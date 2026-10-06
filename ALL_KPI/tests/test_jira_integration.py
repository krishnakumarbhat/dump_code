import json
import importlib.util
from pathlib import Path

from jira_integration import JiraIntegration


def _load_deployer():
    script_path = Path(__file__).resolve().parents[1] / 'generate_upload.py'
    spec = importlib.util.spec_from_file_location('hpcc_generate_upload', script_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_jira_integration_loads_mounted_runtime_config(tmp_path, monkeypatch):
    secret_path = tmp_path / 'jira.json'
    secret_path.write_text(
        json.dumps({
            'JIRA_BASE_URL': 'https://jira.example.invalid',
            'JIRA_PAT': 'test-pat',
            'JIRA_DEFAULT_PROJECT': 'HZP',
            'JIRA_DEFAULT_BOARD': 'HZP',
            'JIRA_RESIM_ISSUE_TYPE': 'Story',
        }),
        encoding='utf-8',
    )
    monkeypatch.setenv('HPCC_JIRA_CONFIG_FILE', str(secret_path))
    for key in (
        'JIRA_BASE_URL', 'JIRA_PAT', 'JIRA_USER', 'JIRA_API_TOKEN',
        'JIRA_DEFAULT_PROJECT', 'JIRA_DEFAULT_BOARD',
    ):
        monkeypatch.delenv(key, raising=False)

    jira = JiraIntegration()

    assert jira._enabled is True
    assert jira.base_url == 'https://jira.example.invalid'
    assert jira.pat == 'test-pat'
    assert jira.default_project == 'HZP'
    assert jira.default_board == 'HZP'
    assert jira.resim_issue_type == 'Story'


def test_jira_project_defaults_to_configured_project(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.setenv('JIRA_DEFAULT_PROJECT', 'HZP')
    monkeypatch.delenv('JIRA_DEFAULT_BOARD', raising=False)
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)

    jira = JiraIntegration()

    assert jira.default_board == 'HZP'


def test_resim_issue_type_defaults_to_story(monkeypatch):
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    monkeypatch.delenv('HPCC_BUNDLE_ROOT', raising=False)
    monkeypatch.delenv('JIRA_RESIM_ISSUE_TYPE', raising=False)

    assert JiraIntegration().resim_issue_type == 'Story'


def test_jira_pat_uses_bearer_auth(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)

    jira = JiraIntegration()

    assert jira._headers()['Authorization'] == 'Bearer test-pat'


def test_resim_ticket_uses_fhw_as_project_key(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.setenv('JIRA_DEFAULT_PROJECT', 'OTHER')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    captured = {}
    jira._build_resim_description = lambda *_args: 'test description'

    def capture_post(url, payload):
        captured['url'] = url
        captured['payload'] = payload
        return {'key': 'FHW-123'}

    jira._post = capture_post
    result = jira.create_resim_ticket(
        input_txt='/net/project/input.txt',
        simg_path='/net/project/resim.simg',
        job_id=28,
        board='FHW',
    )

    assert result == 'FHW-123'
    assert captured['payload']['fields']['project']['key'] == 'FHW'


def test_resim_ticket_normalizes_explicit_lowercase_project_key(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.setenv('JIRA_DEFAULT_PROJECT', 'HZP')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    jira._build_resim_description = lambda *_args: 'test description'
    captured = {}
    jira._post = lambda _url, payload: (captured.update(payload=payload) or {'key': 'FHW-123'})

    assert jira.create_resim_ticket('/net/input.txt', '/net/resim.simg', board='fhw') == 'FHW-123'
    assert captured['payload']['fields']['project']['key'] == 'FHW'


def test_resim_ticket_uses_configured_project_when_board_is_empty(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.setenv('JIRA_DEFAULT_PROJECT', 'HZP')
    monkeypatch.delenv('JIRA_DEFAULT_BOARD', raising=False)
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    jira._build_resim_description = lambda *_args: 'test description'
    captured = {}
    jira._post = lambda url, payload: (captured.update(payload=payload) or {'key': 'HZP-123'})

    assert jira.create_resim_ticket('/net/input.txt', '/net/resim.simg', job_id=8) == 'HZP-123'
    assert captured['payload']['fields']['project']['key'] == 'HZP'
    assert captured['payload']['fields']['issuetype']['name'] == 'Story'
    assert captured['payload']['fields']['customfield_10002'] == 1
    assert captured['payload']['fields']['issuetype']['name'] == 'Story'


def test_resim_ticket_does_not_wait_for_optional_llm(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    jira._post = lambda _url, _payload: {'key': 'HZP-9'}
    jira._call_gemma_for_resim = lambda *_args: (_ for _ in ()).throw(AssertionError('optional LLM must not block Jira'))

    assert jira.create_resim_ticket('/net/input.txt', '/net/resim.simg', job_id=9) == 'HZP-9'


def test_resim_ticket_reports_jira_http_validation_error(monkeypatch):
    import requests

    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    jira._build_resim_description = lambda *_args: 'test description'
    jira._post = lambda _url, _payload: (setattr(jira, 'last_error', 'HTTP 400: customfield_10016: Field cannot be set') or None)

    assert jira.create_resim_ticket('/net/input.txt', '/net/resim.simg', job_id=10) is None
    assert 'customfield_10016' in jira.last_error


def test_upload_jira_config_requires_complete_auth_and_drops_empty_keys(monkeypatch):
    deployer = _load_deployer()
    monkeypatch.delenv('JIRA_BASE_URL', raising=False)
    monkeypatch.delenv('JIRA_PAT', raising=False)

    assert deployer._jira_config_payload({}) is None

    payload = deployer._jira_config_payload({
        'JIRA_BASE_URL': 'https://jira.example.invalid',
        'JIRA_PAT': 'test-pat',
        'JIRA_DEFAULT_PROJECT': 'HZP',
    })

    assert json.loads(payload) == {
        'JIRA_BASE_URL': 'https://jira.example.invalid',
        'JIRA_PAT': 'test-pat',
        'JIRA_DEFAULT_PROJECT': 'HZP',
        'JIRA_DEFAULT_BOARD': 'HZP',
        'JIRA_RESIM_ISSUE_TYPE': 'Story',
    }


def test_upload_jira_config_defaults_resim_issue_type_to_story(monkeypatch):
    deployer = _load_deployer()
    monkeypatch.delenv('JIRA_RESIM_ISSUE_TYPE', raising=False)

    payload = deployer._jira_config_payload({
        'JIRA_BASE_URL': 'https://jira.example.invalid',
        'JIRA_PAT': 'test-pat',
        'JIRA_DEFAULT_PROJECT': 'HZP',
    })

    assert json.loads(payload)['JIRA_RESIM_ISSUE_TYPE'] == 'Story'


def test_deployer_loads_jira_dotenv_and_board_id_as_project_default(monkeypatch, tmp_path):
    deployer = _load_deployer()
    monkeypatch.setattr(deployer, 'ROOT', tmp_path)
    (tmp_path / '.env').write_text('netid=tester\n', encoding='utf-8')
    jira_dir = tmp_path / 'jira'
    jira_dir.mkdir()
    (jira_dir / '.env').write_text(
        'JIRA_BASE_URL=https://jira.example.invalid\n'
        'JIRA_PAT=test-pat\n'
        'JIRA_DEFAULT_PROJECT=HZP\n'
        'JIRA_DEFAULT_BOARD_ID=14936\n',
        encoding='utf-8',
    )
    monkeypatch.delenv('JIRA_BASE_URL', raising=False)
    monkeypatch.delenv('JIRA_PAT', raising=False)

    config = json.loads(deployer._jira_config_payload(deployer._load_env()))

    assert config['JIRA_DEFAULT_PROJECT'] == 'HZP'
    assert config['JIRA_DEFAULT_BOARD'] == 'HZP'
    assert config['JIRA_RESIM_ISSUE_TYPE'] == 'Story'
    assert 'JIRA_DEFAULT_BOARD_ID' not in config


def test_jira_integration_falls_back_to_bundle_runtime_secret(monkeypatch, tmp_path):
    secret_dir = tmp_path / 'runtime_secrets'
    secret_dir.mkdir()
    secret_path = secret_dir / 'jira.json'
    secret_path.write_text(json.dumps({
        'JIRA_BASE_URL': 'https://jira.example.invalid',
        'JIRA_PAT': 'bundle-pat',
        'JIRA_DEFAULT_PROJECT': 'HZP',
    }), encoding='utf-8')
    monkeypatch.setenv('HPCC_BUNDLE_ROOT', str(tmp_path))
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    for key in ('JIRA_BASE_URL', 'JIRA_PAT', 'JIRA_DEFAULT_PROJECT', 'JIRA_DEFAULT_BOARD'):
        monkeypatch.delenv(key, raising=False)

    jira = JiraIntegration()

    assert jira._enabled
    assert jira.pat == 'bundle-pat'
    assert jira.default_project == 'HZP'


def test_jira_create_payload_uses_hzp_defect_story_points(monkeypatch):
    monkeypatch.setenv('JIRA_BASE_URL', 'https://jira.example.invalid')
    monkeypatch.setenv('JIRA_PAT', 'test-pat')
    monkeypatch.setenv('JIRA_DEFAULT_PROJECT', 'HZP')
    monkeypatch.delenv('HPCC_JIRA_CONFIG_FILE', raising=False)
    jira = JiraIntegration()
    jira._build_resim_description = lambda *_args: 'description'
    captured = {}
    jira._post = lambda _url, payload: (captured.update(payload=payload) or {'key': 'HZP-10'})

    assert jira.create_resim_ticket('/net/input.txt', '/net/resim.simg', job_id=10) == 'HZP-10'
    fields = captured['payload']['fields']
    assert fields['project']['key'] == 'HZP'
    assert fields['issuetype']['name'] == 'Story'
    assert fields['customfield_10002'] == 1
    assert 'customfield_10016' not in fields


def test_deployment_uploader_targets_configured_5007_env_paths(monkeypatch, tmp_path):
    deployer = _load_deployer()
    monkeypatch.setattr(deployer, 'ROOT', tmp_path)
    (tmp_path / '.env').write_text(
        'krakow_path=/cluster/krakow/all_services_7\n'
        'southfield_path=/cluster/southfield/all_services_7\n',
        encoding='utf-8',
    )
    assert deployer._deployment_targets(deployer._load_env()) == [
        ('krakow', '10.214.45.45', '/cluster/krakow/all_services_7'),
        ('southfield', '10.192.224.131', '/cluster/southfield/all_services_7'),
    ]


def test_deployment_uploader_prefers_5007_runtime_roots(monkeypatch, tmp_path):
    deployer = _load_deployer()
    monkeypatch.setattr(deployer, 'ROOT', tmp_path)
    (tmp_path / '.env').write_text('krakow_path=/stale/krakow\nsouthfield_path=/stale/southfield\n', encoding='utf-8')
    (tmp_path / 'hpcc_runtime_5007.env').write_text(
        'HPCC_KRAKOW_DEPLOY_ROOT="/active/krakow/all_services_7"\n'
        'HPCC_SOUTHFIELD_DEPLOY_ROOT="/active/southfield/all_services_7"\n', encoding='utf-8')

    assert deployer._deployment_targets(deployer._load_env()) == [
        ('krakow', '10.214.45.45', '/active/krakow/all_services_7'),
        ('southfield', '10.192.224.131', '/active/southfield/all_services_7'),
    ]


def test_project_runtime_paths_are_loaded_for_both_clusters():
    settings = _load_deployer()._load_env()

    assert settings['krakow_path'].endswith('/RNA-SDV-SRR7/4-Checkout/all_services_7')
    assert settings['southfield_path'] == '/mnt/usmidet/projects/RADARCORE/2-Sim/all_services_7'
