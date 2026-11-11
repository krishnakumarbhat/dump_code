/*===========================================================================*/
/**
 * @file anglefinding_project_interface.c
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024-2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains the AF Module interface handling.
 *
 * @section ABBR ABBREVIATIONS:
 *   - AF: Angle Finding (DoA)
 *   - Az: Azimuth
 *   - DS: Down Selection
 *   - El: Elevation
 *   - FC: Fascia Compensation
 *   - IPC: Inter-Processor Communication
 *   - RCS: Radar Cross Section
 *   - XCP: Universal Measurement and Calibration Protocol
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h> // for memset

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "af_fascia_compensation.h"
#include "afbb_cfg.h"
#include "afbb_include.h"
#include "angle_finding_interface.h"
#include "angle_finding_project_interface.h"
#include "api/timing_helpers.h"
#include "fixed_point_conversions.h"
#include "fixmac.h"
#include "ipc_data.h"
#include "mem_pool.h"
#include "reuse.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define AF_MAX_NUM_STAGES (5)

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "dsp_it_macros_test.h"

/*===========================================================================*
 * Local Preprocessor code
 *===========================================================================*/
#define AF_MAX_XCP_INPUT_DETS (1U)

/*===========================================================================*
 * Import function prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
/* expanded type for list of slope correction axis enabled */
typedef struct FC_Slope_Axis_Select_Tag
{
   bool az_enabled;
   bool el_enabled;
   bool roll_enabled;
} FC_Slope_Axis_Select_T;

/* Local Store of XCP Input Data to AF */
typedef struct AF_XCP_RDD_Input_Tag
{
   uint16_t num_rdd_det;
   s10p21_T ran;
   s10p21_T vel;
   s8p23_T snr;
   uint8_t rdd2_sp_fail_flag;
   uint8_t rdd1_neighbor_det_flag;
} AF_XCP_RDD_Input_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static uint32_t g_af_start_time;
static uint32_t g_af_xput_peak_time = 0;
static uint16_t g_af_timeout_count  = 0;
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
static uint32_t g_af_ds_start_time;
#endif
static uint32_t g_af_stage1_xput_ctr;
static uint32_t g_af_stage2_xput_ctr;
static uint32_t g_af_stage3_xput_ctr;
static uint32_t g_af_stage4_xput_ctr;
static uint32_t g_af_stage5_xput_ctr;
static uint32_t g_af_iso_xput_ctr;
static uint32_t g_af_sens_thld_xput_ctr;
static uint32_t g_af_fov_xput_ctr;
static uint32_t g_af_prune_xput_ctr;
static uint32_t g_af_rcs_xput_ctr;
static uint32_t g_af_downselection_xput_ctr;
static int8_t g_af_xcp_below_af_sen_thld[AF_MULTI_TARGET_DETS_L]; // debug xcp sens thld, could add to IPC if needed

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
static float32_t *fascia_temp;
#endif

static __attribute__((section(".sram0.bss"))) AF_XCP_RDD_Input_T g_af_xcp_input_data;

/*===========================================================================*
 * Local function prototype
 *===========================================================================*/

/*===========================================================================*
 * Local function Definitions
 *===========================================================================*/

/**
 * @brief Perform final calculations/cleanup for AF
 *
 * This function mainly computes the xput timing for the AF.
 * It converts the counts from system ticks to float value (in seconds) and
 * updates the Angle_Timing_Data_T output.
 *
 * @param appl_out Pointer to the AF_Appl_Output_T structure to store output data:
 *   - Appl_Detection_stream_data_ptr: Pointer to Detection_Stream_T structure
 *   - Appl_Detection_Debug_data_ptr: Pointer to Detection_Debug_Stream_T structure
 *   - Appl_AF_Timing_data_ptr: Pointer to Angle_Timing_Data_T structure
 *   - Timeout counter stored in detection stream AF_Diagnostics_T
 *
 * @param af_status The status return value from the angle finding pipeline
 *
 * @return void
 *
 * @see Angle_Timing_Data_T
 */
void Angle_Finding_Update_Metrics(AF_Appl_Output_T *appl_out, AF_Retval_T af_status)
{
   uint32_t af_runtime;
   Angle_Timing_Data_T *p_af_timing     = appl_out->appl_af_timing_data_ptr;
   Detection_Stream_T *p_af_det         = appl_out->appl_detection_stream_data_ptr;
   Detection_Debug_Stream_T *p_af_debug = appl_out->appl_detection_debug_data_ptr;

   if (AF_E_TIMEOUT & af_status)
   {
      g_af_timeout_count++;
   }
   appl_out->appl_detection_stream_data_ptr->af_diagnostics_info.af_timeout_count = g_af_timeout_count;

   // Store num_af_det in the debug stream and timing output for atomicity
   p_af_debug->num_af_det  = p_af_det->num_af_det;
   p_af_timing->num_af_det = p_af_det->num_af_det;

   // Compute timing metrics
   af_runtime                = AF_Get_Timing_Delta(g_af_start_time, AF_Get_Timing_Counter());
   g_af_xput_peak_time       = MAX(g_af_xput_peak_time, af_runtime);
   p_af_timing->af_xput_inst = Timing_Helpers_Get_Time_Sec_Float(af_runtime);
   p_af_timing->af_xput_peak = Timing_Helpers_Get_Time_Sec_Float(g_af_xput_peak_time);

   p_af_timing->af_xput_stage1    = Timing_Helpers_Get_Time_Sec_Float(g_af_stage1_xput_ctr);
   p_af_timing->af_xput_stage2    = Timing_Helpers_Get_Time_Sec_Float(g_af_stage2_xput_ctr);
   p_af_timing->af_xput_stage3    = Timing_Helpers_Get_Time_Sec_Float(g_af_stage3_xput_ctr);
   p_af_timing->af_xput_stage4    = Timing_Helpers_Get_Time_Sec_Float(g_af_stage4_xput_ctr);
   p_af_timing->af_xput_stage5    = Timing_Helpers_Get_Time_Sec_Float(g_af_stage5_xput_ctr);
   p_af_timing->af_xput_iso       = Timing_Helpers_Get_Time_Sec_Float(g_af_iso_xput_ctr);
   p_af_timing->af_xput_sens_thld = Timing_Helpers_Get_Time_Sec_Float(g_af_sens_thld_xput_ctr);
   p_af_timing->af_xput_fov       = Timing_Helpers_Get_Time_Sec_Float(g_af_fov_xput_ctr);
   p_af_timing->af_xput_prune     = Timing_Helpers_Get_Time_Sec_Float(g_af_prune_xput_ctr);
   p_af_timing->af_xput_rcs       = Timing_Helpers_Get_Time_Sec_Float(g_af_rcs_xput_ctr);

   // within header stream, scan_index can be out-of-sync with other angle finding streams
   p_af_timing->af_timing_scan_index = p_af_det->stream_hdr.scan_index;
}

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
/**
 * @brief Initializes memory for the Fascia Compensation module.
 *
 * This function is responsible for setting up the memory pool required for the
 * Fascia Compensation module's operations. It allocates and initializes the
 * necessary memory structures within the provided memory pool.
 *
 * @param dram_mem_pool Pointer to the memory pool structure (Mem_Pool_T) where
 *                      the Angle Finding module's memory will be allocated.
 *
 * @return Memory_Pool_Return_T An enumeration value indicating the result of
 *         the memory initialization:
 *         - MEMORY_POOL_SUCCESS if initialization was successful
 *         - An error code if initialization failed (specific error codes
 *           should be defined in the Memory_Pool_Return_T enumeration)
 *
 * @note This function should be called once in each cycle before calling
 *       Appl_Execute_Fascia_Compensation. At the end of the Fascia
 *       Compensation execution, call Mem_Pool_Reset to release the memory.
 *
 * @warning The mem_pool pointer must not be NULL and should point to a valid,
 *          initialized Mem_Pool_T structure.
 *
 * @see Mem_Pool_T
 * @see Memory_Pool_Return_T
 */
