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
 *            Module: ComM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Private_Cfg.h
 *   Generation Time: 2026-06-07 16:44:41
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

#if !defined(COMM_PRIVATE_CFG_H)
#define COMM_PRIVATE_CFG_H
/**********************************************************************************************************************
 *  INCLUDES
**********************************************************************************************************************/
# include "ComM_Lcfg.h"

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
  \defgroup  ComMPCGetConstantDuplicatedRootDataMacros  ComM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define ComM_GetFinalMagicNumberOfPCConfig()                                                        0x0C1Eu  /**< the FinalMagicNumber to validate the size of the initialization structure at initialization time of ComM */
#define ComM_GetInitDataHashCodeOfPCConfig()                                                        -1519769143  /**< the hashcode to validate the initialization structure at initialization time of ComM */
#define ComM_GetPartitionIdentifiersOfPCConfig()                                                    ComM_PartitionIdentifiers  /**< the pointer to ComM_PartitionIdentifiers */
#define ComM_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in ComM_PartitionIdentifiers */
#define ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)                                    ComM_ActiveComMode.raw  /**< the pointer to ComM_ActiveComMode */
#define ComM_GetActivePncComModeOfPCPartitionConfig(partitionIndex)                                 ComM_ActivePncComMode  /**< the pointer to ComM_ActivePncComMode */
#define ComM_GetBusComModeReqFrShutdownOfPCPartitionConfig(partitionIndex)                          ComM_BusComModeReqFrShutdown.raw  /**< the pointer to ComM_BusComModeReqFrShutdown */
#define ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)                                    ComM_BusComModeReq.raw  /**< the pointer to ComM_BusComModeReq */
#define ComM_GetBusPncComModeReqOfPCPartitionConfig(partitionIndex)                                 ComM_BusPncComModeReq  /**< the pointer to ComM_BusPncComModeReq */
#define ComM_GetBusSleepModeIndicatedOfPCPartitionConfig(partitionIndex)                            ComM_BusSleepModeIndicated.raw  /**< the pointer to ComM_BusSleepModeIndicated */
#define ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)                                       ComM_BusSmState.raw  /**< the pointer to ComM_BusSmState */
#define ComM_GetBusTypeFrOfPCPartitionConfig()                                                      ComM_BusTypeFr  /**< the pointer to ComM_BusTypeFr */
#define ComM_GetChannelOfPCPartitionConfig()                                                        ComM_Channel  /**< the pointer to ComM_Channel */
#define ComM_GetChannelPbOfPCPartitionConfig()                                                      ComM_ChannelPb  /**< the pointer to ComM_ChannelPb */
#define ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)                                       ComM_ComAllowed.raw  /**< the pointer to ComM_ComAllowed */
#define ComM_GetCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig()                        ComM_CoordPncWithGwPassiveAndManagedChannels  /**< the pointer to ComM_CoordPncWithGwPassiveAndManagedChannels */
#define ComM_GetDcmIndicationOfPCPartitionConfig()                                                  ComM_DcmIndication  /**< the pointer to ComM_DcmIndication */
#define ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)                                 ComM_DcmRequestActive.raw  /**< the pointer to ComM_DcmRequestActive */
#define ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                              ComM_EcuMWakeUpIndicated  /**< the pointer to ComM_EcuMWakeUpIndicated */
#define ComM_GetEiraTxSignalIndirectionOfPCPartitionConfig()                                        ComM_EiraTxSignalIndirection  /**< the pointer to ComM_EiraTxSignalIndirection */
#define ComM_GetExtendedRamCheckOfPCPartitionConfig()                                               ComM_ExtendedRamCheck  /**< the pointer to ComM_ExtendedRamCheck */
#define ComM_GetForwardNmGatewayOfPCPartitionConfig(partitionIndex)                                 ComM_ForwardNmGateway.raw  /**< the pointer to ComM_ForwardNmGateway */
#define ComM_GetForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(partitionIndex)          ComM_ForwardSynchronizedPncShutdownIndicated  /**< the pointer to ComM_ForwardSynchronizedPncShutdownIndicated */
#define ComM_GetFrShutdownOfPCPartitionConfig(partitionIndex)                                       ComM_FrShutdown.raw  /**< the pointer to ComM_FrShutdown */
#define ComM_GetFullComRequestersOfPCPartitionConfig(partitionIndex)                                ComM_FullComRequesters  /**< the pointer to ComM_FullComRequesters */
#define ComM_GetFullCommRequestNotifOfPCPartitionConfig()                                           ComM_FullCommRequestNotif  /**< the pointer to ComM_FullCommRequestNotif */
#define ComM_GetFullNmTypeOfChannelOfPCPartitionConfig()                                            ComM_FullNmTypeOfChannel  /**< the pointer to ComM_FullNmTypeOfChannel */
#define ComM_GetInhibitionOfPCPartitionConfig(partitionIndex)                                       (&(ComM_Inhibition))  /**< the pointer to ComM_Inhibition */
#define ComM_GetInitStatusOfPCPartitionConfig(partitionIndex)                                       (&(ComM_InitStatus))  /**< the pointer to ComM_InitStatus */
#define ComM_GetKeepAwakeChannelsOfPCPartitionConfig()                                              ComM_KeepAwakeChannels  /**< the pointer to ComM_KeepAwakeChannels */
#define ComM_GetLastStateChangeOfPCPartitionConfig()                                                ComM_LastStateChange  /**< the pointer to ComM_LastStateChange */
#define ComM_GetLightNmTypeOfChannelOfPCPartitionConfig()                                           ComM_LightNmTypeOfChannel  /**< the pointer to ComM_LightNmTypeOfChannel */
#define ComM_GetLinslaveNmTypeOfChannelOfPCPartitionConfig()                                        ComM_LinslaveNmTypeOfChannel  /**< the pointer to ComM_LinslaveNmTypeOfChannel */
#define ComM_GetMinFullComModeTimerOfPCPartitionConfig(partitionIndex)                              ComM_MinFullComModeTimer.raw  /**< the pointer to ComM_MinFullComModeTimer */
#define ComM_GetModeLimitationOfPCPartitionConfig()                                                 ComM_ModeLimitation  /**< the pointer to ComM_ModeLimitation */
#define ComM_GetNmGwExtOfPCPartitionConfig()                                                        ComM_NmGwExt  /**< the pointer to ComM_NmGwExt */
#define ComM_GetNmLightTimerOfPCPartitionConfig(partitionIndex)                                     ComM_NmLightTimer.raw  /**< the pointer to ComM_NmLightTimer */
#define ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                               ComM_NmStartUpIndicated  /**< the pointer to ComM_NmStartUpIndicated */
#define ComM_GetNoneNmTypeOfChannelOfPCPartitionConfig()                                            ComM_NoneNmTypeOfChannel  /**< the pointer to ComM_NoneNmTypeOfChannel */
#define ComM_GetNotifyPncStateChangeOfPCPartitionConfig(partitionIndex)                             (&(ComM_NotifyPncStateChange))  /**< the pointer to ComM_NotifyPncStateChange */
#define ComM_GetNvMStoreReqOfPCPartitionConfig(partitionIndex)                                      (&(ComM_NvMStoreReq))  /**< the pointer to ComM_NvMStoreReq */
#define ComM_GetOnlyNoneNmTypeOfChannelOfPCPartitionConfig()                                        ComM_OnlyNoneNmTypeOfChannel  /**< the pointer to ComM_OnlyNoneNmTypeOfChannel */
#define ComM_GetPnc0VectorAvoidanceOfPCPartitionConfig()                                            ComM_Pnc0VectorAvoidance  /**< the pointer to ComM_Pnc0VectorAvoidance */
#define ComM_GetPncChannelMappingOfPCPartitionConfig()                                              ComM_PncChannelMapping  /**< the pointer to ComM_PncChannelMapping */
#define ComM_GetPncCheckEnabledAtRuntimeOfPCPartitionConfig()                                       ComM_PncCheckEnabledAtRuntime  /**< the pointer to ComM_PncCheckEnabledAtRuntime */
#define ComM_GetPncEiraRxCountOfPCPartitionConfig()                                                 0u  /**< Provides the number of Eira Rx signals */
#define ComM_GetPncEiraRxOfPCPartitionConfig()                                                      ComM_PncEiraRx  /**< the pointer to ComM_PncEiraRx */
#define ComM_GetPncExtendedFunctionalityOfPCPartitionConfig()                                       ComM_PncExtendedFunctionality  /**< the pointer to ComM_PncExtendedFunctionality */
#define ComM_GetPncGwTypeActiveOfPCPartitionConfig()                                                ComM_PncGwTypeActive  /**< the pointer to ComM_PncGwTypeActive */
#define ComM_GetPncGwTypeNoneOfPCPartitionConfig()                                                  ComM_PncGwTypeNone  /**< the pointer to ComM_PncGwTypeNone */
#define ComM_GetPncGwTypePassiveOfPCPartitionConfig()                                               ComM_PncGwTypePassive  /**< the pointer to ComM_PncGwTypePassive */
#define ComM_GetPncLimitationOfPCPartitionConfig(partitionIndex)                                    ComM_PncLimitation  /**< the pointer to ComM_PncLimitation */
#define ComM_GetPncOfPCPartitionConfig()                                                            ComM_Pnc  /**< the pointer to ComM_Pnc */
#define ComM_GetPncPSleepTimerOfPCPartitionConfig(partitionIndex)                                   ComM_PncPSleepTimer  /**< the pointer to ComM_PncPSleepTimer */
#define ComM_GetPncPbIndOfPCPartitionConfig()                                                       ComM_PncPbInd  /**< the pointer to ComM_PncPbInd */
#define ComM_GetPncPbOfPCPartitionConfig()                                                          ComM_PncPb  /**< the pointer to ComM_PncPb */
#define ComM_GetPncSignalIndOfPCPartitionConfig()                                                   ComM_PncSignalInd  /**< the pointer to ComM_PncSignalInd */
#define ComM_GetPncSignalOfPCPartitionConfig()                                                      ComM_PncSignal  /**< the pointer to ComM_PncSignal */
#define ComM_GetPncSignalValuesOfPCPartitionConfig(partitionIndex)                                  ComM_PncSignalValues  /**< the pointer to ComM_PncSignalValues */
#define ComM_GetPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                         ComM_PncToChannelRoutingState.raw  /**< the pointer to ComM_PncToChannelRoutingState */
#define ComM_GetPncWithoutChannelsOfPCPartitionConfig()                                             ComM_PncWithoutChannels  /**< the pointer to ComM_PncWithoutChannels */
#define ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)                                  ComM_PostInitialized  /**< the pointer to ComM_PostInitialized */
#define ComM_GetResetRequiredOfPCPartitionConfig(partitionIndex)                                    ComM_ResetRequired.raw  /**< the pointer to ComM_ResetRequired */
#define ComM_GetSimulatedSmModeOfPCPartitionConfig(partitionIndex)                                  ComM_SimulatedSmMode.raw  /**< the pointer to ComM_SimulatedSmMode */
#define ComM_GetSizeOfActivePncComModeOfPCPartitionConfig(partitionIndex)                           0u  /**< the number of accomplishable value elements in ComM_ActivePncComMode */
#define ComM_GetSizeOfBusComModeReqFrShutdownOfPCPartitionConfig(partitionIndex)                    0u  /**< the number of accomplishable value elements in ComM_BusComModeReqFrShutdown */
#define ComM_GetSizeOfBusPncComModeReqOfPCPartitionConfig(partitionIndex)                           0u  /**< the number of accomplishable value elements in ComM_BusPncComModeReq */
#define ComM_GetSizeOfBusSleepModeIndicatedOfPCPartitionConfig(partitionIndex)                      0u  /**< the number of accomplishable value elements in ComM_BusSleepModeIndicated */
#define ComM_GetSizeOfBusTypeFrOfPCPartitionConfig()                                                0u  /**< the number of accomplishable value elements in ComM_BusTypeFr */
#define ComM_GetSizeOfChannelOfPCPartitionConfig()                                                  3u  /**< the number of accomplishable value elements in ComM_Channel */
#define ComM_GetSizeOfChannelPbOfPCPartitionConfig()                                                3u  /**< the number of accomplishable value elements in ComM_ChannelPb */
#define ComM_GetSizeOfCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig()                  0u  /**< the number of accomplishable value elements in ComM_CoordPncWithGwPassiveAndManagedChannels */
#define ComM_GetSizeOfDcmIndicationOfPCPartitionConfig()                                            1u  /**< the number of accomplishable value elements in ComM_DcmIndication */
#define ComM_GetSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in ComM_EcuMWakeUpIndicated */
#define ComM_GetSizeOfEiraTxSignalIndirectionOfPCPartitionConfig()                                  0u  /**< the number of accomplishable value elements in ComM_EiraTxSignalIndirection */
#define ComM_GetSizeOfExtendedRamCheckOfPCPartitionConfig()                                         0u  /**< the number of accomplishable value elements in ComM_ExtendedRamCheck */
#define ComM_GetSizeOfForwardNmGatewayOfPCPartitionConfig(partitionIndex)                           0u  /**< the number of accomplishable value elements in ComM_ForwardNmGateway */
#define ComM_GetSizeOfForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(partitionIndex)    0u  /**< the number of accomplishable value elements in ComM_ForwardSynchronizedPncShutdownIndicated */
#define ComM_GetSizeOfFrShutdownOfPCPartitionConfig(partitionIndex)                                 0u  /**< the number of accomplishable value elements in ComM_FrShutdown */
#define ComM_GetSizeOfFullComRequestersOfPCPartitionConfig(partitionIndex)                          0u  /**< the number of accomplishable value elements in ComM_FullComRequesters */
#define ComM_GetSizeOfFullCommRequestNotifOfPCPartitionConfig()                                     0u  /**< the number of accomplishable value elements in ComM_FullCommRequestNotif */
#define ComM_GetSizeOfFullNmTypeOfChannelOfPCPartitionConfig()                                      0u  /**< the number of accomplishable value elements in ComM_FullNmTypeOfChannel */
#define ComM_GetSizeOfKeepAwakeChannelsOfPCPartitionConfig()                                        1u  /**< the number of accomplishable value elements in ComM_KeepAwakeChannels */
#define ComM_GetSizeOfLastStateChangeOfPCPartitionConfig()                                          0u  /**< the number of accomplishable value elements in ComM_LastStateChange */
#define ComM_GetSizeOfLightNmTypeOfChannelOfPCPartitionConfig()                                     0u  /**< the number of accomplishable value elements in ComM_LightNmTypeOfChannel */
#define ComM_GetSizeOfLinslaveNmTypeOfChannelOfPCPartitionConfig()                                  0u  /**< the number of accomplishable value elements in ComM_LinslaveNmTypeOfChannel */
#define ComM_GetSizeOfMinFullComModeTimerOfPCPartitionConfig(partitionIndex)                        0u  /**< the number of accomplishable value elements in ComM_MinFullComModeTimer */
#define ComM_GetSizeOfModeLimitationOfPCPartitionConfig()                                           0u  /**< the number of accomplishable value elements in ComM_ModeLimitation */
#define ComM_GetSizeOfNmGwExtOfPCPartitionConfig()                                                  0u  /**< the number of accomplishable value elements in ComM_NmGwExt */
#define ComM_GetSizeOfNmLightTimerOfPCPartitionConfig(partitionIndex)                               0u  /**< the number of accomplishable value elements in ComM_NmLightTimer */
#define ComM_GetSizeOfNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                         1u  /**< the number of accomplishable value elements in ComM_NmStartUpIndicated */
#define ComM_GetSizeOfNoneNmTypeOfChannelOfPCPartitionConfig()                                      1u  /**< the number of accomplishable value elements in ComM_NoneNmTypeOfChannel */
#define ComM_GetSizeOfOnlyNoneNmTypeOfChannelOfPCPartitionConfig()                                  1u  /**< the number of accomplishable value elements in ComM_OnlyNoneNmTypeOfChannel */
#define ComM_GetSizeOfPnc0VectorAvoidanceOfPCPartitionConfig()                                      0u  /**< the number of accomplishable value elements in ComM_Pnc0VectorAvoidance */
#define ComM_GetSizeOfPncChannelMappingOfPCPartitionConfig()                                        0u  /**< the number of accomplishable value elements in ComM_PncChannelMapping */
#define ComM_GetSizeOfPncCheckEnabledAtRuntimeOfPCPartitionConfig()                                 0u  /**< the number of accomplishable value elements in ComM_PncCheckEnabledAtRuntime */
#define ComM_GetSizeOfPncEiraRxOfPCPartitionConfig()                                                0u  /**< the number of accomplishable value elements in ComM_PncEiraRx */
#define ComM_GetSizeOfPncExtendedFunctionalityOfPCPartitionConfig()                                 0u  /**< the number of accomplishable value elements in ComM_PncExtendedFunctionality */
#define ComM_GetSizeOfPncGwTypeActiveOfPCPartitionConfig()                                          0u  /**< the number of accomplishable value elements in ComM_PncGwTypeActive */
#define ComM_GetSizeOfPncGwTypeNoneOfPCPartitionConfig()                                            0u  /**< the number of accomplishable value elements in ComM_PncGwTypeNone */
#define ComM_GetSizeOfPncGwTypePassiveOfPCPartitionConfig()                                         0u  /**< the number of accomplishable value elements in ComM_PncGwTypePassive */
#define ComM_GetSizeOfPncLimitationOfPCPartitionConfig(partitionIndex)                              0u  /**< the number of accomplishable value elements in ComM_PncLimitation */
#define ComM_GetSizeOfPncOfPCPartitionConfig()                                                      0u  /**< the number of accomplishable value elements in ComM_Pnc */
#define ComM_GetSizeOfPncPSleepTimerOfPCPartitionConfig(partitionIndex)                             0u  /**< the number of accomplishable value elements in ComM_PncPSleepTimer */
#define ComM_GetSizeOfPncPbIndOfPCPartitionConfig()                                                 0u  /**< the number of accomplishable value elements in ComM_PncPbInd */
#define ComM_GetSizeOfPncPbOfPCPartitionConfig()                                                    0u  /**< the number of accomplishable value elements in ComM_PncPb */
#define ComM_GetSizeOfPncSignalIndOfPCPartitionConfig()                                             0u  /**< the number of accomplishable value elements in ComM_PncSignalInd */
#define ComM_GetSizeOfPncSignalOfPCPartitionConfig()                                                0u  /**< the number of accomplishable value elements in ComM_PncSignal */
#define ComM_GetSizeOfPncSignalValuesOfPCPartitionConfig(partitionIndex)                            0u  /**< the number of accomplishable value elements in ComM_PncSignalValues */
#define ComM_GetSizeOfPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                   0u  /**< the number of accomplishable value elements in ComM_PncToChannelRoutingState */
#define ComM_GetSizeOfPncWithoutChannelsOfPCPartitionConfig()                                       0u  /**< the number of accomplishable value elements in ComM_PncWithoutChannels */
#define ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in ComM_PostInitialized */
#define ComM_GetSizeOfResetRequiredOfPCPartitionConfig(partitionIndex)                              0u  /**< the number of accomplishable value elements in ComM_ResetRequired */
#define ComM_GetSizeOfSimulatedSmModeOfPCPartitionConfig(partitionIndex)                            0u  /**< the number of accomplishable value elements in ComM_SimulatedSmMode */
#define ComM_GetSizeOfStateChangeOfPCPartitionConfig(partitionIndex)                                0u  /**< the number of accomplishable value elements in ComM_StateChange */
#define ComM_GetSizeOfSynchronousWakeUpOfPCPartitionConfig()                                        0u  /**< the number of accomplishable value elements in ComM_SynchronousWakeUp */
#define ComM_GetSizeOfUserByteMaskOfPCPartitionConfig()                                             3u  /**< the number of accomplishable value elements in ComM_UserByteMask */
#define ComM_GetSizeOfUserModeNotiFuncOfPCPartitionConfig()                                         0u  /**< the number of accomplishable value elements in ComM_UserModeNotiFunc */
#define ComM_GetSizeOfUserModeNotificationOnlyForPncUsersOfPCPartitionConfig()                      1u  /**< the number of accomplishable value elements in ComM_UserModeNotificationOnlyForPncUsers */
#define ComM_GetSizeOfUserOfPCPartitionConfig()                                                     3u  /**< the number of accomplishable value elements in ComM_User */
#define ComM_GetSizeOfUserPncByteMaskOfPCPartitionConfig()                                          0u  /**< the number of accomplishable value elements in ComM_UserPncByteMask */
#define ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)                             3u  /**< the number of accomplishable value elements in ComM_UserReqFullCom */
#define ComM_GetSizeOfUserReqPncFullComOfPCPartitionConfig(partitionIndex)                          0u  /**< the number of accomplishable value elements in ComM_UserReqPncFullCom */
#define ComM_GetSizeOfUserWithSinglePncOfPCPartitionConfig()                                        0u  /**< the number of accomplishable value elements in ComM_UserWithSinglePnc */
#define ComM_GetSizeOfWakeupInhibitionOfPCPartitionConfig()                                         0u  /**< the number of accomplishable value elements in ComM_WakeupInhibition */
#define ComM_GetStateChangeOfPCPartitionConfig(partitionIndex)                                      ComM_StateChange.raw  /**< the pointer to ComM_StateChange */
#define ComM_GetSynchronousWakeUpOfPCPartitionConfig()                                              ComM_SynchronousWakeUp  /**< the pointer to ComM_SynchronousWakeUp */
#define ComM_GetUserByteMaskOfPCPartitionConfig()                                                   ComM_UserByteMask  /**< the pointer to ComM_UserByteMask */
#define ComM_GetUserModeNotiFuncOfPCPartitionConfig()                                               ComM_UserModeNotiFunc  /**< the pointer to ComM_UserModeNotiFunc */
#define ComM_GetUserModeNotificationOnlyForPncUsersOfPCPartitionConfig()                            ComM_UserModeNotificationOnlyForPncUsers  /**< the pointer to ComM_UserModeNotificationOnlyForPncUsers */
#define ComM_GetUserOfPCPartitionConfig()                                                           ComM_User  /**< the pointer to ComM_User */
#define ComM_GetUserPncByteMaskOfPCPartitionConfig()                                                ComM_UserPncByteMask  /**< the pointer to ComM_UserPncByteMask */
#define ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)                                   ComM_UserReqFullCom  /**< the pointer to ComM_UserReqFullCom */
#define ComM_GetUserReqPncFullComOfPCPartitionConfig(partitionIndex)                                ComM_UserReqPncFullCom  /**< the pointer to ComM_UserReqPncFullCom */
#define ComM_GetUserWithSinglePncOfPCPartitionConfig()                                              ComM_UserWithSinglePnc  /**< the pointer to ComM_UserWithSinglePnc */
#define ComM_GetWakeupInhibitionOfPCPartitionConfig()                                               ComM_WakeupInhibition  /**< the pointer to ComM_WakeupInhibition */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDuplicatedRootDataMacros  ComM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ActiveComMode */
#define ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusComModeReq */
#define ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusSmState */
#define ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ComAllowed */
#define ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)                           ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_DcmRequestActive */
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


