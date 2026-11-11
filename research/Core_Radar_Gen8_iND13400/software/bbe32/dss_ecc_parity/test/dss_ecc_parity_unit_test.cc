/*===========================================================================*/
/**
 * @file dss_ecc_parity_unit_test.cc
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 * @section DESC DESCRIPTION:
 * Unit test suite for dss_ecc_parity.c module
 *
 * @section ABBR ABBREVIATIONS:
 *   - ECC: Error Correction Code
 *   - AXI: Advanced eXtensible Interface
 *   - DSP: Digital Signal Processor
 *
 */
/*===========================================================================*/

#include "fff.h"
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Setup
 *===========================================================================*/
#define UNIT_TEST
#include "dss_ecc_parity_mock.h"

extern "C"
{
#include "dss_ecc_parity.c"
}

/*===========================================================================*
 * Test Fixture
 *===========================================================================*/
class DssEccParityTestSuite : public testing::Test
{
 protected:
   void SetUp() override
   {
      mock_dss_ecc_reset();
      Axi_Ecc_Mon_Flag    = 0x55U;
      Csr_Parity_Mon_Flag = 0x55U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief Test Enable_Axi_Ecc successfully enables ECC
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc1)
{
   mock_axi_ecc_register = 1U;
   bool result           = Enable_Axi_Ecc();

   EXPECT_TRUE(result);
   EXPECT_EQ(mock_write_count, 1U);
   EXPECT_EQ(mock_read_count, 1U);
   EXPECT_EQ(mock_axi_ecc_register, 1U);
}

/**
 * @brief Test Enable_Axi_Ecc fails when register write is unsuccessful
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc2)
{
   mock_axi_ecc_register = 0U;
   mock_write_fails      = true;
   bool result           = Enable_Axi_Ecc();

   EXPECT_FALSE(result);
   EXPECT_EQ(mock_write_count, 1U);
   EXPECT_EQ(mock_read_count, 1U);
}

/**
 * @brief Test Enable_Axi_Ecc with multiple calls
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc3)
{
   mock_axi_ecc_register = 1U;
   bool result1          = Enable_Axi_Ecc();
   EXPECT_TRUE(result1);

   mock_dss_ecc_reset();
   mock_axi_ecc_register = 1U;
   bool result2          = Enable_Axi_Ecc();
   EXPECT_TRUE(result2);
}

/**
 * @brief Test Enable_Axi_Ecc with register value mismatch
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc4)
{
   mock_axi_ecc_register = 2U;
   mock_write_fails      = true;
   bool result           = Enable_Axi_Ecc();

   EXPECT_FALSE(result);
   EXPECT_EQ(mock_axi_ecc_register, 2U);
}

/**
 * @brief Test Enable_Axi_Ecc register write operation
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc5)
{
   mock_axi_ecc_register = 1U;
   bool result           = Enable_Axi_Ecc();

   EXPECT_TRUE(result);
   EXPECT_EQ(mock_write_count, 1U);
   EXPECT_EQ(mock_axi_ecc_register, 1U);
}

/**
 * @brief Test Enable_Axi_Ecc register read operation
 */
TEST_F(DssEccParityTestSuite, Enable_Axi_Ecc6)
{
   mock_axi_ecc_register = 1U;
   bool result           = Enable_Axi_Ecc();

   EXPECT_TRUE(result);
   EXPECT_EQ(mock_read_count, 1U);
}

/**
 * @brief Test Enable_Dsp_Ecc with successful ECC initialization
 */
TEST_F(DssEccParityTestSuite, Enable_Dsp_Ecc1)
{
   mock_axi_ecc_register = 1U;
   Enable_Dsp_Ecc();

   EXPECT_EQ(mock_write_count, 1U);
   EXPECT_EQ(mock_read_count, 1U);
   EXPECT_EQ(Axi_Ecc_Mon_Flag, 0x55U);
}

/**
 * @brief Test Enable_Dsp_Ecc detects failure condition
 */
TEST_F(DssEccParityTestSuite, Enable_Dsp_Ecc2)
{
   mock_axi_ecc_register = 0U;
   mock_write_fails      = true;
   Enable_Dsp_Ecc();

   EXPECT_EQ(mock_write_count, 3U);
   EXPECT_EQ(mock_read_count, 3U);
   EXPECT_EQ(Axi_Ecc_Mon_Flag, 0xAAU);
}

/**
 * @brief Test Get_Axi_Ecc_Enable_Err_state returns initial state (no error)
 */

TEST_F(DssEccParityTestSuite, Get_Axi_Ecc_Enable_Err_state1)
{
   uint8_t result = Get_Axi_Ecc_Enable_Err_state();
   EXPECT_EQ(result, 0x55U);
}

TEST_F(DssEccParityTestSuite, Get_Axi_Ecc_Enable_Err_state2)
{
   mock_axi_ecc_register = 0U;
   mock_write_fails      = true;
   Enable_Dsp_Ecc();

   uint8_t result = Get_Axi_Ecc_Enable_Err_state();
   EXPECT_EQ(result, 0xAAU);
}

TEST_F(DssEccParityTestSuite, Get_Axi_Ecc_Enable_Err_state3)
{
   mock_axi_ecc_register = 1U;
   Enable_Dsp_Ecc();

   uint8_t result = Get_Axi_Ecc_Enable_Err_state();
   EXPECT_EQ(result, 0x55U);
}

TEST_F(DssEccParityTestSuite, VerifyAxiEccAddress)
{
   EXPECT_EQ(AXI_ECC_ADDRESS, 0x00103034);
}
TEST_F(DssEccParityTestSuite, EnableCsrpctlParitySetsEnableBit)
{
   EXPECT_TRUE(Enable_Csrpctl_Parity());
   EXPECT_EQ(mock_csrpctl_register, 1U);
   EXPECT_EQ(mock_csrpctl_write_count, 1U);
   EXPECT_EQ(mock_csrpctl_read_count, 2U);
}

TEST_F(DssEccParityTestSuite, EnableCsrpctlParityPreservesOtherBits)
{
   mock_csrpctl_register = 0xA4U;

   EXPECT_TRUE(Enable_Csrpctl_Parity());
   EXPECT_EQ(mock_csrpctl_register, 0xA5U);
}

TEST_F(DssEccParityTestSuite, EnableCsrpctlParityReportsWriteFailure)
{
   mock_csrpctl_write_fails = true;

   EXPECT_FALSE(Enable_Csrpctl_Parity());
   EXPECT_EQ(mock_csrpctl_register, 0U);
}

TEST_F(DssEccParityTestSuite, EnableDspParityKeepsMonitorFlagOnSuccess)
{
   Enable_Dsp_Parity();

   EXPECT_EQ(Csr_Parity_Mon_Flag, 0x55U);
}

TEST_F(DssEccParityTestSuite, EnableDspParitySetsMonitorFlagOnFailure)
{
   mock_csrpctl_write_fails = true;

   Enable_Dsp_Parity();

   EXPECT_EQ(Csr_Parity_Mon_Flag, 0xAAU);
}

TEST_F(DssEccParityTestSuite, GetCsrParityEnableErrStateReturnsMonitorFlag)
{
   EXPECT_EQ(Get_Csr_Parity_Enable_Err_state(), 0x55U);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorDoesNothingWhenDisabled)
{
   dsp_ecc_parity_test_flag = 0U;
   test_dsp                 = ECC_TEST_DRAM_SEC;

   Test_Dsp_Ecc_Parity_Error();

   EXPECT_EQ(mock_dss_ecc_irq_enabled, 0U);
   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, ECC_TEST_DRAM_SEC);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorInjectsDramSingleError)
{
   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = ECC_TEST_DRAM_SEC;

   Test_Dsp_Ecc_Parity_Error();

   EXPECT_EQ(mock_dss_ecc_irq_enabled, 1U);
   EXPECT_EQ(mock_dss_ecc_dram_memory, 0xCAFEBEEFU ^ 0x00000001U);
   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, ECC_TEST_NONE);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorInjectsDramDoubleError)
{
   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = ECC_TEST_DRAM_DED;

   Test_Dsp_Ecc_Parity_Error();

   EXPECT_EQ(mock_dss_ecc_irq_enabled, 1U);
   EXPECT_EQ(mock_dss_ecc_dram_memory, 0xCAFEBEEFU ^ 0x00000081U);
   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, ECC_TEST_NONE);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorInjectsIramErrors)
{
   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = ECC_TEST_IRAM_SEC;
   Test_Dsp_Ecc_Parity_Error();
   EXPECT_EQ(mock_dss_ecc_irq_enabled, 1U);
   EXPECT_EQ(mock_dss_ecc_iram_memory, 0xCAFEBEEFU ^ 0x00000001U);

   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = ECC_TEST_IRAM_DED;
   Test_Dsp_Ecc_Parity_Error();
   EXPECT_EQ(mock_dss_ecc_irq_enabled, 1U);
   EXPECT_EQ(mock_dss_ecc_iram_memory, 0xCAFEBEEFU ^ 0x00000081U);
   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, ECC_TEST_NONE);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorInjectsCsrParityError)
{
   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = ECC_TEST_CSR_PARITY;

   Test_Dsp_Ecc_Parity_Error();

   EXPECT_EQ(mock_dss_ecc_irq_enabled, 1U);
   EXPECT_EQ(mock_csrpctl_register, CSRPCTL_ENABLE);
   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, ECC_TEST_NONE);
}

TEST_F(DssEccParityTestSuite, TestDspEccParityErrorClearsFlagForUnknownTest)
{
   dsp_ecc_parity_test_flag = 1U;
   test_dsp                 = static_cast<EccTest_t>(99);

   Test_Dsp_Ecc_Parity_Error();

   EXPECT_EQ(dsp_ecc_parity_test_flag, 0U);
   EXPECT_EQ(test_dsp, static_cast<EccTest_t>(99));
}
/*===========================================================================*/