Memory_Pool_Return_T Fascia_Compensation_Memory_Init(Mem_Pool_T *dram_mem_pool)
{
   return Mem_Pool_Alloc(dram_mem_pool, AF_MAX_NUM_DET_L * sizeof(float32_t), (void **)&fascia_temp);
}

/**
 * @brief Stub code to test Fascia Slope correction Algorithm
 *
 * This function injects sample data into the fascia compensation inputs.
 *
 * @param fascia_compensation_params [out] Pointer to Fascia_Comp_Data_T
 *        This data will be overriden with the test inputs.
 *
 * @param af_appl_data [inout] Pointer to the anglefinding output data which
 *        will be the input to fascia compensation. This data will be
 *        overriden with the test inputs.
 *
 * @note Expected results for these test data values:
 *       theta[0] = -270.7826559
 *       theta[1] = -1789.872251
 *       theta[2] = -4.18215E+13
 *       theta[3] = -3.41154287
 *       theta[4] = 1.45852E-05
 *       theta[5] = -21.54363504
 *
 * @return void
 */
static void Appl_Fascia_Testing(volatile Fascia_Comp_Data_T *fascia_compensation_params, AF_Appl_Output_T *af_appl_data)
{
   #ifndef AF_FC_STUB_SIMULATE_DET
   UNUSED_PARAM(fascia_compensation_params);
   UNUSED_PARAM(af_appl_data);
   #else
   Detection_Stream_T *p_det_stream_ptr = af_appl_data->appl_detection_stream_data_ptr;
   AF_Detection_T *p_dets               = (AF_Detection_T *)p_det_stream_ptr->af_dets;

   if (NULL != fascia_compensation_params)
   {
      /* AF Params for Testing */
      p_det_stream_ptr->num_af_det = 6;
      p_dets[0].theta              = 1.58765F;
      p_dets[1].theta              = -2.567000456F;
      p_dets[2].theta              = -1000.0F;
      p_dets[3].theta              = -0.52345442357F;
      p_dets[4].theta              = 0.0F;
      p_dets[5].theta              = 0.8457354465F;

      /* Coefficients for testing */
      fascia_compensation_params->axis_enable        = FC_AZIMUTH;
      fascia_compensation_params->az_coefficients[0] = 0.0F;
      fascia_compensation_params->az_coefficients[1] = 0.000222356F;
      fascia_compensation_params->az_coefficients[2] = 0.0005126789F;
      fascia_compensation_params->az_coefficients[3] = -0.000645416F;
      fascia_compensation_params->az_coefficients[4] = 0.000742567F;
      fascia_compensation_params->az_coefficients[5] = -0.0008356723F;
   }
   #endif /* AF_FC_STUB_SIMULATE_DET */
}

/**
 * @brief Helper to decode FC_Enable_Flag_T
 *
 * This function queries an FC_Enable_Flag_T and returns true/false if all of
 * the axis mentioned by query_* flags are enabled.
 *
 * @param axis_enable_mode The supplied IPC enum value for enablement
 * @param axis_enabled Output structure indicating which axis are enabled
 */
static void Query_Fascia_Mode(FC_Enable_Flag_T axis_enable_mode, FC_Slope_Axis_Select_T *axis_enabled)
{
   const FC_Slope_Axis_Select_T axis_map[FC_MAX_NUM_MODES] = {
      [NO_SLOPE_CORRECTION]  = {.az_enabled = false, .el_enabled = false, .roll_enabled = false},
      [FC_ALL_DIRECTIONS]    = {.az_enabled = true, .el_enabled = true, .roll_enabled = true},
      [FC_AZIMUTH]           = {.az_enabled = true, .el_enabled = false, .roll_enabled = false},
      [FC_ELEVATION]         = {.az_enabled = false, .el_enabled = true, .roll_enabled = false},
      [FC_ROLL]              = {.az_enabled = false, .el_enabled = false, .roll_enabled = true},
      [FC_AZIMUTH_ELEVATION] = {.az_enabled = true, .el_enabled = true, .roll_enabled = false},
      [FC_AZIMUTH_ROLL]      = {.az_enabled = true, .el_enabled = false, .roll_enabled = true},
      [FC_ELEVATION_ROLL]    = {.az_enabled = false, .el_enabled = true, .roll_enabled = true},
   };

   if (axis_enable_mode < FC_MAX_NUM_MODES)
   {
      memcpy(axis_enabled, &axis_map[axis_enable_mode], sizeof(*axis_enabled));
   }
   else
   {
      /* unknown - assume false */
      memset(axis_enabled, 0, sizeof(*axis_enabled));
   }
}

/**
 * @brief Executes fascia compensation for angle finding.
 *
 * This function performs fascia compensation as part of the angle finding
 * process. It adjusts the angle measurements to account for the effects of
 * the vehicle's fascia (front body panel) on radar signals.
 *
 * @param fascia_compensation_params [in] Pointer to Fascia_Comp_Data_T
 *        This provides enum with axis enablement and polynomial parameters for
 *        each axis.
 *
 * @param af_appl_data [inout] Pointer to the AF_Appl_Output_T structure
 *        which contains pointers to the AF output data that will be updated
 *        by the fascia compensation algorithm:
 *        - Appl_Detection_stream_data_ptr: Pointer to Detection_Stream_T
 *          structure
 *
 * @warning af_appl_data pointers must be valid and properly initialized
 *          before calling this function.
 */
