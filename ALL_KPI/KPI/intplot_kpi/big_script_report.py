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
from plotly.subplots import make_subplots

# HDF presence shows what this capture contains; it does not prove a stage ran.
PIPELINE_STAGES = [
    ('CDC', r'cdc_stream|/cdc/', 'CDC bin/coverage signals', 'Bin occupancy, range coverage and missing-bin changes.'),
    ('RDD', r'(^|/)rdd_stream(/|$)|(^|/)rdd(/|$)', 'RDD_STREAM', 'Range-Doppler detections, coverage and stage-to-stage loss.'),
    ('Detection', r'detection_stream', 'DETECTION_STREAM', 'Detection counts, scan coverage and spatial distribution.'),
    ('AF', r'af_det|af_diagnostics|af_det_list_property', 'AF_Det / AF_Diagnostics', 'Range, velocity, SNR/RCS, target flags and AF diagnostic rates.'),
    ('Tracker', r'tracker_stream|track_id|trk_id|track_count|num_obj', 'TRACKER_STREAM', 'Track count, continuity, ID changes and position/velocity consistency.'),
]
PIPELINE_CONCEPTS = [
    ('CDC', 'Record volume', r'cdc_stream/.+num_cdc_records|cdc/.+num_cdc_records', 'Records per scan and record-rate shifts.'),
    ('CDC', 'Bin / scan continuity', r'cdc_stream/.+(bin|scan_index)|cdc/.+(bin|scan_index)', 'Missing CDC scans and changes in occupied-bin coverage.'),
    ('RDD', 'Stage-1 detection yield', r'rdd_stream/.+rdd1_num_detect', 'Per-scan RDD1 detection yield and input/output delta.'),
    ('RDD', 'Range–Doppler geometry', r'rdd_stream/.+(rdd2_range|rdd2_range_rate|rdd2_snr)', 'Range/radial-velocity distribution and coverage.'),
    ('Detection', 'AF detections per scan', r'detection_stream/af_det/num_af_det', 'Raw totals and per-scan deltas on shared scan IDs.'),
    ('Detection', 'Input/output scan overlap', r'detection_stream/.*/scan_index', 'Unique scan IDs, common IDs and coverage on each side.'),
    ('AF', 'Detection properties', r'detection_stream/af_det/(ran|range|vel|velocity|snr|rcs|theta|azimuth)', 'Spatial footprint and range/velocity/SNR/RCS distributions.'),
    ('AF', 'Target classes and health', r'detection_stream/(af_det/(f_bistatic|f_single_target|f_superres_target)|af_diagnostics/)', 'Bistatic/single-target/super-resolution rates and saturation/timeout flags.'),
    ('Tracker', 'Track population and state', r'tracker_stream/.+(trkid|track_id|vcs_xposn|vcs_yposn|vcs_xvel|vcs_yvel)', 'Tracks per scan, position/velocity traces and track-life summaries.'),
    ('Tracker', 'Identity continuity', r'tracker_stream/.+(trkid|track_id)', 'ID retention/new/lost tracks and ID-switch candidates across shared scans.'),
]
AF_PROPERTY_RE = re.compile(r'AF_Det/(ran|range|vel|velocity|range_rate|snr|rcs|theta|azimuth|f_bistatic|f_single_target|f_superres_target)$', re.I)
MAX_DETECTION_SAMPLES = 12000

