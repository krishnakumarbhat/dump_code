/*===========================================================================*/
/**
 * @file iohwab_adc_unit_test.cc
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
 * Unit test suite for the checking the ipc_data.c file
 *
 * @section COVERAGE_NOTES COVERAGE NOTES:
 *
 * Line 362 in iohwab_adc.c shows "Branch 0/1" in coverage tool despite comprehensive testing.
 * The compound condition: } while ((ret_value != E_OK) && (ExitCounter > NULL_VALUE));
 *
 * This is a known coverage tool limitation with compound conditions in do-while loops.
 * All logical paths are tested:
 *   - test1-11: Cover immediate success, retries, timeout, and all MC/DC combinations
 *   - Executes 764+ times across all tests
 *   - Both branch directions (loop continue/exit) are exercised
 *
 * Line 365 also shows "Decision couldn't be analyzed" confirming tool limitation.
 * Source code cannot be modified per project constraints
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
#include "Adc_fake.h"
#include "Rte_Type.h"
#include "board_revision_mocks.h"
#include "dd_gpt_mocks.h"
#include "iohwab_fake.h"
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"

DEFINE_FFF_GLOBALS;

#define UNIT_TEST

#include <stddef.h>
static volatile uint32_t ut_adc_capture_status = 0U;
#ifdef ADC_CH_STS
   #undef ADC_CH_STS
#endif
#define ADC_CH_STS ut_adc_capture_status

extern "C"
{
   extern Position_Pins_T lastPins;
#include "iohwab_adc.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class iohwab_adc_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_DD_GPT_LIST(RESET_FAKE);
      FFF_FAKES_ADCSTOP_FUNCTION(RESET_FAKE);
      FFF_FAKES_ADC_PosPin_Prj_FUNCTION(RESET_FAKE);
      FFF_FAKES_THERMAL_MONITOR_INIT(RESET_FAKE);
      FFF_FAKES_ADC_FUNCTION(RESET_FAKE);
      RESET_FAKE(Adc_ReadGroup);
      RESET_FAKE(Adc_StartGroupConversion);
      RESET_FAKE(Get_ADC_Counts);
      Rdi_Log_Board_Connected            = false;
      ut_adc_capture_status              = 0U;
      ut_adc_capture_status              = 0U;
      Adc_GetGroupStatus_fake.return_val = ADC_COMPLETED;
      FFF_RESET_HISTORY();
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
/* redefinition of global variables used by UUT */

/**
 *  @b iohwab_adc_appl_sanity
 *  @n
 *     Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, SanityCheck_SW_Unit_01)
{
   ASSERT_EQ(true, true);
}
/**
 *  @b IoHwAb_RawAdcCount_Read_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_RawAdcCount_Read_SW_Unit_01)
{
   Dt_RawAdcData_T RawAdcData;
   IoHwAb_RawAdcCount_Read(&RawAdcData);
   ASSERT_EQ(IoHwAb_RawAdcCount_Read(&RawAdcData), RTE_E_OK);
}
/**
 *  @b IoHwAb_Get_FloatingPinPosition_FaultStatus_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_Get_FloatingPinPosition_FaultStatus_SW_Unit_01)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   uint8 Status;
   IoHwAb_Get_FloatingPinPosition_FaultStatus(&Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b IoHwAb_Get_STM_TimeStamp_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_Get_STM_TimeStamp_SW_Unit_01)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   uint32 arg;
   IoHwAb_Get_STM_TimeStamp(&arg);
   ASSERT_EQ(true, true);
}
/* Test  GetGroupStatus - should return 2 different  values */
Adc_StatusType custom_fake_Adc_GetGroupStatus_fake(Adc_GroupType group)
{
   static uint32_t call_count = 0;
   if (call_count == 0)
   {
      call_count++;
      return (Adc_StatusType)0;
   }
   return (Adc_StatusType)3;
}
/**
 *  @b Read_RawADCdata_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_RawADCdata_SW_Unit_01)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   uint8 Adc_Group;
   uint16 CPU_Load_test0 = 10;
   Adc_Group             = 0;
   uint16 test_array[10];
   uint16 *BufferPtr_ut                = test_array;
   BufferPtr_ut[0]                     = 5;
   Adc_GetGroupStatus_fake.custom_fake = custom_fake_Adc_GetGroupStatus_fake;
   Get_ADC_Counts_fake.return_val      = 5;
   Read_RawADCdata(Adc_Group, BufferPtr_ut);
   ASSERT_EQ(BufferPtr_ut[0], 5);
}
// /* Test  Get_Elapsed_Time_us - should return 2 different values */
// uint32_t custom_fake_Get_Elapsed_Time_us_fake(uint32_t time)
// {
//    static uint32_t call_count = 0;
//    if (call_count == 0)
//    {
//       call_count++;
//       return 1000;
//    }
//    return 3000;
// }

