/* vse_input_stub.c  -  build: gcc vse_input_stub.c -lm -o vse_input_stub */
#include "VSE_Teststub.h"
#include "sensor_position.h"
#include "smc_cal.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void build_vse_cycle(double t0, volatile Veh_Raw_Data_T *raw, volatile Veh_Raw_Misc_T *misc, volatile Veh_Params_T *veh_params,
                     volatile uint8_t *latest_raw_index);

/* Deterministic LCG uniform in [0, 1); reproducible across runs. */
static uint32_t g_rng = 0x12345678U;

static float rand_u01(void)
{
   g_rng = (g_rng * 1664525U) + 1013904223U;
   return (float)(g_rng >> 8) / (float)0x01000000U;
}

/* Standard normal (mean 0, std 1) via Box-Muller; caches the spare value. */
static float noise_gauss(void)
{
   static int have_spare = 0;
   static float spare    = 0.0f;
   float u1;
   float u2;
   float mag;

   if (have_spare)
   {
      have_spare = 0;
      return spare;
   }

   u1 = rand_u01();
   u2 = rand_u01();
   if (u1 < 1e-7f)
   {
      u1 = 1e-7f; /* guard against log(0) */
   }
   mag        = sqrtf(-2.0f * logf(u1));
   spare      = mag * sinf(2.0f * 3.14159265358979f * u2);
   have_spare = 1;
   return mag * cosf(2.0f * 3.14159265358979f * u2);
}

/* Piecewise drive covering every requested condition (t in seconds). */
static Scenario_T scenario_at(double t)
{
   Scenario_T s;
   memset(&s, 0, sizeof(s));
   s.gear = GEAR_PARK;
   s.turn = TURN_NONE;

   if (t < 1.0) /* [0.0,1.0) stationary in park   */
   {
      s.speed      = 0.0f;
      s.gear       = GEAR_PARK;
      s.standstill = 1U;
   }
   else if (t < 3.0) /* [1.0,3.0) accelerate 0 -> 4 m/s */
   {
      s.gear       = GEAR_DRIVE;
      s.long_accel = 2.0f;
      s.speed      = (float)(2.0 * (t - 1.0));
   }
   else if (t < 4.0) /* [3.0,4.0) cruise 4 m/s          */
   {
      s.gear  = GEAR_DRIVE;
      s.speed = 4.0f;
   }
   else if (t < 6.0) /* [4.0,6.0) steady left turn      */
   {
      double tt = t - 4.0;
      s.gear    = GEAR_DRIVE;
      s.turn    = TURN_LEFT;
      s.speed   = 4.0f;
      if (tt < 0.5) /* ramp wheel 0 -> 90 deg          */
      {
         s.steer_deg   = (float)(180.0 * tt);
         s.steer_speed = 180.0f;
      }
      else
      {
         s.steer_deg   = 90.0f;
         s.steer_speed = 0.0f;
      }
      s.yaw       = 0.25f;
      s.lat_accel = s.speed * s.yaw;
   }
   else if (t < 8.0) /* [6.0,8.0) decelerate 4 -> 0 m/s */
   {
      s.gear       = GEAR_DRIVE;
      s.long_accel = -2.0f;
      s.speed      = (float)(4.0 - 2.0 * (t - 6.0));
      if (s.speed < 0.0f)
      {
         s.speed = 0.0f;
      }
   }
   else if (t < 8.5) /* [8.0,8.5) stop + shift to R     */
   {
      s.gear       = GEAR_REVERSE;
      s.speed      = 0.0f;
      s.standstill = 1U;
   }
   else /* [8.5,9.0) reverse slowly        */
   {
      s.gear  = GEAR_REVERSE;
      s.speed = -1.0f;
   }

   return s;
}

