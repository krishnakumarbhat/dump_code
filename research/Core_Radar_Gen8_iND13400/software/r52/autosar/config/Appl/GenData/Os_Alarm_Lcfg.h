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
 *              File: Os_Alarm_Lcfg.h
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

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_ALARM_LCFG_H
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/*! Alarm configuration data: Rte_Al_TE2_Appl_BackgroundTask_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_BackgroundTask_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_Communication_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_Communication_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_High_Prio_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_Appl_Task_High_Prio_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Appl_Task_High_Prio_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_20ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_20ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_Task_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_Task_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_Appl_IPC_Task_0_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_IPC_Task_0_50ms;

/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_50ms;

/*! Alarm configuration data: Rte_Al_TE_Appl_Task_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_Appl_Task_Communication_0_25ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Appl_Task_Communication_0_25ms;

/*! Alarm configuration data: Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic;

/*! Alarm configuration data: Rte_Al_TE_Radar_Ctrl_Task_0_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Radar_Ctrl_Task_0_50ms;

/*! Alarm configuration data: Rte_Al_TE_Rtm_Rtm_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Rtm_Rtm_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms;

/*! Alarm configuration data: Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
