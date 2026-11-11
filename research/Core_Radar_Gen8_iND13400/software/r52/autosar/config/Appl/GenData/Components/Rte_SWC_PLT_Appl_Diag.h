/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_Appl_Diag.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_Diag>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_DIAG_H
# define RTE_SWC_PLT_APPL_DIAG_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_PLT_Appl_Diag_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_DTC_Status_Type, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime;
extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_DTC_Status_De_DTC_Status (0U)
#  define Rte_InitValue_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset (85U)
#  define Rte_InitValue_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status (0U)
#  define Rte_InitValue_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status (0U)
#  define Rte_InitValue_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts (0U)
#  define Rte_InitValue_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status (0U)
#  define Rte_InitValue_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts (0U)
#  define Rte_InitValue_Pp_TR_PlatformTime_De_PlatformTime (0U)
#  define Rte_InitValue_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag (85U)
#  define Rte_InitValue_Rp_Intigrity_Status_Dt_Intigrity_Status_T (0U)
#  define Rte_InitValue_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet (0U)
#  define Rte_InitValue_Rp_Operation_Mode_System_De_OperationMode_System (0U)
#  define Rte_InitValue_Rp_PCAN_Bus_Off_Fault_Flag_De_PCAN_Busoff_Fault_Flag (FALSE)
#  define Rte_InitValue_Rp_PlatformInitializationStatus_De_MCU_InitializationStatus (0U)
#  define Rte_InitValue_Rp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault (0U)
#  define Rte_InitValue_Rp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status (0U)
#  define Rte_InitValue_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status (85U)
#  define Rte_InitValue_Rp_TR_initMCU_Fail_De_TR_InitMCU_fail (85U)
#  define Rte_InitValue_Rp_TR_platform_Time_De_PlatformTime (85U)
#  define Rte_InitValue_Rp_VbattState_De_Vbatt_State (0U)
#  define Rte_InitValue_Rp_Watchdog_Fault_Reset_De_Watchdog_Fault_Reset (0U)
#  define Rte_InitValue_Rp_exception_reset_flt_exception_reset_flt (0U)
#  define Rte_InitValue_Rp_externalwatchdogstatus_de_externalwatchdogstatus (0U)
#  define Rte_InitValue_Rp_ipc_arm_host_ipc_arm_host (0U)
#  define Rte_InitValue_Rp_ipc_dsp_host_ipc_dsp_host (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Alignment_Faults_De_Alignment_Faults(P2VAR(Dt_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(P2VAR(Dt_MMIC_ErrorFlags, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Hardware_Fault_Status_De_Hardware_Fault_Status(P2VAR(Dt_Hardware_Fault_Error_Status, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_IPC_Faults_De_IPC_Faults(P2VAR(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_RadarCapability_Faults_De_RadarCapability_Faults(P2VAR(Dt_RadarCapability_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(P2CONST(Dt_PltToFltMgr_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults(P2CONST(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(P2CONST(Dt_Mcu_Startup_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst(P2CONST(Dt_Battery_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(P2CONST(Dt_PltToFltMgr_Host_Micro_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(P2CONST(Dt_PltToFltMgr_InterProcessor_Commn_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(P2CONST(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(P2CONST(Dt_PltToFltMgr_MMIC_B_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(P2CONST(Dt_PltToFltMgr_Memory_Diagnostics_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(P2CONST(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(P2CONST(Dt_PltToFltMgr_Blockage_Detection_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(P2CONST(Dt_Rdr_Hw_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_ADC_Measurement_interface_Element Rte_Read_SWC_PLT_Appl_Diag_Rp_ADC_Measurement_interface_Element
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_ADC_Measurement_interface_Element(data) (*(data) = Rte_C_TR_AdcMeasurement_T_A13744F7BAD15CFDC387E03952E7B16B, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Alignment_Faults_De_Alignment_Faults Rte_Read_SWC_PLT_Appl_Diag_Rp_Alignment_Faults_De_Alignment_Faults
#  define Rte_Read_Rp_Customer_Domain_Faults_De_Customer_Domain_Faults Rte_Read_SWC_PLT_Appl_Diag_Rp_Customer_Domain_Faults_De_Customer_Domain_Faults
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Customer_Domain_Faults_De_Customer_Domain_Faults(data) (*(data) = Rte_C_Customer_Domain_Faults_Dt_Customer_Domain_Errors, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Diag_A2H_ErrorFlags_De_A2H_ErrorFlags Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_A2H_ErrorFlags_De_A2H_ErrorFlags
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_A2H_ErrorFlags_De_A2H_ErrorFlags(data) (*(data) = Rte_C_A2H_ErrorFlags_Dt_A2H_ErrorFlags, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Diag_D2H_ErrorFlags_De_D2H_ErrorFlags Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_D2H_ErrorFlags_De_D2H_ErrorFlags
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_D2H_ErrorFlags_De_D2H_ErrorFlags(data) (*(data) = Rte_C_D2H_ErrorFlags_Dt_D2H_ErrorFlags, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Diag_MMIC_B_ErrorFlags_De_MMIC_B_ErrorFlags Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_MMIC_B_ErrorFlags_De_MMIC_B_ErrorFlags
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_MMIC_B_ErrorFlags_De_MMIC_B_ErrorFlags(data) (*(data) = Rte_C_MMIC_B_ErrorFlags_Dt_MMIC_B_ErrorFlags, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags
#  define Rte_Read_Rp_Diag_RawAdc_Data_De_RawAdcData Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_RawAdc_Data_De_RawAdcData
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_RawAdc_Data_De_RawAdcData(data) (*(data) = Rte_C_RawAdcDataFilt_T_Dt_RawAdcDataFilt_T, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag Rte_Read_SWC_PLT_Appl_Diag_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Get_Adc_Data_Structure_De_PhysicalAdcData Rte_Read_SWC_PLT_Appl_Diag_Rp_Get_Adc_Data_Structure_De_PhysicalAdcData
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Get_Adc_Data_Structure_De_PhysicalAdcData(data) (*(data) = Rte_C_Dt_AdcData_T_497FFB561B06C50A6AEA9B6E5B7CE8EE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Hardware_Fault_Status_De_Hardware_Fault_Status Rte_Read_SWC_PLT_Appl_Diag_Rp_Hardware_Fault_Status_De_Hardware_Fault_Status
#  define Rte_Read_Rp_IPC_Faults_De_IPC_Faults Rte_Read_SWC_PLT_Appl_Diag_Rp_IPC_Faults_De_IPC_Faults
#  define Rte_Read_Rp_Intigrity_Status_Dt_Intigrity_Status_T Rte_Read_SWC_PLT_Appl_Diag_Rp_Intigrity_Status_Dt_Intigrity_Status_T
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Intigrity_Status_Dt_Intigrity_Status_T(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet Rte_Read_SWC_PLT_Appl_Diag_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Operation_Mode_System_De_OperationMode_System Rte_Read_SWC_PLT_Appl_Diag_Rp_Operation_Mode_System_De_OperationMode_System
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Operation_Mode_System_De_OperationMode_System(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PCAN_Bus_Off_Fault_Flag_De_PCAN_Busoff_Fault_Flag Rte_Read_SWC_PLT_Appl_Diag_Rp_PCAN_Bus_Off_Fault_Flag_De_PCAN_Busoff_Fault_Flag
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_PCAN_Bus_Off_Fault_Flag_De_PCAN_Busoff_Fault_Flag(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault Rte_Read_SWC_PLT_Appl_Diag_Rp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault(data) (*(data) = Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status Rte_Read_SWC_PLT_Appl_Diag_Rp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status(data) (*(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RadarCapability_Faults_De_RadarCapability_Faults Rte_Read_SWC_PLT_Appl_Diag_Rp_RadarCapability_Faults_De_RadarCapability_Faults
#  define Rte_Read_Rp_RadarCoreStatusInterface_De_RadarCoreStatus Rte_Read_SWC_PLT_Appl_Diag_Rp_RadarCoreStatusInterface_De_RadarCoreStatus
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_RadarCoreStatusInterface_De_RadarCoreStatus(data) (*(data) = Rte_C_RadarCoreStatus_T_Dt_RadarCoreStatus, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status Rte_Read_SWC_PLT_Appl_Diag_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(data) (*(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TR_initMCU_Fail_De_TR_InitMCU_fail Rte_Read_SWC_PLT_Appl_Diag_Rp_TR_initMCU_Fail_De_TR_InitMCU_fail
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_TR_initMCU_Fail_De_TR_InitMCU_fail(data) (*(data) = Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TR_platform_Time_De_PlatformTime Rte_Read_SWC_PLT_Appl_Diag_Rp_TR_platform_Time_De_PlatformTime
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_TR_platform_Time_De_PlatformTime(data) (*(data) = Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_VbattState_De_Vbatt_State Rte_Read_SWC_PLT_Appl_Diag_Rp_VbattState_De_Vbatt_State
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_VbattState_De_Vbatt_State(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Watchdog_Fault_Reset_De_Watchdog_Fault_Reset Rte_Read_SWC_PLT_Appl_Diag_Rp_Watchdog_Fault_Reset_De_Watchdog_Fault_Reset
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_Watchdog_Fault_Reset_De_Watchdog_Fault_Reset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_exception_reset_flt_exception_reset_flt Rte_Read_SWC_PLT_Appl_Diag_Rp_exception_reset_flt_exception_reset_flt
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_exception_reset_flt_exception_reset_flt(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_externalwatchdogstatus_de_externalwatchdogstatus Rte_Read_SWC_PLT_Appl_Diag_Rp_externalwatchdogstatus_de_externalwatchdogstatus
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_externalwatchdogstatus_de_externalwatchdogstatus(data) (*(data) = Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_ipc_arm_host_ipc_arm_host Rte_Read_SWC_PLT_Appl_Diag_Rp_ipc_arm_host_ipc_arm_host
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_ipc_arm_host_ipc_arm_host(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_ipc_dsp_host_ipc_dsp_host Rte_Read_SWC_PLT_Appl_Diag_Rp_ipc_dsp_host_ipc_dsp_host
#  define Rte_Read_SWC_PLT_Appl_Diag_Rp_ipc_dsp_host_ipc_dsp_host(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults Rte_Write_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults
#  define Rte_Write_Pp_DTC_Status_De_DTC_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status(data) (Rte_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_ECUTemperature_ECUTemperature Rte_Write_SWC_PLT_Appl_Diag_Pp_ECUTemperature_ECUTemperature
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_ECUTemperature_ECUTemperature(data) (RTE_E_OK)
#  define Rte_Write_Pp_IPC_Faults_sts_De_IPC_Faults Rte_Write_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults
#  define Rte_Write_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status
#  define Rte_Write_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset Rte_Write_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset(data) (Rte_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst Rte_Write_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst
#  define Rte_Write_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status(data) (Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status(data) (Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag
#  define Rte_Write_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T
#  define Rte_Write_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T
#  define Rte_Write_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T
#  define Rte_Write_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics
#  define Rte_Write_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status
#  define Rte_Write_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts(data) (Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status Rte_Write_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status(data) (Rte_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts Rte_Write_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts
#  define Rte_Write_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts Rte_Write_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts(data) (Rte_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst Rte_Write_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst
#  define Rte_Write_Pp_TR_PlatformTime_De_PlatformTime Rte_Write_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime
#  define Rte_Write_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime(data) (Rte_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmControlDtcSetting_DcmControlDtcSetting() (RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_IoHwAb_START_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_PLT_Appl_IoHwAb_CODE) CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, P2VAR(DT_Thermal_Monitor_Temperatures_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_VAR) reqValue); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_IoHwAb_STOP_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) Get_PlatfromTime_us_read(P2VAR(uint64, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) instant_ustime); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_FailSafe_START_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_ThermMonTemp_Read CS_ThermMonTemp_Read
#  define Rte_Call_FailSafe_Log_ResetReason_FailSafe_Log_ResetReason(arg1) (FailSafe_Log_ResetReason(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Platform_Diagnostics_PltToFltMgr_NvM_FeeCriticalError_Diagnostics() (RTE_E_UNCONNECTED)
#  define Rte_Call_Pp_Get_PlatfromTime_us_diag_read(arg1) (Get_PlatfromTime_us_read(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_Diag_START_SEC_CODE
# include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Diag_Fault_Injection_Read CS_Diag_Fault_Injection_Read
#  define RTE_RUNNABLE_RE_PLT_Diag_Alignment_Diagnostics_50ms RE_PLT_Diag_Alignment_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Battery_Fault_Tests_50ms RE_PLT_Diag_Battery_Fault_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Host_Microcontroller_Tests_50ms RE_PLT_Diag_Host_Microcontroller_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Init RE_PLT_Diag_Init
#  define RTE_RUNNABLE_RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Memory_Diagnostics_50ms RE_PLT_Diag_Memory_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Microprocessor_Temp_Tests_50ms RE_PLT_Diag_Microprocessor_Temp_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_PlatformTime_50ms RE_PLT_Diag_PlatformTime_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Radar_Hardware_Tests_50ms RE_PLT_Diag_Radar_Hardware_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms
# endif

FUNC(void, SWC_PLT_Appl_Diag_CODE) CS_Diag_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Alignment_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Battery_Fault_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Host_Microcontroller_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Memory_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Microprocessor_Temp_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_PlatformTime_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Radar_Hardware_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Diag_CODE) RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_Diag_STOP_SEC_CODE
# include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Pi_ThermMonTemp_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_DIAG_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
