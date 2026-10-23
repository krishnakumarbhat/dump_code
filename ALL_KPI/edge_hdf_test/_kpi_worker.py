"""KPI worker: run the CAN or UDP KPI on one HDF pair and dump JSON + HTML.

Runs as a subprocess with cwd set to the owning package, because
`can_interactive_plot` and `UDP_KPI` both expose top-level module names
(`a_persistence_layer`, `b_data_storage`, ...) that would collide in one
interpreter.

Usage:  python _kpi_worker.py <can|udp> <input.h5> <output.h5> <outdir> <label>
Writes: <outdir>/<label>.json  and  <outdir>/<label>.html
"""
from __future__ import annotations

import json
import os
import sys
import traceback


def run_can(in_path: str, out_path: str, outdir: str, label: str):
    pkg = os.path.dirname(os.path.abspath(__file__))
    for cand in (pkg, os.path.join(pkg, "..", "KPI", "can_interactive_plot")):
        cand = os.path.abspath(cand)
        if os.path.isdir(cand) and cand not in sys.path:
            sys.path.insert(0, cand)
    os.chdir(os.path.abspath(os.path.join(pkg, "..", "KPI", "can_interactive_plot")))

    from a_persistence_layer.hdf_parser import KpiHdfParser
    from c_business_layer.kpi_business import KpiBusiness
    from d_presentation_layer.kpi_html_gen import KpiHtmlGen

    parser = KpiHdfParser()
    biz = KpiBusiness(parser)
    in_s = parser.extract_storages(parser.parse_file(in_path))
    out_s = parser.extract_storages(parser.parse_file(out_path))

    metrics = {}
    tabs = {}
    for sensor in sorted(set(in_s) | set(out_s)):
        if sensor not in in_s or sensor not in out_s:
            metrics[sensor] = {"error": f"present in only one side "
                                          f"(in={sensor in in_s}, out={sensor in out_s})"}
            continue
        try:
            r = biz._compute_match_pct(in_s[sensor], out_s[sensor], sensor)
            metrics[sensor] = {
                "scan": r.get("scan"),
                "overall": r.get("overall"),
                "precision": r.get("precision"),
                "recall": r.get("recall"),
                "f1": r.get("f1"),
                "accuracy": r.get("accuracy"),
                "per_signal": r.get("per_signal"),
            }
            tabs[sensor] = KpiHtmlGen().build_sensor_tab(
                sensor, r.get("scan"), {"overall": r.get("overall"),
                                        "precision": r.get("precision"),
                                        "recall": r.get("recall"),
                                        "f1": r.get("f1")},
                r.get("per_signal"))
        except Exception as ex:
            metrics[sensor] = {"error": f"{type(ex).__name__}: {ex}"}

    page = ""
    if tabs:
        try:
            page = KpiHtmlGen().build_tabbed_html(tabs, label, "")
        except Exception:
            page = "".join(tabs.values())
    return {"kind": "can_kpi", "label": label, "metrics": metrics, "html": page}


