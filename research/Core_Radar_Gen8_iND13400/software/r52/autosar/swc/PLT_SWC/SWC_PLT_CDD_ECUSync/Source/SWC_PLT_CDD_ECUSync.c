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
 *             File:  SWC_PLT_CDD_ECUSync.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_ECUSync
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_ECUSync>
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
 *********************************************************************************************************************/

#include "SWC_PLT_CDD_ECUSync.h"
#include "Rte_SWC_PLT_CDD_ECUSync.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifdef TIMESYNC_TEST_STUB_ON
volatile static uint32_t Profile_Radar_Trigger_Timer_ISR     = 0u;
volatile static uint32_t Profile_Radar_Trigger_Timer_ISR_Max = 0u;
volatile static uint32_t Profile_Radar_Trigger_Timer_ISR_Min = 10000u;
volatile static uint32_t Profile_Time_Radar_Trigger_Counter  = 0u;
volatile StbM_TimeStampType Test_timeStamp                   = {0, 0, 0, 0};
volatile float32 Test_timeStamp_ms                           = 0;
volatile float32 Test_Prev_Time_NSec                         = 0;
volatile float32 Test_Cur_Time_NSec                          = 0;
volatile float32 Test_Delta_Time_NSec                        = 0;
#endif
#include "Os.h"
#include "Rte_SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "StbM.h"
#include "StbM_Cfg.h"
#include "platformtime.h"
#include "radar_ctl.h"
#include "radar_look.h"

/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/
#define RTE_SELF               /* This is used for Callback argument compatibility: No functional impact */
#define RADAR_TRIGGER_TIMER_CH 1
#define TIME_45MS              (45000U)
#define TIME_55MS              (55000U)
#define MAX_TIMEFAIL_COUNT     (100U)
/*====================================================================================================================*\
 * OBJECT DEFINITIONS
\*====================================================================================================================*/
/* Flag indicating that ECU synchronization has been started */
#if 0
static uint16 m_EcuSync_Status = ECUSYNC_STATUS_NOTINIT;
#endif

/* Sensor position depended offset for task trigger */
volatile float32 m_EcuSync_Offset_ms    = 0;
static uint32_t previous_timestamp_nano = 0;
StbM_TimeStampType timeStamp            = {0, 0, 0, 0};
#ifdef ENABLE_COMFREEZE_DEBUG
volatile uint32_t Time_EcuSync_RadarTrigger[MAX_TIMEFAIL_COUNT] = {0};
#endif
volatile uint32_t FailCnt_EcuSyncRadarTrigger = 0;
uint64_t StartTime_EcuSync                    = 0;
uint32_t Delta_time_EcuSync                   = 0;
uint32_t EcuSync_Max_Delta_Time_Us            = 0;
uint32_t EcuSync_Min_Delta_Time_Us            = 1000000U;

#if 0
static uint32 radar_triggering_within_threshold  = 0;
static uint32 radar_trigerring_outside_threshold = 0;
#endif

#if 0
   #if (TRUE == ENABLE_SIT_TEST_STUBS)
static uint32 end_radartrigger_test;
static uint64 ustime_radartrigger_test;
   #endif
#endif

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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
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

#define SWC_PLT_CDD_ECUSync_START_SEC_CODE
#include "SWC_PLT_CDD_ECUSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_ECUSync_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 *   Std_ReturnType Rte_Write_Pp_EcuSync_Offset_ms_De_EcuSync_Offset_ms(float32 data)
 *   Std_ReturnType Rte_Write_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error(Dt_STS_No_TSyn_Error data)
 *   Std_ReturnType Rte_Write_Pp_Time_Stamp_De_StbM_TimeStampType(const StbM_TimeStampType *data)
 *   Std_ReturnType Rte_Write_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta(Dt_Time_Stamp_Delta data)
 *
 * Trigger Interfaces:
 * ===================
 *   void Rte_Trigger_Pp_Radar_Ctl_Look_Complete_Trigger(void)
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Get_Platform_Elapsed_ustime_read(uint32 *inst_us_time, uint64 start_time)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Get_PlatfromTime_us_read(uint64 *instant_ustime)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation(void)
 *     Asynchronous Server Invocation
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(StbM_TimeStampType *timeStampPtr,
 *StbM_UserDataType *userDataPtr) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_E_OK Std_ReturnType
 *Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetCurrentTime(StbM_TimeStampType *timeStampPtr, StbM_UserDataType
 **userDataPtr) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_NOT_OK, RTE_E_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ECUSync_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_ECUSync_CODE) RE_ECUSync_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_ECUSync_Init
    *********************************************************************************************************************/

   /* Start timer for clock synchronization and ECU synchronization */
   Start_EcuSync_Timer();
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   PlatformTime_ustime_Interface_Test();
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_ECUSync_STOP_SEC_CODE
#include "SWC_PLT_CDD_ECUSync_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*====================================================================================================================*\
* FUNCTION: Radar_Trigger_Timer_ISR
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*t
* \\input{Gpt_FreeRunning_Timer_Interrput}
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Notification function for ISR for 50ms StbM timer.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
* ----------------------------------------------------------------------------------------------------------------------
* Traceability:
* ----------------------------------------------------------------------------------------------------------------------
*
\*====================================================================================================================*/

