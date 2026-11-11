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
 *              File: EthTrcv_30_Rtl9010_GenTypes.h
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


#if !defined (ETHTRCV_30_RTL9010_GENTYPES_H)
# define ETHTRCV_30_RTL9010_GENTYPES_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
# include "Eth_GeneralTypes.h"
# include "EthSwt_GeneralTypes.h"
# include "Platform_Types.h"
# include "Rtm.h"
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA TYPES AND STRUCTURES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Rtl9010PCNonComStackLibTypes  EthTrcv_30_Rtl9010 Non ComStackLib Types (PRE_COMPILE)
  \brief  These type definitions are provided by the EthTrcv_30_Rtl9010 itself.
  \{
*/ 

/**   \brief  uint8 type for the hardware accessability */
typedef uint8 EthTrcv_30_Rtl9010_HardwareAccessibilityType;

/**   \brief  uint8 type for the debounce counter of hardware access monitor failure */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterType;

/**   \brief  uint8 type for the debounce counter of hardware access monitor recovery */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterType;

/**   \brief  uint8 type for the cable diagnostic state */
typedef uint8 EthTrcv_30_Rtl9010_CableDiagnosticStateType;

/**   \brief  bitfield type defintion for wakeup reason recognition */
typedef uint8 EthTrcv_30_Rtl9010_WakeupReasonFlagsType;

/**   \brief  function pointer type defintion for register read accesses */
typedef P2FUNC(Std_ReturnType, ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_ReadTrcvRegFctPtrType)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);

/**   \brief  function pointer type defintion for register write accesses */
typedef P2FUNC(Std_ReturnType, ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_WriteTrcvRegFctPtrType)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal);

