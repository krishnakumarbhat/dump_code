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
 *              File: Os_Isr_Lcfg.c
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

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"
#include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic category 2 ISR data: AA0_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_AA0_FUSA_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: AA1_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_AA1_FUSA_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: ANOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ANOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: Artie_Mem_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Artie_Mem_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: BBE_SP_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: BBE_SP_GPIO0_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_BBE_SP_GPIO0_Handler_Dyn;

/*! Dynamic category 2 ISR data: CANFD0_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CANFD0_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: CANFD1_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CANFD1_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: CMRT_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CMRT_ISR_Dyn;

/*! Dynamic category 2 ISR data: CNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CNOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: CRG_RMON_SWS_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: CounterIsr_OsCounter */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_OsCounter_Dyn;

/*! Dynamic category 2 ISR data: DMA_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMA_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: DSP_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DSP_Clock_Monitor_Handler_Dyn;

/*! Dynamic category 2 ISR data: Ethernet0_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet0_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet1_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet1_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet2_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet2_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet3_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet3_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet4_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet4_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet5_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet5_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet6_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet6_IRQ_Dyn;

/*! Dynamic category 2 ISR data: Ethernet7_IRQ */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Ethernet7_IRQ_Dyn;

/*! Dynamic category 2 ISR data: GPADC_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GPADC_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: HSM_DMB_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_HSM_DMB_ISR_Dyn;

/*! Dynamic category 2 ISR data: HSM_FUSA_ALARM_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_HSM_FUSA_ALARM_ISR_Dyn;

/*! Dynamic category 2 ISR data: I2C_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_I2C_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: MIPI_CHP_END_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_CHP_END_Handler_Dyn;

/*! Dynamic category 2 ISR data: MIPI_CHP_FUSA_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_CHP_FUSA_Handler_Dyn;

/*! Dynamic category 2 ISR data: MIPI_CHP_START_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_CHP_START_Handler_Dyn;

/*! Dynamic category 2 ISR data: MIPI_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_Clock_Monitor_Handler_Dyn;

/*! Dynamic category 2 ISR data: MIPI_FRM_END_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_FRM_END_Handler_Dyn;

/*! Dynamic category 2 ISR data: MIPI_FRM_START_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MIPI_FRM_START_Handler_Dyn;

/*! Dynamic category 2 ISR data: MM_INTF0_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MM_INTF0_Handler_Dyn;

/*! Dynamic category 2 ISR data: RA_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_RA_Clock_Monitor_Handler_Dyn;

/*! Dynamic category 2 ISR data: RA_ERROR_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_RA_ERROR_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: RA_FUSA_IRQ_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_RA_FUSA_IRQ_Handler_Dyn;

/*! Dynamic category 2 ISR data: SNOC_Latent_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SNOC_Latent_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: Serial_Clock_Monitor_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Serial_Clock_Monitor_Handler_Dyn;

/*! Dynamic category 2 ISR data: Sysmem0_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Sysmem0_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: Sysmem1_Fusa_Handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Sysmem1_Fusa_Handler_Dyn;

/*! Dynamic category 2 ISR data: TIMER1_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TIMER1_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: TIMER2_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TIMER2_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: TIMER3_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TIMER3_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: TIMER4_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TIMER4_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: TIMER5_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TIMER5_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: WATCHDOG_Handler_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_WATCHDOG_Handler_Isr_Dyn;

/*! Dynamic category 2 ISR data: dsp_ctrl_err_fusa_irq_handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_Dyn;

/*! Dynamic category 2 ISR data: mipi_err_fusa_handler */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_mipi_err_fusa_handler_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: AA0_FUSA_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_AA0_FUSA_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_AA0_FUSA_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_AA0_FUSA_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_AA0_FUSA_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_AA0_FUSA_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_AA0_FUSA_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_AA0_FUSA_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_AA0_FUSA_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_AA0_FUSA_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ AA0_FUSA_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: AA1_FUSA_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_AA1_FUSA_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_AA1_FUSA_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_AA1_FUSA_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_AA1_FUSA_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_AA1_FUSA_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_AA1_FUSA_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_AA1_FUSA_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_AA1_FUSA_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_AA1_FUSA_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ AA1_FUSA_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ANOC_Latent_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ANOC_Latent_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ANOC_Latent_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ANOC_Latent_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ANOC_Latent_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ANOC_Latent_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ANOC_Latent_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ANOC_Latent_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ANOC_Latent_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ANOC_Latent_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ ANOC_Latent_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Artie_Mem_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Artie_Mem_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Artie_Mem_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Artie_Mem_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Artie_Mem_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Artie_Mem_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Artie_Mem_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Artie_Mem_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Artie_Mem_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Artie_Mem_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ Artie_Mem_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: BBE_SP_FUSA_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_BBE_SP_FUSA_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_BBE_SP_FUSA_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BBE_SP_FUSA_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_BBE_SP_FUSA_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BBE_SP_FUSA_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ BBE_SP_FUSA_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: BBE_SP_GPIO0_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_BBE_SP_GPIO0_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_BBE_SP_GPIO0_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_BBE_SP_GPIO0_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_BBE_SP_GPIO0_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BBE_SP_GPIO0_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_BBE_SP_GPIO0_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_BBE_SP_GPIO0_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BBE_SP_GPIO0_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_BBE_SP_GPIO0_Handler_HwConfig,
  /* .IsrId                     = */ BBE_SP_GPIO0_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CANFD0_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CANFD0_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CANFD0_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CANFD0_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CANFD0_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CANFD0_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CANFD0_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CANFD0_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CANFD0_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CANFD0_Handler_Isr_HwConfig,
  /* .IsrId                     = */ CANFD0_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CANFD1_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CANFD1_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CANFD1_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CANFD1_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CANFD1_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CANFD1_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CANFD1_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CANFD1_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CANFD1_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CANFD1_Handler_Isr_HwConfig,
  /* .IsrId                     = */ CANFD1_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CMRT_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CMRT_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CMRT_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CMRT_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CMRT_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CMRT_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CMRT_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CMRT_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CMRT_ISR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CMRT_ISR_HwConfig,
  /* .IsrId                     = */ CMRT_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CNOC_Latent_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CNOC_Latent_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CNOC_Latent_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CNOC_Latent_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CNOC_Latent_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CNOC_Latent_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CNOC_Latent_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CNOC_Latent_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CNOC_Latent_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CNOC_Latent_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ CNOC_Latent_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CRG_RMON_SWS_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CRG_RMON_SWS_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CRG_RMON_SWS_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CRG_RMON_SWS_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CRG_RMON_SWS_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CRG_RMON_SWS_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ CRG_RMON_SWS_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_OsCounter */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_OsCounter,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_OsCounter,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_OsCounter_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CounterIsr_OsCounter,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CounterIsr_OsCounter,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_OsCounter_HwConfig,
  /* .IsrId                     = */ CounterIsr_OsCounter,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter)
};
/*! ISR configuration data: DMA_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_DMA_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMA_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_DMA_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMA_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMA_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMA_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_DMA_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_DMA_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_DMA_Handler_Isr_HwConfig,
  /* .IsrId                     = */ DMA_Handler_Isr,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: DSP_Clock_Monitor_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_DSP_Clock_Monitor_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DSP_Clock_Monitor_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_DSP_Clock_Monitor_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DSP_Clock_Monitor_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DSP_Clock_Monitor_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DSP_Clock_Monitor_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_DSP_Clock_Monitor_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_DSP_Clock_Monitor_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_DSP_Clock_Monitor_Handler_HwConfig,
  /* .IsrId                     = */ DSP_Clock_Monitor_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DataAbort_Exception */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_DataAbort_Exception_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DataAbort_Exception,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_DataAbort_Exception,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_DataAbort_Exception =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_DataAbort_Exception_HwConfig,
};
/*! ISR configuration data: Ethernet0_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet0_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet0_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet0_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet0_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet0_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet0_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet0_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet0_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet0_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet0_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet1_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet1_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet1_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet1_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet1_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet1_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet1_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet1_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet1_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet1_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet1_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet2_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet2_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet2_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet2_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet2_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet2_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet2_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet2_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet2_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet2_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet2_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet3_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet3_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet3_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet3_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet3_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet3_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet3_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet3_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet3_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet3_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet3_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet4_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet4_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet4_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet4_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet4_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet4_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet4_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet4_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet4_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet4_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet4_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet5_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet5_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet5_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet5_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet5_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet5_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet5_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet5_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet5_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet5_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet5_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet6_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet6_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet6_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet6_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet6_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet6_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet6_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet6_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet6_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet6_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet6_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Ethernet7_IRQ */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Ethernet7_IRQ_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Ethernet7_IRQ,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Ethernet7_IRQ,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Ethernet7_IRQ =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Ethernet7_IRQ,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Ethernet7_IRQ_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Ethernet7_IRQ,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Ethernet7_IRQ,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Ethernet7_IRQ_HwConfig,
  /* .IsrId                     = */ Ethernet7_IRQ,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GPADC_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_GPADC_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GPADC_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_GPADC_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GPADC_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GPADC_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GPADC_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_GPADC_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_GPADC_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_GPADC_Handler_Isr_HwConfig,
  /* .IsrId                     = */ GPADC_Handler_Isr,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: HSM_DMB_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_HSM_DMB_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_HSM_DMB_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_HSM_DMB_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_HSM_DMB_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_HSM_DMB_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_HSM_DMB_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_HSM_DMB_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_HSM_DMB_ISR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_HSM_DMB_ISR_HwConfig,
  /* .IsrId                     = */ HSM_DMB_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: HSM_FUSA_ALARM_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_HSM_FUSA_ALARM_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_HSM_FUSA_ALARM_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_HSM_FUSA_ALARM_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_HSM_FUSA_ALARM_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_HSM_FUSA_ALARM_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_HSM_FUSA_ALARM_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_HSM_FUSA_ALARM_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_HSM_FUSA_ALARM_ISR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_HSM_FUSA_ALARM_ISR_HwConfig,
  /* .IsrId                     = */ HSM_FUSA_ALARM_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: I2C_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2C_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_I2C_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_I2C_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2C_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_I2C_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_I2C_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_I2C_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_I2C_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_I2C_Handler_Isr_HwConfig,
  /* .IsrId                     = */ I2C_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Illegal_Instruction_Exception */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_Illegal_Instruction_Exception_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Illegal_Instruction_Exception,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Illegal_Instruction_Exception,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_Illegal_Instruction_Exception =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_Illegal_Instruction_Exception_HwConfig,
};
/*! ISR configuration data: MIPI_CHP_END_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_END_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_CHP_END_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_CHP_END_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_END_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_CHP_END_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_CHP_END_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_CHP_END_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_CHP_END_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_CHP_END_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_CHP_END_Handler,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: MIPI_CHP_FUSA_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_FUSA_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_CHP_FUSA_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_CHP_FUSA_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_FUSA_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_CHP_FUSA_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_CHP_FUSA_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_CHP_FUSA_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_CHP_FUSA_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_CHP_FUSA_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_CHP_FUSA_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MIPI_CHP_START_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_START_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_CHP_START_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_CHP_START_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_CHP_START_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_CHP_START_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_CHP_START_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_CHP_START_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_CHP_START_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_CHP_START_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_CHP_START_Handler,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: MIPI_Clock_Monitor_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_Clock_Monitor_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_Clock_Monitor_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_Clock_Monitor_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_Clock_Monitor_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_Clock_Monitor_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_Clock_Monitor_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_Clock_Monitor_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_Clock_Monitor_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_Clock_Monitor_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_Clock_Monitor_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MIPI_FRM_END_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_END_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_FRM_END_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_FRM_END_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_END_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_FRM_END_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_FRM_END_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_FRM_END_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_FRM_END_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_FRM_END_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_FRM_END_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MIPI_FRM_START_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_START_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MIPI_FRM_START_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MIPI_FRM_START_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MIPI_FRM_START_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MIPI_FRM_START_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MIPI_FRM_START_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MIPI_FRM_START_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MIPI_FRM_START_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MIPI_FRM_START_Handler_HwConfig,
  /* .IsrId                     = */ MIPI_FRM_START_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MM_INTF0_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MM_INTF0_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MM_INTF0_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MM_INTF0_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MM_INTF0_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MM_INTF0_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MM_INTF0_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MM_INTF0_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MM_INTF0_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MM_INTF0_Handler_HwConfig,
  /* .IsrId                     = */ MM_INTF0_Handler,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: PrefetchAbort_Exception */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_PrefetchAbort_Exception_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_PrefetchAbort_Exception,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_PrefetchAbort_Exception,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_PrefetchAbort_Exception =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_PrefetchAbort_Exception_HwConfig,
};
/*! ISR configuration data: RA_Clock_Monitor_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_Clock_Monitor_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_RA_Clock_Monitor_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_RA_Clock_Monitor_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_Clock_Monitor_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_RA_Clock_Monitor_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_RA_Clock_Monitor_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_RA_Clock_Monitor_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_RA_Clock_Monitor_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_RA_Clock_Monitor_Handler_HwConfig,
  /* .IsrId                     = */ RA_Clock_Monitor_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: RA_ERROR_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_ERROR_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_RA_ERROR_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_RA_ERROR_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_ERROR_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_RA_ERROR_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_RA_ERROR_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_RA_ERROR_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_RA_ERROR_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_RA_ERROR_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ RA_ERROR_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: RA_FUSA_IRQ_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RA_FUSA_IRQ_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_RA_FUSA_IRQ_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_RA_FUSA_IRQ_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RA_FUSA_IRQ_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_RA_FUSA_IRQ_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_RA_FUSA_IRQ_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_RA_FUSA_IRQ_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_RA_FUSA_IRQ_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_RA_FUSA_IRQ_Handler_HwConfig,
  /* .IsrId                     = */ RA_FUSA_IRQ_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SNOC_Latent_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SNOC_Latent_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SNOC_Latent_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SNOC_Latent_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SNOC_Latent_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SNOC_Latent_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SNOC_Latent_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SNOC_Latent_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SNOC_Latent_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SNOC_Latent_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ SNOC_Latent_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Serial_Clock_Monitor_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Serial_Clock_Monitor_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Serial_Clock_Monitor_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Serial_Clock_Monitor_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Serial_Clock_Monitor_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Serial_Clock_Monitor_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Serial_Clock_Monitor_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Serial_Clock_Monitor_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Serial_Clock_Monitor_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Serial_Clock_Monitor_Handler_HwConfig,
  /* .IsrId                     = */ Serial_Clock_Monitor_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Sysmem0_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Sysmem0_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Sysmem0_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Sysmem0_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Sysmem0_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Sysmem0_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Sysmem0_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Sysmem0_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Sysmem0_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Sysmem0_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ Sysmem0_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Sysmem1_Fusa_Handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Sysmem1_Fusa_Handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Sysmem1_Fusa_Handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Sysmem1_Fusa_Handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Sysmem1_Fusa_Handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Sysmem1_Fusa_Handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Sysmem1_Fusa_Handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Sysmem1_Fusa_Handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Sysmem1_Fusa_Handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Sysmem1_Fusa_Handler_HwConfig,
  /* .IsrId                     = */ Sysmem1_Fusa_Handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TIMER1_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER1_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TIMER1_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TIMER1_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER1_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TIMER1_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TIMER1_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TIMER1_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_TIMER1_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TIMER1_Handler_Isr_HwConfig,
  /* .IsrId                     = */ TIMER1_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TIMER2_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER2_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TIMER2_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TIMER2_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER2_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TIMER2_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TIMER2_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TIMER2_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_TIMER2_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TIMER2_Handler_Isr_HwConfig,
  /* .IsrId                     = */ TIMER2_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TIMER3_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER3_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TIMER3_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TIMER3_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER3_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TIMER3_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TIMER3_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TIMER3_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_TIMER3_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TIMER3_Handler_Isr_HwConfig,
  /* .IsrId                     = */ TIMER3_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TIMER4_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER4_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TIMER4_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TIMER4_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER4_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TIMER4_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TIMER4_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TIMER4_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_TIMER4_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TIMER4_Handler_Isr_HwConfig,
  /* .IsrId                     = */ TIMER4_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TIMER5_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TIMER5_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TIMER5_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TIMER5_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TIMER5_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TIMER5_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TIMER5_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TIMER5_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_TIMER5_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TIMER5_Handler_Isr_HwConfig,
  /* .IsrId                     = */ TIMER5_Handler_Isr,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: WATCHDOG_Handler_Isr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WATCHDOG_Handler_Isr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_WATCHDOG_Handler_Isr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_WATCHDOG_Handler_Isr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WATCHDOG_Handler_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_WATCHDOG_Handler_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_WATCHDOG_Handler_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_WATCHDOG_Handler_Isr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_WATCHDOG_Handler_Isr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_WATCHDOG_Handler_Isr_HwConfig,
  /* .IsrId                     = */ WATCHDOG_Handler_Isr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: dsp_ctrl_err_fusa_irq_handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_dsp_ctrl_err_fusa_irq_handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_dsp_ctrl_err_fusa_irq_handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_dsp_ctrl_err_fusa_irq_handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_dsp_ctrl_err_fusa_irq_handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_dsp_ctrl_err_fusa_irq_handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler_HwConfig,
  /* .IsrId                     = */ dsp_ctrl_err_fusa_irq_handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: mipi_err_fusa_handler */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_mipi_err_fusa_handler_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_mipi_err_fusa_handler,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_mipi_err_fusa_handler,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_mipi_err_fusa_handler =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_mipi_err_fusa_handler,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_mipi_err_fusa_handler_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .SuspendIntCounters    = */ &OsCfg_Core_OsCore0_SuspendIntCounters_Dyn,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_mipi_err_fusa_handler,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_mipi_err_fusa_handler,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_mipi_err_fusa_handler_HwConfig,
  /* .IsrId                     = */ mipi_err_fusa_handler,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 and category 1P ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_AA0_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_AA1_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ANOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Artie_Mem_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_BBE_SP_GPIO0_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CANFD0_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CANFD1_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CMRT_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CNOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMA_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DSP_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet0_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet1_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet2_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet3_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet4_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet5_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet6_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Ethernet7_IRQ),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GPADC_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_HSM_DMB_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_HSM_FUSA_ALARM_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2C_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_END_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_FUSA_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_CHP_START_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_FRM_END_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MIPI_FRM_START_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MM_INTF0_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_ERROR_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RA_FUSA_IRQ_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SNOC_Latent_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Serial_Clock_Monitor_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Sysmem0_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Sysmem1_Fusa_Handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER1_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER2_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER3_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER4_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TIMER5_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WATCHDOG_Handler_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_mipi_err_fusa_handler),
  NULL_PTR
};

/*! Object reference table for timer category 1 ISRs used in INTERRUPT_ONLY use case. */
CONSTP2CONST(Os_IsrCat1ConfigType, OS_CONST, OS_CONST) OsCfg_TimerIsr1Refs[OS_TIMERISR1ID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
