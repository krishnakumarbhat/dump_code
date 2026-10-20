import importlib.util
import re
from pathlib import Path
from types import SimpleNamespace

import pytest


def _load_viewer_module():
    path = Path(__file__).resolve().parents[1] / 'Hyperlink_tool' / 'code' / 'html_online' / 'main.py'
    spec = importlib.util.spec_from_file_location('hyperlink_test_main', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_mcip_html_and_nested_video_match_by_session(tmp_path):
    viewer = _load_viewer_module()
    html = tmp_path / 'html'
    video = tmp_path / 'video'
    folder = 'IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5'
    session = 'ThunderMCIP_WS11656_20251024_140453_0146_g02'
    (html / folder).mkdir(parents=True)
    (html / folder / 'KPI_DashBoard.html').write_text('<html/>', encoding='utf-8')
    mp4 = video / session / 'bus91100' / 'bus91100.mp4'
    mp4.parent.mkdir(parents=True)
    mp4.write_bytes(b'video')

    mapping = viewer.LogViewerApp(str(html), str(video)).build_mapping()

    assert len(mapping) == 1
    for pair in mapping.values():
        assert pair['video_name'] == 'bus91100.mp4'
        assert pair['video'] == '/data/video/' + mp4.relative_to(video).as_posix()
        assert pair['video_relative_path'] == mp4.relative_to(video).as_posix()
        assert pair['html_missing'] is False
        assert pair['video_missing'] is False


def test_session_key_handles_hdf_report_and_g02_suffix_variants():
    viewer = _load_viewer_module()
    report = 'IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5'
    assert viewer.mapping_key_from_name(report) == '20251024_140453_0146'
    assert viewer.mapping_key_from_name('ThunderMCIP_WS11656_20251024_140453_0146_g02') == '20251024_140453_0146'
    assert viewer.mapping_key_from_name('ThunderMCIP_WS11656_20251024_140453_0146_g02_0001') == '20251024_140453_0146'
    assert viewer.mapping_key_from_name('ThunderMCIP_WS11656_20251024_140453_0146_g05') == '20251024_140453_0146'
    assert viewer.mapping_key_from_name('IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b04_HDF_Report.h5') == '20251024_140453_0146'


def test_hyperlink_scanner_supports_html_only_and_video_only(tmp_path):
    viewer = _load_viewer_module()
    html = tmp_path / 'html'
    video = tmp_path / 'video'
    folder = 'IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5'
    session = 'ThunderMCIP_WS11656_20251024_140453_0146_g02'
    (html / folder).mkdir(parents=True)
    (html / folder / 'KPI_DashBoard.html').write_text('<html/>', encoding='utf-8')
    mp4 = video / session / 'bus91100' / 'bus91100.mp4'
    mp4.parent.mkdir(parents=True)
    mp4.write_bytes(b'video')

    html_entries = viewer.LogViewerApp(str(html), '').build_mapping()
    video_entries = viewer.LogViewerApp('', str(video)).build_mapping()

    assert len(html_entries) == 1
    assert len(video_entries) == 1
    assert next(iter(html_entries.values()))['html_missing'] is False
    assert next(iter(html_entries.values()))['video_missing'] is True
    assert next(iter(video_entries.values()))['html_missing'] is True
    assert next(iter(video_entries.values()))['video_missing'] is False


def test_multiple_report_folders_pair_to_one_video_session(tmp_path):
    viewer = _load_viewer_module()
    html = tmp_path / 'html'
    video = tmp_path / 'video'
    session = 'ThunderMCIP_WS11656_20251024_140453_0146_g02'
    reports = [
        'IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5',
        'IRep57_MRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5',
    ]
    for name in reports:
        folder = html / name
        folder.mkdir(parents=True)
        (folder / 'KPI_DashBoard.html').write_text('<html/>', encoding='utf-8')
    mp4 = video / session / 'bus91100' / 'bus91100.mp4'
    mp4.parent.mkdir(parents=True)
    mp4.write_bytes(b'video')

    mapping = viewer.LogViewerApp(str(html), str(video)).build_mapping()

    assert len(mapping) == 2
    assert {entry['html_folder'] for entry in mapping.values()} == set(reports)
    assert all(entry['video_missing'] is False for entry in mapping.values())


def test_session_keys_cover_mcip_suffix_variations_and_duplicate_reports():
    viewer = _load_viewer_module()
    report = 'IRep158_SRR_ThunderMCIP_WS11656_20251024_140453_0146_b05_HDF_Report.h5'
    video = 'ThunderMCIP_WS11656_20251024_140453_0146_g02'
    video_alt = 'ThunderMCIP_WS11656_20251024_140453_0146_g02_0001'
    keys = [viewer.mapping_key_from_name(value) for value in (report, video, video_alt)]
    assert keys == ['20251024_140453_0146'] * 3

    pattern = re.compile(r'(?i)(\d{8}_\d{6}_\d+)(?:_b05_hdf_report|_g02(?:_\d+)?)$')
    match = pattern.search(report[:-3])
    assert match and match.group(1) == keys[0]


def test_html_download_counts_acl_denied_folder_and_continues(tmp_path):
    from main_html import app as main

    class FakeSftp:
        def listdir_attr(self, path):
            if path.endswith('/restricted'):
                raise PermissionError(13, 'Permission denied')
            return [SimpleNamespace(filename='restricted', st_mode=0o040000)]

    assert main._hyperlink_sftp_download_dir(FakeSftp(), '/remote/report', str(tmp_path / 'report')) == 1


def test_nested_cached_video_path_resolves_under_video_root(monkeypatch, tmp_path):
    from main_html import app as main

    video_root = tmp_path / 'video'
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(tmp_path / 'html'), str(video_root)))

    resolved = main._hyperlink_resolve_video_abs_path('/hyperlink/data/video/session/g02/bus91100/bus91100.mp4')

    assert resolved == str(video_root / 'session' / 'g02' / 'bus91100' / 'bus91100.mp4')


