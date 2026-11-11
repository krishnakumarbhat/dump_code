/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_WdgHandler_Test.c
 *
 * @todo For testing of interfaces and functionality of SWC_PLT_CDD_WdgHandler
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

#include "Rte_SWC_PLT_CDD_WdgHandler.h"
#include "SWC_PLT_CDD_WdgHandler_cfg.h"
#include "reuse.h"
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
volatile uint8 Test_Intwdg_Fail_Status = 0;
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Wdghandler_Integration_Test
 *  This function includes stub code to verify interfaces of Wdghandler
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Wdghandler_Integration_Test(void)
{
   if (Test_Intwdg_Fail_Status == 1)
   {
      Rte_Write_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(CODED_TRUE);
   }
}

#endif
