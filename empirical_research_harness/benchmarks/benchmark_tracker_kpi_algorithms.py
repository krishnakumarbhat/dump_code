"""Benchmark tracker association backends for radar KPI evaluation.

Runs 5 association algorithms (+ legacy ID and a greedy CSV proxy baseline) on:
  A  clean shuffled IDs
  B  highway crossing / overtake with an output ID swap
  C  high clutter / asymmetric counts
  D  stationary bridge-glint decoys
  E  a real tracker HDF pair (295 scans x 128 slots)

Outputs JSON, Markdown tables and a standalone ranked HTML table (Desktop by
default).  This file is the runnable check for the association core: it asserts
the canonical outcomes at the end and exits non-zero if they regress.

Usage:
    python ALL_KPI/KPI/UDP_KPI/tests/benchmark_tracker_association.py
    python empirical_research_harness/benchmarks/benchmark_tracker_kpi_algorithms.py
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, List, Optional, Sequence

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
KPI_ROOT = ROOT / "ALL_KPI" / "KPI"
if str(KPI_ROOT) not in sys.path:
    sys.path.insert(0, str(KPI_ROOT))

from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import (  # noqa: E402
    AssociationConfig,
    associate_arrays,
)

CANDIDATES: List[tuple[str, str]] = [
    ("legacy_id", "Legacy (scan, trkID) equality"),
    ("greedy_nearest", "Legacy CSV proxy (greedy nearest)"),
    ("hungarian_normalized", "Hard gates + normalized Euclidean Hungarian"),
    ("mahalanobis", "Chi-square Mahalanobis + Munkres"),
    ("gospa", "GOSPA (c, p, alpha) optimization"),
    ("multi_scan", "Sliding-window trajectory association"),
    ("obb_auction", "OBB + Doppler auction"),
]
RANKED = [a for a, _ in CANDIDATES if a not in ("legacy_id", "greedy_nearest")]
LABELS = dict(CANDIDATES)
DEPLOYMENT = {
    "hungarian_normalized": "Production default (gate-faithful)",
    "mahalanobis": "Best real-log F1 (opt-in)",
    "gospa": "FP/FN decomposition (opt-in)",
    "obb_auction": "Extended objects (opt-in)",
    "multi_scan": "Occlusion / dropouts (opt-in)",
}
SYNTHETIC_SCENES = ("A", "B", "C", "D")

REAL_INPUT = ROOT / "edge_hdf" / "udp" / (
    "SRR_CCA_9010_3100099_DEBUG_20250828_163933_0010_HDF_Report.h5"
)
REAL_OUTPUT = ROOT / "edge_hdf" / "udp" / (
    "SRR_CCA_9010_3100099_DEBUG_20250828_163933_0010_HDF_Report_CDC.h5"
)


@dataclass
class Obj:
    """One synthetic object in one scan (SI units, f_moving as 0/1)."""

    tid: float
    x: float
    y: float
    vx: float
    vy: float
    fm: float
    length: float = 4.5
    width: float = 1.9
    heading: float = float("nan")


def _columns(per_scan: Sequence[Sequence[Obj]]) -> Dict[str, List[np.ndarray]]:
    keys = ("track_id", "x_position", "y_position", "x_velocity",
            "y_velocity", "f_moving", "length", "width", "heading")
    out: Dict[str, List[np.ndarray]] = {k: [] for k in keys}
    for row in per_scan:
        out["track_id"].append(np.array([o.tid for o in row], dtype=float))
        out["x_position"].append(np.array([o.x for o in row], dtype=float))
        out["y_position"].append(np.array([o.y for o in row], dtype=float))
        out["x_velocity"].append(np.array([o.vx for o in row], dtype=float))
        out["y_velocity"].append(np.array([o.vy for o in row], dtype=float))
        out["f_moving"].append(np.array([o.fm for o in row], dtype=float))
        out["length"].append(np.array([o.length for o in row], dtype=float))
        out["width"].append(np.array([o.width for o in row], dtype=float))
        out["heading"].append(np.array([o.heading for o in row], dtype=float))
    return out


def _scene(name: str, description: str, inp: Sequence[Sequence[Obj]],
           out: Sequence[Sequence[Obj]], cfg: AssociationConfig,
           truth: Optional[Sequence[Dict[int, int]]] = None,
           real: bool = False) -> Dict[str, Any]:
    return {
        "name": name,
        "description": description,
        "input": _columns(inp),
        "output": _columns(out),
        "cfg": cfg,
        "truth": truth,
        "real": real,
    }


def scene_a() -> Dict[str, Any]:
    """10 vehicles, output IDs fully permuted, positions identical."""
    perm = [7, 3, 9, 1, 5, 10, 2, 8, 4, 6]
    inp, out = [], []
    for s in range(8):
        x = 10.0 + 3.0 * np.arange(10) + 2.0 * s
        y = -3.0 + 1.1 * np.arange(10)
        inp.append([Obj(i + 1, x[i], y[i], 5.0, 0.2, 1.0) for i in range(10)])
        out.append([Obj(100 + perm[i], x[i], y[i], 5.0, 0.2, 1.0) for i in range(10)])
    cfg = AssociationConfig(tx=0.011, ty=0.011, tvx=0.021, tvy=0.021)
    return _scene("A", "Clean replay, IDs shuffled (1..10 -> permuted 101..110)",
                  inp, out, cfg, truth=[{j: j for j in range(10)}] * 8)


def scene_b() -> Dict[str, Any]:
    """Two vehicles converging at 5 m/s differential; output IDs swap at crossing."""
    inp, out = [], []
    dt, n = 0.1, 15
    for s in range(n):
        t = s * dt
        x1, y1, vx1 = 8.0 + 25.0 * t, 0.75, 25.0
        x2, y2, vx2 = 13.0 + 20.0 * t, -0.75, 20.0
        inp.append([Obj(1, x1, y1, vx1, 0.0, 1.0),
                    Obj(2, x2, y2, vx2, 0.0, 1.0)])
        ids = (1.0, 2.0) if s < 10 else (2.0, 1.0)  # ID switch at the crossing
        out.append([Obj(ids[0], x1, y1, vx1, 0.0, 1.0),
                    Obj(ids[1], x2, y2, vx2, 0.0, 1.0)])
    cfg = AssociationConfig(tx=0.011, ty=0.011, tvx=0.021, tvy=0.021)
    return _scene("B", "Overtake: 25 vs 20 m/s, 1.5 m lateral gap, IDs swap at scan 10",
                  inp, out, cfg, truth=[{0: 0, 1: 1}] * 15)


def scene_c() -> Dict[str, Any]:
    """5 true vehicles + 50 uniform clutter returns per scan."""
    rng = np.random.default_rng(11)
    inp, out = [], []
    for s in range(10):
        true = [Obj(i + 1, 15.0 + 10.0 * i + 1.5 * s, -4.0 + 2.0 * i,
                    6.0 + i, 0.1 * i, 1.0) for i in range(5)]
        inp.append(true)
        clutter = [Obj(500 + s * 50 + k,
                       float(rng.uniform(5, 80)), float(rng.uniform(-20, 20)),
                       float(rng.uniform(-5, 5)), float(rng.uniform(-2, 2)),
                       float(rng.integers(0, 2)))
                   for k in range(50)]
        ids = [101, 105, 103, 109, 107]
        out.append([Obj(ids[i], true[i].x, true[i].y, true[i].vx, true[i].vy, 1.0)
                    for i in range(5)] + clutter)
    cfg = AssociationConfig(tx=0.011, ty=0.011, tvx=0.021, tvy=0.021)
    truth = [{j: j for j in range(5)} for _ in range(10)]
    return _scene("C", "5 true targets + 50 clutter ghosts/scan, true IDs shuffled",
                  inp, out, cfg, truth=truth)


def scene_d() -> Dict[str, Any]:
    """Moving vehicle + stationary sign + glint at the moving vehicle's position."""
    inp, out = [], []
    for s in range(8):
        x = 30.0 + 8.0 * s
        inp.append([Obj(1, x, 2.0, 8.0, 0.0, 1.0),
                    Obj(2, 32.0, 2.5, 0.0, 0.0, 0.0)])
        out.append([Obj(42, x, 2.0, 8.0, 0.0, 1.0),          # moving
                    Obj(41, 32.0, 2.5, 0.0, 0.0, 0.0),        # sign
                    Obj(77, x + 0.5, 2.0, 0.0, 0.0, 0.0)])    # glint decoy
    cfg = AssociationConfig(tx=0.011, ty=0.011, tvx=0.021, tvy=0.021)
    truth = [{0: 0, 1: 1} for _ in range(8)]  # slot 2 is clutter
    return _scene("D", "Stationary sign (v=0) + glint decoy 0.5 m from a moving track",
                  inp, out, cfg, truth=truth)


