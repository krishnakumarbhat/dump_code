/**
 * @file emb_tracker_wrapper_test.cpp
 *
 * Unit tests for embedded tracker wrapper with stub code enabled.
 */
#include "emb_tracker_internal.h"
#include "emb_tracker_project_parameters.h"
#include "emb_tracker_stubs.h"
#include "emb_tracker_wrapper.h"
#include "f360_detection_list.h"
#include "ipc_data.h"
#include "mem_pool.h"
#include <gtest/gtest.h>
#include <limits>

extern volatile uint8_t Simulation_Test_Case;
extern volatile Stub_Env_Mode_T stub_env_mode;

/*bazelisk test //software/bbe32/emb_tracker/test:unit_tests_with_stub --tracker_variant=AL -c dbg*/
/*bazelisk test //software/bbe32/emb_tracker/test:unit_tests_stub --tracker_variant=platform_srr8p_standalone -c dbg --jobs=auto*/
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

class EmbTrackerWrapperTest : public ::testing::Test
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
      /*Allocate zero-initialized IPC message buffers (stub geometry reads calib data before it is written)*/
      p_ipc_d2m          = static_cast<D2M_Msg_T *>(calloc(1U, sizeof(D2M_Msg_T)));
      p_ipc_m2d          = static_cast<M2D_Msg_T *>(calloc(1U, sizeof(M2D_Msg_T)));
      p_ipc_m2d_one_time = static_cast<volatile M2D_One_Time_Msg_T *>(calloc(1U, sizeof(M2D_One_Time_Msg_T)));
      ASSERT_NE(p_ipc_d2m, nullptr);
      ASSERT_NE(p_ipc_m2d, nullptr);
      ASSERT_NE(p_ipc_m2d_one_time, nullptr);

      /*Allocate and initialize memory pool (stub code will populate IPC data)*/
      EXPECT_EQ(Mem_Pool_Init(&memory_pool, mem_buffer, kMemPoolBufferBytes), MEM_POOL_SUCCESS);
   }

   void TearDown() override
   {
      Simulation_Test_Case                                      = DEFAULT_TRACKER_TEST_CASE;
      stub_env_mode                                             = STUB_ENV_BSIS_AL;
      stub_force_partner_flags_valid                            = true;
      fake_ipc_m2d_buffer.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;

      free(p_ipc_d2m);
      free(p_ipc_m2d);
      free(const_cast<M2D_One_Time_Msg_T *>(p_ipc_m2d_one_time));
   }
};

/**
 * @test TestTrackerInitAndFirstRun
 * @brief Test tracker initialization an
 */
TEST_F(EmbTrackerWrapperTest, TestTrackerInit)
{
   /* Normal success path — pool is properly initialized in SetUp() */
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   EXPECT_EQ(mem_result, MEM_POOL_SUCCESS);
}

/**
 * @test TestTrackerThreeCyclesAndF360Detections
 * @brief Test 3 tracker cycles and verify F360 detections match stub-generated data
 *
 * Stub code fills af_ds_data detections in D2M IPC payload.
 * Tracker processes these and populates F360 detection list.
 * Verify counts match based on number of sensors enabled.
 */
