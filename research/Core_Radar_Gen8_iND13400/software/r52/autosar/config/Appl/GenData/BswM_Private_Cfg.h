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
 *            Module: BswM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Private_Cfg.h
 *   Generation Time: 2026-09-21 09:16:51
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#if !defined(BSWM_PRIVATE_CFG_H)
#define BSWM_PRIVATE_CFG_H


/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
#include "BswM_Cfg.h"
#include "Com.h" 
#include "Rte_BswM.h" 
#include "EcuM_Init_PBcfg.h" 
#include "EcuM.h" 
#include "EthIf.h" 
#include "SoAd.h" 
#include "PduR.h" 
#include "EthSM.h" 
#include "TcpIp.h" 
#include "ComM.h" 
#include "Rte_Main.h" 
#include "CanIf.h" 
#include "CanSM_EcuM.h" 
#include "TcpIpXcp.h" 
#include "Xcp.h" 
#include "StbM.h" 
#include "EthTSyn.h" 
#include "Can.h" 
#include "Fee_30_FlexNor.h" 
#include "NvM.h" 
#include "Sd.h" 
#include "LdCom.h" 
#include "SomeIpTp.h" 
#include "CanXcp.h" 
#include "CanTSyn.h" 
#include "CryIf.h" 
#include "Crypto_182_iND13400.h" 
#include "Csm.h" 
#include "CanTp.h" 
#include "Dcm.h" 
#include "Det.h" 
#include "Dem.h" 
#include "E2EXf.h" 
#include "PHY_User_Cbk.h" 



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BSWM_ACTION_GENERICMODE         STD_ON 
#define BSWM_ACTION_TIMERCONTROL        STD_ON 
#define BSWM_ACTION_COMMALLOWCOM        STD_ON 
#define BSWM_ACTION_COMMMODESWITCH      STD_ON 
#define BSWM_ACTION_SDSERVER            STD_ON 
#define BSWM_ACTION_SDCONSUMED          STD_ON 
#define BSWM_ACTION_SDCLIENT            STD_ON 
#define BSWM_ACTION_COMPDUGROUPHANDLING STD_ON 
#define BSWM_ACTION_COMDMHANDLING       STD_ON 


# define BSWM_FUNCTION_BASED STD_OFF

