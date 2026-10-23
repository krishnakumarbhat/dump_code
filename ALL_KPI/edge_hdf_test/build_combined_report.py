"""Build ONE combined HTML report from every edge_hdf HDF pair.

Runs all four KPI paths over the whole edge_hdf corpus:
  * can_kpi          (can_interactive_plot/a_persistence_layer + c_business_layer)
  * udp_kpi          (UDP_KPI/a_persistence_layer + c_business_layer)
  * intplot_kpi      (intplot_kpi/ResimHTMLReport.py)
  * can_interactive  (can_interactive_plot/can_intplot_main.py)

and emits a SINGLE self-contained HTML (like the research-benchmark master
page) that is easy to hand to another AI.

Usage:  python build_combined_report.py [--max-points N] [--skip-plots]
"""
from __future__ import annotations

import argparse
import base64
import json
import os
import re
import shutil
import subprocess
import sys
import time
from typing import Any, Dict, List, Optional, Tuple

HERE = os.path.dirname(os.path.abspath(__file__))
KPI_DIR = os.path.abspath(os.path.join(HERE, "..", "KPI"))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
EDGE = os.path.join(REPO, "edge_hdf")
OUT = os.path.join(HERE, "combined")
DESKTOP_OUT = r"C:\Users\ouymc2\Desktop\KPI_Combined_Report.html"

# (X, Y) pairings that go into the combined plot config.
XY_PAIRS = [
    dict(plot_id="range_vs_doppler", x_signal={"name": "vel"}, y_signal={"name": "ran"},
         title="Range vs Radial Velocity",
         x_label="Radial Velocity (m/s)", y_label="Distance (m)"),
    dict(plot_id="range_vs_azimuth", x_signal={"name": "theta"}, y_signal={"name": "ran"},
         title="Range vs Azimuth (bird's eye)",
         x_label="Azimuth (deg)", y_label="Distance (m)"),
    dict(plot_id="velocity_vs_elevation", x_signal={"name": "phi"}, y_signal={"name": "vel"},
         title="Radial Velocity vs Elevation",
         x_label="Elevation (deg)", y_label="Radial Velocity (m/s)"),
]
XY_OWNER = {"ran": ["range_vs_doppler", "range_vs_azimuth"],
            "vel": ["velocity_vs_elevation"]}

# The signals whose standard scan-index plot is also worth keeping.
KEEP_PLOT_TYPES = {"scatter_plot", "histogram_with_count"}


# --------------------------------------------------------------------------
# pair discovery
# --------------------------------------------------------------------------

def _norm(stem: str) -> str:
    """Normalise a file stem so input/output variants compare equal."""
    s = stem
    s = re.sub(r"\s*\(\d+\)$", "", s)                  # browser " (2)" suffix
    s = re.sub(r"\s+\d+$", "", s)                      # browser " 1" suffix
    s = re.sub(r"_rR\d+", "", s, flags=re.I)           # resim token
    s = re.sub(r"_r\d{6,}", "", s, flags=re.I)
    s = re.sub(r"_HDF$", "", s, flags=re.I)
    s = re.sub(r"_input$", "", s, flags=re.I)
    s = re.sub(r"_output$", "", s, flags=re.I)
    s = re.sub(r"_formatted$", "", s, flags=re.I)
    s = re.sub(r"_cdc$", "", s, flags=re.I)
    s = re.sub(r"_out$", "", s, flags=re.I)
    s = re.sub(r"[\s_]+", "_", s)
    return s.lower()


def _slot(path: str, stem: str) -> str:
    """Decide whether a file is the input or the output side of a pair."""
    parent = os.path.basename(os.path.dirname(path)).lower()
    if parent == "input":
        return "input"
    if parent == "output":
        return "output"
    if re.search(r"_rR?\d+", stem, re.I):
        return "input"
    if stem.lower().endswith("_input") or stem.lower() == "input":
        return "input"
    if stem.lower().endswith("_output") or stem.lower() == "output":
        return "output"
    return "output"


def _bucket(path: str) -> str:
    """Files under <x>/input and <x>/output belong to the same bucket <x>."""
    d = os.path.dirname(path)
    parent = os.path.basename(d).lower()
    if parent in ("input", "output"):
        d = os.path.dirname(d)
    rel = os.path.relpath(d, EDGE)
    return "root" if rel == "." else rel.replace(os.sep, "/")


