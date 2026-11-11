/*===========================================================================*/
/**
 * @file range_process_ifc_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit tests for range process wrapper `range_process_ifc.c`.
 * Tests follow the style of `appl_cfar_ifc_unit_test.cc` (fixture-based).
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <chrono>
#include <cstring>
#include <gtest/gtest.h>
#include <thread>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "core_macros_fff.h"
#include "dd_mipi_fff.h"
#include "ipc_fff.h"
#include "mipi_helpers_fff.h"
#include "mipi_ifc_fff.h"
#include "profiling_helpers_fff.h"
#include "ra_helpers_fff.h"
#include "range_process_fff.h"
#include "spbb_math.h"
#include "xcp_adc_logging_fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "range_process_ifc.c"

/*===========================================================================*
 * FFF setup and stubs
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

static uint32_t g_xcp_logging_handler_call_count = 0U;

extern "C" void XCP_Logging_Handler(void)
{
   g_xcp_logging_handler_call_count++;
}

/*===========================================================================*
 * Global variables and stubs required by range_process_ifc.c
 *===========================================================================*/
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
const uint16_t K_FRAME[6]   = {960, 1024, 960, 1024, 1024, 1024};
const uint16_t M_FRAME[6]   = {480, 472, 512, 504, 512, 504};

/* Stub IPC buffers */
volatile M2D_Msg_T m2d_msg;
D2M_Msg_T d2m_msg;
volatile uint32_t Offline_Mode_Flag_DSP = (uint32_t)ITF_DISABLED_NORMAL_MODE;
volatile D2M_Msg_T rp_d2m_msg           = {0};

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Range_Process_Ifc_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_RANGE_PROCESS_LIST(RESET_FAKE);
      FFF_FAKES_MIPI_IFC_LIST(RESET_FAKE);
      FFF_FAKES_MIPI_HELPERS_LIST(RESET_FAKE);
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_FAKES_PROFILING_HELPERS_LIST(RESET_FAKE);
      FFF_FAKES_RA_HELPERS_LIST(RESET_FAKE);
      FFF_FAKES_CORE_MACROS(RESET_FAKE);
      FFF_FAKES_XCP_ADC_LOGGING_LIST(RESET_FAKE);
      FFF_FAKES_DD_MIPI_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      (void)memset((void *)&m2d_msg, 0, sizeof(m2d_msg));
      (void)memset(&d2m_msg, 0, sizeof(d2m_msg));
      /* Set up default fake returns */
      Range_Process_Execute_fake.return_val         = RANGE_PROCESS_NO_ERROR;
      Process_Chirp_Callback_fake.return_val        = RANGE_PROCESS_NOT_COMPLETE;
      Appl_IDM_Stat_Init_fake.return_val            = MEM_POOL_SUCCESS;
      Get_IPC_M2D_Buffer_fake.return_val            = &m2d_msg;
      Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;
      Get_RP_IPC_D2M_Msg_Buffer_fake.return_val     = &rp_d2m_msg;

      // Set the frame dwell time to default timeout - the max allowed chirp increase.
      // This allows the tests to use the RANGE_PROCESSING_TIMEOUT_US as the expected failing timeout value.
      k_frame_dwell_ms_smc[0] = (float)(RANGE_PROCESSING_TIMEOUT_US - MAX_ALLOWED_CHIRP_TIME_INCREASE_US) / 1000.0F;
      k_frame_dwell_ms_smc[1] = k_frame_dwell_ms_smc[0];
      k_frame_dwell_ms_smc[2] = k_frame_dwell_ms_smc[0];
      k_frame_dwell_ms_smc[3] = k_frame_dwell_ms_smc[0];

      /* Reset global state */
      memset((void *)&rp_d2m_msg, 0, sizeof(rp_d2m_msg));
      Range_Processing_Done_Timestamp = 0U;
      memset((void *)&Appl_Range_Variables, 0, sizeof(Appl_Range_Variables));
      Appl_Range_Variables.bb_status   = RANGE_PROCESS_NUMBER_STATUS;
      Appl_Range_Variables.status      = APPL_RANGE_PROCESS_IDLE;
      Range_Proc_Overrun_Counter       = 0U;
      Offline_Mode_Flag_DSP            = (uint32_t)ITF_DISABLED_NORMAL_MODE;
      xthal_get_ccount_fake.return_val = 0U;
      g_xcp_logging_handler_call_count = 0U;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/*---------------------------------------------------------------------------*
 * Appl_Range_Process_Init
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, Init_ReturnsTrue_WhenExecuteSucceeds)
{
   Range_Process_Execute_fake.return_val = RANGE_PROCESS_NO_ERROR;
   bool result                           = Appl_Range_Process_Init(RADAR_LOOK_A);
   EXPECT_TRUE(result);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_RUNNING);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, Init_ReturnsFalse_WhenExecuteFails)
{
   Range_Process_Execute_fake.return_val = RANGE_PROCESS_CONFIG_FAIL_ERROR;
   bool result                           = Appl_Range_Process_Init(RADAR_LOOK_A);
   EXPECT_FALSE(result);
   EXPECT_NE(Appl_Range_Variables.status, APPL_RANGE_PROCESS_RUNNING);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, Init_ResetsCHirpCallbackCount)
{
   Appl_Range_Variables.chirp_callback_cnt = 5U;
   Appl_Range_Process_Init(RADAR_LOOK_A);
   EXPECT_EQ(Appl_Range_Variables.chirp_callback_cnt, 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, Init_SetsBBStatusToNotComplete)
{
   Range_Process_Execute_fake.return_val = RANGE_PROCESS_NO_ERROR;
   Appl_Range_Process_Init(RADAR_LOOK_A);
   EXPECT_EQ(Appl_Range_Variables.bb_status, RANGE_PROCESS_NOT_COMPLETE);
}

/*---------------------------------------------------------------------------*
 * Appl_Range_Process_Chirp_Callback
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_IncrementsCnt_OnFirstCall)
{
   Appl_Range_Process_Chirp_Callback(NULL);
   EXPECT_EQ(Appl_Range_Variables.chirp_callback_cnt, 1U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_SetsBBStatus_FromProcessChirpReturn)
{
   Appl_Range_Variables.bb_status                = RANGE_PROCESS_NUMBER_STATUS;
   Appl_Range_Variables.bb_status_mipi_chirp_end = RANGE_PROCESS_NUMBER_STATUS;
   Appl_Range_Process_Chirp_Callback(NULL);
   EXPECT_EQ(Appl_Range_Variables.bb_status, RANGE_PROCESS_NUMBER_STATUS);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_SetsBBStatusToComplete_WhenLastChirp)
{
   Appl_Range_Variables.bb_status_mipi_chirp_end = RANGE_PROCESS_COMPLETE;
   Appl_Range_Variables.expected_num_chirps      = 1U;
   Appl_Range_Process_Chirp_Callback(NULL);
   EXPECT_EQ(Appl_Range_Variables.bb_status, RANGE_PROCESS_COMPLETE);
   EXPECT_EQ(g_xcp_logging_handler_call_count, 1U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_MultipleCalls_AccumulatesCount)
{
   Appl_Range_Process_Chirp_Callback(NULL);
   Appl_Range_Process_Chirp_Callback(NULL);
   Appl_Range_Process_Chirp_Callback(NULL);
   EXPECT_EQ(Appl_Range_Variables.chirp_callback_cnt, 3U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_UpdatesLastChirpCycles_WhenFrameCompletes)
{
   unsigned int seq[] = {100U, 170U, 200U};

   Appl_Range_Variables.chirp_callback_cnt       = 1U;
   Appl_Range_Variables.bb_status_mipi_chirp_end = RANGE_PROCESS_COMPLETE;
   Appl_Range_Variables.expected_num_chirps      = 2U;
   Appl_Range_Chirp_Cycles.other_chirp_timestamp = 50U;
   Get_MIPI_Chirp_End_Timestamp_fake.return_val  = 0U;
   SET_RETURN_SEQ(xthal_get_ccount, seq, 3);

   Appl_Range_Process_Chirp_Callback(NULL);

   EXPECT_EQ(Appl_Range_Chirp_Cycles.last_chirp_cycles, 120U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_UpdatesOtherChirpCyclesMax_WhenChirpCyclesIncrease)
{
   unsigned int seq[] = {100U, 160U, 190U};

   Appl_Range_Variables.chirp_callback_cnt        = 1U;
   Appl_Range_Chirp_Cycles.other_chirp_timestamp  = 40U;
   Appl_Range_Chirp_Cycles.other_chirp_cycles_max = 10U;
   Process_Chirp_Callback_fake.return_val         = RANGE_PROCESS_NOT_COMPLETE;
   Get_MIPI_Chirp_End_Timestamp_fake.return_val   = 0U;
   SET_RETURN_SEQ(xthal_get_ccount, seq, 3);

   Appl_Range_Process_Chirp_Callback(NULL);

   EXPECT_EQ(Appl_Range_Chirp_Cycles.other_chirp_cycles_max, 120U);
}

/*---------------------------------------------------------------------------*
 * Appl_Range_Process_Push_Ra_Commands
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, PushRaCommands_CallsProcessChirpCallback)
{
   Process_Chirp_Callback_fake.return_val = RANGE_PROCESS_NOT_COMPLETE;

   Appl_Range_Process_Push_Ra_Commands();

   EXPECT_EQ(Process_Chirp_Callback_fake.call_count, 1U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, PushRaCommands_UpdatesMipiChirpEndStatus)
{
   Process_Chirp_Callback_fake.return_val = RANGE_PROCESS_COMPLETE;

   Appl_Range_Process_Push_Ra_Commands();

   EXPECT_EQ(Appl_Range_Variables.bb_status_mipi_chirp_end, RANGE_PROCESS_COMPLETE);
}

/*---------------------------------------------------------------------------*
 * Check_For_Range_Process_Complete_Timeout_Check
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_ReturnsNoError_WhenBBComplete)
{
   Mem_Pool_T mem_pool                = {0};
   Appl_Range_Variables.bb_status     = RANGE_PROCESS_COMPLETE;
   Appl_IDM_Stat_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Range_Return_Values_T ret     = Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(ret, APPL_RANGE_NO_ERROR);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_SetsCompleteSuccess_WhenBBComplete)
{
   Mem_Pool_T mem_pool            = {0};
   Appl_Range_Variables.bb_status = RANGE_PROCESS_COMPLETE;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_SUCCESS);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_CompletesSuccessfully_WhenIDMInitSucceeds)
{
   Mem_Pool_T mem_pool                = {0};
   Appl_Range_Variables.bb_status     = RANGE_PROCESS_COMPLETE;
   Appl_IDM_Stat_Init_fake.return_val = MEM_POOL_SUCCESS;

   EXPECT_EQ(Check_For_Range_Process_Complete_Timeout_Check(&mem_pool), APPL_RANGE_NO_ERROR);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_SUCCESS);
   EXPECT_EQ(Range_Proc_Overrun_Counter, 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_UsesDefaultLookA_WhenLookTypeIsInvalid)
{
   Mem_Pool_T mem_pool                                                                  = {0};
   Get_RP_IPC_D2M_Msg_Buffer_fake.return_val->payload.rdd_stream_data.look_data.look_id = NUM_LOOKS;
   Appl_Range_Variables.bb_status                                                       = RANGE_PROCESS_COMPLETE;
   Appl_IDM_Stat_Init_fake.return_val                                                   = MEM_POOL_SUCCESS;

   EXPECT_EQ(Check_For_Range_Process_Complete_Timeout_Check(&mem_pool), APPL_RANGE_NO_ERROR);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_SUCCESS);
   EXPECT_EQ(Range_Proc_Overrun_Counter, 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_CompletesSuccessfully_WhenIDMInitFails)
{
   Mem_Pool_T mem_pool                = {0};
   Appl_Range_Variables.bb_status     = RANGE_PROCESS_COMPLETE;
   Appl_IDM_Stat_Init_fake.return_val = MEM_POOL_FAILURE;

   EXPECT_EQ(Check_For_Range_Process_Complete_Timeout_Check(&mem_pool), APPL_RANGE_NO_ERROR);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_SUCCESS);
   EXPECT_EQ(Range_Proc_Overrun_Counter, 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_ReturnsError_WhenBBNotComplete)
{
   Mem_Pool_T mem_pool = {0};
   /* bb_status stays NOT_COMPLETE; large timestamp exits the while loop */
   xthal_get_ccount_fake.return_val = UINT32_MAX;
   Appl_Range_Return_Values_T ret   = Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(ret, APPL_RANGE_ERROR);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_SetsErrorStatus_WhenBBNotComplete)
{
   Mem_Pool_T mem_pool              = {0};
   xthal_get_ccount_fake.return_val = UINT32_MAX;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_ERROR);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_CallsRaResetReq_WhenBBNotComplete)
{
   Mem_Pool_T mem_pool              = {0};
   xthal_get_ccount_fake.return_val = UINT32_MAX;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Ra_Reset_Req_fake.call_count, 1U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_ReturnsTimeout_WhenLastRuntimeExceedsLimit_01)
{
   Mem_Pool_T mem_pool                                = {0};
   Appl_Range_Variables.bb_status                     = RANGE_PROCESS_COMPLETE;
   Appl_Range_Variables.last_chirp_timestamp          = RANGE_PROCESSING_TIMEOUT_US * DSP_CLK_FREQ_MHZ;
   Appl_Range_Variables.profiling_info.startTimestamp = 0;
   Appl_Range_Variables.profiling_info.lastRuntime    = RANGE_PROCESSING_TIMEOUT_US;
   Appl_Range_Return_Values_T ret                     = Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(ret, APPL_RANGE_TIMEOUT);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_IncrementsOverrunCounter_OnTimeout)
{
   Mem_Pool_T mem_pool                                = {0};
   Appl_Range_Variables.bb_status                     = RANGE_PROCESS_COMPLETE;
   Appl_Range_Variables.last_chirp_timestamp          = RANGE_PROCESSING_TIMEOUT_US * DSP_CLK_FREQ_MHZ;
   Appl_Range_Variables.profiling_info.startTimestamp = 0;
   Appl_Range_Variables.profiling_info.lastRuntime    = RANGE_PROCESSING_TIMEOUT_US;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Range_Proc_Overrun_Counter, 1U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_ClearsMaxRuntime_WhenErrorStatus)
{
   Mem_Pool_T mem_pool                            = {0};
   xthal_get_ccount_fake.return_val               = UINT32_MAX;
   Appl_Range_Variables.profiling_info.maxRuntime = 99999U;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Appl_Range_Variables.profiling_info.maxRuntime, 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_WaitsForFinalInterruptInOfflineMode)
{
   static uint8_t pool_mem[sizeof(ADC_Offline_Data_T)];
   Mem_Pool_T mem_pool                  = {0};
   Appl_Range_Return_Values_T ret_value = APPL_RANGE_ERROR;

   ASSERT_EQ(Mem_Pool_Init(&mem_pool, pool_mem, sizeof(pool_mem)), MEM_POOL_SUCCESS);

   Offline_Mode_Flag_DSP            = (uint32_t)ITF_ADC_INJECTION_MODE;
   Appl_Range_Variables.bb_status   = RANGE_PROCESS_NOT_COMPLETE;
   XT_L32AI_fake.return_val         = 0xAA55U;
   xthal_get_ccount_fake.return_val = 0U;

   std::thread range_process_thread([&]() { ret_value = Check_For_Range_Process_Complete_Timeout_Check(&mem_pool); });

   std::this_thread::sleep_for(std::chrono::milliseconds(10));
   Appl_Range_Variables.bb_status = RANGE_PROCESS_COMPLETE;

   range_process_thread.join();

   EXPECT_EQ(ret_value, APPL_RANGE_NO_ERROR);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_SUCCESS);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_UpdatesRuntimeWhileWaitingForCompletion)
{
   Mem_Pool_T mem_pool          = {0};
   unsigned int timestamp_seq[] = {
      0U,
      1U,
      (RANGE_PROCESSING_TIMEOUT_US * DSP_CLK_FREQ_MHZ) + 1U,
      (RANGE_PROCESSING_TIMEOUT_US * DSP_CLK_FREQ_MHZ) + 1U,
   };

   Appl_Range_Variables.bb_status = RANGE_PROCESS_NOT_COMPLETE;
   SET_RETURN_SEQ(xthal_get_ccount, timestamp_seq, 4);

   EXPECT_EQ(Check_For_Range_Process_Complete_Timeout_Check(&mem_pool), APPL_RANGE_ERROR);
   EXPECT_EQ(Appl_Range_Variables.status, APPL_RANGE_PROCESS_COMPLETE_ERROR);
}

