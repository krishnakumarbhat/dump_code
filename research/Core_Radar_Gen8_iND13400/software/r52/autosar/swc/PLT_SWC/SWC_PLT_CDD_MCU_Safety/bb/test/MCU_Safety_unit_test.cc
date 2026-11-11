/*===========================================================================*/
/**
 * @file MCU_Safety_unit_test.cc
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
 * Unit test suite for the checking the ipc_data.c file
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

#include "MCU_Safety_fake.h"
#include "Mss_Ecc_Parity_fake.h"
#include "static_register_safety_mocks.h"

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <stdint.h>
DEFINE_FFF_GLOBALS;

extern "C"
{
   DEFINE_FAKE_VOID_FUNC(Clear_StickyDiag_MissionFault_registers);
   DEFINE_FAKE_VOID_FUNC(NOC_Run_Bist_Chandra);
   DEFINE_FAKE_VOID_FUNC(NOC_Run_Bist_Small);
   DEFINE_FAKE_VOID_FUNC(NOC_Run_Bist_Artie);
   DEFINE_FAKE_VOID_FUNC(NOC_Verify_Chandra_LatentIsr_Execution);
   DEFINE_FAKE_VOID_FUNC(NOC_Verify_Artie_LatentIsr_Execution);
   DEFINE_FAKE_VOID_FUNC(NOC_Verify_Small_LatentIsr_Execution);
}

/*===========================================================================*
 * Mock Register Variables for PMU BOR Testing
 *===========================================================================*/
volatile uint32_t mock_bor_rst_reason_clr_reg = 0;
volatile uint32_t mock_bor_0p8_trim_register  = 0;
volatile uint32_t mock_bor_1p8_trim_register  = 0;
volatile uint32_t mock_amux_ctrl_register     = 0;
volatile uint32_t mock_bor_trim_otp_register  = 0; /* OTP trim source register */
volatile uint32_t mock_lbist_seq_stat0_reg    = 0;

/*===========================================================================*
 * Mock Register Variables for RMON Testing
 *===========================================================================*/
volatile uint32_t mock_ctl_rmon_register          = 0;
volatile uint32_t mock_irq_rmon_register          = 0;
volatile uint32_t mock_irq_rmon_nomask_register   = 0;
volatile uint32_t mock_rmon_ctrl0_register        = 0;
volatile uint32_t mock_rmon_clkgen_ctrl0_register = 0;
volatile uint32_t mock_misc0_irq_masked_stat      = 0;
volatile uint32_t mock_dcls_ctrl_register         = 0;
#include "SWC_PLT_CDD_MCU_Safety.h"
#undef LBIST_SEQ_STAT0_ADDR
#define LBIST_SEQ_STAT0_ADDR ((uintptr_t)&mock_lbist_seq_stat0_reg)
#undef DCLS_CTRL_ADDR
/* Redefine register macros to use mock variables before including source */
#define BOR_RST_REASON_CLR mock_bor_rst_reason_clr_reg
#define BOR_0P8_TRIM_REG   mock_bor_0p8_trim_register
#define BOR_1P8_TRIM_REG   mock_bor_1p8_trim_register
#define BOR_TRIM_OTP_REG   mock_bor_trim_otp_register
#define AMUX_CTRL_ADDR     mock_amux_ctrl_register

