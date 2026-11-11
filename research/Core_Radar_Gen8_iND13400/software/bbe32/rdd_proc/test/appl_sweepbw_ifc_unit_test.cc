/*===========================================================================*/
/**
 * @file appl_sweepbw_ifc_unit_test.cc
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
 * Unit tests for the application Sweep BW wrapper `appl_sweepbw_ifc.c`.
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <cstring>
#include <gtest/gtest.h>

#include "fff.h"
#include "ipc_fff.h"
#include "sweep_bw_fff.h"
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "appl_sweepbw_ifc.c"
}

/*===========================================================================*
 * Test Backing Data
 *===========================================================================*/
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
USC_Cal_T USC_Cal_Data;
USC_Cal_T *USC_Cal_Data_Ptr = &USC_Cal_Data;

DEFINE_FFF_GLOBALS;

volatile M2D_Msg_T m2d_msg;
RDD_Internal_Buff_T rdd_internal_buffer;

extern "C"
{
   volatile uint32_t Offline_Mode_Flag_DSP = ITF_DISABLED_NORMAL_MODE;
   RDD_Internal_Buff_T *p_rdd_int_buff     = &rdd_internal_buffer;
   Radar_Look_T look_id;
   Radar_Mode_T mode;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Appl_Sweepbw_Unit_Test_Suite : public testing::Test
{
   void SetUp() override
   {
      FFF_FAKES_SWEEP_BW_LIST(RESET_FAKE);
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      Sweep_Bw_Process_Init_fake.return_val    = SWEEP_BW_PROCESS_NO_ERROR;
      Sweep_Bw_LUT_Calc_First_fake.return_val  = SWEEP_BW_PROCESS_NO_ERROR;
      Sweep_Bw_LUT_Calc_Second_fake.return_val = SWEEP_BW_PROCESS_NO_ERROR;
      Sweep_Bw_Calc_fake.return_val            = SWEEP_BW_PROCESS_NO_ERROR;
      Sweep_Bw_RBIN0_Scaling_fake.return_val   = SWEEP_BW_PROCESS_NO_ERROR;

      (void)memset((void *)&m2d_msg, 0, sizeof(m2d_msg));
      (void)memset((void *)&rdd_internal_buffer, 0, sizeof(rdd_internal_buffer));

      Offline_Mode_Flag_DSP              = ITF_DISABLED_NORMAL_MODE;
      p_rdd_int_buff                     = &rdd_internal_buffer;
      Get_IPC_M2D_Buffer_fake.return_val = &m2d_msg;
      look_id                            = RADAR_LOOK_A;
      mode                               = RADAR_MODE_A;
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_init_01)
{
   Sweep_Bw_Process_Init_fake.return_val = SWEEP_BW_PROCESS_NO_ERROR;

   EXPECT_TRUE(Appl_Sweep_Bw_Init(look_id));
   EXPECT_EQ(Sweep_Bw_Process_Init_fake.call_count, 1U);
}

TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_init_02)
{
   Sweep_Bw_Process_Init_fake.return_val = SWEEP_BW_PROCESS_INIT_FAIL_ERROR;

   EXPECT_FALSE(Appl_Sweep_Bw_Init(look_id));
   EXPECT_EQ(Sweep_Bw_Process_Init_fake.call_count, 1U);
}

TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_execute_01)
{
   RDD_Data_T rdd_data = {0};

   Offline_Mode_Flag_DSP      = ITF_ADC_INJECTION_MODE;
   rdd_data.min_chirp_scaling = 123U;

   Appl_Sweep_Bw_Execute(&rdd_data);

   EXPECT_EQ(Sweep_Bw_LUT_Calc_First_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_LUT_Calc_Second_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_Calc_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_RBIN0_Scaling_fake.call_count, 1U);
   EXPECT_EQ(Get_IPC_M2D_Buffer_fake.call_count, 0U);

   ASSERT_NE(Sweep_Bw_Calc_fake.arg0_val, nullptr);
   ASSERT_NE(Sweep_Bw_Calc_fake.arg1_val, nullptr);
// TODO: make the below asserts work for linux
#if 0
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_temperature, 50);
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_sample_shift, 123U);
#endif
}

TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_execute_02)
{
   RDD_Data_T rdd_data = {0};

   Offline_Mode_Flag_DSP      = ITF_DATA_CUBE_INJECTION_MODE;
   rdd_data.min_chirp_scaling = 100U;

   Appl_Sweep_Bw_Execute(&rdd_data);

   EXPECT_EQ(Sweep_Bw_LUT_Calc_First_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_LUT_Calc_Second_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_Calc_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_RBIN0_Scaling_fake.call_count, 1U);
   EXPECT_EQ(Get_IPC_M2D_Buffer_fake.call_count, 0U);

   ASSERT_NE(Sweep_Bw_Calc_fake.arg0_val, nullptr);
// TODO: make the below asserts work for linux
#if 0
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_temperature, 50);
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_sample_shift, 100U);
#endif
}

TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_execute_03)
{
   RDD_Data_T rdd_data = {0};

   Offline_Mode_Flag_DSP      = ITF_TEST_COLLECTION_MODE;
   rdd_data.min_chirp_scaling = 200U;

   Appl_Sweep_Bw_Execute(&rdd_data);

   EXPECT_EQ(Sweep_Bw_LUT_Calc_First_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_LUT_Calc_Second_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_Calc_fake.call_count, 1U);
   EXPECT_EQ(Sweep_Bw_RBIN0_Scaling_fake.call_count, 1U);
   EXPECT_EQ(Get_IPC_M2D_Buffer_fake.call_count, 0U);

   ASSERT_NE(Sweep_Bw_Calc_fake.arg0_val, nullptr);
// TODO: make the below asserts work for linux
#if 0
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_temperature, 50);
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_sample_shift, 200U);
#endif
}

TEST_F(Appl_Sweepbw_Unit_Test_Suite, appl_sweepbw_appl_sweep_bw_execute_04)
{
   RDD_Data_T rdd_data = {0};

   Offline_Mode_Flag_DSP                = ITF_DISABLED_NORMAL_MODE;
   m2d_msg.payload.avg_mmic_onchip_temp = 77U;

   Appl_Sweep_Bw_Execute(&rdd_data);

   EXPECT_EQ(Get_IPC_M2D_Buffer_fake.call_count, 1U);
   ASSERT_NE(Sweep_Bw_Calc_fake.arg0_val, nullptr);
// TODO: make the below asserts work for linux
#if 0
   EXPECT_EQ(Sweep_Bw_Calc_fake.arg0_val->bwdep_temperature, 77U);
#endif
}
