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
 *              File: Os_Isr_Lcfg.h
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
#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: DataAbort_Exception */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_DataAbort_Exception_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_DataAbort_Exception;

/*! ISR configuration data: Illegal_Instruction_Exception */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_Illegal_Instruction_Exception_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_Illegal_Instruction_Exception;

/*! ISR configuration data: PrefetchAbort_Exception */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_PrefetchAbort_Exception_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_PrefetchAbort_Exception;

/*! ISR configuration data: AA0_FUSA_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_AA0_FUSA_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_AA0_FUSA_IRQ_Handler;

/*! ISR configuration data: AA1_FUSA_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_AA1_FUSA_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_AA1_FUSA_IRQ_Handler;

/*! ISR configuration data: ANOC_Latent_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ANOC_Latent_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ANOC_Latent_Fusa_Handler;

/*! ISR configuration data: Artie_Mem_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Artie_Mem_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Artie_Mem_Fusa_Handler;

/*! ISR configuration data: BBE_SP_FUSA_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler;

/*! ISR configuration data: BBE_SP_GPIO0_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_BBE_SP_GPIO0_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_BBE_SP_GPIO0_Handler;

/*! ISR configuration data: CANFD0_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CANFD0_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CANFD0_Handler_Isr;

/*! ISR configuration data: CANFD1_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CANFD1_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CANFD1_Handler_Isr;

/*! ISR configuration data: CMRT_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CMRT_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CMRT_ISR;

/*! ISR configuration data: CNOC_Latent_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CNOC_Latent_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CNOC_Latent_Fusa_Handler;

/*! ISR configuration data: CRG_RMON_SWS_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler;

/*! ISR configuration data: CounterIsr_OsCounter */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter;

/*! ISR configuration data: DMA_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_DMA_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMA_Handler_Isr;

/*! ISR configuration data: DSP_Clock_Monitor_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_DSP_Clock_Monitor_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DSP_Clock_Monitor_Handler;

/*! ISR configuration data: Ethernet0_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet0_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet0_IRQ;

/*! ISR configuration data: Ethernet1_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet1_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet1_IRQ;

/*! ISR configuration data: Ethernet2_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet2_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet2_IRQ;

/*! ISR configuration data: Ethernet3_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet3_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet3_IRQ;

/*! ISR configuration data: Ethernet4_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet4_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet4_IRQ;

/*! ISR configuration data: Ethernet5_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet5_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet5_IRQ;

/*! ISR configuration data: Ethernet6_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet6_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet6_IRQ;

/*! ISR configuration data: Ethernet7_IRQ */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet7_IRQ_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet7_IRQ;

/*! ISR configuration data: GPADC_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_GPADC_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GPADC_Handler_Isr;

/*! ISR configuration data: HSM_DMB_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_HSM_DMB_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_HSM_DMB_ISR;

/*! ISR configuration data: HSM_FUSA_ALARM_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_HSM_FUSA_ALARM_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_HSM_FUSA_ALARM_ISR;

/*! ISR configuration data: I2C_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2C_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2C_Handler_Isr;

/*! ISR configuration data: MIPI_CHP_END_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_END_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_END_Handler;

/*! ISR configuration data: MIPI_CHP_FUSA_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_FUSA_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_FUSA_Handler;

/*! ISR configuration data: MIPI_CHP_START_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_START_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_START_Handler;

/*! ISR configuration data: MIPI_Clock_Monitor_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_Clock_Monitor_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_Clock_Monitor_Handler;

/*! ISR configuration data: MIPI_FRM_END_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_END_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_END_Handler;

/*! ISR configuration data: MIPI_FRM_START_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_START_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_START_Handler;

/*! ISR configuration data: MM_INTF0_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MM_INTF0_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MM_INTF0_Handler;

/*! ISR configuration data: RA_Clock_Monitor_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_Clock_Monitor_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_Clock_Monitor_Handler;

/*! ISR configuration data: RA_ERROR_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_ERROR_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_ERROR_IRQ_Handler;

/*! ISR configuration data: RA_FUSA_IRQ_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_FUSA_IRQ_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_FUSA_IRQ_Handler;

/*! ISR configuration data: SNOC_Latent_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SNOC_Latent_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SNOC_Latent_Fusa_Handler;

/*! ISR configuration data: Serial_Clock_Monitor_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Serial_Clock_Monitor_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Serial_Clock_Monitor_Handler;

/*! ISR configuration data: Sysmem0_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Sysmem0_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Sysmem0_Fusa_Handler;

/*! ISR configuration data: Sysmem1_Fusa_Handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Sysmem1_Fusa_Handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Sysmem1_Fusa_Handler;

/*! ISR configuration data: TIMER1_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER1_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER1_Handler_Isr;

/*! ISR configuration data: TIMER2_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER2_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER2_Handler_Isr;

/*! ISR configuration data: TIMER3_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER3_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER3_Handler_Isr;

/*! ISR configuration data: TIMER4_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER4_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER4_Handler_Isr;

/*! ISR configuration data: TIMER5_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER5_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER5_Handler_Isr;

/*! ISR configuration data: WATCHDOG_Handler_Isr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WATCHDOG_Handler_Isr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WATCHDOG_Handler_Isr;

/*! ISR configuration data: dsp_ctrl_err_fusa_irq_handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler;

/*! ISR configuration data: mipi_err_fusa_handler */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_mipi_err_fusa_handler_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_mipi_err_fusa_handler;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 and category 1P ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for timer category 1 ISRs used in INTERRUPT_ONLY use case. */
extern CONSTP2CONST(Os_IsrCat1ConfigType, OS_CONST, OS_CONST) OsCfg_TimerIsr1Refs[OS_TIMERISR1ID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
