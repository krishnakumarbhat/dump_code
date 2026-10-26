"""ID-independent tracker association KPIs (v2).

Why this module exists
----------------------
v1 (:mod:`tracker_matching_kpi`) pairs objects on the composite key
``(scan, trkID)``.  Track-ID allocation is not stable between a reference run
and a replay/algorithm run, so two physically identical objects with different
IDs become one FN plus one FP.  This module keeps the v1 KPI math and HTML but
replaces the pairing stage with kinematic association.

Backends (``AssociationConfig.algorithm``)
------------------------------------------
``legacy_id``            original v1 pairing (backward compatibility; delegates
                         to :meth:`TrackerMappingKPIHDF.match_tracker_data`)
``hungarian_normalized`` hard per-axis gates + weighted normalized cost +
                         global Hungarian assignment
``mahalanobis``          range-dependent innovation covariance, chi-square gate,
                         Mahalanobis cost + log-determinant volume penalty
``gospa``                GOSPA (c, p, alpha) assignment and decomposition
``multi_scan``           sliding-window constant-velocity projection with an
                         ID-switch penalty (temporal GNN)
``obb_auction``          oriented bounding box + radial Doppler gate, Bertsekas
                         auction assignment

Gates come from the existing ``vcs_*`` thresholds, so production behaviour is
driven by ``KPI_VALIDATION_RULES`` exactly as before.
"""
from __future__ import annotations

import logging
from dataclasses import dataclass
from typing import Any, Dict, List, Optional, Sequence, Tuple

import numpy as np
import pandas as pd
from scipy.optimize import linear_sum_assignment

from UDP_KPI.b_data_storage.kpi_config_storage import KPI_VALIDATION_RULES
from UDP_KPI.c_business_layer.tracker_matching_kpi import TrackerMappingKPIHDF

logger = logging.getLogger(__name__)

ALGORITHMS: Tuple[str, ...] = (
    "legacy_id",
    "hungarian_normalized",
    "mahalanobis",
    "gospa",
    "multi_scan",
    "obb_auction",
    "greedy_nearest",  # diagnostic proxy for the historical CSV matcher only
)
DEFAULT_ALGORITHM = "hungarian_normalized"

# Sentinel for gated pairs: scipy refuses inf, so use a value far above any
# realistic normalized cost, then drop those pairs after assignment.
_BIG = 1.0e9
_CHI2_99 = {2: 9.21, 3: 11.34, 4: 13.28}
_DEFAULT_LENGTH_M = 4.5
_DEFAULT_WIDTH_M = 1.9


@dataclass
class AssociationConfig:
    """Association gates and per-backend tuning, all in SI units."""

    tx: float = 0.01
    ty: float = 0.01
    tvx: float = 0.02
    tvy: float = 0.02
    max_range: float = 160.0
    algorithm: str = DEFAULT_ALGORITHM
    position_weight: float = 1.0
    velocity_weight: float = 1.0
    chi2_gate: float = _CHI2_99[4]
    gospa_cutoff: float = 2.0
    gospa_order: float = 2.0
    gospa_alpha: float = 2.0
    window: int = 3
    scan_period_s: float = 0.05
    id_switch_penalty: float = 1.0
    auction_epsilon: float = 1.0e-3
    obb_margin_m: float = 0.25
    doppler_sigma: float = 0.5
    range_sigma_floor: float = 0.3
    range_sigma_scale: float = 0.02
    speed_sigma_floor: float = 0.2

    def __post_init__(self) -> None:
        if self.algorithm not in ALGORITHMS:
            raise ValueError(
                f"unknown association_algorithm {self.algorithm!r}; "
                f"expected one of {ALGORITHMS}"
            )
        # A zero/negative gate would divide by zero in the normalized cost.
        for name in ("tx", "ty", "tvx", "tvy"):
            if not np.isfinite(getattr(self, name)) or getattr(self, name) <= 0:
                raise ValueError(f"{name} must be a positive finite gate")
        self.window = max(1, int(self.window))
        self.gospa_cutoff = max(float(self.gospa_cutoff), 1e-6)
        self.gospa_order = max(float(self.gospa_order), 1.0)

    @classmethod
    def from_thresholds(
        cls, thresholds: Optional[Dict[str, Any]] = None, algorithm: Optional[str] = None
    ) -> "AssociationConfig":
        """Build a config from ``KPI_VALIDATION_RULES['tracker_thresholds']``."""
        th = thresholds if thresholds is not None else KPI_VALIDATION_RULES.get(
            "tracker_thresholds", {}
        )
        return cls(
            tx=float(th.get("vcs_xposn_threshold", 0.01)),
            ty=float(th.get("vcs_yposn_threshold", 0.01)),
            tvx=float(th.get("vcs_xvel_threshold", 0.02)),
            tvy=float(th.get("vcs_yvel_threshold", 0.02)),
            max_range=float(th.get("max_valid_distance", 160.0)),
            algorithm=str(algorithm or th.get("association_algorithm", DEFAULT_ALGORITHM)),
            window=int(th.get("association_window", 3)),
            gospa_cutoff=float(th.get("gospa_cutoff", 2.0)),
            auction_epsilon=float(th.get("auction_epsilon", 1.0e-3)),
        )

    def with_algorithm(self, algorithm: str) -> "AssociationConfig":
        """Return a copy bound to another backend (config immutability helper)."""
        data = {f: getattr(self, f) for f in self.__dataclass_fields__}
        data["algorithm"] = algorithm
        return AssociationConfig(**data)


