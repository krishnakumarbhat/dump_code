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
 *              File: Os_Types_Lcfg.h
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
#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define OsCore0_ASIL OsCore0_ASIL
#define OsCore_Qm OsCore_Qm
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define Appl_BackgroundTask Appl_BackgroundTask
#define Appl_IPC_Task Appl_IPC_Task
#define Appl_Init Appl_Init
#define Appl_Task Appl_Task
#define Appl_Task_Communication Appl_Task_Communication
#define Appl_Task_Fast Appl_Task_Fast
#define Appl_Task_High_Prio Appl_Task_High_Prio
#define Appl_Task_Logging Appl_Task_Logging
#define BSW_Task BSW_Task
#define IdleTask_OsCore0 IdleTask_OsCore0
#define Init_Task Init_Task
#define Init_Task_Qm Init_Task_Qm
#define Radar_Ctrl_Task Radar_Ctrl_Task

/* Category 2 ISR identifiers. */
#define AA0_FUSA_IRQ_Handler AA0_FUSA_IRQ_Handler
#define AA1_FUSA_IRQ_Handler AA1_FUSA_IRQ_Handler
#define ANOC_Latent_Fusa_Handler ANOC_Latent_Fusa_Handler
#define Artie_Mem_Fusa_Handler Artie_Mem_Fusa_Handler
#define BBE_SP_FUSA_IRQ_Handler BBE_SP_FUSA_IRQ_Handler
#define BBE_SP_GPIO0_Handler BBE_SP_GPIO0_Handler
#define CANFD0_Handler_Isr CANFD0_Handler_Isr
#define CANFD1_Handler_Isr CANFD1_Handler_Isr
#define CMRT_ISR CMRT_ISR
#define CNOC_Latent_Fusa_Handler CNOC_Latent_Fusa_Handler
#define CRG_RMON_SWS_IRQ_Handler CRG_RMON_SWS_IRQ_Handler
#define CounterIsr_OsCounter CounterIsr_OsCounter
#define DMA_Handler_Isr DMA_Handler_Isr
#define DSP_Clock_Monitor_Handler DSP_Clock_Monitor_Handler
#define Ethernet0_IRQ Ethernet0_IRQ
#define Ethernet1_IRQ Ethernet1_IRQ
#define Ethernet2_IRQ Ethernet2_IRQ
#define Ethernet3_IRQ Ethernet3_IRQ
#define Ethernet4_IRQ Ethernet4_IRQ
#define Ethernet5_IRQ Ethernet5_IRQ
#define Ethernet6_IRQ Ethernet6_IRQ
#define Ethernet7_IRQ Ethernet7_IRQ
#define GPADC_Handler_Isr GPADC_Handler_Isr
#define HSM_DMB_ISR HSM_DMB_ISR
#define HSM_FUSA_ALARM_ISR HSM_FUSA_ALARM_ISR
#define I2C_Handler_Isr I2C_Handler_Isr
#define MIPI_CHP_END_Handler MIPI_CHP_END_Handler
#define MIPI_CHP_FUSA_Handler MIPI_CHP_FUSA_Handler
#define MIPI_CHP_START_Handler MIPI_CHP_START_Handler
#define MIPI_Clock_Monitor_Handler MIPI_Clock_Monitor_Handler
#define MIPI_FRM_END_Handler MIPI_FRM_END_Handler
#define MIPI_FRM_START_Handler MIPI_FRM_START_Handler
#define MM_INTF0_Handler MM_INTF0_Handler
#define RA_Clock_Monitor_Handler RA_Clock_Monitor_Handler
#define RA_ERROR_IRQ_Handler RA_ERROR_IRQ_Handler
#define RA_FUSA_IRQ_Handler RA_FUSA_IRQ_Handler
#define SNOC_Latent_Fusa_Handler SNOC_Latent_Fusa_Handler
#define Serial_Clock_Monitor_Handler Serial_Clock_Monitor_Handler
#define Sysmem0_Fusa_Handler Sysmem0_Fusa_Handler
#define Sysmem1_Fusa_Handler Sysmem1_Fusa_Handler
#define TIMER1_Handler_Isr TIMER1_Handler_Isr
#define TIMER2_Handler_Isr TIMER2_Handler_Isr
#define TIMER3_Handler_Isr TIMER3_Handler_Isr
#define TIMER4_Handler_Isr TIMER4_Handler_Isr
#define TIMER5_Handler_Isr TIMER5_Handler_Isr
#define WATCHDOG_Handler_Isr WATCHDOG_Handler_Isr
#define dsp_ctrl_err_fusa_irq_handler dsp_ctrl_err_fusa_irq_handler
#define mipi_err_fusa_handler mipi_err_fusa_handler

