"""Recursive HDF5 tracker-schema catalog (read-only).

Purpose: enumerate every dataset under the given roots via Group.visititems with no
depth limit, extract tracker-relevant schema facts, and classify/pair files.
Inputs: root directories (defaults below); writes hdf_schema_catalog.json.
Outputs: JSON catalog + printed compact table. Never mutates raw HDF files.
"""
from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any

import h5py
import numpy as np

HERE = Path(__file__).resolve().parent
ROOTS = [
    Path(r"C:\Users\ouymc2\Desktop\dump_code\edge_hdf"),
    Path(r"C:\Users\ouymc2\Downloads\HDF_TRACK\HDF_TRACK"),
]
OUT = HERE / "hdf_schema_catalog.json"

TRACKER_RE = re.compile(r"track|trk|object|detection", re.IGNORECASE)
SCAN_RE = re.compile(r"timestamp|timestep|scan_index|tracker_index|index", re.IGNORECASE)
FIELD_RE = re.compile(r"OBJECT_LIST|Tracker_Output|\b(?:Track|Object|Tracker)\w*", re.IGNORECASE)


def _num(v: Any) -> float | int | None:
    """Coerce scalar to JSON-safe number, else None."""
    if isinstance(v, (np.integer, int)):
        return int(v)
    if isinstance(v, (np.floating, float)):
        f = float(v)
        return None if (np.isnan(f) or np.isinf(f)) else f
    return None


def _depth(path: str) -> int:
    """Dataset path depth, /a/b -> 2."""
    return path.count("/")


def _stem(name: str) -> str:
    """Strip replay/report suffixes so raw and replayed files pair."""
    s = name
    for _ in range(2):
        s = re.sub(r"_rR\d+$", "", s)
        s = re.sub(r"_(?:CDC|HDF_Report)$", "", s)
    return s


def _classify(path: Path, dsets: list[str]) -> str:
    """Assign one role per file from filename and dataset layout."""
    if re.search(r"_rR\d+", path.stem):
        return "tracker_replay"
    if any("Tracker_Output" in d or "OBJECT_LIST" in d.upper() for d in dsets):
        return "tracker_report"
    low = {d.lower() for d in dsets}
    has_tracker = any(TRACKER_RE.search(d) for d in low)
    if has_tracker:
        return "tracker_reference"
    return "detection_only" if any("detect" in d for d in low) else "other"


def _find_key(group: h5py.Group, *names: str) -> h5py.Dataset | None:
    """Locate the first child dataset whose basename matches any name."""
    for n in names:
        for k in group:
            if k.lower() == n.lower() and isinstance(group[k], h5py.Dataset):
                return group[k]
    return None


def scan_file(path: Path) -> dict[str, Any]:
    """Visit every dataset in one file and collect schema facts."""
    out: dict[str, Any] = {
        "file": str(path), "role": "other", "tracker_datasets": [],
        "scan_datasets": [], "max_depth": 0, "depth3_tracker": 0,
        "tracker_streams": 0, "n_datasets": 0,
    }
    with h5py.File(path, "r") as f:
        dsets: list[tuple[str, h5py.Dataset]] = []
        f.visititems(lambda n, o: dsets.append((n, o)) if isinstance(o, h5py.Dataset) else None)
        out["n_datasets"] = len(dsets)
        out["max_depth"] = max((_depth(n) for n, _ in dsets), default=0)

        for name, ds in dsets:
            if SCAN_RE.search(name.rsplit("/", 1)[-1]):
                out["scan_datasets"].append({"path": "/" + name, "shape": list(ds.shape), "dtype": str(ds.dtype)})
            if not TRACKER_RE.search(name):
                continue
            entry: dict[str, Any] = {"path": "/" + name, "shape": list(ds.shape), "dtype": str(ds.dtype)}
            if _depth(name) >= 3:
                out["depth3_tracker"] += 1
            if ds.dtype.kind in "biuf" and ds.size:
                try:
                    arr = np.asarray(ds[...])
                    if arr.dtype.kind in "biuf":
                        entry["min"], entry["max"] = _num(np.nanmin(arr)), _num(np.nanmax(arr))
                        entry["first3"] = [_num(x) for x in arr.ravel()[:3]]
                        if arr.ndim == 2 and arr.shape[0] > 50:
                            entry["n_nonzero_rows"] = int(np.count_nonzero(np.any(arr != 0, axis=1)))
                            hdr = _find_key(f, "timestamp", "timestep", "scan_index", "tracker_index", "index")
                            if hdr is not None and hdr.size >= 2:
                                d = np.diff(np.asarray(hdr).ravel())
                                entry["row_stride"] = _num(np.median(d))
                                entry["row_stride_source"] = "/" + hdr.name.lstrip("/")
                            else:
                                # timestamp headers often sit in the owning group; report absence explicitly
                                entry["row_stride"] = None
                except Exception as exc:  # pragma: no cover - corrupt/exotic dataset
                    entry["error"] = str(exc)
            out["tracker_datasets"].append(entry)

        out["tracker_streams"] = len(out["tracker_datasets"])
        out["role"] = _classify(path, [n for n, _ in dsets])
    return out


