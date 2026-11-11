/*===========================================================================*/
/**
 * @file stream_handler_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for checking the stream_handler.c file
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

#include "fff.h"
#include "interference_detection_algo_fake.h"
#include "ipc_fff.h"

#include "interference_detection_algo_interface.c"

/*===========================================================================*
 * Private Mocks
 *===========================================================================*/
ID_BB_Input_Params_T retn;
ID_Stream_T ID_logging;
D2M_Msg_T p_dss_to_mss_l3_fake;
ID_MDF_BB_Internals_T ID_BB_Internals_fake;
int Init_Parameters_custom_index;
M2D_Msg_T retn_fake;
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr   = &SMC_Cal_Data;
uint32_t g_id_init_call_count = 0U;
ID_INPUT_T id_input_data;

void ID_Init(void)
{
   g_id_init_call_count++;
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class algo_interface_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_INTERFERENCE_DETECTION_ALGO(RESET_FAKE);
      FFF_FAKES_IPC_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();
      Init_Parameters_custom_index = 2;
      g_id_init_call_count         = 0U;
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

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b algo_interface_sanity_check
 *  @n
 *      Test functionality to pop a stream out of the queue for a particular stream index
 */
TEST_F(algo_interface_UnitTestSuite, algo_interface_sanity_check)
{
   ASSERT_EQ(true, true);
}

TEST_F(algo_interface_UnitTestSuite, algo_interface_id_ptr_update_assigns_stream_pointers)
{
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);

   EXPECT_EQ(id_input_data.p_rdd_stream, &p_dss_to_mss_l3_fake.payload.rdd_stream_data);
   EXPECT_EQ(id_input_data.p_vse_stream, &retn_fake.payload.veh_data);
   EXPECT_EQ(id_input_data.p_id_stream, &p_dss_to_mss_l3_fake.payload.interference_detection_data);
}

ID_BB_Input_Params_T *Get_ID_Init_Parameters_custom_fake(void)
{
   if (Init_Parameters_custom_index == 1)
   {
      ID_logging.normalised_nf = 10;
      retn.id_logging_out_ptr  = NULL;
   }

   if (Init_Parameters_custom_index == 2)
   {
      ID_logging.normalised_nf = 10;
      retn.id_logging_out_ptr  = &ID_logging;
   }
   return (&retn);
}

volatile D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom_fake(void)
{
   return (&p_dss_to_mss_l3_fake);
}

ID_MDF_BB_Internals_T *Get_ID_BB_Internals_custom_fake(void)
{
   return (&ID_BB_Internals_fake);
}

ID_BB_Input_Params_T *Get_ID_Init_Parameters_wrapper_custom_fake(void)
{
   return (&retn);
}
volatile M2D_Msg_T *Get_IPC_M2D_Buffer_custom_fake(void)
{
   return (&retn_fake);
}

void Interference_Detection_custom_fake(void)
{
   ID_BB_Internals_fake.nf_mean_db_value[0]          = 12.5F;
   ID_BB_Internals_fake.nf_max_db_value[0]           = 18.0F;
   ID_BB_Internals_fake.nf_min_db_value[0]           = 8.75F;
   ID_BB_Internals_fake.interference_detected        = 1U;
   ID_BB_Internals_fake.interference_level           = 3U;
   ID_BB_Internals_fake.range_check_interference     = 1U;
   ID_BB_Internals_fake.normalised_nf                = 42.5F;
   ID_BB_Internals_fake.interference_health          = 2U;
   ID_BB_Internals_fake.interference_data_discard    = 1U;
   ID_BB_Internals_fake.id_version_re_release        = 7U;
   ID_BB_Internals_fake.id_version_branch_identifier = 4U;
   ID_BB_Internals_fake.id_version_minor             = 3U;
   ID_BB_Internals_fake.id_version_major             = 1U;
}

