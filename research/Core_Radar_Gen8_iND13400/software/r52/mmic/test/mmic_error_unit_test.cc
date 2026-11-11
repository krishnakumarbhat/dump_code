/*===========================================================================*/
/**
 * @file mmic_error_unit_test.cc
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

#include "fff.h"
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

#ifndef _Bool
   #define _Bool bool
#endif

extern "C"
{
#include "mmic_error.c"
#include "mmic_interface.h"
   /* Fake function declarations for external dependencies */
   DECLARE_FAKE_VOID_FUNC(MMIC_Reset_MARS);
   DECLARE_FAKE_VOID_FUNC(Reset_MCU_handle);

   /* Define the MMIC_Stream variable used by mmic_error.c */
   MMIC_Stream_T MMIC_Stream = {0};
}
/* Define fake functions for external dependencies */
DEFINE_FAKE_VOID_FUNC(MMIC_Reset_MARS);
DEFINE_FAKE_VOID_FUNC(Reset_MCU_handle);
uint8_t MIPI_CSI2_Data_Error;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class dd_mmic_ErrorUnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      // Reset MMIC_Error structure to known state before each test
      memset(&MMIC_Error, 0, sizeof(MMIC_Error));

      // Initialize MMIC_Stream to simulate initialized MARS system
      // This sets mars_initialization_status = true, making MMIC_REINIT_ERROR_MAX_COUNT = 3
      memset(&MMIC_Stream, 0, sizeof(MMIC_Stream));
      MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status = true;

      // Reset fake functions
      RESET_FAKE(MMIC_Reset_MARS);
      RESET_FAKE(Reset_MCU_handle);
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

TEST_F(dd_mmic_ErrorUnitTestSuite, dd_mmic_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Update_MMIC_Success_INIT_ERROR_CLEAR_COUNT_Check)
{
   MMIC_Error.reinit_clear_count = 2;
   Update_MMIC_Success();
   EXPECT_EQ(MMIC_Error.discard_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Update_MMIC_Success_INIT_ERROR_CLEAR_COUNT_MAXIMUM_Check)
{
   MMIC_Error.reinit_clear_count = 100;
   Update_MMIC_Success();
   EXPECT_EQ(MMIC_Error.reinit_clear_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Update_MMIC_Success_INIT_ERROR_CLEAR_COUNT_MAXIMUM_Check1)
{
   MMIC_Error.reinit_clear_count  = 100;
   MMIC_Error.reinit_error_count  = 5;
   MMIC_Error.discard_error_count = 5;
   Update_MMIC_Success();
   EXPECT_EQ(MMIC_Error.discard_error_count, 4);
   EXPECT_EQ(MMIC_Error.reinit_error_count, 4);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Faulted_Test)
{
   Set_MMIC_Faulted();
   ASSERT_EQ(MMIC_Error.faulted, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Faulted_Test)
{
   bool ret           = false;
   MMIC_Error.faulted = true;
   ret                = Get_MMIC_Faulted();
   ASSERT_EQ(ret, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_Reinit_Test)
{
   bool ret;
   MMIC_Error.reinit_error = false;
   ret                     = Get_MMIC_Error_Reinit();
   ASSERT_EQ(ret, false);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_Reinit_Count_Maximun_check)
{
   uint16_t ret;
   MMIC_Error.reinit_error_total = 100;
   ret                           = Get_MMIC_Error_Reinit_Count();
   ASSERT_EQ(ret, 100);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Faulted_Test)
{
   Clr_MMIC_Faulted();
   EXPECT_EQ(MMIC_Error.faulted, false);
   EXPECT_EQ(MMIC_Error.reinit_error, false);
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
   EXPECT_EQ(MMIC_Error.discard_error, false);
   EXPECT_EQ(MMIC_Error.discard_error_count, false);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_By_ID_Check)
{
   uint16_t ret;
   MMIC_Error_ID_T error_id = REINIT_ERROR_ACQ_ACTIVE;
   ret                      = Get_MMIC_Error_By_ID(error_id);
   ASSERT_EQ(ret, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_Discard_Test)
{
   bool ret;
   MMIC_Error.discard_error = true;
   ret                      = Get_MMIC_Error_Discard();
   ASSERT_EQ(ret, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_Discard_Count_Max_Check)
{
   uint16_t ret;
   MMIC_Error.discard_error_total = 100;
   ret                            = Get_MMIC_Error_Discard_Count();
   ASSERT_EQ(ret, 100);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Error_Discard_Check)
{
   Clr_MMIC_Error_Discard();
   EXPECT_EQ(MMIC_Error.discard_error, false);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_Counters_ptr_Test)
{
   uint16_t ret;

   ret = *Get_MMIC_Error_Counters_ptr();
   ASSERT_EQ(ret, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_Test)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults  = true;
   Set_MMIC_Error_Reinit(error_id);
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_Disable_faults)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = 2; // Starting at 2, adding 1 will reach MAX_COUNT=3
   Set_MMIC_Error_Reinit(error_id);
   EXPECT_EQ(MMIC_Error.faulted, false);
}
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_Disable_Else_case_check)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = MMIC_REINIT_ERROR_MAX_COUNT;
   Set_MMIC_Error_Reinit(error_id);
   EXPECT_EQ(MMIC_Error.faulted, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_Disable_faults_Check)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults  = false;
   Set_MMIC_Error_Reinit(error_id);
   EXPECT_EQ(MMIC_Error.reinit_error, true);
}

// Test Set_MMIC_Error_Reinit - Increments error count and calls MMIC_Reset_MARS and Reset_MCU_Handle
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_IncrementsCountAndResetsMars)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = 2; // Starting at 2, will reach MAX_COUNT=3 after adding UP_COUNT=1
   MMIC_Error.faulted            = false;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, 3);
   EXPECT_EQ(MMIC_Error.reinit_error, true);
   EXPECT_EQ(MMIC_Error.reinit_clear_count, 0);
   EXPECT_FALSE(MMIC_Error.faulted);
}

