#ifndef BOARD_REVISION_CFG_H
#define BOARD_REVISION_CFG_H

/*===========================================================================*\
 * FILE: board_revision_cfg.h
 *===========================================================================
 * Copyright (C) 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This is the header file for board revision configuration.
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

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef enum Board_Revision_Tag
{
   BOARD_REV_EDU,
   BOARD_REV_EDU3,
   BOARD_REV_A0,
   BOARD_REV_EDU5,
   BOARD_REV_A2P0,
   BOARD_REV_A2P1,
   BOARD_REV_A3P0, /* Ashok Leyland 24V CV variant */
   BOARD_REV_EDU8P5,
   BOARD_REV_A4P0,
   BOARD_REV_B0CVAL,
   BOARD_REV_B0CVAL_ETH,
   UNDEFINED_11,
   UNDEFINED_12,
   UNDEFINED_13,
   UNDEFINED_14,
   UNDEFINED_15,
   UNDEFINED_16,
   BOARD_REV_MAX
} Board_Revision_T;

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*\
 *                         Exported Function Prototypes
\*===========================================================================*/

#endif /* BOARD_REVISION_CFG_H */
