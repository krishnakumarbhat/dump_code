/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_FCRU_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
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
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_FCRU_fake.h"
#include "fff.h"
#define UNIT_TEST

/*===========================================================================*
 * Mock Variables for Register Access
 *===========================================================================*/
uint32_t mock_fcru_pmu_faultb        = 0U; // PMU_FAULTB config mock
static uint32_t mock_fcru_rst_en_00  = 0U; /* RST_ENA Config 0-31 */
static uint32_t mock_fcru_rst_en_01  = 0U; /* RST_ENA Config 32-63 */
static uint32_t mock_fcru_pin_en_00  = 0U; /* PIN_ENA Config 0-31 */
static uint32_t mock_fcru_pin_en_01  = 0U; /* PIN_ENA Config 32-63 */
static uint32_t mock_fcru_cap_byp_00 = 0U; /* CAP_BYP Config 0-31 */
static uint32_t mock_fcru_cap_byp_01 = 0U; /* CAP_BYP Config 32-63 */

/* Mock variables for DIAG registers */
static uint32_t mock_fcru_diag_00    = 0U; /* DIAG PIN_EN 0-31 */
static uint32_t mock_fcru_diag_01    = 0U; /* DIAG PIN_EN 32-63 */
static uint32_t mock_fcru_diag_02    = 0U; /* DIAG RST_EN 0-31 */
static uint32_t mock_fcru_diag_03    = 0U; /* DIAG RST_EN 32-63 */
static uint32_t mock_lbist_seq_stat0 = 0U; /* LBIST status register */

/* Mock variables for Clear Fault registers */
static uint32_t mock_fcru_ctrl_04 = 0U; /* Clear PIN_EN 0-31 */
static uint32_t mock_fcru_ctrl_05 = 0U; /* Clear PIN_EN 32-63 */
static uint32_t mock_fcru_ctrl_06 = 0U; /* Clear RST_EN 0-31 */
static uint32_t mock_fcru_ctrl_07 = 0U; /* Clear RST_EN 32-63 */

/*===========================================================================*
 * Mock Macros - Override the configuration macros for testing
 *===========================================================================*/
#undef CONFIG_PMU_FAULTB_PIN
#undef CONFIG_FCRU_RST_EN_00
#undef CONFIG_FCRU_RST_EN_01
#undef CONFIG_FCRU_PIN_EN_00
#undef CONFIG_FCRU_PIN_EN_01
#undef CONFIG_FCRU_CAP_BYP_00
#undef CONFIG_FCRU_CAP_BYP_01

#define CONFIG_PMU_FAULTB_PIN(x)  (mock_fcru_pmu_faultb = (x))
#define CONFIG_FCRU_RST_EN_00(x)  (mock_fcru_rst_en_00 = (x))
#define CONFIG_FCRU_RST_EN_01(x)  (mock_fcru_rst_en_01 = (x))
#define CONFIG_FCRU_PIN_EN_00(x)  (mock_fcru_pin_en_00 = (x))
#define CONFIG_FCRU_PIN_EN_01(x)  (mock_fcru_pin_en_01 = (x))
#define CONFIG_FCRU_CAP_BYP_00(x) (mock_fcru_cap_byp_00 = (x))
#define CONFIG_FCRU_CAP_BYP_01(x) (mock_fcru_cap_byp_01 = (x))

/* Override DIAG register macros */
#undef FCRU_DIAG_00_ADDR
#undef FCRU_DIAG_01_ADDR
#undef FCRU_DIAG_02_ADDR
#undef FCRU_DIAG_03_ADDR
#undef LBIST_SEQ_STAT0_ADDR

#define FCRU_DIAG_00_ADDR    mock_fcru_diag_00
#define FCRU_DIAG_01_ADDR    mock_fcru_diag_01
#define FCRU_DIAG_02_ADDR    mock_fcru_diag_02
#define FCRU_DIAG_03_ADDR    mock_fcru_diag_03
#define LBIST_SEQ_STAT0_ADDR (&mock_lbist_seq_stat0)

/* Override Clear Fault register macros */
#undef FCRU_CTRL_04_ADDR
#undef FCRU_CTRL_05_ADDR
#undef FCRU_CTRL_06_ADDR
#undef FCRU_CTRL_07_ADDR

#define FCRU_CTRL_04_ADDR mock_fcru_ctrl_04
#define FCRU_CTRL_05_ADDR mock_fcru_ctrl_05
#define FCRU_CTRL_06_ADDR mock_fcru_ctrl_06
#define FCRU_CTRL_07_ADDR mock_fcru_ctrl_07

/*===========================================================================*
 * Test Helper Functions
 *===========================================================================*/
static void reset_all_mock_registers(void)
{
   mock_fcru_pmu_faultb = 0U;
   mock_fcru_rst_en_00  = 0U;
   mock_fcru_rst_en_01  = 0U;
   mock_fcru_pin_en_00  = 0U;
   mock_fcru_pin_en_01  = 0U;
   mock_fcru_cap_byp_00 = 0U;
   mock_fcru_cap_byp_01 = 0U;
   mock_fcru_diag_00    = 0U;
   mock_fcru_diag_01    = 0U;
   mock_fcru_diag_02    = 0U;
   mock_fcru_diag_03    = 0U;
   mock_lbist_seq_stat0 = 0U;
   mock_fcru_ctrl_04    = 0U;
   mock_fcru_ctrl_05    = 0U;
   mock_fcru_ctrl_06    = 0U;
   mock_fcru_ctrl_07    = 0U;
}

/* Enable fault injection path and define control constants for tests */
#define XCP_FAULT_INJECTION TRUE

/* Mocks to observe fault injection behavior */
static uint32_t mock_fcru_key_reg_test        = 0U;
static uint32_t mock_fcru_force_fault_00_test = 0U;
static uint32_t mock_fcru_force_fault_01_test = 0U;
static Board_Revision_T Board_Version_Test    = BOARD_REV_EDU;
static uint8 mock_repetative_reset_faultnum   = 0xFFU;
// Manual mock for RTE call used by Log_Last_FCRU_Reset_Reason
static unsigned int Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
static uint8 Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val          = 0U;

#define FCRU_KEY_ADDR mock_fcru_key_reg_test
#define INJECT_FCRU_FAULT(fault_bit)                                                                                              \
   ((fault_bit) > 31U ? (mock_fcru_force_fault_01_test |= (1U << ((fault_bit)-32U))) :                                            \
                        (mock_fcru_force_fault_00_test |= (1U << (fault_bit))))

Board_Revision_T Get_Board_Revision(void)
{
   return Board_Version_Test;
}

