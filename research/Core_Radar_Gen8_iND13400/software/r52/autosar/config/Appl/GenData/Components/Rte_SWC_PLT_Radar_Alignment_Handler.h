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
 *             File:  Rte_SWC_PLT_Radar_Alignment_Handler.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Radar_Alignment_Handler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_H
# define RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_H

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

# include "Rte_SWC_PLT_Radar_Alignment_Handler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_AlignmentModeIn_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type;
extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Rp_Alignment_Type_Alignment_Type (0U)
#  define Rte_InitValue_Rp_OperationMode_Type_De_OperationMode_System (0U)
#  define Rte_InitValue_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag (85U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data(P2VAR(Dt_Alignment_IPC_Data, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_NvM_Data_Alignment_NvM_Data(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC(P2VAR(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(P2VAR(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto(P2CONST(Dt_AlignmentAuto, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService(P2CONST(Dt_AlignmentService, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack(P2CONST(Dt_AlignmentShortTrack, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic(P2CONST(Dt_AlignmentStatic, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults(P2CONST(Dt_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler(P2CONST(Dt_Alignment_Handler, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data(P2CONST(Dt_Alignment_M2D_Data, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data(P2CONST(Dt_Auto_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information(P2CONST(Dt_Auto_Alignment_Status_Information, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result(P2CONST(Dt_Initial_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(P2CONST(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters(P2CONST(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters(P2CONST(Dt_Service_Alignment_Result_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T(P2CONST(DID_StaticAlignment_NonConfig_Param_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters(P2CONST(Dt_Static_Alignment_Engineering_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform(P2CONST(Dt_Initial_Alignment_Performance_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_Radar_Alignment_Handler_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data
#  define Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_NvM_Data_Alignment_NvM_Data
#  define Rte_Read_Rp_Alignment_Type_Alignment_Type Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Type_Alignment_Type
#  define Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Type_Alignment_Type(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM
#  define Rte_Read_Rp_IPC_SWC_AutoAlignment_Input_De_AutoAlignment Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_IPC_SWC_AutoAlignment_Input_De_AutoAlignment
#  define Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_IPC_SWC_AutoAlignment_Input_De_AutoAlignment(data) (*(data) = Rte_C_AutoAlignment_NvM_T_Dt_Alignment_NVM_T, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Read_Rp_OperationMode_Type_De_OperationMode_System Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_OperationMode_Type_De_OperationMode_System
#  define Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_OperationMode_Type_De_OperationMode_System(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
#  define Rte_Read_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag
#  define Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Align_Write_Nvm_Record_Alignment_Record Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record
#  define Rte_Write_Pp_AlignmentAuto_De_AlignmentAuto Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto
#  define Rte_Write_Pp_AlignmentService_De_AlignmentService Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService
#  define Rte_Write_Pp_AlignmentShortTrack_De_AlignmentShortTrack Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack
#  define Rte_Write_Pp_AlignmentStatic_De_AlignmentStatic Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic
#  define Rte_Write_Pp_Alignment_Faults_De_Alignment_Faults Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults
#  define Rte_Write_Pp_Alignment_Handler_De_Alignment_Handler Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler
#  define Rte_Write_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data
#  define Rte_Write_Pp_Auto_Alignment_Data_Auto_Alignment_Data Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data
#  define Rte_Write_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information
#  define Rte_Write_Pp_IPC_SWC_AutoAlignment_Output_De_AutoAlignment Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_IPC_SWC_AutoAlignment_Output_De_AutoAlignment
#  define Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_IPC_SWC_AutoAlignment_Output_De_AutoAlignment(data) (RTE_E_OK)
#  define Rte_Write_Pp_Initial_Alignment_Result_Initial_Alignment_Result Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result
#  define Rte_Write_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Write_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters
#  define Rte_Write_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters
#  define Rte_Write_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T
#  define Rte_Write_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters
#  define Rte_Write_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

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

#  define Rte_Call_CS_Get_Platform_Elapsed_ustime_read(arg1, arg2) (CS_Get_Platform_Elapsed_ustime_read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Get_PlatfromTime_us_read(arg1) (Get_PlatfromTime_us_read(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Rp_Trigger_Write_to_NvM_NvHandler_Trigger_Write_To_NVM(arg1, arg2) (Trigger_Write_to_NVM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM Rte_Call_SWC_PLT_Radar_Alignment_Handler_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM
#  define Rte_Call_Ecu_Shutdown_Request_Ecu_Shutdown_Request(arg1, arg2) (RTE_E_UNCONNECTED)

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Dt_Alignment_NVM_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Radar_Alignment_Handler_Appl_AutoAlignment_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_Appl_AutoAlignment_DefaultValue() (&Rte_SWC_PLT_Radar_Alignment_Handler_Appl_AutoAlignment_DefaultValue)

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Radar_Alignment_Handler_START_SEC_CODE
# include "SWC_PLT_Radar_Alignment_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Alignment_Fault_Injection_read CS_Alignment_Fault_Injection_read
#  define RTE_RUNNABLE_RE_Alignment_Init RE_Alignment_Init
#  define RTE_RUNNABLE_RE_Alignment_Main_50ms RE_Alignment_Main_50ms
# endif

FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE) CS_Alignment_Fault_Injection_read(uint8 Injection_control); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE) RE_Alignment_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE) RE_Alignment_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Radar_Alignment_Handler_STOP_SEC_CODE
# include "SWC_PLT_Radar_Alignment_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Ecu_Shutdown_Request_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_H */

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