TEST_F(EmbTrackerWrapperTest, TestTrackerThreeCyclesAndF360Detections)
{
   /* Initialize memory pool */
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   EXPECT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT; /* overwriting Al mode condtion in init_sensors */
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Run tracker 3 times */
   const uint8_t NUM_CYCLES             = 3;
   constexpr uint32_t kMainBufferLength = MAIN_SENSOR_BUFFER_DELAY_CYCLES + 1U;
   uint32_t main_dets_ring[kMainBufferLength]{};
   uint32_t main_write_index = 0U;
   uint32_t main_read_index  = 0U;

   for (uint8_t cycle = 0; cycle < NUM_CYCLES; ++cycle)
   {
      /* Run tracker cycle - stubs populate detections, then F360 processes them */
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

      /* Read stub-filled detection count AFTER run (stubs write during Run_Emb_Tracker) */
      uint32_t stub_af_ds_dets = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
      stub_af_ds_dets += p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;

      /* F360 detection list should be populated by wrapper from stub data */
      ASSERT_NE(f360_det_list, nullptr) << "F360 detection list must be allocated";

      /* Main sensor detections: should match or be within max bounds */
      uint32_t f360_main_dets          = f360_det_list->number_of_valid_detections;
      const uint32_t current_main_dets = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
      main_dets_ring[main_write_index] = current_main_dets;
      const uint32_t delayed_main_dets = main_dets_ring[main_read_index];
      const uint32_t partner_dets      = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
#if defined(AL_TRACKER)
      const uint32_t expected_f360_dets = (delayed_main_dets + partner_dets) / 2U;
#else
      const uint32_t expected_f360_dets = delayed_main_dets + partner_dets;
#endif

      /* Stubs must have populated detections (skip cycle 0, stub logic only emits after first loop) */
      if (cycle > 0)
      {
         EXPECT_GT(stub_af_ds_dets, 0U) << "Stub should populate af_ds detections at cycle " << cycle;
      }
#if defined(AL_TRACKER)
      /* F360 must have produced detections matching stub input */
      EXPECT_EQ(stub_af_ds_dets / 2U, f360_main_dets)
#else
      EXPECT_EQ(stub_af_ds_dets, f360_main_dets)
#endif
         << "F360 main detections should match stub-filled af_ds_dets at cycle " << cycle;
      EXPECT_LE(f360_main_dets, MAX_NUMBER_OF_DETECTIONS)
         << "F360 main detections must not exceed MAX_NUMBER_OF_DETECTIONS at cycle " << cycle;

      EXPECT_LE(partner_dets, NUMBER_OF_PARTNER_DETECTIONS_EMB)
         << "Partner detections must not exceed NUMBER_OF_PARTNER_DETECTIONS_EMB at cycle " << cycle;

      main_write_index = (main_write_index + 1U) % kMainBufferLength;
      if (cycle + 1U > MAIN_SENSOR_BUFFER_DELAY_CYCLES)
      {
         main_read_index = (main_read_index + 1U) % kMainBufferLength;
      }

      /* Total detections across sensors should be reasonable */
      EXPECT_LE(f360_main_dets, MAX_NUMBER_OF_DETECTIONS)
         << "Total detections should not exceed platform limits at cycle " << cycle;
   }

   /* No null pointers throughout execution */
   ASSERT_NE(p_ipc_d2m, nullptr);
   ASSERT_NE(p_ipc_m2d, nullptr);
}

/**
 * @test TestPartnerIndexDiffBranchCoverage
 * @brief Exercise stale, rollover-adjusted, skip-tolerance, and normal partner-index paths.
 */
TEST_F(EmbTrackerWrapperTest, TestPartnerIndexDiffBranchCoverage)
{
   if (NUMBER_OF_SENSORS_EMB < 2)
   {
      return;
   }
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   uint32_t main_dets    = 0U;
   uint32_t partner_dets = 0U;
   uint32_t f360_dets    = 0U;

   /* Warm up until partner stubs are active. */
   for (uint8_t i = 0; i < 2; ++i)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }

   /* Force rollover-adjusted path: diff = current - UINT16_MAX (large negative), so condition must be false. */
   sensors[1].look_index = UINT16_MAX;
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   ASSERT_NE(f360_det_list, nullptr);
   f360_dets = f360_det_list->number_of_valid_detections;
   ASSERT_GT(partner_dets, 0U);
   EXPECT_EQ(f360_dets, main_dets / 2U);

   /* Force stale path: set previous to next expected current so diff becomes 0 and condition is true. */
   const uint16_t last_look_index = sensors[1].look_index;
   sensors[1].look_index          = static_cast<uint16_t>(last_look_index + 1U);
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   ASSERT_NE(f360_det_list, nullptr);
   f360_dets = f360_det_list->number_of_valid_detections;
   ASSERT_GT(partner_dets, 0U);
   EXPECT_EQ(f360_dets, main_dets / 2U);

   /* Normal path: leave previous as current so diff is +1 and condition is false. */
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   ASSERT_NE(f360_det_list, nullptr);
   f360_dets = f360_det_list->number_of_valid_detections;
   ASSERT_GT(partner_dets, 0U);
   EXPECT_EQ(f360_dets, (main_dets + partner_dets) / 2U);

   /* Force skip-tolerance path: 8 cycles are enough to move past 6 from normal start values.
      Keep a hard upper bound so the test fails fast instead of hanging if look_index stops advancing. */
   for (uint32_t guard = 0U; (guard < 8U) && (sensors[1].look_index <= 6U); ++guard)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }
   ASSERT_GT(sensors[1].look_index, 6U);
   sensors[1].look_index = 0U;
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   ASSERT_NE(f360_det_list, nullptr);
   f360_dets = f360_det_list->number_of_valid_detections;
   ASSERT_GT(partner_dets, 0U);
   EXPECT_EQ(f360_dets, main_dets / 2U);
}