def discover_pairs() -> List[Dict[str, Any]]:
    """Find every input/output HDF pair in edge_hdf."""
    table: Dict[Tuple[str, str], Dict[str, List[str]]] = {}
    for dp, dn, fn in os.walk(EDGE):
        for f in fn:
            if not f.endswith(".h5"):
                continue
            full = os.path.join(dp, f)
            key = (_bucket(full), _norm(f[:-3]))
            slot = _slot(full, f[:-3])
            table.setdefault(key, {"input": [], "output": []})[slot].append(full)

    pairs: List[Dict[str, Any]] = []
    for (bucket, key), sides in sorted(table.items()):
        ins = sorted(sides["input"])
        outs = sorted(sides["output"])
        n = min(len(ins), len(outs))
        for i in range(n):
            pairs.append({"bucket": bucket, "key": key, "input": ins[i], "output": outs[i],
                          "note": ""})
        for extra in ins[n:] + outs[n:]:
            pairs.append({"bucket": bucket, "key": key, "input": extra, "output": None,
                          "note": "no counterpart found"})
    return pairs


def classify(path: str) -> str:
    """'can' | 'udp' | 'unknown' from the HDF top-level group names."""
    try:
        import h5py
        with h5py.File(path, "r") as f:
            tops = [k for k in f.keys() if isinstance(f[k], h5py.Group)]
    except Exception:
        return "unknown"
    joined = " ".join(tops).upper()
    if any(k in joined for k in ("CEER", "MCIP")):
        return "can"
    if any(k in joined for k in ("FL", "FR", "RL", "RR", "FC", "SENSOR")):
        return "udp"
    return "unknown"


# --------------------------------------------------------------------------
# plot config (kept small so the combined report stays shareable)
# --------------------------------------------------------------------------

def build_plot_config(pkg_dir: str, out_json: str) -> str:
    sys.path.insert(0, pkg_dir)
    try:
        from InteractivePlot.c_data_storage.config_storage import Gen7V1_V2
        cfg = json.loads(json.dumps(Gen7V1_V2))
    finally:
        if pkg_dir in sys.path:
            sys.path.remove(pkg_dir)
        for m in list(sys.modules):
            if m.startswith("InteractivePlot"):
                del sys.modules[m]
    for stream_name, stream_cfg in list(cfg.items()):
        if not isinstance(stream_cfg, dict):
            continue
        if "ran" not in stream_cfg or "vel" not in stream_cfg:
            continue
        for signal, ids in XY_OWNER.items():
            if signal not in stream_cfg:
                continue
            entry = stream_cfg[signal]
            pts = [p for p in entry.get("plot_types", []) if p in KEEP_PLOT_TYPES]
            pts.append("plot_xy_correlation")
            entry["plot_types"] = pts
            entry["xy_plots"] = [p for p in XY_PAIRS if p["plot_id"] in ids]
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump({"Gen7V1_V2": cfg}, f, indent=1)
    return out_json


def build_xml(pkg_dir: str, out_xml: str) -> str:
    src = os.path.join(pkg_dir, "ConfigInteractivePlots.xml")
    s = open(src, encoding="utf-8", errors="ignore").read()
    s = re.sub(r"<KPI>1</KPI>", "<KPI>0</KPI>", s)
    s = re.sub(r"<RAG_DATA_TEXT>1</RAG_DATA_TEXT>", "<RAG_DATA_TEXT>0</RAG_DATA_TEXT>", s)
    with open(out_xml, "w", encoding="utf-8") as f:
        f.write(s)
    return out_xml


# --------------------------------------------------------------------------
# figure extraction
# --------------------------------------------------------------------------

def _balanced(text: str, start: int, open_ch: str, close_ch: str):
    depth = 0
    in_str = False
    esc = False
    for i in range(start, len(text)):
        ch = text[i]
        if in_str:
            if esc:
                esc = False
            elif ch == "\\":
                esc = True
            elif ch == '"':
                in_str = False
            continue
        if ch == '"':
            in_str = True
        elif ch == open_ch:
            depth += 1
        elif ch == close_ch:
            depth -= 1
            if depth == 0:
                return text[start:i + 1], i + 1
    return None, len(text)


def _decode(v):
    if isinstance(v, dict) and "bdata" in v:
        raw = base64.b64decode(v["bdata"])
        import numpy as np
        arr = np.frombuffer(raw, dtype=np.dtype(v.get("dtype", "f8")))
        shape = v.get("shape")
        if shape:
            try:
                arr = arr.reshape(shape)
            except Exception:
                pass
        return np.asarray(arr).ravel().tolist()
    return v if isinstance(v, list) else []


