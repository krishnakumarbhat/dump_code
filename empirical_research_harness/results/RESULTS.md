# APRISM Empirical Benchmark Results

Generated: 2026-10-23 15:43:39  |  seeds: [0]  |  elapsed: 20.5s

All values are **measured** by executing the 1:1 Python mirrors of the production C/C++ kernels on physics-grounded fixtures. Nothing in this table is hardcoded.

## Per-concept metrics

### 1. Track-Conditioned Residual Beat Estimator

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c`

> Both estimators run on the same complex beat fixture (r_true=1.00 m, f_b=667.1 kHz, fs=10 MHz). Baseline consumes the full 64-sample window in one lag-1 accumulation; A-PRISM consumes 16 independent 4-sample cubic stencils (prior increment = 0, inside the +-0.5 cycle unwrap band) and averages their centre-increment output. Multiplication counts are the kernel-returned n_mult values, not assumed constants. A-PRISM additionally emits curvature (g_h2) and jerk (l_h3), which the lag-1 estimator cannot produce.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| range_rmse_m_hi_snr | 0.004081 | 0.06964 | +1606.7% |
| range_rmse_m_sweep_mean | 0.3514 | 0.5619 | +59.9% |
| range_rmse_m_worst_snr | 1.549 | 1.406 | -9.2% |
| real_mults | 252 | 192 | -23.8% |
| samples_consumed | 64 | 64 | +0.0% |
| mults_per_sample | 3.938 | 3 | -23.8% |
| curvature_available | 0 | 1 |  |

### 2. 3-Product Cubic-Exact Residual Stencil

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c`

> Fixture: x[n]=exp(j(a0*n+0.5*k*n^2)) with a0=0.40 rad/sample and k=0.0125 rad/sample^2 per m/s^2 (calibration chosen so the curvature is resolvable at the stencil quantisation; the trend, not the absolute scale, is the claim). The baseline reports the window-mean increment (8 samples stale at n_win=16) and has no g_h2 output; the cubic-4 stencil recovers the centre increment and curvature, then extrapolates 2 samples to the newest increment. Multiplication counts are kernel-returned n_mult.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| increment_rmse_rad | 0.3993 | 0.01636 | -95.9% |
| increment_rmse_rad_mean | 0.2223 | 0.01765 | -92.1% |
| curvature_rmse_rad | 0.1 | 0.01326 | -86.7% |
| curvature_equiv_mps2 | 8 | 1.061 | -86.7% |
| real_mults | 60 | 12 | -80.0% |
| points_used | 16 | 4 | -75.0% |

### 3. Range-Adaptive Dual-Loop Clutter CFAR

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c`

> CFAR runs along range (each doppler column is one 'row'), pfa=1e-4, 9 reference cells + 1 guard. BASELINE uses alpha_ca*mean(all refs); A-PRISM excludes tracker-occupied cells from the reference set, seeds the dual-loop floor EMA (lambda=0.02) and lets aprism_cfar_overlay apply the BLUE/CA alpha ratio to the per-cell threshold. The wall skirt raises the baseline reference mean so the weak target is masked; the occupancy mask keeps it below threshold. Targets are injected at explicit range bins because signals.range_doppler_map's r^-4 weight underflows beyond ~0.3 m. Recall is the detection of the weak target cell (bin 111, doppler 16) over 5 seeds; FA counts threshold crossings in the quiet band (outside the wall +-7 bins and the target +-4 bins) per doppler column; the lift is measured at the target cell; floor RMSE compares the row mean (baseline) and the dual-loop EMA state (A-PRISM, unclamped) against the map median.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| weak_target_recall | 0 | 1 |  |
| false_alarms_per_column | 0.1062 | 0.1313 | +23.5% |
| threshold_lift_db | 0 | -25.37 |  |
| floor_rmse_db | 7.893 | 0.02293 | -99.7% |

### 4. Occupancy-BLUE CFAR with Pfa control

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c`

