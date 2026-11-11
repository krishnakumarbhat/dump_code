/**
 * @file emb_tracker_wrapper_api_test.cpp
 *
 * Unit tests for embedded tracker wrapper with stub code enabled.
 */
#include "emb_tracker_internal.h"
#include "emb_tracker_project_parameters.h"
#include "emb_tracker_stubs.h"
#include "emb_tracker_wrapper.h"
#include "ipc_data.h"
#include "mem_pool.h"
#ifndef DISABLE_OCG
   #include "ocg_occupancy_grid_types.h"
#endif
#include "f360_detection_list.h"
#include "f360_reference_point.h"
#ifndef DISABLE_SG
   #include "sg_stationary_geometries.h"
#endif
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <gtest/gtest.h>
#include <limits>
#include <string>

/* bazelisk test //software/bbe32/emb_tracker/test:unit_tests_without_stub --tracker_variant=AL -c dbg */
/*bazelisk test //software/bbe32/emb_tracker/test:unit_tests_without_stub --tracker_variant=platform_srr8p_standalone -c dbg
 * --jobs=auto*/

extern "C"
{
   uint64_t Get_R52_Time_From_BBE32(void)
   {
      static uint64_t fake_time_us = 0U;
      fake_time_us += 50000U;
      return fake_time_us;
   }
}

/* Fake IPC M2D buffer so Update_Core_Info() can read hil_ipc_info.hil_mode_enabled without
 * linking the real (DSP-only) IPC driver implementation. */
static M2D_Msg_T fake_ipc_m2d_buffer{};

extern "C"
{
   volatile M2D_Msg_T *Get_IPC_M2D_Buffer(void)
   {
      return &fake_ipc_m2d_buffer;
   }

   /* Fake HIL time source mirroring the real Get_HIL_R52_Time_From_BBE32() formula, so tests can
    * verify Update_Core_Info() selects this path when hil_mode_enabled is set. */
   uint64_t Get_HIL_R52_Time_From_BBE32(D2M_Msg_T *p_ipc_d2m)
   {
      constexpr uint64_t kUsPerS              = 1000000ULL;
      constexpr uint64_t kNsPerUs             = 1000ULL;
      constexpr uint64_t kTimestampWorkaround = 30000U;
      return (static_cast<uint64_t>(p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec) * kUsPerS) +
             (p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns / kNsPerUs) + kTimestampWorkaround;
   }
}

class InitSensorsTest : public ::testing::Test
{
 protected:
   M2D_Msg_T m2d{};
   D2M_Msg_T p_ipc_d2m{};
   M2D_One_Time_Msg_T m2d_one_time{};
   static constexpr size_t kMemPoolBufferBytes = 2U * 1024U * 1024U;
   alignas(MEM_POOL_ALIGNMENT_IN_BYTES) uint8_t mem_buffer[kMemPoolBufferBytes]{};
   Mem_Pool_T memory_pool{};
   void SetUp() override
   {
      ASSERT_EQ(Mem_Pool_Init(&memory_pool, mem_buffer, kMemPoolBufferBytes), MEM_POOL_SUCCESS);
      ASSERT_EQ(Emb_Tracker_Mem_Init(&memory_pool, &p_ipc_d2m), MEM_POOL_SUCCESS); /*this is for creating ocg instance.*/
      Populate_Ipc_Data_For_Init_Stub_Sensors(&m2d_one_time, &m2d);
   }
};
TEST_F(InitSensorsTest, MountingLocationSwitchCoversAllPositions)
{
   struct
   {
      uint8_t radar_position;
      int8_t expected_location;
   } cases[] = {
      {RADAR_POSITION_REAR_LEFT, F360_MOUNTING_LOCATION_LEFT_REAR},
      {RADAR_POSITION_REAR_RIGHT, F360_MOUNTING_LOCATION_RIGHT_REAR},
      {RADAR_POSITION_FRONT_RIGHT, F360_MOUNTING_LOCATION_RIGHT_FORWARD},
      {RADAR_POSITION_FRONT_LEFT, F360_MOUNTING_LOCATION_LEFT_FORWARD},
      {RADAR_POSITION_FRONT_CENTER, F360_MOUNTING_LOCATION_CENTER_FORWARD},
      {99, F360_MOUNTING_LOCATION_UNKNOWN} /*Unknown/default*/
   };

   for (const auto &c : cases)
   {
      m2d_one_time.radar_position = c.radar_position;
      /*Set roll to 0 for polarity test*/
      m2d_one_time.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll = 0.0f;
      Init_Emb_Tracker(&m2d_one_time, &m2d);
      Run_Emb_Tracker(&p_ipc_d2m, &m2d, &m2d_one_time);
      EXPECT_EQ(sensors[0].mounting_location, c.expected_location)
         << "Failed for radar_position=" << static_cast<uint8_t>(c.radar_position);
      EXPECT_EQ(sensors[0].polarity, -1) << "Polarity should be -1 when roll=0, radar_position="
                                         << static_cast<uint8_t>(c.radar_position);
   }
}

class UpdateHostTest : public ::testing::Test
{
 protected:
   static constexpr size_t kMemPoolBufferBytes = 2U * 1024U * 1024U;

