from pathlib import Path
import shlex
from types import SimpleNamespace

import pytest
from flask import render_template

from main_html import app as main


def _render(template_name, **context):
    with main.app.test_request_context('/html/runtime-map', headers={'Host': '10.214.45.45:5005'}):
        return render_template(template_name, **context)


def _kpi_context(customer_accounts, default_account='radarcore'):
    defaults = {
        key: dict(value)
        for key, value in main.RUNTIME_TOOL_DEFAULTS.items()
    }
    defaults['udp_kpi']['account'] = default_account
    return {
        'tool_name': 'KPI Analysis',
        'recent_jobs': [],
        'runtime_tools': [],
        'defaults': defaults,
        'customer_accounts': customer_accounts,
        'configuration_files': [],
        'detected_cluster': 'krakow',
        'krakow_runtime_profiles': main.KRAKOW_RUNTIME_PROFILES,
        'allow_local_scheduler': False,
    }


def _runtime_context(cluster='krakow'):
    return {
        'runtime_graph': main.runtime_store.graph_payload(),
        'broker_defaults': main.RUNTIME_TOOL_DEFAULTS,
        'detected_cluster': cluster,
        'krakow_runtime_profiles': main.KRAKOW_RUNTIME_PROFILES,
    }


def _response_parts(result):
    if isinstance(result, tuple):
        response, status = result
    else:
        response, status = result, result.status_code
    return status, response.get_json()


class _FakeSession:
    def __init__(self):
        self.jobs = []
        self.commits = 0

    def add(self, job):
        self.jobs.append(job)

    def commit(self):
        self.commits += 1
        if self.jobs:
            self.jobs[-1].id = 42


class _FakeThread:
    instances = []

    def __init__(self, *args, **kwargs):
        self.args = args
        self.kwargs = kwargs
        self.started = False
        self.instances.append(self)

    def start(self):
        self.started = True


@pytest.fixture
def resim_boundary_mocks(tmp_path, monkeypatch):
    script_path = tmp_path / 'trig_helios.sh'
    script_path.write_text('#!/usr/bin/env bash\n', encoding='utf-8')
    session = _FakeSession()
    _FakeThread.instances = []

    monkeypatch.setattr(main, 'current_user', SimpleNamespace(id=7, net_id='tester'))
    monkeypatch.setattr(main, 'db', SimpleNamespace(session=session))
    monkeypatch.setattr(main.threading, 'Thread', _FakeThread)
    monkeypatch.setattr(main, '_resim_script_source_path', lambda: str(script_path))
    monkeypatch.setattr(main, '_stored_cluster_password_for_current_user', lambda _net_id: 'secret')
    monkeypatch.setattr(main, '_write_askpass_script', lambda _password, path: Path(path).write_text('askpass', encoding='utf-8'))
    monkeypatch.setattr(main, '_first_writable_dir', lambda *_paths: str(tmp_path))
    monkeypatch.setattr(main, 'get_cache_dir', lambda: str(tmp_path))

    return session, _FakeThread, tmp_path


def _submit_resim(payload):
    with main.app.test_request_context('/api/resim_run_submit', method='POST', json=payload):
        return main.api_resim_run_submit.__wrapped__()


def _resim_payload(**overrides):
    payload = {
        'input_txt': '/net/8k3/project/input.txt',
        'simg_path': '/net/8k3/project/resim.simg',
        'config_xml': '/net/8k3/project/resim.xml',
    }
    payload.update(overrides)
    return payload


def test_customer_accounts_are_unique_and_ignore_empty_values(monkeypatch):
    monkeypatch.setitem(main.app.config, 'SLURM_ACCOUNT', 'app-account')
    monkeypatch.setattr(main, '_SLURM_DEFAULTS', {'account': 'global-account'})
    monkeypatch.setattr(
        main,
        'get_cluster_slurm_defaults',
        lambda cluster: {'account': 'krakow-account' if cluster == 'krakow' else 'southfield-account'},
    )
    monkeypatch.setattr(
        main,
        'KRAKOW_RUNTIME_PROFILES',
        {'helios': {'account': 'profile-account'}, 'empty': {'account': ''}},
    )
    monkeypatch.setattr(
        main,
        'RUNTIME_TOOL_DEFAULTS',
        {'udp_kpi': {'account': 'tool-account'}, 'duplicate': {'account': 'app-account'}},
    )

    assert main._runtime_customer_accounts() == [
        'app-account',
        'global-account',
        'krakow-account',
        'southfield-account',
        'profile-account',
        'tool-account',
    ]


