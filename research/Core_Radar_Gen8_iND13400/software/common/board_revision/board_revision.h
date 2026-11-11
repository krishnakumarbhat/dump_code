#ifndef BOARD_REVISION_H
#define BOARD_REVISION_H

/*===========================================================================*\
 * FILE: board_revision.h
 *===========================================================================
 * Copyright (C) 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This is the header file for board revision.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdint.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "board_revision_cfg.h"

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef struct Board_Rev_Threshold_Tag
{
   uint16_t lower;
   uint16_t upper;
} Board_Rev_Threshold_T;

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*\
 *                         Exported Function Prototypes
\*===========================================================================*/
void Read_Board_Revision(void);
Board_Revision_T Get_Board_Revision(void);

#endif /* BOARD_REVISION_H */
