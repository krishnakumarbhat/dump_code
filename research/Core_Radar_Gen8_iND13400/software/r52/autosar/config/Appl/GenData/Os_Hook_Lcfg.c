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
 *              File: Os_Hook_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:17
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

#define OS_HOOK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "OsInt.h"

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

/*! Dynamic hook data: Os_CoreInitHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore0_Dyn;

/*! Dynamic hook data: StartupHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_StartupHook_OsCore0_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore0_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore0_Dyn;

/*! Dynamic hook data: ProtectionHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ProtectionHook_OsCore0_Dyn;

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

/*! Hook configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsCore0_Hooks,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)0,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: StartupHook_OsCore0 */
CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartupHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_StartupHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Startup,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_StartupHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsCore0_Hooks,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_STARTUPHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_STARTUPHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_STARTUPHOOK,
    /* .Id           = */ (Os_HookIdType)1,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &StartupHook
};

/*! Hook configuration data: ShutdownHook_OsCore0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsCore0_Hooks,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)2,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsCore0_Hooks,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)3,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

/*! Hook configuration data: ProtectionHook_OsCore0 */
CONST(Os_HookProtectionHookConfigType, OS_CONST) OsCfg_Hook_ProtectionHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ProtectionHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Protection,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ProtectionHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsCore0_Hooks,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_PROTECTIONHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_PROTECTIONHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_PROTECTIONHOOK,
    /* .Id           = */ (Os_HookIdType)4,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ProtectionHook
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for hook callbacks. */
CONSTP2CONST(Os_HookConfigType, OS_CONST, OS_CONST) OsCfg_HookRefs[OS_CFG_NUM_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore0),
  OS_HOOK_CASTCONFIG_PROTECTIONHOOK_2_HOOK(OsCfg_Hook_ProtectionHook_OsCore0),
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
 *  END OF FILE: Os_Hook_Lcfg.c
 *********************************************************************************************************************/
