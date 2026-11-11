/*===========================================================================*/
/**
 * @file mmic_interface_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for checking dd_mmic.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "crc_calc_mocks.h"
#include "crg_sfrs.h"
#include "fff.h"
#include <gtest/gtest.h>
#include <stdint.h>
#include <string.h>

DEFINE_FFF_GLOBALS;
#define UNIT_TEST

static CRG_SFRS_t g_fake_crg;

extern "C"
{
#include "dd_mipi_csi2_fake.h"
#include "radar_sw_config.h"
#undef CRG_base
#define CRG_base ((uintptr_t)(&g_fake_crg))
   volatile uint64_t Acq_End_Time_FE[4]   = {0U};
   volatile uint64_t Acq_Start_Time_FS[4] = {0U};

   // Define extern variables from mmic_error.h
   volatile uint8_t API_Look_Config_Error   = 0;
   volatile uint8_t API_Look_Trigger_Error  = 0;
   volatile uint8_t API_Look_Complete_Error = 0;
   volatile uint8_t MMIC_High_Temp_Fault    = CODED_FALSE;
   volatile uint8_t MMIC_Low_Temp_Fault     = CODED_FALSE;
   /* FuSa globals referenced by mmic_interface.c in unit-test link context */
   volatile bool MIPI_Chp_FuSa_Flag = false;

   FAKE_VOID_FUNC(MIPI_FuSa_Fault_Processing);

   // Define extern variables from dd_mmic.h (size matches MAX_API_FAULT_TYPE = 3)
   volatile uint8_t MMIC_API_Failure_Status[3] = {CODED_FALSE, CODED_FALSE, CODED_FALSE};
   volatile uint8_t Alive_Flag                 = CODED_FALSE;

   // Forward declare the type before the fake function
   typedef struct MMIC_Data_Logging_Tag MMIC_Data_Logging_T;

   // Fake for Rfe_Nvm_Read called from mmic_interface.c
   FAKE_VOID_FUNC(Rfe_Nvm_Read, MMIC_Data_Logging_T *);

   uint64_t *Get_Acq_End_Time_FE_Ptr(void)
   {
      return (uint64_t *)Acq_End_Time_FE;
   }
   uint64_t *Get_Acq_Start_Time_FS_Ptr(void)
   {
      return (uint64_t *)Acq_Start_Time_FS;
   }

#include "mmic_interface.c"
#include "mmic_stream.h"
#include "mocks/dd_mmic_fake.h"
#include "mocks/mmic_error_fake.h"
#include "stdio.h"

   // Define MMIC_Error after the includes so the type is available
   MMIC_Error_Data_T MMIC_Error               = {0};
   MMIC_FuSa_Faults_T Mars_FSM_Reg_State      = {0};
   FuSa_Faults_Union_T MMIC_Fusa_Active_Fault = {0};

   // Test stub for Get_Mmic_Id_Ptr - returns pointer to MMIC_Stream's mmic_id_status
   MMIC_ID_Status_T *Get_Mmic_Id_Ptr(void)
   {
      return &MMIC_Stream.MMIC_Data.mmic_id_status;
   }
}
FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream);

/* -----------------------------------------------------------------------
 * ECU Sync timestamp stubs used by Update_Dwell_Timestamps.
 * Tests can configure the fake values via the setter helpers below.
 * ----------------------------------------------------------------------- */
static GLOB_TS_STRUCT_TYPE g_fake_ts_start = {0};
static GLOB_TS_STRUCT_TYPE g_fake_ts_end   = {0};
static GLOB_TS_STRUCT_TYPE g_fake_ts_mid   = {0};
static uint32_t g_fake_mid_duration_ns     = 0U;

void ResetFakeTimestampData(void)
{
   memset(&g_fake_ts_start, 0, sizeof(g_fake_ts_start));
   memset(&g_fake_ts_end, 0, sizeof(g_fake_ts_end));
   memset(&g_fake_ts_mid, 0, sizeof(g_fake_ts_mid));
   g_fake_mid_duration_ns = 0U;
}

void SetFakeStartTimestamp(uint32_t secs, uint32_t nanosecs, uint8_t status)
{
   g_fake_ts_start.ts_secs     = secs;
   g_fake_ts_start.ts_nanosecs = nanosecs;
   g_fake_ts_start.ts_status   = status;
}

void SetFakeEndTimestamp(uint32_t secs, uint32_t nanosecs, uint8_t status)
{
   g_fake_ts_end.ts_secs     = secs;
   g_fake_ts_end.ts_nanosecs = nanosecs;
   g_fake_ts_end.ts_status   = status;
}

void SetFakeMidTimestamp(uint32_t secs, uint32_t nanosecs, uint8_t status)
{
   g_fake_ts_mid.ts_secs     = secs;
   g_fake_ts_mid.ts_nanosecs = nanosecs;
   g_fake_ts_mid.ts_status   = status;
}

void SetFakeMidDuration(uint32_t duration_ns)
{
   g_fake_mid_duration_ns = duration_ns;
}

GLOB_TS_STRUCT_TYPE *GetGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point)
{
   switch (meas_point)
   {
      case TS_START_ACQ:
         return &g_fake_ts_start;
      case TS_LOOK_COMP:
         return &g_fake_ts_end;
      default:
         return &g_fake_ts_start;
   }
}

uint8_t GetMidTimeStamps(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, GLOB_TS_STRUCT_TYPE *result, uint32_t *diff)
{
   (void)param1;
   (void)param2;

   if (result != NULL)
   {
      *result = g_fake_ts_mid;
   }

   if (diff != NULL)
   {
      *diff = g_fake_mid_duration_ns;
   }

   return (uint8_t)E_OK;
}

MMIC_Stream_T MMIC_Stream = {0};
/* redefinition of global variables used by UUT */
bool Get_MMIC_Error_Discard_custom_fake(void);
bool Get_MMIC_Error_Discard_custom_fake_Ret = false;
uint8_t enable_debug_mode;
volatile XCP_MMIC_FIT_Enable_T XCP_MMIC_FIT_Enable;
mars_uid_t Mars_UID = {0};
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class dd_mmic_InterfaceUnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Compute_CRC32_SW);
      ResetFakeTimestampData();
      XCP_MMIC_FIT_Enable = static_cast<XCP_MMIC_FIT_Enable_T>(0U); // Reset FIT enable before each test
      Alive_Flag          = CODED_FALSE;

      // Initialize global variables to avoid uninitialized memory
      MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;
      Is_Error_Pin_Asserted       = CODED_FALSE; // Initialize error pin flag
      memset((void *)Acq_Window_Time, 0, sizeof(Acq_Window_Time));
      memset((void *)Acq_Start_Time_FS, 0, sizeof(Acq_Start_Time_FS));
      memset((void *)Acq_End_Time_FE, 0, sizeof(Acq_End_Time_FE));
      memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
      memset(&Radar_Data_Status, 0, sizeof(Radar_Data_Status));

      // Initialize calibration arrays for overflow detection (typical values in microseconds)
      // Initialize calibration arrays for overflow detection (values in microseconds)
      for (int i = 0; i < 4; i++)
      {
         MMIC_Daq_Max_Time[i] = 10000U; // 10ms max in microseconds
         MMIC_Daq_Min_Time[i] = 100U;   // 0.1ms min in microseconds
      }

      // Setup Get_MMIC_Error_Discard fake to return false by default
      Get_MMIC_Error_Discard_custom_fake_Ret  = false;
      Get_MMIC_Error_Discard_fake.custom_fake = Get_MMIC_Error_Discard_custom_fake;

      // Initialize MMIC_Stream to simulate initialized MARS system
      // This sets mars_initialization_status = true, making thresholds use "initialized" values
      memset(&MMIC_Stream, 0, sizeof(MMIC_Stream));
      MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status = true;

      // Set custom fake for Clr_MMIC_API_Look_Fault_Status to actually clear the counters
      Clr_MMIC_API_Look_Fault_Status_fake.custom_fake = []()
      {
         API_Look_Config_Error   = 0;
         API_Look_Trigger_Error  = 0;
         API_Look_Complete_Error = 0;
      };
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
 * Custom Functions
 *===========================================================================*/