void Appl_Execute_Fascia_Compensation(volatile Fascia_Comp_Data_T *fascia_compensation_params, AF_Appl_Output_T *af_appl_data)
{
   AF_Retval_T retval;
   uint8_t *p_slope_correction_status;
   AF_Detection_T *p_dets;
   int num_det;
   int i;
   FC_Slope_Axis_Select_T axis_select = {0};

   /* test data injection */
   Appl_Fascia_Testing(fascia_compensation_params, af_appl_data);

   /* Note: always run compensation on the detection stream, then execute downselection afterwards */
   p_slope_correction_status = &(af_appl_data->appl_detection_stream_data_ptr->det_list_property.slope_correction_status);
   p_dets                    = (AF_Detection_T *)af_appl_data->appl_detection_stream_data_ptr->af_dets;
   num_det                   = af_appl_data->appl_detection_stream_data_ptr->num_af_det;

   Query_Fascia_Mode(fascia_compensation_params->axis_enable, &axis_select);

   /* Compute slope correction */
   *(p_slope_correction_status) = FS_NO_SLOPE_CORRECTION;

   /* azimuth compensation */
   if (axis_select.az_enabled)
   {
      /* batch and align inputs */
      for (i = 0; i < num_det; i++)
      {
         fascia_temp[i] = p_dets[i].theta;
      }
      retval = AF_Fascia_Compensation(fascia_temp, (float32_t *)fascia_compensation_params->az_coefficients, (size_t)num_det,
                                      AF_MAX_NUM_FASCIA_COEF);
      if (AF_E_OK == retval)
      {
         /* copy updated values to output */
         for (i = 0; i < num_det; i++)
         {
            p_dets[i].theta = fascia_temp[i];
         }
         *(p_slope_correction_status) += FS_AZ_EXECUTED;
      }
   }

   /* elevation compensation */
   if (axis_select.el_enabled)
   {
      /* batch and align inputs */
      for (i = 0; i < num_det; i++)
      {
         fascia_temp[i] = p_dets[i].phi;
      }
      retval = AF_Fascia_Compensation(fascia_temp, (float32_t *)fascia_compensation_params->el_coefficients, (size_t)num_det,
                                      AF_MAX_NUM_FASCIA_COEF);
      if (AF_E_OK == retval)
      {
         /* copy updated values to output */
         for (i = 0; i < num_det; i++)
         {
            p_dets[i].phi = fascia_temp[i];
         }
         *(p_slope_correction_status) += FS_EL_EXECUTED;
      }
   }
}
#endif /* AF_FASCIA_COMPENSATION_ENABLE */

/**
 * @brief Determine whether XCP mode is enabled
 *
 * @param appl_in [in] Pointer to the AF_Appl_Input_T structure
 * @warning af_appl_data pointers must be valid and properly initialized
 *          before calling this function.
 *
 * @return bool - true if XCP mode is enabled
 */
static bool Angle_Finding_Determine_XCP_Mode(AF_Appl_Input_T *appl_in)
{
   bool is_xcp_mode = false;

   if ((appl_in->appl_xcp_info_data_ptr->xcp_range_idx < AF_MAX_RANGE_BINS_L) &&
       (appl_in->appl_xcp_info_data_ptr->xcp_doppler_idx < AF_MAX_DOPPLER_FFT_SIZE_L))
   {
      is_xcp_mode = true;
   }

#if defined(AF_TESTING) && defined(AF_XCP_TEST_IDX)
   is_xcp_mode = true;
#endif

   return is_xcp_mode;
}