def run_udp(in_path: str, out_path: str, outdir: str, label: str):
    pkg = os.path.dirname(os.path.abspath(__file__))
    kpi_root = os.path.abspath(os.path.join(pkg, "..", "KPI"))
    if kpi_root not in sys.path:
        sys.path.insert(0, kpi_root)
    os.chdir(kpi_root)

    import UDP_KPI.a_persistence_layer.hdf_wrapper as hw
    from UDP_KPI.c_business_layer.detection_matching_kpi import process_detection_kpi
    from UDP_KPI.c_business_layer.tracker_matching_kpi import process_tracker_kpi
    from UDP_KPI.c_business_layer.alignment_matching_kpi import process_alignment_kpi

    import h5py

    def detect_sensors(path):
        """Top-level groups of an HDF are the sensor ids (skip 'header')."""
        try:
            with h5py.File(path, "r") as f:
                return [k for k in f.keys() if isinstance(f[k], h5py.Group)
                        and k.lower() != "header"]
        except Exception:
            return []

    sensors_in = detect_sensors(in_path)
    sensors_out = detect_sensors(out_path)
    all_metrics = {}
    html_parts = []
    streams_seen = set()

    for sensor in sorted(set(sensors_in) | set(sensors_out)):
        held = {}

        class _Capture(hw.KpiDataModel):
            def __init__(self, data, sensor_id):
                # COPY: the wrapper clears self.stream_models after the KPI run.
                held["data"] = dict(data)
                held["sensor"] = sensor_id
                super().__init__(data, sensor_id)

        hw.KpiDataModel = _Capture
        try:
            cfg = hw.KPIProcessingConfig(sensor, in_path, out_path, outdir, "log", "KPI")
            hw.KPIHDFWrapper(cfg).parse()
        except Exception as ex:
            all_metrics[sensor] = {"error": f"parse failed: {type(ex).__name__}: {ex}"}
            continue
        data = held.get("data") or {}
        if not data:
            all_metrics[sensor] = {"error": "no streams resolved"}
            continue
        streams_seen.update(k for k in data if isinstance(data.get(k), dict))
        m = {}
        for name, fn in (("alignment", lambda: process_alignment_kpi(data, sensor)),
                         ("detection", lambda: process_detection_kpi(data, sensor))):
            try:
                res = fn()
                m[name] = res.get("kpi_results", {})
                if res.get("html_content"):
                    html_parts.append(f'<div class="kpi-block"><h4>{sensor} &mdash; {name}</h4>'
                                      + res["html_content"] + "</div>")
            except Exception as ex:
                m[name] = {"error": f"{type(ex).__name__}: {ex}"}
        try:
            trk_models = data.get("TRACKER_STREAM")
            if isinstance(trk_models, dict) and "input" in trk_models and "output" in trk_models:
                res = process_tracker_kpi(trk_models["input"], trk_models["output"],
                                          sensor, "TRACKER_STREAM")
                m["tracker"] = res.get("kpi_results", {})
                if res.get("html_content"):
                    html_parts.append(f'<div class="kpi-block"><h4>{sensor} &mdash; tracker</h4>'
                                      + res["html_content"] + "</div>")
            else:
                m["tracker"] = {"error": "no TRACKER_STREAM in this file"}
        except Exception as ex:
            m["tracker"] = {"error": f"{type(ex).__name__}: {ex}"}
        all_metrics[sensor] = m

    return {"kind": "udp_kpi", "label": label,
            "metrics": {"_streams": sorted(streams_seen),
                        "_sensors": sorted(all_metrics),
                        "per_sensor": all_metrics},
            "html": "".join(html_parts)}


def _json_default(o):
    """Make numpy arrays/scalars JSON-serialisable (they carry the per-scan KPI)."""
    try:
        import numpy as np
        if isinstance(o, np.ndarray):
            return o.tolist()
        if isinstance(o, (np.integer,)):
            return int(o)
        if isinstance(o, (np.floating,)):
            return float(o)
        if isinstance(o, (np.bool_,)):
            return bool(o)
    except Exception:
        pass
    return str(o)


def main() -> int:
    if len(sys.argv) < 6:
        print("usage: _kpi_worker.py <can|udp> <in> <out> <outdir> <label>")
        return 2
    kind, in_path, out_path, outdir, label = sys.argv[1:6]
    os.makedirs(outdir, exist_ok=True)
    try:
        res = run_can(in_path, out_path, outdir, label) if kind == "can" \
            else run_udp(in_path, out_path, outdir, label)
    except Exception:
        res = {"kind": kind, "label": label, "error": traceback.format_exc(limit=6),
               "metrics": {}, "html": ""}
    with open(os.path.join(outdir, label + ".json"), "w", encoding="utf-8") as f:
        json.dump(res, f, default=_json_default)
    with open(os.path.join(outdir, label + ".html"), "w", encoding="utf-8") as f:
        f.write(res.get("html", "") or "")
    err = res.get("error")
    print(f"{label}: {'ERROR ' + str(err)[:300] if err else 'ok'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
