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
 *            Module: EthIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthIf_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:19
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
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA_100Mb is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_TJA1103B is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#if !defined (ETHIF_LCFG_H)
# define ETHIF_LCFG_H

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1977
 *********************************************************************************************************/
# include "EthIf_GenTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# if !defined (ETHIF_LOCAL_INLINE)
#  define ETHIF_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthIf_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    EthIf_ConfigDataPtr
  \brief  Points to the currently active configuration for EthIf
  \details
  Pointer is initialized during EthIf_Init() and holds the active configuration for EthIf were all configuration data
  is retrieved from during runtime.
*/
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
#define EthIf_GetConfigDataPtrList(CfgPtr)  ((CfgPtr == &EthIf_PCConfig.Config_RDR_01) || (CfgPtr == &EthIf_PCConfig.Config_RDR_02) || (CfgPtr == &EthIf_PCConfig.Config_RDR_03) || (CfgPtr == &EthIf_PCConfig.Config_RDR_04) || (CfgPtr == &EthIf_PCConfig.Config_RDR_05) || (CfgPtr == &EthIf_PCConfig.Config_RDR_06) || (CfgPtr == &EthIf_PCConfig.Config_RDR_07) || (CfgPtr == &EthIf_PCConfig.Config_RDR_08))
/*!
 * \spec strong invariant EthIf_GetConfigDataPtrList(EthIf_ConfigDataPtr);
 * \endspec
 */