@dataclass
class Observations:
    """Validated objects of one scan (one row per physical candidate)."""

    ids: np.ndarray
    x: np.ndarray
    y: np.ndarray
    vx: np.ndarray
    vy: np.ndarray
    f_moving: np.ndarray
    length: np.ndarray
    width: np.ndarray
    heading: np.ndarray

    def __len__(self) -> int:
        return int(self.x.size)


def _to_2d_padded(values: Any, fill: float = np.nan) -> np.ndarray:
    """Coerce HDF rows (ragged lists, 1-D scalars or 2-D arrays) to 2-D float."""
    rows = list(values) if values is not None else []
    if not rows:
        return np.empty((0, 0), dtype=float)
    first = np.asarray(rows[0])
    if first.ndim == 0:
        return np.asarray(rows, dtype=float).reshape(-1, 1)
    width = max(np.atleast_1d(np.asarray(r)).size for r in rows)
    out = np.full((len(rows), width), fill, dtype=float)
    for i, row in enumerate(rows):
        flat = np.atleast_1d(np.asarray(row, dtype=float)).ravel()
        out[i, : flat.size] = flat
    return out


def _stacked(data: Dict[str, Any], key: str, n_scans: int, n_slots: int,
             fill: float = np.nan) -> np.ndarray:
    """Return a ``(n_scans, n_slots)`` view of ``data[key]`` padded with fill."""
    raw = data.get(key) if isinstance(data, dict) else None
    out = np.full((n_scans, n_slots), fill, dtype=float)
    if raw is None:
        return out
    arr = _to_2d_padded(raw, fill=fill)
    r = min(n_scans, arr.shape[0])
    c = min(n_slots, arr.shape[1])
    if r and c:
        out[:r, :c] = arr[:r, :c]
    return out


def _prepare(tracks: Dict[str, Any]) -> Tuple[Dict[str, np.ndarray], int, int]:
    """Pad/normalize a tracker dict; returns (fields, n_scans, n_slots)."""
    if not tracks or tracks.get("track_id") is None:
        return {}, 0, 0
    ids = _to_2d_padded(tracks["track_id"], fill=np.nan)
    n_scans, n_slots = ids.shape
    fields = {"track_id": ids}
    for key, fill in (
        ("x_position", np.nan), ("y_position", np.nan),
        ("x_velocity", np.nan), ("y_velocity", np.nan), ("f_moving", np.nan),
        ("length", np.nan), ("width", np.nan), ("heading", np.nan),
    ):
        fields[key] = _stacked(tracks, key, n_scans, n_slots, fill=fill)
    fields["length"] = np.where(np.isfinite(fields["length"]), fields["length"],
                                _DEFAULT_LENGTH_M)
    fields["width"] = np.where(np.isfinite(fields["width"]), fields["width"],
                               _DEFAULT_WIDTH_M)
    return fields, n_scans, n_slots


def _valid_mask(fields: Dict[str, np.ndarray], cfg: AssociationConfig) -> np.ndarray:
    """Slot validity: real ID, finite in-envelope position, CAN sentinel removed."""
    ids, x, y = fields["track_id"], fields["x_position"], fields["y_position"]
    mask = (
        np.isfinite(ids) & (ids != 0)
        & np.isfinite(x) & np.isfinite(y)
        # 0x80 (-128.0) and similar CAN empty-slot sentinels
        & (x > -100.0) & (y > -100.0)
        # empty slot padded with zeros while carrying a stale ID
        & ~((x == 0.0) & (y == 0.0))
    )
    if np.isfinite(cfg.max_range) and cfg.max_range > 0:
        mask &= np.hypot(x, y) <= cfg.max_range
    return mask


