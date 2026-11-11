"""Big Script style story report rebuilt in Plotly, read straight from HDF.

Purpose: mirror the MATLAB "Big Script Report" sections (stream health, scan
index skips, XPUT/timing, AF/RDD/CDC, tracker, host data, voltage,
temperature, time sync, alignment, faults) with ONE combined plot per section:
every matching parameter is a trace (input solid, output dashed) and a
Raw/Normalized toggle lets differently-scaled signals share the plot.

Usage: python big_script_report.py <inputs.json> <output_dir>
       (also called automatically by ResimHTMLReport.py / can_intplot_main.py)
"""
from __future__ import annotations

import html
import json
import os
import re
import sys
from typing import Dict, Iterable, List, Tuple

import h5py
import numpy as np
import plotly.graph_objects as go

# (title, one-line story, path regex). First match wins, order mirrors Big Script.
SECTIONS: List[Tuple[str, str, str]] = [
    ('XPUT & Timing', 'Processing time, latency and idle budget per scan.', r'latency|xput|time_spent|module_time|idle|exec_time|duration|cycle_time'),
    ('AF Detections', 'How many detections AF produced each scan.', r'num_af_det|num_.*det|num_fp|num_sp|bistatic_count|rest_count'),
    ('AF Detection Properties', 'Per-scan mean of range / velocity / SNR / RCS / angles of valid detections.', r'af_det/(ran|vel|snr|rcs|theta|phi|pow)$'),
    ('RDD', 'Range-Doppler stage outputs and coverage.', r'rdd|range_coverage|doppler_coverage|rbin|dbin'),
    ('CDC Bins', 'CDC bin usage.', r'cdc'),
    ('Tracker', 'Object counts and tracker health.', r'num_obj|object|track|underdriv'),
    ('Host Vehicle Data', 'VSE / ego-motion inputs the tracker relies on.', r'vse|ego|speed|yaw|host|steer|accel'),
    ('Voltage', 'Supply rails over the log.', r'volt'),
    ('Temperature', 'Thermal sensors over the log.', r'temp'),
    ('Time Sync', 'Dwell timestamps, sync status and jitter.', r'sync|jitter|dwell'),
    ('Alignment', 'Mounting / alignment estimates.', r'align|mount|misalign'),
    ('Faults & Diagnostics', 'Fault bytes, resets, error and timeout counters.', r'fault|reset|error|exception|diag|counter|timeout|saturation|checksum'),
]
SCAN_RE = re.compile(r'(^|/)(scan_?index)$', re.I)
MAX_POINTS = 4000      # ponytail: stride-downsample per trace; raise if plots look sparse
MAX_TRACES = 48        # per section, keeps the HTML small and fast


def _pairs(inputs_json: str) -> List[Tuple[str, str]]:
    """Purpose: read input/output HDF pairs. Inputs: InputsInteractivePlot-style JSON. Outputs: list of (in, out)."""
    data = json.load(open(inputs_json, encoding='utf-8'))
    if isinstance(data, list):
        return [(d['input_path'], d['output_path']) for d in data]
    flat = lambda v: [x for item in v for x in (item if isinstance(item, list) else [item])]
    ins, outs = flat(data.get('INPUT_HDF', [])), flat(data.get('OUTPUT_HDF', []))
    return list(zip(ins, outs))


def _signals(path: str) -> Dict[str, Dict[str, np.ndarray]]:
    """Purpose: load 1-D signals (2-D -> per-row mean of non-zero). Outputs: {sensor: {stream/group/name: array}}."""
    result: Dict[str, Dict[str, np.ndarray]] = {}
    if not path or not os.path.isfile(path):
        return result
    with h5py.File(path, 'r') as handle:
        def visit(name, obj):
            if not isinstance(obj, h5py.Dataset) or obj.dtype.kind not in 'iufb' or obj.ndim not in (1, 2):
                return
            parts = name.split('/')
            sensor, key = (parts[0], '/'.join(parts[1:])) if len(parts) > 2 else ('LOG', name)
            values = obj[()].astype(float)
            if values.ndim == 2:
                if not re.search(SECTIONS[2][2], key.lower()):
                    return
                masked = np.where(values != 0, values, np.nan)
                with np.errstate(all='ignore'):
                    values = np.nanmean(masked, axis=1)
            result.setdefault(sensor, {})[key] = values
        handle.visititems(visit)
    return result


def _scan_axis(signals: Dict[str, np.ndarray], key: str) -> np.ndarray:
    """Purpose: x-axis for a signal = scan index of its stream when lengths agree, else sample number."""
    stream = key.split('/')[0]
    values = signals[key]
    for name, scan in signals.items():
        if name.startswith(stream + '/') and SCAN_RE.search(name) and len(scan) == len(values):
            return scan
    return np.arange(len(values), dtype=float)


