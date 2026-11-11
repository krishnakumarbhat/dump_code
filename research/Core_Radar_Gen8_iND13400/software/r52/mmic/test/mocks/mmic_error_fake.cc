/**
 * @file mmic_error_fake.cc
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
 * Mocks of the functions in mmic_error.c file.
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
#include "mmic_error_fake.h"

DEFINE_FAKE_VOID_FUNC(Update_MMIC_Success);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_Faulted);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_Faulted);
DEFINE_FAKE_VOID_FUNC(Set_MMIC_Error_Reinit, MMIC_Error_ID_T);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_Error_Reinit);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_Reinit_Error_Count);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_Error_Reinit);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_MMIC_Error_Reinit_Count);
DEFINE_FAKE_VOID_FUNC(Set_MMIC_Error_Discard, MMIC_Error_ID_T);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_Error_Discard);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_Error_Discard);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_MMIC_Error_Discard_Count);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_Config_Error);
DEFINE_FAKE_VOID_FUNC(Set_MMIC_Config_Error, MMIC_Config_Error_ID_T);
DEFINE_FAKE_VOID_FUNC(Clr_MMIC_API_Look_Fault_Status);
