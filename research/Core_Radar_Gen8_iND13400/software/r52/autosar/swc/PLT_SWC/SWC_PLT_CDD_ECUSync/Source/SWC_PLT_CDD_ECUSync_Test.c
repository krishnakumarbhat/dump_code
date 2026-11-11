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

#include "Rte_SWC_PLT_CDD_ECUSync.h"

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint8_t Test_get_platform_time_us         = 0;
volatile uint8_t Test_get_elapsed_platform_time_us = 0;
volatile uint8_t Testcase                          = 0u;
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
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void PlatformTime_ustime_Interface_Test(void)
{
   #if (TRUE == ENABLE_SIT_TEST_STUBS)
   uint64 test_us_time = 0ULL;
   if (TRUE == Test_get_platform_time_us)
   {
      Testcase |= 1u;
   }
   if (TRUE == Test_get_elapsed_platform_time_us)
   {
      Testcase |= 2u;
   }
   switch (Testcase)
   {
      case 1u: /* Get platform time (us) */
         test_us_time = 50ULL;
         (void)Rte_Call_CS_Get_PlatfromTime_us_read(&test_us_time);
         break;
      case 2u: /* Get elapsed platform time (us) */
      {
         uint64_t test_start_ustime = 25ULL;
         uint32_t test_end_ustime   = 30u;
         (void)Rte_Call_CS_Get_Platform_Elapsed_ustime_read(&test_end_ustime, test_start_ustime);
      }
      break;
      default:
         break;
   }
   #endif
}
#endif
