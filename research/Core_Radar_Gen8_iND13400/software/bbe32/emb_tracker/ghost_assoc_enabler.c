/* A-PRISM association enabler implementation. See header for contract. */
#include "ghost_assoc_enabler.h"

#include <math.h>

float GhostDopplerScore(float vr_b_meas, const float *u_sb, const float *v_a,
                        float sig_v_sensor, float sig_v_track, float k_gate)
{
    /* Gate width from TRACK sigma (not sensor sigma): design point of Run 4. */
    float pred = u_sb[0] * v_a[0] + u_sb[1] * v_a[1];
    float den = k_gate * sqrtf(sig_v_sensor * sig_v_sensor + sig_v_track * sig_v_track);
    float d = vr_b_meas - pred;
    if (d < 0.0f) {
        d = -d;
    }
    if (den <= 0.0f) {
        return 1e30f;
    }
    return d / den;
}

void GhostCellOccupancy(float pred_pow, float noise_floor, float ghost_prob,
                        float pd, float *pi_out, float *s_out)
{
    float pi_d = 0.0f, s = 0.0f;
    if ((noise_floor > 0.0f) && (pred_pow > noise_floor)) {
        /* predicted excess power -> detection-likely occupancy */
        pi_d = pd * (pred_pow - noise_floor) / pred_pow;
        s = pred_pow / noise_floor - 1.0f;
    }
    if (pi_out != NULL) {
        float g = ghost_prob;
        if (g < 0.0f) {
            g = 0.0f;
        }
        if (g > 1.0f) {
            g = 1.0f;
        }
        *pi_out = 1.0f - (1.0f - pi_d) * (1.0f - g);
    }
    if (s_out != NULL) {
        *s_out = s < 0.0f ? 0.0f : s;
    }
}

int32_t GhostConfirmUpdate(uint8_t *seen_once, int32_t pair_id, int32_t n_ids, bool gated)
{
    int32_t id;
    if ((seen_once == NULL) || (n_ids <= 0)) {
        return 0;
    }
    id = pair_id % n_ids;
    if (id < 0) {
        id += n_ids;
    }
    if (!gated) {
        seen_once[id] = 0;
        return 0;
    }
    if (seen_once[id] != 0U) {
        seen_once[id] = 0; /* consume confirmation */
        return 1;
    }
    seen_once[id] = 1;
    return 0;
}