> 16 reference cells, 5 of them tracker-occupied (pi=0.85, snr=3). alpha_BLUE solves sum ln(1+a*beta_i) = -ln(pfa) via aprism_alpha_for_pfa; alpha_CA = n*(pfa^(-1/n)-1). The detector statistic is CUT/reference-mean (baseline) vs CUT/(beta.ref) (A-PRISM), swept over the same 4000 synthetic rows with exponential clutter. Both operating points are targeted at pfa=1e-4; the realised Pfa is measured, not assumed.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| pfa_at_operating_point | 0 | 0.003555 |  |
| weak_target_recall | 0.4727 | 0.9237 | +95.4% |
| auc | 0.9988 | 0.999 | +0.0% |
| alpha | 5.336 | 6.869 | +28.7% |
| alpha_ratio | 1 | 1.287 | +28.7% |
| beta_entropy | 0.1733 | 2.292 | +1222.8% |

### 5. Priority-Ranked CDC Urban Packing

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/cdc_priority.c + cdc_packing.c`

> 20 near-weak pedestrians (5-20 m, 6-12 dB) and 20 far-strong clutter returns (50-80 m, 14-22 dB) in random original order. A-PRISM scores 10^(SNR/10)/r^2 and applies cdc_select_top_k; the emitted count is unchanged (K), only the membership/order changes. MEASURED CAVEAT: as mirrored, cdc_select_top_k only sorts the first K entries (its inner loop is bounded by K), so it can never promote a detection from position >= K; near-field retention therefore does not improve and the emitted order is a permutation of the leading K block. The dotted 'global score sort' trace is a diagnostic (argsort of the same scores) showing what the concept would retain if the selection scanned all N entries; it is not part of the A/B claim.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| near_retention_top16 | 0.3 | 0.75 | +150.0% |
| near_retention_top8 | 0.1 | 0.4 | +300.0% |
| far_clutter_top16 | 10 | 1 | -90.0% |
| spearman_vs_original | 1 | -0.2899 | -129.0% |
| kendall_vs_original | 1 | -0.1949 | -119.5% |
| count_changed | 0 | 0 |  |
| oracle_retention_top16 | None | 0.75 |  |

### 6. Closed-Form Specular Contact Inversion

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/ghost_calib.c`

> Fixture: back wall at 1.5x the target range on the sensor axis, so the bistatic path ell=|mirror| is ~2r (mean measured ell/2r is in the metrics). BASELINE feeds the direct-path measurement (ell=|p-s|): ghost_inverse_contact refuses it (ell^2 <= |d|^2), so a Newton iteration on F(t)=|p-(s+tu)|-(ell-t) is run instead. It converges immediately to the trivial root t=0 (contact at the sensor), which is why its contact RMSE equals the target range while its residual is ~0: the iterative path is degenerate, not merely slow. The same Newton run on the bistatic ell needs the reported iterations to reach the closed-form answer. A-PRISM's contact point is the ray foot q, and its RMSE is ~machine precision: the closed form solves the specular (ellipsoid/ray) condition algebraically in 1 step, with 0 iterations.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| contact_rmse_m | 13.57 | 2.335e-15 | -100.0% |
| valid_rate | 0 | 1 |  |
| algebraic_steps | 1 | 1 | +0.0% |
| newton_iterations | 1 | 0 | -100.0% |
| newton_residual_m | 4.654e-16 | 0 |  |
| newton_iterations_bistatic | 5 | 0 | -100.0% |
| newton_residual_bistatic_m | 1.379e-15 | 0 |  |
| ell_over_2r | None | 1.059 |  |

### 7. Dual-Horizon Fast Dynamic Alignment K_DA

Source: `gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/dyn_align_wrapper.c`

