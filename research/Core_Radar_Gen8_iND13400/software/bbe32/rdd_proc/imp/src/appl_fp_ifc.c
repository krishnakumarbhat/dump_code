/**
 * @file appl_fp_ifc.c
 *
 * Application interface mapping for first pass.
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
 * Application interface mapping for Firstpass Process module
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
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "api/bbe_helpers.h"
#include "api/timing_helpers.h"
#include "appl_fp_ifc.h"
#include "appl_rdd_prv.h"
#include "doppler_process.h"
#include "doppler_process_ifc.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "mem_pool.h"
#include "rdd_debug_stream.h"
#include "rdd_first_pass.h"
#include "rdd_first_pass_types.h"
#include "rdd_stream.h"
#include "smc_cal.h"
#include "spbb_cfg.h"
#include "spbb_configuration.h"
#include "spbb_math.h"
#include "usc_cal.h"
#ifdef CDC_ENABLE
   #include "api/cdc.h"
   #include "api/cdc_types.h"
   #include "cdc_packing.h"
#endif
/* ========================================================================== */
/*                     SWE5 Integration Test Hook                             */
/* ========================================================================== */
#include "dsp_it_macros_test.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define CLEAR_BEXP_VALUE               (63U)
#define RDD_ADJ_BV_CIRCULAR_BUFF_DEPTH (BV_CIRCULAR_BUFF_DEPTH - 1U)
#define SPE_GAIN_INCREMENT             (0.1f)
/* ========================================================================== */
/*                         Local Object Definitions                           */
/* ========================================================================== */
/* ========================================================================== */
/*                           External variables                               */
/* ========================================================================== */
RDD_Internal_Buff_T *p_rdd_int_buff = NULL;
/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

s8p23_T __attribute__((section(".sram1.data"))) XCP_Range_Bin_BV_Variance[NUM_CDM_CHANNELS * NUM_RX_CHANNELS];

/* ========================================================================== */
/*                         Static Inline Functions                            */
/* ========================================================================== */

volatile uint16_t XCP_Max_Static_PrBin_Max_Tgts = 5U;
/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                     Internal Function Declarations                         */
/* ========================================================================== */

static void First_Pass_Execute_Setup(uint16_t ridx, D2M_Msg_T *d2m_msg_ptr, Rdd_First_Pass_Input_T *rdd_fp_input,
                                     Rdd_First_Pass_Output_T *rdd_fp_output);

/*===========================================================================*/
/*        Local Inline Function Definitions and Function-Like Macros         */
/*===========================================================================*/

#ifdef CDC_ENABLE
/******************************************************************************
 *  @b Description
 *  @n
 *       Do configuration for cdc processing.
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for an error
 ******************************************************************************/
bool Appl_Cdc_Init(Radar_Look_T look_id)
{
   Cdc_Config_T cdc_cfg      = {0};
   cdc_cfg.doppler_fft_size  = MAX_DOPPLER_FFT_SIZE;
   cdc_cfg.number_range_bins = SPBB_USED_RANGE_BINS;
   cdc_cfg.k_bv_shift_idx    = k_ddma_doppler_bin_shift_smc[look_id];
   /* Call for spbb cdc config func*/
   return (CDC_PROCESS_NO_ERROR == Cdc_Process_Init(&cdc_cfg));
}
/**
 *  @b Description
 *  @n
 *   This function returns the pointer of cdc_dbin_array stored in Internal buffer
 *  @param[out] : Address of cdc_dbin_array stored in Internal buffer
 **/
uint16_t *Get_Cdc_Dbin_Array_Buffer_Ptr(void)
{
   return &p_rdd_int_buff->cdc_dbin_array[0];
}

#endif
/**
 *  @b Description
 *  @n
 *   Allocate the RDD buffer on the memory pool.
 *
 * @param[in]  mem_pool - Pointer to the memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T Appl_Rdd_Dram1_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T ret_val = MEM_POOL_FAILURE;

   ret_val = Mem_Pool_Alloc(mem_pool, sizeof(RDD_Internal_Buff_T), (void **)&p_rdd_int_buff);

   return ret_val;
}

/*===========================================================================*
 *                          Function Definitions
 *===========================================================================*/
