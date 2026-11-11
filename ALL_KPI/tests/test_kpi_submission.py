import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'main_html'))

from main_html import app as kpi_app  # noqa: E402


def _form(tmp_path, mode, name_in, name_out, payload_in=b'MDF     \x00' * 8, payload_out=b'MDF     \x00' * 8):
    in_path = tmp_path / name_in
    out_path = tmp_path / name_out
    in_path.write_bytes(payload_in)
    out_path.write_bytes(payload_out)
    return {
        'execution_target': 'udp_kpi',
        'input_mode': mode,
        'input_hdf': str(in_path),
        'output_hdf': str(out_path),
        'config_xml': str(tmp_path / 'ConfigInteractivePlots.xml'),
    }


def test_mf4_pair_is_accepted_and_routed_as_mf4(tmp_path):
    submission = kpi_app._build_runtime_kpi_submission(_form(tmp_path, 'mf4', 'a_b05.MF4', 'a_ORCAS.mf4'))
    assert submission['input_mode'] == 'mf4'
    assert submission['primary_input'].endswith('a_b05.MF4')


def test_mf4_pair_rejects_non_mdf_content(tmp_path):
    with pytest.raises(ValueError, match='not a valid MDF'):
        kpi_app._build_runtime_kpi_submission(_form(tmp_path, 'mf4', 'x.mf4', 'y.mf4', payload_in=b'NOTMDF!!'))


def test_mf4_pair_rejects_wrong_extension(tmp_path):
    with pytest.raises(ValueError, match='must be a .mf4'):
        kpi_app._build_runtime_kpi_submission(_form(tmp_path, 'mf4', 'x.h5', 'y.mf4'))


def test_cluster_mf4_paths_are_not_opened_by_the_web_node():
    form = {
        'execution_target': 'udp_kpi', 'input_mode': 'mf4',
        'input_hdf': '/net/cluster/project/input_b05.MF4',
        'output_hdf': '/net/cluster/project/output_ORCAS.MF4',
        'config_xml': '/net/cluster/config.xml',
    }
    submission = kpi_app._build_runtime_kpi_submission(form)
    assert submission['primary_input'] == form['input_hdf']


def test_unknown_input_mode_is_rejected(tmp_path):
    with pytest.raises(ValueError, match='Unknown input mode'):
        kpi_app._build_runtime_kpi_submission({'execution_target': 'udp_kpi', 'input_mode': 'csv'})


def test_mf4_json_mode_needs_json_path(tmp_path):
    form = {'execution_target': 'udp_kpi', 'input_mode': 'mf4_json', 'config_xml': str(tmp_path / 'c.xml')}
    with pytest.raises(ValueError, match='JSON path is required'):
        kpi_app._build_runtime_kpi_submission(form)