/*---------------------------------------------------------------------------*
 * Get_Range_Procesing_Done_Time
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, GetDoneTime_ReturnsZero_Initially)
{
   EXPECT_EQ(Get_Range_Procesing_Done_Time(), 0U);
}

TEST_F(Range_Process_Ifc_Unit_Test_Suite, GetDoneTime_ReturnsTimestamp_AfterTimeoutCheck)
{
   Mem_Pool_T mem_pool              = {0};
   Appl_Range_Variables.bb_status   = RANGE_PROCESS_COMPLETE;
   xthal_get_ccount_fake.return_val = 12345U;
   Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);
   EXPECT_EQ(Get_Range_Procesing_Done_Time(), 12345U);
}

/*---------------------------------------------------------------------------*
 * TimeoutCheck - Offline mode active (ITF_ADC_INJECTION_MODE == Offline_Mode_Flag_DSP)
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, TimeoutCheck_ReturnsNoError_WhenOfflineModeActive)
{
   static uint8_t pool_mem[sizeof(ADC_Offline_Data_T)];
   Mem_Pool_T mem_pool;
   Mem_Pool_Init(&mem_pool, pool_mem, sizeof(pool_mem));

   Offline_Mode_Flag_DSP                           = (uint32_t)ITF_ADC_INJECTION_MODE;
   Appl_Range_Variables.bb_status                  = RANGE_PROCESS_COMPLETE;
   Appl_Range_Variables.profiling_info.lastRuntime = RANGE_PROCESSING_TIMEOUT_US;
   XT_L32AI_fake.return_val                        = 0xAA55U;

   Appl_Range_Return_Values_T ret = Check_For_Range_Process_Complete_Timeout_Check(&mem_pool);

   EXPECT_EQ(Range_Proc_Overrun_Counter, 0U);
   EXPECT_EQ(ret, APPL_RANGE_NO_ERROR);
}

/*---------------------------------------------------------------------------*
 * Appl_Range_Process_Chirp_Callback - cycles > callback_cycles branch (line 405)
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ChirpCallback_UpdatesCallbackCycles_WhenCyclesExceedCurrent)
{
   unsigned int seq[] = {0U, 100U, 200U};
   SET_RETURN_SEQ(xthal_get_ccount, seq, 3);

   Appl_Range_Process_Chirp_Callback(NULL);

   EXPECT_EQ(Appl_Range_Chirp_Cycles.callback_cycles, 200U);
}

/*---------------------------------------------------------------------------*
 * ADC_Offline_Injection_Handler (line 510)
 *---------------------------------------------------------------------------*/

TEST_F(Range_Process_Ifc_Unit_Test_Suite, ADCOfflineInjection_CallsWriteChirpForEachChirp)
{
   static uint8_t pool_mem[sizeof(ADC_Offline_Data_T)];
   Mem_Pool_T mem_pool;
   uint16_t ret_size = K_FRAME[RADAR_LOOK_A] * 2 + 2;
   // uint16_t ret_size= 1147;
   Mem_Pool_Init(&mem_pool, pool_mem, sizeof(pool_mem));
   uint32_t XT_L32AI_ret_seq[ret_size] = {0};
   for (uint16_t i = 0; i < ret_size; i++)
   {
      if (i % 2 != 0)
      {
         XT_L32AI_ret_seq[i] = 0xAA55U;
      }
   }
   // K_FRAME[RADAR_LOOK_A]=1;
   SET_RETURN_SEQ(XT_L32AI, XT_L32AI_ret_seq, ret_size);

   ADC_Offline_Injection_Handler(&mem_pool);
   ASSERT_EQ(XT_L32AI_fake.call_count, ret_size);
}
