"""Run the UDP tracker KPI with one selectable matcher version.

    python main.py <input.h5> <output.h5> [v1..v6] [--sensor FC] [--out DIR]

With no version the default is ``v2`` (normalized Hungarian). v1 is the legacy
``(scan_index, trkID)`` matcher; v3..v6 are the other association backends.
Prints one summary line and writes ``<out>/<label>.json`` with the full
``kpi_results`` (TP/FP/FN, precision, recall, F1, Jaccard, per-scan rows).

The HDF streams are read through the production wrapper, so the numbers are the
same ones the KPI report shows — this CLI only removes the need to edit config
or set environment variables to switch matcher.
"""
from __future__ import annotations

import argparse
import importlib
import json
import sys
import tempfile
from pathlib import Path
from typing import Any, Dict

KPI_ROOT = Path(__file__).resolve().parents[2]
if str(KPI_ROOT) not in sys.path:
    sys.path.insert(0, str(KPI_ROOT))

VERSIONS = ("v1", "v2", "v3", "v4", "v5", "v6")
DEFAULT_VERSION = "v2"


def load_tracker_streams(in_path: str, out_path: str, sensor: str,
                         workdir: str) -> Dict[str, Any]:
    """Parse both HDFs and return ``{"input": model, "output": model}``.

    Args:
        in_path: reference HDF (recorded run).
        out_path: replay HDF (``_rR*`` output).
        sensor: top-level sensor group to read, e.g. ``FC``.
        workdir: where the wrapper may drop its diagnostics.

    Returns:
        The ``TRACKER_STREAM`` entry handed to a ``track_vN`` module.

    Raises:
        SystemExit: when the pair carries no tracker stream for the sensor.
    """
    import UDP_KPI.a_persistence_layer.hdf_wrapper as hw

    held: Dict[str, Any] = {}

    class _Capture(hw.KpiDataModel):
        """Keep the parsed streams alive: the wrapper clears them afterwards."""

        def __init__(self, data, sensor_id):
            held["data"] = dict(data)
            super().__init__(data, sensor_id)

    hw.KpiDataModel = _Capture
    cfg = hw.KPIProcessingConfig(sensor, in_path, out_path, workdir, "log", "KPI")
    hw.KPIHDFWrapper(cfg).parse()

    streams = held.get("data") or {}
    tracker = streams.get("TRACKER_STREAM")
    if not (isinstance(tracker, dict) and {"input", "output"} <= set(tracker)):
        raise SystemExit(
            f"no TRACKER_STREAM for sensor {sensor} "
            f"(resolved streams: {sorted(streams) or 'none'})"
        )
    return tracker


def main(argv: list[str] | None = None) -> int:
    """Parse args, run the selected matcher, print and persist the KPI."""
    ap = argparse.ArgumentParser(description="UDP tracker KPI with a selectable matcher.")
    ap.add_argument("input", help="reference HDF, e.g. *_b05.h5")
    ap.add_argument("output", help="replay HDF, e.g. *_b05_rR00070005.h5")
    ap.add_argument("version", nargs="?", default=DEFAULT_VERSION, choices=VERSIONS,
                    help=f"matcher version (default {DEFAULT_VERSION} = Hungarian)")
    ap.add_argument("--sensor", default="FC", help="sensor group (default FC)")
    ap.add_argument("--out", default=str(Path(tempfile.gettempdir()) / "kpi_track_cli"),
                    help="output directory for the JSON")
    ap.add_argument("--label", default=None, help="output file stem")
    ap.add_argument("--stdout", action="store_true", help="print the full JSON")
    args = ap.parse_args(argv)

    mod = importlib.import_module(f"UDP_KPI.c_business_layer.track_{args.version}")
    Path(args.out).mkdir(parents=True, exist_ok=True)
    streams = load_tracker_streams(args.input, args.output, args.sensor, args.out)

    result = mod.process_tracker_kpi(streams["input"], streams["output"],
                                     args.sensor, "TRACKER_STREAM")
    kpi = result.get("kpi_results") or {}
    stats = kpi.get("summary_stats") or {}
    if not stats:
        print(f"{args.version} {mod.ALGORITHM}: no tracker KPI produced "
              f"({kpi.get('error') or 'empty result'})")
        return 1

    label = args.label or f"{Path(args.input).stem}_{args.version}"
    payload = {
        "version": args.version,
        "algorithm": mod.ALGORITHM,
        "label_text": mod.LABEL,
        "sensor": args.sensor,
        "input": str(args.input),
        "output": str(args.output),
        "matching_mode": kpi.get("matching_mode"),
        "thresholds": kpi.get("thresholds"),
        "summary_stats": stats,
        "html_content": result.get("html_content", ""),
    }
    out_file = Path(args.out) / f"{label}.json"
    out_file.write_text(json.dumps(payload, indent=1, default=str), encoding="utf-8")

    print(f"{args.version} ({mod.ALGORITHM}) {args.sensor}: "
          f"scans={stats.get('scans_compared')} "
          f"TP={stats.get('total_matches')} FP={stats.get('total_fp')} FN={stats.get('total_fn')} "
          f"P={stats.get('precision'):.2f}% R={stats.get('recall'):.2f}% "
          f"F1={stats.get('f1'):.2f}% J={stats.get('jaccard'):.2f}% "
          f"gate={kpi.get('thresholds', {}).get('vcs_xposn_threshold')}m")
    print(f"JSON: {out_file}")
    if args.stdout:
        print(json.dumps(payload["summary_stats"], indent=1, default=str))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
