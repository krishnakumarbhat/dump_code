#ifndef SWC_CMP_PRJ_UDSHANDLER_H /* { */
#define SWC_CMP_PRJ_UDSHANDLER_H
/*===========================================================================*\
 * FILE: SWC_CMP_PRJ_UDSHandler.h
 *===========================================================================
 * Copyright 2022 Aptiv, Inc., All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  SWC_CMP_PRJ_UDSHandler.h
 * %version:  1 %
 * %derived_by:   %
 * %date_modified:  %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *  This file contains functions & object definitions for SWC_PRJ_UDSHandler.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *       TODO: Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

#define INDEX_ZERO     (0U)
#define OP_MODE_OFFSET (1U)

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define SENSOR_POS_LOCKED                0x00U
#define SENSOR_POS_UNLOCKED              0x01U
#define RID_STATUS_SUCCESSFUL            0x0
#define RID_STATUS_UNSUCCESSFUL          0x1
#define RID_STATUS_INPROGRESS            0x2
#define DEFAULT_VALUE                    0xFFU
#define RID_INFO_BIT_COMPLETED           0x01 /* Bit 0: Routine completed successfully */
#define RID_INFO_BIT_ABORTED_BY_ECU      0x02 /* Bit 1: Routine aborted by ECU (unsuccessful) */
#define RID_INFO_BIT_ROUTINE_IN_PROGRESS 0x08 /* Bit 3: Routine still in progress */
#define ROUTINE_FAILED                   0x01
#define ROUTINE_STARTED_SUCCESSFULLY     0x00
#define SRR_FC                           0x05U
#define SRR_L1                           0x04U
#define SRR_L2                           0x01U

/* Control DTC and sub function*/
#define CONTROL_DTC     (0x85)
#define CONTROL_DTC_ON  (0x01)
#define CONTROL_DTC_OFF (0x02)

#define CLEAR_DTC_SERVICE (0x14)
typedef enum UDSResetReasonTypeTag
{
   NONE = 0u,
   SOFT_RESET,
} UDSResetReasonType;
typedef enum
{
   PLT_POS_INVALID,
   PLT_POS_SRR_FC,
   PLT_POS_SRR_L1,
   PLT_POS_SRR_L2,
} Plt_PositionType;
typedef enum
{
   ROUTINE_INIT     = 0,
   ROUTINE_START    = 1,
   ROUTINE_PROGRESS = 2,
   ROUTINE_ABORT    = 3,
   ROUTINE_COMPLETE = 4
} RID_Status;
/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
extern void Perform_SoftReset(void);
extern void Diag_services_fnc_caller(void);
void julian_to_calendar(uint8 julian_year, uint16 julian_date, uint8 *year, uint8 *month, uint8 *day);

#endif /* SWC_CMP_PRJ_UDSHANDLER_H */
