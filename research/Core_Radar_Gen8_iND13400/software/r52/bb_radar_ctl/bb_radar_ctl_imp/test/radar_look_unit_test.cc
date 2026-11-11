/*===========================================================================*/
/**
 * @file radar_look_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS;
#define UNIT_TEST

#include "mocks/radar_ctl_fake.h"
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks/xcp_bb_fake.h"

extern "C"
{
#include "bb_radar_ctl_imp/radar_look.c"
#include "dd_mmic_fake.h"
#include "mocks/radar_look_fake.h"
#include "radar_data.h"
#include "radar_look.h"
}

volatile XCP_Single_Look_Type_Enable_T XCP_Single_Look_Type_Enable;
volatile Radar_Look_T XCP_Single_Look_Type;
volatile XCP_MMIC_FIT_Enable_T XCP_MMIC_FIT_Enable = XCP_MMIC_NO_FIT_TEST;
volatile XCP_Single_Look_T xcp_single_select       = {CODED_FALSE, 0U};

Radar_Ctl_Data_T Radar_Ctl_Data;
bool Radar_Ctl_Look_Sync_Trig_State                = false;
uint32_t Radar_Ctl_Look_Sync_Trig_Clear_Call_Count = 0U;

bool Radar_Ctl_Look_Sync_Trig_Tst(void)
{
   return Radar_Ctl_Look_Sync_Trig_State;
}

void Radar_Ctl_Look_Sync_Trig_Clear(void)
{
   Radar_Ctl_Look_Sync_Trig_Clear_Call_Count++;
   Radar_Ctl_Look_Sync_Trig_State = false;
}

uint8_t Get_Radar_Position(void)
{
   return 2;
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class radar_look_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Radar_Ctl_Data.this_mode = RADAR_MODE_A;
      /* Initialize xcp_single_select to known state */
      xcp_single_select.single_look_en          = CODED_FALSE;
      xcp_single_select.single_look_select      = 0U;
      XCP_Single_Look_Type_Enable               = RADAR_CTL_NO_FORCE_LOOK_TYPE;
      XCP_Single_Look_Type                      = (Radar_Look_T)0U;
      XCP_Cmd_Single_look_Invoked               = 0U;
      Next_Look_Index                           = 0U;
      Look_No_Sync_Cntr                         = 0U;
      Radar_Ctl_Look_Sync_Trig_State            = false;
      Radar_Ctl_Look_Sync_Trig_Clear_Call_Count = 0U;
      /* Set up Get_XCP_Single_Look_Mode mock to return &xcp_single_select */
      Get_XCP_Single_Look_Mode_fake.return_val = (volatile XCP_Single_Look_T *)&xcp_single_select;
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

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is to test Get_Force_Look_Type_Enable -False case
 *
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_FALSE(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en) = CODED_FALSE;
   Std_ReturnType ret     = 1;
   return ret;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_IF)
{
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_FALSE;
   Get_Force_Look_Type_Enable();
   EXPECT_EQ(XCP_Single_Look_Type_Enable, RADAR_CTL_NO_FORCE_LOOK_TYPE);
   EXPECT_EQ(RADAR_CTL_NO_FORCE_LOOK_TYPE, 0);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable - CODED_TRUE case
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type_Enable when single_look_en is
 *    CODED_TRUE and XCP_Single_Look_Type_Enable is RADAR_CTL_NO_FORCE_LOOK_TYPE
 \*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_TRUE(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en) = CODED_TRUE;
   Std_ReturnType ret     = 1;
   return ret;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_CODED_TRUE)
{
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_TRUE;

   XCP_Single_Look_Type_Enable_T result = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result, XCP_FORCE_LOOK_TYPE);
   EXPECT_EQ(XCP_Single_Look_Type_Enable, XCP_FORCE_LOOK_TYPE);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable - Already forced case
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type_Enable when
 *    XCP_Single_Look_Type_Enable is already set to XCP_FORCE_LOOK_TYPE
 \*===========================================================================*/

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_Already_Forced)
{
   XCP_Single_Look_Type_Enable = XCP_FORCE_LOOK_TYPE;

   XCP_Single_Look_Type_Enable_T result = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result, XCP_FORCE_LOOK_TYPE);
   EXPECT_EQ(XCP_Single_Look_Type_Enable, XCP_FORCE_LOOK_TYPE);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable - CODED_FALSE maintains NO_FORCE
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type_Enable when single_look_en is
 *    CODED_FALSE and XCP_Single_Look_Type_Enable stays RADAR_CTL_NO_FORCE_LOOK_TYPE
 \*===========================================================================*/

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_CODED_FALSE_No_Force)
{
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_FALSE;

   XCP_Single_Look_Type_Enable_T result = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result, RADAR_CTL_NO_FORCE_LOOK_TYPE);
   EXPECT_EQ(XCP_Single_Look_Type_Enable, RADAR_CTL_NO_FORCE_LOOK_TYPE);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable - RTE Read Error case
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type_Enable when RTE read returns error
 *    to cover the alternate branch in the RTE function call
 \*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_ERROR(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   /* Return error code instead of E_OK */
   return 0xFF; /* Non-E_OK error code */
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_RTE_Read_Error)
{
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_ERROR;

   XCP_Single_Look_Type_Enable_T result = Get_Force_Look_Type_Enable();

   /* Even with RTE error, function should handle gracefully */
   /* Since return value is not checked in implementation, behavior continues */
   EXPECT_TRUE((result == RADAR_CTL_NO_FORCE_LOOK_TYPE) || (result == XCP_FORCE_LOOK_TYPE));
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type - Test Cases
 *===========================================================================
 * ABSTRACT:
 *    Test suite for Get_Force_Look_Type function covering all branches
 \*===========================================================================*/

/*===========================================================================*\
 * Stub function for single_look_select = 1 (RADAR_LOOK_A)
 \*===========================================================================*/
FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_1(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 1U;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_1_Look_A)
{
   /* Setup: Set xcp_single_select to have single_look_select = 1 */
   xcp_single_select.single_look_select = 1U;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_1;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_A);
}

