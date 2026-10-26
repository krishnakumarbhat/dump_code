# Tracker KPI Association Overhaul — Benchmark Report

**Scope:** `ALL_KPI/KPI/UDP_KPI/c_business_layer/tracker_matching_kpi.py` → `tracker_matching_kpi_v2.py`
**Date:** 2026-10-26
**Runner:** `empirical_research_harness/benchmarks/benchmark_tracker_kpi_algorithms.py`
**Artifacts:** `benchmark_results.json`, `benchmark_tables.md`, ranked HTML on Desktop
(`tracker_kpi_algorithm_benchmark.html`), unit tests `UDP_KPI/tests/test_tracker_id_indexed_kpi.py`.

---

## 1. Executive comparison

Scenes A–D are controlled synthetic cases; E is a real 295-scan HDF tracker pair. Synthetic
gates are the configured 1 cm / 0.02 m/s; E uses a perception tolerance of 1.5 m / 2 m/s
(the production 1 cm result is reported separately as E-tight). Ranked by mean F1 over A–E.

| F1 rank | Algorithm | Association basis | Precision % | Recall % | F1 % | Jaccard % | IDSW | IDSW/1k matches | Loc err m | ms / 1k scans | Deployment |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | `mahalanobis` | χ² innovation gate + Munkres | 72.64 | 97.66 | 76.91 | 70.82 | 102 | 4.2 | 0.057 | 1210 | Best real-log F1 (opt-in) |
| 2 | `gospa` | GOSPA (c=2 m, p=2, α=2) | 72.51 | 97.52 | 76.77 | 70.61 | 237 | 9.7 | 0.043 | 1085 | FP/FN decomposition (opt-in) |
| 3 | `hungarian_normalized` | Hard gates + normalized Euclidean Hungarian | 71.92 | 96.93 | 76.18 | 69.71 | 49 | 2.1 | 0.035 | 1067 | **Production default (gate-faithful)** |
| 4 | `multi_scan` | Sliding-window projection + ID-switch penalty | 71.92 | 96.93 | 76.18 | 69.71 | 73 | 3.1 | 0.035 | 2027 | Occlusion/dropouts (opt-in) |
| 5 | `obb_auction` | Oriented box + Doppler + auction | 70.91 | 95.91 | 75.17 | 68.26 | 35 | 1.6 | 0.021 | 1301 | Extended objects (opt-in) |