def main() -> dict[str, Any]:
    """Scan all roots, build catalog, dump JSON, print summary table."""
    files: list[dict[str, Any]] = []
    for root in ROOTS:
        if not root.exists():
            continue
        for p in sorted(root.rglob("*.h5")):
            try:
                files.append(scan_file(p))
            except Exception as exc:
                files.append({"file": str(p), "error": str(exc), "role": "unreadable",
                              "tracker_datasets": [], "depth3_tracker": 0, "tracker_streams": 0})

    by_stem: dict[tuple[str, str], dict[str, Path]] = {}
    for rec in files:
        p = Path(rec["file"])
        by_stem.setdefault((p.parent.as_posix(), _stem(p.stem)), {})[rec["role"]] = p
    pairs = [
        {"input": str(v.get("tracker_reference", next(iter(v.values())))), "output": str(v[k]),
         "streams_found": sum(r["tracker_streams"] for r in files if Path(r["file"]) in v.values())}
        for (_, _), v in by_stem.items()
        if v.get("tracker_replay") and len(v) > 1
        for k in ("tracker_replay",)
    ]

    schema: dict[str, list[dict[str, str]]] = {}
    for rec in files:
        p = Path(rec["file"])
        try:
            with h5py.File(p, "r") as f:
                names: list[str] = []
                f.visititems(lambda n, o: names.append(n) if isinstance(o, h5py.Dataset) else None)
                for n in names:
                    for fld in FIELD_RE.findall(n.rsplit("/", 1)[-1]):
                        schema.setdefault(fld, [])
                        if not any(e["file"] == str(p) and e["path"] == "/" + n for e in schema[fld]):
                            schema[fld].append({"file": str(p), "path": "/" + n})
        except Exception:
            continue

    cat = {
        "roots": [str(r) for r in ROOTS],
        "files": files,
        "pairs": pairs,
        "schema": schema,
        "depth3_tracker_datasets": sum(r.get("depth3_tracker", 0) for r in files),
        "notes": [
            "visititems used with no depth cap; production parser cap of depth 2 (root->group->leaf) "
            "cannot reach 03_TrackerInfo/Tracker_Output/AllObjects (depth 2 group, datasets at depth 3).",
            "row_stride is median diff of the nearest timestamp/index dataset found at file root.",
        ],
    }
    OUT.write_text(json.dumps(cat, indent=2), encoding="utf-8")

    print(f"{'file':58} {'d3trk':>6} {'streams':>8} {'pairs':>6}")
    paired = {Path(pr["input"]).resolve() for pr in pairs} | {Path(pr["output"]).resolve() for pr in pairs}
    for rec in files:
        p = Path(rec["file"]).resolve()
        npr = 1 if p in paired else 0
        print(f"{p.name[:58]:58} {rec.get('depth3_tracker', 0):>6} {rec.get('tracker_streams', 0):>8} {npr:>6}")
    print(f"\nfiles={len(files)} tracker_ds={sum(r.get('tracker_streams', 0) for r in files)} "
          f"depth3={cat['depth3_tracker_datasets']} pairs={len(pairs)}")
    return cat


if __name__ == "__main__":
    main()
