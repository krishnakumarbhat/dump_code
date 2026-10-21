"""Self-check for the generalizable (X, Y) correlation plotting (Task 2).

Run:  pytest tests/test_xy_correlation.py -q
"""
import numpy as np
import plotly.graph_objects as go

from InteractivePlot.d_business_layer.data_cal import DataCalculations
from InteractivePlot.e_presentation_layer.plotly_visualization import PlotlyCharts


def _finite_points(fig):
    if fig is None or not fig.data:
        return 0
    x = fig.data[0].x
    return 0 if x is None else len(x)


def test_basic_xy_correlation():
    dc = DataCalculations()
    x = np.linspace(0, 10, 50)
    y = 2.0 * x + 0.1 * np.random.RandomState(0).randn(50)
    fid, fig = dc.plot_xy_correlation(
        "range_vs_doppler", x, y,
        x_label="range (m)", y_label="doppler (m/s)",
        title="Range vs Doppler",
    )
    assert fid == "xy_fig_range_vs_doppler"
    assert isinstance(fig, go.Figure)
    assert _finite_points(fig) == 50


def test_missing_data_returns_none():
    dc = DataCalculations()
    fid, fig = dc.plot_xy_correlation("missing", None, [1, 2, 3])
    assert fig is None


def test_all_nonfinite_returns_none():
    dc = DataCalculations()
    fid, fig = dc.plot_xy_correlation("nan", [np.nan, np.inf], [np.nan, -np.inf])
    assert fig is None


def test_outlier_filtering():
    dc = DataCalculations()
    x = np.concatenate([np.linspace(0, 10, 50), [1e6]])
    y = np.concatenate([np.linspace(0, 10, 50), [1e6]])
    fid, fig = dc.plot_xy_correlation("out", x, y, outlier_z=3.0)
    assert fig is not None
    assert _finite_points(fig) <= 50


def test_scatter_xy_standalone():
    fig = PlotlyCharts.scatter_xy(
        [1, 2, 3], [4, 5, 6], color_vals=[0.1, 0.5, 0.9],
        signal_name="s", x_label="X", y_label="Y",
    )
    assert isinstance(fig, go.Figure)
    assert _finite_points(fig) == 3


def test_get_xy_plot_specs_empty():
    from InteractivePlot.c_data_storage.config_loader import get_xy_plot_specs
    assert get_xy_plot_specs("nonexistent_stream") == []