# Remaining telemetry chapters follow the processing story; AF and detection
# properties are rendered below as stage-specific charts instead of one giant plot.
SECTIONS: List[Tuple[str, str, str]] = [
    ('Detection coverage indicators', 'Coverage counters attached to detections. These do not replace the full RDD stream.', r'range_coverage|doppler_coverage|rbin|dbin'),
    ('AF diagnostics', 'AF saturation, timeout and target-filter telemetry.', r'af_diagnostics|af_saturation|af_timeout|f_bistatic|f_single_target|f_superres_target'),
    ('Tracker telemetry', 'Track/object telemetry, when present in the HDF.', r'tracker_stream|track_id|trk_id|track_count|num_obj|underdriv'),
    ('CDC bins', 'CDC bin and coverage telemetry, when present in the HDF.', r'cdc'),
    ('Processing time', 'Per-scan processing time and latency signals.', r'latency|xput|time_spent|module_time|idle|exec_time|duration|cycle_time'),
    ('Host Vehicle Data', 'VSE / ego-motion inputs the tracker relies on.', r'vse|ego|speed|yaw|host|steer|accel'),
    ('Time Sync', 'Dwell timestamps, sync status and jitter.', r'sync|jitter|dwell'),
    ('Alignment', 'Mounting / alignment estimates.', r'align|mount|misalign'),
    ('Faults & Diagnostics', 'Fault bytes, resets, error and timeout counters.', r'fault|reset|error|exception|diag|counter|timeout|saturation|checksum'),
    ('Voltage', 'Supply rails over the log.', r'volt'),
    ('Temperature', 'Thermal sensors over the log.', r'temp'),
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
            # Ignore root-level metadata (e.g. /header/stream_info); it is not
            # sensor telemetry and otherwise creates empty phantom LOG reports.
            if len(parts) < 3:
                return
            sensor, key = parts[0], '/'.join(parts[1:])
            if obj.ndim == 2 and not AF_PROPERTY_RE.search(key):
                return
            with np.errstate(invalid='ignore'):
                values = obj[()].astype(float)
            if values.ndim == 2:
                valid = (values != 0) & np.isfinite(values)
                counts = valid.sum(axis=1)
                sums = np.where(valid, values, 0.0).sum(axis=1)
                means = np.full(values.shape[0], np.nan, dtype=float)
                np.divide(sums, counts, out=means, where=counts > 0)
                values = means
            result.setdefault(sensor, {})[key] = values
        handle.visititems(visit)
    return result


def _lookup_child(group, candidates: Tuple[str, ...]):
    """Purpose: find HDF group/dataset names case-insensitively with known aliases."""
    names = {name.lower(): name for name in group.keys()}
    for candidate in candidates:
        actual = names.get(candidate.lower())
        if actual is not None:
            return group[actual]
    return None


def _detection_properties(path: str) -> Dict[str, Dict]:
    """Load bounded AF detection samples and full-array summary stats per sensor.

    Purpose: support position/velocity/SNR views without embedding the 680-slot
    padded HDF matrices in HTML. Inputs: one UDP HDF5 path. Outputs: compact,
    scan-aligned property samples and exact valid-value stats per sensor.
    """
    result: Dict[str, Dict] = {}
    if not path or not os.path.isfile(path):
        return result
    aliases = {
        'range': ('ran', 'range'), 'theta': ('theta', 'azimuth'),
        'velocity': ('vel', 'velocity', 'range_rate'), 'snr': ('snr',), 'rcs': ('rcs',),
        'bistatic': ('f_bistatic',), 'single_target': ('f_single_target',),
        'superres': ('f_superres_target',),
    }
    with h5py.File(path, 'r') as handle:
        for sensor in handle.keys():
            sensor_group = handle[sensor]
            if not isinstance(sensor_group, h5py.Group):
                continue
            stream = _lookup_child(sensor_group, ('DETECTION_STREAM',))
            af_group = _lookup_child(stream, ('AF_Det',)) if isinstance(stream, h5py.Group) else None
            if not isinstance(af_group, h5py.Group):
                continue
            arrays = {}
            for field, names in aliases.items():
                dataset = _lookup_child(af_group, names)
                if isinstance(dataset, h5py.Dataset) and dataset.dtype.kind in 'iufb' and dataset.ndim in (1, 2):
                    with np.errstate(invalid='ignore'):
                        arrays[field] = np.asarray(dataset[()], dtype=float)
            ranges = arrays.get('range')
            if ranges is None or not ranges.size:
                continue
            valid = np.isfinite(ranges) & (ranges > 0)
            theta = arrays.get('theta')
            if theta is not None and theta.shape == ranges.shape:
                valid &= np.isfinite(theta)
            indices = np.flatnonzero(valid.ravel())
            if not indices.size:
                continue
            if indices.size > MAX_DETECTION_SAMPLES:
                indices = indices[np.linspace(0, indices.size - 1, MAX_DETECTION_SAMPLES, dtype=int)]
            samples, stats = {}, {}
            for field, values in arrays.items():
                if values.shape == ranges.shape:
                    flat_values = values.ravel()
                    field_valid = valid.ravel() & np.isfinite(flat_values)
                    finite = flat_values[np.flatnonzero(field_valid)]
                    sample_indices = indices[np.isfinite(flat_values[indices])]
                    sampled = flat_values[sample_indices]
                else:
                    finite = values[np.isfinite(values)]
                    sampled = finite[np.linspace(0, len(finite) - 1, min(len(finite), MAX_DETECTION_SAMPLES), dtype=int)] if len(finite) else finite
                samples[field] = sampled
                if len(finite):
                    q10, median, q90 = np.percentile(finite, [10, 50, 90])
                    stats[field] = {
                        'n': int(len(finite)), 'mean': float(np.mean(finite)),
                        'p10': float(q10), 'median': float(median), 'p90': float(q90),
                    }
            result[sensor] = {'samples': samples, 'stats': stats}
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
    """Purpose: one combined figure per section with Raw/Normalized toggle. Outputs: figure, stat rows.

    Starts in Normalized view: 20-40 signals with different units on one raw axis
    collapse into unreadable flat lines, which is what made this page look broken.
    Raw is one click away for absolute values.
    """
    traces, raw_y, norm_y, rows = [], [], [], []
    for key in list(keys)[:MAX_TRACES]:
        label = key.split('/', 1)[-1]
        for side, source, dash in (('input', sin, 'solid'), ('output', sout, 'dash')):
            if key not in source:
                continue
            x, y = _thin(_scan_axis(source, key), source[key])
            normalized = _normalize(y)
            traces.append(go.Scattergl(
                x=x, y=normalized, mode='lines', name=f'{label} ({side})',
                legendgroup=label, line={'dash': dash, 'width': 1.4},
            ))
            raw_y.append(y)
            norm_y.append(normalized)
        a, b = _stats(sin.get(key, np.array([]))), _stats(sout.get(key, np.array([])))
        rows.append([label, *a, *b, b[0] - a[0] if np.isfinite(a[0]) and np.isfinite(b[0]) else np.nan])

    fig = go.Figure(data=traces)
    # A 90-entry legend covers the chart; with this many traces hover carries the names.
    show_legend = len(traces) <= 12
    fig.update_layout(
        title=title, template='plotly_white', height=520,
        hovermode='x unified' if show_legend else 'closest',
        xaxis_title='Scan index',
        yaxis_title='Normalized (0-1)' if traces else 'Value',
        showlegend=show_legend,
        legend={'orientation': 'h', 'y': -0.28, 'font': {'size': 10}},
        margin={'l': 60, 'r': 20, 't': 70, 'b': 120 if show_legend else 45},
        updatemenus=[{'type': 'buttons', 'direction': 'left', 'x': 1, 'xanchor': 'right', 'y': 1.14, 'buttons': [
            {'label': 'Normalized', 'method': 'update', 'args': [{'y': norm_y}, {'yaxis.title.text': 'Normalized (0-1)'}]},
            {'label': 'Raw', 'method': 'update', 'args': [{'y': raw_y}, {'yaxis.title.text': 'Value'}]},
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


def _pipeline_rows(sin: Dict, sout: Dict) -> List[tuple]:
    """Purpose: map HDF-observed signals onto ordered radar stages, never infer missing data."""
    rows = []
    for label, pattern, expected, capability in PIPELINE_STAGES:
        regex = re.compile(pattern, re.I)
        in_keys = sorted(key for key in sin if regex.search(key))
        out_keys = sorted(key for key in sout if regex.search(key))
        if in_keys and out_keys:
            state = 'Input + output'
        elif in_keys:
            state = 'Input only'
        elif out_keys:
            state = 'Output only'
        else:
            state = 'Not present'
        rows.append((label, state, len(in_keys), len(out_keys), expected, capability))
    return rows


def _pipeline_html(rows: List[tuple]) -> str:
    """Purpose: render a sequential radar-stage overview with explicit missing-stage states."""
    cards = []
    for index, (stage, state, in_count, out_count, expected, capability) in enumerate(rows):
        css_state = 'present' if state == 'Input + output' else ('partial' if state != 'Not present' else 'missing')
        arrow = '<span class="stage-arrow" aria-hidden="true">→</span>' if index < len(rows) - 1 else ''
        cards.append(
            f'<article class="stage-card {css_state}"><span class="stage-number">{index + 1}</span>'
            f'<h3>{html.escape(stage)}</h3><span class="stage-state">{html.escape(state)}</span>'
            f'<small>signals: input {in_count} · output {out_count}</small>'
            f'<small><b>Expected:</b> {html.escape(expected)}</small>'
            f'<p>{html.escape(capability)}</p></article>{arrow}'
        )
    return '<div class="stage-flow">' + ''.join(cards) + '</div>'


def _figure_html(fig: go.Figure, include_plotlyjs: bool) -> str:
    """Purpose: create responsive, standalone Plotly section markup."""
    return fig.to_html(
        full_html=False,
        include_plotlyjs='inline' if include_plotlyjs else False,
        config={'displaylogo': False, 'responsive': True},
    )


def _spatial_figure(samples_in: Dict, samples_out: Dict, sensor: str) -> go.Figure:
    """Purpose: compare input/output detections in radar top-down coordinates."""
    fig = go.Figure()
    for label, source, color in (('Input', samples_in, '#1677c8'), ('Output', samples_out, '#ed7d31')):
        values = source.get('samples', {})
        ranges, theta = values.get('range'), values.get('theta')
        if ranges is None or theta is None:
            continue
        count = min(len(ranges), len(theta))
        x = ranges[:count] * np.sin(theta[:count])
        y = ranges[:count] * np.cos(theta[:count])
        fig.add_trace(go.Scattergl(
            x=x, y=y, mode='markers', name=f'{label} detections',
            marker={'color': color, 'size': 4, 'opacity': 0.48},
            hovertemplate='Lateral %{x:.1f} m<br>Forward %{y:.1f} m<extra>' + label + '</extra>',
        ))
    fig.update_layout(
        title=f'{sensor} · Detection footprint (top-down)', template='plotly_white',
        height=570, xaxis_title='Lateral position (m) · range × sin(azimuth)',
        yaxis_title='Forward distance (m) · range × cos(azimuth)',
        hovermode='closest', margin={'l': 70, 'r': 25, 't': 65, 'b': 65},
    )
    fig.update_yaxes(scaleanchor='x', scaleratio=1)
    return fig


def _range_velocity_figure(samples_in: Dict, samples_out: Dict, sensor: str) -> go.Figure:
    """Purpose: show range/velocity envelope and output changes without claiming point matching."""
    fig = go.Figure()
    for label, source, color in (('Input', samples_in, '#1677c8'), ('Output', samples_out, '#ed7d31')):
        values = source.get('samples', {})
        ranges, velocity = values.get('range'), values.get('velocity')
        if ranges is None or velocity is None:
            continue
        count = min(len(ranges), len(velocity))
        fig.add_trace(go.Scattergl(
            x=ranges[:count], y=velocity[:count], mode='markers', name=label,
            marker={'color': color, 'size': 4, 'opacity': 0.5},
            hovertemplate='Range %{x:.1f} m<br>Radial velocity %{y:.2f} m/s<extra>' + label + '</extra>',
        ))
    fig.update_layout(
        title=f'{sensor} · Detection range vs radial velocity', template='plotly_white',
        height=480, xaxis_title='Range (m)', yaxis_title='Radial velocity (m/s)',
        hovermode='closest', margin={'l': 65, 'r': 25, 't': 65, 'b': 55},
    )
    return fig


def _property_distribution_figure(samples_in: Dict, samples_out: Dict, sensor: str) -> go.Figure:
    """Purpose: compare input/output distributions for AF detection properties."""
    props = [('range', 'Range (m)'), ('velocity', 'Radial velocity (m/s)'), ('snr', 'SNR'), ('rcs', 'RCS')]
    fig = make_subplots(rows=2, cols=2, subplot_titles=[title for _, title in props])
    for index, (field, title) in enumerate(props):
        row, col = index // 2 + 1, index % 2 + 1
        for label, source, color in (('Input', samples_in, '#1677c8'), ('Output', samples_out, '#ed7d31')):
            values = source.get('samples', {}).get(field)
            if values is not None and len(values):
                fig.add_trace(go.Histogram(
                    x=values, name=label, legendgroup=label, showlegend=(index == 0),
                    marker_color=color, opacity=0.55, nbinsx=45,
                    hovertemplate=f'{title}: %{{x:.3g}}<br>Count: %{{y}}<extra>{label}</extra>',
                ), row=row, col=col)
    fig.update_layout(
        title=f'{sensor} · AF detection property distributions', template='plotly_white',
        height=650, barmode='overlay', margin={'l': 55, 'r': 25, 't': 85, 'b': 45},
        legend={'orientation': 'h', 'y': 1.08},
    )
    return fig


def _count_trend_figure(sin: Dict, sout: Dict, sensor: str) -> go.Figure:
    """Purpose: compare per-scan AF count and mean valid range/velocity/SNR."""
    fields = [
        ('AF_Det/num_af_det', 'AF detections / scan'),
        ('AF_Det/ran', 'Mean range (m)'),
        ('AF_Det/vel', 'Mean radial velocity (m/s)'),
        ('AF_Det/snr', 'Mean SNR'),
    ]
    fig = make_subplots(rows=2, cols=2, subplot_titles=[title for _, title in fields], shared_xaxes=True)
    for index, (suffix, title) in enumerate(fields):
        row, col = index // 2 + 1, index % 2 + 1
        for label, source, color, dash in (('Input', sin, '#1677c8', 'solid'), ('Output', sout, '#ed7d31', 'dash')):
            key = next((name for name in source if name.lower().endswith(suffix.lower())), None)
            if key is None:
                continue
            y = source[key]
            fig.add_trace(go.Scattergl(
                x=_scan_axis(source, key), y=y, mode='lines', name=label,
                legendgroup=label, showlegend=(index == 0),
                line={'color': color, 'dash': dash, 'width': 1.5},
            ), row=row, col=col)
        fig.update_xaxes(title_text='Scan index', row=row, col=col)
    fig.update_layout(
        title=f'{sensor} · Stage progression by scan', template='plotly_white',
        height=640, hovermode='x unified', margin={'l': 60, 'r': 25, 't': 80, 'b': 55},
        legend={'orientation': 'h', 'y': 1.08},
    )
    return fig


def _af_flag_figure(samples_in: Dict, samples_out: Dict, sensor: str) -> go.Figure:
    """Purpose: compare the share of valid detections carrying AF target flags."""
    fields = [('bistatic', 'Bistatic'), ('single_target', 'Single target'), ('superres', 'Super-resolution')]
    fig = go.Figure()
    for label, source, color in (('Input', samples_in, '#1677c8'), ('Output', samples_out, '#ed7d31')):
        stats = source.get('stats', {})
        x, y = [], []
        for field, title in fields:
            if field in stats:
                x.append(title)
                y.append(stats[field]['mean'] * 100)
        if x:
            fig.add_trace(go.Bar(x=x, y=y, name=label, marker_color=color, opacity=0.82))
    fig.update_layout(
        title=f'{sensor} · AF target-flag rate among valid detections', template='plotly_white',
        height=430, barmode='group', yaxis_title='Flagged detections (%)',
        margin={'l': 65, 'r': 25, 't': 65, 'b': 55},
    )
    return fig


def _detection_summary_rows(samples_in: Dict, samples_out: Dict) -> List[list]:
    """Purpose: compact distribution and target-flag comparison table."""
    labels = [
        ('range', 'Range (m)'), ('velocity', 'Radial velocity (m/s)'),
        ('snr', 'SNR'), ('rcs', 'RCS'), ('bistatic', 'Bistatic rate (%)'),
        ('single_target', 'Single-target rate (%)'), ('superres', 'Super-resolution rate (%)'),
    ]
    rows = []
    for key, label in labels:
        a = samples_in.get('stats', {}).get(key)
        b = samples_out.get('stats', {}).get(key)
        if not a and not b:
            continue
        scale = 100.0 if key in {'bistatic', 'single_target', 'superres'} else 1.0
        av = a['mean' if scale > 1 else 'median'] * scale if a else np.nan
        bv = b['mean' if scale > 1 else 'median'] * scale if b else np.nan
        ap90 = a['p90'] * scale if a else np.nan
        bp90 = b['p90'] * scale if b else np.nan
        rows.append([label, a['n'] if a else '-', av, bv, bv - av if np.isfinite(av) and np.isfinite(bv) else np.nan,
                     ap90, bp90])
    return rows


def _count_summary_rows(sin: Dict, sout: Dict) -> List[list]:
    """Purpose: report exact scan/count totals and per-scan count summaries."""
    rows = []
    suffix = 'AF_Det/num_af_det'
    arrays = []
    for source in (sin, sout):
        key = next((name for name in source if name.lower().endswith(suffix.lower())), None)
        arrays.append(np.asarray(source[key], dtype=float) if key else np.array([], dtype=float))
    for label, values in zip(('Input', 'Output'), arrays):
        finite = values[np.isfinite(values)]
        if finite.size:
            rows.append([label, int(finite.size), float(finite.sum()), float(np.median(finite)), float(np.mean(finite))])
        else:
            rows.append([label, '-', '-', np.nan, np.nan])
    return rows


def _scan_overlap(sin: Dict, sout: Dict) -> tuple:
    """Purpose: quantify common detection scan IDs before interpreting file-total deltas."""
    def scan_ids(source: Dict) -> set:
        key = next((name for name in source
                    if name.lower().startswith('detection_stream/') and SCAN_RE.search(name)), None)
        if key is None:
            return set()
        values = np.asarray(source[key]).reshape(-1)
        return {int(value) % 65536 for value in values if np.isfinite(value)}

    in_ids, out_ids = scan_ids(sin), scan_ids(sout)
    common = len(in_ids & out_ids)
    return len(in_ids), len(out_ids), common


def _scan_count_map(source: Dict) -> Dict[int, float]:
    """Purpose: map scan IDs to AF counts, averaging duplicate IDs rather than double-counting."""
    scan_key = next((name for name in source if name.lower().startswith('detection_stream/') and SCAN_RE.search(name)), None)
    count_key = next((name for name in source if name.lower().endswith('af_det/num_af_det')), None)
    if scan_key is None or count_key is None:
        return {}
    scans = np.asarray(source[scan_key]).reshape(-1)
    counts = np.asarray(source[count_key], dtype=float).reshape(-1)
    pairs: Dict[int, List[float]] = {}
    for scan, count in zip(scans, counts):
        if np.isfinite(scan) and np.isfinite(count):
            pairs.setdefault(int(scan) % 65536, []).append(float(count))
    return {scan: float(np.mean(values)) for scan, values in pairs.items()}


def _matched_scan_count_summary(sin: Dict, sout: Dict) -> List[list]:
    """Purpose: quantify AF count differences only on scan IDs shared by both HDFs."""
    in_map, out_map = _scan_count_map(sin), _scan_count_map(sout)
    common = sorted(in_map.keys() & out_map.keys())
    if not common:
        return []
    in_counts = np.asarray([in_map[scan] for scan in common])
    out_counts = np.asarray([out_map[scan] for scan in common])
    delta = out_counts - in_counts
    return [[
        len(common), float(in_counts.sum()), float(out_counts.sum()),
        float(np.mean(delta)), float(np.median(delta)),
        int(np.sum(delta < 0)), int(np.sum(delta > 0)), int(np.sum(delta == 0)),
    ]]


def _pipeline_concept_rows(sin: Dict, sout: Dict) -> List[list]:
    """Purpose: expose stage sub-concepts, found signals and the analysis each enables."""
    rows = []
    for stage, concept, pattern, outcome in PIPELINE_CONCEPTS:
        regex = re.compile(pattern, re.I)
        in_keys = sorted(key for key in sin if regex.search(key))
        out_keys = sorted(key for key in sout if regex.search(key))
        if in_keys and out_keys:
            state = 'Both'
        elif in_keys:
            state = 'Input only'
        elif out_keys:
            state = 'Output only'
        else:
            state = 'Unavailable'
        rows.append([stage, concept, state, ', '.join(sorted(set(in_keys + out_keys))[:3]) or '—', outcome])
    return rows


def _quick_read_html(sin: Dict, sout: Dict, samples_in: Dict, samples_out: Dict, stages: List[tuple]) -> str:
    """Purpose: explain observed differences without asserting causality or KPI pass/fail."""
    rows = _count_summary_rows(sin, sout)
    statements = []
    if isinstance(rows[0][2], (int, float)) and isinstance(rows[1][2], (int, float)):
        in_total, out_total = rows[0][2], rows[1][2]
        delta = out_total - in_total
        pct = (delta / in_total * 100.0) if in_total else np.nan
        pct_text = f' ({pct:+.1f}%)' if np.isfinite(pct) else ''
        statements.append(f'Raw AF count totals are {in_total:,.0f} input and {out_total:,.0f} output ({delta:+,.0f}){pct_text}; this is not a matched-scan loss metric or tracking-accuracy score.')
    in_scans, out_scans, common_scans = _scan_overlap(sin, sout)
    if in_scans or out_scans:
        in_pct = common_scans / in_scans * 100 if in_scans else 0.0
        out_pct = common_scans / out_scans * 100 if out_scans else 0.0
        statements.append(f'DETECTION_STREAM scan overlap: {common_scans:,} common IDs / {in_scans:,} input and {out_scans:,} output unique IDs ({in_pct:.1f}% / {out_pct:.1f}% coverage). Interpret raw totals cautiously when scan sets differ.')
    matched = _matched_scan_count_summary(sin, sout)
    if matched:
        row = matched[0]
        statements.append(f'On those {row[0]:,} shared scans, AF count mean delta is {row[3]:+.2f}/scan (median {row[4]:+.2f}); output is lower/higher/equal on {row[5]}/{row[6]}/{row[7]} scans.')
    for field, label in (('range', 'median range'), ('velocity', 'median radial velocity'), ('snr', 'median SNR')):
        a = samples_in.get('stats', {}).get(field)
        b = samples_out.get('stats', {}).get(field)
        if a and b and np.isfinite(a['median']) and np.isfinite(b['median']):
            delta = b['median'] - a['median']
            statements.append(f'{label}: {a["median"]:.3g} input → {b["median"]:.3g} output (Δ {delta:+.3g}).')
    missing = [stage for stage, state, *_ in stages if state == 'Not present']
    if missing:
        statements.append('Cannot attribute downstream effects to absent HDF stages: ' + ', '.join(missing) + '.')
    if not statements:
        statements.append('The pair has insufficient paired AF metrics for a numeric quick read; use the stage cards and signal tables below.')
    return '<ul class="quick-read">' + ''.join(f'<li>{html.escape(item)}</li>' for item in statements) + '</ul>'


CSS = ('body{font-family:Segoe UI,Arial,sans-serif;margin:0;background:#f4f6f8;color:#1b2733}'
       'header{background:#16324a;color:#fff;padding:18px 28px}header h1{margin:0;font-size:22px}header p{margin:4px 0 0;color:#c8d6e2;font-size:13px;overflow-wrap:anywhere}'
       'nav{position:sticky;top:0;background:#fff;border-bottom:1px solid #dde3ea;padding:8px 28px;display:flex;gap:6px;flex-wrap:wrap;z-index:2}'
       'nav a{font-size:12px;color:#0f6b5c;text-decoration:none;border:1px solid #cfe3de;border-radius:14px;padding:3px 10px}'
       'main{max-width:1500px;margin:0 auto;padding:18px 28px}section{background:#fff;border:1px solid #dde3ea;border-radius:12px;padding:16px 18px;margin-bottom:16px}'
       'section h2{margin:0 0 4px;font-size:18px}.story{color:#5f6d7c;font-size:13px;margin:0 0 10px;max-width:1100px}'
       '.kpis{display:grid;grid-template-columns:repeat(auto-fit,minmax(170px,1fr));gap:10px;margin:12px 0}.kpi{border:1px solid #dce5ec;background:#f8fbfd;border-radius:9px;padding:12px}.kpi b{display:block;font-size:21px;color:#174e68}.kpi span{font-size:11px;color:#607181}'
       '.quick-read{margin:8px 0 0;padding-left:20px;color:#344b5b;font-size:13px}.quick-read li{margin:5px 0}'
       '.stage-flow{display:flex;align-items:stretch;gap:7px;overflow-x:auto;padding:8px 0 14px}.stage-card{min-width:190px;max-width:240px;flex:1;border:1px solid #d6e0e7;border-top:4px solid #92a1ad;border-radius:10px;padding:12px;background:#fafcfd}.stage-card.present{border-top-color:#22865a}.stage-card.partial{border-top-color:#d39a28}.stage-card.missing{border-top-color:#c45252;background:#fffafa}.stage-card h3{margin:4px 0 7px;font-size:16px}.stage-state{display:inline-block;font-size:12px;font-weight:700}.stage-card b{font-size:11px}.stage-card small{display:block;color:#526373;margin-top:5px}.stage-card p{font-size:11px;color:#5e6f7e;margin:8px 0 0}.stage-number{display:inline-grid;place-items:center;width:22px;height:22px;border-radius:50%;background:#e5edf2;color:#23495e;font-size:12px;font-weight:bold}.stage-arrow{align-self:center;color:#8da0ad;font-size:23px}.plot-grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(420px,1fr));gap:12px}.plot-card{min-width:0;max-width:100%;overflow:hidden;border:1px solid #e3e9ee;border-radius:8px;padding:5px}.notice{padding:10px 12px;border-left:4px solid #d49a23;background:#fff8e9;color:#57471f;font-size:13px;margin:10px 0}'
       '.tw{display:block;width:100%;max-width:100%;overflow-x:auto;overflow-y:auto;max-height:340px}table{border-collapse:collapse;width:100%;font-size:12px}th,td{border-bottom:1px solid #eef1f4;padding:5px 8px;text-align:right}'
       'th:first-child,td:first-child{text-align:left}th{background:#f7f9fb;position:sticky;top:0}@media(max-width:700px){main{padding:10px}.plot-grid{grid-template-columns:1fr}.stage-card{min-width:175px}}')


def build_sensor_report(input_hdf: str, output_hdf: str, sensor: str, sin: Dict, sout: Dict,
                        samples_in: Dict, samples_out: Dict, out_dir: str) -> str:
    """Purpose: write a sequential, evidence-based radar pipeline story per sensor."""
    base = os.path.splitext(os.path.basename(input_hdf))[0]
    keys_all = sorted(set(sin) | set(sout))
    used = {key for key in keys_all if AF_PROPERTY_RE.search(key) or key.lower().endswith('af_det/num_af_det')}
    stages = _pipeline_rows(sin, sout)
    present = sum(state == 'Input + output' for _, state, *_ in stages)
    count_rows = _count_summary_rows(sin, sout)
    valid_in = samples_in.get('stats', {}).get('range', {}).get('n', 0)
    valid_out = samples_out.get('stats', {}).get('range', {}).get('n', 0)
    def card_value(row_index: int, column: int) -> str:
        value = count_rows[row_index][column]
        return f'{value:,.0f}' if isinstance(value, (int, float, np.integer, np.floating)) and np.isfinite(value) else '—'

    has_valid_in = 'range' in samples_in.get('stats', {})
    has_valid_out = 'range' in samples_out.get('stats', {})
    valid_card = f'{valid_in:,}' if has_valid_in else '—'
    valid_card += f' / {valid_out:,}' if has_valid_out else ' / —'
    count_cards = (
        f'<div class="kpis"><div class="kpi"><b>{card_value(0, 1)}</b><span>Input scans with AF counts</span></div>'
        f'<div class="kpi"><b>{card_value(1, 1)}</b><span>Output scans with AF counts</span></div>'
        f'<div class="kpi"><b>{card_value(0, 2)}</b><span>Input AF detections</span></div>'
        f'<div class="kpi"><b>{card_value(1, 2)}</b><span>Output AF detections</span></div>'
        f'<div class="kpi"><b>{valid_card}</b><span>Valid range samples · input / output</span></div></div>'
    )
    blocks, nav = [], ['<a href="#pipeline">Pipeline stages</a>', '<a href="#counts">Detection counts</a>',
                       '<a href="#footprint">Detection footprint</a>', '<a href="#properties">AF properties</a>']
    blocks.append(
        '<section id="pipeline"><h2>Radar processing story</h2>'
        f'<p class="story">Read left to right: CDC → RDD → detection stream → AF detections → tracker. '
        f'{present} of {len(stages)} stages have signals in both files.</p>{_pipeline_html(stages)}'
        f'<h3>Quick read</h3>{_quick_read_html(sin, sout, samples_in, samples_out, stages)}'
        '<h3>Sub-concepts covered by each stage</h3>'
        + _table(['Stage', 'Sub-concept', 'HDF availability', 'Signals found', 'What this enables'], _pipeline_concept_rows(sin, sout))
        + '<div class="notice">Stage cards report HDF signal presence, not proof that a stage executed. '
        'A missing stage means this pair cannot answer its questions; it is not treated as zero.</div></section>'
    )
    first_plot = True

    def add_plot_section(anchor: str, title: str, story: str, figures: List[go.Figure], table: str = ''):
        nonlocal first_plot
        nav.append(f'<a href="#{anchor}">{html.escape(title)}</a>')
        plots = ''.join(
            f'<div class="plot-card">{_figure_html(fig, first_plot and i == 0)}</div>'
            for i, fig in enumerate(figures)
        )
        if figures:
            first_plot = False
        blocks.append(
            f'<section id="{anchor}"><h2>{html.escape(title)}</h2><p class="story">{html.escape(story)}</p>'
            f'<div class="plot-grid">{plots}</div>{table}</section>'
        )

    matched_count_rows = _matched_scan_count_summary(sin, sout)
    matched_count_table = (
        '<h3>Shared-scan comparison</h3>' + _table(
            ['Common scans', 'Input detections', 'Output detections', 'Mean Δ / scan', 'Median Δ / scan', 'Output lower', 'Output higher', 'Equal'],
            matched_count_rows,
        )
        if matched_count_rows else
        '<p class="notice">No common scan IDs with AF count data; use raw totals only as separate-file summaries.</p>'
    )
    add_plot_section(
        'counts', '1 · Detection volume by scan',
        'Start with AF detections per scan. Exact totals come from num_af_det; property trends are per-scan means, not point matches.',
        [_count_trend_figure(sin, sout, sensor)],
        _table(['Side', 'Counted scans', 'Total AF detections', 'Median detections/scan', 'Mean detections/scan'], count_rows)
        + matched_count_table,
    )

    spatial = _spatial_figure(samples_in, samples_out, sensor)
    range_velocity = _range_velocity_figure(samples_in, samples_out, sensor)
    has_spatial = any(trace.x is not None and len(trace.x) for trace in spatial.data)
    has_range_velocity = any(trace.x is not None and len(trace.x) for trace in range_velocity.data)
    if has_spatial or has_range_velocity:
        add_plot_section(
            'footprint', '2 · Where detections occur',
            'Top-down coordinates use lateral = range × sin(azimuth) and forward = range × cos(azimuth). '
            'The range/velocity cloud compares distributions; detections are bounded, deterministically sampled and not paired one-to-one.',
            [fig for fig, available in ((spatial, has_spatial), (range_velocity, has_range_velocity)) if available],
        )

    property_rows = _detection_summary_rows(samples_in, samples_out)
    if property_rows:
        add_plot_section(
            'properties', '3 · AF detection quality and target mix',
            'Compare range, radial velocity, SNR and RCS distributions, then the bistatic/single-target/super-resolution rates. '
            'Table statistics use all valid HDF values; charts are thinned for browser performance.',
            [_property_distribution_figure(samples_in, samples_out, sensor), _af_flag_figure(samples_in, samples_out, sensor)],
            _table(['Property', 'Valid samples', 'Input median / rate', 'Output median / rate', 'Δ median / rate', 'Input p90', 'Output p90'], property_rows),
        )

    chapter = 4
    for index, (title, story, pattern) in enumerate(SECTIONS):
        regex = re.compile(pattern, re.I)
        keys = [key for key in keys_all if key not in used and not SCAN_RE.search(key) and regex.search(key.lower())]
        if not keys:
            continue
        used.update(keys)
        fig, rows = _section_figure(title, keys, sin, sout)
        add_plot_section(
            f's{index}', f'{chapter} · {title}',
            f'{story} {len(keys)} parameter(s). Click legend items to isolate signals; normalized view is used for mixed units.',
            [fig],
            _table(['Parameter', 'In mean', 'In min', 'In max', 'Out mean', 'Out min', 'Out max', 'Δ mean'], rows),
        )
        chapter += 1

    nav.append('<a href="#health">Stream health</a>')
    blocks.append(
        '<section id="health"><h2>Final · Stream continuity and scan health</h2>'
        '<p class="story">Scan-index skips and sample counts are summarized independently for each stream. '
        'A missing input/output stream is not counted as a zero.</p>'
        + _table(['Stream', 'In samples', 'In scan range', 'In skips', 'Out samples', 'Out scan range', 'Out skips'], _health_rows(sin, sout))
        + '</section>'
    )
    page = (
        f'<!doctype html><html><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">'
        f'<title>Radar Pipeline Analysis · {html.escape(base)} · {html.escape(sensor)}</title><style>{CSS}</style></head><body>'
        f'<header><h1>Radar Pipeline Analysis · {html.escape(sensor)}</h1>'
        f'<p>{html.escape(base)} · reference/input: {html.escape(input_hdf)} · replay/output: {html.escape(output_hdf)}</p>{count_cards}</header>'
        f'<nav>{"".join(nav)}</nav><main>{"".join(blocks)}</main></body></html>'
    )
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
            samples_in = _detection_properties(input_hdf)
            samples_out = _detection_properties(output_hdf)
            for sensor in sorted(set(sin) | set(sout)):
                written.append(build_sensor_report(
                    input_hdf, output_hdf, sensor, sin.get(sensor, {}), sout.get(sensor, {}),
                    samples_in.get(sensor, {}), samples_out.get(sensor, {}), out_dir,
                ))
        if written:
            links = ''.join(f'<li><a href="{html.escape(os.path.basename(p))}">{html.escape(os.path.basename(p))}</a></li>' for p in written)
            with open(os.path.join(out_dir, 'index.html'), 'w', encoding='utf-8') as handle:
                handle.write(f'<!doctype html><meta charset="utf-8"><title>Big Script Reports</title><style>{CSS}</style>'
                             f'<header><h1>Radar Pipeline Reports</h1><p>Open a sensor report, read the CDC → RDD → Detection → AF → Tracker stage cards, then follow the plots in order. Missing stages are explicitly marked.</p></header>'
                             f'<main><section><h2>Sensor reports</h2><ul>{links}</ul></section></main>')
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
