"""Extract tracker streams from HDF replay logs to JSON and score KPI accuracy.

A replay log folder holds two files per scene:

    <scene>_b05.h5             reference (recorded) tracker output
    <scene>_b05_rR<params>.h5  replay output under a different parameter set

Scan rows are aligned by the object-list header timestamp (exact match, ~384 of
395 scans per scene).  Every valid tracker object of every aligned scan is
exported to JSON, then each association backend of
``tracker_matching_kpi_v2`` is scored against the reference log.

"Accuracy" here is one-to-one association agreement with the reference log
(TP/FP/FN -> precision/recall/F1/Jaccard/ID switches) plus the physical
position/velocity error of each matched pair -- the same definition the
production tracker KPI uses, with no labelled ground truth needed.

Usage:
    python empirical_research_harness/benchmarks/hdf_track_accuracy.py
    python empirical_research_harness/benchmarks/hdf_track_accuracy.py --all-fields
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Sequence, Tuple

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
KPI_ROOT = ROOT / "ALL_KPI" / "KPI"
if str(KPI_ROOT) not in sys.path:
    sys.path.insert(0, str(KPI_ROOT))

from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import (  # noqa: E402
    AssociationConfig,
    associate_arrays,
)

DEFAULT_ROOT = Path(r"C:\Users\ouymc2\Downloads\HDF_TRACK\HDF_TRACK")
DEFAULT_OUT = ROOT / "empirical_research_harness" / "benchmarks" / "hdf_track_out"
DESKTOP = Path.home() / "Desktop"

# Scenario A (hard gates at the configured 1 cm) is kept as a diagnostic because
# the production thresholds are ~15x tighter than the inter-run spread of a
# tracker replay; Scenario B is the physical tolerance for comparing two runs.
GATES: List[Tuple[str, str, float, float]] = [
    ("prod", "production gates 1 cm / 0.02 m/s", 0.01, 0.02),
    ("replay", "replay tolerance 1.5 m / 0.5 m/s", 1.5, 0.5),
]
ALGORITHMS = [
    "legacy_id",
    "greedy_nearest",
    "hungarian_normalized",
    "mahalanobis",
    "gospa",
    "multi_scan",
    "obb_auction",
]
# Curated object columns: everything the tracker KPI and an ID-quality review
# need.  --all-fields dumps the remaining 59 object_* datasets instead.
COLUMNS = [
    "trk_id", "uid", "status", "x", "y", "vx", "vy",
    "f_moving", "len", "wid", "hdg", "exist_p", "ndets", "cls", "src",
]
OBJECT_DATASETS = {
    "trk_id": "object_trkID",
    "uid": "object_unique_id",
    "status": "object_status",
    "x": "object_xposn",
    "y": "object_yposn",
    "vx": "object_xvel",
    "vy": "object_yvel",
    "f_moving": "object_f_moving",
    "len": "object_length",
    "wid": "object_width",
    "hdg": "object_heading",
    "exist_p": "object_existence_probability",
    "ndets": "object_ndets",
    "cls": "object_object_class",
    "src": "object_sensor_src",
}
TRACK_KEYS = (
    "track_id", "x_position", "y_position", "x_velocity", "y_velocity",
    "f_moving", "length", "width", "heading",
)
PAIR_RE = re.compile(r"^(?P<scene>.+?)_b05(?P<replay>_rR\d+)?\.h5$")


def discover_pairs(root: Path) -> List[Tuple[str, Path, Path]]:
    """Return ``(scene, reference, replay)`` for every complete HDF pair."""
    refs: Dict[str, Path] = {}
    replays: Dict[str, Path] = {}
    for path in sorted(root.glob("*.h5")):
        m = PAIR_RE.match(path.name)
        if not m:
            continue
        (replays if m["replay"] else refs)[m["scene"]] = path
    return [(s, refs[s], replays[s]) for s in sorted(refs.keys() & replays.keys())]


def _read_group(f: Any, group: str, all_fields: bool) -> Dict[str, np.ndarray]:
    """Read one ``*_Log`` group into ``{short_name: array}``."""
    keys = list(f[group].keys()) if all_fields else list(OBJECT_DATASETS.values())
    out: Dict[str, np.ndarray] = {}
    for ds in keys:
        if ds not in f[group]:
            continue
        short = next((k for k, v in OBJECT_DATASETS.items() if v == ds), ds)
        out[short] = f[group][ds][...]
    return out


def load_stream(path: Path, root: str = "FC", all_fields: bool = False) -> Dict[str, Any]:
    """Load tracker objects, tracker info and detection counts from one HDF."""
    import h5py

    with h5py.File(path, "r") as f:
        if f"{root}/OBJECT_LIST_STREAM/F360_Object_Log" not in f:
            return {}
        obj = _read_group(f, f"{root}/OBJECT_LIST_STREAM/F360_Object_Log", all_fields)
        header = f"{root}/OBJECT_LIST_STREAM/F360_Log_Header"
        ts = f[f"{header}/f360header_data_timstamp_us"][...].astype(np.int64)
        tinfo = {
            k: f[f"{root}/TRACKER_INFO_STREAM/Tracker_Info_Log_Stream/{k}"][...]
            for k in f[f"{root}/TRACKER_INFO_STREAM/Tracker_Info_Log_Stream"].keys()
            if k != "unused"
        }
        det = {}
        dgroup = f"{root}/PROCESSED_DETECTION_STREAM/F360_Detection_Log"
        if dgroup in f:
            det = {
                "ts": f[f"{root}/PROCESSED_DETECTION_STREAM/F360_Log_Header/"
                        "f360header_data_timstamp_us"][...].astype(np.int64),
                "n_valid": (f[f"{dgroup}/detection_position_x"][...] != 0.0).sum(axis=1),
                "n_ok": f[f"{dgroup}/detection_f_ok_to_use"][...].sum(axis=1),
            }
    n_scans = int(ts.shape[0])
    tracks = {k: obj[k].astype(float) for k in COLUMNS + sorted(set(obj) - set(COLUMNS))}
    n_slots = int(obj["trk_id"].shape[1])
    return {
        "root": root, "path": str(path), "scans": n_scans, "slots": n_slots,
        "ts": ts, "tracks": tracks, "tracker_info": tinfo, "detections": det,
    }


def valid_mask(tracks: Dict[str, np.ndarray]) -> np.ndarray:
    """Non-zero track id, real (non-zero, non-sentinel) position."""
    tid, x, y = tracks["trk_id"], tracks["x"], tracks["y"]
    return (tid > 0) & np.isfinite(x) & np.isfinite(y) & (x > -100.0) & (y > -100.0)


def to_json_stream(stream: Dict[str, Any], columns: Sequence[str]) -> Dict[str, Any]:
    """Columnar per-scan export; empty slots are dropped, not padded."""
    tracks, mask = stream["tracks"], valid_mask(stream["tracks"])
    rounds = {"exist_p": 4, "x": 3, "y": 3, "vx": 3, "vy": 3, "len": 3, "wid": 3, "hdg": 3}
    scans = []
    for row in range(stream["scans"]):
        sel = np.flatnonzero(mask[row])
        entry: Dict[str, Any] = {"i": row, "ts": int(stream["ts"][row])}
        if "tracker_index" in stream["tracker_info"]:
            entry["trk"] = int(stream["tracker_info"]["tracker_index"][row])
        entry["objs"] = [
            [round(float(tracks[c][row, s]), rounds.get(c, 0)) for c in columns]
            for s in sel
        ]
        scans.append(entry)
    return {
        "columns": list(columns),
        "scans": scans,
        "valid_objects": int(mask.sum()),
        "tracker_info": {
            k: (v.tolist() if v.dtype != np.uint64 else [int(x) for x in v])
            for k, v in stream["tracker_info"].items() if v.ndim == 1
        },
        "detections": {
            "ts": [int(x) for x in stream["detections"].get("ts", [])],
            "n_valid": [int(x) for x in stream["detections"].get("n_valid", [])],
            "n_ok": [int(x) for x in stream["detections"].get("n_ok", [])],
        },
    }


def align_scores(stream: Dict[str, Any], rows: Sequence[int]) -> Dict[str, np.ndarray]:
    """Build the ``associate_arrays`` input for the aligned scan rows."""
    tracks, mask = stream["tracks"], valid_mask(stream["tracks"])
    out = {k: np.full((len(rows), stream["slots"]), np.nan) for k in TRACK_KEYS}
    for r, row in enumerate(rows):
        sel = np.flatnonzero(mask[row])
        out["track_id"][r, : len(sel)] = tracks["trk_id"][row, sel]
        out["x_position"][r, : len(sel)] = tracks["x"][row, sel]
        out["y_position"][r, : len(sel)] = tracks["y"][row, sel]
        out["x_velocity"][r, : len(sel)] = tracks["vx"][row, sel]
        out["y_velocity"][r, : len(sel)] = tracks["vy"][row, sel]
        out["f_moving"][r, : len(sel)] = tracks["f_moving"][row, sel]
        out["length"][r, : len(sel)] = tracks["len"][row, sel]
        out["width"][r, : len(sel)] = tracks["wid"][row, sel]
        out["heading"][r, : len(sel)] = tracks["hdg"][row, sel]
    return out


def align_scans(ref_ts: np.ndarray, rep_ts: np.ndarray,
                tol_us: int = 25000) -> Tuple[np.ndarray, np.ndarray, str]:
    """Align rows across two logs: exact timestamp, else nearest within ``tol_us``.

    RL scan headers are out of order and the replay clock drifts, so an exact
    match set can be empty; nearest one-to-one matching then recovers the scans.
    """
    oi = np.argsort(ref_ts, kind="stable")
    oo = np.argsort(rep_ts, kind="stable")
    si, so = ref_ts[oi], rep_ts[oo]
    common = np.intersect1d(si, so)
    if len(common) >= 0.5 * min(len(si), len(so)):
        return (oi[np.searchsorted(si, common)], oo[np.searchsorted(so, common)], "exact")
    idx = np.searchsorted(si, so).clip(0, len(si) - 1)
    cands = []
    for k, j in enumerate(idx):
        for c in (j - 1, j, j + 1):
            if 0 <= c < len(si):
                cands.append((abs(int(si[c]) - int(so[k])), c, k))
    cands.sort()
    used: set = set()
    keep: List[Tuple[int, int]] = []
    for _gap, c, k in cands:
        if c in used or abs(int(si[c]) - int(so[k])) > tol_us:
            continue
        used.add(c)
        keep.append((c, k))
    keep.sort()
    return (oi[[c for c, _ in keep]], oo[[k for _, k in keep]], f"nearest<={tol_us // 1000}ms")


def id_switches(matched: Sequence[Dict[str, Any]]) -> int:
    """Extra output IDs seen per reference track (canonical MOT IDSW)."""
    seen: Dict[int, set] = {}
    for m in matched:
        seen.setdefault(int(m["input_track_id"]), set()).add(int(m["output_track_id"]))
    return int(sum(len(v) - 1 for v in seen.values()))


def score(in_tracks: Dict[str, np.ndarray], out_tracks: Dict[str, np.ndarray],
          algorithm: str, gate: float, vel_gate: float) -> Dict[str, Any]:
    """Run one association backend and reduce it to KPI-grade metrics."""
    cfg = AssociationConfig(
        tx=gate, ty=gate, tvx=vel_gate, tvy=vel_gate, algorithm=algorithm
    )
    t0 = time.perf_counter()
    res = associate_arrays(in_tracks, out_tracks, cfg)
    elapsed = time.perf_counter() - t0
    if not res:  # zero aligned scans: nothing to score
        return {k: 0 for k in ("tp", "fp", "fn", "id_switches")} | {
            "algorithm": algorithm, "scans": 0,
            **{k: 0.0 for k in ("precision_pct", "recall_pct", "f1_pct",
                                "jaccard_pct", "idsw_per_1k_matches", "id_identity_pct",
                                "vel_err_mean_mps", "fmoving_agree_pct",
                                "ms_per_1000_scans", "pos_err_mean_m",
                                "pos_err_p95_m")},
        }
    scans = max(int(res.get("scans_compared", 0)), 1)
    tp, fp, fn = res["total_matches"], res["total_fp"], res["total_fn"]
    pos = np.asarray(res["position_errors"], dtype=float)
    vel = np.asarray(res["velocity_errors"], dtype=float)
    ids = id_switches(res["matched_tracks"])
    same_id = [m for m in res["matched_tracks"]
               if m["input_track_id"] == m["output_track_id"]]
    prec = tp / (tp + fp) if tp + fp else 0.0
    rec = tp / (tp + fn) if tp + fn else 0.0
    return {
        "algorithm": algorithm,
        "scans": scans,
        "tp": int(tp), "fp": int(fp), "fn": int(fn),
        "precision_pct": 100.0 * prec,
        "recall_pct": 100.0 * rec,
        "f1_pct": 200.0 * prec * rec / (prec + rec) if prec + rec else 0.0,
        "jaccard_pct": 100.0 * tp / (tp + fp + fn) if tp + fp + fn else 0.0,
        "id_switches": ids,
        "idsw_per_1k_matches": 1000.0 * ids / tp if tp else 0.0,
        "id_identity_pct": 100.0 * len(same_id) / tp if tp else 0.0,
        "pos_err_mean_m": float(pos.mean()) if pos.size else float("nan"),
        "pos_err_p95_m": float(np.percentile(pos, 95)) if pos.size else float("nan"),
        "vel_err_mean_mps": float(vel.mean()) if vel.size else float("nan"),
        "fmoving_agree_pct": 100.0 * res["fmoving_agree"] / res["fmoving_cooccur"]
        if res["fmoving_cooccur"] else 0.0,
        "ms_per_1000_scans": 1000.0 * elapsed / scans,
    }


def micro(scored: Sequence[Dict[str, Any]]) -> Dict[str, Any]:
    """Aggregate per-scene metrics into one micro-averaged row."""
    tp = sum(s["tp"] for s in scored)
    fp = sum(s["fp"] for s in scored)
    fn = sum(s["fn"] for s in scored)
    prec = tp / (tp + fp) if tp + fp else 0.0
    rec = tp / (tp + fn) if tp + fn else 0.0
    ids = sum(s["id_switches"] for s in scored)
    errs = [s["pos_err_mean_m"] for s in scored if np.isfinite(s["pos_err_mean_m"])]
    p95 = [s["pos_err_p95_m"] for s in scored if np.isfinite(s["pos_err_p95_m"])]
    return {
        "algorithm": scored[0]["algorithm"],
        "scenes": len(scored),
        "scans": sum(s["scans"] for s in scored),
        "tp": tp, "fp": fp, "fn": fn,
        "precision_pct": 100.0 * prec,
        "recall_pct": 100.0 * rec,
        "f1_pct": 200.0 * prec * rec / (prec + rec) if prec + rec else 0.0,
        "jaccard_pct": 100.0 * tp / (tp + fp + fn) if tp + fp + fn else 0.0,
        "id_switches": ids,
        "idsw_per_1k_matches": 1000.0 * ids / tp if tp else 0.0,
        "id_identity_pct": sum(s["id_identity_pct"] * s["tp"] for s in scored) / tp
        if tp else 0.0,
        "pos_err_mean_m": float(np.mean(errs)) if errs else float("nan"),
        "pos_err_p95_m": float(np.max(p95)) if p95 else float("nan"),
        "vel_err_mean_mps": float(np.mean([s["vel_err_mean_mps"] for s in scored])),
        "fmoving_agree_pct": sum(s["fmoving_agree_pct"] * s["tp"] for s in scored) / tp
        if tp else 0.0,
        "ms_per_1000_scans": float(np.mean([s["ms_per_1000_scans"] for s in scored])),
    }


def run(root: Path, outdir: Path, all_fields: bool, max_range: float) -> Dict[str, Any]:
    """Export every HDF to JSON, score every pair, write JSON + Markdown."""
    pairs = discover_pairs(root)
    if not pairs:
        raise SystemExit(f"no <scene>_b05.h5 / <scene>_b05_rR*.h5 pairs under {root}")
    outdir.mkdir(parents=True, exist_ok=True)
    export_dir = outdir / "json"
    export_dir.mkdir(exist_ok=True)

    report: Dict[str, Any] = {
        "root": str(root),
        "max_range_m": max_range,
        "gates": {k: {"label": lbl, "pos_m": p, "vel_mps": v} for k, lbl, p, v in GATES},
        "pairs": [], "per_scene": {}, "summary": {}, "export": [],
    }

    for scene, ref_path, rep_path in pairs:
        scene_entry: Dict[str, Any] = {"reference": ref_path.name,
                                       "replay": rep_path.name, "streams": {}}
        for hdf_root in ("FC", "RL"):
            ref = load_stream(ref_path, hdf_root, all_fields)
            rep = load_stream(rep_path, hdf_root, all_fields)
            if not ref or not rep:
                continue
            for role, stream in (("input", ref), ("output", rep)):
                payload = {
                    "file": Path(stream["path"]).name, "scene": scene,
                    "role": role, "root": hdf_root,
                    "scans": stream["scans"], "slots": stream["slots"],
                    **to_json_stream(stream, COLUMNS if not all_fields
                                     else sorted(stream["tracks"])),
                }
                name = f"{scene}_{role}_{hdf_root}.json"
                (export_dir / name).write_text(
                    json.dumps(payload, separators=(",", ":")), encoding="utf-8"
                )
                report["export"].append({"file": name, "scans": stream["scans"],
                                         "valid_objects": payload["valid_objects"]})

            # RL scan headers can be out of order, so sort before aligning.
            rows_in, rows_out, alignment = align_scans(ref["ts"], rep["ts"])
            mask_in = valid_mask(ref["tracks"])[rows_in]
            mask_out = valid_mask(rep["tracks"])[rows_out]
            far = int((mask_in & (np.hypot(ref["tracks"]["x"][rows_in],
                                           ref["tracks"]["y"][rows_in]) > max_range)).sum()
                      + (mask_out & (np.hypot(rep["tracks"]["x"][rows_out],
                                              rep["tracks"]["y"][rows_out]) > max_range)).sum())
            stream_entry = {
                "aligned_scans": int(len(rows_in)),
                "alignment": alignment,
                "ref_scans": ref["scans"], "rep_scans": rep["scans"],
                "objects_clipped_by_range": far,
                "inputs_total": int(mask_in.sum()), "outputs_total": int(mask_out.sum()),
                "gates": {},
            }
            in_tracks = align_scores(ref, rows_in)
            out_tracks = align_scores(rep, rows_out)
            for gate_key, _label, gate, vel_gate in GATES:
                scored = [
                    score(in_tracks, out_tracks, algo, gate, vel_gate)
                    for algo in ALGORITHMS
                ] if max_range == 160.0 else []
                if not scored:  # non-production range: only the primary backend
                    scored = [score(in_tracks, out_tracks, "hungarian_normalized", gate, vel_gate)]
                stream_entry["gates"][gate_key] = {
                    "algorithms": {s["algorithm"]: s for s in scored},
                    "micro": micro(scored),
                }
            scene_entry["streams"][hdf_root] = stream_entry
        report["per_scene"][scene] = scene_entry

    # Cross-scene summary per stream (FC is the primary front-centre coverage).
    for stream in ("FC", "RL"):
        for gate_key, _label, _g, _v in GATES:
            summary = {}
            for algo in ALGORITHMS:
                rows = [
                    report["per_scene"][s]["streams"][stream]["gates"][gate_key]["algorithms"][algo]
                    for s in report["per_scene"]
                    if stream in report["per_scene"][s]["streams"]
                    and algo in report["per_scene"][s]["streams"][stream]["gates"][gate_key]["algorithms"]
                ]
                if rows and sum(r["tp"] for r in rows):
                    summary[algo] = micro(rows)
            if summary:
                report["summary"].setdefault(stream, {})[gate_key] = summary

    (outdir / "accuracy.json").write_text(json.dumps(report, indent=1), encoding="utf-8")
    (outdir / "accuracy.md").write_text(render_markdown(report), encoding="utf-8")
    write_desktop_html(report)
    return report


def alignment_note(report: Dict[str, Any], stream: str) -> str:
    """Describe how scans were paired for a stream (drives the confidence)."""
    modes = sorted({
        st["streams"][stream].get("alignment", "exact")
        for st in report["per_scene"].values() if stream in st["streams"]
    })
    if modes == ["exact"]:
        return "scan alignment: exact header timestamp (high confidence)"
    return ("scan alignment: " + ", ".join(modes)
            + " (replay clock drifts; F1 is a lower bound)")


def render_markdown(report: Dict[str, Any]) -> str:
    """Markdown tables: per-gate ranking per stream, per-scene F1."""
    lines = [
        "# Real HDF replay accuracy (input vs output)",
        "",
        f"Reference: `{report['root']}` — {len(report['per_scene'])} scene pairs, "
        f"range gate {report['max_range_m']:.0f} m.",
        "",
        "`accuracy` = one-to-one association agreement with the reference log.",
        "`pos p95` is the worst scene's 95th percentile; latencies are per 1000 scans.",
        "",
    ]
    for stream, gates in report["summary"].items():
        lines += [f"# Stream {stream}", "", alignment_note(report, stream), ""]
        for gate_key, rows in gates.items():
            label = report["gates"][gate_key]["label"]
            lines += [f"## {stream} — {label}", "",
                      "| Algorithm | TP | FP | FN | Prec % | Rec % | F1 % | Jaccard % | IDSW | IDSW/1k | pos p95 m | ms/1k scans |",
                      "|---|---|---|---|---|---|---|---|---|---|---|---|"]
            for algo, m in sorted(rows.items(), key=lambda kv: -kv[1]["f1_pct"]):
                lines.append(
                    f"| {algo} | {m['tp']} | {m['fp']} | {m['fn']} | {m['precision_pct']:.2f} | "
                    f"{m['recall_pct']:.2f} | {m['f1_pct']:.2f} | {m['jaccard_pct']:.2f} | "
                    f"{m['id_switches']} | {m['idsw_per_1k_matches']:.1f} | "
                    f"{m['pos_err_p95_m']:.3f} | {m['ms_per_1000_scans']:.1f} |"
                )
            lines.append("")
    for stream in report["summary"]:
        scenes = [s for s in report["per_scene"] if stream in report["per_scene"][s]["streams"]]
        if not scenes:
            continue
        lines += [f"## F1 % per scene — {stream} (replay gate)", "",
                  "| Scene | aligned scans | " + " | ".join(ALGORITHMS) + " |",
                  "|---|---|" + "---|" * len(ALGORITHMS)]
        for scene in scenes:
            st = report["per_scene"][scene]["streams"][stream]
            g = st["gates"]["replay"]["algorithms"]
            cells = " | ".join(f"{g[a]['f1_pct']:.1f}" for a in ALGORITHMS if a in g)
            lines.append(f"| {scene.split('_')[-1]} | {st['aligned_scans']} | {cells} |")
        lines.append("")
    return "\n".join(lines)


def write_desktop_html(report: Dict[str, Any]) -> None:
    """Ranked accuracy tables (FC + RL) on the Desktop; self-contained."""
    sections = []
    for stream, gates in report["summary"].items():
        rows = []
        for algo, m in sorted(gates["replay"].items(), key=lambda kv: -kv[1]["f1_pct"]):
            rows.append(
                "<tr><td>{}</td><td>{:.2f}</td><td>{:.2f}</td><td>{:.2f}</td>"
                "<td>{}</td><td>{:.1f}</td><td>{:.3f}</td></tr>".format(
                    algo, m["precision_pct"], m["recall_pct"], m["f1_pct"],
                    m["id_switches"], m["idsw_per_1k_matches"], m["pos_err_p95_m"]
                )
            )
        scanned = gates["replay"]["hungarian_normalized"]["scans"]
        sections.append(
            f"<h2>Stream {stream} — {scanned} aligned scans</h2>\n"
            f"<p class=note>{alignment_note(report, stream)}</p>\n"
            "<table><thead><tr><th>Algorithm</th><th>Precision %</th><th>Recall %</th>"
            "<th>F1 %</th><th>ID switches</th><th>IDSW / 1k</th><th>pos p95 m</th>"
            f"</tr></thead><tbody>{''.join(rows)}</tbody></table>"
        )
    html = f"""<!doctype html><meta charset="utf-8">
