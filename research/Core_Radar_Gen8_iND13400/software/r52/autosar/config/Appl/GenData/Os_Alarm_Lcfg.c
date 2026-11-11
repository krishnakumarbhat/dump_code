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
 *              File: Os_Alarm_Lcfg.c
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

#define OS_ALARM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
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

/*! Dynamic alarm data: Rte_Al_TE2_Appl_BackgroundTask_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Appl_BackgroundTask_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Appl_Task_Communication_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_Communication_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Appl_Task_High_Prio_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Appl_Task_High_Prio_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BSW_Task_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BSW_Task_0_20ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_20ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BSW_Task_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Appl_IPC_Task_0_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Appl_IPC_Task_0_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Appl_Task_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Appl_Task_0_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Appl_Task_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Appl_Task_Communication_0_25ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Appl_Task_Communication_0_25ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Radar_Ctrl_Task_0_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Radar_Ctrl_Task_0_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Rtm_Rtm_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Rtm_Rtm_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST_Dyn;

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


/*! Alarm configuration data: Rte_Al_TE2_Appl_BackgroundTask_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_BackgroundTask_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Appl_BackgroundTask_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_BackgroundTask,
  /* .Mask  = */ Rte_Ev_Cyclic2_Appl_BackgroundTask_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_Communication_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_Communication_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_Communication_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Communication,
  /* .Mask  = */ Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_High_Prio_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_High_Prio,
  /* .Mask  = */ Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_High_Prio_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_High_Prio,
  /* .Mask  = */ Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_BSW_Task,
  /* .Mask  = */ Rte_Ev_Cyclic2_BSW_Task_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_20ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_20ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_20ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_BSW_Task,
  /* .Mask  = */ Rte_Ev_Cyclic2_BSW_Task_0_20ms
};


/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_BSW_Task,
  /* .Mask  = */ Rte_Ev_Cyclic2_BSW_Task_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE_Appl_IPC_Task_0_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_IPC_Task_0_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Appl_IPC_Task_0_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_IPC_Task,
  /* .Mask  = */ Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms
};


/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task,
  /* .Mask  = */ Rte_Ev_Cyclic_Appl_Task_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task,
  /* .Mask  = */ Rte_Ev_Cyclic_Appl_Task_0_50ms
};


/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task,
  /* .Mask  = */ Rte_Ev_Cyclic_Appl_Task_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE_Appl_Task_Communication_0_25ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_Communication_0_25ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Appl_Task_Communication_0_25ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Communication,
  /* .Mask  = */ Rte_Ev_Cyclic_Appl_Task_Communication_0_25ms
};


/*! Alarm configuration data: Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Communication,
  /* .Mask  = */ Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic
};


/*! Alarm configuration data: Rte_Al_TE_Radar_Ctrl_Task_0_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Radar_Ctrl_Task_0_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Radar_Ctrl_Task_0_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Radar_Ctrl_Task,
  /* .Mask  = */ Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms
};


/*! Alarm configuration data: Rte_Al_TE_Rtm_Rtm_MainFunction */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Rtm_Rtm_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Rtm_Rtm_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Radar_Ctrl_Task,
  /* .Mask  = */ Rte_Ev_Run_Rtm_Rtm_MainFunction
};


/*! Alarm configuration data: Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_IPC_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Logging,
  /* .Mask  = */ Rte_Ev_Run_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Communication,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_High_Prio,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_BSW_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_High_Prio,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_BSW_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Fast,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_10ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Fast,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_2ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Fast,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_50ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(OsCore_Qm) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore_Qm
  },
  /* .Task  = */ &OsCfg_Task_Appl_Task_Fast,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_5ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Radar_Ctrl_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms
};


/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsCore0_ASIL) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsCore0_ASIL
  },
  /* .Task  = */ &OsCfg_Task_Radar_Ctrl_Task,
  /* .Mask  = */ Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
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
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST),
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
 *  END OF FILE: Os_Alarm_Lcfg.c
 *********************************************************************************************************************/
