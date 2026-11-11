# APRISM — Empirical Radar Research Verification Harness

Self-contained, isolated verification harness that measures **BASELINE (production path, feature
OFF)** vs **A-PRISM (research path, feature ON)** for 27 radar research concepts.

> **No production C/C++ tree was modified.** Everything here is a read-only mirror.

---

## 1. What this is (and is not)

This is an **empirical A/B harness**, not a set of asserted numbers.

1. Physics-grounded radar fixtures are generated from first principles
   (`x[n] = A·e^{j(2πf_b·n·T_s + φ)} + w[n]`, `τ = 2r/c`, `r = c·τ/2`, `R⁻⁴` spreading).
2. The **production kernels are mirrored 1:1 in Python/numpy** (`aprism_harness/kernels.py`),
   transcribed from the actual C/C++ sources — not paraphrased.
3. BASELINE and A-PRISM run on **bit-identical inputs** (same seed, same fixture).
4. Metrics are **measured** by executing the mirrors: error distributions, convergence curves,
   operation counts, detection masks, covariance ellipses.
5. Every concept emits interactive Plotly HTML **and** static Matplotlib PNG.

**Every number in `results/` is produced by the code. None is hardcoded.**

---

## 2. Run it

```bash
pip install -r requirements.txt

python run_all.py                     # one seed
python run_all.py --seeds 0 1 2 42    # multi-seed robustness sweep
python run_all.py --only 10 13        # subset
python export_results_md.py           # regenerate results/RESULTS.md
```

### Outputs (`results/`)

| Path | Contents |
|---|---|
| `html/concept_XX_<slug>.html` | 62 interactive Plotly figures |
| `png/concept_XX_<slug>.png` | 62 static Matplotlib figures |
| `master_research_benchmarks.html` | master portal: summary table + per-concept metrics, formula and figures |
| `metrics.json` | every measured metric, per seed |
| `RESULTS.md` | the same metrics as a markdown table |

The runner self-verifies: it fails with a non-zero exit if any concept fails or any artefact is
missing/empty.

---

## 3. Layout

```
empirical_research_harness/
  aprism_harness/
    kernels.py       1:1 mirrors of the production C/C++ kernels (the fidelity core)
    signals.py       physics-grounded fixture generators (FMCW, RD maps, geometry, EKF truth)
    concept_api.py   result contract + metric helpers (rmse, roc/auc, eps-guarded division)
    concepts_a.py    concepts #1-#9    (Gen8 DSP firmware)
    concepts_b.py    concepts #10-#18 (domain-controller tracker)
    concepts_c.py    concepts #19-#27 (SIL / replay / algorithm-level)
    plots.py         Plotly -> HTML, Plotly -> Matplotlib PNG converter
    dashboard.py     master portal builder (incl. the formula table)
  run_all.py         orchestrator + verification
  export_results_md.py
```

---

## 4. Kernel fidelity — source of truth

| Kernel | Mirrored from |
|---|---|
| `aprism_dual_loop_floor`, `aprism_blue_weights`, `aprism_alpha_for_pfa`, `aprism_ca_alpha`, `aprism_cfar_overlay` | `Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c`, `appl_cfar_ifc.c` |
| `cdc_priority_score`, `cdc_select_top_k` | `Core_Radar_Gen8_iND13400/software/bbe32/src/cdc_priority.c`, `cdc_packing.c` |
| `ghost_inverse_contact`, `ghost_estimate_yaw`, `ghost_certify`, `hermite_solve2`, `clock_tau1`, `clock_tau_bias2` | `Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/ghost_calib.c` |
| `da_dual_horizon_gain`, `da_lock_detect` | `Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/dyn_align_wrapper.c` |
| `residual_lag1`, `residual_cubic4`, `residual_quant8`, `residual_quant_angle_bound` | `Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c` |
| `adaptive_gamma`, `rank_gate_apply`, `doppler_gate`, `entropy_scale`, `rank1_residual`, `virtual_sensor`, `reff_inflate`, `curvature_ok` | `core-resim-dc-emb-library/.../Fusion360/include/aprism_ot_hooks.h` |
| `TrackValidityFSM`, `DetSidecar`, `ConfirmStore` | `.../Fusion360/track_validity/source/f360_track_validity.cpp` |
| `kalman_update` (Joseph form) | `.../measurement_update_tracks/source/f360_msmt_update_obj_trks_cca_moveable.cpp` |
| `ctca_covariance` | `.../measurement_update_tracks/source/f360_msmt_update_support_functions_ctca.cpp` |
| `preflight_seed`, `deskew` | `core-resim-dc-emb-library/DC_SIL/sil_wrappers/Tracker_VariantA_Wrapper.cpp`, `sil_wrapper.cpp` |

