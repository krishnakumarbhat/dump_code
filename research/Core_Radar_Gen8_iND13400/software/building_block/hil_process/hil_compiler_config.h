#ifndef HIL_MODULE_COMPILER_CFG_H
#define HIL_MODULE_COMPILER_CFG_H
/*===========================================================================*/
/**
 * @file
 *
 * Configurations for the Module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright 2023 Aptiv, All Rights Reserved.
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
\*===========================================================================*/

/*===========================================================================*
 * Header Files
\*===========================================================================*/

/*===========================================================================*
 * #define MACROS
\*===========================================================================*/
#if defined(HIL_CODE_OPTIMIZE_OFF)
   #undef HIL_OPTIMIZE_OFF
   #pragma clang optimize off
#elif defined(HIL_CODE_OPTIMIZE_ON)
   #undef HIL_OPTIMIZE_ON
   #pragma clang optimize on
#endif

/*===========================================================================*
 * #define Constants
\*===========================================================================*/

/*===========================================================================*
 * Custom Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid   (Description on following lines: SCR #, etc.)
 * --------    -----    ------------------------------------------------------
 * 18-Mar-2026  zjfskq   EUR-2481 created file to pass compiler config.

\*===========================================================================*/
#endif // HIL_MODULE_COMPILER_CFG_H