static void fill_raw(volatile Veh_Raw_Data_T *r, double t, const Scenario_T *s)
{
   /* +1 s bias so t=0 never yields the all-zero "empty slot" sentinel */
   uint64_t ns = (uint64_t)(t * 1e9 + 0.5) + 1000000000ULL;

   r->system_time_secs     = (uint32_t)(ns / 1000000000ULL);
   r->system_time_nanosecs = (uint32_t)(ns % 1000000000ULL);

   r->ego_vehicle_speed            = s->speed;
   r->ego_yaw_rate                 = s->yaw;
   r->steering_whl_angle           = s->steer_deg;
   r->steering_whl_speed_deg_per_s = s->steer_speed;
   r->ego_lateral_accel            = s->lat_accel;
   r->ego_longitudinal_accel       = s->long_accel;

#if VSE_INPUT_NOISE
   /* per-signal Gaussian noise sigma (1 std dev); timestamps left untouched */
   r->ego_vehicle_speed += 0.05f * noise_gauss();            /* m/s   */
   r->ego_yaw_rate += 0.01f * noise_gauss();                 /* rad/s */
   r->steering_whl_angle += 0.50f * noise_gauss();           /* deg   */
   r->steering_whl_speed_deg_per_s += 2.00f * noise_gauss(); /* deg/s */
   r->ego_lateral_accel += 0.05f * noise_gauss();            /* m/s^2 */
   r->ego_longitudinal_accel += 0.05f * noise_gauss();       /* m/s^2 */
#endif
}

static void fill_misc(volatile Veh_Raw_Misc_T *m, const Scenario_T *s)
{
   memset((void *)m, 0, sizeof(*m));
   m->vehspeedcompfac_ka        = 1.0f;
   m->vehspeedcompfac_ka_qf     = QF_VALID;
   m->ego_vehicle_speed_qf      = QF_VALID;
   m->ego_yaw_rate_qf           = QF_VALID;
   m->steering_whl_angle_qf     = QF_VALID;
   m->ego_lateral_accel_qf      = QF_VALID;
   m->ego_longitudinal_accel_qf = QF_VALID;
   m->vehicle_standstill        = s->standstill;
   m->gear_pos                  = s->gear;
   m->turn_signal               = s->turn;
}
static void fill_veh_params(volatile Veh_Params_T *veh_params)
{
   veh_params->k_wheel_base            = k_wheelbase_smc;
   veh_params->k_dist_rear_axle_to_vcs = k_distance_front_bumper_to_rear_axle_smc;

   veh_params->k_steering_gear_ratio             = k_steering_gear_ratio_smc;
   veh_params->k_understeer_coefficient          = k_rear_cornering_complicane_smc;
   veh_params->k_rear_cornering_compliance       = k_rear_cornering_complicane_smc;
   veh_params->k_vehicle_length                  = k_vehicle_length_smc;
   veh_params->k_vehicle_width                   = k_vehicle_width_smc;
   veh_params->k_cog_x                           = 0.0F;
   veh_params->k_cog_y                           = 0.0F;
   veh_params->k_front_track_width               = 0.0F;
   veh_params->k_steering_ratio_rack_pinion_type = 0.0F;

   uint8_t sts_radar_pos                      = Get_Radar_Position();
   uint8_t smc_index                          = sts_radar_pos - (uint8_t)BIT_1;
   veh_params->k_long_dist_radar_to_rear_axle = k_sensor_mount_pos_x_list_smc[smc_index];
   veh_params->k_lat_dist_radar_to_rear_axle  = k_sensor_mount_pos_y_list_smc[smc_index];
}
/* Fill one 10 ms cycle: 5 raw ticks + one misc snapshot. */
void build_vse_cycle(double t0, volatile Veh_Raw_Data_T *raw, volatile Veh_Raw_Misc_T *misc, volatile Veh_Params_T *veh_params,
                     volatile uint8_t *latest_raw_index)
{
   static uint8_t index = 0;
   /* raw[VSE_RAW_INSTANCES - 1] always holds the newest tick (t0 + 0.04s). */

   Scenario_T s = scenario_at(t0);
   fill_raw(&raw[index], t0, &s);

   fill_misc(misc, &s);
   fill_veh_params(veh_params);

   *latest_raw_index = index;
   index             = (uint8_t)((index + 1) % VSE_RAW_INSTANCES);
}
#if 0
/* ---- demo driver: prints the newest tick of every cycle ---- */
static const char *gear_str(uint8_t g)
{
   switch (g)
   {
      case GEAR_PARK:    return "P";
      case GEAR_REVERSE: return "R";
      case GEAR_NEUTRAL: return "N";
      case GEAR_DRIVE:   return "D";
      default:           return "?";
   }
}

static const char *turn_str(uint8_t t)
{
   switch (t)
   {
      case TURN_NONE:   return "----";
      case TURN_LEFT:   return "LEFT";
      case TURN_RIGHT:  return "RGHT";
      case TURN_HAZARD: return "HAZ ";
      default:          return "?   ";
   }
}
#endif
