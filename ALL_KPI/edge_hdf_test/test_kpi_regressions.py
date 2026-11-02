"""Regression tests for the KPI / interactive-plot pipeline.

Covers:
  * Bug 2 - CAN "signal not available" slot padding (-128.0 / 0x80) reaching the
    (X, Y) scatter traces and stretching the axis to -128 m.
  * Bug 3 - after a single dropped frame the resim payload lags its scan_index
    label, so every later scan was scored against the wrong neighbour
    (~92% real match reported as ~18%).

Run:  python -m pytest edge_hdf_test/test_kpi_regressions.py -q
"""
from __future__ import annotations

import os
import sys

import numpy as np
import pytest

HERE = os.path.dirname(os.path.abspath(__file__))
ALL_KPI = os.path.dirname(HERE)                      # ...\ALL_KPI
PKG = os.path.join(ALL_KPI, "KPI", "can_interactive_plot")
if PKG not in sys.path:
    sys.path.insert(0, PKG)
os.chdir(PKG)

from a_persistence_layer.hdf_parser import KpiHdfParser  # noqa: E402
from InteractivePlot.d_business_layer.data_cal import DataCalculations  # noqa: E402


# --------------------------------------------------------------------------
# Bug 2 - CAN sentinel filtering in the (X, Y) pairing
# --------------------------------------------------------------------------

SNA = -128.0  # 0x80, AUTOSAR signal-not-available byte padding


def _pairs(gx, gy, gc=None):
    dc = DataCalculations.__new__(DataCalculations)  # no binding needed
    return DataCalculations._xy_pair(dc, gx, gy, gc)


def test_sentinel_slots_are_dropped_from_the_xy_pair():
    """The reported symptom: -128.0 in the OUTPUT x array stretched the axis."""
    gx = {1: np.array([1.0, 2.0, SNA, SNA, 3.0])}
    gy = {1: np.array([4.0, 5.0, SNA, 6.0, 7.0])}
    x, y, c = _pairs(gx, gy)
    assert x is not None
    assert SNA not in x and SNA not in y
    assert x.tolist() == [1.0, 2.0, 3.0]
    assert y.tolist() == [4.0, 5.0, 7.0]
    assert c is None


def test_sentinel_is_dropped_on_either_axis():
    """An empty slot is invalid even when only one coordinate is padding."""
    gx = {1: np.array([10.0, 20.0])}
    gy = {1: np.array([SNA, 30.0])}
    x, y, _ = _pairs(gx, gy)
    assert x.tolist() == [20.0]
    assert y.tolist() == [30.0]


def test_non_finite_values_are_dropped():
    gx = {1: np.array([1.0, np.nan, np.inf, 4.0])}
    gy = {1: np.array([1.0, 2.0, 3.0, 4.0])}
    x, y, _ = _pairs(gx, gy)
    assert x.tolist() == [1.0, 4.0]
    assert y.tolist() == [1.0, 4.0]


def test_colour_values_stay_aligned_with_dropped_points():
    gx = {1: np.array([1.0, SNA, 3.0])}
    gy = {1: np.array([1.0, 2.0, 3.0])}
    gc = {1: np.array([100.0, 200.0, 300.0])}
    x, y, c = _pairs(gx, gy, gc)
    assert x.tolist() == [1.0, 3.0]
    assert c is not None and c.tolist() == [100.0, 300.0], c


def test_all_sentinel_scan_is_skipped_entirely():
    gx = {1: np.array([SNA, SNA]), 2: np.array([5.0])}
    gy = {1: np.array([SNA, SNA]), 2: np.array([6.0])}
    x, y, _ = _pairs(gx, gy)
    assert x.tolist() == [5.0] and y.tolist() == [6.0]


def test_per_scan_groups_are_paired_on_shared_scan_only():
    gx = {1: np.array([1.0]), 3: np.array([9.0])}
    gy = {2: np.array([2.0]), 3: np.array([8.0])}
    x, y, _ = _pairs(gx, gy)
    assert x.tolist() == [9.0] and y.tolist() == [8.0]


def test_real_targets_survive_the_filter():
    """The valid cluster (-5..+5 m) must be untouched."""
    vals = np.linspace(-5.0, 5.0, 21)
    x, y, _ = _pairs({1: vals.copy()}, {1: vals.copy()})
    assert len(x) == 21 and float(x.min()) == -5.0 and float(x.max()) == 5.0


# --------------------------------------------------------------------------
# Bug 3 - dropped-frame row desync
# --------------------------------------------------------------------------