/**   \brief  function pointer type defintion for <User>_PreTransceiverInitCallout() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserPreTrcvInitCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PostTransceiverInitCallout() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserPostTrcvInitCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_WakeupCallout() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserWakeupCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_WakeupVerificationCallout() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserWakeupVerificationCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_HwAccessMonitorFailureCalloutFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserHwAccessMonitorFailureCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PreTrcvReadCalloutsFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserPreTrcvReadCalloutsFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PreTrcvWriteCalloutsFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_RTL9010_APPL_CODE, EthTrcv_30_Rtl9010_UserPreTrcvWriteCalloutsFctPtrType)(uint8 TrcvIdx);




/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Rtl9010PCDataSwitches  EthTrcv_30_Rtl9010 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ETHTRCV_30_RTL9010_ACCESSENTITYFCTS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_READTRCVREGOFACCESSENTITYFCTS                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WRITETRCVREGOFACCESSENTITYFCTS                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ADDRXSAREQUEST                                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ACTIVEOFADDRXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.Active' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ADDRXSAREQUESTPENDINGOFADDRXSAREQUEST                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.AddRxSaRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ANOFADDRXSAREQUEST                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.An' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_KEYSOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.Keys' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_LOWESTPNOFADDRXSAREQUEST                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.LowestPn' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_REQUESTEDBYSWITCHOFADDRXSAREQUEST                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_SSCIOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest.Ssci' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ADDTXSAREQUEST                                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ACTIVEOFADDTXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.Active' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ADDTXSAREQUESTPENDINGOFADDTXSAREQUEST                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.AddTxSaRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ANOFADDTXSAREQUEST                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.An' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_KEYSOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.Keys' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_NEXTPNOFADDTXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.NextPn' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_REQUESTEDBYSWITCHOFADDTXSAREQUEST                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_SSCIOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest.Ssci' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_CABLEDIAGLOOPCYCLES                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_CABLEDIAGNOSTICSTATE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCV                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ACCESSENTITYFCTSIDXOFETHTRCV                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ACCESSENTITYSNVOFETHTRCV                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ADDRESSINGIDXOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_AUTONEGENABLEDOFETHTRCV                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_BASICCTRLREGVALOFETHTRCV                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_CONNECTIONNEGOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_DEMEACCESSEVENTIDOFETHTRCV                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORENABLEDOFETHTRCV                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_MACSECENABLEDOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_MIIMODEOFETHTRCV                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_PHYSIGNALQUALITYMEANOFETHTRCV                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SOCBASEREGADDROFETHTRCV                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SOFTRESETONINITENABLEDOFETHTRCV                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SOFTRESETWAITCYCLESOFETHTRCV                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SPEEDOFETHTRCV                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPIDXOFETHTRCV                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPUSEDOFETHTRCV                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVRTL9010                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_DERIVATIVEOFETHTRCVRTL9010                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_DRIVINGSTRENGTHOFETHTRCVRTL9010                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_IOPOWEROFETHTRCVRTL9010                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_RXCDELAYENABLEOFETHTRCVRTL9010                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_RXCDELAYVALUEOFETHTRCVRTL9010                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SOFTRESETWAITCYCLESOFETHTRCVRTL9010                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TXCDELAYENABLEOFETHTRCVRTL9010                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TXCDELAYVALUEOFETHTRCVRTL9010                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVRTL9010AXERRATAHDLR                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ERRATUM1ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ERRATUM2ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ERRATUM3ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ERRATUM4ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVRTL9010MACSEC                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_EthTrcvRtl9010MacSec' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ETHTRCV_30_RTL9010_FINALMAGICNUMBER                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_RTL9010_GETMACSECSTATSREQUEST                                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_GETMACSECSTATSREQUESTPENDINGOFGETMACSECSTATSREQUEST                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest.GetMacSecStatsRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_REQUESTEDBYSWITCHOFGETMACSECSTATSREQUEST                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_STATSOFGETMACSECSTATSREQUEST                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest.Stats' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_HWACCESSLOOPCOUNT                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORCYCLECOUNTER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILURECALLOUT                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILUREDEBOUNCECOUNTER                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILUREDEBOUNCELIMITER                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORLOOPLIMITER                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORRECOVERYDEBOUNCECOUNTER                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORRECOVERYDEBOUNCELIMITER                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSSTATE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_INITDATAHASHCODE                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_RTL9010_MACSECCONFIG                                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecConfig' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ALWAYSINCLUDESCIOFMACSECCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecConfig.AlwaysIncludeSCI' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_USEESOFMACSECCONFIG                                                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecConfig.UseES' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_MACSECDATA                                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecData' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ETHIFCTRLIDXOFMACSECDATA                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecData.EthIfCtrlIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_KEYSIZEOFMACSECDATA                                                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_MacSecData.KeySize' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_MAXPHYSIGNALQUALITYMEAN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFACCESSENTITYFCTS                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfAddRxSaRequest' Reason: 'Deactivateable: 'AddRxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfAddTxSaRequest' Reason: 'Deactivateable: 'AddTxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFCABLEDIAGNOSTICSTATE                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCV                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010AXERRATAHDLR                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010MACSEC                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010MacSec' Reason: 'Deactivateable: 'EthTrcvRtl9010MacSec' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_EthTrcvRtl9010MacSec' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_RTL9010_SIZEOFGETMACSECSTATSREQUEST                                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfGetMacSecStatsRequest' Reason: 'Deactivateable: 'GetMacSecStatsRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORFAILURECALLOUT                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORFAILUREDEBOUNCECOUNTER                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORRECOVERYDEBOUNCECOUNTER                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSSTATE                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFMACSECCONFIG                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfMacSecConfig' Reason: 'Deactivateable: 'MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_MacSecConfig' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFMACSECDATA                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfMacSecData' Reason: 'Deactivateable: 'MacSecData' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_MacSecData' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFSWITCHMACSECAPI                                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfSwitchMacSecApi' Reason: 'Deactivateable: 'SwitchMacSecApi' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVHWACCESSIBILITY                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVLINKSTATE                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVMODE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVSTATE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFUPDATESECYREQUEST                                                  STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SizeOfUpdateSecYRequest' Reason: 'Deactivateable: 'UpdateSecYRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFUSERACCESSCALLOUTS                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFUSERINITCALLOUTS                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPCALLOUT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPMAP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPMODE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPREASONFLAGS                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPVERIFICATIONCALLOUT                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SWITCHMACSECAPI                                                          STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ADDRXSANOTIFICATIONOFSWITCHMACSECAPI                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.AddRxSaNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_ADDTXSANOTIFICATIONOFSWITCHMACSECAPI                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.AddTxSaNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_GETMACSECSTATSNOTIFICATIONOFSWITCHMACSECAPI                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.GetMacSecStatsNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_PORTIDXOFSWITCHMACSECAPI                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.PortIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_SWITCHIDXOFSWITCHMACSECAPI                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.SwitchIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_UPDATESECYNOTIFICATIONOFSWITCHMACSECAPI                                  STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi.UpdateSecYNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_TRCVHWACCESSIBILITY                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVLINKSTATE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVMODE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVSTATE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_UPDATESECYREQUEST                                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_MACSECCFGOFUPDATESECYREQUEST                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest.MacSecCfg' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_REQUESTEDBYSWITCHOFUPDATESECYREQUEST                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_TXSCIOFUPDATESECYREQUEST                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest.TxSCI' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_UPDATESECYREQUESTPENDINGOFUPDATESECYREQUEST                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest.UpdateSecYRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_RTL9010_USERACCESSCALLOUTS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_USERINITCALLOUTS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_PREINITUSERCALLOUTOFUSERINITCALLOUTS                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ICUCHANNELOFWAKEUP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPCALLOUTIDXOFWAKEUP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPCALLOUTUSEDOFWAKEUP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPINSPECTIONTYPEOFWAKEUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMAPENDIDXOFWAKEUP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMAPSTARTIDXOFWAKEUP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMAPUSEDOFWAKEUP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPCALLOUT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMAP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ECUMWAKEUPSOURCEOFWAKEUPMAP                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPREASONOFWAKEUPMAP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMODE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPREASONFLAGS                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPVERIFICATIONCALLOUT                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_PCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ACCESSENTITYFCTSOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_CABLEDIAGLOOPCYCLESOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_CABLEDIAGNOSTICSTATEOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_ETHTRCVRTL9010OFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_FINALMAGICNUMBEROFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_RTL9010_HWACCESSLOOPCOUNTOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_HWACCESSSTATEOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_INITDATAHASHCODEOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_RTL9010_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFADDRXSAREQUESTOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfAddRxSaRequest' Reason: 'Deactivateable: 'AddRxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_AddRxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFADDTXSAREQUESTOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfAddTxSaRequest' Reason: 'Deactivateable: 'AddTxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_AddTxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFCABLEDIAGNOSTICSTATEOFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010MACSECOFPCCONFIG                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfEthTrcvRtl9010MacSec' Reason: 'Deactivateable: 'EthTrcvRtl9010MacSec' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_EthTrcvRtl9010MacSec' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_RTL9010_SIZEOFETHTRCVRTL9010OFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFGETMACSECSTATSREQUESTOFPCCONFIG                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfGetMacSecStatsRequest' Reason: 'Deactivateable: 'GetMacSecStatsRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_GetMacSecStatsRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFHWACCESSSTATEOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFMACSECCONFIGOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfMacSecConfig' Reason: 'Deactivateable: 'MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_MacSecConfig' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFMACSECDATAOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfMacSecData' Reason: 'Deactivateable: 'MacSecData' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_MacSecData' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFSWITCHMACSECAPIOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfSwitchMacSecApi' Reason: 'Deactivateable: 'SwitchMacSecApi' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_SwitchMacSecApi' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVHWACCESSIBILITYOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVLINKSTATEOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVMODEOFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFTRCVSTATEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFUPDATESECYREQUESTOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Rtl9010_PCConfig.SizeOfUpdateSecYRequest' Reason: 'Deactivateable: 'UpdateSecYRequest' Reason: 'Deactivateable: 'EthTrcv_30_Rtl9010_UpdateSecYRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_RTL9010_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPMAPOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPMODEOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPREASONFLAGSOFPCCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVHWACCESSIBILITYOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVLINKSTATEOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVMODEOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_TRCVSTATEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_USERACCESSCALLOUTSOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_USERINITCALLOUTSOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPCALLOUTOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMAPOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPMODEOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPREASONFLAGSOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_RTL9010_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCMinNumericValueDefines  EthTrcv_30_Rtl9010 Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define ETHTRCV_30_RTL9010_MIN_HWACCESSMONITORCYCLECOUNTER                                          0u
#define ETHTRCV_30_RTL9010_MIN_HWACCESSSTATE                                                        0u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCMaxNumericValueDefines  EthTrcv_30_Rtl9010 Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define ETHTRCV_30_RTL9010_MAX_HWACCESSMONITORCYCLECOUNTER                                          65535u
#define ETHTRCV_30_RTL9010_MAX_HWACCESSSTATE                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCNoReferenceDefines  EthTrcv_30_Rtl9010 No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define ETHTRCV_30_RTL9010_NO_WAKEUPIDXOFETHTRCV                                                    255u
#define ETHTRCV_30_RTL9010_NO_WAKEUPCALLOUTIDXOFWAKEUP                                              255u
#define ETHTRCV_30_RTL9010_NO_WAKEUPMAPENDIDXOFWAKEUP                                               255u
#define ETHTRCV_30_RTL9010_NO_WAKEUPMAPSTARTIDXOFWAKEUP                                             255u
#define ETHTRCV_30_RTL9010_NO_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCEnumExistsDefines  EthTrcv_30_Rtl9010 Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define ETHTRCV_30_RTL9010_EXISTS_CONN_NEG_AUTO_CONNECTIONNEGOFETHTRCV                              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_CONN_NEG_MASTER_CONNECTIONNEGOFETHTRCV                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV                             STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_CONN_NEG_NONE_CONNECTIONNEGOFETHTRCV                              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_INTERNAL_PHY_MIIMODEOFETHTRCV                                     STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_MII_MODE_MIIMODEOFETHTRCV                                         STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_LIGHT_MII_MODE_MIIMODEOFETHTRCV                                   STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RMII_MODE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RGMII_MODE_MIIMODEOFETHTRCV                                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_GMII_MODE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RMII_XTAL_MODE_MIIMODEOFETHTRCV                                   STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RGMII_XTAL_MODE_MIIMODEOFETHTRCV                                  STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_STRAPPING_CONFIG_ONLY_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SGMII_MODE_MIIMODEOFETHTRCV                                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SERDES_2500BASE_X_MODE_MIIMODEOFETHTRCV                           STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SERDES_5GBASE_R_MODE_MIIMODEOFETHTRCV                             STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SERDES_10GBASE_R_MODE_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SERDES_5GUSXGMII_MODE_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_SERDES_10GUSXGMII_MODE_MIIMODEOFETHTRCV                           STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_DONT_CARE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_REVERSE_MII_MODE_MIIMODEOFETHTRCV                                 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_REVERSE_RMII_MODE_MIIMODEOFETHTRCV                                STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_10_SPEEDOFETHTRCV                                      STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_100_SPEEDOFETHTRCV                                     STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_1000_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_2500_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_5000_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_SPEED_10000_SPEEDOFETHTRCV                                   STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RTL9010AA_VA_DERIVATIVEOFETHTRCVRTL9010                      STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RTL9010BX_DERIVATIVEOFETHTRCVRTL9010                         STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RTL9000CX_DERIVATIVEOFETHTRCVRTL9010                         STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_DRIVING_STRENGTH_WEAK_DRIVINGSTRENGTHOFETHTRCVRTL9010        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_DRIVING_STRENGTH_TYPICAL_DRIVINGSTRENGTHOFETHTRCVRTL9010     STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_DRIVING_STRENGTH_INVALID_DRIVINGSTRENGTHOFETHTRCVRTL9010     STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_I_O_LEVEL_1_8V_IOPOWEROFETHTRCVRTL9010                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_I_O_LEVEL_2_5V_IOPOWEROFETHTRCVRTL9010                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_I_O_LEVEL_3_3V_IOPOWEROFETHTRCVRTL9010                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_I_O_LEVEL_INVALID_IOPOWEROFETHTRCVRTL9010                    STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RXC_DELAY_ENABLED_RXCDELAYENABLEOFETHTRCVRTL9010                  STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_RXC_DELAY_DISABLED_RXCDELAYENABLEOFETHTRCVRTL9010                 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_0_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_1_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_2_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_3_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_4_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_5_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_6_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_7_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_8_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_9_RXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_RXC_DELAY_LEVEL_INVALID_RXCDELAYVALUEOFETHTRCVRTL9010        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TXC_DELAY_ENABLED_TXCDELAYENABLEOFETHTRCVRTL9010                  STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TXC_DELAY_DISABLED_TXCDELAYENABLEOFETHTRCVRTL9010                 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_0_TXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_1_TXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_2_TXCDELAYVALUEOFETHTRCVRTL9010              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_NO_DELAY_TXCDELAYVALUEOFETHTRCVRTL9010       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_NO_DELAY_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_0_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_1_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_2_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_TXC_DELAY_LEVEL_INVALID_TXCDELAYVALUEOFETHTRCVRTL9010        STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_ICU_CHANNEL_WAKEUPINSPECTIONTYPEOFWAKEUP                          STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_TRCV_REGISTERS_WAKEUPINSPECTIONTYPEOFWAKEUP                       STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_USER_CODE_WAKEUPINSPECTIONTYPEOFWAKEUP                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_DONT_CARE_WAKEUPINSPECTIONTYPEOFWAKEUP                            STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_GENERAL_WAKEUPREASONOFWAKEUPMAP                               STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_BUS_WAKEUPREASONOFWAKEUPMAP                                   STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_INTERNAL_WAKEUPREASONOFWAKEUPMAP                              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_RESET_WAKEUPREASONOFWAKEUPMAP                                 STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_POWER_ON_WAKEUPREASONOFWAKEUPMAP                              STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_PIN_WAKEUPREASONOFWAKEUPMAP                                   STD_ON
#define ETHTRCV_30_RTL9010_EXISTS_WUR_SYSERR_WAKEUPREASONOFWAKEUPMAP                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCEnumDefines  EthTrcv_30_Rtl9010 Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define ETHTRCV_30_RTL9010_CONN_NEG_AUTO_CONNECTIONNEGOFETHTRCV                                     0x00u
#define ETHTRCV_30_RTL9010_CONN_NEG_MASTER_CONNECTIONNEGOFETHTRCV                                   0x01u
#define ETHTRCV_30_RTL9010_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV                                    0x02u
#define ETHTRCV_30_RTL9010_CONN_NEG_NONE_CONNECTIONNEGOFETHTRCV                                     0x03u
#define ETHTRCV_30_RTL9010_INTERNAL_PHY_MIIMODEOFETHTRCV                                            0x00u
#define ETHTRCV_30_RTL9010_MII_MODE_MIIMODEOFETHTRCV                                                0x01u
#define ETHTRCV_30_RTL9010_LIGHT_MII_MODE_MIIMODEOFETHTRCV                                          0x02u
#define ETHTRCV_30_RTL9010_RMII_MODE_MIIMODEOFETHTRCV                                               0x03u
#define ETHTRCV_30_RTL9010_RGMII_MODE_MIIMODEOFETHTRCV                                              0x04u
#define ETHTRCV_30_RTL9010_GMII_MODE_MIIMODEOFETHTRCV                                               0x05u
#define ETHTRCV_30_RTL9010_RMII_XTAL_MODE_MIIMODEOFETHTRCV                                          0x06u
#define ETHTRCV_30_RTL9010_RGMII_XTAL_MODE_MIIMODEOFETHTRCV                                         0x07u
#define ETHTRCV_30_RTL9010_STRAPPING_CONFIG_ONLY_MIIMODEOFETHTRCV                                   0x08u
#define ETHTRCV_30_RTL9010_SGMII_MODE_MIIMODEOFETHTRCV                                              0x09u
#define ETHTRCV_30_RTL9010_SERDES_2500BASE_X_MODE_MIIMODEOFETHTRCV                                  0x0Au
#define ETHTRCV_30_RTL9010_SERDES_5GBASE_R_MODE_MIIMODEOFETHTRCV                                    0x0Bu
#define ETHTRCV_30_RTL9010_SERDES_10GBASE_R_MODE_MIIMODEOFETHTRCV                                   0x0Cu
#define ETHTRCV_30_RTL9010_SERDES_5GUSXGMII_MODE_MIIMODEOFETHTRCV                                   0x0Du
#define ETHTRCV_30_RTL9010_SERDES_10GUSXGMII_MODE_MIIMODEOFETHTRCV                                  0x0Eu
#define ETHTRCV_30_RTL9010_DONT_CARE_MIIMODEOFETHTRCV                                               0x0Fu
#define ETHTRCV_30_RTL9010_REVERSE_MII_MODE_MIIMODEOFETHTRCV                                        0x10u
#define ETHTRCV_30_RTL9010_REVERSE_RMII_MODE_MIIMODEOFETHTRCV                                       0x11u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_10_SPEEDOFETHTRCV                                             0x00u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_100_SPEEDOFETHTRCV                                            0x01u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_1000_SPEEDOFETHTRCV                                           0x02u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_2500_SPEEDOFETHTRCV                                           0x03u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_5000_SPEEDOFETHTRCV                                           0x04u
#define ETHTRCV_30_RTL9010_TRCV_SPEED_10000_SPEEDOFETHTRCV                                          0x05u
#define ETHTRCV_30_RTL9010_TRCV_RTL9010AA_VA_DERIVATIVEOFETHTRCVRTL9010                             0x00u
#define ETHTRCV_30_RTL9010_TRCV_RTL9010BX_DERIVATIVEOFETHTRCVRTL9010                                0x01u
#define ETHTRCV_30_RTL9010_TRCV_RTL9000CX_DERIVATIVEOFETHTRCVRTL9010                                0x02u
#define ETHTRCV_30_RTL9010_TRCV_DRIVING_STRENGTH_WEAK_DRIVINGSTRENGTHOFETHTRCVRTL9010               0x00u
#define ETHTRCV_30_RTL9010_TRCV_DRIVING_STRENGTH_TYPICAL_DRIVINGSTRENGTHOFETHTRCVRTL9010            0x01u
#define ETHTRCV_30_RTL9010_TRCV_DRIVING_STRENGTH_INVALID_DRIVINGSTRENGTHOFETHTRCVRTL9010            0x02u
#define ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_1_8V_IOPOWEROFETHTRCVRTL9010                              0x00u
#define ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_2_5V_IOPOWEROFETHTRCVRTL9010                              0x01u
#define ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_3_3V_IOPOWEROFETHTRCVRTL9010                              0x02u
#define ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_INVALID_IOPOWEROFETHTRCVRTL9010                           0x03u
#define ETHTRCV_30_RTL9010_RXC_DELAY_ENABLED_RXCDELAYENABLEOFETHTRCVRTL9010                         0x00u
#define ETHTRCV_30_RTL9010_RXC_DELAY_DISABLED_RXCDELAYENABLEOFETHTRCVRTL9010                        0x01u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_0_RXCDELAYVALUEOFETHTRCVRTL9010                     0x00u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_1_RXCDELAYVALUEOFETHTRCVRTL9010                     0x01u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_2_RXCDELAYVALUEOFETHTRCVRTL9010                     0x02u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_3_RXCDELAYVALUEOFETHTRCVRTL9010                     0x03u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_4_RXCDELAYVALUEOFETHTRCVRTL9010                     0x04u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_5_RXCDELAYVALUEOFETHTRCVRTL9010                     0x05u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_6_RXCDELAYVALUEOFETHTRCVRTL9010                     0x06u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_7_RXCDELAYVALUEOFETHTRCVRTL9010                     0x07u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_8_RXCDELAYVALUEOFETHTRCVRTL9010                     0x08u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_9_RXCDELAYVALUEOFETHTRCVRTL9010                     0x09u
#define ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_INVALID_RXCDELAYVALUEOFETHTRCVRTL9010               0x0Au
#define ETHTRCV_30_RTL9010_TXC_DELAY_ENABLED_TXCDELAYENABLEOFETHTRCVRTL9010                         0x00u
#define ETHTRCV_30_RTL9010_TXC_DELAY_DISABLED_TXCDELAYENABLEOFETHTRCVRTL9010                        0x01u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_0_TXCDELAYVALUEOFETHTRCVRTL9010                     0x00u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_1_TXCDELAYVALUEOFETHTRCVRTL9010                     0x01u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_2_TXCDELAYVALUEOFETHTRCVRTL9010                     0x02u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_NO_DELAY_TXCDELAYVALUEOFETHTRCVRTL9010              0x03u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_NO_DELAY_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010 0x00u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_0_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010      0x01u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_1_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010      0x02u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_2_TRCV_RTL9000CX_TXCDELAYVALUEOFETHTRCVRTL9010      0x03u
#define ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_INVALID_TXCDELAYVALUEOFETHTRCVRTL9010               0x04u
#define ETHTRCV_30_RTL9010_ICU_CHANNEL_WAKEUPINSPECTIONTYPEOFWAKEUP                                 0x00u
#define ETHTRCV_30_RTL9010_TRCV_REGISTERS_WAKEUPINSPECTIONTYPEOFWAKEUP                              0x01u
#define ETHTRCV_30_RTL9010_USER_CODE_WAKEUPINSPECTIONTYPEOFWAKEUP                                   0x02u
#define ETHTRCV_30_RTL9010_DONT_CARE_WAKEUPINSPECTIONTYPEOFWAKEUP                                   0x03u
#define ETHTRCV_30_RTL9010_WUR_GENERAL_WAKEUPREASONOFWAKEUPMAP                                      0x01u
#define ETHTRCV_30_RTL9010_WUR_BUS_WAKEUPREASONOFWAKEUPMAP                                          0x02u
#define ETHTRCV_30_RTL9010_WUR_INTERNAL_WAKEUPREASONOFWAKEUPMAP                                     0x03u
#define ETHTRCV_30_RTL9010_WUR_RESET_WAKEUPREASONOFWAKEUPMAP                                        0x04u
#define ETHTRCV_30_RTL9010_WUR_POWER_ON_WAKEUPREASONOFWAKEUPMAP                                     0x05u
#define ETHTRCV_30_RTL9010_WUR_PIN_WAKEUPREASONOFWAKEUPMAP                                          0x06u
#define ETHTRCV_30_RTL9010_WUR_SYSERR_WAKEUPREASONOFWAKEUPMAP                                       0x07u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCIsReducedToDefineDefines  EthTrcv_30_Rtl9010 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ETHTRCV_30_RTL9010_ISDEF_READTRCVREGOFACCESSENTITYFCTS                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WRITETRCVREGOFACCESSENTITYFCTS                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ACCESSENTITYFCTSIDXOFETHTRCV                                       STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ACCESSENTITYSNVOFETHTRCV                                           STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ADDRESSINGIDXOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_AUTONEGENABLEDOFETHTRCV                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_BASICCTRLREGVALOFETHTRCV                                           STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_CONNECTIONNEGOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_DEMEACCESSEVENTIDOFETHTRCV                                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORENABLEDOFETHTRCV                                    STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_MACSECENABLEDOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_MIIMODEOFETHTRCV                                                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_PHYSIGNALQUALITYMEANOFETHTRCV                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SOCBASEREGADDROFETHTRCV                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SOFTRESETONINITENABLEDOFETHTRCV                                    STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SOFTRESETWAITCYCLESOFETHTRCV                                       STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SPEEDOFETHTRCV                                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPIDXOFETHTRCV                                                 STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPUSEDOFETHTRCV                                                STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_DERIVATIVEOFETHTRCVRTL9010                                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_DRIVINGSTRENGTHOFETHTRCVRTL9010                                    STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_IOPOWEROFETHTRCVRTL9010                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_RXCDELAYENABLEOFETHTRCVRTL9010                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_RXCDELAYVALUEOFETHTRCVRTL9010                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SOFTRESETWAITCYCLESOFETHTRCVRTL9010                                STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TXCDELAYENABLEOFETHTRCVRTL9010                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TXCDELAYVALUEOFETHTRCVRTL9010                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ERRATUM1ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ERRATUM2ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ERRATUM3ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ERRATUM4ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORFAILURECALLOUT                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                       STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                              STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_PREINITUSERCALLOUTOFUSERINITCALLOUTS                               STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ICUCHANNELOFWAKEUP                                                 STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPCALLOUTIDXOFWAKEUP                                           STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPCALLOUTUSEDOFWAKEUP                                          STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPINSPECTIONTYPEOFWAKEUP                                       STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPMAPENDIDXOFWAKEUP                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPMAPSTARTIDXOFWAKEUP                                          STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPMAPUSEDOFWAKEUP                                              STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                               STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                              STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPCALLOUT                                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ECUMWAKEUPSOURCEOFWAKEUPMAP                                        STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPREASONOFWAKEUPMAP                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPVERIFICATIONCALLOUT                                          STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ACCESSENTITYFCTSOFPCCONFIG                                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_CABLEDIAGLOOPCYCLESOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_CABLEDIAGNOSTICSTATEOFPCCONFIG                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ETHTRCVOFPCCONFIG                                                  STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                               STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_ETHTRCVRTL9010OFPCCONFIG                                           STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSLOOPCOUNTOFPCCONFIG                                        STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                              STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                    STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                    STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                               STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_HWACCESSSTATEOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                  STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFETHTRCVOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFETHTRCVRTL9010OFPCCONFIG                                     STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                 STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFWAKEUPMAPOFPCCONFIG                                          STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFWAKEUPOFPCCONFIG                                             STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                          STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TRCVHWACCESSIBILITYOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TRCVLINKSTATEOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TRCVMODEOFPCCONFIG                                                 STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_TRCVSTATEOFPCCONFIG                                                STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_USERACCESSCALLOUTSOFPCCONFIG                                       STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_USERINITCALLOUTSOFPCCONFIG                                         STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPCALLOUTOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPMAPOFPCCONFIG                                                STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPMODEOFPCCONFIG                                               STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPOFPCCONFIG                                                   STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPREASONFLAGSOFPCCONFIG                                        STD_OFF
#define ETHTRCV_30_RTL9010_ISDEF_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCEqualsAlwaysToDefines  EthTrcv_30_Rtl9010 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ETHTRCV_30_RTL9010_EQ2_READTRCVREGOFACCESSENTITYFCTS                                        
#define ETHTRCV_30_RTL9010_EQ2_WRITETRCVREGOFACCESSENTITYFCTS                                       
#define ETHTRCV_30_RTL9010_EQ2_ACCESSENTITYFCTSIDXOFETHTRCV                                         
#define ETHTRCV_30_RTL9010_EQ2_ACCESSENTITYSNVOFETHTRCV                                             
#define ETHTRCV_30_RTL9010_EQ2_ADDRESSINGIDXOFETHTRCV                                               
#define ETHTRCV_30_RTL9010_EQ2_AUTONEGENABLEDOFETHTRCV                                              
#define ETHTRCV_30_RTL9010_EQ2_BASICCTRLREGVALOFETHTRCV                                             
#define ETHTRCV_30_RTL9010_EQ2_CONNECTIONNEGOFETHTRCV                                               
#define ETHTRCV_30_RTL9010_EQ2_DEMEACCESSEVENTIDOFETHTRCV                                           
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORENABLEDOFETHTRCV                                      
#define ETHTRCV_30_RTL9010_EQ2_MACSECENABLEDOFETHTRCV                                               
#define ETHTRCV_30_RTL9010_EQ2_MIIMODEOFETHTRCV                                                     
#define ETHTRCV_30_RTL9010_EQ2_PHYSIGNALQUALITYMEANOFETHTRCV                                        
#define ETHTRCV_30_RTL9010_EQ2_SOCBASEREGADDROFETHTRCV                                              
#define ETHTRCV_30_RTL9010_EQ2_SOFTRESETONINITENABLEDOFETHTRCV                                      
#define ETHTRCV_30_RTL9010_EQ2_SOFTRESETWAITCYCLESOFETHTRCV                                         
#define ETHTRCV_30_RTL9010_EQ2_SPEEDOFETHTRCV                                                       
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPIDXOFETHTRCV                                                   
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPUSEDOFETHTRCV                                                  
#define ETHTRCV_30_RTL9010_EQ2_DERIVATIVEOFETHTRCVRTL9010                                           
#define ETHTRCV_30_RTL9010_EQ2_DRIVINGSTRENGTHOFETHTRCVRTL9010                                      
#define ETHTRCV_30_RTL9010_EQ2_IOPOWEROFETHTRCVRTL9010                                              
#define ETHTRCV_30_RTL9010_EQ2_RXCDELAYENABLEOFETHTRCVRTL9010                                       
#define ETHTRCV_30_RTL9010_EQ2_RXCDELAYVALUEOFETHTRCVRTL9010                                        
#define ETHTRCV_30_RTL9010_EQ2_SOFTRESETWAITCYCLESOFETHTRCVRTL9010                                  
#define ETHTRCV_30_RTL9010_EQ2_TXCDELAYENABLEOFETHTRCVRTL9010                                       
#define ETHTRCV_30_RTL9010_EQ2_TXCDELAYVALUEOFETHTRCVRTL9010                                        
#define ETHTRCV_30_RTL9010_EQ2_ERRATUM1ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                           
#define ETHTRCV_30_RTL9010_EQ2_ERRATUM2ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                           
#define ETHTRCV_30_RTL9010_EQ2_ERRATUM3ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                           
#define ETHTRCV_30_RTL9010_EQ2_ERRATUM4ACTIVEOFETHTRCVRTL9010AXERRATAHDLR                           
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORFAILURECALLOUT                                        
#define ETHTRCV_30_RTL9010_EQ2_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                         
#define ETHTRCV_30_RTL9010_EQ2_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                        
#define ETHTRCV_30_RTL9010_EQ2_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                                
#define ETHTRCV_30_RTL9010_EQ2_PREINITUSERCALLOUTOFUSERINITCALLOUTS                                 
#define ETHTRCV_30_RTL9010_EQ2_ICUCHANNELOFWAKEUP                                                   
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPCALLOUTIDXOFWAKEUP                                             
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPCALLOUTUSEDOFWAKEUP                                            
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPINSPECTIONTYPEOFWAKEUP                                         
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPMAPENDIDXOFWAKEUP                                              
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPMAPSTARTIDXOFWAKEUP                                            
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPMAPUSEDOFWAKEUP                                                
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                 
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                                
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPCALLOUT                                                        
#define ETHTRCV_30_RTL9010_EQ2_ECUMWAKEUPSOURCEOFWAKEUPMAP                                          
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPREASONOFWAKEUPMAP                                              
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPVERIFICATIONCALLOUT                                            
#define ETHTRCV_30_RTL9010_EQ2_ACCESSENTITYFCTSOFPCCONFIG                                           
#define ETHTRCV_30_RTL9010_EQ2_CABLEDIAGLOOPCYCLESOFPCCONFIG                                        
#define ETHTRCV_30_RTL9010_EQ2_CABLEDIAGNOSTICSTATEOFPCCONFIG                                       
#define ETHTRCV_30_RTL9010_EQ2_ETHTRCVOFPCCONFIG                                                    
#define ETHTRCV_30_RTL9010_EQ2_ETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                                 
#define ETHTRCV_30_RTL9010_EQ2_ETHTRCVRTL9010OFPCCONFIG                                             
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSLOOPCOUNTOFPCCONFIG                                          
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                                
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                              
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                      
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                      
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                                 
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                     
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                     
#define ETHTRCV_30_RTL9010_EQ2_HWACCESSSTATEOFPCCONFIG                                              
#define ETHTRCV_30_RTL9010_EQ2_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                    
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                     
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFETHTRCVOFPCCONFIG                                              
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFETHTRCVRTL9010AXERRATAHDLROFPCCONFIG                           
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFETHTRCVRTL9010OFPCCONFIG                                       
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                        
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                   
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                     
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                        
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFWAKEUPMAPOFPCCONFIG                                            
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFWAKEUPOFPCCONFIG                                               
#define ETHTRCV_30_RTL9010_EQ2_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                            
#define ETHTRCV_30_RTL9010_EQ2_TRCVHWACCESSIBILITYOFPCCONFIG                                        
#define ETHTRCV_30_RTL9010_EQ2_TRCVLINKSTATEOFPCCONFIG                                              
#define ETHTRCV_30_RTL9010_EQ2_TRCVMODEOFPCCONFIG                                                   
#define ETHTRCV_30_RTL9010_EQ2_TRCVSTATEOFPCCONFIG                                                  
#define ETHTRCV_30_RTL9010_EQ2_USERACCESSCALLOUTSOFPCCONFIG                                         
#define ETHTRCV_30_RTL9010_EQ2_USERINITCALLOUTSOFPCCONFIG                                           
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPCALLOUTOFPCCONFIG                                              
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPMAPOFPCCONFIG                                                  
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPMODEOFPCCONFIG                                                 
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPOFPCCONFIG                                                     
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPREASONFLAGSOFPCCONFIG                                          
#define ETHTRCV_30_RTL9010_EQ2_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                  
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCSymbolicInitializationPointers  EthTrcv_30_Rtl9010 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define EthTrcv_30_Rtl9010_Config_Ptr                                                               &(EthTrcv_30_Rtl9010_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'EthTrcv_30_Rtl9010' */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCInitializationSymbols  EthTrcv_30_Rtl9010 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define EthTrcv_30_Rtl9010_Config                                                                   EthTrcv_30_Rtl9010_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'EthTrcv_30_Rtl9010 */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCGeneral  EthTrcv_30_Rtl9010 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ETHTRCV_30_RTL9010_CHECK_INIT_POINTER                                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ETHTRCV_30_RTL9010_FINAL_MAGIC_NUMBER                                                       0x491Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of EthTrcv_30_Rtl9010 */
#define ETHTRCV_30_RTL9010_INDIVIDUAL_POSTBUILD                                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'EthTrcv_30_Rtl9010' is not configured to be postbuild capable. */
#define ETHTRCV_30_RTL9010_INIT_DATA                                                                ETHTRCV_30_RTL9010_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ETHTRCV_30_RTL9010_INIT_DATA_HASH_CODE                                                      504202949  /**< the precompile constant to validate the initialization structure at initialization time of EthTrcv_30_Rtl9010 with a hashcode. The seed value is '0x491Eu' */
#define ETHTRCV_30_RTL9010_USE_ECUM_BSW_ERROR_HOOK                                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ETHTRCV_30_RTL9010_USE_INIT_POINTER                                                         STD_ON  /**< STD_ON if the init pointer EthTrcv_30_Rtl9010 shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Rtl9010PCSizeOfTypes  EthTrcv_30_Rtl9010 SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfAccessEntityFcts */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfAccessEntityFctsType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfCableDiagnosticState */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfCableDiagnosticStateType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010AxErrataHdlr */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010AxErrataHdlrType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorFailureCallout */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorFailureCalloutType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorFailureDebounceCounter */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorFailureDebounceCounterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorRecoveryDebounceCounter */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorRecoveryDebounceCounterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfHwAccessState */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfHwAccessStateType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfTrcvHwAccessibility */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfTrcvHwAccessibilityType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfTrcvLinkState */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfTrcvLinkStateType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfTrcvMode */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfTrcvModeType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfTrcvState */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfTrcvStateType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfUserAccessCallouts */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfUserAccessCalloutsType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfUserInitCallouts */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfUserInitCalloutsType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeupCallout */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupCalloutType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeupMap */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupMapType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeupMode */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupModeType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeupReasonFlags */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupReasonFlagsType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SizeOfWakeupVerificationCallout */
typedef uint8 EthTrcv_30_Rtl9010_SizeOfWakeupVerificationCalloutType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Rtl9010PCIterableTypes  EthTrcv_30_Rtl9010 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate EthTrcv_30_Rtl9010_AccessEntityFcts */
typedef uint8_least EthTrcv_30_Rtl9010_AccessEntityFctsIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_EthTrcv */
typedef uint8_least EthTrcv_30_Rtl9010_EthTrcvIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
typedef uint8_least EthTrcv_30_Rtl9010_EthTrcvRtl9010IterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
typedef uint8_least EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
typedef uint8_least EthTrcv_30_Rtl9010_HwAccessMonitorFailureCalloutIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_UserAccessCallouts */
typedef uint8_least EthTrcv_30_Rtl9010_UserAccessCalloutsIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_UserInitCallouts */
typedef uint8_least EthTrcv_30_Rtl9010_UserInitCalloutsIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_Wakeup */
typedef uint8_least EthTrcv_30_Rtl9010_WakeupIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_WakeupCallout */
typedef uint8_least EthTrcv_30_Rtl9010_WakeupCalloutIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_WakeupMap */
typedef uint8_least EthTrcv_30_Rtl9010_WakeupMapIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_WakeupVerificationCallout */
typedef uint8_least EthTrcv_30_Rtl9010_WakeupVerificationCalloutIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCIterableTypesWithSizeRelations  EthTrcv_30_Rtl9010 Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate EthTrcv_30_Rtl9010_CableDiagnosticState */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_CableDiagnosticStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_HwAccessState */
typedef EthTrcv_30_Rtl9010_EthTrcvRtl9010IterType EthTrcv_30_Rtl9010_HwAccessStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_TrcvHwAccessibility */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_TrcvHwAccessibilityIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_TrcvLinkState */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_TrcvLinkStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_TrcvMode */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_TrcvModeIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_TrcvState */
typedef EthTrcv_30_Rtl9010_EthTrcvIterType EthTrcv_30_Rtl9010_TrcvStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_WakeupMode */
typedef EthTrcv_30_Rtl9010_WakeupIterType EthTrcv_30_Rtl9010_WakeupModeIterType;