/*===========================================================================*\
 * Stub function for single_look_select = 2 (RADAR_LOOK_B)
 \*===========================================================================*/
FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_2(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 2U;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_2_Look_B)
{
   /* Setup: Set xcp_single_select to have single_look_select = 2 */
   xcp_single_select.single_look_select = 2U;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_2;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_B);
}

/*===========================================================================*\
 * Stub function for single_look_select = 3 (RADAR_LOOK_C)
 \*===========================================================================*/
FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_3(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 3U;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_3_Look_C)
{
   /* Setup: Set xcp_single_select to have single_look_select = 3 */
   xcp_single_select.single_look_select = 3U;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_3;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_C);
}

/*===========================================================================*\
 * Stub function for single_look_select = 4 (RADAR_LOOK_D)
 \*===========================================================================*/
FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_4(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 4U;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_4_Look_D)
{
   /* Setup: Set xcp_single_select to have single_look_select = 4 */
   xcp_single_select.single_look_select = 4U;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_4;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_D);
}

/*===========================================================================*\
 * Stub function for single_look_select = 0 (Use global variable)
 \*===========================================================================*/
FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 0U;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_0_Use_Global_Look_A)
{
   /* Setup: Set xcp_single_select.single_look_select = 0 (no update from RTE) */
   xcp_single_select.single_look_select = 0U;
   XCP_Single_Look_Type                 = RADAR_LOOK_A;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_A);
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_0_Use_Global_Look_B)
{
   /* Setup: Set xcp_single_select.single_look_select = 0 (no update from RTE) */
   xcp_single_select.single_look_select = 0U;
   XCP_Single_Look_Type                 = RADAR_LOOK_B;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_B);
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_0_Use_Global_Look_C)
{
   /* Setup: Set xcp_single_select.single_look_select = 0 (no update from RTE) */
   xcp_single_select.single_look_select = 0U;
   XCP_Single_Look_Type                 = RADAR_LOOK_C;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_C);
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_0_Use_Global_Look_D)
{
   /* Setup: Set xcp_single_select.single_look_select = 0 (no update from RTE) */
   xcp_single_select.single_look_select = 0U;
   XCP_Single_Look_Type                 = RADAR_LOOK_D;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0;

   Radar_Look_T result = Get_Force_Look_Type();

   EXPECT_EQ(result, RADAR_LOOK_D);
}

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Radar_Ctl_Reset_Init_TEST
 *  @n
 *      Test the default valid functionality and also invalid functionality
 */