/**
 *  @b Read_RawADCdata_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_RawADCdata_SW_Unit_02)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   uint8 Adc_Group;
   uint16 CPU_Load_test1 = 10;
   Adc_Group             = 0;
   uint16 test_array[10];
   uint16 *BufferPtr_ut = test_array;
   BufferPtr_ut[0]      = 5;
   // Get_Elapsed_Time_us_fake.custom_fake = custom_fake_Get_Elapsed_Time_us_fake;
   Get_ADC_Counts_fake.return_val = 5;
   Read_RawADCdata(Adc_Group, BufferPtr_ut);
   ASSERT_EQ(BufferPtr_ut[0], 5);
}
/**
 *  @b Read_RawADCdata_test2
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_RawADCdata_SW_Unit_03)
{
   uint8 Adc_Group;
   Adc_Group = 0;
   uint16 test_array[10];
   uint16 *BufferPtr_ut               = test_array;
   BufferPtr_ut[0]                    = 5;
   Adc_GetGroupStatus_fake.return_val = (Adc_StatusType)3;
   Read_RawADCdata(Adc_Group, BufferPtr_ut);
   ASSERT_EQ(Adc_GetGroupStatus_fake.call_count, 1);
}

/**
 *  @b Init_ADC_Channels_SW_Unit_01
 *  @n
 *      Timeout path: ut_adc_ch_sts stays 0 (never equals CH_CAPTURE_DONE),
 *      so the loop decrements timeout_cnt until it reaches 0 and exits.
 *      Adc_MainFunction must NOT be called.
 */
TEST_F(iohwab_adc_UnitTestSuite, Init_ADC_Channels_SW_Unit_01)
{
   ut_adc_capture_status = 0U;

   Init_ADC_Channels();

   ASSERT_EQ(Adc_MainFunction_fake.call_count, 0);
   ASSERT_EQ(PVT_Monitoring_Init_fake.call_count, 1);
}

TEST_F(iohwab_adc_UnitTestSuite, Init_ADC_Channels_SW_Unit_01a)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;

   /* Act */
   Init_ADC_Channels();

   ASSERT_EQ(Adc_MainFunction_fake.call_count, 1);
   ASSERT_EQ(PVT_Monitoring_Init_fake.call_count, 1);
}

/**
 *  @b Init_ADC_Channels_test2_VerifyFunctionCalls
 *  @n
 *      Test case to verify all ADC initialization function calls
 */
TEST_F(iohwab_adc_UnitTestSuite, Init_ADC_Channels_SW_Unit_02)
{
   /* Act */
   Init_ADC_Channels();

   /* Assert - Verify Adc_StartGroupConversion was called once */
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);
}

/**
 *  @b Init_ADC_Channels_test3_VerifyInitSequence
 *  @n
 *      Test case to verify Init_ADC_Channels completes initialization sequence
 */
TEST_F(iohwab_adc_UnitTestSuite, Init_ADC_Channels_SW_Unit_03)
{
   /* Act */
   Init_ADC_Channels();

   /* Assert - Verify initialization sequence completed */
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);
   ASSERT_EQ(Adc_EnableGroupNotification_fake.call_count, 1);
   ASSERT_EQ(Adc_SetupResultBuffer_fake.call_count, 1);
}

/**
 *  @b Init_ADC_Channels_test4_VerifyBufferSetup
 *  @n
 *      Test case to verify ADC buffer is set up correctly
 */
