/* A-PRISM residual estimator implementation. See header for contract. */
#include "residual_track_ifc.h"

#include <math.h>

#define RTR_TWO_PI (6.283185307179586f)

static float rtr_wrap_half(float d)
{
    /* Wrap to [-0.5, 0.5) using roundf: fixed, branch-free-ish. */
    return d - roundf(d);
}

float ResidualLag1(const float *x, int32_t n, float f_pred)
{
    float acc_re = 0.0f, acc_im = 0.0f;
    int32_t i;
    (void)f_pred; /* prediction enters via pre-derotated samples here */
    for (i = 1; i < n; i++) {
        float a_re = x[2 * i], a_im = x[2 * i + 1];
        float b_re = x[2 * (i - 1)], b_im = x[2 * (i - 1) + 1];
        acc_re += a_re * b_re + a_im * b_im;
        acc_im += a_im * b_re - a_re * b_im;
    }
    return atan2f(acc_im, acc_re) / RTR_TWO_PI;
}

float ResidualCubic4(const float *x, const float *pred_incr,
                     float *g_h2, float *l_h3,
                     int32_t *n_mult, bool *invalid)
{
    float eta[3];
    float em, e0, ep, fh;
    int32_t j, nm = 0;
    float maxamp = 0.0f, a;
    for (j = 0; j < 4; j++) {
        a = fabsf(x[2 * j]) + fabsf(x[2 * j + 1]);
        if (a > maxamp) {
            maxamp = a;
        }
    }
    if ((maxamp == 0.0f) || (pred_incr == NULL)) {
        if (invalid != NULL) {
            *invalid = true;
        }
        return 0.0f;
    }
    for (j = 0; j < 3; j++) {
        float a_re = x[2 * (j + 1)], a_im = x[2 * (j + 1) + 1];
        float b_re = x[2 * j], b_im = x[2 * j + 1];
        float c_re = a_re * b_re + a_im * b_im;
        float c_im = a_im * b_re - a_re * b_im;
        float meas;
        nm++; /* exactly one complex multiply per lag */
        meas = atan2f(c_im, c_re) / RTR_TWO_PI;
        eta[j] = rtr_wrap_half(meas - pred_incr[j]);
    }
    em = eta[0];
    e0 = eta[1];
    ep = eta[2];
    fh = (26.0f * e0 - ep - em) / 24.0f;
    if (g_h2 != NULL) {
        *g_h2 = (ep - em) / 2.0f;
    }
    if (l_h3 != NULL) {
        *l_h3 = ep - 2.0f * e0 + em;
    }
    if (n_mult != NULL) {
        *n_mult = nm;
    }
    if (invalid != NULL) {
        *invalid = false;
    }
    return fh;
}

void ResidualQuant8(float re, float im, float scale,
                    int8_t *qr, int8_t *qi, float *rq_re, float *rq_im)
{
    int32_t t;
    if (scale <= 0.0f) {
        scale = 1.0f;
    }
    t = (int32_t)roundf(re / scale);
    if (t > 127) {
        t = 127;
    }
    if (t < -127) {
        t = -127;
    }
    *qr = (int8_t)t;
    t = (int32_t)roundf(im / scale);
    if (t > 127) {
        t = 127;
    }
    if (t < -127) {
        t = -127;
    }
    *qi = (int8_t)t;
    *rq_re = ((float)*qr) * scale;
    *rq_im = ((float)*qi) * scale;
}

float ResidualQuantAngleBound(float amplitude)
{
    /* Worst-case vector error sqrt(1/2) LSB over amplitude (common scale). */
    if (amplitude <= 0.0f) {
        return 0.0f;
    }
    return asinf(0.70710678f / amplitude);
}
