/**
 * @file main.c
 * @brief Main function to start the main_application state machine control loop.
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2024 Aptiv, All Rights Reserved.
 * @copyright Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 */

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "exceptions.h"
#include "main_application.h"
#include "mpu.h"
#include <stdint.h>
#ifndef UNIT_TEST
   #include "dss_ecc_parity.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif

   /*===========================================================================*
    * Local Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Local Preprocessor #define MACROS
    *===========================================================================*/

   /*===========================================================================*
    * Local Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Object Definitions
    *===========================================================================*/

   /*===========================================================================*
    * Local Object Definitions
    *===========================================================================*/

   /*===========================================================================*
    * Local Function Prototypes
    *===========================================================================*/

   /*===========================================================================*
    * Local Inline Function Definitions and Function-Like Macros
    *===========================================================================*/

   /*===========================================================================*
    * Function Definitions
    *===========================================================================*/
   /**
    *  @b Description
    *  @n
    *    BBE application entry point
    *
    * @return None
    */
   int __attribute__((section(".sram0.text"))) main(void)
   {
      /** Enable DSP ram and cache ECC - supports SM - 19 to 22 **/
      xtos_memep_initrams();
      xtos_memep_enable(0);
      /** Register Exception Interrupt Handler **/
      Register_Exception_Handlers();

      /** Update the MPU and read it back for debug purposes. **/
      if (!Mpu_Initialize())
      {
         /* Stop if mpu initialization fails*/
         while (1)
            ;
      }

      Read_Mpu_Configuration();

      /* Run_State_Machine should never return. */
      Main_Application();

      return 0;
   }

#ifdef __cplusplus
}
#endif