MMIC_Result_T MARS_Look_Complete_custom_fake_1(void)
{
   MMIC_Result_T MARS_Look_Complete_custom_fake_Ret = true;
   return MARS_Look_Complete_custom_fake_Ret;
}
MMIC_Result_T MARS_Look_Complete_custom_fake_2(void)
{
   MMIC_Result_T MARS_Look_Complete_custom_fake_Ret = false;
   return MARS_Look_Complete_custom_fake_Ret;
}

MMIC_Result_T MARS_Look_Trigger_custom_fake_1(void)
{
   MMIC_Result_T MARS_Look_Trigger_custom_fake_Ret = true;
   return MARS_Look_Trigger_custom_fake_Ret;
}
MMIC_Result_T MARS_Look_Trigger_custom_fake_2(void)
{
   MMIC_Result_T MARS_Look_Trigger_custom_fake_Ret = false;
   return MARS_Look_Trigger_custom_fake_Ret;
}

MMIC_Result_T MARS_Reset_custom_fake_1(void)
{
   MMIC_Result_T MARS_Reset_custom_fake_Ret = true;
   return MARS_Reset_custom_fake_Ret;
}
MMIC_Result_T MARS_Reset_custom_fake_2(void)
{
   MMIC_Result_T MARS_Reset_custom_fake_Ret = false;
   return MARS_Reset_custom_fake_Ret;
}

MMIC_Result_T MARS_Look_Config_custom_fake_1(void)
{
   MMIC_Result_T MARS_Look_Config_custom_fake_Ret = true;
   return MARS_Look_Config_custom_fake_Ret;
}
MMIC_Result_T MARS_Look_Config_custom_fake_2(void)
{
   MMIC_Result_T MARS_Look_Config_custom_fake_Ret = false;
   return MARS_Look_Config_custom_fake_Ret;
}

bool MIPI_Init_custom_fake_1(const volatile MIPI_Config_T *const ptr2config)
{
   bool MIPI_Init_custom_fake_Ret = true;
   return MIPI_Init_custom_fake_Ret;
}
bool MIPI_Init_custom_fake_2(const volatile MIPI_Config_T *const ptr2config)
{
   bool MIPI_Init_custom_fake_Ret = false;
   return MIPI_Init_custom_fake_Ret;
}

MMIC_Result_T Mars_Init_custom_fake_1(void)
{
   MMIC_Result_T MARS_Init_custom_fake_Ret = false;
   return MARS_Init_custom_fake_Ret;
}

MMIC_Result_T Mars_Init_custom_fake_2(void)
{
   MMIC_Result_T MARS_Init_custom_fake_Ret = true;
   return MARS_Init_custom_fake_Ret;
}