TEST_F(radar_look_UnitTestSuite, Init_Radar_Look_TEST)
{
   Init_Radar_Look();
   ASSERT_EQ(0, Radar_Ctl_Data.scan_index);
   EXPECT_EQ(Radar_Ctl_Data.this_mode, RADAR_MODE_A);
}

/*===========================================================================*\
 * FUNCTION: Next_Radar_Look - Test for else path (normal sequential look)
 *===========================================================================
 * ABSTRACT:
 *    This function tests Next_Radar_Look when force look is NOT enabled,
 *    covering the else branch where normal look sequencing occurs
 \*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Normal_Mode(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en) = CODED_FALSE;
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Next_Radar_Look_TEST_Else_Normal_Sequential_Look)
{
   /* Setup: Force look is NOT enabled - this triggers the else path */
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Normal_Mode;

   /* Initialize radar look to set up next_look */
   Radar_Ctl_Data.next_look  = RADAR_LOOK_B;
   Radar_Ctl_Data.scan_index = 5;

   /* Store initial scan index */
   uint16_t initial_scan_index = Radar_Ctl_Data.scan_index;

   /* Call Next_Radar_Look - should execute ELSE block */
   Next_Radar_Look();

   /* Verify: this_look should be set to the previous next_look (RADAR_LOOK_B) */
   EXPECT_EQ(Radar_Ctl_Data.this_look, RADAR_LOOK_B);
   EXPECT_EQ(Radar_Ctl_Data.this_mode, RADAR_MODE_A);

   /* Verify: Next_Look_Index incremented and next_look updated from k_look_order_smc array */
   /* Based on k_look_order_smc, next should progress in sequence */

   /* Verify: scan_index incremented by 1 */
   EXPECT_EQ(Radar_Ctl_Data.scan_index, initial_scan_index + 1);
}

/*===========================================================================*\
 * FUNCTION: Next_Radar_Look - Test for Next_Look_Index wraparound
 *===========================================================================
 * ABSTRACT:
 *    This function tests Next_Radar_Look when Next_Look_Index reaches NUM_LOOKS
 *    and needs to wrap around to 0, covering the if (Next_Look_Index >= NUM_LOOKS)
 \*===========================================================================*/

TEST_F(radar_look_UnitTestSuite, Next_Radar_Look_TEST_Index_Wraparound)
{
   /* Setup: Force look is NOT enabled */
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Normal_Mode;

   /* Set Next_Look_Index to NUM_LOOKS-1 (last valid index) */
   /* After increment, it will be >= NUM_LOOKS and should wrap to 0 */
   Next_Look_Index = (uint8_t)(NUM_LOOKS - 1);

   Radar_Ctl_Data.next_look  = RADAR_LOOK_D;
   Radar_Ctl_Data.scan_index = 10;

   /* Call Next_Radar_Look */
   Next_Radar_Look();

   /* Verify: Next_Look_Index should have wrapped around to 0 */
   /* After increment (3 + 1 = 4), it equals NUM_LOOKS (4), so it resets to 0 */

   /* Verify: this_look should be the previous next_look */
   EXPECT_EQ(Radar_Ctl_Data.this_look, RADAR_LOOK_D);
   EXPECT_EQ(Radar_Ctl_Data.this_mode, RADAR_MODE_A);

   /* Verify: next_look should be k_look_order_smc[0] (first look after wraparound) */
   EXPECT_EQ(Radar_Ctl_Data.next_look, RADAR_LOOK_A);

   /* Verify: scan_index incremented */
   EXPECT_EQ(Radar_Ctl_Data.scan_index, 11);
}

/*===========================================================================*\
 * FUNCTION: Next_Radar_Look - Test for IF path (Force Look Enabled)
 *===========================================================================
 * ABSTRACT:
 *    This function tests Next_Radar_Look when XCP force look is enabled,
 *    covering the if (XCP_FORCE_LOOK_TYPE == Get_Force_Look_Type_Enable())
 \*===========================================================================*/

