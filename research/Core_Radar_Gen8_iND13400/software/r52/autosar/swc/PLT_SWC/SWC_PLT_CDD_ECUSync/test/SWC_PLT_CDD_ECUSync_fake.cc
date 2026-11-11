#include "SWC_PLT_CDD_ECUSync_fake.h"

DEFINE_FAKE_VOID_FUNC(Start_EcuSync_Timer);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime, StbM_TimeStampType *,
                       StbM_UserDataType *);
DEFINE_FAKE_VOID_FUNC(SuspendAllInterrupts);
DEFINE_FAKE_VOID_FUNC(ResumeAllInterrupts);
DEFINE_FAKE_VOID_FUNC(Set_Timer_Cnt_Value_ms, Gpt_TimerPhysicalChannelType, float32);
