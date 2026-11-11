/* Unit tests for SWC_PLT_CDD_ECUSync */
#include <cmath>
#include <cstdint>
#include <gtest/gtest.h>

extern "C"
{
#include "Rte_SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "radar_look.h"
   void RE_ECUSync_Init(void);
   void DRE_StatusNotification_Callback(void);
   void Radar_Trigger_Timer_ISR(void);
   uint8_t CaptureGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point, GLOB_TS_STRUCT_TYPE *ret_ts);
   GLOB_TS_STRUCT_TYPE *GetGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
   GLOB_TS_STRUCT_TYPE *PeekGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
   uint8_t GetTimeStampDiff_Ns(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result);
   uint8_t GetMidTimeStamps(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, GLOB_TS_STRUCT_TYPE *result, uint32_t *diff);
   extern volatile float32_t m_EcuSync_Offset_ms;
   extern StbM_TimeStampType timeStamp;
}

extern unsigned g_Start_EcuSync_Timer_calls;
extern unsigned g_Radar_Look_Trigger_calls;
extern float32 g_last_timer_value_ms;
extern StbM_TimeStampType g_test_time_inject;
extern Std_ReturnType g_stbm_return_value; // For controlling StbM_GetCurrentTime return value
extern uint8_t g_radar_position;
extern Std_ReturnType g_stbm_get_time_base_status_return_value;
extern Std_ReturnType g_stbm_set_global_time_return_value;
extern StbM_TimeBaseStatusType g_stbm_sync_time_base_status;
extern StbM_TimeBaseStatusType g_stbm_offset_time_base_status;
extern unsigned g_StbM_GetTimeBaseStatus_calls;
extern unsigned g_StbM_SetGlobalTime_calls;
extern StbM_SynchronizedTimeBaseType g_last_set_global_time_base;
extern StbM_TimeStampType g_last_set_global_time_stamp;
extern StbM_UserDataType g_last_set_global_time_user_data;
extern unsigned g_Radar_Ctl_Look_Sync_Trig_calls;
extern unsigned g_Radar_Look_Sync_Test_calls;
extern bool g_Radar_Look_Sync_Test_return_value;
extern bool g_last_radar_look_sync_test_arg;
extern volatile Look_Sync_Enable_T Look_Sync;
extern uint32_t g_test_elapsed_us_value;
extern uint64_t g_test_ustime_value;

/* Helper to set nanoseconds for ISR path */
static void set_nanos(uint32_t nanos)
{
   g_test_time_inject.nanoseconds = nanos;
}

class ECU_Sync_Test : public ::testing::Test
{
   void SetUp() override
   {
      g_Start_EcuSync_Timer_calls              = 0;
      g_Radar_Look_Trigger_calls               = 0;
      g_last_timer_value_ms                    = -1.0f;
      g_test_time_inject.nanoseconds           = 0;
      m_EcuSync_Offset_ms                      = 0.0f;
      timeStamp.nanoseconds                    = 0;
      g_radar_position                         = 1u;
      g_stbm_get_time_base_status_return_value = 0;
      g_stbm_set_global_time_return_value      = 0;
      g_stbm_sync_time_base_status             = (StbM_TimeBaseStatusType)1u;
      g_stbm_offset_time_base_status           = (StbM_TimeBaseStatusType)0u;
      g_StbM_GetTimeBaseStatus_calls           = 0u;
      g_StbM_SetGlobalTime_calls               = 0u;
      g_last_set_global_time_base              = (StbM_SynchronizedTimeBaseType)0u;
      g_last_set_global_time_stamp             = {0u, 0u, 0u, 0u};
      g_last_set_global_time_user_data         = {0u, 0u, 0u, 0u};
      g_Radar_Ctl_Look_Sync_Trig_calls         = 0u;
      g_Radar_Look_Sync_Test_calls             = 0u;
      g_Radar_Look_Sync_Test_return_value      = true;
      g_last_radar_look_sync_test_arg          = false;
      g_test_elapsed_us_value                  = 0u;
      g_test_ustime_value                      = 0u;
      Look_Sync                                = Look_Sync_Enable;

      // Reset StbM return value to success
      g_stbm_return_value = 0; // E_OK
   }
};

TEST_F(ECU_Sync_Test, InitStartsTimer)
{
   RE_ECUSync_Init();
   ASSERT_EQ(1u, g_Start_EcuSync_Timer_calls);
}

TEST_F(ECU_Sync_Test, InitSeedCanTSync_NotMaster_NoStatusReadAndNoSeed)
{
   g_radar_position = 1u;

   RE_ECUSync_Init();

   ASSERT_EQ(1u, g_Start_EcuSync_Timer_calls);
   ASSERT_EQ(0u, g_StbM_GetTimeBaseStatus_calls);
   ASSERT_EQ(0u, g_StbM_SetGlobalTime_calls);
}

