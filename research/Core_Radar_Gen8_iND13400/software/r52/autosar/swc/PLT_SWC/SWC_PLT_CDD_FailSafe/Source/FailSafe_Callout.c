/**************************************************************************
 * Copyright 2019 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        FailSafe \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:fjvnnx  %derived_by: fjvnnx % \n
 * \b Classification:     CONFIDENTIAL \n
 * %date_modified: 23/06/2020 %
 *
 *
 *
 ***************************************************************************
 *
 *  Module Name:  FailSafe_Callout.c
 *
 *  Description:
 *    This file contains the callout functions for FailSafe module
 *
 *
 **************************************************************************/

/**************************************************************************
 * #Include files
 *************************************************************************/
#include "FailSafe_Callout.h"
#include "Rte_SWC_PLT_CDD_FailSafe.h"
#include "SWC_PLT_CDD_FailSafe.h"
/**********************************************************************************************************************\
 *  EXPORTED OBJECT DECLARATIONS
\**********************************************************************************************************************/
/* TODO: fix below compiler*/
/*==========================================================================*/
/**
 * FUNCTION: Fail_Safe_Store_Reset_Reason_Callout
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 * FailSafe_ResetReason_T PLT_Reset_Reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Call out function from platform fail safe module to store the reset reason.
 * Customer specific implementation shall replace the default reference code here.
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/

void Fail_Safe_Store_Reset_Reason_Callout(void)
{
   uint8_t u8_index;

   Dt_FailSafe_ResetReason_T dt_failsafe_store_buffer = {0};

   FailSafe_ResetReason_T *PLT_Reset_Reason = Get_Platform_ResetReason_Info();

   /* Update the NVM block with input from PLT struct to store the reset reason struct*/
   dt_failsafe_store_buffer.reset_reason_crnt_indx = PLT_Reset_Reason->reset_reason_crnt_indx;

   /*Update Reset reason value in buffer*/
   for (u8_index = 0; u8_index < MAX_RESET_REASONS; u8_index++)
   {
      dt_failsafe_store_buffer.reset_reason[u8_index]       = PLT_Reset_Reason->reset_reason_info[u8_index];
      dt_failsafe_store_buffer.wdg_failed_SE_info[u8_index] = PLT_Reset_Reason->wdg_failed_SE_info[u8_index];
   }

   for (u8_index = 0; u8_index < MAX_REG_CHECK_FAILURE; u8_index++)
   {
      dt_failsafe_store_buffer.StaticRegCheckFailureInfo[u8_index] = PLT_Reset_Reason->StaticRegCheckFailureInfo[u8_index];
   }

   dt_failsafe_store_buffer.reset_counter = PLT_Reset_Reason->reset_counter;

   dt_failsafe_store_buffer.last_cycle_reset = PLT_Reset_Reason->last_cycle_reset;

   dt_failsafe_store_buffer.repetitive_reset_counter = PLT_Reset_Reason->repetitive_reset_counter;

   dt_failsafe_store_buffer.mem_exception_reason.ExceptionType = PLT_Reset_Reason->FailSafeExceptionReason.ExceptionType;
   dt_failsafe_store_buffer.mem_exception_reason.ExceptionCausingAddress =
      PLT_Reset_Reason->FailSafeExceptionReason.ExceptionCausingAddress;
   dt_failsafe_store_buffer.mem_exception_reason.ExceptionStatusRegister =
      PLT_Reset_Reason->FailSafeExceptionReason.ExceptionStatusRegister;
   dt_failsafe_store_buffer.mem_exception_reason.IsMemException_Occured =
      PLT_Reset_Reason->FailSafeExceptionReason.IsMemException_Occured;
   dt_failsafe_store_buffer.mem_exception_reason.MemoryExceptionAddress =
      PLT_Reset_Reason->FailSafeExceptionReason.MemoryExceptionAddress;
   dt_failsafe_store_buffer.mem_exception_reason.StackPointer = PLT_Reset_Reason->FailSafeExceptionReason.StackPointer;

   (void)Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(&dt_failsafe_store_buffer);
}