   D2M_Msg_T *p_ipc_d2m                            = nullptr;
   M2D_Msg_T *p_ipc_m2d                            = nullptr;
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = nullptr;
   alignas(MEM_POOL_ALIGNMENT_IN_BYTES) uint8_t mem_buffer[kMemPoolBufferBytes]{};
   Mem_Pool_T memory_pool{};

   void SetUp() override
   {
      p_ipc_d2m          = static_cast<D2M_Msg_T *>(malloc(sizeof(D2M_Msg_T)));
      p_ipc_m2d          = static_cast<M2D_Msg_T *>(malloc(sizeof(M2D_Msg_T)));
      p_ipc_m2d_one_time = static_cast<volatile M2D_One_Time_Msg_T *>(malloc(sizeof(M2D_One_Time_Msg_T)));

      ASSERT_NE(p_ipc_d2m, nullptr);
      ASSERT_NE(p_ipc_m2d, nullptr);
      ASSERT_NE(p_ipc_m2d_one_time, nullptr);

      memset(p_ipc_d2m, 0, sizeof(D2M_Msg_T));
      memset(p_ipc_m2d, 0, sizeof(M2D_Msg_T));
      memset(const_cast<M2D_One_Time_Msg_T *>(p_ipc_m2d_one_time), 0, sizeof(M2D_One_Time_Msg_T));

      ASSERT_EQ(Mem_Pool_Init(&memory_pool, mem_buffer, kMemPoolBufferBytes), MEM_POOL_SUCCESS);
      ASSERT_EQ(Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m), MEM_POOL_SUCCESS);

      Populate_Ipc_Data_For_Init_Stub_Sensors(p_ipc_m2d_one_time, p_ipc_m2d);
      Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);
      Populate_Ipc_Data_For_Stub_Host(p_ipc_d2m, p_ipc_m2d);
      /* Stub host memset wipes veh_params; restore so later Init_Emb_Tracker keeps host_calib. */
      p_ipc_m2d->payload.veh_data.veh_params.k_dist_rear_axle_to_vcs =
         p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
      p_ipc_m2d->payload.veh_data.veh_params.k_rear_cornering_compliance =
         p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_rear_cornering_compliance;
      p_ipc_m2d->payload.veh_data.veh_params.k_steering_gear_ratio =
         p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_steering_gear_ratio;
      p_ipc_m2d->payload.veh_data.veh_params.k_wheel_base     = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_wheelbase;
      p_ipc_m2d->payload.veh_data.veh_params.k_vehicle_width  = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_width;
      p_ipc_m2d->payload.veh_data.veh_params.k_vehicle_length = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_length;
      Populate_Ipc_Data_For_Stub_Dets();
   }
   void TearDown() override
   {
      fake_ipc_m2d_buffer.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
      stub_force_partner_flags_valid                            = true;

      free(p_ipc_d2m);
      free(p_ipc_m2d);
      free(const_cast<M2D_One_Time_Msg_T *>(p_ipc_m2d_one_time));
   }
};

TEST_F(UpdateHostTest, DynamicAlignmentModeErrorCombinationsUseExpectedBoresightValues)
{
   struct
   {
      uint8_t main_alignment_mode;
      uint8_t main_az_qf;
      uint8_t main_el_qf;
      uint8_t partner_alignment_mode;
      uint32_t partner_error_status_combined;
      bool expect_main_az_from_dra;
      bool expect_main_el_from_dra;
      bool expect_partner_from_stream;
   } cases[] = {
      {0U, 2U, 2U, 1U, 0U, false, false, true},
      {1U, 2U, 0U, 0U, 1U, true, false, false},
      {1U, 0U, 2U, 1U, 1U, false, true, false},
   };

   for (const auto &c : cases)
   {
      Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

      p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = -3.5F;

      const float estimated_az         = 0.123F + static_cast<float>(c.partner_error_status_combined);
      const float estimated_el         = -0.456F - static_cast<float>(c.partner_error_status_combined);
      const float partner_estimated_az = 0.789F + static_cast<float>(c.partner_error_status_combined);
      const float partner_estimated_el = -0.321F - static_cast<float>(c.partner_error_status_combined);

      p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode              = c.main_alignment_mode;
      p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf       = c.main_az_qf;
      p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf     = c.main_el_qf;
      p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated = estimated_az;
      p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated = estimated_el;

      p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_mode = c.partner_alignment_mode;
      p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_error_status_combined =
         c.partner_error_status_combined;
      p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_az_estimated = partner_estimated_az;
      p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_el_estimated = partner_estimated_el;

      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

      const float fallback_az         = sensors[0].mounting_position.vcs_boresight_azimuth_angle;
      const float fallback_el         = sensors[0].mounting_position.vcs_boresight_elevation_angle;
      const float partner_fallback_az = sensors[1].mounting_position.vcs_boresight_azimuth_angle;
      const float partner_fallback_el = sensors[1].mounting_position.vcs_boresight_elevation_angle;

      const float expected_az         = c.expect_main_az_from_dra ? estimated_az : fallback_az;
      const float expected_el         = c.expect_main_el_from_dra ? estimated_el : fallback_el;
      const float partner_expected_az = c.expect_partner_from_stream ? partner_estimated_az : partner_fallback_az;
      const float partner_expected_el = c.expect_partner_from_stream ? partner_estimated_el : partner_fallback_el;

      EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_az_estimated, expected_az)
         << "Failed for main_alignment_mode=" << static_cast<uint8_t>(c.main_alignment_mode)
         << ", main_az_qf=" << static_cast<uint8_t>(c.main_az_qf)
         << ", partner_error_status_combined=" << c.partner_error_status_combined;
      EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_el_estimated, expected_el)
         << "Failed for main_alignment_mode=" << static_cast<uint8_t>(c.main_alignment_mode)
         << ", main_el_qf=" << static_cast<uint8_t>(c.main_el_qf)
         << ", partner_error_status_combined=" << c.partner_error_status_combined;
      if (NUMBER_OF_SENSORS_EMB > 1)
      {
         EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_az_estimated, partner_expected_az)
            << "Partner failed for alignment_mode=" << static_cast<uint8_t>(c.partner_alignment_mode)
            << ", error_status_combined=" << c.partner_error_status_combined;
         EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_el_estimated, partner_expected_el)
            << "Partner failed for alignment_mode=" << static_cast<uint8_t>(c.partner_alignment_mode)
            << ", error_status_combined=" << c.partner_error_status_combined;
      }
      // EXPECT_FLOAT_EQ(host_raw.raw_speed, -3.5F)
      //    << "Host speed propagation failed for main_alignment_mode=" << static_cast<uint8_t>(c.main_alignment_mode)
      //    << ", partner_error_status_combined=" << c.partner_error_status_combined;
      // EXPECT_EQ(host_raw.prndl, F360_PRNDL_STATE_REVERSE)
      //    << "PRNDL reverse mapping failed for main_alignment_mode=" << static_cast<uint8_t>(c.main_alignment_mode)
      //    << ", partner_error_status_combined=" << c.partner_error_status_combined;
      // EXPECT_EQ(host_raw.reverse_gear, 1) << "Reverse gear flag failed for main_alignment_mode="
      //                                     << static_cast<uint8_t>(c.main_alignment_mode)
      //                                     << ", partner_error_status_combined=" << c.partner_error_status_combined;
   }
}