/**   \brief  type used to iterate EthTrcv_30_Rtl9010_WakeupReasonFlags */
typedef EthTrcv_30_Rtl9010_WakeupIterType EthTrcv_30_Rtl9010_WakeupReasonFlagsIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCValueTypes  EthTrcv_30_Rtl9010 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for EthTrcv_30_Rtl9010_CableDiagLoopCycles */
typedef uint16 EthTrcv_30_Rtl9010_CableDiagLoopCyclesType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_AccessEntityFctsIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_AccessEntityFctsIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_AccessEntitySnvOfEthTrcv */
typedef uint32 EthTrcv_30_Rtl9010_AccessEntitySnvOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_AddressingIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_AddressingIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_AutoNegEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Rtl9010_AutoNegEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_BasicCtrlRegValOfEthTrcv */
typedef uint16 EthTrcv_30_Rtl9010_BasicCtrlRegValOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_ConnectionNegOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_ConnectionNegOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_DemEAccessEventIdOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_DemEAccessEventIdOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessMonitorEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Rtl9010_HwAccessMonitorEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_MacSecEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Rtl9010_MacSecEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_MiiModeOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_MiiModeOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_PhySignalQualityMeanOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_PhySignalQualityMeanOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SoCBaseRegAddrOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_SoCBaseRegAddrOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SoftResetOnInitEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Rtl9010_SoftResetOnInitEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SpeedOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_SpeedOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Rtl9010_WakeupIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupUsedOfEthTrcv */
typedef boolean EthTrcv_30_Rtl9010_WakeupUsedOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_DerivativeOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_DerivativeOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_DrivingStrengthOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_DrivingStrengthOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_IOPowerOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_IOPowerOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_RxcDelayEnableOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_RxcDelayEnableOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_RxcDelayValueOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_RxcDelayValueOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_TxcDelayEnableOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_TxcDelayEnableOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_TxcDelayValueOfEthTrcvRtl9010 */
typedef uint8 EthTrcv_30_Rtl9010_TxcDelayValueOfEthTrcvRtl9010Type;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_Erratum1ActiveOfEthTrcvRtl9010AxErrataHdlr */
typedef boolean EthTrcv_30_Rtl9010_Erratum1ActiveOfEthTrcvRtl9010AxErrataHdlrType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_Erratum2ActiveOfEthTrcvRtl9010AxErrataHdlr */
typedef boolean EthTrcv_30_Rtl9010_Erratum2ActiveOfEthTrcvRtl9010AxErrataHdlrType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_Erratum3ActiveOfEthTrcvRtl9010AxErrataHdlr */
typedef boolean EthTrcv_30_Rtl9010_Erratum3ActiveOfEthTrcvRtl9010AxErrataHdlrType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_Erratum4ActiveOfEthTrcvRtl9010AxErrataHdlr */
typedef boolean EthTrcv_30_Rtl9010_Erratum4ActiveOfEthTrcvRtl9010AxErrataHdlrType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessLoopCount */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessLoopCountType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter */
typedef uint16 EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceLimiter */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessMonitorLoopLimiter */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessMonitorLoopLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceLimiter */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_HwAccessState */
typedef uint8 EthTrcv_30_Rtl9010_HwAccessStateType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_MaxPhySignalQualityMean */
typedef uint8 EthTrcv_30_Rtl9010_MaxPhySignalQualityMeanType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_IcuChannelOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_IcuChannelOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupCalloutIdxOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_WakeupCalloutIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupCalloutUsedOfWakeup */
typedef boolean EthTrcv_30_Rtl9010_WakeupCalloutUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupInspectionTypeOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_WakeupInspectionTypeOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupMapEndIdxOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_WakeupMapEndIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupMapStartIdxOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_WakeupMapStartIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupMapUsedOfWakeup */
typedef boolean EthTrcv_30_Rtl9010_WakeupMapUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupVerificationCalloutIdxOfWakeup */
typedef uint8 EthTrcv_30_Rtl9010_WakeupVerificationCalloutIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupVerificationCalloutUsedOfWakeup */
typedef boolean EthTrcv_30_Rtl9010_WakeupVerificationCalloutUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_EcuMWakeupSourceOfWakeupMap */
typedef uint8 EthTrcv_30_Rtl9010_EcuMWakeupSourceOfWakeupMapType;

