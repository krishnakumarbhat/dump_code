/* A-PRISM track-conditioned residual estimators (N14 lag-1, N23 3-product).
 * Self-contained C99. Complex samples as interleaved [re,im] float pairs.
 * Zero heap; fixed iteration counts. Verified by host test (clang run).
 */
#ifndef RESIDUAL_TRACK_IFC_H
#define RESIDUAL_TRACK_IFC_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Lag-1 residual frequency (cycles/sample): angle(sum z[n]conj(z[n-1]))/2pi.
 * x: 2*N floats; f_pred: predicted freq (cycles/sample). */
float ResidualLag1(const float *x, int32_t n, float f_pred);

/* Cubic-exact 3-product stencil (N23). x: exactly 4 samples (8 floats).
 * pred_incr: 3 predicted increments (cycles). Returns f_hat (cycles/h);
 * *invalid set when amplitude is zero or pred_incr is NULL. Counter counts
 * complex multiplies through *n_mult (must equal 3 per update). */
float ResidualCubic4(const float *x, const float *pred_incr,
                     float *g_h2, float *l_h3,
                     int32_t *n_mult, bool *invalid);

/* INT8 common-scale quantize of one complex sample (in/out [re,im]). */
void ResidualQuant8(float re, float im, float scale,
                    int8_t *qr, int8_t *qi, float *rq_re, float *rq_im);

/* Common-scale sample angle error bound for amplitude A (counts). */
float ResidualQuantAngleBound(float amplitude);

#ifdef __cplusplus
}
#endif

#endif /* RESIDUAL_TRACK_IFC_H */