// Test Set_MMIC_Error_Reinit - Reaches threshold exactly
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_ReachesThresholdExactly)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = MMIC_REINIT_ERROR_MAX_COUNT - MMIC_REINIT_ERROR_UP_COUNT;
   MMIC_Error.faulted            = false;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, MMIC_REINIT_ERROR_MAX_COUNT);
   EXPECT_FALSE(MMIC_Error.faulted);
}

// Test Set_MMIC_Error_Reinit - Just below threshold doesn't fault
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_JustBelowThresholdNoFault)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = MMIC_REINIT_ERROR_MAX_COUNT - MMIC_REINIT_ERROR_UP_COUNT - 1;
   MMIC_Error.faulted            = false;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, MMIC_REINIT_ERROR_MAX_COUNT - 1);
   EXPECT_FALSE(MMIC_Error.faulted); // Should not fault when below threshold
}

// Test Set_MMIC_Error_Reinit - Above threshold stays faulted
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_AboveThresholdStaysFaulted)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults  = false;
   // Start at exactly MAX_COUNT (3) to avoid triggering Clr_MMIC_Reinit_Count_Post_Init
   MMIC_Error.reinit_error_count = MMIC_REINIT_ERROR_MAX_COUNT;
   MMIC_Error.faulted            = false;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, MMIC_REINIT_ERROR_MAX_COUNT + MMIC_REINIT_ERROR_UP_COUNT); // 3 + 1 = 4
   EXPECT_TRUE(MMIC_Error.faulted); // Should fault when >= threshold
}

// Test Set_MMIC_Error_Reinit - Multiple error IDs increment different counters
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_TracksMultipleErrorIDs)
{
   XCP_MMIC_Disable_Faults = false;

   Set_MMIC_Error_Reinit(REINIT_ERROR_SPI);
   Set_MMIC_Error_Reinit(REINIT_ERROR_MMIC_INIT);
   Set_MMIC_Error_Reinit(REINIT_ERROR_SPI);

   EXPECT_EQ(MMIC_Error.error_counters.u16[REINIT_ERROR_SPI], 2);
   EXPECT_EQ(MMIC_Error.error_counters.u16[REINIT_ERROR_MMIC_INIT], 1);
   EXPECT_EQ(MMIC_Error.reinit_error_total, 3);
}

