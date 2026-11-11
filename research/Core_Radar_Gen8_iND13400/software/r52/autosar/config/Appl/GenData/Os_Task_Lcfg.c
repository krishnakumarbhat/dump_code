/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Task_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:18
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Scheduler_Types.h"
#include "Os_Stack_Lcfg.h"
#include "Os_TaskInt.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic task data: Appl_BackgroundTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_BackgroundTask_Dyn;

/*! Dynamic task data: Appl_IPC_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_IPC_Task_Dyn;

/*! Dynamic task data: Appl_Init */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Init_Dyn;

/*! Dynamic task data: Appl_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Task_Dyn;

/*! Dynamic task data: Appl_Task_Communication */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Task_Communication_Dyn;

/*! Dynamic task data: Appl_Task_Fast */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Task_Fast_Dyn;

/*! Dynamic task data: Appl_Task_High_Prio */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Task_High_Prio_Dyn;

/*! Dynamic task data: Appl_Task_Logging */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Appl_Task_Logging_Dyn;

/*! Dynamic task data: BSW_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BSW_Task_Dyn;

/*! Dynamic task data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore0_Dyn;

/*! Dynamic task data: Init_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Init_Task_Dyn;

/*! Dynamic task data: Init_Task_Qm */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Init_Task_Qm_Dyn;

/*! Dynamic task data: Radar_Ctrl_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Radar_Ctrl_Task_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! Task configuration data: Appl_BackgroundTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_BackgroundTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_BackgroundTask,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_BackgroundTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_BackgroundTask,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_BackgroundTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_BackgroundTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_BackgroundTask,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)10u,
  /* .TaskId                 = */ Appl_BackgroundTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)10u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_IPC_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_IPC_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_IPC_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_IPC_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_IPC_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_IPC_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_IPC_Task,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_IPC_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)4u,
  /* .TaskId                 = */ Appl_IPC_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)4u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Init */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Init =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Init,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Init_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio190,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Init_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Init,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Init,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)2u,
  /* .TaskId                 = */ Appl_Init,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Task,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)9u,
  /* .TaskId                 = */ Appl_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)9u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Task_Communication */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Communication =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Task_Communication,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Task_Communication_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_Task_Communication,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Task_Communication_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Task_Communication,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Task_Communication,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)7u,
  /* .TaskId                 = */ Appl_Task_Communication,
  /* .RunningPriority        = */ (Os_TaskPrioType)7u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Task_Fast */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Fast =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Task_Fast,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Task_Fast_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_Task_Fast,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Task_Fast_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Task_Fast,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Task_Fast,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)8u,
  /* .TaskId                 = */ Appl_Task_Fast,
  /* .RunningPriority        = */ (Os_TaskPrioType)8u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Task_High_Prio */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_High_Prio =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Task_High_Prio,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Task_High_Prio_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_Task_High_Prio,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Task_High_Prio_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Task_High_Prio,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Task_High_Prio,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)3u,
  /* .TaskId                 = */ Appl_Task_High_Prio,
  /* .RunningPriority        = */ (Os_TaskPrioType)3u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Appl_Task_Logging */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Logging =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Appl_Task_Logging,
    /* .Context               = */ &OsCfg_Hal_Context_Appl_Task_Logging_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Appl_Task_Logging,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Appl_Task_Logging_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Appl_Task_Logging,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Appl_Task_Logging,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)6u,
  /* .TaskId                 = */ Appl_Task_Logging,
  /* .RunningPriority        = */ (Os_TaskPrioType)6u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: BSW_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BSW_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BSW_Task,
    /* .Context               = */ &OsCfg_Hal_Context_BSW_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_BSW_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BSW_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_BSW_Task,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BSW_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)8u,
  /* .TaskId                 = */ BSW_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)8u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: IdleTask_OsCore0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio4294967295,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_IdleTask_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_IdleTask_OsCore0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)11u,
  /* .TaskId                 = */ IdleTask_OsCore0,
  /* .RunningPriority        = */ (Os_TaskPrioType)11u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_ANY,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Init_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Init_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Init_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Init_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio200,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Init_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Init_Task,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Init_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)1u,
  /* .TaskId                 = */ Init_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OSDEFAULTAPPMODE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Init_Task_Qm */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Init_Task_Qm =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Init_Task_Qm,
    /* .Context               = */ &OsCfg_Hal_Context_Init_Task_Qm_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio210,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Init_Task_Qm_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Init_Task_Qm,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Init_Task_Qm,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)0u,
  /* .TaskId                 = */ Init_Task_Qm,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Radar_Ctrl_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Radar_Ctrl_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Radar_Ctrl_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Radar_Ctrl_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Radar_Ctrl_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Radar_Ctrl_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Radar_Ctrl_Task,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Radar_Ctrl_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)5u,
  /* .TaskId                 = */ Radar_Ctrl_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)5u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .Reschedule             = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_BackgroundTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_IPC_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Communication),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Fast),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_High_Prio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Logging),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Task_Qm),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Radar_Ctrl_Task),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
