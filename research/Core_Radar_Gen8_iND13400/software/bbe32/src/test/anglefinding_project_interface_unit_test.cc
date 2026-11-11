/*===========================================================================*/
/**
 * @file anglefinding_project_interface_unit_test.cc
 *
 * Unit tests for software/bbe32/src/anglefinding_project_interface.c
 *
 * Testable public functions:
 *   - Anglefinding_Memory_Init()           — allocates AF internal memory
 *   - Appl_Angle_Finding_Process()         — runs the full AF pipeline
 *   - Angle_Finding_Update_Metrics()       — computes timing metrics
 */
/*==========================================================================*/
#include <cstring>
#include <gtest/gtest.h>

#include "anglefinding_project_interface_fake.h"
#include "test_calibration_matrices.h"

extern "C"
{
#include "anglefinding_project_interface.c"
}

/*===========================================================================*
 * Test fixture
 *===========================================================================*/
SMC_Cal_T *SMC_Cal_Data_Ptr;
USC_Cal_T *USC_Cal_Data_Ptr;

static AF_Internal_Mem_Info_T *g_af_internal_mem_info_ptr = nullptr;
static size_t g_af_internal_mem_info_count                = 0U;
static float32_t *g_expected_az_coefficients_ptr          = nullptr;

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
static int32_t g_ds_timeout_num_det = 0;
static int32_t g_ds_set_num_det     = 15;

static AF_Retval_T DownselectionExecuteTimeout_Custom(AF_DownSelection_In_Out_Params_T *af_ds_inout_param)
{
   if ((nullptr != af_ds_inout_param) && (nullptr != af_ds_inout_param->af_det_ptr))
   {
      af_ds_inout_param->af_det_ptr->p_num_af_det = &g_ds_timeout_num_det;
      return AF_E_TIMEOUT;
   }
   return AF_E_PARAM;
}

static AF_Retval_T DownselectionExecuteSetNumDet_Custom(AF_DownSelection_In_Out_Params_T *af_ds_inout_param)
{
   if ((nullptr != af_ds_inout_param) && (nullptr != af_ds_inout_param->af_det_ptr))
   {
      af_ds_inout_param->af_det_ptr->p_num_af_det = &g_ds_set_num_det;
      return AF_E_OK;
   }
   return AF_E_PARAM;
}
#endif

static float32_t TimingCounterToSeconds_Custom(uint32_t counter)
{
   return ((float32_t)counter) * 0.001F;
}

static size_t GetAfInternalMemoryPointers_Custom(AF_Internal_Mem_Info_T **af_internal_mem_info_ptr)
{
   *af_internal_mem_info_ptr = g_af_internal_mem_info_ptr;
   return g_af_internal_mem_info_count;
}

static AF_Retval_T FailingAzimuthPassingElevation_Custom(float32_t *, float32_t *coefficients, size_t, size_t)
{
   return (coefficients == g_expected_az_coefficients_ptr) ? AF_E_PARAM : AF_E_OK;
}

class AngleFindingTest : public ::testing::Test
{
 protected:
   RDD_Data_T m_rdd_data   = {};
   Look_Data_T m_look_data = {};
   XCP_Data_T m_xcp_data   = {};
   XCP_Info_T m_xcp_info   = {
        .xcp_range_idx   = MAX_RANGE_BINS,
        .xcp_doppler_idx = MAX_DOPPLER_FFT_SIZE,
        .xcp_angle_idx   = ANGLE_BINS_USED,
   };
   float32_t m_veh_speed            = 0.0f;
   uint8_t m_radar_position         = 0U;
   Detection_Stream_T m_det_stream  = {};
   Detection_Debug_Stream_T m_debug = {};
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
   Down_selection_Stream_T m_downsel_stream = {};
#endif
   Angle_Data_XCP_T m_xcp_af    = {};
   Angle_Timing_Data_T m_timing = {};
#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
   Fascia_Comp_Data_T m_fascia_comp          = {};
   float32_t m_fascia_temp[AF_MAX_NUM_DET_L] = {};
#endif

   AF_Appl_Input_T m_appl_in   = {};
   AF_Appl_Output_T m_appl_out = {};

   Angle_Finding_Input_T m_af_in   = {};
   Angle_Finding_Output_T m_af_out = {};

   SMC_Cal_T SMC_Cal_Data             = {};
   USC_Cal_T USC_Cal_Data             = {};
   u8p0_T m_original_mode_smc         = 0U;
   u8p0_T m_original_is_uwb_smc[8][4] = {};
   uint8_t m_original_look_id         = 0U;
   Calib_Data_T m_calib_data          = {};

   void SetUp() override
   {
      RESET_FAKE(Get_af_input_data_ptr);
      RESET_FAKE(Get_af_output_data_ptr);
      RESET_FAKE(Angle_Finding_Execute);
      RESET_FAKE(Get_AF_Internal_Memory_Pointers);
      RESET_FAKE(Mem_Pool_Alloc);
      RESET_FAKE(AF_Get_Timing_Counter);
      RESET_FAKE(AF_Get_Timing_Delta);
      RESET_FAKE(Fake_Timing_Helpers_Get_Time_Sec_Float);
      RESET_FAKE(AF_Accumulate_Profiling_Counter);
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      RESET_FAKE(AF_Downselection_Execute);
#endif
#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
      RESET_FAKE(AF_Fascia_Compensation);
      fascia_temp = m_fascia_temp;
#endif
      FFF_RESET_HISTORY();

      SMC_Cal_Data_Ptr                                 = &SMC_Cal_Data;
      USC_Cal_Data_Ptr                                 = &USC_Cal_Data;
      g_af_internal_mem_info_ptr                       = nullptr;
      g_af_internal_mem_info_count                     = 0U;
      Get_AF_Internal_Memory_Pointers_fake.custom_fake = nullptr;

      /* Reset static counters in the production source */
      g_af_timeout_count  = 0U;
      g_af_xput_peak_time = 0U;

      /* Default: provide valid input/output pointers */
      m_appl_in.appl_rdd_data_ptr       = &m_rdd_data;
      m_appl_in.appl_look_data_ptr      = &m_look_data;
      m_appl_in.appl_xcp_data_ptr       = &m_xcp_data;
      m_appl_in.appl_xcp_info_data_ptr  = &m_xcp_info;
      m_appl_in.appl_veh_speed_ptr      = &m_veh_speed;
      m_appl_in.appl_radar_position_ptr = &m_radar_position;
      m_appl_in.calib_data_ptr          = &m_calib_data;

      m_radar_position = 1U;

      m_appl_out.appl_detection_stream_data_ptr = &m_det_stream;
      m_appl_out.appl_detection_debug_data_ptr  = &m_debug;
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      m_appl_out.appl_down_selection_stream_data_ptr = &m_downsel_stream;
      AF_Downselection_Execute_fake.return_val       = AF_E_OK;
      g_af_ds_start_time                             = 0U;
      g_af_downselection_xput_ctr                    = 0U;
      g_ds_timeout_num_det                           = 0;
      g_ds_set_num_det                               = 15;
#endif
      m_appl_out.appl_af_xcp_data_ptr    = &m_xcp_af;
      m_appl_out.appl_af_timing_data_ptr = &m_timing;

      /* Set up the fakes to return valid AF internal pointers */
      Get_af_input_data_ptr_fake.return_val  = &m_af_in;
      Get_af_output_data_ptr_fake.return_val = &m_af_out;

      /* Default: execute succeeds */
      Angle_Finding_Execute_fake.return_val = AF_E_OK;

      /* Timing helpers */
      AF_Get_Timing_Counter_fake.return_val                  = 0U;
      AF_Get_Timing_Delta_fake.return_val                    = 100U;
      Fake_Timing_Helpers_Get_Time_Sec_Float_fake.return_val = 0.001F;

      memset(&SMC_Cal_Data, 0, sizeof(SMC_Cal_Data));
      memset(&USC_Cal_Data, 0, sizeof(USC_Cal_Data));
   }
};

