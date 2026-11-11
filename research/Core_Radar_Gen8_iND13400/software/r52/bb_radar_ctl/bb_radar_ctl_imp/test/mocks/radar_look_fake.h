/**
 * @file radar_look_fake.h
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
 * Mocks of the functions in radar_look.c file.
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
#ifndef RADAR_LOOK_FAKE_H_
#define RADAR_LOOK_FAKE_H_

#include "fff.h"
#include "radar_look.h"

DECLARE_FAKE_VOID_FUNC(Init_Radar_Look);
DECLARE_FAKE_VOID_FUNC(Next_Radar_Look);
extern "C"
{
#include "Rte_Type.h"
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable,
                           Idt_XCP_Single_Look_T *);
}
/* Reset radar look functions*/
#define FFF_FAKES_RADAR_LOOK_LIST(FAKE)                                                                                           \
   FAKE(Init_Radar_Look)                                                                                                          \
   FAKE(Next_Radar_Look)

#endif