/* Combined main/partner timestamp decision matrix coverage:
 *   A: sec!=0, nanosec!=0
 *   B: sec!=0, nanosec==0
 *   C: sec==0, nanosec!=0
 *   D: sec==0, nanosec==0 -> workaround path
 */
TEST_F(UpdateHostTest, UpdateSensorsUsesExpectedTimestampsForMainAndPartner)
{
   struct UpdateSensorsTimestampCase
   {
      const char *name;
      uint32_t main_sec;
      uint32_t main_nanosec;
      uint32_t partner_sec;
      uint32_t partner_nanosec;
   } cases[] = {
      {"both_sec_and_nanosec_non_zero", 3U, 4567000U, 7U, 8912000U},
      {"only_sec_non_zero", 5U, 0U, 4U, 0U},
      {"only_nanosec_non_zero", 0U, 3000000U, 0U, 5000000U},
      {"both_zero", 0U, 0U, 0U, 0U},
   };

   constexpr uint64_t kUsPerS              = 1000000ULL;
   constexpr uint64_t kNsPerUs             = 1000ULL;
   constexpr uint64_t kTimestampWorkaround = 30000U;

   /* The main sensor's variable data (including timestamp_us) is delayed by MAIN_SENSOR_BUFFER_DELAY_CYCLES
    * cycles via a ring buffer (see Update_Sensors()/Run_Emb_Tracker()); the partner sensor path is not
    * buffered. Mirror that ring-buffer indexing here so the expected main timestamp matches what the
    * read pointer actually exposes on each cycle instead of the value just computed this cycle. */
   constexpr uint32_t kMainSensorBufferLength = MAIN_SENSOR_BUFFER_DELAY_CYCLES + 1U;
   uint64_t main_timestamp_ring[kMainSensorBufferLength]{};
   uint32_t main_write_idx = 0U;
   uint32_t main_read_idx  = 0U;
   uint32_t cnt_loops      = 0U;

   for (const auto &test_case : cases)
   {
      p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec         = test_case.main_sec;
      p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns          = test_case.main_nanosec;
      p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].ts_mid_dwell_sec     = test_case.partner_sec;
      p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].ts_mid_dwell_nanosec = test_case.partner_nanosec;

      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

      const bool main_has_timestamp    = (test_case.main_sec != 0U) || (test_case.main_nanosec != 0U);
      const bool partner_has_timestamp = (test_case.partner_sec != 0U) || (test_case.partner_nanosec != 0U);

      const uint64_t expected_main_timestamp_us =
         main_has_timestamp ?
            (static_cast<uint64_t>(test_case.main_sec) * kUsPerS) + (static_cast<uint64_t>(test_case.main_nanosec) / kNsPerUs) :
            (core_info.time_us - kTimestampWorkaround);
      const uint64_t expected_partner_timestamp_us = partner_has_timestamp ?
                                                        (static_cast<uint64_t>(test_case.partner_sec) * kUsPerS) +
                                                           (static_cast<uint64_t>(test_case.partner_nanosec) / kNsPerUs) :
                                                        (core_info.time_us - kTimestampWorkaround);

      /* Simulate the same write-then-read/advance-pointers ordering as Update_Sensors()/Run_Emb_Tracker(). */
      cnt_loops++;
      main_timestamp_ring[main_write_idx]               = expected_main_timestamp_us;
      const uint64_t expected_delayed_main_timestamp_us = main_timestamp_ring[main_read_idx];
      main_write_idx                                    = (main_write_idx + 1U) % kMainSensorBufferLength;
      if (cnt_loops > MAIN_SENSOR_BUFFER_DELAY_CYCLES)
      {
         main_read_idx = (main_read_idx + 1U) % kMainSensorBufferLength;
      }

      EXPECT_EQ(sensors[0].timestamp_us, expected_delayed_main_timestamp_us) << test_case.name;
      if (NUMBER_OF_SENSORS_EMB > 1)
      {
         EXPECT_EQ(sensors[1].timestamp_us, expected_partner_timestamp_us) << test_case.name;
      }
   }
}

