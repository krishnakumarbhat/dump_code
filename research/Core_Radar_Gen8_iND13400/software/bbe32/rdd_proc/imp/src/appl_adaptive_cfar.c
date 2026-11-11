/* A-PRISM adaptive CFAR layer implementation. See header for contract. */
#include "appl_adaptive_cfar.h"

#include <math.h>
#include <string.h>

float Aprism_Median(const float *a, float *scratch, int32_t n)
{
    int32_t i, j;
    if (n <= 0) {
        return 0.0f;
    }
    for (i = 0; i < n; i++) {
        scratch[i] = a[i];
    }
    for (i = 1; i < n; i++) { /* insertion sort: deterministic, bounded */
        float v = scratch[i];
        j = i - 1;
        while ((j >= 0) && (scratch[j] > v)) {
            scratch[j + 1] = scratch[j];
            j--;
        }
        scratch[j + 1] = v;
    }
    if ((n & 1) != 0) {
        return scratch[n / 2];
    }
    return 0.5f * (scratch[n / 2 - 1] + scratch[n / 2]);
}

void Aprism_DualLoopFloor(AprismCfarState_T *st, int32_t r,
                          const float *row, const uint8_t *free_mask, int32_t nd,
                          float *scratch)
{
    /* Collect track-free cells, median, EMA update. No allocation. */
    float vals[APRISM_CFAR_MAX_REFS];
    int32_t m = 0, i;
    float med;
    if ((st == NULL) || (st->floor == NULL) || (r < 0) || (r >= st->nbins)) {
        return;
    }
    for (i = 0; (i < nd) && (m < APRISM_CFAR_MAX_REFS); i++) {
        if (free_mask[i] != 0U) {
            vals[m++] = row[i];
        }
    }
    if (m == 0) {
        return; /* no free cells: hold floor */
    }
    med = Aprism_Median(vals, scratch, m);
    st->floor[r] += st->cfg->ema_lambda * (med - st->floor[r]);
}

int32_t Aprism_SelectR0(float span, float tau1, float tau2)
{
    if (span < tau1) {
        return APRISM_CFAR_R0_SMALL;
    }
    if (span < tau2) {
        return APRISM_CFAR_R0_MID;
    }
    return APRISM_CFAR_R0_LARGE;
}

void Aprism_BlueWeights(const float *pi, const float *snr, float *beta, int32_t n)
{
    int32_t i;
    float denom = 0.0f;
    for (i = 0; i < n; i++) {
        float m = 1.0f + pi[i] * snr[i];
        float v = 2.0f * (1.0f - pi[i] + pi[i] * (1.0f + snr[i]) * (1.0f + snr[i])) - m * m;
        float w;
        if (v < 1e-12f) {
            v = 1e-12f;
        }
        w = m / v;
        beta[i] = w; /* normalize below */
        denom += m * w;
    }
    if (denom < 1e-12f) {
        denom = 1e-12f;
    }
    for (i = 0; i < n; i++) {
        beta[i] /= denom;
    }
}

float Aprism_AlphaForPfa(const float *beta, int32_t n, float pfa_star)
{
    /* g(a) = sum ln(1+a*b) + ln(Pfa): strictly increasing, concave. */
    float lo = 0.0f, hi = 1.0f, mid, g;
    int32_t i, it;
    if (pfa_star <= 0.0f) {
        return 0.0f;
    }
    for (it = 0; it < 200; it++) { /* bracket hi (bounded iterations) */
        g = 0.0f;
        for (i = 0; i < n; i++) {
            g += logf(1.0f + hi * beta[i]);
        }
        if (g + logf(pfa_star) >= 0.0f) {
            break;
        }
        hi *= 2.0f;
        if (hi > 1e12f) {
            return hi;
        }
    }
    for (it = 0; it < 100; it++) { /* bisection */
        mid = 0.5f * (lo + hi);
        g = 0.0f;
        for (i = 0; i < n; i++) {
            g += logf(1.0f + mid * beta[i]);
        }
        if (g + logf(pfa_star) < 0.0f) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return 0.5f * (lo + hi);
}

float Aprism_CaAlpha(int32_t n, float pfa_star)
{
    /* Closed form of the same root for uniform beta: N*(Pfa^(-1/N)-1). */
    float inv;
    if ((n <= 0) || (pfa_star <= 0.0f)) {
        return 0.0f;
    }
    inv = powf(pfa_star, -1.0f / (float)n);
    return ((float)n) * (inv - 1.0f);
}
