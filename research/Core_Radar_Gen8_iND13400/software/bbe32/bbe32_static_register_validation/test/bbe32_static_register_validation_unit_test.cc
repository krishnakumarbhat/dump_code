/*===========================================================================*/
/**
 * @file bbe32_static_register_validation_unit_test.cc
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
 * Unit test suite for bbe32_static_register_validation.c
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - FuSa: Functional Safety
 *   - CRC:  Cyclic Redundancy Check
 *   - BBE32: Baseband Engine 32
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - bbe32_static_register_validation Unit Test Design
 *
 *   - Requirements Document(s):
 *     - Static register safety requirements
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
#include "bbe32_static_register_validation_fake.h"
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/* Define FFF fakes for all faked functions */
DEFINE_FAKE_VALUE_FUNC(uint32_t, Compute_CRC32_SW, uint8_t *, uint32_t, uint32_t, bool);
DEFINE_FAKE_VOID_FUNC(Ipc_Functional_Reset);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_One_50ms_DSP_Delay);
DEFINE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);

/* Static D2M buffer for Get_SP_Post_Proc_IPC_D2M_Msg_Buffer fake */
static D2M_Msg_T g_d2m_msg_stub = {};

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "bbe32_static_register_validation.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Bbe32StaticRegValidation_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Compute_CRC32_SW);
      RESET_FAKE(Ipc_Functional_Reset);
      RESET_FAKE(Get_One_50ms_DSP_Delay);
      RESET_FAKE(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);

      /* Set up D2M buffer fake return */
      memset(&g_d2m_msg_stub, 0, sizeof(g_d2m_msg_stub));
      Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.return_val = reinterpret_cast<volatile D2M_Msg_T *>(&g_d2m_msg_stub);

      /* Reset internal state */
      FS_CRC                 = 0xFFFFFFFFu;
      Runtime_CRC            = 0xFFFFFFFFu;
      One_Sec_Delay          = 0u;
      One_Time_Intialization = CODED_TRUE;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief bbe32_static_register_validation_Init: On first call, sets One_Time_Intialization
 *        to CODED_FALSE after computing initial CRC.
 */
TEST_F(Bbe32StaticRegValidation_UnitTestSuite, Init_FirstCall_SetsOneTimeInitFalse)
{
   Compute_CRC32_SW_fake.return_val = 0xABCDABCDU;
   One_Time_Intialization           = CODED_TRUE;
   One_Sec_Delay                    = FS_STARTUP_DELAY - 1U; /* One increment will hit the modulo check */

   Bbe32_Static_Register_Safety_Check();

   EXPECT_EQ(One_Time_Intialization, static_cast<uint8_t>(CODED_FALSE))
      << "One_Time_Intialization should be CODED_FALSE after init";
}

/**
 * @brief bbe32_static_register_validation_Init: Stores computed CRC to FS_CRC.
 */
TEST_F(Bbe32StaticRegValidation_UnitTestSuite, Init_StoresComputedCrcToFsCrc)
{
   Compute_CRC32_SW_fake.return_val = 0x12345678U;
   One_Time_Intialization           = CODED_TRUE;
   One_Sec_Delay                    = FS_STARTUP_DELAY - 1U;

   Bbe32_Static_Register_Safety_Check();

   EXPECT_EQ(FS_CRC, 0x12345678U) << "FS_CRC should hold the computed baseline CRC value";
}

/**
 * @brief bbe32_static_register_validation_Check: When CRCs match and no functional reset expected.
 */
TEST_F(Bbe32StaticRegValidation_UnitTestSuite, Check_CrcsMatch_NoFunctionalReset)
{
   /* Set up matching CRCs */
   FS_CRC                                 = 0xDEADBEEFU;
   Runtime_CRC                            = 0xDEADBEEFU;
   One_Sec_Delay                          = FS_WAIT_150MS - 1U; /* One increment will hit the modulo check */
   One_Time_Intialization                 = CODED_FALSE;
   Compute_CRC32_SW_fake.return_val       = 0xDEADBEEFU;
   Get_One_50ms_DSP_Delay_fake.return_val = 1U;

   Bbe32_Static_Register_Safety_Check();

   EXPECT_EQ(g_d2m_msg_stub.payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag, static_cast<uint8_t>(CODED_FALSE))
      << "Fault flag should be CODED_FALSE when CRCs match";
}

/**
 * @brief bbe32_static_register_validation_Check: When CRCs mismatch, functional reset triggered.
 */
TEST_F(Bbe32StaticRegValidation_UnitTestSuite, Check_CrcsMismatch_SetsFaultFlag)
{
   /* Baseline CRC differs from runtime */
   FS_CRC                                 = 0xAAAAAAAAU;
   Runtime_CRC                            = 0xBBBBBBBBU;
   One_Sec_Delay                          = FS_WAIT_150MS - 1U;
   One_Time_Intialization                 = CODED_FALSE;
   Compute_CRC32_SW_fake.return_val       = 0xBBBBBBBBU;
   Get_One_50ms_DSP_Delay_fake.return_val = 1U;

   Bbe32_Static_Register_Safety_Check();

   EXPECT_EQ(g_d2m_msg_stub.payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag, static_cast<uint8_t>(CODED_TRUE))
      << "Fault flag should be CODED_TRUE when CRCs mismatch";
}

/**
 * @brief bbe32_static_register_validation_Check: Counter not expired, no check is done yet.
 */
TEST_F(Bbe32StaticRegValidation_UnitTestSuite, Check_DelayNotExpired_NoAction)
{
   One_Sec_Delay                          = 0U; /* Counter not expired */
   One_Time_Intialization                 = CODED_FALSE;
   Get_One_50ms_DSP_Delay_fake.return_val = 1U;

   Bbe32_Static_Register_Safety_Check();

   EXPECT_EQ(g_d2m_msg_stub.payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag, static_cast<uint8_t>(CODED_FALSE))
      << "Fault flag should remain CODED_FALSE when delay counter has not expired";
}