> Boresight error starts at 1.2 deg and is driven to zero by err <- err - K*err + N(0,0.02 deg). BASELINE holds the conservative startup deadband (gain=K_SLOW=0.0025) for the full 400 update frames reported by baseline_da_update_counts; A-PRISM caps the schedule at the 50 updates returned by aprism_da_update_counts and applies da_dual_horizon_gain from frame 1. Lock is da_lock_detect(err, 0.05 deg, hold, 10) - frames are counted, not assumed.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| frames_to_lock | 653 | 313 | -52.1% |
| locked | 1 | 1 | +0.0% |
| updates_budget | 400 | 50 | -87.5% |
| final_abs_err_deg | 0.1685 | 0.157 | -6.8% |
| gain_at_frame_10 | 0.0025 | 0.02283 | +813.1% |

### 8. Preflight DA Header Seeding

Source: `gen_research/core-resim-dc-emb-library/DC_SIL/sil_wrappers/Tracker_VariantA_Wrapper.cpp`

> Tracker update az += 0.10*(az_true-az) per frame; convergence is |error|<=0.05 deg. BASELINE passes qf=0 so preflight_seed returns the cold-start static fallback (-1.145, -0.018) deg (measured initial error 1.889 deg). A-PRISM passes the header in radians; the mirror's guard accepts when |az|<=5 deg, |el|<=2 deg and qf>0. NOTE the mirror's transport is off by DEG2RAD (it returns rad*0.0174533 where the production hook stores degrees and the C++ wrapper applies kDeg2Rad once); the measured transport scale is reported and the inverse is applied so the seed error reflects the production path. Acceptance is measured over 400 noisy headers (az sigma 1.5 deg, el sigma 0.6 deg, qf ~ U(-0.2,1.4)); rejections are detected by the exact fallback value. The population-mean metrics show the honest consequence: a header that is 1.4 deg off truth only saves a few frames, so the win scales with header quality - the (0.2 deg) clean-seed curve is reported separately and is not the headline.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| initial_angle_error_deg | 1.889 | 1.257 | -33.5% |
| frames_to_converge | 36 | 29 | -19.4% |
| seed_rmse_deg | 2.099 | 1.447 | -31.1% |
| accepted_rate | 0 | 0.765 |  |
| accepted_headers | 0 | 306 |  |
| transport_scale | 0.01745 | 0.01745 | +0.0% |
| frames_to_converge_clean | None | 3 |  |

### 9. IMM Acceleration Gating (REFUTED BASELINE)

Source: `synthesised 3-mode IMM (no implementation exists in core-resim-dc-emb-library or Core_Radar_Gen8_iND13400)`

> NO IMM implementation was found in either tree: Core_Radar_Gen8_iND13400/APRISM_LANDING.md row 22 records 'N15 IMM (55)' as REFUTED / 'documented, no code' and the repo-wide grep for IMM only hits pugixml docs. The 3-mode (CV, CA+, CA-) IMM used here is therefore synthesised for this comparison: fixed acceleration covariance q=1.2, transition matrix 0.92 diagonal, +-2.5 m/s^2 model bias, sigma_z=0.6 m, dt=0.1 s, an 8 m/s^2 cut-in at frame 40 lasting 24 frames. BASELINE gates with the fixed 9.21 chi-square threshold (baseline_gamma) and coasts (predict-only) on rejection; A-PRISM uses adaptive_gamma(a_norm, innov_e) capped at 40. The A-PRISM gate admits the manœuvre measurement, so its recall recovers at the cost of the reported extra false associations on 40 uniform clutter candidates per frame - a measured trade, not a free win.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| mode_switch_latency_frames | 6 | 6 | +0.0% |
| recall_at_onset | 0.6 | 1 | +66.7% |
| false_associations_per_frame | 5.1 | 5.95 | +16.7% |
| track_err_rmse_m | 2.759 | 1.263 | -54.2% |
| gate | 9.21 | 15.26 | +65.7% |

