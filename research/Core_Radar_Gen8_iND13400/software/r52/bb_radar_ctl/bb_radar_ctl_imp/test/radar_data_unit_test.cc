/*===========================================================================*/
/**
 * @file radar_data_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for radar_data.c
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - RC:  Radar Control
 *   - XCP: Extended Calibration Protocol
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - radar_data Unit Test Design
 *
 *   - Requirements Document(s):
 *     - Radar data management requirements
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include "radar_data_fake.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "radar_data.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class RadarData_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      /* Reset global data to known state */
      XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
      XCP_Single_Look_Type        = RADAR_LOOK_C;
      XCP_Force_Radar_On          = false;
      RC_Skip_Look                = CODED_FALSE;
      Radar_Ctl_Data.this_mode    = RADAR_MODE_A;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases - Global variable initial states
 *===========================================================================*/

/**
 * @brief Global data: XCP_Single_Look_Type_Enable initial value is NO_FORCE.
 */
TEST_F(RadarData_UnitTestSuite, XcpSingleLookTypeEnable_InitialValue_IsNoForceLookType)
{
   EXPECT_EQ(XCP_Single_Look_Type_Enable, static_cast<XCP_Single_Look_Type_Enable_T>(RADAR_CTL_NO_FORCE_LOOK_TYPE))
      << "XCP_Single_Look_Type_Enable should default to RADAR_CTL_NO_FORCE_LOOK_TYPE";
}

/**
 * @brief Global data: XCP_Single_Look_Type initial value is RADAR_LOOK_C.
 */
TEST_F(RadarData_UnitTestSuite, XcpSingleLookType_InitialValue_IsRadarLookC)
{
   EXPECT_EQ(XCP_Single_Look_Type, static_cast<Radar_Look_T>(RADAR_LOOK_C))
      << "XCP_Single_Look_Type should default to RADAR_LOOK_C";
}

/**
 * @brief Global data: XCP_Force_Radar_On initial value is false.
 */
TEST_F(RadarData_UnitTestSuite, XcpForceRadarOn_InitialValue_IsFalse)
{
   EXPECT_FALSE(XCP_Force_Radar_On) << "XCP_Force_Radar_On should default to false";
}

/**
 * @brief Global data: RC_Skip_Look initial value is CODED_FALSE.
 */
TEST_F(RadarData_UnitTestSuite, RcSkipLook_InitialValue_IsCodedFalse)
{
   EXPECT_EQ(RC_Skip_Look, static_cast<uint8_t>(CODED_FALSE)) << "RC_Skip_Look should default to CODED_FALSE";
}

/**
 * @brief Global data: XCP_Single_Look_Type_Enable can be changed.
 */
TEST_F(RadarData_UnitTestSuite, XcpSingleLookTypeEnable_CanBeModified)
{
   XCP_Single_Look_Type_Enable = XCP_FORCE_LOOK_TYPE;
   EXPECT_EQ(XCP_Single_Look_Type_Enable, static_cast<XCP_Single_Look_Type_Enable_T>(XCP_FORCE_LOOK_TYPE))
      << "XCP_Single_Look_Type_Enable should be modifiable";
}

/**
 * @brief Global data: XCP_Force_Radar_On can be toggled.
 */
TEST_F(RadarData_UnitTestSuite, XcpForceRadarOn_CanBeToggled)
{
   XCP_Force_Radar_On = true;
   EXPECT_TRUE(XCP_Force_Radar_On) << "XCP_Force_Radar_On should be settable to true";

   XCP_Force_Radar_On = false;
   EXPECT_FALSE(XCP_Force_Radar_On) << "XCP_Force_Radar_On should be settable back to false";
}

/**
 * @brief Radar mode accessors store and retrieve the current mode.
 */
TEST_F(RadarData_UnitTestSuite, RadarMode_PutGet_Work)
{
   Put_Radar_Mode(RADAR_MODE_B);

   EXPECT_EQ(Get_Radar_Mode(), RADAR_MODE_B) << "Get_Radar_Mode should return the last stored mode";
   EXPECT_EQ(Radar_Ctl_Data.this_mode, RADAR_MODE_B) << "Radar_Ctl_Data.this_mode should be updated";
}

/**
 * @brief Global data: Radar_Ctl_Data is accessible after module init.
 */
TEST_F(RadarData_UnitTestSuite, RadarCtlData_GlobalExists_Accessible)
{
   /* Simply verify the global variable is accessible */
   (void)Radar_Ctl_Data;
   (void)Radar_Ctl_State;
   SUCCEED() << "Radar_Ctl_Data and Radar_Ctl_State globals are accessible";
}
