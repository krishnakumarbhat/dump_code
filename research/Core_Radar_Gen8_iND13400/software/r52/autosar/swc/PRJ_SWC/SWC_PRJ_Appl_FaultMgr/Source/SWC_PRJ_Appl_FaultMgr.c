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
 *             File:  SWC_PRJ_Appl_FaultMgr.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PRJ_Appl_FaultMgr
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PRJ_Appl_FaultMgr>
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
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PRJ_Appl_FaultMgr.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "NvM.h"
#include "SWC_PRJ_Appl_FaultMgr.h"
#include "psc_cal.h"
extern Platform_fault_T *SWC_PLT_Appl_Active_Fault_Table;
Customer_fault_T *SWC_Appl_History_Fault_Table;
Customer_fault_T *SWC_Appl_Active_Fault_Table;
Customer_fault_T *SWC_Appl_Active_Fault_Latched_Table;
Customer_fault_Latch_Enable_T *SWC_Appl_Fault_Enable_Table;
Customer_fault_T *SWC_Appl_Fault_Test_Completed;
Platform_fault_T *SWC_PLT_Appl_Fault_Test_Completed;
Customer_fault_T *SWC_PRJ_Fault_Test_Completed;
#if ((ENABLE_SIT_TEST_STUBS == STD_ON))
volatile uint8 Fault_Xcp_Test_Stub = 0;
#endif
uint8 SWC_Appl_FaultMgr_NVblock[16];
const uint8 SWC_Appl_FaultMgr_DefaultValue[16] = {0};
volatile uint8_t Pcan_Timeout_Fault_Status     = CODED_TRUE;

/*===========================================================================*\
 * Static functions and variables
\*===========================================================================*/

/* This function is used for handling CAN bus off faults */
static void CAN_Bus_Off_Fault_Handling(void);
/* local static variables for setting the bus off faults */
uint8 VCAN_Diag_BusOffState = DIAG_TEST_NOT_COMPLETED;
uint8 PCAN_Diag_BusOffState = DIAG_TEST_NOT_COMPLETED;

/* Forward declarations for static fault handler functions (prototypes required
 * so functions can be called before their definitions without implicit
 * declaration errors under ISO C99 and strict compiler flags). */
static void Platform_Dtc_50ms(void);
static void Project_Dtc_50ms(void);
static void Application_Interface_Lookup_Dtc(void);
static void MMIC_Component_Internal_Failure_Dtc(void);
static void Radar_Calibration_Dtc(void);
static void Radar_MMIC_RFBIST_Dtc(void);
static void Radar_Performance_Capability_Dtc(void);
static void SMC_Checksum_Dtc(void);
static void Platform_Time_Sync_Dtc(void);
static void Radar_Module_Temperature_Dtc(void);
static void Radar_Module_Memory_Dtc(void);
static void External_Watchdog_Dtc(void);
static void Alignment_No_Initial_Calibration_Dtc(void);
static void Alignment_Sudden_Jump_Dtc(void);
static void Alignment_Out_Of_Range_Dtc(void);
static void Alignment_Critical_Misalignment_Dtc(void);
static void Alignment_Algo_Error_Dtc(void);
static void IPC_Faults_Dtc(void);
static void PCAN_Bus_Off_Dtc(void);
static void VCAN_Bus_Off_Dtc(void);
static void PCAN_Timeout_Dtc(void);
static void VCAN_SAS_Timeout_Dtc(void);
static void VCAN_CCVS1_Timeout_Dtc(void);
static void VCAN_VDC2_Timeout_Dtc(void);
static void VCAN_ETC2_MT_Timeout_Dtc(void);
static void VCAN_VD_Timeout_Dtc(void);
static void VCAN_TD_Timeout_Dtc(void);
static void VCAN_OEL_Timeout_Dtc(void);
static void VCAN_CLS_Tx_16_Timeout_Dtc(void);
static void VCAN_CLS_Tx_4_Timeout_Dtc(void);
static void VCAN_ETC2_AT_AMT_Timeout_Dtc(void);
static void VCAN_ADAS_FN_Enable_Disable_Timeout_Dtc(void);
static void Battery_Low_Volt_Dtc(void);
static void Battery_High_Volt_Dtc(void);
static void Dataset_CRC_Failure_Dtc(void);
static void Dataset_Unprogrammed_Dtc(void);
static void Project_Fault_50ms(void);
static void PinPosition_Mismatch_Fault(void);
static void PinPosition_Mismatch_Dtc(void);

boolean isHighPriorityfaultactive(FaultType faultname);
boolean isHighPriorityfaultQualified(FaultType faultname);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_PCAN_Timeout_Faults_Event.
 * @return void
 */
static void checkComRxTimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_VcanCCVS1_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_VDC2_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_ETC2_MT_Variant_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_ADAS_Function_Switch_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_SAS_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_OEL_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_TD_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_VD_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_CLS_Tx_16_TimeoutFault(void);

/**
 * @brief Checks COM RX timeout fault status and applies debouncing
 * @details Monitors CAN communication RX timeout conditions, applies configured filtering/debouncing,
 *          and updates internal fault counters. Called from RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event.
 * @return void
 */
static void Check_Vcan_CLS_TX_4_TimeoutFault(void);

static void Time_Synchronization_Dtc(void);
static void Time_Synchronization_Fault(void);
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
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 *   DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
 *   DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
 *   DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
 *   DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
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
 * Rte_DT_Idt_XCP_Fault_Override_T_0: Enumeration of integer in interval [0...255] with enumerators
 *   FAULT_OVERRIDE_AUTO_MODE (1U)
 *   FAULT_OVERRIDE_SET_FAULT_MODE (2U)
 *   FAULT_OVERRIDE_CLEAR_FAULT_MODE (3U)
 *
 * Array Types:
 * ============
 * Dt_Fault_T: Array with 16 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Idt_XCP_Fault_Override_T: Record with elements
 *   action of type Rte_DT_Idt_XCP_Fault_Override_T_0
 *   byte_pos of type uint8
 *   bit_pos of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PRJ_Appl_FaultMgr_START_SEC_CODE
