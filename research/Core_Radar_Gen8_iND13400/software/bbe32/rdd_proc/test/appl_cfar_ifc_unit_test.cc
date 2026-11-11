/*===========================================================================*/
/**
 * @file appl_cfar_ifc_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit tests for the application CFAR wrapper `appl_cfar_ifc.c`.
 * Tests follow the style of `mem_pool_unit_test.cc` (fixture-based).
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include "cfar_fff.h"
#include "smc_cal.h"
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "appl_cfar_ifc.c"
}

/*===========================================================================*
 * Valid Configuration For Tests
 *===========================================================================*/
DEFINE_FFF_GLOBALS;
uint16_t *rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH];
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;

/*===========================================================================*
 * Valid Configuration For Tests
 *===========================================================================*/

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/

class Appl_Cfar_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_CFAR_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
/**
 *  @b appl_cfar_appl_cfar_init_01
 *  @n
 *      Appl_Cfar_Init returns true when the underlying CFAR init succeeds.
 */
TEST_F(Appl_Cfar_Unit_Test_Suite, appl_cfar_appl_cfar_init_01)
{
   Cfar_Process_Init_fake.return_val = CFAR_PROCESS_NO_ERROR;
   EXPECT_TRUE(Appl_Cfar_Init(RADAR_LOOK_A));
   EXPECT_EQ(Cfar_Process_Init_fake.call_count, 1);
}

/**
 *  @b appl_cfar_appl_cfar_init_02
 *  @n
 *      Appl_Cfar_Init returns false when the underlying CFAR init fails.
 */
TEST_F(Appl_Cfar_Unit_Test_Suite, appl_cfar_appl_cfar_init_02)
{
   Cfar_Process_Init_fake.return_val = CFAR_PROCESS_INIT_FAIL_ERROR;
   EXPECT_FALSE(Appl_Cfar_Init(RADAR_LOOK_A));
   EXPECT_EQ(Cfar_Process_Init_fake.call_count, 1);
}

/**
 *  @b appl_cfar_appl_cfar_memory_init_01
 *  @n
 *      Appl_CFAR_Memory_Init allocates the internal CFAR buffer from the
 *      provided memory pool and updates `p_cfar_int_buff` accordingly.
 */
TEST_F(Appl_Cfar_Unit_Test_Suite, appl_cfar_appl_cfar_memory_init_01)
{
   Mem_Pool_T pool;
   uint8_t shared_l2_memory[sizeof(CFAR_Internal_Buff_T) + 64] __attribute__((aligned(32)));
   /* Initialize mem pool so Mem_Pool_Alloc can succeed */
   EXPECT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);

   Memory_Pool_Return_T ret = Appl_CFAR_Memory_Init(&pool);
   EXPECT_EQ(ret, MEM_POOL_SUCCESS);
   EXPECT_NE(p_cfar_int_buff, nullptr);
}

/**
 *  @b appl_cfar_appl_cfar_execute_01
 *  @n
 *      Appl_Cfar_Execute should call into the CFAR processing routine.
 */
TEST_F(Appl_Cfar_Unit_Test_Suite, appl_cfar_appl_cfar_execute_01)
{
   /* Prepare IPC RDD buffer */
   RDD_Data_T rdd = {0};

   /* Ensure internal CFAR buffer allocated */
   Mem_Pool_T pool;
   uint8_t shared_l2_memory[sizeof(CFAR_Internal_Buff_T) + 64] __attribute__((aligned(32)));
   ASSERT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_CFAR_Memory_Init(&pool), MEM_POOL_SUCCESS);

   Appl_Cfar_Execute(RADAR_LOOK_A, &rdd);

   EXPECT_EQ(Cfar_Process_fake.call_count, 1);
}
