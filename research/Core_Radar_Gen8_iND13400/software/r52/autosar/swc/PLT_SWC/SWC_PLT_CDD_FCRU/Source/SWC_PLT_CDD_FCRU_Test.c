/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_FCRU_Test.c
 *
 * @todo This file contains test code for the SWC_PLT_CDD_FCRU component, including integration and functionality tests for
 *FCRU mechanisms.
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
#include "Rte_SWC_PLT_CDD_FCRU.h"

/*===========================================================================*
 * External Function Declarations
 *===========================================================================*/
#if (STD_ON == ENABLE_SQT_TEST_STUBS)
extern void Inject_FCRU_Fault(uint8 fault_num);
#endif

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
volatile uint8 FCRU_test       = 0;
uint8 faultnum_test            = 0x0;
volatile uint8 FCRU_Fault_Test = 0;
   #define TEST_RESET 150u
#endif

#if (STD_ON == ENABLE_SQT_TEST_STUBS)
volatile uint8 FCRU_Fault_Test     = 0;
volatile uint8 fcru_fault_num_test = 0xFF;
#endif

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  FCRU_Integration_Test
 *   This function includes stub code to verify interfaces of FCRU Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_FCRU.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
void FCRU_Integration_Test(void)
{
   if (FCRU_test == 1)
   {
      Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason(TEST_RESET);
      FCRU_test = 0;
   }
   else if (FCRU_test == 2)
   {
      Rte_Call_CS_Get_RepetativeReset_Faultnum_Operation(&faultnum_test);
      FCRU_Fault_Test = faultnum_test;
      FCRU_test       = 0;
   }
}
#endif

/******************************************************************************
 * Name:  FCRU_Functionality_Test
 *   This function includes stub code to verify functionality of FCRU Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_FCRU.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/

#if (STD_ON == ENABLE_SQT_TEST_STUBS)
void FCRU_Functionality_Test(void)
{
   if (FCRU_Fault_Test == 1)
   {
      Inject_FCRU_Fault(fcru_fault_num_test);
      fcru_fault_num_test = 0xFF;
      FCRU_Fault_Test     = 0;
   }
}
#endif
