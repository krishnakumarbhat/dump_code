/**
 * @file appl_sp_ifc.c
 *
 * Application interface mapping for Second pass
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
 * Application interface mapping for Second Pass module
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
#include "api/second_pass.h"
#include "appl_rdd_prv.h"
#include "appl_sp_ifc.h"
#include "ipc_dsp.h"
#include "rdd_debug_stream.h"
#include "smc_cal.h"
#include "spbb_cfg.h"
#include "spbb_math.h"
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define SFW_ENABLE      (0x02U)
#define SHIFT_FACTOR_48 ((int16_t)48)

/*===========================================================================*/
/*        Local Inline Function Definitions and Function-Like Macros         */
/*===========================================================================*/
static inline void Calculate_XCP_Output(RDD_Data_T *p_rdd_data, XCP_Data_T *xcp_data_ptr, const uint16_t angle_idx);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/******************************************************************************
 *  @b Description
 *  @n
 *       Do configuration for Second Pass processing.
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for an error
 ******************************************************************************/
bool Appl_Second_Pass_Init(Radar_Look_T look_id)
{
   /* Creating a local RDD second pass config variable to copy the config value from SMC and USC*/
   Rdd_Second_Pass_Config_T rdd_sp_cfg = {0};

   /* copy  second pass configuration from SMC buffer to SPBB config variable */
   rdd_sp_cfg.rbin_res                     = k_rbin_res_smc[look_id];
   rdd_sp_cfg.dbin_res                     = k_dbin_res_smc[look_id];
   rdd_sp_cfg.doppler_fft_size             = MAX_DOPPLER_FFT_SIZE;
   rdd_sp_cfg.k_chirp_slope_sign           = k_chirp_slope_sign_smc[look_id];
   rdd_sp_cfg.k_rwin_sll_sp                = k_rwin_sll_smc;
   rdd_sp_cfg.k_sfw_coeff_r1               = k_sfw_coeff_r1_smc[look_id];
   rdd_sp_cfg.k_sfw_coeff_r1_r2_reciprocal = k_sfw_coeff_r1_r2_reciprocal_smc[look_id];
   rdd_sp_cfg.k_sfw_coeff_r2               = k_sfw_coeff_r2_smc[look_id];
   rdd_sp_cfg.k_sfw_coeff_v_reciprocal     = k_sfw_coeff_v_reciprocal_smc[look_id];
   rdd_sp_cfg.k_sfw_f_primary              = k_sfw_f_primary_smc[look_id];
   rdd_sp_cfg.k_sfw_f_secondary            = k_sfw_f_secondary_smc[look_id];
   rdd_sp_cfg.secondary_freq_bin_res       = k_secondary_freq_bin_res_smc[look_id];
   rdd_sp_cfg.secondary_range_bin_res      = k_secondary_range_bin_res_smc[look_id];
   rdd_sp_cfg.secondary_range_coverage     = k_secondary_range_coverage_smc[look_id];
   rdd_sp_cfg.vun_sp                       = k_vua_smc[look_id];
   rdd_sp_cfg.range_bias                   = k_rbin_bias_correction_factor_smc[look_id];
   rdd_sp_cfg.k_rdotmin_sp                 = k_rdotmin_smc;
   rdd_sp_cfg.k_fr2                        = k_fr2_smc[look_id];
   rdd_sp_cfg.k_slow_freq_res              = k_sfw_freq_per_bin_slow_time_smc[look_id];
   if (SFW_ENABLE == k_rdd_processing_smc[look_id])
   {
      rdd_sp_cfg.sfw_enable_flag = true;
   }

   else
   {
      rdd_sp_cfg.sfw_enable_flag = false;
   }

   /*copy  second pass configuration from SMC buffer to SPBB config variable */
   rdd_sp_cfg.k_sig_sp   = k_sig_snr_compensation_smc[look_id];
   rdd_sp_cfg.k_noise_sp = k_noise_compensation_smc[look_id];
   /* Update xcp test mode flag*/
   rdd_sp_cfg.xcp_rdd_vary_xput_flag = p_rdd_int_buff->xcp_rdd_vary_xput_flag;

   return (RDD_SECOND_PASS_NO_ERROR == Rdd_Second_Pass_Init(&rdd_sp_cfg));
} /*End of Appl_Second_Pass_Init()*/

