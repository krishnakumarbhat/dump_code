/*===========================================================================*\
 * FILE: radar_data.c
 *===========================================================================
 * Copyright 2020 APTIV, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *    This software component stores radar data using get and put functions.
 * This component may eventually be replaced with AUTOSAR sender-receiver
 * ports.
 *
 * ABBREVIATIONS:
 *
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
#include "radar_data.h"

/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/

/*===========================================================================*\
 * Local preprocessor #define MACROS()
\*===========================================================================*/

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/
Radar_Ctl_Data_T Radar_Ctl_Data;
Radar_Ctl_State_T Radar_Ctl_State;
/*initializing the Global variables used for Force Look*/
volatile XCP_Single_Look_Type_Enable_T XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
volatile Radar_Look_T XCP_Single_Look_Type                         = RADAR_LOOK_C;

volatile bool XCP_Force_Radar_On = false;
uint8_t RC_Skip_Look             = CODED_FALSE;

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local function prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Local inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 15-May-2023  tjy9rb  DDR-1972: Integrate radar control mode for SmartTRX.
 * 20-Mar-2025  djdgwr  EPB-3559: Enable Force Look through global variables related to changes.
\*===========================================================================*/