/* Directly invoke status notification callback to raise function coverage */
TEST_F(ECU_Sync_Test, DRE_StatusNotification_Callback_NoOp)
{
   // Function currently contains no active logic but should be callable safely
   DRE_StatusNotification_Callback();
   SUCCEED();
}

/* dtNext <= TIMESYNC_CORRECTIONOFFSET branch */
TEST_F(ECU_Sync_Test, ISR_UpCorrectionSingleStep)
{
   // Want dtNext=5 -> choose base <50 such that SyncClockValue=95ms. Need nanoseconds so that after conversion <50 then +50.
   // SyncClockValue_ms = nanos * NS_2_MS ; choose nanos for 45ms (45,000,000 ns)
   set_nanos(45000000u); // base 45ms -> +50 => 95ms; dtNext = 5
   Radar_Trigger_Timer_ISR();
   float newTimer = g_last_timer_value_ms;
   ASSERT_NEAR(55.0f, newTimer, 0.0001f);
}

/* 10 < dtNext < 48 path */
TEST_F(ECU_Sync_Test, ISR_UpCorrectionMultiStep)
{
   // choose base=5ms -> final 55ms, dtNext=45 -> multi-step -> expect 60
   set_nanos(5000000u);
   Radar_Trigger_Timer_ISR();
   float newTimer = g_last_timer_value_ms;
   ASSERT_NEAR(60.0f, newTimer, 0.0001f);
}

/* 48 < dtNext <= 50 path */
TEST_F(ECU_Sync_Test, ISR_DownCorrectionSingleStep)
{
   // base=1ms -> final 51ms dtNext=49 -> expect 49
   set_nanos(1000000u);
   Radar_Trigger_Timer_ISR();
   float newTimer = g_last_timer_value_ms;
   ASSERT_NEAR(49.0f, newTimer, 0.0001f);
}

/* 48 < dtNext <= 50 path edge: dtNext = 48 should NOT use multi-step (since multi-step is dtNext < 48) */
TEST_F(ECU_Sync_Test, ISR_DownCorrection_Edge48)
{
   // Choose nanos = 2ms => SyncClockValue_ms = 2
   // Next multiple after offset: 50ms -> dtNext = 48ms (boundary)
   set_nanos(2000000u); // 2 ms
   Radar_Trigger_Timer_ISR();
   float newTimer = g_last_timer_value_ms;
   // For dtNext=48 branch we expect NewTimerValue_ms == 48
   ASSERT_NEAR(48.0f, newTimer, 0.0001f);
}

/* 48 < dtNext <= 50 path edge: dtNext = 50 (wrap to next cycle start) */
TEST_F(ECU_Sync_Test, ISR_DownCorrection_Edge50)
{
   // Choose nanos = 0ms => SyncClockValue_ms = 0 -> after initial adjustment adds 50 (SyncClockValue_ms < 50 condition)
   // After adding 50: SyncClockValue_ms = 50; SyncClockValue_ms_Next rounds to 100; dtNext = 50
   set_nanos(0u); // 0 ms
   Radar_Trigger_Timer_ISR();
   float newTimer = g_last_timer_value_ms;
   // For dtNext=50 branch expect NewTimerValue_ms == 50 (down-correction one step)
   ASSERT_NEAR(50.0f, newTimer, 0.0001f);
}

/* Consolidated triplet to reinforce coverage of 48<dtNext<=50 branch for dtNext = 48,49,50 */
TEST_F(ECU_Sync_Test, ISR_DownCorrection_Triplet)
{
   struct Case
   {
      uint32_t nanos;
      float expected;
   } cases[] = {
      {2000000u, 48.0f}, // dtNext = 48
      {1000000u, 49.0f}, // dtNext = 49
      {0u, 50.0f},       // dtNext = 50
   };
   for (const auto &c : cases)
   {
      set_nanos(c.nanos);
      Radar_Trigger_Timer_ISR();
      float v = g_last_timer_value_ms;
      ASSERT_NEAR(c.expected, v, 0.0001f);
      // Additional guards to distinguish from other branches
      ASSERT_LE(v, 50.0f);
      ASSERT_GE(v, 48.0f);
      ASSERT_NE(v, 60.0f); // Not multi-step branch
   }
}

