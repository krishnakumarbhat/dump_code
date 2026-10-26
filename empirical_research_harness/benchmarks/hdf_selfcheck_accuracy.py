"""Control experiment: score input-against-input so the replay numbers have a floor.

For every paired log the same association backend is run on four comparisons:

    self        input vs input          (identical arrays: the matcher's ceiling)
    self+1      input vs input shifted by one scan  (temporal sensitivity)
    cross       input of this scene vs input of the next scene  (unrelated data)
    replay      input vs the ``_rR*`` output        (the real KPI)

If ``self`` is not ~100 % the metric is broken; if ``cross`` is not ~0 % the gate
is too loose.  Whatever sits between them is the only part the replay can move.

Usage:
    python empirical_research_harness/benchmarks/hdf_selfcheck_accuracy.py
"""
from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any, Dict, List, Tuple

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parents[1] / "ALL_KPI" / "KPI"))

from hdf_track_accuracy import (  # noqa: E402
    DEFAULT_ROOT, align_scans, align_scores, discover_pairs, load_stream, score,
)

OUT = HERE / "hdf_track_out" / "selfcheck.json"
ALGOS = ("hungarian_normalized", "mahalanobis", "legacy_id")


def rows_for(stream: Dict[str, Any], rows: np.ndarray) -> Dict[str, np.ndarray]:
    """Slice a stream to the given scan rows for the association engine."""
    return align_scores(stream, rows)


def control_block(in_tracks: Dict[str, np.ndarray], out_tracks: Dict[str, np.ndarray],
                  scan_note: str) -> Dict[str, Any]:
    """Score one comparison at both gate settings for the chosen backends."""
    return {
        scan_note: {
            gate_key: {a: score(in_tracks, out_tracks, a, gate, vel)
                       for a in ALGOS}
            for gate_key, _l, gate, vel in _GATES
        }
    }


def _gates() -> Tuple:
    from hdf_track_accuracy import GATES
    return GATES


_GATES = _gates()


def run(root: Path) -> Dict[str, Any]:
    """Evaluate self, self+1, cross and replay comparisons for every pair."""
    pairs = discover_pairs(root)
    report: Dict[str, Any] = {"root": str(root), "pairs": {}, "pooled": {}}
    loaded = {}
    for scene, ref_path, rep_path in pairs:
        ref = load_stream(ref_path, "FC")
        rep = load_stream(rep_path, "FC")
        rows_in, rows_rep, mode = align_scans(ref["ts"], rep["ts"])
        loaded[scene] = (ref, rep, rows_in, rows_rep)

    scenes = list(loaded)
    for i, scene in enumerate(scenes):
        ref, rep, rows_in, rows_rep = loaded[scene]
        base_in = rows_for(ref, rows_in)
        base_out = rows_for(rep, rows_rep)
        entry: Dict[str, Any] = {"alignment": "exact/nearest", "scans": int(len(rows_in))}

        entry["self"] = {g: {a: score(base_in, base_in, a, p, v) for a in ALGOS}
                         for g, _l, p, v in _GATES}

        # Same log, one scan later: motion per 50 ms shows up as position error.
        shift_in = rows_for(ref, rows_in[1:])
        shift_in2 = rows_for(ref, rows_in[:-1])
        entry["self_plus_1"] = {g: {a: score(shift_in, shift_in2, a, p, v) for a in ALGOS}
                                for g, _l, p, v in _GATES if g == "replay"}

        # Different scene, same backend: unrelated objects must not match.
        other_scene = scenes[(i + 1) % len(scenes)]
        n = min(len(rows_in), len(loaded[other_scene][2]))
        cross = rows_for(ref, rows_in[:n])
        cross_other = rows_for(loaded[other_scene][0], loaded[other_scene][2][:n])
        entry["cross"] = {g: {a: score(cross, cross_other, a, p, v) for a in ALGOS}
                          for g, _l, p, v in _GATES if g == "replay"}

        entry["replay"] = {g: {a: score(base_in, base_out, a, p, v) for a in ALGOS}
                           for g, _l, p, v in _GATES}
        entry["cross_with"] = other_scene.split("_")[-1]
        _seed_entry(entry, scene)
        report["pairs"][scene] = entry

    # Pooled: sum TP/FP/FN per comparison so percentages are object-weighted.
    for comp in ("self", "self_plus_1", "cross", "replay"):
        for gate in ("replay", "prod"):
            for algo in ALGOS:
                rows = [p[comp][gate][algo] for p in report["pairs"].values()
                        if comp in p and gate in p[comp]]
                if not rows:
                    continue
                tp = sum(r["tp"] for r in rows)
                fp = sum(r["fp"] for r in rows)
                fn = sum(r["fn"] for r in rows)
                prec, rec = (tp / (tp + fp) if tp + fp else 0.0,
                             tp / (tp + fn) if tp + fn else 0.0)
                report["pooled"].setdefault(comp, {}).setdefault(gate, {})[algo] = {
                    "tp": tp, "fp": fp, "fn": fn,
                    "f1_pct": 200 * prec * rec / (prec + rec) if prec + rec else 0.0,
                    "pos_mean_m": float(np.mean([r["pos_err_mean_m"] for r in rows])),
                }
    return report