### 10. Kinematics-Aware Adaptive Gating

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/detection_to_track_association/source/f360_determine_association_hypothesis.cpp`

> Target flies at 25 m/s then cuts in at 6 m/s^2 for 25 frames. A constant-velocity predictor makes the normalized innovation e grow during the cut-in. Gate half-width = sqrt(gamma)*sigma_z. BASELINE holds gamma=9.21 (half-width 1.52 m) and loses the association; A-PRISM widens with a_norm=|a|/3.0 and innov_e, measured widen at onset 3.23x. Clutter false associations are counted inside the gate per frame (measured, not assumed).

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| recall_true_association | 0.3833 | 0.4 | +4.3% |
| false_assoc_per_frame | 0.575 | 1.008 | +75.4% |
| mean_gamma | 9.21 | 30.33 | +229.3% |
| widen_at_cut_in_onset | 1 | 3.232 | +223.2% |

### 11. Distribution-Free Conformal Gating

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/detection_to_track_association/source/f360_determine_association_hypothesis.cpp (conformal quantile implemented in-harness; not present upstream)`

> Innovations drawn from 90%% N(0,1) + 10%% Student-t(2)*6 heavy-tail mixture. BASELINE uses the adaptive_gamma threshold 9.21 scaled by the measured innovation std (Gaussian assumption); A-PRISM uses the empirical 0.95 quantile of calibration magnitudes (distribution-free conformal). Actual coverage and tail false-accept rate are measured on an independent test set.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| actual_coverage_nominal_95 | 0.9832 | 0.9446 | -3.9% |
| threshold_m | 13.09 | 4.532 | -65.4% |
| false_accept_rate_tail | 0.835 | 0.4558 | -45.4% |
| nominal_level | 0.95 | 0.95 | +0.0% |

### 12. Contamination-Budgeted Frozen Rank Gate

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/include/aprism_ot_hooks.h`

> Six-sample bridge-glint burst with d^2 > 100. BASELINE sliding-window width = 1 + 5*contaminated_fraction over an 11-sample window; it blows up during the burst and needs a fully clean window to recover. A-PRISM rank_gate_apply(ver=1, factor=0.2, qneed=2) collapses the width to 0.2 after two consecutive confident samples and stays bounded (max 1.0). All widths measured by executing rank_gate_apply.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| max_gate_width | 3.727 | 1 | -73.2% |
| min_gate_width | 1 | 0.2 | -80.0% |
| bounded | 0 | 1 |  |
| frames_to_recover | 5 | 0 | -100.0% |
| mean_width_during_burst | 3.727 | 1 | -73.2% |

### 13. Doppler-Invariant Ghost Disambiguation

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/track_validity/source/f360_detect_multipath.cpp`

> Sensor at origin, target at (100, 0) m moving at 20 m/s, roadside sign at x=150 m. The ghost carries the true-path Doppler (20 m/s) but arrives from the mirrored direction u_g=(-1,0). BASELINE gates with the direct direction u_t=(1,0) so the ghost residual is ~0 and it is accepted (FA~1); A-PRISM gates with u_g so the ghost residual is ~40 m/s and is rejected (FA~0). Separation in sigma units is measured from the executed residuals.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| false_accept_rate_decoy | 0.9977 | 0 | -100.0% |
| recall_true | 0.9977 | 1 | +0.2% |
| separation_sigma | 0 | 7.5 |  |
| gate_bound_mps | 9 | 15 | +66.7% |
| roc_auc | 0.5 | 1 | +100.0% |

### 14. Rank-1 Specular Invariant and Bearing Fix

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/track_validity/source/f360_detect_multipath.cpp + f360_determine_reflected_obj.cpp`

> Sensor at origin, SEP tangent normal at 30 deg, mirror at d=40 m. Truth is the target-mirror ray (+theta=15 deg): detection p = 2*d*n1 so rank1_residual(H1) ~ 0 while residual(H2) = 4*d*sin(theta) ~ 41 m >> RANK1_TOL=1.0 m. BASELINE (legacy sensor-mirror preference) selects H2 and accepts the ghost; A-PRISM's rank-1 invariant selects H1 and rejects the ghost. Residuals, bearing and lateral errors are measured from the executed kernels.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| residual_H1_m | 0.02736 | 0.02736 | +0.0% |
| residual_H2_m | 41.38 | 41.38 | +0.0% |
| selected_residual_m | 41.38 | 0.02736 | -99.9% |
| selected_bearing_err_deg | 29.98 | 0.01959 | -99.9% |
| selected_lateral_m | 39.98 | 0.02735 | -99.9% |
| correct_selection | 0 | 1 |  |
| gate_pass_H1 | 1 | 1 | +0.0% |
| gate_pass_H2 | 0 | 0 |  |

### 15. Virtual Aperture Specular Tracking

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/measurement_update_tracks/source/f360_msmt_update_obj_trks_cca_moveable.cpp`