/*===========================================================================*
 * Appl_Angle_Finding_Process tests
 *===========================================================================*/

/* Verify that NULL appl_in returns AF_E_PARAM */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_NullApplIn_ReturnsParam)
{
   AF_Retval_T ret = Appl_Angle_Finding_Process(NULL, &m_appl_out);
   EXPECT_EQ(ret, AF_E_PARAM);
}

/* Verify that NULL appl_out returns AF_E_PARAM */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_NullApplOut_ReturnsParam)
{
   AF_Retval_T ret = Appl_Angle_Finding_Process(&m_appl_in, NULL);
   EXPECT_EQ(ret, AF_E_PARAM);
}

/* Verify that NULL AF input pointer returns AF_E_PARAM */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_NullAfInputPtr_ReturnsParam)
{
   Get_af_input_data_ptr_fake.return_val = NULL;
   AF_Retval_T ret                       = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_PARAM);
}

/* Verify that NULL AF output pointer returns AF_E_PARAM */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_NullAfOutputPtr_ReturnsParam)
{
   Get_af_output_data_ptr_fake.return_val = NULL;
   AF_Retval_T ret                        = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_PARAM);
}

/* Verify that NULL RDD data pointer in input causes AF_E_PARAM */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_NullRddData_ReturnsParam)
{
   m_appl_in.appl_rdd_data_ptr = NULL;
   AF_Retval_T ret             = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_PARAM);
}

/* Verify that with all valid pointers, Angle_Finding_Execute is called */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_ValidInputs_CallsExecute)
{
   AF_Retval_T ret = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(Angle_Finding_Execute_fake.call_count, 1U);
}

/* Verify that when execute returns timeout, the function still returns that code */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_ExecuteTimeout_ReturnsTimeout)
{
   Angle_Finding_Execute_fake.return_val = AF_E_TIMEOUT;
   AF_Retval_T ret                       = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_TIMEOUT);
}

/* Test that Angle_Finding_Determine_XCP_Mode returns false when XCP range/doppler index are both set to default values */
TEST_F(AngleFindingTest, Angle_Finding_Determine_XCP_Mode_test1)
{
   bool retval;
   retval = Angle_Finding_Determine_XCP_Mode(&m_appl_in);
   EXPECT_EQ(retval, false);
}

/* Test that Angle_Finding_Determine_XCP_Mode returns true when XCP range/doppler index are both set to non-default values */
TEST_F(AngleFindingTest, Angle_Finding_Determine_XCP_Mode_test2)
{
   bool retval;

   m_appl_in.appl_xcp_info_data_ptr->xcp_range_idx   = 0;
   m_appl_in.appl_xcp_info_data_ptr->xcp_doppler_idx = 0;

   retval = Angle_Finding_Determine_XCP_Mode(&m_appl_in);
   EXPECT_EQ(retval, true);
}

/* Verify the direct init path maps headers, interfaces and timing state */
TEST_F(AngleFindingTest, AngleFindingProcessInit_ValidInputs_MapsInterfaceState)
{
   m_look_data.look_id                   = 7U;
   m_look_data.look_index                = 3U;
   m_look_data.scan_index                = 11U;
   m_look_data.mid_dwell_nanosec         = 1234U;
   m_look_data.mid_dwell_sec             = 55U;
   m_look_data.mid_dwell_status          = 2U;
   m_rdd_data.rdd1_num_detect            = 4U;
   m_rdd_data.rdd2_num_detect            = 6U;
   m_appl_in.appl_doppler_start_time     = 90U;
   AF_Get_Timing_Counter_fake.return_val = 100U;
   AF_Get_Timing_Delta_fake.return_val   = 10U;

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_det_stream.stream_hdr.scan_index, m_look_data.scan_index);
   EXPECT_EQ(m_det_stream.stream_hdr.size, sizeof(Detection_Stream_T));
   EXPECT_EQ(m_debug.stream_hdr.scan_index, m_look_data.scan_index);
   EXPECT_EQ(m_debug.stream_hdr.size, sizeof(Detection_Debug_Stream_T));

   EXPECT_EQ(m_af_in.p_rdd1_bv, m_rdd_data.rdd1_bv);
   EXPECT_EQ(m_af_in.p_rdd2_range, m_rdd_data.rdd2_range);
   EXPECT_EQ(m_af_in.p_rdd1_num_detect, &m_rdd_data.rdd1_num_detect);
   EXPECT_EQ(m_af_in.p_rdd2_num_detect, &m_rdd_data.rdd2_num_detect);
   EXPECT_EQ(m_af_in.is_xcp_mode, false);
   EXPECT_EQ(m_af_in.p_veh_speed, &m_veh_speed);
   EXPECT_EQ(m_af_in.p_radar_position, &m_radar_position);

   EXPECT_EQ(m_af_out.afbb_det_output.af_data.p_num_af_det, &m_det_stream.num_af_det);
   EXPECT_EQ(m_af_out.afbb_det_output.af_data.p_dets, (AF_Detection_T *)m_det_stream.af_dets);
   EXPECT_EQ(m_af_out.afbb_det_output.af_data.p_debug_dets, m_debug.af_debug_detections);
   EXPECT_EQ(m_af_out.afbb_det_output.af_saturation_flag_ptr, &m_det_stream.af_diagnostics_info.af_saturation_flag);

   EXPECT_EQ(m_det_stream.det_list_property.look_type, m_look_data.look_id);
   EXPECT_EQ(m_det_stream.det_list_property.lookindex, m_look_data.look_index);
   EXPECT_EQ(m_det_stream.det_list_property.scanindex, m_look_data.scan_index);
   EXPECT_EQ(m_det_stream.det_list_property.num_fp_detections, m_rdd_data.rdd1_num_detect);
   EXPECT_EQ(m_det_stream.det_list_property.num_sp_detections, m_rdd_data.rdd2_num_detect);
   EXPECT_EQ(m_det_stream.det_list_property.detection_timestamp_ns, m_look_data.mid_dwell_nanosec);
   EXPECT_EQ(m_det_stream.det_list_property.detection_timestamp_sec, m_look_data.mid_dwell_sec);
   EXPECT_EQ(m_det_stream.det_list_property.timestamp_status, m_look_data.mid_dwell_status);

#if AF_TIMEOUT_ENABLE_L
   EXPECT_EQ(m_af_in.af_max_time, FRAME_TIME_PERIOD_CLKS - AF_POST_AF_RESERVED_TIME - 10U);
   EXPECT_EQ(AF_Get_Timing_Delta_fake.call_count, 1U);
#endif
}