/* Postbuild */
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
/** 
  \defgroup  ComMPBGetRootDataMacros  ComM Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define ComM_GetLTConfigIdxOfPBConfig()                                                             0u
#define ComM_GetPBPartitionConfigOfPBConfig()                                                       NULL_PTR
#define ComM_GetPCConfigIdxOfPBConfig()                                                             0u
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */ 
/* PRQA S 3449 EXTERNALDECLARATIONS_3449 */ /* MD_ComM_3451_3449 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_Channel
**********************************************************************************************************************/
/** 
  \var    ComM_Channel
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  BusType                   The channel bus type
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_Channel[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPb
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPb
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPb[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                 Description
  PncUser                 decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMask
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element              Description
  Channel              ID of the channel which is requested by this entry.
  UserReqFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMask[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_DcmRequestActive
**********************************************************************************************************************/
/** 
  \var    ComM_DcmRequestActive
  \brief  Status of Dcm active diagnostic request, TRUE if requested, FALSE otherwise
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_DcmRequestActiveUType, COMM_VAR_NO_INIT) ComM_DcmRequestActive;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EcuMWakeUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_EcuMWakeUpIndicated
  \brief  Passive Wakeup indicated by EcuM (ComM_EcuM_WakeUpIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_EcuMWakeUpIndicatedType, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_NmStartUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_NmStartUpIndicated
  \brief  Passive Wakeup indicated by Nm (ComM_Nm_NetworkStartIndication() or ComM_Nm_RestartIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_NmStartUpIndicatedType, COMM_VAR_NO_INIT) ComM_NmStartUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[3];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNALDECLARATIONS_3449 */
