"""End-to-end MF4 -> HDF pairing through kpi_runtime_launcher.sh with a fake container runtime."""
import json
import os
import shutil
import stat
import subprocess
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
pytestmark = pytest.mark.skipif(shutil.which('bash') is None or os.name == 'nt', reason='needs bash (Linux/WSL)')


def _fake_runtime(bin_dir: Path, log: Path) -> None:
    """Fake apptainer: logs argv and, for RUN_MUDP.sh, writes one .h5 per listed MF4."""
    bin_dir.mkdir(parents=True, exist_ok=True)
    script = bin_dir / 'apptainer'
    script.write_text(
        '#!/usr/bin/env bash\n'
        f'echo "$@" >> "{log}"\n'
        'if [[ "$*" == *RUN_MUDP.sh* ]]; then\n'
        '  list="${@: -2:1}"; out="${@: -1}"; mkdir -p "$out"\n'
        '  while read -r f; do b=$(basename "$f" .MF4); b=$(basename "$b" .mf4); echo x > "$out/${b}_r00100012.h5"; done < "$list"\n'
        'fi\n',
        encoding='utf-8',
    )
    script.chmod(script.stat().st_mode | stat.S_IEXEC)


def test_mf4_pairs_convert_then_reach_kpi_runner(tmp_path):
    bundle = tmp_path / 'bundle'
    bundle.mkdir()
    for name in ('kpi_runtime_launcher.sh', 'bundle_common.sh'):
        shutil.copy(ROOT / name, bundle / name)
    (bundle / 'hpcc_runtime.env').write_text('PORT="5008"\n')
    (bundle / 'kpi' / 'can').mkdir(parents=True)
    runner = bundle / 'kpi' / 'udp' / 'run_udp.sh'
    runner.parent.mkdir(parents=True)
    runner.write_text('#!/usr/bin/env bash\necho "RUNNER $@" > "$BUNDLE_ROOT/runner_args.txt"\n', encoding='utf-8')
    runner.chmod(0o755)
    (bundle / 'runner_args.txt').touch()
    log = tmp_path / 'runtime.log'
    _fake_runtime(tmp_path / 'fakebin', log)
    mudp_simg = tmp_path / 'mudp.simg'
    mudp_simg.write_bytes(b'x')
    mudp_cfg = tmp_path / 'mudp.xml'
    mudp_cfg.write_text('<cfg><Data_Extraction_Mode><CSV_MODE>1</CSV_MODE><HDF_MODE>0</HDF_MODE></Data_Extraction_Mode></cfg>', encoding='utf-8')
    in_mf4 = tmp_path / 'CEER_S12_20260701_151002_0000_b05.MF4'
    out_mf4 = tmp_path / 'CEER_S12_20260701_151002_0000_ORCAS.mf4'
    in_mf4.write_bytes(b'MDF     ' + b'\x00' * 8)
    out_mf4.write_bytes(b'MDF     ' + b'\x00' * 8)
    out_dir = tmp_path / 'out'

    env = dict(os.environ, PATH=f"{tmp_path / 'fakebin'}:{os.environ['PATH']}",
               MUDP_SIMG=str(mudp_simg), MUDP_CONFIG=str(mudp_cfg), BUNDLE_ROOT=str(bundle))
    result = subprocess.run(
        ['bash', str(bundle / 'kpi_runtime_launcher.sh'), '--target', 'udp_kpi', '--input-mode', 'mf4',
         '--input-hdf', str(in_mf4), '--output-hdf', str(out_mf4), '--output-dir', str(out_dir)],
        env=env, capture_output=True, text=True, timeout=120,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'KPI socket port=5560' in result.stdout
    assert 'RUN_MUDP.sh' in log.read_text(encoding='utf-8')
    pairs = json.loads((out_dir / 'converted_hdf' / 'pairs.json').read_text(encoding='utf-8'))
    assert len(pairs['INPUT_HDF']) == 1 and len(pairs['OUTPUT_HDF']) == 1
    assert pairs['INPUT_HDF'][0].endswith('.h5') and pairs['OUTPUT_HDF'][0].endswith('.h5')
    assert 'RUNNER' in (bundle / 'runner_args.txt').read_text(encoding='utf-8')
    import xml.etree.ElementTree as ET
    original = ET.parse(mudp_cfg).getroot()
    generated = ET.parse(out_dir / 'converted_hdf' / 'extract_hdf.xml').getroot()
    assert original.findtext('Data_Extraction_Mode/HDF_MODE') == '0'
    assert generated.findtext('Data_Extraction_Mode/HDF_MODE') == '1'
    assert generated.findtext('Data_Extraction_Mode/CSV_MODE') == '0'


def _bundle(tmp_path: Path, runner_rel: str) -> Path:
    bundle = tmp_path / 'bundle'
    bundle.mkdir()
    for name in ('kpi_runtime_launcher.sh', 'bundle_common.sh'):
        shutil.copy(ROOT / name, bundle / name)
    runner = bundle / runner_rel
    runner.parent.mkdir(parents=True, exist_ok=True)
    runner.write_text('#!/usr/bin/env bash\necho "RUNNER $@" > "$BUNDLE_ROOT/runner_args.txt"\n', encoding='utf-8')
    runner.chmod(0o755)
    (bundle / 'runner_args.txt').touch()
    return bundle


def _mf4_inputs(tmp_path: Path):
    in_mf4 = tmp_path / 'CAN_S12_20260701_151002_0000_b05.MF4'
    out_mf4 = tmp_path / 'CAN_S12_20260701_151002_0000_ORCAS.mf4'
    in_mf4.write_bytes(b'MDF     ' + b'\x00' * 8)
    out_mf4.write_bytes(b'MDF     ' + b'\x00' * 8)
    return in_mf4, out_mf4


def _run_launcher(bundle: Path, args: list, env_extra: dict):
    env = dict(os.environ, BUNDLE_ROOT=str(bundle), **env_extra)
    return subprocess.run(['bash', str(bundle / 'kpi_runtime_launcher.sh'), *args], env=env, capture_output=True, text=True, timeout=120)


def test_can_mf4_is_refused_without_can_converter(tmp_path):
    bundle = _bundle(tmp_path, 'kpi/can/run_can.sh')
    in_mf4, out_mf4 = _mf4_inputs(tmp_path)
    result = _run_launcher(bundle, ['--target', 'can_kpi', '--input-mode', 'mf4', '--input-hdf', str(in_mf4),
                                    '--output-hdf', str(out_mf4), '--output-dir', str(tmp_path / 'out')],
                           {'MUDP_SIMG': '', 'CAN_MF4_CONVERT_CMD': ''})
    assert result.returncode != 0
    assert 'CAN MF4 converter is not configured' in result.stderr


def test_udp_reads_site_pipeline_config_and_ignores_legacy_kpi_image(tmp_path):
    bundle = _bundle(tmp_path, 'kpi/udp/run_udp.sh')
    in_mf4, out_mf4 = _mf4_inputs(tmp_path)
    log = tmp_path / 'runtime.log'
    _fake_runtime(tmp_path / 'fakebin', log)
    image = tmp_path / 'mudp.simg'
    image.write_bytes(b'x')
    xml = tmp_path / 'extract.xml'
    xml.write_text('<config><Data_Extraction_Mode><CSV_MODE>1</CSV_MODE><HDF_MODE>0</HDF_MODE></Data_Extraction_Mode></config>')
    site_config = tmp_path / 'mudp_kpi_config.txt'
    site_config.write_text(f'mudp_simg:{image}\nmudp_config:{xml}\nudp_kpi_simg:/obsolete.simg\n')
    result = _run_launcher(bundle, [
        '--target', 'udp_kpi', '--input-mode', 'mf4',
        '--input-hdf', str(in_mf4), '--output-hdf', str(out_mf4),
        '--output-dir', str(tmp_path / 'out'),
    ], {
        'PATH': f"{tmp_path / 'fakebin'}:{os.environ['PATH']}",
        'MUDP_PIPELINE_CONFIG': str(site_config), 'MUDP_SIMG': '', 'MUDP_CONFIG': '',
    })
    assert result.returncode == 0, result.stdout + result.stderr
    assert str(image) in log.read_text()
    assert '/obsolete.simg' not in log.read_text()
    assert 'RUNNER' in (bundle / 'runner_args.txt').read_text()


def test_can_mf4_uses_configured_can_converter_not_mudp(tmp_path):
    bundle = _bundle(tmp_path, 'kpi/can/run_can.sh')
    in_mf4, out_mf4 = _mf4_inputs(tmp_path)
    converter = tmp_path / 'fake_can_converter.sh'
    converter.write_text(
        '#!/usr/bin/env bash\n'
        'list="$1"; out="$2"; mkdir -p "$out"\n'
        'while read -r f; do b=$(basename "$f"); b=${b%.*}; echo x > "$out/${b}_r00100012.h5"; done < "$list"\n',
        encoding='utf-8',
    )
    result = _run_launcher(bundle, ['--target', 'can_kpi', '--input-mode', 'mf4', '--input-hdf', str(in_mf4),
                                    '--output-hdf', str(out_mf4), '--output-dir', str(tmp_path / 'out')],
                           {'CAN_MF4_CONVERT_CMD': f'bash {converter} {{list}} {{out}}', 'MUDP_SIMG': '/nonexistent.simg'})
    assert result.returncode == 0, result.stdout + result.stderr
    pairs = json.loads((tmp_path / 'out' / 'converted_hdf' / 'pairs.json').read_text(encoding='utf-8'))
    assert len(pairs['INPUT_HDF']) == 1 and len(pairs['OUTPUT_HDF']) == 1
    assert 'RUNNER' in (bundle / 'runner_args.txt').read_text(encoding='utf-8')


def test_converted_pairing_preserves_each_sensor(tmp_path):
    bundle = _bundle(tmp_path, 'kpi/can/run_can.sh')
    in_mf4, out_mf4 = _mf4_inputs(tmp_path)
    converter = tmp_path / 'per_sensor_converter.sh'
    converter.write_text(
        '#!/usr/bin/env bash\n'
        'mkdir -p "$2"\n'
        'while read -r f; do b=$(basename "$f"); b=${b%.*}; '
        'for sensor in RL RR; do echo x > "$2/${b}_${sensor}_TRACKER.h5"; done; done < "$1"\n'
    )
    result = _run_launcher(bundle, [
        '--target', 'can_kpi', '--input-mode', 'mf4',
        '--input-hdf', str(in_mf4), '--output-hdf', str(out_mf4),
        '--output-dir', str(tmp_path / 'out'),
    ], {'CAN_MF4_CONVERT_CMD': f'bash {converter} {{list}} {{out}}'})
    assert result.returncode == 0, result.stdout + result.stderr
    pairs = json.loads((tmp_path / 'out' / 'converted_hdf' / 'pairs.json').read_text())
    assert len(pairs['INPUT_HDF']) == len(pairs['OUTPUT_HDF']) == 2
