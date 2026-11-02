"""Sweep the tracker-KPI association gate and pick the better threshold.

The tracker KPI scores replay fidelity with hard per-axis gates
(``vcs_*_threshold``).  Two candidates were in use: the legacy deterministic
replay gate (1 cm / 0.02 m/s) and the physical replay tolerance adopted in
commit ee94f3d (1.5 m / 0.5 m/s).  This script answers "which is better"
with data instead of opinion:

  * loads every real tracker pair available (HDF_TRACK replay scenes, both
    FC and RL streams, plus the edge_hdf depth-3 pairs),
  * scores the production backend (``hungarian_normalized``) on a full
    position x velocity gate grid, micro-averaged across all scenes,
  * measures the gate-independent inter-run noise floor and the spacing to
    the next distinct object, which bound the gate from below and above,
  * measures per-gate *sufficiency*: how many input objects have their
    position-nearest partner inside the gate (the physical ceiling any
    association can reach on this data),
  * picks the tightest gate on the sufficiency plateau that also sits inside
    the safe window ``[noise p99, spacing p10]``.

Why not plain max-F1: F1 is monotone in the gate (a looser gate can only
turn FN into TP), so the raw maximum is always the loosest, most permissive
gate - a KPI that matches everything verifies nothing.  The usable
threshold is the tightest gate that still keeps every physically pairable
object while staying below the distance to a *different* object.

Usage:
    python empirical_research_harness/benchmarks/threshold_sweep_tracker_kpi.py
    python empirical_research_harness/benchmarks/threshold_sweep_tracker_kpi.py --json-only
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Tuple

import numpy as np

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "ALL_KPI" / "KPI"))

from hdf_track_accuracy import (  # noqa: E402
    align_scans,
    align_scores,
    discover_pairs,
    load_stream,
    micro,
    score,
)
import edge_pair_accuracy as edge  # noqa: E402

TRACK_ROOT = Path(r"C:\Users\ouymc2\Downloads\HDF_TRACK\HDF_TRACK")
OUT = HERE / "hdf_track_out" / "threshold_sweep.json"
ALGO = "hungarian_normalized"
EPS = 1e-7  # KPI_VALIDATION_RULES adds this to every configured gate

# Gate grid in SI units.  0.01/0.02 = legacy production, 1.5/0.5 = current
# default; the grid brackets both and extends past them to expose the elbow.
POS_GATES_M = (0.01, 0.05, 0.1, 0.25, 0.5, 1.0, 1.5, 2.0, 3.0)
VEL_GATES_MPS = (0.02, 0.1, 0.25, 0.5, 1.0, 2.0)
INCUMBENTS = {"legacy_prod_1cm": (0.01, 0.02), "current_default_1.5m": (1.5, 0.5)}
SUFFICIENCY_SLACK_PP = 0.5  # plateau band around the sufficiency ceiling


def load_scenes() -> List[Tuple[str, Dict[str, np.ndarray], Dict[str, np.ndarray]]]:
    """Load every available (input, output) tracker pair as aligned arrays.

    Returns a list of ``(scene_name, in_tracks, out_tracks)`` where both track
    dicts are ``scans x slots`` arrays ready for ``associate_arrays``.
    """
    scenes: List[Tuple[str, Dict[str, np.ndarray], Dict[str, np.ndarray]]] = []
    if TRACK_ROOT.exists():
        for scene, ref_path, rep_path in discover_pairs(TRACK_ROOT):
            for hdf_root in ("FC", "RL"):
                ref = load_stream(ref_path, hdf_root)
                rep = load_stream(rep_path, hdf_root)
                if not ref or not rep:
                    continue
                rows_in, rows_out, _mode = align_scans(ref["ts"], rep["ts"])
                if len(rows_in) == 0:
                    continue
                scenes.append((
                    f"{scene}:{hdf_root}",
                    align_scores(ref, rows_in),
                    align_scores(rep, rows_out),
                ))
    for name, ref_path, rep_path in edge.discover(ROOT / "edge_hdf"):
        ref, rep = edge.load(ref_path), edge.load(rep_path)
        rows_ref, rows_rep, _mode = edge.align(ref, rep)
        scenes.append((f"edge:{name}", edge.subset(ref, rows_ref),
                       edge.subset(rep, rows_rep)))
    return scenes


def sweep(scenes: List[Tuple[str, Dict[str, np.ndarray], Dict[str, np.ndarray]]]
          ) -> List[Dict[str, Any]]:
    """Score every (position, velocity) gate over every scene, micro-averaged.

    Inputs: aligned scene list from :func:`load_scenes`.
    Outputs: one row per grid point with ``pos_m``, ``vel_mps`` and the
    micro-averaged metrics (``f1_pct``, ``precision_pct``, ``recall_pct``,
    ``pos_err_p95_m``, ``id_identity_pct``, ...).
    """
    rows: List[Dict[str, Any]] = []
    for pos in POS_GATES_M:
        for vel in VEL_GATES_MPS:
            started = time.perf_counter()
            scored = [score(inp, out, ALGO, pos + EPS, vel + EPS)
                      for _name, inp, out in scenes]
            row = {"pos_m": pos, "vel_mps": vel, **micro(scored)}
            row["elapsed_s"] = time.perf_counter() - started
            rows.append(row)
            print(f"  pos={pos:<5} vel={vel:<5} F1={row['f1_pct']:6.2f}  "
                  f"prec={row['precision_pct']:6.2f} rec={row['recall_pct']:6.2f}  "
                  f"pos_p95={row['pos_err_p95_m']:5.2f} m  "
                  f"id_same={row['id_identity_pct']:5.1f}%  "
                  f"idsw/1k={row['idsw_per_1k_matches']:5.1f}")
    return rows


def _valid_row(row: Dict[str, np.ndarray], i: int) -> np.ndarray:
    """Production slot validity (mirrors ``_valid_mask`` in the KPI backend)."""
    tid, x, y = row["track_id"][i], row["x_position"][i], row["y_position"][i]
    return (
        np.isfinite(tid) & (tid != 0)
        & np.isfinite(x) & np.isfinite(y)
        & (x > -100.0) & (y > -100.0)
        & ~((x == 0.0) & (y == 0.0))
        & (np.hypot(x, y) <= 160.0)
    )


def _partner_deltas(scenes: List[Tuple[str, Dict[str, np.ndarray], Dict[str, np.ndarray]]]
                    ) -> List[Dict[str, Any]]:
    """Per input object: deltas to its partner and to the next distinct object.

    The partner is the position-nearest valid output object of the same scan
    (the physically corresponding one).  Returned per scene as arrays:

      ``cheb``    per-axis |dx|,|dy| max to the partner (exact gate semantics)
      ``euc``     euclidean distance to the partner
      ``dvx/dvy`` per-axis velocity deltas to the partner
      ``spacing`` per-axis max distance to the *second* nearest output object
    """
    per_scene: List[Dict[str, Any]] = []
    for name, inp, out in scenes:
        n = min(len(inp["track_id"]), len(out["track_id"]))
        cheb, euc, dvx, dvy, spacing = ([] for _ in range(5))
        for r in range(n):
            mi, mo = _valid_row(inp, r), _valid_row(out, r)
            if not mi.any() or not mo.any():
                continue
            xi = np.stack([inp["x_position"][r][mi], inp["y_position"][r][mi]], axis=1)
            xo = np.stack([out["x_position"][r][mo], out["y_position"][r][mo]], axis=1)
            dx = np.abs(xi[:, None, 0] - xo[None, :, 0])
            dy = np.abs(xi[:, None, 1] - xo[None, :, 1])
            dist = np.hypot(dx, dy)
            order = np.argsort(dist, axis=1, kind="stable")
            rows = np.arange(len(xi))
            j0 = order[:, 0]
            cheb.append(np.maximum(dx[rows, j0], dy[rows, j0]))
            euc.append(dist[rows, j0])
            dvx.append(np.abs(inp["x_velocity"][r][mi] - out["x_velocity"][r][mo][j0]))
            dvy.append(np.abs(inp["y_velocity"][r][mi] - out["y_velocity"][r][mo][j0]))
            if order.shape[1] > 1:
                j1 = order[:, 1]
                spacing.append(np.maximum(dx[rows, j1], dy[rows, j1]))
        if cheb:
            per_scene.append({
                "scene": name,
                "cheb": np.concatenate(cheb), "euc": np.concatenate(euc),
                "dvx": np.concatenate(dvx), "dvy": np.concatenate(dvy),
                "spacing": np.concatenate(spacing) if spacing else np.array([]),
            })
    return per_scene


def _pct(data: np.ndarray, q: float) -> float:
    """Percentile of the finite entries; NaN when there is no data."""
    data = data[np.isfinite(data)]
    return float(np.percentile(data, q)) if data.size else float("nan")


def noise_and_spacing(per_scene: List[Dict[str, Any]]) -> Dict[str, Any]:
    """Gate-independent inter-run noise floor vs inter-object spacing.

    Inputs: per-scene partner deltas from :func:`_partner_deltas`.
    Outputs: pooled percentiles of the partner deltas (noise a correct gate
    must absorb) and of the second-nearest distance (how far distinct objects
    sit), plus per-scene noise percentiles.  The safe gate window is
    ``[noise p99, spacing p10]``.
    """
    pool = lambda key: np.concatenate([s[key] for s in per_scene if s[key].size])
    cheb, euc = pool("cheb"), pool("euc")
    dvx, dvy, spacing = pool("dvx"), pool("dvy"), pool("spacing")
    return {
        "n_objects": int(cheb.size),
        "noise_pos_cheb_m": {str(q): _pct(cheb, q) for q in (50, 90, 95, 99)},
        "noise_pos_euc_m": {str(q): _pct(euc, q) for q in (50, 90, 95, 99)},
        "noise_dvx_mps": {str(q): _pct(dvx, q) for q in (50, 90, 95, 99)},
        "noise_dvy_mps": {str(q): _pct(dvy, q) for q in (50, 90, 95, 99)},
        "spacing_pos_cheb_m": {str(q): _pct(spacing, q) for q in (5, 10, 50)},
        "per_scene": {
            s["scene"]: {"objects": int(s["cheb"].size),
                         "pos_p50_m": _pct(s["cheb"], 50),
                         "pos_p95_m": _pct(s["cheb"], 95),
                         "pos_p99_m": _pct(s["cheb"], 99)}
            for s in per_scene
        },
    }


def sufficiency(per_scene: List[Dict[str, Any]], grid: List[Dict[str, Any]]
                ) -> List[Dict[str, Any]]:
    """Fraction of input objects whose true partner fits inside each gate.

    Applies the exact per-axis gate semantics of the production backend to
    the partner deltas.  The maximum over the grid is the physical ceiling:
    input objects with no output counterpart at all (tracks born/dying
    differently between runs) can never be covered by any gate.

    Inputs: per-scene partner deltas and the scored gate grid.
    Outputs: one row per gate with ``pos_m``, ``vel_mps``, ``sufficient_pct``.
    """
    cheb = np.concatenate([s["cheb"] for s in per_scene if s["cheb"].size])
    dvx = np.concatenate([s["dvx"] for s in per_scene if s["dvx"].size])
    dvy = np.concatenate([s["dvy"] for s in per_scene if s["dvy"].size])
    known = np.isfinite(dvx) & np.isfinite(dvy)
    rows = []
    for g in grid:
        pos, vel = g["pos_m"], g["vel_mps"]
        ok = cheb <= pos
        ok_v = (~known) | ((dvx <= vel) & (dvy <= vel))
        rows.append({"pos_m": pos, "vel_mps": vel,
                     "sufficient_pct": 100.0 * float(np.mean(ok & ok_v))})
    return rows


def decide(grid: List[Dict[str, Any]], suff: List[Dict[str, Any]],
           noise: Dict[str, Any]) -> Dict[str, Any]:
    """Pick the threshold: tightest gate on the sufficiency plateau.

    Inputs: F1 grid, per-gate sufficiency rows, noise/spacing report.
    Outputs: the chosen ``pos_m``/``vel_mps`` with its F1, sufficiency,
    ``coverage_pct`` (F1 relative to grid max), the plateau size, the
    physically safe window ``[noise_p99, spacing_p10]`` and whether the pick
    sits inside it.
    """
    ceiling = max(s["sufficient_pct"] for s in suff)
    band = [s for s in suff if s["sufficient_pct"] >= ceiling - SUFFICIENCY_SLACK_PP]
    pick = min(band, key=lambda s: (s["pos_m"], s["vel_mps"]))
    grid_row = next(r for r in grid
                    if r["pos_m"] == pick["pos_m"] and r["vel_mps"] == pick["vel_mps"])
    best_f1 = max(r["f1_pct"] for r in grid)
    noise_p99 = noise["noise_pos_cheb_m"]["99"]
    spacing_p10 = noise["spacing_pos_cheb_m"]["10"]
    return {
        "pos_m": pick["pos_m"], "vel_mps": pick["vel_mps"],
        "sufficient_pct": pick["sufficient_pct"], "sufficiency_ceiling_pct": ceiling,
        "plateau_gates": len(band),
        "f1_pct": grid_row["f1_pct"], "best_f1_pct": best_f1,
        "coverage_pct": 100.0 * grid_row["f1_pct"] / best_f1 if best_f1 else 0.0,
        "pos_err_p95_m": grid_row["pos_err_p95_m"],
        "id_identity_pct": grid_row["id_identity_pct"],
        "safe_window_m": [noise_p99, spacing_p10],
        "inside_safe_window": bool(noise_p99 <= pick["pos_m"] <= spacing_p10),
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--json-only", action="store_true",
                    help="reuse the scored grid in threshold_sweep.json (still "
                         "reloads the HDFs for the noise/sufficiency analysis)")
    args = ap.parse_args()

    scenes = load_scenes()
    if not scenes:
        raise SystemExit("no tracker pairs found (HDF_TRACK root missing?)")
    print(f"[load] {len(scenes)} scene-streams: "
          + ", ".join(n for n, _i, _o in scenes))

    if args.json_only and OUT.exists():
        report = json.loads(OUT.read_text(encoding="utf-8"))
        grid = report["grid"]
        print(f"[sweep] reusing {len(grid)} scored gates from {OUT.name}")
    else:
        print(f"[sweep] {len(POS_GATES_M)}x{len(VEL_GATES_MPS)} gates x "
              f"{len(scenes)} scenes, backend={ALGO}")
        grid = sweep(scenes)
        report = {
            "generated": time.strftime("%Y-%m-%d %H:%M:%S"),
            "backend": ALGO,
            "scenes": [n for n, _i, _o in scenes],
            "pos_gates_m": list(POS_GATES_M),
            "vel_gates_mps": list(VEL_GATES_MPS),
            "grid": grid,
        }

    print("[noise] inter-run noise floor vs inter-object spacing ...")
    deltas = _partner_deltas(scenes)
    noise = noise_and_spacing(deltas)
    suff = sufficiency(deltas, grid)
    for s in suff:
        s["f1_pct"] = next(r["f1_pct"] for r in grid
                           if r["pos_m"] == s["pos_m"] and r["vel_mps"] == s["vel_mps"])
    pick = decide(grid, suff, noise)
    report.update({"noise": noise, "sufficiency": suff, "elbow": pick})
    report["incumbents"] = {
        name: next((r for r in grid
                    if r["pos_m"] == pos and r["vel_mps"] == vel), None)
        for name, (pos, vel) in INCUMBENTS.items()
    }
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(report, indent=1), encoding="utf-8")

    print("\n=== gate sweep (micro over all scenes) ===")
    print(f"{'pos m':>7} {'vel m/s':>8} {'F1 %':>7} {'suff %':>7} {'p95 m':>7} "
          f"{'id%':>6} {'idsw/1k':>8}")
    for g, s in zip(grid, suff):
        mark = ""
        if (g["pos_m"], g["vel_mps"]) == (pick["pos_m"], pick["vel_mps"]):
            mark = "  <- pick"
        elif any((g["pos_m"], g["vel_mps"]) == v for v in INCUMBENTS.values()):
            mark = "  <- incumbent"
        print(f"{g['pos_m']:>7} {g['vel_mps']:>8} {g['f1_pct']:>7.2f} "
              f"{s['sufficient_pct']:>7.2f} {g['pos_err_p95_m']:>7.2f} "
              f"{g['id_identity_pct']:>6.1f} {g['idsw_per_1k_matches']:>8.1f}{mark}")

    n = noise
    print("\n=== inter-run noise vs object spacing (partner = position-nearest) ===")
    print(f"objects    : {n['n_objects']}")
    print("noise  pos : " + "  ".join(f"p{q}={v:.3f} m" for q, v in
                                       n["noise_pos_cheb_m"].items()))
    print("noise  vel : " + "  ".join(f"p{q}={v:.3f} m/s" for q, v in
                                       n["noise_dvx_mps"].items()) + "  (vx)")
    print("spacing pos: " + "  ".join(f"p{q}={v:.2f} m" for q, v in
                                       n["spacing_pos_cheb_m"].items()))

    print(f"\nBEST F1      : {pick['best_f1_pct']:.2f}% at the loosest gate")
    print(f"PICK         : {pick['pos_m']} m / {pick['vel_mps']} m/s -> "
          f"F1 {pick['f1_pct']:.2f}% ({pick['coverage_pct']:.1f}% of grid max), "
          f"sufficiency {pick['sufficient_pct']:.2f}% of "
          f"{pick['sufficiency_ceiling_pct']:.2f}% ceiling "
          f"(plateau {pick['plateau_gates']} gates), "
          f"pos p95 {pick['pos_err_p95_m']:.2f} m, id-identity {pick['id_identity_pct']:.1f}%")
    print(f"SAFE WINDOW  : [{pick['safe_window_m'][0]:.2f} m, "
          f"{pick['safe_window_m'][1]:.2f} m] "
          f"(noise p99 .. spacing p10) -> pick inside: {pick['inside_safe_window']}")
    for name, row in report["incumbents"].items():
        if row:
            s = next(x for x in suff if x["pos_m"] == row["pos_m"]
                     and x["vel_mps"] == row["vel_mps"])
            print(f"INCUMBENT    : {name}: {row['pos_m']} m / {row['vel_mps']} m/s -> "
                  f"F1 {row['f1_pct']:.2f}%, sufficiency {s['sufficient_pct']:.2f}%, "
                  f"pos p95 {row['pos_err_p95_m']:.2f} m")
    print(f"\nJSON: {OUT}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
