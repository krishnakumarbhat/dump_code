/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_FailSafe_Test.c
 *
 * @todo This file contains test code for the SWC_PLT_CDD_FailSafe component, including integration and functionality tests for
 *fail-safe mechanisms.
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

#include "Platform_Types.h"
#include "Rte_SWC_PLT_CDD_FailSafe.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "chandra_sfrs_base.h"
#include "serdes_sfrs.h"
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

#if (ENABLE_SIT_TEST_STUBS == TRUE)
volatile uint8_t test_mcu_repetitve_fault   = 0;
volatile uint8_t test_reset                 = 46;
volatile uint8_t test_failsafe_reset_reason = 0;
#endif
#if (TRUE == ENABLE_SQT_TEST_STUBS)
volatile uint8_t Failsafe_test_flag                         = 0;
volatile uint8_t test_reason                                = 45;
volatile uint8_t Failsafe_SM096_test                        = 0x55;
static volatile SERDES_SFRS_t *const FailSafe_PtrSerdesAddr = (volatile SERDES_SFRS_t *)SERDES_base;
#endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  FailSafe_Integration_Test
 *   This function includes stub code to verify interfaces of FailSafe Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_FailSafe.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void FailSafe_Integration_Test(void)
{
   /*Stub Code to test the interface of MCU Repetetive Reset fault */
   if (test_mcu_repetitve_fault == 1)
   {
      Rte_Write_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(CODED_TRUE);
   }
   /*Stub Code to test the Failsafe interface of trigger write to nvm and retain data back from nvm */
   if (test_failsafe_reset_reason == 1)
   {
      Log_ResetReason(test_reset);
   }
}
#endif
/******************************************************************************
 * Name:  Failsafe_SW_Quality_test
 *   This function includes stub code to verify SQT of FailSafe Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_FailSafe.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void Failsafe_SW_Quality_test(void)
{
   /*Trigger reset through failsafe and store & retrieve in NvM and Repetitive reset check */
   if (Failsafe_test_flag == 1)
   {
      Log_ResetReason(test_reason);
   }

   if (Failsafe_SM096_test == 0xAA)
   {
      FailSafe_PtrSerdesAddr->TXPLL_DIVIDER1_0.f.TXPLL_FBDIV = 78;
   }
}
#endif
