/*===========================================================================*/
/**
 * @file therm_mon_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Implementation of fakes/mocks for thermal monitor unit tests
 *
 * @section ABBR ABBREVIATIONS:
 *   - TMU - Thermal Monitoring Unit
 *   - PVT - Process, Voltage, Temperature
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
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "therm_mon_fake.h"
#include "fff.h"

/*===========================================================================*
 * FFF Globals - Must be defined in exactly one compilation unit
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Mock Hardware Register Definitions
 *===========================================================================*/

/*===========================================================================*
 * Fake Function Definitions (using FFF)
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, uint16);
