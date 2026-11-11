/**
 * @file SWC_PLT_Appl_IoHwAb_fake.cc
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
 * Mocks of the functions in SWC_PLT_Appl_IoHwAb.c file.
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
#include "SWC_PLT_Appl_IoHwAb_fake.h"
DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, IoHwAb_Appl_ThermMonTemp_Read, Dt_Therm_Mon_Temp_Opt_T,
                       DT_Thermal_Monitor_Temperatures_T *);
DEFINE_FAKE_VOID_FUNC(IoHwAb_Appl_Init);
DEFINE_FAKE_VOID_FUNC(IoHwAb_Appl_Main_50ms);
DEFINE_FAKE_VOID_FUNC(IoHwAb_Appl_Main_5ms);
DEFINE_FAKE_VOID_FUNC(Can_MainFunction_Mode);
DEFINE_FAKE_VOID_FUNC(Eth_MainFunction);
DEFINE_FAKE_VOID_FUNC(Platform_Time_Register_set, uint8);
