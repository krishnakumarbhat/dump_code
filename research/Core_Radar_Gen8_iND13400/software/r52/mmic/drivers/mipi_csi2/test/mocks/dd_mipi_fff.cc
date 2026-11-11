/*===========================================================================*/
/**
 * @file dd_mipi_fff.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake function definitions for dd_mipi.
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
#include "dd_mipi_fff.h"
/*===========================================================================*
 * Fake value functions - dd_mipi functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Disable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Enable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Disable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_CSI2_Config, const volatile MIPI_CSI2_Rx_Settings_T *);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Init, const volatile MIPI_Config_T *);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Write_Chirp, const volatile int16_t *, uint16_t, uint16_t, uint8_t);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Disable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Enable, uint8_t);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Config, uint8_t);
DEFINE_FAKE_VOID_FUNC(Initialize_Frame_Start_Output_Gpio);
DEFINE_FAKE_VOID_FUNC(Trigger_Frame_Start_To_Resi);