def test_kpi_template_places_bundle_before_execution_note_and_renders_known_accounts():
    html = _render('tools/kpi.html', **_kpi_context(['radarcore', 'rna-sdv-srr7', '8k3p89']))

    assert html.index('Prepare the bundle') < html.index('Execution note')
    assert html.count('id="deployBundleButton"') == 1
    assert '<label class="form-label">Customer Name</label>' in html
    assert '<option value="radarcore" selected>radarcore</option>' in html
    assert 'value="rna-sdv-srr7"' in html and '>rna-sdv-srr7</option>' in html
    assert 'value="8k3p89"' in html and '>8k3p89</option>' in html
    assert 'id="account"' in html and 'name="account"' in html


def test_kpi_template_selects_other_for_an_unknown_default_account():
    html = _render('tools/kpi.html', **_kpi_context(['radarcore'], default_account='new-customer'))

    assert '<option value="__other__" selected>Other</option>' in html
    assert 'id="customAccountField"' in html
    assert 'value="new-customer"' in html


def test_runtime_map_template_exposes_helios_and_updates_profile_metadata():
    html = _render('runtime_map.html', **_runtime_context())

    assert 'id="resimProfile"' in html
    assert 'value="krakow" data-partition="highPrio" data-module="slurm" selected' in html
    assert 'value="helios" data-partition="8k3" data-module="slurm/helios"' in html
    assert 'value="athena"' in html
    assert 'id="detectedPartition"' in html
    assert 'profile: resimProfile ? resimProfile.value : \'krakow\'' in html
    assert 'id="bus_tag"' in html
    assert 'Default (pipeline setting)' in html
    assert 'value="b02"' in html
    assert 'value="b04"' in html
    assert 'id="rm_zero"' in html
    assert 'rm_zero: rmZero' in html
    assert 'Resim XML configuration (optional)' in html
    assert 'Leave blank for vendor default' in html


def test_resim_passes_rm_zero_flag_after_bus_tag(resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(bus_tag='b04', rm_zero=True))
    status, _data = _response_parts(result)

    assert status == 200
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert 'highPrio b04 rm_zero' in command
    assert session.jobs[0].parameters['rm_zero'] is True


def test_resim_omits_rm_zero_by_default(resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload())
    status, _data = _response_parts(result)

    assert status == 200
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert command.endswith("highPrio b02'")
    assert session.jobs[0].parameters['rm_zero'] is False


def test_resim_omits_bus_tag_by_default(resim_boundary_mocks):
    _, thread_class, _ = resim_boundary_mocks
    result = _submit_resim(_resim_payload(bus_tag=''))
    status, _ = _response_parts(result)

    assert status == 200
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert 'highPrio b02' not in command
    assert 'highPrio b04' not in command


def test_runtime_map_template_keeps_highprio_for_southfield():
    html = _render('runtime_map.html', **_runtime_context(cluster='southfield'))

    assert 'let detectedResimCluster = "southfield";' in html
    assert " : 'highPrio';" in html
    assert 'Resim XML configuration (optional)' in html


def test_runtime_map_route_supplies_profile_context(monkeypatch):
    captured = {}

    def capture_template(template_name, **context):
        captured['template_name'] = template_name
        captured['context'] = context
        return 'rendered'

    monkeypatch.setattr(main, 'render_template', capture_template)
    with main.app.test_request_context('/html/runtime-map', headers={'Host': '10.214.45.45:5005'}):
        result = main.runtime_map.__wrapped__()

    assert result == 'rendered'
    assert captured['template_name'] == 'runtime_map.html'
    assert captured['context']['detected_cluster'] == 'krakow'
    assert captured['context']['krakow_runtime_profiles'] is main.KRAKOW_RUNTIME_PROFILES


