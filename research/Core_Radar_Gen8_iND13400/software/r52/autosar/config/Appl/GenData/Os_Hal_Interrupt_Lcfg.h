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
 *              File: Os_Hal_Interrupt_Lcfg.h
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

#ifndef OS_HAL_INTERRUPT_LCFG_H
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


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

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: AA0_FUSA_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AA0_FUSA_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_AA0_FUSA_IRQ_Handler;

/*! HAL ISR configuration data: AA1_FUSA_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AA1_FUSA_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_AA1_FUSA_IRQ_Handler;

/*! HAL ISR configuration data: ANOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ANOC_Latent_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ANOC_Latent_Fusa_Handler;

/*! HAL ISR configuration data: Artie_Mem_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Artie_Mem_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Artie_Mem_Fusa_Handler;

/*! HAL ISR configuration data: BBE_SP_FUSA_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_BBE_SP_FUSA_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_BBE_SP_FUSA_IRQ_Handler;

/*! HAL ISR configuration data: BBE_SP_GPIO0_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_BBE_SP_GPIO0_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_BBE_SP_GPIO0_Handler;

/*! HAL ISR configuration data: CANFD0_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CANFD0_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CANFD0_Handler_Isr;

/*! HAL ISR configuration data: CANFD1_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CANFD1_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CANFD1_Handler_Isr;

/*! HAL ISR configuration data: CMRT_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CMRT_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CMRT_ISR;

/*! HAL ISR configuration data: CNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CNOC_Latent_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CNOC_Latent_Fusa_Handler;

/*! HAL ISR configuration data: CRG_RMON_SWS_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CRG_RMON_SWS_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CRG_RMON_SWS_IRQ_Handler;

/*! HAL ISR configuration data: CounterIsr_OsCounter */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_OsCounter;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter;

/*! HAL ISR configuration data: DMA_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMA_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DMA_Handler_Isr;

/*! HAL ISR configuration data: DSP_Clock_Monitor_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DSP_Clock_Monitor_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DSP_Clock_Monitor_Handler;

/*! HAL ISR configuration data: DataAbort_Exception */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DataAbort_Exception;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DataAbort_Exception;

/*! HAL ISR configuration data: Ethernet0_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet0_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet0_IRQ;

/*! HAL ISR configuration data: Ethernet1_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet1_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet1_IRQ;

/*! HAL ISR configuration data: Ethernet2_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet2_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet2_IRQ;

/*! HAL ISR configuration data: Ethernet3_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet3_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet3_IRQ;

/*! HAL ISR configuration data: Ethernet4_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet4_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet4_IRQ;

/*! HAL ISR configuration data: Ethernet5_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet5_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet5_IRQ;

/*! HAL ISR configuration data: Ethernet6_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet6_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet6_IRQ;

/*! HAL ISR configuration data: Ethernet7_IRQ */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet7_IRQ;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet7_IRQ;

/*! HAL ISR configuration data: GPADC_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GPADC_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_GPADC_Handler_Isr;

/*! HAL ISR configuration data: HSM_DMB_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_HSM_DMB_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_HSM_DMB_ISR;

/*! HAL ISR configuration data: HSM_FUSA_ALARM_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_HSM_FUSA_ALARM_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_HSM_FUSA_ALARM_ISR;

/*! HAL ISR configuration data: I2C_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2C_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2C_Handler_Isr;

/*! HAL ISR configuration data: Illegal_Instruction_Exception */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Illegal_Instruction_Exception;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Illegal_Instruction_Exception;

/*! HAL ISR configuration data: MIPI_CHP_END_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_END_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_END_Handler;

/*! HAL ISR configuration data: MIPI_CHP_FUSA_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_FUSA_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_FUSA_Handler;

/*! HAL ISR configuration data: MIPI_CHP_START_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_START_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_START_Handler;

/*! HAL ISR configuration data: MIPI_Clock_Monitor_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_Clock_Monitor_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_Clock_Monitor_Handler;

/*! HAL ISR configuration data: MIPI_FRM_END_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_FRM_END_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_FRM_END_Handler;

/*! HAL ISR configuration data: MIPI_FRM_START_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_FRM_START_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_FRM_START_Handler;

/*! HAL ISR configuration data: MM_INTF0_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MM_INTF0_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MM_INTF0_Handler;

/*! HAL ISR configuration data: PrefetchAbort_Exception */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_PrefetchAbort_Exception;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_PrefetchAbort_Exception;

/*! HAL ISR configuration data: RA_Clock_Monitor_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_Clock_Monitor_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_Clock_Monitor_Handler;

/*! HAL ISR configuration data: RA_ERROR_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_ERROR_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_ERROR_IRQ_Handler;

/*! HAL ISR configuration data: RA_FUSA_IRQ_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_FUSA_IRQ_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_FUSA_IRQ_Handler;

/*! HAL ISR configuration data: SNOC_Latent_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SNOC_Latent_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SNOC_Latent_Fusa_Handler;

/*! HAL ISR configuration data: Serial_Clock_Monitor_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Serial_Clock_Monitor_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Serial_Clock_Monitor_Handler;

/*! HAL ISR configuration data: Sysmem0_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Sysmem0_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Sysmem0_Fusa_Handler;

/*! HAL ISR configuration data: Sysmem1_Fusa_Handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Sysmem1_Fusa_Handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Sysmem1_Fusa_Handler;

/*! HAL ISR configuration data: TIMER1_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER1_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER1_Handler_Isr;

/*! HAL ISR configuration data: TIMER2_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER2_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER2_Handler_Isr;

/*! HAL ISR configuration data: TIMER3_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER3_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER3_Handler_Isr;

/*! HAL ISR configuration data: TIMER4_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER4_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER4_Handler_Isr;

/*! HAL ISR configuration data: TIMER5_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER5_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER5_Handler_Isr;

/*! HAL ISR configuration data: WATCHDOG_Handler_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WATCHDOG_Handler_Isr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WATCHDOG_Handler_Isr;

/*! HAL ISR configuration data: dsp_ctrl_err_fusa_irq_handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_dsp_ctrl_err_fusa_irq_handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_dsp_ctrl_err_fusa_irq_handler;

/*! HAL ISR configuration data: mipi_err_fusa_handler */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_mipi_err_fusa_handler;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_mipi_err_fusa_handler;

/*! HAL interrupt resource level: OsResource */
extern CONST(Os_Hal_IntLevelType, OS_CONST) OsCfg_Hal_Resource_OsResource_IntLevel;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