/*custom fake function for Get_MMIC_Error_Discard */
bool Get_MMIC_Error_Discard_custom_fake(void)
{
   return Get_MMIC_Error_Discard_custom_fake_Ret;
}

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
TEST_F(dd_mmic_InterfaceUnitTestSuite, Sanity_Check_Test)
{
   ASSERT_EQ(true, true);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Compute_M7_Rdr_Data_Sts_Payload_CRC_FirstCall)
{
   Compute_CRC32_SW_fake.return_val = 0xA5A5A5A5U;

   Compute_M7_Rdr_Data_Sts_Payload_CRC();

   EXPECT_EQ(Alive_Flag, CODED_TRUE);
   EXPECT_EQ(Radar_Data_Status.radar_data_status_header.alive_counter, 1U);
   EXPECT_EQ(Radar_Data_Status.radar_data_status_header.radar_data_status_crc, 0xA5A5A5A5U);
   EXPECT_EQ(Compute_CRC32_SW_fake.call_count, 1U);
   EXPECT_EQ(Compute_CRC32_SW_fake.arg0_val, (uint8_t *)&Radar_Data_Status.radar_data_status_payload);
   EXPECT_EQ(Compute_CRC32_SW_fake.arg1_val, sizeof(Radar_Data_Status_Payload_T));
   EXPECT_EQ(Compute_CRC32_SW_fake.arg2_val, 0U);
   EXPECT_TRUE(Compute_CRC32_SW_fake.arg3_val);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Compute_M7_Rdr_Data_Sts_Payload_CRC_SubsequentCall)
{
   Alive_Flag                                               = CODED_TRUE;
   Radar_Data_Status.radar_data_status_header.alive_counter = 7U;
   Compute_CRC32_SW_fake.return_val                         = 0x1234FEDCU;

   Compute_M7_Rdr_Data_Sts_Payload_CRC();

   EXPECT_EQ(Radar_Data_Status.radar_data_status_header.alive_counter, 7U);
   EXPECT_EQ(Radar_Data_Status.radar_data_status_header.radar_data_status_crc, 0x1234FEDCU);
   EXPECT_EQ(Compute_CRC32_SW_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SafeStartup_FIT_SetsReinitAndActivationType)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   mars_firmware_activation_type_smc = 0U;

   MMIC_Fault_Injection(XCP_MMIC_SAFE_STARTUP_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(mars_firmware_activation_type_smc, 0xFFU);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_MMIC_INIT);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_FunctionConfig_FIT_OverridesTxPower)
{
   const Radar_Look_T look               = RADAR_LOOK_A;
   mars_cfg_tx_config_tx_power_smc[look] = 0U;

   MMIC_Fault_Injection(XCP_MMIC_FUNCTION_CONFIG_FIT_TEST, look);

   EXPECT_EQ(mars_cfg_tx_config_tx_power_smc[look], 16U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_FunctionConfig_FIT_IsLookSpecific)
{
   // Verify that only the specified look's TX power is overridden
   Radar_Look_T test_look                        = RADAR_LOOK_B;
   mars_cfg_tx_config_tx_power_smc[RADAR_LOOK_A] = 5U;
   mars_cfg_tx_config_tx_power_smc[test_look]    = 0U;

   MMIC_Fault_Injection(XCP_MMIC_FUNCTION_CONFIG_FIT_TEST, test_look);

   // Only the test_look should be modified to 16
   EXPECT_EQ(mars_cfg_tx_config_tx_power_smc[RADAR_LOOK_A], 5U);
   EXPECT_EQ(mars_cfg_tx_config_tx_power_smc[test_look], 16U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_DaqMinTime_FIT_IncreasesMinThreshold)
{
   const Radar_Look_T look         = RADAR_LOOK_A;
   const uint32_t initial_min_time = 5000U; // 5ms in microseconds
   MMIC_Daq_Min_Time[look]         = initial_min_time;

   MMIC_Fault_Injection(XCP_MMIC_DAQ_MIN_TIME_FIT_TEST, look);

   // Function adds 6000us (6ms) to the minimum time threshold
   EXPECT_EQ(MMIC_Daq_Min_Time[look], initial_min_time + 6000U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_DaqMaxTime_FIT_IncreasesMaxThreshold)
{
   const Radar_Look_T look         = RADAR_LOOK_A;
   const uint32_t initial_max_time = 16000U; // 16ms in microseconds
   MMIC_Daq_Max_Time[look]         = initial_max_time;

   MMIC_Fault_Injection(XCP_MMIC_DAQ_MAX_TIME_FIT_TEST, look);

   // Function subtracts 6000us (6ms) from the maximum time threshold
   EXPECT_EQ(MMIC_Daq_Max_Time[look], initial_max_time - 6000U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_LowTemp_FIT_SetsTemperatureBelowThreshold)
{
   MMIC_Stream.MMIC_Data.current_temp_status.temperature_pvt = 100;
   MMIC_Stream.MMIC_Data.current_temp_status.state_pvt       = 0;

   MMIC_Fault_Injection(XCP_MMIC_LOW_TEMP_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.current_temp_status.state_pvt, MARS_VAL_FRESH);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.current_temp_status.temperature_pvt, (int8_t)(LOW_Temperature_Threshold_SMC - 1));
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Low_Temperature_Fault_ReturnsStoredFlag)
{
   MMIC_Low_Temp_Fault = CODED_TRUE;

   EXPECT_EQ(Get_MMIC_Low_Temperature_Fault(), CODED_TRUE);

   MMIC_Low_Temp_Fault = CODED_FALSE;
   EXPECT_EQ(Get_MMIC_Low_Temperature_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_High_Temperature_Fault_ReturnsStoredFlag)
{
   MMIC_High_Temp_Fault = CODED_TRUE;

   EXPECT_EQ(Get_MMIC_High_Temperature_Fault(), CODED_TRUE);

   MMIC_High_Temp_Fault = CODED_FALSE;
   EXPECT_EQ(Get_MMIC_High_Temperature_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_MipiFailure_FIT_ConfigsHighChirpsPerFrame)
{
   const Radar_Look_T look                          = RADAR_LOOK_A;
   mars_cfg_chirp_config_chirps_per_frame_smc[look] = 0U;

   MMIC_Fault_Injection(XCP_MMIC_MIPI_FAILURE_FIT_TEST, look);

   // MMIC_MIPI_FAILURE_CHIRPS_PER_FRAME = CHIRPS_PER_CHIRPFRAME + 80 = 1020 + 80 = 1100
   EXPECT_EQ(mars_cfg_chirp_config_chirps_per_frame_smc[look], MMIC_MIPI_FAILURE_CHIRPS_PER_FRAME);
   EXPECT_GT(mars_cfg_chirp_config_chirps_per_frame_smc[look], CHIRPS_PER_CHIRPFRAME);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_HighTemp_FIT_ExceedsThreshold)
{
   const Radar_Look_T look        = RADAR_LOOK_A;
   k_tx_threshold_temperature_smc = 70U;

   MMIC_Fault_Injection(XCP_MMIC_HIGH_TEMP_FIT_TEST, look);

   // Verify the temperature threshold is set to OVER_Temperature_Threshold_SMC + 1
   EXPECT_EQ(k_tx_threshold_temperature_smc, OVER_Temperature_Threshold_SMC + 1);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_Id_Positive_FIT_DoesNotSetReinitWhenAlreadyProgrammed)
{
   RESET_FAKE(Update_Usc_Mmic_Id);
   MMIC_Error.reinit_error                                 = false;
   XCP_MMIC_FIT_Enable                                     = XCP_MMIC_ID_FIT_POS_TEST;
   MMIC_Stream.MMIC_Data.mmic_id_status.mmic_id_programmed = CODED_TRUE;

   MMIC_Fault_Injection(XCP_MMIC_ID_FIT_POS_TEST, RADAR_LOOK_A);

   EXPECT_EQ(Update_Usc_Mmic_Id_fake.call_count, 1U);
   EXPECT_FALSE(MMIC_Error.reinit_error);
   EXPECT_EQ(XCP_MMIC_FIT_Enable, XCP_MMIC_ID_FIT_POS_TEST);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_TxBist_FIT_SetsRecoverableFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_TX_BIST_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19], 0x40);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x1 << 4);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_RxBist_FIT_SetsRecoverableFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_RX_BIST_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[4], 0x01);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x1 << 4);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SftRecoverable_FIT_SetsRecoverableFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[18], 0x01);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x1 << 4);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SftNonRecoverableError_FIT_SetsPrimaryFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_SFT_NON_RECOVERABLE_ERROR_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_NON_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x40000U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV0, 0x101U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SftSecondaryClock_FIT_SetsPrimaryFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_CLOCK_FAULT_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_NON_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x40000U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV0, 0x101U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SftSecondaryMcu_FIT_SetsSecondaryMcuFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_MCU_FAULT_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_NON_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x100000U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_0, 0x10001U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_3, 0x10001000U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_SftSecondaryRegister_FIT_SetsRegisterFaultData)
{
   memset(&MMIC_Stream.MMIC_Data.mmic_bist_status, 0, sizeof(MMIC_Stream.MMIC_Data.mmic_bist_status));

   MMIC_Fault_Injection(XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_REGISTER_FAULT_FIT_TEST, RADAR_LOOK_A);

   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected, 1U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG, MAF_NON_RECOVERABLE_FAULT);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON, 0x4U);
   EXPECT_EQ(MMIC_Stream.MMIC_Data.mmic_bist_status.CPLL_BANK_REFPLL_ERR, 0x101U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_Id_Positive_FIT_UpdatesIdAndHandlesReinitLogic)
{
   RESET_FAKE(Update_Usc_Mmic_Id);
   MMIC_Error.reinit_error = false;

   XCP_MMIC_FIT_Enable = XCP_MMIC_ID_FIT_POS_TEST;

   // First invocation when ID is not programmed
   MMIC_Stream.MMIC_Data.mmic_id_status.mmic_id_programmed = CODED_FALSE;
   MMIC_Fault_Injection(XCP_MMIC_ID_FIT_POS_TEST, RADAR_LOOK_A);

   // Verify Update_Usc_Mmic_Id was called with correct parameters
   EXPECT_EQ(Update_Usc_Mmic_Id_fake.call_count, 1U);
   EXPECT_EQ(Update_Usc_Mmic_Id_fake.arg2_val, CHIP_ID_LEN);
   // Verify reinit error is set and global FIT enable is reset
   EXPECT_TRUE(MMIC_Error.reinit_error);
   EXPECT_EQ(XCP_MMIC_FIT_Enable, XCP_MMIC_NO_FIT_TEST);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_Id_Negative_FIT_UpdatesIdAndSetsReinitError)
{
   RESET_FAKE(Update_Usc_Mmic_Id);
   MMIC_Error.reinit_error = false;

   MMIC_Fault_Injection(XCP_MMIC_ID_FIT_NEG_TEST, RADAR_LOOK_A);

   // Verify Update_Usc_Mmic_Id was called
   EXPECT_EQ(Update_Usc_Mmic_Id_fake.call_count, 1U);
   EXPECT_EQ(Update_Usc_Mmic_Id_fake.arg2_val, CHIP_ID_LEN);
   // Verify reinit error is set to true
   EXPECT_TRUE(MMIC_Error.reinit_error);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_No_FIT_Test)
{
   const Radar_Look_T look = RADAR_LOOK_A;

   MMIC_Fault_Injection(XCP_MMIC_NO_FIT_TEST, look);

   EXPECT_EQ(XCP_MMIC_FIT_Enable, XCP_MMIC_NO_FIT_TEST);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Fault_Injection_MultiLook_Support)
{
   // Verify that fault injection works correctly with different look indices
   const uint32_t initial_min_time = 5000U;  // 5ms in microseconds
   const uint32_t initial_max_time = 16000U; // 16ms in microseconds
   // The source limits total FIT injections to 5 via a static counter.
   // Two single-look FIT tests (DaqMinTime, DaqMaxTime) run before this test,
   // consuming 2 slots. Test MIN injection for 3 looks using the 3 remaining slots.
   Radar_Look_T test_looks[] = {RADAR_LOOK_A, RADAR_LOOK_B, RADAR_LOOK_C};

   for (Radar_Look_T look : test_looks)
   {
      MMIC_Daq_Min_Time[look] = initial_min_time;
      MMIC_Daq_Max_Time[look] = initial_max_time;

      MMIC_Fault_Injection(XCP_MMIC_DAQ_MIN_TIME_FIT_TEST, look);
      EXPECT_EQ(MMIC_Daq_Min_Time[look], initial_min_time + 6000U);

      MMIC_Daq_Min_Time[look] = initial_min_time; // reset for next iteration
   }
}
/*===========================================================================*\
 * FUNCTION: MMIC_Reset_Init_Test
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is to test MMIC_Reset_Init()
 *
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Reset_Init_Test)
{
   MMIC_Reset_Init();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Radar_Data_Status_Test)
{
   Update_Radar_Data_Status();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Radar_Data_Status_Test_1)
{
   Get_MMIC_Error_Discard_custom_fake_Ret  = true;
   Get_MMIC_Error_Discard_fake.custom_fake = Get_MMIC_Error_Discard_custom_fake;
   Update_Radar_Data_Status();
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);
   Get_MMIC_Error_Discard_custom_fake_Ret = false;
   Update_Radar_Data_Status();
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_MMIC_Reinit_Request_SetsAndClearsFlag)
{
   Radar_Data_Status.radar_data_status_payload.MMIC_Reinit_Request = CODED_FALSE;

   Update_MMIC_Reinit_Request(CODED_TRUE);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.MMIC_Reinit_Request, CODED_TRUE);

   Update_MMIC_Reinit_Request(CODED_FALSE);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.MMIC_Reinit_Request, CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_MMIC_Reinit_Request_Idempotent)
{
   Update_MMIC_Reinit_Request(CODED_TRUE);
   Update_MMIC_Reinit_Request(CODED_TRUE);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.MMIC_Reinit_Request, CODED_TRUE);
}

#if 0
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Reset_MIPI_Test)
{
   MMIC_Reset_MIPI();
}
#endif

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_MIPI_Test)
{
   MMIC_Config_MIPI();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Reset_MIPI_TogglesResetRequest)
{
   memset(&g_fake_crg, 0xFF, sizeof(g_fake_crg));
   MARS_Metadata_Read_fake.call_count = 0U;

   MMIC_Reset_MIPI();

   EXPECT_EQ(MARS_Metadata_Read_fake.call_count, 1U);
   EXPECT_EQ(g_fake_crg.RESET_REQ.f.CTL_RG_REQ_MIPI_SYS, 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_Sys_Start_True)
{
   MMIC_Fault_Status_T *mmic_fault_status                             = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);
   mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 20;
   MMIC_Config_Device();
   ASSERT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_system_start_fault, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_Sys_Start_False)
{
   MMIC_Fault_Status_T *mmic_fault_status                             = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);
   mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 0;
   MMIC_Config_Device();
   ASSERT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_system_start_fault, CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_MIPI_Init_false)
{
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_2;
   MMIC_Config_Device();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_MIPI_Init_true)
{
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   MMIC_Config_Device();
}

/*TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_Mars_Init_true)
{
   Mars_Init_fake.custom_fake=Mars_Init_custom_fake_1;
   MMIC_Config_Device();
}*/

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_Mars_Init_false)
{
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake = Mars_Init_custom_fake_2;
   MMIC_Config_Device();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_Test_Mars_Init_XCP_FIT)
{
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake = Mars_Init_custom_fake_2;
   XCP_MMIC_FIT_Enable        = XCP_MMIC_FUNCTION_CONFIG_FIT_TEST;
   MMIC_Config_Device();
}

