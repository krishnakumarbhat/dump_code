/**
 * @file mmic_interface_fake.h
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
#ifndef MMIC_INTERFACE_FAKE_H_
#define MMIC_INTERFACE_FAKE_H_

#include "fff.h"
#include <stdbool.h>

extern "C"
{
// #include "dd_mipi.h"
#include "dd_mmic.h"
#include "dd_mmic_fake.h"
#include "mmic_interface.h"

   DECLARE_FAKE_VOID_FUNC(MMIC_Reset_Init);
   DECLARE_FAKE_VOID_FUNC(MMIC_Config_Device);
   DECLARE_FAKE_VOID_FUNC(MMIC_Config_Look);
   DECLARE_FAKE_VOID_FUNC(MMIC_Look_Trigger);
   DECLARE_FAKE_VOID_FUNC(MMIC_Look_Complete);
   DECLARE_FAKE_VOID_FUNC(MIPI_Init);
   DECLARE_FAKE_VOID_FUNC(MMIC_Reset_MIPI);
   DECLARE_FAKE_VOID_FUNC(Update_Radar_Data_Status);
   DECLARE_FAKE_VOID_FUNC(Update_Mmic_Discard_Error);
   DECLARE_FAKE_VOID_FUNC(Update_MMIC_Reinit_Request, uint8_t);
   DECLARE_FAKE_VOID_FUNC(MMIC_Reset_MARS);
   DECLARE_FAKE_VOID_FUNC(Reset_MCU_Handle);
   DECLARE_FAKE_VOID_FUNC(Update_Dwell_Timestamps);
   DECLARE_FAKE_VOID_FUNC(Get_MMIC_Low_Temp_Fault);
   DECLARE_FAKE_VOID_FUNC(Get_MMIC_High_Temp_Fault);

/* Reset fake functions */
#define FFF_FAKES_MMIC_INTERFACE_FUNCTION(FAKE)                                                                                   \
   FAKE(MMIC_Config_Device)                                                                                                       \
   FAKE(MMIC_Config_Look)                                                                                                         \
   FAKE(MMIC_Look_Complete)                                                                                                       \
   FAKE(MMIC_Look_Trigger)                                                                                                        \
   FAKE(Update_MMIC_Reinit_Request)                                                                                               \
   FAKE(MMIC_Reset_Init)                                                                                                          \
   FAKE(MMIC_Reset_MARS)                                                                                                          \
   FAKE(Reset_MCU_Handle)
}
#endif
