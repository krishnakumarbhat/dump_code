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
 *             File:  Rte_SWC_CDD_IPC.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_CDD_IPC>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_CDD_IPC_H
# define RTE_SWC_CDD_IPC_H

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

# include "Rte_SWC_CDD_IPC_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_Fault_name_FHTI, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(P2VAR(Dt_Alignment_M2D_Data, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data(P2CONST(Dt_Alignment_IPC_Data, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults(P2CONST(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults(P2CONST(Dt_RadarCapability_Faults, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Dt_StaticRegCheckFailureInfo, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params(P2CONST(Dt_VSE_NVM_Params, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, RTE_CODE) Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, RTE_CODE) Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms(void);
FUNC(void, RTE_CODE) Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete(void);

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data
#  define Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params Rte_Read_SWC_CDD_IPC_Rp_VSE_NVM_Params_De_VSE_NVM_Params
#  define Rte_Read_SWC_CDD_IPC_Rp_VSE_NVM_Params_De_VSE_NVM_Params(data) (*(data) = Rte_C_Dt_VSE_NVM_Params_0671719A05B77BCE683C6C16B951E137, ((Std_ReturnType)RTE_E_UNCONNECTED))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data
#  define Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI Rte_Write_SWC_CDD_IPC_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI
#  define Rte_Write_SWC_CDD_IPC_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(data) (Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_IPC_Faults_De_IPC_Faults Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults
#  define Rte_Write_Pp_RadarCapability_Faults_De_RadarCapability_Faults Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults
#  define Rte_Write_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo
#  define Rte_Write_Pp_VSE_NVM_Params_De_VSE_NVM_Params Rte_Write_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params


/**********************************************************************************************************************
 * Rte_Trigger_<p>_<o> (external event trigger communication)
 *********************************************************************************************************************/
#  define Rte_Trigger_Pp_HIL_Periodic_Handler_Trigger Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> for asynchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream
#  define Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream
#  define Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream
#  define Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream
#  define Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
#  define Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream
#  define Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation Rte_Call_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Wdg_Disable_Read(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)2, arg1))

/**********************************************************************************************************************
 * Inter-runnable triggering (Rte_IrTrigger API)
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrTrigger_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms() \
          Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrTrigger_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete() \
          Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete()
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_CDD_IPC_START_SEC_CODE
# include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_IPC_Fault_Injection CS_IPC_Fault_Injection
#  define RTE_RUNNABLE_Dsp_sp_post_processing_complete Dsp_sp_post_processing_complete
#  define RTE_RUNNABLE_RE_CDD_IPC_Init RE_CDD_IPC_Init
#  define RTE_RUNNABLE_RE_IPC_Rx_50ms RE_IPC_Rx_50ms
#  define RTE_RUNNABLE_RE_IPC_Trigger_50ms RE_IPC_Trigger_50ms
#  define RTE_RUNNABLE_RE_IPC_Tx_50ms RE_IPC_Tx_50ms
#  define RTE_RUNNABLE_RE_IPC_VSE_Handler_10ms RE_IPC_VSE_Handler_10ms
# endif

FUNC(void, SWC_CDD_IPC_CODE) CS_IPC_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_CDD_IPC_CODE) Dsp_sp_post_processing_complete(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CDD_IPC_CODE) RE_CDD_IPC_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Rx_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Trigger_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Tx_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_VSE_Handler_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_CDD_IPC_STOP_SEC_CODE
# include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_PostRadarProcessing_Debug_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Debug_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Detection_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Detection_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Header_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Header_E_OK (0U)

#  define RTE_E_PostRadarProcessing_RDD_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_RDD_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Radar_Capability_E_OK (0U)

#  define RTE_E_PostRadarProcessing_Status_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_Status_E_OK (0U)

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_CDD_IPC_H */

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