/**   \brief  value based type definition for EthTrcv_30_Rtl9010_WakeupReasonOfWakeupMap */
typedef uint8 EthTrcv_30_Rtl9010_WakeupReasonOfWakeupMapType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Rtl9010PCStructTypes  EthTrcv_30_Rtl9010 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in EthTrcv_30_Rtl9010_AccessEntityFcts */
typedef struct sEthTrcv_30_Rtl9010_AccessEntityFctsType
{
  EthTrcv_30_Rtl9010_ReadTrcvRegFctPtrType ReadTrcvRegOfAccessEntityFcts;  /**< Function to call when a read register shall be performed */
  EthTrcv_30_Rtl9010_WriteTrcvRegFctPtrType WriteTrcvRegOfAccessEntityFcts;  /**< Function to call when a write register shall be performed */
} EthTrcv_30_Rtl9010_AccessEntityFctsType;

/**   \brief  type used in EthTrcv_30_Rtl9010_EthTrcv */
typedef struct sEthTrcv_30_Rtl9010_EthTrcvType
{
  EthTrcv_30_Rtl9010_AccessEntitySnvOfEthTrcvType AccessEntitySnvOfEthTrcv;  /**< Entity providing access to the transceiver hardware */
  EthTrcv_30_Rtl9010_BasicCtrlRegValOfEthTrcvType BasicCtrlRegValOfEthTrcv;  /**< Initialization value of basic control register */
  EthTrcv_30_Rtl9010_AutoNegEnabledOfEthTrcvType AutoNegEnabledOfEthTrcv;  /**< Auto negotiation configuration */
  EthTrcv_30_Rtl9010_HwAccessMonitorEnabledOfEthTrcvType HwAccessMonitorEnabledOfEthTrcv;  /**< Enable HW access monitor for the defined Transceiver */
  EthTrcv_30_Rtl9010_MacSecEnabledOfEthTrcvType MacSecEnabledOfEthTrcv;  /**< Indicates if MACsec is enabled for this transceiver */
  EthTrcv_30_Rtl9010_SoftResetOnInitEnabledOfEthTrcvType SoftResetOnInitEnabledOfEthTrcv;  /**< Soft reset on initialization configuration */
  EthTrcv_30_Rtl9010_AccessEntityFctsIdxOfEthTrcvType AccessEntityFctsIdxOfEthTrcv;  /**< the index of the 1:1 relation pointing to EthTrcv_30_Rtl9010_AccessEntityFcts */
  EthTrcv_30_Rtl9010_AddressingIdxOfEthTrcvType AddressingIdxOfEthTrcv;  /**< Addressing index in context of the access entity to address the transceiver hardware */
  EthTrcv_30_Rtl9010_ConnectionNegOfEthTrcvType ConnectionNegOfEthTrcv;  /**< Connection negotiation configuration */
  EthTrcv_30_Rtl9010_DemEAccessEventIdOfEthTrcvType DemEAccessEventIdOfEthTrcv;  /**< ETHTRCV_E_ACCESS DEM event */
  EthTrcv_30_Rtl9010_MiiModeOfEthTrcvType MiiModeOfEthTrcv;  /**< Mii interface */
  EthTrcv_30_Rtl9010_PhySignalQualityMeanOfEthTrcvType PhySignalQualityMeanOfEthTrcv;  /**< Mean value of phyisical signal quality */
  EthTrcv_30_Rtl9010_SoCBaseRegAddrOfEthTrcvType SoCBaseRegAddrOfEthTrcv;  /**< Base register address within memory space of SoC in case PHY is integrated as module into SoC. */
  EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcvType SoftResetWaitCyclesOfEthTrcv;  /**< Soft reset wait cycles */
  EthTrcv_30_Rtl9010_SpeedOfEthTrcvType SpeedOfEthTrcv;  /**< Transceiver speed */
  EthTrcv_30_Rtl9010_WakeupIdxOfEthTrcvType WakeupIdxOfEthTrcv;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Rtl9010_Wakeup */
} EthTrcv_30_Rtl9010_EthTrcvType;