/*function ID_Init_BB_Params under test*/
TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Init_BB_Params)
{
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);
   retn_fake.payload.look_Info.look_type                = (Radar_Look_T)0U;
   Get_ID_Init_Parameters_fake.custom_fake              = Get_ID_Init_Parameters_custom_fake;
   Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.custom_fake = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom_fake;
   Get_IPC_M2D_Buffer_fake.custom_fake                  = Get_IPC_M2D_Buffer_custom_fake;

   ID_Init_BB_Params(&id_input_data);

   EXPECT_EQ(*retn.enable_id_ptr, k_enable_interference_det_smc[0]);
   EXPECT_EQ(*retn.id_start_rbin_ptr, k_interference_det_rbin_range_smc[0][0]);
   EXPECT_EQ(*retn.id_end_rbin_ptr, k_interference_det_rbin_range_smc[0][1]);
   EXPECT_EQ(*retn.low_degradation_thold_ptr, G_Low_Degradation_Thold);
   EXPECT_EQ(*retn.med_degradation_thold_ptr, G_Med_Degradation_Thold);
   EXPECT_EQ(*retn.high_degradation_thold_ptr, G_High_Degradation_Thold);
   EXPECT_EQ(retn.nf_est_ptr, (uint16_t *)(id_input_data.p_rdd_stream->rdd_data.cfar_nf_est));
   EXPECT_EQ(retn.min_chirp_scaling_ptr, &id_input_data.p_rdd_stream->rdd_data.min_chirp_scaling);
   EXPECT_EQ(retn.id_logging_out_ptr, (ID_Stream_T *)(id_input_data.p_id_stream));
   EXPECT_NE(retn.nf_est_ptr, nullptr);
   EXPECT_NE(retn.min_chirp_scaling_ptr, nullptr);
}

TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Init_BB_Params_second_look_type)
{
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);
   retn_fake.payload.look_Info.look_type                = (Radar_Look_T)1U;
   Get_ID_Init_Parameters_fake.custom_fake              = Get_ID_Init_Parameters_custom_fake;
   Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.custom_fake = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom_fake;
   Get_IPC_M2D_Buffer_fake.custom_fake                  = Get_IPC_M2D_Buffer_custom_fake;

   ID_Init_BB_Params(&id_input_data);

   EXPECT_EQ(*retn.enable_id_ptr, k_enable_interference_det_smc[1]);
   EXPECT_EQ(*retn.id_start_rbin_ptr, k_interference_det_rbin_range_smc[1][0]);
   EXPECT_EQ(*retn.id_end_rbin_ptr, k_interference_det_rbin_range_smc[1][1]);
}

/*function ID_Init_BB_Params under test*/
TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Populate_Logging_Structure)
{
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);
   retn_fake.payload.look_Info.look_type                = (Radar_Look_T)0U;
   Get_ID_Init_Parameters_fake.custom_fake              = Get_ID_Init_Parameters_custom_fake;
   Get_ID_BB_Internals_fake.custom_fake                 = Get_ID_BB_Internals_custom_fake;
   Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.custom_fake = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom_fake;
   Get_IPC_M2D_Buffer_fake.custom_fake                  = Get_IPC_M2D_Buffer_custom_fake;
   ID_Init_BB_Params(&id_input_data);
   ID_Stream_T *const l_id_logging_out_fake_ptr = (ID_Stream_T *)(retn.id_logging_out_ptr);
   uint16_t id_scan_index                       = p_dss_to_mss_l3_fake.payload.rdd_stream_data.look_data.scan_index;

   ID_Populate_Logging_Structure(&id_input_data);

   EXPECT_EQ(l_id_logging_out_fake_ptr->stream_hdr.scan_index, id_scan_index);
   EXPECT_EQ(l_id_logging_out_fake_ptr->nf_mean_db_value[0], ID_BB_Internals_fake.nf_mean_db_value[0]);
   EXPECT_EQ(l_id_logging_out_fake_ptr->nf_max_db_value[0], ID_BB_Internals_fake.nf_max_db_value[0]);
   EXPECT_EQ(l_id_logging_out_fake_ptr->nf_min_db_value[0], ID_BB_Internals_fake.nf_min_db_value[0]);
   EXPECT_EQ(l_id_logging_out_fake_ptr->interference_detected, ID_BB_Internals_fake.interference_detected);
   EXPECT_EQ(l_id_logging_out_fake_ptr->id_version_re_release, ID_BB_Internals_fake.id_version_re_release);
   EXPECT_EQ(l_id_logging_out_fake_ptr->id_version_branch_identifier, ID_BB_Internals_fake.id_version_branch_identifier);
   EXPECT_EQ(l_id_logging_out_fake_ptr->id_version_minor, ID_BB_Internals_fake.id_version_minor);
   EXPECT_EQ(l_id_logging_out_fake_ptr->id_version_major, ID_BB_Internals_fake.id_version_major);
   EXPECT_EQ(l_id_logging_out_fake_ptr->interference_level, ID_BB_Internals_fake.interference_level);
   EXPECT_EQ(l_id_logging_out_fake_ptr->range_check_interference, ID_BB_Internals_fake.range_check_interference);
   EXPECT_EQ(l_id_logging_out_fake_ptr->normalised_nf, ID_BB_Internals_fake.normalised_nf);
   EXPECT_EQ(l_id_logging_out_fake_ptr->interference_health, ID_BB_Internals_fake.interference_health);
   EXPECT_EQ(l_id_logging_out_fake_ptr->interference_data_discard, ID_BB_Internals_fake.interference_data_discard);
}