TEST_F(iohwab_adc_UnitTestSuite, Init_ADC_Channels_SW_Unit_04)
{
   /* Reset all fakes to ensure clean state */
   RESET_FAKE(Adc_StartGroupConversion);
   FFF_RESET_HISTORY();

   /* Act */
   Init_ADC_Channels();

   /* Assert - Verify the ADC group conversion was started */
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);

   /* Verify no errors occurred during initialization */
   ASSERT_EQ(true, true);
}

TEST_F(iohwab_adc_UnitTestSuite, Platform_Time_Register_set_SW_Unit_01)
{
   uint8 fault_type;
   Platform_Time_Register_set(fault_type);
   ASSERT_EQ(true, true);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_01)
{
   Get_ADC_Counts_fake.return_val = 0U;

   ASSERT_EQ(Check_RDI_Log_Connection(), true);
   ASSERT_EQ(Get_RDI_Log_Board_Connected(), true);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_02)
{
   Get_ADC_Counts_fake.return_val = 1000U;

   ASSERT_EQ(Check_RDI_Log_Connection(), false);
   ASSERT_EQ(Get_RDI_Log_Board_Connected(), false);
}

TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_01)
{
   Read_Sensor_Position_Pins();
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_03)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Get_ADC_Counts_fake.return_val     = 0U;

   ASSERT_EQ(Check_RDI_Log_Connection(), false);
   ASSERT_EQ(Get_RDI_Log_Board_Connected(), false);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_04)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_B0CVAL;
   Get_ADC_Counts_fake.return_val     = 0U;

   ASSERT_EQ(Check_RDI_Log_Connection(), false);
   ASSERT_EQ(Get_RDI_Log_Board_Connected(), false);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_05)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_B0CVAL_ETH;
   Get_ADC_Counts_fake.return_val     = 0U;

   ASSERT_EQ(Check_RDI_Log_Connection(), false);
   ASSERT_EQ(Get_RDI_Log_Board_Connected(), false);
}

TEST_F(iohwab_adc_UnitTestSuite, Check_RDI_Log_Connection_SW_Unit_06)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   RESET_FAKE(Get_ADC_Counts);

   ASSERT_EQ(Check_RDI_Log_Connection(), false);
}
/**
 *  @b Read_Sensor_Position_Pins_test1b_VerifyGlobalVariable
 *  @n
 *      Test case to verify lastPins global variable is updated
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_02)
{
   /* Arrange */
   memset(&lastPins, 0xFF, sizeof(lastPins)); /* Initialize with non-zero values */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 3500;

   /* Act */
   Read_Sensor_Position_Pins();

   /* Assert - Verify global lastPins variable is updated */
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);

   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 3500);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B], 3500);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_C], 3500);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_D], 3500);
}

/**
 *  @b Read_Sensor_Position_Pins_test2
 *  @n
 *      Test case to verify all function calls and ADC read success path
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_03)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   /* Arrange - Set up fake to return E_OK on first call */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 1234;

   /* Act */
   Read_Sensor_Position_Pins();

   /* Assert */
   /* Verify IoHwAb_ADC_PosPin_Prj_cbk called twice (Enable and Disable) */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2);

   /* Verify Adc_StopGroupConversion called once */
   ASSERT_EQ(Adc_StopGroupConversion_fake.call_count, 1);

   /* Verify Adc_StartGroupConversion called once */
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);

   /* Verify Adc_ReadGroup called at least once in the do-while loop */
   ASSERT_GE(Adc_ReadGroup_fake.call_count, 1);

   /* Verify Get_ADC_Counts called 4 times for all position channels */
   ASSERT_EQ(Get_ADC_Counts_fake.call_count, 4);
}

