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
 *             File:  Rte_BswM.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSWM_H
# define RTE_BSWM_H

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

# include "Rte_BswM_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Request_ESH_PostRunRequest_0_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_PostRunRequest_1_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_RunRequest_0_requestedMode (0U)
#  define Rte_InitValue_Request_ESH_RunRequest_1_requestedMode (0U)
#  define Rte_InitValue_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode (0U)
#  define Rte_InitValue_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode (0U)
#  define Rte_InitValue_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode (0U)
#  define Rte_InitValue_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode (0U)
#  define Rte_InitValue_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode(P2VAR(BswM_SDC_SdClientServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode(P2VAR(BswM_SDC_SdConsumedEventGroupRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Dcm_EcuResetType, RTE_CODE) Rte_Mode_BswM_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState(BswM_SDC_SdClientServiceState nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState(BswM_SDC_SdConsumedEventGroupState nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode);

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Request_ESH_PostRunRequest_0_requestedMode Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode
#  define Rte_Read_Request_ESH_PostRunRequest_1_requestedMode Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode
#  define Rte_Read_Request_ESH_RunRequest_0_requestedMode Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode
#  define Rte_Read_Request_ESH_RunRequest_1_requestedMode Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode
#  define Rte_Read_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode
#  define Rte_Read_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode
#  define Rte_Read_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode
#  define Rte_Read_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode Rte_Read_BswM_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode
#  define Rte_Read_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset Rte_Mode_BswM_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState
#  define Rte_Switch_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState
#  define Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState
#  define Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState
#  define Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState


# endif /* !defined(RTE_CORE) */


# define BswM_START_SEC_CODE_ASIL_D
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities (CODE_ASIL_D)
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BswM_MainFunction BswM_MainFunction
# endif

FUNC(void, BswM_CODE_ASIL_D) BswM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BswM_STOP_SEC_CODE_ASIL_D
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSWM_H */

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
