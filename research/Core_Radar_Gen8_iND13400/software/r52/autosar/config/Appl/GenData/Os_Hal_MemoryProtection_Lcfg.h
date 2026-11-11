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
 *              File: Os_Hal_MemoryProtection_Lcfg.h
 *   Generation Time: 2026-09-14 17:36:16
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

#ifndef OS_HAL_MEMORYPROTECTION_LCFG_H
# define OS_HAL_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtection_Types.h"

/* Os kernel module dependencies */

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

/* Start/end address label declarations */
extern uint8 _OS_CORE0_STACKS_LIMIT[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_CORE0_STACKS_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ARTIE_MEM_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ARTIE_MEM_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMA_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMA_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMA_NULL_GUARD_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMA_NULL_GUARD_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMBC_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __R52_TCMBC_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_DATA_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_DATA_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_QM_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_QM_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_SYSMEM_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM0_R52_SYSMEM_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM1_R52_DATA_BASE__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __SYSMEM1_R52_DATA_LIMIT__[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: OsCore0 */
extern CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0;

/*! HAL memory protection configuration data: OsCore0_ASIL */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0_ASIL;

/*! HAL memory protection configuration data: OsCore_Qm */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore_Qm;

/*! HAL memory protection configuration data: SystemApplication_OsCore0 */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0;

/*! HAL memory protection configuration data: AA0_FUSA_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_AA0_FUSA_IRQ_Handler;

/*! HAL memory protection configuration data: AA1_FUSA_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_AA1_FUSA_IRQ_Handler;

/*! HAL memory protection configuration data: ANOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ANOC_Latent_Fusa_Handler;

/*! HAL memory protection configuration data: Artie_Mem_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Artie_Mem_Fusa_Handler;

/*! HAL memory protection configuration data: BBE_SP_FUSA_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BBE_SP_FUSA_IRQ_Handler;

/*! HAL memory protection configuration data: BBE_SP_GPIO0_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BBE_SP_GPIO0_Handler;

/*! HAL memory protection configuration data: CANFD0_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CANFD0_Handler_Isr;

/*! HAL memory protection configuration data: CANFD1_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CANFD1_Handler_Isr;

/*! HAL memory protection configuration data: CMRT_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CMRT_ISR;

/*! HAL memory protection configuration data: CNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CNOC_Latent_Fusa_Handler;

/*! HAL memory protection configuration data: CRG_RMON_SWS_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CRG_RMON_SWS_IRQ_Handler;

/*! HAL memory protection configuration data: CounterIsr_OsCounter */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_OsCounter;

/*! HAL memory protection configuration data: DMA_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DMA_Handler_Isr;

/*! HAL memory protection configuration data: DSP_Clock_Monitor_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DSP_Clock_Monitor_Handler;

/*! HAL memory protection configuration data: Ethernet0_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet0_IRQ;

/*! HAL memory protection configuration data: Ethernet1_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet1_IRQ;

/*! HAL memory protection configuration data: Ethernet2_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet2_IRQ;

/*! HAL memory protection configuration data: Ethernet3_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet3_IRQ;

/*! HAL memory protection configuration data: Ethernet4_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet4_IRQ;

/*! HAL memory protection configuration data: Ethernet5_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet5_IRQ;

/*! HAL memory protection configuration data: Ethernet6_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet6_IRQ;

/*! HAL memory protection configuration data: Ethernet7_IRQ */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet7_IRQ;

/*! HAL memory protection configuration data: GPADC_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_GPADC_Handler_Isr;

/*! HAL memory protection configuration data: HSM_DMB_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_HSM_DMB_ISR;

/*! HAL memory protection configuration data: HSM_FUSA_ALARM_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_HSM_FUSA_ALARM_ISR;

/*! HAL memory protection configuration data: I2C_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_I2C_Handler_Isr;

/*! HAL memory protection configuration data: MIPI_CHP_END_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_END_Handler;

/*! HAL memory protection configuration data: MIPI_CHP_FUSA_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_FUSA_Handler;

/*! HAL memory protection configuration data: MIPI_CHP_START_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_START_Handler;

/*! HAL memory protection configuration data: MIPI_Clock_Monitor_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_Clock_Monitor_Handler;

/*! HAL memory protection configuration data: MIPI_FRM_END_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_FRM_END_Handler;

/*! HAL memory protection configuration data: MIPI_FRM_START_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_FRM_START_Handler;

/*! HAL memory protection configuration data: MM_INTF0_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MM_INTF0_Handler;

/*! HAL memory protection configuration data: RA_Clock_Monitor_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_Clock_Monitor_Handler;

/*! HAL memory protection configuration data: RA_ERROR_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_ERROR_IRQ_Handler;

/*! HAL memory protection configuration data: RA_FUSA_IRQ_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_FUSA_IRQ_Handler;

/*! HAL memory protection configuration data: SNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SNOC_Latent_Fusa_Handler;

/*! HAL memory protection configuration data: Serial_Clock_Monitor_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Serial_Clock_Monitor_Handler;

/*! HAL memory protection configuration data: Sysmem0_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Sysmem0_Fusa_Handler;

/*! HAL memory protection configuration data: Sysmem1_Fusa_Handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Sysmem1_Fusa_Handler;

/*! HAL memory protection configuration data: TIMER1_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER1_Handler_Isr;

/*! HAL memory protection configuration data: TIMER2_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER2_Handler_Isr;

/*! HAL memory protection configuration data: TIMER3_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER3_Handler_Isr;

/*! HAL memory protection configuration data: TIMER4_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER4_Handler_Isr;

/*! HAL memory protection configuration data: TIMER5_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER5_Handler_Isr;

/*! HAL memory protection configuration data: WATCHDOG_Handler_Isr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_WATCHDOG_Handler_Isr;

/*! HAL memory protection configuration data: dsp_ctrl_err_fusa_irq_handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_dsp_ctrl_err_fusa_irq_handler;

/*! HAL memory protection configuration data: mipi_err_fusa_handler */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_mipi_err_fusa_handler;

/*! HAL memory protection configuration data: Appl_BackgroundTask */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_BackgroundTask;

/*! HAL memory protection configuration data: Appl_IPC_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_IPC_Task;

/*! HAL memory protection configuration data: Appl_Init */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Init;

/*! HAL memory protection configuration data: Appl_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task;

/*! HAL memory protection configuration data: Appl_Task_Communication */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Communication;

/*! HAL memory protection configuration data: Appl_Task_Fast */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Fast;

/*! HAL memory protection configuration data: Appl_Task_High_Prio */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_High_Prio;

/*! HAL memory protection configuration data: Appl_Task_Logging */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Logging;

/*! HAL memory protection configuration data: BSW_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_Task;

/*! HAL memory protection configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore0;

/*! HAL memory protection configuration data: Init_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Init_Task;

/*! HAL memory protection configuration data: Init_Task_Qm */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Init_Task_Qm;

/*! HAL memory protection configuration data: Radar_Ctrl_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Radar_Ctrl_Task;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: SystemMpu */
extern CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu;

/*! HAL memory protection configuration data: EmptyThread */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread;

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
