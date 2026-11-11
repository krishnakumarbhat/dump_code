#ifndef APPL_RDD_PRV_H
#define APPL_RDD_PRV_H

/*===========================================================================*/
/**
 * @file
 * @brief rdd_process interface specific private header file
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2025 Aptiv, All Rights Reserved.
 * @copyright Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * RDD_2PASS API
 *
 * @section ABBR ABBREVIATIONS:
 *   - BB - Building Block
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * @defgroup api Module API
 * @{
 * @brief
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "rdd_first_pass_types.h"

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /* ========================================================================== */
   /*                         Local Object Definitions                           */
   /* ========================================================================== */
   /** RDD Internal buffer structure*/
   typedef struct RDD_Internal_Buff_Tag
   {
      float32_t bwdep_range_attenuation[MAX_RANGE_BINS] __attribute__((aligned(32)));
      BV_Decomp_Type_T rdd1_decomp_bv[SPBB_NUM_RX_ANTENNAS * SPBB_NUM_TX_CHANNELS] __attribute__((aligned(32)));
      uint32_t rdd2_thold_zdb[MAX_DETS_FIRST_PASS] __attribute__((aligned(32)));
      uint32_t rdd2_thold_hvc[MAX_DETS_FIRST_PASS] __attribute__((aligned(32)));
      uint16_t nci_rdop_avg_max_collapse[SPBB_MAX_DFFT_BINS_PER_SECTOR * ANGLE_BINS_USED] __attribute__((aligned(32)));
      uint16_t nci_sec_idx_max_collapse[SPBB_MAX_DFFT_BINS_PER_SECTOR * ANGLE_BINS_USED] __attribute__((aligned(32)));
      uint16_t rdd1_bv_reorder_idx[SPBB_NUM_RX_ANTENNAS * SPBB_NUM_TX_CHANNELS] __attribute__((aligned(32)));
      uint16_t rdd1_xcp_bv_order_idx[SPBB_NUM_RX_ANTENNAS * SPBB_NUM_TX_CHANNELS] __attribute__((aligned(32)));
      XCP_Variance_T xcp_bv_var;
      float32_t xcp_spe_gain;
      float32_t xcp_spe_gain_min;
      float32_t xcp_spe_gain_max;
      uint16_t xcp_angle_idx;
      uint16_t xcp_range_idx;
      uint16_t xcp_doppler_idx;
      uint16_t xcp_max_fp_tgt_cnt;
      uint16_t xcp_rngidx_target_start;
      uint16_t xcp_max_fp_per_rbin_target_cnt;
      uint16_t xcp_max_per_rbin_targets;
      uint16_t xcp_range_idx_bv_variance;
      bool xcp_rdd_vary_xput_flag;
      bool xcp_max_static_target_case_enable;
      bool xcp_spe_gain_vary_enable_flag;
#ifdef SPBB_SCM_ENABLE
      float32_t scm_max_detectable_range;
      uint16_t scm_max_rbin_processed;
      uint8_t scm_run_per_rbin;
      uint16_t saturation_cm_dbin_diff[SPBB_FP_MAX_DETECT - 1U] __attribute__((aligned(32)));
      uint8_t scm_targets_saturation_flag;
      uint8_t scm_prioritization_flag;
#endif
   } RDD_Internal_Buff_T;

   typedef struct CFAR_Internal_Buff_Tag
   {
      rdop_avg_t cfar_nci_min[SPBB_CFAR_MIN_SEG_SIZE * S_LENGTH_CFAR_MEAN * ANGLE_BINS_USED] __attribute__((aligned(32)));
      rdop_avg_t cfar_seg_mean[SPBB_MAX_NUM_CFAR_SEGMENTS * ANGLE_BINS_USED] __attribute__((aligned(32)));
      rdop_avg_t cfar_seg_min[SPBB_CFAR_MIN_SEG_SIZE * ANGLE_BINS_USED] __attribute__((aligned(32)));
      uint16_t cfar_seg_min_idx[SPBB_CFAR_MIN_SEG_SIZE * ANGLE_BINS_USED] __attribute__((aligned(32)));
   } CFAR_Internal_Buff_T;

   extern RDD_Internal_Buff_T *p_rdd_int_buff;
   extern CFAR_Internal_Buff_T *p_cfar_int_buff;
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