TEST_F(AngleFindingTest, AngleFindingProcessInit_UwbLook_MapsUwbCalibrationMatrices)
{
   m_look_data.look_id = 1U;
   for (int i = 0; i < NUM_LOOKS; ++i)
   {
      k_isUWB_smc[i] = false;
   }
   k_isUWB_smc[m_look_data.look_id] = true;

   /* Initialize calibration matrices from pre-initialized test data using memcpy */
   memcpy(k_calmat1_ctx_UWB_usc, test_k_calmat1_ctx_UWB_usc, sizeof(k_calmat1_ctx_UWB_usc));
   memcpy(k_calmat1_crx_UWB_usc, test_k_calmat1_crx_UWB_usc, sizeof(k_calmat1_crx_UWB_usc));
   memcpy(k_calmat1_c1_UWB_usc, test_k_calmat1_c1_UWB_usc, sizeof(k_calmat1_c1_UWB_usc));
   memcpy(k_calmat2_ctx_UWB_usc, test_k_calmat2_ctx_UWB_usc, sizeof(k_calmat2_ctx_UWB_usc));
   memcpy(k_calmat2_crx_UWB_usc, test_k_calmat2_crx_UWB_usc, sizeof(k_calmat2_crx_UWB_usc));
   memcpy(k_calmat2_c1_UWB_usc, test_k_calmat2_c1_UWB_usc, sizeof(k_calmat2_c1_UWB_usc));

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_af_in.p_calmat1_ctx, &(k_calmat1_ctx_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_calmat1_crx, &(k_calmat1_crx_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_calmat1_c1, &(k_calmat1_c1_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_ctx, &(k_calmat2_ctx_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_crx, &(k_calmat2_crx_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_c1, &(k_calmat2_c1_UWB_usc[0][0]));
   EXPECT_EQ(m_af_in.p_gain_rolloff_az_recip, k_Gain_Rolloff_Az_Reciprocal_UWB_usc);
   EXPECT_EQ(m_af_in.p_gain_rolloff_el_recip, k_Gain_Rolloff_EL_Reciprocal_UWB_usc);

   /* Verify all matrix values are correctly mapped and not just default zeros */
   for (int row = 0; row < 4; ++row)
   {
      for (int col = 0; col < 8; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_ctx[row * 8 + col], test_k_calmat1_ctx_UWB_usc[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_ctx[row * 8 + col], test_k_calmat2_ctx_UWB_usc[row][col]);
      }
   }
   for (int row = 0; row < 8; ++row)
   {
      for (int col = 0; col < 16; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_crx[row * 16 + col], test_k_calmat1_crx_UWB_usc[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_crx[row * 16 + col], test_k_calmat2_crx_UWB_usc[row][col]);
      }
   }
   for (int row = 0; row < 32; ++row)
   {
      for (int col = 0; col < 64; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_c1[row * 64 + col], test_k_calmat1_c1_UWB_usc[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_c1[row * 64 + col], test_k_calmat2_c1_UWB_usc[row][col]);
      }
   }
}

TEST_F(AngleFindingTest, AngleFindingProcessInit_NonUwbLook_MapsUscCalibrationMatrices)
{
   m_look_data.look_id = 1U;
   for (int i = 0; i < NUM_LOOKS; ++i)
   {
      k_isUWB_smc[i] = true;
   }
   k_isUWB_smc[m_look_data.look_id] = false;

   /* Initialize calibration matrices from pre-initialized test data using memcpy */
   memcpy(k_calmat1_ctx_USC, test_k_calmat1_ctx_USC, sizeof(k_calmat1_ctx_USC));
   memcpy(k_calmat1_crx_USC, test_k_calmat1_crx_USC, sizeof(k_calmat1_crx_USC));
   memcpy(k_calmat1_c1_USC, test_k_calmat1_c1_USC, sizeof(k_calmat1_c1_USC));
   memcpy(k_calmat2_ctx_USC, test_k_calmat2_ctx_USC, sizeof(k_calmat2_ctx_USC));
   memcpy(k_calmat2_crx_USC, test_k_calmat2_crx_USC, sizeof(k_calmat2_crx_USC));
   memcpy(k_calmat2_c1_USC, test_k_calmat2_c1_USC, sizeof(k_calmat2_c1_USC));

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_af_in.p_calmat1_ctx, &(k_calmat1_ctx_USC[0][0]));
   EXPECT_EQ(m_af_in.p_calmat1_crx, &(k_calmat1_crx_USC[0][0]));
   EXPECT_EQ(m_af_in.p_calmat1_c1, &(k_calmat1_c1_USC[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_ctx, &(k_calmat2_ctx_USC[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_crx, &(k_calmat2_crx_USC[0][0]));
   EXPECT_EQ(m_af_in.p_calmat2_c1, &(k_calmat2_c1_USC[0][0]));
   EXPECT_EQ(m_af_in.p_gain_rolloff_az_recip, k_Gain_Rolloff_Az_Reciprocal_USC);
   EXPECT_EQ(m_af_in.p_gain_rolloff_el_recip, k_Gain_Rolloff_EL_Reciprocal_USC);

   /* Verify all matrix values are correctly mapped and not just default zeros */
   for (int row = 0; row < 4; ++row)
   {
      for (int col = 0; col < 8; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_ctx[row * 8 + col], test_k_calmat1_ctx_USC[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_ctx[row * 8 + col], test_k_calmat2_ctx_USC[row][col]);
      }
   }
   for (int row = 0; row < 8; ++row)
   {
      for (int col = 0; col < 16; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_crx[row * 16 + col], test_k_calmat1_crx_USC[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_crx[row * 16 + col], test_k_calmat2_crx_USC[row][col]);
      }
   }
   for (int row = 0; row < 32; ++row)
   {
      for (int col = 0; col < 64; ++col)
      {
         EXPECT_FLOAT_EQ(m_af_in.p_calmat1_c1[row * 64 + col], test_k_calmat1_c1_USC[row][col]);
         EXPECT_FLOAT_EQ(m_af_in.p_calmat2_c1[row * 64 + col], test_k_calmat2_c1_USC[row][col]);
      }
   }
}

/*===========================================================================*
 * Angle_Finding_Update_Metrics tests
 *===========================================================================*/

/* Verify that on AF_E_OK status, timeout count is not incremented */
TEST_F(AngleFindingTest, UpdateMetrics_NoTimeout_CountNotIncremented)
{
   /* Reset static timeout count by setting initial value */
   m_det_stream.af_diagnostics_info.af_timeout_count = 0U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_EQ(m_det_stream.af_diagnostics_info.af_timeout_count, 0U);
}

/* Verify that on AF_E_TIMEOUT status, timeout count is incremented */
TEST_F(AngleFindingTest, UpdateMetrics_Timeout_CountIncremented)
{
   /* Reset static timeout count by setting initial value */
   m_det_stream.af_diagnostics_info.af_timeout_count = 0U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_TIMEOUT);
   EXPECT_EQ(m_det_stream.af_diagnostics_info.af_timeout_count, 1U);
}

/* Verify that timing data is populated */
TEST_F(AngleFindingTest, UpdateMetrics_PopulatesTimingData)
{
   Fake_Timing_Helpers_Get_Time_Sec_Float_fake.return_val = 0.005f;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_EQ(Fake_Timing_Helpers_Get_Time_Sec_Float_fake.call_count, 12U);
   EXPECT_FLOAT_EQ(m_appl_out.appl_af_timing_data_ptr->af_xput_inst, 0.005f);
}

/* Verify that scan index is propagated to timing data */
TEST_F(AngleFindingTest, UpdateMetrics_PropagatesScanIndex)
{
   m_det_stream.stream_hdr.scan_index = 42U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_EQ(m_timing.af_timing_scan_index, 42U);
}

/* Verify that num_af_det is synced to debug stream */
TEST_F(AngleFindingTest, UpdateMetrics_SyncsNumAfDetToDebug)
{
   m_det_stream.num_af_det = 10U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_EQ(m_debug.num_af_det, 10U);
   EXPECT_EQ(m_timing.num_af_det, 10U);
}

/*===========================================================================*
 * Anglefinding_Memory_Init tests
 *===========================================================================*/

/* Verify successful memory init when all allocations succeed */
TEST_F(AngleFindingTest, MemoryInit_AllAllocSuccess_ReturnsSuccess)
{
   void *dram_addr                   = nullptr;
   void *sram_addr                   = nullptr;
   AF_Internal_Mem_Info_T mem_info[] = {
      {.addr_ptr = &dram_addr, .size = 64U, .info = AF_MEMPOOL_DRAM},
      {.addr_ptr = &sram_addr, .size = 32U, .info = AF_MEMPOOL_SRAM},
   };

   g_af_internal_mem_info_ptr                       = mem_info;
   g_af_internal_mem_info_count                     = 2U;
   Get_AF_Internal_Memory_Pointers_fake.custom_fake = GetAfInternalMemoryPointers_Custom;
   Mem_Pool_Alloc_fake.return_val                   = MEM_POOL_SUCCESS;

   Mem_Pool_T dram_pool = {};
   Mem_Pool_T sram_pool = {};

   Memory_Pool_Return_T ret = Anglefinding_Memory_Init(&dram_pool, &sram_pool);

   EXPECT_EQ(ret, MEM_POOL_SUCCESS);
   EXPECT_EQ(Mem_Pool_Alloc_fake.call_count, 2U);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg0_history[0], &dram_pool);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg0_history[1], &sram_pool);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg1_history[0], 64U);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg1_history[1], 32U);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg2_history[0], &dram_addr);
   EXPECT_EQ(Mem_Pool_Alloc_fake.arg2_history[1], &sram_addr);
}

/* Verify that NULL addr_ptr in memory info causes failure */
TEST_F(AngleFindingTest, MemoryInit_NullAddrPtr_ReturnsFailure)
{
   AF_Internal_Mem_Info_T mem_info = {.addr_ptr = NULL, .size = 64U, .info = AF_MEMPOOL_DRAM};

   g_af_internal_mem_info_ptr                       = &mem_info;
   g_af_internal_mem_info_count                     = 1U;
   Get_AF_Internal_Memory_Pointers_fake.custom_fake = GetAfInternalMemoryPointers_Custom;

   Mem_Pool_T dram_pool     = {};
   Mem_Pool_T sram_pool     = {};
   Memory_Pool_Return_T ret = Anglefinding_Memory_Init(&dram_pool, &sram_pool);
   EXPECT_EQ(ret, MEM_POOL_FAILURE);
   EXPECT_EQ(Mem_Pool_Alloc_fake.call_count, 0U);
}

/* Verify zero-sized memory entries fail before allocation */
TEST_F(AngleFindingTest, MemoryInit_ZeroSize_ReturnsFailure)
{
   void *dram_addr                 = nullptr;
   AF_Internal_Mem_Info_T mem_info = {.addr_ptr = &dram_addr, .size = 0U, .info = AF_MEMPOOL_DRAM};

   g_af_internal_mem_info_ptr                       = &mem_info;
   g_af_internal_mem_info_count                     = 1U;
   Get_AF_Internal_Memory_Pointers_fake.custom_fake = GetAfInternalMemoryPointers_Custom;

   Mem_Pool_T dram_pool     = {};
   Mem_Pool_T sram_pool     = {};
   Memory_Pool_Return_T ret = Anglefinding_Memory_Init(&dram_pool, &sram_pool);

   EXPECT_EQ(ret, MEM_POOL_FAILURE);
   EXPECT_EQ(Mem_Pool_Alloc_fake.call_count, 0U);
}

/* Verify allocation failures propagate out of the init loop */
TEST_F(AngleFindingTest, MemoryInit_AllocFailure_ReturnsFailure)
{
   void *dram_addr                 = nullptr;
   AF_Internal_Mem_Info_T mem_info = {.addr_ptr = &dram_addr, .size = 64U, .info = AF_MEMPOOL_DRAM};

   g_af_internal_mem_info_ptr                       = &mem_info;
   g_af_internal_mem_info_count                     = 1U;
   Get_AF_Internal_Memory_Pointers_fake.custom_fake = GetAfInternalMemoryPointers_Custom;
   Mem_Pool_Alloc_fake.return_val                   = MEM_POOL_FAILURE;

   Mem_Pool_T dram_pool     = {};
   Mem_Pool_T sram_pool     = {};
   Memory_Pool_Return_T ret = Anglefinding_Memory_Init(&dram_pool, &sram_pool);

   EXPECT_EQ(ret, MEM_POOL_FAILURE);
   EXPECT_EQ(Mem_Pool_Alloc_fake.call_count, 1U);
}

/* Verify invalid memory pool selectors fail */
TEST_F(AngleFindingTest, MemoryInit_InvalidPoolType_ReturnsFailure)
{
   void *dram_addr                 = nullptr;
   AF_Internal_Mem_Info_T mem_info = {.addr_ptr = &dram_addr, .size = 64U, .info = AF_MEMPOOL_DISABLE};

   g_af_internal_mem_info_ptr                       = &mem_info;
   g_af_internal_mem_info_count                     = 1U;
   Get_AF_Internal_Memory_Pointers_fake.custom_fake = GetAfInternalMemoryPointers_Custom;

   Mem_Pool_T dram_pool     = {};
   Mem_Pool_T sram_pool     = {};
   Memory_Pool_Return_T ret = Anglefinding_Memory_Init(&dram_pool, &sram_pool);

   EXPECT_EQ(ret, MEM_POOL_FAILURE);
   EXPECT_EQ(Mem_Pool_Alloc_fake.call_count, 0U);
}

/*===========================================================================*
 * Angle_Finding_Process_Init NULL Check tests
 *===========================================================================*/
TEST_F(AngleFindingTest, AngleFinding_ProcessInit_AllNullPtrCombinations)
{
   /* Array of valid pointers for each of 10 parameters */
   void *valid_ptrs[] = {(void *)&m_rdd_data,  (void *)&m_look_data,      (void *)&m_xcp_data,   (void *)&m_xcp_info,
                         (void *)&m_veh_speed, (void *)&m_radar_position, (void *)&m_det_stream, (void *)&m_xcp_af,
                         (void *)&m_debug,     (void *)&m_timing};

   for (int mask = (1 << 10) - 1; mask > 0; mask &= (mask << 1))
   {
      m_appl_in.appl_rdd_data_ptr               = (mask & (1 << 0)) ? (RDD_Data_T *)valid_ptrs[0] : NULL;
      m_appl_in.appl_look_data_ptr              = (mask & (1 << 1)) ? (Look_Data_T *)valid_ptrs[1] : NULL;
      m_appl_in.appl_xcp_data_ptr               = (mask & (1 << 2)) ? (XCP_Data_T *)valid_ptrs[2] : NULL;
      m_appl_in.appl_xcp_info_data_ptr          = (mask & (1 << 3)) ? (XCP_Info_T *)valid_ptrs[3] : NULL;
      m_appl_in.appl_veh_speed_ptr              = (mask & (1 << 4)) ? (float32_t *)valid_ptrs[4] : NULL;
      m_appl_in.appl_radar_position_ptr         = (mask & (1 << 5)) ? (uint8_t *)valid_ptrs[5] : NULL;
      m_appl_out.appl_detection_stream_data_ptr = (mask & (1 << 6)) ? (Detection_Stream_T *)valid_ptrs[6] : NULL;
      m_appl_out.appl_af_xcp_data_ptr           = (mask & (1 << 7)) ? (Angle_Data_XCP_T *)valid_ptrs[7] : NULL;
      m_appl_out.appl_detection_debug_data_ptr  = (mask & (1 << 8)) ? (Detection_Debug_Stream_T *)valid_ptrs[8] : NULL;
      m_appl_out.appl_af_timing_data_ptr        = (mask & (1 << 9)) ? (Angle_Timing_Data_T *)valid_ptrs[9] : NULL;

      AF_Retval_T process_init_return = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

      /* When all 10 bits are set (mask == 1023), all pointers are valid → AF_E_OK */
      if (mask == ((1 << 10) - 1))
      {
         EXPECT_EQ(process_init_return, AF_E_OK);
      }
      else
      {
         /* Otherwise, at least one pointer is NULL → AF_E_PARAM */
         EXPECT_EQ(process_init_return, AF_E_PARAM);
      }
   }
}

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
/*===========================================================================*
 * Fascia compensation tests
 *===========================================================================*/
TEST_F(AngleFindingTest, QueryFasciaMode_ReturnsExpectedForSupportedModes)
{
   const struct
   {
      FC_Enable_Flag_T input_mode;
      bool az_expected;
      bool el_expected;
      bool roll_expected;
   } test_vect[] = {
      /* clang-format off */
      /* input_mode          az_exp el_exp roll_exp */
      {NO_SLOPE_CORRECTION,  false, false, false},
      {FC_ALL_DIRECTIONS,    true,  true,  true},
      {FC_AZIMUTH,           true,  false, false},
      {FC_ELEVATION,         false, true,  false},
      {FC_ROLL,              false, false, true},
      {FC_AZIMUTH_ELEVATION, true,  true,  false},
      {FC_AZIMUTH_ROLL,      true,  false, true},
      {FC_ELEVATION_ROLL,    false, true,  true},
      {FC_MAX_NUM_MODES,     false, false, false},
      {(FC_Enable_Flag_T)99, false, false, false},
      /* clang-format on */
   };

   for (int i = 0; i < NUM_ELEMS(test_vect); i++)
   {
      FC_Slope_Axis_Select_T output;
      memset(&output, 0, sizeof(output));
      Query_Fascia_Mode(test_vect[i].input_mode, &output);
      EXPECT_EQ(output.az_enabled, test_vect[i].az_expected) << "for i = " << i;
      EXPECT_EQ(output.el_enabled, test_vect[i].el_expected) << "for i = " << i;
      EXPECT_EQ(output.roll_enabled, test_vect[i].roll_expected) << "for i = " << i;
   }
}

TEST_F(AngleFindingTest, ApplExecuteFasciaCompensation_NoSlopeCorrection_SkipsAlgorithm)
{
   m_fascia_comp.axis_enable                              = NO_SLOPE_CORRECTION;
   m_det_stream.det_list_property.slope_correction_status = FS_AZ_EL_EXECUTED;
   m_det_stream.num_af_det                                = 2U;

   Appl_Execute_Fascia_Compensation(&m_fascia_comp, &m_appl_out);

   EXPECT_EQ(AF_Fascia_Compensation_fake.call_count, 0U);
   EXPECT_EQ(m_det_stream.det_list_property.slope_correction_status, FS_NO_SLOPE_CORRECTION);
}

TEST_F(AngleFindingTest, ApplExecuteFasciaCompensation_AzimuthAndElevation_UpdateStatus)
{
   m_det_stream.num_af_det       = 3U;
   m_det_stream.af_dets[0].theta = 1.0F;
   m_det_stream.af_dets[1].theta = 2.0F;
   m_det_stream.af_dets[2].theta = 3.0F;
   m_det_stream.af_dets[0].phi   = 4.0F;
   m_det_stream.af_dets[1].phi   = 5.0F;
   m_det_stream.af_dets[2].phi   = 6.0F;

   m_fascia_comp.axis_enable              = FC_AZIMUTH_ELEVATION;
   AF_Fascia_Compensation_fake.return_val = AF_E_OK;

   Appl_Execute_Fascia_Compensation(&m_fascia_comp, &m_appl_out);

   EXPECT_EQ(AF_Fascia_Compensation_fake.call_count, 2U);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg2_history[0], 3U);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg3_history[0], AF_MAX_NUM_FASCIA_COEF);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg1_history[0], m_fascia_comp.az_coefficients);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg1_history[1], m_fascia_comp.el_coefficients);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg0_history[0], fascia_temp);
   EXPECT_EQ(AF_Fascia_Compensation_fake.arg0_history[1], fascia_temp);
   EXPECT_EQ(m_det_stream.det_list_property.slope_correction_status, FS_AZ_EL_EXECUTED);
}

