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
 *             File:  SWC_PLT_Appl_FaultMgr.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_FaultMgr
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_FaultMgr>
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
 * Runnable Entities:
 * ==================
 * RE_PLT_Fault_Mgr_Init
 *   This runnable will initialize all the static variables of this SWC
 *
 *
 * RE_PLT_Fault_Mgr_Main_10ms
 *   This function will be used to do timeout of the Missing signal with periodicity 10 and 20ms
 *      Signals are as fallows:
 *      1. ATCU_A108C_FD
 *      2. FWS_R3C_FD
 *      3. ADAS_A109_FD
 *      4. VDC_A116C_FD
 *      5. VDC_A117C_FD
 *      6. STRG_A1C_FD
 *
 * RE_PLT_Fault_Mgr_Main_50ms
 *   All the functionalities which are related to 50ms diagnostics
 *      shall be run here
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_FaultMgr.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "NvM.h"
#include "SWC_Appl_FaultMgr_Cfg.h"
#include "SWC_PLT_Appl_FaultMgr.h"
/**********************************************************************************************************************\
 * #define constants
\**********************************************************************************************************************/
/* Local macros defined and used while setting the fault */
#define DELAY_60MS 12u

/**********************************************************************************************************************\
 *  Global Variables
\**********************************************************************************************************************/

/**********************************************************************************************************************\
 *  File Scope Variables
\**********************************************************************************************************************/

/**********************************************************************************************************************\
 * Structure And Type Definitions
\**********************************************************************************************************************/

/**********************************************************************************************************************\
 *  File Scope Prototypes
\**********************************************************************************************************************/