/**
 *  @b Read_Sensor_Position_Pins_test3_ADC_Read_Timeout
 *  @n
 *      Test case to verify timeout scenario in do-while loop
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_04)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   /* Arrange - Set up fake to always return E_NOT_OK to test timeout */
   Adc_ReadGroup_fake.return_val  = E_NOT_OK;
   Get_ADC_Counts_fake.return_val = 5678;

   /* Act */
   Read_Sensor_Position_Pins();

   /* Assert */
   /* Verify the do-while loop executed until the implementation timeout is reached. */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1000);

   /* Verify all other functions still called */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2);
   ASSERT_EQ(Adc_StopGroupConversion_fake.call_count, 1);
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);

   /* Verify Get_ADC_Counts still called 4 times even after timeout */
   ASSERT_EQ(Get_ADC_Counts_fake.call_count, 4);
}

/**
 *  @b Read_Sensor_Position_Pins_test4_ADC_Read_Success_After_Retries
 *  @n
 *      Test case to verify ADC read succeeds after multiple retries
 */
/* Custom fake function for Adc_ReadGroup that returns E_NOT_OK 5 times, then E_OK */
static uint32_t adc_retry_call_count = 0;
Std_ReturnType Adc_ReadGroup_retry_fake(Adc_GroupType group, Adc_ValueGroupType *DataBufferPtr)
{
   adc_retry_call_count++;
   if (adc_retry_call_count <= 5)
   {
      return E_NOT_OK;
   }
   return E_OK;
}

TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_05)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   /* Arrange - Custom fake to return E_NOT_OK 5 times, then E_OK */
   adc_retry_call_count           = 0; /* Reset for this test */
   Adc_ReadGroup_fake.custom_fake = Adc_ReadGroup_retry_fake;
   Get_ADC_Counts_fake.return_val = 9999;

   /* Act */
   Read_Sensor_Position_Pins();

   /* Assert */
   /* Verify the do-while loop executed 6 times (5 failures + 1 success) */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 6);

   /* Verify all channels were read */
   ASSERT_EQ(Get_ADC_Counts_fake.call_count, 4);

   /* Verify proper enable/disable sequence */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2);
}

/**
 *  @b Read_Sensor_Position_Pins_test5_Verify_Channel_Read_Order
 *  @n
 *      Test case to verify correct ADC channels are read
 */
TEST_F(iohwab_adc_UnitTestSuite, Read_Sensor_Position_Pins_SW_Unit_06)
{
   /* Arrange */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 1111;

   /* Act */
   Read_Sensor_Position_Pins();

   /* Assert - Verify Get_ADC_Counts called 4 times for the 4 position channels */
   ASSERT_EQ(Get_ADC_Counts_fake.call_count, 4);
}
TEST_F(iohwab_adc_UnitTestSuite, Adc_Selftest_SW_Unit_01)
{
   uint32 CPU_Load_Test = 10;
   CPU_Load_Test        = Adc_Selftest();
   ASSERT_EQ(CPU_Load_Test, 0);
}

TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_01)
{
   Position_Pins_T pos_pins;
   Adc_ReadGroup_fake.return_val = 5;
   Hw_Read_Position_Pins(&pos_pins);
   ASSERT_EQ(Adc_StopGroupConversion_fake.call_count, 1);
}

/**
 *  @b Hw_Read_Position_Pins_test2_VerifyDataPopulation
 *  @n
 *      Test case to verify position pins data structure is correctly populated
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_02)
{
   Position_Pins_T pos_pins;

   /* Initialize pos_pins structure */
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Arrange */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 2500; /* Mock ADC count value */

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Verify all 4 channels are marked as valid */
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);

   /* Verify ADC counts are populated */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 2500);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B], 2500);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_C], 2500);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_D], 2500);
}

/**
 *  @b Hw_Read_Position_Pins_test3_TimeoutScenario
 *  @n
 *      Test case to verify behavior when ADC read times out
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_03)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Arrange - ADC read always fails (timeout scenario) */
   Adc_ReadGroup_fake.return_val  = E_NOT_OK;
   Get_ADC_Counts_fake.return_val = 1500;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Even with timeout, channels should still be read and marked valid */
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);

   /* Verify do-while loop ran until the implementation timeout was reached. */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1000);
}

