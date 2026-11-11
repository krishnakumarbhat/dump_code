"""Figure export: interactive Plotly HTML + static Matplotlib PNG.

kaleido is not installed in this environment, so the PNG path converts the
Plotly figure object into an equivalent Matplotlib figure directly rather than
shelling out to a headless browser.
"""
from __future__ import annotations

import os
from typing import Any, Dict, List, Optional

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
import plotly.graph_objects as go


def _axis_pair(trace, layout) -> str:
    """Return the (xaxis, yaxis) anchor names for a trace."""
    xa = getattr(trace, "xaxis", None) or "x"
    ya = getattr(trace, "yaxis", None) or "y"
    return f"{xa}|{ya}"


def _collect_axes(fig) -> List[str]:
    seen: List[str] = []
    for tr in fig.data:
        key = _axis_pair(tr, fig.layout)
        if key not in seen:
            seen.append(key)
    return seen or ["x|y"]


def _clean(vals):
    """Coerce a plotly series into a 1-D float array with NaNs for gaps."""
    if vals is None:
        return np.array([])
    try:
        arr = np.asarray(vals, dtype=object)
    except Exception:
        return np.array([])
    out = []
    for v in arr:
        if v is None:
            out.append(np.nan)
            continue
        try:
            out.append(float(v))
        except (TypeError, ValueError):
            out.append(np.nan)
    return np.asarray(out, dtype=float)


def _trace_color(trace, default=None):
    marker = getattr(trace, "marker", None)
    if marker is not None:
        c = getattr(marker, "color", None)
        if isinstance(c, str):
            return c
        if c is not None and np.size(c) > 0:
            return None          # per-point colours: let matplotlib map
    line = getattr(trace, "line", None)
    if line is not None and isinstance(getattr(line, "color", None), str):
        return line.color
    return default


def figure_to_mpl(fig: go.Figure) -> plt.Figure:
    """Convert a Plotly figure into an equivalent Matplotlib figure."""
    axes = _collect_axes(fig)
    n = len(axes)
    ncols = 1 if n <= 1 else 2
    nrows = int(np.ceil(n / ncols))
    mfig, axs = plt.subplots(nrows, ncols, figsize=(7.2 * ncols, 4.0 * nrows), squeeze=False)
    flat = [a for row in axs for a in row]

    palette = ["#1f77b4", "#d62728", "#2ca02c", "#ff7f0e", "#9467bd",
               "#8c564b", "#e377c2", "#7f7f7f", "#bcbd22", "#17becf"]
    color_i = 0

    for tr in fig.data:
        key = _axis_pair(tr, fig.layout)
        if key not in axes:
            continue
        ax = flat[axes.index(key)]
        x = _clean(getattr(tr, "x", None))
        y = _clean(getattr(tr, "y", None))
        name = getattr(tr, "name", None) or ""
        ttype = type(tr).__name__

        col = _trace_color(tr)
        if col is None:
            col = palette[color_i % len(palette)]
            color_i += 1

        try:
            if ttype in ("Scatter", "Scattergl"):
                mode = getattr(tr, "mode", "lines") or "lines"
                if "lines" in mode and np.isfinite(x).any() and np.isfinite(y).any():
                    ax.plot(x, y, color=col, lw=1.4, label=name)
                if "markers" in mode:
                    m = np.isfinite(x) & np.isfinite(y)
                    sc = ax.scatter(x[m], y[m], s=8, color=col, alpha=0.7,
                                    label=name if "lines" not in mode else None)
            elif ttype == "Bar":
                ax.bar([str(v) for v in x], y, color=col, alpha=0.8, label=name)
            elif ttype == "Histogram":
                ax.hist(y[~np.isnan(y)], bins=40, color=col, alpha=0.6, label=name)
            elif ttype == "Box":
                vals = [y[~np.isnan(y)]]
                ax.boxplot(vals, labels=[name or "data"])
            elif ttype in ("Heatmap",):
                z = np.asarray(tr.z, dtype=float)
                ax.imshow(z, origin="lower", aspect="auto", cmap="viridis",
                          extent=[np.nanmin(x), np.nanmax(x), np.nanmin(y), np.nanmax(y)]
                          if x.size and y.size else None)
            elif ttype == "Scatterpolar":
                th = _clean(getattr(tr, "theta", None))
                r = _clean(getattr(tr, "r", None))
                ax.scatter(th, r, s=6, color=col, alpha=0.7, label=name)
            elif ttype == "Scatter3d":
                z = _clean(getattr(tr, "z", None))
                m = np.isfinite(x) & np.isfinite(y) & np.isfinite(z)
                ax.scatter(x[m], y[m], s=6, color=col, alpha=0.7, label=name)
            else:
                continue
        except Exception:
            continue

    for ax, key in zip(flat, axes):
        xa, ya = key.split("|")
        xt = getattr(fig.layout, f"{xa}_title", None)
        yt = getattr(fig.layout, f"{ya}_title", None)
        if xt is not None and getattr(xt, "text", None):
            ax.set_xlabel(xt.text)
        if yt is not None and getattr(yt, "text", None):
            ax.set_ylabel(yt.text)
        ax.grid(True, alpha=0.25, linewidth=0.6)
        if ax.get_legend_handles_labels()[0]:
            ax.legend(fontsize=7, loc="best")
    for ax in flat[n:]:
        ax.axis("off")

    title = ""
    if fig.layout.title is not None and getattr(fig.layout.title, "text", None):
        title = fig.layout.title.text
    if title:
        mfig.suptitle(title[:180], fontsize=11, fontweight="bold")
    mfig.tight_layout(rect=(0, 0, 1, 0.96 if title else 1.0))
    return mfig


def export_figure(fig: go.Figure, html_path: str, png_path: Optional[str] = None,
                  title: str = "", width: int = 1200, height: int = 760) -> Dict[str, Any]:
    """Write the interactive HTML and (optionally) the static PNG."""
    out: Dict[str, Any] = {"html": html_path, "png": None, "error": None}
    os.makedirs(os.path.dirname(html_path), exist_ok=True)
    try:
        fig.write_html(html_path, include_plotlyjs="cdn", full_html=True,
                       config={"displaylogo": False, "responsive": True})
    except Exception as ex:
        out["error"] = f"html: {ex}"
        return out
    if png_path:
        os.makedirs(os.path.dirname(png_path), exist_ok=True)
        try:
            mfig = figure_to_mpl(fig)
            mfig.savefig(png_path, dpi=130, bbox_inches="tight")
            plt.close(mfig)
            out["png"] = png_path
        except Exception as ex:
            out["error"] = f"png: {ex}"
    return out