<title>Tracker KPI accuracy on real HDF replay</title>
<style>body{{font:14px/1.5 system-ui,sans-serif;margin:32px;color:#111}}
table{{border-collapse:collapse;margin-bottom:28px}}th,td{{border:1px solid #ccc;padding:6px 10px;text-align:right}}
th{{background:#f3f4f6}}td:first-child,th:first-child{{text-align:left}}
tr:nth-child(1) td{{font-weight:600}}.note{{color:#555;margin-top:-8px}}</style>
<h1>Tracker KPI accuracy on real HDF replay</h1>
<p>{len(report['per_scene'])} scene pairs, replay gate 1.5 m / 0.5 m/s, range {report['max_range_m']:.0f} m.
Reference = recorded log; scored = replay output.</p>
{''.join(sections)}
<p>Legacy <code>(scan, trkID)</code> matching scores ~2% because a replay renumbers
<code>trkID</code>; ID-independent association recovers the same physical objects.
Under the production 1 cm gate the Euclidean backends collapse, so the replay
tolerance is the config that actually measures tracker agreement.</p>
"""
    (DESKTOP / "tracker_kpi_real_hdf_accuracy.html").write_text(html, encoding="utf-8")


def self_check(report: Dict[str, Any]) -> List[str]:
    """Guard the facts that make the numbers meaningful."""
    checks = []
    replay = report["summary"]["FC"]["replay"]
    prod = report["summary"]["FC"]["prod"]
    legacy = replay["legacy_id"]
    assert legacy["f1_pct"] < 5.0, f"legacy ID matching should collapse, got {legacy['f1_pct']:.2f}"
    checks.append(f"PASS legacy (scan,trkID) F1 {legacy['f1_pct']:.2f}% < 5%")
    best = max(replay.values(), key=lambda m: m["f1_pct"])
    assert best["tp"] > 0 and legacy["tp"] / best["tp"] < 0.05, "legacy recovers too many objects"
    checks.append(f"PASS legacy TP {legacy['tp']} = "
                  f"{100.0 * legacy['tp'] / best['tp']:.1f}% of {best['algorithm']} TP")
    assert best["f1_pct"] > 85.0, f"best backend only {best['f1_pct']:.2f} F1"
    checks.append(f"PASS best backend {best['algorithm']} F1 {best['f1_pct']:.2f}%")
    assert prod["hungarian_normalized"]["f1_pct"] < replay["hungarian_normalized"]["f1_pct"]
    checks.append("PASS 1 cm gates under-score a replay vs 1.5 m tolerance")
    return checks


def main(argv: Sequence[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    ap.add_argument("--out", type=Path, default=DEFAULT_OUT)
    ap.add_argument("--all-fields", action="store_true",
                    help="export every object_* dataset, not the curated columns")
    ap.add_argument("--max-range", type=float, default=160.0)
    args = ap.parse_args(argv)

    report = run(args.root, args.out, args.all_fields, args.max_range)
    for stream, gates in report["summary"].items():
        for gate_key, rows in gates.items():
            print(f"\n=== {stream} — {report['gates'][gate_key]['label']} ===")
            print(f"{'algorithm':<22}{'TP':>8}{'FP':>8}{'FN':>8}{'Prec%':>8}"
                  f"{'Rec%':>8}{'F1%':>8}{'Jac%':>8}{'IDSW':>7}{'p95m':>8}")
            for algo, m in sorted(rows.items(), key=lambda kv: -kv[1]["f1_pct"]):
                print(f"{algo:<22}{m['tp']:>8}{m['fp']:>8}{m['fn']:>8}"
                      f"{m['precision_pct']:>8.2f}{m['recall_pct']:>8.2f}{m['f1_pct']:>8.2f}"
                      f"{m['jaccard_pct']:>8.2f}{m['id_switches']:>7}{m['pos_err_p95_m']:>8.3f}")
    print()
    for line in self_check(report):
        print(line)
    print(f"\nJSON: {args.out / 'accuracy.json'}")
    print(f"Export: {args.out / 'json'}")
    print(f"Tables: {args.out / 'accuracy.md'}")
    print(f"HTML: {DESKTOP / 'tracker_kpi_real_hdf_accuracy.html'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