def _observations(fields: Dict[str, np.ndarray], row: int, mask: np.ndarray) -> Observations:
    sel = np.flatnonzero(mask)
    heading = fields["heading"][row, sel]
    vx = fields["x_velocity"][row, sel]
    vy = fields["y_velocity"][row, sel]
    heading = np.where(np.isfinite(heading), heading, np.arctan2(vy, vx))
    return Observations(
        ids=fields["track_id"][row, sel],
        x=fields["x_position"][row, sel],
        y=fields["y_position"][row, sel],
        vx=vx,
        vy=vy,
        f_moving=fields["f_moving"][row, sel],
        length=fields["length"][row, sel],
        width=fields["width"][row, sel],
        heading=heading,
    )


def _solve(cost: np.ndarray) -> List[Tuple[int, int]]:
    """Global one-to-one assignment; gated (non-finite) entries are discarded."""
    if cost.size == 0:
        return []
    finite = np.isfinite(cost)
    if not finite.any():
        return []
    work = np.where(finite, cost, _BIG)
    rows, cols = linear_sum_assignment(work)
    return [(int(i), int(j)) for i, j in zip(rows, cols) if finite[i, j]]


def _kinematics(inp: Observations, out: Observations) -> Dict[str, np.ndarray]:
    """Pairwise deltas, NaN-aware motion agreement and hard per-axis gates."""
    dx = np.abs(inp.x[:, None] - out.x[None, :])
    dy = np.abs(inp.y[:, None] - out.y[None, :])
    ivx, ivy = inp.vx[:, None], inp.vy[:, None]
    ovx, ovy = out.vx[None, :], out.vy[None, :]
    dvx = np.abs(ivx - ovx)
    dvy = np.abs(ivy - ovy)
    vx_known = np.isfinite(ivx) & np.isfinite(ovx)
    vy_known = np.isfinite(ivy) & np.isfinite(ovy)
    ifm, ofm = inp.f_moving[:, None], out.f_moving[None, :]
    fm_conflict = np.isfinite(ifm) & np.isfinite(ofm) & (ifm != ofm)
    return {
        "dx": dx, "dy": dy, "dvx": dvx, "dvy": dvy,
        "vx_known": vx_known, "vy_known": vy_known, "fm_conflict": fm_conflict,
    }


def _gate(k: Dict[str, np.ndarray], cfg: AssociationConfig) -> np.ndarray:
    return (
        (k["dx"] <= cfg.tx) & (k["dy"] <= cfg.ty)
        & (~k["vx_known"] | (k["dvx"] <= cfg.tvx))
        & (~k["vy_known"] | (k["dvy"] <= cfg.tvy))
        & ~k["fm_conflict"]
    )


def _normalized_cost(inp: Observations, out: Observations,
                     cfg: AssociationConfig) -> np.ndarray:
    """Algorithm 1: weighted squared normalized innovation, gated."""
    k = _kinematics(inp, out)
    cost = (
        cfg.position_weight * ((k["dx"] / cfg.tx) ** 2 + (k["dy"] / cfg.ty) ** 2)
        + cfg.velocity_weight * (
            np.where(k["vx_known"], (k["dvx"] / cfg.tvx) ** 2, 0.0)
            + np.where(k["vy_known"], (k["dvy"] / cfg.tvy) ** 2, 0.0)
        )
    )
    return np.where(_gate(k, cfg), cost, np.inf)


def _mahalanobis_cost(inp: Observations, out: Observations,
                      cfg: AssociationConfig) -> np.ndarray:
    """Algorithm 2: chi-square innovation gate + log-determinant volume penalty."""
    k = _kinematics(inp, out)
    r_in = np.hypot(inp.x, inp.y)[:, None]
    r_out = np.hypot(out.x, out.y)[None, :]
    sigma_p = cfg.range_sigma_floor + cfg.range_sigma_scale * np.maximum(r_in, r_out)
    var_p = sigma_p ** 2
    speed = np.maximum(np.hypot(inp.vx, inp.vy)[:, None],
                       np.hypot(out.vx, out.vy)[None, :])
    sigma_v = cfg.speed_sigma_floor + cfg.range_sigma_scale * np.nan_to_num(speed)
    var_v = sigma_v ** 2

    d2 = (k["dx"] ** 2 + k["dy"] ** 2) / var_p
    d2 = d2 + np.where(k["vx_known"], k["dvx"] ** 2 / var_v, 0.0)
    d2 = d2 + np.where(k["vy_known"], k["dvy"] ** 2 / var_v, 0.0)
    dof = 2 + k["vx_known"].astype(int) + k["vy_known"].astype(int)
    crit = np.select(
        [dof >= 4, dof == 3], [_CHI2_99[4], _CHI2_99[3]], default=_CHI2_99[2]
    )

    logdet = np.log(var_p) * 2.0
    logdet = logdet + np.where(k["vx_known"], np.log(var_v), 0.0)
    logdet = logdet + np.where(k["vy_known"], np.log(var_v), 0.0)
    cost = d2 + logdet
    return np.where((d2 <= crit) & ~k["fm_conflict"], cost, np.inf)


