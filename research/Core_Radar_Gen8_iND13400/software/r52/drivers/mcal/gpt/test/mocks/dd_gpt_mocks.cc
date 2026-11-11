/*===========================================================================*/
/**
 * @file dd_gpt_mocks.cc
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
 * Fake function declarations for the dd GPT module methods.
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
#include "dd_gpt_mocks.h"

/*===========================================================================*
 * Fake value functions - dd GPT functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(Init_GPT_Wrapper);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Timestamp_Milliseconds);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Elapsed_Time_Milliseconds, uint32_t);
DEFINE_FAKE_VOID_FUNC(Set_Timer_Cnt_Value_ms, Gpt_TimerPhysicalChannelType, float32);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Set_Trigger_GPT_Time, uint32_t);
DEFINE_FAKE_VOID_FUNC(Start_EcuSync_Timer);