/******************************************************************************
 *. Name: Angle_Finding_Init
 *.    Function to Angle_Finding_Init.
 *.
 *. Parameters:
 *. Return Value: Angle_Finding_Output_T
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static AF_Retval_T Angle_Finding_Process_Init(AF_Appl_Input_T *appl_in, AF_Appl_Output_T *appl_out)
{
   AF_Retval_T process_init_return = AF_E_PARAM;
   bool is_xcp_mode                = false;

   Angle_Finding_Input_T *af_input_data_ptr   = Get_af_input_data_ptr();
   Angle_Finding_Output_T *af_output_data_ptr = Get_af_output_data_ptr();

   /* register start time for anglefinding */
   g_af_start_time         = AF_Get_Timing_Counter();
   g_af_stage1_xput_ctr    = 0;
   g_af_stage2_xput_ctr    = 0;
   g_af_stage3_xput_ctr    = 0;
   g_af_stage4_xput_ctr    = 0;
   g_af_stage5_xput_ctr    = 0;
   g_af_iso_xput_ctr       = 0;
   g_af_sens_thld_xput_ctr = 0;
   g_af_fov_xput_ctr       = 0;
   g_af_prune_xput_ctr     = 0;
   g_af_rcs_xput_ctr       = 0;

   const void *const af_in_out_ptrs[] = {(const void *)appl_in->appl_rdd_data_ptr,
                                         (const void *)appl_in->appl_look_data_ptr,
                                         (const void *)appl_in->appl_xcp_data_ptr,
                                         (const void *)appl_in->appl_xcp_info_data_ptr,
                                         (const void *)appl_in->appl_veh_speed_ptr,
                                         (const void *)appl_in->appl_radar_position_ptr,
                                         (const void *)appl_out->appl_detection_stream_data_ptr,
                                         (const void *)appl_out->appl_af_xcp_data_ptr,
                                         (const void *)appl_out->appl_detection_debug_data_ptr,
                                         (const void *)appl_out->appl_af_timing_data_ptr};

   if (NULL_PTR_CHECK(af_in_out_ptrs))
   {
      process_init_return = AF_E_OK;
   }

   if (AF_E_OK == process_init_return)
   { /* contract checking succeeded, proceed with initialization */

      is_xcp_mode = Angle_Finding_Determine_XCP_Mode(appl_in);

      /* Stream Header update */
      appl_out->appl_detection_stream_data_ptr->stream_hdr.scan_index = appl_in->appl_look_data_ptr->scan_index;
      appl_out->appl_detection_stream_data_ptr->stream_hdr.size       = sizeof(Detection_Stream_T);
      appl_out->appl_detection_debug_data_ptr->stream_hdr.scan_index  = appl_in->appl_look_data_ptr->scan_index;
      appl_out->appl_detection_debug_data_ptr->stream_hdr.size        = sizeof(Detection_Debug_Stream_T);

      /*Passing USC parameters to angle finding building block input*/
      if (k_isUWB_smc[appl_in->appl_look_data_ptr->look_id])
      {
         af_input_data_ptr->p_calmat1_ctx           = &(k_calmat1_ctx_UWB_usc[0][0]);
         af_input_data_ptr->p_calmat1_crx           = &(k_calmat1_crx_UWB_usc[0][0]);
         af_input_data_ptr->p_calmat1_c1            = &(k_calmat1_c1_UWB_usc[0][0]);
         af_input_data_ptr->p_calmat2_ctx           = &(k_calmat2_ctx_UWB_usc[0][0]);
         af_input_data_ptr->p_calmat2_crx           = &(k_calmat2_crx_UWB_usc[0][0]);
         af_input_data_ptr->p_calmat2_c1            = &(k_calmat2_c1_UWB_usc[0][0]);
         af_input_data_ptr->p_gain_rolloff_az_recip = k_Gain_Rolloff_Az_Reciprocal_UWB_usc;
         af_input_data_ptr->p_gain_rolloff_el_recip = k_Gain_Rolloff_EL_Reciprocal_UWB_usc;
      }
      else
      {
         af_input_data_ptr->p_calmat1_ctx           = &(k_calmat1_ctx_USC[0][0]);
         af_input_data_ptr->p_calmat1_crx           = &(k_calmat1_crx_USC[0][0]);
         af_input_data_ptr->p_calmat1_c1            = &(k_calmat1_c1_USC[0][0]);
         af_input_data_ptr->p_calmat2_ctx           = &(k_calmat2_ctx_USC[0][0]);
         af_input_data_ptr->p_calmat2_crx           = &(k_calmat2_crx_USC[0][0]);
         af_input_data_ptr->p_calmat2_c1            = &(k_calmat2_c1_USC[0][0]);
         af_input_data_ptr->p_gain_rolloff_az_recip = k_Gain_Rolloff_Az_Reciprocal_USC;
         af_input_data_ptr->p_gain_rolloff_el_recip = k_Gain_Rolloff_EL_Reciprocal_USC;
      }

      /* RDD input interface mapping */
      if (is_xcp_mode)
      {
         /* Override inputs for XCP mode */
         g_af_xcp_input_data.num_rdd_det            = AF_MAX_XCP_INPUT_DETS;
         g_af_xcp_input_data.ran                    = appl_in->appl_xcp_data_ptr->rdd2_xcp_range;
         g_af_xcp_input_data.vel                    = appl_in->appl_xcp_data_ptr->rdd2_xcp_range_rate;
         g_af_xcp_input_data.snr                    = appl_in->appl_xcp_data_ptr->rdd2_xcp_snr * SCALE_FLOAT_TO_P23;
         g_af_xcp_input_data.rdd2_sp_fail_flag      = 0;
         g_af_xcp_input_data.rdd1_neighbor_det_flag = 0;

         af_input_data_ptr->p_rdd1_bv           = &appl_in->appl_xcp_data_ptr->rdd1_xcp_compressed_bv;
         af_input_data_ptr->p_rdd2_range        = &(g_af_xcp_input_data.ran);
         af_input_data_ptr->p_rdd2_range_rate   = &(g_af_xcp_input_data.vel);
         af_input_data_ptr->p_rdd2_snr          = &(g_af_xcp_input_data.snr);
         af_input_data_ptr->p_rdd2_sp_fail_flag = &(g_af_xcp_input_data.rdd2_sp_fail_flag);
         af_input_data_ptr->p_rdd1_rindx        = &(appl_in->appl_xcp_info_data_ptr->xcp_range_idx);
#if (B0_FEAT_3DFFT == 1)
         af_input_data_ptr->p_rdd1_aindx = &(appl_in->appl_xcp_info_data_ptr->xcp_angle_idx);
#endif
         af_input_data_ptr->p_rdd1_num_detect = &g_af_xcp_input_data.num_rdd_det;
         af_input_data_ptr->p_rdd2_num_detect = &g_af_xcp_input_data.num_rdd_det;
         af_input_data_ptr->p_rdd1_rdop_amp   = &(appl_in->appl_xcp_data_ptr->rdd1_xcp_rdop_amp);
         af_input_data_ptr->p_f_neighbor_det  = &g_af_xcp_input_data.rdd1_neighbor_det_flag;
      }
      else
      {
         af_input_data_ptr->p_rdd1_bv           = appl_in->appl_rdd_data_ptr->rdd1_bv;
         af_input_data_ptr->p_rdd2_range        = appl_in->appl_rdd_data_ptr->rdd2_range;
         af_input_data_ptr->p_rdd2_range_rate   = appl_in->appl_rdd_data_ptr->rdd2_range_rate;
         af_input_data_ptr->p_rdd2_snr          = appl_in->appl_rdd_data_ptr->rdd2_snr;
         af_input_data_ptr->p_rdd2_sp_fail_flag = appl_in->appl_rdd_data_ptr->rdd2_sp_fail_flag;
         af_input_data_ptr->p_rdd1_rindx        = appl_in->appl_rdd_data_ptr->rdd1_rindx;
#if (B0_FEAT_3DFFT == 1)
         af_input_data_ptr->p_rdd1_aindx = appl_in->appl_rdd_data_ptr->rdd1_aindx;
#endif
         af_input_data_ptr->p_rdd1_num_detect = &(appl_in->appl_rdd_data_ptr->rdd1_num_detect);
         af_input_data_ptr->p_rdd2_num_detect = &(appl_in->appl_rdd_data_ptr->rdd2_num_detect);
         af_input_data_ptr->p_rdd1_rdop_amp   = appl_in->appl_rdd_data_ptr->rdd1_rdop_amp;
         af_input_data_ptr->p_f_neighbor_det  = appl_in->appl_rdd_data_ptr->rdd1_neighbor_det_flag;
      }
      af_input_data_ptr->p_bwdep_cr_resp        = appl_in->appl_rdd_data_ptr->bwdep_cr_resp;
      af_input_data_ptr->p_nci_bexp             = (uint16_t *)appl_in->appl_rdd_data_ptr->nci_bexp;
      af_input_data_ptr->p_af_sensitivity_thold = appl_in->appl_rdd_data_ptr->af_sensitivity_thold;
      af_input_data_ptr->p_look_id              = &(appl_in->appl_look_data_ptr->look_id);

      /* Vehicle info params*/
      af_input_data_ptr->p_veh_speed      = appl_in->appl_veh_speed_ptr;
      af_input_data_ptr->p_radar_position = appl_in->appl_radar_position_ptr;

      /* Project Interface Input */
#if AF_TIMEOUT_ENABLE_L
      // AF time  = Frame time (50ms) - Post AF reserved time - Doppler and RDD processing time
      af_input_data_ptr->af_max_time = FRAME_TIME_PERIOD_CLKS - AF_POST_AF_RESERVED_TIME -
                                       AF_Get_Timing_Delta(appl_in->appl_doppler_start_time, g_af_start_time);
#endif
      af_input_data_ptr->is_xcp_mode = is_xcp_mode;

      /* angle finding ouput stream data mapping*/
      af_output_data_ptr->afbb_det_output.af_data.p_num_af_det = &(appl_out->appl_detection_stream_data_ptr->num_af_det);
      af_output_data_ptr->afbb_det_output.af_data.p_dets = (AF_Detection_T *)appl_out->appl_detection_stream_data_ptr->af_dets;
      af_output_data_ptr->afbb_det_output.af_data.p_debug_dets = appl_out->appl_detection_debug_data_ptr->af_debug_detections;
      af_output_data_ptr->afbb_det_output.af_data.est_rx_tx_amp =
         appl_out->appl_detection_debug_data_ptr->af_det_debug_data.est_rx_tx_amp;

      /* angle finding stream : det list property data mapping */
      appl_out->appl_detection_stream_data_ptr->det_list_property.look_type         = appl_in->appl_look_data_ptr->look_id;
      appl_out->appl_detection_stream_data_ptr->det_list_property.lookindex         = appl_in->appl_look_data_ptr->look_index;
      appl_out->appl_detection_stream_data_ptr->det_list_property.scanindex         = appl_in->appl_look_data_ptr->scan_index;
      appl_out->appl_detection_stream_data_ptr->det_list_property.num_fp_detections = appl_in->appl_rdd_data_ptr->rdd1_num_detect;
      appl_out->appl_detection_stream_data_ptr->det_list_property.num_sp_detections = appl_in->appl_rdd_data_ptr->rdd2_num_detect;
      appl_out->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_ns =
         appl_in->appl_look_data_ptr->mid_dwell_nanosec;
      appl_out->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_sec =
         appl_in->appl_look_data_ptr->mid_dwell_sec;
      appl_out->appl_detection_stream_data_ptr->det_list_property.timestamp_status = appl_in->appl_look_data_ptr->mid_dwell_status;

      /* AF detections added/selected after each stage */
      af_output_data_ptr->afbb_det_output.target_selected_post_stage_1 =
         &(appl_out->appl_detection_debug_data_ptr->af_det_debug_data.target_selected_post_stage_1);
      af_output_data_ptr->afbb_det_output.target_selected_post_stage_2 =
         &(appl_out->appl_detection_debug_data_ptr->af_det_debug_data.target_selected_post_stage_2);
      af_output_data_ptr->afbb_det_output.target_selected_post_stage_3 =
         &(appl_out->appl_detection_debug_data_ptr->af_det_debug_data.target_selected_post_stage_3);
      af_output_data_ptr->afbb_det_output.target_selected_post_stage_4 =
         &(appl_out->appl_detection_debug_data_ptr->af_det_debug_data.target_selected_post_stage_4);
      af_output_data_ptr->afbb_det_output.target_selected_post_stage_5 =
         &(appl_out->appl_detection_debug_data_ptr->af_det_debug_data.target_selected_post_stage_5);

      /* AF stage counts  */
      af_output_data_ptr->afbb_det_output.num_af_stage1        = &(appl_out->appl_af_timing_data_ptr->num_af_stage1);
      af_output_data_ptr->afbb_det_output.num_af_stage2        = &(appl_out->appl_af_timing_data_ptr->num_af_stage2);
      af_output_data_ptr->afbb_det_output.num_af_stage3        = &(appl_out->appl_af_timing_data_ptr->num_af_stage3);
      af_output_data_ptr->afbb_det_output.num_af_stage4        = &(appl_out->appl_af_timing_data_ptr->num_af_stage4);
      af_output_data_ptr->afbb_det_output.num_af_stage5        = &(appl_out->appl_af_timing_data_ptr->num_af_stage5);
      af_output_data_ptr->afbb_det_output.num_af_iso           = &(appl_out->appl_af_timing_data_ptr->num_af_iso);
      af_output_data_ptr->afbb_det_output.num_af_sens_thld     = &(appl_out->appl_af_timing_data_ptr->num_af_sens_thld);
      af_output_data_ptr->afbb_det_output.num_af_fov           = &(appl_out->appl_af_timing_data_ptr->num_af_fov);
      af_output_data_ptr->afbb_det_output.num_af_prune         = &(appl_out->appl_af_timing_data_ptr->num_af_prune);
      af_output_data_ptr->afbb_det_output.num_af_rcs           = &(appl_out->appl_af_timing_data_ptr->num_af_rcs);
      af_output_data_ptr->afbb_det_output.num_af_downselection = &(appl_out->appl_af_timing_data_ptr->num_af_downselection);

      /* AF XPUT/Timing outputs */
      af_output_data_ptr->afbb_det_output.stage1_xput        = &g_af_stage1_xput_ctr;
      af_output_data_ptr->afbb_det_output.stage2_xput        = &g_af_stage2_xput_ctr;
      af_output_data_ptr->afbb_det_output.stage3_xput        = &g_af_stage3_xput_ctr;
      af_output_data_ptr->afbb_det_output.stage4_xput        = &g_af_stage4_xput_ctr;
      af_output_data_ptr->afbb_det_output.stage5_xput        = &g_af_stage5_xput_ctr;
      af_output_data_ptr->afbb_det_output.iso_xput           = &g_af_iso_xput_ctr;
      af_output_data_ptr->afbb_det_output.sens_thld_xput     = &g_af_sens_thld_xput_ctr;
      af_output_data_ptr->afbb_det_output.fov_xput           = &g_af_fov_xput_ctr;
      af_output_data_ptr->afbb_det_output.prune_xput         = &g_af_prune_xput_ctr;
      af_output_data_ptr->afbb_det_output.rcs_xput           = &g_af_rcs_xput_ctr;
      af_output_data_ptr->afbb_det_output.downselection_xput = &g_af_downselection_xput_ctr;

      /* Diagnostic Outputs */
      af_output_data_ptr->afbb_det_output.af_saturation_flag_ptr =
         &(appl_out->appl_detection_stream_data_ptr->af_diagnostics_info.af_saturation_flag);
      af_output_data_ptr->afbb_det_output.af_timeout_flag_ptr =
         &(appl_out->appl_detection_stream_data_ptr->af_diagnostics_info.af_timeout_flag);
      af_output_data_ptr->afbb_det_output.af_smc_mismatch_flag_ptr =
         &(appl_out->appl_detection_stream_data_ptr->af_diagnostics_info.af_smc_mismatch_flag);
      af_output_data_ptr->afbb_det_output.af_usc_mismatch_flag_ptr =
         &(appl_out->appl_detection_stream_data_ptr->af_diagnostics_info.af_usc_mismatch_flag);

      /* Providing af_input_data_ptr info, for Integration Testing */
      SIT_AF_INPUT(af_input_data_ptr, appl_out);
   } /* AF_E_OK == process_init_return */

   return process_init_return;
}

