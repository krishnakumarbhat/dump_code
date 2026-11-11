/*===========================================================================*/
/**
 * @file Mipi_wrapper_unit_test.cc
 *
 * Unit test suite for Mipi_wrapper.c
 */
/*==========================================================================*/

#include <gtest/gtest.h>

#include "Mipi_wrapper_fake.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

extern "C"
{
#include "mipi_wrapper.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class mipi_wrapper_UnitTestSuite : public ::testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Get_Board_Revision);
      RESET_FAKE(Get_RDI_Log_Board_Connected);
      RESET_FAKE(I2c_Write_Data);
      RESET_FAKE(I2c_Receive_Data);
      RESET_FAKE(Stub_SetMode);
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

TEST_F(mipi_wrapper_UnitTestSuite, mipi_wrapper__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

TEST_F(mipi_wrapper_UnitTestSuite, Mipi_Debug_Counters_InitializedToZero)
{
   /* Verify the debug counters are initialized to zero */
   extern Mipi_I2c_Debug_Counters_T Mipi_Debug_Counters;
   EXPECT_EQ(Mipi_Debug_Counters.write_attempts, 0U);
   EXPECT_EQ(Mipi_Debug_Counters.write_success, 0U);
   EXPECT_EQ(Mipi_Debug_Counters.read_attempts, 0U);
   EXPECT_EQ(Mipi_Debug_Counters.read_success, 0U);
   EXPECT_EQ(Mipi_Debug_Counters.reset_verified, 0U);
   EXPECT_EQ(Mipi_Debug_Counters.reset_failed, 0U);
}

TEST_F(mipi_wrapper_UnitTestSuite, Assert_Reset_Mipi_NoRdiConnection_ReturnsFail)
{
   /* When RDI is not connected and board is not A0, function returns false */
   Get_RDI_Log_Board_Connected_fake.return_val = false;
   Get_Board_Revision_fake.return_val          = BOARD_REV_EDU;

   bool result = Assert_Reset_Mipi();
   EXPECT_FALSE(result);
}

TEST_F(mipi_wrapper_UnitTestSuite, Deassert_Reset_Mipi_NoRdiConnection_ReturnsFail)
{
   /* When RDI is not connected, function sets port mode and returns false */
   Get_RDI_Log_Board_Connected_fake.return_val = false;
   Get_Board_Revision_fake.return_val          = BOARD_REV_EDU;

   bool result = Deassert_Reset_Mipi();
   EXPECT_FALSE(result);
}
