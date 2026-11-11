#ifndef XCP_ADC_LOGGING_FFF_H
#define XCP_ADC_LOGGING_FFF_H
/*===========================================================================*/
/**
 * @file xcp_adc_logging_fff.h
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
 * Mocking functions for xcp_adc_logging using FFF.
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
#ifndef ENABLE_ADC_DATA_LOGGING
   #define ENABLE_ADC_DATA_LOGGING (1U)
#endif
#include "xcp_adc_logging.h"
/*===========================================================================*
 * Fake void functions - xcp_adc_logging functions
 *===========================================================================*/
DECLARE_FAKE_VOID_FUNC(Post_Process_ADC_Data_Buffer);
DECLARE_FAKE_VOID_FUNC(Configure_ADC_XCP_Output);
DECLARE_FAKE_VOID_FUNC(Invalidate_ADC_XCP_Cache);

/* List of fakes used by this unit tester */
#define FFF_FAKES_XCP_ADC_LOGGING_LIST(FAKE)                                                                                      \
   FAKE(Post_Process_ADC_Data_Buffer)                                                                                             \
   FAKE(Configure_ADC_XCP_Output)                                                                                                 \
   FAKE(Invalidate_ADC_XCP_Cache)

#endif /* XCP_ADC_LOGGING_FFF_H */