// Test Set_MMIC_Error_Reinit - Clears reinit_clear_count
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_ClearsReinitClearCount)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_clear_count = 50;
   MMIC_Error.reinit_error_count = 0;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_clear_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_Check)
{
   MMIC_Error_ID_T error_id       = REINIT_ERROR_ISM_RESET;
   XCP_MMIC_Disable_Faults        = true;
   MMIC_Error.discard_error_count = 0;
   Set_MMIC_Error_Discard(error_id);
   EXPECT_EQ(MMIC_Error.discard_error, false);
   EXPECT_EQ(MMIC_Error.discard_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_XCP_MMIC_Disable_Faults)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults  = false;
   Set_MMIC_Error_Discard(error_id);
   EXPECT_EQ(MMIC_Error.discard_error, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_XCP_MMIC_Disable_Faults_1)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults  = false;
   Set_MMIC_Error_Discard(error_id);
   EXPECT_EQ(MMIC_Error.discard_error, true);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_XCP_MMIC_Disable_Faults_Check)
{
   MMIC_Error_ID_T error_id       = REINIT_ERROR_ACQ_ACTIVE;
   XCP_MMIC_Disable_Faults        = false;
   MMIC_Error.discard_error_count = 10;
   Set_MMIC_Error_Discard(error_id);
   EXPECT_EQ(MMIC_Error.discard_error, true);
   EXPECT_EQ(MMIC_Error.discard_error_count, 8);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Error_Reinit_Test)
{
   Clr_MMIC_Error_Reinit();
   ASSERT_EQ(MMIC_Error.reinit_error, false);
   ASSERT_EQ(MMIC_Error.discard_error, false);
   ASSERT_EQ(MMIC_Error.discard_error_count, 0);
}
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_Test)
{
   MMIC_Config_Error_ID_T error_id  = CONFIG_ERROR_MIPI_CONFIG;
   MMIC_Error.function_config_fault = 85;
   Set_MMIC_Config_Error(error_id);
   EXPECT_EQ(MMIC_Error.MMIC_config_error, true);
   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, 1);
   EXPECT_EQ(MMIC_Error.function_config_fault, 85);
}

/* XCP_MMIC_Disable_Faults True Case */
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_Test_1)
{
   MMIC_Config_Error_ID_T error_id  = CONFIG_ERROR_MIPI_CONFIG;
   MMIC_Error.function_config_fault = 85;
   MMIC_Error.MMIC_config_error     = false;
   Set_MMIC_Config_Error(error_id);      // First call: count 0->1
   Set_MMIC_Config_Error(error_id);      // Second call: count stays 1 (since MMIC_config_error is now true)
   MMIC_Error.MMIC_config_error = false; // Reset to test another increment
   Set_MMIC_Config_Error(error_id);      // Third call: count 1->2, triggers CODED_TRUE
   EXPECT_EQ(MMIC_Error.MMIC_config_error, 1);
   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, MMIC_CONFIG_ERROR_MAX_COUNT);
   EXPECT_EQ(MMIC_Error.function_config_fault, 0xAA); // Now set to CODED_TRUE
}

/* Test when MMIC_config_error is already true - count should not increment */
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_Test_3)
{
   MMIC_Config_Error_ID_T error_id    = CONFIG_ERROR_MIPI_CONFIG;
   MMIC_Error.MMIC_config_error       = true;
   MMIC_Error.MMIC_config_error_count = 1;
   Set_MMIC_Config_Error(error_id);
   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, 1); // Should stay 1 since MMIC_config_error was already true
   EXPECT_EQ(MMIC_Error.function_config_fault, 0);   // Should stay 0 since count < 2
}

/* XCP_MMIC_Disable_Faults True Case, with Function_Config_Fault set to 0xAA */
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_Test_2)
{
   MMIC_Config_Error_ID_T error_id    = CONFIG_ERROR_MIPI_CONFIG;
   MMIC_Error.MMIC_config_error       = false;
   MMIC_Error.MMIC_config_error_count = 5;
   Set_MMIC_Config_Error(error_id);
   EXPECT_EQ(MMIC_Error.MMIC_config_error, true);
   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, MMIC_CONFIG_ERROR_MAX_COUNT);
   EXPECT_EQ(MMIC_Error.function_config_fault, 0xAA);
}
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Config_Error_Check)
{
   Clr_MMIC_Config_Error();
}
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Config_Error_False_Check)
{
   bool ret;
   MMIC_Error.MMIC_config_error = false;
   ret                          = Get_MMIC_Config_Error();
   ASSERT_EQ(ret, false);
}
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_Function_Config_Error_Check_Coded_False)
{
   uint8_t ret;
   MMIC_Error.function_config_fault = 85;
   ret                              = Get_Function_Config_Error();
   ASSERT_EQ(ret, 85);
}

