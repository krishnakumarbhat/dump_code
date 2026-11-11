/*===========================================================================*/
/**
 * @file SWC_PRJ_Appl_Power_Manager_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the SWC_PRJ_Appl_Power_Manager.c file
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
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "Rte_Type.h"
#include "SWC_PRJ_Appl_Power_Manager_fake.h"
#include "fff.h"

extern "C"
{
#include "SWC_PRJ_Appl_Power_Manager.c"
}
VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode       = 0U;
VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0U;
uint8 CustShutdownTaskCompleted;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_PRJ_Appl_Power_Manager_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
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

// Helper for ADC injection
static Dt_AdcData_T test_adc_data;
static Std_ReturnType adc_read_fake(Dt_AdcData_T *data)
{
   *data = test_adc_data;
   return 0;
}

/**
 *  @b RE_Power_Manager_5ms
 *  @n
 */
TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_5ms_01)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   RE_Power_Manager_5ms();
   ASSERT_EQ(Get_Board_Revision_fake.call_count, 1);
}
/**
 *  @b RE_Power_Manager_5ms
 *  @n
 */
TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_5ms_02)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P1;
   RE_Power_Manager_5ms();
   ASSERT_EQ(Get_Board_Revision_fake.call_count, 4);
}
/**
 *  @b RE_Power_Manager_Init
 *  @n
 */
TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_Init_01)
{
   RE_Power_Manager_Init();
   ASSERT_EQ(Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode, REQUESTED);
}

TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_5ms_03)
{
   RESET_FAKE(Get_Board_Revision);

   RESET_FAKE(Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData);
   RESET_FAKE(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown);

   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Dt_AdcData_T adc_data              = {0};
   adc_data.Adc_Pos_Gnd_C             = 5.0f; // Below threshold

   for (unsigned i = 0; i < LOW_IGN_DEBOUNCE_CNT; ++i)
   {
      RE_Power_Manager_5ms();
   }
   ASSERT_GE(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown_fake.call_count, LOW_IGN_DEBOUNCE_CNT);
}

TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_5ms_04)
{
   RESET_FAKE(Get_Board_Revision);
   RESET_FAKE(Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData);
   RESET_FAKE(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown);
   RESET_FAKE(Dio_Wrapper_WriteChannel);
   RESET_FAKE(Mcu_Reset);

   Get_Board_Revision_fake.return_val                                                         = BOARD_REV_A3P0;
   test_adc_data                                                                              = (Dt_AdcData_T){0};
   test_adc_data.Adc_Pos_Gnd_C                                                                = 7.0f; // Above threshold
   Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData_fake.custom_fake = adc_read_fake;

   RE_Power_Manager_5ms();
   // Should not request shutdown, debounce resets
   ASSERT_EQ(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown_fake.call_count, 1);
}

TEST_F(SWC_PRJ_Appl_Power_Manager_UnitTestSuite, RE_Power_Manager_5ms_05)
{
   RESET_FAKE(Get_Board_Revision);
   RESET_FAKE(Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData);
   RESET_FAKE(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown);
   RESET_FAKE(Dio_Wrapper_WriteChannel);
   RESET_FAKE(Mcu_Reset);

   Get_Board_Revision_fake.return_val                                                         = BOARD_REV_A3P0;
   test_adc_data                                                                              = (Dt_AdcData_T){0};
   test_adc_data.Adc_Pos_Gnd_C                                                                = 7.0f; // Above threshold
   Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System               = SHUTDOWN_COMPLETED;
   Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData_fake.custom_fake = adc_read_fake;

   RE_Power_Manager_5ms();
   ASSERT_EQ(Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown_fake.call_count, 1);
}