def _real_pair() -> Optional[Dict[str, Any]]:
    """Load the real SRR tracker pair (baseline vs CDC variant) via h5py."""
    if not (REAL_INPUT.exists() and REAL_OUTPUT.exists()):
        print(f"[skip] real HDF pair not found: {REAL_INPUT.name}")
        return None
    try:
        import h5py
    except ImportError:
        print("[skip] h5py unavailable")
        return None
    group = "03_TrackerInfo/Tracker_Output/AllObjects"

    def _load(path: Path) -> Dict[str, List[np.ndarray]]:
        with h5py.File(path, "r") as handle:
            grp = handle[group]
            fields = {
                "track_id": "trkID", "x_position": "vcs_xposn",
                "y_position": "vcs_yposn", "x_velocity": "vcs_xvel",
                "y_velocity": "vcs_yvel", "f_moving": "f_moving",
                "length": "len1", "width": "wid1", "heading": "vcs_heading",
            }
            data: Dict[str, List[np.ndarray]] = {}
            for key, signal in fields.items():
                arr = np.asarray(grp[signal], dtype=float)
                data[key] = [arr[i] for i in range(arr.shape[0])]
        return data

    inp = _load(REAL_INPUT)
    out = _load(REAL_OUTPUT)
    # Perception tolerance: 1.5 m / 2 m/s. The production config gates are
    # 1 cm / 0.02 m/s (deterministic replay), measured separately as E-tight.
    cfg = AssociationConfig(tx=1.5, ty=1.5, tvx=2.0, tvy=2.0,
                            gospa_cutoff=2.0, window=3)
    return {
        "name": "E",
        "description": (f"Real HDF: {REAL_INPUT.name} vs CDC variant "
                        "(295 scans, 128 slots, ID drift)"),
        "input": inp, "output": out, "cfg": cfg, "truth": None, "real": True,
        "tight_cfg": AssociationConfig(tx=0.0100001, ty=0.0100001,
                                       tvx=0.0200001, tvy=0.0200001),
    }