def test_saved_video_cache_name_prefers_existing_nested_scan_path(tmp_path):
    from main_html import app as main

    video_root = tmp_path / 'video'
    nested = video_root / '20251024_140453_0189_g02' / 'bus91100' / 'bus91100.mp4'
    nested.parent.mkdir(parents=True)
    nested.write_bytes(b'video')

    cache_name = main._hyperlink_saved_video_cache_name(
        str(video_root),
        'bus91100.mp4',
        '20251024_140453_0189_g02/bus91100/bus91100.mp4',
    )

    assert cache_name == '20251024_140453_0189_g02/bus91100/bus91100.mp4'


def test_saved_remote_video_recovers_relative_nested_cache_path():
    from main_html import app as main

    assert main._hyperlink_remote_video_cache_name(
        '/mnt/project/RESULTS/output/20251024/140453/VIDEO/out_jpeg/'
        'ThunderMCIP_WS11656_20251024_140453_0189_g02/bus91100/bus91100.mp4'
    ) == 'ThunderMCIP_WS11656_20251024_140453_0189_g02/bus91100/bus91100.mp4'


def test_legacy_flat_cache_cannot_replace_an_unrelated_session(tmp_path):
    from main_html import app as main

    video_root = tmp_path / 'video'
    flat = video_root / 'bus91100.mp4'
    flat.parent.mkdir(parents=True)
    flat.write_bytes(b'legacy-video')
    remote = '/mnt/project/out_jpeg/session_0189_g02/bus91100/bus91100.mp4'

    recovered = main._hyperlink_recover_saved_video(
        str(video_root), remote, 'session_0189_g02/bus91100/bus91100.mp4'
    )

    assert recovered is False
    assert not (video_root / 'session_0189_g02' / 'bus91100' / 'bus91100.mp4').exists()


def test_browser_video_cache_lock_serializes_same_target(monkeypatch, tmp_path):
    from main_html import app as main

    lock = main._hyperlink_browser_video_cache_lock(str(tmp_path / 'video.mp4'))
    same_lock = main._hyperlink_browser_video_cache_lock(str(tmp_path / '.' / 'video.mp4'))
    assert same_lock is lock


def test_browser_transcode_limits_threads_and_reuses_completed_cache(monkeypatch, tmp_path):
    from main_html import app as main

    source = tmp_path / 'bus91100.mp4'
    source.write_bytes(b'mp4v')
    calls = []

    def run(command, **kwargs):
        calls.append(command)
        assert command.count('-threads') == 2
        assert command[command.index('-threads') + 1] == '1'
        Path(command[-1]).write_bytes(b'avc1')
        return SimpleNamespace(returncode=0, stderr='', stdout='')

    monkeypatch.setattr(main.subprocess, 'run', run)
    result = main._hyperlink_prepare_browser_video(str(source))
    assert Path(result).read_bytes() == b'avc1'
    assert main._hyperlink_prepare_browser_video(str(source)) == result
    assert len(calls) == 1