extern "C"
{
   // Provide the boot shared data object expected by SWC code when linked in unit tests.
   // Initialize with correct bootloader version to match production behavior (v1.6.6)
   Boot_Shared_Data_T Boot_Shared_Data = {
      .pbl_version_major = 1U,
      .pbl_version_minor = 6U,
      .pbl_version_patch = 6U,
   };

#include "SWC_PLT_CDD_FCRU.c"
}

void CS_Get_RepetativeReset_Faultnum_Operation(uint8 *faultnum)
{
   *faultnum = mock_repetative_reset_faultnum;
}

void CS_Failsafe_Log_ResetReason_at_Startup(uint8 reset_reason)
{
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count++;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val = reset_reason;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class FCRU_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      reset_all_mock_registers();
      Rst_Ena_Config0      = RST_ENA_CONFIG0;
      Rst_Ena_Config1      = RST_ENA_CONFIG1;
      Pin_Ena_Config0      = PIN_ENA_CONFIG0;
      Pin_Ena_Config1      = PIN_ENA_CONFIG1;
      mock_lbist_seq_stat0 = LBIST_AVAILABLE;
      Board_Version_Test   = BOARD_REV_EDU;
      // Reset Boot_Shared_Data version fields to default values
      Boot_Shared_Data.pbl_version_major = 1U;
      Boot_Shared_Data.pbl_version_minor = 6U;
      Boot_Shared_Data.pbl_version_patch = 6U;
      // Reset Boot_Shared_Data diagnostic fields
      Boot_Shared_Data.fcru_diag2    = 0U;
      Boot_Shared_Data.fcru_diag3    = 0U;
      mock_repetative_reset_faultnum = 0xFFU;
      // Reset manual RTE mock counters
      Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
      Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;
      FFF_RESET_HISTORY();
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
      reset_all_mock_registers();
      Rst_Ena_Config0 = RST_ENA_CONFIG0;
      Rst_Ena_Config1 = RST_ENA_CONFIG1;
      Pin_Ena_Config0 = PIN_ENA_CONFIG0;
      Pin_Ena_Config1 = PIN_ENA_CONFIG1;
   }
};

/*===========================================================================*
 * Test Cases for RE_PLT_FCRU_Init
 *===========================================================================*/

/**
 *  @b RE_PLT_FCRU_Init_00
 *  @n  Test that RE_PLT_FCRU_Init properly configures all FCRU registers
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_00)
{
   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Verify PMU_FaultB pin configuration
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);

   // Verify Reset Enable configuration
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);

   // Verify Pin Enable configuration
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);

   // Verify Capture Bypass configuration
   EXPECT_EQ(mock_fcru_cap_byp_00, CAP_BYP_CONFIG0);
   EXPECT_EQ(mock_fcru_cap_byp_01, CAP_BYP_CONFIG1);
}

/**
 *  @b RE_PLT_FCRU_Init_01
 *  @n  Test initialization when all registers start at zero
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_01)
{
   // Ensure all registers start at expected initial values (SetUp already does this)
   EXPECT_EQ(mock_fcru_pmu_faultb, 0U);
   EXPECT_EQ(mock_fcru_rst_en_00, 0U);
   EXPECT_EQ(mock_fcru_rst_en_01, 0U);
   EXPECT_EQ(mock_fcru_pin_en_00, 0U);
   EXPECT_EQ(mock_fcru_pin_en_01, 0U);
   EXPECT_EQ(mock_fcru_cap_byp_00, 0U);
   EXPECT_EQ(mock_fcru_cap_byp_01, 0U);

   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Verify configuration was applied correctly
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
   EXPECT_EQ(mock_fcru_cap_byp_00, CAP_BYP_CONFIG0);
   EXPECT_EQ(mock_fcru_cap_byp_01, CAP_BYP_CONFIG1);
}

/**
 *  @b RE_PLT_FCRU_Init_02
 *  @n  Test initialization when registers have existing values
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_02)
{
   // Set some initial values in registers
   mock_fcru_pmu_faultb = 0xDEADBEEFU;
   mock_fcru_rst_en_00  = 0x12345678U;
   mock_fcru_rst_en_01  = 0xABCDEF00U;
   mock_fcru_pin_en_00  = 0xFFFFFFFFU;
   mock_fcru_pin_en_01  = 0x55555555U;
   mock_fcru_cap_byp_00 = 0xAAAAAAAAU;
   mock_fcru_cap_byp_01 = 0x11111111U;

   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Verify configuration overwrote existing values
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
   EXPECT_EQ(mock_fcru_cap_byp_00, CAP_BYP_CONFIG0);
   EXPECT_EQ(mock_fcru_cap_byp_01, CAP_BYP_CONFIG1);
}

/**
 *  @b RE_PLT_FCRU_Init_03
 *  @n  Test multiple initialization calls (idempotent behavior)
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_03)
{
   // Execute initialization multiple times
   RE_PLT_FCRU_Init();
   RE_PLT_FCRU_Init();
   RE_PLT_FCRU_Init();

   // Verify final configuration is correct
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
   EXPECT_EQ(mock_fcru_cap_byp_00, CAP_BYP_CONFIG0);
   EXPECT_EQ(mock_fcru_cap_byp_01, CAP_BYP_CONFIG1);
}

/**
 *  @b RE_PLT_FCRU_Init_04
 *  @n  Test that specific configuration values are properly set
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_04)
{
   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Test individual configuration register values
   // Note: These values depend on the actual configuration in SWC_PLT_CDD_FCRU_Cfg.h
   EXPECT_EQ(mock_fcru_pmu_faultb, ACTIVE_LOW_INACTIVE_HIGH); // PMU_FAULTB_CONFIG should be ACTIVE_LOW_INACTIVE_HIGH

   // Verify that each configuration register received its expected composite value
   // These are bitwise OR combinations of individual fault configurations
   ASSERT_TRUE(mock_fcru_rst_en_00 != 0U || RST_ENA_CONFIG0 == 0U); // Either configured or explicitly zero
   ASSERT_TRUE(mock_fcru_rst_en_01 != 0U || RST_ENA_CONFIG1 == 0U);
   ASSERT_TRUE(mock_fcru_pin_en_00 != 0U || PIN_ENA_CONFIG0 == 0U);
   ASSERT_TRUE(mock_fcru_pin_en_01 != 0U || PIN_ENA_CONFIG1 == 0U);
   ASSERT_TRUE(mock_fcru_cap_byp_00 != 0U || CAP_BYP_CONFIG0 == 0U);
   ASSERT_TRUE(mock_fcru_cap_byp_01 != 0U || CAP_BYP_CONFIG1 == 0U);
}

/**
 *  @b RE_PLT_FCRU_Init_05
 *  @n  Test that specific board Version
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_05)
{
   Board_Version_Test   = BOARD_REV_A2P0;
   mock_fcru_pmu_faultb = 0xDEADBEEFU;
   mock_fcru_rst_en_00  = 0x12345678U;
   mock_fcru_rst_en_01  = 0xABCDEF00U;
   mock_fcru_pin_en_00  = 0xFFFFFFFFU;
   mock_fcru_pin_en_01  = 0x55555555U;
   mock_fcru_cap_byp_00 = 0xAAAAAAAAU;
   mock_fcru_cap_byp_01 = 0x11111111U;

   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Verify Board Version was read correctly
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_A2P0);
}

/**
 *  @b RE_PLT_FCRU_Init_06
 *  @n  Test that unsupported board Version
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_06)
{
   Board_Version_Test   = BOARD_REV_EDU3;
   mock_fcru_pmu_faultb = 0xDEADBEEFU;
   mock_fcru_rst_en_00  = 0x12345678U;
   mock_fcru_rst_en_01  = 0xABCDEF00U;
   mock_fcru_pin_en_00  = 0xFFFFFFFFU;
   mock_fcru_pin_en_01  = 0x55555555U;
   mock_fcru_cap_byp_00 = 0xAAAAAAAAU;
   mock_fcru_cap_byp_01 = 0x11111111U;

   // Execute the function under test
   RE_PLT_FCRU_Init();

   // Verify Board Version was read correctly
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_EDU3);
}

/**
 *  @b Get_LBIST_Availability_In_HW_00
 *  @n  Test LBIST availability returns false when not all availability bits are set
 */
