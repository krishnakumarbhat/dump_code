#ifndef STACK_MONITOR_R52_H
#define STACK_MONITOR_R52_H
/*===========================================================================*\
 * FILE: stack_monitor_r52.h
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 *
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/
#include "Os_CoreInt.h"
#include "Os_StackInt.h"
#include "Os_Stack_Cfg.h"
#include "Os_Thread.h"
// #include "debug_stream.h"
#include "Os.h"
#include "reuse.h"
#include <stdint.h>
#include <string.h>

/*===========================================================================*\
 *  preprocessor #define CONSTANTS
\*===========================================================================*/
#define TOTAL_NUM_TASKS OS_TASKID_COUNT // 7
#define TOTAL_NUM_ISRS  OS_ISRID_COUNT  // 14
#define PERCENTAGE      (100U)
#define INVALID_VALUE   (255U)
#define BYTES           (4U)

typedef struct
{
   uint32_t stack_isr[TOTAL_NUM_ISRS];
   uint8_t stack_isr_percentage[TOTAL_NUM_ISRS];
   ISRType ISR_Type[TOTAL_NUM_ISRS];
   /* Note: ALl category-2 ISRs which are not nestable share one stack*/
   bool ISR_stack_sharing[TOTAL_NUM_ISRS]; /*  */

   /* data */
} Stack_ISR_R52_T;

typedef struct
{
   uint32_t stack_task[TOTAL_NUM_TASKS];
   uint8_t stack_task_percentage[TOTAL_NUM_TASKS];
   TaskType TASK_Type[TOTAL_NUM_TASKS];
   /* Reschedule  = OS_TASKSCHEDULE_ALLOWED(0) : Stack is not shared
                  = OS_TASKSCHEDULE_PROHIBITED(1) : Stack is shared
   */
   Os_TaskScheduleType TASk_stack_sharing[TOTAL_NUM_TASKS];

   /* data */
} Stack_TASK_R52_T;

typedef struct
{
   uint32_t R52_StackCore_Kernel;
   uint32_t R52_StackCore_Startuphook;
   uint32_t R52_StackCore_Errorhook;
   uint32_t R52_StackCore_Shutdownhook;
   uint32_t R52_StackCore_Protectionhook;

   uint8_t R52_StackCore_Kernel_percentage;
   uint8_t R52_StackCore_Startuphook_percentage;
   uint8_t R52_StackCore_Errorhook_percentage;
   uint8_t R52_StackCore_Shutdownhook_percentage;
   uint8_t R52_StackCore_Protectionhook_percentage;
   /* data */
} Stack_CORE_R52_T;

/*===========================================================================*\
 * Function declarations
\*===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
   void Stack_Monitor_R52(void);
   uint8_t CalculateStackUsageInPercentage(uint32_t stack_sizes, uint32_t stack_usage);
   uint8_t CalculateStackUsageInPercentage_task(const uint32_t *low, const uint32_t *high, const uint32_t stack_usage);
   Stack_ISR_R52_T *Get_stack_isr_r52(void);
   Stack_TASK_R52_T *Get_stack_task_r52(void);
   Stack_CORE_R52_T *Get_stack_core_r52(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STACK_MONITOR_R52_H */
