/**
 * @file p_l_xcp_core_fake.h
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
 * Mocks of the functions in p_l_xcp_core.c file.
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
#ifndef P_L_XCP_CORE_FAKE_H_
#define P_L_XCP_CORE_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "xcp_bb_types.h"

   DECLARE_FAKE_VOID_FUNC(XCP_BB_Refresh_Dynamic_Data);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, xcp_periodic_task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(XCP_BB_Input_Params_T *, Get_XCP_Init_Parameters);

#ifdef __cplusplus
}
#endif
#define FFF_FAKES_XCP_BB_INPUT_PARAMS_INIT_LIST(FAKE)                                                                             \
   FAKE(XCP_BB_Refresh_Dynamic_Data)                                                                                              \
   FAKE(xcp_periodic_task)                                                                                                        \
   FAKE(Get_XCP_Init_Parameters)

#endif
