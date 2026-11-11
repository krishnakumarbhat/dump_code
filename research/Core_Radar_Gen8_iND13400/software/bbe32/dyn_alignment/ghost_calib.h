/* A-PRISM ghost-based calibration kernels (N25/N26/N20g/N27 + DA fast-lock).
 * Self-contained C99 (math.h only). All angles radians, 2-D vectors [x,y].
 * Zero heap; fixed bounds. Verified by aprism_host_tests/test_ghost_calib.c.
 */
#ifndef GHOST_CALIB_H
#define GHOST_CALIB_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GHOST_CALIB_MAXREC (256)
#define GHOST_CALIB_DEG    (0.017453292519943295f)

/* ---- N25: ghost-difference relative yaw + baseline closure ---- */
typedef struct GhostYawResult_Tag {
    float delta;   /* beta_j - beta_i */
    float beta_i;
    float beta_j;
    float lmin;    /* min |D| lever */
    float cmax;    /* max |C| */
    bool  valid;   /* false on L=0 / zero baseline / no records */
} GhostYawResult_T;

/* zd1/zg1, zd2/zg2: [2*M] direct/ghost local-Cartesian records.
 * s1,s2: surveyed centers. */
GhostYawResult_T GhostEstimateYaw(const float *zd1, const float *zg1,
                                  const float *zd2, const float *zg2,
                                  int32_t m, const float *s1, const float *s2);

/* Deterministic arcsin release certificate. */
bool GhostCertify(float eps, float lmin, float cmax, float baseline,
                  float *e_rel_deg, float *e_i_deg, float *e_j_deg);

/* ---- N26: closed-form specular contact inverse ---- */
typedef struct GhostContact_Tag {
    float q[2];    /* foot */
    float n[2];    /* normal (sensor side) */
    float a[2];    /* target-side direction */
    float t;       /* ray distance */
    float rho;
    bool  valid;
} GhostContact_T;

GhostContact_T GhostInverseContact(const float *s, const float *p,
                                   const float *u, float ell);

/* ---- N20g: Hermite cubic solve from two point-slope pairs ---- */
/* xs[2],ys[2],slopes[2] -> c[4] monomial coeffs. Returns det magnitude. */
float HermiteSolve2(const float *xs, const float *ys, const float *slopes,
                    float *c);

/* ---- N27: yaw-free clock/bias ---- */
float ClockTau1(const float *d, const float *v, float r, float w); /* N27.1 */
bool ClockTauBias2(float a1, float r1, float y1,
                   float a2, float r2, float y2,
                   float *tau, float *b);                          /* N27.2 */

/* ---- DA fast-lock: dual-horizon gain + lock detector ---- */
float DaDualHorizonGain(float k_fast, float k_slow, float alpha, int32_t n);
bool DaLockDetect(float err_deg, float tol_deg, int32_t *hold_count, int32_t need);

#ifdef __cplusplus
}
#endif

#endif /* GHOST_CALIB_H */
