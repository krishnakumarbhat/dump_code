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
 *             File:  SWC_PLT_CDD_FailSafe.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_FailSafe
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_FailSafe>
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
 * Dt_Fault_name_FHTI
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
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
 * Component Types:
 * ================
 * SWC_PLT_CDD_FailSafe
 *   SWC for fail safe concept implementation.
 *
 *
 * Operation Prototypes:
 * =====================
 * GetFirstExpiredSEID of Port Interface WdgM_General
 *   Returns the id of that supervised entity which first reached the status WDGM_LOCAL_STATUS_EXPIRED.
 *
 *
 * Runnable Entities:
 * ==================
 * RE_PLT_FailSafe_Init
 *   Init runnable for Failsafe module.
 *
 * RE_PLT_FailSafe_Main_50ms
 *   50 ms runnable for fail safe module.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_FailSafe.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Can_GeneralTypes.h"
#include "EthTrcv_GeneralTypes.h"
#include "FS_IntHndlr.h"
#include "FailSafe_Callout.h"
#include "Os.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "boot_interface.h"
#include "mcu_reset_wrapper.h"
#include "retention_ram_data.h"
#ifndef UNIT_TEST
   #include "Can.h"
#else
extern Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);
#endif
#include "EthTrcv_30_Rtl9010.h"