def test_resim_defaults_to_normal_krakow_runtime(resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload())
    status, data = _response_parts(result)

    assert status == 200
    assert data == {'ok': True, 'message': 'Submitted', 'job_id': 42}
    assert session.commits == 1
    assert session.jobs[0].parameters['profile'] == 'krakow'
    assert session.jobs[0].parameters['bus_tag'] == 'b02'
    assert session.jobs[0].parameters['config_xml'] == '/net/8k3/project/resim.xml'
    assert session.jobs[0].parameters['profile_label'] == 'Krakow Default'
    assert len(thread_class.instances) == 1
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert 'RESIM_SLURM_MODULE=slurm' in command
    assert 'srun -A' not in command
    assert '/net/8k3/project/input.txt /net/8k3/project/resim.simg highPrio b02' in command
    assert thread_class.instances[0].kwargs['kwargs']['config_xml'] == '/net/8k3/project/resim.xml'
    assert thread_class.instances[0].started is True


@pytest.mark.parametrize(
    ('input_txt', 'simg_path'),
    [
        ('/net/8k3/project/input.txt', '/net/8k3/project/resim.simg'),
        ('/mnt/usmidet/project/input.txt', '/mnt/usmidet/project/resim.simg'),
    ],
)
def test_resim_xml_is_optional_on_krakow_and_southfield(
    input_txt, simg_path, resim_boundary_mocks
):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(
        input_txt=input_txt,
        simg_path=simg_path,
        config_xml='',
    ))
    status, _data = _response_parts(result)

    assert status == 200
    assert session.jobs[0].parameters['config_xml'] == ''
    assert thread_class.instances[0].kwargs['kwargs']['config_xml'] == ''


def test_resim_passes_b04_bus_tag_through(resim_boundary_mocks):
    _session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(bus_tag='b04'))
    status, _data = _response_parts(result)

    assert status == 200
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert 'highPrio b04' in command


def test_resim_rejects_unknown_bus_tag(resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(bus_tag='b07'))
    status, data = _response_parts(result)

    assert status == 400
    assert 'bus tag' in data['error'].lower()
    assert session.jobs == []
    assert thread_class.instances == []


def test_resim_input_feeder_sends_xml_after_yes():
    feeder = main._start_resim_input_feeder('/net/8k3/project/resim.xml')
    try:
        assert feeder.stdout.readline().decode().strip() == 'n'
        assert feeder.stdout.readline().decode().strip() == '1'
        assert feeder.stdout.readline().decode().strip() == '/net/8k3/project/resim.xml'
        assert feeder.stdout.readline() == b''
    finally:
        feeder.kill()
        feeder.wait()


def test_resim_input_feeder_selects_default_config_when_xml_is_blank():
    feeder = main._start_resim_input_feeder('')
    try:
        assert feeder.stdout.readline().decode().strip() == 'y'
        assert feeder.stdout.readline() == b''
    finally:
        feeder.kill()
        feeder.wait()


def test_resim_pipeline_submission_marker_parses_all_slurm_ids():
    marker = (
        '[INFO] : PipeLine Triggered  ReSIm_docker: 25682374 '
        '| ReSim_Mining: 25682375 | Stats_Mining: 25682376'
    )

    assert main._parse_resim_pipeline_submission(marker) == {
        'resim': '25682374',
        'resim_mining': '25682375',
        'stats_mining': '25682376',
    }
    assert main._parse_resim_pipeline_submission('Still waiting for ReSim') is None


def test_resim_input_validation_error_is_reported_as_failure(tmp_path):
    log_path = tmp_path / 'resim.log'
    log_path.write_text('[ERROR] : Inputs Validation :- short of needed argument', encoding='utf-8')

    assert 'rejected its arguments' in main._first_failure_marker_in_log(str(log_path))