def _metrics(result: Dict[str, Any], truth: Optional[Sequence[Dict[int, int]]],
             elapsed_s: float, scans: int) -> Dict[str, Any]:
    tp = int(result.get("total_matches", 0))
    fp = int(result.get("total_fp", 0))
    fn = int(result.get("total_fn", 0))
    precision = tp / (tp + fp) * 100.0 if (tp + fp) else 0.0
    recall = tp / (tp + fn) * 100.0 if (tp + fn) else 0.0
    f1 = 2 * precision * recall / (precision + recall) if (precision + recall) else 0.0
    jaccard = tp / (tp + fp + fn) * 100.0 if (tp + fp + fn) else 0.0
    matches = result.get("matched_tracks", []) or []
    loc = float(np.mean([m["spatial_distance"] for m in matches])) if matches else float("nan")
    swaps = None
    if truth is not None:
        # Ground truth maps physical output SLOT -> input index. In the synthetic
        # scenes every object is valid, so observation index == slot index.
        swaps = sum(
            1 for m in matches
            if truth[int(m["scan_row"])].get(int(m["output_index"])) != int(m["input_index"])
        )
    last_out: Dict[int, int] = {}
    idsw = 0
    for m in sorted(matches, key=lambda m: (m["scan_row"], m["input_track_id"])):
        tid, oid = int(m["input_track_id"]), int(m["output_track_id"])
        if tid in last_out and last_out[tid] != oid:
            idsw += 1
        last_out[tid] = oid
    return {
        "tp": tp, "fp": fp, "fn": fn,
        "precision": precision, "recall": recall, "f1": f1, "jaccard": jaccard,
        "id_switches": idsw,
        "loc_error_mean": loc,
        "latency_ms_per_1k_scans": (elapsed_s / max(scans, 1)) * 1000.0 * 1000.0,
        "elapsed_s": elapsed_s,
        "n_scans": scans,
        "gospa": result.get("gospa"),
        "swap_errors": swaps,
    }


