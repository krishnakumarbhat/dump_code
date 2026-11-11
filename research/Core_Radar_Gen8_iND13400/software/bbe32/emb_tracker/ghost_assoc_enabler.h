/* A-PRISM satellite-side association enablers (N11/N24/N22g inputs).
 * Pure array functions producing the observables the central tracker
 * consumes: Doppler-gated pair scores + occupancy/SNR masks for CFAR.
 * Self-contained C99. Verified by aprism_host_tests/test_assoc_enabler.c.
 */
#ifndef GHOST_ASSOC_ENABLER_H
#define GHOST_ASSOC_ENABLER_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GHOST_ASSOC_MAXDET (680)

/* Doppler consistency score for one candidate pair (N11 gate quantity).
 * vr_b_meas: measured ghost Doppler; u_sb (2D unit), v_a (2D track vel):
 * vr_b_pred = u_sb . v_a. Returns normalized residual |meas-pred|/gate.
 * <=1 inside the K-sigma gate. */
float GhostDopplerScore(float vr_b_meas, const float *u_sb, const float *v_a,
                        float sig_v_sensor, float sig_v_track, float k_gate);

/* Occupancy/SNR mask row for one reference cell (N22g CFAR feed).
 * pred_pow: tracker-predicted power in cell; noise_floor: current mu_hat;
 * ghost_prob: ghost-hypothesis mass in cell (0..1).
 * Outputs pi (occupancy) and s (expected SNR). */
void GhostCellOccupancy(float pred_pow, float noise_floor, float ghost_prob,
                        float pd, float *pi_out, float *s_out);

/* Two-scan confirmation counter update (N11 2-scan rule).
 * Returns confirmed count increment (0/1) for a pair id hash. */
int32_t GhostConfirmUpdate(uint8_t *seen_once, int32_t pair_id, int32_t n_ids, bool gated);

#ifdef __cplusplus
}
#endif

#endif /* GHOST_ASSOC_ENABLER_H */
