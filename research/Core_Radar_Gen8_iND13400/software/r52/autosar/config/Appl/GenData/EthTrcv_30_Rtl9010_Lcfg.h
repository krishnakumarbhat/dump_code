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
 *            Module: EthTrcv_30_Rtl9010
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Rtl9010_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:14
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
 * [Warning] ETHIF01416 - Hardware module SNV configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] DefinitionRef: /[ANY]/EthTrcv/EthTrcvGeneral/EthTrcvIndexs must be configured to a value in range from 0 to 2 without gaps. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvGeneral[0:EthTrcvIndex](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvGeneral/EthTrcvIndex)
 * /ActiveEcuC/EthTrcv_NXP/EthTrcvGeneral[0:EthTrcvIndex](value=0) (DefRef: /MICROSAR/EthTrcv_30_Tja1103/EthTrcv/EthTrcvGeneral/EthTrcvIndex)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#if !defined (ETHTRCV_30_RTL9010_LCFG_H)
# define ETHTRCV_30_RTL9010_LCFG_H
/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
# include "EthTrcv_30_Rtl9010_GenTypes.h"

# if !defined (ETHTRCV_30_RTL9010_LOCAL_INLINE)
#  define ETHTRCV_30_RTL9010_LOCAL_INLINE LOCAL_INLINE
# endif
/**********************************************************************************************************************
 *  RTM MEASUREMENT POINT MACROS
 *********************************************************************************************************************/

