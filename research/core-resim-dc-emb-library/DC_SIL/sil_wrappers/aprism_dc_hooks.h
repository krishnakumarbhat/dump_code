/* A-PRISM DC hooks (preflight / deskew / clock split): header-only helpers.
 * Self-contained (cmath/cstdint only). Production call sites are guarded by
 * APRISM_DC_ENABLE (default OFF = bit-identical baseline). Zero heap, bounded.
 */
#ifndef APRISM_DC_HOOKS_H
#define APRISM_DC_HOOKS_H

#include <cmath>
#include <cstdint>

/* DC-1 preflight seed state (HPCC parallel nodes start aligned on frame 1). */
struct Aprism_Align_Seed_T {
   float az_deg;
   float el_deg;
   uint8_t aligned;
   uint8_t valid;
};
inline Aprism_Align_Seed_T &Aprism_Seed_State()
{
   static Aprism_Align_Seed_T s = {0.0F, 0.0F, 0U, 0U};
   return s;
}
/* Validates converged-header seed (|az|<=5deg, |el|<=2deg); 1 = accepted. */
inline uint8_t Aprism_DC_Preflight_Seed(float conv_az_deg, float conv_el_deg)
{
   Aprism_Align_Seed_T &s = Aprism_Seed_State();
   float az               = conv_az_deg < 0.0F ? -conv_az_deg : conv_az_deg;
   float el               = conv_el_deg < 0.0F ? -conv_el_deg : conv_el_deg;
   if ((az > 5.0F) || (el > 2.0F)) {
      s.valid = 0U;
      return 0U;
   }
   s.az_deg  = conv_az_deg;
   s.el_deg  = conv_el_deg;
   s.aligned = 1U;
   s.valid   = 1U;
   return 1U;
}

/* DC-1 header transport: dets_info.AutoAlignAzimuth/Elevation (+QF) carried in
 * the log header (see recu_stream_log.cpp vcs_boresight_*_align_angle mapping
 * and HDF_Trace AutoAlign* datasets) IS the converged DA seed transport
 * (M2D one-time path). Gate: QF>0 (calibration may tighten) + range check. */
inline uint8_t Aprism_DC_Seed_From_Header(float az, float el, unsigned qf_az, unsigned qf_el)
{
   if ((qf_az == 0U) || (qf_el == 0U)) return Aprism_Seed_State().valid;
   return Aprism_DC_Preflight_Seed(az, el);
}

/* DC-2 rigid-body async extrapolation:
 * p_corr = Rz(w*dt)*p - v*dt - 0.5*a*dt^2 (2-D, ego frame). */
inline void Aprism_DC_Deskew(float px, float py, float vx, float vy, float w, float ax, float ay, float dt,
                             float &ox, float &oy)
{
   const float th = w * dt, c = cosf(th), sn = sinf(th);
   const float rx = c * px - sn * py, ry = sn * px + c * py;
   ox = rx - vx * dt - 0.5F * ax * dt * dt;
   oy = ry - vy * dt - 0.5F * ay * dt * dt;
}
/* Max |dt| recorder (SiL visibility of async spread). */
inline float Aprism_DC_Note_Dt(float dt)
{
   static float m = 0.0F;
   float a        = dt < 0.0F ? -dt : dt;
   if (a > m) m = a;
   return m;
}

/* DC-3 yaw-free clock/bias split (shared with Gen8 N27, duplicated here so the
 * DC lib has no Gen8 dependency): tau from (r,w,d.v), 2-target (tau,b) solve. */
inline float Aprism_DC_ClockTau1(const float *d, const float *v, float r, float w)
{
   const float den = v[0] * v[0] + v[1] * v[1];
   if (den <= 0.0F) return 0.0F;
   return (r * w - (d[0] * v[0] + d[1] * v[1])) / den;
}
inline bool Aprism_DC_ClockTauBias2(float a1, float r1, float y1, float a2, float r2, float y2, float *tau, float *b)
{
   const float D = a1 * r2 - a2 * r1;
   if (D == 0.0F) return false;
   if (tau != nullptr) *tau = (y1 * r2 - y2 * r1) / D;
   if (b != nullptr) *b = (a1 * y2 - a2 * y1) / D;
   return true;
}
/* Consecutive-scan clock/bias tracker: feeds (speed, yaw, ts) from UpdateHostInfo.
 * Proxy transport: inter-scan ego-motion pair. Replace with paired-target inputs
 * at fusion-buffer integration (documented). Sidecar only, no output touched. */
struct Aprism_DC_Clock_State_T {
   float tau;
   float b;
   uint8_t ok;
};
inline Aprism_DC_Clock_State_T &Aprism_DC_Clock_State()
{
   static Aprism_DC_Clock_State_T s = {0.0F, 0.0F, 0U};
   return s;
}
inline void Aprism_DC_Clock_Update(float speed, float yawrate, double ts_us)
{
   static float prev_speed = 0.0F;
   static double prev_ts   = 0.0;
   static uint8_t have_prev = 0U;
   Aprism_DC_Clock_State_T &s = Aprism_DC_Clock_State();
   if (have_prev != 0U) {
      const float dt = (float)((ts_us - prev_ts) * 1e-6);
      if ((dt > 0.001F) && (dt < 1.0F)) {
         /* 1-DOF proxy pair: (a1,r1,y1) = (1, dt, dv), (a2,r2,y2) = (dt, 1, dyaw).
          * Carries the Gram structure; paired-target inputs replace this proxy. */
         const float dv   = speed - prev_speed;
         const float dyaw = yawrate * dt;
         float tau = 0.0F, b = 0.0F;
         if (Aprism_DC_ClockTauBias2(1.0F, dt, dv, dt, 1.0F, dyaw, &tau, &b)) {
            s.tau = tau;
            s.b   = b;
            s.ok  = 1U;
         }
      }
   }
   prev_speed = speed;
   prev_ts    = ts_us;
   have_prev  = 1U;
}

#endif /* APRISM_DC_HOOKS_H */
