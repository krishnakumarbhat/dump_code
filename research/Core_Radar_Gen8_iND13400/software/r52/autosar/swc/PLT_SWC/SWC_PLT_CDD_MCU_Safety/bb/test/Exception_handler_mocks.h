#ifndef EXCEPTION_HANDLER_MOCKS_H_
#define EXCEPTION_HANDLER_MOCKS_H_
/*===========================================================================*/
/**
 * @file illegal_inst_is_mocks.h
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
 * Mocking functions for the MCU_Safety FFF
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
#ifdef __cplusplus
extern "C"
{
#endif

#include "fff.h"

   DECLARE_FAKE_VOID_FUNC(ExceptionHandler_Illegal_Instruction);
   DECLARE_FAKE_VOID_FUNC(ExceptionHandler_Abort_Prefetch);
   DECLARE_FAKE_VOID_FUNC(ExceptionHandler_Abort_Data);

#ifdef __cplusplus
}
#endif

#endif /* EXCEPTION_HANDLER_MOCKS_H_ */
