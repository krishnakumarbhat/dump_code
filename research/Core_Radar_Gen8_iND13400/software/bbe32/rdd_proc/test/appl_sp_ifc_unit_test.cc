/*===========================================================================*/
/**
 * @file appl_sp_ifc_unit_test.cc
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
 * Unit tests for the application Second Pass wrapper `appl_sp_ifc.c`.
 * Tests follow the style of `appl_cfar_ifc_unit_test.cc`.
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
#include "appl_sp_ifc.h"
#include "ipc_fff.h"
#include "second_pass_fff.h"

/*===========================================================================*
 * FFF setup
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "appl_sp_ifc.c"

/*===========================================================================*
 * Test Backing Data
 *===========================================================================*/
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;

D2M_Msg_T d2m_msg;
RDD_Internal_Buff_T rdd_internal_buffer;
RDD_Internal_Buff_T *p_rdd_int_buff;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Appl_Sp_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_FAKES_RDD_SECOND_PASS_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      (void)memset(&d2m_msg, 0, sizeof(d2m_msg));
      (void)memset(&SMC_Cal_Data, 0, sizeof(SMC_Cal_Data));
      (void)memset(&rdd_internal_buffer, 0, sizeof(rdd_internal_buffer));

      Rdd_Second_Pass_Init_fake.return_val          = RDD_SECOND_PASS_NO_ERROR;
      Rdd_Second_Pass_Execute_fake.return_val       = RDD_SECOND_PASS_NO_ERROR;
      Rdd_Second_Pass_XCP_Output_fake.return_val    = RDD_SECOND_PASS_NO_ERROR;
      Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.return_val = &d2m_msg;

      p_rdd_int_buff = &rdd_internal_buffer;
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
 *  @b appl_sp_appl_second_pass_init_01
 *  @n
 *      Verify init returns true and calls SPBB init when SFW mode value is enabled.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Init_SfwEnabled_ReturnsTrue)
{
   k_rbin_res_smc[0]                      = 11;
   k_dbin_res_smc[0]                      = 22;
   k_rdd_processing_smc[0]                = 2U;
   p_rdd_int_buff->xcp_rdd_vary_xput_flag = 1U;

   ASSERT_EQ(true, Appl_Second_Pass_Init((Radar_Look_T)0));
   ASSERT_EQ(1U, Rdd_Second_Pass_Init_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Init_fake.arg0_val == nullptr);
   ASSERT_EQ(11, k_rbin_res_smc[0]);
   ASSERT_EQ(22, k_dbin_res_smc[0]);
   ASSERT_EQ(1U, p_rdd_int_buff->xcp_rdd_vary_xput_flag);
}

