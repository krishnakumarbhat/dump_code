/*===========================================================================*/
/**
 * @file therm_mon_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the thermal_monitor.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - TMU - Thermal Monitoring Unit
 *   - PVT - Process, Voltage, Temperature
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
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <cmath>
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"

/*===========================================================================*
 * Mock Register Definitions - Actual storage for mock registers
 * Must be defined BEFORE including therm_mon_fake.h
 *===========================================================================*/
/* PVT0 Mock Registers */
uint32_t mock_PVT0_CTRL0    = 0;
uint32_t mock_PVT0_CTRL1    = 0;
uint32_t mock_PVT0_CTRL3    = 0;
uint32_t mock_PVT0_CTRL4    = 0;
uint32_t mock_PVT0_IRQ_CTRL = 0;
uint32_t mock_PVT0_STAT0    = 0;
uint32_t mock_PVT0_STAT1    = 0;

/* PVT1 Mock Registers */
uint32_t mock_PVT1_CTRL0    = 0;
uint32_t mock_PVT1_CTRL1    = 0;
uint32_t mock_PVT1_CTRL3    = 0;
uint32_t mock_PVT1_CTRL4    = 0;
uint32_t mock_PVT1_IRQ_CTRL = 0;
uint32_t mock_PVT1_STAT0    = 0;
uint32_t mock_PVT1_STAT1    = 0;

/* SYS CTRL Mock Registers */
uint32_t mock_SYS_CTRL_PVT_TRIM = 0;

/* Reset function implementation */
void Reset_Mock_PVT_Registers(void)
{
   mock_PVT0_CTRL0    = 0;
   mock_PVT0_CTRL1    = 0;
   mock_PVT0_CTRL3    = 0;
   mock_PVT0_CTRL4    = 0;
   mock_PVT0_IRQ_CTRL = 0;
   mock_PVT0_STAT0    = 0;
   mock_PVT0_STAT1    = 0;

   mock_PVT1_CTRL0    = 0;
   mock_PVT1_CTRL1    = 0;
   mock_PVT1_CTRL3    = 0;
   mock_PVT1_CTRL4    = 0;
   mock_PVT1_IRQ_CTRL = 0;
   mock_PVT1_STAT0    = 0;
   mock_PVT1_STAT1    = 0;

   mock_SYS_CTRL_PVT_TRIM = 0;
}
/*===========================================================================*
 * Mock/Fake implementations for external dependencies
 *===========================================================================*/
/* Fake implementation of VStdLib_MemCpy used by VStdMemCpy macro */
extern "C" void VStdLib_MemCpy(void *pDst, const void *pSrc, unsigned int nCnt)
{
   memcpy(pDst, pSrc, nCnt);
}

/*===========================================================================*
 * Include the fake header which defines macro overrides
 *===========================================================================*/
#include "therm_mon_fake.h"
/*===========================================================================*
 * Include the source file under test
 * The fake header has already defined mocked register macros, so the
 * hardware register accesses in thermal_monitor.c will use mock variables.
 * Wrap in extern "C" to ensure C linkage for all functions (including static
 * PVT_Convert_To_Celsius) and prevent duplicate function symbols in coverage.
 *===========================================================================*/
extern "C"
{
#include "../Source/thermal_monitor.c"
}

/*===========================================================================*
 * Test Fixture Definition
 *===========================================================================*/
class ThermalMonitorTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      /* Reset all mock registers before each test */
      Reset_Mock_PVT_Registers();
   }

   void TearDown() override
   {
      /* Clean up after each test */
      Reset_Mock_PVT_Registers();
   }
};

/*===========================================================================*
 * Unit Tests for PVT_Monitoring_Init
 *===========================================================================*/

/**
 * @brief Test that PVT_Monitoring_Init clears PSAMPLE and VSAMPLE bits for PVT0
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Clears_PVT0_PSAMPLE_VSAMPLE)
{
   /* Setup - Set bits that should be cleared */
   mock_PVT0_CTRL1 = 0xFFFFFFFF;

   /* Execute */
   PVT_Monitoring_Init();

   /* Verify PSAMPLE and VSAMPLE bits are cleared (bits 4 and 3) */
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_PSAMPLE_Msk, 0U);
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_VSAMPLE_Msk, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init sets TRIM values correctly for PVT0
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Sets_PVT0_TRIM_Values)
{
   mock_SYS_CTRL_PVT_TRIM = (5U << SYS_CTRL_PVT0_TRIMG_Pos) | (6U << SYS_CTRL_PVT0_TRIMO_Pos) | SYS_CTRL_PVT0_TRIM_FLAG_Msk;

   /* Execute */
   PVT_Monitoring_Init();

   /* Verify TRIMG/TRIMO values are sourced from the SYS CTRL trim register */
   uint32_t trimg_value = (mock_PVT0_CTRL1 >> PVT0_TRIMG_Pos) & 0x1F;
   EXPECT_EQ(trimg_value, 5U);

   /* Verify TRIMO value is set (bits 6-11 should be 0x06) */
   uint32_t trimo_value = (mock_PVT0_CTRL1 >> PVT0_TRIMO_Pos) & 0x3F;
   EXPECT_EQ(trimo_value, 6U);
}

TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Uses_Default_PVT0_TRIM_Values_When_Flag_Not_Set)
{
   /* Execute */
   PVT_Monitoring_Init();

   EXPECT_EQ((mock_PVT0_CTRL1 >> PVT0_TRIMG_Pos) & 0x1F, DEFAULT_TRIMG_VALUE);
   EXPECT_EQ((mock_PVT0_CTRL1 >> PVT0_TRIMO_Pos) & 0x3F, DEFAULT_TRIMO_VALUE);
}

TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Preserves_NonTrim_PVT0_Bits)
{
   const uint32_t preserved_bits = 0x80000000U;
   mock_PVT0_CTRL1               = preserved_bits | PVT0_PSAMPLE_Msk | PVT0_VSAMPLE_Msk;
   mock_SYS_CTRL_PVT_TRIM        = (3U << SYS_CTRL_PVT0_TRIMG_Pos) | (9U << SYS_CTRL_PVT0_TRIMO_Pos) | SYS_CTRL_PVT0_TRIM_FLAG_Msk;

   PVT_Monitoring_Init();

   EXPECT_EQ((mock_PVT0_CTRL1 >> PVT0_TRIMG_Pos) & 0x1F, 3U);
   EXPECT_EQ((mock_PVT0_CTRL1 >> PVT0_TRIMO_Pos) & 0x3F, 9U);
   EXPECT_EQ(mock_PVT0_CTRL1 & preserved_bits, preserved_bits);
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_PSAMPLE_Msk, 0U);
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_VSAMPLE_Msk, 0U);
}

TEST_F(ThermalMonitorTest, Configure_PVT_Trim_Values_PVT0_Uses_OTP_Trim_When_Flag_Set)
{
   const uint32_t preserved_bits = 0x80000000U;
   mock_PVT0_CTRL1               = preserved_bits;
   mock_PVT1_CTRL1               = 0x12340000U;
   mock_SYS_CTRL_PVT_TRIM = (4U << SYS_CTRL_PVT0_TRIMG_Pos) | (11U << SYS_CTRL_PVT0_TRIMO_Pos) | SYS_CTRL_PVT0_TRIM_FLAG_Msk;

   Configure_PVT_Trim_Values(PVT0);

   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_TRIMG_Msk, CTRL_PVT0_TRIMG(4U));
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_TRIMO_Msk, CTRL_PVT0_TRIMO(11U));
   EXPECT_EQ(mock_PVT0_CTRL1 & preserved_bits, preserved_bits);
   EXPECT_EQ(mock_PVT1_CTRL1, 0x12340000U);
}

TEST_F(ThermalMonitorTest, Configure_PVT_Trim_Values_PVT0_Uses_Default_Trim_When_Flag_Clear)
{
   const uint32_t preserved_bits = 0x40000000U;
   mock_PVT0_CTRL1               = preserved_bits;

   Configure_PVT_Trim_Values(PVT0);

   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_TRIMG_Msk, CTRL_PVT0_TRIMG(DEFAULT_TRIMG_VALUE));
   EXPECT_EQ(mock_PVT0_CTRL1 & PVT0_TRIMO_Msk, CTRL_PVT0_TRIMO(DEFAULT_TRIMO_VALUE));
   EXPECT_EQ(mock_PVT0_CTRL1 & preserved_bits, preserved_bits);
}

