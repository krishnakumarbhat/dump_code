/*===========================================================================*/
/**
 * @file mem_pool_unit_test.cc
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
 * Unit test suite for the checking the mem_pool.h file
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

extern "C"
{
#include "mem_pool.h"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Mem_Pool_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
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

/**
 *  @b mem_pool_mem_pool_init
 *  @n
 */
TEST_F(Mem_Pool_Unit_Test_Suite, mem_pool_mem_pool_init_01)
{
   Mem_Pool_T mem_pool;
   uint32_t max_size = 64;
   uint8_t shared_l2_memory[max_size] __attribute__((aligned(32)));
   uint32_t size               = 32;
   Memory_Pool_Return_T retval = Mem_Pool_Init(&mem_pool, shared_l2_memory, size);

   EXPECT_EQ(retval, MEM_POOL_SUCCESS);
   EXPECT_EQ(mem_pool.max_size, size);
   EXPECT_EQ(mem_pool.size, 0);
}

/**
 *  @b mem_pool_mem_pool_init
 *  @n
 */
TEST_F(Mem_Pool_Unit_Test_Suite, mem_pool_mem_pool_init_02)
{
   Mem_Pool_T mem_pool;
   uint32_t max_size = 64;
   uint8_t shared_l2_memory[max_size];
   uint32_t size               = 10;
   uint8_t *addr               = (uint8_t *)7;
   Memory_Pool_Return_T retval = Mem_Pool_Init(&mem_pool, addr, size);

   EXPECT_EQ(retval, MEM_POOL_FAILURE);
   EXPECT_EQ(mem_pool.max_size, 0);
   EXPECT_EQ(mem_pool.size, 0);
}

/**
 *  @b mem_pool_mem_pool_reset
 *  @n
 */
TEST_F(Mem_Pool_Unit_Test_Suite, mem_pool_mem_pool_reset_01)
{
   Mem_Pool_T mem_pool;
   mem_pool.size = 16;
   Mem_Pool_Reset(&mem_pool);

   EXPECT_EQ(mem_pool.size, 0);
}

/**
 *  @b mem_pool_mem_pool_alloc
 *  @n
 */
TEST_F(Mem_Pool_Unit_Test_Suite, mem_pool_mem_pool_alloc_01)
{
   Mem_Pool_T mem_pool;
   uint32_t max_size = 1024;
   uint8_t shared_l2_memory[max_size] __attribute__((aligned(32)));
   uint8_t(*buffer)[4][4]      = NULL;
   uint8_t(*buffer_2)[8][4]    = NULL;
   uint32_t size1              = sizeof(*buffer);
   uint32_t size2              = sizeof(*buffer_2);
   uint32_t exp_alloc_size1    = 32;
   uint32_t exp_alloc_size2    = 64;
   Memory_Pool_Return_T retval = Mem_Pool_Init(&mem_pool, shared_l2_memory, max_size);

   retval = Mem_Pool_Alloc(&mem_pool, size1, (void **)&buffer);

   EXPECT_EQ(retval, MEM_POOL_SUCCESS);
   EXPECT_EQ(mem_pool.size, exp_alloc_size1);
   EXPECT_TRUE((uint8_t *)buffer == (uint8_t *)&shared_l2_memory[0]);

   // Verify allocation of mempool happens after the end of previous allocation
   retval = Mem_Pool_Alloc(&mem_pool, size2, (void **)&buffer_2);
   EXPECT_EQ(retval, MEM_POOL_SUCCESS);
   EXPECT_EQ(mem_pool.size, exp_alloc_size2);
   EXPECT_TRUE((uint8_t *)buffer_2 == (uint8_t *)&shared_l2_memory[exp_alloc_size1]);
}

/**
 *  @b mem_pool_mem_pool_alloc
 *  @n
 */
TEST_F(Mem_Pool_Unit_Test_Suite, mem_pool_mem_pool_alloc_02)
{
   Mem_Pool_T mem_pool;
   uint32_t max_size = 1024;
   uint8_t shared_l2_memory[max_size] __attribute__((aligned(32)));
   uint8_t(*buffer)[512][4] = NULL;

   Memory_Pool_Return_T retval = Mem_Pool_Init(&mem_pool, shared_l2_memory, max_size);

   retval = Mem_Pool_Alloc(&mem_pool, sizeof(*buffer), (void **)&buffer);

   EXPECT_EQ(retval, MEM_POOL_FAILURE);
   EXPECT_EQ(mem_pool.size, 0);
}