def _seed_entry(entry: Dict[str, Any], scene: str) -> None:
    """Keep the scene key inside the entry so the table is self-describing."""
    entry["scene"] = scene.split("_")[-1]


def table(report: Dict[str, Any]) -> str:
    """Fixed-width control table for the console."""
    head = (f"{'pair':<6}{'scans':>6}{'self@1cm':>10}{'self@1.5m':>11}"
            f"{'self+1@1.5m':>13}{'cross@1.5m':>12}{'replay@1cm':>12}"
            f"{'replay@1.5m':>13}{'legacy@1.5m':>13}")
    lines = [head, "-" * len(head)]
    for scene, e in report["pairs"].items():
        def g(comp: str, gate: str, algo: str = "hungarian_normalized") -> float:
            try:
                return e[comp][gate][algo]["f1_pct"]
            except KeyError:
                return float("nan")
        lines.append(
            f"{e['scene']:<6}{e['scans']:>6}{g('self', 'prod'):>10.2f}"
            f"{g('self', 'replay'):>11.2f}{g('self_plus_1', 'replay'):>13.2f}"
            f"{g('cross', 'replay'):>12.2f}{g('replay', 'prod'):>12.2f}"
            f"{g('replay', 'replay'):>13.2f}{g('replay', 'replay', 'legacy_id'):>13.2f}"
        )
    pooled = report["pooled"]
    lines.append("-" * len(head))
    for comp, gate, algo, label in (
        ("self", "prod", "hungarian_normalized", "pooled self @1cm"),
        ("self", "replay", "hungarian_normalized", "pooled self @1.5m"),
        ("self_plus_1", "replay", "hungarian_normalized", "pooled self+1 @1.5m"),
        ("cross", "replay", "hungarian_normalized", "pooled cross @1.5m"),
        ("replay", "prod", "hungarian_normalized", "pooled replay @1cm"),
        ("replay", "replay", "hungarian_normalized", "pooled replay @1.5m"),
        ("replay", "replay", "legacy_id", "pooled legacy @1.5m"),
        ("replay", "replay", "mahalanobis", "pooled mahalanobis @1.5m"),
    ):
        m = pooled[comp][gate][algo]
        lines.append(f"{label:<32} F1={m['f1_pct']:6.2f}  "
                     f"TP={m['tp']:6d} FP={m['fp']:6d} FN={m['fn']:6d}  "
                     f"pos={m['pos_mean_m']:.3f} m")
    return "\n".join(lines)


def main() -> int:
    report = run(DEFAULT_ROOT)
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(report, indent=1), encoding="utf-8")
    print(table(report))
    self_f1 = report["pooled"]["self"]["replay"]["hungarian_normalized"]["f1_pct"]
    cross_f1 = report["pooled"]["cross"]["replay"]["hungarian_normalized"]["f1_pct"]
    assert self_f1 > 99.9, f"self comparison must be exact, got {self_f1}"
    # 20-30 % is the chance floor: the scenes share a road, so guardrails and
    # static clutter land on the same coordinates even in unrelated logs.
    assert cross_f1 < 30.0, f"unrelated logs must stay near chance, got {cross_f1}"
    replay_f1 = report["pooled"]["replay"]["replay"]["hungarian_normalized"]["f1_pct"]
    assert replay_f1 > 3 * cross_f1, "replay result must beat the chance floor clear"
    print(f"\nJSON: {OUT}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