/**
 * @brief Function to dump the beamvectors for all doppler bins in a selected range index.
 *        If @ref range_idx matches @ref xcp_range_idx_bv_var, then the beamvectors are copied
 *        and the variance is calculated.
 *
 * @param[in1]: range_idx
 * @param[in2]: xcp_dfft_bv_output_buffer
 * @param[in3]: xcp_range_idx_bv_var
 * @param[out]
 * returns none
 */

void Handle_Xcp_Beamvector_Data(uint16_t range_idx,
                                BV_Comp_Type_T (*xcp_dfft_bv_output_buffer)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE],
                                uint16_t xcp_range_idx_bv_var)
{
   if (range_idx == xcp_range_idx_bv_var)
   {
      s8p23_T *xcp_range_bin_beamvector_variance = XCP_Range_Bin_BV_Variance;

      Calculate_BV_Variance(xcp_range_bin_beamvector_variance, xcp_dfft_bv_output_buffer, &p_rdd_int_buff->xcp_bv_var);
   }
}

/**
 *  @b Description
 *  @n
 *   Run First Pass for range bins other than 0.
 *
 * @param[in]  d2m_msg_ptr - Pointer to the output D2M IPC buffer
 * @param[in]  p_beam_vector_data - Pointer to the current beamvector data
 *
 * @return true for success, false for failure
 *
 **/
bool Appl_First_Pass_Execute(uint16_t ridx, D2M_Msg_T *d2m_msg_ptr,
                             BV_Comp_Type_T (*p_beam_vector_data)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE])

{
   Rdd_First_Pass_Error_T rdd_first_pass_err = RDD_FIRST_PASS_NO_ERROR;
   Rdd_First_Pass_Input_T rdd_fp_input       = {0};
   Rdd_First_Pass_Output_T rdd_fp_output     = {0};
   RDD_Data_T *p_rdd_data                    = &d2m_msg_ptr->payload.rdd_stream_data.rdd_data;
#ifdef CDC_ENABLE
   Look_Data_T *p_look_data = &d2m_msg_ptr->payload.rdd_stream_data.look_data;
#endif
   // Invalidate the BV memory.
   xthal_dcache_block_invalidate(&(*p_beam_vector_data)[0][0], sizeof(*p_beam_vector_data));

   rdd_fp_input.p_beam_vector_data = p_beam_vector_data;

   First_Pass_Execute_Setup(ridx, d2m_msg_ptr, &rdd_fp_input, &rdd_fp_output);

   rdd_fp_input.p_bexp_prev = p_rdd_data->nci_bexp[ridx - 1];
   rdd_fp_input.p_bexp_next = p_rdd_data->nci_bexp[ridx + 1];

   rdd_first_pass_err = Rdd_First_Pass_Execute(&rdd_fp_input, &rdd_fp_output);

   Handle_Xcp_Beamvector_Data(ridx, p_beam_vector_data, p_rdd_int_buff->xcp_range_idx_bv_variance);

#ifdef CDC_ENABLE
   Cdc_Packing(p_look_data, ridx, p_rdd_int_buff->cdc_dbin_cnt, p_beam_vector_data);
#endif

   /* Provides rdd_fp_input parameter details to verify Integration Testing.
    * This section executes only when the Integration_Testing macro is enabled.
    */
   SIT_FP_RDD_INPUT(&rdd_fp_input);

   return (RDD_FIRST_PASS_NO_ERROR == rdd_first_pass_err);
}

/* ========================================================================== */
/*                     Internal Function Definitions                          */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *   Initialize the First pass input and output structures.
 *   NOTE- the previous and next bexp values are not configured here,
 *         they both must be initialized by the calling functions.
 *
 * @param[in]  ridx - Range index to process
 * @param[in]  d2m_msg_ptr - Pointer to the output D2M IPC buffer
 * @param[in]  rdd_fp_input - Pointer to the First Pass input structure to setup
 * @param[in]  rdd_fp_output - Pointer to the First Pass output structure to setup
 *
 * @return N/A
 *
 **/

