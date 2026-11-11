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
 *             File:  SWC_PLT_CDD_MCU_Safety.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_MCU_Safety
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_MCU_Safety>
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
 * Dt_PltRRUFS_SafetyReq_Status_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_MCU_Safety.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SWC_PLT_CDD_MCU_Safety.h"
#include "mcu_reset_wrapper.h"
#if (TRUE == XCP_FAULT_INJECTION)
   #include "FailSafe_Callout.h"
   #include "retention_ram_data.h"

   #define IC_REPETATIVE_RESET_0x00 (0x00U)
   #define IC_REPETATIVE_RESET_0x01 (0x01U)
   #define IC_REPETATIVE_RESET_0x02 (0x02U)
   #define IC_REPETATIVE_RESET_0x03 (0x03U)
   #define IC_REPETATIVE_RESET_0x04 (0x04U)
   #define IC_REPETATIVE_RESET_0x05 (0x05U)
   #define IC_REPETATIVE_RESET_0x06 (0x06U)

   #define RESET_WITH_SAME_RESET_REASON (0x01U)
   #define RESET_WITH_DIFF_RESET_REASON (0x02U)

   #define RESET_1_TIME                        (0x01U)
   #define RESET_2_TIME                        (0x02U)
   #define RESET_3_TIME                        (0x03U)
   #define RESET_4_TIME                        (0x04U)
   #define RESET_8_TIME                        (0x08U)
   #define NO_RESET                            (0x00U)
   #define REMOVE_FAULT                        0x01U
   #define INJECT_FAULT                        0x00U
   #define FAILURE_TYPE_MCU_STARTUP_FAULT      (0x00U)
   #define FAILURE_TYPE_REPETATIVE_RESET_FAULT (0x01U)

#endif