/* Redefine RMON register macros to use mock variables */
#define CTL_RMON                         mock_ctl_rmon_register
#define IRQ_RMON                         mock_irq_rmon_register
#define IRQ_RMON_NOMASK                  mock_irq_rmon_nomask_register
#define RMON_CTRL0                       mock_rmon_ctrl0_register
#define RMON_CLKGEN_CTRL0                mock_rmon_clkgen_ctrl0_register
#define MCU_SAFETY_MISC0_IRQ_MASKED_STAT mock_misc0_irq_masked_stat
#define DCLS_CTRL_ADDR                   mock_dcls_ctrl_register
extern "C"
{
#include "MCU_Safety.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class MCU_Safety_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(Ecc_Fault_Injection_Test);
      RESET_FAKE(Clear_StickyDiag_MissionFault_registers);
      RESET_FAKE(NOC_Run_Bist_Chandra);
      RESET_FAKE(NOC_Run_Bist_Small);
      RESET_FAKE(NOC_Run_Bist_Artie);
      RESET_FAKE(NOC_Verify_Chandra_LatentIsr_Execution);
      RESET_FAKE(NOC_Verify_Artie_LatentIsr_Execution);
      RESET_FAKE(NOC_Verify_Small_LatentIsr_Execution);
      FFF_RESET_HISTORY();

      mock_lbist_seq_stat0_reg                                          = 0U;
      mock_ctl_rmon_register                                            = 0U;
      mock_irq_rmon_register                                            = 0U;
      mock_irq_rmon_nomask_register                                     = 0U;
      mock_rmon_ctrl0_register                                          = 0U;
      mock_rmon_clkgen_ctrl0_register                                   = 0U;
      mock_misc0_irq_masked_stat                                        = 0U;
      TR_InitMCUfail                                                    = CODED_FALSE;
      MCU_InitializationStatus                                          = (MCU_InitializationStatus_T)NOT_COMPLETED;
      Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = CODED_FALSE;
      counter_NOC                                                       = NOC_STATE_RUN_CHANDRA;
      mock_dcls_ctrl_register                                           = 0U;
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

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/*===========================================================================*
 * Test Cases
 *===========================================================================*/
/**
 *  @b MCU_Safety_Init_Test
 *  @n
 *      Executed once after the RTE is started.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Init_Testcase1)
{
   RESET_FAKE(ECC_Irq_Enable);
   RESET_FAKE(ECC_Sec_Threshold_Config);
   FFF_RESET_HISTORY();

   MCU_Safety_Init();
   ASSERT_EQ(TR_InitMCUfail, CODED_FALSE);
   ASSERT_EQ(MCU_InitializationStatus, COMPLETED);
   ASSERT_EQ(ECC_Irq_Enable_fake.call_count, 1u);
   ASSERT_EQ(ECC_Sec_Threshold_Config_fake.call_count, 1u);
}
/**
 *  @b MCU_InitializationStatus
 *  @n
 *      MCU_InitializationStatus update.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Init_Testcase2)
{
   MCU_InitializationStatus = MCUINIT_FAILED;
   MCU_Safety_Init();
   ASSERT_EQ(TR_InitMCUfail, CODED_TRUE);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Init_Testcase3)
{
   MCU_Safety_Init();

   ASSERT_EQ(1u, Clear_StickyDiag_MissionFault_registers_fake.call_count);
   ASSERT_EQ(1u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(1u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(1u, NOC_Run_Bist_Artie_fake.call_count);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Init_LBISTFail_SetsFailed)
{
   /* DONE=1, LOADED=1, GOOD=0 -> test ran and failed */
   mock_lbist_seq_stat0_reg = (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK);

   MCU_Safety_Init();

   ASSERT_EQ(TR_InitMCUfail, CODED_TRUE);
   ASSERT_EQ(MCU_InitializationStatus, MCUINIT_FAILED);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Init_LBISTLoaded0_DefaultPass)
{
   /* LOADED=0: no OTP sequence (pre-A2P4 hw or empty OTP) -> default pass */
   mock_lbist_seq_stat0_reg = 0x0U;

   MCU_Safety_Init();

   ASSERT_EQ(TR_InitMCUfail, CODED_FALSE);
   ASSERT_EQ(MCU_InitializationStatus, COMPLETED);
}

/* --- Table 2.6 test cases --- */
/* DONE=0, LOADED=0: sequencer not finished loading -> default pass */
TEST_F(MCU_Safety_UnitTestSuite, Startup_ValidateLbist_Done0_Loaded0_DefaultPass)
{
   mock_lbist_seq_stat0_reg = 0x0U;

   ASSERT_EQ(Startup_ValidateLbist(), CODED_TRUE);
}

/* DONE=0, LOADED=1: sequencer not finished self-test -> default pass */
TEST_F(MCU_Safety_UnitTestSuite, Startup_ValidateLbist_Done0_Loaded1_DefaultPass)
{
   mock_lbist_seq_stat0_reg = STS_LBSC_LOADED_MASK;

   ASSERT_EQ(Startup_ValidateLbist(), CODED_TRUE);
}

