#ifndef SPBB_CFG_H
#define SPBB_CFG_H
/**
 * @file spbb_cfg.h
 *
 * Configurations for the Signal Processing BB module
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
 * Application provided configuration of the SPBB modules.
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
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "radar_sw_config.h"
/*===========================================================================*
 * #define Constants
 *===========================================================================*/
#define SPBB_DOPPLER_ATTRIBUTE_SRAM_FUNCTION     __attribute__((section(".sram0.text")))
#define SPBB_FIRST_PASS_ATTRIBUTE_SRAM_FUNCTION  __attribute__((section(".sram0.text")))
#define SPBB_SECOND_PASS_ATTRIBUTE_SRAM_FUNCTION __attribute__((section(".sram0.text")))

/*===========================================================================*
 * #define SMC MACROS
 *===========================================================================*/
#define SPBB_NUM_TX_CHANNELS  (NUM_TX_CHANNELS)
#define SPBB_NUM_RX_CHANNELS  (NUM_RX_CHANNELS)
#define SPBB_NUM_CHANNELS     (NUM_TX_CHANNELS * NUM_RX_CHANNELS)
#define SPBB_NUM_RX_ANTENNAS  (NUM_RX_ANTENNAS)
#define XCP_CAL_NO_OF_TARGETS (3U)
#define SPBB_SCM_ENABLE       (SCM_ENABLE)
/* Need to map the compression range bins with SMC*/
#define LOW_COMPRESSION_RANGE_BINS (VARIABLE_COMPRESSION_RANGE_BIN)

/*===========================================================================*
 * #define CDC/TDC Specific Macros
 *===========================================================================*/

#define SPBB_MAX_CDC_DBIN_COUNT_PER_FRAME (420U)

/*===========================================================================*
 * #define Common Macros
 *===========================================================================*/
/**
 * @note Provide MACRO definitions here to configure the SPBB modules.
 *       These provide an interface to configure settings from the SMC.
 **/
#define SPBB_TDC_ENABLE
#ifdef CDC_ENABLE
   #define SPBB_CDC_ENABLE
#endif
#define SPBB_MAX_CHIRPS         (K_MAX)
#define SPBB_MAX_SAMPLES        (M_MAX)
#define SPBB_USED_RANGE_BINS    (MAX_RANGE_BINS)
#define SPBB_MAX_RANGE_BINS     (MAX_RANGE_FFT_SIZE >> 1)
#define SPBB_MAX_RANGE_FFT_SIZE (MAX_RANGE_FFT_SIZE)
#ifndef __XTENSA__
   #define SPBB_CI_ENABLE (1U) // Enabling CI for Unit testing
#else
   #define SPBB_CI_ENABLE (CI_ENABLE)
#endif

/*===========================================================================*
 * #define Range Specific Macros
 *===========================================================================*/
#define ENABLE_NCI_CALC (1U)

/*===========================================================================*
 * #define Doppler Specific Macros
 *===========================================================================*/
#define SPBB_MAX_DOPPLER_FFT_SIZE (MAX_DOPPLER_FFT_SIZE)
/* Number of DDMA Sectors: 8, 16 for gen8,
   Setting Max to 64 considering 16
 */
#define SPBB_MAX_DFFT_BINS_PER_SECTOR (MAX_DOPPLER_FFT_SIZE >> 3U)
#define K_ENABLE_REST_PROC            (1U) /*TODO: Map with SMC once available*/
/*===========================================================================*
 * #define CFAR Specific Macros
 *===========================================================================*/
#define SPBB_CFAR_LUT_SIZE (CFAR_LUT_LENGTH)
/* k_num_segs_min is from smc and can vary,
 * setting max size in mempool memory to SPBB_MAX_NUM_CFAR_SEGMENTS >> 1
 * Number of segments retained: 1, 2, 4, 6, 8, … likely up to number of segments / 2
 * i.e For mempool allocation SPBB_CFAR_MIN_SEG_SIZE is set to SPBB_MAX_NUM_CFAR_SEGMENTS/2 instead of k_num_segs_min
 */
#define SPBB_MAX_NUM_CFAR_SEGMENTS (64U)
#define SPBB_CFAR_MIN_SEG_SIZE     (SPBB_MAX_NUM_CFAR_SEGMENTS >> 1)
/*===========================================================================*
 * #define Sweep BW Specific Macros
 *===========================================================================*/
#define RANGE_ATTEN_LUT_LENGTH (313)
#define MB_PROFILE_LUT_LENGTH  (8)
#define HVC_PROFILE_LUT_LENGTH (13)
#define NUM_COL_LUT            (2)
/*===========================================================================*
 * #define First Pass Specific Macros
 *===========================================================================*/
#define SPBB_FP_MAX_DETECT            (MAX_DETS_FIRST_PASS)
#define DBINLAST                      (SPBB_MAX_DOPPLER_FFT_SIZE - 1U)
#define K_ENABLE_SENSITIVITY_THOLD_FP (0U)
#define SPBB_NUM_CDM_CHANNELS         (NUM_CDM_CHANNELS)
#define SPBB_NUM_DDM_CHANNELS         (NUM_DDM_CHANNELS)
#define SPBB_COMPRESSED_BV_SIZE       (NUM_CDM_CHANNELS * NUM_DDM_CHANNELS)
#define XCP_COMPRESSED_BV_SIZE        (8U)

/*===========================================================================*
 * #define CDC/TDC Specific Macros
 *===========================================================================*/
#define MAX_CDC_DBIN_COUNT_PER_RBIN ((uint16_t)SPBB_MAX_DOPPLER_FFT_SIZE)
/*===========================================================================*
 * #define Second Pass Specific Macros
 *===========================================================================*/
#define SPBB_SP_MAX_DETECT (MAX_DETS_FIRST_PASS)

/*===========================================================================*
 * Custom Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * ENABLE VALIDATION
 *===========================================================================*/

/*===========================================================================*
 * Custom Type Declarations
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* SPBB_CFG_H */