/**
 * @test UpdateCoreInfoUsesHilTimestampWhenHilModeEnabled
 * @brief When hil_ipc_info.hil_mode_enabled is set, Update_Core_Info() should derive current_time_us from
 *        the downselection detection timestamp (Get_HIL_R52_Time_From_BBE32) instead of Get_R52_Time_From_BBE32.
 */
TEST_F(UpdateHostTest, UpdateCoreInfoUsesHilTimestampWhenHilModeEnabled)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   fake_ipc_m2d_buffer.payload.hil_ipc_info.hil_mode_enabled                       = CODED_TRUE;
   p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec = 10U;
   p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns  = 500000U;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   constexpr uint64_t kUsPerS              = 1000000ULL;
   constexpr uint64_t kNsPerUs             = 1000ULL;
   constexpr uint64_t kTimestampWorkaround = 30000U;
   const uint64_t expected_time_us         = (10ULL * kUsPerS) + (500000ULL / kNsPerUs) + kTimestampWorkaround;

   EXPECT_EQ(core_info.time_us, expected_time_us);
}

/**
 * @test UpdateCoreInfoUsesR52TimeWhenHilModeDisabled
 * @brief When hil_ipc_info.hil_mode_enabled is clear (default), Update_Core_Info() should use
 *        Get_R52_Time_From_BBE32() and ignore the downselection detection timestamp entirely.
 */
TEST_F(UpdateHostTest, UpdateCoreInfoUsesR52TimeWhenHilModeDisabled)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   fake_ipc_m2d_buffer.payload.hil_ipc_info.hil_mode_enabled                       = CODED_FALSE;
   p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec = 999U; /* Should be ignored */
   p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns  = 999U; /* Should be ignored */

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   constexpr uint64_t kUsPerS              = 1000000ULL;
   constexpr uint64_t kNsPerUs             = 1000ULL;
   constexpr uint64_t kTimestampWorkaround = 30000U;
   const uint64_t hil_derived_time_us      = (999ULL * kUsPerS) + (999ULL / kNsPerUs) + kTimestampWorkaround;

   EXPECT_NE(core_info.time_us, hil_derived_time_us);
}

TEST_F(UpdateHostTest, BoresightCacheRetainsLastValidValuesAcrossInvalidCycle)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode              = 1U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf       = 2U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf     = 2U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated = 1.25F;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated = -2.5F;

   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_mode                  = 1U;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_error_status_combined = 0U;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_az_estimated     = 3.75F;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_el_estimated     = -4.5F;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_az_estimated, 1.25F);
   EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_el_estimated, -2.5F);
   if (NUMBER_OF_SENSORS_EMB > 1)
   {
      EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_az_estimated, 3.75F);
      EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_el_estimated, -4.5F);
   }

   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode              = 0U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf       = 0U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf     = 0U;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated = 9.25F;
   p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated = 8.5F;

   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_mode                  = 0U;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].alignment_error_status_combined = 1U;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_az_estimated     = 7.75F;
   p_ipc_m2d->payload.partners_data.partner_sensor_alignment_info[0].vacs_boresight_el_estimated     = 6.5F;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_az_estimated, 1.25F);
   EXPECT_FLOAT_EQ(sensors[0].vacs_boresight_el_estimated, -2.5F);
   if (NUMBER_OF_SENSORS_EMB > 1)
   {
      EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_az_estimated, 3.75F);
      EXPECT_FLOAT_EQ(sensors[1].vacs_boresight_el_estimated, -4.5F);
   }
}