def _downsample(arr, n: int):
    if not isinstance(arr, list) or len(arr) <= n:
        return arr
    step = len(arr) / float(n)
    return [arr[int(i * step)] for i in range(n)]


def extract_figures(html_path: str, max_points: int) -> List[Dict[str, Any]]:
    """Pull the (X, Y) figures out of a generated report, downsampled."""
    s = open(html_path, encoding="utf-8", errors="ignore").read()
    out: List[Dict[str, Any]] = []
    idx = 0
    while True:
        m = s.find("Plotly.newPlot(", idx)
        if m < 0:
            break
        p = m + len("Plotly.newPlot(")
        while p < len(s) and s[p] in " \t\r\n":
            p += 1
        fid = "?"
        if p < len(s) and s[p] == '"':
            q = s.index('"', p + 1)
            fid = s[p + 1:q]
            p = q + 1
        while p < len(s) and s[p] in " \t\r\n,":
            p += 1
        data_s, p = _balanced(s, p, "[", "]")
        while p < len(s) and s[p] in " \t\r\n,":
            p += 1
        layout_s, p = _balanced(s, p, "{", "}")
        if not data_s or not layout_s:
            idx = m + 1
            continue
        try:
            data = json.loads(data_s)
            layout = json.loads(layout_s)
        except Exception:
            idx = m + 1
            continue
        t = layout.get("title") or {}
        title = t.get("text", "") if isinstance(t, dict) else str(t)
        if "X, Y" not in str(title):
            idx = m + 1
            continue
        for tr in data:
            for k in ("x", "y"):
                tr[k] = _downsample(_decode(tr.get(k)), max_points)
        out.append({"title": title, "data": data, "layout": layout})
        idx = m + 1
    return out


# --------------------------------------------------------------------------
# runners
# --------------------------------------------------------------------------

def run_kpi_worker(kind: str, pair: Dict[str, Any], outdir: str, label: str) -> Dict[str, Any]:
    """Run the CAN or UDP KPI on one pair (separate process: module-name clash)."""
    cmd = [sys.executable, os.path.join(HERE, "_kpi_worker.py"), kind,
           pair["input"], pair["output"], outdir, label]
    try:
        subprocess.run(cmd, capture_output=True, text=True, timeout=3600, cwd=HERE)
    except subprocess.TimeoutExpired:
        return {"error": "timeout"}
    jf = os.path.join(outdir, label + ".json")
    if not os.path.exists(jf):
        return {"error": "worker produced no output"}
    with open(jf, encoding="utf-8") as f:
        return json.load(f)


def run_interactive(pkg: str, entry: str, pairs: List[Dict[str, Any]],
                    plot_cfg: str, outdir: str) -> Dict[str, Any]:
    """Run an interactive-plot CLI over a list of pairs, then harvest figures."""
    pkg_dir = os.path.join(KPI_DIR, pkg)
    xml = build_xml(pkg_dir, os.path.join(outdir, "_config.xml"))
    inputs = os.path.join(outdir, "_inputs.json")
    with open(inputs, "w", encoding="utf-8") as f:
        json.dump({"INPUT_HDF": [p["input"] for p in pairs],
                   "OUTPUT_HDF": [p["output"] for p in pairs]}, f, indent=1)
    if os.path.isdir(outdir):
        for dp, dn, fn in os.walk(outdir):
            for f in fn:
                if f.endswith(".html"):
                    os.remove(os.path.join(dp, f))
    cmd = [sys.executable, entry, xml, inputs, outdir, plot_cfg]
    t0 = time.time()
    try:
        proc = subprocess.run(cmd, cwd=pkg_dir, capture_output=True, text=True, timeout=7200)
        rc = proc.returncode
        tail = (proc.stdout or "")[-1500:] + (proc.stderr or "")[-1500:]
    except subprocess.TimeoutExpired:
        rc, tail = -1, "timeout"
    return {"cmd": " ".join(cmd), "rc": rc, "elapsed_s": time.time() - t0, "tail": tail}


# --------------------------------------------------------------------------
# KPI metric summarising
# --------------------------------------------------------------------------