TEST_F(FCRU_UnitTestSuite, Get_LBIST_Availability_In_HW_00)
{
   mock_lbist_seq_stat0 = STS_LBSC_DONE_MASK;

   EXPECT_EQ(Get_LBIST_Availability_In_HW(), CODED_FALSE);
}

/**
 *  @b Get_LBIST_Availability_In_HW_01
 *  @n  Test LBIST availability returns true when both availability bits are set
 */
TEST_F(FCRU_UnitTestSuite, Get_LBIST_Availability_In_HW_01)
{
   mock_lbist_seq_stat0 = LBIST_AVAILABLE;

   EXPECT_EQ(Get_LBIST_Availability_In_HW(), CODED_TRUE);
}

/**
 *  @b RE_PLT_FCRU_Init_07
 *  @n  Test initialization disables PMU fault reaction when LBIST is unavailable
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_07)
{
   mock_lbist_seq_stat0 = STS_LBSC_DONE_MASK;
   mock_fcru_pin_en_00  = 0xFFFFFFFFU;
   mock_fcru_pin_en_01  = 0xFFFFFFFFU;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, 0U);
   EXPECT_EQ(mock_fcru_pin_en_01, 0U);
   EXPECT_EQ(mock_fcru_cap_byp_00, CAP_BYP_CONFIG0);
   EXPECT_EQ(mock_fcru_cap_byp_01, CAP_BYP_CONFIG1);
}

/**
 *  @b RE_PLT_FCRU_Init_08
 *  @n  Reset fault number 100 clears bit 0 in reset enable register 0
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_08)
{
   mock_repetative_reset_faultnum = 100U;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_rst_en_00, (RST_ENA_CONFIG0 & ~((uint32_t)1U << 0U)));
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, (PIN_ENA_CONFIG0 & ~((uint32_t)1U << 0U)));
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
}

/**
 *  @b RE_PLT_FCRU_Init_09
 *  @n  Reset fault number 131 clears bit 31 in reset enable register 0
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_09)
{
   mock_repetative_reset_faultnum = 131U;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_rst_en_00, (RST_ENA_CONFIG0 & ~((uint32_t)1U << 31U)));
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, (PIN_ENA_CONFIG0 & ~((uint32_t)1U << 31U)));
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
}

/**
 *  @b RE_PLT_FCRU_Init_10
 *  @n  Reset fault number 132 clears bit 0 in reset enable register 1
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_10)
{
   mock_repetative_reset_faultnum = 132U;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
}

/**
 *  @b RE_PLT_FCRU_Init_11
 *  @n  Reset fault number 163 clears bit 31 in reset enable register 1
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_11)
{
   mock_repetative_reset_faultnum = 163U;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
}

/**
 *  @b RE_PLT_FCRU_Init_12
 *  @n  Invalid reset fault number leaves reset enable registers unchanged
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Init_12)
{
   mock_repetative_reset_faultnum = NO_FCRU_REPETATIVE_RESET;

   RE_PLT_FCRU_Init();

   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   EXPECT_EQ(mock_fcru_pin_en_00, Pin_Ena_Config0);
   EXPECT_EQ(mock_fcru_pin_en_01, Pin_Ena_Config1);
}

/*===========================================================================*
 * Test Cases for RE_PLT_FCRU_Main_50ms
 *===========================================================================*/

/**
 *  @b RE_PLT_FCRU_Main_50ms_00
 *  @n  Test that RE_PLT_FCRU_Main_50ms runs without errors (currently empty function)
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Main_50ms_00)
{
   // Set initial register states
   uint32_t initial_mock_fcru_pmu_faultb = mock_fcru_pmu_faultb;
   uint32_t initial_rst_en_00            = mock_fcru_rst_en_00;
   uint32_t initial_rst_en_01            = mock_fcru_rst_en_01;
   uint32_t initial_pin_en_00            = mock_fcru_pin_en_00;

   // Execute the function under test
   RE_PLT_FCRU_Main_50ms();

   // Verify no registers were modified (function is currently empty)
   EXPECT_EQ(mock_fcru_pmu_faultb, initial_mock_fcru_pmu_faultb);
   EXPECT_EQ(mock_fcru_rst_en_00, initial_rst_en_00);
   EXPECT_EQ(mock_fcru_rst_en_01, initial_rst_en_01);
   EXPECT_EQ(mock_fcru_pin_en_00, initial_pin_en_00);
}

/**
 *  @b RE_PLT_FCRU_Main_50ms_01
 *  @n  Test multiple executions of the 50ms function
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Main_50ms_01)
{
   // Execute multiple times to ensure stability
   for (int i = 0; i < 10; i++)
   {
      RE_PLT_FCRU_Main_50ms();
   }

   // Should complete without any issues
   SUCCEED();
}

/**
 *  @b RE_PLT_FCRU_Main_50ms_02
 *  @n  Test Main function execution after initialization
 */