class _StubStorage:
    """Minimal stand-in exposing the accessors the calibration reads.

    Detection content encodes the row index, so a pair scores 1.0 only when
    both sides read the same physical row.
    """

    DETS_PER_ROW = 3

    def __init__(self, n_rows=0):
        self._n = int(n_rows)

    def get_valid_detection_counts(self):
        return np.full(self._n, self.DETS_PER_ROW, dtype=np.int32)

    def get_scan_detections(self, signal_names, row_idx, max_det, det_idx_shifts=None):
        shift = 0
        if det_idx_shifts:
            shift = int(det_idx_shifts.get(0, 0))
        r = int(row_idx) + shift
        if max_det <= 0 or r < 0 or r >= self._n:
            return []
        return [
            {s: float(r) + 0.1 * d for s in signal_names}
            for d in range(min(self.DETS_PER_ROW, int(max_det)))
        ]


def _build_dropped_frame_case(n_seg=12):
    """Input drops one scan; the OUTPUT payload lags its label by one row.

    Segment 1: in_row == out_row          (content aligns at offset 0)
    Segment 2: out_row == in_row + 1      (content aligns at offset -1)
    """
    scans_a = list(range(10, 10 + n_seg))
    scans_b = list(range(10 + n_seg + 1, 10 + n_seg + 1 + n_seg))
    common = np.array(scans_a + scans_b, dtype=np.int64)
    in_rows = np.arange(2 * n_seg, dtype=np.int64)
    out_rows = np.concatenate([
        np.arange(n_seg, dtype=np.int64),
        np.arange(n_seg + 1, 2 * n_seg + 1, dtype=np.int64),
    ])
    return common, in_rows, out_rows


def test_dropped_frame_desync_is_corrected():
    """Before the fix every scan after the gap scored ~18% against the wrong row."""
    common, in_rows, out_rows = _build_dropped_frame_case()
    p = KpiHdfParser()
    out_fixed = p._apply_out_row_offsets(
        _StubStorage(26), _StubStorage(26), common, in_rows, out_rows, {},
    )
    # segment 1 untouched, segment 2 shifted back by exactly one row
    assert out_fixed[:12].tolist() == out_rows[:12].tolist()
    assert out_fixed[12:].tolist() == (out_rows[12:] - 1).tolist()
    # after correcting, both sides read the same payload row
    assert np.array_equal(out_fixed, in_rows)
    assert p.out_row_offsets == [(int(common[12]), int(common[-1]), -1)]


def test_already_aligned_logs_are_left_alone():
    """No regression: a clean log must keep offset 0 everywhere."""
    n = 24
    common = np.arange(100, 100 + n, dtype=np.int64)
    in_rows = np.arange(n, dtype=np.int64)
    out_rows = np.arange(n, dtype=np.int64)
    p = KpiHdfParser()
    out_fixed = p._apply_out_row_offsets(
        _StubStorage(n), _StubStorage(n), common, in_rows, out_rows, {},
    )
    assert np.array_equal(out_fixed, out_rows)
    assert p.out_row_offsets == []


def test_short_segments_are_not_corrected():
    """Below OUT_OFF_MIN_SEG there is not enough evidence - stay legacy."""
    common = np.array([1, 2, 3])
    in_rows = np.array([0, 1, 2], dtype=np.int64)
    out_rows = np.array([1, 2, 3], dtype=np.int64)
    p = KpiHdfParser()
    out_fixed = p._apply_out_row_offsets(
        _StubStorage(6), _StubStorage(6), common, in_rows, out_rows, {},
    )
    assert np.array_equal(out_fixed, out_rows)
    assert p.out_row_offsets == []


def test_absent_detections_leave_behaviour_unchanged():
    common, in_rows, out_rows = _build_dropped_frame_case()
    p = KpiHdfParser()
    out_fixed = p._apply_out_row_offsets(
        _StubStorage(0), _StubStorage(0), common, in_rows, out_rows, {},
    )
    assert np.array_equal(out_fixed, out_rows)
    assert p.out_row_offsets == []


def test_scan_index_join_is_the_alignment_key():
    """Guard against a regression back to positional zip()."""
    p = KpiHdfParser()
    # input drops 18531; output keeps it
    in_scan = np.array([18530, 18532, 18533], dtype=np.int64)
    out_scan = np.array([18530, 18531, 18532, 18533], dtype=np.int64)
    common, i_rows, o_rows = p._align_scan_only(in_scan, out_scan)
    assert common.tolist() == [18530, 18532, 18533]
    assert i_rows.tolist() == [0, 1, 2]
    # 18532 must map to output row 2, NOT row 1 (positional pairing)
    assert o_rows.tolist() == [0, 2, 3]


if __name__ == "__main__":
    raise SystemExit(pytest.main([__file__, "-q"]))