/* DONE=1, LOADED=0: finished without running test (no OTP sequence) -> default pass */
TEST_F(MCU_Safety_UnitTestSuite, Startup_ValidateLbist_Done1_Loaded0_NoTestRan_DefaultPass)
{
   mock_lbist_seq_stat0_reg = STS_LBSC_DONE_MASK;

   ASSERT_EQ(Startup_ValidateLbist(), CODED_TRUE);
}

/* DONE=1, LOADED=1, GOOD=1: test ran and passed -> pass */
TEST_F(MCU_Safety_UnitTestSuite, Startup_ValidateLbist_Done1_Loaded1_Good1_TestPassed)
{
   mock_lbist_seq_stat0_reg = (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK | STS_LBSC_GOOD_MASK);

   ASSERT_EQ(Startup_ValidateLbist(), CODED_TRUE);
}

/* DONE=1, LOADED=1, GOOD=0: test ran and failed -> fail */
TEST_F(MCU_Safety_UnitTestSuite, Startup_ValidateLbist_Done1_Loaded1_Good0_TestFailed)
{
   mock_lbist_seq_stat0_reg = (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK);

   ASSERT_EQ(Startup_ValidateLbist(), CODED_FALSE);
}

/*MCU_InitializationStatus variable test case to be written upon adding new functions*/
/**
 *  @b MCU_Safety_50ms_Test
 *  @n
 *      Executed once after the RTE is started.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase1)
{
   MCU_Safety_50ms();
   /*This Function is only used for XCP Fault Injection*/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   ASSERT_EQ(Ecc_Fault_Injection_Test_fake.call_count, 1u);
#else
   ASSERT_EQ(Ecc_Fault_Injection_Test_fake.call_count, 0u);
#endif

   ASSERT_EQ(1u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(NOC_STATE_RUN_SMALL, counter_NOC);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase2)
{
   counter_NOC = NOC_STATE_RUN_SMALL;

   MCU_Safety_50ms();

   ASSERT_EQ(0u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(1u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(NOC_STATE_RUN_ARTIE, counter_NOC);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase3)
{
   counter_NOC = NOC_STATE_RUN_ARTIE;

   MCU_Safety_50ms();

   ASSERT_EQ(0u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(1u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(NOC_STATE_VERIFY_CHANDRA, counter_NOC);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase4)
{
   counter_NOC = NOC_STATE_VERIFY_ARTIE;

   MCU_Safety_50ms();

   ASSERT_EQ(0u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(1u, NOC_Verify_Artie_LatentIsr_Execution_fake.call_count);
   ASSERT_EQ(NOC_STATE_RUN_CHANDRA, counter_NOC);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase5)
{
   counter_NOC = NOC_STATE_VERIFY_CHANDRA;

   MCU_Safety_50ms();

   ASSERT_EQ(0u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(1u, NOC_Verify_Chandra_LatentIsr_Execution_fake.call_count);
   ASSERT_EQ(NOC_STATE_VERIFY_SMALL, counter_NOC);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_50ms_Testcase6)
{
   counter_NOC = NOC_STATE_VERIFY_SMALL;

   MCU_Safety_50ms();

   ASSERT_EQ(0u, NOC_Run_Bist_Chandra_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Small_fake.call_count);
   ASSERT_EQ(0u, NOC_Run_Bist_Artie_fake.call_count);
   ASSERT_EQ(1u, NOC_Verify_Small_LatentIsr_Execution_fake.call_count);
   ASSERT_EQ(NOC_STATE_VERIFY_ARTIE, counter_NOC);
}
/**
 *  @b HandleDiffResetReason
 *  @n
 *      Executed once after the RTE is started.
 */
#if (TRUE == XCP_FAULT_INJECTION)
TEST_F(MCU_Safety_UnitTestSuite, HandleDiffResetReason)
{
   HandleDiffResetReason();
   ASSERT_EQ(CODED_TRUE, CODED_TRUE);
}
#endif
/*===========================================================================*
 * Enable_PMU_BOR Unit Test Cases
 *===========================================================================*/

/**
 *  @b Enable_PMU_BOR_ResetFlagsCleared_DefaultTrimOTP_Test
 *  @n
 *      Test case to verify BOR reset reason clear register is properly set on every call.
 *      Verifies clearing happens with OTP=0x00000000U and BOR rails are armed.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_Testcase1)
{
   /* Initialize mock register with pre-existing flags and OTP=0x00000000U */
   mock_bor_trim_otp_register  = 0x00000000;
   mock_bor_rst_reason_clr_reg = 0xFFFFFFFF;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify BOR reset reason flags are set to clear mask */
   ASSERT_EQ(mock_bor_rst_reason_clr_reg, BOR_FLAGS_CLR_MSK);
   ASSERT_NE((mock_bor_rst_reason_clr_reg & BOR_0P8_FLAG_CLR_MSK), 0U);
   ASSERT_NE((mock_bor_rst_reason_clr_reg & BOR_1P8_FLAG_CLR_MSK), 0U);

   /* Verify BOR is armed and default trim is applied for invalid OTP=0 */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), BOR_DEFAULT_TRIM_VALUE);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), BOR_DEFAULT_TRIM_VALUE);
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
}

/**
 *  @b Enable_PMU_BOR_BothRailsArmed_ValidOTP_Test
 *  @n
 *      Test case to verify both voltage rails (0P8V and 1P8V) are armed with valid OTP.
 *      Verifies that ARM enable bits are set independently with trim values extracted from OTP.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_Testcase2)
{
   /* Initialize mock registers with valid OTP containing trim values */
   mock_bor_trim_otp_register  = 0x00000249; /* OTP: 0P8=0x09, 1P8=0x09 */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify BOR ARM enable bit is set for 0P8V (bit 8) */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);

   /* Verify BOR ARM enable bit is set for 1P8V (bit 8) */
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);

   /* Verify trim values are extracted from OTP */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), 0x09);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), 0x09);
}

