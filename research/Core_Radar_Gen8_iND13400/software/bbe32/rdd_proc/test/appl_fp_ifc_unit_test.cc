/*===========================================================================*/
/**
 * @file appl_fp_ifc_unit_test.cc
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
 * Unit tests for the application First Pass wrapper `appl_fp_ifc.c`.
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "core_macros_fff.h"
#include "ipc_fff.h"
#include "rdd_fp_fff.h"

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "appl_fp_ifc.c"

/*===========================================================================*
 * FFF setup
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Backing Data
 *===========================================================================*/
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
USC_Cal_T USC_Cal_Data;
USC_Cal_T *USC_Cal_Data_Ptr = &USC_Cal_Data;
Radar_Look_T look_id;

volatile M2D_Msg_T m2d_msg;
D2M_Msg_T d2m_msg;
RDD_Internal_Buff_T rdd_internal_buffer;
uint16_t *rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH];

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Appl_Fp_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_FAKES_CORE_MACROS(RESET_FAKE);
      FFF_FAKES_RDD_FIRST_PASS_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      (void)memset((void *)&m2d_msg, 0, sizeof(m2d_msg));
      (void)memset(&d2m_msg, 0, sizeof(d2m_msg));
      (void)memset(&SMC_Cal_Data, 0, sizeof(SMC_Cal_Data));
      (void)memset(&USC_Cal_Data, 0, sizeof(USC_Cal_Data));
      (void)memset(&rdd_internal_buffer, 0, sizeof(rdd_internal_buffer));

      Rdd_First_Pass_Init_fake.return_val           = RDD_FIRST_PASS_NO_ERROR;
      Rdd_First_Pass_Execute_fake.return_val        = RDD_FIRST_PASS_NO_ERROR;
      Get_IPC_M2D_Buffer_fake.return_val            = &m2d_msg;
      Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

      p_rdd_int_buff = &rdd_internal_buffer;
      look_id        = RADAR_LOOK_A;
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
 *  @b appl_fp_appl_rdd_dram1_memory_init_01
 *  @n
 *      Verify memory init returns success when pool allocation succeeds.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_rdd_dram1_memory_init_01)
{
   Mem_Pool_T pool = {0};
   uint8_t shared_l2_memory[sizeof(RDD_Internal_Buff_T) + 64] __attribute__((aligned(32)));

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);

   EXPECT_EQ(Appl_Rdd_Dram1_Memory_Init(&pool), MEM_POOL_SUCCESS);
   EXPECT_NE(p_rdd_int_buff, nullptr);
}

