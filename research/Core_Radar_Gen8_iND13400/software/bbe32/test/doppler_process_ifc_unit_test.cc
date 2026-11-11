/*===========================================================================*/
/**
 * @file doppler_process_ifc_unit_test.cc
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
 * Unit tests for doppler process wrapper `doppler_process_ifc.c`.
 * Tests follow the style of `appl_cfar_ifc_unit_test.cc` (fixture-based).
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "software/bbe32/src/doppler_process_ifc.c"

#include "appl_cfar_ifc_fff.h"
#include "appl_fp_ifc_fff.h"
#include "appl_sp_ifc_fff.h"
#include "appl_sweepbw_ifc_fff.h"
#include "cfar_fff.h"
#include "ci_stv_misalignment_fff.h"
#include "doppler_process_fff.h"
#include "ipc_fff.h"
#include "ra_helpers_fff.h"
#include "second_pass_fff.h"
#include "sweep_bw_fff.h"

/*===========================================================================*
 * FFF setup
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

uint16_t IPC_M2D_Buffer_Err_Cnt                                              = 0U;
uint32_t RangeProc_OutputDataCube[COMP_RFFT_CUBE_SIZE_IN_32BIT_WORDS][K_MAX] = {{0}};
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
USC_Cal_T USC_Cal_Data;
USC_Cal_T *USC_Cal_Data_Ptr = &USC_Cal_Data;
RDD_Internal_Buff_T rdd_internal_buffer;
RDD_Internal_Buff_T *p_rdd_int_buff = &rdd_internal_buffer;
const uint16_t K_FRAME[6]           = {960, 1024, 960, 1024, 1024, 1024};
const uint16_t M_FRAME[6]           = {480, 472, 512, 504, 512, 504};
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Doppler_Process_Ifc_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_CFAR_LIST(RESET_FAKE);
      FFF_FAKES_APPL_CFAR_IFC_LIST(RESET_FAKE);
      FFF_FAKES_APPL_FP_IFC_LIST(RESET_FAKE);
      FFF_FAKES_APPL_SP_IFC_LIST(RESET_FAKE);
      FFF_FAKES_APPL_SWEEPBW_IFC_LIST(RESET_FAKE);
      FFF_FAKES_RDD_SECOND_PASS_LIST(RESET_FAKE);
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_FAKES_DOPPLER_PROCESS_LIST(RESET_FAKE);
      FFF_FAKES_CI_STV_MISALLIGN_LIST(RESET_FAKE);
      FFF_FAKES_SWEEP_BW_LIST(RESET_FAKE);
      FFF_FAKES_RA_HELPERS_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      Appl_Sweep_Bw_Init_fake.return_val      = true;
      Appl_Cfar_Init_fake.return_val          = true;
      Appl_Rdd_Fp_Init_fake.return_val        = true;
      Appl_Second_Pass_Init_fake.return_val   = true;
      Appl_First_Pass_Execute_fake.return_val = true;

      Appl_Rdd_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
      Appl_CFAR_Memory_Init_fake.return_val      = MEM_POOL_SUCCESS;

      Doppler_Process_Init_fake.return_val                  = DOPPLER_PROCESS_NO_ERROR;
      Doppler_Process_Execute_RangeBin_Zero_fake.return_val = DOPPLER_PROCESS_NO_ERROR;
      Ra_Wait_Until_Done_fake.return_val                    = RA_HELPER_NO_ERROR;
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
 *  @b doppler_ifc_circular_buffer_init_01
 *  @n
 *      Circular_Buffer_Init should initialize all circular pointers.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_circular_buffer_init_01)
{
   NCI_Circular_Buffer_Trans_T rdop_avg_data_local = {0};

   rdop_avg_data = &rdop_avg_data_local;

   Circular_Buffer_Init();

   EXPECT_EQ(rdop_avg_data_ptr[0], &(*rdop_avg_data)[0][0][0]);
   EXPECT_EQ(rdop_avg_data_ptr[1], &(*rdop_avg_data)[1][0][0]);
   EXPECT_EQ(rdop_avg_data_ptr[NCI_CIRCULAR_BUFF_DEPTH - 1], &(*rdop_avg_data)[NCI_CIRCULAR_BUFF_DEPTH - 1][0][0]);
}

/**
 *  @b doppler_ifc_circular_buffer_update_01
 *  @n
 *      Circular_Buffer_Update should rotate the buffer pointers by one position.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_circular_buffer_update_01)
{
   NCI_Circular_Buffer_Trans_T rdop_avg_data_local = {0};

   rdop_avg_data = &rdop_avg_data_local;

   Circular_Buffer_Init();

   uint16_t *ptr0 = rdop_avg_data_ptr[0];
   uint16_t *ptr1 = rdop_avg_data_ptr[1];

   ASSERT_NE(ptr0, nullptr);
   ASSERT_NE(ptr1, nullptr);

   Circular_Buffer_Update();

   EXPECT_EQ(rdop_avg_data_ptr[0], ptr1);
   EXPECT_EQ(rdop_avg_data_ptr[NCI_CIRCULAR_BUFF_DEPTH - 1], ptr0);
}

/**
 *  @b doppler_ifc_dram1_memory_init_01
 *  @n
 *      Appl_Doppler_Dram1_Memory_Init should return success with sufficient pool memory.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_dram1_memory_init_01)
{
   Mem_Pool_T pool                                                   = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32))) = {0};

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Dram1_Memory_Init(&pool), MEM_POOL_SUCCESS);
   EXPECT_NE(rdop_avg_data, nullptr);
   EXPECT_NE(Angle_Coefficients_Ptr, nullptr);
}

/**
 *  @b doppler_ifc_dram1_memory_init_02
 *  @n
 *      Appl_Doppler_Dram1_Memory_Init should return failure when memory is insufficient.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_dram1_memory_init_02)
{
   Mem_Pool_T pool                                           = {0};
   uint8_t shared_l2_memory[64] __attribute__((aligned(32))) = {0};

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Dram1_Memory_Init(&pool), MEM_POOL_FAILURE);
}

/**
 *  @b doppler_ifc_sram1_memory_init_01
 *  @n
 *      Appl_Doppler_Sram1_Memory_Init should return success with sufficient pool memory.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_sram1_memory_init_01)
{
   Mem_Pool_T pool                                                             = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Sram1_Memory_Init(&pool), MEM_POOL_SUCCESS);
}

/**
 *  @b doppler_ifc_sram1_memory_init_02
 *  @n
 *      Appl_Doppler_Sram1_Memory_Init should return failure when memory is insufficient.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_sram1_memory_init_02)
{
   Mem_Pool_T pool                                              = {0};
   uint8_t shared_sram1_memory[64] __attribute__((aligned(32))) = {0};

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_sram1_memory, sizeof(shared_sram1_memory)), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Sram1_Memory_Init(&pool), MEM_POOL_FAILURE);
}

/**
 *  @b doppler_ifc_sram1_memory_init_null_alloc_01
 *  @n
 *      Appl_Doppler_Sram1_Memory_Init should skip body when pool alloc reports success with NULL output.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_sram1_memory_init_null_alloc_01)
{
   Mem_Pool_T pool = {0};

   pool.base_addr = nullptr;
   pool.size      = 0U;
   pool.max_size  = 0xFFFFFFFFU;

   dp_dfft_bv_output_buffer = nullptr;
   dp_rdop_avg_nci_data     = nullptr;
   dp_nci_bexp              = nullptr;

   EXPECT_EQ(Appl_Doppler_Sram1_Memory_Init(&pool), MEM_POOL_SUCCESS);
   EXPECT_EQ(dp_dfft_bv_output_buffer, nullptr);
   EXPECT_EQ(dp_rdop_avg_nci_data, nullptr);
   EXPECT_EQ(dp_nci_bexp, nullptr);
   EXPECT_EQ(Appl_CFAR_Memory_Init_fake.call_count, 0U);
}

/**
 *  @b doppler_ifc_process_init_look_a_01
 *  @n
 *      Appl_Doppler_Process_Init should succeed for look A when SPBB init succeeds.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_process_init_look_a_01)
{
   int16_t angle_coeffs[4][32] = {{0}};
   Angle_Coefficients_Ptr      = &angle_coeffs[0];

   Doppler_Process_Init_fake.return_val = DOPPLER_PROCESS_NO_ERROR;

   EXPECT_TRUE(Appl_Doppler_Process_Init(RADAR_LOOK_A));
   EXPECT_EQ(Doppler_Process_Init_fake.call_count, 1U);
   EXPECT_EQ(Do_Matrix_Multiply_fake.call_count, 1U);
}

/**
 *  @b doppler_ifc_process_init_look_bcd_01
 *  @n
 *      Appl_Doppler_Process_Init should execute look-id specific branches B, C, and D.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_process_init_look_bcd_01)
{
   int16_t angle_coeffs[4][32] = {{0}};
   Angle_Coefficients_Ptr      = &angle_coeffs[0];

   Doppler_Process_Init_fake.return_val = DOPPLER_PROCESS_NO_ERROR;

   EXPECT_TRUE(Appl_Doppler_Process_Init(RADAR_LOOK_B));
   EXPECT_TRUE(Appl_Doppler_Process_Init(RADAR_LOOK_C));
   EXPECT_TRUE(Appl_Doppler_Process_Init(RADAR_LOOK_D));
   EXPECT_EQ(Doppler_Process_Init_fake.call_count, 3U);
   EXPECT_EQ(Do_Matrix_Multiply_fake.call_count, 3U);
}

/**
 *  @b doppler_ifc_process_init_fail_01
 *  @n
 *      Appl_Doppler_Process_Init should return false when Doppler_Process_Init fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_process_init_fail_01)
{
   int16_t angle_coeffs[4][32] = {{0}};
   Angle_Coefficients_Ptr      = &angle_coeffs[0];

   Doppler_Process_Init_fake.return_val = DOPPLER_PROCESS_CONFIG_FAIL_ERROR;

   EXPECT_FALSE(Appl_Doppler_Process_Init(RADAR_LOOK_A));
   EXPECT_EQ(Doppler_Process_Init_fake.call_count, 1U);
}

/**
 *  @b doppler_ifc_rdd_process_init_fail_01
 *  @n
 *      Appl_Rdd_Process_Init should return false when any sub-init fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_rdd_process_init_fail_01)
{
   Appl_Cfar_Init_fake.return_val = false;

   EXPECT_FALSE(Appl_Rdd_Process_Init(RADAR_LOOK_A));
   EXPECT_EQ(Appl_Sweep_Bw_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Cfar_Init_fake.call_count, 1U);
}

/**
 *  @b doppler_ifc_rdd_process_init_fp_fail_01
 *  @n
 *      Appl_Rdd_Process_Init should return false when first pass init fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_rdd_process_init_fp_fail_01)
{
   Appl_Rdd_Fp_Init_fake.return_val = false;

   EXPECT_FALSE(Appl_Rdd_Process_Init(RADAR_LOOK_A));
   EXPECT_EQ(Appl_Sweep_Bw_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Cfar_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Rdd_Fp_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Second_Pass_Init_fake.call_count, 0U);
}

/**
 *  @b doppler_ifc_rdd_process_init_sp_fail_01
 *  @n
 *      Appl_Rdd_Process_Init should return false when second pass init fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_rdd_process_init_sp_fail_01)
{
   Appl_Second_Pass_Init_fake.return_val = false;

   EXPECT_FALSE(Appl_Rdd_Process_Init(RADAR_LOOK_A));
   EXPECT_EQ(Appl_Sweep_Bw_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Cfar_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Rdd_Fp_Init_fake.call_count, 1U);
   EXPECT_EQ(Appl_Second_Pass_Init_fake.call_count, 1U);
}

/**
 *  @b doppler_ifc_appl_processing_init_fail_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return error when init path fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_init_fail_01)
{
   D2M_Msg_T d2m_msg                             = {0};
   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

   Appl_Sweep_Bw_Init_fake.return_val = false;

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_ERROR);
}

/**
 *  @b doppler_ifc_appl_processing_init_fail_02
 *  @n
 *      Appl_Doppler_Rdd_Processing should return error when init path fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_init_fail_02)
{
   D2M_Msg_T d2m_msg                             = {0};
   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

   Doppler_Process_Init_fake.return_val = DOPPLER_PROCESS_CONFIG_FAIL_ERROR;
   Appl_Sweep_Bw_Init_fake.return_val   = false;

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_ERROR);
}

/**
 *  @b doppler_ifc_appl_processing_success_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return success on full happy path.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_success_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_NO_ERROR);
   EXPECT_GT(Doppler_Process_Execute_fake.call_count, 0U);
   EXPECT_EQ(Appl_Second_Pass_Execute_fake.call_count, 1U);
}

/**
 *  @b doppler_ifc_appl_processing_rangebin_zero_fail_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should skip the first three guarded execute calls when range-bin-zero fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_rangebin_zero_fail_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val         = &d2m_msg;
   Doppler_Process_Execute_RangeBin_Zero_fake.return_val = DOPPLER_PROCESS_CONFIG_FAIL_ERROR;

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_NO_ERROR);
   EXPECT_EQ(Doppler_Process_Execute_fake.call_count, (unsigned int)(MAX_RANGE_BINS - 4U));
}

/**
 *  @b doppler_ifc_appl_processing_ra_fail_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return error when RA completion fails.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_ra_fail_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   Ra_Wait_Until_Done_fake.return_val = RA_HELPER_FAIL_ERROR;

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_ERROR);
   EXPECT_GT(Ra_Wait_Until_Done_fake.call_count, 0U);
}

/**
 *  @b doppler_ifc_appl_processing_ra_fail_second_loop_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return error when RA fails at the beginning of the second loop.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_ra_fail_second_loop_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};
   Ra_Helper_Error_T ra_wait_seq[NUM_INITIAL_RANGE_BINS + 1U]                  = {RA_HELPER_NO_ERROR};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   for (uint32_t idx = 0U; idx < NUM_INITIAL_RANGE_BINS; ++idx)
   {
      ra_wait_seq[idx] = RA_HELPER_NO_ERROR;
   }
   ra_wait_seq[NUM_INITIAL_RANGE_BINS] = RA_HELPER_FAIL_ERROR;

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;
   SET_RETURN_SEQ(Ra_Wait_Until_Done, ra_wait_seq, NUM_INITIAL_RANGE_BINS + 1U);

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_ERROR);
   EXPECT_EQ(Ra_Wait_Until_Done_fake.call_count, (unsigned int)(NUM_INITIAL_RANGE_BINS + 1U));
}

/**
 *  @b doppler_ifc_appl_processing_ra_fail_last_wait_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return error when RA fails at the final wait after LAST_RBIN_INDEX.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_ra_fail_last_wait_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};
   static Ra_Helper_Error_T ra_wait_seq[MAX_RANGE_BINS]                        = {RA_HELPER_NO_ERROR};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   for (uint32_t idx = 0U; idx < MAX_RANGE_BINS; ++idx)
   {
      ra_wait_seq[idx] = RA_HELPER_NO_ERROR;
   }
   ra_wait_seq[MAX_RANGE_BINS - 1U] = RA_HELPER_FAIL_ERROR;

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;
   SET_RETURN_SEQ(Ra_Wait_Until_Done, ra_wait_seq, MAX_RANGE_BINS);

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_ERROR);
   EXPECT_EQ(Ra_Wait_Until_Done_fake.call_count, (unsigned int)(MAX_RANGE_BINS));
}

/**
 *  @b doppler_ifc_appl_processing_timeout_fail_01
 *  @n
 *      Appl_Doppler_Rdd_Processing should return timeout error when processing exceeds allowed time.
 */