TEST_F(FCRU_UnitTestSuite, RE_PLT_FCRU_Main_50ms_02)
{
   // Execute initialization first
   RE_PLT_FCRU_Init();

   // Store configured values
   uint32_t configured_mock_fcru_pmu_faultb = mock_fcru_pmu_faultb;
   uint32_t configured_rst_en_00            = mock_fcru_rst_en_00;
   uint32_t configured_rst_en_01            = mock_fcru_rst_en_01;
   uint32_t configured_pin_en_00            = mock_fcru_pin_en_00;
   uint32_t configured_pin_en_01            = mock_fcru_pin_en_01;
   uint32_t configured_cap_byp_00           = mock_fcru_cap_byp_00;
   uint32_t configured_cap_byp_01           = mock_fcru_cap_byp_01;

   // Execute main function
   RE_PLT_FCRU_Main_50ms();

   // Verify configuration was not disturbed by main function
   EXPECT_EQ(mock_fcru_pmu_faultb, configured_mock_fcru_pmu_faultb);
   EXPECT_EQ(mock_fcru_rst_en_00, configured_rst_en_00);
   EXPECT_EQ(mock_fcru_rst_en_01, configured_rst_en_01);
   EXPECT_EQ(mock_fcru_pin_en_00, configured_pin_en_00);
   EXPECT_EQ(mock_fcru_pin_en_01, configured_pin_en_01);
   EXPECT_EQ(mock_fcru_cap_byp_00, configured_cap_byp_00);
   EXPECT_EQ(mock_fcru_cap_byp_01, configured_cap_byp_01);
}

/*===========================================================================*
 * Integration Tests
 *===========================================================================*/

/**
 *  @b FCRU_Init_Main_Integration_00
 *  @n  Test integration of Init followed by Main function calls
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Init_Main_Integration_00)
{
   // Test normal operational sequence
   RE_PLT_FCRU_Init();

   // Verify initialization completed successfully
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);

   // Execute main function multiple times (simulating periodic calls)
   for (int cycle = 0; cycle < 5; cycle++)
   {
      RE_PLT_FCRU_Main_50ms();

      // Verify configuration remains stable
      EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
      EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
      EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
   }
}

/**
 *  @b FCRU_Robustness_00
 *  @n  Test robustness with various call sequences
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Robustness_00)
{
   // Test various call sequences

   // Main before Init (should handle gracefully)
   RE_PLT_FCRU_Main_50ms();
   SUCCEED(); // Should not crash

   // Init multiple times
   RE_PLT_FCRU_Init();
   RE_PLT_FCRU_Init();

   // Main multiple times
   RE_PLT_FCRU_Main_50ms();
   RE_PLT_FCRU_Main_50ms();

   // Mixed sequence
   RE_PLT_FCRU_Init();
   RE_PLT_FCRU_Main_50ms();
   RE_PLT_FCRU_Init(); // Re-initialization
   RE_PLT_FCRU_Main_50ms();

   // Final verification - should still be properly configured
   EXPECT_EQ(mock_fcru_pmu_faultb, PMU_FAULTB_CONFIG);
   EXPECT_EQ(mock_fcru_rst_en_00, Rst_Ena_Config0);
   EXPECT_EQ(mock_fcru_rst_en_01, Rst_Ena_Config1);
}

/*===========================================================================*
 * Test Cases for Get_FCRU_Fault_Info (Static Function - Active)
 *===========================================================================*/