def _scalar(v) -> Optional[float]:
    try:
        import numpy as np
        if isinstance(v, (int, float, np.integer, np.floating)):
            return float(v)
        if isinstance(v, (list, tuple, np.ndarray)) and len(v):
            a = np.asarray(v, dtype=float)
            a = a[np.isfinite(a)]
            return float(a.mean()) if a.size else None
    except Exception:
        return None
    return None


PRIORITY_COLS = [
    "accuracy", "detection_accuracy_percentage", "precision", "recall", "f1",
    "jaccard", "jaccard_pct", "overall", "scan_match_pct", "input_match_pct",
    "output_match_pct", "min_accuracy", "max_accuracy", "scans_processed",
    "num_scans", "total_matches", "total_detections", "input_total",
    "common_count", "total_fp", "total_fn", "total_input_tracks",
    "total_output_tracks", "id_common", "id_union", "fmoving_agreement_pct",
    "matches", "denominator", "numerator",
]


def _flatten(d: Any, prefix: str = "") -> Dict[str, float]:
    """Flatten a KPI result dict into {dotted.path: number}."""
    out: Dict[str, float] = {}
    if not isinstance(d, dict):
        return out
    for k, v in d.items():
        if k.startswith("per_") or k == "per_scan":
            continue
        if k == "scan":
            continue          # per-scan INDEX array - its mean is meaningless
        path = f"{prefix}{k}"
        if isinstance(v, dict):
            out.update(_flatten(v, path + "."))
            continue
        sv = _scalar(v)
        if sv is not None:
            out[path] = sv
    return out


def summarise_kpi(metrics: Dict[str, Any]) -> List[Dict[str, Any]]:
    """Flatten a KPI result dict into summary rows."""
    rows: List[Dict[str, Any]] = []

    def add(scope, kpi, m):
        flat = _flatten(m)
        if not flat:
            return
        row = {"scope": scope, "kpi": kpi}
        row.update(flat)
        rows.append(row)

    per_sensor = metrics.get("per_sensor") or {}
    for sensor, m in per_sensor.items():
        if not isinstance(m, dict):
            continue
        for kpi in ("alignment", "detection", "tracker"):
            add(sensor, kpi, m.get(kpi))

    for sensor, m in metrics.items():
        if sensor.startswith("_") or not isinstance(m, dict):
            continue
        if "per_signal" in m:
            row = {"scope": sensor, "kpi": "can_kpi"}
            row.update({k: v for k, v in _flatten(m).items() if not k.startswith("scan.")})
            for sig, arr in (m.get("per_signal") or {}).items():
                sv = _scalar(arr)
                if sv is not None:
                    row[f"sig_{sig}"] = sv
            rows.append(row)
    return rows


# --------------------------------------------------------------------------
# HTML
# --------------------------------------------------------------------------

CSS = """
:root{--bg:#0b1020;--panel:#141a30;--line:#253056;--fg:#e8ecf8;--mut:#93a0c4;
 --ok:#2ecc71;--bad:#e74c3c;--base:#e67e22;--after:#3498db;--accent:#58a6ff}
*{box-sizing:border-box}
body{margin:0;background:var(--bg);color:var(--fg);
 font-family:"Segoe UI",system-ui,-apple-system,sans-serif;font-size:14px;line-height:1.5}
header{padding:26px 32px;background:linear-gradient(135deg,#0d1330,#1b2a55);border-bottom:1px solid var(--line)}
h1{margin:0 0 6px;font-size:24px}
.sub{color:var(--mut);font-size:13.5px;max-width:1200px}
.wrap{max-width:1600px;margin:0 auto;padding:20px 26px 80px}
h2{font-size:18px;margin:30px 0 10px;padding-bottom:6px;border-bottom:1px solid var(--line)}
h3{font-size:15px;margin:20px 0 8px;color:#c9d6e8}
table{width:100%;border-collapse:collapse;font-size:12.5px;margin:8px 0}
th,td{border:1px solid var(--line);padding:6px 9px;text-align:left;vertical-align:top}
th{background:#1a2240;font-weight:600;position:sticky;top:0}
tr:nth-child(even) td{background:#10162b}
code{background:#0e1428;padding:1px 4px;border-radius:3px;color:#9ecbff;font-size:12px}
.card{background:var(--panel);border:1px solid var(--line);border-radius:10px;padding:16px 18px;margin:14px 0}
.meta{display:flex;gap:24px;flex-wrap:wrap;margin-top:14px;font-size:12.5px;color:var(--mut)}
.meta b{color:var(--fg)}
.pill{display:inline-block;background:#243044;border-radius:10px;padding:2px 9px;font-size:11.5px;
 margin:2px 4px 2px 0;color:#c9d6e8}
.ok{color:var(--ok)}.bad{color:var(--bad)}
.kpiblock{background:#0e1428;border:1px solid var(--line);border-radius:8px;padding:10px 12px;margin:8px 0;overflow-x:auto}
.kpiblock h4{margin:2px 0 8px;color:#9ecbff;font-size:13px}
.kpiblock table{font-size:11.5px}
.kpiblock .kpi-section{margin:0}
.kpiblock .kpi-summary{background:#111a33;padding:10px;border-radius:6px;margin:6px 0}
.kpiblock .kpi-summary p{margin:4px 0}
.kpiblock ul{margin-left:18px}
.kpiblock li{margin:2px 0}
.kpiblock details{background:#0a1020;border:1px solid var(--line);border-radius:6px;padding:8px 10px}
.kpiblock summary{color:#9ecbff}
.plot{width:100%;height:520px}
.small{font-size:12px;color:var(--mut)}
details{margin:8px 0}summary{cursor:pointer;font-weight:600}
"""


