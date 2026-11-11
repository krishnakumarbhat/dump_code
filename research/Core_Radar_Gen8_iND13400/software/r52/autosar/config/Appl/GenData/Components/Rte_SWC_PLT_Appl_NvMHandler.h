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
 *             File:  Rte_SWC_PLT_Appl_NvMHandler.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_NvMHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_H
# define RTE_SWC_PLT_APPL_NVMHANDLER_H

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

# include "Rte_SWC_PLT_Appl_NvMHandler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_NvM_flag_status_Pim_write_status (0U)
#  define Rte_InitValue_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault (170U)
#  define Rte_InitValue_Rp_R1_NCF_Count_R1_NCF_Count (0U)
#  define Rte_InitValue_Rp_Vbatt_State_Volt_De_Vbatt_State (0U)
#  define Rte_InitValue_Rp_XCP_Program_Mode_De_XCP_Program_Mode (FALSE)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Align_Write_Nvm_Record_Alignment_Record(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(P2VAR(Dt_ECC_Correctable_Error_Counters, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2VAR(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(P2VAR(Dt_SensorPosition_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_RFE_NvM_Data_De_RFE_NvM_Data(P2VAR(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_VSE_NVM_Params_De_VSE_NVM_Params(P2VAR(Dt_VSE_NVM_Params, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2CONST(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data(P2CONST(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Align_Write_Nvm_Record_Alignment_Record Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Align_Write_Nvm_Record_Alignment_Record
#  define Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault
#  define Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason
#  define Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(data) (*(data) = Rte_C_Dt_Manual_Alignment_Execution_Data_CRC_D239E83BEA087CE8D08EBACC2DD214A6, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status
#  define Rte_Read_Rp_R1_NCF_Count_R1_NCF_Count Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_R1_NCF_Count_R1_NCF_Count
#  define Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_R1_NCF_Count_R1_NCF_Count(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_RFE_NvM_Data_De_RFE_NvM_Data
#  define Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
#  define Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(data) (*(data) = Rte_C_Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_CDCCBF02DA3C25359EC6D6D27E2A3DA2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_VSE_NVM_Params_De_VSE_NVM_Params
#  define Rte_Read_Rp_Vbatt_State_Volt_De_Vbatt_State Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Vbatt_State_Volt_De_Vbatt_State
#  define Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Vbatt_State_Volt_De_Vbatt_State(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Program_Mode_De_XCP_Program_Mode Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_XCP_Program_Mode_De_XCP_Program_Mode
#  define Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_XCP_Program_Mode_De_XCP_Program_Mode(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Alignment_NvM_Data_Alignment_NvM_Data Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data
#  define Rte_Write_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data
#  define Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason
#  define Rte_Write_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC
#  define Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(data) (RTE_E_OK)
#  define Rte_Write_Pp_NvM_flag_status_Pim_write_status Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status
#  define Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status(data) (Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data
#  define Rte_Write_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault
#  define Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault(data) (Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
#  define Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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