/* PRQA L:EXTERNDECLARATIONS */

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


 /* VCA Disable RCH-21: VCA_COMM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

/**********************************************************************************************************************
 *  GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSizeOfInlineFunctionPrototypes  SizeOf Inline Function Prototypes
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_SizeOfActiveComModeType, COMM_CODE) ComM_GetSizeOfActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfActivePncComModeType, COMM_CODE) ComM_GetSizeOfActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusComModeReqType, COMM_CODE) ComM_GetSizeOfBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusComModeReqFrShutdownType, COMM_CODE) ComM_GetSizeOfBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusPncComModeReqType, COMM_CODE) ComM_GetSizeOfBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusSleepModeIndicatedType, COMM_CODE) ComM_GetSizeOfBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusSmStateType, COMM_CODE) ComM_GetSizeOfBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusTypeFrType, COMM_CODE) ComM_GetSizeOfBusTypeFr(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfChannelType, COMM_CODE) ComM_GetSizeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfChannelPbType, COMM_CODE) ComM_GetSizeOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfComAllowedType, COMM_CODE) ComM_GetSizeOfComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfCoordPncWithGwPassiveAndManagedChannelsType, COMM_CODE) ComM_GetSizeOfCoordPncWithGwPassiveAndManagedChannels(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfDcmIndicationType, COMM_CODE) ComM_GetSizeOfDcmIndication(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfDcmRequestActiveType, COMM_CODE) ComM_GetSizeOfDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfEcuMWakeUpIndicatedType, COMM_CODE) ComM_GetSizeOfEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfEiraTxSignalIndirectionType, COMM_CODE) ComM_GetSizeOfEiraTxSignalIndirection(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfExtendedRamCheckType, COMM_CODE) ComM_GetSizeOfExtendedRamCheck(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfForwardNmGatewayType, COMM_CODE) ComM_GetSizeOfForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfForwardSynchronizedPncShutdownIndicatedType, COMM_CODE) ComM_GetSizeOfForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFrShutdownType, COMM_CODE) ComM_GetSizeOfFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullComRequestersType, COMM_CODE) ComM_GetSizeOfFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullCommRequestNotifType, COMM_CODE) ComM_GetSizeOfFullCommRequestNotif(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfFullNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfKeepAwakeChannelsType, COMM_CODE) ComM_GetSizeOfKeepAwakeChannels(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLastStateChangeType, COMM_CODE) ComM_GetSizeOfLastStateChange(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLightNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfLightNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLinslaveNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfLinslaveNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfMinFullComModeTimerType, COMM_CODE) ComM_GetSizeOfMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfModeLimitationType, COMM_CODE) ComM_GetSizeOfModeLimitation(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmGwExtType, COMM_CODE) ComM_GetSizeOfNmGwExt(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmLightTimerType, COMM_CODE) ComM_GetSizeOfNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmStartUpIndicatedType, COMM_CODE) ComM_GetSizeOfNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNoneNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfOnlyNoneNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfOnlyNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPartitionIdentifiersType, COMM_CODE) ComM_GetSizeOfPartitionIdentifiers(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncType, COMM_CODE) ComM_GetSizeOfPnc(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPnc0VectorAvoidanceType, COMM_CODE) ComM_GetSizeOfPnc0VectorAvoidance(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncChannelMappingType, COMM_CODE) ComM_GetSizeOfPncChannelMapping(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncCheckEnabledAtRuntimeType, COMM_CODE) ComM_GetSizeOfPncCheckEnabledAtRuntime(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncEiraRxType, COMM_CODE) ComM_GetSizeOfPncEiraRx(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncExtendedFunctionalityType, COMM_CODE) ComM_GetSizeOfPncExtendedFunctionality(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypeActiveType, COMM_CODE) ComM_GetSizeOfPncGwTypeActive(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypeNoneType, COMM_CODE) ComM_GetSizeOfPncGwTypeNone(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypePassiveType, COMM_CODE) ComM_GetSizeOfPncGwTypePassive(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncLimitationType, COMM_CODE) ComM_GetSizeOfPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPSleepTimerType, COMM_CODE) ComM_GetSizeOfPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPbType, COMM_CODE) ComM_GetSizeOfPncPb(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPbIndType, COMM_CODE) ComM_GetSizeOfPncPbInd(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalType, COMM_CODE) ComM_GetSizeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalIndType, COMM_CODE) ComM_GetSizeOfPncSignalInd(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalValuesType, COMM_CODE) ComM_GetSizeOfPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncToChannelRoutingStateType, COMM_CODE) ComM_GetSizeOfPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncWithoutChannelsType, COMM_CODE) ComM_GetSizeOfPncWithoutChannels(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPostInitializedType, COMM_CODE) ComM_GetSizeOfPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfResetRequiredType, COMM_CODE) ComM_GetSizeOfResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfSimulatedSmModeType, COMM_CODE) ComM_GetSizeOfSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfStateChangeType, COMM_CODE) ComM_GetSizeOfStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfSynchronousWakeUpType, COMM_CODE) ComM_GetSizeOfSynchronousWakeUp(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserType, COMM_CODE) ComM_GetSizeOfUser(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserByteMaskType, COMM_CODE) ComM_GetSizeOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserModeNotiFuncType, COMM_CODE) ComM_GetSizeOfUserModeNotiFunc(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserModeNotificationOnlyForPncUsersType, COMM_CODE) ComM_GetSizeOfUserModeNotificationOnlyForPncUsers(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserPncByteMaskType, COMM_CODE) ComM_GetSizeOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserReqFullComType, COMM_CODE) ComM_GetSizeOfUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserReqPncFullComType, COMM_CODE) ComM_GetSizeOfUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserWithSinglePncType, COMM_CODE) ComM_GetSizeOfUserWithSinglePnc(void);
COMM_LOCAL_INLINE FUNC(ComM_SizeOfWakeupInhibitionType, COMM_CODE) ComM_GetSizeOfWakeupInhibition(void);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetDataInlineFunctionPrototypes  Get Data Inline Function Prototypes
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncModeType, COMM_CODE) ComM_GetActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncModeType, COMM_CODE) ComM_GetBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_BusSleepModeIndicatedType, COMM_CODE) ComM_IsBusSleepModeIndicated(ComM_BusSleepModeIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ModeType, COMM_CODE) ComM_GetBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_BusTypeFrType, COMM_CODE) ComM_IsBusTypeFr(ComM_BusTypeFrIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_BusType, COMM_CODE) ComM_GetBusTypeOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(GetCurrentBusSMModeApiType, COMM_CODE) ComM_GetGetCurrentBusSMModeApiOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_InvalidHndOfChannelType, COMM_CODE) ComM_IsInvalidHndOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_J1939SupportOfChannelType, COMM_CODE) ComM_IsJ1939SupportOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_MainFunctionNeedsSyncOfChannelType, COMM_CODE) ComM_IsMainFunctionNeedsSyncOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ManagingChannelOfChannelType, COMM_CODE) ComM_IsManagingChannelOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ManagingUserOfChannelType, COMM_CODE) ComM_GetManagingUserOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_MinFullComTimeOfChannelType, COMM_CODE) ComM_GetMinFullComTimeOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmLightDurationOfChannelType, COMM_CODE) ComM_GetNmLightDurationOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmLightSilentDurationOfChannelType, COMM_CODE) ComM_GetNmLightSilentDurationOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmSupportOfChannelType, COMM_CODE) ComM_IsNmSupportOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PassiveOrLinSlaveOfChannelType, COMM_CODE) ComM_IsPassiveOrLinSlaveOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncNmRequestOfChannelType, COMM_CODE) ComM_IsPncNmRequestOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(RequestBusSMModeApiType, COMM_CODE) ComM_GetRequestBusSMModeApiOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ResetAfterForcingNoCommOfChannelType, COMM_CODE) ComM_IsResetAfterForcingNoCommOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SilentSupportOfChannelType, COMM_CODE) ComM_IsSilentSupportOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_InvalidHndOfChannelPbType, COMM_CODE) ComM_IsInvalidHndOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationEndIdxOfChannelPbType, COMM_CODE) ComM_GetPncLimitationEndIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationStartIdxOfChannelPbType, COMM_CODE) ComM_GetPncLimitationStartIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationUsedOfChannelPbType, COMM_CODE) ComM_IsPncLimitationUsedOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndEndIdxOfChannelPbType, COMM_CODE) ComM_GetPncPbIndEndIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndStartIdxOfChannelPbType, COMM_CODE) ComM_GetPncPbIndStartIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndUsedOfChannelPbType, COMM_CODE) ComM_IsPncPbIndUsedOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComEndIdxOfChannelPbType, COMM_CODE) ComM_GetUserReqFullComEndIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComStartIdxOfChannelPbType, COMM_CODE) ComM_GetUserReqFullComStartIdxOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ComAllowedType, COMM_CODE) ComM_IsComAllowed(ComM_ComAllowedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_CoordPncWithGwPassiveAndManagedChannelsType, COMM_CODE) ComM_IsCoordPncWithGwPassiveAndManagedChannels(ComM_CoordPncWithGwPassiveAndManagedChannelsIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_DcmRequestActiveType, COMM_CODE) ComM_IsDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_EcuMWakeUpIndicatedType, COMM_CODE) ComM_IsEcuMWakeUpIndicated(ComM_EcuMWakeUpIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ExtendedRamCheckType, COMM_CODE) ComM_IsExtendedRamCheck(ComM_ExtendedRamCheckIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ForwardNmGatewayType, COMM_CODE) ComM_IsForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ForwardSynchronizedPncShutdownIndicatedType, COMM_CODE) ComM_IsForwardSynchronizedPncShutdownIndicated(ComM_ForwardSynchronizedPncShutdownIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_FrShutdownType, COMM_CODE) ComM_IsFrShutdown(ComM_FrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_FullComRequestersType, COMM_CODE) ComM_GetFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_FullCommRequestNotifType, COMM_CODE) ComM_IsFullCommRequestNotif(ComM_FullCommRequestNotifIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_FullNmTypeOfChannelType, COMM_CODE) ComM_IsFullNmTypeOfChannel(ComM_FullNmTypeOfChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_InhibitionType, COMM_CODE) ComM_GetInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_InitStatusType, COMM_CODE) ComM_GetInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ModeType, COMM_CODE) ComM_GetLastStateChange(ComM_LastStateChangeIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_LightNmTypeOfChannelType, COMM_CODE) ComM_IsLightNmTypeOfChannel(ComM_LightNmTypeOfChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_LinslaveNmTypeOfChannelType, COMM_CODE) ComM_IsLinslaveNmTypeOfChannel(ComM_LinslaveNmTypeOfChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_MinFullComModeTimerType, COMM_CODE) ComM_GetMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ModeLimitationType, COMM_CODE) ComM_IsModeLimitation(ComM_ModeLimitationIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmGwExtType, COMM_CODE) ComM_IsNmGwExt(ComM_NmGwExtIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmLightTimerType, COMM_CODE) ComM_GetNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_NmStartUpIndicatedType, COMM_CODE) ComM_IsNmStartUpIndicated(ComM_NmStartUpIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_NotifyPncStateChangeType, COMM_CODE) ComM_IsNotifyPncStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_NvMStoreReqType, COMM_CODE) ComM_IsNvMStoreReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType, COMM_CODE) ComM_GetPCPartitionConfigIdxOfPartitionIdentifiers(ComM_PartitionIdentifiersIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PartitionSNVOfPartitionIdentifiersType, COMM_CODE) ComM_GetPartitionSNVOfPartitionIdentifiers(ComM_PartitionIdentifiersIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfPncType, COMM_CODE) ComM_GetClearMaskOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_CoordinatedOfPncType, COMM_CODE) ComM_IsCoordinatedOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_IntermediatePncCoordinatorOfPncType, COMM_CODE) ComM_IsIntermediatePncCoordinatorOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncIdOfPncType, COMM_CODE) ComM_GetPncIdOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfPncType, COMM_CODE) ComM_GetSetMaskOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SystemUserOfPncType, COMM_CODE) ComM_GetSystemUserOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_TopLevelPncCoordinatorOfPncType, COMM_CODE) ComM_IsTopLevelPncCoordinatorOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_WakeupEnabledOfPncType, COMM_CODE) ComM_IsWakeupEnabledOfPnc(ComM_PncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_Pnc0VectorAvoidanceType, COMM_CODE) ComM_IsPnc0VectorAvoidance(ComM_Pnc0VectorAvoidanceIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingType, COMM_CODE) ComM_GetPncChannelMapping(ComM_PncChannelMappingIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncCheckEnabledAtRuntimeType, COMM_CODE) ComM_IsPncCheckEnabledAtRuntime(ComM_PncCheckEnabledAtRuntimeIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncEiraRxType, COMM_CODE) ComM_IsPncEiraRx(ComM_PncEiraRxIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncExtendedFunctionalityType, COMM_CODE) ComM_IsPncExtendedFunctionality(ComM_PncExtendedFunctionalityIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypeActiveType, COMM_CODE) ComM_IsPncGwTypeActive(ComM_PncGwTypeActiveIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypeNoneType, COMM_CODE) ComM_IsPncGwTypeNone(ComM_PncGwTypeNoneIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypePassiveType, COMM_CODE) ComM_IsPncGwTypePassive(ComM_PncGwTypePassiveIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationType, COMM_CODE) ComM_GetPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncPSleepTimerType, COMM_CODE) ComM_GetPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingEndIdxOfPncPbType, COMM_CODE) ComM_GetPncChannelMappingEndIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingStartIdxOfPncPbType, COMM_CODE) ComM_GetPncChannelMappingStartIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingUsedOfPncPbType, COMM_CODE) ComM_IsPncChannelMappingUsedOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndEndIdxOfPncPbType, COMM_CODE) ComM_GetPncSignalIndEndIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndStartIdxOfPncPbType, COMM_CODE) ComM_GetPncSignalIndStartIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndUsedOfPncPbType, COMM_CODE) ComM_IsPncSignalIndUsedOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SignalByteIndexOfPncPbType, COMM_CODE) ComM_GetSignalByteIndexOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComEndIdxOfPncPbType, COMM_CODE) ComM_GetUserReqPncFullComEndIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComStartIdxOfPncPbType, COMM_CODE) ComM_GetUserReqPncFullComStartIdxOfPncPb(ComM_PncPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndType, COMM_CODE) ComM_GetPncPbInd(ComM_PncPbIndIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_BusTypeIdOfPncSignalType, COMM_CODE) ComM_GetBusTypeIdOfPncSignal(ComM_PncSignalIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ChannelIdxOfPncSignalType, COMM_CODE) ComM_GetChannelIdxOfPncSignal(ComM_PncSignalIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ChannelUsedOfPncSignalType, COMM_CODE) ComM_IsChannelUsedOfPncSignal(ComM_PncSignalIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_TypeOfPncSignalType, COMM_CODE) ComM_GetTypeOfPncSignal(ComM_PncSignalIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndType, COMM_CODE) ComM_GetPncSignalInd(ComM_PncSignalIndIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalValuesType, COMM_CODE) ComM_GetPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncToChannelRoutingStateType, COMM_CODE) ComM_GetPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncWithoutChannelsType, COMM_CODE) ComM_IsPncWithoutChannels(ComM_PncWithoutChannelsIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PostInitializedType, COMM_CODE) ComM_IsPostInitialized(ComM_PostInitializedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ResetRequiredType, COMM_CODE) ComM_IsResetRequired(ComM_ResetRequiredIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SimulatedSmModeType, COMM_CODE) ComM_GetSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_StateChangeType, COMM_CODE) ComM_GetStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_SynchronousWakeUpType, COMM_CODE) ComM_IsSynchronousWakeUp(ComM_SynchronousWakeUpIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncUserOfUserType, COMM_CODE) ComM_IsPncUserOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskEndIdxOfUserType, COMM_CODE) ComM_GetUserByteMaskEndIdxOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskStartIdxOfUserType, COMM_CODE) ComM_GetUserByteMaskStartIdxOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskEndIdxOfUserType, COMM_CODE) ComM_GetUserPncByteMaskEndIdxOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskLengthOfUserType, COMM_CODE) ComM_GetUserPncByteMaskLengthOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskStartIdxOfUserType, COMM_CODE) ComM_GetUserPncByteMaskStartIdxOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskUsedOfUserType, COMM_CODE) ComM_IsUserPncByteMaskUsedOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ChannelOfUserByteMaskType, COMM_CODE) ComM_GetChannelOfUserByteMask(ComM_UserByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComIdxOfUserByteMaskType, COMM_CODE) ComM_GetUserReqFullComIdxOfUserByteMask(ComM_UserByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_StateNotiFuncPtrType, COMM_CODE) ComM_GetUserModeNotiFunc(ComM_UserModeNotiFuncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfUserPncByteMaskType, COMM_CODE) ComM_GetClearMaskOfUserPncByteMask(ComM_UserPncByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncIDOfUserPncByteMaskType, COMM_CODE) ComM_GetPncIDOfUserPncByteMask(ComM_UserPncByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncIdxOfUserPncByteMaskType, COMM_CODE) ComM_GetPncIdxOfUserPncByteMask(ComM_UserPncByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfUserPncByteMaskType, COMM_CODE) ComM_GetSetMaskOfUserPncByteMask(ComM_UserPncByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComIdxOfUserPncByteMaskType, COMM_CODE) ComM_GetUserReqPncFullComIdxOfUserPncByteMask(ComM_UserPncByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComType, COMM_CODE) ComM_GetUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComType, COMM_CODE) ComM_GetUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_UserWithSinglePncType, COMM_CODE) ComM_IsUserWithSinglePnc(ComM_UserWithSinglePncIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_WakeupInhibitionType, COMM_CODE) ComM_IsWakeupInhibition(ComM_WakeupInhibitionIterType Index);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetDeduplicatedInlineFunctionPrototypes  Get Deduplicated Inline Function Prototypes
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_GwTypeOfChannelType, COMM_CODE) ComM_GetGwTypeOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_InhibitionInitValueOfChannelType, COMM_CODE) ComM_GetInhibitionInitValueOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ManagingChannelIdOfChannelType, COMM_CODE) ComM_GetManagingChannelIdOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NmTypeOfChannelType, COMM_CODE) ComM_GetNmTypeOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PartitionConfigIdxOfChannelType, COMM_CODE) ComM_GetPartitionConfigIdxOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_WakeupStateOfChannelType, COMM_CODE) ComM_GetWakeupStateOfChannel(ComM_ChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComUsedOfChannelPbType, COMM_CODE) ComM_IsUserReqFullComUsedOfChannelPb(ComM_ChannelPbIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_DcmIndicationType, COMM_CODE) ComM_IsDcmIndication(ComM_DcmIndicationIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_FinalMagicNumberType, COMM_CODE) ComM_GetFinalMagicNumber(void);
COMM_LOCAL_INLINE FUNC(ComM_InitDataHashCodeType, COMM_CODE) ComM_GetInitDataHashCode(void);
COMM_LOCAL_INLINE FUNC(ComM_KeepAwakeChannelsType, COMM_CODE) ComM_IsKeepAwakeChannels(ComM_KeepAwakeChannelsIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_NoneNmTypeOfChannelType, COMM_CODE) ComM_IsNoneNmTypeOfChannel(ComM_NoneNmTypeOfChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_OnlyNoneNmTypeOfChannelType, COMM_CODE) ComM_IsOnlyNoneNmTypeOfChannel(ComM_OnlyNoneNmTypeOfChannelIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_PncEiraRxCountType, COMM_CODE) ComM_GetPncEiraRxCount(void);
COMM_LOCAL_INLINE FUNC(ComM_PartitionConfigIdxOfUserType, COMM_CODE) ComM_GetPartitionConfigIdxOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskUsedOfUserType, COMM_CODE) ComM_IsUserByteMaskUsedOfUser(ComM_UserIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfUserByteMaskType, COMM_CODE) ComM_GetClearMaskOfUserByteMask(ComM_UserByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfUserByteMaskType, COMM_CODE) ComM_GetSetMaskOfUserByteMask(ComM_UserByteMaskIterType Index);
COMM_LOCAL_INLINE FUNC(ComM_UserModeNotificationOnlyForPncUsersType, COMM_CODE) ComM_IsUserModeNotificationOnlyForPncUsers(ComM_UserModeNotificationOnlyForPncUsersIterType Index);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSetDataInlineFunctionPrototypes  Set Data Inline Function Prototypes
  \brief  These inline functions can be used to write data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusSleepModeIndicated(ComM_BusSleepModeIndicatedIterType Index, ComM_BusSleepModeIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetComAllowed(ComM_ComAllowedIterType Index, ComM_ComAllowedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_DcmRequestActiveType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetEcuMWakeUpIndicated(ComM_EcuMWakeUpIndicatedIterType Index, ComM_EcuMWakeUpIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_ForwardNmGatewayType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetForwardSynchronizedPncShutdownIndicated(ComM_ForwardSynchronizedPncShutdownIndicatedIterType Index, ComM_ForwardSynchronizedPncShutdownIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetFrShutdown(ComM_FrShutdownIterType Index, ComM_FrShutdownType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetInhibition(ComM_InhibitionType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNmStartUpIndicated(ComM_NmStartUpIndicatedIterType Index, ComM_NmStartUpIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNotifyPncStateChange(ComM_NotifyPncStateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNvMStoreReq(ComM_NvMStoreReqType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPostInitialized(ComM_PostInitializedIterType Index, ComM_PostInitializedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetResetRequired(ComM_ResetRequiredIterType Index, ComM_ResetRequiredType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetAddressOfDataInlineFunctionPrototypes  Get Address Of Data Inline Function Prototypes
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_ActiveComModePtrType, COMM_CODE) ComM_GetAddrActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_BusComModeReqFrShutdownPtrType, COMM_CODE) ComM_GetAddrBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_DcmRequestActivePtrType, COMM_CODE) ComM_GetAddrDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_ForwardNmGatewayPtrType, COMM_CODE) ComM_GetAddrForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_InhibitionPtrType, COMM_CODE) ComM_GetAddrInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_MinFullComModeTimerPtrType, COMM_CODE) ComM_GetAddrMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_PncSignalValuesPtrType, COMM_CODE) ComM_GetAddrPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(ComM_StateChangePtrType, COMM_CODE) ComM_GetAddrStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeFr(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasGetCurrentBusSMModeApiOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasGwTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibitionInitValueOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInvalidHndOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasJ1939SupportOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMainFunctionNeedsSyncOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingChannelIdOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingChannelOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingUserOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComTimeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightDurationOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightSilentDurationOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmSupportOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionConfigIdxOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPassiveOrLinSlaveOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncNmRequestOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasRequestBusSMModeApiOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetAfterForcingNoCommOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSilentSupportOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupStateOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInvalidHndOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationEndIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationStartIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationUsedOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndEndIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndStartIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndUsedOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComEndIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComStartIdxOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComUsedOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordPncWithGwPassiveAndManagedChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmIndication(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEiraTxSignalIndirection(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasExtendedRamCheck(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFinalMagicNumber(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullCommRequestNotif(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitDataHashCode(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasKeepAwakeChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLastStateChange(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLightNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLinslaveNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasModeLimitation(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmGwExt(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNotifyPncStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNvMStoreReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasOnlyNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionIdentifiers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfigIdxOfPartitionIdentifiers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionSNVOfPartitionIdentifiers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordinatedOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasIntermediatePncCoordinatorOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIdOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSystemUserOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasTopLevelPncCoordinatorOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupEnabledOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc0VectorAvoidance(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMapping(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncCheckEnabledAtRuntime(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRx(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxCount(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncExtendedFunctionality(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeActive(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeNone(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypePassive(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingEndIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingStartIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingUsedOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndEndIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndStartIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndUsedOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSignalByteIndexOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComEndIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComStartIdxOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbInd(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeIdOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelIdxOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelUsedOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasTypeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalInd(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncWithoutChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusTypeFr(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfCoordPncWithGwPassiveAndManagedChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmIndication(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEiraTxSignalIndirection(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfExtendedRamCheck(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullCommRequestNotif(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfKeepAwakeChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLastStateChange(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLightNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLinslaveNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfModeLimitation(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmGwExt(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfOnlyNoneNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPartitionIdentifiers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc0VectorAvoidance(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncChannelMapping(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncCheckEnabledAtRuntime(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncEiraRx(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncExtendedFunctionality(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeActive(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeNone(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypePassive(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPb(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbInd(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalInd(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncWithoutChannels(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSynchronousWakeUp(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotiFunc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotificationOnlyForPncUsers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserWithSinglePnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfWakeupInhibition(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSynchronousWakeUp(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionConfigIdxOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncUserOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskEndIdxOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskStartIdxOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskUsedOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskEndIdxOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskLengthOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskStartIdxOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskUsedOfUser(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComIdxOfUserByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotiFunc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotificationOnlyForPncUsers(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIDOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIdxOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComIdxOfUserPncByteMask(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserWithSinglePnc(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupInhibition(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFinalMagicNumberOfPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitDataHashCodeOfPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfigOfPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionIdentifiersOfPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPartitionIdentifiersOfPCConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActiveComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActivePncComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusPncComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSleepModeIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSmStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeFrOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelPbOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasComAllowedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmIndicationOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmRequestActiveOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEcuMWakeUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEiraTxSignalIndirectionOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasExtendedRamCheckOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardNmGatewayOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullComRequestersOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullCommRequestNotifOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibitionOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitStatusOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasKeepAwakeChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLastStateChangeOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLightNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLinslaveNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComModeTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasModeLimitationOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmGwExtOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmStartUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNoneNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNotifyPncStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNvMStoreReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasOnlyNoneNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc0VectorAvoidanceOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncCheckEnabledAtRuntimeOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxCountOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncExtendedFunctionalityOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeActiveOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeNoneOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypePassiveOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPSleepTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalValuesOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncToChannelRoutingStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncWithoutChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPostInitializedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetRequiredOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSimulatedSmModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActiveComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActivePncComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusPncComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSleepModeIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSmStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusTypeFrOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelPbOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfComAllowedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmIndicationOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmRequestActiveOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEiraTxSignalIndirectionOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfExtendedRamCheckOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardNmGatewayOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullComRequestersOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullCommRequestNotifOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfKeepAwakeChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLastStateChangeOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLightNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLinslaveNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfMinFullComModeTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfModeLimitationOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmGwExtOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmLightTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmStartUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNoneNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfOnlyNoneNmTypeOfChannelOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc0VectorAvoidanceOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncChannelMappingOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncCheckEnabledAtRuntimeOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncEiraRxOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncExtendedFunctionalityOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeActiveOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeNoneOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypePassiveOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncLimitationOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPSleepTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbIndOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalIndOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalValuesOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncToChannelRoutingStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncWithoutChannelsOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPostInitializedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfResetRequiredOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSimulatedSmModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSynchronousWakeUpOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserByteMaskOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotiFuncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotificationOnlyForPncUsersOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserPncByteMaskOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqPncFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserWithSinglePncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfWakeupInhibitionOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSynchronousWakeUpOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotiFuncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotificationOnlyForPncUsersOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserWithSinglePncOfPCPartitionConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupInhibitionOfPCPartitionConfig(void);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCEsistsEnumInlineFunctionPrototypes  Esists Enum Inline Function Prototypes
  \brief  These inilne functions can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNOT_USED_IN_THIS_VARIANTNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsFULLNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsPASSIVENmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsLIGHTNmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNONENmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsLINSLAVENmTypeOfChannel(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsEIRA_RXTypeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsEIRA_TXTypeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsERA_RXTypeOfPncSignal(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNOT_USED_IN_THIS_VARIANTTypeOfPncSignal(void);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCIncrementInlineFunctionPrototypes  Increment Inline Function Prototypes
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncLastStateChange(ComM_LastStateChangeIterType Index);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCDecrementInlineFunctionPrototypes  Decrement Inline Function Prototypes
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecLastStateChange(ComM_LastStateChangeIterType Index);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCAddInlineFunctionPrototypes  Add Inline Function Prototypes
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSubstractInlineFunctionPrototypes  Substract Inline Function Prototypes
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMLTHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTPartitionConfigOfLTConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTPartitionConfig(void);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPBHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTConfigIdxOfPBConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBPartitionConfigOfPBConfig(void);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCConfigIdxOfPBConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex);
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBPartitionConfig(void);
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
 *  INTERNAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSizeOfInlineFunctions  ComM SizeOf Inline Functions (PRE_COMPILE)
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_SizeOfActiveComModeType, COMM_CODE) ComM_GetSizeOfActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfActiveComModeType) ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfActivePncComModeType, COMM_CODE) ComM_GetSizeOfActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfActivePncComModeType) ComM_GetSizeOfActivePncComModeOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusComModeReqType, COMM_CODE) ComM_GetSizeOfBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfBusComModeReqType) ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusComModeReqFrShutdownType, COMM_CODE) ComM_GetSizeOfBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfBusComModeReqFrShutdownType) ComM_GetSizeOfBusComModeReqFrShutdownOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusPncComModeReqType, COMM_CODE) ComM_GetSizeOfBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfBusPncComModeReqType) ComM_GetSizeOfBusPncComModeReqOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusSleepModeIndicatedType, COMM_CODE) ComM_GetSizeOfBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfBusSleepModeIndicatedType) ComM_GetSizeOfBusSleepModeIndicatedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusSmStateType, COMM_CODE) ComM_GetSizeOfBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfBusSmStateType) ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfBusTypeFrType, COMM_CODE) ComM_GetSizeOfBusTypeFr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfBusTypeFrType) ComM_GetSizeOfBusTypeFrOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfChannelType, COMM_CODE) ComM_GetSizeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfChannelType) ComM_GetSizeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfChannelPbType, COMM_CODE) ComM_GetSizeOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfChannelPbType) ComM_GetSizeOfChannelPbOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfComAllowedType, COMM_CODE) ComM_GetSizeOfComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfComAllowedType) ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfCoordPncWithGwPassiveAndManagedChannelsType, COMM_CODE) ComM_GetSizeOfCoordPncWithGwPassiveAndManagedChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfCoordPncWithGwPassiveAndManagedChannelsType) ComM_GetSizeOfCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfDcmIndicationType, COMM_CODE) ComM_GetSizeOfDcmIndication(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfDcmIndicationType) ComM_GetSizeOfDcmIndicationOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfDcmRequestActiveType, COMM_CODE) ComM_GetSizeOfDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfDcmRequestActiveType) ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfEcuMWakeUpIndicatedType, COMM_CODE) ComM_GetSizeOfEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfEcuMWakeUpIndicatedType) ComM_GetSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfEiraTxSignalIndirectionType, COMM_CODE) ComM_GetSizeOfEiraTxSignalIndirection(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfEiraTxSignalIndirectionType) ComM_GetSizeOfEiraTxSignalIndirectionOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfExtendedRamCheckType, COMM_CODE) ComM_GetSizeOfExtendedRamCheck(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfExtendedRamCheckType) ComM_GetSizeOfExtendedRamCheckOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfForwardNmGatewayType, COMM_CODE) ComM_GetSizeOfForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfForwardNmGatewayType) ComM_GetSizeOfForwardNmGatewayOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfForwardSynchronizedPncShutdownIndicatedType, COMM_CODE) ComM_GetSizeOfForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfForwardSynchronizedPncShutdownIndicatedType) ComM_GetSizeOfForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFrShutdownType, COMM_CODE) ComM_GetSizeOfFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfFrShutdownType) ComM_GetSizeOfFrShutdownOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullComRequestersType, COMM_CODE) ComM_GetSizeOfFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfFullComRequestersType) ComM_GetSizeOfFullComRequestersOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullCommRequestNotifType, COMM_CODE) ComM_GetSizeOfFullCommRequestNotif(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfFullCommRequestNotifType) ComM_GetSizeOfFullCommRequestNotifOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfFullNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfFullNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfFullNmTypeOfChannelType) ComM_GetSizeOfFullNmTypeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfKeepAwakeChannelsType, COMM_CODE) ComM_GetSizeOfKeepAwakeChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfKeepAwakeChannelsType) ComM_GetSizeOfKeepAwakeChannelsOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLastStateChangeType, COMM_CODE) ComM_GetSizeOfLastStateChange(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfLastStateChangeType) ComM_GetSizeOfLastStateChangeOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLightNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfLightNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfLightNmTypeOfChannelType) ComM_GetSizeOfLightNmTypeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfLinslaveNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfLinslaveNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfLinslaveNmTypeOfChannelType) ComM_GetSizeOfLinslaveNmTypeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfMinFullComModeTimerType, COMM_CODE) ComM_GetSizeOfMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfMinFullComModeTimerType) ComM_GetSizeOfMinFullComModeTimerOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfModeLimitationType, COMM_CODE) ComM_GetSizeOfModeLimitation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfModeLimitationType) ComM_GetSizeOfModeLimitationOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmGwExtType, COMM_CODE) ComM_GetSizeOfNmGwExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfNmGwExtType) ComM_GetSizeOfNmGwExtOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmLightTimerType, COMM_CODE) ComM_GetSizeOfNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfNmLightTimerType) ComM_GetSizeOfNmLightTimerOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNmStartUpIndicatedType, COMM_CODE) ComM_GetSizeOfNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfNmStartUpIndicatedType) ComM_GetSizeOfNmStartUpIndicatedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfNoneNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfNoneNmTypeOfChannelType) ComM_GetSizeOfNoneNmTypeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfOnlyNoneNmTypeOfChannelType, COMM_CODE) ComM_GetSizeOfOnlyNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfOnlyNoneNmTypeOfChannelType) ComM_GetSizeOfOnlyNoneNmTypeOfChannelOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPartitionIdentifiersType, COMM_CODE) ComM_GetSizeOfPartitionIdentifiers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPartitionIdentifiersType) ComM_GetSizeOfPartitionIdentifiersOfPCConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncType, COMM_CODE) ComM_GetSizeOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncType) ComM_GetSizeOfPncOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPnc0VectorAvoidanceType, COMM_CODE) ComM_GetSizeOfPnc0VectorAvoidance(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPnc0VectorAvoidanceType) ComM_GetSizeOfPnc0VectorAvoidanceOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncChannelMappingType, COMM_CODE) ComM_GetSizeOfPncChannelMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncChannelMappingType) ComM_GetSizeOfPncChannelMappingOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncCheckEnabledAtRuntimeType, COMM_CODE) ComM_GetSizeOfPncCheckEnabledAtRuntime(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncCheckEnabledAtRuntimeType) ComM_GetSizeOfPncCheckEnabledAtRuntimeOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncEiraRxType, COMM_CODE) ComM_GetSizeOfPncEiraRx(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncEiraRxType) ComM_GetSizeOfPncEiraRxOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncExtendedFunctionalityType, COMM_CODE) ComM_GetSizeOfPncExtendedFunctionality(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncExtendedFunctionalityType) ComM_GetSizeOfPncExtendedFunctionalityOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypeActiveType, COMM_CODE) ComM_GetSizeOfPncGwTypeActive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncGwTypeActiveType) ComM_GetSizeOfPncGwTypeActiveOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypeNoneType, COMM_CODE) ComM_GetSizeOfPncGwTypeNone(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncGwTypeNoneType) ComM_GetSizeOfPncGwTypeNoneOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncGwTypePassiveType, COMM_CODE) ComM_GetSizeOfPncGwTypePassive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncGwTypePassiveType) ComM_GetSizeOfPncGwTypePassiveOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncLimitationType, COMM_CODE) ComM_GetSizeOfPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfPncLimitationType) ComM_GetSizeOfPncLimitationOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPSleepTimerType, COMM_CODE) ComM_GetSizeOfPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfPncPSleepTimerType) ComM_GetSizeOfPncPSleepTimerOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPbType, COMM_CODE) ComM_GetSizeOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncPbType) ComM_GetSizeOfPncPbOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncPbIndType, COMM_CODE) ComM_GetSizeOfPncPbInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncPbIndType) ComM_GetSizeOfPncPbIndOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalType, COMM_CODE) ComM_GetSizeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncSignalType) ComM_GetSizeOfPncSignalOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalIndType, COMM_CODE) ComM_GetSizeOfPncSignalInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncSignalIndType) ComM_GetSizeOfPncSignalIndOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncSignalValuesType, COMM_CODE) ComM_GetSizeOfPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfPncSignalValuesType) ComM_GetSizeOfPncSignalValuesOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncToChannelRoutingStateType, COMM_CODE) ComM_GetSizeOfPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfPncToChannelRoutingStateType) ComM_GetSizeOfPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPncWithoutChannelsType, COMM_CODE) ComM_GetSizeOfPncWithoutChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfPncWithoutChannelsType) ComM_GetSizeOfPncWithoutChannelsOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfPostInitializedType, COMM_CODE) ComM_GetSizeOfPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfPostInitializedType) ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfResetRequiredType, COMM_CODE) ComM_GetSizeOfResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfResetRequiredType) ComM_GetSizeOfResetRequiredOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfSimulatedSmModeType, COMM_CODE) ComM_GetSizeOfSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfSimulatedSmModeType) ComM_GetSizeOfSimulatedSmModeOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfStateChangeType, COMM_CODE) ComM_GetSizeOfStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfStateChangeType) ComM_GetSizeOfStateChangeOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfSynchronousWakeUpType, COMM_CODE) ComM_GetSizeOfSynchronousWakeUp(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfSynchronousWakeUpType) ComM_GetSizeOfSynchronousWakeUpOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserType, COMM_CODE) ComM_GetSizeOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserType) ComM_GetSizeOfUserOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserByteMaskType, COMM_CODE) ComM_GetSizeOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserByteMaskType) ComM_GetSizeOfUserByteMaskOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserModeNotiFuncType, COMM_CODE) ComM_GetSizeOfUserModeNotiFunc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserModeNotiFuncType) ComM_GetSizeOfUserModeNotiFuncOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserModeNotificationOnlyForPncUsersType, COMM_CODE) ComM_GetSizeOfUserModeNotificationOnlyForPncUsers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserModeNotificationOnlyForPncUsersType) ComM_GetSizeOfUserModeNotificationOnlyForPncUsersOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserPncByteMaskType, COMM_CODE) ComM_GetSizeOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserPncByteMaskType) ComM_GetSizeOfUserPncByteMaskOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserReqFullComType, COMM_CODE) ComM_GetSizeOfUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfUserReqFullComType) ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserReqPncFullComType, COMM_CODE) ComM_GetSizeOfUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SizeOfUserReqPncFullComType) ComM_GetSizeOfUserReqPncFullComOfPCPartitionConfig(partitionIndex);
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfUserWithSinglePncType, COMM_CODE) ComM_GetSizeOfUserWithSinglePnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfUserWithSinglePncType) ComM_GetSizeOfUserWithSinglePncOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_SizeOfWakeupInhibitionType, COMM_CODE) ComM_GetSizeOfWakeupInhibition(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_SizeOfWakeupInhibitionType) ComM_GetSizeOfWakeupInhibitionOfPCPartitionConfig();
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetDataInlineFunctions  ComM Get Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateType) (ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)]);
}
COMM_LOCAL_INLINE FUNC(ComM_PncModeType, COMM_CODE) ComM_GetActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncModeType) (0xFFu);
}
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateType) (ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)]);
}
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_GetBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateType) (0xFFu);
}
COMM_LOCAL_INLINE FUNC(ComM_PncModeType, COMM_CODE) ComM_GetBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncModeType) (0xFFu);
}
COMM_LOCAL_INLINE FUNC(ComM_BusSleepModeIndicatedType, COMM_CODE) ComM_IsBusSleepModeIndicated(ComM_BusSleepModeIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_BusSleepModeIndicatedType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ModeType, COMM_CODE) ComM_GetBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ModeType) (ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)]);
}
COMM_LOCAL_INLINE FUNC(ComM_BusTypeFrType, COMM_CODE) ComM_IsBusTypeFr(ComM_BusTypeFrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_BusTypeFrType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_BusType, COMM_CODE) ComM_GetBusTypeOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_BusType) (ComM_GetChannelOfPCPartitionConfig()[(Index)].BusTypeOfChannel);
}
COMM_LOCAL_INLINE FUNC(GetCurrentBusSMModeApiType, COMM_CODE) ComM_GetGetCurrentBusSMModeApiOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (GetCurrentBusSMModeApiType) (ComM_GetChannelOfPCPartitionConfig()[(Index)].GetCurrentBusSMModeApiOfChannel);
}
COMM_LOCAL_INLINE FUNC(ComM_InvalidHndOfChannelType, COMM_CODE) ComM_IsInvalidHndOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_InvalidHndOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_J1939SupportOfChannelType, COMM_CODE) ComM_IsJ1939SupportOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_J1939SupportOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_MainFunctionNeedsSyncOfChannelType, COMM_CODE) ComM_IsMainFunctionNeedsSyncOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_MainFunctionNeedsSyncOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ManagingChannelOfChannelType, COMM_CODE) ComM_IsManagingChannelOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ManagingChannelOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ManagingUserOfChannelType, COMM_CODE) ComM_GetManagingUserOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ManagingUserOfChannelType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_MinFullComTimeOfChannelType, COMM_CODE) ComM_GetMinFullComTimeOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_MinFullComTimeOfChannelType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_NmLightDurationOfChannelType, COMM_CODE) ComM_GetNmLightDurationOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmLightDurationOfChannelType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_NmLightSilentDurationOfChannelType, COMM_CODE) ComM_GetNmLightSilentDurationOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmLightSilentDurationOfChannelType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_NmSupportOfChannelType, COMM_CODE) ComM_IsNmSupportOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmSupportOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PassiveOrLinSlaveOfChannelType, COMM_CODE) ComM_IsPassiveOrLinSlaveOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PassiveOrLinSlaveOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncNmRequestOfChannelType, COMM_CODE) ComM_IsPncNmRequestOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncNmRequestOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(RequestBusSMModeApiType, COMM_CODE) ComM_GetRequestBusSMModeApiOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (RequestBusSMModeApiType) (ComM_GetChannelOfPCPartitionConfig()[(Index)].RequestBusSMModeApiOfChannel);
}
COMM_LOCAL_INLINE FUNC(ComM_ResetAfterForcingNoCommOfChannelType, COMM_CODE) ComM_IsResetAfterForcingNoCommOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ResetAfterForcingNoCommOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_SilentSupportOfChannelType, COMM_CODE) ComM_IsSilentSupportOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SilentSupportOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_InvalidHndOfChannelPbType, COMM_CODE) ComM_IsInvalidHndOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_InvalidHndOfChannelPbType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationEndIdxOfChannelPbType, COMM_CODE) ComM_GetPncLimitationEndIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncLimitationEndIdxOfChannelPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationStartIdxOfChannelPbType, COMM_CODE) ComM_GetPncLimitationStartIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncLimitationStartIdxOfChannelPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationUsedOfChannelPbType, COMM_CODE) ComM_IsPncLimitationUsedOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncLimitationUsedOfChannelPbType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndEndIdxOfChannelPbType, COMM_CODE) ComM_GetPncPbIndEndIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncPbIndEndIdxOfChannelPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndStartIdxOfChannelPbType, COMM_CODE) ComM_GetPncPbIndStartIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncPbIndStartIdxOfChannelPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndUsedOfChannelPbType, COMM_CODE) ComM_IsPncPbIndUsedOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncPbIndUsedOfChannelPbType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComEndIdxOfChannelPbType, COMM_CODE) ComM_GetUserReqFullComEndIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqFullComEndIdxOfChannelPbType) (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComEndIdxOfChannelPb);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComStartIdxOfChannelPbType, COMM_CODE) ComM_GetUserReqFullComStartIdxOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqFullComStartIdxOfChannelPbType) (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComStartIdxOfChannelPb);
}
COMM_LOCAL_INLINE FUNC(ComM_ComAllowedType, COMM_CODE) ComM_IsComAllowed(ComM_ComAllowedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ComAllowedType) ((ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_CoordPncWithGwPassiveAndManagedChannelsType, COMM_CODE) ComM_IsCoordPncWithGwPassiveAndManagedChannels(ComM_CoordPncWithGwPassiveAndManagedChannelsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_CoordPncWithGwPassiveAndManagedChannelsType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_DcmRequestActiveType, COMM_CODE) ComM_IsDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_DcmRequestActiveType) ((ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_EcuMWakeUpIndicatedType, COMM_CODE) ComM_IsEcuMWakeUpIndicated(ComM_EcuMWakeUpIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_EcuMWakeUpIndicatedType) ((ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ExtendedRamCheckType, COMM_CODE) ComM_IsExtendedRamCheck(ComM_ExtendedRamCheckIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ExtendedRamCheckType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ForwardNmGatewayType, COMM_CODE) ComM_IsForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ForwardNmGatewayType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ForwardSynchronizedPncShutdownIndicatedType, COMM_CODE) ComM_IsForwardSynchronizedPncShutdownIndicated(ComM_ForwardSynchronizedPncShutdownIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ForwardSynchronizedPncShutdownIndicatedType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_FrShutdownType, COMM_CODE) ComM_IsFrShutdown(ComM_FrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_FrShutdownType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_FullComRequestersType, COMM_CODE) ComM_GetFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_FullComRequestersType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_FullCommRequestNotifType, COMM_CODE) ComM_IsFullCommRequestNotif(ComM_FullCommRequestNotifIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_FullCommRequestNotifType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_FullNmTypeOfChannelType, COMM_CODE) ComM_IsFullNmTypeOfChannel(ComM_FullNmTypeOfChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_FullNmTypeOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_InhibitionType, COMM_CODE) ComM_GetInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return ((*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))));
}
COMM_LOCAL_INLINE FUNC(ComM_InitStatusType, COMM_CODE) ComM_GetInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_InitStatusType) ((*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))));
}
COMM_LOCAL_INLINE FUNC(ComM_ModeType, COMM_CODE) ComM_GetLastStateChange(ComM_LastStateChangeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ModeType) (0xFFu);
}
COMM_LOCAL_INLINE FUNC(ComM_LightNmTypeOfChannelType, COMM_CODE) ComM_IsLightNmTypeOfChannel(ComM_LightNmTypeOfChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_LightNmTypeOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_LinslaveNmTypeOfChannelType, COMM_CODE) ComM_IsLinslaveNmTypeOfChannel(ComM_LinslaveNmTypeOfChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_LinslaveNmTypeOfChannelType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_MinFullComModeTimerType, COMM_CODE) ComM_GetMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_MinFullComModeTimerType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_ModeLimitationType, COMM_CODE) ComM_IsModeLimitation(ComM_ModeLimitationIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ModeLimitationType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_NmGwExtType, COMM_CODE) ComM_IsNmGwExt(ComM_NmGwExtIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmGwExtType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_NmLightTimerType, COMM_CODE) ComM_GetNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmLightTimerType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_NmStartUpIndicatedType, COMM_CODE) ComM_IsNmStartUpIndicated(ComM_NmStartUpIndicatedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmStartUpIndicatedType) ((ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_NotifyPncStateChangeType, COMM_CODE) ComM_IsNotifyPncStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NotifyPncStateChangeType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_NvMStoreReqType, COMM_CODE) ComM_IsNvMStoreReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NvMStoreReqType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType, COMM_CODE) ComM_GetPCPartitionConfigIdxOfPartitionIdentifiers(ComM_PartitionIdentifiersIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PCPartitionConfigIdxOfPartitionIdentifiersType) (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers);
}
COMM_LOCAL_INLINE FUNC(ComM_PartitionSNVOfPartitionIdentifiersType, COMM_CODE) ComM_GetPartitionSNVOfPartitionIdentifiers(ComM_PartitionIdentifiersIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PartitionSNVOfPartitionIdentifiersType) (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers);
}
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfPncType, COMM_CODE) ComM_GetClearMaskOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ClearMaskOfPncType) (0x00u);
}
COMM_LOCAL_INLINE FUNC(ComM_CoordinatedOfPncType, COMM_CODE) ComM_IsCoordinatedOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_CoordinatedOfPncType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_IntermediatePncCoordinatorOfPncType, COMM_CODE) ComM_IsIntermediatePncCoordinatorOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_IntermediatePncCoordinatorOfPncType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncIdOfPncType, COMM_CODE) ComM_GetPncIdOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncIdOfPncType) ((PNCHandleType)0u);
}
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfPncType, COMM_CODE) ComM_GetSetMaskOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SetMaskOfPncType) (0x00u);
}
COMM_LOCAL_INLINE FUNC(ComM_SystemUserOfPncType, COMM_CODE) ComM_GetSystemUserOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SystemUserOfPncType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_TopLevelPncCoordinatorOfPncType, COMM_CODE) ComM_IsTopLevelPncCoordinatorOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_TopLevelPncCoordinatorOfPncType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_WakeupEnabledOfPncType, COMM_CODE) ComM_IsWakeupEnabledOfPnc(ComM_PncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_WakeupEnabledOfPncType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_Pnc0VectorAvoidanceType, COMM_CODE) ComM_IsPnc0VectorAvoidance(ComM_Pnc0VectorAvoidanceIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_Pnc0VectorAvoidanceType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingType, COMM_CODE) ComM_GetPncChannelMapping(ComM_PncChannelMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncChannelMappingType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncCheckEnabledAtRuntimeType, COMM_CODE) ComM_IsPncCheckEnabledAtRuntime(ComM_PncCheckEnabledAtRuntimeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncCheckEnabledAtRuntimeType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncEiraRxType, COMM_CODE) ComM_IsPncEiraRx(ComM_PncEiraRxIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncEiraRxType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncExtendedFunctionalityType, COMM_CODE) ComM_IsPncExtendedFunctionality(ComM_PncExtendedFunctionalityIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncExtendedFunctionalityType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypeActiveType, COMM_CODE) ComM_IsPncGwTypeActive(ComM_PncGwTypeActiveIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncGwTypeActiveType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypeNoneType, COMM_CODE) ComM_IsPncGwTypeNone(ComM_PncGwTypeNoneIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncGwTypeNoneType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncGwTypePassiveType, COMM_CODE) ComM_IsPncGwTypePassive(ComM_PncGwTypePassiveIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncGwTypePassiveType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncLimitationType, COMM_CODE) ComM_GetPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncLimitationType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncPSleepTimerType, COMM_CODE) ComM_GetPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncPSleepTimerType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingEndIdxOfPncPbType, COMM_CODE) ComM_GetPncChannelMappingEndIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncChannelMappingEndIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingStartIdxOfPncPbType, COMM_CODE) ComM_GetPncChannelMappingStartIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncChannelMappingStartIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncChannelMappingUsedOfPncPbType, COMM_CODE) ComM_IsPncChannelMappingUsedOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncChannelMappingUsedOfPncPbType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndEndIdxOfPncPbType, COMM_CODE) ComM_GetPncSignalIndEndIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalIndEndIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndStartIdxOfPncPbType, COMM_CODE) ComM_GetPncSignalIndStartIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalIndStartIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndUsedOfPncPbType, COMM_CODE) ComM_IsPncSignalIndUsedOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalIndUsedOfPncPbType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_SignalByteIndexOfPncPbType, COMM_CODE) ComM_GetSignalByteIndexOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SignalByteIndexOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComEndIdxOfPncPbType, COMM_CODE) ComM_GetUserReqPncFullComEndIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqPncFullComEndIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComStartIdxOfPncPbType, COMM_CODE) ComM_GetUserReqPncFullComStartIdxOfPncPb(ComM_PncPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqPncFullComStartIdxOfPncPbType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncPbIndType, COMM_CODE) ComM_GetPncPbInd(ComM_PncPbIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncPbIndType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_BusTypeIdOfPncSignalType, COMM_CODE) ComM_GetBusTypeIdOfPncSignal(ComM_PncSignalIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_BusTypeIdOfPncSignalType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_ChannelIdxOfPncSignalType, COMM_CODE) ComM_GetChannelIdxOfPncSignal(ComM_PncSignalIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ChannelIdxOfPncSignalType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_ChannelUsedOfPncSignalType, COMM_CODE) ComM_IsChannelUsedOfPncSignal(ComM_PncSignalIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ChannelUsedOfPncSignalType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_TypeOfPncSignalType, COMM_CODE) ComM_GetTypeOfPncSignal(ComM_PncSignalIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_TypeOfPncSignalType) (0x00u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalIndType, COMM_CODE) ComM_GetPncSignalInd(ComM_PncSignalIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalIndType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalValuesType, COMM_CODE) ComM_GetPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalValuesType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncToChannelRoutingStateType, COMM_CODE) ComM_GetPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncToChannelRoutingStateType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncWithoutChannelsType, COMM_CODE) ComM_IsPncWithoutChannels(ComM_PncWithoutChannelsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncWithoutChannelsType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PostInitializedType, COMM_CODE) ComM_IsPostInitialized(ComM_PostInitializedIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PostInitializedType) ((ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ResetRequiredType, COMM_CODE) ComM_IsResetRequired(ComM_ResetRequiredIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ResetRequiredType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_SimulatedSmModeType, COMM_CODE) ComM_GetSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SimulatedSmModeType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_StateChangeType, COMM_CODE) ComM_GetStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateChangeType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_SynchronousWakeUpType, COMM_CODE) ComM_IsSynchronousWakeUp(ComM_SynchronousWakeUpIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SynchronousWakeUpType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncUserOfUserType, COMM_CODE) ComM_IsPncUserOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncUserOfUserType) ((ComM_GetUserOfPCPartitionConfig()[(Index)].PncUserOfUser) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskEndIdxOfUserType, COMM_CODE) ComM_GetUserByteMaskEndIdxOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserByteMaskEndIdxOfUserType) (ComM_GetUserOfPCPartitionConfig()[(Index)].UserByteMaskEndIdxOfUser);
}
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskStartIdxOfUserType, COMM_CODE) ComM_GetUserByteMaskStartIdxOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserByteMaskStartIdxOfUserType) (ComM_GetUserOfPCPartitionConfig()[(Index)].UserByteMaskStartIdxOfUser);
}
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskEndIdxOfUserType, COMM_CODE) ComM_GetUserPncByteMaskEndIdxOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserPncByteMaskEndIdxOfUserType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskLengthOfUserType, COMM_CODE) ComM_GetUserPncByteMaskLengthOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserPncByteMaskLengthOfUserType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskStartIdxOfUserType, COMM_CODE) ComM_GetUserPncByteMaskStartIdxOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserPncByteMaskStartIdxOfUserType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserPncByteMaskUsedOfUserType, COMM_CODE) ComM_IsUserPncByteMaskUsedOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserPncByteMaskUsedOfUserType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ChannelOfUserByteMaskType, COMM_CODE) ComM_GetChannelOfUserByteMask(ComM_UserByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ChannelOfUserByteMaskType) ((NetworkHandleType)ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].ChannelOfUserByteMask);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComIdxOfUserByteMaskType, COMM_CODE) ComM_GetUserReqFullComIdxOfUserByteMask(ComM_UserByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqFullComIdxOfUserByteMaskType) (ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].UserReqFullComIdxOfUserByteMask);
}
COMM_LOCAL_INLINE FUNC(ComM_StateNotiFuncPtrType, COMM_CODE) ComM_GetUserModeNotiFunc(ComM_UserModeNotiFuncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateNotiFuncPtrType) (NULL_PTR);
}
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfUserPncByteMaskType, COMM_CODE) ComM_GetClearMaskOfUserPncByteMask(ComM_UserPncByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ClearMaskOfUserPncByteMaskType) (0x00u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncIDOfUserPncByteMaskType, COMM_CODE) ComM_GetPncIDOfUserPncByteMask(ComM_UserPncByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncIDOfUserPncByteMaskType) ((PNCHandleType)0u);
}
COMM_LOCAL_INLINE FUNC(ComM_PncIdxOfUserPncByteMaskType, COMM_CODE) ComM_GetPncIdxOfUserPncByteMask(ComM_UserPncByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncIdxOfUserPncByteMaskType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfUserPncByteMaskType, COMM_CODE) ComM_GetSetMaskOfUserPncByteMask(ComM_UserPncByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SetMaskOfUserPncByteMaskType) (0x00u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComIdxOfUserPncByteMaskType, COMM_CODE) ComM_GetUserReqPncFullComIdxOfUserPncByteMask(ComM_UserPncByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqPncFullComIdxOfUserPncByteMaskType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComType, COMM_CODE) ComM_GetUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqFullComType) (ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)]);
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqPncFullComType, COMM_CODE) ComM_GetUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqPncFullComType) (0u);
}
COMM_LOCAL_INLINE FUNC(ComM_UserWithSinglePncType, COMM_CODE) ComM_IsUserWithSinglePnc(ComM_UserWithSinglePncIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserWithSinglePncType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_WakeupInhibitionType, COMM_CODE) ComM_IsWakeupInhibition(ComM_WakeupInhibitionIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_WakeupInhibitionType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetDeduplicatedInlineFunctions  ComM Get Deduplicated Inline Functions (PRE_COMPILE)
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_GwTypeOfChannelType, COMM_CODE) ComM_GetGwTypeOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_GwTypeOfChannelType) COMM_GATEWAY_TYPE_NONE;
}
COMM_LOCAL_INLINE FUNC(ComM_InhibitionInitValueOfChannelType, COMM_CODE) ComM_GetInhibitionInitValueOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_InhibitionInitValueOfChannelType) 0x00u;
}
COMM_LOCAL_INLINE FUNC(ComM_ManagingChannelIdOfChannelType, COMM_CODE) ComM_GetManagingChannelIdOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ManagingChannelIdOfChannelType) 255u;
}
COMM_LOCAL_INLINE FUNC(ComM_NmTypeOfChannelType, COMM_CODE) ComM_GetNmTypeOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NmTypeOfChannelType) COMM_NONE_NMTYPEOFCHANNEL;
}
COMM_LOCAL_INLINE FUNC(ComM_PartitionConfigIdxOfChannelType, COMM_CODE) ComM_GetPartitionConfigIdxOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PartitionConfigIdxOfChannelType) 0u;
}
COMM_LOCAL_INLINE FUNC(ComM_WakeupStateOfChannelType, COMM_CODE) ComM_GetWakeupStateOfChannel(ComM_ChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_WakeupStateOfChannelType) COMM_FULL_COM_NETWORK_REQUESTED;
}
COMM_LOCAL_INLINE FUNC(ComM_UserReqFullComUsedOfChannelPbType, COMM_CODE) ComM_IsUserReqFullComUsedOfChannelPb(ComM_ChannelPbIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserReqFullComUsedOfChannelPbType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_DcmIndicationType, COMM_CODE) ComM_IsDcmIndication(ComM_DcmIndicationIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_DcmIndicationType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_FinalMagicNumberType, COMM_CODE) ComM_GetFinalMagicNumber(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_FinalMagicNumberType) ComM_GetFinalMagicNumberOfPCConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_InitDataHashCodeType, COMM_CODE) ComM_GetInitDataHashCode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_InitDataHashCodeType) ComM_GetInitDataHashCodeOfPCConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_KeepAwakeChannelsType, COMM_CODE) ComM_IsKeepAwakeChannels(ComM_KeepAwakeChannelsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_KeepAwakeChannelsType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_NoneNmTypeOfChannelType, COMM_CODE) ComM_IsNoneNmTypeOfChannel(ComM_NoneNmTypeOfChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_NoneNmTypeOfChannelType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_OnlyNoneNmTypeOfChannelType, COMM_CODE) ComM_IsOnlyNoneNmTypeOfChannel(ComM_OnlyNoneNmTypeOfChannelIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_OnlyNoneNmTypeOfChannelType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_PncEiraRxCountType, COMM_CODE) ComM_GetPncEiraRxCount(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (ComM_PncEiraRxCountType) ComM_GetPncEiraRxCountOfPCPartitionConfig();
}
COMM_LOCAL_INLINE FUNC(ComM_PartitionConfigIdxOfUserType, COMM_CODE) ComM_GetPartitionConfigIdxOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PartitionConfigIdxOfUserType) 0u;
}
COMM_LOCAL_INLINE FUNC(ComM_UserByteMaskUsedOfUserType, COMM_CODE) ComM_IsUserByteMaskUsedOfUser(ComM_UserIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserByteMaskUsedOfUserType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(ComM_ClearMaskOfUserByteMaskType, COMM_CODE) ComM_GetClearMaskOfUserByteMask(ComM_UserByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ClearMaskOfUserByteMaskType) 0xFEu;
}
COMM_LOCAL_INLINE FUNC(ComM_SetMaskOfUserByteMaskType, COMM_CODE) ComM_GetSetMaskOfUserByteMask(ComM_UserByteMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_SetMaskOfUserByteMaskType) 0x01u;
}
COMM_LOCAL_INLINE FUNC(ComM_UserModeNotificationOnlyForPncUsersType, COMM_CODE) ComM_IsUserModeNotificationOnlyForPncUsers(ComM_UserModeNotificationOnlyForPncUsersIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_UserModeNotificationOnlyForPncUsersType) (((TRUE)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSetDataInlineFunctions  ComM Set Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to write data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusSleepModeIndicated(ComM_BusSleepModeIndicatedIterType Index, ComM_BusSleepModeIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetComAllowed(ComM_ComAllowedIterType Index, ComM_ComAllowedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_DcmRequestActiveType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetEcuMWakeUpIndicated(ComM_EcuMWakeUpIndicatedIterType Index, ComM_EcuMWakeUpIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_ForwardNmGatewayType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetForwardSynchronizedPncShutdownIndicated(ComM_ForwardSynchronizedPncShutdownIndicatedIterType Index, ComM_ForwardSynchronizedPncShutdownIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetFrShutdown(ComM_FrShutdownIterType Index, ComM_FrShutdownType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetInhibition(ComM_InhibitionType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  (*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))) = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  (*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))) = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNmStartUpIndicated(ComM_NmStartUpIndicatedIterType Index, ComM_NmStartUpIndicatedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNotifyPncStateChange(ComM_NotifyPncStateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetNvMStoreReq(ComM_NvMStoreReqType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetPostInitialized(ComM_PostInitializedIterType Index, ComM_PostInitializedType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetResetRequired(ComM_ResetRequiredIterType Index, ComM_ResetRequiredType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)] = (Value);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SetUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCGetAddressOfDataInlineFunctions  ComM Get Address Of Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(ComM_ActiveComModePtrType, COMM_CODE) ComM_GetAddrActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ActiveComModePtrType) (&(ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)]));
}
COMM_LOCAL_INLINE FUNC(ComM_BusComModeReqFrShutdownPtrType, COMM_CODE) ComM_GetAddrBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_BusComModeReqFrShutdownPtrType) (NULL_PTR);
}
COMM_LOCAL_INLINE FUNC(ComM_DcmRequestActivePtrType, COMM_CODE) ComM_GetAddrDcmRequestActive(ComM_DcmRequestActiveIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_DcmRequestActivePtrType) (&(ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)]));
}
COMM_LOCAL_INLINE FUNC(ComM_ForwardNmGatewayPtrType, COMM_CODE) ComM_GetAddrForwardNmGateway(ComM_ForwardNmGatewayIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_ForwardNmGatewayPtrType) (NULL_PTR);
}
COMM_LOCAL_INLINE FUNC(ComM_InhibitionPtrType, COMM_CODE) ComM_GetAddrInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_InhibitionPtrType) (&((*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex)))));
}
COMM_LOCAL_INLINE FUNC(ComM_MinFullComModeTimerPtrType, COMM_CODE) ComM_GetAddrMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_MinFullComModeTimerPtrType) (NULL_PTR);
}
COMM_LOCAL_INLINE FUNC(ComM_PncSignalValuesPtrType, COMM_CODE) ComM_GetAddrPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_PncSignalValuesPtrType) (NULL_PTR);
}
COMM_LOCAL_INLINE FUNC(ComM_StateChangePtrType, COMM_CODE) ComM_GetAddrStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (ComM_StateChangePtrType) (NULL_PTR);
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCHasInlineFunctions  ComM Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeFr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasGetCurrentBusSMModeApiOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasGwTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibitionInitValueOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInvalidHndOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasJ1939SupportOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMainFunctionNeedsSyncOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingChannelIdOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingChannelOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasManagingUserOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComTimeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightDurationOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightSilentDurationOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmSupportOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionConfigIdxOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPassiveOrLinSlaveOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncNmRequestOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasRequestBusSMModeApiOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetAfterForcingNoCommOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSilentSupportOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupStateOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInvalidHndOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationEndIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationStartIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationUsedOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndEndIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndStartIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndUsedOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComEndIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComStartIdxOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComUsedOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordPncWithGwPassiveAndManagedChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmIndication(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEiraTxSignalIndirection(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasExtendedRamCheck(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFinalMagicNumber(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullCommRequestNotif(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibition(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitDataHashCode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasKeepAwakeChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLastStateChange(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLightNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLinslaveNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasModeLimitation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmGwExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNotifyPncStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNvMStoreReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasOnlyNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionIdentifiers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfigIdxOfPartitionIdentifiers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionSNVOfPartitionIdentifiers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordinatedOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasIntermediatePncCoordinatorOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIdOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSystemUserOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasTopLevelPncCoordinatorOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupEnabledOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc0VectorAvoidance(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncCheckEnabledAtRuntime(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRx(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxCount(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncExtendedFunctionality(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeActive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeNone(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypePassive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingEndIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingStartIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingUsedOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndEndIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndStartIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndUsedOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSignalByteIndexOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComEndIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComStartIdxOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeIdOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelIdxOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelUsedOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasTypeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncWithoutChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActiveComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActivePncComMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusPncComModeReq(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSleepModeIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSmState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusTypeFr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfComAllowed(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfCoordPncWithGwPassiveAndManagedChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmIndication(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmRequestActive(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEcuMWakeUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEiraTxSignalIndirection(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfExtendedRamCheck(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardNmGateway(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardSynchronizedPncShutdownIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFrShutdown(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullComRequesters(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullCommRequestNotif(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfKeepAwakeChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLastStateChange(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLightNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLinslaveNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfMinFullComModeTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfModeLimitation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmGwExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmLightTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmStartUpIndicated(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfOnlyNoneNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPartitionIdentifiers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc0VectorAvoidance(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncChannelMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncCheckEnabledAtRuntime(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncEiraRx(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncExtendedFunctionality(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeActive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeNone(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypePassive(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncLimitation(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPSleepTimer(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPb(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalValues(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncToChannelRoutingState(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncWithoutChannels(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPostInitialized(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfResetRequired(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSimulatedSmMode(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSynchronousWakeUp(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotiFunc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotificationOnlyForPncUsers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserWithSinglePnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfWakeupInhibition(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasStateChange(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSynchronousWakeUp(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionConfigIdxOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncUserOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskEndIdxOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskStartIdxOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskUsedOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskEndIdxOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskLengthOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskStartIdxOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskUsedOfUser(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComIdxOfUserByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotiFunc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotificationOnlyForPncUsers(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasClearMaskOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIDOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncIdxOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSetMaskOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComIdxOfUserPncByteMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullCom(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserWithSinglePnc(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupInhibition(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFinalMagicNumberOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitDataHashCodeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfigOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPartitionIdentifiersOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPartitionIdentifiersOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActiveComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasActivePncComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusPncComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSleepModeIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusSmStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasBusTypeFrOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasChannelPbOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasComAllowedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmIndicationOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasDcmRequestActiveOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEcuMWakeUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasEiraTxSignalIndirectionOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasExtendedRamCheckOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardNmGatewayOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullComRequestersOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullCommRequestNotifOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasFullNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInhibitionOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasInitStatusOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasKeepAwakeChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLastStateChangeOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLightNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLinslaveNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasMinFullComModeTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasModeLimitationOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmGwExtOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmLightTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNmStartUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNoneNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNotifyPncStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasNvMStoreReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasOnlyNoneNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPnc0VectorAvoidanceOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncChannelMappingOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncCheckEnabledAtRuntimeOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxCountOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncEiraRxOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncExtendedFunctionalityOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeActiveOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypeNoneOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncGwTypePassiveOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncLimitationOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPSleepTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbIndOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncPbOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalIndOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncSignalValuesOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncToChannelRoutingStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPncWithoutChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPostInitializedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasResetRequiredOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSimulatedSmModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActiveComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfActivePncComModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusPncComModeReqOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSleepModeIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusSmStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfBusTypeFrOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfChannelPbOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfComAllowedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfCoordPncWithGwPassiveAndManagedChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmIndicationOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfDcmRequestActiveOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfEiraTxSignalIndirectionOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfExtendedRamCheckOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardNmGatewayOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfForwardSynchronizedPncShutdownIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFrShutdownOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullComRequestersOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullCommRequestNotifOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfFullNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfKeepAwakeChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLastStateChangeOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLightNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfLinslaveNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfMinFullComModeTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfModeLimitationOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmGwExtOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmLightTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNmStartUpIndicatedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfNoneNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfOnlyNoneNmTypeOfChannelOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPnc0VectorAvoidanceOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncChannelMappingOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncCheckEnabledAtRuntimeOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncEiraRxOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncExtendedFunctionalityOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeActiveOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypeNoneOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncGwTypePassiveOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncLimitationOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPSleepTimerOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbIndOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncPbOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalIndOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncSignalValuesOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncToChannelRoutingStateOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPncWithoutChannelsOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfPostInitializedOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfResetRequiredOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSimulatedSmModeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfSynchronousWakeUpOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserByteMaskOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotiFuncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserModeNotificationOnlyForPncUsersOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserPncByteMaskOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserReqPncFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfUserWithSinglePncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSizeOfWakeupInhibitionOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasStateChangeOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasSynchronousWakeUpOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserByteMaskOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotiFuncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserModeNotificationOnlyForPncUsersOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserPncByteMaskOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserReqPncFullComOfPCPartitionConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasUserWithSinglePncOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasWakeupInhibitionOfPCPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCEsistsEnumInlineFunctions  ComM Esists Enum Inline Functions (PRE_COMPILE)
  \brief  These inilne functions can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNOT_USED_IN_THIS_VARIANTNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsFULLNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsPASSIVENmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsLIGHTNmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNONENmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsLINSLAVENmTypeOfChannel(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsEIRA_RXTypeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsEIRA_TXTypeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsERA_RXTypeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ExistsNOT_USED_IN_THIS_VARIANTTypeOfPncSignal(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCIncrementInlineFunctions  ComM Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  (*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex)))++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncLastStateChange(ComM_LastStateChangeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_IncUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCDecrementInlineFunctions  ComM Decrement Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecActiveComMode(ComM_ActiveComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusComModeReq(ComM_BusComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecBusSmState(ComM_BusSmStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecFullComRequesters(ComM_FullComRequestersIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecInitStatus(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  (*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex)))--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecLastStateChange(ComM_LastStateChangeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecNmLightTimer(ComM_NmLightTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncLimitation(ComM_PncLimitationIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecStateChange(ComM_StateChangeIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_DecUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCAddInlineFunctions  ComM Add Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetActiveComMode(Index, (ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)] + Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] + Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetBusSmState(Index, (ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)] + Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetInitStatus(((*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))) + Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)] + Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_AddUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPCSubstractInlineFunctions  ComM Substract Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubActiveComMode(ComM_ActiveComModeIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetActiveComMode(Index, (ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)] - Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubActivePncComMode(ComM_ActivePncComModeIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusComModeReq(ComM_BusComModeReqIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] - Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusComModeReqFrShutdown(ComM_BusComModeReqFrShutdownIterType Index, ComM_StateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusPncComModeReq(ComM_BusPncComModeReqIterType Index, ComM_PncModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubBusSmState(ComM_BusSmStateIterType Index, ComM_ModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetBusSmState(Index, (ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)] - Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubFullComRequesters(ComM_FullComRequestersIterType Index, ComM_FullComRequestersType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubInitStatus(ComM_InitStatusType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetInitStatus(((*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))) - Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubLastStateChange(ComM_LastStateChangeIterType Index, ComM_ModeType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubMinFullComModeTimer(ComM_MinFullComModeTimerIterType Index, ComM_MinFullComModeTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubNmLightTimer(ComM_NmLightTimerIterType Index, ComM_NmLightTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncLimitation(ComM_PncLimitationIterType Index, ComM_PncLimitationType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncPSleepTimer(ComM_PncPSleepTimerIterType Index, ComM_PncPSleepTimerType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncSignalValues(ComM_PncSignalValuesIterType Index, ComM_PncSignalValuesType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubPncToChannelRoutingState(ComM_PncToChannelRoutingStateIterType Index, ComM_PncToChannelRoutingStateType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubSimulatedSmMode(ComM_SimulatedSmModeIterType Index, ComM_SimulatedSmModeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubStateChange(ComM_StateChangeIterType Index, ComM_StateChangeType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubUserReqFullCom(ComM_UserReqFullComIterType Index, ComM_UserReqFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)] - Value), partitionIndex);
}
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_SubUserReqPncFullCom(ComM_UserReqPncFullComIterType Index, ComM_UserReqPncFullComType Value, ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMLTHasInlineFunctions  ComM Has Inline Functions (LINK)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTPartitionConfigOfLTConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComMPBHasInlineFunctions  ComM Has Inline Functions (POST_BUILD)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasLTConfigIdxOfPBConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBPartitionConfigOfPBConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPCConfigIdxOfPBConfig(ComM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIndex)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COMM_DUMMY_STATEMENT(partitionIndex);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_HasPBPartitionConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COMM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



 /* VCA Enable: VCA_COMM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif /* COMM_PRIVATE_CFG_H */

