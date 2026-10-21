"""End-to-end verification of the generalizable (X, Y) plots on edge_hdf.

Runs the REAL interactive-plot pipelines (CAN and UDP) against the real
HDF5 fixtures in edge_hdf/, with a plot config that declares arbitrary
(X, Y) signal pairs, then verifies the generated HTML actually contains
those plots and that they carry data.

Usage:
    python run_edge_hdf_test.py            # both CAN and UDP
    python run_edge_hdf_test.py --can
    python run_edge_hdf_test.py --udp
"""
from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
import numpy as np
from typing import Any, Dict, List

HERE = os.path.dirname(os.path.abspath(__file__))
KPI_ROOT = os.path.dirname(HERE)                 # ALL_KPI
REPO = os.path.dirname(KPI_ROOT)                 # dump_code
EDGE = os.path.join(REPO, "edge_hdf")
OUT = os.path.join(HERE, "out")

# Real fixture pairs (input -> output), same basename convention.
CAN_PAIRS = [
    (os.path.join(EDGE, "can", "input", "CCA_9010_3100099_BUS_20260119_120641_0000_rR00080104_HDF.h5"),
     os.path.join(EDGE, "can", "output", "CCA_9010_3100099_BUS_20260119_120641_0000_HDF.h5")),
]
UDP_PAIRS = [
    (os.path.join(EDGE, "udp", "input", "ThunderMCIP_WS07952_20260316_193238_0000_b05_r000801151.h5"),
     os.path.join(EDGE, "udp", "output", "ThunderMCIP_WS07952_20260316_193238_0000_b05.h5")),
]
UDP_DUMMY_PAIRS = [
    (os.path.join(EDGE, "udp", "input", "kpi_dummy_pair1_input.h5"),
     os.path.join(EDGE, "udp", "output", "kpi_dummy_pair1_output.h5")),
]

# (X, Y) pairs under test. Deliberately NOT scan_index on the X axis.
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

# Which signal carries which pairing.
XY_OWNER = {"ran": ["range_vs_doppler", "range_vs_azimuth"],
            "vel": ["velocity_vs_elevation"]}


def build_plot_config(pkg_dir: str, out_json: str) -> str:
    """Take the shipped Gen7V1_V2 config and add the (X, Y) pairings."""
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

    # Add the (X, Y) pairings to EVERY stream that carries both ran and vel
    # (the CAN layout uses DETECTION_STREAM, the real MUDP/ThunderMCIP layout
    # uses DOWN_SELECTION_STREAM).
    for stream_name, stream_cfg in list(cfg.items()):
        if not isinstance(stream_cfg, dict):
            continue
        if "ran" not in stream_cfg or "vel" not in stream_cfg:
            continue
        for signal, ids in XY_OWNER.items():
            if signal not in stream_cfg:
                continue
            entry = stream_cfg[signal]
            pts = list(entry.get("plot_types", []))
            if "plot_xy_correlation" not in pts:
                pts.append("plot_xy_correlation")
            entry["plot_types"] = pts
            entry["xy_plots"] = [p for p in XY_PAIRS if p["plot_id"] in ids]
        # the X/Y partner signals must also offer the pairing when they own one
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump({"Gen7V1_V2": cfg}, f, indent=1)
    return out_json


def build_inputs(pairs: List[tuple], out_json: str) -> str:
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump({"INPUT_HDF": [p[0] for p in pairs],
                   "OUTPUT_HDF": [p[1] for p in pairs]}, f, indent=1)
    return out_json


def build_xml(pkg_dir: str, out_xml: str) -> str:
    """Copy the shipped XML and turn the KPI tab off (it needs a ZMQ server)."""
    src = os.path.join(pkg_dir, "ConfigInteractivePlots.xml")
    s = open(src, encoding="utf-8", errors="ignore").read()
    s = re.sub(r"<KPI>1</KPI>", "<KPI>0</KPI>", s)
    with open(out_xml, "w", encoding="utf-8") as f:
        f.write(s)
    return out_xml


def run_pipeline(pkg_dir: str, entry: str, xml: str, inputs: str,
                 outdir: str, plot_cfg: str, timeout: int = 1800) -> Dict[str, Any]:
    """Run the real CLI in the package directory."""
    if os.path.isdir(outdir):
        shutil.rmtree(outdir, ignore_errors=True)
    os.makedirs(outdir, exist_ok=True)
    cmd = [sys.executable, entry, xml, inputs, outdir, plot_cfg]
    t0 = time.time()
    proc = subprocess.run(cmd, cwd=pkg_dir, capture_output=True, text=True,
                          timeout=timeout)
    return {
        "cmd": " ".join(cmd),
        "returncode": proc.returncode,
        "elapsed_s": time.time() - t0,
        "stdout_tail": proc.stdout[-4000:],
        "stderr_tail": proc.stderr[-4000:],
        "outdir": outdir,
    }


def _decode_series(v):
    """Plotly >=5 encodes numpy arrays as {'dtype':..,'bdata':..} - decode it."""
    import base64
    if isinstance(v, dict) and "bdata" in v:
        raw = base64.b64decode(v["bdata"])
        arr = np.frombuffer(raw, dtype=np.dtype(v.get("dtype", "f8")))
        shape = v.get("shape")
        if shape:
            try:
                arr = arr.reshape(shape)
            except Exception:
                pass
        return np.asarray(arr).ravel().tolist()
    return v if isinstance(v, list) else []


def _balanced(text: str, start: int, open_ch: str, close_ch: str):
    """Return (substring, end_index) for a balanced bracket region."""
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