#if (defined (BSWM_ACTIONLISTSTRUEIDXOFRULES))
# if ((BSWM_ACTIONLISTSTRUEIDXOFRULES == STD_ON) && defined (BSWM_NO_ACTIONLISTSTRUEIDXOFRULES))
#  define BSWM_NO_ACTIONLIST(partition) BSWM_NO_ACTIONLISTSTRUEIDXOFRULES
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# if(defined(BSWM_ACTIONLISTSFALSEIDXOFRULES))
#  if ((BSWM_ACTIONLISTSFALSEIDXOFRULES == STD_ON) && defined (BSWM_NO_ACTIONLISTSFALSEIDXOFRULES))
#   define BSWM_NO_ACTIONLIST(partition) BSWM_NO_ACTIONLISTSFALSEIDXOFRULES
#  endif
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# if(defined(BSWM_SIZEOFACTIONLISTS))
#  if (BSWM_SIZEOFACTIONLISTS == STD_ON)
#   define BSWM_NO_ACTIONLIST(partition) BswM_GetSizeOfActionLists(partition) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# define BSWM_NO_ACTIONLIST(partition) 255
#endif




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCGetRootDataMacros  BswM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define BswM_GetPCPartitionConfigOfPCConfig()                                                       BswM_ConfigPtr->PCPartitionConfigOfPCConfig
#define BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)                                      BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ActionItemsOfPCPartitionConfig
#define BswM_GetActionsOfPCPartitionConfig(partitionIndex)                                          BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ActionsOfPCPartitionConfig
#define BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)                   BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComDMHandlingDisableParametersOfPCPartitionConfig
#define BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)                    BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComDMHandlingEnableParametersOfPCPartitionConfig
#define BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)                    BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComPduGroupHandlingParametersOfPCPartitionConfig
#define BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)               BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComPduGroupHandlingStartParametersOfPCPartitionConfig
#define BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)                BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComPduGroupHandlingStopParametersOfPCPartitionConfig
#define BswM_GetExpressionsOfPCPartitionConfig(partitionIndex)                                      BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ExpressionsOfPCPartitionConfig
#define BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex)                           BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimerControlParametersOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetConstantDuplicatedRootDataMacros  BswM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define BswM_GetPartitionIdentifiersOfPCConfig()                                                    BswM_PartitionIdentifiers  /**< the pointer to BswM_PartitionIdentifiers */
#define BswM_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in BswM_PartitionIdentifiers */
#define BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)                                  BswM_ActionListQueue.raw  /**< the pointer to BswM_ActionListQueue */
#define BswM_GetActionListsOfPCPartitionConfig(partitionIndex)                                      BswM_ActionLists  /**< the pointer to BswM_ActionLists */
#define BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                              BswM_CanSMChannelMapping  /**< the pointer to BswM_CanSMChannelMapping */
#define BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)                                BswM_CanSMChannelState  /**< the pointer to BswM_CanSMChannelState */
#define BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                          BswM_ComDMHandlingParameters  /**< the pointer to BswM_ComDMHandlingParameters */
#define BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)                           BswM_ComMAllowComParameters  /**< the pointer to BswM_ComMAllowComParameters */
#define BswM_GetComMChannelMappingOfPCPartitionConfig(partitionIndex)                               BswM_ComMChannelMapping  /**< the pointer to BswM_ComMChannelMapping */
#define BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)                                 BswM_ComMChannelState  /**< the pointer to BswM_ComMChannelState */
#define BswM_GetComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)                         BswM_ComMModeSwitchParameters  /**< the pointer to BswM_ComMModeSwitchParameters */
#define BswM_GetDeferredRulesOfPCPartitionConfig(partitionIndex)                                    BswM_DeferredRules  /**< the pointer to BswM_DeferredRules */
#define BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex)                         (&(BswM_ForcedActionListPriority))  /**< the pointer to BswM_ForcedActionListPriority */
#define BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)                                   BswM_GenericMapping  /**< the pointer to BswM_GenericMapping */
#define BswM_GetGenericModeParametersOfPCPartitionConfig(partitionIndex)                            BswM_GenericModeParameters  /**< the pointer to BswM_GenericModeParameters */
#define BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)                                     BswM_GenericState  /**< the pointer to BswM_GenericState */
#define BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)                                    BswM_ImmediateUser  /**< the pointer to BswM_ImmediateUser */
#define BswM_GetInitActionListsOfPCPartitionConfig(partitionIndex)                                  BswM_InitActionLists  /**< the pointer to BswM_InitActionLists */
#define BswM_GetInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                              BswM_InitGenVarAndInitAL  /**< the pointer to BswM_InitGenVarAndInitAL */
#define BswM_GetInitializedOfPCPartitionConfig(partitionIndex)                                      (&(BswM_Initialized))  /**< the pointer to BswM_Initialized */
#define BswM_GetModeNotificationFctOfPCPartitionConfig(partitionIndex)                              BswM_ModeNotificationFct  /**< the pointer to BswM_ModeNotificationFct */
#define BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)                                 BswM_ModeRequestQueue  /**< the pointer to BswM_ModeRequestQueue */
#define BswM_GetNvMJobMappingOfPCPartitionConfig(partitionIndex)                                    BswM_NvMJobMapping  /**< the pointer to BswM_NvMJobMapping */
#define BswM_GetNvMJobStateOfPCPartitionConfig(partitionIndex)                                      BswM_NvMJobState  /**< the pointer to BswM_NvMJobState */
#define BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex)                                   (&(BswM_QueueSemaphore))  /**< the pointer to BswM_QueueSemaphore */
#define BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex)                                     (&(BswM_QueueWritten))  /**< the pointer to BswM_QueueWritten */
#define BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)                                       BswM_RuleStates.raw  /**< the pointer to BswM_RuleStates */
#define BswM_GetRulesIndOfPCPartitionConfig(partitionIndex)                                         BswM_RulesInd  /**< the pointer to BswM_RulesInd */
#define BswM_GetRulesOfPCPartitionConfig(partitionIndex)                                            BswM_Rules  /**< the pointer to BswM_Rules */
#define BswM_GetSdClientParametersOfPCPartitionConfig(partitionIndex)                               BswM_SdClientParameters  /**< the pointer to BswM_SdClientParameters */
#define BswM_GetSdClientServiceMappingOfPCPartitionConfig(partitionIndex)                           BswM_SdClientServiceMapping  /**< the pointer to BswM_SdClientServiceMapping */
#define BswM_GetSdClientServiceStateOfPCPartitionConfig(partitionIndex)                             BswM_SdClientServiceState  /**< the pointer to BswM_SdClientServiceState */
#define BswM_GetSdConsumedEventMappingOfPCPartitionConfig(partitionIndex)                           BswM_SdConsumedEventMapping  /**< the pointer to BswM_SdConsumedEventMapping */
#define BswM_GetSdConsumedEventStateOfPCPartitionConfig(partitionIndex)                             BswM_SdConsumedEventState  /**< the pointer to BswM_SdConsumedEventState */
#define BswM_GetSdConsumedParametersOfPCPartitionConfig(partitionIndex)                             BswM_SdConsumedParameters  /**< the pointer to BswM_SdConsumedParameters */
#define BswM_GetSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)                            BswM_SdEventHandlerMapping  /**< the pointer to BswM_SdEventHandlerMapping */
#define BswM_GetSdEventHandlerStateOfPCPartitionConfig(partitionIndex)                              BswM_SdEventHandlerState  /**< the pointer to BswM_SdEventHandlerState */
#define BswM_GetSdServerParametersOfPCPartitionConfig(partitionIndex)                               BswM_SdServerParameters  /**< the pointer to BswM_SdServerParameters */
#define BswM_GetSizeOfActionItemsOfPCPartitionConfig(partitionIndex)                                117u  /**< the number of accomplishable value elements in BswM_ActionItems */
#define BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)                                43u  /**< the number of accomplishable value elements in BswM_ActionLists */
#define BswM_GetSizeOfActionsOfPCPartitionConfig(partitionIndex)                                    78u  /**< the number of accomplishable value elements in BswM_Actions */
#define BswM_GetSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                        2u  /**< the number of accomplishable value elements in BswM_CanSMChannelMapping */
#define BswM_GetSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)                          2u  /**< the number of accomplishable value elements in BswM_CanSMChannelState */
#define BswM_GetSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)             2u  /**< the number of accomplishable value elements in BswM_ComDMHandlingDisableParameters */
#define BswM_GetSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)              2u  /**< the number of accomplishable value elements in BswM_ComDMHandlingEnableParameters */
#define BswM_GetSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                    4u  /**< the number of accomplishable value elements in BswM_ComDMHandlingParameters */
#define BswM_GetSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)                     5u  /**< the number of accomplishable value elements in BswM_ComMAllowComParameters */
#define BswM_GetSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)                         1u  /**< the number of accomplishable value elements in BswM_ComMChannelMapping */
#define BswM_GetSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)                           1u  /**< the number of accomplishable value elements in BswM_ComMChannelState */
#define BswM_GetSizeOfComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)                   2u  /**< the number of accomplishable value elements in BswM_ComMModeSwitchParameters */
#define BswM_GetSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)              6u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingParameters */
#define BswM_GetSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)         3u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingStartParameters */
#define BswM_GetSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)          3u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingStopParameters */
#define BswM_GetSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)                              17u  /**< the number of accomplishable value elements in BswM_DeferredRules */
#define BswM_GetSizeOfExpressionsOfPCPartitionConfig(partitionIndex)                                37u  /**< the number of accomplishable value elements in BswM_Expressions */
#define BswM_GetSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in BswM_GenericMapping */
#define BswM_GetSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)                      5u  /**< the number of accomplishable value elements in BswM_GenericModeParameters */
#define BswM_GetSizeOfGenericStateOfPCPartitionConfig(partitionIndex)                               1u  /**< the number of accomplishable value elements in BswM_GenericState */
#define BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)                              3u  /**< the number of accomplishable value elements in BswM_ImmediateUser */
#define BswM_GetSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in BswM_InitActionLists */
#define BswM_GetSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in BswM_InitGenVarAndInitAL */
#define BswM_GetSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in BswM_ModeNotificationFct */
#define BswM_GetSizeOfNvMJobMappingOfPCPartitionConfig(partitionIndex)                              1u  /**< the number of accomplishable value elements in BswM_NvMJobMapping */
#define BswM_GetSizeOfNvMJobStateOfPCPartitionConfig(partitionIndex)                                1u  /**< the number of accomplishable value elements in BswM_NvMJobState */
#define BswM_GetSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)                                 26u  /**< the number of accomplishable value elements in BswM_RuleStates */
#define BswM_GetSizeOfRulesIndOfPCPartitionConfig(partitionIndex)                                   12u  /**< the number of accomplishable value elements in BswM_RulesInd */
#define BswM_GetSizeOfRulesOfPCPartitionConfig(partitionIndex)                                      26u  /**< the number of accomplishable value elements in BswM_Rules */
#define BswM_GetSizeOfSdClientParametersOfPCPartitionConfig(partitionIndex)                         2u  /**< the number of accomplishable value elements in BswM_SdClientParameters */
#define BswM_GetSizeOfSdClientServiceMappingOfPCPartitionConfig(partitionIndex)                     1u  /**< the number of accomplishable value elements in BswM_SdClientServiceMapping */
#define BswM_GetSizeOfSdClientServiceStateOfPCPartitionConfig(partitionIndex)                       1u  /**< the number of accomplishable value elements in BswM_SdClientServiceState */
#define BswM_GetSizeOfSdConsumedEventMappingOfPCPartitionConfig(partitionIndex)                     1u  /**< the number of accomplishable value elements in BswM_SdConsumedEventMapping */
#define BswM_GetSizeOfSdConsumedEventStateOfPCPartitionConfig(partitionIndex)                       1u  /**< the number of accomplishable value elements in BswM_SdConsumedEventState */
#define BswM_GetSizeOfSdConsumedParametersOfPCPartitionConfig(partitionIndex)                       2u  /**< the number of accomplishable value elements in BswM_SdConsumedParameters */
#define BswM_GetSizeOfSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)                      3u  /**< the number of accomplishable value elements in BswM_SdEventHandlerMapping */
#define BswM_GetSizeOfSdEventHandlerStateOfPCPartitionConfig(partitionIndex)                        3u  /**< the number of accomplishable value elements in BswM_SdEventHandlerState */
#define BswM_GetSizeOfSdServerParametersOfPCPartitionConfig(partitionIndex)                         6u  /**< the number of accomplishable value elements in BswM_SdServerParameters */
#define BswM_GetSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                    1u  /**< the number of accomplishable value elements in BswM_SwcModeRequestUpdateFct */
#define BswM_GetSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)                     5u  /**< the number of accomplishable value elements in BswM_TimerControlParameters */
#define BswM_GetSizeOfTimerStateOfPCPartitionConfig(partitionIndex)                                 3u  /**< the number of accomplishable value elements in BswM_TimerState */
#define BswM_GetSizeOfTimerValueOfPCPartitionConfig(partitionIndex)                                 3u  /**< the number of accomplishable value elements in BswM_TimerValue */
#define BswM_GetSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                          BswM_SwcModeRequestUpdateFct  /**< the pointer to BswM_SwcModeRequestUpdateFct */
#define BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)                                       BswM_TimerState.raw  /**< the pointer to BswM_TimerState */
#define BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)                                       BswM_TimerValue.raw  /**< the pointer to BswM_TimerValue */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDuplicatedRootDataMacros  BswM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define BswM_GetSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)                            BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in BswM_ActionListQueue */
#define BswM_GetSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)                           BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in BswM_ModeRequestQueue */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDataMacros  BswM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define BswM_GetActionsIdxOfActionItems(Index, partitionIndex)                                      (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ActionsIdxOfActionItems)
#define BswM_GetParameterIdxOfActionItems(Index, partitionIndex)                                    (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ParameterIdxOfActionItems)
#define BswM_GetParameterOfActionItems(Index, partitionIndex)                                       (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ParameterOfActionItems)
#define BswM_GetActionListQueue(Index, partitionIndex)                                              (BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetActionItemsEndIdxOfActionLists(Index, partitionIndex)                               (BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsEndIdxOfActionLists)
#define BswM_GetActionItemsStartIdxOfActionLists(Index, partitionIndex)                             (BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsStartIdxOfActionLists)
#define BswM_IsConditionalOfActionLists(Index, partitionIndex)                                      ((BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ConditionalOfActionLists) != FALSE)
#define BswM_GetActions(Index, partitionIndex)                                                      (BswM_GetActionsOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetExternalIdOfCanSMChannelMapping(Index, partitionIndex)                              (BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfCanSMChannelMapping)
#define BswM_GetImmediateUserEndIdxOfCanSMChannelMapping(Index, partitionIndex)                     (BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserEndIdxOfCanSMChannelMapping)
#define BswM_GetImmediateUserStartIdxOfCanSMChannelMapping(Index, partitionIndex)                   (BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserStartIdxOfCanSMChannelMapping)
#define BswM_GetCanSMChannelState(Index, partitionIndex)                                            (BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetIpduGroupIdOfComDMHandlingDisableParameters(Index, partitionIndex)                  (BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComDMHandlingDisableParameters)
#define BswM_GetIpduGroupIdOfComDMHandlingEnableParameters(Index, partitionIndex)                   (BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComDMHandlingEnableParameters)
#define BswM_GetActionItemsIdxOfComDMHandlingParameters(Index, partitionIndex)                      (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters)
#define BswM_GetAllowedOfComMAllowComParameters(Index, partitionIndex)                              (BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)[(Index)].AllowedOfComMAllowComParameters)
#define BswM_GetChannelOfComMAllowComParameters(Index, partitionIndex)                              (BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)[(Index)].ChannelOfComMAllowComParameters)
#define BswM_GetComMChannelState(Index, partitionIndex)                                             (BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetUserOfComMModeSwitchParameters(Index, partitionIndex)                               (BswM_GetComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)[(Index)].UserOfComMModeSwitchParameters)
#define BswM_GetActionItemsIdxOfComPduGroupHandlingParameters(Index, partitionIndex)                (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters)
#define BswM_GetIpduGroupIdOfComPduGroupHandlingStartParameters(Index, partitionIndex)              (BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComPduGroupHandlingStartParameters)
#define BswM_GetIpduGroupIdOfComPduGroupHandlingStopParameters(Index, partitionIndex)               (BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComPduGroupHandlingStopParameters)
#define BswM_GetRulesIdxOfDeferredRules(Index, partitionIndex)                                      (BswM_GetDeferredRulesOfPCPartitionConfig(partitionIndex)[(Index)].RulesIdxOfDeferredRules)
#define BswM_GetExpressions(Index, partitionIndex)                                                  (BswM_GetExpressionsOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetForcedActionListPriority(partitionIndex)                                            ((*(BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex))))
#define BswM_GetModeOfGenericModeParameters(Index, partitionIndex)                                  (BswM_GetGenericModeParametersOfPCPartitionConfig(partitionIndex)[(Index)].ModeOfGenericModeParameters)
#define BswM_GetGenericState(Index, partitionIndex)                                                 (BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_IsOnInitOfImmediateUser(Index, partitionIndex)                                         ((BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].OnInitOfImmediateUser) != FALSE)
#define BswM_GetRulesIndEndIdxOfImmediateUser(Index, partitionIndex)                                (BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].RulesIndEndIdxOfImmediateUser)
#define BswM_GetRulesIndStartIdxOfImmediateUser(Index, partitionIndex)                              (BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].RulesIndStartIdxOfImmediateUser)
#define BswM_GetInitGenVarAndInitAL(Index, partitionIndex)                                          (BswM_GetInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_IsInitialized(partitionIndex)                                                          (((*(BswM_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define BswM_GetModeNotificationFct(Index, partitionIndex)                                          (BswM_GetModeNotificationFctOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetModeRequestQueue(Index, partitionIndex)                                             (BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetNvMJobState(Index, partitionIndex)                                                  (BswM_GetNvMJobStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (BswM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define BswM_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (BswM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define BswM_GetQueueSemaphore(partitionIndex)                                                      ((*(BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex))))
#define BswM_IsQueueWritten(partitionIndex)                                                         (((*(BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define BswM_GetRuleStates(Index, partitionIndex)                                                   (BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetActionListsFalseIdxOfRules(Index, partitionIndex)                                   (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ActionListsFalseIdxOfRules)
#define BswM_GetActionListsTrueIdxOfRules(Index, partitionIndex)                                    (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ActionListsTrueIdxOfRules)
#define BswM_GetExpressionsIdxOfRules(Index, partitionIndex)                                        (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ExpressionsIdxOfRules)
#define BswM_GetIdOfRules(Index, partitionIndex)                                                    (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].IdOfRules)
#define BswM_GetRuleStatesIdxOfRules(Index, partitionIndex)                                         (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].RuleStatesIdxOfRules)
#define BswM_GetRulesInd(Index, partitionIndex)                                                     (BswM_GetRulesIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetStateOfSdClientParameters(Index, partitionIndex)                                    (BswM_GetSdClientParametersOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSdClientParameters)
#define BswM_GetSdClientServiceState(Index, partitionIndex)                                         (BswM_GetSdClientServiceStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetSdConsumedEventState(Index, partitionIndex)                                         (BswM_GetSdConsumedEventStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetStateOfSdConsumedParameters(Index, partitionIndex)                                  (BswM_GetSdConsumedParametersOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSdConsumedParameters)
#define BswM_GetExternalIdOfSdEventHandlerMapping(Index, partitionIndex)                            (BswM_GetSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfSdEventHandlerMapping)
#define BswM_GetSdEventHandlerState(Index, partitionIndex)                                          (BswM_GetSdEventHandlerStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetIdOfSdServerParameters(Index, partitionIndex)                                       (BswM_GetSdServerParametersOfPCPartitionConfig(partitionIndex)[(Index)].IdOfSdServerParameters)
#define BswM_GetStateOfSdServerParameters(Index, partitionIndex)                                    (BswM_GetSdServerParametersOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSdServerParameters)
#define BswM_GetSwcModeRequestUpdateFct(Index, partitionIndex)                                      (BswM_GetSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetTimerOfTimerControlParameters(Index, partitionIndex)                                (BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex)[(Index)].TimerOfTimerControlParameters)
#define BswM_GetValueOfTimerControlParameters(Index, partitionIndex)                                (BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex)[(Index)].ValueOfTimerControlParameters)
#define BswM_GetTimerState(Index, partitionIndex)                                                   (BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetTimerValue(Index, partitionIndex)                                                   (BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDeduplicatedDataMacros  BswM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define BswM_IsParameterUsedOfActionItems(Index, partitionIndex)                                    (((boolean)(BswM_GetParameterIdxOfActionItems(((Index)), (partitionIndex)) != BSWM_NO_PARAMETERIDXOFACTIONITEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules */
#define BswM_IsActionItemsUsedOfActionLists(Index, partitionIndex)                                  (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ActionItems */
#define BswM_IsImmediateUserUsedOfCanSMChannelMapping(Index, partitionIndex)                        (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfCanSMChannelMapping(Index, partitionIndex)                               CANSM_BSWM_NO_COMMUNICATION  /**< Initialization value of port. */
#define BswM_IsComDMHandlingDisableParametersUsedOfComDMHandlingParameters(Index, partitionIndex)   (((boolean)(BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComDMHandlingDisableParameters */
#define BswM_IsComDMHandlingEnableParametersUsedOfComDMHandlingParameters(Index, partitionIndex)    (((boolean)(BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComDMHandlingEnableParameters */
#define BswM_GetExternalIdOfComMChannelMapping(Index, partitionIndex)                               ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b  /**< External id of BswMComMIndication. */
#define BswM_GetInitValueOfComMChannelMapping(Index, partitionIndex)                                COMM_NO_COMMUNICATION  /**< Initialization value of port. */
#define BswM_GetComModeOfComMModeSwitchParameters(Index, partitionIndex)                            COMM_FULL_COMMUNICATION
#define BswM_IsComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParameters(Index, partitionIndex) (((boolean)(BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComPduGroupHandlingStartParameters */
#define BswM_IsComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParameters(Index, partitionIndex) (((boolean)(BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComPduGroupHandlingStopParameters */
#define BswM_GetInitializeOfComPduGroupHandlingStartParameters(Index, partitionIndex)               FALSE
#define BswM_GetExternalIdOfGenericMapping(Index, partitionIndex)                                   BSWM_GENERIC_ESH_State  /**< External id of BswMGenericRequest. */
#define BswM_GetImmediateUserEndIdxOfGenericMapping(Index, partitionIndex)                          3u  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_GetImmediateUserStartIdxOfGenericMapping(Index, partitionIndex)                        2u  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_IsImmediateUserUsedOfGenericMapping(Index, partitionIndex)                             (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfGenericMapping(Index, partitionIndex)                                    BSWM_GENERICVALUE_ESH_State_ESH_INIT  /**< Initialization value of port. */
#define BswM_GetUserOfGenericModeParameters(Index, partitionIndex)                                  BSWM_GENERIC_ESH_State
#define BswM_IsRulesIndUsedOfImmediateUser(Index, partitionIndex)                                   (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_RulesInd */
#define BswM_GetInitActionLists(Index, partitionIndex)                                              22u  /**< List of all action lists which shall be executed at end of Bswm_Init. */
#define BswM_GetExternalIdOfNvMJobMapping(Index, partitionIndex)                                    NVM_WRITE_ALL  /**< External id of BswMNvMJobModeIndication. */
#define BswM_GetInitValueOfNvMJobMapping(Index, partitionIndex)                                     NVM_REQ_OK  /**< Initialization value of port. */
#define BswM_IsActionListsFalseUsedOfRules(Index, partitionIndex)                                   (((boolean)(BswM_GetActionListsFalseIdxOfRules(((Index)), (partitionIndex)) != BSWM_NO_ACTIONLISTSFALSEIDXOFRULES)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ActionLists */
#define BswM_IsActionListsTrueUsedOfRules(Index, partitionIndex)                                    (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ActionLists */
#define BswM_GetInitOfRules(Index, partitionIndex)                                                  BSWM_FALSE  /**< Initialization value of rule state (TRUE, FALSE, UNDEFINED or DEACTIVATED). */
#define BswM_GetIdOfSdClientParameters(Index, partitionIndex)                                       SdConf_SdClientService_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b
#define BswM_GetExternalIdOfSdClientServiceMapping(Index, partitionIndex)                           SdConf_SdClientService_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b  /**< External id of BswMSdClientServiceCurrentState. */
#define BswM_GetInitValueOfSdClientServiceMapping(Index, partitionIndex)                            SD_CLIENT_SERVICE_DOWN  /**< Initialization value of port. */
#define BswM_GetExternalIdOfSdConsumedEventMapping(Index, partitionIndex)                           SdConf_SdConsumedEventGroup_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85  /**< External id of BswMSdConsumedEventGroupCurrentState. */
#define BswM_GetInitValueOfSdConsumedEventMapping(Index, partitionIndex)                            SD_CONSUMED_EVENTGROUP_DOWN  /**< Initialization value of port. */
#define BswM_GetIdOfSdConsumedParameters(Index, partitionIndex)                                     SdConf_SdConsumedEventGroup_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85
#define BswM_GetInitValueOfSdEventHandlerMapping(Index, partitionIndex)                             SD_EVENT_HANDLER_RELEASED  /**< Initialization value of port. */
#define BswM_GetSizeOfActionItems(partitionIndex)                                                   BswM_GetSizeOfActionItemsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActionListQueue(partitionIndex)                                               BswM_GetSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActionLists(partitionIndex)                                                   BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActions(partitionIndex)                                                       BswM_GetSizeOfActionsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfCanSMChannelMapping(partitionIndex)                                           BswM_GetSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfCanSMChannelState(partitionIndex)                                             BswM_GetSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingDisableParameters(partitionIndex)                                BswM_GetSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingEnableParameters(partitionIndex)                                 BswM_GetSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingParameters(partitionIndex)                                       BswM_GetSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMAllowComParameters(partitionIndex)                                        BswM_GetSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMChannelMapping(partitionIndex)                                            BswM_GetSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMChannelState(partitionIndex)                                              BswM_GetSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMModeSwitchParameters(partitionIndex)                                      BswM_GetSizeOfComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingParameters(partitionIndex)                                 BswM_GetSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingStartParameters(partitionIndex)                            BswM_GetSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingStopParameters(partitionIndex)                             BswM_GetSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfDeferredRules(partitionIndex)                                                 BswM_GetSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfExpressions(partitionIndex)                                                   BswM_GetSizeOfExpressionsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericMapping(partitionIndex)                                                BswM_GetSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericModeParameters(partitionIndex)                                         BswM_GetSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericState(partitionIndex)                                                  BswM_GetSizeOfGenericStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfImmediateUser(partitionIndex)                                                 BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfInitActionLists(partitionIndex)                                               BswM_GetSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfInitGenVarAndInitAL(partitionIndex)                                           BswM_GetSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfModeNotificationFct(partitionIndex)                                           BswM_GetSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfModeRequestQueue(partitionIndex)                                              BswM_GetSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfNvMJobMapping(partitionIndex)                                                 BswM_GetSizeOfNvMJobMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfNvMJobState(partitionIndex)                                                   BswM_GetSizeOfNvMJobStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfPartitionIdentifiers()                                                        BswM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define BswM_GetSizeOfRuleStates(partitionIndex)                                                    BswM_GetSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfRules(partitionIndex)                                                         BswM_GetSizeOfRulesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfRulesInd(partitionIndex)                                                      BswM_GetSizeOfRulesIndOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdClientParameters(partitionIndex)                                            BswM_GetSizeOfSdClientParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdClientServiceMapping(partitionIndex)                                        BswM_GetSizeOfSdClientServiceMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdClientServiceState(partitionIndex)                                          BswM_GetSizeOfSdClientServiceStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdConsumedEventMapping(partitionIndex)                                        BswM_GetSizeOfSdConsumedEventMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdConsumedEventState(partitionIndex)                                          BswM_GetSizeOfSdConsumedEventStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdConsumedParameters(partitionIndex)                                          BswM_GetSizeOfSdConsumedParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdEventHandlerMapping(partitionIndex)                                         BswM_GetSizeOfSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdEventHandlerState(partitionIndex)                                           BswM_GetSizeOfSdEventHandlerStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSdServerParameters(partitionIndex)                                            BswM_GetSizeOfSdServerParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSwcModeRequestUpdateFct(partitionIndex)                                       BswM_GetSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerControlParameters(partitionIndex)                                        BswM_GetSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerState(partitionIndex)                                                    BswM_GetSizeOfTimerStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerValue(partitionIndex)                                                    BswM_GetSizeOfTimerValueOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSetDataMacros  BswM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define BswM_SetActionListQueue(Index, Value, partitionIndex)                                       BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetCanSMChannelState(Index, Value, partitionIndex)                                     BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetComMChannelState(Index, Value, partitionIndex)                                      BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetForcedActionListPriority(Value, partitionIndex)                                     (*(BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetGenericState(Index, Value, partitionIndex)                                          BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetInitialized(Value, partitionIndex)                                                  (*(BswM_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetModeRequestQueue(Index, Value, partitionIndex)                                      BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetNvMJobState(Index, Value, partitionIndex)                                           BswM_GetNvMJobStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetQueueSemaphore(Value, partitionIndex)                                               (*(BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetQueueWritten(Value, partitionIndex)                                                 (*(BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetRuleStates(Index, Value, partitionIndex)                                            BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetSdClientServiceState(Index, Value, partitionIndex)                                  BswM_GetSdClientServiceStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetSdConsumedEventState(Index, Value, partitionIndex)                                  BswM_GetSdConsumedEventStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetSdEventHandlerState(Index, Value, partitionIndex)                                   BswM_GetSdEventHandlerStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetTimerState(Index, Value, partitionIndex)                                            BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetTimerValue(Index, Value, partitionIndex)                                            BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCHasMacros  BswM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define BswM_HasActionItems(partitionIndex)                                                         (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasActionsIdxOfActionItems(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasParameterIdxOfActionItems(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasParameterOfActionItems(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasParameterUsedOfActionItems(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasActionListQueue(partitionIndex)                                                     (TRUE != FALSE)
#define BswM_HasActionLists(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasActionItemsEndIdxOfActionLists(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionItemsStartIdxOfActionLists(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasActionItemsUsedOfActionLists(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasConditionalOfActionLists(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasActions(partitionIndex)                                                             (BswM_GetActionsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasCanSMChannelMapping(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasExternalIdOfCanSMChannelMapping(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfCanSMChannelMapping(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfCanSMChannelMapping(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfCanSMChannelMapping(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasInitValueOfCanSMChannelMapping(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasCanSMChannelState(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParameters(partitionIndex)                                      (BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComDMHandlingDisableParameters(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParameters(partitionIndex)                                       (BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComDMHandlingEnableParameters(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasComDMHandlingParameters(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasActionItemsIdxOfComDMHandlingParameters(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(partitionIndex)       (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(partitionIndex)     (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersUsedOfComDMHandlingParameters(partitionIndex)         (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(partitionIndex)        (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(partitionIndex)      (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersUsedOfComDMHandlingParameters(partitionIndex)          (TRUE != FALSE)
#define BswM_HasComMAllowComParameters(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasAllowedOfComMAllowComParameters(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasChannelOfComMAllowComParameters(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasComMChannelMapping(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasExternalIdOfComMChannelMapping(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasInitValueOfComMChannelMapping(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasComMChannelState(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasComMModeSwitchParameters(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasComModeOfComMModeSwitchParameters(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasUserOfComMModeSwitchParameters(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingParameters(partitionIndex)                                       (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasActionItemsIdxOfComPduGroupHandlingParameters(partitionIndex)                       (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParameters(partitionIndex)                                  (BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasInitializeOfComPduGroupHandlingStartParameters(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasIpduGroupIdOfComPduGroupHandlingStartParameters(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParameters(partitionIndex)                                   (BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComPduGroupHandlingStopParameters(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasDeferredRules(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasRulesIdxOfDeferredRules(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasExpressions(partitionIndex)                                                         (BswM_GetExpressionsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasForcedActionListPriority(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasGenericMapping(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasExternalIdOfGenericMapping(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfGenericMapping(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfGenericMapping(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfGenericMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasInitValueOfGenericMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasGenericModeParameters(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasModeOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasUserOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasGenericState(partitionIndex)                                                        (TRUE != FALSE)
#define BswM_HasImmediateUser(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasOnInitOfImmediateUser(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasRulesIndEndIdxOfImmediateUser(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasRulesIndStartIdxOfImmediateUser(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasRulesIndUsedOfImmediateUser(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasInitActionLists(partitionIndex)                                                     (TRUE != FALSE)
#define BswM_HasInitGenVarAndInitAL(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasInitialized(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasModeNotificationFct(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasModeRequestQueue(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasNvMJobMapping(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasExternalIdOfNvMJobMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasInitValueOfNvMJobMapping(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasNvMJobState(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define BswM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define BswM_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define BswM_HasQueueSemaphore(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasQueueWritten(partitionIndex)                                                        (TRUE != FALSE)
#define BswM_HasRuleStates(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasRules(partitionIndex)                                                               (TRUE != FALSE)
#define BswM_HasActionListsFalseIdxOfRules(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasActionListsFalseUsedOfRules(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasActionListsTrueIdxOfRules(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasActionListsTrueUsedOfRules(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasExpressionsIdxOfRules(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasIdOfRules(partitionIndex)                                                           (TRUE != FALSE)
#define BswM_HasInitOfRules(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasRuleStatesIdxOfRules(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasRulesInd(partitionIndex)                                                            (TRUE != FALSE)
#define BswM_HasSdClientParameters(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasIdOfSdClientParameters(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasStateOfSdClientParameters(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSdClientServiceMapping(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasExternalIdOfSdClientServiceMapping(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasInitValueOfSdClientServiceMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasSdClientServiceState(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasSdConsumedEventMapping(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasExternalIdOfSdConsumedEventMapping(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasInitValueOfSdConsumedEventMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasSdConsumedEventState(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasSdConsumedParameters(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasIdOfSdConsumedParameters(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasStateOfSdConsumedParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasSdEventHandlerMapping(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasExternalIdOfSdEventHandlerMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasInitValueOfSdEventHandlerMapping(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasSdEventHandlerState(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSdServerParameters(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasIdOfSdServerParameters(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasStateOfSdServerParameters(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfActionItems(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfActionListQueue(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasSizeOfActionLists(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfActions(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelState(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingDisableParameters(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingEnableParameters(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasSizeOfComMAllowComParameters(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelMapping(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelState(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasSizeOfComMModeSwitchParameters(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingParameters(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStartParameters(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStopParameters(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSizeOfDeferredRules(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfExpressions(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfGenericMapping(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasSizeOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasSizeOfGenericState(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasSizeOfImmediateUser(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfInitActionLists(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasSizeOfInitGenVarAndInitAL(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfModeNotificationFct(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfModeRequestQueue(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasSizeOfNvMJobMapping(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfNvMJobState(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define BswM_HasSizeOfRuleStates(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSizeOfRules(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasSizeOfRulesInd(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasSizeOfSdClientParameters(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSizeOfSdClientServiceMapping(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfSdClientServiceState(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedEventMapping(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedEventState(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedParameters(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasSizeOfSdEventHandlerMapping(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasSizeOfSdEventHandlerState(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfSdServerParameters(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSizeOfSwcModeRequestUpdateFct(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasSizeOfTimerControlParameters(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfTimerState(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSizeOfTimerValue(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSwcModeRequestUpdateFct(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasTimerControlParameters(partitionIndex)                                              (BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasTimerOfTimerControlParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasValueOfTimerControlParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasTimerState(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasTimerValue(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasPCConfig()                                                                          (TRUE != FALSE)
#define BswM_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define BswM_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define BswM_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define BswM_HasPCPartitionConfig()                                                                 (BswM_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define BswM_HasActionItemsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionListQueueOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasActionListsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionsOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasCanSMChannelStateOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasComMAllowComParametersOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasComMChannelMappingOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasComMChannelStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define BswM_HasDeferredRulesOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasExpressionsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasForcedActionListPriorityOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasGenericMappingOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasGenericModeParametersOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasGenericStateOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasImmediateUserOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasInitActionListsOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasInitializedOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasModeNotificationFctOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasModeRequestQueueOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasNvMJobMappingOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasNvMJobStateOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasQueueSemaphoreOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasQueueWrittenOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasRuleStatesOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasRulesIndOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasRulesOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSdClientParametersOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasSdClientServiceMappingOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSdClientServiceStateOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSdConsumedEventMappingOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSdConsumedEventStateOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSdConsumedParametersOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSdEventHandlerStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSdServerParametersOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasSizeOfActionItemsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfActionListsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfActionsOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSizeOfComMModeSwitchParametersOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define BswM_HasSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfExpressionsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasSizeOfGenericStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSizeOfNvMJobMappingOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfNvMJobStateOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfRulesIndOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasSizeOfRulesOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasSizeOfSdClientParametersOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasSizeOfSdClientServiceMappingOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfSdClientServiceStateOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedEventMappingOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedEventStateOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define BswM_HasSizeOfSdConsumedParametersOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define BswM_HasSizeOfSdEventHandlerMappingOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasSizeOfSdEventHandlerStateOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfSdServerParametersOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfTimerStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfTimerValueOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasTimerControlParametersOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasTimerStateOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasTimerValueOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCIncrementDataMacros  BswM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define BswM_IncActionListQueue(Index, partitionIndex)                                              BswM_GetActionListQueue(((Index)), (partitionIndex))++
#define BswM_IncCanSMChannelState(Index, partitionIndex)                                            BswM_GetCanSMChannelState(((Index)), (partitionIndex))++
#define BswM_IncComMChannelState(Index, partitionIndex)                                             BswM_GetComMChannelState(((Index)), (partitionIndex))++
#define BswM_IncForcedActionListPriority(partitionIndex)                                            BswM_GetForcedActionListPriority(partitionIndex)++
#define BswM_IncGenericState(Index, partitionIndex)                                                 BswM_GetGenericState(((Index)), (partitionIndex))++
#define BswM_IncModeRequestQueue(Index, partitionIndex)                                             BswM_GetModeRequestQueue(((Index)), (partitionIndex))++
#define BswM_IncNvMJobState(Index, partitionIndex)                                                  BswM_GetNvMJobState(((Index)), (partitionIndex))++
#define BswM_IncQueueSemaphore(partitionIndex)                                                      BswM_GetQueueSemaphore(partitionIndex)++
#define BswM_IncRuleStates(Index, partitionIndex)                                                   BswM_GetRuleStates(((Index)), (partitionIndex))++
#define BswM_IncSdClientServiceState(Index, partitionIndex)                                         BswM_GetSdClientServiceState(((Index)), (partitionIndex))++
#define BswM_IncSdConsumedEventState(Index, partitionIndex)                                         BswM_GetSdConsumedEventState(((Index)), (partitionIndex))++
#define BswM_IncSdEventHandlerState(Index, partitionIndex)                                          BswM_GetSdEventHandlerState(((Index)), (partitionIndex))++
#define BswM_IncTimerState(Index, partitionIndex)                                                   BswM_GetTimerState(((Index)), (partitionIndex))++
#define BswM_IncTimerValue(Index, partitionIndex)                                                   BswM_GetTimerValue(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCDecrementDataMacros  BswM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define BswM_DecActionListQueue(Index, partitionIndex)                                              BswM_GetActionListQueue(((Index)), (partitionIndex))--
#define BswM_DecCanSMChannelState(Index, partitionIndex)                                            BswM_GetCanSMChannelState(((Index)), (partitionIndex))--
#define BswM_DecComMChannelState(Index, partitionIndex)                                             BswM_GetComMChannelState(((Index)), (partitionIndex))--
#define BswM_DecForcedActionListPriority(partitionIndex)                                            BswM_GetForcedActionListPriority(partitionIndex)--
#define BswM_DecGenericState(Index, partitionIndex)                                                 BswM_GetGenericState(((Index)), (partitionIndex))--
#define BswM_DecModeRequestQueue(Index, partitionIndex)                                             BswM_GetModeRequestQueue(((Index)), (partitionIndex))--
#define BswM_DecNvMJobState(Index, partitionIndex)                                                  BswM_GetNvMJobState(((Index)), (partitionIndex))--
#define BswM_DecQueueSemaphore(partitionIndex)                                                      BswM_GetQueueSemaphore(partitionIndex)--
#define BswM_DecRuleStates(Index, partitionIndex)                                                   BswM_GetRuleStates(((Index)), (partitionIndex))--
#define BswM_DecSdClientServiceState(Index, partitionIndex)                                         BswM_GetSdClientServiceState(((Index)), (partitionIndex))--
#define BswM_DecSdConsumedEventState(Index, partitionIndex)                                         BswM_GetSdConsumedEventState(((Index)), (partitionIndex))--
#define BswM_DecSdEventHandlerState(Index, partitionIndex)                                          BswM_GetSdEventHandlerState(((Index)), (partitionIndex))--
#define BswM_DecTimerState(Index, partitionIndex)                                                   BswM_GetTimerState(((Index)), (partitionIndex))--
#define BswM_DecTimerValue(Index, partitionIndex)                                                   BswM_GetTimerValue(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCAddDataMacros  BswM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define BswM_AddActionListQueue(Index, Value, partitionIndex)                                       BswM_SetActionListQueue(Index, (BswM_GetActionListQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddCanSMChannelState(Index, Value, partitionIndex)                                     BswM_SetCanSMChannelState(Index, (BswM_GetCanSMChannelState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddComMChannelState(Index, Value, partitionIndex)                                      BswM_SetComMChannelState(Index, (BswM_GetComMChannelState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddForcedActionListPriority(Value, partitionIndex)                                     BswM_SetForcedActionListPriority((BswM_GetForcedActionListPriority(partitionIndex) + Value), partitionIndex)
#define BswM_AddGenericState(Index, Value, partitionIndex)                                          BswM_SetGenericState(Index, (BswM_GetGenericState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddModeRequestQueue(Index, Value, partitionIndex)                                      BswM_SetModeRequestQueue(Index, (BswM_GetModeRequestQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddNvMJobState(Index, Value, partitionIndex)                                           BswM_SetNvMJobState(Index, (BswM_GetNvMJobState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddQueueSemaphore(Value, partitionIndex)                                               BswM_SetQueueSemaphore((BswM_GetQueueSemaphore(partitionIndex) + Value), partitionIndex)
#define BswM_AddRuleStates(Index, Value, partitionIndex)                                            BswM_SetRuleStates(Index, (BswM_GetRuleStates(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddSdClientServiceState(Index, Value, partitionIndex)                                  BswM_SetSdClientServiceState(Index, (BswM_GetSdClientServiceState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddSdConsumedEventState(Index, Value, partitionIndex)                                  BswM_SetSdConsumedEventState(Index, (BswM_GetSdConsumedEventState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddSdEventHandlerState(Index, Value, partitionIndex)                                   BswM_SetSdEventHandlerState(Index, (BswM_GetSdEventHandlerState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddTimerState(Index, Value, partitionIndex)                                            BswM_SetTimerState(Index, (BswM_GetTimerState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddTimerValue(Index, Value, partitionIndex)                                            BswM_SetTimerValue(Index, (BswM_GetTimerValue(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSubstractDataMacros  BswM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define BswM_SubActionListQueue(Index, Value, partitionIndex)                                       BswM_SetActionListQueue(Index, (BswM_GetActionListQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubCanSMChannelState(Index, Value, partitionIndex)                                     BswM_SetCanSMChannelState(Index, (BswM_GetCanSMChannelState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubComMChannelState(Index, Value, partitionIndex)                                      BswM_SetComMChannelState(Index, (BswM_GetComMChannelState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubForcedActionListPriority(Value, partitionIndex)                                     BswM_SetForcedActionListPriority((BswM_GetForcedActionListPriority(partitionIndex) - Value), partitionIndex)
#define BswM_SubGenericState(Index, Value, partitionIndex)                                          BswM_SetGenericState(Index, (BswM_GetGenericState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubModeRequestQueue(Index, Value, partitionIndex)                                      BswM_SetModeRequestQueue(Index, (BswM_GetModeRequestQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubNvMJobState(Index, Value, partitionIndex)                                           BswM_SetNvMJobState(Index, (BswM_GetNvMJobState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubQueueSemaphore(Value, partitionIndex)                                               BswM_SetQueueSemaphore((BswM_GetQueueSemaphore(partitionIndex) - Value), partitionIndex)
#define BswM_SubRuleStates(Index, Value, partitionIndex)                                            BswM_SetRuleStates(Index, (BswM_GetRuleStates(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubSdClientServiceState(Index, Value, partitionIndex)                                  BswM_SetSdClientServiceState(Index, (BswM_GetSdClientServiceState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubSdConsumedEventState(Index, Value, partitionIndex)                                  BswM_SetSdConsumedEventState(Index, (BswM_GetSdConsumedEventState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubSdEventHandlerState(Index, Value, partitionIndex)                                   BswM_SetSdEventHandlerState(Index, (BswM_GetSdEventHandlerState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubTimerState(Index, Value, partitionIndex)                                            BswM_SetTimerState(Index, (BswM_GetTimerState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubTimerValue(Index, Value, partitionIndex)                                            BswM_SetTimerValue(Index, (BswM_GetTimerValue(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define BswM_GetPartitionContext() 0u

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3449, 3451 EXTERNDECLARATIONS */ /* MD_BSWM_3449, MD_BSWM_3451 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionItemsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsRDR_01
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRDR_01[117];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionItemsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsRDR_05
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRDR_05[117];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element                Description
  Conditional            If true, action list is executed on condition else on trigger.
  ActionItemsEndIdx      the end index of the 0:n relation pointing to BswM_ActionItems
  ActionItemsStartIdx    the start index of the 0:n relation pointing to BswM_ActionItems
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[43];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_01
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_01[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_02
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_02[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_03
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_03[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_04
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_04[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_05
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_05[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_06
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_06[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_07
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_07[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_08
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_08[78];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMapping
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMCanSMIndication.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMapping[2];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_01[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_02[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_03[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_04[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_05[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_06[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_07[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_08[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_01[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_02[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_03[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_04[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_05[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_06[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_07[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_08[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingParameters
  \details
  Element                                   Description
  ActionItemsIdx                            the index of the 1:1 relation pointing to BswM_ActionItems
  ComDMHandlingDisableParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingDisableParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
  ComDMHandlingEnableParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComDMHandlingParametersType, BSWM_CONST) BswM_ComDMHandlingParameters[4];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMAllowComParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComMAllowComParameters
  \details
  Element    Description
  Channel
  Allowed
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParameters[5];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMModeSwitchParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComMModeSwitchParameters
  \details
  Element    Description
  User   
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComMModeSwitchParametersType, BSWM_CONST) BswM_ComMModeSwitchParameters[2];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingParametersRDR_01
  \details
  Element                                       Description
  ActionItemsIdx                                the index of the 1:1 relation pointing to BswM_ActionItems
  ComPduGroupHandlingStartParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStartParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
  ComPduGroupHandlingStopParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParametersRDR_01[6];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingParametersRDR_05
  \details
  Element                                       Description
  ActionItemsIdx                                the index of the 1:1 relation pointing to BswM_ActionItems
  ComPduGroupHandlingStartParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStartParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
  ComPduGroupHandlingStopParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParametersRDR_05[6];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_01[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_02[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_03[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_04[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_05[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_06[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_07[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_08[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_01[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_02[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_03[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_04[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_05[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_06[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_07[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_08[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[17];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_01
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_01[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_02
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_02[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_03
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_03[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_04
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_04[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_05
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_05[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_06
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_06[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_07
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_07[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_08
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_08[37];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericModeParameters
**********************************************************************************************************************/
/** 
  \var    BswM_GenericModeParameters
  \details
  Element    Description
  Mode   
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_GenericModeParametersType, BSWM_CONST) BswM_GenericModeParameters[5];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  OnInit              Arbitrate depending rules on initialization.
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[3];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeNotificationFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element                Description
  ActionListsFalseIdx    the index of the 0:1 relation pointing to BswM_ActionLists
  ActionListsTrueIdx     the index of the 0:1 relation pointing to BswM_ActionLists
  ExpressionsIdx         the index of the 1:1 relation pointing to BswM_Expressions
  Id                     External id of rule.
  RuleStatesIdx          the index of the 1:1 relation pointing to BswM_RuleStates
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[26];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[12];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdClientParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdClientParameters
  \details
  Element    Description
  State  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_SdClientParametersType, BSWM_CONST) BswM_SdClientParameters[2];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdConsumedParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdConsumedParameters
  \details
  Element    Description
  State  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_SdConsumedParametersType, BSWM_CONST) BswM_SdConsumedParameters[2];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdEventHandlerMapping
**********************************************************************************************************************/
/** 
  \var    BswM_SdEventHandlerMapping
  \brief  Maps the external id of BswMSdEventHandlerCurrentState to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMSdEventHandlerCurrentState.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_SdEventHandlerMappingType, BSWM_CONST) BswM_SdEventHandlerMapping[3];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdServerParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdServerParameters
  \details
  Element    Description
  State  
  Id     
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_SdServerParametersType, BSWM_CONST) BswM_SdServerParameters[6];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SwcModeRequestUpdateFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_01
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_01[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_02
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_02[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_03
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_03[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_04
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_04[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_05
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_05[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_06
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_06[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_07
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_07[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_08
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_08[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_ActionListQueueUType, BSWM_VAR_CLEARED) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store the current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanSM_BswMCurrentStateType, BSWM_VAR_CLEARED) BswM_CanSMChannelState[2];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelState
  \brief  Variable to store the current mode of BswMComMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ModeType, BSWM_VAR_CLEARED) BswM_ComMChannelState[1];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_CLEARED) BswM_ForcedActionListPriority;
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store the current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_ModeType, BSWM_VAR_CLEARED) BswM_GenericState[1];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_InitializedType, BSWM_VAR_CLEARED) BswM_Initialized;
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_ModeRequestQueueType, BSWM_VAR_CLEARED) BswM_ModeRequestQueue[3];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store the current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_RequestResultType, BSWM_VAR_CLEARED) BswM_NvMJobState[1];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_QueueSemaphoreType, BSWM_VAR_CLEARED) BswM_QueueSemaphore;
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_QueueWrittenType, BSWM_VAR_CLEARED) BswM_QueueWritten;
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_RuleStatesUType, BSWM_VAR_CLEARED) BswM_RuleStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdClientServiceState
**********************************************************************************************************************/
/** 
  \var    BswM_SdClientServiceState
  \brief  Variable to store the current mode of BswMSdClientServiceCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ClientServiceCurrentStateType, BSWM_VAR_CLEARED) BswM_SdClientServiceState[1];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdConsumedEventState
**********************************************************************************************************************/
/** 
  \var    BswM_SdConsumedEventState
  \brief  Variable to store the current mode of BswMSdConsumedEventGroupCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ConsumedEventGroupCurrentStateType, BSWM_VAR_CLEARED) BswM_SdConsumedEventState[1];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdEventHandlerState
**********************************************************************************************************************/
/** 
  \var    BswM_SdEventHandlerState
  \brief  Variable to store the current mode of BswMSdEventHandlerCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_EventHandlerCurrentStateType, BSWM_VAR_CLEARED) BswM_SdEventHandlerState[3];
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_TimerStateUType, BSWM_VAR_CLEARED) BswM_TimerState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(BswM_TimerValueUType, BSWM_VAR_CLEARED) BswM_TimerValue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCConfig
**********************************************************************************************************************/
/** 
  \var    BswM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCConfigsType, BSWM_CONST) BswM_PCConfig;
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_01
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_01[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_02
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_02[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_03
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_03[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_04
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_04[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_05
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_05[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_06
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_06[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_07
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_07[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_08
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_08[1];
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNDECLARATIONS */


