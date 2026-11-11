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
 *              File: Os_Trace_Lcfg.h
 *   Generation Time: 2026-09-14 17:36:19
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
#ifndef OS_TRACE_LCFG_H
# define OS_TRACE_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trace_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */
# include "Rtm.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! \brief    Represents the identification of OS services for an external debugger supporting the
 *            OSEK Runtime Interface (ORTI) or AUTOSAR Runtime Interface (ARTI).
 *  \details  Start and end of a service are coded in the least significant bit according to the
 *            ORTI standard. Therefore, all IDs are even.
 *            We trace the service in a uint8. Therefore, at most 127 services are possible to
 *            trace currently.
 */
typedef enum
{
  OsOrtiApiIdGetApplicationID = 0x02u, /*!< GetApplicationID() */
  OsOrtiApiIdGetISRID = 0x04u, /*!< GetISRID() */
  OsOrtiApiIdCallTrustedFunction = 0x06u, /*!< CallTrustedFunction() */
  OsOrtiApiIdCheckISRMemoryAccess = 0x08u, /*!< CheckISRMemoryAccess() */
  OsOrtiApiIdCheckTaskMemoryAccess = 0x0Au, /*!< CheckTaskMemoryAccess() */
  OsOrtiApiIdCheckObjectAccess = 0x0Cu, /*!< CheckObjectAccess() */
  OsOrtiApiIdCheckObjectOwnership = 0x0Eu, /*!< CheckObjectOwnership() */
  OsOrtiApiIdStartScheduleTableRel = 0x10u, /*!< StartScheduleTableRel() */
  OsOrtiApiIdStartScheduleTableAbs = 0x12u, /*!< StartScheduleTableAbs() */
  OsOrtiApiIdStopScheduleTable = 0x14u, /*!< StopScheduleTable() */
  OsOrtiApiIdNextScheduleTable = 0x16u, /*!< NextScheduleTable() */
  OsOrtiApiIdStartScheduleTableSynchron = 0x18u, /*!< StartScheduleTableSynchron() */
  OsOrtiApiIdSyncScheduleTable = 0x1Au, /*!< SyncScheduleTable() */
  OsOrtiApiIdSetScheduleTableAsync = 0x1Cu, /*!< SetScheduleTableAsync() */
  OsOrtiApiIdGetScheduleTableStatus = 0x1Eu, /*!< GetScheduleTableStatus() */
  OsOrtiApiIdIncrementCounter = 0x20u, /*!< IncrementCounter() */
  OsOrtiApiIdGetCounterValue = 0x22u, /*!< GetCounterValue() */
  OsOrtiApiIdGetElapsedValue = 0x24u, /*!< GetElapsedValue() */
  OsOrtiApiIdTerminateApplication = 0x26u, /*!< TerminateApplication() */
  OsOrtiApiIdAllowAccess = 0x28u, /*!< AllowAccess() */
  OsOrtiApiIdGetApplicationState = 0x2Au, /*!< GetApplicationState() */
  OsOrtiApiIdGetNumberOfActivatedCores = 0x2Cu, /*!< GetNumberOfActivatedCores() */
  OsOrtiApiIdGetCoreID = 0x2Eu, /*!< GetCoreID() */
  OsOrtiApiIdStartCore = 0x30u, /*!< StartCore() */
  OsOrtiApiIdStartNonAutosarCore = 0x32u, /*!< StartNonAutosarCore() */
  OsOrtiApiIdGetSpinlock = 0x34u, /*!< GetSpinlock() */
  OsOrtiApiIdReleaseSpinlock = 0x36u, /*!< ReleaseSpinlock() */
  OsOrtiApiIdTryToGetSpinlock = 0x38u, /*!< TryToGetSpinlock() */
  OsOrtiApiIdShutdownAllCores = 0x3Au, /*!< ShutdownAllCores() */
  OsOrtiApiIdControlIdle = 0x3Cu, /*!< ControlIdle() */
  OsOrtiApiIdIocSend = 0x3Eu, /*!< IocSend() */
  OsOrtiApiIdIocWrite = 0x40u, /*!< IocWrite() */
  OsOrtiApiIdIocSendGroup = 0x42u, /*!< IocSendGroup() */
  OsOrtiApiIdIocWriteGroup = 0x44u, /*!< IocWriteGroup() */
  OsOrtiApiIdIocReceive = 0x46u, /*!< IocReceive() */
  OsOrtiApiIdIocRead = 0x48u, /*!< IocRead() */
  OsOrtiApiIdIocReceiveGroup = 0x4Au, /*!< IocReceiveGroup() */
  OsOrtiApiIdIocReadGroup = 0x4Cu, /*!< IocReadGroup() */
  OsOrtiApiIdIocEmptyQueue = 0x4Eu, /*!< IocEmptyQueue() */
  OsOrtiApiIdGetCurrentApplicationID = 0x50u, /*!< GetCurrentApplicationID() */
  OsOrtiApiIdCallNonTrustedFunction = 0x52u, /*!< CallNonTrustedFunction() */
  OsOrtiApiIdGetTaskStackUsage = 0x54u, /*!< Os_GetTaskStackUsage() */
  OsOrtiApiIdGetISRStackUsage = 0x56u, /*!< Os_GetISRStackUsage() */
  OsOrtiApiIdGetKernelStackUsage = 0x58u, /*!< Os_GetKernelStackUsage() */
  OsOrtiApiIdGetStartupHookStackUsage = 0x5Au, /*!< Os_GetStartupHookStackUsage() */
  OsOrtiApiIdGetErrorHookStackUsage = 0x5Cu, /*!< Os_GetErrorHookStackUsage() */
  OsOrtiApiIdGetShutdownHookStackUsage = 0x5Eu, /*!< Os_GetShutdownHookStackUsage() */
  OsOrtiApiIdGetProtectionHookStackUsage = 0x60u, /*!< Os_GetProtectionHookStackUsage() */
  OsOrtiApiIdGetSemaphore = 0x62u, /*!< GetSemaphore() */
  OsOrtiApiIdReleaseSemaphore = 0x64u, /*!< ReleaseSemaphore() */
  OsOrtiApiIdStartOS = 0x66u, /*!< StartOS() */
  OsOrtiApiIdGetActiveApplicationMode = 0x68u, /*!< GetActiveApplicationMode() */
  OsOrtiApiIdDisableAllInterrupts = 0x6Au, /*!< DisableAllInterrupts() */
  OsOrtiApiIdEnableAllInterrupts = 0x6Cu, /*!< EnableAllInterrupts() */
  OsOrtiApiIdSuspendAllInterrupts = 0x6Eu, /*!< SuspendAllInterrupts() */
  OsOrtiApiIdResumeAllInterrupts = 0x70u, /*!< ResumeAllInterrupts() */
  OsOrtiApiIdSuspendOSInterrupts = 0x72u, /*!< SuspendOSInterrupts() */
  OsOrtiApiIdResumeOSInterrupts = 0x74u, /*!< ResumeOSInterrupts() */
  OsOrtiApiIdActivateTask = 0x76u, /*!< ActivateTask() */
  OsOrtiApiIdTerminateTask = 0x78u, /*!< TerminateTask() */
  OsOrtiApiIdChainTask = 0x7Au, /*!< ChainTask() */
  OsOrtiApiIdGetTaskID = 0x7Cu, /*!< GetTaskID() */
  OsOrtiApiIdGetTaskState = 0x7Eu, /*!< GetTaskState() */
  OsOrtiApiIdSchedule = 0x80u, /*!< Schedule() */
  OsOrtiApiIdSetEvent = 0x82u, /*!< SetEvent() */
  OsOrtiApiIdClearEvent = 0x84u, /*!< ClearEvent() */
  OsOrtiApiIdGetEvent = 0x86u, /*!< GetEvent() */
  OsOrtiApiIdWaitEvent = 0x88u, /*!< WaitEvent() */
  OsOrtiApiIdGetAlarmBase = 0x8Au, /*!< GetAlarmBase() */
  OsOrtiApiIdGetAlarm = 0x8Cu, /*!< GetAlarm() */
  OsOrtiApiIdSetRelAlarm = 0x8Eu, /*!< SetRelAlarm() */
  OsOrtiApiIdSetAbsAlarm = 0x90u, /*!< SetAbsAlarm() */
  OsOrtiApiIdCancelAlarm = 0x92u, /*!< CancelAlarm() */
  OsOrtiApiIdGetResource = 0x94u, /*!< GetResource() */
  OsOrtiApiIdReleaseResource = 0x96u, /*!< ReleaseResource() */
  OsOrtiApiIdGetVersionInfo = 0x98u, /*!< GetVersionInfo() */
  OsOrtiApiIdEnterPreStartTask = 0x9Eu, /*!< EnterPreStartTask() */
  OsOrtiApiIdShutdownOS = 0xA0u, /*!< ShutdownOS() */
  OsOrtiApiIdGetUnhandledIrq = 0xA2u, /*!< GetUnhandledIrq() */
  OsOrtiApiIdGetUnhandledExc = 0xA4u, /*!< GetUnhandledExc() */
  OsOrtiApiIdDisableOSInterrupts = 0xA6u, /*!< DisableOSInterrupts() */
  OsOrtiApiIdEnableOSInterrupts = 0xA8u, /*!< EnableOSInterrupts() */
  OsOrtiApiIdReadPeripheral8 = 0xAAu, /*!< Os_ReadPeripheral8() */
  OsOrtiApiIdReadPeripheral16 = 0xACu, /*!< Os_ReadPeripheral16() */
  OsOrtiApiIdReadPeripheral32 = 0xAEu, /*!< Os_ReadPeripheral32() */
  OsOrtiApiIdWritePeripheral8 = 0xB0u, /*!< Os_WritePeripheral8() */
  OsOrtiApiIdWritePeripheral16 = 0xB2u, /*!< Os_WritePeripheral16() */
  OsOrtiApiIdWritePeripheral32 = 0xB4u, /*!< Os_WritePeripheral32() */
  OsOrtiApiIdModifyPeripheral8 = 0xB6u, /*!< Os_ModifyPeripheral8() */
  OsOrtiApiIdModifyPeripheral16 = 0xB8u, /*!< Os_ModifyPeripheral16() */
  OsOrtiApiIdModifyPeripheral32 = 0xBAu, /*!< Os_ModifyPeripheral32() */
  OsOrtiApiIdGetDetailedError = 0xBCu, /*!< GetDetailedError() */
  OsOrtiApiIdOSErrorGetServiceId = 0xBEu, /*!< OSErrorGetServiceId() */
  OsOrtiApiIdDisableInterruptSource = 0xC0u, /*!< Os_DisableInterruptSource() */
  OsOrtiApiIdEnableInterruptSource = 0xC2u, /*!< Os_EnableInterruptSource() */
  OsOrtiApiIdClearPendingInterrupt = 0xC4u, /*!< Os_ClearPendingInterrupt() */
  OsOrtiApiIdIsInterruptSourceEnabled = 0xC6u, /*!< Os_IsInterruptSourceEnabled() */
  OsOrtiApiIdIsInterruptPending = 0xC8u, /*!< Os_IsInterruptPending() */
  OsOrtiApiIdCallFastTrustedFunction = 0xCAu, /*!< Os_CallFastTrustedFunction() */
  OsOrtiApiIdBarrierSynchronize = 0xCCu, /*!< Os_BarrierSynchronize() */
  OsOrtiApiIdGetExceptionContext = 0xCEu, /*!< Os_GetExceptionContext() */
  OsOrtiApiIdSetExceptionContext = 0xD0u, /*!< Os_SetExceptionContext() */
  OsOrtiApiIdInitialEnableInterruptSources = 0xD2u, /*!< Os_InitialEnableInterruptSources() */
  OsOrtiApiIdGetCoreStartState = 0xD4u, /*!< Os_GetCoreStartState() */
  OsOrtiApiIdGetExceptionAddress = 0xD6u, /*!< Os_GetExceptionAddress() */
  OsOrtiApiIdGetNonTrustedFunctionStackUsage = 0xD8u, /*!< Os_GetNonTrustedFunctionStackUsage() */
  OsOrtiApiIdEnableInterruptsPreStart = 0xDAu, /*!< Os_EnableInterruptsPreStart() */
  OsOrtiApiIdGetInitHookStackUsage = 0xDCu, /*!< Os_GetInitHookStackUsage() */
  OsOrtiApiIdActivateTaskAsyn = 0xDEu, /*!< ActivateTaskAsyn() */
  OsOrtiApiIdSetEventAsyn = 0xE0u, /*!< SetEventAsyn() */
  OsOrtiApiIdSetDeferredPriorities = 0xE2u, /*!< Os_SetDeferredPriorities() */
  OsOrtiApiIdAddDeferredPriorities = 0xE4u, /*!< Os_AddDeferredPriorities() */
  OsOrtiApiIdRemoveDeferredPriorities = 0xE6u, /*!< Os_RemoveDeferredPriorities() */
  OsOrtiApiIdCallTrustedFunctionAsNonTrusted = 0xE8u /*!< Os_CallTrustedFunctionAsNonTrusted() */
} OsOrtiApiIdType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_VAR_CLEARED_PUBLIC_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic trace data: OsCore0 */
extern VAR(Os_TraceCoreType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Dyn;

# define OS_CORE0_STOP_SEC_VAR_CLEARED_PUBLIC_ASIL_D_LOCAL_UNSPECIFIED
# include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trace configuration data: OsCore0_ASIL */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsCore0_ASIL;

/*! Trace configuration data: OsCore_Qm */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsCore_Qm;

/*! Trace configuration data: SystemApplication_OsCore0 */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_SystemApplication_OsCore0;

/*! Trace configuration data: Appl_BackgroundTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_BackgroundTask;

/*! Trace configuration data: Appl_IPC_Task */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_IPC_Task;

/*! Trace configuration data: Appl_Init */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Init;

/*! Trace configuration data: Appl_Task */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task;

/*! Trace configuration data: Appl_Task_Communication */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Communication;

/*! Trace configuration data: Appl_Task_Fast */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Fast;

/*! Trace configuration data: Appl_Task_High_Prio */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_High_Prio;

/*! Trace configuration data: Appl_Task_Logging */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Appl_Task_Logging;

/*! Trace configuration data: BSW_Task */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BSW_Task;

/*! Trace configuration data: IdleTask_OsCore0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore0;

/*! Trace configuration data: Init_Task */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Init_Task;

/*! Trace configuration data: Init_Task_Qm */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Init_Task_Qm;

/*! Trace configuration data: Radar_Ctrl_Task */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Radar_Ctrl_Task;

/*! Trace configuration data: AA0_FUSA_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_AA0_FUSA_IRQ_Handler;

/*! Trace configuration data: AA1_FUSA_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_AA1_FUSA_IRQ_Handler;

/*! Trace configuration data: ANOC_Latent_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ANOC_Latent_Fusa_Handler;

/*! Trace configuration data: Artie_Mem_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Artie_Mem_Fusa_Handler;

/*! Trace configuration data: BBE_SP_FUSA_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BBE_SP_FUSA_IRQ_Handler;

/*! Trace configuration data: BBE_SP_GPIO0_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BBE_SP_GPIO0_Handler;

/*! Trace configuration data: CANFD0_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CANFD0_Handler_Isr;

/*! Trace configuration data: CANFD1_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CANFD1_Handler_Isr;

/*! Trace configuration data: CMRT_ISR */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CMRT_ISR;

/*! Trace configuration data: CNOC_Latent_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CNOC_Latent_Fusa_Handler;

/*! Trace configuration data: CRG_RMON_SWS_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CRG_RMON_SWS_IRQ_Handler;

/*! Trace configuration data: CounterIsr_OsCounter */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CounterIsr_OsCounter;

/*! Trace configuration data: DMA_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_DMA_Handler_Isr;

/*! Trace configuration data: DSP_Clock_Monitor_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_DSP_Clock_Monitor_Handler;

/*! Trace configuration data: Ethernet0_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet0_IRQ;

/*! Trace configuration data: Ethernet1_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet1_IRQ;

/*! Trace configuration data: Ethernet2_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet2_IRQ;

/*! Trace configuration data: Ethernet3_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet3_IRQ;

/*! Trace configuration data: Ethernet4_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet4_IRQ;

/*! Trace configuration data: Ethernet5_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet5_IRQ;

/*! Trace configuration data: Ethernet6_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet6_IRQ;

/*! Trace configuration data: Ethernet7_IRQ */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Ethernet7_IRQ;

/*! Trace configuration data: GPADC_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_GPADC_Handler_Isr;

/*! Trace configuration data: HSM_DMB_ISR */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_HSM_DMB_ISR;

/*! Trace configuration data: HSM_FUSA_ALARM_ISR */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_HSM_FUSA_ALARM_ISR;

/*! Trace configuration data: I2C_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2C_Handler_Isr;

/*! Trace configuration data: MIPI_CHP_END_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_END_Handler;

/*! Trace configuration data: MIPI_CHP_FUSA_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_FUSA_Handler;

/*! Trace configuration data: MIPI_CHP_START_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_CHP_START_Handler;

/*! Trace configuration data: MIPI_Clock_Monitor_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_Clock_Monitor_Handler;

/*! Trace configuration data: MIPI_FRM_END_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_FRM_END_Handler;

/*! Trace configuration data: MIPI_FRM_START_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MIPI_FRM_START_Handler;

/*! Trace configuration data: MM_INTF0_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MM_INTF0_Handler;

/*! Trace configuration data: RA_Clock_Monitor_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_Clock_Monitor_Handler;

/*! Trace configuration data: RA_ERROR_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_ERROR_IRQ_Handler;

/*! Trace configuration data: RA_FUSA_IRQ_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RA_FUSA_IRQ_Handler;

/*! Trace configuration data: SNOC_Latent_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SNOC_Latent_Fusa_Handler;

/*! Trace configuration data: Serial_Clock_Monitor_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Serial_Clock_Monitor_Handler;

/*! Trace configuration data: Sysmem0_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Sysmem0_Fusa_Handler;

/*! Trace configuration data: Sysmem1_Fusa_Handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Sysmem1_Fusa_Handler;

/*! Trace configuration data: TIMER1_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER1_Handler_Isr;

/*! Trace configuration data: TIMER2_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER2_Handler_Isr;

/*! Trace configuration data: TIMER3_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER3_Handler_Isr;

/*! Trace configuration data: TIMER4_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER4_Handler_Isr;

/*! Trace configuration data: TIMER5_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_TIMER5_Handler_Isr;

/*! Trace configuration data: WATCHDOG_Handler_Isr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WATCHDOG_Handler_Isr;

/*! Trace configuration data: dsp_ctrl_err_fusa_irq_handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_dsp_ctrl_err_fusa_irq_handler;

/*! Trace configuration data: mipi_err_fusa_handler */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_mipi_err_fusa_handler;

/*! Trace configuration data: OsCore0_Hooks */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsCore0_Hooks;

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TRACE_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Trace_Lcfg.h
 *********************************************************************************************************************/