static FailSafe_ResetReason_T PLT_Reset_Reason;
#ifdef TEST_NOINIT
static volatile uint8 FailSafe_Test_Trigger_Reset = 0;
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
 * Rte_DT_Dt_StaticRegCheckFailureInfo_0: Integer in interval [0...255]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_ECU_ResetReasonType: Enumeration of integer in interval [0...65535] with enumerators
 * Dt_Fault_name_FHTI: Enumeration of integer in interval [0...255] with enumerators
 *   SMC_CHECKSUM_FAULT (0U)
 *   USC_VALIDATION_FAULT (1U)
 *   MMIC_B_ID_FAULT (2U)
 *   MMIC_TEMPERATURE_HIGH_FAULT (3U)
 *   MMIC_TEMPERATURE_LOW_FAULT (4U)
 *   MMIC_A_SAFESTART (5U)
 *   MMIC_B_SAFESTART (6U)
 *   MMIC_A_SAFETY_INTEGRITY_RFBIST (7U)
 *   MMIC_A_SENSOR_FAULT (8U)
 *   MMIC_TEMPERATURE_CONSISTANCY_FAILURE (9U)
 *   PLATFORM_TIME_FAULT (10U)
 *   TX_BALL_BREAK_FAULT (11U)
 *   BLOCKAGE_ALGO_ERROR_FAULT (12U)
 *   MCU_STARTUP_FAULT (13U)
 *   MCU_REPETATIVE_RESET_FAULT (14U)
 *   A53_TO_CM7_IPC_FAULT (15U)
 *   CM7_TO_DSP_IPC_FAULT (16U)
 *   EDMA_FAULT_CALIBRATION (17U)
 *   DSP_TO_A53_IPC_FAULT (18U)
 *   DSP_TO_CM7_IPC_FAULT (19U)
 *   MAX_FAULT_NUMBER (20U)
 * Dt_Nv_Caller_ID: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID (0U)
 *   CDD_FAIL_SAFE (1U)
 *   CDD_ESM (2U)
 *   APPL_DIAG (3U)
 *   CDD_ALIGNMENT (4U)
 *   DYNAMIC_ALIGNMENT (5U)
 *   RFE_R1R2_FAULT (6U)
 *   CDD_FAILSAFE_ECC (7U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Dt_StaticRegCheckFailureInfo: Array with 35 element(s) of type Rte_DT_Dt_StaticRegCheckFailureInfo_0
 * Rte_DT_Dt_FailSafe_ExceptionReason_Info_T_3: Array with 5 element(s) of type uint32
 * Rte_DT_Dt_FailSafe_ExceptionReason_T_0: Array with 3 element(s) of type Dt_FailSafe_ExceptionReason_Info_T
 * Rte_DT_Dt_FailSafe_ResetReason_T_0: Array with 5 element(s) of type uint8
 * Rte_DT_Dt_FailSafe_ResetReason_T_7: Array with 5 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_8: Array with 10 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_9: Array with 35 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Dt_ECC_Correctable_Error_Counters: Record with elements
 *   aa_mem_sec of type uint8
 *   artie_mem_sec of type uint8
 *   csi2_sec of type uint8
 *   dsp_opif_sec of type uint8
 *   dsp_idma_sec of type uint8
 *   dsp_iram_sec_axis of type uint8
 *   dsp_dcache_sec of type uint8
 *   dsp_dram_sec of type uint8
 *   dsp_icache_sec of type uint8
 *   dsp_iram_sec of type uint8
 *   ra_cqmem_sec of type uint8
 *   ra_dpmem_sec of type uint8
 *   ra_estmem_sec of type uint8
 *   ra_idxmem_sec of type uint8
 *   ra_phmem_sec of type uint8
 *   ra_wcmem_sec of type uint8
 *   sp_axi_m_corr of type uint16
 *   sp_axi_s_corr of type uint16
 *   sysmem0_sec of type uint8
 *   sysmem1_sec of type uint8
 *   not_recorded of type uint8
 * Dt_FailSafe_ExceptionReason_Info_T: Record with elements
 *   exception_type of type uint8
 *   coreid of type uint8
 *   reserved of type uint16
 *   spf_regs of type Rte_DT_Dt_FailSafe_ExceptionReason_Info_T_3
 * Dt_FailSafe_ExceptionReason_T: Record with elements
 *   exception_reason_info of type Rte_DT_Dt_FailSafe_ExceptionReason_T_0
 *   exception_reason_crnt_indx of type uint8
 * Dt_FailSafe_ResetReason_T: Record with elements
 *   reset_reason of type Rte_DT_Dt_FailSafe_ResetReason_T_0
 *   reset_counter of type uint8
 *   last_cycle_reset of type uint8
 *   reset_reason_crnt_indx of type uint8
 *   repetitive_reset_counter of type uint8
 *   RFE_Repetitive_Reset_Counter of type uint8
 *   mem_exception_reason of type Dt_Memory_Exception_Info_T
 *   wdg_failed_SE_info of type Rte_DT_Dt_FailSafe_ResetReason_T_7
 *   FCCU_Faults of type Rte_DT_Dt_FailSafe_ResetReason_T_8
 *   StaticRegCheckFailureInfo of type Rte_DT_Dt_FailSafe_ResetReason_T_9
 *   NOC_LatentIntFault_Info of type Dt_NOC_Fault_Info_T
 * Dt_Hardware_Fault_Error_Status: Record with elements
 *   RA_Fault_Status of type uint8
 * Dt_Memory_Exception_Info_T: Record with elements
 *   ExceptionType of type uint32
 *   ExceptionCausingAddress of type uint32
 *   ExceptionStatusRegister of type uint32
 *   IsMemException_Occured of type boolean
 *   MemoryExceptionAddress of type uint32
 *   StackPointer of type uint32
 * Dt_NOC_Fault_Info_T: Record with elements
 *   LatentFault0 of type uint32
 *   LatentFault1 of type uint32
 *   LatentFault2 of type uint32
 *   LatentFault3 of type uint32
 *   Resnum of type uint16
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Dt_FailSafe_ExceptionReason_T *Rte_Pim_ExceptionReason_PIM(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Dt_FailSafe_ExceptionReason_T *Rte_CData_ExceptionReason_DefaultValue(void)
 *   Dt_FailSafe_ResetReason_T *Rte_CData_ResetReason_DefaultValue(void)
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_FailSafe_START_SEC_CODE
#include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_FailSafe_Fault_Injection
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_FailSafe_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_FailSafe_Fault_Injection(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_FailSafe_Fault_Injection_doc
 *********************************************************************************************************************/

/*==========================================================================*/
/**
 * FUNCTION: Log_ResetReason
 *===========================================================================
 * RETURN VALUE:
 *
 *
 * PARAMETERS:
 * reset_reason
 *
 *
 * EXTERNAL REFERENCES:

 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * This logs the reset reasona nd perform reset
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Log_ResetReason(uint16 reset_reason)
{
   if ((reset_reason == MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION) || (reset_reason == MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION) ||
       (reset_reason == MCU_FAILSAFE_ABORT_DATA_EXCEPTION) || (reset_reason == E_OS_PROTECTION_MEMORY) ||
       (reset_reason == E_OS_PROTECTION_EXCEPTION) || (reset_reason == OS_PANICHOOK) ||
       (reset_reason == MCU_FAILSAFE_SERIAL_CLK_FAILURE))
   {
#if (TRUE == XCP_FAULT_INJECTION)
      /* FHTI_Time_Data is not available in Gen8 this need to be Updated */
      // Get_Platform_Elapsed_ustime((uint32 *)&FHTI_Time_Data.DeltaTime, FHTI_Time_Data.StartTime);
#endif
      /*To go to SS2 Turn off CAN and Ethernet transceivers */
      /* Check if Ethernet link is Up, to resolve the ETHTRCV_30_RTL9010_SID_SET_TRANSCEIVER_MODE issue */
      if (EthTrcv_30_Rtl9010_TrcvLinkState == (EthTrcv_StateType *)ETHTRCV_LINK_STATE_ACTIVE)
      {
         EthTrcv_30_Rtl9010_SetTransceiverMode(0u, ETHTRCV_MODE_DOWN);
      }
      Can_SetControllerMode(0u, CAN_CS_STOPPED);
      Mcu_Reset(RESET_SW_UNINTENTIONAL);
   }
   else
   {
      Failsafe_WriteToNvMAndPerformReset(reset_reason);
   }
#ifndef UNIT_TEST
   while (1) /*if code reaches here, it means reset is not happening and external watch dog should trigger a reset  */
   {
      /*do nothing*/
   }
#endif
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FailSafe_CODE)
CS_FailSafe_Fault_Injection(uint8 Injection_control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_FailSafe_Fault_Injection
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Failsafe_Log_ResetReason_at_Startup
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <fcru_reset_reason> of PortPrototype
 *<CS_Failsafe_Log_ResetReason_at_Startup>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Failsafe_Log_ResetReason_at_Startup(uint8 reset_reason)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Failsafe_Log_ResetReason_at_Startup_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FailSafe_CODE)
CS_Failsafe_Log_ResetReason_at_Startup(uint8 reset_reason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Failsafe_Log_ResetReason_at_Startup
    *********************************************************************************************************************/

   if ((reset_reason >= MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD) && (reset_reason <= MCU_FCRU_FAULT_63_TOP_RESET_FAULT))
   {
      Log_ResetReason_Info(reset_reason);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAIL_SAFE);
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Get_RepetativeReset_Faultnum_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_Get_RepetativeReset_Faultnum>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Get_RepetativeReset_Faultnum_Operation(uint8 *faultnum)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Get_RepetativeReset_Faultnum_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FailSafe_CODE)
CS_Get_RepetativeReset_Faultnum_Operation(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR)
                                             faultnum) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Get_RepetativeReset_Faultnum_Operation
    *********************************************************************************************************************/
   uint8 ret = CODED_FALSE;
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   *faultnum = 0xFF;
#endif

   /* read and verify repetative reset and get reaset reason */
   ret = FailSafe_Verify_ResetReason(faultnum);
   if (ret != (uint8)CODED_TRUE)
   {
      /* if reset is not because of FCRU fault then update faultnum with NO_FCRU_REPETATIVE_RESET */
      *faultnum = NO_FCRU_REPETATIVE_RESET;
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FailSafe_Log_ResetReason
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <FailSafe_Log_ResetReason> of PortPrototype <FailSafe_Log_ResetReason>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID
 *dt_Nv_Caller_Id) Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_WdgM_General_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType *SEID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_General_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FailSafe_Log_ResetReason_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FailSafe_CODE)
FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: FailSafe_Log_ResetReason
    *********************************************************************************************************************/

   Log_ResetReason(reset_reason);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_FailSafe_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(const Dt_FailSafe_ResetReason_T *data)
 *   Std_ReturnType Rte_Write_Pp_FailSafe_Verify_ResetReason_FailSafe_Verify_ResetReason(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_FailSafe_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*==========================================================================*/
/**
 * FUNCTION: Failsafe_check_power_on_reset
 *===========================================================================
 * RETURN
 * void
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
 * Failsafe_check_power_on_reset to Check it is a power on reset
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Failsafe_check_power_on_reset(void)
{
#ifndef UNIT_TEST
   if (Boot_Shared_Data.reset_type == CNTR_INDEX_ZERO)
   {
      PLT_Reset_Reason.repetitive_reset_counter = ZERO;
   }
   else
   {
      /*Do nothing*/
   }
#endif
}

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) RE_PLT_FailSafe_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_FailSafe_Init
    *********************************************************************************************************************/
   /* Configure correctable error count limit */
   Initalize_CEE_Limit();

   /*Read if any reset reason stored in No-init or NVM*/
   Fail_Safe_Read_Reset_Reason_Callout();
#ifndef UNIT_TEST
   if ((Retention_Ram_Data.Exception_data.reset_number == MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION) ||
       (Retention_Ram_Data.Exception_data.reset_number == MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION) ||
       (Retention_Ram_Data.Exception_data.reset_number == MCU_FAILSAFE_ABORT_DATA_EXCEPTION) ||
       (Retention_Ram_Data.Exception_data.reset_number == MCU_FAILSAFE_SERIAL_CLK_FAILURE) ||
       (Retention_Ram_Data.Exception_data.reset_number == OS_PROTECTION_MEMORY) ||
       (Retention_Ram_Data.Exception_data.reset_number == OS_PROTECTION_EXCEPTION))
   {
      Log_ResetReason_Info(Retention_Ram_Data.Exception_data.reset_number);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAIL_SAFE);
   }
   else
   {
      /* Do nothing */
   }