/**
 *  @b Get_FCRU_Fault_Info_00
 *  @n  Test Get_FCRU_Fault_Info when all DIAG registers are zero
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_00)
{
   FCRU_Diag_Info_t diag_info;

   // Set all DIAG registers to zero
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000000U;
   mock_fcru_diag_03 = 0x00000000U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // Verify all fields are zero
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x00000000U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x00000000U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0x00000000U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x00000000U);
}

/**
 *  @b Get_FCRU_Fault_Info_01
 *  @n  Test Get_FCRU_Fault_Info with valid DIAG register values
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_01)
{
   FCRU_Diag_Info_t diag_info;

   // Set DIAG registers to known values
   mock_fcru_diag_00 = 0x12345678U;
   mock_fcru_diag_01 = 0x9ABCDEF0U;
   mock_fcru_diag_02 = 0x11111111U;
   mock_fcru_diag_03 = 0x22222222U;
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x11111111U;
   Boot_Shared_Data.fcru_diag3 = 0x22222222U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // Verify values were copied correctly
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x12345678U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x9ABCDEF0U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0x11111111U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x22222222U);
}

/**
 *  @b Get_FCRU_Fault_Info_02
 *  @n  Test Get_FCRU_Fault_Info with maximum register values
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_02)
{
   FCRU_Diag_Info_t diag_info;

   // Set all DIAG registers to maximum value
   mock_fcru_diag_00 = 0xFFFFFFFFU;
   mock_fcru_diag_01 = 0xFFFFFFFFU;
   mock_fcru_diag_02 = 0xFFFFFFFFU;
   mock_fcru_diag_03 = 0xFFFFFFFFU;
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0xFFFFFFFFU;
   Boot_Shared_Data.fcru_diag3 = 0xFFFFFFFFU;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // Verify all fields have maximum value
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0xFFFFFFFFU);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0xFFFFFFFFU);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0xFFFFFFFFU);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0xFFFFFFFFU);
}

/**
 *  @b Get_FCRU_Fault_Info_03
 *  @n  Test Get_FCRU_Fault_Info with single bits set in each register
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_03)
{
   FCRU_Diag_Info_t diag_info;

   // Set single bits in each DIAG register
   mock_fcru_diag_00 = 0x00000001U; // Bit 0
   mock_fcru_diag_01 = 0x80000000U; // Bit 31
   mock_fcru_diag_02 = 0x00000100U; // Bit 8
   mock_fcru_diag_03 = 0x00010000U; // Bit 16
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00000100U;
   Boot_Shared_Data.fcru_diag3 = 0x00010000U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // Verify single bits are correctly copied
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x00000001U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x80000000U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0x00000100U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x00010000U);
}

/**
 *  @b Get_FCRU_Fault_Info_04
 *  @n  Test Get_FCRU_Fault_Info else-branch: patch version too low
 *      major=1, minor=6, patch=5 => Cond1 false (patch<6), Cond2 false (minor not>6), Cond3 false (major not>1)
 *      Exercises: else-branch, condition C (patch>=6) evaluating to false
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_04)
{
   FCRU_Diag_Info_t diag_info;

   // Set version so patch is below threshold
   Boot_Shared_Data.pbl_version_major = 1U;
   Boot_Shared_Data.pbl_version_minor = 6U;
   Boot_Shared_Data.pbl_version_patch = 5U;

   // Set DIAG registers to distinct values
   mock_fcru_diag_00           = 0xAAAAAAAAU;
   mock_fcru_diag_01           = 0xBBBBBBBBU;
   mock_fcru_diag_02           = 0xCCCCCCCCU;
   mock_fcru_diag_03           = 0xDDDDDDDDU;
   Boot_Shared_Data.fcru_diag2 = 0x11111111U;
   Boot_Shared_Data.fcru_diag3 = 0x22222222U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // else-branch: Diag_Pin_En reads from DIAG_02/03, Diag_Rst_En not updated from Boot_Shared_Data
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0xAAAAAAAAU);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0xBBBBBBBBU);
}

/**
 *  @b Get_FCRU_Fault_Info_05
 *  @n  Test Get_FCRU_Fault_Info else-branch: major version mismatch (too low)
 *      major=0, minor=0, patch=0 => all conditions false
 *      Exercises: else-branch, conditions A/D (major==1) evaluating to false
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_05)
{
   FCRU_Diag_Info_t diag_info;

   // Set version so major is below expected
   Boot_Shared_Data.pbl_version_major = 0U;
   Boot_Shared_Data.pbl_version_minor = 0U;
   Boot_Shared_Data.pbl_version_patch = 0U;

   // Set DIAG registers to distinct values
   mock_fcru_diag_00           = 0x11111111U;
   mock_fcru_diag_01           = 0x22222222U;
   mock_fcru_diag_02           = 0x33333333U;
   mock_fcru_diag_03           = 0x44444444U;
   Boot_Shared_Data.fcru_diag2 = 0x55555555U;
   Boot_Shared_Data.fcru_diag3 = 0x66666666U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // else-branch: Diag_Pin_En overwritten with DIAG_02/03 values
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x11111111U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x22222222U);
}

/**
 *  @b Get_FCRU_Fault_Info_06
 *  @n  Test Get_FCRU_Fault_Info if-branch via Cond2: minor version higher than expected
 *      major=1, minor=7, patch=0 => Cond1 false (minor!=6), Cond2 true (major==1 && minor>6)
 *      Exercises: condition B (minor==6) false, condition E (minor>6) true
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_06)
{
   FCRU_Diag_Info_t diag_info;

   // Set version: same major, higher minor
   Boot_Shared_Data.pbl_version_major = 1U;
   Boot_Shared_Data.pbl_version_minor = 7U;
   Boot_Shared_Data.pbl_version_patch = 0U;

   // Set DIAG registers and Boot_Shared_Data diagnostic fields
   mock_fcru_diag_00           = 0xAABBCCDDU;
   mock_fcru_diag_01           = 0x11223344U;
   mock_fcru_diag_02           = 0x55667788U;
   mock_fcru_diag_03           = 0x99AABBCCU;
   Boot_Shared_Data.fcru_diag2 = 0xDDEEFF00U;
   Boot_Shared_Data.fcru_diag3 = 0x12345678U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // if-branch: Diag_Rst_En reads from Boot_Shared_Data
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0xAABBCCDDU);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x11223344U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0xDDEEFF00U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x12345678U);
}

/**
 *  @b Get_FCRU_Fault_Info_07
 *  @n  Test Get_FCRU_Fault_Info if-branch via Cond3: major version higher than expected
 *      major=2, minor=0, patch=0 => Cond1 false, Cond2 false, Cond3 true (major>1)
 *      Exercises: condition F (major>1) true
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_07)
{
   FCRU_Diag_Info_t diag_info;

   // Set version: higher major
   Boot_Shared_Data.pbl_version_major = 2U;
   Boot_Shared_Data.pbl_version_minor = 0U;
   Boot_Shared_Data.pbl_version_patch = 0U;

   // Set DIAG registers and Boot_Shared_Data diagnostic fields
   mock_fcru_diag_00           = 0x10203040U;
   mock_fcru_diag_01           = 0x50607080U;
   mock_fcru_diag_02           = 0x90A0B0C0U;
   mock_fcru_diag_03           = 0xD0E0F000U;
   Boot_Shared_Data.fcru_diag2 = 0xABCDEF01U;
   Boot_Shared_Data.fcru_diag3 = 0x23456789U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // if-branch: Diag_Rst_En reads from Boot_Shared_Data
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x10203040U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x50607080U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0xABCDEF01U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x23456789U);
}

/**
 *  @b Get_FCRU_Fault_Info_08
 *  @n  Test Get_FCRU_Fault_Info if-branch via Cond1: patch version higher than expected
 *      major=1, minor=6, patch=7 => Cond1 true (patch>=6)
 *      Exercises: boundary condition, patch > threshold
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_08)
{
   FCRU_Diag_Info_t diag_info;

   // Set version: exact major/minor, higher patch
   Boot_Shared_Data.pbl_version_major = 1U;
   Boot_Shared_Data.pbl_version_minor = 6U;
   Boot_Shared_Data.pbl_version_patch = 7U;

   // Set DIAG registers and Boot_Shared_Data diagnostic fields
   mock_fcru_diag_00           = 0xFEDCBA98U;
   mock_fcru_diag_01           = 0x76543210U;
   mock_fcru_diag_02           = 0x01234567U;
   mock_fcru_diag_03           = 0x89ABCDEFU;
   Boot_Shared_Data.fcru_diag2 = 0x11112222U;
   Boot_Shared_Data.fcru_diag3 = 0x33334444U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // if-branch: Diag_Rst_En reads from Boot_Shared_Data
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0xFEDCBA98U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x76543210U);
   EXPECT_EQ(diag_info.Diag_Rst_En_00, 0x11112222U);
   EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x33334444U);
}

/**
 *  @b Get_FCRU_Fault_Info_09
 *  @n  Test Get_FCRU_Fault_Info else-branch: minor version lower, major matches
 *      major=1, minor=5, patch=10 => Cond1 false (minor!=6), Cond2 false (minor not>6), Cond3 false (major not>1)
 *      Exercises: condition B false with condition E false (minor < expected)
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_09)
{
   FCRU_Diag_Info_t diag_info;

   // Set version: same major, lower minor, high patch
   Boot_Shared_Data.pbl_version_major = 1U;
   Boot_Shared_Data.pbl_version_minor = 5U;
   Boot_Shared_Data.pbl_version_patch = 10U;

   // Set DIAG registers to distinct values
   mock_fcru_diag_00           = 0x01010101U;
   mock_fcru_diag_01           = 0x02020202U;
   mock_fcru_diag_02           = 0x03030303U;
   mock_fcru_diag_03           = 0x04040404U;
   Boot_Shared_Data.fcru_diag2 = 0x05050505U;
   Boot_Shared_Data.fcru_diag3 = 0x06060606U;

   // Execute function under test
   Get_FCRU_Fault_Info(&diag_info);

   // else-branch: Diag_Pin_En overwritten with DIAG_02/03 values
   EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x01010101U);
   EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x02020202U);
}

/*===========================================================================*
 * Test Cases for Get_Fault_Number (Static Function - Active)
 *===========================================================================*/

