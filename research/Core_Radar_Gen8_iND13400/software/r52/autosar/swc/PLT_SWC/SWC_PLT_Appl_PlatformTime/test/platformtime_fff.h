#ifndef PLATFORMTIME_FFF_H
#define PLATFORMTIME_FFF_H
/*===========================================================================*/
/**
 * @file platformtime_fff.h
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
 * Mocking functions for platformtime using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "platformtime.h"

/*===========================================================================*
 * Fake void functions - platformtime functions
 *===========================================================================*/
DECLARE_FAKE_VOID_FUNC(Get_PlatformTime_Init);
DECLARE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64 *);
DECLARE_FAKE_VOID_FUNC(Get_Platform_mstime, uint32_t *);
DECLARE_FAKE_VOID_FUNC(Platform_Ustime_Errorcheck);
DECLARE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);
DECLARE_FAKE_VOID_FUNC(Get_Platform_Elapsed_mstime, uint32_t *, uint32_t);
#if (TRUE == ENABLE_SQT_TEST_STUBS)
DECLARE_FAKE_VOID_FUNC(PlatformTime_Functionality_Test);
#endif

extern uint32_t platformtime_fff_mstime_value;
extern uint32_t platformtime_fff_elapsed_mstime_value;

void Init_platformtime_fff_defaults(void);

/* List of fakes used by this unit tester */
#define FFF_FAKES_PLATFORMTIME_LIST(FAKE)                                                                                         \
   FAKE(Get_PlatformTime_Init)                                                                                                    \
   FAKE(Get_Platform_ustime)                                                                                                      \
   FAKE(Get_Platform_mstime)                                                                                                      \
   FAKE(Platform_Ustime_Errorcheck)                                                                                               \
   FAKE(Get_Platform_Elapsed_ustime)                                                                                              \
   FAKE(Get_Platform_Elapsed_mstime)

#endif /* PLATFORMTIME_FFF_H */
