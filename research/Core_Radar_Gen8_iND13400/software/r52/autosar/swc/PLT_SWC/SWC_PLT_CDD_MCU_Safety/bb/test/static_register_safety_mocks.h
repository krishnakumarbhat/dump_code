#ifndef STATIC_REGISTER_SAFETY_MOCKS_H
#define STATIC_REGISTER_SAFETY_MOCKS_H
/*===========================================================================*/
/**
 * @file static_register_safety_mocks.h
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
 * Mocking functions for the static_register_safety FFF
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
   #include "fff.h"
   /*===========================================================================*
    * C Header Files
    *===========================================================================*/
   /*===========================================================================*
    * Fake value functions - static_register_safety functions
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(Static_Register_Safety_Check);
   #ifdef __cplusplus
}
   #endif
#endif
#define FFF_FAKES_STATIC_REGISTER_SAFETY_LIST(FAKE) FAKE(Static_Register_Safety_Check)
#endif /* STATIC_REGISTER_SAFETY_MOCKS_H */