#endif
   /*Check if it is power on reset*/
   Failsafe_check_power_on_reset();
   /*Check Repetitive Reset*/
   FailSafe_Check_RepetitiveResetCount();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_FailSafe_Main_50ms
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
 *   Std_ReturnType Rte_Read_Rp_MemExceptionInfo_De_MemExceptionInfo(Dt_Memory_Exception_Info_T *data)
 *   Std_ReturnType Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(Rte_DT_Dt_StaticRegCheckFailureInfo_0 *data)
 *     Argument data: Rte_DT_Dt_StaticRegCheckFailureInfo_0* is of type Dt_StaticRegCheckFailureInfo
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(const Dt_ECC_Correctable_Error_Counters *data)
 *   Std_ReturnType Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(Dt_Fault_name_FHTI data)
 *   Std_ReturnType Rte_Write_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status(const Dt_Hardware_Fault_Error_Status *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ExceptiontReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ExceptiontReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_FailSafe_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) RE_PLT_FailSafe_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_FailSafe_Main_50ms
    *********************************************************************************************************************/
   Dt_Hardware_Fault_Error_Status Fault_Error_Status = {0};
   Rte_Write_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status(&Fault_Error_Status);
   /*Checking if last cycle reset is TRUE*/
   if ((uint8)CODED_TRUE == (uint8)PLT_Reset_Reason.last_cycle_reset)
   {
      PLT_Reset_Reason.last_cycle_reset = CODED_FALSE;
      /*Clear in NVM RAM also*/
      Fail_Safe_Clear_Last_Cycle_Callout();
   }
   else
   {
      /*Do nothing*/
   }

   Monitor_Correctable_Errors();

#ifdef TEST_NOINIT
   if (FailSafe_Test_Trigger_Reset)
   {
      FailSafe_Log_ResetReason(MCU_FAILSAFE_SOFT_FUNC_RESET);
   }
#endif /* TEST_NOINIT */

#if (TRUE == ENABLE_SIT_TEST_STUBS)
   FailSafe_Integration_Test();
#endif
#if (TRUE == ENABLE_SQT_TEST_STUBS)
   Failsafe_SW_Quality_test();
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
#include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*==========================================================================*/
/**
 * FUNCTION: Get_Platform_ResetReason_Info
 *===========================================================================
 * RETURN VALUE:
 * FailSafe_ResetReason_T
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
 * Get function that can be used at platform boundary to read the reset reason
 * info struct
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
FailSafe_ResetReason_T *Get_Platform_ResetReason_Info(void)
{
   return ((FailSafe_ResetReason_T *)&PLT_Reset_Reason);
}

/*====================================================================================================================*\
* FUNCTION: Log_ExceptionReason_Info
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: uint8 ,uint16
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* To Log the Exception reason information in NVM.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
* ----------------------------------------------------------------------------------------------------------------------
* Traceability:
* ----------------------------------------------------------------------------------------------------------------------
* SUV/CDV: WI-58931, WI-58954, WI-58952, WI-58953, WI-58958, WI-60019
\*====================================================================================================================*/

void Log_ExceptionReason_Info(Dt_Memory_Exception_Info_T *Exception_Context, uint16 Resnum)
{
#ifndef UNIT_TEST
   Retention_Ram_Data.Exception_data.exception_type            = Exception_Context->ExceptionType;
   Retention_Ram_Data.Exception_data.exception_causing_address = Exception_Context->ExceptionCausingAddress;
   Retention_Ram_Data.Exception_data.exception_status_register = Exception_Context->ExceptionStatusRegister;
   Retention_Ram_Data.Exception_data.memory_exception_occurred = Exception_Context->IsMemException_Occured;
   Retention_Ram_Data.Exception_data.memory_exception_address  = Exception_Context->MemoryExceptionAddress;
   Retention_Ram_Data.Exception_data.stack_pointer             = Exception_Context->StackPointer;
   Retention_Ram_Data.Exception_data.reset_number              = Resnum;
#endif
}