/**
 * @brief Finalize any detection output data
 *
 * In particular, this function copies AF data output to the Angle_Data_XCP_T
 * output IPC structure.
 *
 * @param appl_in Pointer to the AF_Appl_Input_T structure containing input data:
 *   - appl_xcp_data_ptr: Pointer to XCP_Data_T structure
 *
 * @param appl_out Pointer to the AF_Appl_Output_T structure to store output data:
 *   - appl_detection_stream_data_ptr: Pointer to Detection_Stream_T structure
 *   - appl_detection_debug_data_ptr: Pointer to Detection_Debug_Stream_T structure
 *   - appl_af_xcp_data_ptr: Pointer to Angle_Data_XCP_T structure
 *
 * @return always returns AF_E_OK
 *
 * @warning Both input and output pointers must be valid and properly initialized
 *          before calling this function.
 *
 * @see AF_Appl_Input_T
 * @see AF_Appl_Output_T
 * @see AF_Retval_T
 */
AF_Retval_T Angle_Finding_Complete_Target_Information(AF_Appl_Input_T *appl_in, AF_Appl_Output_T *appl_out)
{
   int i;
   XCP_Data_T *p_xcp_data               = appl_in->appl_xcp_data_ptr;
   Detection_Stream_T *p_af_det         = appl_out->appl_detection_stream_data_ptr;
   Detection_Debug_Stream_T *p_af_debug = appl_out->appl_detection_debug_data_ptr;
   Angle_Data_XCP_T *p_xcp_af_data      = appl_out->appl_af_xcp_data_ptr;

   if (Angle_Finding_Determine_XCP_Mode(appl_in))
   {
      p_xcp_af_data->snr        = p_xcp_data->rdd2_xcp_snr;
      p_xcp_af_data->ran        = p_xcp_data->rdd2_xcp_range * (SCALE_P21_TO_FLOAT);
      p_xcp_af_data->vel        = p_xcp_data->rdd2_xcp_range_rate * (SCALE_P21_TO_FLOAT);
      p_xcp_af_data->num_af_det = p_af_det->num_af_det;
      p_xcp_af_data->rdd_idx    = p_af_det->af_dets[0].rdd_idx;

      for (i = 0; i < (int)AF_MULTI_TARGET_DETS_L; i++)
      {
         p_xcp_af_data->theta[i]             = p_af_det->af_dets[i].theta;
         p_xcp_af_data->phi[i]               = p_af_det->af_dets[i].phi;
         p_xcp_af_data->pow[i]               = p_af_det->af_dets[i].pow;
         p_xcp_af_data->spec_res[i]          = p_af_det->af_dets[i].spec_res;
         p_xcp_af_data->az_conf[i]           = p_af_det->af_dets[i].az_conf;
         p_xcp_af_data->el_conf[i]           = p_af_det->af_dets[i].el_conf;
         p_xcp_af_data->az_af_type[i]        = p_af_debug->af_debug_detections[i].az_af_type;
         p_xcp_af_data->el_af_type[i]        = p_af_debug->af_debug_detections[i].el_af_type;
         p_xcp_af_data->f_single_target[i]   = p_af_det->af_dets[i].f_single_target;
         p_xcp_af_data->f_superres_target[i] = p_af_det->af_dets[i].f_superres_target;
         p_xcp_af_data->f_bistatic[i]        = p_af_det->af_dets[i].f_bistatic;
         p_xcp_af_data->f_1az2el[i]          = p_af_debug->af_debug_detections[i].f_1az2el;
         p_xcp_af_data->rcs[i]               = p_af_det->af_dets[i].rcs;
         g_af_xcp_below_af_sen_thld[i]       = p_af_debug->af_debug_detections[i].below_af_sen_thld;
      }
   }

   return AF_E_OK;
}

