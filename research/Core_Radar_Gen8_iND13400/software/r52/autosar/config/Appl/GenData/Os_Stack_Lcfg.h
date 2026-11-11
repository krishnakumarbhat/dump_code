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
 *              File: Os_Stack_Lcfg.h
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
#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_BackgroundTask */
/* User: [Appl_BackgroundTask] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_BackgroundTask_Dyn, OS_CFG_SIZE_APPL_BACKGROUNDTASK_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_IPC_Task */
/* User: [Appl_IPC_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_IPC_Task_Dyn, OS_CFG_SIZE_APPL_IPC_TASK_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_Task */
/* User: [Appl_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_Task_Dyn, OS_CFG_SIZE_APPL_TASK_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_Task_Communication */
/* User: [Appl_Task_Communication] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_Task_Communication_Dyn, OS_CFG_SIZE_APPL_TASK_COMMUNICATION_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_Task_Fast */
/* User: [Appl_Task_Fast] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_Task_Fast_Dyn, OS_CFG_SIZE_APPL_TASK_FAST_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_Task_High_Prio */
/* User: [Appl_Task_High_Prio] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_Task_High_Prio_Dyn, OS_CFG_SIZE_APPL_TASK_HIGH_PRIO_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Appl_Task_Logging */
/* User: [Appl_Task_Logging] */
extern OS_STACK_DECLARE(OsCfg_Stack_Appl_Task_Logging_Dyn, OS_CFG_SIZE_APPL_TASK_LOGGING_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: BSW_Task */
/* User: [BSW_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_BSW_Task_Dyn, OS_CFG_SIZE_BSW_TASK_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, ErrorHook_OsCore0_ASIL, ErrorHook_OsCore_Qm, ErrorHook_SystemApplication_OsCore0, OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [AA0_FUSA_IRQ_Handler, AA1_FUSA_IRQ_Handler, ANOC_Latent_Fusa_Handler, Artie_Mem_Fusa_Handler, BBE_SP_FUSA_IRQ_Handler, BBE_SP_GPIO0_Handler, CANFD0_Handler_Isr, CANFD1_Handler_Isr, CMRT_ISR, CNOC_Latent_Fusa_Handler, CRG_RMON_SWS_IRQ_Handler, CounterIsr_OsCounter, DMA_Handler_Isr, DSP_Clock_Monitor_Handler, Ethernet0_IRQ, Ethernet1_IRQ, Ethernet2_IRQ, Ethernet3_IRQ, Ethernet4_IRQ, Ethernet5_IRQ, Ethernet6_IRQ, Ethernet7_IRQ, GPADC_Handler_Isr, HSM_DMB_ISR, HSM_FUSA_ALARM_ISR, I2C_Handler_Isr, MIPI_CHP_END_Handler, MIPI_CHP_FUSA_Handler, MIPI_CHP_START_Handler, MIPI_Clock_Monitor_Handler, MIPI_FRM_END_Handler, MIPI_FRM_START_Handler, MM_INTF0_Handler, RA_Clock_Monitor_Handler, RA_ERROR_IRQ_Handler, RA_FUSA_IRQ_Handler, SNOC_Latent_Fusa_Handler, Serial_Clock_Monitor_Handler, Sysmem0_Fusa_Handler, Sysmem1_Fusa_Handler, TIMER1_Handler_Isr, TIMER2_Handler_Isr, TIMER3_Handler_Isr, TIMER4_Handler_Isr, TIMER5_Handler_Isr, WATCHDOG_Handler_Isr, dsp_ctrl_err_fusa_irq_handler, mipi_err_fusa_handler] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core protection stack: OsCore0_Protection */
/* User: [OsCore0, ProtectionHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Protection_Dyn, OS_CFG_SIZE_OSCORE0_PROTECTION_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore0_Shutdown */
/* User: [OsCore0, ShutdownHook_OsCore0, ShutdownHook_OsCore0_ASIL, ShutdownHook_OsCore_Qm, ShutdownHook_SystemApplication_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core startup stack: OsCore0_Startup */
/* User: [OsCore0, StartupHook_OsCore0, StartupHook_OsCore0_ASIL, StartupHook_OsCore_Qm, StartupHook_SystemApplication_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Startup_Dyn, OS_CFG_SIZE_OSCORE0_STARTUP_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio190 */
/* User: [Appl_Init] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio190_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO190_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio200 */
/* User: [Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio200_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO200_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio210 */
/* User: [Init_Task_Qm] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio210_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO210_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Radar_Ctrl_Task */
/* User: [Radar_Ctrl_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_Radar_Ctrl_Task_Dyn, OS_CFG_SIZE_RADAR_CTRL_TASK_STACK);

# define OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Stacks_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Standard stack configuration data: Appl_BackgroundTask */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_BackgroundTask;
/* Standard stack configuration data: Appl_IPC_Task */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_IPC_Task;
/* Standard stack configuration data: Appl_Task */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_Task;
/* Standard stack configuration data: Appl_Task_Communication */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_Task_Communication;
/* Standard stack configuration data: Appl_Task_Fast */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_Task_Fast;
/* Standard stack configuration data: Appl_Task_High_Prio */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_Task_High_Prio;
/* Standard stack configuration data: Appl_Task_Logging */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Appl_Task_Logging;
/* Standard stack configuration data: BSW_Task */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_BSW_Task;
/* Standard stack configuration data: OsCore0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error;
/* Standard stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;
/* Standard stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;
/* Standard stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;
/* Standard stack configuration data: OsCore0_Protection */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Protection;
/* Standard stack configuration data: OsCore0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Shutdown;
/* Standard stack configuration data: OsCore0_Startup */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Startup;
/* Standard stack configuration data: OsCore0_Task_Prio190 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio190;
/* Standard stack configuration data: OsCore0_Task_Prio200 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio200;
/* Standard stack configuration data: OsCore0_Task_Prio210 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio210;
/* Standard stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;
/* Standard stack configuration data: Radar_Ctrl_Task */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Radar_Ctrl_Task;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