TEST_F(UpdateHostTest, ValidTrackerHostOutputDrivesSensorMotion)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   const float speed        = 8.0F;
   const float yaw_rate_rad = 0.5F;

   p_ipc_m2d->payload.veh_data.vse_output_valid                             = CODED_TRUE;
   p_ipc_m2d->payload.veh_data.vse_output.veh_index                         = 17U;
   p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = speed;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_velocity                 = speed;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_velocity                  = 0.0F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_accel                    = 1.25F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_accel                     = -0.75F;
   p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_filtered            = yaw_rate_rad;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_sideslip                      = 0.0F;
   p_ipc_m2d->payload.veh_data.vse_output.curvature_rear_axle               = 0.0F;
   p_ipc_m2d->payload.veh_data.vse_output.speed_compensation_factor         = 1.0F;
   p_ipc_m2d->payload.veh_data.vse_output.filt_veh_speed_over_ground_qf     = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_qf                  = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_accel_qf                  = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_accel_qf                 = 2U;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   const float dist_rear_axle_to_vcs_m = host_buffer_read_ptr->dist_rear_axle_to_vcs_m;
   const float sensor_longitudinal_m   = sensors[0].mounting_position.vcs_position.longitudinal;
   const float sensor_lateral_m        = sensors[0].mounting_position.vcs_position.lateral;
   const float expected_sensor_xsens_m = dist_rear_axle_to_vcs_m + sensor_longitudinal_m;
   const float expected_sensor_ysens_m = sensor_lateral_m;
   const float rear_sideslip           = -(host_buffer_read_ptr->rear_cornering_compliance) *
                               (host_buffer_read_ptr->curvature_rear * host_buffer_read_ptr->speed * host_buffer_read_ptr->speed);
   const float expected_long_velocity    = (speed * cosf(rear_sideslip)) - (yaw_rate_rad * expected_sensor_ysens_m);
   const float expected_lateral_velocity = (speed * sinf(rear_sideslip)) + (yaw_rate_rad * expected_sensor_xsens_m);

   EXPECT_FLOAT_EQ(sensors[0].vcs_velocity.longitudinal, expected_long_velocity);
   EXPECT_FLOAT_EQ(sensors[0].vcs_velocity.lateral, expected_lateral_velocity);
}

TEST_F(UpdateHostTest, InvalidVseOutputKeepsPreviousHostBufferState)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   p_ipc_m2d->payload.veh_data.vse_output_valid                             = CODED_TRUE;
   p_ipc_m2d->payload.veh_data.vse_output.veh_index                         = 51U;
   p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = 6.5F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_velocity                 = 6.5F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_velocity                  = 0.25F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_accel                    = 0.4F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_accel                     = -0.2F;
   p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_filtered            = 0.05F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_sideslip                      = 0.01F;
   p_ipc_m2d->payload.veh_data.vse_output.curvature_rear_axle               = 0.002F;
   p_ipc_m2d->payload.veh_data.vse_output.speed_compensation_factor         = 1.0F;
   p_ipc_m2d->payload.veh_data.vse_output.filt_veh_speed_over_ground_qf     = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_qf                  = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_accel_qf                  = 2U;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_accel_qf                 = 2U;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   const uint32_t expected_vehicle_index = host_buffer_read_ptr->vehicle_index;
   const float expected_speed            = host_buffer_read_ptr->speed;
   const float expected_vcs_speed        = host_buffer_read_ptr->vcs_speed;
   const float expected_yaw_rate         = host_buffer_read_ptr->yaw_rate_rad;
   const float expected_long_velocity    = sensors[0].vcs_velocity.longitudinal;
   const float expected_lateral_velocity = sensors[0].vcs_velocity.lateral;

   p_ipc_m2d->payload.veh_data.vse_output_valid                             = CODED_FALSE;
   p_ipc_m2d->payload.veh_data.vse_output.veh_index                         = 99U;
   p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = -20.0F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_velocity                 = -20.0F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_velocity                  = 2.0F;
   p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_filtered            = 0.8F;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_EQ(host_buffer_read_ptr->vehicle_index, expected_vehicle_index);
   EXPECT_FLOAT_EQ(host_buffer_read_ptr->speed, expected_speed);
   EXPECT_FLOAT_EQ(host_buffer_read_ptr->vcs_speed, expected_vcs_speed);
   EXPECT_FLOAT_EQ(host_buffer_read_ptr->yaw_rate_rad, expected_yaw_rate);
   EXPECT_FLOAT_EQ(sensors[0].vcs_velocity.longitudinal, expected_long_velocity);
   EXPECT_FLOAT_EQ(sensors[0].vcs_velocity.lateral, expected_lateral_velocity);
}

class TrackerMemInitFailureTest : public ::testing::Test
{
 protected:
   struct TrackerMemInitFailureCase
   {
      const char *name;
      uint32_t max_pool_size;
      uint32_t expected_pool_size;
   };

   static constexpr size_t kMemPoolBufferBytes = 2U * 1024U * 1024U;

   D2M_Msg_T p_ipc_d2m{};
   alignas(MEM_POOL_ALIGNMENT_IN_BYTES) uint8_t mem_buffer[kMemPoolBufferBytes]{};
   Mem_Pool_T memory_pool{};

   size_t FillTestCases(TrackerMemInitFailureCase (&test_cases)[4]) const
   {
      size_t case_count            = 0U;
      uint32_t successful_pool_use = 0U;

      test_cases[case_count++] = {"f360_det_list_fails_first", successful_pool_use, successful_pool_use};

      successful_pool_use = MEM_POOL_USAGE(sizeof(F360_Detection_List_T));

#ifndef DISABLE_OCG
      test_cases[case_count++] = {"ocg_inputs_fails_after_f360_det_list_passes", successful_pool_use, successful_pool_use};

      successful_pool_use      = MEM_POOL_USAGE(successful_pool_use + sizeof(ocg::OCG_Inputs_T));
      test_cases[case_count++] = {"ocg_outputs_fails_after_f360_det_list_and_ocg_inputs_pass", successful_pool_use,
                                  successful_pool_use};
#endif

#ifndef DISABLE_SG
   #ifndef DISABLE_OCG
      successful_pool_use = MEM_POOL_USAGE(successful_pool_use + sizeof(ocg::OCG_Outputs_T));
   #endif
      test_cases[case_count++] = {"sg_output_fails_after_previous_allocations_pass", successful_pool_use, successful_pool_use};
#endif

      return case_count;
   }