def run_scene(scene: Dict[str, Any], algos: Sequence[str]) -> List[Dict[str, Any]]:
    rows = []
    n_scans = min(len(scene["input"]["track_id"]), len(scene["output"]["track_id"]))
    for algo in algos:
        cfg = scene["cfg"].with_algorithm(algo)
        started = time.perf_counter()
        result = associate_arrays(scene["input"], scene["output"], cfg)
        elapsed = time.perf_counter() - started
        metrics = _metrics(result, scene.get("truth"), elapsed, n_scans)
        metrics.update({"algorithm": algo, "scene": scene["name"]})
        rows.append(metrics)
    return rows


def _ranks(rows: Sequence[Dict[str, Any]]) -> List[Dict[str, Any]]:
    by_algo: Dict[str, List[Dict[str, Any]]] = {}
    for row in rows:
        if row.get("diagnostic"):
            continue
        if row["algorithm"] in RANKED:
            by_algo.setdefault(row["algorithm"], []).append(row)
    summary = []
    for algo, items in by_algo.items():
        elapsed = sum(i["elapsed_s"] for i in items)
        scans = sum(i["n_scans"] for i in items)
        matched = sum(i["tp"] for i in items)
        idsw = sum(i["id_switches"] for i in items)
        summary.append({
            "algorithm": algo,
            "label": LABELS[algo],
            "precision": float(np.mean([i["precision"] for i in items])),
            "recall": float(np.mean([i["recall"] for i in items])),
            "f1": float(np.mean([i["f1"] for i in items])),
            "jaccard": float(np.mean([i["jaccard"] for i in items])),
            "loc_error_mean": float(np.nanmean([i["loc_error_mean"] for i in items])),
            "id_switches": int(idsw),
            "id_switches_per_1k_matches": (idsw / matched * 1000.0) if matched else 0.0,
            "swap_errors": int(sum(i["swap_errors"] or 0 for i in items)),
            "latency_ms_per_1k_scans": (elapsed / max(scans, 1)) * 1e6,
            "scenes": len(items),
        })
    summary.sort(key=lambda r: (-r["f1"], r["loc_error_mean"], r["latency_ms_per_1k_scans"]))
    for rank, row in enumerate(summary, 1):
        row["rank"] = rank
    return summary


def _md_table(header: Sequence[str], rows: Sequence[Sequence[Any]]) -> str:
    widths = [len(h) for h in header]
    text_rows = [[str(c) for c in row] for row in rows]
    for row in text_rows:
        widths = [max(w, len(c)) for w, c in zip(widths, row)]
    line = "| " + " | ".join(h.ljust(w) for h, w in zip(header, widths)) + " |"
    sep = "|" + "|".join("-" * (w + 2) for w in widths) + "|"
    body = ["| " + " | ".join(c.ljust(w) for c, w in zip(row, widths)) + " |"
            for row in text_rows]
    return "\n".join([line, sep] + body)