> Eye 1 at the origin measures vx only (H=[0,1,0,0,0,0]); with the cross-track velocity init wrong (0 vs true 4 m/s) the monostatic tracker cannot observe vy so y drifts. A-PRISM adds eye 2 at the mirrored sensor position virtual_sensor(0,1,100)=(0,200) m with a second range-rate measurement whose covariance row is inflated with reff_inflate. Position RMSE and the steady-state position-block eigenvalues of P are measured from the executed kalman_update.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| position_rmse_m | 22.98 | 1.21 | -94.7% |
| p_eig_min_m2 | 2.168 | 2.151 | -0.8% |
| p_eig_max_m2 | 2861 | 2.503 | -99.9% |
| semi_major_m | 53.49 | 1.582 | -97.0% |
| rmse_improvement_pct | None | 94.73 |  |

### 16. Spectral Entropy Covariance Scaling

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/measurement_update_tracks/source/f360_msmt_update_support_functions_ctca.cpp`

> Tire spray raises measurement entropy H(t) via a (1-w)*N(0,0.3^2) + w*N(0,8^2) mixture with w ramping to 0.85 during the spray window. Covariance R_true = r0*exp(beta*H/snr) drives the measurement noise. BASELINE holds fixed R=r0 (underestimates spray noise); A-PRISM uses R(t)=entropy_scale(r0,H,snr,beta) via ctca_covariance/entropy_scale. Position RMSE during vs after spray is measured.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| mean_R_spray | 0.2 | 14.04 | +6922.2% |
| rmse_spray | 1.726 | 1.26 | -27.0% |
| rmse_after | 1.003 | 0.5931 | -40.9% |
| mean_entropy_spray | 2.052 | 2.052 | +0.0% |

### 17. Tangent-Mirror Hermite Linearization

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/track_validity/source/f360_is_reflective_guardrail_track.cpp`

> Clothoid-like off-ramp barrier y = 0.006*x^3 over x in [0, 20] m with noisy samples. BASELINE fits a single line (poor for the cubic curve). A-PRISM fits a 2-point cubic Hermite per segment via hermite_solve2 and drops segments whose |slope| exceeds 2*k_max*rho_max = 6.0 via curvature_ok. Reconstruction RMSE, max error and rejected-point count are measured from the executed kernels.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| rmse_m | 5.713 | 0.1734 | -97.0% |
| max_err_m | 13.93 | 0.5813 | -95.8% |
| points_rejected | 0 | 4 |  |
| coverage_frac | 1 | 0.925 | -7.5% |

### 18. XOR Sentinel Contract

Source: `core-resim-dc-emb-library/Application/F360Tracker/F360TrackerLib/Fusion360/track_validity/source/f360_track_validity.cpp`

> Frames 0-7 are benign single bounces, frame 8 is a genuine double-bounce ghost (sets the mirror_prob=-1.0 sentinel), frames 9-24 are benign again. BASELINE uses a plain threshold (mirror_prob<0.5) and falsely suppresses 5 benign frames; A-PRISM uses the XOR sentinel FSM which latches -1.0 only on the genuine ghost, so benign events are never suppressed and the sentinel is respected after the ghost. xor_sentinel is evaluated per frame; benign frames flagged by naive XOR but correctly not suppressed by the FSM are counted.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| false_suppressions | 5 | 0 | -100.0% |
| true_suppressions | 1 | 1 | +0.0% |
| sentinel_respected | 0 | 1 |  |
| xor_benign_flags | 0 | 0 |  |

