/*===========================================================================*/
/**
 * @file fusa_bbe_self_test_unit_test.cc
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
 * Unit test suite for fusa_bbe_self_test.c
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - FuSa: Functional Safety
 *   - BBE:  Baseband Engine
 *   - STL:  Software Test Library
 *   - BIST: Built-In Self Test
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - fusa_bbe_self_test Unit Test Design
 *
 *   - Requirements Document(s):
 *     - FuSa BBE Self Test requirements
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
#include "fusa_bbe_self_test_fake.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
DEFINE_FAKE_VOID_FUNC(BBE_Helpers_Trigger_Watchdog);

DEFINE_FAKE_VALUE_FUNC(int, xtstl_arstall);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_dram_prot, uint32_t *, uint32_t);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_dsp_bbe32_all_noDspOpts, uint32_t);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_er);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_externint, uint32_t *, uint32_t);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_instfetch);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_iram0_l32r);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_loadstore, uint32_t *);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_mpu);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_mpu_entry, uint32_t *);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_regfile_loadstore, uint32_t *);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_sr);
DEFINE_FAKE_VALUE_FUNC(int, xtstl_win_rot);

static uint32_t g_test_buf[16] = {0};

static Memory_Pool_Return_T Mem_Pool_Alloc_Success(Mem_Pool_T *pool, uint32_t size, void **ptr)
{
   (void)pool;
   (void)size;
   *ptr = g_test_buf;
   return MEM_POOL_SUCCESS;
}

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "fusa_bbe_self_test.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class FusaBbeSelfTest_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(xtstl_arstall);
      RESET_FAKE(xtstl_dram_prot);
      RESET_FAKE(xtstl_dsp_bbe32_all_noDspOpts);
      RESET_FAKE(xtstl_er);
      RESET_FAKE(xtstl_externint);
      RESET_FAKE(xtstl_instfetch);
      RESET_FAKE(xtstl_iram0_l32r);
      RESET_FAKE(xtstl_loadstore);
      RESET_FAKE(xtstl_mpu);
      RESET_FAKE(xtstl_mpu_entry);
      RESET_FAKE(xtstl_regfile_loadstore);
      RESET_FAKE(xtstl_sr);
      RESET_FAKE(xtstl_win_rot);
      RESET_FAKE(Mem_Pool_Alloc);
      RESET_FAKE(Timing_Helpers_Get_Timestamp);
      RESET_FAKE(BBE_Helpers_Trigger_Watchdog);

      /* Set default custom fake for Mem_Pool_Alloc */
      Mem_Pool_Alloc_fake.custom_fake = Mem_Pool_Alloc_Success;

      /* Reset global pointers */
      Dram1_Test_Buf_Ptr  = NULL;
      Sysram_Test_Buf_Ptr = NULL;

      /* Default all STL fakes to XTSTL_PASS (source checks != XTSTL_PASS for failure) */
      xtstl_arstall_fake.return_val                 = XTSTL_PASS;
      xtstl_dram_prot_fake.return_val               = XTSTL_PASS;
      xtstl_dsp_bbe32_all_noDspOpts_fake.return_val = XTSTL_PASS;
      xtstl_er_fake.return_val                      = XTSTL_PASS;
      xtstl_externint_fake.return_val               = XTSTL_PASS;
      xtstl_instfetch_fake.return_val               = XTSTL_PASS;
      xtstl_iram0_l32r_fake.return_val              = XTSTL_PASS;
      xtstl_loadstore_fake.return_val               = XTSTL_PASS;
      xtstl_mpu_fake.return_val                     = XTSTL_PASS;
      xtstl_mpu_entry_fake.return_val               = XTSTL_PASS;
      xtstl_regfile_loadstore_fake.return_val       = XTSTL_PASS;
      xtstl_sr_fake.return_val                      = XTSTL_PASS;
      xtstl_win_rot_fake.return_val                 = XTSTL_PASS;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief Fusa_BBE_Check_Buffer: Buffer address in range and aligned, no error bits set.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckBuffer_InRangeAligned_NoError)
{
   uint32_t error_code  = 0;
   uintptr_t buf_addr   = 0x82000100; // 128-byte aligned address (SRAM1)
   uint32_t range_start = 0x82000000;
   uint32_t range_end   = 0x84000000;
   int range_bit        = 2;
   int align_bit        = 3;
   // FUSA_BBE_ALIGNMENT_BYTES is 128, so 0x80000100 is aligned
   Fusa_BBE_Check_Buffer(buf_addr, range_start, range_end, range_bit, align_bit, &error_code);
   EXPECT_EQ(error_code, 0U) << "No error bits should be set for in-range and aligned buffer.";
}

