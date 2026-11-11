/* A-PRISM adaptive CFAR layer: dual-loop floor/R0 + Occupancy-BLUE weights.
 * Self-contained C99 (stdint/stdbool/string/math only). Zero heap: caller
 * owns all buffers. Feature flag APRISM_ADAPTIVE_CFAR_ENABLE gates hooks.
 * Verified by aprism_host_tests/test_adaptive_cfar.c (clang host run).
 */
#ifndef APPL_ADAPTIVE_CFAR_H
#define APPL_ADAPTIVE_CFAR_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dual-loop tunables (Run 2 values). */
#define APRISM_CFAR_EMA_LAMBDA   (0.02f)
#define APRISM_CFAR_R0_SMALL     (8)
#define APRISM_CFAR_R0_MID       (16)
#define APRISM_CFAR_R0_LARGE     (32)
#define APRISM_CFAR_WALL_MULT    (12.0f)
#define APRISM_CFAR_MEDIAN_RESCALE (1.442695f) /* 1/ln2: median->mean for Exp */
#define APRISM_CFAR_MAX_BINS     (1024)
#define APRISM_CFAR_MAX_REFS     (64)

typedef struct AprismCfarCfg_Tag {
    float ema_lambda;      /* slow-loop rate */
    float wall_mult;       /* wall/skirt regime threshold x global median */
    float pfa;             /* target false-alarm probability */
    bool  blue_enable;     /* false: plain CA weights (backward compatible) */
} AprismCfarCfg_T;

typedef struct AprismCfarState_Tag {
    const AprismCfarCfg_T *cfg;
    float *floor;          /* caller buffer [nbins] */
    int32_t nbins;
    uint8_t mof2_hist;     /* 1-bit transition history per call site */
} AprismCfarState_T;

/* Median of a[0..n) using caller scratch[0..n). */
float Aprism_Median(const float *a, float *scratch, int32_t n);

/* Slow-loop floor update for one range bin over track-free doppler cells. */
void Aprism_DualLoopFloor(AprismCfarState_T *st, int32_t r,
                          const float *row, const uint8_t *free_mask, int32_t nd,
                          float *scratch);

/* Span-heterogeneity R0 selection. */
int32_t Aprism_SelectR0(float span, float tau1, float tau2);

/* BLUE weights: beta = (m/v)/sum(m^2/v), m = 1+pi*s. */
void Aprism_BlueWeights(const float *pi, const float *snr, float *beta, int32_t n);

/* Threshold multiplier for Pfa*: solve sum ln(1+a*b) + ln(Pfa) = 0. */
float Aprism_AlphaForPfa(const float *beta, int32_t n, float pfa_star);

/* Classical CA factor (all-beta-equal special case). */
float Aprism_CaAlpha(int32_t n, float pfa_star);

#ifdef __cplusplus
}
#endif

#endif /* APPL_ADAPTIVE_CFAR_H */
