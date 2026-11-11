#ifndef AFBB_CFG_H
#define AFBB_CFG_H
/*===========================================================================*/
/**
 * @file
 *
 * Configurations for Angle finding module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright 2024 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 *
 * @section ABBR ABBREVIATIONS:
 *   - None
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - "None"
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "radar_sw_config.h"
#include "smc_cal.h"

/*===========================================================================*
 * #define Constants
 *===========================================================================*/
/* Enabled belown macro to use the hardcoded SMC values for initial release*/
// #define AF_STANDALONE_CALS
// #define AF_TESTING
// #define RCS_TESTING
// #define AF_FC_STUB_SIMULATE_DET
// #define AF_PROFILING /* enabled detailed profiling */
// #define DS_TESTING /* enable downselection testing interface */
#ifdef AF_CFG_SIL_BUILD
   #undef AF_TIMEOUT_ENABLE
   #define AF_TIMEOUT_ENABLE (0)
#else
   /* define as 1 for bbe32App build and for UNIT_TEST build */
   #define AF_TIMEOUT_ENABLE (1)
#endif

#ifdef UNIT_TEST
   #undef DOWNSELECTION_ENABLE
   #undef MAX_TARGET_REPORTS
   #undef DS_EN_FEAT_BASED
   #define DS_EN_FEAT_BASED     (1U)
   #define DOWNSELECTION_ENABLE (1U)
   #define MAX_TARGET_REPORTS   (128U)
#endif

#ifndef AF_MULTI_TARGET_DETS
   #define AF_MULTI_TARGET_DETS (6U)
#endif

#define AF_TIMEOUT_ENABLE_L    (AF_TIMEOUT_ENABLE)
#define FRAME_TIME_PERIOD_CLKS (41650000U /* 50ms * DSP_CLK_FREQ_HZ */)
#ifdef TRACKER_ENABLED
   #define AF_DS_RCS_TIME_CLKS      (1666000U /* 2ms * DSP_CLK_FREQ_HZ */)
   #define AF_POST_AF_RESERVED_TIME (12495000U /* (12.5ms tracker + 2.5ms RC/align) * DSP_CLK_FREQ_HZ */)
#else
   #define AF_DS_RCS_TIME_CLKS      (2915500U /* 3.5ms * DSP_CLK_FREQ_HZ */)
   #define AF_POST_AF_RESERVED_TIME (2082500U /* 2.5ms * DSP_CLK_FREQ_HZ */)
#endif

#define AF_DS_ENABLE_FEAT_BASED_L     (DS_EN_FEAT_BASED) /* Enable feature based downselection SMC DS_EN_FEAT_BASED */
#define AF_DS_MAX_NUM_DET_PER_GROUP_L (64)
#define AF_FASCIA_COMPENSATION_ENABLE (1U) /* Fascia Slope Correction */

/*RCS Defines*/
#define ANTENNA_CAL_LUT_SIZE      (181U)
#define ANTENNA_CAL_LUT_MIN_ANGLE (-90)
#define ANTENNA_CAL_LUT_MAX_ANGLE (90)

#ifdef FLR8
   /* Radar SW config linking*/
   #define AF_MAX_NUM_DET_L          (AF_MAX_NUM_DET)
   #define AF_NUM_TX_CHANNELS_L      (NUM_TX_CHANNELS)
   #define AF_NUM_RX_CHANNELS_L      (NUM_RX_ANTENNAS)
   #define AF_MAX_RANGE_BINS_L       (MAX_RANGE_BINS)
   #define AF_MAX_DOPPLER_FFT_SIZE_L (MAX_DOPPLER_FFT_SIZE)
   #define AF_RDD_ANGLE_BINS_USED_L  (ANGLE_BINS_USED)

   /* SMC Cal header linking */
   #define AF_SSC_T_SIZE_L (ANGLE_FINDING_FLR8_SIZE)
   #define AF_FOV_DEG_L    (AF_FOV_DEG)

   /* USC Cal config linking */
   #define AF_CAL_SEC_N (2U)

   /*Local config*/
   #define AF_MULTI_TARGET_DETS_L     (AF_MULTI_TARGET_DETS)
   #define AF_BATCH_M                 (8)
   #define AF_COMPRESSED_BV_MODE      (1) /* 0=none, 1=Indie, 2=CP4Q */
   #define B0_FEAT_3DFFT              (1) /* 0=classical SP, 1=3D FFT SP */
   #define AF_RDD_NUM_DET_PER_GROUP_L (64)
   #define AF_MAX_NUM_S2              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S3              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S4              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S5              (AF_RDD_NUM_DET_PER_GROUP_L + 2 * AF_MAX_NUM_S2 + 3 * AF_MAX_NUM_S3 + 2 * AF_MAX_NUM_S4)
   #define AF_CAL_MC_NUM_L            (32)
   #define AF_MAX_FFT_ITER_L          (2)

   /* Down Selection configs*/
   #define AF_DOWNSELECTION_ENABLE_L (DOWNSELECTION_ENABLE)
   #define AF_MAX_TARGET_REPORTS_L   (MAX_TARGET_REPORTS)

#endif

#ifdef SRR8P
   /* Radar SW config linking*/
   #define AF_MAX_NUM_DET_L          (AF_MAX_NUM_DET)
   #define AF_NUM_TX_CHANNELS_L      (NUM_TX_CHANNELS)
   #define AF_NUM_RX_CHANNELS_L      (NUM_RX_ANTENNAS)
   #define AF_MAX_RANGE_BINS_L       (MAX_RANGE_BINS)
   #define AF_MAX_DOPPLER_FFT_SIZE_L (MAX_DOPPLER_FFT_SIZE)
   #define AF_RDD_ANGLE_BINS_USED_L  (ANGLE_BINS_USED)

   /* SMC Cal header linking */
   #define AF_SSC_T_SIZE_L (ANGLE_FINDING_SRR8P_SIZE)
   #define AF_FOV_DEG_L    (AF_FOV_DEG)

   /* USC Cal config linking */
   #define AF_CAL_SEC_N (2U)

   /*Local config*/
   #define AF_MULTI_TARGET_DETS_L     (AF_MULTI_TARGET_DETS)
   #define AF_BATCH_M                 (8)
   #define AF_COMPRESSED_BV_MODE      (1) /* 0=none, 1=Indie, 2=CP4Q */
   #define B0_FEAT_3DFFT              (1) /* 0=classical SP, 1=3D FFT SP */
   #define AF_RDD_NUM_DET_PER_GROUP_L (64)
   #define AF_MAX_NUM_S2              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S3              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S4              (AF_RDD_NUM_DET_PER_GROUP_L)
   #define AF_MAX_NUM_S5              (AF_RDD_NUM_DET_PER_GROUP_L + 2 * AF_MAX_NUM_S2 + 2 * AF_MAX_NUM_S4)
   #define AF_CAL_MC_NUM_L            (32)
   #define AF_MAX_FFT_ITER_L          (2)

   /* Down Selection configs*/
   #define AF_DOWNSELECTION_ENABLE_L (DOWNSELECTION_ENABLE)
   #define AF_MAX_TARGET_REPORTS_L   (MAX_TARGET_REPORTS)

#endif

#if (B0_FEAT_3DFFT == 1)
   #define B0_COMPRESSION_INDIE (1) /* 1=2-ch compression used with 3D FFT SP */
#else
   #define B0_COMPRESSION_INDIE (0) /* 0=4-ch compression used with classical SP */
#endif

/*===========================================================================*
 * #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Custom Type Declarations
 *===========================================================================*/

#endif /* AFBB_CFG_H */
