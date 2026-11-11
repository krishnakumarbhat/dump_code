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
 *              File: Os_Hal_Core_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:15
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

#define OS_HAL_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL variable used to save registers on exception entry: OsCore0 */
OS_LOCAL VAR(Os_Hal_ExcEntryRegSaveType, OS_VAR_NOINIT_FAST) OsCfg_Hal_ExcEntryRegSaveVar_OsCore0_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core stack protection symbol declarations */
extern uint8 _OS_CORE0_STACKS_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_CORE0_STACKS_LIMIT[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */



/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_FAST_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore0 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore0_Dyn;

#define OS_CORE0_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore0 */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Isr_CounterIsr_OsCounter_HwConfig,
  NULL_PTR
};


/*! HAL core configuration data: OsCore0 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0 =
{
  /* .CoreId  = */ 0, /* OsCore0 */
  /* .CoreStartAddress = */ (uint32)(&_start) /* PRQA S 0324 */ /* MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
}
;

/*! HAL AUTOSAR core configuration data: OsCore0 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore0 =
{
  /* .ExcEntryRegSaveVarRef     = */ &OsCfg_Hal_ExcEntryRegSaveVar_OsCore0_Dyn,
  /* .ExceptionTable            = */ (Os_Hal_ExceptionTableType)OsCfg_Hal_Core_OsCore0_ExceptionTable,
  /* .IrqVectorTable            = */ {NULL_PTR},
  /* .FiqVectorTable            = */ NULL_PTR,
  /* .StackProtectionStartLabel = */ (Os_AddressOfConstType)(&_OS_CORE0_STACKS_START),            /* PRQA S 0314 */ /* MD_Os_Hal_Dir1.1_0314 */
  /* .StackProtectionLimitLabel = */ (Os_AddressOfConstType)(&_OS_CORE0_STACKS_LIMIT)             /* PRQA S 0314 */ /* MD_Os_Hal_Dir1.1_0314 */

};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to thread configuration data. */
CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread =
{
  /* .Core2Thread = */
  {
    &OsCfg_Hal_Core2Thread_OsCore0_Dyn, /* OS_CORE_ID_0 */
  }
};

/*! HAL system configuration data. */
CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System =
{
  /* .Dummy = */ 0,
};

/*! Interrupt sources which are initialized by the hardware init core. */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Isr_AA0_FUSA_IRQ_Handler_HwConfig,
  &OsCfg_Isr_AA1_FUSA_IRQ_Handler_HwConfig,
  &OsCfg_Isr_ANOC_Latent_Fusa_Handler_HwConfig,
  &OsCfg_Isr_Artie_Mem_Fusa_Handler_HwConfig,
  &OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_HwConfig,
  &OsCfg_Isr_BBE_SP_GPIO0_Handler_HwConfig,
  &OsCfg_Isr_CANFD0_Handler_Isr_HwConfig,
  &OsCfg_Isr_CANFD1_Handler_Isr_HwConfig,
  &OsCfg_Isr_CMRT_ISR_HwConfig,
  &OsCfg_Isr_CNOC_Latent_Fusa_Handler_HwConfig,
  &OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_HwConfig,
  &OsCfg_Isr_DMA_Handler_Isr_HwConfig,
  &OsCfg_Isr_DSP_Clock_Monitor_Handler_HwConfig,
  &OsCfg_Isr_Ethernet0_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet1_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet2_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet3_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet4_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet5_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet6_IRQ_HwConfig,
  &OsCfg_Isr_Ethernet7_IRQ_HwConfig,
  &OsCfg_Isr_GPADC_Handler_Isr_HwConfig,
  &OsCfg_Isr_HSM_DMB_ISR_HwConfig,
  &OsCfg_Isr_HSM_FUSA_ALARM_ISR_HwConfig,
  &OsCfg_Isr_I2C_Handler_Isr_HwConfig,
  &OsCfg_Isr_MIPI_CHP_END_Handler_HwConfig,
  &OsCfg_Isr_MIPI_CHP_FUSA_Handler_HwConfig,
  &OsCfg_Isr_MIPI_CHP_START_Handler_HwConfig,
  &OsCfg_Isr_MIPI_Clock_Monitor_Handler_HwConfig,
  &OsCfg_Isr_MIPI_FRM_END_Handler_HwConfig,
  &OsCfg_Isr_MIPI_FRM_START_Handler_HwConfig,
  &OsCfg_Isr_MM_INTF0_Handler_HwConfig,
  &OsCfg_Isr_RA_Clock_Monitor_Handler_HwConfig,
  &OsCfg_Isr_RA_ERROR_IRQ_Handler_HwConfig,
  &OsCfg_Isr_RA_FUSA_IRQ_Handler_HwConfig,
  &OsCfg_Isr_SNOC_Latent_Fusa_Handler_HwConfig,
  &OsCfg_Isr_Serial_Clock_Monitor_Handler_HwConfig,
  &OsCfg_Isr_Sysmem0_Fusa_Handler_HwConfig,
  &OsCfg_Isr_Sysmem1_Fusa_Handler_HwConfig,
  &OsCfg_Isr_TIMER1_Handler_Isr_HwConfig,
  &OsCfg_Isr_TIMER2_Handler_Isr_HwConfig,
  &OsCfg_Isr_TIMER3_Handler_Isr_HwConfig,
  &OsCfg_Isr_TIMER4_Handler_Isr_HwConfig,
  &OsCfg_Isr_TIMER5_Handler_Isr_HwConfig,
  &OsCfg_Isr_WATCHDOG_Handler_Isr_HwConfig,
  &OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_HwConfig,
  &OsCfg_Isr_mipi_err_fusa_handler_HwConfig,
  NULL_PTR
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
 *  END OF FILE: Os_Hal_Core_Lcfg.c
 *********************************************************************************************************************/