/* Coded True Case */
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_Function_Config_Error_Check_Coded_True)
{
   uint8_t ret;
   MMIC_Error.function_config_fault = 170;
   ret                              = Get_Function_Config_Error();
   ASSERT_EQ(ret, 170);
}

// Test counter increments (reinit_error_total and error_counters)
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_IncrementsCounters)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_TRIGGER_TIMEOUT;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_total, 1);
   EXPECT_EQ(MMIC_Error.error_counters.u16[error_id], 1);
}

// Test reinit_clear_count reset
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_ResetsReinitClearCount)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_MIPI_CONFIG_INIT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_clear_count = 5;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_clear_count, 0);
}

// Test MMIC_Reset_MARS() is called
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_CallsMMICResetMARS)
{
   RESET_FAKE(MMIC_Reset_MARS);
   MMIC_Error_ID_T error_id = REINIT_ERROR_MMIC_INIT;
   XCP_MMIC_Disable_Faults  = false;

   // Start with clean state
   MMIC_Error.reinit_error_count = 0;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Reset_MARS_fake.call_count, 1); /*MMIC_Reset_MARS should be called when setting the error*/
}

// Test reinit_error_count increment by UP_COUNT (1)
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_IncrementsReinitErrorCount)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_LOOK_COMPLETE;
   XCP_MMIC_Disable_Faults  = false;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, 1); // MMIC_REINIT_ERROR_UP_COUNT = 1
}

// Test faulted not set when count < MAX_COUNT after single call from 0
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_NoFaultBelowMaxCount_NegativeCase)
{
   MMIC_Error_ID_T error_id      = REINIT_ERROR_TRIGGER_TIMEOUT;
   XCP_MMIC_Disable_Faults       = false;
   MMIC_Error.reinit_error_count = -1; // Will become 0 after call (< MAX_COUNT=3)

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
   EXPECT_EQ(MMIC_Error.faulted, false); // Should NOT be set yet
}

// Test reinit_error_count accumulation across multiple calls
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_AccumulatesErrorCount)
{
   XCP_MMIC_Disable_Faults = false;

   Set_MMIC_Error_Reinit(REINIT_ERROR_TRIGGER_TIMEOUT);
   Set_MMIC_Error_Reinit(REINIT_ERROR_LOOK_COMPLETE);

   EXPECT_EQ(MMIC_Error.reinit_error_count, 2); // 1 + 1
}

//  Test XCP bypass only increments basic counters
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Reinit_XCPBypass_OnlyBasicCounters)
{
   MMIC_Error_ID_T error_id = REINIT_ERROR_MIPI_CONFIG_INIT;
   XCP_MMIC_Disable_Faults  = true;

   Set_MMIC_Error_Reinit(error_id);

   EXPECT_EQ(MMIC_Error.reinit_error_total, 1);
   EXPECT_EQ(MMIC_Error.error_counters.u16[error_id], 1);
   EXPECT_EQ(MMIC_Error.reinit_error, false);
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
   EXPECT_EQ(MMIC_Reset_MARS_fake.call_count, 0);
}

/*===========================================================================*
 * Unit Tests for Function Config Error Functions (EPB-4023)
 *===========================================================================*/

// Test Set_MMIC_Config_Error - First error sets flag
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_FirstError)
{
   // Setup: No error initially
   MMIC_Error.MMIC_config_error       = false;
   MMIC_Error.MMIC_config_error_count = 0;
   MMIC_Error.function_config_fault   = CODED_FALSE;
   MMIC_Error.faulted                 = false;

   // Execute: Set first config error
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);

   // Verify: Error flag set, count incremented
   ASSERT_TRUE(MMIC_Error.MMIC_config_error);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_count, 1); // MMIC_CONFIG_ERROR_UP_COUNT = 1
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[CONFIG_ERROR_MMIC_CONFIG], 1);
   ASSERT_TRUE(MMIC_Error.faulted);
   ASSERT_EQ(MMIC_Error.function_config_fault, CODED_FALSE); // Not at max yet
}