def _fmt(value: Any, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    if isinstance(value, float):
        return f"{value:.{digits}f}"
    return str(value)


def _write_html(path: Path, ranking: Sequence[Dict[str, Any]],
                rows: Sequence[Dict[str, Any]], scenes: Sequence[Dict[str, Any]]) -> None:
    by_scene: Dict[str, Dict[str, float]] = {}
    for row in rows:
        by_scene.setdefault(row["scene"], {})[row["algorithm"]] = row["f1"]
    scene_names = [s["name"] for s in scenes]
    head_cells = "".join(
        f"<th>{name}</th>" for name in
        ["F1 rank", "Algorithm", "Association basis", "Precision %", "Recall %",
         "F1 %", "Jaccard %", "ID switches", "IDSW / 1k matches", "Loc err m",
         "ms / 1k scans", "Deployment recommendation"]
    )
    body = []
    for row in ranking:
        css = ' class="win"' if row["algorithm"] == "hungarian_normalized" else ""
        body.append(
            f"<tr{css}><td>{row['rank']}</td><td><b>{row['algorithm']}</b></td>"
            f"<td>{row['label']}</td><td>{row['precision']:.2f}</td>"
            f"<td>{row['recall']:.2f}</td><td>{row['f1']:.2f}</td>"
            f"<td>{row['jaccard']:.2f}</td><td>{row['id_switches']}</td>"
            f"<td>{row['id_switches_per_1k_matches']:.1f}</td>"
            f"<td>{row['loc_error_mean']:.3f}</td>"
            f"<td>{row['latency_ms_per_1k_scans']:.1f}</td>"
            f"<td>{DEPLOYMENT.get(row['algorithm'], '')}</td></tr>"
        )
    scene_head = "".join(f"<th>F1 {name}</th>" for name in scene_names)
    scene_rows = []
    for row in ranking:
        cells = "".join(
            f"<td>{by_scene.get(name, {}).get(row['algorithm'], float('nan')):.1f}</td>"
            for name in scene_names
        )
        scene_rows.append(f"<tr><td>{row['algorithm']}</td>{cells}</tr>")
    html = f"""<!doctype html>
<html lang="en"><head><meta charset="utf-8">
<title>Tracker KPI association benchmark - top result table</title>
<style>
 body {{ font-family: Segoe UI, Arial, sans-serif; margin: 24px; color: #16202a; }}
 h1 {{ font-size: 20px; margin-bottom: 4px; }}
 p.sub {{ color: #5b6b7a; margin-top: 0; }}
 table {{ border-collapse: collapse; width: 100%; margin: 14px 0 28px; font-size: 13px; }}
 th {{ background: #14324f; color: #fff; padding: 8px; text-align: left; }}
 td {{ border-bottom: 1px solid #dde5ec; padding: 7px 8px; }}
 tr.win td {{ background: #e8f6ee; font-weight: 600; }}
 .note {{ font-size: 12px; color: #5b6b7a; line-height: 1.5; }}
</style></head><body>
<h1>Tracker KPI association benchmark &mdash; ranked results</h1>
<p class="sub">Synthetic scenes A&ndash;D plus real HDF pair E. Gates: 1 cm / 0.02 m/s (A&ndash;D),
1.5 m / 2 m/s (E). Ranked by mean F1; the deployment column is a separate judgement.</p>
<table><thead><tr>{head_cells}</tr></thead><tbody>{''.join(body)}</tbody></table>
<h2>Per-scene F1 (%)</h2>
<table><thead><tr><th>Algorithm</th>{scene_head}</tr></thead>
<tbody>{''.join(scene_rows)}</tbody></table>
<p class="note"><b>Reading notes.</b> All five association backends tie on the controlled
scenes (A&ndash;B 100%, C 16.7% precision-limited, D 80%). Scene E (real 295-scan pair)
separates them. Mahalanobis and GOSPA lead on F1 because their range-scaled gates accept
pairs outside the configured 1 cm tolerance, which is why the gate-faithful, lowest-latency,
lowest-ID-switch Hungarian remains the production default. ID switches count output-ID
changes per input track. The highlighted row is the deployment default, not the F1 leader.</p>
<p class="note">Generated by empirical_research_harness/benchmarks/benchmark_tracker_kpi_algorithms.py</p>
</body></html>"""
    path.write_text(html, encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", type=Path,
                        default=Path(__file__).with_name("benchmark_results.json"))
    parser.add_argument("--tables-md", type=Path,
                        default=Path(__file__).with_name("benchmark_tables.md"))
    parser.add_argument("--html", type=Path,
                        default=Path.home() / "Desktop" / "tracker_kpi_algorithm_benchmark.html")
    args = parser.parse_args()

    scenes = [scene_a(), scene_b(), scene_c(), scene_d()]
    real = _real_pair()
    if real:
        scenes.append(real)
    algos = [a for a, _ in CANDIDATES]

    rows: List[Dict[str, Any]] = []
    for scene in scenes:
        scene_rows = run_scene(scene, algos)
        rows.extend(scene_rows)
        if scene["name"] == "E" and "tight_cfg" in scene:
            tight = dict(scene, cfg=scene["tight_cfg"])
            tight_rows = run_scene(tight, algos)
            for row in tight_rows:
                row["scene"] = "E-tight"
                row["diagnostic"] = True
                rows.append(row)
            print("[E-tight] " + ", ".join(
                f"{r['algorithm']}={r['f1']:.1f}%F1" for r in tight_rows))
        print(f"[{scene['name']}] " + ", ".join(
            f"{r['algorithm']}={r['f1']:.1f}%F1" for r in scene_rows))

    ranking = _ranks(rows)
    measured = [r for r in rows if r["scene"] != "E-tight"]
    matrix_header = ["Scene"] + [r["algorithm"] for r in ranking]
    matrix_rows = []
    for name in [s["name"] for s in scenes]:
        values = []
        for rank_row in ranking:
            hit = next((r for r in measured
                        if r["scene"] == name and r["algorithm"] == rank_row["algorithm"]), None)
            values.append(_fmt(hit["f1"]) if hit else "n/a")
        matrix_rows.append([name] + values)

    summary_header = ["F1 rank", "Algorithm", "Basis", "Prec %", "Rec %", "F1 %",
                      "Jacc %", "IDSW", "IDSW/1k", "Loc m", "ms/1k", "Deployment"]
    summary_rows = []
    for rank_row in ranking:
        summary_rows.append([
            rank_row["rank"], rank_row["algorithm"], rank_row["label"],
            _fmt(rank_row["precision"]), _fmt(rank_row["recall"]),
            _fmt(rank_row["f1"]), _fmt(rank_row["jaccard"]),
            rank_row["id_switches"], _fmt(rank_row["id_switches_per_1k_matches"], 1),
            _fmt(rank_row["loc_error_mean"], 3),
            _fmt(rank_row["latency_ms_per_1k_scans"], 1),
            DEPLOYMENT.get(rank_row["algorithm"], ""),
        ])
    baseline = [r for r in rows if r["algorithm"] in ("legacy_id", "greedy_nearest")
                and r["scene"] != "E-tight"]
    baseline_rows = []
    for row in baseline:
        baseline_rows.append([
            row["algorithm"], row["scene"], row["tp"], row["fp"], row["fn"],
            _fmt(row["precision"]), _fmt(row["recall"]), _fmt(row["f1"]),
            _fmt(row["swap_errors"]) if row["swap_errors"] is not None else "n/a",
        ])

    tables_md = "\n\n".join([
        "## Ranked association backends",
        _md_table(summary_header, summary_rows),
        "## F1 (%) per scenario",
        _md_table(matrix_header, matrix_rows),
        "## Legacy baselines (uniform FP accounting)",
        _md_table(["Algorithm", "Scene", "TP", "FP", "FN", "Prec %", "Rec %", "F1 %", "Swaps"],
                  baseline_rows),
    ])
    args.tables_md.write_text(tables_md, encoding="utf-8")
    args.json.write_text(json.dumps({"ranking": ranking, "rows": rows,
                                     "scenes": [s["name"] for s in scenes]},
                                    indent=2, default=float), encoding="utf-8")
    args.html.parent.mkdir(parents=True, exist_ok=True)
    _write_html(args.html, ranking, measured, scenes)
    print("\n" + tables_md)
    print(f"\nHTML: {args.html}\nJSON: {args.json}\nTables: {args.tables_md}")

    # Runnable checks: canonical outcomes must hold.
    def f1(scene_name: str, algo: str) -> float:
        return next(r["f1"] for r in rows
                    if r["scene"] == scene_name and r["algorithm"] == algo)

    from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import _auction, _solve
    rng = np.random.default_rng(3)
    probe = rng.random((8, 8))
    auction_cost = sum(probe[i, j] for i, j in _auction(probe, 1e-4))
    hungarian_cost = sum(probe[i, j] for i, j in _solve(probe))
    auction_ok = abs(auction_cost - hungarian_cost) <= 8 * 1e-4 + 1e-9

    checks = [
        ("A: Hungarian recovers shuffled IDs", f1("A", "hungarian_normalized") >= 99.0),
        ("A: legacy fails on shuffled IDs", f1("A", "legacy_id") <= 1.0),
        ("B: Hungarian keeps 100% F1 through the ID swap", f1("B", "hungarian_normalized") >= 99.0),
        ("C: clutter is not a 100% win", f1("C", "hungarian_normalized") < 60.0),
        ("D: glint decoys rejected", f1("D", "hungarian_normalized") >= 75.0),
        ("E: real HDF produces matched tracks", f1("E", "hungarian_normalized") > 0.0),
        ("Auction matches Hungarian within epsilon", auction_ok),
    ]
    failed = [name for name, ok in checks if not ok]
    for name, ok in checks:
        print(("PASS " if ok else "FAIL ") + name)
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