extern P2CONST(EthIf_ConfigType, ETHIF_VAR_NO_INIT, ETHIF_INIT_DATA) EthIf_ConfigDataPtr;
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCGetRootDataMacros  EthIf Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define EthIf_GetDedicatedRxPduNextFreePosOfPCConfig()                                              EthIf_ConfigDataPtr->DedicatedRxPduNextFreePosOfPCConfig
#define EthIf_GetEcucPartitionOfPCConfig()                                                          EthIf_ConfigDataPtr->EcucPartitionOfPCConfig
#define EthIf_GetEthCtrlInitCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthCtrlInitCntOfPCConfig
#define EthIf_GetEthCtrlModeCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthCtrlModeCntOfPCConfig
#define EthIf_GetEthCtrlOfPCConfig()                                                                EthIf_ConfigDataPtr->EthCtrlOfPCConfig
#define EthIf_GetEthCtrlStateOfPCConfig()                                                           EthIf_ConfigDataPtr->EthCtrlStateOfPCConfig
#define EthIf_GetEthDrvApiOfPCConfig()                                                              EthIf_ConfigDataPtr->EthDrvApiOfPCConfig
#define EthIf_GetEthIfClkUnitOfPCConfig()                                                           EthIf_ConfigDataPtr->EthIfClkUnitOfPCConfig
#define EthIf_GetEthIfControllerModeChangeReqCntOfPCConfig()                                        EthIf_ConfigDataPtr->EthIfControllerModeChangeReqCntOfPCConfig
#define EthIf_GetEthIfCtrlInitStateOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlInitStateOfPCConfig
#define EthIf_GetEthIfCtrlLinkCountOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlLinkCountOfPCConfig
#define EthIf_GetEthIfCtrlLinkStateOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlLinkStateOfPCConfig
#define EthIf_GetEthIfCtrlModeOfPCConfig()                                                          EthIf_ConfigDataPtr->EthIfCtrlModeOfPCConfig
#define EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig()                                                  EthIf_ConfigDataPtr->EthIfCtrlOfEthTrcvIndOfPCConfig
#define EthIf_GetEthIfCtrlOfPCConfig()                                                              EthIf_ConfigDataPtr->EthIfCtrlOfPCConfig
#define EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig()                                                EthIf_ConfigDataPtr->EthIfCtrlOfPortGroupIndOfPCConfig
#define EthIf_GetEthIfCtrlRxStatsOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfCtrlRxStatsOfPCConfig
#define EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()                                                EthIf_ConfigDataPtr->EthIfCtrlToEtherTypeMapOfPCConfig
#define EthIf_GetEthIfCtrlToRxPduMapOfPCConfig()                                                    EthIf_ConfigDataPtr->EthIfCtrlToRxPduMapOfPCConfig
#define EthIf_GetEthIfCtrlTxStatsOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfCtrlTxStatsOfPCConfig
#define EthIf_GetEthIfMeasurementDataOfPCConfig()                                                   EthIf_ConfigDataPtr->EthIfMeasurementDataOfPCConfig
#define EthIf_GetEthIfPhysCtrlCfgOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfPhysCtrlCfgOfPCConfig
#define EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()                           EthIf_ConfigDataPtr->EthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig
#define EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()                             EthIf_ConfigDataPtr->EthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig
#define EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()                               EthIf_ConfigDataPtr->EthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig
#define EthIf_GetEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()                                 EthIf_ConfigDataPtr->EthIfSwitchOffPortGroupTimerDelayStateOfPCConfig
#define EthIf_GetEthIfSwitchOffPortTimeDelayCountsOfPCConfig()                                      EthIf_ConfigDataPtr->EthIfSwitchOffPortTimeDelayCountsOfPCConfig
#define EthIf_GetEthIfSwitchOffPortTimeDelayReqCntOfPCConfig()                                      EthIf_ConfigDataPtr->EthIfSwitchOffPortTimeDelayReqCntOfPCConfig
#define EthIf_GetEthIfSwitchOffPortTimerDelayStateOfPCConfig()                                      EthIf_ConfigDataPtr->EthIfSwitchOffPortTimerDelayStateOfPCConfig
#define EthIf_GetEthIfSwtPortGroupStateOfPCConfig()                                                 EthIf_ConfigDataPtr->EthIfSwtPortGroupStateOfPCConfig
#define EthIf_GetEthRxQueueOfPCConfig()                                                             EthIf_ConfigDataPtr->EthRxQueueOfPCConfig
#define EthIf_GetEthSwtDrvApiOfPCConfig()                                                           EthIf_ConfigDataPtr->EthSwtDrvApiOfPCConfig
#define EthIf_GetEthSwtDrvOfPCConfig()                                                              EthIf_ConfigDataPtr->EthSwtDrvOfPCConfig
#define EthIf_GetEthSwtIndOfPCConfig()                                                              EthIf_ConfigDataPtr->EthSwtIndOfPCConfig
#define EthIf_GetEthSwtInitCntOfPCConfig()                                                          EthIf_ConfigDataPtr->EthSwtInitCntOfPCConfig
#define EthIf_GetEthSwtOfPCConfig()                                                                 EthIf_ConfigDataPtr->EthSwtOfPCConfig
#define EthIf_GetEthSwtPortInEthSwtContextOfPCConfig()                                              EthIf_ConfigDataPtr->EthSwtPortInEthSwtContextOfPCConfig
#define EthIf_GetEthSwtPortIndOfPCConfig()                                                          EthIf_ConfigDataPtr->EthSwtPortIndOfPCConfig
#define EthIf_GetEthSwtPortLinkStateOfPCConfig()                                                    EthIf_ConfigDataPtr->EthSwtPortLinkStateOfPCConfig
#define EthIf_GetEthSwtPortModeCntOfPCConfig()                                                      EthIf_ConfigDataPtr->EthSwtPortModeCntOfPCConfig
#define EthIf_GetEthSwtPortOfPCConfig()                                                             EthIf_ConfigDataPtr->EthSwtPortOfPCConfig
#define EthIf_GetEthTrcvDrvApiOfPCConfig()                                                          EthIf_ConfigDataPtr->EthTrcvDrvApiOfPCConfig
#define EthIf_GetEthTrcvInitCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthTrcvInitCntOfPCConfig
#define EthIf_GetEthTrcvLinkStateOfPCConfig()                                                       EthIf_ConfigDataPtr->EthTrcvLinkStateOfPCConfig
#define EthIf_GetEthTrcvModeChangeRetryCounterOfPCConfig()                                          EthIf_ConfigDataPtr->EthTrcvModeChangeRetryCounterOfPCConfig
#define EthIf_GetEthTrcvModeChangeRetryPeriodCounterOfPCConfig()                                    EthIf_ConfigDataPtr->EthTrcvModeChangeRetryPeriodCounterOfPCConfig
#define EthIf_GetEthTrcvModeCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthTrcvModeCntOfPCConfig
#define EthIf_GetEthTrcvModeOfPCConfig()                                                            EthIf_ConfigDataPtr->EthTrcvModeOfPCConfig
#define EthIf_GetEthTrcvOfPCConfig()                                                                EthIf_ConfigDataPtr->EthTrcvOfPCConfig
#define EthIf_GetEthTrcvStateOfPCConfig()                                                           EthIf_ConfigDataPtr->EthTrcvStateOfPCConfig
#define EthIf_GetEthTxQueueOfPCConfig()                                                             EthIf_ConfigDataPtr->EthTxQueueOfPCConfig
#define EthIf_GetExplicitBufReleaseFilterOfPCConfig()                                               EthIf_ConfigDataPtr->ExplicitBufReleaseFilterOfPCConfig
#define EthIf_GetFloatingRxPduMapOfPCConfig()                                                       EthIf_ConfigDataPtr->FloatingRxPduMapOfPCConfig
#define EthIf_GetFloatingRxPduNextFreePosOfPCConfig()                                               EthIf_ConfigDataPtr->FloatingRxPduNextFreePosOfPCConfig
#define EthIf_GetGatewaySrcMacBlackListOfPCConfig()                                                 EthIf_ConfigDataPtr->GatewaySrcMacBlackListOfPCConfig
#define EthIf_GetGlobalModeChangeMaxRetryCountOfPCConfig()                                          EthIf_ConfigDataPtr->GlobalModeChangeMaxRetryCountOfPCConfig
#define EthIf_GetGlobalModeChangeRetryPeriodCountOfPCConfig()                                       EthIf_ConfigDataPtr->GlobalModeChangeRetryPeriodCountOfPCConfig
#define EthIf_GetGlobalStartupActiveTimerActiveOfPCConfig()                                         EthIf_ConfigDataPtr->GlobalStartupActiveTimerActiveOfPCConfig
#define EthIf_GetInitLockedOfPCConfig()                                                             EthIf_ConfigDataPtr->InitLockedOfPCConfig
#define EthIf_GetLegacyWakeupMapOfPCConfig()                                                        EthIf_ConfigDataPtr->LegacyWakeupMapOfPCConfig
#define EthIf_GetLinkStateChgIndicationsOfPCConfig()                                                EthIf_ConfigDataPtr->LinkStateChgIndicationsOfPCConfig
#define EthIf_GetLinkStateChgMainReloadOfPCConfig()                                                 EthIf_ConfigDataPtr->LinkStateChgMainReloadOfPCConfig
#define EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig()                                           EthIf_ConfigDataPtr->MainFuncStateDecoupleFreqCntOfPCConfig
#define EthIf_GetMainPartitionRxEthCtrlOfPCConfig()                                                 EthIf_ConfigDataPtr->MainPartitionRxEthCtrlOfPCConfig
#define EthIf_GetMainPartitionTxEthCtrlOfPCConfig()                                                 EthIf_ConfigDataPtr->MainPartitionTxEthCtrlOfPCConfig
#define EthIf_GetMaxRxFramePerEthCtrlOfPCConfig()                                                   EthIf_ConfigDataPtr->MaxRxFramePerEthCtrlOfPCConfig
#define EthIf_GetMaxTxBufPerEthCtrlOfPCConfig()                                                     EthIf_ConfigDataPtr->MaxTxBufPerEthCtrlOfPCConfig
#define EthIf_GetMirrorDestOfPCConfig()                                                             EthIf_ConfigDataPtr->MirrorDestOfPCConfig
#define EthIf_GetMirrorTxInfoOfPCConfig()                                                           EthIf_ConfigDataPtr->MirrorTxInfoOfPCConfig
#define EthIf_GetModeChangeLockedOfPCConfig()                                                       EthIf_ConfigDataPtr->ModeChangeLockedOfPCConfig
#define EthIf_GetPhysLayerInitElemsOfPCConfig()                                                     EthIf_ConfigDataPtr->PhysLayerInitElemsOfPCConfig
#define EthIf_GetPhysLayerModeElemsOfPCConfig()                                                     EthIf_ConfigDataPtr->PhysLayerModeElemsOfPCConfig
#define EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                                 EthIf_ConfigDataPtr->PortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig
#define EthIf_GetPortGroupIndOfPCConfig()                                                           EthIf_ConfigDataPtr->PortGroupIndOfPCConfig
#define EthIf_GetPortGroupLinkStateOfPCConfig()                                                     EthIf_ConfigDataPtr->PortGroupLinkStateOfPCConfig
#define EthIf_GetPortGroupModeOfPCConfig()                                                          EthIf_ConfigDataPtr->PortGroupModeOfPCConfig
#define EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()                                               EthIf_ConfigDataPtr->PortGroupNoRoleLinkCountOfPCConfig
#define EthIf_GetPortGroupOfPCConfig()                                                              EthIf_ConfigDataPtr->PortGroupOfPCConfig
#define EthIf_GetPortGroupStartupActiveTimerActiveOfPCConfig()                                      EthIf_ConfigDataPtr->PortGroupStartupActiveTimerActiveOfPCConfig
#define EthIf_GetPortModeOfPCConfig()                                                               EthIf_ConfigDataPtr->PortModeOfPCConfig
#define EthIf_GetPortSignalQualityResultOfPCConfig()                                                EthIf_ConfigDataPtr->PortSignalQualityResultOfPCConfig
#define EthIf_GetPortStartupActiveTimeCounterOfPCConfig()                                           EthIf_ConfigDataPtr->PortStartupActiveTimeCounterOfPCConfig
#define EthIf_GetPortStartupActiveTimeFreqOfPCConfig()                                              EthIf_ConfigDataPtr->PortStartupActiveTimeFreqOfPCConfig
#define EthIf_GetPortStartupActiveTimerActiveOfPCConfig()                                           EthIf_ConfigDataPtr->PortStartupActiveTimerActiveOfPCConfig
#define EthIf_GetRequestedEthIfCtrlModeOfPCConfig()                                                 EthIf_ConfigDataPtr->RequestedEthIfCtrlModeOfPCConfig
#define EthIf_GetRequestedEthTrcvModeOfPCConfig()                                                   EthIf_ConfigDataPtr->RequestedEthTrcvModeOfPCConfig
#define EthIf_GetRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()                                       EthIf_ConfigDataPtr->RequestedEthTrcvStateOfEthIfCtrlOfPCConfig
#define EthIf_GetRequestedPortGroupModeOfPCConfig()                                                 EthIf_ConfigDataPtr->RequestedPortGroupModeOfPCConfig
#define EthIf_GetRequestedPortGroupStateOfEthIfCtrlOfPCConfig()                                     EthIf_ConfigDataPtr->RequestedPortGroupStateOfEthIfCtrlOfPCConfig
#define EthIf_GetRequestedPortModeOfPCConfig()                                                      EthIf_ConfigDataPtr->RequestedPortModeOfPCConfig
#define EthIf_GetRxIndicationsOfPCConfig()                                                          EthIf_ConfigDataPtr->RxIndicationsOfPCConfig
#define EthIf_GetRxPduContextOfPCConfig()                                                           EthIf_ConfigDataPtr->RxPduContextOfPCConfig
#define EthIf_GetRxPduFrameTypeOfPCConfig()                                                         EthIf_ConfigDataPtr->RxPduFrameTypeOfPCConfig
#define EthIf_GetRxPduFreeListOfPCConfig()                                                          EthIf_ConfigDataPtr->RxPduFreeListOfPCConfig
#define EthIf_GetRxPduMetaDataOfPCConfig()                                                          EthIf_ConfigDataPtr->RxPduMetaDataOfPCConfig
#define EthIf_GetRxPduOfPCConfig()                                                                  EthIf_ConfigDataPtr->RxPduOfPCConfig
#define EthIf_GetRxQueueListOfPCConfig()                                                            EthIf_ConfigDataPtr->RxQueueListOfPCConfig
#define EthIf_GetSetControllerModeTimeoutOfPCConfig()                                               EthIf_ConfigDataPtr->SetControllerModeTimeoutOfPCConfig
#define EthIf_GetSignalQualityChgMainReloadOfPCConfig()                                             EthIf_ConfigDataPtr->SignalQualityChgMainReloadOfPCConfig
#define EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig()                                           EthIf_ConfigDataPtr->SignalQualityDecoupleFreqCntOfPCConfig
#define EthIf_GetSignalQualityResultOfPCConfig()                                                    EthIf_ConfigDataPtr->SignalQualityResultOfPCConfig
#define EthIf_GetSizeOfEcucPartitionOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfEcucPartitionOfPCConfig
#define EthIf_GetSizeOfEthCtrlOfPCConfig()                                                          EthIf_ConfigDataPtr->SizeOfEthCtrlOfPCConfig
#define EthIf_GetSizeOfEthDrvApiOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthDrvApiOfPCConfig
#define EthIf_GetSizeOfEthIfClkUnitOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfEthIfClkUnitOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()                                            EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfEthTrcvIndOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()                                          EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfPortGroupIndOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlToEtherTypeMapOfPCConfig()                                          EthIf_ConfigDataPtr->SizeOfEthIfCtrlToEtherTypeMapOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlToRxPduMapOfPCConfig()                                              EthIf_ConfigDataPtr->SizeOfEthIfCtrlToRxPduMapOfPCConfig
#define EthIf_GetSizeOfEthIfMeasurementDataOfPCConfig()                                             EthIf_ConfigDataPtr->SizeOfEthIfMeasurementDataOfPCConfig
#define EthIf_GetSizeOfEthIfPhysCtrlCfgOfPCConfig()                                                 EthIf_ConfigDataPtr->SizeOfEthIfPhysCtrlCfgOfPCConfig
#define EthIf_GetSizeOfEthRxQueueOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfEthRxQueueOfPCConfig
#define EthIf_GetSizeOfEthSwtDrvApiOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfEthSwtDrvApiOfPCConfig
#define EthIf_GetSizeOfEthSwtDrvOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthSwtDrvOfPCConfig
#define EthIf_GetSizeOfEthSwtIndOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthSwtIndOfPCConfig
#define EthIf_GetSizeOfEthSwtOfPCConfig()                                                           EthIf_ConfigDataPtr->SizeOfEthSwtOfPCConfig
#define EthIf_GetSizeOfEthSwtPortInEthSwtContextOfPCConfig()                                        EthIf_ConfigDataPtr->SizeOfEthSwtPortInEthSwtContextOfPCConfig
#define EthIf_GetSizeOfEthSwtPortIndOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfEthSwtPortIndOfPCConfig
#define EthIf_GetSizeOfEthSwtPortOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfEthSwtPortOfPCConfig
#define EthIf_GetSizeOfEthTrcvDrvApiOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfEthTrcvDrvApiOfPCConfig
#define EthIf_GetSizeOfEthTrcvOfPCConfig()                                                          EthIf_ConfigDataPtr->SizeOfEthTrcvOfPCConfig
#define EthIf_GetSizeOfEthTxQueueOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfEthTxQueueOfPCConfig
#define EthIf_GetSizeOfExplicitBufReleaseFilterOfPCConfig()                                         EthIf_ConfigDataPtr->SizeOfExplicitBufReleaseFilterOfPCConfig
#define EthIf_GetSizeOfFloatingRxPduMapOfPCConfig()                                                 EthIf_ConfigDataPtr->SizeOfFloatingRxPduMapOfPCConfig
#define EthIf_GetSizeOfGatewaySrcMacBlackListOfPCConfig()                                           EthIf_ConfigDataPtr->SizeOfGatewaySrcMacBlackListOfPCConfig
#define EthIf_GetSizeOfLegacyWakeupMapOfPCConfig()                                                  EthIf_ConfigDataPtr->SizeOfLegacyWakeupMapOfPCConfig
#define EthIf_GetSizeOfLinkStateChgIndicationsOfPCConfig()                                          EthIf_ConfigDataPtr->SizeOfLinkStateChgIndicationsOfPCConfig
#define EthIf_GetSizeOfMainPartitionRxEthCtrlOfPCConfig()                                           EthIf_ConfigDataPtr->SizeOfMainPartitionRxEthCtrlOfPCConfig
#define EthIf_GetSizeOfMainPartitionTxEthCtrlOfPCConfig()                                           EthIf_ConfigDataPtr->SizeOfMainPartitionTxEthCtrlOfPCConfig
#define EthIf_GetSizeOfMirrorDestOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfMirrorDestOfPCConfig
#define EthIf_GetSizeOfMirrorTxInfoOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfMirrorTxInfoOfPCConfig
#define EthIf_GetSizeOfPhysLayerInitElemsOfPCConfig()                                               EthIf_ConfigDataPtr->SizeOfPhysLayerInitElemsOfPCConfig
#define EthIf_GetSizeOfPhysLayerModeElemsOfPCConfig()                                               EthIf_ConfigDataPtr->SizeOfPhysLayerModeElemsOfPCConfig
#define EthIf_GetSizeOfPortGroupIndOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfPortGroupIndOfPCConfig
#define EthIf_GetSizeOfPortGroupOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfPortGroupOfPCConfig
#define EthIf_GetSizeOfPortModeOfPCConfig()                                                         EthIf_ConfigDataPtr->SizeOfPortModeOfPCConfig
#define EthIf_GetSizeOfRequestedPortModeOfPCConfig()                                                EthIf_ConfigDataPtr->SizeOfRequestedPortModeOfPCConfig
#define EthIf_GetSizeOfRxIndicationsOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfRxIndicationsOfPCConfig
#define EthIf_GetSizeOfRxPduFrameTypeOfPCConfig()                                                   EthIf_ConfigDataPtr->SizeOfRxPduFrameTypeOfPCConfig
#define EthIf_GetSizeOfRxPduMetaDataOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfRxPduMetaDataOfPCConfig
#define EthIf_GetSizeOfRxPduOfPCConfig()                                                            EthIf_ConfigDataPtr->SizeOfRxPduOfPCConfig
#define EthIf_GetSizeOfRxQueueListOfPCConfig()                                                      EthIf_ConfigDataPtr->SizeOfRxQueueListOfPCConfig
#define EthIf_GetSizeOfTxConfirmationsOfPCConfig()                                                  EthIf_ConfigDataPtr->SizeOfTxConfirmationsOfPCConfig
#define EthIf_GetSizeOfTxContextOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfTxContextOfPCConfig
#define EthIf_GetSizeOfTxPduOfPCConfig()                                                            EthIf_ConfigDataPtr->SizeOfTxPduOfPCConfig
#define EthIf_GetSizeOfTxQueueListOfPCConfig()                                                      EthIf_ConfigDataPtr->SizeOfTxQueueListOfPCConfig
#define EthIf_GetSizeOfWakeupMapOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfWakeupMapOfPCConfig
#define EthIf_GetSizeOfWakeupSrcDeviceOfPCConfig()                                                  EthIf_ConfigDataPtr->SizeOfWakeupSrcDeviceOfPCConfig
#define EthIf_GetSrcMacAddrBufferOfPCConfig()                                                       EthIf_ConfigDataPtr->SrcMacAddrBufferOfPCConfig
#define EthIf_GetSwtPortGroupModeChangeReqCntOfPCConfig()                                           EthIf_ConfigDataPtr->SwtPortGroupModeChangeReqCntOfPCConfig
#define EthIf_GetSwtPortGroupModeChangeRetryCounterOfPCConfig()                                     EthIf_ConfigDataPtr->SwtPortGroupModeChangeRetryCounterOfPCConfig
#define EthIf_GetSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()                               EthIf_ConfigDataPtr->SwtPortGroupModeChangeRetryPeriodCounterOfPCConfig
#define EthIf_GetTxConfirmationsOfPCConfig()                                                        EthIf_ConfigDataPtr->TxConfirmationsOfPCConfig
#define EthIf_GetTxContextOfPCConfig()                                                              EthIf_ConfigDataPtr->TxContextOfPCConfig
#define EthIf_GetTxPduContextOfPCConfig()                                                           EthIf_ConfigDataPtr->TxPduContextOfPCConfig
#define EthIf_GetTxPduOfPCConfig()                                                                  EthIf_ConfigDataPtr->TxPduOfPCConfig
#define EthIf_GetTxQueueListOfPCConfig()                                                            EthIf_ConfigDataPtr->TxQueueListOfPCConfig
#define EthIf_GetWakeupMapOfPCConfig()                                                              EthIf_ConfigDataPtr->WakeupMapOfPCConfig
#define EthIf_GetWakeupSrcDeviceOfPCConfig()                                                        EthIf_ConfigDataPtr->WakeupSrcDeviceOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDuplicatedRootDataMacros  EthIf Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define EthIf_GetSizeOfDedicatedRxPduNextFreePosOfPCConfig()                                        EthIf_GetSizeOfEthIfCtrlToRxPduMapOfPCConfig()  /**< the number of accomplishable value elements in EthIf_DedicatedRxPduNextFreePos */
#define EthIf_GetSizeOfEthCtrlInitCntOfPCConfig()                                                   EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlInitCnt */
#define EthIf_GetSizeOfEthCtrlModeCntOfPCConfig()                                                   EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlModeCnt */
#define EthIf_GetSizeOfEthCtrlStateOfPCConfig()                                                     EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlState */
#define EthIf_GetSizeOfEthIfCtrlInitStateOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlInitState */
#define EthIf_GetSizeOfEthIfCtrlLinkCountOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlLinkCount */
#define EthIf_GetSizeOfEthIfCtrlLinkStateOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlLinkState */
#define EthIf_GetSizeOfEthIfCtrlModeOfPCConfig()                                                    EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlMode */
#define EthIf_GetSizeOfEthIfCtrlRxStatsOfPCConfig()                                                 EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlRxStats */
#define EthIf_GetSizeOfEthIfCtrlTxStatsOfPCConfig()                                                 EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlTxStats */
#define EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()                     EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter */
#define EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()                       EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfQualifiedUnexpectedLinkDownTimerState */
#define EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()                         EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfSwitchOffPortGroupTimerDelayCounter */
#define EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()                           EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfSwitchOffPortGroupTimerDelayState */
#define EthIf_GetSizeOfEthIfSwitchOffPortTimerDelayStateOfPCConfig()                                EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfSwitchOffPortTimerDelayState */
#define EthIf_GetSizeOfEthIfSwtPortGroupStateOfPCConfig()                                           EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfSwtPortGroupState */
#define EthIf_GetSizeOfEthSwtInitCntOfPCConfig()                                                    EthIf_GetSizeOfEthSwtOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtInitCnt */
#define EthIf_GetSizeOfEthSwtPortLinkStateOfPCConfig()                                              EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtPortLinkState */
#define EthIf_GetSizeOfEthSwtPortModeCntOfPCConfig()                                                EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtPortModeCnt */
#define EthIf_GetSizeOfEthTrcvInitCntOfPCConfig()                                                   EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvInitCnt */
#define EthIf_GetSizeOfEthTrcvLinkStateOfPCConfig()                                                 EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvLinkState */
#define EthIf_GetSizeOfEthTrcvModeChangeRetryCounterOfPCConfig()                                    EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvModeChangeRetryCounter */
#define EthIf_GetSizeOfEthTrcvModeChangeRetryPeriodCounterOfPCConfig()                              EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvModeChangeRetryPeriodCounter */
#define EthIf_GetSizeOfEthTrcvModeCntOfPCConfig()                                                   EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvModeCnt */
#define EthIf_GetSizeOfEthTrcvModeOfPCConfig()                                                      EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvMode */
#define EthIf_GetSizeOfEthTrcvStateOfPCConfig()                                                     EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvState */
#define EthIf_GetSizeOfFloatingRxPduNextFreePosOfPCConfig()                                         EthIf_GetSizeOfFloatingRxPduMapOfPCConfig()  /**< the number of accomplishable value elements in EthIf_FloatingRxPduNextFreePos */
#define EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                           EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
#define EthIf_GetSizeOfPortGroupLinkStateOfPCConfig()                                               EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupLinkState */
#define EthIf_GetSizeOfPortGroupModeOfPCConfig()                                                    EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupMode */
#define EthIf_GetSizeOfPortGroupNoRoleLinkCountOfPCConfig()                                         EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupNoRoleLinkCount */
#define EthIf_GetSizeOfPortGroupStartupActiveTimerActiveOfPCConfig()                                EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupStartupActiveTimerActive */
#define EthIf_GetSizeOfPortSignalQualityResultOfPCConfig()                                          EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortSignalQualityResult */
#define EthIf_GetSizeOfPortStartupActiveTimerActiveOfPCConfig()                                     EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortStartupActiveTimerActive */
#define EthIf_GetSizeOfRequestedEthIfCtrlModeOfPCConfig()                                           EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RequestedEthIfCtrlMode */
#define EthIf_GetSizeOfRequestedEthTrcvModeOfPCConfig()                                             EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RequestedEthTrcvMode */
#define EthIf_GetSizeOfRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()                                 EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RequestedEthTrcvStateOfEthIfCtrl */
#define EthIf_GetSizeOfRequestedPortGroupModeOfPCConfig()                                           EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RequestedPortGroupMode */
#define EthIf_GetSizeOfRequestedPortGroupStateOfEthIfCtrlOfPCConfig()                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RequestedPortGroupStateOfEthIfCtrl */
#define EthIf_GetSizeOfRxPduContextOfPCConfig()                                                     EthIf_GetSizeOfRxPduOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RxPduContext */
#define EthIf_GetSizeOfRxPduFreeListOfPCConfig()                                                    EthIf_GetSizeOfRxPduOfPCConfig()  /**< the number of accomplishable value elements in EthIf_RxPduFreeList */
#define EthIf_GetSizeOfSignalQualityResultOfPCConfig()                                              EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SignalQualityResult */
#define EthIf_GetSizeOfSrcMacAddrBufferOfPCConfig()                                                 EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SrcMacAddrBuffer */
#define EthIf_GetSizeOfSwtPortGroupModeChangeRetryCounterOfPCConfig()                               EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SwtPortGroupModeChangeRetryCounter */
#define EthIf_GetSizeOfSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()                         EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SwtPortGroupModeChangeRetryPeriodCounter */
#define EthIf_GetSizeOfTxPduContextOfPCConfig()                                                     EthIf_GetSizeOfTxPduOfPCConfig()  /**< the number of accomplishable value elements in EthIf_TxPduContext */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDataMacros  EthIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EthIf_GetDedicatedRxPduNextFreePos(Index)                                                   (EthIf_GetDedicatedRxPduNextFreePosOfPCConfig()[(Index)])
#define EthIf_GetQualityLevelOfEcucPartition(Index)                                                 (EthIf_GetEcucPartitionOfPCConfig()[(Index)].QualityLevelOfEcucPartition)
#define EthIf_IsBufIdxOffsetEnabledOfEthCtrl(Index)                                                 ((EthIf_GetEthCtrlOfPCConfig()[(Index)].BufIdxOffsetEnabledOfEthCtrl) != FALSE)
#define EthIf_IsEthArReleaseRxBufferSupportedOfEthCtrl(Index)                                       ((EthIf_GetEthCtrlOfPCConfig()[(Index)].EthArReleaseRxBufferSupportedOfEthCtrl) != FALSE)
#define EthIf_GetEthDrvApiIdxOfEthCtrl(Index)                                                       (EthIf_GetEthCtrlOfPCConfig()[(Index)].EthDrvApiIdxOfEthCtrl)
#define EthIf_IsImplicitBufferReleaseNeededOfEthCtrl(Index)                                         ((EthIf_GetEthCtrlOfPCConfig()[(Index)].ImplicitBufferReleaseNeededOfEthCtrl) != FALSE)
#define EthIf_GetNumOfTxBuffersOfEthCtrl(Index)                                                     (EthIf_GetEthCtrlOfPCConfig()[(Index)].NumOfTxBuffersOfEthCtrl)
#define EthIf_GetSnvOfEthCtrl(Index)                                                                (EthIf_GetEthCtrlOfPCConfig()[(Index)].SnvOfEthCtrl)
#define EthIf_GetTxContextEndIdxOfEthCtrl(Index)                                                    (EthIf_GetEthCtrlOfPCConfig()[(Index)].TxContextEndIdxOfEthCtrl)
#define EthIf_GetTxContextLengthOfEthCtrl(Index)                                                    (EthIf_GetEthCtrlOfPCConfig()[(Index)].TxContextLengthOfEthCtrl)
#define EthIf_GetTxContextStartIdxOfEthCtrl(Index)                                                  (EthIf_GetEthCtrlOfPCConfig()[(Index)].TxContextStartIdxOfEthCtrl)
#define EthIf_GetEthCtrlInitCnt(Index)                                                              (EthIf_GetEthCtrlInitCntOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlModeCnt(Index)                                                              (EthIf_GetEthCtrlModeCntOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlState(Index)                                                                (EthIf_GetEthCtrlStateOfPCConfig()[(Index)])
#define EthIf_GetCtrlInitOfEthDrvApi(Index)                                                         (EthIf_GetEthDrvApiOfPCConfig()[(Index)].CtrlInitOfEthDrvApi)
#define EthIf_GetEnableEgressTimeStampOfEthDrvApi(Index)                                            (EthIf_GetEthDrvApiOfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApi)
#define EthIf_GetGetBandwidthLimitOfEthDrvApi(Index)                                                (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetBandwidthLimitOfEthDrvApi)
#define EthIf_GetGetCtrlModeOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetCtrlModeOfEthDrvApi)
#define EthIf_GetGetCurrentTimeOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApi)
#define EthIf_GetGetEgressTimeStampOfEthDrvApi(Index)                                               (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApi)
#define EthIf_GetGetIngressTimeStampOfEthDrvApi(Index)                                              (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApi)
#define EthIf_GetGetPhysAddrOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetPhysAddrOfEthDrvApi)
#define EthIf_GetGetRxHeaderPtrOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetRxHeaderPtrOfEthDrvApi)
#define EthIf_GetGetRxStatsOfEthDrvApi(Index)                                                       (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetRxStatsOfEthDrvApi)
#define EthIf_GetGetSpiStatusOfEthDrvApi(Index)                                                     (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetSpiStatusOfEthDrvApi)
#define EthIf_GetGetTxHeaderPtrOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetTxHeaderPtrOfEthDrvApi)
#define EthIf_GetGetTxStatsOfEthDrvApi(Index)                                                       (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetTxStatsOfEthDrvApi)
#define EthIf_GetImmediateTransmitOfEthDrvApi(Index)                                                (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ImmediateTransmitOfEthDrvApi)
#define EthIf_GetProvideExtTxBufferOfEthDrvApi(Index)                                               (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ProvideExtTxBufferOfEthDrvApi)
#define EthIf_GetProvideTxBufferOfEthDrvApi(Index)                                                  (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApi)
#define EthIf_GetReceiveOfEthDrvApi(Index)                                                          (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ReceiveOfEthDrvApi)
#define EthIf_GetReceiveQueueOfEthDrvApi(Index)                                                     (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ReceiveQueueOfEthDrvApi)
#define EthIf_GetReleaseRxBufferOfEthDrvApi(Index)                                                  (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ReleaseRxBufferOfEthDrvApi)
#define EthIf_GetSetBandwidthLimitOfEthDrvApi(Index)                                                (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetBandwidthLimitOfEthDrvApi)
#define EthIf_GetSetCtrlModeOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetCtrlModeOfEthDrvApi)
#define EthIf_GetSetPhysAddrOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetPhysAddrOfEthDrvApi)
#define EthIf_GetTransmitOfEthDrvApi(Index)                                                         (EthIf_GetEthDrvApiOfPCConfig()[(Index)].TransmitOfEthDrvApi)
#define EthIf_GetTxConfirmationOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].TxConfirmationOfEthDrvApi)
#define EthIf_GetTxConfirmationQueueOfEthDrvApi(Index)                                              (EthIf_GetEthDrvApiOfPCConfig()[(Index)].TxConfirmationQueueOfEthDrvApi)
#define EthIf_GetUpdatePhysAddrFilterOfEthDrvApi(Index)                                             (EthIf_GetEthDrvApiOfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApi)
#define EthIf_GetVGetEgressTimeStampOfEthDrvApi(Index)                                              (EthIf_GetEthDrvApiOfPCConfig()[(Index)].VGetEgressTimeStampOfEthDrvApi)
#define EthIf_GetVReleaseRxBufferOfEthDrvApi(Index)                                                 (EthIf_GetEthDrvApiOfPCConfig()[(Index)].VReleaseRxBufferOfEthDrvApi)
#define EthIf_GetVTransmitOfEthDrvApi(Index)                                                        (EthIf_GetEthDrvApiOfPCConfig()[(Index)].VTransmitOfEthDrvApi)
#define EthIf_GetEthClkUnitIdxOfEthIfClkUnit(Index)                                                 (EthIf_GetEthIfClkUnitOfPCConfig()[(Index)].EthClkUnitIdxOfEthIfClkUnit)
#define EthIf_GetEthIfClkUnitIdxOfEthIfClkUnit(Index)                                               (EthIf_GetEthIfClkUnitOfPCConfig()[(Index)].EthIfClkUnitIdxOfEthIfClkUnit)
#define EthIf_GetEthIfControllerModeChangeReqCnt()                                                  ((*(EthIf_GetEthIfControllerModeChangeReqCntOfPCConfig())))
#define EthIf_GetEcucPartitionIdxOfEthIfCtrl(Index)                                                 (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EcucPartitionIdxOfEthIfCtrl)
#define EthIf_GetEthCtrlIdxOfEthIfCtrl(Index)                                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthCtrlIdxOfEthIfCtrl)
#define EthIf_GetEthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrl(Index)                                    (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrl)
#define EthIf_GetEthIfCtrlToEtherTypeMapLengthOfEthIfCtrl(Index)                                    (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthIfCtrlToEtherTypeMapLengthOfEthIfCtrl)
#define EthIf_GetEthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrl(Index)                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrl)
#define EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(Index)                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthIfPhysCtrlCfgIdxOfEthIfCtrl)
#define EthIf_GetEthSwtDrvApiIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthSwtDrvApiIdxOfEthIfCtrl)
#define EthIf_GetGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl(Index)                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].GatewayDestEthIfCtrlIdxIdxOfEthIfCtrl)
#define EthIf_GetGatewayDestEthIfCtrlIdxOfEthIfCtrl(Index)                                          (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].GatewayDestEthIfCtrlIdxOfEthIfCtrl)
#define EthIf_GetLinkAggrThresholdOfEthIfCtrl(Index)                                                (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].LinkAggrThresholdOfEthIfCtrl)
#define EthIf_GetMacSecTypeOfEthIfCtrl(Index)                                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MacSecTypeOfEthIfCtrl)
#define EthIf_GetMirrorRxDestIdxIdxOfEthIfCtrl(Index)                                               (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorRxDestIdxIdxOfEthIfCtrl)
#define EthIf_GetMirrorRxDestIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorRxDestIdxOfEthIfCtrl)
#define EthIf_GetMirrorTxDestIdxIdxOfEthIfCtrl(Index)                                               (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorTxDestIdxIdxOfEthIfCtrl)
#define EthIf_GetMirrorTxDestIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorTxDestIdxOfEthIfCtrl)
#define EthIf_GetMtuOfEthIfCtrl(Index)                                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MtuOfEthIfCtrl)
#define EthIf_GetPhysLayerInitElemsIdxOfEthIfCtrl(Index)                                            (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].PhysLayerInitElemsIdxOfEthIfCtrl)
#define EthIf_GetPhysLayerModeElemsIdxOfEthIfCtrl(Index)                                            (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].PhysLayerModeElemsIdxOfEthIfCtrl)
#define EthIf_GetSnvOfEthIfCtrl(Index)                                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].SnvOfEthIfCtrl)
#define EthIf_GetTypeOfEthIfCtrl(Index)                                                             (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].TypeOfEthIfCtrl)
#define EthIf_GetVlanIdOfEthIfCtrl(Index)                                                           (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].VlanIdOfEthIfCtrl)
#define EthIf_GetEthIfCtrlInitState(Index)                                                          (EthIf_GetEthIfCtrlInitStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlLinkCount(Index)                                                          (EthIf_GetEthIfCtrlLinkCountOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlLinkState(Index)                                                          (EthIf_GetEthIfCtrlLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlMode(Index)                                                               (EthIf_GetEthIfCtrlModeOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlOfEthTrcvInd(Index)                                                       (EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlOfPortGroupInd(Index)                                                     (EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig()[(Index)])
#define EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)                                                (EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxBytesOfEthIfCtrlRxStats)
#define EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)                                                 (EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxPktsOfEthIfCtrlRxStats)
#define EthIf_GetEtherTypeOfEthIfCtrlToEtherTypeMap(Index)                                          (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].EtherTypeOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetRxIndicationsEndIdxOfEthIfCtrlToEtherTypeMap(Index)                                (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].RxIndicationsEndIdxOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetRxIndicationsLengthOfEthIfCtrlToEtherTypeMap(Index)                                (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].RxIndicationsLengthOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetRxIndicationsStartIdxOfEthIfCtrlToEtherTypeMap(Index)                              (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].RxIndicationsStartIdxOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetTxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMap(Index)                              (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].TxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetTxConfirmationsLengthOfEthIfCtrlToEtherTypeMap(Index)                              (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].TxConfirmationsLengthOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetTxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMap(Index)                            (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig()[(Index)].TxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMap)
#define EthIf_GetRxPduCountOfEthIfCtrlToRxPduMap(Index)                                             (EthIf_GetEthIfCtrlToRxPduMapOfPCConfig()[(Index)].RxPduCountOfEthIfCtrlToRxPduMap)
#define EthIf_GetRxPduEndIdxOfEthIfCtrlToRxPduMap(Index)                                            (EthIf_GetEthIfCtrlToRxPduMapOfPCConfig()[(Index)].RxPduEndIdxOfEthIfCtrlToRxPduMap)
#define EthIf_GetRxPduLengthOfEthIfCtrlToRxPduMap(Index)                                            (EthIf_GetEthIfCtrlToRxPduMapOfPCConfig()[(Index)].RxPduLengthOfEthIfCtrlToRxPduMap)
#define EthIf_GetRxPduStartIdxOfEthIfCtrlToRxPduMap(Index)                                          (EthIf_GetEthIfCtrlToRxPduMapOfPCConfig()[(Index)].RxPduStartIdxOfEthIfCtrlToRxPduMap)
#define EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)                                                (EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxBytesOfEthIfCtrlTxStats)
#define EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)                                                 (EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxPktsOfEthIfCtrlTxStats)
#define EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)                                           (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].DropCtrlIdxOfEthIfMeasurementData)
#define EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)                                      (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].UnknownEtherTypeOfEthIfMeasurementData)
#define EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].VlanDoubleTaggedOfEthIfMeasurementData)
#define EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(Index)                                                (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthCtrlIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(Index)                                              (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthDrvApiIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(Index)                                        (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfClkUnitEndIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfClkUnitLengthOfEthIfPhysCtrlCfg(Index)                                        (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfClkUnitLengthOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(Index)                                      (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfClkUnitStartIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfPhysControllerIdxOfEthIfPhysCtrlCfg(Index)                                    (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfPhysControllerIdxOfEthIfPhysCtrlCfg)
#define EthIf_IsEthPhcSupportAvailableOfEthIfPhysCtrlCfg(Index)                                     ((EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthPhcSupportAvailableOfEthIfPhysCtrlCfg) != FALSE)
#define EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)                                (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()[(Index)])
#define EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerState(Index)                                  (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index)                                    (EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()[(Index)])
#define EthIf_GetEthIfSwitchOffPortGroupTimerDelayState(Index)                                      (EthIf_GetEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt()                                                ((*(EthIf_GetEthIfSwitchOffPortTimeDelayReqCntOfPCConfig())))
#define EthIf_GetEthIfSwitchOffPortTimerDelayState(Index)                                           (EthIf_GetEthIfSwitchOffPortTimerDelayStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfSwtPortGroupState(Index)                                                      (EthIf_GetEthIfSwtPortGroupStateOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlIdxOfEthRxQueue(Index)                                                      (EthIf_GetEthRxQueueOfPCConfig()[(Index)].EthCtrlIdxOfEthRxQueue)
#define EthIf_GetQueueIndexOfEthRxQueue(Index)                                                      (EthIf_GetEthRxQueueOfPCConfig()[(Index)].QueueIndexOfEthRxQueue)
#define EthIf_GetEthSwtDrvApiIdxOfEthSwt(Index)                                                     (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtDrvApiIdxOfEthSwt)
#define EthIf_GetEthSwtPortInEthSwtContextEndIdxOfEthSwt(Index)                                     (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtPortInEthSwtContextEndIdxOfEthSwt)
#define EthIf_GetEthSwtPortInEthSwtContextLengthOfEthSwt(Index)                                     (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtPortInEthSwtContextLengthOfEthSwt)
#define EthIf_GetEthSwtPortInEthSwtContextStartIdxOfEthSwt(Index)                                   (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtPortInEthSwtContextStartIdxOfEthSwt)
#define EthIf_GetSnvOfEthSwt(Index)                                                                 (EthIf_GetEthSwtOfPCConfig()[(Index)].SnvOfEthSwt)
#define EthIf_GetEthSwtEndIdxOfEthSwtDrv(Index)                                                     (EthIf_GetEthSwtDrvOfPCConfig()[(Index)].EthSwtEndIdxOfEthSwtDrv)
#define EthIf_GetEthSwtLengthOfEthSwtDrv(Index)                                                     (EthIf_GetEthSwtDrvOfPCConfig()[(Index)].EthSwtLengthOfEthSwtDrv)
#define EthIf_GetEthSwtStartIdxOfEthSwtDrv(Index)                                                   (EthIf_GetEthSwtDrvOfPCConfig()[(Index)].EthSwtStartIdxOfEthSwtDrv)
#define EthIf_GetCheckWakeupOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].CheckWakeupOfEthSwtDrvApi)
#define EthIf_GetEnableVlanOfEthSwtDrvApi(Index)                                                    (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].EnableVlanOfEthSwtDrvApi)
#define EthIf_GetGetArlTableOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetArlTableOfEthSwtDrvApi)
#define EthIf_GetGetBaudRateOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetBaudRateOfEthSwtDrvApi)
#define EthIf_GetGetBufferLevelOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetBufferLevelOfEthSwtDrvApi)
#define EthIf_GetGetCounterValuesOfEthSwtDrvApi(Index)                                              (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetCounterValuesOfEthSwtDrvApi)
#define EthIf_GetGetDropCountOfEthSwtDrvApi(Index)                                                  (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetDropCountOfEthSwtDrvApi)
#define EthIf_GetGetDuplexModeOfEthSwtDrvApi(Index)                                                 (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetDuplexModeOfEthSwtDrvApi)
#define EthIf_GetGetLinkStateOfEthSwtDrvApi(Index)                                                  (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetLinkStateOfEthSwtDrvApi)
#define EthIf_GetGetMacLearningModeOfEthSwtDrvApi(Index)                                            (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetMacLearningModeOfEthSwtDrvApi)
#define EthIf_GetGetPortCableDiagnosticsResultOfEthSwtDrvApi(Index)                                 (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortCableDiagnosticsResultOfEthSwtDrvApi)
#define EthIf_GetGetPortMacAddrOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortMacAddrOfEthSwtDrvApi)
#define EthIf_GetGetPortSignalQualityOfEthSwtDrvApi(Index)                                          (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortSignalQualityOfEthSwtDrvApi)
#define EthIf_GetGetRxMgmtObjectOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetRxMgmtObjectOfEthSwtDrvApi)
#define EthIf_GetGetRxStatsOfEthSwtDrvApi(Index)                                                    (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetRxStatsOfEthSwtDrvApi)
#define EthIf_GetGetSwitchPortWakeupReasonOfEthSwtDrvApi(Index)                                     (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetSwitchPortWakeupReasonOfEthSwtDrvApi)
#define EthIf_GetGetSwtPortModeOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetSwtPortModeOfEthSwtDrvApi)
#define EthIf_GetGetTxErrorCounterValuesOfEthSwtDrvApi(Index)                                       (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthSwtDrvApi)
#define EthIf_GetGetTxMgmtObjectOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetTxMgmtObjectOfEthSwtDrvApi)
#define EthIf_GetGetTxStatsOfEthSwtDrvApi(Index)                                                    (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetTxStatsOfEthSwtDrvApi)
#define EthIf_GetPortEnableTimeStampOfEthSwtDrvApi(Index)                                           (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].PortEnableTimeStampOfEthSwtDrvApi)
#define EthIf_GetResetConfigOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].ResetConfigOfEthSwtDrvApi)
#define EthIf_GetRunPortCableDiagnosticOfEthSwtDrvApi(Index)                                        (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].RunPortCableDiagnosticOfEthSwtDrvApi)
#define EthIf_GetSetCorrectionTimeOfEthSwtDrvApi(Index)                                             (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetCorrectionTimeOfEthSwtDrvApi)
#define EthIf_GetSetMacLearningModeOfEthSwtDrvApi(Index)                                            (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetMacLearningModeOfEthSwtDrvApi)
#define EthIf_GetSetSwtMgmtInfoOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetSwtMgmtInfoOfEthSwtDrvApi)
#define EthIf_GetSetSwtPortModeOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetSwtPortModeOfEthSwtDrvApi)
#define EthIf_GetStartQbvScheduleOfEthSwtDrvApi(Index)                                              (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StartQbvScheduleOfEthSwtDrvApi)
#define EthIf_GetStartSwtPortAutoNegOfEthSwtDrvApi(Index)                                           (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StartSwtPortAutoNegOfEthSwtDrvApi)
#define EthIf_GetStopQbvScheduleOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StopQbvScheduleOfEthSwtDrvApi)
#define EthIf_GetStoreConfigOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StoreConfigOfEthSwtDrvApi)
#define EthIf_GetSwtInitOfEthSwtDrvApi(Index)                                                       (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SwtInitOfEthSwtDrvApi)
#define EthIf_GetUpdateMCastPortAssignmentOfEthSwtDrvApi(Index)                                     (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].UpdateMCastPortAssignmentOfEthSwtDrvApi)
#define EthIf_GetEthSwtInd(Index)                                                                   (EthIf_GetEthSwtIndOfPCConfig()[(Index)])
#define EthIf_GetEthSwtInitCnt(Index)                                                               (EthIf_GetEthSwtInitCntOfPCConfig()[(Index)])
#define EthIf_IsAsyncProcessingOfEthSwtPort(Index)                                                  ((EthIf_GetEthSwtPortOfPCConfig()[(Index)].AsyncProcessingOfEthSwtPort) != FALSE)
#define EthIf_GetEthSwtIdxOfEthSwtPort(Index)                                                       (EthIf_GetEthSwtPortOfPCConfig()[(Index)].EthSwtIdxOfEthSwtPort)
#define EthIf_GetEthSwtPortHostOrUpLinkPortIdxOfEthSwtPort(Index)                                   (EthIf_GetEthSwtPortOfPCConfig()[(Index)].EthSwtPortHostOrUpLinkPortIdxOfEthSwtPort)
#define EthIf_IsMacSecSecuredOfEthSwtPort(Index)                                                    ((EthIf_GetEthSwtPortOfPCConfig()[(Index)].MacSecSecuredOfEthSwtPort) != FALSE)
#define EthIf_GetMkaPaeIdxOfEthSwtPort(Index)                                                       (EthIf_GetEthSwtPortOfPCConfig()[(Index)].MkaPaeIdxOfEthSwtPort)
#define EthIf_GetPortGroupIndEndIdxOfEthSwtPort(Index)                                              (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortGroupIndEndIdxOfEthSwtPort)
#define EthIf_GetPortGroupIndStartIdxOfEthSwtPort(Index)                                            (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortGroupIndStartIdxOfEthSwtPort)
#define EthIf_GetPortRoleOfEthSwtPort(Index)                                                        (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortRoleOfEthSwtPort)
#define EthIf_GetSnvOfEthSwtPort(Index)                                                             (EthIf_GetEthSwtPortOfPCConfig()[(Index)].SnvOfEthSwtPort)
#define EthIf_GetEthSwtPortIdxOfEthSwtPortInEthSwtContext(Index)                                    (EthIf_GetEthSwtPortInEthSwtContextOfPCConfig()[(Index)].EthSwtPortIdxOfEthSwtPortInEthSwtContext)
#define EthIf_GetEthSwtPortInd(Index)                                                               (EthIf_GetEthSwtPortIndOfPCConfig()[(Index)])
#define EthIf_GetEthSwtPortLinkState(Index)                                                         (EthIf_GetEthSwtPortLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthSwtPortModeCnt(Index)                                                           (EthIf_GetEthSwtPortModeCntOfPCConfig()[(Index)])
#define EthIf_IsAsyncProcessingOfEthTrcv(Index)                                                     ((EthIf_GetEthTrcvOfPCConfig()[(Index)].AsyncProcessingOfEthTrcv) != FALSE)
#define EthIf_GetEthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv(Index)                                        (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv)
#define EthIf_GetEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv(Index)                                      (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv)
#define EthIf_GetEthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcv(Index)                         (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcv)
#define EthIf_IsEthTrcvActAsSlavePassiveEnabledOfEthTrcv(Index)                                     ((EthIf_GetEthTrcvOfPCConfig()[(Index)].EthTrcvActAsSlavePassiveEnabledOfEthTrcv) != FALSE)
#define EthIf_GetEthTrcvDrvApiIdxOfEthTrcv(Index)                                                   (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthTrcvDrvApiIdxOfEthTrcv)
#define EthIf_GetEthTrcvTypeOfEthTrcv(Index)                                                        (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthTrcvTypeOfEthTrcv)
#define EthIf_IsMacSecSecuredOfEthTrcv(Index)                                                       ((EthIf_GetEthTrcvOfPCConfig()[(Index)].MacSecSecuredOfEthTrcv) != FALSE)
#define EthIf_GetMkaPaeIdxOfEthTrcv(Index)                                                          (EthIf_GetEthTrcvOfPCConfig()[(Index)].MkaPaeIdxOfEthTrcv)
#define EthIf_GetPortModeIdxOfEthTrcv(Index)                                                        (EthIf_GetEthTrcvOfPCConfig()[(Index)].PortModeIdxOfEthTrcv)
#define EthIf_GetRequestedPortModeIdxOfEthTrcv(Index)                                               (EthIf_GetEthTrcvOfPCConfig()[(Index)].RequestedPortModeIdxOfEthTrcv)
#define EthIf_GetSnvOfEthTrcv(Index)                                                                (EthIf_GetEthTrcvOfPCConfig()[(Index)].SnvOfEthTrcv)
#define EthIf_GetUserSleepIndicationOfEthTrcv(Index)                                                (EthIf_GetEthTrcvOfPCConfig()[(Index)].UserSleepIndicationOfEthTrcv)
#define EthIf_GetCheckWakeupOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].CheckWakeupOfEthTrcvDrvApi)
#define EthIf_GetGetBaudRateOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetBaudRateOfEthTrcvDrvApi)
#define EthIf_GetGetCableDiagnosticsResultOfEthTrcvDrvApi(Index)                                    (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetCableDiagnosticsResultOfEthTrcvDrvApi)
#define EthIf_GetGetDuplexModeOfEthTrcvDrvApi(Index)                                                (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetDuplexModeOfEthTrcvDrvApi)
#define EthIf_GetGetLinkStateOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetLinkStateOfEthTrcvDrvApi)
#define EthIf_GetGetPhySignalQualityOfEthTrcvDrvApi(Index)                                          (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetPhySignalQualityOfEthTrcvDrvApi)
#define EthIf_GetGetPhyWakeupReasonOfEthTrcvDrvApi(Index)                                           (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetPhyWakeupReasonOfEthTrcvDrvApi)
#define EthIf_GetGetTrcvModeOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetTrcvModeOfEthTrcvDrvApi)
#define EthIf_GetRunCableDiagnosticOfEthTrcvDrvApi(Index)                                           (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].RunCableDiagnosticOfEthTrcvDrvApi)
#define EthIf_GetSetPhyLoopbackModeOfEthTrcvDrvApi(Index)                                           (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyLoopbackModeOfEthTrcvDrvApi)
#define EthIf_GetSetPhyTestModeOfEthTrcvDrvApi(Index)                                               (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyTestModeOfEthTrcvDrvApi)
#define EthIf_GetSetPhyTxModeOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyTxModeOfEthTrcvDrvApi)
#define EthIf_GetSetTrcvModeOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetTrcvModeOfEthTrcvDrvApi)
#define EthIf_GetStartAutoNegOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].StartAutoNegOfEthTrcvDrvApi)
#define EthIf_GetTrcvInitOfEthTrcvDrvApi(Index)                                                     (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].TrcvInitOfEthTrcvDrvApi)
#define EthIf_GetEthTrcvInitCnt(Index)                                                              (EthIf_GetEthTrcvInitCntOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvLinkState(Index)                                                            (EthIf_GetEthTrcvLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvMode(Index)                                                                 (EthIf_GetEthTrcvModeOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvModeChangeRetryCounter(Index)                                               (EthIf_GetEthTrcvModeChangeRetryCounterOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index)                                         (EthIf_GetEthTrcvModeChangeRetryPeriodCounterOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvModeCnt(Index)                                                              (EthIf_GetEthTrcvModeCntOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvState(Index)                                                                (EthIf_GetEthTrcvStateOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlIdxOfEthTxQueue(Index)                                                      (EthIf_GetEthTxQueueOfPCConfig()[(Index)].EthCtrlIdxOfEthTxQueue)
#define EthIf_GetQueueIndexOfEthTxQueue(Index)                                                      (EthIf_GetEthTxQueueOfPCConfig()[(Index)].QueueIndexOfEthTxQueue)
#define EthIf_GetEthIfCtrlIdxOfExplicitBufReleaseFilter(Index)                                      (EthIf_GetExplicitBufReleaseFilterOfPCConfig()[(Index)].EthIfCtrlIdxOfExplicitBufReleaseFilter)
#define EthIf_IsEtherTypeConfiguredOfExplicitBufReleaseFilter(Index)                                ((EthIf_GetExplicitBufReleaseFilterOfPCConfig()[(Index)].EtherTypeConfiguredOfExplicitBufReleaseFilter) != FALSE)
#define EthIf_GetEtherTypeOfExplicitBufReleaseFilter(Index)                                         (EthIf_GetExplicitBufReleaseFilterOfPCConfig()[(Index)].EtherTypeOfExplicitBufReleaseFilter)
#define EthIf_GetRxPduEndIdxOfFloatingRxPduMap(Index)                                               (EthIf_GetFloatingRxPduMapOfPCConfig()[(Index)].RxPduEndIdxOfFloatingRxPduMap)
#define EthIf_GetRxPduLengthOfFloatingRxPduMap(Index)                                               (EthIf_GetFloatingRxPduMapOfPCConfig()[(Index)].RxPduLengthOfFloatingRxPduMap)
#define EthIf_GetRxPduStartIdxOfFloatingRxPduMap(Index)                                             (EthIf_GetFloatingRxPduMapOfPCConfig()[(Index)].RxPduStartIdxOfFloatingRxPduMap)
#define EthIf_GetFloatingRxPduNextFreePos(Index)                                                    (EthIf_GetFloatingRxPduNextFreePosOfPCConfig()[(Index)])
#define EthIf_GetMacAddrOfGatewaySrcMacBlackList(Index)                                             (EthIf_GetGatewaySrcMacBlackListOfPCConfig()[(Index)].MacAddrOfGatewaySrcMacBlackList)
#define EthIf_IsGlobalStartupActiveTimerActive()                                                    (((*(EthIf_GetGlobalStartupActiveTimerActiveOfPCConfig()))) != FALSE)
#define EthIf_IsInitLocked()                                                                        (((*(EthIf_GetInitLockedOfPCConfig()))) != FALSE)
#define EthIf_GetEthTrcvIdxOfLegacyWakeupMap(Index)                                                 (EthIf_GetLegacyWakeupMapOfPCConfig()[(Index)].EthTrcvIdxOfLegacyWakeupMap)
#define EthIf_GetWakeupSourceOfLegacyWakeupMap(Index)                                               (EthIf_GetLegacyWakeupMapOfPCConfig()[(Index)].WakeupSourceOfLegacyWakeupMap)
#define EthIf_GetLinkStateChgIndications(Index)                                                     (EthIf_GetLinkStateChgIndicationsOfPCConfig()[(Index)])
#define EthIf_GetMainFuncStateDecoupleFreqCnt()                                                     ((*(EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig())))
#define EthIf_GetEthCtrlIdxOfMainPartitionRxEthCtrl(Index)                                          (EthIf_GetMainPartitionRxEthCtrlOfPCConfig()[(Index)].EthCtrlIdxOfMainPartitionRxEthCtrl)
#define EthIf_GetEthCtrlIdxOfMainPartitionTxEthCtrl(Index)                                          (EthIf_GetMainPartitionTxEthCtrlOfPCConfig()[(Index)].EthCtrlIdxOfMainPartitionTxEthCtrl)
#define EthIf_GetEthCtrlIdxOfMirrorDest(Index)                                                      (EthIf_GetMirrorDestOfPCConfig()[(Index)].EthCtrlIdxOfMirrorDest)
#define EthIf_IsKeepSrcMacEnabledOfMirrorDest(Index)                                                ((EthIf_GetMirrorDestOfPCConfig()[(Index)].KeepSrcMacEnabledOfMirrorDest) != FALSE)
#define EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestEthTxBufferIdxOfMirrorTxInfo)
#define EthIf_GetDestPayloadPtrOfMirrorTxInfo(Index)                                                (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestPayloadPtrOfMirrorTxInfo)
#define EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].EthIfCtrlIdxOfMirrorTxInfo)
#define EthIf_IsInfoValidOfMirrorTxInfo(Index)                                                      ((EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].InfoValidOfMirrorTxInfo) != FALSE)
#define EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcEthTxBufferIdxOfMirrorTxInfo)
#define EthIf_GetSrcPayloadPtrOfMirrorTxInfo(Index)                                                 (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcPayloadPtrOfMirrorTxInfo)
#define EthIf_IsUsedOfMirrorTxInfo(Index)                                                           ((EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].UsedOfMirrorTxInfo) != FALSE)
#define EthIf_IsModeChangeLocked()                                                                  (((*(EthIf_GetModeChangeLockedOfPCConfig()))) != FALSE)
#define EthIf_GetEthSwtIndEndIdxOfPhysLayerInitElems(Index)                                         (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthSwtIndEndIdxOfPhysLayerInitElems)
#define EthIf_GetEthSwtIndStartIdxOfPhysLayerInitElems(Index)                                       (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthSwtIndStartIdxOfPhysLayerInitElems)
#define EthIf_GetEthTrcvIdxOfPhysLayerInitElems(Index)                                              (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthTrcvIdxOfPhysLayerInitElems)
#define EthIf_GetEthTrcvIdxOfPhysLayerModeElems(Index)                                              (EthIf_GetPhysLayerModeElemsOfPCConfig()[(Index)].EthTrcvIdxOfPhysLayerModeElems)
#define EthIf_GetPortGroupIdxOfPhysLayerModeElems(Index)                                            (EthIf_GetPhysLayerModeElemsOfPCConfig()[(Index)].PortGroupIdxOfPhysLayerModeElems)
#define EthIf_GetEthIfCtrlOfPortGroupIndEndIdxOfPortGroup(Index)                                    (EthIf_GetPortGroupOfPCConfig()[(Index)].EthIfCtrlOfPortGroupIndEndIdxOfPortGroup)
#define EthIf_GetEthIfCtrlOfPortGroupIndStartIdxOfPortGroup(Index)                                  (EthIf_GetPortGroupOfPCConfig()[(Index)].EthIfCtrlOfPortGroupIndStartIdxOfPortGroup)
#define EthIf_GetEthSwtPortIndEndIdxOfPortGroup(Index)                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].EthSwtPortIndEndIdxOfPortGroup)
#define EthIf_GetEthSwtPortIndStartIdxOfPortGroup(Index)                                            (EthIf_GetPortGroupOfPCConfig()[(Index)].EthSwtPortIndStartIdxOfPortGroup)
#define EthIf_GetHostAndUpLinkPortThresholdOfPortGroup(Index)                                       (EthIf_GetPortGroupOfPCConfig()[(Index)].HostAndUpLinkPortThresholdOfPortGroup)
#define EthIf_GetNoRolePortThresholdOfPortGroup(Index)                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].NoRolePortThresholdOfPortGroup)
#define EthIf_GetSemanticOfPortGroup(Index)                                                         (EthIf_GetPortGroupOfPCConfig()[(Index)].SemanticOfPortGroup)
#define EthIf_GetSnvOfPortGroup(Index)                                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].SnvOfPortGroup)
#define EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()[(Index)])
#define EthIf_GetPortGroupInd(Index)                                                                (EthIf_GetPortGroupIndOfPCConfig()[(Index)])
#define EthIf_GetPortGroupLinkState(Index)                                                          (EthIf_GetPortGroupLinkStateOfPCConfig()[(Index)])
#define EthIf_GetPortGroupMode(Index)                                                               (EthIf_GetPortGroupModeOfPCConfig()[(Index)])
#define EthIf_GetPortGroupNoRoleLinkCount(Index)                                                    (EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()[(Index)])
#define EthIf_IsPortGroupStartupActiveTimerActive(Index)                                            ((EthIf_GetPortGroupStartupActiveTimerActiveOfPCConfig()[(Index)]) != FALSE)
#define EthIf_GetPortMode(Index)                                                                    (EthIf_GetPortModeOfPCConfig()[(Index)])
#define EthIf_GetPortSignalQualityResult(Index)                                                     (EthIf_GetPortSignalQualityResultOfPCConfig()[(Index)])
#define EthIf_GetPortStartupActiveTimeCounter()                                                     ((*(EthIf_GetPortStartupActiveTimeCounterOfPCConfig())))
#define EthIf_IsPortStartupActiveTimerActive(Index)                                                 ((EthIf_GetPortStartupActiveTimerActiveOfPCConfig()[(Index)]) != FALSE)
#define EthIf_GetRequestedEthIfCtrlMode(Index)                                                      (EthIf_GetRequestedEthIfCtrlModeOfPCConfig()[(Index)])
#define EthIf_GetRequestedEthTrcvMode(Index)                                                        (EthIf_GetRequestedEthTrcvModeOfPCConfig()[(Index)])
#define EthIf_GetRequestedEthTrcvStateOfEthIfCtrl(Index)                                            (EthIf_GetRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()[(Index)])
#define EthIf_GetRequestedPortGroupMode(Index)                                                      (EthIf_GetRequestedPortGroupModeOfPCConfig()[(Index)])
#define EthIf_GetRequestedPortGroupStateOfEthIfCtrl(Index)                                          (EthIf_GetRequestedPortGroupStateOfEthIfCtrlOfPCConfig()[(Index)])
#define EthIf_GetRequestedPortMode(Index)                                                           (EthIf_GetRequestedPortModeOfPCConfig()[(Index)])
#define EthIf_GetRxIndications(Index)                                                               (EthIf_GetRxIndicationsOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlToRxPduMapIdxOfRxPdu(Index)                                               (EthIf_GetRxPduOfPCConfig()[(Index)].EthIfCtrlToRxPduMapIdxOfRxPdu)
#define EthIf_GetEthMacAddrOffsetOfRxPdu(Index)                                                     (EthIf_GetRxPduOfPCConfig()[(Index)].EthMacAddrOffsetOfRxPdu)
#define EthIf_IsFloatingPoolOfRxPdu(Index)                                                          ((EthIf_GetRxPduOfPCConfig()[(Index)].FloatingPoolOfRxPdu) != FALSE)
#define EthIf_GetFloatingRxPduMapIdxOfRxPdu(Index)                                                  (EthIf_GetRxPduOfPCConfig()[(Index)].FloatingRxPduMapIdxOfRxPdu)
#define EthIf_IsKeepLocalBufferOfRxPdu(Index)                                                       ((EthIf_GetRxPduOfPCConfig()[(Index)].KeepLocalBufferOfRxPdu) != FALSE)
#define EthIf_GetRxPduMetaDataEndIdxOfRxPdu(Index)                                                  (EthIf_GetRxPduOfPCConfig()[(Index)].RxPduMetaDataEndIdxOfRxPdu)
#define EthIf_GetRxPduMetaDataLengthOfRxPdu(Index)                                                  (EthIf_GetRxPduOfPCConfig()[(Index)].RxPduMetaDataLengthOfRxPdu)
#define EthIf_GetRxPduMetaDataStartIdxOfRxPdu(Index)                                                (EthIf_GetRxPduOfPCConfig()[(Index)].RxPduMetaDataStartIdxOfRxPdu)
#define EthIf_GetTimeTuplePtrOffsetOfRxPdu(Index)                                                   (EthIf_GetRxPduOfPCConfig()[(Index)].TimeTuplePtrOffsetOfRxPdu)
#define EthIf_GetUlPduIdOfRxPdu(Index)                                                              (EthIf_GetRxPduOfPCConfig()[(Index)].UlPduIdOfRxPdu)
#define EthIf_IsValidEthMacAddrMetaDataOfRxPdu(Index)                                               ((EthIf_GetRxPduOfPCConfig()[(Index)].ValidEthMacAddrMetaDataOfRxPdu) != FALSE)
#define EthIf_IsValidTimeTupleMetaDataOfRxPdu(Index)                                                ((EthIf_GetRxPduOfPCConfig()[(Index)].ValidTimeTupleMetaDataOfRxPdu) != FALSE)
#define EthIf_GetEthIfCtrlIdxOfRxPduContext(Index)                                                  (EthIf_GetRxPduContextOfPCConfig()[(Index)].EthIfCtrlIdxOfRxPduContext)
#define EthIf_GetRxHandleIdOfRxPduContext(Index)                                                    (EthIf_GetRxPduContextOfPCConfig()[(Index)].RxHandleIdOfRxPduContext)
#define EthIf_GetStateOfRxPduContext(Index)                                                         (EthIf_GetRxPduContextOfPCConfig()[(Index)].StateOfRxPduContext)
#define EthIf_GetTimeTupleOfRxPduContext(Index)                                                     (EthIf_GetRxPduContextOfPCConfig()[(Index)].TimeTupleOfRxPduContext)
#define EthIf_GetEthIfCtrlToRxPduMapEndIdxOfRxPduFrameType(Index)                                   (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].EthIfCtrlToRxPduMapEndIdxOfRxPduFrameType)
#define EthIf_GetEthIfCtrlToRxPduMapLengthOfRxPduFrameType(Index)                                   (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].EthIfCtrlToRxPduMapLengthOfRxPduFrameType)
#define EthIf_GetEthIfCtrlToRxPduMapStartIdxOfRxPduFrameType(Index)                                 (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].EthIfCtrlToRxPduMapStartIdxOfRxPduFrameType)
#define EthIf_GetEtherTypeOfRxPduFrameType(Index)                                                   (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].EtherTypeOfRxPduFrameType)
#define EthIf_GetFloatingRxPduMapEndIdxOfRxPduFrameType(Index)                                      (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].FloatingRxPduMapEndIdxOfRxPduFrameType)
#define EthIf_GetFloatingRxPduMapLengthOfRxPduFrameType(Index)                                      (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].FloatingRxPduMapLengthOfRxPduFrameType)
#define EthIf_GetFloatingRxPduMapStartIdxOfRxPduFrameType(Index)                                    (EthIf_GetRxPduFrameTypeOfPCConfig()[(Index)].FloatingRxPduMapStartIdxOfRxPduFrameType)
#define EthIf_GetPduIdOfRxPduFreeList(Index)                                                        (EthIf_GetRxPduFreeListOfPCConfig()[(Index)].PduIdOfRxPduFreeList)
#define EthIf_GetRxPduMetaData(Index)                                                               (EthIf_GetRxPduMetaDataOfPCConfig()[(Index)])
#define EthIf_GetEthRxQueueEndIdxOfRxQueueList(Index)                                               (EthIf_GetRxQueueListOfPCConfig()[(Index)].EthRxQueueEndIdxOfRxQueueList)
#define EthIf_GetEthRxQueueLengthOfRxQueueList(Index)                                               (EthIf_GetRxQueueListOfPCConfig()[(Index)].EthRxQueueLengthOfRxQueueList)
#define EthIf_GetEthRxQueueStartIdxOfRxQueueList(Index)                                             (EthIf_GetRxQueueListOfPCConfig()[(Index)].EthRxQueueStartIdxOfRxQueueList)
#define EthIf_GetSignalQualityDecoupleFreqCnt()                                                     ((*(EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig())))
#define EthIf_GetSignalQualityResult(Index)                                                         (EthIf_GetSignalQualityResultOfPCConfig()[(Index)])
#define EthIf_GetSrcMacOfSrcMacAddrBuffer(Index)                                                    (EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].SrcMacOfSrcMacAddrBuffer)
#define EthIf_IsValidOfSrcMacAddrBuffer(Index)                                                      ((EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].ValidOfSrcMacAddrBuffer) != FALSE)
#define EthIf_GetSwtPortGroupModeChangeReqCnt()                                                     ((*(EthIf_GetSwtPortGroupModeChangeReqCntOfPCConfig())))
#define EthIf_GetSwtPortGroupModeChangeRetryCounter(Index)                                          (EthIf_GetSwtPortGroupModeChangeRetryCounterOfPCConfig()[(Index)])
#define EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index)                                    (EthIf_GetSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()[(Index)])
#define EthIf_GetTxConfirmations(Index)                                                             (EthIf_GetTxConfirmationsOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlIdxOfTxContext(Index)                                                     (EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlIdxOfTxContext)
#define EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)                                       (EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlToEtherTypeMapIdxOfTxContext)
#define EthIf_GetFrameHdrOfTxContext(Index)                                                         (EthIf_GetTxContextOfPCConfig()[(Index)].FrameHdrOfTxContext)
#define EthIf_GetLinkedPduIdOfTxContext(Index)                                                      (EthIf_GetTxContextOfPCConfig()[(Index)].LinkedPduIdOfTxContext)
#define EthIf_GetPayloadLenOfTxContext(Index)                                                       (EthIf_GetTxContextOfPCConfig()[(Index)].PayloadLenOfTxContext)
#define EthIf_GetPayloadPtrOfTxContext(Index)                                                       (EthIf_GetTxContextOfPCConfig()[(Index)].PayloadPtrOfTxContext)
#define EthIf_IsTxPendingOfTxContext(Index)                                                         ((EthIf_GetTxContextOfPCConfig()[(Index)].TxPendingOfTxContext) != FALSE)
#define EthIf_IsValidOfTxContext(Index)                                                             ((EthIf_GetTxContextOfPCConfig()[(Index)].ValidOfTxContext) != FALSE)
#define EthIf_IsValidPduIdOfTxContext(Index)                                                        ((EthIf_GetTxContextOfPCConfig()[(Index)].ValidPduIdOfTxContext) != FALSE)
#define EthIf_IsDirectDataProvisionOfTxPdu(Index)                                                   ((EthIf_GetTxPduOfPCConfig()[(Index)].DirectDataProvisionOfTxPdu) != FALSE)
#define EthIf_IsEgressHardwareSupportedDataTransferOfTxPdu(Index)                                   ((EthIf_GetTxPduOfPCConfig()[(Index)].EgressHardwareSupportedDataTransferOfTxPdu) != FALSE)
#define EthIf_GetEthIfCtrlIdxOfTxPdu(Index)                                                         (EthIf_GetTxPduOfPCConfig()[(Index)].EthIfCtrlIdxOfTxPdu)
#define EthIf_GetEthMacAddrOffsetOfTxPdu(Index)                                                     (EthIf_GetTxPduOfPCConfig()[(Index)].EthMacAddrOffsetOfTxPdu)
#define EthIf_GetEtherTypeOfTxPdu(Index)                                                            (EthIf_GetTxPduOfPCConfig()[(Index)].EtherTypeOfTxPdu)
#define EthIf_GetFrameTxPriorityOfTxPdu(Index)                                                      (EthIf_GetTxPduOfPCConfig()[(Index)].FrameTxPriorityOfTxPdu)
#define EthIf_IsKeepLocalBufferOfTxPdu(Index)                                                       ((EthIf_GetTxPduOfPCConfig()[(Index)].KeepLocalBufferOfTxPdu) != FALSE)
#define EthIf_GetListItemPtrOffsetOfTxPdu(Index)                                                    (EthIf_GetTxPduOfPCConfig()[(Index)].ListItemPtrOffsetOfTxPdu)
#define EthIf_GetPriorityOffsetOfTxPdu(Index)                                                       (EthIf_GetTxPduOfPCConfig()[(Index)].PriorityOffsetOfTxPdu)
#define EthIf_GetTimeTuplePtrOffsetOfTxPdu(Index)                                                   (EthIf_GetTxPduOfPCConfig()[(Index)].TimeTuplePtrOffsetOfTxPdu)
#define EthIf_GetTotalMetaDataLengthOfTxPdu(Index)                                                  (EthIf_GetTxPduOfPCConfig()[(Index)].TotalMetaDataLengthOfTxPdu)
#define EthIf_GetUlPduIdOfTxPdu(Index)                                                              (EthIf_GetTxPduOfPCConfig()[(Index)].UlPduIdOfTxPdu)
#define EthIf_GetVLanOffsetOfTxPdu(Index)                                                           (EthIf_GetTxPduOfPCConfig()[(Index)].VLanOffsetOfTxPdu)
#define EthIf_IsValidEthMacAddrMetaDataOfTxPdu(Index)                                               ((EthIf_GetTxPduOfPCConfig()[(Index)].ValidEthMacAddrMetaDataOfTxPdu) != FALSE)
#define EthIf_IsValidListItemMetaDataOfTxPdu(Index)                                                 ((EthIf_GetTxPduOfPCConfig()[(Index)].ValidListItemMetaDataOfTxPdu) != FALSE)
#define EthIf_IsValidPriority8MetaDataOfTxPdu(Index)                                                ((EthIf_GetTxPduOfPCConfig()[(Index)].ValidPriority8MetaDataOfTxPdu) != FALSE)
#define EthIf_IsValidTimeTupleMetaDataOfTxPdu(Index)                                                ((EthIf_GetTxPduOfPCConfig()[(Index)].ValidTimeTupleMetaDataOfTxPdu) != FALSE)
#define EthIf_IsValidVlan16MetaDataOfTxPdu(Index)                                                   ((EthIf_GetTxPduOfPCConfig()[(Index)].ValidVlan16MetaDataOfTxPdu) != FALSE)
#define EthIf_GetFrameHdrBufOfTxPduContext(Index)                                                   (EthIf_GetTxPduContextOfPCConfig()[(Index)].FrameHdrBufOfTxPduContext)
#define EthIf_GetFrameHdrOfTxPduContext(Index)                                                      (EthIf_GetTxPduContextOfPCConfig()[(Index)].FrameHdrOfTxPduContext)
#define EthIf_GetListElementOfTxPduContext(Index)                                                   (EthIf_GetTxPduContextOfPCConfig()[(Index)].ListElementOfTxPduContext)
#define EthIf_GetStateOfTxPduContext(Index)                                                         (EthIf_GetTxPduContextOfPCConfig()[(Index)].StateOfTxPduContext)
#define EthIf_GetTimeTuplePtrOfTxPduContext(Index)                                                  (EthIf_GetTxPduContextOfPCConfig()[(Index)].TimeTuplePtrOfTxPduContext)
#define EthIf_GetEthTxQueueEndIdxOfTxQueueList(Index)                                               (EthIf_GetTxQueueListOfPCConfig()[(Index)].EthTxQueueEndIdxOfTxQueueList)
#define EthIf_GetEthTxQueueLengthOfTxQueueList(Index)                                               (EthIf_GetTxQueueListOfPCConfig()[(Index)].EthTxQueueLengthOfTxQueueList)
#define EthIf_GetEthTxQueueStartIdxOfTxQueueList(Index)                                             (EthIf_GetTxQueueListOfPCConfig()[(Index)].EthTxQueueStartIdxOfTxQueueList)
#define EthIf_GetWakeupSourceMaskOfWakeupMap(Index)                                                 (EthIf_GetWakeupMapOfPCConfig()[(Index)].WakeupSourceMaskOfWakeupMap)
#define EthIf_GetWakeupSrcDeviceEndIdxOfWakeupMap(Index)                                            (EthIf_GetWakeupMapOfPCConfig()[(Index)].WakeupSrcDeviceEndIdxOfWakeupMap)
#define EthIf_GetWakeupSrcDeviceLengthOfWakeupMap(Index)                                            (EthIf_GetWakeupMapOfPCConfig()[(Index)].WakeupSrcDeviceLengthOfWakeupMap)
#define EthIf_GetWakeupSrcDeviceStartIdxOfWakeupMap(Index)                                          (EthIf_GetWakeupMapOfPCConfig()[(Index)].WakeupSrcDeviceStartIdxOfWakeupMap)
#define EthIf_GetEthSwtIdxOfWakeupSrcDevice(Index)                                                  (EthIf_GetWakeupSrcDeviceOfPCConfig()[(Index)].EthSwtIdxOfWakeupSrcDevice)
#define EthIf_GetEthTrcvIdxOfWakeupSrcDevice(Index)                                                 (EthIf_GetWakeupSrcDeviceOfPCConfig()[(Index)].EthTrcvIdxOfWakeupSrcDevice)
#define EthIf_GetTypeOfWakeupSrcDevice(Index)                                                       (EthIf_GetWakeupSrcDeviceOfPCConfig()[(Index)].TypeOfWakeupSrcDevice)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDeduplicatedDataMacros  EthIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EthIf_IsEcucPartitionUsedOfEthIfCtrl(Index)                                                 (((boolean)(EthIf_GetEcucPartitionIdxOfEthIfCtrl(Index) != ETHIF_NO_ECUCPARTITIONIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EcucPartition */
#define EthIf_IsEthSwtDrvApiUsedOfEthIfCtrl(Index)                                                  (((boolean)(EthIf_GetEthSwtDrvApiIdxOfEthIfCtrl(Index) != ETHIF_NO_ETHSWTDRVAPIIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthSwtDrvApi */
#define EthIf_IsGatewayDestEthIfCtrlIdxUsedOfEthIfCtrl(Index)                                       (((boolean)(EthIf_GetGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthIfCtrl */
#define EthIf_IsMirrorRxDestIdxUsedOfEthIfCtrl(Index)                                               (((boolean)(EthIf_GetMirrorRxDestIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_MIRRORRXDESTIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_MirrorDest */
#define EthIf_IsMirrorTxDestIdxUsedOfEthIfCtrl(Index)                                               (((boolean)(EthIf_GetMirrorTxDestIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_MIRRORTXDESTIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_MirrorDest */
#define EthIf_IsRxIndicationsUsedOfEthIfCtrlToEtherTypeMap(Index)                                   (((boolean)(EthIf_GetRxIndicationsLengthOfEthIfCtrlToEtherTypeMap(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_RxIndications */
#define EthIf_IsTxConfirmationsUsedOfEthIfCtrlToEtherTypeMap(Index)                                 (((boolean)(EthIf_GetTxConfirmationsLengthOfEthIfCtrlToEtherTypeMap(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_TxConfirmations */
#define EthIf_IsRxPduUsedOfEthIfCtrlToRxPduMap(Index)                                               (((boolean)(EthIf_GetRxPduLengthOfEthIfCtrlToRxPduMap(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_RxPdu */
#define EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(Index)                                           (((boolean)(EthIf_GetEthIfClkUnitLengthOfEthIfPhysCtrlCfg(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfClkUnit */
#define EthIf_GetEthIfSwitchOffPortTimeDelayCounts()                                                EthIf_GetEthIfSwitchOffPortTimeDelayCountsOfPCConfig()
#define EthIf_IsEthSwtPortInEthSwtContextUsedOfEthSwt(Index)                                        (((boolean)(EthIf_GetEthSwtPortInEthSwtContextLengthOfEthSwt(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthSwtPortInEthSwtContext */
#define EthIf_IsEthSwtPortUsedOfEthSwtPortInEthSwtContext(Index)                                    (((boolean)(EthIf_GetEthSwtPortIdxOfEthSwtPortInEthSwtContext(Index) != ETHIF_NO_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthSwtPort */
#define EthIf_IsEthIfCtrlOfEthTrcvIndUsedOfEthTrcv(Index)                                           (((boolean)(EthIf_GetEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv(Index) != ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfCtrlOfEthTrcvInd */
#define EthIf_IsPortModeUsedOfEthTrcv(Index)                                                        (((boolean)(EthIf_GetPortModeIdxOfEthTrcv(Index) != ETHIF_NO_PORTMODEIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_PortMode */
#define EthIf_IsRequestedPortModeUsedOfEthTrcv(Index)                                               (((boolean)(EthIf_GetRequestedPortModeIdxOfEthTrcv(Index) != ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_RequestedPortMode */
#define EthIf_IsRxPduUsedOfFloatingRxPduMap(Index)                                                  (((boolean)(EthIf_GetRxPduLengthOfFloatingRxPduMap(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_RxPdu */
#define EthIf_GetGlobalModeChangeMaxRetryCount()                                                    EthIf_GetGlobalModeChangeMaxRetryCountOfPCConfig()
#define EthIf_GetGlobalModeChangeRetryPeriodCount()                                                 EthIf_GetGlobalModeChangeRetryPeriodCountOfPCConfig()
#define EthIf_GetLinkStateChgMainReload()                                                           EthIf_GetLinkStateChgMainReloadOfPCConfig()
#define EthIf_GetMaxRxFramePerEthCtrl()                                                             EthIf_GetMaxRxFramePerEthCtrlOfPCConfig()
#define EthIf_GetMaxTxBufPerEthCtrl()                                                               EthIf_GetMaxTxBufPerEthCtrlOfPCConfig()
#define EthIf_IsEthSwtIndUsedOfPhysLayerInitElems(Index)                                            (((boolean)(EthIf_GetEthSwtIndStartIdxOfPhysLayerInitElems(Index) != ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthSwtInd */
#define EthIf_IsEthTrcvUsedOfPhysLayerInitElems(Index)                                              (((boolean)(EthIf_GetEthTrcvIdxOfPhysLayerInitElems(Index) != ETHIF_NO_ETHTRCVIDXOFPHYSLAYERINITELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthTrcv */
#define EthIf_IsEthTrcvUsedOfPhysLayerModeElems(Index)                                              (((boolean)(EthIf_GetEthTrcvIdxOfPhysLayerModeElems(Index) != ETHIF_NO_ETHTRCVIDXOFPHYSLAYERMODEELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthTrcv */
#define EthIf_IsPortGroupUsedOfPhysLayerModeElems(Index)                                            (((boolean)(EthIf_GetPortGroupIdxOfPhysLayerModeElems(Index) != ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_PortGroup */
#define EthIf_IsEthIfCtrlOfPortGroupIndUsedOfPortGroup(Index)                                       (((boolean)(EthIf_GetEthIfCtrlOfPortGroupIndStartIdxOfPortGroup(Index) != ETHIF_NO_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfCtrlOfPortGroupInd */
#define EthIf_GetPortStartupActiveTimeFreq()                                                        EthIf_GetPortStartupActiveTimeFreqOfPCConfig()
#define EthIf_IsEthIfCtrlToRxPduMapUsedOfRxPdu(Index)                                               (((boolean)(EthIf_GetEthIfCtrlToRxPduMapIdxOfRxPdu(Index) != ETHIF_NO_ETHIFCTRLTORXPDUMAPIDXOFRXPDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthIfCtrlToRxPduMap */
#define EthIf_IsFloatingRxPduMapUsedOfRxPdu(Index)                                                  (((boolean)(EthIf_GetFloatingRxPduMapIdxOfRxPdu(Index) != ETHIF_NO_FLOATINGRXPDUMAPIDXOFRXPDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_FloatingRxPduMap */
#define EthIf_IsRxPduMetaDataUsedOfRxPdu(Index)                                                     (((boolean)(EthIf_GetRxPduMetaDataLengthOfRxPdu(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_RxPduMetaData */
#define EthIf_IsEthIfCtrlToRxPduMapUsedOfRxPduFrameType(Index)                                      (((boolean)(EthIf_GetEthIfCtrlToRxPduMapLengthOfRxPduFrameType(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfCtrlToRxPduMap */
#define EthIf_IsFloatingRxPduMapUsedOfRxPduFrameType(Index)                                         (((boolean)(EthIf_GetFloatingRxPduMapLengthOfRxPduFrameType(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_FloatingRxPduMap */
#define EthIf_IsEthRxQueueUsedOfRxQueueList(Index)                                                  (((boolean)(EthIf_GetEthRxQueueLengthOfRxQueueList(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthRxQueue */
#define EthIf_GetSetControllerModeTimeout()                                                         EthIf_GetSetControllerModeTimeoutOfPCConfig()
#define EthIf_GetSignalQualityChgMainReload()                                                       EthIf_GetSignalQualityChgMainReloadOfPCConfig()
#define EthIf_GetSizeOfDedicatedRxPduNextFreePos()                                                  EthIf_GetSizeOfDedicatedRxPduNextFreePosOfPCConfig()
#define EthIf_GetSizeOfEcucPartition()                                                              EthIf_GetSizeOfEcucPartitionOfPCConfig()
#define EthIf_GetSizeOfEthCtrl()                                                                    EthIf_GetSizeOfEthCtrlOfPCConfig()
#define EthIf_GetSizeOfEthCtrlInitCnt()                                                             EthIf_GetSizeOfEthCtrlInitCntOfPCConfig()
#define EthIf_GetSizeOfEthCtrlModeCnt()                                                             EthIf_GetSizeOfEthCtrlModeCntOfPCConfig()
#define EthIf_GetSizeOfEthCtrlState()                                                               EthIf_GetSizeOfEthCtrlStateOfPCConfig()
#define EthIf_GetSizeOfEthDrvApi()                                                                  EthIf_GetSizeOfEthDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthIfClkUnit()                                                               EthIf_GetSizeOfEthIfClkUnitOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrl()                                                                  EthIf_GetSizeOfEthIfCtrlOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlInitState()                                                         EthIf_GetSizeOfEthIfCtrlInitStateOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlLinkCount()                                                         EthIf_GetSizeOfEthIfCtrlLinkCountOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlLinkState()                                                         EthIf_GetSizeOfEthIfCtrlLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlMode()                                                              EthIf_GetSizeOfEthIfCtrlModeOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlOfEthTrcvInd()                                                      EthIf_GetSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlOfPortGroupInd()                                                    EthIf_GetSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlRxStats()                                                           EthIf_GetSizeOfEthIfCtrlRxStatsOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlToEtherTypeMap()                                                    EthIf_GetSizeOfEthIfCtrlToEtherTypeMapOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlToRxPduMap()                                                        EthIf_GetSizeOfEthIfCtrlToRxPduMapOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlTxStats()                                                           EthIf_GetSizeOfEthIfCtrlTxStatsOfPCConfig()
#define EthIf_GetSizeOfEthIfMeasurementData()                                                       EthIf_GetSizeOfEthIfMeasurementDataOfPCConfig()
#define EthIf_GetSizeOfEthIfPhysCtrlCfg()                                                           EthIf_GetSizeOfEthIfPhysCtrlCfgOfPCConfig()
#define EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerCounter()                               EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()
#define EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerState()                                 EthIf_GetSizeOfEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()
#define EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayCounter()                                   EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()
#define EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayState()                                     EthIf_GetSizeOfEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()
#define EthIf_GetSizeOfEthIfSwitchOffPortTimerDelayState()                                          EthIf_GetSizeOfEthIfSwitchOffPortTimerDelayStateOfPCConfig()
#define EthIf_GetSizeOfEthIfSwtPortGroupState()                                                     EthIf_GetSizeOfEthIfSwtPortGroupStateOfPCConfig()
#define EthIf_GetSizeOfEthRxQueue()                                                                 EthIf_GetSizeOfEthRxQueueOfPCConfig()
#define EthIf_GetSizeOfEthSwt()                                                                     EthIf_GetSizeOfEthSwtOfPCConfig()
#define EthIf_GetSizeOfEthSwtDrv()                                                                  EthIf_GetSizeOfEthSwtDrvOfPCConfig()
#define EthIf_GetSizeOfEthSwtDrvApi()                                                               EthIf_GetSizeOfEthSwtDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthSwtInd()                                                                  EthIf_GetSizeOfEthSwtIndOfPCConfig()
#define EthIf_GetSizeOfEthSwtInitCnt()                                                              EthIf_GetSizeOfEthSwtInitCntOfPCConfig()
#define EthIf_GetSizeOfEthSwtPort()                                                                 EthIf_GetSizeOfEthSwtPortOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortInEthSwtContext()                                                  EthIf_GetSizeOfEthSwtPortInEthSwtContextOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortInd()                                                              EthIf_GetSizeOfEthSwtPortIndOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortLinkState()                                                        EthIf_GetSizeOfEthSwtPortLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortModeCnt()                                                          EthIf_GetSizeOfEthSwtPortModeCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcv()                                                                    EthIf_GetSizeOfEthTrcvOfPCConfig()
#define EthIf_GetSizeOfEthTrcvDrvApi()                                                              EthIf_GetSizeOfEthTrcvDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthTrcvInitCnt()                                                             EthIf_GetSizeOfEthTrcvInitCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcvLinkState()                                                           EthIf_GetSizeOfEthTrcvLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthTrcvMode()                                                                EthIf_GetSizeOfEthTrcvModeOfPCConfig()
#define EthIf_GetSizeOfEthTrcvModeChangeRetryCounter()                                              EthIf_GetSizeOfEthTrcvModeChangeRetryCounterOfPCConfig()
#define EthIf_GetSizeOfEthTrcvModeChangeRetryPeriodCounter()                                        EthIf_GetSizeOfEthTrcvModeChangeRetryPeriodCounterOfPCConfig()
#define EthIf_GetSizeOfEthTrcvModeCnt()                                                             EthIf_GetSizeOfEthTrcvModeCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcvState()                                                               EthIf_GetSizeOfEthTrcvStateOfPCConfig()
#define EthIf_GetSizeOfEthTxQueue()                                                                 EthIf_GetSizeOfEthTxQueueOfPCConfig()
#define EthIf_GetSizeOfExplicitBufReleaseFilter()                                                   EthIf_GetSizeOfExplicitBufReleaseFilterOfPCConfig()
#define EthIf_GetSizeOfFloatingRxPduMap()                                                           EthIf_GetSizeOfFloatingRxPduMapOfPCConfig()
#define EthIf_GetSizeOfFloatingRxPduNextFreePos()                                                   EthIf_GetSizeOfFloatingRxPduNextFreePosOfPCConfig()
#define EthIf_GetSizeOfGatewaySrcMacBlackList()                                                     EthIf_GetSizeOfGatewaySrcMacBlackListOfPCConfig()
#define EthIf_GetSizeOfLegacyWakeupMap()                                                            EthIf_GetSizeOfLegacyWakeupMapOfPCConfig()
#define EthIf_GetSizeOfLinkStateChgIndications()                                                    EthIf_GetSizeOfLinkStateChgIndicationsOfPCConfig()
#define EthIf_GetSizeOfMainPartitionRxEthCtrl()                                                     EthIf_GetSizeOfMainPartitionRxEthCtrlOfPCConfig()
#define EthIf_GetSizeOfMainPartitionTxEthCtrl()                                                     EthIf_GetSizeOfMainPartitionTxEthCtrlOfPCConfig()
#define EthIf_GetSizeOfMirrorDest()                                                                 EthIf_GetSizeOfMirrorDestOfPCConfig()
#define EthIf_GetSizeOfMirrorTxInfo()                                                               EthIf_GetSizeOfMirrorTxInfoOfPCConfig()
#define EthIf_GetSizeOfPhysLayerInitElems()                                                         EthIf_GetSizeOfPhysLayerInitElemsOfPCConfig()
#define EthIf_GetSizeOfPhysLayerModeElems()                                                         EthIf_GetSizeOfPhysLayerModeElemsOfPCConfig()
#define EthIf_GetSizeOfPortGroup()                                                                  EthIf_GetSizeOfPortGroupOfPCConfig()
#define EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCount()                                     EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()
#define EthIf_GetSizeOfPortGroupInd()                                                               EthIf_GetSizeOfPortGroupIndOfPCConfig()
#define EthIf_GetSizeOfPortGroupLinkState()                                                         EthIf_GetSizeOfPortGroupLinkStateOfPCConfig()
#define EthIf_GetSizeOfPortGroupMode()                                                              EthIf_GetSizeOfPortGroupModeOfPCConfig()
#define EthIf_GetSizeOfPortGroupNoRoleLinkCount()                                                   EthIf_GetSizeOfPortGroupNoRoleLinkCountOfPCConfig()
#define EthIf_GetSizeOfPortGroupStartupActiveTimerActive()                                          EthIf_GetSizeOfPortGroupStartupActiveTimerActiveOfPCConfig()
#define EthIf_GetSizeOfPortMode()                                                                   EthIf_GetSizeOfPortModeOfPCConfig()
#define EthIf_GetSizeOfPortSignalQualityResult()                                                    EthIf_GetSizeOfPortSignalQualityResultOfPCConfig()
#define EthIf_GetSizeOfPortStartupActiveTimerActive()                                               EthIf_GetSizeOfPortStartupActiveTimerActiveOfPCConfig()
#define EthIf_GetSizeOfRequestedEthIfCtrlMode()                                                     EthIf_GetSizeOfRequestedEthIfCtrlModeOfPCConfig()
#define EthIf_GetSizeOfRequestedEthTrcvMode()                                                       EthIf_GetSizeOfRequestedEthTrcvModeOfPCConfig()
#define EthIf_GetSizeOfRequestedEthTrcvStateOfEthIfCtrl()                                           EthIf_GetSizeOfRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()
#define EthIf_GetSizeOfRequestedPortGroupMode()                                                     EthIf_GetSizeOfRequestedPortGroupModeOfPCConfig()
#define EthIf_GetSizeOfRequestedPortGroupStateOfEthIfCtrl()                                         EthIf_GetSizeOfRequestedPortGroupStateOfEthIfCtrlOfPCConfig()
#define EthIf_GetSizeOfRequestedPortMode()                                                          EthIf_GetSizeOfRequestedPortModeOfPCConfig()
#define EthIf_GetSizeOfRxIndications()                                                              EthIf_GetSizeOfRxIndicationsOfPCConfig()
#define EthIf_GetSizeOfRxPdu()                                                                      EthIf_GetSizeOfRxPduOfPCConfig()
#define EthIf_GetSizeOfRxPduContext()                                                               EthIf_GetSizeOfRxPduContextOfPCConfig()
#define EthIf_GetSizeOfRxPduFrameType()                                                             EthIf_GetSizeOfRxPduFrameTypeOfPCConfig()
#define EthIf_GetSizeOfRxPduFreeList()                                                              EthIf_GetSizeOfRxPduFreeListOfPCConfig()
#define EthIf_GetSizeOfRxPduMetaData()                                                              EthIf_GetSizeOfRxPduMetaDataOfPCConfig()
#define EthIf_GetSizeOfRxQueueList()                                                                EthIf_GetSizeOfRxQueueListOfPCConfig()
#define EthIf_GetSizeOfSignalQualityResult()                                                        EthIf_GetSizeOfSignalQualityResultOfPCConfig()
#define EthIf_GetSizeOfSrcMacAddrBuffer()                                                           EthIf_GetSizeOfSrcMacAddrBufferOfPCConfig()
#define EthIf_GetSizeOfSwtPortGroupModeChangeRetryCounter()                                         EthIf_GetSizeOfSwtPortGroupModeChangeRetryCounterOfPCConfig()
#define EthIf_GetSizeOfSwtPortGroupModeChangeRetryPeriodCounter()                                   EthIf_GetSizeOfSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()
#define EthIf_GetSizeOfTxConfirmations()                                                            EthIf_GetSizeOfTxConfirmationsOfPCConfig()
#define EthIf_GetSizeOfTxContext()                                                                  EthIf_GetSizeOfTxContextOfPCConfig()
#define EthIf_GetSizeOfTxPdu()                                                                      EthIf_GetSizeOfTxPduOfPCConfig()
#define EthIf_GetSizeOfTxPduContext()                                                               EthIf_GetSizeOfTxPduContextOfPCConfig()
#define EthIf_GetSizeOfTxQueueList()                                                                EthIf_GetSizeOfTxQueueListOfPCConfig()
#define EthIf_GetSizeOfWakeupMap()                                                                  EthIf_GetSizeOfWakeupMapOfPCConfig()
#define EthIf_GetSizeOfWakeupSrcDevice()                                                            EthIf_GetSizeOfWakeupSrcDeviceOfPCConfig()
#define EthIf_IsEthIfCtrlUsedOfTxPdu(Index)                                                         (((boolean)(EthIf_GetEthIfCtrlIdxOfTxPdu(Index) != ETHIF_NO_ETHIFCTRLIDXOFTXPDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthIfCtrl */
#define EthIf_IsEthTxQueueUsedOfTxQueueList(Index)                                                  (((boolean)(EthIf_GetEthTxQueueLengthOfTxQueueList(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthTxQueue */
#define EthIf_IsWakeupSrcDeviceUsedOfWakeupMap(Index)                                               (((boolean)(EthIf_GetWakeupSrcDeviceLengthOfWakeupMap(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_WakeupSrcDevice */
#define EthIf_IsEthSwtUsedOfWakeupSrcDevice(Index)                                                  (((boolean)(EthIf_GetEthSwtIdxOfWakeupSrcDevice(Index) != ETHIF_NO_ETHSWTIDXOFWAKEUPSRCDEVICE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthSwt */
#define EthIf_IsEthTrcvUsedOfWakeupSrcDevice(Index)                                                 (((boolean)(EthIf_GetEthTrcvIdxOfWakeupSrcDevice(Index) != ETHIF_NO_ETHTRCVIDXOFWAKEUPSRCDEVICE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthTrcv */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSetDataMacros  EthIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EthIf_SetDedicatedRxPduNextFreePos(Index, Value)                                            EthIf_GetDedicatedRxPduNextFreePosOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlInitCnt(Index, Value)                                                       EthIf_GetEthCtrlInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlModeCnt(Index, Value)                                                       EthIf_GetEthCtrlModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlState(Index, Value)                                                         EthIf_GetEthCtrlStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfControllerModeChangeReqCnt(Value)                                             (*(EthIf_GetEthIfControllerModeChangeReqCntOfPCConfig())) = (Value)
#define EthIf_SetEthIfCtrlInitState(Index, Value)                                                   EthIf_GetEthIfCtrlInitStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlLinkCount(Index, Value)                                                   EthIf_GetEthIfCtrlLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlLinkState(Index, Value)                                                   EthIf_GetEthIfCtrlLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlMode(Index, Value)                                                        EthIf_GetEthIfCtrlModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxBytesOfEthIfCtrlRxStats = (Value)
#define EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxPktsOfEthIfCtrlRxStats = (Value)
#define EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxBytesOfEthIfCtrlTxStats = (Value)
#define EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxPktsOfEthIfCtrlTxStats = (Value)
#define EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].DropCtrlIdxOfEthIfMeasurementData = (Value)
#define EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].UnknownEtherTypeOfEthIfMeasurementData = (Value)
#define EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].VlanDoubleTaggedOfEthIfMeasurementData = (Value)
#define EthIf_SetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index, Value)                         EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfQualifiedUnexpectedLinkDownTimerState(Index, Value)                           EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfSwitchOffPortGroupTimerDelayCounter(Index, Value)                             EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfSwitchOffPortGroupTimerDelayState(Index, Value)                               EthIf_GetEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfSwitchOffPortTimeDelayReqCnt(Value)                                           (*(EthIf_GetEthIfSwitchOffPortTimeDelayReqCntOfPCConfig())) = (Value)
#define EthIf_SetEthIfSwitchOffPortTimerDelayState(Index, Value)                                    EthIf_GetEthIfSwitchOffPortTimerDelayStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfSwtPortGroupState(Index, Value)                                               EthIf_GetEthIfSwtPortGroupStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtInitCnt(Index, Value)                                                        EthIf_GetEthSwtInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtPortLinkState(Index, Value)                                                  EthIf_GetEthSwtPortLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtPortModeCnt(Index, Value)                                                    EthIf_GetEthSwtPortModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvInitCnt(Index, Value)                                                       EthIf_GetEthTrcvInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvLinkState(Index, Value)                                                     EthIf_GetEthTrcvLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvMode(Index, Value)                                                          EthIf_GetEthTrcvModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvModeChangeRetryCounter(Index, Value)                                        EthIf_GetEthTrcvModeChangeRetryCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvModeChangeRetryPeriodCounter(Index, Value)                                  EthIf_GetEthTrcvModeChangeRetryPeriodCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvModeCnt(Index, Value)                                                       EthIf_GetEthTrcvModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvState(Index, Value)                                                         EthIf_GetEthTrcvStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetFloatingRxPduNextFreePos(Index, Value)                                             EthIf_GetFloatingRxPduNextFreePosOfPCConfig()[(Index)] = (Value)
#define EthIf_SetGlobalStartupActiveTimerActive(Value)                                              (*(EthIf_GetGlobalStartupActiveTimerActiveOfPCConfig())) = (Value)
#define EthIf_SetInitLocked(Value)                                                                  (*(EthIf_GetInitLockedOfPCConfig())) = (Value)
#define EthIf_SetMainFuncStateDecoupleFreqCnt(Value)                                                (*(EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig())) = (Value)
#define EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestEthTxBufferIdxOfMirrorTxInfo = (Value)
#define EthIf_SetDestPayloadPtrOfMirrorTxInfo(Index, Value)                                         EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestPayloadPtrOfMirrorTxInfo = (Value)
#define EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].EthIfCtrlIdxOfMirrorTxInfo = (Value)
#define EthIf_SetInfoValidOfMirrorTxInfo(Index, Value)                                              EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].InfoValidOfMirrorTxInfo = (Value)
#define EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcEthTxBufferIdxOfMirrorTxInfo = (Value)
#define EthIf_SetSrcPayloadPtrOfMirrorTxInfo(Index, Value)                                          EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcPayloadPtrOfMirrorTxInfo = (Value)
#define EthIf_SetUsedOfMirrorTxInfo(Index, Value)                                                   EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].UsedOfMirrorTxInfo = (Value)
#define EthIf_SetModeChangeLocked(Value)                                                            (*(EthIf_GetModeChangeLockedOfPCConfig())) = (Value)
#define EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupLinkState(Index, Value)                                                   EthIf_GetPortGroupLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupMode(Index, Value)                                                        EthIf_GetPortGroupModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupStartupActiveTimerActive(Index, Value)                                    EthIf_GetPortGroupStartupActiveTimerActiveOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortMode(Index, Value)                                                             EthIf_GetPortModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortSignalQualityResult(Index, Value)                                              EthIf_GetPortSignalQualityResultOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortStartupActiveTimeCounter(Value)                                                (*(EthIf_GetPortStartupActiveTimeCounterOfPCConfig())) = (Value)
#define EthIf_SetPortStartupActiveTimerActive(Index, Value)                                         EthIf_GetPortStartupActiveTimerActiveOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedEthIfCtrlMode(Index, Value)                                               EthIf_GetRequestedEthIfCtrlModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedEthTrcvMode(Index, Value)                                                 EthIf_GetRequestedEthTrcvModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedEthTrcvStateOfEthIfCtrl(Index, Value)                                     EthIf_GetRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedPortGroupMode(Index, Value)                                               EthIf_GetRequestedPortGroupModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedPortGroupStateOfEthIfCtrl(Index, Value)                                   EthIf_GetRequestedPortGroupStateOfEthIfCtrlOfPCConfig()[(Index)] = (Value)
#define EthIf_SetRequestedPortMode(Index, Value)                                                    EthIf_GetRequestedPortModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlIdxOfRxPduContext(Index, Value)                                           EthIf_GetRxPduContextOfPCConfig()[(Index)].EthIfCtrlIdxOfRxPduContext = (Value)
#define EthIf_SetRxHandleIdOfRxPduContext(Index, Value)                                             EthIf_GetRxPduContextOfPCConfig()[(Index)].RxHandleIdOfRxPduContext = (Value)
#define EthIf_SetStateOfRxPduContext(Index, Value)                                                  EthIf_GetRxPduContextOfPCConfig()[(Index)].StateOfRxPduContext = (Value)
#define EthIf_SetTimeTupleOfRxPduContext(Index, Value)                                              EthIf_GetRxPduContextOfPCConfig()[(Index)].TimeTupleOfRxPduContext = (Value)
#define EthIf_SetPduIdOfRxPduFreeList(Index, Value)                                                 EthIf_GetRxPduFreeListOfPCConfig()[(Index)].PduIdOfRxPduFreeList = (Value)
#define EthIf_SetRxPduMetaData(Index, Value)                                                        EthIf_GetRxPduMetaDataOfPCConfig()[(Index)] = (Value)
#define EthIf_SetSignalQualityDecoupleFreqCnt(Value)                                                (*(EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig())) = (Value)
#define EthIf_SetSignalQualityResult(Index, Value)                                                  EthIf_GetSignalQualityResultOfPCConfig()[(Index)] = (Value)
#define EthIf_SetSrcMacOfSrcMacAddrBuffer(Index, Value)                                             EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].SrcMacOfSrcMacAddrBuffer = (Value)
#define EthIf_SetValidOfSrcMacAddrBuffer(Index, Value)                                              EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].ValidOfSrcMacAddrBuffer = (Value)
#define EthIf_SetSwtPortGroupModeChangeReqCnt(Value)                                                (*(EthIf_GetSwtPortGroupModeChangeReqCntOfPCConfig())) = (Value)
#define EthIf_SetSwtPortGroupModeChangeRetryCounter(Index, Value)                                   EthIf_GetSwtPortGroupModeChangeRetryCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetSwtPortGroupModeChangeRetryPeriodCounter(Index, Value)                             EthIf_GetSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlIdxOfTxContext = (Value)
#define EthIf_SetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index, Value)                                EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlToEtherTypeMapIdxOfTxContext = (Value)
#define EthIf_SetFrameHdrOfTxContext(Index, Value)                                                  EthIf_GetTxContextOfPCConfig()[(Index)].FrameHdrOfTxContext = (Value)
#define EthIf_SetLinkedPduIdOfTxContext(Index, Value)                                               EthIf_GetTxContextOfPCConfig()[(Index)].LinkedPduIdOfTxContext = (Value)
#define EthIf_SetPayloadLenOfTxContext(Index, Value)                                                EthIf_GetTxContextOfPCConfig()[(Index)].PayloadLenOfTxContext = (Value)
#define EthIf_SetPayloadPtrOfTxContext(Index, Value)                                                EthIf_GetTxContextOfPCConfig()[(Index)].PayloadPtrOfTxContext = (Value)
#define EthIf_SetTxPendingOfTxContext(Index, Value)                                                 EthIf_GetTxContextOfPCConfig()[(Index)].TxPendingOfTxContext = (Value)
#define EthIf_SetValidOfTxContext(Index, Value)                                                     EthIf_GetTxContextOfPCConfig()[(Index)].ValidOfTxContext = (Value)
#define EthIf_SetValidPduIdOfTxContext(Index, Value)                                                EthIf_GetTxContextOfPCConfig()[(Index)].ValidPduIdOfTxContext = (Value)
#define EthIf_SetFrameHdrBufOfTxPduContext(Index, Value)                                            EthIf_GetTxPduContextOfPCConfig()[(Index)].FrameHdrBufOfTxPduContext = (Value)
#define EthIf_SetFrameHdrOfTxPduContext(Index, Value)                                               EthIf_GetTxPduContextOfPCConfig()[(Index)].FrameHdrOfTxPduContext = (Value)
#define EthIf_SetListElementOfTxPduContext(Index, Value)                                            EthIf_GetTxPduContextOfPCConfig()[(Index)].ListElementOfTxPduContext = (Value)
#define EthIf_SetStateOfTxPduContext(Index, Value)                                                  EthIf_GetTxPduContextOfPCConfig()[(Index)].StateOfTxPduContext = (Value)
#define EthIf_SetTimeTuplePtrOfTxPduContext(Index, Value)                                           EthIf_GetTxPduContextOfPCConfig()[(Index)].TimeTuplePtrOfTxPduContext = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetAddressOfDataMacros  EthIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define EthIf_GetAddrDedicatedRxPduNextFreePos(Index)                                               (&EthIf_GetDedicatedRxPduNextFreePos(Index))
#define EthIf_GetAddrEthCtrlInitCnt(Index)                                                          (&EthIf_GetEthCtrlInitCnt(Index))
#define EthIf_GetAddrEthCtrlModeCnt(Index)                                                          (&EthIf_GetEthCtrlModeCnt(Index))
#define EthIf_GetAddrEthCtrlState(Index)                                                            (&EthIf_GetEthCtrlState(Index))
#define EthIf_GetAddrEthIfControllerModeChangeReqCnt()                                              (&EthIf_GetEthIfControllerModeChangeReqCnt())
#define EthIf_GetAddrEthIfCtrlInitState(Index)                                                      (&EthIf_GetEthIfCtrlInitState(Index))
#define EthIf_GetAddrEthIfCtrlLinkCount(Index)                                                      (&EthIf_GetEthIfCtrlLinkCount(Index))
#define EthIf_GetAddrEthIfCtrlLinkState(Index)                                                      (&EthIf_GetEthIfCtrlLinkState(Index))
#define EthIf_GetAddrEthIfCtrlMode(Index)                                                           (&EthIf_GetEthIfCtrlMode(Index))
#define EthIf_GetAddrNumRxBytesOfEthIfCtrlRxStats(Index)                                            (&EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index))
#define EthIf_GetAddrNumRxPktsOfEthIfCtrlRxStats(Index)                                             (&EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index))
#define EthIf_GetAddrNumTxBytesOfEthIfCtrlTxStats(Index)                                            (&EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index))
#define EthIf_GetAddrNumTxPktsOfEthIfCtrlTxStats(Index)                                             (&EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index))
#define EthIf_GetAddrDropCtrlIdxOfEthIfMeasurementData(Index)                                       (&EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index))
#define EthIf_GetAddrUnknownEtherTypeOfEthIfMeasurementData(Index)                                  (&EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index))
#define EthIf_GetAddrVlanDoubleTaggedOfEthIfMeasurementData(Index)                                  (&EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index))
#define EthIf_GetAddrEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)                            (&EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index))
#define EthIf_GetAddrEthIfQualifiedUnexpectedLinkDownTimerState(Index)                              (&EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerState(Index))
#define EthIf_GetAddrEthIfSwitchOffPortGroupTimerDelayCounter(Index)                                (&EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index))
#define EthIf_GetAddrEthIfSwitchOffPortGroupTimerDelayState(Index)                                  (&EthIf_GetEthIfSwitchOffPortGroupTimerDelayState(Index))
#define EthIf_GetAddrEthIfSwitchOffPortTimeDelayReqCnt()                                            (&EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt())
#define EthIf_GetAddrEthIfSwitchOffPortTimerDelayState(Index)                                       (&EthIf_GetEthIfSwitchOffPortTimerDelayState(Index))
#define EthIf_GetAddrEthIfSwtPortGroupState(Index)                                                  (&EthIf_GetEthIfSwtPortGroupState(Index))
#define EthIf_GetAddrEthSwtInitCnt(Index)                                                           (&EthIf_GetEthSwtInitCnt(Index))
#define EthIf_GetAddrEthSwtPortLinkState(Index)                                                     (&EthIf_GetEthSwtPortLinkState(Index))
#define EthIf_GetAddrEthSwtPortModeCnt(Index)                                                       (&EthIf_GetEthSwtPortModeCnt(Index))
#define EthIf_GetAddrEthTrcvInitCnt(Index)                                                          (&EthIf_GetEthTrcvInitCnt(Index))
#define EthIf_GetAddrEthTrcvLinkState(Index)                                                        (&EthIf_GetEthTrcvLinkState(Index))
#define EthIf_GetAddrEthTrcvMode(Index)                                                             (&EthIf_GetEthTrcvMode(Index))
#define EthIf_GetAddrEthTrcvModeChangeRetryCounter(Index)                                           (&EthIf_GetEthTrcvModeChangeRetryCounter(Index))
#define EthIf_GetAddrEthTrcvModeChangeRetryPeriodCounter(Index)                                     (&EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index))
#define EthIf_GetAddrEthTrcvModeCnt(Index)                                                          (&EthIf_GetEthTrcvModeCnt(Index))
#define EthIf_GetAddrEthTrcvState(Index)                                                            (&EthIf_GetEthTrcvState(Index))
#define EthIf_GetAddrFloatingRxPduNextFreePos(Index)                                                (&EthIf_GetFloatingRxPduNextFreePos(Index))
#define EthIf_GetAddrGlobalStartupActiveTimerActive()                                               (&((*(EthIf_GetGlobalStartupActiveTimerActiveOfPCConfig()))))
#define EthIf_GetAddrInitLocked()                                                                   (&((*(EthIf_GetInitLockedOfPCConfig()))))
#define EthIf_GetAddrMainFuncStateDecoupleFreqCnt()                                                 (&EthIf_GetMainFuncStateDecoupleFreqCnt())
#define EthIf_GetAddrDestEthTxBufferIdxOfMirrorTxInfo(Index)                                        (&EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrDestPayloadPtrOfMirrorTxInfo(Index)                                            (&EthIf_GetDestPayloadPtrOfMirrorTxInfo(Index))
#define EthIf_GetAddrEthIfCtrlIdxOfMirrorTxInfo(Index)                                              (&EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrInfoValidOfMirrorTxInfo(Index)                                                 (&(EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].InfoValidOfMirrorTxInfo))
#define EthIf_GetAddrSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                         (&EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrSrcPayloadPtrOfMirrorTxInfo(Index)                                             (&EthIf_GetSrcPayloadPtrOfMirrorTxInfo(Index))
#define EthIf_GetAddrUsedOfMirrorTxInfo(Index)                                                      (&(EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].UsedOfMirrorTxInfo))
#define EthIf_GetAddrModeChangeLocked()                                                             (&((*(EthIf_GetModeChangeLockedOfPCConfig()))))
#define EthIf_GetAddrPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                  (&EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index))
#define EthIf_GetAddrPortGroupLinkState(Index)                                                      (&EthIf_GetPortGroupLinkState(Index))
#define EthIf_GetAddrPortGroupMode(Index)                                                           (&EthIf_GetPortGroupMode(Index))
#define EthIf_GetAddrPortGroupNoRoleLinkCount(Index)                                                (&EthIf_GetPortGroupNoRoleLinkCount(Index))
#define EthIf_GetAddrPortGroupStartupActiveTimerActive(Index)                                       (&(EthIf_GetPortGroupStartupActiveTimerActiveOfPCConfig()[(Index)]))
#define EthIf_GetAddrPortMode(Index)                                                                (&EthIf_GetPortMode(Index))
#define EthIf_GetAddrPortSignalQualityResult(Index)                                                 (&EthIf_GetPortSignalQualityResult(Index))
#define EthIf_GetAddrPortStartupActiveTimeCounter()                                                 (&EthIf_GetPortStartupActiveTimeCounter())
#define EthIf_GetAddrPortStartupActiveTimerActive(Index)                                            (&(EthIf_GetPortStartupActiveTimerActiveOfPCConfig()[(Index)]))
#define EthIf_GetAddrRequestedEthIfCtrlMode(Index)                                                  (&EthIf_GetRequestedEthIfCtrlMode(Index))
#define EthIf_GetAddrRequestedEthTrcvMode(Index)                                                    (&EthIf_GetRequestedEthTrcvMode(Index))
#define EthIf_GetAddrRequestedEthTrcvStateOfEthIfCtrl(Index)                                        (&EthIf_GetRequestedEthTrcvStateOfEthIfCtrl(Index))
#define EthIf_GetAddrRequestedPortGroupMode(Index)                                                  (&EthIf_GetRequestedPortGroupMode(Index))
#define EthIf_GetAddrRequestedPortGroupStateOfEthIfCtrl(Index)                                      (&EthIf_GetRequestedPortGroupStateOfEthIfCtrl(Index))
#define EthIf_GetAddrRequestedPortMode(Index)                                                       (&EthIf_GetRequestedPortMode(Index))
#define EthIf_GetAddrEthIfCtrlIdxOfRxPduContext(Index)                                              (&EthIf_GetEthIfCtrlIdxOfRxPduContext(Index))
#define EthIf_GetAddrRxHandleIdOfRxPduContext(Index)                                                (&EthIf_GetRxHandleIdOfRxPduContext(Index))
#define EthIf_GetAddrStateOfRxPduContext(Index)                                                     (&EthIf_GetStateOfRxPduContext(Index))
#define EthIf_GetAddrTimeTupleOfRxPduContext(Index)                                                 (&EthIf_GetTimeTupleOfRxPduContext(Index))
#define EthIf_GetAddrPduIdOfRxPduFreeList(Index)                                                    (&EthIf_GetPduIdOfRxPduFreeList(Index))
#define EthIf_GetAddrRxPduMetaData(Index)                                                           (&EthIf_GetRxPduMetaData(Index))
#define EthIf_GetAddrSignalQualityDecoupleFreqCnt()                                                 (&EthIf_GetSignalQualityDecoupleFreqCnt())
#define EthIf_GetAddrSignalQualityResult(Index)                                                     (&EthIf_GetSignalQualityResult(Index))
#define EthIf_GetAddrSrcMacOfSrcMacAddrBuffer(Index)                                                (&EthIf_GetSrcMacOfSrcMacAddrBuffer(Index))
#define EthIf_GetAddrValidOfSrcMacAddrBuffer(Index)                                                 (&(EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].ValidOfSrcMacAddrBuffer))
#define EthIf_GetAddrSwtPortGroupModeChangeReqCnt()                                                 (&EthIf_GetSwtPortGroupModeChangeReqCnt())
#define EthIf_GetAddrSwtPortGroupModeChangeRetryCounter(Index)                                      (&EthIf_GetSwtPortGroupModeChangeRetryCounter(Index))
#define EthIf_GetAddrSwtPortGroupModeChangeRetryPeriodCounter(Index)                                (&EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index))
#define EthIf_GetAddrEthIfCtrlIdxOfTxContext(Index)                                                 (&EthIf_GetEthIfCtrlIdxOfTxContext(Index))
#define EthIf_GetAddrEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)                                   (&EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index))
#define EthIf_GetAddrFrameHdrOfTxContext(Index)                                                     (&EthIf_GetFrameHdrOfTxContext(Index))
#define EthIf_GetAddrLinkedPduIdOfTxContext(Index)                                                  (&EthIf_GetLinkedPduIdOfTxContext(Index))
#define EthIf_GetAddrPayloadLenOfTxContext(Index)                                                   (&EthIf_GetPayloadLenOfTxContext(Index))
#define EthIf_GetAddrPayloadPtrOfTxContext(Index)                                                   (&EthIf_GetPayloadPtrOfTxContext(Index))
#define EthIf_GetAddrTxPendingOfTxContext(Index)                                                    (&(EthIf_GetTxContextOfPCConfig()[(Index)].TxPendingOfTxContext))
#define EthIf_GetAddrValidOfTxContext(Index)                                                        (&(EthIf_GetTxContextOfPCConfig()[(Index)].ValidOfTxContext))
#define EthIf_GetAddrValidPduIdOfTxContext(Index)                                                   (&(EthIf_GetTxContextOfPCConfig()[(Index)].ValidPduIdOfTxContext))
#define EthIf_GetAddrFrameHdrBufOfTxPduContext(Index)                                               (&EthIf_GetFrameHdrBufOfTxPduContext(Index))
#define EthIf_GetAddrFrameHdrOfTxPduContext(Index)                                                  (&EthIf_GetFrameHdrOfTxPduContext(Index))
#define EthIf_GetAddrListElementOfTxPduContext(Index)                                               (&EthIf_GetListElementOfTxPduContext(Index))
#define EthIf_GetAddrStateOfTxPduContext(Index)                                                     (&EthIf_GetStateOfTxPduContext(Index))
#define EthIf_GetAddrTimeTuplePtrOfTxPduContext(Index)                                              (&EthIf_GetTimeTuplePtrOfTxPduContext(Index))
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCHasMacros  EthIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EthIf_HasDedicatedRxPduNextFreePos()                                                        (EthIf_GetDedicatedRxPduNextFreePosOfPCConfig() != NULL_PTR)
#define EthIf_HasEcucPartition()                                                                    (EthIf_GetEcucPartitionOfPCConfig() != NULL_PTR)
#define EthIf_HasQualityLevelOfEcucPartition()                                                      (TRUE != FALSE)
#define EthIf_HasEthCtrl()                                                                          (EthIf_GetEthCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasBufIdxOffsetEnabledOfEthCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasEthArReleaseRxBufferSupportedOfEthCtrl()                                           (TRUE != FALSE)
#define EthIf_HasEthDrvApiIdxOfEthCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasImplicitBufferReleaseNeededOfEthCtrl()                                             (TRUE != FALSE)
#define EthIf_HasNumOfTxBuffersOfEthCtrl()                                                          (TRUE != FALSE)
#define EthIf_HasSnvOfEthCtrl()                                                                     (TRUE != FALSE)
#define EthIf_HasTxContextEndIdxOfEthCtrl()                                                         (TRUE != FALSE)
#define EthIf_HasTxContextLengthOfEthCtrl()                                                         (TRUE != FALSE)
#define EthIf_HasTxContextStartIdxOfEthCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasEthCtrlInitCnt()                                                                   (EthIf_GetEthCtrlInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlModeCnt()                                                                   (EthIf_GetEthCtrlModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlState()                                                                     (EthIf_GetEthCtrlStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthDrvApi()                                                                        (EthIf_GetEthDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasCtrlInitOfEthDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasEnableEgressTimeStampOfEthDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasGetBandwidthLimitOfEthDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetCtrlModeOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasGetCurrentTimeOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetEgressTimeStampOfEthDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasGetIngressTimeStampOfEthDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasGetPhysAddrOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasGetRxHeaderPtrOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetRxStatsOfEthDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasGetSpiStatusOfEthDrvApi()                                                          (TRUE != FALSE)
#define EthIf_HasGetTxHeaderPtrOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetTxStatsOfEthDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasImmediateTransmitOfEthDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasProvideExtTxBufferOfEthDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasProvideTxBufferOfEthDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasReceiveOfEthDrvApi()                                                               (TRUE != FALSE)
#define EthIf_HasReceiveQueueOfEthDrvApi()                                                          (TRUE != FALSE)
#define EthIf_HasReleaseRxBufferOfEthDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasSetBandwidthLimitOfEthDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasSetCtrlModeOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasSetPhysAddrOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasTransmitOfEthDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasTxConfirmationOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasTxConfirmationQueueOfEthDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasUpdatePhysAddrFilterOfEthDrvApi()                                                  (TRUE != FALSE)
#define EthIf_HasVGetEgressTimeStampOfEthDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasVReleaseRxBufferOfEthDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasVTransmitOfEthDrvApi()                                                             (TRUE != FALSE)
#define EthIf_HasEthIfClkUnit()                                                                     (EthIf_GetEthIfClkUnitOfPCConfig() != NULL_PTR)
#define EthIf_HasEthClkUnitIdxOfEthIfClkUnit()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitIdxOfEthIfClkUnit()                                                    (TRUE != FALSE)
#define EthIf_HasEthIfControllerModeChangeReqCnt()                                                  (EthIf_GetEthIfControllerModeChangeReqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrl()                                                                        (EthIf_GetEthIfCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasEcucPartitionIdxOfEthIfCtrl()                                                      (TRUE != FALSE)
#define EthIf_HasEcucPartitionUsedOfEthIfCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasEthCtrlIdxOfEthIfCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrl()                                         (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMapLengthOfEthIfCtrl()                                         (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrl()                                       (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfgIdxOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiUsedOfEthIfCtrl()                                                      (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl()                                            (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxOfEthIfCtrl()                                               (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxUsedOfEthIfCtrl()                                           (TRUE != FALSE)
#define EthIf_HasLinkAggrThresholdOfEthIfCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasMacSecTypeOfEthIfCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxIdxOfEthIfCtrl()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxUsedOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxIdxOfEthIfCtrl()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxUsedOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasMtuOfEthIfCtrl()                                                                   (TRUE != FALSE)
#define EthIf_HasPhysLayerInitElemsIdxOfEthIfCtrl()                                                 (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElemsIdxOfEthIfCtrl()                                                 (TRUE != FALSE)
#define EthIf_HasSnvOfEthIfCtrl()                                                                   (TRUE != FALSE)
#define EthIf_HasTypeOfEthIfCtrl()                                                                  (TRUE != FALSE)
#define EthIf_HasVlanIdOfEthIfCtrl()                                                                (TRUE != FALSE)
#define EthIf_HasEthIfCtrlInitState()                                                               (EthIf_GetEthIfCtrlInitStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlLinkCount()                                                               (EthIf_GetEthIfCtrlLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlLinkState()                                                               (EthIf_GetEthIfCtrlLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlMode()                                                                    (EthIf_GetEthIfCtrlModeOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfEthTrcvInd()                                                            (EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfPortGroupInd()                                                          (EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlRxStats()                                                                 (EthIf_GetEthIfCtrlRxStatsOfPCConfig() != NULL_PTR)
#define EthIf_HasNumRxBytesOfEthIfCtrlRxStats()                                                     (TRUE != FALSE)
#define EthIf_HasNumRxPktsOfEthIfCtrlRxStats()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMap()                                                          (EthIf_GetEthIfCtrlToEtherTypeMapOfPCConfig() != NULL_PTR)
#define EthIf_HasEtherTypeOfEthIfCtrlToEtherTypeMap()                                               (TRUE != FALSE)
#define EthIf_HasRxIndicationsEndIdxOfEthIfCtrlToEtherTypeMap()                                     (TRUE != FALSE)
#define EthIf_HasRxIndicationsLengthOfEthIfCtrlToEtherTypeMap()                                     (TRUE != FALSE)
#define EthIf_HasRxIndicationsStartIdxOfEthIfCtrlToEtherTypeMap()                                   (TRUE != FALSE)
#define EthIf_HasRxIndicationsUsedOfEthIfCtrlToEtherTypeMap()                                       (TRUE != FALSE)
#define EthIf_HasTxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMap()                                   (TRUE != FALSE)
#define EthIf_HasTxConfirmationsLengthOfEthIfCtrlToEtherTypeMap()                                   (TRUE != FALSE)
#define EthIf_HasTxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMap()                                 (TRUE != FALSE)
#define EthIf_HasTxConfirmationsUsedOfEthIfCtrlToEtherTypeMap()                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMap()                                                              (EthIf_GetEthIfCtrlToRxPduMapOfPCConfig() != NULL_PTR)
#define EthIf_HasRxPduCountOfEthIfCtrlToRxPduMap()                                                  (TRUE != FALSE)
#define EthIf_HasRxPduEndIdxOfEthIfCtrlToRxPduMap()                                                 (TRUE != FALSE)
#define EthIf_HasRxPduLengthOfEthIfCtrlToRxPduMap()                                                 (TRUE != FALSE)
#define EthIf_HasRxPduStartIdxOfEthIfCtrlToRxPduMap()                                               (TRUE != FALSE)
#define EthIf_HasRxPduUsedOfEthIfCtrlToRxPduMap()                                                   (TRUE != FALSE)
#define EthIf_HasEthIfCtrlTxStats()                                                                 (EthIf_GetEthIfCtrlTxStatsOfPCConfig() != NULL_PTR)
#define EthIf_HasNumTxBytesOfEthIfCtrlTxStats()                                                     (TRUE != FALSE)
#define EthIf_HasNumTxPktsOfEthIfCtrlTxStats()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfMeasurementData()                                                             (EthIf_GetEthIfMeasurementDataOfPCConfig() != NULL_PTR)
#define EthIf_HasDropCtrlIdxOfEthIfMeasurementData()                                                (TRUE != FALSE)
#define EthIf_HasUnknownEtherTypeOfEthIfMeasurementData()                                           (TRUE != FALSE)
#define EthIf_HasVlanDoubleTaggedOfEthIfMeasurementData()                                           (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfg()                                                                 (EthIf_GetEthIfPhysCtrlCfgOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfEthIfPhysCtrlCfg()                                                     (TRUE != FALSE)
#define EthIf_HasEthDrvApiIdxOfEthIfPhysCtrlCfg()                                                   (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg()                                             (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitLengthOfEthIfPhysCtrlCfg()                                             (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg()                                           (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitUsedOfEthIfPhysCtrlCfg()                                               (TRUE != FALSE)
#define EthIf_HasEthIfPhysControllerIdxOfEthIfPhysCtrlCfg()                                         (TRUE != FALSE)
#define EthIf_HasEthPhcSupportAvailableOfEthIfPhysCtrlCfg()                                         (TRUE != FALSE)
#define EthIf_HasEthIfQualifiedUnexpectedLinkDownTimerCounter()                                     (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfQualifiedUnexpectedLinkDownTimerState()                                       (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfSwitchOffPortGroupTimerDelayCounter()                                         (EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfSwitchOffPortGroupTimerDelayState()                                           (EthIf_GetEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfSwitchOffPortTimeDelayCounts()                                                (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortTimeDelayReqCnt()                                                (EthIf_GetEthIfSwitchOffPortTimeDelayReqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfSwitchOffPortTimerDelayState()                                                (EthIf_GetEthIfSwitchOffPortTimerDelayStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfSwtPortGroupState()                                                           (EthIf_GetEthIfSwtPortGroupStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthRxQueue()                                                                       (EthIf_GetEthRxQueueOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfEthRxQueue()                                                           (TRUE != FALSE)
#define EthIf_HasQueueIndexOfEthRxQueue()                                                           (TRUE != FALSE)
#define EthIf_HasEthSwt()                                                                           (EthIf_GetEthSwtOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtDrvApiIdxOfEthSwt()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextEndIdxOfEthSwt()                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextLengthOfEthSwt()                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextStartIdxOfEthSwt()                                        (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextUsedOfEthSwt()                                            (TRUE != FALSE)
#define EthIf_HasSnvOfEthSwt()                                                                      (TRUE != FALSE)
#define EthIf_HasEthSwtDrv()                                                                        (EthIf_GetEthSwtDrvOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtEndIdxOfEthSwtDrv()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtLengthOfEthSwtDrv()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtStartIdxOfEthSwtDrv()                                                        (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApi()                                                                     (EthIf_GetEthSwtDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasCheckWakeupOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasEnableVlanOfEthSwtDrvApi()                                                         (TRUE != FALSE)
#define EthIf_HasGetArlTableOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetBaudRateOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetBufferLevelOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetCounterValuesOfEthSwtDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasGetDropCountOfEthSwtDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetDuplexModeOfEthSwtDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasGetLinkStateOfEthSwtDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetMacLearningModeOfEthSwtDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasGetPortCableDiagnosticsResultOfEthSwtDrvApi()                                      (TRUE != FALSE)
#define EthIf_HasGetPortMacAddrOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetPortSignalQualityOfEthSwtDrvApi()                                               (TRUE != FALSE)
#define EthIf_HasGetRxMgmtObjectOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasGetRxStatsOfEthSwtDrvApi()                                                         (TRUE != FALSE)
#define EthIf_HasGetSwitchPortWakeupReasonOfEthSwtDrvApi()                                          (TRUE != FALSE)
#define EthIf_HasGetSwtPortModeOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetTxErrorCounterValuesOfEthSwtDrvApi()                                            (TRUE != FALSE)
#define EthIf_HasGetTxMgmtObjectOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasGetTxStatsOfEthSwtDrvApi()                                                         (TRUE != FALSE)
#define EthIf_HasPortEnableTimeStampOfEthSwtDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasResetConfigOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasRunPortCableDiagnosticOfEthSwtDrvApi()                                             (TRUE != FALSE)
#define EthIf_HasSetCorrectionTimeOfEthSwtDrvApi()                                                  (TRUE != FALSE)
#define EthIf_HasSetMacLearningModeOfEthSwtDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasSetSwtMgmtInfoOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasSetSwtPortModeOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasStartQbvScheduleOfEthSwtDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasStartSwtPortAutoNegOfEthSwtDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasStopQbvScheduleOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasStoreConfigOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasSwtInitOfEthSwtDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasUpdateMCastPortAssignmentOfEthSwtDrvApi()                                          (TRUE != FALSE)
#define EthIf_HasEthSwtInd()                                                                        (EthIf_GetEthSwtIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtInitCnt()                                                                    (EthIf_GetEthSwtInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPort()                                                                       (EthIf_GetEthSwtPortOfPCConfig() != NULL_PTR)
#define EthIf_HasAsyncProcessingOfEthSwtPort()                                                      (TRUE != FALSE)
#define EthIf_HasEthSwtIdxOfEthSwtPort()                                                            (TRUE != FALSE)
#define EthIf_HasEthSwtPortHostOrUpLinkPortIdxOfEthSwtPort()                                        (TRUE != FALSE)
#define EthIf_HasMacSecSecuredOfEthSwtPort()                                                        (TRUE != FALSE)
#define EthIf_HasMkaPaeIdxOfEthSwtPort()                                                            (TRUE != FALSE)
#define EthIf_HasPortGroupIndEndIdxOfEthSwtPort()                                                   (TRUE != FALSE)
#define EthIf_HasPortGroupIndStartIdxOfEthSwtPort()                                                 (TRUE != FALSE)
#define EthIf_HasPortRoleOfEthSwtPort()                                                             (TRUE != FALSE)
#define EthIf_HasSnvOfEthSwtPort()                                                                  (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContext()                                                        (EthIf_GetEthSwtPortInEthSwtContextOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortIdxOfEthSwtPortInEthSwtContext()                                         (TRUE != FALSE)
#define EthIf_HasEthSwtPortUsedOfEthSwtPortInEthSwtContext()                                        (TRUE != FALSE)
#define EthIf_HasEthSwtPortInd()                                                                    (EthIf_GetEthSwtPortIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortLinkState()                                                              (EthIf_GetEthSwtPortLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortModeCnt()                                                                (EthIf_GetEthSwtPortModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcv()                                                                          (EthIf_GetEthTrcvOfPCConfig() != NULL_PTR)
#define EthIf_HasAsyncProcessingOfEthTrcv()                                                         (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv()                                             (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv()                                           (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndUsedOfEthTrcv()                                               (TRUE != FALSE)
#define EthIf_HasEthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcv()                              (TRUE != FALSE)
#define EthIf_HasEthTrcvActAsSlavePassiveEnabledOfEthTrcv()                                         (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApiIdxOfEthTrcv()                                                        (TRUE != FALSE)
#define EthIf_HasEthTrcvTypeOfEthTrcv()                                                             (TRUE != FALSE)
#define EthIf_HasMacSecSecuredOfEthTrcv()                                                           (TRUE != FALSE)
#define EthIf_HasMkaPaeIdxOfEthTrcv()                                                               (TRUE != FALSE)
#define EthIf_HasPortModeIdxOfEthTrcv()                                                             (TRUE != FALSE)
#define EthIf_HasPortModeUsedOfEthTrcv()                                                            (TRUE != FALSE)
#define EthIf_HasRequestedPortModeIdxOfEthTrcv()                                                    (TRUE != FALSE)
#define EthIf_HasRequestedPortModeUsedOfEthTrcv()                                                   (TRUE != FALSE)
#define EthIf_HasSnvOfEthTrcv()                                                                     (TRUE != FALSE)
#define EthIf_HasUserSleepIndicationOfEthTrcv()                                                     (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApi()                                                                    (EthIf_GetEthTrcvDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasCheckWakeupOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetBaudRateOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetCableDiagnosticsResultOfEthTrcvDrvApi()                                         (TRUE != FALSE)
#define EthIf_HasGetDuplexModeOfEthTrcvDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetLinkStateOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasGetPhySignalQualityOfEthTrcvDrvApi()                                               (TRUE != FALSE)
#define EthIf_HasGetPhyWakeupReasonOfEthTrcvDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasGetTrcvModeOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasRunCableDiagnosticOfEthTrcvDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasSetPhyLoopbackModeOfEthTrcvDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasSetPhyTestModeOfEthTrcvDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasSetPhyTxModeOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasSetTrcvModeOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasStartAutoNegOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasTrcvInitOfEthTrcvDrvApi()                                                          (TRUE != FALSE)
#define EthIf_HasEthTrcvInitCnt()                                                                   (EthIf_GetEthTrcvInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvLinkState()                                                                 (EthIf_GetEthTrcvLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvMode()                                                                      (EthIf_GetEthTrcvModeOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvModeChangeRetryCounter()                                                    (EthIf_GetEthTrcvModeChangeRetryCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvModeChangeRetryPeriodCounter()                                              (EthIf_GetEthTrcvModeChangeRetryPeriodCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvModeCnt()                                                                   (EthIf_GetEthTrcvModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvState()                                                                     (EthIf_GetEthTrcvStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTxQueue()                                                                       (EthIf_GetEthTxQueueOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfEthTxQueue()                                                           (TRUE != FALSE)
#define EthIf_HasQueueIndexOfEthTxQueue()                                                           (TRUE != FALSE)
#define EthIf_HasExplicitBufReleaseFilter()                                                         (EthIf_GetExplicitBufReleaseFilterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlIdxOfExplicitBufReleaseFilter()                                           (TRUE != FALSE)
#define EthIf_HasEtherTypeConfiguredOfExplicitBufReleaseFilter()                                    (TRUE != FALSE)
#define EthIf_HasEtherTypeOfExplicitBufReleaseFilter()                                              (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMap()                                                                 (EthIf_GetFloatingRxPduMapOfPCConfig() != NULL_PTR)
#define EthIf_HasRxPduEndIdxOfFloatingRxPduMap()                                                    (TRUE != FALSE)
#define EthIf_HasRxPduLengthOfFloatingRxPduMap()                                                    (TRUE != FALSE)
#define EthIf_HasRxPduStartIdxOfFloatingRxPduMap()                                                  (TRUE != FALSE)
#define EthIf_HasRxPduUsedOfFloatingRxPduMap()                                                      (TRUE != FALSE)
#define EthIf_HasFloatingRxPduNextFreePos()                                                         (EthIf_GetFloatingRxPduNextFreePosOfPCConfig() != NULL_PTR)
#define EthIf_HasGatewaySrcMacBlackList()                                                           (EthIf_GetGatewaySrcMacBlackListOfPCConfig() != NULL_PTR)
#define EthIf_HasMacAddrOfGatewaySrcMacBlackList()                                                  (TRUE != FALSE)
#define EthIf_HasGlobalModeChangeMaxRetryCount()                                                    (TRUE != FALSE)
#define EthIf_HasGlobalModeChangeRetryPeriodCount()                                                 (TRUE != FALSE)
#define EthIf_HasGlobalStartupActiveTimerActive()                                                   (EthIf_GetGlobalStartupActiveTimerActiveOfPCConfig() != NULL_PTR)
#define EthIf_HasInitLocked()                                                                       (EthIf_GetInitLockedOfPCConfig() != NULL_PTR)
#define EthIf_HasLegacyWakeupMap()                                                                  (EthIf_GetLegacyWakeupMapOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvIdxOfLegacyWakeupMap()                                                      (TRUE != FALSE)
#define EthIf_HasWakeupSourceOfLegacyWakeupMap()                                                    (TRUE != FALSE)
#define EthIf_HasLinkStateChgIndications()                                                          (EthIf_GetLinkStateChgIndicationsOfPCConfig() != NULL_PTR)
#define EthIf_HasLinkStateChgMainReload()                                                           (TRUE != FALSE)
#define EthIf_HasMainFuncStateDecoupleFreqCnt()                                                     (EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasMainPartitionRxEthCtrl()                                                           (EthIf_GetMainPartitionRxEthCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfMainPartitionRxEthCtrl()                                               (TRUE != FALSE)
#define EthIf_HasMainPartitionTxEthCtrl()                                                           (EthIf_GetMainPartitionTxEthCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfMainPartitionTxEthCtrl()                                               (TRUE != FALSE)
#define EthIf_HasMaxRxFramePerEthCtrl()                                                             (TRUE != FALSE)
#define EthIf_HasMaxTxBufPerEthCtrl()                                                               (TRUE != FALSE)
#define EthIf_HasMirrorDest()                                                                       (EthIf_GetMirrorDestOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfMirrorDest()                                                           (TRUE != FALSE)
#define EthIf_HasKeepSrcMacEnabledOfMirrorDest()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorTxInfo()                                                                     (EthIf_GetMirrorTxInfoOfPCConfig() != NULL_PTR)
#define EthIf_HasDestEthTxBufferIdxOfMirrorTxInfo()                                                 (TRUE != FALSE)
#define EthIf_HasDestPayloadPtrOfMirrorTxInfo()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlIdxOfMirrorTxInfo()                                                       (TRUE != FALSE)
#define EthIf_HasInfoValidOfMirrorTxInfo()                                                          (TRUE != FALSE)
#define EthIf_HasSrcEthTxBufferIdxOfMirrorTxInfo()                                                  (TRUE != FALSE)
#define EthIf_HasSrcPayloadPtrOfMirrorTxInfo()                                                      (TRUE != FALSE)
#define EthIf_HasUsedOfMirrorTxInfo()                                                               (TRUE != FALSE)
#define EthIf_HasModeChangeLocked()                                                                 (EthIf_GetModeChangeLockedOfPCConfig() != NULL_PTR)
#define EthIf_HasPhysLayerInitElems()                                                               (EthIf_GetPhysLayerInitElemsOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtIndEndIdxOfPhysLayerInitElems()                                              (TRUE != FALSE)
#define EthIf_HasEthSwtIndStartIdxOfPhysLayerInitElems()                                            (TRUE != FALSE)
#define EthIf_HasEthSwtIndUsedOfPhysLayerInitElems()                                                (TRUE != FALSE)
#define EthIf_HasEthTrcvIdxOfPhysLayerInitElems()                                                   (TRUE != FALSE)
#define EthIf_HasEthTrcvUsedOfPhysLayerInitElems()                                                  (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElems()                                                               (EthIf_GetPhysLayerModeElemsOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvIdxOfPhysLayerModeElems()                                                   (TRUE != FALSE)
#define EthIf_HasEthTrcvUsedOfPhysLayerModeElems()                                                  (TRUE != FALSE)
#define EthIf_HasPortGroupIdxOfPhysLayerModeElems()                                                 (TRUE != FALSE)
#define EthIf_HasPortGroupUsedOfPhysLayerModeElems()                                                (TRUE != FALSE)
#define EthIf_HasPortGroup()                                                                        (EthIf_GetPortGroupOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfPortGroupIndEndIdxOfPortGroup()                                         (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndStartIdxOfPortGroup()                                       (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndUsedOfPortGroup()                                           (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndEndIdxOfPortGroup()                                                   (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndStartIdxOfPortGroup()                                                 (TRUE != FALSE)
#define EthIf_HasHostAndUpLinkPortThresholdOfPortGroup()                                            (TRUE != FALSE)
#define EthIf_HasNoRolePortThresholdOfPortGroup()                                                   (TRUE != FALSE)
#define EthIf_HasSemanticOfPortGroup()                                                              (TRUE != FALSE)
#define EthIf_HasSnvOfPortGroup()                                                                   (TRUE != FALSE)
#define EthIf_HasPortGroupHostOrUpLinkPortRoleLinkCount()                                           (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupInd()                                                                     (EthIf_GetPortGroupIndOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupLinkState()                                                               (EthIf_GetPortGroupLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupMode()                                                                    (EthIf_GetPortGroupModeOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupNoRoleLinkCount()                                                         (EthIf_GetPortGroupNoRoleLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupStartupActiveTimerActive()                                                (EthIf_GetPortGroupStartupActiveTimerActiveOfPCConfig() != NULL_PTR)
#define EthIf_HasPortMode()                                                                         (EthIf_GetPortModeOfPCConfig() != NULL_PTR)
#define EthIf_HasPortSignalQualityResult()                                                          (EthIf_GetPortSignalQualityResultOfPCConfig() != NULL_PTR)
#define EthIf_HasPortStartupActiveTimeCounter()                                                     (EthIf_GetPortStartupActiveTimeCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasPortStartupActiveTimeFreq()                                                        (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimerActive()                                                     (EthIf_GetPortStartupActiveTimerActiveOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedEthIfCtrlMode()                                                           (EthIf_GetRequestedEthIfCtrlModeOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedEthTrcvMode()                                                             (EthIf_GetRequestedEthTrcvModeOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedEthTrcvStateOfEthIfCtrl()                                                 (EthIf_GetRequestedEthTrcvStateOfEthIfCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedPortGroupMode()                                                           (EthIf_GetRequestedPortGroupModeOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedPortGroupStateOfEthIfCtrl()                                               (EthIf_GetRequestedPortGroupStateOfEthIfCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasRequestedPortMode()                                                                (EthIf_GetRequestedPortModeOfPCConfig() != NULL_PTR)
#define EthIf_HasRxIndications()                                                                    (EthIf_GetRxIndicationsOfPCConfig() != NULL_PTR)
#define EthIf_HasRxPdu()                                                                            (EthIf_GetRxPduOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlToRxPduMapIdxOfRxPdu()                                                    (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMapUsedOfRxPdu()                                                   (TRUE != FALSE)
#define EthIf_HasEthMacAddrOffsetOfRxPdu()                                                          (TRUE != FALSE)
#define EthIf_HasFloatingPoolOfRxPdu()                                                              (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapIdxOfRxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapUsedOfRxPdu()                                                      (TRUE != FALSE)
#define EthIf_HasKeepLocalBufferOfRxPdu()                                                           (TRUE != FALSE)
#define EthIf_HasRxPduMetaDataEndIdxOfRxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasRxPduMetaDataLengthOfRxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasRxPduMetaDataStartIdxOfRxPdu()                                                     (TRUE != FALSE)
#define EthIf_HasRxPduMetaDataUsedOfRxPdu()                                                         (TRUE != FALSE)
#define EthIf_HasTimeTuplePtrOffsetOfRxPdu()                                                        (TRUE != FALSE)
#define EthIf_HasUlPduIdOfRxPdu()                                                                   (TRUE != FALSE)
#define EthIf_HasValidEthMacAddrMetaDataOfRxPdu()                                                   (TRUE != FALSE)
#define EthIf_HasValidTimeTupleMetaDataOfRxPdu()                                                    (TRUE != FALSE)
#define EthIf_HasRxPduContext()                                                                     (EthIf_GetRxPduContextOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlIdxOfRxPduContext()                                                       (TRUE != FALSE)
#define EthIf_HasRxHandleIdOfRxPduContext()                                                         (TRUE != FALSE)
#define EthIf_HasStateOfRxPduContext()                                                              (TRUE != FALSE)
#define EthIf_HasTimeTupleOfRxPduContext()                                                          (TRUE != FALSE)
#define EthIf_HasRxPduFrameType()                                                                   (EthIf_GetRxPduFrameTypeOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlToRxPduMapEndIdxOfRxPduFrameType()                                        (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMapLengthOfRxPduFrameType()                                        (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMapStartIdxOfRxPduFrameType()                                      (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMapUsedOfRxPduFrameType()                                          (TRUE != FALSE)
#define EthIf_HasEtherTypeOfRxPduFrameType()                                                        (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapEndIdxOfRxPduFrameType()                                           (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapLengthOfRxPduFrameType()                                           (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapStartIdxOfRxPduFrameType()                                         (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapUsedOfRxPduFrameType()                                             (TRUE != FALSE)
#define EthIf_HasRxPduFreeList()                                                                    (EthIf_GetRxPduFreeListOfPCConfig() != NULL_PTR)
#define EthIf_HasPduIdOfRxPduFreeList()                                                             (TRUE != FALSE)
#define EthIf_HasRxPduMetaData()                                                                    (EthIf_GetRxPduMetaDataOfPCConfig() != NULL_PTR)
#define EthIf_HasRxQueueList()                                                                      (EthIf_GetRxQueueListOfPCConfig() != NULL_PTR)
#define EthIf_HasEthRxQueueEndIdxOfRxQueueList()                                                    (TRUE != FALSE)
#define EthIf_HasEthRxQueueLengthOfRxQueueList()                                                    (TRUE != FALSE)
#define EthIf_HasEthRxQueueStartIdxOfRxQueueList()                                                  (TRUE != FALSE)
#define EthIf_HasEthRxQueueUsedOfRxQueueList()                                                      (TRUE != FALSE)
#define EthIf_HasSetControllerModeTimeout()                                                         (TRUE != FALSE)
#define EthIf_HasSignalQualityChgMainReload()                                                       (TRUE != FALSE)
#define EthIf_HasSignalQualityDecoupleFreqCnt()                                                     (EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasSignalQualityResult()                                                              (EthIf_GetSignalQualityResultOfPCConfig() != NULL_PTR)
#define EthIf_HasSizeOfDedicatedRxPduNextFreePos()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEcucPartition()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrl()                                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlInitCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlModeCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlState()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthDrvApi()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfClkUnit()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrl()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlInitState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkCount()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlMode()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfEthTrcvInd()                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPortGroupInd()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlRxStats()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlToEtherTypeMap()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlToRxPduMap()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlTxStats()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfMeasurementData()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfPhysCtrlCfg()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfQualifiedUnexpectedLinkDownTimerCounter()                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfQualifiedUnexpectedLinkDownTimerState()                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortGroupTimerDelayCounter()                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortGroupTimerDelayState()                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortTimerDelayState()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwtPortGroupState()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthRxQueue()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwt()                                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrv()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvApi()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInd()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInitCnt()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPort()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInEthSwtContext()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInd()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortLinkState()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortModeCnt()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcv()                                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvInitCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvLinkState()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvMode()                                                                (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeChangeRetryCounter()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeChangeRetryPeriodCounter()                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvState()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthTxQueue()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfExplicitBufReleaseFilter()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfFloatingRxPduMap()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfFloatingRxPduNextFreePos()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfGatewaySrcMacBlackList()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfLegacyWakeupMap()                                                            (TRUE != FALSE)
#define EthIf_HasSizeOfLinkStateChgIndications()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfMainPartitionRxEthCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfMainPartitionTxEthCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorDest()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorTxInfo()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerInitElems()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerModeElems()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroup()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupHostOrUpLinkPortRoleLinkCount()                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupInd()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLinkState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupMode()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupNoRoleLinkCount()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupStartupActiveTimerActive()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfPortMode()                                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfPortSignalQualityResult()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfPortStartupActiveTimerActive()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthIfCtrlMode()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthTrcvMode()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthTrcvStateOfEthIfCtrl()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortGroupMode()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortGroupStateOfEthIfCtrl()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortMode()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndications()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfRxPdu()                                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduContext()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduFrameType()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduFreeList()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduMetaData()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfRxQueueList()                                                                (TRUE != FALSE)
#define EthIf_HasSizeOfSignalQualityResult()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfSrcMacAddrBuffer()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfSwtPortGroupModeChangeRetryCounter()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfSwtPortGroupModeChangeRetryPeriodCounter()                                   (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmations()                                                            (TRUE != FALSE)
#define EthIf_HasSizeOfTxContext()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfTxPdu()                                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfTxPduContext()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfTxQueueList()                                                                (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupMap()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupSrcDevice()                                                            (TRUE != FALSE)
#define EthIf_HasSrcMacAddrBuffer()                                                                 (EthIf_GetSrcMacAddrBufferOfPCConfig() != NULL_PTR)
#define EthIf_HasSrcMacOfSrcMacAddrBuffer()                                                         (TRUE != FALSE)
#define EthIf_HasValidOfSrcMacAddrBuffer()                                                          (TRUE != FALSE)
#define EthIf_HasSwtPortGroupModeChangeReqCnt()                                                     (EthIf_GetSwtPortGroupModeChangeReqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasSwtPortGroupModeChangeRetryCounter()                                               (EthIf_GetSwtPortGroupModeChangeRetryCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasSwtPortGroupModeChangeRetryPeriodCounter()                                         (EthIf_GetSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasTxConfirmations()                                                                  (EthIf_GetTxConfirmationsOfPCConfig() != NULL_PTR)
#define EthIf_HasTxContext()                                                                        (EthIf_GetTxContextOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlIdxOfTxContext()                                                          (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMapIdxOfTxContext()                                            (TRUE != FALSE)
#define EthIf_HasFrameHdrOfTxContext()                                                              (TRUE != FALSE)
#define EthIf_HasLinkedPduIdOfTxContext()                                                           (TRUE != FALSE)
#define EthIf_HasPayloadLenOfTxContext()                                                            (TRUE != FALSE)
#define EthIf_HasPayloadPtrOfTxContext()                                                            (TRUE != FALSE)
#define EthIf_HasTxPendingOfTxContext()                                                             (TRUE != FALSE)
#define EthIf_HasValidOfTxContext()                                                                 (TRUE != FALSE)
#define EthIf_HasValidPduIdOfTxContext()                                                            (TRUE != FALSE)
#define EthIf_HasTxPdu()                                                                            (EthIf_GetTxPduOfPCConfig() != NULL_PTR)
#define EthIf_HasDirectDataProvisionOfTxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasEgressHardwareSupportedDataTransferOfTxPdu()                                       (TRUE != FALSE)
#define EthIf_HasEthIfCtrlIdxOfTxPdu()                                                              (TRUE != FALSE)
#define EthIf_HasEthIfCtrlUsedOfTxPdu()                                                             (TRUE != FALSE)
#define EthIf_HasEthMacAddrOffsetOfTxPdu()                                                          (TRUE != FALSE)
#define EthIf_HasEtherTypeOfTxPdu()                                                                 (TRUE != FALSE)
#define EthIf_HasFrameTxPriorityOfTxPdu()                                                           (TRUE != FALSE)
#define EthIf_HasKeepLocalBufferOfTxPdu()                                                           (TRUE != FALSE)
#define EthIf_HasListItemPtrOffsetOfTxPdu()                                                         (TRUE != FALSE)
#define EthIf_HasPriorityOffsetOfTxPdu()                                                            (TRUE != FALSE)
#define EthIf_HasTimeTuplePtrOffsetOfTxPdu()                                                        (TRUE != FALSE)
#define EthIf_HasTotalMetaDataLengthOfTxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasUlPduIdOfTxPdu()                                                                   (TRUE != FALSE)
#define EthIf_HasVLanOffsetOfTxPdu()                                                                (TRUE != FALSE)
#define EthIf_HasValidEthMacAddrMetaDataOfTxPdu()                                                   (TRUE != FALSE)
#define EthIf_HasValidListItemMetaDataOfTxPdu()                                                     (TRUE != FALSE)
#define EthIf_HasValidPriority8MetaDataOfTxPdu()                                                    (TRUE != FALSE)
#define EthIf_HasValidTimeTupleMetaDataOfTxPdu()                                                    (TRUE != FALSE)
#define EthIf_HasValidVlan16MetaDataOfTxPdu()                                                       (TRUE != FALSE)
#define EthIf_HasTxPduContext()                                                                     (EthIf_GetTxPduContextOfPCConfig() != NULL_PTR)
#define EthIf_HasFrameHdrBufOfTxPduContext()                                                        (TRUE != FALSE)
#define EthIf_HasFrameHdrOfTxPduContext()                                                           (TRUE != FALSE)
#define EthIf_HasListElementOfTxPduContext()                                                        (TRUE != FALSE)
#define EthIf_HasStateOfTxPduContext()                                                              (TRUE != FALSE)
#define EthIf_HasTimeTuplePtrOfTxPduContext()                                                       (TRUE != FALSE)
#define EthIf_HasTxQueueList()                                                                      (EthIf_GetTxQueueListOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTxQueueEndIdxOfTxQueueList()                                                    (TRUE != FALSE)
#define EthIf_HasEthTxQueueLengthOfTxQueueList()                                                    (TRUE != FALSE)
#define EthIf_HasEthTxQueueStartIdxOfTxQueueList()                                                  (TRUE != FALSE)
#define EthIf_HasEthTxQueueUsedOfTxQueueList()                                                      (TRUE != FALSE)
#define EthIf_HasWakeupMap()                                                                        (EthIf_GetWakeupMapOfPCConfig() != NULL_PTR)
#define EthIf_HasWakeupSourceMaskOfWakeupMap()                                                      (TRUE != FALSE)
#define EthIf_HasWakeupSrcDeviceEndIdxOfWakeupMap()                                                 (TRUE != FALSE)
#define EthIf_HasWakeupSrcDeviceLengthOfWakeupMap()                                                 (TRUE != FALSE)
#define EthIf_HasWakeupSrcDeviceStartIdxOfWakeupMap()                                               (TRUE != FALSE)
#define EthIf_HasWakeupSrcDeviceUsedOfWakeupMap()                                                   (TRUE != FALSE)
#define EthIf_HasWakeupSrcDevice()                                                                  (EthIf_GetWakeupSrcDeviceOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtIdxOfWakeupSrcDevice()                                                       (TRUE != FALSE)
#define EthIf_HasEthSwtUsedOfWakeupSrcDevice()                                                      (TRUE != FALSE)
#define EthIf_HasEthTrcvIdxOfWakeupSrcDevice()                                                      (TRUE != FALSE)
#define EthIf_HasEthTrcvUsedOfWakeupSrcDevice()                                                     (TRUE != FALSE)
#define EthIf_HasTypeOfWakeupSrcDevice()                                                            (TRUE != FALSE)
#define EthIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define EthIf_HasDedicatedRxPduNextFreePosOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasEcucPartitionOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthCtrlInitCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthCtrlModeCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthCtrlOfPCConfig()                                                                (TRUE != FALSE)
#define EthIf_HasEthCtrlStateOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthDrvApiOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthIfControllerModeChangeReqCntOfPCConfig()                                        (TRUE != FALSE)
#define EthIf_HasEthIfCtrlInitStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlLinkCountOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlLinkStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlModeOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasEthIfCtrlRxStatsOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToEtherTypeMapOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasEthIfCtrlToRxPduMapOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasEthIfCtrlTxStatsOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfMeasurementDataOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfgOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()                           (TRUE != FALSE)
#define EthIf_HasEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()                             (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()                               (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()                                 (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortTimeDelayCountsOfPCConfig()                                      (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortTimeDelayReqCntOfPCConfig()                                      (TRUE != FALSE)
#define EthIf_HasEthIfSwitchOffPortTimerDelayStateOfPCConfig()                                      (TRUE != FALSE)
#define EthIf_HasEthIfSwtPortGroupStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasEthRxQueueOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthSwtDrvOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthSwtIndOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthSwtInitCntOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtOfPCConfig()                                                                 (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortLinkStateOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasEthSwtPortModeCntOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasEthSwtPortOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApiOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthTrcvInitCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthTrcvLinkStateOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthTrcvModeChangeRetryCounterOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasEthTrcvModeChangeRetryPeriodCounterOfPCConfig()                                    (TRUE != FALSE)
#define EthIf_HasEthTrcvModeCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthTrcvModeOfPCConfig()                                                            (TRUE != FALSE)
#define EthIf_HasEthTrcvOfPCConfig()                                                                (TRUE != FALSE)
#define EthIf_HasEthTrcvStateOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthTxQueueOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasExplicitBufReleaseFilterOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasFloatingRxPduMapOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasFloatingRxPduNextFreePosOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasGatewaySrcMacBlackListOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasGlobalModeChangeMaxRetryCountOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasGlobalModeChangeRetryPeriodCountOfPCConfig()                                       (TRUE != FALSE)
#define EthIf_HasGlobalStartupActiveTimerActiveOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasInitLockedOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasLegacyWakeupMapOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasLinkStateChgIndicationsOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasLinkStateChgMainReloadOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasMainFuncStateDecoupleFreqCntOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasMainPartitionRxEthCtrlOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasMainPartitionTxEthCtrlOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasMaxRxFramePerEthCtrlOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasMaxTxBufPerEthCtrlOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasMirrorDestOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasMirrorTxInfoOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasModeChangeLockedOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasPhysLayerInitElemsOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElemsOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                                 (TRUE != FALSE)
#define EthIf_HasPortGroupIndOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasPortGroupLinkStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPortGroupModeOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasPortGroupNoRoleLinkCountOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasPortGroupOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasPortGroupStartupActiveTimerActiveOfPCConfig()                                      (TRUE != FALSE)
#define EthIf_HasPortModeOfPCConfig()                                                               (TRUE != FALSE)
#define EthIf_HasPortSignalQualityResultOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimeCounterOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimeFreqOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimerActiveOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasRequestedEthIfCtrlModeOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasRequestedEthTrcvModeOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()                                       (TRUE != FALSE)
#define EthIf_HasRequestedPortGroupModeOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasRequestedPortGroupStateOfEthIfCtrlOfPCConfig()                                     (TRUE != FALSE)
#define EthIf_HasRequestedPortModeOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasRxIndicationsOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasRxPduContextOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasRxPduFrameTypeOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasRxPduFreeListOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasRxPduMetaDataOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasRxPduOfPCConfig()                                                                  (TRUE != FALSE)
#define EthIf_HasRxQueueListOfPCConfig()                                                            (TRUE != FALSE)
#define EthIf_HasSetControllerModeTimeoutOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSignalQualityChgMainReloadOfPCConfig()                                             (TRUE != FALSE)
#define EthIf_HasSignalQualityDecoupleFreqCntOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSignalQualityResultOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfDedicatedRxPduNextFreePosOfPCConfig()                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEcucPartitionOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlInitCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlModeCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthDrvApiOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfClkUnitOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlInitStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkCountOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlModeOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()                                            (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlRxStatsOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlToEtherTypeMapOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlToRxPduMapOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlTxStatsOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfMeasurementDataOfPCConfig()                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfPhysCtrlCfgOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig()                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig()                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig()                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortGroupTimerDelayStateOfPCConfig()                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwitchOffPortTimerDelayStateOfPCConfig()                                (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwtPortGroupStateOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthRxQueueOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvApiOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtIndOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInitCntOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInEthSwtContextOfPCConfig()                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortIndOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortLinkStateOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortModeCntOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvDrvApiOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvInitCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvLinkStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeChangeRetryCounterOfPCConfig()                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeChangeRetryPeriodCounterOfPCConfig()                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthTxQueueOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfExplicitBufReleaseFilterOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfFloatingRxPduMapOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfFloatingRxPduNextFreePosOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfGatewaySrcMacBlackListOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfLegacyWakeupMapOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfLinkStateChgIndicationsOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfMainPartitionRxEthCtrlOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfMainPartitionTxEthCtrlOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorDestOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorTxInfoOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerInitElemsOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerModeElemsOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                           (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupIndOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLinkStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupModeOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupNoRoleLinkCountOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupStartupActiveTimerActiveOfPCConfig()                                (TRUE != FALSE)
#define EthIf_HasSizeOfPortModeOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortSignalQualityResultOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfPortStartupActiveTimerActiveOfPCConfig()                                     (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthIfCtrlModeOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthTrcvModeOfPCConfig()                                             (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedEthTrcvStateOfEthIfCtrlOfPCConfig()                                 (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortGroupModeOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortGroupStateOfEthIfCtrlOfPCConfig()                               (TRUE != FALSE)
#define EthIf_HasSizeOfRequestedPortModeOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndicationsOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduContextOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduFrameTypeOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduFreeListOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduMetaDataOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfRxPduOfPCConfig()                                                            (TRUE != FALSE)
#define EthIf_HasSizeOfRxQueueListOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfSignalQualityResultOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfSrcMacAddrBufferOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfSwtPortGroupModeChangeRetryCounterOfPCConfig()                               (TRUE != FALSE)
#define EthIf_HasSizeOfSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()                         (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmationsOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfTxContextOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfTxPduContextOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfTxPduOfPCConfig()                                                            (TRUE != FALSE)
#define EthIf_HasSizeOfTxQueueListOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupMapOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupSrcDeviceOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasSrcMacAddrBufferOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSwtPortGroupModeChangeReqCntOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSwtPortGroupModeChangeRetryCounterOfPCConfig()                                     (TRUE != FALSE)
#define EthIf_HasSwtPortGroupModeChangeRetryPeriodCounterOfPCConfig()                               (TRUE != FALSE)
#define EthIf_HasTxConfirmationsOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasTxContextOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasTxPduContextOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasTxPduOfPCConfig()                                                                  (TRUE != FALSE)
#define EthIf_HasTxQueueListOfPCConfig()                                                            (TRUE != FALSE)
#define EthIf_HasWakeupMapOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasWakeupSrcDeviceOfPCConfig()                                                        (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCIncrementDataMacros  EthIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EthIf_IncDedicatedRxPduNextFreePos(Index)                                                   EthIf_GetDedicatedRxPduNextFreePos(Index)++
#define EthIf_IncEthCtrlInitCnt(Index)                                                              EthIf_GetEthCtrlInitCnt(Index)++
#define EthIf_IncEthCtrlModeCnt(Index)                                                              EthIf_GetEthCtrlModeCnt(Index)++
#define EthIf_IncEthIfControllerModeChangeReqCnt()                                                  EthIf_GetEthIfControllerModeChangeReqCnt()++
#define EthIf_IncEthIfCtrlLinkCount(Index)                                                          EthIf_GetEthIfCtrlLinkCount(Index)++
#define EthIf_IncNumRxBytesOfEthIfCtrlRxStats(Index)                                                EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)++
#define EthIf_IncNumRxPktsOfEthIfCtrlRxStats(Index)                                                 EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)++
#define EthIf_IncNumTxBytesOfEthIfCtrlTxStats(Index)                                                EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)++
#define EthIf_IncNumTxPktsOfEthIfCtrlTxStats(Index)                                                 EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)++
#define EthIf_IncDropCtrlIdxOfEthIfMeasurementData(Index)                                           EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)++
#define EthIf_IncUnknownEtherTypeOfEthIfMeasurementData(Index)                                      EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)++
#define EthIf_IncVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)++
#define EthIf_IncEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)                                EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)++
#define EthIf_IncEthIfSwitchOffPortGroupTimerDelayCounter(Index)                                    EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index)++
#define EthIf_IncEthIfSwitchOffPortTimeDelayReqCnt()                                                EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt()++
#define EthIf_IncEthSwtInitCnt(Index)                                                               EthIf_GetEthSwtInitCnt(Index)++
#define EthIf_IncEthSwtPortModeCnt(Index)                                                           EthIf_GetEthSwtPortModeCnt(Index)++
#define EthIf_IncEthTrcvInitCnt(Index)                                                              EthIf_GetEthTrcvInitCnt(Index)++
#define EthIf_IncEthTrcvModeChangeRetryCounter(Index)                                               EthIf_GetEthTrcvModeChangeRetryCounter(Index)++
#define EthIf_IncEthTrcvModeChangeRetryPeriodCounter(Index)                                         EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index)++
#define EthIf_IncEthTrcvModeCnt(Index)                                                              EthIf_GetEthTrcvModeCnt(Index)++
#define EthIf_IncFloatingRxPduNextFreePos(Index)                                                    EthIf_GetFloatingRxPduNextFreePos(Index)++
#define EthIf_IncMainFuncStateDecoupleFreqCnt()                                                     EthIf_GetMainFuncStateDecoupleFreqCnt()++
#define EthIf_IncDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)++
#define EthIf_IncEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)++
#define EthIf_IncSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)++
#define EthIf_IncPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)++
#define EthIf_IncPortGroupNoRoleLinkCount(Index)                                                    EthIf_GetPortGroupNoRoleLinkCount(Index)++
#define EthIf_IncPortStartupActiveTimeCounter()                                                     EthIf_GetPortStartupActiveTimeCounter()++
#define EthIf_IncEthIfCtrlIdxOfRxPduContext(Index)                                                  EthIf_GetEthIfCtrlIdxOfRxPduContext(Index)++
#define EthIf_IncRxHandleIdOfRxPduContext(Index)                                                    EthIf_GetRxHandleIdOfRxPduContext(Index)++
#define EthIf_IncPduIdOfRxPduFreeList(Index)                                                        EthIf_GetPduIdOfRxPduFreeList(Index)++
#define EthIf_IncRxPduMetaData(Index)                                                               EthIf_GetRxPduMetaData(Index)++
#define EthIf_IncSignalQualityDecoupleFreqCnt()                                                     EthIf_GetSignalQualityDecoupleFreqCnt()++
#define EthIf_IncSwtPortGroupModeChangeReqCnt()                                                     EthIf_GetSwtPortGroupModeChangeReqCnt()++
#define EthIf_IncSwtPortGroupModeChangeRetryCounter(Index)                                          EthIf_GetSwtPortGroupModeChangeRetryCounter(Index)++
#define EthIf_IncSwtPortGroupModeChangeRetryPeriodCounter(Index)                                    EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index)++
#define EthIf_IncEthIfCtrlIdxOfTxContext(Index)                                                     EthIf_GetEthIfCtrlIdxOfTxContext(Index)++
#define EthIf_IncEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)                                       EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)++
#define EthIf_IncPayloadLenOfTxContext(Index)                                                       EthIf_GetPayloadLenOfTxContext(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCDecrementDataMacros  EthIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EthIf_DecDedicatedRxPduNextFreePos(Index)                                                   EthIf_GetDedicatedRxPduNextFreePos(Index)--
#define EthIf_DecEthCtrlInitCnt(Index)                                                              EthIf_GetEthCtrlInitCnt(Index)--
#define EthIf_DecEthCtrlModeCnt(Index)                                                              EthIf_GetEthCtrlModeCnt(Index)--
#define EthIf_DecEthIfControllerModeChangeReqCnt()                                                  EthIf_GetEthIfControllerModeChangeReqCnt()--
#define EthIf_DecEthIfCtrlLinkCount(Index)                                                          EthIf_GetEthIfCtrlLinkCount(Index)--
#define EthIf_DecNumRxBytesOfEthIfCtrlRxStats(Index)                                                EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)--
#define EthIf_DecNumRxPktsOfEthIfCtrlRxStats(Index)                                                 EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)--
#define EthIf_DecNumTxBytesOfEthIfCtrlTxStats(Index)                                                EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)--
#define EthIf_DecNumTxPktsOfEthIfCtrlTxStats(Index)                                                 EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)--
#define EthIf_DecDropCtrlIdxOfEthIfMeasurementData(Index)                                           EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)--
#define EthIf_DecUnknownEtherTypeOfEthIfMeasurementData(Index)                                      EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)--
#define EthIf_DecVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)--
#define EthIf_DecEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)                                EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index)--
#define EthIf_DecEthIfSwitchOffPortGroupTimerDelayCounter(Index)                                    EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index)--
#define EthIf_DecEthIfSwitchOffPortTimeDelayReqCnt()                                                EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt()--
#define EthIf_DecEthSwtInitCnt(Index)                                                               EthIf_GetEthSwtInitCnt(Index)--
#define EthIf_DecEthSwtPortModeCnt(Index)                                                           EthIf_GetEthSwtPortModeCnt(Index)--
#define EthIf_DecEthTrcvInitCnt(Index)                                                              EthIf_GetEthTrcvInitCnt(Index)--
#define EthIf_DecEthTrcvModeChangeRetryCounter(Index)                                               EthIf_GetEthTrcvModeChangeRetryCounter(Index)--
#define EthIf_DecEthTrcvModeChangeRetryPeriodCounter(Index)                                         EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index)--
#define EthIf_DecEthTrcvModeCnt(Index)                                                              EthIf_GetEthTrcvModeCnt(Index)--
#define EthIf_DecFloatingRxPduNextFreePos(Index)                                                    EthIf_GetFloatingRxPduNextFreePos(Index)--
#define EthIf_DecMainFuncStateDecoupleFreqCnt()                                                     EthIf_GetMainFuncStateDecoupleFreqCnt()--
#define EthIf_DecDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)--
#define EthIf_DecEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)--
#define EthIf_DecSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)--
#define EthIf_DecPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)--
#define EthIf_DecPortGroupNoRoleLinkCount(Index)                                                    EthIf_GetPortGroupNoRoleLinkCount(Index)--
#define EthIf_DecPortStartupActiveTimeCounter()                                                     EthIf_GetPortStartupActiveTimeCounter()--
#define EthIf_DecEthIfCtrlIdxOfRxPduContext(Index)                                                  EthIf_GetEthIfCtrlIdxOfRxPduContext(Index)--
#define EthIf_DecRxHandleIdOfRxPduContext(Index)                                                    EthIf_GetRxHandleIdOfRxPduContext(Index)--
#define EthIf_DecPduIdOfRxPduFreeList(Index)                                                        EthIf_GetPduIdOfRxPduFreeList(Index)--
#define EthIf_DecRxPduMetaData(Index)                                                               EthIf_GetRxPduMetaData(Index)--
#define EthIf_DecSignalQualityDecoupleFreqCnt()                                                     EthIf_GetSignalQualityDecoupleFreqCnt()--
#define EthIf_DecSwtPortGroupModeChangeReqCnt()                                                     EthIf_GetSwtPortGroupModeChangeReqCnt()--
#define EthIf_DecSwtPortGroupModeChangeRetryCounter(Index)                                          EthIf_GetSwtPortGroupModeChangeRetryCounter(Index)--
#define EthIf_DecSwtPortGroupModeChangeRetryPeriodCounter(Index)                                    EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index)--
#define EthIf_DecEthIfCtrlIdxOfTxContext(Index)                                                     EthIf_GetEthIfCtrlIdxOfTxContext(Index)--
#define EthIf_DecEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)                                       EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index)--
#define EthIf_DecPayloadLenOfTxContext(Index)                                                       EthIf_GetPayloadLenOfTxContext(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCAddDataMacros  EthIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define EthIf_AddDedicatedRxPduNextFreePos(Index, Value)                                            EthIf_SetDedicatedRxPduNextFreePos(Index, (EthIf_GetDedicatedRxPduNextFreePos(Index) + Value))
#define EthIf_AddEthCtrlInitCnt(Index, Value)                                                       EthIf_SetEthCtrlInitCnt(Index, (EthIf_GetEthCtrlInitCnt(Index) + Value))
#define EthIf_AddEthCtrlModeCnt(Index, Value)                                                       EthIf_SetEthCtrlModeCnt(Index, (EthIf_GetEthCtrlModeCnt(Index) + Value))
#define EthIf_AddEthIfControllerModeChangeReqCnt(Value)                                             EthIf_SetEthIfControllerModeChangeReqCnt((EthIf_GetEthIfControllerModeChangeReqCnt() + Value))
#define EthIf_AddEthIfCtrlLinkCount(Index, Value)                                                   EthIf_SetEthIfCtrlLinkCount(Index, (EthIf_GetEthIfCtrlLinkCount(Index) + Value))
#define EthIf_AddNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index) + Value))
#define EthIf_AddNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index) + Value))
#define EthIf_AddNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index) + Value))
#define EthIf_AddNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index) + Value))
#define EthIf_AddDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, (EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, (EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, (EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddEthIfQualifiedUnexpectedLinkDownTimerCounter(Index, Value)                         EthIf_SetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index, (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index) + Value))
#define EthIf_AddEthIfSwitchOffPortGroupTimerDelayCounter(Index, Value)                             EthIf_SetEthIfSwitchOffPortGroupTimerDelayCounter(Index, (EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index) + Value))
#define EthIf_AddEthIfSwitchOffPortTimeDelayReqCnt(Value)                                           EthIf_SetEthIfSwitchOffPortTimeDelayReqCnt((EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt() + Value))
#define EthIf_AddEthSwtInitCnt(Index, Value)                                                        EthIf_SetEthSwtInitCnt(Index, (EthIf_GetEthSwtInitCnt(Index) + Value))
#define EthIf_AddEthSwtPortModeCnt(Index, Value)                                                    EthIf_SetEthSwtPortModeCnt(Index, (EthIf_GetEthSwtPortModeCnt(Index) + Value))
#define EthIf_AddEthTrcvInitCnt(Index, Value)                                                       EthIf_SetEthTrcvInitCnt(Index, (EthIf_GetEthTrcvInitCnt(Index) + Value))
#define EthIf_AddEthTrcvModeChangeRetryCounter(Index, Value)                                        EthIf_SetEthTrcvModeChangeRetryCounter(Index, (EthIf_GetEthTrcvModeChangeRetryCounter(Index) + Value))
#define EthIf_AddEthTrcvModeChangeRetryPeriodCounter(Index, Value)                                  EthIf_SetEthTrcvModeChangeRetryPeriodCounter(Index, (EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index) + Value))
#define EthIf_AddEthTrcvModeCnt(Index, Value)                                                       EthIf_SetEthTrcvModeCnt(Index, (EthIf_GetEthTrcvModeCnt(Index) + Value))
#define EthIf_AddFloatingRxPduNextFreePos(Index, Value)                                             EthIf_SetFloatingRxPduNextFreePos(Index, (EthIf_GetFloatingRxPduNextFreePos(Index) + Value))
#define EthIf_AddMainFuncStateDecoupleFreqCnt(Value)                                                EthIf_SetMainFuncStateDecoupleFreqCnt((EthIf_GetMainFuncStateDecoupleFreqCnt() + Value))
#define EthIf_AddDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, (EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index) + Value))
#define EthIf_AddPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_SetPortGroupNoRoleLinkCount(Index, (EthIf_GetPortGroupNoRoleLinkCount(Index) + Value))
#define EthIf_AddPortStartupActiveTimeCounter(Value)                                                EthIf_SetPortStartupActiveTimeCounter((EthIf_GetPortStartupActiveTimeCounter() + Value))
#define EthIf_AddEthIfCtrlIdxOfRxPduContext(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfRxPduContext(Index, (EthIf_GetEthIfCtrlIdxOfRxPduContext(Index) + Value))
#define EthIf_AddRxHandleIdOfRxPduContext(Index, Value)                                             EthIf_SetRxHandleIdOfRxPduContext(Index, (EthIf_GetRxHandleIdOfRxPduContext(Index) + Value))
#define EthIf_AddPduIdOfRxPduFreeList(Index, Value)                                                 EthIf_SetPduIdOfRxPduFreeList(Index, (EthIf_GetPduIdOfRxPduFreeList(Index) + Value))
#define EthIf_AddRxPduMetaData(Index, Value)                                                        EthIf_SetRxPduMetaData(Index, (EthIf_GetRxPduMetaData(Index) + Value))
#define EthIf_AddSignalQualityDecoupleFreqCnt(Value)                                                EthIf_SetSignalQualityDecoupleFreqCnt((EthIf_GetSignalQualityDecoupleFreqCnt() + Value))
#define EthIf_AddSwtPortGroupModeChangeReqCnt(Value)                                                EthIf_SetSwtPortGroupModeChangeReqCnt((EthIf_GetSwtPortGroupModeChangeReqCnt() + Value))
#define EthIf_AddSwtPortGroupModeChangeRetryCounter(Index, Value)                                   EthIf_SetSwtPortGroupModeChangeRetryCounter(Index, (EthIf_GetSwtPortGroupModeChangeRetryCounter(Index) + Value))
#define EthIf_AddSwtPortGroupModeChangeRetryPeriodCounter(Index, Value)                             EthIf_SetSwtPortGroupModeChangeRetryPeriodCounter(Index, (EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index) + Value))
#define EthIf_AddEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_SetEthIfCtrlIdxOfTxContext(Index, (EthIf_GetEthIfCtrlIdxOfTxContext(Index) + Value))
#define EthIf_AddEthIfCtrlToEtherTypeMapIdxOfTxContext(Index, Value)                                EthIf_SetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index, (EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index) + Value))
#define EthIf_AddPayloadLenOfTxContext(Index, Value)                                                EthIf_SetPayloadLenOfTxContext(Index, (EthIf_GetPayloadLenOfTxContext(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSubstractDataMacros  EthIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define EthIf_SubDedicatedRxPduNextFreePos(Index, Value)                                            EthIf_SetDedicatedRxPduNextFreePos(Index, (EthIf_GetDedicatedRxPduNextFreePos(Index) - Value))
#define EthIf_SubEthCtrlInitCnt(Index, Value)                                                       EthIf_SetEthCtrlInitCnt(Index, (EthIf_GetEthCtrlInitCnt(Index) - Value))
#define EthIf_SubEthCtrlModeCnt(Index, Value)                                                       EthIf_SetEthCtrlModeCnt(Index, (EthIf_GetEthCtrlModeCnt(Index) - Value))
#define EthIf_SubEthIfControllerModeChangeReqCnt(Value)                                             EthIf_SetEthIfControllerModeChangeReqCnt((EthIf_GetEthIfControllerModeChangeReqCnt() - Value))
#define EthIf_SubEthIfCtrlLinkCount(Index, Value)                                                   EthIf_SetEthIfCtrlLinkCount(Index, (EthIf_GetEthIfCtrlLinkCount(Index) - Value))
#define EthIf_SubNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index) - Value))
#define EthIf_SubNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index) - Value))
#define EthIf_SubNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index) - Value))
#define EthIf_SubNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index) - Value))
#define EthIf_SubDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, (EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, (EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, (EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubEthIfQualifiedUnexpectedLinkDownTimerCounter(Index, Value)                         EthIf_SetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index, (EthIf_GetEthIfQualifiedUnexpectedLinkDownTimerCounter(Index) - Value))
#define EthIf_SubEthIfSwitchOffPortGroupTimerDelayCounter(Index, Value)                             EthIf_SetEthIfSwitchOffPortGroupTimerDelayCounter(Index, (EthIf_GetEthIfSwitchOffPortGroupTimerDelayCounter(Index) - Value))
#define EthIf_SubEthIfSwitchOffPortTimeDelayReqCnt(Value)                                           EthIf_SetEthIfSwitchOffPortTimeDelayReqCnt((EthIf_GetEthIfSwitchOffPortTimeDelayReqCnt() - Value))
#define EthIf_SubEthSwtInitCnt(Index, Value)                                                        EthIf_SetEthSwtInitCnt(Index, (EthIf_GetEthSwtInitCnt(Index) - Value))
#define EthIf_SubEthSwtPortModeCnt(Index, Value)                                                    EthIf_SetEthSwtPortModeCnt(Index, (EthIf_GetEthSwtPortModeCnt(Index) - Value))
#define EthIf_SubEthTrcvInitCnt(Index, Value)                                                       EthIf_SetEthTrcvInitCnt(Index, (EthIf_GetEthTrcvInitCnt(Index) - Value))
#define EthIf_SubEthTrcvModeChangeRetryCounter(Index, Value)                                        EthIf_SetEthTrcvModeChangeRetryCounter(Index, (EthIf_GetEthTrcvModeChangeRetryCounter(Index) - Value))
#define EthIf_SubEthTrcvModeChangeRetryPeriodCounter(Index, Value)                                  EthIf_SetEthTrcvModeChangeRetryPeriodCounter(Index, (EthIf_GetEthTrcvModeChangeRetryPeriodCounter(Index) - Value))
#define EthIf_SubEthTrcvModeCnt(Index, Value)                                                       EthIf_SetEthTrcvModeCnt(Index, (EthIf_GetEthTrcvModeCnt(Index) - Value))
#define EthIf_SubFloatingRxPduNextFreePos(Index, Value)                                             EthIf_SetFloatingRxPduNextFreePos(Index, (EthIf_GetFloatingRxPduNextFreePos(Index) - Value))
#define EthIf_SubMainFuncStateDecoupleFreqCnt(Value)                                                EthIf_SetMainFuncStateDecoupleFreqCnt((EthIf_GetMainFuncStateDecoupleFreqCnt() - Value))
#define EthIf_SubDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, (EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index) - Value))
#define EthIf_SubPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_SetPortGroupNoRoleLinkCount(Index, (EthIf_GetPortGroupNoRoleLinkCount(Index) - Value))
#define EthIf_SubPortStartupActiveTimeCounter(Value)                                                EthIf_SetPortStartupActiveTimeCounter((EthIf_GetPortStartupActiveTimeCounter() - Value))
#define EthIf_SubEthIfCtrlIdxOfRxPduContext(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfRxPduContext(Index, (EthIf_GetEthIfCtrlIdxOfRxPduContext(Index) - Value))
#define EthIf_SubRxHandleIdOfRxPduContext(Index, Value)                                             EthIf_SetRxHandleIdOfRxPduContext(Index, (EthIf_GetRxHandleIdOfRxPduContext(Index) - Value))
#define EthIf_SubPduIdOfRxPduFreeList(Index, Value)                                                 EthIf_SetPduIdOfRxPduFreeList(Index, (EthIf_GetPduIdOfRxPduFreeList(Index) - Value))
#define EthIf_SubRxPduMetaData(Index, Value)                                                        EthIf_SetRxPduMetaData(Index, (EthIf_GetRxPduMetaData(Index) - Value))
#define EthIf_SubSignalQualityDecoupleFreqCnt(Value)                                                EthIf_SetSignalQualityDecoupleFreqCnt((EthIf_GetSignalQualityDecoupleFreqCnt() - Value))
#define EthIf_SubSwtPortGroupModeChangeReqCnt(Value)                                                EthIf_SetSwtPortGroupModeChangeReqCnt((EthIf_GetSwtPortGroupModeChangeReqCnt() - Value))
#define EthIf_SubSwtPortGroupModeChangeRetryCounter(Index, Value)                                   EthIf_SetSwtPortGroupModeChangeRetryCounter(Index, (EthIf_GetSwtPortGroupModeChangeRetryCounter(Index) - Value))
#define EthIf_SubSwtPortGroupModeChangeRetryPeriodCounter(Index, Value)                             EthIf_SetSwtPortGroupModeChangeRetryPeriodCounter(Index, (EthIf_GetSwtPortGroupModeChangeRetryPeriodCounter(Index) - Value))
#define EthIf_SubEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_SetEthIfCtrlIdxOfTxContext(Index, (EthIf_GetEthIfCtrlIdxOfTxContext(Index) - Value))
#define EthIf_SubEthIfCtrlToEtherTypeMapIdxOfTxContext(Index, Value)                                EthIf_SetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index, (EthIf_GetEthIfCtrlToEtherTypeMapIdxOfTxContext(Index) - Value))
#define EthIf_SubPayloadLenOfTxContext(Index, Value)                                                EthIf_SetPayloadLenOfTxContext(Index, (EthIf_GetPayloadLenOfTxContext(Index) - Value))
/** 
  \}
*/ 


/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

# if !defined(ETHIF_UNIT_TEST)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

# endif /* ETHIF_UNIT_TEST */

#endif /* ETHIF_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_Lcfg.h
 *********************************************************************************************************************/


