/**
 * @file main_application.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Main application definitions.
 * @note This file should only contain constant definitions and NO INCLUDE files.
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
#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include <stdbool.h>
#include <stdint.h>

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#define ENABLE_PROFILE_TIMING_OUTPUTS
#define RADAR_CYCLE_MS_DSP (50U) /** @todo : It needs to be removed once RADAR_CYCLE_MS is available*/

/* ========================================================================== */
/*                         Type Definitions                                   */
/* ========================================================================== */
typedef struct L2_BSIS_Feature_Degradation_Flags_Tag
{
   uint8_t bsis_self_blockage_flag;
   uint8_t bsis_self_align_init_calib_degrade_flag;
} L2_BSIS_Feature_Degradation_Flags_T;

typedef struct L2_MOIS_Feature_Degradation_Flags_Tag
{
   uint8_t mois_self_blockage_flag;
   uint8_t mois_self_align_init_calib_degrade_flag;
} L2_MOIS_Feature_Degradation_Flags_T;
/* ========================================================================== */
/*                      Function Declarations                                 */
/* ========================================================================== */
uint16_t Get_Current_Lookindex(void);
void __attribute__((section(".sram0.text"))) Main_Application(void);

#endif
