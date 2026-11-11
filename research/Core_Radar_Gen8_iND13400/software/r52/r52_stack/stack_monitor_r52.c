/*===========================================================================*\
 * FILE: stack_monitor_r52.c
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
#include "stack_monitor_r52.h"

/*====================================================================================================================*\
 * OBJECT DEFINITIONS
\*====================================================================================================================*/
Stack_ISR_R52_T stack_isr_r52;
Stack_TASK_R52_T stack_task_r52;
Stack_CORE_R52_T stack_core_r52;
volatile uint16_t counter_stack_monitor_r52 = 0;
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Stack_Monitor_MSS
 *===========================================================================
 * RETURN VALUE: void
 *
 *
 * PARAMETERS: void

 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This is MSS stack monitoring function. Gets executed at every 1seconds.
 * MSS stack utlization is stored in MSS_Stack_Utilization structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Stack_Monitor_R52(void)
{
   uint8_t taskId    = 0;
   uint8_t isrId     = 0;
   CoreIdType coreId = (CoreIdType)OS_CORE_ID_0;
   P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) TaskRef;
   P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) stack_temp;
   P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread_temp;

   counter_stack_monitor_r52++;

   memset((Stack_ISR_R52_T *)&stack_isr_r52, 0, sizeof(Stack_ISR_R52_T));
   memset((Stack_TASK_R52_T *)&stack_task_r52, 0, sizeof(Stack_TASK_R52_T));
   memset((Stack_CORE_R52_T *)&stack_core_r52, 0, sizeof(Stack_CORE_R52_T));

   stack_core_r52.R52_StackCore_Kernel = Os_GetKernelStackUsage(coreId);
   stack_core_r52.R52_StackCore_Kernel_percentage =
      CalculateStackUsageInPercentage(OS_CFG_SIZE_OSCORE0_KERNEL_STACK, stack_core_r52.R52_StackCore_Kernel);

   stack_core_r52.R52_StackCore_Errorhook = Os_GetErrorHookStackUsage(coreId);
   stack_core_r52.R52_StackCore_Errorhook_percentage =
      CalculateStackUsageInPercentage(OS_CFG_SIZE_OSCORE0_ERROR_STACK, stack_core_r52.R52_StackCore_Errorhook);

   stack_core_r52.R52_StackCore_Shutdownhook = Os_GetShutdownHookStackUsage(coreId);
   stack_core_r52.R52_StackCore_Shutdownhook_percentage =
      CalculateStackUsageInPercentage(OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK, stack_core_r52.R52_StackCore_Shutdownhook);

   /* Note: Protection and Startuphook are not initialized and configured */
   // stack_core_r52.R52_StackCore_Protectionhook = Os_GetProtectionHookStackUsage(coreId);
   /*     stack_core_r52.R52_StackCore_Protectionhook_percentage = CalculateStackUsageInPercentage(,
    * stack_core_r52.R52_StackCore_Protectionhook); */

   // stack_core_r52.R52_StackCore_Startuphook = Os_GetStartupHookStackUsage(coreId);
   /*     stack_core_r52.R52_StackCore_Startuphook_percentage =CalculateStackUsageInPercentage(,
    * stack_core_r52.R52_StackCore_Startuphook);  */

   /*Stack measurement for ISRs*/
   /* Note: Bytes utilized (stack_isr_r52.stack_isr[isrId]) is same for all ISRs because Stack is shared across all ISRs. */
   for (isrId = 0; isrId < (uint32_t)TOTAL_NUM_ISRS; isrId++)
   {
      stack_isr_r52.stack_isr[isrId]            = Os_GetISRStackUsage((ISRType)isrId);
      stack_isr_r52.stack_isr_percentage[isrId] = (uint8_t)CalculateStackUsageInPercentage(
         (uint32_t)OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK, (uint32_t)stack_isr_r52.stack_isr[isrId]);
      stack_isr_r52.ISR_Type[isrId]          = (ISRType)isrId;
      stack_isr_r52.ISR_stack_sharing[isrId] = TRUE; /* All ISRs have shared stack */
   }

   /*Stack measurement for task*/
   for (taskId = 0; taskId < (uint32_t)TOTAL_NUM_TASKS; taskId++)
   {
      stack_task_r52.stack_task[taskId] = Os_GetTaskStackUsage((TaskType)taskId);
      stack_task_r52.TASK_Type[taskId]  = (TaskType)taskId;
      TaskRef                           = Os_TaskId2Task(taskId); // OsCfg_TaskRefs[taskId];
                                                                  /* Reschedule  = OS_TASKSCHEDULE_ALLOWED(0) : Stack is not shared
                                                                              = OS_TASKSCHEDULE_PROHIBITED(1) : Stack is shared
                                                                  */
      thread_temp                                  = Os_TaskGetThread(Os_TaskId2Task(taskId));
      stack_temp                                   = Os_ThreadGetStack(thread_temp);
      stack_task_r52.TASk_stack_sharing[taskId]    = (*(TaskRef)).Reschedule;
      stack_task_r52.stack_task_percentage[taskId] = (uint8_t)CalculateStackUsageInPercentage_task(
         (uint32_t *)stack_temp->LowAddress, (uint32_t *)stack_temp->HighAddress, stack_task_r52.stack_task[taskId]);
   }
}