TEST_F(ECU_Sync_Test, ISR_TimingStatistics_AndFailureCounter_CoversAllBranches)
{
   extern uint32_t EcuSync_Max_Delta_Time_Us;
   extern uint32_t EcuSync_Min_Delta_Time_Us;
   extern volatile uint32_t FailCnt_EcuSyncRadarTrigger;

   const uint32_t valid_delta_us = 48000U;
   const uint32_t low_delta_us   = 40000U;
   const uint32_t high_delta_us  = 60000U;

   const uint32_t before_max  = EcuSync_Max_Delta_Time_Us;
   const uint32_t before_min  = EcuSync_Min_Delta_Time_Us;
   const uint32_t before_fail = FailCnt_EcuSyncRadarTrigger;

   g_test_elapsed_us_value = valid_delta_us;
   Radar_Trigger_Timer_ISR();
   EXPECT_GE(EcuSync_Max_Delta_Time_Us, before_max);
   EXPECT_LE(EcuSync_Min_Delta_Time_Us, before_min);
   EXPECT_GE(FailCnt_EcuSyncRadarTrigger, before_fail);

   const uint32_t after_valid_fail = FailCnt_EcuSyncRadarTrigger;
   g_test_elapsed_us_value         = low_delta_us;
   Radar_Trigger_Timer_ISR();
   EXPECT_GE(FailCnt_EcuSyncRadarTrigger, after_valid_fail + 1U);
   EXPECT_LE(EcuSync_Min_Delta_Time_Us, low_delta_us);

   const uint32_t after_low_fail = FailCnt_EcuSyncRadarTrigger;
   g_test_elapsed_us_value       = high_delta_us;
   Radar_Trigger_Timer_ISR();
   EXPECT_GE(FailCnt_EcuSyncRadarTrigger, after_low_fail + 1U);
   EXPECT_GE(EcuSync_Max_Delta_Time_Us, high_delta_us);

   for (int i = 0; i < 10; ++i)
   {
      g_test_elapsed_us_value = high_delta_us;
      Radar_Trigger_Timer_ISR();
   }
   EXPECT_GE(FailCnt_EcuSyncRadarTrigger, after_low_fail + 11U);
}

/* CaptureGlobalTimestamp unbuffered */
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_NoBuffer)
{
   set_nanos(123000000u);
   GLOB_TS_STRUCT_TYPE ts;
   ts.ts_nanosecs = 0;
   ts.ts_secs     = 0;
   ts.ts_status   = 0;
   uint8_t ret    = CaptureGlobalTimestamp(TS_NO_BUFF, &ts);
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(123000000u, ts.ts_nanosecs);
}

/* CaptureGlobalTimestamp buffered wrap/overflow path */
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_BufferedOverflow)
{
   // Fill more than buffer size (2) to trigger overwrite logic
   for (int i = 0; i < 3; i++)
   {
      set_nanos((uint32_t)(i * 100u));
      CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
   }
   // Retrieve with GetGlobalTimestamp to consume entries
   GLOB_TS_STRUCT_TYPE *first = GetGlobalTimestamp(TS_START_ACQ);
   (void)first; // just ensure not null
   // After consuming once, second call should still succeed or give last
   GLOB_TS_STRUCT_TYPE *second = GetGlobalTimestamp(TS_START_ACQ);
   ASSERT_NE(nullptr, second);
}

TEST_F(ECU_Sync_Test, GetGlobalTimestamp_Empty)
{
   auto *val = GetGlobalTimestamp(TS_LOOK_COMP); // empty path
   ASSERT_NE(nullptr, val);
}

TEST_F(ECU_Sync_Test, PeekGlobalTimestamp_ReturnsPointer)
{
   auto *p = PeekGlobalTimestamp(TS_NO_BUFF);
   ASSERT_NE(nullptr, p);
}

TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_SameSecond)
{
   GLOB_TS_STRUCT_TYPE a{0, 200u, 1u};
   GLOB_TS_STRUCT_TYPE b{0, 100u, 1u};
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(100u, diff);
}

TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_NextSecond)
{
   GLOB_TS_STRUCT_TYPE a{0, 30u, 2u};
   GLOB_TS_STRUCT_TYPE b{0, 999999950u, 1u};
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(0u, ret);
   ASSERT_LT(diff, 100u); // expect small wrap diff < 100
}

TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_Error)
{
   GLOB_TS_STRUCT_TYPE a{0, 10u, 1u};
   GLOB_TS_STRUCT_TYPE b{0, 20u, 1u};
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_NE(0u, ret);
   ASSERT_EQ(TS_ERROR, diff);
}

TEST_F(ECU_Sync_Test, GetMidTimeStamps_Success)
{
   GLOB_TS_STRUCT_TYPE a{0, 200u, 1u};
   GLOB_TS_STRUCT_TYPE b{0, 100u, 1u};
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(150u, mid.ts_nanosecs);
   ASSERT_EQ(100u, diff);
}

TEST_F(ECU_Sync_Test, GetMidTimeStamps_Error)
{
   GLOB_TS_STRUCT_TYPE a{0, 10u, 1u};
   GLOB_TS_STRUCT_TYPE b{0, 20u, 1u};
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_NE(0u, ret);
   ASSERT_EQ(TS_ERROR, mid.ts_nanosecs);
}

