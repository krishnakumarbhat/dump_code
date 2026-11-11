/*===========================================================================*/
/**
 * @file ci_misalign_stv_ut_data.h
 *
 * Unit testing data for CI steering vector Misalignment.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright 2025 Aptiv, All Rights Reserved.
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

/*===========================================================================*
 * #define Constants
 *===========================================================================*/

/*===========================================================================*
 * #define MACROS
 *===========================================================================*/
#include "spbb_cfg.h"
#include "spbb_include.h"
#include "spbb_typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif
   extern int16_t Test_CI_Stv_In[SPBB_NUM_CHANNELS * 4];
   extern int16_t Test_CI_Stv_Out[SPBB_NUM_CHANNELS * 4];
   extern float Test_K_Calmat[SPBB_NUM_CHANNELS * 2][SPBB_NUM_CHANNELS * 4];
   extern u8p0_T Test_K_Inv_Bv_Order[SPBB_NUM_CHANNELS * 2];

   extern int16_t Expec_Cistv_Disable_Misalign_Out[SPBB_NUM_CHANNELS * 4];

#ifdef __cplusplus
}
#endif