/*==========================================================================*/
/**
 * FUNCTION: Fail_Safe_Check_NVM_Status
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Call out function to check and try NVM write continuously so that system shall perform reset
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Fail_Safe_Check_NVM_Status_Callout(void)
{
   /*Can be enbaled once NVM block for fail safe is implemented*/
   uint8_t u8_immediete_write = CODED_TRUE;
   (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(u8_immediete_write, CDD_FAIL_SAFE);
}
/*==========================================================================*/
/**
 * FUNCTION: FailSafe_Check_RepetitiveResetCount
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 * FailSafe_ResetReason_T PLT_Reset_Reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Repetitive reset is evaluated and communicate to mode manager
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void FailSafe_Check_RepetitiveResetCount(void)
{
   FailSafe_ResetReason_T *PLT_Reset_Reason = Get_Platform_ResetReason_Info();

   if (PLT_Reset_Reason->last_cycle_reset == (uint8_t)CODED_TRUE)
   {
      if (PLT_Reset_Reason->repetitive_reset_counter >= REPETITIVE_RESET_CNTR_THRSHLD)
      {
         /*Write RTE port to update the fault status to modemanager*/
         Rte_Write_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status((uint8_t)CODED_TRUE);
      }
      else
      {
         /*Do nothing*/
      }
   }
   else
   {
      /*Do nothing*/
   }
}
/*==========================================================================*/
/**
 * FUNCTION: Fail_Safe_Read_Reset_Reason_Callout
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 * FailSafe_ResetReason_T PLT_Reset_Reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Call out function to read the reset reason from NVM or no init ram.
 * This call out will be called by platform to take action based on the last cycle reset reason
 * Customer specific implementation shall replace the default reference code here.
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Fail_Safe_Read_Reset_Reason_Callout(void)
{
   uint8_t u8_index;

   Dt_FailSafe_ResetReason_T dt_failsafe_read_buffer;

   FailSafe_ResetReason_T *PLT_Reset_Reason = Get_Platform_ResetReason_Info();

   (void)Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(&dt_failsafe_read_buffer);

   PLT_Reset_Reason->reset_reason_crnt_indx = dt_failsafe_read_buffer.reset_reason_crnt_indx;

   for (u8_index = 0; u8_index < MAX_RESET_REASONS; u8_index++)
   {
      PLT_Reset_Reason->reset_reason_info[u8_index]  = dt_failsafe_read_buffer.reset_reason[u8_index];
      PLT_Reset_Reason->wdg_failed_SE_info[u8_index] = dt_failsafe_read_buffer.wdg_failed_SE_info[u8_index];
   }

   for (u8_index = 0; u8_index < MAX_REG_CHECK_FAILURE; u8_index++)
   {
      PLT_Reset_Reason->StaticRegCheckFailureInfo[u8_index] = dt_failsafe_read_buffer.StaticRegCheckFailureInfo[u8_index];
   }

   PLT_Reset_Reason->reset_counter = dt_failsafe_read_buffer.reset_counter;

   PLT_Reset_Reason->last_cycle_reset = dt_failsafe_read_buffer.last_cycle_reset;

   PLT_Reset_Reason->repetitive_reset_counter              = dt_failsafe_read_buffer.repetitive_reset_counter;
   PLT_Reset_Reason->FailSafeExceptionReason.ExceptionType = dt_failsafe_read_buffer.mem_exception_reason.ExceptionType;
   PLT_Reset_Reason->FailSafeExceptionReason.ExceptionCausingAddress =
      dt_failsafe_read_buffer.mem_exception_reason.ExceptionCausingAddress;
   PLT_Reset_Reason->FailSafeExceptionReason.ExceptionStatusRegister =
      dt_failsafe_read_buffer.mem_exception_reason.ExceptionStatusRegister;
   PLT_Reset_Reason->FailSafeExceptionReason.IsMemException_Occured =
      dt_failsafe_read_buffer.mem_exception_reason.IsMemException_Occured;
   PLT_Reset_Reason->FailSafeExceptionReason.MemoryExceptionAddress =
      dt_failsafe_read_buffer.mem_exception_reason.MemoryExceptionAddress;
   PLT_Reset_Reason->FailSafeExceptionReason.StackPointer = dt_failsafe_read_buffer.mem_exception_reason.StackPointer;
}
/*==========================================================================*/
/**
 * FUNCTION: Fail_Safe_Clear_Last_Cycle_Callout
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 * None
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Call out function to clear the last cycle reset status in NVM.
 * This function is called out by platform on taking action for last cycle reset.
 * Customer specific implementation shall replace the default reference code here.
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Fail_Safe_Clear_Last_Cycle_Callout(void)
{
   Fail_Safe_Store_Reset_Reason_Callout();
   uint8_t u8_immediete_write = CODED_FALSE;
   (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(u8_immediete_write, CDD_FAIL_SAFE);
}

/**
 * FUNCTION: FailSafe_Verify_ResetReason
 *===========================================================================
 * RETURN VALUE:
 * uint8_t
 *
 * PARAMETERS:
 * uint8_t *FaultChannel
 *
 *
 * EXTERNAL REFERENCES:
 * None
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *.
 * This function is called to verify the last two reset reason by platform on taking action for last cycle reset.
 * Customer specific implementation shall replace the default reference code here.
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/

uint8_t FailSafe_Verify_ResetReason(uint8_t *FaultChannel)
{
   uint8_t reset_status = (uint8_t)CODED_FALSE;
   uint8_t current_reset_reason;

   FailSafe_ResetReason_T *PLT_Reset_Reason = Get_Platform_ResetReason_Info();

   /* check if last cycle reset occurred */
   if (PLT_Reset_Reason->last_cycle_reset == (uint8_t)CODED_TRUE)
   {
      /* check if repetitive reset counter exceeds threshold */
      if (PLT_Reset_Reason->repetitive_reset_counter >= REPETITIVE_RESET_CNTR_THRSHLD)
      {
         current_reset_reason = PLT_Reset_Reason->reset_reason_info[PLT_Reset_Reason->reset_reason_crnt_indx - 1];
         /* check if reset is because of an FCRU fault */
         if ((current_reset_reason >= MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD) &&
             (current_reset_reason <= MCU_FCRU_FAULT_63_TOP_RESET_FAULT))
         {
            /* if Reset is because of an FCRU fault update FaultChannel and return with CODED_TRUE to indicate FCRU Reset */
            *FaultChannel = current_reset_reason;
            reset_status  = (uint8_t)CODED_TRUE;
         }
         else if ((current_reset_reason != DEFAULT_RESET_REASON))
         {
            /* if Reset is because of a non FCRU fault update FaultChannel and return with CODED_FALSE to indicate Non FCRU Reset
             */
            *FaultChannel = current_reset_reason;
            reset_status  = (uint8_t)CODED_FALSE;
         }
         else
         {
            /*Do Nothing*/
         }
      }
      else
      {
         /*Do Nothing*/
      }
   }
   else
   {
      /*Do Nothing*/
   }

   return reset_status;
}