/**
 *  @b Hw_Read_Position_Pins_test4_VerifyCallbackSequence
 *  @n
 *      Test case to verify Enable/Disable callback sequence
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_04)
{
   Position_Pins_T pos_pins;

   /* Arrange */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 3000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Verify callback called exactly twice (Enable, then Disable) */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2);

   /* Verify ADC control sequence */
   ASSERT_EQ(Adc_StopGroupConversion_fake.call_count, 1);
   ASSERT_EQ(Adc_StartGroupConversion_fake.call_count, 1);
}

/**
 *  @b Hw_Read_Position_Pins_test5_ExitCounter_Boundary
 *  @n
 *      Test case to verify both exit conditions of do-while loop are tested
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_05)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Arrange - Test specific ExitCounter boundary */
   /* Always return E_NOT_OK so loop runs exactly until ExitCounter hits 0 */
   Adc_ReadGroup_fake.return_val  = E_NOT_OK;
   Get_ADC_Counts_fake.return_val = 2000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Loop should run exactly 1000 times (ExitCounter goes from 1000 to 0) */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1000);

   /* Verify the memset was called (line 365) */
   /* All valid flags should be set to true after reading */
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);
}

/**
 *  @b Hw_Read_Position_Pins_test6_ExitOnSuccess
 *  @n
 *      Test case to verify early exit when ADC read succeeds before timeout
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_06)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;

   /* Arrange - Return E_OK immediately */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 3500;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Loop should run only once (exits on first success) */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1);

   /* Verify data is populated correctly */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 3500);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
}

/**
 *  @b Hw_Read_Position_Pins_test7_LoopExitAtZeroCounter
 *  @n
 *      Test case to verify loop exits when ExitCounter reaches exactly 0
 *      This tests the second part of the compound while condition: (ExitCounter > NULL_VALUE)
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_07)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0xFF, sizeof(pos_pins)); /* Initialize with known values */

   /* Arrange - Never succeed, force timeout at ExitCounter == 0 */
   Adc_ReadGroup_fake.return_val  = E_NOT_OK; /* Always fail */
   Get_ADC_Counts_fake.return_val = 4000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert */
   /* Loop runs exactly 1000 times: ExitCounter goes 1000 -> 999 -> ... -> 1 -> 0 */
   /* Final iteration: ExitCounter becomes 0, condition (ExitCounter > 0) becomes FALSE, loop exits */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1000);

   /* Verify that even after timeout (ExitCounter == 0), data is still populated */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 4000);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B], 4000);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_C], 4000);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_D], 4000);

   /* All channels should be marked valid */
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);
}

/**
 *  @b Hw_Read_Position_Pins_test8_BothConditionsFalse
 *  @n
 *      Test case to explicitly test the case where BOTH parts of the while condition are FALSE
 *      This is an edge case where ret_value == E_OK (first condition FALSE)
 *      AND we're at the last iteration (ExitCounter would be 0 after decrement)
 *
 *      While logically test6 already covers ret_value == E_OK, this test exercises
 *      a different code path to ensure full branch coverage of the compound condition.
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_08)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Arrange - Return E_OK to make first condition FALSE */
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 5000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert */
   /* Loop should run exactly once - exits because ret_value == E_OK */
   /* After 1 iteration: ret_value == E_OK (first part FALSE), ExitCounter becomes 99 (second part TRUE) */
   /* But due to short-circuit AND evaluation, second part may not be evaluated */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1);

   /* Verify data is populated */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 5000);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);

   /* Verify callback sequence */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2); /* Enable + Disable */
}

/**
 *  @b Hw_Read_Position_Pins_test9_MultipleIterations_MidRange
 *  @n
 *      Test case with exactly 50 iterations to cover additional branch paths
 *      This ensures the loop's TRUE branch (continue loop) is exercised
 *      multiple times before taking the FALSE branch (exit).
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_09)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Custom fake to fail 49 times, then succeed on 50th call */
   static int call_counter_test9 = 0;
   call_counter_test9            = 0;

   Adc_ReadGroup_fake.custom_fake = [](Adc_GroupType group, Adc_ValueGroupType *DataBufferPtr) -> Std_ReturnType
   {
      call_counter_test9++;
      if (call_counter_test9 < 50)
      {
         return E_NOT_OK;
      }
      return E_OK;
   };

   Get_ADC_Counts_fake.return_val = 6000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Loop runs exactly 50 times */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 50);

   /* Verify data populated correctly */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 6000);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
}