def build_html(sections: List[Dict[str, Any]], summary_rows: List[Dict[str, Any]],
               meta: Dict[str, Any], out_path: str) -> str:
    e = html_escape = __import__("html").escape
    parts: List[str] = []
    parts.append(f"""<!DOCTYPE html><html lang="en"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>KPI Combined Report - edge_hdf</title>
<script src="https://cdn.plot.ly/plotly-2.35.2.min.js" charset="utf-8"></script>
<style>{CSS}</style></head><body>
<header>
<h1>APRISM KPI &mdash; Combined edge_hdf Report</h1>
<div class="sub">One self-contained page: every KPI path over every HDF pair in <code>edge_hdf/</code>
&mdash; <b>can_kpi</b>, <b>udp_kpi</b>, <b>intplot_kpi</b> and <b>can_interactive</b>.
All (X, Y) plots use a real signal on the X axis (range / velocity / azimuth / elevation),
never <code>scan_index</code>. Every number is measured by the production code.</div>
<div class="meta">
<div>pairs: <b>{meta['pairs']}</b></div><div>can_kpi: <b>{meta['can_kpi']}</b></div>
<div>udp_kpi: <b>{meta['udp_kpi']}</b></div><div>intplot: <b>{meta['intplot']}</b></div>
<div>can_interactive: <b>{meta['can_int']}</b></div>
<div>XY figures: <b>{meta['figures']}</b></div><div>generated: <b>{meta['generated']}</b></div>
</div></header><div class="wrap">
""")

    # ---- summary table ----
    parts.append("<h2>1. KPI summary</h2><div class=\"card\">")
    if summary_rows:
        present = set()
        for r in summary_rows:
            present.update(r.keys())
        cols = [c for c in PRIORITY_COLS if c in present]
        extra = sorted(present - set(cols) - {"file", "scope", "kpi"})
        sig_cols = [c for c in extra if c.startswith("sig_")]
        other_cols = [c for c in extra if not c.startswith("sig_")][:10]
        cols = cols + sig_cols + other_cols
        # drop columns that are empty in EVERY row (CAN and UDP expose
        # different metric keys; an all-empty union column is just noise)
        cols = [c for c in cols if any(r.get(c, "") not in ("", None) for r in summary_rows)]
        parts.append("<table><thead><tr><th>file</th><th>scope</th><th>KPI</th>"
                     + "".join(f"<th>{html_escape(c)}</th>" for c in cols) + "</tr></thead><tbody>")
        for r in summary_rows:
            cells = ""
            for c in cols:
                v = r.get(c, "")
                if isinstance(v, float):
                    v = f"{v:.2f}"
                cells += f"<td>{html_escape(str(v))}</td>"
            parts.append(f"<tr><td class='small'>{html_escape(str(r.get('file',''))[:46])}</td>"
                         f"<td>{html_escape(str(r.get('scope','')))}</td>"
                         f"<td>{html_escape(str(r.get('kpi','')))}</td>{cells}</tr>")
        parts.append("</tbody></table>")
        parts.append(f"<p class='small'>All other metric keys are in "
                     f"<code>combined/summary.json</code>.</p>")
    else:
        parts.append("<p>No KPI metrics were produced.</p>")
    parts.append("</div>")

    # ---- per file sections ----
    parts.append("<h2>2. Per-file results</h2>")
    for sec in sections:
        parts.append(f"<div class='card'><h3>{html_escape(sec['title'])}</h3>")
        parts.append(f"<div class='small'>{html_escape(sec['subtitle'])}</div>")
        for pill in sec.get("pills", []):
            parts.append(f"<span class='pill'>{html_escape(str(pill))}</span>")
        if sec.get("note"):
            parts.append(f"<div class='small'>{sec['note']}</div>")
        if sec.get("kpi_html"):
            parts.append(f"<div class='kpiblock'><h4>{html_escape(sec['title'])} &mdash; KPI detail</h4>"
                         f"{sec['kpi_html']}</div>")
        if sec.get("figures"):
            parts.append(f"<h3>(X, Y) plots &mdash; {len(sec['figures'])} figure(s)</h3>")
            for i, fig in enumerate(sec["figures"]):
                did = f"fig_{sec['idx']}_{i}"
                parts.append(f"<details open><summary>{html_escape(str(fig['title']))}</summary>"
                             f"<div id='{did}' class='plot'></div></details>")
                parts.append(f"<script>Plotly.newPlot('{did}',{json.dumps(fig['data'])},"
                             f"{json.dumps(fig['layout'])},{{responsive:true,displaylogo:false}});</script>")
        parts.append("</div>")

    parts.append("</div></body></html>")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("".join(parts))
    return out_path


