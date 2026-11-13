"""Regression checks for persistent single-media adds and complete atomic cache files."""
import os
from pathlib import Path
from types import SimpleNamespace

import pytest


def test_download_preserves_old_cache_on_failure_and_skips_unchanged(tmp_path):
    from main_html import app as main
    target = tmp_path / 'clip.mp4'
    target.write_bytes(b'old-data')
    calls = []

    class Sftp:
        def stat(self, path):
            return SimpleNamespace(st_size=8, st_mtime=100)

        def get(self, remote, local, max_concurrent_prefetch_requests=None):
            calls.append(local)
            assert max_concurrent_prefetch_requests == 32
            Path(local).write_bytes(b'part')

    with pytest.raises(IOError, match='Incomplete'):
        main._hyperlink_sftp_download_file(Sftp(), '/remote/clip.mp4', str(target))
    assert target.read_bytes() == b'old-data'
    assert not list(tmp_path.glob('*.part'))
    os.utime(target, (100, 100))
    assert main._hyperlink_sftp_download_file(Sftp(), '/remote/clip.mp4', str(target))
    assert len(calls) == 1


@pytest.mark.parametrize('video_only', [True, False])
def test_single_media_add_returns_persisted_viewer_entry(monkeypatch, tmp_path, video_only):
    from main_html import app as main
    pairs = []

    class Query:
        def filter_by(self, **filters):
            self.filters = {**getattr(self, 'filters', {}), **filters}
            return self

        def first(self):
            result = next((pair for pair in pairs if all(getattr(pair, k) == v for k, v in self.filters.items())), None)
            self.filters = {}
            return result

    class Pair:
        query = Query()

        def __init__(self, **kwargs):
            self.__dict__.update(kwargs)
            self.id, self.created_at = 71, None

    def add(pair):
        if pair not in pairs:
            pairs.append(pair)

    class Sftp:
        def get(self, remote, local):
            Path(local).write_bytes(b'complete-video')

        def listdir_attr(self, path):
            return [SimpleNamespace(filename='index.html', st_mode=0o100644)]

    monkeypatch.setattr(main, 'HyperlinkSavedPair', Pair)
    monkeypatch.setattr(main.db.session, 'add', add)
    monkeypatch.setattr(main.db.session, 'commit', lambda: None)
    monkeypatch.setattr(main, '_hyperlink_saved_owner', lambda: ('tester', None))
    monkeypatch.setattr(main, '_hyperlink_get_user_key', lambda: 'tester')
    monkeypatch.setattr(main, '_hyperlink_get_live_session', lambda user: {'sftp': Sftp()})
    html, video = tmp_path / 'html', tmp_path / 'video'
    html.mkdir()
    video.mkdir()
    monkeypatch.setattr(main, '_hyperlink_get_user_dirs', lambda: (str(tmp_path), str(html), str(video)))
    body = {'key': '20261113_123115_0000', 'html_path': '' if video_only else '/remote/report',
            'video_path': '/remote/clip.mp4' if video_only else ''}
    client = main.app.test_client()
    for _ in range(2):
        response = client.post('/hyperlink/api/cluster/download-log', json=body)
        assert response.status_code == 200, response.json
        assert response.json['saved_id'] == 71
        assert response.json['entry']['saved_id'] == 71
        assert response.json['entry']['cached'] is True
        assert response.json['entry']['html_missing'] is video_only
        assert response.json['entry']['cached_video'] is video_only
    assert len(pairs) == 1
    assert pairs[0].html_folder == ('' if video_only else 'report')
