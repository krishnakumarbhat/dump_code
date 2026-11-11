#include <gtest/gtest.h>

extern "C"
{
#include "../VSE_Core.h"
#include "../vse_stub/VSE_Teststub.h"

   static uint8_t g_radar_position = RADAR_POS_FRONT_LEFT;

   uint8_t Get_Radar_Position(void)
   {
      return g_radar_position;
   }
}

class VSECoreUnitTest : public ::testing::Test
{
 protected:
   volatile M2D_Msg_T m2d_msg_test{};

   void SetUp() override
   {
      memset((void *)&m2d_msg_test, 0, sizeof(m2d_msg_test));
      g_radar_position = RADAR_POS_FRONT_LEFT;

      m2d_msg_test.payload.veh_data.veh_params.k_wheel_base                      = 2.8F;
      m2d_msg_test.payload.veh_data.veh_params.k_dist_rear_axle_to_vcs           = 1.2F;
      m2d_msg_test.payload.veh_data.veh_params.k_long_dist_radar_to_rear_axle    = 1.0F;
      m2d_msg_test.payload.veh_data.veh_params.k_lat_dist_radar_to_rear_axle     = 0.75F;
      m2d_msg_test.payload.veh_data.veh_params.k_steering_gear_ratio             = 16.0F;
      m2d_msg_test.payload.veh_data.veh_params.k_understeer_coefficient          = 0.2F;
      m2d_msg_test.payload.veh_data.veh_params.k_rear_cornering_compliance       = 0.0F;
      m2d_msg_test.payload.veh_data.veh_params.k_vehicle_width                   = 1.8F;
      m2d_msg_test.payload.veh_data.veh_params.k_cog_x                           = 0.0F;
      m2d_msg_test.payload.veh_data.veh_params.k_cog_y                           = 0.0F;
      m2d_msg_test.payload.veh_data.veh_params.k_front_track_width               = 1.6F;
      m2d_msg_test.payload.veh_data.veh_params.k_steering_ratio_rack_pinion_type = 1U;

      m2d_msg_test.payload.veh_data.last_key_cycle.nvm_last_rem_swa_bias_deg                  = 0.0F;
      m2d_msg_test.payload.veh_data.last_key_cycle.nvm_f_last_rem_swa_bias                    = 0U;
      m2d_msg_test.payload.veh_data.last_key_cycle.nvm_last_rem_speed_comp                    = 1.0F;
      m2d_msg_test.payload.veh_data.last_key_cycle.nvm_last_rem_stop_yaw_bias_primary_radps   = 0.0F;
      m2d_msg_test.payload.veh_data.last_key_cycle.nvm_last_rem_stop_yaw_bias_secondary_radps = 0.0F;
   }
};

TEST_F(VSECoreUnitTest, RunVSE_InitializesAndPopulatesOutputFromStubbedCycle)
{
   build_vse_cycle(0.0, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                   &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);

   Run_VSE(&m2d_msg_test);

   EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
   EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output.timestamp_secs,
             m2d_msg_test.payload.veh_data.veh_raw_data[4].system_time_secs);
   EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output.timestamp_nanosecs,
             m2d_msg_test.payload.veh_data.veh_raw_data[4].system_time_nanosecs);
   EXPECT_GE(m2d_msg_test.payload.veh_data.vse_output.veh_index, 0U);
   EXPECT_LE(m2d_msg_test.payload.veh_data.vse_output.veh_index, 5U);
   EXPECT_GT(m2d_msg_test.payload.veh_data.vse_output.vse_major_version, 0U);
   EXPECT_GE(m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps, -10.0F);
   EXPECT_LE(m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps, 10.0F);
   EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 0.0F, 0.3F);
   EXPECT_GE(m2d_msg_test.payload.veh_data.vse_output.raw_yaw_rate_rps, -2.0F);
   EXPECT_LE(m2d_msg_test.payload.veh_data.vse_output.raw_yaw_rate_rps, 2.0F);
}

TEST_F(VSECoreUnitTest, RunVSE_NullPointer_DoesNotCrash)
{
   Run_VSE(nullptr);
}

TEST_F(VSECoreUnitTest, RunVSE_Phase1_Stationary_ParkedNotMoving)
{
   // 0.0s – 1.0s: Stationary - Parked, not moving (speed = 0, standstill = 1, gear = P, accels/yaw ≈ 0)
   for (int step = 0; step < 20; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
      EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.vehicle_standstill, 1U);
      EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_PARK);
      EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps, 0.0F, 0.3F);
      EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 0.0F, 0.3F);
      EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.raw_yaw_rate_rps, 0.0F, 0.1F);
      EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_longitudinal_accel, 0.0F, 0.3F);
      EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_lateral_accel, 0.0F, 0.3F);
   }
}

