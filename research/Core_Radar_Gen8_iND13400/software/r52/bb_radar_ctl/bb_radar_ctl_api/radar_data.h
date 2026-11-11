#ifndef RADAR_DATA_H
#define RADAR_DATA_H
/*===========================================================================*\
 * FILE: radar_data.h
 *===========================================================================
 * Copyright 2024 APTIV, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *    This software component stores radar data using get and put functions.
 * This component may eventually be replaced with AUTOSAR sender-receiver
 * ports.
 *
 * ABBREVIATIONS:
 * RMM - Radar Mode Manager
 * Op  - Operating
 * Req - Requested
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
#include "radar_look_types.h"

/*===========================================================================*\
 * Exported preprocessor #define constants (object-like macros)
\*===========================================================================*/

/*===========================================================================*\
 * Exported preprocessor #define macros (i.e. those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/* Typedef of base types *****************************************************/
typedef uint16_t Scan_Index_T;

/* Typedef of enumerations ***************************************************/
typedef enum Radar_Ctl_Init_Status_Tag
{
   RADAR_CTL_INIT_FAIL,
   RADAR_CTL_INIT_NOT_STARTED,
   RADAR_CTL_INIT_STARTED,
   RADAR_CTL_INIT_SUCCESS,

   NUM_RADAR_CTL_INIT
} Radar_Ctl_Init_Status_T;

typedef enum Radar_Ctl_State_Tag
{
   RADAR_CTL_OFF,
   RADAR_CTL_FAULTED,
   RADAR_CTL_INIT,
   RADAR_CTL_READY,
   RADAR_CTL_CONFIGURED,
   RADAR_CTL_TRANSMITTING,
   RADAR_CTL_A2D_INJECTION,
   RADAR_CTL_PURE_CW,
   RADAR_CTL_DEGRADED,
   RADAR_CTL_IDLE,
   RADAR_CTL_NUM_STATES
} Radar_Ctl_State_T;

typedef enum XCP_Single_Look_Type_Enable_Tag
{
   RADAR_CTL_NO_FORCE_LOOK_TYPE,
   XCP_FORCE_LOOK_TYPE = 0x55AA
} XCP_Single_Look_Type_Enable_T;

/* Typedef of structures *****************************************************/
typedef struct Radar_Ctl_Data_Tag
{
   Radar_Ctl_Init_Status_T init_status;
   Radar_Mode_T this_mode;
   Radar_Look_T this_look;
   Radar_Look_T next_look;
   Scan_Index_T scan_index;
   bool radiate_enable;
} Radar_Ctl_Data_T;

/*===========================================================================*\
 * Exported object declarations
\*===========================================================================*/
extern Radar_Ctl_Data_T Radar_Ctl_Data;
extern Radar_Ctl_State_T Radar_Ctl_State;
extern volatile XCP_Single_Look_Type_Enable_T XCP_Single_Look_Type_Enable;
extern volatile Radar_Look_T XCP_Single_Look_Type;
extern volatile bool XCP_Force_Radar_On;
extern uint8_t RC_Skip_Look;

/*===========================================================================*\
 * Exported function prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Exported inline function definitions and #define function-like macros
\*===========================================================================*/
#define Put_Radar_Radiate_Enable(x) Radar_Ctl_Data.radiate_enable = x
#define Get_Radar_Radiate_Enable()  ((Radar_Ctl_Data.radiate_enable) || (XCP_Force_Radar_On))

#define Put_Radar_Ctl_Init_Status(status) Radar_Ctl_Data.init_status = status
#define Get_Radar_Ctl_Init_Status()       (Radar_Ctl_Data.init_status)

#define Put_Radar_Mode(mode) Radar_Ctl_Data.this_mode = mode
#define Get_Radar_Mode()     (Radar_Ctl_Data.this_mode)
#define Get_Radar_Mode_Ptr() (&Radar_Ctl_Data.this_mode)

#define Put_Radar_Look(look) Radar_Ctl_Data.this_look = look
#define Get_Radar_Look()     (Radar_Ctl_Data.this_look)
#define Get_Radar_Look_Ptr() (&Radar_Ctl_Data.this_look)

#define Put_Radar_Next_Look(index) Radar_Ctl_Data.next_look = index
#define Get_Radar_Next_Look()      (Radar_Ctl_Data.next_look)

#define Put_Radar_Scan_Index(index) Radar_Ctl_Data.scan_index = index
#define Get_Radar_Scan_Index()      (Radar_Ctl_Data.scan_index)

#define Put_Radar_Ctl_State(state) Radar_Ctl_State = state
#define Get_Radar_Ctl_State()      (Radar_Ctl_State)

#define Put_Skip_Look_State(state) RC_Skip_Look = (state)
#define Get_Skip_Look_State()      (RC_Skip_Look)
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 15-May-2023  tjy9rb  DDR-1972: Integrate radar control mode for SmartTRX.
 * 20-Mar-2025  djdgwr  EPB-3559: Enable Force Look through global variables related to changes.
\*===========================================================================*/
#endif
