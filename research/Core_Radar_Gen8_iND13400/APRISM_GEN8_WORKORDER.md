# A-PRISM Gen8 Work Order — what to implement in THIS repo, exactly where

Scope: `Core_Radar_Gen8_iND13400` only. No OT repo changes. No commits requested.
Status terms: **WIRED** = called from a production path; **STAGED** = code present,
host-tested, not yet called; **BLOCKED** = missing input/owner confirmation.

## 0. Ground rules (read first)

1. Everything new stays **default-OFF** until SiL replay proves the enabled diff.
2. Do not change shared stream structs (`rdd_stream.h`, `cdc_stream.h`, IPC) without
   ICD/version review — they are auto-generated or cross-core contracts.
3. Do not edit the external `@dabb` estimator or `@spbb` CFAR core from here;
   change wrapper inputs, config, and pre/post steps only.
4. Masks/predictions coming from the tracker are **previous-scan** data (tracker
   runs after DSP in the cycle). Every consumer must document the one-scan delay.

## 1. CFAR — `software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c`

Real call path (verified): `doppler_process_ifc.c` → `Appl_Cfar_Execute(ridx,
p_rdd_data)` per range bin → external `Cfar_Process()`.

- STAGED: `appl_adaptive_cfar.h/.c` (EMA floor, R0 select, BLUE weights,
  α bisection, CA closed form), static state + Init wiring,
  guarded `#if` block, `appl_adaptive_cfar_lib`/`_ut_lib` targets,
  `test/appl_adaptive_cfar_unit_test.cc` (3 gtest cases, in `all_tests`).
- NCI row source: `rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH]` is `uint16_t*`
  (see `inc/doppler_process_ifc.h:82`). The element type/scale
  (`rdop_avg_t`) is defined outside this repo tree — **owner must confirm
  the LSB-to-power scale** before the row copy in the `#if` block is filled in.
- Outputs to adjust: `p_rdd_data->cfar_thold[ridx]` (`uint32_t`),
  `cfar_nf_est[ridx]` (`uint16_t`). Any overlay must write these exact Q
  formats; confirm scaling with the RDD owner.
- Occupancy mask: not available at CFAR time — use previous-scan buffer
  written by the emb_tracker hook (§5), default all-free.
- Acceptance: host test PASS (done) → enable on guardrail SiL scene →
  Tier-1 yield held + edge-skirt recall lift + FA count per Run 2 contract.

## 2. CDC priority — `software/bbe32/src/cdc_priority.h/.c`

Real path (verified): `doppler_process_ifc.c` → `Appl_First_Pass_Execute()` →
`Cdc_Packing(p_look_data, range_idx, cdc_dbin_count, bv_buffer)`, which packs
the **already-selected** `p_cdc_array` (+ CI flags) into `CDC_Record_T`
(`common/cdc_stream.h`: `rng_idx/dopp_idx/nci_data/ci_flag` + beamvector).

- STAGED: score `s=SNR_lin/r²` + stable top-k (`CdcSelectTopK`).
- To wire (needs FP owner): reorder `p_cdc_array` **and** `p_ci_flag_array`
  identically by score **before** `Cdc_Packing` consumes them for that
  `range_idx`, in `doppler_process_ifc.c` after the first-pass call; dropping
  records means reducing `cdc_dbin_count` with frame accounting kept
  consistent. Do NOT reorder inside `Cdc_Packing` past the partial-frame
  bookkeeping — scores must be built from `rdop_avg_data_ptr` amplitudes +
  `range_idx` at selection time.
- Acceptance: saturating urban scene keeps near-strong records; Tier-1/2
  deltas on dropped-vs-kept sets.

## 3. Residual DSP — `software/bbe32/src/residual_track_ifc.h/.c`