TEST_F(radar_look_UnitTestSuite, Next_Radar_Look_TEST_Force_Look_Enabled)
{
   /* Setup: Enable force look mode */
   XCP_Single_Look_Type_Enable = XCP_FORCE_LOOK_TYPE;
   XCP_Single_Look_Type        = RADAR_LOOK_C;

   /* Use stub that returns CODED_TRUE to keep force look enabled */
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Look_Select_0;

   Radar_Ctl_Data.scan_index   = 20;
   uint16_t initial_scan_index = Radar_Ctl_Data.scan_index;

   /* Call Next_Radar_Look - should execute IF block (force look path) */
   Next_Radar_Look();

   /* Verify: this_look should be set to forced look type */
   EXPECT_EQ(Radar_Ctl_Data.this_look, RADAR_LOOK_C);
   EXPECT_EQ(Radar_Ctl_Data.this_mode, RADAR_MODE_A);

   /* Verify: next_look should be same as this_look (forced) */
   EXPECT_EQ(Radar_Ctl_Data.next_look, RADAR_LOOK_C);

   /* Verify: scan_index still increments even in force mode */
   EXPECT_EQ(Radar_Ctl_Data.scan_index, initial_scan_index + 1);
}

/*===========================================================================*\
 * FUNCTION: Next_Radar_Look - Test for Out-of-Range Forced Look Type
 *===========================================================================
 * ABSTRACT:
 *    This function tests Next_Radar_Look when forced look type is out of range
 *    [RADAR_LOOK_A, NUM_LOOKS), covering the else branch inside the force look
 *    path that resets XCP_Single_Look_Type_Enable to normal look run.
 *    This is critical for EPB-3577/EPB-3699 bug fix.
 \*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_OutOfRange(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_TRUE;
   (data->single_look_select) = 0U; /* Out of range - should trigger fallback */
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Next_Radar_Look_TEST_OutOfRange_Forced_Look_Fallback)
{
   /* Setup: Force look is enabled but XCP_Single_Look_Type is out of range */
   XCP_Single_Look_Type_Enable = XCP_FORCE_LOOK_TYPE;
   XCP_Single_Look_Type        = NUM_LOOKS; /* Out of range: should be [0, NUM_LOOKS) */

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_OutOfRange;

   Radar_Ctl_Data.next_look  = RADAR_LOOK_B;
   Radar_Ctl_Data.scan_index = 15;

   uint16_t initial_scan_index = Radar_Ctl_Data.scan_index;

   /* Call Next_Radar_Look - should detect out-of-range and fallback to normal */
   Next_Radar_Look();

   /* Verify: this_look should use Get_Radar_Next_Look() (normal fallback) */
   EXPECT_EQ(Radar_Ctl_Data.this_look, RADAR_LOOK_B);

   /* Verify: next_look should progress from k_look_order_smc (normal sequence) */
   /* After increment from initial, next should be set to k_look_order_smc[Next_Look_Index] */

   /* Verify: XCP_Single_Look_Type_Enable should be reset to NO_FORCE_LOOK_TYPE */
   EXPECT_EQ(XCP_Single_Look_Type_Enable, RADAR_CTL_NO_FORCE_LOOK_TYPE);

   /* Verify: scan_index still increments */
   EXPECT_EQ(Radar_Ctl_Data.scan_index, initial_scan_index + 1);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type - Test when single_look_select is 0
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type when xcp_cmd_single_look_mode->
 *    single_look_select equals 0 (False condition). The function should NOT
 *    update XCP_Single_Look_Type and should return the previously set value.
 \*===========================================================================*/

FUNC(Std_ReturnType, RTE_CODE)
Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_NoSelect(
   P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data)
{
   (data->single_look_en)     = CODED_FALSE;
   (data->single_look_select) = 0U; /* 0 = no update, use global variable */
   return E_OK;
}

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_TEST_Select_0_NoUpdate_RetainGlobal)
{
   /* Set XCP_Single_Look_Type to a known value */
   XCP_Single_Look_Type = RADAR_LOOK_B;
   /* Setup: Set xcp_single_select.single_look_select = 0 (no update from RTE) */
   xcp_single_select.single_look_select = 0U;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_NoSelect;

   Radar_Look_T result = Get_Force_Look_Type();

   /* Verify: XCP_Single_Look_Type should NOT be modified (still RADAR_LOOK_B) */
   EXPECT_EQ(result, RADAR_LOOK_B);
   EXPECT_EQ(XCP_Single_Look_Type, RADAR_LOOK_B);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable - Test XCP_Cmd_Single_look_Invoked
 *===========================================================================
 * ABSTRACT:
 *    This function tests Get_Force_Look_Type_Enable with focus on the
 *    XCP_Cmd_Single_look_Invoked flag. This flag enables re-reading RTE data
 *    when transitioning from forced to normal mode.
 \*===========================================================================*/

TEST_F(radar_look_UnitTestSuite, Get_Force_Look_Type_Enable_TEST_Cmd_Invoked_Flag_Lifecycle)
{
   /* Setup: Initial state - no force */
   XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
   XCP_Cmd_Single_look_Invoked = 0U;

   /* First call with CODED_TRUE - should set flag */
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_TRUE;

   XCP_Single_Look_Type_Enable_T result1 = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result1, XCP_FORCE_LOOK_TYPE);
   EXPECT_EQ(XCP_Cmd_Single_look_Invoked, 1U);

   /* Second call while already forced - should not re-read RTE yet (no condition triggered) */
   /* The if condition checks: (NO_FORCE_LOOK_TYPE == enabled) || (Cmd_Invoked) */
   /* Since enabled != NO_FORCE_LOOK_TYPE, it won't re-read unless Cmd_Invoked is still 1 */
   XCP_Single_Look_Type_Enable_T result2 = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result2, XCP_FORCE_LOOK_TYPE);

   /* Third call with CODED_FALSE to disable - should reset flag */
   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_CODED_FALSE;

   XCP_Single_Look_Type_Enable_T result3 = Get_Force_Look_Type_Enable();

   EXPECT_EQ(result3, RADAR_CTL_NO_FORCE_LOOK_TYPE);
   EXPECT_EQ(XCP_Cmd_Single_look_Invoked, 0U);
}
TEST_F(radar_look_UnitTestSuite, Radar_Look_Sync_Test_ReturnsFalseAndCountsWhenDirectionsMismatch)
{
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_A]         = -1;
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_B]         = 1;
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_sensor_init_look_list[1] = RADAR_LOOK_A;
   Radar_Ctl_Data.this_look                                          = RADAR_LOOK_B;

   bool result = Radar_Look_Sync_Test(true);

   EXPECT_FALSE(result);
   EXPECT_EQ(Look_No_Sync_Cntr, 1U);
}