/**
 * @brief Test that PVT_Monitoring_Init configures PVT0 accumulator length
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Configures_PVT0_ACC_Length)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify accumulator length is set correctly (6-bit field at offset 16)
    * Note: CTRL3 also contains ALARM0_ACC (bit 24) and ALARM1_ACC (bit 25) */
   uint32_t acc_len_field = (mock_PVT0_CTRL3 >> CTL_PVT0_ACC_LEN_OFFSET) & 0xFF;
   /* ACC_LEN is ORed into the register, so we check if the expected bits are set */
   EXPECT_NE(mock_PVT0_CTRL3 & (CTRL_PVT0_ACC_LEN << CTL_PVT0_ACC_LEN_OFFSET), 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT0 alarms
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT0_Alarms)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify ALARM0 and ALARM1 are enabled */
   EXPECT_NE(mock_PVT0_CTRL3 & CTRL_PVT0_ALARM0_ACC, 0U);
   EXPECT_NE(mock_PVT0_CTRL3 & CTRL_PVT0_ALARM1_ACC, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init sets PVT0 threshold values (multiplied by ACC_LEN)
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Sets_PVT0_Thresholds)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify ALARM0 threshold (lower 16 bits) - multiplied by ACC_LEN */
   uint32_t alarm0_thr = mock_PVT0_CTRL4 & 0xFFFF;
   EXPECT_EQ(alarm0_thr, CTRL_PVT0_ALARM0_THR * CTRL_PVT0_ACC_LEN);

   /* Verify ALARM1 threshold (upper 16 bits) - multiplied by ACC_LEN */
   uint32_t alarm1_thr = (mock_PVT0_CTRL4 >> CTL_PVT0_ALARM1_THR_OFFSET) & 0xFFFF;
   EXPECT_EQ(alarm1_thr, CTRL_PVT0_ALARM1_THR * CTRL_PVT0_ACC_LEN);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT0 interrupts
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT0_Interrupts)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify alarm and signal interrupts are enabled */
   EXPECT_NE(mock_PVT0_IRQ_CTRL & CTRL_PVT0_ALARM_ENA, 0U);
   EXPECT_NE(mock_PVT0_IRQ_CTRL & CTRL_PVT0_SIG_ENA, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT0 clock and run mode
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT0_Clock_And_Run)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify clock enable and run mode are set */
   EXPECT_NE(mock_PVT0_CTRL0 & CTRL_PVT0_CK_EN, 0U);
   EXPECT_NE(mock_PVT0_CTRL0 & CTRL_PVT0_RUN, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init clears PSAMPLE and VSAMPLE bits for PVT1
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Clears_PVT1_PSAMPLE_VSAMPLE)
{
   /* Setup - Set bits that should be cleared */
   mock_PVT1_CTRL1 = 0xFFFFFFFF;

   /* Execute */
   PVT_Monitoring_Init();

   /* Verify PSAMPLE and VSAMPLE bits are cleared */
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_PSAMPLE_Msk, 0U);
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_VSAMPLE_Msk, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init sets TRIM values correctly for PVT1
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Sets_PVT1_TRIM_Values)
{
   mock_SYS_CTRL_PVT_TRIM = (5U << SYS_CTRL_PVT1_TRIMG_Pos) | (6U << SYS_CTRL_PVT1_TRIMO_Pos) | SYS_CTRL_PVT1_TRIM_FLAG_Msk;

   /* Execute */
   PVT_Monitoring_Init();

   /* Verify TRIMG value is set */
   uint32_t trimg_value = (mock_PVT1_CTRL1 >> PVT1_TRIMG_Pos) & 0x1F;
   EXPECT_EQ(trimg_value, 5U);

   /* Verify TRIMO value is set */
   uint32_t trimo_value = (mock_PVT1_CTRL1 >> PVT1_TRIMO_Pos) & 0x3F;
   EXPECT_EQ(trimo_value, 6U);
}

TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Uses_Default_PVT1_TRIM_Values_When_Flag_Not_Set)
{
   /* Execute */
   PVT_Monitoring_Init();

   EXPECT_EQ((mock_PVT1_CTRL1 >> PVT1_TRIMG_Pos) & 0x1F, DEFAULT_TRIMG_VALUE);
   EXPECT_EQ((mock_PVT1_CTRL1 >> PVT1_TRIMO_Pos) & 0x3F, DEFAULT_TRIMO_VALUE);
}

TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Preserves_NonTrim_PVT1_Bits)
{
   const uint32_t preserved_bits = 0x40000000U;
   mock_PVT1_CTRL1               = preserved_bits | PVT1_PSAMPLE_Msk | PVT1_VSAMPLE_Msk;
   mock_SYS_CTRL_PVT_TRIM        = (2U << SYS_CTRL_PVT1_TRIMG_Pos) | (7U << SYS_CTRL_PVT1_TRIMO_Pos) | SYS_CTRL_PVT1_TRIM_FLAG_Msk;

   PVT_Monitoring_Init();

   EXPECT_EQ((mock_PVT1_CTRL1 >> PVT1_TRIMG_Pos) & 0x1F, 2U);
   EXPECT_EQ((mock_PVT1_CTRL1 >> PVT1_TRIMO_Pos) & 0x3F, 7U);
   EXPECT_EQ(mock_PVT1_CTRL1 & preserved_bits, preserved_bits);
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_PSAMPLE_Msk, 0U);
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_VSAMPLE_Msk, 0U);
}

TEST_F(ThermalMonitorTest, Configure_PVT_Trim_Values_PVT1_Uses_OTP_Trim_When_Flag_Set)
{
   const uint32_t preserved_bits = 0x20000000U;
   mock_PVT0_CTRL1               = 0x55AA0000U;
   mock_PVT1_CTRL1               = preserved_bits;
   mock_SYS_CTRL_PVT_TRIM = (6U << SYS_CTRL_PVT1_TRIMG_Pos) | (13U << SYS_CTRL_PVT1_TRIMO_Pos) | SYS_CTRL_PVT1_TRIM_FLAG_Msk;

   Configure_PVT_Trim_Values(PVT1);

   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_TRIMG_Msk, CTRL_PVT1_TRIMG(6U));
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_TRIMO_Msk, CTRL_PVT1_TRIMO(13U));
   EXPECT_EQ(mock_PVT1_CTRL1 & preserved_bits, preserved_bits);
   EXPECT_EQ(mock_PVT0_CTRL1, 0x55AA0000U);
}

TEST_F(ThermalMonitorTest, Configure_PVT_Trim_Values_PVT1_Uses_Default_Trim_When_Flag_Clear)
{
   const uint32_t preserved_bits = 0x10000000U;
   mock_PVT1_CTRL1               = preserved_bits;

   Configure_PVT_Trim_Values(PVT1);

   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_TRIMG_Msk, CTRL_PVT1_TRIMG(DEFAULT_TRIMG_VALUE));
   EXPECT_EQ(mock_PVT1_CTRL1 & PVT1_TRIMO_Msk, CTRL_PVT1_TRIMO(DEFAULT_TRIMO_VALUE));
   EXPECT_EQ(mock_PVT1_CTRL1 & preserved_bits, preserved_bits);
}

TEST_F(ThermalMonitorTest, Configure_PVT_Trim_Values_Invalid_Site_Does_Not_Modify_Registers)
{
   mock_PVT0_CTRL1        = 0x13579BDFU;
   mock_PVT1_CTRL1        = 0x2468ACE0U;
   mock_SYS_CTRL_PVT_TRIM = 0xFFFFFFFFU;

   Configure_PVT_Trim_Values((PVT_Measurement_Sites_T)MAX_PVT);

   EXPECT_EQ(mock_PVT0_CTRL1, 0x13579BDFU);
   EXPECT_EQ(mock_PVT1_CTRL1, 0x2468ACE0U);
}