def test_saved_pair_keeps_nested_video_cache_path(monkeypatch):
    from main_html import app as main

    class FakeQuery:
        def filter_by(self, **kwargs):
            return self

        def first(self):
            return None

    class FakePair:
        query = FakeQuery()

        def __init__(self, **kwargs):
            self.__dict__.update(kwargs)

    monkeypatch.setattr(main, 'HyperlinkSavedPair', FakePair)
    monkeypatch.setattr(main, '_hyperlink_saved_owner', lambda: ('tester', 1))
    monkeypatch.setattr(main.db.session, 'add', lambda pair: None)
    monkeypatch.setattr(main.db.session, 'commit', lambda: None)

    pair = main._hyperlink_upsert_saved_pair(
        key='session::report',
        html_path='/remote/report',
        video_path='/remote/session/bus91100/bus91100.mp4',
        output_root='/cache',
        video_cache_name='session/bus91100/bus91100.mp4',
    )

    assert pair.video_name == 'session/bus91100/bus91100.mp4'


def test_hyperlink_video_route_resolves_and_serves_nested_cache_path(monkeypatch, tmp_path):
    from main_html import app as main

    video_root = tmp_path / 'video'
    nested = video_root / 'session' / 'g02' / 'bus91100' / 'bus91100.mp4'
    nested.parent.mkdir(parents=True)
    nested.write_bytes(b'video-bytes')
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(tmp_path / 'html'), str(video_root)))
    monkeypatch.setattr(main, '_hyperlink_prepare_browser_video', lambda path: path)

    response = main.app.test_client().get('/hyperlink/data/video/session/g02/bus91100/bus91100.mp4')

    assert response.status_code == 200
    assert response.data == b'video-bytes'


def test_duplicate_video_basenames_use_distinct_nested_cached_files(tmp_path, monkeypatch):
    from main_html import app as main

    video_root = tmp_path / 'video'
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(tmp_path / 'html'), str(video_root)))
    for session, content in [('0189', b'first'), ('0190', b'second')]:
        path = video_root / f'20251024_140453_{session}' / 'g02' / 'bus91100' / 'bus91100.mp4'
        path.parent.mkdir(parents=True)
        path.write_bytes(content)
        url = '/hyperlink/data/video/' + path.relative_to(video_root).as_posix()
        response = main.app.test_client().get(url)
        assert response.status_code == 200
        assert response.data == content


def test_video_scan_ignores_browser_cache_temp_mp4(tmp_path):
    viewer = _load_viewer_module()
    video_root = tmp_path / 'video'
    session = video_root / 'ThunderMCIP_WS11656_20251024_140453_0173_g02'
    actual = session / 'bus91100' / 'bus91100.mp4'
    actual.parent.mkdir(parents=True)
    actual.write_bytes(b'video')
    temp = actual.parent / '.browser_cache' / 'bus91100.browser.mp4.tmp.mp4'
    temp.parent.mkdir()
    temp.write_bytes(b'temporary')

    mapping = viewer.LogViewerApp('', str(video_root)).build_mapping()

    assert len(mapping) == 1
    assert next(iter(mapping.values()))['video_relative_path'] == actual.relative_to(video_root).as_posix()


def test_json_only_report_matches_video_under_wrapper_directories(tmp_path):
    viewer = _load_viewer_module()
    report = 'IRep185_SRR_ThunderMCIP_WS11656_20251024_140453_0173_b05_HDF_Report.h5'
    html = tmp_path / 'html'
    (html / report / 'JSON').mkdir(parents=True)
    video = tmp_path / 'video'
    clip = video / 'wrapper' / 'output' / 'ThunderMCIP_WS11656_20251024_140453_0173_g02' / 'bus91100' / 'bus91100.mp4'
    clip.parent.mkdir(parents=True)
    clip.write_bytes(b'video')
    mapping = viewer.LogViewerApp(str(html), str(video)).build_mapping()
    assert len(mapping) == 1
    entry = next(iter(mapping.values()))
    assert entry['html_folder'] == report
    assert entry['video_relative_path'] == clip.relative_to(video).as_posix()