def _thin(x: np.ndarray, y: np.ndarray) -> Tuple[list, list]:
    step = max(1, len(y) // MAX_POINTS)
    return x[::step].tolist(), [None if not np.isfinite(v) else float(v) for v in y[::step]]


def _normalize(values: list) -> list:
    finite = [v for v in values if v is not None]
    if not finite:
        return values
    low, high = min(finite), max(finite)
    span = (high - low) or 1.0
    return [None if v is None else (v - low) / span for v in values]


def _stats(values: np.ndarray) -> Tuple[float, float, float]:
    finite = values[np.isfinite(values)]
    return (float(finite.mean()), float(finite.min()), float(finite.max())) if finite.size else (np.nan, np.nan, np.nan)


def _section_figure(title: str, keys: Iterable[str], sin: Dict, sout: Dict) -> Tuple[go.Figure, List[list]]:
    """Purpose: one combined figure per section with Raw/Normalized toggle. Outputs: figure, stat rows."""
    fig, raw_y, norm_y, rows = go.Figure(), [], [], []
    for key in list(keys)[:MAX_TRACES]:
        label = key.split('/', 1)[-1]
        for side, source, dash in (('input', sin, 'solid'), ('output', sout, 'dash')):
            if key not in source:
                continue
            x, y = _thin(_scan_axis(source, key), source[key])
            fig.add_trace(go.Scattergl(x=x, y=y, mode='lines', name=f'{label} ({side})', legendgroup=label,
                                       line={'dash': dash, 'width': 1.4}))
            raw_y.append(y)
            norm_y.append(_normalize(y))
        a, b = _stats(sin.get(key, np.array([]))), _stats(sout.get(key, np.array([])))
        rows.append([label, *a, *b, b[0] - a[0] if np.isfinite(a[0]) and np.isfinite(b[0]) else np.nan])
    fig.update_layout(
        title=title, template='plotly_white', height=520, hovermode='x unified',
        xaxis_title='Scan index', yaxis_title='Value',
        legend={'orientation': 'h', 'y': -0.22, 'font': {'size': 10}},
        margin={'l': 60, 'r': 20, 't': 60, 'b': 40},
        updatemenus=[{'type': 'buttons', 'direction': 'left', 'x': 1, 'xanchor': 'right', 'y': 1.15, 'buttons': [
            {'label': 'Raw', 'method': 'update', 'args': [{'y': raw_y}, {'yaxis.title.text': 'Value'}]},
            {'label': 'Normalized', 'method': 'update', 'args': [{'y': norm_y}, {'yaxis.title.text': 'Normalized (0-1)'}]},
        ]}],
    )
    return fig, rows


def _health_rows(sin: Dict, sout: Dict) -> List[list]:
    """Purpose: UDP stream health = samples, scan range and scan-index skips per stream, input vs output."""
    rows = []
    for key in sorted(k for k in set(sin) | set(sout) if SCAN_RE.search(k)):
        row = [key.split('/')[0]]
        for source in (sin, sout):
            scan = source.get(key)
            if scan is None or not len(scan):
                row += ['-', '-', '-']
                continue
            gaps = np.diff(scan.astype(np.int64)) % 65536  # uint16 rollover safe
            row += [len(scan), f'{int(scan[0])}–{int(scan[-1])}', int(np.sum(gaps > 1))]
        rows.append(row)
    return rows


def _table(headers: List[str], rows: List[list]) -> str:
    fmt = lambda v: f'{v:.4g}' if isinstance(v, float) and np.isfinite(v) else ('-' if isinstance(v, float) else html.escape(str(v)))
    head = ''.join(f'<th>{html.escape(h)}</th>' for h in headers)
    body = ''.join('<tr>' + ''.join(f'<td>{fmt(v)}</td>' for v in row) + '</tr>' for row in rows)
    return f'<div class="tw"><table><thead><tr>{head}</tr></thead><tbody>{body}</tbody></table></div>'


CSS = ('body{font-family:Segoe UI,Arial,sans-serif;margin:0;background:#f4f6f8;color:#1b2733}'
       'header{background:#16324a;color:#fff;padding:18px 28px}header h1{margin:0;font-size:22px}header p{margin:4px 0 0;color:#c8d6e2;font-size:13px}'
       'nav{position:sticky;top:0;background:#fff;border-bottom:1px solid #dde3ea;padding:8px 28px;display:flex;gap:6px;flex-wrap:wrap;z-index:2}'
       'nav a{font-size:12px;color:#0f6b5c;text-decoration:none;border:1px solid #cfe3de;border-radius:14px;padding:3px 10px}'
       'main{max-width:1500px;margin:0 auto;padding:18px 28px}section{background:#fff;border:1px solid #dde3ea;border-radius:12px;padding:16px 18px;margin-bottom:16px}'
       'section h2{margin:0 0 4px;font-size:17px}.story{color:#5f6d7c;font-size:13px;margin:0 0 10px}'
       '.tw{overflow:auto;max-height:340px}table{border-collapse:collapse;width:100%;font-size:12px}th,td{border-bottom:1px solid #eef1f4;padding:5px 8px;text-align:right}'
       'th:first-child,td:first-child{text-align:left}th{background:#f7f9fb;position:sticky;top:0}')


def build_sensor_report(input_hdf: str, output_hdf: str, sensor: str, sin: Dict, sout: Dict, out_dir: str) -> str:
    """Purpose: write one story HTML for a sensor. Outputs: written path."""
    base = os.path.splitext(os.path.basename(input_hdf))[0]
    keys_all = sorted(set(sin) | set(sout))
    used, blocks, nav = set(), [], ['<a href="#health">Stream Health</a>']
    health = _health_rows(sin, sout)
    blocks.append('<section id="health"><h2>UDP Stream Health</h2><p class="story">Samples, scan range and '
                  'scan-index skips per stream. Skips in output but not input point at resim drops.</p>'
                  + _table(['Stream', 'In samples', 'In scan range', 'In skips', 'Out samples', 'Out scan range', 'Out skips'], health) + '</section>')
    first_plot = True
    for index, (title, story, pattern) in enumerate(SECTIONS):
        regex = re.compile(pattern, re.I)
        keys = [k for k in keys_all if k not in used and not SCAN_RE.search(k) and regex.search(k.lower())]
        if not keys:
            continue
        used.update(keys)
        fig, rows = _section_figure(title, keys, sin, sout)
        anchor = f's{index}'
        nav.append(f'<a href="#{anchor}">{html.escape(title)}</a>')
        plot = fig.to_html(full_html=False, include_plotlyjs='cdn' if first_plot else False, config={'displaylogo': False})
        first_plot = False
        blocks.append(f'<section id="{anchor}"><h2>{html.escape(title)}</h2><p class="story">{html.escape(story)} '
                      f'{len(keys)} parameter(s) in one plot; click legend items to isolate, use Normalized to compare shapes.</p>'
                      + plot + _table(['Parameter', 'In mean', 'In min', 'In max', 'Out mean', 'Out min', 'Out max', 'Δ mean'], rows) + '</section>')
    page = (f'<!doctype html><html><head><meta charset="utf-8"><title>{html.escape(base)} {sensor}</title><style>{CSS}</style></head><body>'
            f'<header><h1>Big Script Report · {html.escape(sensor)}</h1><p>{html.escape(base)} — input: {html.escape(input_hdf)} | output: {html.escape(output_hdf)}</p></header>'
            f'<nav>{"".join(nav)}</nav><main>{"".join(blocks)}</main></body></html>')
    os.makedirs(out_dir, exist_ok=True)
    target = os.path.join(out_dir, f'{base}_{sensor}_big_script.html')
    with open(target, 'w', encoding='utf-8') as handle:
        handle.write(page)
    return target


def write_reports(inputs_json: str, output_dir: str) -> List[str]:
    """Purpose: build all sensor story reports for every pair + an index. Outputs: written paths. Never raises."""
    written: List[str] = []
    out_dir = os.path.join(output_dir or 'html', 'big_script')
    try:
        for input_hdf, output_hdf in _pairs(inputs_json):
            sin, sout = _signals(input_hdf), _signals(output_hdf)
            for sensor in sorted(set(sin) | set(sout)):
                written.append(build_sensor_report(input_hdf, output_hdf, sensor, sin.get(sensor, {}), sout.get(sensor, {}), out_dir))
        if written:
            links = ''.join(f'<li><a href="{html.escape(os.path.basename(p))}">{html.escape(os.path.basename(p))}</a></li>' for p in written)
            with open(os.path.join(out_dir, 'index.html'), 'w', encoding='utf-8') as handle:
                handle.write(f'<!doctype html><meta charset="utf-8"><title>Big Script Reports</title><style>{CSS}</style>'
                             f'<header><h1>Big Script Reports</h1></header><main><section><ul>{links}</ul></section></main>')
        master = os.path.join(output_dir or 'html', 'master_index.html')
        if written and os.path.isfile(master):
            page = open(master, encoding='utf-8').read()
            if 'big_script/index.html' not in page and '</body>' in page:
                link = '<p style="font-family:sans-serif;margin:16px"><a href="big_script/index.html">Big Script Report</a></p>'
                open(master, 'w', encoding='utf-8').write(page.replace('</body>', link + '</body>'))
    except Exception as exc:  # report must never break the main interactive plot run
        print(f'[big_script] skipped: {exc}')
    print(f'[big_script] {len(written)} report(s) in {out_dir}')
    return written


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit('Usage: python big_script_report.py <inputs.json> <output_dir>')
    write_reports(sys.argv[1], sys.argv[2])
