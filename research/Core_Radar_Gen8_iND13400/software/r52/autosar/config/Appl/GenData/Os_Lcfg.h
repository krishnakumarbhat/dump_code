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
 *              File: Os_Lcfg.h
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
#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE_Appl_BackgroundTask_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_BackgroundTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_BACKGROUNDTASK_CODE) Os_Task_Appl_BackgroundTask(void);

# define OS_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_IPC_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_IPC_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_IPC_TASK_CODE) Os_Task_Appl_IPC_Task(void);

# define OS_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Init_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Init()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_INIT_CODE) Os_Task_Appl_Init(void);

# define OS_STOP_SEC_CODE_Appl_Init_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_TASK_CODE) Os_Task_Appl_Task(void);

# define OS_STOP_SEC_CODE_Appl_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Task_Communication_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Task_Communication()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_TASK_COMMUNICATION_CODE) Os_Task_Appl_Task_Communication(void);

# define OS_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Task_Fast_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Task_Fast()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_TASK_FAST_CODE) Os_Task_Appl_Task_Fast(void);

# define OS_STOP_SEC_CODE_Appl_Task_Fast_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Task_High_Prio()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_TASK_HIGH_PRIO_CODE) Os_Task_Appl_Task_High_Prio(void);

# define OS_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Appl_Task_Logging_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Appl_Task_Logging()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPL_TASK_LOGGING_CODE) Os_Task_Appl_Task_Logging(void);

# define OS_STOP_SEC_CODE_Appl_Task_Logging_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_BSW_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BSW_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_BSW_TASK_CODE) Os_Task_BSW_Task(void);

# define OS_STOP_SEC_CODE_BSW_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Init_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_TASK_CODE) Os_Task_Init_Task(void);

# define OS_STOP_SEC_CODE_Init_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Init_Task_Qm_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Task_Qm()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_TASK_QM_CODE) Os_Task_Init_Task_Qm(void);

# define OS_STOP_SEC_CODE_Init_Task_Qm_QM
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Radar_Ctrl_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_RADAR_CTRL_TASK_CODE) Os_Task_Radar_Ctrl_Task(void);

# define OS_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_HSM0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  HSM0_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_HSM0_HANDLER_CODE) Os_Isr_HSM0_Handler(void);

# define OS_STOP_SEC_CODE_HSM0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET0_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET0_HANDLER_CODE) Os_Isr_ETHERNET0_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_RA_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RA_Clock_Monitor_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_RA_CLOCK_MONITOR_HANDLER_CODE) Os_Isr_RA_Clock_Monitor_Handler(void);

# define OS_STOP_SEC_CODE_RA_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_TIMER5_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TIMER5_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_TIMER5_HANDLER_CODE) Os_Isr_TIMER5_Handler(void);

# define OS_STOP_SEC_CODE_TIMER5_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_DMB_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMB_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMB_HANDLER_CODE) Os_Isr_DMB_Handler(void);

# define OS_STOP_SEC_CODE_DMB_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_CNOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CNOC_Latent_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_CNOC_LATENT_FUSA_HANDLER_CODE) Os_Isr_CNOC_Latent_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_CNOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Sysmem1_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Sysmem1_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_SYSMEM1_FUSA_HANDLER_CODE) Os_Isr_Sysmem1_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_Sysmem1_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ANOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ANOC_Latent_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ANOC_LATENT_FUSA_HANDLER_CODE) Os_Isr_ANOC_Latent_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_ANOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_HSM_ALARM_FUSA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  HSM_ALARM_FUSA_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_HSM_ALARM_FUSA_HANDLER_CODE) Os_Isr_HSM_ALARM_FUSA_Handler(void);

# define OS_STOP_SEC_CODE_HSM_ALARM_FUSA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_TIMER4_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TIMER4_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_TIMER4_HANDLER_CODE) Os_Isr_TIMER4_Handler(void);

# define OS_STOP_SEC_CODE_TIMER4_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET1_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET1_HANDLER_CODE) Os_Isr_ETHERNET1_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Sysmem0_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Sysmem0_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_SYSMEM0_FUSA_HANDLER_CODE) Os_Isr_Sysmem0_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_Sysmem0_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_MCDMA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCDMA_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCDMA_HANDLER_CODE) Os_Isr_MCDMA_Handler(void);

# define OS_STOP_SEC_CODE_MCDMA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_GPADC_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GPADC_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPADC_HANDLER_CODE) Os_Isr_GPADC_Handler(void);

# define OS_STOP_SEC_CODE_GPADC_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_CANFD1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CANFD1_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANFD1_HANDLER_CODE) Os_Isr_CANFD1_Handler(void);

# define OS_STOP_SEC_CODE_CANFD1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_I2CM_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  I2CM_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_I2CM_HANDLER_CODE) Os_Isr_I2CM_Handler(void);

# define OS_STOP_SEC_CODE_I2CM_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_AA1_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  AA1_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_AA1_FUSA_HANDLER_CODE) Os_Isr_AA1_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_AA1_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_MIPI_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MIPI_Clock_Monitor_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_CLOCK_MONITOR_HANDLER_CODE) Os_Isr_MIPI_Clock_Monitor_Handler(void);

# define OS_STOP_SEC_CODE_MIPI_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Serial_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Serial_Clock_Monitor_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_SERIAL_CLOCK_MONITOR_HANDLER_CODE) Os_Isr_Serial_Clock_Monitor_Handler(void);

# define OS_STOP_SEC_CODE_Serial_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_chp_fusa_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_chp_fusa_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_CHP_FUSA_HANDLER_CODE) Os_Isr_mipi_chp_fusa_handler(void);