/**
 * @brief Test that PVT_Monitoring_Init configures PVT1 accumulator length
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Configures_PVT1_ACC_Length)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify accumulator length is set correctly (6-bit field at offset 16)
    * Note: CTRL3 also contains ALARM0_ACC (bit 24) and ALARM1_ACC (bit 25) */
   uint32_t acc_len_field = (mock_PVT1_CTRL3 >> CTL_PVT1_ACC_LEN_OFFSET) & 0xFF;
   /* ACC_LEN is ORed into the register, so we check if the expected bits are set */
   EXPECT_NE(mock_PVT1_CTRL3 & (CTRL_PVT1_ACC_LEN << CTL_PVT1_ACC_LEN_OFFSET), 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT1 alarms
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT1_Alarms)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify ALARM0 and ALARM1 are enabled */
   EXPECT_NE(mock_PVT1_CTRL3 & CTRL_PVT1_ALARM0_ACC, 0U);
   EXPECT_NE(mock_PVT1_CTRL3 & CTRL_PVT1_ALARM1_ACC, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init sets PVT1 threshold values (multiplied by ACC_LEN)
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Sets_PVT1_Thresholds)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify ALARM0 threshold (lower 16 bits) - multiplied by ACC_LEN */
   uint32_t alarm0_thr = mock_PVT1_CTRL4 & 0xFFFF;
   EXPECT_EQ(alarm0_thr, CTRL_PVT1_ALARM0_THR * CTRL_PVT1_ACC_LEN);

   /* Verify ALARM1 threshold (upper 16 bits) - multiplied by ACC_LEN */
   uint32_t alarm1_thr = (mock_PVT1_CTRL4 >> CTL_PVT1_ALARM1_THR_OFFSET) & 0xFFFF;
   EXPECT_EQ(alarm1_thr, CTRL_PVT1_ALARM1_THR * CTRL_PVT1_ACC_LEN);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT1 interrupts
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT1_Interrupts)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify alarm and signal interrupts are enabled */
   EXPECT_NE(mock_PVT1_IRQ_CTRL & CTRL_PVT1_ALARM_ENA, 0U);
   EXPECT_NE(mock_PVT1_IRQ_CTRL & CTRL_PVT1_SIG_ENA, 0U);
}

/**
 * @brief Test that PVT_Monitoring_Init enables PVT1 clock and run mode
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Enables_PVT1_Clock_And_Run)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify clock enable and run mode are set */
   EXPECT_NE(mock_PVT1_CTRL0 & CTRL_PVT1_CK_EN, 0U);
   EXPECT_NE(mock_PVT1_CTRL0 & CTRL_PVT1_RUN, 0U);
}

/**
 * @brief Test complete initialization sequence for both PVT0 and PVT1
 */
TEST_F(ThermalMonitorTest, PVT_Monitoring_Init_Complete_Sequence)
{
   /* Execute */
   PVT_Monitoring_Init();

   /* Verify PVT0 is fully configured */
   EXPECT_NE(mock_PVT0_CTRL0, 0U);    /* Clock and run enabled */
   EXPECT_NE(mock_PVT0_CTRL1, 0U);    /* TRIM values set */
   EXPECT_NE(mock_PVT0_CTRL3, 0U);    /* Alarms and length configured */
   EXPECT_NE(mock_PVT0_CTRL4, 0U);    /* Thresholds set */
   EXPECT_NE(mock_PVT0_IRQ_CTRL, 0U); /* Interrupts enabled */

   /* Verify PVT1 is fully configured */
   EXPECT_NE(mock_PVT1_CTRL0, 0U);    /* Clock and run enabled */
   EXPECT_NE(mock_PVT1_CTRL1, 0U);    /* TRIM values set */
   EXPECT_NE(mock_PVT1_CTRL3, 0U);    /* Alarms and length configured */
   EXPECT_NE(mock_PVT1_CTRL4, 0U);    /* Thresholds set */
   EXPECT_NE(mock_PVT1_IRQ_CTRL, 0U); /* Interrupts enabled */
}

/*===========================================================================*
 * Unit Tests for Read_PVT_Temperature_Values
 *===========================================================================*/

/**
 * @brief Test that Read_PVT_Temperature_Values reads PVT0 instantaneous temperature correctly
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Reads_PVT0_Inst_Temp)
{
   /* Setup - Set known raw temperature value in PVT0 STAT0 register */
   const uint32_t expected_raw_temp = 0x1A5U; /* Example raw value within 10-bit range */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = expected_raw_temp;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - The function reads the register with proper mask (0x3FF) */
   /* The instantaneous value should be masked with STS_PVT0_DOUT_INS_MASK */
   EXPECT_EQ(mock_PVT0_STAT0 & STS_PVT0_DOUT_INS_MASK, expected_raw_temp);
}

/**
 * @brief Test that Read_PVT_Temperature_Values reads PVT1 instantaneous temperature correctly
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Reads_PVT1_Inst_Temp)
{
   /* Setup - Set known raw temperature value in PVT1 STAT0 register */
   const uint32_t expected_raw_temp = 0x2B7U; /* Example raw value within 10-bit range */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT0 = expected_raw_temp;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - The function reads the register with proper mask (0x3FF) */
   EXPECT_EQ(mock_PVT1_STAT0 & STS_PVT1_DOUT_INS_MASK, expected_raw_temp);
}

/**
 * @brief Test that Read_PVT_Temperature_Values reads PVT0 accumulated temperature correctly
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Reads_PVT0_Acc_Temp)
{
   /* Setup - Set known accumulated temperature value in PVT0 STAT1 register */
   const uint32_t accumulated_temp = 0xA5A5U; /* Example accumulated value within 16-bit range */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT0_STAT1 = accumulated_temp;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - The function reads the register with proper mask (0xFFFF) */
   EXPECT_EQ(mock_PVT0_STAT1 & STS_PVT0_DOUT_ACC_MASK, accumulated_temp);
}

/**
 * @brief Test that Read_PVT_Temperature_Values reads PVT1 accumulated temperature correctly
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Reads_PVT1_Acc_Temp)
{
   /* Setup - Set known accumulated temperature value in PVT1 STAT1 register */
   const uint32_t accumulated_temp = 0xB7B7U; /* Example accumulated value within 16-bit range */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT1_STAT1 = accumulated_temp;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - The function reads the register with proper mask (0xFFFF) */
   EXPECT_EQ(mock_PVT1_STAT1 & STS_PVT1_DOUT_ACC_MASK, accumulated_temp);
}

/**
 * @brief Test that Read_PVT_Temperature_Values masks instantaneous values to 10 bits
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Masks_Inst_Temp_To_10_Bits)
{
   /* Setup - Set values with bits outside the 10-bit mask */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0xFFFFFFFFU; /* All bits set */
   mock_PVT1_STAT0 = 0xFFFFFFFFU; /* All bits set */
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Only lower 10 bits should be considered (mask = 0x3FF) */
   EXPECT_EQ(mock_PVT0_STAT0 & STS_PVT0_DOUT_INS_MASK, 0x3FFU);
   EXPECT_EQ(mock_PVT1_STAT0 & STS_PVT1_DOUT_INS_MASK, 0x3FFU);
}

/**
 * @brief Test that Read_PVT_Temperature_Values masks accumulated values to 16 bits
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Masks_Acc_Temp_To_16_Bits)
{
   /* Setup - Set values with bits outside the 16-bit mask */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT0_STAT1 = 0xFFFFFFFFU; /* All bits set */
   mock_PVT1_STAT1 = 0xFFFFFFFFU; /* All bits set */

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Only lower 16 bits should be considered (mask = 0xFFFF) */
   EXPECT_EQ(mock_PVT0_STAT1 & STS_PVT0_DOUT_ACC_MASK, 0xFFFFU);
   EXPECT_EQ(mock_PVT1_STAT1 & STS_PVT1_DOUT_ACC_MASK, 0xFFFFU);
}

/**
 * @brief Test that Read_PVT_Temperature_Values handles zero temperature values
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Handles_Zero_Values)
{
   /* Setup - All registers are zero (from SetUp) */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute - Should not crash with zero values */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Registers still contain zero */
   EXPECT_EQ(mock_PVT0_STAT0, 0x0U);
   EXPECT_EQ(mock_PVT0_STAT1, 0x0U);
   EXPECT_EQ(mock_PVT1_STAT0, 0x0U);
   EXPECT_EQ(mock_PVT1_STAT1, 0x0U);
}

/**
 * @brief Test that Read_PVT_Temperature_Values handles maximum valid instantaneous values
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Handles_Max_Inst_Values)
{
   /* Setup - Set maximum valid 10-bit values (0x3FF = 1023) */
   const uint32_t max_inst_value = 0x3FFU;
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = max_inst_value;
   mock_PVT1_STAT0 = max_inst_value;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Maximum instantaneous values are preserved */
   EXPECT_EQ(mock_PVT0_STAT0 & STS_PVT0_DOUT_INS_MASK, max_inst_value);
   EXPECT_EQ(mock_PVT1_STAT0 & STS_PVT1_DOUT_INS_MASK, max_inst_value);
}