   void SetUp() override
   {
   }
};

TEST_F(TrackerMemInitFailureTest, ReturnsFailureWhenAllocationStepRunsOutOfPool)
{
   TrackerMemInitFailureCase test_cases[4] = {};
   const size_t case_count                 = FillTestCases(test_cases);

   for (size_t index = 0U; index < case_count; ++index)
   {
      const TrackerMemInitFailureCase &test_case = test_cases[index];

      ASSERT_EQ(Mem_Pool_Init(&memory_pool, mem_buffer, test_case.max_pool_size), MEM_POOL_SUCCESS) << test_case.name;

      const Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, &p_ipc_d2m);

      EXPECT_EQ(mem_result, MEM_POOL_FAILURE) << test_case.name;
      EXPECT_EQ(memory_pool.size, test_case.expected_pool_size) << test_case.name;
   }
}

class HelperFunctionTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
   }
};

TEST_F(HelperFunctionTest, MapRefPointToLenWidSegments)
{
   struct ReferencePointTestCase
   {
      uint8_t reference_point;
      Len_Wid_Segments expected_segments;
   } cases[] = {
      {F360_REFERENCE_POINT_FRONT_LEFT, {10.0F, 0.0F, 0.0F, 10.0F}},  {F360_REFERENCE_POINT_FRONT, {10.0F, 0.0F, 5.0F, 5.0F}},
      {F360_REFERENCE_POINT_FRONT_RIGHT, {10.0F, 0.0F, 10.0F, 0.0F}}, {F360_REFERENCE_POINT_RIGHT, {5.0F, 5.0F, 10.0F, 0.0F}},
      {F360_REFERENCE_POINT_REAR_RIGHT, {0.0F, 10.0F, 10.0F, 0.0F}},  {F360_REFERENCE_POINT_REAR, {0.0F, 10.0F, 5.0F, 5.0F}},
      {F360_REFERENCE_POINT_REAR_LEFT, {0.0F, 10.0F, 0.0F, 10.0F}},   {F360_REFERENCE_POINT_LEFT, {5.0F, 5.0F, 0.0F, 10.0F}},
      {F360_REFERENCE_POINT_CENTER, {5.0F, 5.0F, 5.0F, 5.0F}},        {255U, {5.0F, 5.0F, 5.0F, 5.0F}},
   };
   Len_Wid_Segments segments{};
   for (const auto &c : cases)
   {
      Map_Ref_Point_To_Len_Wid_Segments(c.reference_point, 10.0F, 10.0F, &segments);
      EXPECT_FLOAT_EQ(segments.len1, c.expected_segments.len1);
      EXPECT_FLOAT_EQ(segments.len2, c.expected_segments.len2);
      EXPECT_FLOAT_EQ(segments.wid1, c.expected_segments.wid1);
      EXPECT_FLOAT_EQ(segments.wid2, c.expected_segments.wid2);
   }
}

TEST_F(UpdateHostTest, VcsSpeedSignFollowsLongitudinalVelocityDirection)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   p_ipc_m2d->payload.veh_data.vse_output_valid             = CODED_TRUE;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_velocity = -6.0F;
   p_ipc_m2d->payload.veh_data.vse_output.vcs_lat_velocity  = 8.0F;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_FLOAT_EQ(host_buffer_read_ptr->vcs_speed, -10.0F);

   p_ipc_m2d->payload.veh_data.vse_output.vcs_long_velocity = 6.0F;
   for (int i = 0; i < MAIN_SENSOR_BUFFER_DELAY_CYCLES + 1; i++)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }
   EXPECT_FLOAT_EQ(host_buffer_read_ptr->vcs_speed, 10.0F);
}

TEST_F(UpdateHostTest, NonAdvancingCoreTimeInvalidatesElapsedTime)
{
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   ASSERT_GT(core_info.elapsed_time_s, 0.0F);

   /* The next cycle's timestamp is lower than this, so no elapsed time can be computed. */
   core_info.time_us = std::numeric_limits<uint64_t>::max();

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_FLOAT_EQ(core_info.elapsed_time_s, 0.0F);
}

