/*===========================================================================*/
/**
 * @file Fault_Lib_Prj_unit_test.cc
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
 * Unit test suite for the checking the Fault_Lib_Prj.c file
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
#include "fff.h"

extern "C"
{
#include "Fault_Lib_Prj.c"
}

DEFINE_FFF_GLOBALS;
uint16 Fail_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];
uint16 Pass_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Fault_Lib_Prj_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
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

/*fake definition*/
/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Fault_Lib_sanity
 *  @n
 */
TEST_F(Fault_Lib_Prj_UnitTestSuite, Fault_Lib__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Customer_Fault_Enable_Table_test)
{
   *Get_Customer_Fault_Enable_Table();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Customer_Fault_Test_Completed_Table_test)
{
   *Get_Customer_Fault_Test_Completed_Table();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Customer_History_Fault_Table_test)
{
   *Get_Customer_History_Fault_Table();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Customer_Active_Fault_Latched_Table_test)
{
   *Get_Customer_Active_Fault_Latched_Table();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Customer_Active_Fault_Table_test)
{
   *Get_Customer_Active_Fault_Table();
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Platform_Active_Fault_Latched_Table_test)
{
   *Get_Platform_Active_Fault_Latch_Table();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Fault_Status_test)
{
   Customer_Active_Fault_Table.Customer_byte[1]  = 255;
   Customer_Active_Fault_Table.Customer_byte[2]  = 255;
   Customer_Active_Fault_Table.Customer_byte[3]  = 255;
   Customer_Active_Fault_Table.Customer_byte[4]  = 255;
   Customer_Active_Fault_Table.Customer_byte[5]  = 255;
   Customer_Active_Fault_Table.Customer_byte[6]  = 255;
   Customer_Active_Fault_Table.Customer_byte[7]  = 255;
   Customer_Active_Fault_Table.Customer_byte[8]  = 255;
   Customer_Active_Fault_Table.Customer_byte[9]  = 255;
   Customer_Active_Fault_Table.Customer_byte[10] = 255;
   Customer_Active_Fault_Table.Customer_byte[11] = 255;
   Customer_Active_Fault_Table.Customer_byte[12] = 255;
   Customer_Active_Fault_Table.Customer_byte[13] = 255;
   Customer_Active_Fault_Table.Customer_byte[14] = 255;
   Customer_Active_Fault_Table.Customer_byte[15] = 255;
   uint16 fault_name                             = 9;
   Customer_Get_Fault_Status(fault_name);
   ASSERT_EQ(Customer_Active_Fault_Table.Customer_byte[15], 255);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Get_Fault_Status_test_1)
{
   Customer_Active_Fault_Table.Customer_byte[1] = 0;
   uint16 fault_name                            = 9;
   Customer_Get_Fault_Status(fault_name);
   ASSERT_EQ(Customer_Active_Fault_Table.Customer_byte[1], 0);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Cust_Check_Fault_If_Enabled_test)
{
   Customer_Fault_Enable_Table.Customer_byte[1]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[2]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[3]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[4]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[5]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[6]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[7]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[8]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[9]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[10] = 255;
   Customer_Fault_Enable_Table.Customer_byte[11] = 255;
   Customer_Fault_Enable_Table.Customer_byte[12] = 255;
   Customer_Fault_Enable_Table.Customer_byte[13] = 255;
   Customer_Fault_Enable_Table.Customer_byte[14] = 255;
   Customer_Fault_Enable_Table.Customer_byte[15] = 255;
   Prj_Fault_Name_T fault_name                   = (Prj_Fault_Name_T)9;
   Cust_Check_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Cust_Check_Fault_If_Enabled_test1)
{
   Customer_Active_Fault_Table.Customer_byte[1] = 0;
   Prj_Fault_Name_T fault_name;
   Cust_Check_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Customer_Active_Fault_Table.Customer_byte[1], 0);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Set_Test_Completed_If_Enabled_test)
{
   Customer_Fault_Enable_Table.Customer_byte[1]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[2]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[3]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[4]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[5]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[6]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[7]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[8]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[9]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[10] = 255;
   Customer_Fault_Enable_Table.Customer_byte[11] = 255;
   Customer_Fault_Enable_Table.Customer_byte[12] = 255;
   Customer_Fault_Enable_Table.Customer_byte[13] = 255;
   Customer_Fault_Enable_Table.Customer_byte[14] = 255;
   Customer_Fault_Enable_Table.Customer_byte[15] = 255;
   uint16 fault_name                             = 9;
   Set_Test_Completed_If_Enabled(fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Set_Fault_If_Enabled_test)
{
   Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;
   Customer_Fault_Enable_Table.Customer_byte[1] = 1;
   uint16 fault_name                            = 9;
   Set_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[1], 1);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Clear_Fault_If_Enabled_and_Not_Latched_test)
{
   Customer_Fault_Enable_Table.Customer_byte[1]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[2]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[3]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[4]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[5]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[6]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[7]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[8]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[9]  = 255;
   Customer_Fault_Enable_Table.Customer_byte[10] = 255;
   Customer_Fault_Enable_Table.Customer_byte[11] = 255;
   Customer_Fault_Enable_Table.Customer_byte[12] = 255;
   Customer_Fault_Enable_Table.Customer_byte[13] = 255;
   Customer_Fault_Enable_Table.Customer_byte[14] = 255;
   Customer_Fault_Enable_Table.Customer_byte[15] = 255;
   uint16 fault_name                             = 9;
   Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Clear_Platform_Fault_Arrays_Prj_test)
{
   Clear_Platform_Fault_Arrays_Prj();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Clear_Platform_Fault_Information_Prj_test)
{
   uint16 fault_name;
   Clear_Platform_Fault_Information_Prj(fault_name);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Clear_Cust_Fault_Arrays_test)
{
   Clear_Cust_Fault_Arrays();
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Clear_Cust_Fault_Information_test)
{
   uint16 fault_name;
   Clear_Cust_Fault_Information(fault_name);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Cust_Fault_Enabled_Disable_test)
{
   Prj_Fault_Name_T fault_name;
   uint8 enable_status = 170;
   Cust_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_EQ(enable_status, DIAG_ENABLE_FAULT);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Cust_Fault_Enabled_Disable_test1)
{
   Prj_Fault_Name_T fault_name;
   uint8 enable_status = 85;
   Cust_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_EQ(enable_status, DIAG_DISABLE_FAULT);
}
TEST_F(Fault_Lib_Prj_UnitTestSuite, Cust_Fault_Enabled_Disable_test2)
{
   Prj_Fault_Name_T fault_name;
   uint8 enable_status = 50;
   boolean_T fault_Op_Status;
   Cust_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_NE(fault_Op_Status, DIAG_ENABLE_FAULT);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diag_No_Filter_Test_test1)
{
   uint8 test_status = DIAG_TEST_PASS;
   uint16 fault_name = MAX_NUMBER_OF_PLATFORM_TYPES - 1;
   for (uint16 i = 1; i < 16; i++)
   {
      Customer_Fault_Enable_Table.Customer_byte[i] = 255;
   }
   Clear_Fault_If_Enabled_and_Not_Latched(fault_name);

   Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diag_No_Filter_Test_test2)
{
   uint8 test_status = DIAG_TEST_PASS;
   uint16 fault_name = MAX_NUMBER_OF_PLATFORM_TYPES + 1;

   for (uint16 i = 1; i < 16; i++)
   {
      Customer_Fault_Enable_Table.Customer_byte[i] = 255;
   }
   Clear_Fault_If_Enabled_and_Not_Latched(fault_name);

   Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diag_No_Filter_Test_test3)
{
   uint8 test_status = DIAG_TEST_FAIL;
   uint16 fault_name = MAX_NUMBER_OF_PLATFORM_TYPES + 1;

   Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;
   Customer_Fault_Enable_Table.Customer_byte[1] = 1;
   Set_Fault_If_Enabled(fault_name);

   Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[1], 1);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diagnostics_Filter_Test_test1)
{
   uint16 fault_name       = MAX_NUMBER_OF_PLATFORM_TYPES + 1;
   uint8 test_status       = DIAG_TEST_PASS;
   uint16 fault_fail_limit = 5;
   uint16 fault_pass_limit = 3;
   uint16 fail_counter_ptr = 2;
   uint16 pass_counter_ptr = 0;

   for (uint16 i = 1; i < 16; i++)
   {
      Customer_Fault_Enable_Table.Customer_byte[i] = 255;
   }
   Clear_Fault_If_Enabled_and_Not_Latched(fault_name);

   Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, &fail_counter_ptr, &pass_counter_ptr);
   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
   ASSERT_EQ(pass_counter_ptr, 1);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diagnostics_Filter_Test_test2)
{
   uint16 fault_name       = MAX_NUMBER_OF_PLATFORM_TYPES + 1;
   uint8 test_status       = DIAG_TEST_PASS;
   uint16 fault_fail_limit = 5;
   uint16 fault_pass_limit = 3;
   uint16 fail_counter_ptr = 0;
   uint16 pass_counter_ptr = 2;

   for (uint16 i = 1; i < 16; i++)
   {
      Customer_Fault_Enable_Table.Customer_byte[i] = 255;
   }
   Clear_Fault_If_Enabled_and_Not_Latched(fault_name);

   Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, &fail_counter_ptr, &pass_counter_ptr);

   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[15], 255);
   ASSERT_EQ(pass_counter_ptr, 3);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diagnostics_Filter_Test_test3)
{
   uint16 fault_name       = MAX_NUMBER_OF_PLATFORM_TYPES + 1;
   uint8 test_status       = DIAG_TEST_FAIL;
   uint16 fault_fail_limit = 5;
   uint16 fault_pass_limit = 3;
   uint16 fail_counter_ptr = 0;
   uint16 pass_counter_ptr = 4;

   Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;
   Customer_Fault_Enable_Table.Customer_byte[1] = 1;
   Set_Fault_If_Enabled(fault_name);
   Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, &fail_counter_ptr, &pass_counter_ptr);

   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[1], 1);
   ASSERT_EQ(fail_counter_ptr, 1);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diagnostics_Filter_Test_test4)
{
   uint16 fault_name       = MAX_NUMBER_OF_PLATFORM_TYPES + 1;
   uint8 test_status       = DIAG_TEST_FAIL;
   uint16 fault_fail_limit = 5;
   uint16 fault_pass_limit = 3;
   uint16 fail_counter_ptr = 4;
   uint16 pass_counter_ptr = 0;

   Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;
   Customer_Fault_Enable_Table.Customer_byte[1] = 1;
   Set_Fault_If_Enabled(fault_name);
   Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, &fail_counter_ptr, &pass_counter_ptr);

   ASSERT_EQ(Customer_Fault_Enable_Table.Customer_byte[1], 1);
   ASSERT_EQ(fail_counter_ptr, 5);
}

TEST_F(Fault_Lib_Prj_UnitTestSuite, Diagnostics_Filter_Test_test5)
{
   uint16 fault_name       = MAX_NUMBER_OF_PLATFORM_TYPES - 1;
   uint8 test_status       = DIAG_TEST_PASS;
   uint16 fault_fail_limit = 5;
   uint16 fault_pass_limit = 3;
   uint16 fail_counter_ptr = 0;
   uint16 pass_counter_ptr = 4;

   Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, &fail_counter_ptr, &pass_counter_ptr);

   ASSERT_EQ(fail_counter_ptr, 0);
   ASSERT_EQ(pass_counter_ptr, 4);
}