def _gospa_cost(inp: Observations, out: Observations, cfg: AssociationConfig
                ) -> Tuple[np.ndarray, np.ndarray]:
    """Algorithm 3: GOSPA truncated cost matrix plus the localization matrix."""
    k = _kinematics(inp, out)
    d = np.hypot(k["dx"], k["dy"])
    cost = np.minimum(d, cfg.gospa_cutoff) ** cfg.gospa_order
    cost = np.where(k["fm_conflict"], np.inf, cost)
    return cost, d


def _obb_auction_cost(inp: Observations, out: Observations,
                      cfg: AssociationConfig) -> np.ndarray:
    """Algorithm 5: oriented-box containment + line-of-sight Doppler projection."""
    k = _kinematics(inp, out)
    dx = inp.x[:, None] - out.x[None, :]
    dy = inp.y[:, None] - out.y[None, :]
    ca, sa = np.cos(inp.heading)[:, None], np.sin(inp.heading)[:, None]
    local_x = dx * ca + dy * sa
    local_y = -dx * sa + dy * ca
    half_len = (np.maximum(inp.length, 1.0) / 2.0 + cfg.obb_margin_m)[:, None]
    half_wid = (np.maximum(inp.width, 1.0) / 2.0 + cfg.obb_margin_m)[:, None]
    inside = (np.abs(local_x) <= half_len) & (np.abs(local_y) <= half_wid)

    def _radial(o: Observations) -> np.ndarray:
        rng = np.maximum(np.hypot(o.x, o.y), 1e-3)
        return (o.x * o.vx + o.y * o.vy) / rng

    vr_in, vr_out = _radial(inp)[:, None], _radial(out)[None, :]
    doppler_ok = ~(np.isfinite(vr_in) & np.isfinite(vr_out)) | (
        np.abs(vr_in - vr_out) <= 3.0 * cfg.doppler_sigma
    )
    gate = inside & doppler_ok & ~k["fm_conflict"]
    cost = ((k["dx"] / cfg.tx) ** 2 + (k["dy"] / cfg.ty) ** 2)
    return np.where(gate, cost, np.inf)


def _auction(cost: np.ndarray, epsilon: float = 1e-3,
             max_iter: int = 200_000) -> List[Tuple[int, int]]:
    """Bertsekas epsilon-auction on a minimization cost matrix.

    Rows/columns without any feasible entry are removed first (otherwise an
    infeasible row can outbid a real one and destroy the assignment).  Falls
    back to the Hungarian solution if the bid loop does not converge, keeping
    embedded-grade latency bounded.
    """
    if cost.size == 0:
        return []
    finite = np.isfinite(cost)
    row_ok = finite.any(axis=1)
    col_ok = finite.any(axis=0)
    if not row_ok.any() or not col_ok.any():
        return []
    rows = np.flatnonzero(row_ok)
    cols = np.flatnonzero(col_ok)
    sub = cost[np.ix_(rows, cols)]
    n, m = sub.shape
    transposed = n > m
    work = sub.T.copy() if transposed else sub.copy()
    n, m = work.shape
    work = np.where(np.isfinite(work), work, 1e6)
    owner_obj = -np.ones(m, dtype=int)
    prices = np.zeros(m)
    unassigned = list(range(n))
    iterations = 0
    while unassigned:
        iterations += 1
        if iterations > max_iter:
            logger.warning("auction did not converge; falling back to Hungarian")
            return _solve(cost)
        i = unassigned.pop(0)
        values = -work[i] - prices
        order = np.argsort(values)[::-1]
        j1 = int(order[0])
        best = values[j1]
        second = values[int(order[1])] if m > 1 else best - 1.0
        displaced = int(owner_obj[j1])
        if displaced >= 0:
            unassigned.append(displaced)
        owner_obj[j1] = i
        prices[j1] += (best - second) + epsilon
    assignment = [(int(r), int(c)) for c, r in enumerate(owner_obj) if r >= 0]
    if transposed:
        assignment = [(c, r) for r, c in assignment]
    return [(int(rows[i]), int(cols[j])) for i, j in assignment if np.isfinite(sub[i, j])]


