#ifndef RADAR_CTL_H
#define RADAR_CTL_H
/*===========================================================================*\
 * FILE: radar_ctl.h
 *===========================================================================
 * Copyright 2024 APTIV, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This module coordinates the initialization and triggering of radar frames or
 * looks.
 *
 * ABBREVIATIONS:
 *    CTL - Control
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
#include "Rte_SWC_PLT_CDD_Radar_Control_Type.h"

/*===========================================================================*\
 * Exported preprocessor #define constants (object-like macros)
\*===========================================================================*/
#define RADAR_CONTROL_MODE_TEST (1)
/*===========================================================================*\
 * Exported preprocessor #define macros (i.e. those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Exported object declarations
\*===========================================================================*/
extern Dt_RadarCoreStatus Radar_Core_Status;
/*===========================================================================*\
 * Exported function prototypes
\*===========================================================================*/
void Radar_Ctl_Reset_Init(void);
void Radar_Ctl_Periodic(void);
void Radar_Ctl_Look_Trigger(void);
void Radar_Ctl_Look_Complete(void);
void Radar_Ctl_Look_Sync_Trig(void);
bool Radar_Ctl_Look_Sync_Trig_Tst(void);
void Radar_Ctl_Look_Sync_Trig_Clear(void);

#if RESI_MODE_ENABLE
void RESI_Mode_Put_Next_Look(void);
#endif

/*===========================================================================*\
 * Exported inline function definitions and #define function-like macros
\*===========================================================================*/
#define Get_Radar_Ctl_Idle_Timeout_State() (MMIC_Stream.MMIC_Data.ot_handle.idle_timeout_status)
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
