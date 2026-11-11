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
 *              File: Os_Hal_Interrupt_Lcfg.c
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
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

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

#define OS_START_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic interrupt send core information: AA0_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_AA0_FUSA_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: AA1_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_AA1_FUSA_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: ANOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_ANOC_Latent_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Artie_Mem_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Artie_Mem_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: BBE_SP_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_BBE_SP_FUSA_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: BBE_SP_GPIO0_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_BBE_SP_GPIO0_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CANFD0_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CANFD0_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CANFD1_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CANFD1_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CMRT_ISR */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CMRT_ISR_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CNOC_Latent_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CRG_RMON_SWS_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CRG_RMON_SWS_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CounterIsr_OsCounter */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CounterIsr_OsCounter_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: DMA_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_DMA_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: DSP_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_DSP_Clock_Monitor_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: DataAbort_Exception */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Cat1Isr_DataAbort_Exception_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet0_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet0_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet1_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet1_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet2_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet2_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet3_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet3_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet4_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet4_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet5_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet5_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet6_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet6_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Ethernet7_IRQ */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Ethernet7_IRQ_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: GPADC_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_GPADC_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: HSM_DMB_ISR */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_HSM_DMB_ISR_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: HSM_FUSA_ALARM_ISR */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_HSM_FUSA_ALARM_ISR_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: I2C_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_I2C_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Illegal_Instruction_Exception */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Cat1Isr_Illegal_Instruction_Exception_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_CHP_END_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_CHP_END_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_CHP_FUSA_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_CHP_FUSA_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_CHP_START_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_CHP_START_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_Clock_Monitor_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_FRM_END_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_FRM_END_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MIPI_FRM_START_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MIPI_FRM_START_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MM_INTF0_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MM_INTF0_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: PrefetchAbort_Exception */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Cat1Isr_PrefetchAbort_Exception_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: RA_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_RA_Clock_Monitor_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: RA_ERROR_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_RA_ERROR_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: RA_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_RA_FUSA_IRQ_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SNOC_Latent_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Serial_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Serial_Clock_Monitor_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Sysmem0_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Sysmem0_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Sysmem1_Fusa_Handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Sysmem1_Fusa_Handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: TIMER1_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_TIMER1_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: TIMER2_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_TIMER2_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: TIMER3_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_TIMER3_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: TIMER4_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_TIMER4_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: TIMER5_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_TIMER5_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: WATCHDOG_Handler_Isr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_WATCHDOG_Handler_Isr_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: dsp_ctrl_err_fusa_irq_handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_dsp_ctrl_err_fusa_irq_handler_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: mipi_err_fusa_handler */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_mipi_err_fusa_handler_SenderID_Dyn;