def _legacy_pairs(inp: Observations, out: Observations,
                  cfg: AssociationConfig) -> List[Tuple[int, int]]:
    """Reference copy of v1 (scan, trkID) semantics for benchmark comparison.

    Production ``legacy_id`` does NOT use this: it delegates to v1 verbatim.
    The copy exists so every backend can be measured through one evaluator.
    """
    buckets: Dict[int, List[int]] = {}
    for j, tid in enumerate(out.ids):
        if np.isfinite(tid):
            buckets.setdefault(int(tid), []).append(j)
    pairs: List[Tuple[int, int]] = []
    for i, tid in enumerate(inp.ids):
        if not np.isfinite(tid):
            continue
        queue = buckets.get(int(tid))
        if not queue:
            continue
        j = queue.pop(0)
        if (abs(inp.x[i] - out.x[j]) <= cfg.tx
                and abs(inp.y[i] - out.y[j]) <= cfg.ty
                and (not (np.isfinite(inp.vx[i]) and np.isfinite(out.vx[j]))
                     or abs(inp.vx[i] - out.vx[j]) <= cfg.tvx)
                and (not (np.isfinite(inp.vy[i]) and np.isfinite(out.vy[j]))
                     or abs(inp.vy[i] - out.vy[j]) <= cfg.tvy)
                and np.isfinite(inp.f_moving[i]) and np.isfinite(out.f_moving[j])
                and inp.f_moving[i] == out.f_moving[j]):
            pairs.append((i, j))
    return pairs


def _greedy_pairs(cost: np.ndarray) -> List[Tuple[int, int]]:
    """Legacy CSV proxy: first-match greedy nearest, no global assignment."""
    finite = np.isfinite(cost)
    if not finite.any():
        return []
    order = np.argsort(np.where(finite, cost, _BIG), axis=None)
    used_i, used_j, pairs = set(), set(), []
    for flat in order:
        i, j = np.unravel_index(int(flat), cost.shape)
        if not finite[i, j]:
            break
        if i in used_i or j in used_j:
            continue
        used_i.add(int(i))
        used_j.add(int(j))
        pairs.append((int(i), int(j)))
    return pairs


@dataclass
class _MultiScanState:
    """History for the temporal backend (keyed by stable input track ID)."""
    frames: List[Observations]
    last_out_id: Dict[int, float]


def _multi_scan_cost(inp: Observations, out: Observations, cfg: AssociationConfig,
                     state: _MultiScanState) -> np.ndarray:
    """Algorithm 4: windowed constant-velocity projection + ID-switch penalty.

    History is aligned by stable input track ID (not row index), so a dropped or
    reordered slot cannot shift the prediction onto the wrong physical object.
    """
    k = _kinematics(inp, out)
    pos = ((k["dx"] / cfg.tx) ** 2 + (k["dy"] / cfg.ty) ** 2)
    window_err = pos.copy()
    anchor_count = np.ones_like(pos)
    history = state.frames[-(cfg.window - 1):] if cfg.window > 1 else []
    for back, frame in enumerate(reversed(history)):
        dt = (back + 1) * cfg.scan_period_s
        lookup = {int(t): n for n, t in enumerate(frame.ids) if np.isfinite(t)}
        src = np.array([lookup.get(int(t), -1) if np.isfinite(t) else -1
                        for t in inp.ids], dtype=int)
        has = src >= 0
        if not has.any():
            continue
        safe = np.where(has, src, 0)
        px = np.full(len(inp), np.nan)
        py = np.full(len(inp), np.nan)
        px[has] = frame.x[safe[has]] + frame.vx[safe[has]] * dt
        py[has] = frame.y[safe[has]] + frame.vy[safe[has]] * dt
        err = ((px[:, None] - out.x[None, :]) / cfg.tx) ** 2 + (
            (py[:, None] - out.y[None, :]) / cfg.ty) ** 2
        window_err += np.nan_to_num(err, nan=0.0)
        anchor_count += has[:, None].astype(float)
    window_err /= np.maximum(anchor_count, 1.0)
    cost = 0.5 * pos + 0.5 * window_err
    cost = cost + cfg.velocity_weight * (
        np.where(k["vx_known"], (k["dvx"] / cfg.tvx) ** 2, 0.0)
        + np.where(k["vy_known"], (k["dvy"] / cfg.tvy) ** 2, 0.0)
    )
    for i, tid in enumerate(inp.ids):
        prev = state.last_out_id.get(int(tid)) if np.isfinite(tid) else None
        if prev is not None and np.isfinite(prev):
            cost[i, out.ids == prev] += cfg.id_switch_penalty
    return np.where(_gate(k, cfg), cost, np.inf)


