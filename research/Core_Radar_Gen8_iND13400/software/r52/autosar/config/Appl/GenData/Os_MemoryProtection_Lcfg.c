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
 *              File: Os_MemoryProtection_Lcfg.c
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
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_MEMORYROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_MemoryProtection_Lcfg.h"


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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data: OsCore0 */
CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0 =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_OsCore0
};

/*! Memory protection configuration data: OsCore0_ASIL */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsCore0_ASIL =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: OsCore_Qm */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsCore_Qm =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore_Qm,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: SystemApplication_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: AA0_FUSA_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_AA0_FUSA_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_AA0_FUSA_IRQ_Handler
};

/*! Memory protection configuration data: AA1_FUSA_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_AA1_FUSA_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_AA1_FUSA_IRQ_Handler
};

/*! Memory protection configuration data: ANOC_Latent_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ANOC_Latent_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ANOC_Latent_Fusa_Handler
};

/*! Memory protection configuration data: Artie_Mem_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Artie_Mem_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Artie_Mem_Fusa_Handler
};

/*! Memory protection configuration data: BBE_SP_FUSA_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BBE_SP_FUSA_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BBE_SP_FUSA_IRQ_Handler
};

/*! Memory protection configuration data: BBE_SP_GPIO0_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BBE_SP_GPIO0_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BBE_SP_GPIO0_Handler
};

/*! Memory protection configuration data: CANFD0_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CANFD0_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CANFD0_Handler_Isr
};

/*! Memory protection configuration data: CANFD1_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CANFD1_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CANFD1_Handler_Isr
};

/*! Memory protection configuration data: CMRT_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CMRT_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CMRT_ISR
};

/*! Memory protection configuration data: CNOC_Latent_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CNOC_Latent_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CNOC_Latent_Fusa_Handler
};

/*! Memory protection configuration data: CRG_RMON_SWS_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CRG_RMON_SWS_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CRG_RMON_SWS_IRQ_Handler
};

/*! Memory protection configuration data: CounterIsr_OsCounter */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_OsCounter =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CounterIsr_OsCounter
};

/*! Memory protection configuration data: DMA_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DMA_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_DMA_Handler_Isr
};

/*! Memory protection configuration data: DSP_Clock_Monitor_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DSP_Clock_Monitor_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_DSP_Clock_Monitor_Handler
};

/*! Memory protection configuration data: Ethernet0_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet0_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet0_IRQ
};

/*! Memory protection configuration data: Ethernet1_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet1_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet1_IRQ
};

/*! Memory protection configuration data: Ethernet2_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet2_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet2_IRQ
};

/*! Memory protection configuration data: Ethernet3_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet3_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet3_IRQ
};

/*! Memory protection configuration data: Ethernet4_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet4_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet4_IRQ
};

/*! Memory protection configuration data: Ethernet5_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet5_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet5_IRQ
};

/*! Memory protection configuration data: Ethernet6_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet6_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet6_IRQ
};

/*! Memory protection configuration data: Ethernet7_IRQ */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet7_IRQ =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Ethernet7_IRQ
};

