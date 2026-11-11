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
 *            Module: Eth_30_Wrapper
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eth_30_Wrapper_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:20
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
#if !defined (ETH_30_WRAPPER_LCFG_H)
# define ETH_30_WRAPPER_LCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Eth_30_Wrapper_Cfg.h"
#include "Eth_30_Wrapper_Int_ApiTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# if !defined (ETH_30_WRAPPER_LOCAL_INLINE)
#  define ETH_30_WRAPPER_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Eth_30_WrapperPCDataSwitches  Eth_30_Wrapper Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ETH_30_WRAPPER_APIACCESSMUTEX                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEAPILOCKEDOFAPIACCESSMUTEX                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMETUPLEAPILOCKEDOFAPIACCESSMUTEX                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIAPILOCKEDOFAPIACCESSMUTEX                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRL                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_BUFFERINDEXOFFSETENABLEDOFETHCTRL                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CTRLIDXOFETHCTRL                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUESPOLLEDENDIDXOFETHCTRL                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUESPOLLEDUSEDOFETHCTRL                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIINDIDXOFETHCTRL                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIINDOFETHCTRL                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIINDUSEDOFETHCTRL                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SUBCTRLIDXOFETHCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUESPOLLED                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUEIDXOFETHCTRLCONFIGINGRESSQUEUESPOLLED               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_19_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_19_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_19_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_19_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_19_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_19_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_19_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_19_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_19_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_19_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_19_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_19_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_19_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_19_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_19_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_19_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_19_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_20_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_20_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_20_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_20_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_20_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_20_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_20_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_20_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_20_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_20_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_20_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_20_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_20_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_20_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_20_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_20_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_20_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_21_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_21_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_21_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_21_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_21_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_21_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_21_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_21_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_21_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_21_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_21_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_21_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_21_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_21_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_21_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_21_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_21_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_22_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_22_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_22_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_22_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_22_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_22_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_22_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_22_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_22_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_22_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_22_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_22_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_22_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_22_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_22_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_22_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_22_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_23_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_23_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_23_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_23_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_23_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_23_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHCTIMEOFETHDRVAPIS_AR_23_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_23_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_23_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_23_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_23_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_IMMEDIATETRANSMITOFETHDRVAPIS_AR_23_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_23_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_23_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_23_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RELEASERXBUFFEROFETHDRVAPIS_AR_23_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHCCORRECTIONOFETHDRVAPIS_AR_23_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHCTIMEOFETHDRVAPIS_AR_23_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_23_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPPSSIGNALMODEOFETHDRVAPIS_AR_23_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_23_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_23_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_23_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_23_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_24_11                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_24_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_24_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_24_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_24_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_24_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHCTIMEOFETHDRVAPIS_AR_24_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_24_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_24_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_24_11                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_24_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_IMMEDIATETRANSMITOFETHDRVAPIS_AR_24_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_24_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_24_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMMDOFETHDRVAPIS_AR_24_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_24_11                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RELEASERXBUFFEROFETHDRVAPIS_AR_24_11                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHCCORRECTIONOFETHDRVAPIS_AR_24_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHCTIMEOFETHDRVAPIS_AR_24_11                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_24_11                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPPSSIGNALMODEOFETHDRVAPIS_AR_24_11                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_24_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_24_11                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_24_11                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_24_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMMDOFETHDRVAPIS_AR_24_11                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_1_3                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_4_1_3                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_1_3                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_4_1_3                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_4_1_3                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_4_1_3                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_4_1_3                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_1_3                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_4_1_3                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_4_1_3                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_4_1_3                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_4_1_3                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_4_1_3                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_1_3                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_4_1_3                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_0                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_4_3_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_0                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_4_3_0                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_4_3_0                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_4_3_0                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_0                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_4_3_0                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_4_3_0                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_4_3_0                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_4_3_0                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_0                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_4_3_0                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_1                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_4_3_1                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_1                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_1                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_4_3_1                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_4_3_1                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_4_3_1                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_1                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_4_3_1                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_4_3_1                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_4_3_1                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_4_3_1                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_1                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_1                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_4_3_1                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_4_0                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_CONTROLLERINITOFETHDRVAPIS_AR_4_4_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_4_0                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETCURRENTTIMEOFETHDRVAPIS_AR_4_4_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETPHYSADDROFETHDRVAPIS_AR_4_4_0                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETRXSTATSOFETHDRVAPIS_AR_4_4_0                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_GETTXSTATSOFETHDRVAPIS_AR_4_4_0                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_4_0                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_READMIIOFETHDRVAPIS_AR_4_4_0                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_RECEIVEOFETHDRVAPIS_AR_4_4_0                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SETPHYSADDROFETHDRVAPIS_AR_4_4_0                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TRANSMITOFETHDRVAPIS_AR_4_4_0                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_TXCONFIRMATIONOFETHDRVAPIS_AR_4_4_0                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_4_0                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_WRITEMIIOFETHDRVAPIS_AR_4_4_0                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_FINALMAGICNUMBER                                                             STD_OFF  /**< Deactivateable: 'Eth_30_Wrapper_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETH_30_WRAPPER_INITDATAHASHCODE                                                             STD_OFF  /**< Deactivateable: 'Eth_30_Wrapper_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETH_30_WRAPPER_SIZEOFAPIACCESSMUTEX                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHCTRL                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHCTRLCONFIGINGRESSQUEUESPOLLED                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_19_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_20_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_21_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_22_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_23_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_24_11                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_1_3                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_3_0                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_3_1                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_4_0                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_PCCONFIG                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_APIACCESSMUTEXOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHCTRLOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_19_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_20_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_21_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_22_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_23_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_24_11OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_1_3OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_0OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_1OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_4_0OFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Eth_30_Wrapper_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETH_30_WRAPPER_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Eth_30_Wrapper_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETH_30_WRAPPER_SIZEOFAPIACCESSMUTEXOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHCTRLOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_19_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_20_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_21_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_22_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_23_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_24_11OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_1_3OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_3_0OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_3_1OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETH_30_WRAPPER_SIZEOFETHDRVAPIS_AR_4_4_0OFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCNoReferenceDefines  Eth_30_Wrapper No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define ETH_30_WRAPPER_NO_ETHCTRLCONFIGINGRESSQUEUESPOLLEDENDIDXOFETHCTRL                           255u
#define ETH_30_WRAPPER_NO_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL                         255u
#define ETH_30_WRAPPER_NO_ETHDRVAPIINDIDXOFETHCTRL                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCEnumExistsDefines  Eth_30_Wrapper Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_4_1_3_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_4_3_0_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_4_3_1_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_4_4_0_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_19_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_20_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_21_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_22_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_23_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_ETHDRVAPIS_AR_24_11_ETHDRVAPIINDOFETHCTRL                             STD_ON
#define ETH_30_WRAPPER_EXISTS_NO_ETHDRVAPIINDOFETHCTRL                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCEnumDefines  Eth_30_Wrapper Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_1_3_ETHDRVAPIINDOFETHCTRL                                    0x00u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_0_ETHDRVAPIINDOFETHCTRL                                    0x01u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_3_1_ETHDRVAPIINDOFETHCTRL                                    0x02u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_4_4_0_ETHDRVAPIINDOFETHCTRL                                    0x03u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_19_11_ETHDRVAPIINDOFETHCTRL                                    0x04u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_20_11_ETHDRVAPIINDOFETHCTRL                                    0x05u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_21_11_ETHDRVAPIINDOFETHCTRL                                    0x06u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_22_11_ETHDRVAPIINDOFETHCTRL                                    0x07u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_23_11_ETHDRVAPIINDOFETHCTRL                                    0x08u
#define ETH_30_WRAPPER_ETHDRVAPIS_AR_24_11_ETHDRVAPIINDOFETHCTRL                                    0x09u
#define ETH_30_WRAPPER_NO_ETHDRVAPIINDOFETHCTRL                                                     0xFFu
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCIsReducedToDefineDefines  Eth_30_Wrapper Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ETH_30_WRAPPER_ISDEF_BUFFERINDEXOFFSETENABLEDOFETHCTRL                                      STD_OFF
#define ETH_30_WRAPPER_ISDEF_CTRLIDXOFETHCTRL                                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLCONFIGINGRESSQUEUESPOLLEDENDIDXOFETHCTRL                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL                      STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLCONFIGINGRESSQUEUESPOLLEDUSEDOFETHCTRL                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIINDIDXOFETHCTRL                                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIINDOFETHCTRL                                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIINDUSEDOFETHCTRL                                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_SUBCTRLIDXOFETHCTRL                                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLCONFIGINGRESSQUEUEIDXOFETHCTRLCONFIGINGRESSQUEUESPOLLED         STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_19_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_19_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_19_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_19_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_19_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_19_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_19_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_19_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_19_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_19_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_19_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_19_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_19_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_19_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_19_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_19_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_20_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_20_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_20_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_20_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_20_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_20_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_20_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_20_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_20_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_20_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_20_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_20_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_20_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_20_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_20_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_20_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_21_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_21_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_21_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_21_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_21_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_21_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_21_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_21_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_21_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_21_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_21_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_21_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_21_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_21_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_21_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_21_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_22_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_22_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_22_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_22_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_22_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_22_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_22_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_22_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_22_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_22_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_22_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_22_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_22_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_22_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_22_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_22_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_23_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_23_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_23_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_23_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_23_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHCTIMEOFETHDRVAPIS_AR_23_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_23_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_23_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_23_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_23_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_IMMEDIATETRANSMITOFETHDRVAPIS_AR_23_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_23_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_23_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_23_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RELEASERXBUFFEROFETHDRVAPIS_AR_23_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHCCORRECTIONOFETHDRVAPIS_AR_23_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHCTIMEOFETHDRVAPIS_AR_23_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_23_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPPSSIGNALMODEOFETHDRVAPIS_AR_23_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_23_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_23_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_23_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_23_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_24_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_24_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_24_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_24_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_24_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHCTIMEOFETHDRVAPIS_AR_24_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_24_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_24_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_24_11                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_24_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_IMMEDIATETRANSMITOFETHDRVAPIS_AR_24_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_24_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_24_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMMDOFETHDRVAPIS_AR_24_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_24_11                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RELEASERXBUFFEROFETHDRVAPIS_AR_24_11                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHCCORRECTIONOFETHDRVAPIS_AR_24_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHCTIMEOFETHDRVAPIS_AR_24_11                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_24_11                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPPSSIGNALMODEOFETHDRVAPIS_AR_24_11                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_24_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_24_11                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_24_11                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_24_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMMDOFETHDRVAPIS_AR_24_11                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_4_1_3                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_1_3                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_4_1_3                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_4_1_3                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_4_1_3                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_4_1_3                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_1_3                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_4_1_3                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_4_1_3                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_4_1_3                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_4_1_3                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_4_1_3                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_1_3                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_4_1_3                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_4_3_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_0                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_4_3_0                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_4_3_0                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_4_3_0                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_0                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_4_3_0                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_4_3_0                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_4_3_0                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_4_3_0                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_0                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_4_3_0                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_4_3_1                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_1                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_1                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_4_3_1                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_4_3_1                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_4_3_1                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_1                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_4_3_1                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_4_3_1                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_4_3_1                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_4_3_1                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_1                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_1                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_4_3_1                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_CONTROLLERINITOFETHDRVAPIS_AR_4_4_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_4_0                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                                  STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETCURRENTTIMEOFETHDRVAPIS_AR_4_4_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETPHYSADDROFETHDRVAPIS_AR_4_4_0                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETRXSTATSOFETHDRVAPIS_AR_4_4_0                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_GETTXSTATSOFETHDRVAPIS_AR_4_4_0                                        STD_OFF
#define ETH_30_WRAPPER_ISDEF_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_4_0                                   STD_OFF
#define ETH_30_WRAPPER_ISDEF_READMIIOFETHDRVAPIS_AR_4_4_0                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_RECEIVEOFETHDRVAPIS_AR_4_4_0                                           STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                 STD_OFF
#define ETH_30_WRAPPER_ISDEF_SETPHYSADDROFETHDRVAPIS_AR_4_4_0                                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_TRANSMITOFETHDRVAPIS_AR_4_4_0                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_TXCONFIRMATIONOFETHDRVAPIS_AR_4_4_0                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_4_0                              STD_OFF
#define ETH_30_WRAPPER_ISDEF_WRITEMIIOFETHDRVAPIS_AR_4_4_0                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_APIACCESSMUTEXOFPCCONFIG                                               STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                             STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHCTRLOFPCCONFIG                                                      STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_19_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_20_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_21_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_22_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_23_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_24_11OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_4_1_3OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_4_3_0OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_4_3_1OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_ETHDRVAPIS_AR_4_4_0OFPCCONFIG                                          STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                       STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHCTRLOFPCCONFIG                                                STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_19_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_20_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_21_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_22_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_23_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_24_11OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_4_1_3OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_4_3_0OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_4_3_1OFPCCONFIG                                    STD_OFF
#define ETH_30_WRAPPER_ISDEF_SIZEOFETHDRVAPIS_AR_4_4_0OFPCCONFIG                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCEqualsAlwaysToDefines  Eth_30_Wrapper Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ETH_30_WRAPPER_EQ2_BUFFERINDEXOFFSETENABLEDOFETHCTRL                                        
#define ETH_30_WRAPPER_EQ2_CTRLIDXOFETHCTRL                                                         
#define ETH_30_WRAPPER_EQ2_ETHCTRLCONFIGINGRESSQUEUESPOLLEDENDIDXOFETHCTRL                          
#define ETH_30_WRAPPER_EQ2_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL                        
#define ETH_30_WRAPPER_EQ2_ETHCTRLCONFIGINGRESSQUEUESPOLLEDUSEDOFETHCTRL                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIINDIDXOFETHCTRL                                                 
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIINDOFETHCTRL                                                    
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIINDUSEDOFETHCTRL                                                
#define ETH_30_WRAPPER_EQ2_SUBCTRLIDXOFETHCTRL                                                      
#define ETH_30_WRAPPER_EQ2_ETHCTRLCONFIGINGRESSQUEUEIDXOFETHCTRLCONFIGINGRESSQUEUESPOLLED           
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_19_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_19_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_19_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_19_11                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_19_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_19_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_19_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_19_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_19_11                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_19_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_19_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_19_11                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_19_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_19_11                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_19_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_19_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_19_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_19_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_20_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_20_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_20_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_20_11                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_20_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_20_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_20_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_20_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_20_11                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_20_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_20_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_20_11                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_20_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_20_11                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_20_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_20_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_20_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_20_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_21_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_21_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_21_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_21_11                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_21_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_21_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_21_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_21_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_21_11                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_21_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_21_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_21_11                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_21_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_21_11                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_21_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_21_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_21_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_21_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_22_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_22_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_22_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_22_11                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_22_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_22_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_22_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_22_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_22_11                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_22_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_22_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_22_11                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_22_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_22_11                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_22_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_22_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_22_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_22_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_23_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_23_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_23_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_23_11                                      
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_23_11                                 
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_23_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHCTIMEOFETHDRVAPIS_AR_23_11                                          
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_23_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_23_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_23_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_23_11                                          
#define ETH_30_WRAPPER_EQ2_IMMEDIATETRANSMITOFETHDRVAPIS_AR_23_11                                   
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_23_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_23_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_23_11                                             
#define ETH_30_WRAPPER_EQ2_RELEASERXBUFFEROFETHDRVAPIS_AR_23_11                                     
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_23_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHCCORRECTIONOFETHDRVAPIS_AR_23_11                                    
#define ETH_30_WRAPPER_EQ2_SETPHCTIMEOFETHDRVAPIS_AR_23_11                                          
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_23_11                                         
#define ETH_30_WRAPPER_EQ2_SETPPSSIGNALMODEOFETHDRVAPIS_AR_23_11                                    
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_23_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_23_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_23_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_23_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_24_11                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_24_11                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_24_11                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_24_11                                      
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMETUPLEOFETHDRVAPIS_AR_24_11                                 
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_24_11                                 
#define ETH_30_WRAPPER_EQ2_GETPHCTIMEOFETHDRVAPIS_AR_24_11                                          
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_24_11                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_24_11                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_24_11                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_24_11                                          
#define ETH_30_WRAPPER_EQ2_IMMEDIATETRANSMITOFETHDRVAPIS_AR_24_11                                   
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_24_11                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_24_11                                             
#define ETH_30_WRAPPER_EQ2_READMMDOFETHDRVAPIS_AR_24_11                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_24_11                                             
#define ETH_30_WRAPPER_EQ2_RELEASERXBUFFEROFETHDRVAPIS_AR_24_11                                     
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_24_11                                   
#define ETH_30_WRAPPER_EQ2_SETPHCCORRECTIONOFETHDRVAPIS_AR_24_11                                    
#define ETH_30_WRAPPER_EQ2_SETPHCTIMEOFETHDRVAPIS_AR_24_11                                          
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_24_11                                         
#define ETH_30_WRAPPER_EQ2_SETPPSSIGNALMODEOFETHDRVAPIS_AR_24_11                                    
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_24_11                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_24_11                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_24_11                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_24_11                                            
#define ETH_30_WRAPPER_EQ2_WRITEMMDOFETHDRVAPIS_AR_24_11                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_4_1_3                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_1_3                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_4_1_3                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_1_3                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_4_1_3                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_4_1_3                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_1_3                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_4_1_3                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_1_3                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_4_1_3                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_4_1_3                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_1_3                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_4_1_3                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_4_1_3                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_4_1_3                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_1_3                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_4_1_3                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_4_3_0                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_0                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_0                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_0                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_4_3_0                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_4_3_0                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_0                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_4_3_0                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_0                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_4_3_0                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_4_3_0                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_0                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_4_3_0                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_4_3_0                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_0                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_0                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_4_3_0                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_4_3_1                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_3_1                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_4_3_1                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_3_1                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_4_3_1                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_4_3_1                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_3_1                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_4_3_1                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_3_1                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_4_3_1                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_4_3_1                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_3_1                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_4_3_1                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_4_3_1                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_4_3_1                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_3_1                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_4_3_1                                            
#define ETH_30_WRAPPER_EQ2_CONTROLLERINITOFETHDRVAPIS_AR_4_4_0                                      
#define ETH_30_WRAPPER_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                               
#define ETH_30_WRAPPER_EQ2_GETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                   
#define ETH_30_WRAPPER_EQ2_GETCOUNTERSTATEOFETHDRVAPIS_AR_4_4_0                                     
#define ETH_30_WRAPPER_EQ2_GETCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                                    
#define ETH_30_WRAPPER_EQ2_GETCURRENTTIMEOFETHDRVAPIS_AR_4_4_0                                      
#define ETH_30_WRAPPER_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                  
#define ETH_30_WRAPPER_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPIS_AR_4_4_0                                 
#define ETH_30_WRAPPER_EQ2_GETPHYSADDROFETHDRVAPIS_AR_4_4_0                                         
#define ETH_30_WRAPPER_EQ2_GETRXSTATSOFETHDRVAPIS_AR_4_4_0                                          
#define ETH_30_WRAPPER_EQ2_GETTXERRORCOUNTERVALUESOFETHDRVAPIS_AR_4_4_0                             
#define ETH_30_WRAPPER_EQ2_GETTXSTATSOFETHDRVAPIS_AR_4_4_0                                          
#define ETH_30_WRAPPER_EQ2_PROVIDETXBUFFEROFETHDRVAPIS_AR_4_4_0                                     
#define ETH_30_WRAPPER_EQ2_READMIIOFETHDRVAPIS_AR_4_4_0                                             
#define ETH_30_WRAPPER_EQ2_RECEIVEOFETHDRVAPIS_AR_4_4_0                                             
#define ETH_30_WRAPPER_EQ2_SETCONTROLLERMODEOFETHDRVAPIS_AR_4_4_0                                   
#define ETH_30_WRAPPER_EQ2_SETPHYSADDROFETHDRVAPIS_AR_4_4_0                                         
#define ETH_30_WRAPPER_EQ2_TRANSMITOFETHDRVAPIS_AR_4_4_0                                            
#define ETH_30_WRAPPER_EQ2_TXCONFIRMATIONOFETHDRVAPIS_AR_4_4_0                                      
#define ETH_30_WRAPPER_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPIS_AR_4_4_0                                
#define ETH_30_WRAPPER_EQ2_WRITEMIIOFETHDRVAPIS_AR_4_4_0                                            
#define ETH_30_WRAPPER_EQ2_APIACCESSMUTEXOFPCCONFIG                                                 
#define ETH_30_WRAPPER_EQ2_ETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                               
#define ETH_30_WRAPPER_EQ2_ETHCTRLOFPCCONFIG                                                        
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_19_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_20_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_21_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_22_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_23_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_24_11OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_4_1_3OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_4_3_0OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_4_3_1OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_ETHDRVAPIS_AR_4_4_0OFPCCONFIG                                            
#define ETH_30_WRAPPER_EQ2_SIZEOFETHCTRLCONFIGINGRESSQUEUESPOLLEDOFPCCONFIG                         
#define ETH_30_WRAPPER_EQ2_SIZEOFETHCTRLOFPCCONFIG                                                  
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_19_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_20_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_21_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_22_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_23_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_24_11OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_4_1_3OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_4_3_0OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_4_3_1OFPCCONFIG                                      
#define ETH_30_WRAPPER_EQ2_SIZEOFETHDRVAPIS_AR_4_4_0OFPCCONFIG                                      
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCSymbolicInitializationPointers  Eth_30_Wrapper Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Eth_30_Wrapper_Config_Ptr                                                                   &(Eth_30_Wrapper_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'Eth_30_Wrapper' */
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCInitializationSymbols  Eth_30_Wrapper Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Eth_30_Wrapper_Config                                                                       Eth_30_Wrapper_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'Eth_30_Wrapper */
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCGeneral  Eth_30_Wrapper General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ETH_30_WRAPPER_CHECK_INIT_POINTER                                                           STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ETH_30_WRAPPER_FINAL_MAGIC_NUMBER                                                           0x581Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Eth_30_Wrapper */
#define ETH_30_WRAPPER_INDIVIDUAL_POSTBUILD                                                         STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Eth_30_Wrapper' is not configured to be postbuild capable. */
#define ETH_30_WRAPPER_INIT_DATA                                                                    ETH_30_WRAPPER_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ETH_30_WRAPPER_INIT_DATA_HASH_CODE                                                          -1463986360  /**< the precompile constant to validate the initialization structure at initialization time of Eth_30_Wrapper with a hashcode. The seed value is '0x581Eu' */
#define ETH_30_WRAPPER_USE_ECUM_BSW_ERROR_HOOK                                                      STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ETH_30_WRAPPER_USE_INIT_POINTER                                                             STD_ON  /**< STD_ON if the init pointer Eth_30_Wrapper shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  Eth_30_WrapperPCSizeOfTypes  Eth_30_Wrapper SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfApiAccessMutex */
typedef uint8 Eth_30_Wrapper_SizeOfApiAccessMutexType;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthCtrl */
typedef uint8 Eth_30_Wrapper_SizeOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthCtrlConfigIngressQueuesPolled */
typedef uint8 Eth_30_Wrapper_SizeOfEthCtrlConfigIngressQueuesPolledType;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_19_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_19_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_20_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_20_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_21_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_21_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_22_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_22_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_23_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_23_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_24_11 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_24_11Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_1_3 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_1_3Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_0 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_0Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_1 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_1Type;

/**   \brief  value based type definition for Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_4_0 */
typedef uint8 Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_4_0Type;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Eth_30_WrapperPCIterableTypes  Eth_30_Wrapper Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Eth_30_Wrapper_EthCtrl */
typedef uint8_least Eth_30_Wrapper_EthCtrlIterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
typedef uint8_least Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledIterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_19_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_19_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_20_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_20_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_21_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_21_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_22_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_22_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_23_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_23_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_24_11 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_24_11IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_4_1_3IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_4_3_0IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_4_3_1IterType;

/**   \brief  type used to iterate Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
typedef uint8_least Eth_30_Wrapper_EthDrvApis_AR_4_4_0IterType;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCIterableTypesWithSizeRelations  Eth_30_Wrapper Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Eth_30_Wrapper_ApiAccessMutex */
typedef Eth_30_Wrapper_EthCtrlIterType Eth_30_Wrapper_ApiAccessMutexIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCValueTypes  Eth_30_Wrapper Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutex */
typedef boolean Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutexType;

/**   \brief  value based type definition for Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutex */
typedef boolean Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutexType;

/**   \brief  value based type definition for Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutex */
typedef boolean Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutexType;

/**   \brief  value based type definition for Eth_30_Wrapper_BufferIndexOffsetEnabledOfEthCtrl */
typedef boolean Eth_30_Wrapper_BufferIndexOffsetEnabledOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_CtrlIdxOfEthCtrl */
typedef uint8 Eth_30_Wrapper_CtrlIdxOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrl */
typedef uint8 Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl */
typedef uint8 Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledUsedOfEthCtrl */
typedef boolean Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledUsedOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthDrvApiIndIdxOfEthCtrl */
typedef uint8 Eth_30_Wrapper_EthDrvApiIndIdxOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthDrvApiIndOfEthCtrl */
typedef uint8 Eth_30_Wrapper_EthDrvApiIndOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthDrvApiIndUsedOfEthCtrl */
typedef boolean Eth_30_Wrapper_EthDrvApiIndUsedOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_SubCtrlIdxOfEthCtrl */
typedef uint8 Eth_30_Wrapper_SubCtrlIdxOfEthCtrlType;

/**   \brief  value based type definition for Eth_30_Wrapper_EthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolled */
typedef uint8 Eth_30_Wrapper_EthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolledType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Eth_30_WrapperPCStructTypes  Eth_30_Wrapper Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Eth_30_Wrapper_ApiAccessMutex */
typedef struct sEth_30_Wrapper_ApiAccessMutexType
{
  Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutexType GetCurrentTimeApiLockedOfApiAccessMutex;  /**< Indicates if the Eth_GetCurrentTime is locked by an ISR/TASK */
  Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutexType GetCurrentTimeTupleApiLockedOfApiAccessMutex;  /**< Indicates if the Eth_GetCurrentTimeTuple is locked by an ISR/TASK */
  Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutexType ReadMiiApiLockedOfApiAccessMutex;  /**< Indicates if the Eth_ReadMii is locked by an ISR/TASK */
} Eth_30_Wrapper_ApiAccessMutexType;

/**   \brief  type used in Eth_30_Wrapper_EthCtrl */
typedef struct sEth_30_Wrapper_EthCtrlType
{
  Eth_30_Wrapper_BufferIndexOffsetEnabledOfEthCtrlType BufferIndexOffsetEnabledOfEthCtrl;
  Eth_30_Wrapper_CtrlIdxOfEthCtrlType CtrlIdxOfEthCtrl;  /**< EthWrapper Controller Index */
  Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrlType EthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrl;  /**< the end index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
  Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrlType EthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl;  /**< the start index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
  Eth_30_Wrapper_EthDrvApiIndOfEthCtrlType EthDrvApiIndOfEthCtrl;  /**< the enum value of the according target of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11 */
  Eth_30_Wrapper_EthDrvApiIndIdxOfEthCtrlType EthDrvApiIndIdxOfEthCtrl;  /**< the index of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11 */
  Eth_30_Wrapper_SubCtrlIdxOfEthCtrlType SubCtrlIdxOfEthCtrl;  /**< Third-Party Controller Index */
} Eth_30_Wrapper_EthCtrlType;

/**   \brief  type used in Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
typedef struct sEth_30_Wrapper_EthCtrlConfigIngressQueuesPolledType
{
  Eth_30_Wrapper_EthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolledType EthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolled;
} Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledType;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_19_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_19_11Type
{
  Eth_EthControllerInitFctPtrType_AR_19_11 ControllerInitOfEthDrvApis_AR_19_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_19_11 EnableEgressTimeStampOfEthDrvApis_AR_19_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_19_11 GetControllerModeOfEthDrvApis_AR_19_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_19_11 GetCounterStateOfEthDrvApis_AR_19_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_19_11 GetCounterValuesOfEthDrvApis_AR_19_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_19_11 GetCurrentTimeOfEthDrvApis_AR_19_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_19_11 GetEgressTimeStampOfEthDrvApis_AR_19_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_19_11 GetIngressTimeStampOfEthDrvApis_AR_19_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_19_11 GetPhysAddrOfEthDrvApis_AR_19_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_19_11 GetRxStatsOfEthDrvApis_AR_19_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_19_11 GetTxErrorCounterValuesOfEthDrvApis_AR_19_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_19_11 GetTxStatsOfEthDrvApis_AR_19_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_19_11 ProvideTxBufferOfEthDrvApis_AR_19_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_19_11 ReadMiiOfEthDrvApis_AR_19_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_19_11 ReceiveOfEthDrvApis_AR_19_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_19_11 SetControllerModeOfEthDrvApis_AR_19_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_19_11 SetPhysAddrOfEthDrvApis_AR_19_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_19_11 TransmitOfEthDrvApis_AR_19_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_19_11 TxConfirmationOfEthDrvApis_AR_19_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_19_11 UpdatePhysAddrFilterOfEthDrvApis_AR_19_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_19_11 WriteMiiOfEthDrvApis_AR_19_11;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_19_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_20_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_20_11Type
{
  Eth_EthControllerInitFctPtrType_AR_20_11 ControllerInitOfEthDrvApis_AR_20_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_20_11 EnableEgressTimeStampOfEthDrvApis_AR_20_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_20_11 GetControllerModeOfEthDrvApis_AR_20_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_20_11 GetCounterStateOfEthDrvApis_AR_20_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_20_11 GetCounterValuesOfEthDrvApis_AR_20_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_20_11 GetCurrentTimeOfEthDrvApis_AR_20_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_20_11 GetEgressTimeStampOfEthDrvApis_AR_20_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_20_11 GetIngressTimeStampOfEthDrvApis_AR_20_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_20_11 GetPhysAddrOfEthDrvApis_AR_20_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_20_11 GetRxStatsOfEthDrvApis_AR_20_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_20_11 GetTxErrorCounterValuesOfEthDrvApis_AR_20_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_20_11 GetTxStatsOfEthDrvApis_AR_20_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_20_11 ProvideTxBufferOfEthDrvApis_AR_20_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_20_11 ReadMiiOfEthDrvApis_AR_20_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_20_11 ReceiveOfEthDrvApis_AR_20_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_20_11 SetControllerModeOfEthDrvApis_AR_20_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_20_11 SetPhysAddrOfEthDrvApis_AR_20_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_20_11 TransmitOfEthDrvApis_AR_20_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_20_11 TxConfirmationOfEthDrvApis_AR_20_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_20_11 UpdatePhysAddrFilterOfEthDrvApis_AR_20_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_20_11 WriteMiiOfEthDrvApis_AR_20_11;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_20_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_21_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_21_11Type
{
  Eth_EthControllerInitFctPtrType_AR_21_11 ControllerInitOfEthDrvApis_AR_21_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_21_11 EnableEgressTimeStampOfEthDrvApis_AR_21_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_21_11 GetControllerModeOfEthDrvApis_AR_21_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_21_11 GetCounterStateOfEthDrvApis_AR_21_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_21_11 GetCounterValuesOfEthDrvApis_AR_21_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_21_11 GetCurrentTimeOfEthDrvApis_AR_21_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_21_11 GetEgressTimeStampOfEthDrvApis_AR_21_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_21_11 GetIngressTimeStampOfEthDrvApis_AR_21_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_21_11 GetPhysAddrOfEthDrvApis_AR_21_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_21_11 GetRxStatsOfEthDrvApis_AR_21_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_21_11 GetTxErrorCounterValuesOfEthDrvApis_AR_21_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_21_11 GetTxStatsOfEthDrvApis_AR_21_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_21_11 ProvideTxBufferOfEthDrvApis_AR_21_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_21_11 ReadMiiOfEthDrvApis_AR_21_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_21_11 ReceiveOfEthDrvApis_AR_21_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_21_11 SetControllerModeOfEthDrvApis_AR_21_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_21_11 SetPhysAddrOfEthDrvApis_AR_21_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_21_11 TransmitOfEthDrvApis_AR_21_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_21_11 TxConfirmationOfEthDrvApis_AR_21_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_21_11 UpdatePhysAddrFilterOfEthDrvApis_AR_21_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_21_11 WriteMiiOfEthDrvApis_AR_21_11;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_21_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_22_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_22_11Type
{
  Eth_EthControllerInitFctPtrType_AR_22_11 ControllerInitOfEthDrvApis_AR_22_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_22_11 EnableEgressTimeStampOfEthDrvApis_AR_22_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_22_11 GetControllerModeOfEthDrvApis_AR_22_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_22_11 GetCounterStateOfEthDrvApis_AR_22_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_22_11 GetCounterValuesOfEthDrvApis_AR_22_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_22_11 GetCurrentTimeOfEthDrvApis_AR_22_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_22_11 GetEgressTimeStampOfEthDrvApis_AR_22_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_22_11 GetIngressTimeStampOfEthDrvApis_AR_22_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_22_11 GetPhysAddrOfEthDrvApis_AR_22_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_22_11 GetRxStatsOfEthDrvApis_AR_22_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_22_11 GetTxErrorCounterValuesOfEthDrvApis_AR_22_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_22_11 GetTxStatsOfEthDrvApis_AR_22_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_22_11 ProvideTxBufferOfEthDrvApis_AR_22_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_22_11 ReadMiiOfEthDrvApis_AR_22_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_22_11 ReceiveOfEthDrvApis_AR_22_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_22_11 SetControllerModeOfEthDrvApis_AR_22_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_22_11 SetPhysAddrOfEthDrvApis_AR_22_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_22_11 TransmitOfEthDrvApis_AR_22_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_22_11 TxConfirmationOfEthDrvApis_AR_22_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_22_11 UpdatePhysAddrFilterOfEthDrvApis_AR_22_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_22_11 WriteMiiOfEthDrvApis_AR_22_11;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_22_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_23_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_23_11Type
{
  Eth_EthControllerInitFctPtrType_AR_23_11 ControllerInitOfEthDrvApis_AR_23_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_23_11 EnableEgressTimeStampOfEthDrvApis_AR_23_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_23_11 GetControllerModeOfEthDrvApis_AR_23_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_23_11 GetCounterStateOfEthDrvApis_AR_23_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_23_11 GetCounterValuesOfEthDrvApis_AR_23_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_23_11 GetCurrentTimeOfEthDrvApis_AR_23_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetCurrentTimeTupleFctPtrType_AR_23_11 GetCurrentTimeTupleOfEthDrvApis_AR_23_11;  /**< Eth_GetCurrentTimeTuple() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_23_11 GetEgressTimeStampOfEthDrvApis_AR_23_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_23_11 GetIngressTimeStampOfEthDrvApis_AR_23_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhcTimeFctPtrType_AR_23_11 GetPhcTimeOfEthDrvApis_AR_23_11;  /**< Eth_GetPhcTime() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_23_11 GetPhysAddrOfEthDrvApis_AR_23_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_23_11 GetRxStatsOfEthDrvApis_AR_23_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_23_11 GetTxErrorCounterValuesOfEthDrvApis_AR_23_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_23_11 GetTxStatsOfEthDrvApis_AR_23_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthImmediateTransmitFctPtrType_AR_23_11 ImmediateTransmitOfEthDrvApis_AR_23_11;  /**< Eth_ImmediateTransmit() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_23_11 ProvideTxBufferOfEthDrvApis_AR_23_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_23_11 ReadMiiOfEthDrvApis_AR_23_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_23_11 ReceiveOfEthDrvApis_AR_23_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthReleaseRxBufferFctPtrType_AR_23_11 ReleaseRxBufferOfEthDrvApis_AR_23_11;  /**< Eth_ReleaseRxBuffer() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_23_11 SetControllerModeOfEthDrvApis_AR_23_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhcCorrectionFctPtrType_AR_23_11 SetPhcCorrectionOfEthDrvApis_AR_23_11;  /**< Eth_SetPhcCorrection() of Eth driver. */
  Eth_EthSetPhcTimeFctPtrType_AR_23_11 SetPhcTimeOfEthDrvApis_AR_23_11;  /**< Eth_SetPhcTime() of Eth driver. */
  Eth_EthSetPhysAddrFctPtrType_AR_23_11 SetPhysAddrOfEthDrvApis_AR_23_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthSetPpsSignalModeFctPtrType_AR_23_11 SetPpsSignalModeOfEthDrvApis_AR_23_11;  /**< Eth_SetPpsSignalMode() of Eth driver. */
  Eth_EthTransmitFctPtrType_AR_23_11 TransmitOfEthDrvApis_AR_23_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_23_11 TxConfirmationOfEthDrvApis_AR_23_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_23_11 UpdatePhysAddrFilterOfEthDrvApis_AR_23_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_23_11 WriteMiiOfEthDrvApis_AR_23_11;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_23_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_24_11 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_24_11Type
{
  Eth_EthControllerInitFctPtrType_AR_24_11 ControllerInitOfEthDrvApis_AR_24_11;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_24_11 EnableEgressTimeStampOfEthDrvApis_AR_24_11;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_24_11 GetControllerModeOfEthDrvApis_AR_24_11;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_24_11 GetCounterStateOfEthDrvApis_AR_24_11;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_24_11 GetCounterValuesOfEthDrvApis_AR_24_11;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_24_11 GetCurrentTimeOfEthDrvApis_AR_24_11;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetCurrentTimeTupleFctPtrType_AR_24_11 GetCurrentTimeTupleOfEthDrvApis_AR_24_11;  /**< Eth_GetCurrentTimeTuple() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_24_11 GetEgressTimeStampOfEthDrvApis_AR_24_11;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_24_11 GetIngressTimeStampOfEthDrvApis_AR_24_11;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhcTimeFctPtrType_AR_24_11 GetPhcTimeOfEthDrvApis_AR_24_11;  /**< Eth_GetPhcTime() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_24_11 GetPhysAddrOfEthDrvApis_AR_24_11;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_24_11 GetRxStatsOfEthDrvApis_AR_24_11;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_24_11 GetTxErrorCounterValuesOfEthDrvApis_AR_24_11;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_24_11 GetTxStatsOfEthDrvApis_AR_24_11;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthImmediateTransmitFctPtrType_AR_24_11 ImmediateTransmitOfEthDrvApis_AR_24_11;  /**< Eth_ImmediateTransmit() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_24_11 ProvideTxBufferOfEthDrvApis_AR_24_11;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_24_11 ReadMiiOfEthDrvApis_AR_24_11;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReadMmdFctPtrType_AR_24_11 ReadMmdOfEthDrvApis_AR_24_11;  /**< Eth_ReadMmd() of Eth driver. */
  Eth_EthReceiveFctPtrType_AR_24_11 ReceiveOfEthDrvApis_AR_24_11;  /**< Eth_Receive() of Eth driver */
  Eth_EthReleaseRxBufferFctPtrType_AR_24_11 ReleaseRxBufferOfEthDrvApis_AR_24_11;  /**< Eth_ReleaseRxBuffer() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_24_11 SetControllerModeOfEthDrvApis_AR_24_11;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhcCorrectionFctPtrType_AR_24_11 SetPhcCorrectionOfEthDrvApis_AR_24_11;  /**< Eth_SetPhcCorrection() of Eth driver. */
  Eth_EthSetPhcTimeFctPtrType_AR_24_11 SetPhcTimeOfEthDrvApis_AR_24_11;  /**< Eth_SetPhcTime() of Eth driver. */
  Eth_EthSetPhysAddrFctPtrType_AR_24_11 SetPhysAddrOfEthDrvApis_AR_24_11;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthSetPpsSignalModeFctPtrType_AR_24_11 SetPpsSignalModeOfEthDrvApis_AR_24_11;  /**< Eth_SetPpsSignalMode() of Eth driver. */
  Eth_EthTransmitFctPtrType_AR_24_11 TransmitOfEthDrvApis_AR_24_11;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_24_11 TxConfirmationOfEthDrvApis_AR_24_11;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_24_11 UpdatePhysAddrFilterOfEthDrvApis_AR_24_11;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_24_11 WriteMiiOfEthDrvApis_AR_24_11;  /**< Eth_WriteMii() of Eth driver */
  Eth_EthWriteMmdFctPtrType_AR_24_11 WriteMmdOfEthDrvApis_AR_24_11;  /**< Eth_WriteMmd() of Eth driver. */
} Eth_30_Wrapper_EthDrvApis_AR_24_11Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_4_1_3Type
{
  Eth_EthControllerInitFctPtrType_AR_4_1_3 ControllerInitOfEthDrvApis_AR_4_1_3;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_4_1_3 EnableEgressTimeStampOfEthDrvApis_AR_4_1_3;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_4_1_3 GetControllerModeOfEthDrvApis_AR_4_1_3;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_4_1_3 GetCounterStateOfEthDrvApis_AR_4_1_3;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_4_1_3 GetCounterValuesOfEthDrvApis_AR_4_1_3;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_4_1_3 GetCurrentTimeOfEthDrvApis_AR_4_1_3;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_4_1_3 GetEgressTimeStampOfEthDrvApis_AR_4_1_3;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_4_1_3 GetIngressTimeStampOfEthDrvApis_AR_4_1_3;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_4_1_3 GetPhysAddrOfEthDrvApis_AR_4_1_3;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_4_1_3 GetRxStatsOfEthDrvApis_AR_4_1_3;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_4_1_3 GetTxErrorCounterValuesOfEthDrvApis_AR_4_1_3;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_4_1_3 GetTxStatsOfEthDrvApis_AR_4_1_3;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_4_1_3 ProvideTxBufferOfEthDrvApis_AR_4_1_3;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_4_1_3 ReadMiiOfEthDrvApis_AR_4_1_3;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_4_1_3 ReceiveOfEthDrvApis_AR_4_1_3;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_4_1_3 SetControllerModeOfEthDrvApis_AR_4_1_3;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_4_1_3 SetPhysAddrOfEthDrvApis_AR_4_1_3;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_4_1_3 TransmitOfEthDrvApis_AR_4_1_3;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_4_1_3 TxConfirmationOfEthDrvApis_AR_4_1_3;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_4_1_3 UpdatePhysAddrFilterOfEthDrvApis_AR_4_1_3;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_4_1_3 WriteMiiOfEthDrvApis_AR_4_1_3;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_4_1_3Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_4_3_0Type
{
  Eth_EthControllerInitFctPtrType_AR_4_3_0 ControllerInitOfEthDrvApis_AR_4_3_0;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_4_3_0 EnableEgressTimeStampOfEthDrvApis_AR_4_3_0;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_4_3_0 GetControllerModeOfEthDrvApis_AR_4_3_0;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_4_3_0 GetCounterStateOfEthDrvApis_AR_4_3_0;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_4_3_0 GetCounterValuesOfEthDrvApis_AR_4_3_0;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_4_3_0 GetCurrentTimeOfEthDrvApis_AR_4_3_0;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_4_3_0 GetEgressTimeStampOfEthDrvApis_AR_4_3_0;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_4_3_0 GetIngressTimeStampOfEthDrvApis_AR_4_3_0;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_4_3_0 GetPhysAddrOfEthDrvApis_AR_4_3_0;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_4_3_0 GetRxStatsOfEthDrvApis_AR_4_3_0;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_4_3_0 GetTxErrorCounterValuesOfEthDrvApis_AR_4_3_0;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_4_3_0 GetTxStatsOfEthDrvApis_AR_4_3_0;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_4_3_0 ProvideTxBufferOfEthDrvApis_AR_4_3_0;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_4_3_0 ReadMiiOfEthDrvApis_AR_4_3_0;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_4_3_0 ReceiveOfEthDrvApis_AR_4_3_0;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_4_3_0 SetControllerModeOfEthDrvApis_AR_4_3_0;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_4_3_0 SetPhysAddrOfEthDrvApis_AR_4_3_0;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_4_3_0 TransmitOfEthDrvApis_AR_4_3_0;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_4_3_0 TxConfirmationOfEthDrvApis_AR_4_3_0;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_4_3_0 UpdatePhysAddrFilterOfEthDrvApis_AR_4_3_0;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_4_3_0 WriteMiiOfEthDrvApis_AR_4_3_0;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_4_3_0Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_4_3_1Type
{
  Eth_EthControllerInitFctPtrType_AR_4_3_1 ControllerInitOfEthDrvApis_AR_4_3_1;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_4_3_1 EnableEgressTimeStampOfEthDrvApis_AR_4_3_1;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_4_3_1 GetControllerModeOfEthDrvApis_AR_4_3_1;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_4_3_1 GetCounterStateOfEthDrvApis_AR_4_3_1;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_4_3_1 GetCounterValuesOfEthDrvApis_AR_4_3_1;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_4_3_1 GetCurrentTimeOfEthDrvApis_AR_4_3_1;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_4_3_1 GetEgressTimeStampOfEthDrvApis_AR_4_3_1;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_4_3_1 GetIngressTimeStampOfEthDrvApis_AR_4_3_1;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_4_3_1 GetPhysAddrOfEthDrvApis_AR_4_3_1;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_4_3_1 GetRxStatsOfEthDrvApis_AR_4_3_1;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_4_3_1 GetTxErrorCounterValuesOfEthDrvApis_AR_4_3_1;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_4_3_1 GetTxStatsOfEthDrvApis_AR_4_3_1;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_4_3_1 ProvideTxBufferOfEthDrvApis_AR_4_3_1;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_4_3_1 ReadMiiOfEthDrvApis_AR_4_3_1;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_4_3_1 ReceiveOfEthDrvApis_AR_4_3_1;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_4_3_1 SetControllerModeOfEthDrvApis_AR_4_3_1;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_4_3_1 SetPhysAddrOfEthDrvApis_AR_4_3_1;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_4_3_1 TransmitOfEthDrvApis_AR_4_3_1;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_4_3_1 TxConfirmationOfEthDrvApis_AR_4_3_1;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_4_3_1 UpdatePhysAddrFilterOfEthDrvApis_AR_4_3_1;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_4_3_1 WriteMiiOfEthDrvApis_AR_4_3_1;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_4_3_1Type;

/**   \brief  type used in Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
typedef struct sEth_30_Wrapper_EthDrvApis_AR_4_4_0Type
{
  Eth_EthControllerInitFctPtrType_AR_4_4_0 ControllerInitOfEthDrvApis_AR_4_4_0;  /**< Eth_ControllerInit() of Eth driver */
  Eth_EthEnableEgressTimeStampFctPtrType_AR_4_4_0 EnableEgressTimeStampOfEthDrvApis_AR_4_4_0;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  Eth_EthGetControllerModeFctPtrType_AR_4_4_0 GetControllerModeOfEthDrvApis_AR_4_4_0;  /**< Eth_GetControllerMode() of Eth driver */
  Eth_EthGetCounterStateFctPtrType_AR_4_4_0 GetCounterStateOfEthDrvApis_AR_4_4_0;  /**< Eth_GetCounterState() of Eth driver */
  Eth_EthGetCounterValuesFctPtrType_AR_4_4_0 GetCounterValuesOfEthDrvApis_AR_4_4_0;  /**< Eth_GetCounterValues() of Eth driver */
  Eth_EthGetCurrentTimeFctPtrType_AR_4_4_0 GetCurrentTimeOfEthDrvApis_AR_4_4_0;  /**< Eth_GetCurrentTime() of Eth driver. */
  Eth_EthGetEgressTimeStampFctPtrType_AR_4_4_0 GetEgressTimeStampOfEthDrvApis_AR_4_4_0;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  Eth_EthGetIngressTimeStampFctPtrType_AR_4_4_0 GetIngressTimeStampOfEthDrvApis_AR_4_4_0;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  Eth_EthGetPhysAddrFctPtrType_AR_4_4_0 GetPhysAddrOfEthDrvApis_AR_4_4_0;  /**< Eth_GetPhysAddr() of Eth driver */
  Eth_EthGetRxStatsFctPtrType_AR_4_4_0 GetRxStatsOfEthDrvApis_AR_4_4_0;  /**< Eth_GetRxStats() of Eth driver */
  Eth_EthGetTxErrorCounterValuesFctPtrType_AR_4_4_0 GetTxErrorCounterValuesOfEthDrvApis_AR_4_4_0;  /**< Eth_GetTxErrorCounterValues() of Eth driver */
  Eth_EthGetTxStatsFctPtrType_AR_4_4_0 GetTxStatsOfEthDrvApis_AR_4_4_0;  /**< Eth_GetTxStats() of Eth driver */
  Eth_EthProvideTxBufferFctPtrType_AR_4_4_0 ProvideTxBufferOfEthDrvApis_AR_4_4_0;  /**< Eth_ProvideTxBuffer() of Eth driver */
  Eth_EthReadMiiFctPtrType_AR_4_4_0 ReadMiiOfEthDrvApis_AR_4_4_0;  /**< Eth_ReadMii() of Eth driver */
  Eth_EthReceiveFctPtrType_AR_4_4_0 ReceiveOfEthDrvApis_AR_4_4_0;  /**< Eth_Receive() of Eth driver */
  Eth_EthSetControllerModeFctPtrType_AR_4_4_0 SetControllerModeOfEthDrvApis_AR_4_4_0;  /**< Eth_SetControllerMode() of Eth driver */
  Eth_EthSetPhysAddrFctPtrType_AR_4_4_0 SetPhysAddrOfEthDrvApis_AR_4_4_0;  /**< Eth_SetPhysAddr() of Eth driver */
  Eth_EthTransmitFctPtrType_AR_4_4_0 TransmitOfEthDrvApis_AR_4_4_0;  /**< Eth_Transmit() of Eth driver */
  Eth_EthTxConfirmationFctPtrType_AR_4_4_0 TxConfirmationOfEthDrvApis_AR_4_4_0;  /**< Eth_TxConfirmation() of Eth driver */
  Eth_EthUpdatePhysAddrFilterFctPtrType_AR_4_4_0 UpdatePhysAddrFilterOfEthDrvApis_AR_4_4_0;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  Eth_EthWriteMiiFctPtrType_AR_4_4_0 WriteMiiOfEthDrvApis_AR_4_4_0;  /**< Eth_WriteMii() of Eth driver */
} Eth_30_Wrapper_EthDrvApis_AR_4_4_0Type;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCSymbolicStructTypes  Eth_30_Wrapper Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Eth_30_Wrapper_ApiAccessMutex for debugging purposes */
typedef struct Eth_30_Wrapper_ApiAccessMutexStructSTag
{
  Eth_30_Wrapper_ApiAccessMutexType RDR_1_Eth_Controller_1_6addc1bb;
} Eth_30_Wrapper_ApiAccessMutexStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCUnionIndexAndSymbolTypes  Eth_30_Wrapper Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access Eth_30_Wrapper_ApiAccessMutex in an index and symbol based style for debugging purposes */
typedef union Eth_30_Wrapper_ApiAccessMutexUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Eth_30_Wrapper_ApiAccessMutexType raw[1];
  Eth_30_Wrapper_ApiAccessMutexStructSType str;
} Eth_30_Wrapper_ApiAccessMutexUType;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCRootPointerTypes  Eth_30_Wrapper Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Eth_30_Wrapper_ApiAccessMutex */
typedef P2VAR(Eth_30_Wrapper_ApiAccessMutexType, TYPEDEF, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_ApiAccessMutexPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutex */
typedef P2VAR(Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutexType, TYPEDEF, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_GetCurrentTimeApiLockedOfApiAccessMutexPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutex */
typedef P2VAR(Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutexType, TYPEDEF, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_GetCurrentTimeTupleApiLockedOfApiAccessMutexPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutex */
typedef P2VAR(Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutexType, TYPEDEF, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_ReadMiiApiLockedOfApiAccessMutexPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthCtrl */
typedef P2CONST(Eth_30_Wrapper_EthCtrlType, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthCtrlPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
typedef P2CONST(Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledType, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledPtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_19_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_19_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_19_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_20_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_20_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_20_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_21_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_21_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_21_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_22_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_22_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_22_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_23_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_23_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_23_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_24_11 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_24_11Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_24_11PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_4_1_3Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_1_3PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_4_3_0Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_3_0PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_4_3_1Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_3_1PtrType;

/**   \brief  type used to point to Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
typedef P2CONST(Eth_30_Wrapper_EthDrvApis_AR_4_4_0Type, TYPEDEF, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_4_0PtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCRootValueTypes  Eth_30_Wrapper Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Eth_30_Wrapper_PCConfig */
typedef struct sEth_30_Wrapper_PCConfigType
{
  Eth_30_Wrapper_ApiAccessMutexPtrType ApiAccessMutexOfPCConfig;  /**< the pointer to Eth_30_Wrapper_ApiAccessMutex */
  Eth_30_Wrapper_EthCtrlPtrType EthCtrlOfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthCtrl */
  Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolledPtrType EthCtrlConfigIngressQueuesPolledOfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
  Eth_30_Wrapper_EthDrvApis_AR_19_11PtrType EthDrvApis_AR_19_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_19_11 */
  Eth_30_Wrapper_EthDrvApis_AR_20_11PtrType EthDrvApis_AR_20_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_20_11 */
  Eth_30_Wrapper_EthDrvApis_AR_21_11PtrType EthDrvApis_AR_21_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_21_11 */
  Eth_30_Wrapper_EthDrvApis_AR_22_11PtrType EthDrvApis_AR_22_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_22_11 */
  Eth_30_Wrapper_EthDrvApis_AR_23_11PtrType EthDrvApis_AR_23_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_23_11 */
  Eth_30_Wrapper_EthDrvApis_AR_24_11PtrType EthDrvApis_AR_24_11OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_24_11 */
  Eth_30_Wrapper_EthDrvApis_AR_4_1_3PtrType EthDrvApis_AR_4_1_3OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
  Eth_30_Wrapper_EthDrvApis_AR_4_3_0PtrType EthDrvApis_AR_4_3_0OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
  Eth_30_Wrapper_EthDrvApis_AR_4_3_1PtrType EthDrvApis_AR_4_3_1OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
  Eth_30_Wrapper_EthDrvApis_AR_4_4_0PtrType EthDrvApis_AR_4_4_0OfPCConfig;  /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
  Eth_30_Wrapper_SizeOfEthCtrlType SizeOfEthCtrlOfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthCtrl */
  Eth_30_Wrapper_SizeOfEthCtrlConfigIngressQueuesPolledType SizeOfEthCtrlConfigIngressQueuesPolledOfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_19_11Type SizeOfEthDrvApis_AR_19_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_19_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_20_11Type SizeOfEthDrvApis_AR_20_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_20_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_21_11Type SizeOfEthDrvApis_AR_21_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_21_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_22_11Type SizeOfEthDrvApis_AR_22_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_22_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_23_11Type SizeOfEthDrvApis_AR_23_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_23_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_24_11Type SizeOfEthDrvApis_AR_24_11OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_24_11 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_1_3Type SizeOfEthDrvApis_AR_4_1_3OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_0Type SizeOfEthDrvApis_AR_4_3_0OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_3_1Type SizeOfEthDrvApis_AR_4_3_1OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
  Eth_30_Wrapper_SizeOfEthDrvApis_AR_4_4_0Type SizeOfEthDrvApis_AR_4_4_0OfPCConfig;  /**< the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
} Eth_30_Wrapper_PCConfigType;

typedef Eth_30_Wrapper_PCConfigType Eth_30_Wrapper_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access Eth_30_Wrapper_PCConfig in a symbol based style. */
typedef struct sEth_30_Wrapper_PCConfigsType
{
  Eth_30_Wrapper_PCConfigType Config;  /**< [Config] */
} Eth_30_Wrapper_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Eth_30_Wrapper_EthCtrl
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_EthCtrl
  \brief  Eth controller table
  \details
  Element                                     Description
  BufferIndexOffsetEnabled                
  CtrlIdx                                     EthWrapper Controller Index
  EthCtrlConfigIngressQueuesPolledEndIdx      the end index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthCtrlConfigIngressQueuesPolledStartIdx    the start index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthDrvApiInd                                the enum value of the according target of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11
  EthDrvApiIndIdx                             the index of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11
  SubCtrlIdx                                  Third-Party Controller Index
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Eth_30_Wrapper_EthCtrlType, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthCtrl[1];
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_EthDrvApis_AR_4_4_0
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_EthDrvApis_AR_4_4_0
  \brief  Eth driver APIs for AR_4_4_0
  \details
  Element                    Description
  ControllerInit             Eth_ControllerInit() of Eth driver
  EnableEgressTimeStamp      Eth_EnableEgressTimeStamp() of Eth driver.
  GetControllerMode          Eth_GetControllerMode() of Eth driver
  GetCounterState            Eth_GetCounterState() of Eth driver
  GetCounterValues           Eth_GetCounterValues() of Eth driver
  GetCurrentTime             Eth_GetCurrentTime() of Eth driver.
  GetEgressTimeStamp         Eth_GetEgressTimeStamp() of Eth driver.
  GetIngressTimeStamp        Eth_GetIngressTimeStamp() of Eth driver.
  GetPhysAddr                Eth_GetPhysAddr() of Eth driver
  GetRxStats                 Eth_GetRxStats() of Eth driver
  GetTxErrorCounterValues    Eth_GetTxErrorCounterValues() of Eth driver
  GetTxStats                 Eth_GetTxStats() of Eth driver
  ProvideTxBuffer            Eth_ProvideTxBuffer() of Eth driver
  ReadMii                    Eth_ReadMii() of Eth driver
  Receive                    Eth_Receive() of Eth driver
  SetControllerMode          Eth_SetControllerMode() of Eth driver
  SetPhysAddr                Eth_SetPhysAddr() of Eth driver
  Transmit                   Eth_Transmit() of Eth driver
  TxConfirmation             Eth_TxConfirmation() of Eth driver
  UpdatePhysAddrFilter       Eth_UpdatePhysAddrFilter() of Eth driver
  WriteMii                   Eth_WriteMii() of Eth driver
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Eth_30_Wrapper_EthDrvApis_AR_4_4_0Type, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_4_0[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_ApiAccessMutex
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_ApiAccessMutex
  \brief  Api access mutex for dedicated APIs that are defined by AUTOSAR as non-reentrant but are reentrant by the EthWrapper.
  \details
  Element                         Description
  GetCurrentTimeApiLocked         Indicates if the Eth_GetCurrentTime is locked by an ISR/TASK
  GetCurrentTimeTupleApiLocked    Indicates if the Eth_GetCurrentTimeTuple is locked by an ISR/TASK
  ReadMiiApiLocked                Indicates if the Eth_ReadMii is locked by an ISR/TASK
*/ 
#define ETH_30_WRAPPER_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_30_Wrapper_ApiAccessMutexUType, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_ApiAccessMutex;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define ETH_30_WRAPPER_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_PCConfig
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_PCConfig
  \details
  Element                                   Description
  ApiAccessMutex                            the pointer to Eth_30_Wrapper_ApiAccessMutex
  EthCtrl                                   the pointer to Eth_30_Wrapper_EthCtrl
  EthCtrlConfigIngressQueuesPolled          the pointer to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthDrvApis_AR_19_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_19_11
  EthDrvApis_AR_20_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_20_11
  EthDrvApis_AR_21_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_21_11
  EthDrvApis_AR_22_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_22_11
  EthDrvApis_AR_23_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_23_11
  EthDrvApis_AR_24_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_24_11
  EthDrvApis_AR_4_1_3                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_1_3
  EthDrvApis_AR_4_3_0                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_0
  EthDrvApis_AR_4_3_1                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_1
  EthDrvApis_AR_4_4_0                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_4_0
  SizeOfEthCtrl                             the number of accomplishable value elements in Eth_30_Wrapper_EthCtrl
  SizeOfEthCtrlConfigIngressQueuesPolled    the number of accomplishable value elements in Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  SizeOfEthDrvApis_AR_19_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_19_11
  SizeOfEthDrvApis_AR_20_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_20_11
  SizeOfEthDrvApis_AR_21_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_21_11
  SizeOfEthDrvApis_AR_22_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_22_11
  SizeOfEthDrvApis_AR_23_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_23_11
  SizeOfEthDrvApis_AR_24_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_24_11
  SizeOfEthDrvApis_AR_4_1_3                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_1_3
  SizeOfEthDrvApis_AR_4_3_0                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_0
  SizeOfEthDrvApis_AR_4_3_1                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_1
  SizeOfEthDrvApis_AR_4_4_0                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_4_0
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Eth_30_Wrapper_PCConfigsType, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_PCConfig;
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  Eth_30_Wrapper_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    Eth_30_Wrapper_ConfigDataPtr
  \brief  Points to the currently active configuration for EthWrapper
  \details
  Pointer is initialized during EthWrapper_Init() and holds the active configuration for EthWrapper were all configuration data
  is retrieved from during runtime.
*/
#define ETH_30_WRAPPER_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
extern P2CONST(Eth_30_Wrapper_ConfigType, ETH_30_WRAPPER_VAR_NO_INIT, ETH_30_WRAPPER_INIT_DATA) Eth_30_Wrapper_ConfigDataPtr;
#define ETH_30_WRAPPER_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */


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
  \defgroup  Eth_30_WrapperPCGetRootDataMacros  Eth_30_Wrapper Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()                                                Eth_30_Wrapper_ConfigDataPtr->ApiAccessMutexOfPCConfig
#define Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledOfPCConfig()                              Eth_30_Wrapper_ConfigDataPtr->EthCtrlConfigIngressQueuesPolledOfPCConfig
#define Eth_30_Wrapper_GetEthCtrlOfPCConfig()                                                       Eth_30_Wrapper_ConfigDataPtr->EthCtrlOfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_19_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_20_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_21_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_22_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_23_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_24_11OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_4_1_3OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_4_3_0OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_4_3_1OfPCConfig
#define Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()                                           Eth_30_Wrapper_ConfigDataPtr->EthDrvApis_AR_4_4_0OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthCtrlConfigIngressQueuesPolledOfPCConfig()                        Eth_30_Wrapper_ConfigDataPtr->SizeOfEthCtrlConfigIngressQueuesPolledOfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthCtrlOfPCConfig()                                                 Eth_30_Wrapper_ConfigDataPtr->SizeOfEthCtrlOfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_19_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_19_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_20_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_20_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_21_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_21_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_22_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_22_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_23_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_23_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_24_11OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_24_11OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_1_3OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_4_1_3OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_0OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_4_3_0OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_1OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_4_3_1OfPCConfig
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_4_0OfPCConfig()                                     Eth_30_Wrapper_ConfigDataPtr->SizeOfEthDrvApis_AR_4_4_0OfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCGetDuplicatedRootDataMacros  Eth_30_Wrapper Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Eth_30_Wrapper_GetSizeOfApiAccessMutexOfPCConfig()                                          Eth_30_Wrapper_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in Eth_30_Wrapper_ApiAccessMutex */
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCGetDataMacros  Eth_30_Wrapper Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Eth_30_Wrapper_IsGetCurrentTimeApiLockedOfApiAccessMutex(Index)                             ((Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeApiLockedOfApiAccessMutex) != FALSE)
#define Eth_30_Wrapper_IsGetCurrentTimeTupleApiLockedOfApiAccessMutex(Index)                        ((Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeTupleApiLockedOfApiAccessMutex) != FALSE)
#define Eth_30_Wrapper_IsReadMiiApiLockedOfApiAccessMutex(Index)                                    ((Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].ReadMiiApiLockedOfApiAccessMutex) != FALSE)
#define Eth_30_Wrapper_IsBufferIndexOffsetEnabledOfEthCtrl(Index)                                   ((Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].BufferIndexOffsetEnabledOfEthCtrl) != FALSE)
#define Eth_30_Wrapper_GetCtrlIdxOfEthCtrl(Index)                                                   (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].CtrlIdxOfEthCtrl)
#define Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrl(Index)                    (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].EthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrl)
#define Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl(Index)                  (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].EthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl)
#define Eth_30_Wrapper_GetEthDrvApiIndIdxOfEthCtrl(Index)                                           (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].EthDrvApiIndIdxOfEthCtrl)
#define Eth_30_Wrapper_GetEthDrvApiIndOfEthCtrl(Index)                                              (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].EthDrvApiIndOfEthCtrl)
#define Eth_30_Wrapper_GetSubCtrlIdxOfEthCtrl(Index)                                                (Eth_30_Wrapper_GetEthCtrlOfPCConfig()[(Index)].SubCtrlIdxOfEthCtrl)
#define Eth_30_Wrapper_GetEthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolled(Index)     (Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledOfPCConfig()[(Index)].EthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolled)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_19_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_19_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_19_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_19_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_19_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_19_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_19_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_19_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_19_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_19_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_19_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_19_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_19_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_19_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_19_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_19_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_19_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_19_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_19_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_19_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_19_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_19_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_20_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_20_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_20_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_20_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_20_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_20_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_20_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_20_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_20_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_20_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_20_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_20_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_20_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_20_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_20_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_20_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_20_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_20_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_20_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_20_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_20_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_20_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_21_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_21_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_21_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_21_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_21_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_21_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_21_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_21_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_21_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_21_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_21_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_21_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_21_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_21_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_21_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_21_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_21_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_21_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_21_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_21_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_21_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_21_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_22_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_22_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_22_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_22_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_22_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_22_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_22_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_22_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_22_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_22_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_22_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_22_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_22_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_22_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_22_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_22_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_22_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_22_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_22_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_22_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_22_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_22_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_23_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_23_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_23_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_23_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_23_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_23_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetCurrentTimeTupleOfEthDrvApis_AR_23_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetCurrentTimeTupleOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_23_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_23_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetPhcTimeOfEthDrvApis_AR_23_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetPhcTimeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_23_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_23_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_23_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_23_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetImmediateTransmitOfEthDrvApis_AR_23_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ImmediateTransmitOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_23_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_23_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_23_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetReleaseRxBufferOfEthDrvApis_AR_23_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].ReleaseRxBufferOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_23_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetSetPhcCorrectionOfEthDrvApis_AR_23_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].SetPhcCorrectionOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetSetPhcTimeOfEthDrvApis_AR_23_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].SetPhcTimeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_23_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetSetPpsSignalModeOfEthDrvApis_AR_23_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].SetPpsSignalModeOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_23_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_23_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_23_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_23_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_23_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_24_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_24_11(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_24_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_24_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_24_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_24_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetCurrentTimeTupleOfEthDrvApis_AR_24_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetCurrentTimeTupleOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_24_11(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_24_11(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetPhcTimeOfEthDrvApis_AR_24_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetPhcTimeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_24_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_24_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_24_11(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_24_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetImmediateTransmitOfEthDrvApis_AR_24_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ImmediateTransmitOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_24_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_24_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetReadMmdOfEthDrvApis_AR_24_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ReadMmdOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_24_11(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetReleaseRxBufferOfEthDrvApis_AR_24_11(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].ReleaseRxBufferOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_24_11(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetSetPhcCorrectionOfEthDrvApis_AR_24_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].SetPhcCorrectionOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetSetPhcTimeOfEthDrvApis_AR_24_11(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].SetPhcTimeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_24_11(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetSetPpsSignalModeOfEthDrvApis_AR_24_11(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].SetPpsSignalModeOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_24_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_24_11(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_24_11(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_24_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetWriteMmdOfEthDrvApis_AR_24_11(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig()[(Index)].WriteMmdOfEthDrvApis_AR_24_11)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_4_1_3(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_4_1_3(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_4_1_3(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_4_1_3(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_4_1_3(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_4_1_3(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_4_1_3(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_4_1_3(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_4_1_3(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_4_1_3(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_4_1_3(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_4_1_3(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_4_1_3(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_4_1_3(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_4_1_3(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_4_1_3(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_4_1_3(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_4_1_3(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_4_1_3(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_4_1_3(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_4_1_3(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_4_1_3)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_4_3_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_4_3_0(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_4_3_0(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_4_3_0(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_4_3_0(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_4_3_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_4_3_0(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_4_3_0(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_4_3_0(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_4_3_0(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_4_3_0(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_4_3_0(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_4_3_0(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_4_3_0(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_4_3_0(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_4_3_0(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_4_3_0(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_4_3_0(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_4_3_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_4_3_0(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_4_3_0(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_4_3_0)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_4_3_1(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_4_3_1(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_4_3_1(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_4_3_1(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_4_3_1(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_4_3_1(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_4_3_1(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_4_3_1(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_4_3_1(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_4_3_1(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_4_3_1(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_4_3_1(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_4_3_1(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_4_3_1(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_4_3_1(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_4_3_1(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_4_3_1(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_4_3_1(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_4_3_1(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_4_3_1(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_4_3_1(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_4_3_1)
#define Eth_30_Wrapper_GetControllerInitOfEthDrvApis_AR_4_4_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].ControllerInitOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetEnableEgressTimeStampOfEthDrvApis_AR_4_4_0(Index)                         (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetControllerModeOfEthDrvApis_AR_4_4_0(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetControllerModeOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetCounterStateOfEthDrvApis_AR_4_4_0(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetCounterStateOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetCounterValuesOfEthDrvApis_AR_4_4_0(Index)                              (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetCounterValuesOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetCurrentTimeOfEthDrvApis_AR_4_4_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetEgressTimeStampOfEthDrvApis_AR_4_4_0(Index)                            (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetIngressTimeStampOfEthDrvApis_AR_4_4_0(Index)                           (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetPhysAddrOfEthDrvApis_AR_4_4_0(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetPhysAddrOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetRxStatsOfEthDrvApis_AR_4_4_0(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetRxStatsOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetTxErrorCounterValuesOfEthDrvApis_AR_4_4_0(Index)                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetTxErrorCounterValuesOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetGetTxStatsOfEthDrvApis_AR_4_4_0(Index)                                    (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].GetTxStatsOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetProvideTxBufferOfEthDrvApis_AR_4_4_0(Index)                               (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetReadMiiOfEthDrvApis_AR_4_4_0(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].ReadMiiOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetReceiveOfEthDrvApis_AR_4_4_0(Index)                                       (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].ReceiveOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetSetControllerModeOfEthDrvApis_AR_4_4_0(Index)                             (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].SetControllerModeOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetSetPhysAddrOfEthDrvApis_AR_4_4_0(Index)                                   (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].SetPhysAddrOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetTransmitOfEthDrvApis_AR_4_4_0(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].TransmitOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetTxConfirmationOfEthDrvApis_AR_4_4_0(Index)                                (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].TxConfirmationOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetUpdatePhysAddrFilterOfEthDrvApis_AR_4_4_0(Index)                          (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApis_AR_4_4_0)
#define Eth_30_Wrapper_GetWriteMiiOfEthDrvApis_AR_4_4_0(Index)                                      (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig()[(Index)].WriteMiiOfEthDrvApis_AR_4_4_0)
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCGetDeduplicatedDataMacros  Eth_30_Wrapper Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Eth_30_Wrapper_IsEthCtrlConfigIngressQueuesPolledUsedOfEthCtrl(Index)                       (((boolean)(Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl(Index) != ETH_30_WRAPPER_NO_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
#define Eth_30_Wrapper_IsEthDrvApiIndUsedOfEthCtrl(Index)                                           (((boolean)(Eth_30_Wrapper_GetEthDrvApiIndIdxOfEthCtrl(Index) != ETH_30_WRAPPER_NO_ETHDRVAPIINDIDXOFETHCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11 */
#define Eth_30_Wrapper_GetSizeOfApiAccessMutex()                                                    Eth_30_Wrapper_GetSizeOfApiAccessMutexOfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthCtrl()                                                           Eth_30_Wrapper_GetSizeOfEthCtrlOfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthCtrlConfigIngressQueuesPolled()                                  Eth_30_Wrapper_GetSizeOfEthCtrlConfigIngressQueuesPolledOfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_19_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_19_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_20_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_20_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_21_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_21_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_22_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_22_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_23_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_23_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_24_11()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_24_11OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_1_3()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_1_3OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_0()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_0OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_1()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_3_1OfPCConfig()
#define Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_4_0()                                               Eth_30_Wrapper_GetSizeOfEthDrvApis_AR_4_4_0OfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCSetDataMacros  Eth_30_Wrapper Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Eth_30_Wrapper_SetGetCurrentTimeApiLockedOfApiAccessMutex(Index, Value)                     Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeApiLockedOfApiAccessMutex = (Value)
#define Eth_30_Wrapper_SetGetCurrentTimeTupleApiLockedOfApiAccessMutex(Index, Value)                Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeTupleApiLockedOfApiAccessMutex = (Value)
#define Eth_30_Wrapper_SetReadMiiApiLockedOfApiAccessMutex(Index, Value)                            Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].ReadMiiApiLockedOfApiAccessMutex = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCGetAddressOfDataMacros  Eth_30_Wrapper Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Eth_30_Wrapper_GetAddrGetCurrentTimeApiLockedOfApiAccessMutex(Index)                        (&(Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeApiLockedOfApiAccessMutex))
#define Eth_30_Wrapper_GetAddrGetCurrentTimeTupleApiLockedOfApiAccessMutex(Index)                   (&(Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].GetCurrentTimeTupleApiLockedOfApiAccessMutex))
#define Eth_30_Wrapper_GetAddrReadMiiApiLockedOfApiAccessMutex(Index)                               (&(Eth_30_Wrapper_GetApiAccessMutexOfPCConfig()[(Index)].ReadMiiApiLockedOfApiAccessMutex))
/** 
  \}
*/ 

/** 
  \defgroup  Eth_30_WrapperPCHasMacros  Eth_30_Wrapper Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Eth_30_Wrapper_HasApiAccessMutex()                                                          (Eth_30_Wrapper_GetApiAccessMutexOfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasGetCurrentTimeApiLockedOfApiAccessMutex()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeTupleApiLockedOfApiAccessMutex()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiApiLockedOfApiAccessMutex()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrl()                                                                 (Eth_30_Wrapper_GetEthCtrlOfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasBufferIndexOffsetEnabledOfEthCtrl()                                       (TRUE != FALSE)
#define Eth_30_Wrapper_HasCtrlIdxOfEthCtrl()                                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueuesPolledEndIdxOfEthCtrl()                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueuesPolledStartIdxOfEthCtrl()                       (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueuesPolledUsedOfEthCtrl()                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApiIndIdxOfEthCtrl()                                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApiIndOfEthCtrl()                                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApiIndUsedOfEthCtrl()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSubCtrlIdxOfEthCtrl()                                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueuesPolled()                                        (Eth_30_Wrapper_GetEthCtrlConfigIngressQueuesPolledOfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueueIdxOfEthCtrlConfigIngressQueuesPolled()          (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_19_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_19_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_19_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_19_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_19_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_19_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_19_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_19_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_19_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_19_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_19_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_19_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_19_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_19_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_19_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_19_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_19_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_19_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_19_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_19_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_19_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_19_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_19_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_20_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_20_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_20_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_20_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_20_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_20_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_20_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_20_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_20_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_20_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_20_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_20_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_20_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_20_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_20_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_20_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_20_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_20_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_20_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_20_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_20_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_20_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_20_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_21_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_21_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_21_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_21_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_21_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_21_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_21_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_21_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_21_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_21_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_21_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_21_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_21_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_21_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_21_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_21_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_21_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_21_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_21_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_21_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_21_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_21_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_21_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_22_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_22_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_22_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_22_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_22_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_22_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_22_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_22_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_22_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_22_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_22_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_22_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_22_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_22_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_22_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_22_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_22_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_22_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_22_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_22_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_22_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_22_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_22_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_23_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_23_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_23_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_23_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_23_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_23_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_23_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_23_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeTupleOfEthDrvApis_AR_23_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_23_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_23_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhcTimeOfEthDrvApis_AR_23_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_23_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_23_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_23_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_23_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasImmediateTransmitOfEthDrvApis_AR_23_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_23_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_23_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_23_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReleaseRxBufferOfEthDrvApis_AR_23_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_23_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhcCorrectionOfEthDrvApis_AR_23_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhcTimeOfEthDrvApis_AR_23_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_23_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPpsSignalModeOfEthDrvApis_AR_23_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_23_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_23_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_23_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_23_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_24_11()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_24_11OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_24_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_24_11()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_24_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_24_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_24_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_24_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeTupleOfEthDrvApis_AR_24_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_24_11()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_24_11()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhcTimeOfEthDrvApis_AR_24_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_24_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_24_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_24_11()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_24_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasImmediateTransmitOfEthDrvApis_AR_24_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_24_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_24_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMmdOfEthDrvApis_AR_24_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_24_11()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReleaseRxBufferOfEthDrvApis_AR_24_11()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_24_11()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhcCorrectionOfEthDrvApis_AR_24_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhcTimeOfEthDrvApis_AR_24_11()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_24_11()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPpsSignalModeOfEthDrvApis_AR_24_11()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_24_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_24_11()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_24_11()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_24_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMmdOfEthDrvApis_AR_24_11()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_1_3()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_4_1_3OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_4_1_3()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_4_1_3()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_4_1_3()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_4_1_3()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_4_1_3()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_4_1_3()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_4_1_3()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_4_1_3()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_4_1_3()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_4_1_3()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_4_1_3()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_4_1_3()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_4_1_3()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_4_1_3()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_4_1_3()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_4_1_3()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_4_1_3()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_4_1_3()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_4_1_3()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_4_1_3()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_4_1_3()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_3_0()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_0OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_4_3_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_4_3_0()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_4_3_0()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_4_3_0()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_4_3_0()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_4_3_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_4_3_0()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_4_3_0()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_4_3_0()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_4_3_0()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_4_3_0()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_4_3_0()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_4_3_0()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_4_3_0()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_4_3_0()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_4_3_0()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_4_3_0()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_4_3_0()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_4_3_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_4_3_0()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_4_3_0()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_3_1()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_4_3_1OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_4_3_1()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_4_3_1()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_4_3_1()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_4_3_1()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_4_3_1()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_4_3_1()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_4_3_1()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_4_3_1()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_4_3_1()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_4_3_1()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_4_3_1()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_4_3_1()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_4_3_1()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_4_3_1()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_4_3_1()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_4_3_1()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_4_3_1()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_4_3_1()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_4_3_1()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_4_3_1()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_4_3_1()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_4_0()                                                     (Eth_30_Wrapper_GetEthDrvApis_AR_4_4_0OfPCConfig() != NULL_PTR)
#define Eth_30_Wrapper_HasControllerInitOfEthDrvApis_AR_4_4_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasEnableEgressTimeStampOfEthDrvApis_AR_4_4_0()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetControllerModeOfEthDrvApis_AR_4_4_0()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterStateOfEthDrvApis_AR_4_4_0()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCounterValuesOfEthDrvApis_AR_4_4_0()                                   (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetCurrentTimeOfEthDrvApis_AR_4_4_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetEgressTimeStampOfEthDrvApis_AR_4_4_0()                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetIngressTimeStampOfEthDrvApis_AR_4_4_0()                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetPhysAddrOfEthDrvApis_AR_4_4_0()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetRxStatsOfEthDrvApis_AR_4_4_0()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxErrorCounterValuesOfEthDrvApis_AR_4_4_0()                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasGetTxStatsOfEthDrvApis_AR_4_4_0()                                         (TRUE != FALSE)
#define Eth_30_Wrapper_HasProvideTxBufferOfEthDrvApis_AR_4_4_0()                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasReadMiiOfEthDrvApis_AR_4_4_0()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasReceiveOfEthDrvApis_AR_4_4_0()                                            (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetControllerModeOfEthDrvApis_AR_4_4_0()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSetPhysAddrOfEthDrvApis_AR_4_4_0()                                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasTransmitOfEthDrvApis_AR_4_4_0()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasTxConfirmationOfEthDrvApis_AR_4_4_0()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasUpdatePhysAddrFilterOfEthDrvApis_AR_4_4_0()                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasWriteMiiOfEthDrvApis_AR_4_4_0()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfApiAccessMutex()                                                    (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthCtrl()                                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthCtrlConfigIngressQueuesPolled()                                  (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_19_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_20_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_21_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_22_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_23_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_24_11()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_1_3()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_3_0()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_3_1()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_4_0()                                               (TRUE != FALSE)
#define Eth_30_Wrapper_HasPCConfig()                                                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasApiAccessMutexOfPCConfig()                                                (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlConfigIngressQueuesPolledOfPCConfig()                              (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthCtrlOfPCConfig()                                                       (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_19_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_20_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_21_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_22_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_23_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_24_11OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_1_3OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_3_0OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_3_1OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasEthDrvApis_AR_4_4_0OfPCConfig()                                           (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfApiAccessMutexOfPCConfig()                                          (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthCtrlConfigIngressQueuesPolledOfPCConfig()                        (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthCtrlOfPCConfig()                                                 (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_19_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_20_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_21_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_22_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_23_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_24_11OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_1_3OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_3_0OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_3_1OfPCConfig()                                     (TRUE != FALSE)
#define Eth_30_Wrapper_HasSizeOfEthDrvApis_AR_4_4_0OfPCConfig()                                     (TRUE != FALSE)
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

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/



#endif /* ETH_30_WRAPPER_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Wrapper_Lcfg.h
 *********************************************************************************************************************/