/**
 * @brief Test that Read_PVT_Temperature_Values handles maximum valid accumulated values
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Handles_Max_Acc_Values)
{
   /* Setup - Set maximum valid 16-bit values (0xFFFF = 65535) */
   const uint32_t max_acc_value = 0xFFFFU;
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT0_STAT1 = max_acc_value;
   mock_PVT1_STAT1 = max_acc_value;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Maximum accumulated values are preserved */
   EXPECT_EQ(mock_PVT0_STAT1 & STS_PVT0_DOUT_ACC_MASK, max_acc_value);
   EXPECT_EQ(mock_PVT1_STAT1 & STS_PVT1_DOUT_ACC_MASK, max_acc_value);
}

/**
 * @brief Test Read_PVT_Temperature_Values with realistic temperature scenario
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Realistic_Scenario)
{
   /* Setup - Set realistic temperature values
    * Typical raw value around 500 corresponds to ~25°C based on polynomial conversion
    * Accumulated value = instantaneous * CTRL_PVT0_ACC_LEN for stable temperature
    */
   const uint32_t pvt0_inst = 0x1F4U;                        /* 500 decimal - typical room temperature */
   const uint32_t pvt1_inst = 0x1F8U;                        /* 504 decimal - slightly different sensor */
   const uint32_t pvt0_acc  = pvt0_inst * CTRL_PVT0_ACC_LEN; /* Accumulated over samples */
   const uint32_t pvt1_acc  = pvt1_inst * CTRL_PVT1_ACC_LEN; /* Accumulated over samples */

   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = pvt0_inst;
   mock_PVT1_STAT0 = pvt1_inst;
   mock_PVT0_STAT1 = pvt0_acc;
   mock_PVT1_STAT1 = pvt1_acc;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Values are read correctly */
   EXPECT_EQ(mock_PVT0_STAT0 & STS_PVT0_DOUT_INS_MASK, pvt0_inst);
   EXPECT_EQ(mock_PVT1_STAT0 & STS_PVT1_DOUT_INS_MASK, pvt1_inst);
   EXPECT_EQ(mock_PVT0_STAT1 & STS_PVT0_DOUT_ACC_MASK, pvt0_acc);
   EXPECT_EQ(mock_PVT1_STAT1 & STS_PVT1_DOUT_ACC_MASK, pvt1_acc);
}

/**
 * @brief Test Read_PVT_Temperature_Values reads both PVT0 and PVT1 simultaneously
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Reads_Both_PVTs)
{
   /* Setup - Set different values for each PVT to verify both are read */
   PVT_Temp_Celsius_T pvt_temp_c;
   mock_PVT0_STAT0 = 0x100U;
   mock_PVT0_STAT1 = 0x2000U;
   mock_PVT1_STAT0 = 0x200U;
   mock_PVT1_STAT1 = 0x4000U;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - All four readings are taken from both PVT peripherals */
   EXPECT_EQ(mock_PVT0_STAT0 & STS_PVT0_DOUT_INS_MASK, 0x100U);
   EXPECT_EQ(mock_PVT0_STAT1 & STS_PVT0_DOUT_ACC_MASK, 0x2000U);
   EXPECT_EQ(mock_PVT1_STAT0 & STS_PVT1_DOUT_INS_MASK, 0x200U);
   EXPECT_EQ(mock_PVT1_STAT1 & STS_PVT1_DOUT_ACC_MASK, 0x4000U);
}

/*===========================================================================*
 * Unit Tests for PVT_Convert_To_Celsius
 *===========================================================================*/

/**
 * @brief Helper function to compute expected Celsius temperature from raw value
 *        using the polynomial formula: temp = (((a4*x + a3)*x + a2)*x + a1)*x + a0
 */
static float32 ComputeExpectedCelsius(float32 raw_value)
{
   /* Polynomial coefficients from thermal_monitor.c */
   const float32 coeff_a4 = -9.2627e-12f;
   const float32 coeff_a3 = 6.0373e-08f;
   const float32 coeff_a2 = -1.7058e-04f;
   const float32 coeff_a1 = 3.2512e-01f;
   const float32 coeff_a0 = -4.9002e+01f;

   return (((coeff_a4 * raw_value + coeff_a3) * raw_value + coeff_a2) * raw_value + coeff_a1) * raw_value + coeff_a0;
}

/**
 * @brief Test PVT_Convert_To_Celsius with zero raw values
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Zero_Raw_Values)
{
   /* Setup */
   PVT_Temperatures_T raw_temps     = {0U, 0U, 0U, 0U};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - For raw value 0, result should be a0 = -49.002 */
   float32 expected = ComputeExpectedCelsius(0.0f);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);
}

/**
 * @brief Test PVT_Convert_To_Celsius with typical room temperature raw value (~25°C)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Room_Temperature)
{
   /* Setup - Raw value ~228 typically corresponds to ~25°C */
   const uint32_t room_temp_raw     = 228U;
   PVT_Temperatures_T raw_temps     = {room_temp_raw, room_temp_raw, room_temp_raw, room_temp_raw};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Temperature should be approximately 25°C (within reasonable tolerance) */
   float32 expected = ComputeExpectedCelsius((float32)room_temp_raw);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);

   /* Result should be in reasonable room temperature range (15°C to 35°C) */
   EXPECT_GT(celsius_temps.PVT0_Inst_Temp_Value_C, 15.0f);
   EXPECT_LT(celsius_temps.PVT0_Inst_Temp_Value_C, 35.0f);
}

/**
 * @brief Test PVT_Convert_To_Celsius with different values for each PVT channel
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Different_Values_Per_Channel)
{
   /* Setup - Different raw values for each channel */
   PVT_Temperatures_T raw_temps = {
      200U, /* PVT0 Instant */
      250U, /* PVT1 Instant */
      220U, /* PVT0 Average */
      280U  /* PVT1 Average */
   };
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Each channel should have a different converted value */
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, ComputeExpectedCelsius(200.0f), 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, ComputeExpectedCelsius(250.0f), 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, ComputeExpectedCelsius(220.0f), 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, ComputeExpectedCelsius(280.0f), 0.001f);

   /* Higher raw values should result in higher temperatures */
   EXPECT_LT(celsius_temps.PVT0_Inst_Temp_Value_C, celsius_temps.PVT1_Inst_Temp_Value_C);
   EXPECT_LT(celsius_temps.PVT0_Avg_Temp_Value_C, celsius_temps.PVT1_Avg_Temp_Value_C);
}

/**
 * @brief Test PVT_Convert_To_Celsius with maximum 10-bit raw value (0x3FF = 1023)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Max_10Bit_Raw_Value)
{
   /* Setup - Maximum 10-bit value */
   const uint32_t max_raw           = 0x3FFU; /* 1023 */
   PVT_Temperatures_T raw_temps     = {max_raw, max_raw, max_raw, max_raw};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - All values should be computed correctly */
   float32 expected = ComputeExpectedCelsius((float32)max_raw);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);
}

/**
 * @brief Test PVT_Convert_To_Celsius with mid-range raw value (512)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Mid_Range_Raw_Value)
{
   /* Setup - Mid-range value */
   const uint32_t mid_raw           = 512U;
   PVT_Temperatures_T raw_temps     = {mid_raw, mid_raw, mid_raw, mid_raw};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Value should be computed correctly */
   float32 expected = ComputeExpectedCelsius((float32)mid_raw);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);
}

/**
 * @brief Test PVT_Convert_To_Celsius with low raw value (cold temperature)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Low_Raw_Value_Cold_Temp)
{
   /* Setup - Low raw value corresponding to cold temperature */
   const uint32_t cold_raw          = 100U;
   PVT_Temperatures_T raw_temps     = {cold_raw, cold_raw, cold_raw, cold_raw};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Value should be computed correctly */
   float32 expected = ComputeExpectedCelsius((float32)cold_raw);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);

   /* Cold raw value should produce lower temperature than room temperature */
   PVT_Temperatures_T room_temps   = {228U, 228U, 228U, 228U};
   PVT_Temp_Celsius_T room_celsius = {0.0f, 0.0f, 0.0f, 0.0f};
   PVT_Convert_To_Celsius(&room_temps, &room_celsius);
   EXPECT_LT(celsius_temps.PVT0_Inst_Temp_Value_C, room_celsius.PVT0_Inst_Temp_Value_C);
}

