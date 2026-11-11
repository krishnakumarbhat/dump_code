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
 *             File:  SWC_PLT_CDD_ExternalWdg.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_ExternalWdg
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_ExternalWdg>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_ExternalWdg.h"
#include "dd_pmic.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define TASK_DELAY_30_MS 6U /* 6 * 5ms = 30ms */

#if (TRUE == XCP_FAULT_INJECTION)
   #define IC_INJECT_FAULT          (0x00U)
   #define IC_REMOVE_FAULT          (0x01U)
   #define FT_PMIC_MCU_COMM_FAILURE (0x04U)
   #define FT_EXT_WDT_FAILURE       (0x05U)
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
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/
volatile uint8 ExtWatchdog_Task_Delay   = 0U;
volatile uint8 External_Watchdog_Status = CODED_FALSE;
#if ((STD_ON == ENABLE_SQT_TEST_STUBS) || (STD_ON == ENABLE_SIT_TEST_STUBS) || (STD_ON == XCP_FAULT_INJECTION))
volatile uint8_t test_flag_externalwdg_fault = 0U;
volatile uint8 IntWDG_Fail_Status            = CODED_FALSE;
#endif
#define SWC_PLT_CDD_ExternalWdg_START_SEC_CODE
#include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_External_Watchdog_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_External_Watchdog_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_External_Watchdog_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_External_Watchdog_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE)
CS_External_Watchdog_Fault_Injection_Read(uint8 Injection_control,
                                          uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_External_Watchdog_Fault_Injection_Read
    *********************************************************************************************************************/
#if (STD_ON == XCP_FAULT_INJECTION)
   if (FT_PMIC_MCU_COMM_FAILURE == Failure_Type)
   {
      Pmic_Fault_Injection_XCP(Injection_control);
   }
   else if (FT_EXT_WDT_FAILURE == Failure_Type)
   {
      if (IC_INJECT_FAULT == Injection_control)
      {
         test_flag_externalwdg_fault = CODED_TRUE;
      }
      else if (IC_REMOVE_FAULT == Injection_control)
      {
         test_flag_externalwdg_fault = CODED_FALSE;
      }
      else
      {
         /* */
      }
   }
   else
   {
   }

#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Pp_ExtWdg_Disable_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Pp_ExtWdg_Disable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Pp_ExtWdg_Disable_Operation(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Pp_ExtWdg_Disable_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE)
CS_Pp_ExtWdg_Disable_Operation(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Pp_ExtWdg_Disable_Operation
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Pp_ExtWdg_Enable_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Pp_ExtWdg_Enable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Pp_ExtWdg_Enable_Operation(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Pp_ExtWdg_Enable_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) CS_Pp_ExtWdg_Enable_Operation(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Pp_ExtWdg_Enable_Operation
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CDD_Ext_Wdg_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_externalwatchdogstatus_de_externalwatchdogstatus(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CDD_Ext_Wdg_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_CDD_Ext_Wdg_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_CDD_Ext_Wdg_50ms
    *********************************************************************************************************************/
   /*Fault injection code for external watchdog fault*/
   External_Watchdog_Status = Pmic_Check_Wdg_Dis_Status();
#if ((STD_ON == ENABLE_SQT_TEST_STUBS) || (STD_ON == ENABLE_SIT_TEST_STUBS) || (STD_ON == XCP_FAULT_INJECTION))
   if (CODED_TRUE == test_flag_externalwdg_fault)
   {
      External_Watchdog_Status = CODED_TRUE;
   }
   else if (CODED_FALSE == test_flag_externalwdg_fault)
   {
      External_Watchdog_Status = CODED_FALSE;
   }
   else
   {
      /*Do Nothing*/
   }
   Rte_Read_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(&IntWDG_Fail_Status);

#endif
   Rte_Write_Pp_externalwatchdogstatus_de_externalwatchdogstatus(External_Watchdog_Status);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CDD_Ext_Wdg_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CDD_Ext_Wdg_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_CDD_Ext_Wdg_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_CDD_Ext_Wdg_5ms
    *********************************************************************************************************************/
   ExtWatchdog_Task_Delay++;
   if (ExtWatchdog_Task_Delay >= TASK_DELAY_30_MS)
   {
      /*Watchdog need to be serviced on priority. */
      ExtWatchdog_Task_Delay = 0U;
      Pmic_Watchdog_Service();
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_ExternalWdg_Init
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
 *   Std_ReturnType Rte_Write_Pp_external_watchdog_init_status_de_wdginit_status(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_ExternalWdg_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_PLT_ExternalWdg_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_ExternalWdg_Init
 *********************************************************************************************************************/
#if (PMIC_SPREAD_SPECTRUM_ENABLE == FEATURE_ENABLED)
   (void)Pmic_Spread_Spectrum_Enable();
#else
   (void)Pmic_Spread_Spectrum_Disable();
#endif
#if (PMIC_CLK_SYNC_ENABLE == FEATURE_ENABLED)
   (void)Pmic_Clk_Sync_Enable();
#endif /*end of PMIC_CLK_SYNC_ENABLE*/
   Pmic_Watchdog_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_ExternalWdg_STOP_SEC_CODE
#include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
