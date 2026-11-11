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
 *              File: EthTrcv_30_Tja1103_GenTypes.h
 *   Generation Time: 2026-09-03 22:28:16
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


#if !defined (ETHTRCV_30_TJA1103_GENTYPES_H)
# define ETHTRCV_30_TJA1103_GENTYPES_H

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
  \defgroup  EthTrcv_30_Tja1103PCNonComStackLibTypes  EthTrcv_30_Tja1103 Non ComStackLib Types (PRE_COMPILE)
  \brief  These type definitions are provided by the EthTrcv_30_Tja1103 itself.
  \{
*/ 

/**   \brief  uint8 type for the hardware accessability */
typedef uint8 EthTrcv_30_Tja1103_HardwareAccessibilityType;

/**   \brief  uint8 type for the debounce counter of hardware access monitor failure */
typedef uint8 EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterType;

/**   \brief  uint8 type for the debounce counter of hardware access monitor recovery */
typedef uint8 EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterType;

/**   \brief  uint8 type for the cable diagnostic state */
typedef uint8 EthTrcv_30_Tja1103_CableDiagnosticStateType;

/**   \brief  bitfield type defintion for wakeup reason recognition */
typedef uint8 EthTrcv_30_Tja1103_WakeupReasonFlagsType;

/**   \brief  function pointer type defintion for register read accesses */
typedef P2FUNC(Std_ReturnType, ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_ReadTrcvRegFctPtrType)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);

/**   \brief  function pointer type defintion for register write accesses */
typedef P2FUNC(Std_ReturnType, ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_WriteTrcvRegFctPtrType)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal);

/**   \brief  function pointer type defintion for <User>_PreTransceiverInitCallout() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserPreTrcvInitCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PostTransceiverInitCallout() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserPostTrcvInitCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_WakeupCallout() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserWakeupCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_WakeupVerificationCallout() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserWakeupVerificationCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_HwAccessMonitorFailureCalloutFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserHwAccessMonitorFailureCalloutFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PreTrcvReadCalloutsFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserPreTrcvReadCalloutsFctPtrType)(uint8 TrcvIdx);

/**   \brief  function pointer type defintion for <User>_PreTrcvWriteCalloutsFctPtrType() */
typedef P2FUNC(void,           ETHTRCV_30_TJA1103_APPL_CODE, EthTrcv_30_Tja1103_UserPreTrcvWriteCalloutsFctPtrType)(uint8 TrcvIdx);