/**   \brief  type used in EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
typedef struct sEthTrcv_30_Rtl9010_EthTrcvRtl9010Type
{
  EthTrcv_30_Rtl9010_DerivativeOfEthTrcvRtl9010Type DerivativeOfEthTrcvRtl9010;  /**< Rtl9010AA-Vx derivative */
  EthTrcv_30_Rtl9010_DrivingStrengthOfEthTrcvRtl9010Type DrivingStrengthOfEthTrcvRtl9010;  /**< RGMII Driving Strength */
  EthTrcv_30_Rtl9010_IOPowerOfEthTrcvRtl9010Type IOPowerOfEthTrcvRtl9010;  /**< RGMII I/O Power Level */
  EthTrcv_30_Rtl9010_RxcDelayEnableOfEthTrcvRtl9010Type RxcDelayEnableOfEthTrcvRtl9010;  /**< RGMII delay for Rxc */
  EthTrcv_30_Rtl9010_RxcDelayValueOfEthTrcvRtl9010Type RxcDelayValueOfEthTrcvRtl9010;  /**< RxcDelay level selection */
  EthTrcv_30_Rtl9010_SoftResetWaitCyclesOfEthTrcvRtl9010Type SoftResetWaitCyclesOfEthTrcvRtl9010;  /**< Soft reset wait cycles */
  EthTrcv_30_Rtl9010_TxcDelayEnableOfEthTrcvRtl9010Type TxcDelayEnableOfEthTrcvRtl9010;  /**< RGMII delay for Txc */
  EthTrcv_30_Rtl9010_TxcDelayValueOfEthTrcvRtl9010Type TxcDelayValueOfEthTrcvRtl9010;  /**< TxcDelay level selection */
} EthTrcv_30_Rtl9010_EthTrcvRtl9010Type;