/**
 *  @b Enable_PMU_BOR_Idempotency_ValidOTP_Test
 *  @n
 *      Test case to verify that calling Enable_PMU_BOR multiple times is safe with valid OTP.
 *      Idempotent operations should produce the same result when called multiple times.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_Testcase3)
{
   /* Initialize mock registers to known state with valid OTP */
   mock_bor_trim_otp_register  = 0x00000264; /* Valid OTP: 0P8=0x24, 1P8=0x09 */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* First call */
   Enable_PMU_BOR();
   uint32_t first_0p8    = mock_bor_0p8_trim_register;
   uint32_t first_1p8    = mock_bor_1p8_trim_register;
   uint32_t first_reason = mock_bor_rst_reason_clr_reg;

   /* Verify reset reason and trim values are as expected */
   ASSERT_NE(first_reason, 0U);
   ASSERT_EQ((first_0p8 & BOR_TRIM_FIELD_MSK), 0x24);
   ASSERT_EQ((first_1p8 & BOR_TRIM_FIELD_MSK), 0x09);

   /* Call again with the same initial state */
   mock_bor_trim_otp_register  = 0x00000264; /* Re-initialize OTP */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Second call */
   Enable_PMU_BOR();

   /* Verify results are identical to first call (idempotent) */
   ASSERT_EQ(mock_bor_rst_reason_clr_reg, first_reason);
   ASSERT_EQ(mock_bor_0p8_trim_register, first_0p8);
   ASSERT_EQ(mock_bor_1p8_trim_register, first_1p8);

   /* Verify that trim and ARM bits match both calls */
   ASSERT_EQ((mock_bor_0p8_trim_register & (BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)),
             (first_0p8 & (BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)));
   ASSERT_EQ((mock_bor_1p8_trim_register & (BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)),
             (first_1p8 & (BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)));
}

/*===========================================================================*
 * Enable_PMU_BOR OTP Trim Extraction Tests
 *===========================================================================*/

/**
 *  @b Enable_PMU_BOR_ValidOTP_Max0P8Trim_Test
 *  @n
 *      Test case to verify trim extraction and programming from valid OTP register.
 *      Verifies 0P8 voltage rail receives maximum trim value (0x3F).
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_ValidOTP_Testcase4)
{
   /* Initialize mock OTP with max 0P8 trim value (bits [5:0] = 0x3F, bits [11:6] = 0) */
   mock_bor_trim_otp_register  = 0x0000003F; /* 0P8 = 0x3F, 1P8 = 0x00 */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify 0P8 trim register: should contain ARM bit + 0x3F trim value */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), 0x3F);
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);

   /* Verify 1P8 trim register: should contain only ARM bit (no trim from OTP) */
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), 0x00);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
}