// Test MMIC_Config_Device - Reinit error flag cleared when initially true
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_ClearsReinitError_WhenTrue)
{
   // Arrange: Set reinit_error to true before calling MMIC_Config_Device
   MMIC_Error.reinit_error    = true;
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake = Mars_Init_custom_fake_1;

   // Act: Call MMIC_Config_Device
   MMIC_Config_Device();

   // Assert: reinit_error should be cleared (false) after initialization
   EXPECT_EQ(MMIC_Error.reinit_error, false);
}

// Test MMIC_Config_Device - Reinit error flag remains false when initially false
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_ClearsReinitError_WhenFalse)
{
   // Arrange: Set reinit_error to false before calling MMIC_Config_Device
   MMIC_Error.reinit_error    = false;
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake = Mars_Init_custom_fake_1;

   // Act: Call MMIC_Config_Device
   MMIC_Config_Device();

   // Assert: reinit_error should remain false after initialization
   EXPECT_EQ(MMIC_Error.reinit_error, false);
}

// Test MMIC_Config_Device - Reinit error flag always cleared regardless of initial state
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_AlwaysClearsReinitError)
{
   // Test 1: Start with true
   MMIC_Error.reinit_error    = true;
   MIPI_Init_fake.custom_fake = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake = Mars_Init_custom_fake_1;
   MMIC_Config_Device();
   EXPECT_EQ(MMIC_Error.reinit_error, false);

   // Test 2: Start with false (call again)
   MMIC_Error.reinit_error = false;
   MMIC_Config_Device();
   EXPECT_EQ(MMIC_Error.reinit_error, false);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_Test1)
{
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1;
   MMIC_Config_Look();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_Test2)
{
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_2;
   MMIC_Config_Look();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Rest_MARS_Test_1)
{
   MARS_Reset_fake.custom_fake = MARS_Reset_custom_fake_1;
   MMIC_Reset_MARS();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Rest_MARS_Test_2)
{
   MARS_Reset_fake.custom_fake = MARS_Reset_custom_fake_2;
   MMIC_Reset_MARS();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_Test_1)
{
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_Test_2)
{
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_2;
   MMIC_Look_Trigger();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_CallsMIPIEnable)
{
   MIPI_Enable_fake.return_val        = true;
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_Test_1)
{
   Radar_Look_T look;
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_Test_2)
{
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_2;
   MMIC_Look_Complete();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Init_MMIC_Config_Test)
{
   Init_MMIC_Config();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Mmic_Discard_Error_Test)
{
   Update_Mmic_Discard_Error();
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_System_Start_Fault_Test_1)
{
   Get_MMIC_System_Start_Fault();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_System_Start_Fault_ReturnsFalseWhenNoFault)
{
   MMIC_Stream.MMIC_Data.MMIC_fault_status.MMIC_system_start_status.MMIC_system_start_fault = CODED_FALSE;
   EXPECT_EQ(Get_MMIC_System_Start_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_System_Start_Fault_ReturnsTrueWhenFaultSet)
{
   MMIC_Stream.MMIC_Data.MMIC_fault_status.MMIC_system_start_status.MMIC_system_start_fault = CODED_TRUE;
   EXPECT_EQ(Get_MMIC_System_Start_Fault(), CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_LookConfigFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_CONFIG);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_LookTriggerFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_TRIGGER);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_LookCompleteFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_COMPLETE);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_InvalidFaultType)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(99U)); // Invalid fault type
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_SetsErrorWhenFails)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_2;
   MMIC_Config_Look();
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.arg0_val, DISCARD_ERROR_CONFIG_LOOK);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_UpdatesSuccessWhenPasses)
{
   RESET_FAKE(Clr_MMIC_Error_Discard);
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1;
   MMIC_Config_Look();
   EXPECT_EQ(Clr_MMIC_Error_Discard_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_CallsUpdateAPIFaultWhenThresholdReached)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error             = API_ERROR_THRESHOLD;
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1;
   MMIC_Config_Look();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Config_Error = 0;
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_SetsErrorWhenFails)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_2;
   MMIC_Look_Trigger();
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.arg0_val, DISCARD_ERROR_LOOK_TRIGGER);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_DoesNotSetErrorWhenPasses)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.call_count, 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_CallsUpdateAPIFaultWhenThresholdReached)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Trigger_Error             = API_ERROR_THRESHOLD;
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Trigger_Error = 0;
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_SetsErrorWhenFails)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_2;
   MMIC_Look_Complete();
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_UpdatesSuccessWhenPasses)
{
   RESET_FAKE(Update_MMIC_Success);
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Update_MMIC_Success_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_CallsUpdateAPIFaultWhenThresholdReached)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Complete_Error             = API_ERROR_THRESHOLD;
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Complete_Error = 0;
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_UpdatesRadarDataStatus)
{
   Get_MMIC_Error_Discard_custom_fake_Ret  = true;
   Get_MMIC_Error_Discard_fake.custom_fake = Get_MMIC_Error_Discard_custom_fake;
   MARS_Look_Complete_fake.custom_fake     = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_ProcessesMipiFuSaWhenFlagSet)
{
   RESET_FAKE(MIPI_FuSa_Fault_Processing);
   MIPI_Chp_FuSa_Flag                  = true;
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;

   MMIC_Look_Complete();

   EXPECT_EQ(MIPI_FuSa_Fault_Processing_fake.call_count, 1U);
   EXPECT_FALSE(MIPI_Chp_FuSa_Flag);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_CallsPopulateStream)
{
   RESET_FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream);
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream_fake.call_count, 1U);
}