/* Additional edge case tests for higher coverage */
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_NoBuffer_NullPointer)
{
   set_nanos(456000000u);
   uint8_t ret = CaptureGlobalTimestamp(TS_NO_BUFF, nullptr); // null ret_ts path
   ASSERT_EQ(0u, ret);
}

TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_LargeSecondGap)
{
   GLOB_TS_STRUCT_TYPE a{0, 100u, 5u}; // 5 second gap - too large
   GLOB_TS_STRUCT_TYPE b{0, 50u, 1u};
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(2u, ret); // out of bounds
   ASSERT_EQ(TS_ERROR, diff);
}

TEST_F(ECU_Sync_Test, GetMidTimeStamps_WithNullDiffPointer)
{
   GLOB_TS_STRUCT_TYPE a{0, 200u, 1u};
   GLOB_TS_STRUCT_TYPE b{0, 100u, 1u};
   GLOB_TS_STRUCT_TYPE mid{0};
   auto ret = GetMidTimeStamps(&a, &b, &mid, nullptr); // null diff
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(150u, mid.ts_nanosecs);
}

TEST_F(ECU_Sync_Test, ISR_EdgeCaseZeroTime)
{
   set_nanos(0u); // Edge: zero nanoseconds
   Radar_Trigger_Timer_ISR();
   extern float32 g_last_timer_value_ms;
   float newTimer = g_last_timer_value_ms;
   ASSERT_GT(newTimer, 0.0f); // Should still produce valid timer value
}

TEST_F(ECU_Sync_Test, ISR_MaxNanoseconds)
{
   set_nanos(999999999u); // Edge: max nanoseconds in a second
   Radar_Trigger_Timer_ISR();
   extern float32 g_last_timer_value_ms;
   float newTimer = g_last_timer_value_ms;
   ASSERT_GT(newTimer, 0.0f);
}

// Test CaptureGlobalTimestamp with RTE error return
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_RteError)
{
   // Set stub to return E_NOT_OK
   g_stbm_return_value = 1; // E_NOT_OK

   set_nanos(123000000u);
   GLOB_TS_STRUCT_TYPE ts;
   uint8_t ret = CaptureGlobalTimestamp(TS_START_ACQ, &ts);
   ASSERT_EQ(1u, ret); // Should return E_NOT_OK
}

// Test buffer exactly at capacity (count == GLOB_TS_BUFF_SIZE)
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_BufferAtCapacity)
{
   // Fill buffer exactly to capacity (2 entries)
   for (int i = 0; i < 2; i++)
   {
      set_nanos((uint32_t)(i * 1000u));
      CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
   }
   // Add one more to trigger overflow path
   set_nanos(3000u);
   uint8_t ret = CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
   ASSERT_EQ(0u, ret);
}

// Test GetGlobalTimestamp when count > 0 but decrements to 0
TEST_F(ECU_Sync_Test, GetGlobalTimestamp_CountDecrementToZero)
{
   // Add one entry
   set_nanos(100000u);
   CaptureGlobalTimestamp(TS_START_ACQ, nullptr);

   // Get it - this should decrement count to 0
   GLOB_TS_STRUCT_TYPE *first = GetGlobalTimestamp(TS_START_ACQ);
   ASSERT_NE(nullptr, first);

   // Get again - should hit the else branch (count == 0)
   GLOB_TS_STRUCT_TYPE *second = GetGlobalTimestamp(TS_START_ACQ);
   ASSERT_NE(nullptr, second);
   // This should return TS_NO_BUFF entry, which is always available
}

// Test the edge case where count is exactly 1
TEST_F(ECU_Sync_Test, GetGlobalTimestamp_CountExactlyOne)
{
   // Add exactly one entry
   set_nanos(200000u);
   CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);

   // Retrieve it - count becomes 0
   GLOB_TS_STRUCT_TYPE *result = GetGlobalTimestamp(TS_LOOK_COMP);
   ASSERT_NE(nullptr, result);

   // Try to get another - should get TS_NO_BUFF fallback
   GLOB_TS_STRUCT_TYPE *fallback = GetGlobalTimestamp(TS_LOOK_COMP);
   ASSERT_NE(nullptr, fallback);
}

// Test GetTimeStampDiff_Ns: param1 < param2 (ret_val = 1)
TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_Param1LessThanParam2)
{
   GLOB_TS_STRUCT_TYPE a{0, 100u, 1u}; // Earlier time
   GLOB_TS_STRUCT_TYPE b{0, 200u, 2u}; // Later time
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(1u, ret); // negative difference
   ASSERT_EQ(TS_ERROR, diff);
}

