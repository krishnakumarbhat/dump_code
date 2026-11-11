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
 *             File:  Rte_SWC_PLT_CDD_Radar_Control.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_Radar_Control>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_RADAR_CONTROL_H
# define RTE_SWC_PLT_CDD_RADAR_CONTROL_H

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

# include "Rte_SWC_PLT_CDD_Radar_Control_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode;
extern VAR(Idt_XCP_Op_Mode_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_MMIC_Count_De_MMIC_Count (0U)
#  define Rte_InitValue_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate (0U)
#  define Rte_InitValue_Pp_Radar_Init_Status_De_Radar_Init_Status (0U)
#  define Rte_InitValue_Rp_Command_Radiate_Final_De_CommandRadiate_Final (170U)
#  define Rte_InitValue_Rp_IsRadiateForced_De_IsRadiateForced (85U)
#  define Rte_InitValue_Rp_XCP_CW_Mode_De_XCP_CW_Mode (0U)
#  define Rte_InitValue_Rp_XCP_Op_Mode_De_XCP_Op_Mode (0U)
#  define Rte_InitValue_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration (FALSE)
#  define Rte_InitValue_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger (85U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_RFE_NvM_Data_De_RFE_NvM_Data(P2VAR(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(P2CONST(Dt_MMIC_ErrorFlags, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature(P2CONST(Idt_Type_MMIC_Temperature, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data(P2CONST(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus(P2CONST(Dt_RadarCoreStatus, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_Command_Radiate_Final_De_CommandRadiate_Final
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_Command_Radiate_Final_De_CommandRadiate_Final(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_IsRadiateForced_De_IsRadiateForced Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_IsRadiateForced_De_IsRadiateForced
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_IsRadiateForced_De_IsRadiateForced(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_RFE_NvM_Data_De_RFE_NvM_Data
#  define Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_CW_Mode_De_XCP_CW_Mode
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_CW_Mode_De_XCP_CW_Mode(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Op_Mode_De_XCP_Op_Mode Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Op_Mode_De_XCP_Op_Mode
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Op_Mode_De_XCP_Op_Mode(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger
#  define Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags
#  define Rte_Write_Pp_MMIC_Count_De_MMIC_Count Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count
#  define Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count(data) (Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MMIC_Temperature_De_MMIC_Temperature Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature
#  define Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data
#  define Rte_Write_Pp_RadarCoreStatus_De_RadarCoreStatus Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus
#  define Rte_Write_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate
#  define Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate(data) (Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Radar_Init_Status_De_Radar_Init_Status Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status
#  define Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status(data) (Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> for asynchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_PostRadarProcessing_ADC_Populate_ADC_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream
#  define Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx
#  define Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream
#  define Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream
#  define Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream
#  define Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream
#  define Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream
#  define Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
#  define Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_IntWDG_START_SEC_CODE
#  include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) CS_Disable_Wdg_Supervised_Entites_Operation(uint8 disable_SE_Flag); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_IntWDG_STOP_SEC_CODE
#  include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_FailSafe_START_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation(arg1) (CS_Disable_Wdg_Supervised_Entites_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_FailSafe_Log_ResetReason_FailSafe_Log_ResetReason(arg1) (FailSafe_Log_ResetReason(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM(arg1, arg2) (Trigger_Write_to_NVM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_Radar_Control_START_SEC_CODE
# include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Radar_control_Fault_Injection_Read CS_Radar_control_Fault_Injection_Read
#  define RTE_RUNNABLE_RE_Radar_Control_10ms RE_Radar_Control_10ms
#  define RTE_RUNNABLE_RE_Radar_Control_50ms RE_Radar_Control_50ms
#  define RTE_RUNNABLE_RE_Radar_Control_Init RE_Radar_Control_Init
#  define RTE_RUNNABLE_RE_Radar_Ctl_Look_Complete RE_Radar_Ctl_Look_Complete
#  define RTE_RUNNABLE_RE_Radar_Ctl_Look_Complete_Post_RFBIST RE_Radar_Ctl_Look_Complete_Post_RFBIST
#  define RTE_RUNNABLE_RE_Radar_Ctl_Look_Trigger RE_Radar_Ctl_Look_Trigger
#  define RTE_RUNNABLE_RE_Test RE_Test
# endif

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) CS_Radar_control_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Ctl_Look_Complete(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Ctl_Look_Complete_Post_RFBIST(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Ctl_Look_Trigger(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Test(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_CDD_Radar_Control_STOP_SEC_CODE
# include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_PostRadarProcessing_ADC_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_ADC_E_OK (0U)

#  define RTE_E_PostRadarProcessing_CAN_Tx_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_CAN_Tx_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Debug_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Debug_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Detection_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Detection_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Header_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Header_E_OK (0U)

#  define RTE_E_PostRadarProcessing_MMIC_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_MMIC_E_OK (0U)

#  define RTE_E_PostRadarProcessing_RDD_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_RDD_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Radar_Capability_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Status_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Status_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_RADAR_CONTROL_H */

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
