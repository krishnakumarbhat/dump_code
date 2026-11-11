#ifndef BOARD_REVISION_MOCKS_H_
#define BOARD_REVISION_MOCKS_H_

/*===========================================================================*/
/**
 * @file board_revision_mocks.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the board_revision.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "board_revision_cfg.h"
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
#include "fff.h"

   /*===========================================================================*
    * FAKE VALUE FUNCTIONS for board_revision.c
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Board_Revision_T, Get_Board_Revision);
   /*===========================================================================*
    * FAKE VOID FUNCTIONS for board_revision.c
    *===========================================================================*/

   DECLARE_FAKE_VOID_FUNC(Read_Board_Revision);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */
#define FFF_FAKES_BOARD_REVISION_LIST(FAKE)                                                                                       \
   FAKE(Read_Board_Revision)                                                                                                      \
   FAKE(Get_Board_Revision)

#endif /* BOARD_REVISION_MOCKS_H_ */
