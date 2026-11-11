/*===========================================================================*/
/**
 * @file ipc_fff.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake function declarations for the ipc dsp.
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
#include "ipc_fff.h"
/*===========================================================================*
 * Fake value functions - IPC functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_DP_RDD_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_IPC_M2D_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_RP_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
/*===========================================================================*
 * Mock the internal data structure
 *===========================================================================*/
extern "C"
{
}
