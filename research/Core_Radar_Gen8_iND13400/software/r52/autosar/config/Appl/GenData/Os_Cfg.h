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
 *              File: Os_Cfg.h
 *   Generation Time: 2026-09-14 17:36:12
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
#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (4u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (10u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_ARM     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXR52_ASIMD     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_IND13400     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_LLVMDIAB     (STD_ON)

/*! Defines whether virtualization is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_VIRTUALIZATION                   (STD_OFF)


/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_ON)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_ON)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_ON)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_ON)

/*! Defines whether the interrupt only use case is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_INTERRUPT_ONLY                   (STD_OFF)

/*! Defines whether interrupt suspend API counters are writable in user mode (STD_ON) or not (STD_OFF). */
# define OS_CFG_INT_LOCK_OPTIMIZATION            (STD_OFF)

/*! Defines whether the single stack per application stack model is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SINGLE_STACK_PER_APPLICATION     (STD_OFF)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_Appl_BackgroundTask_0_5ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_5ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic2_BSW_Task_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_BSW_Task_0_20ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic2_BSW_Task_0_5ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_Appl_Task_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_Appl_Task_0_50ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_Appl_Task_0_5ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_Appl_Task_Communication_0_25ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_Appl_Task_Communication_0_50ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms     ((EventMaskType)1uLL)
# define Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic     ((EventMaskType)8uLL)
# define Rte_Ev_Run_Rtm_Rtm_MainFunction     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SWC_CDD_IPC_Dsp_sp_post_processing_complete     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms     ((EventMaskType)4uLL)
# define Rte_Ev_Run_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms     ((EventMaskType)1uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_HIL_RE_HIL_Periodic_Handler_Rp_HIL_Periodic_Handler_Trigger     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream     ((EventMaskType)4uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream     ((EventMaskType)64uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream     ((EventMaskType)128uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream     ((EventMaskType)256uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream     ((EventMaskType)512uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_2ms     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_50ms     ((EventMaskType)4uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_5ms     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms     ((EventMaskType)4uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Rp_Radar_Ctl_Look_Complete_Trigger     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SWC_PLT_CDD_TimeSync_DRE_StatusNotification_Callback     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event     ((EventMaskType)64uLL)
# define Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event     ((EventMaskType)128uLL)
# define Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event     ((EventMaskType)256uLL)
# define Rte_Ev_WP_Appl_Task_High_Prio     ((EventMaskType)2uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