/*function ID_Init_BB_Params under test*/
TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Populate_Logging_Structure_Null)
{
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);
   Get_ID_Init_Parameters_fake.custom_fake      = Get_ID_Init_Parameters_custom_fake;
   Init_Parameters_custom_index                 = 1;
   ID_Stream_T *const l_id_logging_out_fake_ptr = nullptr;

   ID_Populate_Logging_Structure(&id_input_data);

   EXPECT_EQ(l_id_logging_out_fake_ptr, nullptr);
}

/*function ID_Clear_Logging_Data under test*/
TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Clear_Logging_Data)
{
   Get_ID_Init_Parameters_fake.custom_fake = Get_ID_Init_Parameters_custom_fake;
   Init_Parameters_custom_index            = 2;

   ID_Clear_Logging_Data();

   EXPECT_EQ(ID_logging.normalised_nf, 0);
}

/*function ID_Clear_Logging_Data under test*/
TEST_F(algo_interface_UnitTestSuite, algo_interface_ID_Clear_Logging_Data_Null)
{
   Get_ID_Init_Parameters_fake.custom_fake = Get_ID_Init_Parameters_custom_fake;
   Init_Parameters_custom_index            = 1;

   ID_Clear_Logging_Data();

   EXPECT_EQ(ID_logging.normalised_nf, 10);
}

TEST_F(algo_interface_UnitTestSuite, algo_interface_interference_detection_wrapper)
{
   ID_Stream_T *const l_id_stream = &p_dss_to_mss_l3_fake.payload.interference_detection_data;
   id_ptr_update(&retn_fake, &p_dss_to_mss_l3_fake, &id_input_data);

   memset(l_id_stream, 0xA5, sizeof(ID_Stream_T));
   p_dss_to_mss_l3_fake.payload.rdd_stream_data.look_data.scan_index = 321U;
   retn.id_logging_out_ptr                                           = l_id_stream;
   Get_ID_Init_Parameters_fake.custom_fake                           = Get_ID_Init_Parameters_wrapper_custom_fake;

   Get_IPC_M2D_Buffer_fake.custom_fake                  = Get_IPC_M2D_Buffer_custom_fake;
   Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.custom_fake = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom_fake;
   Get_ID_BB_Internals_fake.custom_fake                 = Get_ID_BB_Internals_custom_fake;
   Interference_Detection_fake.custom_fake              = Interference_Detection_custom_fake;

   retn_fake.payload.veh_data.vse_output.raw_speed_mps = 524270.0F;
   retn_fake.payload.look_Info.look_type               = (Radar_Look_T)0U;

   interference_detection_wrapper(&retn_fake, &p_dss_to_mss_l3_fake);
   ASSERT_EQ(g_id_init_call_count, 1U);
   ASSERT_EQ(Interference_Detection_fake.call_count, 1);
   EXPECT_EQ(l_id_stream->stream_hdr.scan_index, p_dss_to_mss_l3_fake.payload.rdd_stream_data.look_data.scan_index);
   EXPECT_EQ(l_id_stream->interference_detected, ID_BB_Internals_fake.interference_detected);
   EXPECT_EQ(l_id_stream->interference_level, ID_BB_Internals_fake.interference_level);
   EXPECT_EQ(l_id_stream->range_check_interference, ID_BB_Internals_fake.range_check_interference);
   EXPECT_EQ(l_id_stream->normalised_nf, ID_BB_Internals_fake.normalised_nf);
   EXPECT_EQ(l_id_stream->interference_health, ID_BB_Internals_fake.interference_health);
   EXPECT_EQ(l_id_stream->interference_data_discard, ID_BB_Internals_fake.interference_data_discard);
}
