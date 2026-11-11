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
 *              File: Os_MemoryProtection_Lcfg.h
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

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_MEMORYPROTECTION_LCFG_H
# define OS_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsCore0_ASIL;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsCore_Qm;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_AA0_FUSA_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_AA1_FUSA_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ANOC_Latent_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Artie_Mem_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BBE_SP_FUSA_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BBE_SP_GPIO0_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CANFD0_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CANFD1_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CMRT_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CNOC_Latent_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CRG_RMON_SWS_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_OsCounter;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DMA_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DSP_Clock_Monitor_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet0_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet1_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet2_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet3_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet4_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet5_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet6_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Ethernet7_IRQ;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_GPADC_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_HSM_DMB_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_HSM_FUSA_ALARM_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2C_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_END_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_FUSA_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_CHP_START_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_Clock_Monitor_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_FRM_END_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MIPI_FRM_START_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MM_INTF0_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_Clock_Monitor_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_ERROR_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_RA_FUSA_IRQ_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SNOC_Latent_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Serial_Clock_Monitor_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Sysmem0_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Sysmem1_Fusa_Handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER1_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER2_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER3_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER4_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TIMER5_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WATCHDOG_Handler_Isr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_dsp_ctrl_err_fusa_irq_handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_mipi_err_fusa_handler;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_BackgroundTask;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_IPC_Task;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Init;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Communication;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Fast;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_High_Prio;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl_Task_Logging;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_Task;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Init_Task;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Init_Task_Qm;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Radar_Ctrl_Task;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu;

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
