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
 *              File: Os_Core_Lcfg.c
 *   Generation Time: 2026-09-14 19:12:49
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

#define OS_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Core_Cfg.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Barrier_Lcfg.h"
#include "Os_Common.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Resource_Lcfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Core_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_CORE0_START_SEC_VAR_CLEARED_NOCACHE_CORESTATUS_ASIL_D_UNSPECIFIED
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore0 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Status_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_NOCACHE_CORESTATUS_ASIL_D_UNSPECIFIED
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore0 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_ThreadClass;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core boot barrier: OsCore0 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_BootBarrier_Dyn;

#define OS_STOP_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore0 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Dyn;
VAR(Os_IntSuspendCountersType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_SuspendIntCounters_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore0_HookRefs[OS_CFG_NUM_CORE_OSCORE0_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore0),
  OS_HOOK_CASTCONFIG_PROTECTIONHOOK_2_HOOK(OsCfg_Hook_ProtectionHook_OsCore0),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore0 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore0_AppRefs[OS_CFG_NUM_CORE_OSCORE0_APPS + 1u] =
{
  (Os_AppConfigRefType) &OsCfg_App_OsCore0_ASIL,
  (Os_AppConfigRefType) &OsCfg_App_OsCore_Qm,
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore0 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IocRefs[OS_CFG_NUM_CORE_OSCORE0_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore0 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore0_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore0 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore0_ResourceRefs[OS_CFG_NUM_CORE_OSCORE0_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCEINTERRUPT_2_RESOURCE(OsCfg_Resource_OsResource),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore0 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore0_StackRefs[OS_CFG_NUM_CORE_OSCORE0_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_BackgroundTask,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_IPC_Task,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_Task,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_Task_Communication,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_Task_Fast,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_Task_High_Prio,
  (Os_StackConfigRefType) &OsCfg_Stack_Appl_Task_Logging,
  (Os_StackConfigRefType) &OsCfg_Stack_BSW_Task,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Protection,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Startup,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio190,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio200,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio210,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_Radar_Ctrl_Task,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IsrRefs[OS_CFG_NUM_CORE_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_AA0_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_AA1_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ANOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Artie_Mem_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_BBE_SP_GPIO0_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CANFD0_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CANFD1_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CMRT_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CNOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMA_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DSP_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet0_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet1_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet2_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet3_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet4_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet5_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet6_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet7_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GPADC_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_HSM_DMB_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_HSM_FUSA_ALARM_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2C_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_END_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_FUSA_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_START_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_FRM_END_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_FRM_START_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MM_INTF0_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_ERROR_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SNOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Serial_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Sysmem0_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Sysmem1_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER1_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER2_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER3_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER4_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER5_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WATCHDOG_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_mipi_err_fusa_handler),
  NULL_PTR
};

/*! Core configuration data: OsCore0 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore0 =
{
  /* .Core                   = */
  {
    /* .Status                      = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore0_Status_Dyn),
    /* .HwConfig                    = */ &OsCfg_Hal_Core_OsCore0,
    /* .InterruptSourceRefs         = */ OsCfg_Hal_Core_OsCore0_InterruptSourceRefs,
    /* .InterruptSourceCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS,
    /* .Id                          = */ OS_CORE_ID_0,
    /* .Trace                       = */ &OsCfg_Trace_OsCore0_Dyn,
    /* .IsAsrCore                   = */ TRUE,
    /* .IsAutostart                 = */ TRUE,
    /* .IsMasterStartAllowed        = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ TRUE
  },
  /* .Dyn                    = */ &OsCfg_Core_OsCore0_Dyn,
  /* .SuspendIntCounters     = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
  /* .Scheduler              = */ &OsCfg_Scheduler_OsCore0,
  /* .IdleTask               = */ &OsCfg_Task_IdleTask_OsCore0,
  /* .KernelApp              = */ &OsCfg_App_SystemApplication_OsCore0,
  /* .KernelStack            = */ &OsCfg_Stack_OsCore0_Kernel,
  /* .PreStartTask           = */ NULL_PTR,
  /* .PreStartTaskCallback   = */ NULL_PTR,
  /* .StartupHookRef         = */ &OsCfg_Hook_StartupHook_OsCore0,
  /* .ShutdownHookRef        = */ &OsCfg_Hook_ShutdownHook_OsCore0,
  /* .ErrorHookRef           = */ &OsCfg_Hook_ErrorHook_OsCore0,
  /* .ProtectionHookRef      = */ &OsCfg_Hook_ProtectionHook_OsCore0,
  /* .InitHookRef            = */ &OsCfg_Hook_Os_CoreInitHook_OsCore0,
  /* .HookRefs               = */ OsCfg_Core_OsCore0_HookRefs,
  /* .HookCount              = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_HOOKS,
  /* .AppRefs                = */ OsCfg_Core_OsCore0_AppRefs,
  /* .AppCount               = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_APPS,
  /* .ResourceRefs           = */ OsCfg_Core_OsCore0_ResourceRefs,
  /* .ResourceCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_RESOURCES,
  /* .HwConfig               = */ &OsCfg_Hal_CoreAsr_OsCore0,
  /* .MemoryProtection       = */ &OsCfg_Mp_OsCore0,
  /* .TimingProtection       = */ NULL_PTR,
  /* .StackRefs              = */ OsCfg_Core_OsCore0_StackRefs,
  /* .StackCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_STACKS,
  /* .CoreIdx                = */ OS_COREASRCOREIDX_0,
  /* .XSignal                = */ NULL_PTR,
  /* .IocRefs                = */ OsCfg_Core_OsCore0_IocRefs,
  /* .IocCount               = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_IOCS,
  /* .Barrier                = */ &OsCfg_Barrier_OsCore0,
  /* .BarrierRefs            = */ OsCfg_Core_OsCore0_BarrierRefs,
  /* .BarrierCount           = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass            = */ &OsCfg_Core_OsCore0_ThreadClass,
  /* .IsrRefs                = */ OsCfg_Core_OsCore0_IsrRefs,
  /* .IsrCount               = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_ISRS
}
;

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for system spinlocks. */
OS_LOCAL CONST(Os_SpinlockConfigRefType, OS_CONST) OsCfg_SystemSpinlockRefs[OS_CFG_NUM_SYSTEM_SPINLOCKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core boot barriers. */
CONSTP2VAR(Os_CoreBootBarrierType, AUTOMATIC, OS_CONST) OsCfg_CoreBootBarrierRefs[OS_COREID_COUNT + 1u] =               /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_Core_OsCore0_BootBarrier_Dyn,
  NULL_PTR
};

/*! System configuration data. */
CONST(Os_SystemConfigType, OS_CONST) OsCfg_System =
{
  /* .VersionInfo      = */
  {
    /* .vendorID         = */ OS_VENDOR_ID,
    /* .moduleID         = */ OS_MODULE_ID,
    /* .sw_major_version = */ OS_SW_MAJOR_VERSION,
    /* .sw_minor_version = */ OS_SW_MINOR_VERSION,
    /* .sw_patch_version = */ OS_SW_PATCH_VERSION
  },
  /* .NumberOfAsrCores = */ OS_COREASRCOREIDX_COUNT,
  /* .SpinlockRefs     = */ OsCfg_SystemSpinlockRefs,
  /* .SpinlockCount    = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_SPINLOCKS,
  /* .HwConfig         = */ &OsCfg_Hal_System,
  /* .MemoryProtection = */ &OsCfg_Mp_SystemMpu,
  /* .InterruptSourceRefs  = */ OsCfg_Hal_System_InterruptSourceRefs,
  /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS,
  /* .Core2Thread      = */ &OsCfg_Hal_Core2Thread
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
 *  END OF FILE: Os_Core_Lcfg.c
 *********************************************************************************************************************/