/*====================================================================================================================*\
* FUNCTION: Log_NOCLatentIntFault_Info
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: uint8 ,uint16
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* To Log the NOC latent internal fault information in NVM.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
* ----------------------------------------------------------------------------------------------------------------------
* Traceability:
* ----------------------------------------------------------------------------------------------------------------------
* SUV/CDV:
\*====================================================================================================================*/

void Log_NOCLatentIntFault_Info(Dt_NOC_Fault_Info_T *NOC_Fault_Context, uint16 Resnum)
{
#ifndef UNIT_TEST
   PLT_Reset_Reason.NOC_LatentIntFault_Info.LatentFault0 = NOC_Fault_Context->LatentFault0;
   PLT_Reset_Reason.NOC_LatentIntFault_Info.LatentFault1 = NOC_Fault_Context->LatentFault1;
   PLT_Reset_Reason.NOC_LatentIntFault_Info.LatentFault2 = NOC_Fault_Context->LatentFault2;
   PLT_Reset_Reason.NOC_LatentIntFault_Info.LatentFault3 = NOC_Fault_Context->LatentFault3;
   PLT_Reset_Reason.NOC_LatentIntFault_Info.Resnum       = Resnum;
#endif
}
/*====================================================================================================================*\
* FUNCTION: Log_ResetReason_Info
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: uint8
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* To Log the Reset reason information in NVM.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
* ----------------------------------------------------------------------------------------------------------------------
* Traceability:
* ----------------------------------------------------------------------------------------------------------------------
* SUV/CDV:
\*====================================================================================================================*/
void Log_ResetReason_Info(uint8 reset_reason)
{
   Dt_StaticRegCheckFailureInfo StaticRegCheckFailure_Info;
   uint8 index                      = 0u;
   uint8 current_reset_reason       = 0u;
   uint8 prev_reset_reason          = 0u;
   WdgM_SupervisedEntityIdType SEID = 0xFF;
   /*Increment Reset Reason current index by 1*/
   PLT_Reset_Reason.reset_reason_crnt_indx++;
   /*check current reset reason index value if it reaches max value*/
   if (MAX_RESET_REASONS == PLT_Reset_Reason.reset_reason_crnt_indx)
   {
      PLT_Reset_Reason.reset_reason_crnt_indx = 0u;
   }
   else
   {
      /* No action to perform */
   }
   (void)Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(StaticRegCheckFailure_Info);
   for (index = 0; index < MAX_REG_CHECK_FAILURE; index++)
   {
      PLT_Reset_Reason.StaticRegCheckFailureInfo[index] = StaticRegCheckFailure_Info[index];
   }
   if ((reset_reason == MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION) || (reset_reason == MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION) ||
       (reset_reason == MCU_FAILSAFE_ABORT_DATA_EXCEPTION) || (reset_reason == E_OS_PROTECTION_MEMORY) ||
       (reset_reason == E_OS_PROTECTION_EXCEPTION) || (reset_reason == MCU_FAILSAFE_SERIAL_CLK_FAILURE))
   {
      PLT_Reset_Reason.FailSafeExceptionReason.ExceptionType = Retention_Ram_Data.Exception_data.exception_type;
      PLT_Reset_Reason.FailSafeExceptionReason.ExceptionCausingAddress =
         Retention_Ram_Data.Exception_data.exception_causing_address;
      PLT_Reset_Reason.FailSafeExceptionReason.ExceptionStatusRegister =
         Retention_Ram_Data.Exception_data.exception_status_register;
      PLT_Reset_Reason.FailSafeExceptionReason.IsMemException_Occured =
         Retention_Ram_Data.Exception_data.memory_exception_occurred;
      PLT_Reset_Reason.FailSafeExceptionReason.MemoryExceptionAddress = Retention_Ram_Data.Exception_data.memory_exception_address;
      PLT_Reset_Reason.FailSafeExceptionReason.StackPointer           = Retention_Ram_Data.Exception_data.stack_pointer;
      Failsafe_clear_Exception_SharedData();
   }

   /*Update Reset reason value in buffer*/
   PLT_Reset_Reason.reset_reason_info[PLT_Reset_Reason.reset_reason_crnt_indx] = reset_reason;
   if (reset_reason == MCU_FAILSAFE_WDG_RESET_REASON)
   {
      Rte_Call_CS_WdgM_General_GetFirstExpiredSEID(&SEID);
   }
   else
   {
      /* No action to perform */
   }
   PLT_Reset_Reason.wdg_failed_SE_info[PLT_Reset_Reason.reset_reason_crnt_indx] = SEID;

   if (PLT_Reset_Reason.reset_counter != CNTR_INDEX_ZERO)
   {
      current_reset_reason = PLT_Reset_Reason.reset_reason_info[PLT_Reset_Reason.reset_reason_crnt_indx];
      if (PLT_Reset_Reason.reset_reason_crnt_indx == CNTR_INDEX_ZERO)
      {
         prev_reset_reason = PLT_Reset_Reason.reset_reason_info[MAX_RESET_REASONS - PREV_INDX];
      }
      else
      {
         prev_reset_reason = PLT_Reset_Reason.reset_reason_info[PLT_Reset_Reason.reset_reason_crnt_indx - PREV_INDX];
      }
      if (current_reset_reason == prev_reset_reason)
      {
         PLT_Reset_Reason.repetitive_reset_counter++;
      }
      else
      {
         PLT_Reset_Reason.repetitive_reset_counter = RESET_CNTR;
      }
   }
   else
   {
      /* No action to perform */
   }
   /*Check Reset counter if it reaches to max value*/
   if (MAX_RESET_COUNTER_VAL > PLT_Reset_Reason.reset_counter)
   {
      PLT_Reset_Reason.reset_counter++;
   }
   else
   {
      /* No action to perform */
   }
   /*Update last cycle reset to TRUE*/
   PLT_Reset_Reason.last_cycle_reset = (uint8)CODED_TRUE;

   /*Call out customer specific reset reason storage via NVM/No-Init-Ram */
   Fail_Safe_Store_Reset_Reason_Callout();
}
/*==========================================================================*/
/**
 * FUNCTION: Failsafe_WriteToNvMAndPerformReset
 *===========================================================================
 * RETURN VALUE:
 * void
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
 * Failsafe_WriteToNvMAndPerformReset to log thde reset raeson if there are no cat1 exceptions
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Failsafe_WriteToNvMAndPerformReset(uint16 reset_reason)
{
   /*To go to SS2 Turn off CAN and Ethernet transceivers */
   /* Check if Ethernet link is Up, to resolve the ETHTRCV_30_RTL9010_SID_SET_TRANSCEIVER_MODE issue */
   if (EthTrcv_30_Rtl9010_TrcvLinkState == (EthTrcv_StateType *)ETHTRCV_LINK_STATE_ACTIVE)
   {
      EthTrcv_30_Rtl9010_SetTransceiverMode(0u, ETHTRCV_MODE_DOWN);
   }
   Can_SetControllerMode(0u, CAN_CS_STOPPED);
   /* Log Reset reason information */
   Log_ResetReason_Info(reset_reason);
   SuspendAllInterrupts(); /*Suspend all interrupts before logging the reset reason and perform reset*/
   Fail_Safe_Check_NVM_Status_Callout();
   Mcu_Reset(RESET_SW_UNINTENTIONAL);
}

/*==========================================================================*/
/**
 * FUNCTION: Failsafe_clear_Exception_SharedData
 *===========================================================================
 * RETURN VALUE:
 * void
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
 * Failsafe_clear_Exception_SharedData to clear the boot shared data
 *
 *
 * PRECONDITIONS:
 *
 *
 * POSTCONDITIONS:
 *
 */
/*===========================================================================*/
void Failsafe_clear_Exception_SharedData(void)
{
#ifndef UNIT_TEST
   Retention_Ram_Data.Exception_data.exception_type            = 0;
   Retention_Ram_Data.Exception_data.exception_causing_address = 0;
   Retention_Ram_Data.Exception_data.exception_status_register = 0;
   Retention_Ram_Data.Exception_data.memory_exception_occurred = 0;
   Retention_Ram_Data.Exception_data.memory_exception_address  = 0;
   Retention_Ram_Data.Exception_data.stack_pointer             = 0;
   Retention_Ram_Data.Exception_data.reset_number              = 0;
#endif
}

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