/**
 *  @b Enable_PMU_BOR_ValidOTP_Max1P8Trim_Test
 *  @n
 *      Test case to verify 1P8 voltage rail trim extraction.
 *      Verifies 1P8 receives maximum trim value (0x3F) when OTP bits [11:6] = 0x3F.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_ValidOTP_Testcase5)
{
   /* Initialize mock OTP with max 1P8 trim value (bits [5:0] = 0, bits [11:6] = 0x3F) */
   /* OTP layout: bits [11:6] for 1P8, bits [5:0] for 0P8 */
   /* 0x3F << 6 = 0xFC0 */
   mock_bor_trim_otp_register  = 0x00000FC0; /* 0P8 = 0x00, 1P8 = 0x3F */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify 0P8 trim register: should contain only ARM bit (no trim from OTP) */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), 0x00);
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);

   /* Verify 1P8 trim register: should contain ARM bit + 0x3F trim value */
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), 0x3F);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
}

/**
 *  @b Enable_PMU_BOR_ValidOTP_ClearsPreexistingTrim_Test
 *  @n
 *      Test case to verify valid OTP overwrites pre-existing trim values.
 *      Uses read-modify-write to replace trim field while preserving other bits.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_ValidOTP_Testcase6)
{
   /* Initialize with valid OTP and different pre-existing trim values */
   mock_bor_trim_otp_register  = 0x00000AEC; /* Valid OTP: 0P8=0x2C, 1P8=0x2B */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000015; /* Pre-programmed trim = 0x15 (different from OTP) */
   mock_bor_1p8_trim_register  = 0x00000022; /* Pre-programmed trim = 0x22 (different from OTP) */

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify OTP trim values replace pre-existing values using RMW operation */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), 0x2C);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), 0x2B);

   /* Verify ARM bits are set */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_ARM_EN_BIT), BOR_ARM_EN_BIT);
}

/**
 *  @b Enable_PMU_BOR_TrimExtraction_Masking_Test
 *  @n
 *      Test case to verify 6-bit masking (0x3F) is correctly applied to extracted trim values.
 *      Ensures no bits beyond [5:0] are set in the trim field.
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_PMU_BOR_TrimExtraction_Testcase7)
{
   /* Initialize OTP with pattern that would fail masking if not done correctly */
   mock_bor_trim_otp_register  = 0xFFFFFFFF; /* All bits set */
   mock_bor_rst_reason_clr_reg = 0x00000000;
   mock_bor_0p8_trim_register  = 0x00000000;
   mock_bor_1p8_trim_register  = 0x00000000;

   /* Execute function under test */
   Enable_PMU_BOR();

   /* Verify 6-bit masking is applied (trim field should be 0x3F, not more) */
   ASSERT_EQ((mock_bor_0p8_trim_register & BOR_TRIM_FIELD_MSK), 0x3F);
   ASSERT_EQ((mock_bor_1p8_trim_register & BOR_TRIM_FIELD_MSK), 0x3F);

   /* Verify no bits 6 and above are set in the trim field */
   ASSERT_EQ((mock_bor_0p8_trim_register & ~(BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)), 0x00);
   ASSERT_EQ((mock_bor_1p8_trim_register & ~(BOR_ARM_EN_BIT | BOR_TRIM_FIELD_MSK)), 0x00);
}

/*===========================================================================*
 * Platform_Time_Errorcheck Unit Test Cases
 *===========================================================================*/

/**
 *  @b Platform_Time_Errorcheck_NoFailure_Test
 *  @n
 *      Test case to verify that MCU_InitializationStatus is NOT set to MCUINIT_FAILED
 *      when the platform time value is CODED_FALSE (time check passes).
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Platform_Time_Errorcheck_Testcase1)
{
   /* Set platform time to CODED_FALSE - no time freeze detected */
   Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = CODED_FALSE;

   /* Set MCU_InitializationStatus to a known passing state */
   MCU_InitializationStatus = (MCU_InitializationStatus_T)COMPLETED;

   /* Execute function under test */
   Platform_Time_Errorcheck();

   /* Verify pre_mcu_status was updated from the RTE read */
   ASSERT_EQ(pre_mcu_status, CODED_FALSE);

   /* Verify MCU_InitializationStatus was NOT changed to MCUINIT_FAILED */
   ASSERT_NE(MCU_InitializationStatus, MCUINIT_FAILED);
   ASSERT_EQ(MCU_InitializationStatus, (MCU_InitializationStatus_T)COMPLETED);
}

