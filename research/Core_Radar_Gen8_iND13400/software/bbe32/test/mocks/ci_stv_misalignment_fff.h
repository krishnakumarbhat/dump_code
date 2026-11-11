#ifndef CI_STV_MISALIGNMENT_FFF
#define CI_STV_MISALIGNMENT_FFF
/*===========================================================================*/
/**
 * @file ci_stv_misalignment_fff.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the HWA helpers using FFF
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
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "ci_stv_misalignment.h"

/*===========================================================================*
 * Fake value functions - ci_stv_misalignment functions
 *===========================================================================*/
typedef float32_t (*Usc_Matrix_Ptr_T)[4][8];
typedef int16_t (*Dopp_Bb_Coeffs_Out_Ptr_T)[32];

DECLARE_FAKE_VOID_FUNC(Do_Matrix_Multiply, int16_t *, int16_t *, Usc_Matrix_Ptr_T, uint8_t *, uint8_t *, Dopp_Bb_Coeffs_Out_Ptr_T);

/* List of fakes used by this unit tester */
#define FFF_FAKES_CI_STV_MISALLIGN_LIST(FAKE) FAKE(Do_Matrix_Multiply)

#endif /* CI_STV_MISALIGNMENT_FFF */