/**
 * @brief Fusa_BBE_Check_buffer: Buffer address out of range, range error bit set.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckBuffer_OutOfRange_RangeError)
{
   uint32_t error_code  = 0;
   uintptr_t buf_addr   = 0x90000000; // Out of range
   uint32_t range_start = 0x82000000;
   uint32_t range_end   = 0x84000000;
   int range_bit        = 2;
   int align_bit        = 3;
   Fusa_BBE_Check_Buffer(buf_addr, range_start, range_end, range_bit, align_bit, &error_code);
   EXPECT_EQ(error_code, (1U << range_bit)) << "Range error bit should be set for out-of-range buffer.";
}

/**
 * @brief Fusa_BBE_Check_buffer: Buffer address misaligned, alignment error bit set.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckBuffer_Misaligned_AlignError)
{
   uint32_t error_code  = 0;
   uintptr_t buf_addr   = 0x82000104; // Misaligned (not multiple of 128)
   uint32_t range_start = 0x82000000;
   uint32_t range_end   = 0x84000000;
   int range_bit        = 2;
   int align_bit        = 3;
   Fusa_BBE_Check_Buffer(buf_addr, range_start, range_end, range_bit, align_bit, &error_code);
   EXPECT_EQ(error_code, (1U << align_bit)) << "Alignment error bit should be set for misaligned buffer.";
}

/**
 * @brief Fusa_BBE_Check_buffer: Buffer address out of range and misaligned, both error bits set.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckBuffer_OutOfRangeAndMisaligned_BothErrors)
{
   uint32_t error_code  = 0;
   uintptr_t buf_addr   = 0x90000104; // Out of range and misaligned
   uint32_t range_start = 0x82000000;
   uint32_t range_end   = 0x84000000;
   int range_bit        = 2;
   int align_bit        = 3;
   Fusa_BBE_Check_Buffer(buf_addr, range_start, range_end, range_bit, align_bit, &error_code);
   EXPECT_EQ(error_code, ((1U << range_bit) | (1U << align_bit)))
      << "Both error bits should be set for out-of-range and misaligned buffer.";
}

/**
 * @brief Update_FUSA_BBE_Self_Test_Fault_Flag: returns CODED_FALSE if no error bits set, CODED_TRUE otherwise.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, UpdateFusaBBESelfTestFaultFlag_PassAndFail)
{
   // No error bits set (pass)
   uint32_t result_pass = 0U;
   EXPECT_EQ(Update_FUSA_BBE_Self_Test_Fault_Flag(result_pass), CODED_FALSE)
      << "Should return CODED_FALSE when no error bits set.";

   // Error bits set (fail)
   uint32_t result_fail = 0x1U;
   EXPECT_EQ(Update_FUSA_BBE_Self_Test_Fault_Flag(result_fail), CODED_TRUE) << "Should return CODED_TRUE when error bits set.";
}
/**
 * @brief Fusa_BBE_Check_Execute: When all subroutines return 0 (pass),
 *        the function returns 0 (no errors).
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckExecute_AllSubroutinesPass_ReturnsZero)
{
   /* All fakes return XTSTL_PASS (0x50415353) to indicate passing */
   xtstl_arstall_fake.return_val                 = XTSTL_PASS;
   xtstl_dram_prot_fake.return_val               = XTSTL_PASS;
   xtstl_dsp_bbe32_all_noDspOpts_fake.return_val = XTSTL_PASS;
   xtstl_er_fake.return_val                      = XTSTL_PASS;
   xtstl_externint_fake.return_val               = XTSTL_PASS;
   xtstl_instfetch_fake.return_val               = XTSTL_PASS;
   xtstl_iram0_l32r_fake.return_val              = XTSTL_PASS;
   xtstl_loadstore_fake.return_val               = XTSTL_PASS;
   xtstl_mpu_fake.return_val                     = XTSTL_PASS;
   xtstl_mpu_entry_fake.return_val               = XTSTL_PASS;
   xtstl_regfile_loadstore_fake.return_val       = XTSTL_PASS;
   xtstl_sr_fake.return_val                      = XTSTL_PASS;
   xtstl_win_rot_fake.return_val                 = XTSTL_PASS;

   uint32_t result = Fusa_BBE_Check_Execute();

   EXPECT_EQ(result & VALID_TEST_BITS, 0U) << "All subroutines pass, error result should be 0";
}

/**
 * @brief Fusa_BBE_Check_Execute: When one subroutine fails,
 *        corresponding bit is set in the return value.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckExecute_OneSubroutineFails_BitSet)
{
   /* xtstl_arstall returns XTSTL_FAIL to indicate failure */
   xtstl_arstall_fake.return_val = XTSTL_FAIL;

   uint32_t result = Fusa_BBE_Check_Execute();

   /* Bit 0 corresponds to xtstl_arstall failure */
   EXPECT_NE(result & 0x01U, 0U) << "Bit 0 should be set when xtstl_arstall fails";
}

/**
 * @brief Fusa_BBE_Check_Execute: When multiple subroutines fail,
 *        multiple bits are set.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckExecute_MultipleSubroutinesFail_MultipleBitsSet)
{
   xtstl_arstall_fake.return_val   = XTSTL_FAIL; /* bit 0 */
   xtstl_loadstore_fake.return_val = XTSTL_FAIL; /* bit 8 */

   uint32_t result = Fusa_BBE_Check_Execute();

   EXPECT_NE(result & 0x01U, 0U) << "Bit 0 (xtstl_arstall) should be set";
   EXPECT_NE(result & 0x100U, 0U) << "Bit 8 (xtstl_loadstore) should be set";
}

/**
 * @brief Fusa_BBE_Check_Execute: Test buffer pointers are set before tests run.
 */
TEST_F(FusaBbeSelfTest_UnitTestSuite, FusaBBECheckExecute_AllocatesTestBuffers)
{
   Mem_Pool_T dram1_pool = {0};
   Mem_Pool_T sram1_pool = {0};

   Mem_Pool_Alloc_fake.custom_fake = Mem_Pool_Alloc_Success;
   Appl_BBE_Self_Test_Memory_Init(&dram1_pool, &sram1_pool);

   EXPECT_GE(Mem_Pool_Alloc_fake.call_count, 1U) << "Mem_Pool_Alloc should be called at least once to allocate test buffers";
}
