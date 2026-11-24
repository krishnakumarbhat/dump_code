"""Pairing rules for the batch UDP runner (no HDF or network needed)."""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / 'scripts'))

from run_batch_udp_intplot import build_datasets, normalize_stem


def _record(path, role, key):
    return {'path': Path(path), 'role': role, 'key': key, 'layout': 'MUDP', 'sensors': ['FL'], 'reason': ''}


def test_normalize_stem_strips_capture_suffixes():
    assert normalize_stem('CCA_9010_3100099_DEBUG_20250828_163718_0001_r00070104') == 'CCA_9010_3100099_DEBUG_20250828_163718_0001'
    assert normalize_stem('CCA_9010_3100099_DEBUG_20250828_163718_0001') == 'CCA_9010_3100099_DEBUG_20250828_163718_0001'
    assert normalize_stem('ThunderMCIP_WS11656_20250730_121739_0015_b04_rR000801151_HDF') == 'ThunderMCIP_WS11656_20250730_121739_0015_b04'
    assert normalize_stem('ThunderMCIP_WS11656_20250730_121739_0015_b04_HDF') == 'ThunderMCIP_WS11656_20250730_121739_0015_b04'
    assert normalize_stem('kpi_dummy_pair1_input') == normalize_stem('kpi_dummy_pair1_output') == 'kpi_dummy_pair1'


def test_build_datasets_pairs_by_key_and_self_pairs_orphans():
    records = [
        _record('root/input/cca_r00070104.h5', 'input', normalize_stem('cca_r00070104')),
        _record('root/output/cca.h5', 'output', normalize_stem('cca')),
        _record('root/solo.h5', 'standalone', normalize_stem('solo')),
    ]
    datasets = build_datasets(records)
    modes = {item['name']: item['mode'] for item in datasets}
    assert modes == {'cca_r00070104': 'input/output pair', 'solo': 'self-pair (no reference capture found)'}
    pair = next(item for item in datasets if item['mode'] == 'input/output pair')
    assert pair['input']['path'].name == 'cca_r00070104.h5'
    assert pair['output']['path'].name == 'cca.h5'
    solo = next(item for item in datasets if item['name'] == 'solo')
    assert solo['input'] is solo['output']
