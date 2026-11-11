/**
 * @file SWC_PLT_Appl_ModeManager_fake.h
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
 * Mocks of the functions in SWC_PLT_Appl_ModeManager.c file.
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
#ifndef SWC_PLT_APPL_MODEMANAGER_FAKE_H_
#define SWC_PLT_APPL_MODEMANAGER_FAKE_H_

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(Mode_Manager_StateMachine_5ms);
   DECLARE_FAKE_VOID_FUNC(Mode_Manager_Main_50ms);
   DECLARE_FAKE_VOID_FUNC(Mode_manager_Init);
#ifdef __cplusplus
}
#endif
#define FFF_FAKES_MODE_MANAGER_LIST(FAKE)                                                                                         \
   FAKE(Mode_Manager_StateMachine_5ms)                                                                                            \
   FAKE(Mode_manager_Init)
#endif