STAGED: `ResidualLag1`, `ResidualCubic4` (3 mults asserted, invalid on
zero/missing), INT8 common-scale quant + angle bound. **No call site yet.**
To wire: needs (a) per-track predicted beat increment at the range/doppler
flow, i.e. a tracker prediction struct that does not exist in this flow —
owner pair: range-proc owner (fast-time tap + epoch) + tracker owner
(prediction feed). Note the lag-1 helper expects **pre-derotated** samples;
it does not derotate. Do not call with raw ADC until the derotation step
is defined at the call site.

## 4. Dynamic alignment — `software/bbe32/dyn_alignment/`

Real path (verified): `dyn_align_wrapper()` → `da_ptr_update()` →
`Auto_align_Init()` (once) → per scan `convert_detections()` (AF_Det_T →
single-sensor `DRA_Detection_Input_T`: az/el/range/range-rate/ampl/snr/conf,
`f_bistatic`) → **external** `DRA_Step_Execution()` (`@dabb`) →
`Populate_Dyn_Align_Output()`. SiL mirrors call the wrapper from
`sil/emb_lib/rsp_emb_lib/rsp_sil_wrapper.cpp` and
`sil/rsp_sil/.../psp_sil_interface.cpp`.

- STAGED: `ghost_calib.h/.c` (yaw, cert, contact, Hermite, clock/bias,
  `DaDualHorizonGain`, lock detector) + `ghost_calib_lib` + DA.md section.
- **Direct answer on the dual-horizon schedule: it is NOT in this repo.**
  Only the scalar reference helper is here. The executed recursion lives in
  external `@dabb`. The shippable Gen8-side subset is:
  1. Preflight injection through fields `Auto_align_Init()` already reads
     (`initial_num_updates_az/el/rl`, `az/el covariances`,
     `max_abs_misalignment_*`, `align_cmd` ← M2D `dra_data`) — set from
     converged log headers at `t=0`.
  2. Lock detector on `Dynamic_Alignment_Log_Stream_T` outputs.
  3. Any change to the internal gain recursion → DABB owner, not this repo.
- Single-sensor ghost pairing **is** possible here: pair detections inside
  `p_detection_input->detections[]` (`number_of_detections ≤
  DRA_NUMBER_OF_DETECTIONS`) in `convert_detections()`/`Execute_Dynamic_Alignment()`,
  using the sensor mount already read in `Auto_align_Init()`
  (`k_sensor_mount_pos_*`, yaw/pitch/roll).
- **Cross-satellite yaw is impossible in this wrapper**: `DYN_ALIGN_INPUT_T`
  carries one sensor's streams only. It must run where two satellites meet
  (fusion/DC side) — see `APRISM_OT_HANDOFF.md`.
- Acceptance: 46-frame lock on replay with drops-to-zero; ghost path needs
  SiL scenes with labeled multipath + refusal-rate reporting.

## 5. emb_tracker enablers — `software/bbe32/emb_tracker/ghost_assoc_enabler.h/.c`

STAGED: track-sigma Doppler score, occupancy/SNR row builder, 2-scan counter.
Real handoff region (verified): `emb_tracker_wrapper.cpp` fills
`f360_det_list->detections[]` (`.range/.range_rate/.azimuth/.elevation/.snr/
.rcs/.sensor_id/...`) then calls the F360 state manager
(`Get_State_Manager().execute(...)`).

- To wire: add a guarded pre-pass after the det-list fill computing Doppler
  scores + occupancy rows into static buffers; previous-cycle tracks feed
  predictions (one-scan delay — document per consumer).
- Do NOT hand-edit the 76KB wrapper blindly: confirm the exact insertion
  line in `Run_Emb_Tracker` with the wrapper owner, plus where previous-cycle
  track predictions are readable. The F360 core itself (`@rotbb`) is external.

## 6. Explicitly NOT in this work order

RDU classifier edits (`rdu/src/*classifier*.c`, `moving_special_cases.c`) —
no code yet, needs RDU owner. Stream-struct changes — ICD review first.
Anything in `C:\git\OT_ObjectTracking` — see `APRISM_OT_HANDOFF.md`.
