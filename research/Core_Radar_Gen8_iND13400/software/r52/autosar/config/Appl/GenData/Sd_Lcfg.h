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
 *            Module: Sd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Sd_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:21
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
#if !defined (SD_LCFG_H)
# define SD_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Sd_Types.h"
# include "Os.h"

/**********************************************************************************************************************
*  CAPABILITY RECORD USER FUNCTION CALLOUT DECLARATION
**********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL CUSTOM DEFINES
 *********************************************************************************************************************/
 #define SD_NO_OS_APPL_MAPPED 65535u

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SdPCDataSwitches  Sd Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SD_ACLIPV4                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDROFACLIPV4                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4CIND                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4SIND                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDROFACLIPV6                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6CIND                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6SIND                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGE                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDROFADDRESSSTORAGE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_FLAGSOFADDRESSSTORAGE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REBOOTDETECTEDOFADDRESSSTORAGE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXMULTICASTFLAGSOFADDRESSSTORAGE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXMULTICASTSESSIONIDOFADDRESSSTORAGE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXUNICASTFLAGSOFADDRESSSTORAGE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXUNICASTSESSIONIDOFADDRESSSTORAGE                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYHEADIDXOFADDRESSSTORAGE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYNRPENDINGIDXOFADDRESSSTORAGE                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYTAILIDXOFADDRESSSTORAGE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SESSIONIDCOUNTEROFADDRESSSTORAGE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMETOSENDOFADDRESSSTORAGE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORD                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTR                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENT                                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4CINDENDIDXOFCLIENT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4CINDSTARTIDXOFCLIENT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4CINDUSEDOFCLIENT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6CINDENDIDXOFCLIENT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6CINDSTARTIDXOFCLIENT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6CINDUSEDOFCLIENT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_AUTOREQUIREOFCLIENT                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDENDIDXOFCLIENT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFCLIENT                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDSTARTIDXOFCLIENT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDUSEDOFCLIENT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTTIMERIDXOFCLIENT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAYIDXOFCLIENT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAYUSEDOFCLIENT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPENDIDXOFCLIENT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPSTARTIDXOFCLIENT                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPUSEDOFCLIENT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_FINDBEHAVIOROFCLIENT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_HANDLEIDOFCLIENT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALINSTANCEIDOFCLIENT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDXOFCLIENT                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MAJORVERSIONOFCLIENT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODIDXOFCLIENT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODUSEDOFCLIENT                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MINORVERSIONOFCLIENT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MINORVERSIONWILDCARDOFCLIENT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBEROFCLIENT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEIDOFCLIENT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNTCPIDXOFCLIENT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNTCPUSEDOFCLIENT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNUDPIDXOFCLIENT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNUDPUSEDOFCLIENT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDENDIDXOFCLIENT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDSTARTIDXOFCLIENT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDUSEDOFCLIENT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPCLIENTMULTICASTOFCLIENT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONENDIDXOFCLIENT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONSTARTIDXOFCLIENT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONUSEDOFCLIENT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTDYN                                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGECURRENTSERVERIDXOFCLIENTDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGESERVERIDXOFCLIENTDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CURRENTSTATEOFCLIENTDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTMAINOFCLIENTDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTRXOFCLIENTDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDOFCLIENTDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODTCPSOCONIDOFCLIENTDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODUDPSOCONIDOFCLIENTDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_OFFEREDTTLOFCLIENTDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REPETITIONRUNOFCLIENTDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RETRYCOUNTEROFCLIENTDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RETRYTIMEROFCLIENTDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERTCPENDPOINTADDROFCLIENTDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERUDPENDPOINTADDROFCLIENTDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPREQCOUNTEROFCLIENTDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEEXECUTIONREQUESTEDOFCLIENTDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEOFCLIENTDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATESWCOFCLIENTDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMETOTRIGGERSENDOFCLIENTDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMERTTLOFCLIENTDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTIDMAP                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFCLIENTIDMAP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCLIENTIDXOFCLIENTIDMAP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCLIENTPARTITIONIDXOFCLIENTIDMAP                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCLIENTUSEDOFCLIENTIDMAP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLIST                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGEIDXOFCLIENTLIST                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ASSIGNEDTCPSOCONIDOFCLIENTLIST                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ASSIGNEDUDPSOCONIDOFCLIENTLIST                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTSTATEOFCLIENTLIST                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGETCPIDXOFCLIENTLIST                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGEUDPIDXOFCLIENTLIST                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NROFREFERENCESOFCLIENTLIST                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTEDTTLOFCLIENTLIST                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXRESERVEDOFCLIENTLIST                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SUBSCRIBEDUNTILOFCLIENTLIST                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTTIMER                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALFINDDELAYMAXOFCLIENTTIMER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALFINDDELAYMINOFCLIENTTIMER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALFINDREPETITIONBASEDELAYOFCLIENTTIMER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALFINDREPETITIONSMAXOFCLIENTTIMER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTRESPONSEMAXDELAYOFCLIENTTIMER                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTRESPONSEMINDELAYOFCLIENTTIMER                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TTLOFCLIENTTIMER                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAY                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_AUTOREQUIREOFCONSUMEDEVENTGROUP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTIDXOFCONSUMEDEVENTGROUP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTTIMERIDXOFCONSUMEDEVENTGROUP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTGROUPIDOFCONSUMEDEVENTGROUP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_HANDLEIDOFCONSUMEDEVENTGROUP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTENDPOINTADDRUSEDOFCONSUMEDEVENTGROUP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONIDENDIDXOFCONSUMEDEVENTGROUP                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONIDUSEDOFCONSUMEDEVENTGROUP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPMULTICASTACTREFUSEDOFCONSUMEDEVENTGROUP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTCPACTREFUSEDOFCONSUMEDEVENTGROUP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPUDPACTREFIDXOFCONSUMEDEVENTGROUP                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPUDPACTREFUSEDOFCONSUMEDEVENTGROUP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACKNOWLEDGEDTTLOFCONSUMEDEVENTGROUPDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CURRENTSTATEOFCONSUMEDEVENTGROUPDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTOFCONSUMEDEVENTGROUPDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONIDOFCONSUMEDEVENTGROUPDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXINDICATIONCOUNTOFCONSUMEDEVENTGROUPDYN                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEMODEREQUESTOFCONSUMEDEVENTGROUPDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEOFCONSUMEDEVENTGROUPDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDOFCONSUMEDEVENTGROUPDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMERTTLOFCONSUMEDEVENTGROUPDYN                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERSUBSCRIPTIONOFCONSUMEDEVENTGROUPDYN                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONIDOFCONSUMEDEVENTGROUPDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPIDMAP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFCONSUMEDEVENTGROUPIDMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCONSUMEDEVENTGROUPIDXOFCONSUMEDEVENTGROUPIDMAP                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCONSUMEDEVENTGROUPPARTITIONIDXOFCONSUMEDEVENTGROUPIDMAP                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICCONSUMEDEVENTGROUPUSEDOFCONSUMEDEVENTGROUPIDMAP                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGE                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDROFENDPOINTSTORAGE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NROFREFERENCESOFENDPOINTSTORAGE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TYPEOFENDPOINTSTORAGE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTENDIDXOFEVENTHANDLER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTSTARTIDXOFEVENTHANDLER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTGROUPIDOFEVENTHANDLER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERMULTICASTUSEDOFEVENTHANDLER                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERTCPIDXOFEVENTHANDLER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERTCPUSEDOFEVENTHANDLER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUDPIDXOFEVENTHANDLER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUDPUSEDOFEVENTHANDLER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_HANDLEIDOFEVENTHANDLER                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTTHRESHOLDOFEVENTHANDLER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDXOFEVENTHANDLER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERTIMERIDXOFEVENTHANDLER                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONACTIVATIONMAPENDIDXOFEVENTHANDLER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONACTIVATIONMAPSTARTIDXOFEVENTHANDLER                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONACTIVATIONMAPUSEDOFEVENTHANDLER                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERDYN                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NROFCLIENTSOFEVENTHANDLERDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTSTATEOFEVENTHANDLERDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEOFEVENTHANDLERDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERMULTICAST                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFIDXOFEVENTHANDLERMULTICAST                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERMULTICAST                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONIDOFEVENTHANDLERMULTICAST                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERTCP                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFIDXOFEVENTHANDLERTCP                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERTCP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERTCP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERTCP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUDP                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFIDXOFEVENTHANDLERUDP                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERUDP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERUDP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_FINALMAGICNUMBER                                                                         STD_OFF  /**< Deactivateable: 'Sd_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SD_INITDATAHASHCODE                                                                         STD_OFF  /**< Deactivateable: 'Sd_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SD_INSTANCE                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGEENDIDXOFINSTANCE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGESTARTIDXOFINSTANCE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDENDIDXOFINSTANCE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDSTARTIDXOFINSTANCE                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDUSEDOFINSTANCE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTENDIDXOFINSTANCE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTSTARTIDXOFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTUSEDOFINSTANCE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EMALFORMEDMSGIDOFINSTANCE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENACKRECVIDOFINSTANCE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EOUTOFRESIDOFINSTANCE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGEENDIDXOFINSTANCE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGESTARTIDXOFINSTANCE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERENDIDXOFINSTANCE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERSTARTIDXOFINSTANCE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUSEDOFINSTANCE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_LOCALADDRESSCHECKLENGTHOFINSTANCE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTRXPDUIDOFINSTANCE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTRXSOCONIDOFINSTANCE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_QUEUEPROCESSLIMITOFINSTANCE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RETRYDELAYOFINSTANCE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RETRYMAXOFINSTANCE                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTENDIDXOFINSTANCE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTSTARTIDXOFINSTANCE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTUSEDOFINSTANCE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYCAPACITYOFINSTANCE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYENDIDXOFINSTANCE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYSTARTIDXOFINSTANCE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERENDIDXOFINSTANCE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERSTARTIDXOFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERUSEDOFINSTANCE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SEVDUPLICATEOFFEROFINSTANCE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SEVFAILEDMETHODREQOFINSTANCE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SEVFAILEDOFFEROFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SEVFAILEDSUBOFINSTANCE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDENDIDXOFINSTANCE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDSTARTIDXOFINSTANCE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDUSEDOFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TXPDUIDOFINSTANCE                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TXSOCONIDOFINSTANCE                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONENDIDXOFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONSTARTIDXOFINSTANCE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONUSEDOFINSTANCE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UNICASTRXPDUIDOFINSTANCE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UNICASTRXSOCONIDOFINSTANCE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEDYN                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_LASTFOUNDENDPOINTOFINSTANCEDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NEXTSTATEMACHINERUNOFINSTANCEDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RUNMODEOFINSTANCEDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTENDIDXOFINSTANCEDYN                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTLISTFULLOFINSTANCEDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTSTARTIDXOFINSTANCEDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYFREELISTHEADIDXOFINSTANCEDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYFREELISTTAILIDXOFINSTANCEDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYNRPENDINGIDXOFINSTANCEDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEOFINSTANCEDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_IPADDRREQUEST                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PORTSETIDXOFIPADDRREQUEST                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTCNTIDXOFIPADDRREQUEST                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONIDOFIPADDRREQUEST                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATICIPCONFIGURATIONOFIPADDRREQUEST                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATICPORTCONFIGURATIONOFIPADDRREQUEST                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MAXNROPTIONSPERENTRY                                                                     STD_ON
#define SD_METHOD                                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFIDXOFMETHOD                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPACTREFUSEDOFMETHOD                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPCONFIGUREDOFMETHOD                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPCONFIGUREDOFMETHOD                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTENDPOINTADDR                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONID                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_OPTIONINDEX                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONDATA                                                                            STD_OFF  /**< Deactivateable: 'Sd_PartitionData' Reason: 'No Multi-Partition environment.' */
#define SD_OSAPPLICATIONIDOFPARTITIONDATA                                                           STD_OFF  /**< Deactivateable: 'Sd_PartitionData.OsApplicationId' Reason: 'No Multi-Partition environment.' */
#define SD_PARTITIONDATADYN                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALIZEDOFPARTITIONDATADYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NROFOPTIONSOFPARTITIONDATADYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXINDICATIONCOUNTOFPARTITIONDATADYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMEMSSINCESTARTOFPARTITIONDATADYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERTRANSMITDYNENDIDXOFPARTITIONDATADYN                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERTRANSMITDYNSTARTIDXOFPARTITIONDATADYN                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERTRANSMITFULLOFPARTITIONDATADYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TXPATHLOCKEDOFPARTITIONDATADYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONIDENTIFIERS                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PAYLOAD                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PORTSET                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTCNT                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPDYN                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATUSOFROUTINGGROUPDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPIDMAP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFROUTINGGROUPIDMAP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDXOFROUTINGGROUPIDMAP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERPARTITIONIDXOFROUTINGGROUPIDMAP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERUSEDOFROUTINGGROUPIDMAP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENT                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTIDXOFRXEVENT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERIDXOFRXEVENT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTOFRXEVENT                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXPDUIDMAP                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFRXPDUIDMAP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEIDXOFRXPDUIDMAP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFRXPDUIDMAP                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEUSEDOFRXPDUIDMAP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRY                                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTIDXOFSENDENTRY                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTIDXOFSENDENTRY                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPIDXOFSENDENTRY                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENTRYTYPEOFSENDENTRY                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERIDOFSENDENTRY                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERIDXOFSENDENTRY                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDOFSENDENTRY                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDXOFSENDENTRY                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MAJORVERSIONOFSENDENTRY                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RESERVEDFIELDOFSENDENTRY                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYNEXTIDXOFSENDENTRY                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYPREVIDXOFSENDENTRY                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDXOFSENDENTRY                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEIDOFSENDENTRY                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVER                                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4SINDENDIDXOFSERVER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4SINDSTARTIDXOFSERVER                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4SINDUSEDOFSERVER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6SINDENDIDXOFSERVER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6SINDSTARTIDXOFSERVER                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6SINDUSEDOFSERVER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_AUTOAVAILABLEOFSERVER                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDENDIDXOFSERVER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFSERVER                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDSTARTIDXOFSERVER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDUSEDOFSERVER                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAYIDXOFSERVER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAYUSEDOFSERVER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERENDIDXOFSERVER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERSTARTIDXOFSERVER                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUSEDOFSERVER                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_HANDLEIDOFSERVER                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALINSTANCEIDOFSERVER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDXOFSERVER                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MAJORVERSIONOFSERVER                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODIDXOFSERVER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_METHODUSEDOFSERVER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MINORVERSIONOFSERVER                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERTIMERIDXOFSERVER                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBEROFSERVER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEIDOFSERVER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNTCPIDXOFSERVER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNTCPUSEDOFSERVER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNUDPIDXOFSERVER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNUDPUSEDOFSERVER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDENDIDXOFSERVER                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDSTARTIDXOFSERVER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDUSEDOFSERVER                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONENDIDXOFSERVER                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONSTARTIDXOFSERVER                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONUSEDOFSERVER                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERDYN                                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALOFFERREPETITIONRUNOFSERVERDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEIDOFSERVERDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPREQCOUNTEROFSERVERDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEEXECUTIONREQUESTEDOFSERVERDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATEMACHINEOFSERVERDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_STATESWCOFSERVERDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TIMETOTRIGGERSENDOFSERVERDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDMAP                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFSERVERIDMAP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVERIDXOFSERVERIDMAP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVERPARTITIONIDXOFSERVERIDMAP                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVERUSEDOFSERVERIDMAP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERTIMER                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALOFFERDELAYMAXOFSERVERTIMER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALOFFERDELAYMINOFSERVERTIMER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALOFFERREPETITIONBASEDELAYOFSERVERTIMER                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INITIALOFFERREPETITIONSMAXOFSERVERTIMER                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_OFFERCYCLICDELAYOFSERVERTIMER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTRESPONSEMAXDELAYOFSERVERTIMER                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTRESPONSEMINDELAYOFSERVERTIMER                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TTLOFSERVERTIMER                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBERENDIDXOFSERVICEGROUP                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBERSTARTIDXOFSERVICEGROUP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPIDMAP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFSERVICEGROUPIDMAP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVICEGROUPIDXOFSERVICEGROUPIDMAP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVICEGROUPPARTITIONIDXOFSERVICEGROUPIDMAP                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSERVICEGROUPUSEDOFSERVICEGROUPIDMAP                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTIDXOFSERVICEGROUPMEMBER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTUSEDOFSERVICEGROUPMEMBER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDXOFSERVICEGROUPMEMBER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERUSEDOFSERVICEGROUPMEMBER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4CIND                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4SIND                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6CIND                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6SIND                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFADDRESSSTORAGE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCAPABILITYRECORD                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCAPABILITYRECORDFUNCTIONCALLOUTPTR                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENT                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTDYN                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTIDMAP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTLIST                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTTIMER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCOMMONINITIALDELAY                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUPDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUPIDMAP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFENDPOINTSTORAGE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERMULTICAST                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERTCP                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERUDP                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFINSTANCE                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFINSTANCEDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFIPADDRREQUEST                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMETHOD                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMULTICASTENDPOINTADDR                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMULTICASTSOCONID                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFOPTIONINDEX                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPARTITIONDATA                                                                      STD_OFF  /**< Deactivateable: 'Sd_SizeOfPartitionData' Reason: 'Deactivateable: 'PartitionData' Reason: 'Deactivateable: 'Sd_PartitionData' Reason: 'No Multi-Partition environment.''' */
#define SD_SIZEOFPARTITIONDATADYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPARTITIONIDENTIFIERS                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPAYLOAD                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPORTSET                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFREQUESTCNT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUPDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUPIDMAP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFRXEVENT                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFRXPDUIDMAP                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSENDENTRY                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERDYN                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERIDMAP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERTIMER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUPIDMAP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUPMEMBER                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONACTIVATIONMAP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONGRPDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONMODEDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONMODEIDMAP                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTCPSOCONID                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTRIGGERTRANSMITDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTXSOCONIDMAP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFUDPSOCON                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONACTIVATIONMAP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_NROFACTIVATIONSOFSOCONACTIVATIONMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONIDOFSOCONACTIVATIONMAP                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYN                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_LOCALPORTOFSOCONGRPDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONMODEDYN                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONMODEIDMAP                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFSOCONMODEIDMAP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICSOCONMODEUSEDOFSOCONMODEIDMAP                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONID                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERTRANSMITDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTIDXOFTRIGGERTRANSMITDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERIDXOFTRIGGERTRANSMITDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TXSOCONIDMAP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INVALIDHNDOFTXSOCONIDMAP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEIDXOFTXSOCONIDMAP                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFTXSOCONIDMAP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONSPECIFICINSTANCEUSEDOFTXSOCONIDMAP                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCON                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_IDOFUDPSOCON                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PRECONFIGUREDOFUDPSOCON                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PCCONFIG                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_FINALMAGICNUMBEROFPCCONFIG                                                               STD_OFF  /**< Deactivateable: 'Sd_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SD_INITDATAHASHCODEOFPCCONFIG                                                               STD_OFF  /**< Deactivateable: 'Sd_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SD_PCPARTITIONCONFIGOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONIDENTIFIERSOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PCPARTITIONCONFIG                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4CINDOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4OFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV4SINDOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6CINDOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6OFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ACLIPV6SINDOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ADDRESSSTORAGEOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CAPABILITYRECORDOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTDYNOFPCPARTITIONCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTIDMAPOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTLISTOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTOFPCPARTITIONCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CLIENTTIMEROFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_COMMONINITIALDELAYOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPDYNOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_CONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ENDPOINTSTORAGEOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERDYNOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERTCPOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_EVENTHANDLERUDPOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEDYNOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_INSTANCEOFPCPARTITIONCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_IPADDRREQUESTOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MAXNROPTIONSPERENTRYOFPCPARTITIONCONFIG                                                  STD_ON
#define SD_METHODOFPCPARTITIONCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_MULTICASTSOCONIDOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_OPTIONINDEXOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PARTITIONDATADYNOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PAYLOADOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_PORTSETOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_REQUESTCNTOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPDYNOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_ROUTINGGROUPOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXEVENTOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_RXPDUIDMAPOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SENDENTRYOFPCPARTITIONCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERDYNOFPCPARTITIONCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERIDMAPOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVEROFPCPARTITIONCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVERTIMEROFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SERVICEGROUPOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4CINDOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4OFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV4SINDOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6CINDOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6OFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFACLIPV6SINDOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFADDRESSSTORAGEOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCAPABILITYRECORDOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTDYNOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTIDMAPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTLISTOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCLIENTTIMEROFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCOMMONINITIALDELAYOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUPDYNOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFCONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFENDPOINTSTORAGEOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERDYNOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERTCPOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFEVENTHANDLERUDPOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFINSTANCEDYNOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFIPADDRREQUESTOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMETHODOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFMULTICASTSOCONIDOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFOPTIONINDEXOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPARTITIONDATADYNOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPARTITIONDATAOFPCPARTITIONCONFIG                                                   STD_OFF  /**< Deactivateable: 'Sd_PCPartitionConfig.SizeOfPartitionData' Reason: 'Deactivateable: 'PartitionData' Reason: 'Deactivateable: 'Sd_PartitionData' Reason: 'No Multi-Partition environment.''' */
#define SD_SIZEOFPAYLOADOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFPORTSETOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFREQUESTCNTOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUPDYNOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFROUTINGGROUPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFRXEVENTOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFRXPDUIDMAPOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSENDENTRYOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERDYNOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERIDMAPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVERTIMEROFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSERVICEGROUPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONGRPDYNOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONMODEDYNOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFSOCONMODEIDMAPOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTCPSOCONIDOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFTXSOCONIDMAPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SIZEOFUDPSOCONOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONGRPDYNOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONMODEDYNOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_SOCONMODEIDMAPOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TCPSOCONIDOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_TXSOCONIDMAPOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SD_UDPSOCONOFPCPARTITIONCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  SdPCMinNumericValueDefines  Sd Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SD_MIN_FLAGSOFADDRESSSTORAGE                                                                0u
#define SD_MIN_RXMULTICASTFLAGSOFADDRESSSTORAGE                                                     0u
#define SD_MIN_RXMULTICASTSESSIONIDOFADDRESSSTORAGE                                                 0u
#define SD_MIN_RXUNICASTFLAGSOFADDRESSSTORAGE                                                       0u
#define SD_MIN_RXUNICASTSESSIONIDOFADDRESSSTORAGE                                                   0u
#define SD_MIN_SENDENTRYHEADIDXOFADDRESSSTORAGE                                                     0u
#define SD_MIN_SENDENTRYNRPENDINGIDXOFADDRESSSTORAGE                                                0u
#define SD_MIN_SENDENTRYTAILIDXOFADDRESSSTORAGE                                                     0u
#define SD_MIN_SESSIONIDCOUNTEROFADDRESSSTORAGE                                                     0u
#define SD_MIN_ADDRESSSTORAGECURRENTSERVERIDXOFCLIENTDYN                                            0u
#define SD_MIN_ADDRESSSTORAGESERVERIDXOFCLIENTDYN                                                   0u
#define SD_MIN_INSTANCEIDOFCLIENTDYN                                                                0u
#define SD_MIN_OFFEREDTTLOFCLIENTDYN                                                                0u
#define SD_MIN_REPETITIONRUNOFCLIENTDYN                                                             0u
#define SD_MIN_RETRYCOUNTEROFCLIENTDYN                                                              0u
#define SD_MIN_SERVICEGROUPREQCOUNTEROFCLIENTDYN                                                    0u
#define SD_MIN_ADDRESSSTORAGEIDXOFCLIENTLIST                                                        0u
#define SD_MIN_ENDPOINTSTORAGETCPIDXOFCLIENTLIST                                                    0u
#define SD_MIN_ENDPOINTSTORAGEUDPIDXOFCLIENTLIST                                                    0u
#define SD_MIN_NROFREFERENCESOFCLIENTLIST                                                           0u
#define SD_MIN_REQUESTEDTTLOFCLIENTLIST                                                             0u
#define SD_MIN_RXRESERVEDOFCLIENTLIST                                                               0u
#define SD_MIN_COMMONINITIALDELAY                                                                   0u
#define SD_MIN_ACKNOWLEDGEDTTLOFCONSUMEDEVENTGROUPDYN                                               0u
#define SD_MIN_RXINDICATIONCOUNTOFCONSUMEDEVENTGROUPDYN                                             0u
#define SD_MIN_NROFREFERENCESOFENDPOINTSTORAGE                                                      0u
#define SD_MIN_NROFCLIENTSOFEVENTHANDLERDYN                                                         0u
#define SD_MIN_RXEVENTENDIDXOFINSTANCEDYN                                                           0u
#define SD_MIN_RXEVENTSTARTIDXOFINSTANCEDYN                                                         0u
#define SD_MIN_SENDENTRYFREELISTHEADIDXOFINSTANCEDYN                                                0u
#define SD_MIN_SENDENTRYFREELISTTAILIDXOFINSTANCEDYN                                                0u
#define SD_MIN_SENDENTRYNRPENDINGIDXOFINSTANCEDYN                                                   0u
#define SD_MIN_OPTIONINDEX                                                                          0u
#define SD_MIN_NROFOPTIONSOFPARTITIONDATADYN                                                        0u
#define SD_MIN_RXINDICATIONCOUNTOFPARTITIONDATADYN                                                  0u
#define SD_MIN_TRIGGERTRANSMITDYNENDIDXOFPARTITIONDATADYN                                           0u
#define SD_MIN_TRIGGERTRANSMITDYNSTARTIDXOFPARTITIONDATADYN                                         0u
#define SD_MIN_PAYLOAD                                                                              0u
#define SD_MIN_REQUESTCNT                                                                           0u
#define SD_MIN_CLIENTLISTIDXOFRXEVENT                                                               0u
#define SD_MIN_EVENTHANDLERIDXOFRXEVENT                                                             0u
#define SD_MIN_CLIENTIDXOFSENDENTRY                                                                 0u
#define SD_MIN_CLIENTLISTIDXOFSENDENTRY                                                             0u
#define SD_MIN_CONSUMEDEVENTGROUPIDXOFSENDENTRY                                                     0u
#define SD_MIN_EVENTHANDLERIDOFSENDENTRY                                                            0u
#define SD_MIN_EVENTHANDLERIDXOFSENDENTRY                                                           0u
#define SD_MIN_INSTANCEIDOFSENDENTRY                                                                0u
#define SD_MIN_INSTANCEIDXOFSENDENTRY                                                               0u
#define SD_MIN_MAJORVERSIONOFSENDENTRY                                                              0u
#define SD_MIN_RESERVEDFIELDOFSENDENTRY                                                             0u
#define SD_MIN_SENDENTRYNEXTIDXOFSENDENTRY                                                          0u
#define SD_MIN_SENDENTRYPREVIDXOFSENDENTRY                                                          0u
#define SD_MIN_SERVERIDXOFSENDENTRY                                                                 0u
#define SD_MIN_SERVICEIDOFSENDENTRY                                                                 0u
#define SD_MIN_INITIALOFFERREPETITIONRUNOFSERVERDYN                                                 0u
#define SD_MIN_INSTANCEIDOFSERVERDYN                                                                0u
#define SD_MIN_SERVICEGROUPREQCOUNTEROFSERVERDYN                                                    0u
#define SD_MIN_NROFACTIVATIONSOFSOCONACTIVATIONMAP                                                  0u
#define SD_MIN_LOCALPORTOFSOCONGRPDYN                                                               0u
#define SD_MIN_CLIENTLISTIDXOFTRIGGERTRANSMITDYN                                                    0u
#define SD_MIN_EVENTHANDLERIDXOFTRIGGERTRANSMITDYN                                                  0u
/** 
  \}
*/ 

/** 
  \defgroup  SdPCMaxNumericValueDefines  Sd Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SD_MAX_FLAGSOFADDRESSSTORAGE                                                                255u
#define SD_MAX_RXMULTICASTFLAGSOFADDRESSSTORAGE                                                     255u
#define SD_MAX_RXMULTICASTSESSIONIDOFADDRESSSTORAGE                                                 65535u
#define SD_MAX_RXUNICASTFLAGSOFADDRESSSTORAGE                                                       255u
#define SD_MAX_RXUNICASTSESSIONIDOFADDRESSSTORAGE                                                   65535u
#define SD_MAX_SENDENTRYHEADIDXOFADDRESSSTORAGE                                                     255u
#define SD_MAX_SENDENTRYNRPENDINGIDXOFADDRESSSTORAGE                                                255u
#define SD_MAX_SENDENTRYTAILIDXOFADDRESSSTORAGE                                                     255u
#define SD_MAX_SESSIONIDCOUNTEROFADDRESSSTORAGE                                                     65535u
#define SD_MAX_ADDRESSSTORAGECURRENTSERVERIDXOFCLIENTDYN                                            255u
#define SD_MAX_ADDRESSSTORAGESERVERIDXOFCLIENTDYN                                                   255u
#define SD_MAX_INSTANCEIDOFCLIENTDYN                                                                65535u
#define SD_MAX_OFFEREDTTLOFCLIENTDYN                                                                4294967295u
#define SD_MAX_REPETITIONRUNOFCLIENTDYN                                                             255u
#define SD_MAX_RETRYCOUNTEROFCLIENTDYN                                                              255u
#define SD_MAX_SERVICEGROUPREQCOUNTEROFCLIENTDYN                                                    255u
#define SD_MAX_ADDRESSSTORAGEIDXOFCLIENTLIST                                                        255u
#define SD_MAX_ENDPOINTSTORAGETCPIDXOFCLIENTLIST                                                    255u
#define SD_MAX_ENDPOINTSTORAGEUDPIDXOFCLIENTLIST                                                    255u
#define SD_MAX_NROFREFERENCESOFCLIENTLIST                                                           255u
#define SD_MAX_REQUESTEDTTLOFCLIENTLIST                                                             4294967295u
#define SD_MAX_RXRESERVEDOFCLIENTLIST                                                               65535u
#define SD_MAX_COMMONINITIALDELAY                                                                   4294967295u
#define SD_MAX_ACKNOWLEDGEDTTLOFCONSUMEDEVENTGROUPDYN                                               4294967295u
#define SD_MAX_RXINDICATIONCOUNTOFCONSUMEDEVENTGROUPDYN                                             255u
#define SD_MAX_NROFREFERENCESOFENDPOINTSTORAGE                                                      255u
#define SD_MAX_NROFCLIENTSOFEVENTHANDLERDYN                                                         65535u
#define SD_MAX_RXEVENTENDIDXOFINSTANCEDYN                                                           255u
#define SD_MAX_RXEVENTSTARTIDXOFINSTANCEDYN                                                         255u
#define SD_MAX_SENDENTRYFREELISTHEADIDXOFINSTANCEDYN                                                255u
#define SD_MAX_SENDENTRYFREELISTTAILIDXOFINSTANCEDYN                                                255u
#define SD_MAX_SENDENTRYNRPENDINGIDXOFINSTANCEDYN                                                   255u
#define SD_MAX_OPTIONINDEX                                                                          65535u
#define SD_MAX_NROFOPTIONSOFPARTITIONDATADYN                                                        65535u
#define SD_MAX_RXINDICATIONCOUNTOFPARTITIONDATADYN                                                  255u
#define SD_MAX_TRIGGERTRANSMITDYNENDIDXOFPARTITIONDATADYN                                           255u
#define SD_MAX_TRIGGERTRANSMITDYNSTARTIDXOFPARTITIONDATADYN                                         255u
#define SD_MAX_PAYLOAD                                                                              255u
#define SD_MAX_REQUESTCNT                                                                           65535u
#define SD_MAX_CLIENTLISTIDXOFRXEVENT                                                               255u
#define SD_MAX_EVENTHANDLERIDXOFRXEVENT                                                             255u
#define SD_MAX_CLIENTIDXOFSENDENTRY                                                                 255u
#define SD_MAX_CLIENTLISTIDXOFSENDENTRY                                                             255u
#define SD_MAX_CONSUMEDEVENTGROUPIDXOFSENDENTRY                                                     255u
#define SD_MAX_EVENTHANDLERIDOFSENDENTRY                                                            65535u
#define SD_MAX_EVENTHANDLERIDXOFSENDENTRY                                                           255u
#define SD_MAX_INSTANCEIDOFSENDENTRY                                                                65535u
#define SD_MAX_INSTANCEIDXOFSENDENTRY                                                               255u
#define SD_MAX_MAJORVERSIONOFSENDENTRY                                                              255u
#define SD_MAX_RESERVEDFIELDOFSENDENTRY                                                             65535u
#define SD_MAX_SENDENTRYNEXTIDXOFSENDENTRY                                                          255u
#define SD_MAX_SENDENTRYPREVIDXOFSENDENTRY                                                          255u
#define SD_MAX_SERVERIDXOFSENDENTRY                                                                 255u
#define SD_MAX_SERVICEIDOFSENDENTRY                                                                 65535u
#define SD_MAX_INITIALOFFERREPETITIONRUNOFSERVERDYN                                                 255u
#define SD_MAX_INSTANCEIDOFSERVERDYN                                                                65535u
#define SD_MAX_SERVICEGROUPREQCOUNTEROFSERVERDYN                                                    255u
#define SD_MAX_NROFACTIVATIONSOFSOCONACTIVATIONMAP                                                  255u
#define SD_MAX_LOCALPORTOFSOCONGRPDYN                                                               65535u
#define SD_MAX_CLIENTLISTIDXOFTRIGGERTRANSMITDYN                                                    255u
#define SD_MAX_EVENTHANDLERIDXOFTRIGGERTRANSMITDYN                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  SdPCNoReferenceDefines  Sd No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define SD_NO_SENDENTRYHEADIDXOFADDRESSSTORAGE                                                      255u
#define SD_NO_SENDENTRYNRPENDINGIDXOFADDRESSSTORAGE                                                 255u
#define SD_NO_SENDENTRYTAILIDXOFADDRESSSTORAGE                                                      255u
#define SD_NO_ACLIPV4CINDENDIDXOFCLIENT                                                             255u
#define SD_NO_ACLIPV4CINDSTARTIDXOFCLIENT                                                           255u
#define SD_NO_ACLIPV6CINDENDIDXOFCLIENT                                                             255u
#define SD_NO_ACLIPV6CINDSTARTIDXOFCLIENT                                                           255u
#define SD_NO_CAPABILITYRECORDENDIDXOFCLIENT                                                        255u
#define SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT                                         255u
#define SD_NO_CAPABILITYRECORDSTARTIDXOFCLIENT                                                      255u
#define SD_NO_COMMONINITIALDELAYIDXOFCLIENT                                                         255u
#define SD_NO_CONSUMEDEVENTGROUPENDIDXOFCLIENT                                                      255u
#define SD_NO_CONSUMEDEVENTGROUPSTARTIDXOFCLIENT                                                    255u
#define SD_NO_METHODIDXOFCLIENT                                                                     255u
#define SD_NO_SOCONGRPDYNTCPIDXOFCLIENT                                                             255u
#define SD_NO_SOCONGRPDYNUDPIDXOFCLIENT                                                             255u
#define SD_NO_TCPSOCONIDENDIDXOFCLIENT                                                              255u
#define SD_NO_TCPSOCONIDSTARTIDXOFCLIENT                                                            255u
#define SD_NO_UDPSOCONENDIDXOFCLIENT                                                                255u
#define SD_NO_UDPSOCONSTARTIDXOFCLIENT                                                              255u
#define SD_NO_ADDRESSSTORAGECURRENTSERVERIDXOFCLIENTDYN                                             255u
#define SD_NO_ADDRESSSTORAGESERVERIDXOFCLIENTDYN                                                    255u
#define SD_NO_PARTITIONSPECIFICCLIENTIDXOFCLIENTIDMAP                                               255u
#define SD_NO_PARTITIONSPECIFICCLIENTPARTITIONIDXOFCLIENTIDMAP                                      255u
#define SD_NO_ADDRESSSTORAGEIDXOFCLIENTLIST                                                         255u
#define SD_NO_ENDPOINTSTORAGETCPIDXOFCLIENTLIST                                                     255u
#define SD_NO_ENDPOINTSTORAGEUDPIDXOFCLIENTLIST                                                     255u
#define SD_NO_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP                                          255u
#define SD_NO_MULTICASTSOCONIDENDIDXOFCONSUMEDEVENTGROUP                                            255u
#define SD_NO_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP                                          255u
#define SD_NO_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP                                    255u
#define SD_NO_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP                                          255u
#define SD_NO_ROUTINGGROUPUDPACTREFIDXOFCONSUMEDEVENTGROUP                                          255u
#define SD_NO_PARTITIONSPECIFICCONSUMEDEVENTGROUPIDXOFCONSUMEDEVENTGROUPIDMAP                       255u
#define SD_NO_PARTITIONSPECIFICCONSUMEDEVENTGROUPPARTITIONIDXOFCONSUMEDEVENTGROUPIDMAP              255u
#define SD_NO_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER                                                255u
#define SD_NO_EVENTHANDLERTCPIDXOFEVENTHANDLER                                                      255u
#define SD_NO_EVENTHANDLERUDPIDXOFEVENTHANDLER                                                      255u
#define SD_NO_SOCONACTIVATIONMAPENDIDXOFEVENTHANDLER                                                255u
#define SD_NO_SOCONACTIVATIONMAPSTARTIDXOFEVENTHANDLER                                              255u
#define SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERMULTICAST                                          255u
#define SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERTCP                                                255u
#define SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERTCP                                               255u
#define SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERUDP                                                255u
#define SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP                                               255u
#define SD_NO_CAPABILITYRECORDENDIDXOFINSTANCE                                                      255u
#define SD_NO_CAPABILITYRECORDSTARTIDXOFINSTANCE                                                    255u
#define SD_NO_CLIENTENDIDXOFINSTANCE                                                                255u
#define SD_NO_CLIENTSTARTIDXOFINSTANCE                                                              255u
#define SD_NO_EVENTHANDLERENDIDXOFINSTANCE                                                          255u
#define SD_NO_EVENTHANDLERSTARTIDXOFINSTANCE                                                        255u
#define SD_NO_RXEVENTENDIDXOFINSTANCE                                                               255u
#define SD_NO_RXEVENTSTARTIDXOFINSTANCE                                                             255u
#define SD_NO_SERVERENDIDXOFINSTANCE                                                                255u
#define SD_NO_SERVERSTARTIDXOFINSTANCE                                                              255u
#define SD_NO_TCPSOCONIDENDIDXOFINSTANCE                                                            255u
#define SD_NO_TCPSOCONIDSTARTIDXOFINSTANCE                                                          255u
#define SD_NO_UDPSOCONENDIDXOFINSTANCE                                                              255u
#define SD_NO_UDPSOCONSTARTIDXOFINSTANCE                                                            255u
#define SD_NO_ROUTINGGROUPACTREFIDXOFMETHOD                                                         255u
#define SD_NO_SERVERIDXOFROUTINGGROUPIDMAP                                                          255u
#define SD_NO_SERVERPARTITIONIDXOFROUTINGGROUPIDMAP                                                 255u
#define SD_NO_CLIENTLISTIDXOFRXEVENT                                                                255u
#define SD_NO_EVENTHANDLERIDXOFRXEVENT                                                              255u
#define SD_NO_PARTITIONSPECIFICINSTANCEIDXOFRXPDUIDMAP                                              255u
#define SD_NO_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFRXPDUIDMAP                                     255u
#define SD_NO_CLIENTIDXOFSENDENTRY                                                                  255u
#define SD_NO_CLIENTLISTIDXOFSENDENTRY                                                              255u
#define SD_NO_CONSUMEDEVENTGROUPIDXOFSENDENTRY                                                      255u
#define SD_NO_EVENTHANDLERIDXOFSENDENTRY                                                            255u
#define SD_NO_INSTANCEIDXOFSENDENTRY                                                                255u
#define SD_NO_SENDENTRYNEXTIDXOFSENDENTRY                                                           255u
#define SD_NO_SENDENTRYPREVIDXOFSENDENTRY                                                           255u
#define SD_NO_SERVERIDXOFSENDENTRY                                                                  255u
#define SD_NO_ACLIPV4SINDENDIDXOFSERVER                                                             255u
#define SD_NO_ACLIPV4SINDSTARTIDXOFSERVER                                                           255u
#define SD_NO_ACLIPV6SINDENDIDXOFSERVER                                                             255u
#define SD_NO_ACLIPV6SINDSTARTIDXOFSERVER                                                           255u
#define SD_NO_CAPABILITYRECORDENDIDXOFSERVER                                                        255u
#define SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER                                         255u
#define SD_NO_CAPABILITYRECORDSTARTIDXOFSERVER                                                      255u
#define SD_NO_COMMONINITIALDELAYIDXOFSERVER                                                         255u
#define SD_NO_EVENTHANDLERENDIDXOFSERVER                                                            255u
#define SD_NO_EVENTHANDLERSTARTIDXOFSERVER                                                          255u
#define SD_NO_METHODIDXOFSERVER                                                                     255u
#define SD_NO_SOCONGRPDYNTCPIDXOFSERVER                                                             255u
#define SD_NO_SOCONGRPDYNUDPIDXOFSERVER                                                             255u
#define SD_NO_TCPSOCONIDENDIDXOFSERVER                                                              255u
#define SD_NO_TCPSOCONIDSTARTIDXOFSERVER                                                            255u
#define SD_NO_UDPSOCONENDIDXOFSERVER                                                                255u
#define SD_NO_UDPSOCONSTARTIDXOFSERVER                                                              255u
#define SD_NO_PARTITIONSPECIFICSERVERIDXOFSERVERIDMAP                                               255u
#define SD_NO_PARTITIONSPECIFICSERVERPARTITIONIDXOFSERVERIDMAP                                      255u
#define SD_NO_PARTITIONSPECIFICSERVICEGROUPIDXOFSERVICEGROUPIDMAP                                   255u
#define SD_NO_PARTITIONSPECIFICSERVICEGROUPPARTITIONIDXOFSERVICEGROUPIDMAP                          255u
#define SD_NO_CLIENTIDXOFSERVICEGROUPMEMBER                                                         255u
#define SD_NO_SERVERIDXOFSERVICEGROUPMEMBER                                                         255u
#define SD_NO_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP                                         255u
#define SD_NO_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                                255u
#define SD_NO_CLIENTLISTIDXOFTRIGGERTRANSMITDYN                                                     255u
#define SD_NO_EVENTHANDLERIDXOFTRIGGERTRANSMITDYN                                                   255u
#define SD_NO_PARTITIONSPECIFICINSTANCEIDXOFTXSOCONIDMAP                                            255u
#define SD_NO_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFTXSOCONIDMAP                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  SdPCIsReducedToDefineDefines  Sd Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SD_ISDEF_ADDROFACLIPV4                                                                      STD_OFF
#define SD_ISDEF_ACLIPV4CIND                                                                        STD_OFF
#define SD_ISDEF_ACLIPV4SIND                                                                        STD_OFF
#define SD_ISDEF_ADDROFACLIPV6                                                                      STD_OFF
#define SD_ISDEF_ACLIPV6CIND                                                                        STD_OFF
#define SD_ISDEF_ACLIPV6SIND                                                                        STD_OFF
#define SD_ISDEF_CAPABILITYRECORD                                                                   STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTR                                                 STD_OFF
#define SD_ISDEF_ACLIPV4CINDENDIDXOFCLIENT                                                          STD_OFF
#define SD_ISDEF_ACLIPV4CINDSTARTIDXOFCLIENT                                                        STD_OFF
#define SD_ISDEF_ACLIPV4CINDUSEDOFCLIENT                                                            STD_OFF
#define SD_ISDEF_ACLIPV6CINDENDIDXOFCLIENT                                                          STD_OFF
#define SD_ISDEF_ACLIPV6CINDSTARTIDXOFCLIENT                                                        STD_OFF
#define SD_ISDEF_ACLIPV6CINDUSEDOFCLIENT                                                            STD_OFF
#define SD_ISDEF_AUTOREQUIREOFCLIENT                                                                STD_OFF
#define SD_ISDEF_CAPABILITYRECORDENDIDXOFCLIENT                                                     STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT                                      STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFCLIENT                                     STD_OFF
#define SD_ISDEF_CAPABILITYRECORDSTARTIDXOFCLIENT                                                   STD_OFF
#define SD_ISDEF_CAPABILITYRECORDUSEDOFCLIENT                                                       STD_OFF
#define SD_ISDEF_CLIENTTIMERIDXOFCLIENT                                                             STD_OFF
#define SD_ISDEF_COMMONINITIALDELAYIDXOFCLIENT                                                      STD_OFF
#define SD_ISDEF_COMMONINITIALDELAYUSEDOFCLIENT                                                     STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPENDIDXOFCLIENT                                                   STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPSTARTIDXOFCLIENT                                                 STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPUSEDOFCLIENT                                                     STD_OFF
#define SD_ISDEF_FINDBEHAVIOROFCLIENT                                                               STD_OFF
#define SD_ISDEF_HANDLEIDOFCLIENT                                                                   STD_OFF
#define SD_ISDEF_INITIALINSTANCEIDOFCLIENT                                                          STD_OFF
#define SD_ISDEF_INSTANCEIDXOFCLIENT                                                                STD_OFF
#define SD_ISDEF_MAJORVERSIONOFCLIENT                                                               STD_OFF
#define SD_ISDEF_METHODIDXOFCLIENT                                                                  STD_OFF
#define SD_ISDEF_METHODUSEDOFCLIENT                                                                 STD_OFF
#define SD_ISDEF_MINORVERSIONOFCLIENT                                                               STD_OFF
#define SD_ISDEF_MINORVERSIONWILDCARDOFCLIENT                                                       STD_OFF
#define SD_ISDEF_SERVICEGROUPMEMBEROFCLIENT                                                         STD_OFF
#define SD_ISDEF_SERVICEIDOFCLIENT                                                                  STD_OFF
#define SD_ISDEF_SOCONGRPDYNTCPIDXOFCLIENT                                                          STD_OFF
#define SD_ISDEF_SOCONGRPDYNTCPUSEDOFCLIENT                                                         STD_OFF
#define SD_ISDEF_SOCONGRPDYNUDPIDXOFCLIENT                                                          STD_OFF
#define SD_ISDEF_SOCONGRPDYNUDPUSEDOFCLIENT                                                         STD_OFF
#define SD_ISDEF_TCPSOCONIDENDIDXOFCLIENT                                                           STD_OFF
#define SD_ISDEF_TCPSOCONIDSTARTIDXOFCLIENT                                                         STD_OFF
#define SD_ISDEF_TCPSOCONIDUSEDOFCLIENT                                                             STD_OFF
#define SD_ISDEF_UDPCLIENTMULTICASTOFCLIENT                                                         STD_OFF
#define SD_ISDEF_UDPSOCONENDIDXOFCLIENT                                                             STD_OFF
#define SD_ISDEF_UDPSOCONSTARTIDXOFCLIENT                                                           STD_OFF
#define SD_ISDEF_UDPSOCONUSEDOFCLIENT                                                               STD_OFF
#define SD_ISDEF_INVALIDHNDOFCLIENTIDMAP                                                            STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCLIENTIDXOFCLIENTIDMAP                                            STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCLIENTPARTITIONIDXOFCLIENTIDMAP                                   STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCLIENTUSEDOFCLIENTIDMAP                                           STD_OFF
#define SD_ISDEF_INITIALFINDDELAYMAXOFCLIENTTIMER                                                   STD_OFF
#define SD_ISDEF_INITIALFINDDELAYMINOFCLIENTTIMER                                                   STD_OFF
#define SD_ISDEF_INITIALFINDREPETITIONBASEDELAYOFCLIENTTIMER                                        STD_OFF
#define SD_ISDEF_INITIALFINDREPETITIONSMAXOFCLIENTTIMER                                             STD_OFF
#define SD_ISDEF_REQUESTRESPONSEMAXDELAYOFCLIENTTIMER                                               STD_OFF
#define SD_ISDEF_REQUESTRESPONSEMINDELAYOFCLIENTTIMER                                               STD_OFF
#define SD_ISDEF_TTLOFCLIENTTIMER                                                                   STD_OFF
#define SD_ISDEF_AUTOREQUIREOFCONSUMEDEVENTGROUP                                                    STD_OFF
#define SD_ISDEF_CLIENTIDXOFCONSUMEDEVENTGROUP                                                      STD_OFF
#define SD_ISDEF_CLIENTTIMERIDXOFCONSUMEDEVENTGROUP                                                 STD_OFF
#define SD_ISDEF_EVENTGROUPIDOFCONSUMEDEVENTGROUP                                                   STD_OFF
#define SD_ISDEF_HANDLEIDOFCONSUMEDEVENTGROUP                                                       STD_OFF
#define SD_ISDEF_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP                                       STD_OFF
#define SD_ISDEF_MULTICASTENDPOINTADDRUSEDOFCONSUMEDEVENTGROUP                                      STD_OFF
#define SD_ISDEF_MULTICASTSOCONIDENDIDXOFCONSUMEDEVENTGROUP                                         STD_OFF
#define SD_ISDEF_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP                                       STD_OFF
#define SD_ISDEF_MULTICASTSOCONIDUSEDOFCONSUMEDEVENTGROUP                                           STD_OFF
#define SD_ISDEF_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP                                 STD_OFF
#define SD_ISDEF_ROUTINGGROUPMULTICASTACTREFUSEDOFCONSUMEDEVENTGROUP                                STD_OFF
#define SD_ISDEF_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP                                       STD_OFF
#define SD_ISDEF_ROUTINGGROUPTCPACTREFUSEDOFCONSUMEDEVENTGROUP                                      STD_OFF
#define SD_ISDEF_ROUTINGGROUPUDPACTREFIDXOFCONSUMEDEVENTGROUP                                       STD_OFF
#define SD_ISDEF_ROUTINGGROUPUDPACTREFUSEDOFCONSUMEDEVENTGROUP                                      STD_OFF
#define SD_ISDEF_INVALIDHNDOFCONSUMEDEVENTGROUPIDMAP                                                STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCONSUMEDEVENTGROUPIDXOFCONSUMEDEVENTGROUPIDMAP                    STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCONSUMEDEVENTGROUPPARTITIONIDXOFCONSUMEDEVENTGROUPIDMAP           STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICCONSUMEDEVENTGROUPUSEDOFCONSUMEDEVENTGROUPIDMAP                   STD_OFF
#define SD_ISDEF_CLIENTLISTENDIDXOFEVENTHANDLER                                                     STD_OFF
#define SD_ISDEF_CLIENTLISTSTARTIDXOFEVENTHANDLER                                                   STD_OFF
#define SD_ISDEF_EVENTGROUPIDOFEVENTHANDLER                                                         STD_OFF
#define SD_ISDEF_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER                                             STD_OFF
#define SD_ISDEF_EVENTHANDLERMULTICASTUSEDOFEVENTHANDLER                                            STD_OFF
#define SD_ISDEF_EVENTHANDLERTCPIDXOFEVENTHANDLER                                                   STD_OFF
#define SD_ISDEF_EVENTHANDLERTCPUSEDOFEVENTHANDLER                                                  STD_OFF
#define SD_ISDEF_EVENTHANDLERUDPIDXOFEVENTHANDLER                                                   STD_OFF
#define SD_ISDEF_EVENTHANDLERUDPUSEDOFEVENTHANDLER                                                  STD_OFF
#define SD_ISDEF_HANDLEIDOFEVENTHANDLER                                                             STD_OFF
#define SD_ISDEF_MULTICASTTHRESHOLDOFEVENTHANDLER                                                   STD_OFF
#define SD_ISDEF_SERVERIDXOFEVENTHANDLER                                                            STD_OFF
#define SD_ISDEF_SERVERTIMERIDXOFEVENTHANDLER                                                       STD_OFF
#define SD_ISDEF_SOCONACTIVATIONMAPENDIDXOFEVENTHANDLER                                             STD_OFF
#define SD_ISDEF_SOCONACTIVATIONMAPSTARTIDXOFEVENTHANDLER                                           STD_OFF
#define SD_ISDEF_SOCONACTIVATIONMAPUSEDOFEVENTHANDLER                                               STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFIDXOFEVENTHANDLERMULTICAST                                       STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERMULTICAST                                      STD_OFF
#define SD_ISDEF_SOCONIDOFEVENTHANDLERMULTICAST                                                     STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFIDXOFEVENTHANDLERTCP                                             STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERTCP                                            STD_OFF
#define SD_ISDEF_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERTCP                                            STD_OFF
#define SD_ISDEF_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERTCP                                           STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFIDXOFEVENTHANDLERUDP                                             STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERUDP                                            STD_OFF
#define SD_ISDEF_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP                                            STD_OFF
#define SD_ISDEF_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERUDP                                           STD_OFF
#define SD_ISDEF_ADDRESSSTORAGEENDIDXOFINSTANCE                                                     STD_OFF
#define SD_ISDEF_ADDRESSSTORAGESTARTIDXOFINSTANCE                                                   STD_OFF
#define SD_ISDEF_CAPABILITYRECORDENDIDXOFINSTANCE                                                   STD_OFF
#define SD_ISDEF_CAPABILITYRECORDSTARTIDXOFINSTANCE                                                 STD_OFF
#define SD_ISDEF_CAPABILITYRECORDUSEDOFINSTANCE                                                     STD_OFF
#define SD_ISDEF_CLIENTENDIDXOFINSTANCE                                                             STD_OFF
#define SD_ISDEF_CLIENTSTARTIDXOFINSTANCE                                                           STD_OFF
#define SD_ISDEF_CLIENTUSEDOFINSTANCE                                                               STD_OFF
#define SD_ISDEF_EMALFORMEDMSGIDOFINSTANCE                                                          STD_OFF
#define SD_ISDEF_ENACKRECVIDOFINSTANCE                                                              STD_OFF
#define SD_ISDEF_EOUTOFRESIDOFINSTANCE                                                              STD_OFF
#define SD_ISDEF_ENDPOINTSTORAGEENDIDXOFINSTANCE                                                    STD_OFF
#define SD_ISDEF_ENDPOINTSTORAGESTARTIDXOFINSTANCE                                                  STD_OFF
#define SD_ISDEF_EVENTHANDLERENDIDXOFINSTANCE                                                       STD_OFF
#define SD_ISDEF_EVENTHANDLERSTARTIDXOFINSTANCE                                                     STD_OFF
#define SD_ISDEF_EVENTHANDLERUSEDOFINSTANCE                                                         STD_OFF
#define SD_ISDEF_LOCALADDRESSCHECKLENGTHOFINSTANCE                                                  STD_OFF
#define SD_ISDEF_MULTICASTRXPDUIDOFINSTANCE                                                         STD_OFF
#define SD_ISDEF_MULTICASTRXSOCONIDOFINSTANCE                                                       STD_OFF
#define SD_ISDEF_QUEUEPROCESSLIMITOFINSTANCE                                                        STD_OFF
#define SD_ISDEF_RETRYDELAYOFINSTANCE                                                               STD_OFF
#define SD_ISDEF_RETRYMAXOFINSTANCE                                                                 STD_OFF
#define SD_ISDEF_RXEVENTENDIDXOFINSTANCE                                                            STD_OFF
#define SD_ISDEF_RXEVENTSTARTIDXOFINSTANCE                                                          STD_OFF
#define SD_ISDEF_RXEVENTUSEDOFINSTANCE                                                              STD_OFF
#define SD_ISDEF_SENDENTRYCAPACITYOFINSTANCE                                                        STD_OFF
#define SD_ISDEF_SENDENTRYENDIDXOFINSTANCE                                                          STD_OFF
#define SD_ISDEF_SENDENTRYSTARTIDXOFINSTANCE                                                        STD_OFF
#define SD_ISDEF_SERVERENDIDXOFINSTANCE                                                             STD_OFF
#define SD_ISDEF_SERVERSTARTIDXOFINSTANCE                                                           STD_OFF
#define SD_ISDEF_SERVERUSEDOFINSTANCE                                                               STD_OFF
#define SD_ISDEF_SEVDUPLICATEOFFEROFINSTANCE                                                        STD_OFF
#define SD_ISDEF_SEVFAILEDMETHODREQOFINSTANCE                                                       STD_OFF
#define SD_ISDEF_SEVFAILEDOFFEROFINSTANCE                                                           STD_OFF
#define SD_ISDEF_SEVFAILEDSUBOFINSTANCE                                                             STD_OFF
#define SD_ISDEF_TCPSOCONIDENDIDXOFINSTANCE                                                         STD_OFF
#define SD_ISDEF_TCPSOCONIDSTARTIDXOFINSTANCE                                                       STD_OFF
#define SD_ISDEF_TCPSOCONIDUSEDOFINSTANCE                                                           STD_OFF
#define SD_ISDEF_TXPDUIDOFINSTANCE                                                                  STD_OFF
#define SD_ISDEF_TXSOCONIDOFINSTANCE                                                                STD_OFF
#define SD_ISDEF_UDPSOCONENDIDXOFINSTANCE                                                           STD_OFF
#define SD_ISDEF_UDPSOCONSTARTIDXOFINSTANCE                                                         STD_OFF
#define SD_ISDEF_UDPSOCONUSEDOFINSTANCE                                                             STD_OFF
#define SD_ISDEF_UNICASTRXPDUIDOFINSTANCE                                                           STD_OFF
#define SD_ISDEF_UNICASTRXSOCONIDOFINSTANCE                                                         STD_OFF
#define SD_ISDEF_PORTSETIDXOFIPADDRREQUEST                                                          STD_OFF
#define SD_ISDEF_REQUESTCNTIDXOFIPADDRREQUEST                                                       STD_OFF
#define SD_ISDEF_SOCONIDOFIPADDRREQUEST                                                             STD_OFF
#define SD_ISDEF_STATICIPCONFIGURATIONOFIPADDRREQUEST                                               STD_OFF
#define SD_ISDEF_STATICPORTCONFIGURATIONOFIPADDRREQUEST                                             STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFIDXOFMETHOD                                                      STD_OFF
#define SD_ISDEF_ROUTINGGROUPACTREFUSEDOFMETHOD                                                     STD_OFF
#define SD_ISDEF_TCPCONFIGUREDOFMETHOD                                                              STD_OFF
#define SD_ISDEF_UDPCONFIGUREDOFMETHOD                                                              STD_OFF
#define SD_ISDEF_MULTICASTSOCONID                                                                   STD_OFF
#define SD_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         STD_OFF
#define SD_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 STD_OFF
#define SD_ISDEF_ROUTINGGROUP                                                                       STD_OFF
#define SD_ISDEF_INVALIDHNDOFROUTINGGROUPIDMAP                                                      STD_OFF
#define SD_ISDEF_SERVERIDXOFROUTINGGROUPIDMAP                                                       STD_OFF
#define SD_ISDEF_SERVERPARTITIONIDXOFROUTINGGROUPIDMAP                                              STD_OFF
#define SD_ISDEF_SERVERUSEDOFROUTINGGROUPIDMAP                                                      STD_OFF
#define SD_ISDEF_INVALIDHNDOFRXPDUIDMAP                                                             STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEIDXOFRXPDUIDMAP                                           STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFRXPDUIDMAP                                  STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEUSEDOFRXPDUIDMAP                                          STD_OFF
#define SD_ISDEF_ACLIPV4SINDENDIDXOFSERVER                                                          STD_OFF
#define SD_ISDEF_ACLIPV4SINDSTARTIDXOFSERVER                                                        STD_OFF
#define SD_ISDEF_ACLIPV4SINDUSEDOFSERVER                                                            STD_OFF
#define SD_ISDEF_ACLIPV6SINDENDIDXOFSERVER                                                          STD_OFF
#define SD_ISDEF_ACLIPV6SINDSTARTIDXOFSERVER                                                        STD_OFF
#define SD_ISDEF_ACLIPV6SINDUSEDOFSERVER                                                            STD_OFF
#define SD_ISDEF_AUTOAVAILABLEOFSERVER                                                              STD_OFF
#define SD_ISDEF_CAPABILITYRECORDENDIDXOFSERVER                                                     STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER                                      STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFSERVER                                     STD_OFF
#define SD_ISDEF_CAPABILITYRECORDSTARTIDXOFSERVER                                                   STD_OFF
#define SD_ISDEF_CAPABILITYRECORDUSEDOFSERVER                                                       STD_OFF
#define SD_ISDEF_COMMONINITIALDELAYIDXOFSERVER                                                      STD_OFF
#define SD_ISDEF_COMMONINITIALDELAYUSEDOFSERVER                                                     STD_OFF
#define SD_ISDEF_EVENTHANDLERENDIDXOFSERVER                                                         STD_OFF
#define SD_ISDEF_EVENTHANDLERSTARTIDXOFSERVER                                                       STD_OFF
#define SD_ISDEF_EVENTHANDLERUSEDOFSERVER                                                           STD_OFF
#define SD_ISDEF_HANDLEIDOFSERVER                                                                   STD_OFF
#define SD_ISDEF_INITIALINSTANCEIDOFSERVER                                                          STD_OFF
#define SD_ISDEF_INSTANCEIDXOFSERVER                                                                STD_OFF
#define SD_ISDEF_MAJORVERSIONOFSERVER                                                               STD_OFF
#define SD_ISDEF_METHODIDXOFSERVER                                                                  STD_OFF
#define SD_ISDEF_METHODUSEDOFSERVER                                                                 STD_OFF
#define SD_ISDEF_MINORVERSIONOFSERVER                                                               STD_OFF
#define SD_ISDEF_SERVERTIMERIDXOFSERVER                                                             STD_OFF
#define SD_ISDEF_SERVICEGROUPMEMBEROFSERVER                                                         STD_OFF
#define SD_ISDEF_SERVICEIDOFSERVER                                                                  STD_OFF
#define SD_ISDEF_SOCONGRPDYNTCPIDXOFSERVER                                                          STD_OFF
#define SD_ISDEF_SOCONGRPDYNTCPUSEDOFSERVER                                                         STD_OFF
#define SD_ISDEF_SOCONGRPDYNUDPIDXOFSERVER                                                          STD_OFF
#define SD_ISDEF_SOCONGRPDYNUDPUSEDOFSERVER                                                         STD_OFF
#define SD_ISDEF_TCPSOCONIDENDIDXOFSERVER                                                           STD_OFF
#define SD_ISDEF_TCPSOCONIDSTARTIDXOFSERVER                                                         STD_OFF
#define SD_ISDEF_TCPSOCONIDUSEDOFSERVER                                                             STD_OFF
#define SD_ISDEF_UDPSOCONENDIDXOFSERVER                                                             STD_OFF
#define SD_ISDEF_UDPSOCONSTARTIDXOFSERVER                                                           STD_OFF
#define SD_ISDEF_UDPSOCONUSEDOFSERVER                                                               STD_OFF
#define SD_ISDEF_INVALIDHNDOFSERVERIDMAP                                                            STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVERIDXOFSERVERIDMAP                                            STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVERPARTITIONIDXOFSERVERIDMAP                                   STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVERUSEDOFSERVERIDMAP                                           STD_OFF
#define SD_ISDEF_INITIALOFFERDELAYMAXOFSERVERTIMER                                                  STD_OFF
#define SD_ISDEF_INITIALOFFERDELAYMINOFSERVERTIMER                                                  STD_OFF
#define SD_ISDEF_INITIALOFFERREPETITIONBASEDELAYOFSERVERTIMER                                       STD_OFF
#define SD_ISDEF_INITIALOFFERREPETITIONSMAXOFSERVERTIMER                                            STD_OFF
#define SD_ISDEF_OFFERCYCLICDELAYOFSERVERTIMER                                                      STD_OFF
#define SD_ISDEF_REQUESTRESPONSEMAXDELAYOFSERVERTIMER                                               STD_OFF
#define SD_ISDEF_REQUESTRESPONSEMINDELAYOFSERVERTIMER                                               STD_OFF
#define SD_ISDEF_TTLOFSERVERTIMER                                                                   STD_OFF
#define SD_ISDEF_SERVICEGROUPMEMBERENDIDXOFSERVICEGROUP                                             STD_OFF
#define SD_ISDEF_SERVICEGROUPMEMBERSTARTIDXOFSERVICEGROUP                                           STD_OFF
#define SD_ISDEF_INVALIDHNDOFSERVICEGROUPIDMAP                                                      STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVICEGROUPIDXOFSERVICEGROUPIDMAP                                STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVICEGROUPPARTITIONIDXOFSERVICEGROUPIDMAP                       STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSERVICEGROUPUSEDOFSERVICEGROUPIDMAP                               STD_OFF
#define SD_ISDEF_CLIENTIDXOFSERVICEGROUPMEMBER                                                      STD_OFF
#define SD_ISDEF_CLIENTUSEDOFSERVICEGROUPMEMBER                                                     STD_OFF
#define SD_ISDEF_SERVERIDXOFSERVICEGROUPMEMBER                                                      STD_OFF
#define SD_ISDEF_SERVERUSEDOFSERVICEGROUPMEMBER                                                     STD_OFF
#define SD_ISDEF_INVALIDHNDOFSOCONMODEIDMAP                                                         STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP                                      STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                             STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICSOCONMODEUSEDOFSOCONMODEIDMAP                                     STD_OFF
#define SD_ISDEF_TCPSOCONID                                                                         STD_OFF
#define SD_ISDEF_INVALIDHNDOFTXSOCONIDMAP                                                           STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEIDXOFTXSOCONIDMAP                                         STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFTXSOCONIDMAP                                STD_OFF
#define SD_ISDEF_PARTITIONSPECIFICINSTANCEUSEDOFTXSOCONIDMAP                                        STD_OFF
#define SD_ISDEF_IDOFUDPSOCON                                                                       STD_OFF
#define SD_ISDEF_PRECONFIGUREDOFUDPSOCON                                                            STD_OFF
#define SD_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                        STD_OFF
#define SD_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                     STD_OFF
#define SD_ISDEF_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                               STD_OFF
#define SD_ISDEF_ACLIPV4CINDOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_ACLIPV4OFPCPARTITIONCONFIG                                                         STD_OFF
#define SD_ISDEF_ACLIPV4SINDOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_ACLIPV6CINDOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_ACLIPV6OFPCPARTITIONCONFIG                                                         STD_OFF
#define SD_ISDEF_ACLIPV6SINDOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_ADDRESSSTORAGEOFPCPARTITIONCONFIG                                                  STD_OFF
#define SD_ISDEF_CAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                              STD_OFF
#define SD_ISDEF_CAPABILITYRECORDOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_CLIENTDYNOFPCPARTITIONCONFIG                                                       STD_OFF
#define SD_ISDEF_CLIENTIDMAPOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_CLIENTLISTOFPCPARTITIONCONFIG                                                      STD_OFF
#define SD_ISDEF_CLIENTOFPCPARTITIONCONFIG                                                          STD_OFF
#define SD_ISDEF_CLIENTTIMEROFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_COMMONINITIALDELAYOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPDYNOFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                         STD_OFF
#define SD_ISDEF_CONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_ENDPOINTSTORAGEOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_EVENTHANDLERDYNOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_EVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_EVENTHANDLEROFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_EVENTHANDLERTCPOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_EVENTHANDLERUDPOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_INSTANCEDYNOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_INSTANCEOFPCPARTITIONCONFIG                                                        STD_OFF
#define SD_ISDEF_IPADDRREQUESTOFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_METHODOFPCPARTITIONCONFIG                                                          STD_OFF
#define SD_ISDEF_MULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_MULTICASTSOCONIDOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_OPTIONINDEXOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_PARTITIONDATADYNOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_PAYLOADOFPCPARTITIONCONFIG                                                         STD_OFF
#define SD_ISDEF_PORTSETOFPCPARTITIONCONFIG                                                         STD_OFF
#define SD_ISDEF_REQUESTCNTOFPCPARTITIONCONFIG                                                      STD_OFF
#define SD_ISDEF_ROUTINGGROUPDYNOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_ROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_ROUTINGGROUPOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_RXEVENTOFPCPARTITIONCONFIG                                                         STD_OFF
#define SD_ISDEF_RXPDUIDMAPOFPCPARTITIONCONFIG                                                      STD_OFF
#define SD_ISDEF_SENDENTRYOFPCPARTITIONCONFIG                                                       STD_OFF
#define SD_ISDEF_SERVERDYNOFPCPARTITIONCONFIG                                                       STD_OFF
#define SD_ISDEF_SERVERIDMAPOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_SERVEROFPCPARTITIONCONFIG                                                          STD_OFF
#define SD_ISDEF_SERVERTIMEROFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_SERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SERVICEGROUPOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_SIZEOFACLIPV4CINDOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFACLIPV4OFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_SIZEOFACLIPV4SINDOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFACLIPV6CINDOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFACLIPV6OFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_SIZEOFACLIPV6SINDOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFADDRESSSTORAGEOFPCPARTITIONCONFIG                                            STD_OFF
#define SD_ISDEF_SIZEOFCAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                        STD_OFF
#define SD_ISDEF_SIZEOFCAPABILITYRECORDOFPCPARTITIONCONFIG                                          STD_OFF
#define SD_ISDEF_SIZEOFCLIENTIDMAPOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFCLIENTLISTOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_SIZEOFCLIENTOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_SIZEOFCLIENTTIMEROFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFCOMMONINITIALDELAYOFPCPARTITIONCONFIG                                        STD_OFF
#define SD_ISDEF_SIZEOFCONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                   STD_OFF
#define SD_ISDEF_SIZEOFCONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                        STD_OFF
#define SD_ISDEF_SIZEOFENDPOINTSTORAGEOFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_SIZEOFEVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                     STD_OFF
#define SD_ISDEF_SIZEOFEVENTHANDLEROFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SIZEOFEVENTHANDLERTCPOFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_SIZEOFEVENTHANDLERUDPOFPCPARTITIONCONFIG                                           STD_OFF
#define SD_ISDEF_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                  STD_OFF
#define SD_ISDEF_SIZEOFIPADDRREQUESTOFPCPARTITIONCONFIG                                             STD_OFF
#define SD_ISDEF_SIZEOFMETHODOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_SIZEOFMULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                     STD_OFF
#define SD_ISDEF_SIZEOFMULTICASTSOCONIDOFPCPARTITIONCONFIG                                          STD_OFF
#define SD_ISDEF_SIZEOFOPTIONINDEXOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFPARTITIONDATADYNOFPCPARTITIONCONFIG                                          STD_OFF
#define SD_ISDEF_SIZEOFPAYLOADOFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_SIZEOFPORTSETOFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_SIZEOFREQUESTCNTOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_SIZEOFROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                         STD_OFF
#define SD_ISDEF_SIZEOFROUTINGGROUPOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SIZEOFRXEVENTOFPCPARTITIONCONFIG                                                   STD_OFF
#define SD_ISDEF_SIZEOFRXPDUIDMAPOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_SIZEOFSENDENTRYOFPCPARTITIONCONFIG                                                 STD_OFF
#define SD_ISDEF_SIZEOFSERVERIDMAPOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFSERVEROFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_SIZEOFSERVERTIMEROFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFSERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                         STD_OFF
#define SD_ISDEF_SIZEOFSERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                        STD_OFF
#define SD_ISDEF_SIZEOFSERVICEGROUPOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SIZEOFSOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                        STD_OFF
#define SD_ISDEF_SIZEOFSOCONGRPDYNOFPCPARTITIONCONFIG                                               STD_OFF
#define SD_ISDEF_SIZEOFSOCONMODEDYNOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SIZEOFSOCONMODEIDMAPOFPCPARTITIONCONFIG                                            STD_OFF
#define SD_ISDEF_SIZEOFTCPSOCONIDOFPCPARTITIONCONFIG                                                STD_OFF
#define SD_ISDEF_SIZEOFTRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                        STD_OFF
#define SD_ISDEF_SIZEOFTXSOCONIDMAPOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SIZEOFUDPSOCONOFPCPARTITIONCONFIG                                                  STD_OFF
#define SD_ISDEF_SOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_SOCONGRPDYNOFPCPARTITIONCONFIG                                                     STD_OFF
#define SD_ISDEF_SOCONMODEDYNOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_SOCONMODEIDMAPOFPCPARTITIONCONFIG                                                  STD_OFF
#define SD_ISDEF_TCPSOCONIDOFPCPARTITIONCONFIG                                                      STD_OFF
#define SD_ISDEF_TRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                              STD_OFF
#define SD_ISDEF_TXSOCONIDMAPOFPCPARTITIONCONFIG                                                    STD_OFF
#define SD_ISDEF_UDPSOCONOFPCPARTITIONCONFIG                                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  SdPCEqualsAlwaysToDefines  Sd Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SD_EQ2_ADDROFACLIPV4                                                                        
#define SD_EQ2_ACLIPV4CIND                                                                          
#define SD_EQ2_ACLIPV4SIND                                                                          
#define SD_EQ2_ADDROFACLIPV6                                                                        
#define SD_EQ2_ACLIPV6CIND                                                                          
#define SD_EQ2_ACLIPV6SIND                                                                          
#define SD_EQ2_CAPABILITYRECORD                                                                     
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTR                                                   
#define SD_EQ2_ACLIPV4CINDENDIDXOFCLIENT                                                            
#define SD_EQ2_ACLIPV4CINDSTARTIDXOFCLIENT                                                          
#define SD_EQ2_ACLIPV4CINDUSEDOFCLIENT                                                              
#define SD_EQ2_ACLIPV6CINDENDIDXOFCLIENT                                                            
#define SD_EQ2_ACLIPV6CINDSTARTIDXOFCLIENT                                                          
#define SD_EQ2_ACLIPV6CINDUSEDOFCLIENT                                                              
#define SD_EQ2_AUTOREQUIREOFCLIENT                                                                  
#define SD_EQ2_CAPABILITYRECORDENDIDXOFCLIENT                                                       
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT                                        
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFCLIENT                                       
#define SD_EQ2_CAPABILITYRECORDSTARTIDXOFCLIENT                                                     
#define SD_EQ2_CAPABILITYRECORDUSEDOFCLIENT                                                         
#define SD_EQ2_CLIENTTIMERIDXOFCLIENT                                                               
#define SD_EQ2_COMMONINITIALDELAYIDXOFCLIENT                                                        
#define SD_EQ2_COMMONINITIALDELAYUSEDOFCLIENT                                                       
#define SD_EQ2_CONSUMEDEVENTGROUPENDIDXOFCLIENT                                                     
#define SD_EQ2_CONSUMEDEVENTGROUPSTARTIDXOFCLIENT                                                   
#define SD_EQ2_CONSUMEDEVENTGROUPUSEDOFCLIENT                                                       
#define SD_EQ2_FINDBEHAVIOROFCLIENT                                                                 
#define SD_EQ2_HANDLEIDOFCLIENT                                                                     
#define SD_EQ2_INITIALINSTANCEIDOFCLIENT                                                            
#define SD_EQ2_INSTANCEIDXOFCLIENT                                                                  
#define SD_EQ2_MAJORVERSIONOFCLIENT                                                                 
#define SD_EQ2_METHODIDXOFCLIENT                                                                    
#define SD_EQ2_METHODUSEDOFCLIENT                                                                   
#define SD_EQ2_MINORVERSIONOFCLIENT                                                                 
#define SD_EQ2_MINORVERSIONWILDCARDOFCLIENT                                                         
#define SD_EQ2_SERVICEGROUPMEMBEROFCLIENT                                                           
#define SD_EQ2_SERVICEIDOFCLIENT                                                                    
#define SD_EQ2_SOCONGRPDYNTCPIDXOFCLIENT                                                            
#define SD_EQ2_SOCONGRPDYNTCPUSEDOFCLIENT                                                           
#define SD_EQ2_SOCONGRPDYNUDPIDXOFCLIENT                                                            
#define SD_EQ2_SOCONGRPDYNUDPUSEDOFCLIENT                                                           
#define SD_EQ2_TCPSOCONIDENDIDXOFCLIENT                                                             
#define SD_EQ2_TCPSOCONIDSTARTIDXOFCLIENT                                                           
#define SD_EQ2_TCPSOCONIDUSEDOFCLIENT                                                               
#define SD_EQ2_UDPCLIENTMULTICASTOFCLIENT                                                           
#define SD_EQ2_UDPSOCONENDIDXOFCLIENT                                                               
#define SD_EQ2_UDPSOCONSTARTIDXOFCLIENT                                                             
#define SD_EQ2_UDPSOCONUSEDOFCLIENT                                                                 
#define SD_EQ2_INVALIDHNDOFCLIENTIDMAP                                                              
#define SD_EQ2_PARTITIONSPECIFICCLIENTIDXOFCLIENTIDMAP                                              
#define SD_EQ2_PARTITIONSPECIFICCLIENTPARTITIONIDXOFCLIENTIDMAP                                     
#define SD_EQ2_PARTITIONSPECIFICCLIENTUSEDOFCLIENTIDMAP                                             
#define SD_EQ2_INITIALFINDDELAYMAXOFCLIENTTIMER                                                     
#define SD_EQ2_INITIALFINDDELAYMINOFCLIENTTIMER                                                     
#define SD_EQ2_INITIALFINDREPETITIONBASEDELAYOFCLIENTTIMER                                          
#define SD_EQ2_INITIALFINDREPETITIONSMAXOFCLIENTTIMER                                               
#define SD_EQ2_REQUESTRESPONSEMAXDELAYOFCLIENTTIMER                                                 
#define SD_EQ2_REQUESTRESPONSEMINDELAYOFCLIENTTIMER                                                 
#define SD_EQ2_TTLOFCLIENTTIMER                                                                     
#define SD_EQ2_AUTOREQUIREOFCONSUMEDEVENTGROUP                                                      
#define SD_EQ2_CLIENTIDXOFCONSUMEDEVENTGROUP                                                        
#define SD_EQ2_CLIENTTIMERIDXOFCONSUMEDEVENTGROUP                                                   
#define SD_EQ2_EVENTGROUPIDOFCONSUMEDEVENTGROUP                                                     
#define SD_EQ2_HANDLEIDOFCONSUMEDEVENTGROUP                                                         
#define SD_EQ2_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP                                         
#define SD_EQ2_MULTICASTENDPOINTADDRUSEDOFCONSUMEDEVENTGROUP                                        
#define SD_EQ2_MULTICASTSOCONIDENDIDXOFCONSUMEDEVENTGROUP                                           
#define SD_EQ2_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP                                         
#define SD_EQ2_MULTICASTSOCONIDUSEDOFCONSUMEDEVENTGROUP                                             
#define SD_EQ2_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP                                   
#define SD_EQ2_ROUTINGGROUPMULTICASTACTREFUSEDOFCONSUMEDEVENTGROUP                                  
#define SD_EQ2_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP                                         
#define SD_EQ2_ROUTINGGROUPTCPACTREFUSEDOFCONSUMEDEVENTGROUP                                        
#define SD_EQ2_ROUTINGGROUPUDPACTREFIDXOFCONSUMEDEVENTGROUP                                         
#define SD_EQ2_ROUTINGGROUPUDPACTREFUSEDOFCONSUMEDEVENTGROUP                                        
#define SD_EQ2_INVALIDHNDOFCONSUMEDEVENTGROUPIDMAP                                                  
#define SD_EQ2_PARTITIONSPECIFICCONSUMEDEVENTGROUPIDXOFCONSUMEDEVENTGROUPIDMAP                      
#define SD_EQ2_PARTITIONSPECIFICCONSUMEDEVENTGROUPPARTITIONIDXOFCONSUMEDEVENTGROUPIDMAP             
#define SD_EQ2_PARTITIONSPECIFICCONSUMEDEVENTGROUPUSEDOFCONSUMEDEVENTGROUPIDMAP                     
#define SD_EQ2_CLIENTLISTENDIDXOFEVENTHANDLER                                                       
#define SD_EQ2_CLIENTLISTSTARTIDXOFEVENTHANDLER                                                     
#define SD_EQ2_EVENTGROUPIDOFEVENTHANDLER                                                           
#define SD_EQ2_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER                                               
#define SD_EQ2_EVENTHANDLERMULTICASTUSEDOFEVENTHANDLER                                              
#define SD_EQ2_EVENTHANDLERTCPIDXOFEVENTHANDLER                                                     
#define SD_EQ2_EVENTHANDLERTCPUSEDOFEVENTHANDLER                                                    
#define SD_EQ2_EVENTHANDLERUDPIDXOFEVENTHANDLER                                                     
#define SD_EQ2_EVENTHANDLERUDPUSEDOFEVENTHANDLER                                                    
#define SD_EQ2_HANDLEIDOFEVENTHANDLER                                                               
#define SD_EQ2_MULTICASTTHRESHOLDOFEVENTHANDLER                                                     
#define SD_EQ2_SERVERIDXOFEVENTHANDLER                                                              
#define SD_EQ2_SERVERTIMERIDXOFEVENTHANDLER                                                         
#define SD_EQ2_SOCONACTIVATIONMAPENDIDXOFEVENTHANDLER                                               
#define SD_EQ2_SOCONACTIVATIONMAPSTARTIDXOFEVENTHANDLER                                             
#define SD_EQ2_SOCONACTIVATIONMAPUSEDOFEVENTHANDLER                                                 
#define SD_EQ2_ROUTINGGROUPACTREFIDXOFEVENTHANDLERMULTICAST                                         
#define SD_EQ2_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERMULTICAST                                        
#define SD_EQ2_SOCONIDOFEVENTHANDLERMULTICAST                                                       
#define SD_EQ2_ROUTINGGROUPACTREFIDXOFEVENTHANDLERTCP                                               
#define SD_EQ2_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERTCP                                              
#define SD_EQ2_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERTCP                                              
#define SD_EQ2_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERTCP                                             
#define SD_EQ2_ROUTINGGROUPACTREFIDXOFEVENTHANDLERUDP                                               
#define SD_EQ2_ROUTINGGROUPACTREFUSEDOFEVENTHANDLERUDP                                              
#define SD_EQ2_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP                                              
#define SD_EQ2_ROUTINGGROUPTRIGGERUSEDOFEVENTHANDLERUDP                                             
#define SD_EQ2_ADDRESSSTORAGEENDIDXOFINSTANCE                                                       
#define SD_EQ2_ADDRESSSTORAGESTARTIDXOFINSTANCE                                                     
#define SD_EQ2_CAPABILITYRECORDENDIDXOFINSTANCE                                                     
#define SD_EQ2_CAPABILITYRECORDSTARTIDXOFINSTANCE                                                   
#define SD_EQ2_CAPABILITYRECORDUSEDOFINSTANCE                                                       
#define SD_EQ2_CLIENTENDIDXOFINSTANCE                                                               
#define SD_EQ2_CLIENTSTARTIDXOFINSTANCE                                                             
#define SD_EQ2_CLIENTUSEDOFINSTANCE                                                                 
#define SD_EQ2_EMALFORMEDMSGIDOFINSTANCE                                                            
#define SD_EQ2_ENACKRECVIDOFINSTANCE                                                                
#define SD_EQ2_EOUTOFRESIDOFINSTANCE                                                                
#define SD_EQ2_ENDPOINTSTORAGEENDIDXOFINSTANCE                                                      
#define SD_EQ2_ENDPOINTSTORAGESTARTIDXOFINSTANCE                                                    
#define SD_EQ2_EVENTHANDLERENDIDXOFINSTANCE                                                         
#define SD_EQ2_EVENTHANDLERSTARTIDXOFINSTANCE                                                       
#define SD_EQ2_EVENTHANDLERUSEDOFINSTANCE                                                           
#define SD_EQ2_LOCALADDRESSCHECKLENGTHOFINSTANCE                                                    
#define SD_EQ2_MULTICASTRXPDUIDOFINSTANCE                                                           
#define SD_EQ2_MULTICASTRXSOCONIDOFINSTANCE                                                         
#define SD_EQ2_QUEUEPROCESSLIMITOFINSTANCE                                                          
#define SD_EQ2_RETRYDELAYOFINSTANCE                                                                 
#define SD_EQ2_RETRYMAXOFINSTANCE                                                                   
#define SD_EQ2_RXEVENTENDIDXOFINSTANCE                                                              
#define SD_EQ2_RXEVENTSTARTIDXOFINSTANCE                                                            
#define SD_EQ2_RXEVENTUSEDOFINSTANCE                                                                
#define SD_EQ2_SENDENTRYCAPACITYOFINSTANCE                                                          
#define SD_EQ2_SENDENTRYENDIDXOFINSTANCE                                                            
#define SD_EQ2_SENDENTRYSTARTIDXOFINSTANCE                                                          
#define SD_EQ2_SERVERENDIDXOFINSTANCE                                                               
#define SD_EQ2_SERVERSTARTIDXOFINSTANCE                                                             
#define SD_EQ2_SERVERUSEDOFINSTANCE                                                                 
#define SD_EQ2_SEVDUPLICATEOFFEROFINSTANCE                                                          
#define SD_EQ2_SEVFAILEDMETHODREQOFINSTANCE                                                         
#define SD_EQ2_SEVFAILEDOFFEROFINSTANCE                                                             
#define SD_EQ2_SEVFAILEDSUBOFINSTANCE                                                               
#define SD_EQ2_TCPSOCONIDENDIDXOFINSTANCE                                                           
#define SD_EQ2_TCPSOCONIDSTARTIDXOFINSTANCE                                                         
#define SD_EQ2_TCPSOCONIDUSEDOFINSTANCE                                                             
#define SD_EQ2_TXPDUIDOFINSTANCE                                                                    
#define SD_EQ2_TXSOCONIDOFINSTANCE                                                                  
#define SD_EQ2_UDPSOCONENDIDXOFINSTANCE                                                             
#define SD_EQ2_UDPSOCONSTARTIDXOFINSTANCE                                                           
#define SD_EQ2_UDPSOCONUSEDOFINSTANCE                                                               
#define SD_EQ2_UNICASTRXPDUIDOFINSTANCE                                                             
#define SD_EQ2_UNICASTRXSOCONIDOFINSTANCE                                                           
#define SD_EQ2_PORTSETIDXOFIPADDRREQUEST                                                            
#define SD_EQ2_REQUESTCNTIDXOFIPADDRREQUEST                                                         
#define SD_EQ2_SOCONIDOFIPADDRREQUEST                                                               
#define SD_EQ2_STATICIPCONFIGURATIONOFIPADDRREQUEST                                                 
#define SD_EQ2_STATICPORTCONFIGURATIONOFIPADDRREQUEST                                               
#define SD_EQ2_ROUTINGGROUPACTREFIDXOFMETHOD                                                        
#define SD_EQ2_ROUTINGGROUPACTREFUSEDOFMETHOD                                                       
#define SD_EQ2_TCPCONFIGUREDOFMETHOD                                                                
#define SD_EQ2_UDPCONFIGUREDOFMETHOD                                                                
#define SD_EQ2_MULTICASTSOCONID                                                                     
#define SD_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                           
#define SD_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                   
#define SD_EQ2_ROUTINGGROUP                                                                         
#define SD_EQ2_INVALIDHNDOFROUTINGGROUPIDMAP                                                        
#define SD_EQ2_SERVERIDXOFROUTINGGROUPIDMAP                                                         
#define SD_EQ2_SERVERPARTITIONIDXOFROUTINGGROUPIDMAP                                                
#define SD_EQ2_SERVERUSEDOFROUTINGGROUPIDMAP                                                        
#define SD_EQ2_INVALIDHNDOFRXPDUIDMAP                                                               
#define SD_EQ2_PARTITIONSPECIFICINSTANCEIDXOFRXPDUIDMAP                                             
#define SD_EQ2_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFRXPDUIDMAP                                    
#define SD_EQ2_PARTITIONSPECIFICINSTANCEUSEDOFRXPDUIDMAP                                            
#define SD_EQ2_ACLIPV4SINDENDIDXOFSERVER                                                            
#define SD_EQ2_ACLIPV4SINDSTARTIDXOFSERVER                                                          
#define SD_EQ2_ACLIPV4SINDUSEDOFSERVER                                                              
#define SD_EQ2_ACLIPV6SINDENDIDXOFSERVER                                                            
#define SD_EQ2_ACLIPV6SINDSTARTIDXOFSERVER                                                          
#define SD_EQ2_ACLIPV6SINDUSEDOFSERVER                                                              
#define SD_EQ2_AUTOAVAILABLEOFSERVER                                                                
#define SD_EQ2_CAPABILITYRECORDENDIDXOFSERVER                                                       
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER                                        
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTRUSEDOFSERVER                                       
#define SD_EQ2_CAPABILITYRECORDSTARTIDXOFSERVER                                                     
#define SD_EQ2_CAPABILITYRECORDUSEDOFSERVER                                                         
#define SD_EQ2_COMMONINITIALDELAYIDXOFSERVER                                                        
#define SD_EQ2_COMMONINITIALDELAYUSEDOFSERVER                                                       
#define SD_EQ2_EVENTHANDLERENDIDXOFSERVER                                                           
#define SD_EQ2_EVENTHANDLERSTARTIDXOFSERVER                                                         
#define SD_EQ2_EVENTHANDLERUSEDOFSERVER                                                             
#define SD_EQ2_HANDLEIDOFSERVER                                                                     
#define SD_EQ2_INITIALINSTANCEIDOFSERVER                                                            
#define SD_EQ2_INSTANCEIDXOFSERVER                                                                  
#define SD_EQ2_MAJORVERSIONOFSERVER                                                                 
#define SD_EQ2_METHODIDXOFSERVER                                                                    
#define SD_EQ2_METHODUSEDOFSERVER                                                                   
#define SD_EQ2_MINORVERSIONOFSERVER                                                                 
#define SD_EQ2_SERVERTIMERIDXOFSERVER                                                               
#define SD_EQ2_SERVICEGROUPMEMBEROFSERVER                                                           
#define SD_EQ2_SERVICEIDOFSERVER                                                                    
#define SD_EQ2_SOCONGRPDYNTCPIDXOFSERVER                                                            
#define SD_EQ2_SOCONGRPDYNTCPUSEDOFSERVER                                                           
#define SD_EQ2_SOCONGRPDYNUDPIDXOFSERVER                                                            
#define SD_EQ2_SOCONGRPDYNUDPUSEDOFSERVER                                                           
#define SD_EQ2_TCPSOCONIDENDIDXOFSERVER                                                             
#define SD_EQ2_TCPSOCONIDSTARTIDXOFSERVER                                                           
#define SD_EQ2_TCPSOCONIDUSEDOFSERVER                                                               
#define SD_EQ2_UDPSOCONENDIDXOFSERVER                                                               
#define SD_EQ2_UDPSOCONSTARTIDXOFSERVER                                                             
#define SD_EQ2_UDPSOCONUSEDOFSERVER                                                                 
#define SD_EQ2_INVALIDHNDOFSERVERIDMAP                                                              
#define SD_EQ2_PARTITIONSPECIFICSERVERIDXOFSERVERIDMAP                                              
#define SD_EQ2_PARTITIONSPECIFICSERVERPARTITIONIDXOFSERVERIDMAP                                     
#define SD_EQ2_PARTITIONSPECIFICSERVERUSEDOFSERVERIDMAP                                             
#define SD_EQ2_INITIALOFFERDELAYMAXOFSERVERTIMER                                                    
#define SD_EQ2_INITIALOFFERDELAYMINOFSERVERTIMER                                                    
#define SD_EQ2_INITIALOFFERREPETITIONBASEDELAYOFSERVERTIMER                                         
#define SD_EQ2_INITIALOFFERREPETITIONSMAXOFSERVERTIMER                                              
#define SD_EQ2_OFFERCYCLICDELAYOFSERVERTIMER                                                        
#define SD_EQ2_REQUESTRESPONSEMAXDELAYOFSERVERTIMER                                                 
#define SD_EQ2_REQUESTRESPONSEMINDELAYOFSERVERTIMER                                                 
#define SD_EQ2_TTLOFSERVERTIMER                                                                     
#define SD_EQ2_SERVICEGROUPMEMBERENDIDXOFSERVICEGROUP                                               
#define SD_EQ2_SERVICEGROUPMEMBERSTARTIDXOFSERVICEGROUP                                             
#define SD_EQ2_INVALIDHNDOFSERVICEGROUPIDMAP                                                        
#define SD_EQ2_PARTITIONSPECIFICSERVICEGROUPIDXOFSERVICEGROUPIDMAP                                  
#define SD_EQ2_PARTITIONSPECIFICSERVICEGROUPPARTITIONIDXOFSERVICEGROUPIDMAP                         
#define SD_EQ2_PARTITIONSPECIFICSERVICEGROUPUSEDOFSERVICEGROUPIDMAP                                 
#define SD_EQ2_CLIENTIDXOFSERVICEGROUPMEMBER                                                        
#define SD_EQ2_CLIENTUSEDOFSERVICEGROUPMEMBER                                                       
#define SD_EQ2_SERVERIDXOFSERVICEGROUPMEMBER                                                        
#define SD_EQ2_SERVERUSEDOFSERVICEGROUPMEMBER                                                       
#define SD_EQ2_INVALIDHNDOFSOCONMODEIDMAP                                                           
#define SD_EQ2_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP                                        
#define SD_EQ2_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                               
#define SD_EQ2_PARTITIONSPECIFICSOCONMODEUSEDOFSOCONMODEIDMAP                                       
#define SD_EQ2_TCPSOCONID                                                                           
#define SD_EQ2_INVALIDHNDOFTXSOCONIDMAP                                                             
#define SD_EQ2_PARTITIONSPECIFICINSTANCEIDXOFTXSOCONIDMAP                                           
#define SD_EQ2_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFTXSOCONIDMAP                                  
#define SD_EQ2_PARTITIONSPECIFICINSTANCEUSEDOFTXSOCONIDMAP                                          
#define SD_EQ2_IDOFUDPSOCON                                                                         
#define SD_EQ2_PRECONFIGUREDOFUDPSOCON                                                              
#define SD_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                          
#define SD_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                       
#define SD_EQ2_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                 
#define SD_EQ2_ACLIPV4CINDOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_ACLIPV4OFPCPARTITIONCONFIG                                                           
#define SD_EQ2_ACLIPV4SINDOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_ACLIPV6CINDOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_ACLIPV6OFPCPARTITIONCONFIG                                                           
#define SD_EQ2_ACLIPV6SINDOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_ADDRESSSTORAGEOFPCPARTITIONCONFIG                                                    
#define SD_EQ2_CAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                                
#define SD_EQ2_CAPABILITYRECORDOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_CLIENTDYNOFPCPARTITIONCONFIG                                                         
#define SD_EQ2_CLIENTIDMAPOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_CLIENTLISTOFPCPARTITIONCONFIG                                                        
#define SD_EQ2_CLIENTOFPCPARTITIONCONFIG                                                            
#define SD_EQ2_CLIENTTIMEROFPCPARTITIONCONFIG                                                       
#define SD_EQ2_COMMONINITIALDELAYOFPCPARTITIONCONFIG                                                
#define SD_EQ2_CONSUMEDEVENTGROUPDYNOFPCPARTITIONCONFIG                                             
#define SD_EQ2_CONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                           
#define SD_EQ2_CONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                                
#define SD_EQ2_ENDPOINTSTORAGEOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_EVENTHANDLERDYNOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_EVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                             
#define SD_EQ2_EVENTHANDLEROFPCPARTITIONCONFIG                                                      
#define SD_EQ2_EVENTHANDLERTCPOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_EVENTHANDLERUDPOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_INSTANCEDYNOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_INSTANCEOFPCPARTITIONCONFIG                                                          
#define SD_EQ2_IPADDRREQUESTOFPCPARTITIONCONFIG                                                     
#define SD_EQ2_METHODOFPCPARTITIONCONFIG                                                            
#define SD_EQ2_MULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                             
#define SD_EQ2_MULTICASTSOCONIDOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_OPTIONINDEXOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_PARTITIONDATADYNOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_PAYLOADOFPCPARTITIONCONFIG                                                           
#define SD_EQ2_PORTSETOFPCPARTITIONCONFIG                                                           
#define SD_EQ2_REQUESTCNTOFPCPARTITIONCONFIG                                                        
#define SD_EQ2_ROUTINGGROUPDYNOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_ROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_ROUTINGGROUPOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_RXEVENTOFPCPARTITIONCONFIG                                                           
#define SD_EQ2_RXPDUIDMAPOFPCPARTITIONCONFIG                                                        
#define SD_EQ2_SENDENTRYOFPCPARTITIONCONFIG                                                         
#define SD_EQ2_SERVERDYNOFPCPARTITIONCONFIG                                                         
#define SD_EQ2_SERVERIDMAPOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_SERVEROFPCPARTITIONCONFIG                                                            
#define SD_EQ2_SERVERTIMEROFPCPARTITIONCONFIG                                                       
#define SD_EQ2_SERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                                
#define SD_EQ2_SERVICEGROUPOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_SIZEOFACLIPV4CINDOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFACLIPV4OFPCPARTITIONCONFIG                                                     
#define SD_EQ2_SIZEOFACLIPV4SINDOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFACLIPV6CINDOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFACLIPV6OFPCPARTITIONCONFIG                                                     
#define SD_EQ2_SIZEOFACLIPV6SINDOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFADDRESSSTORAGEOFPCPARTITIONCONFIG                                              
#define SD_EQ2_SIZEOFCAPABILITYRECORDFUNCTIONCALLOUTPTROFPCPARTITIONCONFIG                          
#define SD_EQ2_SIZEOFCAPABILITYRECORDOFPCPARTITIONCONFIG                                            
#define SD_EQ2_SIZEOFCLIENTIDMAPOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFCLIENTLISTOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_SIZEOFCLIENTOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_SIZEOFCLIENTTIMEROFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFCOMMONINITIALDELAYOFPCPARTITIONCONFIG                                          
#define SD_EQ2_SIZEOFCONSUMEDEVENTGROUPIDMAPOFPCPARTITIONCONFIG                                     
#define SD_EQ2_SIZEOFCONSUMEDEVENTGROUPOFPCPARTITIONCONFIG                                          
#define SD_EQ2_SIZEOFENDPOINTSTORAGEOFPCPARTITIONCONFIG                                             
#define SD_EQ2_SIZEOFEVENTHANDLERMULTICASTOFPCPARTITIONCONFIG                                       
#define SD_EQ2_SIZEOFEVENTHANDLEROFPCPARTITIONCONFIG                                                
#define SD_EQ2_SIZEOFEVENTHANDLERTCPOFPCPARTITIONCONFIG                                             
#define SD_EQ2_SIZEOFEVENTHANDLERUDPOFPCPARTITIONCONFIG                                             
#define SD_EQ2_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                    
#define SD_EQ2_SIZEOFIPADDRREQUESTOFPCPARTITIONCONFIG                                               
#define SD_EQ2_SIZEOFMETHODOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_SIZEOFMULTICASTENDPOINTADDROFPCPARTITIONCONFIG                                       
#define SD_EQ2_SIZEOFMULTICASTSOCONIDOFPCPARTITIONCONFIG                                            
#define SD_EQ2_SIZEOFOPTIONINDEXOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFPARTITIONDATADYNOFPCPARTITIONCONFIG                                            
#define SD_EQ2_SIZEOFPAYLOADOFPCPARTITIONCONFIG                                                     
#define SD_EQ2_SIZEOFPORTSETOFPCPARTITIONCONFIG                                                     
#define SD_EQ2_SIZEOFREQUESTCNTOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_SIZEOFROUTINGGROUPIDMAPOFPCPARTITIONCONFIG                                           
#define SD_EQ2_SIZEOFROUTINGGROUPOFPCPARTITIONCONFIG                                                
#define SD_EQ2_SIZEOFRXEVENTOFPCPARTITIONCONFIG                                                     
#define SD_EQ2_SIZEOFRXPDUIDMAPOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_SIZEOFSENDENTRYOFPCPARTITIONCONFIG                                                   
#define SD_EQ2_SIZEOFSERVERIDMAPOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFSERVEROFPCPARTITIONCONFIG                                                      
#define SD_EQ2_SIZEOFSERVERTIMEROFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFSERVICEGROUPIDMAPOFPCPARTITIONCONFIG                                           
#define SD_EQ2_SIZEOFSERVICEGROUPMEMBEROFPCPARTITIONCONFIG                                          
#define SD_EQ2_SIZEOFSERVICEGROUPOFPCPARTITIONCONFIG                                                
#define SD_EQ2_SIZEOFSOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                          
#define SD_EQ2_SIZEOFSOCONGRPDYNOFPCPARTITIONCONFIG                                                 
#define SD_EQ2_SIZEOFSOCONMODEDYNOFPCPARTITIONCONFIG                                                
#define SD_EQ2_SIZEOFSOCONMODEIDMAPOFPCPARTITIONCONFIG                                              
#define SD_EQ2_SIZEOFTCPSOCONIDOFPCPARTITIONCONFIG                                                  
#define SD_EQ2_SIZEOFTRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                          
#define SD_EQ2_SIZEOFTXSOCONIDMAPOFPCPARTITIONCONFIG                                                
#define SD_EQ2_SIZEOFUDPSOCONOFPCPARTITIONCONFIG                                                    
#define SD_EQ2_SOCONACTIVATIONMAPOFPCPARTITIONCONFIG                                                
#define SD_EQ2_SOCONGRPDYNOFPCPARTITIONCONFIG                                                       
#define SD_EQ2_SOCONMODEDYNOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_SOCONMODEIDMAPOFPCPARTITIONCONFIG                                                    
#define SD_EQ2_TCPSOCONIDOFPCPARTITIONCONFIG                                                        
#define SD_EQ2_TRIGGERTRANSMITDYNOFPCPARTITIONCONFIG                                                
#define SD_EQ2_TXSOCONIDMAPOFPCPARTITIONCONFIG                                                      
#define SD_EQ2_UDPSOCONOFPCPARTITIONCONFIG                                                          
/** 
  \}
*/ 

/** 
  \defgroup  SdPCSymbolicInitializationPointers  Sd Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Sd_Config_Ptr                                                                               &(Sd_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'Sd' */
/** 
  \}
*/ 

/** 
  \defgroup  SdPCInitializationSymbols  Sd Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Sd_Config                                                                                   Sd_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'Sd */
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGeneral  Sd General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SD_CHECK_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SD_FINAL_MAGIC_NUMBER                                                                       0xAB1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Sd */
#define SD_INDIVIDUAL_POSTBUILD                                                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Sd' is not configured to be postbuild capable. */
#define SD_INIT_DATA                                                                                SD_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SD_INIT_DATA_HASH_CODE                                                                      615995392  /**< the precompile constant to validate the initialization structure at initialization time of Sd with a hashcode. The seed value is '0xAB1Eu' */
#define SD_USE_ECUM_BSW_ERROR_HOOK                                                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SD_USE_INIT_POINTER                                                                         STD_ON  /**< STD_ON if the init pointer Sd shall be used. */
#define Sd_PartitionIndexOfCSLForSD_NO_OS_APPL_MAPPED                                               0u  /**< internal partition index of the ComStackLib for the partition SD_NO_OS_APPL_MAPPED */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
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
  \defgroup  SdPCGetRootDataMacros  Sd Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Sd_GetPCPartitionConfigOfPCConfig()                                                         Sd_ConfigDataPtr->PCPartitionConfigOfPCConfig
#define Sd_GetPartitionIdentifiersOfPCConfig()                                                      Sd_ConfigDataPtr->PartitionIdentifiersOfPCConfig
#define Sd_GetSizeOfPartitionIdentifiersOfPCConfig()                                                Sd_ConfigDataPtr->SizeOfPartitionIdentifiersOfPCConfig
#define Sd_GetAclIPv4CIndOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv4CIndOfPCPartitionConfig
#define Sd_GetAclIPv4OfPCPartitionConfig(partitionIndex)                                            Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv4OfPCPartitionConfig
#define Sd_GetAclIPv4SIndOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv4SIndOfPCPartitionConfig
#define Sd_GetAclIPv6CIndOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv6CIndOfPCPartitionConfig
#define Sd_GetAclIPv6OfPCPartitionConfig(partitionIndex)                                            Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv6OfPCPartitionConfig
#define Sd_GetAclIPv6SIndOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AclIPv6SIndOfPCPartitionConfig
#define Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)                                     Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].AddressStorageOfPCPartitionConfig
#define Sd_GetCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()                               Sd_GetPCPartitionConfigOfPCConfig()[(0)].CapabilityRecordFunctionCalloutPtrOfPCPartitionConfig
#define Sd_GetCapabilityRecordOfPCPartitionConfig()                                                 Sd_GetPCPartitionConfigOfPCConfig()[(0)].CapabilityRecordOfPCPartitionConfig
#define Sd_GetClientDynOfPCPartitionConfig(partitionIndex)                                          Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ClientDynOfPCPartitionConfig
#define Sd_GetClientIdMapOfPCPartitionConfig()                                                      Sd_GetPCPartitionConfigOfPCConfig()[(0)].ClientIdMapOfPCPartitionConfig
#define Sd_GetClientListOfPCPartitionConfig(partitionIndex)                                         Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ClientListOfPCPartitionConfig
#define Sd_GetClientOfPCPartitionConfig(partitionIndex)                                             Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ClientOfPCPartitionConfig
#define Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ClientTimerOfPCPartitionConfig
#define Sd_GetCommonInitialDelayOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].CommonInitialDelayOfPCPartitionConfig
#define Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ConsumedEventgroupDynOfPCPartitionConfig
#define Sd_GetConsumedEventgroupIdMapOfPCPartitionConfig()                                          Sd_GetPCPartitionConfigOfPCConfig()[(0)].ConsumedEventgroupIdMapOfPCPartitionConfig
#define Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ConsumedEventgroupOfPCPartitionConfig
#define Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EndpointStorageOfPCPartitionConfig
#define Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventHandlerDynOfPCPartitionConfig
#define Sd_GetEventHandlerMulticastOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventHandlerMulticastOfPCPartitionConfig
#define Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventHandlerOfPCPartitionConfig
#define Sd_GetEventHandlerTcpOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventHandlerTcpOfPCPartitionConfig
#define Sd_GetEventHandlerUdpOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventHandlerUdpOfPCPartitionConfig
#define Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InstanceDynOfPCPartitionConfig
#define Sd_GetInstanceOfPCPartitionConfig(partitionIndex)                                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InstanceOfPCPartitionConfig
#define Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IpAddrRequestOfPCPartitionConfig
#define Sd_GetMethodOfPCPartitionConfig(partitionIndex)                                             Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MethodOfPCPartitionConfig
#define Sd_GetMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MulticastEndpointAddrOfPCPartitionConfig
#define Sd_GetMulticastSoConIdOfPCPartitionConfig(partitionIndex)                                   Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MulticastSoConIdOfPCPartitionConfig
#define Sd_GetOptionIndexOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].OptionIndexOfPCPartitionConfig
#define Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)                                   Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PartitionDataDynOfPCPartitionConfig
#define Sd_GetPayloadOfPCPartitionConfig(partitionIndex)                                            Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PayloadOfPCPartitionConfig
#define Sd_GetPortSetOfPCPartitionConfig(partitionIndex)                                            Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PortSetOfPCPartitionConfig
#define Sd_GetRequestCntOfPCPartitionConfig(partitionIndex)                                         Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RequestCntOfPCPartitionConfig
#define Sd_GetRoutingGroupDynOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RoutingGroupDynOfPCPartitionConfig
#define Sd_GetRoutingGroupIdMapOfPCPartitionConfig()                                                Sd_GetPCPartitionConfigOfPCConfig()[(0)].RoutingGroupIdMapOfPCPartitionConfig
#define Sd_GetRoutingGroupOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RoutingGroupOfPCPartitionConfig
#define Sd_GetRxEventOfPCPartitionConfig(partitionIndex)                                            Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxEventOfPCPartitionConfig
#define Sd_GetRxPduIdMapOfPCPartitionConfig()                                                       Sd_GetPCPartitionConfigOfPCConfig()[(0)].RxPduIdMapOfPCPartitionConfig
#define Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)                                          Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SendEntryOfPCPartitionConfig
#define Sd_GetServerDynOfPCPartitionConfig(partitionIndex)                                          Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ServerDynOfPCPartitionConfig
#define Sd_GetServerIdMapOfPCPartitionConfig()                                                      Sd_GetPCPartitionConfigOfPCConfig()[(0)].ServerIdMapOfPCPartitionConfig
#define Sd_GetServerOfPCPartitionConfig(partitionIndex)                                             Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ServerOfPCPartitionConfig
#define Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ServerTimerOfPCPartitionConfig
#define Sd_GetServiceGroupIdMapOfPCPartitionConfig()                                                Sd_GetPCPartitionConfigOfPCConfig()[(0)].ServiceGroupIdMapOfPCPartitionConfig
#define Sd_GetServiceGroupMemberOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ServiceGroupMemberOfPCPartitionConfig
#define Sd_GetServiceGroupOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ServiceGroupOfPCPartitionConfig
#define Sd_GetSizeOfAclIPv4CIndOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv4CIndOfPCPartitionConfig
#define Sd_GetSizeOfAclIPv4OfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv4OfPCPartitionConfig
#define Sd_GetSizeOfAclIPv4SIndOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv4SIndOfPCPartitionConfig
#define Sd_GetSizeOfAclIPv6CIndOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv6CIndOfPCPartitionConfig
#define Sd_GetSizeOfAclIPv6OfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv6OfPCPartitionConfig
#define Sd_GetSizeOfAclIPv6SIndOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAclIPv6SIndOfPCPartitionConfig
#define Sd_GetSizeOfAddressStorageOfPCPartitionConfig(partitionIndex)                               Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfAddressStorageOfPCPartitionConfig
#define Sd_GetSizeOfCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()                         Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig
#define Sd_GetSizeOfCapabilityRecordOfPCPartitionConfig()                                           Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfCapabilityRecordOfPCPartitionConfig
#define Sd_GetSizeOfClientIdMapOfPCPartitionConfig()                                                Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfClientIdMapOfPCPartitionConfig
#define Sd_GetSizeOfClientListOfPCPartitionConfig(partitionIndex)                                   Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfClientListOfPCPartitionConfig
#define Sd_GetSizeOfClientOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfClientOfPCPartitionConfig
#define Sd_GetSizeOfClientTimerOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfClientTimerOfPCPartitionConfig
#define Sd_GetSizeOfCommonInitialDelayOfPCPartitionConfig(partitionIndex)                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfCommonInitialDelayOfPCPartitionConfig
#define Sd_GetSizeOfConsumedEventgroupIdMapOfPCPartitionConfig()                                    Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfConsumedEventgroupIdMapOfPCPartitionConfig
#define Sd_GetSizeOfConsumedEventgroupOfPCPartitionConfig(partitionIndex)                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfConsumedEventgroupOfPCPartitionConfig
#define Sd_GetSizeOfEndpointStorageOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEndpointStorageOfPCPartitionConfig
#define Sd_GetSizeOfEventHandlerMulticastOfPCPartitionConfig(partitionIndex)                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventHandlerMulticastOfPCPartitionConfig
#define Sd_GetSizeOfEventHandlerOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventHandlerOfPCPartitionConfig
#define Sd_GetSizeOfEventHandlerTcpOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventHandlerTcpOfPCPartitionConfig
#define Sd_GetSizeOfEventHandlerUdpOfPCPartitionConfig(partitionIndex)                              Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventHandlerUdpOfPCPartitionConfig
#define Sd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)                                     Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfInstanceOfPCPartitionConfig
#define Sd_GetSizeOfIpAddrRequestOfPCPartitionConfig(partitionIndex)                                Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfIpAddrRequestOfPCPartitionConfig
#define Sd_GetSizeOfMethodOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMethodOfPCPartitionConfig
#define Sd_GetSizeOfMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMulticastEndpointAddrOfPCPartitionConfig
#define Sd_GetSizeOfMulticastSoConIdOfPCPartitionConfig(partitionIndex)                             Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMulticastSoConIdOfPCPartitionConfig
#define Sd_GetSizeOfOptionIndexOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfOptionIndexOfPCPartitionConfig
#define Sd_GetSizeOfPartitionDataDynOfPCPartitionConfig(partitionIndex)                             Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPartitionDataDynOfPCPartitionConfig
#define Sd_GetSizeOfPayloadOfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPayloadOfPCPartitionConfig
#define Sd_GetSizeOfPortSetOfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPortSetOfPCPartitionConfig
#define Sd_GetSizeOfRequestCntOfPCPartitionConfig(partitionIndex)                                   Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRequestCntOfPCPartitionConfig
#define Sd_GetSizeOfRoutingGroupIdMapOfPCPartitionConfig()                                          Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfRoutingGroupIdMapOfPCPartitionConfig
#define Sd_GetSizeOfRoutingGroupOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRoutingGroupOfPCPartitionConfig
#define Sd_GetSizeOfRxEventOfPCPartitionConfig(partitionIndex)                                      Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRxEventOfPCPartitionConfig
#define Sd_GetSizeOfRxPduIdMapOfPCPartitionConfig()                                                 Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfRxPduIdMapOfPCPartitionConfig
#define Sd_GetSizeOfSendEntryOfPCPartitionConfig(partitionIndex)                                    Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSendEntryOfPCPartitionConfig
#define Sd_GetSizeOfServerIdMapOfPCPartitionConfig()                                                Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfServerIdMapOfPCPartitionConfig
#define Sd_GetSizeOfServerOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfServerOfPCPartitionConfig
#define Sd_GetSizeOfServerTimerOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfServerTimerOfPCPartitionConfig
#define Sd_GetSizeOfServiceGroupIdMapOfPCPartitionConfig()                                          Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfServiceGroupIdMapOfPCPartitionConfig
#define Sd_GetSizeOfServiceGroupMemberOfPCPartitionConfig(partitionIndex)                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfServiceGroupMemberOfPCPartitionConfig
#define Sd_GetSizeOfServiceGroupOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfServiceGroupOfPCPartitionConfig
#define Sd_GetSizeOfSoConActivationMapOfPCPartitionConfig(partitionIndex)                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConActivationMapOfPCPartitionConfig
#define Sd_GetSizeOfSoConGrpDynOfPCPartitionConfig(partitionIndex)                                  Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConGrpDynOfPCPartitionConfig
#define Sd_GetSizeOfSoConModeDynOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConModeDynOfPCPartitionConfig
#define Sd_GetSizeOfSoConModeIdMapOfPCPartitionConfig()                                             Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfSoConModeIdMapOfPCPartitionConfig
#define Sd_GetSizeOfTcpSoConIdOfPCPartitionConfig(partitionIndex)                                   Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTcpSoConIdOfPCPartitionConfig
#define Sd_GetSizeOfTriggerTransmitDynOfPCPartitionConfig(partitionIndex)                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTriggerTransmitDynOfPCPartitionConfig
#define Sd_GetSizeOfTxSoConIdMapOfPCPartitionConfig()                                               Sd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfTxSoConIdMapOfPCPartitionConfig
#define Sd_GetSizeOfUdpSoConOfPCPartitionConfig(partitionIndex)                                     Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfUdpSoConOfPCPartitionConfig
#define Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConActivationMapOfPCPartitionConfig
#define Sd_GetSoConGrpDynOfPCPartitionConfig(partitionIndex)                                        Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConGrpDynOfPCPartitionConfig
#define Sd_GetSoConModeDynOfPCPartitionConfig(partitionIndex)                                       Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConModeDynOfPCPartitionConfig
#define Sd_GetSoConModeIdMapOfPCPartitionConfig()                                                   Sd_GetPCPartitionConfigOfPCConfig()[(0)].SoConModeIdMapOfPCPartitionConfig
#define Sd_GetTcpSoConIdOfPCPartitionConfig(partitionIndex)                                         Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TcpSoConIdOfPCPartitionConfig
#define Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex)                                 Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TriggerTransmitDynOfPCPartitionConfig
#define Sd_GetTxSoConIdMapOfPCPartitionConfig()                                                     Sd_GetPCPartitionConfigOfPCConfig()[(0)].TxSoConIdMapOfPCPartitionConfig
#define Sd_GetUdpSoConOfPCPartitionConfig(partitionIndex)                                           Sd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].UdpSoConOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGetConstantDuplicatedRootDataMacros  Sd Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Sd_GetMaxNrOptionsPerEntryOfPCPartitionConfig(partitionIndex)                               10u
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGetDuplicatedRootDataMacros  Sd Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Sd_GetSizeOfClientDynOfPCPartitionConfig(partitionIndex)                                    Sd_GetSizeOfClientOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_ClientDyn */
#define Sd_GetSizeOfConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)                        Sd_GetSizeOfConsumedEventgroupOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_ConsumedEventgroupDyn */
#define Sd_GetSizeOfEventHandlerDynOfPCPartitionConfig(partitionIndex)                              Sd_GetSizeOfEventHandlerOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_EventHandlerDyn */
#define Sd_GetSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)                                  Sd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_InstanceDyn */
#define Sd_GetSizeOfRoutingGroupDynOfPCPartitionConfig(partitionIndex)                              Sd_GetSizeOfRoutingGroupOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_RoutingGroupDyn */
#define Sd_GetSizeOfServerDynOfPCPartitionConfig(partitionIndex)                                    Sd_GetSizeOfServerOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in Sd_ServerDyn */
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGetDataMacros  Sd Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Sd_GetAddrOfAclIPv4(Index, partitionIndex)                                                  (Sd_GetAclIPv4OfPCPartitionConfig(partitionIndex)[(Index)].AddrOfAclIPv4)
#define Sd_GetAclIPv4CInd(Index, partitionIndex)                                                    (Sd_GetAclIPv4CIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetAclIPv4SInd(Index, partitionIndex)                                                    (Sd_GetAclIPv4SIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetAddrOfAclIPv6(Index, partitionIndex)                                                  (Sd_GetAclIPv6OfPCPartitionConfig(partitionIndex)[(Index)].AddrOfAclIPv6)
#define Sd_GetAclIPv6CInd(Index, partitionIndex)                                                    (Sd_GetAclIPv6CIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetAclIPv6SInd(Index, partitionIndex)                                                    (Sd_GetAclIPv6SIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetAddrOfAddressStorage(Index, partitionIndex)                                           (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].AddrOfAddressStorage)
#define Sd_GetFlagsOfAddressStorage(Index, partitionIndex)                                          (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].FlagsOfAddressStorage)
#define Sd_IsRebootDetectedOfAddressStorage(Index, partitionIndex)                                  ((Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RebootDetectedOfAddressStorage) != FALSE)
#define Sd_GetRxMulticastFlagsOfAddressStorage(Index, partitionIndex)                               (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxMulticastFlagsOfAddressStorage)
#define Sd_GetRxMulticastSessionIdOfAddressStorage(Index, partitionIndex)                           (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxMulticastSessionIdOfAddressStorage)
#define Sd_GetRxUnicastFlagsOfAddressStorage(Index, partitionIndex)                                 (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxUnicastFlagsOfAddressStorage)
#define Sd_GetRxUnicastSessionIdOfAddressStorage(Index, partitionIndex)                             (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxUnicastSessionIdOfAddressStorage)
#define Sd_GetSendEntryHeadIdxOfAddressStorage(Index, partitionIndex)                               (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryHeadIdxOfAddressStorage)
#define Sd_GetSendEntryNrPendingIdxOfAddressStorage(Index, partitionIndex)                          (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNrPendingIdxOfAddressStorage)
#define Sd_GetSendEntryTailIdxOfAddressStorage(Index, partitionIndex)                               (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryTailIdxOfAddressStorage)
#define Sd_GetSessionIdCounterOfAddressStorage(Index, partitionIndex)                               (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SessionIdCounterOfAddressStorage)
#define Sd_GetTimeToSendOfAddressStorage(Index, partitionIndex)                                     (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].TimeToSendOfAddressStorage)
#define Sd_GetCapabilityRecord(Index)                                                               (Sd_GetCapabilityRecordOfPCPartitionConfig()[(Index)])
#define Sd_GetCapabilityRecordFunctionCalloutPtr(Index)                                             (Sd_GetCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()[(Index)])
#define Sd_GetAclIPv4CIndEndIdxOfClient(Index, partitionIndex)                                      (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv4CIndEndIdxOfClient)
#define Sd_GetAclIPv4CIndStartIdxOfClient(Index, partitionIndex)                                    (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv4CIndStartIdxOfClient)
#define Sd_GetAclIPv6CIndEndIdxOfClient(Index, partitionIndex)                                      (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv6CIndEndIdxOfClient)
#define Sd_GetAclIPv6CIndStartIdxOfClient(Index, partitionIndex)                                    (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv6CIndStartIdxOfClient)
#define Sd_IsAutoRequireOfClient(Index, partitionIndex)                                             ((Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].AutoRequireOfClient) != FALSE)
#define Sd_GetCapabilityRecordEndIdxOfClient(Index, partitionIndex)                                 (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordEndIdxOfClient)
#define Sd_GetCapabilityRecordFunctionCalloutPtrIdxOfClient(Index, partitionIndex)                  (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordFunctionCalloutPtrIdxOfClient)
#define Sd_GetCapabilityRecordStartIdxOfClient(Index, partitionIndex)                               (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordStartIdxOfClient)
#define Sd_GetClientTimerIdxOfClient(Index, partitionIndex)                                         (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].ClientTimerIdxOfClient)
#define Sd_GetCommonInitialDelayIdxOfClient(Index, partitionIndex)                                  (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].CommonInitialDelayIdxOfClient)
#define Sd_GetConsumedEventgroupEndIdxOfClient(Index, partitionIndex)                               (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].ConsumedEventgroupEndIdxOfClient)
#define Sd_GetConsumedEventgroupStartIdxOfClient(Index, partitionIndex)                             (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].ConsumedEventgroupStartIdxOfClient)
#define Sd_GetFindBehaviorOfClient(Index, partitionIndex)                                           (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].FindBehaviorOfClient)
#define Sd_GetHandleIdOfClient(Index, partitionIndex)                                               (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].HandleIdOfClient)
#define Sd_GetInitialInstanceIdOfClient(Index, partitionIndex)                                      (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].InitialInstanceIdOfClient)
#define Sd_GetInstanceIdxOfClient(Index, partitionIndex)                                            (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdxOfClient)
#define Sd_GetMajorVersionOfClient(Index, partitionIndex)                                           (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].MajorVersionOfClient)
#define Sd_GetMethodIdxOfClient(Index, partitionIndex)                                              (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].MethodIdxOfClient)
#define Sd_GetMinorVersionOfClient(Index, partitionIndex)                                           (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].MinorVersionOfClient)
#define Sd_IsMinorVersionWildcardOfClient(Index, partitionIndex)                                    ((Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].MinorVersionWildcardOfClient) != FALSE)
#define Sd_IsServiceGroupMemberOfClient(Index, partitionIndex)                                      ((Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupMemberOfClient) != FALSE)
#define Sd_GetServiceIdOfClient(Index, partitionIndex)                                              (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].ServiceIdOfClient)
#define Sd_GetSoConGrpDynTcpIdxOfClient(Index, partitionIndex)                                      (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpDynTcpIdxOfClient)
#define Sd_GetSoConGrpDynUdpIdxOfClient(Index, partitionIndex)                                      (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpDynUdpIdxOfClient)
#define Sd_GetTcpSoConIdEndIdxOfClient(Index, partitionIndex)                                       (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdEndIdxOfClient)
#define Sd_GetTcpSoConIdStartIdxOfClient(Index, partitionIndex)                                     (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdStartIdxOfClient)
#define Sd_IsUdpClientMulticastOfClient(Index, partitionIndex)                                      ((Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].UdpClientMulticastOfClient) != FALSE)
#define Sd_GetUdpSoConEndIdxOfClient(Index, partitionIndex)                                         (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConEndIdxOfClient)
#define Sd_GetUdpSoConStartIdxOfClient(Index, partitionIndex)                                       (Sd_GetClientOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConStartIdxOfClient)
#define Sd_GetAddressStorageCurrentServerIdxOfClientDyn(Index, partitionIndex)                      (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageCurrentServerIdxOfClientDyn)
#define Sd_GetAddressStorageServerIdxOfClientDyn(Index, partitionIndex)                             (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageServerIdxOfClientDyn)
#define Sd_GetCurrentStateOfClientDyn(Index, partitionIndex)                                        (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].CurrentStateOfClientDyn)
#define Sd_GetEventMainOfClientDyn(Index, partitionIndex)                                           (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].EventMainOfClientDyn)
#define Sd_GetEventRxOfClientDyn(Index, partitionIndex)                                             (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].EventRxOfClientDyn)
#define Sd_GetInstanceIdOfClientDyn(Index, partitionIndex)                                          (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfClientDyn)
#define Sd_GetMethodTcpSoConIdOfClientDyn(Index, partitionIndex)                                    (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].MethodTcpSoConIdOfClientDyn)
#define Sd_GetMethodUdpSoConIdOfClientDyn(Index, partitionIndex)                                    (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].MethodUdpSoConIdOfClientDyn)
#define Sd_GetOfferedTTLOfClientDyn(Index, partitionIndex)                                          (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].OfferedTTLOfClientDyn)
#define Sd_GetRepetitionRunOfClientDyn(Index, partitionIndex)                                       (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RepetitionRunOfClientDyn)
#define Sd_GetRetryCounterOfClientDyn(Index, partitionIndex)                                        (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryCounterOfClientDyn)
#define Sd_GetRetryTimerOfClientDyn(Index, partitionIndex)                                          (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryTimerOfClientDyn)
#define Sd_GetServerTcpEndpointAddrOfClientDyn(Index, partitionIndex)                               (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServerTcpEndpointAddrOfClientDyn)
#define Sd_GetServerUdpEndpointAddrOfClientDyn(Index, partitionIndex)                               (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServerUdpEndpointAddrOfClientDyn)
#define Sd_GetServiceGroupReqCounterOfClientDyn(Index, partitionIndex)                              (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupReqCounterOfClientDyn)
#define Sd_IsStateMachineExecutionRequestedOfClientDyn(Index, partitionIndex)                       ((Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineExecutionRequestedOfClientDyn) != FALSE)
#define Sd_GetStateMachineOfClientDyn(Index, partitionIndex)                                        (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfClientDyn)
#define Sd_GetStateSwcOfClientDyn(Index, partitionIndex)                                            (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateSwcOfClientDyn)
#define Sd_GetTimeToTriggerSendOfClientDyn(Index, partitionIndex)                                   (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeToTriggerSendOfClientDyn)
#define Sd_GetTimerTTLOfClientDyn(Index, partitionIndex)                                            (Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].TimerTTLOfClientDyn)
#define Sd_IsInvalidHndOfClientIdMap(Index)                                                         ((Sd_GetClientIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfClientIdMap) != FALSE)
#define Sd_GetPartitionSpecificClientIdxOfClientIdMap(Index)                                        (Sd_GetClientIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificClientIdxOfClientIdMap)
#define Sd_GetPartitionSpecificClientPartitionIdxOfClientIdMap(Index)                               (Sd_GetClientIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificClientPartitionIdxOfClientIdMap)
#define Sd_GetAddressStorageIdxOfClientList(Index, partitionIndex)                                  (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageIdxOfClientList)
#define Sd_GetAssignedTcpSoConIdOfClientList(Index, partitionIndex)                                 (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AssignedTcpSoConIdOfClientList)
#define Sd_GetAssignedUdpSoConIdOfClientList(Index, partitionIndex)                                 (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AssignedUdpSoConIdOfClientList)
#define Sd_GetClientStateOfClientList(Index, partitionIndex)                                        (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].ClientStateOfClientList)
#define Sd_GetEndpointStorageTcpIdxOfClientList(Index, partitionIndex)                              (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageTcpIdxOfClientList)
#define Sd_GetEndpointStorageUdpIdxOfClientList(Index, partitionIndex)                              (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageUdpIdxOfClientList)
#define Sd_GetNrOfReferencesOfClientList(Index, partitionIndex)                                     (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].NrOfReferencesOfClientList)
#define Sd_GetRequestedTTLOfClientList(Index, partitionIndex)                                       (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].RequestedTTLOfClientList)
#define Sd_GetRxReservedOfClientList(Index, partitionIndex)                                         (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].RxReservedOfClientList)
#define Sd_GetSubscribedUntilOfClientList(Index, partitionIndex)                                    (Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].SubscribedUntilOfClientList)
#define Sd_GetInitialFindDelayMaxOfClientTimer(Index, partitionIndex)                               (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialFindDelayMaxOfClientTimer)
#define Sd_GetInitialFindDelayMinOfClientTimer(Index, partitionIndex)                               (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialFindDelayMinOfClientTimer)
#define Sd_GetInitialFindRepetitionBaseDelayOfClientTimer(Index, partitionIndex)                    (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialFindRepetitionBaseDelayOfClientTimer)
#define Sd_GetInitialFindRepetitionsMaxOfClientTimer(Index, partitionIndex)                         (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialFindRepetitionsMaxOfClientTimer)
#define Sd_GetRequestResponseMaxDelayOfClientTimer(Index, partitionIndex)                           (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].RequestResponseMaxDelayOfClientTimer)
#define Sd_GetRequestResponseMinDelayOfClientTimer(Index, partitionIndex)                           (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].RequestResponseMinDelayOfClientTimer)
#define Sd_GetTTLOfClientTimer(Index, partitionIndex)                                               (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex)[(Index)].TTLOfClientTimer)
#define Sd_GetCommonInitialDelay(Index, partitionIndex)                                             (Sd_GetCommonInitialDelayOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_IsAutoRequireOfConsumedEventgroup(Index, partitionIndex)                                 ((Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].AutoRequireOfConsumedEventgroup) != FALSE)
#define Sd_GetClientIdxOfConsumedEventgroup(Index, partitionIndex)                                  (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].ClientIdxOfConsumedEventgroup)
#define Sd_GetClientTimerIdxOfConsumedEventgroup(Index, partitionIndex)                             (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].ClientTimerIdxOfConsumedEventgroup)
#define Sd_GetEventGroupIdOfConsumedEventgroup(Index, partitionIndex)                               (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].EventGroupIdOfConsumedEventgroup)
#define Sd_GetHandleIdOfConsumedEventgroup(Index, partitionIndex)                                   (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].HandleIdOfConsumedEventgroup)
#define Sd_GetMulticastEndpointAddrIdxOfConsumedEventgroup(Index, partitionIndex)                   (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].MulticastEndpointAddrIdxOfConsumedEventgroup)
#define Sd_GetMulticastSoConIdEndIdxOfConsumedEventgroup(Index, partitionIndex)                     (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].MulticastSoConIdEndIdxOfConsumedEventgroup)
#define Sd_GetMulticastSoConIdStartIdxOfConsumedEventgroup(Index, partitionIndex)                   (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].MulticastSoConIdStartIdxOfConsumedEventgroup)
#define Sd_GetRoutingGroupMulticastActRefIdxOfConsumedEventgroup(Index, partitionIndex)             (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupMulticastActRefIdxOfConsumedEventgroup)
#define Sd_GetRoutingGroupTcpActRefIdxOfConsumedEventgroup(Index, partitionIndex)                   (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupTcpActRefIdxOfConsumedEventgroup)
#define Sd_GetRoutingGroupUdpActRefIdxOfConsumedEventgroup(Index, partitionIndex)                   (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupUdpActRefIdxOfConsumedEventgroup)
#define Sd_GetAcknowledgedTTLOfConsumedEventgroupDyn(Index, partitionIndex)                         (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].AcknowledgedTTLOfConsumedEventgroupDyn)
#define Sd_GetCurrentStateOfConsumedEventgroupDyn(Index, partitionIndex)                            (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].CurrentStateOfConsumedEventgroupDyn)
#define Sd_GetEventOfConsumedEventgroupDyn(Index, partitionIndex)                                   (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].EventOfConsumedEventgroupDyn)
#define Sd_GetMulticastSoConIdOfConsumedEventgroupDyn(Index, partitionIndex)                        (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].MulticastSoConIdOfConsumedEventgroupDyn)
#define Sd_GetRxIndicationCountOfConsumedEventgroupDyn(Index, partitionIndex)                       (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].RxIndicationCountOfConsumedEventgroupDyn)
#define Sd_GetServiceModeRequestOfConsumedEventgroupDyn(Index, partitionIndex)                      (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceModeRequestOfConsumedEventgroupDyn)
#define Sd_GetStateMachineOfConsumedEventgroupDyn(Index, partitionIndex)                            (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfConsumedEventgroupDyn)
#define Sd_GetTcpSoConIdOfConsumedEventgroupDyn(Index, partitionIndex)                              (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdOfConsumedEventgroupDyn)
#define Sd_GetTimerTTLOfConsumedEventgroupDyn(Index, partitionIndex)                                (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TimerTTLOfConsumedEventgroupDyn)
#define Sd_IsTriggerSubscriptionOfConsumedEventgroupDyn(Index, partitionIndex)                      ((Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerSubscriptionOfConsumedEventgroupDyn) != FALSE)
#define Sd_GetUdpSoConIdOfConsumedEventgroupDyn(Index, partitionIndex)                              (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConIdOfConsumedEventgroupDyn)
#define Sd_IsInvalidHndOfConsumedEventgroupIdMap(Index)                                             ((Sd_GetConsumedEventgroupIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfConsumedEventgroupIdMap) != FALSE)
#define Sd_GetPartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap(Index)                (Sd_GetConsumedEventgroupIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap)
#define Sd_GetPartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMap(Index)       (Sd_GetConsumedEventgroupIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMap)
#define Sd_GetAddrOfEndpointStorage(Index, partitionIndex)                                          (Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].AddrOfEndpointStorage)
#define Sd_GetNrOfReferencesOfEndpointStorage(Index, partitionIndex)                                (Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].NrOfReferencesOfEndpointStorage)
#define Sd_GetTypeOfEndpointStorage(Index, partitionIndex)                                          (Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].TypeOfEndpointStorage)
#define Sd_GetClientListEndIdxOfEventHandler(Index, partitionIndex)                                 (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].ClientListEndIdxOfEventHandler)
#define Sd_GetClientListStartIdxOfEventHandler(Index, partitionIndex)                               (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].ClientListStartIdxOfEventHandler)
#define Sd_GetEventGroupIdOfEventHandler(Index, partitionIndex)                                     (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].EventGroupIdOfEventHandler)
#define Sd_GetEventHandlerMulticastIdxOfEventHandler(Index, partitionIndex)                         (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerMulticastIdxOfEventHandler)
#define Sd_GetEventHandlerTcpIdxOfEventHandler(Index, partitionIndex)                               (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerTcpIdxOfEventHandler)
#define Sd_GetEventHandlerUdpIdxOfEventHandler(Index, partitionIndex)                               (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerUdpIdxOfEventHandler)
#define Sd_GetHandleIdOfEventHandler(Index, partitionIndex)                                         (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].HandleIdOfEventHandler)
#define Sd_GetMulticastThresholdOfEventHandler(Index, partitionIndex)                               (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].MulticastThresholdOfEventHandler)
#define Sd_GetServerIdxOfEventHandler(Index, partitionIndex)                                        (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].ServerIdxOfEventHandler)
#define Sd_GetServerTimerIdxOfEventHandler(Index, partitionIndex)                                   (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].ServerTimerIdxOfEventHandler)
#define Sd_GetSoConActivationMapEndIdxOfEventHandler(Index, partitionIndex)                         (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].SoConActivationMapEndIdxOfEventHandler)
#define Sd_GetSoConActivationMapStartIdxOfEventHandler(Index, partitionIndex)                       (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex)[(Index)].SoConActivationMapStartIdxOfEventHandler)
#define Sd_GetNrOfClientsOfEventHandlerDyn(Index, partitionIndex)                                   (Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].NrOfClientsOfEventHandlerDyn)
#define Sd_GetRequestStateOfEventHandlerDyn(Index, partitionIndex)                                  (Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].RequestStateOfEventHandlerDyn)
#define Sd_GetStateMachineOfEventHandlerDyn(Index, partitionIndex)                                  (Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfEventHandlerDyn)
#define Sd_GetRoutingGroupActRefIdxOfEventHandlerMulticast(Index, partitionIndex)                   (Sd_GetEventHandlerMulticastOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupActRefIdxOfEventHandlerMulticast)
#define Sd_GetSoConIdOfEventHandlerMulticast(Index, partitionIndex)                                 (Sd_GetEventHandlerMulticastOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdOfEventHandlerMulticast)
#define Sd_GetRoutingGroupActRefIdxOfEventHandlerTcp(Index, partitionIndex)                         (Sd_GetEventHandlerTcpOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupActRefIdxOfEventHandlerTcp)
#define Sd_GetRoutingGroupTriggerIdxOfEventHandlerTcp(Index, partitionIndex)                        (Sd_GetEventHandlerTcpOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupTriggerIdxOfEventHandlerTcp)
#define Sd_GetRoutingGroupActRefIdxOfEventHandlerUdp(Index, partitionIndex)                         (Sd_GetEventHandlerUdpOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupActRefIdxOfEventHandlerUdp)
#define Sd_GetRoutingGroupTriggerIdxOfEventHandlerUdp(Index, partitionIndex)                        (Sd_GetEventHandlerUdpOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupTriggerIdxOfEventHandlerUdp)
#define Sd_GetAddressStorageEndIdxOfInstance(Index, partitionIndex)                                 (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageEndIdxOfInstance)
#define Sd_GetAddressStorageStartIdxOfInstance(Index, partitionIndex)                               (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageStartIdxOfInstance)
#define Sd_GetCapabilityRecordEndIdxOfInstance(Index, partitionIndex)                               (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordEndIdxOfInstance)
#define Sd_GetCapabilityRecordStartIdxOfInstance(Index, partitionIndex)                             (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordStartIdxOfInstance)
#define Sd_GetClientEndIdxOfInstance(Index, partitionIndex)                                         (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].ClientEndIdxOfInstance)
#define Sd_GetClientStartIdxOfInstance(Index, partitionIndex)                                       (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].ClientStartIdxOfInstance)
#define Sd_GetEMalformedMsgIdOfInstance(Index, partitionIndex)                                      (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EMalformedMsgIdOfInstance)
#define Sd_GetENackRecvIdOfInstance(Index, partitionIndex)                                          (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].ENackRecvIdOfInstance)
#define Sd_GetEOutOfResIdOfInstance(Index, partitionIndex)                                          (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EOutOfResIdOfInstance)
#define Sd_GetEndpointStorageEndIdxOfInstance(Index, partitionIndex)                                (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageEndIdxOfInstance)
#define Sd_GetEndpointStorageStartIdxOfInstance(Index, partitionIndex)                              (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageStartIdxOfInstance)
#define Sd_GetEventHandlerEndIdxOfInstance(Index, partitionIndex)                                   (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerEndIdxOfInstance)
#define Sd_GetEventHandlerStartIdxOfInstance(Index, partitionIndex)                                 (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerStartIdxOfInstance)
#define Sd_GetLocalAddressCheckLengthOfInstance(Index, partitionIndex)                              (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].LocalAddressCheckLengthOfInstance)
#define Sd_GetMulticastRxPduIdOfInstance(Index, partitionIndex)                                     (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].MulticastRxPduIdOfInstance)
#define Sd_GetMulticastRxSoConIdOfInstance(Index, partitionIndex)                                   (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].MulticastRxSoConIdOfInstance)
#define Sd_GetQueueProcessLimitOfInstance(Index, partitionIndex)                                    (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].QueueProcessLimitOfInstance)
#define Sd_GetRetryDelayOfInstance(Index, partitionIndex)                                           (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].RetryDelayOfInstance)
#define Sd_GetRetryMaxOfInstance(Index, partitionIndex)                                             (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].RetryMaxOfInstance)
#define Sd_GetRxEventEndIdxOfInstance(Index, partitionIndex)                                        (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].RxEventEndIdxOfInstance)
#define Sd_GetRxEventStartIdxOfInstance(Index, partitionIndex)                                      (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].RxEventStartIdxOfInstance)
#define Sd_GetSendEntryCapacityOfInstance(Index, partitionIndex)                                    (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryCapacityOfInstance)
#define Sd_GetSendEntryEndIdxOfInstance(Index, partitionIndex)                                      (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryEndIdxOfInstance)
#define Sd_GetSendEntryStartIdxOfInstance(Index, partitionIndex)                                    (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryStartIdxOfInstance)
#define Sd_GetServerEndIdxOfInstance(Index, partitionIndex)                                         (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].ServerEndIdxOfInstance)
#define Sd_GetServerStartIdxOfInstance(Index, partitionIndex)                                       (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].ServerStartIdxOfInstance)
#define Sd_GetSevDuplicateOfferOfInstance(Index, partitionIndex)                                    (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SevDuplicateOfferOfInstance)
#define Sd_GetSevFailedMethodReqOfInstance(Index, partitionIndex)                                   (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SevFailedMethodReqOfInstance)
#define Sd_GetSevFailedOfferOfInstance(Index, partitionIndex)                                       (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SevFailedOfferOfInstance)
#define Sd_GetSevFailedSubOfInstance(Index, partitionIndex)                                         (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].SevFailedSubOfInstance)
#define Sd_GetTcpSoConIdEndIdxOfInstance(Index, partitionIndex)                                     (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdEndIdxOfInstance)
#define Sd_GetTcpSoConIdStartIdxOfInstance(Index, partitionIndex)                                   (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdStartIdxOfInstance)
#define Sd_GetTxPduIdOfInstance(Index, partitionIndex)                                              (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TxPduIdOfInstance)
#define Sd_GetTxSoConIdOfInstance(Index, partitionIndex)                                            (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TxSoConIdOfInstance)
#define Sd_GetUdpSoConEndIdxOfInstance(Index, partitionIndex)                                       (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConEndIdxOfInstance)
#define Sd_GetUdpSoConStartIdxOfInstance(Index, partitionIndex)                                     (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConStartIdxOfInstance)
#define Sd_GetUnicastRxPduIdOfInstance(Index, partitionIndex)                                       (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].UnicastRxPduIdOfInstance)
#define Sd_GetUnicastRxSoConIdOfInstance(Index, partitionIndex)                                     (Sd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].UnicastRxSoConIdOfInstance)
#define Sd_GetLastFoundEndpointOfInstanceDyn(Index, partitionIndex)                                 (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].LastFoundEndpointOfInstanceDyn)
#define Sd_GetNextStateMachineRunOfInstanceDyn(Index, partitionIndex)                               (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].NextStateMachineRunOfInstanceDyn)
#define Sd_GetRunModeOfInstanceDyn(Index, partitionIndex)                                           (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RunModeOfInstanceDyn)
#define Sd_GetRxEventEndIdxOfInstanceDyn(Index, partitionIndex)                                     (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventEndIdxOfInstanceDyn)
#define Sd_IsRxEventListFullOfInstanceDyn(Index, partitionIndex)                                    ((Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventListFullOfInstanceDyn) != FALSE)
#define Sd_GetRxEventStartIdxOfInstanceDyn(Index, partitionIndex)                                   (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventStartIdxOfInstanceDyn)
#define Sd_GetSendEntryFreeListHeadIdxOfInstanceDyn(Index, partitionIndex)                          (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryFreeListHeadIdxOfInstanceDyn)
#define Sd_GetSendEntryFreeListTailIdxOfInstanceDyn(Index, partitionIndex)                          (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryFreeListTailIdxOfInstanceDyn)
#define Sd_GetSendEntryNrPendingIdxOfInstanceDyn(Index, partitionIndex)                             (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNrPendingIdxOfInstanceDyn)
#define Sd_GetStateOfInstanceDyn(Index, partitionIndex)                                             (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].StateOfInstanceDyn)
#define Sd_GetPortSetIdxOfIpAddrRequest(Index, partitionIndex)                                      (Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)[(Index)].PortSetIdxOfIpAddrRequest)
#define Sd_GetRequestCntIdxOfIpAddrRequest(Index, partitionIndex)                                   (Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)[(Index)].RequestCntIdxOfIpAddrRequest)
#define Sd_GetSoConIdOfIpAddrRequest(Index, partitionIndex)                                         (Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdOfIpAddrRequest)
#define Sd_IsStaticIpConfigurationOfIpAddrRequest(Index, partitionIndex)                            ((Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)[(Index)].StaticIpConfigurationOfIpAddrRequest) != FALSE)
#define Sd_IsStaticPortConfigurationOfIpAddrRequest(Index, partitionIndex)                          ((Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex)[(Index)].StaticPortConfigurationOfIpAddrRequest) != FALSE)
#define Sd_GetRoutingGroupActRefIdxOfMethod(Index, partitionIndex)                                  (Sd_GetMethodOfPCPartitionConfig(partitionIndex)[(Index)].RoutingGroupActRefIdxOfMethod)
#define Sd_IsTcpConfiguredOfMethod(Index, partitionIndex)                                           ((Sd_GetMethodOfPCPartitionConfig(partitionIndex)[(Index)].TcpConfiguredOfMethod) != FALSE)
#define Sd_IsUdpConfiguredOfMethod(Index, partitionIndex)                                           ((Sd_GetMethodOfPCPartitionConfig(partitionIndex)[(Index)].UdpConfiguredOfMethod) != FALSE)
#define Sd_GetMulticastEndpointAddr(Index, partitionIndex)                                          (Sd_GetMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetMulticastSoConId(Index, partitionIndex)                                               (Sd_GetMulticastSoConIdOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetOptionIndex(Index, partitionIndex)                                                    (Sd_GetOptionIndexOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetInitializedOfPartitionDataDyn(Index, partitionIndex)                                  (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].InitializedOfPartitionDataDyn)
#define Sd_GetNrOfOptionsOfPartitionDataDyn(Index, partitionIndex)                                  (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].NrOfOptionsOfPartitionDataDyn)
#define Sd_GetRxIndicationCountOfPartitionDataDyn(Index, partitionIndex)                            (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].RxIndicationCountOfPartitionDataDyn)
#define Sd_GetTimeMsSinceStartOfPartitionDataDyn(Index, partitionIndex)                             (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeMsSinceStartOfPartitionDataDyn)
#define Sd_GetTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, partitionIndex)                     (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitDynEndIdxOfPartitionDataDyn)
#define Sd_GetTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, partitionIndex)                   (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitDynStartIdxOfPartitionDataDyn)
#define Sd_IsTriggerTransmitFullOfPartitionDataDyn(Index, partitionIndex)                           ((Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitFullOfPartitionDataDyn) != FALSE)
#define Sd_IsTxPathLockedOfPartitionDataDyn(Index, partitionIndex)                                  ((Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TxPathLockedOfPartitionDataDyn) != FALSE)
#define Sd_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                     (Sd_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define Sd_GetPartitionSNVOfPartitionIdentifiers(Index)                                             (Sd_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define Sd_GetPayload(Index, partitionIndex)                                                        (Sd_GetPayloadOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_IsPortSet(Index, partitionIndex)                                                         ((Sd_GetPortSetOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define Sd_GetRequestCnt(Index, partitionIndex)                                                     (Sd_GetRequestCntOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetRoutingGroup(Index, partitionIndex)                                                   (Sd_GetRoutingGroupOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetStatusOfRoutingGroupDyn(Index, partitionIndex)                                        (Sd_GetRoutingGroupDynOfPCPartitionConfig(partitionIndex)[(Index)].StatusOfRoutingGroupDyn)
#define Sd_IsInvalidHndOfRoutingGroupIdMap(Index)                                                   ((Sd_GetRoutingGroupIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfRoutingGroupIdMap) != FALSE)
#define Sd_GetServerIdxOfRoutingGroupIdMap(Index)                                                   (Sd_GetRoutingGroupIdMapOfPCPartitionConfig()[(Index)].ServerIdxOfRoutingGroupIdMap)
#define Sd_GetServerPartitionIdxOfRoutingGroupIdMap(Index)                                          (Sd_GetRoutingGroupIdMapOfPCPartitionConfig()[(Index)].ServerPartitionIdxOfRoutingGroupIdMap)
#define Sd_GetClientListIdxOfRxEvent(Index, partitionIndex)                                         (Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfRxEvent)
#define Sd_GetEventHandlerIdxOfRxEvent(Index, partitionIndex)                                       (Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfRxEvent)
#define Sd_GetEventOfRxEvent(Index, partitionIndex)                                                 (Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].EventOfRxEvent)
#define Sd_IsInvalidHndOfRxPduIdMap(Index)                                                          ((Sd_GetRxPduIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfRxPduIdMap) != FALSE)
#define Sd_GetPartitionSpecificInstanceIdxOfRxPduIdMap(Index)                                       (Sd_GetRxPduIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstanceIdxOfRxPduIdMap)
#define Sd_GetPartitionSpecificInstancePartitionIdxOfRxPduIdMap(Index)                              (Sd_GetRxPduIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstancePartitionIdxOfRxPduIdMap)
#define Sd_GetClientIdxOfSendEntry(Index, partitionIndex)                                           (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ClientIdxOfSendEntry)
#define Sd_GetClientListIdxOfSendEntry(Index, partitionIndex)                                       (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfSendEntry)
#define Sd_GetConsumedEventgroupIdxOfSendEntry(Index, partitionIndex)                               (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ConsumedEventgroupIdxOfSendEntry)
#define Sd_GetEntryTypeOfSendEntry(Index, partitionIndex)                                           (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EntryTypeOfSendEntry)
#define Sd_GetEventHandlerIdOfSendEntry(Index, partitionIndex)                                      (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdOfSendEntry)
#define Sd_GetEventHandlerIdxOfSendEntry(Index, partitionIndex)                                     (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfSendEntry)
#define Sd_GetInstanceIdOfSendEntry(Index, partitionIndex)                                          (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfSendEntry)
#define Sd_GetInstanceIdxOfSendEntry(Index, partitionIndex)                                         (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdxOfSendEntry)
#define Sd_GetMajorVersionOfSendEntry(Index, partitionIndex)                                        (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].MajorVersionOfSendEntry)
#define Sd_GetReservedFieldOfSendEntry(Index, partitionIndex)                                       (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ReservedFieldOfSendEntry)
#define Sd_GetSendEntryNextIdxOfSendEntry(Index, partitionIndex)                                    (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNextIdxOfSendEntry)
#define Sd_GetSendEntryPrevIdxOfSendEntry(Index, partitionIndex)                                    (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryPrevIdxOfSendEntry)
#define Sd_GetServerIdxOfSendEntry(Index, partitionIndex)                                           (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ServerIdxOfSendEntry)
#define Sd_GetServiceIdOfSendEntry(Index, partitionIndex)                                           (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ServiceIdOfSendEntry)
#define Sd_GetAclIPv4SIndEndIdxOfServer(Index, partitionIndex)                                      (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv4SIndEndIdxOfServer)
#define Sd_GetAclIPv4SIndStartIdxOfServer(Index, partitionIndex)                                    (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv4SIndStartIdxOfServer)
#define Sd_GetAclIPv6SIndEndIdxOfServer(Index, partitionIndex)                                      (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv6SIndEndIdxOfServer)
#define Sd_GetAclIPv6SIndStartIdxOfServer(Index, partitionIndex)                                    (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].AclIPv6SIndStartIdxOfServer)
#define Sd_IsAutoAvailableOfServer(Index, partitionIndex)                                           ((Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].AutoAvailableOfServer) != FALSE)
#define Sd_GetCapabilityRecordEndIdxOfServer(Index, partitionIndex)                                 (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordEndIdxOfServer)
#define Sd_GetCapabilityRecordFunctionCalloutPtrIdxOfServer(Index, partitionIndex)                  (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordFunctionCalloutPtrIdxOfServer)
#define Sd_GetCapabilityRecordStartIdxOfServer(Index, partitionIndex)                               (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].CapabilityRecordStartIdxOfServer)
#define Sd_GetCommonInitialDelayIdxOfServer(Index, partitionIndex)                                  (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].CommonInitialDelayIdxOfServer)
#define Sd_GetEventHandlerEndIdxOfServer(Index, partitionIndex)                                     (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerEndIdxOfServer)
#define Sd_GetEventHandlerStartIdxOfServer(Index, partitionIndex)                                   (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerStartIdxOfServer)
#define Sd_GetHandleIdOfServer(Index, partitionIndex)                                               (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].HandleIdOfServer)
#define Sd_GetInitialInstanceIdOfServer(Index, partitionIndex)                                      (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].InitialInstanceIdOfServer)
#define Sd_GetInstanceIdxOfServer(Index, partitionIndex)                                            (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdxOfServer)
#define Sd_GetMajorVersionOfServer(Index, partitionIndex)                                           (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].MajorVersionOfServer)
#define Sd_GetMethodIdxOfServer(Index, partitionIndex)                                              (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].MethodIdxOfServer)
#define Sd_GetMinorVersionOfServer(Index, partitionIndex)                                           (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].MinorVersionOfServer)
#define Sd_GetServerTimerIdxOfServer(Index, partitionIndex)                                         (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].ServerTimerIdxOfServer)
#define Sd_IsServiceGroupMemberOfServer(Index, partitionIndex)                                      ((Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupMemberOfServer) != FALSE)
#define Sd_GetServiceIdOfServer(Index, partitionIndex)                                              (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].ServiceIdOfServer)
#define Sd_GetSoConGrpDynTcpIdxOfServer(Index, partitionIndex)                                      (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpDynTcpIdxOfServer)
#define Sd_GetSoConGrpDynUdpIdxOfServer(Index, partitionIndex)                                      (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpDynUdpIdxOfServer)
#define Sd_GetTcpSoConIdEndIdxOfServer(Index, partitionIndex)                                       (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdEndIdxOfServer)
#define Sd_GetTcpSoConIdStartIdxOfServer(Index, partitionIndex)                                     (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdStartIdxOfServer)
#define Sd_GetUdpSoConEndIdxOfServer(Index, partitionIndex)                                         (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConEndIdxOfServer)
#define Sd_GetUdpSoConStartIdxOfServer(Index, partitionIndex)                                       (Sd_GetServerOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConStartIdxOfServer)
#define Sd_GetInitialOfferRepetitionRunOfServerDyn(Index, partitionIndex)                           (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferRepetitionRunOfServerDyn)
#define Sd_GetInstanceIdOfServerDyn(Index, partitionIndex)                                          (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfServerDyn)
#define Sd_GetServiceGroupReqCounterOfServerDyn(Index, partitionIndex)                              (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupReqCounterOfServerDyn)
#define Sd_IsStateMachineExecutionRequestedOfServerDyn(Index, partitionIndex)                       ((Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineExecutionRequestedOfServerDyn) != FALSE)
#define Sd_GetStateMachineOfServerDyn(Index, partitionIndex)                                        (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfServerDyn)
#define Sd_GetStateSwcOfServerDyn(Index, partitionIndex)                                            (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateSwcOfServerDyn)
#define Sd_GetTimeToTriggerSendOfServerDyn(Index, partitionIndex)                                   (Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeToTriggerSendOfServerDyn)
#define Sd_IsInvalidHndOfServerIdMap(Index)                                                         ((Sd_GetServerIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfServerIdMap) != FALSE)
#define Sd_GetPartitionSpecificServerIdxOfServerIdMap(Index)                                        (Sd_GetServerIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificServerIdxOfServerIdMap)
#define Sd_GetPartitionSpecificServerPartitionIdxOfServerIdMap(Index)                               (Sd_GetServerIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificServerPartitionIdxOfServerIdMap)
#define Sd_GetInitialOfferDelayMaxOfServerTimer(Index, partitionIndex)                              (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferDelayMaxOfServerTimer)
#define Sd_GetInitialOfferDelayMinOfServerTimer(Index, partitionIndex)                              (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferDelayMinOfServerTimer)
#define Sd_GetInitialOfferRepetitionBaseDelayOfServerTimer(Index, partitionIndex)                   (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferRepetitionBaseDelayOfServerTimer)
#define Sd_GetInitialOfferRepetitionsMaxOfServerTimer(Index, partitionIndex)                        (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferRepetitionsMaxOfServerTimer)
#define Sd_GetOfferCyclicDelayOfServerTimer(Index, partitionIndex)                                  (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].OfferCyclicDelayOfServerTimer)
#define Sd_GetRequestResponseMaxDelayOfServerTimer(Index, partitionIndex)                           (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].RequestResponseMaxDelayOfServerTimer)
#define Sd_GetRequestResponseMinDelayOfServerTimer(Index, partitionIndex)                           (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].RequestResponseMinDelayOfServerTimer)
#define Sd_GetTTLOfServerTimer(Index, partitionIndex)                                               (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex)[(Index)].TTLOfServerTimer)
#define Sd_GetServiceGroupMemberEndIdxOfServiceGroup(Index, partitionIndex)                         (Sd_GetServiceGroupOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupMemberEndIdxOfServiceGroup)
#define Sd_GetServiceGroupMemberStartIdxOfServiceGroup(Index, partitionIndex)                       (Sd_GetServiceGroupOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupMemberStartIdxOfServiceGroup)
#define Sd_IsInvalidHndOfServiceGroupIdMap(Index)                                                   ((Sd_GetServiceGroupIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfServiceGroupIdMap) != FALSE)
#define Sd_GetPartitionSpecificServiceGroupIdxOfServiceGroupIdMap(Index)                            (Sd_GetServiceGroupIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificServiceGroupIdxOfServiceGroupIdMap)
#define Sd_GetPartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMap(Index)                   (Sd_GetServiceGroupIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMap)
#define Sd_GetClientIdxOfServiceGroupMember(Index, partitionIndex)                                  (Sd_GetServiceGroupMemberOfPCPartitionConfig(partitionIndex)[(Index)].ClientIdxOfServiceGroupMember)
#define Sd_GetServerIdxOfServiceGroupMember(Index, partitionIndex)                                  (Sd_GetServiceGroupMemberOfPCPartitionConfig(partitionIndex)[(Index)].ServerIdxOfServiceGroupMember)
#define Sd_GetNrOfActivationsOfSoConActivationMap(Index, partitionIndex)                            (Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex)[(Index)].NrOfActivationsOfSoConActivationMap)
#define Sd_GetSoConIdOfSoConActivationMap(Index, partitionIndex)                                    (Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdOfSoConActivationMap)
#define Sd_GetLocalPortOfSoConGrpDyn(Index, partitionIndex)                                         (Sd_GetSoConGrpDynOfPCPartitionConfig(partitionIndex)[(Index)].LocalPortOfSoConGrpDyn)
#define Sd_GetSoConModeDyn(Index, partitionIndex)                                                   (Sd_GetSoConModeDynOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_IsInvalidHndOfSoConModeIdMap(Index)                                                      ((Sd_GetSoConModeIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfSoConModeIdMap) != FALSE)
#define Sd_GetPartitionSpecificSoConModeIdxOfSoConModeIdMap(Index)                                  (Sd_GetSoConModeIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificSoConModeIdxOfSoConModeIdMap)
#define Sd_GetPartitionSpecificSoConModePartitionIdxOfSoConModeIdMap(Index)                         (Sd_GetSoConModeIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificSoConModePartitionIdxOfSoConModeIdMap)
#define Sd_GetTcpSoConId(Index, partitionIndex)                                                     (Sd_GetTcpSoConIdOfPCPartitionConfig(partitionIndex)[(Index)])
#define Sd_GetClientListIdxOfTriggerTransmitDyn(Index, partitionIndex)                              (Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfTriggerTransmitDyn)
#define Sd_GetEventHandlerIdxOfTriggerTransmitDyn(Index, partitionIndex)                            (Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfTriggerTransmitDyn)
#define Sd_IsInvalidHndOfTxSoConIdMap(Index)                                                        ((Sd_GetTxSoConIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfTxSoConIdMap) != FALSE)
#define Sd_GetPartitionSpecificInstanceIdxOfTxSoConIdMap(Index)                                     (Sd_GetTxSoConIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstanceIdxOfTxSoConIdMap)
#define Sd_GetPartitionSpecificInstancePartitionIdxOfTxSoConIdMap(Index)                            (Sd_GetTxSoConIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstancePartitionIdxOfTxSoConIdMap)
#define Sd_GetIdOfUdpSoCon(Index, partitionIndex)                                                   (Sd_GetUdpSoConOfPCPartitionConfig(partitionIndex)[(Index)].IdOfUdpSoCon)
#define Sd_IsPreconfiguredOfUdpSoCon(Index, partitionIndex)                                         ((Sd_GetUdpSoConOfPCPartitionConfig(partitionIndex)[(Index)].PreconfiguredOfUdpSoCon) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGetDeduplicatedDataMacros  Sd Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Sd_IsAclIPv4CIndUsedOfClient(Index, partitionIndex)                                         (((boolean)(Sd_GetAclIPv4CIndStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_ACLIPV4CINDSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_AclIPv4CInd */
#define Sd_IsAclIPv6CIndUsedOfClient(Index, partitionIndex)                                         (((boolean)(Sd_GetAclIPv6CIndStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_ACLIPV6CINDSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_AclIPv6CInd */
#define Sd_IsCapabilityRecordFunctionCalloutPtrUsedOfClient(Index, partitionIndex)                  (((boolean)(Sd_GetCapabilityRecordFunctionCalloutPtrIdxOfClient(((Index)), (partitionIndex)) != SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr */
#define Sd_IsCapabilityRecordUsedOfClient(Index, partitionIndex)                                    (((boolean)(Sd_GetCapabilityRecordStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_CAPABILITYRECORDSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_CapabilityRecord */
#define Sd_IsCommonInitialDelayUsedOfClient(Index, partitionIndex)                                  (((boolean)(Sd_GetCommonInitialDelayIdxOfClient(((Index)), (partitionIndex)) != SD_NO_COMMONINITIALDELAYIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_CommonInitialDelay */
#define Sd_IsConsumedEventgroupUsedOfClient(Index, partitionIndex)                                  (((boolean)(Sd_GetConsumedEventgroupStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_CONSUMEDEVENTGROUPSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_ConsumedEventgroup */
#define Sd_IsMethodUsedOfClient(Index, partitionIndex)                                              (((boolean)(Sd_GetMethodIdxOfClient(((Index)), (partitionIndex)) != SD_NO_METHODIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Method */
#define Sd_IsSoConGrpDynTcpUsedOfClient(Index, partitionIndex)                                      (((boolean)(Sd_GetSoConGrpDynTcpIdxOfClient(((Index)), (partitionIndex)) != SD_NO_SOCONGRPDYNTCPIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_SoConGrpDyn */
#define Sd_IsSoConGrpDynUdpUsedOfClient(Index, partitionIndex)                                      (((boolean)(Sd_GetSoConGrpDynUdpIdxOfClient(((Index)), (partitionIndex)) != SD_NO_SOCONGRPDYNUDPIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_SoConGrpDyn */
#define Sd_IsTcpSoConIdUsedOfClient(Index, partitionIndex)                                          (((boolean)(Sd_GetTcpSoConIdStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_TCPSOCONIDSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_TcpSoConId */
#define Sd_IsUdpSoConUsedOfClient(Index, partitionIndex)                                            (((boolean)(Sd_GetUdpSoConStartIdxOfClient(((Index)), (partitionIndex)) != SD_NO_UDPSOCONSTARTIDXOFCLIENT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_UdpSoCon */
#define Sd_IsPartitionSpecificClientUsedOfClientIdMap(Index)                                        (((boolean)(Sd_GetPartitionSpecificClientIdxOfClientIdMap(Index) != SD_NO_PARTITIONSPECIFICCLIENTIDXOFCLIENTIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Client */
#define Sd_IsMulticastEndpointAddrUsedOfConsumedEventgroup(Index, partitionIndex)                   (((boolean)(Sd_GetMulticastEndpointAddrIdxOfConsumedEventgroup(((Index)), (partitionIndex)) != SD_NO_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_MulticastEndpointAddr */
#define Sd_IsMulticastSoConIdUsedOfConsumedEventgroup(Index, partitionIndex)                        (((boolean)(Sd_GetMulticastSoConIdStartIdxOfConsumedEventgroup(((Index)), (partitionIndex)) != SD_NO_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_MulticastSoConId */
#define Sd_IsRoutingGroupMulticastActRefUsedOfConsumedEventgroup(Index, partitionIndex)             (((boolean)(Sd_GetRoutingGroupMulticastActRefIdxOfConsumedEventgroup(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupTcpActRefUsedOfConsumedEventgroup(Index, partitionIndex)                   (((boolean)(Sd_GetRoutingGroupTcpActRefIdxOfConsumedEventgroup(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupUdpActRefUsedOfConsumedEventgroup(Index, partitionIndex)                   (((boolean)(Sd_GetRoutingGroupUdpActRefIdxOfConsumedEventgroup(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPUDPACTREFIDXOFCONSUMEDEVENTGROUP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsPartitionSpecificConsumedEventgroupUsedOfConsumedEventgroupIdMap(Index)                (((boolean)(Sd_GetPartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap(Index) != SD_NO_PARTITIONSPECIFICCONSUMEDEVENTGROUPIDXOFCONSUMEDEVENTGROUPIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_ConsumedEventgroup */
#define Sd_IsEventHandlerMulticastUsedOfEventHandler(Index, partitionIndex)                         (((boolean)(Sd_GetEventHandlerMulticastIdxOfEventHandler(((Index)), (partitionIndex)) != SD_NO_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_EventHandlerMulticast */
#define Sd_IsEventHandlerTcpUsedOfEventHandler(Index, partitionIndex)                               (((boolean)(Sd_GetEventHandlerTcpIdxOfEventHandler(((Index)), (partitionIndex)) != SD_NO_EVENTHANDLERTCPIDXOFEVENTHANDLER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_EventHandlerTcp */
#define Sd_IsEventHandlerUdpUsedOfEventHandler(Index, partitionIndex)                               (((boolean)(Sd_GetEventHandlerUdpIdxOfEventHandler(((Index)), (partitionIndex)) != SD_NO_EVENTHANDLERUDPIDXOFEVENTHANDLER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_EventHandlerUdp */
#define Sd_IsSoConActivationMapUsedOfEventHandler(Index, partitionIndex)                            (((boolean)(Sd_GetSoConActivationMapStartIdxOfEventHandler(((Index)), (partitionIndex)) != SD_NO_SOCONACTIVATIONMAPSTARTIDXOFEVENTHANDLER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_SoConActivationMap */
#define Sd_IsRoutingGroupActRefUsedOfEventHandlerMulticast(Index, partitionIndex)                   (((boolean)(Sd_GetRoutingGroupActRefIdxOfEventHandlerMulticast(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERMULTICAST)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupActRefUsedOfEventHandlerTcp(Index, partitionIndex)                         (((boolean)(Sd_GetRoutingGroupActRefIdxOfEventHandlerTcp(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERTCP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupTriggerUsedOfEventHandlerTcp(Index, partitionIndex)                        (((boolean)(Sd_GetRoutingGroupTriggerIdxOfEventHandlerTcp(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERTCP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupActRefUsedOfEventHandlerUdp(Index, partitionIndex)                         (((boolean)(Sd_GetRoutingGroupActRefIdxOfEventHandlerUdp(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPACTREFIDXOFEVENTHANDLERUDP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsRoutingGroupTriggerUsedOfEventHandlerUdp(Index, partitionIndex)                        (((boolean)(Sd_GetRoutingGroupTriggerIdxOfEventHandlerUdp(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsCapabilityRecordUsedOfInstance(Index, partitionIndex)                                  (((boolean)(Sd_GetCapabilityRecordStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_CAPABILITYRECORDSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_CapabilityRecord */
#define Sd_IsClientUsedOfInstance(Index, partitionIndex)                                            (((boolean)(Sd_GetClientStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_CLIENTSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_Client */
#define Sd_IsEventHandlerUsedOfInstance(Index, partitionIndex)                                      (((boolean)(Sd_GetEventHandlerStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_EVENTHANDLERSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_EventHandler */
#define Sd_IsRxEventUsedOfInstance(Index, partitionIndex)                                           (((boolean)(Sd_GetRxEventStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_RXEVENTSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_RxEvent */
#define Sd_IsServerUsedOfInstance(Index, partitionIndex)                                            (((boolean)(Sd_GetServerStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_SERVERSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_Server */
#define Sd_IsTcpSoConIdUsedOfInstance(Index, partitionIndex)                                        (((boolean)(Sd_GetTcpSoConIdStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_TCPSOCONIDSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_TcpSoConId */
#define Sd_IsUdpSoConUsedOfInstance(Index, partitionIndex)                                          (((boolean)(Sd_GetUdpSoConStartIdxOfInstance(((Index)), (partitionIndex)) != SD_NO_UDPSOCONSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_UdpSoCon */
#define Sd_GetMaxNrOptionsPerEntry(partitionIndex)                                                  Sd_GetMaxNrOptionsPerEntryOfPCPartitionConfig(partitionIndex)
#define Sd_IsRoutingGroupActRefUsedOfMethod(Index, partitionIndex)                                  (((boolean)(Sd_GetRoutingGroupActRefIdxOfMethod(((Index)), (partitionIndex)) != SD_NO_ROUTINGGROUPACTREFIDXOFMETHOD)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_RoutingGroup */
#define Sd_IsServerUsedOfRoutingGroupIdMap(Index)                                                   (((boolean)(Sd_GetServerIdxOfRoutingGroupIdMap(Index) != SD_NO_SERVERIDXOFROUTINGGROUPIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Server */
#define Sd_IsPartitionSpecificInstanceUsedOfRxPduIdMap(Index)                                       (((boolean)(Sd_GetPartitionSpecificInstanceIdxOfRxPduIdMap(Index) != SD_NO_PARTITIONSPECIFICINSTANCEIDXOFRXPDUIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Instance */
#define Sd_IsAclIPv4SIndUsedOfServer(Index, partitionIndex)                                         (((boolean)(Sd_GetAclIPv4SIndStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_ACLIPV4SINDSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_AclIPv4SInd */
#define Sd_IsAclIPv6SIndUsedOfServer(Index, partitionIndex)                                         (((boolean)(Sd_GetAclIPv6SIndStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_ACLIPV6SINDSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_AclIPv6SInd */
#define Sd_IsCapabilityRecordFunctionCalloutPtrUsedOfServer(Index, partitionIndex)                  (((boolean)(Sd_GetCapabilityRecordFunctionCalloutPtrIdxOfServer(((Index)), (partitionIndex)) != SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr */
#define Sd_IsCapabilityRecordUsedOfServer(Index, partitionIndex)                                    (((boolean)(Sd_GetCapabilityRecordStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_CAPABILITYRECORDSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_CapabilityRecord */
#define Sd_IsCommonInitialDelayUsedOfServer(Index, partitionIndex)                                  (((boolean)(Sd_GetCommonInitialDelayIdxOfServer(((Index)), (partitionIndex)) != SD_NO_COMMONINITIALDELAYIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_CommonInitialDelay */
#define Sd_IsEventHandlerUsedOfServer(Index, partitionIndex)                                        (((boolean)(Sd_GetEventHandlerStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_EVENTHANDLERSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_EventHandler */
#define Sd_IsMethodUsedOfServer(Index, partitionIndex)                                              (((boolean)(Sd_GetMethodIdxOfServer(((Index)), (partitionIndex)) != SD_NO_METHODIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Method */
#define Sd_IsSoConGrpDynTcpUsedOfServer(Index, partitionIndex)                                      (((boolean)(Sd_GetSoConGrpDynTcpIdxOfServer(((Index)), (partitionIndex)) != SD_NO_SOCONGRPDYNTCPIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_SoConGrpDyn */
#define Sd_IsSoConGrpDynUdpUsedOfServer(Index, partitionIndex)                                      (((boolean)(Sd_GetSoConGrpDynUdpIdxOfServer(((Index)), (partitionIndex)) != SD_NO_SOCONGRPDYNUDPIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_SoConGrpDyn */
#define Sd_IsTcpSoConIdUsedOfServer(Index, partitionIndex)                                          (((boolean)(Sd_GetTcpSoConIdStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_TCPSOCONIDSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_TcpSoConId */
#define Sd_IsUdpSoConUsedOfServer(Index, partitionIndex)                                            (((boolean)(Sd_GetUdpSoConStartIdxOfServer(((Index)), (partitionIndex)) != SD_NO_UDPSOCONSTARTIDXOFSERVER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Sd_UdpSoCon */
#define Sd_IsPartitionSpecificServerUsedOfServerIdMap(Index)                                        (((boolean)(Sd_GetPartitionSpecificServerIdxOfServerIdMap(Index) != SD_NO_PARTITIONSPECIFICSERVERIDXOFSERVERIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Server */
#define Sd_IsPartitionSpecificServiceGroupUsedOfServiceGroupIdMap(Index)                            (((boolean)(Sd_GetPartitionSpecificServiceGroupIdxOfServiceGroupIdMap(Index) != SD_NO_PARTITIONSPECIFICSERVICEGROUPIDXOFSERVICEGROUPIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_ServiceGroup */
#define Sd_IsClientUsedOfServiceGroupMember(Index, partitionIndex)                                  (((boolean)(Sd_GetClientIdxOfServiceGroupMember(((Index)), (partitionIndex)) != SD_NO_CLIENTIDXOFSERVICEGROUPMEMBER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Client */
#define Sd_IsServerUsedOfServiceGroupMember(Index, partitionIndex)                                  (((boolean)(Sd_GetServerIdxOfServiceGroupMember(((Index)), (partitionIndex)) != SD_NO_SERVERIDXOFSERVICEGROUPMEMBER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Server */
#define Sd_GetSizeOfAclIPv4(partitionIndex)                                                         Sd_GetSizeOfAclIPv4OfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAclIPv4CInd(partitionIndex)                                                     Sd_GetSizeOfAclIPv4CIndOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAclIPv4SInd(partitionIndex)                                                     Sd_GetSizeOfAclIPv4SIndOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAclIPv6(partitionIndex)                                                         Sd_GetSizeOfAclIPv6OfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAclIPv6CInd(partitionIndex)                                                     Sd_GetSizeOfAclIPv6CIndOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAclIPv6SInd(partitionIndex)                                                     Sd_GetSizeOfAclIPv6SIndOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfAddressStorage(partitionIndex)                                                  Sd_GetSizeOfAddressStorageOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfCapabilityRecord()                                                              Sd_GetSizeOfCapabilityRecordOfPCPartitionConfig()
#define Sd_GetSizeOfCapabilityRecordFunctionCalloutPtr()                                            Sd_GetSizeOfCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()
#define Sd_GetSizeOfClient(partitionIndex)                                                          Sd_GetSizeOfClientOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfClientDyn(partitionIndex)                                                       Sd_GetSizeOfClientDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfClientIdMap()                                                                   Sd_GetSizeOfClientIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfClientList(partitionIndex)                                                      Sd_GetSizeOfClientListOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfClientTimer(partitionIndex)                                                     Sd_GetSizeOfClientTimerOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfCommonInitialDelay(partitionIndex)                                              Sd_GetSizeOfCommonInitialDelayOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfConsumedEventgroup(partitionIndex)                                              Sd_GetSizeOfConsumedEventgroupOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfConsumedEventgroupDyn(partitionIndex)                                           Sd_GetSizeOfConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfConsumedEventgroupIdMap()                                                       Sd_GetSizeOfConsumedEventgroupIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfEndpointStorage(partitionIndex)                                                 Sd_GetSizeOfEndpointStorageOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfEventHandler(partitionIndex)                                                    Sd_GetSizeOfEventHandlerOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfEventHandlerDyn(partitionIndex)                                                 Sd_GetSizeOfEventHandlerDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfEventHandlerMulticast(partitionIndex)                                           Sd_GetSizeOfEventHandlerMulticastOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfEventHandlerTcp(partitionIndex)                                                 Sd_GetSizeOfEventHandlerTcpOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfEventHandlerUdp(partitionIndex)                                                 Sd_GetSizeOfEventHandlerUdpOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfInstance(partitionIndex)                                                        Sd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfInstanceDyn(partitionIndex)                                                     Sd_GetSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfIpAddrRequest(partitionIndex)                                                   Sd_GetSizeOfIpAddrRequestOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfMethod(partitionIndex)                                                          Sd_GetSizeOfMethodOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfMulticastEndpointAddr(partitionIndex)                                           Sd_GetSizeOfMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfMulticastSoConId(partitionIndex)                                                Sd_GetSizeOfMulticastSoConIdOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfOptionIndex(partitionIndex)                                                     Sd_GetSizeOfOptionIndexOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfPartitionDataDyn(partitionIndex)                                                Sd_GetSizeOfPartitionDataDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfPartitionIdentifiers()                                                          Sd_GetSizeOfPartitionIdentifiersOfPCConfig()
#define Sd_GetSizeOfPayload(partitionIndex)                                                         Sd_GetSizeOfPayloadOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfPortSet(partitionIndex)                                                         Sd_GetSizeOfPortSetOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfRequestCnt(partitionIndex)                                                      Sd_GetSizeOfRequestCntOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfRoutingGroup(partitionIndex)                                                    Sd_GetSizeOfRoutingGroupOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfRoutingGroupDyn(partitionIndex)                                                 Sd_GetSizeOfRoutingGroupDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfRoutingGroupIdMap()                                                             Sd_GetSizeOfRoutingGroupIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfRxEvent(partitionIndex)                                                         Sd_GetSizeOfRxEventOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfRxPduIdMap()                                                                    Sd_GetSizeOfRxPduIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfSendEntry(partitionIndex)                                                       Sd_GetSizeOfSendEntryOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfServer(partitionIndex)                                                          Sd_GetSizeOfServerOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfServerDyn(partitionIndex)                                                       Sd_GetSizeOfServerDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfServerIdMap()                                                                   Sd_GetSizeOfServerIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfServerTimer(partitionIndex)                                                     Sd_GetSizeOfServerTimerOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfServiceGroup(partitionIndex)                                                    Sd_GetSizeOfServiceGroupOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfServiceGroupIdMap()                                                             Sd_GetSizeOfServiceGroupIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfServiceGroupMember(partitionIndex)                                              Sd_GetSizeOfServiceGroupMemberOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfSoConActivationMap(partitionIndex)                                              Sd_GetSizeOfSoConActivationMapOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfSoConGrpDyn(partitionIndex)                                                     Sd_GetSizeOfSoConGrpDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfSoConModeDyn(partitionIndex)                                                    Sd_GetSizeOfSoConModeDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfSoConModeIdMap()                                                                Sd_GetSizeOfSoConModeIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfTcpSoConId(partitionIndex)                                                      Sd_GetSizeOfTcpSoConIdOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfTriggerTransmitDyn(partitionIndex)                                              Sd_GetSizeOfTriggerTransmitDynOfPCPartitionConfig(partitionIndex)
#define Sd_GetSizeOfTxSoConIdMap()                                                                  Sd_GetSizeOfTxSoConIdMapOfPCPartitionConfig()
#define Sd_GetSizeOfUdpSoCon(partitionIndex)                                                        Sd_GetSizeOfUdpSoConOfPCPartitionConfig(partitionIndex)
#define Sd_IsPartitionSpecificSoConModeUsedOfSoConModeIdMap(Index)                                  (((boolean)(Sd_GetPartitionSpecificSoConModeIdxOfSoConModeIdMap(Index) != SD_NO_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_SoConModeDyn */
#define Sd_IsPartitionSpecificInstanceUsedOfTxSoConIdMap(Index)                                     (((boolean)(Sd_GetPartitionSpecificInstanceIdxOfTxSoConIdMap(Index) != SD_NO_PARTITIONSPECIFICINSTANCEIDXOFTXSOCONIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Sd_Instance */
/** 
  \}
*/ 

/** 
  \defgroup  SdPCSetDataMacros  Sd Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Sd_SetAddrOfAddressStorage(Index, Value, partitionIndex)                                    Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].AddrOfAddressStorage = (Value)
#define Sd_SetFlagsOfAddressStorage(Index, Value, partitionIndex)                                   Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].FlagsOfAddressStorage = (Value)
#define Sd_SetRebootDetectedOfAddressStorage(Index, Value, partitionIndex)                          Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RebootDetectedOfAddressStorage = (Value)
#define Sd_SetRxMulticastFlagsOfAddressStorage(Index, Value, partitionIndex)                        Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxMulticastFlagsOfAddressStorage = (Value)
#define Sd_SetRxMulticastSessionIdOfAddressStorage(Index, Value, partitionIndex)                    Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxMulticastSessionIdOfAddressStorage = (Value)
#define Sd_SetRxUnicastFlagsOfAddressStorage(Index, Value, partitionIndex)                          Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxUnicastFlagsOfAddressStorage = (Value)
#define Sd_SetRxUnicastSessionIdOfAddressStorage(Index, Value, partitionIndex)                      Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].RxUnicastSessionIdOfAddressStorage = (Value)
#define Sd_SetSendEntryHeadIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryHeadIdxOfAddressStorage = (Value)
#define Sd_SetSendEntryNrPendingIdxOfAddressStorage(Index, Value, partitionIndex)                   Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNrPendingIdxOfAddressStorage = (Value)
#define Sd_SetSendEntryTailIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryTailIdxOfAddressStorage = (Value)
#define Sd_SetSessionIdCounterOfAddressStorage(Index, Value, partitionIndex)                        Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].SessionIdCounterOfAddressStorage = (Value)
#define Sd_SetTimeToSendOfAddressStorage(Index, Value, partitionIndex)                              Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex)[(Index)].TimeToSendOfAddressStorage = (Value)
#define Sd_SetAddressStorageCurrentServerIdxOfClientDyn(Index, Value, partitionIndex)               Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageCurrentServerIdxOfClientDyn = (Value)
#define Sd_SetAddressStorageServerIdxOfClientDyn(Index, Value, partitionIndex)                      Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageServerIdxOfClientDyn = (Value)
#define Sd_SetCurrentStateOfClientDyn(Index, Value, partitionIndex)                                 Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].CurrentStateOfClientDyn = (Value)
#define Sd_SetEventMainOfClientDyn(Index, Value, partitionIndex)                                    Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].EventMainOfClientDyn = (Value)
#define Sd_SetEventRxOfClientDyn(Index, Value, partitionIndex)                                      Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].EventRxOfClientDyn = (Value)
#define Sd_SetInstanceIdOfClientDyn(Index, Value, partitionIndex)                                   Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfClientDyn = (Value)
#define Sd_SetMethodTcpSoConIdOfClientDyn(Index, Value, partitionIndex)                             Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].MethodTcpSoConIdOfClientDyn = (Value)
#define Sd_SetMethodUdpSoConIdOfClientDyn(Index, Value, partitionIndex)                             Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].MethodUdpSoConIdOfClientDyn = (Value)
#define Sd_SetOfferedTTLOfClientDyn(Index, Value, partitionIndex)                                   Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].OfferedTTLOfClientDyn = (Value)
#define Sd_SetRepetitionRunOfClientDyn(Index, Value, partitionIndex)                                Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RepetitionRunOfClientDyn = (Value)
#define Sd_SetRetryCounterOfClientDyn(Index, Value, partitionIndex)                                 Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryCounterOfClientDyn = (Value)
#define Sd_SetRetryTimerOfClientDyn(Index, Value, partitionIndex)                                   Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryTimerOfClientDyn = (Value)
#define Sd_SetServerTcpEndpointAddrOfClientDyn(Index, Value, partitionIndex)                        Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServerTcpEndpointAddrOfClientDyn = (Value)
#define Sd_SetServerUdpEndpointAddrOfClientDyn(Index, Value, partitionIndex)                        Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServerUdpEndpointAddrOfClientDyn = (Value)
#define Sd_SetServiceGroupReqCounterOfClientDyn(Index, Value, partitionIndex)                       Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupReqCounterOfClientDyn = (Value)
#define Sd_SetStateMachineExecutionRequestedOfClientDyn(Index, Value, partitionIndex)               Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineExecutionRequestedOfClientDyn = (Value)
#define Sd_SetStateMachineOfClientDyn(Index, Value, partitionIndex)                                 Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfClientDyn = (Value)
#define Sd_SetStateSwcOfClientDyn(Index, Value, partitionIndex)                                     Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].StateSwcOfClientDyn = (Value)
#define Sd_SetTimeToTriggerSendOfClientDyn(Index, Value, partitionIndex)                            Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeToTriggerSendOfClientDyn = (Value)
#define Sd_SetTimerTTLOfClientDyn(Index, Value, partitionIndex)                                     Sd_GetClientDynOfPCPartitionConfig(partitionIndex)[(Index)].TimerTTLOfClientDyn = (Value)
#define Sd_SetAddressStorageIdxOfClientList(Index, Value, partitionIndex)                           Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AddressStorageIdxOfClientList = (Value)
#define Sd_SetAssignedTcpSoConIdOfClientList(Index, Value, partitionIndex)                          Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AssignedTcpSoConIdOfClientList = (Value)
#define Sd_SetAssignedUdpSoConIdOfClientList(Index, Value, partitionIndex)                          Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].AssignedUdpSoConIdOfClientList = (Value)
#define Sd_SetClientStateOfClientList(Index, Value, partitionIndex)                                 Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].ClientStateOfClientList = (Value)
#define Sd_SetEndpointStorageTcpIdxOfClientList(Index, Value, partitionIndex)                       Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageTcpIdxOfClientList = (Value)
#define Sd_SetEndpointStorageUdpIdxOfClientList(Index, Value, partitionIndex)                       Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].EndpointStorageUdpIdxOfClientList = (Value)
#define Sd_SetNrOfReferencesOfClientList(Index, Value, partitionIndex)                              Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].NrOfReferencesOfClientList = (Value)
#define Sd_SetRequestedTTLOfClientList(Index, Value, partitionIndex)                                Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].RequestedTTLOfClientList = (Value)
#define Sd_SetRxReservedOfClientList(Index, Value, partitionIndex)                                  Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].RxReservedOfClientList = (Value)
#define Sd_SetSubscribedUntilOfClientList(Index, Value, partitionIndex)                             Sd_GetClientListOfPCPartitionConfig(partitionIndex)[(Index)].SubscribedUntilOfClientList = (Value)
#define Sd_SetCommonInitialDelay(Index, Value, partitionIndex)                                      Sd_GetCommonInitialDelayOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetAcknowledgedTTLOfConsumedEventgroupDyn(Index, Value, partitionIndex)                  Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].AcknowledgedTTLOfConsumedEventgroupDyn = (Value)
#define Sd_SetCurrentStateOfConsumedEventgroupDyn(Index, Value, partitionIndex)                     Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].CurrentStateOfConsumedEventgroupDyn = (Value)
#define Sd_SetEventOfConsumedEventgroupDyn(Index, Value, partitionIndex)                            Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].EventOfConsumedEventgroupDyn = (Value)
#define Sd_SetMulticastSoConIdOfConsumedEventgroupDyn(Index, Value, partitionIndex)                 Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].MulticastSoConIdOfConsumedEventgroupDyn = (Value)
#define Sd_SetRxIndicationCountOfConsumedEventgroupDyn(Index, Value, partitionIndex)                Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].RxIndicationCountOfConsumedEventgroupDyn = (Value)
#define Sd_SetServiceModeRequestOfConsumedEventgroupDyn(Index, Value, partitionIndex)               Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceModeRequestOfConsumedEventgroupDyn = (Value)
#define Sd_SetStateMachineOfConsumedEventgroupDyn(Index, Value, partitionIndex)                     Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfConsumedEventgroupDyn = (Value)
#define Sd_SetTcpSoConIdOfConsumedEventgroupDyn(Index, Value, partitionIndex)                       Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TcpSoConIdOfConsumedEventgroupDyn = (Value)
#define Sd_SetTimerTTLOfConsumedEventgroupDyn(Index, Value, partitionIndex)                         Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TimerTTLOfConsumedEventgroupDyn = (Value)
#define Sd_SetTriggerSubscriptionOfConsumedEventgroupDyn(Index, Value, partitionIndex)              Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerSubscriptionOfConsumedEventgroupDyn = (Value)
#define Sd_SetUdpSoConIdOfConsumedEventgroupDyn(Index, Value, partitionIndex)                       Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)[(Index)].UdpSoConIdOfConsumedEventgroupDyn = (Value)
#define Sd_SetAddrOfEndpointStorage(Index, Value, partitionIndex)                                   Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].AddrOfEndpointStorage = (Value)
#define Sd_SetNrOfReferencesOfEndpointStorage(Index, Value, partitionIndex)                         Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].NrOfReferencesOfEndpointStorage = (Value)
#define Sd_SetTypeOfEndpointStorage(Index, Value, partitionIndex)                                   Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex)[(Index)].TypeOfEndpointStorage = (Value)
#define Sd_SetNrOfClientsOfEventHandlerDyn(Index, Value, partitionIndex)                            Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].NrOfClientsOfEventHandlerDyn = (Value)
#define Sd_SetRequestStateOfEventHandlerDyn(Index, Value, partitionIndex)                           Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].RequestStateOfEventHandlerDyn = (Value)
#define Sd_SetStateMachineOfEventHandlerDyn(Index, Value, partitionIndex)                           Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfEventHandlerDyn = (Value)
#define Sd_SetLastFoundEndpointOfInstanceDyn(Index, Value, partitionIndex)                          Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].LastFoundEndpointOfInstanceDyn = (Value)
#define Sd_SetNextStateMachineRunOfInstanceDyn(Index, Value, partitionIndex)                        Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].NextStateMachineRunOfInstanceDyn = (Value)
#define Sd_SetRunModeOfInstanceDyn(Index, Value, partitionIndex)                                    Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RunModeOfInstanceDyn = (Value)
#define Sd_SetRxEventEndIdxOfInstanceDyn(Index, Value, partitionIndex)                              Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventEndIdxOfInstanceDyn = (Value)
#define Sd_SetRxEventListFullOfInstanceDyn(Index, Value, partitionIndex)                            Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventListFullOfInstanceDyn = (Value)
#define Sd_SetRxEventStartIdxOfInstanceDyn(Index, Value, partitionIndex)                            Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].RxEventStartIdxOfInstanceDyn = (Value)
#define Sd_SetSendEntryFreeListHeadIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryFreeListHeadIdxOfInstanceDyn = (Value)
#define Sd_SetSendEntryFreeListTailIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryFreeListTailIdxOfInstanceDyn = (Value)
#define Sd_SetSendEntryNrPendingIdxOfInstanceDyn(Index, Value, partitionIndex)                      Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNrPendingIdxOfInstanceDyn = (Value)
#define Sd_SetStateOfInstanceDyn(Index, Value, partitionIndex)                                      Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].StateOfInstanceDyn = (Value)
#define Sd_SetMulticastEndpointAddr(Index, Value, partitionIndex)                                   Sd_GetMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetOptionIndex(Index, Value, partitionIndex)                                             Sd_GetOptionIndexOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetInitializedOfPartitionDataDyn(Index, Value, partitionIndex)                           Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].InitializedOfPartitionDataDyn = (Value)
#define Sd_SetNrOfOptionsOfPartitionDataDyn(Index, Value, partitionIndex)                           Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].NrOfOptionsOfPartitionDataDyn = (Value)
#define Sd_SetRxIndicationCountOfPartitionDataDyn(Index, Value, partitionIndex)                     Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].RxIndicationCountOfPartitionDataDyn = (Value)
#define Sd_SetTimeMsSinceStartOfPartitionDataDyn(Index, Value, partitionIndex)                      Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeMsSinceStartOfPartitionDataDyn = (Value)
#define Sd_SetTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, Value, partitionIndex)              Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitDynEndIdxOfPartitionDataDyn = (Value)
#define Sd_SetTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, Value, partitionIndex)            Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitDynStartIdxOfPartitionDataDyn = (Value)
#define Sd_SetTriggerTransmitFullOfPartitionDataDyn(Index, Value, partitionIndex)                   Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TriggerTransmitFullOfPartitionDataDyn = (Value)
#define Sd_SetTxPathLockedOfPartitionDataDyn(Index, Value, partitionIndex)                          Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex)[(Index)].TxPathLockedOfPartitionDataDyn = (Value)
#define Sd_SetPayload(Index, Value, partitionIndex)                                                 Sd_GetPayloadOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetPortSet(Index, Value, partitionIndex)                                                 Sd_GetPortSetOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetRequestCnt(Index, Value, partitionIndex)                                              Sd_GetRequestCntOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetStatusOfRoutingGroupDyn(Index, Value, partitionIndex)                                 Sd_GetRoutingGroupDynOfPCPartitionConfig(partitionIndex)[(Index)].StatusOfRoutingGroupDyn = (Value)
#define Sd_SetClientListIdxOfRxEvent(Index, Value, partitionIndex)                                  Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfRxEvent = (Value)
#define Sd_SetEventHandlerIdxOfRxEvent(Index, Value, partitionIndex)                                Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfRxEvent = (Value)
#define Sd_SetEventOfRxEvent(Index, Value, partitionIndex)                                          Sd_GetRxEventOfPCPartitionConfig(partitionIndex)[(Index)].EventOfRxEvent = (Value)
#define Sd_SetClientIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ClientIdxOfSendEntry = (Value)
#define Sd_SetClientListIdxOfSendEntry(Index, Value, partitionIndex)                                Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfSendEntry = (Value)
#define Sd_SetConsumedEventgroupIdxOfSendEntry(Index, Value, partitionIndex)                        Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ConsumedEventgroupIdxOfSendEntry = (Value)
#define Sd_SetEntryTypeOfSendEntry(Index, Value, partitionIndex)                                    Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EntryTypeOfSendEntry = (Value)
#define Sd_SetEventHandlerIdOfSendEntry(Index, Value, partitionIndex)                               Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdOfSendEntry = (Value)
#define Sd_SetEventHandlerIdxOfSendEntry(Index, Value, partitionIndex)                              Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfSendEntry = (Value)
#define Sd_SetInstanceIdOfSendEntry(Index, Value, partitionIndex)                                   Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfSendEntry = (Value)
#define Sd_SetInstanceIdxOfSendEntry(Index, Value, partitionIndex)                                  Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdxOfSendEntry = (Value)
#define Sd_SetMajorVersionOfSendEntry(Index, Value, partitionIndex)                                 Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].MajorVersionOfSendEntry = (Value)
#define Sd_SetReservedFieldOfSendEntry(Index, Value, partitionIndex)                                Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ReservedFieldOfSendEntry = (Value)
#define Sd_SetSendEntryNextIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryNextIdxOfSendEntry = (Value)
#define Sd_SetSendEntryPrevIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].SendEntryPrevIdxOfSendEntry = (Value)
#define Sd_SetServerIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ServerIdxOfSendEntry = (Value)
#define Sd_SetServiceIdOfSendEntry(Index, Value, partitionIndex)                                    Sd_GetSendEntryOfPCPartitionConfig(partitionIndex)[(Index)].ServiceIdOfSendEntry = (Value)
#define Sd_SetInitialOfferRepetitionRunOfServerDyn(Index, Value, partitionIndex)                    Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].InitialOfferRepetitionRunOfServerDyn = (Value)
#define Sd_SetInstanceIdOfServerDyn(Index, Value, partitionIndex)                                   Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdOfServerDyn = (Value)
#define Sd_SetServiceGroupReqCounterOfServerDyn(Index, Value, partitionIndex)                       Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].ServiceGroupReqCounterOfServerDyn = (Value)
#define Sd_SetStateMachineExecutionRequestedOfServerDyn(Index, Value, partitionIndex)               Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineExecutionRequestedOfServerDyn = (Value)
#define Sd_SetStateMachineOfServerDyn(Index, Value, partitionIndex)                                 Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateMachineOfServerDyn = (Value)
#define Sd_SetStateSwcOfServerDyn(Index, Value, partitionIndex)                                     Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].StateSwcOfServerDyn = (Value)
#define Sd_SetTimeToTriggerSendOfServerDyn(Index, Value, partitionIndex)                            Sd_GetServerDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeToTriggerSendOfServerDyn = (Value)
#define Sd_SetNrOfActivationsOfSoConActivationMap(Index, Value, partitionIndex)                     Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex)[(Index)].NrOfActivationsOfSoConActivationMap = (Value)
#define Sd_SetSoConIdOfSoConActivationMap(Index, Value, partitionIndex)                             Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdOfSoConActivationMap = (Value)
#define Sd_SetLocalPortOfSoConGrpDyn(Index, Value, partitionIndex)                                  Sd_GetSoConGrpDynOfPCPartitionConfig(partitionIndex)[(Index)].LocalPortOfSoConGrpDyn = (Value)
#define Sd_SetSoConModeDyn(Index, Value, partitionIndex)                                            Sd_GetSoConModeDynOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Sd_SetClientListIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                       Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex)[(Index)].ClientListIdxOfTriggerTransmitDyn = (Value)
#define Sd_SetEventHandlerIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                     Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex)[(Index)].EventHandlerIdxOfTriggerTransmitDyn = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SdPCGetAddressOfDataMacros  Sd Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Sd_GetAddrAddrOfAddressStorage(Index, partitionIndex)                                       (&Sd_GetAddrOfAddressStorage(((Index)), (partitionIndex)))
#define Sd_GetAddrTimeToSendOfAddressStorage(Index, partitionIndex)                                 (&Sd_GetTimeToSendOfAddressStorage(((Index)), (partitionIndex)))
#define Sd_GetAddrCapabilityRecord(Index)                                                           (&Sd_GetCapabilityRecord(Index))
#define Sd_GetAddrMethodTcpSoConIdOfClientDyn(Index, partitionIndex)                                (&Sd_GetMethodTcpSoConIdOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrMethodUdpSoConIdOfClientDyn(Index, partitionIndex)                                (&Sd_GetMethodUdpSoConIdOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrRetryTimerOfClientDyn(Index, partitionIndex)                                      (&Sd_GetRetryTimerOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrServerTcpEndpointAddrOfClientDyn(Index, partitionIndex)                           (&Sd_GetServerTcpEndpointAddrOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrServerUdpEndpointAddrOfClientDyn(Index, partitionIndex)                           (&Sd_GetServerUdpEndpointAddrOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrTimeToTriggerSendOfClientDyn(Index, partitionIndex)                               (&Sd_GetTimeToTriggerSendOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrTimerTTLOfClientDyn(Index, partitionIndex)                                        (&Sd_GetTimerTTLOfClientDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrRxReservedOfClientList(Index, partitionIndex)                                     (&Sd_GetRxReservedOfClientList(((Index)), (partitionIndex)))
#define Sd_GetAddrSubscribedUntilOfClientList(Index, partitionIndex)                                (&Sd_GetSubscribedUntilOfClientList(((Index)), (partitionIndex)))
#define Sd_GetAddrTimerTTLOfConsumedEventgroupDyn(Index, partitionIndex)                            (&Sd_GetTimerTTLOfConsumedEventgroupDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrAddrOfEndpointStorage(Index, partitionIndex)                                      (&Sd_GetAddrOfEndpointStorage(((Index)), (partitionIndex)))
#define Sd_GetAddrNextStateMachineRunOfInstanceDyn(Index, partitionIndex)                           (&Sd_GetNextStateMachineRunOfInstanceDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrMulticastEndpointAddr(Index, partitionIndex)                                      (&Sd_GetMulticastEndpointAddr(((Index)), (partitionIndex)))
#define Sd_GetAddrInitializedOfPartitionDataDyn(Index, partitionIndex)                              (&Sd_GetInitializedOfPartitionDataDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrTimeMsSinceStartOfPartitionDataDyn(Index, partitionIndex)                         (&Sd_GetTimeMsSinceStartOfPartitionDataDyn(((Index)), (partitionIndex)))
#define Sd_GetAddrPayload(Index, partitionIndex)                                                    (&Sd_GetPayload(((Index)), (partitionIndex)))
#define Sd_GetAddrTimeToTriggerSendOfServerDyn(Index, partitionIndex)                               (&Sd_GetTimeToTriggerSendOfServerDyn(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  SdPCHasMacros  Sd Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Sd_HasAclIPv4(partitionIndex)                                                               (Sd_GetAclIPv4OfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddrOfAclIPv4(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasAclIPv4CInd(partitionIndex)                                                           (Sd_GetAclIPv4CIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAclIPv4SInd(partitionIndex)                                                           (Sd_GetAclIPv4SIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAclIPv6(partitionIndex)                                                               (Sd_GetAclIPv6OfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddrOfAclIPv6(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasAclIPv6CInd(partitionIndex)                                                           (Sd_GetAclIPv6CIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAclIPv6SInd(partitionIndex)                                                           (Sd_GetAclIPv6SIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddressStorage(partitionIndex)                                                        (Sd_GetAddressStorageOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddrOfAddressStorage(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasFlagsOfAddressStorage(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasRebootDetectedOfAddressStorage(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasRxMulticastFlagsOfAddressStorage(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasRxMulticastSessionIdOfAddressStorage(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasRxUnicastFlagsOfAddressStorage(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasRxUnicastSessionIdOfAddressStorage(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasSendEntryHeadIdxOfAddressStorage(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSendEntryNrPendingIdxOfAddressStorage(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSendEntryTailIdxOfAddressStorage(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSessionIdCounterOfAddressStorage(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasTimeToSendOfAddressStorage(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasCapabilityRecord()                                                                    (Sd_GetCapabilityRecordOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasCapabilityRecordFunctionCalloutPtr()                                                  (Sd_GetCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasClient(partitionIndex)                                                                (Sd_GetClientOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAclIPv4CIndEndIdxOfClient(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasAclIPv4CIndStartIdxOfClient(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasAclIPv4CIndUsedOfClient(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasAclIPv6CIndEndIdxOfClient(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasAclIPv6CIndStartIdxOfClient(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasAclIPv6CIndUsedOfClient(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasAutoRequireOfClient(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasCapabilityRecordEndIdxOfClient(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasCapabilityRecordFunctionCalloutPtrIdxOfClient(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasCapabilityRecordFunctionCalloutPtrUsedOfClient(partitionIndex)                        (TRUE != FALSE)
#define Sd_HasCapabilityRecordStartIdxOfClient(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasCapabilityRecordUsedOfClient(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasClientTimerIdxOfClient(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasCommonInitialDelayIdxOfClient(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasCommonInitialDelayUsedOfClient(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasConsumedEventgroupEndIdxOfClient(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasConsumedEventgroupStartIdxOfClient(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasConsumedEventgroupUsedOfClient(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasFindBehaviorOfClient(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasHandleIdOfClient(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasInitialInstanceIdOfClient(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasInstanceIdxOfClient(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasMajorVersionOfClient(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasMethodIdxOfClient(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasMethodUsedOfClient(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasMinorVersionOfClient(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasMinorVersionWildcardOfClient(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasServiceGroupMemberOfClient(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasServiceIdOfClient(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSoConGrpDynTcpIdxOfClient(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasSoConGrpDynTcpUsedOfClient(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasSoConGrpDynUdpIdxOfClient(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasSoConGrpDynUdpUsedOfClient(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasTcpSoConIdEndIdxOfClient(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasTcpSoConIdStartIdxOfClient(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasTcpSoConIdUsedOfClient(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasUdpClientMulticastOfClient(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasUdpSoConEndIdxOfClient(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasUdpSoConStartIdxOfClient(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasUdpSoConUsedOfClient(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasClientDyn(partitionIndex)                                                             (Sd_GetClientDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddressStorageCurrentServerIdxOfClientDyn(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasAddressStorageServerIdxOfClientDyn(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasCurrentStateOfClientDyn(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasEventMainOfClientDyn(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasEventRxOfClientDyn(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasInstanceIdOfClientDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasMethodTcpSoConIdOfClientDyn(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasMethodUdpSoConIdOfClientDyn(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasOfferedTTLOfClientDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasRepetitionRunOfClientDyn(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasRetryCounterOfClientDyn(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasRetryTimerOfClientDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasServerTcpEndpointAddrOfClientDyn(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasServerUdpEndpointAddrOfClientDyn(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasServiceGroupReqCounterOfClientDyn(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasStateMachineExecutionRequestedOfClientDyn(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasStateMachineOfClientDyn(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasStateSwcOfClientDyn(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasTimeToTriggerSendOfClientDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasTimerTTLOfClientDyn(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasClientIdMap()                                                                         (Sd_GetClientIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfClientIdMap()                                                             (TRUE != FALSE)
#define Sd_HasPartitionSpecificClientIdxOfClientIdMap()                                             (TRUE != FALSE)
#define Sd_HasPartitionSpecificClientPartitionIdxOfClientIdMap()                                    (TRUE != FALSE)
#define Sd_HasPartitionSpecificClientUsedOfClientIdMap()                                            (TRUE != FALSE)
#define Sd_HasClientList(partitionIndex)                                                            (Sd_GetClientListOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddressStorageIdxOfClientList(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasAssignedTcpSoConIdOfClientList(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAssignedUdpSoConIdOfClientList(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasClientStateOfClientList(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasEndpointStorageTcpIdxOfClientList(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasEndpointStorageUdpIdxOfClientList(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasNrOfReferencesOfClientList(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasRequestedTTLOfClientList(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasRxReservedOfClientList(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasSubscribedUntilOfClientList(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasClientTimer(partitionIndex)                                                           (Sd_GetClientTimerOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasInitialFindDelayMaxOfClientTimer(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasInitialFindDelayMinOfClientTimer(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasInitialFindRepetitionBaseDelayOfClientTimer(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasInitialFindRepetitionsMaxOfClientTimer(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasRequestResponseMaxDelayOfClientTimer(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasRequestResponseMinDelayOfClientTimer(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasTTLOfClientTimer(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasCommonInitialDelay(partitionIndex)                                                    (Sd_GetCommonInitialDelayOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasConsumedEventgroup(partitionIndex)                                                    (Sd_GetConsumedEventgroupOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAutoRequireOfConsumedEventgroup(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasClientIdxOfConsumedEventgroup(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasClientTimerIdxOfConsumedEventgroup(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasEventGroupIdOfConsumedEventgroup(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasHandleIdOfConsumedEventgroup(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasMulticastEndpointAddrIdxOfConsumedEventgroup(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasMulticastEndpointAddrUsedOfConsumedEventgroup(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasMulticastSoConIdEndIdxOfConsumedEventgroup(partitionIndex)                            (TRUE != FALSE)
#define Sd_HasMulticastSoConIdStartIdxOfConsumedEventgroup(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasMulticastSoConIdUsedOfConsumedEventgroup(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasRoutingGroupMulticastActRefIdxOfConsumedEventgroup(partitionIndex)                    (TRUE != FALSE)
#define Sd_HasRoutingGroupMulticastActRefUsedOfConsumedEventgroup(partitionIndex)                   (TRUE != FALSE)
#define Sd_HasRoutingGroupTcpActRefIdxOfConsumedEventgroup(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasRoutingGroupTcpActRefUsedOfConsumedEventgroup(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasRoutingGroupUdpActRefIdxOfConsumedEventgroup(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasRoutingGroupUdpActRefUsedOfConsumedEventgroup(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasConsumedEventgroupDyn(partitionIndex)                                                 (Sd_GetConsumedEventgroupDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAcknowledgedTTLOfConsumedEventgroupDyn(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasCurrentStateOfConsumedEventgroupDyn(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasEventOfConsumedEventgroupDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasMulticastSoConIdOfConsumedEventgroupDyn(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasRxIndicationCountOfConsumedEventgroupDyn(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasServiceModeRequestOfConsumedEventgroupDyn(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasStateMachineOfConsumedEventgroupDyn(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasTcpSoConIdOfConsumedEventgroupDyn(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasTimerTTLOfConsumedEventgroupDyn(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasTriggerSubscriptionOfConsumedEventgroupDyn(partitionIndex)                            (TRUE != FALSE)
#define Sd_HasUdpSoConIdOfConsumedEventgroupDyn(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasConsumedEventgroupIdMap()                                                             (Sd_GetConsumedEventgroupIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfConsumedEventgroupIdMap()                                                 (TRUE != FALSE)
#define Sd_HasPartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap()                     (TRUE != FALSE)
#define Sd_HasPartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMap()            (TRUE != FALSE)
#define Sd_HasPartitionSpecificConsumedEventgroupUsedOfConsumedEventgroupIdMap()                    (TRUE != FALSE)
#define Sd_HasEndpointStorage(partitionIndex)                                                       (Sd_GetEndpointStorageOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddrOfEndpointStorage(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasNrOfReferencesOfEndpointStorage(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasTypeOfEndpointStorage(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasEventHandler(partitionIndex)                                                          (Sd_GetEventHandlerOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasClientListEndIdxOfEventHandler(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasClientListStartIdxOfEventHandler(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasEventGroupIdOfEventHandler(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasEventHandlerMulticastIdxOfEventHandler(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasEventHandlerMulticastUsedOfEventHandler(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasEventHandlerTcpIdxOfEventHandler(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasEventHandlerTcpUsedOfEventHandler(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasEventHandlerUdpIdxOfEventHandler(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasEventHandlerUdpUsedOfEventHandler(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasHandleIdOfEventHandler(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasMulticastThresholdOfEventHandler(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasServerIdxOfEventHandler(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasServerTimerIdxOfEventHandler(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasSoConActivationMapEndIdxOfEventHandler(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasSoConActivationMapStartIdxOfEventHandler(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSoConActivationMapUsedOfEventHandler(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasEventHandlerDyn(partitionIndex)                                                       (Sd_GetEventHandlerDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasNrOfClientsOfEventHandlerDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasRequestStateOfEventHandlerDyn(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasStateMachineOfEventHandlerDyn(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasEventHandlerMulticast(partitionIndex)                                                 (Sd_GetEventHandlerMulticastOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroupActRefIdxOfEventHandlerMulticast(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasRoutingGroupActRefUsedOfEventHandlerMulticast(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasSoConIdOfEventHandlerMulticast(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasEventHandlerTcp(partitionIndex)                                                       (Sd_GetEventHandlerTcpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroupActRefIdxOfEventHandlerTcp(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasRoutingGroupActRefUsedOfEventHandlerTcp(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasRoutingGroupTriggerIdxOfEventHandlerTcp(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasRoutingGroupTriggerUsedOfEventHandlerTcp(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasEventHandlerUdp(partitionIndex)                                                       (Sd_GetEventHandlerUdpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroupActRefIdxOfEventHandlerUdp(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasRoutingGroupActRefUsedOfEventHandlerUdp(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasRoutingGroupTriggerIdxOfEventHandlerUdp(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasRoutingGroupTriggerUsedOfEventHandlerUdp(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasInstance(partitionIndex)                                                              (Sd_GetInstanceOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAddressStorageEndIdxOfInstance(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAddressStorageStartIdxOfInstance(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasCapabilityRecordEndIdxOfInstance(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasCapabilityRecordStartIdxOfInstance(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasCapabilityRecordUsedOfInstance(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasClientEndIdxOfInstance(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasClientStartIdxOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasClientUsedOfInstance(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasEMalformedMsgIdOfInstance(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasENackRecvIdOfInstance(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasEOutOfResIdOfInstance(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasEndpointStorageEndIdxOfInstance(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasEndpointStorageStartIdxOfInstance(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasEventHandlerEndIdxOfInstance(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasEventHandlerStartIdxOfInstance(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasEventHandlerUsedOfInstance(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasLocalAddressCheckLengthOfInstance(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasMulticastRxPduIdOfInstance(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasMulticastRxSoConIdOfInstance(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasQueueProcessLimitOfInstance(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasRetryDelayOfInstance(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasRetryMaxOfInstance(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasRxEventEndIdxOfInstance(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasRxEventStartIdxOfInstance(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasRxEventUsedOfInstance(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSendEntryCapacityOfInstance(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSendEntryEndIdxOfInstance(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasSendEntryStartIdxOfInstance(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasServerEndIdxOfInstance(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasServerStartIdxOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasServerUsedOfInstance(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasSevDuplicateOfferOfInstance(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSevFailedMethodReqOfInstance(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasSevFailedOfferOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSevFailedSubOfInstance(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasTcpSoConIdEndIdxOfInstance(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasTcpSoConIdStartIdxOfInstance(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasTcpSoConIdUsedOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasTxPduIdOfInstance(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasTxSoConIdOfInstance(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasUdpSoConEndIdxOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasUdpSoConStartIdxOfInstance(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasUdpSoConUsedOfInstance(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasUnicastRxPduIdOfInstance(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasUnicastRxSoConIdOfInstance(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasInstanceDyn(partitionIndex)                                                           (Sd_GetInstanceDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasLastFoundEndpointOfInstanceDyn(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasNextStateMachineRunOfInstanceDyn(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasRunModeOfInstanceDyn(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasRxEventEndIdxOfInstanceDyn(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasRxEventListFullOfInstanceDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasRxEventStartIdxOfInstanceDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasSendEntryFreeListHeadIdxOfInstanceDyn(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSendEntryFreeListTailIdxOfInstanceDyn(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSendEntryNrPendingIdxOfInstanceDyn(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasStateOfInstanceDyn(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasIpAddrRequest(partitionIndex)                                                         (Sd_GetIpAddrRequestOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasPortSetIdxOfIpAddrRequest(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasRequestCntIdxOfIpAddrRequest(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasSoConIdOfIpAddrRequest(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasStaticIpConfigurationOfIpAddrRequest(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasStaticPortConfigurationOfIpAddrRequest(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasMaxNrOptionsPerEntry(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasMethod(partitionIndex)                                                                (Sd_GetMethodOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroupActRefIdxOfMethod(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasRoutingGroupActRefUsedOfMethod(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasTcpConfiguredOfMethod(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasUdpConfiguredOfMethod(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasMulticastEndpointAddr(partitionIndex)                                                 (Sd_GetMulticastEndpointAddrOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasMulticastSoConId(partitionIndex)                                                      (Sd_GetMulticastSoConIdOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasOptionIndex(partitionIndex)                                                           (Sd_GetOptionIndexOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasPartitionDataDyn(partitionIndex)                                                      (Sd_GetPartitionDataDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasInitializedOfPartitionDataDyn(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasNrOfOptionsOfPartitionDataDyn(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasRxIndicationCountOfPartitionDataDyn(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasTimeMsSinceStartOfPartitionDataDyn(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasTriggerTransmitDynEndIdxOfPartitionDataDyn(partitionIndex)                            (TRUE != FALSE)
#define Sd_HasTriggerTransmitDynStartIdxOfPartitionDataDyn(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasTriggerTransmitFullOfPartitionDataDyn(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasTxPathLockedOfPartitionDataDyn(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasPartitionIdentifiers()                                                                (Sd_GetPartitionIdentifiersOfPCConfig() != NULL_PTR)
#define Sd_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                          (TRUE != FALSE)
#define Sd_HasPartitionSNVOfPartitionIdentifiers()                                                  (TRUE != FALSE)
#define Sd_HasPayload(partitionIndex)                                                               (Sd_GetPayloadOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasPortSet(partitionIndex)                                                               (Sd_GetPortSetOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRequestCnt(partitionIndex)                                                            (Sd_GetRequestCntOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroup(partitionIndex)                                                          (Sd_GetRoutingGroupOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasRoutingGroupDyn(partitionIndex)                                                       (Sd_GetRoutingGroupDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasStatusOfRoutingGroupDyn(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasRoutingGroupIdMap()                                                                   (Sd_GetRoutingGroupIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfRoutingGroupIdMap()                                                       (TRUE != FALSE)
#define Sd_HasServerIdxOfRoutingGroupIdMap()                                                        (TRUE != FALSE)
#define Sd_HasServerPartitionIdxOfRoutingGroupIdMap()                                               (TRUE != FALSE)
#define Sd_HasServerUsedOfRoutingGroupIdMap()                                                       (TRUE != FALSE)
#define Sd_HasRxEvent(partitionIndex)                                                               (Sd_GetRxEventOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasClientListIdxOfRxEvent(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasEventHandlerIdxOfRxEvent(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasEventOfRxEvent(partitionIndex)                                                        (TRUE != FALSE)
#define Sd_HasRxPduIdMap()                                                                          (Sd_GetRxPduIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfRxPduIdMap()                                                              (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstanceIdxOfRxPduIdMap()                                            (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstancePartitionIdxOfRxPduIdMap()                                   (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstanceUsedOfRxPduIdMap()                                           (TRUE != FALSE)
#define Sd_HasSendEntry(partitionIndex)                                                             (Sd_GetSendEntryOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasClientIdxOfSendEntry(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasClientListIdxOfSendEntry(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasConsumedEventgroupIdxOfSendEntry(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasEntryTypeOfSendEntry(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasEventHandlerIdOfSendEntry(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasEventHandlerIdxOfSendEntry(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasInstanceIdOfSendEntry(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasInstanceIdxOfSendEntry(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasMajorVersionOfSendEntry(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasReservedFieldOfSendEntry(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSendEntryNextIdxOfSendEntry(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSendEntryPrevIdxOfSendEntry(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasServerIdxOfSendEntry(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasServiceIdOfSendEntry(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasServer(partitionIndex)                                                                (Sd_GetServerOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasAclIPv4SIndEndIdxOfServer(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasAclIPv4SIndStartIdxOfServer(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasAclIPv4SIndUsedOfServer(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasAclIPv6SIndEndIdxOfServer(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasAclIPv6SIndStartIdxOfServer(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasAclIPv6SIndUsedOfServer(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasAutoAvailableOfServer(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasCapabilityRecordEndIdxOfServer(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasCapabilityRecordFunctionCalloutPtrIdxOfServer(partitionIndex)                         (TRUE != FALSE)
#define Sd_HasCapabilityRecordFunctionCalloutPtrUsedOfServer(partitionIndex)                        (TRUE != FALSE)
#define Sd_HasCapabilityRecordStartIdxOfServer(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasCapabilityRecordUsedOfServer(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasCommonInitialDelayIdxOfServer(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasCommonInitialDelayUsedOfServer(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasEventHandlerEndIdxOfServer(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasEventHandlerStartIdxOfServer(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasEventHandlerUsedOfServer(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasHandleIdOfServer(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasInitialInstanceIdOfServer(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasInstanceIdxOfServer(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasMajorVersionOfServer(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasMethodIdxOfServer(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasMethodUsedOfServer(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasMinorVersionOfServer(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasServerTimerIdxOfServer(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasServiceGroupMemberOfServer(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasServiceIdOfServer(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSoConGrpDynTcpIdxOfServer(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasSoConGrpDynTcpUsedOfServer(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasSoConGrpDynUdpIdxOfServer(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasSoConGrpDynUdpUsedOfServer(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasTcpSoConIdEndIdxOfServer(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasTcpSoConIdStartIdxOfServer(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasTcpSoConIdUsedOfServer(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasUdpSoConEndIdxOfServer(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasUdpSoConStartIdxOfServer(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasUdpSoConUsedOfServer(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasServerDyn(partitionIndex)                                                             (Sd_GetServerDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasInitialOfferRepetitionRunOfServerDyn(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasInstanceIdOfServerDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasServiceGroupReqCounterOfServerDyn(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasStateMachineExecutionRequestedOfServerDyn(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasStateMachineOfServerDyn(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasStateSwcOfServerDyn(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasTimeToTriggerSendOfServerDyn(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasServerIdMap()                                                                         (Sd_GetServerIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfServerIdMap()                                                             (TRUE != FALSE)
#define Sd_HasPartitionSpecificServerIdxOfServerIdMap()                                             (TRUE != FALSE)
#define Sd_HasPartitionSpecificServerPartitionIdxOfServerIdMap()                                    (TRUE != FALSE)
#define Sd_HasPartitionSpecificServerUsedOfServerIdMap()                                            (TRUE != FALSE)
#define Sd_HasServerTimer(partitionIndex)                                                           (Sd_GetServerTimerOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasInitialOfferDelayMaxOfServerTimer(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasInitialOfferDelayMinOfServerTimer(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasInitialOfferRepetitionBaseDelayOfServerTimer(partitionIndex)                          (TRUE != FALSE)
#define Sd_HasInitialOfferRepetitionsMaxOfServerTimer(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasOfferCyclicDelayOfServerTimer(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasRequestResponseMaxDelayOfServerTimer(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasRequestResponseMinDelayOfServerTimer(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasTTLOfServerTimer(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasServiceGroup(partitionIndex)                                                          (Sd_GetServiceGroupOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasServiceGroupMemberEndIdxOfServiceGroup(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasServiceGroupMemberStartIdxOfServiceGroup(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasServiceGroupIdMap()                                                                   (Sd_GetServiceGroupIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfServiceGroupIdMap()                                                       (TRUE != FALSE)
#define Sd_HasPartitionSpecificServiceGroupIdxOfServiceGroupIdMap()                                 (TRUE != FALSE)
#define Sd_HasPartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMap()                        (TRUE != FALSE)
#define Sd_HasPartitionSpecificServiceGroupUsedOfServiceGroupIdMap()                                (TRUE != FALSE)
#define Sd_HasServiceGroupMember(partitionIndex)                                                    (Sd_GetServiceGroupMemberOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasClientIdxOfServiceGroupMember(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasClientUsedOfServiceGroupMember(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasServerIdxOfServiceGroupMember(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasServerUsedOfServiceGroupMember(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4CInd(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4SInd(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6CInd(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6SInd(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfAddressStorage(partitionIndex)                                                  (TRUE != FALSE)
#define Sd_HasSizeOfCapabilityRecord()                                                              (TRUE != FALSE)
#define Sd_HasSizeOfCapabilityRecordFunctionCalloutPtr()                                            (TRUE != FALSE)
#define Sd_HasSizeOfClient(partitionIndex)                                                          (TRUE != FALSE)
#define Sd_HasSizeOfClientDyn(partitionIndex)                                                       (TRUE != FALSE)
#define Sd_HasSizeOfClientIdMap()                                                                   (TRUE != FALSE)
#define Sd_HasSizeOfClientList(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasSizeOfClientTimer(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfCommonInitialDelay(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroup(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroupDyn(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroupIdMap()                                                       (TRUE != FALSE)
#define Sd_HasSizeOfEndpointStorage(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSizeOfEventHandler(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerMulticast(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerTcp(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerUdp(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSizeOfInstance(partitionIndex)                                                        (TRUE != FALSE)
#define Sd_HasSizeOfInstanceDyn(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfIpAddrRequest(partitionIndex)                                                   (TRUE != FALSE)
#define Sd_HasSizeOfMethod(partitionIndex)                                                          (TRUE != FALSE)
#define Sd_HasSizeOfMulticastEndpointAddr(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSizeOfMulticastSoConId(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasSizeOfOptionIndex(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfPartitionDataDyn(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasSizeOfPartitionIdentifiers()                                                          (TRUE != FALSE)
#define Sd_HasSizeOfPayload(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasSizeOfPortSet(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasSizeOfRequestCnt(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroup(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroupDyn(partitionIndex)                                                 (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroupIdMap()                                                             (TRUE != FALSE)
#define Sd_HasSizeOfRxEvent(partitionIndex)                                                         (TRUE != FALSE)
#define Sd_HasSizeOfRxPduIdMap()                                                                    (TRUE != FALSE)
#define Sd_HasSizeOfSendEntry(partitionIndex)                                                       (TRUE != FALSE)
#define Sd_HasSizeOfServer(partitionIndex)                                                          (TRUE != FALSE)
#define Sd_HasSizeOfServerDyn(partitionIndex)                                                       (TRUE != FALSE)
#define Sd_HasSizeOfServerIdMap()                                                                   (TRUE != FALSE)
#define Sd_HasSizeOfServerTimer(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroup(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroupIdMap()                                                             (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroupMember(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSizeOfSoConActivationMap(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSizeOfSoConGrpDyn(partitionIndex)                                                     (TRUE != FALSE)
#define Sd_HasSizeOfSoConModeDyn(partitionIndex)                                                    (TRUE != FALSE)
#define Sd_HasSizeOfSoConModeIdMap()                                                                (TRUE != FALSE)
#define Sd_HasSizeOfTcpSoConId(partitionIndex)                                                      (TRUE != FALSE)
#define Sd_HasSizeOfTriggerTransmitDyn(partitionIndex)                                              (TRUE != FALSE)
#define Sd_HasSizeOfTxSoConIdMap()                                                                  (TRUE != FALSE)
#define Sd_HasSizeOfUdpSoCon(partitionIndex)                                                        (TRUE != FALSE)
#define Sd_HasSoConActivationMap(partitionIndex)                                                    (Sd_GetSoConActivationMapOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasNrOfActivationsOfSoConActivationMap(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasSoConIdOfSoConActivationMap(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasSoConGrpDyn(partitionIndex)                                                           (Sd_GetSoConGrpDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasLocalPortOfSoConGrpDyn(partitionIndex)                                                (TRUE != FALSE)
#define Sd_HasSoConModeDyn(partitionIndex)                                                          (Sd_GetSoConModeDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasSoConModeIdMap()                                                                      (Sd_GetSoConModeIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfSoConModeIdMap()                                                          (TRUE != FALSE)
#define Sd_HasPartitionSpecificSoConModeIdxOfSoConModeIdMap()                                       (TRUE != FALSE)
#define Sd_HasPartitionSpecificSoConModePartitionIdxOfSoConModeIdMap()                              (TRUE != FALSE)
#define Sd_HasPartitionSpecificSoConModeUsedOfSoConModeIdMap()                                      (TRUE != FALSE)
#define Sd_HasTcpSoConId(partitionIndex)                                                            (Sd_GetTcpSoConIdOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasTriggerTransmitDyn(partitionIndex)                                                    (Sd_GetTriggerTransmitDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasClientListIdxOfTriggerTransmitDyn(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasEventHandlerIdxOfTriggerTransmitDyn(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasTxSoConIdMap()                                                                        (Sd_GetTxSoConIdMapOfPCPartitionConfig() != NULL_PTR)
#define Sd_HasInvalidHndOfTxSoConIdMap()                                                            (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstanceIdxOfTxSoConIdMap()                                          (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstancePartitionIdxOfTxSoConIdMap()                                 (TRUE != FALSE)
#define Sd_HasPartitionSpecificInstanceUsedOfTxSoConIdMap()                                         (TRUE != FALSE)
#define Sd_HasUdpSoCon(partitionIndex)                                                              (Sd_GetUdpSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define Sd_HasIdOfUdpSoCon(partitionIndex)                                                          (TRUE != FALSE)
#define Sd_HasPreconfiguredOfUdpSoCon(partitionIndex)                                               (TRUE != FALSE)
#define Sd_HasPCConfig()                                                                            (TRUE != FALSE)
#define Sd_HasPCPartitionConfigOfPCConfig()                                                         (TRUE != FALSE)
#define Sd_HasPartitionIdentifiersOfPCConfig()                                                      (TRUE != FALSE)
#define Sd_HasSizeOfPartitionIdentifiersOfPCConfig()                                                (TRUE != FALSE)
#define Sd_HasPCPartitionConfig()                                                                   (Sd_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define Sd_HasAclIPv4CIndOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAclIPv4OfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasAclIPv4SIndOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAclIPv6CIndOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAclIPv6OfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasAclIPv6SIndOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasAddressStorageOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()                               (TRUE != FALSE)
#define Sd_HasCapabilityRecordOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define Sd_HasClientDynOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasClientIdMapOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define Sd_HasClientListOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasClientOfPCPartitionConfig(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasClientTimerOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasCommonInitialDelayOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasConsumedEventgroupIdMapOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Sd_HasConsumedEventgroupOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasEndpointStorageOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasEventHandlerDynOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasEventHandlerMulticastOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasEventHandlerOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasEventHandlerTcpOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasEventHandlerUdpOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasInstanceDynOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasInstanceOfPCPartitionConfig(partitionIndex)                                           (TRUE != FALSE)
#define Sd_HasIpAddrRequestOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasMaxNrOptionsPerEntryOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasMethodOfPCPartitionConfig(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasMulticastSoConIdOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasOptionIndexOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasPartitionDataDynOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasPayloadOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasPortSetOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasRequestCntOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasRoutingGroupDynOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasRoutingGroupIdMapOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Sd_HasRoutingGroupOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasRxEventOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define Sd_HasRxPduIdMapOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define Sd_HasSendEntryOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasServerDynOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define Sd_HasServerIdMapOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define Sd_HasServerOfPCPartitionConfig(partitionIndex)                                             (TRUE != FALSE)
#define Sd_HasServerTimerOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasServiceGroupIdMapOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Sd_HasServiceGroupMemberOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasServiceGroupOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4CIndOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4OfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv4SIndOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6CIndOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6OfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSizeOfAclIPv6SIndOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfAddressStorageOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define Sd_HasSizeOfCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig()                         (TRUE != FALSE)
#define Sd_HasSizeOfCapabilityRecordOfPCPartitionConfig()                                           (TRUE != FALSE)
#define Sd_HasSizeOfClientDynOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasSizeOfClientIdMapOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Sd_HasSizeOfClientListOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasSizeOfClientOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasSizeOfClientTimerOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfCommonInitialDelayOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroupDynOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroupIdMapOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Sd_HasSizeOfConsumedEventgroupOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasSizeOfEndpointStorageOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerDynOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerMulticastOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerTcpOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSizeOfEventHandlerUdpOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfInstanceOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasSizeOfIpAddrRequestOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define Sd_HasSizeOfMethodOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasSizeOfMulticastEndpointAddrOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define Sd_HasSizeOfMulticastSoConIdOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasSizeOfOptionIndexOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfPartitionDataDynOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define Sd_HasSizeOfPayloadOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSizeOfPortSetOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSizeOfRequestCntOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroupDynOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroupIdMapOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Sd_HasSizeOfRoutingGroupOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSizeOfRxEventOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define Sd_HasSizeOfRxPduIdMapOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define Sd_HasSizeOfSendEntryOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasSizeOfServerDynOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Sd_HasSizeOfServerIdMapOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Sd_HasSizeOfServerOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasSizeOfServerTimerOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroupIdMapOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroupMemberOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasSizeOfServiceGroupOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSizeOfSoConActivationMapOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasSizeOfSoConGrpDynOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Sd_HasSizeOfSoConModeDynOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSizeOfSoConModeIdMapOfPCPartitionConfig()                                             (TRUE != FALSE)
#define Sd_HasSizeOfTcpSoConIdOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define Sd_HasSizeOfTriggerTransmitDynOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define Sd_HasSizeOfTxSoConIdMapOfPCPartitionConfig()                                               (TRUE != FALSE)
#define Sd_HasSizeOfUdpSoConOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define Sd_HasSoConActivationMapOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasSoConGrpDynOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Sd_HasSoConModeDynOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Sd_HasSoConModeIdMapOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define Sd_HasTcpSoConIdOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define Sd_HasTriggerTransmitDynOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Sd_HasTxSoConIdMapOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define Sd_HasUdpSoConOfPCPartitionConfig(partitionIndex)                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SdPCIncrementDataMacros  Sd Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Sd_IncFlagsOfAddressStorage(Index, partitionIndex)                                          Sd_GetFlagsOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncRxMulticastFlagsOfAddressStorage(Index, partitionIndex)                               Sd_GetRxMulticastFlagsOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncRxMulticastSessionIdOfAddressStorage(Index, partitionIndex)                           Sd_GetRxMulticastSessionIdOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncRxUnicastFlagsOfAddressStorage(Index, partitionIndex)                                 Sd_GetRxUnicastFlagsOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncRxUnicastSessionIdOfAddressStorage(Index, partitionIndex)                             Sd_GetRxUnicastSessionIdOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncSendEntryHeadIdxOfAddressStorage(Index, partitionIndex)                               Sd_GetSendEntryHeadIdxOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncSendEntryNrPendingIdxOfAddressStorage(Index, partitionIndex)                          Sd_GetSendEntryNrPendingIdxOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncSendEntryTailIdxOfAddressStorage(Index, partitionIndex)                               Sd_GetSendEntryTailIdxOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncSessionIdCounterOfAddressStorage(Index, partitionIndex)                               Sd_GetSessionIdCounterOfAddressStorage(((Index)), (partitionIndex))++
#define Sd_IncAddressStorageCurrentServerIdxOfClientDyn(Index, partitionIndex)                      Sd_GetAddressStorageCurrentServerIdxOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncAddressStorageServerIdxOfClientDyn(Index, partitionIndex)                             Sd_GetAddressStorageServerIdxOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncInstanceIdOfClientDyn(Index, partitionIndex)                                          Sd_GetInstanceIdOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncOfferedTTLOfClientDyn(Index, partitionIndex)                                          Sd_GetOfferedTTLOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncRepetitionRunOfClientDyn(Index, partitionIndex)                                       Sd_GetRepetitionRunOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncRetryCounterOfClientDyn(Index, partitionIndex)                                        Sd_GetRetryCounterOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncServiceGroupReqCounterOfClientDyn(Index, partitionIndex)                              Sd_GetServiceGroupReqCounterOfClientDyn(((Index)), (partitionIndex))++
#define Sd_IncAddressStorageIdxOfClientList(Index, partitionIndex)                                  Sd_GetAddressStorageIdxOfClientList(((Index)), (partitionIndex))++
#define Sd_IncEndpointStorageTcpIdxOfClientList(Index, partitionIndex)                              Sd_GetEndpointStorageTcpIdxOfClientList(((Index)), (partitionIndex))++
#define Sd_IncEndpointStorageUdpIdxOfClientList(Index, partitionIndex)                              Sd_GetEndpointStorageUdpIdxOfClientList(((Index)), (partitionIndex))++
#define Sd_IncNrOfReferencesOfClientList(Index, partitionIndex)                                     Sd_GetNrOfReferencesOfClientList(((Index)), (partitionIndex))++
#define Sd_IncRequestedTTLOfClientList(Index, partitionIndex)                                       Sd_GetRequestedTTLOfClientList(((Index)), (partitionIndex))++
#define Sd_IncRxReservedOfClientList(Index, partitionIndex)                                         Sd_GetRxReservedOfClientList(((Index)), (partitionIndex))++
#define Sd_IncCommonInitialDelay(Index, partitionIndex)                                             Sd_GetCommonInitialDelay(((Index)), (partitionIndex))++
#define Sd_IncAcknowledgedTTLOfConsumedEventgroupDyn(Index, partitionIndex)                         Sd_GetAcknowledgedTTLOfConsumedEventgroupDyn(((Index)), (partitionIndex))++
#define Sd_IncRxIndicationCountOfConsumedEventgroupDyn(Index, partitionIndex)                       Sd_GetRxIndicationCountOfConsumedEventgroupDyn(((Index)), (partitionIndex))++
#define Sd_IncNrOfReferencesOfEndpointStorage(Index, partitionIndex)                                Sd_GetNrOfReferencesOfEndpointStorage(((Index)), (partitionIndex))++
#define Sd_IncNrOfClientsOfEventHandlerDyn(Index, partitionIndex)                                   Sd_GetNrOfClientsOfEventHandlerDyn(((Index)), (partitionIndex))++
#define Sd_IncRxEventEndIdxOfInstanceDyn(Index, partitionIndex)                                     Sd_GetRxEventEndIdxOfInstanceDyn(((Index)), (partitionIndex))++
#define Sd_IncRxEventStartIdxOfInstanceDyn(Index, partitionIndex)                                   Sd_GetRxEventStartIdxOfInstanceDyn(((Index)), (partitionIndex))++
#define Sd_IncSendEntryFreeListHeadIdxOfInstanceDyn(Index, partitionIndex)                          Sd_GetSendEntryFreeListHeadIdxOfInstanceDyn(((Index)), (partitionIndex))++
#define Sd_IncSendEntryFreeListTailIdxOfInstanceDyn(Index, partitionIndex)                          Sd_GetSendEntryFreeListTailIdxOfInstanceDyn(((Index)), (partitionIndex))++
#define Sd_IncSendEntryNrPendingIdxOfInstanceDyn(Index, partitionIndex)                             Sd_GetSendEntryNrPendingIdxOfInstanceDyn(((Index)), (partitionIndex))++
#define Sd_IncOptionIndex(Index, partitionIndex)                                                    Sd_GetOptionIndex(((Index)), (partitionIndex))++
#define Sd_IncNrOfOptionsOfPartitionDataDyn(Index, partitionIndex)                                  Sd_GetNrOfOptionsOfPartitionDataDyn(((Index)), (partitionIndex))++
#define Sd_IncRxIndicationCountOfPartitionDataDyn(Index, partitionIndex)                            Sd_GetRxIndicationCountOfPartitionDataDyn(((Index)), (partitionIndex))++
#define Sd_IncTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, partitionIndex)                     Sd_GetTriggerTransmitDynEndIdxOfPartitionDataDyn(((Index)), (partitionIndex))++
#define Sd_IncTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, partitionIndex)                   Sd_GetTriggerTransmitDynStartIdxOfPartitionDataDyn(((Index)), (partitionIndex))++
#define Sd_IncPayload(Index, partitionIndex)                                                        Sd_GetPayload(((Index)), (partitionIndex))++
#define Sd_IncRequestCnt(Index, partitionIndex)                                                     Sd_GetRequestCnt(((Index)), (partitionIndex))++
#define Sd_IncClientListIdxOfRxEvent(Index, partitionIndex)                                         Sd_GetClientListIdxOfRxEvent(((Index)), (partitionIndex))++
#define Sd_IncEventHandlerIdxOfRxEvent(Index, partitionIndex)                                       Sd_GetEventHandlerIdxOfRxEvent(((Index)), (partitionIndex))++
#define Sd_IncClientIdxOfSendEntry(Index, partitionIndex)                                           Sd_GetClientIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncClientListIdxOfSendEntry(Index, partitionIndex)                                       Sd_GetClientListIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncConsumedEventgroupIdxOfSendEntry(Index, partitionIndex)                               Sd_GetConsumedEventgroupIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncEventHandlerIdOfSendEntry(Index, partitionIndex)                                      Sd_GetEventHandlerIdOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncEventHandlerIdxOfSendEntry(Index, partitionIndex)                                     Sd_GetEventHandlerIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncInstanceIdOfSendEntry(Index, partitionIndex)                                          Sd_GetInstanceIdOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncInstanceIdxOfSendEntry(Index, partitionIndex)                                         Sd_GetInstanceIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncMajorVersionOfSendEntry(Index, partitionIndex)                                        Sd_GetMajorVersionOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncReservedFieldOfSendEntry(Index, partitionIndex)                                       Sd_GetReservedFieldOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncSendEntryNextIdxOfSendEntry(Index, partitionIndex)                                    Sd_GetSendEntryNextIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncSendEntryPrevIdxOfSendEntry(Index, partitionIndex)                                    Sd_GetSendEntryPrevIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncServerIdxOfSendEntry(Index, partitionIndex)                                           Sd_GetServerIdxOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncServiceIdOfSendEntry(Index, partitionIndex)                                           Sd_GetServiceIdOfSendEntry(((Index)), (partitionIndex))++
#define Sd_IncInitialOfferRepetitionRunOfServerDyn(Index, partitionIndex)                           Sd_GetInitialOfferRepetitionRunOfServerDyn(((Index)), (partitionIndex))++
#define Sd_IncInstanceIdOfServerDyn(Index, partitionIndex)                                          Sd_GetInstanceIdOfServerDyn(((Index)), (partitionIndex))++
#define Sd_IncServiceGroupReqCounterOfServerDyn(Index, partitionIndex)                              Sd_GetServiceGroupReqCounterOfServerDyn(((Index)), (partitionIndex))++
#define Sd_IncNrOfActivationsOfSoConActivationMap(Index, partitionIndex)                            Sd_GetNrOfActivationsOfSoConActivationMap(((Index)), (partitionIndex))++
#define Sd_IncLocalPortOfSoConGrpDyn(Index, partitionIndex)                                         Sd_GetLocalPortOfSoConGrpDyn(((Index)), (partitionIndex))++
#define Sd_IncClientListIdxOfTriggerTransmitDyn(Index, partitionIndex)                              Sd_GetClientListIdxOfTriggerTransmitDyn(((Index)), (partitionIndex))++
#define Sd_IncEventHandlerIdxOfTriggerTransmitDyn(Index, partitionIndex)                            Sd_GetEventHandlerIdxOfTriggerTransmitDyn(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  SdPCDecrementDataMacros  Sd Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Sd_DecFlagsOfAddressStorage(Index, partitionIndex)                                          Sd_GetFlagsOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecRxMulticastFlagsOfAddressStorage(Index, partitionIndex)                               Sd_GetRxMulticastFlagsOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecRxMulticastSessionIdOfAddressStorage(Index, partitionIndex)                           Sd_GetRxMulticastSessionIdOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecRxUnicastFlagsOfAddressStorage(Index, partitionIndex)                                 Sd_GetRxUnicastFlagsOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecRxUnicastSessionIdOfAddressStorage(Index, partitionIndex)                             Sd_GetRxUnicastSessionIdOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecSendEntryHeadIdxOfAddressStorage(Index, partitionIndex)                               Sd_GetSendEntryHeadIdxOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecSendEntryNrPendingIdxOfAddressStorage(Index, partitionIndex)                          Sd_GetSendEntryNrPendingIdxOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecSendEntryTailIdxOfAddressStorage(Index, partitionIndex)                               Sd_GetSendEntryTailIdxOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecSessionIdCounterOfAddressStorage(Index, partitionIndex)                               Sd_GetSessionIdCounterOfAddressStorage(((Index)), (partitionIndex))--
#define Sd_DecAddressStorageCurrentServerIdxOfClientDyn(Index, partitionIndex)                      Sd_GetAddressStorageCurrentServerIdxOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecAddressStorageServerIdxOfClientDyn(Index, partitionIndex)                             Sd_GetAddressStorageServerIdxOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecInstanceIdOfClientDyn(Index, partitionIndex)                                          Sd_GetInstanceIdOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecOfferedTTLOfClientDyn(Index, partitionIndex)                                          Sd_GetOfferedTTLOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecRepetitionRunOfClientDyn(Index, partitionIndex)                                       Sd_GetRepetitionRunOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecRetryCounterOfClientDyn(Index, partitionIndex)                                        Sd_GetRetryCounterOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecServiceGroupReqCounterOfClientDyn(Index, partitionIndex)                              Sd_GetServiceGroupReqCounterOfClientDyn(((Index)), (partitionIndex))--
#define Sd_DecAddressStorageIdxOfClientList(Index, partitionIndex)                                  Sd_GetAddressStorageIdxOfClientList(((Index)), (partitionIndex))--
#define Sd_DecEndpointStorageTcpIdxOfClientList(Index, partitionIndex)                              Sd_GetEndpointStorageTcpIdxOfClientList(((Index)), (partitionIndex))--
#define Sd_DecEndpointStorageUdpIdxOfClientList(Index, partitionIndex)                              Sd_GetEndpointStorageUdpIdxOfClientList(((Index)), (partitionIndex))--
#define Sd_DecNrOfReferencesOfClientList(Index, partitionIndex)                                     Sd_GetNrOfReferencesOfClientList(((Index)), (partitionIndex))--
#define Sd_DecRequestedTTLOfClientList(Index, partitionIndex)                                       Sd_GetRequestedTTLOfClientList(((Index)), (partitionIndex))--
#define Sd_DecRxReservedOfClientList(Index, partitionIndex)                                         Sd_GetRxReservedOfClientList(((Index)), (partitionIndex))--
#define Sd_DecCommonInitialDelay(Index, partitionIndex)                                             Sd_GetCommonInitialDelay(((Index)), (partitionIndex))--
#define Sd_DecAcknowledgedTTLOfConsumedEventgroupDyn(Index, partitionIndex)                         Sd_GetAcknowledgedTTLOfConsumedEventgroupDyn(((Index)), (partitionIndex))--
#define Sd_DecRxIndicationCountOfConsumedEventgroupDyn(Index, partitionIndex)                       Sd_GetRxIndicationCountOfConsumedEventgroupDyn(((Index)), (partitionIndex))--
#define Sd_DecNrOfReferencesOfEndpointStorage(Index, partitionIndex)                                Sd_GetNrOfReferencesOfEndpointStorage(((Index)), (partitionIndex))--
#define Sd_DecNrOfClientsOfEventHandlerDyn(Index, partitionIndex)                                   Sd_GetNrOfClientsOfEventHandlerDyn(((Index)), (partitionIndex))--
#define Sd_DecRxEventEndIdxOfInstanceDyn(Index, partitionIndex)                                     Sd_GetRxEventEndIdxOfInstanceDyn(((Index)), (partitionIndex))--
#define Sd_DecRxEventStartIdxOfInstanceDyn(Index, partitionIndex)                                   Sd_GetRxEventStartIdxOfInstanceDyn(((Index)), (partitionIndex))--
#define Sd_DecSendEntryFreeListHeadIdxOfInstanceDyn(Index, partitionIndex)                          Sd_GetSendEntryFreeListHeadIdxOfInstanceDyn(((Index)), (partitionIndex))--
#define Sd_DecSendEntryFreeListTailIdxOfInstanceDyn(Index, partitionIndex)                          Sd_GetSendEntryFreeListTailIdxOfInstanceDyn(((Index)), (partitionIndex))--
#define Sd_DecSendEntryNrPendingIdxOfInstanceDyn(Index, partitionIndex)                             Sd_GetSendEntryNrPendingIdxOfInstanceDyn(((Index)), (partitionIndex))--
#define Sd_DecOptionIndex(Index, partitionIndex)                                                    Sd_GetOptionIndex(((Index)), (partitionIndex))--
#define Sd_DecNrOfOptionsOfPartitionDataDyn(Index, partitionIndex)                                  Sd_GetNrOfOptionsOfPartitionDataDyn(((Index)), (partitionIndex))--
#define Sd_DecRxIndicationCountOfPartitionDataDyn(Index, partitionIndex)                            Sd_GetRxIndicationCountOfPartitionDataDyn(((Index)), (partitionIndex))--
#define Sd_DecTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, partitionIndex)                     Sd_GetTriggerTransmitDynEndIdxOfPartitionDataDyn(((Index)), (partitionIndex))--
#define Sd_DecTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, partitionIndex)                   Sd_GetTriggerTransmitDynStartIdxOfPartitionDataDyn(((Index)), (partitionIndex))--
#define Sd_DecPayload(Index, partitionIndex)                                                        Sd_GetPayload(((Index)), (partitionIndex))--
#define Sd_DecRequestCnt(Index, partitionIndex)                                                     Sd_GetRequestCnt(((Index)), (partitionIndex))--
#define Sd_DecClientListIdxOfRxEvent(Index, partitionIndex)                                         Sd_GetClientListIdxOfRxEvent(((Index)), (partitionIndex))--
#define Sd_DecEventHandlerIdxOfRxEvent(Index, partitionIndex)                                       Sd_GetEventHandlerIdxOfRxEvent(((Index)), (partitionIndex))--
#define Sd_DecClientIdxOfSendEntry(Index, partitionIndex)                                           Sd_GetClientIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecClientListIdxOfSendEntry(Index, partitionIndex)                                       Sd_GetClientListIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecConsumedEventgroupIdxOfSendEntry(Index, partitionIndex)                               Sd_GetConsumedEventgroupIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecEventHandlerIdOfSendEntry(Index, partitionIndex)                                      Sd_GetEventHandlerIdOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecEventHandlerIdxOfSendEntry(Index, partitionIndex)                                     Sd_GetEventHandlerIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecInstanceIdOfSendEntry(Index, partitionIndex)                                          Sd_GetInstanceIdOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecInstanceIdxOfSendEntry(Index, partitionIndex)                                         Sd_GetInstanceIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecMajorVersionOfSendEntry(Index, partitionIndex)                                        Sd_GetMajorVersionOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecReservedFieldOfSendEntry(Index, partitionIndex)                                       Sd_GetReservedFieldOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecSendEntryNextIdxOfSendEntry(Index, partitionIndex)                                    Sd_GetSendEntryNextIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecSendEntryPrevIdxOfSendEntry(Index, partitionIndex)                                    Sd_GetSendEntryPrevIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecServerIdxOfSendEntry(Index, partitionIndex)                                           Sd_GetServerIdxOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecServiceIdOfSendEntry(Index, partitionIndex)                                           Sd_GetServiceIdOfSendEntry(((Index)), (partitionIndex))--
#define Sd_DecInitialOfferRepetitionRunOfServerDyn(Index, partitionIndex)                           Sd_GetInitialOfferRepetitionRunOfServerDyn(((Index)), (partitionIndex))--
#define Sd_DecInstanceIdOfServerDyn(Index, partitionIndex)                                          Sd_GetInstanceIdOfServerDyn(((Index)), (partitionIndex))--
#define Sd_DecServiceGroupReqCounterOfServerDyn(Index, partitionIndex)                              Sd_GetServiceGroupReqCounterOfServerDyn(((Index)), (partitionIndex))--
#define Sd_DecNrOfActivationsOfSoConActivationMap(Index, partitionIndex)                            Sd_GetNrOfActivationsOfSoConActivationMap(((Index)), (partitionIndex))--
#define Sd_DecLocalPortOfSoConGrpDyn(Index, partitionIndex)                                         Sd_GetLocalPortOfSoConGrpDyn(((Index)), (partitionIndex))--
#define Sd_DecClientListIdxOfTriggerTransmitDyn(Index, partitionIndex)                              Sd_GetClientListIdxOfTriggerTransmitDyn(((Index)), (partitionIndex))--
#define Sd_DecEventHandlerIdxOfTriggerTransmitDyn(Index, partitionIndex)                            Sd_GetEventHandlerIdxOfTriggerTransmitDyn(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  SdPCAddDataMacros  Sd Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Sd_AddFlagsOfAddressStorage(Index, Value, partitionIndex)                                   Sd_SetFlagsOfAddressStorage(Index, (Sd_GetFlagsOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxMulticastFlagsOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetRxMulticastFlagsOfAddressStorage(Index, (Sd_GetRxMulticastFlagsOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxMulticastSessionIdOfAddressStorage(Index, Value, partitionIndex)                    Sd_SetRxMulticastSessionIdOfAddressStorage(Index, (Sd_GetRxMulticastSessionIdOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxUnicastFlagsOfAddressStorage(Index, Value, partitionIndex)                          Sd_SetRxUnicastFlagsOfAddressStorage(Index, (Sd_GetRxUnicastFlagsOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxUnicastSessionIdOfAddressStorage(Index, Value, partitionIndex)                      Sd_SetRxUnicastSessionIdOfAddressStorage(Index, (Sd_GetRxUnicastSessionIdOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryHeadIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSendEntryHeadIdxOfAddressStorage(Index, (Sd_GetSendEntryHeadIdxOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryNrPendingIdxOfAddressStorage(Index, Value, partitionIndex)                   Sd_SetSendEntryNrPendingIdxOfAddressStorage(Index, (Sd_GetSendEntryNrPendingIdxOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryTailIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSendEntryTailIdxOfAddressStorage(Index, (Sd_GetSendEntryTailIdxOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSessionIdCounterOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSessionIdCounterOfAddressStorage(Index, (Sd_GetSessionIdCounterOfAddressStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddAddressStorageCurrentServerIdxOfClientDyn(Index, Value, partitionIndex)               Sd_SetAddressStorageCurrentServerIdxOfClientDyn(Index, (Sd_GetAddressStorageCurrentServerIdxOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddAddressStorageServerIdxOfClientDyn(Index, Value, partitionIndex)                      Sd_SetAddressStorageServerIdxOfClientDyn(Index, (Sd_GetAddressStorageServerIdxOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddInstanceIdOfClientDyn(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfClientDyn(Index, (Sd_GetInstanceIdOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddOfferedTTLOfClientDyn(Index, Value, partitionIndex)                                   Sd_SetOfferedTTLOfClientDyn(Index, (Sd_GetOfferedTTLOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRepetitionRunOfClientDyn(Index, Value, partitionIndex)                                Sd_SetRepetitionRunOfClientDyn(Index, (Sd_GetRepetitionRunOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRetryCounterOfClientDyn(Index, Value, partitionIndex)                                 Sd_SetRetryCounterOfClientDyn(Index, (Sd_GetRetryCounterOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddServiceGroupReqCounterOfClientDyn(Index, Value, partitionIndex)                       Sd_SetServiceGroupReqCounterOfClientDyn(Index, (Sd_GetServiceGroupReqCounterOfClientDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddAddressStorageIdxOfClientList(Index, Value, partitionIndex)                           Sd_SetAddressStorageIdxOfClientList(Index, (Sd_GetAddressStorageIdxOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEndpointStorageTcpIdxOfClientList(Index, Value, partitionIndex)                       Sd_SetEndpointStorageTcpIdxOfClientList(Index, (Sd_GetEndpointStorageTcpIdxOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEndpointStorageUdpIdxOfClientList(Index, Value, partitionIndex)                       Sd_SetEndpointStorageUdpIdxOfClientList(Index, (Sd_GetEndpointStorageUdpIdxOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddNrOfReferencesOfClientList(Index, Value, partitionIndex)                              Sd_SetNrOfReferencesOfClientList(Index, (Sd_GetNrOfReferencesOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRequestedTTLOfClientList(Index, Value, partitionIndex)                                Sd_SetRequestedTTLOfClientList(Index, (Sd_GetRequestedTTLOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxReservedOfClientList(Index, Value, partitionIndex)                                  Sd_SetRxReservedOfClientList(Index, (Sd_GetRxReservedOfClientList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddCommonInitialDelay(Index, Value, partitionIndex)                                      Sd_SetCommonInitialDelay(Index, (Sd_GetCommonInitialDelay(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddAcknowledgedTTLOfConsumedEventgroupDyn(Index, Value, partitionIndex)                  Sd_SetAcknowledgedTTLOfConsumedEventgroupDyn(Index, (Sd_GetAcknowledgedTTLOfConsumedEventgroupDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxIndicationCountOfConsumedEventgroupDyn(Index, Value, partitionIndex)                Sd_SetRxIndicationCountOfConsumedEventgroupDyn(Index, (Sd_GetRxIndicationCountOfConsumedEventgroupDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddNrOfReferencesOfEndpointStorage(Index, Value, partitionIndex)                         Sd_SetNrOfReferencesOfEndpointStorage(Index, (Sd_GetNrOfReferencesOfEndpointStorage(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddNrOfClientsOfEventHandlerDyn(Index, Value, partitionIndex)                            Sd_SetNrOfClientsOfEventHandlerDyn(Index, (Sd_GetNrOfClientsOfEventHandlerDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxEventEndIdxOfInstanceDyn(Index, Value, partitionIndex)                              Sd_SetRxEventEndIdxOfInstanceDyn(Index, (Sd_GetRxEventEndIdxOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxEventStartIdxOfInstanceDyn(Index, Value, partitionIndex)                            Sd_SetRxEventStartIdxOfInstanceDyn(Index, (Sd_GetRxEventStartIdxOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryFreeListHeadIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_SetSendEntryFreeListHeadIdxOfInstanceDyn(Index, (Sd_GetSendEntryFreeListHeadIdxOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryFreeListTailIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_SetSendEntryFreeListTailIdxOfInstanceDyn(Index, (Sd_GetSendEntryFreeListTailIdxOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryNrPendingIdxOfInstanceDyn(Index, Value, partitionIndex)                      Sd_SetSendEntryNrPendingIdxOfInstanceDyn(Index, (Sd_GetSendEntryNrPendingIdxOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddOptionIndex(Index, Value, partitionIndex)                                             Sd_SetOptionIndex(Index, (Sd_GetOptionIndex(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddNrOfOptionsOfPartitionDataDyn(Index, Value, partitionIndex)                           Sd_SetNrOfOptionsOfPartitionDataDyn(Index, (Sd_GetNrOfOptionsOfPartitionDataDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRxIndicationCountOfPartitionDataDyn(Index, Value, partitionIndex)                     Sd_SetRxIndicationCountOfPartitionDataDyn(Index, (Sd_GetRxIndicationCountOfPartitionDataDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, Value, partitionIndex)              Sd_SetTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, (Sd_GetTriggerTransmitDynEndIdxOfPartitionDataDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, Value, partitionIndex)            Sd_SetTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, (Sd_GetTriggerTransmitDynStartIdxOfPartitionDataDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddPayload(Index, Value, partitionIndex)                                                 Sd_SetPayload(Index, (Sd_GetPayload(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddRequestCnt(Index, Value, partitionIndex)                                              Sd_SetRequestCnt(Index, (Sd_GetRequestCnt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddClientListIdxOfRxEvent(Index, Value, partitionIndex)                                  Sd_SetClientListIdxOfRxEvent(Index, (Sd_GetClientListIdxOfRxEvent(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEventHandlerIdxOfRxEvent(Index, Value, partitionIndex)                                Sd_SetEventHandlerIdxOfRxEvent(Index, (Sd_GetEventHandlerIdxOfRxEvent(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddClientIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetClientIdxOfSendEntry(Index, (Sd_GetClientIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddClientListIdxOfSendEntry(Index, Value, partitionIndex)                                Sd_SetClientListIdxOfSendEntry(Index, (Sd_GetClientListIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddConsumedEventgroupIdxOfSendEntry(Index, Value, partitionIndex)                        Sd_SetConsumedEventgroupIdxOfSendEntry(Index, (Sd_GetConsumedEventgroupIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEventHandlerIdOfSendEntry(Index, Value, partitionIndex)                               Sd_SetEventHandlerIdOfSendEntry(Index, (Sd_GetEventHandlerIdOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEventHandlerIdxOfSendEntry(Index, Value, partitionIndex)                              Sd_SetEventHandlerIdxOfSendEntry(Index, (Sd_GetEventHandlerIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddInstanceIdOfSendEntry(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfSendEntry(Index, (Sd_GetInstanceIdOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddInstanceIdxOfSendEntry(Index, Value, partitionIndex)                                  Sd_SetInstanceIdxOfSendEntry(Index, (Sd_GetInstanceIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddMajorVersionOfSendEntry(Index, Value, partitionIndex)                                 Sd_SetMajorVersionOfSendEntry(Index, (Sd_GetMajorVersionOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddReservedFieldOfSendEntry(Index, Value, partitionIndex)                                Sd_SetReservedFieldOfSendEntry(Index, (Sd_GetReservedFieldOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryNextIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_SetSendEntryNextIdxOfSendEntry(Index, (Sd_GetSendEntryNextIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddSendEntryPrevIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_SetSendEntryPrevIdxOfSendEntry(Index, (Sd_GetSendEntryPrevIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddServerIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetServerIdxOfSendEntry(Index, (Sd_GetServerIdxOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddServiceIdOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetServiceIdOfSendEntry(Index, (Sd_GetServiceIdOfSendEntry(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddInitialOfferRepetitionRunOfServerDyn(Index, Value, partitionIndex)                    Sd_SetInitialOfferRepetitionRunOfServerDyn(Index, (Sd_GetInitialOfferRepetitionRunOfServerDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddInstanceIdOfServerDyn(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfServerDyn(Index, (Sd_GetInstanceIdOfServerDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddServiceGroupReqCounterOfServerDyn(Index, Value, partitionIndex)                       Sd_SetServiceGroupReqCounterOfServerDyn(Index, (Sd_GetServiceGroupReqCounterOfServerDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddNrOfActivationsOfSoConActivationMap(Index, Value, partitionIndex)                     Sd_SetNrOfActivationsOfSoConActivationMap(Index, (Sd_GetNrOfActivationsOfSoConActivationMap(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddLocalPortOfSoConGrpDyn(Index, Value, partitionIndex)                                  Sd_SetLocalPortOfSoConGrpDyn(Index, (Sd_GetLocalPortOfSoConGrpDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddClientListIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                       Sd_SetClientListIdxOfTriggerTransmitDyn(Index, (Sd_GetClientListIdxOfTriggerTransmitDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Sd_AddEventHandlerIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                     Sd_SetEventHandlerIdxOfTriggerTransmitDyn(Index, (Sd_GetEventHandlerIdxOfTriggerTransmitDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  SdPCSubstractDataMacros  Sd Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Sd_SubFlagsOfAddressStorage(Index, Value, partitionIndex)                                   Sd_SetFlagsOfAddressStorage(Index, (Sd_GetFlagsOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxMulticastFlagsOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetRxMulticastFlagsOfAddressStorage(Index, (Sd_GetRxMulticastFlagsOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxMulticastSessionIdOfAddressStorage(Index, Value, partitionIndex)                    Sd_SetRxMulticastSessionIdOfAddressStorage(Index, (Sd_GetRxMulticastSessionIdOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxUnicastFlagsOfAddressStorage(Index, Value, partitionIndex)                          Sd_SetRxUnicastFlagsOfAddressStorage(Index, (Sd_GetRxUnicastFlagsOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxUnicastSessionIdOfAddressStorage(Index, Value, partitionIndex)                      Sd_SetRxUnicastSessionIdOfAddressStorage(Index, (Sd_GetRxUnicastSessionIdOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryHeadIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSendEntryHeadIdxOfAddressStorage(Index, (Sd_GetSendEntryHeadIdxOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryNrPendingIdxOfAddressStorage(Index, Value, partitionIndex)                   Sd_SetSendEntryNrPendingIdxOfAddressStorage(Index, (Sd_GetSendEntryNrPendingIdxOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryTailIdxOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSendEntryTailIdxOfAddressStorage(Index, (Sd_GetSendEntryTailIdxOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSessionIdCounterOfAddressStorage(Index, Value, partitionIndex)                        Sd_SetSessionIdCounterOfAddressStorage(Index, (Sd_GetSessionIdCounterOfAddressStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubAddressStorageCurrentServerIdxOfClientDyn(Index, Value, partitionIndex)               Sd_SetAddressStorageCurrentServerIdxOfClientDyn(Index, (Sd_GetAddressStorageCurrentServerIdxOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubAddressStorageServerIdxOfClientDyn(Index, Value, partitionIndex)                      Sd_SetAddressStorageServerIdxOfClientDyn(Index, (Sd_GetAddressStorageServerIdxOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubInstanceIdOfClientDyn(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfClientDyn(Index, (Sd_GetInstanceIdOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubOfferedTTLOfClientDyn(Index, Value, partitionIndex)                                   Sd_SetOfferedTTLOfClientDyn(Index, (Sd_GetOfferedTTLOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRepetitionRunOfClientDyn(Index, Value, partitionIndex)                                Sd_SetRepetitionRunOfClientDyn(Index, (Sd_GetRepetitionRunOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRetryCounterOfClientDyn(Index, Value, partitionIndex)                                 Sd_SetRetryCounterOfClientDyn(Index, (Sd_GetRetryCounterOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubServiceGroupReqCounterOfClientDyn(Index, Value, partitionIndex)                       Sd_SetServiceGroupReqCounterOfClientDyn(Index, (Sd_GetServiceGroupReqCounterOfClientDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubAddressStorageIdxOfClientList(Index, Value, partitionIndex)                           Sd_SetAddressStorageIdxOfClientList(Index, (Sd_GetAddressStorageIdxOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEndpointStorageTcpIdxOfClientList(Index, Value, partitionIndex)                       Sd_SetEndpointStorageTcpIdxOfClientList(Index, (Sd_GetEndpointStorageTcpIdxOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEndpointStorageUdpIdxOfClientList(Index, Value, partitionIndex)                       Sd_SetEndpointStorageUdpIdxOfClientList(Index, (Sd_GetEndpointStorageUdpIdxOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubNrOfReferencesOfClientList(Index, Value, partitionIndex)                              Sd_SetNrOfReferencesOfClientList(Index, (Sd_GetNrOfReferencesOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRequestedTTLOfClientList(Index, Value, partitionIndex)                                Sd_SetRequestedTTLOfClientList(Index, (Sd_GetRequestedTTLOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxReservedOfClientList(Index, Value, partitionIndex)                                  Sd_SetRxReservedOfClientList(Index, (Sd_GetRxReservedOfClientList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubCommonInitialDelay(Index, Value, partitionIndex)                                      Sd_SetCommonInitialDelay(Index, (Sd_GetCommonInitialDelay(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubAcknowledgedTTLOfConsumedEventgroupDyn(Index, Value, partitionIndex)                  Sd_SetAcknowledgedTTLOfConsumedEventgroupDyn(Index, (Sd_GetAcknowledgedTTLOfConsumedEventgroupDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxIndicationCountOfConsumedEventgroupDyn(Index, Value, partitionIndex)                Sd_SetRxIndicationCountOfConsumedEventgroupDyn(Index, (Sd_GetRxIndicationCountOfConsumedEventgroupDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubNrOfReferencesOfEndpointStorage(Index, Value, partitionIndex)                         Sd_SetNrOfReferencesOfEndpointStorage(Index, (Sd_GetNrOfReferencesOfEndpointStorage(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubNrOfClientsOfEventHandlerDyn(Index, Value, partitionIndex)                            Sd_SetNrOfClientsOfEventHandlerDyn(Index, (Sd_GetNrOfClientsOfEventHandlerDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxEventEndIdxOfInstanceDyn(Index, Value, partitionIndex)                              Sd_SetRxEventEndIdxOfInstanceDyn(Index, (Sd_GetRxEventEndIdxOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxEventStartIdxOfInstanceDyn(Index, Value, partitionIndex)                            Sd_SetRxEventStartIdxOfInstanceDyn(Index, (Sd_GetRxEventStartIdxOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryFreeListHeadIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_SetSendEntryFreeListHeadIdxOfInstanceDyn(Index, (Sd_GetSendEntryFreeListHeadIdxOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryFreeListTailIdxOfInstanceDyn(Index, Value, partitionIndex)                   Sd_SetSendEntryFreeListTailIdxOfInstanceDyn(Index, (Sd_GetSendEntryFreeListTailIdxOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryNrPendingIdxOfInstanceDyn(Index, Value, partitionIndex)                      Sd_SetSendEntryNrPendingIdxOfInstanceDyn(Index, (Sd_GetSendEntryNrPendingIdxOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubOptionIndex(Index, Value, partitionIndex)                                             Sd_SetOptionIndex(Index, (Sd_GetOptionIndex(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubNrOfOptionsOfPartitionDataDyn(Index, Value, partitionIndex)                           Sd_SetNrOfOptionsOfPartitionDataDyn(Index, (Sd_GetNrOfOptionsOfPartitionDataDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRxIndicationCountOfPartitionDataDyn(Index, Value, partitionIndex)                     Sd_SetRxIndicationCountOfPartitionDataDyn(Index, (Sd_GetRxIndicationCountOfPartitionDataDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, Value, partitionIndex)              Sd_SetTriggerTransmitDynEndIdxOfPartitionDataDyn(Index, (Sd_GetTriggerTransmitDynEndIdxOfPartitionDataDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, Value, partitionIndex)            Sd_SetTriggerTransmitDynStartIdxOfPartitionDataDyn(Index, (Sd_GetTriggerTransmitDynStartIdxOfPartitionDataDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubPayload(Index, Value, partitionIndex)                                                 Sd_SetPayload(Index, (Sd_GetPayload(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubRequestCnt(Index, Value, partitionIndex)                                              Sd_SetRequestCnt(Index, (Sd_GetRequestCnt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubClientListIdxOfRxEvent(Index, Value, partitionIndex)                                  Sd_SetClientListIdxOfRxEvent(Index, (Sd_GetClientListIdxOfRxEvent(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEventHandlerIdxOfRxEvent(Index, Value, partitionIndex)                                Sd_SetEventHandlerIdxOfRxEvent(Index, (Sd_GetEventHandlerIdxOfRxEvent(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubClientIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetClientIdxOfSendEntry(Index, (Sd_GetClientIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubClientListIdxOfSendEntry(Index, Value, partitionIndex)                                Sd_SetClientListIdxOfSendEntry(Index, (Sd_GetClientListIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubConsumedEventgroupIdxOfSendEntry(Index, Value, partitionIndex)                        Sd_SetConsumedEventgroupIdxOfSendEntry(Index, (Sd_GetConsumedEventgroupIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEventHandlerIdOfSendEntry(Index, Value, partitionIndex)                               Sd_SetEventHandlerIdOfSendEntry(Index, (Sd_GetEventHandlerIdOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEventHandlerIdxOfSendEntry(Index, Value, partitionIndex)                              Sd_SetEventHandlerIdxOfSendEntry(Index, (Sd_GetEventHandlerIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubInstanceIdOfSendEntry(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfSendEntry(Index, (Sd_GetInstanceIdOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubInstanceIdxOfSendEntry(Index, Value, partitionIndex)                                  Sd_SetInstanceIdxOfSendEntry(Index, (Sd_GetInstanceIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubMajorVersionOfSendEntry(Index, Value, partitionIndex)                                 Sd_SetMajorVersionOfSendEntry(Index, (Sd_GetMajorVersionOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubReservedFieldOfSendEntry(Index, Value, partitionIndex)                                Sd_SetReservedFieldOfSendEntry(Index, (Sd_GetReservedFieldOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryNextIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_SetSendEntryNextIdxOfSendEntry(Index, (Sd_GetSendEntryNextIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubSendEntryPrevIdxOfSendEntry(Index, Value, partitionIndex)                             Sd_SetSendEntryPrevIdxOfSendEntry(Index, (Sd_GetSendEntryPrevIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubServerIdxOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetServerIdxOfSendEntry(Index, (Sd_GetServerIdxOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubServiceIdOfSendEntry(Index, Value, partitionIndex)                                    Sd_SetServiceIdOfSendEntry(Index, (Sd_GetServiceIdOfSendEntry(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubInitialOfferRepetitionRunOfServerDyn(Index, Value, partitionIndex)                    Sd_SetInitialOfferRepetitionRunOfServerDyn(Index, (Sd_GetInitialOfferRepetitionRunOfServerDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubInstanceIdOfServerDyn(Index, Value, partitionIndex)                                   Sd_SetInstanceIdOfServerDyn(Index, (Sd_GetInstanceIdOfServerDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubServiceGroupReqCounterOfServerDyn(Index, Value, partitionIndex)                       Sd_SetServiceGroupReqCounterOfServerDyn(Index, (Sd_GetServiceGroupReqCounterOfServerDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubNrOfActivationsOfSoConActivationMap(Index, Value, partitionIndex)                     Sd_SetNrOfActivationsOfSoConActivationMap(Index, (Sd_GetNrOfActivationsOfSoConActivationMap(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubLocalPortOfSoConGrpDyn(Index, Value, partitionIndex)                                  Sd_SetLocalPortOfSoConGrpDyn(Index, (Sd_GetLocalPortOfSoConGrpDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubClientListIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                       Sd_SetClientListIdxOfTriggerTransmitDyn(Index, (Sd_GetClientListIdxOfTriggerTransmitDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Sd_SubEventHandlerIdxOfTriggerTransmitDyn(Index, Value, partitionIndex)                     Sd_SetEventHandlerIdxOfTriggerTransmitDyn(Index, (Sd_GetEventHandlerIdxOfTriggerTransmitDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
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


#if(!defined(SD_SIZEOFADDRESSSTORAGE))
typedef uint8 Sd_SizeOfAddressStorageType;
#endif
#if(!defined(SD_SIZEOFCAPABILITYRECORD))
typedef uint8 Sd_SizeOfCapabilityRecordType;
#endif
#if(!defined(SD_SIZEOFCLIENTLIST))
typedef uint8 Sd_SizeOfClientListType;
# define Sd_GetSizeOfClientList() 0u
#endif
#if(!defined(SD_SIZEOFCLIENT))
typedef uint8 Sd_SizeOfClientType;
# define Sd_GetSizeOfClient() 0u
#endif
#if(!defined(SD_SIZEOFCONSUMEDEVENTGROUP))
typedef uint8 Sd_SizeOfConsumedEventgroupType;
# define Sd_GetSizeOfConsumedEventgroup() 0u
#endif
#if(!defined(SD_SIZEOFENDPOINTSTORAGE))
typedef uint8 Sd_SizeOfEndpointStorageType;
#endif
#if(!defined(SD_SIZEOFEVENTHANDLER))
typedef uint8 Sd_SizeOfEventHandlerType;
# define Sd_GetSizeOfEventHandler() 0u
#endif
#if(!defined(SD_SIZEOFINSTANCE))
typedef uint8 Sd_SizeOfInstanceType;
#endif
#if(!defined(SD_SIZEOFMULTICASTSOCONID))
typedef uint8 Sd_SizeOfMulticastSoConIdType;
#endif
#if(!defined(SD_SIZEOFPAYLOAD))
typedef uint8 Sd_SizeOfPayloadType;
#endif
#if(!defined(SD_SIZEOFRXEVENT))
typedef uint8 Sd_SizeOfRxEventType;
#endif
#if(!defined(SD_SIZEOFSENDENTRY))
typedef uint8 Sd_SizeOfSendEntryType;
#endif
#if(!defined(SD_SIZEOFSERVERTIMER))
typedef uint8 Sd_SizeOfServerTimerType;
#endif
#if(!defined(SD_SIZEOFSERVER))
typedef uint8 Sd_SizeOfServerType;
# define Sd_GetSizeOfServer() 0u
#endif
#if(SD_SOCONACTIVATIONMAP == STD_OFF)
typedef uint8 Sd_SizeOfSoConActivationMapType;
#endif
#if(!defined(SD_SIZEOFTRIGGERTRANSMIT))
typedef uint8 Sd_SizeOfTriggerTransmitType;
#endif

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#if !defined (SD_LOCAL_INLINE)
# define SD_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  SdPCSizeOfTypes  Sd SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Sd_SizeOfAclIPv4 */
typedef uint8 Sd_SizeOfAclIPv4Type;

/**   \brief  value based type definition for Sd_SizeOfAclIPv4CInd */
typedef uint8 Sd_SizeOfAclIPv4CIndType;

/**   \brief  value based type definition for Sd_SizeOfAclIPv4SInd */
typedef uint8 Sd_SizeOfAclIPv4SIndType;

/**   \brief  value based type definition for Sd_SizeOfAclIPv6 */
typedef uint8 Sd_SizeOfAclIPv6Type;

/**   \brief  value based type definition for Sd_SizeOfAclIPv6CInd */
typedef uint8 Sd_SizeOfAclIPv6CIndType;

/**   \brief  value based type definition for Sd_SizeOfAclIPv6SInd */
typedef uint8 Sd_SizeOfAclIPv6SIndType;

/**   \brief  value based type definition for Sd_SizeOfAddressStorage */
typedef uint8 Sd_SizeOfAddressStorageType;

/**   \brief  value based type definition for Sd_SizeOfCapabilityRecord */
typedef uint8 Sd_SizeOfCapabilityRecordType;

/**   \brief  value based type definition for Sd_SizeOfCapabilityRecordFunctionCalloutPtr */
typedef uint8 Sd_SizeOfCapabilityRecordFunctionCalloutPtrType;

/**   \brief  value based type definition for Sd_SizeOfClient */
typedef uint8 Sd_SizeOfClientType;

/**   \brief  value based type definition for Sd_SizeOfClientDyn */
typedef uint8 Sd_SizeOfClientDynType;

/**   \brief  value based type definition for Sd_SizeOfClientIdMap */
typedef uint8 Sd_SizeOfClientIdMapType;

/**   \brief  value based type definition for Sd_SizeOfClientList */
typedef uint8 Sd_SizeOfClientListType;

/**   \brief  value based type definition for Sd_SizeOfClientTimer */
typedef uint8 Sd_SizeOfClientTimerType;

/**   \brief  value based type definition for Sd_SizeOfCommonInitialDelay */
typedef uint8 Sd_SizeOfCommonInitialDelayType;

/**   \brief  value based type definition for Sd_SizeOfConsumedEventgroup */
typedef uint8 Sd_SizeOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_SizeOfConsumedEventgroupDyn */
typedef uint8 Sd_SizeOfConsumedEventgroupDynType;

/**   \brief  value based type definition for Sd_SizeOfConsumedEventgroupIdMap */
typedef uint8 Sd_SizeOfConsumedEventgroupIdMapType;

/**   \brief  value based type definition for Sd_SizeOfEndpointStorage */
typedef uint8 Sd_SizeOfEndpointStorageType;

/**   \brief  value based type definition for Sd_SizeOfEventHandler */
typedef uint8 Sd_SizeOfEventHandlerType;

/**   \brief  value based type definition for Sd_SizeOfEventHandlerDyn */
typedef uint8 Sd_SizeOfEventHandlerDynType;

/**   \brief  value based type definition for Sd_SizeOfEventHandlerMulticast */
typedef uint8 Sd_SizeOfEventHandlerMulticastType;

/**   \brief  value based type definition for Sd_SizeOfEventHandlerTcp */
typedef uint8 Sd_SizeOfEventHandlerTcpType;

/**   \brief  value based type definition for Sd_SizeOfEventHandlerUdp */
typedef uint8 Sd_SizeOfEventHandlerUdpType;

/**   \brief  value based type definition for Sd_SizeOfInstance */
typedef uint8 Sd_SizeOfInstanceType;

/**   \brief  value based type definition for Sd_SizeOfInstanceDyn */
typedef uint8 Sd_SizeOfInstanceDynType;

/**   \brief  value based type definition for Sd_SizeOfIpAddrRequest */
typedef uint8 Sd_SizeOfIpAddrRequestType;

/**   \brief  value based type definition for Sd_SizeOfMethod */
typedef uint8 Sd_SizeOfMethodType;

/**   \brief  value based type definition for Sd_SizeOfMulticastEndpointAddr */
typedef uint8 Sd_SizeOfMulticastEndpointAddrType;

/**   \brief  value based type definition for Sd_SizeOfMulticastSoConId */
typedef uint8 Sd_SizeOfMulticastSoConIdType;

/**   \brief  value based type definition for Sd_SizeOfOptionIndex */
typedef uint8 Sd_SizeOfOptionIndexType;

/**   \brief  value based type definition for Sd_SizeOfPartitionDataDyn */
typedef uint8 Sd_SizeOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_SizeOfPartitionIdentifiers */
typedef uint8 Sd_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for Sd_SizeOfPayload */
typedef uint16 Sd_SizeOfPayloadType;

/**   \brief  value based type definition for Sd_SizeOfPortSet */
typedef uint8 Sd_SizeOfPortSetType;

/**   \brief  value based type definition for Sd_SizeOfRequestCnt */
typedef uint8 Sd_SizeOfRequestCntType;

/**   \brief  value based type definition for Sd_SizeOfRoutingGroup */
typedef uint8 Sd_SizeOfRoutingGroupType;

/**   \brief  value based type definition for Sd_SizeOfRoutingGroupDyn */
typedef uint8 Sd_SizeOfRoutingGroupDynType;

/**   \brief  value based type definition for Sd_SizeOfRoutingGroupIdMap */
typedef uint8 Sd_SizeOfRoutingGroupIdMapType;

/**   \brief  value based type definition for Sd_SizeOfRxEvent */
typedef uint8 Sd_SizeOfRxEventType;

/**   \brief  value based type definition for Sd_SizeOfRxPduIdMap */
typedef uint8 Sd_SizeOfRxPduIdMapType;

/**   \brief  value based type definition for Sd_SizeOfSendEntry */
typedef uint8 Sd_SizeOfSendEntryType;

/**   \brief  value based type definition for Sd_SizeOfServer */
typedef uint8 Sd_SizeOfServerType;

/**   \brief  value based type definition for Sd_SizeOfServerDyn */
typedef uint8 Sd_SizeOfServerDynType;

/**   \brief  value based type definition for Sd_SizeOfServerIdMap */
typedef uint8 Sd_SizeOfServerIdMapType;

/**   \brief  value based type definition for Sd_SizeOfServerTimer */
typedef uint8 Sd_SizeOfServerTimerType;

/**   \brief  value based type definition for Sd_SizeOfServiceGroup */
typedef uint8 Sd_SizeOfServiceGroupType;

/**   \brief  value based type definition for Sd_SizeOfServiceGroupIdMap */
typedef uint8 Sd_SizeOfServiceGroupIdMapType;

/**   \brief  value based type definition for Sd_SizeOfServiceGroupMember */
typedef uint8 Sd_SizeOfServiceGroupMemberType;

/**   \brief  value based type definition for Sd_SizeOfSoConActivationMap */
typedef uint8 Sd_SizeOfSoConActivationMapType;

/**   \brief  value based type definition for Sd_SizeOfSoConGrpDyn */
typedef uint8 Sd_SizeOfSoConGrpDynType;

/**   \brief  value based type definition for Sd_SizeOfSoConModeDyn */
typedef uint8 Sd_SizeOfSoConModeDynType;

/**   \brief  value based type definition for Sd_SizeOfSoConModeIdMap */
typedef uint8 Sd_SizeOfSoConModeIdMapType;

/**   \brief  value based type definition for Sd_SizeOfTcpSoConId */
typedef uint8 Sd_SizeOfTcpSoConIdType;

/**   \brief  value based type definition for Sd_SizeOfTriggerTransmitDyn */
typedef uint8 Sd_SizeOfTriggerTransmitDynType;

/**   \brief  value based type definition for Sd_SizeOfTxSoConIdMap */
typedef uint8 Sd_SizeOfTxSoConIdMapType;

/**   \brief  value based type definition for Sd_SizeOfUdpSoCon */
typedef uint8 Sd_SizeOfUdpSoConType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SdPCIterableTypes  Sd Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Sd_AclIPv4 */
typedef uint8_least Sd_AclIPv4IterType;

/**   \brief  type used to iterate Sd_AclIPv4CInd */
typedef uint8_least Sd_AclIPv4CIndIterType;

/**   \brief  type used to iterate Sd_AclIPv4SInd */
typedef uint8_least Sd_AclIPv4SIndIterType;

/**   \brief  type used to iterate Sd_AclIPv6 */
typedef uint8_least Sd_AclIPv6IterType;

/**   \brief  type used to iterate Sd_AclIPv6CInd */
typedef uint8_least Sd_AclIPv6CIndIterType;

/**   \brief  type used to iterate Sd_AclIPv6SInd */
typedef uint8_least Sd_AclIPv6SIndIterType;

/**   \brief  type used to iterate Sd_AddressStorage */
typedef uint8_least Sd_AddressStorageIterType;

/**   \brief  type used to iterate Sd_CapabilityRecord */
typedef uint8_least Sd_CapabilityRecordIterType;

/**   \brief  type used to iterate Sd_CapabilityRecordFunctionCalloutPtr */
typedef uint8_least Sd_CapabilityRecordFunctionCalloutPtrIterType;

/**   \brief  type used to iterate Sd_Client */
typedef uint8_least Sd_ClientIterType;

/**   \brief  type used to iterate Sd_ClientIdMap */
typedef uint8_least Sd_ClientIdMapIterType;

/**   \brief  type used to iterate Sd_ClientList */
typedef uint8_least Sd_ClientListIterType;

/**   \brief  type used to iterate Sd_ClientTimer */
typedef uint8_least Sd_ClientTimerIterType;

/**   \brief  type used to iterate Sd_CommonInitialDelay */
typedef uint8_least Sd_CommonInitialDelayIterType;

/**   \brief  type used to iterate Sd_ConsumedEventgroup */
typedef uint8_least Sd_ConsumedEventgroupIterType;

/**   \brief  type used to iterate Sd_ConsumedEventgroupIdMap */
typedef uint8_least Sd_ConsumedEventgroupIdMapIterType;

/**   \brief  type used to iterate Sd_EndpointStorage */
typedef uint8_least Sd_EndpointStorageIterType;

/**   \brief  type used to iterate Sd_EventHandler */
typedef uint8_least Sd_EventHandlerIterType;

/**   \brief  type used to iterate Sd_EventHandlerMulticast */
typedef uint8_least Sd_EventHandlerMulticastIterType;

/**   \brief  type used to iterate Sd_EventHandlerTcp */
typedef uint8_least Sd_EventHandlerTcpIterType;

/**   \brief  type used to iterate Sd_EventHandlerUdp */
typedef uint8_least Sd_EventHandlerUdpIterType;

/**   \brief  type used to iterate Sd_Instance */
typedef uint8_least Sd_InstanceIterType;

/**   \brief  type used to iterate Sd_IpAddrRequest */
typedef uint8_least Sd_IpAddrRequestIterType;

/**   \brief  type used to iterate Sd_Method */
typedef uint8_least Sd_MethodIterType;

/**   \brief  type used to iterate Sd_MulticastEndpointAddr */
typedef uint8_least Sd_MulticastEndpointAddrIterType;

/**   \brief  type used to iterate Sd_MulticastSoConId */
typedef uint8_least Sd_MulticastSoConIdIterType;

/**   \brief  type used to iterate Sd_OptionIndex */
typedef uint8_least Sd_OptionIndexIterType;

/**   \brief  type used to iterate Sd_PartitionDataDyn */
typedef uint8_least Sd_PartitionDataDynIterType;

/**   \brief  type used to iterate Sd_PartitionIdentifiers */
typedef uint8_least Sd_PartitionIdentifiersIterType;

/**   \brief  type used to iterate Sd_Payload */
typedef uint16_least Sd_PayloadIterType;

/**   \brief  type used to iterate Sd_PortSet */
typedef uint8_least Sd_PortSetIterType;

/**   \brief  type used to iterate Sd_RequestCnt */
typedef uint8_least Sd_RequestCntIterType;

/**   \brief  type used to iterate Sd_RoutingGroup */
typedef uint8_least Sd_RoutingGroupIterType;

/**   \brief  type used to iterate Sd_RoutingGroupIdMap */
typedef uint8_least Sd_RoutingGroupIdMapIterType;

/**   \brief  type used to iterate Sd_RxEvent */
typedef uint8_least Sd_RxEventIterType;

/**   \brief  type used to iterate Sd_RxPduIdMap */
typedef uint8_least Sd_RxPduIdMapIterType;

/**   \brief  type used to iterate Sd_SendEntry */
typedef uint8_least Sd_SendEntryIterType;

/**   \brief  type used to iterate Sd_Server */
typedef uint8_least Sd_ServerIterType;

/**   \brief  type used to iterate Sd_ServerIdMap */
typedef uint8_least Sd_ServerIdMapIterType;

/**   \brief  type used to iterate Sd_ServerTimer */
typedef uint8_least Sd_ServerTimerIterType;

/**   \brief  type used to iterate Sd_ServiceGroup */
typedef uint8_least Sd_ServiceGroupIterType;

/**   \brief  type used to iterate Sd_ServiceGroupIdMap */
typedef uint8_least Sd_ServiceGroupIdMapIterType;

/**   \brief  type used to iterate Sd_ServiceGroupMember */
typedef uint8_least Sd_ServiceGroupMemberIterType;

/**   \brief  type used to iterate Sd_SoConActivationMap */
typedef uint8_least Sd_SoConActivationMapIterType;

/**   \brief  type used to iterate Sd_SoConGrpDyn */
typedef uint8_least Sd_SoConGrpDynIterType;

/**   \brief  type used to iterate Sd_SoConModeDyn */
typedef uint8_least Sd_SoConModeDynIterType;

/**   \brief  type used to iterate Sd_SoConModeIdMap */
typedef uint8_least Sd_SoConModeIdMapIterType;

/**   \brief  type used to iterate Sd_TcpSoConId */
typedef uint8_least Sd_TcpSoConIdIterType;

/**   \brief  type used to iterate Sd_TriggerTransmitDyn */
typedef uint8_least Sd_TriggerTransmitDynIterType;

/**   \brief  type used to iterate Sd_TxSoConIdMap */
typedef uint8_least Sd_TxSoConIdMapIterType;

/**   \brief  type used to iterate Sd_UdpSoCon */
typedef uint8_least Sd_UdpSoConIterType;

/**   \brief  type used to iterate Sd_PCPartitionConfig */
typedef uint8_least Sd_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SdPCIterableTypesWithSizeRelations  Sd Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Sd_ClientDyn */
typedef Sd_ClientIterType Sd_ClientDynIterType;

/**   \brief  type used to iterate Sd_ConsumedEventgroupDyn */
typedef Sd_ConsumedEventgroupIterType Sd_ConsumedEventgroupDynIterType;

/**   \brief  type used to iterate Sd_EventHandlerDyn */
typedef Sd_EventHandlerIterType Sd_EventHandlerDynIterType;

/**   \brief  type used to iterate Sd_InstanceDyn */
typedef Sd_InstanceIterType Sd_InstanceDynIterType;

/**   \brief  type used to iterate Sd_RoutingGroupDyn */
typedef Sd_RoutingGroupIterType Sd_RoutingGroupDynIterType;

/**   \brief  type used to iterate Sd_ServerDyn */
typedef Sd_ServerIterType Sd_ServerDynIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SdPCValueTypes  Sd Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Sd_AclIPv4CInd */
typedef uint8 Sd_AclIPv4CIndType;

/**   \brief  value based type definition for Sd_AclIPv4SInd */
typedef uint8 Sd_AclIPv4SIndType;

/**   \brief  value based type definition for Sd_AclIPv6CInd */
typedef uint8 Sd_AclIPv6CIndType;

/**   \brief  value based type definition for Sd_AclIPv6SInd */
typedef uint8 Sd_AclIPv6SIndType;

/**   \brief  value based type definition for Sd_FlagsOfAddressStorage */
typedef uint8 Sd_FlagsOfAddressStorageType;

/**   \brief  value based type definition for Sd_RebootDetectedOfAddressStorage */
typedef boolean Sd_RebootDetectedOfAddressStorageType;

/**   \brief  value based type definition for Sd_RxMulticastFlagsOfAddressStorage */
typedef uint8 Sd_RxMulticastFlagsOfAddressStorageType;

/**   \brief  value based type definition for Sd_RxMulticastSessionIdOfAddressStorage */
typedef uint16 Sd_RxMulticastSessionIdOfAddressStorageType;

/**   \brief  value based type definition for Sd_RxUnicastFlagsOfAddressStorage */
typedef uint8 Sd_RxUnicastFlagsOfAddressStorageType;

/**   \brief  value based type definition for Sd_RxUnicastSessionIdOfAddressStorage */
typedef uint16 Sd_RxUnicastSessionIdOfAddressStorageType;

/**   \brief  value based type definition for Sd_SendEntryHeadIdxOfAddressStorage */
typedef uint8 Sd_SendEntryHeadIdxOfAddressStorageType;

/**   \brief  value based type definition for Sd_SendEntryNrPendingIdxOfAddressStorage */
typedef uint8 Sd_SendEntryNrPendingIdxOfAddressStorageType;

/**   \brief  value based type definition for Sd_SendEntryTailIdxOfAddressStorage */
typedef uint8 Sd_SendEntryTailIdxOfAddressStorageType;

/**   \brief  value based type definition for Sd_SessionIdCounterOfAddressStorage */
typedef uint16 Sd_SessionIdCounterOfAddressStorageType;

/**   \brief  value based type definition for Sd_CapabilityRecord */
typedef uint8 Sd_CapabilityRecordType;

/**   \brief  value based type definition for Sd_AclIPv4CIndEndIdxOfClient */
typedef uint8 Sd_AclIPv4CIndEndIdxOfClientType;

/**   \brief  value based type definition for Sd_AclIPv4CIndStartIdxOfClient */
typedef uint8 Sd_AclIPv4CIndStartIdxOfClientType;

/**   \brief  value based type definition for Sd_AclIPv4CIndUsedOfClient */
typedef boolean Sd_AclIPv4CIndUsedOfClientType;

/**   \brief  value based type definition for Sd_AclIPv6CIndEndIdxOfClient */
typedef uint8 Sd_AclIPv6CIndEndIdxOfClientType;

/**   \brief  value based type definition for Sd_AclIPv6CIndStartIdxOfClient */
typedef uint8 Sd_AclIPv6CIndStartIdxOfClientType;

/**   \brief  value based type definition for Sd_AclIPv6CIndUsedOfClient */
typedef boolean Sd_AclIPv6CIndUsedOfClientType;

/**   \brief  value based type definition for Sd_AutoRequireOfClient */
typedef boolean Sd_AutoRequireOfClientType;

/**   \brief  value based type definition for Sd_CapabilityRecordEndIdxOfClient */
typedef uint8 Sd_CapabilityRecordEndIdxOfClientType;

/**   \brief  value based type definition for Sd_CapabilityRecordFunctionCalloutPtrIdxOfClient */
typedef uint8 Sd_CapabilityRecordFunctionCalloutPtrIdxOfClientType;

/**   \brief  value based type definition for Sd_CapabilityRecordFunctionCalloutPtrUsedOfClient */
typedef boolean Sd_CapabilityRecordFunctionCalloutPtrUsedOfClientType;

/**   \brief  value based type definition for Sd_CapabilityRecordStartIdxOfClient */
typedef uint8 Sd_CapabilityRecordStartIdxOfClientType;

/**   \brief  value based type definition for Sd_CapabilityRecordUsedOfClient */
typedef boolean Sd_CapabilityRecordUsedOfClientType;

/**   \brief  value based type definition for Sd_ClientTimerIdxOfClient */
typedef uint8 Sd_ClientTimerIdxOfClientType;

/**   \brief  value based type definition for Sd_CommonInitialDelayIdxOfClient */
typedef uint8 Sd_CommonInitialDelayIdxOfClientType;

/**   \brief  value based type definition for Sd_CommonInitialDelayUsedOfClient */
typedef boolean Sd_CommonInitialDelayUsedOfClientType;

/**   \brief  value based type definition for Sd_ConsumedEventgroupEndIdxOfClient */
typedef uint8 Sd_ConsumedEventgroupEndIdxOfClientType;

/**   \brief  value based type definition for Sd_ConsumedEventgroupStartIdxOfClient */
typedef uint8 Sd_ConsumedEventgroupStartIdxOfClientType;

/**   \brief  value based type definition for Sd_ConsumedEventgroupUsedOfClient */
typedef boolean Sd_ConsumedEventgroupUsedOfClientType;

/**   \brief  value based type definition for Sd_HandleIdOfClient */
typedef uint8 Sd_HandleIdOfClientType;

/**   \brief  value based type definition for Sd_InitialInstanceIdOfClient */
typedef uint8 Sd_InitialInstanceIdOfClientType;

/**   \brief  value based type definition for Sd_InstanceIdxOfClient */
typedef uint8 Sd_InstanceIdxOfClientType;

/**   \brief  value based type definition for Sd_MajorVersionOfClient */
typedef uint8 Sd_MajorVersionOfClientType;

/**   \brief  value based type definition for Sd_MethodIdxOfClient */
typedef uint8 Sd_MethodIdxOfClientType;

/**   \brief  value based type definition for Sd_MethodUsedOfClient */
typedef boolean Sd_MethodUsedOfClientType;

/**   \brief  value based type definition for Sd_MinorVersionOfClient */
typedef uint8 Sd_MinorVersionOfClientType;

/**   \brief  value based type definition for Sd_MinorVersionWildcardOfClient */
typedef boolean Sd_MinorVersionWildcardOfClientType;

/**   \brief  value based type definition for Sd_ServiceGroupMemberOfClient */
typedef boolean Sd_ServiceGroupMemberOfClientType;

/**   \brief  value based type definition for Sd_ServiceIdOfClient */
typedef uint16 Sd_ServiceIdOfClientType;

/**   \brief  value based type definition for Sd_SoConGrpDynTcpIdxOfClient */
typedef uint8 Sd_SoConGrpDynTcpIdxOfClientType;

/**   \brief  value based type definition for Sd_SoConGrpDynTcpUsedOfClient */
typedef boolean Sd_SoConGrpDynTcpUsedOfClientType;

/**   \brief  value based type definition for Sd_SoConGrpDynUdpIdxOfClient */
typedef uint8 Sd_SoConGrpDynUdpIdxOfClientType;

/**   \brief  value based type definition for Sd_SoConGrpDynUdpUsedOfClient */
typedef boolean Sd_SoConGrpDynUdpUsedOfClientType;

/**   \brief  value based type definition for Sd_TcpSoConIdEndIdxOfClient */
typedef uint8 Sd_TcpSoConIdEndIdxOfClientType;

/**   \brief  value based type definition for Sd_TcpSoConIdStartIdxOfClient */
typedef uint8 Sd_TcpSoConIdStartIdxOfClientType;

/**   \brief  value based type definition for Sd_TcpSoConIdUsedOfClient */
typedef boolean Sd_TcpSoConIdUsedOfClientType;

/**   \brief  value based type definition for Sd_UdpClientMulticastOfClient */
typedef boolean Sd_UdpClientMulticastOfClientType;

/**   \brief  value based type definition for Sd_UdpSoConEndIdxOfClient */
typedef uint8 Sd_UdpSoConEndIdxOfClientType;

/**   \brief  value based type definition for Sd_UdpSoConStartIdxOfClient */
typedef uint8 Sd_UdpSoConStartIdxOfClientType;

/**   \brief  value based type definition for Sd_UdpSoConUsedOfClient */
typedef boolean Sd_UdpSoConUsedOfClientType;

/**   \brief  value based type definition for Sd_AddressStorageCurrentServerIdxOfClientDyn */
typedef uint8 Sd_AddressStorageCurrentServerIdxOfClientDynType;

/**   \brief  value based type definition for Sd_AddressStorageServerIdxOfClientDyn */
typedef uint8 Sd_AddressStorageServerIdxOfClientDynType;

/**   \brief  value based type definition for Sd_InstanceIdOfClientDyn */
typedef uint16 Sd_InstanceIdOfClientDynType;

/**   \brief  value based type definition for Sd_OfferedTTLOfClientDyn */
typedef uint32 Sd_OfferedTTLOfClientDynType;

/**   \brief  value based type definition for Sd_RepetitionRunOfClientDyn */
typedef uint8 Sd_RepetitionRunOfClientDynType;

/**   \brief  value based type definition for Sd_RetryCounterOfClientDyn */
typedef uint8 Sd_RetryCounterOfClientDynType;

/**   \brief  value based type definition for Sd_ServiceGroupReqCounterOfClientDyn */
typedef uint8 Sd_ServiceGroupReqCounterOfClientDynType;

/**   \brief  value based type definition for Sd_StateMachineExecutionRequestedOfClientDyn */
typedef boolean Sd_StateMachineExecutionRequestedOfClientDynType;

/**   \brief  value based type definition for Sd_InvalidHndOfClientIdMap */
typedef boolean Sd_InvalidHndOfClientIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificClientIdxOfClientIdMap */
typedef uint8 Sd_PartitionSpecificClientIdxOfClientIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificClientPartitionIdxOfClientIdMap */
typedef uint8 Sd_PartitionSpecificClientPartitionIdxOfClientIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificClientUsedOfClientIdMap */
typedef boolean Sd_PartitionSpecificClientUsedOfClientIdMapType;

/**   \brief  value based type definition for Sd_AddressStorageIdxOfClientList */
typedef uint8 Sd_AddressStorageIdxOfClientListType;

/**   \brief  value based type definition for Sd_EndpointStorageTcpIdxOfClientList */
typedef uint8 Sd_EndpointStorageTcpIdxOfClientListType;

/**   \brief  value based type definition for Sd_EndpointStorageUdpIdxOfClientList */
typedef uint8 Sd_EndpointStorageUdpIdxOfClientListType;

/**   \brief  value based type definition for Sd_NrOfReferencesOfClientList */
typedef uint8 Sd_NrOfReferencesOfClientListType;

/**   \brief  value based type definition for Sd_RequestedTTLOfClientList */
typedef uint32 Sd_RequestedTTLOfClientListType;

/**   \brief  value based type definition for Sd_RxReservedOfClientList */
typedef uint16 Sd_RxReservedOfClientListType;

/**   \brief  value based type definition for Sd_InitialFindDelayMaxOfClientTimer */
typedef uint8 Sd_InitialFindDelayMaxOfClientTimerType;

/**   \brief  value based type definition for Sd_InitialFindDelayMinOfClientTimer */
typedef uint8 Sd_InitialFindDelayMinOfClientTimerType;

/**   \brief  value based type definition for Sd_InitialFindRepetitionBaseDelayOfClientTimer */
typedef uint8 Sd_InitialFindRepetitionBaseDelayOfClientTimerType;

/**   \brief  value based type definition for Sd_InitialFindRepetitionsMaxOfClientTimer */
typedef uint8 Sd_InitialFindRepetitionsMaxOfClientTimerType;

/**   \brief  value based type definition for Sd_RequestResponseMaxDelayOfClientTimer */
typedef uint8 Sd_RequestResponseMaxDelayOfClientTimerType;

/**   \brief  value based type definition for Sd_RequestResponseMinDelayOfClientTimer */
typedef uint8 Sd_RequestResponseMinDelayOfClientTimerType;

/**   \brief  value based type definition for Sd_TTLOfClientTimer */
typedef uint8 Sd_TTLOfClientTimerType;

/**   \brief  value based type definition for Sd_CommonInitialDelay */
typedef uint32 Sd_CommonInitialDelayType;

/**   \brief  value based type definition for Sd_AutoRequireOfConsumedEventgroup */
typedef boolean Sd_AutoRequireOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_ClientIdxOfConsumedEventgroup */
typedef uint8 Sd_ClientIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_ClientTimerIdxOfConsumedEventgroup */
typedef uint8 Sd_ClientTimerIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_EventGroupIdOfConsumedEventgroup */
typedef uint8 Sd_EventGroupIdOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_HandleIdOfConsumedEventgroup */
typedef uint8 Sd_HandleIdOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_MulticastEndpointAddrIdxOfConsumedEventgroup */
typedef uint8 Sd_MulticastEndpointAddrIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_MulticastEndpointAddrUsedOfConsumedEventgroup */
typedef boolean Sd_MulticastEndpointAddrUsedOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_MulticastSoConIdEndIdxOfConsumedEventgroup */
typedef uint8 Sd_MulticastSoConIdEndIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_MulticastSoConIdStartIdxOfConsumedEventgroup */
typedef uint8 Sd_MulticastSoConIdStartIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_MulticastSoConIdUsedOfConsumedEventgroup */
typedef boolean Sd_MulticastSoConIdUsedOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupMulticastActRefIdxOfConsumedEventgroup */
typedef uint8 Sd_RoutingGroupMulticastActRefIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupMulticastActRefUsedOfConsumedEventgroup */
typedef boolean Sd_RoutingGroupMulticastActRefUsedOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupTcpActRefIdxOfConsumedEventgroup */
typedef uint8 Sd_RoutingGroupTcpActRefIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupTcpActRefUsedOfConsumedEventgroup */
typedef boolean Sd_RoutingGroupTcpActRefUsedOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupUdpActRefIdxOfConsumedEventgroup */
typedef uint8 Sd_RoutingGroupUdpActRefIdxOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_RoutingGroupUdpActRefUsedOfConsumedEventgroup */
typedef boolean Sd_RoutingGroupUdpActRefUsedOfConsumedEventgroupType;

/**   \brief  value based type definition for Sd_AcknowledgedTTLOfConsumedEventgroupDyn */
typedef uint32 Sd_AcknowledgedTTLOfConsumedEventgroupDynType;

/**   \brief  value based type definition for Sd_RxIndicationCountOfConsumedEventgroupDyn */
typedef uint8 Sd_RxIndicationCountOfConsumedEventgroupDynType;

/**   \brief  value based type definition for Sd_TriggerSubscriptionOfConsumedEventgroupDyn */
typedef boolean Sd_TriggerSubscriptionOfConsumedEventgroupDynType;

/**   \brief  value based type definition for Sd_InvalidHndOfConsumedEventgroupIdMap */
typedef boolean Sd_InvalidHndOfConsumedEventgroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap */
typedef uint8 Sd_PartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMap */
typedef uint8 Sd_PartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificConsumedEventgroupUsedOfConsumedEventgroupIdMap */
typedef boolean Sd_PartitionSpecificConsumedEventgroupUsedOfConsumedEventgroupIdMapType;

/**   \brief  value based type definition for Sd_NrOfReferencesOfEndpointStorage */
typedef uint8 Sd_NrOfReferencesOfEndpointStorageType;

/**   \brief  value based type definition for Sd_ClientListEndIdxOfEventHandler */
typedef uint8 Sd_ClientListEndIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_ClientListStartIdxOfEventHandler */
typedef uint8 Sd_ClientListStartIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventGroupIdOfEventHandler */
typedef uint8 Sd_EventGroupIdOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerMulticastIdxOfEventHandler */
typedef uint8 Sd_EventHandlerMulticastIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerMulticastUsedOfEventHandler */
typedef boolean Sd_EventHandlerMulticastUsedOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerTcpIdxOfEventHandler */
typedef uint8 Sd_EventHandlerTcpIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerTcpUsedOfEventHandler */
typedef boolean Sd_EventHandlerTcpUsedOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerUdpIdxOfEventHandler */
typedef uint8 Sd_EventHandlerUdpIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_EventHandlerUdpUsedOfEventHandler */
typedef boolean Sd_EventHandlerUdpUsedOfEventHandlerType;

/**   \brief  value based type definition for Sd_HandleIdOfEventHandler */
typedef uint8 Sd_HandleIdOfEventHandlerType;

/**   \brief  value based type definition for Sd_MulticastThresholdOfEventHandler */
typedef uint8 Sd_MulticastThresholdOfEventHandlerType;

/**   \brief  value based type definition for Sd_ServerIdxOfEventHandler */
typedef uint8 Sd_ServerIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_ServerTimerIdxOfEventHandler */
typedef uint8 Sd_ServerTimerIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_SoConActivationMapEndIdxOfEventHandler */
typedef uint8 Sd_SoConActivationMapEndIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_SoConActivationMapStartIdxOfEventHandler */
typedef uint8 Sd_SoConActivationMapStartIdxOfEventHandlerType;

/**   \brief  value based type definition for Sd_SoConActivationMapUsedOfEventHandler */
typedef boolean Sd_SoConActivationMapUsedOfEventHandlerType;

/**   \brief  value based type definition for Sd_NrOfClientsOfEventHandlerDyn */
typedef uint16 Sd_NrOfClientsOfEventHandlerDynType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefIdxOfEventHandlerMulticast */
typedef uint8 Sd_RoutingGroupActRefIdxOfEventHandlerMulticastType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefUsedOfEventHandlerMulticast */
typedef boolean Sd_RoutingGroupActRefUsedOfEventHandlerMulticastType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefIdxOfEventHandlerTcp */
typedef uint8 Sd_RoutingGroupActRefIdxOfEventHandlerTcpType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefUsedOfEventHandlerTcp */
typedef boolean Sd_RoutingGroupActRefUsedOfEventHandlerTcpType;

/**   \brief  value based type definition for Sd_RoutingGroupTriggerIdxOfEventHandlerTcp */
typedef uint8 Sd_RoutingGroupTriggerIdxOfEventHandlerTcpType;

/**   \brief  value based type definition for Sd_RoutingGroupTriggerUsedOfEventHandlerTcp */
typedef boolean Sd_RoutingGroupTriggerUsedOfEventHandlerTcpType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefIdxOfEventHandlerUdp */
typedef uint8 Sd_RoutingGroupActRefIdxOfEventHandlerUdpType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefUsedOfEventHandlerUdp */
typedef boolean Sd_RoutingGroupActRefUsedOfEventHandlerUdpType;

/**   \brief  value based type definition for Sd_RoutingGroupTriggerIdxOfEventHandlerUdp */
typedef uint8 Sd_RoutingGroupTriggerIdxOfEventHandlerUdpType;

/**   \brief  value based type definition for Sd_RoutingGroupTriggerUsedOfEventHandlerUdp */
typedef boolean Sd_RoutingGroupTriggerUsedOfEventHandlerUdpType;

/**   \brief  value based type definition for Sd_AddressStorageEndIdxOfInstance */
typedef uint8 Sd_AddressStorageEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_AddressStorageStartIdxOfInstance */
typedef uint8 Sd_AddressStorageStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_CapabilityRecordEndIdxOfInstance */
typedef uint8 Sd_CapabilityRecordEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_CapabilityRecordStartIdxOfInstance */
typedef uint8 Sd_CapabilityRecordStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_CapabilityRecordUsedOfInstance */
typedef boolean Sd_CapabilityRecordUsedOfInstanceType;

/**   \brief  value based type definition for Sd_ClientEndIdxOfInstance */
typedef uint8 Sd_ClientEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_ClientStartIdxOfInstance */
typedef uint8 Sd_ClientStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_ClientUsedOfInstance */
typedef boolean Sd_ClientUsedOfInstanceType;

/**   \brief  value based type definition for Sd_EndpointStorageEndIdxOfInstance */
typedef uint8 Sd_EndpointStorageEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_EndpointStorageStartIdxOfInstance */
typedef uint8 Sd_EndpointStorageStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_EventHandlerEndIdxOfInstance */
typedef uint8 Sd_EventHandlerEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_EventHandlerStartIdxOfInstance */
typedef uint8 Sd_EventHandlerStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_EventHandlerUsedOfInstance */
typedef boolean Sd_EventHandlerUsedOfInstanceType;

/**   \brief  value based type definition for Sd_LocalAddressCheckLengthOfInstance */
typedef uint8 Sd_LocalAddressCheckLengthOfInstanceType;

/**   \brief  value based type definition for Sd_MulticastRxPduIdOfInstance */
typedef PduIdType Sd_MulticastRxPduIdOfInstanceType;

/**   \brief  value based type definition for Sd_QueueProcessLimitOfInstance */
typedef uint8 Sd_QueueProcessLimitOfInstanceType;

/**   \brief  value based type definition for Sd_RetryDelayOfInstance */
typedef uint8 Sd_RetryDelayOfInstanceType;

/**   \brief  value based type definition for Sd_RetryMaxOfInstance */
typedef uint8 Sd_RetryMaxOfInstanceType;

/**   \brief  value based type definition for Sd_RxEventEndIdxOfInstance */
typedef uint8 Sd_RxEventEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_RxEventStartIdxOfInstance */
typedef uint8 Sd_RxEventStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_RxEventUsedOfInstance */
typedef boolean Sd_RxEventUsedOfInstanceType;

/**   \brief  value based type definition for Sd_SendEntryCapacityOfInstance */
typedef uint8 Sd_SendEntryCapacityOfInstanceType;

/**   \brief  value based type definition for Sd_SendEntryEndIdxOfInstance */
typedef uint8 Sd_SendEntryEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_SendEntryStartIdxOfInstance */
typedef uint8 Sd_SendEntryStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_ServerEndIdxOfInstance */
typedef uint8 Sd_ServerEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_ServerStartIdxOfInstance */
typedef uint8 Sd_ServerStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_ServerUsedOfInstance */
typedef boolean Sd_ServerUsedOfInstanceType;

/**   \brief  value based type definition for Sd_TcpSoConIdEndIdxOfInstance */
typedef uint8 Sd_TcpSoConIdEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_TcpSoConIdStartIdxOfInstance */
typedef uint8 Sd_TcpSoConIdStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_TcpSoConIdUsedOfInstance */
typedef boolean Sd_TcpSoConIdUsedOfInstanceType;

/**   \brief  value based type definition for Sd_TxPduIdOfInstance */
typedef PduIdType Sd_TxPduIdOfInstanceType;

/**   \brief  value based type definition for Sd_UdpSoConEndIdxOfInstance */
typedef uint8 Sd_UdpSoConEndIdxOfInstanceType;

/**   \brief  value based type definition for Sd_UdpSoConStartIdxOfInstance */
typedef uint8 Sd_UdpSoConStartIdxOfInstanceType;

/**   \brief  value based type definition for Sd_UdpSoConUsedOfInstance */
typedef boolean Sd_UdpSoConUsedOfInstanceType;

/**   \brief  value based type definition for Sd_UnicastRxPduIdOfInstance */
typedef PduIdType Sd_UnicastRxPduIdOfInstanceType;

/**   \brief  value based type definition for Sd_RxEventEndIdxOfInstanceDyn */
typedef uint8 Sd_RxEventEndIdxOfInstanceDynType;

/**   \brief  value based type definition for Sd_RxEventListFullOfInstanceDyn */
typedef boolean Sd_RxEventListFullOfInstanceDynType;

/**   \brief  value based type definition for Sd_RxEventStartIdxOfInstanceDyn */
typedef uint8 Sd_RxEventStartIdxOfInstanceDynType;

/**   \brief  value based type definition for Sd_SendEntryFreeListHeadIdxOfInstanceDyn */
typedef uint8 Sd_SendEntryFreeListHeadIdxOfInstanceDynType;

/**   \brief  value based type definition for Sd_SendEntryFreeListTailIdxOfInstanceDyn */
typedef uint8 Sd_SendEntryFreeListTailIdxOfInstanceDynType;

/**   \brief  value based type definition for Sd_SendEntryNrPendingIdxOfInstanceDyn */
typedef uint8 Sd_SendEntryNrPendingIdxOfInstanceDynType;

/**   \brief  value based type definition for Sd_PortSetIdxOfIpAddrRequest */
typedef uint8 Sd_PortSetIdxOfIpAddrRequestType;

/**   \brief  value based type definition for Sd_RequestCntIdxOfIpAddrRequest */
typedef uint8 Sd_RequestCntIdxOfIpAddrRequestType;

/**   \brief  value based type definition for Sd_StaticIpConfigurationOfIpAddrRequest */
typedef boolean Sd_StaticIpConfigurationOfIpAddrRequestType;

/**   \brief  value based type definition for Sd_StaticPortConfigurationOfIpAddrRequest */
typedef boolean Sd_StaticPortConfigurationOfIpAddrRequestType;

/**   \brief  value based type definition for Sd_MaxNrOptionsPerEntry */
typedef uint8 Sd_MaxNrOptionsPerEntryType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefIdxOfMethod */
typedef uint8 Sd_RoutingGroupActRefIdxOfMethodType;

/**   \brief  value based type definition for Sd_RoutingGroupActRefUsedOfMethod */
typedef boolean Sd_RoutingGroupActRefUsedOfMethodType;

/**   \brief  value based type definition for Sd_TcpConfiguredOfMethod */
typedef boolean Sd_TcpConfiguredOfMethodType;

/**   \brief  value based type definition for Sd_UdpConfiguredOfMethod */
typedef boolean Sd_UdpConfiguredOfMethodType;

/**   \brief  value based type definition for Sd_OptionIndex */
typedef uint16 Sd_OptionIndexType;

/**   \brief  value based type definition for Sd_NrOfOptionsOfPartitionDataDyn */
typedef uint16 Sd_NrOfOptionsOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_RxIndicationCountOfPartitionDataDyn */
typedef uint8 Sd_RxIndicationCountOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_TriggerTransmitDynEndIdxOfPartitionDataDyn */
typedef uint8 Sd_TriggerTransmitDynEndIdxOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_TriggerTransmitDynStartIdxOfPartitionDataDyn */
typedef uint8 Sd_TriggerTransmitDynStartIdxOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_TriggerTransmitFullOfPartitionDataDyn */
typedef boolean Sd_TriggerTransmitFullOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_TxPathLockedOfPartitionDataDyn */
typedef boolean Sd_TxPathLockedOfPartitionDataDynType;

/**   \brief  value based type definition for Sd_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 Sd_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for Sd_PartitionSNVOfPartitionIdentifiers */
typedef uint32 Sd_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for Sd_Payload */
typedef uint8 Sd_PayloadType;

/**   \brief  value based type definition for Sd_PortSet */
typedef boolean Sd_PortSetType;

/**   \brief  value based type definition for Sd_RequestCnt */
typedef uint16 Sd_RequestCntType;

/**   \brief  value based type definition for Sd_InvalidHndOfRoutingGroupIdMap */
typedef boolean Sd_InvalidHndOfRoutingGroupIdMapType;

/**   \brief  value based type definition for Sd_ServerIdxOfRoutingGroupIdMap */
typedef uint8 Sd_ServerIdxOfRoutingGroupIdMapType;

/**   \brief  value based type definition for Sd_ServerPartitionIdxOfRoutingGroupIdMap */
typedef uint8 Sd_ServerPartitionIdxOfRoutingGroupIdMapType;

/**   \brief  value based type definition for Sd_ServerUsedOfRoutingGroupIdMap */
typedef boolean Sd_ServerUsedOfRoutingGroupIdMapType;

/**   \brief  value based type definition for Sd_ClientListIdxOfRxEvent */
typedef uint8 Sd_ClientListIdxOfRxEventType;

/**   \brief  value based type definition for Sd_EventHandlerIdxOfRxEvent */
typedef uint8 Sd_EventHandlerIdxOfRxEventType;

/**   \brief  value based type definition for Sd_InvalidHndOfRxPduIdMap */
typedef boolean Sd_InvalidHndOfRxPduIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstanceIdxOfRxPduIdMap */
typedef uint8 Sd_PartitionSpecificInstanceIdxOfRxPduIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstancePartitionIdxOfRxPduIdMap */
typedef uint8 Sd_PartitionSpecificInstancePartitionIdxOfRxPduIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstanceUsedOfRxPduIdMap */
typedef boolean Sd_PartitionSpecificInstanceUsedOfRxPduIdMapType;

/**   \brief  value based type definition for Sd_ClientIdxOfSendEntry */
typedef uint8 Sd_ClientIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_ClientListIdxOfSendEntry */
typedef uint8 Sd_ClientListIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_ConsumedEventgroupIdxOfSendEntry */
typedef uint8 Sd_ConsumedEventgroupIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_EventHandlerIdOfSendEntry */
typedef uint16 Sd_EventHandlerIdOfSendEntryType;

/**   \brief  value based type definition for Sd_EventHandlerIdxOfSendEntry */
typedef uint8 Sd_EventHandlerIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_InstanceIdOfSendEntry */
typedef uint16 Sd_InstanceIdOfSendEntryType;

/**   \brief  value based type definition for Sd_InstanceIdxOfSendEntry */
typedef uint8 Sd_InstanceIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_MajorVersionOfSendEntry */
typedef uint8 Sd_MajorVersionOfSendEntryType;

/**   \brief  value based type definition for Sd_ReservedFieldOfSendEntry */
typedef uint16 Sd_ReservedFieldOfSendEntryType;

/**   \brief  value based type definition for Sd_SendEntryNextIdxOfSendEntry */
typedef uint8 Sd_SendEntryNextIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_SendEntryPrevIdxOfSendEntry */
typedef uint8 Sd_SendEntryPrevIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_ServerIdxOfSendEntry */
typedef uint8 Sd_ServerIdxOfSendEntryType;

/**   \brief  value based type definition for Sd_ServiceIdOfSendEntry */
typedef uint16 Sd_ServiceIdOfSendEntryType;

/**   \brief  value based type definition for Sd_AclIPv4SIndEndIdxOfServer */
typedef uint8 Sd_AclIPv4SIndEndIdxOfServerType;

/**   \brief  value based type definition for Sd_AclIPv4SIndStartIdxOfServer */
typedef uint8 Sd_AclIPv4SIndStartIdxOfServerType;

/**   \brief  value based type definition for Sd_AclIPv4SIndUsedOfServer */
typedef boolean Sd_AclIPv4SIndUsedOfServerType;

/**   \brief  value based type definition for Sd_AclIPv6SIndEndIdxOfServer */
typedef uint8 Sd_AclIPv6SIndEndIdxOfServerType;

/**   \brief  value based type definition for Sd_AclIPv6SIndStartIdxOfServer */
typedef uint8 Sd_AclIPv6SIndStartIdxOfServerType;

/**   \brief  value based type definition for Sd_AclIPv6SIndUsedOfServer */
typedef boolean Sd_AclIPv6SIndUsedOfServerType;

/**   \brief  value based type definition for Sd_AutoAvailableOfServer */
typedef boolean Sd_AutoAvailableOfServerType;

/**   \brief  value based type definition for Sd_CapabilityRecordEndIdxOfServer */
typedef uint8 Sd_CapabilityRecordEndIdxOfServerType;

/**   \brief  value based type definition for Sd_CapabilityRecordFunctionCalloutPtrIdxOfServer */
typedef uint8 Sd_CapabilityRecordFunctionCalloutPtrIdxOfServerType;

/**   \brief  value based type definition for Sd_CapabilityRecordFunctionCalloutPtrUsedOfServer */
typedef boolean Sd_CapabilityRecordFunctionCalloutPtrUsedOfServerType;

/**   \brief  value based type definition for Sd_CapabilityRecordStartIdxOfServer */
typedef uint8 Sd_CapabilityRecordStartIdxOfServerType;

/**   \brief  value based type definition for Sd_CapabilityRecordUsedOfServer */
typedef boolean Sd_CapabilityRecordUsedOfServerType;

/**   \brief  value based type definition for Sd_CommonInitialDelayIdxOfServer */
typedef uint8 Sd_CommonInitialDelayIdxOfServerType;

/**   \brief  value based type definition for Sd_CommonInitialDelayUsedOfServer */
typedef boolean Sd_CommonInitialDelayUsedOfServerType;

/**   \brief  value based type definition for Sd_EventHandlerEndIdxOfServer */
typedef uint8 Sd_EventHandlerEndIdxOfServerType;

/**   \brief  value based type definition for Sd_EventHandlerStartIdxOfServer */
typedef uint8 Sd_EventHandlerStartIdxOfServerType;

/**   \brief  value based type definition for Sd_EventHandlerUsedOfServer */
typedef boolean Sd_EventHandlerUsedOfServerType;

/**   \brief  value based type definition for Sd_HandleIdOfServer */
typedef uint8 Sd_HandleIdOfServerType;

/**   \brief  value based type definition for Sd_InitialInstanceIdOfServer */
typedef uint8 Sd_InitialInstanceIdOfServerType;

/**   \brief  value based type definition for Sd_InstanceIdxOfServer */
typedef uint8 Sd_InstanceIdxOfServerType;

/**   \brief  value based type definition for Sd_MajorVersionOfServer */
typedef uint8 Sd_MajorVersionOfServerType;

/**   \brief  value based type definition for Sd_MethodIdxOfServer */
typedef uint8 Sd_MethodIdxOfServerType;

/**   \brief  value based type definition for Sd_MethodUsedOfServer */
typedef boolean Sd_MethodUsedOfServerType;

/**   \brief  value based type definition for Sd_MinorVersionOfServer */
typedef uint8 Sd_MinorVersionOfServerType;

/**   \brief  value based type definition for Sd_ServerTimerIdxOfServer */
typedef uint8 Sd_ServerTimerIdxOfServerType;

/**   \brief  value based type definition for Sd_ServiceGroupMemberOfServer */
typedef boolean Sd_ServiceGroupMemberOfServerType;

/**   \brief  value based type definition for Sd_ServiceIdOfServer */
typedef uint8 Sd_ServiceIdOfServerType;

/**   \brief  value based type definition for Sd_SoConGrpDynTcpIdxOfServer */
typedef uint8 Sd_SoConGrpDynTcpIdxOfServerType;

/**   \brief  value based type definition for Sd_SoConGrpDynTcpUsedOfServer */
typedef boolean Sd_SoConGrpDynTcpUsedOfServerType;

/**   \brief  value based type definition for Sd_SoConGrpDynUdpIdxOfServer */
typedef uint8 Sd_SoConGrpDynUdpIdxOfServerType;

/**   \brief  value based type definition for Sd_SoConGrpDynUdpUsedOfServer */
typedef boolean Sd_SoConGrpDynUdpUsedOfServerType;

/**   \brief  value based type definition for Sd_TcpSoConIdEndIdxOfServer */
typedef uint8 Sd_TcpSoConIdEndIdxOfServerType;

/**   \brief  value based type definition for Sd_TcpSoConIdStartIdxOfServer */
typedef uint8 Sd_TcpSoConIdStartIdxOfServerType;

/**   \brief  value based type definition for Sd_TcpSoConIdUsedOfServer */
typedef boolean Sd_TcpSoConIdUsedOfServerType;

/**   \brief  value based type definition for Sd_UdpSoConEndIdxOfServer */
typedef uint8 Sd_UdpSoConEndIdxOfServerType;

/**   \brief  value based type definition for Sd_UdpSoConStartIdxOfServer */
typedef uint8 Sd_UdpSoConStartIdxOfServerType;

/**   \brief  value based type definition for Sd_UdpSoConUsedOfServer */
typedef boolean Sd_UdpSoConUsedOfServerType;

/**   \brief  value based type definition for Sd_InitialOfferRepetitionRunOfServerDyn */
typedef uint8 Sd_InitialOfferRepetitionRunOfServerDynType;

/**   \brief  value based type definition for Sd_InstanceIdOfServerDyn */
typedef uint16 Sd_InstanceIdOfServerDynType;

/**   \brief  value based type definition for Sd_ServiceGroupReqCounterOfServerDyn */
typedef uint8 Sd_ServiceGroupReqCounterOfServerDynType;

/**   \brief  value based type definition for Sd_StateMachineExecutionRequestedOfServerDyn */
typedef boolean Sd_StateMachineExecutionRequestedOfServerDynType;

/**   \brief  value based type definition for Sd_InvalidHndOfServerIdMap */
typedef boolean Sd_InvalidHndOfServerIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServerIdxOfServerIdMap */
typedef uint8 Sd_PartitionSpecificServerIdxOfServerIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServerPartitionIdxOfServerIdMap */
typedef uint8 Sd_PartitionSpecificServerPartitionIdxOfServerIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServerUsedOfServerIdMap */
typedef boolean Sd_PartitionSpecificServerUsedOfServerIdMapType;

/**   \brief  value based type definition for Sd_InitialOfferDelayMaxOfServerTimer */
typedef uint8 Sd_InitialOfferDelayMaxOfServerTimerType;

/**   \brief  value based type definition for Sd_InitialOfferDelayMinOfServerTimer */
typedef uint8 Sd_InitialOfferDelayMinOfServerTimerType;

/**   \brief  value based type definition for Sd_InitialOfferRepetitionBaseDelayOfServerTimer */
typedef uint8 Sd_InitialOfferRepetitionBaseDelayOfServerTimerType;

/**   \brief  value based type definition for Sd_InitialOfferRepetitionsMaxOfServerTimer */
typedef uint8 Sd_InitialOfferRepetitionsMaxOfServerTimerType;

/**   \brief  value based type definition for Sd_OfferCyclicDelayOfServerTimer */
typedef uint16 Sd_OfferCyclicDelayOfServerTimerType;

/**   \brief  value based type definition for Sd_RequestResponseMaxDelayOfServerTimer */
typedef uint8 Sd_RequestResponseMaxDelayOfServerTimerType;

/**   \brief  value based type definition for Sd_RequestResponseMinDelayOfServerTimer */
typedef uint8 Sd_RequestResponseMinDelayOfServerTimerType;

/**   \brief  value based type definition for Sd_TTLOfServerTimer */
typedef uint8 Sd_TTLOfServerTimerType;

/**   \brief  value based type definition for Sd_ServiceGroupMemberEndIdxOfServiceGroup */
typedef uint8 Sd_ServiceGroupMemberEndIdxOfServiceGroupType;

/**   \brief  value based type definition for Sd_ServiceGroupMemberStartIdxOfServiceGroup */
typedef uint8 Sd_ServiceGroupMemberStartIdxOfServiceGroupType;

/**   \brief  value based type definition for Sd_InvalidHndOfServiceGroupIdMap */
typedef boolean Sd_InvalidHndOfServiceGroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServiceGroupIdxOfServiceGroupIdMap */
typedef uint8 Sd_PartitionSpecificServiceGroupIdxOfServiceGroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMap */
typedef uint8 Sd_PartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificServiceGroupUsedOfServiceGroupIdMap */
typedef boolean Sd_PartitionSpecificServiceGroupUsedOfServiceGroupIdMapType;

/**   \brief  value based type definition for Sd_ClientIdxOfServiceGroupMember */
typedef uint8 Sd_ClientIdxOfServiceGroupMemberType;

/**   \brief  value based type definition for Sd_ClientUsedOfServiceGroupMember */
typedef boolean Sd_ClientUsedOfServiceGroupMemberType;

/**   \brief  value based type definition for Sd_ServerIdxOfServiceGroupMember */
typedef uint8 Sd_ServerIdxOfServiceGroupMemberType;

/**   \brief  value based type definition for Sd_ServerUsedOfServiceGroupMember */
typedef boolean Sd_ServerUsedOfServiceGroupMemberType;

/**   \brief  value based type definition for Sd_NrOfActivationsOfSoConActivationMap */
typedef uint8 Sd_NrOfActivationsOfSoConActivationMapType;

/**   \brief  value based type definition for Sd_LocalPortOfSoConGrpDyn */
typedef uint16 Sd_LocalPortOfSoConGrpDynType;

/**   \brief  value based type definition for Sd_InvalidHndOfSoConModeIdMap */
typedef boolean Sd_InvalidHndOfSoConModeIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificSoConModeIdxOfSoConModeIdMap */
typedef uint8 Sd_PartitionSpecificSoConModeIdxOfSoConModeIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificSoConModePartitionIdxOfSoConModeIdMap */
typedef uint8 Sd_PartitionSpecificSoConModePartitionIdxOfSoConModeIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificSoConModeUsedOfSoConModeIdMap */
typedef boolean Sd_PartitionSpecificSoConModeUsedOfSoConModeIdMapType;

/**   \brief  value based type definition for Sd_ClientListIdxOfTriggerTransmitDyn */
typedef uint8 Sd_ClientListIdxOfTriggerTransmitDynType;

/**   \brief  value based type definition for Sd_EventHandlerIdxOfTriggerTransmitDyn */
typedef uint8 Sd_EventHandlerIdxOfTriggerTransmitDynType;

/**   \brief  value based type definition for Sd_InvalidHndOfTxSoConIdMap */
typedef boolean Sd_InvalidHndOfTxSoConIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstanceIdxOfTxSoConIdMap */
typedef uint8 Sd_PartitionSpecificInstanceIdxOfTxSoConIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstancePartitionIdxOfTxSoConIdMap */
typedef uint8 Sd_PartitionSpecificInstancePartitionIdxOfTxSoConIdMapType;

/**   \brief  value based type definition for Sd_PartitionSpecificInstanceUsedOfTxSoConIdMap */
typedef boolean Sd_PartitionSpecificInstanceUsedOfTxSoConIdMapType;

/**   \brief  value based type definition for Sd_PreconfiguredOfUdpSoCon */
typedef boolean Sd_PreconfiguredOfUdpSoConType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SdPCStructTypes  Sd Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Sd_AclIPv4 */
typedef struct sSd_AclIPv4Type
{
  Sd_IpAddrInetType AddrOfAclIPv4;
} Sd_AclIPv4Type;

/**   \brief  type used in Sd_AclIPv6 */
typedef struct sSd_AclIPv6Type
{
  Sd_IpAddrInet6Type AddrOfAclIPv6;
} Sd_AclIPv6Type;

/**   \brief  type used in Sd_AddressStorage */
typedef struct sSd_AddressStorageType
{
  Sd_RxMulticastSessionIdOfAddressStorageType RxMulticastSessionIdOfAddressStorage;  /**< RX multicast session ID */
  Sd_RxUnicastSessionIdOfAddressStorageType RxUnicastSessionIdOfAddressStorage;  /**< RX unicast session ID */
  Sd_SessionIdCounterOfAddressStorageType SessionIdCounterOfAddressStorage;  /**< TX session ID */
  Sd_FlagsOfAddressStorageType FlagsOfAddressStorage;  /**< TX flags */
  Sd_RebootDetectedOfAddressStorageType RebootDetectedOfAddressStorage;  /**< Remote reboot detection status */
  Sd_RxMulticastFlagsOfAddressStorageType RxMulticastFlagsOfAddressStorage;  /**< RX multicast flags */
  Sd_RxUnicastFlagsOfAddressStorageType RxUnicastFlagsOfAddressStorage;  /**< RX unicast flags */
  Sd_SendEntryHeadIdxOfAddressStorageType SendEntryHeadIdxOfAddressStorage;  /**< the index of the 0:1 relation pointing to Sd_SendEntry */
  Sd_SendEntryNrPendingIdxOfAddressStorageType SendEntryNrPendingIdxOfAddressStorage;  /**< the index of the 0:1 relation pointing to Sd_SendEntry */
  Sd_SendEntryTailIdxOfAddressStorageType SendEntryTailIdxOfAddressStorage;  /**< the index of the 0:1 relation pointing to Sd_SendEntry */
  Sd_SockAddrContainerType AddrOfAddressStorage;  /**< Address of the communication partner */
  Sd_ExtendedTimeType TimeToSendOfAddressStorage;  /**< Time when queued SendEntries became / will become ready to be sent */
} Sd_AddressStorageType;

/**   \brief  type used in Sd_Client */
typedef struct sSd_ClientType
{
  Sd_ServiceIdOfClientType ServiceIdOfClient;  /**< Service ID */
  Sd_AutoRequireOfClientType AutoRequireOfClient;  /**< Auto require flag */
  Sd_MinorVersionWildcardOfClientType MinorVersionWildcardOfClient;  /**< Indicates if MinorVersion is configured to wildcard. */
  Sd_ServiceGroupMemberOfClientType ServiceGroupMemberOfClient;  /**< Specifies if service is member of a ServiceGroup. */
  Sd_UdpClientMulticastOfClientType UdpClientMulticastOfClient;  /**< Specifies if CEG of service use UDP ClientMulticast or UDP Unicast. */
  Sd_AclIPv4CIndEndIdxOfClientType AclIPv4CIndEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_AclIPv4CInd */
  Sd_AclIPv4CIndStartIdxOfClientType AclIPv4CIndStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_AclIPv4CInd */
  Sd_AclIPv6CIndEndIdxOfClientType AclIPv6CIndEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_AclIPv6CInd */
  Sd_AclIPv6CIndStartIdxOfClientType AclIPv6CIndStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_AclIPv6CInd */
  Sd_CapabilityRecordEndIdxOfClientType CapabilityRecordEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_CapabilityRecordFunctionCalloutPtrIdxOfClientType CapabilityRecordFunctionCalloutPtrIdxOfClient;  /**< the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr */
  Sd_CapabilityRecordStartIdxOfClientType CapabilityRecordStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_ClientTimerIdxOfClientType ClientTimerIdxOfClient;  /**< the index of the 1:1 relation pointing to Sd_ClientTimer */
  Sd_CommonInitialDelayIdxOfClientType CommonInitialDelayIdxOfClient;  /**< the index of the 0:1 relation pointing to Sd_CommonInitialDelay */
  Sd_ConsumedEventgroupEndIdxOfClientType ConsumedEventgroupEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_ConsumedEventgroup */
  Sd_ConsumedEventgroupStartIdxOfClientType ConsumedEventgroupStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_ConsumedEventgroup */
  Sd_HandleIdOfClientType HandleIdOfClient;  /**< Handle ID */
  Sd_InitialInstanceIdOfClientType InitialInstanceIdOfClient;  /**< InitialInstance ID */
  Sd_InstanceIdxOfClientType InstanceIdxOfClient;  /**< the index of the 1:1 relation pointing to Sd_Instance */
  Sd_MajorVersionOfClientType MajorVersionOfClient;  /**< Major Version */
  Sd_MethodIdxOfClientType MethodIdxOfClient;  /**< the index of the 0:1 relation pointing to Sd_Method */
  Sd_MinorVersionOfClientType MinorVersionOfClient;  /**< Minor Version */
  Sd_SoConGrpDynTcpIdxOfClientType SoConGrpDynTcpIdxOfClient;  /**< the index of the 0:1 relation pointing to Sd_SoConGrpDyn */
  Sd_SoConGrpDynUdpIdxOfClientType SoConGrpDynUdpIdxOfClient;  /**< the index of the 0:1 relation pointing to Sd_SoConGrpDyn */
  Sd_TcpSoConIdEndIdxOfClientType TcpSoConIdEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_TcpSoConIdStartIdxOfClientType TcpSoConIdStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_UdpSoConEndIdxOfClientType UdpSoConEndIdxOfClient;  /**< the end index of the 0:n relation pointing to Sd_UdpSoCon */
  Sd_UdpSoConStartIdxOfClientType UdpSoConStartIdxOfClient;  /**< the start index of the 0:n relation pointing to Sd_UdpSoCon */
  Sd_ClientFindBehaviorType FindBehaviorOfClient;  /**< SdVersionDrivenFindBehavior */
} Sd_ClientType;

/**   \brief  type used in Sd_ClientDyn */
typedef struct sSd_ClientDynType
{
  Sd_OfferedTTLOfClientDynType OfferedTTLOfClientDyn;  /**< Offered Time To Live */
  Sd_InstanceIdOfClientDynType InstanceIdOfClientDyn;  /**< Current Instance ID of client service */
  Sd_AddressStorageCurrentServerIdxOfClientDynType AddressStorageCurrentServerIdxOfClientDyn;  /**< the index of the 0:1 relation pointing to Sd_AddressStorage */
  Sd_AddressStorageServerIdxOfClientDynType AddressStorageServerIdxOfClientDyn;  /**< the index of the 0:1 relation pointing to Sd_AddressStorage */
  Sd_RepetitionRunOfClientDynType RepetitionRunOfClientDyn;  /**< Repetition run counter */
  Sd_RetryCounterOfClientDynType RetryCounterOfClientDyn;  /**< Counter for subscribe eventgroup retry handling. */
  Sd_ServiceGroupReqCounterOfClientDynType ServiceGroupReqCounterOfClientDyn;  /**< Client request counter for ServiceGroup service API */
  Sd_StateMachineExecutionRequestedOfClientDynType StateMachineExecutionRequestedOfClientDyn;  /**< Flag if State machine shall be executed for this client */
  Sd_ClientServiceCurrentStateType CurrentStateOfClientDyn;  /**< Current state */
  Sd_ClientServiceEventType EventMainOfClientDyn;  /**< Event processed in MainFunction. */
  Sd_ClientServiceEventType EventRxOfClientDyn;  /**< Received event */
  SoAd_SoConIdType MethodTcpSoConIdOfClientDyn;  /**< TCP method SoConId */
  SoAd_SoConIdType MethodUdpSoConIdOfClientDyn;  /**< UDP method SoConId */
  Sd_ExtendedTimeType RetryTimerOfClientDyn;  /**< Timer for subscribe eventgroup retry handling. */
  Sd_SockAddrContainerType ServerTcpEndpointAddrOfClientDyn;  /**< Server TCP endpoint address */
  Sd_SockAddrContainerType ServerUdpEndpointAddrOfClientDyn;  /**< Server UDP endpoint address */
  Sd_ClientStateMachineType StateMachineOfClientDyn;  /**< State machine */
  Sd_ClientServiceSetStateType StateSwcOfClientDyn;  /**< Requested state */
  Sd_ExtendedTimeType TimeToTriggerSendOfClientDyn;  /**< Time to trigger next message transmission */
  Sd_ExtendedTimeType TimerTTLOfClientDyn;  /**< Time To Live */
} Sd_ClientDynType;

/**   \brief  type used in Sd_ClientIdMap */
typedef struct sSd_ClientIdMapType
{
  Sd_InvalidHndOfClientIdMapType InvalidHndOfClientIdMap;  /**< FALSE, if the handle of Sd_ClientIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificClientIdxOfClientIdMapType PartitionSpecificClientIdxOfClientIdMap;  /**< the index of the 0:1 relation pointing to Sd_Client */
  Sd_PartitionSpecificClientPartitionIdxOfClientIdMapType PartitionSpecificClientPartitionIdxOfClientIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_Client */
} Sd_ClientIdMapType;

/**   \brief  type used in Sd_ClientList */
typedef struct sSd_ClientListType
{
  Sd_RequestedTTLOfClientListType RequestedTTLOfClientList;  /**< Requested TimeToLive */
  Sd_RxReservedOfClientListType RxReservedOfClientList;  /**< Received reserved field */
  Sd_AddressStorageIdxOfClientListType AddressStorageIdxOfClientList;  /**< the index of the 0:1 relation pointing to Sd_AddressStorage */
  Sd_EndpointStorageTcpIdxOfClientListType EndpointStorageTcpIdxOfClientList;  /**< the index of the 0:1 relation pointing to Sd_EndpointStorage */
  Sd_EndpointStorageUdpIdxOfClientListType EndpointStorageUdpIdxOfClientList;  /**< the index of the 0:1 relation pointing to Sd_EndpointStorage */
  Sd_NrOfReferencesOfClientListType NrOfReferencesOfClientList;  /**< Number of simultaneous subscriptions */
  SoAd_SoConIdType AssignedTcpSoConIdOfClientList;  /**< Used TCP SocketConnection ID */
  SoAd_SoConIdType AssignedUdpSoConIdOfClientList;  /**< Used UDP SocketConnection ID */
  Sd_EventHandlerClientStateType ClientStateOfClientList;  /**< State of the client */
  Sd_ExtendedTimeType SubscribedUntilOfClientList;  /**< Point in time till the client is subscribed */
} Sd_ClientListType;

/**   \brief  type used in Sd_ClientTimer */
typedef struct sSd_ClientTimerType
{
  Sd_InitialFindDelayMaxOfClientTimerType InitialFindDelayMaxOfClientTimer;  /**< Maximal initial delay for FindService message */
  Sd_InitialFindDelayMinOfClientTimerType InitialFindDelayMinOfClientTimer;  /**< Minimal initial delay for FindService message */
  Sd_InitialFindRepetitionBaseDelayOfClientTimerType InitialFindRepetitionBaseDelayOfClientTimer;  /**< Base delay for FindService messages during initial find phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS. */
  Sd_InitialFindRepetitionsMaxOfClientTimerType InitialFindRepetitionsMaxOfClientTimer;  /**< Amount of FindService messages transmitted during initial find phase */
  Sd_RequestResponseMaxDelayOfClientTimerType RequestResponseMaxDelayOfClientTimer;  /**< Maximal request-response delay */
  Sd_RequestResponseMinDelayOfClientTimerType RequestResponseMinDelayOfClientTimer;  /**< Minimal request-response delay */
  Sd_TTLOfClientTimerType TTLOfClientTimer;  /**< Time To Live */
} Sd_ClientTimerType;

/**   \brief  type used in Sd_ConsumedEventgroup */
typedef struct sSd_ConsumedEventgroupType
{
  Sd_AutoRequireOfConsumedEventgroupType AutoRequireOfConsumedEventgroup;  /**< Auto require flag */
  Sd_ClientIdxOfConsumedEventgroupType ClientIdxOfConsumedEventgroup;  /**< the index of the 1:1 relation pointing to Sd_Client */
  Sd_ClientTimerIdxOfConsumedEventgroupType ClientTimerIdxOfConsumedEventgroup;  /**< the index of the 1:1 relation pointing to Sd_ClientTimer */
  Sd_EventGroupIdOfConsumedEventgroupType EventGroupIdOfConsumedEventgroup;  /**< Eventgroup ID */
  Sd_HandleIdOfConsumedEventgroupType HandleIdOfConsumedEventgroup;  /**< Handle ID */
  Sd_MulticastEndpointAddrIdxOfConsumedEventgroupType MulticastEndpointAddrIdxOfConsumedEventgroup;  /**< the index of the 0:1 relation pointing to Sd_MulticastEndpointAddr */
  Sd_MulticastSoConIdEndIdxOfConsumedEventgroupType MulticastSoConIdEndIdxOfConsumedEventgroup;  /**< the end index of the 0:n relation pointing to Sd_MulticastSoConId */
  Sd_MulticastSoConIdStartIdxOfConsumedEventgroupType MulticastSoConIdStartIdxOfConsumedEventgroup;  /**< the start index of the 0:n relation pointing to Sd_MulticastSoConId */
  Sd_RoutingGroupMulticastActRefIdxOfConsumedEventgroupType RoutingGroupMulticastActRefIdxOfConsumedEventgroup;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
  Sd_RoutingGroupTcpActRefIdxOfConsumedEventgroupType RoutingGroupTcpActRefIdxOfConsumedEventgroup;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
  Sd_RoutingGroupUdpActRefIdxOfConsumedEventgroupType RoutingGroupUdpActRefIdxOfConsumedEventgroup;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
} Sd_ConsumedEventgroupType;

/**   \brief  type used in Sd_ConsumedEventgroupDyn */
typedef struct sSd_ConsumedEventgroupDynType
{
  Sd_AcknowledgedTTLOfConsumedEventgroupDynType AcknowledgedTTLOfConsumedEventgroupDyn;  /**< Acknowledge Time To Live */
  Sd_RxIndicationCountOfConsumedEventgroupDynType RxIndicationCountOfConsumedEventgroupDyn;  /**< Counter to differentiate RxIndication calls. */
  Sd_TriggerSubscriptionOfConsumedEventgroupDynType TriggerSubscriptionOfConsumedEventgroupDyn;  /**< Flag indicating if a subscription shall be triggered. */
  Sd_ConsumedEventGroupCurrentStateType CurrentStateOfConsumedEventgroupDyn;  /**< Current state */
  Sd_ClientEventgroupEventType EventOfConsumedEventgroupDyn;  /**< Received event */
  SoAd_SoConIdType MulticastSoConIdOfConsumedEventgroupDyn;  /**< Configured multicast SocketConnection */
  Sd_ConsumedEventGroupSetStateType ServiceModeRequestOfConsumedEventgroupDyn;  /**< Requested state */
  Sd_ConsumedEventGroupStateMachineType StateMachineOfConsumedEventgroupDyn;  /**< State machine */
  SoAd_SoConIdType TcpSoConIdOfConsumedEventgroupDyn;  /**< Configured TCP SocketConnection */
  Sd_ExtendedTimeType TimerTTLOfConsumedEventgroupDyn;  /**< Time To Live */
  SoAd_SoConIdType UdpSoConIdOfConsumedEventgroupDyn;  /**< Configured UDP SocketConnection */
} Sd_ConsumedEventgroupDynType;

/**   \brief  type used in Sd_ConsumedEventgroupIdMap */
typedef struct sSd_ConsumedEventgroupIdMapType
{
  Sd_InvalidHndOfConsumedEventgroupIdMapType InvalidHndOfConsumedEventgroupIdMap;  /**< FALSE, if the handle of Sd_ConsumedEventgroupIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMapType PartitionSpecificConsumedEventgroupIdxOfConsumedEventgroupIdMap;  /**< the index of the 0:1 relation pointing to Sd_ConsumedEventgroup */
  Sd_PartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMapType PartitionSpecificConsumedEventgroupPartitionIdxOfConsumedEventgroupIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_ConsumedEventgroup */
} Sd_ConsumedEventgroupIdMapType;

/**   \brief  type used in Sd_EndpointStorage */
typedef struct sSd_EndpointStorageType
{
  Sd_NrOfReferencesOfEndpointStorageType NrOfReferencesOfEndpointStorage;  /**< Number of external references */
  Sd_SockAddrContainerType AddrOfEndpointStorage;  /**< Endpoint address */
  Sd_EndpointType TypeOfEndpointStorage;  /**< Endpoint type */
} Sd_EndpointStorageType;

/**   \brief  type used in Sd_EventHandler */
typedef struct sSd_EventHandlerType
{
  Sd_ClientListEndIdxOfEventHandlerType ClientListEndIdxOfEventHandler;  /**< the end index of the 1:n relation pointing to Sd_ClientList */
  Sd_ClientListStartIdxOfEventHandlerType ClientListStartIdxOfEventHandler;  /**< the start index of the 1:n relation pointing to Sd_ClientList */
  Sd_EventGroupIdOfEventHandlerType EventGroupIdOfEventHandler;  /**< Eventgroup ID */
  Sd_EventHandlerMulticastIdxOfEventHandlerType EventHandlerMulticastIdxOfEventHandler;  /**< the index of the 0:1 relation pointing to Sd_EventHandlerMulticast */
  Sd_EventHandlerTcpIdxOfEventHandlerType EventHandlerTcpIdxOfEventHandler;  /**< the index of the 0:1 relation pointing to Sd_EventHandlerTcp */
  Sd_EventHandlerUdpIdxOfEventHandlerType EventHandlerUdpIdxOfEventHandler;  /**< the index of the 0:1 relation pointing to Sd_EventHandlerUdp */
  Sd_HandleIdOfEventHandlerType HandleIdOfEventHandler;  /**< Handle ID */
  Sd_MulticastThresholdOfEventHandlerType MulticastThresholdOfEventHandler;  /**< Multicast threshold */
  Sd_ServerIdxOfEventHandlerType ServerIdxOfEventHandler;  /**< the index of the 1:1 relation pointing to Sd_Server */
  Sd_ServerTimerIdxOfEventHandlerType ServerTimerIdxOfEventHandler;  /**< the index of the 1:1 relation pointing to Sd_ServerTimer */
  Sd_SoConActivationMapEndIdxOfEventHandlerType SoConActivationMapEndIdxOfEventHandler;  /**< the end index of the 0:n relation pointing to Sd_SoConActivationMap */
  Sd_SoConActivationMapStartIdxOfEventHandlerType SoConActivationMapStartIdxOfEventHandler;  /**< the start index of the 0:n relation pointing to Sd_SoConActivationMap */
} Sd_EventHandlerType;

/**   \brief  type used in Sd_EventHandlerDyn */
typedef struct sSd_EventHandlerDynType
{
  Sd_NrOfClientsOfEventHandlerDynType NrOfClientsOfEventHandlerDyn;  /**< Nr of subscribed clients */
  Sd_EventHandlerCurrentStateType RequestStateOfEventHandlerDyn;  /**< Request state */
  Sd_EventHandlerStateMachineType StateMachineOfEventHandlerDyn;  /**< State machine */
} Sd_EventHandlerDynType;

/**   \brief  type used in Sd_EventHandlerMulticast */
typedef struct sSd_EventHandlerMulticastType
{
  Sd_RoutingGroupActRefIdxOfEventHandlerMulticastType RoutingGroupActRefIdxOfEventHandlerMulticast;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
  SoAd_SoConIdType SoConIdOfEventHandlerMulticast;  /**< SocketConnection used for multicast transmission */
} Sd_EventHandlerMulticastType;

/**   \brief  type used in Sd_EventHandlerTcp */
typedef struct sSd_EventHandlerTcpType
{
  Sd_RoutingGroupActRefIdxOfEventHandlerTcpType RoutingGroupActRefIdxOfEventHandlerTcp;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
  Sd_RoutingGroupTriggerIdxOfEventHandlerTcpType RoutingGroupTriggerIdxOfEventHandlerTcp;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
} Sd_EventHandlerTcpType;

/**   \brief  type used in Sd_EventHandlerUdp */
typedef struct sSd_EventHandlerUdpType
{
  Sd_RoutingGroupActRefIdxOfEventHandlerUdpType RoutingGroupActRefIdxOfEventHandlerUdp;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
  Sd_RoutingGroupTriggerIdxOfEventHandlerUdpType RoutingGroupTriggerIdxOfEventHandlerUdp;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
} Sd_EventHandlerUdpType;

/**   \brief  type used in Sd_Instance */
typedef struct sSd_InstanceType
{
  Sd_MulticastRxPduIdOfInstanceType MulticastRxPduIdOfInstance;  /**< RX PDU ID used for multicast reception */
  Sd_TxPduIdOfInstanceType TxPduIdOfInstance;  /**< TX PDU ID used for message transmission */
  Sd_UnicastRxPduIdOfInstanceType UnicastRxPduIdOfInstance;  /**< RX PDU ID used for unicast reception */
  Sd_AddressStorageEndIdxOfInstanceType AddressStorageEndIdxOfInstance;  /**< the end index of the 1:n relation pointing to Sd_AddressStorage */
  Sd_AddressStorageStartIdxOfInstanceType AddressStorageStartIdxOfInstance;  /**< the start index of the 1:n relation pointing to Sd_AddressStorage */
  Sd_CapabilityRecordEndIdxOfInstanceType CapabilityRecordEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_CapabilityRecordStartIdxOfInstanceType CapabilityRecordStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_ClientEndIdxOfInstanceType ClientEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_Client */
  Sd_ClientStartIdxOfInstanceType ClientStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_Client */
  Sd_EndpointStorageEndIdxOfInstanceType EndpointStorageEndIdxOfInstance;  /**< the end index of the 1:n relation pointing to Sd_EndpointStorage */
  Sd_EndpointStorageStartIdxOfInstanceType EndpointStorageStartIdxOfInstance;  /**< the start index of the 1:n relation pointing to Sd_EndpointStorage */
  Sd_EventHandlerEndIdxOfInstanceType EventHandlerEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_EventHandler */
  Sd_EventHandlerStartIdxOfInstanceType EventHandlerStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_EventHandler */
  Sd_LocalAddressCheckLengthOfInstanceType LocalAddressCheckLengthOfInstance;  /**< Number of leading bits which shall be compared between SdEndpoint and local address to check for the same subnet. */
  Sd_QueueProcessLimitOfInstanceType QueueProcessLimitOfInstance;  /**< Maximum number of Rx Queue Entries which shall be processed during one MainFunction cycle. */
  Sd_RetryDelayOfInstanceType RetryDelayOfInstance;  /**< Delay when a not answered subscription will be retriggered. */
  Sd_RetryMaxOfInstanceType RetryMaxOfInstance;  /**< Maximum count of subscription retries. */
  Sd_RxEventEndIdxOfInstanceType RxEventEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_RxEvent */
  Sd_RxEventStartIdxOfInstanceType RxEventStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_RxEvent */
  Sd_SendEntryCapacityOfInstanceType SendEntryCapacityOfInstance;  /**< Number of SendEntries reserved for this instance. */
  Sd_SendEntryEndIdxOfInstanceType SendEntryEndIdxOfInstance;  /**< the end index of the 1:n relation pointing to Sd_SendEntry */
  Sd_SendEntryStartIdxOfInstanceType SendEntryStartIdxOfInstance;  /**< the start index of the 1:n relation pointing to Sd_SendEntry */
  Sd_ServerEndIdxOfInstanceType ServerEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_Server */
  Sd_ServerStartIdxOfInstanceType ServerStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_Server */
  Sd_TcpSoConIdEndIdxOfInstanceType TcpSoConIdEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_TcpSoConIdStartIdxOfInstanceType TcpSoConIdStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_UdpSoConEndIdxOfInstanceType UdpSoConEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to Sd_UdpSoCon */
  Sd_UdpSoConStartIdxOfInstanceType UdpSoConStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to Sd_UdpSoCon */
  Sd_Dem_EventIdType EMalformedMsgIdOfInstance;  /**< DEM Event ID for malformed messages */
  Sd_Dem_EventIdType ENackRecvIdOfInstance;  /**< DEM Event ID for received SubscribeEventgroupNack messages */
  Sd_Dem_EventIdType EOutOfResIdOfInstance;  /**< DEM Event ID for too few available resources */
  Sd_IdsM_SecurityEventIdType SevDuplicateOfferOfInstance;  /**< IdsM Security Event ID for receiving a different Offer for a Client that is READY. */
  Sd_IdsM_SecurityEventIdType SevFailedMethodReqOfInstance;  /**< IdsM Security Event ID for failed Method Request ACL Check. */
  Sd_IdsM_SecurityEventIdType SevFailedOfferOfInstance;  /**< IdsM Security Event ID for failed Offer ACL Check. */
  Sd_IdsM_SecurityEventIdType SevFailedSubOfInstance;  /**< IdsM Security Event ID for failed Subscription ACL Check. */
  SoAd_SoConIdType MulticastRxSoConIdOfInstance;  /**< RX SocketConnection ID used for multicast reception */
  SoAd_SoConIdType TxSoConIdOfInstance;  /**< TX SocketConnection ID used for message transmission */
  SoAd_SoConIdType UnicastRxSoConIdOfInstance;  /**< RX SocketConnection ID used for unicast reception */
} Sd_InstanceType;

/**   \brief  type used in Sd_InstanceDyn */
typedef struct sSd_InstanceDynType
{
  Sd_RxEventEndIdxOfInstanceDynType RxEventEndIdxOfInstanceDyn;  /**< the index of the 1:1 relation pointing to Sd_RxEvent */
  Sd_RxEventListFullOfInstanceDynType RxEventListFullOfInstanceDyn;  /**< Full flag of dynamic queue */
  Sd_RxEventStartIdxOfInstanceDynType RxEventStartIdxOfInstanceDyn;  /**< the index of the 1:1 relation pointing to Sd_RxEvent */
  Sd_SendEntryFreeListHeadIdxOfInstanceDynType SendEntryFreeListHeadIdxOfInstanceDyn;  /**< the index of the 1:1 relation pointing to Sd_SendEntry */
  Sd_SendEntryFreeListTailIdxOfInstanceDynType SendEntryFreeListTailIdxOfInstanceDyn;  /**< the index of the 1:1 relation pointing to Sd_SendEntry */
  Sd_SendEntryNrPendingIdxOfInstanceDynType SendEntryNrPendingIdxOfInstanceDyn;  /**< the index of the 1:1 relation pointing to Sd_SendEntry */
  Sd_SizeOfEndpointStorageType LastFoundEndpointOfInstanceDyn;  /**< LastFoundEndpoint */
  Sd_ExtendedTimeType NextStateMachineRunOfInstanceDyn;  /**< Time indicating next execution of state machines */
  Sd_RunModeType RunModeOfInstanceDyn;  /**< Communication mode */
  Sd_ServiceInstanceStateType StateOfInstanceDyn;  /**< State */
} Sd_InstanceDynType;

/**   \brief  type used in Sd_IpAddrRequest */
typedef struct sSd_IpAddrRequestType
{
  Sd_StaticIpConfigurationOfIpAddrRequestType StaticIpConfigurationOfIpAddrRequest;  /**< Indicates if a static IP address is configured */
  Sd_StaticPortConfigurationOfIpAddrRequestType StaticPortConfigurationOfIpAddrRequest;  /**< Indicates is a static port is configured */
  Sd_PortSetIdxOfIpAddrRequestType PortSetIdxOfIpAddrRequest;  /**< the index of the 1:1 relation pointing to Sd_PortSet */
  Sd_RequestCntIdxOfIpAddrRequestType RequestCntIdxOfIpAddrRequest;  /**< the index of the 1:1 relation pointing to Sd_RequestCnt */
  SoAd_SoConIdType SoConIdOfIpAddrRequest;  /**< SocketConnection ID */
} Sd_IpAddrRequestType;

/**   \brief  type used in Sd_Method */
typedef struct sSd_MethodType
{
  Sd_TcpConfiguredOfMethodType TcpConfiguredOfMethod;  /**< Indicates whether the method is configured for TCP */
  Sd_UdpConfiguredOfMethodType UdpConfiguredOfMethod;  /**< Indicates whether the method is configured for UDP */
  Sd_RoutingGroupActRefIdxOfMethodType RoutingGroupActRefIdxOfMethod;  /**< the index of the 0:1 relation pointing to Sd_RoutingGroup */
} Sd_MethodType;

/**   \brief  type used in Sd_PartitionDataDyn */
typedef struct sSd_PartitionDataDynType
{
  Sd_NrOfOptionsOfPartitionDataDynType NrOfOptionsOfPartitionDataDyn;  /**< Number of options saved in the OptionIndex. */
  Sd_RxIndicationCountOfPartitionDataDynType RxIndicationCountOfPartitionDataDyn;  /**< Counter for calls of RxIndication. */
  Sd_TriggerTransmitDynEndIdxOfPartitionDataDynType TriggerTransmitDynEndIdxOfPartitionDataDyn;  /**< the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn */
  Sd_TriggerTransmitDynStartIdxOfPartitionDataDynType TriggerTransmitDynStartIdxOfPartitionDataDyn;  /**< the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn */
  Sd_TriggerTransmitFullOfPartitionDataDynType TriggerTransmitFullOfPartitionDataDyn;  /**< Indication whether trigger transmit ring buffer is full. */
  Sd_TxPathLockedOfPartitionDataDynType TxPathLockedOfPartitionDataDyn;  /**< Indication if transmission path is locked. */
  Sd_PartitionStateType InitializedOfPartitionDataDyn;  /**< initialized state of the partition */
  Sd_ExtendedTimeType TimeMsSinceStartOfPartitionDataDyn;  /**< Time since start of the component. */
} Sd_PartitionDataDynType;

/**   \brief  type used in Sd_PartitionIdentifiers */
typedef struct sSd_PartitionIdentifiersType
{
  Sd_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  Sd_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to Sd_PCPartitionConfig */
} Sd_PartitionIdentifiersType;

/**   \brief  type used in Sd_RoutingGroupDyn */
typedef struct sSd_RoutingGroupDynType
{
  Sd_RoutingGroupStatusType StatusOfRoutingGroupDyn;  /**< Status (disabled/enabled/unknown) of RoutingGroup */
} Sd_RoutingGroupDynType;

/**   \brief  type used in Sd_RoutingGroupIdMap */
typedef struct sSd_RoutingGroupIdMapType
{
  Sd_InvalidHndOfRoutingGroupIdMapType InvalidHndOfRoutingGroupIdMap;  /**< FALSE, if the handle of Sd_RoutingGroupIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_ServerIdxOfRoutingGroupIdMapType ServerIdxOfRoutingGroupIdMap;  /**< the index of the 0:1 relation pointing to Sd_Server */
  Sd_ServerPartitionIdxOfRoutingGroupIdMapType ServerPartitionIdxOfRoutingGroupIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_Server */
} Sd_RoutingGroupIdMapType;

/**   \brief  type used in Sd_RxEvent */
typedef struct sSd_RxEventType
{
  Sd_ClientListIdxOfRxEventType ClientListIdxOfRxEvent;  /**< the index of the 0:1 relation pointing to Sd_ClientList */
  Sd_EventHandlerIdxOfRxEventType EventHandlerIdxOfRxEvent;  /**< the index of the 0:1 relation pointing to Sd_EventHandler */
  Sd_ServerEventgroupEventType EventOfRxEvent;  /**< Received event */
} Sd_RxEventType;

/**   \brief  type used in Sd_RxPduIdMap */
typedef struct sSd_RxPduIdMapType
{
  Sd_InvalidHndOfRxPduIdMapType InvalidHndOfRxPduIdMap;  /**< FALSE, if the handle of Sd_RxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificInstanceIdxOfRxPduIdMapType PartitionSpecificInstanceIdxOfRxPduIdMap;  /**< the index of the 0:1 relation pointing to Sd_Instance */
  Sd_PartitionSpecificInstancePartitionIdxOfRxPduIdMapType PartitionSpecificInstancePartitionIdxOfRxPduIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_Instance */
} Sd_RxPduIdMapType;

/**   \brief  type used in Sd_SendEntry */
typedef struct sSd_SendEntryType
{
  Sd_EventHandlerIdOfSendEntryType EventHandlerIdOfSendEntry;  /**< EventHandler ID */
  Sd_InstanceIdOfSendEntryType InstanceIdOfSendEntry;  /**< Instance ID */
  Sd_ReservedFieldOfSendEntryType ReservedFieldOfSendEntry;  /**< Reserved Field */
  Sd_ServiceIdOfSendEntryType ServiceIdOfSendEntry;  /**< Service ID */
  Sd_ClientIdxOfSendEntryType ClientIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_Client */
  Sd_ClientListIdxOfSendEntryType ClientListIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_ClientList */
  Sd_ConsumedEventgroupIdxOfSendEntryType ConsumedEventgroupIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_ConsumedEventgroup */
  Sd_EventHandlerIdxOfSendEntryType EventHandlerIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_EventHandler */
  Sd_InstanceIdxOfSendEntryType InstanceIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_Instance */
  Sd_MajorVersionOfSendEntryType MajorVersionOfSendEntry;  /**< Major Version */
  Sd_SendEntryNextIdxOfSendEntryType SendEntryNextIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_SendEntry */
  Sd_SendEntryPrevIdxOfSendEntryType SendEntryPrevIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_SendEntry */
  Sd_ServerIdxOfSendEntryType ServerIdxOfSendEntry;  /**< the index of the 0:1 relation pointing to Sd_Server */
  Sd_EntryType EntryTypeOfSendEntry;  /**< Type of entry */
} Sd_SendEntryType;

/**   \brief  type used in Sd_Server */
typedef struct sSd_ServerType
{
  Sd_AutoAvailableOfServerType AutoAvailableOfServer;  /**< Auto available flag */
  Sd_ServiceGroupMemberOfServerType ServiceGroupMemberOfServer;  /**< Specifies if service is member of a ServiceGroup. */
  Sd_AclIPv4SIndEndIdxOfServerType AclIPv4SIndEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_AclIPv4SInd */
  Sd_AclIPv4SIndStartIdxOfServerType AclIPv4SIndStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_AclIPv4SInd */
  Sd_AclIPv6SIndEndIdxOfServerType AclIPv6SIndEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_AclIPv6SInd */
  Sd_AclIPv6SIndStartIdxOfServerType AclIPv6SIndStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_AclIPv6SInd */
  Sd_CapabilityRecordEndIdxOfServerType CapabilityRecordEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_CapabilityRecordFunctionCalloutPtrIdxOfServerType CapabilityRecordFunctionCalloutPtrIdxOfServer;  /**< the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr */
  Sd_CapabilityRecordStartIdxOfServerType CapabilityRecordStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_CapabilityRecord */
  Sd_CommonInitialDelayIdxOfServerType CommonInitialDelayIdxOfServer;  /**< the index of the 0:1 relation pointing to Sd_CommonInitialDelay */
  Sd_EventHandlerEndIdxOfServerType EventHandlerEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_EventHandler */
  Sd_EventHandlerStartIdxOfServerType EventHandlerStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_EventHandler */
  Sd_HandleIdOfServerType HandleIdOfServer;  /**< Handle ID */
  Sd_InitialInstanceIdOfServerType InitialInstanceIdOfServer;  /**< Initial Instance ID */
  Sd_InstanceIdxOfServerType InstanceIdxOfServer;  /**< the index of the 1:1 relation pointing to Sd_Instance */
  Sd_MajorVersionOfServerType MajorVersionOfServer;  /**< Major Version */
  Sd_MethodIdxOfServerType MethodIdxOfServer;  /**< the index of the 0:1 relation pointing to Sd_Method */
  Sd_MinorVersionOfServerType MinorVersionOfServer;  /**< Minor Version */
  Sd_ServerTimerIdxOfServerType ServerTimerIdxOfServer;  /**< the index of the 1:1 relation pointing to Sd_ServerTimer */
  Sd_ServiceIdOfServerType ServiceIdOfServer;  /**< Service ID */
  Sd_SoConGrpDynTcpIdxOfServerType SoConGrpDynTcpIdxOfServer;  /**< the index of the 0:1 relation pointing to Sd_SoConGrpDyn */
  Sd_SoConGrpDynUdpIdxOfServerType SoConGrpDynUdpIdxOfServer;  /**< the index of the 0:1 relation pointing to Sd_SoConGrpDyn */
  Sd_TcpSoConIdEndIdxOfServerType TcpSoConIdEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_TcpSoConIdStartIdxOfServerType TcpSoConIdStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_TcpSoConId */
  Sd_UdpSoConEndIdxOfServerType UdpSoConEndIdxOfServer;  /**< the end index of the 0:n relation pointing to Sd_UdpSoCon */
  Sd_UdpSoConStartIdxOfServerType UdpSoConStartIdxOfServer;  /**< the start index of the 0:n relation pointing to Sd_UdpSoCon */
} Sd_ServerType;

/**   \brief  type used in Sd_ServerDyn */
typedef struct sSd_ServerDynType
{
  Sd_InstanceIdOfServerDynType InstanceIdOfServerDyn;  /**< Current Instance ID of server service */
  Sd_InitialOfferRepetitionRunOfServerDynType InitialOfferRepetitionRunOfServerDyn;  /**< Counting the number of repetition runs */
  Sd_ServiceGroupReqCounterOfServerDynType ServiceGroupReqCounterOfServerDyn;  /**< Server availability counter for ServiceGroup service API */
  Sd_StateMachineExecutionRequestedOfServerDynType StateMachineExecutionRequestedOfServerDyn;  /**< Flag if State machine shall be executed for this server */
  Sd_ServerStateMachineType StateMachineOfServerDyn;  /**< State machine */
  Sd_ServerServiceSetStateType StateSwcOfServerDyn;  /**< Requested state */
  Sd_ExtendedTimeType TimeToTriggerSendOfServerDyn;  /**< Point in time the next message will be transmitted */
} Sd_ServerDynType;

/**   \brief  type used in Sd_ServerIdMap */
typedef struct sSd_ServerIdMapType
{
  Sd_InvalidHndOfServerIdMapType InvalidHndOfServerIdMap;  /**< FALSE, if the handle of Sd_ServerIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificServerIdxOfServerIdMapType PartitionSpecificServerIdxOfServerIdMap;  /**< the index of the 0:1 relation pointing to Sd_Server */
  Sd_PartitionSpecificServerPartitionIdxOfServerIdMapType PartitionSpecificServerPartitionIdxOfServerIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_Server */
} Sd_ServerIdMapType;

/**   \brief  type used in Sd_ServerTimer */
typedef struct sSd_ServerTimerType
{
  Sd_OfferCyclicDelayOfServerTimerType OfferCyclicDelayOfServerTimer;  /**< Delay used for cyclic transmission of OfferService messages. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS. */
  Sd_InitialOfferDelayMaxOfServerTimerType InitialOfferDelayMaxOfServerTimer;  /**< Initial maximal Offer delay */
  Sd_InitialOfferDelayMinOfServerTimerType InitialOfferDelayMinOfServerTimer;  /**< Initial minimal Offer delay */
  Sd_InitialOfferRepetitionBaseDelayOfServerTimerType InitialOfferRepetitionBaseDelayOfServerTimer;  /**< Base delay used for timing of OfferServices messages during repetition phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS. */
  Sd_InitialOfferRepetitionsMaxOfServerTimerType InitialOfferRepetitionsMaxOfServerTimer;  /**< Amount of OfferService messages transmitted during repetition phase */
  Sd_RequestResponseMaxDelayOfServerTimerType RequestResponseMaxDelayOfServerTimer;  /**< Maximal request-response delay */
  Sd_RequestResponseMinDelayOfServerTimerType RequestResponseMinDelayOfServerTimer;  /**< Minimal request-response delay */
  Sd_TTLOfServerTimerType TTLOfServerTimer;  /**< Time To Live */
} Sd_ServerTimerType;

/**   \brief  type used in Sd_ServiceGroup */
typedef struct sSd_ServiceGroupType
{
  Sd_ServiceGroupMemberEndIdxOfServiceGroupType ServiceGroupMemberEndIdxOfServiceGroup;  /**< the end index of the 1:n relation pointing to Sd_ServiceGroupMember */
  Sd_ServiceGroupMemberStartIdxOfServiceGroupType ServiceGroupMemberStartIdxOfServiceGroup;  /**< the start index of the 1:n relation pointing to Sd_ServiceGroupMember */
} Sd_ServiceGroupType;

/**   \brief  type used in Sd_ServiceGroupIdMap */
typedef struct sSd_ServiceGroupIdMapType
{
  Sd_InvalidHndOfServiceGroupIdMapType InvalidHndOfServiceGroupIdMap;  /**< FALSE, if the handle of Sd_ServiceGroupIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificServiceGroupIdxOfServiceGroupIdMapType PartitionSpecificServiceGroupIdxOfServiceGroupIdMap;  /**< the index of the 0:1 relation pointing to Sd_ServiceGroup */
  Sd_PartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMapType PartitionSpecificServiceGroupPartitionIdxOfServiceGroupIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_ServiceGroup */
} Sd_ServiceGroupIdMapType;

/**   \brief  type used in Sd_ServiceGroupMember */
typedef struct sSd_ServiceGroupMemberType
{
  Sd_ClientIdxOfServiceGroupMemberType ClientIdxOfServiceGroupMember;  /**< the index of the 0:1 relation pointing to Sd_Client */
  Sd_ServerIdxOfServiceGroupMemberType ServerIdxOfServiceGroupMember;  /**< the index of the 0:1 relation pointing to Sd_Server */
} Sd_ServiceGroupMemberType;

/**   \brief  type used in Sd_SoConActivationMap */
typedef struct sSd_SoConActivationMapType
{
  Sd_NrOfActivationsOfSoConActivationMapType NrOfActivationsOfSoConActivationMap;  /**< Nr of activations */
  SoAd_SoConIdType SoConIdOfSoConActivationMap;  /**< SocketConnection ID */
} Sd_SoConActivationMapType;

/**   \brief  type used in Sd_SoConGrpDyn */
typedef struct sSd_SoConGrpDynType
{
  Sd_LocalPortOfSoConGrpDynType LocalPortOfSoConGrpDyn;  /**< Local Port of the SoCon Group */
} Sd_SoConGrpDynType;

/**   \brief  type used in Sd_SoConModeIdMap */
typedef struct sSd_SoConModeIdMapType
{
  Sd_InvalidHndOfSoConModeIdMapType InvalidHndOfSoConModeIdMap;  /**< FALSE, if the handle of Sd_SoConModeIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificSoConModeIdxOfSoConModeIdMapType PartitionSpecificSoConModeIdxOfSoConModeIdMap;  /**< the index of the 0:1 relation pointing to Sd_SoConModeDyn */
  Sd_PartitionSpecificSoConModePartitionIdxOfSoConModeIdMapType PartitionSpecificSoConModePartitionIdxOfSoConModeIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_SoConModeDyn */
} Sd_SoConModeIdMapType;

/**   \brief  type used in Sd_TriggerTransmitDyn */
typedef struct sSd_TriggerTransmitDynType
{
  Sd_ClientListIdxOfTriggerTransmitDynType ClientListIdxOfTriggerTransmitDyn;  /**< the index of the 0:1 relation pointing to Sd_ClientList */
  Sd_EventHandlerIdxOfTriggerTransmitDynType EventHandlerIdxOfTriggerTransmitDyn;  /**< the index of the 0:1 relation pointing to Sd_EventHandler */
} Sd_TriggerTransmitDynType;

/**   \brief  type used in Sd_TxSoConIdMap */
typedef struct sSd_TxSoConIdMapType
{
  Sd_InvalidHndOfTxSoConIdMapType InvalidHndOfTxSoConIdMap;  /**< FALSE, if the handle of Sd_TxSoConIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  Sd_PartitionSpecificInstanceIdxOfTxSoConIdMapType PartitionSpecificInstanceIdxOfTxSoConIdMap;  /**< the index of the 0:1 relation pointing to Sd_Instance */
  Sd_PartitionSpecificInstancePartitionIdxOfTxSoConIdMapType PartitionSpecificInstancePartitionIdxOfTxSoConIdMap;  /**< the partition index of the 0:1 relation pointing to Sd_Instance */
} Sd_TxSoConIdMapType;

/**   \brief  type used in Sd_UdpSoCon */
typedef struct sSd_UdpSoConType
{
  Sd_PreconfiguredOfUdpSoConType PreconfiguredOfUdpSoCon;  /**< Specifies if SoCon is preconfigured with IP and Port or not */
  SoAd_SoConIdType IdOfUdpSoCon;  /**< IDs of UDP SocketConnections */
} Sd_UdpSoConType;

/** 
  \}
*/ 

/** 
  \defgroup  SdPCRootPointerTypes  Sd Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Sd_AclIPv4 */
typedef P2CONST(Sd_AclIPv4Type, TYPEDEF, SD_CONST) Sd_AclIPv4PtrType;

/**   \brief  type used to point to Sd_AclIPv4CInd */
typedef P2CONST(Sd_AclIPv4CIndType, TYPEDEF, SD_CONST) Sd_AclIPv4CIndPtrType;

/**   \brief  type used to point to Sd_AclIPv4SInd */
typedef P2CONST(Sd_AclIPv4SIndType, TYPEDEF, SD_CONST) Sd_AclIPv4SIndPtrType;

/**   \brief  type used to point to Sd_AclIPv6 */
typedef P2CONST(Sd_AclIPv6Type, TYPEDEF, SD_CONST) Sd_AclIPv6PtrType;

/**   \brief  type used to point to Sd_AclIPv6CInd */
typedef P2CONST(Sd_AclIPv6CIndType, TYPEDEF, SD_CONST) Sd_AclIPv6CIndPtrType;

/**   \brief  type used to point to Sd_AclIPv6SInd */
typedef P2CONST(Sd_AclIPv6SIndType, TYPEDEF, SD_CONST) Sd_AclIPv6SIndPtrType;

/**   \brief  type used to point to Sd_AddressStorage */
typedef P2VAR(Sd_AddressStorageType, TYPEDEF, SD_VAR_NO_INIT) Sd_AddressStoragePtrType;

/**   \brief  type used to point to Sd_AddrOfAddressStorage */
typedef P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_VAR_NO_INIT) Sd_AddrOfAddressStoragePtrType;

/**   \brief  type used to point to Sd_TimeToSendOfAddressStorage */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimeToSendOfAddressStoragePtrType;

/**   \brief  type used to point to Sd_CapabilityRecord */
typedef P2CONST(Sd_CapabilityRecordType, TYPEDEF, SD_CONST) Sd_CapabilityRecordPtrType;

/**   \brief  type used to point to Sd_CapabilityRecordFunctionCalloutPtr */
typedef P2CONST(Sd_CapabilityRecordCalloutFunctionApiType, TYPEDEF, SD_CONST) Sd_CapabilityRecordFunctionCalloutPtrPtrType;

/**   \brief  type used to point to Sd_Client */
typedef P2CONST(Sd_ClientType, TYPEDEF, SD_CONST) Sd_ClientPtrType;

/**   \brief  type used to point to Sd_ClientDyn */
typedef P2VAR(Sd_ClientDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_ClientDynPtrType;

/**   \brief  type used to point to Sd_MethodTcpSoConIdOfClientDyn */
typedef P2VAR(SoAd_SoConIdType, TYPEDEF, SD_VAR_NO_INIT) Sd_MethodTcpSoConIdOfClientDynPtrType;

/**   \brief  type used to point to Sd_MethodUdpSoConIdOfClientDyn */
typedef P2VAR(SoAd_SoConIdType, TYPEDEF, SD_VAR_NO_INIT) Sd_MethodUdpSoConIdOfClientDynPtrType;

/**   \brief  type used to point to Sd_RetryTimerOfClientDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_RetryTimerOfClientDynPtrType;

/**   \brief  type used to point to Sd_ServerTcpEndpointAddrOfClientDyn */
typedef P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_VAR_NO_INIT) Sd_ServerTcpEndpointAddrOfClientDynPtrType;

/**   \brief  type used to point to Sd_ServerUdpEndpointAddrOfClientDyn */
typedef P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_VAR_NO_INIT) Sd_ServerUdpEndpointAddrOfClientDynPtrType;

/**   \brief  type used to point to Sd_TimeToTriggerSendOfClientDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimeToTriggerSendOfClientDynPtrType;

/**   \brief  type used to point to Sd_TimerTTLOfClientDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimerTTLOfClientDynPtrType;

/**   \brief  type used to point to Sd_ClientIdMap */
typedef P2CONST(Sd_ClientIdMapType, TYPEDEF, SD_CONST) Sd_ClientIdMapPtrType;

/**   \brief  type used to point to Sd_ClientList */
typedef P2VAR(Sd_ClientListType, TYPEDEF, SD_VAR_NO_INIT) Sd_ClientListPtrType;

/**   \brief  type used to point to Sd_RxReservedOfClientList */
typedef P2VAR(Sd_RxReservedOfClientListType, TYPEDEF, SD_VAR_NO_INIT) Sd_RxReservedOfClientListPtrType;

/**   \brief  type used to point to Sd_SubscribedUntilOfClientList */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_SubscribedUntilOfClientListPtrType;

/**   \brief  type used to point to Sd_ClientTimer */
typedef P2CONST(Sd_ClientTimerType, TYPEDEF, SD_CONST) Sd_ClientTimerPtrType;

/**   \brief  type used to point to Sd_CommonInitialDelay */
typedef P2VAR(Sd_CommonInitialDelayType, TYPEDEF, SD_VAR_NO_INIT) Sd_CommonInitialDelayPtrType;

/**   \brief  type used to point to Sd_ConsumedEventgroup */
typedef P2CONST(Sd_ConsumedEventgroupType, TYPEDEF, SD_CONST) Sd_ConsumedEventgroupPtrType;

/**   \brief  type used to point to Sd_ConsumedEventgroupDyn */
typedef P2VAR(Sd_ConsumedEventgroupDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_ConsumedEventgroupDynPtrType;

/**   \brief  type used to point to Sd_TimerTTLOfConsumedEventgroupDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimerTTLOfConsumedEventgroupDynPtrType;

/**   \brief  type used to point to Sd_ConsumedEventgroupIdMap */
typedef P2CONST(Sd_ConsumedEventgroupIdMapType, TYPEDEF, SD_CONST) Sd_ConsumedEventgroupIdMapPtrType;

/**   \brief  type used to point to Sd_EndpointStorage */
typedef P2VAR(Sd_EndpointStorageType, TYPEDEF, SD_VAR_NO_INIT) Sd_EndpointStoragePtrType;

/**   \brief  type used to point to Sd_AddrOfEndpointStorage */
typedef P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_VAR_NO_INIT) Sd_AddrOfEndpointStoragePtrType;

/**   \brief  type used to point to Sd_EventHandler */
typedef P2CONST(Sd_EventHandlerType, TYPEDEF, SD_CONST) Sd_EventHandlerPtrType;

/**   \brief  type used to point to Sd_EventHandlerDyn */
typedef P2VAR(Sd_EventHandlerDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_EventHandlerDynPtrType;

/**   \brief  type used to point to Sd_EventHandlerMulticast */
typedef P2CONST(Sd_EventHandlerMulticastType, TYPEDEF, SD_CONST) Sd_EventHandlerMulticastPtrType;

/**   \brief  type used to point to Sd_EventHandlerTcp */
typedef P2CONST(Sd_EventHandlerTcpType, TYPEDEF, SD_CONST) Sd_EventHandlerTcpPtrType;

/**   \brief  type used to point to Sd_EventHandlerUdp */
typedef P2CONST(Sd_EventHandlerUdpType, TYPEDEF, SD_CONST) Sd_EventHandlerUdpPtrType;

/**   \brief  type used to point to Sd_Instance */
typedef P2CONST(Sd_InstanceType, TYPEDEF, SD_CONST) Sd_InstancePtrType;

/**   \brief  type used to point to Sd_InstanceDyn */
typedef P2VAR(Sd_InstanceDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_InstanceDynPtrType;

/**   \brief  type used to point to Sd_NextStateMachineRunOfInstanceDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_NextStateMachineRunOfInstanceDynPtrType;

/**   \brief  type used to point to Sd_IpAddrRequest */
typedef P2CONST(Sd_IpAddrRequestType, TYPEDEF, SD_CONST) Sd_IpAddrRequestPtrType;

/**   \brief  type used to point to Sd_Method */
typedef P2CONST(Sd_MethodType, TYPEDEF, SD_CONST) Sd_MethodPtrType;

/**   \brief  type used to point to Sd_MulticastEndpointAddr */
typedef P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_VAR_NO_INIT) Sd_MulticastEndpointAddrPtrType;

/**   \brief  type used to point to Sd_MulticastSoConId */
typedef P2CONST(SoAd_SoConIdType, TYPEDEF, SD_CONST) Sd_MulticastSoConIdPtrType;

/**   \brief  type used to point to Sd_OptionIndex */
typedef P2VAR(Sd_OptionIndexType, TYPEDEF, SD_VAR_NO_INIT) Sd_OptionIndexPtrType;

/**   \brief  type used to point to Sd_PartitionDataDyn */
typedef P2VAR(Sd_PartitionDataDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_PartitionDataDynPtrType;

/**   \brief  type used to point to Sd_InitializedOfPartitionDataDyn */
typedef P2VAR(Sd_PartitionStateType, TYPEDEF, SD_VAR_NO_INIT) Sd_InitializedOfPartitionDataDynPtrType;

/**   \brief  type used to point to Sd_TimeMsSinceStartOfPartitionDataDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimeMsSinceStartOfPartitionDataDynPtrType;

/**   \brief  type used to point to Sd_PartitionIdentifiers */
typedef P2CONST(Sd_PartitionIdentifiersType, TYPEDEF, SD_CONST) Sd_PartitionIdentifiersPtrType;

/**   \brief  type used to point to Sd_Payload */
typedef P2VAR(Sd_PayloadType, TYPEDEF, SD_VAR_NO_INIT) Sd_PayloadPtrType;

/**   \brief  type used to point to Sd_PortSet */
typedef P2VAR(Sd_PortSetType, TYPEDEF, SD_VAR_NO_INIT) Sd_PortSetPtrType;

/**   \brief  type used to point to Sd_RequestCnt */
typedef P2VAR(Sd_RequestCntType, TYPEDEF, SD_VAR_NO_INIT) Sd_RequestCntPtrType;

/**   \brief  type used to point to Sd_RoutingGroup */
typedef P2CONST(SoAd_RoutingGroupIdType, TYPEDEF, SD_CONST) Sd_RoutingGroupPtrType;

/**   \brief  type used to point to Sd_RoutingGroupDyn */
typedef P2VAR(Sd_RoutingGroupDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_RoutingGroupDynPtrType;

/**   \brief  type used to point to Sd_RoutingGroupIdMap */
typedef P2CONST(Sd_RoutingGroupIdMapType, TYPEDEF, SD_CONST) Sd_RoutingGroupIdMapPtrType;

/**   \brief  type used to point to Sd_RxEvent */
typedef P2VAR(Sd_RxEventType, TYPEDEF, SD_VAR_NO_INIT) Sd_RxEventPtrType;

/**   \brief  type used to point to Sd_RxPduIdMap */
typedef P2CONST(Sd_RxPduIdMapType, TYPEDEF, SD_CONST) Sd_RxPduIdMapPtrType;

/**   \brief  type used to point to Sd_SendEntry */
typedef P2VAR(Sd_SendEntryType, TYPEDEF, SD_VAR_NO_INIT) Sd_SendEntryPtrType;

/**   \brief  type used to point to Sd_Server */
typedef P2CONST(Sd_ServerType, TYPEDEF, SD_CONST) Sd_ServerPtrType;

/**   \brief  type used to point to Sd_ServerDyn */
typedef P2VAR(Sd_ServerDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_ServerDynPtrType;

/**   \brief  type used to point to Sd_TimeToTriggerSendOfServerDyn */
typedef P2VAR(Sd_ExtendedTimeType, TYPEDEF, SD_VAR_NO_INIT) Sd_TimeToTriggerSendOfServerDynPtrType;

/**   \brief  type used to point to Sd_ServerIdMap */
typedef P2CONST(Sd_ServerIdMapType, TYPEDEF, SD_CONST) Sd_ServerIdMapPtrType;

/**   \brief  type used to point to Sd_ServerTimer */
typedef P2CONST(Sd_ServerTimerType, TYPEDEF, SD_CONST) Sd_ServerTimerPtrType;

/**   \brief  type used to point to Sd_ServiceGroup */
typedef P2CONST(Sd_ServiceGroupType, TYPEDEF, SD_CONST) Sd_ServiceGroupPtrType;

/**   \brief  type used to point to Sd_ServiceGroupIdMap */
typedef P2CONST(Sd_ServiceGroupIdMapType, TYPEDEF, SD_CONST) Sd_ServiceGroupIdMapPtrType;

/**   \brief  type used to point to Sd_ServiceGroupMember */
typedef P2CONST(Sd_ServiceGroupMemberType, TYPEDEF, SD_CONST) Sd_ServiceGroupMemberPtrType;

/**   \brief  type used to point to Sd_SoConActivationMap */
typedef P2VAR(Sd_SoConActivationMapType, TYPEDEF, SD_VAR_NO_INIT) Sd_SoConActivationMapPtrType;

/**   \brief  type used to point to Sd_SoConGrpDyn */
typedef P2VAR(Sd_SoConGrpDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_SoConGrpDynPtrType;

/**   \brief  type used to point to Sd_SoConModeDyn */
typedef P2VAR(Sd_SoConModeType, TYPEDEF, SD_VAR_NO_INIT) Sd_SoConModeDynPtrType;

/**   \brief  type used to point to Sd_SoConModeIdMap */
typedef P2CONST(Sd_SoConModeIdMapType, TYPEDEF, SD_CONST) Sd_SoConModeIdMapPtrType;

/**   \brief  type used to point to Sd_TcpSoConId */
typedef P2CONST(SoAd_SoConIdType, TYPEDEF, SD_CONST) Sd_TcpSoConIdPtrType;

/**   \brief  type used to point to Sd_TriggerTransmitDyn */
typedef P2VAR(Sd_TriggerTransmitDynType, TYPEDEF, SD_VAR_NO_INIT) Sd_TriggerTransmitDynPtrType;

/**   \brief  type used to point to Sd_TxSoConIdMap */
typedef P2CONST(Sd_TxSoConIdMapType, TYPEDEF, SD_CONST) Sd_TxSoConIdMapPtrType;

/**   \brief  type used to point to Sd_UdpSoCon */
typedef P2CONST(Sd_UdpSoConType, TYPEDEF, SD_CONST) Sd_UdpSoConPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SdPCPartitionRootPointer  Sd Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in Sd_PCPartitionConfig */
typedef struct sSd_PCPartitionConfigType
{
  Sd_AclIPv4PtrType AclIPv4OfPCPartitionConfig;  /**< the pointer to Sd_AclIPv4 */
  Sd_AclIPv4CIndPtrType AclIPv4CIndOfPCPartitionConfig;  /**< the pointer to Sd_AclIPv4CInd */
  Sd_AclIPv4SIndPtrType AclIPv4SIndOfPCPartitionConfig;  /**< the pointer to Sd_AclIPv4SInd */
  Sd_AclIPv6PtrType AclIPv6OfPCPartitionConfig;  /**< the pointer to Sd_AclIPv6 */
  Sd_AclIPv6CIndPtrType AclIPv6CIndOfPCPartitionConfig;  /**< the pointer to Sd_AclIPv6CInd */
  Sd_AclIPv6SIndPtrType AclIPv6SIndOfPCPartitionConfig;  /**< the pointer to Sd_AclIPv6SInd */
  Sd_AddressStoragePtrType AddressStorageOfPCPartitionConfig;  /**< the pointer to Sd_AddressStorage */
  Sd_CapabilityRecordPtrType CapabilityRecordOfPCPartitionConfig;  /**< the pointer to Sd_CapabilityRecord */
  Sd_CapabilityRecordFunctionCalloutPtrPtrType CapabilityRecordFunctionCalloutPtrOfPCPartitionConfig;  /**< the pointer to Sd_CapabilityRecordFunctionCalloutPtr */
  Sd_ClientPtrType ClientOfPCPartitionConfig;  /**< the pointer to Sd_Client */
  Sd_ClientDynPtrType ClientDynOfPCPartitionConfig;  /**< the pointer to Sd_ClientDyn */
  Sd_ClientIdMapPtrType ClientIdMapOfPCPartitionConfig;  /**< the pointer to Sd_ClientIdMap */
  Sd_ClientListPtrType ClientListOfPCPartitionConfig;  /**< the pointer to Sd_ClientList */
  Sd_ClientTimerPtrType ClientTimerOfPCPartitionConfig;  /**< the pointer to Sd_ClientTimer */
  Sd_CommonInitialDelayPtrType CommonInitialDelayOfPCPartitionConfig;  /**< the pointer to Sd_CommonInitialDelay */
  Sd_ConsumedEventgroupPtrType ConsumedEventgroupOfPCPartitionConfig;  /**< the pointer to Sd_ConsumedEventgroup */
  Sd_ConsumedEventgroupDynPtrType ConsumedEventgroupDynOfPCPartitionConfig;  /**< the pointer to Sd_ConsumedEventgroupDyn */
  Sd_ConsumedEventgroupIdMapPtrType ConsumedEventgroupIdMapOfPCPartitionConfig;  /**< the pointer to Sd_ConsumedEventgroupIdMap */
  Sd_EndpointStoragePtrType EndpointStorageOfPCPartitionConfig;  /**< the pointer to Sd_EndpointStorage */
  Sd_EventHandlerPtrType EventHandlerOfPCPartitionConfig;  /**< the pointer to Sd_EventHandler */
  Sd_EventHandlerDynPtrType EventHandlerDynOfPCPartitionConfig;  /**< the pointer to Sd_EventHandlerDyn */
  Sd_EventHandlerMulticastPtrType EventHandlerMulticastOfPCPartitionConfig;  /**< the pointer to Sd_EventHandlerMulticast */
  Sd_EventHandlerTcpPtrType EventHandlerTcpOfPCPartitionConfig;  /**< the pointer to Sd_EventHandlerTcp */
  Sd_EventHandlerUdpPtrType EventHandlerUdpOfPCPartitionConfig;  /**< the pointer to Sd_EventHandlerUdp */
  Sd_InstancePtrType InstanceOfPCPartitionConfig;  /**< the pointer to Sd_Instance */
  Sd_InstanceDynPtrType InstanceDynOfPCPartitionConfig;  /**< the pointer to Sd_InstanceDyn */
  Sd_IpAddrRequestPtrType IpAddrRequestOfPCPartitionConfig;  /**< the pointer to Sd_IpAddrRequest */
  Sd_MethodPtrType MethodOfPCPartitionConfig;  /**< the pointer to Sd_Method */
  Sd_MulticastEndpointAddrPtrType MulticastEndpointAddrOfPCPartitionConfig;  /**< the pointer to Sd_MulticastEndpointAddr */
  Sd_MulticastSoConIdPtrType MulticastSoConIdOfPCPartitionConfig;  /**< the pointer to Sd_MulticastSoConId */
  Sd_OptionIndexPtrType OptionIndexOfPCPartitionConfig;  /**< the pointer to Sd_OptionIndex */
  Sd_PartitionDataDynPtrType PartitionDataDynOfPCPartitionConfig;  /**< the pointer to Sd_PartitionDataDyn */
  Sd_PayloadPtrType PayloadOfPCPartitionConfig;  /**< the pointer to Sd_Payload */
  Sd_PortSetPtrType PortSetOfPCPartitionConfig;  /**< the pointer to Sd_PortSet */
  Sd_RequestCntPtrType RequestCntOfPCPartitionConfig;  /**< the pointer to Sd_RequestCnt */
  Sd_RoutingGroupPtrType RoutingGroupOfPCPartitionConfig;  /**< the pointer to Sd_RoutingGroup */
  Sd_RoutingGroupDynPtrType RoutingGroupDynOfPCPartitionConfig;  /**< the pointer to Sd_RoutingGroupDyn */
  Sd_RoutingGroupIdMapPtrType RoutingGroupIdMapOfPCPartitionConfig;  /**< the pointer to Sd_RoutingGroupIdMap */
  Sd_RxEventPtrType RxEventOfPCPartitionConfig;  /**< the pointer to Sd_RxEvent */
  Sd_RxPduIdMapPtrType RxPduIdMapOfPCPartitionConfig;  /**< the pointer to Sd_RxPduIdMap */
  Sd_SendEntryPtrType SendEntryOfPCPartitionConfig;  /**< the pointer to Sd_SendEntry */
  Sd_ServerPtrType ServerOfPCPartitionConfig;  /**< the pointer to Sd_Server */
  Sd_ServerDynPtrType ServerDynOfPCPartitionConfig;  /**< the pointer to Sd_ServerDyn */
  Sd_ServerIdMapPtrType ServerIdMapOfPCPartitionConfig;  /**< the pointer to Sd_ServerIdMap */
  Sd_ServerTimerPtrType ServerTimerOfPCPartitionConfig;  /**< the pointer to Sd_ServerTimer */
  Sd_ServiceGroupPtrType ServiceGroupOfPCPartitionConfig;  /**< the pointer to Sd_ServiceGroup */
  Sd_ServiceGroupIdMapPtrType ServiceGroupIdMapOfPCPartitionConfig;  /**< the pointer to Sd_ServiceGroupIdMap */
  Sd_ServiceGroupMemberPtrType ServiceGroupMemberOfPCPartitionConfig;  /**< the pointer to Sd_ServiceGroupMember */
  Sd_SoConActivationMapPtrType SoConActivationMapOfPCPartitionConfig;  /**< the pointer to Sd_SoConActivationMap */
  Sd_SoConGrpDynPtrType SoConGrpDynOfPCPartitionConfig;  /**< the pointer to Sd_SoConGrpDyn */
  Sd_SoConModeDynPtrType SoConModeDynOfPCPartitionConfig;  /**< the pointer to Sd_SoConModeDyn */
  Sd_SoConModeIdMapPtrType SoConModeIdMapOfPCPartitionConfig;  /**< the pointer to Sd_SoConModeIdMap */
  Sd_TcpSoConIdPtrType TcpSoConIdOfPCPartitionConfig;  /**< the pointer to Sd_TcpSoConId */
  Sd_TriggerTransmitDynPtrType TriggerTransmitDynOfPCPartitionConfig;  /**< the pointer to Sd_TriggerTransmitDyn */
  Sd_TxSoConIdMapPtrType TxSoConIdMapOfPCPartitionConfig;  /**< the pointer to Sd_TxSoConIdMap */
  Sd_UdpSoConPtrType UdpSoConOfPCPartitionConfig;  /**< the pointer to Sd_UdpSoCon */
  Sd_SizeOfPayloadType SizeOfPayloadOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_Payload */
  Sd_SizeOfAclIPv4Type SizeOfAclIPv4OfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv4 */
  Sd_SizeOfAclIPv4CIndType SizeOfAclIPv4CIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv4CInd */
  Sd_SizeOfAclIPv4SIndType SizeOfAclIPv4SIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv4SInd */
  Sd_SizeOfAclIPv6Type SizeOfAclIPv6OfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv6 */
  Sd_SizeOfAclIPv6CIndType SizeOfAclIPv6CIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv6CInd */
  Sd_SizeOfAclIPv6SIndType SizeOfAclIPv6SIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AclIPv6SInd */
  Sd_SizeOfAddressStorageType SizeOfAddressStorageOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_AddressStorage */
  Sd_SizeOfCapabilityRecordType SizeOfCapabilityRecordOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_CapabilityRecord */
  Sd_SizeOfCapabilityRecordFunctionCalloutPtrType SizeOfCapabilityRecordFunctionCalloutPtrOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_CapabilityRecordFunctionCalloutPtr */
  Sd_SizeOfClientType SizeOfClientOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_Client */
  Sd_SizeOfClientIdMapType SizeOfClientIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ClientIdMap */
  Sd_SizeOfClientListType SizeOfClientListOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ClientList */
  Sd_SizeOfClientTimerType SizeOfClientTimerOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ClientTimer */
  Sd_SizeOfCommonInitialDelayType SizeOfCommonInitialDelayOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_CommonInitialDelay */
  Sd_SizeOfConsumedEventgroupType SizeOfConsumedEventgroupOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ConsumedEventgroup */
  Sd_SizeOfConsumedEventgroupIdMapType SizeOfConsumedEventgroupIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ConsumedEventgroupIdMap */
  Sd_SizeOfEndpointStorageType SizeOfEndpointStorageOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_EndpointStorage */
  Sd_SizeOfEventHandlerType SizeOfEventHandlerOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_EventHandler */
  Sd_SizeOfEventHandlerMulticastType SizeOfEventHandlerMulticastOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_EventHandlerMulticast */
  Sd_SizeOfEventHandlerTcpType SizeOfEventHandlerTcpOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_EventHandlerTcp */
  Sd_SizeOfEventHandlerUdpType SizeOfEventHandlerUdpOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_EventHandlerUdp */
  Sd_SizeOfInstanceType SizeOfInstanceOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_Instance */
  Sd_SizeOfIpAddrRequestType SizeOfIpAddrRequestOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_IpAddrRequest */
  Sd_SizeOfMethodType SizeOfMethodOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_Method */
  Sd_SizeOfMulticastEndpointAddrType SizeOfMulticastEndpointAddrOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_MulticastEndpointAddr */
  Sd_SizeOfMulticastSoConIdType SizeOfMulticastSoConIdOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_MulticastSoConId */
  Sd_SizeOfOptionIndexType SizeOfOptionIndexOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_OptionIndex */
  Sd_SizeOfPartitionDataDynType SizeOfPartitionDataDynOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_PartitionDataDyn */
  Sd_SizeOfPortSetType SizeOfPortSetOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_PortSet */
  Sd_SizeOfRequestCntType SizeOfRequestCntOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_RequestCnt */
  Sd_SizeOfRoutingGroupType SizeOfRoutingGroupOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_RoutingGroup */
  Sd_SizeOfRoutingGroupIdMapType SizeOfRoutingGroupIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_RoutingGroupIdMap */
  Sd_SizeOfRxEventType SizeOfRxEventOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_RxEvent */
  Sd_SizeOfRxPduIdMapType SizeOfRxPduIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_RxPduIdMap */
  Sd_SizeOfSendEntryType SizeOfSendEntryOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_SendEntry */
  Sd_SizeOfServerType SizeOfServerOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_Server */
  Sd_SizeOfServerIdMapType SizeOfServerIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ServerIdMap */
  Sd_SizeOfServerTimerType SizeOfServerTimerOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ServerTimer */
  Sd_SizeOfServiceGroupType SizeOfServiceGroupOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ServiceGroup */
  Sd_SizeOfServiceGroupIdMapType SizeOfServiceGroupIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ServiceGroupIdMap */
  Sd_SizeOfServiceGroupMemberType SizeOfServiceGroupMemberOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_ServiceGroupMember */
  Sd_SizeOfSoConActivationMapType SizeOfSoConActivationMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_SoConActivationMap */
  Sd_SizeOfSoConGrpDynType SizeOfSoConGrpDynOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_SoConGrpDyn */
  Sd_SizeOfSoConModeDynType SizeOfSoConModeDynOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_SoConModeDyn */
  Sd_SizeOfSoConModeIdMapType SizeOfSoConModeIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_SoConModeIdMap */
  Sd_SizeOfTcpSoConIdType SizeOfTcpSoConIdOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_TcpSoConId */
  Sd_SizeOfTriggerTransmitDynType SizeOfTriggerTransmitDynOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_TriggerTransmitDyn */
  Sd_SizeOfTxSoConIdMapType SizeOfTxSoConIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_TxSoConIdMap */
  Sd_SizeOfUdpSoConType SizeOfUdpSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in Sd_UdpSoCon */
} Sd_PCPartitionConfigType;

/**   \brief  type used to point to Sd_PCPartitionConfig */
typedef P2CONST(Sd_PCPartitionConfigType, TYPEDEF, SD_CONST) Sd_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SdPCRootValueTypes  Sd Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Sd_PCConfig */
typedef struct sSd_PCConfigType
{
  Sd_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to Sd_PCPartitionConfig */
  Sd_PartitionIdentifiersPtrType PartitionIdentifiersOfPCConfig;  /**< the pointer to Sd_PartitionIdentifiers */
  Sd_SizeOfPartitionIdentifiersType SizeOfPartitionIdentifiersOfPCConfig;  /**< the number of accomplishable value elements in Sd_PartitionIdentifiers */
} Sd_PCConfigType;

typedef Sd_PCConfigType Sd_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access Sd_PCConfig in a symbol based style. */
typedef struct sSd_PCConfigsType
{
  Sd_PCConfigType Config;  /**< [Config] */
} Sd_PCConfigsType;

/** 
  \}
*/ 




typedef struct
{
  SD_P2CONST(PduInfoType)             PduInfoPtr;
  Sd_SizeOfAddressStorageType         AddressStorageIdx;
  boolean                             MulticastMessage;
} Sd_RxMessageInfoType;

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Sd_Client
**********************************************************************************************************************/
/** 
  \var    Sd_Client
  \brief  Configuration data of SdClientService. List is sorted by ServiceId (and HandleId if ServiceId is not unique) per SdInstance.
  \details
  Element                                  Description
  ServiceId                                Service ID
  AutoRequire                              Auto require flag
  MinorVersionWildcard                     Indicates if MinorVersion is configured to wildcard.
  ServiceGroupMember                       Specifies if service is member of a ServiceGroup.
  UdpClientMulticast                       Specifies if CEG of service use UDP ClientMulticast or UDP Unicast.
  AclIPv4CIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv4CInd
  AclIPv4CIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv4CInd
  AclIPv6CIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv6CInd
  AclIPv6CIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv6CInd
  CapabilityRecordEndIdx                   the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtrIdx    the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr
  CapabilityRecordStartIdx                 the start index of the 0:n relation pointing to Sd_CapabilityRecord
  ClientTimerIdx                           the index of the 1:1 relation pointing to Sd_ClientTimer
  CommonInitialDelayIdx                    the index of the 0:1 relation pointing to Sd_CommonInitialDelay
  ConsumedEventgroupEndIdx                 the end index of the 0:n relation pointing to Sd_ConsumedEventgroup
  ConsumedEventgroupStartIdx               the start index of the 0:n relation pointing to Sd_ConsumedEventgroup
  HandleId                                 Handle ID
  InitialInstanceId                        InitialInstance ID
  InstanceIdx                              the index of the 1:1 relation pointing to Sd_Instance
  MajorVersion                             Major Version
  MethodIdx                                the index of the 0:1 relation pointing to Sd_Method
  MinorVersion                             Minor Version
  SoConGrpDynTcpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  SoConGrpDynUdpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  TcpSoConIdEndIdx                         the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx                       the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx                           the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx                         the start index of the 0:n relation pointing to Sd_UdpSoCon
  FindBehavior                             SdVersionDrivenFindBehavior
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ClientType, SD_CONST) Sd_Client[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ClientIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific client IDs.
  \details
  Element                                Description
  InvalidHnd                             FALSE, if the handle of Sd_ClientIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificClientIdx             the index of the 0:1 relation pointing to Sd_Client
  PartitionSpecificClientPartitionIdx    the partition index of the 0:1 relation pointing to Sd_Client
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ClientIdMapType, SD_CONST) Sd_ClientIdMap[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientTimer
**********************************************************************************************************************/
/** 
  \var    Sd_ClientTimer
  \brief  Timer parameter for SdClientService and SdConsumedEventgroup
  \details
  Element                           Description
  InitialFindDelayMax               Maximal initial delay for FindService message
  InitialFindDelayMin               Minimal initial delay for FindService message
  InitialFindRepetitionBaseDelay    Base delay for FindService messages during initial find phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialFindRepetitionsMax         Amount of FindService messages transmitted during initial find phase
  RequestResponseMaxDelay           Maximal request-response delay
  RequestResponseMinDelay           Minimal request-response delay
  TTL                               Time To Live
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ClientTimerType, SD_CONST) Sd_ClientTimer[2];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroup
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroup
  \brief  Configuration data of SdConsumedEventgroup
  \details
  Element                           Description
  AutoRequire                       Auto require flag
  ClientIdx                         the index of the 1:1 relation pointing to Sd_Client
  ClientTimerIdx                    the index of the 1:1 relation pointing to Sd_ClientTimer
  EventGroupId                      Eventgroup ID
  HandleId                          Handle ID
  MulticastEndpointAddrIdx          the index of the 0:1 relation pointing to Sd_MulticastEndpointAddr
  MulticastSoConIdEndIdx            the end index of the 0:n relation pointing to Sd_MulticastSoConId
  MulticastSoConIdStartIdx          the start index of the 0:n relation pointing to Sd_MulticastSoConId
  RoutingGroupMulticastActRefIdx    the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupTcpActRefIdx          the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupUdpActRefIdx          the index of the 0:1 relation pointing to Sd_RoutingGroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ConsumedEventgroupType, SD_CONST) Sd_ConsumedEventgroup[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroupIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroupIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific consumed eventgroup IDs.
  \details
  Element                                            Description
  InvalidHnd                                         FALSE, if the handle of Sd_ConsumedEventgroupIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificConsumedEventgroupIdx             the index of the 0:1 relation pointing to Sd_ConsumedEventgroup
  PartitionSpecificConsumedEventgroupPartitionIdx    the partition index of the 0:1 relation pointing to Sd_ConsumedEventgroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ConsumedEventgroupIdMapType, SD_CONST) Sd_ConsumedEventgroupIdMap[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandler
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandler
  \brief  Configuration data of SdEventHandler
  \details
  Element                       Description
  ClientListEndIdx              the end index of the 1:n relation pointing to Sd_ClientList
  ClientListStartIdx            the start index of the 1:n relation pointing to Sd_ClientList
  EventGroupId                  Eventgroup ID
  EventHandlerMulticastIdx      the index of the 0:1 relation pointing to Sd_EventHandlerMulticast
  EventHandlerTcpIdx            the index of the 0:1 relation pointing to Sd_EventHandlerTcp
  EventHandlerUdpIdx            the index of the 0:1 relation pointing to Sd_EventHandlerUdp
  HandleId                      Handle ID
  MulticastThreshold            Multicast threshold
  ServerIdx                     the index of the 1:1 relation pointing to Sd_Server
  ServerTimerIdx                the index of the 1:1 relation pointing to Sd_ServerTimer
  SoConActivationMapEndIdx      the end index of the 0:n relation pointing to Sd_SoConActivationMap
  SoConActivationMapStartIdx    the start index of the 0:n relation pointing to Sd_SoConActivationMap
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_EventHandlerType, SD_CONST) Sd_EventHandler[3];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandlerUdp
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandlerUdp
  \brief  Configuration of SdEventHandlerUdp
  \details
  Element                   Description
  RoutingGroupActRefIdx     the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupTriggerIdx    the index of the 0:1 relation pointing to Sd_RoutingGroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_EventHandlerUdpType, SD_CONST) Sd_EventHandlerUdp[3];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Instance
**********************************************************************************************************************/
/** 
  \var    Sd_Instance
  \brief  Configuration data for SdInstance
  \details
  Element                     Description
  MulticastRxPduId            RX PDU ID used for multicast reception
  TxPduId                     TX PDU ID used for message transmission
  UnicastRxPduId              RX PDU ID used for unicast reception
  AddressStorageEndIdx        the end index of the 1:n relation pointing to Sd_AddressStorage
  AddressStorageStartIdx      the start index of the 1:n relation pointing to Sd_AddressStorage
  CapabilityRecordEndIdx      the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordStartIdx    the start index of the 0:n relation pointing to Sd_CapabilityRecord
  ClientEndIdx                the end index of the 0:n relation pointing to Sd_Client
  ClientStartIdx              the start index of the 0:n relation pointing to Sd_Client
  EndpointStorageEndIdx       the end index of the 1:n relation pointing to Sd_EndpointStorage
  EndpointStorageStartIdx     the start index of the 1:n relation pointing to Sd_EndpointStorage
  EventHandlerEndIdx          the end index of the 0:n relation pointing to Sd_EventHandler
  EventHandlerStartIdx        the start index of the 0:n relation pointing to Sd_EventHandler
  LocalAddressCheckLength     Number of leading bits which shall be compared between SdEndpoint and local address to check for the same subnet.
  QueueProcessLimit           Maximum number of Rx Queue Entries which shall be processed during one MainFunction cycle.
  RetryDelay                  Delay when a not answered subscription will be retriggered.
  RetryMax                    Maximum count of subscription retries.
  RxEventEndIdx               the end index of the 0:n relation pointing to Sd_RxEvent
  RxEventStartIdx             the start index of the 0:n relation pointing to Sd_RxEvent
  SendEntryCapacity           Number of SendEntries reserved for this instance.
  SendEntryEndIdx             the end index of the 1:n relation pointing to Sd_SendEntry
  SendEntryStartIdx           the start index of the 1:n relation pointing to Sd_SendEntry
  ServerEndIdx                the end index of the 0:n relation pointing to Sd_Server
  ServerStartIdx              the start index of the 0:n relation pointing to Sd_Server
  TcpSoConIdEndIdx            the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx          the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx              the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx            the start index of the 0:n relation pointing to Sd_UdpSoCon
  EMalformedMsgId             DEM Event ID for malformed messages
  ENackRecvId                 DEM Event ID for received SubscribeEventgroupNack messages
  EOutOfResId                 DEM Event ID for too few available resources
  SevDuplicateOffer           IdsM Security Event ID for receiving a different Offer for a Client that is READY.
  SevFailedMethodReq          IdsM Security Event ID for failed Method Request ACL Check.
  SevFailedOffer              IdsM Security Event ID for failed Offer ACL Check.
  SevFailedSub                IdsM Security Event ID for failed Subscription ACL Check.
  MulticastRxSoConId          RX SocketConnection ID used for multicast reception
  TxSoConId                   TX SocketConnection ID used for message transmission
  UnicastRxSoConId            RX SocketConnection ID used for unicast reception
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_InstanceType, SD_CONST) Sd_Instance[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Sd_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Sd_PCPartitionConfig
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_PartitionIdentifiersType, SD_CONST) Sd_PartitionIdentifiers[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RoutingGroup
**********************************************************************************************************************/
/** 
  \var    Sd_RoutingGroup
  \brief  SoAd RoutingGroups relevant for SD
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RoutingGroupIdType, SD_CONST) Sd_RoutingGroup[4];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RxPduIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_RxPduIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific reception PDU IDs.
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of Sd_RxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificInstanceIdx             the index of the 0:1 relation pointing to Sd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 0:1 relation pointing to Sd_Instance
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_RxPduIdMapType, SD_CONST) Sd_RxPduIdMap[2];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Server
**********************************************************************************************************************/
/** 
  \var    Sd_Server
  \brief  Configuration data of SdServerService. List is sorted by ServiceId (and HandleId if ServiceId is not unique) per SdInstance.
  \details
  Element                                  Description
  AutoAvailable                            Auto available flag
  ServiceGroupMember                       Specifies if service is member of a ServiceGroup.
  AclIPv4SIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv4SInd
  AclIPv4SIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv4SInd
  AclIPv6SIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv6SInd
  AclIPv6SIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv6SInd
  CapabilityRecordEndIdx                   the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtrIdx    the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr
  CapabilityRecordStartIdx                 the start index of the 0:n relation pointing to Sd_CapabilityRecord
  CommonInitialDelayIdx                    the index of the 0:1 relation pointing to Sd_CommonInitialDelay
  EventHandlerEndIdx                       the end index of the 0:n relation pointing to Sd_EventHandler
  EventHandlerStartIdx                     the start index of the 0:n relation pointing to Sd_EventHandler
  HandleId                                 Handle ID
  InitialInstanceId                        Initial Instance ID
  InstanceIdx                              the index of the 1:1 relation pointing to Sd_Instance
  MajorVersion                             Major Version
  MethodIdx                                the index of the 0:1 relation pointing to Sd_Method
  MinorVersion                             Minor Version
  ServerTimerIdx                           the index of the 1:1 relation pointing to Sd_ServerTimer
  ServiceId                                Service ID
  SoConGrpDynTcpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  SoConGrpDynUdpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  TcpSoConIdEndIdx                         the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx                       the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx                           the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx                         the start index of the 0:n relation pointing to Sd_UdpSoCon
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ServerType, SD_CONST) Sd_Server[3];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ServerIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific server IDs.
  \details
  Element                                Description
  InvalidHnd                             FALSE, if the handle of Sd_ServerIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificServerIdx             the index of the 0:1 relation pointing to Sd_Server
  PartitionSpecificServerPartitionIdx    the partition index of the 0:1 relation pointing to Sd_Server
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ServerIdMapType, SD_CONST) Sd_ServerIdMap[3];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerTimer
**********************************************************************************************************************/
/** 
  \var    Sd_ServerTimer
  \brief  Timer parameter for SdServerService and SdEventHandler
  \details
  Element                            Description
  OfferCyclicDelay                   Delay used for cyclic transmission of OfferService messages. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialOfferDelayMax               Initial maximal Offer delay
  InitialOfferDelayMin               Initial minimal Offer delay
  InitialOfferRepetitionBaseDelay    Base delay used for timing of OfferServices messages during repetition phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialOfferRepetitionsMax         Amount of OfferService messages transmitted during repetition phase
  RequestResponseMaxDelay            Maximal request-response delay
  RequestResponseMinDelay            Minimal request-response delay
  TTL                                Time To Live
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_ServerTimerType, SD_CONST) Sd_ServerTimer[6];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConModeIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_SoConModeIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific socket connection mode IDs.
  \details
  Element                                   Description
  InvalidHnd                                FALSE, if the handle of Sd_SoConModeIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSoConModeIdx             the index of the 0:1 relation pointing to Sd_SoConModeDyn
  PartitionSpecificSoConModePartitionIdx    the partition index of the 0:1 relation pointing to Sd_SoConModeDyn
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_SoConModeIdMapType, SD_CONST) Sd_SoConModeIdMap[4];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_TxSoConIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_TxSoConIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific Tx socket connection IDs.
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of Sd_TxSoConIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificInstanceIdx             the index of the 0:1 relation pointing to Sd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 0:1 relation pointing to Sd_Instance
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_TxSoConIdMapType, SD_CONST) Sd_TxSoConIdMap[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_UdpSoCon
**********************************************************************************************************************/
/** 
  \var    Sd_UdpSoCon
  \brief  UDP SocketConnections sorted by SdInstance and SdServer/SdClientServices
  \details
  Element          Description
  Preconfigured    Specifies if SoCon is preconfigured with IP and Port or not
  Id               IDs of UDP SocketConnections
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_UdpSoConType, SD_CONST) Sd_UdpSoCon[2];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_AddressStorage
**********************************************************************************************************************/
/** 
  \var    Sd_AddressStorage
  \brief  State information of communication partner
  \details
  Element                  Description
  RxMulticastSessionId     RX multicast session ID
  RxUnicastSessionId       RX unicast session ID
  SessionIdCounter         TX session ID
  Flags                    TX flags
  RebootDetected           Remote reboot detection status
  RxMulticastFlags         RX multicast flags
  RxUnicastFlags           RX unicast flags
  SendEntryHeadIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryNrPendingIdx    the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryTailIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  Addr                     Address of the communication partner
  TimeToSend               Time when queued SendEntries became / will become ready to be sent
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_AddressStorageType, SD_VAR_NO_INIT) Sd_AddressStorage[16];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ClientDyn
  \brief  Dynamic configuration data for SdClientService
  \details
  Element                           Description
  OfferedTTL                        Offered Time To Live
  InstanceId                        Current Instance ID of client service
  AddressStorageCurrentServerIdx    the index of the 0:1 relation pointing to Sd_AddressStorage
  AddressStorageServerIdx           the index of the 0:1 relation pointing to Sd_AddressStorage
  RepetitionRun                     Repetition run counter
  RetryCounter                      Counter for subscribe eventgroup retry handling.
  ServiceGroupReqCounter            Client request counter for ServiceGroup service API
  StateMachineExecutionRequested    Flag if State machine shall be executed for this client
  CurrentState                      Current state
  EventMain                         Event processed in MainFunction.
  EventRx                           Received event
  MethodTcpSoConId                  TCP method SoConId
  MethodUdpSoConId                  UDP method SoConId
  RetryTimer                        Timer for subscribe eventgroup retry handling.
  ServerTcpEndpointAddr             Server TCP endpoint address
  ServerUdpEndpointAddr             Server UDP endpoint address
  StateMachine                      State machine
  StateSwc                          Requested state
  TimeToTriggerSend                 Time to trigger next message transmission
  TimerTTL                          Time To Live
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ClientDynType, SD_VAR_NO_INIT) Sd_ClientDyn[1];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientList
**********************************************************************************************************************/
/** 
  \var    Sd_ClientList
  \brief  Dynamic data of subscribed clients
  \details
  Element                  Description
  RequestedTTL             Requested TimeToLive
  RxReserved               Received reserved field
  AddressStorageIdx        the index of the 0:1 relation pointing to Sd_AddressStorage
  EndpointStorageTcpIdx    the index of the 0:1 relation pointing to Sd_EndpointStorage
  EndpointStorageUdpIdx    the index of the 0:1 relation pointing to Sd_EndpointStorage
  NrOfReferences           Number of simultaneous subscriptions
  AssignedTcpSoConId       Used TCP SocketConnection ID
  AssignedUdpSoConId       Used UDP SocketConnection ID
  ClientState              State of the client
  SubscribedUntil          Point in time till the client is subscribed
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ClientListType, SD_VAR_NO_INIT) Sd_ClientList[3];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroupDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroupDyn
  \brief  Dynamic configuration of SdConsumedEventgroup
  \details
  Element                Description
  AcknowledgedTTL        Acknowledge Time To Live
  RxIndicationCount      Counter to differentiate RxIndication calls.
  TriggerSubscription    Flag indicating if a subscription shall be triggered.
  CurrentState           Current state
  Event                  Received event
  MulticastSoConId       Configured multicast SocketConnection
  ServiceModeRequest     Requested state
  StateMachine           State machine
  TcpSoConId             Configured TCP SocketConnection
  TimerTTL               Time To Live
  UdpSoConId             Configured UDP SocketConnection
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ConsumedEventgroupDynType, SD_VAR_NO_INIT) Sd_ConsumedEventgroupDyn[1];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EndpointStorage
**********************************************************************************************************************/
/** 
  \var    Sd_EndpointStorage
  \brief  Received endpoint options
  \details
  Element           Description
  NrOfReferences    Number of external references
  Addr              Endpoint address
  Type              Endpoint type
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_EndpointStorageType, SD_VAR_NO_INIT) Sd_EndpointStorage[32];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandlerDyn
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandlerDyn
  \brief  Dynamic configuration of SdEventHandler
  \details
  Element         Description
  NrOfClients     Nr of subscribed clients
  RequestState    Request state
  StateMachine    State machine
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_EventHandlerDynType, SD_VAR_NO_INIT) Sd_EventHandlerDyn[3];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_InstanceDyn
**********************************************************************************************************************/
/** 
  \var    Sd_InstanceDyn
  \brief  Variable data for each SdInstance
  \details
  Element                     Description
  RxEventEndIdx               the index of the 1:1 relation pointing to Sd_RxEvent
  RxEventListFull             Full flag of dynamic queue
  RxEventStartIdx             the index of the 1:1 relation pointing to Sd_RxEvent
  SendEntryFreeListHeadIdx    the index of the 1:1 relation pointing to Sd_SendEntry
  SendEntryFreeListTailIdx    the index of the 1:1 relation pointing to Sd_SendEntry
  SendEntryNrPendingIdx       the index of the 1:1 relation pointing to Sd_SendEntry
  LastFoundEndpoint           LastFoundEndpoint
  NextStateMachineRun         Time indicating next execution of state machines
  RunMode                     Communication mode
  State                       State
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_InstanceDynType, SD_VAR_NO_INIT) Sd_InstanceDyn[1];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_OptionIndex
**********************************************************************************************************************/
/** 
  \var    Sd_OptionIndex
  \brief  Payload offset of options
*/ 
#define SD_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_OptionIndexType, SD_VAR_NO_INIT) Sd_OptionIndex[10];
#define SD_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PartitionDataDyn
**********************************************************************************************************************/
/** 
  \var    Sd_PartitionDataDyn
  \brief  Partition specific dynamic data.
  \details
  Element                       Description
  NrOfOptions                   Number of options saved in the OptionIndex.
  RxIndicationCount             Counter for calls of RxIndication.
  TriggerTransmitDynEndIdx      the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn
  TriggerTransmitDynStartIdx    the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn
  TriggerTransmitFull           Indication whether trigger transmit ring buffer is full.
  TxPathLocked                  Indication if transmission path is locked.
  Initialized                   initialized state of the partition
  TimeMsSinceStart              Time since start of the component.
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_PartitionDataDynType, SD_VAR_NO_INIT) Sd_PartitionDataDyn[1];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Payload
**********************************************************************************************************************/
/** 
  \var    Sd_Payload
  \brief  Buffer used for message transmission
*/ 
#define SD_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_PayloadType, SD_VAR_NO_INIT) Sd_Payload[1464];
#define SD_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RoutingGroupDyn
**********************************************************************************************************************/
/** 
  \var    Sd_RoutingGroupDyn
  \brief  Dynamic data of SoAd RoutingGroups relevant for SD
  \details
  Element    Description
  Status     Status (disabled/enabled/unknown) of RoutingGroup
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_RoutingGroupDynType, SD_VAR_NO_INIT) Sd_RoutingGroupDyn[4];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RxEvent
**********************************************************************************************************************/
/** 
  \var    Sd_RxEvent
  \brief  Saves received server events
  \details
  Element            Description
  ClientListIdx      the index of the 0:1 relation pointing to Sd_ClientList
  EventHandlerIdx    the index of the 0:1 relation pointing to Sd_EventHandler
  Event              Received event
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_RxEventType, SD_VAR_NO_INIT) Sd_RxEvent[96];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SendEntry
**********************************************************************************************************************/
/** 
  \var    Sd_SendEntry
  \brief  Saves messages which shall be transmitted
  \details
  Element                  Description
  EventHandlerId           EventHandler ID
  InstanceId               Instance ID
  ReservedField            Reserved Field
  ServiceId                Service ID
  ClientIdx                the index of the 0:1 relation pointing to Sd_Client
  ClientListIdx            the index of the 0:1 relation pointing to Sd_ClientList
  ConsumedEventgroupIdx    the index of the 0:1 relation pointing to Sd_ConsumedEventgroup
  EventHandlerIdx          the index of the 0:1 relation pointing to Sd_EventHandler
  InstanceIdx              the index of the 0:1 relation pointing to Sd_Instance
  MajorVersion             Major Version
  SendEntryNextIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryPrevIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  ServerIdx                the index of the 0:1 relation pointing to Sd_Server
  EntryType                Type of entry
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_SendEntryType, SD_VAR_NO_INIT) Sd_SendEntry[96];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ServerDyn
  \brief  Dynamic configuration data of SdServerService
  \details
  Element                           Description
  InstanceId                        Current Instance ID of server service
  InitialOfferRepetitionRun         Counting the number of repetition runs
  ServiceGroupReqCounter            Server availability counter for ServiceGroup service API
  StateMachineExecutionRequested    Flag if State machine shall be executed for this server
  StateMachine                      State machine
  StateSwc                          Requested state
  TimeToTriggerSend                 Point in time the next message will be transmitted
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_ServerDynType, SD_VAR_NO_INIT) Sd_ServerDyn[3];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConActivationMap
**********************************************************************************************************************/
/** 
  \var    Sd_SoConActivationMap
  \brief  Configuration data of SocketConnections
  \details
  Element            Description
  NrOfActivations    Nr of activations
  SoConId            SocketConnection ID
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_SoConActivationMapType, SD_VAR_NO_INIT) Sd_SoConActivationMap[3];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConGrpDyn
**********************************************************************************************************************/
/** 
  \var    Sd_SoConGrpDyn
  \brief  Dynamic data of used SoAd Socket Connection Groups
  \details
  Element      Description
  LocalPort    Local Port of the SoCon Group
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_SoConGrpDynType, SD_VAR_NO_INIT) Sd_SoConGrpDyn[2];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConModeDyn
**********************************************************************************************************************/
/** 
  \var    Sd_SoConModeDyn
  \brief  Saves the current SocketConnection mode of a SoCon which has been returned by Sd_SoConModeChg().
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Sd_SoConModeType, SD_VAR_NO_INIT) Sd_SoConModeDyn[2];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PCConfig
**********************************************************************************************************************/
/** 
  \var    Sd_PCConfig
  \details
  Element                       Description
  PCPartitionConfig             the pointer to Sd_PCPartitionConfig
  PartitionIdentifiers          the pointer to Sd_PartitionIdentifiers
  SizeOfPartitionIdentifiers    the number of accomplishable value elements in Sd_PartitionIdentifiers
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_PCConfigsType, SD_CONST) Sd_PCConfig;
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    Sd_PCPartitionConfig
  \details
  Element                                     Description
  AclIPv4                                     the pointer to Sd_AclIPv4
  AclIPv4CInd                                 the pointer to Sd_AclIPv4CInd
  AclIPv4SInd                                 the pointer to Sd_AclIPv4SInd
  AclIPv6                                     the pointer to Sd_AclIPv6
  AclIPv6CInd                                 the pointer to Sd_AclIPv6CInd
  AclIPv6SInd                                 the pointer to Sd_AclIPv6SInd
  AddressStorage                              the pointer to Sd_AddressStorage
  CapabilityRecord                            the pointer to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtr          the pointer to Sd_CapabilityRecordFunctionCalloutPtr
  Client                                      the pointer to Sd_Client
  ClientDyn                                   the pointer to Sd_ClientDyn
  ClientIdMap                                 the pointer to Sd_ClientIdMap
  ClientList                                  the pointer to Sd_ClientList
  ClientTimer                                 the pointer to Sd_ClientTimer
  CommonInitialDelay                          the pointer to Sd_CommonInitialDelay
  ConsumedEventgroup                          the pointer to Sd_ConsumedEventgroup
  ConsumedEventgroupDyn                       the pointer to Sd_ConsumedEventgroupDyn
  ConsumedEventgroupIdMap                     the pointer to Sd_ConsumedEventgroupIdMap
  EndpointStorage                             the pointer to Sd_EndpointStorage
  EventHandler                                the pointer to Sd_EventHandler
  EventHandlerDyn                             the pointer to Sd_EventHandlerDyn
  EventHandlerMulticast                       the pointer to Sd_EventHandlerMulticast
  EventHandlerTcp                             the pointer to Sd_EventHandlerTcp
  EventHandlerUdp                             the pointer to Sd_EventHandlerUdp
  Instance                                    the pointer to Sd_Instance
  InstanceDyn                                 the pointer to Sd_InstanceDyn
  IpAddrRequest                               the pointer to Sd_IpAddrRequest
  Method                                      the pointer to Sd_Method
  MulticastEndpointAddr                       the pointer to Sd_MulticastEndpointAddr
  MulticastSoConId                            the pointer to Sd_MulticastSoConId
  OptionIndex                                 the pointer to Sd_OptionIndex
  PartitionDataDyn                            the pointer to Sd_PartitionDataDyn
  Payload                                     the pointer to Sd_Payload
  PortSet                                     the pointer to Sd_PortSet
  RequestCnt                                  the pointer to Sd_RequestCnt
  RoutingGroup                                the pointer to Sd_RoutingGroup
  RoutingGroupDyn                             the pointer to Sd_RoutingGroupDyn
  RoutingGroupIdMap                           the pointer to Sd_RoutingGroupIdMap
  RxEvent                                     the pointer to Sd_RxEvent
  RxPduIdMap                                  the pointer to Sd_RxPduIdMap
  SendEntry                                   the pointer to Sd_SendEntry
  Server                                      the pointer to Sd_Server
  ServerDyn                                   the pointer to Sd_ServerDyn
  ServerIdMap                                 the pointer to Sd_ServerIdMap
  ServerTimer                                 the pointer to Sd_ServerTimer
  ServiceGroup                                the pointer to Sd_ServiceGroup
  ServiceGroupIdMap                           the pointer to Sd_ServiceGroupIdMap
  ServiceGroupMember                          the pointer to Sd_ServiceGroupMember
  SoConActivationMap                          the pointer to Sd_SoConActivationMap
  SoConGrpDyn                                 the pointer to Sd_SoConGrpDyn
  SoConModeDyn                                the pointer to Sd_SoConModeDyn
  SoConModeIdMap                              the pointer to Sd_SoConModeIdMap
  TcpSoConId                                  the pointer to Sd_TcpSoConId
  TriggerTransmitDyn                          the pointer to Sd_TriggerTransmitDyn
  TxSoConIdMap                                the pointer to Sd_TxSoConIdMap
  UdpSoCon                                    the pointer to Sd_UdpSoCon
  SizeOfPayload                               the number of accomplishable value elements in Sd_Payload
  SizeOfAclIPv4                               the number of accomplishable value elements in Sd_AclIPv4
  SizeOfAclIPv4CInd                           the number of accomplishable value elements in Sd_AclIPv4CInd
  SizeOfAclIPv4SInd                           the number of accomplishable value elements in Sd_AclIPv4SInd
  SizeOfAclIPv6                               the number of accomplishable value elements in Sd_AclIPv6
  SizeOfAclIPv6CInd                           the number of accomplishable value elements in Sd_AclIPv6CInd
  SizeOfAclIPv6SInd                           the number of accomplishable value elements in Sd_AclIPv6SInd
  SizeOfAddressStorage                        the number of accomplishable value elements in Sd_AddressStorage
  SizeOfCapabilityRecord                      the number of accomplishable value elements in Sd_CapabilityRecord
  SizeOfCapabilityRecordFunctionCalloutPtr    the number of accomplishable value elements in Sd_CapabilityRecordFunctionCalloutPtr
  SizeOfClient                                the number of accomplishable value elements in Sd_Client
  SizeOfClientIdMap                           the number of accomplishable value elements in Sd_ClientIdMap
  SizeOfClientList                            the number of accomplishable value elements in Sd_ClientList
  SizeOfClientTimer                           the number of accomplishable value elements in Sd_ClientTimer
  SizeOfCommonInitialDelay                    the number of accomplishable value elements in Sd_CommonInitialDelay
  SizeOfConsumedEventgroup                    the number of accomplishable value elements in Sd_ConsumedEventgroup
  SizeOfConsumedEventgroupIdMap               the number of accomplishable value elements in Sd_ConsumedEventgroupIdMap
  SizeOfEndpointStorage                       the number of accomplishable value elements in Sd_EndpointStorage
  SizeOfEventHandler                          the number of accomplishable value elements in Sd_EventHandler
  SizeOfEventHandlerMulticast                 the number of accomplishable value elements in Sd_EventHandlerMulticast
  SizeOfEventHandlerTcp                       the number of accomplishable value elements in Sd_EventHandlerTcp
  SizeOfEventHandlerUdp                       the number of accomplishable value elements in Sd_EventHandlerUdp
  SizeOfInstance                              the number of accomplishable value elements in Sd_Instance
  SizeOfIpAddrRequest                         the number of accomplishable value elements in Sd_IpAddrRequest
  SizeOfMethod                                the number of accomplishable value elements in Sd_Method
  SizeOfMulticastEndpointAddr                 the number of accomplishable value elements in Sd_MulticastEndpointAddr
  SizeOfMulticastSoConId                      the number of accomplishable value elements in Sd_MulticastSoConId
  SizeOfOptionIndex                           the number of accomplishable value elements in Sd_OptionIndex
  SizeOfPartitionDataDyn                      the number of accomplishable value elements in Sd_PartitionDataDyn
  SizeOfPortSet                               the number of accomplishable value elements in Sd_PortSet
  SizeOfRequestCnt                            the number of accomplishable value elements in Sd_RequestCnt
  SizeOfRoutingGroup                          the number of accomplishable value elements in Sd_RoutingGroup
  SizeOfRoutingGroupIdMap                     the number of accomplishable value elements in Sd_RoutingGroupIdMap
  SizeOfRxEvent                               the number of accomplishable value elements in Sd_RxEvent
  SizeOfRxPduIdMap                            the number of accomplishable value elements in Sd_RxPduIdMap
  SizeOfSendEntry                             the number of accomplishable value elements in Sd_SendEntry
  SizeOfServer                                the number of accomplishable value elements in Sd_Server
  SizeOfServerIdMap                           the number of accomplishable value elements in Sd_ServerIdMap
  SizeOfServerTimer                           the number of accomplishable value elements in Sd_ServerTimer
  SizeOfServiceGroup                          the number of accomplishable value elements in Sd_ServiceGroup
  SizeOfServiceGroupIdMap                     the number of accomplishable value elements in Sd_ServiceGroupIdMap
  SizeOfServiceGroupMember                    the number of accomplishable value elements in Sd_ServiceGroupMember
  SizeOfSoConActivationMap                    the number of accomplishable value elements in Sd_SoConActivationMap
  SizeOfSoConGrpDyn                           the number of accomplishable value elements in Sd_SoConGrpDyn
  SizeOfSoConModeDyn                          the number of accomplishable value elements in Sd_SoConModeDyn
  SizeOfSoConModeIdMap                        the number of accomplishable value elements in Sd_SoConModeIdMap
  SizeOfTcpSoConId                            the number of accomplishable value elements in Sd_TcpSoConId
  SizeOfTriggerTransmitDyn                    the number of accomplishable value elements in Sd_TriggerTransmitDyn
  SizeOfTxSoConIdMap                          the number of accomplishable value elements in Sd_TxSoConIdMap
  SizeOfUdpSoCon                              the number of accomplishable value elements in Sd_UdpSoCon
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Sd_PCPartitionConfigType, SD_CONST) Sd_PCPartitionConfig[1];
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
 * GLOBAL CUSTOM TYPES
 *********************************************************************************************************************/
 /*! Partition config index data type. */
typedef Sd_PCPartitionConfigIdxOfPartitionIdentifiersType Sd_PartitionConfigIdxType;

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
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


#endif  /* SD_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Sd_Lcfg.h
 *********************************************************************************************************************/