TEST_F(AngleFindingTest, ApplExecuteFasciaCompensation_AzimuthFailure_ElevationSuccess_OnlySetsElevation)
{
   m_det_stream.num_af_det                 = 1U;
   m_fascia_comp.axis_enable               = FC_AZIMUTH_ELEVATION;
   g_expected_az_coefficients_ptr          = m_fascia_comp.az_coefficients;
   AF_Fascia_Compensation_fake.custom_fake = FailingAzimuthPassingElevation_Custom;

   Appl_Execute_Fascia_Compensation(&m_fascia_comp, &m_appl_out);

   EXPECT_EQ(AF_Fascia_Compensation_fake.call_count, 2U);
   EXPECT_EQ(m_det_stream.det_list_property.slope_correction_status, FS_EL_EXECUTED);
}
#endif

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
/*===========================================================================*
 * AF_Downselection_Init NULL Check tests
 *===========================================================================*/
TEST_F(AngleFindingTest, AFDownselectionInit_AllNullPtrCombinations)
{
   AF_DownSelection_In_Out_Params_T ds_inout_param = {};
   Downselection_Cal_T ds_cal                      = {};
   Vehicle_Configuration_Cal_T veh_conf_cal        = {};
   Secondpass_Threshold_Cal_T sp_threshold_cal     = {};
   Down_selection_Stream_T downsel_stream          = {};

   m_appl_out.appl_down_selection_stream_data_ptr = &downsel_stream;

   /* Array of valid pointers for each of 11 internal checks */
   void *valid_ptrs[] = {
      (void *)&ds_inout_param, (void *)&ds_cal,         (void *)&veh_conf_cal, (void *)&sp_threshold_cal,
      (void *)&m_appl_in,      (void *)&m_look_data,    (void *)&m_veh_speed,  (void *)&m_radar_position,
      (void *)&m_appl_out,     (void *)&downsel_stream, (void *)&m_af_out,
   };

   for (int mask = (1 << 11) - 1; mask > 0; mask &= (mask << 1))
   {
      AF_DownSelection_In_Out_Params_T *ds_inout_param_ptr =
         (mask & (1 << 0)) ? (AF_DownSelection_In_Out_Params_T *)valid_ptrs[0] : NULL;
      Downselection_Cal_T *ds_cal_ptr                  = (mask & (1 << 1)) ? (Downselection_Cal_T *)valid_ptrs[1] : NULL;
      Vehicle_Configuration_Cal_T *veh_conf_cal_ptr    = (mask & (1 << 2)) ? (Vehicle_Configuration_Cal_T *)valid_ptrs[2] : NULL;
      Secondpass_Threshold_Cal_T *sp_threshold_cal_ptr = (mask & (1 << 3)) ? (Secondpass_Threshold_Cal_T *)valid_ptrs[3] : NULL;

      AF_Appl_Input_T *appl_in_ptr      = (mask & (1 << 4)) ? (AF_Appl_Input_T *)valid_ptrs[4] : NULL;
      m_appl_in.appl_look_data_ptr      = (mask & (1 << 5)) ? (Look_Data_T *)valid_ptrs[5] : NULL;
      m_appl_in.appl_veh_speed_ptr      = (mask & (1 << 6)) ? (float32_t *)valid_ptrs[6] : NULL;
      m_appl_in.appl_radar_position_ptr = (mask & (1 << 7)) ? (uint8_t *)valid_ptrs[7] : NULL;

      AF_Appl_Output_T *appl_out_ptr                 = (mask & (1 << 8)) ? (AF_Appl_Output_T *)valid_ptrs[8] : NULL;
      m_appl_out.appl_down_selection_stream_data_ptr = (mask & (1 << 9)) ? (Down_selection_Stream_T *)valid_ptrs[9] : NULL;

      Get_af_output_data_ptr_fake.return_val = (mask & (1 << 10)) ? (Angle_Finding_Output_T *)valid_ptrs[10] : NULL;

      AF_Retval_T process_init_return =
         AF_Downselection_Init(ds_inout_param_ptr, ds_cal_ptr, veh_conf_cal_ptr, sp_threshold_cal_ptr, appl_in_ptr, appl_out_ptr);

      /* When all bits are set, all pointers are valid -> AF_E_OK */
      if (mask == ((1 << 11) - 1))
      {
         EXPECT_EQ(process_init_return, AF_E_OK);
      }
      else
      {
         /* Otherwise, at least one required pointer is NULL -> AF_E_PARAM */
         EXPECT_EQ(process_init_return, AF_E_PARAM);
      }
   }
}

