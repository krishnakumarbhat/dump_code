/**
 * @file appl_cfar_ifc.c
 *
 * Application interface mapping for CFAR
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
 * Application interface mapping for CFAR module
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
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
#include "appl_adaptive_cfar.h"
#include "appl_cfar_ifc.h"
#include "appl_rdd_prv.h"
#include "cfar.h"
#include "doppler_process_ifc.h"
#include "ipc_dsp.h"
#include "rdd_debug_stream.h"
#include "smc_cal.h"
#include "spbb_cfg.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define SFW_ENABLE (0x02U)

CFAR_Internal_Buff_T *p_cfar_int_buff = NULL;

/* A-PRISM adaptive CFAR layer (Runs 22-23: dual-loop floor + Occupancy-BLUE).
 * Default OFF (APRISM_ADAPTIVE_CFAR_ENABLE undefined/0): behavior identical.
 * Enable via BUILD local_defines. State is statically allocated: no heap. */
static AprismCfarCfg_T aprism_cfar_cfg = {
   APRISM_CFAR_EMA_LAMBDA, APRISM_CFAR_WALL_MULT, 1e-4F, true
};
static float aprism_cfar_floor[MAX_RANGE_BINS];
static AprismCfarState_T aprism_cfar_state = {0};
/* A-PRISM overlay working buffers (static: no DSP stack pressure). */
static float aprism_cfar_row[APRISM_CFAR_MAX_REFS];
static float aprism_cfar_scratch[APRISM_CFAR_MAX_REFS];
static float aprism_cfar_beta[APRISM_CFAR_MAX_REFS];
static float aprism_cfar_pi[APRISM_CFAR_MAX_REFS];
static float aprism_cfar_snr[APRISM_CFAR_MAX_REFS];
static uint8_t aprism_cfar_free[APRISM_CFAR_MAX_REFS];
/*===========================================================================*/
/*        Local Inline Function Definitions and Function-Like Macros         */
/*===========================================================================*/
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/******************************************************************************
 *  @b Description
 *  @n
 *       Do configuration for CFAR processing.
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for an error
 ******************************************************************************/
bool Appl_Cfar_Init(Radar_Look_T look_id)
{
   /* Creating a local Cfar config variable to copy the config value from SMC and USC*/
   Cfar_Config_T cfar_cfg = {0};

   Cfar_Error_T cfar_error_code;
   cfar_error_code                    = CFAR_PROCESS_NO_ERROR;
   cfar_cfg.range_bins_used           = MAX_RANGE_BINS;
   cfar_cfg.doppler_fft_size          = MAX_DOPPLER_FFT_SIZE;
   cfar_cfg.angle_fft_size            = ANGLE_BINS_USED;
   cfar_cfg.k_corr_coeff_mult         = k_corr_coeff_mult_smc[look_id];
   cfar_cfg.k_corr_coeff_sub          = k_corr_coeff_sub_smc[look_id];
   cfar_cfg.k_scrub_factor            = k_scrub_factor_smc[look_id];
   cfar_cfg.k_total_num_CFAR_segments = k_total_num_cfar_segments_smc[look_id];
   cfar_cfg.k_num_segs_min            = k_num_segs_min_smc[look_id];
   cfar_cfg.k_CFAR_LUT                = k_cfar_lut_smc[look_id];
   cfar_cfg.k_CFAR_LUT_length         = CFAR_LUT_LENGTH;
   cfar_cfg.k_scrub_use               = k_scrub_use_smc[look_id];
   cfar_error_code                    = Cfar_Process_Init(&cfar_cfg);

   /* A-PRISM: wire adaptive-layer state (inert until enabled). */
   aprism_cfar_state.cfg   = &aprism_cfar_cfg;
   aprism_cfar_state.floor = &aprism_cfar_floor[0];
   aprism_cfar_state.nbins = MAX_RANGE_BINS;

   return (CFAR_PROCESS_NO_ERROR == cfar_error_code);
} /*End of Appl_Cfar_Init()*/

/******************************************************************************
 *  @b Description
 *  @n
 *       Execute the Cfar processing on the specified input.
 *
 * @param[in] ridx current range index
 * @param[in]  p_rdd_data Pointer to IPC RDD stream structure.
 *
 * @return N/A
 ******************************************************************************/
