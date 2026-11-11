/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_PlatformTime_fake.cc
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
 * Fake/Mock implementation file for SWC_PLT_Appl_PlatformTime unit testing
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#include "SWC_PLT_Appl_PlatformTime_fake.h"

/* Define the RTE variable referenced by the CUT */
uint8 Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = 0U;

DEFINE_FAKE_VOID_FUNC(Platform_Time_Ms_Notification);
DEFINE_FAKE_VOID_FUNC(CS_Platform_register_set, uint8);
DEFINE_FAKE_VOID_FUNC(SuspendAllInterrupts);
DEFINE_FAKE_VOID_FUNC(ResumeAllInterrupts);
DEFINE_FAKE_VALUE_FUNC(uint64_t, Get_Timer_Cnt_Value_Ticks, uint8 *);
DEFINE_FAKE_VOID_FUNC(Get_Platform_mstime, uint32_t *);
DEFINE_FAKE_VOID_FUNC(Get_Platform_Elapsed_mstime, uint32_t *, uint32_t);
DEFINE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64 *);
DEFINE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);

/* Fake the RTE write API and update the backing variable */
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_TR_platform_Time_De_PlatformTime, uint8);

static Std_ReturnType Rte_Write_Pp_TR_platform_Time_De_PlatformTime_default(uint8 data)
{
   Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = data;
   return (Std_ReturnType)0; /* E_OK */
}

__attribute__((constructor)) static void init_swc_plt_platformtime_fakes(void)
{
   Rte_Write_Pp_TR_platform_Time_De_PlatformTime_fake.custom_fake = Rte_Write_Pp_TR_platform_Time_De_PlatformTime_default;
}
