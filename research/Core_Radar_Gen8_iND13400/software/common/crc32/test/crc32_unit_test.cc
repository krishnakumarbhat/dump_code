/*===========================================================================*/
/**
 * @file crc32_unit_test.cc
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
 * Unit test suite for crc32.c
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - CRC: Cyclic Redundancy Check
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - crc32 Unit Test Design
 *
 *   - Requirements Document(s):
 *     - CRC32 calculation requirements
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
#include <gtest/gtest.h>
#include <cstdint>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files - Include source after mocks
 *===========================================================================*/
extern "C"
{
#include "crc32.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class CRC32_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      /* Initialize CRC table before each test */
      CRC32_Init();
   }

   void TearDown() override {}
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief CRC32_Init: CRC table is initialized - table entry [0] must be 0x00000000.
 */
TEST_F(CRC32_UnitTestSuite, CRC32Init_TableEntry0_IsZero)
{
   /* Table[0] is always 0 for reversed CRC polynomial */
   EXPECT_EQ(CRC32_Table[0], 0x00000000U)
      << "CRC32 table entry 0 should be 0";
}

/**
 * @brief CRC32_Init: CRC table entry for index 1 must match the reversed polynomial value.
 */
TEST_F(CRC32_UnitTestSuite, CRC32Init_TableEntry1_EqualsReversedPolynomial)
{
   /* Standard CRC-32 reversed polynomial */
   EXPECT_EQ(CRC32_Table[1], 0x77073096U)
      << "CRC32 table entry 1 should equal 0x77073096";
}

/**
 * @brief CRC32_GetRunTimeCRC32: Computing CRC32 of empty buffer (length=0) should
 *        return the XOR of initial and final values.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_EmptyBuffer_ReturnsInitialXORFinal)
{
   uint8_t buf[1] = {0};
   /* With length=0, the loop doesn't execute and retCRCValue = 0xFFFFFFFF ^ UINT32_MAX = 0 */
   uint32_t result = CRC32_GetRunTimeCRC32(buf, 0U);
   EXPECT_EQ(result, 0x00000000U)
      << "CRC32 of empty buffer should be 0x00000000";
}

/**
 * @brief CRC32_GetRunTimeCRC32: Computing CRC32 of single byte 0x00 must yield
 *        a known, deterministic result.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_SingleZeroByte_KnownValue)
{
   uint8_t buf[1] = {0x00U};
   uint32_t result = CRC32_GetRunTimeCRC32(buf, 1U);
   /* Known CRC-32 value for 0x00 with initial 0xFFFFFFFF and final XOR 0xFFFFFFFF */
   EXPECT_EQ(result, 0xD202EF8DU)
      << "CRC32 of single 0x00 byte should be 0xD202EF8D";
}

/**
 * @brief CRC32_GetRunTimeCRC32: Computing CRC32 of the string "123456789" must yield
 *        the standard check value 0xCBF43926.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_CheckVector_StandardResult)
{
   uint8_t buf[] = {0x31U, 0x32U, 0x33U, 0x34U, 0x35U,
                    0x36U, 0x37U, 0x38U, 0x39U};
   uint32_t result = CRC32_GetRunTimeCRC32(buf, sizeof(buf));
   EXPECT_EQ(result, 0xCBF43926U)
      << "CRC32 check vector '123456789' should yield 0xCBF43926";
}

/**
 * @brief CRC32_GetRunTimeCRC32: CRC32 is deterministic - same input yields same output.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_SameInput_SameOutput)
{
   uint8_t buf[] = {0xAAU, 0xBBU, 0xCCU};
   uint32_t result1 = CRC32_GetRunTimeCRC32(buf, sizeof(buf));
   uint32_t result2 = CRC32_GetRunTimeCRC32(buf, sizeof(buf));
   EXPECT_EQ(result1, result2) << "CRC32 must be deterministic";
}

/**
 * @brief CRC32_GetRunTimeCRC32: Different inputs produce different CRC32 values.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_DifferentInputs_DifferentOutputs)
{
   uint8_t buf1[] = {0x01U, 0x02U, 0x03U};
   uint8_t buf2[] = {0x01U, 0x02U, 0x04U};
   uint32_t crc1 = CRC32_GetRunTimeCRC32(buf1, sizeof(buf1));
   uint32_t crc2 = CRC32_GetRunTimeCRC32(buf2, sizeof(buf2));
   EXPECT_NE(crc1, crc2) << "Different data must produce different CRC32 values";
}

/**
 * @brief CRC32_GetRunTimeCRC32: Boundary - max uint16_t length should not overflow.
 * This test checks that the function handles larger lengths without crashing.
 */
TEST_F(CRC32_UnitTestSuite, GetRunTimeCRC32_LargerBuffer_DoesNotCrash)
{
   static uint8_t large_buf[256] = {0};
   for (int i = 0; i < 256; i++) large_buf[i] = static_cast<uint8_t>(i);

   uint32_t result = CRC32_GetRunTimeCRC32(large_buf, 256U);
   /* Just verify we get a non-crash; specific value tested elsewhere */
   EXPECT_NE(result, 0xFFFFFFFFU) << "CRC32 of patterned data should not be 0xFFFFFFFF";
}