/**   \brief  type used in EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
typedef struct sEthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrType
{
  EthTrcv_30_Rtl9010_Erratum1ActiveOfEthTrcvRtl9010AxErrataHdlrType Erratum1ActiveOfEthTrcvRtl9010AxErrataHdlr;  /**< Indicates if Erratum #1 is active. */
  EthTrcv_30_Rtl9010_Erratum2ActiveOfEthTrcvRtl9010AxErrataHdlrType Erratum2ActiveOfEthTrcvRtl9010AxErrataHdlr;  /**< Indicates if Erratum #2 is active. */
  EthTrcv_30_Rtl9010_Erratum3ActiveOfEthTrcvRtl9010AxErrataHdlrType Erratum3ActiveOfEthTrcvRtl9010AxErrataHdlr;  /**< Indicates if Erratum #3 is active. */
  EthTrcv_30_Rtl9010_Erratum4ActiveOfEthTrcvRtl9010AxErrataHdlrType Erratum4ActiveOfEthTrcvRtl9010AxErrataHdlr;  /**< Indicates if Erratum #4 is active. */
} EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrType;

/**   \brief  type used in EthTrcv_30_Rtl9010_UserAccessCallouts */
typedef struct sEthTrcv_30_Rtl9010_UserAccessCalloutsType
{
  EthTrcv_30_Rtl9010_UserPreTrcvReadCalloutsFctPtrType PreTrcvReadAccessCalloutOfUserAccessCallouts;  /**< Pre-Transceiver Read Access callout */
  EthTrcv_30_Rtl9010_UserPreTrcvWriteCalloutsFctPtrType PreTrcvWriteAccessCalloutOfUserAccessCallouts;  /**< Pre-Transceiver Write Access callout */
} EthTrcv_30_Rtl9010_UserAccessCalloutsType;

/**   \brief  type used in EthTrcv_30_Rtl9010_UserInitCallouts */
typedef struct sEthTrcv_30_Rtl9010_UserInitCalloutsType
{
  EthTrcv_30_Rtl9010_UserPostTrcvInitCalloutFctPtrType PostInitUserCalloutOfUserInitCallouts;  /**< Post-Transceiver-Initialization callout */
  EthTrcv_30_Rtl9010_UserPreTrcvInitCalloutFctPtrType PreInitUserCalloutOfUserInitCallouts;  /**< Pre-Transceiver-Initialization callout */
} EthTrcv_30_Rtl9010_UserInitCalloutsType;