/**
 * @test TestMainIndexDiffSkipsMainSensorDetections
 * @brief Force the stale-main path so only partner detections are forwarded to F360.
 */
TEST_F(EmbTrackerWrapperTest, TestMainIndexDiffSkipsMainSensorDetections)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   for (uint8_t i = 0; i < 2; ++i)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   const uint32_t baseline_main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   const uint32_t baseline_partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   ASSERT_NE(f360_det_list, nullptr);
   const uint32_t baseline_f360_dets = f360_det_list->number_of_valid_detections;

   ASSERT_GT(baseline_main_dets, 0U);
   if (NUMBER_OF_SENSORS_EMB > 1)
   {
      ASSERT_GT(baseline_partner_dets, 0U);
   }
#if defined(AL_TRACKER)
   EXPECT_EQ(baseline_f360_dets, (baseline_main_dets + baseline_partner_dets) / 2U);
#else
   EXPECT_EQ(baseline_f360_dets, (baseline_main_dets + baseline_partner_dets));
#endif

   const uint16_t last_main_look_index = sensors[0].look_index;
   sensors[0].look_index               = static_cast<uint16_t>(last_main_look_index + 1U);

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   const uint32_t stale_main_dets    = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   const uint32_t stale_partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   const uint32_t stale_f360_dets    = f360_det_list->number_of_valid_detections;

   ASSERT_GT(stale_main_dets, 0U);
   if (NUMBER_OF_SENSORS_EMB > 1)
   {
      ASSERT_GT(stale_partner_dets, 0U);
      EXPECT_EQ(stale_f360_dets, stale_partner_dets / 2U);
   }
   EXPECT_LT(stale_f360_dets, baseline_f360_dets);
}

/**
 * @test TestAlFrontCenterSpecialCaseIgnoresPartnerSensor
 * @brief Cover the AL front-center init special case where only the main sensor is updated.
 */
TEST_F(EmbTrackerWrapperTest, TestAlFrontCenterSpecialCaseIgnoresPartnerSensor)
{
   if (NUMBER_OF_SENSORS_EMB < 2)
   {
      return;
   }
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);

   /* Init_Emb_Tracker repopulates stub radar positions internally, so switch the stub
      environment to the front-center AL setup before initialization. */
   stub_env_mode = STUB_ENV_MOIS_AL;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   for (uint8_t i = 0; i < 3; ++i)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }

   const uint32_t main_dets              = p_ipc_d2m->payload.downselection_data.num_af_ds_det;
   const uint16_t partner_ipc_look_index = p_ipc_m2d->payload.partners_data.partner_det_list_property_data[0].look_index;

   ASSERT_NE(f360_det_list, nullptr);
   ASSERT_GT(main_dets, 0U);
   EXPECT_EQ(f360_det_list->number_of_valid_detections, main_dets);
   EXPECT_GT(partner_ipc_look_index, 0U);
   EXPECT_EQ(sensors[1].look_index, 0U);
   EXPECT_EQ(sensors[1].number_of_valid_detections, 0U);
}

/**
 * @test TestHostBufferDelayBranchNotTakenOnCounterRollover
 * @brief Force cnt_loops rollover so (cnt_loops > HOST_BUFFER_DELAY_CYCLES) evaluates false.
 */
