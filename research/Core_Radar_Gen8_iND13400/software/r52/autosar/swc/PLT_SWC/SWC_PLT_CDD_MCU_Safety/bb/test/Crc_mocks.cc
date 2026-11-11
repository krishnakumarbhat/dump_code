/*===========================================================================*/
/**
 * @file Crc_mocks.cc
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
 * Fake function declarations for the Crc methods.
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
#include "Crc_mocks.h"
/*===========================================================================*
 * Fake value functions - crc functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(uint32_t, Crc_CalculateCRC32, Crc_DataRefType, uint32, uint32, boolean);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo,
                       Rte_DT_Dt_StaticRegCheckFailureInfo_0 *);