/*! Memory protection configuration data: GPADC_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_GPADC_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_GPADC_Handler_Isr
};

/*! Memory protection configuration data: HSM_DMB_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_HSM_DMB_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_HSM_DMB_ISR
};

/*! Memory protection configuration data: HSM_FUSA_ALARM_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_HSM_FUSA_ALARM_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_HSM_FUSA_ALARM_ISR
};

/*! Memory protection configuration data: I2C_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2C_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_I2C_Handler_Isr
};

/*! Memory protection configuration data: MIPI_CHP_END_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_END_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_CHP_END_Handler
};

/*! Memory protection configuration data: MIPI_CHP_FUSA_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_FUSA_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_CHP_FUSA_Handler
};

/*! Memory protection configuration data: MIPI_CHP_START_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_START_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_CHP_START_Handler
};

/*! Memory protection configuration data: MIPI_Clock_Monitor_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_Clock_Monitor_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_Clock_Monitor_Handler
};

/*! Memory protection configuration data: MIPI_FRM_END_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_FRM_END_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_FRM_END_Handler
};

/*! Memory protection configuration data: MIPI_FRM_START_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_FRM_START_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MIPI_FRM_START_Handler
};

/*! Memory protection configuration data: MM_INTF0_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MM_INTF0_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MM_INTF0_Handler
};

/*! Memory protection configuration data: RA_Clock_Monitor_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_Clock_Monitor_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_RA_Clock_Monitor_Handler
};

/*! Memory protection configuration data: RA_ERROR_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_ERROR_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_RA_ERROR_IRQ_Handler
};

/*! Memory protection configuration data: RA_FUSA_IRQ_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_FUSA_IRQ_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_RA_FUSA_IRQ_Handler
};

/*! Memory protection configuration data: SNOC_Latent_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SNOC_Latent_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SNOC_Latent_Fusa_Handler
};

/*! Memory protection configuration data: Serial_Clock_Monitor_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Serial_Clock_Monitor_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Serial_Clock_Monitor_Handler
};

/*! Memory protection configuration data: Sysmem0_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Sysmem0_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Sysmem0_Fusa_Handler
};

/*! Memory protection configuration data: Sysmem1_Fusa_Handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Sysmem1_Fusa_Handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Sysmem1_Fusa_Handler
};

/*! Memory protection configuration data: TIMER1_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER1_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TIMER1_Handler_Isr
};

/*! Memory protection configuration data: TIMER2_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER2_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TIMER2_Handler_Isr
};

/*! Memory protection configuration data: TIMER3_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER3_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TIMER3_Handler_Isr
};

/*! Memory protection configuration data: TIMER4_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER4_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TIMER4_Handler_Isr
};

/*! Memory protection configuration data: TIMER5_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER5_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TIMER5_Handler_Isr
};

/*! Memory protection configuration data: WATCHDOG_Handler_Isr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WATCHDOG_Handler_Isr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_WATCHDOG_Handler_Isr
};

/*! Memory protection configuration data: dsp_ctrl_err_fusa_irq_handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_dsp_ctrl_err_fusa_irq_handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_dsp_ctrl_err_fusa_irq_handler
};

/*! Memory protection configuration data: mipi_err_fusa_handler */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_mipi_err_fusa_handler =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_mipi_err_fusa_handler
};

/*! Memory protection configuration data: Appl_BackgroundTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_BackgroundTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_BackgroundTask
};

/*! Memory protection configuration data: Appl_IPC_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_IPC_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_IPC_Task
};

/*! Memory protection configuration data: Appl_Init */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Init =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Init
};

/*! Memory protection configuration data: Appl_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Task
};

/*! Memory protection configuration data: Appl_Task_Communication */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Communication =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Task_Communication
};

/*! Memory protection configuration data: Appl_Task_Fast */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Fast =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore_Qm,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Task_Fast
};

/*! Memory protection configuration data: Appl_Task_High_Prio */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_High_Prio =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Task_High_Prio
};

/*! Memory protection configuration data: Appl_Task_Logging */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Logging =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore_Qm,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Appl_Task_Logging
};

/*! Memory protection configuration data: BSW_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BSW_Task
};

/*! Memory protection configuration data: IdleTask_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IdleTask_OsCore0
};

/*! Memory protection configuration data: Init_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Init_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Init_Task
};

/*! Memory protection configuration data: Init_Task_Qm */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Init_Task_Qm =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore_Qm,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Init_Task_Qm
};

/*! Memory protection configuration data: Radar_Ctrl_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Radar_Ctrl_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsCore0_ASIL,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Radar_Ctrl_Task
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data: SystemMpu */
CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_SystemMpu
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
 *  END OF FILE: Os_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
