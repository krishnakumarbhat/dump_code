"""Regression tests for the research-benchmark harness.

Covers:
  * Bug 1 - metric delta polarity in the master dashboard (higher-is-better
    metrics were rendered as "(worse)" whenever they improved).
  * Bonus - the Python mirror of CdcSelectTopK bounded its inner loop by ``k``
    instead of ``n``, so it could never promote a candidate from slot >= k.

Run:  python -m pytest tests/test_harness_regressions.py -q
"""
from __future__ import annotations

import os
import sys

import numpy as np
import pytest

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
if ROOT not in sys.path:
    sys.path.insert(0, ROOT)

from aprism_harness.dashboard import (  # noqa: E402
    HIGHER_IS_BETTER,
    LOWER_IS_BETTER,
    _delta_cell,
    _delta_html,
    metric_direction,
)
from aprism_harness.kernels import cdc_select_top_k  # noqa: E402


# --------------------------------------------------------------------------
# Bug 1 - delta polarity
# --------------------------------------------------------------------------

@pytest.mark.parametrize("metric", sorted(HIGHER_IS_BETTER))
def test_higher_is_better_metrics_improve_upward(metric):
    assert metric_direction(metric) == 1
    # +50% must read as better, -50% as worse
    assert _delta_cell(1.0, 1.5, metric) == "+50.0% (better)"
    assert _delta_cell(1.0, 0.5, metric) == "-50.0% (worse)"


@pytest.mark.parametrize("metric", sorted(LOWER_IS_BETTER))
def test_lower_is_better_metrics_improve_downward(metric):
    assert metric_direction(metric) == -1
    assert _delta_cell(1.0, 0.5, metric) == "-50.0% (better)"
    assert _delta_cell(1.0, 1.5, metric) == "+50.0% (worse)"


def test_roc_auc_perfect_score_is_not_reported_as_worse():
    """The reported symptom: 0.28 -> 1.00 rendered as +254.5% (worse)."""
    cell = _delta_cell(0.28, 1.00, "roc_auc")
    assert cell == "+257.1% (better)", cell
    assert "worse" not in cell
    assert 'class="better"' in _delta_html(0.28, 1.00, "roc_auc")


def test_metric_families_resolve_by_token():
    # explicit-set misses, resolved by the substring fallback
    assert metric_direction("position_rmse_m") == -1
    assert metric_direction("range_rmse_m_hi_snr") == -1
    assert metric_direction("track_err_rmse_m") == -1
    assert metric_direction("false_associations_per_frame") == -1
    assert metric_direction("near_retention_top16") == 1
    # lower-family must win over the higher-family token "suppression"
    assert metric_direction("false_suppressions") == -1
    assert metric_direction("true_suppressions") == 1


def test_unknown_metric_gets_no_polarity_claim():
    """Guessing polarity is what caused the bug - unknown metrics stay unlabelled."""
    assert metric_direction("alpha") == 0
    assert metric_direction("beta_entropy") == 0
    assert _delta_cell(2.0, 3.0, "alpha") == "+50.0%"
    assert "class=\"neutral\"" in _delta_html(2.0, 3.0, "alpha")


def test_zero_baseline_and_bad_values_are_blank():
    assert _delta_cell(0.0, 5.0, "roc_auc") == ""
    assert _delta_cell(None, 5.0, "roc_auc") == ""
    assert _delta_cell(1.0, None, "roc_auc") == ""


def test_identical_values_report_same():
    assert _delta_cell(0.5, 0.5, "roc_auc") == "+0.0% (same)"


# --------------------------------------------------------------------------
# Bonus - CdcSelectTopK mirror must scan all n candidates
# --------------------------------------------------------------------------

def test_cdc_select_top_k_promotes_candidate_beyond_k():
    """A best candidate sitting at index >= k must still be selected.

    This is the exact case the mirror got wrong: with the inner bound at ``k``
    the best value at index 9 was invisible and index 0 won.
    """
    scores = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 99.0])
    idx = np.zeros(len(scores), dtype=np.int32)
    kept = cdc_select_top_k(scores, len(scores), 3, idx)
    assert kept == 3
    assert int(idx[0]) == 9, f"expected candidate 9 first, got {idx[:3].tolist()}"
    assert scores[idx[0]] == 99.0
    # the remaining selected slots are the next best values
    assert sorted(scores[idx[:3]].tolist()) == [0.8, 0.9, 99.0]


def test_cdc_select_top_k_matches_reference_sorted_order():
    """Full-sort reference equivalence on a randomised case."""
    rng = np.random.default_rng(7)
    scores = rng.random(40).astype(float)
    k = 8
    idx = np.zeros(len(scores), dtype=np.int32)
    cdc_select_top_k(scores, len(scores), k, idx)
    got = scores[idx[:k]]
    want = np.sort(scores)[::-1][:k]
    assert np.allclose(got, want), f"{got} != {want}"


def test_cdc_select_top_k_is_stable_on_ties():
    scores = np.array([5.0, 5.0, 5.0, 5.0])
    idx = np.zeros(4, dtype=np.int32)
    cdc_select_top_k(scores, 4, 2, idx)
    assert idx[:2].tolist() == [0, 1], "ties must keep original order"


def test_cdc_select_top_k_edge_cases():
    scores = np.array([1.0, 2.0])
    idx = np.zeros(2, dtype=np.int32)
    assert cdc_select_top_k(scores, 2, 0, idx) == 0
    # k > n is clamped to n
    assert cdc_select_top_k(scores, 2, 10, idx) == 2
    assert sorted(idx[:2].tolist()) == [0, 1]


if __name__ == "__main__":
    raise SystemExit(pytest.main([__file__, "-q"]))