static void First_Pass_Execute_Setup(uint16_t ridx, D2M_Msg_T *d2m_msg_ptr, Rdd_First_Pass_Input_T *rdd_fp_input,
                                     Rdd_First_Pass_Output_T *rdd_fp_output)
{
   RDD_Data_T *p_rdd_data   = &d2m_msg_ptr->payload.rdd_stream_data.rdd_data;
   XCP_Data_T *xcp_data_ptr = &d2m_msg_ptr->payload.xcp_data;

   volatile XCP_Info_T *xcp_info_ptr = &Get_IPC_M2D_Buffer()->payload.xcp_info;
   /* Common Input parameters */
   rdd_fp_input->range_idx = ridx;
   uint16_t look_id        = d2m_msg_ptr->payload.rdd_stream_data.look_data.look_id;

   /* Input parameters for NCI */
   rdd_fp_input->prev_ptr     = rdop_avg_data_ptr[NCI_PREV_BUFFER_DEPTH];
   rdd_fp_input->curr_ptr     = rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH];
   rdd_fp_input->next_ptr     = rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH];
   rdd_fp_input->p_bexp_curr  = p_rdd_data->nci_bexp[ridx];
   rdd_fp_input->p_cfar_thold = &p_rdd_data->cfar_thold[ridx][0];
   rdd_fp_input->p_sens_thold = &p_rdd_data->bwdep_sensitivity_thold[0];

   /* RDD FP common output buffers */
   rdd_fp_output->p_rdd1_num_detect    = &p_rdd_data->rdd1_num_detect;
   rdd_fp_output->p_rdd1_rindx         = &p_rdd_data->rdd1_rindx[0];
   rdd_fp_output->p_rdd1_dindx         = &p_rdd_data->rdd1_dindx[0];
   rdd_fp_output->p_rdd1_aindx         = &p_rdd_data->rdd1_aindx[0];
   rdd_fp_output->p_rdd1_rbinest       = &p_rdd_data->rdd1_rbinest[0];
   rdd_fp_output->p_rdd1_dbinest       = &p_rdd_data->rdd1_dbinest[0];
   rdd_fp_output->p_rdd1_abinest       = &p_rdd_data->rdd1_abinest[0];
   rdd_fp_output->p_rdd1_rdop_amp      = &p_rdd_data->rdd1_rdop_amp[0];
   rdd_fp_output->p_fp_thold           = &p_rdd_data->rdd1_first_pass_thold[ridx][0];
   rdd_fp_output->p_sig_thold_1st_pass = &p_rdd_data->rdd1_signal_thold_first_pass[ridx][0];
   rdd_fp_output->p_mprb               = &p_rdd_data->rdd1_max_per_range_bin[ridx][0];

   rdd_fp_output->p_rdd1_bv = (BV_Comp_Type_T(*)[MAX_DETS_FIRST_PASS][SPBB_COMPRESSED_BV_SIZE]) & p_rdd_data->rdd1_bv;

   /* XCP Input buffers are present in IPC structure */
   rdd_fp_input->rdd_fp_xcp_ip.xcp_rdd_vary_xput_flag         = p_rdd_int_buff->xcp_rdd_vary_xput_flag;
   rdd_fp_input->rdd_fp_xcp_ip.xcp_spe_gain                   = p_rdd_int_buff->xcp_spe_gain;
   rdd_fp_input->rdd_fp_xcp_ip.xcp_max_fp_per_rbin_target_cnt = p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt;
   rdd_fp_input->rdd_fp_xcp_ip.xcp_max_fp_tgt_cnt             = p_rdd_int_buff->xcp_max_fp_tgt_cnt;
   rdd_fp_input->rdd_fp_xcp_ip.xcp_rngidx_target_start        = p_rdd_int_buff->xcp_rngidx_target_start;
#ifdef SPBB_SCM_ENABLE
   rdd_fp_input->p_scm_run_per_rbin = &p_rdd_int_buff->scm_run_per_rbin;
   rdd_fp_input->p_scm_dbin_diff    = &p_rdd_int_buff->saturation_cm_dbin_diff[0];