/**
 * FUNCTION: FailSafe_Repetative_ResetReason
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * uint8_t *ResetReason
 *
 *
 * EXTERNAL REFERENCES:
 * None
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *.
 * This function is called to Read the Repetative Reset Reason
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void FailSafe_Repetative_ResetReason(uint8_t *ResetReason)
{
   Dt_FailSafe_ResetReason_T dt_failsafe_read_buffer;

   (void)Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(&dt_failsafe_read_buffer);

   if (dt_failsafe_read_buffer.last_cycle_reset == (uint8_t)CODED_TRUE)
   {
      if (dt_failsafe_read_buffer.repetitive_reset_counter >= REPETITIVE_RESET_CNTR_THRSHLD)
      {
         *ResetReason = dt_failsafe_read_buffer.reset_reason[dt_failsafe_read_buffer.reset_reason_crnt_indx];
      }
      else
      {
         /* Do nothing */
      }
   }
   else
   {
      /* Do nothing */
   }
}
#if (TRUE == XCP_FAULT_INJECTION)
/**
 * FUNCTION: FailSafe_Reset_PLT_Reset_Reason
 *===========================================================================
 * RETURN VALUE:
 * Void
 *
 * PARAMETERS:
 * None
 *
 *
 * EXTERNAL REFERENCES:
 * None
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *.
 * This function is called to clear the PLT Reset Reason
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void FailSafe_Reset_PLT_Reset_Reason(void)
{
   uint8 u8_index                           = 0;
   FailSafe_ResetReason_T *PLT_Reset_Reason = Get_Platform_ResetReason_Info();

   PLT_Reset_Reason->reset_reason_crnt_indx = 0;

   for (u8_index = 0; u8_index < MAX_RESET_REASONS; u8_index++)
   {
      PLT_Reset_Reason->reset_reason_info[u8_index]  = 0;
      PLT_Reset_Reason->wdg_failed_SE_info[u8_index] = 0;
   }
   PLT_Reset_Reason->reset_counter = 0;

   PLT_Reset_Reason->last_cycle_reset = CODED_FALSE;

   PLT_Reset_Reason->repetitive_reset_counter = 0;
}
#endif
/************************************************************************************************************************************
 *  Revision History
 *
 *   Date        SCR			Name             Description
 *   ----        ----		  ----------- ---------------------------------------------------------------------------------------
 * 23-JUN-2020   CPT-341		Prince     	   Updated the module SWC_PLT_Appl_Validation_Diag according to APTIV C CODING GUIDELINES
 * . 13-Sep-2022	EEG-1267    Niveditha	   Created callout functions for customer project to interface with reset reason
 * implementation 01-Mar-2023	EEG-1179	Chirag		   FailSafe_Repetative_ResetReason added to read repetative reset reason
 * 08-Mar-2023	EEG-1694	Chirag		   Fail_Safe_Clear_Last_Cycle_Callout Function updated to clear the last reset value on reset
 * not triggred by software 26-Mar-2023   EEG-1958    Pragathi       Modified the FailSafe_Verify_ResetReason that was referring to
 * improper variable
 * 31-12-24   EEG-5215        Rajasekar T      Modified Based on C coding Guidelines
 * *************************************************************************************************************************************************/