@pytest.mark.parametrize(
    ('submission_detected', 'return_code', 'failure_reason', 'expected_status'),
    [
        (True, 255, '', 'SUBMITTED'),
        (True, 0, 'process failed', 'SUBMITTED'),
        (False, 0, '', 'COMPLETED'),
        (False, 1, '', 'FAILED'),
    ],
)
def test_resim_completion_status_preserves_scheduler_acceptance(
    submission_detected, return_code, failure_reason, expected_status
):
    assert main._resim_job_completion_status(
        submission_detected, return_code, failure_reason
    ) == expected_status


def test_resim_accepts_case_insensitive_profile_and_uses_athena(resim_boundary_mocks):
    _session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(profile='ATHENA'))
    status, _data = _response_parts(result)

    assert status == 200
    ssh_command = thread_class.instances[0].kwargs['args'][1]
    command = ssh_command[-1]
    assert command.startswith('bash -lc ')
    assert 'bash' not in ssh_command[-3:-1]
    assert 'module load slurm/athena' in command
    assert '/app/software/slurm/athena/bin/srun -A 8k3p89 -p athena' in command


def test_helios_invokes_shared_launcher_with_bash_on_compute_node(resim_boundary_mocks):
    _session, thread_class, _tmp_path = resim_boundary_mocks
    result = _submit_resim(_resim_payload(profile='helios'))
    status, _data = _response_parts(result)

    assert status == 200
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert '8k3tester@149.156.176.25' in command
    assert 'tester@10.214.45.149' in command
    assert command.count('StrictHostKeyChecking=accept-new') == 2
    assert command.count('BatchMode=yes') == 2
    assert (
        'bash Main/trig_pip.sh /net/8k3/project/input.txt '
        '/net/8k3/project/resim.simg highPrio b02'
    ) in command
    assert ' "$@"' not in command
    assert 'Core_RESIM_HPCC/Resim_Pipeline' in command
    assert 'STLA-SMALL/7-Tools/ReSimAutoMng' not in command


@pytest.mark.parametrize('net_id', ['ouymc2', 'pcmzxl'])
@pytest.mark.parametrize('config_xml', ['', '/net/8k3/project/custom config.xml'])
def test_helios_keeps_arguments_and_answers_inside_allocation(net_id, config_xml, resim_boundary_mocks, monkeypatch):
    _, threads, _ = resim_boundary_mocks
    monkeypatch.setattr(main, 'current_user', SimpleNamespace(id=7, net_id=net_id))
    status, _ = _response_parts(_submit_resim(_resim_payload(profile='helios', config_xml=config_xml, rm_zero=True)))
    assert status == 200
    outer = shlex.split(threads.instances[0].kwargs['args'][1][-1])[2]
    hop = shlex.split(outer[outer.index('ssh -T'):])
    assert hop[-2] == f'8k3{net_id}@149.156.176.25'
    assert any(f'{net_id}@10.214.45.149' in token for token in hop if token.startswith('ProxyCommand='))
    native = shlex.split(shlex.split(hop[-1])[2])
    assert native[0] == 'srun'
    compute = native[-1]
    tokens = shlex.split(compute)
    assert tokens[tokens.index('%s') + 1] == ('n\n1\n' + config_xml + '\n' if config_xml else 'y\n')
    assert tokens[-5:] == ['/net/8k3/project/input.txt', '/net/8k3/project/resim.simg', 'highPrio', 'b02', 'rm_zero']


def test_helios_omits_bus_tag_when_using_pipeline_default(resim_boundary_mocks, monkeypatch):
    _, threads, _ = resim_boundary_mocks
    result = _submit_resim(_resim_payload(profile='helios', bus_tag=''))
    assert _response_parts(result)[0] == 200
    command = threads.instances[0].kwargs['args'][1][-1]
    assert 'trig_pip.sh /net/8k3/project/input.txt /net/8k3/project/resim.simg highPrio\'' in command
    assert 'b02' not in command and 'b04' not in command