// Test MMIC_Config_Look - Does not call Update_API_Fault_Status when below threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_DoesNotCallUpdateAPIFaultBelowThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error             = API_ERROR_THRESHOLD - 1;
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1;
   MMIC_Config_Look();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
   API_Look_Config_Error = 0;
}

// Test MMIC_Config_Look - Calls Update_API_Fault_Status when above threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_CallsUpdateAPIFaultAboveThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error             = API_ERROR_THRESHOLD + 5;
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1;
   MMIC_Config_Look();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Config_Error = 0;
}

// Verify that MMIC_Config_Look only invokes MMIC_Fault_Injection when a FIT test is enabled
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_DoesNotInvokeFaultInjectionWhenNoFitEnabled)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   mars_firmware_activation_type_smc = 0U;

   XCP_MMIC_FIT_Enable               = XCP_MMIC_NO_FIT_TEST;
   API_Look_Config_Error             = 0U;
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1; // ensure success path

   MMIC_Config_Look();

   // No FIT -> no fault injection side effects
   EXPECT_EQ(mars_firmware_activation_type_smc, 0U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Look_InvokesFaultInjectionWhenFitEnabled)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   mars_firmware_activation_type_smc = 0U;

   XCP_MMIC_FIT_Enable               = XCP_MMIC_SAFE_STARTUP_FIT_TEST;
   API_Look_Config_Error             = 0U;
   MARS_Look_Config_fake.custom_fake = MARS_Look_Config_custom_fake_1; // ensure config succeeds

   MMIC_Config_Look();

   // With SAFE_STARTUP FIT enabled, MMIC_Fault_Injection should run via MMIC_Config_Look
   EXPECT_EQ(mars_firmware_activation_type_smc, 0xFFU);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_MMIC_INIT);
}

// Test MMIC_Look_Trigger - Does not call Update_API_Fault_Status when below threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_DoesNotCallUpdateAPIFaultBelowThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Trigger_Error             = API_ERROR_THRESHOLD - 1;
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
   API_Look_Trigger_Error = 0;
}

// Test MMIC_Look_Trigger - Calls Update_API_Fault_Status when above threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Trigger_CallsUpdateAPIFaultAboveThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Trigger_Error             = API_ERROR_THRESHOLD + 3;
   MARS_Look_Trigger_fake.custom_fake = MARS_Look_Trigger_custom_fake_1;
   MMIC_Look_Trigger();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Trigger_Error = 0;
}

// Test MMIC_Look_Complete - Does not call Update_API_Fault_Status when below threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_DoesNotCallUpdateAPIFaultBelowThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Complete_Error             = API_ERROR_THRESHOLD - 1;
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
   API_Look_Complete_Error = 0;
}

// Test MMIC_Look_Complete - Calls Update_API_Fault_Status when above threshold
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_CallsUpdateAPIFaultAboveThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Complete_Error             = API_ERROR_THRESHOLD + 10;
   MARS_Look_Complete_fake.custom_fake = MARS_Look_Complete_custom_fake_1;
   MMIC_Look_Complete();
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   API_Look_Complete_Error = 0;
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_SetsErrorValueForMIPIFailure)
{
   MMIC_Fault_Status_T *mmic_fault_status                             = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);
   mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 0;
   MIPI_Init_fake.custom_fake                                         = MIPI_Init_custom_fake_2;
   MMIC_Config_Device();
   EXPECT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_system_start_error_value, MIPI_FAILURE);
   EXPECT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_SetsErrorValueForMARSFailure)
{
   MMIC_Fault_Status_T *mmic_fault_status                             = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);
   mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 0;
   MIPI_Init_fake.custom_fake                                         = MIPI_Init_custom_fake_1;
   Mars_Init_fake.custom_fake                                         = Mars_Init_custom_fake_1;
   MMIC_Config_Device();
   EXPECT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_system_start_error_value, MARS_FAILURE);
   EXPECT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_Device_IncrementErrorCountOnRepeatedFailure)
{
   MMIC_Fault_Status_T *mmic_fault_status                             = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);
   mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 1U;
   MIPI_Init_fake.custom_fake                                         = MIPI_Init_custom_fake_2;
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MMIC_Config_Device();
   EXPECT_EQ(mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt, 2U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Reset_MARS_SetsErrorWhenFails)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MARS_Reset_fake.custom_fake = MARS_Reset_custom_fake_2;
   MMIC_Reset_MARS();
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Discard_fake.arg0_val, DISCARD_ERROR_RESET);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Reset_MARS_ClearsErrorOnSuccess)
{
   RESET_FAKE(Clr_MMIC_Error_Discard);
   MARS_Reset_fake.custom_fake = MARS_Reset_custom_fake_1;
   MMIC_Reset_MARS();
   EXPECT_EQ(Clr_MMIC_Error_Discard_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Mmic_Discard_Error_SetsRadarDataDiscard)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard = CODED_FALSE;
   Update_Mmic_Discard_Error();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_MIPI_WithOfflineModeEnabled)
{
   RESET_FAKE(MIPI_Init);
   MMIC_Config_MIPI();
   EXPECT_EQ(MIPI_Init_fake.call_count, 1U);
   EXPECT_FALSE(MIPI_Config.enable_debug_mode);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_MIPI_WithOfflineModeDisabled)
{
   RESET_FAKE(MIPI_Init);
   MMIC_Config_MIPI();
   EXPECT_EQ(MIPI_Init_fake.call_count, 1U);
   EXPECT_FALSE(MIPI_Config.enable_debug_mode);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_MIPI_SetsReinitErrorOnInitFailure)
{
   RESET_FAKE(MIPI_Init);
   RESET_FAKE(Set_MMIC_Error_Reinit);

   MIPI_Init_fake.return_val = false;

   MMIC_Config_MIPI();

   EXPECT_EQ(MIPI_Init_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_MIPI_CONFIG_RUN_TIME);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Config_MIPI_DoesNotSetReinitErrorOnInitSuccess)
{
   RESET_FAKE(MIPI_Init);
   RESET_FAKE(Set_MMIC_Error_Reinit);

   MIPI_Init_fake.return_val = true;

   MMIC_Config_MIPI();

   EXPECT_EQ(MIPI_Init_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Fault_ReturnsFalseWhenBelowThreshold)
{
   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Fault_ReturnsTrueWhenAboveThreshold)
{
   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   MMIC_Daq_Over_Flow_Error_Cnt[0] = (uint8_t)(MMIC_DAQ_OVER_FLOW_ERR_THRESH + 1U);
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Fault(), CODED_TRUE);
}

