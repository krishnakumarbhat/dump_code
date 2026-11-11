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
 *             File:  SWC_PLT_Appl_ModeManager.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_ModeManager
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_ModeManager>
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
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_ModeManager.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "modemanager.h"
#if (TRUE == XCP_FAULT_INJECTION)
   #include "dd_gpt.h"
   #include "platformtime.h"
   #include "retention_ram_data.h"
static uint8 Get_Modemanager_State(uint8 injection_control);
   #define FT_MODE_MANAGER_EXTERNAL_INTERFACES (0x06U)
   #define IC_PRJ_RESET_REQ                    (0x00U)
   #define IC_PRJ_SAFETY_CRITICAL_TRUE         (0x01U)
   #define IC_PRJ_SAFETY_CRITICAL_FALSE        (0x02U)
   #define IC_PRJ_RADAR_DIAG_SHUTDOWN_TRUE     (0x03U)
   #define IC_PRJ_RADAR_DIAG_SHUTDOWN_FALSE    (0x04U)
   #define IC_CUST_FORCE_RADIATE_ON            (0x05U)
   #define IC_CUST_FORCE_RADIATE_FALSE         (0x06U)

   #define FT_MODE_MANAGER_TRANSITIONS                  (0x05U)
   #define IC_MCU_INIT                                  (0x00U)
   #define IC_MCU_INIT_TO_RADAR_NOT_CONFIGURED_STATE    (0x01U)
   #define IC_RADAR_NOT_CONFIGURED_STATE_TO_OPEARTIONAL (0x02U)
   #define IC_OPERATIONAL_TO_SHUTDOWN_INITIATED         (0x03U)
   #define IC_SHUTDOWN_INITIATED_TO_INIT_MCU            (0x04U)
   #define IC_SHUTDOWN_INITIATED_TO_POWER_OFF           (0x05U)

volatile uint8 Mode_Manager_Fault_Injection  = MODEMANAGER_VALUE_DEFAULT;
volatile uint8 Mode_Manager_State_Transition = MODEMANAGER_VALUE_DEFAULT;

