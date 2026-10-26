"""Explain the replay accuracy number: is the loss alignment, or the gate?

For every input/replay pair this measures, without any gate:

* the nearest-neighbour position delta of the same physical scan (lag 0), and
  the same delta at lags -3..+3 to rule out a scan-alignment offset;
* the fraction of reference objects whose nearest replay object is within
  1 cm / 10 cm / 50 cm / 1.5 m;
* the delta restricted to objects that kept the same ``trkID``.

If lag 0 does not minimise the delta the logs are misaligned. If it does and the
median delta is ~0.1 m, then a 1 cm gate is simply the wrong tolerance.

Usage:
    python empirical_research_harness/benchmarks/hdf_alignment_diag.py
"""
from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any, Dict, List

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parents[1] / "ALL_KPI" / "KPI"))

from hdf_track_accuracy import DEFAULT_ROOT, align_scans, discover_pairs, load_stream, valid_mask  # noqa: E402

OUT = HERE / "hdf_track_out" / "alignment_diag.json"
LAGS = (-3, -2, -1, 0, 1, 2, 3)


def nn_delta(inp: Dict[str, np.ndarray], out: Dict[str, np.ndarray]) -> Dict[str, np.ndarray]:
    """Per-input-object nearest-neighbour distance, plus the same-ID distance.

    Args:
        inp: ``{"x", "y", "id"}`` arrays of shape ``(scans, slots)``.
        out: the same for the replay.

    Returns:
        ``{"nn": (n,), "same_id": (n,)}`` — ``same_id`` holds NaN where the
        reference ``trkID`` is absent from the replay scan.
    """
    n = len(inp["x"])
    nn: List[np.ndarray] = []
    same: List[np.ndarray] = []
    for s in range(n):
        mx = np.isfinite(inp["x"][s])
        mo = np.isfinite(out["x"][s])
        if not mx.any() or not mo.any():
            continue
        ax, ay, ai = inp["x"][s][mx], inp["y"][s][mx], inp["id"][s][mx]
        bx, by, bi = out["x"][s][mo], out["y"][s][mo], out["id"][s][mo]
        d = np.hypot(ax[:, None] - bx[None, :], ay[:, None] - by[None, :])
        nn.append(d.min(axis=1))
        best = d.argmin(axis=1)
        same.append(np.where(bi[best] == ai, d[np.arange(len(ai)), best], np.nan))
    return {"nn": np.concatenate(nn) if nn else np.zeros(0),
            "same_id": np.concatenate(same) if same else np.zeros(0)}


def pct(a: np.ndarray, q: float) -> float:
    """Percentile of the finite entries, 0 when empty."""
    a = a[np.isfinite(a)]
    return float(np.percentile(a, q)) if a.size else float("nan")


def main() -> int:
    pairs = discover_pairs(DEFAULT_ROOT)
    report: Dict[str, Any] = {"root": str(DEFAULT_ROOT), "lags": list(LAGS), "pairs": {}}
    for scene, ref_path, rep_path in pairs:
        ref, rep = load_stream(ref_path, "FC"), load_stream(rep_path, "FC")
        rows_in, rows_rep, mode = align_scans(ref["ts"], rep["ts"])
        keep = {k: ref["tracks"][k][rows_in] for k in ("x", "y", "trk_id")}
        inp = {"x": keep["x"], "y": keep["y"], "id": keep["trk_id"]}

        mask = valid_mask(rep["tracks"])
        base = {"x": rep["tracks"]["x"], "y": rep["tracks"]["y"],
                "id": rep["tracks"]["trk_id"]}
        masked = {k: np.where(mask, v, np.nan) for k, v in base.items()}
        masked = {k: v[rows_rep] for k, v in masked.items()}

        lag_rows = {}
        for lag in LAGS:
            a = slice(max(0, lag), len(rows_rep) + min(0, lag))
            b = slice(max(0, -lag), len(rows_rep) - max(0, lag))
            d = nn_delta({"x": inp["x"][a], "y": inp["y"][a], "id": inp["id"][a]},
                         {k: v[b] for k, v in masked.items()})["nn"]
            lag_rows[lag] = {"median_m": pct(d, 50), "mean_m": float(np.nanmean(d)) if d.size else float("nan")}

        d0 = nn_delta(inp, masked)
        nn, same = d0["nn"], d0["same_id"]
        report["pairs"][scene.split("_")[-1]] = {
            "input": ref_path.name, "replay": rep_path.name,
            "scans": int(len(rows_in)),
            "input_rows": int(len(ref["ts"])), "replay_rows": int(len(rep["ts"])),
            "alignment": mode,
            "scans_missing_in_replay": int(len(ref["ts"]) - len(rows_in)),
            "lag_median_m": {str(k): v["median_m"] for k, v in lag_rows.items()},
            "nn_median_m": pct(nn, 50), "nn_mean_m": float(np.nanmean(nn)),
            "nn_p90_m": pct(nn, 90), "nn_p99_m": pct(nn, 99),
            "frac_le": {str(t): float(np.mean(nn <= t)) for t in (0.01, 0.1, 0.5, 1.0, 1.5)},
            "same_id_frac": float(np.mean(np.isfinite(same))),
            "same_id_median_m": pct(same, 50),
            "objects": int(nn.size),
        }

    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(report, indent=1), encoding="utf-8")

    hdr = (f"{'pair':<6}{'scans':>6}{'miss':>5}{'lag-1':>8}{'lag0':>7}{'lag+1':>7}"
           f"{'p50':>7}{'p90':>7}{'p99':>7}{'<1cm%':>7}{'<10cm%':>7}{'<50cm%':>7}"
           f"{'<1.5m%':>7}{'sameID%':>8}")
    print(hdr)
    print("-" * len(hdr))
    for name, r in report["pairs"].items():
        f = r["frac_le"]
        print(f"{name:<6}{r['scans']:>6}{r['scans_missing_in_replay']:>5}"
              f"{r['lag_median_m']['-1']:>8.3f}{r['lag_median_m']['0']:>7.3f}"
              f"{r['lag_median_m']['1']:>7.3f}"
              f"{r['nn_median_m']:>7.3f}{r['nn_p90_m']:>7.3f}{r['nn_p99_m']:>7.3f}"
              f"{100 * f['0.01']:>7.2f}{100 * f['0.1']:>7.2f}{100 * f['0.5']:>7.2f}"
              f"{100 * f['1.5']:>7.2f}{100 * r['same_id_frac']:>8.2f}")
    print(f"\nJSON: {OUT}")
    best = [n for n, r in report["pairs"].items()
            if min(r["lag_median_m"], key=lambda k: r["lag_median_m"][k]) == "0"]
    assert len(best) == len(report["pairs"]), f"lag 0 is not the best alignment for {len(best)} pairs"
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
