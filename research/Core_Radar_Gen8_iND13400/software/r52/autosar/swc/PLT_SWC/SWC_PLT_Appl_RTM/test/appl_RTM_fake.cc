#include "appl_RTM_fake.h"

DEFINE_FAKE_VOID_FUNC(Rtm_Init);
DEFINE_FAKE_VOID_FUNC(Rtm_InitMemory);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rtm_GetMeasurementItem, uint32, Rtm_ItemType, uint32 *);
DEFINE_FAKE_VALUE_FUNC(Gpt_ValueType, Gpt_GetTimeElapsed, Gpt_ChannelType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load, const Dt_CPU_Load *);
