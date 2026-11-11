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
 *             File:  SWC_PLT_Appl_Diag.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_Diag
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_Diag>
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
 * Dt_Therm_Mon_Temp_Opt_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *
 * Component Types:
 * ================
 * SWC_PLT_Appl_Diag
 *   Implementation of validation diagnostc faults.
 *
 *
 * Runnable Entities:
 * ==================
 * RE_PLT_Diag_Init
 *   Init runnable for the module validation diagnostics.
 *
 * RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms
 *   Runnable for inter process communication diagnostic tests.
 *
 * RE_PLT_Diag_Memory_Diagnostics_50ms
 *   Runnable for memory diagnostic faults.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_Diag.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Platform_Diag_Callout.h"
#include "SWC_PLT_Appl_Diag.h"

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
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_DTC_Status_Type: Enumeration of integer in interval [0...255] with enumerators
 *   DIAG_TEST_FAIL (85U)
 *   DIAG_TEST_PASS (170U)
 *   DIAG_TEST_NOT_COMPLETED (0U)
 * Dt_ECU_ResetReasonType: Enumeration of integer in interval [0...65535] with enumerators
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
 *   POWER_OFF (6U)
 * Dt_Therm_Mon_Temp_Opt_T: Enumeration of integer in interval [0...255] with enumerators
 *   IMMEDIATE_TEMPERATURES_KELVIN (0U)
 *   AVERAGE_TEMPERATURES_KELVIN (1U)
 *   IMMEDIATE_TEMPERATURES_CELCIUS (2U)
 *   AVERAGE_TEMPERATURES_CELCIUS (3U)
 *   IMMEDIATE_TEMPERATURES_FAHRENHEIT (4U)
 *   AVERAGE_TEMPERATURES_FAHRENHEIT (5U)
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
 * Array Types:
 * ============
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0: Array with 2 element(s) of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0
 *
 * Record Types:
 * =============
 * DT_Thermal_Monitor_Temperatures_T: Record with elements
 *   temperature of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0
 * Dt_A2H_ErrorFlags: Record with elements
 *   blockage_data_checksum of type uint32
 *   alignment_data_checksum of type uint32
 *   blockage_complete of type uint8
 *   TD_Blockage of type uint8
 *   c0_xcp_connect_status of type uint8
 *   C2_Calib_CKSUM_FaultError of type uint8
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
 * Dt_Alignment_Faults_T: Record with elements
 *   No_Initial_Calibration_error of type uint8
 *   Static_Calibration_error of type uint8
 *   Service_Calibration_error of type uint8
 *   ShortTrack_Calibration_error of type uint8
 *   Autoalign_outof_range_error of type uint8
 *   Autoalignment_algo_error of type uint8
 *   Autoalignment_critical_misalignment_error of type uint8
 *   Autoalignment_sudden_jump_detection_error of type uint8
 * Dt_Battery_Tst_T: Record with elements
 *   battery_low_flt_sts of type uint8
 *   battery_high_flt_sts of type uint8
 * Dt_Customer_Domain_Errors: Record with elements
 *   Keep_Alive_Checksum_Error of type uint8
 *   PCAN_BussOff_Error of type uint8
 * Dt_D2H_ErrorFlags: Record with elements
 *   DSP_Unit_Calibration_Error of type uint8
 *   DSP_System_Modifiable_Calibration_Error of type uint8
 *   DSP_Loop_Over_Run of type uint8
 * Dt_ECUTemperature: Record with elements
 *   MCUTemperature1 of type sint16
 *   MCUTemeperature2 of type sint16
 *   onboardTemperature of type sint16
 * Dt_Hardware_Fault_Error_Status: Record with elements
 *   RA_Fault_Status of type uint8
 * Dt_IPC_Faults: Record with elements
 *   IPC_M2D_Crc_Err_Cnt of type uint32
 *   IPC_D2M_Crc_Err_Cnt of type uint32
 *   IPC_D2A_Crc_Err_Cnt of type uint32
 *   IPC_A2M_Crc_Err_Cnt of type uint32
 * Dt_MMIC_B_ErrorFlags: Record with elements
 *   MMIC_B_Transmitter_ID_Fault of type uint8
 *   MMIC_B_MIPI_ADC_Fault of type uint8
 *   MMIC_B_Timeout_Error of type uint8
 *   MMIC_B_safety_integtrity_pfbist_Error of type uint8
 *   MMIC_B_SafeStartUp_Error of type uint8
 *   MMIC_B_SafetyInt_Check_Error of type uint8
 *   MMIC_B_SensorDead_Error of type uint8
 *   MMIC_B_SPI_Transfer_Error of type uint8
 * Dt_MMIC_ErrorFlags: Record with elements
 *   temperature_max_err of type uint8
 *   chirp_pll_err of type uint8
 *   tx0_ball_brk_err of type uint8
 *   tx1_ball_brk_err of type uint8
 *   tx2_ball_brk_err of type uint8
 *   tx3_ball_brk_err of type uint8
 *   sensor_dead_err of type uint8
 *   safety_intergrity_err of type uint8
 *   MMIC_TemperatureLowFault of type uint8
 *   MMIC_SafeStartUp_Error of type uint8
 *   MMIC_Transmitter_ID_Fault of type uint8
 *   RF_BallBreak of type uint8
 *   MMIC_Loop_Back_Test_Fault of type uint8
 *   Data_Acquisition_err of type uint8
 *   RFE_Freq_Monitor_err of type uint8
 *   RFE_Power_Level_err of type uint8
 *   RFE_Lock_Step_err of type uint8
 *   RFE_CPU_err of type uint8
 *   RFE_Voltage_err of type uint8
 *   RFE_TX_RFBIST_err of type uint8
 *   RFE_RX_RFBIST_err of type uint8
 *   MMIC_Error_Recovery_Failure of type uint8
 *   MMIC_Id_Unprogrammed_Error of type uint8
 *   MMIC_Secondary_Clock_Fault of type uint8
 *   API_Look_Config_err of type uint8
 *   API_Look_Complete_err of type uint8
 *   API_Look_Trigger_err of type uint8
 *   MMIC_RFE_MCU_Fault of type uint8
 *   MMIC_RFE_Par_Redun_Fault of type uint8
 *   MMIC_RFE_PLL_Lock_Fault of type uint8
 *   MMIC_Sec_Thermal_monitoring_flt of type uint8
 *   MMIC_Secondary_MIPI_Fault of type uint8
 *   MMIC_Secondary_Register_Fault of type uint8
 *   MMIC_Secondary_Ball_Break_Fault of type uint8
 *   MMIC_Secondary_MCU_Fault of type uint8
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
 * Dt_RadarCapability_Faults: Record with elements
 *   SLL_Fault of type uint8
 *   Range_Estimation_Fault of type uint8
 *   Blockage_Fault of type uint8
 *   Damping_Estimation_Fault of type uint8
 *   SPT_Fault of type uint8
 *   Safety_Integrity_Fault of type uint8
 *   Core_Self_Test_Fault of type uint8
 *   Detection_Procession_Loop_Overrun_Fault of type uint8
 *   Firstpass_Saturation_Fault of type uint8
 *   Dsp_Internal_Fault of type uint8
 *   Detection_Data_Integrity_Fault of type uint8
 * Dt_RadarCoreStatus: Record with elements
 *   RadarInitializatonStatus of type Rte_DT_Dt_RadarCoreStatus_0
 *   RadarReInitRequired of type uint8
 *   IsRadiating of type uint8
 *   OperationMode_Radar of type Rte_DT_Dt_RadarCoreStatus_3
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
 * TR_AdcMeasurement_T: Record with elements
 *   TR_MCUtemp_Calflt of type boolean
 *   TR_onboardThermistorFault of type boolean
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_Diag_START_SEC_CODE
#include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Diag_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Diag_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Diag_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Diag_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
CS_Diag_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Diag_Fault_Injection_Read
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Alignment_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Alignment_Faults_De_Alignment_Faults(Dt_Alignment_Faults_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(const Dt_PltToFltMgr_Alignment_Faults_T *data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_DcmControlDtcSetting_DcmControlDtcSetting(void)
 *   Modes of Rte_ModeType_DcmControlDtcSetting:
 *   - RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING
 *   - RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING
 *   - RTE_TRANSITION_DcmControlDtcSetting
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Alignment_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Alignment_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Alignment_Diagnostics_50ms
    *********************************************************************************************************************/

   Diag_Alignment_Diagnostics_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Battery_Fault_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_VbattState_De_Vbatt_State(Dt_VBattState_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst(const Dt_Battery_Tst_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Battery_Fault_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Battery_Fault_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Battery_Fault_Tests_50ms
    *********************************************************************************************************************/

   Diag_Battery_Fault_Tests_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms
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
 *   Std_ReturnType Rte_Read_Rp_PCAN_Bus_Off_Fault_Flag_De_PCAN_Busoff_Fault_Flag(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms
    *********************************************************************************************************************/

   Diag_Can_Bus_Off_Fault_Test_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Host_Microcontroller_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Watchdog_Fault_Reset_De_Watchdog_Fault_Reset(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_externalwatchdogstatus_de_externalwatchdogstatus(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(const Dt_PltToFltMgr_Host_Micro_Diag_T
 **data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Host_Microcontroller_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Host_Microcontroller_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Host_Microcontroller_Tests_50ms
    *********************************************************************************************************************/

   Diag_Host_Microcontroller_Tests_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Init
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
 *   Std_ReturnType Rte_Read_Rp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_TR_initMCU_Fail_De_TR_InitMCU_fail(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(const Dt_Mcu_Startup_Fault *data)
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Init
    *********************************************************************************************************************/

   Diag_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_IPC_Faults_De_IPC_Faults(Dt_IPC_Faults *data)
 *   Std_ReturnType Rte_Read_Rp_ipc_arm_host_ipc_arm_host(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_ipc_dsp_host_ipc_dsp_host(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_IPC_Faults_sts_De_IPC_Faults(const Dt_IPC_Faults *data)
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(const
 *Dt_PltToFltMgr_InterProcessor_Commn_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms
    *********************************************************************************************************************/

   Diag_Inter_Processor_Communication_Diagnostics_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Memory_Diagnostics_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 * Executed in the context of the following exclusive areas:
 *   - ExclusiveArea
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Customer_Domain_Faults_De_Customer_Domain_Faults(Dt_Customer_Domain_Errors *data)
 *   Std_ReturnType Rte_Read_Rp_Diag_A2H_ErrorFlags_De_A2H_ErrorFlags(Dt_A2H_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_Diag_D2H_ErrorFlags_De_D2H_ErrorFlags(Dt_D2H_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_Intigrity_Status_Dt_Intigrity_Status_T(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_exception_reset_flt_exception_reset_flt(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_DTC_Status_De_DTC_Status(Dt_DTC_Status_Type data)
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(const
 *Dt_PltToFltMgr_Memory_Diagnostics_T *data) Std_ReturnType
 *Rte_Write_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FailSafe_Log_ResetReason_FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Platform_Diagnostics_PltToFltMgr_NvM_FeeCriticalError_Diagnostics(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Memory_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Memory_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Memory_Diagnostics_50ms
    *********************************************************************************************************************/

   Diag_Memory_Diagnostics_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Microprocessor_Temp_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_ADC_Measurement_interface_Element(TR_AdcMeasurement_T *data)
 *   Std_ReturnType Rte_Read_Rp_Diag_RawAdc_Data_De_RawAdcData(Dt_RawAdcDataFilt_T *data)
 *   Std_ReturnType Rte_Read_Rp_Get_Adc_Data_Structure_De_PhysicalAdcData(Dt_AdcData_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ECUTemperature_ECUTemperature(const Dt_ECUTemperature *data)
 *   Std_ReturnType Rte_Write_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(const
 *Dt_PltToFltMgr_Micro_Temp_Fault_Status_T *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, DT_Thermal_Monitor_Temperatures_T *reqValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Pi_ThermMonTemp_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Microprocessor_Temp_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Microprocessor_Temp_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Microprocessor_Temp_Tests_50ms
    *********************************************************************************************************************/

   Diag_Microprocessor_Temp_Tests_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_PlatformTime_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_TR_PlatformTime_De_PlatformTime(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_PlatformTime_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_PlatformTime_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_PlatformTime_50ms
    *********************************************************************************************************************/

   Diag_PlatformTime_Test_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Diag_A2H_ErrorFlags_De_A2H_ErrorFlags(Dt_A2H_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_RadarCapability_Faults_De_RadarCapability_Faults(Dt_RadarCapability_Faults *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(const Dt_PltToFltMgr_Blockage_Detection_T *data)
 *   Std_ReturnType Rte_Write_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms
    *********************************************************************************************************************/

   Diag_Radar_Blockage_Detection_Test_50ms();
   Diag_Radar_Interference_Detection_Test_50ms();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Radar_Hardware_Tests_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Hardware_Fault_Status_De_Hardware_Fault_Status(Dt_Hardware_Fault_Error_Status *data)
 *   Std_ReturnType Rte_Read_Rp_Operation_Mode_System_De_OperationMode_System(Dt_SystemOperationMode *data)
 *   Std_ReturnType Rte_Read_Rp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_TR_platform_Time_De_PlatformTime(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(const Dt_Rdr_Hw_Tst_T *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Pp_Get_PlatfromTime_us_diag_read(uint64 *instant_ustime)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Radar_Hardware_Tests_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Radar_Hardware_Tests_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Radar_Hardware_Tests_50ms
    *********************************************************************************************************************/

   Diag_Radar_Hardware_Tests_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Diag_MMIC_B_ErrorFlags_De_MMIC_B_ErrorFlags(Dt_MMIC_B_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(Dt_MMIC_ErrorFlags *data)
 *   Std_ReturnType Rte_Read_Rp_RadarCoreStatusInterface_De_RadarCoreStatus(Dt_RadarCoreStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(const
 *Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T *data) Std_ReturnType Rte_Write_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(const
 *Dt_PltToFltMgr_MMIC_B_Diag_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_Diag_CODE)
RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms
    *********************************************************************************************************************/

   Diag_Radar_Transceiver_Diagnostics_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_Diag_STOP_SEC_CODE
#include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************************************************************************************************
 *  Revision History
 *
 *   Date         SCR			     Name             Description
 *   ----         ----		     ----------- ---------------------------------------------------------------------------------------
 * 22-NOV-2019    CPT-107          Priyatham         Mapped all the manual interfaces through RTE for
 * SWC_PLT_Appl_Platform_Diag_Diag and removed NvM.h, Diag_Cal_file.h, hw_init_c2.h, No_Init.h, Fls.h, dd_stm.h, timing_function.h,
 * Mcu_MC_ME.h, SWC_Appl_IoHwAb.h, SWC_CDD_FailSafe.h header files.
 * 28-NOV-2019	 CPT-96		      Priyatham	        The variables ending with "_VC" are placed in compiler switch "UNIT_TEST" are
 * used only for Functional Testing 12-DEC-2019	 CPT-143		  Priyatham	        Created S/R and C/S ports and also created macros
 * between platform SWC and fault manager SWC. Changed generation path of stub files. 16-DEC-2019    CPT-144          Sibeesh M
 * Move Debouncing handling to Fault Manager from Platform Diag 13-DEC-2019	 CPT-132	      Prince	        Dolphin Fault
 * Implementation. 15-JAN-2020	 CPT-199	      Prince	        Implement remaining Platform diagnostics - Part 2. 30_Jan-2020
 * CPT-224		  Priyatham		    Created S/R ports as mentioned in the ticket CPT-224. 28-APR-2020    CPT-286	      Prince Fault
 * Manager as per Platform PDD Part-1. 05-MAY-2020    CPT-289	      Prince	        Fault Manager as per Platform PDD Part-2.
 * 23-JUN-2020    CPT-341	      Prince	        Solve the Software Qualification test finding
 * 29-JUN-2020    CPT-309	      Prince	        TemperatureSupervision as per mode manager PDD
 * 28-JAN-2021 	 CPT-413	      Priyatham		    Implementation of Temperature Supervision in Mode Manager
 * 22-FEB-2021 	 CPT-511	      Priyatham		    Created Provider Port, Pp_ECUTemperature for, to provide, Tsense0, Tsense1,
 * Onboard temperture values 25-May-2021    EEG-367          Vijayendra        Implementation ticket for RNA SRR6 DV faults
 * 05-Jun-2021	 EEG-366		  Chetan Desai		PCAN bus off implemetation
 * 09-Jun-2021    EEG-382          Vijayendra        Implementation of the Barracuda faults
 * 08-June-2021   EEG-403          Gyan.R.Jha        ADC structure update for common indexing.
 * 05-OCT-2021                     Vijayendra        Updated for SRR6P build errors
 * 24-OCT-2021    EEG-590          Vijayendra        [EMH-930][SW]bifircation of the software component as template and static
 * *************************************************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: runnable implementation:RE_PLT_Diag_PlatformTime_Diagnostics_50ms)  ******/
   Diag_PlatformTime_Test_50ms();

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RE_PLT_Diag_PlatformTime_Diagnostics_50ms_doc)  *******/

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