/**
 *  @b appl_fp_appl_rdd_dram1_memory_init_02
 *  @n
 *      Verify memory init returns failure when pool allocation fails.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_rdd_dram1_memory_init_02)
{
   Mem_Pool_T pool = {0};
   uint8_t shared_l2_memory[sizeof(RDD_Internal_Buff_T) + 64] __attribute__((aligned(32)));
   Memory_Pool_Return_T ret;

   ASSERT_EQ(Mem_Pool_Init(&pool, shared_l2_memory, sizeof(shared_l2_memory)), MEM_POOL_SUCCESS);

   ret = Appl_Rdd_Dram1_Memory_Init(&pool);
   EXPECT_EQ(ret, MEM_POOL_SUCCESS);

   ret = Appl_Rdd_Dram1_Memory_Init(&pool);
   EXPECT_EQ(ret, MEM_POOL_FAILURE);
}

/**
 *  @b appl_fp_appl_first_pass_execute_01
 *  @n
 *      Appl_First_Pass_Execute returns true when first pass processing succeeds.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_first_pass_execute_01)
{
   D2M_Msg_T local_d2m_msg                                                 = {0};
   BV_Comp_Type_T beam_vector_data[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE] = {0};

   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[0][0] = 1U;
   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[1][0] = 2U;
   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[2][0] = 3U;

   Rdd_First_Pass_Execute_fake.return_val = RDD_FIRST_PASS_NO_ERROR;
   EXPECT_TRUE(Appl_First_Pass_Execute(1U, &local_d2m_msg, &beam_vector_data));
   EXPECT_EQ(Rdd_First_Pass_Execute_fake.call_count, 1U);
   EXPECT_EQ(xthal_dcache_block_invalidate_fake.call_count, 1U);
}

/**
 *  @b appl_fp_appl_first_pass_execute_02
 *  @n
 *      Appl_First_Pass_Execute returns false when first pass processing fails.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_first_pass_execute_02)
{
   D2M_Msg_T local_d2m_msg                                                 = {0};
   BV_Comp_Type_T beam_vector_data[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE] = {0};

   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[0][0] = 1U;
   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[1][0] = 2U;
   local_d2m_msg.payload.rdd_stream_data.rdd_data.nci_bexp[2][0] = 3U;

   Rdd_First_Pass_Execute_fake.return_val = RDD_FIRST_PASS_FAILURE_ERROR;
   EXPECT_FALSE(Appl_First_Pass_Execute(1U, &local_d2m_msg, &beam_vector_data));
   EXPECT_EQ(Rdd_First_Pass_Execute_fake.call_count, 1U);
}

/**
 *  @b appl_fp_first_pass_execute_setup_01
 *  @n
 *      Verify target-select command forces max XCP indices in setup.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_first_pass_execute_setup_01)
{
   Rdd_First_Pass_Input_T rdd_fp_input   = {0};
   Rdd_First_Pass_Output_T rdd_fp_output = {0};

   m2d_msg.payload.xcp_info.xcp_target_select_cmd = CODED_TRUE;

   p_rdd_int_buff->xcp_range_idx   = 7U;
   p_rdd_int_buff->xcp_doppler_idx = 9U;
   p_rdd_int_buff->xcp_angle_idx   = 11U;

   First_Pass_Execute_Setup(1U, &d2m_msg, &rdd_fp_input, &rdd_fp_output);

   EXPECT_EQ(rdd_fp_input.rdd_fp_xcp_ip.xcp_range_idx, MAX_RANGE_BINS);
   EXPECT_EQ(rdd_fp_input.rdd_fp_xcp_ip.xcp_doppler_idx, MAX_DOPPLER_FFT_SIZE);
   EXPECT_EQ(rdd_fp_input.rdd_fp_xcp_ip.xcp_angle_idx, ANGLE_BINS_USED);
}

/**
 *  @b appl_fp_appl_rdd_fp_init_01
 *  @n
 *      Appl_Rdd_Fp_Init returns true when first pass init succeeds.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_rdd_fp_init_01)
{
   Rdd_First_Pass_Init_fake.return_val = RDD_FIRST_PASS_NO_ERROR;

   EXPECT_TRUE(Appl_Rdd_Fp_Init(look_id));
   EXPECT_EQ(Rdd_First_Pass_Init_fake.call_count, 1U);
}

/**
 *  @b appl_fp_appl_rdd_fp_init_02
 *  @n
 *      Appl_Rdd_Fp_Init returns false when first pass init fails.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_appl_rdd_fp_init_02)
{
   Rdd_First_Pass_Init_fake.return_val = RDD_FIRST_PASS_FAILURE_ERROR;

   EXPECT_FALSE(Appl_Rdd_Fp_Init(look_id));
   EXPECT_EQ(Rdd_First_Pass_Init_fake.call_count, 1U);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_01
 *  @n
 *      Verify disabled vary-throughput path uses values from incoming IPC info.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_01)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag         = CODED_FALSE;
   m2d_msg.payload.xcp_info.xcp_max_fp_per_rbin_target_cnt = 8U;
   m2d_msg.payload.xcp_info.xcp_max_fp_tgt_cnt             = 16U;
   m2d_msg.payload.xcp_info.xcp_rngidx_target_start        = 3U;
   m2d_msg.payload.xcp_info.xcp_spe_gain                   = 1.2f;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_FALSE(p_rdd_int_buff->xcp_rdd_vary_xput_flag);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt, 8U);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_tgt_cnt, 16U);
   EXPECT_EQ(p_rdd_int_buff->xcp_rngidx_target_start, 3U);
   EXPECT_FLOAT_EQ(p_rdd_int_buff->xcp_spe_gain, 1.2f);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_02
 *  @n
 *      Verify enabled vary-throughput + static-target path applies default limits.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_02)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag            = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_max_static_target_case_enable = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_spe_gain                      = 2.3f;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_TRUE(p_rdd_int_buff->xcp_rdd_vary_xput_flag);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt, MAX_DETS_FIRST_PASS);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_tgt_cnt, MAX_DETS_FIRST_PASS);
   EXPECT_EQ(p_rdd_int_buff->xcp_rngidx_target_start, 0U);
   EXPECT_FLOAT_EQ(p_rdd_int_buff->xcp_spe_gain, 2.3f);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_03
 *  @n
 *      Verify non-static-target vary-throughput branch updates limits and index.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_03)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag            = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_max_static_target_case_enable = CODED_FALSE;
   m2d_msg.payload.xcp_info.xcp_spe_gain_vary_enable_flag     = CODED_FALSE;
   m2d_msg.payload.xcp_info.xcp_spe_gain                      = 1.5f;

   p_rdd_int_buff->xcp_max_fp_tgt_cnt                = 0U;
   p_rdd_int_buff->xcp_rngidx_target_start           = 10U;
   d2m_msg.payload.xcp_data.xcp_max_per_rbin_targets = 5U;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_TRUE(p_rdd_int_buff->xcp_rdd_vary_xput_flag);
   EXPECT_EQ(d2m_msg.payload.xcp_data.xcp_max_per_rbin_targets, 0U);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt, XCP_Max_Static_PrBin_Max_Tgts);
   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_tgt_cnt, MAX_DETS_FIRST_PASS);
   EXPECT_EQ(p_rdd_int_buff->xcp_rngidx_target_start, 11U);
   EXPECT_FLOAT_EQ(p_rdd_int_buff->xcp_spe_gain, 1.5f);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_04
 *  @n
 *      Verify non-zero target-count branch, SPE gain vary branch, and range-index wrap branch.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_04)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag            = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_max_static_target_case_enable = CODED_FALSE;

   /* Branch: (0U == xcp_max_fp_tgt_cnt) is false, and wrap at MAX_RANGE_BINS - 1U */
   m2d_msg.payload.xcp_info.xcp_spe_gain_vary_enable_flag = CODED_FALSE;
   p_rdd_int_buff->xcp_max_fp_tgt_cnt                     = 2U;
   p_rdd_int_buff->xcp_rngidx_target_start                = (uint16_t)(MAX_RANGE_BINS - 1U);
   d2m_msg.payload.xcp_data.xcp_max_per_rbin_targets      = 3U;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_tgt_cnt, 1U);
   EXPECT_EQ(p_rdd_int_buff->xcp_rngidx_target_start, 0U);
   EXPECT_EQ(d2m_msg.payload.xcp_data.xcp_max_per_rbin_targets, 0U);

   /* Branch: (CODED_TRUE == xcp_spe_gain_vary_enable_flag) is true */
   m2d_msg.payload.xcp_info.xcp_spe_gain_vary_enable_flag = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_spe_gain_min              = 1.0f;
   m2d_msg.payload.xcp_info.xcp_spe_gain_max              = 1.0f;
   p_rdd_int_buff->xcp_max_fp_tgt_cnt                     = 0U;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_EQ(p_rdd_int_buff->xcp_max_fp_tgt_cnt, MAX_DETS_FIRST_PASS);
   EXPECT_FLOAT_EQ(p_rdd_int_buff->xcp_spe_gain, 1.0f);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_05
 *  @n
 *      Verify SPE gain vary branch keeps local gain when it remains within min/max bounds.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_05)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag            = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_max_static_target_case_enable = CODED_FALSE;
   m2d_msg.payload.xcp_info.xcp_spe_gain_vary_enable_flag     = CODED_TRUE;

   /* Keep the bounds wide so both comparisons at line 438 evaluate false. */
   m2d_msg.payload.xcp_info.xcp_spe_gain_min = -1000.0f;
   m2d_msg.payload.xcp_info.xcp_spe_gain_max = 1000.0f;

   p_rdd_int_buff->xcp_max_fp_tgt_cnt      = 0U;
   p_rdd_int_buff->xcp_rngidx_target_start = 20U;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_TRUE(p_rdd_int_buff->xcp_rdd_vary_xput_flag);
   EXPECT_GT(p_rdd_int_buff->xcp_spe_gain, m2d_msg.payload.xcp_info.xcp_spe_gain_min);
   EXPECT_LT(p_rdd_int_buff->xcp_spe_gain, m2d_msg.payload.xcp_info.xcp_spe_gain_max);
}