def test_mappings_api_includes_saved_pair_without_discovered_match(monkeypatch, tmp_path):
    from datetime import datetime

    from main_html import app as main

    html_root = tmp_path / 'html'
    video_root = tmp_path / 'video'
    report = 'IRep185_SRR_ThunderMCIP_WS11656_20251024_140453_0173_b05_HDF_Report.h5'
    video_name = 'ThunderMCIP_WS11656_20251024_140453_0173_g02/bus91100/bus91100.mp4'
    (html_root / report).mkdir(parents=True)
    video_file = video_root / video_name
    video_file.parent.mkdir(parents=True)
    video_file.write_bytes(b'saved-video')
    pair = SimpleNamespace(
        id=173,
        pair_key='20251024_140453_0173::' + report,
        video_name=video_name,
        remote_video_path='/remote/out_jpeg/' + video_name,
        remote_html_path='/remote/html/' + report,
        remote_overlay_path=None,
        overlay_name=None,
        label=report,
        html_folder=report,
        created_at=datetime(2026, 10, 12),
        last_used_at=datetime(2026, 10, 12),
    )

    class EmptyViewer:
        def __init__(self, *_args):
            pass

        def build_mapping(self):
            return {}

    monkeypatch.setattr(main, '_load_hyperlink_log_viewer_app', lambda: EmptyViewer)
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(html_root), str(video_root)))
    monkeypatch.setattr(main, '_hyperlink_cached_mapping', lambda *_args: None)
    monkeypatch.setattr(main, '_hyperlink_store_mapping', lambda *_args: None)
    monkeypatch.setattr(main, '_hyperlink_saved_pairs', lambda: [pair])

    client = main.app.test_client()
    with client.session_transaction() as session:
        session['hyperlink_net_id'] = 'tester'
    response = client.get('/hyperlink/api/mappings')

    assert response.status_code == 200
    entry = response.get_json()['mappings']['173']
    assert entry['saved_id'] == 173
    assert entry['video_cache_name'] == video_name
    assert entry['video'] == '/hyperlink/data/video/' + video_name


def test_mappings_api_invalidates_cached_mapping_when_saved_pair_added(monkeypatch, tmp_path):
    from datetime import datetime

    from main_html import app as main

    html_root = tmp_path / 'html'
    video_root = tmp_path / 'video'
    html_root.mkdir()
    video_root.mkdir()
    pair = SimpleNamespace(
        id=173,
        pair_key='key-173',
        video_name='session/bus91100.mp4',
        remote_video_path='/remote/out_jpeg/session/bus91100.mp4',
        remote_html_path='/remote/report',
        remote_overlay_path=None,
        overlay_name=None,
        label='report',
        html_folder='report',
        created_at=datetime(2026, 10, 12),
        last_used_at=datetime(2026, 10, 12),
    )

    class EmptyViewer:
        def __init__(self, *_args):
            pass

        def build_mapping(self):
            return {}

    monkeypatch.setattr(main, '_load_hyperlink_log_viewer_app', lambda: EmptyViewer)
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(html_root), str(video_root)))
    monkeypatch.setattr(main, '_hyperlink_cached_mapping', lambda *_args: {'old': {'saved_id': 1}})
    monkeypatch.setattr(main, '_hyperlink_store_mapping', lambda *_args: None)
    monkeypatch.setattr(main, '_hyperlink_saved_pairs', lambda: [pair])
    client = main.app.test_client()
    with client.session_transaction() as session:
        session['hyperlink_net_id'] = 'tester'

    response = client.get('/hyperlink/api/mappings')

    assert response.status_code == 200
    entries = response.get_json()['mappings'].values()
    assert any(entry.get('saved_id') == 173 for entry in entries)


def test_html_recursive_download_skips_acl_denied_subfolder(tmp_path, monkeypatch):
    from types import SimpleNamespace

    from main_html import app as main

    class _Sftp:
        def listdir_attr(self, path):
            if path.endswith('/restricted'):
                raise PermissionError(13, 'Permission denied')
            return [SimpleNamespace(filename='restricted', st_mode=0o040000)]

    skipped = main._hyperlink_sftp_download_dir(_Sftp(), '/remote/report', str(tmp_path / 'report'))

    assert skipped == 1
    assert (tmp_path / 'report' / 'restricted').is_dir()