def _associate_frame(inp: Observations, out: Observations, cfg: AssociationConfig,
                     state: Optional[_MultiScanState]) -> List[Tuple[int, int]]:
    """Dispatch one scan to the configured association backend."""
    if len(inp) == 0 or len(out) == 0:
        return []
    algo = cfg.algorithm
    if algo == "legacy_id":
        return _legacy_pairs(inp, out, cfg)
    if algo == "hungarian_normalized":
        return _solve(_normalized_cost(inp, out, cfg))
    if algo == "greedy_nearest":
        return _greedy_pairs(_normalized_cost(inp, out, cfg))
    if algo == "mahalanobis":
        return _solve(_mahalanobis_cost(inp, out, cfg))
    if algo == "gospa":
        cost, d = _gospa_cost(inp, out, cfg)
        return [(i, j) for i, j in _solve(cost) if d[i, j] < cfg.gospa_cutoff]
    if algo == "multi_scan":
        assert state is not None
        return _solve(_multi_scan_cost(inp, out, cfg, state))
    if algo == "obb_auction":
        return _auction(_obb_auction_cost(inp, out, cfg), cfg.auction_epsilon)
    raise ValueError(f"unsupported association algorithm {algo!r}")


def _gospa_terms(n_in: int, n_out: int, pairs: Sequence[Tuple[int, int]],
                 d: np.ndarray, cfg: AssociationConfig) -> Dict[str, float]:
    """GOSPA decomposition into localization, missed and false-target terms."""
    c, p, alpha = cfg.gospa_cutoff, cfg.gospa_order, cfg.gospa_alpha
    k = len(pairs)
    loc = float(sum(float(d[i, j]) ** p for i, j in pairs))
    missed = (c ** p / alpha) * (n_in - k)
    false = (c ** p / alpha) * (n_out - k)
    total = (loc + missed + false) ** (1.0 / p) if (loc + missed + false) > 0 else 0.0
    return {
        "localization_term": loc,
        "missed_penalty": float(missed),
        "false_penalty": float(false),
        "gospa": float(total),
    }