/* Category 1P ISR identifiers. */

/* Timer category 1 ISR identifiers (INTERRUPT_ONLY use case). */

/* Alarm identifiers. */
#define Rte_Al_TE2_Appl_BackgroundTask_0_5ms Rte_Al_TE2_Appl_BackgroundTask_0_5ms
#define Rte_Al_TE2_Appl_Task_Communication_0_10ms Rte_Al_TE2_Appl_Task_Communication_0_10ms
#define Rte_Al_TE2_Appl_Task_High_Prio_0_10ms Rte_Al_TE2_Appl_Task_High_Prio_0_10ms
#define Rte_Al_TE2_Appl_Task_High_Prio_0_5ms Rte_Al_TE2_Appl_Task_High_Prio_0_5ms
#define Rte_Al_TE2_BSW_Task_0_10ms Rte_Al_TE2_BSW_Task_0_10ms
#define Rte_Al_TE2_BSW_Task_0_20ms Rte_Al_TE2_BSW_Task_0_20ms
#define Rte_Al_TE2_BSW_Task_0_5ms Rte_Al_TE2_BSW_Task_0_5ms
#define Rte_Al_TE_Appl_IPC_Task_0_50ms Rte_Al_TE_Appl_IPC_Task_0_50ms
#define Rte_Al_TE_Appl_Task_0_10ms Rte_Al_TE_Appl_Task_0_10ms
#define Rte_Al_TE_Appl_Task_0_50ms Rte_Al_TE_Appl_Task_0_50ms
#define Rte_Al_TE_Appl_Task_0_5ms Rte_Al_TE_Appl_Task_0_5ms
#define Rte_Al_TE_Appl_Task_Communication_0_25ms Rte_Al_TE_Appl_Task_Communication_0_25ms
#define Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic
#define Rte_Al_TE_Radar_Ctrl_Task_0_50ms Rte_Al_TE_Radar_Ctrl_Task_0_50ms
#define Rte_Al_TE_Rtm_Rtm_MainFunction Rte_Al_TE_Rtm_Rtm_MainFunction
#define Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms
#define Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms
#define Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms
#define Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms
#define Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task
#define Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task
#define Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms
#define Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms
#define Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms
#define Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms
#define Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms
#define Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms
#define Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms
#define Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST

/* Counter identifiers. */
#define OsCounter OsCounter

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource OsResource

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
#define Os_TraceId_OsCore0_ASIL Os_TraceId_OsCore0_ASIL
#define Os_TraceId_OsCore_Qm Os_TraceId_OsCore_Qm
#define Os_TraceId_SystemApplication_OsCore0 Os_TraceId_SystemApplication_OsCore0

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */
#define Os_TraceId_Appl_BackgroundTask Os_TraceId_Appl_BackgroundTask
#define Os_TraceId_Appl_IPC_Task Os_TraceId_Appl_IPC_Task
#define Os_TraceId_Appl_Init Os_TraceId_Appl_Init
#define Os_TraceId_Appl_Task Os_TraceId_Appl_Task
#define Os_TraceId_Appl_Task_Communication Os_TraceId_Appl_Task_Communication
#define Os_TraceId_Appl_Task_Fast Os_TraceId_Appl_Task_Fast
#define Os_TraceId_Appl_Task_High_Prio Os_TraceId_Appl_Task_High_Prio
#define Os_TraceId_Appl_Task_Logging Os_TraceId_Appl_Task_Logging
#define Os_TraceId_BSW_Task Os_TraceId_BSW_Task
#define Os_TraceId_IdleTask_OsCore0 Os_TraceId_IdleTask_OsCore0
#define Os_TraceId_Init_Task Os_TraceId_Init_Task
#define Os_TraceId_Init_Task_Qm Os_TraceId_Init_Task_Qm
#define Os_TraceId_Radar_Ctrl_Task Os_TraceId_Radar_Ctrl_Task
#define Os_TraceId_AA0_FUSA_IRQ_Handler Os_TraceId_AA0_FUSA_IRQ_Handler
#define Os_TraceId_AA1_FUSA_IRQ_Handler Os_TraceId_AA1_FUSA_IRQ_Handler
#define Os_TraceId_ANOC_Latent_Fusa_Handler Os_TraceId_ANOC_Latent_Fusa_Handler
#define Os_TraceId_Artie_Mem_Fusa_Handler Os_TraceId_Artie_Mem_Fusa_Handler
#define Os_TraceId_BBE_SP_FUSA_IRQ_Handler Os_TraceId_BBE_SP_FUSA_IRQ_Handler
#define Os_TraceId_BBE_SP_GPIO0_Handler Os_TraceId_BBE_SP_GPIO0_Handler
#define Os_TraceId_CANFD0_Handler_Isr Os_TraceId_CANFD0_Handler_Isr
#define Os_TraceId_CANFD1_Handler_Isr Os_TraceId_CANFD1_Handler_Isr
#define Os_TraceId_CMRT_ISR Os_TraceId_CMRT_ISR
#define Os_TraceId_CNOC_Latent_Fusa_Handler Os_TraceId_CNOC_Latent_Fusa_Handler
#define Os_TraceId_CRG_RMON_SWS_IRQ_Handler Os_TraceId_CRG_RMON_SWS_IRQ_Handler
#define Os_TraceId_CounterIsr_OsCounter Os_TraceId_CounterIsr_OsCounter
#define Os_TraceId_DMA_Handler_Isr Os_TraceId_DMA_Handler_Isr
#define Os_TraceId_DSP_Clock_Monitor_Handler Os_TraceId_DSP_Clock_Monitor_Handler
#define Os_TraceId_Ethernet0_IRQ Os_TraceId_Ethernet0_IRQ
#define Os_TraceId_Ethernet1_IRQ Os_TraceId_Ethernet1_IRQ
#define Os_TraceId_Ethernet2_IRQ Os_TraceId_Ethernet2_IRQ
#define Os_TraceId_Ethernet3_IRQ Os_TraceId_Ethernet3_IRQ
#define Os_TraceId_Ethernet4_IRQ Os_TraceId_Ethernet4_IRQ
#define Os_TraceId_Ethernet5_IRQ Os_TraceId_Ethernet5_IRQ
#define Os_TraceId_Ethernet6_IRQ Os_TraceId_Ethernet6_IRQ
#define Os_TraceId_Ethernet7_IRQ Os_TraceId_Ethernet7_IRQ
#define Os_TraceId_GPADC_Handler_Isr Os_TraceId_GPADC_Handler_Isr
#define Os_TraceId_HSM_DMB_ISR Os_TraceId_HSM_DMB_ISR
#define Os_TraceId_HSM_FUSA_ALARM_ISR Os_TraceId_HSM_FUSA_ALARM_ISR
#define Os_TraceId_I2C_Handler_Isr Os_TraceId_I2C_Handler_Isr
#define Os_TraceId_MIPI_CHP_END_Handler Os_TraceId_MIPI_CHP_END_Handler
#define Os_TraceId_MIPI_CHP_FUSA_Handler Os_TraceId_MIPI_CHP_FUSA_Handler
#define Os_TraceId_MIPI_CHP_START_Handler Os_TraceId_MIPI_CHP_START_Handler
#define Os_TraceId_MIPI_Clock_Monitor_Handler Os_TraceId_MIPI_Clock_Monitor_Handler
#define Os_TraceId_MIPI_FRM_END_Handler Os_TraceId_MIPI_FRM_END_Handler
#define Os_TraceId_MIPI_FRM_START_Handler Os_TraceId_MIPI_FRM_START_Handler
#define Os_TraceId_MM_INTF0_Handler Os_TraceId_MM_INTF0_Handler
#define Os_TraceId_RA_Clock_Monitor_Handler Os_TraceId_RA_Clock_Monitor_Handler
#define Os_TraceId_RA_ERROR_IRQ_Handler Os_TraceId_RA_ERROR_IRQ_Handler
#define Os_TraceId_RA_FUSA_IRQ_Handler Os_TraceId_RA_FUSA_IRQ_Handler
#define Os_TraceId_SNOC_Latent_Fusa_Handler Os_TraceId_SNOC_Latent_Fusa_Handler
#define Os_TraceId_Serial_Clock_Monitor_Handler Os_TraceId_Serial_Clock_Monitor_Handler
#define Os_TraceId_Sysmem0_Fusa_Handler Os_TraceId_Sysmem0_Fusa_Handler
#define Os_TraceId_Sysmem1_Fusa_Handler Os_TraceId_Sysmem1_Fusa_Handler
#define Os_TraceId_TIMER1_Handler_Isr Os_TraceId_TIMER1_Handler_Isr
#define Os_TraceId_TIMER2_Handler_Isr Os_TraceId_TIMER2_Handler_Isr
#define Os_TraceId_TIMER3_Handler_Isr Os_TraceId_TIMER3_Handler_Isr
#define Os_TraceId_TIMER4_Handler_Isr Os_TraceId_TIMER4_Handler_Isr
#define Os_TraceId_TIMER5_Handler_Isr Os_TraceId_TIMER5_Handler_Isr
#define Os_TraceId_WATCHDOG_Handler_Isr Os_TraceId_WATCHDOG_Handler_Isr
#define Os_TraceId_dsp_ctrl_err_fusa_irq_handler Os_TraceId_dsp_ctrl_err_fusa_irq_handler
#define Os_TraceId_mipi_err_fusa_handler Os_TraceId_mipi_err_fusa_handler
#define Os_TraceId_OsCore0_Hooks Os_TraceId_OsCore0_Hooks

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/* Os_PrioritySet identifiers. */
#define Os_PrioritySet_Empty Os_PrioritySet_Empty

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  OsCore0_ASIL = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsCore_Qm = 1, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore0 = 2, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 3,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  Appl_BackgroundTask = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_IPC_Task = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Init = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Task = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Task_Communication = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Task_Fast = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Task_High_Prio = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Appl_Task_Logging = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BSW_Task = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Task = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Task_Qm = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Radar_Ctrl_Task = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 13,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 and category 1P ISR identifiers. */
typedef enum
{
  AA0_FUSA_IRQ_Handler = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  AA1_FUSA_IRQ_Handler = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ANOC_Latent_Fusa_Handler = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Artie_Mem_Fusa_Handler = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BBE_SP_FUSA_IRQ_Handler = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BBE_SP_GPIO0_Handler = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CANFD0_Handler_Isr = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CANFD1_Handler_Isr = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CMRT_ISR = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CNOC_Latent_Fusa_Handler = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CRG_RMON_SWS_IRQ_Handler = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_OsCounter = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMA_Handler_Isr = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DSP_Clock_Monitor_Handler = 13,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet0_IRQ = 14,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet1_IRQ = 15,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet2_IRQ = 16,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet3_IRQ = 17,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet4_IRQ = 18,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet5_IRQ = 19,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet6_IRQ = 20,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ethernet7_IRQ = 21,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GPADC_Handler_Isr = 22,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  HSM_DMB_ISR = 23,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  HSM_FUSA_ALARM_ISR = 24,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  I2C_Handler_Isr = 25,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_CHP_END_Handler = 26,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_CHP_FUSA_Handler = 27,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_CHP_START_Handler = 28,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_Clock_Monitor_Handler = 29,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_FRM_END_Handler = 30,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MIPI_FRM_START_Handler = 31,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MM_INTF0_Handler = 32,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RA_Clock_Monitor_Handler = 33,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RA_ERROR_IRQ_Handler = 34,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RA_FUSA_IRQ_Handler = 35,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SNOC_Latent_Fusa_Handler = 36,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Serial_Clock_Monitor_Handler = 37,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Sysmem0_Fusa_Handler = 38,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Sysmem1_Fusa_Handler = 39,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TIMER1_Handler_Isr = 40,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TIMER2_Handler_Isr = 41,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TIMER3_Handler_Isr = 42,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TIMER4_Handler_Isr = 43,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TIMER5_Handler_Isr = 44,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  WATCHDOG_Handler_Isr = 45,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  dsp_ctrl_err_fusa_irq_handler = 46,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  mipi_err_fusa_handler = 47,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 48,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Timer category 1 ISR identifiers used in INTERRUPT_ONLY use case. */
typedef enum
{
  OS_TIMERISR1ID_COUNT = 0
} TimerISR1Type;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_Appl_BackgroundTask_0_5ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Appl_Task_Communication_0_10ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Appl_Task_High_Prio_0_10ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Appl_Task_High_Prio_0_5ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_Task_0_10ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_Task_0_20ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_Task_0_5ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Appl_IPC_Task_0_50ms = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Appl_Task_0_10ms = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Appl_Task_0_50ms = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Appl_Task_0_5ms = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Appl_Task_Communication_0_25ms = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Radar_Ctrl_Task_0_50ms = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Rtm_Rtm_MainFunction = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms = 25,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms = 26,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms = 27,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST = 28,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 29
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  OsCounter = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
typedef enum
{
  Os_TraceId_OsCore0_ASIL = 0,
  Os_TraceId_OsCore_Qm = 1,
  Os_TraceId_SystemApplication_OsCore0 = 2,
  OS_TRACE_APPID_COUNT = 3,
  OS_TRACE_INVALID_APPLICATION = OS_TRACE_APPID_COUNT + 1
} Os_TraceAppIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  Os_TraceId_Appl_BackgroundTask = 0,
  Os_TraceId_Appl_IPC_Task = 1,
  Os_TraceId_Appl_Init = 2,
  Os_TraceId_Appl_Task = 3,
  Os_TraceId_Appl_Task_Communication = 4,
  Os_TraceId_Appl_Task_Fast = 5,
  Os_TraceId_Appl_Task_High_Prio = 6,
  Os_TraceId_Appl_Task_Logging = 7,
  Os_TraceId_BSW_Task = 8,
  Os_TraceId_IdleTask_OsCore0 = 9,
  Os_TraceId_Init_Task = 10,
  Os_TraceId_Init_Task_Qm = 11,
  Os_TraceId_Radar_Ctrl_Task = 12,
  Os_TraceId_AA0_FUSA_IRQ_Handler = 13,
  Os_TraceId_AA1_FUSA_IRQ_Handler = 14,
  Os_TraceId_ANOC_Latent_Fusa_Handler = 15,
  Os_TraceId_Artie_Mem_Fusa_Handler = 16,
  Os_TraceId_BBE_SP_FUSA_IRQ_Handler = 17,
  Os_TraceId_BBE_SP_GPIO0_Handler = 18,
  Os_TraceId_CANFD0_Handler_Isr = 19,
  Os_TraceId_CANFD1_Handler_Isr = 20,
  Os_TraceId_CMRT_ISR = 21,
  Os_TraceId_CNOC_Latent_Fusa_Handler = 22,
  Os_TraceId_CRG_RMON_SWS_IRQ_Handler = 23,
  Os_TraceId_CounterIsr_OsCounter = 24,
  Os_TraceId_DMA_Handler_Isr = 25,
  Os_TraceId_DSP_Clock_Monitor_Handler = 26,
  Os_TraceId_Ethernet0_IRQ = 27,
  Os_TraceId_Ethernet1_IRQ = 28,
  Os_TraceId_Ethernet2_IRQ = 29,
  Os_TraceId_Ethernet3_IRQ = 30,
  Os_TraceId_Ethernet4_IRQ = 31,
  Os_TraceId_Ethernet5_IRQ = 32,
  Os_TraceId_Ethernet6_IRQ = 33,
  Os_TraceId_Ethernet7_IRQ = 34,
  Os_TraceId_GPADC_Handler_Isr = 35,
  Os_TraceId_HSM_DMB_ISR = 36,
  Os_TraceId_HSM_FUSA_ALARM_ISR = 37,
  Os_TraceId_I2C_Handler_Isr = 38,
  Os_TraceId_MIPI_CHP_END_Handler = 39,
  Os_TraceId_MIPI_CHP_FUSA_Handler = 40,
  Os_TraceId_MIPI_CHP_START_Handler = 41,
  Os_TraceId_MIPI_Clock_Monitor_Handler = 42,
  Os_TraceId_MIPI_FRM_END_Handler = 43,
  Os_TraceId_MIPI_FRM_START_Handler = 44,
  Os_TraceId_MM_INTF0_Handler = 45,
  Os_TraceId_RA_Clock_Monitor_Handler = 46,
  Os_TraceId_RA_ERROR_IRQ_Handler = 47,
  Os_TraceId_RA_FUSA_IRQ_Handler = 48,
  Os_TraceId_SNOC_Latent_Fusa_Handler = 49,
  Os_TraceId_Serial_Clock_Monitor_Handler = 50,
  Os_TraceId_Sysmem0_Fusa_Handler = 51,
  Os_TraceId_Sysmem1_Fusa_Handler = 52,
  Os_TraceId_TIMER1_Handler_Isr = 53,
  Os_TraceId_TIMER2_Handler_Isr = 54,
  Os_TraceId_TIMER3_Handler_Isr = 55,
  Os_TraceId_TIMER4_Handler_Isr = 56,
  Os_TraceId_TIMER5_Handler_Isr = 57,
  Os_TraceId_WATCHDOG_Handler_Isr = 58,
  Os_TraceId_dsp_ctrl_err_fusa_irq_handler = 59,
  Os_TraceId_mipi_err_fusa_handler = 60,
  Os_TraceId_OsCore0_Hooks = 61,
  OS_TRACE_THREADID_COUNT = 62,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = 0,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/*! Os_PrioritySet identifiers */
typedef enum
{
  OS_PRIORITYSETID_COUNT = 0
} Os_PrioritySetIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
