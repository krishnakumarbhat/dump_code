"""Self-check for the generalizable (X, Y) correlation plotting (Task 2).

Covers both entry points:
  * plot_xy_correlation(signal, data_dict, shared_data, lock)
        - the framework entry point used by the plot_types config
  * xy_correlation_figure(signal, x, y, ...)
        - the pure, stateless helper

Run:  pytest tests/test_xy_correlation.py -q
"""
import numpy as np
import plotly.graph_objects as go

from InteractivePlot.d_business_layer.data_cal import DataCalculations
from InteractivePlot.e_presentation_layer.plotly_visualization import PlotlyCharts


def _fixtures(n_scans=5, n_slots=3):
    """A tiny two-scan-pair fixture: ran, vel, snr over 5 scans x 3 slots."""
    si = np.repeat(np.arange(n_scans), n_slots)
    ran = np.arange(n_scans * n_slots, dtype=float)
    vel = ran * 2.0
    snr = ran + 10.0
    shared = {
        "_signal_bundle::ran": {"SI": si.tolist(), "I": ran.tolist(), "O": (ran + 0.5).tolist()},
        "_signal_bundle::vel": {"SI": si.tolist(), "I": vel.tolist(), "O": (vel + 0.5).tolist()},
        "_signal_bundle::snr": {"SI": si.tolist(), "I": snr.tolist(), "O": snr.tolist()},
    }
    data_dict = {"SI": si, "I": ran, "O": ran + 0.5, "MI": [[], []], "MO": [[], []]}
    return data_dict, shared


def _spec(x="vel", y="ran", color=None):
    spec = {"x_signal": {"name": x}, "y_signal": {"name": y},
            "title": "Range vs Radial Velocity",
            "x_label": "Radial Velocity (m/s)", "y_label": "Distance (m)"}
    if color:
        spec["color_signal"] = {"name": color}
    return spec


def test_framework_entry_point_builds_input_and_output_traces():
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    shared["_xy_spec::ran"] = [_spec()]
    fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    assert fid == "xy_fig_ran"
    assert isinstance(fig, go.Figure)
    assert len(fig.data) == 2
    assert {t.name for t in fig.data} == {"INPUT", "OUTPUT"}
    for t in fig.data:
        assert len(t.x) == 15
        assert len(t.y) == 15


def test_framework_entry_point_uses_the_declared_axes():
    """X must be the x_signal, Y the y_signal - not scan index."""
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    shared["_xy_spec::ran"] = [_spec()]
    _fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    xs = [v for v in fig.data[0].x]
    ys = [v for v in fig.data[0].y]
    # vel = ran * 2, so the x values must be exactly double the y values
    assert all(abs(x - 2.0 * y) < 1e-9 for x, y in zip(xs, ys))


def test_framework_entry_point_without_spec_returns_none():
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    assert fig is None


def test_framework_entry_point_with_two_specs_makes_two_subplots():
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    shared["_xy_spec::ran"] = [_spec(), _spec(x="snr", y="ran")]
    _fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    assert fig is not None
    assert len(fig.data) == 4          # 2 specs x (INPUT, OUTPUT)
    assert fig.layout.xaxis2 is not None   # second subplot exists


def test_framework_entry_point_with_color_signal():
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    shared["_xy_spec::ran"] = [_spec(color="snr")]
    _fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    assert fig is not None
    assert len(fig.data) == 2


def test_framework_entry_point_missing_bundle_yields_no_points():
    """A referenced signal that is not in the bundle must not produce points."""
    dc = DataCalculations()
    data_dict, shared = _fixtures()
    shared["_xy_spec::ran"] = [_spec(x="does_not_exist")]
    _fid, fig = dc.plot_xy_correlation("ran", data_dict, shared, None)
    assert fig is None


def test_pure_helper_filters_outliers_and_handles_nan():
    dc = DataCalculations()
    x = np.concatenate([np.linspace(0, 10, 50), [1e6]])
    y = np.concatenate([np.linspace(0, 10, 50), [1e6]])
    fid, fig = dc.xy_correlation_figure("t", x, y, outlier_z=3.0)
    assert fid == "xy_fig_t"
    assert fig is not None
    assert len(fig.data[0].x) <= 50

    fid, fig = dc.xy_correlation_figure("t", None, [1, 2, 3])
    assert fig is None
    fid, fig = dc.xy_correlation_figure("t", [np.nan, np.inf], [np.nan, np.inf])
    assert fig is None


def test_scatter_xy_standalone():
    fig = PlotlyCharts.scatter_xy([1, 2, 3], [4, 5, 6], color_vals=[0.1, 0.5, 0.9],
                                   signal_name="s", x_label="X", y_label="Y")
    assert isinstance(fig, go.Figure)
    assert len(fig.data) == 1
    assert len(fig.data[0].x) == 3