def associate_arrays(input_tracks: Dict[str, Any], output_tracks: Dict[str, Any],
                     cfg: AssociationConfig,
                     scan_values: Optional[Sequence[Any]] = None) -> Dict[str, Any]:
    """Run per-scan association over two tracker signal dicts.

    Returns the same result contract as
    :meth:`TrackerMappingKPIHDF.match_tracker_data` so the v1 KPI/HTML layer is
    reused unchanged, plus ``algorithm`` and (for GOSPA) ``gospa``.
    """
    in_fields, n_in_scans, _ = _prepare(input_tracks)
    out_fields, n_out_scans, _ = _prepare(output_tracks)
    if n_in_scans == 0 or n_out_scans == 0:
        return {}
    n_scans = int(min(n_in_scans, n_out_scans))
    in_valid = _valid_mask(in_fields, cfg)
    out_valid = _valid_mask(out_fields, cfg)
    state = _MultiScanState(frames=[], last_out_id={}) if cfg.algorithm == "multi_scan" else None

    matched: List[Dict[str, Any]] = []
    per_scan: List[Dict[str, Any]] = []
    position_errors: List[float] = []
    velocity_errors: List[float] = []
    totals = {"tp": 0, "fp": 0, "fn": 0, "n_in": 0, "n_out": 0}
    fm_agree = fm_cooccur = 0
    scans_with_matches = 0
    in_ids, out_ids = set(), set()
    gospa_terms: List[Dict[str, float]] = []

    for row in range(n_scans):
        inp = _observations(in_fields, row, in_valid[row])
        outp = _observations(out_fields, row, out_valid[row])
        in_ids.update(int(v) for v in inp.ids if np.isfinite(v))
        out_ids.update(int(v) for v in outp.ids if np.isfinite(v))
        totals["n_in"] += len(inp)
        totals["n_out"] += len(outp)

        pairs: List[Tuple[int, int]] = []
        if cfg.algorithm == "gospa":
            if len(inp) and len(outp):
                cost, d = _gospa_cost(inp, outp, cfg)
                pairs = [(i, j) for i, j in _solve(cost) if d[i, j] < cfg.gospa_cutoff]
                gospa_terms.append(_gospa_terms(len(inp), len(outp), pairs, d, cfg))
            else:
                # Cardinality-only scan: missed/false penalties still apply.
                gospa_terms.append(
                    _gospa_terms(len(inp), len(outp), [], np.zeros((0, 0)), cfg)
                )
        elif state is not None:
            pairs = _associate_frame(inp, outp, cfg, state)
            state.frames.append(inp)
            state.frames = state.frames[-cfg.window:]
            for i, j in pairs:
                if np.isfinite(inp.ids[i]) and np.isfinite(outp.ids[j]):
                    state.last_out_id[int(inp.ids[i])] = float(outp.ids[j])
        else:
            pairs = _associate_frame(inp, outp, cfg, state)

        scan_value = scan_values[row] if scan_values is not None and row < len(scan_values) else row
        for i, j in pairs:
            dist = float(np.hypot(inp.x[i] - outp.x[j], inp.y[i] - outp.y[j]))
            in_vel = np.array([inp.vx[i], inp.vy[i]], dtype=float)
            out_vel = np.array([outp.vx[j], outp.vy[j]], dtype=float)
            matched.append({
                "scan_row": int(row),
                "scan_value": scan_value,
                "input_track_id": int(inp.ids[i]),
                "output_track_id": int(outp.ids[j]),
                "input_pos": np.array([inp.x[i], inp.y[i]], dtype=float),
                "output_pos": np.array([outp.x[j], outp.y[j]], dtype=float),
                "spatial_distance": dist,
                "input_vel": in_vel,
                "output_vel": out_vel,
                "fmoving_agree": bool(
                    not np.isfinite(inp.f_moving[i]) or not np.isfinite(outp.f_moving[j])
                    or inp.f_moving[i] == outp.f_moving[j]
                ),
                "vx_gate_skipped": bool(not (np.isfinite(inp.vx[i]) and np.isfinite(outp.vx[j]))),
                "vy_gate_skipped": bool(not (np.isfinite(inp.vy[i]) and np.isfinite(outp.vy[j]))),
                "input_index": int(i),
                "output_index": int(j),
            })
            position_errors.append(dist)
            verr = float(np.linalg.norm(in_vel - out_vel))
            if np.isfinite(verr):
                velocity_errors.append(verr)
            fm_cooccur += 1
            fm_agree += int(np.isfinite(inp.f_moving[i]) and np.isfinite(outp.f_moving[j])
                            and inp.f_moving[i] == outp.f_moving[j])

        tp = len(pairs)
        fp = max(len(outp) - tp, 0)
        fn = max(len(inp) - tp, 0)
        totals["tp"] += tp
        totals["fp"] += fp
        totals["fn"] += fn
        if tp:
            scans_with_matches += 1
        den = tp + fn
        per_scan.append({
            "scan_row": int(row),
            "scan_value": scan_value,
            "tp": int(tp), "fp": int(fp), "fn": int(fn),
            "matches": int(tp), "den": int(den),
            "acc_pct": float(100.0 * tp / den) if den else (100.0 if tp == 0 and fp == 0 else 0.0),
            "n_in": int(len(inp)), "n_out": int(len(outp)),
        })

    id_overlap = {
        "common": len(in_ids & out_ids),
        "union": len(in_ids | out_ids),
        "input_only": len(in_ids - out_ids),
        "output_only": len(out_ids - in_ids),
        "n_input_ids": len(in_ids),
        "n_output_ids": len(out_ids),
    }
    result: Dict[str, Any] = {
        "matched_tracks": matched,
        "total_matches": int(totals["tp"]),
        "total_fp": int(totals["fp"]),
        "total_fn": int(totals["fn"]),
        "total_in_valid": int(totals["n_in"]),
        "total_out_valid": int(totals["n_out"]),
        "scans_compared": int(n_scans),
        "scans_with_matches": int(scans_with_matches),
        "fmoving_agree": int(fm_agree),
        "fmoving_cooccur": int(fm_cooccur),
        "position_errors": [float(v) for v in position_errors],
        "velocity_errors": [float(v) for v in velocity_errors],
        "per_scan": per_scan,
        "id_overlap": id_overlap,
        "algorithm": cfg.algorithm,
    }
    if gospa_terms:
        n = float(len(gospa_terms))
        result["gospa"] = {
            "mean": float(np.mean([g["gospa"] for g in gospa_terms])),
            "localization_mean": float(np.mean([g["localization_term"] for g in gospa_terms])) ** 0.5,
            "missed_mean": float(np.mean([g["missed_penalty"] for g in gospa_terms])),
            "false_mean": float(np.mean([g["false_penalty"] for g in gospa_terms])),
            "scans": len(gospa_terms),
        }
    return result


