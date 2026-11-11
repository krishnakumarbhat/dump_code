/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_CDD_WdgHandler.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_WdgHandler
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_WdgHandler>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dt_Wdg_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * WdgM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *
 * Operation Prototypes:
 * =====================
 * SetMode of Port Interface WdgM_General
 *   Requests a new trigger mode
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_WdgHandler.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_PLT_CDD_FailSafe.h"
#include "Wdg_182_iND13400.h"
#include "appl_wdg_handler.h"
#include "reuse.h"

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
volatile uint8_t test_Injection_control_Wdg_Handler = 0U;
volatile uint8_t test_Failure_Type_Wdg_Handler      = 0U;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dt_Wdg_Type: Integer in interval [0...255]
 * WdgM_ModeType: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_WdgHandler_START_SEC_CODE
#include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_WdgHandler_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_WdgHandler_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_WdgHandler_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_WdgHandler_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE)
CS_WdgHandler_Fault_Injection_Read(uint8 Injection_control,
                                   uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_WdgHandler_Fault_Injection_Read
    *********************************************************************************************************************/

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
   test_Injection_control_Wdg_Handler = Injection_control;
   test_Failure_Type_Wdg_Handler      = Failure_Type;
#endif
#if (TRUE == XCP_FAULT_INJECTION)
   if (FT_SWT_FAILURE == Failure_Type)
   {
      if (IC_INTERNAL_SWT_FAILURE == Injection_control)
      {
         /* Internal SWT Failure injection */
         Rte_Write_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(CODED_TRUE);
      }
      else if (IC_EXTERNAL_SWT_FAILURE == Injection_control)
      {
         /* External SWT Failure injection */
         Rte_Write_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(CODED_TRUE);
      }
      else if (IC_INT_EXT_SWT_FAILURE == Injection_control)
      {
         /* Internal & External SWT Failure injection */
         Rte_Write_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(CODED_TRUE);
         Rte_Write_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(CODED_TRUE);
      }
      else if (IC_REMOVE_SWT_FAILURE == Injection_control)
      {
         /* Remove SWT Failures */
         Rte_Write_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(CODED_FALSE);
         Rte_Write_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(CODED_FALSE);
      }
      else
      {
         /* */
      }
   }
   else
   {
      /* */
   }
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Wdg_Disable
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Wdg_Disable>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_General_SetMode(WdgM_ModeType Mode, uint16 CallerID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Wdg_Disable(Dt_Wdg_Type Wdg_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Wdg_Disable_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) CS_Wdg_Disable(Dt_Wdg_Type Wdg_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Wdg_Disable
    *********************************************************************************************************************/
   Appl_Wdg_Disable(Wdg_Type);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WdgHandler_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WdgHandler_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) RE_PLT_WdgHandler_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WdgHandler_Init
    *********************************************************************************************************************/
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
   Wdghandler_Integration_Test();
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/*===========================================================================*\
 * FUNCTION: Internal_Wdg_Instance_SetTriggerCondition
 *===========================================================================
 * RETURN VALUE:None
 *
 *
 * PARAMETERS: u16Timeout
 *
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * This function used to set the trigger condition for internal watchdog
 *
\*===========================================================================*/

FUNC(void, WDG_CODE) Internal_Wdg_Instance_SetTriggerCondition(uint16 u16Timeout)
{
   Appl_Internal_Wdg_Instance_SetTriggerCondition(u16Timeout);
}

/*===========================================================================*\
 * FUNCTION: Internal_Wdg_Instance_SetMode
 *===========================================================================
 * RETURN VALUE:Std_ReturnType
 *
 *
 * PARAMETERS:
 *    Mode
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * This function used to set the mode for internal watchdog
 *
\*===========================================================================*/

FUNC(Std_ReturnType, WDG_CODE) Internal_Wdg_Instance_SetMode(WdgIf_ModeType Mode)
{
   return Appl_Internal_Wdg_Instance_SetMode(Mode);
}

void WdgTriggerLocation_WdgGeneral(void)
{
   FailSafe_Log_ResetReason(MCU_FAILSAFE_WDG_RESET_REASON);
}

#define SWC_PLT_CDD_WdgHandler_STOP_SEC_CODE
#include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