/**   \brief  type used in EthTrcv_30_Rtl9010_Wakeup */
typedef struct sEthTrcv_30_Rtl9010_WakeupType
{
  EthTrcv_30_Rtl9010_IcuChannelOfWakeupType IcuChannelOfWakeup;  /**< Icu channel related to wakeup signal */
  EthTrcv_30_Rtl9010_WakeupCalloutIdxOfWakeupType WakeupCalloutIdxOfWakeup;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Rtl9010_WakeupCallout */
  EthTrcv_30_Rtl9010_WakeupInspectionTypeOfWakeupType WakeupInspectionTypeOfWakeup;  /**< Inspection type method */
  EthTrcv_30_Rtl9010_WakeupMapEndIdxOfWakeupType WakeupMapEndIdxOfWakeup;  /**< the end index of the 0:n relation pointing to EthTrcv_30_Rtl9010_WakeupMap */
  EthTrcv_30_Rtl9010_WakeupMapStartIdxOfWakeupType WakeupMapStartIdxOfWakeup;  /**< the start index of the 0:n relation pointing to EthTrcv_30_Rtl9010_WakeupMap */
  EthTrcv_30_Rtl9010_WakeupVerificationCalloutIdxOfWakeupType WakeupVerificationCalloutIdxOfWakeup;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Rtl9010_WakeupVerificationCallout */
} EthTrcv_30_Rtl9010_WakeupType;

