#ifndef RCBB_INCLUDE_H
#define RCBB_INCLUDE_H
/*===========================================================================*/
/**
 * @file
 * @brief File to include application header into RCBB
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2022 Aptiv, All Rights Reserved.
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
#include <stdbool.h>
#include <stdint.h>

#include "fixed_point_conversions.h"
#include "fixmac.h"
#include "radar_sw_config.h"
#include "rc_types.h"
#include "reuse.h"
#include "smc_cal.h"
#include "usc_cal.h"

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*\
   * Exported Preprocessor #define MACROS
   \*===========================================================================*/

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

   typedef struct RC_Input_Tag
   {
#ifdef RC_RESIM_FORCE_INFO_FROM_LOG
      Radar_Capability_Stream_T const *p_rc_data;
#endif
      RC_Detection_Input_T p_det_data;
      RC_Rdd_Input_T p_rdd_stream_data;
      RC_Vse_Input_T p_veh_data;
      RC_ID_Input_T p_id_data;
#ifdef GEN7_V1
      RC_RFHealth_Status_T p_rf_health_data;
#endif
      RC_Dynamic_Alignment_Log_Input_T p_dyn_align_data;
      RC_GLOB_TS_STRUCT_TYPE p_middle_of_dwell_ts;
      Fault_Inject_Cmd_T fault_inject_cmd;
      int16_t avg_mmic_onchip_temp;
      RC_Cal_T rc_cals;
      bool f_eco_mode_enabled;
   } RC_Input_T;

   ////////////////// endian handling?

   /* compatibility with future USC updates */
#if defined(k_Gain_Rolloff_Az_Reciprocal_usc) && !defined(k_Gain_Rolloff_Az_Reciprocal_USC)
   #define k_Gain_Rolloff_Az_Reciprocal_USC k_Gain_Rolloff_Az_Reciprocal_usc
#endif

#if defined(k_Gain_Rolloff_EL_Reciprocal_usc) && !defined(k_Gain_Rolloff_EL_Reciprocal_USC)
   #define k_Gain_Rolloff_EL_Reciprocal_USC k_Gain_Rolloff_EL_Reciprocal_usc
#endif

#if defined(k_Mfg_Cal_Target_Range_usc) && !defined(k_Mfg_Cal_Target_Range_USC)
   #define k_Mfg_Cal_Target_Range_USC k_Mfg_Cal_Target_Range_usc
#endif

#if defined(k_Mfg_Cal_Target_RCS_usc) && !defined(k_Mfg_Cal_Target_RCS_USC)
   #define k_Mfg_Cal_Target_RCS_USC k_Mfg_Cal_Target_RCS_usc
#endif

#if defined(k_Boresight_SNR_usc) && !defined(k_Boresight_SNR_USC)
   #define k_Boresight_SNR_USC k_Boresight_SNR_usc
#endif

#if defined(k_Peak_SNR_usc) && !defined(k_Peak_SNR_USC)
   #define k_Peak_SNR_USC k_Peak_SNR_usc
#endif

#if defined(k_Peak_SNR_Az_usc) && !defined(k_Peak_SNR_Az_USC)
   #define k_Peak_SNR_Az_USC k_Peak_SNR_Az_usc
#endif

#if defined(k_Peak_SNR_El_usc) && !defined(k_Peak_SNR_El_USC)
   #define k_Peak_SNR_El_USC k_Peak_SNR_El_usc
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RCBB_INCLUDE_H */
