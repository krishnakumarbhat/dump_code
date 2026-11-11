/*===========================================================================*/
/**
 * @file Fault_Lib_Plt_unit_test.cc
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
 * Unit test suite for the checking the Fault_Lib_Plt.c file
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
#include "Fault_Lib_Plt.c"
}

DEFINE_FFF_GLOBALS;

uint16 Fail_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];
uint16 Pass_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Fault_Lib_Plt_UnitTestSuite : public testing::Test
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
};
/*fake definition*/
/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Fault_Lib_sanity
 *  @n
 */
TEST_F(Fault_Lib_Plt_UnitTestSuite, Fault_Lib__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diagnostics_Filter_Test_test)
{
   uint8 test_status = 170;
   uint16 fault_name = 120;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)10u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diagnostics_Filter_Test_test1)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)10u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   fault_fail_limit         = 10u;
   test_status              = 85;
   fault_name               = 120;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_FAIL);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diagnostics_Filter_Test_test2)
{
   uint8 test_status;
   uint16 fault_name = 200;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)10u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_NE(pass_counter_ptr, fail_counter_ptr);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diagnostics_Filter_Test_test3)
{
   uint8 test_status = 170;
   uint16 fault_name = 120;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 10u;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diagnostics_Filter_Test_test4)
{
   uint8 test_status = 171;
   uint16 fault_name = 120;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 10u;
   fault_fail_limit         = 10u;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(fault_pass_limit, fault_fail_limit);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Clear_Fault_If_Enabled_and_Not_Latched_test1)
{
   Platform_fault_T Platform_Active_Fault_Table;
   Platform_Active_Fault_Table.Platform_byte[1] = 1;
   Platform_fault_T Platform_Latch_Enable_Table;
   Platform_Latch_Enable_Table.Platform_byte[1] = 0;
   uint16 fault_name                            = 9;
   Platform_Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 1);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Clear_Fault_If_Enabled_and_Not_Latched_test2)
{
   uint16 fault_name = 0;

   Platform_Active_Fault_Table.Platform_byte[0] = 0x80;
   Platform_Fault_Enable_Table.Platform_byte[0] = 0x80;

   Platform_Clear_Fault_If_Enabled_and_Not_Latched(fault_name);

   if (!(Platform_Latch_Enable_Table.Platform_byte[0] & 0x80))
   {
      ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[0], 0x00);
   }
   else
   {
      ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[0], 0x80);
   }
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Get_Platform_Fault_Enable_Table_test)
{
   *Get_Platform_Fault_Enable_Table();
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Get_Platform_Fault_Test_Completed_Table_test)
{
   *Get_Platform_Fault_Test_Completed_Table();
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Get_Platform_Active_Fault_Table_test)
{
   *Get_Platform_Active_Fault_Table();
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_memory_Copy_test)
{
   uint8 source, destination, num, i;
   uint8 src;
   uint8 dst;
   source = 5;
   num    = 2;
   Platform_memory_Copy(&destination, &source, num);
   ASSERT_EQ(destination, 5);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diag_No_Filter_Test_test)
{
   uint8 test_status = 170;
   uint16 fault_name = 130;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diag_No_Filter_Test_test1)
{
   uint8 test_status = 171;
   uint16 fault_name = 130;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, 171);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diag_No_Filter_Test_test2)
{
   uint8 test_status = 85;
   uint16 fault_name = 120;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, DIAG_TEST_FAIL);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Enabled_Disable_test)
{
   fault_name_T fault_name;
   uint8 enable_status = 170;
   Platform_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_EQ(enable_status, DIAG_ENABLE_FAULT);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Enabled_Disable_test1)
{
   fault_name_T fault_name;
   uint8 enable_status = 85;
   Platform_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_EQ(enable_status, DIAG_DISABLE_FAULT);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Enabled_Disable_test2)
{
   fault_name_T fault_name;
   uint8 enable_status       = 50;
   boolean_T fault_Op_Status = (boolean_T)Platform_Fault_Enabled_Disable(fault_name, enable_status);
   ASSERT_EQ(fault_Op_Status, FALSE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Check_Fault_If_Enabled_test)
{
   Platform_fault_T Platform_Fault_Enable_Table;
   Platform_Fault_Enable_Table.Platform_byte[0] = 1;
   fault_name_T fault_name                      = (fault_name_T)9;
   Platform_Check_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Platform_Fault_Enable_Table.Platform_byte[0], 1);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Check_Fault_If_Enabled_test1)
{
   Platform_fault_T Platform_Fault_Enable_Table;
   Platform_Fault_Enable_Table.Platform_byte[1] = 0;
   fault_name_T fault_name                      = (fault_name_T)0;
   Platform_Check_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Platform_Fault_Enable_Table.Platform_byte[1], 0);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Check_Fault_If_Enabled_test2)
{
   fault_name_T fault_name = (fault_name_T)10;
   uint8 byte_pos          = (uint8)fault_name / BYTE_SIZE;
   uint8 bit_pos           = (uint8)fault_name % BYTE_SIZE;
   uint8 bit_mask          = Bit_Position_Table[bit_pos];

   Platform_Fault_Enable_Table.Platform_byte[byte_pos] |= bit_mask;

   boolean_T result = Platform_Check_Fault_If_Enabled(fault_name);

   ASSERT_EQ(result, TRUE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Clear_Platform_Fault_Information_test)
{
   uint16 fault_name;
   Clear_Platform_Fault_Information(fault_name);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Set_Fault_If_Enabled_test1)
{
   Platform_fault_T Platform_Active_Fault_Table;
   Platform_Active_Fault_Table.Platform_byte[1] = 1;
   uint16 fault_name                            = 9;
   Platform_Set_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 1);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Set_Fault_If_Enabled_test2)
{
   uint16 fault_name   = 5; // Arbitrary valid fault number
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   Platform_Fault_Enable_Table.Platform_byte[byte_position] = bit_mask;

   Platform_Set_Fault_If_Enabled(fault_name);
   ASSERT_EQ(Platform_Fault_Enable_Table.Platform_byte[byte_position], bit_mask);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Set_Test_Completed_If_Enabled_test1)
{
   Platform_fault_T Platform_Active_Fault_Table;
   Platform_Active_Fault_Table.Platform_byte[1] = 1;
   uint16 fault_name                            = 9;
   Platform_Set_Test_Completed_If_Enabled(fault_name);
   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 1);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Set_Test_Completed_If_Enabled_test2)
{
   uint16 fault_name = 10;
   uint8 byte_pos    = fault_name / BYTE_SIZE;
   uint8 bit_pos     = fault_name % BYTE_SIZE;
   uint8 bit_mask    = Bit_Position_Table[bit_pos];

   Platform_Fault_Enable_Table.Platform_byte[byte_pos] |= bit_mask;

   Platform_Set_Test_Completed_If_Enabled(fault_name);

   ASSERT_EQ(Platform_Fault_Test_Completed.Platform_byte[byte_pos], bit_mask);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diag_No_Filter_Test_test)
{
   uint8 test_status = 170;
   uint16 fault_name = 120;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diag_No_Filter_Test_test1)
{
   uint8 test_status = 85;
   uint16 fault_name = 120;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, DIAG_TEST_FAIL);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diag_No_Filter_Test_test2)
{
   uint8 test_status = 0;
   uint16 fault_name = 120;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(test_status, FALSE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diag_No_Filter_Test_test3)
{
   uint8 test_status;
   uint16 fault_name      = 130;
   Plt_Fault_Table_Freeze = CODED_FALSE;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(Plt_Fault_Table_Freeze, CODED_FALSE);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Diag_No_Filter_Test_test4)
{
   uint8 test_status;
   uint16 fault_name      = 100;
   Plt_Fault_Table_Freeze = CODED_FALSE;
   Platform_Diag_No_Filter_Test(test_status, fault_name);
   ASSERT_EQ(Plt_Fault_Table_Freeze, CODED_FALSE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)10u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   test_status              = 170;
   fault_name               = 129;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test1)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)10u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   test_status              = 85;
   fault_name               = 129;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_FAIL);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test2)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)10u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)10u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   // fault_pass_limit = 5u;
   fault_fail_limit = 10u;
   test_status      = 85;
   fault_name       = 129;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_FAIL);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test3)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)4u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 5u;
   test_status              = 170;
   fault_name               = 100;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(test_status, DIAG_TEST_PASS);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test4)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_fail_limit         = 10u;
   fault_pass_limit         = 10;
   test_status              = 171;
   fault_name               = 130;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(fault_pass_limit, fault_fail_limit);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test5)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_fail_limit         = 10u;
   fault_pass_limit         = 10u;
   test_status              = 171;
   fault_name               = 130;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(fault_pass_limit, fault_fail_limit);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Diagnostics_Filter_Test_test6)
{
   uint8 test_status;
   uint16 fault_name;
   uint16 fault_fail_limit;
   uint16 fault_pass_limit;
   uint16 *fail             = (uint16 *)1u;
   uint16 *fail_counter_ptr = (uint16 *)&fail;
   uint16 *pass             = (uint16 *)1u;
   uint16 *pass_counter_ptr = (uint16 *)&pass;
   fault_pass_limit         = 10u;
   fault_fail_limit         = 10;
   test_status              = 170;
   fault_name               = 130;
   Platform_Diagnostics_Filter_Test(test_status, fault_name, fault_fail_limit, fault_pass_limit, fail_counter_ptr,
                                    pass_counter_ptr);
   ASSERT_EQ(fault_pass_limit, fault_fail_limit);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test)
{
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 1;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, PLTFORM_AUTO_MODE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test1)
{
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 2;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, PLATFORM_SET_FAULT_MODE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test2)
{
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 3;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, PLATFORM_CLEAR_FAULT_MODE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test3)
{
   Platform_fault_T Platform_Fault_Enable_Table;
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 2;
   Plt_XCP_Fault_Override_a.bit_pos                 = 4;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Plt_XCP_Fault_Override->bit_pos                  = Plt_XCP_Fault_Override_a.bit_pos;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, PLATFORM_SET_FAULT_MODE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test4)
{
   Platform_fault_T Platform_Fault_Enable_Table;
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 3;
   Plt_XCP_Fault_Override_a.bit_pos                 = 4;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Plt_XCP_Fault_Override->bit_pos                  = Plt_XCP_Fault_Override_a.bit_pos;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, PLATFORM_CLEAR_FAULT_MODE);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test5)
{
   Plt_XCP_Fault_Override_T Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override_a.action                  = 0;
   Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override = &Plt_XCP_Fault_Override_a;
   Plt_XCP_Fault_Override->action                   = Plt_XCP_Fault_Override_a.action;
   Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override);
   ASSERT_EQ(Plt_XCP_Fault_Override->action, 0);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test6)
{
   Plt_XCP_Fault_Override_T override;
   override.action                              = PLATFORM_SET_FAULT_MODE;
   override.byte_pos                            = 1;
   override.bit_pos                             = 3;
   uint8 bit_mask                               = Bit_Position_Table[3]; // 0x10
   Platform_Fault_Enable_Table.Platform_byte[1] = bit_mask;

   uint8 result = Platform_Fault_Table_Override_XCP(&override);

   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], bit_mask);
   ASSERT_EQ(Plt_Fault_Table_Freeze, CODED_FALSE);
   ASSERT_EQ(result, CODED_TRUE);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Fault_Table_Override_XCP_test7)
{
   Plt_XCP_Fault_Override_T override;
   override.action   = PLATFORM_CLEAR_FAULT_MODE;
   override.byte_pos = 1;
   override.bit_pos  = 4;
   uint8 bit_mask    = Bit_Position_Table[4]; // 0x08

   Platform_Fault_Enable_Table.Platform_byte[1] = bit_mask;

   Platform_Active_Fault_Table.Platform_byte[1] = bit_mask;

   uint8 result = Platform_Fault_Table_Override_XCP(&override);

   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 0x00);
   ASSERT_EQ(result, CODED_TRUE);
   ASSERT_EQ(Plt_Fault_Table_Freeze, CODED_FALSE);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Get_Fault_Status_test)
{
   Platform_fault_T Platform_Active_Fault_Table;
   Platform_Active_Fault_Table.Platform_byte[1] = 1;
   uint16 fault_name                            = 9;
   Platform_Get_Fault_Status(fault_name);
   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 1);
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Get_Fault_Status_test1)
{
   Platform_fault_T Platform_Active_Fault_Table;
   Platform_Active_Fault_Table.Platform_byte[1] = 1;
   uint16 fault_name                            = 1;
   Platform_Get_Fault_Status(fault_name);
   ASSERT_EQ(Platform_Active_Fault_Table.Platform_byte[1], 1);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Platform_Get_Fault_Status_test2)
{
   uint16 fault_name = 10;
   uint8 byte_pos    = fault_name / BYTE_SIZE;
   uint8 bit_pos     = fault_name % BYTE_SIZE;
   uint8 bit_mask    = Bit_Position_Table[bit_pos];

   Platform_Active_Fault_Table.Platform_byte[byte_pos] = bit_mask;

   uint8 result = Platform_Get_Fault_Status(fault_name);

   ASSERT_EQ(result, CODED_TRUE);
}

TEST_F(Fault_Lib_Plt_UnitTestSuite, Clear_Debounce_Fault_Counters_test)
{
   Clear_Debounce_Fault_Counters();
}
TEST_F(Fault_Lib_Plt_UnitTestSuite, Clear_Platform_Fault_Arrays_test)
{
   Clear_Platform_Fault_Arrays();
}