# --------------------------------------------------------------------------

def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--max-points", type=int, default=4000)
    ap.add_argument("--skip-plots", action="store_true")
    ap.add_argument("--only", default=None, help="substring filter on the pair key")
    ap.add_argument("--rebuild-only", action="store_true",
                    help="re-assemble the HTML from the cached collection (no re-run)")
    ap.add_argument("--kpi-only", action="store_true",
                    help="re-run the KPI phase only and re-harvest the existing plots")
    args = ap.parse_args()

    cache = os.path.join(OUT, "_collected.json")
    if args.rebuild_only:
        with open(cache, encoding="utf-8") as f:
            blob = json.load(f)
        sections = blob["sections"]
        summary_rows = blob["summary"]
        meta = blob["meta"]
        out = build_html(sections, summary_rows, meta, os.path.join(OUT, "KPI_Combined_Report.html"))
        shutil.copyfile(out, DESKTOP_OUT)
        print(f"rebuilt: {out} ({os.path.getsize(out):,} bytes)")
        print(f"desktop : {DESKTOP_OUT}")
        return 0

    if os.path.isdir(OUT):
        if args.kpi_only:
            # Park the plot output OUTSIDE OUT, otherwise the rmtree below
            # would delete the very thing we are trying to preserve.
            keep_root = OUT + "_keep"
            os.makedirs(keep_root, exist_ok=True)
            for keep in ("can_int", "intplot"):
                src = os.path.join(OUT, keep)
                dst = os.path.join(keep_root, keep)
                if os.path.isdir(src) and not os.path.isdir(dst):
                    shutil.move(src, dst)
        shutil.rmtree(OUT, ignore_errors=True)
    os.makedirs(OUT, exist_ok=True)
    if args.kpi_only:
        keep_root = OUT + "_keep"
        for keep in ("can_int", "intplot"):
            src = os.path.join(keep_root, keep)
            if os.path.isdir(src):
                shutil.move(src, os.path.join(OUT, keep))
        shutil.rmtree(keep_root, ignore_errors=True)

    pairs = discover_pairs()
    for p in pairs:
        p["kind"] = classify(p["input"])
    if args.only:
        pairs = [p for p in pairs if args.only.lower() in p["key"].lower()]
    print(f"discovered {len(pairs)} candidate pair(s):")
    for p in pairs:
        print(f"   [{p['bucket']:5}] {p['kind']:8} {p['key'][:60]}"
              + ("  (no counterpart)" if not p["output"] else ""))

    sections: List[Dict[str, Any]] = []
    summary_rows: List[Dict[str, Any]] = []
    n_fig = 0
    idx = 0

    # ---------------- KPI runs (per pair) ----------------
    for p in pairs:
        if not p["output"]:
            continue
        idx += 1
        label = f"{p['bucket']}__{p['key'][:40]}"
        kinds = []
        if p["kind"] == "can":
            kinds.append(("can", "can_kpi"))
        elif p["kind"] == "udp":
            kinds.append(("udp", "udp_kpi"))
        kpi_html = ""
        pills = []
        for kind, kname in kinds:
            t0 = time.time()
            res = run_kpi_worker(kind, p, OUT, f"{label}__{kname}")
            dt = time.time() - t0
            if res.get("error"):
                pills.append(f"{kname}: ERROR {str(res['error'])[:120]}")
                continue
            rows = summarise_kpi(res.get("metrics", {}))
            for r in rows:
                r["file"] = label
            summary_rows.extend(rows)
            pills.append(f"{kname}: {len(rows)} metric row(s) in {dt:.0f}s")
            kpi_html += res.get("html", "") or ""
        sections.append({"idx": idx, "title": label, "subtitle": f"{p['kind']} pair",
                         "pills": pills, "note": p.get("note", ""),
                         "kpi_html": kpi_html, "figures": []})

    # ---------------- interactive plot runs ----------------
    if not args.skip_plots:
        can_pairs = [p for p in pairs if p["output"] and p["kind"] == "can"]
        udp_pairs = [p for p in pairs if p["output"] and p["kind"] == "udp"]
        for pkg, entry, plist, tag in (
                ("can_interactive_plot", "can_intplot_main.py", can_pairs, "can_int"),
                ("intplot_kpi", "ResimHTMLReport.py", udp_pairs, "intplot")):
            if not plist:
                continue
            outdir = os.path.join(OUT, tag)
            os.makedirs(outdir, exist_ok=True)
            plot_cfg = build_plot_config(os.path.join(KPI_DIR, pkg),
                                         os.path.join(OUT, f"{tag}_plot_config.json"))
            if not args.kpi_only:
                print(f"\n>> {pkg}: running {len(plist)} pair(s) ...")
                r = run_interactive(pkg, entry, plist, plot_cfg, outdir)
                print(f"   rc={r['rc']} elapsed={r['elapsed_s']:.0f}s")
                if r["rc"] != 0:
                    print("   tail:", r["tail"][-600:])
            else:
                print(f"\n>> {pkg}: re-harvesting existing plots from {outdir}")
            # harvest figures per generated report
            for dp, dn, fn in os.walk(outdir):
                for f in sorted(fn):
                    if not f.endswith(".html"):
                        continue
                    hp = os.path.join(dp, f)
                    figs = extract_figures(hp, args.max_points)
                    if not figs:
                        continue
                    n_fig += len(figs)
                    rel = os.path.relpath(hp, outdir)
                    # attach to the matching section, else create one
                    matched = None
                    for sec in sections:
                        if sec["title"] and rel.lower().startswith(sec["title"].lower()[:18]):
                            matched = sec
                            break
                    if matched is None:
                        matched = {"idx": 9000 + len(sections), "title": f"{tag}: {rel}",
                                   "subtitle": "interactive plot report", "pills": [],
                                   "note": "", "kpi_html": "", "figures": []}
                        sections.append(matched)
                    matched["figures"].extend(figs)

    meta = {
        "pairs": len([p for p in pairs if p["output"]]),
        "can_kpi": len([s for s in sections if any("can_kpi" in str(x) for x in s["pills"])]),
        "udp_kpi": len([s for s in sections if any("udp_kpi" in str(x) for x in s["pills"])]),
        "intplot": 1 if not args.skip_plots else 0,
        "can_int": 1 if not args.skip_plots else 0,
        "figures": n_fig,
        "generated": time.strftime("%Y-%m-%d %H:%M:%S"),
    }
    out = build_html(sections, summary_rows, meta, os.path.join(OUT, "KPI_Combined_Report.html"))
    shutil.copyfile(out, DESKTOP_OUT)
    print(f"\ncombined report: {out}")
    print(f"desktop copy  : {DESKTOP_OUT} ({os.path.getsize(DESKTOP_OUT):,} bytes)")
    print(f"sections={len(sections)} summary_rows={len(summary_rows)} figures={n_fig}")
    with open(os.path.join(OUT, "summary.json"), "w", encoding="utf-8") as f:
        json.dump({"meta": meta, "summary": summary_rows,
                   "sections": [{k: v for k, v in s.items() if k != "kpi_html"} for s in sections]},
                  f, indent=2, default=str)
    with open(cache, "w", encoding="utf-8") as f:
        json.dump({"meta": meta, "summary": summary_rows, "sections": sections},
                  f, default=str)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