FUNC(void, SWC_CDD_StbMD_CODE) Radar_Trigger_Timer_ISR(void)
{
   volatile static float32 NewTimerValue_ms;
   volatile static float32 SyncClockValue_ms_Next;
   volatile static float32 dtNext_ms;
   volatile float32 SyncClockValue_ms;
   uint32_t current_timestamp_nano = 0;
   bool look_sync_time_overflow    = false;
   static uint8_t local_count      = 0;
   static bool FirstFailureSkipped = false;
#if 0
   static uint32 end_radartrigger;
   static uint64 ustime_radartrigger;

#endif

#ifdef TIMESYNC_TEST_STUB_ON
   static uint32_t temp1 = 0u;
   static uint32_t temp2 = 0u;
   Profile_Time_Radar_Trigger_Counter++;
   Get_Platform_mstime(&temp1);
   Profile_Radar_Trigger_Timer_ISR = temp1 - temp2;
   if (Profile_Radar_Trigger_Timer_ISR > Profile_Radar_Trigger_Timer_ISR_Max)
   {
      Profile_Radar_Trigger_Timer_ISR_Max = Profile_Radar_Trigger_Timer_ISR;
   }
   if (Profile_Radar_Trigger_Timer_ISR < Profile_Radar_Trigger_Timer_ISR_Min)
   {
      Profile_Radar_Trigger_Timer_ISR_Min = Profile_Radar_Trigger_Timer_ISR;
   }
#endif

   /* Local variable to fetch and store the time STBM */

   StbM_UserDataType userData = {0, 0, 0, 0};
#if 0 /*Disabled Temporarily*/
   TaskStateType IPC_Task_state = RUNNING;
   #if (TRUE == ENABLE_SIT_TEST_STUBS)
   Rte_Call_CS_Get_Platform_Elapsed_ustime_read(RTE_SELF, &end_radartrigger_test, ustime_radartrigger_test);
   Rte_Call_CS_Get_PlatfromTime_us_read(RTE_SELF, &ustime_radartrigger_test);
   #endif
#endif
   Get_Platform_Elapsed_ustime(&Delta_time_EcuSync, StartTime_EcuSync);
   Get_Platform_ustime(&StartTime_EcuSync);
   if (!FirstFailureSkipped)
   {
      FirstFailureSkipped = true;
   }
   else
   {
      if (Delta_time_EcuSync > EcuSync_Max_Delta_Time_Us)
      {
         EcuSync_Max_Delta_Time_Us = Delta_time_EcuSync;
      }
      if (Delta_time_EcuSync < EcuSync_Min_Delta_Time_Us)
      {
         EcuSync_Min_Delta_Time_Us = Delta_time_EcuSync;
      }
      if ((Delta_time_EcuSync < TIME_45MS) || (Delta_time_EcuSync > TIME_55MS))
      {
#ifdef ENABLE_COMFREEZE_DEBUG
         Time_EcuSync_RadarTrigger[local_count++] = Delta_time_EcuSync;
#endif
         FailCnt_EcuSyncRadarTrigger++;
         if (local_count >= MAX_TIMEFAIL_COUNT)
         {
            local_count = 0u;
         }
      }
   }

   (void)Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation();

   /* Sensor position depended offset for task trigger from smc */
   m_EcuSync_Offset_ms = (float32)TIMESYNCOFFSET;

   /* Critical section ENTER */
   SuspendAllInterrupts();
#if defined(CANTSYNC_ENABLE) || defined(AL_CAN_TSYNCH_DEFAULT)
   (void)Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetCurrentTime(&timeStamp, &userData);
#else
   (void)Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(&timeStamp, &userData);
#endif

   current_timestamp_nano = timeStamp.nanoseconds;

#ifdef TIMESYNC_TEST_STUB_ON
   Test_timeStamp.nanoseconds    = timeStamp.nanoseconds;
   Test_timeStamp.seconds        = timeStamp.seconds;
   Test_timeStamp.timeBaseStatus = timeStamp.timeBaseStatus;
   Test_timeStamp.secondsHi      = timeStamp.secondsHi;
   Test_Cur_Time_NSec            = Test_timeStamp.nanoseconds;
   Test_Delta_Time_NSec          = Test_Cur_Time_NSec - Test_Prev_Time_NSec;
   Test_Prev_Time_NSec           = Test_timeStamp.nanoseconds;
   Test_timeStamp_ms             = Test_Delta_Time_NSec * NS_2_MS;
#endif

   look_sync_time_overflow = ((current_timestamp_nano - (TIMESYNCOFFSET)) < previous_timestamp_nano) ? true : false;
   if (Look_Sync && look_sync_time_overflow &&
       !(Radar_Look_Sync_Test(!(timeStamp.timeBaseStatus & ~StbM_Global_Time_Base_BflMask))))
   {
      Radar_Ctl_Look_Sync_Trig();
   }

   previous_timestamp_nano = current_timestamp_nano;
   SyncClockValue_ms       = (((float32)timeStamp.nanoseconds) * NS_2_MS);

   if (SyncClockValue_ms < TIMESYNC_CYCLE_TIMERPERIOD_MS)
   {
      SyncClockValue_ms += TIMESYNC_CYCLE_TIMERPERIOD_MS;
   }
   SyncClockValue_ms_Next = (uint32_t)((SyncClockValue_ms - m_EcuSync_Offset_ms) / (TIMESYNC_CYCLE_TIMERPERIOD_MS));
   SyncClockValue_ms_Next = ((SyncClockValue_ms_Next + 1.0f) * ((float32)TIMESYNC_CYCLE_TIMERPERIOD_MS)) + m_EcuSync_Offset_ms;
   dtNext_ms              = SyncClockValue_ms_Next - SyncClockValue_ms;

   if (dtNext_ms <= (float32)TIMESYNC_CORRECTIONOFFSET) /* dtNext <= 10ms */
   {
      /* Up correction in one step. Next timer value = dtNext + 50ms (more than 50ms)*/
      NewTimerValue_ms = dtNext_ms + (float32)TIMESYNC_CYCLE_TIMERPERIOD_MS;
   }
   else if (dtNext_ms < (float32)TIMESYNC_CORRECTIONTHRESHOLD) /* 10ms < dtNext <= 48ms */
   {
      /* Up correction in several steps. Next timer value = 10ms + 50ms = 60ms */
      NewTimerValue_ms = (float32)(TIMESYNC_CYCLE_TIMERPERIOD_MS + TIMESYNC_CORRECTIONOFFSET);
   }
   else
   {
      /* Down correction in one step. Next timer value = dtNext (less than 50ms) */
      /*  48ms < dtNext <= 50ms  or dtNext > 50ms*/
      NewTimerValue_ms = dtNext_ms;
   }
#if 0 // Platform Time Component not Integrated
   if (TS_GLOBAL_TIME_BASE == timeStamp.timeBaseStatus) /*check to verify if Ecu is synced atleast once*/
   {
      Rte_Call_CS_Get_Platform_Elapsed_ustime_read(
         RTE_SELF, &end_radartrigger,
         ustime_radartrigger); /*Using Platform timer to do the verification for radar trigger timer */

      if ((Radar_triggering_threshold_MIN <= end_radartrigger) &&
          (Radar_triggering_threshold_MAX >= end_radartrigger)) /*Considering the threshold of +/- 2.5 % for radar trigerring */
      {
         radar_triggering_within_threshold++;
      }

      else if ((Radar_triggering_outside_threshold_MIN <= end_radartrigger) ||
               (Radar_triggering_outside_threshold_MAX >=
                end_radartrigger)) /*Considering the higher threshold value limit of +/- 10% */
      {
         radar_trigerring_outside_threshold++;
      }

      else
      {
      }
      Rte_Call_CS_Get_PlatfromTime_us_read(RTE_SELF, &ustime_radartrigger);
   }
#endif
   Set_Timer_Cnt_Value_ms((Gpt_TimerPhysicalChannelType)RADAR_TRIGGER_TIMER_CH, NewTimerValue_ms);

   /* Critical section EXIT */
   ResumeAllInterrupts();

#ifdef TIMESYNC_TEST_STUB_ON
   Get_Platform_mstime(&temp2);
#endif
} /*Radar_Trigger_Timer_ISR*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:DRE_StatusNotification_Callback_doc)  *****************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DRE_StatusNotification_Callback)  ****************/
   // Tsync_calculateTimeDiff(); //Disabled Temporariliy, Logic for time calculation difference with just StbM needs to be explored

/***  End of saved code  ************************************************************************************/
#endif

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