/**
 *  @b appl_fp_update_rdd_instrumentation_variables_06
 *  @n
 *      Verify SPE gain vary branch takes out-of-range path when local gain exceeds max
 *      while still not being below min.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_update_rdd_instrumentation_variables_06)
{
   m2d_msg.payload.xcp_info.xcp_rdd_vary_xput_flag            = CODED_TRUE;
   m2d_msg.payload.xcp_info.xcp_max_static_target_case_enable = CODED_FALSE;
   m2d_msg.payload.xcp_info.xcp_spe_gain_vary_enable_flag     = CODED_TRUE;

   /* Ensure (xcp_spe_gain_local > max) is true and (xcp_spe_gain_local < min) is false. */
   m2d_msg.payload.xcp_info.xcp_spe_gain_min = -1000.0f;
   m2d_msg.payload.xcp_info.xcp_spe_gain_max = -500.0f;

   p_rdd_int_buff->xcp_max_fp_tgt_cnt      = 0U;
   p_rdd_int_buff->xcp_rngidx_target_start = 30U;

   Update_Rdd_Instrumentation_Variables();

   EXPECT_TRUE(p_rdd_int_buff->xcp_rdd_vary_xput_flag);
   EXPECT_FLOAT_EQ(p_rdd_int_buff->xcp_spe_gain, -1000.0f);
}