/**
 * @brief Processes angle finding for the application.
 *
 * This function performs the angle finding process using the provided input data
 * and populates the output structure with the results.
 *
 * @param appl_in Pointer to the AF_Appl_Input_T structure containing input data:
 *   - Appl_RDD_data_ptr: Pointer to RDD_Data_T structure
 *   - Appl_Look_data_ptr: Pointer to Look_Data_T structure
 *   - Appl_XCP_data_ptr: Pointer to XCP_Data_T structure
 *   - Appl_XCP_info_data_ptr: Pointer to XCP_Info_T structure
 *   - Appl_veh_speed_ptr: Pointer to float32_t representing vehicle speed
 *   - Appl_radar_position_ptr: Pointer to uint8_t representing radar position.
 *   - Appl_doppler_start_time: Input to anglefinding so that it can use
 *                              any remaining frame time for additional processing
 *
 * @param appl_out Pointer to the AF_Appl_Output_T structure to store output data:
 *   - Appl_Detection_stream_data_ptr: Pointer to Detection_Stream_T structure
 *   - Appl_AF_XCP_data_ptr: Pointer to Angle_Data_XCP_T structure
 *
 * @return AF_Retval_T Returns status result of the angle finding pipeline.
 *         In particular, returns AF_E_PARAM if invalid parameters are provided.
 *
 * @warning Both input and output pointers must be valid and properly initialized
 *          before calling this function.
 *
 * @see AF_Appl_Input_T
 * @see AF_Appl_Output_T
 * @see AF_Retval_T
 */
AF_Retval_T Appl_Angle_Finding_Process(AF_Appl_Input_T *appl_in, AF_Appl_Output_T *appl_out)
{
   AF_Retval_T process_return                 = AF_E_PARAM;
   Angle_Finding_Input_T *af_input_data_ptr   = Get_af_input_data_ptr();
   Angle_Finding_Output_T *af_output_data_ptr = Get_af_output_data_ptr();
   const void *const af_in_out_ptrs[]         = {(const void *)appl_in, (const void *)appl_out, (const void *)af_input_data_ptr,
                                         (const void *)af_output_data_ptr};

   if (NULL_PTR_CHECK(af_in_out_ptrs))
   {
      process_return = Angle_Finding_Process_Init(appl_in, appl_out);
      if (AF_E_OK == process_return)
      {
         process_return = Angle_Finding_Execute(af_input_data_ptr, af_output_data_ptr);
         process_return |= Angle_Finding_Complete_Target_Information(appl_in, appl_out);
         /* Angle_Finding_Update_Metrics doesn't currently do additional null-pointer
            checks so don't execute it if Angle_Finding_Process_Init returns an error */
         Angle_Finding_Update_Metrics(appl_out, process_return);
      }
   }

   return process_return;
}

/**
 * @brief Initializes memory for the Angle Finding module.
 *
 * This function is responsible for setting up the memory pool required for the
 * Angle Finding module's operations. It allocates and initializes the necessary
 * memory structures within the provided memory pool.
 *
 * @param dram_mem_pool Pointer to the memory pool structure (Mem_Pool_T) where
 *                      the Angle Finding module's memory will be allocated.
 *
 * @param sram_mem_pool Pointer to the memory pool structure (Mem_Pool_T) where
 *                      the Angle Finding module's memory will be allocated.
 *
 * @return Memory_Pool_Return_T An enumeration value indicating the result of
 *         the memory initialization:
 *         - MEMORY_POOL_SUCCESS if initialization was successful
 *         - An error code if initialization failed (specific error codes
 *           should be defined in the Memory_Pool_Return_T enumeration)
 *
 * @note This function should be called once in each cycle before calling
 *       Appl_Down_Selection_Process. At the end of the Down Selection
 *       execution, call Mem_Pool_Reset for both mempools to release the
 *       memory.
 *
 * @warning The mem_pool pointer must not be NULL and should point to a valid,
 *          initialized Mem_Pool_T structure.
 *
 * @see Mem_Pool_T
 * @see Memory_Pool_Return_T
 */
