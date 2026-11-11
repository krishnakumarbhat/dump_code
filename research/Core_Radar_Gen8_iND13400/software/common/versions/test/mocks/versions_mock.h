#ifndef VERSIONS_MOCK_H_
#define VERSIONS_MOCK_H_
/*===========================================================================*/
/**
 * @file versions_mock.h
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
 * Mocking functions for the versions module using FFF
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
#include "versions.h"

/*===========================================================================*
 * Fake value functions - EDMA helper functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(const Application_Version_T *, Get_Application_Version);
DECLARE_FAKE_VALUE_FUNC(const Bootloader_Version_T *, Get_Bootloader_Version);

/* List of fakes used by this unit tester */
#define FFF_FAKES_VERSIONS_LIST(FAKE)                                                                                             \
   FAKE(Get_Application_Version)                                                                                                  \
   FAKE(Get_Bootloader_Version)

#endif /* VERSIONS_MOCK_H_ */
