/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_CDD_TimeSync.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_TimeSync
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_TimeSync>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * StbM_RateDeviationType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed.
 *
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * StbM_TimeBaseNotificationType
 *   uint32 represents integers with a minimum value of 0 and a maximum value
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 12234567, 104400.
 *
 * StbM_TimeBaseStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * StbM_TimeDiffType
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the
 *      sign is omitted, "+" is assumed.
 *
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_TimeSync.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "PLT_APPL_CDD_TimeSync.h"
#include "SWC_PLT_CDD_TimeSync_cfg.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dt_STS_No_TSyn_Error: Integer in interval [0...255]
 * Dt_Time_Stamp_Delta: Integer in interval [-32768...32767]
 * StbM_RateDeviationType: Integer in interval [-32768...32767]
 * StbM_TimeDiffType: Integer in interval [-2147483648...2147483647]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * StbM_TimeBaseNotificationType: Enumeration of integer in interval [0...4294967295] with enumerators
 *   EV_GLOBAL_TIME__FALSE (0U)
 *   EV_GLOBAL_TIME_BflMask 1U (0b00000000000000000000000000000001)
 *   EV_GLOBAL_TIME_BflPn 0
 *   EV_GLOBAL_TIME_BflLn 1
 *   EV_GLOBAL_TIME (1U)
 *   EV_GLOBAL_TIME_BflMask 1U (0b00000000000000000000000000000001)
 *   EV_GLOBAL_TIME_BflPn 0
 *   EV_GLOBAL_TIME_BflLn 1
 *   EV_TIMEOUT_OCCURRED__FALSE (0U)
 *   EV_TIMEOUT_OCCURRED_BflMask 2U (0b00000000000000000000000000000010)
 *   EV_TIMEOUT_OCCURRED_BflPn 1
 *   EV_TIMEOUT_OCCURRED_BflLn 1
 *   EV_TIMEOUT_OCCURRED (2U)
 *   EV_TIMEOUT_OCCURRED_BflMask 2U (0b00000000000000000000000000000010)
 *   EV_TIMEOUT_OCCURRED_BflPn 1
 *   EV_TIMEOUT_OCCURRED_BflLn 1
 *   EV_TIMEOUT_REMOVED__FALSE (0U)
 *   EV_TIMEOUT_REMOVED_BflMask 4U (0b00000000000000000000000000000100)
 *   EV_TIMEOUT_REMOVED_BflPn 2
 *   EV_TIMEOUT_REMOVED_BflLn 1
 *   EV_TIMEOUT_REMOVED (4U)
 *   EV_TIMEOUT_REMOVED_BflMask 4U (0b00000000000000000000000000000100)
 *   EV_TIMEOUT_REMOVED_BflPn 2
 *   EV_TIMEOUT_REMOVED_BflLn 1
 *   EV_TIMELEAP_FUTURE__FALSE (0U)
 *   EV_TIMELEAP_FUTURE_BflMask 8U (0b00000000000000000000000000001000)
 *   EV_TIMELEAP_FUTURE_BflPn 3
 *   EV_TIMELEAP_FUTURE_BflLn 1
 *   EV_TIMELEAP_FUTURE (8U)
 *   EV_TIMELEAP_FUTURE_BflMask 8U (0b00000000000000000000000000001000)
 *   EV_TIMELEAP_FUTURE_BflPn 3
 *   EV_TIMELEAP_FUTURE_BflLn 1
 *   EV_TIMELEAP_FUTURE_REMOVED__FALSE (0U)
 *   EV_TIMELEAP_FUTURE_REMOVED_BflMask 16U (0b00000000000000000000000000010000)
 *   EV_TIMELEAP_FUTURE_REMOVED_BflPn 4
 *   EV_TIMELEAP_FUTURE_REMOVED_BflLn 1
 *   EV_TIMELEAP_FUTURE_REMOVED (16U)
 *   EV_TIMELEAP_FUTURE_REMOVED_BflMask 16U (0b00000000000000000000000000010000)
 *   EV_TIMELEAP_FUTURE_REMOVED_BflPn 4
 *   EV_TIMELEAP_FUTURE_REMOVED_BflLn 1
 *   EV_TIMELEAP_PAST__FALSE (0U)
 *   EV_TIMELEAP_PAST_BflMask 32U (0b00000000000000000000000000100000)
 *   EV_TIMELEAP_PAST_BflPn 5
 *   EV_TIMELEAP_PAST_BflLn 1
 *   EV_TIMELEAP_PAST (32U)
 *   EV_TIMELEAP_PAST_BflMask 32U (0b00000000000000000000000000100000)
 *   EV_TIMELEAP_PAST_BflPn 5
 *   EV_TIMELEAP_PAST_BflLn 1
 *   EV_TIMELEAP_PAST_REMOVED__FALSE (0U)
 *   EV_TIMELEAP_PAST_REMOVED_BflMask 64U (0b00000000000000000000000001000000)
 *   EV_TIMELEAP_PAST_REMOVED_BflPn 6
 *   EV_TIMELEAP_PAST_REMOVED_BflLn 1
 *   EV_TIMELEAP_PAST_REMOVED (64U)
 *   EV_TIMELEAP_PAST_REMOVED_BflMask 64U (0b00000000000000000000000001000000)
 *   EV_TIMELEAP_PAST_REMOVED_BflPn 6
 *   EV_TIMELEAP_PAST_REMOVED_BflLn 1
 *   EV_SYNC_TO_SUBDOMAIN__FALSE (0U)
 *   EV_SYNC_TO_SUBDOMAIN_BflMask 128U (0b00000000000000000000000010000000)
 *   EV_SYNC_TO_SUBDOMAIN_BflPn 7
 *   EV_SYNC_TO_SUBDOMAIN_BflLn 1
 *   EV_SYNC_TO_SUBDOMAIN (128U)
 *   EV_SYNC_TO_SUBDOMAIN_BflMask 128U (0b00000000000000000000000010000000)
 *   EV_SYNC_TO_SUBDOMAIN_BflPn 7
 *   EV_SYNC_TO_SUBDOMAIN_BflLn 1
 *   EV_SYNC_TO_GLOBAL_MASTER__FALSE (0U)
 *   EV_SYNC_TO_GLOBAL_MASTER_BflMask 256U (0b00000000000000000000000100000000)
 *   EV_SYNC_TO_GLOBAL_MASTER_BflPn 8
 *   EV_SYNC_TO_GLOBAL_MASTER_BflLn 1
 *   EV_SYNC_TO_GLOBAL_MASTER (256U)
 *   EV_SYNC_TO_GLOBAL_MASTER_BflMask 256U (0b00000000000000000000000100000000)
 *   EV_SYNC_TO_GLOBAL_MASTER_BflPn 8
 *   EV_SYNC_TO_GLOBAL_MASTER_BflLn 1
 *   EV_RESYNC__FALSE (0U)
 *   EV_RESYNC_BflMask 512U (0b00000000000000000000001000000000)
 *   EV_RESYNC_BflPn 9
 *   EV_RESYNC_BflLn 1
 *   EV_RESYNC (512U)
 *   EV_RESYNC_BflMask 512U (0b00000000000000000000001000000000)
 *   EV_RESYNC_BflPn 9
 *   EV_RESYNC_BflLn 1
 *   EV_RATECORRECTION__FALSE (0U)
 *   EV_RATECORRECTION_BflMask 1024U (0b00000000000000000000010000000000)
 *   EV_RATECORRECTION_BflPn 10
 *   EV_RATECORRECTION_BflLn 1
 *   EV_RATECORRECTION (1024U)
 *   EV_RATECORRECTION_BflMask 1024U (0b00000000000000000000010000000000)
 *   EV_RATECORRECTION_BflPn 10
 *   EV_RATECORRECTION_BflLn 1
 * StbM_TimeBaseStatusType: Enumeration of integer in interval [0...63] with enumerators
 *   TIMEOUT__FALSE (0U)
 *   TIMEOUT_BflMask 1U (0b00000001)
 *   TIMEOUT_BflPn 0
 *   TIMEOUT_BflLn 1
 *   TIMEOUT (1U)
 *   TIMEOUT_BflMask 1U (0b00000001)
 *   TIMEOUT_BflPn 0
 *   TIMEOUT_BflLn 1
 *   SYNC_TO_GATEWAY__FALSE (0U)
 *   SYNC_TO_GATEWAY_BflMask 4U (0b00000100)
 *   SYNC_TO_GATEWAY_BflPn 2
 *   SYNC_TO_GATEWAY_BflLn 1
 *   SYNC_TO_GATEWAY (4U)
 *   SYNC_TO_GATEWAY_BflMask 4U (0b00000100)
 *   SYNC_TO_GATEWAY_BflPn 2
 *   SYNC_TO_GATEWAY_BflLn 1
 *   GLOBAL_TIME_BASE__FALSE (0U)
 *   GLOBAL_TIME_BASE_BflMask 8U (0b00001000)
 *   GLOBAL_TIME_BASE_BflPn 3
 *   GLOBAL_TIME_BASE_BflLn 1
 *   GLOBAL_TIME_BASE (8U)
 *   GLOBAL_TIME_BASE_BflMask 8U (0b00001000)
 *   GLOBAL_TIME_BASE_BflPn 3
 *   GLOBAL_TIME_BASE_BflLn 1
 *   TIMELEAP_FUTURE__FALSE (0U)
 *   TIMELEAP_FUTURE_BflMask 16U (0b00010000)
 *   TIMELEAP_FUTURE_BflPn 4
 *   TIMELEAP_FUTURE_BflLn 1
 *   TIMELEAP_FUTURE (16U)
 *   TIMELEAP_FUTURE_BflMask 16U (0b00010000)
 *   TIMELEAP_FUTURE_BflPn 4
 *   TIMELEAP_FUTURE_BflLn 1
 *   TIMELEAP_PAST__FALSE (0U)
 *   TIMELEAP_PAST_BflMask 32U (0b00100000)
 *   TIMELEAP_PAST_BflPn 5
 *   TIMELEAP_PAST_BflLn 1
 *   TIMELEAP_PAST (32U)
 *   TIMELEAP_PAST_BflMask 32U (0b00100000)
 *   TIMELEAP_PAST_BflPn 5
 *   TIMELEAP_PAST_BflLn 1
 *
 * Record Types:
 * =============
 * StbM_SyncRecordTableHeadType: Record with elements
 *   SynchronizedTimeDomain of type uint8
 *   HWfrequency of type uint32
 *   HWprescaler of type uint32
 * StbM_TimeStampType: Record with elements
 *   timeBaseStatus of type StbM_TimeBaseStatusType
 *   nanoseconds of type uint32
 *   seconds of type uint32
 *   secondsHi of type uint16
 * StbM_UserDataType: Record with elements
 *   userDataLength of type uint8
 *   userByte0 of type uint8
 *   userByte1 of type uint8
 *   userByte2 of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_TimeSync_START_SEC_CODE