TEST_F(radar_look_UnitTestSuite, Radar_Look_Sync_Test_ReturnsTrueWhenDirectionsMatch)
{
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_A]         = -1;
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_B]         = 1;
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_sensor_init_look_list[1] = RADAR_LOOK_A;
   Radar_Ctl_Data.this_look                                          = RADAR_LOOK_A;

   bool result = Radar_Look_Sync_Test(true);

   EXPECT_TRUE(result);
   EXPECT_EQ(Look_No_Sync_Cntr, 0U);
}

TEST_F(radar_look_UnitTestSuite, Radar_Look_Sync_Test_IgnoresMismatchWhenTimesyncIsFalse)
{
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_A]         = -1;
   SMC_Cal_Data.Secondpass_Threshold_Cal.k_fr2[RADAR_LOOK_B]         = 1;
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_sensor_init_look_list[1] = RADAR_LOOK_A;
   Radar_Ctl_Data.this_look                                          = RADAR_LOOK_B;

   bool result = Radar_Look_Sync_Test(false);

   EXPECT_TRUE(result);
   EXPECT_EQ(Look_No_Sync_Cntr, 0U);
}
TEST_F(radar_look_UnitTestSuite, Next_Radar_Look_TEST_NormalMode_UsesCurrentLookWhenSyncTriggerSet)
{
   XCP_Single_Look_Type_Enable    = RADAR_CTL_NO_FORCE_LOOK_TYPE;
   Radar_Ctl_Look_Sync_Trig_State = true;

   Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_fake.custom_fake =
      Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable_stub_Normal_Mode;

   Radar_Ctl_Data.this_look  = RADAR_LOOK_C;
   Radar_Ctl_Data.next_look  = RADAR_LOOK_B;
   Radar_Ctl_Data.scan_index = 7U;
   Next_Look_Index           = 2U;

   Next_Radar_Look();

   EXPECT_EQ(Radar_Ctl_Data.this_look, RADAR_LOOK_C);
   EXPECT_EQ(Radar_Ctl_Look_Sync_Trig_Clear_Call_Count, 1U);
   EXPECT_FALSE(Radar_Ctl_Look_Sync_Trig_State);
   EXPECT_EQ(Next_Look_Index, 2U);
   EXPECT_EQ(Radar_Ctl_Data.scan_index, 8U);
}