/**********************************************************************************************************************\
 *  External Object Prototypes
\**********************************************************************************************************************/

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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_Batt_Volt_Status_T: Enumeration of integer in interval [0...2] with enumerators
 *   BATT_NORMAL_VOLTAGE (0U)
 *   BATT_OVER_VOLTAGE (1U)
 *   BATT_LOW_VOLTAGE (2U)
 * Dt_DTC_Status_Type: Enumeration of integer in interval [0...255] with enumerators
 *   DIAG_TEST_FAIL (85U)
 *   DIAG_TEST_PASS (170U)
 *   DIAG_TEST_NOT_COMPLETED (0U)
 * Dt_ECUPosition: Enumeration of integer in interval [0.0...255] with enumerators
 *   RTE_ECU_POSITION_INVALID (0U)
 *   RTE_ECU_POSITION_REAR_LEFT (1U)
 *   RTE_ECU_POSITION_REAR_RIGHT (2U)
 *   RTE_ECU_POSITION_FRONT_RIGHT (3U)
 *   RTE_ECU_POSITION_FRONT_LEFT (4U)
 *   RTE_ECU_POSITION_ADC_HIGH_THRESHOLD (255U)
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
 * Dt_A2H_ErrorFlags: Record with elements
 *   blockage_data_checksum of type uint32
 *   alignment_data_checksum of type uint32
 *   blockage_complete of type uint8
 *   TD_Blockage of type uint8
 *   c0_xcp_connect_status of type uint8
 *   C2_Calib_CKSUM_FaultError of type uint8
 * Dt_ALIGNMENT_STATUS: Record with elements
 *   CurrentAlignmentAngleUsed of type uint16
 *   EOLAlignmentAngle of type uint16
 * Dt_AdcData_T: Record with elements
 *   Adc_Board_Rev of type float32
 *   Adc_Batt_Volt of type float32
 *   Adc_Pos_Gnd_A of type float32
 *   Adc_Pos_Gnd_B of type float32
 *   Adc_Pos_Gnd_C of type float32
 *   Adc_Pos_Gnd_D of type float32
 *   Adc_Eth_0v9 of type float32
 *   Adc_Rdi_Detect of type float32
 *   Adc_MMIC_Temp of type float32
 *   Adc_Mcu_Temp of type float32
 *   Validity_Flag of type uint16
 * Dt_Battery_Tst_T: Record with elements
 *   battery_low_flt_sts of type uint8
 *   battery_high_flt_sts of type uint8
 * Dt_D2H_ErrorFlags: Record with elements
 *   DSP_Unit_Calibration_Error of type uint8
 *   DSP_System_Modifiable_Calibration_Error of type uint8
 *   DSP_Loop_Over_Run of type uint8
 * Dt_Dataset_ECU_Config_T: Record with elements
 *   ECU_Incomplete_Config_Status of type uint8
 *   ECU_Configuration_Updated_Status of type uint8
 * Dt_IPC_Faults: Record with elements
 *   IPC_M2D_Crc_Err_Cnt of type uint32
 *   IPC_D2M_Crc_Err_Cnt of type uint32
 *   IPC_D2A_Crc_Err_Cnt of type uint32
 *   IPC_A2M_Crc_Err_Cnt of type uint32
 * Dt_Mcu_Startup_Fault: Record with elements
 *   Mcu_Startup_Fault_Status of type uint8
 *   Mcu_Repetitive_Reset_Fault_Status of type uint8
 * Dt_PltToFltMgr_Alignment_Faults_T: Record with elements
 *   No_Initial_Calibration_flt_sts of type uint8
 *   Static_Calibration_flt_sts of type uint8
 *   Service_Calibration_flt_sts of type uint8
 *   ShortTrack_Calibration_flt_sts of type uint8
 *   Autoalign_outof_range_flt_sts of type uint8
 *   Autoalignment_algo_flt_sts of type uint8
 *   Autoalignment_sudden_jump_detection_error_flt_sts of type uint8
 *   Autoalignment_critical_misalignment_error_sts of type uint8
 * Dt_PltToFltMgr_Blockage_Detection_T: Record with elements
 *   radar_blockage_flt_sts of type uint8
 *   blockage_algo_flt_sts of type uint8
 *   damping_algo_flt_sts of type uint8
 *   Sidelobe_Level_flt_sts of type uint8
 * Dt_PltToFltMgr_Host_Micro_Diag_T: Record with elements
 *   host_pll_lock_flt_status of type uint8
 *   watchdog_flt_status of type uint8
 *   host_instr_set_chk_flt_status of type uint8
 *   Signal_Integrity_Chk_Flt_Status of type uint8
 *   externalwdg_flt_status of type uint8
 * Dt_PltToFltMgr_InterProcessor_Commn_T: Record with elements
 *   host_loss_of_commn_with_arm_flt_status of type uint8
 *   arm_loss_of_commn_with_host_flt_status of type uint8
 *   arm_loss_of_commn_with_dsp_flt_status of type uint8
 *   dsp_loss_of_commn_with_arm_flt_status of type uint8
 *   dsp_loss_of_commn_with_host_flt_status of type uint8
 *   host_loss_of_commn_with_dsp_flt_status of type uint8
 * Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T: Record with elements
 *   MMIC_TX_Temperature_flt_status of type uint8
 *   MMIC_chirp_pll_flt_status of type uint8
 *   MMIC_tx0_ball_brk_flt_status of type uint8
 *   MMIC_tx1_ball_brk_flt_status of type uint8
 *   MMIC_tx2_ball_brk_flt_status of type uint8
 *   MMIC_tx3_ball_brk_flt_status of type uint8
 *   MMIC_sensor_dead_flt_status of type uint8
 *   MMIC_safety_intergrity_flt_status of type uint8
 *   MMIC_TemperatureLow_flt_Status of type uint8
 *   MMIC_SafeStartUp_flt_Status of type uint8
 *   MMIC_Transmitter_ID_Fault of type uint8
 *   RF_BallBreak of type uint8
 *   MMIC_Loop_Back_Test_flt_status of type uint8
 *   Data_Acquisition_flt_status of type uint8
 *   RFE_Freq_Monitor_flt_sts of type uint8
 *   RFE_Power_Level_flt_sts of type uint8
 *   RFE_Lock_Step_flt_sts of type uint8
 *   RFE_CPU_flt_sts of type uint8
 *   RFE_Voltage_flt_sts of type uint8
 *   RFE_TX_RFBIST_flt_sts of type uint8
 *   RFE_RX_RFBIST_flt_sts of type uint8
 *   MMIC_Error_Recovery_Failure_Status of type uint8
 *   MMIC_Id_Unprogrammed_flt_status of type uint8
 *   API_Look_Config_flt_sts of type uint8
 *   API_Look_Complete_flt_sts of type uint8
 *   API_Look_Trigger_flt_sts of type uint8
 *   MMIC_Sec_Thermal_monitoring_flt_Status of type uint8
 *   MMIC_Secondary_Clock_Fault_Status of type uint8
 *   MMIC_Secondary_MIPI_Fault_Status of type uint8
 *   MMIC_Secondary_Register_Fault_Status of type uint8
 *   MMIC_Secondary_Ball_Break_Fault_Status of type uint8
 *   MMIC_Secondary_MCU_Fault_Status of type uint8
 * Dt_PltToFltMgr_MMIC_B_Diag_T: Record with elements
 *   MMIC_B_tx_id_flt_status of type uint8
 *   MMIC_B_mipi_adc_flt_status of type uint8
 *   MMIC_B_Timeout_flt_status of type uint8
 *   MMIC_B_safety_integtrity_pfbist_flt_status of type uint8
 *   MMIC_B_safe_strt_flt_status of type uint8
 *   MMIC_B_SafetyInt_Check_flt_sts of type uint8
 *   MMIC_B_SensorDead_flt_sts of type uint8
 *   MMIC_B_SPI_Transfer_flt_status of type uint8
 * Dt_PltToFltMgr_Memory_Diagnostics_T: Record with elements
 *   stack_overflow_flt_status of type uint8
 *   host_ram_memory_test_flt_status of type uint8
 *   host_appn_flash_checksum_flt_status of type uint8
 *   usc_validation_flt_status of type uint8
 *   smc_validtn_flt_status of type uint8
 *   core2_calib_flash_checksum_flt_status of type uint8
 *   Keep_Alive_Checksum_flt_sts of type uint8
 *   usc_unprogrammed_flt_status of type uint8
 * Dt_PltToFltMgr_Micro_Temp_Fault_Status_T: Record with elements
 *   TR_MCUTempLowFault of type uint8
 *   TR_MCUTempHighFault of type uint8
 *   thermistor_flt_status of type uint8
 *   TR_ECUTempLowFault of type uint8
 *   TR_ECUTempHighFault of type uint8
 * Dt_RadarDiagRequest: Record with elements
 *   RadarDiagShutdown of type uint8
 *   SafetyCriticalFaultActive of type uint8
 *   RadarReinitRequired_Qual of type uint8
 * Dt_RawAdcDataFilt_T: Record with elements
 *   Adc_Board_Rev of type uint16
 *   Adc_Batt_Volt of type uint16
 *   Adc_Pos_Gnd_A of type uint16
 *   Adc_Pos_Gnd_B of type uint16
 *   Adc_Pos_Gnd_C of type uint16
 *   Adc_Pos_Gnd_D of type uint16
 *   Adc_Eth_0v9 of type uint16
 *   Adc_Rdi_Detect of type uint16
 *   Adc_MMIC_Temp of type uint16
 *   Adc_Mcu_Temp of type uint16
 *   Validity_Flag of type uint8
 *   Pos_Validity_Flag of type uint8
 * Dt_Rdr_Hw_Tst_T: Record with elements
 *   dsp_loop_overrun_error_sts of type uint8
 *   c2_loop_overrun_error_sts of type uint8
 *   TR_Platformtime of type uint8
 *   SPT_error_sts of type uint8
 *   Range_algo_error_sts of type uint8
 *   PMIC_MCU_Comm_sts of type uint8
 *   Safety_Integrity_flt_sts of type uint8
 *   core_self_test_flt_status of type uint8
 *   Detection_Procession_Loop_Overrun_Fault_sts of type uint8
 *   Firstpass_Saturation_flt_sts of type uint8
 *   Dsp_Internal_Fault_sts of type uint8
 *   Detection_Data_Integrity_Fault_sts of type uint8
 * Dt_SignalTimeoutStatus_Group2_T: Record with elements
 *   STRG_A1C_FD_TO_Status of type uint8
 * Dt_Snapshot_received_signal_T: Record with elements
 *   FlashingIndicatorCommandPosition of type uint8
 *   Rear_Gear_Engaged of type uint8
 *   VehicleSpeed of type uint16
 *   BatteryVoltageStatus of type Dt_Batt_Volt_Status_T
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
 * Idt_XCP_Fault_Override_T: Record with elements
 *   action of type Rte_DT_Idt_XCP_Fault_Override_T_0
 *   byte_pos of type uint8
 *   bit_pos of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_FaultMgr_START_SEC_CODE