class TrackerMappingKPIHDFv2(TrackerMappingKPIHDF):
    """v1 tracker KPI with a pluggable association backend."""

    def __init__(self, input_data, output_data, sensor_id: str, stream_name: str,
                 algorithm: Optional[str] = None,
                 config: Optional[AssociationConfig] = None):
        super().__init__(input_data, output_data, sensor_id, stream_name)
        self.assoc_config = config or AssociationConfig.from_thresholds(
            self.thresholds, algorithm
        )
        if algorithm is not None and config is not None:
            self.assoc_config = config.with_algorithm(algorithm)
        self.association_algorithm = self.assoc_config.algorithm

    def match_tracker_data(self, input_data: Dict[str, np.ndarray],
                           output_data: Dict[str, np.ndarray]) -> Dict[str, Any]:
        """Legacy path is byte-identical to v1; all others use association."""
        if self.association_algorithm == "legacy_id":
            return super().match_tracker_data(input_data, output_data)
        try:
            scan_values = list(getattr(self.input_data, "_data_container", {}).keys())
            result = associate_arrays(
                input_data, output_data, self.assoc_config, scan_values or None
            )
            if result:
                from UDP_KPI.c_business_layer.tracker_matching_kpi import (
                    _TRACKER_PLOT_PAIR_CAP,
                )
                plot_pairs = result["matched_tracks"][:_TRACKER_PLOT_PAIR_CAP]
                self.matched_tracks_df = pd.DataFrame(plot_pairs) if plot_pairs else pd.DataFrame()
            return result
        except Exception as exc:  # never lose a report on one bad scan
            logger.error("v2 association failed: %s", exc)
            return {}

    def calculate_tracker_kpis(self, matching_results: Dict) -> None:
        super().calculate_tracker_kpis(matching_results)
        algo = self.association_algorithm
        if algo == "legacy_id" or not self.kpi_results:
            return
        mode = f"association:{algo} (ID-independent)"
        self.kpi_results["matching_mode"] = mode
        self.kpi_results["association_algorithm"] = algo
        self.kpi_results.setdefault("thresholds", {})["matching_mode"] = mode
        self.kpi_results["thresholds"]["association_algorithm"] = algo
        mr = matching_results or {}
        if "gospa" in mr:
            self.kpi_results["gospa"] = mr["gospa"]
            self.summary_stats["gospa"] = mr["gospa"]["mean"]
            self.summary_stats["gospa_localization"] = mr["gospa"]["localization_mean"]

    def generate_html_report(self) -> None:
        """Reuse v1 HTML, correcting the stale composite-key description."""
        super().generate_html_report()
        algo = self.association_algorithm
        if algo == "legacy_id" or not self.html_content:
            return
        self.html_content = self.html_content.replace(
            "per scan on the composite key (scan, trkID) with one-to-one consume, "
            "mirroring CAN-KPI hashmap discipline.",
            f"per scan with ID-independent '{algo}' association "
            "(kinematic gates + global assignment); track IDs are not used as keys.",
        )
        self.html_content = self.html_content.replace(
            "Tracker Matching KPI Results",
            f"Tracker Matching KPI Results [{algo}]",
            1,
        )


def process_tracker_kpi_v2(input_data, output_data, sensor_id: str, stream_name: str,
                           algorithm: Optional[str] = None) -> Dict[str, Any]:
    """Drop-in replacement for :func:`process_tracker_kpi` with association."""
    try:
        processor = TrackerMappingKPIHDFv2(
            input_data, output_data, sensor_id, stream_name, algorithm=algorithm
        )
        if processor.process_tracker_matching():
            return processor.get_results()
        return {
            "kpi_results": {},
            "html_content": f"<p>Failed to process tracker KPIs for {sensor_id}</p>",
            "success": False,
        }
    except Exception as exc:
        logger.error("Error in process_tracker_kpi_v2: %s", exc)
        return {
            "kpi_results": {},
            "html_content": f"<p>Error processing tracker KPIs: {exc}</p>",
            "success": False,
        }
