#ifndef MCU_RESET_WRAPPER
#define MCU_RESET_WRAPPER
/*===========================================================================*\
 * FILE: mcu_reset_wrapper.h
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the APIs and types for mcu_reset_wrapper
 *
 * ABBREVIATIONS:
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

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
typedef enum Mcu_reset_Tag
{
   RESET_POR = 0,
   RESET_SW_INTENTIONAL,
   RESET_SW_UNINTENTIONAL,
   RESET_MAX
} Mcu_reset_T;
void Mcu_Reset(Mcu_reset_T);

#endif /* MCU_RESET_WRAPPER */