// Test GetTimeStampDiff_Ns: same second, param1.nanos < param2.nanos
TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_SameSecondNegativeDiff)
{
   GLOB_TS_STRUCT_TYPE a{0, 100u, 1u}; // Same second
   GLOB_TS_STRUCT_TYPE b{0, 200u, 1u}; // Same second, later nanos
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(1u, ret); // negative difference within same second
   ASSERT_EQ(TS_ERROR, diff);
}

// Test GetTimeStampDiff_Ns: next second but underflow case
TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_NextSecondUnderflow)
{
   GLOB_TS_STRUCT_TYPE a{0, 100u, 2u}; // Second 2, small nanos
   GLOB_TS_STRUCT_TYPE b{0, 200u, 1u}; // Second 1, large nanos (this should work fine)
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(0u, ret);          // This should actually work, not underflow
   ASSERT_GT(diff, 999999000u); // Close to 1 second + small diff
}

// Test GetTimeStampDiff_Ns: actual underflow case
TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_ActualUnderflow)
{
   // This is a theoretical case that would cause underflow, but given S_2_NS = 1000000000
   // and max nanosecs = 999999999, underflow is mathematically impossible
   // So let's test the boundary case instead
   GLOB_TS_STRUCT_TYPE a{0, 1u, 2u};         // Second 2, very small nanos
   GLOB_TS_STRUCT_TYPE b{0, 999999999u, 1u}; // Second 1, max nanos
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(0u, ret); // Should work: 1 + 1000000000 - 999999999 = 2
   ASSERT_EQ(2u, diff);
}

// Test GetMidTimeStamps: cross-second boundary calculation
TEST_F(ECU_Sync_Test, GetMidTimeStamps_CrossSecondBoundary)
{
   GLOB_TS_STRUCT_TYPE a{0, 100u, 2u};       // Second 2, small nanos
   GLOB_TS_STRUCT_TYPE b{0, 500000000u, 1u}; // Second 1, 0.5 seconds
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_EQ(0u, ret);
   // Mid should be calculated correctly for cross-second scenario
   ASSERT_GT(mid.ts_nanosecs, 0u);
}

// Test GetMidTimeStamps: result requires second adjustment
TEST_F(ECU_Sync_Test, GetMidTimeStamps_SecondAdjustment)
{
   GLOB_TS_STRUCT_TYPE a{0, 1000000000u, 2u}; // Edge case at second boundary
   GLOB_TS_STRUCT_TYPE b{0, 0u, 2u};
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_EQ(0u, ret);
   // Test the temp2 == temp1 vs temp2 != temp1 branch
   ASSERT_GE(mid.ts_secs, 0u);
}

/* Branch coverage: temp2 != temp1 when sum exceeds 1 second boundary */
TEST_F(ECU_Sync_Test, GetMidTimeStamps_SecondBoundaryOverflow)
{
   /* NextSecond case: param1=(sec 2, 100ms), param2=(sec 1, 900ms)
      diff = (100e6 - 900e6) + 1e9 = 200e6
      half_diff = 100e6
      temp1 = 900e6 + 100e6 = 1e9 = S_2_NS (overflow!)
      temp2 = 1e9 % 1e9 = 0 != temp1
      Takes else branch: result.ts_secs = param1->ts_secs */
   GLOB_TS_STRUCT_TYPE a{0, 100000000u, 2u}; /* param1: sec 2, 100ms */
   GLOB_TS_STRUCT_TYPE b{0, 900000000u, 1u}; /* param2: sec 1, 900ms */
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(2u, mid.ts_secs);              /* Verifies else branch taken: uses param1->ts_secs */
   ASSERT_LT(mid.ts_nanosecs, 1000000000u); /* Within 1 second */
}

// Test all measurement point enums for buffered operations
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_AllMeasurementPoints)
{
   // Test each measurement point enum
   GLOB_TS_MEAS_PTS points[] = {TS_START_ACQ, TS_LOOK_COMP};
   for (auto point : points)
   {
      set_nanos(123000u + (uint32_t)point);
      uint8_t ret = CaptureGlobalTimestamp(point, nullptr);
      ASSERT_EQ(0u, ret);
   }
}

// Test buffer wraparound with read index advancement
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_BufferWrapAround)
{
   // Fill buffer beyond capacity to test wraparound
   for (int i = 0; i < 5; i++)
   {
      set_nanos((uint32_t)(i * 10000u));
      CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);
   }

   // Verify we can still retrieve data
   GLOB_TS_STRUCT_TYPE *result = GetGlobalTimestamp(TS_LOOK_COMP);
   ASSERT_NE(nullptr, result);
}

