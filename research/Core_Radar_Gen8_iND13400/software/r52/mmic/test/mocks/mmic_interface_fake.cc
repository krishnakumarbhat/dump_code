/**
 * @file mmic_interface_fake.cc
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
 * Mocks of the functions in mmic_interface.c file.
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
#include "mmic_interface_fake.h"

DEFINE_FAKE_VOID_FUNC(MMIC_Reset_Init);
DEFINE_FAKE_VOID_FUNC(MMIC_Config_Device);
DEFINE_FAKE_VOID_FUNC(MMIC_Reset_MIPI);
DEFINE_FAKE_VOID_FUNC(Update_Radar_Data_Status);
DEFINE_FAKE_VOID_FUNC(Update_Mmic_Discard_Error);
DEFINE_FAKE_VOID_FUNC(Update_MMIC_Reinit_Request, uint8_t);
DEFINE_FAKE_VOID_FUNC(MMIC_Config_Look);
DEFINE_FAKE_VOID_FUNC(MMIC_Look_Trigger);
DEFINE_FAKE_VOID_FUNC(MMIC_Look_Complete);
DEFINE_FAKE_VOID_FUNC(MIPI_Init);
DEFINE_FAKE_VOID_FUNC(MMIC_Reset_MARS);
DEFINE_FAKE_VOID_FUNC(Reset_MCU_Handle);
DEFINE_FAKE_VOID_FUNC(Update_Dwell_Timestamps);
DEFINE_FAKE_VOID_FUNC(Get_MMIC_Low_Temp_Fault);
DEFINE_FAKE_VOID_FUNC(Get_MMIC_High_Temp_Fault);
