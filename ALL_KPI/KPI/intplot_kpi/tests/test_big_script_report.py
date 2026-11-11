import json
import sys
from pathlib import Path

import h5py
import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from big_script_report import write_reports  # noqa: E402


def _make_pair(path: Path, scale: float) -> None:
    n = 200
    with h5py.File(path, 'w') as handle:
        handle.create_dataset('FL/DETECTION_STREAM/Stream_Hdr/scan_index', data=np.arange(n, dtype=np.uint16))
        handle.create_dataset('FL/DETECTION_STREAM/AF_Det/num_af_det', data=(np.arange(n) % 7).astype(np.int32))
        ran = np.random.default_rng(0).uniform(1, 50, (n, 20)).astype(np.float32) * scale
        handle.create_dataset('FL/DETECTION_STREAM/AF_Det/ran', data=ran)
        handle.create_dataset('FL/Voltage/main_volt', data=np.linspace(11.5, 12.5, n) * scale)


def test_big_script_writes_combined_section_reports(tmp_path):
    h_in, h_out = tmp_path / 'in.h5', tmp_path / 'out.h5'
    _make_pair(h_in, 1.0)
    _make_pair(h_out, 1.01)
    inputs = tmp_path / 'inputs.json'
    inputs.write_text(json.dumps({'INPUT_HDF': [str(h_in)], 'OUTPUT_HDF': [str(h_out)]}), encoding='utf-8')
    master = tmp_path / 'html' / 'master_index.html'
    master.parent.mkdir()
    master.write_text('<html><body>master</body></html>', encoding='utf-8')

    written = write_reports(str(inputs), str(tmp_path / 'html'))

    assert written, 'expected at least one sensor report'
    page = Path(written[0]).read_text(encoding='utf-8')
    assert 'UDP Stream Health' in page
    assert 'AF Detections' in page
    assert 'Voltage' in page
    assert 'Normalized' in page
    assert (tmp_path / 'html' / 'big_script' / 'index.html').is_file()
    assert 'big_script/index.html' in master.read_text(encoding='utf-8')


def test_big_script_never_raises_on_bad_input(tmp_path):
    inputs = tmp_path / 'inputs.json'
    inputs.write_text(json.dumps({'INPUT_HDF': ['/missing.h5'], 'OUTPUT_HDF': ['/missing2.h5']}), encoding='utf-8')
    assert write_reports(str(inputs), str(tmp_path)) == []
