/*===========================================================================*\
 * FILE: SWC_PLT_CDD_ECUSync_external.c
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This file conatins ECUSync/TimeSync realted functions.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/

#include "SWC_PLT_CDD_ECUSync_external.h"
#include "Os.h"
#include "Rte_SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync.h"
#include "dd_gpt.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/
#define RTE_SELF          /* This is used for Callback argument compatibility: No functional impact */
#define GLOB_TS_BUFF_SIZE (2u)
#define GLOB_TS_DOMAIN    (STBM_DOMAIN_INDEX)

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef struct
{
   GLOB_TS_STRUCT_TYPE ts_data[GLOB_TS_BUFF_SIZE];
   uint8_t w_index;
   uint8_t r_index;
   uint8_t cnt;
   uint8_t ovr;
} MOD_TS_ENTRY_TYPE;

#pragma clang section data                                  = ".Rte_No_Init_QM"
static MOD_TS_ENTRY_TYPE global_timestamps[TS_MAX_MEAS_PTS] = {0};
#pragma clang section data                                  = ""
volatile uint32 m_StbMD_Time_Secs                           = 0;

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/
/*===========================================================================*\
 * FUNCTION: Tsync_calculateTimeDiff
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function calculates the time difference
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#if 0 /*Disabled Temporarliy, Logic for time calculation difference with just StbM needs to be explored*/
void Tsync_calculateTimeDiff()
{
   #if (TIMESYNC_SLAVE_FEATURE == STD_ON)
   /* Local variable to save the timer count in microseconds */
   static float32_t stbm_timer_us;
   float32_t local_timer_us;
   float32_t time_diff_us;
   int32_t time_diff_sec;
   int16_t TimeStamp_delta;
   uint8_t sts_no_tsyn_error;
   /* Local variable to store the status return type */
   StbM_TimeBaseNotificationType notification_status;
   /* Local variable to fetch and store the time STBM */
   StbM_TimeStampType timeStamp = {0, 0, 0, 0};
   StbM_UserDataType userData   = {0, 0, 0, 0};
   /* Getting the status of the notification given by the StbM module */
   (void)Rte_Read_Rp_StbMStatusNotificationCallback_StbMSynchronizedTimeBase_eventNotification(RTE_SELF, &notification_status);
   /* Checking for the time out had occurred or not*/
   if (STBM_EV_TIMEOUT_OCCURRED_MASK != (notification_status & STBM_EV_TIMEOUT_OCCURRED_MASK))
   {
      sts_no_tsyn_error = TRUE;
      /* Critical section ENTER */
      SuspendAllInterrupts();
      /* Invoking the function to fetch STBM time */
      (void)Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(RTE_SELF, &timeStamp, &userData);
      /* Converting STBM nanoseconds time to ticks of RTI timer */
      stbm_timer_us = (((float32_t)timeStamp.nanoseconds) * NS_2_US);
      /*Get the RTI timer Micro Seconds cnt value*/
      local_timer_us = RTI_Get_TimeSyncTimer_Cnt_Value_us();
      /* Disabling the timer, Update the Count, Restart the clock */
      /*RTI_Set_Timer_Cnt_Value_us  has to be updated if any other channel or value is changed*/
      RTI_Set_Timer_Cnt_Value_us(TIME_SYNC_TIMER_CH, stbm_timer_us);

      /*Get the time difference of global and internal time in both seconds and MicroSeconds*/
      time_diff_sec = m_StbMD_Time_Secs - (timeStamp.seconds);
      time_diff_us  = local_timer_us - stbm_timer_us;

      /* updated global second counter */
      m_StbMD_Time_Secs = timeStamp.seconds;
      if (time_diff_sec > 0)
      {
         /*add a value of second to MicroSecond's time from Second's time*/
         time_diff_sec--;
         time_diff_us += S_2_US;
      }
      else if (time_diff_sec < 0)
      {
         /*add a value of second to Second's time from MicroSecond's time*/
         time_diff_sec++;
         time_diff_us -= S_2_US;
      }
      else
      {
         /*Do Nothing*/
      }
      /*TimeStamp_delta should be in range  -32768.0f(INT16_MIN_F) and +32767.0f (INT16_MAX_F)*/
      /*Updating the max value to time stamp delta if greater than 32767*/
      if (time_diff_us > INT16_MAX_F)
      {
         TimeStamp_delta = (int16_t)INT16_MAX_F;
      }
      /*Updating the min value to time stamp delta if less than -32768*/
      else if (time_diff_us < INT16_MIN_F)
      {
         TimeStamp_delta = (int16_t)INT16_MIN_F;
      }
      else
      {
         TimeStamp_delta = (int16_t)time_diff_us;
      }

      /* Critical section EXIT */
      ResumeAllInterrupts();

      Rte_Write_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta(RTE_SELF, TimeStamp_delta);
   }
   else
   {
      /* Timesyn Timeout */
      sts_no_tsyn_error = FALSE;
   }
   Rte_Write_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error(RTE_SELF, sts_no_tsyn_error);
   #endif
}
#endif