TEST_F(EmbTrackerWrapperTest, TestHostBufferDelayBranchNotTakenOnCounterRollover)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Update_Core_Info() increments cnt_loops at the start of Run_Emb_Tracker.
      Set to max so next increment wraps to 0 and the host-buffer delay condition is false. */
   core_info.cnt_loops = std::numeric_limits<uint32_t>::max();

   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   EXPECT_EQ(core_info.cnt_loops, 0U);
}

/**
 * @test TestUpdateCoreInfoUsesHilTimestampWhenHilModeEnabled
 * @brief When hil_ipc_info.hil_mode_enabled is set, Update_Core_Info() should derive current_time_us from
 *        the downselection detection timestamp (Get_HIL_R52_Time_From_BBE32) instead of Get_R52_Time_From_BBE32.
 */
TEST_F(EmbTrackerWrapperTest, TestUpdateCoreInfoUsesHilTimestampWhenHilModeEnabled)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
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
 * @test TestUpdateCoreInfoUsesR52TimeWhenHilModeDisabled
 * @brief When hil_ipc_info.hil_mode_enabled is clear (default), Update_Core_Info() should use
 *        Get_R52_Time_From_BBE32() and ignore the downselection detection timestamp entirely.
 */
TEST_F(EmbTrackerWrapperTest, TestUpdateCoreInfoUsesR52TimeWhenHilModeDisabled)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
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

/**
 * @test TestPartnerSensorValidityCheckInvalidFlags
 * @brief Exercise the false branch of Update_Sensors validity check by clearing recvd_flags.
 *        Partner sensor detections should be skipped when data is invalid.
 */
TEST_F(EmbTrackerWrapperTest, TestPartnerSensorValidityCheckInvalidFlags)
{
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_FRONT_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Warm up to get past initial cycles */
   for (uint8_t i = 0; i < 2; ++i)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }

   /* Capture baseline with valid flags (stub sets both to 1U) */
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   const uint32_t baseline_partner_dets = p_ipc_m2d->payload.partners_data.partner_sensor_det_data.num_af_det;
   EXPECT_GT(baseline_partner_dets, 0U) << "Partner detections should be populated with valid flags";
   EXPECT_GT(sensors[1].number_of_valid_detections, 0U) << "Partner sensor should have detections with valid flags";

   /* Stop the stub from forcing valid flags each cycle, then invalidate them */
   stub_force_partner_flags_valid                                                 = false;
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].status_recvd_flag = 0U;
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].det_recvd_flag    = 0U;

   /* Run tracker - the validity check will see invalid flags and zero detections */
   Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);

   /* Partner sensor should have zero detections due to invalid data */
   EXPECT_EQ(sensors[1].number_of_valid_detections, 0U) << "Partner sensor detections should be zero when recvd_flags are invalid";
}

/**
 * @test TestRunOCGEarlyReturnWhenDisabled
 * @brief Test the early return in Run_OCG when runtime_enable_ocg is false.
 */
TEST_F(EmbTrackerWrapperTest, TestRunOCGEarlyReturnWhenDisabled)
{
#ifndef DISABLE_OCG
   Memory_Pool_Return_T mem_result = Emb_Tracker_Mem_Init(&memory_pool, p_ipc_d2m);
   ASSERT_EQ(mem_result, MEM_POOL_SUCCESS);

   /* Initialize with non-front-center main sensor and no partner sensors */
   p_ipc_m2d_one_time->radar_position = RADAR_POSITION_REAR_LEFT;
   Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Ensure no partner sensor is marked as front-center (partner recvd_flags are 0 from stub) */
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].status_recvd_flag = 0U;
   p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[0].det_recvd_flag    = 0U;

   /* Run tracker - should execute without crashing even though OCG is disabled via early return */
   for (uint8_t i = 0; i < 3; ++i)
   {
      Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
   }

   /* Verify tracker ran successfully */
   ASSERT_NE(f360_det_list, nullptr);
#else
   GTEST_SKIP() << "Test only applicable when OCG is enabled (DISABLE_OCG not defined)";
#endif
}