Legacy baselines, re-scored with uniform FP accounting (`FP = all unmatched outputs`, so
v1's consumed-but-gate-failed outputs are visible):

| Algorithm | Scene | TP | FP | FN | Prec % | Rec % | F1 % |
|---|---|---|---|---|---|---|---|
| `legacy_id` | A (shuffled IDs) | 0 | 80 | 80 | 0.00 | 0.00 | 0.00 |
| `greedy_nearest` (CSV proxy) | A | 80 | 0 | 0 | 100.00 | 100.00 | 100.00 |
| `legacy_id` | B (ID swap) | 20 | 10 | 10 | 66.67 | 66.67 | 66.67 |
| `greedy_nearest` | B | 30 | 0 | 0 | 100.00 | 100.00 | 100.00 |
| `legacy_id` | C (5 + 50 clutter) | 0 | 550 | 50 | 0.00 | 0.00 | 0.00 |
| `greedy_nearest` | C | 50 | 500 | 0 | 9.09 | **100.00** | 16.67 |
| `legacy_id` | D (glint/sign) | 0 | 24 | 16 | 0.00 | 0.00 | 0.00 |
| `greedy_nearest` | D | 16 | 8 | 0 | 66.67 | 100.00 | 80.00 |
| `legacy_id` | E (real pair) | 6110 | 21741 | 21480 | 21.94 | 22.15 | 22.04 |
| `greedy_nearest` | E | 23353 | 4498 | 4237 | 83.85 | 84.64 | 84.24 |

**F1 rank is not the deployment order.** All five backends tie on A–D; E is the only
discriminator. Mahalanobis and GOSPA lead there because their gates scale with range and
accept pairs outside the configured 1 cm tolerance (E-tight below). For a KPI whose job is
to verify replay fidelity against a configured acceptance tolerance, that is a semantic
violation, so the gate-faithful, fastest, lowest-ID-switch Hungarian remains the default.

Per-scene F1 (%):

| Scene | mahalanobis | gospa | hungarian_normalized | multi_scan | obb_auction |
|---|---|---|---|---|---|
| A clean shuffled IDs | 100.00 | 100.00 | 100.00 | 100.00 | 100.00 |
| B crossing / ID swap | 100.00 | 100.00 | 100.00 | 100.00 | 100.00 |
| C clutter | 16.67 | 16.67 | 16.67 | 16.67 | 16.67 |
| D stationary decoys | 80.00 | 80.00 | 80.00 | 80.00 | 80.00 |
| E real HDF | 87.86 | 87.19 | 84.24 | 84.24 | 79.17 |

**Production-config result (E-tight, 1 cm / 0.02 m/s):**

| Algorithm | F1 % | Comment |
|---|---|---|
| `legacy_id` | 17.86 | ID equality collapses even where positions match |
| `hungarian_normalized` | 53.26 | Matches only positions that survived 2-decimal quantisation |
| `multi_scan` | 53.26 | Same gate, plus temporal cost |
| `obb_auction` | 79.17 | Box envelope is wider than the cm gate |
| `mahalanobis` | 87.86 | **Ignores tx/ty** — gate is χ² with σ(r) |
| `gospa` | 87.19 | **Ignores tx/ty** — gate is c=2 m |

This table is the clearest proof that algorithm choice and gate semantics must be made
together. A 1 cm acceptance gate is a deterministic-replay criterion, not a perception
tolerance; `mahalanobis`/`gospa` are only meaningful after relaxing the configured gates.

---

## 2. Root cause: why `(scan, trkID)` is invalid

`tracker_matching_kpi.py:270-378` builds per-scan `int(trkID) -> deque` maps and pops one
output per input in slot order. Consequences measured above:

1. **Scene A:** identical positions, output IDs `101..110` → legacy F1 **0%**, all five
   association backends **100%**. The KPI was measuring ID allocation, not tracking.
2. **Scene B:** output IDs swap at the crossing → legacy loses 10 of 15 scans even though
   both physical tracks are present (F1 66.7% vs 100%).
3. **Scene E:** real logs drift to 49.18% per-scan ID-set Jaccard (measured: 606 vs 616
   distinct IDs, 295×128 slots); legacy TP 6,110 vs 23,353 for the same gate.
4. **Precision is inflated by v1 bookkeeping:** when an ID co-occurs but a kinematic gate
   fails, v1 consumes the output (`out_dq.popleft()` at line 317) and counts only an FN —
   the output never becomes FP. The benchmark re-scores the same pairing with uniform FP,
   which is why the baseline table is harsher than the v1 HTML.
5. **NaN `f_moving` is a mismatch** in v1 (lines 339-342), so a log that omits the flag
   scores 0% by construction.

---

## 3. Algorithms: math, strengths, failure modes

### 3.1 `hungarian_normalized` (production default)

Hard gates per axis plus `f_moving` agreement, then weighted squared normalized cost:

```
C_ij = w_p[(Δx/Tx)² + (Δy/Ty)²] + w_v[(Δvx/Tvx)² + (Δvy/Tvy)²]
```

solved with `scipy.optimize.linear_sum_assignment`; non-finite (gated) entries are removed
after assignment.

```python
def _normalized_cost(inp, out, cfg):
    k = _kinematics(inp, out)
    cost = cfg.position_weight * ((k["dx"]/cfg.tx)**2 + (k["dy"]/cfg.ty)**2)
    cost += cfg.velocity_weight * (
        np.where(k["vx_known"], (k["dvx"]/cfg.tvx)**2, 0.0)
        + np.where(k["vy_known"], (k["dvy"]/cfg.tvy)**2, 0.0))
    return np.where(_gate(k, cfg), cost, np.inf)
```

**Strengths:** honours the configured acceptance gates exactly; global optimum; 1,067 ms per
1,000 scans at 128 slots; lowest IDSW/1k among high-recall backends (2.1); deterministic.
**Failure:** hard gates are brittle when the reference and replay disagree by more than the
gate — which is exactly what a real regression log does. It also cannot exploit history.

### 3.2 `mahalanobis`

Innovation `y = z_out − z_in`, diagonal innovation covariance from range-dependent sensor
noise (`σ_p = 0.3 + 0.02·max(r_in,r_out) m`, `σ_v = 0.2 + 0.02·speed`), statistical distance
`d² = yᵀS⁻¹y`, gate at χ²₉₉ (2/3/4 DOF), cost `d² + ln|S|`.

```python
d2 = (k["dx"]**2 + k["dy"]**2) / var_p
d2 += np.where(k["vx_known"], k["dvx"]**2 / var_v, 0.0)
d2 += np.where(k["vy_known"], k["dvy"]**2 / var_v, 0.0)
cost = np.where(d2 <= crit, d2 + logdet, np.inf)
```

**Strengths:** principled, calibration-friendly, best real-log F1 (87.86). **Failure:** at
100 m the gate is ~7-8 m, so it can bind different physical objects and it ignores the
configured tx/ty; highest IDSW among the accurate backends (102). Use only with a
perception-tolerance KPI, not the replay-fidelity KPI.

### 3.3 `gospa`

For cutoff `c`, order `p`, `α=2`, per scan:

```
d_p^(c,α)(X,Y) = ( min_π Σ d_c(x_i,y_j)^p + (c^p/α)(|X|−|π|) + (c^p/α)(|Y|−|π|) )^(1/p)
```

Assignment uses the truncated metric, then the total is decomposed into localization,
missed-target and false-target terms (`result["gospa"]`).

**Strengths:** no heuristic asymmetry, explicit FN/FP accounting, standard in automotive
benchmarking. **Failure:** fixed `c` is itself a tuning choice; it produced 237 ID switches
on E and its 87.19 F1 again comes from a 2 m gate, not the configured 1 cm. Use it as the
**reporting metric**, not necessarily the production matcher.

### 3.4 `multi_scan`

For scan `t`, input track IDs are projected from the last `W−1` frames with constant
velocity (`p(t0) + v·Δt`) and averaged with the current-frame cost; a per-input-ID
assignment memory adds an `id_switch_penalty` when the output ID changes.

```python
px = frame.x[safe] + frame.vx[safe] * dt
py = frame.y[safe] + frame.vy[safe] * dt
window_err += np.nan_to_num(((px[:,None]-out.x)**2/cfg.tx**2
                           + (py[:,None]-out.y)**2/cfg.ty**2))
cost = 0.5*pos + 0.5*(window_err / anchor_count) + id_switch_penalty
```

**Strengths:** robust to gate jitter and short dropouts, holds identity through crossings;
reduces to Hungarian at `window=1`. **Failure:** 2× latency (2,027 ms/1k) and no benefit on
this corpus because the real pair's dominant error is cardinality drift, not single-frame
gating. Needs the scan period (`0.05 s`).

### 3.5 `obb_auction`

Oriented box containment (`|l_x| ≤ L/2+margin`, `|l_y| ≤ W/2+margin` in the input heading
frame) plus radial Doppler consistency `|v_r,in − v_r,out| ≤ 3σ_v`, assigned by Bertsekas
ε-auction with a Hungarian fallback.

**Strengths:** best localization error (0.021 m) and lowest IDSW/1k (1.6) on E; models
vehicle extent and line-of-sight Doppler. **Failure:** box containment is permissive for
adjacent vehicles at 1.5 m lateral separation, and its F1 is the lowest (75.17) because
extent + Doppler reject some genuinely matched tracks. Auction is ~22% slower than Hungarian.

---

## 4. Real HDF data audit

The directive names
`edge_hdf/udp/input/CCA_9010_3100099_DEBUG_20250828_163718_0001_r00070104.h5` and its output
pair. **That pair contains no tracker stream** — only `DETECTION_STREAM`, `RDD_STREAM`,
`HEADER_STREAM` (verified by walking every dataset). It cannot exercise tracker association.

Real tracker logs available in this checkout are the SRR/MRR report HDFs under
`03_TrackerInfo/Tracker_Output/AllObjects`, shape `295 × 128`, with `trkID`, `vcs_xposn`,
`vcs_yposn`, `vcs_xvel`, `vcs_yvel`, `f_moving`, `len1`, `wid1`, `vcs_heading`. The harness
therefore uses:

- input: `edge_hdf/udp/SRR_CCA_9010_3100099_DEBUG_20250828_163933_0010_HDF_Report.h5`
- output: `..._HDF_Report_CDC.h5` (same recording, CDC variant)

Measured properties: 605 vs 615 non-zero IDs (606/616 including the empty-slot 0); 538 `x < −100` CAN sentinels per file;
per-scan ID-set Jaccard **49.18%**; nearest-neighbour distance ≤1.5 m for 100% of objects in
early scans but only 64% by scan 290 — i.e. the two runs diverge physically, which is what a
regression KPI should expose. They are not a ground-truth pair, so scene E deliberately has
no physical-swap truth; its role is tolerance to ID churn, precision/recall and latency.

Also found: `KPIHDFParser` only accepts `TRACKER_STREAM`/`OBJECT_LIST_STREAM` at depth 2, so
`03_TrackerInfo/...` report HDFs are invisible to the production tracker KPI path. The
harness reads them directly with h5py. Fixing ingestion is a separate change; it is not
required for the association engine.

---

## 5. Legacy CSV audit (what is and is not in this checkout)

The historical CSV matcher referenced in the directive is **not present** in this
repository; no `threshold_mul_factor` symbol exists anywhere under `ALL_KPI/`. The audit is
therefore code-grounded on the v1 HDF matcher plus a measured greedy-nearest proxy, not on
unavailable source. The four failure classes are still reproducible:

1. **Composite ID key** — measured, scene A: 0% F1; E: 22.04% F1.
2. **Greedy first match** — the proxy ties Hungarian on clean exact matches (A/B) and on the
   real pair, so greed alone is *not* the decisive defect; the historical bug matters through
   slot-order dependence and threshold leakage, which cannot be measured without the script.
3. **L∞ box vs physical envelope** — v1 gates `|Δx| ≤ Tx and |Δy| ≤ Ty`, i.e. a square box;
   OBB (algorithm 5) reduces E localization error from 0.035 m to 0.021 m at the same recall
   class, and is the correct envelope for extended vehicles.
4. **Recall-only accuracy** — scene C: greedy recall **100%** while 50 of 55 outputs are
   false alarms (precision 9.09%, F1 16.67%). Any KPI hero number of `TP/Input` reports a
   100% false win here. The v2 report keeps `TP/Input` for backward compatibility but adds
   precision/F1/Jaccard and never labels it "accuracy" without the denominator.

The v1 NaN-motion rule and silent FP consumption are fixed in v2: NaN flags no longer veto a
pair, and every unmatched output is counted as FP (so C cannot look clean).

---

## 6. Production switch

The backend is selected by one config key in
`UDP_KPI/b_data_storage/kpi_config_storage.py`:

```python
KPI_VALIDATION_RULES["tracker_thresholds"]["association_algorithm"] = "hungarian_normalized"
```

Accepted values: `legacy_id`, `hungarian_normalized`, `mahalanobis`, `gospa`, `multi_scan`,
`obb_auction`. `legacy_id` runs the original `TrackerMappingKPIHDF.match_tracker_data`
unchanged (verified by a byte-compatible test); any other value routes the factory to
`process_tracker_kpi_v2`. Per-run override:

```python
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2
result = process_tracker_kpi_v2(input_storage, output_storage, sensor, "TRACKER_STREAM",
                                algorithm="mahalanobis")
```

Tuning keys (all optional, defaults shown): `association_window=3`, `gospa_cutoff=2.0`,
`auction_epsilon=0.001`. For perception benchmarking with real logs, relax
`vcs_xposn_threshold`/`vcs_yposn_threshold` to the physical tolerance (e.g. 1.5 m,
2.0 m/s) **and** pick `mahalanobis`; do not relax the gates while keeping Hungarian, because
Hungarian will then accept more wrong pairs too.

Rollback: set the key to `legacy_id`. No code change, no schema change, HTML contract intact
(the wrapper summary regex still finds `Tracker Accuracy: (n/d) → x%`).

---

## 7. Verification

- `python -m pytest UDP_KPI/tests -q` → **20 passed** (14 tracker tests, including v1/v2
  byte-compatibility, shuffled-ID recovery for all five backends, clutter FP accounting,
  config-driven factory switch).
- Benchmark self-checks → **7/7 PASS**: shuffled IDs, legacy failure, crossing, clutter
  false-win guard, glint rejection, real HDF execution, auction optimality within ε.
- End-to-end HDF ingestion via `KPIHDFWrapper` is **not** exercised by the bundled dummy
  pairs: their scan-index header is degenerate (all-zero), so the existing wrapper skips
  every stream. This predates the change and is unaffected by it; the storage-level and
  factory-level paths are covered by tests.
- Machine: Windows, Python 3.x, numpy 2.4.6, scipy 1.17.1, h5py 3.15.1. Latency numbers are
  single-run wall clock on this host (295 real scans + 51 synthetic scans per algorithm);
  treat them as relative, not certified WCET.

## 8. Limitations / SOTIF notes

- No ground-truth occupancy on the real pair; scene E measures consistency, not truth.
- ID switches on E reflect output labeling churn, not a matcher defect; they are reported
  because MOTA/HOTA require them.
- GOSPA is decomposed per scan but not temporally aggregated with a track-level metric
  (HOTA identity association is out of scope).
- The 1 cm production gate is a replay-fidelity threshold; do not present E-tight F1 as
  tracking accuracy in an OEM audit.
- `mahalanobis` assumes diagonal innovation covariance; a full `S` from the tracker's
  `state_variance` (available in the report HDF) is the upgrade path if covariance is trusted.