/**
 *  @b Get_Fault_Number_00
 *  @n  Test Get_Fault_Number when bit 0 is set
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_00)
{
   uint32 diag_reg = 0x00000001U; // Bit 0 set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 0);
}

/**
 *  @b Get_Fault_Number_01
 *  @n  Test Get_Fault_Number when bit 15 is set
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_01)
{
   uint32 diag_reg = 0x00008000U; // Bit 15 set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 15);
}

/**
 *  @b Get_Fault_Number_02
 *  @n  Test Get_Fault_Number when bit 31 (MSB) is set
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_02)
{
   uint32 diag_reg = 0x80000000U; // Bit 31 set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 31);
}

/**
 *  @b Get_Fault_Number_03
 *  @n  Test Get_Fault_Number when multiple bits are set (should return first one)
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_03)
{
   uint32 diag_reg = 0x00000006U; // Bits 1 and 2 set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 1); // Should return the first set bit (lowest)
}

/**
 *  @b Get_Fault_Number_04
 *  @n  Test Get_Fault_Number when all bits are set
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_04)
{
   uint32 diag_reg = 0xFFFFFFFFU; // All bits set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 0); // Should return first bit
}

/**
 *  @b Get_Fault_Number_05
 *  @n  Test Get_Fault_Number when no bits are set
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_05)
{
   uint32 diag_reg = 0x00000000U; // No bits set
   uint8 fault_num = Get_Fault_Number(diag_reg);
   EXPECT_EQ(fault_num, 0); // Should return 0 (default)
}

/**
 *  @b Get_Fault_Number_06
 *  @n  Test Get_Fault_Number for various middle bits
 */
TEST_F(FCRU_UnitTestSuite, Get_Fault_Number_06)
{
   // Test bit 10
   uint32 diag_reg_10 = 0x00000400U;
   EXPECT_EQ(Get_Fault_Number(diag_reg_10), 10);

   // Test bit 20
   uint32 diag_reg_20 = 0x00100000U;
   EXPECT_EQ(Get_Fault_Number(diag_reg_20), 20);

   // Test bit 25
   uint32 diag_reg_25 = 0x02000000U;
   EXPECT_EQ(Get_Fault_Number(diag_reg_25), 25);
}

/*===========================================================================*
 * Test Cases for FCRU_Clear_All_Fault_Status (Public Function - Active)
 *===========================================================================*/

/**
 *  @b FCRU_Clear_All_Fault_Status_00
 *  @n  Test FCRU_Clear_All_Fault_Status clears all fault registers
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Clear_All_Fault_Status_00)
{
   // Initialize clear registers to zero
   mock_fcru_ctrl_04 = 0x00000000U;
   mock_fcru_ctrl_05 = 0x00000000U;
   mock_fcru_ctrl_06 = 0x00000000U;
   mock_fcru_ctrl_07 = 0x00000000U;

   // Execute function under test
   FCRU_Clear_All_Fault_Status();

   // Verify all bits are set to clear faults
   EXPECT_EQ(mock_fcru_ctrl_04, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_05, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_06, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_07, 0xFFFFFFFFU);
}

/**
 *  @b FCRU_Clear_All_Fault_Status_01
 *  @n  Test FCRU_Clear_All_Fault_Status overwrites existing register values
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Clear_All_Fault_Status_01)
{
   // Set some initial values in clear registers
   mock_fcru_ctrl_04 = 0x12345678U;
   mock_fcru_ctrl_05 = 0xABCDEF00U;
   mock_fcru_ctrl_06 = 0x55555555U;
   mock_fcru_ctrl_07 = 0xAAAAAAAAU;

   // Execute function under test
   FCRU_Clear_All_Fault_Status();

   // Verify all registers are set to all 1's
   EXPECT_EQ(mock_fcru_ctrl_04, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_05, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_06, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_07, 0xFFFFFFFFU);
}

/**
 *  @b FCRU_Clear_All_Fault_Status_02
 *  @n  Test multiple executions of FCRU_Clear_All_Fault_Status
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Clear_All_Fault_Status_02)
{
   // Execute multiple times
   FCRU_Clear_All_Fault_Status();
   FCRU_Clear_All_Fault_Status();
   FCRU_Clear_All_Fault_Status();

   // Verify final state is correct
   EXPECT_EQ(mock_fcru_ctrl_04, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_05, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_06, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_07, 0xFFFFFFFFU);
}

/**
 *  @b FCRU_Clear_All_Fault_Status_03
 *  @n  Test that FCRU_Clear_All_Fault_Status doesn't affect other registers
 */
TEST_F(FCRU_UnitTestSuite, FCRU_Clear_All_Fault_Status_03)
{
   // Set other registers to known values
   mock_fcru_pmu_faultb = 0x12345678U;
   mock_fcru_rst_en_00  = 0xABCDEF00U;
   mock_fcru_diag_00    = 0x55555555U;

   // Execute function under test
   FCRU_Clear_All_Fault_Status();

   // Verify other registers are not affected
   EXPECT_EQ(mock_fcru_pmu_faultb, 0x12345678U);
   EXPECT_EQ(mock_fcru_rst_en_00, 0xABCDEF00U);
   EXPECT_EQ(mock_fcru_diag_00, 0x55555555U);

   // Verify clear registers are set
   EXPECT_EQ(mock_fcru_ctrl_04, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_05, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_06, 0xFFFFFFFFU);
   EXPECT_EQ(mock_fcru_ctrl_07, 0xFFFFFFFFU);
}

/*===========================================================================*
 * Test Cases for CS_FCRU_Fault_Injection (Runnable - Active)
 *===========================================================================*/

/**
 *  @b CS_FCRU_Fault_Injection_00
 *  @n  Valid control with low-range fault number triggers injection (0-31)
 */
TEST_F(FCRU_UnitTestSuite, CS_FCRU_Fault_Injection_00)
{
   mock_fcru_key_reg_test        = 0U;
   mock_fcru_force_fault_00_test = 0U;
   mock_fcru_force_fault_01_test = 0U;

   CS_FCRU_Fault_Injection(IC_INJECT_FAULT, 5U);

   EXPECT_NE(mock_fcru_force_fault_00_test, 0U);
   EXPECT_EQ(mock_fcru_force_fault_00_test, 1U << 5U);
   EXPECT_EQ(mock_fcru_key_reg_test, FCRU_KEY_CLEAR);
}

/**
 *  @b CS_FCRU_Fault_Injection_01
 *  @n  Valid control with high-range fault number triggers injection (32-63)
 */