### 19. Asynchronous Satellite Yaw Extrapolation

Source: `core-resim-dc-emb-library/DC_SIL/sil_wrappers/sil_wrapper.cpp`

> Two reports of one target separated by dt=0.08 s with mounting yaw rate omega swept in [0.1,0.6] rad/s; 60 noisy trials per omega. BASELINE reads the second report as-is; A-PRISM applies kernels.deskew.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| rmse_mean_m | 4.679 | 0.4941 | -89.4% |
| rmse_at_max_omega_m | 7.13 | 0.4592 | -93.6% |
| smear_mean_m | 4.664 | 0.6263 | -86.6% |

### 20. Yaw-Free Timestamp and Doppler Bias Separation

Source: `core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c (ClockTau1/ClockTauBias2) + sil_wrapper.cpp`

> Generative model y_i = a_i*tau + r_i*b with b = yaw-induced Doppler bias; BASELINE solves tau from one target (ClockTau1) and is biased by (r1/a1)*b; A-PRISM runs ClockTauBias2 joint solve. Condition numbers are measured with numpy.linalg.cond on the actual normal matrices.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| tau_rmse_at_max_yaw | 0.1923 | 3.155e-04 | -99.8% |
| tau_rmse_mean | 0.09618 | 3.457e-04 | -99.6% |
| b_estimate_mean | 0.8425 | 0.06008 | -92.9% |
| normal_matrix_cond | inf | 4.718 | +nan% |

### 21. Cross-Satellite Relative Yaw Cancellation

Source: `core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c (GhostEstimateYaw, GhostCertify)`

> Direct/ghost complex vectors of one specular target; absolute mounting yaw swept +/-45 deg while the relative yaw is fixed. A-PRISM error stays flat (common-mode cancellation in GhostEstimateYaw); baseline uses a linearised absolute-amplitude inversion and drifts. Bounds from GhostCertify with measured lmin/cmax.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| rel_yaw_err_mean_deg | 7.088 | 0.2672 | -96.2% |
| rel_yaw_err_max_deg | 8.536 | 0.4721 | -94.5% |
| cert_valid | yes | None |  |
| corr_peak_coherence | None | 0.9977 |  |
| corr_peak_err_deg | None | 0.2672 |  |
| cert_e_rel_deg | None | 0.614 |  |
| cert_e_i_deg | None | 0.0195 |  |
| cert_e_j_deg | None | 0.6335 |  |

### 22. 155-Scan Fleet Replay Verification

Source: `core-resim-dc-emb-library/DC_SIL/sil_wrappers/Tracker_VariantA_Wrapper.cpp`

> Fleet replay of 155 scans, 8 targets, 6 ghosts/scan, 300 clutter/scan = 49388 actual detections (pre-generated once; both pipelines process bit-identical inputs). Each ghost swamps its victim's direct return on 30% of scans (multipath masking). BASELINE: fixed gamma, no rank gate, no XOR sentinel. A-PRISM: adaptive_gamma (normalised-innovation input) + rank_gate_apply + XOR sentinel via TrackValidityFSM and DetSidecar; blocked = baseline false associations that A-PRISM did not reproduce.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| total_detections | 49,388 | 49,388 | +0.0% |
| false_associations | 191 | 64 | -66.5% |
| true_associations_retained | 880 | 915 | +4.0% |
| ghosts_assimilated | 0 | 930 |  |
| id_switches | 247 | 90 | -63.6% |
| false_associations_blocked | None | 169 |  |

### 23. 4D Doppler-RadarSplat Simulation

Source: `algorithm-level research concept (no upstream C kernel found)`

