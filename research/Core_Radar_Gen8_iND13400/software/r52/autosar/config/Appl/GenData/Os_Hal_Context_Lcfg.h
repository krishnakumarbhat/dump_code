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
 *              File: Os_Hal_Context_Lcfg.h
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

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_LCFG_H
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


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

# define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
# include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: StartupHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartupHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic task context data: Appl_BackgroundTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_BackgroundTask_Dyn;


/*! HAL dynamic task context data: Appl_IPC_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_IPC_Task_Dyn;


/*! HAL dynamic task context data: Appl_Init */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Init_Dyn;


/*! HAL dynamic task context data: Appl_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Dyn;


/*! HAL dynamic task context data: Appl_Task_Communication */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Communication_Dyn;


/*! HAL dynamic task context data: Appl_Task_Fast */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Fast_Dyn;


/*! HAL dynamic task context data: Appl_Task_High_Prio */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_High_Prio_Dyn;


/*! HAL dynamic task context data: Appl_Task_Logging */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Appl_Task_Logging_Dyn;


/*! HAL dynamic task context data: BSW_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_Task_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;


/*! HAL dynamic task context data: Init_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Task_Dyn;


/*! HAL dynamic task context data: Init_Task_Qm */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Task_Qm_Dyn;


/*! HAL dynamic task context data: Radar_Ctrl_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Radar_Ctrl_Task_Dyn;


/*! HAL exception context data: OsCore0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

# define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
# include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0;

/*! HAL hook context configuration data: StartupHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartupHook_OsCore0;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0;

/*! HAL ISR2 context configuration data: AA0_FUSA_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AA0_FUSA_IRQ_Handler;

/*! HAL ISR2 context configuration data: AA1_FUSA_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AA1_FUSA_IRQ_Handler;

/*! HAL ISR2 context configuration data: ANOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ANOC_Latent_Fusa_Handler;

/*! HAL ISR2 context configuration data: Artie_Mem_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Artie_Mem_Fusa_Handler;

/*! HAL ISR2 context configuration data: BBE_SP_FUSA_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BBE_SP_FUSA_IRQ_Handler;

/*! HAL ISR2 context configuration data: BBE_SP_GPIO0_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BBE_SP_GPIO0_Handler;

/*! HAL ISR2 context configuration data: CANFD0_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CANFD0_Handler_Isr;

/*! HAL ISR2 context configuration data: CANFD1_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CANFD1_Handler_Isr;

/*! HAL ISR2 context configuration data: CMRT_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CMRT_ISR;

/*! HAL ISR2 context configuration data: CNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CNOC_Latent_Fusa_Handler;

/*! HAL ISR2 context configuration data: CRG_RMON_SWS_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CRG_RMON_SWS_IRQ_Handler;

/*! HAL ISR2 context configuration data: CounterIsr_OsCounter */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_OsCounter;

/*! HAL ISR2 context configuration data: DMA_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMA_Handler_Isr;

/*! HAL ISR2 context configuration data: DSP_Clock_Monitor_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DSP_Clock_Monitor_Handler;

/*! HAL ISR2 context configuration data: Ethernet0_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet0_IRQ;

/*! HAL ISR2 context configuration data: Ethernet1_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet1_IRQ;

/*! HAL ISR2 context configuration data: Ethernet2_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet2_IRQ;

/*! HAL ISR2 context configuration data: Ethernet3_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet3_IRQ;

/*! HAL ISR2 context configuration data: Ethernet4_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet4_IRQ;

/*! HAL ISR2 context configuration data: Ethernet5_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet5_IRQ;

/*! HAL ISR2 context configuration data: Ethernet6_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet6_IRQ;

/*! HAL ISR2 context configuration data: Ethernet7_IRQ */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ethernet7_IRQ;

/*! HAL ISR2 context configuration data: GPADC_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GPADC_Handler_Isr;

/*! HAL ISR2 context configuration data: HSM_DMB_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_HSM_DMB_ISR;

/*! HAL ISR2 context configuration data: HSM_FUSA_ALARM_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_HSM_FUSA_ALARM_ISR;

/*! HAL ISR2 context configuration data: I2C_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2C_Handler_Isr;

/*! HAL ISR2 context configuration data: MIPI_CHP_END_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_END_Handler;

/*! HAL ISR2 context configuration data: MIPI_CHP_FUSA_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_FUSA_Handler;

/*! HAL ISR2 context configuration data: MIPI_CHP_START_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_CHP_START_Handler;

/*! HAL ISR2 context configuration data: MIPI_Clock_Monitor_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_Clock_Monitor_Handler;

/*! HAL ISR2 context configuration data: MIPI_FRM_END_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_FRM_END_Handler;

/*! HAL ISR2 context configuration data: MIPI_FRM_START_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MIPI_FRM_START_Handler;

/*! HAL ISR2 context configuration data: MM_INTF0_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MM_INTF0_Handler;

/*! HAL ISR2 context configuration data: RA_Clock_Monitor_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_Clock_Monitor_Handler;

/*! HAL ISR2 context configuration data: RA_ERROR_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_ERROR_IRQ_Handler;

/*! HAL ISR2 context configuration data: RA_FUSA_IRQ_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_RA_FUSA_IRQ_Handler;

/*! HAL ISR2 context configuration data: SNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SNOC_Latent_Fusa_Handler;

/*! HAL ISR2 context configuration data: Serial_Clock_Monitor_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Serial_Clock_Monitor_Handler;

/*! HAL ISR2 context configuration data: Sysmem0_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Sysmem0_Fusa_Handler;

/*! HAL ISR2 context configuration data: Sysmem1_Fusa_Handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Sysmem1_Fusa_Handler;

/*! HAL ISR2 context configuration data: TIMER1_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER1_Handler_Isr;

/*! HAL ISR2 context configuration data: TIMER2_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER2_Handler_Isr;

/*! HAL ISR2 context configuration data: TIMER3_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER3_Handler_Isr;

/*! HAL ISR2 context configuration data: TIMER4_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER4_Handler_Isr;

/*! HAL ISR2 context configuration data: TIMER5_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TIMER5_Handler_Isr;

/*! HAL ISR2 context configuration data: WATCHDOG_Handler_Isr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WATCHDOG_Handler_Isr;

/*! HAL ISR2 context configuration data: dsp_ctrl_err_fusa_irq_handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_dsp_ctrl_err_fusa_irq_handler;

/*! HAL ISR2 context configuration data: mipi_err_fusa_handler */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_mipi_err_fusa_handler;

/*! HAL task context configuration data: Appl_BackgroundTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_BackgroundTask;

/*! HAL task context configuration data: Appl_IPC_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_IPC_Task;

/*! HAL task context configuration data: Appl_Init */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Init;

/*! HAL task context configuration data: Appl_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task;

/*! HAL task context configuration data: Appl_Task_Communication */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Communication;

/*! HAL task context configuration data: Appl_Task_Fast */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Fast;

/*! HAL task context configuration data: Appl_Task_High_Prio */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_High_Prio;

/*! HAL task context configuration data: Appl_Task_Logging */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Appl_Task_Logging;

/*! HAL task context configuration data: BSW_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_Task;

/*! HAL task context configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0;

/*! HAL task context configuration data: Init_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Task;

/*! HAL task context configuration data: Init_Task_Qm */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Task_Qm;

/*! HAL task context configuration data: Radar_Ctrl_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Radar_Ctrl_Task;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u];

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
