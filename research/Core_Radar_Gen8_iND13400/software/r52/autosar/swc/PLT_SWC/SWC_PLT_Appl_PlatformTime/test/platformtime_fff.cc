/*===========================================================================*/
/**
 * @file platformtime_fff.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake function declarations for platformtime.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "platformtime_fff.h"

uint32_t platformtime_fff_mstime_value         = 0U;
uint32_t platformtime_fff_elapsed_mstime_value = 0U;

static void Get_Platform_mstime_default(uint32_t *out_ms)
{
   if (out_ms != nullptr)
   {
      *out_ms = platformtime_fff_mstime_value;
   }
}

static void Get_Platform_Elapsed_mstime_default(uint32_t *out_ms, uint32_t start_ms)
{
   (void)start_ms;
   if (out_ms != nullptr)
   {
      *out_ms = platformtime_fff_elapsed_mstime_value;
   }
}
/*===========================================================================*
 * Fake void functions - platformtime functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(Get_PlatformTime_Init);
DEFINE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64 *);
DEFINE_FAKE_VOID_FUNC(Get_Platform_mstime, uint32_t *);
DEFINE_FAKE_VOID_FUNC(Platform_Ustime_Errorcheck);
DEFINE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);
DEFINE_FAKE_VOID_FUNC(Get_Platform_Elapsed_mstime, uint32_t *, uint32_t);
#if (TRUE == ENABLE_SQT_TEST_STUBS)
DEFINE_FAKE_VOID_FUNC(PlatformTime_Functionality_Test);
#endif

void Init_platformtime_fff_defaults(void)
{
   platformtime_fff_mstime_value                = 0U;
   platformtime_fff_elapsed_mstime_value        = 0U;
   Get_Platform_mstime_fake.custom_fake         = Get_Platform_mstime_default;
   Get_Platform_Elapsed_mstime_fake.custom_fake = Get_Platform_Elapsed_mstime_default;
}

extern "C"
{
}
