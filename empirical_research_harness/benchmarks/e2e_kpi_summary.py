"""Collect the end-to-end UDP KPI tracker block from every ``_kpi_worker.py`` run.

Each ``<label>.json`` produced by ``ALL_KPI/edge_hdf_test/_kpi_worker.py`` holds
the real KPI payload (``metrics.per_sensor.<sensor>.tracker``), so this is the
only place where the full-pipeline numbers are read. It writes
``hdf_track_out/e2e_runs.json`` and prints one row per run.

Usage:
    python empirical_research_harness/benchmarks/e2e_kpi_summary.py [--dir DIR]
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

HERE = Path(__file__).resolve().parent
DEFAULT_DIR = HERE.parents[1] / "ALL_KPI" / "edge_hdf_test" / "out_e2e_abs"
OUT = HERE / "hdf_track_out" / "e2e_runs.json"


def collect(run_dir: Path) -> List[Dict[str, Any]]:
    """Read every JSON in ``run_dir`` that carries a tracker KPI block."""
    runs = []
    for path in sorted(run_dir.glob("*.json")):
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        for sensor, blocks in (payload.get("metrics", {}).get("per_sensor") or {}).items():
            tracker = blocks.get("tracker")
            if not isinstance(tracker, dict) or "summary_stats" not in tracker:
                continue
            stats, thr = tracker["summary_stats"], tracker.get("thresholds", {})
            runs.append({
                "run": path.stem,
                "label": payload.get("label"),
                "sensor": sensor,
                "algorithm": tracker.get("association_algorithm"),
                "matching_mode": tracker.get("matching_mode"),
                "pos_tol_m": thr.get("vcs_xposn_threshold"),
                "vel_tol_ms": thr.get("vcs_xvel_threshold"),
                "max_valid_distance_m": thr.get("max_valid_distance"),
                "scans": stats.get("scans_compared"),
                "tp": stats.get("total_matches"),
                "fp": stats.get("total_fp"),
                "fn": stats.get("total_fn"),
                "precision_pct": stats.get("precision"),
                "recall_pct": stats.get("recall"),
                "f1_pct": stats.get("f1"),
                "jaccard_pct": stats.get("jaccard"),
                "scans_with_matches": stats.get("scans_with_matches"),
            })
    return runs


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default=str(DEFAULT_DIR))
    run_dir = Path(ap.parse_args().dir)
    runs = collect(run_dir)
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps({"source": str(run_dir), "runs": runs}, indent=1),
                   encoding="utf-8")
    head = "{:<12}{:<24}{:>8}{:>8}{:>8}{:>8}{:>8}{:>7}{:>7}{:>7}{:>7}".format(
        "run", "algorithm", "pos_tol", "vel_tol", "TP", "FP", "FN", "P%", "R%", "F1%", "J%")
    print(head)
    print("-" * len(head))
    for r in runs:
        print("{:<12}{:<24}{:>8.2f}{:>8.2f}{:>8}{:>8}{:>8}{:>7.2f}{:>7.2f}{:>7.2f}{:>7.2f}".format(
            r["run"], str(r["algorithm"]), r["pos_tol_m"] or 0, r["vel_tol_ms"] or 0,
            r["tp"], r["fp"], r["fn"], r["precision_pct"], r["recall_pct"],
            r["f1_pct"], r["jaccard_pct"]))
    print(f"\nJSON: {OUT}  ({len(runs)} runs)")
    assert runs, f"no tracker KPI blocks found under {run_dir}"
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