/**
 *  @b Platform_Time_Errorcheck_Failure_Test
 *  @n
 *      Test case to verify that MCU_InitializationStatus is set to MCUINIT_FAILED
 *      when the platform time value is CODED_TRUE (two identical time instances
 *      detected during platform initialization).
 */
TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Platform_Time_Errorcheck_Testcase2)
{
   /* Set platform time to CODED_TRUE - frozen/duplicate time detected */
   Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = CODED_TRUE;

   /* Set MCU_InitializationStatus to a non-failed state before the call */
   MCU_InitializationStatus = (MCU_InitializationStatus_T)COMPLETED;

   /* Execute function under test */
   Platform_Time_Errorcheck();

   /* Verify pre_mcu_status was updated to CODED_TRUE from the RTE read */
   ASSERT_EQ(pre_mcu_status, CODED_TRUE);

   /* Verify MCU_InitializationStatus was set to MCUINIT_FAILED */
   ASSERT_EQ(MCU_InitializationStatus, MCUINIT_FAILED);
}

/*===========================================================================*
 * Enable_RMON Unit Test Cases
 *===========================================================================*/

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_RMON_Testcase1)
{
   /* Seed with non-zero values to ensure function overwrites/updates correctly. */
   mock_irq_rmon_register          = 0xFFFFFFFFU;
   mock_ctl_rmon_register          = 0x00000000U;
   mock_misc0_irq_masked_stat      = 0x00000000U;
   mock_rmon_clkgen_ctrl0_register = 0x00000000U;

   Enable_RMON();

   ASSERT_EQ(mock_irq_rmon_register, (IRQ_RMON_RA_BIT | IRQ_RMON_MIPI_BIT | IRQ_RMON_DSP_BIT | IRQ_RMON_REF_BIT));
   ASSERT_EQ(mock_ctl_rmon_register, (CTL_RMON_EN_RA | CTL_RMON_EN_MIPI | CTL_RMON_EN_DSP | CTL_RMON_EN_REF));
   ASSERT_EQ((mock_misc0_irq_masked_stat & IRQ_RMON_SER_BIT), IRQ_RMON_SER_BIT);
   ASSERT_EQ((mock_rmon_clkgen_ctrl0_register & CLKGEN_RMON_SER_ENA), CLKGEN_RMON_SER_ENA);
}

TEST_F(MCU_Safety_UnitTestSuite, MCU_Safety_Enable_RMON_Testcase2)
{
   /* Ensure OR operations preserve unrelated bits while setting serial reset monitor bits. */
   const uint32_t misc0_seed       = 0xA5A50001U;
   const uint32_t clkgen_ctrl_seed = 0x00000003U;

   mock_irq_rmon_register          = 0x0U;
   mock_ctl_rmon_register          = 0x0U;
   mock_misc0_irq_masked_stat      = misc0_seed;
   mock_rmon_clkgen_ctrl0_register = clkgen_ctrl_seed;

   Enable_RMON();

   ASSERT_EQ(mock_irq_rmon_register, (IRQ_RMON_RA_BIT | IRQ_RMON_MIPI_BIT | IRQ_RMON_DSP_BIT | IRQ_RMON_REF_BIT));
   ASSERT_EQ(mock_ctl_rmon_register, (CTL_RMON_EN_RA | CTL_RMON_EN_MIPI | CTL_RMON_EN_DSP | CTL_RMON_EN_REF));
   ASSERT_EQ(mock_misc0_irq_masked_stat, (misc0_seed | IRQ_RMON_SER_BIT));
   ASSERT_EQ(mock_rmon_clkgen_ctrl0_register, (clkgen_ctrl_seed | CLKGEN_RMON_SER_ENA));
}
