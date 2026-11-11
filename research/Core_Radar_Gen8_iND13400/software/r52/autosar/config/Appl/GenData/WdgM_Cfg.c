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
 *              File: WdgM_Cfg.c
 *   Generation Time: 2026-08-21 19:08:57
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
#define WDGM_CFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WdgM.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGM_CFG_C_MAJOR_VERSION (7u) 
#define WDGM_CFG_C_MINOR_VERSION (0u) 
#define WDGM_CFG_C_PATCH_VERSION (0u) 


/* Check the version of WdgM_Cfg header file */
#if ( (WDGM_CFG_MAJOR_VERSION != WDGM_CFG_C_MAJOR_VERSION) \
   || (WDGM_CFG_MINOR_VERSION != WDGM_CFG_C_MINOR_VERSION) \
   || (WDGM_CFG_PATCH_VERSION != WDGM_CFG_C_PATCH_VERSION) )
# error "Version numbers of WdgM_Cfg.c and WdgM_Cfg.h are inconsistent!"
#endif

#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */
# define WDGM_LOCAL static
#endif

#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for global shared data */ 
WDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0; 
WDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES]; 
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_START_SEC_VAR_CLEARED_SE0CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_Dummy' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_0; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE0CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE1CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_1; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE1CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE1CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Internal_Wdg' in 'SE_Internal_Wdg' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_0; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE1CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE2CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Alive_Program_Flow_Monitoring' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_2; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE2CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE2CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Alive_Program_Flow_Monitoring' in 'SE_Alive_Program_Flow_Monitoring' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_1; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE2CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE3CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_Appl_IPC_Task' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_3; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE3CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE3CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_IPC_Task' in 'SE_Internal_Wdg_Appl_IPC_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_2; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE3CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE4CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_PLT_Appl_Task' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_4; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE4CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE4CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'SE_Internal_Wdg_PLT_Appl_Task' in 'SE_Internal_Wdg_PLT_Appl_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_3; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE4CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE5CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_Appl_Task_Communication' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_5; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE5CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE5CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_Task_Communication' in 'SE_Internal_Wdg_Appl_Task_Communication' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_4; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE5CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE6CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_Appl_Task_Radar_Control' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_6; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE6CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE6CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_Task_Radar_Control' in 'SE_Internal_Wdg_Appl_Task_Radar_Control' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_5; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE6CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE7CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'SE_Internal_Wdg_BSW_Task' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_7; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE7CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_START_SEC_VAR_CLEARED_SE7CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'CP_Internal_Wdg_BSW_Task' in 'SE_Internal_Wdg_BSW_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_6; 
#define WDGM_STOP_SEC_VAR_CLEARED_SE7CORE0_ASIL_D_LOCAL_32 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
 
#define WDGM_START_SEC_VAR_CLEARED_CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* Global Status for Supervised Entities */ 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_0; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_1; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_2; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_3; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_4; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_5; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_6; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_7; 
 
/* Global Alive Counters for checkpoint 'CP_Internal_Wdg' in supervised entity 'SE_Internal_Wdg' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_0; 
 
/* Global Alive Counters for checkpoint 'CP_Alive_Program_Flow_Monitoring' in supervised entity 'SE_Alive_Program_Flow_Monitoring' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_1; 
 
/* Global Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_IPC_Task' in supervised entity 'SE_Internal_Wdg_Appl_IPC_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_2; 
 
/* Global Alive Counters for checkpoint 'SE_Internal_Wdg_PLT_Appl_Task' in supervised entity 'SE_Internal_Wdg_PLT_Appl_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_3; 
 
/* Global Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_Task_Communication' in supervised entity 'SE_Internal_Wdg_Appl_Task_Communication' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_4; 
 
/* Global Alive Counters for checkpoint 'CP_Internal_Wdg_Appl_Task_Radar_Control' in supervised entity 'SE_Internal_Wdg_Appl_Task_Radar_Control' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_5; 
 
/* Global Alive Counters for checkpoint 'CP_Internal_Wdg_BSW_Task' in supervised entity 'SE_Internal_Wdg_BSW_Task' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_6; 
 
/* RAM section for Global Status */ 
WDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0; 
 
/* Global variables */ 
WDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0; 
 
#define WDGM_STOP_SEC_VAR_CLEARED_CORE0_ASIL_D_LOCAL_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



WDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =
{
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Dummy /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    10u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    10u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_0 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_0 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Alive_Program_Flow_Monitoring /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    3u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    30u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_1 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_1 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_IPC_Task /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    2u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    20u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_2 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_2 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMCheckpoint_SE_Internal_Wdg_PLT_Appl_Task /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    4u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    20u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_3 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_3 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Communication /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    4u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    20u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_4 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_4 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Radar_Control /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    2u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    20u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_5 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_5 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_BSW_Task /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    4u /*  WdgMExpectedAliveIndications  */ , 
    1u /*  WdgMMinMargin  */ , 
    1u /*  WdgMMaxMargin  */ , 
    20u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_6 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_6 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [7]  */ 
};


WDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =
{
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Dummy /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Dummy /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[0] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE0 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_0 /*  EntityStatusLRef  */ , 
    &EntityStatusG_0 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[1] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE1 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_1 /*  EntityStatusLRef  */ , 
    &EntityStatusG_1 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Alive_Program_Flow_Monitoring /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Alive_Program_Flow_Monitoring /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[2] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE2 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_2 /*  EntityStatusLRef  */ , 
    &EntityStatusG_2 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_IPC_Task /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_IPC_Task /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[3] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE3 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_3 /*  EntityStatusLRef  */ , 
    &EntityStatusG_3 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_PLT_Appl_Task /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_SE_Internal_Wdg_PLT_Appl_Task /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[4] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE4 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_4 /*  EntityStatusLRef  */ , 
    &EntityStatusG_4 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Communication /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Communication /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[5] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE5 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_5 /*  EntityStatusLRef  */ , 
    &EntityStatusG_5 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_Appl_Task_Radar_Control /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_Appl_Task_Radar_Control /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[6] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE6 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_6 /*  EntityStatusLRef  */ , 
    &EntityStatusG_6 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg_BSW_Task /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_CP_Internal_Wdg_BSW_Task /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[7] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_DEACTIVATED /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE7 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_7 /*  EntityStatusLRef  */ , 
    &EntityStatusG_7 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [7]  */ 
};


WDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] = 
{
  {
    500u /*   (condition value)  WdgMTriggerTimeout  */ , 
    100u /*  WdgMTicksPerSecond[Hz]=200 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_OFF_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 0  */ , 
  {
    4480u /*   (condition value)  WdgMTriggerTimeout  */ , 
    896u /*  WdgMTicksPerSecond[Hz]=200 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_SLOW_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 1  */ , 
  {
    105u /*   (condition value)  WdgMTriggerTimeout  */ , 
    21u /*  WdgMTicksPerSecond[Hz]=200 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_FAST_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 2  */ 
}; 
 
WDGM_LOCAL CONST(WdgM_WatchdogDeviceType, WDGM_CONST) WdgMWatchdogDevice0[WDGM_NR_OF_WATCHDOGS_CORE0] = 
{
  {
    &WdgMTriggerMode_core0[0] /*  WdgMTriggerModeRef  */ 
  } /*  [0]  */ 
}; 


WDGM_LOCAL CONST(WdgM_CallersType, WDGM_CONST) WdgMAllowedCallers[WDGM_NR_OF_ALLOWED_CALLERS] =
{
  {
    0u /*  WdgMAllowedCaller  */ 
  } /*  [0]  */ 
};


CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 = 
{
  7u /*  WdgMConfigMajorVersion  */ , 
  0u /*  WdgMConfigMinorVersion  */ , 
  0u /*  WdgMConfigId  */ , 
  1u /*  WdgMInitialTriggerModeId  */ , 
  0u /*  WdgMExpiredSupervisionCycleTol  */ , 
  WDGM_INVALID_SE_ID /*  WdgMGlobInitialEntityId  */ , 
  WDGM_INVALID_CP_ID /*  WdgMGlobInitialCheckpointId  */ , 
  WDGM_NR_OF_GLOBAL_TRANSITIONS /*  NrOfGlobalTransitions  */ , 
  NULL_PTR /*  WdgMGlobalTransitions  */ , 
  WDGM_NR_OF_WATCHDOGS_CORE0 /*  NrOfWatchdogDevices  */ , 
  WDGM_NR_OF_TRIGGER_MODES_CORE0 /*  NrOfTriggerModes  */ , 
  WdgMWatchdogDevice0 /*  WdgMWatchdogDeviceRef  */ , 
  WDGM_NR_OF_ALLOWED_CALLERS /*  NrOfAllowedCallers  */ , 
  WdgMAllowedCallers /*  WdgMCallersRef  */ , 
  WDGM_NR_OF_ENTITIES /*  NrOfSupervisedEntities  */ , 
  WdgMSupervisedEntity /*  WdgMSupervisedEntityRef  */ , 
  &StatusG_core0 /*  DataGRef  */ , 
  &StatusGS_core0 /*  DataGSRef  */ , 
  EntityGS /*  EntityGSRef  */ , 
  NULL_PTR /*  GlobalTransitionFlagsGSRef  */ , 
  WdgM_GlobalStatusChangeNotificationCore0 /*  WdgM_GlobalStatusChangeNotification  */ , 
  &GlobalVariables_core0 /*  WdgMGlobalVariables  */ , 
  0u /*  WdgMModeCoreAssignment  */ , 
  54u /*  WdgMConfigChecksum  */ 
}; 
 

#define WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.c
 *********************************************************************************************************************/

