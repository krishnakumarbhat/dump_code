/* A-PRISM ghost calibration implementation. See header for contract. */
#include "ghost_calib.h"

#include <math.h>

static float gc_norm2(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1]);
}

GhostYawResult_T GhostEstimateYaw(const float *zd1, const float *zg1,
                                  const float *zd2, const float *zg2,
                                  int32_t m, const float *s1, const float *s2)
{
    GhostYawResult_T out = {0};
    float h_re = 0.0f, h_im = 0.0f;
    float c1[2] = {0.0f, 0.0f}, c2[2] = {0.0f, 0.0f};
    float bx, by, B[2], blen, mean_b[2];
    float ca, sa, rb_re, rb_im;
    int32_t k;
    out.valid = false;
    if ((m <= 0) || (m > GHOST_CALIB_MAXREC)) {
        return out;
    }
    for (k = 0; k < m; k++) {
        float d1x = zd1[2 * k] - zg1[2 * k];
        float d1y = zd1[2 * k + 1] - zg1[2 * k + 1];
        float d2x = zd2[2 * k] - zg2[2 * k];
        float d2y = zd2[2 * k + 1] - zg2[2 * k + 1];
        float L = sqrtf(d1x * d1x + d1y * d1y);
        if (L < 1e-12f) {
            return out; /* L=0: target on reflector */
        }
        if (k == 0) {
            out.lmin = L;
        } else if (L < out.lmin) {
            out.lmin = L;
        }
        /* conj(D_j) * D_i accumulation: H = sum D_i * conj(D_j) */
        h_re += d1x * d2x + d1y * d2y;
        h_im += d1y * d2x - d1x * d2y;
        c1[0] += 0.5f * (zd1[2 * k] + zg1[2 * k]);
        c1[1] += 0.5f * (zd1[2 * k + 1] + zg1[2 * k + 1]);
        c2[0] += 0.5f * (zd2[2 * k] + zg2[2 * k]);
        c2[1] += 0.5f * (zd2[2 * k + 1] + zg2[2 * k + 1]);
    }
    if ((h_re == 0.0f) && (h_im == 0.0f)) {
        return out;
    }
    out.delta = atan2f(h_im, h_re);
    c1[0] /= (float)m;
    c1[1] /= (float)m;
    c2[0] /= (float)m;
    c2[1] /= (float)m;
    /* max |C_j| over sensor-2 records (certificate input) */
    out.cmax = 0.0f;
    {
        int32_t k2;
        for (k2 = 0; k2 < m; k2++) {
            float mx = 0.5f * (zd2[2 * k2] + zg2[2 * k2]);
            float my = 0.5f * (zd2[2 * k2 + 1] + zg2[2 * k2 + 1]);
            float cc = sqrtf(mx * mx + my * my);
            if (cc > out.cmax) {
                out.cmax = cc;
            }
        }
    }
    ca = cosf(out.delta);
    sa = sinf(out.delta);
    /* R(delta) * mean(C_j): rotation of averaged midpoint */
    rb_re = ca * c2[0] - sa * c2[1];
    rb_im = sa * c2[0] + ca * c2[1];
    mean_b[0] = c1[0] - rb_re;
    mean_b[1] = c1[1] - rb_im;
    B[0] = s2[0] - s1[0];
    B[1] = s2[1] - s1[1];
    blen = gc_norm2(B);
    if (blen == 0.0f) {
        return out; /* zero baseline: relative-only, refuse absolute */
    }
    bx = mean_b[0];
    by = mean_b[1];
    /* beta_i = arg(B * conj(mean_b)): Re = dot, Im = cross(By*bx - Bx*by) */
    out.beta_i = atan2f(B[1] * bx - B[0] * by, B[0] * bx + B[1] * by);
    out.beta_j = out.beta_i + out.delta;
    out.valid = true;
    return out;
}

bool GhostCertify(float eps, float lmin, float cmax, float baseline,
                  float *e_rel_deg, float *e_i_deg, float *e_j_deg)
{
    float rho, e_d, eb, e_i;
    const float rad2deg = 57.29577951308232f;
    if ((lmin <= 0.0f) || (baseline <= 0.0f)) {
        return false;
    }
    rho = 4.0f * eps / lmin + (2.0f * eps / lmin) * (2.0f * eps / lmin);
    if (rho >= 1.0f) {
        return false;
    }
    e_d = asinf(rho < 1.0f ? rho : 1.0f);
    eb = 2.0f * eps + 2.0f * cmax * sinf(e_d / 2.0f);
    if (eb >= baseline) {
        return false;
    }
    {
        float r = eb / baseline;
        e_i = asinf(r < 1.0f ? r : 1.0f);
    }
    if (e_rel_deg != NULL) {
        *e_rel_deg = e_d * rad2deg;
    }
    if (e_i_deg != NULL) {
        *e_i_deg = e_i * rad2deg;
    }
    if (e_j_deg != NULL) {
        *e_j_deg = (e_i + e_d) * rad2deg;
    }
    return true;
}