/*
 * Verify that the downselection stream header is initialized with
 * the current scan index and correct stream size.
 */
TEST_F(AngleFindingTest, AFDownselectionInit_StreamHeaderPopulated)
{
   AF_DownSelection_In_Out_Params_T ds_inout_param = {};
   Downselection_Cal_T ds_cal                      = {};
   Vehicle_Configuration_Cal_T veh_conf_cal        = {};
   Secondpass_Threshold_Cal_T sp_threshold_cal     = {};

   m_look_data.scan_index = 42U;

   const AF_Retval_T ret =
      AF_Downselection_Init(&ds_inout_param, &ds_cal, &veh_conf_cal, &sp_threshold_cal, &m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_downsel_stream.stream_hdr.scan_index, 42U);
   EXPECT_EQ(m_downsel_stream.stream_hdr.size, sizeof(Down_selection_Stream_T));
}
/*
 * Verify that look metadata, timestamps, and detection counts are
 * propagated from the application input structures into the
 * downselection stream properties.
 */
TEST_F(AngleFindingTest, AFDownselectionInit_MetadataPropagates)
{
   AF_DownSelection_In_Out_Params_T ds_inout_param = {};
   Downselection_Cal_T ds_cal                      = {};
   Vehicle_Configuration_Cal_T veh_conf_cal        = {};
   Secondpass_Threshold_Cal_T sp_threshold_cal     = {};

   m_look_data.look_id           = 3U;
   m_look_data.look_index        = 5U;
   m_look_data.scan_index        = 7U;
   m_look_data.mid_dwell_nanosec = 123456U;
   m_look_data.mid_dwell_sec     = 100U;
   m_look_data.mid_dwell_status  = 1U;
   m_rdd_data.rdd1_num_detect    = 10U;
   m_rdd_data.rdd2_num_detect    = 20U;

   /* angle finding stream : det list property data mapping */
   m_det_stream.det_list_property.look_type               = m_look_data.look_id;
   m_det_stream.det_list_property.lookindex               = m_look_data.look_index;
   m_det_stream.det_list_property.scanindex               = m_look_data.scan_index;
   m_det_stream.det_list_property.num_fp_detections       = m_rdd_data.rdd1_num_detect;
   m_det_stream.det_list_property.num_sp_detections       = m_rdd_data.rdd2_num_detect;
   m_det_stream.det_list_property.detection_timestamp_ns  = m_look_data.mid_dwell_nanosec;
   m_det_stream.det_list_property.detection_timestamp_sec = m_look_data.mid_dwell_sec;
   m_det_stream.det_list_property.timestamp_status        = m_look_data.mid_dwell_status;

   const AF_Retval_T ret =
      AF_Downselection_Init(&ds_inout_param, &ds_cal, &veh_conf_cal, &sp_threshold_cal, &m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_downsel_stream.det_list_property.look_type, 3U);
   EXPECT_EQ(m_downsel_stream.det_list_property.lookindex, 5U);
   EXPECT_EQ(m_downsel_stream.det_list_property.scanindex, 7U);
   EXPECT_EQ(m_downsel_stream.det_list_property.detection_timestamp_ns, 123456U);
   EXPECT_EQ(m_downsel_stream.det_list_property.detection_timestamp_sec, 100U);
   EXPECT_EQ(m_downsel_stream.det_list_property.timestamp_status, 1U);
   EXPECT_EQ(m_downsel_stream.det_list_property.num_fp_detections, 10U);
   EXPECT_EQ(m_downsel_stream.det_list_property.num_sp_detections, 20U);
}
/*
 * Verify that downselection initialization captures the current
 * timing counter value and resets throughput tracking variables.
 * This ensures profiling measurements start from a known state
 * for the current downselection execution.
 */