/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Tja1103PCDataSwitches  EthTrcv_30_Tja1103 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ETHTRCV_30_TJA1103_ACCESSENTITYFCTS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_READTRCVREGOFACCESSENTITYFCTS                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WRITETRCVREGOFACCESSENTITYFCTS                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ADDRXSAREQUEST                                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ACTIVEOFADDRXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.Active' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ADDRXSAREQUESTPENDINGOFADDRXSAREQUEST                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.AddRxSaRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ANOFADDRXSAREQUEST                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.An' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_KEYSOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.Keys' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_LOWESTPNOFADDRXSAREQUEST                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.LowestPn' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_REQUESTEDBYSWITCHOFADDRXSAREQUEST                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_SSCIOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest.Ssci' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ADDTXSAREQUEST                                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ACTIVEOFADDTXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.Active' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ADDTXSAREQUESTPENDINGOFADDTXSAREQUEST                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.AddTxSaRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ANOFADDTXSAREQUEST                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.An' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_KEYSOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.Keys' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_NEXTPNOFADDTXSAREQUEST                                                   STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.NextPn' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_REQUESTEDBYSWITCHOFADDTXSAREQUEST                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_SSCIOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest.Ssci' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_CABLEDIAGLOOPCYCLES                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_CABLEDIAGNOSTICSTATE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ETHTRCV                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ACCESSENTITYFCTSIDXOFETHTRCV                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ACCESSENTITYSNVOFETHTRCV                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ADDRESSINGIDXOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_AUTONEGENABLEDOFETHTRCV                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_BASICCTRLREGVALOFETHTRCV                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_CONNECTIONNEGOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_DEMEACCESSEVENTIDOFETHTRCV                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORENABLEDOFETHTRCV                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_MACSECENABLEDOFETHTRCV                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_MIIMODEOFETHTRCV                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_PHYSIGNALQUALITYMEANOFETHTRCV                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SOCBASEREGADDROFETHTRCV                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SOFTRESETONINITENABLEDOFETHTRCV                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SOFTRESETWAITCYCLESOFETHTRCV                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SPEEDOFETHTRCV                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPIDXOFETHTRCV                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPUSEDOFETHTRCV                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ETHTRCVTJA1103                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_DERIVATIVEOFETHTRCVTJA1103                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ETHTRCVTJA1103MACSEC                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSec' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ETHTRCV_30_TJA1103_ETHTRCVTJA1103MACSECCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSecConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ETHTRCV_30_TJA1103_FINALMAGICNUMBER                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_TJA1103_GETMACSECSTATSREQUEST                                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_GETMACSECSTATSREQUESTPENDINGOFGETMACSECSTATSREQUEST                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest.GetMacSecStatsRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_REQUESTEDBYSWITCHOFGETMACSECSTATSREQUEST                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_STATSOFGETMACSECSTATSREQUEST                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest.Stats' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_HWACCESSLOOPCOUNT                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORCYCLECOUNTER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILURECALLOUT                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILUREDEBOUNCECOUNTER                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILUREDEBOUNCELIMITER                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORLOOPLIMITER                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORRECOVERYDEBOUNCECOUNTER                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORRECOVERYDEBOUNCELIMITER                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_INITDATAHASHCODE                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_TJA1103_MACSECCONFIG                                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecConfig' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ALWAYSINCLUDESCIOFMACSECCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecConfig.AlwaysIncludeSCI' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_USEESOFMACSECCONFIG                                                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecConfig.UseES' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_MACSECDATA                                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecData' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ETHIFCTRLIDXOFMACSECDATA                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecData.EthIfCtrlIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_KEYSIZEOFMACSECDATA                                                      STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_MacSecData.KeySize' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_MAXPHYSIGNALQUALITYMEAN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_POLSWAPCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_POLARITYSWAPOFPOLSWAPCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFACCESSENTITYFCTS                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFADDRXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfAddRxSaRequest' Reason: 'Deactivateable: 'AddRxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFADDTXSAREQUEST                                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfAddTxSaRequest' Reason: 'Deactivateable: 'AddTxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFCABLEDIAGNOSTICSTATE                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCV                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103MACSEC                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfEthTrcvTja1103MacSec' Reason: 'Deactivateable: 'EthTrcvTja1103MacSec' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSec' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103MACSECCONFIG                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfEthTrcvTja1103MacSecConfig' Reason: 'Deactivateable: 'EthTrcvTja1103MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSecConfig' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_TJA1103_SIZEOFGETMACSECSTATSREQUEST                                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfGetMacSecStatsRequest' Reason: 'Deactivateable: 'GetMacSecStatsRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORFAILURECALLOUT                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORFAILUREDEBOUNCECOUNTER                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORRECOVERYDEBOUNCECOUNTER                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFMACSECCONFIG                                                       STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfMacSecConfig' Reason: 'Deactivateable: 'MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_MacSecConfig' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFMACSECDATA                                                         STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfMacSecData' Reason: 'Deactivateable: 'MacSecData' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_MacSecData' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFPOLSWAPCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFSMICONFIGURATION                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFSWITCHMACSECAPI                                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfSwitchMacSecApi' Reason: 'Deactivateable: 'SwitchMacSecApi' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVHWACCESSIBILITY                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVLINKSTATE                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVMODE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVRGMIICONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVSTATE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFUPDATESECYREQUEST                                                  STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SizeOfUpdateSecYRequest' Reason: 'Deactivateable: 'UpdateSecYRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFUSERACCESSCALLOUTS                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFUSERINITCALLOUTS                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPCALLOUT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPMAP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPMODE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPREASONFLAGS                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPVERIFICATIONCALLOUT                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFXMIICLKIOCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFXMIIDATAIOCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SMICONFIGURATION                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SMIIDLEPRECHARGEENABLEDOFSMICONFIGURATION                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SWITCHMACSECAPI                                                          STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ADDRXSANOTIFICATIONOFSWITCHMACSECAPI                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.AddRxSaNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_ADDTXSANOTIFICATIONOFSWITCHMACSECAPI                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.AddTxSaNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_GETMACSECSTATSNOTIFICATIONOFSWITCHMACSECAPI                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.GetMacSecStatsNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_PORTIDXOFSWITCHMACSECAPI                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.PortIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_SWITCHIDXOFSWITCHMACSECAPI                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.SwitchIdx' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_UPDATESECYNOTIFICATIONOFSWITCHMACSECAPI                                  STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi.UpdateSecYNotification' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_TRCVHWACCESSIBILITY                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVLINKSTATE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVMODE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVRGMIICONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVSTATE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_UPDATESECYREQUEST                                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_MACSECCFGOFUPDATESECYREQUEST                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest.MacSecCfg' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_REQUESTEDBYSWITCHOFUPDATESECYREQUEST                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest.RequestedBySwitch' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_TXSCIOFUPDATESECYREQUEST                                                 STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest.TxSCI' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_UPDATESECYREQUESTPENDINGOFUPDATESECYREQUEST                              STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest.UpdateSecYRequestPending' Reason: 'MacSec Deactivated' */
#define ETHTRCV_30_TJA1103_USERACCESSCALLOUTS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_USERINITCALLOUTS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_PREINITUSERCALLOUTOFUSERINITCALLOUTS                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ICUCHANNELOFWAKEUP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPCALLOUTIDXOFWAKEUP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPCALLOUTUSEDOFWAKEUP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPINSPECTIONTYPEOFWAKEUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMAPENDIDXOFWAKEUP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMAPSTARTIDXOFWAKEUP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMAPUSEDOFWAKEUP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPCALLOUT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMAP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ECUMWAKEUPSOURCEOFWAKEUPMAP                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPREASONOFWAKEUPMAP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMODE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPREASONFLAGS                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPVERIFICATIONCALLOUT                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_XMIICLKIOCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SLEWRATEOFXMIICLKIOCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_XMIIDATAIOCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SLEWRATEOFXMIIDATAIOCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_PCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ACCESSENTITYFCTSOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_CABLEDIAGLOOPCYCLESOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_CABLEDIAGNOSTICSTATEOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ETHTRCVOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_ETHTRCVTJA1103OFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_FINALMAGICNUMBEROFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_TJA1103_HWACCESSLOOPCOUNTOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_INITDATAHASHCODEOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTRCV_30_TJA1103_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_POLSWAPCONFIGOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFADDRXSAREQUESTOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfAddRxSaRequest' Reason: 'Deactivateable: 'AddRxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_AddRxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFADDTXSAREQUESTOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfAddTxSaRequest' Reason: 'Deactivateable: 'AddTxSaRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_AddTxSaRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFCABLEDIAGNOSTICSTATEOFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103MACSECCONFIGOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfEthTrcvTja1103MacSecConfig' Reason: 'Deactivateable: 'EthTrcvTja1103MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSecConfig' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103MACSECOFPCCONFIG                                     STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfEthTrcvTja1103MacSec' Reason: 'Deactivateable: 'EthTrcvTja1103MacSec' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_EthTrcvTja1103MacSec' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTRCV_30_TJA1103_SIZEOFETHTRCVTJA1103OFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFGETMACSECSTATSREQUESTOFPCCONFIG                                    STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfGetMacSecStatsRequest' Reason: 'Deactivateable: 'GetMacSecStatsRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_GetMacSecStatsRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFHWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFMACSECCONFIGOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfMacSecConfig' Reason: 'Deactivateable: 'MacSecConfig' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_MacSecConfig' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFMACSECDATAOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfMacSecData' Reason: 'Deactivateable: 'MacSecData' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_MacSecData' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFPOLSWAPCONFIGOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFSMICONFIGURATIONOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFSWITCHMACSECAPIOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfSwitchMacSecApi' Reason: 'Deactivateable: 'SwitchMacSecApi' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_SwitchMacSecApi' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVHWACCESSIBILITYOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVLINKSTATEOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVMODEOFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVRGMIICONFIGOFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFTRCVSTATEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFUPDATESECYREQUESTOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'EthTrcv_30_Tja1103_PCConfig.SizeOfUpdateSecYRequest' Reason: 'Deactivateable: 'UpdateSecYRequest' Reason: 'Deactivateable: 'EthTrcv_30_Tja1103_UpdateSecYRequest' Reason: 'MacSec Deactivated''' */
#define ETHTRCV_30_TJA1103_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPMAPOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPMODEOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPREASONFLAGSOFPCCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFXMIICLKIOCONFIGOFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SIZEOFXMIIDATAIOCONFIGOFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_SMICONFIGURATIONOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVHWACCESSIBILITYOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVLINKSTATEOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVMODEOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVRGMIICONFIGOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_TRCVSTATEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_USERACCESSCALLOUTSOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_USERINITCALLOUTSOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPCALLOUTOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMAPOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPMODEOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPREASONFLAGSOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_XMIICLKIOCONFIGOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTRCV_30_TJA1103_XMIIDATAIOCONFIGOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCMinNumericValueDefines  EthTrcv_30_Tja1103 Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define ETHTRCV_30_TJA1103_MIN_HWACCESSMONITORCYCLECOUNTER                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCMaxNumericValueDefines  EthTrcv_30_Tja1103 Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define ETHTRCV_30_TJA1103_MAX_HWACCESSMONITORCYCLECOUNTER                                          65535u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCNoReferenceDefines  EthTrcv_30_Tja1103 No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define ETHTRCV_30_TJA1103_NO_WAKEUPIDXOFETHTRCV                                                    255u
#define ETHTRCV_30_TJA1103_NO_WAKEUPCALLOUTIDXOFWAKEUP                                              255u
#define ETHTRCV_30_TJA1103_NO_WAKEUPMAPENDIDXOFWAKEUP                                               255u
#define ETHTRCV_30_TJA1103_NO_WAKEUPMAPSTARTIDXOFWAKEUP                                             255u
#define ETHTRCV_30_TJA1103_NO_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCEnumExistsDefines  EthTrcv_30_Tja1103 Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define ETHTRCV_30_TJA1103_EXISTS_CONN_NEG_AUTO_CONNECTIONNEGOFETHTRCV                              STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CONN_NEG_MASTER_CONNECTIONNEGOFETHTRCV                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV                             STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CONN_NEG_NONE_CONNECTIONNEGOFETHTRCV                              STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_INTERNAL_PHY_MIIMODEOFETHTRCV                                     STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_MII_MODE_MIIMODEOFETHTRCV                                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_LIGHT_MII_MODE_MIIMODEOFETHTRCV                                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_RMII_MODE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_RGMII_MODE_MIIMODEOFETHTRCV                                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_GMII_MODE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_RMII_XTAL_MODE_MIIMODEOFETHTRCV                                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_RGMII_XTAL_MODE_MIIMODEOFETHTRCV                                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_STRAPPING_CONFIG_ONLY_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SGMII_MODE_MIIMODEOFETHTRCV                                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SERDES_2500BASE_X_MODE_MIIMODEOFETHTRCV                           STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SERDES_5GBASE_R_MODE_MIIMODEOFETHTRCV                             STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SERDES_10GBASE_R_MODE_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SERDES_5GUSXGMII_MODE_MIIMODEOFETHTRCV                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SERDES_10GUSXGMII_MODE_MIIMODEOFETHTRCV                           STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DONT_CARE_MIIMODEOFETHTRCV                                        STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_REVERSE_MII_MODE_MIIMODEOFETHTRCV                                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_REVERSE_RMII_MODE_MIIMODEOFETHTRCV                                STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_10_SPEEDOFETHTRCV                                      STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_100_SPEEDOFETHTRCV                                     STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_1000_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_2500_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_5000_SPEEDOFETHTRCV                                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_SPEED_10000_SPEEDOFETHTRCV                                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TJA1103A_DERIVATIVEOFETHTRCVTJA1103                               STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TJA1103B_DERIVATIVEOFETHTRCVTJA1103                               STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TJA1104A_DERIVATIVEOFETHTRCVTJA1103                               STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TJA1104B_DERIVATIVEOFETHTRCVTJA1103                               STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_POL_CORRECTION_POLARITYSWAPOFPOLSWAPCONFIG                        STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_POL_NO_CORRECTION_POLARITYSWAPOFPOLSWAPCONFIG                     STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_POL_CORRECTION_PLUS_FORCED_POL_SWAP_POLARITYSWAPOFPOLSWAPCONFIG   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_POL_NO_CORRECTION_PLUS_FORCED_POL_SWAP_POLARITYSWAPOFPOLSWAPCONFIG STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_POL_INVALID_POLARITYSWAPOFPOLSWAPCONFIG                           STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_73_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_74_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_75_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_76_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_77_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_78_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_79_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_80_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_81_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_81_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_82_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_83_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_84_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_85_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_86_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_87_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_88_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_89_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_90_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_90_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_91_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_92_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_93_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_94_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_95_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_96_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_97_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_98_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_99_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_99_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_100_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_101_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_INVALID_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_73_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_74_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_75_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_76_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_77_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_78_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_79_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_80_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_81_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_81_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_82_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_83_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_84_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_85_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_86_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_87_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_88_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_89_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_90_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_90_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_91_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_92_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_93_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_94_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_95_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_96_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_97_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_98_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_99_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                    STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_99_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                  STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_100_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_101_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_SHIFT_INVALID_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_ICU_CHANNEL_WAKEUPINSPECTIONTYPEOFWAKEUP                          STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_TRCV_REGISTERS_WAKEUPINSPECTIONTYPEOFWAKEUP                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_USER_CODE_WAKEUPINSPECTIONTYPEOFWAKEUP                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DONT_CARE_WAKEUPINSPECTIONTYPEOFWAKEUP                            STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_GENERAL_WAKEUPREASONOFWAKEUPMAP                               STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_BUS_WAKEUPREASONOFWAKEUPMAP                                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_INTERNAL_WAKEUPREASONOFWAKEUPMAP                              STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_RESET_WAKEUPREASONOFWAKEUPMAP                                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_POWER_ON_WAKEUPREASONOFWAKEUPMAP                              STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_PIN_WAKEUPREASONOFWAKEUPMAP                                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_WUR_SYSERR_WAKEUPREASONOFWAKEUPMAP                                STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_0_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_1_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_2_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_3_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_4_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_5_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_6_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_7_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIICLKIOCONFIG             STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_0_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_1_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_2_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_3_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_4_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_5_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_6_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_7_SLEWRATEOFXMIICLKIOCONFIG                         STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_CLK_SLEW_RATE_INVALID_SLEWRATEOFXMIICLKIOCONFIG                   STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_0_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_1_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_2_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_3_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_4_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_5_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_6_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_7_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                 STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG           STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_0_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_1_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_2_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_3_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_4_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_5_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_6_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_7_SLEWRATEOFXMIIDATAIOCONFIG                       STD_ON
#define ETHTRCV_30_TJA1103_EXISTS_DATA_SLEW_RATE_INVALID_SLEWRATEOFXMIIDATAIOCONFIG                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCEnumDefines  EthTrcv_30_Tja1103 Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define ETHTRCV_30_TJA1103_CONN_NEG_AUTO_CONNECTIONNEGOFETHTRCV                                     0x00u
#define ETHTRCV_30_TJA1103_CONN_NEG_MASTER_CONNECTIONNEGOFETHTRCV                                   0x01u
#define ETHTRCV_30_TJA1103_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV                                    0x02u
#define ETHTRCV_30_TJA1103_CONN_NEG_NONE_CONNECTIONNEGOFETHTRCV                                     0x03u
#define ETHTRCV_30_TJA1103_INTERNAL_PHY_MIIMODEOFETHTRCV                                            0x00u
#define ETHTRCV_30_TJA1103_MII_MODE_MIIMODEOFETHTRCV                                                0x01u
#define ETHTRCV_30_TJA1103_LIGHT_MII_MODE_MIIMODEOFETHTRCV                                          0x02u
#define ETHTRCV_30_TJA1103_RMII_MODE_MIIMODEOFETHTRCV                                               0x03u
#define ETHTRCV_30_TJA1103_RGMII_MODE_MIIMODEOFETHTRCV                                              0x04u
#define ETHTRCV_30_TJA1103_GMII_MODE_MIIMODEOFETHTRCV                                               0x05u
#define ETHTRCV_30_TJA1103_RMII_XTAL_MODE_MIIMODEOFETHTRCV                                          0x06u
#define ETHTRCV_30_TJA1103_RGMII_XTAL_MODE_MIIMODEOFETHTRCV                                         0x07u
#define ETHTRCV_30_TJA1103_STRAPPING_CONFIG_ONLY_MIIMODEOFETHTRCV                                   0x08u
#define ETHTRCV_30_TJA1103_SGMII_MODE_MIIMODEOFETHTRCV                                              0x09u
#define ETHTRCV_30_TJA1103_SERDES_2500BASE_X_MODE_MIIMODEOFETHTRCV                                  0x0Au
#define ETHTRCV_30_TJA1103_SERDES_5GBASE_R_MODE_MIIMODEOFETHTRCV                                    0x0Bu
#define ETHTRCV_30_TJA1103_SERDES_10GBASE_R_MODE_MIIMODEOFETHTRCV                                   0x0Cu
#define ETHTRCV_30_TJA1103_SERDES_5GUSXGMII_MODE_MIIMODEOFETHTRCV                                   0x0Du
#define ETHTRCV_30_TJA1103_SERDES_10GUSXGMII_MODE_MIIMODEOFETHTRCV                                  0x0Eu
#define ETHTRCV_30_TJA1103_DONT_CARE_MIIMODEOFETHTRCV                                               0x0Fu
#define ETHTRCV_30_TJA1103_REVERSE_MII_MODE_MIIMODEOFETHTRCV                                        0x10u
#define ETHTRCV_30_TJA1103_REVERSE_RMII_MODE_MIIMODEOFETHTRCV                                       0x11u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_10_SPEEDOFETHTRCV                                             0x00u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_100_SPEEDOFETHTRCV                                            0x01u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_1000_SPEEDOFETHTRCV                                           0x02u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_2500_SPEEDOFETHTRCV                                           0x03u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_5000_SPEEDOFETHTRCV                                           0x04u
#define ETHTRCV_30_TJA1103_TRCV_SPEED_10000_SPEEDOFETHTRCV                                          0x05u
#define ETHTRCV_30_TJA1103_TJA1103A_DERIVATIVEOFETHTRCVTJA1103                                      0x00u
#define ETHTRCV_30_TJA1103_TJA1103B_DERIVATIVEOFETHTRCVTJA1103                                      0x01u
#define ETHTRCV_30_TJA1103_TJA1104A_DERIVATIVEOFETHTRCVTJA1103                                      0x02u
#define ETHTRCV_30_TJA1103_TJA1104B_DERIVATIVEOFETHTRCVTJA1103                                      0x03u
#define ETHTRCV_30_TJA1103_POL_CORRECTION_POLARITYSWAPOFPOLSWAPCONFIG                               0x00u
#define ETHTRCV_30_TJA1103_POL_NO_CORRECTION_POLARITYSWAPOFPOLSWAPCONFIG                            0x01u
#define ETHTRCV_30_TJA1103_POL_CORRECTION_PLUS_FORCED_POL_SWAP_POLARITYSWAPOFPOLSWAPCONFIG          0x02u
#define ETHTRCV_30_TJA1103_POL_NO_CORRECTION_PLUS_FORCED_POL_SWAP_POLARITYSWAPOFPOLSWAPCONFIG       0x03u
#define ETHTRCV_30_TJA1103_POL_INVALID_POLARITYSWAPOFPOLSWAPCONFIG                                  0x04u
#define ETHTRCV_30_TJA1103_SHIFT_73_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x00u
#define ETHTRCV_30_TJA1103_SHIFT_74_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x01u
#define ETHTRCV_30_TJA1103_SHIFT_75_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x02u
#define ETHTRCV_30_TJA1103_SHIFT_76_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x03u
#define ETHTRCV_30_TJA1103_SHIFT_77_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x04u
#define ETHTRCV_30_TJA1103_SHIFT_78_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x05u
#define ETHTRCV_30_TJA1103_SHIFT_79_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x06u
#define ETHTRCV_30_TJA1103_SHIFT_80_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x07u
#define ETHTRCV_30_TJA1103_SHIFT_81_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x08u
#define ETHTRCV_30_TJA1103_SHIFT_81_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x09u
#define ETHTRCV_30_TJA1103_SHIFT_82_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Au
#define ETHTRCV_30_TJA1103_SHIFT_83_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Bu
#define ETHTRCV_30_TJA1103_SHIFT_84_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Cu
#define ETHTRCV_30_TJA1103_SHIFT_85_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Du
#define ETHTRCV_30_TJA1103_SHIFT_86_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Eu
#define ETHTRCV_30_TJA1103_SHIFT_87_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Fu
#define ETHTRCV_30_TJA1103_SHIFT_88_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x10u
#define ETHTRCV_30_TJA1103_SHIFT_89_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x11u
#define ETHTRCV_30_TJA1103_SHIFT_90_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x12u
#define ETHTRCV_30_TJA1103_SHIFT_90_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x13u
#define ETHTRCV_30_TJA1103_SHIFT_91_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x14u
#define ETHTRCV_30_TJA1103_SHIFT_92_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x15u
#define ETHTRCV_30_TJA1103_SHIFT_93_6_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x16u
#define ETHTRCV_30_TJA1103_SHIFT_94_5_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x17u
#define ETHTRCV_30_TJA1103_SHIFT_95_4_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x18u
#define ETHTRCV_30_TJA1103_SHIFT_96_3_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x19u
#define ETHTRCV_30_TJA1103_SHIFT_97_2_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Au
#define ETHTRCV_30_TJA1103_SHIFT_98_1_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Bu
#define ETHTRCV_30_TJA1103_SHIFT_99_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x1Cu
#define ETHTRCV_30_TJA1103_SHIFT_99_9_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Du
#define ETHTRCV_30_TJA1103_SHIFT_100_8_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                        0x1Eu
#define ETHTRCV_30_TJA1103_SHIFT_101_7_DEG_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                        0x1Fu
#define ETHTRCV_30_TJA1103_SHIFT_INVALID_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                          0x20u
#define ETHTRCV_30_TJA1103_SHIFT_73_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x00u
#define ETHTRCV_30_TJA1103_SHIFT_74_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x01u
#define ETHTRCV_30_TJA1103_SHIFT_75_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x02u
#define ETHTRCV_30_TJA1103_SHIFT_76_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x03u
#define ETHTRCV_30_TJA1103_SHIFT_77_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x04u
#define ETHTRCV_30_TJA1103_SHIFT_78_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x05u
#define ETHTRCV_30_TJA1103_SHIFT_79_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x06u
#define ETHTRCV_30_TJA1103_SHIFT_80_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x07u
#define ETHTRCV_30_TJA1103_SHIFT_81_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x08u
#define ETHTRCV_30_TJA1103_SHIFT_81_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x09u
#define ETHTRCV_30_TJA1103_SHIFT_82_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Au
#define ETHTRCV_30_TJA1103_SHIFT_83_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Bu
#define ETHTRCV_30_TJA1103_SHIFT_84_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Cu
#define ETHTRCV_30_TJA1103_SHIFT_85_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Du
#define ETHTRCV_30_TJA1103_SHIFT_86_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Eu
#define ETHTRCV_30_TJA1103_SHIFT_87_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x0Fu
#define ETHTRCV_30_TJA1103_SHIFT_88_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x10u
#define ETHTRCV_30_TJA1103_SHIFT_89_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x11u
#define ETHTRCV_30_TJA1103_SHIFT_90_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x12u
#define ETHTRCV_30_TJA1103_SHIFT_90_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x13u
#define ETHTRCV_30_TJA1103_SHIFT_91_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x14u
#define ETHTRCV_30_TJA1103_SHIFT_92_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x15u
#define ETHTRCV_30_TJA1103_SHIFT_93_6_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x16u
#define ETHTRCV_30_TJA1103_SHIFT_94_5_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x17u
#define ETHTRCV_30_TJA1103_SHIFT_95_4_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x18u
#define ETHTRCV_30_TJA1103_SHIFT_96_3_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x19u
#define ETHTRCV_30_TJA1103_SHIFT_97_2_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Au
#define ETHTRCV_30_TJA1103_SHIFT_98_1_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Bu
#define ETHTRCV_30_TJA1103_SHIFT_99_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                           0x1Cu
#define ETHTRCV_30_TJA1103_SHIFT_99_9_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                         0x1Du
#define ETHTRCV_30_TJA1103_SHIFT_100_8_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                        0x1Eu
#define ETHTRCV_30_TJA1103_SHIFT_101_7_DEG_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                        0x1Fu
#define ETHTRCV_30_TJA1103_SHIFT_INVALID_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                          0x20u
#define ETHTRCV_30_TJA1103_ICU_CHANNEL_WAKEUPINSPECTIONTYPEOFWAKEUP                                 0x00u
#define ETHTRCV_30_TJA1103_TRCV_REGISTERS_WAKEUPINSPECTIONTYPEOFWAKEUP                              0x01u
#define ETHTRCV_30_TJA1103_USER_CODE_WAKEUPINSPECTIONTYPEOFWAKEUP                                   0x02u
#define ETHTRCV_30_TJA1103_DONT_CARE_WAKEUPINSPECTIONTYPEOFWAKEUP                                   0x03u
#define ETHTRCV_30_TJA1103_WUR_GENERAL_WAKEUPREASONOFWAKEUPMAP                                      0x01u
#define ETHTRCV_30_TJA1103_WUR_BUS_WAKEUPREASONOFWAKEUPMAP                                          0x02u
#define ETHTRCV_30_TJA1103_WUR_INTERNAL_WAKEUPREASONOFWAKEUPMAP                                     0x03u
#define ETHTRCV_30_TJA1103_WUR_RESET_WAKEUPREASONOFWAKEUPMAP                                        0x04u
#define ETHTRCV_30_TJA1103_WUR_POWER_ON_WAKEUPREASONOFWAKEUPMAP                                     0x05u
#define ETHTRCV_30_TJA1103_WUR_PIN_WAKEUPREASONOFWAKEUPMAP                                          0x06u
#define ETHTRCV_30_TJA1103_WUR_SYSERR_WAKEUPREASONOFWAKEUPMAP                                       0x07u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_0_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x00u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_1_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x01u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_2_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x02u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_3_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x03u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_4_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x04u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_5_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x05u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_6_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x06u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_7_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                          0x07u
#define ETHTRCV_30_TJA1103_CLK_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                    0x08u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_0_SLEWRATEOFXMIICLKIOCONFIG                                0x00u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_1_SLEWRATEOFXMIICLKIOCONFIG                                0x01u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_2_SLEWRATEOFXMIICLKIOCONFIG                                0x02u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_3_SLEWRATEOFXMIICLKIOCONFIG                                0x03u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_4_SLEWRATEOFXMIICLKIOCONFIG                                0x04u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_5_SLEWRATEOFXMIICLKIOCONFIG                                0x05u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_6_SLEWRATEOFXMIICLKIOCONFIG                                0x06u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_7_SLEWRATEOFXMIICLKIOCONFIG                                0x07u
#define ETHTRCV_30_TJA1103_CLK_SLEW_RATE_INVALID_SLEWRATEOFXMIICLKIOCONFIG                          0x08u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_0_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x00u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_1_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x01u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_2_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x02u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_3_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x03u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_4_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x04u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_5_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x05u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_6_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x06u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_7_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                        0x07u
#define ETHTRCV_30_TJA1103_DATA_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                  0x08u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_0_SLEWRATEOFXMIIDATAIOCONFIG                              0x00u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_1_SLEWRATEOFXMIIDATAIOCONFIG                              0x01u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_2_SLEWRATEOFXMIIDATAIOCONFIG                              0x02u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_3_SLEWRATEOFXMIIDATAIOCONFIG                              0x03u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_4_SLEWRATEOFXMIIDATAIOCONFIG                              0x04u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_5_SLEWRATEOFXMIIDATAIOCONFIG                              0x05u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_6_SLEWRATEOFXMIIDATAIOCONFIG                              0x06u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_7_SLEWRATEOFXMIIDATAIOCONFIG                              0x07u
#define ETHTRCV_30_TJA1103_DATA_SLEW_RATE_INVALID_SLEWRATEOFXMIIDATAIOCONFIG                        0x08u
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCIsReducedToDefineDefines  EthTrcv_30_Tja1103 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ETHTRCV_30_TJA1103_ISDEF_READTRCVREGOFACCESSENTITYFCTS                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WRITETRCVREGOFACCESSENTITYFCTS                                     STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ACCESSENTITYFCTSIDXOFETHTRCV                                       STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ACCESSENTITYSNVOFETHTRCV                                           STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ADDRESSINGIDXOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_AUTONEGENABLEDOFETHTRCV                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_BASICCTRLREGVALOFETHTRCV                                           STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_CONNECTIONNEGOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_DEMEACCESSEVENTIDOFETHTRCV                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORENABLEDOFETHTRCV                                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_MACSECENABLEDOFETHTRCV                                             STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_MIIMODEOFETHTRCV                                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_PHYSIGNALQUALITYMEANOFETHTRCV                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SOCBASEREGADDROFETHTRCV                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SOFTRESETONINITENABLEDOFETHTRCV                                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SOFTRESETWAITCYCLESOFETHTRCV                                       STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SPEEDOFETHTRCV                                                     STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPIDXOFETHTRCV                                                 STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPUSEDOFETHTRCV                                                STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_DERIVATIVEOFETHTRCVTJA1103                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORFAILURECALLOUT                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_POLARITYSWAPOFPOLSWAPCONFIG                                        STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SMIIDLEPRECHARGEENABLEDOFSMICONFIGURATION                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                  STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                  STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                       STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                              STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_PREINITUSERCALLOUTOFUSERINITCALLOUTS                               STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ICUCHANNELOFWAKEUP                                                 STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPCALLOUTIDXOFWAKEUP                                           STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPCALLOUTUSEDOFWAKEUP                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPINSPECTIONTYPEOFWAKEUP                                       STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPMAPENDIDXOFWAKEUP                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPMAPSTARTIDXOFWAKEUP                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPMAPUSEDOFWAKEUP                                              STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                               STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                              STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPCALLOUT                                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ECUMWAKEUPSOURCEOFWAKEUPMAP                                        STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPREASONOFWAKEUPMAP                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPVERIFICATIONCALLOUT                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SLEWRATEOFXMIICLKIOCONFIG                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                                  STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SLEWRATEOFXMIIDATAIOCONFIG                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ACCESSENTITYFCTSOFPCCONFIG                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_CABLEDIAGLOOPCYCLESOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_CABLEDIAGNOSTICSTATEOFPCCONFIG                                     STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ETHTRCVOFPCCONFIG                                                  STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_ETHTRCVTJA1103OFPCCONFIG                                           STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSLOOPCOUNTOFPCCONFIG                                        STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                              STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                               STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                  STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_POLSWAPCONFIGOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFETHTRCVOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFETHTRCVTJA1103OFPCCONFIG                                     STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFPOLSWAPCONFIGOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFSMICONFIGURATIONOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFTRCVRGMIICONFIGOFPCCONFIG                                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                 STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFWAKEUPMAPOFPCCONFIG                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFWAKEUPOFPCCONFIG                                             STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFXMIICLKIOCONFIGOFPCCONFIG                                    STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SIZEOFXMIIDATAIOCONFIGOFPCCONFIG                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_SMICONFIGURATIONOFPCCONFIG                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TRCVHWACCESSIBILITYOFPCCONFIG                                      STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TRCVLINKSTATEOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TRCVMODEOFPCCONFIG                                                 STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TRCVRGMIICONFIGOFPCCONFIG                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_TRCVSTATEOFPCCONFIG                                                STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_USERACCESSCALLOUTSOFPCCONFIG                                       STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_USERINITCALLOUTSOFPCCONFIG                                         STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPCALLOUTOFPCCONFIG                                            STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPMAPOFPCCONFIG                                                STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPMODEOFPCCONFIG                                               STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPOFPCCONFIG                                                   STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPREASONFLAGSOFPCCONFIG                                        STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_XMIICLKIOCONFIGOFPCCONFIG                                          STD_OFF
#define ETHTRCV_30_TJA1103_ISDEF_XMIIDATAIOCONFIGOFPCCONFIG                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCEqualsAlwaysToDefines  EthTrcv_30_Tja1103 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ETHTRCV_30_TJA1103_EQ2_READTRCVREGOFACCESSENTITYFCTS                                        
#define ETHTRCV_30_TJA1103_EQ2_WRITETRCVREGOFACCESSENTITYFCTS                                       
#define ETHTRCV_30_TJA1103_EQ2_ACCESSENTITYFCTSIDXOFETHTRCV                                         
#define ETHTRCV_30_TJA1103_EQ2_ACCESSENTITYSNVOFETHTRCV                                             
#define ETHTRCV_30_TJA1103_EQ2_ADDRESSINGIDXOFETHTRCV                                               
#define ETHTRCV_30_TJA1103_EQ2_AUTONEGENABLEDOFETHTRCV                                              
#define ETHTRCV_30_TJA1103_EQ2_BASICCTRLREGVALOFETHTRCV                                             
#define ETHTRCV_30_TJA1103_EQ2_CONNECTIONNEGOFETHTRCV                                               
#define ETHTRCV_30_TJA1103_EQ2_DEMEACCESSEVENTIDOFETHTRCV                                           
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORENABLEDOFETHTRCV                                      
#define ETHTRCV_30_TJA1103_EQ2_MACSECENABLEDOFETHTRCV                                               
#define ETHTRCV_30_TJA1103_EQ2_MIIMODEOFETHTRCV                                                     
#define ETHTRCV_30_TJA1103_EQ2_PHYSIGNALQUALITYMEANOFETHTRCV                                        
#define ETHTRCV_30_TJA1103_EQ2_SOCBASEREGADDROFETHTRCV                                              
#define ETHTRCV_30_TJA1103_EQ2_SOFTRESETONINITENABLEDOFETHTRCV                                      
#define ETHTRCV_30_TJA1103_EQ2_SOFTRESETWAITCYCLESOFETHTRCV                                         
#define ETHTRCV_30_TJA1103_EQ2_SPEEDOFETHTRCV                                                       
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPIDXOFETHTRCV                                                   
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPUSEDOFETHTRCV                                                  
#define ETHTRCV_30_TJA1103_EQ2_DERIVATIVEOFETHTRCVTJA1103                                           
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORFAILURECALLOUT                                        
#define ETHTRCV_30_TJA1103_EQ2_POLARITYSWAPOFPOLSWAPCONFIG                                          
#define ETHTRCV_30_TJA1103_EQ2_SMIIDLEPRECHARGEENABLEDOFSMICONFIGURATION                            
#define ETHTRCV_30_TJA1103_EQ2_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                    
#define ETHTRCV_30_TJA1103_EQ2_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG                                    
#define ETHTRCV_30_TJA1103_EQ2_PRETRCVREADACCESSCALLOUTOFUSERACCESSCALLOUTS                         
#define ETHTRCV_30_TJA1103_EQ2_PRETRCVWRITEACCESSCALLOUTOFUSERACCESSCALLOUTS                        
#define ETHTRCV_30_TJA1103_EQ2_POSTINITUSERCALLOUTOFUSERINITCALLOUTS                                
#define ETHTRCV_30_TJA1103_EQ2_PREINITUSERCALLOUTOFUSERINITCALLOUTS                                 
#define ETHTRCV_30_TJA1103_EQ2_ICUCHANNELOFWAKEUP                                                   
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPCALLOUTIDXOFWAKEUP                                             
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPCALLOUTUSEDOFWAKEUP                                            
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPINSPECTIONTYPEOFWAKEUP                                         
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPMAPENDIDXOFWAKEUP                                              
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPMAPSTARTIDXOFWAKEUP                                            
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPMAPUSEDOFWAKEUP                                                
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPVERIFICATIONCALLOUTIDXOFWAKEUP                                 
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPVERIFICATIONCALLOUTUSEDOFWAKEUP                                
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPCALLOUT                                                        
#define ETHTRCV_30_TJA1103_EQ2_ECUMWAKEUPSOURCEOFWAKEUPMAP                                          
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPREASONOFWAKEUPMAP                                              
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPVERIFICATIONCALLOUT                                            
#define ETHTRCV_30_TJA1103_EQ2_DRIVINGSTRENGTHOFXMIICLKIOCONFIG                                     
#define ETHTRCV_30_TJA1103_EQ2_SLEWRATEOFXMIICLKIOCONFIG                                            
#define ETHTRCV_30_TJA1103_EQ2_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG                                    
#define ETHTRCV_30_TJA1103_EQ2_SLEWRATEOFXMIIDATAIOCONFIG                                           
#define ETHTRCV_30_TJA1103_EQ2_ACCESSENTITYFCTSOFPCCONFIG                                           
#define ETHTRCV_30_TJA1103_EQ2_CABLEDIAGLOOPCYCLESOFPCCONFIG                                        
#define ETHTRCV_30_TJA1103_EQ2_CABLEDIAGNOSTICSTATEOFPCCONFIG                                       
#define ETHTRCV_30_TJA1103_EQ2_ETHTRCVOFPCCONFIG                                                    
#define ETHTRCV_30_TJA1103_EQ2_ETHTRCVTJA1103OFPCCONFIG                                             
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSLOOPCOUNTOFPCCONFIG                                          
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORCYCLECOUNTEROFPCCONFIG                                
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORFAILURECALLOUTOFPCCONFIG                              
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORFAILUREDEBOUNCECOUNTEROFPCCONFIG                      
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORFAILUREDEBOUNCELIMITEROFPCCONFIG                      
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORLOOPLIMITEROFPCCONFIG                                 
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORRECOVERYDEBOUNCECOUNTEROFPCCONFIG                     
#define ETHTRCV_30_TJA1103_EQ2_HWACCESSMONITORRECOVERYDEBOUNCELIMITEROFPCCONFIG                     
#define ETHTRCV_30_TJA1103_EQ2_MAXPHYSIGNALQUALITYMEANOFPCCONFIG                                    
#define ETHTRCV_30_TJA1103_EQ2_POLSWAPCONFIGOFPCCONFIG                                              
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFACCESSENTITYFCTSOFPCCONFIG                                     
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFETHTRCVOFPCCONFIG                                              
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFETHTRCVTJA1103OFPCCONFIG                                       
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFHWACCESSMONITORFAILURECALLOUTOFPCCONFIG                        
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFPOLSWAPCONFIGOFPCCONFIG                                        
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFSMICONFIGURATIONOFPCCONFIG                                     
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFTRCVRGMIICONFIGOFPCCONFIG                                      
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFUSERACCESSCALLOUTSOFPCCONFIG                                   
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFUSERINITCALLOUTSOFPCCONFIG                                     
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFWAKEUPCALLOUTOFPCCONFIG                                        
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFWAKEUPMAPOFPCCONFIG                                            
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFWAKEUPOFPCCONFIG                                               
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFWAKEUPVERIFICATIONCALLOUTOFPCCONFIG                            
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFXMIICLKIOCONFIGOFPCCONFIG                                      
#define ETHTRCV_30_TJA1103_EQ2_SIZEOFXMIIDATAIOCONFIGOFPCCONFIG                                     
#define ETHTRCV_30_TJA1103_EQ2_SMICONFIGURATIONOFPCCONFIG                                           
#define ETHTRCV_30_TJA1103_EQ2_TRCVHWACCESSIBILITYOFPCCONFIG                                        
#define ETHTRCV_30_TJA1103_EQ2_TRCVLINKSTATEOFPCCONFIG                                              
#define ETHTRCV_30_TJA1103_EQ2_TRCVMODEOFPCCONFIG                                                   
#define ETHTRCV_30_TJA1103_EQ2_TRCVRGMIICONFIGOFPCCONFIG                                            
#define ETHTRCV_30_TJA1103_EQ2_TRCVSTATEOFPCCONFIG                                                  
#define ETHTRCV_30_TJA1103_EQ2_USERACCESSCALLOUTSOFPCCONFIG                                         
#define ETHTRCV_30_TJA1103_EQ2_USERINITCALLOUTSOFPCCONFIG                                           
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPCALLOUTOFPCCONFIG                                              
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPMAPOFPCCONFIG                                                  
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPMODEOFPCCONFIG                                                 
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPOFPCCONFIG                                                     
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPREASONFLAGSOFPCCONFIG                                          
#define ETHTRCV_30_TJA1103_EQ2_WAKEUPVERIFICATIONCALLOUTOFPCCONFIG                                  
#define ETHTRCV_30_TJA1103_EQ2_XMIICLKIOCONFIGOFPCCONFIG                                            
#define ETHTRCV_30_TJA1103_EQ2_XMIIDATAIOCONFIGOFPCCONFIG                                           
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCSymbolicInitializationPointers  EthTrcv_30_Tja1103 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define EthTrcv_30_Tja1103_Config_Ptr                                                               &(EthTrcv_30_Tja1103_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'EthTrcv_30_Tja1103' */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCInitializationSymbols  EthTrcv_30_Tja1103 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define EthTrcv_30_Tja1103_Config                                                                   EthTrcv_30_Tja1103_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'EthTrcv_30_Tja1103 */
/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCGeneral  EthTrcv_30_Tja1103 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ETHTRCV_30_TJA1103_CHECK_INIT_POINTER                                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ETHTRCV_30_TJA1103_FINAL_MAGIC_NUMBER                                                       0x491Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of EthTrcv_30_Tja1103 */
#define ETHTRCV_30_TJA1103_INDIVIDUAL_POSTBUILD                                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'EthTrcv_30_Tja1103' is not configured to be postbuild capable. */
#define ETHTRCV_30_TJA1103_INIT_DATA                                                                ETHTRCV_30_TJA1103_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ETHTRCV_30_TJA1103_INIT_DATA_HASH_CODE                                                      -1774448329  /**< the precompile constant to validate the initialization structure at initialization time of EthTrcv_30_Tja1103 with a hashcode. The seed value is '0x491Eu' */
#define ETHTRCV_30_TJA1103_USE_ECUM_BSW_ERROR_HOOK                                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ETHTRCV_30_TJA1103_USE_INIT_POINTER                                                         STD_ON  /**< STD_ON if the init pointer EthTrcv_30_Tja1103 shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Tja1103PCSizeOfTypes  EthTrcv_30_Tja1103 SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfAccessEntityFcts */
typedef uint8 EthTrcv_30_Tja1103_SizeOfAccessEntityFctsType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfCableDiagnosticState */
typedef uint8 EthTrcv_30_Tja1103_SizeOfCableDiagnosticStateType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_SizeOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfEthTrcvTja1103 */
typedef uint8 EthTrcv_30_Tja1103_SizeOfEthTrcvTja1103Type;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfHwAccessMonitorFailureCallout */
typedef uint8 EthTrcv_30_Tja1103_SizeOfHwAccessMonitorFailureCalloutType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfHwAccessMonitorFailureDebounceCounter */
typedef uint8 EthTrcv_30_Tja1103_SizeOfHwAccessMonitorFailureDebounceCounterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfHwAccessMonitorRecoveryDebounceCounter */
typedef uint8 EthTrcv_30_Tja1103_SizeOfHwAccessMonitorRecoveryDebounceCounterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfPolSwapConfig */
typedef uint8 EthTrcv_30_Tja1103_SizeOfPolSwapConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfSmiConfiguration */
typedef uint8 EthTrcv_30_Tja1103_SizeOfSmiConfigurationType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfTrcvHwAccessibility */
typedef uint8 EthTrcv_30_Tja1103_SizeOfTrcvHwAccessibilityType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfTrcvLinkState */
typedef uint8 EthTrcv_30_Tja1103_SizeOfTrcvLinkStateType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfTrcvMode */
typedef uint8 EthTrcv_30_Tja1103_SizeOfTrcvModeType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfTrcvRgmiiConfig */
typedef uint8 EthTrcv_30_Tja1103_SizeOfTrcvRgmiiConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfTrcvState */
typedef uint8 EthTrcv_30_Tja1103_SizeOfTrcvStateType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfUserAccessCallouts */
typedef uint8 EthTrcv_30_Tja1103_SizeOfUserAccessCalloutsType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfUserInitCallouts */
typedef uint8 EthTrcv_30_Tja1103_SizeOfUserInitCalloutsType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeupCallout */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupCalloutType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeupMap */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupMapType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeupMode */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupModeType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeupReasonFlags */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupReasonFlagsType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfWakeupVerificationCallout */
typedef uint8 EthTrcv_30_Tja1103_SizeOfWakeupVerificationCalloutType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfXmiiClkIoConfig */
typedef uint8 EthTrcv_30_Tja1103_SizeOfXmiiClkIoConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SizeOfXmiiDataIoConfig */
typedef uint8 EthTrcv_30_Tja1103_SizeOfXmiiDataIoConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Tja1103PCIterableTypes  EthTrcv_30_Tja1103 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate EthTrcv_30_Tja1103_AccessEntityFcts */
typedef uint8_least EthTrcv_30_Tja1103_AccessEntityFctsIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_EthTrcv */
typedef uint8_least EthTrcv_30_Tja1103_EthTrcvIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_EthTrcvTja1103 */
typedef uint8_least EthTrcv_30_Tja1103_EthTrcvTja1103IterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
typedef uint8_least EthTrcv_30_Tja1103_HwAccessMonitorFailureCalloutIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_PolSwapConfig */
typedef uint8_least EthTrcv_30_Tja1103_PolSwapConfigIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_SmiConfiguration */
typedef uint8_least EthTrcv_30_Tja1103_SmiConfigurationIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_TrcvRgmiiConfig */
typedef uint8_least EthTrcv_30_Tja1103_TrcvRgmiiConfigIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_UserAccessCallouts */
typedef uint8_least EthTrcv_30_Tja1103_UserAccessCalloutsIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_UserInitCallouts */
typedef uint8_least EthTrcv_30_Tja1103_UserInitCalloutsIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_Wakeup */
typedef uint8_least EthTrcv_30_Tja1103_WakeupIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_WakeupCallout */
typedef uint8_least EthTrcv_30_Tja1103_WakeupCalloutIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_WakeupMap */
typedef uint8_least EthTrcv_30_Tja1103_WakeupMapIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_WakeupVerificationCallout */
typedef uint8_least EthTrcv_30_Tja1103_WakeupVerificationCalloutIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_XmiiClkIoConfig */
typedef uint8_least EthTrcv_30_Tja1103_XmiiClkIoConfigIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_XmiiDataIoConfig */
typedef uint8_least EthTrcv_30_Tja1103_XmiiDataIoConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCIterableTypesWithSizeRelations  EthTrcv_30_Tja1103 Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate EthTrcv_30_Tja1103_CableDiagnosticState */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_CableDiagnosticStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_TrcvHwAccessibility */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_TrcvHwAccessibilityIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_TrcvLinkState */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_TrcvLinkStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_TrcvMode */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_TrcvModeIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_TrcvState */
typedef EthTrcv_30_Tja1103_EthTrcvIterType EthTrcv_30_Tja1103_TrcvStateIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_WakeupMode */
typedef EthTrcv_30_Tja1103_WakeupIterType EthTrcv_30_Tja1103_WakeupModeIterType;

/**   \brief  type used to iterate EthTrcv_30_Tja1103_WakeupReasonFlags */
typedef EthTrcv_30_Tja1103_WakeupIterType EthTrcv_30_Tja1103_WakeupReasonFlagsIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCValueTypes  EthTrcv_30_Tja1103 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for EthTrcv_30_Tja1103_CableDiagLoopCycles */
typedef uint16 EthTrcv_30_Tja1103_CableDiagLoopCyclesType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_AccessEntityFctsIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_AccessEntityFctsIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_AccessEntitySnvOfEthTrcv */
typedef uint32 EthTrcv_30_Tja1103_AccessEntitySnvOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_AddressingIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_AddressingIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_AutoNegEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Tja1103_AutoNegEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_BasicCtrlRegValOfEthTrcv */
typedef uint16 EthTrcv_30_Tja1103_BasicCtrlRegValOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_ConnectionNegOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_ConnectionNegOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_DemEAccessEventIdOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_DemEAccessEventIdOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessMonitorEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Tja1103_HwAccessMonitorEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_MacSecEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Tja1103_MacSecEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_MiiModeOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_MiiModeOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_PhySignalQualityMeanOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_PhySignalQualityMeanOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SoCBaseRegAddrOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_SoCBaseRegAddrOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SoftResetOnInitEnabledOfEthTrcv */
typedef boolean EthTrcv_30_Tja1103_SoftResetOnInitEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SoftResetWaitCyclesOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_SoftResetWaitCyclesOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SpeedOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_SpeedOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupIdxOfEthTrcv */
typedef uint8 EthTrcv_30_Tja1103_WakeupIdxOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupUsedOfEthTrcv */
typedef boolean EthTrcv_30_Tja1103_WakeupUsedOfEthTrcvType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_DerivativeOfEthTrcvTja1103 */
typedef uint8 EthTrcv_30_Tja1103_DerivativeOfEthTrcvTja1103Type;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessLoopCount */
typedef uint8 EthTrcv_30_Tja1103_HwAccessLoopCountType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter */
typedef uint16 EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceLimiter */
typedef uint8 EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessMonitorLoopLimiter */
typedef uint8 EthTrcv_30_Tja1103_HwAccessMonitorLoopLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceLimiter */
typedef uint8 EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceLimiterType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_MaxPhySignalQualityMean */
typedef uint8 EthTrcv_30_Tja1103_MaxPhySignalQualityMeanType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_PolaritySwapOfPolSwapConfig */
typedef uint8 EthTrcv_30_Tja1103_PolaritySwapOfPolSwapConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SmiIdlePreChargeEnabledOfSmiConfiguration */
typedef boolean EthTrcv_30_Tja1103_SmiIdlePreChargeEnabledOfSmiConfigurationType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_RxClkSignalShiftOfTrcvRgmiiConfig */
typedef uint8 EthTrcv_30_Tja1103_RxClkSignalShiftOfTrcvRgmiiConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_TxClkSignalShiftOfTrcvRgmiiConfig */
typedef uint8 EthTrcv_30_Tja1103_TxClkSignalShiftOfTrcvRgmiiConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_IcuChannelOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_IcuChannelOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupCalloutIdxOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_WakeupCalloutIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupCalloutUsedOfWakeup */
typedef boolean EthTrcv_30_Tja1103_WakeupCalloutUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupInspectionTypeOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_WakeupInspectionTypeOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupMapEndIdxOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_WakeupMapEndIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupMapStartIdxOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_WakeupMapStartIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupMapUsedOfWakeup */
typedef boolean EthTrcv_30_Tja1103_WakeupMapUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupVerificationCalloutIdxOfWakeup */
typedef uint8 EthTrcv_30_Tja1103_WakeupVerificationCalloutIdxOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupVerificationCalloutUsedOfWakeup */
typedef boolean EthTrcv_30_Tja1103_WakeupVerificationCalloutUsedOfWakeupType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_EcuMWakeupSourceOfWakeupMap */
typedef uint8 EthTrcv_30_Tja1103_EcuMWakeupSourceOfWakeupMapType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_WakeupReasonOfWakeupMap */
typedef uint8 EthTrcv_30_Tja1103_WakeupReasonOfWakeupMapType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_DrivingStrengthOfXmiiClkIoConfig */
typedef uint8 EthTrcv_30_Tja1103_DrivingStrengthOfXmiiClkIoConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SlewRateOfXmiiClkIoConfig */
typedef uint8 EthTrcv_30_Tja1103_SlewRateOfXmiiClkIoConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_DrivingStrengthOfXmiiDataIoConfig */
typedef uint8 EthTrcv_30_Tja1103_DrivingStrengthOfXmiiDataIoConfigType;

/**   \brief  value based type definition for EthTrcv_30_Tja1103_SlewRateOfXmiiDataIoConfig */
typedef uint8 EthTrcv_30_Tja1103_SlewRateOfXmiiDataIoConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTrcv_30_Tja1103PCStructTypes  EthTrcv_30_Tja1103 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in EthTrcv_30_Tja1103_AccessEntityFcts */
typedef struct sEthTrcv_30_Tja1103_AccessEntityFctsType
{
  EthTrcv_30_Tja1103_ReadTrcvRegFctPtrType ReadTrcvRegOfAccessEntityFcts;  /**< Function to call when a read register shall be performed */
  EthTrcv_30_Tja1103_WriteTrcvRegFctPtrType WriteTrcvRegOfAccessEntityFcts;  /**< Function to call when a write register shall be performed */
} EthTrcv_30_Tja1103_AccessEntityFctsType;

/**   \brief  type used in EthTrcv_30_Tja1103_EthTrcv */
typedef struct sEthTrcv_30_Tja1103_EthTrcvType
{
  EthTrcv_30_Tja1103_AccessEntitySnvOfEthTrcvType AccessEntitySnvOfEthTrcv;  /**< Entity providing access to the transceiver hardware */
  EthTrcv_30_Tja1103_BasicCtrlRegValOfEthTrcvType BasicCtrlRegValOfEthTrcv;  /**< Initialization value of basic control register */
  EthTrcv_30_Tja1103_AutoNegEnabledOfEthTrcvType AutoNegEnabledOfEthTrcv;  /**< Auto negotiation configuration */
  EthTrcv_30_Tja1103_HwAccessMonitorEnabledOfEthTrcvType HwAccessMonitorEnabledOfEthTrcv;  /**< Enable HW access monitor for the defined Transceiver */
  EthTrcv_30_Tja1103_MacSecEnabledOfEthTrcvType MacSecEnabledOfEthTrcv;  /**< Indicates if MACsec is enabled for this transceiver */
  EthTrcv_30_Tja1103_SoftResetOnInitEnabledOfEthTrcvType SoftResetOnInitEnabledOfEthTrcv;  /**< Soft reset on initialization configuration */
  EthTrcv_30_Tja1103_AccessEntityFctsIdxOfEthTrcvType AccessEntityFctsIdxOfEthTrcv;  /**< the index of the 1:1 relation pointing to EthTrcv_30_Tja1103_AccessEntityFcts */
  EthTrcv_30_Tja1103_AddressingIdxOfEthTrcvType AddressingIdxOfEthTrcv;  /**< Addressing index in context of the access entity to address the transceiver hardware */
  EthTrcv_30_Tja1103_ConnectionNegOfEthTrcvType ConnectionNegOfEthTrcv;  /**< Connection negotiation configuration */
  EthTrcv_30_Tja1103_DemEAccessEventIdOfEthTrcvType DemEAccessEventIdOfEthTrcv;  /**< ETHTRCV_E_ACCESS DEM event */
  EthTrcv_30_Tja1103_MiiModeOfEthTrcvType MiiModeOfEthTrcv;  /**< Mii interface */
  EthTrcv_30_Tja1103_PhySignalQualityMeanOfEthTrcvType PhySignalQualityMeanOfEthTrcv;  /**< Mean value of phyisical signal quality */
  EthTrcv_30_Tja1103_SoCBaseRegAddrOfEthTrcvType SoCBaseRegAddrOfEthTrcv;  /**< Base register address within memory space of SoC in case PHY is integrated as module into SoC. */
  EthTrcv_30_Tja1103_SoftResetWaitCyclesOfEthTrcvType SoftResetWaitCyclesOfEthTrcv;  /**< Soft reset wait cycles */
  EthTrcv_30_Tja1103_SpeedOfEthTrcvType SpeedOfEthTrcv;  /**< Transceiver speed */
  EthTrcv_30_Tja1103_WakeupIdxOfEthTrcvType WakeupIdxOfEthTrcv;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Tja1103_Wakeup */
} EthTrcv_30_Tja1103_EthTrcvType;

/**   \brief  type used in EthTrcv_30_Tja1103_EthTrcvTja1103 */
typedef struct sEthTrcv_30_Tja1103_EthTrcvTja1103Type
{
  EthTrcv_30_Tja1103_DerivativeOfEthTrcvTja1103Type DerivativeOfEthTrcvTja1103;  /**< Tja1103x derivative. */
} EthTrcv_30_Tja1103_EthTrcvTja1103Type;

/**   \brief  type used in EthTrcv_30_Tja1103_PolSwapConfig */
typedef struct sEthTrcv_30_Tja1103_PolSwapConfigType
{
  EthTrcv_30_Tja1103_PolaritySwapOfPolSwapConfigType PolaritySwapOfPolSwapConfig;  /**< Polarity swap correction and detection. */
} EthTrcv_30_Tja1103_PolSwapConfigType;

/**   \brief  type used in EthTrcv_30_Tja1103_SmiConfiguration */
typedef struct sEthTrcv_30_Tja1103_SmiConfigurationType
{
  EthTrcv_30_Tja1103_SmiIdlePreChargeEnabledOfSmiConfigurationType SmiIdlePreChargeEnabledOfSmiConfiguration;  /**< SMI Idle Pre-Charge Configuration. */
} EthTrcv_30_Tja1103_SmiConfigurationType;

/**   \brief  type used in EthTrcv_30_Tja1103_TrcvRgmiiConfig */
typedef struct sEthTrcv_30_Tja1103_TrcvRgmiiConfigType
{
  EthTrcv_30_Tja1103_RxClkSignalShiftOfTrcvRgmiiConfigType RxClkSignalShiftOfTrcvRgmiiConfig;  /**< RGMII Rx clock signal shift */
  EthTrcv_30_Tja1103_TxClkSignalShiftOfTrcvRgmiiConfigType TxClkSignalShiftOfTrcvRgmiiConfig;  /**< RGMII Tx clock signal shift */
} EthTrcv_30_Tja1103_TrcvRgmiiConfigType;

/**   \brief  type used in EthTrcv_30_Tja1103_UserAccessCallouts */
typedef struct sEthTrcv_30_Tja1103_UserAccessCalloutsType
{
  EthTrcv_30_Tja1103_UserPreTrcvReadCalloutsFctPtrType PreTrcvReadAccessCalloutOfUserAccessCallouts;  /**< Pre-Transceiver Read Access callout */
  EthTrcv_30_Tja1103_UserPreTrcvWriteCalloutsFctPtrType PreTrcvWriteAccessCalloutOfUserAccessCallouts;  /**< Pre-Transceiver Write Access callout */
} EthTrcv_30_Tja1103_UserAccessCalloutsType;

/**   \brief  type used in EthTrcv_30_Tja1103_UserInitCallouts */
typedef struct sEthTrcv_30_Tja1103_UserInitCalloutsType
{
  EthTrcv_30_Tja1103_UserPostTrcvInitCalloutFctPtrType PostInitUserCalloutOfUserInitCallouts;  /**< Post-Transceiver-Initialization callout */
  EthTrcv_30_Tja1103_UserPreTrcvInitCalloutFctPtrType PreInitUserCalloutOfUserInitCallouts;  /**< Pre-Transceiver-Initialization callout */
} EthTrcv_30_Tja1103_UserInitCalloutsType;

/**   \brief  type used in EthTrcv_30_Tja1103_Wakeup */
typedef struct sEthTrcv_30_Tja1103_WakeupType
{
  EthTrcv_30_Tja1103_IcuChannelOfWakeupType IcuChannelOfWakeup;  /**< Icu channel related to wakeup signal */
  EthTrcv_30_Tja1103_WakeupCalloutIdxOfWakeupType WakeupCalloutIdxOfWakeup;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Tja1103_WakeupCallout */
  EthTrcv_30_Tja1103_WakeupInspectionTypeOfWakeupType WakeupInspectionTypeOfWakeup;  /**< Inspection type method */
  EthTrcv_30_Tja1103_WakeupMapEndIdxOfWakeupType WakeupMapEndIdxOfWakeup;  /**< the end index of the 0:n relation pointing to EthTrcv_30_Tja1103_WakeupMap */
  EthTrcv_30_Tja1103_WakeupMapStartIdxOfWakeupType WakeupMapStartIdxOfWakeup;  /**< the start index of the 0:n relation pointing to EthTrcv_30_Tja1103_WakeupMap */
  EthTrcv_30_Tja1103_WakeupVerificationCalloutIdxOfWakeupType WakeupVerificationCalloutIdxOfWakeup;  /**< the index of the 0:1 relation pointing to EthTrcv_30_Tja1103_WakeupVerificationCallout */
} EthTrcv_30_Tja1103_WakeupType;

/**   \brief  type used in EthTrcv_30_Tja1103_WakeupMap */
typedef struct sEthTrcv_30_Tja1103_WakeupMapType
{
  EthTrcv_30_Tja1103_EcuMWakeupSourceOfWakeupMapType EcuMWakeupSourceOfWakeupMap;  /**< Wakeup source of EcuM */
  EthTrcv_30_Tja1103_WakeupReasonOfWakeupMapType WakeupReasonOfWakeupMap;  /**< Wakeup reason of EthTrcv */
} EthTrcv_30_Tja1103_WakeupMapType;

/**   \brief  type used in EthTrcv_30_Tja1103_XmiiClkIoConfig */
typedef struct sEthTrcv_30_Tja1103_XmiiClkIoConfigType
{
  EthTrcv_30_Tja1103_DrivingStrengthOfXmiiClkIoConfigType DrivingStrengthOfXmiiClkIoConfig;  /**< xMII clock I/O Driving Strength. */
  EthTrcv_30_Tja1103_SlewRateOfXmiiClkIoConfigType SlewRateOfXmiiClkIoConfig;  /**< xMII clock I/O Slew Rate. */
} EthTrcv_30_Tja1103_XmiiClkIoConfigType;

/**   \brief  type used in EthTrcv_30_Tja1103_XmiiDataIoConfig */
typedef struct sEthTrcv_30_Tja1103_XmiiDataIoConfigType
{
  EthTrcv_30_Tja1103_DrivingStrengthOfXmiiDataIoConfigType DrivingStrengthOfXmiiDataIoConfig;  /**< xMII data I/O Driving Strength. */
  EthTrcv_30_Tja1103_SlewRateOfXmiiDataIoConfigType SlewRateOfXmiiDataIoConfig;  /**< xMII data I/O Slew Rate. */
} EthTrcv_30_Tja1103_XmiiDataIoConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCRootPointerTypes  EthTrcv_30_Tja1103 Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to EthTrcv_30_Tja1103_AccessEntityFcts */
typedef P2CONST(EthTrcv_30_Tja1103_AccessEntityFctsType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_AccessEntityFctsPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_CableDiagnosticState */
typedef P2VAR(EthTrcv_30_Tja1103_CableDiagnosticStateType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_CableDiagnosticStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_EthTrcv */
typedef P2CONST(EthTrcv_30_Tja1103_EthTrcvType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcvPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_EthTrcvTja1103 */
typedef P2CONST(EthTrcv_30_Tja1103_EthTrcvTja1103Type, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcvTja1103PtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter */
typedef P2VAR(EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
typedef P2CONST(EthTrcv_30_Tja1103_UserHwAccessMonitorFailureCalloutFctPtrType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_HwAccessMonitorFailureCalloutPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter */
typedef P2VAR(EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter */
typedef P2VAR(EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_PolSwapConfig */
typedef P2CONST(EthTrcv_30_Tja1103_PolSwapConfigType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_PolSwapConfigPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_SmiConfiguration */
typedef P2CONST(EthTrcv_30_Tja1103_SmiConfigurationType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_SmiConfigurationPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_TrcvHwAccessibility */
typedef P2VAR(EthTrcv_30_Tja1103_HardwareAccessibilityType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvHwAccessibilityPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_TrcvLinkState */
typedef P2VAR(EthTrcv_StateType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvLinkStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_TrcvMode */
typedef P2VAR(EthTrcv_ModeType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvModePtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_TrcvRgmiiConfig */
typedef P2CONST(EthTrcv_30_Tja1103_TrcvRgmiiConfigType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_TrcvRgmiiConfigPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_TrcvState */
typedef P2VAR(EthTrcv_StateType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvStatePtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_UserAccessCallouts */
typedef P2CONST(EthTrcv_30_Tja1103_UserAccessCalloutsType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserAccessCalloutsPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_UserInitCallouts */
typedef P2CONST(EthTrcv_30_Tja1103_UserInitCalloutsType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserInitCalloutsPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_Wakeup */
typedef P2CONST(EthTrcv_30_Tja1103_WakeupType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_WakeupPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_WakeupCallout */
typedef P2CONST(EthTrcv_30_Tja1103_UserWakeupCalloutFctPtrType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_WakeupCalloutPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_WakeupMap */
typedef P2CONST(EthTrcv_30_Tja1103_WakeupMapType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_WakeupMapPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_WakeupMode */
typedef P2VAR(EthTrcv_WakeupModeType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_WakeupModePtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_WakeupReasonFlags */
typedef P2VAR(EthTrcv_30_Tja1103_WakeupReasonFlagsType, TYPEDEF, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_WakeupReasonFlagsPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_WakeupVerificationCallout */
typedef P2CONST(EthTrcv_30_Tja1103_UserWakeupVerificationCalloutFctPtrType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_WakeupVerificationCalloutPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_XmiiClkIoConfig */
typedef P2CONST(EthTrcv_30_Tja1103_XmiiClkIoConfigType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiClkIoConfigPtrType;

/**   \brief  type used to point to EthTrcv_30_Tja1103_XmiiDataIoConfig */
typedef P2CONST(EthTrcv_30_Tja1103_XmiiDataIoConfigType, TYPEDEF, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiDataIoConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTrcv_30_Tja1103PCRootValueTypes  EthTrcv_30_Tja1103 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in EthTrcv_30_Tja1103_PCConfig */
typedef struct sEthTrcv_30_Tja1103_PCConfigType
{
  EthTrcv_30_Tja1103_AccessEntityFctsPtrType AccessEntityFctsOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_AccessEntityFcts */
  EthTrcv_30_Tja1103_CableDiagnosticStatePtrType CableDiagnosticStateOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_CableDiagnosticState */
  EthTrcv_30_Tja1103_EthTrcvPtrType EthTrcvOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_EthTrcv */
  EthTrcv_30_Tja1103_EthTrcvTja1103PtrType EthTrcvTja1103OfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_EthTrcvTja1103 */
  EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterPtrType HwAccessMonitorCycleCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter */
  EthTrcv_30_Tja1103_HwAccessMonitorFailureCalloutPtrType HwAccessMonitorFailureCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
  EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterPtrType HwAccessMonitorFailureDebounceCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter */
  EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterPtrType HwAccessMonitorRecoveryDebounceCounterOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter */
  EthTrcv_30_Tja1103_PolSwapConfigPtrType PolSwapConfigOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_PolSwapConfig */
  EthTrcv_30_Tja1103_SmiConfigurationPtrType SmiConfigurationOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_SmiConfiguration */
  EthTrcv_30_Tja1103_TrcvHwAccessibilityPtrType TrcvHwAccessibilityOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_TrcvHwAccessibility */
  EthTrcv_30_Tja1103_TrcvLinkStatePtrType TrcvLinkStateOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_TrcvLinkState */
  EthTrcv_30_Tja1103_TrcvModePtrType TrcvModeOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_TrcvMode */
  EthTrcv_30_Tja1103_TrcvRgmiiConfigPtrType TrcvRgmiiConfigOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_TrcvRgmiiConfig */
  EthTrcv_30_Tja1103_TrcvStatePtrType TrcvStateOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_TrcvState */
  EthTrcv_30_Tja1103_UserAccessCalloutsPtrType UserAccessCalloutsOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_UserAccessCallouts */
  EthTrcv_30_Tja1103_UserInitCalloutsPtrType UserInitCalloutsOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_UserInitCallouts */
  EthTrcv_30_Tja1103_WakeupPtrType WakeupOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_Wakeup */
  EthTrcv_30_Tja1103_WakeupCalloutPtrType WakeupCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_WakeupCallout */
  EthTrcv_30_Tja1103_WakeupMapPtrType WakeupMapOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_WakeupMap */
  EthTrcv_30_Tja1103_WakeupModePtrType WakeupModeOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_WakeupMode */
  EthTrcv_30_Tja1103_WakeupReasonFlagsPtrType WakeupReasonFlagsOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_WakeupReasonFlags */
  EthTrcv_30_Tja1103_WakeupVerificationCalloutPtrType WakeupVerificationCalloutOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_WakeupVerificationCallout */
  EthTrcv_30_Tja1103_XmiiClkIoConfigPtrType XmiiClkIoConfigOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_XmiiClkIoConfig */
  EthTrcv_30_Tja1103_XmiiDataIoConfigPtrType XmiiDataIoConfigOfPCConfig;  /**< the pointer to EthTrcv_30_Tja1103_XmiiDataIoConfig */
  EthTrcv_30_Tja1103_CableDiagLoopCyclesType CableDiagLoopCyclesOfPCConfig;  /**< Maximum tries the driver performs to get results during cable diagnostics. */
  EthTrcv_30_Tja1103_HwAccessLoopCountType HwAccessLoopCountOfPCConfig;  /**< Maximum tries the driver performs to access the hardware. */
  EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceLimiterType HwAccessMonitorFailureDebounceLimiterOfPCConfig;  /**< The debounce limiter number. The debouncing is completed when the debounce counter reaches that value */
  EthTrcv_30_Tja1103_HwAccessMonitorLoopLimiterType HwAccessMonitorLoopLimiterOfPCConfig;  /**< The loop limiter value to realize the period of the hardware access check in relation to the main function period */
  EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceLimiterType HwAccessMonitorRecoveryDebounceLimiterOfPCConfig;  /**< The debounce limiter number. The debouncing is completed when the debounce counter reaches that value */
  EthTrcv_30_Tja1103_MaxPhySignalQualityMeanType MaxPhySignalQualityMeanOfPCConfig;  /**< Maximum physical signal quality mean configured for the Ethernet transceivers */
  EthTrcv_30_Tja1103_SizeOfAccessEntityFctsType SizeOfAccessEntityFctsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_AccessEntityFcts */
  EthTrcv_30_Tja1103_SizeOfEthTrcvType SizeOfEthTrcvOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcv */
  EthTrcv_30_Tja1103_SizeOfEthTrcvTja1103Type SizeOfEthTrcvTja1103OfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcvTja1103 */
  EthTrcv_30_Tja1103_SizeOfHwAccessMonitorFailureCalloutType SizeOfHwAccessMonitorFailureCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
  EthTrcv_30_Tja1103_SizeOfPolSwapConfigType SizeOfPolSwapConfigOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_PolSwapConfig */
  EthTrcv_30_Tja1103_SizeOfSmiConfigurationType SizeOfSmiConfigurationOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_SmiConfiguration */
  EthTrcv_30_Tja1103_SizeOfTrcvRgmiiConfigType SizeOfTrcvRgmiiConfigOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvRgmiiConfig */
  EthTrcv_30_Tja1103_SizeOfUserAccessCalloutsType SizeOfUserAccessCalloutsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_UserAccessCallouts */
  EthTrcv_30_Tja1103_SizeOfUserInitCalloutsType SizeOfUserInitCalloutsOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_UserInitCallouts */
  EthTrcv_30_Tja1103_SizeOfWakeupType SizeOfWakeupOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_Wakeup */
  EthTrcv_30_Tja1103_SizeOfWakeupCalloutType SizeOfWakeupCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupCallout */
  EthTrcv_30_Tja1103_SizeOfWakeupMapType SizeOfWakeupMapOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupMap */
  EthTrcv_30_Tja1103_SizeOfWakeupVerificationCalloutType SizeOfWakeupVerificationCalloutOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupVerificationCallout */
  EthTrcv_30_Tja1103_SizeOfXmiiClkIoConfigType SizeOfXmiiClkIoConfigOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiClkIoConfig */
  EthTrcv_30_Tja1103_SizeOfXmiiDataIoConfigType SizeOfXmiiDataIoConfigOfPCConfig;  /**< the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiDataIoConfig */
} EthTrcv_30_Tja1103_PCConfigType;

typedef EthTrcv_30_Tja1103_PCConfigType EthTrcv_30_Tja1103_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access EthTrcv_30_Tja1103_PCConfig in a symbol based style. */
typedef struct sEthTrcv_30_Tja1103_PCConfigsType
{
  EthTrcv_30_Tja1103_PCConfigType Config;  /**< [Config] */
} EthTrcv_30_Tja1103_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Tja1103_AccessEntityFcts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_AccessEntityFcts
  \brief  Functions of the accesses entities to read/write transceiver registers.
  \details
  Element         Description
  ReadTrcvReg     Function to call when a read register shall be performed
  WriteTrcvReg    Function to call when a write register shall be performed
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_AccessEntityFctsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_AccessEntityFcts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_EthTrcv
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_EthTrcv
  \brief  Ethernet transceivers managed by the driver.
  \details
  Element                   Description
  AccessEntitySnv           Entity providing access to the transceiver hardware
  BasicCtrlRegVal           Initialization value of basic control register
  AutoNegEnabled            Auto negotiation configuration
  HwAccessMonitorEnabled    Enable HW access monitor for the defined Transceiver
  MacSecEnabled             Indicates if MACsec is enabled for this transceiver
  SoftResetOnInitEnabled    Soft reset on initialization configuration
  AccessEntityFctsIdx       the index of the 1:1 relation pointing to EthTrcv_30_Tja1103_AccessEntityFcts
  AddressingIdx             Addressing index in context of the access entity to address the transceiver hardware
  ConnectionNeg             Connection negotiation configuration
  DemEAccessEventId         ETHTRCV_E_ACCESS DEM event
  MiiMode                   Mii interface
  PhySignalQualityMean      Mean value of phyisical signal quality
  SoCBaseRegAddr            Base register address within memory space of SoC in case PHY is integrated as module into SoC.
  SoftResetWaitCycles       Soft reset wait cycles
  Speed                     Transceiver speed
  WakeupIdx                 the index of the 0:1 relation pointing to EthTrcv_30_Tja1103_Wakeup
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_EthTrcvType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcv[1];
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_EthTrcvTja1103
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_EthTrcvTja1103
  \brief  Tja1103 specific configuration data.
  \details
  Element       Description
  Derivative    Tja1103x derivative.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_EthTrcvTja1103Type, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcvTja1103[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  \brief  Hardware access monitor failure callouts to application.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_UserHwAccessMonitorFailureCalloutFctPtrType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_PolSwapConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_PolSwapConfig
  \brief  Polarity swap configuration.
  \details
  Element         Description
  PolaritySwap    Polarity swap correction and detection.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_PolSwapConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_PolSwapConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_SmiConfiguration
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_SmiConfiguration
  \brief  SMI configuration.
  \details
  Element                    Description
  SmiIdlePreChargeEnabled    SMI Idle Pre-Charge Configuration.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_SmiConfigurationType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_SmiConfiguration[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvRgmiiConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvRgmiiConfig
  \brief  RGMII specific configuration data.
  \details
  Element             Description
  RxClkSignalShift    RGMII Rx clock signal shift
  TxClkSignalShift    RGMII Tx clock signal shift
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_TrcvRgmiiConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_TrcvRgmiiConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_UserAccessCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_UserAccessCallouts
  \brief  pretransceiver read/write access callouts to application.
  \details
  Element                      Description
  PreTrcvReadAccessCallout     Pre-Transceiver Read Access callout
  PreTrcvWriteAccessCallout    Pre-Transceiver Write Access callout
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_UserAccessCalloutsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserAccessCallouts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_UserInitCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_UserInitCallouts
  \brief  Pre-/Post-Transceiver-Initialization callouts to application.
  \details
  Element                Description
  PostInitUserCallout    Post-Transceiver-Initialization callout
  PreInitUserCallout     Pre-Transceiver-Initialization callout
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_UserInitCalloutsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserInitCallouts[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_XmiiClkIoConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_XmiiClkIoConfig
  \brief  xMii clock I/O configuration.
  \details
  Element            Description
  DrivingStrength    xMII clock I/O Driving Strength.
  SlewRate           xMII clock I/O Slew Rate.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_XmiiClkIoConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiClkIoConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_XmiiDataIoConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_XmiiDataIoConfig
  \brief  xMii data I/O configuration.
  \details
  Element            Description
  DrivingStrength    xMII data I/O Driving Strength.
  SlewRate           xMII data I/O Slew Rate.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_XmiiDataIoConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiDataIoConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_CableDiagnosticState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_CableDiagnosticState
  \brief  State of cable diagnostic.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Tja1103_CableDiagnosticStateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_CableDiagnosticState[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
  \brief  The Wakeup reason cycle Counter
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error reaction
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error recovery
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvHwAccessibility
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvHwAccessibility
  \brief  Transceiver hardware accessibility
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_30_Tja1103_HardwareAccessibilityType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvHwAccessibility[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvLinkState
  \brief  Transceiver link state.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_StateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvLinkState[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvMode
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvMode
  \brief  Transceiver operating mode.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_ModeType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvMode[1];
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvState
  \brief  Transceiver initialization state.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTrcv_StateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvState[1];
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_PCConfig
  \details
  Element                                   Description
  AccessEntityFcts                          the pointer to EthTrcv_30_Tja1103_AccessEntityFcts
  CableDiagnosticState                      the pointer to EthTrcv_30_Tja1103_CableDiagnosticState
  EthTrcv                                   the pointer to EthTrcv_30_Tja1103_EthTrcv
  EthTrcvTja1103                            the pointer to EthTrcv_30_Tja1103_EthTrcvTja1103
  HwAccessMonitorCycleCounter               the pointer to EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
  HwAccessMonitorFailureCallout             the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  HwAccessMonitorFailureDebounceCounter     the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
  HwAccessMonitorRecoveryDebounceCounter    the pointer to EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
  PolSwapConfig                             the pointer to EthTrcv_30_Tja1103_PolSwapConfig
  SmiConfiguration                          the pointer to EthTrcv_30_Tja1103_SmiConfiguration
  TrcvHwAccessibility                       the pointer to EthTrcv_30_Tja1103_TrcvHwAccessibility
  TrcvLinkState                             the pointer to EthTrcv_30_Tja1103_TrcvLinkState
  TrcvMode                                  the pointer to EthTrcv_30_Tja1103_TrcvMode
  TrcvRgmiiConfig                           the pointer to EthTrcv_30_Tja1103_TrcvRgmiiConfig
  TrcvState                                 the pointer to EthTrcv_30_Tja1103_TrcvState
  UserAccessCallouts                        the pointer to EthTrcv_30_Tja1103_UserAccessCallouts
  UserInitCallouts                          the pointer to EthTrcv_30_Tja1103_UserInitCallouts
  Wakeup                                    the pointer to EthTrcv_30_Tja1103_Wakeup
  WakeupCallout                             the pointer to EthTrcv_30_Tja1103_WakeupCallout
  WakeupMap                                 the pointer to EthTrcv_30_Tja1103_WakeupMap
  WakeupMode                                the pointer to EthTrcv_30_Tja1103_WakeupMode
  WakeupReasonFlags                         the pointer to EthTrcv_30_Tja1103_WakeupReasonFlags
  WakeupVerificationCallout                 the pointer to EthTrcv_30_Tja1103_WakeupVerificationCallout
  XmiiClkIoConfig                           the pointer to EthTrcv_30_Tja1103_XmiiClkIoConfig
  XmiiDataIoConfig                          the pointer to EthTrcv_30_Tja1103_XmiiDataIoConfig
  CableDiagLoopCycles                       Maximum tries the driver performs to get results during cable diagnostics.
  HwAccessLoopCount                         Maximum tries the driver performs to access the hardware.
  HwAccessMonitorFailureDebounceLimiter     The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  HwAccessMonitorLoopLimiter                The loop limiter value to realize the period of the hardware access check in relation to the main function period
  HwAccessMonitorRecoveryDebounceLimiter    The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  MaxPhySignalQualityMean                   Maximum physical signal quality mean configured for the Ethernet transceivers
  SizeOfAccessEntityFcts                    the number of accomplishable value elements in EthTrcv_30_Tja1103_AccessEntityFcts
  SizeOfEthTrcv                             the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcv
  SizeOfEthTrcvTja1103                      the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcvTja1103
  SizeOfHwAccessMonitorFailureCallout       the number of accomplishable value elements in EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  SizeOfPolSwapConfig                       the number of accomplishable value elements in EthTrcv_30_Tja1103_PolSwapConfig
  SizeOfSmiConfiguration                    the number of accomplishable value elements in EthTrcv_30_Tja1103_SmiConfiguration
  SizeOfTrcvRgmiiConfig                     the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvRgmiiConfig
  SizeOfUserAccessCallouts                  the number of accomplishable value elements in EthTrcv_30_Tja1103_UserAccessCallouts
  SizeOfUserInitCallouts                    the number of accomplishable value elements in EthTrcv_30_Tja1103_UserInitCallouts
  SizeOfWakeup                              the number of accomplishable value elements in EthTrcv_30_Tja1103_Wakeup
  SizeOfWakeupCallout                       the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupCallout
  SizeOfWakeupMap                           the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupMap
  SizeOfWakeupVerificationCallout           the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupVerificationCallout
  SizeOfXmiiClkIoConfig                     the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiClkIoConfig
  SizeOfXmiiDataIoConfig                    the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiDataIoConfig
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTrcv_30_Tja1103_PCConfigsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_PCConfig;
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#endif /* ETHTRCV_30_TJA1103_GENTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1103_GenTypes.h
 *********************************************************************************************************************/