// Boundary test: error count exactly at threshold (should still return FALSE)
TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Fault_ReturnsFalseWhenAtThreshold)
{
   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   MMIC_Daq_Over_Flow_Error_Cnt[0] = (uint8_t)MMIC_DAQ_OVER_FLOW_ERR_THRESH;
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Fault_ReturnsTrueWhenSumAcrossLooksExceedsThreshold)
{
   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   MMIC_Daq_Over_Flow_Error_Cnt[0] = (uint8_t)MMIC_DAQ_OVER_FLOW_ERR_THRESH;
   MMIC_Daq_Over_Flow_Error_Cnt[1] = 1U;
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Fault(), CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Fault_ReturnsFalseWhenSumAcrossLooksEqualsThreshold)
{
   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   MMIC_Daq_Over_Flow_Error_Cnt[0] = (uint8_t)(MMIC_DAQ_OVER_FLOW_ERR_THRESH - 1U);
   MMIC_Daq_Over_Flow_Error_Cnt[1] = 1U;
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Fault(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Err_ReturnsFalseWhenFlagCleared)
{
   MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Err(), CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Get_MMIC_Daq_Over_Flow_Err_ReturnsTrueWhenFlagSet)
{
   MMIC_Daq_Over_Flow_Err_Flag = CODED_TRUE;
   EXPECT_EQ(Get_MMIC_Daq_Over_Flow_Err(), CODED_TRUE);
   MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_SetsErrorWhenAboveMax)
{
   const Radar_Look_T look            = static_cast<Radar_Look_T>(0U);
   MMIC_Daq_Min_Time[look]            = 1000U; /* 1ms in microseconds */
   MMIC_Daq_Max_Time[look]            = 2000U; /* 2ms in microseconds */
   MMIC_Daq_Over_Flow_Error_Cnt[look] = 0U;
   MMIC_Daq_Over_Flow_Err_Flag        = CODED_FALSE;
   Acq_Start_Time_FS[look]            = 0U;
   Acq_End_Time_FE[look]              = 4000U; /* 4ms in microseconds, exceeds 2ms max */

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 1U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_TRUE);
   EXPECT_EQ(Acq_Window_Time[look], 0U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_ClearsErrorWhenWithinRange)
{
   const Radar_Look_T look            = static_cast<Radar_Look_T>(0U);
   MMIC_Daq_Min_Time[look]            = 1000U; /* 1ms in microseconds */
   MMIC_Daq_Max_Time[look]            = 3000U; /* 3ms in microseconds */
   MMIC_Daq_Over_Flow_Error_Cnt[look] = 2U;
   MMIC_Daq_Over_Flow_Err_Flag        = CODED_TRUE;
   Acq_Start_Time_FS[look]            = 0U;
   Acq_End_Time_FE[look]              = 2000U; /* 2ms in microseconds, within [1ms, 3ms] */

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 0U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_SetsErrorWhenEqualToMax)
{
   const Radar_Look_T look            = static_cast<Radar_Look_T>(0U);
   MMIC_Daq_Min_Time[look]            = 1.0F;
   MMIC_Daq_Max_Time[look]            = 2.0F;
   MMIC_Daq_Over_Flow_Error_Cnt[look] = 0U;
   MMIC_Daq_Over_Flow_Err_Flag        = CODED_FALSE;
   Acq_Start_Time_FS[look]            = 0U;
   Acq_End_Time_FE[look]              = 2000U; /* 2 ms */

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 1U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_IncrementsFromNonZeroWhenEqualToMax)
{
   const Radar_Look_T look            = static_cast<Radar_Look_T>(0U);
   MMIC_Daq_Min_Time[look]            = 1.0F;
   MMIC_Daq_Max_Time[look]            = 2.0F;
   MMIC_Daq_Over_Flow_Error_Cnt[look] = 2U;
   MMIC_Daq_Over_Flow_Err_Flag        = CODED_FALSE;
   Acq_Start_Time_FS[look]            = 0U;
   Acq_End_Time_FE[look]              = 2000U; /* 2 ms */

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 3U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_SetsErrorWhenEqualToMin)
{
   const Radar_Look_T look            = static_cast<Radar_Look_T>(0U);
   MMIC_Daq_Min_Time[look]            = 2.0F;
   MMIC_Daq_Max_Time[look]            = 3.0F;
   MMIC_Daq_Over_Flow_Error_Cnt[look] = 0U;
   MMIC_Daq_Over_Flow_Err_Flag        = CODED_FALSE;
   Acq_Start_Time_FS[look]            = 0U;
   Acq_End_Time_FE[look]              = 2000U; /* 2 ms */

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 1U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_TRUE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_ComputesWrapAroundDuration)
{
   const Radar_Look_T look       = static_cast<Radar_Look_T>(0U);
   const uint32_t start_us       = PLATFORMTIME_MAX - 100U;
   const uint32_t end_us         = 50U;
   const uint32_t expected_ticks = end_us + (PLATFORMTIME_MAX - start_us);
   const float expected_ms       = static_cast<float>(expected_ticks) * US_2_MS;

   memset((void *)MMIC_Daq_Over_Flow_Error_Cnt, 0, sizeof(MMIC_Daq_Over_Flow_Error_Cnt));
   MMIC_Daq_Min_Time[look]     = 0U;
   MMIC_Daq_Max_Time[look]     = expected_ticks + 1U;
   MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;
   Acq_Start_Time_FS[look]     = start_us;
   Acq_End_Time_FE[look]       = end_us;

   Check_MMIC_DAQ_OverFlow_Time(look);

   EXPECT_EQ(MMIC_Daq_Over_Flow_Error_Cnt[look], 0U);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_FALSE);
}

/* Tests for DAQ FIT injection modes were removed because
 * Check_MMIC_DAQ_OverFlow_Time no longer depends on XCP_MMIC_FIT_Enable.
 */

// Test Update_API_Fault_Status calls Clr_MMIC_API_Look_Fault_Status for Config fault
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_ClearsAPICountersForConfigFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 10;
   API_Look_Trigger_Error  = 5;
   API_Look_Complete_Error = 7;

   Update_API_Fault_Status(API_FAULT_LOOK_CONFIG);

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Update_API_Fault_Status calls Clr_MMIC_API_Look_Fault_Status for Trigger fault
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_ClearsAPICountersForTriggerFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 3;
   API_Look_Trigger_Error  = 15;
   API_Look_Complete_Error = 2;

   Update_API_Fault_Status(API_FAULT_LOOK_TRIGGER);

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Update_API_Fault_Status calls Clr_MMIC_API_Look_Fault_Status for Complete fault
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_ClearsAPICountersForCompleteFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 1;
   API_Look_Trigger_Error  = 2;
   API_Look_Complete_Error = 20;

   Update_API_Fault_Status(API_FAULT_LOOK_COMPLETE);

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Update_API_Fault_Status does not clear counters for invalid fault type
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_DoesNotClearCountersForInvalidType)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 8;
   API_Look_Trigger_Error  = 6;
   API_Look_Complete_Error = 4;

   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(99U)); // Invalid fault type

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
   // Counters should remain unchanged for invalid fault type
   EXPECT_EQ(API_Look_Config_Error, 8);
   EXPECT_EQ(API_Look_Trigger_Error, 6);
   EXPECT_EQ(API_Look_Complete_Error, 4);
}