/**
 * @brief Test PVT_Convert_To_Celsius with high raw value (hot temperature)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_High_Raw_Value_Hot_Temp)
{
   /* Setup - High raw value corresponding to hot temperature (~85°C typical max operating) */
   const uint32_t hot_raw           = 420U;
   PVT_Temperatures_T raw_temps     = {hot_raw, hot_raw, hot_raw, hot_raw};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Value should be computed correctly */
   float32 expected = ComputeExpectedCelsius((float32)hot_raw);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);

   /* Hot raw value should produce higher temperature than room temperature */
   PVT_Temperatures_T room_temps   = {228U, 228U, 228U, 228U};
   PVT_Temp_Celsius_T room_celsius = {0.0f, 0.0f, 0.0f, 0.0f};
   PVT_Convert_To_Celsius(&room_temps, &room_celsius);
   EXPECT_GT(celsius_temps.PVT0_Inst_Temp_Value_C, room_celsius.PVT0_Inst_Temp_Value_C);
}

/**
 * @brief Test PVT_Convert_To_Celsius polynomial computation accuracy
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Polynomial_Accuracy)
{
   /* Setup - Test multiple known raw values for polynomial accuracy */
   const uint32_t test_values[] = {50U, 150U, 300U, 450U, 600U, 750U, 900U};
   const size_t num_values      = sizeof(test_values) / sizeof(test_values[0]);

   for (size_t i = 0; i < num_values; i++)
   {
      PVT_Temperatures_T raw_temps     = {test_values[i], test_values[i], test_values[i], test_values[i]};
      PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

      /* Execute */
      PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

      /* Verify - All channels should match expected polynomial output */
      float32 expected = ComputeExpectedCelsius((float32)test_values[i]);
      EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f) << "Failed for raw value: " << test_values[i];
      EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f) << "Failed for raw value: " << test_values[i];
      EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f) << "Failed for raw value: " << test_values[i];
      EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f) << "Failed for raw value: " << test_values[i];
   }
}

/**
 * @brief Test PVT_Convert_To_Celsius temperature increases monotonically with raw value
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Monotonic_Increase)
{
   /* Setup - Test that temperature increases as raw value increases (within valid operating range) */
   float32 prev_temp = -100.0f; /* Start with very low value */

   /* Test raw values from 100 to 500 (typical operating range) */
   for (uint32_t raw = 100U; raw <= 500U; raw += 50U)
   {
      PVT_Temperatures_T raw_temps     = {raw, raw, raw, raw};
      PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

      /* Execute */
      PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

      /* Verify - Temperature should be greater than previous */
      EXPECT_GT(celsius_temps.PVT0_Inst_Temp_Value_C, prev_temp)
         << "Temperature not monotonically increasing at raw value: " << raw;
      prev_temp = celsius_temps.PVT0_Inst_Temp_Value_C;
   }
}

/**
 * @brief Test PVT_Convert_To_Celsius with raw value of 1 (minimum non-zero)
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Min_NonZero_Raw_Value)
{
   /* Setup */
   PVT_Temperatures_T raw_temps     = {1U, 1U, 1U, 1U};
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify */
   float32 expected = ComputeExpectedCelsius(1.0f);
   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected, 0.001f);
}

/*===========================================================================*
 * Unit Tests for Update_Thermal_Monitor_Values
 *===========================================================================*/

/**
 * @brief Helper function to convert Celsius to Fahrenheit
 */
static float32 CelsiusToFahrenheit(float32 temp_c)
{
   return ((temp_c * 9.0f / 5.0f) + 32.0f);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values correctly populates the result structure with zero raw values
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Zero_Raw_Values)
{
   /* Setup - All registers return zero */
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0xFF, sizeof(therm_results)); /* Pre-fill with non-zero to verify update */

   mock_PVT0_STAT0 = 0x0U;
   mock_PVT0_STAT1 = 0x0U;
   mock_PVT1_STAT0 = 0x0U;
   mock_PVT1_STAT1 = 0x0U;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Celsius temperatures should equal polynomial output for raw=0 */
   float32 expected_c = ComputeExpectedCelsius(0.0f);
   float32 expected_f = CelsiusToFahrenheit(expected_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_c, 0.001f);

   /* Verify - Fahrenheit temperatures should be correctly converted */
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[0], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[1], expected_f, 0.001f);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values correctly handles room temperature values
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Room_Temperature)
{
   /* Setup - Raw value ~228 typically corresponds to ~25°C */
   const uint32_t room_temp_raw = 228U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = room_temp_raw;
   mock_PVT0_STAT1 = room_temp_raw * CTRL_PVT0_ACC_LEN; /* Accumulated = inst * acc_len */
   mock_PVT1_STAT0 = room_temp_raw;
   mock_PVT1_STAT1 = room_temp_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Celsius temperatures should be computed correctly */
   float32 expected_c = ComputeExpectedCelsius((float32)room_temp_raw);
   float32 expected_f = CelsiusToFahrenheit(expected_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_c, 0.001f);

   /* Verify - Fahrenheit conversion */
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[0], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[1], expected_f, 0.001f);

   /* Verify - Temperature in reasonable room temperature range (15°C to 35°C) */
   EXPECT_GT(therm_results.immediate_temp_c.temperature[0], 15.0f);
   EXPECT_LT(therm_results.immediate_temp_c.temperature[0], 35.0f);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values handles different PVT0 and PVT1 values
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Different_PVT_Values)
{
   /* Setup - Different raw values for PVT0 and PVT1 */
   const uint32_t pvt0_inst_raw = 200U;
   const uint32_t pvt1_inst_raw = 300U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = pvt0_inst_raw;
   mock_PVT0_STAT1 = pvt0_inst_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = pvt1_inst_raw;
   mock_PVT1_STAT1 = pvt1_inst_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - PVT0 and PVT1 should have different temperature values */
   float32 expected_pvt0_c = ComputeExpectedCelsius((float32)pvt0_inst_raw);
   float32 expected_pvt1_c = ComputeExpectedCelsius((float32)pvt1_inst_raw);
   float32 expected_pvt0_f = CelsiusToFahrenheit(expected_pvt0_c);
   float32 expected_pvt1_f = CelsiusToFahrenheit(expected_pvt1_c);

   /* Verify immediate temperatures */
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_pvt0_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_pvt1_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_pvt0_f, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], expected_pvt1_f, 0.001f);

   /* Verify average temperatures */
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_pvt0_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_pvt1_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[0], expected_pvt0_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[1], expected_pvt1_f, 0.001f);

   /* Verify PVT1 temperature is higher than PVT0 (higher raw value = higher temp) */
   EXPECT_GT(therm_results.immediate_temp_c.temperature[1], therm_results.immediate_temp_c.temperature[0]);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values handles different instantaneous and average values
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Different_Inst_And_Avg)
{
   /* Setup - Different instantaneous and average values */
   const uint32_t inst_raw = 250U;
   const uint32_t avg_raw  = 220U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = inst_raw;
   mock_PVT0_STAT1 = avg_raw * CTRL_PVT0_ACC_LEN; /* Set accumulated so average = avg_raw */
   mock_PVT1_STAT0 = inst_raw;
   mock_PVT1_STAT1 = avg_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Instantaneous and average should be different */
   float32 expected_inst_c = ComputeExpectedCelsius((float32)inst_raw);
   float32 expected_avg_c  = ComputeExpectedCelsius((float32)avg_raw);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_inst_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_avg_c, 0.001f);

   /* Instantaneous should be higher than average in this case */
   EXPECT_GT(therm_results.immediate_temp_c.temperature[0], therm_results.average_temp_c.temperature[0]);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values handles maximum raw values
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Max_Raw_Values)
{
   /* Setup - Maximum 10-bit raw values */
   const uint32_t max_raw = 0x3FFU; /* 1023 */
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = max_raw;
   mock_PVT0_STAT1 = max_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = max_raw;
   mock_PVT1_STAT1 = max_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Values are computed correctly for max raw */
   float32 expected_c = ComputeExpectedCelsius((float32)max_raw);
   float32 expected_f = CelsiusToFahrenheit(expected_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_f, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], expected_f, 0.001f);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values correctly uses VStdMemCpy to copy results
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Copies_To_Output)
{
   /* Setup */
   const uint32_t test_raw = 350U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0xAA, sizeof(therm_results)); /* Pre-fill with pattern */

   mock_PVT0_STAT0 = test_raw;
   mock_PVT0_STAT1 = test_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = test_raw;
   mock_PVT1_STAT1 = test_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Output should be completely overwritten with new values */
   float32 expected_c = ComputeExpectedCelsius((float32)test_raw);

   /* All values should match expected, not contain 0xAA pattern */
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_c, 0.001f);
}

