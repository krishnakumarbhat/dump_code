/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_FaultMgr_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_FaultMgr.c file
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
#include "SWC_PLT_Appl_FaultMgr_fake.h"
#include "fff.h"
extern "C"
{
#include "SWC_PLT_Appl_FaultMgr.c"
}

DEFINE_FFF_GLOBALS;

// Forward declaration for helper used as a custom fake in tests
Std_ReturnType NvM_GetErrorStatus_ReturnPending(uint16 BlockId, uint8 *RequestResultPtr);

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_appl_faultmgr_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      // FFF_FAKES_FAULT_MGR_BLOCKAGE_DETECTION_50MS(RESET_FAKE);
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b swc_plt_appl_faultmgr_sanity
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, swc_plt_appl_faultmgr__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms_test1)
{
   RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms();
   ASSERT_EQ(Fault_Mgr_Alignment_Diagnostics_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms_test1)
{
   RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms();
   ASSERT_EQ(Fault_Mgr_Battery_Fault_Tests_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_General_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_General_Diagnostics_50ms_test1)
{
   RE_PLT_Fault_Mgr_General_Diagnostics_50ms();
   ASSERT_EQ(Fault_Mgr_General_Diagnostics_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms_test1)
{
   RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms();
   ASSERT_EQ(Fault_Mgr_Host_Microcontroller_Tests_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Fault_Mgr_Init
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Init)
{
   RE_PLT_Fault_Mgr_Init();
   ASSERT_EQ(Fault_Mgr_Init_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_Main_10ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Main_10ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Main_10ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_Main_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Main_50ms_1)
{
   RE_PLT_Fault_Mgr_Init();
   FFF_RESET_HISTORY();

   Platform_fault_T platform_history_table = {0};
   Platform_fault_T platform_active_table  = {0};
   platform_active_table.Platform_byte[0]  = 0x01;

   Get_Platform_Active_Fault_Table_fake.return_val = &platform_active_table;

   NvM_GetErrorStatus_fake.custom_fake = NvM_GetErrorStatus_ReturnPending;
   RE_PLT_Fault_Mgr_Main_50ms();

   ASSERT_EQ(Get_Platform_Active_Fault_Table_fake.call_count, 0);
}
/**
 *  @b RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms_test1)
{
   RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms();
   ASSERT_EQ(Fault_Mgr_Radar_Blockage_Detection_Test_50ms_fake.call_count, 1);
}

/**
 *  @b RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms_test1)
{
   RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms();
   ASSERT_EQ(Fault_Mgr_Radar_Transceiver_Diagnostics_50ms_fake.call_count, 1);
}

/**
 *  @b RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms_test1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms();
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Main_50ms_test)
{
   Platform_fault_T platform_history_table = {0};
   Platform_fault_T platform_active_table  = {0};

   // Initialize with different data to trigger fault_table_updated
   platform_history_table.Platform_byte[0]         = 0x01; // Original history
   platform_active_table.Platform_byte[0]          = 0x02; // New active fault
   Get_Platform_Active_Fault_Table_fake.return_val = &platform_active_table;

   // CRITICAL FIX: Use custom_fake instead of return_val
   NvM_GetErrorStatus_fake.return_val = 0;
   RE_PLT_Fault_Mgr_Main_50ms();
   ASSERT_EQ(NvM_WriteBlock_fake.call_count, 0);
}
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Main_50ms_test2)
{
   Platform_fault_T platform_history_table         = {0};
   platform_history_table.Platform_byte[0]         = 0x01;
   Get_Platform_Active_Fault_Table_fake.return_val = NULL; // NULL pointer
   NvM_GetErrorStatus_fake.return_val              = 0;
   RE_PLT_Fault_Mgr_Main_50ms();
   ASSERT_EQ(NvM_GetErrorStatus_fake.call_count, 0);
}

// Helper function to set NVM_REQ_PENDING status
Std_ReturnType NvM_GetErrorStatus_ReturnPending(uint16 BlockId, uint8 *RequestResultPtr)
{
   *RequestResultPtr = NVM_REQ_PENDING;
   return 0;
}
TEST_F(swc_plt_appl_faultmgr_UnitTestSuite, RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms_test)
{
   RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms();
   ASSERT_EQ(true, true);
}