/**   \brief  type used in EthTrcv_30_Rtl9010_WakeupMap */
typedef struct sEthTrcv_30_Rtl9010_WakeupMapType
{
  EthTrcv_30_Rtl9010_EcuMWakeupSourceOfWakeupMapType EcuMWakeupSourceOfWakeupMap;  /**< Wakeup source of EcuM */
  EthTrcv_30_Rtl9010_WakeupReasonOfWakeupMapType WakeupReasonOfWakeupMap;  /**< Wakeup reason of EthTrcv */
} EthTrcv_30_Rtl9010_WakeupMapType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCRootPointerTypes  EthTrcv_30_Rtl9010 Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to EthTrcv_30_Rtl9010_AccessEntityFcts */
typedef P2CONST(EthTrcv_30_Rtl9010_AccessEntityFctsType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_AccessEntityFctsPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_CableDiagnosticState */
typedef P2VAR(EthTrcv_30_Rtl9010_CableDiagnosticStateType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_CableDiagnosticStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_EthTrcv */
typedef P2CONST(EthTrcv_30_Rtl9010_EthTrcvType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
typedef P2CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010Type, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010PtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
typedef P2CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter */
typedef P2VAR(EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
typedef P2CONST(EthTrcv_30_Rtl9010_UserHwAccessMonitorFailureCalloutFctPtrType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_HwAccessMonitorFailureCalloutPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter */
typedef P2VAR(EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter */
typedef P2VAR(EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_HwAccessState */
typedef P2VAR(EthTrcv_30_Rtl9010_HwAccessStateType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_TrcvHwAccessibility */
typedef P2VAR(EthTrcv_30_Rtl9010_HardwareAccessibilityType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvHwAccessibilityPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_TrcvLinkState */
typedef P2VAR(EthTrcv_StateType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvLinkStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_TrcvMode */
typedef P2VAR(EthTrcv_ModeType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvModePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_TrcvState */
typedef P2VAR(EthTrcv_StateType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_UserAccessCallouts */
typedef P2CONST(EthTrcv_30_Rtl9010_UserAccessCalloutsType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserAccessCalloutsPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_UserInitCallouts */
typedef P2CONST(EthTrcv_30_Rtl9010_UserInitCalloutsType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserInitCalloutsPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_Wakeup */
typedef P2CONST(EthTrcv_30_Rtl9010_WakeupType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_WakeupPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_WakeupCallout */
typedef P2CONST(EthTrcv_30_Rtl9010_UserWakeupCalloutFctPtrType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_WakeupCalloutPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_WakeupMap */
typedef P2CONST(EthTrcv_30_Rtl9010_WakeupMapType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_WakeupMapPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_WakeupMode */
typedef P2VAR(EthTrcv_WakeupModeType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_WakeupModePtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_WakeupReasonFlags */
typedef P2VAR(EthTrcv_30_Rtl9010_WakeupReasonFlagsType, TYPEDEF, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_WakeupReasonFlagsPtrType;

/**   \brief  type used to point to EthTrcv_30_Rtl9010_WakeupVerificationCallout */
typedef P2CONST(EthTrcv_30_Rtl9010_UserWakeupVerificationCalloutFctPtrType, TYPEDEF, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_WakeupVerificationCalloutPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Rtl9010PCRootValueTypes  EthTrcv_30_Rtl9010 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in EthTrcv_30_Rtl9010_PCConfig */
typedef struct sEthTrcv_30_Rtl9010_PCConfigType
{
  EthTrcv_30_Rtl9010_AccessEntityFctsPtrType AccessEntityFctsOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_AccessEntityFcts */
  EthTrcv_30_Rtl9010_CableDiagnosticStatePtrType CableDiagnosticStateOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_CableDiagnosticState */
  EthTrcv_30_Rtl9010_EthTrcvPtrType EthTrcvOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_EthTrcv */
  EthTrcv_30_Rtl9010_EthTrcvRtl9010PtrType EthTrcvRtl9010OfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
  EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrPtrType EthTrcvRtl9010AxErrataHdlrOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
  EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterPtrType HwAccessMonitorCycleCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter */
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureCalloutPtrType HwAccessMonitorFailureCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterPtrType HwAccessMonitorFailureDebounceCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter */
  EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterPtrType HwAccessMonitorRecoveryDebounceCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter */
  EthTrcv_30_Rtl9010_HwAccessStatePtrType HwAccessStateOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessState */
  EthTrcv_30_Rtl9010_TrcvHwAccessibilityPtrType TrcvHwAccessibilityOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_TrcvHwAccessibility */
  EthTrcv_30_Rtl9010_TrcvLinkStatePtrType TrcvLinkStateOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_TrcvLinkState */
  EthTrcv_30_Rtl9010_TrcvModePtrType TrcvModeOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_TrcvMode */
  EthTrcv_30_Rtl9010_TrcvStatePtrType TrcvStateOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_TrcvState */
  EthTrcv_30_Rtl9010_UserAccessCalloutsPtrType UserAccessCalloutsOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_UserAccessCallouts */
  EthTrcv_30_Rtl9010_UserInitCalloutsPtrType UserInitCalloutsOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_UserInitCallouts */
  EthTrcv_30_Rtl9010_WakeupPtrType WakeupOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_Wakeup */
  EthTrcv_30_Rtl9010_WakeupCalloutPtrType WakeupCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_WakeupCallout */
  EthTrcv_30_Rtl9010_WakeupMapPtrType WakeupMapOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_WakeupMap */
  EthTrcv_30_Rtl9010_WakeupModePtrType WakeupModeOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_WakeupMode */
  EthTrcv_30_Rtl9010_WakeupReasonFlagsPtrType WakeupReasonFlagsOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_WakeupReasonFlags */
  EthTrcv_30_Rtl9010_WakeupVerificationCalloutPtrType WakeupVerificationCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Rtl9010_WakeupVerificationCallout */
  EthTrcv_30_Rtl9010_CableDiagLoopCyclesType CableDiagLoopCyclesOfPCConfig;  /**< Maximum tries the driver performs to get results during cable diagnostics. */
  EthTrcv_30_Rtl9010_HwAccessLoopCountType HwAccessLoopCountOfPCConfig;  /**< Maximum tries the driver performs to access the hardware. */
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceLimiterType HwAccessMonitorFailureDebounceLimiterOfPCConfig;  /**< The debounce limiter number. The debouncing is completed when the debounce counter reaches that value */
  EthTrcv_30_Rtl9010_HwAccessMonitorLoopLimiterType HwAccessMonitorLoopLimiterOfPCConfig;  /**< The loop limiter value to realize the period of the hardware access check in relation to the main function period */
  EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceLimiterType HwAccessMonitorRecoveryDebounceLimiterOfPCConfig;  /**< The debounce limiter number. The debouncing is completed when the debounce counter reaches that value */
  EthTrcv_30_Rtl9010_MaxPhySignalQualityMeanType MaxPhySignalQualityMeanOfPCConfig;  /**< Maximum physical signal quality mean configured for the Ethernet transceivers */
  EthTrcv_30_Rtl9010_SizeOfAccessEntityFctsType SizeOfAccessEntityFctsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_AccessEntityFcts */
  EthTrcv_30_Rtl9010_SizeOfEthTrcvType SizeOfEthTrcvOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcv */
  EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010Type SizeOfEthTrcvRtl9010OfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
  EthTrcv_30_Rtl9010_SizeOfEthTrcvRtl9010AxErrataHdlrType SizeOfEthTrcvRtl9010AxErrataHdlrOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
  EthTrcv_30_Rtl9010_SizeOfHwAccessMonitorFailureCalloutType SizeOfHwAccessMonitorFailureCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
  EthTrcv_30_Rtl9010_SizeOfUserAccessCalloutsType SizeOfUserAccessCalloutsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserAccessCallouts */
  EthTrcv_30_Rtl9010_SizeOfUserInitCalloutsType SizeOfUserInitCalloutsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserInitCallouts */
  EthTrcv_30_Rtl9010_SizeOfWakeupType SizeOfWakeupOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_Wakeup */
  EthTrcv_30_Rtl9010_SizeOfWakeupCalloutType SizeOfWakeupCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupCallout */
  EthTrcv_30_Rtl9010_SizeOfWakeupMapType SizeOfWakeupMapOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupMap */
  EthTrcv_30_Rtl9010_SizeOfWakeupVerificationCalloutType SizeOfWakeupVerificationCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupVerificationCallout */
} EthTrcv_30_Rtl9010_PCConfigType;

typedef EthTrcv_30_Rtl9010_PCConfigType EthTrcv_30_Rtl9010_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access EthTrcv_30_Rtl9010_PCConfig in a symbol based style. */
typedef struct sEthTrcv_30_Rtl9010_PCConfigsType
{
  EthTrcv_30_Rtl9010_PCConfigType Config;  /**< [Config] */
} EthTrcv_30_Rtl9010_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_AccessEntityFcts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_AccessEntityFcts
  \brief  Functions of the accesses entities to read/write transceiver registers.
  \details
  Element         Description
  ReadTrcvReg     Function to call when a read register shall be performed
  WriteTrcvReg    Function to call when a write register shall be performed
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_AccessEntityFctsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_AccessEntityFcts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcv
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcv
  \brief  Ethernet transceivers managed by the driver.
  \details
  Element                   Description
  AccessEntitySnv           Entity providing access to the transceiver hardware
  BasicCtrlRegVal           Initialization value of basic control register
  AutoNegEnabled            Auto negotiation configuration
  HwAccessMonitorEnabled    Enable HW access monitor for the defined Transceiver
  MacSecEnabled             Indicates if MACsec is enabled for this transceiver
  SoftResetOnInitEnabled    Soft reset on initialization configuration
  AccessEntityFctsIdx       the index of the 1:1 relation pointing to EthTrcv_30_Rtl9010_AccessEntityFcts
  AddressingIdx             Addressing index in context of the access entity to address the transceiver hardware
  ConnectionNeg             Connection negotiation configuration
  DemEAccessEventId         ETHTRCV_E_ACCESS DEM event
  MiiMode                   Mii interface
  PhySignalQualityMean      Mean value of phyisical signal quality
  SoCBaseRegAddr            Base register address within memory space of SoC in case PHY is integrated as module into SoC.
  SoftResetWaitCycles       Soft reset wait cycles
  Speed                     Transceiver speed
  WakeupIdx                 the index of the 0:1 relation pointing to EthTrcv_30_Rtl9010_Wakeup
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_EthTrcvType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcv[2];
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcvRtl9010
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcvRtl9010
  \brief  Rtl9010 specific configuration data.
  \details
  Element                Description
  Derivative             Rtl9010AA-Vx derivative
  DrivingStrength        RGMII Driving Strength
  IOPower                RGMII I/O Power Level
  RxcDelayEnable         RGMII delay for Rxc
  RxcDelayValue          RxcDelay level selection
  SoftResetWaitCycles    Soft reset wait cycles
  TxcDelayEnable         RGMII delay for Txc
  TxcDelayValue          TxcDelay level selection
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010Type, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  \brief  Rtl9010Ax specific configuration data related to Erratum handling.
  \details
  Element           Description
  Erratum1Active    Indicates if Erratum #1 is active.
  Erratum2Active    Indicates if Erratum #2 is active.
  Erratum3Active    Indicates if Erratum #3 is active.
  Erratum4Active    Indicates if Erratum #4 is active.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  \brief  Hardware access monitor failure callouts to application.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_UserHwAccessMonitorFailureCalloutFctPtrType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_UserAccessCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_UserAccessCallouts
  \brief  pretransceiver read/write access callouts to application.
  \details
  Element                      Description
  PreTrcvReadAccessCallout     Pre-Transceiver Read Access callout
  PreTrcvWriteAccessCallout    Pre-Transceiver Write Access callout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_UserAccessCalloutsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserAccessCallouts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_UserInitCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_UserInitCallouts
  \brief  Pre-/Post-Transceiver-Initialization callouts to application.
  \details
  Element                Description
  PostInitUserCallout    Post-Transceiver-Initialization callout
  PreInitUserCallout     Pre-Transceiver-Initialization callout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_UserInitCalloutsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserInitCallouts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_CableDiagnosticState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_CableDiagnosticState
  \brief  State of cable diagnostic.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_CableDiagnosticStateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_CableDiagnosticState[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
  \brief  The Wakeup reason cycle Counter
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error reaction
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error recovery
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessState
  \brief  State of the hardware access state for Transceiver initialization
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_HwAccessStateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessState[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvHwAccessibility
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvHwAccessibility
  \brief  Transceiver hardware accessibility
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Rtl9010_HardwareAccessibilityType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvHwAccessibility[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvLinkState
  \brief  Transceiver link state.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_StateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvLinkState[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvMode
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvMode
  \brief  Transceiver operating mode.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_ModeType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvMode[2];
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvState
  \brief  Transceiver initialization state.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_StateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvState[2];
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_PCConfig
  \details
  Element                                   Description
  AccessEntityFcts                          the pointer to EthTrcv_30_Rtl9010_AccessEntityFcts
  CableDiagnosticState                      the pointer to EthTrcv_30_Rtl9010_CableDiagnosticState
  EthTrcv                                   the pointer to EthTrcv_30_Rtl9010_EthTrcv
  EthTrcvRtl9010                            the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010
  EthTrcvRtl9010AxErrataHdlr                the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  HwAccessMonitorCycleCounter               the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
  HwAccessMonitorFailureCallout             the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  HwAccessMonitorFailureDebounceCounter     the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
  HwAccessMonitorRecoveryDebounceCounter    the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
  HwAccessState                             the pointer to EthTrcv_30_Rtl9010_HwAccessState
  TrcvHwAccessibility                       the pointer to EthTrcv_30_Rtl9010_TrcvHwAccessibility
  TrcvLinkState                             the pointer to EthTrcv_30_Rtl9010_TrcvLinkState
  TrcvMode                                  the pointer to EthTrcv_30_Rtl9010_TrcvMode
  TrcvState                                 the pointer to EthTrcv_30_Rtl9010_TrcvState
  UserAccessCallouts                        the pointer to EthTrcv_30_Rtl9010_UserAccessCallouts
  UserInitCallouts                          the pointer to EthTrcv_30_Rtl9010_UserInitCallouts
  Wakeup                                    the pointer to EthTrcv_30_Rtl9010_Wakeup
  WakeupCallout                             the pointer to EthTrcv_30_Rtl9010_WakeupCallout
  WakeupMap                                 the pointer to EthTrcv_30_Rtl9010_WakeupMap
  WakeupMode                                the pointer to EthTrcv_30_Rtl9010_WakeupMode
  WakeupReasonFlags                         the pointer to EthTrcv_30_Rtl9010_WakeupReasonFlags
  WakeupVerificationCallout                 the pointer to EthTrcv_30_Rtl9010_WakeupVerificationCallout
  CableDiagLoopCycles                       Maximum tries the driver performs to get results during cable diagnostics.
  HwAccessLoopCount                         Maximum tries the driver performs to access the hardware.
  HwAccessMonitorFailureDebounceLimiter     The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  HwAccessMonitorLoopLimiter                The loop limiter value to realize the period of the hardware access check in relation to the main function period
  HwAccessMonitorRecoveryDebounceLimiter    The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  MaxPhySignalQualityMean                   Maximum physical signal quality mean configured for the Ethernet transceivers
  SizeOfAccessEntityFcts                    the number of accomplishable value elements in EthTrcv_30_Rtl9010_AccessEntityFcts
  SizeOfEthTrcv                             the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcv
  SizeOfEthTrcvRtl9010                      the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010
  SizeOfEthTrcvRtl9010AxErrataHdlr          the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  SizeOfHwAccessMonitorFailureCallout       the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  SizeOfUserAccessCallouts                  the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserAccessCallouts
  SizeOfUserInitCallouts                    the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserInitCallouts
  SizeOfWakeup                              the number of accomplishable value elements in EthTrcv_30_Rtl9010_Wakeup
  SizeOfWakeupCallout                       the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupCallout
  SizeOfWakeupMap                           the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupMap
  SizeOfWakeupVerificationCallout           the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupVerificationCallout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Rtl9010_PCConfigsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_PCConfig;
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#endif /* ETHTRCV_30_RTL9010_GENTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Rtl9010_GenTypes.h
 *********************************************************************************************************************/


