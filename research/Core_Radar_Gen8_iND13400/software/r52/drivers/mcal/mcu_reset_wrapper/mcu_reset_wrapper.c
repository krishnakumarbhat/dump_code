/*===========================================================================*\
 * FILE: mcu_reset_wrapper.c
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains MCU Reset Wrapper functions to perform MCU reset and other operations related to MCU.
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

#include "mcu_reset_wrapper.h"
#include "Mcu.h"
#include "Os.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "boot_interface.h"
#include "chandra_sfrs_base.h"
#include "mipi_wrapper.h"
#include "mmic_interface.h"

/*****************************************************************************
 *. Name: Mcu_Reset
 *.    This function will act as a wrapper function of Mcu_PerformReset.
 *.    This is essential to perform some pre-reset activities before calling the Mcu_PerformReset
 *.
 *. Parameters: resetmode - The mode of reset to be performed.
 *.
 *. Return Value:None
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *.
 ******************************************************************************/
void Mcu_Reset(Mcu_reset_T resetmode)
{
   if (RESET_SW_INTENTIONAL == resetmode)
   {
      SuspendAllInterrupts();
   }

   Boot_Shared_Data.reset_type = resetmode;

   if (Get_RDI_Log_Board_Connected())
   {
      (void)Assert_Reset_Mipi(); /* Reset MIPI if Get_RDI_Log_Board_Connected */
   }
   /* TODO: Reset MARS as well    MMIC_Reset_MARS(); */

   Mcu_PerformReset();
}