Memory_Pool_Return_T Anglefinding_Memory_Init(Mem_Pool_T *dram_mem_pool, Mem_Pool_T *sram_mem_pool)
{
   Memory_Pool_Return_T retval = MEM_POOL_SUCCESS;
   AF_Internal_Mem_Info_T *AF_Internal_memory_ptr;
   size_t i;
   size_t n = Get_AF_Internal_Memory_Pointers(&AF_Internal_memory_ptr);

   for (i = 0; i < n; i++)
   {
      // sanity check
      if ((NULL == AF_Internal_memory_ptr[i].addr_ptr) || (0U == AF_Internal_memory_ptr[i].size))
      {
         retval = MEM_POOL_FAILURE;
         break;
      }

      switch (AF_Internal_memory_ptr[i].info)
      {
         case AF_MEMPOOL_DRAM:
            retval = Mem_Pool_Alloc(dram_mem_pool, (uint32_t)AF_Internal_memory_ptr[i].size, AF_Internal_memory_ptr[i].addr_ptr);
            break;
         case AF_MEMPOOL_SRAM:
            retval = Mem_Pool_Alloc(sram_mem_pool, (uint32_t)AF_Internal_memory_ptr[i].size, AF_Internal_memory_ptr[i].addr_ptr);
            break;
         case AF_MEMPOOL_DISABLE: // invalid mempool type
         default:                 // unknown mempool type
            retval = MEM_POOL_FAILURE;
            break;
      }

      if (retval != MEM_POOL_SUCCESS)
      {
         break;
      }
   }

   return retval;
}

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
/**
 * @brief Initializes memory for the Down Selection module.
 *
 * This function is responsible for setting up the memory pool required for the
 * Down Selection module's operations. It allocates and initializes the necessary
 * memory structures within the provided memory pool.
 *
 * @param mem_pool Pointer to the memory pool structure (Mem_Pool_T) where the
 *                 Down Selection module's memory will be allocated.
 *
 * @return Memory_Pool_Return_T An enumeration value indicating the result of
 *         the memory initialization:
 *         - MEMORY_POOL_SUCCESS if initialization was successful
 *         - An error code if initialization failed (specific error codes
 *           should be defined in the Memory_Pool_Return_T enumeration)
 *
 * @note This function should be called once in each cycle before calling
 *       Angle_Finding_Execute. At the end of the Angle Finding execution, call
 *       Mem_Pool_Reset for both mempools to release the memory.
 *
 * @warning The mem_pool pointer must not be NULL and should point to a valid,
 *          initialized Mem_Pool_T structure.
 *
 * @see Mem_Pool_T
 * @see Memory_Pool_Return_T
 */
Memory_Pool_Return_T DownSelection_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;
   uint8_t mem_loc             = 0U;

   AF_Internal_Mem_Info_T *DS_Internal_memory_ptr = Get_DS_Internal_memory_pointers();

   do
   {
      if ((NULL != DS_Internal_memory_ptr[mem_loc].addr_ptr) && (0U != DS_Internal_memory_ptr[mem_loc].size))
      {
         retVal = Mem_Pool_Alloc(mem_pool, DS_Internal_memory_ptr[mem_loc].size, DS_Internal_memory_ptr[mem_loc].addr_ptr);
      }
      mem_loc++;
   } while ((MEM_POOL_SUCCESS == retVal) && (mem_loc < AF_DS_MAX_NUM_MEMORY_LOC));

   return retVal;
}

