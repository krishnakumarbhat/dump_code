"""Batch Interactive Plot + UDP KPI runner over a folder of MUDP HDF captures.

Purpose: discover every *.h5 under a root, pair input/output captures by stem,
run the Interactive Plot HTML report once for all supported pairs, run UDP KPI
per real pair, and emit one landing index for the whole result folder.

Inputs: --hdf-root (folder), --out (result folder), optional --limit, --skip-ip,
--skip-kpi, --plot-config (repeatable JSON presets).
Outputs: result tree (interactive_plot/, udp_kpi/, logs/, inputs/, configs/),
index.html, README.txt, run_summary.json.
"""

import argparse
import html
import json
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

import h5py

REPO = Path(__file__).resolve().parents[2]
INT_PLOT = REPO / 'ALL_KPI' / 'KPI' / 'intplot_kpi'
KPI_ROOT = REPO / 'ALL_KPI' / 'KPI'
DEFAULT_CONFIG_XML = Path(__file__).resolve().parent / 'ConfigBatchUDP.xml'
DEFAULT_PLOT_CONFIG = Path(__file__).resolve().parent / 'batch_udp_plot_config.json'
MUDP_STREAMS = ('DETECTION_STREAM', 'RDD_STREAM', 'DOWN_SELECTION_STREAM', 'TOI_STREAM', 'VSE_STREAM')
DC_MARKER = '00_metadata'
PAIR_SUFFIX = re.compile(r'(?:_r[rR]?\d+)(?:_HDF)?$|_HDF$|_(?:input|output)$', re.IGNORECASE)


def normalize_stem(stem: str) -> str:
    """Purpose: map '<capture>_r00070104' and '<capture>' to one pairing key."""
    return PAIR_SUFFIX.sub('', stem).strip()


def describe_hdf(path: Path) -> dict:
    """Purpose: read root groups/streams so layout support can be decided safely."""
    try:
        with h5py.File(path, 'r') as handle:
            sensors = [name for name in handle.keys() if isinstance(handle[name], h5py.Group)]
            streams = sorted({child for sensor in sensors for child in handle[sensor].keys()
                              if isinstance(handle[sensor][child], h5py.Group)})
    except Exception as exc:  # unreadable/truncated capture must not abort the batch
        return {'sensors': [], 'streams': [], 'layout': 'UNREADABLE', 'reason': f'{type(exc).__name__}: {exc}'}
    if DC_MARKER in sensors:
        return {'sensors': sensors, 'streams': streams, 'layout': 'DC_HDF_FORMAT',
                'reason': 'Data Collector HDF layout has no MUDP streams; the MUDP plot/KPI pipeline cannot read it.'}
    if not any(stream in MUDP_STREAMS for stream in streams):
        return {'sensors': sensors, 'streams': streams, 'layout': 'UNKNOWN',
                'reason': 'No MUDP stream (DETECTION/RDD/DOWN_SELECTION/TOI/VSE) present.'}
    return {'sensors': sensors, 'streams': streams, 'layout': 'MUDP', 'reason': ''}


def discover(root: Path) -> list:
    """Purpose: list every HDF with its pairing role based on its parent folder."""
    records = []
    for path in sorted(root.rglob('*.h5')):
        if not path.is_file() or path.stat().st_size == 0:
            continue
        role = path.parent.name.lower() if path.parent.name.lower() in ('input', 'output') else 'standalone'
        records.append({'path': path, 'role': role, 'key': normalize_stem(path.stem), **describe_hdf(path)})
    return records


def build_datasets(records: list) -> list:
    """Purpose: pair input/output captures by normalized stem, else self-pair the file."""
    grouped = {}
    for record in records:
        grouped.setdefault(record['key'], {'input': [], 'output': [], 'standalone': []})[record['role']].append(record)
    datasets, used = [], set()
    for key, group in grouped.items():
        for input_record in group['input']:
            if group['output']:
                output_record = group['output'][0]
                used.update({input_record['path'], output_record['path']})
                datasets.append({'name': input_record['path'].stem, 'input': input_record,
                                 'output': output_record, 'mode': 'input/output pair'})
        for record in group['standalone']:
            if record['path'] not in used:
                used.add(record['path'])
                datasets.append({'name': record['path'].stem, 'input': record, 'output': record,
                                 'mode': 'self-pair (no reference capture found)'})
        for record in group['output']:
            if record['path'] not in used:
                used.add(record['path'])
                datasets.append({'name': record['path'].stem, 'input': record, 'output': record,
                                 'mode': 'self-pair (no reference capture found)'})
    for record in records:
        if record['path'] not in used:
            datasets.append({'name': record['path'].stem, 'input': record, 'output': record,
                             'mode': 'self-pair (no reference capture found)'})
    return sorted(datasets, key=lambda item: (item['mode'].startswith('self'), item['name'].lower()))