/*===========================================================================*\
 * FUNCTION: CaptureGlobalTimestamp_HandleBuffered
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    meas_point - measurement point index
 *    timeStamp - timestamp data to store
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Helper function to handle buffered timestamp storage and index management
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void CaptureGlobalTimestamp_HandleBuffered(GLOB_TS_MEAS_PTS meas_point, StbM_TimeStampType timeStamp)
{
   global_timestamps[meas_point].ts_data[global_timestamps[meas_point].w_index].ts_nanosecs = timeStamp.nanoseconds;
   global_timestamps[meas_point].ts_data[global_timestamps[meas_point].w_index].ts_secs     = timeStamp.seconds;
   global_timestamps[meas_point].ts_data[global_timestamps[meas_point].w_index].ts_status   = timeStamp.timeBaseStatus;

   global_timestamps[meas_point].w_index = (global_timestamps[meas_point].w_index + 1) % GLOB_TS_BUFF_SIZE;

   if (global_timestamps[meas_point].cnt < GLOB_TS_BUFF_SIZE)
   {
      global_timestamps[meas_point].cnt++;
   }
   else
   {
      global_timestamps[meas_point].r_index = (global_timestamps[meas_point].r_index + 1) % GLOB_TS_BUFF_SIZE;
      global_timestamps[meas_point].ovr     = CODED_TRUE;
   }
}

/*===========================================================================*\
 * FUNCTION: CaptureGlobalTimestamp_HandleNonBuffered
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    ret_ts - pointer to return timestamp
 *    timeStamp - timestamp data to return
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Helper function to handle non-buffered timestamp return
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void CaptureGlobalTimestamp_HandleNonBuffered(GLOB_TS_STRUCT_TYPE *ret_ts, StbM_TimeStampType timeStamp)
{
   if (ret_ts != NULL)
   {
      ret_ts->ts_nanosecs = timeStamp.nanoseconds;
      ret_ts->ts_secs     = timeStamp.seconds;
      ret_ts->ts_status   = timeStamp.timeBaseStatus;
   }
}

/*===========================================================================*\
 * FUNCTION: CaptureGlobalTimestamp
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    measurement point
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function timestamps the measurement point
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t CaptureGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point, GLOB_TS_STRUCT_TYPE *ret_ts)
{
   Std_ReturnType ret_val;
   StbM_TimeStampType timeStamp;
   StbM_UserDataType userData;

   SuspendAllInterrupts();
#if defined(CANTSYNC_ENABLE) || defined(AL_CAN_TSYNCH_DEFAULT)
   ret_val = Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_CanTsync_GetCurrentTime(&timeStamp, &userData);
#else
   ret_val = Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime(&timeStamp, &userData);
#endif
   ResumeAllInterrupts();

   if (E_OK == ret_val)
   {
      if (meas_point == TS_NO_BUFF)
      {
         CaptureGlobalTimestamp_HandleNonBuffered(ret_ts, timeStamp);
      }
      else
      {
         CaptureGlobalTimestamp_HandleBuffered(meas_point, timeStamp);
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: GetGlobalTimestamp
 *===========================================================================
 * RETURN VALUE:
 *    GLOB_TS_STRUCT_TYPE *
 *
 * PARAMETERS:
 *    measurement point
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function gets the latest timestamp of the measurement point
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
GLOB_TS_STRUCT_TYPE *GetGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point)
{
   GLOB_TS_STRUCT_TYPE *ret_val;
   if (global_timestamps[meas_point].cnt > 0)
   {
      ret_val                               = &global_timestamps[meas_point].ts_data[global_timestamps[meas_point].r_index];
      global_timestamps[meas_point].r_index = (global_timestamps[meas_point].r_index + 1) % GLOB_TS_BUFF_SIZE;
      if (global_timestamps[meas_point].cnt > 0)
      {
         global_timestamps[meas_point].cnt--;
      }
      else
      {
         ret_val = &global_timestamps[TS_NO_BUFF].ts_data[global_timestamps[TS_NO_BUFF].r_index];
      }
   }
   else
   {
      ret_val = &global_timestamps[TS_NO_BUFF].ts_data[global_timestamps[TS_NO_BUFF].r_index];
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: PeekGlobalTimestamp
 *===========================================================================
 * RETURN VALUE:
 *    GLOB_TS_STRUCT_TYPE *
 *
 * PARAMETERS:
 *    measurement point
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function gets the latest timestamp of the measurement point
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
GLOB_TS_STRUCT_TYPE *PeekGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point)
{
   return &global_timestamps[meas_point].ts_data[global_timestamps[meas_point].r_index];
}

/*===========================================================================*\
 * FUNCTION: GetTimeStampDiff_SameSecond
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t  0 no error, 1 negative
 *
 * PARAMETERS:
 *    GLOB_TS_STRUCT_TYPE * param1
 *    GLOB_TS_STRUCT_TYPE * param2
 *    uint32_t * result
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Helper function to calculate difference when timestamps have same second
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static uint8_t GetTimeStampDiff_SameSecond(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result)
{
   uint8_t ret_val = 0;

   if (param1->ts_nanosecs >= param2->ts_nanosecs)
   {
      *result = param1->ts_nanosecs - param2->ts_nanosecs;
   }
   else
   {
      ret_val = 1;
   }

   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: GetTimeStampDiff_NextSecond
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t  0 no error, 1 negative
 *
 * PARAMETERS:
 *    GLOB_TS_STRUCT_TYPE * param1
 *    GLOB_TS_STRUCT_TYPE * param2
 *    uint32_t * result
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Helper function to calculate difference when param1 is next second from param2
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static uint8_t GetTimeStampDiff_NextSecond(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result)
{
   uint8_t ret_val = 0;

   if ((param1->ts_nanosecs + S_2_NS) >= param2->ts_nanosecs)
   {
      *result = (param1->ts_nanosecs + S_2_NS) - param2->ts_nanosecs;
   }
   else
   {
      ret_val = 1;
   }

   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: GetTimeStampDiff_Ns()
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t  0 no error, 1 negative, 2 greater
 *
 * PARAMETERS:
 *    GLOB_TS_STRUCT_TYPE * param1
 *    GLOB_TS_STRUCT_TYPE * param2
 *    uint32_t * result
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function provides the difference between two timestamp measurement points
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t GetTimeStampDiff_Ns(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result)
{
   uint8_t ret_val = 0; /* Assume typical path */

   if (param1->ts_secs >= param2->ts_secs)
   {
      if (param1->ts_secs == param2->ts_secs)
      {
         ret_val = GetTimeStampDiff_SameSecond(param1, param2, result);
      }
      else if (param1->ts_secs == (param2->ts_secs + 1))
      {
         ret_val = GetTimeStampDiff_NextSecond(param1, param2, result);
      }
      else
      {
         ret_val = 2; /* out of bounds*/
      }
   }
   else
   {
      ret_val = 1;
   }

   if (0 != ret_val)
   {
      *result = TS_ERROR; /* invalidate result, if unexpected condition */
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: GetMidTimeStamps()
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t  0 no error, =!0 error
 *
 * PARAMETERS:
 *    GLOB_TS_STRUCT_TYPE * param1
 *    GLOB_TS_STRUCT_TYPE * param2
 *    GLOB_TS_STRUCT_TYPE * result
 *    uint32_t * diff (optional)
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function provides the middle time between two measurement points
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t GetMidTimeStamps(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, GLOB_TS_STRUCT_TYPE *result, uint32_t *diff)
{
   uint8_t ret_val;
   uint32_t nanosecs;
   uint32_t temp1, temp2;
   if (0 == (ret_val = GetTimeStampDiff_Ns(param1, param2, &nanosecs)))
   {
      temp1               = param2->ts_nanosecs + nanosecs / 2;
      temp2               = temp1 % S_2_NS;
      result->ts_nanosecs = temp2;
      result->ts_secs     = (temp2 == temp1) ? param2->ts_secs : param1->ts_secs;
   }
   else
   {
      result->ts_nanosecs = TS_ERROR;
      result->ts_secs     = TS_ERROR;
   }
   if (NULL != diff)
   {
      *diff = nanosecs;
   }

   return ret_val;
}