uint8_t Failure_name = 0xFF;
FHTI_Failure_Time Failure_time[PLT_MAX_FAULT_NUMBER];

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
 * Enumeration Types:
 * ==================
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
 * Dt_ForceRadiate: Enumeration of integer in interval [0...255] with enumerators
 *   FORCE_OFF (0U)
 *   FORCE_ON (1U)
 *   NO_FORCE (2U)
 * Dt_InitializationStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NOT_COMPLETED (0U)
 *   COMPLETED (1U)
 *   FAILED (2U)
 * Dt_SystemOperationMode: Enumeration of integer in interval [0...255] with enumerators
 *   INIT_MCU (1U)
 *   RADAR_NOT_CONFIGURED (2U)
 *   OPERATIONAL (3U)
 *   FAULTY (4U)
 *   SHUTDOWN_INITIATED (5U)
 *   SHUTDOWN_COMPLETED (6U)
 * Dt_VBattState_T: Enumeration of integer in interval [0...255] with enumerators
 *   PowerON (0U)
 *   NORMV (1U)
 *   LO_V1 (2U)
 *   HI_V1 (3U)
 *   LO_V2 (4U)
 *   HI_V2 (5U)
 *   LO_Vtemp (6U)
 *   LO_VTEMP_TONORM (7U)
 *   LO_V1_TONORM (8U)
 *   LO_V2_TONORM (9U)
 *   HI_VTEMP_TONORM (10U)
 *   HI_V1_TONORM (11U)
 *   HI_V2_TONORM (12U)
 *   HI_Vtemp (13U)
 * Rte_DT_Dt_RadarCoreStatus_0: Enumeration of integer in interval [0...255] with enumerators
 *   RADAR_NOT_STARTED (0U)
 *   BUSY_RadarInitStatus (1U)
 *   RADAR_SUCCESS (2U)
 *   RADAR_INITIALIZATION_FAIL (3U)
 * Rte_DT_Dt_RadarCoreStatus_3: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   RADAR_INIT (1U)
 *   ERROR_RECOVERY (2U)
 *   FULLY_OPERATIONAL (3U)
 *   FAULTY (4U)
 *   ENVIRONMENTAL_DEGRADED (5U)
 *   TEMPERATURE_DEGRADED (6U)
 *   MANUFACTURING_MODE (7U)
 *
 * Record Types:
 * =============
 * Dt_CustDegradation: Record with elements
 *   Proj_RadarDiagShutdown of type uint8
 *   Proj_SafetyCriticalFaultActive of type uint8
 * Dt_OpModeShutdown: Record with elements
 *   ShutdownRequested of type uint8
 *   ReturnToNormalRequested of type uint8
 *   CustShutdownTaskCompleted of type uint8
 * Dt_RadarCoreStatus: Record with elements
 *   RadarInitializatonStatus of type Rte_DT_Dt_RadarCoreStatus_0
 *   RadarReInitRequired of type uint8
 *   IsRadiating of type uint8
 *   OperationMode_Radar of type Rte_DT_Dt_RadarCoreStatus_3
 * Dt_RadarDiagRequest: Record with elements
 *   RadarDiagShutdown of type uint8
 *   SafetyCriticalFaultActive of type uint8
 *   RadarReinitRequired_Qual of type uint8
 * Dt_TR_ModeManager: Record with elements
 *   TR_FCCU_fault of type uint8
 *   TR_MCUTempCalFlt of type uint8
 *   TR_MCUTempHighFault of type uint8
 *   TR_onboardThermistorFault of type uint8
 *   TR_ECUTempHighFault of type uint8
 *   TR_PLLLockFault of type uint8
 *   TR_InstructionSetCheckFault of type uint8
 *   TR_WatchdogFault of type uint8
 *   TR_StackOverUnderflowFault of type uint8
 *   TR_ApplicationFlashChecksumFault of type uint8
 *   TR_FlashMemoryECCFault of type uint8
 *   TR_RAMMemoryTestFault of type uint8
 *   TR_1_1V_SupplyOutOfRangeFault of type uint8
 *   TR_1_25V_SupplyOutOfRangeFault of type uint8
 *   TR_1_8V_SupplyOutOfRangeFault of type uint8
 *   TR_2_3V_SupplyOutOfRangeFault of type uint8
 *   TR_5_0V_SupplyOutOfRangeFault of type uint8
 *   TR_BatteryLowFault of type uint8
 *   TR_BatteryHighFault of type uint8
 *   TR_Core1toCore0Fault of type uint8
 *   TR_Core1toCore2Fault of type uint8
 *   TR_Core2toCore0Fault of type uint8
 *   TR_Core2toCore1Fault of type uint8
 *   TR_Core0toCore1Fault of type uint8
 *   TR_Core0toCore2Fault of type uint8
 *   TR_InitMCUfail of type uint8
 *   TR_PlatformTimeFault of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_ModeManager_START_SEC_CODE
#include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Modemanager_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Modemanager_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Modemanager_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Modemanager_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_ModeManager_CODE)
CS_Modemanager_Fault_Injection_Read(uint8 Injection_Control,
                                    uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Modemanager_Fault_Injection_Read
    *********************************************************************************************************************/
#if (TRUE == XCP_FAULT_INJECTION)
   if (FT_MODE_MANAGER_EXTERNAL_INTERFACES == Failure_Type) /*Modify external interfaces from integrator*/
   {
      if (IC_PRJ_RESET_REQ == Injection_Control)
      {
         Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset();
      }
      else
      {
         Mode_Manager_Fault_Injection = Get_Modemanager_State(Injection_Control);
      }
   }
   else if (FT_MODE_MANAGER_TRANSITIONS == Failure_Type) /*To test OperationMode transitions*/
   {
      Mode_Manager_State_Transition = Get_Modemanager_State(Injection_Control);
   }
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Mode_Manager_Init
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
 *   Std_ReturnType Rte_Read_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(Dt_Fault_name_FHTI *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Mode_Manager_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_ModeManager_CODE) RE_PLT_Mode_Manager_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Mode_Manager_Init
    *********************************************************************************************************************/

   Mode_manager_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Mode_Manager_Main_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Mode_Manager_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_ModeManager_CODE)
