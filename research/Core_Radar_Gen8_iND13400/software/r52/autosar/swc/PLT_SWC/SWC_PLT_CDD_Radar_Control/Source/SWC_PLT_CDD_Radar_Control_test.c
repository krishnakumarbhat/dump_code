/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_Radar_Control_test.c
 *
 * Test stubs and utilities for Radar Control SWC
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Test stubs and utilities for Radar Control SWC
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
#include <cstring>

/*===========================================================================*
 * External Header Files
 *===========================================================================*/
#if ((ENABLE_SQT_TEST_STUBS == STD_ON) || (ENABLE_SIT_TEST_STUBS == STD_ON))
   #include "Rte_SWC_PLT_CDD_Radar_Control.h"
   #include "mcal_init.h"
volatile uint8_t Test_MMIC_Error_Flags = 0U;
volatile uint8_t Test_Disable_Se       = 0;

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Test_MMIC_Error_Flags_Set
 *   This function includes stub code to verify interfaces of MMIC Errors to Diagnostic Component
 *
 * Shared Variables: none
 *
 * Parameters: Dt_MMIC_ErrorFlags *   - Pointer to the MMIC Error Flags structure
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Test_MMIC_Error_Flags_Set(Dt_MMIC_ErrorFlags *MMIC_Errors)
{
   if (Test_MMIC_Error_Flags == 1U)
   {
      (void)memset(MMIC_Errors, CODED_FALSE, sizeof(Dt_MMIC_ErrorFlags));
   }
   if (Test_MMIC_Error_Flags == 2U)
   {
      (void)memset(MMIC_Errors, CODED_TRUE, sizeof(Dt_MMIC_ErrorFlags));
   }
}
/******************************************************************************
 * Name:  Disable_Wdg_Supervised_Entities
 *   This function includes stub code to verify interfaces of Disable and Enable Wdg Supervised Entities
 *
 * Shared Variables: none
 *
 * Parameters: void
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Disable_Wdg_Supervised_Entities(void)
{
   if (Test_Disable_Se == 1U)
   {
      (void)Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation(CODED_TRUE);
   }
}
#endif
