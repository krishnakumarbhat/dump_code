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
 *            Module: WdgM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg.h
 *   Generation Time: 2026-08-21 18:28:43
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
#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_MAJOR_VERSION (7u) 
#define WDGM_CFG_MINOR_VERSION (0u) 
#define WDGM_CFG_PATCH_VERSION (0u) 


/* Module specific general defines */ 
#ifndef WDGM_USE_DUMMY_STATEMENT
#define WDGM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT
#define WDGM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT_CONST
#define WDGM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef WDGM_ATOMIC_VARIABLE_ACCESS
#define WDGM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef WDGM_PROCESSOR_IND13400
#define WDGM_PROCESSOR_IND13400
#endif
#ifndef WDGM_COMP_LLVMDIAB
#define WDGM_COMP_LLVMDIAB
#endif
#ifndef WDGM_GEN_GENERATOR_MSR
#define WDGM_GEN_GENERATOR_MSR
#endif
#ifndef WDGM_CPUTYPE_BITORDER_LSB2MSB
#define WDGM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#define WDGM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_LINKTIME
#define WDGM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef WDGM_CONFIGURATION_VARIANT
#define WDGM_CONFIGURATION_VARIANT WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef WDGM_POSTBUILD_VARIANT_SUPPORT
#define WDGM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif
 

 
/* Module config related defines */ 
# define WDGM_NR_OF_CHECKPOINTS           (8u) 
# define WDGM_NR_OF_ENTITIES              (8u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (3u) 

/* Checkpoints for supervised entity 'SE_Internal_Wdg_Dummy' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Dummy (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg (0u) 
/* Checkpoints for supervised entity 'SE_Alive_Program_Flow_Monitoring' */ 
# define WdgMConf_WdgMCheckpoint_CP_Alive_Program_Flow_Monitoring (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg_Appl_IPC_Task' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_IPC_Task (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg_PLT_Appl_Task' */ 
# define WdgMConf_WdgMCheckpoint_SE_Internal_Wdg_PLT_Appl_Task (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg_Appl_Task_Communication' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Communication (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg_Appl_Task_Radar_Control' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Radar_Control (0u) 
/* Checkpoints for supervised entity 'SE_Internal_Wdg_BSW_Task' */ 
# define WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_BSW_Task (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Dummy (0u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg (1u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Alive_Program_Flow_Monitoring (2u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task (3u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task (4u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication (5u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control (6u) 
# define WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task (7u) 



#define WDGM_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Status reporting (WdgMStatusReportingMechanism) configured to WDGM_USE_MODE_SWITCH_PORTS
 */

#define WDGM_START_SEC_CALLOUT_CODE_ASIL_D
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
/* 
 * Local callback routines for mode switch ports of core 0 
 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_Dummy' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE1(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Alive_Program_Flow_Monitoring' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE2(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_Appl_IPC_Task' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE3(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_PLT_Appl_Task' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE4(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_Appl_Task_Communication' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE5(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_Appl_Task_Radar_Control' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE6(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'SE_Internal_Wdg_BSW_Task' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE7(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
 
/* 
 * Global callback routine for mode switch ports of core0 
 */ 
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 

#define WDGM_STOP_SEC_CALLOUT_CODE_ASIL_D
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 



#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