def run(command: list, cwd: Path, log_path: Path, timeout: int, env_extra: dict) -> tuple:
    """Purpose: execute one subprocess with captured log; never raise on failure."""
    env = os.environ.copy()
    env.update(env_extra)
    started = time.time()
    log_path.parent.mkdir(parents=True, exist_ok=True)
    with open(log_path, 'w', encoding='utf-8', errors='replace') as log:
        log.write(f'$ {subprocess.list2cmdline(command)}\ncwd={cwd}\n\n')
        log.flush()
        try:
            result = subprocess.run(command, cwd=str(cwd), stdout=log, stderr=subprocess.STDOUT,
                                    timeout=timeout, env=env)
            code = result.returncode
        except subprocess.TimeoutExpired:
            code = 'timeout'
        except Exception as exc:
            log.write(f'\n[runner] {type(exc).__name__}: {exc}\n')
            code = 'error'
    return code, round(time.time() - started, 1)


def rel_link(target: Path, base: Path) -> str:
    """Purpose: produce a relative, URL-safe link for the landing page."""
    try:
        return Path(os.path.relpath(target, base)).as_posix().replace(' ', '%20')
    except ValueError:
        return Path(target).as_posix()


def write_readme(out_dir: Path, root: Path, datasets: list, config_name: str, plot_configs: list) -> None:
    """Purpose: leave a plain-text handoff next to the HTML index."""
    pairs = sum(1 for item in datasets if item['mode'].startswith('input'))
    lines = [
        'Edge UDP batch results',
        '======================',
        '',
        'Open index.html first.',
        '',
        f'Source folder : {root}',
        f'Plot config   : {config_name}',
        f'Signal config : {", ".join(path.name for path in plot_configs)}',
        f'Datasets      : {len(datasets)} ({pairs} input/output pairs, {len(datasets) - pairs} self-pairs)',
        '',
        'Layout',
        '  interactive_plot/   Interactive Plot overlay HTML per dataset/sensor',
        '  interactive_plot/big_script/   ordered CDC -> RDD -> Detection -> AF -> Tracker analysis',
        '  udp_kpi/            UDP KPI pages per compared pair',
        '  inputs/             Inputs_batch.json handed to the plotter',
        '  configs/            exact XML + plot JSON used for this run',
        '  logs/               per-step stdout/stderr',
        '',
        'Notes',
        '  - Each file is paired with an input/output counterpart by capture stem when one exists.',
        '  - Files without a reference capture are self-paired: the same HDF is used as input and',
        '    output, so every overlay delta is zero by construction. Use them for signal inspection,',
        '    not for regression conclusions.',
        '  - DC_HDF_FORMAT (00_metadata/01_Scan_Index/...) and non-MUDP CAN layouts are skipped',
        '    and listed with the reason in index.html.',
        '  - The in-run KPI ZMQ server is not used; UDP KPI runs separately in HDF mode.',
        '',
    ]
    (out_dir / 'README.txt').write_text('\n'.join(lines), encoding='utf-8')


