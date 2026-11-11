/**
 * @file Fault_Lib_Plt_fake.cc
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

#include "Fault_Lib_Plt_fake.h"
DEFINE_FAKE_VALUE_FUNC(void *, memset, void *, int, size_t);
DEFINE_FAKE_VOID_FUNC(Clear_Fault_If_Enabled_and_Not_Latched, uint16);
DEFINE_FAKE_VOID_FUNC(Set_Fault_If_Enabled, uint16);
DEFINE_FAKE_VOID_FUNC(Set_Test_Completed_If_Enabled, uint16);
DEFINE_FAKE_VOID_FUNC(Clear_Cust_Fault_Information, uint16);
DEFINE_FAKE_VOID_FUNC(Clear_Cust_Fault_Arrays);
DEFINE_FAKE_VALUE_FUNC(boolean, Cust_Fault_Enabled_Disable, fault_name_T, uint8);
