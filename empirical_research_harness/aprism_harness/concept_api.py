"""Shared contract for the 27 empirical concept experiments.

Each concept module exposes ``CONCEPTS: list[dict]`` where every entry is
``{"id": int, "title": str, "source": str, "run": callable}``.

``run(seed: int) -> dict`` must return a result built by :func:`make_result`.
Every metric is MEASURED by executing the mirrored kernels; nothing is
hardcoded.
"""
from __future__ import annotations

import math
from typing import Any, Callable, Dict, List, Optional

import numpy as np

EPS = 1e-9


def make_result(concept_id: int, title: str, source: str,
                baseline_metrics: Dict[str, Any], aprism_metrics: Dict[str, Any],
                figures: Optional[List[Dict[str, Any]]] = None,
                notes: str = "",
                baseline_label: str = "BASELINE (feature OFF)",
                aprism_label: str = "A-PRISM (feature ON)") -> Dict[str, Any]:
    """Build the standard result dict consumed by the runner and dashboard."""
    return {
        "id": concept_id,
        "title": title,
        "source": source,
        "baseline": {"label": baseline_label, "metrics": baseline_metrics},
        "aprism": {"label": aprism_label, "metrics": aprism_metrics},
        "figures": figures or [],
        "notes": notes,
    }


def fig_entry(fid: str, title: str, fig) -> Dict[str, Any]:
    """Package a plotly figure for the runner (html + png rendering)."""
    return {"id": fid, "title": title, "fig": fig}


def safe_div(a: float, b: float) -> float:
    """eps-guarded division."""
    return float(a) / (float(b) if abs(float(b)) > EPS else EPS)


def rmse(err) -> float:
    """Root-mean-square error over a finite array (0 for empty)."""
    e = np.asarray(err, dtype=float).ravel()
    e = e[np.isfinite(e)]
    if e.size == 0:
        return 0.0
    return float(math.sqrt(np.mean(e ** 2)))


def mae(err) -> float:
    e = np.asarray(err, dtype=float).ravel()
    e = e[np.isfinite(e)]
    if e.size == 0:
        return 0.0
    return float(np.mean(np.abs(e)))


def pct(a: float, b: float) -> float:
    """Percent change from a (baseline) to b (after)."""
    if abs(a) < EPS:
        return 0.0
    return 100.0 * (b - a) / a


def roc_curve(labels, scores):
    """Return (fpr, tpr, thresholds) for binary labels/scores."""
    labels = np.asarray(labels).astype(int).ravel()
    scores = np.asarray(scores, dtype=float).ravel()
    if labels.size == 0:
        return np.array([0.0, 1.0]), np.array([0.0, 1.0]), np.array([])
    order = np.argsort(-scores)
    y = labels[order]
    tp = np.cumsum(y == 1)
    fp = np.cumsum(y == 0)
    npos = max(int((labels == 1).sum()), 1)
    nneg = max(int((labels == 0).sum()), 1)
    tpr = np.concatenate([[0.0], tp / npos])
    fpr = np.concatenate([[0.0], fp / nneg])
    thr = np.concatenate([[np.inf], scores[order]])
    return fpr, tpr, thr


def auc(fpr, tpr) -> float:
    """Trapezoidal AUC."""
    fpr = np.asarray(fpr, dtype=float)
    tpr = np.asarray(tpr, dtype=float)
    if fpr.size < 2:
        return 0.0
    return float(np.trapezoid(tpr, fpr)) if hasattr(np, "trapezoid") else float(np.trapz(tpr, fpr))


def best_threshold(fpr, tpr, thr):
    """Threshold maximising Youden's J (TPR - FPR)."""
    j = np.asarray(tpr, dtype=float) - np.asarray(fpr, dtype=float)
    i = int(np.argmax(j))
    return float(thr[i]) if i < len(thr) else 0.0


def fmt(v) -> str:
    """Compact human-readable metric formatting for the dashboard."""
    if isinstance(v, bool):
        return "yes" if v else "no"
    if isinstance(v, (int, np.integer)):
        return f"{int(v):,}"
    if isinstance(v, (float, np.floating)):
        if not math.isfinite(float(v)):
            return str(v)
        av = abs(float(v))
        if av == 0.0:
            return "0"
        if av >= 1e4 or av < 1e-3:
            return f"{float(v):.3e}"
        return f"{float(v):.4g}"
    return str(v)