/******************************************************************************
 *  @b Description
 *  @n
 *       Execute the Second Pass processing on the specified input.
 *
 * @param[in]  p_rdd_data Pointer to IPC structure.
 *
 * @return N/A
 ******************************************************************************/
void Appl_Second_Pass_Execute(RDD_Data_T *p_rdd_data)
{
   Rdd_Second_Pass_Input_T rdd_sp_in    = {0};                      /* Local bufer for RDD Second Pass input */
   Rdd_Second_Pass_Output_T rdd_sp_out  = {0};                      /* Local bufer for RDD Second Pass Output */
   Rdd_Second_Pass_Error_T rdd_sp_error = RDD_SECOND_PASS_NO_ERROR; /* Setting the RDD SP initial error as error free */
   XCP_Data_T *xcp_data_ptr             = &Get_DP_RDD_IPC_D2M_Msg_Buffer()->payload.xcp_data;

   rdd_sp_in.number_range_bins = MAX_RANGE_BINS;
   /* Input parameters for NCI */
   rdd_sp_in.p_rdd1_num_detect   = &p_rdd_data->rdd1_num_detect;
   rdd_sp_in.p_hvc_thold         = &p_rdd_data->bwdep_hvc_thold[0];
   rdd_sp_in.p_max_per_range_bin = &p_rdd_data->rdd1_max_per_range_bin[0][0];
   rdd_sp_in.p_mb_thold          = &p_rdd_data->bwdep_mb_thold[0];
   rdd_sp_in.p_nf_est            = &p_rdd_data->cfar_nf_est[0][0];
   rdd_sp_in.p_rdd1_dbinest      = &p_rdd_data->rdd1_dbinest[0];
   rdd_sp_in.p_rdd1_aindx        = &p_rdd_data->rdd1_aindx[0];
   rdd_sp_in.p_rdd1_dindx        = &p_rdd_data->rdd1_dindx[0];
   rdd_sp_in.p_rdd1_rbinest      = &p_rdd_data->rdd1_rbinest[0];
   rdd_sp_in.p_rdd1_rdop_amp     = &p_rdd_data->rdd1_rdop_amp[0];
   rdd_sp_in.p_rdd1_rindx        = &p_rdd_data->rdd1_rindx[0];
   rdd_sp_in.p_sensitivity_thold = &p_rdd_data->bwdep_sensitivity_thold[0];
   rdd_sp_in.p_firstpass_thold   = &p_rdd_data->rdd1_first_pass_thold[0][0];
   rdd_sp_in.p_scale_per_rbin    = &p_rdd_data->nci_bexp[0][0];

   /* Output parameters */
   rdd_sp_out.p_rdd2_range        = &p_rdd_data->rdd2_range[0];
   rdd_sp_out.p_rdd2_range_rate   = &p_rdd_data->rdd2_range_rate[0];
   rdd_sp_out.p_rdd2_snr          = &p_rdd_data->rdd2_snr[0];
   rdd_sp_out.p_rdd2_num_detect   = &p_rdd_data->rdd2_num_detect;
   rdd_sp_out.p_rdd2_sp_fail_flag = &p_rdd_data->rdd2_sp_fail_flag[0];
   rdd_sp_out.p_thold_zdb         = &p_rdd_int_buff->rdd2_thold_zdb[0];
   rdd_sp_out.p_thold_hvc         = &p_rdd_int_buff->rdd2_thold_hvc[0];
   rdd_sp_out.p_thold_2nd_pass    = &p_rdd_data->rdd2_thold_2nd_pass[0][0];
   rdd_sp_out.p_below_SP_thold    = &p_rdd_data->below_sp_thold[0];
   rdd_sp_out.p_below_ZDB_thold   = &p_rdd_data->below_zdb_thold[0];
   rdd_sp_out.p_below_HVC_thold   = &p_rdd_data->below_hvc_thold[0];

   /* Rdd second pass main process is triggered*/
   rdd_sp_error = Rdd_Second_Pass_Execute(&rdd_sp_in, &rdd_sp_out);

   if ((rdd_sp_error == RDD_SECOND_PASS_NO_ERROR) && (p_rdd_int_buff->xcp_doppler_idx < MAX_DOPPLER_FFT_SIZE) &&
       (p_rdd_int_buff->xcp_range_idx < MAX_RANGE_BINS))
   {
      Rdd_Second_Pass_XCP_IO_T xcp_io = {0}; /* Local buffer for RDDSP XCP input/output */
      SPBB_XCP_Config_T xcp_cfg       = {0}; /* Local buffer for RDDSP XCP configuration */
      s8p23_T temp_xcp_snr;                  /*Local variable to store integer format for snr*/

      /* Initialize Config for XCP*/
      xcp_cfg.doppler_idx = p_rdd_int_buff->xcp_doppler_idx;
      xcp_cfg.range_idx   = p_rdd_int_buff->xcp_range_idx;

      if (p_rdd_int_buff->xcp_angle_idx >= ANGLE_BINS_USED)
      {
         xcp_cfg.angle_idx = 0U;
      }
      else
      {
         xcp_cfg.angle_idx = p_rdd_int_buff->xcp_angle_idx;
      }

      /* Initialize Input for XCP from IPC */
      xcp_io.dbin_est = xcp_data_ptr->rdd1_xcp_dbin_est;
      xcp_io.rbin_est = xcp_data_ptr->rdd1_xcp_rbin_est;
      xcp_io.nf_est   = p_rdd_data->cfar_nf_est[xcp_cfg.range_idx][xcp_cfg.angle_idx];
      xcp_io.rdop_avg = xcp_data_ptr->rdd1_xcp_rdop_amp;
      /* XCP output*/
      xcp_io.p_range      = (s10p21_T *)&xcp_data_ptr->rdd2_xcp_range;
      xcp_io.p_range_rate = (s10p21_T *)&xcp_data_ptr->rdd2_xcp_range_rate;
      xcp_io.p_rdd_snr    = &temp_xcp_snr;

      xcp_data_ptr->rdd1_xcp_nf_est = xcp_io.nf_est;

      /* API call to estimate Range,range rate and snr for the XCP input*/
      if (RDD_SECOND_PASS_NO_ERROR == Rdd_Second_Pass_XCP_Output(&xcp_cfg, &xcp_io))
      {
         float32_t *p_rdd2_xcp_snr;
         p_rdd2_xcp_snr = (float32_t *)&xcp_data_ptr->rdd2_xcp_snr;
         RADAR_FLOAT(*xcp_io.p_rdd_snr, 0, *p_rdd2_xcp_snr);
         *p_rdd2_xcp_snr *= SCALE_P23_TO_FLOAT;
      }

      Calculate_XCP_Output(p_rdd_data, xcp_data_ptr, xcp_cfg.angle_idx);
   }
} /*End of Appl_Second_Pass_Execute()*/