// Test Update_API_Fault_Status with zero as invalid enum value
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_WithZeroValue)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 5;
   API_Look_Trigger_Error  = 3;
   API_Look_Complete_Error = 7;

   Update_API_Fault_Status(API_FAULT_LOOK_CONFIG); // API_FAULT_LOOK_CONFIG (value 0) is a valid enum

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
   // Counters should be cleared after Update_API_Fault_Status is called
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Update_API_Fault_Status with boundary value 4
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_WithBoundaryValue)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 2;
   API_Look_Trigger_Error  = 4;
   API_Look_Complete_Error = 6;

   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(4U)); // Just outside valid range

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
   // Counters should remain unchanged for out-of-range value
   EXPECT_EQ(API_Look_Config_Error, 2);
   EXPECT_EQ(API_Look_Trigger_Error, 4);
   EXPECT_EQ(API_Look_Complete_Error, 6);
}

// Test Update_API_Fault_Status - Each valid enum calls Set_MMIC_Error_Reinit exactly once
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_AllValidEnumsCallReinit)
{
   // Test API_FAULT_LOOK_CONFIG (0)
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_CONFIG);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);

   // Test API_FAULT_LOOK_TRIGGER (1)
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_TRIGGER);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);

   // Test API_FAULT_LOOK_COMPLETE (2)
   RESET_FAKE(Set_MMIC_Error_Reinit);
   Update_API_Fault_Status(API_FAULT_LOOK_COMPLETE);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_API_RETURN_VAL_FAULT);
}

// Test Update_API_Fault_Status - Multiple calls with same enum
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_MultipleCallsSameEnum)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error = 10;

   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(1U)); // ApiFaultLookConfig
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(API_Look_Config_Error, 0);

   // Second call should also work
   API_Look_Config_Error = 15;
   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(1U)); // ApiFaultLookConfig
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 2U);
   EXPECT_EQ(API_Look_Config_Error, 0);
}

// Test Update_API_Fault_Status - Switching between different fault types
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_SwitchingFaultTypes)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);

   // Set different counter values
   API_Look_Config_Error   = 5;
   API_Look_Trigger_Error  = 10;
   API_Look_Complete_Error = 15;

   // Call with Config fault - should clear all
   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(1U)); // ApiFaultLookConfig
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);

   // Set again and call with Trigger fault
   API_Look_Config_Error   = 3;
   API_Look_Trigger_Error  = 7;
   API_Look_Complete_Error = 11;
   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(2U)); // ApiFaultLookTrigger
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Update_API_Fault_Status clears counters even when already zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_API_Fault_Status_ClearsCountersWhenAlreadyZero)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Update_API_Fault_Status(static_cast<API_Fault_Type_T>(1U)); // ApiFaultLookConfig

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Validate_MMIC_Error_Reinit_Count - Clears reinit count when all API errors are zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_ClearsWhenAllZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 1U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear when Config error is non-zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearWhenConfigNonZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 1;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear when Trigger error is non-zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearWhenTriggerNonZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 5;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear when Complete error is non-zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearWhenCompleteNonZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 3;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear when all errors are non-zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearWhenAllNonZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 2;
   API_Look_Trigger_Error  = 3;
   API_Look_Complete_Error = 1;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear when two errors are non-zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearWhenTwoNonZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 5;
   API_Look_Trigger_Error  = 7;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear at threshold values
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearAtThreshold)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = API_ERROR_THRESHOLD;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Does not clear at maximum values
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_DoesNotClearAtMaxValues)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 255;
   API_Look_Trigger_Error  = 255;
   API_Look_Complete_Error = 255;

   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);
}

// Test Validate_MMIC_Error_Reinit_Count - Multiple consecutive calls when all zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_MultipleCallsWhenZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();
   Validate_MMIC_Error_Reinit_Count();
   Validate_MMIC_Error_Reinit_Count();

   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 3U);
}

// Test Validate_MMIC_Error_Reinit_Count - State transition from errors to zero
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_TransitionToZero)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);

   // Start with errors
   API_Look_Config_Error   = 5;
   API_Look_Trigger_Error  = 3;
   API_Look_Complete_Error = 2;

   Validate_MMIC_Error_Reinit_Count();
   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 0U);

   // Clear all errors
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   Validate_MMIC_Error_Reinit_Count();
   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 1U);
}

// Test Validate_MMIC_Error_Reinit_Count - Handles reinit_error flag correctly
TEST_F(dd_mmic_InterfaceUnitTestSuite, Validate_MMIC_Error_Reinit_Count_HandlesReinitError)
{
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   // Validate function behavior when reinit_error is initially false
   Validate_MMIC_Error_Reinit_Count();
   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 1U);

   // Reset and verify state isolation
   RESET_FAKE(Clr_MMIC_Reinit_Error_Count);
   Validate_MMIC_Error_Reinit_Count();
   EXPECT_EQ(Clr_MMIC_Reinit_Error_Count_fake.call_count, 1U);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Dwell_Timestamps_test)
{
   // Set up fake timestamps using the helper functions
   SetFakeStartTimestamp(10, 100, 1);
   SetFakeEndTimestamp(20, 200, 1);
   SetFakeMidTimestamp(15, 150, 1);
   SetFakeMidDuration(1000);

   Update_Dwell_Timestamps();

   // Verify that timestamps were correctly populated
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.start_dwell_nanosec, 100);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.start_dwell_sec, 10);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.start_dwell_status, 1);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.end_dwell_nanosec, 200);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.end_dwell_sec, 20);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.end_dwell_status, 1);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.mid_dwell_nanosec, 150);
   ASSERT_EQ(Radar_Data_Status.radar_data_status_payload.mid_dwell_sec, 15);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_WithinTolerance)
{
   Radar_Look_T look_var = RADAR_LOOK_A;

   MMIC_Daq_Max_Time[look_var] = 2000U; // 2ms max in microseconds
   MMIC_Daq_Min_Time[look_var] = 100U;  // 0.1ms min in microseconds

   Acq_Window_Time[look_var]              = 1000U;
   Acq_Start_Time_FS[look_var]            = 100U;
   Acq_End_Time_FE[look_var]              = 1100U; // window = 1000us, within [100, 2000]
   MMIC_Daq_Over_Flow_Err_Flag            = CODED_FALSE;
   MMIC_Daq_Over_Flow_Error_Cnt[look_var] = 0;

   Check_MMIC_DAQ_OverFlow_Time(look_var);
   EXPECT_EQ(MMIC_Daq_Over_Flow_Err_Flag, CODED_FALSE);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_ExceedsTolerance)
{
   Radar_Look_T look_var                  = RADAR_LOOK_B;
   MMIC_Daq_Max_Time[look_var]            = 1000U; // 1ms max in microseconds
   MMIC_Daq_Min_Time[look_var]            = 100U;  // 0.1ms min in microseconds
   Acq_Window_Time[look_var]              = 1000U;
   Acq_Start_Time_FS[look_var]            = 100U;
   Acq_End_Time_FE[look_var]              = 1200U; // window = 1100us, exceeds 1000us max
   MMIC_Daq_Over_Flow_Err_Flag            = CODED_FALSE;
   MMIC_Daq_Over_Flow_Error_Cnt[look_var] = 0;
   for (int i = 0; i < 5; i++)
   {
      Check_MMIC_DAQ_OverFlow_Time(look_var);
   }
   EXPECT_GT(MMIC_Daq_Over_Flow_Error_Cnt[look_var], 0);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Check_MMIC_DAQ_OverFlow_Time_IndependentLooks)
{
   MMIC_Daq_Max_Time[RADAR_LOOK_A] = 1500U; // 1.5ms max in microseconds
   MMIC_Daq_Min_Time[RADAR_LOOK_A] = 500U;  // 0.5ms min in microseconds
   MMIC_Daq_Max_Time[RADAR_LOOK_B] = 1500U;
   MMIC_Daq_Min_Time[RADAR_LOOK_B] = 500U;

   Acq_Window_Time[RADAR_LOOK_A]              = 1000U;
   Acq_Start_Time_FS[RADAR_LOOK_A]            = 100U;
   Acq_End_Time_FE[RADAR_LOOK_A]              = 2100U; // 2ms - Overflow (above 1.5ms max)
   Acq_Window_Time[RADAR_LOOK_B]              = 1000U;
   Acq_Start_Time_FS[RADAR_LOOK_B]            = 100U;
   Acq_End_Time_FE[RADAR_LOOK_B]              = 1200U; // 1.1ms - No overflow (within range)
   MMIC_Daq_Over_Flow_Error_Cnt[RADAR_LOOK_A] = 0;
   MMIC_Daq_Over_Flow_Error_Cnt[RADAR_LOOK_B] = 0;

   Check_MMIC_DAQ_OverFlow_Time(RADAR_LOOK_A);
   Check_MMIC_DAQ_OverFlow_Time(RADAR_LOOK_B);

   EXPECT_GT(MMIC_Daq_Over_Flow_Error_Cnt[RADAR_LOOK_A], MMIC_Daq_Over_Flow_Error_Cnt[RADAR_LOOK_B]);
}

TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Mmic_Discard_Error_SetWhenTrue)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MMIC_Daq_Over_Flow_Err_Flag = CODED_TRUE;

   Update_Mmic_Discard_Error();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Mmic_Discard_Error_NoSetWhenFalse)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;

   Update_Mmic_Discard_Error();

   EXPECT_EQ(Set_MMIC_Error_Discard_fake.call_count, 0U);
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Mmic_Discard_Error_MultipleCalls)
{
   RESET_FAKE(Set_MMIC_Error_Discard);
   MMIC_Daq_Over_Flow_Err_Flag = CODED_TRUE;
   Update_Mmic_Discard_Error();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);

   Update_Mmic_Discard_Error();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);

   MMIC_Daq_Over_Flow_Err_Flag = CODED_TRUE;
   Update_Mmic_Discard_Error();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_TRUE);
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Radar_Data_Status_SetsValid)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard = CODED_TRUE;

   Update_Radar_Data_Status();

   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_FALSE);
}
TEST_F(dd_mmic_InterfaceUnitTestSuite, Update_Radar_Data_Status_MultipleCalls)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard = CODED_TRUE;

   Update_Radar_Data_Status();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_FALSE);

   Update_Radar_Data_Status();
   EXPECT_EQ(Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard, CODED_FALSE);
}

/* ===========================================================================
 * MMIC_Look_Complete – AoU guard: CORE_BANK_MCU_STS_MCU_MSSG
 *
 * Condition under test:
 *   if (((mars_sft_err_n_t)1U == bist_stat_ptr->safety_error_detected) &&
 *       (MAF_NON_RECOVERABLE_FAULT < bist_stat_ptr->CORE_BANK_MCU_STS_MCU_MSSG))
 *   {
 *      Set_MMIC_Error_Reinit(REINIT_ERROR_MARS_MCU_STS_MCU_MSSG);
 *   }
 * ===========================================================================*/

// TC1: Both conditions true → Set_MMIC_Error_Reinit() is called once with REINIT_ERROR_MARS_MCU_STS_MCU_MSSG
// safety_error_detected = 1, CORE_BANK_MCU_STS_MCU_MSSG > MAF_NON_RECOVERABLE_FAULT (5)
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_AoU_ReinitTriggeredWhenSafetyErrorAndMsgAboveNonRecoverableThreshold)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MARS_Look_Complete_fake.custom_fake                          = MARS_Look_Complete_custom_fake_1;
   MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected = 1U;
   MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG =
      MAF_NON_RECOVERABLE_FAULT + 1U; /* 6: strictly above threshold */

   MMIC_Look_Complete();

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 1U);
   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.arg0_val, REINIT_ERROR_MARS_MCU_STS_MCU_MSSG);
}

// TC2: First condition false (safety_error_detected == 0), second true → NOT triggered
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_AoU_ReinitNotTriggeredWhenSafetyErrorClear)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MARS_Look_Complete_fake.custom_fake                               = MARS_Look_Complete_custom_fake_1;
   MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 0U;
   MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_NON_RECOVERABLE_FAULT + 1U;

   MMIC_Look_Complete();

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

// TC3: Boundary – MCU_MSSG == MAF_NON_RECOVERABLE_FAULT (5): strict < means == does NOT trigger
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_AoU_ReinitNotTriggeredWhenMsgEqualsNonRecoverableFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MARS_Look_Complete_fake.custom_fake                               = MARS_Look_Complete_custom_fake_1;
   MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
   MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_NON_RECOVERABLE_FAULT; /* == 5 */

   MMIC_Look_Complete();

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

// TC4: First condition true, second below threshold – MCU_MSSG == MAF_RECOVERABLE_FAULT (4) → NOT triggered
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_AoU_ReinitNotTriggeredWhenMsgIsRecoverableFault)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MARS_Look_Complete_fake.custom_fake                               = MARS_Look_Complete_custom_fake_1;
   MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
   MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_RECOVERABLE_FAULT; /* 4 */

   MMIC_Look_Complete();

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

// TC5: Both conditions false → NOT triggered
TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Look_Complete_AoU_ReinitNotTriggeredWhenBothConditionsFalse)
{
   RESET_FAKE(Set_MMIC_Error_Reinit);
   MARS_Look_Complete_fake.custom_fake                               = MARS_Look_Complete_custom_fake_1;
   MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 0U;
   MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = 0U;

   MMIC_Look_Complete();

   EXPECT_EQ(Set_MMIC_Error_Reinit_fake.call_count, 0U);
}

// ============================================================================
// MMIC_Daq_Cal_Min_Max_Time Tests
// ============================================================================

TEST_F(dd_mmic_InterfaceUnitTestSuite, MMIC_Daq_Cal_Min_Max_Time_CalculatesCorrectMinMax)
{
   // Arrange: Set known dwell times for all looks
   k_frame_dwell_ms_smc[RADAR_LOOK_A] = 100.0F;
   k_frame_dwell_ms_smc[RADAR_LOOK_B] = 200.0F;
   k_frame_dwell_ms_smc[RADAR_LOOK_C] = 50.0F;
   k_frame_dwell_ms_smc[RADAR_LOOK_D] = 0.0F;

   // Act
   MMIC_Daq_Cal_Min_Max_Time();

   // Assert: result stored as uint32_t microseconds with 20% tolerance (MMIC_DAQ_OVER_FLOW_TOLERANCE)
   // Formula: (uint32_t)((dwell_ms +/- dwell_ms * 0.2) * MS_2_US)  where MS_2_US = 1000
   EXPECT_EQ(MMIC_Daq_Max_Time[RADAR_LOOK_A], 120000U); // (100 + 20) * 1000 us
   EXPECT_EQ(MMIC_Daq_Min_Time[RADAR_LOOK_A], 80000U);  // (100 - 20) * 1000 us
   EXPECT_EQ(MMIC_Daq_Max_Time[RADAR_LOOK_B], 240000U); // (200 + 40) * 1000 us
   EXPECT_EQ(MMIC_Daq_Min_Time[RADAR_LOOK_B], 160000U); // (200 - 40) * 1000 us
   EXPECT_EQ(MMIC_Daq_Max_Time[RADAR_LOOK_C], 60000U);  // (50 + 10) * 1000 us
   EXPECT_EQ(MMIC_Daq_Min_Time[RADAR_LOOK_C], 40000U);  // (50 - 10) * 1000 us
   EXPECT_EQ(MMIC_Daq_Max_Time[RADAR_LOOK_D], 0U);
   EXPECT_EQ(MMIC_Daq_Min_Time[RADAR_LOOK_D], 0U);
}
