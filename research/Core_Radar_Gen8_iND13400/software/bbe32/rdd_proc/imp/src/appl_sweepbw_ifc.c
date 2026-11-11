/**
 * @file appl_sweepbw_ifc.c
 *
 * Application interface mapping for first pass, second pass, and sweep BW init.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business ? Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Sweep BW module
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
#include "appl_rdd_prv.h"
#include "appl_sweepbw_ifc.h"
#include "ipc_dsp.h"
#include "smc_cal.h"
#include "spbb_cfg.h"
#include "sweep_bw.h"
#include "sweep_bw_types.h"
#include "usc_cal.h"
/*===========================================================================*/
/* Compatibility with future USC updates */
/*===========================================================================*/
#if defined(k_sensitivity_SF_USC_usc) && !defined(k_sensitivity_SF_USC_USC)
   #define k_sensitivity_SF_USC_USC k_sensitivity_SF_USC_usc
#endif
/*===========================================================================*/
/*        Local Inline Function Definitions and Function-Like Macros         */
/*===========================================================================*/

/*===========================================================================*/
/*        Local Inline Function Definitions and Function-Like Macros         */
/*===========================================================================*/
/******************************************************************************
 *  @b Description
 *  @n
 *       Do configuration for Sweep Bandwidth processing.
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for an error
 ******************************************************************************/
bool Appl_Sweep_Bw_Init(Radar_Look_T look_id)
{
   Sweep_Bw_Process_Config_T sweepbw_cfg = {0};

   sweepbw_cfg.k_sensitivity_sf_platform = k_sensitivity_sf_platform_smc;
   if (k_isUWB_smc[look_id])
   {
      sweepbw_cfg.k_sensitivity_sf_usc = k_sensitivity_SF_USC_UWB_usc;
   }
   else
   {
      sweepbw_cfg.k_sensitivity_sf_usc = k_sensitivity_SF_USC_USC;
   }
   sweepbw_cfg.p_bwdep_bb_freq_res_lut       = k_bb_freq_resp_smc;
   sweepbw_cfg.p_bwdep_hvc_profile_lut       = k_hvc_lut_smc;
   sweepbw_cfg.p_bwdep_mb_profile_lut        = k_mb_lut_smc;
   sweepbw_cfg.p_bwdep_range_atten_lut       = k_range_atten_lut_smc;
   sweepbw_cfg.p_bwdep_rcs_profile_lut       = k_rcs_lut_smc;
   sweepbw_cfg.p_af_rcs_profile_lut          = k_rcs_lut_angle_finding_smc;
   sweepbw_cfg.p_bwdep_temp_scale_factor_lut = k_temp_sens_smc;
   sweepbw_cfg.range_bias                    = k_rbin_bias_correction_factor_smc[look_id];
   sweepbw_cfg.rbin_res                      = k_rbin_res_smc[look_id];
   sweepbw_cfg.p_bwdep_range_attenuation     = &p_rdd_int_buff->bwdep_range_attenuation[0];

   return (SWEEP_BW_PROCESS_NO_ERROR == Sweep_Bw_Process_Init(&sweepbw_cfg));
} /* End of Appl_Sweep_Bw_Init() */

/******************************************************************************
 *  @b Description
 *  @n
 *       API for Sweep Bandwidth processing.
 *
 * @param[in]  *p_rdd_data
 *
 * @return void
 ******************************************************************************/
void Appl_Sweep_Bw_Execute(RDD_Data_T *p_rdd_data)
{
   Sweep_Bw_Process_Input_T sweep_bw_input   = {0};
   Sweep_Bw_Process_Output_T sweep_bw_output = {0};

   Sweep_Bw_Process_Error_T sweep_bw_error_code = SWEEP_BW_PROCESS_NO_ERROR;

   if ((ITF_ADC_INJECTION_MODE == Offline_Mode_Flag_DSP) || (ITF_DATA_CUBE_INJECTION_MODE == Offline_Mode_Flag_DSP) ||
       (ITF_TEST_COLLECTION_MODE == Offline_Mode_Flag_DSP))
   {
      sweep_bw_input.bwdep_temperature = 50;
   }
   else
   {
      sweep_bw_input.bwdep_temperature = Get_IPC_M2D_Buffer()->payload.avg_mmic_onchip_temp;
   }
   sweep_bw_input.bwdep_sample_shift         = (uint16_t)(p_rdd_data->min_chirp_scaling);
   sweep_bw_output.p_bwdep_cr_resp           = &p_rdd_data->bwdep_cr_resp[0];
   sweep_bw_output.p_bwdep_hvc_thold         = &p_rdd_data->bwdep_hvc_thold[0];
   sweep_bw_output.p_bwdep_mb_thold          = &p_rdd_data->bwdep_mb_thold[0];
   sweep_bw_output.p_bwdep_sensitivity_thold = &p_rdd_data->bwdep_sensitivity_thold[0];
   sweep_bw_output.p_af_sensitivity_thold    = &p_rdd_data->af_sensitivity_thold[0];

   sweep_bw_error_code = Sweep_Bw_LUT_Calc_First(&sweep_bw_output);
   /*Calulate the second set of LUT for Sweep Bandwidth*/
   sweep_bw_error_code = Sweep_Bw_LUT_Calc_Second(&sweep_bw_output);

   // Calc sweepbw tholds for all range bins
   sweep_bw_error_code = Sweep_Bw_Calc(&sweep_bw_input, &sweep_bw_output);
   sweep_bw_error_code = Sweep_Bw_RBIN0_Scaling(&sweep_bw_output);

} /* End of Appl_Sweep_Bw_Execute() */
