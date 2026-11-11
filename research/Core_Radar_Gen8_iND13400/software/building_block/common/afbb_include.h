#ifndef AFBB_INCLUDE_H
#define AFBB_INCLUDE_H
/*===========================================================================*/
/**
 * @file
 * @brief File to include application header into AFBB world
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2024 Aptiv, All Rights Reserved.
 * @copyright Aptiv Confidential
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
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * @addtogroup api
 * @{
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "af_common_data.h"
#include "afbb_cfg.h"
#include "afbb_memmap.h"
#include "calibration.h"
#include "detection_debug_stream.h"
#include "fixmac.h"
#include "radar_look_types.h"
#include "radar_math_types.h"
#include "rdd_stream.h"
#include "reuse.h"
#include "smc_cal.h"
#include "usc_cal.h"

/* xtensa include files*/
#ifdef __XTENSA__
   #include <xtensa/config/defs.h>
   #include <xtensa/tie/xt_bbe32.h>
   #include <xtensa/tie/xt_bben.h>
   #include <xtensa/tie/xt_misc.h>
#endif

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

/* verify that SMC configuration matches our detection stream configuration */
#if (CH_CH_NUM_RX_ANTENNAS != NUM_RX_ANTENNAS)
   #error CH_CH_NUM_RX_ANTENNAS does not match NUM_RX_ANTENNAS
#endif
#if (CH_CH_NUM_TX_ANTENNAS != NUM_TX_CHANNELS)
   #error CH_CH_NUM_TX_ANTENNAS does not match NUM_TX_CHANNELS
#endif
#if (AF_EST_RX_TX_BUF_SIZE != (NUM_RX_ANTENNAS * NUM_TX_CHANNELS))
   #error AF_EST_RX_TX_BUF_SIZE does not match antenna configuration
#endif

#ifndef RADAR_PI
   #define RADAR_PI (3.141592653589793f)
#endif

#ifndef RADAR_PI_BY_2
   #define RADAR_PI_BY_2 (1.5707963267948966f)
#endif

   /* compatibility with future USC updates */
#if defined(k_Gain_Rolloff_Az_Reciprocal_usc) && !defined(k_Gain_Rolloff_Az_Reciprocal_USC)
   #define k_Gain_Rolloff_Az_Reciprocal_USC k_Gain_Rolloff_Az_Reciprocal_usc
#endif

#if defined(k_Gain_Rolloff_EL_Reciprocal_usc) && !defined(k_Gain_Rolloff_EL_Reciprocal_USC)
   #define k_Gain_Rolloff_EL_Reciprocal_USC k_Gain_Rolloff_EL_Reciprocal_usc
#endif

#if defined(k_calmat1_ctx_usc) && !defined(k_calmat1_ctx_USC)
   #define k_calmat1_ctx_USC k_calmat1_ctx_usc
#endif

#if defined(k_calmat1_crx_usc) && !defined(k_calmat1_crx_USC)
   #define k_calmat1_crx_USC k_calmat1_crx_usc
#endif

#if defined(k_calmat1_c1_usc) && !defined(k_calmat1_c1_USC)
   #define k_calmat1_c1_USC k_calmat1_c1_usc
#endif

#if defined(k_calmat2_ctx_usc) && !defined(k_calmat2_ctx_USC)
   #define k_calmat2_ctx_USC k_calmat2_ctx_usc
#endif

#if defined(k_calmat2_crx_usc) && !defined(k_calmat2_crx_USC)
   #define k_calmat2_crx_USC k_calmat2_crx_usc
#endif

#if defined(k_calmat2_c1_usc) && !defined(k_calmat2_c1_USC)
   #define k_calmat2_c1_USC k_calmat2_c1_usc
#endif

#if defined(K_GAIN_ROLLOFF_AZ_RECIPROCAL_USC) && !defined(k_Gain_Rolloff_Az_Reciprocal_USC)
   #define k_Gain_Rolloff_Az_Reciprocal_USC K_GAIN_ROLLOFF_AZ_RECIPROCAL_USC
#endif

#if defined(K_GAIN_ROLLOFF_EL_RECIPROCAL_USC) && !defined(k_Gain_Rolloff_EL_Reciprocal_USC)
   #define k_Gain_Rolloff_EL_Reciprocal_USC K_GAIN_ROLLOFF_EL_RECIPROCAL_USC
#endif

