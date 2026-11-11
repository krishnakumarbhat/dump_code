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
 *            Module: EthTrcv_30_Tja1103
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Tja1103_Lcfg.h
 *   Generation Time: 2026-09-03 22:28:17
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

#if !defined (ETHTRCV_30_TJA1103_LCFG_H)
# define ETHTRCV_30_TJA1103_LCFG_H
/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
# include "EthTrcv_30_Tja1103_GenTypes.h"

# if !defined (ETHTRCV_30_TJA1103_LOCAL_INLINE)
#  define ETHTRCV_30_TJA1103_LOCAL_INLINE LOCAL_INLINE
# endif
/**********************************************************************************************************************
 *  RTM MEASUREMENT POINT MACROS
 *********************************************************************************************************************/

/* PRQA S 0342 2 */ /* MD_MSR_Rule20.10_0342 */
# define EthTrcv_30_Tja1103_Rtm_Start(Type) \
  Rtm_Start(RtmConf_RtmMeasurementPoint_EthTrcv_30_Tja1103_##Type)

/* PRQA S 0342 2 */ /* MD_MSR_Rule20.10_0342 */
# define EthTrcv_30_Tja1103_Rtm_Stop(Type) \
  Rtm_Stop(RtmConf_RtmMeasurementPoint_EthTrcv_30_Tja1103_##Type)

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Tja1103_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_ConfigDataPtr
  \brief  Points to the currently active configuration for EthTrcv_30_Tja1103
  \details
  Pointer is intialized during EthTrcv_30_Tja1103_Init() and holds the active configuration for EthTrcv_30_Tja1103
  were all configuration data is retrieved from during runtime.
*/ 
# define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"
extern P2CONST(EthTrcv_30_Tja1103_ConfigType, ETHTRCV_30_TJA1103_VAR_NOINIT, ETHTRCV_30_TJA1103_INIT_DATA) EthTrcv_30_Tja1103_ConfigDataPtr;
# define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

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
  \defgroup  EthTrcv_30_Tja1103PCGetRootDataMacros  EthTrcv_30_Tja1103 Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define EthTrcv_30_Tja1103_GetAccessEntityFctsOfPCConfig()                                          EthTrcv_30_Tja1103_ConfigDataPtr->AccessEntityFctsOfPCConfig
#define EthTrcv_30_Tja1103_GetCableDiagLoopCyclesOfPCConfig()                                       EthTrcv_30_Tja1103_ConfigDataPtr->CableDiagLoopCyclesOfPCConfig
#define EthTrcv_30_Tja1103_GetCableDiagnosticStateOfPCConfig()                                      EthTrcv_30_Tja1103_ConfigDataPtr->CableDiagnosticStateOfPCConfig
#define EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()                                                   EthTrcv_30_Tja1103_ConfigDataPtr->EthTrcvOfPCConfig
#define EthTrcv_30_Tja1103_GetEthTrcvTja1103OfPCConfig()                                            EthTrcv_30_Tja1103_ConfigDataPtr->EthTrcvTja1103OfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessLoopCountOfPCConfig()                                         EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessLoopCountOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounterOfPCConfig()                               EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorCycleCounterOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureCalloutOfPCConfig()                             EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorFailureCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()                     EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorFailureDebounceCounterOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceLimiterOfPCConfig()                     EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorFailureDebounceLimiterOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorLoopLimiterOfPCConfig()                                EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorLoopLimiterOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()                    EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorRecoveryDebounceCounterOfPCConfig
#define EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()                    EthTrcv_30_Tja1103_ConfigDataPtr->HwAccessMonitorRecoveryDebounceLimiterOfPCConfig
#define EthTrcv_30_Tja1103_GetMaxPhySignalQualityMeanOfPCConfig()                                   EthTrcv_30_Tja1103_ConfigDataPtr->MaxPhySignalQualityMeanOfPCConfig
#define EthTrcv_30_Tja1103_GetPolSwapConfigOfPCConfig()                                             EthTrcv_30_Tja1103_ConfigDataPtr->PolSwapConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfAccessEntityFctsOfPCConfig()                                    EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfAccessEntityFctsOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()                                             EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfEthTrcvOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfEthTrcvTja1103OfPCConfig()                                      EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfEthTrcvTja1103OfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureCalloutOfPCConfig()                       EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfHwAccessMonitorFailureCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfPolSwapConfigOfPCConfig()                                       EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfPolSwapConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfSmiConfigurationOfPCConfig()                                    EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfSmiConfigurationOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfTrcvRgmiiConfigOfPCConfig()                                     EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfTrcvRgmiiConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfUserAccessCalloutsOfPCConfig()                                  EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfUserAccessCalloutsOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfUserInitCalloutsOfPCConfig()                                    EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfUserInitCalloutsOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfWakeupCalloutOfPCConfig()                                       EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfWakeupCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfWakeupMapOfPCConfig()                                           EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfWakeupMapOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfWakeupOfPCConfig()                                              EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfWakeupOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfWakeupVerificationCalloutOfPCConfig()                           EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfWakeupVerificationCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfXmiiClkIoConfigOfPCConfig()                                     EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfXmiiClkIoConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetSizeOfXmiiDataIoConfigOfPCConfig()                                    EthTrcv_30_Tja1103_ConfigDataPtr->SizeOfXmiiDataIoConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetSmiConfigurationOfPCConfig()                                          EthTrcv_30_Tja1103_ConfigDataPtr->SmiConfigurationOfPCConfig
#define EthTrcv_30_Tja1103_GetTrcvHwAccessibilityOfPCConfig()                                       EthTrcv_30_Tja1103_ConfigDataPtr->TrcvHwAccessibilityOfPCConfig
#define EthTrcv_30_Tja1103_GetTrcvLinkStateOfPCConfig()                                             EthTrcv_30_Tja1103_ConfigDataPtr->TrcvLinkStateOfPCConfig
#define EthTrcv_30_Tja1103_GetTrcvModeOfPCConfig()                                                  EthTrcv_30_Tja1103_ConfigDataPtr->TrcvModeOfPCConfig
#define EthTrcv_30_Tja1103_GetTrcvRgmiiConfigOfPCConfig()                                           EthTrcv_30_Tja1103_ConfigDataPtr->TrcvRgmiiConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetTrcvStateOfPCConfig()                                                 EthTrcv_30_Tja1103_ConfigDataPtr->TrcvStateOfPCConfig
#define EthTrcv_30_Tja1103_GetUserAccessCalloutsOfPCConfig()                                        EthTrcv_30_Tja1103_ConfigDataPtr->UserAccessCalloutsOfPCConfig
#define EthTrcv_30_Tja1103_GetUserInitCalloutsOfPCConfig()                                          EthTrcv_30_Tja1103_ConfigDataPtr->UserInitCalloutsOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupCalloutOfPCConfig()                                             EthTrcv_30_Tja1103_ConfigDataPtr->WakeupCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupMapOfPCConfig()                                                 EthTrcv_30_Tja1103_ConfigDataPtr->WakeupMapOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupModeOfPCConfig()                                                EthTrcv_30_Tja1103_ConfigDataPtr->WakeupModeOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupOfPCConfig()                                                    EthTrcv_30_Tja1103_ConfigDataPtr->WakeupOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupReasonFlagsOfPCConfig()                                         EthTrcv_30_Tja1103_ConfigDataPtr->WakeupReasonFlagsOfPCConfig
#define EthTrcv_30_Tja1103_GetWakeupVerificationCalloutOfPCConfig()                                 EthTrcv_30_Tja1103_ConfigDataPtr->WakeupVerificationCalloutOfPCConfig
#define EthTrcv_30_Tja1103_GetXmiiClkIoConfigOfPCConfig()                                           EthTrcv_30_Tja1103_ConfigDataPtr->XmiiClkIoConfigOfPCConfig
#define EthTrcv_30_Tja1103_GetXmiiDataIoConfigOfPCConfig()                                          EthTrcv_30_Tja1103_ConfigDataPtr->XmiiDataIoConfigOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCGetDuplicatedRootDataMacros  EthTrcv_30_Tja1103 Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define EthTrcv_30_Tja1103_GetSizeOfCableDiagnosticStateOfPCConfig()                                EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_CableDiagnosticState */
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()               EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter */
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()              EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter */
#define EthTrcv_30_Tja1103_GetSizeOfTrcvHwAccessibilityOfPCConfig()                                 EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvHwAccessibility */
#define EthTrcv_30_Tja1103_GetSizeOfTrcvLinkStateOfPCConfig()                                       EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvLinkState */
#define EthTrcv_30_Tja1103_GetSizeOfTrcvModeOfPCConfig()                                            EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvMode */
#define EthTrcv_30_Tja1103_GetSizeOfTrcvStateOfPCConfig()                                           EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvState */
#define EthTrcv_30_Tja1103_GetSizeOfWakeupModeOfPCConfig()                                          EthTrcv_30_Tja1103_GetSizeOfWakeupOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupMode */
#define EthTrcv_30_Tja1103_GetSizeOfWakeupReasonFlagsOfPCConfig()                                   EthTrcv_30_Tja1103_GetSizeOfWakeupOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupReasonFlags */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCGetDataMacros  EthTrcv_30_Tja1103 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EthTrcv_30_Tja1103_GetReadTrcvRegOfAccessEntityFcts(Index)                                  (EthTrcv_30_Tja1103_GetAccessEntityFctsOfPCConfig()[(Index)].ReadTrcvRegOfAccessEntityFcts)
#define EthTrcv_30_Tja1103_GetWriteTrcvRegOfAccessEntityFcts(Index)                                 (EthTrcv_30_Tja1103_GetAccessEntityFctsOfPCConfig()[(Index)].WriteTrcvRegOfAccessEntityFcts)
#define EthTrcv_30_Tja1103_GetCableDiagnosticState(Index)                                           (EthTrcv_30_Tja1103_GetCableDiagnosticStateOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetAccessEntityFctsIdxOfEthTrcv(Index)                                   (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].AccessEntityFctsIdxOfEthTrcv)
#define EthTrcv_30_Tja1103_GetAccessEntitySnvOfEthTrcv(Index)                                       (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].AccessEntitySnvOfEthTrcv)
#define EthTrcv_30_Tja1103_GetAddressingIdxOfEthTrcv(Index)                                         (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].AddressingIdxOfEthTrcv)
#define EthTrcv_30_Tja1103_IsAutoNegEnabledOfEthTrcv(Index)                                         ((EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].AutoNegEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Tja1103_GetBasicCtrlRegValOfEthTrcv(Index)                                       (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].BasicCtrlRegValOfEthTrcv)
#define EthTrcv_30_Tja1103_GetConnectionNegOfEthTrcv(Index)                                         (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].ConnectionNegOfEthTrcv)
#define EthTrcv_30_Tja1103_GetDemEAccessEventIdOfEthTrcv(Index)                                     (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].DemEAccessEventIdOfEthTrcv)
#define EthTrcv_30_Tja1103_IsHwAccessMonitorEnabledOfEthTrcv(Index)                                 ((EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].HwAccessMonitorEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Tja1103_IsMacSecEnabledOfEthTrcv(Index)                                          ((EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].MacSecEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Tja1103_GetMiiModeOfEthTrcv(Index)                                               (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].MiiModeOfEthTrcv)
#define EthTrcv_30_Tja1103_GetPhySignalQualityMeanOfEthTrcv(Index)                                  (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].PhySignalQualityMeanOfEthTrcv)
#define EthTrcv_30_Tja1103_GetSoCBaseRegAddrOfEthTrcv(Index)                                        (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].SoCBaseRegAddrOfEthTrcv)
#define EthTrcv_30_Tja1103_IsSoftResetOnInitEnabledOfEthTrcv(Index)                                 ((EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].SoftResetOnInitEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Tja1103_GetSoftResetWaitCyclesOfEthTrcv(Index)                                   (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].SoftResetWaitCyclesOfEthTrcv)
#define EthTrcv_30_Tja1103_GetSpeedOfEthTrcv(Index)                                                 (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].SpeedOfEthTrcv)
#define EthTrcv_30_Tja1103_GetWakeupIdxOfEthTrcv(Index)                                             (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig()[(Index)].WakeupIdxOfEthTrcv)
#define EthTrcv_30_Tja1103_GetDerivativeOfEthTrcvTja1103(Index)                                     (EthTrcv_30_Tja1103_GetEthTrcvTja1103OfPCConfig()[(Index)].DerivativeOfEthTrcvTja1103)
#define EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter()                                         ((*(EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounterOfPCConfig())))
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureCallout(Index)                                  (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureCalloutOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index)                          (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index)                         (EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetPolaritySwapOfPolSwapConfig(Index)                                    (EthTrcv_30_Tja1103_GetPolSwapConfigOfPCConfig()[(Index)].PolaritySwapOfPolSwapConfig)
#define EthTrcv_30_Tja1103_IsSmiIdlePreChargeEnabledOfSmiConfiguration(Index)                       ((EthTrcv_30_Tja1103_GetSmiConfigurationOfPCConfig()[(Index)].SmiIdlePreChargeEnabledOfSmiConfiguration) != FALSE)
#define EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index)                                            (EthTrcv_30_Tja1103_GetTrcvHwAccessibilityOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetTrcvLinkState(Index)                                                  (EthTrcv_30_Tja1103_GetTrcvLinkStateOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetTrcvMode(Index)                                                       (EthTrcv_30_Tja1103_GetTrcvModeOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetRxClkSignalShiftOfTrcvRgmiiConfig(Index)                              (EthTrcv_30_Tja1103_GetTrcvRgmiiConfigOfPCConfig()[(Index)].RxClkSignalShiftOfTrcvRgmiiConfig)
#define EthTrcv_30_Tja1103_GetTxClkSignalShiftOfTrcvRgmiiConfig(Index)                              (EthTrcv_30_Tja1103_GetTrcvRgmiiConfigOfPCConfig()[(Index)].TxClkSignalShiftOfTrcvRgmiiConfig)
#define EthTrcv_30_Tja1103_GetTrcvState(Index)                                                      (EthTrcv_30_Tja1103_GetTrcvStateOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetPreTrcvReadAccessCalloutOfUserAccessCallouts(Index)                   (EthTrcv_30_Tja1103_GetUserAccessCalloutsOfPCConfig()[(Index)].PreTrcvReadAccessCalloutOfUserAccessCallouts)
#define EthTrcv_30_Tja1103_GetPreTrcvWriteAccessCalloutOfUserAccessCallouts(Index)                  (EthTrcv_30_Tja1103_GetUserAccessCalloutsOfPCConfig()[(Index)].PreTrcvWriteAccessCalloutOfUserAccessCallouts)
#define EthTrcv_30_Tja1103_GetPostInitUserCalloutOfUserInitCallouts(Index)                          (EthTrcv_30_Tja1103_GetUserInitCalloutsOfPCConfig()[(Index)].PostInitUserCalloutOfUserInitCallouts)
#define EthTrcv_30_Tja1103_GetPreInitUserCalloutOfUserInitCallouts(Index)                           (EthTrcv_30_Tja1103_GetUserInitCalloutsOfPCConfig()[(Index)].PreInitUserCalloutOfUserInitCallouts)
#define EthTrcv_30_Tja1103_GetIcuChannelOfWakeup(Index)                                             (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].IcuChannelOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupCalloutIdxOfWakeup(Index)                                       (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].WakeupCalloutIdxOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupInspectionTypeOfWakeup(Index)                                   (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].WakeupInspectionTypeOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupMapEndIdxOfWakeup(Index)                                        (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].WakeupMapEndIdxOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupMapStartIdxOfWakeup(Index)                                      (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].WakeupMapStartIdxOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupVerificationCalloutIdxOfWakeup(Index)                           (EthTrcv_30_Tja1103_GetWakeupOfPCConfig()[(Index)].WakeupVerificationCalloutIdxOfWakeup)
#define EthTrcv_30_Tja1103_GetWakeupCallout(Index)                                                  (EthTrcv_30_Tja1103_GetWakeupCalloutOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetEcuMWakeupSourceOfWakeupMap(Index)                                    (EthTrcv_30_Tja1103_GetWakeupMapOfPCConfig()[(Index)].EcuMWakeupSourceOfWakeupMap)
#define EthTrcv_30_Tja1103_GetWakeupReasonOfWakeupMap(Index)                                        (EthTrcv_30_Tja1103_GetWakeupMapOfPCConfig()[(Index)].WakeupReasonOfWakeupMap)
#define EthTrcv_30_Tja1103_GetWakeupMode(Index)                                                     (EthTrcv_30_Tja1103_GetWakeupModeOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index)                                              (EthTrcv_30_Tja1103_GetWakeupReasonFlagsOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetWakeupVerificationCallout(Index)                                      (EthTrcv_30_Tja1103_GetWakeupVerificationCalloutOfPCConfig()[(Index)])
#define EthTrcv_30_Tja1103_GetDrivingStrengthOfXmiiClkIoConfig(Index)                               (EthTrcv_30_Tja1103_GetXmiiClkIoConfigOfPCConfig()[(Index)].DrivingStrengthOfXmiiClkIoConfig)
#define EthTrcv_30_Tja1103_GetSlewRateOfXmiiClkIoConfig(Index)                                      (EthTrcv_30_Tja1103_GetXmiiClkIoConfigOfPCConfig()[(Index)].SlewRateOfXmiiClkIoConfig)
#define EthTrcv_30_Tja1103_GetDrivingStrengthOfXmiiDataIoConfig(Index)                              (EthTrcv_30_Tja1103_GetXmiiDataIoConfigOfPCConfig()[(Index)].DrivingStrengthOfXmiiDataIoConfig)
#define EthTrcv_30_Tja1103_GetSlewRateOfXmiiDataIoConfig(Index)                                     (EthTrcv_30_Tja1103_GetXmiiDataIoConfigOfPCConfig()[(Index)].SlewRateOfXmiiDataIoConfig)
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCGetDeduplicatedDataMacros  EthTrcv_30_Tja1103 Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EthTrcv_30_Tja1103_GetCableDiagLoopCycles()                                                 EthTrcv_30_Tja1103_GetCableDiagLoopCyclesOfPCConfig()
#define EthTrcv_30_Tja1103_IsWakeupUsedOfEthTrcv(Index)                                             (((boolean)(EthTrcv_30_Tja1103_GetWakeupIdxOfEthTrcv(Index) != ETHTRCV_30_TJA1103_NO_WAKEUPIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Tja1103_Wakeup */
#define EthTrcv_30_Tja1103_GetHwAccessLoopCount()                                                   EthTrcv_30_Tja1103_GetHwAccessLoopCountOfPCConfig()
#define EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceLimiter()                               EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceLimiterOfPCConfig()
#define EthTrcv_30_Tja1103_GetHwAccessMonitorLoopLimiter()                                          EthTrcv_30_Tja1103_GetHwAccessMonitorLoopLimiterOfPCConfig()
#define EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceLimiter()                              EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()
#define EthTrcv_30_Tja1103_GetMaxPhySignalQualityMean()                                             EthTrcv_30_Tja1103_GetMaxPhySignalQualityMeanOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfAccessEntityFcts()                                              EthTrcv_30_Tja1103_GetSizeOfAccessEntityFctsOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfCableDiagnosticState()                                          EthTrcv_30_Tja1103_GetSizeOfCableDiagnosticStateOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfEthTrcv()                                                       EthTrcv_30_Tja1103_GetSizeOfEthTrcvOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfEthTrcvTja1103()                                                EthTrcv_30_Tja1103_GetSizeOfEthTrcvTja1103OfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureCallout()                                 EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureCalloutOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureDebounceCounter()                         EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorRecoveryDebounceCounter()                        EthTrcv_30_Tja1103_GetSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfPolSwapConfig()                                                 EthTrcv_30_Tja1103_GetSizeOfPolSwapConfigOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfSmiConfiguration()                                              EthTrcv_30_Tja1103_GetSizeOfSmiConfigurationOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfTrcvHwAccessibility()                                           EthTrcv_30_Tja1103_GetSizeOfTrcvHwAccessibilityOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfTrcvLinkState()                                                 EthTrcv_30_Tja1103_GetSizeOfTrcvLinkStateOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfTrcvMode()                                                      EthTrcv_30_Tja1103_GetSizeOfTrcvModeOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfTrcvRgmiiConfig()                                               EthTrcv_30_Tja1103_GetSizeOfTrcvRgmiiConfigOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfTrcvState()                                                     EthTrcv_30_Tja1103_GetSizeOfTrcvStateOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfUserAccessCallouts()                                            EthTrcv_30_Tja1103_GetSizeOfUserAccessCalloutsOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfUserInitCallouts()                                              EthTrcv_30_Tja1103_GetSizeOfUserInitCalloutsOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeup()                                                        EthTrcv_30_Tja1103_GetSizeOfWakeupOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeupCallout()                                                 EthTrcv_30_Tja1103_GetSizeOfWakeupCalloutOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeupMap()                                                     EthTrcv_30_Tja1103_GetSizeOfWakeupMapOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeupMode()                                                    EthTrcv_30_Tja1103_GetSizeOfWakeupModeOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeupReasonFlags()                                             EthTrcv_30_Tja1103_GetSizeOfWakeupReasonFlagsOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfWakeupVerificationCallout()                                     EthTrcv_30_Tja1103_GetSizeOfWakeupVerificationCalloutOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfXmiiClkIoConfig()                                               EthTrcv_30_Tja1103_GetSizeOfXmiiClkIoConfigOfPCConfig()
#define EthTrcv_30_Tja1103_GetSizeOfXmiiDataIoConfig()                                              EthTrcv_30_Tja1103_GetSizeOfXmiiDataIoConfigOfPCConfig()
#define EthTrcv_30_Tja1103_IsWakeupCalloutUsedOfWakeup(Index)                                       (((boolean)(EthTrcv_30_Tja1103_GetWakeupCalloutIdxOfWakeup(Index) != ETHTRCV_30_TJA1103_NO_WAKEUPCALLOUTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Tja1103_WakeupCallout */
#define EthTrcv_30_Tja1103_IsWakeupMapUsedOfWakeup(Index)                                           (((boolean)(EthTrcv_30_Tja1103_GetWakeupMapStartIdxOfWakeup(Index) != ETHTRCV_30_TJA1103_NO_WAKEUPMAPSTARTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthTrcv_30_Tja1103_WakeupMap */
#define EthTrcv_30_Tja1103_IsWakeupVerificationCalloutUsedOfWakeup(Index)                           (((boolean)(EthTrcv_30_Tja1103_GetWakeupVerificationCalloutIdxOfWakeup(Index) != ETHTRCV_30_TJA1103_NO_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Tja1103_WakeupVerificationCallout */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCSetDataMacros  EthTrcv_30_Tja1103 Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EthTrcv_30_Tja1103_SetCableDiagnosticState(Index, Value)                                    EthTrcv_30_Tja1103_GetCableDiagnosticStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetHwAccessMonitorCycleCounter(Value)                                    (*(EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounterOfPCConfig())) = (Value)
#define EthTrcv_30_Tja1103_SetHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Tja1103_GetTrcvHwAccessibilityOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetTrcvLinkState(Index, Value)                                           EthTrcv_30_Tja1103_GetTrcvLinkStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetTrcvMode(Index, Value)                                                EthTrcv_30_Tja1103_GetTrcvModeOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetTrcvState(Index, Value)                                               EthTrcv_30_Tja1103_GetTrcvStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetWakeupMode(Index, Value)                                              EthTrcv_30_Tja1103_GetWakeupModeOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Tja1103_SetWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Tja1103_GetWakeupReasonFlagsOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCGetAddressOfDataMacros  EthTrcv_30_Tja1103 Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define EthTrcv_30_Tja1103_GetAddrCableDiagnosticState(Index)                                       (&EthTrcv_30_Tja1103_GetCableDiagnosticState(Index))
#define EthTrcv_30_Tja1103_GetAddrHwAccessMonitorCycleCounter()                                     (&EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter())
#define EthTrcv_30_Tja1103_GetAddrHwAccessMonitorFailureDebounceCounter(Index)                      (&EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index))
#define EthTrcv_30_Tja1103_GetAddrHwAccessMonitorRecoveryDebounceCounter(Index)                     (&EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index))
#define EthTrcv_30_Tja1103_GetAddrTrcvHwAccessibility(Index)                                        (&EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index))
#define EthTrcv_30_Tja1103_GetAddrTrcvLinkState(Index)                                              (&EthTrcv_30_Tja1103_GetTrcvLinkState(Index))
#define EthTrcv_30_Tja1103_GetAddrTrcvMode(Index)                                                   (&EthTrcv_30_Tja1103_GetTrcvMode(Index))
#define EthTrcv_30_Tja1103_GetAddrTrcvState(Index)                                                  (&EthTrcv_30_Tja1103_GetTrcvState(Index))
#define EthTrcv_30_Tja1103_GetAddrWakeupMode(Index)                                                 (&EthTrcv_30_Tja1103_GetWakeupMode(Index))
#define EthTrcv_30_Tja1103_GetAddrWakeupReasonFlags(Index)                                          (&EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index))
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCHasMacros  EthTrcv_30_Tja1103 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EthTrcv_30_Tja1103_HasAccessEntityFcts()                                                    (EthTrcv_30_Tja1103_GetAccessEntityFctsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasReadTrcvRegOfAccessEntityFcts()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWriteTrcvRegOfAccessEntityFcts()                                      (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasCableDiagLoopCycles()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasCableDiagnosticState()                                                (EthTrcv_30_Tja1103_GetCableDiagnosticStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasEthTrcv()                                                             (EthTrcv_30_Tja1103_GetEthTrcvOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasAccessEntityFctsIdxOfEthTrcv()                                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasAccessEntitySnvOfEthTrcv()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasAddressingIdxOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasAutoNegEnabledOfEthTrcv()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasBasicCtrlRegValOfEthTrcv()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasConnectionNegOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasDemEAccessEventIdOfEthTrcv()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorEnabledOfEthTrcv()                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasMacSecEnabledOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasMiiModeOfEthTrcv()                                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPhySignalQualityMeanOfEthTrcv()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSoCBaseRegAddrOfEthTrcv()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSoftResetOnInitEnabledOfEthTrcv()                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSoftResetWaitCyclesOfEthTrcv()                                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSpeedOfEthTrcv()                                                      (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupIdxOfEthTrcv()                                                  (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupUsedOfEthTrcv()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasEthTrcvTja1103()                                                      (EthTrcv_30_Tja1103_GetEthTrcvTja1103OfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasDerivativeOfEthTrcvTja1103()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessLoopCount()                                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorCycleCounter()                                         (EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureCallout()                                       (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureDebounceCounter()                               (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureDebounceLimiter()                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorLoopLimiter()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorRecoveryDebounceCounter()                              (EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorRecoveryDebounceLimiter()                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasMaxPhySignalQualityMean()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPolSwapConfig()                                                       (EthTrcv_30_Tja1103_GetPolSwapConfigOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasPolaritySwapOfPolSwapConfig()                                         (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfAccessEntityFcts()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfCableDiagnosticState()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfEthTrcv()                                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfEthTrcvTja1103()                                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorFailureCallout()                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorFailureDebounceCounter()                         (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorRecoveryDebounceCounter()                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfPolSwapConfig()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfSmiConfiguration()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvHwAccessibility()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvLinkState()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvMode()                                                      (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvRgmiiConfig()                                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvState()                                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfUserAccessCallouts()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfUserInitCallouts()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeup()                                                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupCallout()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupMap()                                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupMode()                                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupReasonFlags()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupVerificationCallout()                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfXmiiClkIoConfig()                                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfXmiiDataIoConfig()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSmiConfiguration()                                                    (EthTrcv_30_Tja1103_GetSmiConfigurationOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasSmiIdlePreChargeEnabledOfSmiConfiguration()                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvHwAccessibility()                                                 (EthTrcv_30_Tja1103_GetTrcvHwAccessibilityOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasTrcvLinkState()                                                       (EthTrcv_30_Tja1103_GetTrcvLinkStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasTrcvMode()                                                            (EthTrcv_30_Tja1103_GetTrcvModeOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasTrcvRgmiiConfig()                                                     (EthTrcv_30_Tja1103_GetTrcvRgmiiConfigOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasRxClkSignalShiftOfTrcvRgmiiConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTxClkSignalShiftOfTrcvRgmiiConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvState()                                                           (EthTrcv_30_Tja1103_GetTrcvStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasUserAccessCallouts()                                                  (EthTrcv_30_Tja1103_GetUserAccessCalloutsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasPreTrcvReadAccessCalloutOfUserAccessCallouts()                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPreTrcvWriteAccessCalloutOfUserAccessCallouts()                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasUserInitCallouts()                                                    (EthTrcv_30_Tja1103_GetUserInitCalloutsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasPostInitUserCalloutOfUserInitCallouts()                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPreInitUserCalloutOfUserInitCallouts()                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeup()                                                              (EthTrcv_30_Tja1103_GetWakeupOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasIcuChannelOfWakeup()                                                  (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupCalloutIdxOfWakeup()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupCalloutUsedOfWakeup()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupInspectionTypeOfWakeup()                                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupMapEndIdxOfWakeup()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupMapStartIdxOfWakeup()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupMapUsedOfWakeup()                                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupVerificationCalloutIdxOfWakeup()                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupVerificationCalloutUsedOfWakeup()                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupCallout()                                                       (EthTrcv_30_Tja1103_GetWakeupCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasWakeupMap()                                                           (EthTrcv_30_Tja1103_GetWakeupMapOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasEcuMWakeupSourceOfWakeupMap()                                         (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupReasonOfWakeupMap()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupMode()                                                          (EthTrcv_30_Tja1103_GetWakeupModeOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasWakeupReasonFlags()                                                   (EthTrcv_30_Tja1103_GetWakeupReasonFlagsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasWakeupVerificationCallout()                                           (EthTrcv_30_Tja1103_GetWakeupVerificationCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasXmiiClkIoConfig()                                                     (EthTrcv_30_Tja1103_GetXmiiClkIoConfigOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasDrivingStrengthOfXmiiClkIoConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSlewRateOfXmiiClkIoConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasXmiiDataIoConfig()                                                    (EthTrcv_30_Tja1103_GetXmiiDataIoConfigOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Tja1103_HasDrivingStrengthOfXmiiDataIoConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSlewRateOfXmiiDataIoConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPCConfig()                                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasAccessEntityFctsOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasCableDiagLoopCyclesOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasCableDiagnosticStateOfPCConfig()                                      (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasEthTrcvOfPCConfig()                                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasEthTrcvTja1103OfPCConfig()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessLoopCountOfPCConfig()                                         (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorCycleCounterOfPCConfig()                               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureCalloutOfPCConfig()                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureDebounceCounterOfPCConfig()                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorFailureDebounceLimiterOfPCConfig()                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorLoopLimiterOfPCConfig()                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorRecoveryDebounceCounterOfPCConfig()                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasMaxPhySignalQualityMeanOfPCConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasPolSwapConfigOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfAccessEntityFctsOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfCableDiagnosticStateOfPCConfig()                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfEthTrcvOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfEthTrcvTja1103OfPCConfig()                                      (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorFailureCalloutOfPCConfig()                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()               (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfPolSwapConfigOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfSmiConfigurationOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvHwAccessibilityOfPCConfig()                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvLinkStateOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvModeOfPCConfig()                                            (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvRgmiiConfigOfPCConfig()                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfTrcvStateOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfUserAccessCalloutsOfPCConfig()                                  (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfUserInitCalloutsOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupCalloutOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupMapOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupModeOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupOfPCConfig()                                              (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupReasonFlagsOfPCConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfWakeupVerificationCalloutOfPCConfig()                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfXmiiClkIoConfigOfPCConfig()                                     (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSizeOfXmiiDataIoConfigOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasSmiConfigurationOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvHwAccessibilityOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvLinkStateOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvModeOfPCConfig()                                                  (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvRgmiiConfigOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasTrcvStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasUserAccessCalloutsOfPCConfig()                                        (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasUserInitCalloutsOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupCalloutOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupMapOfPCConfig()                                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupModeOfPCConfig()                                                (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupOfPCConfig()                                                    (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupReasonFlagsOfPCConfig()                                         (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasWakeupVerificationCalloutOfPCConfig()                                 (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasXmiiClkIoConfigOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Tja1103_HasXmiiDataIoConfigOfPCConfig()                                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCIncrementDataMacros  EthTrcv_30_Tja1103 Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Tja1103_IncCableDiagnosticState(Index)                                           EthTrcv_30_Tja1103_GetCableDiagnosticState(Index)++
#define EthTrcv_30_Tja1103_IncHwAccessMonitorCycleCounter()                                         EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter()++
#define EthTrcv_30_Tja1103_IncHwAccessMonitorFailureDebounceCounter(Index)                          EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index)++
#define EthTrcv_30_Tja1103_IncHwAccessMonitorRecoveryDebounceCounter(Index)                         EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index)++
#define EthTrcv_30_Tja1103_IncTrcvHwAccessibility(Index)                                            EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index)++
#define EthTrcv_30_Tja1103_IncTrcvLinkState(Index)                                                  EthTrcv_30_Tja1103_GetTrcvLinkState(Index)++
#define EthTrcv_30_Tja1103_IncTrcvMode(Index)                                                       EthTrcv_30_Tja1103_GetTrcvMode(Index)++
#define EthTrcv_30_Tja1103_IncTrcvState(Index)                                                      EthTrcv_30_Tja1103_GetTrcvState(Index)++
#define EthTrcv_30_Tja1103_IncWakeupMode(Index)                                                     EthTrcv_30_Tja1103_GetWakeupMode(Index)++
#define EthTrcv_30_Tja1103_IncWakeupReasonFlags(Index)                                              EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCDecrementDataMacros  EthTrcv_30_Tja1103 Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Tja1103_DecCableDiagnosticState(Index)                                           EthTrcv_30_Tja1103_GetCableDiagnosticState(Index)--
#define EthTrcv_30_Tja1103_DecHwAccessMonitorCycleCounter()                                         EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter()--
#define EthTrcv_30_Tja1103_DecHwAccessMonitorFailureDebounceCounter(Index)                          EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index)--
#define EthTrcv_30_Tja1103_DecHwAccessMonitorRecoveryDebounceCounter(Index)                         EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index)--
#define EthTrcv_30_Tja1103_DecTrcvHwAccessibility(Index)                                            EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index)--
#define EthTrcv_30_Tja1103_DecTrcvLinkState(Index)                                                  EthTrcv_30_Tja1103_GetTrcvLinkState(Index)--
#define EthTrcv_30_Tja1103_DecTrcvMode(Index)                                                       EthTrcv_30_Tja1103_GetTrcvMode(Index)--
#define EthTrcv_30_Tja1103_DecTrcvState(Index)                                                      EthTrcv_30_Tja1103_GetTrcvState(Index)--
#define EthTrcv_30_Tja1103_DecWakeupMode(Index)                                                     EthTrcv_30_Tja1103_GetWakeupMode(Index)--
#define EthTrcv_30_Tja1103_DecWakeupReasonFlags(Index)                                              EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCAddDataMacros  EthTrcv_30_Tja1103 Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Tja1103_AddCableDiagnosticState(Index, Value)                                    EthTrcv_30_Tja1103_SetCableDiagnosticState(Index, (EthTrcv_30_Tja1103_GetCableDiagnosticState(Index) + Value))
#define EthTrcv_30_Tja1103_AddHwAccessMonitorCycleCounter(Value)                                    EthTrcv_30_Tja1103_SetHwAccessMonitorCycleCounter((EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter() + Value))
#define EthTrcv_30_Tja1103_AddHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Tja1103_SetHwAccessMonitorFailureDebounceCounter(Index, (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index) + Value))
#define EthTrcv_30_Tja1103_AddHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Tja1103_SetHwAccessMonitorRecoveryDebounceCounter(Index, (EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index) + Value))
#define EthTrcv_30_Tja1103_AddTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Tja1103_SetTrcvHwAccessibility(Index, (EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index) + Value))
#define EthTrcv_30_Tja1103_AddTrcvLinkState(Index, Value)                                           EthTrcv_30_Tja1103_SetTrcvLinkState(Index, (EthTrcv_30_Tja1103_GetTrcvLinkState(Index) + Value))
#define EthTrcv_30_Tja1103_AddTrcvMode(Index, Value)                                                EthTrcv_30_Tja1103_SetTrcvMode(Index, (EthTrcv_30_Tja1103_GetTrcvMode(Index) + Value))
#define EthTrcv_30_Tja1103_AddTrcvState(Index, Value)                                               EthTrcv_30_Tja1103_SetTrcvState(Index, (EthTrcv_30_Tja1103_GetTrcvState(Index) + Value))
#define EthTrcv_30_Tja1103_AddWakeupMode(Index, Value)                                              EthTrcv_30_Tja1103_SetWakeupMode(Index, (EthTrcv_30_Tja1103_GetWakeupMode(Index) + Value))
#define EthTrcv_30_Tja1103_AddWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Tja1103_SetWakeupReasonFlags(Index, (EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCSubstractDataMacros  EthTrcv_30_Tja1103 Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Tja1103_SubCableDiagnosticState(Index, Value)                                    EthTrcv_30_Tja1103_SetCableDiagnosticState(Index, (EthTrcv_30_Tja1103_GetCableDiagnosticState(Index) - Value))
#define EthTrcv_30_Tja1103_SubHwAccessMonitorCycleCounter(Value)                                    EthTrcv_30_Tja1103_SetHwAccessMonitorCycleCounter((EthTrcv_30_Tja1103_GetHwAccessMonitorCycleCounter() - Value))
#define EthTrcv_30_Tja1103_SubHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Tja1103_SetHwAccessMonitorFailureDebounceCounter(Index, (EthTrcv_30_Tja1103_GetHwAccessMonitorFailureDebounceCounter(Index) - Value))
#define EthTrcv_30_Tja1103_SubHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Tja1103_SetHwAccessMonitorRecoveryDebounceCounter(Index, (EthTrcv_30_Tja1103_GetHwAccessMonitorRecoveryDebounceCounter(Index) - Value))
#define EthTrcv_30_Tja1103_SubTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Tja1103_SetTrcvHwAccessibility(Index, (EthTrcv_30_Tja1103_GetTrcvHwAccessibility(Index) - Value))
#define EthTrcv_30_Tja1103_SubTrcvLinkState(Index, Value)                                           EthTrcv_30_Tja1103_SetTrcvLinkState(Index, (EthTrcv_30_Tja1103_GetTrcvLinkState(Index) - Value))
#define EthTrcv_30_Tja1103_SubTrcvMode(Index, Value)                                                EthTrcv_30_Tja1103_SetTrcvMode(Index, (EthTrcv_30_Tja1103_GetTrcvMode(Index) - Value))
#define EthTrcv_30_Tja1103_SubTrcvState(Index, Value)                                               EthTrcv_30_Tja1103_SetTrcvState(Index, (EthTrcv_30_Tja1103_GetTrcvState(Index) - Value))
#define EthTrcv_30_Tja1103_SubWakeupMode(Index, Value)                                              EthTrcv_30_Tja1103_SetWakeupMode(Index, (EthTrcv_30_Tja1103_GetWakeupMode(Index) - Value))
#define EthTrcv_30_Tja1103_SubWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Tja1103_SetWakeupReasonFlags(Index, (EthTrcv_30_Tja1103_GetWakeupReasonFlags(Index) - Value))
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

# if !defined(ETHTRCV_30_TJA1103_UNIT_TEST)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

# endif /* ETHTRCV_30_TJA1103_UNIT_TEST */
#endif /* ETHTRCV_30_TJA1103_LCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1103_Lcfg.h
 *********************************************************************************************************************/
 