#include "SWC_PLT_CDD_TimeSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DRE_StatusNotification_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <eventNotification> of PortPrototype
 *<Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType
 *Rte_Read_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification(StbM_TimeBaseNotificationType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error(Dt_STS_No_TSyn_Error data)
 *   Std_ReturnType Rte_Write_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta(Dt_Time_Stamp_Delta data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DRE_StatusNotification_Callback_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_TimeSync_CODE) DRE_StatusNotification_Callback(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: DRE_StatusNotification_Callback
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_TimeSync_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_TimeSync_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_TimeSync_CODE) RE_PLT_TimeSync_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_TimeSync_Init
    *********************************************************************************************************************/
   (void)EcuSync_SeedCanTSynTimeBaseIfNeeded();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_TimeSync_Main_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Global_Seconds_Cnt_De_Global_Seconds_Cnt(uint32 *data)
 *   Std_ReturnType
 *Rte_Read_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification(StbM_TimeBaseNotificationType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Time_Stamp_De_StbM_TimeStampType(const StbM_TimeStampType *data)
 *   Std_ReturnType Rte_Write_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Timesync_Status_De_Timesync_Status(uint8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(StbM_TimeStampType *timeStampPtr,
 *StbM_UserDataType *userDataPtr) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetRateDeviation(StbM_RateDeviationType *rateDeviation) Synchronous Service
 *Invocation. Timeout: None Returned Application Errors: RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK,
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetSyncTimeRecordHead(StbM_SyncRecordTableHeadType *syncRecordTableHead)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK,
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetTimeBaseStatus(StbM_TimeBaseStatusType *syncTimeBaseStatus,
 *StbM_TimeBaseStatusType *offsetTimeBaseStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetTimeLeap(StbM_TimeDiffType *timeJump) Synchronous Service Invocation.
 *Timeout: None Returned Application Errors: RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK,
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetCurrentTime(StbM_TimeStampType *timeStampPtr, StbM_UserDataType
 **userDataPtr) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK
 *   Std_ReturnType Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetRateDeviation(StbM_RateDeviationType
 **rateDeviation) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK
 *   Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetSyncTimeRecordHead(StbM_SyncRecordTableHeadType
 **syncRecordTableHead) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK
 *   Std_ReturnType Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetTimeBaseStatus(StbM_TimeBaseStatusType
 **syncTimeBaseStatus, StbM_TimeBaseStatusType *offsetTimeBaseStatus) Synchronous Service Invocation. Timeout: None Returned
 *Application Errors: RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK,
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetTimeLeap(StbM_TimeDiffType *timeJump) Synchronous Service
 *Invocation. Timeout: None Returned Application Errors: RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK,
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeSync_ExclusiveArea(void)
 *   void Rte_Exit_TimeSync_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_TimeSync_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_TimeSync_CODE) RE_PLT_TimeSync_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_TimeSync_Main_50ms
    *********************************************************************************************************************/
   TimeSync_Main_50ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_TimeSync_STOP_SEC_CODE
#include "SWC_PLT_CDD_TimeSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*====================================================================================================================*\
* FUNCTION: SWC_PLT_CDD_TimeSync_GetTimerCntValueUs
*======================================================================================================================
* RETURN VALUE: float32
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* Gpt_GetTimeElapsed()
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Returns the elapsed TimeSync GPT timer value in microseconds.
*
* PRECONDITIONS:
* GPT timer channel is configured.
*
* POSTCONDITIONS:
* None.
*
\*====================================================================================================================*/
float32 SWC_PLT_CDD_TimeSync_GetTimerCntValueUs(void)
{
   return (((float32)Gpt_GetTimeElapsed(TIMESYNC_TIMER_CHANNEL)) * TIMESYNC_US_PER_SECOND_F32) / TIMESYNC_TIMER_CLK_HZ_F32;
}
/*====================================================================================================================*\
* FUNCTION: SWC_PLT_CDD_TimeSync_SetTimerCntValueUs
*======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: float32 timer_value_us
*
* EXTERNAL REFERENCES:
* Gpt_StopTimer()
* Gpt_StartTimer()
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Converts the requested timer value from microseconds to GPT ticks and restarts the TimeSync timer.
*
* PRECONDITIONS:
* GPT timer channel is configured.
*
* POSTCONDITIONS:
* The TimeSync GPT timer restarts with the requested counter value.
*
\*====================================================================================================================*/
void SWC_PLT_CDD_TimeSync_SetTimerCntValueUs(float32 timer_value_us)
{
   Gpt_ValueType ticks = (Gpt_ValueType)((timer_value_us * TIMESYNC_TIMER_CLK_HZ_F32) / TIMESYNC_US_PER_SECOND_F32);

   Gpt_StopTimer(TIMESYNC_TIMER_CHANNEL);
   Gpt_StartTimer(TIMESYNC_TIMER_CHANNEL, ticks);
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