// Test Set_MMIC_Config_Error - Multiple errors reach threshold
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_ReachThreshold)
{
   // Setup: No error initially
   MMIC_Error.MMIC_config_error       = false;
   MMIC_Error.MMIC_config_error_count = 0;
   MMIC_Error.function_config_fault   = CODED_FALSE;

   // Execute: Set first error (count increments only on first error)
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_count, 1);
   ASSERT_EQ(MMIC_Error.function_config_fault, CODED_FALSE);
   ASSERT_TRUE(MMIC_Error.MMIC_config_error); // Flag is now set

   // Clear the flag and call again to increment count
   Clr_MMIC_Config_Error();
   Set_MMIC_Config_Error(CONFIG_ERROR_MIPI_CONFIG);

   // Verify: Function config fault set when threshold reached
   ASSERT_EQ(MMIC_Error.MMIC_config_error_count, 2); // Now at max
   ASSERT_EQ(MMIC_Error.function_config_fault, CODED_TRUE);
   ASSERT_TRUE(MMIC_Error.faulted);
}

// Test Set_MMIC_Config_Error - Error count clamped at max
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_ClampedAtMax)
{
   // Setup: Already at max count
   MMIC_Error.MMIC_config_error       = true;
   MMIC_Error.MMIC_config_error_count = 2; // MMIC_CONFIG_ERROR_MAX_COUNT
   MMIC_Error.function_config_fault   = CODED_TRUE;

   // Execute: Add another error
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);

   // Verify: Count stays at max
   ASSERT_EQ(MMIC_Error.MMIC_config_error_count, 2);
   ASSERT_EQ(MMIC_Error.function_config_fault, CODED_TRUE);
}

// Test Set_MMIC_Config_Error - Different error IDs tracked
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_MultipleErrorIDs)
{
   // Setup
   MMIC_Error.MMIC_config_error       = false;
   MMIC_Error.MMIC_config_error_count = 0;

   // Execute: Set different error types
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);
   Set_MMIC_Config_Error(CONFIG_ERROR_MIPI_CONFIG);
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG); // Same ID again

   // Verify: Each error ID counter incremented correctly
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[CONFIG_ERROR_MMIC_CONFIG], 2);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[CONFIG_ERROR_MIPI_CONFIG], 1);
}

// Test Clr_MMIC_Config_Error
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Config_Error_ClearsFlag)
{
   // Setup: Error is set
   MMIC_Error.MMIC_config_error       = true;
   MMIC_Error.MMIC_config_error_count = 2;

   // Execute: Clear the error
   Clr_MMIC_Config_Error();

   // Verify: Error flag cleared (but count remains)
   ASSERT_FALSE(MMIC_Error.MMIC_config_error);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_count, 2); // Count not cleared
}

// Test Get_MMIC_Config_Error - Returns true when error set
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Config_Error_ReturnsTrue)
{
   // Setup: Error is set
   MMIC_Error.MMIC_config_error = true;

   // Execute & Verify
   ASSERT_TRUE(Get_MMIC_Config_Error());
}

// Test Get_MMIC_Config_Error - Returns false when no error
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Config_Error_ReturnsFalse)
{
   // Setup: No error
   MMIC_Error.MMIC_config_error = false;

   // Execute & Verify
   ASSERT_FALSE(Get_MMIC_Config_Error());
}

// Test Get_Function_Config_Error - Returns fault status
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_Function_Config_Error_ReturnsCODED_TRUE)
{
   // Setup: Function config fault set
   MMIC_Error.function_config_fault = CODED_TRUE;

   // Execute & Verify
   ASSERT_EQ(Get_Function_Config_Error(), CODED_TRUE);
}

// Test Get_Function_Config_Error - Returns false when no fault
TEST_F(dd_mmic_ErrorUnitTestSuite, Get_Function_Config_Error_ReturnsCODED_FALSE)
{
   // Setup: No fault
   MMIC_Error.function_config_fault = CODED_FALSE;

   // Execute & Verify
   ASSERT_EQ(Get_Function_Config_Error(), CODED_FALSE);
}

