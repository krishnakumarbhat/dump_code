/*===========================================================================*/
/**
 * @file ci_misalign_stv_ut_data.c
 *
 * Unit testing data for the CI steering vector Misalignment.
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
// #include "spbb_cfg.h"
// #include "spbb_include.h"
// #include "spbb_typedefs.h"
#include "ci_misalign_stv_ut_data.h"
/*===========================================================================*
 * #define Constants
 *===========================================================================*/

/*===========================================================================*
 * #define MACROS
 *===========================================================================*/
/* Test data Generated for CI Enable. look_A and
 *SMC Version : FLR8_EDU_Aptiv_Satellite_8_82_0_1
 *USC Version: FLR8_EDU_Default_4_82_0_0
 */
int16_t Test_CI_Stv_In[SPBB_NUM_CHANNELS * 4] = {
   (s15p0_T)32767,  (s15p0_T)0,      (s15p0_T)26156,  (s15p0_T)19737,  (s15p0_T)-32752, (s15p0_T)-990,   (s15p0_T)-30661,
   (s15p0_T)11557,  (s15p0_T)-5647,  (s15p0_T)32277,  (s15p0_T)32767,  (s15p0_T)0,      (s15p0_T)16669,  (s15p0_T)-28211,
   (s15p0_T)16669,  (s15p0_T)-28211, (s15p0_T)-31937, (s15p0_T)-7328,  (s15p0_T)-21079, (s15p0_T)-25087, (s15p0_T)31701,
   (s15p0_T)8290,   (s15p0_T)32469,  (s15p0_T)-4407,  (s15p0_T)12723,  (s15p0_T)-30196, (s15p0_T)-31937, (s15p0_T)-7328,
   (s15p0_T)-22556, (s15p0_T)23768,  (s15p0_T)-22556, (s15p0_T)23768,  (s15p0_T)29489,  (s15p0_T)14285,  (s15p0_T)14934,
   (s15p0_T)29166,  (s15p0_T)-29044, (s15p0_T)-15170, (s15p0_T)-32632, (s15p0_T)-2966,  (s15p0_T)-19154, (s15p0_T)26586,
   (s15p0_T)29489,  (s15p0_T)14285,  (s15p0_T)27300,  (s15p0_T)-18122, (s15p0_T)27300,  (s15p0_T)-18122, (s15p0_T)-25547,
   (s15p0_T)-20519, (s15p0_T)-8033,  (s15p0_T)-31767, (s15p0_T)24916,  (s15p0_T)21281,  (s15p0_T)31142,  (s15p0_T)10190,
   (s15p0_T)24615,  (s15p0_T)-21629, (s15p0_T)-25547, (s15p0_T)-20519, (s15p0_T)-30661, (s15p0_T)11557,  (s15p0_T)-30661,
   (s15p0_T)11557};

int16_t __attribute__((aligned(32))) Test_CI_Stv_Out[SPBB_NUM_CHANNELS * 4];

float Test_K_Calmat[SPBB_NUM_CHANNELS * 2][SPBB_NUM_CHANNELS * 4] = {
   {(float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1,
    (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1,
    (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1,
    (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,   (float)0, (float)0, (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1, (float)0, (float)0},
   {(float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,  (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,  (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,  (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,  (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0,  (float)0, (float)0,
    (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)0, (float)1, (float)0.1}};

u8p0_T Test_K_Inv_Bv_Order[SPBB_NUM_CHANNELS * 2] = {
   (u8p0_T)31, (u8p0_T)23, (u8p0_T)27, (u8p0_T)19, (u8p0_T)28, (u8p0_T)20, (u8p0_T)29, (u8p0_T)21,
   (u8p0_T)30, (u8p0_T)22, (u8p0_T)24, (u8p0_T)16, (u8p0_T)25, (u8p0_T)17, (u8p0_T)26, (u8p0_T)18,
   (u8p0_T)15, (u8p0_T)7,  (u8p0_T)11, (u8p0_T)3,  (u8p0_T)12, (u8p0_T)4,  (u8p0_T)13, (u8p0_T)5,
   (u8p0_T)14, (u8p0_T)6,  (u8p0_T)8,  (u8p0_T)0,  (u8p0_T)9,  (u8p0_T)1,  (u8p0_T)10, (u8p0_T)2};

int16_t Expec_Cistv_Disable_Misalign_Out[SPBB_NUM_CHANNELS * 4] = {
   -31678, 8454,  28985, -15325, 29992,  13246,  -32194, -6201, 26661,  -19084, -21718, 24563, -23392, -22973, 27939,  17159,
   -31678, 8454,  28985, -15325, -23392, -22973, 27939,  17159, -4834,  -32428, 11964,  30525, 22688,  23669,  -27407, -17995,
   -24824, 21418, 19405, -26428, 32767,  -1154,  -31678, 8454,  15674,  -28798, -8836,  31574, -31068, -10476, 32624,  3262,
   -24824, 21418, 19405, -26428, -31068, -10476, 32624,  3262,  -18489, -27076, 24076,  22255, 30737,  11410,  -32511, -4246};