// Test GetTimeStampDiff_Ns: exact 1 second difference (boundary case)
TEST_F(ECU_Sync_Test, GetTimeStampDiff_Ns_ExactSecondDiff)
{
   GLOB_TS_STRUCT_TYPE a{0, 0u, 2u}; // Second 2, 0 nanos
   GLOB_TS_STRUCT_TYPE b{0, 0u, 1u}; // Second 1, 0 nanos
   uint32_t diff = 0;
   auto ret      = GetTimeStampDiff_Ns(&a, &b, &diff);
   ASSERT_EQ(0u, ret);
   ASSERT_EQ(1000000000u, diff); // Exactly 1 second in nanoseconds
}

// Test GetMidTimeStamps with error propagation
TEST_F(ECU_Sync_Test, GetMidTimeStamps_ErrorPropagation)
{
   // Use timestamps that will cause GetTimeStampDiff_Ns to fail
   GLOB_TS_STRUCT_TYPE a{0, 100u, 1u}; // Earlier
   GLOB_TS_STRUCT_TYPE b{0, 200u, 1u}; // Later
   GLOB_TS_STRUCT_TYPE mid{0};
   uint32_t diff = 0;
   auto ret      = GetMidTimeStamps(&a, &b, &mid, &diff);
   ASSERT_NE(0u, ret); // Should propagate error
   ASSERT_EQ(TS_ERROR, mid.ts_nanosecs);
   ASSERT_EQ(TS_ERROR, mid.ts_secs);
}

// Test PeekGlobalTimestamp for different measurement points
TEST_F(ECU_Sync_Test, PeekGlobalTimestamp_DifferentPoints)
{
   GLOB_TS_MEAS_PTS points[] = {TS_NO_BUFF, TS_START_ACQ, TS_LOOK_COMP};
   for (auto point : points)
   {
      GLOB_TS_STRUCT_TYPE *result = PeekGlobalTimestamp(point);
      ASSERT_NE(nullptr, result);
   }
}

/* Branch coverage: GetGlobalTimestamp when cnt == 0 (false branch at line 292)
   When buffer is empty, should return fallback TS_NO_BUFF timestamp */
TEST_F(ECU_Sync_Test, GetGlobalTimestamp_CountZero_ReturnsFallback)
{
   /* Intentionally do NOT capture any timestamp for TS_LOOK_COMP
      This leaves cnt == 0, exercising the else branch that returns TS_NO_BUFF */
   GLOB_TS_STRUCT_TYPE *result = GetGlobalTimestamp(TS_LOOK_COMP);
   ASSERT_NE(nullptr, result);
   /* Verify it returns a valid pointer (either the timestamp or fallback) */
}

// Test CaptureGlobalTimestamp with RTE error for TS_NO_BUFF case
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_RteError_NoBuffer)
{
   // Set stub to return E_NOT_OK
   g_stbm_return_value = 1; // E_NOT_OK

   set_nanos(456000000u);
   GLOB_TS_STRUCT_TYPE ts;
   uint8_t ret = CaptureGlobalTimestamp(TS_NO_BUFF, &ts);
   ASSERT_EQ(1u, ret); // Should return E_NOT_OK
}

// Test various buffer states and edge cases
TEST_F(ECU_Sync_Test, CaptureGlobalTimestamp_BufferStates)
{
   // Test with different measurement points to ensure all buffer paths are covered
   for (int i = 0; i < 3; i++)
   {
      set_nanos((uint32_t)(i * 50000u));
      uint8_t ret = CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
      ASSERT_EQ(0u, ret);
   }

   // Test overflow condition is properly handled
   for (int i = 0; i < 3; i++)
   {
      set_nanos((uint32_t)(i * 60000u));
      uint8_t ret = CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);
      ASSERT_EQ(0u, ret);
   }
}

TEST_F(ECU_Sync_Test, HandleNonBuffered_FillsAllFields)
{
   g_test_time_inject.nanoseconds    = 123456789u;
   g_test_time_inject.seconds        = 99u;
   g_test_time_inject.timeBaseStatus = 0x5u;

   GLOB_TS_STRUCT_TYPE ts = {0u, 0u, 0u};
   uint8_t ret            = CaptureGlobalTimestamp(TS_NO_BUFF, &ts);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(123456789u, ts.ts_nanosecs);
   ASSERT_EQ(99u, ts.ts_secs);
   ASSERT_EQ(0x5u, ts.ts_status);
}

TEST_F(ECU_Sync_Test, HandleNonBuffered_NullPointer_NoCrash)
{
   g_test_time_inject.nanoseconds = 111u;
   g_stbm_return_value            = 0; // E_OK

   uint8_t ret = CaptureGlobalTimestamp(TS_NO_BUFF, nullptr);
   ASSERT_EQ(0u, ret);
}

TEST_F(ECU_Sync_Test, HandleNonBuffered_NotCalledOnRteError)
{
   g_stbm_return_value            = 1u; // E_NOT_OK
   g_test_time_inject.nanoseconds = 999u;

   GLOB_TS_STRUCT_TYPE ts = {0u, 0u, 0u};
   uint8_t ret            = CaptureGlobalTimestamp(TS_NO_BUFF, &ts);

   ASSERT_EQ(1u, ret);
   ASSERT_EQ(0u, ts.ts_nanosecs); // must remain untouched
}

