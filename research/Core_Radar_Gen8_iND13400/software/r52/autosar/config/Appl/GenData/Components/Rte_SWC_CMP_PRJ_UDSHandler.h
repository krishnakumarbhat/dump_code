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
 *             File:  Rte_SWC_CMP_PRJ_UDSHandler.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_CMP_PRJ_UDSHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_CMP_PRJ_UDSHANDLER_H
# define RTE_SWC_CMP_PRJ_UDSHANDLER_H

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

# include "Rte_SWC_CMP_PRJ_UDSHandler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault;

#  define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault (170U)
#  define Rte_InitValue_Rp_OperationModeType_De_OperationMode_System (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information(P2VAR(Dt_Auto_Alignment_Status_Information, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(P2VAR(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2VAR(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters(P2VAR(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters(P2VAR(Dt_Service_Alignment_Result_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T(P2VAR(DID_StaticAlignment_NonConfig_Param_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters(P2VAR(Dt_Static_Alignment_Engineering_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info(P2CONST(Idt_Cal_Version_Info_Type, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info(P2CONST(Dt_Customer_SW_Version, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC(P2CONST(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(P2CONST(Dt_SensorPosition_Data_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info(P2CONST(Idt_SW_Version_Info_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(P2CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information
#  define Rte_Read_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Read_Rp_OperationModeType_De_OperationMode_System Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_OperationModeType_De_OperationMode_System
#  define Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_OperationModeType_De_OperationMode_System(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData
#  define Rte_Read_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable
#  define Rte_Read_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL
#  define Rte_Read_Rp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters
#  define Rte_Read_Rp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters
#  define Rte_Read_Rp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T
#  define Rte_Read_Rp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Calibration_Version_Info_De_Calibration_Version_Info Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info
#  define Rte_Write_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info
#  define Rte_Write_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Write_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status
#  define Rte_Write_Pp_SW_Version_Info_De_SW_Version_Info Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info
#  define Rte_Write_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault
#  define Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault(data) (Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Dcm_START_SEC_CODE
#  include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define Dcm_STOP_SEC_CODE
#  include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define NvM_START_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, NvM_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define NvM_STOP_SEC_CODE
#  include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) CS_GetError_Status_Operation(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) NvM_Error_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) CS_ReadNvM_Value_Operation(P2VAR(Dt_SensorPosition_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) Sensorpos_Read_Record); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) CS_Get_Platform_Elapsed_ustime_read(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) inst_us_time, uint64 start_time); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) Get_PlatfromTime_us_read(P2VAR(uint64, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) instant_ustime); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PRJ_Appl_FaultMgr_START_SEC_CODE
#  include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) CS_Control_DTC_Service_Operation(uint8 Control); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PRJ_Appl_FaultMgr_STOP_SEC_CODE
#  include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PRJ_Appl_Security_Manager_START_SEC_CODE
#  include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_Compare_key_Operation(uint8 Security_Level, P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) Encrypted_key, P2VAR(Crypto_ResultType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) verify_Result); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_Compare_key_Operation(uint8 Security_Level, P2CONST(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) Encrypted_key, P2VAR(Crypto_ResultType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) verify_Result); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_PRJ_Appl_Security_Manager_STOP_SEC_CODE
#  include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PRJ_Appl_Security_Manager_START_SEC_CODE
#  include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_generate_seed_Operation(uint8 Security_level, P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) Seed_Value); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PRJ_Appl_Security_Manager_STOP_SEC_CODE
#  include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PRJ_Appl_SensorPosition_START_SEC_CODE
#  include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PRJ_Appl_SensorPosition_CODE) CS_Get_Pinposition_Status_Operation(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SENSORPOSITION_APPL_VAR) Sensor_Position); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PRJ_Appl_SensorPosition_STOP_SEC_CODE
#  include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Control_DTC_Service_Operation(arg1) (CS_Control_DTC_Service_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_GetError_Status_Operation(arg1) (CS_GetError_Status_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Get_Pinposition_Status_Operation(arg1) (CS_Get_Pinposition_Status_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_HSE_Security_Compare_key_Operation(arg1, arg2, arg3) (CS_HSE_Security_Compare_key_Operation(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_HSE_Security_generate_seed_Operation(arg1, arg2) (CS_HSE_Security_generate_seed_Operation(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_NvMService_AttemptCounter_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)22))
#  define Rte_Call_CS_NvMService_AttemptCounter_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)22, arg1))
#  define Rte_Call_CS_NvMService_AttemptCounter_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)22))
#  define Rte_Call_CS_NvMService_AttemptCounter_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)22, arg1))
#  define Rte_Call_CS_NvMService_AttemptCounter_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)22, arg1))
#  define Rte_Call_CS_NvMService_AttemptCounter_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)22, arg1))
#  define Rte_Call_CS_NvMService_AttemptCounter_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)22, arg1))
#  define Rte_Call_CS_NvMService_VIN_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)20, arg1))
#  define Rte_Call_CS_NvMService_VIN_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)20, arg1))
#  define Rte_Call_CS_NvMService_VIN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)20, arg1))
#  define Rte_Call_CS_NvM_Trigger_Write_NvHandler_Trigger_Write_To_NVM(arg1, arg2) (Trigger_Write_to_NVM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_ReadNvM_Value_Operation(arg1) (CS_ReadNvM_Value_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_UDS_Get_Platform_Elapsed_ustime_read(arg1, arg2) (CS_Get_Platform_Elapsed_ustime_read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_UDS_Get_PlatfromTime_us_read(arg1) (Get_PlatfromTime_us_read(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_DCMServices_GetSesCtrlType Dcm_GetSesCtrlType

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Dt_VIN_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_VIN_DefaultValue;
extern CONST(AttempCounter_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_Attemptcounter_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_SWC_UDSHandler_VIN_DefaultValue() (&(Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_VIN_DefaultValue[0]))
#  else
#   define Rte_CData_SWC_UDSHandler_VIN_DefaultValue() (&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_VIN_DefaultValue)
#  endif

#  define Rte_CData_SWC_UDSHandler_Attemptcounter_DefaultValue() (&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_Attemptcounter_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_VIN_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN;
extern VAR(AttempCounter_Type, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_AttemptCounter;

#   define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_SWC_UDS_VIN() (&((*RtePim_SWC_UDS_VIN())[0]))
#  else
#   define Rte_Pim_SWC_UDS_VIN() RtePim_SWC_UDS_VIN()
#  endif
#  define RtePim_SWC_UDS_VIN() \
          (&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SWC_UDS_AttemptCounter() \
          (&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_AttemptCounter)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
# include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CSCallbackDTCStatusChange_DTCStatusChanged CSCallbackDTCStatusChange_DTCStatusChanged
#  define RTE_RUNNABLE_CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0x1111_ECUVoltage_ReadData DataServices_Data_0x1111_ECUVoltage_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0x1112_VehicleSpeed_ReadData DataServices_Data_0x1112_VehicleSpeed_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0x1116_DateandTime_ConditionCheckRead DataServices_Data_0x1116_DateandTime_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0x1116_DateandTime_ReadData DataServices_Data_0x1116_DateandTime_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xA000_SerialNumber_ConditionCheckRead DataServices_Data_0xA000_SerialNumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xA000_SerialNumber_ReadData DataServices_Data_0xA000_SerialNumber_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xA001_SoftwareNumber_ReadData DataServices_Data_0xA001_SoftwareNumber_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xA004_Ego_Acceleration_ReadData DataServices_Data_0xA004_Ego_Acceleration_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF010_Vehicle_Variant_ReadData DataServices_Data_0xF010_Vehicle_Variant_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData
#  define RTE_RUNNABLE_DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF017_Pin_Position_Status_ReadData DataServices_Data_0xF017_Pin_Position_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData
#  define RTE_RUNNABLE_DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF150_Hardware_Version_number_ReadData DataServices_Data_0xF150_Hardware_Version_number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF15A_Software_Fingerprint_ReadData DataServices_Data_0xF15A_Software_Fingerprint_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF15A_Software_Fingerprint_WriteData DataServices_Data_0xF15A_Software_Fingerprint_WriteData
#  define RTE_RUNNABLE_DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF16A_Boot_App_Identification_ReadData DataServices_Data_0xF16A_Boot_App_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF180_BootloaderNumber_ReadData DataServices_Data_0xF180_BootloaderNumber_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF189_Base_Software_Version_number_ReadData DataServices_Data_0xF189_Base_Software_Version_number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF18B_ECUBuildDate_ReadData DataServices_Data_0xF18B_ECUBuildDate_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF190_VIN_ConditionCheckRead DataServices_Data_0xF190_VIN_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF190_VIN_ReadData DataServices_Data_0xF190_VIN_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF190_VIN_WriteData DataServices_Data_0xF190_VIN_WriteData
#  define RTE_RUNNABLE_DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF191_HardwareNumber_ReadData DataServices_Data_0xF191_HardwareNumber_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF19D_CANDBMatrixVer_ReadData DataServices_Data_0xF19D_CANDBMatrixVer_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData
#  define RTE_RUNNABLE_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms RE_SWC_CMP_PRJ_UDSHandler_Main_50ms
#  define RTE_RUNNABLE_RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start
#  define RTE_RUNNABLE_SecurityAccess_Unlocked_L1_CompareKey SecurityAccess_Unlocked_L1_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter
#  define RTE_RUNNABLE_SecurityAccess_Unlocked_L1_GetSeed SecurityAccess_Unlocked_L1_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter
#  define RTE_RUNNABLE_ServiceRequestNotification_Confirmation ServiceRequestNotification_Confirmation
#  define RTE_RUNNABLE_ServiceRequestNotification_Indication ServiceRequestNotification_Indication
# endif

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSCallbackDTCStatusChange_DTCStatusChanged(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData(P2VAR(DataArrayType_uint8_7, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUVoltage_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUVoltage_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VehicleSpeed_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VehicleSpeed_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_DateandTime_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_DateandTime_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Sensor_Availability_Flag_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SerialNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SerialNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SoftwareNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Dataset_Part_No_and_Revision_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SMC_Part_No_and_Revision_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Ego_Acceleration_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Ego_Acceleration_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Vehicle_Variant_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Vehicle_Variant_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Read_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Read_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData(P2CONST(Dcm_DataElement_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData(P2CONST(Dcm_DataElement_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Result_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Result_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Auto_Alignment_Status_Information_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Auto_Alignment_Status_Information_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Pin_Position_Status_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Pin_Position_Status_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Manual_Alignment_Execution_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData(P2CONST(Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData(P2CONST(Dcm_DataElement_Data_Manual_Alignment_Execution_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Result_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Result_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Hardware_Version_number_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Hardware_Version_number_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Software_Fingerprint_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_WriteData(P2CONST(Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_WriteData(P2CONST(Dcm_DataElement_Data_Software_Fingerprint_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Boot_App_Identification_DID_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Boot_App_Identification_DID_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_BootloaderNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_BootloaderNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Base_Software_Version_number_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Base_Software_Version_number_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUBuildDate_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUBuildDate_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VIN_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VIN_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_WriteData(P2CONST(Dcm_DataElement_Data_VIN_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_WriteData(P2CONST(Dcm_DataElement_Data_VIN_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_HardwareNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_HardwareNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_CANDBMatrixVer_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_CANDBMatrixVer_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_PCAN_DBC_Version_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_PCAN_DBC_Version_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Read_Active_Fault_Table_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Read_Active_Fault_Table_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(void, SWC_CMP_PRJ_UDSHandler_CODE) RE_SWC_CMP_PRJ_UDSHandler_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgPreCond_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgPreCond_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_CompareKey(P2CONST(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) AttemptCounter); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Indication(uint8 SID, P2CONST(Dcm_Data96ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif

# define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
# include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_Data_DID_0x1111_ECUVoltage_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1112_VehicleSpeed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1116_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1117_Sensor_Availability_Flag_Information_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0xa004_Ego_Acceleration_E_NOT_OK (1U)

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Auto_Alignment_Status_Information_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Auto_Alignment_Status_Information_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Base_Software_Version_number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Base_Software_Version_number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Boot_App_Identification_DID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Boot_App_Identification_DID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_BootloaderNumber_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_BootloaderNumber_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_CANDBMatrixVer_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_CANDBMatrixVer_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Dataset_Part_No_and_Revision_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Dataset_Part_No_and_Revision_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_DateandTime_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_DateandTime_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_ECUBuildDate_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_ECUBuildDate_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_ECUVoltage_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_ECUVoltage_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Ego_Acceleration_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Ego_Acceleration_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_HardwareNumber_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_HardwareNumber_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Hardware_Version_number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Hardware_Version_number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Manual_Alignment_Execution_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Manual_Alignment_Execution_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_PCAN_DBC_Version_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_PCAN_DBC_Version_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Pin_Position_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Pin_Position_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Read_Active_Fault_Table_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Read_Active_Fault_Table_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_SMC_Part_No_and_Revision_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_SMC_Part_No_and_Revision_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Sensor_Availability_Flag_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Sensor_Availability_Flag_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_SerialNumber_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_SerialNumber_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Service_Alignment_Result_Parameters_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Service_Alignment_Result_Parameters_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_SoftwareNumber_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_SoftwareNumber_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Software_Fingerprint_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Software_Fingerprint_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Static_Alignment_Result_Parameters_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Static_Alignment_Result_Parameters_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_VIN_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_VIN_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_VehicleSpeed_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_VehicleSpeed_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Vehicle_Variant_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Vehicle_Variant_Read_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Lock_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Lock_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Lock_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Unlock_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Unlock_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Pin_Position_Unlock_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_CMP_PRJ_UDSHANDLER_H */

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