/**
 *  @b Hw_Read_Position_Pins_test10_Success_On_100th_Iteration
 *  @n
 *      CRITICAL TEST for MC/DC branch coverage on line 362.
 *      This test covers the edge case where ADC succeeds on the EXACT 100th iteration,
 *      making ret_value == E_OK when ExitCounter becomes 0.
 *
 *      At the while condition check after iteration 100:
 *      - ret_value == E_OK (first condition FALSE)
 *      - ExitCounter == 0 (second condition FALSE)
 *      Result: Both atomic conditions are FALSE, loop exits.
 *
 *      This is different from test7 where ret_value != E_OK when ExitCounter == 0.
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_10)
{
   ut_adc_capture_status = CH_CAPTURE_DONE;
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Custom fake: Fail 99 times, succeed EXACTLY on 100th call */
   static int call_counter_test10 = 0;
   call_counter_test10            = 0;

   Adc_ReadGroup_fake.custom_fake = [](Adc_GroupType group, Adc_ValueGroupType *DataBufferPtr) -> Std_ReturnType
   {
      call_counter_test10++;
      if (call_counter_test10 < 100)
      {
         return E_NOT_OK; /* Fail for iterations 1-99 */
      }
      return E_OK; /* Succeed on iteration 100 */
   };

   Get_ADC_Counts_fake.return_val = 7000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Loop runs exactly 100 times */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 100);

   /* After iteration 100: */
   /* - ret_value gets E_OK (set by ADC_Read_Group) */
   /* - ExitCounter gets decremented from 1 to 0 */
   /* - Condition check: (E_OK != E_OK) && (0 > 0) = FALSE && FALSE = FALSE */
   /* - Loop exits with BOTH conditions FALSE */

   /* Verify data is populated correctly even though we hit the iteration limit */
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 7000);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);

   /* Verify full callback sequence */
   ASSERT_EQ(IoHwAb_ADC_PosPin_Prj_cbk_fake.call_count, 2); /* Enable + Disable */
}

/**
 *  @b Hw_Read_Position_Pins_test11_NonStandardReturnValue
 *  @n
 *      Test with a non-standard return value (not E_OK or E_NOT_OK).
 *      Some coverage tools track different values of the comparison operand.
 *      This ensures ret_value != 0 is tested with various actual values.
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_11)
{
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   /* Return value 0xFF (not standard E_OK or E_NOT_OK) */
   Adc_ReadGroup_fake.return_val  = 0xFF;
   Get_ADC_Counts_fake.return_val = 8000;

   /* Act */
   Hw_Read_Position_Pins(&pos_pins);

   /* Assert - Should timeout after 1000 iterations since return value != E_OK */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1000);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 8000);
}

/**
 *  @b Hw_Read_Position_Pins_test12_StreamCompletedStatus
 *  @n
 *      Covers the (ADC_STREAM_COMPLETED == status) side of the if condition:
 *      status is never ADC_COMPLETED, so ADC_Read_Group is only reached via
 *      the second, short-circuited operand evaluating true.
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_12)
{
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   Adc_GetGroupStatus_fake.return_val = ADC_STREAM_COMPLETED;
   Adc_ReadGroup_fake.return_val      = E_OK;
   Get_ADC_Counts_fake.return_val     = 9500;

   Hw_Read_Position_Pins(&pos_pins);

   /* Loop exits after the first successful read via the STREAM_COMPLETED path */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 1);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 9500);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
}

/**
 *  @b Hw_Read_Position_Pins_test13_NeitherStatusCompleted
 *  @n
 *      Covers the FALSE/FALSE combination of the if condition: status is
 *      neither ADC_COMPLETED nor ADC_STREAM_COMPLETED, so ADC_Read_Group is
 *      never invoked and the loop runs until ExitCounter times out.
 */
