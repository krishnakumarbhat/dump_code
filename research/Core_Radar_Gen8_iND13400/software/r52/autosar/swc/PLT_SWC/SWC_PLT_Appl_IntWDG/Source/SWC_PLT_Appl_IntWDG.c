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
 *             File:  SWC_PLT_Appl_IntWDG.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_IntWDG
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_IntWDG>
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
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 1267, +10000.
 *
 * WdgM_GlobalStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * WdgM_LocalStatusType
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
 * WdgM_SupervisedEntityIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 * ActivateSupervisionEntity of Port Interface WdgM_General
 *   Activates the supervision of the given supervised entity.
 *
 * DeactivateSupervisionEntity of Port Interface WdgM_General
 *   Deactivates the supervision of the given supervised entity.
 *
 * GetFirstExpiredSEID of Port Interface WdgM_General
 *   Returns the id of that supervised entity which first reached the status WDGM_LOCAL_STATUS_EXPIRED.
 *
 * GetGlobalStatus of Port Interface WdgM_General
 *   Returns the global supervision status of the Watchdog Manager.
 *
 * GetLocalStatus of Port Interface WdgM_General
 *   Returns the supervision status of a supervised entity.
 *
 * GetMode of Port Interface WdgM_General
 *   Returns the current mode of the Watchdog Manager.
 *
 * PerformReset of Port Interface WdgM_General
 *   Instructs the Watchdog Manager to cause a watchdog reset.
 *
 * SetMode of Port Interface WdgM_General
 *   Requests a new trigger mode
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_IntWDG.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_PLT_Appl_IntWDG.h"

volatile uint8 XCP_Intwdg_Fault = CODED_FALSE;
volatile uint8 Wdg_Mode_Change  = CODED_TRUE;
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
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * WdgM_ModeType: Integer in interval [0...255]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_Wdg_Type: Enumeration of integer in interval [0...255] with enumerators
 *   INT_WDG (0U)
 *   EXT_WDG (1U)
 *   INT_EXT_WDG (2U)
 * WdgM_GlobalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_GLOBAL_STATUS_OK (0U)
 *   WDGM_GLOBAL_STATUS_FAILED (1U)
 *   WDGM_GLOBAL_STATUS_EXPIRED (2U)
 *   WDGM_GLOBAL_STATUS_STOPPED (3U)
 *   WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_LOCAL_STATUS_OK (0U)
 *   WDGM_LOCAL_STATUS_FAILED (1U)
 *   WDGM_LOCAL_STATUS_EXPIRED (2U)
 *   WDGM_LOCAL_STATUS_DEACTIVATED (4U)
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_IntWDG_START_SEC_CODE
#include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Disable_Wdg_Supervised_Entites_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_Disable_Wdg_Supervised_Entites>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Disable_Wdg_Supervised_Entites_Operation(uint8 disable_SE_Flag)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Disable_Wdg_Supervised_Entites_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE)
CS_Disable_Wdg_Supervised_Entites_Operation(uint8 disable_SE_Flag) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Disable_Wdg_Supervised_Entites_Operation
    *********************************************************************************************************************/

   if (CODED_TRUE == disable_SE_Flag)
   {
      /* Disable Supervision Entities */
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Alive_Program_Flow_Monitoring);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control);
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task);
   }
   else if (CODED_FALSE == disable_SE_Flag)
   {
#if (FALSE == DISABLE_INT_WDG)
      /* Updating WdgM & Wdg Mode to FAST_MODE */
      if ((CODED_TRUE == Wdg_Mode_Change) && (ENABLE_WDG_SMC == k_internal_wdg_disable_smc))
      {
         Rte_Call_CS_WdgM_General_SetMode(WDGIF_FAST_MODE, 0);
         Wdg_Mode_Change = CODED_FALSE;
      }
      else
      {
         /* do nothing */
      }
#endif
      /* Enable Supervision Entities */
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg);
      // /* Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Alive_Program_Flow_Monitoring); */ /* Disabling PFM */
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task);
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task);
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication);
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control);
      // Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(
      //    (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task);
   }
   else
   {
      /* Do Nothing*/
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_IPC_Task_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE)
RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task
    *********************************************************************************************************************/
   Appl_Task_Monitoring(WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 25ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Communication_CheckpointReached(WdgM_CheckpointIdType
 *CPID) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE)
RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication
    *********************************************************************************************************************/

   Appl_Task_Monitoring(WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Radar_Control_CheckpointReached(WdgM_CheckpointIdType
 *CPID) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE)
RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control
    *********************************************************************************************************************/
   Appl_Task_Monitoring(WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_INTERNAL_WDG_BSW_Task
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 25ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_BSW_Task_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_INTERNAL_WDG_BSW_Task_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_BSW_Task(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_INTERNAL_WDG_BSW_Task
    *********************************************************************************************************************/
   Appl_Task_Monitoring(WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 25ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_PLT_Appl_Task_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE)
RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task
    *********************************************************************************************************************/
   Appl_Task_Monitoring(WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_Main_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_Main_50ms
    *********************************************************************************************************************/
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
   Disable_Internal_Wdg_Sit();
   Deactivate_SE_On_Req();
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_WDG_Main_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Wdg_Disable_Read(Dt_Wdg_Type Wdg_Type)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType *SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetGlobalStatus(WdgM_GlobalStatusType *Status)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType *Status)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetMode(WdgM_ModeType *Mode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_PerformReset(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_SetMode(WdgM_ModeType Mode, uint16 CallerID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_WDG_Main_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_Main_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_WDG_Main_5ms
    *********************************************************************************************************************/

   /* Calling Checkpoint Reach for SE_Internal_Wdg */
#if (STD_ON == ENABLE_SQT_TEST_STUBS)
   Perform_SWT_SQT_Test();
#else
   #if (TRUE == XCP_FAULT_INJECTION)
   uint8_t intwdg_service_xcp = CODED_FALSE;
   Rte_Read_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(&intwdg_service_xcp);
   XCP_Intwdg_Fault = intwdg_service_xcp;
   #endif
   if (CODED_TRUE == XCP_Intwdg_Fault)
   {
      /*Stop servicing the Internal Wdg*/
   }
   else
      Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Wdg_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_General_ActivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType *SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetGlobalStatus(WdgM_GlobalStatusType *Status)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType *Status)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetMode(WdgM_ModeType *Mode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_PerformReset(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_WdgM_General_SetMode(WdgM_ModeType Mode, uint16 CallerID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Wdg_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_Wdg_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Wdg_Init
    *********************************************************************************************************************/

   WdgM_Init(&WdgMConfig_Mode0_core0);
#if (TRUE == DISABLE_INT_WDG)
   Rte_Call_CS_WdgM_General_SetMode(WDGIF_OFF_MODE, 0);
#endif
   if (DISABLE_WDG_SMC == k_internal_wdg_disable_smc)
   {
      Rte_Call_CS_WdgM_General_SetMode(WDGIF_OFF_MODE, 0);
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_IntWDG_STOP_SEC_CODE
#include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
 *. Name: Appl_Task_Monitoring
 *. This function abstracts the watchdog checkpoint triggering mechanism for various internal task
 *.
 *.
 *. Parameters: se_id_info
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Appl_Task_Monitoring(uint16 se_id_info)
{
   uint16 Task_SE_Id = se_id_info;

#if (STD_ON == ENABLE_SQT_TEST_STUBS)
   Task_SE_Id = Test_WDG_Task_Monitoring(se_id_info);
#endif
   switch (Task_SE_Id)
   {
      case WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task:
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_IPC_Task_CheckpointReached(
            (WdgM_CheckpointIdType)WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_IPC_Task);
         break;
      case WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication:
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Communication_CheckpointReached(
            (WdgM_CheckpointIdType)WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Communication);
         break;
      case WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control:
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Radar_Control_CheckpointReached(
            (WdgM_CheckpointIdType)WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Radar_Control);
         break;
      case WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task:
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_BSW_Task_CheckpointReached(
            (WdgM_CheckpointIdType)WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_BSW_Task);
         break;
      case WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task:
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_PLT_Appl_Task_CheckpointReached(
            (WdgM_CheckpointIdType)WdgMConf_WdgMCheckpoint_SE_Internal_Wdg_PLT_Appl_Task);
         break;
      default:
         // Optional: log error or trigger fallback
         break;
   }
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:CS_IntWdg_Fault_Injection_Read_doc)  ******************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:CS_IntWdg_Fault_Injection_Read)  *****************/

/***  End of saved code  ************************************************************************************/
#endif

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