TEST_F(AngleFindingTest, AFDownselectionInit_CapturesStartTime)
{
   AF_DownSelection_In_Out_Params_T ds_inout_param = {};
   Downselection_Cal_T ds_cal                      = {};
   Vehicle_Configuration_Cal_T veh_conf_cal        = {};
   Secondpass_Threshold_Cal_T sp_threshold_cal     = {};

   AF_Get_Timing_Counter_fake.return_val = 12345U;

   const AF_Retval_T ret =
      AF_Downselection_Init(&ds_inout_param, &ds_cal, &veh_conf_cal, &sp_threshold_cal, &m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(AF_Get_Timing_Counter_fake.call_count, 1U);
   EXPECT_EQ(g_af_ds_start_time, 12345U);
   EXPECT_EQ(g_af_downselection_xput_ctr, 0U);
}
/*
 * Verify that an initialization failure caused by an invalid
 * output data pointer results in AF_E_PARAM being returned.
 * This ensures parameter validation errors are detected early
 * and downselection execution is not attempted with invalid data.
 */
TEST_F(AngleFindingTest, ApplDownSelectionProcess_InitFailure_ReturnsParamError)
{
   Get_af_output_data_ptr_fake.return_val = NULL;

   const AF_Retval_T ret = Appl_Down_Selection_Process(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_PARAM);
   EXPECT_EQ(AF_Downselection_Execute_fake.call_count, 0U);
}
/*
 * Verify that the return status from AF_Downselection_Execute()
 * is propagated unchanged to the application layer.
 * This ensures timeout and execution failures are correctly
 * reported to the caller for handling and diagnostics.
 */
TEST_F(AngleFindingTest, ApplDownSelectionProcess_ExecuteStatusPropagates)
{
   AF_Get_Timing_Counter_fake.return_val = 12345U;

   AF_Downselection_Execute_fake.custom_fake = DownselectionExecuteTimeout_Custom;

   const AF_Retval_T ret = Appl_Down_Selection_Process(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_TIMEOUT);
   EXPECT_EQ(AF_Downselection_Execute_fake.call_count, 1U);
}
/*
 * Verify that profiling counters are accumulated after a
 * successful downselection execution using the captured
 * start-time information.
 */
TEST_F(AngleFindingTest, ApplDownSelectionProcess_AccumulatesProfilingCounter)
{
   constexpr uint32_t doppler_start = 100U;

   m_appl_in.appl_doppler_start_time         = doppler_start;
   AF_Get_Timing_Counter_fake.return_val     = 77U;
   AF_Downselection_Execute_fake.custom_fake = DownselectionExecuteSetNumDet_Custom;

   const AF_Retval_T ret = Appl_Down_Selection_Process(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(AF_Accumulate_Profiling_Counter_fake.call_count, 1U);
   EXPECT_EQ(AF_Accumulate_Profiling_Counter_fake.arg0_history[0], 77U);
}
/*
 * Verify that the measured downselection execution time is converted to seconds and populated in the timing output structure.
 * Verify that the number of detections produced during downselection is propagated to the timing and statistics output structure.
 * This ensures execution metrics accurately reflect the amount of processed detection data.
 * This ensures throughput reporting and performance monitoring
 * reflect the actual execution duration.
 */
TEST_F(AngleFindingTest, ApplDownSelectionProcess_PopulatesTimingOutput)
{
   Fake_Timing_Helpers_Get_Time_Sec_Float_fake.return_val = 0.050F;
   AF_Get_Timing_Counter_fake.return_val                  = 12345U;
   AF_Downselection_Execute_fake.custom_fake              = DownselectionExecuteSetNumDet_Custom;

   const AF_Retval_T ret = Appl_Down_Selection_Process(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_FLOAT_EQ(m_timing.af_xput_downselection, 0.050F);
   EXPECT_EQ(Fake_Timing_Helpers_Get_Time_Sec_Float_fake.call_count, 1U);
   EXPECT_EQ(m_timing.num_af_downselection, 15U);
}
/*
 * Verify that f_rear_sensor is set correctly based on sensor yaw angle.
 *
 * Expected behavior:
 *  yaw > PI/2 -> true
 *  yaw < -PI/2 -> true
 *  -PI/2 < yaw < PI/2 -> false
 */
TEST_F(AngleFindingTest, ApplDownSelectionProcess_ValidateYawAngle)
{
   AF_DownSelection_In_Out_Params_T ds_inout_param = {};
   Downselection_Cal_T ds_cal                      = {};
   Vehicle_Configuration_Cal_T veh_conf_cal        = {};
   Secondpass_Threshold_Cal_T sp_threshold_cal     = {};
   uint8_t i;
   const float32_t yaw_angles[3] = {RADAR_PI_BY_2 + 1.0F, -RADAR_PI_BY_2 - 1.0F, 0.0F};
   const uint8_t positionpointer = 1;

   for (i = 0; i < 3; i++)
   {
      m_appl_in.calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw = yaw_angles[i];
      *m_appl_in.appl_radar_position_ptr                                                    = positionpointer;
      const AF_Retval_T ret =
         AF_Downselection_Init(&ds_inout_param, &ds_cal, &veh_conf_cal, &sp_threshold_cal, &m_appl_in, &m_appl_out);
      EXPECT_EQ(ret, AF_E_OK);
      EXPECT_EQ(ds_inout_param.f_rear_sensor, i != 2);
   }
}

#endif

/*
 * Verify that af_max_time is reduced by the measured timing delta.
 * This ensures the timeout budget is correctly calculated when
 * processing has already consumed a portion of the frame time.
 */
TEST_F(AngleFindingTest, AngleFindingProcessInit_AfMaxTimeCalculatedFromTimingDelta)
{
   constexpr uint32_t doppler_start = 100U;
   constexpr uint32_t current_time  = 150U;
   constexpr uint32_t delta_time    = current_time - doppler_start;
   uint32_t expected_max_time       = FRAME_TIME_PERIOD_CLKS - AF_POST_AF_RESERVED_TIME - delta_time;

   m_appl_in.appl_doppler_start_time     = doppler_start;
   AF_Get_Timing_Counter_fake.return_val = current_time;
   AF_Get_Timing_Delta_fake.return_val   = delta_time;

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);

   EXPECT_EQ(m_af_in.af_max_time, expected_max_time);

   EXPECT_EQ(AF_Get_Timing_Delta_fake.call_count, 1U);
}
/*
 * Verify that af_max_time uses the full available budget when
 * the timing delta is zero.
 */
TEST_F(AngleFindingTest, AngleFindingProcessInit_AfMaxTimeCalculatedFromZeroTimingDelta)
{
   constexpr uint32_t doppler_start = 100U;
   constexpr uint32_t current_time  = 150U;
   constexpr uint32_t delta_time    = 0U;
   uint32_t expected_max_time       = FRAME_TIME_PERIOD_CLKS - AF_POST_AF_RESERVED_TIME - delta_time;

   m_appl_in.appl_doppler_start_time     = doppler_start;
   AF_Get_Timing_Counter_fake.return_val = current_time;
   AF_Get_Timing_Delta_fake.return_val   = delta_time;

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);

   EXPECT_EQ(m_af_in.af_max_time, expected_max_time);

   EXPECT_EQ(AF_Get_Timing_Delta_fake.call_count, 1U);
}
/*
 * Verify that af_max_time is correctly calculated when a large
 * timing delta has already been consumed.
 */
TEST_F(AngleFindingTest, AngleFindingProcessInit_AfMaxTimeCalculatedFromLargeTimingDelta)
{
   const uint32_t large_delta       = FRAME_TIME_PERIOD_CLKS / 2U;
   constexpr uint32_t doppler_start = 100U;
   constexpr uint32_t current_time  = 150U;
   constexpr uint32_t delta_time    = large_delta;
   uint32_t expected_max_time       = FRAME_TIME_PERIOD_CLKS - AF_POST_AF_RESERVED_TIME - delta_time;

   m_appl_in.appl_doppler_start_time     = doppler_start;
   AF_Get_Timing_Counter_fake.return_val = current_time;
   AF_Get_Timing_Delta_fake.return_val   = large_delta;

   const AF_Retval_T ret = Angle_Finding_Process_Init(&m_appl_in, &m_appl_out);

   EXPECT_EQ(ret, AF_E_OK);

   EXPECT_EQ(m_af_in.af_max_time, expected_max_time);

   EXPECT_EQ(AF_Get_Timing_Delta_fake.call_count, 1U);
}
/*
 * Verify that af_xput_peak tracks and retains the highest observed
 * throughput value across multiple metric updates.
 */
TEST_F(AngleFindingTest, UpdateMetrics_XputPeakTracksMaximumAcrossCalls)
{
   Fake_Timing_Helpers_Get_Time_Sec_Float_fake.custom_fake = TimingCounterToSeconds_Custom;

   AF_Get_Timing_Delta_fake.return_val = 100U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_FLOAT_EQ(m_timing.af_xput_inst, 0.100F);
   EXPECT_FLOAT_EQ(m_timing.af_xput_peak, 0.100F);

   AF_Get_Timing_Delta_fake.return_val = 200U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_FLOAT_EQ(m_timing.af_xput_inst, 0.200F);
   EXPECT_FLOAT_EQ(m_timing.af_xput_peak, 0.200F);

   AF_Get_Timing_Delta_fake.return_val = 50U;
   Angle_Finding_Update_Metrics(&m_appl_out, AF_E_OK);
   EXPECT_FLOAT_EQ(m_timing.af_xput_inst, 0.050F);
   EXPECT_FLOAT_EQ(m_timing.af_xput_peak, 0.200F);
}
/*
 * Verify that AF_E_TIMEOUT returned by Angle_Finding_Execute()
 * is propagated to the application layer and increments the
 * timeout diagnostic counter on each occurrence.
 */
TEST_F(AngleFindingTest, ApplAngleFindingProcess_ExecuteStatusPropagatesToTimeoutCount)
{
   Angle_Finding_Execute_fake.return_val = AF_E_OK;
   AF_Retval_T ret                       = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
   EXPECT_EQ(ret, AF_E_OK);
   EXPECT_EQ(m_det_stream.af_diagnostics_info.af_timeout_count, 0U);

   int8_t i;
   for (i = 1; i < 3; i++)
   {
      Angle_Finding_Execute_fake.return_val = AF_E_TIMEOUT;
      ret                                   = Appl_Angle_Finding_Process(&m_appl_in, &m_appl_out);
      EXPECT_EQ(ret, AF_E_TIMEOUT);
      EXPECT_EQ(m_det_stream.af_diagnostics_info.af_timeout_count, i);
   }
}

/*
 * Run Angle_Finding_Complete_Target_Information with XCP mode disabled
 */
TEST_F(AngleFindingTest, Angle_Finding_Complete_Target_Information_Non_XCP_Mode)
{
   AF_Retval_T retval;
   constexpr float32_t aaaaaaaa = -3.03164882520939871213272E-13; /* 0xAAAAAAAA as float */

   memset(&m_xcp_af, 0xAA, sizeof(m_xcp_af));

   retval = Angle_Finding_Complete_Target_Information(&m_appl_in, &m_appl_out);
   EXPECT_EQ(retval, AF_E_OK);

   /* expect no changes to XCP structure */
   EXPECT_EQ(m_xcp_af.num_af_det, 0xAAAAAAAA);
   EXPECT_EQ(m_xcp_af.ran, aaaaaaaa);
   EXPECT_EQ(m_xcp_af.vel, aaaaaaaa);
   EXPECT_EQ(m_xcp_af.pow[0], aaaaaaaa);
   EXPECT_EQ(m_xcp_af.snr, aaaaaaaa);
   EXPECT_EQ(m_xcp_af.theta[0], aaaaaaaa);
   EXPECT_EQ(m_xcp_af.phi[0], aaaaaaaa);
   EXPECT_EQ(m_xcp_af.spec_res[0], aaaaaaaa);
   EXPECT_EQ(m_xcp_af.rdd_idx, (int16_t)0xAAAA);
   EXPECT_EQ(m_xcp_af.az_conf[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.el_conf[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.f_single_target[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.f_superres_target[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.f_1az2el[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.f_bistatic[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.az_af_type[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.el_af_type[0], (int8_t)0xAA);
   EXPECT_EQ(m_xcp_af.rcs[0], aaaaaaaa);
}

/*
 * Run Angle_Finding_Complete_Target_Information with XCP mode enabled
 */
TEST_F(AngleFindingTest, Angle_Finding_Complete_Target_Information_XCP_Mode)
{
   AF_Retval_T retval;
   constexpr float32_t aaaaaaaa = -3.03164882520939871213272E-13; /* 0xAAAAAAAA as float */

   m_appl_in.appl_xcp_info_data_ptr->xcp_range_idx   = 0;
   m_appl_in.appl_xcp_info_data_ptr->xcp_doppler_idx = 0;
   m_det_stream.num_af_det                           = 1;
   m_det_stream.af_dets[0].ran                       = 1.234F;
   m_det_stream.af_dets[0].vel                       = 5.678F;
   m_det_stream.af_dets[0].pow                       = 9.012F;
   m_det_stream.af_dets[0].snr                       = 3.456F;
   m_det_stream.af_dets[0].theta                     = 7.890F;
   m_det_stream.af_dets[0].phi                       = -0.123F;
   m_det_stream.af_dets[0].rcs                       = 4.567F;
   m_det_stream.af_dets[0].spec_res                  = 8.910F;
   m_det_stream.af_dets[0].rdd_idx                   = 100;
   m_det_stream.af_dets[0].az_conf                   = 0;
   m_det_stream.af_dets[0].el_conf                   = 1;
   m_det_stream.af_dets[0].f_single_target           = 2;
   m_det_stream.af_dets[0].f_superres_target         = 3;
   m_det_stream.af_dets[0].f_bistatic                = 4;
   m_debug.num_af_det                                = 1;
   m_debug.af_debug_detections[0].f_1az2el           = 5;
   m_debug.af_debug_detections[0].az_af_type         = 6;
   m_debug.af_debug_detections[0].el_af_type         = 7;
   m_debug.af_debug_detections[0].below_af_sen_thld  = 8;
   m_xcp_data.rdd2_xcp_snr                           = m_det_stream.af_dets[0].snr;
   m_xcp_data.rdd2_xcp_range                         = m_det_stream.af_dets[0].ran * SCALE_FLOAT_TO_P21;
   m_xcp_data.rdd2_xcp_range_rate                    = m_det_stream.af_dets[0].vel * SCALE_FLOAT_TO_P21;
   memset(&m_xcp_af, 0xAA, sizeof(m_xcp_af));

   retval = Angle_Finding_Complete_Target_Information(&m_appl_in, &m_appl_out);
   EXPECT_EQ(retval, AF_E_OK);

   /* expect input detection copied to XCP structure */
   EXPECT_EQ(m_xcp_af.num_af_det, 1);
   EXPECT_FLOAT_EQ(m_xcp_af.ran, 1.234F);
   EXPECT_FLOAT_EQ(m_xcp_af.vel, 5.678F);
   EXPECT_FLOAT_EQ(m_xcp_af.pow[0], 9.012F);
   EXPECT_FLOAT_EQ(m_xcp_af.snr, 3.456F);
   EXPECT_FLOAT_EQ(m_xcp_af.theta[0], 7.890F);
   EXPECT_FLOAT_EQ(m_xcp_af.phi[0], -0.123F);
   EXPECT_FLOAT_EQ(m_xcp_af.rcs[0], 4.567F);
   EXPECT_FLOAT_EQ(m_xcp_af.spec_res[0], 8.910F);
   EXPECT_EQ(m_xcp_af.rdd_idx, 100);
   EXPECT_EQ(m_xcp_af.az_conf[0], 0);
   EXPECT_EQ(m_xcp_af.el_conf[0], 1);
   EXPECT_EQ(m_xcp_af.f_single_target[0], 2);
   EXPECT_EQ(m_xcp_af.f_superres_target[0], 3);
   EXPECT_EQ(m_xcp_af.f_bistatic[0], 4);
   EXPECT_EQ(m_xcp_af.f_1az2el[0], 5);
   EXPECT_EQ(m_xcp_af.az_af_type[0], 6);
   EXPECT_EQ(m_xcp_af.el_af_type[0], 7);
}