The A-PRISM deltas themselves were taken from the reference patches:
`dump_code/newv2/New folder (2)/APRISM_Gen8_Full.patch` and `APRISM_DC_OT_Full.patch`.

### Production defaults mirrored verbatim

`APRISM_CFAR_EMA_LAMBDA=0.02` · `APRISM_CFAR_WALL_MULT=12.0` (stored, never read) · `pfa=1e-4` ·
`APRISM_DA_K_FAST=0.05` · `APRISM_DA_K_SLOW=0.0025` · `APRISM_DA_ALPHA=0.1` ·
`APRISM_DA_LOCK_TOL_DEG=0.05` · `APRISM_DA_LOCK_NEED=10` · `APRISM_DA_MAX_UPDATES=50` ·
`GAMMA_MIN=9.21` · `GAMMA_MAX=40.0` · `RANK1_TOL=1.0` · `GHOST_SIGMA_XI=0.4` ·
`MIRROR_PROB=-1.0` · `kappa_max=0.05` · `rho_max=60` · `MP_POISSON_LIMIT=3.4` · `MP_ALPHA=0.98`

---

## 5. Headline measured results (seed 0)

| # | Concept | Key measured outcome |
|---|---|---|
| 1 | Track-conditioned residual beat | real mults 252 → 192; worst-SNR range RMSE 1.549 → 1.406 m (**but** high-SNR RMSE 0.0041 → 0.0696 m) |
| 2 | 3-product cubic-exact stencil | increment RMSE 0.399 → 0.016 rad; curvature error 8.0 → 1.06 m/s²; mults 60 → 12 |
| 3 | Range-adaptive dual-loop CFAR | weak-target recall 0.0 → 1.0; floor RMSE 7.89 → 0.023 dB; FA/column 0.106 → 0.131 |
| 4 | Occupancy-BLUE CFAR | weak-target recall 0.473 → 0.924; Pfa 0.0 → 0.0036; AUC 0.9988 → 0.9990 |
| 5 | Priority-ranked CDC packing | order Spearman 1.0 → −0.29; near-retention flat at 0.30 (see caveats) |
| 6 | Closed-form specular contact | contact RMSE 13.57 → 2.3e-15 m; valid rate 0.0 → 1.0; Newton 1 → 0 iters |
| 7 | Dual-horizon K_DA | frames-to-lock 653 → 313; update budget 400 → 50 |
| 8 | Preflight DA header seeding | initial error 1.889 → 1.257°; frames-to-converge 36 → 29; accept rate 0.765 |
| 9 | IMM acceleration gating (refuted) | recall at onset 0.60 → 1.00; track RMSE 2.76 → 1.26 m; **no IMM in either tree** |
| 10 | Kinematics-aware adaptive gating | gate widen at cut-in 1.0× → 3.23×; recall 0.383 → 0.400; **FA 0.58 → 1.01** |
| 11 | Distribution-free conformal gating | tail false-accept 0.835 → 0.456; coverage 0.983 → 0.945 (nominal 0.95) |
| 12 | Contamination-budgeted frozen rank gate | max gate width 3.73 → 1.00 (bounded); recovery 5 → 0 frames |
| 13 | Doppler-invariant ghost disambiguation | decoy false-accept 0.998 → 0.000; separation 0.0 → 7.50 σ; AUC 0.5 → 1.0 |
| 14 | Rank-1 specular invariant & bearing fix | selected residual 41.38 → 0.027 m; bearing error 29.98 → 0.02° |
| 15 | Virtual aperture specular tracking | position RMSE 22.98 → 1.21 m; ellipse major axis 53.5 → 1.58 m; P λmax 2861 → 2.50 m² |
| 16 | Spectral entropy covariance scaling | spray-window RMSE 1.73 → 1.26 m; after-spray RMSE 1.00 → 0.59 m |
| 17 | Tangent-mirror Hermite linearization | reconstruction RMSE 5.71 → 0.17 m; max error 13.93 → 0.58 m |
| 18 | XOR sentinel contract | false suppressions 5 → 0; true suppressions 1 → 1; sentinel respected 0 → 1 |
| 19 | Async satellite yaw extrapolation | RMSE at ω=0.6 rad/s 7.13 → 0.46 m; smear 4.66 → 0.63 m |
| 20 | Yaw-free timestamp/Doppler bias separation | τ RMSE 0.192 → 0.00032; bias 0.842 → 0.060; cond(∞) → 4.72 |
| 21 | Cross-satellite relative yaw cancellation | rel-yaw err 7.09° → 0.27°, flat vs ±45° mounting yaw; cert e_rel 0.598° |
| 22 | 155-scan fleet replay (49,388 dets) | false assoc 191 → 64; retained 880 → 915; ghosts assimilated 0 → 930; ID switches 247 → 90 |
| 23 | 4D Doppler-RadarSplat (no upstream kernel) | range align 37.61 → 0.0008 m; velocity 7.60 → 0.0015 m/s |
| 24 | Associative prefix-scan KF (no upstream kernel) | serial depth 50,000 → 32 tree levels (1562.5×); max abs diff 2.1e-11 |
| 25 | Ghost-conditioned target augmentation | ROC-AUC 0.282 → 0.99998; PR-AUC 0.442 → 0.999; FA 0.0225 → 0.0 |
| 26 | Nonlinear Gram-lifted state space (no upstream kernel) | closure residual rms 0.196 → 1.8e-4; max 3.92 → 9.7e-4 |
| 27 | Guarded error-transfer replay certificates | shard ID changes 108 → 0; guard radius 1.55 m; cert e_rel/e_i/e_j 0.598/0.019/0.617° |

