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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:14
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

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: StartupHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartupHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic task context data: Appl_BackgroundTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_BackgroundTask_Dyn;

/*! HAL dynamic task context data: Appl_IPC_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_IPC_Task_Dyn;

/*! HAL dynamic task context data: Appl_Init */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Init_Dyn;

/*! HAL dynamic task context data: Appl_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Dyn;

/*! HAL dynamic task context data: Appl_Task_Communication */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Communication_Dyn;

/*! HAL dynamic task context data: Appl_Task_Fast */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Fast_Dyn;

/*! HAL dynamic task context data: Appl_Task_High_Prio */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_High_Prio_Dyn;

/*! HAL dynamic task context data: Appl_Task_Logging */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Logging_Dyn;

/*! HAL dynamic task context data: BSW_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Task_Dyn;

/*! HAL dynamic task context data: Init_Task_Qm */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Task_Qm_Dyn;

/*! HAL dynamic task context data: Radar_Ctrl_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Radar_Ctrl_Task_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Init_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL hook context configuration data: StartupHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartupHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Startup_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_HookWrapperCallback,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Startup_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Shutdown_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Error_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Protection_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_HookWrapperProtectionHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)0, /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Protection_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL ISR2 context configuration data: AA0_FUSA_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AA0_FUSA_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_AA0_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: AA1_FUSA_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AA1_FUSA_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_AA1_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: ANOC_Latent_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ANOC_Latent_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ANOC_Latent_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Artie_Mem_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Artie_Mem_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Artie_Mem_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: BBE_SP_FUSA_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BBE_SP_FUSA_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_BBE_SP_FUSA_IRQ_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: BBE_SP_GPIO0_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BBE_SP_GPIO0_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_BBE_SP_GPIO0_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CANFD0_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CANFD0_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_CANFD0_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CANFD1_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CANFD1_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_CANFD1_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CMRT_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CMRT_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_HSM0_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CNOC_Latent_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CNOC_Latent_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_CNOC_Latent_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CRG_RMON_SWS_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CRG_RMON_SWS_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Reset_Monitor_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: CounterIsr_OsCounter */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_OsCounter =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: DMA_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMA_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_MCDMA_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: DSP_Clock_Monitor_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DSP_Clock_Monitor_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_DSP_Clock_Monitor_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet0_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet0_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET0_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet1_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet1_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET1_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet2_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet2_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET2_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet3_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet3_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET3_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet4_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet4_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET4_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet5_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet5_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET5_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet6_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet6_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET6_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Ethernet7_IRQ */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet7_IRQ =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_ETHERNET7_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: GPADC_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GPADC_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_GPADC_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: HSM_DMB_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_HSM_DMB_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_DMB_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: HSM_FUSA_ALARM_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_HSM_FUSA_ALARM_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_HSM_ALARM_FUSA_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: I2C_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2C_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_I2CM_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_CHP_END_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_END_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_chp_end_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_CHP_FUSA_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_FUSA_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_chp_fusa_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_CHP_START_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_START_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_chp_start_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_Clock_Monitor_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_Clock_Monitor_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_MIPI_Clock_Monitor_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_FRM_END_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_FRM_END_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_frm_end_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MIPI_FRM_START_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_FRM_START_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_frm_start_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: MM_INTF0_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MM_INTF0_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mm_intf0_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: RA_Clock_Monitor_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_Clock_Monitor_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_RA_Clock_Monitor_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: RA_ERROR_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_ERROR_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_RA_ERROR_IRQ_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: RA_FUSA_IRQ_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_FUSA_IRQ_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_RA_FUSA_IRQ_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: SNOC_Latent_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SNOC_Latent_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_SNOC_Latent_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Serial_Clock_Monitor_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Serial_Clock_Monitor_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Serial_Clock_Monitor_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Sysmem0_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Sysmem0_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Sysmem0_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: Sysmem1_Fusa_Handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Sysmem1_Fusa_Handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_Sysmem1_Fusa_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: TIMER1_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER1_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_TIMER1_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: TIMER2_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER2_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_TIMER2_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: TIMER3_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER3_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_TIMER3_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: TIMER4_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER4_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_TIMER4_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: TIMER5_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER5_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_TIMER5_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: WATCHDOG_Handler_Isr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WATCHDOG_Handler_Isr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_WATCHDOG_FUSA_Handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: dsp_ctrl_err_fusa_irq_handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_dsp_ctrl_err_fusa_irq_handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_dsp_ctrl_err_fusa_irq_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL ISR2 context configuration data: mipi_err_fusa_handler */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_mipi_err_fusa_handler =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Isr_Core_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)0u,
  /* .Entry            = */ (uint32)&Os_Isr_mipi_err_fusa_handler,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL task context configuration data: Appl_BackgroundTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_BackgroundTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_BackgroundTask_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_BackgroundTask,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_BackgroundTask_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  1024 

}
;

/*! HAL task context configuration data: Appl_IPC_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_IPC_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_IPC_Task_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_IPC_Task,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_IPC_Task_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL task context configuration data: Appl_Init */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Init =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Task_Prio190_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Init,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio190_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  1024 

}
;

/*! HAL task context configuration data: Appl_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_Task_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Task,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_Task_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL task context configuration data: Appl_Task_Communication */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Communication =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_Task_Communication_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Task_Communication,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_Task_Communication_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL task context configuration data: Appl_Task_Fast */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Fast =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_Task_Fast_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Task_Fast,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_Task_Fast_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL task context configuration data: Appl_Task_High_Prio */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_High_Prio =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_Task_High_Prio_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Task_High_Prio,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_Task_High_Prio_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  1024 

}
;

/*! HAL task context configuration data: Appl_Task_Logging */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Logging =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Appl_Task_Logging_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Appl_Task_Logging,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Appl_Task_Logging_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL task context configuration data: BSW_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_BSW_Task_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_BSW_Task,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_BSW_Task_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  2048 

}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  512 

}
;

/*! HAL task context configuration data: Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Task_Prio200_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Init_Task,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio200_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  1024 

}
;

/*! HAL task context configuration data: Init_Task_Qm */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Task_Qm =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Task_Prio210_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Init_Task_Qm,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio210_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  1024 

}
;

/*! HAL task context configuration data: Radar_Ctrl_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Radar_Ctrl_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_Radar_Ctrl_Task_Dyn)),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Radar_Ctrl_Task,   /* PRQA S 0305, 0311, 0314 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Radar_Ctrl_Task_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETLIMIT(OsCfg_Stack_OsCore0_Kernel_Dyn)),  /* OsCore0_Kernel */   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */  4096 

}
;

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