/**
 * @brief Test that Update_Thermal_Monitor_Values maintains static state across calls
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Static_State_Persistence)
{
   /* Setup - First call with specific raw values */
   const uint32_t first_raw = 200U;
   DT_Thermal_mon_mes_results_T therm_results_1;
   DT_Thermal_mon_mes_results_T therm_results_2;
   memset(&therm_results_1, 0, sizeof(therm_results_1));
   memset(&therm_results_2, 0, sizeof(therm_results_2));

   mock_PVT0_STAT0 = first_raw;
   mock_PVT0_STAT1 = first_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = first_raw;
   mock_PVT1_STAT1 = first_raw * CTRL_PVT1_ACC_LEN;

   /* Execute first call */
   Update_Thermal_Monitor_Values(&therm_results_1);

   /* Setup - Second call with different raw values */
   const uint32_t second_raw = 400U;
   mock_PVT0_STAT0           = second_raw;
   mock_PVT0_STAT1           = second_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0           = second_raw;
   mock_PVT1_STAT1           = second_raw * CTRL_PVT1_ACC_LEN;

   /* Execute second call */
   Update_Thermal_Monitor_Values(&therm_results_2);

   /* Verify - Each call should return values based on current register state */
   float32 expected_first_c  = ComputeExpectedCelsius((float32)first_raw);
   float32 expected_second_c = ComputeExpectedCelsius((float32)second_raw);

   EXPECT_NEAR(therm_results_1.immediate_temp_c.temperature[0], expected_first_c, 0.001f);
   EXPECT_NEAR(therm_results_2.immediate_temp_c.temperature[0], expected_second_c, 0.001f);

   /* Second values should be higher (higher raw = higher temp) */
   EXPECT_GT(therm_results_2.immediate_temp_c.temperature[0], therm_results_1.immediate_temp_c.temperature[0]);
}

/**
 * @brief Test Update_Thermal_Monitor_Values with cold temperature scenario
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Cold_Temperature)
{
   /* Setup - Low raw value corresponding to cold temperature */
   const uint32_t cold_raw = 100U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = cold_raw;
   mock_PVT0_STAT1 = cold_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = cold_raw;
   mock_PVT1_STAT1 = cold_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - All temperature values are computed */
   float32 expected_c = ComputeExpectedCelsius((float32)cold_raw);
   float32 expected_f = CelsiusToFahrenheit(expected_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_f, 0.001f);

   /* Cold temperature should be below room temperature (25°C) */
   EXPECT_LT(therm_results.immediate_temp_c.temperature[0], 25.0f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values with hot temperature scenario
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Hot_Temperature)
{
   /* Setup - High raw value corresponding to hot temperature */
   const uint32_t hot_raw = 450U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = hot_raw;
   mock_PVT0_STAT1 = hot_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = hot_raw;
   mock_PVT1_STAT1 = hot_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - All temperature values are computed */
   float32 expected_c = ComputeExpectedCelsius((float32)hot_raw);
   float32 expected_f = CelsiusToFahrenheit(expected_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_f, 0.001f);

   /* Hot temperature should be above room temperature (25°C) */
   EXPECT_GT(therm_results.immediate_temp_c.temperature[0], 25.0f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values verifies Fahrenheit conversion is correct
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Fahrenheit_Conversion_Accuracy)
{
   /* Setup - Use known value where we can verify C to F conversion */
   const uint32_t test_raw = 228U; /* ~25°C */
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = test_raw;
   mock_PVT0_STAT1 = test_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = test_raw;
   mock_PVT1_STAT1 = test_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Fahrenheit should be (C * 9/5) + 32 */
   float32 celsius_val    = therm_results.immediate_temp_c.temperature[0];
   float32 expected_f     = CelsiusToFahrenheit(celsius_val);
   float32 fahrenheit_val = therm_results.immediate_temp_f.temperature[0];

   EXPECT_NEAR(fahrenheit_val, expected_f, 0.001f);

   /* Verify all Fahrenheit values follow the same conversion */
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], CelsiusToFahrenheit(therm_results.immediate_temp_c.temperature[1]),
               0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[0], CelsiusToFahrenheit(therm_results.average_temp_c.temperature[0]),
               0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[1], CelsiusToFahrenheit(therm_results.average_temp_c.temperature[1]),
               0.001f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values iterates through both PVT sites
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Iterates_All_PVT_Sites)
{
   /* Setup - Unique values for PVT0 and PVT1 to verify loop iteration */
   const uint32_t pvt0_raw = 180U;
   const uint32_t pvt1_raw = 320U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = pvt0_raw;
   mock_PVT0_STAT1 = pvt0_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = pvt1_raw;
   mock_PVT1_STAT1 = pvt1_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Index 0 (PVT0) and Index 1 (PVT1) should have different values */
   EXPECT_NE(therm_results.immediate_temp_c.temperature[0], therm_results.immediate_temp_c.temperature[1]);
   EXPECT_NE(therm_results.average_temp_c.temperature[0], therm_results.average_temp_c.temperature[1]);

   /* Verify correct values at each index */
   float32 expected_pvt0_c = ComputeExpectedCelsius((float32)pvt0_raw);
   float32 expected_pvt1_c = ComputeExpectedCelsius((float32)pvt1_raw);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_pvt0_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_pvt1_c, 0.001f);
}
/*===========================================================================*
 * Unit Tests for Check_PVT_Temperature_Deviation
 *===========================================================================*/

/**
 * @brief Test fixture for PVT Temperature Deviation tests
 * Extends base fixture to reset the consecutive counter before each test
 */
class PVTDeviationTest : public ThermalMonitorTest
{
 protected:
   void SetUp() override
   {
      ThermalMonitorTest::SetUp();
      /* Reset the static consecutive counter before each test */
      PVT_Deviation_Consecutive_Count = 0U;
      /* Reset the FailSafe_Log_ResetReason fake */
      RESET_FAKE(FailSafe_Log_ResetReason);
   }

   void TearDown() override
   {
      ThermalMonitorTest::TearDown();
      /* Reset the static consecutive counter after each test */
      PVT_Deviation_Consecutive_Count = 0U;
   }

   /**
    * @brief Helper function to create PVT temperature struct with specified values
    */
   PVT_Temp_Celsius_T CreatePVTTemp(float32 pvt0_avg, float32 pvt1_avg)
   {
      PVT_Temp_Celsius_T temp;
      temp.PVT0_Inst_Temp_Value_C = pvt0_avg;
      temp.PVT1_Inst_Temp_Value_C = pvt1_avg;
      temp.PVT0_Avg_Temp_Value_C  = pvt0_avg;
      temp.PVT1_Avg_Temp_Value_C  = pvt1_avg;
      return temp;
   }

   /**
    * @brief Helper function to calculate absolute temperature difference
    */
   float32 CalculateAbsoluteDifference(float32 pvt0, float32 pvt1)
   {
      return (pvt0 >= pvt1) ? (pvt0 - pvt1) : (pvt1 - pvt0);
   }
};

/**
 * @brief Test that no deviation is detected when PVT0 and PVT1 are equal
 */