/**
 *  @b appl_sp_appl_second_pass_init_02
 *  @n
 *      Verify init returns true and calls SPBB init when SFW mode value is disabled.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Init_SfwDisabled_ReturnsTrue)
{
   k_rbin_res_smc[1]       = 33;
   k_rdd_processing_smc[1] = 1U;

   ASSERT_EQ(true, Appl_Second_Pass_Init((Radar_Look_T)1));
   ASSERT_EQ(1U, Rdd_Second_Pass_Init_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Init_fake.arg0_val == nullptr);
   ASSERT_EQ(33, k_rbin_res_smc[1]);
   ASSERT_EQ(1U, k_rdd_processing_smc[1]);
}

/**
 *  @b appl_sp_appl_second_pass_init_03
 *  @n
 *      Verify init returns false when underlying second-pass init fails.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Init_ApiFail_ReturnsFalse)
{
   Rdd_Second_Pass_Init_fake.return_val = (Rdd_Second_Pass_Error_T)1;

   ASSERT_EQ(false, Appl_Second_Pass_Init((Radar_Look_T)0));
   ASSERT_EQ(1U, Rdd_Second_Pass_Init_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Init_fake.arg0_val == nullptr);
}

/**
 *  @b appl_sp_appl_second_pass_execute_01
 *  @n
 *      Verify execute skips XCP when doppler index is out of bounds.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_DopplerOutOfRange_SkipsXcp)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx = MAX_DOPPLER_FFT_SIZE;
   p_rdd_int_buff->xcp_range_idx   = 0U;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_Execute_fake.call_count);
   ASSERT_EQ(0U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Execute_fake.arg0_val == nullptr);
   ASSERT_EQ(false, Rdd_Second_Pass_Execute_fake.arg1_val == nullptr);
   ASSERT_EQ(MAX_DOPPLER_FFT_SIZE, p_rdd_int_buff->xcp_doppler_idx);
   ASSERT_EQ(0U, p_rdd_int_buff->xcp_range_idx);
}

/**
 *  @b appl_sp_appl_second_pass_execute_02
 *  @n
 *      Verify execute skips XCP when range index is out of bounds.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_RangeOutOfRange_SkipsXcp)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx = 0U;
   p_rdd_int_buff->xcp_range_idx   = MAX_RANGE_BINS;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_Execute_fake.call_count);
   ASSERT_EQ(0U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Execute_fake.arg0_val == nullptr);
   ASSERT_EQ(0U, p_rdd_int_buff->xcp_doppler_idx);
   ASSERT_EQ(MAX_RANGE_BINS, p_rdd_int_buff->xcp_range_idx);
}

/**
 *  @b appl_sp_appl_second_pass_execute_03
 *  @n
 *      Verify execute skips XCP when second-pass execute API fails.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_ExecuteFail_DoesNotCallXcp)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx         = 0U;
   p_rdd_int_buff->xcp_range_idx           = 0U;
   p_rdd_int_buff->xcp_angle_idx           = 0U;
   Rdd_Second_Pass_Execute_fake.return_val = (Rdd_Second_Pass_Error_T)1;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_Execute_fake.call_count);
   ASSERT_EQ(0U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_Execute_fake.arg1_val == nullptr);
   ASSERT_EQ((Rdd_Second_Pass_Error_T)1, Rdd_Second_Pass_Execute_fake.return_val);
}

/**
 *  @b appl_sp_appl_second_pass_execute_04
 *  @n
 *      Verify execute calls XCP path when indices are valid and execute succeeds.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_ValidXcpIndex_CallsXcp)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx = 0U;
   p_rdd_int_buff->xcp_range_idx   = 0U;
   p_rdd_int_buff->xcp_angle_idx   = 0U;

   d2m_msg.payload.xcp_data.rdd1_xcp_dbin_est = 10;
   d2m_msg.payload.xcp_data.rdd1_xcp_rbin_est = 20;
   d2m_msg.payload.xcp_data.rdd1_xcp_rdop_amp = 30;
   rdd_data.cfar_nf_est[0][0]                 = 40;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_Execute_fake.call_count);
   ASSERT_EQ(1U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_XCP_Output_fake.arg0_val == nullptr);
   ASSERT_EQ(false, Rdd_Second_Pass_XCP_Output_fake.arg1_val == nullptr);
   ASSERT_EQ(0U, p_rdd_int_buff->xcp_doppler_idx);
   ASSERT_EQ(0U, p_rdd_int_buff->xcp_range_idx);
   ASSERT_EQ(0U, p_rdd_int_buff->xcp_angle_idx);
}

/**
 *  @b appl_sp_appl_second_pass_execute_05
 *  @n
 *      Verify XCP angle index is clamped to zero when it exceeds the valid angle-bin range.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_AngleOutOfRange_ClampsAngleIndexToZero)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx = 0U;
   p_rdd_int_buff->xcp_range_idx   = 0U;
   p_rdd_int_buff->xcp_angle_idx   = ANGLE_BINS_USED;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(0U, Rdd_Second_Pass_XCP_Output_fake.arg0_val->angle_idx);
}

/**
 *  @b appl_sp_appl_second_pass_execute_06
 *  @n
 *      Verify XCP success branch executes and updates XCP SNR output field.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_XcpSuccess_UpdatesSNR)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx       = 0U;
   p_rdd_int_buff->xcp_range_idx         = 0U;
   p_rdd_int_buff->xcp_angle_idx         = 0U;
   d2m_msg.payload.xcp_data.rdd2_xcp_snr = -1.0f;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(false, Rdd_Second_Pass_XCP_Output_fake.arg1_val == nullptr);
}

/**
 *  @b appl_sp_appl_second_pass_execute_07
 *  @n
 *      Verify XCP failure branch leaves range and range-rate outputs unchanged.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Appl_Second_Pass_Execute_XcpFail_LeavesOutputsUnchanged)
{
   RDD_Data_T rdd_data = {0};

   p_rdd_int_buff->xcp_doppler_idx            = 0U;
   p_rdd_int_buff->xcp_range_idx              = 0U;
   p_rdd_int_buff->xcp_angle_idx              = 0U;
   Rdd_Second_Pass_XCP_Output_fake.return_val = (Rdd_Second_Pass_Error_T)1;

   d2m_msg.payload.xcp_data.rdd2_xcp_range      = 111;
   d2m_msg.payload.xcp_data.rdd2_xcp_range_rate = 222;

   Appl_Second_Pass_Execute(&rdd_data);

   ASSERT_EQ(1U, Rdd_Second_Pass_XCP_Output_fake.call_count);
   ASSERT_EQ(111, d2m_msg.payload.xcp_data.rdd2_xcp_range);
   ASSERT_EQ(222, d2m_msg.payload.xcp_data.rdd2_xcp_range_rate);
   ASSERT_EQ(false, Rdd_Second_Pass_XCP_Output_fake.arg0_val == nullptr);
   ASSERT_EQ((Rdd_Second_Pass_Error_T)1, Rdd_Second_Pass_XCP_Output_fake.return_val);
}

/**
 *  @b appl_sp_calculate_xcp_output_01
 *  @n
 *      Verify negative block exponent shift uses right-shifted debug outputs.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Calculate_XCP_Output_NegativeBlockShift_RightShiftsDebugBins)
{
   RDD_Data_T rdd_data = {0};
   XCP_Data_T xcp_data = {0};

   rdd_data.nci_bexp[0][0]               = (uint16_t)(SHIFT_FACTOR_48 + 1);
   rdd_data.rdd1_max_per_range_bin[0][0] = 8U;
   rdd_data.rdd1_first_pass_thold[0][0]  = 4U;
   rdd_data.cfar_thold[0][0]             = 16U;
   rdd_data.cfar_nf_est[0][0]            = 2U;

   Calculate_XCP_Output(&rdd_data, &xcp_data, 0U);

   ASSERT_EQ(4U, xcp_data.mprb_abin[0]);
   ASSERT_EQ(2U, xcp_data.first_pass_abin[0]);
   ASSERT_EQ(8U, xcp_data.cfar_abin[0]);
   ASSERT_EQ(1U, xcp_data.cfar_nf_abin[0]);
}

/**
 *  @b appl_sp_calculate_xcp_output_02
 *  @n
 *      Verify a positive MPRB debug bin enters the max tracking path.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Calculate_XCP_Output_PositiveMprb_TracksDebugMaximum)
{
   RDD_Data_T rdd_data = {0};
   XCP_Data_T xcp_data = {0};

   rdd_data.nci_bexp[0][0]               = SHIFT_FACTOR_48;
   rdd_data.rdd1_max_per_range_bin[0][0] = 7U;
   rdd_data.rdd1_first_pass_thold[0][0]  = 3U;

   Calculate_XCP_Output(&rdd_data, &xcp_data, 0U);

   ASSERT_EQ(7U, xcp_data.mprb_abin[0]);
   ASSERT_EQ(3U, xcp_data.second_pass_abin[0]);
}

/**
 *  @b appl_sp_calculate_xcp_output_03
 *  @n
 *      Verify second-pass debug threshold is selected when it exceeds the BW-dependent threshold.
 */
TEST_F(Appl_Sp_Unit_Test_Suite, Calculate_XCP_Output_DebugThresholdAboveBwdep_StoresDebugThreshold)
{
   RDD_Data_T rdd_data = {0};
   XCP_Data_T xcp_data = {0};

   rdd_data.nci_bexp[0][0]              = SHIFT_FACTOR_48;
   rdd_data.rdd1_first_pass_thold[0][0] = 5U;
   rdd_data.bwdep_sensitivity_thold[0]  = 4U;

   Calculate_XCP_Output(&rdd_data, &xcp_data, 0U);

   ASSERT_EQ(5U, xcp_data.first_pass_abin[0]);
   ASSERT_EQ(5U, xcp_data.second_pass_abin[0]);
}
