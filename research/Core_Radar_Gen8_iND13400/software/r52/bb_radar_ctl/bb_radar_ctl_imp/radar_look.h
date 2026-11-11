#ifndef RADAR_LOOK_H
#define RADAR_LOOK_H
/*===========================================================================*\
 * FILE: mmic_look.h
 *===========================================================================
 * Copyright 2020 APTIV, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This software component updates the look and operating mode of the radar
 * system.
 *
 * ABBREVIATIONS:
 *    RMM - Radar Mode Manager
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *
 *   Requirements Document(s):
 *
 *
 *   Applicable Standards (in order of precedence: highest first):
 *   1. C Coding Standards SW REF 264.15D
 *
 * DEVIATIONS FROM STANDARDS:
 *
 *
\*===========================================================================*/
/*===========================================================================*\
 * Preprocessor #include directive(s) for standard header files
\*===========================================================================*/
#include "reuse.h"

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/

/*===========================================================================*\
 * Exported preprocessor #define constants (object-like macros)
\*===========================================================================*/

/*===========================================================================*\
 * Exported preprocessor #define macros (i.e. those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef enum Look_Sync_Status_Tag
{
   NotAvailable = 1,
   InSync,
   OutOfSync,
} Look_Sync_Status_T;
typedef enum Look_Sync_Enable_Tag
{
   Look_Sync_Disable = 0,
   Look_Sync_Enable,

} Look_Sync_Enable_T;
/*===========================================================================*\
 * Exported object declarations
\*===========================================================================*/
extern volatile Look_Sync_Status_T Look_Sync_Status;
extern volatile Look_Sync_Enable_T Look_Sync;

/*===========================================================================*\
 * Exported function prototypes
\*===========================================================================*/
void Init_Radar_Look(void);
void Next_Radar_Look(void);
bool Radar_Look_Sync_Test(bool tsyn_status);
/*===========================================================================*\
 * Exported inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 15-May-2023 tjy9rb
 * + DDR-1972: Integrate radar control mode for SmartTRX.
 *
\*===========================================================================*/
#endif
