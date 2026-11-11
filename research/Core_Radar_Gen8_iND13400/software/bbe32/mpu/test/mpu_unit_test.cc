/*===========================================================================*/
/**
 * @file mpu_unit_test.cc
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
 * Unit test suite for mpu.c (DSP Memory Protection Unit)
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - MPU: Memory Protection Unit
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - mpu Unit Test Design
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
#include "mpu_fake.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "mpu.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class MPU_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(xthal_read_map);
      RESET_FAKE(xthal_write_map);
      RESET_FAKE(xthal_check_map);
      MPU_Entry_Count = 0U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief Read_Mpu_Configuration: When xthal_read_map succeeds, MPU_Entry_Count
 *        should be incremented for each entry.
 */
TEST_F(MPU_UnitTestSuite, ReadMpuConfiguration_ReadMapSuccess_CountsEntries)
{
   xthal_read_map_fake.return_val = XTHAL_SUCCESS;

   Read_Mpu_Configuration();

   EXPECT_EQ(MPU_Entry_Count, (uint32_t)XCHAL_MPU_ENTRIES) << "MPU_Entry_Count should equal XCHAL_MPU_ENTRIES on successful read";
}

/**
 * @brief Read_Mpu_Configuration: When xthal_read_map fails, MPU_Entry_Count
 *        should remain at 0.
 */
TEST_F(MPU_UnitTestSuite, ReadMpuConfiguration_ReadMapFails_CounterNotIncremented)
{
   xthal_read_map_fake.return_val = XTHAL_INVALID;

   Read_Mpu_Configuration();

   EXPECT_EQ(MPU_Entry_Count, 0U) << "MPU_Entry_Count should remain 0 when xthal_read_map fails";
}

/**
 * @brief Mpu_Initialize: When xthal_check_map succeeds and xthal_read_map succeeds,
 *        function should return true.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_AllCallsSucceed_ReturnsTrue)
{
   xthal_check_map_fake.return_val = XTHAL_SUCCESS;
   xthal_read_map_fake.return_val  = XTHAL_SUCCESS;

   bool result = Mpu_Initialize();

   EXPECT_TRUE(result) << "Mpu_Initialize should return true when all HAL calls succeed";
}

/**
 * @brief Mpu_Initialize: When xthal_check_map fails, function should return false.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_CheckMapFails_ReturnsFalse)
{
   xthal_check_map_fake.return_val = XTHAL_INVALID;

   bool result = Mpu_Initialize();

   EXPECT_FALSE(result) << "Mpu_Initialize should return false when xthal_check_map fails";
}

/**
 * @brief Mpu_Initialize: xthal_write_map is called after successful check.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_CheckMapSucceeds_WritesMap)
{
   xthal_check_map_fake.return_val = XTHAL_SUCCESS;
   xthal_read_map_fake.return_val  = XTHAL_SUCCESS;

   Mpu_Initialize();

   EXPECT_EQ(xthal_write_map_fake.call_count, 1U) << "xthal_write_map should be called once after a successful check";
}

/**
 * @brief Mpu_Initialize: xthal_check_map is called a second time after a successful
 *        xthal_read_map (readback verification path).
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_ReadMapSucceeds_CheckMapCalledTwice)
{
   xthal_check_map_fake.return_val = XTHAL_SUCCESS;
   xthal_read_map_fake.return_val  = XTHAL_SUCCESS;

   Mpu_Initialize();

   EXPECT_EQ(xthal_check_map_fake.call_count, 2U)
      << "xthal_check_map should be called twice: once before write and once after successful read-back";
}

/**
 * @brief Mpu_Initialize: When xthal_read_map succeeds but the second xthal_check_map
 *        (readback verification) fails, the return value is still true because
 *        the second check result is not used in this path.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_ReadMapSucceeds_SecondCheckReadbackIgnored_ReturnsTrue)
{
   int32_t check_map_seq[] = {XTHAL_SUCCESS, XTHAL_INVALID};
   SET_RETURN_SEQ(xthal_check_map, check_map_seq, 2);
   xthal_read_map_fake.return_val = XTHAL_SUCCESS;

   bool result = Mpu_Initialize();

   EXPECT_TRUE(result) << "Mpu_Initialize should return true even when the second xthal_check_map fails "
                          "because its result is not used in the read_map-success path";
}

/**
 * @brief Mpu_Initialize: When xthal_read_map fails and the subsequent readback
 *        xthal_check_map also fails, function should return false.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_ReadMapFails_ReadbackCheckFails_ReturnsFalse)
{
   int32_t check_map_seq[] = {XTHAL_SUCCESS, XTHAL_INVALID};
   SET_RETURN_SEQ(xthal_check_map, check_map_seq, 2);
   xthal_read_map_fake.return_val = XTHAL_INVALID;

   bool result = Mpu_Initialize();

   EXPECT_FALSE(result) << "Mpu_Initialize should return false when read_map fails and the readback xthal_check_map also fails";
}

/* Custom fake: fills the readback buffer with strictly ascending addresses, returns XTHAL_INVALID */
static int32_t custom_read_map_ascending(struct xthal_MPU_entry *map)
{
   for (uint32_t i = 0U; i < XCHAL_MPU_ENTRIES; i++)
   {
      map[i].as = (uint32_t)(i * 0x1000U);
      map[i].at = 0U;
   }
   return XTHAL_INVALID;
}

/* Custom fake: fills the readback buffer with identical (non-ascending) addresses, returns XTHAL_INVALID */
static int32_t custom_read_map_not_ascending(struct xthal_MPU_entry *map)
{
   for (uint32_t i = 0U; i < XCHAL_MPU_ENTRIES; i++)
   {
      map[i].as = 0U; /* All identical — violates strictly-ascending requirement */
      map[i].at = 0U;
   }
   return XTHAL_INVALID;
}

/**
 * @brief Mpu_Initialize: When xthal_read_map fails, the readback xthal_check_map
 *        succeeds, and all readback addresses are in strictly ascending order,
 *        function should return true.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_ReadMapFails_ReadbackCheckSucceeds_AddressesAscending_ReturnsTrue)
{
   xthal_check_map_fake.return_val = XTHAL_SUCCESS;
   xthal_read_map_fake.custom_fake = custom_read_map_ascending;

   bool result = Mpu_Initialize();

   EXPECT_TRUE(result) << "Mpu_Initialize should return true when read_map fails, readback check succeeds, "
                          "and readback addresses are in strictly ascending order";
}

/**
 * @brief Mpu_Initialize: When xthal_read_map fails, the readback xthal_check_map
 *        succeeds, but readback addresses are NOT in strictly ascending order,
 *        function should return false.
 */
TEST_F(MPU_UnitTestSuite, MpuInitialize_ReadMapFails_ReadbackCheckSucceeds_AddressesNotAscending_ReturnsFalse)
{
   xthal_check_map_fake.return_val = XTHAL_SUCCESS;
   xthal_read_map_fake.custom_fake = custom_read_map_not_ascending;

   bool result = Mpu_Initialize();

   EXPECT_FALSE(result) << "Mpu_Initialize should return false when read_map fails, readback check succeeds, "
                           "but readback addresses are not in strictly ascending order";
}