#include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Control_DTC_Service_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_Control_DTC_Service>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Control_DTC_Service_Operation(uint8 Control)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Control_DTC_Service_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE)
CS_Control_DTC_Service_Operation(uint8 Control) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Control_DTC_Service_Operation
    *********************************************************************************************************************/
   if ((CONTROL_DTC_ON_FAULTMGR == Control))
   {
      /* Set Fault Enable Table */
      Platform_Fault_Enable_Table = (Platform_fault_T){PLATFORM_FAULT_ENABLE_TABLE_VALUES};
      Customer_Fault_Enable_Table = (Customer_fault_Latch_Enable_T){CUSTOMER_FAULT_ENABLE_TABLE_VALUES};
   }
   if ((CONTROL_DTC_OFF_FAULTMGR == Control))
   {
      /* Clear Fault Enable Table */
      (void)memset(&Platform_Fault_Enable_Table.Platform_byte, 0, sizeof(Platform_fault_T));
      (void)memset(&Customer_Fault_Enable_Table.Customer_byte, 0, sizeof(Customer_fault_Latch_Enable_T));
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PCAN_Timeout_Faults_Event
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Timeout_Status> of PortPrototype
 *<Rp_Alignment_Status_1_Com_Rx_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Timeout_Status> of PortPrototype
 *<Rp_Header_msg_Com_Rx_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Timeout_Status> of PortPrototype
 *<Rp_Radar_Capability_Com_Rx_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Timeout_Status> of PortPrototype
 *<Rp_Radar_Status_1_Com_Rx_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Timeout_Status> of PortPrototype
 *<Rp_Radar_Status_2_Com_Rx_Timeout_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PCAN_Timeout_Faults_Event_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PCAN_Timeout_Faults_Event(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PCAN_Timeout_Faults_Event
    *********************************************************************************************************************/
   /* PCAN_timeout fault check*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      checkComRxTimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(PCAN_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault = 1U;
      }
   }

   PCAN_Timeout_Dtc();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PRJ_FaultMgr_50ms
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
 *   Std_ReturnType Rte_Read_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_ActiveFaultTable_De_ActiveFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_FaultMngr_Vbatt_State_De_Vbatt_State(Dt_VBattState_T *data)
 *   Std_ReturnType Rte_Read_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Fault_Override_De_XCP_Fault_Override(Idt_XCP_Fault_Override_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_ActiveFaultTable_De_ActiveFaultTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_FaultEnableTable_De_FaultEnableTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_HistoryFaultTable_De_HistoryFaultTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PRJ_FaultMgr_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PRJ_FaultMgr_50ms
    *********************************************************************************************************************/

   Project_Fault_50ms();
   NvM_RequestResultType nvblock_status;
   uint8 byte_indx;
   static uint8 fault_table_updated = CODED_FALSE;
   Platform_fault_T *SWC_PLT_Appl_Fault_Enable_Table;
   Platform_fault_T *SWC_PLT_Appl_Fault_Test_Completed;
   Platform_fault_T *SWC_PLT_Appl_Active_Fault_Latch_Table;

   Customer_fault_T *SWC_Project_FaultMgr_NVblock = (Customer_fault_T *)&SWC_Appl_FaultMgr_NVblock;

   SWC_PLT_Appl_Fault_Test_Completed     = Get_Platform_Fault_Test_Completed_Table();
   SWC_PLT_Appl_Fault_Enable_Table       = Get_Platform_Fault_Enable_Table();
   SWC_PLT_Appl_Active_Fault_Table       = Get_Platform_Active_Fault_Table();
   SWC_PLT_Appl_Active_Fault_Latch_Table = Get_Platform_Active_Fault_Latch_Table();

   SWC_Appl_Active_Fault_Table         = Get_Customer_Active_Fault_Table();
   SWC_Appl_Active_Fault_Latched_Table = Get_Customer_Active_Fault_Latched_Table();
   SWC_Appl_Fault_Test_Completed       = Get_Customer_Fault_Test_Completed_Table();
   SWC_Appl_Fault_Enable_Table         = Get_Customer_Fault_Enable_Table();

   /*Copy from Tkey to Project table*/
   Platform_memory_Copy((void *)SWC_Appl_Active_Fault_Table, (void *)SWC_PLT_Appl_Active_Fault_Table, PLATFORM_FAULT_TABLE_SIZE);
   Platform_memory_Copy((void *)SWC_Appl_Active_Fault_Latched_Table, (void *)SWC_PLT_Appl_Active_Fault_Latch_Table,
                        PLATFORM_FAULT_TABLE_SIZE);
   Platform_memory_Copy((void *)SWC_Appl_Fault_Test_Completed, (void *)SWC_PLT_Appl_Fault_Test_Completed,
                        PLATFORM_FAULT_TABLE_SIZE);
   Platform_memory_Copy((void *)SWC_Appl_Fault_Enable_Table, (void *)SWC_PLT_Appl_Fault_Enable_Table, PLATFORM_FAULT_TABLE_SIZE);

   /*check if any new faults are detected*/
   for (byte_indx = 0u; byte_indx < PLATFORM_FAULT_TABLE_SIZE; byte_indx++)
   {
      /*To update the platform history fault table from the platform active fault table and store it in NVM*/
      if (SWC_PLT_Appl_Active_Fault_Table != NULL)
      {
         SWC_Appl_History_Fault_Table->Platform_byte[byte_indx] |= SWC_PLT_Appl_Active_Fault_Table->Platform_byte[byte_indx];
      }
      /*Check the difference between current and prev faults*/
      if (SWC_Project_FaultMgr_NVblock->Platform_byte[byte_indx] != SWC_Appl_History_Fault_Table->Platform_byte[byte_indx])
      {
         fault_table_updated = CODED_TRUE;
      }
   }

   /* Check NV block status first */
   NvM_GetErrorStatus((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_SWC_Appl_Faultmgr, &nvblock_status);
   if ((NVM_REQ_PENDING != nvblock_status) && (CODED_TRUE == fault_table_updated))
   {
      fault_table_updated = CODED_FALSE;
      Platform_memory_Copy((void *)SWC_Project_FaultMgr_NVblock, (void *)SWC_Appl_History_Fault_Table, PLATFORM_FAULT_TABLE_SIZE);
      /* Restored: DND-4333 IR-1473 Short term fix as this is causing reset ExceptionHandler_Abort_Data */
      NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_SWC_Appl_Faultmgr, NULL_PTR);
   }
#if ((ENABLE_SIT_TEST_STUBS == STD_ON))
   if (Fault_Xcp_Test_Stub == 1)
   {
      for (int i = 0; i < 16; i++)
      {
         SWC_Appl_Active_Fault_Latched_Table->Platform_byte[i] = 0xFF;
         SWC_Appl_Active_Fault_Table->Platform_byte[i]         = 0xFF;
         SWC_Appl_Fault_Enable_Table->Customer_byte[i]         = 0xFF;
         SWC_Appl_Fault_Test_Completed->Platform_byte[i]       = 0xFF;
         SWC_Appl_History_Fault_Table->Platform_byte[i]        = 0xFF;
      }
   }
#endif

   /* Provide the fault table to XCP and IPC */
   (void)Rte_Write_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable((uint8 *)SWC_Appl_Active_Fault_Latched_Table);
   (void)Rte_Write_Pp_ActiveFaultTable_De_ActiveFaultTable((uint8 *)SWC_Appl_Active_Fault_Table);
   (void)Rte_Write_Pp_FaultEnableTable_De_FaultEnableTable((uint8 *)SWC_Appl_Fault_Enable_Table);
   (void)Rte_Write_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable((uint8 *)SWC_Appl_Fault_Test_Completed);
   (void)Rte_Write_Pp_HistoryFaultTable_De_HistoryFaultTable((uint8 *)SWC_Appl_History_Fault_Table);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PRJ_FaultMgr_DEM_50ms
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
 *   Std_ReturnType Rte_Read_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(uint8 *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AT_or_AMT_ECU_ETC2_03_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Interface_Lookup_Performance_OR_incorrect_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Radar_MMIC_Component_Internal_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Algorithm_Signal_Calculation_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Misalignment_Performance_or_Incorrect_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Range_Alignment_or_Adjustment_Incorrect_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_High_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_Low_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Calibration_or_Parameter_Memory_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_ADAS_FN_STS_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_16_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_4_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_OEL_message_Missing_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_TD_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_CCVS1_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_ETC2_00_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_VD_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_ESC_ECU_VDC2_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Front_Left_Side_Radar_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Initial_Alignment_Missing_Calibration_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_MMIC_RFBIST_Component_or_System_Internal_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_General_Memory_Failure_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Over_Temperature_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_System_Internal_Failure_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Watchdog_or_Safety_Failure_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Mounting_Orientation_Incorrect_Assembly_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_PCAN_Communication_Bus_off_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Performance_Capability_Algorithm_Based_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Platform_Time_Sync_error_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SAS_ECU_SAS_message_Missing_Message_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SMC_General_Checksum_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Security_Access_0x27_Attempt_Threshold_Authentication_Failure_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Time_Synchronization_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_VCAN_Communication_Bus_off_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_DatasetNot_Configured_Fault_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_Dataset_Value_of_Signal_Protection_Calculation_Incorrect_Fault_SetEventStatus(Dem_EventStatusType
 *EventStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PRJ_FaultMgr_DEM_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_DEM_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PRJ_FaultMgr_DEM_50ms
    *********************************************************************************************************************/
   Platform_Dtc_50ms();

   Project_Dtc_50ms();

   /* Check pin position mismatch fault status. */
   PinPosition_Mismatch_Fault();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PRJ_FaultMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PRJ_FaultMgr_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PRJ_FaultMgr_Init
    *********************************************************************************************************************/

   Customer_fault_T *SWC_Project_FaultMgr_NVblock = (Customer_fault_T *)&SWC_Appl_FaultMgr_NVblock;
   SWC_Appl_History_Fault_Table                   = Get_Customer_History_Fault_Table();
   Platform_memory_Copy((void *)SWC_Appl_History_Fault_Table, (void *)SWC_Project_FaultMgr_NVblock, PLATFORM_FAULT_TABLE_SIZE);

   SWC_PLT_Appl_Fault_Test_Completed = Get_Platform_Fault_Test_Completed_Table();

   SWC_PRJ_Fault_Test_Completed = Get_Customer_Fault_Test_Completed_Table();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VCAN_Timeout_Faults_100ms_1000ms_Event
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_CLS_TX_16_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_CLS_TX_4_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Timeout_Status> of PortPrototype
 *<Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Timeout_Status> of PortPrototype
 *<Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_OEL_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_TD_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_VD_message_Non_Safety_Timeout_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCAN_Timeout_Faults_100ms_1000ms_Event_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE)
RE_VCAN_Timeout_Faults_100ms_1000ms_Event(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_VCAN_Timeout_Faults_100ms_1000ms_Event
    *********************************************************************************************************************/
   /*ETC2_MT_VARIANT_MESSAGE fault check 100ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_ETC2_MT_Variant_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(ETC2_MT_VARIANT_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_ETC2_MT_Timeout_Dtc();

   /*ETC2_AT_AMT_VARIANT_MESSAGE fault check 100ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_ETC2_AT_AMT_Timeout_Dtc();

   /*CLS_TX_4_MESSAGE fault check 100ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_CLS_TX_4_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[CLS_TX_4_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(CLS_TX_4_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_CLS_Tx_4_Timeout_Dtc();

   /*CLS_TX_16_MESSAGE fault check 100ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_CLS_Tx_16_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[CLS_TX_16_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(CLS_TX_16_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_CLS_Tx_16_Timeout_Dtc();

   /*OEL_MESSAGE fault check 100ms*/

   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_OEL_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[OEL_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(OEL_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_OEL_Timeout_Dtc();

   /*VD_MESSAGE fault check 100ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_VD_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[VD_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(VD_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.VD_message_timeout_fault = 1U;
      }
   }

   /*DTC*/
   VCAN_VD_Timeout_Dtc();

   /*TD_MESSAGE fault check 1000ms*/
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_TD_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[TD_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(TD_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.TD_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_TD_Timeout_Dtc();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Timeout_Status> of PortPrototype
 *<Rp_CCVS1_message_Vcan_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Non_Safety_Timeout_Status> of PortPrototype
 *<Rp_SAS_message_Non_Safety_Timeout_Status>
 *   - triggered on DataReceivedEvent for DataElementPrototype <De_Com_Rx_Vcan_Timeout_Status> of PortPrototype
 *<Rp_VDC2_message_Vcan_Safety_Timeout_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType
 *Rte_Read_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE)
RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event
    *********************************************************************************************************************/
   /*VDC2_Timeout fault check 10ms*/

   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_VDC2_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[VDC2_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(VDC2_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_VDC2_Timeout_Dtc();

   /* SAS_Timeout fault check 10ms*/

   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_SAS_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[SAS_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(SAS_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.SAS_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_SAS_Timeout_Dtc();

   /* CCVS1_Timeout fault check 20ms */
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_VcanCCVS1_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[CCVS1_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(CCVS1_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.CCVS1_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_CCVS1_Timeout_Dtc();

   /* ADAS_Function_Switch_Timeout fault check 50ms */
   if ((isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT) == false) &&
       (isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT) == false))
   {
      Check_Vcan_ADAS_Function_Switch_TimeoutFault();
   }
   else
   {
      if ((Plt_Fault_Table_Freeze != CODED_FALSE))
      {
         Fail_Count_Debounce[ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT] = 0;
         Clear_Fault_If_Enabled_and_Not_Latched(ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT);
         SWC_PRJ_Fault_Test_Completed->Customer_Bits.ADAS_Function_Switch_message_timeout_fault = 1U;
      }
   }
   /*DTC*/
   VCAN_ADAS_FN_Enable_Disable_Timeout_Dtc();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PRJ_Appl_FaultMgr_STOP_SEC_CODE
#include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*====================================================================================================================*\
* FUNCTION: CAN_Bus_Off_Fault_Handling
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: None
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Handles PCAN and VCAN bus-off fault diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void CAN_Bus_Off_Fault_Handling(void)
{
   /* Pointer to debouncing calibration limits (fail/pass counts) */
   const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;

   /* Fetch calibration parameters for Ethernet E2E debouncing thresholds.
      Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
   p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

/* ========================================================================== */
/*                      PCAN BUSOFF FAULT DIAGNOSTICS                         */
/* ========================================================================== */

/* Check if the PCAN Bus-Off fault diagnostic feature is enabled in configuration */
#if (TRUE == ENABLE_PCAN_BUSOFF_FAULT)

   /* Validate that the diagnostic cycle has finished to prevent false positives from transient states */
   if (DIAG_TEST_NOT_COMPLETED != PCAN_Diag_BusOffState)
   {
   /* --- UNFILTERED DETECTION PATH --- */
   /* Check if the system is configured to report faults instantly without debouncing */
   #if (NO_FILTER == ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE)
      /* Directly evaluate and log the fault state based on the immediate test outcome */
      Diag_No_Filter_Test(PCAN_Diag_BusOffState, (uint16)PCAN_BUSOFF_FAULT);
   #endif /* (NO_FILTER == ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE) */

   /* --- DEBOUNCED DETECTION PATH --- */
   /* Check if the system is configured to filter/debounce the fault signals */
   #if (DIAG_FILTER == ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE)
      /* Pass the test state, fault ID, calibrated error thresholds, and the
         dedicated RAM tracking counters to the diagnostics filtering engine */
      Diagnostics_Filter_Test(PCAN_Diag_BusOffState, (uint16)PCAN_BUSOFF_FAULT, (uint16)p_Diag_cal->pcan_busoff_fail_limit,
                              (uint16)p_Diag_cal->pcan_busoff_pass_limit,
                              (uint16 *)(&PRJ_Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT]),
                              (uint16 *)(&PRJ_Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT]));
   #endif /* (DIAG_FILTER == ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE) */
   }
#endif /* (TRUE == ENABLE_PCAN_BUSOFF_FAULT) */

/* ========================================================================== */
/*                      VCAN BUSOFF FAULT DIAGNOSTICS                         */
/* ========================================================================== */

/* Check if the VCAN Bus-Off fault diagnostic feature is enabled in configuration */
#if (TRUE == ENABLE_VCAN_BUSOFF_FAULT)

   /* Validate that the diagnostic cycle has finished to prevent false positives from transient states */
   if (DIAG_TEST_NOT_COMPLETED != VCAN_Diag_BusOffState)
   {
   /* --- UNFILTERED DETECTION PATH --- */
   /* Check if the system is configured to report faults instantly without debouncing */
   #if (NO_FILTER == ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE)
      /* Directly evaluate and log the fault state based on the immediate test outcome */
      Diag_No_Filter_Test(VCAN_Diag_BusOffState, (uint16)VCAN_BUSOFF_FAULT);
   #endif /* (NO_FILTER == ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE) */

   /* --- DEBOUNCED DETECTION PATH --- */
   /* Check if the system is configured to filter/debounce the fault signals */
   #if (DIAG_FILTER == ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE)
      /* Pass the test state, fault ID, calibrated error thresholds, and the
         dedicated RAM tracking counters to the diagnostics filtering engine */
      Diagnostics_Filter_Test(VCAN_Diag_BusOffState, (uint16)VCAN_BUSOFF_FAULT, (uint16)p_Diag_cal->vcan_busoff_fail_limit,
                              (uint16)p_Diag_cal->vcan_busoff_pass_limit,
                              (uint16 *)(&PRJ_Fail_Count_Debounce[VCAN_BUSOFF_FAULT_COUNT]),
                              (uint16 *)(&PRJ_Fail_Count_Debounce[VCAN_BUSOFF_FAULT_COUNT]));
   #endif /* (DIAG_FILTER == ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE) */
   }
#endif /* (TRUE == ENABLE_VCAN_BUSOFF_FAULT) */
}
/*====================================================================================================================*\
* FUNCTION: checkComRxTimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks PCAN communication receive timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void checkComRxTimeoutFault(void)
{
#if (TRUE == ENABLE_PCAN_RX_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t Alignment_Status_1_Status = CODED_TRUE;
   uint8_t Radar_Status_2_Status     = CODED_TRUE;
   uint8_t Radar_Status_1_Status     = CODED_TRUE;
   uint8_t Radar_Capability_Status   = CODED_TRUE;
   uint8_t Header_msg_Status         = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(&Alignment_Status_1_Status);
   Rte_Read_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(&Radar_Status_2_Status);
   Rte_Read_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(&Radar_Status_1_Status);
   Rte_Read_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(&Radar_Capability_Status);
   Rte_Read_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(&Header_msg_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if ((DIAG_TEST_NOT_COMPLETED != Alignment_Status_1_Status) || (DIAG_TEST_NOT_COMPLETED != Radar_Status_2_Status) ||
       (DIAG_TEST_NOT_COMPLETED != Radar_Status_1_Status) || (DIAG_TEST_NOT_COMPLETED != Radar_Capability_Status) ||
       (DIAG_TEST_NOT_COMPLETED != Header_msg_Status))
   {
      if (((Alignment_Status_1_Status != DIAG_TEST_PASS) || (Radar_Status_2_Status != DIAG_TEST_PASS) ||
           (Radar_Status_1_Status != DIAG_TEST_PASS) || (Radar_Capability_Status != DIAG_TEST_PASS) ||
           (Header_msg_Status != DIAG_TEST_PASS)))
      {
         Pcan_Timeout_Fault_Status = CODED_FALSE; /* Fault detected */
      }
      else
      {
         Pcan_Timeout_Fault_Status = CODED_TRUE; /* No Fault detected */
      }
   }

   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_PCAN_RX_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(Pcan_Timeout_Fault_Status, (uint16)PCAN_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by PCAN_RX_TIMEOUT_FAULT_COUNT. */
   #if (DIAG_FILTER == ENABLE_PCAN_RX_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;

      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         Pcan_Timeout_Fault_Status, (uint16)PCAN_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->pcan_message_timeout_fail_limit,
         (uint16)p_Diag_cal->pcan_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}

/*====================================================================================================================*\
* FUNCTION: Check_VcanCCVS1_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN CCVS1 timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_VcanCCVS1_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t CCVS1_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(&CCVS1_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != CCVS1_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(CCVS1_message_Status, (uint16)CCVS1_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         CCVS1_message_Status, (uint16)CCVS1_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->CCVS1_message_timeout_fail_limit,
         (uint16)p_Diag_cal->CCVS1_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[CCVS1_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[CCVS1_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_VDC2_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN VDC2 timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_VDC2_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t VDC2_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(&VDC2_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != VDC2_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(VDC2_message_Status, (uint16)VDC2_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by VCAN_VDC2_MESSAGE_TIMEOUT_FAULT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         VDC2_message_Status, (uint16)VDC2_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->VDC2_message_timeout_fail_limit,
         (uint16)p_Diag_cal->VDC2_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[VDC2_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[VDC2_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_ETC2_MT_Variant_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN ETC2 MT variant timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_ETC2_MT_Variant_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t ETC2_MT_Variant_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(&ETC2_MT_Variant_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != ETC2_MT_Variant_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(ETC2_MT_Variant_message_Status, (uint16)ETC2_MT_VARIANT_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(ETC2_MT_Variant_message_Status, (uint16)ETC2_MT_VARIANT_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->ETC2_MT_Variant_message_timeout_fail_limit,
                              (uint16)p_Diag_cal->ETC2_MT_Variant_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN ETC2 AT/AMT variant timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t ETC2_AT_AMT_Variant_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(&ETC2_AT_AMT_Variant_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != ETC2_AT_AMT_Variant_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(ETC2_AT_AMT_Variant_message_Status, (uint16)ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(ETC2_AT_AMT_Variant_message_Status, (uint16)ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->ETC2_AT_AMT_Variant_message_timeout_fail_limit,
                              (uint16)p_Diag_cal->ETC2_AT_AMT_Variant_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}

/*====================================================================================================================*\
* FUNCTION: Check_Vcan_ADAS_Function_Switch_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN ADAS function switch timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_ADAS_Function_Switch_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t ADAS_Function_Switch_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      &ADAS_Function_Switch_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != ADAS_Function_Switch_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(ADAS_Function_Switch_message_Status, (uint16)ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(ADAS_Function_Switch_message_Status, (uint16)ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->ADAS_Function_Switch_message_timeout_fail_limit,
                              (uint16)p_Diag_cal->ADAS_Function_Switch_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_CLS_Tx_16_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN CLS Tx 16 timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_CLS_Tx_16_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t CLS_Tx_16_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&CLS_Tx_16_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != CLS_Tx_16_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(CLS_Tx_16_message_Status, (uint16)CLS_TX_16_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by CLS_TX_16_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(CLS_Tx_16_message_Status, (uint16)CLS_TX_16_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->CLS_Tx_16_message_timeout_fail_limit,
                              (uint16)p_Diag_cal->CLS_Tx_16_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[CLS_TX_16_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[CLS_TX_16_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}

/*====================================================================================================================*\
* FUNCTION: Check_Vcan_CLS_TX_4_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN CLS Tx 4 timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_CLS_TX_4_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t CLS_TX_4_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&CLS_TX_4_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != CLS_TX_4_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(CLS_TX_4_message_Status, (uint16)CLS_TX_4_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by CLS_TX_4_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         CLS_TX_4_message_Status, (uint16)CLS_TX_4_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->CLS_TX_4_message_timeout_fail_limit,
         (uint16)p_Diag_cal->CLS_TX_4_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[CLS_TX_4_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[CLS_TX_4_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_OEL_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN OEL timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_OEL_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t OEL_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&OEL_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != OEL_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(OEL_message_Status, (uint16)OEL_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by OEL_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         OEL_message_Status, (uint16)OEL_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->OEL_message_timeout_fail_limit,
         (uint16)p_Diag_cal->OEL_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[OEL_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[OEL_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}

/*====================================================================================================================*\
* FUNCTION: Check_Vcan_TD_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN TD timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_TD_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t TD_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&TD_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != TD_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(TD_message_Status, (uint16)TD_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by TD_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(TD_message_Status, (uint16)TD_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->TD_message_timeout_fail_limit, (uint16)p_Diag_cal->TD_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[TD_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[TD_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_VD_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN VD timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_VD_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t VD_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&VD_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != VD_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(VD_message_Status, (uint16)VD_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by TD_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(VD_message_Status, (uint16)VD_MESSAGE_TIMEOUT_FAULT,
                              (uint16)p_Diag_cal->VD_message_timeout_fail_limit, (uint16)p_Diag_cal->VD_message_timeout_pass_limit,
                              (uint16 *)(&Fail_Count_Debounce[VD_MESSAGE_TIMEOUT_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[VD_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Check_Vcan_SAS_TimeoutFault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: RTE timeout status and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Checks VCAN SAS timeout status and applies filtering.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Check_Vcan_SAS_TimeoutFault(void)
{
#if (TRUE == ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FAULT)
   /* Status variable to store the COM RX timeout diagnostic result.
      Initialized to CODED_TRUE as a safe default before RTE read. */
   uint8_t SAS_message_Status = CODED_TRUE;

   /* Read the COM RX timeout status from the RTE port.
      Expected values:
        - DIAG_TEST_PASS       : diagnostic passed (no timeout)
        - DIAG_TEST_NOT_COMPLETED : diagnostic not yet completed (do not evaluate)
        - DIAG_TEST_FAIL/CODED_TRUE : diagnostic failed (timeout fault detected)
      We ignore the Std_ReturnType and act on the out-parameter value. */
   Rte_Read_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(&SAS_message_Status);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != SAS_message_Status)
   {
   /* Fast path: no filtering configured -> set/clear fault immediately based on test result. */
   #if (NO_FILTER == ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FILTER_TYPE)
      Diag_No_Filter_Test(SAS_message_Status, (uint16)SAS_MESSAGE_TIMEOUT_FAULT);
   #endif

   /* Debounce path: apply configured fail/pass limits from calibration.
      Behavior:
        - On repeated timeouts beyond fail_limit, the fault is asserted.
        - On repeated passes beyond pass_limit, the fault is cleared.
      The filter function updates internal counters stored in Fail_Count_Debounce
      and PRJ_Pass_Count_Debounce indexed by SAS_MESSAGE_TIMEOUT_COUNT. */
   #if (DIAG_FILTER == ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FILTER_TYPE)
      /* Pointer to debouncing calibration limits (fail/pass counts) */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetch calibration parameters for timeout debouncing thresholds.
         Assumes Get_Diag_PLT_Debouncing_Cal() returns a valid pointer when this feature is enabled. */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();

      /* Apply diagnostic filter with debouncing logic using calibrated thresholds. */
      Diagnostics_Filter_Test(
         SAS_message_Status, (uint16)SAS_MESSAGE_TIMEOUT_FAULT, (uint16)p_Diag_cal->SAS_message_timeout_fail_limit,
         (uint16)p_Diag_cal->SAS_message_timeout_pass_limit, (uint16 *)(&Fail_Count_Debounce[SAS_MESSAGE_TIMEOUT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[SAS_MESSAGE_TIMEOUT_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Proj_Battery_Fault_Tests_50ms
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Battery state and fault diagnostic interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Executes project battery fault tests.
* PRECONDITIONS: None
\*====================================================================================================================*/
void Proj_Battery_Fault_Tests_50ms(void)
{
#if ((TRUE == ENABLE_PRJ_BATTERY_HIGH_FAULT) || (TRUE == ENABLE_PRJ_BATTERY_LOW_FAULT))
   Dt_VBattState_T Project_vbatt_state;
   Rte_Read_Rp_FaultMngr_Vbatt_State_De_Vbatt_State(&Project_vbatt_state);

   Prj_Battery_Low_Fault(Project_vbatt_state);
   Prj_Battery_High_Fault(Project_vbatt_state);

#endif
}
volatile uint8_t Project_battery_low_flt_sts;
/*====================================================================================================================*\
* FUNCTION: Prj_Battery_Low_Fault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: Project_vbatt_state - current battery voltage state
* EXTERNAL REFERENCES: Project fault tables and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Evaluates and filters the project battery low-voltage fault.
* PRECONDITIONS: None
\*====================================================================================================================*/
void Prj_Battery_Low_Fault(Dt_VBattState_T Project_vbatt_state)
{
   if ((LO_V1 == Project_vbatt_state) || (LO_V2 == Project_vbatt_state) || (LO_V1_TONORM == Project_vbatt_state) ||
       (LO_V2_TONORM == Project_vbatt_state))
   {
      Project_battery_low_flt_sts = DIAG_TEST_FAIL;
   }
   else
   {
      Project_battery_low_flt_sts = DIAG_TEST_PASS;
   }

   if (DIAG_TEST_NOT_COMPLETED != Project_battery_low_flt_sts)
   {
/* Filters for Setting the fault*/
#if (NO_FILTER == ENABLE_PRJ_BATTERY_LOW_FAULT_FILTER_TYPE)
      Diag_No_Filter_Test(Project_battery_low_flt_sts, (uint16)PRJ_BATTERY_LOW_FAULT);
#elif (DIAG_FILTER == ENABLE_PRJ_BATTERY_LOW_FAULT_FILTER_TYPE)
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();
      Diagnostics_Filter_Test(
         Project_battery_low_flt_sts, (uint16)PRJ_BATTERY_LOW_FAULT, (uint16)p_Diag_cal->Prj_Battery_Low_fault_fail_limit,
         (uint16)p_Diag_cal->Prj_Battery_Low_fault_pass_limit, (uint16 *)(&Fail_Count_Debounce[PRJ_BATTERY_LOW_FAULT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[PRJ_BATTERY_LOW_FAULT_COUNT]));
#endif
   }
}
volatile uint8_t Project_battery_high_flt_sts;
/*====================================================================================================================*\
* FUNCTION: Prj_Battery_High_Fault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: Project_vbatt_state - current battery voltage state
* EXTERNAL REFERENCES: Project fault tables and diagnostic filtering interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Evaluates and filters the project battery high-voltage fault.
* PRECONDITIONS: None
\*====================================================================================================================*/
void Prj_Battery_High_Fault(Dt_VBattState_T Project_vbatt_state)
{
   if ((HI_V1 == Project_vbatt_state) || (HI_V2 == Project_vbatt_state) || (HI_V1_TONORM == Project_vbatt_state) ||
       (HI_V2_TONORM == Project_vbatt_state))
   {
      Project_battery_high_flt_sts = DIAG_TEST_FAIL;
   }
   else
   {
      Project_battery_high_flt_sts = DIAG_TEST_PASS;
   }

   if (DIAG_TEST_NOT_COMPLETED != Project_battery_high_flt_sts)
   {
/* Filters for Setting the fault*/
#if (NO_FILTER == ENABLE_PRJ_BATTERY_HIGH_FAULT_FILTER_TYPE)
      Diag_No_Filter_Test(Project_battery_high_flt_sts, (uint16)PRJ_BATTERY_HIGH_FAULT);
#elif (DIAG_FILTER == ENABLE_PRJ_BATTERY_HIGH_FAULT_FILTER_TYPE)
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();
      Diagnostics_Filter_Test(
         Project_battery_high_flt_sts, (uint16)PRJ_BATTERY_HIGH_FAULT, (uint16)p_Diag_cal->Prj_Battery_High_fault_fail_limit,
         (uint16)p_Diag_cal->Prj_Battery_High_fault_pass_limit, (uint16 *)(&Fail_Count_Debounce[PRJ_BATTERY_HIGH_FAULT_COUNT]),
         (uint16 *)(&PRJ_Pass_Count_Debounce[PRJ_BATTERY_HIGH_FAULT_COUNT]));
#endif
   }
}

/*====================================================================================================================*\
* FUNCTION: App_DemCbkEventStatus_PCAN_BusOffFault
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
* PARAMETERS: EventStatusOld, EventStatusNew - previous and current DEM status
* EXTERNAL REFERENCES: PCAN bus-off diagnostic state
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Updates the PCAN bus-off diagnostic state from the DEM status.
* PRECONDITIONS: None
\*====================================================================================================================*/
Std_ReturnType App_DemCbkEventStatus_PCAN_BusOffFault(uint8_t EventStatusOld, uint8_t EventStatusNew)
{
   if ((EventStatusNew & 0x01) == 0x01)
   {
      PCAN_Diag_BusOffState = DIAG_TEST_FAIL;
   }
   else
   {
      PCAN_Diag_BusOffState = DIAG_TEST_PASS;
   }
   return E_OK;
}

/*====================================================================================================================*\
* FUNCTION: App_DemCbkEventStatus_VCAN_BusOffFault
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
* PARAMETERS: EventStatusOld, EventStatusNew - previous and current DEM status
* EXTERNAL REFERENCES: VCAN bus-off diagnostic state
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Updates the VCAN bus-off diagnostic state from the DEM status.
* PRECONDITIONS: None
\*====================================================================================================================*/
Std_ReturnType App_DemCbkEventStatus_VCAN_BusOffFault(uint8_t EventStatusOld, uint8_t EventStatusNew)
{
   if ((EventStatusNew & 0x01) == 0x01)
   {
      VCAN_Diag_BusOffState = DIAG_TEST_FAIL;
   }
   else
   {
      VCAN_Diag_BusOffState = DIAG_TEST_PASS;
   }
   return E_OK;
}

/*====================================================================================================================*\
* FUNCTION: PinPosition_Mismatch_Fault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: None
* DEVIATIONS FROM STANDARDS: None
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* This function reads the sensor mounting pin position mismatch diagnostic status and applies filtering based on
* configuration (NO_FILTER for immediate, DIAG_FILTER for debounced). The fault bit at customer fault byte 16, bit 0
* is managed accordingly.
*
* PRECONDITIONS: None
*
\*====================================================================================================================*/
static void PinPosition_Mismatch_Fault(void)
{
#if (TRUE == ENABLE_PIN_POSITION_MISMATCH_FAULT)
   uint8 pinposition_mismatch_fault_sts = DIAG_TEST_NOT_COMPLETED;

   (void)Rte_Read_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(&pinposition_mismatch_fault_sts);

   /* Only evaluate when the diagnostic has completed to avoid reacting to transient states. */
   if (DIAG_TEST_NOT_COMPLETED != pinposition_mismatch_fault_sts)
   {
   #if (NO_FILTER == ENABLE_PIN_POSITION_MISMATCH_FAULT_FILTER_TYPE)
      Diag_No_Filter_Test(pinposition_mismatch_fault_sts, (uint16)PIN_POSITION_FAULT);
   #endif
   #if (DIAG_FILTER == ENABLE_PIN_POSITION_MISMATCH_FAULT_FILTER_TYPE)
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();
      Diagnostics_Filter_Test(pinposition_mismatch_fault_sts, (uint16)PIN_POSITION_FAULT,
                              (uint16)p_Diag_cal->pinposition_mismatch_fault_fail_limit,
                              (uint16)p_Diag_cal->pinposition_mismatch_fault_pass_limit,
                              (uint16 *)(&PRJ_Fail_Count_Debounce[PIN_POSITION_MISMATCH_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[PIN_POSITION_MISMATCH_COUNT]));
   #endif
   }
#endif
}

/*====================================================================================================================*\
* FUNCTION: isHighPriorityfaultactive
*=======================================================================================================================
* RETURN VALUE: boolean
* PARAMETERS: faultname - fault type to evaluate
* EXTERNAL REFERENCES: Customer active fault table
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Determines whether a higher-priority fault is active.
* PRECONDITIONS: None
\*====================================================================================================================*/
boolean isHighPriorityfaultactive(FaultType faultname)
{
   boolean is_high_priority_fault_active = false;

   switch (faultname)
   {
      case FAULT_SIGNAL_ERROR_INVALID_DATA:
         is_high_priority_fault_active = Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault;
         break;

      case FAULT_ERRATIC_COMMUNICATION_ABNORMAL:
         is_high_priority_fault_active = Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault;
         break;
      case FAULT_E2E:
         is_high_priority_fault_active = Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault;
         break;
      case FAULT_MESSAGE_TIMEOUT:
         is_high_priority_fault_active = Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault ||
                                         Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault;
         break;

      case FAULT_BUSOFF:
         is_high_priority_fault_active = false; // Nothing has higher priority
         break;

      default:
         break;
   }

   return is_high_priority_fault_active;
}
/**
 * @brief Determines if a fault is qualified based on higher priority faults
 *
 * @details This function evaluates whether a given fault type is qualified by checking
 * the debounce counters of higher priority faults. A fault is considered qualified if
 * at least one of its higher priority fault conditions has exceeded the debounce threshold.
 *
 * The priority hierarchy is:
 * - SECOC (highest priority)
 * - MESSAGE_TIMEOUT
 * - E2E
 * - SIGNAL_IMPLAUSIBLE (lowest priority)
 *
 * @param[in] faultname The fault type to evaluate
 * @return boolean
 *         - TRUE: The fault is qualified (one or more higher priority faults are active)
 *         - FALSE: The fault is not qualified or is the highest priority fault
 *
 * @note FAULT_SECOC always returns FALSE as it has the highest priority with no higher
 *       priority faults to check
 *
 * @see Tkey_Fail_Count_Debounce
 * @see FaultType
 */
/*====================================================================================================================*\
* FUNCTION: isHighPriorityfaultQualified
*=======================================================================================================================
* RETURN VALUE: boolean
* PARAMETERS: faultname - fault type to evaluate
* EXTERNAL REFERENCES: Fault debounce counters
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Determines whether a higher-priority fault is qualified.
* PRECONDITIONS: None
\*====================================================================================================================*/
boolean isHighPriorityfaultQualified(FaultType faultname)
{
   /* Check if PCAN bus off fault has exceeded its debounce threshold.
      A non-zero fail count indicates the bus-off condition has been consistently detected.
      This is the highest priority fault. */
   boolean busoff_qualified = false;
   if ((Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT] > 0) || (Fail_Count_Debounce[VCAN_BUSOFF_FAULT_COUNT] > 0))
   {
      busoff_qualified = true;
   }

   /* Check if PCAN and VCAN  RX timeout fault has exceeded its debounce threshold.
      A non-zero fail count indicates the timeout condition has been consistently detected. */
   boolean timeout_qualified = false;

   if ((Fail_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT] > 0) || (Fail_Count_Debounce[CLS_TX_4_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[CLS_TX_16_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT] > 0) || (Fail_Count_Debounce[VDC2_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[CCVS1_MESSAGE_TIMEOUT_COUNT] > 0) || (Fail_Count_Debounce[OEL_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[TD_MESSAGE_TIMEOUT_COUNT] > 0) || (Fail_Count_Debounce[VD_MESSAGE_TIMEOUT_COUNT] > 0) ||
       (Fail_Count_Debounce[SAS_MESSAGE_TIMEOUT_COUNT] > 0))
   {
      timeout_qualified = true;
   }

   boolean erratic_communication_abnormal_qualified = false;

   /* Check if CAN E2E (End-to-End) fault has exceeded its debounce threshold.
      A non-zero fail count indicates repeated E2E protection failures. */
   boolean e2e_qualified = false;

   boolean is_high_priority_fault_qualified = false;

   switch (faultname)
   {
      /* For implausible signal faults (lowest priority):
         Qualified if any higher priority fault (bus-off, timeout, or E2E) is qualified.
         These faults are suppressed when higher priority communication faults are active. */
      case FAULT_SIGNAL_ERROR_INVALID_DATA:
         is_high_priority_fault_qualified =
            busoff_qualified || timeout_qualified || e2e_qualified || erratic_communication_abnormal_qualified;
         break;

      /* For implausible signal faults (lowest priority):
         Qualified if any higher priority fault (bus-off, timeout, or E2E) is qualified.
         These faults are suppressed when higher priority communication faults are active. */
      case FAULT_ERRATIC_COMMUNICATION_ABNORMAL:
         is_high_priority_fault_qualified = busoff_qualified || timeout_qualified || e2e_qualified;
         break;
      /* For E2E faults (medium-low priority):
         Qualified if any higher priority fault (bus-off or timeout) is qualified.
         E2E checks are suppressed when bus-off or timeout faults are detected. */
      case FAULT_E2E:
         is_high_priority_fault_qualified = busoff_qualified || timeout_qualified;
         break;

      /* For message timeout faults (medium-high priority):
         Qualified only if the highest priority fault (bus-off) is qualified.
         Timeout detection is suppressed only by bus-off faults. */
      case FAULT_MESSAGE_TIMEOUT:
         is_high_priority_fault_qualified = busoff_qualified;
         break;

      /* For bus-off faults (highest priority):
         Nothing has higher priority, so always returns not qualified. */
      case FAULT_BUSOFF:
         is_high_priority_fault_qualified = false; // Nothing has higher priority
         break;

      /* Default case: Unknown fault type - return not qualified (safe default). */
      default:
         break;
   }

   return is_high_priority_fault_qualified;
}

/*====================================================================================================================*\
* FUNCTION: Time_Synchronization_Fault
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: None
* DEVIATIONS FROM STANDARDS: None
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* This function is called to check Time_Synchronization_Fault
*
*
*
\*====================================================================================================================*/
static void Time_Synchronization_Fault(void)
{
   uint8 Time_Synchronization_fault_Status = DIAG_TEST_PASS;

#if (TRUE == ENABLE_TIME_SYNCHRONIZATION_FAULT)
   Rte_Read_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status(&Time_Synchronization_fault_Status);
   if (DIAG_TEST_NOT_COMPLETED != Time_Synchronization_fault_Status)
   {
   /* Filters for Setting the fault*/
   #if (NO_FILTER == ENABLE_TIME_SYNCHRONIZATION_FAULT_FILTER_TYPE)
      Diag_No_Filter_Test(Time_Synchronization_fault_Status, (uint16)TIME_SYNCHRONIZATION_FAULT);
   #endif
   /* Filters for Setting the fault*/
   #if (DIAG_FILTER == ENABLE_TIME_SYNCHRONIZATION_FAULT_FILTER_TYPE)
      /* Declaring the local pointer for fetching the calibration for debouncing */
      const Diag_PLT_Debouncing_Cal_T *p_Diag_cal;
      /* Fetching the pointer for diag calibration structure */
      p_Diag_cal = Get_Diag_PLT_Debouncing_Cal();
      Diagnostics_Filter_Test(Time_Synchronization_fault_Status, (uint16)TIME_SYNCHRONIZATION_FAULT,
                              (uint16)p_Diag_cal->Time_Synchronization_Fault_Fail_Limit,
                              (uint16)p_Diag_cal->Time_Synchronization_Fault_Pass_Limit,
                              (uint16 *)(&PRJ_Fail_Count_Debounce[TIME_SYNCHRONIZATION_COUNT]),
                              (uint16 *)(&PRJ_Pass_Count_Debounce[TIME_SYNCHRONIZATION_COUNT]));
   #endif
   }
#endif
}
/*====================================================================================================================*\
* FUNCTION: Project_Fault_50ms
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: None
* DEVIATIONS FROM STANDARDS: None
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* This function is called to call all the project specific fault functions which are to be called every 50ms
*
*
*
\*====================================================================================================================*/
static void Project_Fault_50ms(void)
{
   Proj_Battery_Fault_Tests_50ms();

   Time_Synchronization_Fault();
}

/*====================================================================================================================*\
* FUNCTION: Platform_Dtc_50ms
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault tables and DEM interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports platform diagnostic trouble codes.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Platform_Dtc_50ms(void)
{
   /* Blockage Algo, Damping Algo, Range Algo, SLL Monitoring Algo Errors */
   Radar_Performance_Capability_Dtc();

   /* API_Look_Config_Fault, API_Look_Trigger_Fault, API_Look_Complete_Fault */
   Application_Interface_Lookup_Dtc();

   /* MMIC Sensor Dead Fault, MMIC Safe Start Fault, Safety Integrity Fault,
    * MMIC Secondary MIPI/Clock/Register/MCU Fault */
   MMIC_Component_Internal_Failure_Dtc();

   /* USC Validation Fault, MMIC A ID Fault */
   Radar_Calibration_Dtc();

   /* MMIC Secondary Tx/Rx RFBIST Failure */
   Radar_MMIC_RFBIST_Dtc();

   /* SMC Checksum Fault */
   SMC_Checksum_Dtc();

   /* Platform time fault */
   Platform_Time_Sync_Dtc();

   /* MMIC High Temp fault, MMIC Low Temp fault */
   Radar_Module_Temperature_Dtc();

   /* MCU Repetitive Reset Fault */
   Radar_Module_Memory_Dtc();

   /* External Watchdog Fault */
   External_Watchdog_Dtc();

   /* Alignment No Initial Calibration Fault */
   Alignment_No_Initial_Calibration_Dtc();

   /* Alignment AutoAlignment Sudden Jump Detection Fault */
   Alignment_Sudden_Jump_Dtc();

   /* Alignment AutoAlignment Out Of Range Fault */
   Alignment_Out_Of_Range_Dtc();

   /* Alignment AutoAlignment Critical Misalignment Fault */
   Alignment_Critical_Misalignment_Dtc();

   /* Alignment AutoAlignment Algo Error Fault */
   Alignment_Algo_Error_Dtc();

   /* BBE to R52 IPC Fault, R52 to BBE IPC Fault */
   IPC_Faults_Dtc();
}
/*====================================================================================================================*\
* FUNCTION: Project_Dtc_50ms
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Project fault tables and DEM interfaces
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports project diagnostic trouble codes.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Project_Dtc_50ms(void)
{
   PCAN_Bus_Off_Dtc();
   VCAN_Bus_Off_Dtc();
   CAN_Bus_Off_Fault_Handling();
   Battery_Low_Volt_Dtc();
   Battery_High_Volt_Dtc();
   Dataset_CRC_Failure_Dtc();
   Dataset_Unprogrammed_Dtc();

   Time_Synchronization_Dtc();
   PinPosition_Mismatch_Dtc();
}
/*====================================================================================================================*\
* FUNCTION: Radar_Performance_Capability_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the radar performance capability diagnostic status.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Radar_Performance_Capability_Dtc(void)
{
   /* RADAR_Blockage_Algo_error_fault &  RADAR_Damping_Algo_error_fault & RADAR_Range_Algo_error_fault &
    * RADAR_SLL_Monitoring_error_fault*/

   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Performance_Capability_Algorithm_Based_Failure_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.blockage_algo_error_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.damping_algo_error_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.range_algo_error_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.sll_monitoring_algo_error)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(BLOCKAGE_ALGO_ERROR_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(DAMPING_ALGO_ERROR_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(RANGE_ALGO_ERROR_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(SLL_MONITORING_ALGO_ERROR_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Application_Interface_Lookup_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the application interface lookup diagnostic status.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Application_Interface_Lookup_Dtc(void)
{
   /* API_Look_Config_Fault, API_Look_Trigger_Fault, API_Look_Complete_Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Interface_Lookup_Performance_OR_incorrect_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.api_look_config_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.api_look_trigger_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.api_look_complete_fault)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(API_LOOK_CONFIG_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(API_LOOK_TRIGGER_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(API_LOOK_COMPLETE_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: MMIC_Component_Internal_Failure_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports MMIC component internal failure diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void MMIC_Component_Internal_Failure_Dtc(void)
{
   /* MMIC Sensor Dead, MMIC Safe Start, Safety Integrity, MMIC Secondary MIPI/Clock/Register/MCU */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Radar_MMIC_Component_Internal_Failure_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_a_sensor_dead_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_safe_start_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.safety_integrity_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_secondary_mipi_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_secondary_clock_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_secondary_register_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_secondary_mcu_fault)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_A_SENSOR_DEAD_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_SAFE_START_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(SAFETY_INTEGRITY_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_SECONDARY_MIPI_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_SECONDARY_CLOCK_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_SECONDARY_REGISTER_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_SECONDARY_MCU_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Radar_Calibration_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports radar calibration diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Radar_Calibration_Dtc(void)
{
   /* USC Validation Fault, MMIC A ID Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Calibration_or_Parameter_Memory_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.usc_validation_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_transmitter_id_fault)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(USC_VALIDATION_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_TRANSMITTER_ID_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Radar_MMIC_RFBIST_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports radar MMIC RFBIST diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Radar_MMIC_RFBIST_Dtc(void)
{
   /* MMIC Secondary Tx/Rx RFBIST Failure */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_MMIC_RFBIST_Component_or_System_Internal_Failure_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.rfe_tx_rfbist_err) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.rfe_rx_rfbist_err)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(RFE_TX_RFBIST_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(RFE_RX_RFBIST_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: SMC_Checksum_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports SMC checksum diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void SMC_Checksum_Dtc(void)
{
   /* SMC Checksum Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SMC_General_Checksum_Failure_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.smc_validtn_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(SMC_VALIDTN_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Platform_Time_Sync_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports platform time synchronization diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Platform_Time_Sync_Dtc(void)
{
   /* Platform time fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Platform_Time_Sync_error_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.platform_time_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(PLATFORM_TIME_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                  DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Radar_Module_Temperature_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports radar module temperature diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Radar_Module_Temperature_Dtc(void)
{
   /* MMIC High Temp, MMIC Low Temp */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Over_Temperature_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_temperature_high_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mmic_temperature_low_fault)) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_TEMPERATURE_HIGH_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MMIC_TEMPERATURE_LOW_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Radar_Module_Memory_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports radar module memory diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Radar_Module_Memory_Dtc(void)
{
   /* MCU Repetitive Reset Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_General_Memory_Failure_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mcu_repetitive_reset_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(MCU_REPETITIVE_RESET_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                         DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: External_Watchdog_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports external watchdog diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void External_Watchdog_Dtc(void)
{
   /* External Watchdog Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Watchdog_or_Safety_Failure_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.external_watchdog_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(EXTERNAL_WATCHDOG_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                      DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Alignment_No_Initial_Calibration_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the initial alignment calibration diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Alignment_No_Initial_Calibration_Dtc(void)
{
   /* Alignment No Initial Calibration Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Initial_Alignment_Missing_Calibration_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.alignment_no_initial_calibration_error_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                     DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Alignment_Sudden_Jump_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the alignment sudden-jump diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Alignment_Sudden_Jump_Dtc(void)
{
   /* Alignment AutoAlignment Sudden Jump Detection Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Mounting_Orientation_Incorrect_Assembly_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.alignment_autoalignment_sudden_jump_detection_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                        DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Alignment_Out_Of_Range_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the alignment out-of-range diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Alignment_Out_Of_Range_Dtc(void)
{
   /* Alignment AutoAlignment Out Of Range Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Range_Alignment_or_Adjustment_Incorrect_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.alignment_autoalignment_out_of_range_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                    DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Alignment_Critical_Misalignment_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the critical alignment misalignment diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Alignment_Critical_Misalignment_Dtc(void)
{
   /* Alignment AutoAlignment Critical Misalignment Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Misalignment_Performance_or_Incorrect_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.autoalignment_critical_misalignment_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(AUTOALIGNMENT_CRITICAL_MISALIGNMENT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                        DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: Alignment_Algo_Error_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the alignment algorithm error diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Alignment_Algo_Error_Dtc(void)
{
   /* Alignment AutoAlignment Algo Error Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Algorithm_Signal_Calculation_Failure_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.alignment_autoalignment_algo_error_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(ALIGNMENT_AUTOALIGN_ALGO_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                             DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: IPC_Faults_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Platform fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports inter-processor communication diagnostics.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void IPC_Faults_Dtc(void)
{
   /* BBE to R52 and R52 to BBE IPC Faults */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_System_Internal_Failure_Fault_SetEventStatus(
      (((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.bbe_to_r52_ipc_fault) &&
       ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.r52_to_bbe_ipc_fault)) &&
            ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.signal_integrity_fault) &&
            ((uint8)TRUE == SWC_PLT_Appl_Fault_Test_Completed->Platform_Bits.mcu_startup_fault) ?
         (((uint8)CODED_TRUE == Platform_Get_Fault_Status(BBE_TO_R52_IPC_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(R52_TO_BBE_IPC_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(SIGNAL_INTEGRITY_FAULT)) ||
          ((uint8)CODED_TRUE == Platform_Get_Fault_Status(MCU_STARTUP_FAULT))) ?
         DEM_EVENT_STATUS_FAILED :
         DEM_EVENT_STATUS_PASSED :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: PCAN_Bus_Off_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the PCAN bus-off diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void PCAN_Bus_Off_Dtc(void)
{
   // The PCAN Bus Off Fault is not currently implemented in the project fault management module, so this function is a placeholder
   // for future implementation.
   /* PCAN Bus Off Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_PCAN_Communication_Bus_off_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.pcan_bus_off_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(PCAN_BUSOFF_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_Bus_Off_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN bus-off diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_Bus_Off_Dtc(void)
{ // VCAN Bus Off Fault failure is not currently implemented in the platform fault management module, so this function is a
  // placeholder for future implementation
   /* VCAN Bus Off Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_VCAN_Communication_Bus_off_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.vcan_bus_off_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(VCAN_BUSOFF_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
static void Time_Synchronization_Dtc(void)
{
   /* Time Synchronization Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Time_Synchronization_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.Time_Synchronization_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(TIME_SYNCHRONIZATION_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                         DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: PCAN_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the PCAN timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void PCAN_Timeout_Dtc(void)
{
   /* PCAN Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Front_Left_Side_Radar_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(PCAN_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                         DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_CCVS1_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN CCVS1 timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_CCVS1_Timeout_Dtc(void)
{
   /* VCAN CCVS1 Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_CCVS1_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.CCVS1_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(CCVS1_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                          DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_VDC2_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN VDC2 timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_VDC2_Timeout_Dtc(void)
{
   /* VCAN VDC2 Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_ESC_ECU_VDC2_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(VDC2_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                         DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_ETC2_MT_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN ETC2 MT timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_ETC2_MT_Timeout_Dtc(void)
{
   /* VCAN ETC2 MT Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_ETC2_00_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(ETC2_MT_VARIANT_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                    DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_ETC2_AT_AMT_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN ETC2 AT/AMT timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_ETC2_AT_AMT_Timeout_Dtc(void)
{
   /* VCAN ETC2 AT/AMT Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AT_or_AMT_ECU_ETC2_03_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                        DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: VCAN_ADAS_FN_Enable_Disable_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN ADAS function switch timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_ADAS_FN_Enable_Disable_Timeout_Dtc(void)
{
   /* VCAN ADAS FN Enable/Disable Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_ADAS_FN_STS_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.ADAS_Function_Switch_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                         DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_CLS_Tx_16_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN CLS Tx 16 timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_CLS_Tx_16_Timeout_Dtc(void)
{
   /* VCAN CLS Tx 16 Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_16_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(CLS_TX_16_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                              DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_CLS_Tx_4_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN CLS Tx 4 timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_CLS_Tx_4_Timeout_Dtc(void)
{
   /* VCAN CLS Tx 4 Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_4_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(CLS_TX_4_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                             DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_OEL_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN OEL timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_OEL_Timeout_Dtc(void)
{
   /* VCAN OEL Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_OEL_message_Missing_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(OEL_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                        DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_TD_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN TD timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_TD_Timeout_Dtc(void)
{
   /* VCAN TD Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_TD_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.TD_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(TD_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                       DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_VD_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN VD timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_VD_Timeout_Dtc(void)
{
   /* VCAN VD Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_VD_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.VD_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(VD_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                       DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: VCAN_SAS_Timeout_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the VCAN SAS timeout diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void VCAN_SAS_Timeout_Dtc(void)
{
   /* VCAN SAS Message Timeout Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SAS_ECU_SAS_message_Missing_Message_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.SAS_message_timeout_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(SAS_MESSAGE_TIMEOUT_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                        DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: Battery_High_Volt_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the battery high-voltage diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Battery_High_Volt_Dtc(void)
{
   /* Battery High Volt Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_High_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.Prj_Battery_High_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(PRJ_BATTERY_HIGH_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                     DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
/*====================================================================================================================*\
* FUNCTION: Battery_Low_Volt_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the battery low-voltage diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void Battery_Low_Volt_Dtc(void)
{
   /* Battery Low Volt Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_Low_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.Prj_Battery_Low_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(PRJ_BATTERY_LOW_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                    DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}
static void Dataset_CRC_Failure_Dtc(void)
{
   /* TODO: always reports PASSED for now - main.c does not yet set/clear or complete this fault (no valid CRC check source) */
   (void)
      Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_Dataset_Value_of_Signal_Protection_Calculation_Incorrect_Fault_SetEventStatus(
         ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.dataset_crc_failure_fault) ?
            (((uint8)CODED_TRUE == Customer_Get_Fault_Status((uint16)PRJ_DATASET_CRC_FAILURE_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                       DEM_EVENT_STATUS_PASSED) :
            DEM_EVENT_STATUS_PASSED);
}

static void Dataset_Unprogrammed_Dtc(void)
{
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_DatasetNot_Configured_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.dataset_unprogrammed_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status((uint16)PRJ_DATASET_UNPROGRAMMED_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                                     DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
}

/*====================================================================================================================*\
* FUNCTION: PinPosition_Mismatch_Dtc
*=======================================================================================================================
* RETURN VALUE: void
* PARAMETERS: void
* EXTERNAL REFERENCES: Customer fault status and DEM interface
* DEVIATIONS FROM STANDARDS: None
* ABSTRACT: Reports the pin-position mismatch diagnostic.
* PRECONDITIONS: None
\*====================================================================================================================*/
static void PinPosition_Mismatch_Dtc(void)
{
   /* Pin Position Mismatch Fault */
   (void)Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Radar_Pin_Position_Wrong_Mounting_Position_Fault_SetEventStatus(
      ((uint8)TRUE == SWC_PRJ_Fault_Test_Completed->Customer_Bits.pin_position_fault) ?
         (((uint8)CODED_TRUE == Customer_Get_Fault_Status(PIN_POSITION_FAULT)) ? DEM_EVENT_STATUS_FAILED :
                                                                                 DEM_EVENT_STATUS_PASSED) :
         DEM_EVENT_STATUS_PASSED);
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
