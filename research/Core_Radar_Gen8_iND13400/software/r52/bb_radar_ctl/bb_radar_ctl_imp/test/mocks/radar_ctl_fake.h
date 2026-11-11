/**
 * @file radar_ctl_fake.h
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
 * Mocks of the functions in radar_ctl.c file.
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
#ifndef RADAR_CTL_FAKE_H_
#define RADAR_CTL_FAKE_H_

#include "fff.h"

#include "radar_ctl.h"

DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Reset_Init);
DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Periodic);
DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Look_Trigger);
DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Look_Complete);

/* Reset fake functions */
#define FFF_FAKES_RADAR_CTL_FUNCTION(FAKE)                                                                                        \
   FAKE(Radar_Ctl_Reset_Init)                                                                                                     \
   FAKE(Radar_Ctl_Periodic)                                                                                                       \
   FAKE(Radar_Ctl_Look_Trigger)                                                                                                   \
   FAKE(Radar_Ctl_Look_Complete)

#endif /* DD_SENSOR_POS_FAKE_H_ */