#endif

   if (CODED_TRUE == xcp_info_ptr->xcp_target_select_cmd)
   {
      rdd_fp_input->rdd_fp_xcp_ip.xcp_based_calib_active = true;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_range_idx          = MAX_RANGE_BINS;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_doppler_idx        = MAX_DOPPLER_FFT_SIZE;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_angle_idx          = ANGLE_BINS_USED;
   }
   else
   {
      rdd_fp_input->rdd_fp_xcp_ip.xcp_based_calib_active = false;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_range_idx          = p_rdd_int_buff->xcp_range_idx;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_doppler_idx        = p_rdd_int_buff->xcp_doppler_idx;
      rdd_fp_input->rdd_fp_xcp_ip.xcp_angle_idx          = p_rdd_int_buff->xcp_angle_idx;
   }

   for (uint8_t i = 0; i < XCP_CAL_NO_OF_TARGETS; i++)
   {
      rdd_fp_input->rdd_fp_xcp_ip.p_xcp_3p_range_idx[i] = (uint16_t *)(uintptr_t)&xcp_info_ptr->xcp_target_range_idx[look_id][i];
      rdd_fp_input->rdd_fp_xcp_ip.p_xcp_3p_doppler_idx[i] =
         (uint16_t *)(uintptr_t)&xcp_info_ptr->xcp_target_doppler_idx[look_id][i];
      rdd_fp_input->rdd_fp_xcp_ip.p_xcp_3p_angle_idx[i] = (uint16_t *)(uintptr_t)&xcp_info_ptr->xcp_target_angle_idx[look_id][i];
   }

   rdd_fp_output->rdd_fp_xcp_out.p_xcp_3p_rdopavg_rbin  = &xcp_data_ptr->xcp_cal_rdopavg_rbin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_3p_rdopavg_dbin  = &xcp_data_ptr->xcp_cal_rdopavg_dbin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_3p_rdopavg_abin  = &xcp_data_ptr->xcp_cal_rdopavg_abin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_3p_raw_bv        = (BV_Comp_Type_T *)&xcp_data_ptr->rdd1_xcp_compressed_bv_3p[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_3p_decompress_bv = (BV_Decomp_Type_T *)&xcp_data_ptr->rdd1_xcp_decompressed_bv_3p[0];

   /* XCP Output buffers are present in IPC structure */
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rdop_amp             = &xcp_data_ptr->rdd1_xcp_rdop_amp;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rbin_est             = &xcp_data_ptr->rdd1_xcp_rbin_est;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_dbin_est             = &xcp_data_ptr->rdd1_xcp_dbin_est;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_abin_est             = &xcp_data_ptr->rdd1_xcp_abin_est;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_nf_est               = &xcp_data_ptr->rdd1_xcp_nf_est;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rdopavg              = &xcp_data_ptr->rdd1_xcp_rdop_avg;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rdopavg_rbin         = &xcp_data_ptr->rdd1_xcp_rdop_avg_rbin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rdopavg_dbin         = &xcp_data_ptr->rdd1_xcp_rdop_avg_dbin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_rdopavg_abin         = &xcp_data_ptr->rdd1_xcp_rdop_avg_abin[0];
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_raw_bv               = (BV_Comp_Type_T *)&xcp_data_ptr->rdd1_xcp_compressed_bv;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_decompress_bv        = (BV_Decomp_Type_T *)&xcp_data_ptr->rdd1_xcp_decompressed_bv;
   rdd_fp_output->rdd_fp_xcp_out.p_xcp_max_per_rbin_targets = &xcp_data_ptr->xcp_max_per_rbin_targets;

#ifdef SPBB_SCM_ENABLE
   rdd_fp_output->p_rdd1_targets_saturation_flag = &p_rdd_int_buff->scm_targets_saturation_flag;
   rdd_fp_output->p_rdd1_scm_prioritization_flag = &p_rdd_int_buff->scm_prioritization_flag;
   rdd_fp_output->p_rdd1_max_rbin_processed      = &p_rdd_int_buff->scm_max_rbin_processed;
   rdd_fp_output->p_rdd1_max_detectable_range    = &p_rdd_int_buff->scm_max_detectable_range;
#endif

#ifdef CDC_ENABLE
   p_rdd_int_buff->cdc_dbin_cnt               = 0;
   rdd_fp_output->cdc_output.p_cdc_dbin_array = &p_rdd_int_buff->cdc_dbin_array[0];
   vector_clear(rdd_fp_output->cdc_output.p_cdc_dbin_array, sizeof(uint16_t) * MAX_DOPPLER_FFT_SIZE);
   rdd_fp_output->cdc_output.p_cdc_dbin_count = &p_rdd_int_buff->cdc_dbin_cnt;
#endif
}

