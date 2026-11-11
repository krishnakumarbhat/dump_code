#ifndef SWC_PLT_CDD_HIL_H
#define SWC_PLT_CDD_HIL_H
/*===========================================================================*\
 * FILE: SWC_PLT_CDD_HIL.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This header file declares interfaces and function prototypes for the
 *   Hardware-in-the-Loop (HIL) module, supporting HIL testing and integration
 *   within the radar software system.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     Update list of design document(s)
 *
 *   Requirements Document(s):
 *     Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
#include "Std_Types.h"
#include "reuse.h"

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
uint8_t Get_MPU_Status_For_HIL_Trigger(void);

/*===========================================================================*
 * Import function prototypes
 *===========================================================================*/

#endif /* SWC_PLT_CDD_HIL_H */