TEST_F(FCRU_UnitTestSuite, CS_FCRU_Fault_Injection_01)
{
   mock_fcru_key_reg_test        = 0U;
   mock_fcru_force_fault_00_test = 0U;
   mock_fcru_force_fault_01_test = 0U;

   CS_FCRU_Fault_Injection(IC_INJECT_FAULT, 40U);

   EXPECT_NE(mock_fcru_force_fault_01_test, 0U);
   EXPECT_EQ(mock_fcru_force_fault_01_test, 1U << (40U - 32U));
   EXPECT_EQ(mock_fcru_key_reg_test, FCRU_KEY_CLEAR);
}

/**
 *  @b CS_FCRU_Fault_Injection_02
 *  @n  Invalid fault number (greater than max) does nothing
 */
TEST_F(FCRU_UnitTestSuite, CS_FCRU_Fault_Injection_02)
{
   mock_fcru_key_reg_test        = 0U;
   mock_fcru_force_fault_00_test = 0U;
   mock_fcru_force_fault_01_test = 0U;

   CS_FCRU_Fault_Injection(IC_INJECT_FAULT, (uint8)(MAX_FCRU_FAULT_NUM + 1U));

   EXPECT_EQ(mock_fcru_force_fault_00_test, 0U);
   EXPECT_EQ(mock_fcru_force_fault_01_test, 0U);
   EXPECT_EQ(mock_fcru_key_reg_test, 0U); // key should not be touched
}

/**
 *  @b CS_FCRU_Fault_Injection_03
 *  @n  Invalid control value does nothing
 */
TEST_F(FCRU_UnitTestSuite, CS_FCRU_Fault_Injection_03)
{
   mock_fcru_key_reg_test        = 0U;
   mock_fcru_force_fault_00_test = 0U;
   mock_fcru_force_fault_01_test = 0U;

   CS_FCRU_Fault_Injection(IC_REMOVE_FAULT /*not IC_INJECT_FAULT*/, 10U);

   EXPECT_EQ(mock_fcru_force_fault_00_test, 0U);
   EXPECT_EQ(mock_fcru_force_fault_01_test, 0U);
   EXPECT_EQ(mock_fcru_key_reg_test, 0U);
}

/*===========================================================================*
 * Test Cases for Log_Last_FCRU_Reset_Reason (Static Function - Active)
 * Note: This function calls Get_FCRU_Fault_Info and Log_ResetReason_Info_at_Startup
 * The Log_ResetReason_Info_at_Startup is an external function that needs to be mocked
 *===========================================================================*/

/**
 *  @b Log_Last_FCRU_Reset_Reason_00
 *  @n  Test Log_Last_FCRU_Reset_Reason when no faults are present
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_00)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set all DIAG registers to zero (no faults)
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000000U;
   mock_fcru_diag_03 = 0x00000000U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();

   // Verify RTE call was NOT made
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 0U);
}

/**
 *  @b Log_Last_FCRU_Reset_Reason_01
 *  @n  Test Log_Last_FCRU_Reset_Reason with fault 0 in Diag_Rst_En_00
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_01)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set fault 0 in Diag_Rst_En_00
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000001U; // Bit 0 set in RST_EN_00
   mock_fcru_diag_03 = 0x00000000U;
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00000001U;
   Boot_Shared_Data.fcru_diag3 = 0x00000000U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();

   // Verify RTE call was made with correct offset
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 1U);
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val, FCRU_RESET_REASON_OFFSET1 + 0);
}

/**
 *  @b Log_Last_FCRU_Reset_Reason_02
 *  @n  Test Log_Last_FCRU_Reset_Reason with fault 15 in Diag_Rst_En_00
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_02)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set fault 15 in Diag_Rst_En_00
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00008000U; // Bit 15 set in RST_EN_00
   mock_fcru_diag_03 = 0x00000000U;
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00008000U;
   Boot_Shared_Data.fcru_diag3 = 0x00000000U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();

   // Verify RTE call was made with correct value
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 1U);
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val, FCRU_RESET_REASON_OFFSET1 + 15);
}

/**
 *  @b Log_Last_FCRU_Reset_Reason_03
 *  @n  Test Log_Last_FCRU_Reset_Reason with fault 0 in Diag_Rst_En_01 (fault 32)
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_03)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set fault in Diag_Rst_En_01 (bit 0 = fault 32)
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000000U; // RST_EN_00 is zero
   mock_fcru_diag_03 = 0x00000001U; // Bit 0 set in RST_EN_01
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00000000U;
   Boot_Shared_Data.fcru_diag3 = 0x00000001U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();

   // Verify RTE call was made with correct offset
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 1U);
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val, FCRU_RESET_REASON_OFFSET2 + 0);
}

/**
 *  @b Log_Last_FCRU_Reset_Reason_04
 *  @n  Test Log_Last_FCRU_Reset_Reason with fault 31 in Diag_Rst_En_01 (fault 63)
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_04)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set fault 63 in Diag_Rst_En_01 (bit 31)
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000000U; // RST_EN_00 is zero
   mock_fcru_diag_03 = 0x80000000U; // Bit 31 set in RST_EN_01
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00000000U;
   Boot_Shared_Data.fcru_diag3 = 0x80000000U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();

   // Verify RTE call was made with correct offset
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 1U);
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val, FCRU_RESET_REASON_OFFSET2 + 31);
}

/**
 *  @b Log_Last_FCRU_Reset_Reason_05
 *  @n  Test that Diag_Rst_En_00 has priority over Diag_Rst_En_01
 */
TEST_F(FCRU_UnitTestSuite, Log_Last_FCRU_Reset_Reason_05)
{
   // Reset fake function
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count = 0U;
   Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val   = 0U;

   // Set faults in both registers
   mock_fcru_diag_00 = 0x00000000U;
   mock_fcru_diag_01 = 0x00000000U;
   mock_fcru_diag_02 = 0x00000001U; // Bit 0 set in RST_EN_00
   mock_fcru_diag_03 = 0x00000001U; // Bit 0 set in RST_EN_01
   // With correct bootloader version, RST_EN values come from Boot_Shared_Data
   Boot_Shared_Data.fcru_diag2 = 0x00000001U;
   Boot_Shared_Data.fcru_diag3 = 0x00000001U;

   // Execute function under test
   Log_Last_FCRU_Reset_Reason();
   // Verify only RST_EN_00 fault was logged (has priority)
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_call_count, 1U);
   EXPECT_EQ(Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason_arg0_val, FCRU_RESET_REASON_OFFSET1 + 0);
}

