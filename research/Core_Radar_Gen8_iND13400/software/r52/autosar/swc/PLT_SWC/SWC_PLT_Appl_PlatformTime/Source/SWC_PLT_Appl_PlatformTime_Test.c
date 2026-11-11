/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_PlatformTime_Test.c
 *
 * @todo Add a one line description of the implementation.
 *
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

#include "platformtime.h"

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if (TRUE == ENABLE_SQT_TEST_STUBS)
uint64_t Test_Plt_Timer_Start_Ustime;
uint32_t Test_Plt_Timer_Start_mstime;
#endif
#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint8_t platformtime_init_sit_test = 0u;
#endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  PlatformTime_Functionality_Test
 *   This function includes stub code to verify functionality of Mode Manager Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Mode_Manager.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void PlatformTime_Functionality_Test(void)
{
   /*Stub code for checking milliseconds and microseconds using platform timer  */

   Get_Platform_ustime(&Test_Plt_Timer_Start_Ustime);
   Get_Platform_mstime(&Test_Plt_Timer_Start_mstime);
}
#endif

/******************************************************************************
 * Name:  PlatformTime_Integration_Test
 *   This function applies SIT overrides for platform time initialization
 *   status reporting.
 *
 * Shared Variables: platformtime_init_sit_test
 *
 * Parameters: volatile uint8 *   - Pointer to the platform time status output
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void PlatformTime_Integration_Test(volatile uint8 *tr_platformtime)
{
   if (platformtime_init_sit_test == 1U)
   {
      *tr_platformtime = CODED_TRUE;
   }
   else if (platformtime_init_sit_test == 2U)
   {
      *tr_platformtime = CODED_FALSE;
   }
}
#endif
