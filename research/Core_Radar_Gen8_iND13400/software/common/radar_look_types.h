/**
 * @file radar_look_types.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Radar look type definition
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
#ifndef RADAR_LOOK_TYPES_H
#define RADAR_LOOK_TYPES_H

typedef enum Radar_Look_Tag
{
   RADAR_LOOK_A,
   RADAR_LOOK_B,
   RADAR_LOOK_C,
   RADAR_LOOK_D,
   RADAR_LOOK_E,
   RADAR_LOOK_F,

   NUM_LOOKS
} Radar_Look_T;

typedef enum Radar_Mode_Tag
{
   RADAR_MODE_A,
   RADAR_MODE_B,
   RADAR_MODE_C,
   RADAR_MODE_D,
   RADAR_MODE_E,
   RADAR_MODE_F,
   RADAR_MODE_G,
   RADAR_MODE_H,

   NUM_MODES
} Radar_Mode_T;

#endif