RE_PLT_Mode_Manager_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Mode_Manager_Main_50ms
    *********************************************************************************************************************/

   Mode_Manager_Main_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Mode_Manager_StateMachine_5ms
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
 *   Std_ReturnType Rte_Read_Rp_CustDegradation_De_CustDegradation(Dt_CustDegradation *data)
 *   Std_ReturnType Rte_Read_Rp_CustForceRadiate_CustForceRadiate(Dt_ForceRadiate *data)
 *   Std_ReturnType Rte_Read_Rp_InitializationStatus_De_MCU_InitializationStatus(Dt_InitializationStatus *data)
 *   Std_ReturnType Rte_Read_Rp_ModeManager_NVM_ModeManager_NVM(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_OpModeShutdown_De_OpModeShutdown(Dt_OpModeShutdown *data)
 *   Std_ReturnType Rte_Read_Rp_RadarCoreStatus_De_RadarCoreStatus(Dt_RadarCoreStatus *data)
 *   Std_ReturnType Rte_Read_Rp_RadarDiagRequest_De_RadarDiagRequest(Dt_RadarDiagRequest *data)
 *   Std_ReturnType Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_TR_ModeManager_De_TR_ModeManager(Dt_TR_ModeManager *data)
 *   Std_ReturnType Rte_Read_Rp_Vbattstate_De_Vbatt_State(Dt_VBattState_T *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_ForceRadiate_De_XCPForceRadiate(Dt_ForceRadiate *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_CommandRadiate_Final_De_CommandRadiate_Final(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_IsRadiateForced_De_IsRadiateForced(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_OperationMode_System_De_OperationMode_System(Dt_SystemOperationMode data)
 *   Std_ReturnType Rte_Write_Pp_ShutdownTask_De_shutdownTask(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Mode_Manager_StateMachine_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_ModeManager_CODE)
RE_PLT_Mode_Manager_StateMachine_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Mode_Manager_StateMachine_5ms
    *********************************************************************************************************************/

   Mode_Manager_StateMachine_5ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_ModeManager_STOP_SEC_CODE
#include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
 * Name:  Get_Modemanager_State
 *   This function returns the value of injection_control
 *
 * Shared Variables: none
 *
 * Parameters: injection_control
 *
 * Return Value: uint8
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Mode_Manager.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == XCP_FAULT_INJECTION)
static uint8 Get_Modemanager_State(uint8 injection_control)
{
   uint8 mode_state_arr[] = {MODEMANAGER_VALUE_ZERO, MODEMANAGER_VALUE_ONE,  MODEMANAGER_VALUE_TWO, MODEMANAGER_VALUE_THREE,
                             MODEMANAGER_VALUE_FOUR, MODEMANAGER_VALUE_FIVE, MODEMANAGER_VALUE_SIX};

   return mode_state_arr[injection_control];
}
#endif

/******************************************************************************
* Name:  Shutdown_Completed_Processing
*    This function is called in SHUTDOWN_COMPLETED state and action will be implimented by customer.
*
* Shared Variables: none
*
* Parameters: none
*
* Return Value: none

******************************************************************************/

void Shutdown_Completed_Processing(void)
{
   /*Do nothing*/
}

/******************************************************************************
 * Name:  Evaluate_FHTI_Time
 *    This function is used to calculate FHTI timing when OperationMode_System
 * changes to Faulty state.
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
#if (TRUE == XCP_FAULT_INJECTION)
__attribute__((optnone)) void Evaluate_FHTI_Time(void)
{
   if ((Failure_name != PLATFORM_TIME_FAULT) && (Failure_name != MCU_STARTUP_FAULT) && (Failure_name < MAX_FAULT_NUMBER))
   {
      /*Calculate FHTI time for the fault other then Platform time fault by using Platform Timer */
      Get_Platform_Elapsed_mstime(&Failure_time[Failure_name].DeltaTime, Failure_time[Failure_name].StartTime);
   }
   else if ((Failure_name == PLATFORM_TIME_FAULT) || (Failure_name == MCU_STARTUP_FAULT))
   {
      /*Calculate FHTI time for the Platform time fault by using Free Running Timer */
      Failure_time[Failure_name].DeltaTime = Get_Elapsed_Time_Milliseconds(Failure_time[Failure_name].StartTime);
   }
   else
   {
      /* code */
   }
}
#endif

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