#if (ENABLE_SIT_TEST_STUBS == TRUE)
volatile uint8 Test_Injection_Control_MCU_Safety = 0;
volatile uint8 Test_Failure_Type_MCU_Safety      = 0;
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
 * Dt_ECU_ResetReasonType: Integer in interval [0...65535]
 * Dt_Fault_name_FHTI: Integer in interval [0...255]
 * Dt_InitializationStatus: Integer in interval [0...255]
 * Dt_PltRRUFS_SafetyReq_Status_T: Integer in interval [0.0...3]
 * Rte_DT_Dt_StaticRegCheckFailureInfo_0: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Dt_StaticRegCheckFailureInfo: Array with 35 element(s) of type Rte_DT_Dt_StaticRegCheckFailureInfo_0
 * Rte_DT_Dt_ID_data_0: Array with 16 element(s) of type uint8
 * Rte_DT_Dt_ID_data_1: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Dt_ID_data: Record with elements
 *   MCU_ID of type Rte_DT_Dt_ID_data_0
 *   Unique_ID of type Rte_DT_Dt_ID_data_1
 * Dt_Memory_Exception_Info_T: Record with elements
 *   ExceptionType of type uint32
 *   ExceptionCausingAddress of type uint32
 *   ExceptionStatusRegister of type uint32
 *   IsMemException_Occured of type boolean
 *   MemoryExceptionAddress of type uint32
 *   StackPointer of type uint32
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_MCU_Safety_START_SEC_CODE
#include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_MCU_Safety_Fault_Injection
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_MCU_Safety_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_MCU_Safety_Fault_Injection(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_MCU_Safety_Fault_Injection_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
CS_MCU_Safety_Fault_Injection(uint8 Injection_control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_MCU_Safety_Fault_Injection
    *********************************************************************************************************************/

#if (ENABLE_SIT_TEST_STUBS == TRUE)
   Test_Injection_Control_MCU_Safety = Injection_control;
   Test_Failure_Type_MCU_Safety      = Failure_Type;
#endif
#if (TRUE == XCP_FAULT_INJECTION)
   if (FAILURE_TYPE_MCU_STARTUP_FAULT == Failure_Type)
   {
      if (INJECT_FAULT == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name = MCU_STARTUP_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count  = RESET_1_TIME;
         Mcu_Reset(RESET_SW_INTENTIONAL);
      }
      else if (REMOVE_FAULT == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name = 0x0U;
         Retention_Ram_Data.fhti_test_data.reset_count  = NO_RESET;
         Mcu_Reset(RESET_SW_INTENTIONAL);
      }
   }
   else if (FAILURE_TYPE_REPETATIVE_RESET_FAULT == Failure_Type)
   {
      FailSafe_Reset_PLT_Reset_Reason();

      if (IC_REPETATIVE_RESET_0x00 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_1_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_SAME_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x01 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_2_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_SAME_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x02 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_3_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_SAME_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x03 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_4_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_SAME_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x04 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_8_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_SAME_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x05 == Injection_control)
      {
         Retention_Ram_Data.fhti_test_data.failure_name                = MCU_REPETATIVE_RESET_FAULT;
         Retention_Ram_Data.fhti_test_data.reset_count                 = RESET_4_TIME;
         Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = RESET_WITH_DIFF_RESET_REASON;
      }
      else if (IC_REPETATIVE_RESET_0x06 == Injection_control)
      {
         Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(DEFAULT_RESET_REASON);
      }
   }
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ECC_CacheMemory_SafetyCore_Disable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ECC_CacheMemory_SafetyCore_Disable> of PortPrototype
 *<Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ECC_CacheMemory_SafetyCore_Disable(Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ECC_CacheMemory_SafetyCore_Disable_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
ECC_CacheMemory_SafetyCore_Disable(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                                      ECC_CacheMemory_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: ECC_CacheMemory_SafetyCore_Disable
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ECC_CacheMemory_SafetyCore_Enable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ECC_CacheMemory_SafetyCore_Enable> of PortPrototype
 *<Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ECC_CacheMemory_SafetyCore_Enable(Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ECC_CacheMemory_SafetyCore_Enable_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
ECC_CacheMemory_SafetyCore_Enable(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                                     ECC_CacheMemory_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: ECC_CacheMemory_SafetyCore_Enable
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ECC_CacheMemory_SafetyCore_Status
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ECC_CacheMemory_SafetyCore_Status> of PortPrototype
 *<Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ECC_CacheMemory_SafetyCore_Status(Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ECC_CacheMemory_SafetyCore_Status_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
ECC_CacheMemory_SafetyCore_Status(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                                     ECC_CacheMemory_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: ECC_CacheMemory_SafetyCore_Status
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ECC_FlashMemory_Fault_Report_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ECC_FlashMemory_Fault_Report_Check> of PortPrototype
 *<Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Rp_PltFCCU_TestFlashMemECCPath_FCCU_TestFlashMemECCPath(uint8 *FLS_MemTestResult)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ECC_FlashMemory_Fault_Report_Check(Dt_PltRRUFS_SafetyReq_Status_T *ECC_FlashMemory_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ECC_FlashMemory_Fault_Report_Check_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
ECC_FlashMemory_Fault_Report_Check(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                                      ECC_FlashMemory_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: ECC_FlashMemory_Fault_Report_Check
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ECU_Soft_Reset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ECU_Soft_Reset> of PortPrototype <Pp_ECU_Reset>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ECU_Soft_Reset(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ECU_Soft_Reset_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECU_Soft_Reset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: ECU_Soft_Reset
    *********************************************************************************************************************/

   Mcu_Reset(RESET_SW_INTENTIONAL);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCCU_CheckerCore_Status
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RCCU_CheckerCore_Status> of PortPrototype
 *<Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RCCU_CheckerCore_Status(Dt_PltRRUFS_SafetyReq_Status_T *CheckerCore_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCCU_CheckerCore_Status_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
RCCU_CheckerCore_Status(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                           CheckerCore_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RCCU_CheckerCore_Status
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_MCU_Safety_50ms
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
 *   Std_ReturnType Rte_Read_Rp_FCCU_Init_Status_De_Init_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_MPU_lock_request_De_MPU_lock_sts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(Rte_DT_Dt_StaticRegCheckFailureInfo_0 *data)
 *     Argument data: Rte_DT_Dt_StaticRegCheckFailureInfo_0* is of type Dt_StaticRegCheckFailureInfo
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(Dt_Fault_name_FHTI data)
 *   Std_ReturnType Rte_Write_Pp_MPU_lock_sts_De_MPU_lock_sts(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_MemExceptionInfo_De_MemExceptionInfo(const Dt_Memory_Exception_Info_T *data)
 *   Std_ReturnType Rte_Write_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(const Rte_DT_Dt_StaticRegCheckFailureInfo_0
 **data) Argument data: Rte_DT_Dt_StaticRegCheckFailureInfo_0* is of type Dt_StaticRegCheckFailureInfo
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_MCU_Safety_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RE_PLT_MCU_Safety_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_MCU_Safety_50ms
    *********************************************************************************************************************/

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   MCU_Safety_TestManager();
#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   MCU_Safety_Integration_Test();
#endif
   MCU_Safety_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_MCU_Safety_Init
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
 *   Std_ReturnType Rte_Read_Rp_FCCU_Config_State_FCCU_Config_State(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_TR_PlatformTime_De_PlatformTime(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_external_watchdog_init_status_de_wdginit_status(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ID_data_De_ID_data(const Dt_ID_data *data)
 *   Std_ReturnType Rte_Write_Pp_MCU_Ram_Fault_Test_Status_De_MCU_Ram_Fault_Test_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus(Dt_InitializationStatus data)
 *   Std_ReturnType Rte_Write_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_MCU_Safety_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RE_PLT_MCU_Safety_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_MCU_Safety_Init
    *********************************************************************************************************************/

   MCU_Safety_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RRU_FS_InitTest
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RRU_FS_InitTest> of PortPrototype <Pi_PltRRUFS_SafetyReq_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RRU_FS_InitTest(Dt_PltRRUFS_SafetyReq_Status_T *SafetyReq_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RRU_FS_InitTest_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE)
RRU_FS_InitTest(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR)
                   SafetyReq_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RRU_FS_InitTest
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_MCU_Safety_STOP_SEC_CODE
#include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