def extract_xy_figures(html_path: str) -> List[Dict[str, Any]]:
    """Return the (X, Y) figures embedded in a generated report."""
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
        if p < len(s) and s[p] == '"':
            q = s.index('"', p + 1)
            fid = s[p + 1:q]
            p = q + 1
        else:
            fid = "?"
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
        traces = []
        for tr in data:
            xs = [v for v in _decode_series(tr.get("x")) if isinstance(v, (int, float))]
            ys = [v for v in _decode_series(tr.get("y")) if isinstance(v, (int, float))]
            traces.append({
                "name": tr.get("name"),
                "n": len(xs),
                "x": [min(xs, default=None), max(xs, default=None)],
                "y": [min(ys, default=None), max(ys, default=None)],
            })
        out.append({"fig_id": fid, "title": title, "traces": traces})
        idx = m + 1
    return out


def scan_outputs(outdir: str) -> Dict[str, Any]:
    """Find generated HTML and verify the (X, Y) plots carry real data."""
    htmls = []
    for dp, _dn, fn in os.walk(outdir):
        for f in fn:
            if f.endswith(".html"):
                htmls.append(os.path.join(dp, f))
    xy_figs, xy_points, plotly_data = [], 0, 0
    sizes = []
    for h in htmls:
        s = open(h, encoding="utf-8", errors="ignore").read()
        sizes.append((os.path.getsize(h), os.path.relpath(h, outdir)))
        plotly_data += s.count("Plotly.newPlot")
        for fig in extract_xy_figures(h):
            n = sum(t["n"] for t in fig["traces"])
            xy_points += n
            xy_figs.append({
                "file": os.path.relpath(h, outdir),
                "title": fig["title"],
                "traces": fig["traces"],
                "points": n,
            })
    sizes.sort(reverse=True)
    return {
        "html_count": len(htmls),
        "html_files": sizes[:12],
        "xy_figures": xy_figs,
        "xy_figure_count": len(xy_figs),
        "xy_points_total": xy_points,
        "plotly_plots": plotly_data,
        "total_bytes": sum(s for s, _ in sizes),
    }


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--can", action="store_true")
    ap.add_argument("--udp", action="store_true")
    ap.add_argument("--dummy", action="store_true",
                    help="also run the small UDP dummy pair")
    args = ap.parse_args()
    if not (args.can or args.udp or args.dummy):
        args.can = args.udp = args.dummy = True

    os.makedirs(OUT, exist_ok=True)
    report: Dict[str, Any] = {"generated": time.strftime("%Y-%m-%d %H:%M:%S"), "runs": []}
    failures = []

    jobs = []
    if args.can:
        jobs.append(("CAN", "can_interactive_plot", "can_intplot_main.py", CAN_PAIRS))
    if args.udp:
        jobs.append(("UDP", "intplot_kpi", "ResimHTMLReport.py", UDP_PAIRS))
    if args.dummy:
        jobs.append(("UDP-DUMMY", "intplot_kpi", "ResimHTMLReport.py", UDP_DUMMY_PAIRS))

    for label, pkg, entry, pairs in jobs:
        pkg_dir = os.path.join(os.path.dirname(HERE), "KPI", pkg)
        tag = label.lower().replace("-", "_")
        xml = build_xml(pkg_dir, os.path.join(OUT, f"{tag}_config.xml"))
        inputs = build_inputs(pairs, os.path.join(OUT, f"{tag}_inputs.json"))
        plot_cfg = build_plot_config(pkg_dir, os.path.join(OUT, f"{tag}_plot_config.json"))
        outdir = os.path.join(OUT, f"{tag}_html")

        missing = [p for pr in pairs for p in pr if not os.path.exists(p)]
        if missing:
            failures.append(f"{label}: missing fixtures {missing}")
            continue

        print(f"\n=== {label} :: {pkg}/{entry} ===")
        print(f"    plot config: {os.path.basename(plot_cfg)}")
        res = run_pipeline(pkg_dir, entry, xml, inputs, outdir, plot_cfg)
        scan = scan_outputs(outdir)
        res["scan"] = scan
        report["runs"].append({"label": label, "package": pkg, **res})
        print(f"    rc={res['returncode']} elapsed={res['elapsed_s']:.1f}s "
              f"html={scan['html_count']} plotly={scan['plotly_plots']} "
              f"xy_figures={scan['xy_figure_count']} xy_points={scan['xy_points_total']}")
        for f in scan["xy_figures"][:6]:
            print(f"      {f['points']:6d} pts | {f['title']}")
            for t in f["traces"]:
                print(f"              {str(t['name']):8} n={t['n']:6d} "
                      f"x=[{t['x'][0]}, {t['x'][1]}] y=[{t['y'][0]}, {t['y'][1]}]")
        if res["returncode"] != 0:
            failures.append(f"{label}: exit {res['returncode']}")
            print("    stderr tail:", res["stderr_tail"][-1500:])
        if scan["xy_figure_count"] == 0:
            failures.append(f"{label}: no (X, Y) plots found in the generated HTML")
        elif scan["xy_points_total"] == 0:
            failures.append(f"{label}: (X, Y) plots found but they carry NO data points")
        for size, name in scan["html_files"][:3]:
            print(f"      {size:>9,}  {name}")

    with open(os.path.join(OUT, "report.json"), "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2, default=str)

    print("\n" + "=" * 72)
    if failures:
        print("FAILURES:")
        for x in failures:
            print("  -", x)
        return 1
    print("ALL EDGE_HDF RUNS OK: (X, Y) plots present in the generated reports.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