/******************************************************************************
 *  @b Description
 *  @n
 *       Do configuration for First Pass processing.
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for an error
 ******************************************************************************/
bool Appl_Rdd_Fp_Init(Radar_Look_T look_id)
{
   bool ret_val                              = false;
   Rdd_First_Pass_Error_T rdd_first_pass_err = RDD_FIRST_PASS_NO_ERROR;
   Rdd_First_Pass_Config_T rdd_fp_cfg        = {0};
#if (CI_ENABLE == 1U)
   volatile D2M_Msg_T *d2m_msg_ptr   = Get_DP_RDD_IPC_D2M_Msg_Buffer();
   volatile XCP_Data_T *xcp_data_ptr = &d2m_msg_ptr->payload.xcp_data; // XCP configuration is updated in the interrupt context.
#endif

   rdd_fp_cfg.afft_size                   = ANGLE_BINS_USED;
   rdd_fp_cfg.num_sectors                 = k_num_doppler_sector_smc[look_id];
   rdd_fp_cfg.dfft_bins_per_sector        = k_num_doppler_sector_bin_smc[look_id];
   rdd_fp_cfg.p_ddm_shift                 = (uint16_t *)k_ddma_bin_shifts_smc[look_id];
   rdd_fp_cfg.p_k_bv_order                = k_bv_order_smc;
   rdd_fp_cfg.k_dopp_sll_rest             = k_dopp_sll_rest_smc[look_id];
   rdd_fp_cfg.k_dopp_sll_no_rest          = k_dopp_sll_no_rest_smc[look_id];
   rdd_fp_cfg.doppler_fft_size            = MAX_DOPPLER_FFT_SIZE;
   rdd_fp_cfg.range_bin_size              = MAX_RANGE_BINS;
   rdd_fp_cfg.range_log_est               = k_enable_range_logscale_frac_est_smc[look_id];
   rdd_fp_cfg.doppler_logscale_est        = k_enable_doppler_logscale_frac_est_smc[look_id];
   rdd_fp_cfg.enable_sensitivity_thold_fp = k_enable_sensitivity_thold_first_pass_smc[look_id];
#ifdef SPBB_SCM_ENABLE
   /* SMCs related to Saturation Counter Measure*/
   rdd_fp_cfg.veh_speed              = Get_IPC_M2D_Buffer()->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
   rdd_fp_cfg.scm_enable_flag        = k_saturation_cm_enable_smc;
   rdd_fp_cfg.scm_dbin_cluster_thold = k_saturation_dbin_cluster_thold_smc;
   rdd_fp_cfg.scm_host_speed_thold   = k_saturation_host_speed_smc * (SCALE_P8_TO_FLOAT);
   rdd_fp_cfg.scm_fp_dets_margin     = k_saturation_fp_dets_margin_smc;
   rdd_fp_cfg.run_scm_if_saturated   = k_run_saturation_cm_if_saturated_smc;
   rdd_fp_cfg.rbin_res_smc           = k_rbin_res_smc[look_id] * (SCALE_P16_TO_FLOAT);
#endif

   /* Spoofing in thresholds for ghost rejection */
   rdd_fp_cfg.k_nci_avg_mag_split = k_nci_mag_split_threshold_smc[look_id];

   rdd_fp_cfg.p_rdop_avg_max_collapse = &p_rdd_int_buff->nci_rdop_avg_max_collapse[0];
   rdd_fp_cfg.p_sec_idx_max_collapse  = &p_rdd_int_buff->nci_sec_idx_max_collapse[0];
   rdd_fp_cfg.p_bv_reorder_idx        = &p_rdd_int_buff->rdd1_bv_reorder_idx[0];
   rdd_fp_cfg.p_xcp_bv_order_idx      = &p_rdd_int_buff->rdd1_xcp_bv_order_idx[0];
   rdd_fp_cfg.p_decompressed_bv_temp  = &p_rdd_int_buff->rdd1_decomp_bv[0];

   rdd_first_pass_err = Rdd_First_Pass_Init(&rdd_fp_cfg);

   if (RDD_FIRST_PASS_NO_ERROR == rdd_first_pass_err)
   {
      ret_val = true;
   }
   return ret_val;
}