// Test integration scenario: Full error escalation flow
TEST_F(dd_mmic_ErrorUnitTestSuite, ConfigError_IntegrationFlow)
{
   // Setup: Clean state
   MMIC_Error.MMIC_config_error       = false;
   MMIC_Error.MMIC_config_error_count = 0;
   MMIC_Error.function_config_fault   = CODED_FALSE;

   // Step 1: First error
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);
   ASSERT_TRUE(Get_MMIC_Config_Error());
   ASSERT_EQ(Get_Function_Config_Error(), CODED_FALSE);

   // Step 2: Clear flag and set second error to reach threshold
   Clr_MMIC_Config_Error();
   Set_MMIC_Config_Error(CONFIG_ERROR_MIPI_CONFIG);
   ASSERT_TRUE(Get_MMIC_Config_Error());
   ASSERT_EQ(Get_Function_Config_Error(), CODED_TRUE);

   // Step 3: Clear flag (but fault persists)
   Clr_MMIC_Config_Error();
   ASSERT_FALSE(Get_MMIC_Config_Error());
   ASSERT_EQ(Get_Function_Config_Error(), CODED_TRUE); // Fault not cleared
}

// Test Set_MMIC_Config_Error - All error ID types
TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Config_Error_AllErrorTypes)
{
   // Test each error type can be set
   Set_MMIC_Config_Error(CONFIG_ERROR_MMIC_CONFIG);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[CONFIG_ERROR_MMIC_CONFIG], 1);

   Set_MMIC_Config_Error(CONFIG_ERROR_MIPI_CONFIG);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[CONFIG_ERROR_MIPI_CONFIG], 1);

   Set_MMIC_Config_Error(REINIT_CONFIG_ERROR_MIPI_CONFIG);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[REINIT_CONFIG_ERROR_MIPI_CONFIG], 1);

   Set_MMIC_Config_Error(REINIT_CONFIG_ERROR_MMIC_CONFIG);
   ASSERT_EQ(MMIC_Error.MMIC_config_error_counters.u16[REINIT_CONFIG_ERROR_MMIC_CONFIG], 1);
}

// Test Clr_MMIC_API_Look_Fault_Status - Clears all API error counters to zero
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_ClearsAllCounters)
{
   // Set up: Set all API error counters to non-zero values
   API_Look_Config_Error   = 5;
   API_Look_Trigger_Error  = 3;
   API_Look_Complete_Error = 7;

   // Execute: Clear all fault status
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: All counters are cleared to zero
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Clr_MMIC_API_Look_Fault_Status - Works when counters already zero
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_WhenAlreadyZero)
{
   // Set up: Ensure all counters are zero
   API_Look_Config_Error   = 0;
   API_Look_Trigger_Error  = 0;
   API_Look_Complete_Error = 0;

   // Execute: Clear fault status
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: Counters remain zero (no side effects)
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Clr_MMIC_API_Look_Fault_Status - Clears maximum values
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_ClearsMaxValues)
{
   // Set up: Set counters to maximum uint8_t value
   API_Look_Config_Error   = 255;
   API_Look_Trigger_Error  = 255;
   API_Look_Complete_Error = 255;

   // Execute: Clear fault status
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: All counters cleared to zero
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Clr_MMIC_API_Look_Fault_Status - Clears one counter at threshold
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_ClearsThresholdValue)
{
   // Set up: Set config error at threshold, others at different values
   API_Look_Config_Error   = API_ERROR_THRESHOLD;
   API_Look_Trigger_Error  = 1;
   API_Look_Complete_Error = 2;

   // Execute: Clear fault status
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: All counters cleared including threshold value
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Clr_MMIC_API_Look_Fault_Status - Multiple calls idempotent
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_MultipleCallsIdempotent)
{
   // Set up: Set counters to non-zero
   API_Look_Config_Error   = 10;
   API_Look_Trigger_Error  = 20;
   API_Look_Complete_Error = 30;

   // Execute: Call clear multiple times
   Clr_MMIC_API_Look_Fault_Status();
   Clr_MMIC_API_Look_Fault_Status();
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: Counters remain zero after multiple calls
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
}

