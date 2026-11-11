/**
 * @file Fault_Lib_Plt_fake.h
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
 * Mocks of the functions in Fault_Lib_Plt.c file.
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
#ifndef FAULT_LIB_PLT_FAKE_H_
#define FAULT_LIB_PLT_FAKE_H_

#include "fff.h"
extern "C"
{
#include "Fault_Lib_Plt.h"
}

#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VALUE_FUNC(void *, memset, void *, int, size_t);
   DECLARE_FAKE_VOID_FUNC(Clear_Fault_If_Enabled_and_Not_Latched, uint16);
   DECLARE_FAKE_VOID_FUNC(Set_Fault_If_Enabled, uint16);
   DECLARE_FAKE_VOID_FUNC(Set_Test_Completed_If_Enabled, uint16);
   DECLARE_FAKE_VOID_FUNC(Clear_Cust_Fault_Information, uint16);
   DECLARE_FAKE_VOID_FUNC(Clear_Cust_Fault_Arrays);
   DECLARE_FAKE_VALUE_FUNC(boolean, Cust_Fault_Enabled_Disable, fault_name_T, uint8);

#ifdef __cplusplus
}
#endif
#endif