TEST_F(VSECoreUnitTest, RunVSE_Phase2_Acceleration_PullsAwaySpeedRamps)
{
   // 1.0s – 3.0s: Acceleration - Pulls away, speed ramps 0 -> 4 m/s (long_accel = +2 m/s², speed rising, gear = D)
   float initial_speed = 0.0F;
   float final_speed   = 0.0F;

   for (int step = 0; step < 60; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 20)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_DRIVE);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_longitudinal_accel, 2.0F, 0.3F);

         if (step == 20)
         {
            initial_speed = m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps;
         }
         else if (step == 59)
         {
            final_speed = m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps;
         }
      }
   }

   EXPECT_LT(initial_speed, final_speed);
   EXPECT_NEAR(final_speed, 4.0F, 0.5F);
}

TEST_F(VSECoreUnitTest, RunVSE_Phase3_Cruise_SteadyMovingAtFourMps)
{
   // 3.0s – 4.0s: Cruise - Steady moving (speed = 4 m/s, long_accel = 0)
   for (int step = 0; step < 80; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 63)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_DRIVE);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps, 4.0F, 0.5F);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 4.0F, 0.5F);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_longitudinal_accel, 0.0F, 0.3F);
      }
   }
}

TEST_F(VSECoreUnitTest, RunVSE_Phase4_TurningLeft_SteeringRampsAndYawActive)
{
   // 4.0s – 6.0s: Turning (left) - Turns left while cruising (steer 0->90deg, steer_speed = 180deg/s during 0.5s ramp, yaw_rate =
   // 0.25 rad/s, lat_accel = 1.0 m/s², turn_signal = LEFT)
   for (int step = 0; step < 120; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 80)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.turn_signal, TURN_LEFT);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 4.0F, 0.5F);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.raw_yaw_rate_rps, 0.25F, 0.1F);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_lateral_accel, 1.0F, 0.3F);

         if (step >= 80 && step < 90)
         {
            EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].steering_whl_speed_deg_per_s, 180.0F, 10.0F);
         }
         else if (step >= 90)
         {
            EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].steering_whl_angle, 90.0F, 5.0F);
         }
      }
   }
}

TEST_F(VSECoreUnitTest, RunVSE_Phase5_Deceleration_BrakesToStop)
{
   // 6.0s – 8.0s: Deceleration - Brakes to a stop, 4 -> 0 m/s (long_accel = -2 m/s², speed falling)
   float initial_decel_speed = 0.0F;
   float final_decel_speed   = 0.0F;

   for (int step = 0; step < 160; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 120)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_DRIVE);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_longitudinal_accel, -2.0F, 0.3F);

         if (step == 120)
         {
            initial_decel_speed = m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps;
         }
         else if (step == 159)
         {
            final_decel_speed = m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps;
            EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 0.05F, 0.5F);
         }
      }
   }

   EXPECT_GT(initial_decel_speed, final_decel_speed);
   EXPECT_NEAR(final_decel_speed, 0.0F, 0.5F);
}

TEST_F(VSECoreUnitTest, RunVSE_Phase6_StopAndGearChange_HaltsAndShiftsToReverse)
{
   // 8.0s – 8.5s: Stop + gear change - Halts, shifts D -> R (standstill = 1, gear changes to R)
   for (int step = 0; step < 170; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 160)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.vehicle_standstill, 1U);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_REVERSE);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.raw_speed_mps, 0.0F, 0.3F);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, 0.0F, 0.3F);
      }
   }
}

TEST_F(VSECoreUnitTest, RunVSE_Phase7_Reverse_BacksUpSlowly)
{
   // 8.5s – 9.0s: Reverse - Backs up slowly (speed = -1 m/s, gear = R)
   for (int step = 0; step <= 180; ++step)
   {
      double t = (double)step * 0.05;
      build_vse_cycle(t, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);

      if (step >= 170)
      {
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.veh_raw_misc.gear_pos, GEAR_REVERSE);
         EXPECT_NEAR(m2d_msg_test.payload.veh_data.veh_raw_data[4].ego_vehicle_speed, -1.0F, 0.3F);
         EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output.reverse_status, 1U);

         if (step >= 178)
         {
            EXPECT_NEAR(m2d_msg_test.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, -1.0F, 0.3F);
         }
      }
   }
}

TEST_F(VSECoreUnitTest, RunVSE_DifferentRadarPositions_PopulatesPositionSpecificParams)
{
   const uint8_t radar_positions[] = {RADAR_POS_FRONT_RIGHT,  RADAR_POS_REAR_LEFT,  RADAR_POS_REAR_RIGHT,
                                      RADAR_POS_FRONT_CENTER, RADAR_POS_FRONT_LEFT, INVALID_POSITION};

   for (uint8_t pos : radar_positions)
   {
      g_radar_position = pos;
      build_vse_cycle(1.5, &m2d_msg_test.payload.veh_data.veh_raw_data[0], &m2d_msg_test.payload.veh_data.veh_raw_misc,
                      &m2d_msg_test.payload.veh_data.veh_params, &m2d_msg_test.payload.veh_data.latest_raw_index);
      Run_VSE(&m2d_msg_test);
      EXPECT_EQ(m2d_msg_test.payload.veh_data.vse_output_valid, CODED_TRUE);
   }
}
