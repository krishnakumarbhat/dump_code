/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_PlatformTime_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock header file for SWC_PLT_Appl_PlatformTime unit testing
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef SWC_PLT_APPL_PLATFORMTIME_FAKE
   #define SWC_PLT_APPL_PLATFORMTIME_FAKE
   #include "Rte_Type.h"
   #include "dd_gpt.h"
   #include "fff.h"

   #ifdef __cplusplus
extern "C"
{
   #endif
   /* External interfaces faked for CUT */
   DECLARE_FAKE_VOID_FUNC(Platform_Time_Ms_Notification);
   DECLARE_FAKE_VOID_FUNC(CS_Platform_register_set, uint8);
   DECLARE_FAKE_VOID_FUNC(SuspendAllInterrupts);
   DECLARE_FAKE_VOID_FUNC(ResumeAllInterrupts);
   DECLARE_FAKE_VOID_FUNC(Get_Platform_mstime, uint32_t *);
   DECLARE_FAKE_VOID_FUNC(Get_Platform_Elapsed_mstime, uint32_t *, uint32_t);
   DECLARE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64 *);
   DECLARE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);

   /* RTE variable exposed by generated code and used by CUT */
   extern uint8 Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime;

   /* Fakes for external calls used by CUT */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_TR_platform_Time_De_PlatformTime, uint8);

   #ifdef __cplusplus
}
   #endif
   #ifdef __cplusplus
extern "C"
{
   #endif
   DECLARE_FAKE_VALUE_FUNC(uint64_t, Get_Timer_Cnt_Value_Ticks, uint8 *);
   #ifdef __cplusplus
}
   #endif
/* Reset fake functions */
#endif

/* Reset fake functions */
#define FFF_FAKE_SWC_PLATFORMTIME(FAKE)                                                                                           \
   FAKE(Rte_Write_Pp_TR_platform_Time_De_PlatformTime)                                                                            \
   FAKE(Get_Timer_Cnt_Value_Ticks)                                                                                                \
   FAKE(Platform_Time_Ms_Notification)                                                                                            \
   FAKE(CS_Platform_register_set)                                                                                                 \
   FAKE(SuspendAllInterrupts)                                                                                                     \
   FAKE(ResumeAllInterrupts)                                                                                                      \
   FAKE(ResumeAllInterrupts)                                                                                                      \
   FAKE(CS_Platform_register_set)                                                                                                 \
   FAKE(Get_Platform_mstime)                                                                                                      \
   FAKE(Get_Platform_Elapsed_mstime)                                                                                              \
   FAKE(Get_Platform_ustime)                                                                                                      \
   FAKE(Get_Platform_Elapsed_ustime)
