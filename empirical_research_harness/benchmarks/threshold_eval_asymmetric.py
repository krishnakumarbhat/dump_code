"""Measure asymmetric X/Y tracker-KPI gate configurations on the real replay scenes.

The published sweep (``threshold_sweep_tracker_kpi.py``) assumes one position
gate for both axes.  The production gate is asymmetric (ΔX ≠ ΔY), so this
script measures:

  * 15 named configurations (legacy, deployed, candidate, one-axis sweeps),
  * the full 5 x 4 grid  ΔX in {0.5, 1.0, 1.5, 2.0, 3.0} m
    by ΔY in {0.5, 1.0, 1.5, 2.0} m  at ΔV = 0.5 m/s,

on the same 11 real replay scenes and the same backend
(``hungarian_normalized``) as the symmetric sweep, so the two artefacts are
directly comparable.

Usage:
    python empirical_research_harness/benchmarks/threshold_eval_asymmetric.py

Output:
    empirical_research_harness/benchmarks/hdf_track_out/threshold_asymmetric.json
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path
from typing import Any, Dict, List, Tuple

ROOT = Path(__file__).resolve().parents[2]
BENCH = ROOT / "empirical_research_harness" / "benchmarks"
sys.path.insert(0, str(BENCH))

OUT_PATH = BENCH / "hdf_track_out" / "threshold_asymmetric.json"

EPS = 1e-7  # keep values just above the hard gate to avoid float equality drops
ALGO = "hungarian_normalized"

XS = (0.5, 1.0, 1.5, 2.0, 3.0)
YS = (0.5, 1.0, 1.5, 2.0)
VEL = 0.5

CONFIGS: Tuple[Tuple[str, float, float, float, float], ...] = (
    ("legacy_1cm", 0.01, 0.01, 0.02, 0.02),
    ("current_1.5_1.0_0.5", 1.5, 1.0, 0.5, 0.5),
    ("candidate_3.0_2.0_0.5", 3.0, 2.0, 0.5, 0.5),
    ("x_0.5_y1.0_v0.5", 0.5, 1.0, 0.5, 0.5),
    ("x_1.0_y1.0_v0.5", 1.0, 1.0, 0.5, 0.5),
    ("x_2.0_y1.0_v0.5", 2.0, 1.0, 0.5, 0.5),
    ("x_3.0_y1.0_v0.5", 3.0, 1.0, 0.5, 0.5),
    ("x1.5_y0.25_v0.5", 1.5, 0.25, 0.5, 0.5),
    ("x1.5_y0.5_v0.5", 1.5, 0.5, 0.5, 0.5),
    ("x1.5_y1.5_v0.5", 1.5, 1.5, 0.5, 0.5),
    ("x1.5_y2.0_v0.5", 1.5, 2.0, 0.5, 0.5),
    ("x1.5_y1.0_v0.1", 1.5, 1.0, 0.1, 0.1),
    ("x1.5_y1.0_v0.25", 1.5, 1.0, 0.25, 0.25),
    ("x1.5_y1.0_v1.0", 1.5, 1.0, 1.0, 1.0),
    ("x1.5_y1.0_v2.0", 1.5, 1.0, 2.0, 2.0),
)

_SCENES: List[Tuple[str, Dict[str, Any], Dict[str, Any]]] | None = None


def scenes() -> List[Tuple[str, Dict[str, Any], Dict[str, Any]]]:
    """Load (and memoise per worker) the 11 real replay scene pairs."""
    global _SCENES
    if _SCENES is None:
        import threshold_sweep_tracker_kpi as sweep

        _SCENES = sweep.load_scenes()
    return _SCENES


def _measure(gate: Tuple[float, float, float, float]) -> Dict[str, Any]:
    """Score one gate configuration; returns micro-averaged totals."""
    import hdf_track_accuracy as acc

    tx, ty, tvx, tvy = gate
    started = time.perf_counter()
    per_scene = [
        {"scene": name, **acc.score(inp, out, ALGO, tx + EPS, tvx + EPS,
                                    gate_y=ty + EPS, vel_gate_y=tvy + EPS)}
        for name, inp, out in scenes()
    ]
    total = acc.micro(per_scene)
    total.update({"tx_m": tx, "ty_m": ty, "tvx_mps": tvx, "tvy_mps": tvy,
                  "elapsed_s": round(time.perf_counter() - started, 2)})
    return total


def _run_config(cfg: Tuple[str, float, float, float, float]) -> Dict[str, Any]:
    """Score one named configuration and keep the per-scene breakdown."""
    import hdf_track_accuracy as acc

    name, tx, ty, tvx, tvy = cfg
    per_scene = [
        {"scene": scene, **acc.score(inp, out, ALGO, tx + EPS, tvx + EPS,
                                     gate_y=ty + EPS, vel_gate_y=tvy + EPS)}
        for scene, inp, out in scenes()
    ]
    total = acc.micro(per_scene)
    total.update({"config": name, "tx_m": tx, "ty_m": ty,
                  "tvx_mps": tvx, "tvy_mps": tvy})
    return {"total": total, "scenes": per_scene}


def _run_grid_cell(cell: Tuple[float, float]) -> Dict[str, Any]:
    return _measure((cell[0], cell[1], VEL, VEL))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--workers", type=int, default=4)
    parser.add_argument("--out", type=Path, default=OUT_PATH)
    args = parser.parse_args()

    started = time.perf_counter()
    payload: Dict[str, Any] = {
        "generated": time.strftime("%Y-%m-%d %H:%M:%S"),
        "backend": ALGO,
        "grid_axes": {"xs": list(XS), "ys": list(YS), "vel_mps": VEL},
        "results": [],
        "grid": [],
    }

    with ProcessPoolExecutor(max_workers=args.workers) as pool:
        for i, result in enumerate(pool.map(_run_config, CONFIGS), 1):
            total = result["total"]
            print(f"[cfg {i}/{len(CONFIGS)}] {total['config']:<22} "
                  f"F1={total['f1_pct']:6.2f} P={total['precision_pct']:6.2f} "
                  f"R={total['recall_pct']:6.2f} p95={total['pos_err_p95_m']:.2f} m",
                  flush=True)
            payload["results"].append(result)

        cells = [(x, y) for x in XS for y in YS]
        for i, total in enumerate(pool.map(_run_grid_cell, cells), 1):
            print(f"[grid {i}/{len(cells)}] x={total['tx_m']} y={total['ty_m']} "
                  f"F1={total['f1_pct']:6.2f} p95={total['pos_err_p95_m']:.2f} m "
                  f"IDSW/1k={total['idsw_per_1k_matches']:.1f}", flush=True)
            payload["grid"].append(total)

    payload["elapsed_s"] = round(time.perf_counter() - started, 1)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(payload, indent=1), encoding="utf-8")

    assert len(payload["results"]) == len(CONFIGS), len(payload["results"])
    assert len(payload["grid"]) == len(XS) * len(YS), len(payload["grid"])
    print(f"WROTE {args.out} ({args.out.stat().st_size:,} bytes, "
          f"{payload['elapsed_s']} s)")


if __name__ == "__main__":
    main()
