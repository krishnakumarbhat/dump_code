/*===========================================================================*/
/**
 * @file program_flow_monitor_fff.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mock functions for program_flow_monitor.c file.
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

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "program_flow_monitor_fff.h"

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for program_flow_monitor.c
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(PFM_Update_Stage, PFM_Stage_T, uint32_t);
DEFINE_FAKE_VALUE_FUNC(PFM_Flow_Status_T, PFM_Get_Status);
DEFINE_FAKE_VALUE_FUNC(uint32_t, PFM_Get_Fail_Count);
DEFINE_FAKE_VALUE_FUNC(uint32_t, PFM_Get_Success_Count);