@pytest.mark.parametrize('profile_id', tuple(main.KRAKOW_RUNTIME_PROFILES))
def test_resim_supports_every_krakow_profile(profile_id, resim_boundary_mocks):
    _session, thread_class, _tmp_path = resim_boundary_mocks
    result = _submit_resim(_resim_payload(profile=profile_id))
    status, _data = _response_parts(result)

    assert status == 200
    profile = main.KRAKOW_RUNTIME_PROFILES[profile_id]
    command = thread_class.instances[0].kwargs['args'][1][-1]
    if profile_id == 'krakow':
        assert f"RESIM_SLURM_MODULE={profile['module']}" in command
        assert 'srun -A' not in command
    elif profile_id == 'helios':
        assert 'bash Main/trig_pip.sh /net/8k3/project/input.txt' in command
    else:
        assert f"RESIM_SLURM_MODULE={profile['module']}" in command
        assert f"module load {profile['module']}" in command
        assert f"{profile['srun']} -A {profile['account']} -p {profile['partition']}" in command
        assert f"--mem={profile['memory']} --cpus-per-task={profile['cpus']}" in command
        assert f"--time={profile['time_limit']}" in command


def test_explicit_fhw_jira_project_is_not_replaced_by_configured_default(monkeypatch):
    from types import SimpleNamespace
    import sys

    captured = {}

    class _Jira:
        _enabled = True
        default_project = 'HZP'
        default_board = 'HZP'
        last_error = ''

        def create_resim_ticket(self, **kwargs):
            captured.update(kwargs)
            return 'FHW-123'

    monkeypatch.setattr(sys.modules['jira_integration'], 'JiraIntegration', _Jira)
    commits = []
    monkeypatch.setattr(main.db, 'session', SimpleNamespace(commit=lambda: commits.append(True), remove=lambda: None))
    job = SimpleNamespace(
        parameters={'create_jira': True, 'jira_board': 'FHW', 'input_txt': '/net/in.txt', 'simg_path': '/net/run.simg'},
        input_path='/net/in.txt', id=81,
    )
    with main.app.app_context():
        main._create_jira_ticket_for_job(job, '')

    assert job.parameters['jira_ticket_key'] == 'FHW-123'
    assert captured['board'] == 'FHW'
    assert commits