/* PRQA S 0342 2 */ /* MD_MSR_Rule20.10_0342 */
# define EthTrcv_30_Rtl9010_Rtm_Start(Type) \
  Rtm_Start(RtmConf_RtmMeasurementPoint_EthTrcv_30_Rtl9010_##Type)

/* PRQA S 0342 2 */ /* MD_MSR_Rule20.10_0342 */
# define EthTrcv_30_Rtl9010_Rtm_Stop(Type) \
  Rtm_Stop(RtmConf_RtmMeasurementPoint_EthTrcv_30_Rtl9010_##Type)

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_ConfigDataPtr
  \brief  Points to the currently active configuration for EthTrcv_30_Rtl9010
  \details
  Pointer is intialized during EthTrcv_30_Rtl9010_Init() and holds the active configuration for EthTrcv_30_Rtl9010
  were all configuration data is retrieved from during runtime.
*/ 
# define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"
extern P2CONST(EthTrcv_30_Rtl9010_ConfigType, ETHTRCV_30_RTL9010_VAR_NOINIT, ETHTRCV_30_RTL9010_INIT_DATA) EthTrcv_30_Rtl9010_ConfigDataPtr;
# define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
  \defgroup  EthTrcv_30_Rtl9010PCGetRootDataMacros  EthTrcv_30_Rtl9010 Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define EthTrcv_30_Rtl9010_GetAccessEntityFctsOfPCConfig()                                          EthTrcv_30_Rtl9010_ConfigDataPtr->AccessEntityFctsOfPCConfig
#define EthTrcv_30_Rtl9010_GetCableDiagLoopCyclesOfPCConfig()                                       EthTrcv_30_Rtl9010_ConfigDataPtr->CableDiagLoopCyclesOfPCConfig
#define EthTrcv_30_Rtl9010_GetCableDiagnosticStateOfPCConfig()                                      EthTrcv_30_Rtl9010_ConfigDataPtr->CableDiagnosticStateOfPCConfig
#define EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()                                                   EthTrcv_30_Rtl9010_ConfigDataPtr->EthTrcvOfPCConfig
#define EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig()                                EthTrcv_30_Rtl9010_ConfigDataPtr->EthTrcvRtl9010AxErrataHdlrOfPCConfig
#define EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()                                            EthTrcv_30_Rtl9010_ConfigDataPtr->EthTrcvRtl9010OfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessLoopCountOfPCConfig()                                         EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessLoopCountOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounterOfPCConfig()                               EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorCycleCounterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureCalloutOfPCConfig()                             EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorFailureCalloutOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()                     EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorFailureDebounceCounterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceLimiterOfPCConfig()                     EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorFailureDebounceLimiterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorLoopLimiterOfPCConfig()                                EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorLoopLimiterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()                    EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorRecoveryDebounceCounterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()                    EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessMonitorRecoveryDebounceLimiterOfPCConfig
#define EthTrcv_30_Rtl9010_GetHwAccessStateOfPCConfig()                                             EthTrcv_30_Rtl9010_ConfigDataPtr->HwAccessStateOfPCConfig
#define EthTrcv_30_Rtl9010_GetMaxPhySignalQualityMeanOfPCConfig()                                   EthTrcv_30_Rtl9010_ConfigDataPtr->MaxPhySignalQualityMeanOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfAccessEntityFctsOfPCConfig()                                    EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfAccessEntityFctsOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()                                             EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfEthTrcvOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010AxErrataHdlrOfPCConfig()                          EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfEthTrcvRtl9010AxErrataHdlrOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010OfPCConfig()                                      EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfEthTrcvRtl9010OfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureCalloutOfPCConfig()                       EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfHwAccessMonitorFailureCalloutOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfUserAccessCalloutsOfPCConfig()                                  EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfUserAccessCalloutsOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfUserInitCalloutsOfPCConfig()                                    EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfUserInitCalloutsOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupCalloutOfPCConfig()                                       EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfWakeupCalloutOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupMapOfPCConfig()                                           EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfWakeupMapOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupOfPCConfig()                                              EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfWakeupOfPCConfig
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupVerificationCalloutOfPCConfig()                           EthTrcv_30_Rtl9010_ConfigDataPtr->SizeOfWakeupVerificationCalloutOfPCConfig
#define EthTrcv_30_Rtl9010_GetTrcvHwAccessibilityOfPCConfig()                                       EthTrcv_30_Rtl9010_ConfigDataPtr->TrcvHwAccessibilityOfPCConfig
#define EthTrcv_30_Rtl9010_GetTrcvLinkStateOfPCConfig()                                             EthTrcv_30_Rtl9010_ConfigDataPtr->TrcvLinkStateOfPCConfig
#define EthTrcv_30_Rtl9010_GetTrcvModeOfPCConfig()                                                  EthTrcv_30_Rtl9010_ConfigDataPtr->TrcvModeOfPCConfig
#define EthTrcv_30_Rtl9010_GetTrcvStateOfPCConfig()                                                 EthTrcv_30_Rtl9010_ConfigDataPtr->TrcvStateOfPCConfig
#define EthTrcv_30_Rtl9010_GetUserAccessCalloutsOfPCConfig()                                        EthTrcv_30_Rtl9010_ConfigDataPtr->UserAccessCalloutsOfPCConfig
#define EthTrcv_30_Rtl9010_GetUserInitCalloutsOfPCConfig()                                          EthTrcv_30_Rtl9010_ConfigDataPtr->UserInitCalloutsOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupCalloutOfPCConfig()                                             EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupCalloutOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupMapOfPCConfig()                                                 EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupMapOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupModeOfPCConfig()                                                EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupModeOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()                                                    EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupReasonFlagsOfPCConfig()                                         EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupReasonFlagsOfPCConfig
#define EthTrcv_30_Rtl9010_GetWakeupVerificationCalloutOfPCConfig()                                 EthTrcv_30_Rtl9010_ConfigDataPtr->WakeupVerificationCalloutOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCGetDuplicatedRootDataMacros  EthTrcv_30_Rtl9010 Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define EthTrcv_30_Rtl9010_GetSizeOfCableDiagnosticStateOfPCConfig()                                EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_CableDiagnosticState */
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()               EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter */
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()              EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter */
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessStateOfPCConfig()                                       EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010OfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessState */
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvHwAccessibilityOfPCConfig()                                 EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_TrcvHwAccessibility */
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvLinkStateOfPCConfig()                                       EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_TrcvLinkState */
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvModeOfPCConfig()                                            EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_TrcvMode */
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvStateOfPCConfig()                                           EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_TrcvState */
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupModeOfPCConfig()                                          EthTrcv_30_Rtl9010_GetSizeOfWakeupOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupMode */
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupReasonFlagsOfPCConfig()                                   EthTrcv_30_Rtl9010_GetSizeOfWakeupOfPCConfig()  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupReasonFlags */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCGetDataMacros  EthTrcv_30_Rtl9010 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EthTrcv_30_Rtl9010_GetReadTrcvRegOfAccessEntityFcts(Index)                                  (EthTrcv_30_Rtl9010_GetAccessEntityFctsOfPCConfig()[(Index)].ReadTrcvRegOfAccessEntityFcts)
#define EthTrcv_30_Rtl9010_GetWriteTrcvRegOfAccessEntityFcts(Index)                                 (EthTrcv_30_Rtl9010_GetAccessEntityFctsOfPCConfig()[(Index)].WriteTrcvRegOfAccessEntityFcts)
#define EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index)                                           (EthTrcv_30_Rtl9010_GetCableDiagnosticStateOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetAccessEntityFctsIdxOfEthTrcv(Index)                                   (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].AccessEntityFctsIdxOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetAccessEntitySnvOfEthTrcv(Index)                                       (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].AccessEntitySnvOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetAddressingIdxOfEthTrcv(Index)                                         (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].AddressingIdxOfEthTrcv)
#define EthTrcv_30_Rtl9010_IsAutoNegEnabledOfEthTrcv(Index)                                         ((EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].AutoNegEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Rtl9010_GetBasicCtrlRegValOfEthTrcv(Index)                                       (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].BasicCtrlRegValOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetConnectionNegOfEthTrcv(Index)                                         (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].ConnectionNegOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetDemEAccessEventIdOfEthTrcv(Index)                                     (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].DemEAccessEventIdOfEthTrcv)
#define EthTrcv_30_Rtl9010_IsHwAccessMonitorEnabledOfEthTrcv(Index)                                 ((EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].HwAccessMonitorEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Rtl9010_IsMacSecEnabledOfEthTrcv(Index)                                          ((EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].MacSecEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Rtl9010_GetMiiModeOfEthTrcv(Index)                                               (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].MiiModeOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetPhySignalQualityMeanOfEthTrcv(Index)                                  (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].PhySignalQualityMeanOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetSoCBaseRegAddrOfEthTrcv(Index)                                        (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].SoCBaseRegAddrOfEthTrcv)
#define EthTrcv_30_Rtl9010_IsSoftResetOnInitEnabledOfEthTrcv(Index)                                 ((EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].SoftResetOnInitEnabledOfEthTrcv) != FALSE)
#define EthTrcv_30_Rtl9010_GetSoftResetWaitCyclesOfEthTrcv(Index)                                   (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].SoftResetWaitCyclesOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetSpeedOfEthTrcv(Index)                                                 (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].SpeedOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetWakeupIdxOfEthTrcv(Index)                                             (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig()[(Index)].WakeupIdxOfEthTrcv)
#define EthTrcv_30_Rtl9010_GetDerivativeOfEthTrcvRtl9010(Index)                                     (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].DerivativeOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetDrivingStrengthOfEthTrcvRtl9010(Index)                                (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].DrivingStrengthOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetIOPowerOfEthTrcvRtl9010(Index)                                        (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].IOPowerOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetRxcDelayEnableOfEthTrcvRtl9010(Index)                                 (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].RxcDelayEnableOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetRxcDelayValueOfEthTrcvRtl9010(Index)                                  (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].RxcDelayValueOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetSoftResetWaitCyclesOfEthTrcvRtl9010(Index)                            (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].SoftResetWaitCyclesOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetTxcDelayEnableOfEthTrcvRtl9010(Index)                                 (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].TxcDelayEnableOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_GetTxcDelayValueOfEthTrcvRtl9010(Index)                                  (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig()[(Index)].TxcDelayValueOfEthTrcvRtl9010)
#define EthTrcv_30_Rtl9010_IsErratum1ActiveOfEthTrcvRtl9010AxErrataHdlr(Index)                      ((EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig()[(Index)].Erratum1ActiveOfEthTrcvRtl9010AxErrataHdlr) != FALSE)
#define EthTrcv_30_Rtl9010_IsErratum2ActiveOfEthTrcvRtl9010AxErrataHdlr(Index)                      ((EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig()[(Index)].Erratum2ActiveOfEthTrcvRtl9010AxErrataHdlr) != FALSE)
#define EthTrcv_30_Rtl9010_IsErratum3ActiveOfEthTrcvRtl9010AxErrataHdlr(Index)                      ((EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig()[(Index)].Erratum3ActiveOfEthTrcvRtl9010AxErrataHdlr) != FALSE)
#define EthTrcv_30_Rtl9010_IsErratum4ActiveOfEthTrcvRtl9010AxErrataHdlr(Index)                      ((EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig()[(Index)].Erratum4ActiveOfEthTrcvRtl9010AxErrataHdlr) != FALSE)
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter()                                         ((*(EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounterOfPCConfig())))
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureCallout(Index)                                  (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureCalloutOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index)                          (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index)                         (EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetHwAccessState(Index)                                                  (EthTrcv_30_Rtl9010_GetHwAccessStateOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index)                                            (EthTrcv_30_Rtl9010_GetTrcvHwAccessibilityOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetTrcvLinkState(Index)                                                  (EthTrcv_30_Rtl9010_GetTrcvLinkStateOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetTrcvMode(Index)                                                       (EthTrcv_30_Rtl9010_GetTrcvModeOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetTrcvState(Index)                                                      (EthTrcv_30_Rtl9010_GetTrcvStateOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetPreTrcvReadAccessCalloutOfUserAccessCallouts(Index)                   (EthTrcv_30_Rtl9010_GetUserAccessCalloutsOfPCConfig()[(Index)].PreTrcvReadAccessCalloutOfUserAccessCallouts)
#define EthTrcv_30_Rtl9010_GetPreTrcvWriteAccessCalloutOfUserAccessCallouts(Index)                  (EthTrcv_30_Rtl9010_GetUserAccessCalloutsOfPCConfig()[(Index)].PreTrcvWriteAccessCalloutOfUserAccessCallouts)
#define EthTrcv_30_Rtl9010_GetPostInitUserCalloutOfUserInitCallouts(Index)                          (EthTrcv_30_Rtl9010_GetUserInitCalloutsOfPCConfig()[(Index)].PostInitUserCalloutOfUserInitCallouts)
#define EthTrcv_30_Rtl9010_GetPreInitUserCalloutOfUserInitCallouts(Index)                           (EthTrcv_30_Rtl9010_GetUserInitCalloutsOfPCConfig()[(Index)].PreInitUserCalloutOfUserInitCallouts)
#define EthTrcv_30_Rtl9010_GetIcuChannelOfWakeup(Index)                                             (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].IcuChannelOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupCalloutIdxOfWakeup(Index)                                       (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].WakeupCalloutIdxOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupInspectionTypeOfWakeup(Index)                                   (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].WakeupInspectionTypeOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupMapEndIdxOfWakeup(Index)                                        (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].WakeupMapEndIdxOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupMapStartIdxOfWakeup(Index)                                      (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].WakeupMapStartIdxOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupVerificationCalloutIdxOfWakeup(Index)                           (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig()[(Index)].WakeupVerificationCalloutIdxOfWakeup)
#define EthTrcv_30_Rtl9010_GetWakeupCallout(Index)                                                  (EthTrcv_30_Rtl9010_GetWakeupCalloutOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetEcuMWakeupSourceOfWakeupMap(Index)                                    (EthTrcv_30_Rtl9010_GetWakeupMapOfPCConfig()[(Index)].EcuMWakeupSourceOfWakeupMap)
#define EthTrcv_30_Rtl9010_GetWakeupReasonOfWakeupMap(Index)                                        (EthTrcv_30_Rtl9010_GetWakeupMapOfPCConfig()[(Index)].WakeupReasonOfWakeupMap)
#define EthTrcv_30_Rtl9010_GetWakeupMode(Index)                                                     (EthTrcv_30_Rtl9010_GetWakeupModeOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index)                                              (EthTrcv_30_Rtl9010_GetWakeupReasonFlagsOfPCConfig()[(Index)])
#define EthTrcv_30_Rtl9010_GetWakeupVerificationCallout(Index)                                      (EthTrcv_30_Rtl9010_GetWakeupVerificationCalloutOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCGetDeduplicatedDataMacros  EthTrcv_30_Rtl9010 Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EthTrcv_30_Rtl9010_GetCableDiagLoopCycles()                                                 EthTrcv_30_Rtl9010_GetCableDiagLoopCyclesOfPCConfig()
#define EthTrcv_30_Rtl9010_IsWakeupUsedOfEthTrcv(Index)                                             (((boolean)(EthTrcv_30_Rtl9010_GetWakeupIdxOfEthTrcv(Index) != ETHTRCV_30_RTL9010_NO_WAKEUPIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Rtl9010_Wakeup */
#define EthTrcv_30_Rtl9010_GetHwAccessLoopCount()                                                   EthTrcv_30_Rtl9010_GetHwAccessLoopCountOfPCConfig()
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceLimiter()                               EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceLimiterOfPCConfig()
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorLoopLimiter()                                          EthTrcv_30_Rtl9010_GetHwAccessMonitorLoopLimiterOfPCConfig()
#define EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceLimiter()                              EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()
#define EthTrcv_30_Rtl9010_GetMaxPhySignalQualityMean()                                             EthTrcv_30_Rtl9010_GetMaxPhySignalQualityMeanOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfAccessEntityFcts()                                              EthTrcv_30_Rtl9010_GetSizeOfAccessEntityFctsOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfCableDiagnosticState()                                          EthTrcv_30_Rtl9010_GetSizeOfCableDiagnosticStateOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcv()                                                       EthTrcv_30_Rtl9010_GetSizeOfEthTrcvOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010()                                                EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010OfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010AxErrataHdlr()                                    EthTrcv_30_Rtl9010_GetSizeOfEthTrcvRtl9010AxErrataHdlrOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureCallout()                                 EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureCalloutOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureDebounceCounter()                         EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorRecoveryDebounceCounter()                        EthTrcv_30_Rtl9010_GetSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfHwAccessState()                                                 EthTrcv_30_Rtl9010_GetSizeOfHwAccessStateOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvHwAccessibility()                                           EthTrcv_30_Rtl9010_GetSizeOfTrcvHwAccessibilityOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvLinkState()                                                 EthTrcv_30_Rtl9010_GetSizeOfTrcvLinkStateOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvMode()                                                      EthTrcv_30_Rtl9010_GetSizeOfTrcvModeOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfTrcvState()                                                     EthTrcv_30_Rtl9010_GetSizeOfTrcvStateOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfUserAccessCallouts()                                            EthTrcv_30_Rtl9010_GetSizeOfUserAccessCalloutsOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfUserInitCallouts()                                              EthTrcv_30_Rtl9010_GetSizeOfUserInitCalloutsOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeup()                                                        EthTrcv_30_Rtl9010_GetSizeOfWakeupOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupCallout()                                                 EthTrcv_30_Rtl9010_GetSizeOfWakeupCalloutOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupMap()                                                     EthTrcv_30_Rtl9010_GetSizeOfWakeupMapOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupMode()                                                    EthTrcv_30_Rtl9010_GetSizeOfWakeupModeOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupReasonFlags()                                             EthTrcv_30_Rtl9010_GetSizeOfWakeupReasonFlagsOfPCConfig()
#define EthTrcv_30_Rtl9010_GetSizeOfWakeupVerificationCallout()                                     EthTrcv_30_Rtl9010_GetSizeOfWakeupVerificationCalloutOfPCConfig()
#define EthTrcv_30_Rtl9010_IsWakeupCalloutUsedOfWakeup(Index)                                       (((boolean)(EthTrcv_30_Rtl9010_GetWakeupCalloutIdxOfWakeup(Index) != ETHTRCV_30_RTL9010_NO_WAKEUPCALLOUTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Rtl9010_WakeupCallout */
#define EthTrcv_30_Rtl9010_IsWakeupMapUsedOfWakeup(Index)                                           (((boolean)(EthTrcv_30_Rtl9010_GetWakeupMapStartIdxOfWakeup(Index) != ETHTRCV_30_RTL9010_NO_WAKEUPMAPSTARTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthTrcv_30_Rtl9010_WakeupMap */
#define EthTrcv_30_Rtl9010_IsWakeupVerificationCalloutUsedOfWakeup(Index)                           (((boolean)(EthTrcv_30_Rtl9010_GetWakeupVerificationCalloutIdxOfWakeup(Index) != ETHTRCV_30_RTL9010_NO_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTrcv_30_Rtl9010_WakeupVerificationCallout */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCSetDataMacros  EthTrcv_30_Rtl9010 Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EthTrcv_30_Rtl9010_SetCableDiagnosticState(Index, Value)                                    EthTrcv_30_Rtl9010_GetCableDiagnosticStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetHwAccessMonitorCycleCounter(Value)                                    (*(EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounterOfPCConfig())) = (Value)
#define EthTrcv_30_Rtl9010_SetHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounterOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetHwAccessState(Index, Value)                                           EthTrcv_30_Rtl9010_GetHwAccessStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Rtl9010_GetTrcvHwAccessibilityOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetTrcvLinkState(Index, Value)                                           EthTrcv_30_Rtl9010_GetTrcvLinkStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetTrcvMode(Index, Value)                                                EthTrcv_30_Rtl9010_GetTrcvModeOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetTrcvState(Index, Value)                                               EthTrcv_30_Rtl9010_GetTrcvStateOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetWakeupMode(Index, Value)                                              EthTrcv_30_Rtl9010_GetWakeupModeOfPCConfig()[(Index)] = (Value)
#define EthTrcv_30_Rtl9010_SetWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Rtl9010_GetWakeupReasonFlagsOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCGetAddressOfDataMacros  EthTrcv_30_Rtl9010 Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define EthTrcv_30_Rtl9010_GetAddrCableDiagnosticState(Index)                                       (&EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index))
#define EthTrcv_30_Rtl9010_GetAddrHwAccessMonitorCycleCounter()                                     (&EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter())
#define EthTrcv_30_Rtl9010_GetAddrHwAccessMonitorFailureDebounceCounter(Index)                      (&EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index))
#define EthTrcv_30_Rtl9010_GetAddrHwAccessMonitorRecoveryDebounceCounter(Index)                     (&EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index))
#define EthTrcv_30_Rtl9010_GetAddrHwAccessState(Index)                                              (&EthTrcv_30_Rtl9010_GetHwAccessState(Index))
#define EthTrcv_30_Rtl9010_GetAddrTrcvHwAccessibility(Index)                                        (&EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index))
#define EthTrcv_30_Rtl9010_GetAddrTrcvLinkState(Index)                                              (&EthTrcv_30_Rtl9010_GetTrcvLinkState(Index))
#define EthTrcv_30_Rtl9010_GetAddrTrcvMode(Index)                                                   (&EthTrcv_30_Rtl9010_GetTrcvMode(Index))
#define EthTrcv_30_Rtl9010_GetAddrTrcvState(Index)                                                  (&EthTrcv_30_Rtl9010_GetTrcvState(Index))
#define EthTrcv_30_Rtl9010_GetAddrWakeupMode(Index)                                                 (&EthTrcv_30_Rtl9010_GetWakeupMode(Index))
#define EthTrcv_30_Rtl9010_GetAddrWakeupReasonFlags(Index)                                          (&EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index))
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCHasMacros  EthTrcv_30_Rtl9010 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EthTrcv_30_Rtl9010_HasAccessEntityFcts()                                                    (EthTrcv_30_Rtl9010_GetAccessEntityFctsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasReadTrcvRegOfAccessEntityFcts()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWriteTrcvRegOfAccessEntityFcts()                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasCableDiagLoopCycles()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasCableDiagnosticState()                                                (EthTrcv_30_Rtl9010_GetCableDiagnosticStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasEthTrcv()                                                             (EthTrcv_30_Rtl9010_GetEthTrcvOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasAccessEntityFctsIdxOfEthTrcv()                                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasAccessEntitySnvOfEthTrcv()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasAddressingIdxOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasAutoNegEnabledOfEthTrcv()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasBasicCtrlRegValOfEthTrcv()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasConnectionNegOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasDemEAccessEventIdOfEthTrcv()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorEnabledOfEthTrcv()                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasMacSecEnabledOfEthTrcv()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasMiiModeOfEthTrcv()                                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasPhySignalQualityMeanOfEthTrcv()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSoCBaseRegAddrOfEthTrcv()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSoftResetOnInitEnabledOfEthTrcv()                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSoftResetWaitCyclesOfEthTrcv()                                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSpeedOfEthTrcv()                                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupIdxOfEthTrcv()                                                  (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupUsedOfEthTrcv()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasEthTrcvRtl9010()                                                      (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010OfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasDerivativeOfEthTrcvRtl9010()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasDrivingStrengthOfEthTrcvRtl9010()                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasIOPowerOfEthTrcvRtl9010()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasRxcDelayEnableOfEthTrcvRtl9010()                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasRxcDelayValueOfEthTrcvRtl9010()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSoftResetWaitCyclesOfEthTrcvRtl9010()                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTxcDelayEnableOfEthTrcvRtl9010()                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTxcDelayValueOfEthTrcvRtl9010()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasEthTrcvRtl9010AxErrataHdlr()                                          (EthTrcv_30_Rtl9010_GetEthTrcvRtl9010AxErrataHdlrOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasErratum1ActiveOfEthTrcvRtl9010AxErrataHdlr()                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasErratum2ActiveOfEthTrcvRtl9010AxErrataHdlr()                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasErratum3ActiveOfEthTrcvRtl9010AxErrataHdlr()                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasErratum4ActiveOfEthTrcvRtl9010AxErrataHdlr()                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessLoopCount()                                                   (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorCycleCounter()                                         (EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureCallout()                                       (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureDebounceCounter()                               (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureDebounceLimiter()                               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorLoopLimiter()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorRecoveryDebounceCounter()                              (EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounterOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorRecoveryDebounceLimiter()                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessState()                                                       (EthTrcv_30_Rtl9010_GetHwAccessStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasMaxPhySignalQualityMean()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfAccessEntityFcts()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfCableDiagnosticState()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcv()                                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcvRtl9010()                                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcvRtl9010AxErrataHdlr()                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorFailureCallout()                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorFailureDebounceCounter()                         (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorRecoveryDebounceCounter()                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessState()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvHwAccessibility()                                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvLinkState()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvMode()                                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvState()                                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfUserAccessCallouts()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfUserInitCallouts()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeup()                                                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupCallout()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupMap()                                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupMode()                                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupReasonFlags()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupVerificationCallout()                                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTrcvHwAccessibility()                                                 (EthTrcv_30_Rtl9010_GetTrcvHwAccessibilityOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasTrcvLinkState()                                                       (EthTrcv_30_Rtl9010_GetTrcvLinkStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasTrcvMode()                                                            (EthTrcv_30_Rtl9010_GetTrcvModeOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasTrcvState()                                                           (EthTrcv_30_Rtl9010_GetTrcvStateOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasUserAccessCallouts()                                                  (EthTrcv_30_Rtl9010_GetUserAccessCalloutsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasPreTrcvReadAccessCalloutOfUserAccessCallouts()                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasPreTrcvWriteAccessCalloutOfUserAccessCallouts()                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasUserInitCallouts()                                                    (EthTrcv_30_Rtl9010_GetUserInitCalloutsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasPostInitUserCalloutOfUserInitCallouts()                               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasPreInitUserCalloutOfUserInitCallouts()                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeup()                                                              (EthTrcv_30_Rtl9010_GetWakeupOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasIcuChannelOfWakeup()                                                  (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupCalloutIdxOfWakeup()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupCalloutUsedOfWakeup()                                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupInspectionTypeOfWakeup()                                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupMapEndIdxOfWakeup()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupMapStartIdxOfWakeup()                                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupMapUsedOfWakeup()                                               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupVerificationCalloutIdxOfWakeup()                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupVerificationCalloutUsedOfWakeup()                               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupCallout()                                                       (EthTrcv_30_Rtl9010_GetWakeupCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasWakeupMap()                                                           (EthTrcv_30_Rtl9010_GetWakeupMapOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasEcuMWakeupSourceOfWakeupMap()                                         (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupReasonOfWakeupMap()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupMode()                                                          (EthTrcv_30_Rtl9010_GetWakeupModeOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasWakeupReasonFlags()                                                   (EthTrcv_30_Rtl9010_GetWakeupReasonFlagsOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasWakeupVerificationCallout()                                           (EthTrcv_30_Rtl9010_GetWakeupVerificationCalloutOfPCConfig() != NULL_PTR)
#define EthTrcv_30_Rtl9010_HasPCConfig()                                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasAccessEntityFctsOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasCableDiagLoopCyclesOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasCableDiagnosticStateOfPCConfig()                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasEthTrcvOfPCConfig()                                                   (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasEthTrcvRtl9010AxErrataHdlrOfPCConfig()                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasEthTrcvRtl9010OfPCConfig()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessLoopCountOfPCConfig()                                         (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorCycleCounterOfPCConfig()                               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureCalloutOfPCConfig()                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureDebounceCounterOfPCConfig()                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorFailureDebounceLimiterOfPCConfig()                     (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorLoopLimiterOfPCConfig()                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorRecoveryDebounceCounterOfPCConfig()                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessMonitorRecoveryDebounceLimiterOfPCConfig()                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasHwAccessStateOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasMaxPhySignalQualityMeanOfPCConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfAccessEntityFctsOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfCableDiagnosticStateOfPCConfig()                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcvOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcvRtl9010AxErrataHdlrOfPCConfig()                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfEthTrcvRtl9010OfPCConfig()                                      (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorFailureCalloutOfPCConfig()                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorFailureDebounceCounterOfPCConfig()               (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessMonitorRecoveryDebounceCounterOfPCConfig()              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfHwAccessStateOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvHwAccessibilityOfPCConfig()                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvLinkStateOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvModeOfPCConfig()                                            (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfTrcvStateOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfUserAccessCalloutsOfPCConfig()                                  (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfUserInitCalloutsOfPCConfig()                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupCalloutOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupMapOfPCConfig()                                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupModeOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupOfPCConfig()                                              (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupReasonFlagsOfPCConfig()                                   (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasSizeOfWakeupVerificationCalloutOfPCConfig()                           (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTrcvHwAccessibilityOfPCConfig()                                       (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTrcvLinkStateOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTrcvModeOfPCConfig()                                                  (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasTrcvStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasUserAccessCalloutsOfPCConfig()                                        (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasUserInitCalloutsOfPCConfig()                                          (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupCalloutOfPCConfig()                                             (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupMapOfPCConfig()                                                 (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupModeOfPCConfig()                                                (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupOfPCConfig()                                                    (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupReasonFlagsOfPCConfig()                                         (TRUE != FALSE)
#define EthTrcv_30_Rtl9010_HasWakeupVerificationCalloutOfPCConfig()                                 (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCIncrementDataMacros  EthTrcv_30_Rtl9010 Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Rtl9010_IncCableDiagnosticState(Index)                                           EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index)++
#define EthTrcv_30_Rtl9010_IncHwAccessMonitorCycleCounter()                                         EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter()++
#define EthTrcv_30_Rtl9010_IncHwAccessMonitorFailureDebounceCounter(Index)                          EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index)++
#define EthTrcv_30_Rtl9010_IncHwAccessMonitorRecoveryDebounceCounter(Index)                         EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index)++
#define EthTrcv_30_Rtl9010_IncHwAccessState(Index)                                                  EthTrcv_30_Rtl9010_GetHwAccessState(Index)++
#define EthTrcv_30_Rtl9010_IncTrcvHwAccessibility(Index)                                            EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index)++
#define EthTrcv_30_Rtl9010_IncTrcvLinkState(Index)                                                  EthTrcv_30_Rtl9010_GetTrcvLinkState(Index)++
#define EthTrcv_30_Rtl9010_IncTrcvMode(Index)                                                       EthTrcv_30_Rtl9010_GetTrcvMode(Index)++
#define EthTrcv_30_Rtl9010_IncTrcvState(Index)                                                      EthTrcv_30_Rtl9010_GetTrcvState(Index)++
#define EthTrcv_30_Rtl9010_IncWakeupMode(Index)                                                     EthTrcv_30_Rtl9010_GetWakeupMode(Index)++
#define EthTrcv_30_Rtl9010_IncWakeupReasonFlags(Index)                                              EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCDecrementDataMacros  EthTrcv_30_Rtl9010 Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Rtl9010_DecCableDiagnosticState(Index)                                           EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index)--
#define EthTrcv_30_Rtl9010_DecHwAccessMonitorCycleCounter()                                         EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter()--
#define EthTrcv_30_Rtl9010_DecHwAccessMonitorFailureDebounceCounter(Index)                          EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index)--
#define EthTrcv_30_Rtl9010_DecHwAccessMonitorRecoveryDebounceCounter(Index)                         EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index)--
#define EthTrcv_30_Rtl9010_DecHwAccessState(Index)                                                  EthTrcv_30_Rtl9010_GetHwAccessState(Index)--
#define EthTrcv_30_Rtl9010_DecTrcvHwAccessibility(Index)                                            EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index)--
#define EthTrcv_30_Rtl9010_DecTrcvLinkState(Index)                                                  EthTrcv_30_Rtl9010_GetTrcvLinkState(Index)--
#define EthTrcv_30_Rtl9010_DecTrcvMode(Index)                                                       EthTrcv_30_Rtl9010_GetTrcvMode(Index)--
#define EthTrcv_30_Rtl9010_DecTrcvState(Index)                                                      EthTrcv_30_Rtl9010_GetTrcvState(Index)--
#define EthTrcv_30_Rtl9010_DecWakeupMode(Index)                                                     EthTrcv_30_Rtl9010_GetWakeupMode(Index)--
#define EthTrcv_30_Rtl9010_DecWakeupReasonFlags(Index)                                              EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCAddDataMacros  EthTrcv_30_Rtl9010 Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Rtl9010_AddCableDiagnosticState(Index, Value)                                    EthTrcv_30_Rtl9010_SetCableDiagnosticState(Index, (EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index) + Value))
#define EthTrcv_30_Rtl9010_AddHwAccessMonitorCycleCounter(Value)                                    EthTrcv_30_Rtl9010_SetHwAccessMonitorCycleCounter((EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter() + Value))
#define EthTrcv_30_Rtl9010_AddHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Rtl9010_SetHwAccessMonitorFailureDebounceCounter(Index, (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index) + Value))
#define EthTrcv_30_Rtl9010_AddHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Rtl9010_SetHwAccessMonitorRecoveryDebounceCounter(Index, (EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index) + Value))
#define EthTrcv_30_Rtl9010_AddHwAccessState(Index, Value)                                           EthTrcv_30_Rtl9010_SetHwAccessState(Index, (EthTrcv_30_Rtl9010_GetHwAccessState(Index) + Value))
#define EthTrcv_30_Rtl9010_AddTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Rtl9010_SetTrcvHwAccessibility(Index, (EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index) + Value))
#define EthTrcv_30_Rtl9010_AddTrcvLinkState(Index, Value)                                           EthTrcv_30_Rtl9010_SetTrcvLinkState(Index, (EthTrcv_30_Rtl9010_GetTrcvLinkState(Index) + Value))
#define EthTrcv_30_Rtl9010_AddTrcvMode(Index, Value)                                                EthTrcv_30_Rtl9010_SetTrcvMode(Index, (EthTrcv_30_Rtl9010_GetTrcvMode(Index) + Value))
#define EthTrcv_30_Rtl9010_AddTrcvState(Index, Value)                                               EthTrcv_30_Rtl9010_SetTrcvState(Index, (EthTrcv_30_Rtl9010_GetTrcvState(Index) + Value))
#define EthTrcv_30_Rtl9010_AddWakeupMode(Index, Value)                                              EthTrcv_30_Rtl9010_SetWakeupMode(Index, (EthTrcv_30_Rtl9010_GetWakeupMode(Index) + Value))
#define EthTrcv_30_Rtl9010_AddWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Rtl9010_SetWakeupReasonFlags(Index, (EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCSubstractDataMacros  EthTrcv_30_Rtl9010 Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define EthTrcv_30_Rtl9010_SubCableDiagnosticState(Index, Value)                                    EthTrcv_30_Rtl9010_SetCableDiagnosticState(Index, (EthTrcv_30_Rtl9010_GetCableDiagnosticState(Index) - Value))
#define EthTrcv_30_Rtl9010_SubHwAccessMonitorCycleCounter(Value)                                    EthTrcv_30_Rtl9010_SetHwAccessMonitorCycleCounter((EthTrcv_30_Rtl9010_GetHwAccessMonitorCycleCounter() - Value))
#define EthTrcv_30_Rtl9010_SubHwAccessMonitorFailureDebounceCounter(Index, Value)                   EthTrcv_30_Rtl9010_SetHwAccessMonitorFailureDebounceCounter(Index, (EthTrcv_30_Rtl9010_GetHwAccessMonitorFailureDebounceCounter(Index) - Value))
#define EthTrcv_30_Rtl9010_SubHwAccessMonitorRecoveryDebounceCounter(Index, Value)                  EthTrcv_30_Rtl9010_SetHwAccessMonitorRecoveryDebounceCounter(Index, (EthTrcv_30_Rtl9010_GetHwAccessMonitorRecoveryDebounceCounter(Index) - Value))
#define EthTrcv_30_Rtl9010_SubHwAccessState(Index, Value)                                           EthTrcv_30_Rtl9010_SetHwAccessState(Index, (EthTrcv_30_Rtl9010_GetHwAccessState(Index) - Value))
#define EthTrcv_30_Rtl9010_SubTrcvHwAccessibility(Index, Value)                                     EthTrcv_30_Rtl9010_SetTrcvHwAccessibility(Index, (EthTrcv_30_Rtl9010_GetTrcvHwAccessibility(Index) - Value))
#define EthTrcv_30_Rtl9010_SubTrcvLinkState(Index, Value)                                           EthTrcv_30_Rtl9010_SetTrcvLinkState(Index, (EthTrcv_30_Rtl9010_GetTrcvLinkState(Index) - Value))
#define EthTrcv_30_Rtl9010_SubTrcvMode(Index, Value)                                                EthTrcv_30_Rtl9010_SetTrcvMode(Index, (EthTrcv_30_Rtl9010_GetTrcvMode(Index) - Value))
#define EthTrcv_30_Rtl9010_SubTrcvState(Index, Value)                                               EthTrcv_30_Rtl9010_SetTrcvState(Index, (EthTrcv_30_Rtl9010_GetTrcvState(Index) - Value))
#define EthTrcv_30_Rtl9010_SubWakeupMode(Index, Value)                                              EthTrcv_30_Rtl9010_SetWakeupMode(Index, (EthTrcv_30_Rtl9010_GetWakeupMode(Index) - Value))
#define EthTrcv_30_Rtl9010_SubWakeupReasonFlags(Index, Value)                                       EthTrcv_30_Rtl9010_SetWakeupReasonFlags(Index, (EthTrcv_30_Rtl9010_GetWakeupReasonFlags(Index) - Value))
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

# if !defined(ETHTRCV_30_RTL9010_UNIT_TEST)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

# endif /* ETHTRCV_30_RTL9010_UNIT_TEST */
#endif /* ETHTRCV_30_RTL9010_LCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Rtl9010_Lcfg.h
 *********************************************************************************************************************/
 
