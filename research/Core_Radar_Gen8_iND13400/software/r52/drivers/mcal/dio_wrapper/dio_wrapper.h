#ifndef DIO_WRAPPER_H
#define DIO_WRAPPER_H

/*===========================================================================*\
 * FILE: dio_wrapper.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the APIs and types for DIO wrapper with board
 *   revision validation
 *
 * ABBREVIATIONS:
 *   DIO - Digital Input/Output
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include <stdbool.h>

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Dio.h"
#include "Dio_Cfg.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/
typedef enum Dio_Wrapper_Status_Tag
{
   DIO_WRAPPER_OK = 0,
   DIO_WRAPPER_INVALID_CHANNEL,
   DIO_WRAPPER_BOARD_MISMATCH
} Dio_Wrapper_Status_T;

/*===========================================================================*\
 * Exported Const Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

/*****************************************************************************
 * Function: Dio_Wrapper_ReadChannel
 *
 * Description:
 *   Wrapper function for Dio_ReadChannel that validates channel access based
 *   on board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 and A3-specific pins.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *   Level     - Pointer to store the read level value
 *   Status    - Pointer to store operation status
 *
 * Return:
 *   Dio_LevelType - Channel level (STD_HIGH/STD_LOW) if successful,
 *                   STD_LOW if validation fails
 ******************************************************************************/
Dio_LevelType Dio_Wrapper_ReadChannel(Dio_ChannelType ChannelId, Dio_Wrapper_Status_T *Status);

/*****************************************************************************
 * Function: Dio_Wrapper_WriteChannel
 *
 * Description:
 *   Wrapper function for Dio_WriteChannel that validates channel access based
 *   on board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 and A3-specific pins.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *   Level     - Level to be written (STD_HIGH/STD_LOW)
 *
 * Return:
 *   Dio_Wrapper_Status_T - Status of the operation
 ******************************************************************************/
Dio_Wrapper_Status_T Dio_Wrapper_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*****************************************************************************
 * Function: Dio_Wrapper_IsChannelAllowed
 *
 * Description:
 *   Checks if a DIO channel is allowed to be accessed based on the current
 *   board revision.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *
 * Return:
 *   bool - true if channel access is allowed, false otherwise
 ******************************************************************************/
bool Dio_Wrapper_IsChannelAllowed(Dio_ChannelType ChannelId);

#endif /* DIO_WRAPPER_H */