/**
 *  @b appl_fp_handle_xcp_beamvector_data_01
 *  @n
 *      Verify Calculate_BV_Variance is called when range_idx matches xcp_range_idx_bv_var.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_handle_xcp_beamvector_data_01)
{
   BV_Comp_Type_T beam_vector_data[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE] = {0};
   uint16_t range_idx                                                      = 10U;
   uint16_t xcp_range_idx_bv                                               = 10U;

   Handle_Xcp_Beamvector_Data(range_idx, &beam_vector_data, xcp_range_idx_bv);

   EXPECT_EQ(Calculate_BV_Variance_fake.call_count, 1U);
}

/**
 *  @b appl_fp_handle_xcp_beamvector_data_02
 *  @n
 *      Verify Calculate_BV_Variance is NOT called when range_idx does not match xcp_range_idx_bv_var.
 */
TEST_F(Appl_Fp_Unit_Test_Suite, appl_fp_handle_xcp_beamvector_data_02)
{
   BV_Comp_Type_T beam_vector_data[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE] = {0};
   uint16_t range_idx                                                      = 10U;
   uint16_t xcp_range_idx_bv                                               = 15U;

   Handle_Xcp_Beamvector_Data(range_idx, &beam_vector_data, xcp_range_idx_bv);

   EXPECT_EQ(Calculate_BV_Variance_fake.call_count, 0U);
}