# define OS_STOP_SEC_CODE_mipi_chp_fusa_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_chp_end_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_chp_end_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_CHP_END_HANDLER_CODE) Os_Isr_mipi_chp_end_handler(void);

# define OS_STOP_SEC_CODE_mipi_chp_end_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_SNOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SNOC_Latent_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_SNOC_LATENT_FUSA_HANDLER_CODE) Os_Isr_SNOC_Latent_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_SNOC_Latent_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_DSP_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DSP_Clock_Monitor_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_DSP_CLOCK_MONITOR_HANDLER_CODE) Os_Isr_DSP_Clock_Monitor_Handler(void);

# define OS_STOP_SEC_CODE_DSP_Clock_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_WATCHDOG_FUSA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WATCHDOG_FUSA_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_WATCHDOG_FUSA_HANDLER_CODE) Os_Isr_WATCHDOG_FUSA_Handler(void);

# define OS_STOP_SEC_CODE_WATCHDOG_FUSA_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Reset_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Reset_Monitor_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_RESET_MONITOR_HANDLER_CODE) Os_Isr_Reset_Monitor_Handler(void);

# define OS_STOP_SEC_CODE_Reset_Monitor_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mm_intf0_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mm_intf0_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MM_INTF0_HANDLER_CODE) Os_Isr_mm_intf0_handler(void);

# define OS_STOP_SEC_CODE_mm_intf0_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_AA0_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  AA0_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_AA0_FUSA_HANDLER_CODE) Os_Isr_AA0_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_AA0_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET6_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET6_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET6_HANDLER_CODE) Os_Isr_ETHERNET6_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET6_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_BBE_SP_FUSA_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BBE_SP_FUSA_IRQ_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_BBE_SP_FUSA_IRQ_HANDLER_CODE) Os_Isr_BBE_SP_FUSA_IRQ_Handler(void);

# define OS_STOP_SEC_CODE_BBE_SP_FUSA_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET7_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET7_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET7_HANDLER_CODE) Os_Isr_ETHERNET7_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET7_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_frm_start_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_frm_start_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_FRM_START_HANDLER_CODE) Os_Isr_mipi_frm_start_handler(void);

# define OS_STOP_SEC_CODE_mipi_frm_start_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET3_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET3_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET3_HANDLER_CODE) Os_Isr_ETHERNET3_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET3_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_RA_ERROR_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RA_ERROR_IRQ_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_RA_ERROR_IRQ_HANDLER_CODE) Os_Isr_RA_ERROR_IRQ_Handler(void);

# define OS_STOP_SEC_CODE_RA_ERROR_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_CANFD0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CANFD0_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANFD0_HANDLER_CODE) Os_Isr_CANFD0_Handler(void);

# define OS_STOP_SEC_CODE_CANFD0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_TIMER2_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TIMER2_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_TIMER2_HANDLER_CODE) Os_Isr_TIMER2_Handler(void);

# define OS_STOP_SEC_CODE_TIMER2_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_dsp_ctrl_err_fusa_irq_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  dsp_ctrl_err_fusa_irq_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_DSP_CTRL_ERR_FUSA_IRQ_HANDLER_CODE) Os_Isr_dsp_ctrl_err_fusa_irq_handler(void);

# define OS_STOP_SEC_CODE_dsp_ctrl_err_fusa_irq_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET2_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET2_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET2_HANDLER_CODE) Os_Isr_ETHERNET2_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET2_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_TIMER3_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TIMER3_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_TIMER3_HANDLER_CODE) Os_Isr_TIMER3_Handler(void);

# define OS_STOP_SEC_CODE_TIMER3_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET5_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET5_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET5_HANDLER_CODE) Os_Isr_ETHERNET5_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET5_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_chp_start_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_chp_start_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_CHP_START_HANDLER_CODE) Os_Isr_mipi_chp_start_handler(void);

# define OS_STOP_SEC_CODE_mipi_chp_start_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_TIMER1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TIMER1_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_TIMER1_HANDLER_CODE) Os_Isr_TIMER1_Handler(void);

# define OS_STOP_SEC_CODE_TIMER1_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_Artie_Mem_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Artie_Mem_Fusa_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ARTIE_MEM_FUSA_HANDLER_CODE) Os_Isr_Artie_Mem_Fusa_Handler(void);

# define OS_STOP_SEC_CODE_Artie_Mem_Fusa_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_frm_end_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_frm_end_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_FRM_END_HANDLER_CODE) Os_Isr_mipi_frm_end_handler(void);

# define OS_STOP_SEC_CODE_mipi_frm_end_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_BBE_SP_GPIO0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BBE_SP_GPIO0_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_BBE_SP_GPIO0_HANDLER_CODE) Os_Isr_BBE_SP_GPIO0_Handler(void);

# define OS_STOP_SEC_CODE_BBE_SP_GPIO0_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_mipi_err_fusa_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  mipi_err_fusa_handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_MIPI_ERR_FUSA_HANDLER_CODE) Os_Isr_mipi_err_fusa_handler(void);

# define OS_STOP_SEC_CODE_mipi_err_fusa_handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_ETHERNET4_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ETHERNET4_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_ETHERNET4_HANDLER_CODE) Os_Isr_ETHERNET4_Handler(void);

# define OS_STOP_SEC_CODE_ETHERNET4_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE_RA_FUSA_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RA_FUSA_IRQ_Handler()
 *********************************************************************************************************************/
extern FUNC(void, OS_RA_FUSA_IRQ_HANDLER_CODE) Os_Isr_RA_FUSA_IRQ_Handler(void);

# define OS_STOP_SEC_CODE_RA_FUSA_IRQ_Handler_ASIL_B
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