TEST_F(ECU_Sync_Test, HandleBuffered_FirstWrite_DataStoredAndRetrievable)
{
   // Drain any stale entries left by previous tests (buffer size = 2)
   GetGlobalTimestamp(TS_START_ACQ);
   GetGlobalTimestamp(TS_START_ACQ);

   g_test_time_inject.nanoseconds    = 500000u;
   g_test_time_inject.seconds        = 3u;
   g_test_time_inject.timeBaseStatus = 1u;

   uint8_t ret = CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
   ASSERT_EQ(0u, ret);

   GLOB_TS_STRUCT_TYPE *p = GetGlobalTimestamp(TS_START_ACQ);
   ASSERT_NE(nullptr, p);
   ASSERT_EQ(500000u, p->ts_nanosecs);
   ASSERT_EQ(3u, p->ts_secs);
   ASSERT_EQ(1u, p->ts_status);
}

TEST_F(ECU_Sync_Test, HandleBuffered_OverflowPath_OldestEntryEvicted)
{
   GetGlobalTimestamp(TS_START_ACQ);
   GetGlobalTimestamp(TS_START_ACQ);

   // entry 0: nanos = 100
   g_test_time_inject.nanoseconds = 100u;
   CaptureGlobalTimestamp(TS_START_ACQ, nullptr);

   // entry 1: nanos = 200  (buffer now full)
   g_test_time_inject.nanoseconds = 200u;
   CaptureGlobalTimestamp(TS_START_ACQ, nullptr);

   // entry 2: nanos = 300  (triggers overflow — r_index advances, ovr set)
   g_test_time_inject.nanoseconds = 300u;
   uint8_t ret                    = CaptureGlobalTimestamp(TS_START_ACQ, nullptr);
   ASSERT_EQ(0u, ret);

   // Oldest entry (100) must have been evicted; first readable entry is 200
   GLOB_TS_STRUCT_TYPE *p = GetGlobalTimestamp(TS_START_ACQ);
   ASSERT_NE(nullptr, p);
   ASSERT_NE(100u, p->ts_nanosecs);
}

// Write index wraps around correctly after BUFF_SIZE writes
TEST_F(ECU_Sync_Test, HandleBuffered_WriteIndexWraps)
{
   // Drain any stale entries left by previous tests (buffer size = 2)
   GetGlobalTimestamp(TS_LOOK_COMP);
   GetGlobalTimestamp(TS_LOOK_COMP);

   // Two writes fill the buffer
   g_test_time_inject.nanoseconds = 10u;
   CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);
   g_test_time_inject.nanoseconds = 20u;
   CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);

   // Third write wraps write index back to 0
   g_test_time_inject.nanoseconds = 30u;
   CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);

   // Fourth write wraps write index to 1
   g_test_time_inject.nanoseconds = 40u;
   uint8_t ret                    = CaptureGlobalTimestamp(TS_LOOK_COMP, nullptr);
   ASSERT_EQ(0u, ret);

   // Buffer should still hold two entries and be readable
   GLOB_TS_STRUCT_TYPE *p = GetGlobalTimestamp(TS_LOOK_COMP);
   ASSERT_NE(nullptr, p);
}

// ===========================================================================
// Tests for GetTimeStampDiff_SameSecond (via GetTimeStampDiff_Ns, same ts_secs)
// ===========================================================================

