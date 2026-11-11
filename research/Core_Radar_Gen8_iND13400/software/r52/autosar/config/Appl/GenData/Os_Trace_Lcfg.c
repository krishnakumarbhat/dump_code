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
 *              File: Os_Trace_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:19
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

#define OS_TRACE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Trace_Lcfg.h"
#include "Os_Trace.h"

/* Os kernel module dependencies */
#include "Os_Common_Types.h"

/* Os hal dependencies */


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

#define OS_CORE0_START_SEC_VAR_CLEARED_PUBLIC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic trace data: OsCore0 */
VAR(Os_TraceCoreType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Dyn;

/*! Dynamic trace data: Appl_BackgroundTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_BackgroundTask_Dyn;

/*! Dynamic trace data: Appl_IPC_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_IPC_Task_Dyn;

/*! Dynamic trace data: Appl_Init */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Init_Dyn;

/*! Dynamic trace data: Appl_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Task_Dyn;

/*! Dynamic trace data: Appl_Task_Communication */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Task_Communication_Dyn;

/*! Dynamic trace data: Appl_Task_Fast */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Task_Fast_Dyn;

/*! Dynamic trace data: Appl_Task_High_Prio */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Task_High_Prio_Dyn;

/*! Dynamic trace data: Appl_Task_Logging */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Appl_Task_Logging_Dyn;

/*! Dynamic trace data: BSW_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BSW_Task_Dyn;

/*! Dynamic trace data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_IdleTask_OsCore0_Dyn;

/*! Dynamic trace data: Init_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Init_Task_Dyn;

/*! Dynamic trace data: Init_Task_Qm */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Init_Task_Qm_Dyn;

/*! Dynamic trace data: Radar_Ctrl_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Radar_Ctrl_Task_Dyn;

/*! Dynamic trace data: AA0_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_AA0_FUSA_IRQ_Handler_Dyn;

/*! Dynamic trace data: AA1_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_AA1_FUSA_IRQ_Handler_Dyn;

/*! Dynamic trace data: ANOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ANOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic trace data: Artie_Mem_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Artie_Mem_Fusa_Handler_Dyn;

/*! Dynamic trace data: BBE_SP_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BBE_SP_FUSA_IRQ_Handler_Dyn;

/*! Dynamic trace data: BBE_SP_GPIO0_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BBE_SP_GPIO0_Handler_Dyn;

/*! Dynamic trace data: CANFD0_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CANFD0_Handler_Isr_Dyn;

/*! Dynamic trace data: CANFD1_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CANFD1_Handler_Isr_Dyn;

/*! Dynamic trace data: CMRT_ISR */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CMRT_ISR_Dyn;

/*! Dynamic trace data: CNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CNOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic trace data: CRG_RMON_SWS_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CRG_RMON_SWS_IRQ_Handler_Dyn;

/*! Dynamic trace data: CounterIsr_OsCounter */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CounterIsr_OsCounter_Dyn;

/*! Dynamic trace data: DMA_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_DMA_Handler_Isr_Dyn;

/*! Dynamic trace data: DSP_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_DSP_Clock_Monitor_Handler_Dyn;

/*! Dynamic trace data: Ethernet0_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet0_IRQ_Dyn;

/*! Dynamic trace data: Ethernet1_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet1_IRQ_Dyn;

/*! Dynamic trace data: Ethernet2_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet2_IRQ_Dyn;

/*! Dynamic trace data: Ethernet3_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet3_IRQ_Dyn;

/*! Dynamic trace data: Ethernet4_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet4_IRQ_Dyn;

/*! Dynamic trace data: Ethernet5_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet5_IRQ_Dyn;

/*! Dynamic trace data: Ethernet6_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet6_IRQ_Dyn;

/*! Dynamic trace data: Ethernet7_IRQ */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Ethernet7_IRQ_Dyn;

/*! Dynamic trace data: GPADC_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_GPADC_Handler_Isr_Dyn;

/*! Dynamic trace data: HSM_DMB_ISR */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_HSM_DMB_ISR_Dyn;

/*! Dynamic trace data: HSM_FUSA_ALARM_ISR */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_HSM_FUSA_ALARM_ISR_Dyn;

/*! Dynamic trace data: I2C_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_I2C_Handler_Isr_Dyn;

/*! Dynamic trace data: MIPI_CHP_END_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_CHP_END_Handler_Dyn;

/*! Dynamic trace data: MIPI_CHP_FUSA_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_CHP_FUSA_Handler_Dyn;

/*! Dynamic trace data: MIPI_CHP_START_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_CHP_START_Handler_Dyn;

/*! Dynamic trace data: MIPI_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_Clock_Monitor_Handler_Dyn;

/*! Dynamic trace data: MIPI_FRM_END_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_FRM_END_Handler_Dyn;

/*! Dynamic trace data: MIPI_FRM_START_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MIPI_FRM_START_Handler_Dyn;

/*! Dynamic trace data: MM_INTF0_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MM_INTF0_Handler_Dyn;

/*! Dynamic trace data: RA_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_RA_Clock_Monitor_Handler_Dyn;

/*! Dynamic trace data: RA_ERROR_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_RA_ERROR_IRQ_Handler_Dyn;

/*! Dynamic trace data: RA_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_RA_FUSA_IRQ_Handler_Dyn;

/*! Dynamic trace data: SNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SNOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic trace data: Serial_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Serial_Clock_Monitor_Handler_Dyn;

/*! Dynamic trace data: Sysmem0_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Sysmem0_Fusa_Handler_Dyn;

/*! Dynamic trace data: Sysmem1_Fusa_Handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Sysmem1_Fusa_Handler_Dyn;

/*! Dynamic trace data: TIMER1_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_TIMER1_Handler_Isr_Dyn;

/*! Dynamic trace data: TIMER2_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_TIMER2_Handler_Isr_Dyn;

/*! Dynamic trace data: TIMER3_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_TIMER3_Handler_Isr_Dyn;

/*! Dynamic trace data: TIMER4_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_TIMER4_Handler_Isr_Dyn;

/*! Dynamic trace data: TIMER5_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_TIMER5_Handler_Isr_Dyn;

/*! Dynamic trace data: WATCHDOG_Handler_Isr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_WATCHDOG_Handler_Isr_Dyn;

/*! Dynamic trace data: dsp_ctrl_err_fusa_irq_handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_dsp_ctrl_err_fusa_irq_handler_Dyn;

/*! Dynamic trace data: mipi_err_fusa_handler */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_mipi_err_fusa_handler_Dyn;

/*! Dynamic trace data: OsCore0_Hooks */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Hooks_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_PUBLIC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trace configuration data: OsCore0_ASIL */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsCore0_ASIL =
{
  /* .Id   = */ Os_TraceId_OsCore0_ASIL
};

/*! Trace configuration data: OsCore_Qm */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsCore_Qm =
{
  /* .Id   = */ Os_TraceId_OsCore_Qm
};

/*! Trace configuration data: SystemApplication_OsCore0 */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_SystemApplication_OsCore0 =
{
  /* .Id   = */ Os_TraceId_SystemApplication_OsCore0
};

/*! Trace configuration data: Appl_BackgroundTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_BackgroundTask =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_BackgroundTask_Dyn,
  /* .Id   = */ Os_TraceId_Appl_BackgroundTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_IPC_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_IPC_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_IPC_Task_Dyn,
  /* .Id   = */ Os_TraceId_Appl_IPC_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Init */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Init =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Init_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Init,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Task_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Task_Communication */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Communication =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Task_Communication_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Task_Communication,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Task_Fast */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Fast =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Task_Fast_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Task_Fast,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Task_High_Prio */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_High_Prio =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Task_High_Prio_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Task_High_Prio,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Appl_Task_Logging */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Logging =
{
  /* .Dyn  = */ &OsCfg_Trace_Appl_Task_Logging_Dyn,
  /* .Id   = */ Os_TraceId_Appl_Task_Logging,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: BSW_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BSW_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_BSW_Task_Dyn,
  /* .Id   = */ Os_TraceId_BSW_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: IdleTask_OsCore0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore0 =
{
  /* .Dyn  = */ &OsCfg_Trace_IdleTask_OsCore0_Dyn,
  /* .Id   = */ Os_TraceId_IdleTask_OsCore0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Init_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Init_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_Init_Task_Dyn,
  /* .Id   = */ Os_TraceId_Init_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Init_Task_Qm */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Init_Task_Qm =
{
  /* .Dyn  = */ &OsCfg_Trace_Init_Task_Qm_Dyn,
  /* .Id   = */ Os_TraceId_Init_Task_Qm,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Radar_Ctrl_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Radar_Ctrl_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_Radar_Ctrl_Task_Dyn,
  /* .Id   = */ Os_TraceId_Radar_Ctrl_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: AA0_FUSA_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_AA0_FUSA_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_AA0_FUSA_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_AA0_FUSA_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: AA1_FUSA_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_AA1_FUSA_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_AA1_FUSA_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_AA1_FUSA_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: ANOC_Latent_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ANOC_Latent_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_ANOC_Latent_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_ANOC_Latent_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Artie_Mem_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Artie_Mem_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_Artie_Mem_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_Artie_Mem_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: BBE_SP_FUSA_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BBE_SP_FUSA_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_BBE_SP_FUSA_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_BBE_SP_FUSA_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: BBE_SP_GPIO0_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BBE_SP_GPIO0_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_BBE_SP_GPIO0_Handler_Dyn,
  /* .Id   = */ Os_TraceId_BBE_SP_GPIO0_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CANFD0_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CANFD0_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_CANFD0_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_CANFD0_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CANFD1_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CANFD1_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_CANFD1_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_CANFD1_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CMRT_ISR */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CMRT_ISR =
{
  /* .Dyn  = */ &OsCfg_Trace_CMRT_ISR_Dyn,
  /* .Id   = */ Os_TraceId_CMRT_ISR,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CNOC_Latent_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CNOC_Latent_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_CNOC_Latent_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_CNOC_Latent_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CRG_RMON_SWS_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CRG_RMON_SWS_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_CRG_RMON_SWS_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_CRG_RMON_SWS_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CounterIsr_OsCounter */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CounterIsr_OsCounter =
{
  /* .Dyn  = */ &OsCfg_Trace_CounterIsr_OsCounter_Dyn,
  /* .Id   = */ Os_TraceId_CounterIsr_OsCounter,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: DMA_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_DMA_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_DMA_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_DMA_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: DSP_Clock_Monitor_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_DSP_Clock_Monitor_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_DSP_Clock_Monitor_Handler_Dyn,
  /* .Id   = */ Os_TraceId_DSP_Clock_Monitor_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet0_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet0_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet0_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet0_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet1_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet1_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet1_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet1_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet2_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet2_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet2_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet2_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet3_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet3_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet3_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet3_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet4_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet4_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet4_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet4_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet5_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet5_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet5_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet5_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet6_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet6_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet6_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet6_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Ethernet7_IRQ */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet7_IRQ =
{
  /* .Dyn  = */ &OsCfg_Trace_Ethernet7_IRQ_Dyn,
  /* .Id   = */ Os_TraceId_Ethernet7_IRQ,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: GPADC_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_GPADC_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_GPADC_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_GPADC_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: HSM_DMB_ISR */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_HSM_DMB_ISR =
{
  /* .Dyn  = */ &OsCfg_Trace_HSM_DMB_ISR_Dyn,
  /* .Id   = */ Os_TraceId_HSM_DMB_ISR,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: HSM_FUSA_ALARM_ISR */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_HSM_FUSA_ALARM_ISR =
{
  /* .Dyn  = */ &OsCfg_Trace_HSM_FUSA_ALARM_ISR_Dyn,
  /* .Id   = */ Os_TraceId_HSM_FUSA_ALARM_ISR,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: I2C_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2C_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_I2C_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_I2C_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_CHP_END_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_END_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_CHP_END_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_CHP_END_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_CHP_FUSA_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_FUSA_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_CHP_FUSA_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_CHP_FUSA_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_CHP_START_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_START_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_CHP_START_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_CHP_START_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_Clock_Monitor_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_Clock_Monitor_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_Clock_Monitor_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_Clock_Monitor_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_FRM_END_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_FRM_END_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_FRM_END_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_FRM_END_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MIPI_FRM_START_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_FRM_START_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MIPI_FRM_START_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MIPI_FRM_START_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MM_INTF0_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MM_INTF0_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_MM_INTF0_Handler_Dyn,
  /* .Id   = */ Os_TraceId_MM_INTF0_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: RA_Clock_Monitor_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_Clock_Monitor_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_RA_Clock_Monitor_Handler_Dyn,
  /* .Id   = */ Os_TraceId_RA_Clock_Monitor_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: RA_ERROR_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_ERROR_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_RA_ERROR_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_RA_ERROR_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: RA_FUSA_IRQ_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_FUSA_IRQ_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_RA_FUSA_IRQ_Handler_Dyn,
  /* .Id   = */ Os_TraceId_RA_FUSA_IRQ_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SNOC_Latent_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SNOC_Latent_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_SNOC_Latent_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_SNOC_Latent_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Serial_Clock_Monitor_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Serial_Clock_Monitor_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_Serial_Clock_Monitor_Handler_Dyn,
  /* .Id   = */ Os_TraceId_Serial_Clock_Monitor_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Sysmem0_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Sysmem0_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_Sysmem0_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_Sysmem0_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Sysmem1_Fusa_Handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Sysmem1_Fusa_Handler =
{
  /* .Dyn  = */ &OsCfg_Trace_Sysmem1_Fusa_Handler_Dyn,
  /* .Id   = */ Os_TraceId_Sysmem1_Fusa_Handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: TIMER1_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER1_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_TIMER1_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_TIMER1_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: TIMER2_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER2_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_TIMER2_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_TIMER2_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: TIMER3_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER3_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_TIMER3_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_TIMER3_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: TIMER4_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER4_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_TIMER4_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_TIMER4_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: TIMER5_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER5_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_TIMER5_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_TIMER5_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: WATCHDOG_Handler_Isr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WATCHDOG_Handler_Isr =
{
  /* .Dyn  = */ &OsCfg_Trace_WATCHDOG_Handler_Isr_Dyn,
  /* .Id   = */ Os_TraceId_WATCHDOG_Handler_Isr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: dsp_ctrl_err_fusa_irq_handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_dsp_ctrl_err_fusa_irq_handler =
{
  /* .Dyn  = */ &OsCfg_Trace_dsp_ctrl_err_fusa_irq_handler_Dyn,
  /* .Id   = */ Os_TraceId_dsp_ctrl_err_fusa_irq_handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: mipi_err_fusa_handler */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_mipi_err_fusa_handler =
{
  /* .Dyn  = */ &OsCfg_Trace_mipi_err_fusa_handler_Dyn,
  /* .Id   = */ Os_TraceId_mipi_err_fusa_handler,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: OsCore0_Hooks */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsCore0_Hooks =
{
  /* .Dyn  = */ &OsCfg_Trace_OsCore0_Hooks_Dyn,
  /* .Id   = */ Os_TraceId_OsCore0_Hooks,
  /* .Type = */ OS_TRACE_THREAD_TYPE_MISC
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
 *  END OF FILE: Os_Trace_Lcfg.c
 *********************************************************************************************************************/