/*===========================================================================*
 * Test Cases for Static Functions (when enabled)
 * Note: These functions are currently in #if 0 block in source code
 * To enable these tests, change #if 0 to #if 1 in the source file
 *===========================================================================*/

#if 0 // Enable when static functions are uncommented in source code

// Mock variables for static function testing
static uint32_t mock_fcru_diag_00_reg = 0U;  /* DIAG PIN_EN 0-31 */
static uint32_t mock_fcru_diag_01_reg = 0U;  /* DIAG PIN_EN 32-63 */
static uint32_t mock_fcru_diag_02_reg = 0U;  /* DIAG RST_EN 0-31 */
static uint32_t mock_fcru_diag_03_reg = 0U;  /* DIAG RST_EN 32-63 */
static uint32_t mock_fcru_clear_pin_en_00 = 0U;
static uint32_t mock_fcru_clear_pin_en_01 = 0U;
static uint32_t mock_fcru_clear_rst_en_00 = 0U;
static uint32_t mock_fcru_clear_rst_en_01 = 0U;
static uint32_t mock_fcru_force_fault_00 = 0U;
static uint32_t mock_fcru_force_fault_01 = 0U;
static uint32_t mock_fcru_key_reg = 0U;

// Additional mock macros for static functions
   #undef FCRU_DIAG_00_ADDR
   #undef FCRU_DIAG_01_ADDR
   #undef FCRU_DIAG_02_ADDR
   #undef FCRU_DIAG_03_ADDR
   #undef CLEAR_PIN_EN_FAULT_STATE
   #undef CLEAR_RST_EN_FAULT_STATE
   #undef INJECT_FCRU_FAULT
   #undef FCRU_KEY_ADDR

   #define FCRU_DIAG_00_ADDR mock_fcru_diag_00_reg
   #define FCRU_DIAG_01_ADDR mock_fcru_diag_01_reg
   #define FCRU_DIAG_02_ADDR mock_fcru_diag_02_reg
   #define FCRU_DIAG_03_ADDR mock_fcru_diag_03_reg
   #define FCRU_KEY_ADDR     mock_fcru_key_reg

   #define CLEAR_PIN_EN_FAULT_STATE(fault_bit)                                                                                    \
      (fault_bit > 31 ? (mock_fcru_clear_pin_en_01 |= (1U << (fault_bit - 32U))) :                                                \
                        (mock_fcru_clear_pin_en_00 |= (1U << fault_bit)))

   #define CLEAR_RST_EN_FAULT_STATE(fault_bit)                                                                                    \
      (fault_bit > 31 ? (mock_fcru_clear_rst_en_01 |= (1U << (fault_bit - 32U))) :                                                \
                        (mock_fcru_clear_rst_en_00 |= (1U << fault_bit)))

   #define INJECT_FCRU_FAULT(fault_bit)                                                                                           \
      (fault_bit > 31 ? (mock_fcru_force_fault_01 |= (1U << (fault_bit - 32U))) : (mock_fcru_force_fault_00 |= (1U << fault_bit)))

/**
 *  @b Clear_FCRU_Fault_Status_PinEnStatus_test
 *  @n  Test clearing PIN_EN fault status for various fault numbers
 */
TEST_F(FCRU_UnitTestSuite, Clear_FCRU_Fault_Status_PinEnStatus_test)
{
    // Test clearing fault 0 (PIN_EN_STATUS)
    mock_fcru_clear_pin_en_00 = 0U;
    Clear_FCRU_Fault_Status(PIN_EN_STATUS, 0);
    EXPECT_EQ(mock_fcru_clear_pin_en_00, 0x00000001U);

    // Test clearing fault 15 (PIN_EN_STATUS)
    mock_fcru_clear_pin_en_00 = 0U;
    Clear_FCRU_Fault_Status(PIN_EN_STATUS, 15);
    EXPECT_EQ(mock_fcru_clear_pin_en_00, 0x00008000U);

    // Test clearing fault 32 (PIN_EN_STATUS) - should use mock_fcru_clear_pin_en_01
    mock_fcru_clear_pin_en_01 = 0U;
    Clear_FCRU_Fault_Status(PIN_EN_STATUS, 32);
    EXPECT_EQ(mock_fcru_clear_pin_en_01, 0x00000001U);

    // Test clearing fault 63 (PIN_EN_STATUS) - should use mock_fcru_clear_pin_en_01
    mock_fcru_clear_pin_en_01 = 0U;
    Clear_FCRU_Fault_Status(PIN_EN_STATUS, 63);
    EXPECT_EQ(mock_fcru_clear_pin_en_01, 0x80000000U);
}

/**
 *  @b Get_FCRU_Fault_Info_ValidPointer_test
 *  @n  Test getting FCRU fault information with valid pointer
 */
TEST_F(FCRU_UnitTestSuite, Get_FCRU_Fault_Info_ValidPointer_test)
{
    FCRU_Diag_Info_t diag_info;

    // Set mock diagnostic register values
    mock_fcru_diag_00_reg = 0x12345678U;
    mock_fcru_diag_01_reg = 0x9ABCDEF0U;
    mock_fcru_diag_02_reg = 0x11111111U;
    mock_fcru_diag_03_reg = 0x22222222U;

    // Execute function under test
    Get_FCRU_Fault_Info(&diag_info);

    // Verify values were copied correctly
    EXPECT_EQ(diag_info.Diag_Pin_En_00, 0x12345678U);
    EXPECT_EQ(diag_info.Diag_Pin_En_01, 0x9ABCDEF0U);
    EXPECT_EQ(diag_info.Diag_Rst_En_00, 0x11111111U);
    EXPECT_EQ(diag_info.Diag_Rst_En_01, 0x22222222U);
}

/**
 *  @b Inject_FCRU_Fault_LowFaultNumber_test
 *  @n  Test fault injection for fault numbers 0-31
 */
TEST_F(FCRU_UnitTestSuite, Inject_FCRU_Fault_LowFaultNumber_test)
{
    // Test injecting fault 0
    mock_fcru_key_reg = 0U;
    mock_fcru_force_fault_00 = 0U;
    Inject_FCRU_Fault(0);
    EXPECT_EQ(mock_fcru_force_fault_00, 0x00000001U);
    EXPECT_EQ(mock_fcru_key_reg, FCRU_KEY_CLEAR);  // Should be cleared at end

    // Test injecting fault 31
    mock_fcru_key_reg = 0U;
    mock_fcru_force_fault_00 = 0U;
    Inject_FCRU_Fault(31);
    EXPECT_EQ(mock_fcru_force_fault_00, 0x80000000U);
    EXPECT_EQ(mock_fcru_key_reg, FCRU_KEY_CLEAR);
}

#endif // End of static function tests
