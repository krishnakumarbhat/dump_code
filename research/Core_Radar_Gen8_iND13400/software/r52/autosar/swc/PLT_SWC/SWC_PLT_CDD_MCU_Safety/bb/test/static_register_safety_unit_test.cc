/*===========================================================================*/
/**
 * @file static_register_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the static_register_safety.c file
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
#include "Crc_mocks.h"
#include "board_revision_mocks.h"
#include "fff.h"
#include "radar_ctl.h"

DEFINE_FFF_GLOBALS;

extern "C"
{
#include "static_register_safety.c"
}

Std_ReturnType Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(
   const Rte_DT_Dt_StaticRegCheckFailureInfo_0 *data)
{
   (void)data;
   return E_OK;
}

/*---------------------------------------------------------------------------*
 * Helpers to drive RTE read behavior via FFF custom fakes
 *---------------------------------------------------------------------------*/
extern "C"
{
#include "Std_Types.h" /* for Std_ReturnType, E_OK/E_NOT_OK, TRUE/FALSE */
}

/* Use the exact generated RTE type for the out parameter */
static Std_ReturnType Rte_Read_StaticRegChkFail_SetTrue(Rte_DT_Dt_StaticRegCheckFailureInfo_0 *pVal)
{
   if (pVal != nullptr)
   {
      *pVal = TRUE; /* or 1u if TRUE is unavailable */
   }
   return E_OK;
}

static Std_ReturnType Rte_Read_StaticRegChkFail_SetFalse(Rte_DT_Dt_StaticRegCheckFailureInfo_0 *pVal)
{
   if (pVal != nullptr)
   {
      *pVal = FALSE; /* or 0u */
   }
   return E_OK;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Static_Register_Safety_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_FAKES_CRC_LIST(RESET_FAKE);
      FFF_FAKES_BOARD_REVISION_LIST(RESET_FAKE);
      RESET_FAKE(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo);
      FFF_RESET_HISTORY();
      Get_Board_Revision_fake.return_val = BOARD_REV_EDU;

      // This avoids segfault when source code dereferences Reg_Desc_Ptr
      static uint32 reg_values[MAX_NUM_REGISTER] = {10U, 10U};

      // Override Reg_Desc_Ptr to point to actual valid memory
      for (uint32 i = 0; i < MAX_NUM_REGISTER; i++)
      {
         Reg_Desc_Ptr[i]  = &reg_values[i];
         Reg_Data_Init[i] = 0U; // Reset init data
      }
   }

   void TearDown() override
   {
   }
};

TEST_F(Static_Register_Safety_UnitTestSuite, Eth_Static_Register_Excluded_1)
{
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_B0CVAL, REG_LATENCY_CTRL), CODED_TRUE);
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_B0CVAL, REG_SERDES_MISC_CTRL), CODED_TRUE);
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_B0CVAL, REG_ETHERNET_MCGR_CTRL), CODED_TRUE);
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_B0CVAL, REG_PWM_CFG), CODED_FALSE);
}

TEST_F(Static_Register_Safety_UnitTestSuite, Eth_Static_Register_Excluded_2)
{
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_EDU, REG_LATENCY_CTRL), CODED_FALSE);
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_EDU, REG_SERDES_MISC_CTRL), CODED_FALSE);
   ASSERT_EQ(Eth_Static_Register_Excluded(BOARD_REV_EDU, REG_ETHERNET_MCGR_CTRL), CODED_FALSE);
}

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
TEST_F(Static_Register_Safety_UnitTestSuite, Static_Register_Safety_Check_RADAR_FAIL_1)
{
   Crc_CalculateCRC32_fake.return_val = 0xAD49DB7A;

   Radar_Core_Status.RadarInitializatonStatus = 1U;

   for (uint32 i = 0; i < 20; i++)
   {
      Static_Register_Safety_Check();
   }

   ASSERT_EQ(Crc_CalculateCRC32_fake.call_count, 0U);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 0U);
   ASSERT_EQ(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7A);
}

TEST_F(Static_Register_Safety_UnitTestSuite, Static_Register_Safety_Check_1)
{
   Crc_CalculateCRC32_fake.return_val         = 0xAD49DB7A;
   Crc_CalculateCRC32_fake.call_count         = 0U;
   Radar_Core_Status.RadarInitializatonStatus = RADAR_SUCCESS;

   Static_Register_Safety_Check();

   ASSERT_EQ(Crc_CalculateCRC32_fake.call_count, MAX_NUM_REGISTER);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 0U);
   ASSERT_EQ(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7A);
   for (uint32 i = 0; i < MAX_NUM_REGISTER; i++)
   {
      ASSERT_EQ(Reg_Data_Init[i], *Reg_Desc_Ptr[i]);
   }
}

TEST_F(Static_Register_Safety_UnitTestSuite, Static_Register_Safety_Check_2)
{
   Crc_CalculateCRC32_fake.return_val = 0xAD49DB7A;
   Get_Board_Revision_fake.return_val = BOARD_REV_B0CVAL;
   Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.custom_fake =
      Rte_Read_StaticRegChkFail_SetFalse;

   for (uint32 i = 0; i < 3; i++)
   {
      Static_Register_Safety_Check();
   }

   ASSERT_EQ(Crc_CalculateCRC32_fake.call_count, 245U);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 1U);
   ASSERT_EQ(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7A);
   ASSERT_TRUE(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.custom_fake !=
               nullptr);
}

TEST_F(Static_Register_Safety_UnitTestSuite, Static_Register_Safety_Check_3)
{
   Crc_CalculateCRC32_fake.return_val = 0xAD49DB7A;
   Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.custom_fake =
      Rte_Read_StaticRegChkFail_SetTrue;

   for (uint32 i = 0; i < 3; i++)
   {
      Static_Register_Safety_Check();
   }

   ASSERT_EQ(Crc_CalculateCRC32_fake.call_count, MAX_NUM_REGISTER);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 1U);
   ASSERT_EQ(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7A);
   ASSERT_TRUE(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.custom_fake !=
               nullptr);
}

TEST_F(Static_Register_Safety_UnitTestSuite, Static_Register_Safety_Check_4)
{
   Crc_CalculateCRC32_fake.return_val = 0xAD49DB7B;
   Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.custom_fake =
      Rte_Read_StaticRegChkFail_SetFalse;

   for (uint32 i = 0; i < 3; i++)
   {
      Static_Register_Safety_Check();
   }

   ASSERT_EQ(Crc_CalculateCRC32_fake.call_count, MAX_NUM_REGISTER);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 1U);
   ASSERT_NE(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7A);
   ASSERT_EQ(Crc_CalculateCRC32_fake.return_val, 0xAD49DB7B);
}