TEST_F(Doppler_Process_Ifc_Unit_Test_Suite, doppler_ifc_appl_processing_timeout_fail_01)
{
   D2M_Msg_T d2m_msg                                                           = {0};
   Mem_Pool_T dram_pool                                                        = {0};
   Mem_Pool_T sram_pool                                                        = {0};
   uint8_t shared_l2_memory[512 * 1024] __attribute__((aligned(32)))           = {0};
   const size_t sram1_size                                                     = 2 * 1024 * 1024;
   static uint8_t shared_sram1_memory[sram1_size] __attribute__((aligned(32))) = {0};
   uint32_t doppler_proc_timestamp_seq[3] = {0U, MAX_DOPPLER_PROC_OVERRUN_TIME_TICKS, MAX_DOPPLER_PROC_OVERRUN_TIME_TICKS + 1U};

   ASSERT_NE(shared_sram1_memory, nullptr);
   memset(shared_sram1_memory, 0, sram1_size);

   Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;
   SET_RETURN_SEQ(xthal_get_ccount, doppler_proc_timestamp_seq, 3);

   ASSERT_EQ(Mem_Pool_Init(&dram_pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);
   ASSERT_EQ(Mem_Pool_Init(&sram_pool, shared_sram1_memory, sram1_size), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Dram1_Memory_Init(&dram_pool), MEM_POOL_SUCCESS);
   ASSERT_EQ(Appl_Doppler_Sram1_Memory_Init(&sram_pool), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Doppler_Rdd_Processing(RADAR_LOOK_A), APPL_DOPPLER_TIMEOUT);
   EXPECT_GT(Doppler_Process_Execute_fake.call_count, 0U);
   EXPECT_EQ(Appl_Second_Pass_Execute_fake.call_count, 1U);
}