GhostContact_T GhostInverseContact(const float *s, const float *p,
                                   const float *u, float ell)
{
    GhostContact_T out = {{0, 0}, {0, 0}, {0, 0}, 0, 0, false};
    float ulen, ux, uy, dx, dy, d2, ud, B, t, rho, ax, ay, zx, zy, nz;
    ulen = gc_norm2(u);
    if (ulen == 0.0f) {
        return out;
    }
    ux = u[0] / ulen;
    uy = u[1] / ulen;
    dx = p[0] - s[0];
    dy = p[1] - s[1];
    d2 = dx * dx + dy * dy;
    if (ell * ell <= d2) {
        return out; /* ell <= |d| degenerate */
    }
    ud = ux * dx + uy * dy;
    B = ell - ud;
    if (B <= 1e-12f) {
        return out;
    }
    t = (ell * ell - d2) / (2.0f * B);
    if ((t <= 0.0f) || (t >= ell)) {
        return out;
    }
    rho = ell - t;
    if (rho <= 0.0f) {
        return out;
    }
    out.t = t;
    out.rho = rho;
    out.q[0] = s[0] + t * ux;
    out.q[1] = s[1] + t * uy;
    ax = (p[0] - out.q[0]) / rho;
    ay = (p[1] - out.q[1]) / rho;
    out.a[0] = ax;
    out.a[1] = ay;
    zx = ax - ux;
    zy = ay - uy;
    nz = sqrtf(zx * zx + zy * zy);
    if (nz == 0.0f) {
        return out; /* collinear a==u */
    }
    out.n[0] = zx / nz;
    out.n[1] = zy / nz;
    out.valid = true;
    return out;
}

float HermiteSolve2(const float *xs, const float *ys, const float *slopes,
                    float *c)
{
    /* 4x4 confluent Vandermonde solve by Gaussian elimination (fixed 4). */
    float A[4][5];
    float V[4][4] = {{1, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}};
    float z[4];
    int32_t r, col, piv;
    float x1 = xs[0], x2 = xs[1];
    V[0][0] = 1.0f;
    V[0][1] = x1;
    V[0][2] = x1 * x1;
    V[0][3] = x1 * x1 * x1;
    V[1][0] = 0.0f;
    V[1][1] = 1.0f;
    V[1][2] = 2.0f * x1;
    V[1][3] = 3.0f * x1 * x1;
    V[2][0] = 1.0f;
    V[2][1] = x2;
    V[2][2] = x2 * x2;
    V[2][3] = x2 * x2 * x2;
    V[3][0] = 0.0f;
    V[3][1] = 1.0f;
    V[3][2] = 2.0f * x2;
    V[3][3] = 3.0f * x2 * x2;
    z[0] = ys[0];
    z[1] = slopes[0];
    z[2] = ys[1];
    z[3] = slopes[1];
    for (r = 0; r < 4; r++) {
        int32_t cc;
        for (cc = 0; cc < 4; cc++) {
            A[r][cc] = V[r][cc];
        }
        A[r][4] = z[r];
    }
    for (col = 0; col < 4; col++) {
        float best = 0.0f;
        int32_t rr;
        piv = col;
        for (rr = col; rr < 4; rr++) {
            float av = A[rr][col] < 0.0f ? -A[rr][col] : A[rr][col];
            if (av > best) {
                best = av;
                piv = rr;
            }
        }
        if (best == 0.0f) {
            return 0.0f; /* singular */
        }
        if (piv != col) {
            int32_t cc;
            for (cc = col; cc < 5; cc++) {
                float t = A[col][cc];
                A[col][cc] = A[piv][cc];
                A[piv][cc] = t;
            }
        }
        {
            float inv = 1.0f / A[col][col];
            int32_t rr, cc;
            for (cc = col; cc < 5; cc++) {
                A[col][cc] *= inv;
            }
            for (rr = 0; rr < 4; rr++) {
                if (rr != col) {
                    float f = A[rr][col];
                    for (cc = col; cc < 5; cc++) {
                        A[rr][cc] -= f * A[col][cc];
                    }
                }
            }
        }
    }
    for (r = 0; r < 4; r++) {
        c[r] = A[r][4];
    }
    /* determinant magnitude via product of pivots ~ (x2-x1)^4 scale check */
    {
        float h = x2 - x1;
        return h * h * h * h; /* |det| scale (exact for confluent Vandermonde) */
    }
}

float ClockTau1(const float *d, const float *v, float r, float w)
{
    float den = v[0] * v[0] + v[1] * v[1];
    if (den <= 0.0f) {
        return 0.0f; /* v=0 unobservable; caller must gate */
    }
    return (r * w - (d[0] * v[0] + d[1] * v[1])) / den;
}

bool ClockTauBias2(float a1, float r1, float y1,
                   float a2, float r2, float y2,
                   float *tau, float *b)
{
    float D = a1 * r2 - a2 * r1;
    if (D == 0.0f) {
        return false;
    }
    if (tau != NULL) {
        *tau = (y1 * r2 - y2 * r1) / D;
    }
    if (b != NULL) {
        *b = (a1 * y2 - a2 * y1) / D;
    }
    return true;
}

float DaDualHorizonGain(float k_fast, float k_slow, float alpha, int32_t n)
{
    /* K_DA(n) = K_fast * exp(-a*n) + K_slow. n>=0. */
    if (n < 0) {
        n = 0;
    }
    return k_fast * expf(-alpha * (float)n) + k_slow;
}

bool DaLockDetect(float err_deg, float tol_deg, int32_t *hold_count, int32_t need)
{
    if (hold_count == NULL) {
        return false;
    }
    if (err_deg < 0.0f) {
        err_deg = -err_deg;
    }
    if (err_deg <= tol_deg) {
        (*hold_count)++;
    } else {
        *hold_count = 0;
    }
    return (*hold_count >= need);
}