#  define Rte_Call_CS_NvMService_ManualAlignment_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)23))
#  define Rte_Call_CS_NvMService_ManualAlignment_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)23, arg1))
#  define Rte_Call_CS_NvMService_ManualAlignment_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)23))
#  define Rte_Call_CS_NvMService_ManualAlignment_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)23, arg1))
#  define Rte_Call_CS_NvMService_ManualAlignment_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)23, arg1))
#  define Rte_Call_CS_NvMService_ManualAlignment_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)23, arg1))
#  define Rte_Call_CS_NvMService_ManualAlignment_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)23, arg1))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)24))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)24, arg1))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)24))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)24, arg1))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)24, arg1))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)24, arg1))
#  define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)24, arg1))
#  define Rte_Call_CS_NvMService_VSE_Parameters_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)25))
#  define Rte_Call_CS_NvMService_VSE_Parameters_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)25, arg1))
#  define Rte_Call_CS_NvMService_VSE_Parameters_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)25))
#  define Rte_Call_CS_NvMService_VSE_Parameters_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)25, arg1))
#  define Rte_Call_CS_NvMService_VSE_Parameters_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)25, arg1))
#  define Rte_Call_CS_NvMService_VSE_Parameters_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)25, arg1))
#  define Rte_Call_CS_NvMService_VSE_Parameters_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)25, arg1))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)21))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)21, arg1))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)21))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)21, arg1))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)21, arg1))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)21, arg1))
#  define Rte_Call_Rp_CDD_SensorPos_UDS_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)21, arg1))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)3))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)3, arg1))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)3))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)3, arg1))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)3, arg1))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)3, arg1))
#  define Rte_Call_Rp_PS_Swc_NvMBringup_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)3, arg1))
#  define Rte_Call_Rp_PS_Swc_Xcp_Alignment_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)2))
#  define Rte_Call_Rp_PS_Swc_Xcp_Alignment_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)2, arg1))
#  define Rte_Call_Rp_PS_Swc_Xcp_Alignment_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)2, arg1))
#  define Rte_Call_Rp_PS_Swc_Xcp_Alignment_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)2, arg1))
#  define Rte_Call_Rp_PS_Swc_Xcp_Alignment_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)2, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)7))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)7, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)7))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)7, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)7, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)7, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)7, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)5, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)5, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)5, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)4))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)4, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)4, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)4, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)4, arg1))
#  define Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)4, arg1))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_Alignment_NvMBlock_DefaultValue;
extern CONST(Dt_ECC_Correctable_Error_Counters, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_NvM_DefaultValue;
extern CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_DefaultValue;
extern CONST(Dt_Rfe_REC_NREC_Fault, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_Fault_NvM_DefaultValue;
extern CONST(Dt_Manual_Alignment_Execution_Data_CRC, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_Manual_alignment_Execution_DefaultValue;
extern CONST(Dt_FailSafe_ResetReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_PLT_CDD_FailSafe_DefaultValue;
extern CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_Static_Alignment_Write_Parameters_DefaultValue;
extern CONST(Dt_VSE_NVM_Params, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_VSE_NVM_Params_DefaultValue;
extern CONST(Dt_SensorPosition_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SensorPos_NvM_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_Alignment_NvMBlock_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_Alignment_NvMBlock_DefaultValue)

#  define Rte_CData_Correctable_Fault_NvM_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_NvM_DefaultValue)

#  define Rte_CData_NvMBringUp_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_DefaultValue)

#  define Rte_CData_RFE_R1R2_Fault_NvM_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_Fault_NvM_DefaultValue)

#  define Rte_CData_SWC_Manual_alignment_Execution_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_SWC_Manual_alignment_Execution_DefaultValue)

#  define Rte_CData_SWC_PLT_CDD_FailSafe_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_SWC_PLT_CDD_FailSafe_DefaultValue)

#  define Rte_CData_SWC_Static_Alignment_Write_Parameters_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_SWC_Static_Alignment_Write_Parameters_DefaultValue)

#  define Rte_CData_SWC_VSE_NVM_Params_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_SWC_VSE_NVM_Params_DefaultValue)

#  define Rte_CData_SensorPos_NvM_DefaultValue() (&Rte_SWC_PLT_Appl_NvMHandler_SensorPos_NvM_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM;
extern VAR(Dt_ECC_Correctable_Error_Counters, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_PIM;
extern VAR(Dt_FailSafe_ResetReason_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_FailSafe_ResetReason_PIM;
extern VAR(Dt_Manual_Alignment_Execution_Data_CRC, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Manual_Alignment_Execution_Data_PIM;
extern VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM;
extern VAR(Dt_Rfe_REC_NREC_Fault, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_PIM;
extern VAR(Dt_SensorPosition_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Sensorpos_PIM_UDS;
extern VAR(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM;
extern VAR(Dt_VSE_NVM_Params, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_VSE_NVM_Params_PIM;

#   define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Appl_Alignment_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Correctable_Fault_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_FailSafe_ResetReason_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_FailSafe_ResetReason_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Manual_Alignment_Execution_Data_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_Manual_Alignment_Execution_Data_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvMBringUp_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RFE_R1R2_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Sensorpos_PIM_UDS() \
          (&Rte_SWC_PLT_Appl_NvMHandler_Sensorpos_PIM_UDS)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_VSE_NVM_Params_PIM() \
          (&Rte_SWC_PLT_Appl_NvMHandler_VSE_NVM_Params_PIM)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
# include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_GetError_Status_Operation CS_GetError_Status_Operation
#  define RTE_RUNNABLE_CS_ReadNvM_Value_Operation CS_ReadNvM_Value_Operation
#  define RTE_RUNNABLE_RE_PLT_Appl_NvMHandler_50ms RE_PLT_Appl_NvMHandler_50ms
#  define RTE_RUNNABLE_RE_PLT_Appl_NvMHandler_5ms RE_PLT_Appl_NvMHandler_5ms
#  define RTE_RUNNABLE_SWC_PLT_Appl_NvMHandler_Init SWC_PLT_Appl_NvMHandler_Init
#  define RTE_RUNNABLE_Trigger_Write_to_NVM Trigger_Write_to_NVM
# endif

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) CS_GetError_Status_Operation(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) NvM_Error_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) CS_ReadNvM_Value_Operation(P2VAR(Dt_SensorPosition_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) Sensorpos_Read_Record); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) RE_PLT_Appl_NvMHandler_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) RE_PLT_Appl_NvMHandler_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) SWC_PLT_Appl_NvMHandler_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
# include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_NVMHANDLER_H */

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