def build_index(out_dir: Path, datasets: list, config_name: str) -> Path:
    """Purpose: write the landing page that tells the operator where every result lives."""
    rows = []
    for item in datasets:
        input_rec, output_rec = item['input'], item['output']
        supported = input_rec['layout'] == 'MUDP' and output_rec['layout'] == 'MUDP'
        status = item.get('status', 'not run')
        links = []
        ip_page, big_script, kpi_page = item.get('ip_page'), item.get('big_script'), item.get('kpi_page')
        if ip_page:
            links.append(f'<a href="{rel_link(ip_page, out_dir)}">plots</a>')
        if big_script:
            links.append(f'<a href="{rel_link(big_script, out_dir)}">analysis</a>')
        if kpi_page:
            links.append(f'<a href="{rel_link(kpi_page, out_dir)}">KPI</a>')
        note = item.get('note') or (input_rec['reason'] if not supported else '')
        rows.append(
            '<tr>'
            f'<td>{html.escape(item["name"])}</td>'
            f'<td>{html.escape(item["mode"])}</td>'
            f'<td>{html.escape(input_rec["layout"])}</td>'
            f'<td>{html.escape(",".join(input_rec["sensors"])[:60])}</td>'
            f'<td class="{status.replace(" ", "-")}">{html.escape(status)}</td>'
            f'<td>{" · ".join(links) or "-"}</td>'
            f'<td>{html.escape(note)}</td>'
            f'<td>{item.get("seconds") or "-"}</td>'
            '</tr>'
        )
    totals = {state: sum(1 for item in datasets if item.get('status') == state)
              for state in sorted({item.get('status', 'not run') for item in datasets})}
    cards = ''.join(f'<div class="kpi"><b>{count}</b><span>{html.escape(state)}</span></div>'
                    for state, count in totals.items())
    style = ('body{font-family:Segoe UI,Arial,sans-serif;margin:0;background:#f4f6f8;color:#1b2733}'
             'header{background:#16324a;color:#fff;padding:18px 28px}header h1{margin:0;font-size:22px}'
             'header p{margin:5px 0 0;color:#c8d6e2;font-size:13px;overflow-wrap:anywhere}'
             'main{max-width:1500px;margin:0 auto;padding:18px 28px}'
             'section{background:#fff;border:1px solid #dde3ea;border-radius:12px;padding:16px 18px;margin-bottom:16px}'
             'section h2{margin:0 0 6px;font-size:17px}.story{color:#5f6d7c;font-size:13px;margin:0 0 12px}'
             '.kpis{display:grid;grid-template-columns:repeat(auto-fit,minmax(150px,1fr));gap:10px;margin:10px 0}'
             '.kpi{border:1px solid #dce5ec;background:#f8fbfd;border-radius:9px;padding:12px}'
             '.kpi b{display:block;font-size:20px;color:#174e68}.kpi span{font-size:11px;color:#607181}'
             '.tw{overflow-x:auto}table{border-collapse:collapse;width:100%;font-size:12px}'
             'th,td{border-bottom:1px solid #eef1f4;padding:6px 8px;text-align:left;vertical-align:top}'
             'th{background:#f7f9fb;position:sticky;top:0}a{color:#0f6b5c}'
             '.ok{color:#1c7a4a;font-weight:600}.skipped{color:#9a6b12;font-weight:600}'
             '.failed{color:#b23a3a;font-weight:600}')
    page = (
        '<!doctype html><html><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">'
        f'<title>Edge UDP batch results</title><style>{style}</style></head><body>'
        f'<header><h1>Edge UDP batch · Interactive Plot + KPI</h1>'
        f'<p>Every HDF under edge_hdf/udp processed with {html.escape(config_name)}. '
        f'Input/output pairs are compared; files without a reference capture are self-paired and marked as such.</p>'
        f'<div class="kpis">{cards}</div></header><main>'
        '<section><h2>Start here</h2><p class="story">'
        '<a href="interactive_plot/master_index.html">Interactive Plot master index</a> · '
        '<a href="interactive_plot/big_script/index.html">Radar pipeline analysis (Big Script)</a> · '
        '<a href="udp_kpi/index.html">UDP KPI index</a> · '
        '<a href="run_summary.json">run_summary.json</a> · <a href="README.txt">README.txt</a></p></section>'
        '<section><h2>Datasets</h2><p class="story">Plots = Interactive Plot overlay HTML per sensor. '
        'Analysis = ordered CDC → RDD → Detection → AF → Tracker report. KPI = UDP KPI detection/alignment pages. '
        'Self-pairs compare a file with itself, so deltas are zero by construction.</p>'
        '<div class="tw"><table><thead><tr><th>Dataset</th><th>Mode</th><th>Layout</th><th>Sensors</th>'
        '<th>Status</th><th>Results</th><th>Note</th><th>Seconds</th></tr></thead><tbody>'
        + ''.join(rows) + '</tbody></table></div></section></main></body></html>'
    )
    target = out_dir / 'index.html'
    target.write_text(page, encoding='utf-8')
    return target