def test_resim_keeps_southfield_execution_unchanged(resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(_resim_payload(
        input_txt='/mnt/usmidet/project/input.txt',
        simg_path='/mnt/usmidet/project/resim.simg',
        config_xml='/mnt/usmidet/project/resim.xml',
        profile='cyfronet',
    ))
    status, _data = _response_parts(result)

    assert status == 200
    assert session.jobs[0].parameters['profile'] == 'krakow'
    command = thread_class.instances[0].kwargs['args'][1][-1]
    assert 'module load slurm/' not in command
    assert 'srun -A' not in command
    assert '/mnt/usmidet/project/input.txt /mnt/usmidet/project/resim.simg highPrio b02' in command


def test_resim_rejects_missing_cluster_password_without_starting_a_job(resim_boundary_mocks, monkeypatch):
    session, thread_class, _tmp_path = resim_boundary_mocks
    monkeypatch.setattr(main, '_stored_cluster_password_for_current_user', lambda _net_id: '')

    result = _submit_resim(_resim_payload())
    status, data = _response_parts(result)

    assert status == 400
    assert 'No cluster password saved' in data['error']
    assert session.jobs == []
    assert thread_class.instances == []


def test_resim_rejects_missing_script_without_starting_a_job(resim_boundary_mocks, monkeypatch):
    session, thread_class, tmp_path = resim_boundary_mocks
    monkeypatch.setattr(main, '_resim_script_source_path', lambda: str(tmp_path / 'missing-trig_helios.sh'))

    result = _submit_resim(_resim_payload())
    status, data = _response_parts(result)

    assert status == 500
    assert 'trig_helios.sh not found' in data['error']
    assert session.jobs == []
    assert thread_class.instances == []


def test_generated_dashboard_copies_include_the_runtime_map_changes():
    root = Path(__file__).resolve().parent.parent
    pairs = [
        ('main_html/app.py', 'generate_upload/bundle_src/main_html/app.py'),
        ('main_html/jira_integration.py', 'generate_upload/bundle_src/main_html/jira_integration.py'),
        ('main_html/templates/tools/kpi.html', 'generate_upload/bundle_src/main_html/templates/tools/kpi.html'),
        ('main_html/templates/runtime_map.html', 'generate_upload/bundle_src/main_html/templates/runtime_map.html'),
        ('main_html/templates/job_log.html', 'generate_upload/bundle_src/main_html/templates/job_log.html'),
    ]
    markers = {
        'main_html/app.py': ('_runtime_customer_accounts', 'Unknown Krakow Resim runtime profile.', "data.get('config_xml')", 'RESIM_CONFIG_XML', 'bus_tag', 'rm_zero', 'if config_xml and not config_xml.lower().endswith'),
        'main_html/jira_integration.py': ('HPCC_BUNDLE_ROOT', 'default_project or \'FHW\'', 'last_error'),
        'main_html/templates/tools/kpi.html': ('Prepare the bundle', 'Customer Name', 'Other'),
        'main_html/templates/runtime_map.html': ('resimProfile', 'Helios', 'profile:', 'config_xml', 'bus_tag', 'rm_zero', 'Resim XML configuration (optional)', 'vendor default'),
        'main_html/templates/job_log.html': ('Retry Jira ticket', 'jira_ticket_key', '/api/job/{{ job.id }}/jira'),
    }

    for source_name, generated_name in pairs:
        source = (root / source_name).read_text(encoding='utf-8')
        generated = (root / generated_name).read_text(encoding='utf-8')
        assert all(marker in source and marker in generated for marker in markers[source_name])

    app_source = (root / 'main_html/app.py').read_text(encoding='utf-8')
    bundle_app = (root / 'generate_upload/bundle_src/main_html/app.py').read_text(encoding='utf-8')
    helios_dispatch = 'bash Main/trig_pip.sh '
    assert helios_dispatch in app_source
    assert helios_dispatch in bundle_app
    assert 'Core_RESIM_HPCC/Resim_Pipeline' in app_source
    assert 'Core_RESIM_HPCC/Resim_Pipeline' in bundle_app


@pytest.mark.parametrize(
    ('payload', 'expected_error'),
    [
        ({}, 'Input file (input.txt) path is required.'),
        ({'input_txt': '/net/8k3/project/input.txt'}, 'Simg file path is required.'),
        ({'input_txt': 'C:/project/input.txt', 'simg_path': 'C:/project/resim.simg', 'config_xml': 'C:/project/resim.xml'}, 'Input file path must start'),
        ({'input_txt': '/net/8k3/project/input.txt', 'simg_path': '/net/8k3/project/resim.simg', 'config_xml': 'relative.xml'}, 'XML configuration path must start'),
        ({'input_txt': '/net/8k3/project/input.txt', 'simg_path': '/net/8k3/project/resim.simg', 'config_xml': '/mnt/usmidet/project/resim.xml'}, 'All files must be in the same partition'),
        ({'input_txt': '/net/8k3/project/input.txt', 'simg_path': '/mnt/usmidet/project/resim.simg', 'config_xml': '/net/8k3/project/resim.xml'}, 'Both files must be in the same partition'),
        ({'input_txt': '/net/8k3/project/input.txt', 'simg_path': '/net/8k3/project/resim.simg', 'config_xml': '/net/8k3/project/resim.xml', 'profile': 'unknown'}, 'Unknown Krakow Resim runtime profile.'),
        ({'input_txt': '/net/8k3/project/input.txt', 'simg_path': '/net/8k3/project/resim.simg', 'config_xml': '/net/8k3/project/resim.xml', 'bus_tag': 'b07'}, 'Unknown bus tag'),
    ],
)
def test_resim_rejects_invalid_inputs_without_starting_a_job(payload, expected_error, resim_boundary_mocks):
    session, thread_class, _tmp_path = resim_boundary_mocks

    result = _submit_resim(payload)
    status, data = _response_parts(result)

    assert status == 400
    assert expected_error in data['error']
    assert session.jobs == []
    assert thread_class.instances == []