/*===========================================================================*\
* FUNCTION: CalculateStackUsageInPercentage
*===========================================================================
* RETURN VALUE:uint8_t Percentage of stack consumed

*
* PARAMETERS:uint32_t stack_size, uint32_t stack_usage


* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* --------------------------------------------------------------------------
* ABSTRACT:
* --------------------------------------------------------------------------

* PRECONDITIONS:
*  None
* POSTCONDITIONS:
* None
\*===========================================================================*/

uint8_t CalculateStackUsageInPercentage(uint32_t stack_sizes, uint32_t stack_usage)
{
   uint8_t return_var = 0;
   if (0u != stack_sizes)
   {
      return_var = (uint8_t)((stack_usage * PERCENTAGE) / (stack_sizes));
   }
   else
   {
      return_var = 0;
   }
   return return_var;
}

/*===========================================================================*\
 * FUNCTION: CalculateStackUsageInPercentage_task
 *===========================================================================
 * RETURN VALUE: uint8_t Percentage of stack consumed
 *
 *
 * PARAMETERS: uint32_t* low address, uint32_t* high address, uint32_t stack_usage

 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This is MSS stack monitoring function. Gets executed at every 1seconds.
 * MSS stack utlization is stored in MSS_Stack_Utilization structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t CalculateStackUsageInPercentage_task(const uint32_t *low, const uint32_t *high, const uint32_t stack_usage)
{
   uint32_t total_stack_size_allocated = 0;
   uint8_t return_var                  = 0;
   if ((NULL != low) || (NULL != high))
   {
      total_stack_size_allocated = (uint32_t)(high - low);
      /* Note: (BYTES*total_stack_size_allocated) this is done because each stack address has 4bytes info */
      return_var = (uint32_t)(stack_usage * PERCENTAGE) / (total_stack_size_allocated * BYTES);
   }
   else
   {
      return_var = INVALID_VALUE;
   }
   return return_var;
}

/*===========================================================================*\
 * FUNCTION: Get_stack_isr_r52
 *===========================================================================
 * RETURN VALUE: Stack_ISR_R52_T* stack_isr_r52
 *
 *
 * PARAMETERS: void

 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This is MSS stack monitoring function. Gets executed at every 1seconds.
 * MSS stack utlization is stored in MSS_Stack_Utilization structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Stack_ISR_R52_T *Get_stack_isr_r52(void)
{
   return (&stack_isr_r52);
}

/*===========================================================================*\
 * FUNCTION: Get_stack_task_r52
 *===========================================================================
 * RETURN VALUE: Stack_TASK_R52_T* stack_task_r52
 *
 *
 * PARAMETERS: void

 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This is MSS stack monitoring function. Gets executed at every 1seconds.
 * MSS stack utlization is stored in MSS_Stack_Utilization structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Stack_TASK_R52_T *Get_stack_task_r52(void)
{
   return (&stack_task_r52);
}

/*===========================================================================*\
 * FUNCTION: Get_stack_core_r52
 *===========================================================================
 * RETURN VALUE: Stack_CORE_R52_T* stack_core_r52
 *
 *
 * PARAMETERS: void

 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This is MSS stack monitoring function. Gets executed at every 1seconds.
 * MSS stack utlization is stored in MSS_Stack_Utilization structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Stack_CORE_R52_T *Get_stack_core_r52(void)
{
   return (&stack_core_r52);
}