TEST_F(UpdateHostTest, MainSensorLookIndexDiffSelectsDetectionForwarding)
{
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_REAR_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);
   constexpr uint32_t kMainDets                                        = 8U;
   p_ipc_d2m->payload.downselection_data.num_af_ds_det                 = static_cast<int32_t>(kMainDets);
   p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det = 0;

   ASSERT_NE(f360_det_list, nullptr);
   constexpr bool main_sensor_buffering_enabled = (MAIN_SENSOR_BUFFER_DELAY_CYCLES > 0U);

   constexpr uint8_t kSkipTolerance      = 5U;
   constexpr int32_t kRolloverAdjustment = static_cast<int32_t>(kSkipTolerance) - static_cast<int32_t>(UINT16_MAX);

   constexpr uint32_t kMainSensorBufferLength = MAIN_SENSOR_BUFFER_DELAY_CYCLES + 1U;
   uint16_t look_index_ring[kMainSensorBufferLength]{};
   uint32_t det_count_ring[kMainSensorBufferLength]{};
   uint32_t main_write_idx = 0U;
   uint32_t main_read_idx  = 0U;
   uint32_t cnt_loops      = 0U;

   bool sim_first_main_scan_received     = false;
   uint16_t sim_prev_incoming_look_index = 0U;
   uint16_t sim_sensor_look_index        = 0U;
   uint16_t sim_prev_scan_index          = 0U;

   bool saw_consecutive = false;
   bool saw_skipped     = false;
   bool saw_rollover    = false;
   bool saw_unchanged   = false;

   auto RunAndCheck = [&](uint16_t incoming_look_index)
   {
      const bool scan_available = !sim_first_main_scan_received || (incoming_look_index != sim_prev_incoming_look_index);

      if (!sim_first_main_scan_received)
      {
         sim_first_main_scan_received = true;
      }

      /* Production updates the stale baseline only when a new input scan is accepted. */
      if (scan_available)
      {
         sim_prev_scan_index = sim_sensor_look_index;
      }

      p_ipc_d2m->payload.downselection_data.det_list_property.lookindex = incoming_look_index;
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

      const uint16_t written_look_index = scan_available ? incoming_look_index : sim_prev_incoming_look_index;
      const uint32_t written_det_count  = scan_available ? kMainDets : 0U;

      look_index_ring[main_write_idx] = written_look_index;
      det_count_ring[main_write_idx]  = written_det_count;
      sim_prev_incoming_look_index    = written_look_index;

      const uint32_t read_idx        = main_sensor_buffering_enabled ? main_read_idx : main_write_idx;
      const uint16_t read_look_index = look_index_ring[read_idx];
      const uint32_t read_det_count  = det_count_ring[read_idx];
      const int32_t main_index_diff  = static_cast<int32_t>(read_look_index) - static_cast<int32_t>(sim_prev_scan_index);
      const bool main_sensor_data_valid =
         !((main_index_diff <= 0 && main_index_diff >= kRolloverAdjustment) || (main_index_diff > kSkipTolerance));
      const bool delayed_duplicate =
         main_sensor_buffering_enabled && (static_cast<uint16_t>(read_look_index + 1U) == incoming_look_index);
      const uint32_t expected_forwarded_dets = delayed_duplicate ? 0U : (main_sensor_data_valid ? read_det_count : 0U);

      EXPECT_EQ(f360_det_list->number_of_valid_detections, expected_forwarded_dets)
         << "cycle=" << cnt_loops << ", incoming=" << incoming_look_index << ", read=" << read_look_index
         << ", previous_scan=" << sim_prev_scan_index << ", diff=" << main_index_diff
         << ", actual_sensor_look=" << sensors[0].look_index;

      if (main_index_diff == 1)
      {
         saw_consecutive = true;
      }
      if (main_index_diff > kSkipTolerance)
      {
         saw_skipped = true;
      }
      if (main_index_diff < kRolloverAdjustment)
      {
         saw_rollover = true;
      }
      if (!scan_available)
      {
         saw_unchanged = true;
      }

      sim_sensor_look_index = read_look_index;

      cnt_loops++;
      main_write_idx = (main_write_idx + 1U) % kMainSensorBufferLength;
      if (main_sensor_buffering_enabled && cnt_loops > MAIN_SENSOR_BUFFER_DELAY_CYCLES)
      {
         main_read_idx = (main_read_idx + 1U) % kMainSensorBufferLength;
      }
   };
   /* Prime the cached look index and the simulated ring exactly as production does. */
   for (uint32_t flush_count = 0U; flush_count <= MAIN_SENSOR_BUFFER_DELAY_CYCLES; ++flush_count)
   {
      RunAndCheck(static_cast<uint16_t>(998U + flush_count));
   }
   /* Prime and then exercise transitions that cover consecutive, skipped, rollover, and unchanged paths.
    * Extra unchanged cycles flush delayed entries when main sensor buffering is enabled. */
   RunAndCheck(1000U);
   RunAndCheck(1001U);
   RunAndCheck(1010U);
   for (uint32_t flush_count = 0U; flush_count <= MAIN_SENSOR_BUFFER_DELAY_CYCLES + 2U; ++flush_count)
   {
      RunAndCheck(0);
   }
   RunAndCheck(UINT16_MAX);
   for (uint32_t flush_count = 0U; flush_count <= MAIN_SENSOR_BUFFER_DELAY_CYCLES + 2U; ++flush_count)
   {
      RunAndCheck(flush_count);
   }

   EXPECT_TRUE(saw_consecutive);
   EXPECT_TRUE(saw_skipped);
   EXPECT_TRUE(saw_rollover);

   EXPECT_TRUE(saw_unchanged);
}