/******************************************************************************
 *. Name: AF_Downselection_Init
 *.    Function to AF_Downselection_Init.
 *.
 *. This function is to initialize the input/output data struct for down-selection
 *.
 *. Parameters:
 *. Return Value: AF_Retval_T
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static AF_Retval_T AF_Downselection_Init(AF_DownSelection_In_Out_Params_T *af_ds_init_params, Downselection_Cal_T *ds_cal_ptr,
                                         Vehicle_Configuration_Cal_T *veh_conf_cal_ptr,
                                         Secondpass_Threshold_Cal_T *sp_threshold_cal_ptr, AF_Appl_Input_T *appl_in,
                                         AF_Appl_Output_T *appl_out)
{
   AF_Retval_T process_init_return            = AF_E_PARAM;
   Angle_Finding_Output_T *af_output_data_ptr = Get_af_output_data_ptr();
   #if AF_DS_ENABLE_FEAT_BASED_L
   float32_t yaw_angle;
   #endif

   /* register start time for downselection */
   g_af_ds_start_time          = AF_Get_Timing_Counter();
   g_af_downselection_xput_ctr = 0;

   const void *const af_ds_in_out_ptrs[] = {
      (const void *)af_ds_init_params,    (const void *)ds_cal_ptr, (const void *)veh_conf_cal_ptr,
      (const void *)sp_threshold_cal_ptr, (const void *)appl_in,    (const void *)appl_out,
      (const void *)af_output_data_ptr,
   };

   if (NULL_PTR_CHECK(af_ds_in_out_ptrs))
   {
      const void *const af_ds_appl_in_out_ptrs[] = {
         (const void *)appl_in->appl_look_data_ptr,
         (const void *)appl_in->calib_data_ptr,
         (const void *)appl_in->appl_veh_speed_ptr,
         (const void *)appl_in->appl_radar_position_ptr,
         (const void *)appl_out->appl_down_selection_stream_data_ptr,
      };

      if (NULL_PTR_CHECK(af_ds_appl_in_out_ptrs))
      {
         process_init_return = AF_E_OK;
      }
   }

   if (AF_E_OK == process_init_return)
   { /* contract checking succeeded, proceed with initializiation */

      /* Stream Header update */
      appl_out->appl_down_selection_stream_data_ptr->stream_hdr.scan_index = appl_in->appl_look_data_ptr->scan_index;
      appl_out->appl_down_selection_stream_data_ptr->stream_hdr.size       = sizeof(Down_selection_Stream_T);

      /* Down Selection interface mapping */
      af_ds_init_params->af_det_ptr    = &af_output_data_ptr->afbb_det_output.af_data;
      af_ds_init_params->af_ds_det_ptr = &af_output_data_ptr->afbb_ds_det_output;

      af_output_data_ptr->afbb_ds_det_output.p_num_af_ds_det = &(appl_out->appl_down_selection_stream_data_ptr->num_af_ds_det);
      af_output_data_ptr->afbb_ds_det_output.p_af_ds_dets =
         (AF_Detection_T *)appl_out->appl_down_selection_stream_data_ptr->af_ds_dets;

      memcpy((void *)&appl_out->appl_down_selection_stream_data_ptr->det_list_property,
             (const void *)&appl_out->appl_detection_stream_data_ptr->det_list_property, sizeof(AF_DS_Str_Det_List_Property_T));

      /* Down selection SMC threshold parameters */
      af_ds_init_params->enable_downselection_ptr       = &ds_cal_ptr->k_enable_downselection;
      af_ds_init_params->ds_enable_aa_az_ptr            = &ds_cal_ptr->k_ds_enable_aa_az;
      af_ds_init_params->ds_enable_aa_el_ptr            = &ds_cal_ptr->k_ds_enable_aa_el;
      af_ds_init_params->ds_enable_az_proj_ptr          = &ds_cal_ptr->k_ds_enable_az_proj;
      af_ds_init_params->ds_enable_el_proj_ptr          = &ds_cal_ptr->k_ds_enable_el_proj;
      af_ds_init_params->ds_num_unfolding_intervals_ptr = &ds_cal_ptr->k_ds_num_unfolding_intervals;
      af_ds_init_params->ds_score_selection_ptr         = &ds_cal_ptr->k_ds_score_selection;
      af_ds_init_params->vua_ptr                        = sp_threshold_cal_ptr->k_vua; // k_vua_smc;;
      af_ds_init_params->ds_moving_thold_ptr            = &ds_cal_ptr->k_ds_moving_thold;
      af_ds_init_params->ds_max_target_reports_ptr      = &ds_cal_ptr->k_ds_max_target_reports;

      /* Sensor mounting position from SMC */
      af_ds_init_params->sensor_mount_pos_x_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x;
      af_ds_init_params->sensor_mount_pos_y_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y;
      af_ds_init_params->sensor_mount_pos_z_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z;
      af_ds_init_params->sensor_mount_ornt_roll_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll;
      af_ds_init_params->sensor_mount_ornt_pitch_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch;
      af_ds_init_params->sensor_mount_ornt_yaw_ptr =
         &appl_in->calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw;

      /* Vehicle speed, radar position and Look ID*/
      af_ds_init_params->vehicle_speed_ptr  = appl_in->appl_veh_speed_ptr;
      af_ds_init_params->radar_position_ptr = appl_in->appl_radar_position_ptr;
      af_ds_init_params->look_id_ptr        = &appl_in->appl_look_data_ptr->look_id;

   #if AF_DS_ENABLE_FEAT_BASED_L

      af_ds_init_params->ds_flr_mount_idx_ptr = &ds_cal_ptr->k_ds_flr_mount_idx;
      af_ds_init_params->distance_front_bumper_to_rear_axle_ptr =
         &appl_in->calib_data_ptr->vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
      af_ds_init_params->ds_enable_feat_based_ptr  = &ds_cal_ptr->k_ds_enable_feat_based;
      af_ds_init_params->feat_based_host_speed_ptr = ds_cal_ptr->k_feat_based_host_speed_vec;
      af_ds_init_params->zone_b_vcs_y_ptr          = &ds_cal_ptr->k_range_weight_low_host_speed_zone_b_front_vcs_y_max;
      af_ds_init_params->zone_a_range_max_ptr      = &ds_cal_ptr->k_range_weight_zone_a_range_max;

      // pass these smc's as is to the afbb, then make the necessary adjustments in the afbb based on the sensor mounting position
      // and orientation
      af_ds_init_params->low_host_speed_zone_b_front_vcs_x_min_ptr =
         &ds_cal_ptr->k_range_weight_low_host_speed_zone_b_front_vcs_x_min;
      af_ds_init_params->low_host_speed_zone_b_front_vcs_x_max_ptr =
         &ds_cal_ptr->k_range_weight_low_host_speed_zone_b_front_vcs_x_max;
      af_ds_init_params->high_host_speed_zone_b_front_range_max_ptr =
         &ds_cal_ptr->k_range_weight_high_host_speed_zone_b_front_range_max;
      af_ds_init_params->high_host_speed_zone_b_front_az_max_ptr = &ds_cal_ptr->k_range_weight_high_host_speed_zone_b_front_az_max;
      af_ds_init_params->high_host_speed_zone_b_front_az_min_ptr = &ds_cal_ptr->k_range_weight_high_host_speed_zone_b_front_az_min;
      af_ds_init_params->med_host_speed_zone_b_front_range_max_ptr =
         &ds_cal_ptr->k_range_weight_med_host_speed_zone_b_front_range_max;
      af_ds_init_params->med_host_speed_zone_b_front_az_max_ptr = &ds_cal_ptr->k_range_weight_med_host_speed_zone_b_front_az_max;
      af_ds_init_params->med_host_speed_zone_b_front_az_min_ptr = &ds_cal_ptr->k_range_weight_med_host_speed_zone_b_front_az_min;

      yaw_angle                        = af_ds_init_params->sensor_mount_ornt_yaw_ptr[*af_ds_init_params->radar_position_ptr - 1];
      af_ds_init_params->f_rear_sensor = (yaw_angle > RADAR_PI_BY_2) || (yaw_angle < -RADAR_PI_BY_2);

      af_ds_init_params->motion_max_range_ptr                  = &ds_cal_ptr->k_motion_max_range;
      af_ds_init_params->motion_weight_threshold_high_conf_ptr = &ds_cal_ptr->k_motion_weight_threshold_vec[0];
      af_ds_init_params->motion_weight_threshold_low_conf_ptr  = &ds_cal_ptr->k_motion_weight_threshold_vec[1];
   #endif

      /* Provides AF downselection input parameter details to verify Integration Testing.
       * This section executes only when the Integration_Testing macro is enabled.
       */
      SIT_AF_DOWNSELECTION(af_ds_init_params);
   } /* AF_E_OK == process_init_return */

   return process_init_return;
}

/**
 * @brief Processes down-selection for the application.
 *
 * This function performs down-selection (post AF) Populates the down-selection stream.
 *
 * @param appl_in Pointer to the AF_Appl_Input_T structure containing input data:
 *   - Appl_Look_data_ptr: Pointer to Look_Data_T structure
 *   - Appl_veh_speed_ptr: Pointer to float32_t representing vehicle speed
 *   - Appl_radar_position_ptr: Pointer to uint8_t representing radar position.
 *
 * @param appl_out Pointer to the AF_Appl_Output_T structure to store output data:
 *   - Appl_Detection_stream_data_ptr: Pointer to Detection_Stream_T structure
 *   - appl_down_selection_stream_data_ptr:  Pointer to Down_selection_Stream_T structure
 *
 * @return AF_Retval_T
 *
 * @warning Both input and output pointers must be valid and properly initialized
 *          before calling this function.
 *
 */
AF_Retval_T Appl_Down_Selection_Process(AF_Appl_Input_T *appl_in, AF_Appl_Output_T *appl_out)
{
   AF_Retval_T process_return                       = AF_E_PARAM;
   Downselection_Cal_T *ds_cal_ptr                  = Get_Downselection_Cal();
   Vehicle_Configuration_Cal_T *veh_conf_cal_ptr    = Get_Vehicle_Configuration_Cal();
   Secondpass_Threshold_Cal_T *sp_threshold_cal_ptr = Get_Secondpass_Threshold_Cal();

   AF_DownSelection_In_Out_Params_T af_ds_inout_param; // added to the types file in the AFBB

   process_return =
      AF_Downselection_Init(&af_ds_inout_param, ds_cal_ptr, veh_conf_cal_ptr, sp_threshold_cal_ptr, appl_in, appl_out);
   if (AF_E_OK == process_return)
   {
      process_return = AF_Downselection_Execute(&af_ds_inout_param);

      AF_Accumulate_Profiling_Counter(g_af_ds_start_time, &g_af_downselection_xput_ctr);
      if (NULL != appl_out->appl_af_timing_data_ptr)
      {
         appl_out->appl_af_timing_data_ptr->num_af_downselection  = *(af_ds_inout_param.af_det_ptr->p_num_af_det);
         appl_out->appl_af_timing_data_ptr->af_xput_downselection = Timing_Helpers_Get_Time_Sec_Float(g_af_downselection_xput_ctr);
      }
   }

   return process_return;
}
#endif /* AF_DOWNSELECTION_ENABLE_L */
