"""Score the depth-3 tracker pairs (``*_HDF_Report``) against the reference log.

Those logs keep the tracker object list three groups deep at
``03_TrackerInfo/Tracker_Output/AllObjects`` (60 datasets, 295 x 128), which the
production ``KPIHDFParser`` cannot reach because it stops at depth 2.  This
loader goes straight to the group and scores the same association backends used
for the replay logs, so both schemas are comparable in one report.

Usage:
    python empirical_research_harness/benchmarks/edge_pair_accuracy.py
"""
from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any, Dict, List, Tuple

import numpy as np

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "ALL_KPI" / "KPI"))

from hdf_track_accuracy import GATES, micro, score  # noqa: E402

EDGE_ROOT = ROOT / "edge_hdf"
OUT = HERE / "hdf_track_out" / "edge_pairs.json"
OBJECT_GROUP = "03_TrackerInfo/Tracker_Output/AllObjects"
TIME_GROUP = "03_TrackerInfo/Tracker_Input/CoreInfo/time_us"
# Depth-3 field names -> association engine keys.
FIELD_MAP = {
    "track_id": "trkID",
    "x_position": "vcs_xposn",
    "y_position": "vcs_yposn",
    "x_velocity": "vcs_xvel",
    "y_velocity": "vcs_yvel",
    "f_moving": "f_moving",
    "length": "len1",
    "width": "wid1",
    "heading": "vcs_heading",
}
SUFFIXES = ("_CDC", "_out")


def discover(root: Path) -> List[Tuple[str, Path, Path]]:
    """Pair ``X.h5`` with ``X_CDC.h5`` / ``X_out.h5`` where both hold a tracker list."""
    import h5py

    groups: Dict[str, Dict[str, Path]] = {}
    for path in sorted(root.rglob("*.h5")):
        try:
            with h5py.File(path, "r") as f:
                if OBJECT_GROUP not in f:
                    continue
        except OSError:
            continue
        suffix = next((s for s in SUFFIXES if path.stem.endswith(s)), "")
        groups.setdefault(path.stem[: -len(suffix)] if suffix else path.stem,
                          {})[suffix] = path
    pairs = []
    for stem, files in sorted(groups.items()):
        ref = files.get("", next(iter(files.values())))
        for suffix in SUFFIXES:
            if suffix in files and files[suffix] != ref:
                pairs.append((f"{stem}{suffix}", ref, files[suffix]))
    return pairs


def load(path: Path) -> Dict[str, Any]:
    """Read the depth-3 object list and the scan clock."""
    import h5py

    with h5py.File(path, "r") as f:
        g = f[OBJECT_GROUP]
        return {
            "path": str(path),
            "scans": int(g["trkID"].shape[0]),
            "slots": int(g["trkID"].shape[1]),
            "fields": {k: g[v][...] for k, v in FIELD_MAP.items()},
            "time_us": f[TIME_GROUP][...].astype(np.int64) if TIME_GROUP in f else None,
        }


def align(ref: Dict[str, Any], rep: Dict[str, Any]) -> Tuple[np.ndarray, np.ndarray, str]:
    """Align on the core clock when it exists and is monotonic, else by index."""
    t_ref, t_rep = ref.get("time_us"), rep.get("time_us")
    if (t_ref is not None and t_rep is not None and len(t_ref) == ref["scans"]
            and len(t_rep) == rep["scans"] and np.all(np.diff(t_ref) >= 0)
            and np.all(np.diff(t_rep) >= 0)):
        common = np.intersect1d(t_ref, t_rep)
        if len(common) >= 0.5 * min(len(t_ref), len(t_rep)):
            return (np.searchsorted(t_ref, common), np.searchsorted(t_rep, common), "core clock")
    n = min(ref["scans"], rep["scans"])
    return np.arange(n), np.arange(n), "scan index"


def subset(stream: Dict[str, Any], rows: np.ndarray) -> Dict[str, np.ndarray]:
    """Slice to the aligned rows; ``associate_arrays`` wants ``scans x slots``."""
    return {k: v[rows] for k, v in stream["fields"].items()}


def main() -> int:
    pairs = discover(EDGE_ROOT)
    report: Dict[str, Any] = {"object_group": OBJECT_GROUP, "field_map": FIELD_MAP,
                              "pairs": {}, "summary": {}}
    for name, ref_path, rep_path in pairs:
        ref, rep = load(ref_path), load(rep_path)
        rows_ref, rows_rep, mode = align(ref, rep)
        in_tracks, out_tracks = subset(ref, rows_ref), subset(rep, rows_rep)
        sentinels = {
            "ref_zero_x": int((ref["fields"]["x_position"] == 0.0).sum()),
            "ref_below_minus100": int((ref["fields"]["x_position"] < -100.0).sum()),
            "ref_zero_id": int((ref["fields"]["track_id"] == 0).sum()),
        }
        entry = {
            "reference": ref_path.name, "replay": rep_path.name,
            "scans": int(len(rows_ref)), "slots": ref["slots"],
            "alignment": mode, "sentinels": sentinels,
            "ref_valid": int((ref["fields"]["track_id"][rows_ref] > 0).sum()),
            "rep_valid": int((rep["fields"]["track_id"][rows_rep] > 0).sum()),
            "gates": {},
        }
        for gate_key, _label, gate, vel in GATES:
            scored = [score(in_tracks, out_tracks, algo, gate, vel) for algo in
                      ("legacy_id", "hungarian_normalized", "mahalanobis", "gospa", "obb_auction")]
            entry["gates"][gate_key] = {"algorithms": {s["algorithm"]: s for s in scored},
                                        "micro": micro(scored)}
        report["pairs"][name] = entry

    for gate_key, _l, _g, _v in GATES:
        rows = [p["gates"][gate_key]["micro"] | {"tp": p["gates"][gate_key]["algorithms"]
                ["hungarian_normalized"]["tp"]} for p in report["pairs"].values()]
        if rows:
            report["summary"][gate_key] = micro(rows)

    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(report, indent=1), encoding="utf-8")
    for gate_key, label, _g, _v in GATES:
        if not report["pairs"]:
            break
        first = next(iter(report["pairs"].values()))
        print(f"\n=== edge_hdf depth-3 pairs — {label} ===")
        for algo, m in sorted(first["gates"][gate_key]["algorithms"].items(),
                              key=lambda kv: -kv[1]["f1_pct"]):
            print(f"  {algo:<22} F1={m['f1_pct']:6.2f} TP={m['tp']:6d} FP={m['fp']:6d} "
                  f"FN={m['fn']:6d} pos_p95={m['pos_err_p95_m']:.2f}m")
    print(f"\nJSON: {OUT}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