#include "SWC_PLT_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(Dt_PltToFltMgr_Alignment_Faults_T *data)
 *   Std_ReturnType Rte_Read_Rp_Codding_Position_Pins_error_Codding_Position_Pins_error(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_RADAR_SensorMisaligned_RADAR_SensorMisaligned(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_RADAR_SensorNotAligned_RADAR_SensorNotAligned(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Alignment_Diagnostics_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Platform_Battery_Tst_De_Platform_Battery_Tst(Dt_Battery_Tst_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Battery_Fault_Tests_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms
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
 *   Std_ReturnType Rte_Read_Rp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms
    *********************************************************************************************************************/

   /* Fault_Mgr_Can_Bus_Off_Fault_Test_50ms(); */

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_General_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_DTC_Status_De_DTC_Status(Dt_DTC_Status_Type *data)
 *   Std_ReturnType Rte_Read_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_ECU_Config_Dt_ECU_Config(Dt_Dataset_ECU_Config_T *data)
 *   Std_ReturnType Rte_Read_Rp_Intigrity_Status_Version_Logistic_T_Dt_Intigrity_Status_T(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_EcuIncompleteConfig_Status_De_EcuIncompleteConfig_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Platform_ActiveFault_Table_De_ActiveFaultTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_General_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_General_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_General_Diagnostics_50ms
    *********************************************************************************************************************/

   Fault_Mgr_General_Diagnostics_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(Dt_PltToFltMgr_Host_Micro_Diag_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Host_Microcontroller_Tests_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Init
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
 *   Std_ReturnType Rte_Read_Rp_FaultMgr_Get_Radar_Position_De_ECUPosition(Dt_ECUPosition *data)
 *   Std_ReturnType Rte_Read_Rp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(Dt_Mcu_Startup_Fault *data)
 *   Std_ReturnType Rte_Read_Rp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Init
    *********************************************************************************************************************/

   Fault_Mgr_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms
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
 *   Std_ReturnType Rte_Read_Rp_IPC_Faults_sts_De_IPC_Faults(Dt_IPC_Faults *data)
 *   Std_ReturnType
 *Rte_Read_Rp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(Dt_PltToFltMgr_InterProcessor_Commn_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Interprocessor_Comm_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Main_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Frame_TimeoutStatus_10ms_Update_TimeoutStatus_Group2(Dt_SignalTimeoutStatus_Group2_T *data)
 *   Std_ReturnType Rte_Read_Rp_Signal_Gade_Timeout_Status_De_Status(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ModeManagerTestResultInterface_De_TR_ModeManager(const Dt_TR_ModeManager *data)
 *   Std_ReturnType Rte_Write_Pp_RadarDiagRequestInterface_De_RadarDiagRequest(const Dt_RadarDiagRequest *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Main_10ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Main_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Main_10ms
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Main_50ms
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
 *   Std_ReturnType Rte_Read_Rp_A2H_ErrorFlags_De_A2H_ErrorFlags(Dt_A2H_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_D2H_ErrorFlags_De_D2H_ErrorFlags(Dt_D2H_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_FCCU_HW_State_FCCU_HW_State(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData(Dt_AdcData_T *data)
 *   Std_ReturnType Rte_Read_Rp_RMID_Status_from_ExtFlash_RMID_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_RawAdc_Data_De_RawAdcData(Dt_RawAdcDataFilt_T *data)
 *   Std_ReturnType Rte_Read_Rp_SPI_Failure_Failt_SPI_Failure_Fault(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Fault_Override_De_XCP_Fault_Override(Idt_XCP_Fault_Override_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_Active_Fault_Table_De_ActiveFaultTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Write_Pp_Forced_WDI_Disable_Forced_WDI_Disable(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_HistoryFaultTable_De_HistoryFaultTable(const uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Rp_Trigger_NvM_Erase_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Rp_Get_FloatingPinPosition_FaultStatus(uint8 *Status)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Main_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Main_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms
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
 *   Std_ReturnType
 *Rte_Read_Rp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(Dt_PltToFltMgr_Memory_Diagnostics_T *data)
 *   Std_ReturnType Rte_Read_Rp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Memory_Diagnostics_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset(uint8 *data)
 *   Std_ReturnType
 *Rte_Read_Rp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T
 **data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Microprocessor_Temp_Tests_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(Dt_PltToFltMgr_Blockage_Detection_T *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Radar_Blockage_Detection_Test_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(Dt_Rdr_Hw_Tst_T *data)
 *   Std_ReturnType Rte_Read_Rp_TR_PlatformTime_De_PlatformTime(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Radar_Hardware_Tests_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T
 **data) Std_ReturnType Rte_Read_Rp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(Dt_PltToFltMgr_MMIC_B_Diag_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms
    *********************************************************************************************************************/

   Fault_Mgr_Radar_Transceiver_Diagnostics_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE)
RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_FaultMgr_STOP_SEC_CODE
#include "SWC_PLT_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
