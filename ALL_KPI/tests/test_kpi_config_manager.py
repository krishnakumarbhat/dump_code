from pathlib import Path
import sys
import os

import pytest

MAIN_HTML = Path(__file__).resolve().parents[1] / 'main_html'
sys.path.insert(0, str(MAIN_HTML))

import kpi_config_manager as manager


def test_configurations_are_seeded_and_saved_per_netid(monkeypatch, tmp_path):
    monkeypatch.setenv('HPCC_KPI_CONFIG_ROOT', str(tmp_path / 'configs'))
    monkeypatch.setenv('HPCC_PROJECT_ROOT', str(Path(__file__).resolve().parents[1]))

    alice = manager.configuration_path('udp_config_xml', 'alice')
    bob = manager.configuration_path('udp_config_xml', 'bob')
    assert Path(alice).is_file()
    assert Path(bob).is_file()
    assert Path(alice).parent != Path(bob).parent

    updated = '<Configuration><PLOT_MODE><KPI>0</KPI></PLOT_MODE></Configuration>'
    manager.save_configuration('udp_config_xml', updated, 'alice')

    assert manager.get_configuration('udp_config_xml', 'alice')[1] == updated
    assert manager.get_configuration('udp_config_xml', 'bob')[1] != updated
    if os.name == 'posix':
        assert Path(alice).stat().st_mode & 0o077 == 0


@pytest.mark.parametrize('net_id', ['', '../bob', 'bad/id', '.'])
def test_invalid_netid_cannot_escape_private_config_root(monkeypatch, tmp_path, net_id):
    monkeypatch.setenv('HPCC_KPI_CONFIG_ROOT', str(tmp_path / 'configs'))
    with pytest.raises(ValueError, match='NetID'):
        manager.list_configurations(net_id)