#define OS_STOP_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: AA0_FUSA_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AA0_FUSA_IRQ_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 88u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_AA0_FUSA_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_AA0_FUSA_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: AA1_FUSA_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AA1_FUSA_IRQ_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 89u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_AA1_FUSA_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_AA1_FUSA_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: ANOC_Latent_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ANOC_Latent_Fusa_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 124u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_ANOC_Latent_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ANOC_Latent_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Artie_Mem_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Artie_Mem_Fusa_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 66u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Artie_Mem_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Artie_Mem_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: BBE_SP_FUSA_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_BBE_SP_FUSA_IRQ_Handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 72u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_BBE_SP_FUSA_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_BBE_SP_FUSA_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: BBE_SP_GPIO0_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_BBE_SP_GPIO0_Handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 73u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_BBE_SP_GPIO0_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_BBE_SP_GPIO0_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CANFD0_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CANFD0_Handler_Isr =
{
  /* .Level                    = */ 6u,
  /* .Source                   = */ 32u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CANFD0_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CANFD0_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CANFD1_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CANFD1_Handler_Isr =
{
  /* .Level                    = */ 6u,
  /* .Source                   = */ 33u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CANFD1_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CANFD1_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CMRT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CMRT_ISR =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 57u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CMRT_ISR_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CMRT_ISR =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CNOC_Latent_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CNOC_Latent_Fusa_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 121u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CNOC_Latent_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CNOC_Latent_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CRG_RMON_SWS_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CRG_RMON_SWS_IRQ_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 148u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CRG_RMON_SWS_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CRG_RMON_SWS_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CounterIsr_OsCounter */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_OsCounter =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 30u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CounterIsr_OsCounter_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: DMA_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMA_Handler_Isr =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 65u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_DMA_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DMA_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: DSP_Clock_Monitor_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DSP_Clock_Monitor_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 140u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_DSP_Clock_Monitor_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DSP_Clock_Monitor_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: DataAbort_Exception */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DataAbort_Exception =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 4u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Cat1Isr_DataAbort_Exception_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_DataAbort_Exception =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet0_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet0_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 47u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet0_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet0_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet1_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet1_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 48u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet1_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet1_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet2_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet2_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 49u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet2_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet2_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet3_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet3_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 50u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet3_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet3_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet4_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet4_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 51u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet4_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet4_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet5_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet5_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 52u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet5_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet5_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet6_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet6_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 53u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet6_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet6_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Ethernet7_IRQ */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Ethernet7_IRQ =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 54u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Ethernet7_IRQ_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Ethernet7_IRQ =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: GPADC_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GPADC_Handler_Isr =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 67u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_GPADC_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_GPADC_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: HSM_DMB_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_HSM_DMB_ISR =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 130u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_HSM_DMB_ISR_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_HSM_DMB_ISR =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: HSM_FUSA_ALARM_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_HSM_FUSA_ALARM_ISR =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 117u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_HSM_FUSA_ALARM_ISR_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_HSM_FUSA_ALARM_ISR =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: I2C_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2C_Handler_Isr =
{
  /* .Level                    = */ 2u,
  /* .Source                   = */ 43u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_I2C_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2C_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Illegal_Instruction_Exception */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Illegal_Instruction_Exception =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 1u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Cat1Isr_Illegal_Instruction_Exception_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Illegal_Instruction_Exception =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_CHP_END_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_END_Handler =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 84u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_CHP_END_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_END_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_CHP_FUSA_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_FUSA_Handler =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 85u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_CHP_FUSA_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_FUSA_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_CHP_START_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_CHP_START_Handler =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 83u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_CHP_START_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_CHP_START_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_Clock_Monitor_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_Clock_Monitor_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 142u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_Clock_Monitor_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_Clock_Monitor_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_FRM_END_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_FRM_END_Handler =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 82u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_FRM_END_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_FRM_END_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MIPI_FRM_START_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MIPI_FRM_START_Handler =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 81u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MIPI_FRM_START_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MIPI_FRM_START_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MM_INTF0_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MM_INTF0_Handler =
{
  /* .Level                    = */ 9u,
  /* .Source                   = */ 90u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MM_INTF0_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MM_INTF0_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: PrefetchAbort_Exception */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_PrefetchAbort_Exception =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 3u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Cat1Isr_PrefetchAbort_Exception_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_PrefetchAbort_Exception =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: RA_Clock_Monitor_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_Clock_Monitor_Handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 141u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_RA_Clock_Monitor_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_Clock_Monitor_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: RA_ERROR_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_ERROR_IRQ_Handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 77u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_RA_ERROR_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_ERROR_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: RA_FUSA_IRQ_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_RA_FUSA_IRQ_Handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 78u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_RA_FUSA_IRQ_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_RA_FUSA_IRQ_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SNOC_Latent_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SNOC_Latent_Fusa_Handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 127u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SNOC_Latent_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_EDGE
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SNOC_Latent_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Serial_Clock_Monitor_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Serial_Clock_Monitor_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 143u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Serial_Clock_Monitor_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Serial_Clock_Monitor_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Sysmem0_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Sysmem0_Fusa_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 79u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Sysmem0_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Sysmem0_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Sysmem1_Fusa_Handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Sysmem1_Fusa_Handler =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 80u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Sysmem1_Fusa_Handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Sysmem1_Fusa_Handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: TIMER1_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER1_Handler_Isr =
{
  /* .Level                    = */ 5u,
  /* .Source                   = */ 44u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_TIMER1_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER1_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: TIMER2_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER2_Handler_Isr =
{
  /* .Level                    = */ 3u,
  /* .Source                   = */ 45u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_TIMER2_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER2_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: TIMER3_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER3_Handler_Isr =
{
  /* .Level                    = */ 6u,
  /* .Source                   = */ 46u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_TIMER3_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER3_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: TIMER4_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER4_Handler_Isr =
{
  /* .Level                    = */ 9u,
  /* .Source                   = */ 156u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_TIMER4_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER4_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: TIMER5_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TIMER5_Handler_Isr =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 157u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_TIMER5_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TIMER5_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: WATCHDOG_Handler_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WATCHDOG_Handler_Isr =
{
  /* .Level                    = */ 2u,
  /* .Source                   = */ 34u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_WATCHDOG_Handler_Isr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WATCHDOG_Handler_Isr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: dsp_ctrl_err_fusa_irq_handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_dsp_ctrl_err_fusa_irq_handler =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 108u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_dsp_ctrl_err_fusa_irq_handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_dsp_ctrl_err_fusa_irq_handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: mipi_err_fusa_handler */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_mipi_err_fusa_handler =
{
  /* .Level                    = */ 0u,
  /* .Source                   = */ 110u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_mipi_err_fusa_handler_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_mipi_err_fusa_handler =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL interrupt resource level: OsResource */
CONST(Os_Hal_IntLevelType, OS_CONST) OsCfg_Hal_Resource_OsResource_IntLevel = ((Os_Hal_IntLevelType)0)
;

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
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
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