def main() -> int:
    """Purpose: orchestrate discovery, plotting, KPI and index generation in one pass."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hdf-root', required=True)
    parser.add_argument('--out', required=True)
    parser.add_argument('--config', default=str(DEFAULT_CONFIG_XML))
    parser.add_argument('--plot-config', action='append', default=None)
    parser.add_argument('--limit', type=int, default=0)
    parser.add_argument('--skip-ip', action='store_true')
    parser.add_argument('--skip-kpi', action='store_true')
    parser.add_argument('--ip-timeout', type=int, default=7200)
    parser.add_argument('--kpi-timeout', type=int, default=1800)
    args = parser.parse_args()

    root, out_dir = Path(args.hdf_root).resolve(), Path(args.out).resolve()
    plot_configs = [Path(p).resolve() for p in (args.plot_config or [str(DEFAULT_PLOT_CONFIG)])]
    config_xml = Path(args.config).resolve()
    for required in (root, config_xml, *plot_configs):
        if not required.exists():
            print(f'Missing required path: {required}', file=sys.stderr)
            return 2

    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / 'logs').mkdir(exist_ok=True)
    (out_dir / 'inputs').mkdir(exist_ok=True)
    (out_dir / 'configs').mkdir(exist_ok=True)
    shutil.copy2(config_xml, out_dir / 'configs' / config_xml.name)
    for plot_config in plot_configs:
        shutil.copy2(plot_config, out_dir / 'configs' / plot_config.name)

    datasets = build_datasets(discover(root))
    if args.limit:
        datasets = datasets[:args.limit]
    supported = [item for item in datasets if item['input']['layout'] == 'MUDP' and item['output']['layout'] == 'MUDP']
    for item in datasets:
        if item not in supported:
            item['status'] = 'skipped'
            item['note'] = item['input']['reason'] or item['output']['reason']

    inputs_json = out_dir / 'inputs' / 'Inputs_batch.json'
    inputs_json.write_text(json.dumps({
        'INPUT_HDF': [str(item['input']['path']) for item in supported],
        'OUTPUT_HDF': [str(item['output']['path']) for item in supported],
    }, indent=2), encoding='utf-8')

    if not args.skip_ip and supported:
        code, seconds = run(
            [sys.executable, 'ResimHTMLReport.py', str(config_xml), str(inputs_json),
             str(out_dir / 'interactive_plot'), *[str(p) for p in plot_configs]],
            cwd=INT_PLOT, log_path=out_dir / 'logs' / 'interactive_plot.log',
            timeout=args.ip_timeout, env_extra={'PYTHONPATH': str(INT_PLOT)},
        )
        print(f'[batch] interactive plot exit={code} in {seconds}s')
        for item in supported:
            base = item['input']['path'].stem
            page = out_dir / 'interactive_plot' / base / f'{base}.html'
            reports = sorted((out_dir / 'interactive_plot' / 'big_script').glob(f'{base}_*_big_script.html'))
            item['ip_page'] = page if page.exists() else None
            item['big_script'] = reports[0] if reports else None
            item['status'] = 'ok' if (page.exists() or reports) else 'failed'
            item['seconds'] = seconds if len(supported) == 1 else None
            if not page.exists() and not reports:
                item['note'] = 'Interactive Plot produced no HTML for this file.'

    kpi_index_rows = []
    if not args.skip_kpi:
        for item in supported:
            if item['mode'].startswith('self'):
                continue
            base = item['input']['path'].stem
            kpi_dir = out_dir / 'udp_kpi'
            code, seconds = run(
                [sys.executable, '-m', 'UDP_KPI.kpi_server', str(item['input']['path']),
                 str(item['output']['path']), str(kpi_dir)],
                cwd=KPI_ROOT, log_path=out_dir / 'logs' / f'kpi_{base}.log',
                timeout=args.kpi_timeout, env_extra={'PYTHONPATH': str(KPI_ROOT)},
            )
            pages = sorted((kpi_dir / base).rglob('*.html'))
            item['kpi_page'] = pages[0] if pages else None
            item['kpi_status'] = 'ok' if pages else 'failed'
            item['kpi_seconds'] = seconds
            if not pages and not item.get('note'):
                item['note'] = 'UDP KPI produced no HTML (see logs).'
            kpi_index_rows.append((base, item['kpi_status'], len(pages), seconds))
            print(f'[batch] kpi {base} exit={code} pages={len(pages)} in {seconds}s')

    if kpi_index_rows:
        kpi_style = ('body{font-family:Segoe UI,Arial,sans-serif;padding:24px;background:#f6f8fa}'
                     'table{border-collapse:collapse}td,th{border-bottom:1px solid #e3e8ee;padding:6px 10px;font-size:13px}')
        (out_dir / 'udp_kpi' / 'index.html').write_text(
            '<!doctype html><meta charset="utf-8"><title>UDP KPI results</title>'
            f'<style>{kpi_style}</style><h1>UDP KPI results</h1><table><tr><th>Dataset</th><th>Status</th>'
            '<th>Pages</th><th>Seconds</th></tr>'
            + ''.join(f'<tr><td>{html.escape(name)}</td><td>{status}</td><td>{count}</td><td>{seconds}</td></tr>'
                      for name, status, count, seconds in kpi_index_rows)
            + '</table>', encoding='utf-8')

    summary = [{'name': item['name'], 'mode': item['mode'], 'layout': item['input']['layout'],
                'status': item['status'], 'kpi_status': item.get('kpi_status'),
                'input': str(item['input']['path']), 'output': str(item['output']['path']),
                'note': item.get('note', '')} for item in datasets]
    (out_dir / 'run_summary.json').write_text(json.dumps(summary, indent=2), encoding='utf-8')
    build_index(out_dir, datasets, config_xml.name)
    write_readme(out_dir, root, datasets, config_xml.name, plot_configs)

    ok = sum(1 for item in datasets if item['status'] == 'ok')
    print(f'[batch] datasets={len(datasets)} plotted={ok} skipped={len(datasets) - ok} out={out_dir}')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())