#if defined(K_CALMAT1_CTX_USC) && !defined(k_calmat1_ctx_USC)
   #define k_calmat1_ctx_USC K_CALMAT1_CTX_USC
#endif

#if defined(K_CALMAT1_CRX_USC) && !defined(k_calmat1_crx_USC)
   #define k_calmat1_crx_USC K_CALMAT1_CRX_USC
#endif

#if defined(K_CALMAT1_C1_USC) && !defined(k_calmat1_c1_USC)
   #define k_calmat1_c1_USC K_CALMAT1_C1_USC
#endif

#if defined(K_CALMAT2_CTX_USC) && !defined(k_calmat2_ctx_USC)
   #define k_calmat2_ctx_USC K_CALMAT2_CTX_USC
#endif

#if defined(K_CALMAT2_CRX_USC) && !defined(k_calmat2_crx_USC)
   #define k_calmat2_crx_USC K_CALMAT2_CRX_USC
#endif

#if defined(K_CALMAT2_C1_USC) && !defined(k_calmat2_c1_USC)
   #define k_calmat2_c1_USC K_CALMAT2_C1_USC
#endif

   /* compatibility with future SMC updates */
#if defined(k_bv2mprb_SMC) && !defined(k_bv2mprb_smc)
   #define k_bv2mprb_smc k_bv2mprb_SMC
#endif

#if defined(k_rcs_az_rolloff_limit_SMC) && !defined(k_rcs_az_rolloff_limit_smc)
   #define k_rcs_az_rolloff_limit_smc k_rcs_az_rolloff_limit_SMC
#endif

#if defined(k_rcs_el_rolloff_limit_SMC) && !defined(k_rcs_el_rolloff_limit_smc)
   #define k_rcs_el_rolloff_limit_smc k_rcs_el_rolloff_limit_SMC
#endif

#if defined(k_flag_flip_azimuth_rolloff_SMC) && !defined(k_flag_flip_azimuth_rolloff_smc)
   #define k_flag_flip_azimuth_rolloff_smc k_flag_flip_azimuth_rolloff_SMC
#endif

#if defined(k_flag_flip_elevation_rolloff_SMC) && !defined(k_flag_flip_elevation_rolloff_smc)
   #define k_flag_flip_elevation_rolloff_smc k_flag_flip_elevation_rolloff_SMC
#endif

#if defined(k_bv_order_SMC) && !defined(k_bv_order_smc)
   #define k_bv_order_smc k_bv_order_SMC
#endif

#if defined(K_BV2MPRB_SMC) && !defined(k_bv2mprb_smc)
   #define k_bv2mprb_smc K_BV2MPRB_SMC
#endif

#if defined(K_RCS_AZ_ROLLOFF_LIMIT_SMC) && !defined(k_rcs_az_rolloff_limit_smc)
   #define k_rcs_az_rolloff_limit_smc K_RCS_AZ_ROLLOFF_LIMIT_SMC
#endif

#if defined(K_RCS_EL_ROLLOFF_LIMIT_SMC) && !defined(k_rcs_el_rolloff_limit_smc)
   #define k_rcs_el_rolloff_limit_smc K_RCS_EL_ROLLOFF_LIMIT_SMC
#endif

#if defined(K_FLAG_FLIP_AZIMUTH_ROLLOFF_SMC) && !defined(k_flag_flip_azimuth_rolloff_smc)
   #define k_flag_flip_azimuth_rolloff_smc K_FLAG_FLIP_AZIMUTH_ROLLOFF_SMC
#endif

#if defined(K_FLAG_FLIP_ELEVATION_ROLLOFF_SMC) && !defined(k_flag_flip_elevation_rolloff_smc)
   #define k_flag_flip_elevation_rolloff_smc K_FLAG_FLIP_ELEVATION_ROLLOFF_SMC
#endif

#if defined(K_BV_ORDER_SMC) && !defined(k_bv_order_smc)
   #define k_bv_order_smc K_BV_ORDER_SMC
#endif

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   /*===========================================================================*
    * Exported variables
    *===========================================================================*/
   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    Name...  (Description on following lines: SCR #, etc.)
 * ----------- ----------------------------------------------------------------
 * 16-Sep-2024 gjfh3l(Arun G)      CUW-3863 : FLR8 SAFV1.1 integration updates.
 * 25-Mar-2025 hzgbb0(Chris Baker) CUW-4299 : Move includes outside of extern C
 * ===========================================================================*/
#endif /* AFBB_INCLUDE_H */
