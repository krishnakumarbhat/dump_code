# edge_hdf end-to-end test — generalizable (X, Y) plots

Verifies the **generalizable (X, Y) plotting** feature against the real HDF5
fixtures in `edge_hdf/`, by driving the real interactive-plot CLIs.

## What it runs

| Target | Tool | Fixtures | Layout |
|---|---|---|---|
| `CAN` | `KPI/can_interactive_plot/can_intplot_main.py` | `edge_hdf/can/{input,output}/CCA_9010_3100099_BUS_20260119_120641_0000*` | `CEER_FL/…/SRR_FL_DETECTION_001_004` (group attrs) |
| `UDP` | `KPI/intplot_kpi/ResimHTMLReport.py` | `edge_hdf/udp/{input,output}/ThunderMCIP_WS07952_20260316_193238_0000_b05*` | `FC/FL/FR/RL/RR/DOWN_SELECTION_STREAM` |
| `UDP-DUMMY` | `KPI/intplot_kpi/ResimHTMLReport.py` | `edge_hdf/udp/{input,output}/kpi_dummy_pair1_*` | `SENSOR1/DETECTION_STREAM` |

## How

1. `build_plot_config()` takes the shipped `Gen7V1_V2` config, **adds** the
   `(X, Y)` pairings, and writes a plot-config JSON. Everything else in the
   config is untouched, so the normal plots still run alongside.
2. `build_xml()` copies the shipped `ConfigInteractivePlots.xml` and turns the
   KPI tab off (it needs a live ZMQ server; the plots are what is under test).
3. The real CLI is executed as a subprocess in the package directory.
4. The generated HTML is parsed back and every `(X, Y)` figure is decoded
   (including Plotly's base64 array encoding) to confirm the traces carry
   **real data points**, not just an empty axis.

The test **fails** if the pipeline errors, if no `(X, Y)` figure is produced,
or if the figures carry zero points.

## The (X, Y) pairings under test

Declared per signal in the plot config:

```json
"ran": {
  "plot_types": ["plot_xy_correlation"],
  "xy_plots": [
    {"x_signal": {"name": "vel"},   "y_signal": {"name": "ran"},
     "title": "Range vs Radial Velocity",
     "x_label": "Radial Velocity (m/s)", "y_label": "Distance (m)"},
    {"x_signal": {"name": "theta"}, "y_signal": {"name": "ran"},
     "title": "Range vs Azimuth (bird's eye)",
     "x_label": "Azimuth (deg)", "y_label": "Distance (m)"}
  ]
}
```

Note the X axis is **not** `scan_index` — it is a real signal.

## Running it

```bash
cd ALL_KPI/edge_hdf_test
python run_edge_hdf_test.py            # all three targets
python run_edge_hdf_test.py --can      # CAN only
python run_edge_hdf_test.py --udp      # real UDP only
python run_edge_hdf_test.py --dummy    # small UDP pair (fast, ~20 s)
```

Outputs land in `out/`:
- `<tag>_config.xml`, `<tag>_inputs.json`, `<tag>_plot_config.json`
- `<tag>_html/` — the generated reports
- `report.json` — machine-readable summary

## How the feature works (short version)

`data_prep._process_signal_plot()` stashes the declared pairing into
`shared_data` under `_xy_spec::<signal>` and pre-resolves every referenced
signal's bundle under `_signal_bundle::<name>`, so the pairing works
regardless of the order the signals are processed in.

`data_cal.plot_xy_correlation(signal, data_dict, shared_data, lock)` then:
- groups each signal's flattened per-detection values **by scan** (two signals
  can carry a different number of detections per scan, so pairing by raw index
  would mis-align them),
- pairs X and Y element-wise inside each scan,
- overlays the INPUT and OUTPUT clouds in the same (X, Y) plane, so a
  behaviour change in the simulation shows up directly as a shift of the
  OUTPUT cloud.

Set `INTERACTIVE_PLOT_XY_DEBUG=<path>` to dump the resolved bundles and the
resolved spec for every call.