/******************************************************************************
 *  @b Description
 *  @n
 *       Update the XCP buffers for single angle bin output data.
 *
 * @param[in]  p_rdd_data Pointer to RDD stream from where the data will be read.
 * @param[out]  xcp_data_ptr Pointer to XCP structure to where the data will be written.
 * @param[in]  angle_idx   The angle index for which the XCP output is to be calculated.
 *
 * @return N/A
 ******************************************************************************/
static inline void Calculate_XCP_Output(RDD_Data_T *p_rdd_data, XCP_Data_T *xcp_data_ptr, const uint16_t angle_idx)
{
   uint32_t max_mprb_debug = 0U;
   float32_t k_rwin_sll_float, rwin_thold_unscaled, k_rwin_sll_tmp;
   int32_t rwin_thold;

   uint16_t *nci_bexp_ptr         = &p_rdd_data->nci_bexp[0][angle_idx];
   uint32_t *cfar_thold_ptr       = &p_rdd_data->cfar_thold[0][angle_idx];
   uint16_t *first_pass_thold_ptr = &p_rdd_data->rdd1_first_pass_thold[0][angle_idx];
   uint16_t *mprb_ptr             = &p_rdd_data->rdd1_max_per_range_bin[0][angle_idx];
   uint16_t *cfar_nf_est_ptr      = &p_rdd_data->cfar_nf_est[0][angle_idx];

   uint32_t *mprb_abin_ptr        = &xcp_data_ptr->mprb_abin[0];
   uint32_t *first_pass_abin_ptr  = &xcp_data_ptr->first_pass_abin[0];
   uint32_t *cfar_abin_ptr        = &xcp_data_ptr->cfar_abin[0];
   uint32_t *cfar_nf_abin_ptr     = &xcp_data_ptr->cfar_nf_abin[0];
   uint32_t *second_pass_abin_ptr = &xcp_data_ptr->second_pass_abin[0];

   for (uint32_t k = 0U; k < (uint16_t)MAX_RANGE_BINS; k++)
   {
      int16_t block_exp_shift = (int16_t)(SHIFT_FACTOR_48 - *nci_bexp_ptr);

      if (block_exp_shift >= 0)
      {
         *mprb_abin_ptr       = (uint32_t)*mprb_ptr << block_exp_shift;
         *first_pass_abin_ptr = (uint32_t)*first_pass_thold_ptr << block_exp_shift;
         *cfar_abin_ptr       = (uint32_t)*cfar_thold_ptr << block_exp_shift;
         *cfar_nf_abin_ptr    = (uint32_t)*cfar_nf_est_ptr << block_exp_shift;
      }
      else
      {
         block_exp_shift *= -1;
         *mprb_abin_ptr       = (uint32_t)*mprb_ptr >> block_exp_shift;
         *first_pass_abin_ptr = (uint32_t)*first_pass_thold_ptr >> block_exp_shift;
         *cfar_abin_ptr       = (uint32_t)*cfar_thold_ptr >> block_exp_shift;
         *cfar_nf_abin_ptr    = (uint32_t)*cfar_nf_est_ptr >> block_exp_shift;
      }

      if (*mprb_abin_ptr > max_mprb_debug)
      {
         max_mprb_debug = *mprb_abin_ptr;
      }

      nci_bexp_ptr += ANGLE_BINS_USED;
      cfar_thold_ptr += ANGLE_BINS_USED;
      first_pass_thold_ptr += ANGLE_BINS_USED;
      mprb_ptr += ANGLE_BINS_USED;
      cfar_nf_est_ptr += ANGLE_BINS_USED;

      mprb_abin_ptr++;
      first_pass_abin_ptr++;
      cfar_abin_ptr++;
      cfar_nf_abin_ptr++;
   }

   // TODO: this can be removed with new second pass updates
   RADAR_UFLOAT((uint32_t)k_rwin_sll_smc, 0, k_rwin_sll_tmp);
   k_rwin_sll_float    = SCALE_P16_TO_FLOAT * k_rwin_sll_tmp;
   rwin_thold_unscaled = k_rwin_sll_float * (float32_t)max_mprb_debug;
   RADAR_ROUND32(rwin_thold_unscaled, 0, rwin_thold);

   first_pass_abin_ptr = &xcp_data_ptr->first_pass_abin[0];

   for (uint32_t k = 0U; k < (uint16_t)MAX_RANGE_BINS; k++)
   {
      uint32_t sp_debug_thold = first_pass_abin_ptr[k] + (uint32_t)rwin_thold;

      if (sp_debug_thold > p_rdd_data->bwdep_sensitivity_thold[k])
      {
         second_pass_abin_ptr[k] = sp_debug_thold;
      }
      else
      {
         second_pass_abin_ptr[k] = p_rdd_data->bwdep_sensitivity_thold[k];
      }
   }
}
