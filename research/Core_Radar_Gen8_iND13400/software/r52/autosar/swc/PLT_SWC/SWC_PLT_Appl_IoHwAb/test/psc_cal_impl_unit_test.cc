/****************************************************************************
 * Copyright 2022 APTIV, All Rights Reserved
 * Unit Test for Get_Volt_Monitor_Cal_Impl
 * File Name: psc_cal_impl_unit_test.cc
 *****************************************************************************/
#include "board_revision_mocks.h"
#include "fff.h"
#include "gtest/gtest.h"

extern "C"
{
#include "psc_cal.h"
}

DEFINE_FFF_GLOBALS;

class PscCalImplUnitTestSuite : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;
      Proj_Electrical_System             = (u8p0_T)PROJ_ELECTRICAL_SYSTEM_24V;
   }
};

TEST_F(PscCalImplUnitTestSuite, Get_Volt_Monitor_Cal_Impl_NonA3P0_Returns12V)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   Volt_Monitor_Cal_T *result = Get_Volt_Monitor_Cal_Impl();

   ASSERT_NE(result, nullptr);
   /* 12V variant has k_norm_vmax = 16384 */
   EXPECT_EQ(result->k_norm_vmax, (u6p10_T)16384);
}

TEST_F(PscCalImplUnitTestSuite, Get_Volt_Monitor_Cal_Impl_A3P0_8_32V)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Proj_Electrical_System             = (u8p0_T)PROJ_ELECTRICAL_SYSTEM_8_32V;

   Volt_Monitor_Cal_T *result = Get_Volt_Monitor_Cal_Impl();

   ASSERT_NE(result, nullptr);
   /* 8-32V variant has k_norm_vmax = 34284 */
   EXPECT_EQ(result->k_norm_vmax, (u6p10_T)34284);
}

TEST_F(PscCalImplUnitTestSuite, Get_Volt_Monitor_Cal_Impl_A3P0_12V)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Proj_Electrical_System             = (u8p0_T)PROJ_ELECTRICAL_SYSTEM_12V;

   Volt_Monitor_Cal_T *result = Get_Volt_Monitor_Cal_Impl();

   ASSERT_NE(result, nullptr);
   /* 12V variant has k_norm_vmax = 16384 */
   EXPECT_EQ(result->k_norm_vmax, (u6p10_T)16384);
}

TEST_F(PscCalImplUnitTestSuite, Get_Volt_Monitor_Cal_Impl_A3P0_24V)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Proj_Electrical_System             = (u8p0_T)PROJ_ELECTRICAL_SYSTEM_24V;

   Volt_Monitor_Cal_T *result = Get_Volt_Monitor_Cal_Impl();

   ASSERT_NE(result, nullptr);
   /* 24V variant has k_norm_vmax = 32768 */
   EXPECT_EQ(result->k_norm_vmax, (u6p10_T)32768);
}

TEST_F(PscCalImplUnitTestSuite, Get_Volt_Monitor_Cal_Impl_A3P0_Default)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Proj_Electrical_System             = (u8p0_T)255U; /* Invalid value triggers default */

   Volt_Monitor_Cal_T *result = Get_Volt_Monitor_Cal_Impl();

   ASSERT_NE(result, nullptr);
   /* Default is 8-32V variant with k_norm_vmax = 34284 */
   EXPECT_EQ(result->k_norm_vmax, (u6p10_T)34284);
}
