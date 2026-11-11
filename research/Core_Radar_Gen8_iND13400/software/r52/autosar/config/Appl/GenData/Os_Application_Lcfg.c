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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:11
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

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


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

/*! Dynamic application data: OsCore0_ASIL */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsCore0_ASIL_Dyn;

/*! Dynamic application data: OsCore_Qm */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsCore_Qm_Dyn;

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

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

/*! Object reference table for application alarms: OsCore0_ASIL */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_AlarmRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Appl_BackgroundTask_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_Communication_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Appl_IPC_Task_0_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Appl_Task_Communication_0_25ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Radar_Ctrl_Task_0_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Rtm_Rtm_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST),
  NULL_PTR
};

/*! Object reference table for application counters: OsCore0_ASIL */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_CounterRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsCore0_ASIL */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_HookRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsCore0_ASIL */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_IsrRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_ISRS + 1u] =
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

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsCore0_ASIL */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_Cat1IsrRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsCore0_ASIL */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_SchTRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsCore0_ASIL */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_TaskRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_BackgroundTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_IPC_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Communication),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_High_Prio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Radar_Ctrl_Task),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsCore0_ASIL */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsCore0_ASIL_ServiceRefs[OS_CFG_NUM_APP_OSCORE0_ASIL_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsCore0_ASIL */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsCore0_ASIL =
{
  /* .Dyn                      = */ &OsCfg_App_OsCore0_ASIL_Dyn,
  /* .Core                     = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId            = */ OS_APPID2MASK(OsCore0_ASIL),
  /* .SingleStack              = */ NULL_PTR,
  /* .TaskRefs                 = */ OsCfg_App_OsCore0_ASIL_TaskRefs,
  /* .TaskCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_TASKS,
  /* .IsrRefs                  = */ OsCfg_App_OsCore0_ASIL_IsrRefs,
  /* .IsrCount                 = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_ISRS,
  /* .IsrCat1Refs              = */ OsCfg_App_OsCore0_ASIL_Cat1IsrRefs,
  /* .IsrCat1Count             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_CAT1ISRS,
  /* .CounterRefs              = */ OsCfg_App_OsCore0_ASIL_CounterRefs,
  /* .CounterCount             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_COUNTERS,
  /* .AlarmRefs                = */ OsCfg_App_OsCore0_ASIL_AlarmRefs,
  /* .AlarmCount               = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_ALARMS,
  /* .SchTRefs                 = */ OsCfg_App_OsCore0_ASIL_SchTRefs,
  /* .SchTCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_SCHTS,
  /* .ServiceFunctions         = */ OsCfg_App_OsCore0_ASIL_ServiceRefs,
  /* .ServiceFunctionCount     = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_SERVICES,
  /* .StartupHookRef           = */ NULL_PTR,
  /* .ShutdownHookRef          = */ NULL_PTR,
  /* .ErrorHookRef             = */ NULL_PTR,
  /* .HookRefs                 = */ OsCfg_App_OsCore0_ASIL_HookRefs,
  /* .HookCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE0_ASIL_HOOKS,
  /* .TraceAppl                = */ &OsCfg_Trace_OsCore0_ASIL,
  /* .RestartTask              = */ NULL_PTR,
  /* .IsTrusted                = */ TRUE,
  /* .IsPrivileged             = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                       = */ OsCore0_ASIL
};

/*! Object reference table for application alarms: OsCore_Qm */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_AlarmRefs[OS_CFG_NUM_APP_OSCORE_QM_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms),
  NULL_PTR
};

/*! Object reference table for application counters: OsCore_Qm */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_CounterRefs[OS_CFG_NUM_APP_OSCORE_QM_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsCore_Qm */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_HookRefs[OS_CFG_NUM_APP_OSCORE_QM_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsCore_Qm */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_IsrRefs[OS_CFG_NUM_APP_OSCORE_QM_ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsCore_Qm */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_Cat1IsrRefs[OS_CFG_NUM_APP_OSCORE_QM_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsCore_Qm */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_SchTRefs[OS_CFG_NUM_APP_OSCORE_QM_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsCore_Qm */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_TaskRefs[OS_CFG_NUM_APP_OSCORE_QM_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Fast),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Appl_Task_Logging),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Task_Qm),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsCore_Qm */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsCore_Qm_ServiceRefs[OS_CFG_NUM_APP_OSCORE_QM_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsCore_Qm */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsCore_Qm =
{
  /* .Dyn                      = */ &OsCfg_App_OsCore_Qm_Dyn,
  /* .Core                     = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId            = */ OS_APPID2MASK(OsCore_Qm),
  /* .SingleStack              = */ NULL_PTR,
  /* .TaskRefs                 = */ OsCfg_App_OsCore_Qm_TaskRefs,
  /* .TaskCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_TASKS,
  /* .IsrRefs                  = */ OsCfg_App_OsCore_Qm_IsrRefs,
  /* .IsrCount                 = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_ISRS,
  /* .IsrCat1Refs              = */ OsCfg_App_OsCore_Qm_Cat1IsrRefs,
  /* .IsrCat1Count             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_CAT1ISRS,
  /* .CounterRefs              = */ OsCfg_App_OsCore_Qm_CounterRefs,
  /* .CounterCount             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_COUNTERS,
  /* .AlarmRefs                = */ OsCfg_App_OsCore_Qm_AlarmRefs,
  /* .AlarmCount               = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_ALARMS,
  /* .SchTRefs                 = */ OsCfg_App_OsCore_Qm_SchTRefs,
  /* .SchTCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_SCHTS,
  /* .ServiceFunctions         = */ OsCfg_App_OsCore_Qm_ServiceRefs,
  /* .ServiceFunctionCount     = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_SERVICES,
  /* .StartupHookRef           = */ NULL_PTR,
  /* .ShutdownHookRef          = */ NULL_PTR,
  /* .ErrorHookRef             = */ NULL_PTR,
  /* .HookRefs                 = */ OsCfg_App_OsCore_Qm_HookRefs,
  /* .HookCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSCORE_QM_HOOKS,
  /* .TraceAppl                = */ &OsCfg_Trace_OsCore_Qm,
  /* .RestartTask              = */ NULL_PTR,
  /* .IsTrusted                = */ TRUE,
  /* .IsPrivileged             = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                       = */ OsCore_Qm
};

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                      = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                     = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId            = */ OS_APPID2MASK(SystemApplication_OsCore0),
  /* .SingleStack              = */ NULL_PTR,
  /* .TaskRefs                 = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrRefs                  = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCount                 = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs              = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs              = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount             = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs                = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount               = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs                 = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions         = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount     = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef           = */ NULL_PTR,
  /* .ShutdownHookRef          = */ NULL_PTR,
  /* .ErrorHookRef             = */ NULL_PTR,
  /* .HookRefs                 = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount                = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .TraceAppl                = */ &OsCfg_Trace_SystemApplication_OsCore0,
  /* .RestartTask              = */ NULL_PTR,
  /* .IsTrusted                = */ TRUE,
  /* .IsPrivileged             = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                       = */ SystemApplication_OsCore0
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_OsCore0_ASIL,
  &OsCfg_App_OsCore_Qm,
  &OsCfg_App_SystemApplication_OsCore0,
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
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
