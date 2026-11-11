#ifndef SWC_PLT_CDD_ECUSYNC_FAKE_H
#define SWC_PLT_CDD_ECUSYNC_FAKE_H

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

   /* Minimal type replicas / forward declarations to decouple fake lib from production headers.
      They are crafted to match production underlying types to avoid ODR/type mismatch when the
      real headers are pulled in by the test translation unit that also includes the .c sources. */

   typedef float float32;                         /* production uses float32 via Std_Types */
   typedef uint8_t Std_ReturnType;                /* matches Std_Types */
   typedef uint32_t Gpt_TimerPhysicalChannelType; /* underlying physical channel type */

   typedef struct StbM_TimeStampType StbM_TimeStampType; /* incomplete OK for pointer use */
   typedef struct StbM_UserDataType StbM_UserDataType;   /* incomplete OK for pointer use */

   /* RTE / OS / GPT dependent functions to fake */
   DECLARE_FAKE_VOID_FUNC(Start_EcuSync_Timer);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_GlobalTime_Slave_StbMSynchronizedTimeBase_GetCurrentTime,
                           StbM_TimeStampType *, StbM_UserDataType *);
   DECLARE_FAKE_VOID_FUNC(SuspendAllInterrupts);
   DECLARE_FAKE_VOID_FUNC(ResumeAllInterrupts);
   DECLARE_FAKE_VOID_FUNC(Set_Timer_Cnt_Value_ms, Gpt_TimerPhysicalChannelType, float32);

#ifdef __cplusplus
}
#endif

#endif /* SWC_PLT_CDD_ECUSYNC_FAKE_H */