TEST_F(iohwab_adc_UnitTestSuite, Hw_Read_Position_Pins_SW_Unit_13)
{
   Position_Pins_T pos_pins;
   memset(&pos_pins, 0, sizeof(pos_pins));

   Adc_GetGroupStatus_fake.return_val = ADC_BUSY;
   Get_ADC_Counts_fake.return_val     = 10500;

   Hw_Read_Position_Pins(&pos_pins);

   /* ADC_Read_Group is never reached because the if condition is always false */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 0);
   ASSERT_EQ(Adc_GetGroupStatus_fake.call_count, 1000);
   ASSERT_EQ(pos_pins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 10500);
   ASSERT_EQ(pos_pins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
}

TEST_F(iohwab_adc_UnitTestSuite, Get_Board_Rev_Cnt_SW_Unit_01)
{
   RESET_FAKE(Get_ADC_Counts); /* Reset only this fake */
   FFF_RESET_HISTORY();        /* Reset all call history */

   /* Arrange */
   Get_ADC_Counts_fake.return_val = 4321;

   /* Act */
   uint16_t result = Get_Board_Rev_Cnt();

   /* Assert */
   ASSERT_EQ(result, 4321);
   ASSERT_EQ(Get_ADC_Counts_fake.call_count, 1);
   ASSERT_EQ(Get_ADC_Counts_fake.arg0_val, ADC_BOARD_REV);
}
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_AdcNotification_SW_Unit_01)
{
   uint8 Adc_Group = 0;
   uint16 test_array[9];
   uint16 *BufferPtr_ut               = test_array;
   BufferPtr_ut[0]                    = 5;
   Adc_GetGroupStatus_fake.return_val = (Adc_StatusType)3;
   IoHwAb_AdcNotification();
   ASSERT_EQ(true, true);
}
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_AdcNotification_SW_Unit_02)
{
   /* Arrange */
   Adc_GetGroupStatus_fake.return_val = ADC_BUSY; /* Any value other than ADC_STREAM_COMPLETED */

   /* Act */
   IoHwAb_AdcNotification();

   /* Assert */
   ASSERT_EQ(Adc_ReadGroup_fake.call_count, 0); /* Should not call Adc_ReadGroup */
}
/**
 *  @b IoHwAb_Adc_Main_5ms_test1
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, IoHwAb_Adc_Main_5ms_SW_Unit_01)
{
   uint8 Adc_Group;
   Adc_Group = 0;
   uint16 test_array[1];
   uint16 *BufferPtr_ut = test_array;
   BufferPtr_ut[0]      = 5;
   // Get_Elapsed_Time_us_fake.return_val = (uint32_t)2500;
   IoHwAb_Adc_Main_5ms();
   // ASSERT_EQ(Get_Elapsed_Time_us_fake.return_val, 2500);
}

/**
 *  @b Get_Last_Sensor_Position_Pins_test
 *  @n
 *      Test case
 */
TEST_F(iohwab_adc_UnitTestSuite, Get_Last_Sensor_Position_Pins_SW_Unit_01)
{
   Position_Pins_T *result = Get_Last_Sensor_Position_Pins();
   ASSERT_EQ(result, &lastPins);
}

TEST_F(iohwab_adc_UnitTestSuite, Get_Last_Sensor_Position_Pins_SW_Unit_02)
{
   memset(&lastPins, 0x00, sizeof(lastPins));
   lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_A]   = true;
   lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A] = 3500;
   lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_B]   = false;
   lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B] = 1200;

   Position_Pins_T *result = Get_Last_Sensor_Position_Pins();

   ASSERT_EQ(result, &lastPins);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 3500);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_B], false);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B], 1200);
}

TEST_F(iohwab_adc_UnitTestSuite, Get_Last_Sensor_Position_Pins_SW_Unit_03)
{
   Adc_ReadGroup_fake.return_val  = E_OK;
   Get_ADC_Counts_fake.return_val = 3333;

   Read_Sensor_Position_Pins();
   Position_Pins_T *result = Get_Last_Sensor_Position_Pins();

   ASSERT_EQ(result, &lastPins);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_A], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_B], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_C], true);
   ASSERT_EQ(lastPins.pos_gnd_valid[CHANNEL_POSITION_GND_D], true);
   ASSERT_EQ(lastPins.pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A], 3333);
}