Full numbers: `results/RESULTS.md` and `results/metrics.json`.

### Seed stability
Run with `--seeds 0 1 2 42`: **26 / 27** concepts have fully seed-consistent metric *direction*
(the same metric moves the same way for every seed). Concept **#16** has one metric whose
direction varies with the random spray realisation.

---

## 6. Honest caveats — where the result is NOT a clean win

These are real findings, not defects to be papered over:

- **#1 is worse at high SNR.** A-PRISM's 3-product stencil is *cheaper* (192 vs 252 real mults)
  and better at the worst SNR (1.549 → 1.406 m) but **less accurate at high SNR**
  (0.0041 → 0.0696 m), because the baseline lag-1 estimator uses far more samples. The trade-off
  is measured, not asserted.
- **The claimed "4,608 vs 1,024 multiplication" figures are NOT reproduced.** The measured counts
  for the configurations exercised here are **252 vs 192**. The production numbers depend on
  buffer sizes that this harness does not assume.
- **#10 widens the gate so much that false associations rise** (0.58 → 1.01/frame) while recall
  barely moves (0.383 → 0.400). The adaptive gate is **not** an unambiguous improvement on this
  fixture.
- **#3 trades false alarms for recall** (FA/column 0.106 → 0.131) and its threshold *lift* is
  negative (−25.4 dB) in this fixture — the A-PRISM path lowers the threshold relative to the
  baseline CA-CFAR while still detecting the weak target.
- **#5 near-field retention is flat (0.30 → 0.30).** `cdc_select_top_k` only permutes within the
  first `K` slots, so it cannot promote a near target past index K. The *order* does change
  (Spearman 1.0 → −0.29); the retention metric simply cannot see it. The production kernel
  has this same bound.
- **#9 has no upstream baseline.** There is **no IMM implementation in either tree**; the 3-mode
  IMM used for the comparison was synthesised for the experiment. Treat #9 as an algorithm-level
  A/B.
- **#23, #24, #26 have no upstream C kernel** (differentiability, prefix-scan KF, Gram lifting
  are not in the firmware). They are algorithm-level A/B pairs, explicitly flagged in the
  per-concept notes.
- **#11 coverage moves the wrong way** (0.983 → 0.945 against a nominal 0.95). The conformal gate
  is *closer* to nominal here, but it is not strictly better; its win is the halved tail
  false-accept rate.

---

## 7. Reproducibility

- Fully deterministic given `--seeds` (all fixtures derive from `np.random.default_rng(seed)`).
- No network access at run time (the HTML embeds plotly from a CDN for the dashboard only; the
  per-concept HTML files are standalone).
- Dependencies: `numpy`, `plotly`, `matplotlib` only. `kaleido` is **not** required — the PNG
  path converts the Plotly figure object to Matplotlib directly (`aprism_harness/plots.py`).
- All divisions are eps-guarded (`EPS = 1e-9`).