void Appl_Cfar_Execute(uint16_t ridx, RDD_Data_T *p_rdd_data)
{
   Cfar_Input_T cfar_input   = {0}; /* Local bufer for Cfar input */
   Cfar_Output_T cfar_output = {0}; /* Local bufer for Cfar Output */

   /* Pointing the cfar inputs*/
   cfar_input.p_rdop_avg_nci = rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH];

   /* Pointing the cfar output buffer to rdd IPC buffer */
   cfar_output.p_cfar_threshold  = &p_rdd_data->cfar_thold[ridx][0];
   cfar_output.p_nf_est          = &p_rdd_data->cfar_nf_est[ridx][0];
   cfar_output.p_cfar_corr_coeff = &p_rdd_data->cfar_corr_coeff[ridx][0];

   /* Pointing the cfar output buffer to rdd internal buffer */
   cfar_output.p_nci_min     = &p_cfar_int_buff->cfar_nci_min[0];
   cfar_output.p_seg_mean    = &p_cfar_int_buff->cfar_seg_mean[0];
   cfar_output.p_seg_min     = &p_cfar_int_buff->cfar_seg_min[0];
   cfar_output.p_seg_min_idx = &p_cfar_int_buff->cfar_seg_min_idx[0];
   Cfar_Process(&cfar_input, &cfar_output);
#if defined(APRISM_ADAPTIVE_CFAR_ENABLE) && (APRISM_ADAPTIVE_CFAR_ENABLE == 1)
   /* A-PRISM adaptive overlay: dual-loop floor + Occupancy-BLUE rescale.
    * Real calls with real I/O; default OFF = baseline bit-identical.
    * ponytail: slow-loop follows SPBB nf_est (direct NCI-row stride/LSB is
    * owned by SPBB — switch the row source when the RDD owner confirms the
    * rdop_avg plane layout). Occupancy is all-free until the emb_tracker
    * previous-scan mask lands; the BLUE ratio is ~1 until then and the
    * floor smoothing is the active effect. Ratios are dimensionless so the
    * uint32/uint16 Q-formats hold by construction. */
   if ((aprism_cfar_state.floor != NULL) && (ridx < (uint16_t)aprism_cfar_state.nbins))
   {
      int32_t ai, nad = (int32_t)ANGLE_BINS_USED;
      float floor_v, alpha_b, alpha_ca, ratio;
      uint16_t nf_new;
      if (nad > APRISM_CFAR_MAX_REFS)
      {
         nad = APRISM_CFAR_MAX_REFS;
      }
      for (ai = 0; ai < nad; ai++)
      {
         aprism_cfar_row[ai]  = (float)p_rdd_data->cfar_nf_est[ridx][ai];
         aprism_cfar_free[ai] = 1U;
         aprism_cfar_pi[ai]   = 0.0f;
      }
      Aprism_DualLoopFloor(&aprism_cfar_state, (int32_t)ridx, aprism_cfar_row, aprism_cfar_free, nad,
                           aprism_cfar_scratch);
      floor_v = aprism_cfar_floor[ridx];
      if (floor_v < 1.0f)
      {
         floor_v = 1.0f;
      }
      for (ai = 0; ai < nad; ai++)
      {
         float snr = aprism_cfar_row[ai] / floor_v - 1.0f;
         aprism_cfar_snr[ai] = (snr > 0.0f) ? snr : 0.0f;
      }
      Aprism_BlueWeights(aprism_cfar_pi, aprism_cfar_snr, aprism_cfar_beta, nad);
      alpha_b  = Aprism_AlphaForPfa(aprism_cfar_beta, nad, aprism_cfar_cfg.pfa);
      alpha_ca = Aprism_CaAlpha(nad, aprism_cfar_cfg.pfa);
      ratio    = (alpha_ca > 0.0f) ? (alpha_b / alpha_ca) : 1.0f;
      if (ratio < 0.5f)
      {
         ratio = 0.5f;
      }
      if (ratio > 2.0f)
      {
         ratio = 2.0f;
      }
      nf_new = (floor_v > 65535.0f) ? 0xFFFFU : (uint16_t)(floor_v + 0.5f);
      for (ai = 0; ai < nad; ai++)
      {
         /* All-free identity: thresholds untouched, only floor smoothing lands. */
         if (ratio != 1.0f)
         {
            float th_scaled = (float)p_rdd_data->cfar_thold[ridx][ai] * ratio + 0.5f;
            p_rdd_data->cfar_thold[ridx][ai] =
               (th_scaled > 4294967295.0f) ? 0xFFFFFFFFU : (uint32_t)th_scaled;
         }
         p_rdd_data->cfar_nf_est[ridx][ai] = nf_new;
      }
   }
#endif
} /*End of Appl_Cfar_Execute()*/

/**
 *  @b Description
 *  @n
 *   Allocate the CFAR buffer on the memory pool.
 *
 * @param[in]  mem_pool - Pointer to the memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T __attribute__((noinline)) Appl_CFAR_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T ret_val = MEM_POOL_FAILURE;

   ret_val = Mem_Pool_Alloc(mem_pool, sizeof(CFAR_Internal_Buff_T), (void **)&p_cfar_int_buff);
   return ret_val;
}
