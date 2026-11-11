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
 *             File:  Rte_Dcm.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DCM_H
# define RTE_DCM_H

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

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void);
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckProgDep_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgDep_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckProgDep_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgDep_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckSig_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckSig_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckSig_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckSig_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_EraseMem_Start_Start(P2CONST(Dcm_StartDataIn_Routine_EraseMem_Start_In_ReqDataArrayType, AUTOMATIC, RTE_DCM_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_EraseMem_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_EraseMem_Start_Start(P2CONST(Dcm_StartDataIn_Routine_EraseMem_Start_In_ReqDataType, AUTOMATIC, RTE_DCM_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_EraseMem_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Auto_Alignment_Status_Information_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Auto_Alignment_Status_Information_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Base_Software_Version_number_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF189_Base_Software_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Base_Software_Version_number_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Boot_App_Identification_DID_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF16A_Boot_App_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Boot_App_Identification_DID_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_BootloaderNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF180_BootloaderNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_BootloaderNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_CANDBMatrixVer_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19D_CANDBMatrixVer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_CANDBMatrixVer_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Dataset_Part_No_and_Revision_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_DateandTime_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1116_DateandTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_DateandTime_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUBuildDate_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF18B_ECUBuildDate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUBuildDate_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUVoltage_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1111_ECUVoltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_ECUVoltage_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Ego_Acceleration_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA004_Ego_Acceleration_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Ego_Acceleration_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_HardwareNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF191_HardwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_HardwareNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Hardware_Version_number_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF150_Hardware_Version_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Hardware_Version_number_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Manual_Alignment_Execution_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData(P2CONST(Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData(P2CONST(Dcm_DataElement_Data_Manual_Alignment_Execution_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_PCAN_DBC_Version_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_PCAN_DBC_Version_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Pin_Position_Status_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF017_Pin_Position_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Pin_Position_Status_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Read_Active_Fault_Table_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Read_Active_Fault_Table_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SMC_Part_No_and_Revision_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Sensor_Availability_Flag_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SerialNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA000_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SerialNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Result_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Service_Alignment_Result_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xA001_SoftwareNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_SoftwareNumber_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Software_Fingerprint_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_WriteData(P2CONST(Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF15A_Software_Fingerprint_WriteData(P2CONST(Dcm_DataElement_Data_Software_Fingerprint_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Read_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Engineering_Read_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData(P2CONST(Dcm_DataElement_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData(P2CONST(Dcm_DataElement_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Result_Parameters_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Static_Alignment_Result_Parameters_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VIN_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VIN_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_WriteData(P2CONST(Dcm_DataElement_Data_VIN_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF190_VIN_WriteData(P2CONST(Dcm_DataElement_Data_VIN_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VehicleSpeed_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0x1112_VehicleSpeed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_VehicleSpeed_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Vehicle_Variant_Read_ArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) DataServices_Data_0xF010_Vehicle_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_DataElement_Data_Vehicle_Variant_ReadType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgPreCond_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgPreCond_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(P2CONST(Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_CompareKey(P2CONST(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) AttemptCounter); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CMP_PRJ_UDSHandler_START_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, SWC_CMP_PRJ_UDSHandler_CODE) ServiceRequestNotification_Indication(uint8 SID, P2CONST(Dcm_Data96ByteType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
#  endif

#  define SWC_CMP_PRJ_UDSHandler_STOP_SEC_CODE
#  include "SWC_CMP_PRJ_UDSHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_ConditionCheckRead DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead
#  define Rte_Call_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_ReadData DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData
#  define Rte_Call_DataServices_Data_Auto_Alignment_Status_Information_Read_ConditionCheckRead DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Auto_Alignment_Status_Information_Read_ReadData DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData
#  define Rte_Call_DataServices_Data_Base_Software_Version_number_Read_ConditionCheckRead DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Base_Software_Version_number_Read_ReadData DataServices_Data_0xF189_Base_Software_Version_number_ReadData
#  define Rte_Call_DataServices_Data_Boot_App_Identification_DID_Read_ConditionCheckRead DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Boot_App_Identification_DID_Read_ReadData DataServices_Data_0xF16A_Boot_App_Identification_ReadData
#  define Rte_Call_DataServices_Data_BootloaderNumber_Read_ConditionCheckRead DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead
#  define Rte_Call_DataServices_Data_BootloaderNumber_Read_ReadData DataServices_Data_0xF180_BootloaderNumber_ReadData
#  define Rte_Call_DataServices_Data_CANDBMatrixVer_Read_ConditionCheckRead DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead
#  define Rte_Call_DataServices_Data_CANDBMatrixVer_Read_ReadData DataServices_Data_0xF19D_CANDBMatrixVer_ReadData
#  define Rte_Call_DataServices_Data_Dataset_Part_No_and_Revision_Read_ConditionCheckRead DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Dataset_Part_No_and_Revision_Read_ReadData DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData
#  define Rte_Call_DataServices_Data_DateandTime_Read_ConditionCheckRead DataServices_Data_0x1116_DateandTime_ConditionCheckRead
#  define Rte_Call_DataServices_Data_DateandTime_Read_ReadData DataServices_Data_0x1116_DateandTime_ReadData
#  define Rte_Call_DataServices_Data_ECUBuildDate_Read_ConditionCheckRead DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead
#  define Rte_Call_DataServices_Data_ECUBuildDate_Read_ReadData DataServices_Data_0xF18B_ECUBuildDate_ReadData
#  define Rte_Call_DataServices_Data_ECUVoltage_Read_ConditionCheckRead DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead
#  define Rte_Call_DataServices_Data_ECUVoltage_Read_ReadData DataServices_Data_0x1111_ECUVoltage_ReadData
#  define Rte_Call_DataServices_Data_Ego_Acceleration_Read_ConditionCheckRead DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Ego_Acceleration_Read_ReadData DataServices_Data_0xA004_Ego_Acceleration_ReadData
#  define Rte_Call_DataServices_Data_HardwareNumber_Read_ConditionCheckRead DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead
#  define Rte_Call_DataServices_Data_HardwareNumber_Read_ReadData DataServices_Data_0xF191_HardwareNumber_ReadData
#  define Rte_Call_DataServices_Data_Hardware_Version_number_Read_ConditionCheckRead DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Hardware_Version_number_Read_ReadData DataServices_Data_0xF150_Hardware_Version_number_ReadData
#  define Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_ConditionCheckRead DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_ReadData DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData
#  define Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_WriteData DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData
#  define Rte_Call_DataServices_Data_PCAN_DBC_Version_Read_ConditionCheckRead DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Data_PCAN_DBC_Version_Read_ReadData DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData
#  define Rte_Call_DataServices_Data_Pin_Position_Status_Read_ConditionCheckRead DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Pin_Position_Status_Read_ReadData DataServices_Data_0xF017_Pin_Position_Status_ReadData
#  define Rte_Call_DataServices_Data_Read_Active_Fault_Table_Read_ConditionCheckRead DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Read_Active_Fault_Table_Read_ReadData DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData
#  define Rte_Call_DataServices_Data_SMC_Part_No_and_Revision_Read_ConditionCheckRead DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead
#  define Rte_Call_DataServices_Data_SMC_Part_No_and_Revision_Read_ReadData DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData
#  define Rte_Call_DataServices_Data_Sensor_Availability_Flag_Read_ConditionCheckRead DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Sensor_Availability_Flag_Read_ReadData DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData
#  define Rte_Call_DataServices_Data_SerialNumber_Read_ConditionCheckRead DataServices_Data_0xA000_SerialNumber_ConditionCheckRead
#  define Rte_Call_DataServices_Data_SerialNumber_Read_ReadData DataServices_Data_0xA000_SerialNumber_ReadData
#  define Rte_Call_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ConditionCheckRead DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ReadData DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData
#  define Rte_Call_DataServices_Data_Service_Alignment_Result_Parameters_Read_ConditionCheckRead DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Service_Alignment_Result_Parameters_Read_ReadData DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData
#  define Rte_Call_DataServices_Data_SoftwareNumber_Read_ConditionCheckRead DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead
#  define Rte_Call_DataServices_Data_SoftwareNumber_Read_ReadData DataServices_Data_0xA001_SoftwareNumber_ReadData
#  define Rte_Call_DataServices_Data_Software_Fingerprint_Read_ConditionCheckRead DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Software_Fingerprint_Read_ReadData DataServices_Data_0xF15A_Software_Fingerprint_ReadData
#  define Rte_Call_DataServices_Data_Software_Fingerprint_Read_WriteData DataServices_Data_0xF15A_Software_Fingerprint_WriteData
#  define Rte_Call_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ConditionCheckRead DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ReadData DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData
#  define Rte_Call_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_ConditionCheckRead DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_ReadData DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData
#  define Rte_Call_DataServices_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_WriteData DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData
#  define Rte_Call_DataServices_Data_Static_Alignment_Result_Parameters_Read_ConditionCheckRead DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Static_Alignment_Result_Parameters_Read_ReadData DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData
#  define Rte_Call_DataServices_Data_VIN_Read_ConditionCheckRead DataServices_Data_0xF190_VIN_ConditionCheckRead
#  define Rte_Call_DataServices_Data_VIN_Read_ReadData DataServices_Data_0xF190_VIN_ReadData
#  define Rte_Call_DataServices_Data_VIN_Read_WriteData DataServices_Data_0xF190_VIN_WriteData
#  define Rte_Call_DataServices_Data_VehicleSpeed_Read_ConditionCheckRead DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead
#  define Rte_Call_DataServices_Data_VehicleSpeed_Read_ReadData DataServices_Data_0x1112_VehicleSpeed_ReadData
#  define Rte_Call_DataServices_Data_Vehicle_Variant_Read_ConditionCheckRead DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Vehicle_Variant_Read_ReadData DataServices_Data_0xF010_Vehicle_Variant_ReadData
#  define Rte_Call_RoutineServices_Routine_CheckProgDep_Start_Start Rte_Call_Dcm_RoutineServices_Routine_CheckProgDep_Start_Start
#  define Rte_Call_RoutineServices_Routine_CheckProgPreCond_Start_Start RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start
#  define Rte_Call_RoutineServices_Routine_CheckSig_Start_Start Rte_Call_Dcm_RoutineServices_Routine_CheckSig_Start_Start
#  define Rte_Call_RoutineServices_Routine_EraseMem_Start_Start Rte_Call_Dcm_RoutineServices_Routine_EraseMem_Start_Start
#  define Rte_Call_RoutineServices_Routine_Pin_Position_Lock_Start_RequestResults RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_Pin_Position_Lock_Start_Start RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start
#  define Rte_Call_RoutineServices_Routine_Pin_Position_Unlock_Start_RequestResults RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_Pin_Position_Unlock_Start_Start RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start
#  define Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_RequestResults RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_Start RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start
#  define Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_Stop RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop
#  define Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_RequestResults RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_Start RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start
#  define Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_Stop RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop
#  define Rte_Call_SecurityAccess_UnlockedL1_CompareKey SecurityAccess_Unlocked_L1_CompareKey
#  define Rte_Call_SecurityAccess_UnlockedL1_GetSecurityAttemptCounter SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter
#  define Rte_Call_SecurityAccess_UnlockedL1_GetSeed SecurityAccess_Unlocked_L1_GetSeed
#  define Rte_Call_SecurityAccess_UnlockedL1_SetSecurityAttemptCounter SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter
#  define Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Confirmation ServiceRequestNotification_Confirmation
#  define Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Indication ServiceRequestNotification_Indication

# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetRequestKind Dcm_GetRequestKind
#  define RTE_RUNNABLE_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

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

#  define RTE_E_RoutineServices_Routine_CheckProgDep_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_CheckProgDep_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_CheckProgDep_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_CheckProgPreCond_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_CheckSig_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_CheckSig_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_CheckSig_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_EraseMem_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_EraseMem_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_EraseMem_Start_E_NOT_OK (1U)

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

#endif /* RTE_DCM_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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
