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
 *             File:  Rte_SWC_PLT_CDD_TimeSync.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_TimeSync>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_TIMESYNC_H
# define RTE_SWC_PLT_CDD_TIMESYNC_H

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

# include "Rte_SWC_PLT_CDD_TimeSync_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_STS_No_TSyn_Error, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error;
extern VAR(Dt_Time_Stamp_Delta, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status;
extern VAR(StbM_TimeBaseNotificationType, RTE_VAR_INIT) Rte_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error (0U)
#  define Rte_InitValue_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta (0)
#  define Rte_InitValue_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status (170U)
#  define Rte_InitValue_Pp_Timesync_Status_De_Timesync_Status (85U)
#  define Rte_InitValue_Rp_Global_Seconds_Cnt_De_Global_Seconds_Cnt (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Global_Seconds_Cnt_De_Global_Seconds_Cnt Rte_Read_SWC_PLT_CDD_TimeSync_Rp_Global_Seconds_Cnt_De_Global_Seconds_Cnt
#  define Rte_Read_SWC_PLT_CDD_TimeSync_Rp_Global_Seconds_Cnt_De_Global_Seconds_Cnt(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification Rte_Read_SWC_PLT_CDD_TimeSync_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification
#  define Rte_Read_SWC_PLT_CDD_TimeSync_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification(data) (*(data) = Rte_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error Rte_Write_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error
#  define Rte_Write_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error(data) (Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Time_Stamp_De_StbM_TimeStampType Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_De_StbM_TimeStampType
#  define Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_De_StbM_TimeStampType(data) (RTE_E_OK)
#  define Rte_Write_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta
#  define Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta(data) (Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status
#  define Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status(data) (Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Timesync_Status_De_Timesync_Status Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Timesync_Status_De_Timesync_Status
#  define Rte_Write_SWC_PLT_CDD_TimeSync_Pp_Timesync_Status_De_Timesync_Status(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define StbM_START_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, StbM_CODE) StbM_GetCurrentTime(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_STBM_APPL_VAR) timeStampPtr, P2VAR(StbM_UserDataType, AUTOMATIC, RTE_STBM_APPL_VAR) userDataPtr); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define StbM_STOP_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define StbM_START_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, StbM_CODE) StbM_GetRateDeviation(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_RateDeviationType, AUTOMATIC, RTE_STBM_APPL_VAR) rateDeviation); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define StbM_STOP_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define StbM_START_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, StbM_CODE) StbM_GetSyncTimeRecordHead(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_SyncRecordTableHeadType, AUTOMATIC, RTE_STBM_APPL_VAR) syncRecordTableHead); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define StbM_STOP_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define StbM_START_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, StbM_CODE) StbM_GetTimeBaseStatus(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_STBM_APPL_VAR) syncTimeBaseStatus, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_STBM_APPL_VAR) offsetTimeBaseStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define StbM_STOP_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define StbM_START_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, StbM_CODE) StbM_GetTimeLeap(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_TimeDiffType, AUTOMATIC, RTE_STBM_APPL_VAR) timeJump); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define StbM_STOP_SEC_CODE
#  include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(arg1, arg2) (StbM_GetCurrentTime((StbM_SynchronizedTimeBaseType)0, arg1, arg2))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetRateDeviation(arg1) (StbM_GetRateDeviation((StbM_SynchronizedTimeBaseType)0, arg1))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetSyncTimeRecordHead(arg1) (StbM_GetSyncTimeRecordHead((StbM_SynchronizedTimeBaseType)0, arg1))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetTimeBaseStatus(arg1, arg2) (StbM_GetTimeBaseStatus((StbM_SynchronizedTimeBaseType)0, arg1, arg2))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetTimeLeap(arg1) (StbM_GetTimeLeap((StbM_SynchronizedTimeBaseType)0, arg1))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetCurrentTime(arg1, arg2) (StbM_GetCurrentTime((StbM_SynchronizedTimeBaseType)1, arg1, arg2))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetRateDeviation(arg1) (StbM_GetRateDeviation((StbM_SynchronizedTimeBaseType)1, arg1))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetSyncTimeRecordHead(arg1) (StbM_GetSyncTimeRecordHead((StbM_SynchronizedTimeBaseType)1, arg1))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetTimeBaseStatus(arg1, arg2) (StbM_GetTimeBaseStatus((StbM_SynchronizedTimeBaseType)1, arg1, arg2))
#  define Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetTimeLeap(arg1) (StbM_GetTimeLeap((StbM_SynchronizedTimeBaseType)1, arg1))

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_TimeSync_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_TimeSync_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_TimeSync_START_SEC_CODE
# include "SWC_PLT_CDD_TimeSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DRE_StatusNotification_Callback DRE_StatusNotification_Callback
#  define RTE_RUNNABLE_RE_PLT_TimeSync_Init RE_PLT_TimeSync_Init
#  define RTE_RUNNABLE_RE_PLT_TimeSync_Main_50ms RE_PLT_TimeSync_Main_50ms
# endif

FUNC(void, SWC_PLT_CDD_TimeSync_CODE) DRE_StatusNotification_Callback(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_TimeSync_CODE) RE_PLT_TimeSync_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_TimeSync_CODE) RE_PLT_TimeSync_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_CDD_TimeSync_STOP_SEC_CODE
# include "SWC_PLT_CDD_TimeSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK (1U)

#  define RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK (0U)

#  define RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK (1U)

#  define RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_TIMESYNC_H */

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