// Test Clr_MMIC_API_Look_Fault_Status - Does not affect other MMIC_Error fields
TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_API_Look_Fault_Status_DoesNotAffectOtherFields)
{
   // Set up: Set API counters and other MMIC_Error fields
   API_Look_Config_Error              = 5;
   API_Look_Trigger_Error             = 3;
   API_Look_Complete_Error            = 7;
   MMIC_Error.reinit_error            = true;
   MMIC_Error.discard_error           = true;
   MMIC_Error.faulted                 = true;
   MMIC_Error.reinit_error_count      = 2;
   MMIC_Error.discard_error_count     = 3;
   MMIC_Error.MMIC_config_error       = true;
   MMIC_Error.function_config_fault   = CODED_TRUE;
   MMIC_Error.MMIC_config_error_count = 1;

   // Execute: Clear API fault status
   Clr_MMIC_API_Look_Fault_Status();

   // Verify: API counters cleared but other fields unchanged
   EXPECT_EQ(API_Look_Config_Error, 0);
   EXPECT_EQ(API_Look_Trigger_Error, 0);
   EXPECT_EQ(API_Look_Complete_Error, 0);
   EXPECT_TRUE(MMIC_Error.reinit_error);
   EXPECT_TRUE(MMIC_Error.discard_error);
   EXPECT_TRUE(MMIC_Error.faulted);
   EXPECT_EQ(MMIC_Error.reinit_error_count, 2);
   EXPECT_EQ(MMIC_Error.discard_error_count, 3);
   EXPECT_TRUE(MMIC_Error.MMIC_config_error);
   EXPECT_EQ(MMIC_Error.function_config_fault, CODED_TRUE);
   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, 1);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Error_Count_ClearsCount)
{
   MMIC_Error.reinit_error_count = 5;
   Clr_MMIC_Reinit_Error_Count();
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Error_Count_WhenAlreadyZero)
{
   MMIC_Error.reinit_error_count = 0;
   Clr_MMIC_Reinit_Error_Count();
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Error_Count_ClearsMaxValue)
{
   MMIC_Error.reinit_error_count = 127;
   Clr_MMIC_Reinit_Error_Count();
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Error_Count_DoesNotAffectOtherFields)
{
   MMIC_Error.reinit_error_count  = 10;
   MMIC_Error.discard_error_count = 5;
   MMIC_Error.reinit_error        = true;
   MMIC_Error.discard_error       = true;
   MMIC_Error.faulted             = true;
   Clr_MMIC_Reinit_Error_Count();

   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
   EXPECT_EQ(MMIC_Error.discard_error_count, 5);
   EXPECT_TRUE(MMIC_Error.reinit_error);
   EXPECT_TRUE(MMIC_Error.discard_error);
   EXPECT_TRUE(MMIC_Error.faulted);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_ReachesThresholdAndTriggersReinit)
{
   XCP_MMIC_Disable_Faults        = false;
   MMIC_Error.discard_error_count = MMIC_DISCARD_ERROR_MAX_COUNT - MMIC_DISCARD_ERROR_UP_COUNT; // 8 - 2 = 6
   Set_MMIC_Error_Discard(DISCARD_ERROR_CONFIG_LOOK);

   EXPECT_EQ(MMIC_Error.discard_error_count, MMIC_DISCARD_ERROR_MAX_COUNT);
   EXPECT_TRUE(MMIC_Error.discard_error);
   // Note: Set_MMIC_Error_Discard does not trigger reinit - it only manages discard error count
   // Reinit is triggered separately by Set_MMIC_Error_Reinit when needed
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_IncrementsCounters)
{
   XCP_MMIC_Disable_Faults        = false;
   MMIC_Error_ID_T error_id       = DISCARD_ERROR_LOOK_TRIGGER;
   MMIC_Error.discard_error_count = 0;

   Set_MMIC_Error_Discard(error_id);
   EXPECT_EQ(MMIC_Error.discard_error_total, 1);
   EXPECT_EQ(MMIC_Error.error_counters.u16[error_id], 1);
   EXPECT_EQ(MMIC_Error.discard_error_count, MMIC_DISCARD_ERROR_UP_COUNT); // Should be 2
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_TracksMultipleErrorTypes)
{
   XCP_MMIC_Disable_Faults = false;

   Set_MMIC_Error_Discard(DISCARD_ERROR_CONFIG_LOOK);
   Set_MMIC_Error_Discard(DISCARD_ERROR_LOOK_TRIGGER);
   Set_MMIC_Error_Discard(DISCARD_ERROR_CONFIG_LOOK); // Same as first

   EXPECT_EQ(MMIC_Error.discard_error_total, 3);
   EXPECT_EQ(MMIC_Error.error_counters.u16[DISCARD_ERROR_CONFIG_LOOK], 2);
   EXPECT_EQ(MMIC_Error.error_counters.u16[DISCARD_ERROR_LOOK_TRIGGER], 1);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MMIC_Error_By_ID_ReturnsCorrectCount)
{
   MMIC_Error.error_counters.u16[REINIT_ERROR_SPI]       = 5;
   MMIC_Error.error_counters.u16[REINIT_ERROR_MMIC_INIT] = 3;
   MMIC_Error.error_counters.u16[DISCARD_ERROR_RESET]    = 7;

   EXPECT_EQ(Get_MMIC_Error_By_ID(REINIT_ERROR_SPI), 5);
   EXPECT_EQ(Get_MMIC_Error_By_ID(REINIT_ERROR_MMIC_INIT), 3);
   EXPECT_EQ(Get_MMIC_Error_By_ID(DISCARD_ERROR_RESET), 7);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Update_MMIC_Success_DecrementsBothCounts)
{
   MMIC_Error.reinit_error_count  = 5;
   MMIC_Error.discard_error_count = 8;
   MMIC_Error.reinit_clear_count  = 99;

   Update_MMIC_Success();
   EXPECT_EQ(MMIC_Error.reinit_error_count, 4);
   EXPECT_EQ(MMIC_Error.discard_error_count, 7);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Update_MMIC_Success_DoesNotGoNegative)
{
   MMIC_Error.reinit_error_count  = 0;
   MMIC_Error.discard_error_count = 0;
   MMIC_Error.reinit_clear_count  = 50;

   Update_MMIC_Success();
   EXPECT_EQ(MMIC_Error.reinit_error_count, 0);
   EXPECT_EQ(MMIC_Error.discard_error_count, 0);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Set_MMIC_Error_Discard_ClampsAtMaxThreshold)
{
   XCP_MMIC_Disable_Faults        = false;
   MMIC_Error.discard_error_count = MMIC_DISCARD_ERROR_MAX_COUNT; // Already at max
   Set_MMIC_Error_Discard(DISCARD_ERROR_LOOK_COMPLETE);
   EXPECT_EQ(MMIC_Error.discard_error_count, MMIC_DISCARD_ERROR_MAX_COUNT);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Get_MIPI_Fault_ReflectsDataFaultFlag)
{
   MMIC_Stream.MMIC_Data.MIPI_FuSa_fault_info.mipi_data_fault = CODED_FALSE;
   EXPECT_EQ(Get_MIPI_Fault(), CODED_FALSE);

   MMIC_Stream.MMIC_Data.MIPI_FuSa_fault_info.mipi_data_fault = CODED_TRUE;
   EXPECT_EQ(Get_MIPI_Fault(), CODED_TRUE);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Config_Error_Cnt_ResetsCounter)
{
   MMIC_Error.MMIC_config_error_count = 5U;

   Clr_MMIC_Config_Error_Cnt();

   EXPECT_EQ(MMIC_Error.MMIC_config_error_count, 0U);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Count_Post_Init_DoesNothingWhenNotInitialized)
{
   MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status = false;
   MMIC_Error.reinit_error_count                                       = 5;

   Clr_MMIC_Reinit_Count_Post_Init();

   EXPECT_EQ(MMIC_Error.reinit_error_count, 5);
}

TEST_F(dd_mmic_ErrorUnitTestSuite, Clr_MMIC_Reinit_Count_Post_Init_DoesNothingBelowThreshold)
{
   MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status = true;
   MMIC_Error.reinit_error_count                                       = 3;

   Clr_MMIC_Reinit_Count_Post_Init();

   EXPECT_EQ(MMIC_Error.reinit_error_count, 3);
}