TEST_F(PVTDeviationTest, NoDeviation_WhenTemperaturesAreEqual)
{
   /* Setup - Equal temperatures (0 degree C difference) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(50.0f, 50.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter should remain at 0, no reset called */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that no deviation is detected when deviation is below 10 degree C
 */
TEST_F(PVTDeviationTest, NoDeviation_WhenDeviationBelow10DegC)
{
   /* Setup - 9 degree C difference (below threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(54.5f, 45.5f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter should remain at 0, no reset called */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that deviation is not detected when exactly at 10 degree C threshold
 */
TEST_F(PVTDeviationTest, NoDeviation_WhenExactlyAt10DegC)
{
   /* Setup - Exactly 10 degree C difference (at threshold, not exceeded) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(55.0f, 45.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter should remain at 0 (threshold is >, not >=), no reset called */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that deviation is detected when above 10 degree C threshold
 */
TEST_F(PVTDeviationTest, DeviationDetected_WhenAbove10DegC)
{
   /* Setup - 11 degree C difference (above threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(55.5f, 44.5f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter should increment to 1, no reset yet (need 3 consecutive) */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that deviation is detected when PVT1 is higher than PVT0
 */
TEST_F(PVTDeviationTest, DeviationDetected_WhenPVT1HigherThanPVT0)
{
   /* Setup - PVT1 higher than PVT0 with >10 degree C deviation */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(44.0f, 55.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter should increment (deviation is symmetric), no reset yet */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test counter increments on consecutive deviation cycles
 */
TEST_F(PVTDeviationTest, CounterIncrements_OnConsecutiveDeviations)
{
   /* Setup - 20 degree C difference */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(60.0f, 40.0f);

   /* Execute - First cycle */
   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   /* Execute - Second cycle */
   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 2U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test counter resets when deviation returns to acceptable range
 */
TEST_F(PVTDeviationTest, CounterResets_WhenDeviationReturnsToNormal)
{
   /* Setup - First create deviation (>10 degree C) */
   PVT_Temp_Celsius_T pvt_temp_high = CreatePVTTemp(55.0f, 44.0f);

   /* Execute - Two cycles with deviation */
   Check_PVT_Temperature_Deviation(&pvt_temp_high);
   Check_PVT_Temperature_Deviation(&pvt_temp_high);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 2U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   /* Setup - Normal temperatures (0 degree C difference) */
   PVT_Temp_Celsius_T pvt_temp_normal = CreatePVTTemp(50.0f, 50.0f);

   /* Execute - One cycle with normal readings */
   Check_PVT_Temperature_Deviation(&pvt_temp_normal);

   /* Verify - Counter should reset to 0, no reset called */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that 3 consecutive deviations triggers FailSafe_Log_ResetReason
 */
TEST_F(PVTDeviationTest, ThreeConsecutiveDeviations_TriggersReset)
{
   /* Setup - Large deviation (>10 degree C) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(60.0f, 40.0f);

   /* Execute - Three consecutive cycles with deviation */
   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 2U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 3U);

   /* Verify - FailSafe_Log_ResetReason should be called with correct parameter */
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, PVT_TEMPERATURE_DEVIATION_RESET);
}

/**
 * @brief Test counter does not overflow past 255
 */
TEST_F(PVTDeviationTest, CounterSaturatesAt255)
{
   /* Setup - Set counter near max */
   PVT_Deviation_Consecutive_Count = 254U;
   PVT_Temp_Celsius_T pvt_temp     = CreatePVTTemp(60.0f, 40.0f);

   /* Execute - Should increment to 255 */
   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 255U);

   /* Execute - Should stay at 255 (saturated) */
   Check_PVT_Temperature_Deviation(&pvt_temp);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 255U);
}

/**
 * @brief Test with high temperature values (above 100 degree C)
 */
TEST_F(PVTDeviationTest, HandlesHighTemperatureValues)
{
   /* Setup - High temperatures with >10 degree C deviation */
   /* PVT0=120, PVT1=100 -> diff=20 degree C */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(120.0f, 100.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test with negative temperature values
 */
TEST_F(PVTDeviationTest, HandlesNegativeTemperatureValues)
{
   /* Setup - Negative temperatures with 10 degree C deviation */
   /* PVT0=-20, PVT1=-30 -> diff=10 degree C (exactly at threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(-20.0f, -30.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - 10 degree C exactly should NOT trigger (threshold is >) */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test with negative temperature values above threshold
 */
TEST_F(PVTDeviationTest, HandlesNegativeTemperatureValues_AboveThreshold)
{
   /* Setup - Negative temperatures with >10 degree C deviation */
   /* PVT0=-20, PVT1=-31 -> diff=11 degree C */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(-20.0f, -31.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - 11 degree C should trigger deviation detection */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test with mixed positive and negative temperature values
 */
TEST_F(PVTDeviationTest, HandlesMixedPositiveNegativeTemperatures)
{
   /* Setup - One positive, one negative (11 degree C difference) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(5.5f, -5.5f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - 11 degree C deviation should be detected */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test boundary case with small temperature values below threshold
 */
TEST_F(PVTDeviationTest, HandlesSmallTemperatureValues_BelowThreshold)
{
   /* Setup - Small temperatures near zero with 8 degree C difference */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(4.0f, -4.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - 8 degree C is below 10 degree C threshold */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test boundary case with small temperature values above threshold
 */
TEST_F(PVTDeviationTest, HandlesSmallTemperatureValues_AboveThreshold)
{
   /* Setup - Small temperatures with 10.5 degree C difference */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(5.25f, -5.25f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - 10.5 degree C should trigger deviation detection */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test that interrupting consecutive deviations resets counter
 */
TEST_F(PVTDeviationTest, InterruptedDeviation_ResetsCounter)
{
   /* Setup - deviation must be > 10 degree C (not >=) */
   PVT_Temp_Celsius_T pvt_deviation = CreatePVTTemp(56.0f, 45.0f); /* 11 degree C diff */
   PVT_Temp_Celsius_T pvt_normal    = CreatePVTTemp(50.0f, 50.0f); /* 0 degree C diff */

   /* Execute - 2 cycles deviation, then normal, then deviation again */
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 2U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   Check_PVT_Temperature_Deviation(&pvt_normal);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);

   Check_PVT_Temperature_Deviation(&pvt_deviation);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test deviation calculation accuracy with known values
 */
TEST_F(PVTDeviationTest, DeviationCalculation_IsAccurate)
{
   /* Setup - Test case: 64.2 and 53.3 (10.9 degree C difference) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(64.2f, 53.3f);

   float32 expected_diff = CalculateAbsoluteDifference(64.2f, 53.3f);
   EXPECT_GT(expected_diff, 5.0f); /* Sanity check: 10.9 > 5 */

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Should detect deviation */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test edge case: just above 10 degree C threshold
 */
TEST_F(PVTDeviationTest, JustAboveThreshold_TriggersDeviation)
{
   /* Setup - 10.1 degree C difference (just above 10 degree C threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(55.05f, 44.95f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Should detect deviation */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test edge case: just below 10 degree C threshold
 */
TEST_F(PVTDeviationTest, JustBelowThreshold_NoDeviation)
{
   /* Setup - 9.9 degree C difference (just below 10 degree C threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(54.95f, 45.05f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Should NOT detect deviation */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test full scenario: 3 consecutive deviations followed by normal
 */
TEST_F(PVTDeviationTest, FullScenario_ThreeDeviationsThenNormal)
{
   PVT_Temp_Celsius_T pvt_deviation = CreatePVTTemp(60.0f, 40.0f); /* 20 degree C diff */
   PVT_Temp_Celsius_T pvt_normal    = CreatePVTTemp(50.0f, 50.0f);

   /* Execute 3 consecutive deviations */
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 3U);

   /* Verify - FailSafe_Log_ResetReason should have been called */
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, PVT_TEMPERATURE_DEVIATION_RESET);

   /* Reset fake for next verification */
   RESET_FAKE(FailSafe_Log_ResetReason);

   /* Execute normal reading */
   Check_PVT_Temperature_Deviation(&pvt_normal);

   /* Verify - Counter should reset */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
}

/**
 * @brief Test that FailSafe_Log_ResetReason is called repeatedly after threshold
 */
TEST_F(PVTDeviationTest, ResetCalledOnEveryDeviationAfterThreshold)
{
   PVT_Temp_Celsius_T pvt_deviation = CreatePVTTemp(60.0f, 40.0f);

   /* Execute 4 consecutive deviations */
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   Check_PVT_Temperature_Deviation(&pvt_deviation);
   Check_PVT_Temperature_Deviation(&pvt_deviation); /* First reset call */
   Check_PVT_Temperature_Deviation(&pvt_deviation); /* Second reset call */

   /* Verify - FailSafe_Log_ResetReason should have been called twice */
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 2U);
}

/**
 * @brief Test temperature difference calculation when PVT0 > PVT1 (if branch)
 */
TEST_F(PVTDeviationTest, TemperatureDifference_PVT0GreaterThanPVT1)
{
   /* Setup - PVT0 = 70, PVT1 = 50, diff = 20 degree C (>10 threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(70.0f, 50.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Deviation should be detected via the if branch (pvt0 >= pvt1) */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test temperature difference calculation when PVT1 > PVT0 (else branch)
 */
TEST_F(PVTDeviationTest, TemperatureDifference_PVT1GreaterThanPVT0)
{
   /* Setup - PVT0 = 50, PVT1 = 70, diff = 20 degree C (>10 threshold) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(50.0f, 70.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Deviation should be detected via the else branch (pvt1 > pvt0) */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test temperature difference when temperatures are exactly equal
 */
TEST_F(PVTDeviationTest, TemperatureDifference_ExactlyEqual)
{
   /* Setup - PVT0 = PVT1 = 50, diff = 0 (uses if branch since pvt0 >= pvt1) */
   PVT_Temp_Celsius_T pvt_temp = CreatePVTTemp(50.0f, 50.0f);

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - No deviation when equal */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 0U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

/**
 * @brief Test counter saturation at maximum uint8 value (255)
 */
TEST_F(PVTDeviationTest, CounterSaturation_AtMax255_NoOverflow)
{
   /* Setup - Set counter to maximum value */
   PVT_Deviation_Consecutive_Count = 255U;
   PVT_Temp_Celsius_T pvt_temp     = CreatePVTTemp(70.0f, 50.0f);

   /* Execute - Counter should not overflow past 255 */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Counter stays at 255 */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 255U);
   /* FailSafe should still be called since 255 >= 3 */
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
}

/**
 * @brief Test that deviation detection uses average temperature values
 */
TEST_F(PVTDeviationTest, UsesAverageTemperatureValues)
{
   /* Setup - Create struct with different inst and avg values
    * Deviation check uses PVT0_Avg_Temp_Value_C and PVT1_Avg_Temp_Value_C */
   PVT_Temp_Celsius_T pvt_temp;
   pvt_temp.PVT0_Inst_Temp_Value_C = 50.0f; /* Inst - no deviation */
   pvt_temp.PVT1_Inst_Temp_Value_C = 50.0f; /* Inst - no deviation */
   pvt_temp.PVT0_Avg_Temp_Value_C  = 70.0f; /* Avg - 20 degree C deviation */
   pvt_temp.PVT1_Avg_Temp_Value_C  = 50.0f; /* Avg */

   /* Execute */
   Check_PVT_Temperature_Deviation(&pvt_temp);

   /* Verify - Should detect deviation based on average values */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 1U);
}

/*===========================================================================*
 * Additional coverage tests for Update_Thermal_Monitor_Values
 *===========================================================================*/

/**
 * @brief Test Update_Thermal_Monitor_Values loop iterates through both PVT0 (index 0) and PVT1 (index 1)
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Loop_BothIndices)
{
   /* Setup - Different values for PVT0 and PVT1 to verify both loop iterations */
   const uint32_t pvt0_raw = 200U;
   const uint32_t pvt1_raw = 400U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = pvt0_raw;
   mock_PVT0_STAT1 = pvt0_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = pvt1_raw;
   mock_PVT1_STAT1 = pvt1_raw * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Both index 0 (PVT0) and index 1 (PVT1) are populated correctly */
   float32 expected_pvt0_c = ComputeExpectedCelsius((float32)pvt0_raw);
   float32 expected_pvt1_c = ComputeExpectedCelsius((float32)pvt1_raw);

   /* Verify index 0 (PVT0 branch) */
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_pvt0_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_pvt0_c, 0.001f);

   /* Verify index 1 (PVT1 branch - else branch) */
   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_pvt1_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_pvt1_c, 0.001f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values with PVT0 index explicitly (site_idx == PVT0 branch)
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_PVT0_Branch)
{
   /* Setup */
   const uint32_t pvt0_inst = 250U;
   const uint32_t pvt0_avg  = 240U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = pvt0_inst;
   mock_PVT0_STAT1 = pvt0_avg * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = 0U;
   mock_PVT1_STAT1 = 0U;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - PVT0 values at index 0 */
   float32 expected_inst_c = ComputeExpectedCelsius((float32)pvt0_inst);
   float32 expected_avg_c  = ComputeExpectedCelsius((float32)pvt0_avg);
   float32 expected_inst_f = CelsiusToFahrenheit(expected_inst_c);
   float32 expected_avg_f  = CelsiusToFahrenheit(expected_avg_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[0], expected_inst_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[0], expected_inst_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[0], expected_avg_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[0], expected_avg_f, 0.001f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values with PVT1 index explicitly (else branch)
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_PVT1_Branch)
{
   /* Setup */
   const uint32_t pvt1_inst = 300U;
   const uint32_t pvt1_avg  = 290U;
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   mock_PVT0_STAT0 = 0U;
   mock_PVT0_STAT1 = 0U;
   mock_PVT1_STAT0 = pvt1_inst;
   mock_PVT1_STAT1 = pvt1_avg * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - PVT1 values at index 1 */
   float32 expected_inst_c = ComputeExpectedCelsius((float32)pvt1_inst);
   float32 expected_avg_c  = ComputeExpectedCelsius((float32)pvt1_avg);
   float32 expected_inst_f = CelsiusToFahrenheit(expected_inst_c);
   float32 expected_avg_f  = CelsiusToFahrenheit(expected_avg_c);

   EXPECT_NEAR(therm_results.immediate_temp_c.temperature[1], expected_inst_c, 0.001f);
   EXPECT_NEAR(therm_results.immediate_temp_f.temperature[1], expected_inst_f, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_c.temperature[1], expected_avg_c, 0.001f);
   EXPECT_NEAR(therm_results.average_temp_f.temperature[1], expected_avg_f, 0.001f);
}

/**
 * @brief Test Update_Thermal_Monitor_Values calls Check_PVT_Temperature_Deviation
 */
TEST_F(ThermalMonitorTest, Update_Thermal_Monitor_Values_Calls_DeviationCheck)
{
   /* Setup - Create deviation condition (>10 degree C difference) */
   const uint32_t pvt0_raw = 450U; /* Higher temperature */
   const uint32_t pvt1_raw = 150U; /* Lower temperature */
   DT_Thermal_mon_mes_results_T therm_results;
   memset(&therm_results, 0, sizeof(therm_results));

   /* Reset deviation counter */
   PVT_Deviation_Consecutive_Count = 0U;
   RESET_FAKE(FailSafe_Log_ResetReason);

   mock_PVT0_STAT0 = pvt0_raw;
   mock_PVT0_STAT1 = pvt0_raw * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = pvt1_raw;
   mock_PVT1_STAT1 = pvt1_raw * CTRL_PVT1_ACC_LEN;

   /* Execute 3 times to trigger reset */
   Update_Thermal_Monitor_Values(&therm_results);
   Update_Thermal_Monitor_Values(&therm_results);
   Update_Thermal_Monitor_Values(&therm_results);

   /* Verify - Check_PVT_Temperature_Deviation was called and triggered reset */
   EXPECT_EQ(PVT_Deviation_Consecutive_Count, 3U);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
}

/**
 * @brief Test Read_PVT_Temperature_Values computes average from accumulated values
 */
TEST_F(ThermalMonitorTest, Read_PVT_Temperature_Values_Computes_Average)
{
   /* Setup - Accumulated value = raw * ACC_LEN, average should be raw */
   const uint32_t raw_value = 300U;
   PVT_Temp_Celsius_T pvt_temp_c;

   mock_PVT0_STAT0 = raw_value;
   mock_PVT0_STAT1 = raw_value * CTRL_PVT0_ACC_LEN;
   mock_PVT1_STAT0 = raw_value;
   mock_PVT1_STAT1 = raw_value * CTRL_PVT1_ACC_LEN;

   /* Execute */
   Read_PVT_Temperature_Values(&pvt_temp_c);

   /* Verify - Instantaneous and average should be same when acc = inst * ACC_LEN */
   EXPECT_NEAR(pvt_temp_c.PVT0_Inst_Temp_Value_C, pvt_temp_c.PVT0_Avg_Temp_Value_C, 0.001f);
   EXPECT_NEAR(pvt_temp_c.PVT1_Inst_Temp_Value_C, pvt_temp_c.PVT1_Avg_Temp_Value_C, 0.001f);
}

/**
 * @brief Test PVT_Convert_To_Celsius loop iterates through all 4 indices
 */
TEST_F(ThermalMonitorTest, PVT_Convert_To_Celsius_Loop_AllIndices)
{
   /* Setup - Different values for each channel to verify loop */
   PVT_Temperatures_T raw_temps = {
      100U, /* PVT0 Instant - index 0 */
      200U, /* PVT1 Instant - index 1 */
      300U, /* PVT0 Average - index 2 */
      400U  /* PVT1 Average - index 3 */
   };
   PVT_Temp_Celsius_T celsius_temps = {0.0f, 0.0f, 0.0f, 0.0f};

   /* Execute */
   PVT_Convert_To_Celsius(&raw_temps, &celsius_temps);

   /* Verify - Each index has unique computed value */
   float32 expected_0 = ComputeExpectedCelsius(100.0f);
   float32 expected_1 = ComputeExpectedCelsius(200.0f);
   float32 expected_2 = ComputeExpectedCelsius(300.0f);
   float32 expected_3 = ComputeExpectedCelsius(400.0f);

   EXPECT_NEAR(celsius_temps.PVT0_Inst_Temp_Value_C, expected_0, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Inst_Temp_Value_C, expected_1, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT0_Avg_Temp_Value_C, expected_2, 0.001f);
   EXPECT_NEAR(celsius_temps.PVT1_Avg_Temp_Value_C, expected_3, 0.001f);
}
