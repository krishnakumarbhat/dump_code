#ifndef APPL_RTM_FAKE_H_
#define APPL_RTM_FAKE_H_

#include "Gpt.h"
#include "Rte_Type.h"
#include "Rtm_Types.h"
#include "Std_Types.h"
#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(Rtm_InitMemory);
   DECLARE_FAKE_VOID_FUNC(Rtm_Init);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load, const Dt_CPU_Load *);
   DECLARE_FAKE_VALUE_FUNC(Gpt_ValueType, Gpt_GetTimeElapsed, Gpt_ChannelType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rtm_GetMeasurementItem, uint32, Rtm_ItemType, uint32 *);
#ifdef __cplusplus
}

#endif

/* Reset fake functions */

/* APPL_DIAG_FAKE_H_ */

#endif