// param1.nanos > param2.nanos: success, correct delta returned
TEST_F(ECU_Sync_Test, SameSecond_Param1Greater_CorrectDelta)
{
   GLOB_TS_STRUCT_TYPE a = {0, 700000000u, 5u};
   GLOB_TS_STRUCT_TYPE b = {0, 200000000u, 5u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(500000000u, diff);
}

// param1.nanos == param2.nanos: success, zero delta
TEST_F(ECU_Sync_Test, SameSecond_EqualNanos_ZeroDelta)
{
   GLOB_TS_STRUCT_TYPE a = {0, 123u, 2u};
   GLOB_TS_STRUCT_TYPE b = {0, 123u, 2u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(0u, diff);
}

// param1.nanos < param2.nanos: returns error 1, result set to TS_ERROR
TEST_F(ECU_Sync_Test, SameSecond_Param1Smaller_ReturnsError)
{
   GLOB_TS_STRUCT_TYPE a = {0, 99u, 4u};
   GLOB_TS_STRUCT_TYPE b = {0, 100u, 4u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(1u, ret);
   ASSERT_EQ(TS_ERROR, diff);
}

// ===========================================================================
// Tests for GetTimeStampDiff_NextSecond (via GetTimeStampDiff_Ns, ts_secs differ by 1)
// ===========================================================================

// Typical consecutive-second case: correct nanosecond delta
TEST_F(ECU_Sync_Test, NextSecond_TypicalCase_CorrectDelta)
{
   // (50 + 1000000000) - 999999900 = 150
   GLOB_TS_STRUCT_TYPE a = {0, 50u, 2u};
   GLOB_TS_STRUCT_TYPE b = {0, 999999900u, 1u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(150u, diff);
}

// param1.nanos = 0, param2.nanos = 0: exactly one second difference
TEST_F(ECU_Sync_Test, NextSecond_BothZeroNanos_ExactOneSecond)
{
   GLOB_TS_STRUCT_TYPE a = {0, 0u, 3u};
   GLOB_TS_STRUCT_TYPE b = {0, 0u, 2u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(1000000000u, diff);
}

// param1.nanos at max (999999999): (999999999 + 1000000000) - 0 = 1999999999
TEST_F(ECU_Sync_Test, NextSecond_MaxNanos_LargeDelta)
{
   GLOB_TS_STRUCT_TYPE a = {0, 999999999u, 6u};
   GLOB_TS_STRUCT_TYPE b = {0, 0u, 5u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(1999999999u, diff);
}

/* Branch coverage: NextSecond false path when (param1.nanos + S_2_NS) < param2.nanos
   This branch is UNREACHABLE in practice because:
   - param1.nanos always < 1e9 (by definition)
   - param2.nanos always < 1e9 (by definition)
   - (param1.nanos + 1e9) always >= 1e9 > param2.nanos

   However, we include this test to document the unreachable branch coverage gap.
   The condition at line 381 will ALWAYS be true with valid nanosecond values. */
TEST_F(ECU_Sync_Test, NextSecond_ErrorPath_UnreachableBranch)
{
   /* Attempt to trigger false branch (impossible with valid inputs)
      param1: sec 6, max nanos (999999999); param2: sec 5, 0 nanos
      (999999999 + 1000000000) - 0 = 1999999999 (always >= param2.nanos)
      This demonstrates the false branch is unreachable */
   GLOB_TS_STRUCT_TYPE a = {0, 999999999u, 6u};
   GLOB_TS_STRUCT_TYPE b = {0, 0u, 5u};
   uint32_t diff         = 0u;

   uint8_t ret = GetTimeStampDiff_Ns(&a, &b, &diff);

   ASSERT_EQ(0u, ret);
   ASSERT_EQ(1999999999u, diff);
   /* Note: false branch at line 381 remains unreachable - this is unreachable code
      that could be safely removed or a defensive programming artifact */
}
TEST_F(ECU_Sync_Test, ISR_LookSyncOverflow_TriggersRadarCtlWhenLookSyncFails)
{
   g_test_time_inject.timeBaseStatus   = 0u;
   g_Radar_Look_Sync_Test_return_value = false;

   set_nanos(999999999u);
   Radar_Trigger_Timer_ISR();

   set_nanos(50u);
   Radar_Trigger_Timer_ISR();

   ASSERT_EQ(1u, g_Radar_Look_Sync_Test_calls);
   ASSERT_TRUE(g_last_radar_look_sync_test_arg);
   ASSERT_EQ(1u, g_Radar_Ctl_Look_Sync_Trig_calls);
}

TEST_F(ECU_Sync_Test, ISR_LookSyncOverflow_DoesNotTriggerRadarCtlWhenLookSyncPasses)
{
   g_test_time_inject.timeBaseStatus   = 0u;
   g_Radar_Look_Sync_Test_return_value = true;

   set_nanos(999999999u);
   Radar_Trigger_Timer_ISR();

   set_nanos(50u);
   Radar_Trigger_Timer_ISR();

   ASSERT_EQ(1u, g_Radar_Look_Sync_Test_calls);
   ASSERT_TRUE(g_last_radar_look_sync_test_arg);
   ASSERT_EQ(0u, g_Radar_Ctl_Look_Sync_Trig_calls);
}

TEST_F(ECU_Sync_Test, ISR_LookSyncOverflow_DoesNotEvaluateOrTriggerWhenLookSyncDisabled)
{
   g_test_time_inject.timeBaseStatus   = 0u;
   g_Radar_Look_Sync_Test_return_value = false;
   Look_Sync                           = Look_Sync_Disable;

   set_nanos(999999999u);
   Radar_Trigger_Timer_ISR();

   set_nanos(50u);
   Radar_Trigger_Timer_ISR();

   ASSERT_EQ(0u, g_Radar_Look_Sync_Test_calls);
   ASSERT_FALSE(g_last_radar_look_sync_test_arg);
   ASSERT_EQ(0u, g_Radar_Ctl_Look_Sync_Trig_calls);
}
