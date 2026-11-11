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
 *             File:  Rte_SWC_PLT_Appl_FaultMgr.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_FaultMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_FAULTMGR_H
# define RTE_SWC_PLT_APPL_FAULTMGR_H

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

# include "Rte_SWC_PLT_Appl_FaultMgr_Type.h"
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

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_Lib_START_SEC_CODE_ASIL_B
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_Lib_STOP_SEC_CODE_ASIL_B
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_EcuIncompleteConfig_Status_De_EcuIncompleteConfig_Status (85U)
#  define Rte_InitValue_Pp_Forced_WDI_Disable_Forced_WDI_Disable (0U)
#  define Rte_InitValue_Rp_Codding_Position_Pins_error_Codding_Position_Pins_error (0U)
#  define Rte_InitValue_Rp_DTC_Status_De_DTC_Status (0U)
#  define Rte_InitValue_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag (85U)
#  define Rte_InitValue_Rp_FCCU_HW_State_FCCU_HW_State (0U)
#  define Rte_InitValue_Rp_FaultMgr_Get_Radar_Position_De_ECUPosition (0U)
#  define Rte_InitValue_Rp_Intigrity_Status_Version_Logistic_T_Dt_Intigrity_Status_T (0U)
#  define Rte_InitValue_Rp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset (85U)
#  define Rte_InitValue_Rp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status (0U)
#  define Rte_InitValue_Rp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status (0U)
#  define Rte_InitValue_Rp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts (0U)
#  define Rte_InitValue_Rp_RADAR_SensorMisaligned_RADAR_SensorMisaligned (0U)
#  define Rte_InitValue_Rp_RADAR_SensorNotAligned_RADAR_SensorNotAligned (0U)
#  define Rte_InitValue_Rp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status (0U)
#  define Rte_InitValue_Rp_RMID_Status_from_ExtFlash_RMID_Status (0U)
#  define Rte_InitValue_Rp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts (0U)
#  define Rte_InitValue_Rp_SPI_Failure_Failt_SPI_Failure_Fault (0U)
#  define Rte_InitValue_Rp_Signal_Gade_Timeout_Status_De_Status (0U)
#  define Rte_InitValue_Rp_TR_PlatformTime_De_PlatformTime (0U)
#  define Rte_InitValue_Rp_Vbatt_State_De_Vbatt_State (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(P2VAR(Dt_PltToFltMgr_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_IPC_Faults_sts_De_IPC_Faults(P2VAR(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(P2VAR(Dt_Mcu_Startup_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Platform_Battery_Tst_De_Platform_Battery_Tst(P2VAR(Dt_Battery_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(P2VAR(Dt_PltToFltMgr_Host_Micro_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(P2VAR(Dt_PltToFltMgr_InterProcessor_Commn_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(P2VAR(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(P2VAR(Dt_PltToFltMgr_MMIC_B_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(P2VAR(Dt_PltToFltMgr_Memory_Diagnostics_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(P2VAR(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(P2VAR(Dt_PltToFltMgr_Blockage_Detection_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(P2VAR(Dt_Rdr_Hw_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_XCP_Fault_Override_De_XCP_Fault_Override(P2VAR(Idt_XCP_Fault_Override_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager(P2CONST(Dt_TR_ModeManager, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest(P2CONST(Dt_RadarDiagRequest, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_A2H_ErrorFlags_De_A2H_ErrorFlags Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_A2H_ErrorFlags_De_A2H_ErrorFlags
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_A2H_ErrorFlags_De_A2H_ErrorFlags(data) (*(data) = Rte_C_A2H_ErrorFlags_Dt_A2H_ErrorFlags, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults
#  define Rte_Read_Rp_Codding_Position_Pins_error_Codding_Position_Pins_error Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Codding_Position_Pins_error_Codding_Position_Pins_error
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Codding_Position_Pins_error_Codding_Position_Pins_error(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_D2H_ErrorFlags_De_D2H_ErrorFlags Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_D2H_ErrorFlags_De_D2H_ErrorFlags
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_D2H_ErrorFlags_De_D2H_ErrorFlags(data) (*(data) = Rte_C_D2H_ErrorFlags_Dt_D2H_ErrorFlags, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_DTC_Status_De_DTC_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_DTC_Status_De_DTC_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_DTC_Status_De_DTC_Status(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Dinamo_Enable_Flag_Faultmgr_De_Dinamo_Enable_Flag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_ECU_Config_Dt_ECU_Config Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_ECU_Config_Dt_ECU_Config
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_ECU_Config_Dt_ECU_Config(data) (*(data) = Rte_C_Dt_Dataset_ECU_Config_T_29E91F69E2FAE291DCAC176C8CB8268E, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_FCCU_HW_State_FCCU_HW_State Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_FCCU_HW_State_FCCU_HW_State
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_FCCU_HW_State_FCCU_HW_State(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_FaultMgr_Get_Radar_Position_De_ECUPosition Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_FaultMgr_Get_Radar_Position_De_ECUPosition
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_FaultMgr_Get_Radar_Position_De_ECUPosition(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Frame_TimeoutStatus_10ms_Update_TimeoutStatus_Group2 Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Frame_TimeoutStatus_10ms_Update_TimeoutStatus_Group2
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Frame_TimeoutStatus_10ms_Update_TimeoutStatus_Group2(data) (*(data) = Rte_C_SignalTimeoutStatus_Group2_T_Dt_SignalTimeoutStatus_Group2_T, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_IPC_Faults_sts_De_IPC_Faults Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_IPC_Faults_sts_De_IPC_Faults
#  define Rte_Read_Rp_Intigrity_Status_Version_Logistic_T_Dt_Intigrity_Status_T Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Intigrity_Status_Version_Logistic_T_Dt_Intigrity_Status_T
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Intigrity_Status_Version_Logistic_T_Dt_Intigrity_Status_T(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status
#  define Rte_Read_Rp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PhysicalAdcData_De_PhysicalAdcData
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PhysicalAdcData_De_PhysicalAdcData(data) (*(data) = Rte_C_Dt_AdcData_T_497FFB561B06C50A6AEA9B6E5B7CE8EE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Platform_Battery_Tst_De_Platform_Battery_Tst Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Platform_Battery_Tst_De_Platform_Battery_Tst
#  define Rte_Read_Rp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag
#  define Rte_Read_Rp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T
#  define Rte_Read_Rp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T
#  define Rte_Read_Rp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T
#  define Rte_Read_Rp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics
#  define Rte_Read_Rp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status
#  define Rte_Read_Rp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RADAR_SensorMisaligned_RADAR_SensorMisaligned Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RADAR_SensorMisaligned_RADAR_SensorMisaligned
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RADAR_SensorMisaligned_RADAR_SensorMisaligned(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_RADAR_SensorNotAligned_RADAR_SensorNotAligned Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RADAR_SensorNotAligned_RADAR_SensorNotAligned
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RADAR_SensorNotAligned_RADAR_SensorNotAligned(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RMID_Status_from_ExtFlash_RMID_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RMID_Status_from_ExtFlash_RMID_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RMID_Status_from_ExtFlash_RMID_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts
#  define Rte_Read_Rp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RawAdc_Data_De_RawAdcData Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RawAdc_Data_De_RawAdcData
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_RawAdc_Data_De_RawAdcData(data) (*(data) = Rte_C_RawAdcDataFilt_T_Dt_RawAdcDataFilt_T, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Rdr_Hw_Tst_De_Rdr_Hw_Tst Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Rdr_Hw_Tst_De_Rdr_Hw_Tst
#  define Rte_Read_Rp_SPI_Failure_Failt_SPI_Failure_Fault Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_SPI_Failure_Failt_SPI_Failure_Fault
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_SPI_Failure_Failt_SPI_Failure_Fault(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Signal_Gade_Timeout_Status_De_Status Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Signal_Gade_Timeout_Status_De_Status
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Signal_Gade_Timeout_Status_De_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_TR_PlatformTime_De_PlatformTime Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_TR_PlatformTime_De_PlatformTime
#  define Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_TR_PlatformTime_De_PlatformTime(data) (*(data) = Rte_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Fault_Override_De_XCP_Fault_Override Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_XCP_Fault_Override_De_XCP_Fault_Override


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable
#  define Rte_Write_Pp_Active_Fault_Table_De_ActiveFaultTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable
#  define Rte_Write_Pp_EcuIncompleteConfig_Status_De_EcuIncompleteConfig_Status Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_EcuIncompleteConfig_Status_De_EcuIncompleteConfig_Status
#  define Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_EcuIncompleteConfig_Status_De_EcuIncompleteConfig_Status(data) (RTE_E_OK)
#  define Rte_Write_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable
#  define Rte_Write_Pp_Forced_WDI_Disable_Forced_WDI_Disable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Forced_WDI_Disable_Forced_WDI_Disable
#  define Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Forced_WDI_Disable_Forced_WDI_Disable(data) (RTE_E_OK)
#  define Rte_Write_Pp_HistoryFaultTable_De_HistoryFaultTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable
#  define Rte_Write_Pp_ModeManagerTestResultInterface_De_TR_ModeManager Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager
#  define Rte_Write_Pp_Platform_ActiveFault_Table_De_ActiveFaultTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_ActiveFault_Table_De_ActiveFaultTable
#  define Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_ActiveFault_Table_De_ActiveFaultTable(data) (RTE_E_OK)
#  define Rte_Write_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable
#  define Rte_Write_Pp_RadarDiagRequestInterface_De_RadarDiagRequest Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_Rp_Get_FloatingPinPosition_FaultStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_Trigger_NvM_Erase_Operation() (RTE_E_UNCONNECTED)

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_FaultMgr_START_SEC_CODE
# include "SWC_PLT_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_General_Diagnostics_50ms RE_PLT_Fault_Mgr_General_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Init RE_PLT_Fault_Mgr_Init
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Main_10ms RE_PLT_Fault_Mgr_Main_10ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Main_50ms RE_PLT_Fault_Mgr_Main_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms
#  define RTE_RUNNABLE_RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms
# endif

FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_General_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Main_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_FaultMgr_CODE) RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_FaultMgr_STOP_SEC_CODE
# include "SWC_PLT_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_FAULTMGR_H */

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
