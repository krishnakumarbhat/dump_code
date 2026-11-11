#include "Rte_SWC_PLT_CDD_ECUSync.h"
#include "dd_gpt.h"
#include "radar_look.h"
#include <stdint.h>

/* Simple global hooks for assertions from C++ tests */
unsigned g_Start_EcuSync_Timer_calls              = 0;
unsigned g_Radar_Look_Trigger_calls               = 0;
Gpt_TimerPhysicalChannelType g_last_timer_channel = (Gpt_TimerPhysicalChannelType)0xFFFFFFFFu;
float32 g_last_timer_value_ms                     = -1.0f;
/* Time injection object consumed by test and StbM_GetCurrentTime */
StbM_TimeStampType g_test_time_inject = {0};
uint32_t g_test_elapsed_us_value      = 0U;
uint64_t g_test_ustime_value          = 0U;

/* Global variable to control StbM_GetCurrentTime return value for testing */
Std_ReturnType g_stbm_return_value = 0; // Default to E_OK

/* StbM status and seeding stubs used by SWC_PLT_CDD_ECUSync */
Std_ReturnType g_stbm_get_time_base_status_return_value   = 0; /* E_OK */
Std_ReturnType g_stbm_set_global_time_return_value        = 0; /* E_OK */
StbM_TimeBaseStatusType g_stbm_sync_time_base_status      = (StbM_TimeBaseStatusType)1u;
StbM_TimeBaseStatusType g_stbm_offset_time_base_status    = (StbM_TimeBaseStatusType)0u;
uint8_t g_radar_position                                  = 1u;
unsigned g_StbM_GetTimeBaseStatus_calls                   = 0;
unsigned g_StbM_SetGlobalTime_calls                       = 0;
StbM_SynchronizedTimeBaseType g_last_set_global_time_base = (StbM_SynchronizedTimeBaseType)0;
StbM_TimeStampType g_last_set_global_time_stamp           = {0};
StbM_UserDataType g_last_set_global_time_user_data        = {0};
unsigned g_Radar_Ctl_Look_Sync_Trig_calls                 = 0;
unsigned g_Radar_Look_Sync_Test_calls                     = 0;
bool g_Radar_Look_Sync_Test_return_value                  = true;
bool g_last_radar_look_sync_test_arg                      = false;
volatile Look_Sync_Enable_T Look_Sync                     = Look_Sync_Enable;

/* Provide sensor position dependent calibration array referenced by TIMESYNCOFFSET macro */
float32 k_sensor_radar_firing_offset_list_smc[1] = {0.0f};

/* Stub for radar position selector */
uint8_t Get_Radar_Position(void)
{
   return g_radar_position;
}

void Start_EcuSync_Timer(void)
{
   g_Start_EcuSync_Timer_calls++;
}
Std_ReturnType Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation(void)
{
   g_Radar_Look_Trigger_calls++;
   return 0;
}
/* Rte macro maps to StbM_GetCurrentTime; implement that symbol */
Std_ReturnType StbM_GetCurrentTime(StbM_SynchronizedTimeBaseType base, StbM_TimeStampType *ts, StbM_UserDataType *ud)
{
   (void)base;
   (void)ud;
   extern StbM_TimeStampType g_test_time_inject;
   extern Std_ReturnType g_stbm_return_value;

   if (g_stbm_return_value == 0)
   { // E_OK
      *ts = g_test_time_inject;
   }
   return g_stbm_return_value;
}
void SuspendAllInterrupts(void)
{
}
void ResumeAllInterrupts(void)
{
}
void Get_Platform_ustime(uint64 *inst_us_time)
{
   if (inst_us_time != NULL)
   {
      *inst_us_time = g_test_ustime_value;
   }
}
void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time)
{
   (void)start_time;
   if (inst_us_time != NULL)
   {
      *inst_us_time = g_test_elapsed_us_value;
   }
}
void Set_Timer_Cnt_Value_ms(Gpt_TimerPhysicalChannelType ch, float32 val)
{
   g_last_timer_channel  = ch;
   g_last_timer_value_ms = val;
}

void DRE_StatusNotification_Callback(void)
{
}

Std_ReturnType StbM_GetTimeBaseStatus(StbM_SynchronizedTimeBaseType base, StbM_TimeBaseStatusType *syncStatus,
                                      StbM_TimeBaseStatusType *offsetStatus)
{
   (void)base;
   g_StbM_GetTimeBaseStatus_calls++;

   if (syncStatus != NULL)
   {
      *syncStatus = g_stbm_sync_time_base_status;
   }
   if (offsetStatus != NULL)
   {
      *offsetStatus = g_stbm_offset_time_base_status;
   }
   return g_stbm_get_time_base_status_return_value;
}

Std_ReturnType StbM_SetGlobalTime(StbM_SynchronizedTimeBaseType timeBaseId, const StbM_TimeStampType *timeStampPtr,
                                  const StbM_UserDataType *userDataPtr)
{
   g_StbM_SetGlobalTime_calls++;
   g_last_set_global_time_base = timeBaseId;
   if (timeStampPtr != NULL)
   {
      g_last_set_global_time_stamp = *timeStampPtr;
   }
   if (userDataPtr != NULL)
   {
      g_last_set_global_time_user_data = *userDataPtr;
   }
   return g_stbm_set_global_time_return_value;
}
bool Radar_Look_Sync_Test(bool tsyn_status)
{
   g_Radar_Look_Sync_Test_calls++;
   g_last_radar_look_sync_test_arg = tsyn_status;
   return g_Radar_Look_Sync_Test_return_value;
}

void Radar_Ctl_Look_Sync_Trig(void)
{
   g_Radar_Ctl_Look_Sync_Trig_calls++;
}
