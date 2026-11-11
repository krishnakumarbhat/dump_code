/*===========================================================================*/
/**
 * @file stack_monitor_r52_fake.cc
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
 * Fake/Mock implementation file for stack_monitor_r52 unit testing
 *
 * @section ABBR ABBREVIATIONS:
 *   - FFF: Fake Function Framework
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - stack_monitor_r52 Unit Test Design
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#include "stack_monitor_r52_fake.h"

/* Define fake functions */
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetKernelStackUsage, CoreIdType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetErrorHookStackUsage, CoreIdType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetShutdownHookStackUsage, CoreIdType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetProtectionHookStackUsage, CoreIdType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetStartupHookStackUsage, CoreIdType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetISRStackUsage, ISRType);
DEFINE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetTaskStackUsage, TaskType);
DEFINE_FAKE_VALUE_FUNC(const Os_TaskConfigType *, Os_TaskId2Task, TaskType);
DEFINE_FAKE_VALUE_FUNC(const Os_ThreadConfigType *, Os_TaskGetThread, const Os_TaskConfigType *);
DEFINE_FAKE_VALUE_FUNC(const Os_StackConfigType *, Os_ThreadGetStack, const Os_ThreadConfigType *);