#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (BSWM_USE_INIT_POINTER == STD_ON)
extern  P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_PBCFG) BswM_ConfigPtr;
#endif

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define BswM_IsPreInitialized()                     (BswM_PreInitialized) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define BswM_SetPreInitialized(Value)               (BswM_IsPreInitialized()) = (Value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    &&&~ EXTERNAL DECLARATIONS
 ----------------------------------------------------------------------------- */

#define BSWM_START_SEC_CODE_ASIL_D
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  BswMActionFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionFunctions
 * \{
 */

/*!
 * \{
 * \brief       Executes an action.
 * \details     Generated function which executes the configured action.
 * \param[IN]   handleId      ID of the parameter set which shall be used for calling the action.
 * \param[IN]   partitionIdx  Current partition context
 * \return      E_OK      Action was successfully executed.
 * \return      E_NOT_OK  Execution of Action failed
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_GenericMode(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_TimerControl(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMAllowCom(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMModeSwitch(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdServer(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdConsumed(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdClient(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComPduGroupHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComDMHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionFunctions */
/*! \} */ /* End of group BswMActionFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */





#if (BSWM_FUNCTION_BASED == STD_OFF)
/**********************************************************************************************************************
 *  BswM_Action_ActionListHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes an action list.
 * \details     Executes all actions of an action list.
 * \param[in]   handleId  Id of the action list to execute.
 * \param[in]   partitionIdx Index of current partition Context
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ActionListHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
#endif

#if ((BSWM_RULES == STD_ON)  && (BSWM_FUNCTION_BASED == STD_OFF))
/**********************************************************************************************************************
 *  BswM_ArbitrateRule()
 **********************************************************************************************************************/
/*!
 * \brief       Arbitrates a rule.
 * \details     Evaluates the logical expression of the rule and determines the action list to execute.
 * \param[in]   ruleId  Id of the rule to arbitrate
 * \param[in]   partitionIdx  Index of current partition Context
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no action list shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(BswM_SizeOfActionListsType, BSWM_CODE) BswM_ArbitrateRule(BswM_HandleType ruleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
#endif

#if(BSWM_IMMEDIATEUSER == STD_ON)
# if (BSWM_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 *  BswM_ImmediateModeRequest()
 **********************************************************************************************************************/
/*!
 * \brief       Processes an immediate mode request.
 * \details     Queues mode request and starts arbitration of depending rules if no other request is currently active.
 * \param[in]   start   Handle of first mode request.
 * \param[in]   end     Handle of last mode request.
 * \param[in]   sid     Service Id of calling API. Only available if BSWM_DEV_ERROR_REPORT is STD_ON.
 * \param[in]   partitionIdx Index of current partition Context
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest(BswM_SizeOfImmediateUserType start, BswM_SizeOfImmediateUserType end, uint8 sid, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
# else
extern FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest(BswM_SizeOfImmediateUserType start, BswM_SizeOfImmediateUserType end, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
# endif
#endif

#define BSWM_STOP_SEC_CODE_ASIL_D
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* BSWM_PRIVATE_CFG_H */