/**
 *  @b Description
 *  @n
 *   This function to update the RDD instrumentation variables
 *  @param[in1]
 *  @param[out]
 *
 **/
void Update_Rdd_Instrumentation_Variables(void)
{
   volatile XCP_Info_T *xcp_info_ptr = &Get_IPC_M2D_Buffer()->payload.xcp_info;
   XCP_Data_T *xcp_data_ptr          = &Get_DP_RDD_IPC_D2M_Msg_Buffer()->payload.xcp_data;

   p_rdd_int_buff->xcp_range_idx             = xcp_info_ptr->xcp_range_idx;
   p_rdd_int_buff->xcp_doppler_idx           = xcp_info_ptr->xcp_doppler_idx;
   p_rdd_int_buff->xcp_angle_idx             = xcp_info_ptr->xcp_angle_idx;
   p_rdd_int_buff->xcp_range_idx_bv_variance = xcp_info_ptr->xcp_range_idx_bv_variance;
   p_rdd_int_buff->xcp_spe_gain_max          = xcp_info_ptr->xcp_spe_gain_max;
   p_rdd_int_buff->xcp_spe_gain_min          = xcp_info_ptr->xcp_spe_gain_min;

   if (CODED_TRUE == xcp_info_ptr->xcp_rdd_vary_xput_flag)
   {
      p_rdd_int_buff->xcp_rdd_vary_xput_flag = true;

      /**Reset max per rbin target*/
      xcp_data_ptr->xcp_max_per_rbin_targets = 0U;
      if (CODED_TRUE != xcp_info_ptr->xcp_max_static_target_case_enable)
      {
         /** This is set to default value 5 to get the worst case scenario.
          * This can be set as needed and tested */
         p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt = XCP_Max_Static_PrBin_Max_Tgts;
         if (0U == p_rdd_int_buff->xcp_max_fp_tgt_cnt)
         {
            p_rdd_int_buff->xcp_max_fp_tgt_cnt = MAX_DETS_FIRST_PASS;

            if (CODED_TRUE == xcp_info_ptr->xcp_spe_gain_vary_enable_flag)
            {
               static float32_t xcp_spe_gain_local = SPE_GAIN_INCREMENT;
               xcp_spe_gain_local += SPE_GAIN_INCREMENT;

               if (xcp_spe_gain_local > p_rdd_int_buff->xcp_spe_gain_max || xcp_spe_gain_local < p_rdd_int_buff->xcp_spe_gain_min)
               {
                  xcp_spe_gain_local = p_rdd_int_buff->xcp_spe_gain_min;
               }
               else
               {
                  /* Do Nothing */
               }
               p_rdd_int_buff->xcp_spe_gain = xcp_spe_gain_local;
            }
            else
            {
               p_rdd_int_buff->xcp_spe_gain = xcp_info_ptr->xcp_spe_gain;
            }
         }
         else
         {
            p_rdd_int_buff->xcp_max_fp_tgt_cnt--;
         }

         if ((uint16_t)(MAX_RANGE_BINS - 1U) == p_rdd_int_buff->xcp_rngidx_target_start)
         {
            p_rdd_int_buff->xcp_rngidx_target_start = 0U;
         }
         else
         {
            p_rdd_int_buff->xcp_rngidx_target_start++;
         }
      }
      else
      {
         p_rdd_int_buff->xcp_spe_gain                   = xcp_info_ptr->xcp_spe_gain;
         p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt = MAX_DETS_FIRST_PASS;
         p_rdd_int_buff->xcp_rngidx_target_start        = 0U;
         p_rdd_int_buff->xcp_max_fp_tgt_cnt             = MAX_DETS_FIRST_PASS;
      }
   }
   else
   {
      p_rdd_int_buff->xcp_rdd_vary_xput_flag         = false;
      p_rdd_int_buff->xcp_max_fp_per_rbin_target_cnt = xcp_info_ptr->xcp_max_fp_per_rbin_target_cnt;
      p_rdd_int_buff->xcp_max_fp_tgt_cnt             = xcp_info_ptr->xcp_max_fp_tgt_cnt;
      p_rdd_int_buff->xcp_rngidx_target_start        = xcp_info_ptr->xcp_rngidx_target_start;
      p_rdd_int_buff->xcp_spe_gain                   = xcp_info_ptr->xcp_spe_gain;
   }
}
