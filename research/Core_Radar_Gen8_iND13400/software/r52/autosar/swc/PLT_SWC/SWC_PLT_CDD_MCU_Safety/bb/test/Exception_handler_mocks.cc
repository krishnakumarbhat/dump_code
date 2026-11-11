/*===========================================================================*/
/**
 * @file MCU_Safety_mocks.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake function declarations for the MCU_Safety methods.
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
//#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "Exception_Handler_mocks.h"

/*===========================================================================*
 * Fake value functions - MCU_Safety functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(ExceptionHandler_Illegal_Instruction);
DEFINE_FAKE_VOID_FUNC(ExceptionHandler_Abort_Prefetch);
DEFINE_FAKE_VOID_FUNC(ExceptionHandler_Abort_Data);
