/*===========================================================================*/
/**
 * @file stack_monitor_r52_fake.h
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
 * Fake/Mock header file for stack_monitor_r52 unit testing
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

#ifndef STACK_MONITOR_R52_FAKE_H
#define STACK_MONITOR_R52_FAKE_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* Type definitions to avoid including AUTOSAR OS headers */
   typedef uint32_t Os_StackSizeType;
   typedef uint32_t CoreIdType;
   typedef uint32_t ISRType;
   typedef uint32_t TaskType;

#define OS_CORE_ID_0 0U
#define TRUE         1
#define FALSE        0

   /* Forward declarations for AUTOSAR OS types */
   typedef struct Os_TaskConfigType_tag Os_TaskConfigType;
   typedef struct Os_ThreadConfigType_tag Os_ThreadConfigType;
   typedef struct Os_StackConfigType_tag Os_StackConfigType;

   /* Task schedule types */
   typedef enum
   {
      OS_TASKSCHEDULE_ALLOWED    = 0,
      OS_TASKSCHEDULE_PROHIBITED = 1
   } Os_TaskScheduleType;

   /* Mock structure definitions */
   struct Os_TaskConfigType_tag
   {
      Os_TaskScheduleType Reschedule;
      /* Other fields not needed for testing */
   };

   struct Os_ThreadConfigType_tag
   {
      uint32_t dummy;
      /* Other fields not needed for testing */
   };

   struct Os_StackConfigType_tag
   {
      uint32_t *LowAddress;
      uint32_t *HighAddress;
      /* Other fields not needed for testing */
   };

/* AUTOSAR pointer macros */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define P2VAR(ptrtype, memclass, ptrclass)   ptrtype *
#define AUTOMATIC
#define OS_CONST

   /* Mock AUTOSAR OS functions */
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetKernelStackUsage, CoreIdType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetErrorHookStackUsage, CoreIdType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetShutdownHookStackUsage, CoreIdType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetProtectionHookStackUsage, CoreIdType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetStartupHookStackUsage, CoreIdType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetISRStackUsage, ISRType);
   DECLARE_FAKE_VALUE_FUNC(Os_StackSizeType, Os_GetTaskStackUsage, TaskType);
   DECLARE_FAKE_VALUE_FUNC(const Os_TaskConfigType *, Os_TaskId2Task, TaskType);
   DECLARE_FAKE_VALUE_FUNC(const Os_ThreadConfigType *, Os_TaskGetThread, const Os_TaskConfigType *);
   DECLARE_FAKE_VALUE_FUNC(const Os_StackConfigType *, Os_ThreadGetStack, const Os_ThreadConfigType *);

#ifdef __cplusplus
}
#endif

#endif /* STACK_MONITOR_R52_FAKE_H */