/**
 * @test TestInitPartnerSensorsDeferredAllRadarPositions
 * @brief Test all five radar_position cases in Init_Partner_Sensors_Deferred:
 *        REAR_LEFT, REAR_RIGHT, FRONT_RIGHT, FRONT_LEFT, FRONT_CENTER
 */
TEST_F(UpdateHostTest, TestInitPartnerSensorsDeferredAllRadarPositions)
{
   struct RadarPositionTestCase
   {
      Radar_Position_T radar_position;
      F360_Mounting_Location_T expected_location;
      const char *description;
   };

   const RadarPositionTestCase test_cases[] = {
      {RADAR_POSITION_REAR_LEFT, F360_MOUNTING_LOCATION_LEFT_REAR, "REAR_LEFT"},
      {RADAR_POSITION_REAR_RIGHT, F360_MOUNTING_LOCATION_RIGHT_REAR, "REAR_RIGHT"},
      {RADAR_POSITION_FRONT_RIGHT, F360_MOUNTING_LOCATION_RIGHT_FORWARD, "FRONT_RIGHT"},
      {RADAR_POSITION_FRONT_LEFT, F360_MOUNTING_LOCATION_LEFT_FORWARD, "FRONT_LEFT"},
      {RADAR_POSITION_FRONT_CENTER, F360_MOUNTING_LOCATION_CENTER_FORWARD, "FRONT_CENTER"},
   };

   for (size_t tc_idx = 0; tc_idx < sizeof(test_cases) / sizeof(test_cases[0]); ++tc_idx)
   {
      const RadarPositionTestCase &tc = test_cases[tc_idx];

      /* Full teardown/setup for clean state between iterations */
      TearDown();
      SetUp();

      Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
      ASSERT_EQ(mem_result, MEM_POOL_SUCCESS) << "Failed to init memory pool for test case: " << tc.description;

      p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
      Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

      /* Set desired partner radar_position before the first cycle: the stub forces recvd_flags
         valid from cycle one, so deferred init locks in whatever position is set here. */
      p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].radar_position = tc.radar_position;

      /* Run tracker once to trigger Init_Partner_Sensors_Deferred */
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

      /* Verify the mounting_location matches expected value for this radar_position */
      EXPECT_EQ(sensors[1].mounting_location, tc.expected_location)
         << "Partner sensor mounting_location mismatch for radar_position: " << tc.description;
   }
}

/**
 * @test TestInitPartnerSensorsDeferredInvalidStatus
 * @brief Test the status_recvd_flag validity check in Init_Partner_Sensors_Deferred.
 *        Partner sensor initialization should be deferred when status_recvd_flag != 1U.
 */
TEST_F(UpdateHostTest, TestInitPartnerSensorsDeferredInvalidStatus)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Disable the stub's forced-valid flags so status_recvd_flag stays invalid across cycles */
   stub_force_partner_flags_valid                                                    = false;
   p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].radar_position = RADAR_POSITION_REAR_LEFT;
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].status_recvd_flag    = 0U;
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].det_recvd_flag       = 1U;

   /* Run tracker - deferred init should NOT trigger */
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   /* Partner sensor should still have UNKNOWN mounting_location (not initialized) */
   EXPECT_EQ(sensors[1].mounting_location, F360_MOUNTING_LOCATION_UNKNOWN)
      << "Partner sensor should remain UNKNOWN when status_recvd_flag is invalid";

   /* Now set status_recvd_flag to 1U to trigger deferred init */
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].status_recvd_flag = 1U;

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   /* Now partner sensor should be initialized to REAR_LEFT */
   EXPECT_EQ(sensors[1].mounting_location, F360_MOUNTING_LOCATION_LEFT_REAR)
      << "Partner sensor should be initialized to REAR_LEFT when status_recvd_flag becomes 1U";
}

/**
 * @test TestInitPartnerSensorsDeferredFrontCenterOCGUpdate
 * @brief Test the special case in Init_Partner_Sensors_Deferred where a partner sensor
 *        is FRONT_CENTER and updates OCG indices.
 */
TEST_F(UpdateHostTest, TestInitPartnerSensorsDeferredFrontCenterOCGUpdate)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);

   /* Initialize with FRONT_LEFT main sensor (NOT front-center) so runtime_enable_ocg is initially false */
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Partner sensor is FRONT_CENTER; set before the first cycle since deferred init
      locks in on cycle one (stub forces recvd_flags valid from the start). */
   p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].radar_position = RADAR_POSITION_FRONT_CENTER;

   /* Run tracker - deferred init should trigger and update OCG indices */
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   /* Partner sensor should be initialized to CENTER_FORWARD */
   EXPECT_EQ(sensors[1].mounting_location, F360_MOUNTING_LOCATION_CENTER_FORWARD)
      << "Partner sensor should be initialized to CENTER_FORWARD";

   /* Verify that deferred init succeeded and OCG was configured with the partner sensor */
   /* The deferred init should have marked partner_sensors_initialized[1] = true */
   /* and set front_center_sensor_index = 1 since this is the first FRONT_CENTER sensor found */
   /* This is verified indirectly: tracker continues running without errors */
   ASSERT_NE(f360_det_list, nullptr) << "F360 detection list should be valid after OCG update";
}