> NO upstream C kernel was found: this is an algorithm-level A/B, not a firmware-verified one. Differentiable monostatic range-Doppler primitive with R^-4 spreading loss; BASELINE aligns on magnitude only (free amplitude), A-PRISM aligns with the R^-4 loss-weighted centroid/gradient.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| range_align_err_m | 37.61 | 8.074e-04 | -100.0% |
| vel_align_err_mps | 7.6 | 0.001463 | -100.0% |
| final_loss | 1.073e+08 | 242.4 | -100.0% |
| iterations | 1,534 | 1,528 | -0.4% |

### 24. Associative Parallel Prefix-Scan Kalman Filter

Source: `algorithm-level research concept (no upstream C kernel found)`

> NO upstream C kernel was found: algorithm-level A/B, not firmware-verified. Serial Kalman predict/update chain over N=50,000 logical steps (affine operators from a forward Riccati pass) vs a Blelloch up-sweep/down-sweep associative prefix scan; tree levels are COUNTED from the scan loops. Equivalence asserted at runtime (max abs diff reported).

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| serial_depth | 50,000 | 50,000 | +0.0% |
| tree_levels | 0 | 32 |  |
| span_reduction_factor | 1 | 1562 | +156150.0% |
| max_abs_diff | 2.092e-11 | 2.092e-11 | +0.0% |
| max_rel_diff | 8.367e-16 | 8.367e-16 |  |
| steps | 50,000 | 50,000 | +0.0% |

### 25. Ghost-Conditioned Target Augmentation

Source: `core-resim-dc-emb-library/.../Fusion360/track_validity/source/f360_detect_multipath.cpp`

> 400 near low-power targets + 400 far strong ghosts. BASELINE scores by raw power (ghosts dominate). A-PRISM applies near-far power normalisation and augments with ghost-conditioned negatives using rank1_residual, doppler_gate and TrackValidityFSM (ROC/PR from concept_api.roc_curve).

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| roc_auc | 0.2821 | 1 | +254.5% |
| pr_auc | 0.442 | 0.9987 | +125.9% |
| false_alarm_rate | 0.0225 | 0 | -100.0% |
| n_detections | 800 | 800 | +0.0% |

### 26. Nonlinear Parallel Gram-Lifted State Space

Source: `algorithm-level research concept (no upstream C kernel found)`

> NO upstream C kernel was found: algorithm-level A/B, not firmware-verified. Constant-turn-rate model whose speed squared vx^2+vy^2 is a quadratic invariant measured directly. BASELINE linear-EKF linearises the invariant (nonzero closure); A-PRISM lifts the quadratic monomials into an 8-dim Gram state so the update closes linearly. Closure = |z - h(state)| after the update, measured on both filters over 400 steps.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| closure_residual_max | 3.923 | 9.742e-04 | -100.0% |
| closure_residual_rms | 0.1962 | 1.826e-04 | -99.9% |
| state_dimension | 5 | None |  |
| lifting_dimension | None | 8 |  |
| gram_condition_number | None | 5.666e+09 |  |

### 27. Guarded Error-Transfer Replay Certificates

Source: `core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c (GhostCertify) + replay`

> Replay split into two shards over 360 frames. Guard radius h_k = GhostCertify angular bound (eps=1e-3, measured lmin/cmax) x lever x adaptive_gamma gate gain. BASELINE has no guard (h=0): every shard decision change is a violation. A-PRISM locks frames inside h_k; 17 empirical violations occur when the injected error deliberately exceeds the guard.

| Metric | Baseline | A-PRISM | Change |
|---|---:|---:|---:|
| certified_e_rel_deg | 0.5984 | 0.5984 | +0.0% |
| certified_e_i_deg | 0.01897 | 0.01897 | +0.0% |
| certified_e_j_deg | 0.6173 | 0.6173 | +0.0% |
| guard_radius_mean_m | 0 | 1.55 |  |
| id_changed_frames | 108 | 0 | -100.0% |
| id_equivalent_frames | 252 | 360 | +42.9% |
| violations_outside_guard | 108 | 0 | -100.0% |
| guard_covered_fraction | None | 0.8306 |  |
| violations_when_guard_exceeded | None | 17 |  |

## Failures

None - all 27 concepts executed successfully.