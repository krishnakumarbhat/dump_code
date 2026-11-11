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
 *            Module: EthTSyn
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTSyn_Cfg.h
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
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#ifndef ETHTSYN_CFG_H
#define ETHTSYN_CFG_H
 
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
 
/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETHTSYN_USE_DUMMY_STATEMENT
#define ETHTSYN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTSYN_DUMMY_STATEMENT
#define ETHTSYN_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTSYN_DUMMY_STATEMENT_CONST
#define ETHTSYN_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETHTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETHTSYN_ATOMIC_VARIABLE_ACCESS
#define ETHTSYN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETHTSYN_PROCESSOR_IND13400
#define ETHTSYN_PROCESSOR_IND13400
#endif
#ifndef ETHTSYN_COMP_LLVMDIAB
#define ETHTSYN_COMP_LLVMDIAB
#endif
#ifndef ETHTSYN_GEN_GENERATOR_MSR
#define ETHTSYN_GEN_GENERATOR_MSR
#endif
#ifndef ETHTSYN_CPUTYPE_BITORDER_LSB2MSB
#define ETHTSYN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETHTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#define ETHTSYN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETHTSYN_CONFIGURATION_VARIANT_LINKTIME
#define ETHTSYN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETHTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETHTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETHTSYN_CONFIGURATION_VARIANT
#define ETHTSYN_CONFIGURATION_VARIANT ETHTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETHTSYN_POSTBUILD_VARIANT_SUPPORT
#define ETHTSYN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif
 
 

/**********************************************************************************************************************
 *  INTEGER DEFINES
 *********************************************************************************************************************/
#define ETHTSYN_CFG_MAJOR_VERSION                                18u
#define ETHTSYN_CFG_MINOR_VERSION                                4u

#define ETHTSYN_MAIN_FUNCTION_CYCLE                              10u /*  ms  */ 
#define ETHTSYN_FRAME_TYPE                                       0x88F7u
#define ETHTSYN_TIME_DOMAIN_COUNT                                1u
#define ETHTSYN_PORT_COUNT                                       1u

#define ETHTSYN_FLAGS_OCTET_1_DEFAULT_VALUE                      0x08u /*  ptpTimescale  */ 

#define ETHTSYN_SWT_MGMT_MSG_BUFFER_PAYLOAD_SIZE                 2u /*  Dummy size for type SwtMgmt typedefs. SwtMgmt is disabled and type is not used.  */ 
#define ETHTSYN_SWT_MGMT_RX_MSG_BUFFER_SIZE                      2u /*  Dummy size for type SwtMgmt typedefs. SwtMgmt is disabled and type is not used.  */ 

/* ----- Bridge mode values ----- */
#define ETHTSYN_SWT_MGMT_BRIDGE_MODE_NONE                        0u
#define ETHTSYN_SWT_MGMT_BRIDGE_MODE_TRANSPARENT                 1u
#define ETHTSYN_SWT_MGMT_BRIDGE_MODE_BOUNDARY                    2u
#define ETHTSYN_SWT_MGMT_BRIDGE_MODE_ASYMMETRIC_TRANSPARENT      3u

/* ----- Sub-TLV flags ----- */
#define ETHTSYN_SUB_TLV_OFS_FLAG                                 0x01u
#define ETHTSYN_SUB_TLV_STATUS_FLAG                              0x02u
#define ETHTSYN_SUB_TLV_TIME_FLAG                                0x04u
#define ETHTSYN_SUB_TLV_USER_DATA_FLAG                           0x08u

/**********************************************************************************************************************
 *  SWITCH DEFINES
 *********************************************************************************************************************/
#define ETHTSYN_DEV_ERROR_DETECT                                 STD_ON
#define ETHTSYN_DEV_ERROR_REPORT                                 STD_ON
#define ETHTSYN_VERSION_INFO_API                                 STD_OFF

#define ETHTSYN_HW_TIMESTAMP_SUPPORT                             STD_OFF
#define ETHTSYN_CRC_SUPPORT                                      STD_OFF
#define ETHTSYN_PORT_PARAM_STATS_SUPPORT                         STD_OFF
#define ETHTSYN_MASTER_SLAVE_CONFLICT_DETECTION                  STD_OFF
#define ETHTSYN_MESSAGE_COMPLIANCE                               STD_ON
#define ETHTSYN_TX_SUPPORT                                       STD_ON
#define ETHTSYN_PDELAY_INITIATOR_SUPPORT                         STD_ON
#define ETHTSYN_PDELAY_RESPONDER_SUPPORT                         STD_ON
#define ETHTSYN_PD_RESP_USE_GLOBAL_TIME_SUPPORT                  STD_OFF
#define ETHTSYN_MASTER_SUPPORT                                   STD_OFF
#define ETHTSYN_SLAVE_SUPPORT                                    STD_ON
#define ETHTSYN_MASTER_PD_RESP_TIME_VALIDATION_SUPPORT           STD_OFF
#define ETHTSYN_SLAVE_PD_REQ_TIME_VALIDATION_SUPPORT             STD_OFF
#define ETHTSYN_MASTER_OFS_DOMAIN_SUPPORT                        STD_OFF
#define ETHTSYN_SWT_MGMT_SUPPORT                                 STD_OFF
#define ETHTSYN_SWT_TIME_SYNC_SUPPORT                            STD_OFF
#define ETHTSYN_SWT_MGMT_BRIDGE_MODE                             ETHTSYN_SWT_MGMT_BRIDGE_MODE_NONE
#define ETHTSYN_SWT_MGMT_ONE_TAS                                 STD_OFF /*  Consider Host and Switch as one Time-Aware system  */ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthTSynPCDataSwitches  EthTSyn Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ETHTSYN_ANNOUNCERCVSM                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFANNOUNCERCVSM                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MAXSTEPSREMOVEDOFANNOUNCERCVSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXTIMEOUTOFANNOUNCERCVSM                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAIDXOFANNOUNCERCVSM                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCERCVSMDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXTIMEOUTCOUNTEROFANNOUNCERCVSMDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SMRESETREQUESTEDOFANNOUNCERCVSMDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFANNOUNCERCVSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSM                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCELOGMSGINTERVALOFANNOUNCESENDSM                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCETXCYCLEOFANNOUNCESENDSM                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFANNOUNCESENDSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSMDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCECYCLETIMEROFANNOUNCESENDSMDYN                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESETREQUESTEDOFANNOUNCESENDSMDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SEQUENCEIDOFANNOUNCESENDSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFANNOUNCESENDSMDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ASYMSITESYNCSYNCSM                                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMFUPPAYLOADBUFDYNENDIDXOFASYMSITESYNCSYNCSM                        STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm.AsymSiteSyncSyncSmFupPayloadBufDynEndIdx' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMFUPPAYLOADBUFDYNLENGTHOFASYMSITESYNCSYNCSM                        STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm.AsymSiteSyncSyncSmFupPayloadBufDynLength' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMFUPPAYLOADBUFDYNSTARTIDXOFASYMSITESYNCSYNCSM                      STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm.AsymSiteSyncSyncSmFupPayloadBufDynStartIdx' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_COMCTRLPORTSLAVEIDXOFASYMSITESYNCSYNCSM                                             STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm.ComCtrlPortSlaveIdx' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCTXIDXOFASYMSITESYNCSYNCSM                                               STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm.SiteSyncSyncTxIdx' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMDYN                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_STATEOFASYMSITESYNCSYNCSMDYN                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmDyn.State' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMFUPHNDLDYN                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_RCVDHDROFASYMSITESYNCSYNCSMFUPHNDLDYN                                               STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupHndlDyn.RcvdHdr' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_ASYMSITESYNCSYNCSMFUPPAYLOADBUFDYN                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_BRIDGETXMASTERPORT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFBRIDGETXMASTERPORT                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BRIDGETXMASTERPORTDYN                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPFWDSTATEOFBRIDGETXMASTERPORTDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCEGRTSMGMTOFBRIDGETXMASTERPORTDYN                                                STD_OFF  /**< Deactivateable: 'EthTSyn_BridgeTxMasterPortDyn.SyncEgrTsMgmt' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCFWDDELAYNSOFBRIDGETXMASTERPORTDYN                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCFWDSTATEOFBRIDGETXMASTERPORTDYN                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_BridgeTxMasterPortDyn.SyncFwdState' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_COMCTRLETHIFCTRL                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTINDENDIDXOFCOMCTRLETHIFCTRL                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTINDSTARTIDXOFCOMCTRLETHIFCTRL                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACINDENDIDXOFCOMCTRLETHIFCTRL                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACINDSTARTIDXOFCOMCTRLETHIFCTRL                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ETHIFCTRLIDXOFCOMCTRLETHIFCTRL                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLETHIFCTRLDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CLOCKIDOFCOMCTRLETHIFCTRLDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LINKSTATEACTIVEOFCOMCTRLETHIFCTRLDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXACTIVEOFCOMCTRLETHIFCTRLDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPHYSPORT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ALWAYSASCAPABLEOFCOMCTRLPHYSPORT                                                    STD_ON
#define ETHTSYN_DEBOUNCETIMERINITOFCOMCTRLPHYSPORT                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_INITIALPDELAYNSOFCOMCTRLPHYSPORT                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_USESTATICPDELAYOFCOMCTRLPHYSPORT                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPHYSPORTDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ASCAPABLEOFCOMCTRLPHYSPORTDYN                                                       STD_ON
#define ETHTSYN_DEBOUNCETIMEROFCOMCTRLPHYSPORTDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDELAYVALUENSOFCOMCTRLPHYSPORTDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSMIDXOFCOMCTRLPORT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSMUSEDOFCOMCTRLPORT                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLETHIFCTRLIDXOFCOMCTRLPORT                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPHYSPORTIDXOFCOMCTRLPORT                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLTIMEDOMAINIDXOFCOMCTRLPORT                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FRAMEPRIOOFCOMCTRLPORT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_NUMBEROFCOMCTRLPORT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSMIDXOFCOMCTRLPORT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSMUSEDOFCOMCTRLPORT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPSMIDXOFCOMCTRLPORT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPSMUSEDOFCOMCTRLPORT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYNIDXOFCOMCTRLPORT                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYNUSEDOFCOMCTRLPORT                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSMIDXOFCOMCTRLPORT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSMUSEDOFCOMCTRLPORT                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAHANDLERIDXOFCOMCTRLPORT                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAHANDLERUSEDOFCOMCTRLPORT                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STBMTIMESRCEQUALOFCOMCTRLPORT                                                       STD_OFF  /**< Deactivateable: 'EthTSyn_ComCtrlPort.StbMTimeSrcEqual' Reason: 'SW-Timestamping is used' */
#define ETHTSYN_SYNCSENDSMIDXOFCOMCTRLPORT                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDSMUSEDOFCOMCTRLPORT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIND                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLTIMEDOMAIN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTENDIDXOFCOMCTRLTIMEDOMAIN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTSTARTIDXOFCOMCTRLTIMEDOMAIN                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACIDXOFCOMCTRLTIMEDOMAIN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_IDOFCOMCTRLTIMEDOMAIN                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFFSETTIMEDOMAINENDIDXOFCOMCTRLTIMEDOMAIN                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFFSETTIMEDOMAINSTARTIDXOFCOMCTRLTIMEDOMAIN                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFFSETTIMEDOMAINUSEDOFCOMCTRLTIMEDOMAIN                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STBMTIMESRCEQUALOFSLAVEPORTOFCOMCTRLTIMEDOMAIN                                      STD_OFF  /**< Deactivateable: 'EthTSyn_ComCtrlTimeDomain.StbMTimeSrcEqualOfSlavePort' Reason: 'Slave support and/or hardware timestamp support is disabled.' */
#define ETHTSYN_SYNCHRONIZEDTIMEBASEIDOFCOMCTRLTIMEDOMAIN                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDL                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPDATAIDLISTENDIDXOFCRCHNDL                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPDATAIDLISTSTARTIDXOFCRCHNDL                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMAC                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE0OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE1OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE2OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE3OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE4OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BYTE5OFDESTINATIONMAC                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACIND                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FINALMAGICNUMBER                                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTSYN_FUPDATAIDLIST                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPPAYLOADBUFDYN                                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_FupPayloadBufDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FUPRXHANDLER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTEXTERNALIDXOFFUPRXHANDLER                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCFLAGSRXVALIDATEDOFFUPRXHANDLER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDLIDXOFFUPRXHANDLER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDLUSEDOFFUPRXHANDLER                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPCORRFIELDTHRESHOLDNSOFFUPRXHANDLER                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPRXOFSDOMAINHANDLERENDIDXOFFUPRXHANDLER                                           STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandler.FupRxOfsDomainHandlerEndIdx' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_FUPRXOFSDOMAINHANDLERSTARTIDXOFFUPRXHANDLER                                         STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandler.FupRxOfsDomainHandlerStartIdx' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_FUPRXOFSDOMAINHANDLERUSEDOFFUPRXHANDLER                                             STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandler.FupRxOfsDomainHandlerUsed' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_REPORTDATATOSTBMOFFUPRXHANDLER                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandler.ReportDataToStbM' Reason: 'Switch management is disabled' */
#define ETHTSYN_RXCRCVALIDATEDOFFUPRXHANDLER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXSUBTLVFLAGSOFFUPRXHANDLER                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandler.RxSubTlvFlags' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_TIMEVALIDATIONENABLEDOFFUPRXHANDLER                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPRXHANDLERDYN                                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandlerDyn' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_TBSTATUSOFFUPRXHANDLERDYN                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandlerDyn.TbStatus' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_USERDATAOFFUPRXHANDLERDYN                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxHandlerDyn.UserData' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_FUPRXOFSDOMAINHANDLER                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandler' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_DOMAINNUMOFFUPRXOFSDOMAINHANDLER                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandler.DomainNum' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_OFSTIMEBASEIDOFFUPRXOFSDOMAINHANDLER                                                STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandler.OfsTimeBaseId' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_FUPRXOFSDOMAINHANDLERDYN                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_TIMESTAMPOFFUPRXOFSDOMAINHANDLERDYN                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn.Timestamp' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_UPDATEDOFFUPRXOFSDOMAINHANDLERDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn.Updated' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_USERDATAOFFUPRXOFSDOMAINHANDLERDYN                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn.UserData' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_INITDATAHASHCODE                                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTSYN_MSGSENTCBKBUF                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFFSETTIMEDOMAIN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_IDOFOFFSETTIMEDOMAIN                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCHRONIZEDTIMEBASEIDOFOFFSETTIMEDOMAIN                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSM                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_AVERAGEWEIGHTOFPDREQSM                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFPDREQSM                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LOGMSGINTERVALOFPDREQSM                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MAXLOSTRESPONSESOFPDREQSM                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQPERIODOFPDREQSM                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPTIMEOUTOFPDREQSM                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDTHRESHOLDOFPDREQSM                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEVALIDATIONENABLEDOFPDREQSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTIDXOFPDREQSM                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSMDYN                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FIRSTPDELAYOFPDREQSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LOSTRESPONSECNTOFPDREQSMDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_REFGLOBALTIMEOFPDREQSMDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_REFLOCALTIMEOFPDREQSMDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESPTIMEOUTCNTOFPDREQSMDYN                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SEQUENCEIDOFPDREQSMDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SMRESETREQUESTEDOFPDREQSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFPDREQSMDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXINTERVALCNTOFPDREQSMDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQTRCVDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQEGRTSMGMTOFPDREQTRCVDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQEGRTSPROVIDEDOFPDREQTRCVDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPINGRTSMGMTOFPDREQTRCVDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_REQRECEIVEDTSOFPDREQTRCVDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESPCLOCKIDOFPDREQTRCVDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESPORIGINTSOFPDREQTRCVDYN                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESPPORTNUMOFPDREQTRCVDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFPDREQTRCVDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPSM                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFPDRESPSM                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEVALIDATIONENABLEDOFPDRESPSM                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTIDXOFPDRESPSM                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_USEGLOBALTIMEOFPDRESPSM                                                             STD_OFF  /**< Deactivateable: 'EthTSyn_PdRespSm.UseGlobalTime' Reason: 'Pdelay Responder use global time support is disabled.' */
#define ETHTSYN_PDRESPSMDYN                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQRCVDTSOFPDRESPSMDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPORGTSOFPDRESPSMDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_REFGLOBALTIMEOFPDRESPSMDYN                                                          STD_OFF  /**< Deactivateable: 'EthTSyn_PdRespSmDyn.RefGlobalTime' Reason: 'Both Pdelay Responder use global time support and time validation support are disabled.' */
#define ETHTSYN_REFHWTIMEOFPDRESPSMDYN                                                              STD_OFF  /**< Deactivateable: 'EthTSyn_PdRespSmDyn.RefHwTime' Reason: 'Pdelay Responder use global time support is disabled.' */
#define ETHTSYN_REFLOCALTIMEOFPDRESPSMDYN                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_PdRespSmDyn.RefLocalTime' Reason: 'Both Pdelay Responder use global time support and time validation support are disabled.' */
#define ETHTSYN_REFSTBMVLTOFPDRESPSMDYN                                                             STD_OFF  /**< Deactivateable: 'EthTSyn_PdRespSmDyn.RefStbmVlt' Reason: 'Pdelay Responder use global time support is disabled.' */
#define ETHTSYN_REQUESTORCLOCKIDOFPDRESPSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_REQUESTORPORTNUMOFPDRESPSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SEQUENCEIDOFPDRESPSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SMRESETREQUESTEDOFPDRESPSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFPDRESPSMDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDLOSTRESPEXCEEDEDCOUNTOFPORTPARAMSTATSDYN                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXDISCARDCOUNTOFPORTPARAMSTATSDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXFUPCOUNTOFPORTPARAMSTATSDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXPDREQCOUNTOFPORTPARAMSTATSDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RXSYNCCOUNTOFPORTPARAMSTATSDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXFUPCOUNTOFPORTPARAMSTATSDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXPDREQCOUNTOFPORTPARAMSTATSDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXSYNCCOUNTOFPORTPARAMSTATSDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSM                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFPORTSYNCSENDSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FOLLOWUPSENTCBKPTROFPORTSYNCSENDSM                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MSGSENTCBKBUFENDIDXOFPORTSYNCSENDSM                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MSGSENTCBKBUFLENGTHOFPORTSYNCSENDSM                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MSGSENTCBKBUFSTARTIDXOFPORTSYNCSENDSM                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MSGSENTCBKBUFUSEDOFPORTSYNCSENDSM                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENTCBKPTROFPORTSYNCSENDSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEVALIDATIONENABLEDOFPORTSYNCSENDSM                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTIDXOFPORTSYNCSENDSM                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSMDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_EGRTSINFOOFPORTSYNCSENDSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFPORTSYNCSENDSMDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEAS                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_MAXOUTOFSYNCCNTOFRATEMEAS                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_NRSYNCCYCLESFOROFSCORROFRATEMEAS                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFSJUMPCORRTHRESHOLDNSOFRATEMEAS                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASBUFENDIDXOFRATEMEAS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASBUFLENGTHOFRATEMEAS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASBUFSTARTIDXOFRATEMEAS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATERATIOMAXOFRATEMEAS                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATERATIOMINOFRATEMEAS                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCPRECISIONLIMITNSOFRATEMEAS                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_USEINITIALOFFSETCORRECTIONOFRATEMEAS                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASBUF                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ACCUMULATEDMASTERTIMEDIFFOFRATEMEASBUF                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ACCUMULATEDSWTTIMEDIFFOFRATEMEASBUF                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ACTIVENROFSYNCCYCLESOFRATEMEASBUF                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ACTIVEOFRATEMEASBUF                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASDYN                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CURRTSINFOOFRATEMEASDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LASTCORRECTEDOFFSETNSOFRATEMEASDYN                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OUTOFSYNCCNTOFRATEMEASDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PREVTSINFOOFRATEMEASDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFRATEMEASDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCCYCLECOUNTEROFRATEMEASDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCCYCLECOUNTERRESTARTEDOFRATEMEASDYN                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_WASSYNCREACHEDOFRATEMEASDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SITESYNCSYNCSM                                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_COMCTRLPORTSLAVEIDXOFSITESYNCSYNCSM                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.ComCtrlPortSlaveIdx' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FUPPAYLOADBUFDYNENDIDXOFSITESYNCSYNCSM                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.FupPayloadBufDynEndIdx' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FUPPAYLOADBUFDYNLENGTHOFSITESYNCSYNCSM                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.FupPayloadBufDynLength' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FUPPAYLOADBUFDYNSTARTIDXOFSITESYNCSYNCSM                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.FupPayloadBufDynStartIdx' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_INITIALSYNCRXTIMEOUTOFSITESYNCSYNCSM                                                STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.InitialSyncRxTimeout' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCTXIDXOFSITESYNCSYNCSM                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.SiteSyncSyncTxIdx' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCLOGMSGINTERVALOFSITESYNCSYNCSM                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.SyncLogMsgInterval' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCRXTIMEOUTOFSITESYNCSYNCSM                                                       STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.SyncRxTimeout' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCSENDINTERVALOFSITESYNCSYNCSM                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSm.SyncSendInterval' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCSMDYN                                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_OPERATIONMODEOFSITESYNCSYNCSMDYN                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.OperationMode' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SEQUENCEIDINCOFSITESYNCSYNCSMDYN                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.SequenceIdInc' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_STATEOFSITESYNCSYNCSMDYN                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.State' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCCYCLECNTOFSITESYNCSYNCSMDYN                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.SyncCycleCnt' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCRXTIMEOUTCNTOFSITESYNCSYNCSMDYN                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.SyncRxTimeoutCnt' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_VALIDSYNCFUPFORWARDEDOFSITESYNCSYNCSMDYN                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn.ValidSyncFupForwarded' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCSMFUPHNDLDYN                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FWDPENDINGOFSITESYNCSYNCSMFUPHNDLDYN                                                STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmFupHndlDyn.FwdPending' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_HDROFSITESYNCSYNCSMFUPHNDLDYN                                                       STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmFupHndlDyn.Hdr' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCSMSYNCHNDLDYN                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_FIRSTSYNCEGRTSMGMTOFSITESYNCSYNCSMSYNCHNDLDYN                                       STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.FirstSyncEgrTsMgmt' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_HDROFSITESYNCSYNCSMSYNCHNDLDYN                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.Hdr' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_LASTVALIDINGRTSMGMTOFSITESYNCSYNCSMSYNCHNDLDYN                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.LastValidIngrTsMgmt' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_LASTVALIDPDELAYOFSITESYNCSYNCSMSYNCHNDLDYN                                          STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.LastValidPdelay' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_LASTVALIDRCVDHDROFSITESYNCSYNCSMSYNCHNDLDYN                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.LastValidRcvdHdr' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_PDELAYOFSITESYNCSYNCSMSYNCHNDLDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.Pdelay' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SYNCREFTSMGMTOFSITESYNCSYNCSMSYNCHNDLDYN                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn.SyncRefTsMgmt' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SITESYNCSYNCTX                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BRIDGETXMASTERPORTENDIDXOFSITESYNCSYNCTX                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BRIDGETXMASTERPORTSTARTIDXOFSITESYNCSYNCTX                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_KEEPSRCPORTIDENTITYOFSITESYNCSYNCTX                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncTx.KeepSrcPortIdentity' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_NUMMSGFWDRETRYOFSITESYNCSYNCTX                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SITESYNCSYNCTXDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FWDRETRYCNTOFSITESYNCSYNCTXDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LASTMSGHDROFSITESYNCSYNCTXDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_LASTSYNCREFTSMGMTOFSITESYNCSYNCTXDYN                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SECUREDTLVINFOOFSITESYNCSYNCTXDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SiteSyncSyncTxDyn.SecuredTlvInfo' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_SLAVEPDELAYNSOFSITESYNCSYNCTXDYN                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFSITESYNCSYNCTXDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCERCVSM                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCERCVSMDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCESENDSM                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCESENDSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSM                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfAsymSiteSyncSyncSm' Reason: 'Deactivateable: 'AsymSiteSyncSyncSm' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMDYN                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfAsymSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMFUPHNDLDYN                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfAsymSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMFUPPAYLOADBUFDYN                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfAsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFBRIDGETXMASTERPORT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFBRIDGETXMASTERPORTDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLETHIFCTRL                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLETHIFCTRLDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPHYSPORT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPHYSPORTDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPORT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPORTIND                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLTIMEDOMAIN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCRCHNDL                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFDESTINATIONMAC                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFDESTINATIONMACIND                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPDATAIDLIST                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPPAYLOADBUFDYN                                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfFupPayloadBufDyn' Reason: 'Deactivateable: 'FupPayloadBufDyn' Reason: 'Deactivateable: 'EthTSyn_FupPayloadBufDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFFUPRXHANDLER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPRXHANDLERDYN                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfFupRxHandlerDyn' Reason: 'Deactivateable: 'FupRxHandlerDyn' Reason: 'Deactivateable: 'EthTSyn_FupRxHandlerDyn' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFFUPRXOFSDOMAINHANDLER                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfFupRxOfsDomainHandler' Reason: 'Deactivateable: 'FupRxOfsDomainHandler' Reason: 'Deactivateable: 'EthTSyn_FupRxOfsDomainHandler' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFFUPRXOFSDOMAINHANDLERDYN                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfFupRxOfsDomainHandlerDyn' Reason: 'Deactivateable: 'FupRxOfsDomainHandlerDyn' Reason: 'Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFMSGSENTCBKBUF                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFOFFSETTIMEDOMAIN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQSM                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQSMDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQTRCVDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDRESPSM                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDRESPSMDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTPARAMSTATSDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTSYNCSENDSM                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTSYNCSENDSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEAS                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEASBUF                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEASDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSITESYNCSYNCSM                                                                STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSiteSyncSyncSm' Reason: 'Deactivateable: 'SiteSyncSyncSm' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSm' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMDYN                                                             STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMFUPHNDLDYN                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMSYNCHNDLDYN                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSiteSyncSyncSmSyncHndlDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmSyncHndlDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCTX                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSITESYNCSYNCTXDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXDATA                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXDATAHANDLER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXMASTERCLOCKIDDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXSRCPORTIDCHECKCLOCKID                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVESWITCHIDXLIST                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSWTMGMTQ                                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQ' Reason: 'Deactivateable: 'SwtMgmtQ' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQ' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQBUF                                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQBuf' Reason: 'Deactivateable: 'SwtMgmtQBuf' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQBuf' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQBUFDYN                                                                STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQBufDyn' Reason: 'Deactivateable: 'SwtMgmtQBufDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQBufDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQDYN                                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQDyn' Reason: 'Deactivateable: 'SwtMgmtQDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQEGRTSBUFDYN                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQEgrTsBufDyn' Reason: 'Deactivateable: 'SwtMgmtQEgrTsBufDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQEgrTsBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSWTMGMTQIND                                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtQInd' Reason: 'Deactivateable: 'SwtMgmtQInd' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQInd' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTSYN_SIZEOFSWTMGMTRX                                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtRx' Reason: 'Deactivateable: 'SwtMgmtRx' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRx' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTRXDYN                                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtRxDyn' Reason: 'Deactivateable: 'SwtMgmtRxDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRxDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTRXMSGBUF                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtRxMsgBuf' Reason: 'Deactivateable: 'SwtMgmtRxMsgBuf' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRxMsgBuf' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTTXDYN                                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SizeOfSwtMgmtTxDyn' Reason: 'Deactivateable: 'SwtMgmtTxDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtTxDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTTIMESYNCSM                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSWTTIMESYNCSMDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCRCVSM                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCRCVSMDYN                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCSENDSM                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCSENDSMDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTIMEBASEUPDATECOUNTER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTIMEBASEUPDATECOUNTERDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTXCONFCONTEXT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTXCONFCONTEXTDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATA                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCERCVSMIDXOFSLAVERXDATA                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCERCVSMUSEDOFSLAVERXDATA                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXMASTERCLOCKIDDYNIDXOFSLAVERXDATA                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXMASTERCLOCKIDDYNUSEDOFSLAVERXDATA                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXSRCPORTIDCHECKCLOCKIDIDXOFSLAVERXDATA                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXSRCPORTIDCHECKCLOCKIDUSEDOFSLAVERXDATA                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRCVSMIDXOFSLAVERXDATA                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAHANDLER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ASYMSITESYNCSYNCSMIDXOFSLAVERXDATAHANDLER                                           STD_OFF  /**< Deactivateable: 'EthTSyn_SlaveRxDataHandler.AsymSiteSyncSyncSmIdx' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_COMCTRLPORTIDXOFSLAVERXDATAHANDLER                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SITESYNCSYNCSMIDXOFSLAVERXDATAHANDLER                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SlaveRxDataHandler.SiteSyncSyncSmIdx' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.' */
#define ETHTSYN_SLAVERXDATAEXTERNALIDXOFSLAVERXDATAHANDLER                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAINTERNALIDXOFSLAVERXDATAHANDLER                                          STD_OFF  /**< Deactivateable: 'EthTSyn_SlaveRxDataHandler.SlaveRxDataInternalIdx' Reason: 'Switch management is disabled.' */
#define ETHTSYN_SLAVERXDATAINTERNALUSEDOFSLAVERXDATAHANDLER                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SlaveRxDataHandler.SlaveRxDataInternalUsed' Reason: 'Switch management is disabled.' */
#define ETHTSYN_SLAVERXMASTERCLOCKIDDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_VALIDMASTERCLOCKIDOFSLAVERXMASTERCLOCKIDDYN                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_VALIDMASTERSETOFSLAVERXMASTERCLOCKIDDYN                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXSRCPORTIDCHECKCLOCKID                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVESWITCHIDXLIST                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTMGMTQ                                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQ' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFENDIDXOFSWTMGMTQ                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQ.SwtMgmtQBufEndIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFLENGTHOFSWTMGMTQ                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQ.SwtMgmtQBufLength' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFSTARTIDXOFSWTMGMTQ                                                       STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQ.SwtMgmtQBufStartIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUF                                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTOBJUSERIDXOFSWTMGMTQBUF                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtObjUserIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTOBJUSEROFSWTMGMTQBUF                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtObjUser' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQEGRTSBUFDYNENDIDXOFSWTMGMTQBUF                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtQEgrTsBufDynEndIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQEGRTSBUFDYNLENGTHOFSWTMGMTQBUF                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtQEgrTsBufDynLength' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQEGRTSBUFDYNSTARTIDXOFSWTMGMTQBUF                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtQEgrTsBufDynStartIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQEGRTSBUFDYNUSEDOFSWTMGMTQBUF                                                STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtQEgrTsBufDynUsed' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFDYN                                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn' Reason: 'Switch management is disabled' */
#define ETHTSYN_EGRTSBUFUSEDELEMSOFSWTMGMTQBUFDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.EgrTsBufUsedElems' Reason: 'Switch management is disabled' */
#define ETHTSYN_ETHSWTMGMTOBJPTROFSWTMGMTQBUFDYN                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.EthSwtMgmtObjPtr' Reason: 'Switch management is disabled' */
#define ETHTSYN_STATEOFSWTMGMTQBUFDYN                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.State' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTEGRESSTSMGMTOFSWTMGMTQBUFDYN                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.SwtEgressTsMgmt' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTINGRESSTSMGMTOFSWTMGMTQBUFDYN                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.SwtIngressTsMgmt' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTINFOOFSWTMGMTQBUFDYN                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBufDyn.SwtMgmtInfo' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQDYN                                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQDyn' Reason: 'Switch management is disabled' */
#define ETHTSYN_INUSEOFSWTMGMTQDYN                                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQDyn.InUse' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFCURRPROCIDXOFSWTMGMTQDYN                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQDyn.SwtMgmtQBufCurrProcIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQBUFNEXTFREEIDXOFSWTMGMTQDYN                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQDyn.SwtMgmtQBufNextFreeIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQEGRTSBUFDYN                                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQEgrTsBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.' */
#define ETHTSYN_SWTMGMTQIND                                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQInd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ETHTSYN_SWTMGMTQRXINSTIDXOFSWTMGMTQIND                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQInd.SwtMgmtQRxInstIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTQTXINSTIDXOFSWTMGMTQIND                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQInd.SwtMgmtQTxInstIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRX                                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRXMSGBUFENDIDXOFSWTMGMTRX                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRx.SwtMgmtRxMsgBufEndIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRXMSGBUFLENGTHOFSWTMGMTRX                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRx.SwtMgmtRxMsgBufLength' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRXMSGBUFSTARTIDXOFSWTMGMTRX                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRx.SwtMgmtRxMsgBufStartIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRXDYN                                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRxDyn' Reason: 'Switch management is disabled' */
#define ETHTSYN_COMCTRLETHIFCTRLIDXOFSWTMGMTRXDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRxDyn.ComCtrlEthIfCtrlIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_INGRTIMINGINFOOFSWTMGMTRXDYN                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRxDyn.IngrTimingInfo' Reason: 'Switch management is disabled' */
#define ETHTSYN_STATEOFSWTMGMTRXDYN                                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRxDyn.State' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTRXMSGBUF                                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtRxMsgBuf' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTMGMTTXDYN                                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtTxDyn' Reason: 'Switch management is disabled' */
#define ETHTSYN_COMCTRLETHIFCTRLIDXOFSWTMGMTTXDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtTxDyn.ComCtrlEthIfCtrlIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_STATEOFSWTMGMTTXDYN                                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtTxDyn.State' Reason: 'Switch management is disabled' */
#define ETHTSYN_TXCONFCONTEXTIDXOFSWTMGMTTXDYN                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtTxDyn.TxConfContextIdx' Reason: 'Switch management is disabled' */
#define ETHTSYN_SWTTIMESYNCSM                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_APPLYRATERATIOTOSLAVESWITCHESOFSWTTIMESYNCSM                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ETHIFSWITCHIDXOFSWTTIMESYNCSM                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASIDXOFSWTTIMESYNCSM                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVESWITCHIDXLISTENDIDXOFSWTTIMESYNCSM                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVESWITCHIDXLISTSTARTIDXOFSWTTIMESYNCSM                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVESWITCHIDXLISTUSEDOFSWTTIMESYNCSM                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTSYNCSTATECHGFCTPTROFSWTTIMESYNCSM                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCEVENTTIMEOUTOFSWTTIMESYNCSM                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTTIMESYNCSMDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFSWTTIMESYNCSMDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTSYNCSTATEOFSWTTIMESYNCSMDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCEVENTTIMEOUTCNTOFSWTTIMESYNCSMDYN                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMESTAMPINFOOFSWTTIMESYNCSMDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRCVSM                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FOLLOWUPRXTIMEOUTOFSYNCRCVSM                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPRXHANDLERIDXOFSYNCRCVSM                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYNIDXOFSYNCRCVSM                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYNUSEDOFSYNCRCVSM                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRCVSMDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANYSYNCRECEIVEDOFSYNCRCVSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPRXTIMEOUTCNTOFSYNCRCVSMDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RESETREQUESTEDOFSYNCRCVSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFSYNCRCVSMDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRXTIMEINFOOFSYNCRCVSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSEQUENCEIDOFSYNCRCVSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSRCCLOCKIDOFSYNCRCVSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSRCPORTNUMOFSYNCRCVSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDSM                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDLIDXOFSYNCSENDSM                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDLUSEDOFSYNCSENDSM                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCTIMEFLAGSOFSYNCSENDSM                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CYCLICMSGRESUMECNTOFSYNCSENDSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPTXLENOFSYNCSENDSM                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_IMMEDIATETIMESYNCOFSYNCSENDSM                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFSSUBTLVOFSYNCSENDSM                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SyncSendSm.OfsSubTlv' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_PORTSYNCSENDSMIDXOFSYNCSENDSM                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATUSSUBTLVOFSYNCSENDSM                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_SyncSendSm.StatusSubTlv' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_SYNCLOGMSGINTERVALOFSYNCSENDSM                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDINTERVALOFSYNCSENDSM                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEBASEUPDATECOUNTERIDXOFSYNCSENDSM                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEBASEUPDATECOUNTERUSEDOFSYNCSENDSM                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMESUBTLVOFSYNCSENDSM                                                              STD_OFF  /**< Deactivateable: 'EthTSyn_SyncSendSm.TimeSubTlv' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_TXCRCSECUREDOFSYNCSENDSM                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_USERDATASUBTLVOFSYNCSENDSM                                                          STD_OFF  /**< Deactivateable: 'EthTSyn_SyncSendSm.UserDataSubTlv' Reason: 'Message compliance is enabled.' */
#define ETHTSYN_SYNCSENDSMDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPCORRFIELDOFSYNCSENDSMDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PRECISEORIGINTSOFSYNCSENDSMDYN                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SEQUENCEIDOFSYNCSENDSMDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SMRESETREQUESTEDOFSYNCSENDSMDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_STATEOFSYNCSENDSMDYN                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCTXINFOOFSYNCSENDSMDYN                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXINTERVALCNTOFSYNCSENDSMDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDSMMAXFUPTXLEN                                                               STD_OFF  /**< Deactivateable: 'EthTSyn_SyncSendSmMaxFupTxLen' Reason: 'Master support is disabled.' */
#define ETHTSYN_TIMEBASEUPDATECOUNTER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCHRONIZEDTIMEBASEIDOFTIMEBASEUPDATECOUNTER                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEBASEUPDATECOUNTERDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_UPDATEDOFTIMEBASEUPDATECOUNTERDYN                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_VALUEOFTIMEBASEUPDATECOUNTERDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXT                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTIDXOFTXCONFCONTEXT                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXSMIDXOFTXCONFCONTEXT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXSMOFTXCONFCONTEXT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ACTIVEOFTXCONFCONTEXTDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BUFFERIDXOFTXCONFCONTEXTDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_EGRTSINTVLTOFTXCONFCONTEXTDYN                                                       STD_OFF  /**< Deactivateable: 'EthTSyn_TxConfContextDyn.EgrTsIntVlt' Reason: 'Switch management is disabled.' */
#define ETHTSYN_EGRTSINTVLTVALIDOFTXCONFCONTEXTDYN                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_TxConfContextDyn.EgrTsIntVltValid' Reason: 'Switch management is disabled.' */
#define ETHTSYN_SWTMGMTTXDYNIDXOFTXCONFCONTEXTDYN                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_TxConfContextDyn.SwtMgmtTxDynIdx' Reason: 'Switch management is disabled.' */
#define ETHTSYN_TXCONFCONTEXTNEXTACTIVEIDXOFTXCONFCONTEXTDYN                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTPREVACTIVEIDXOFTXCONFCONTEXTDYN                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYNACTIVEFIRSTIDX                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYNACTIVELASTIDX                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PCCONFIG                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCERCVSMDYNOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCERCVSMOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSMDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_ANNOUNCESENDSMOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BRIDGETXMASTERPORTDYNOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_BRIDGETXMASTERPORTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLETHIFCTRLDYNOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLETHIFCTRLOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPHYSPORTDYNOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPHYSPORTOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTINDOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLPORTOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_COMCTRLTIMEDOMAINOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_CRCHNDLOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACINDOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_DESTINATIONMACOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTSYN_FUPDATAIDLISTOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_FUPRXHANDLEROFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHTSYN_MSGSENTCBKBUFOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_OFFSETTIMEDOMAINOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSMDYNOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQSMOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDREQTRCVDYNOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPSMDYNOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PDRESPSMOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTPARAMSTATSDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSMDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_PORTSYNCSENDSMOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASBUFOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASDYNOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_RATEMEASOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SITESYNCSYNCTXDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SITESYNCSYNCTXOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCERCVSMDYNOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCERCVSMOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCESENDSMDYNOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFANNOUNCESENDSMOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMDYNOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfAsymSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMFUPHNDLDYNOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfAsymSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMFUPPAYLOADBUFDYNOFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfAsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Deactivateable: 'AsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSmFupPayloadBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFASYMSITESYNCSYNCSMOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfAsymSiteSyncSyncSm' Reason: 'Deactivateable: 'AsymSiteSyncSyncSm' Reason: 'Deactivateable: 'EthTSyn_AsymSiteSyncSyncSm' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFBRIDGETXMASTERPORTDYNOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFBRIDGETXMASTERPORTOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLETHIFCTRLDYNOFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLETHIFCTRLOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPHYSPORTDYNOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPHYSPORTOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPORTINDOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLPORTOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCOMCTRLTIMEDOMAINOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFCRCHNDLOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFDESTINATIONMACINDOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFDESTINATIONMACOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPDATAIDLISTOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPPAYLOADBUFDYNOFPCCONFIG                                                    STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfFupPayloadBufDyn' Reason: 'Deactivateable: 'FupPayloadBufDyn' Reason: 'Deactivateable: 'EthTSyn_FupPayloadBufDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFFUPRXHANDLERDYNOFPCCONFIG                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfFupRxHandlerDyn' Reason: 'Deactivateable: 'FupRxHandlerDyn' Reason: 'Deactivateable: 'EthTSyn_FupRxHandlerDyn' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFFUPRXHANDLEROFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFFUPRXOFSDOMAINHANDLERDYNOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfFupRxOfsDomainHandlerDyn' Reason: 'Deactivateable: 'FupRxOfsDomainHandlerDyn' Reason: 'Deactivateable: 'EthTSyn_FupRxOfsDomainHandlerDyn' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFFUPRXOFSDOMAINHANDLEROFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfFupRxOfsDomainHandler' Reason: 'Deactivateable: 'FupRxOfsDomainHandler' Reason: 'Deactivateable: 'EthTSyn_FupRxOfsDomainHandler' Reason: 'Message compliance is enabled.''' */
#define ETHTSYN_SIZEOFMSGSENTCBKBUFOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFOFFSETTIMEDOMAINOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQSMDYNOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQSMOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDREQTRCVDYNOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDRESPSMDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPDRESPSMOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTPARAMSTATSDYNOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTSYNCSENDSMDYNOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFPORTSYNCSENDSMOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEASBUFOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEASDYNOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFRATEMEASOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMDYNOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSiteSyncSyncSmDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMFUPHNDLDYNOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmFupHndlDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmFupHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSiteSyncSyncSm' Reason: 'Deactivateable: 'SiteSyncSyncSm' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSm' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCSMSYNCHNDLDYNOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSiteSyncSyncSmSyncHndlDyn' Reason: 'Deactivateable: 'SiteSyncSyncSmSyncHndlDyn' Reason: 'Deactivateable: 'EthTSyn_SiteSyncSyncSmSyncHndlDyn' Reason: 'Bridge mode is not TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSITESYNCSYNCTXDYNOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSITESYNCSYNCTXOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXDATAHANDLEROFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXDATAOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSLAVESWITCHIDXLISTOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSWTMGMTQBUFDYNOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQBufDyn' Reason: 'Deactivateable: 'SwtMgmtQBufDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQBufDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQBUFOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQBuf' Reason: 'Deactivateable: 'SwtMgmtQBuf' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQBuf' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQDYNOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQDyn' Reason: 'Deactivateable: 'SwtMgmtQDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTQEGRTSBUFDYNOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQEgrTsBufDyn' Reason: 'Deactivateable: 'SwtMgmtQEgrTsBufDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQEgrTsBufDyn' Reason: 'Bridge mode is not ASYMMETRIC_TRANSPARENT_CLOCK.''' */
#define ETHTSYN_SIZEOFSWTMGMTQINDOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQInd' Reason: 'Deactivateable: 'SwtMgmtQInd' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQInd' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define ETHTSYN_SIZEOFSWTMGMTQOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtQ' Reason: 'Deactivateable: 'SwtMgmtQ' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtQ' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTRXDYNOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtRxDyn' Reason: 'Deactivateable: 'SwtMgmtRxDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRxDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTRXMSGBUFOFPCCONFIG                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtRxMsgBuf' Reason: 'Deactivateable: 'SwtMgmtRxMsgBuf' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRxMsgBuf' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTRXOFPCCONFIG                                                           STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtRx' Reason: 'Deactivateable: 'SwtMgmtRx' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtRx' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTMGMTTXDYNOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SizeOfSwtMgmtTxDyn' Reason: 'Deactivateable: 'SwtMgmtTxDyn' Reason: 'Deactivateable: 'EthTSyn_SwtMgmtTxDyn' Reason: 'Switch management is disabled''' */
#define ETHTSYN_SIZEOFSWTTIMESYNCSMDYNOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSWTTIMESYNCSMOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCRCVSMDYNOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCRCVSMOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCSENDSMDYNOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFSYNCSENDSMOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTIMEBASEUPDATECOUNTERDYNOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTIMEBASEUPDATECOUNTEROFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTXCONFCONTEXTDYNOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SIZEOFTXCONFCONTEXTOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAHANDLEROFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXDATAOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SLAVESWITCHIDXLISTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTTIMESYNCSMDYNOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SWTTIMESYNCSMOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRCVSMDYNOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCRCVSMOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDSMDYNOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_SYNCSENDSMMAXFUPTXLENOFPCCONFIG                                                     STD_OFF  /**< Deactivateable: 'EthTSyn_PCConfig.SyncSendSmMaxFupTxLen' Reason: 'Master support is disabled.' */
#define ETHTSYN_SYNCSENDSMOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEBASEUPDATECOUNTERDYNOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TIMEBASEUPDATECOUNTEROFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYNACTIVEFIRSTIDXOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYNACTIVELASTIDXOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTDYNOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHTSYN_TXCONFCONTEXTOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCMinNumericValueDefines  EthTSyn Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define ETHTSYN_MIN_RXTIMEOUTCOUNTEROFANNOUNCERCVSMDYN                                              0u
#define ETHTSYN_MIN_ANNOUNCECYCLETIMEROFANNOUNCESENDSMDYN                                           0u
#define ETHTSYN_MIN_SEQUENCEIDOFANNOUNCESENDSMDYN                                                   0u
#define ETHTSYN_MIN_SYNCFWDDELAYNSOFBRIDGETXMASTERPORTDYN                                           0u
#define ETHTSYN_MIN_CLOCKIDOFCOMCTRLETHIFCTRLDYN                                                    0u
#define ETHTSYN_MIN_DEBOUNCETIMEROFCOMCTRLPHYSPORTDYN                                               0u
#define ETHTSYN_MIN_MSGSENTCBKBUF                                                                   0u
#define ETHTSYN_MIN_LOSTRESPONSECNTOFPDREQSMDYN                                                     0u
#define ETHTSYN_MIN_RESPTIMEOUTCNTOFPDREQSMDYN                                                      0u
#define ETHTSYN_MIN_SEQUENCEIDOFPDREQSMDYN                                                          0u
#define ETHTSYN_MIN_TXINTERVALCNTOFPDREQSMDYN                                                       0u
#define ETHTSYN_MIN_RESPCLOCKIDOFPDREQTRCVDYN                                                       0u
#define ETHTSYN_MIN_RESPPORTNUMOFPDREQTRCVDYN                                                       0u
#define ETHTSYN_MIN_REQUESTORCLOCKIDOFPDRESPSMDYN                                                   0u
#define ETHTSYN_MIN_REQUESTORPORTNUMOFPDRESPSMDYN                                                   0u
#define ETHTSYN_MIN_SEQUENCEIDOFPDRESPSMDYN                                                         0u
#define ETHTSYN_MIN_PDLOSTRESPEXCEEDEDCOUNTOFPORTPARAMSTATSDYN                                      0u
#define ETHTSYN_MIN_RXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                              0u
#define ETHTSYN_MIN_RXDISCARDCOUNTOFPORTPARAMSTATSDYN                                               0u
#define ETHTSYN_MIN_RXFUPCOUNTOFPORTPARAMSTATSDYN                                                   0u
#define ETHTSYN_MIN_RXPDREQCOUNTOFPORTPARAMSTATSDYN                                                 0u
#define ETHTSYN_MIN_RXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                0u
#define ETHTSYN_MIN_RXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                             0u
#define ETHTSYN_MIN_RXSYNCCOUNTOFPORTPARAMSTATSDYN                                                  0u
#define ETHTSYN_MIN_TXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                              0u
#define ETHTSYN_MIN_TXFUPCOUNTOFPORTPARAMSTATSDYN                                                   0u
#define ETHTSYN_MIN_TXPDREQCOUNTOFPORTPARAMSTATSDYN                                                 0u
#define ETHTSYN_MIN_TXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                0u
#define ETHTSYN_MIN_TXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                             0u
#define ETHTSYN_MIN_TXSYNCCOUNTOFPORTPARAMSTATSDYN                                                  0u
#define ETHTSYN_MIN_ACTIVENROFSYNCCYCLESOFRATEMEASBUF                                               0u
#define ETHTSYN_MIN_LASTCORRECTEDOFFSETNSOFRATEMEASDYN                                              -9223372036854775807-1
#define ETHTSYN_MIN_OUTOFSYNCCNTOFRATEMEASDYN                                                       0u
#define ETHTSYN_MIN_SYNCCYCLECOUNTEROFRATEMEASDYN                                                   0u
#define ETHTSYN_MIN_FWDRETRYCNTOFSITESYNCSYNCTXDYN                                                  0u
#define ETHTSYN_MIN_VALIDMASTERCLOCKIDOFSLAVERXMASTERCLOCKIDDYN                                     0u
#define ETHTSYN_MIN_SYNCEVENTTIMEOUTCNTOFSWTTIMESYNCSMDYN                                           0u
#define ETHTSYN_MIN_FUPRXTIMEOUTCNTOFSYNCRCVSMDYN                                                   0u
#define ETHTSYN_MIN_SYNCSEQUENCEIDOFSYNCRCVSMDYN                                                    0u
#define ETHTSYN_MIN_SYNCSRCCLOCKIDOFSYNCRCVSMDYN                                                    0u
#define ETHTSYN_MIN_SYNCSRCPORTNUMOFSYNCRCVSMDYN                                                    0u
#define ETHTSYN_MIN_FUPCORRFIELDOFSYNCSENDSMDYN                                                     0u
#define ETHTSYN_MIN_SEQUENCEIDOFSYNCSENDSMDYN                                                       0u
#define ETHTSYN_MIN_TXINTERVALCNTOFSYNCSENDSMDYN                                                    0u
#define ETHTSYN_MIN_VALUEOFTIMEBASEUPDATECOUNTERDYN                                                 0u
#define ETHTSYN_MIN_BUFFERIDXOFTXCONFCONTEXTDYN                                                     0u
#define ETHTSYN_MIN_TXCONFCONTEXTNEXTACTIVEIDXOFTXCONFCONTEXTDYN                                    0u
#define ETHTSYN_MIN_TXCONFCONTEXTPREVACTIVEIDXOFTXCONFCONTEXTDYN                                    0u
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCMaxNumericValueDefines  EthTSyn Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define ETHTSYN_MAX_RXTIMEOUTCOUNTEROFANNOUNCERCVSMDYN                                              4294967295u
#define ETHTSYN_MAX_ANNOUNCECYCLETIMEROFANNOUNCESENDSMDYN                                           4294967295u
#define ETHTSYN_MAX_SEQUENCEIDOFANNOUNCESENDSMDYN                                                   65535u
#define ETHTSYN_MAX_SYNCFWDDELAYNSOFBRIDGETXMASTERPORTDYN                                           18446744073709551615u
#define ETHTSYN_MAX_CLOCKIDOFCOMCTRLETHIFCTRLDYN                                                    18446744073709551615u
#define ETHTSYN_MAX_DEBOUNCETIMEROFCOMCTRLPHYSPORTDYN                                               4294967295u
#define ETHTSYN_MAX_MSGSENTCBKBUF                                                                   255u
#define ETHTSYN_MAX_LOSTRESPONSECNTOFPDREQSMDYN                                                     255u
#define ETHTSYN_MAX_RESPTIMEOUTCNTOFPDREQSMDYN                                                      4294967295u
#define ETHTSYN_MAX_SEQUENCEIDOFPDREQSMDYN                                                          65535u
#define ETHTSYN_MAX_TXINTERVALCNTOFPDREQSMDYN                                                       4294967295u
#define ETHTSYN_MAX_RESPCLOCKIDOFPDREQTRCVDYN                                                       18446744073709551615u
#define ETHTSYN_MAX_RESPPORTNUMOFPDREQTRCVDYN                                                       65535u
#define ETHTSYN_MAX_REQUESTORCLOCKIDOFPDRESPSMDYN                                                   18446744073709551615u
#define ETHTSYN_MAX_REQUESTORPORTNUMOFPDRESPSMDYN                                                   65535u
#define ETHTSYN_MAX_SEQUENCEIDOFPDRESPSMDYN                                                         65535u
#define ETHTSYN_MAX_PDLOSTRESPEXCEEDEDCOUNTOFPORTPARAMSTATSDYN                                      4294967295u
#define ETHTSYN_MAX_RXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                              4294967295u
#define ETHTSYN_MAX_RXDISCARDCOUNTOFPORTPARAMSTATSDYN                                               4294967295u
#define ETHTSYN_MAX_RXFUPCOUNTOFPORTPARAMSTATSDYN                                                   4294967295u
#define ETHTSYN_MAX_RXPDREQCOUNTOFPORTPARAMSTATSDYN                                                 4294967295u
#define ETHTSYN_MAX_RXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                4294967295u
#define ETHTSYN_MAX_RXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                             4294967295u
#define ETHTSYN_MAX_RXSYNCCOUNTOFPORTPARAMSTATSDYN                                                  4294967295u
#define ETHTSYN_MAX_TXANNOUNCECOUNTOFPORTPARAMSTATSDYN                                              4294967295u
#define ETHTSYN_MAX_TXFUPCOUNTOFPORTPARAMSTATSDYN                                                   4294967295u
#define ETHTSYN_MAX_TXPDREQCOUNTOFPORTPARAMSTATSDYN                                                 4294967295u
#define ETHTSYN_MAX_TXPDRESPCOUNTOFPORTPARAMSTATSDYN                                                4294967295u
#define ETHTSYN_MAX_TXPDRESPFUPCOUNTOFPORTPARAMSTATSDYN                                             4294967295u
#define ETHTSYN_MAX_TXSYNCCOUNTOFPORTPARAMSTATSDYN                                                  4294967295u
#define ETHTSYN_MAX_ACTIVENROFSYNCCYCLESOFRATEMEASBUF                                               255u
#define ETHTSYN_MAX_LASTCORRECTEDOFFSETNSOFRATEMEASDYN                                              9223372036854775807
#define ETHTSYN_MAX_OUTOFSYNCCNTOFRATEMEASDYN                                                       255u
#define ETHTSYN_MAX_SYNCCYCLECOUNTEROFRATEMEASDYN                                                   255u
#define ETHTSYN_MAX_FWDRETRYCNTOFSITESYNCSYNCTXDYN                                                  255u
#define ETHTSYN_MAX_VALIDMASTERCLOCKIDOFSLAVERXMASTERCLOCKIDDYN                                     18446744073709551615u
#define ETHTSYN_MAX_SYNCEVENTTIMEOUTCNTOFSWTTIMESYNCSMDYN                                           4294967295u
#define ETHTSYN_MAX_FUPRXTIMEOUTCNTOFSYNCRCVSMDYN                                                   4294967295u
#define ETHTSYN_MAX_SYNCSEQUENCEIDOFSYNCRCVSMDYN                                                    65535u
#define ETHTSYN_MAX_SYNCSRCCLOCKIDOFSYNCRCVSMDYN                                                    18446744073709551615u
#define ETHTSYN_MAX_SYNCSRCPORTNUMOFSYNCRCVSMDYN                                                    65535u
#define ETHTSYN_MAX_FUPCORRFIELDOFSYNCSENDSMDYN                                                     18446744073709551615u
#define ETHTSYN_MAX_SEQUENCEIDOFSYNCSENDSMDYN                                                       65535u
#define ETHTSYN_MAX_TXINTERVALCNTOFSYNCSENDSMDYN                                                    4294967295u
#define ETHTSYN_MAX_VALUEOFTIMEBASEUPDATECOUNTERDYN                                                 255u
#define ETHTSYN_MAX_BUFFERIDXOFTXCONFCONTEXTDYN                                                     255u
#define ETHTSYN_MAX_TXCONFCONTEXTNEXTACTIVEIDXOFTXCONFCONTEXTDYN                                    255u
#define ETHTSYN_MAX_TXCONFCONTEXTPREVACTIVEIDXOFTXCONFCONTEXTDYN                                    255u
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCNoReferenceDefines  EthTSyn No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define ETHTSYN_NO_ANNOUNCESENDSMIDXOFCOMCTRLPORT                                                   255u
#define ETHTSYN_NO_PDREQSMIDXOFCOMCTRLPORT                                                          255u
#define ETHTSYN_NO_PDRESPSMIDXOFCOMCTRLPORT                                                         255u
#define ETHTSYN_NO_PORTPARAMSTATSDYNIDXOFCOMCTRLPORT                                                255u
#define ETHTSYN_NO_PORTSYNCSENDSMIDXOFCOMCTRLPORT                                                   255u
#define ETHTSYN_NO_SLAVERXDATAHANDLERIDXOFCOMCTRLPORT                                               255u
#define ETHTSYN_NO_SYNCSENDSMIDXOFCOMCTRLPORT                                                       255u
#define ETHTSYN_NO_OFFSETTIMEDOMAINENDIDXOFCOMCTRLTIMEDOMAIN                                        255u
#define ETHTSYN_NO_OFFSETTIMEDOMAINSTARTIDXOFCOMCTRLTIMEDOMAIN                                      255u
#define ETHTSYN_NO_CRCHNDLIDXOFFUPRXHANDLER                                                         255u
#define ETHTSYN_NO_MSGSENTCBKBUFENDIDXOFPORTSYNCSENDSM                                              255u
#define ETHTSYN_NO_MSGSENTCBKBUFSTARTIDXOFPORTSYNCSENDSM                                            255u
#define ETHTSYN_NO_ANNOUNCERCVSMIDXOFSLAVERXDATA                                                    255u
#define ETHTSYN_NO_SLAVERXMASTERCLOCKIDDYNIDXOFSLAVERXDATA                                          255u
#define ETHTSYN_NO_SLAVERXSRCPORTIDCHECKCLOCKIDIDXOFSLAVERXDATA                                     255u
#define ETHTSYN_NO_SLAVESWITCHIDXLISTENDIDXOFSWTTIMESYNCSM                                          255u
#define ETHTSYN_NO_SLAVESWITCHIDXLISTSTARTIDXOFSWTTIMESYNCSM                                        255u
#define ETHTSYN_NO_PORTPARAMSTATSDYNIDXOFSYNCRCVSM                                                  255u
#define ETHTSYN_NO_CRCHNDLIDXOFSYNCSENDSM                                                           255u
#define ETHTSYN_NO_TIMEBASEUPDATECOUNTERIDXOFSYNCSENDSM                                             255u
#define ETHTSYN_NO_TXCONFCONTEXTNEXTACTIVEIDXOFTXCONFCONTEXTDYN                                     255u
#define ETHTSYN_NO_TXCONFCONTEXTPREVACTIVEIDXOFTXCONFCONTEXTDYN                                     255u
#define ETHTSYN_NO_TXCONFCONTEXTDYNACTIVEFIRSTIDX                                                   255u
#define ETHTSYN_NO_TXCONFCONTEXTDYNACTIVELASTIDX                                                    255u
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCEnumExistsDefines  EthTSyn Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define ETHTSYN_EXISTS_SWTMGMTRX_SWTMGMTOBJUSEROFSWTMGMTQBUF                                        STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtObjUser' Reason: 'Switch management is disabled' */
#define ETHTSYN_EXISTS_SWTMGMTTXDYN_SWTMGMTOBJUSEROFSWTMGMTQBUF                                     STD_OFF  /**< Deactivateable: 'EthTSyn_SwtMgmtQBuf.SwtMgmtObjUser' Reason: 'Switch management is disabled' */
#define ETHTSYN_EXISTS_PORTSYNCSENDSM_TXSMOFTXCONFCONTEXT                                           STD_ON
#define ETHTSYN_EXISTS_PDREQSM_TXSMOFTXCONFCONTEXT                                                  STD_ON
#define ETHTSYN_EXISTS_PDRESPSM_TXSMOFTXCONFCONTEXT                                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCEnumDefines  EthTSyn Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define ETHTSYN_NO_VALID_MASTER_STATEOFANNOUNCERCVSMDYN                                             0x00u
#define ETHTSYN_VALID_MASTER_SET_STATEOFANNOUNCERCVSMDYN                                            0x01u
#define ETHTSYN_INITIALIZING_STATEOFANNOUNCESENDSMDYN                                               0x00u
#define ETHTSYN_TX_ANNOUNCE_STATEOFANNOUNCESENDSMDYN                                                0x01u
#define ETHTSYN_WAIT_TX_ANNOUNCE_STATEOFANNOUNCESENDSMDYN                                           0x02u
#define ETHTSYN_NONE_FUPFWDSTATEOFBRIDGETXMASTERPORTDYN                                             0x00u
#define ETHTSYN_PENDING_FUPFWDSTATEOFBRIDGETXMASTERPORTDYN                                          0x01u
#define ETHTSYN_CALC_SYNC_FWD_DELAY_FUPFWDSTATEOFBRIDGETXMASTERPORTDYN                              0x02u
#define ETHTSYN_FINISHED_FUPFWDSTATEOFBRIDGETXMASTERPORTDYN                                         0x03u
#define ETHTSYN_INITIALIZING_STATEOFPDREQSMDYN                                                      0x00u
#define ETHTSYN_TX_PD_REQ_STATEOFPDREQSMDYN                                                         0x01u
#define ETHTSYN_WAIT_TX_PD_REQ_STATEOFPDREQSMDYN                                                    0x02u
#define ETHTSYN_WAIT_RESP_RESP_FUP_STATEOFPDREQSMDYN                                                0x03u
#define ETHTSYN_WAIT_REQ_EGR_TS_STATEOFPDREQSMDYN                                                   0x04u
#define ETHTSYN_COMPUTE_PDELAY_STATEOFPDREQSMDYN                                                    0x05u
#define ETHTSYN_IDLE_STATEOFPDREQTRCVDYN                                                            0x00u
#define ETHTSYN_WAIT_PD_RESP_STATEOFPDREQTRCVDYN                                                    0x01u
#define ETHTSYN_WAIT_PD_RESP_FUP_STATEOFPDREQTRCVDYN                                                0x02u
#define ETHTSYN_WAIT_PD_REQ_EGR_TS_STATEOFPDREQTRCVDYN                                              0x03u
#define ETHTSYN_ALL_DATA_AVAILABLE_STATEOFPDREQTRCVDYN                                              0x04u
#define ETHTSYN_INITIALIZING_STATEOFPDRESPSMDYN                                                     0x00u
#define ETHTSYN_WAIT_RX_PD_REQ_STATEOFPDRESPSMDYN                                                   0x01u
#define ETHTSYN_TX_PD_RESP_STATEOFPDRESPSMDYN                                                       0x02u
#define ETHTSYN_WAIT_PD_RESP_EGR_TS_STATEOFPDRESPSMDYN                                              0x03u
#define ETHTSYN_TX_PD_RESP_FUP_STATEOFPDRESPSMDYN                                                   0x04u
#define ETHTSYN_WAIT_TX_SYNC_STATEOFPORTSYNCSENDSMDYN                                               0x00u
#define ETHTSYN_WAIT_SYNC_EGR_TS_STATEOFPORTSYNCSENDSMDYN                                           0x01u
#define ETHTSYN_WAIT_TX_FUP_STATEOFPORTSYNCSENDSMDYN                                                0x02u
#define ETHTSYN_TX_FUP_STATEOFPORTSYNCSENDSMDYN                                                     0x03u
#define ETHTSYN_WAIT_FIRST_TS_STATEOFRATEMEASDYN                                                    0x00u
#define ETHTSYN_WAIT_SECOND_TS_STATEOFRATEMEASDYN                                                   0x01u
#define ETHTSYN_TS_READY_STATEOFRATEMEASDYN                                                         0x02u
#define ETHTSYN_IDLE_STATEOFSITESYNCSYNCTXDYN                                                       0x00u
#define ETHTSYN_TX_SYNC_STATEOFSITESYNCSYNCTXDYN                                                    0x01u
#define ETHTSYN_TX_FUP_STATEOFSITESYNCSYNCTXDYN                                                     0x02u
#define ETHTSYN_WAIT_TS_STATEOFSWTTIMESYNCSMDYN                                                     0x00u
#define ETHTSYN_TS_READY_STATEOFSWTTIMESYNCSMDYN                                                    0x01u
#define ETHTSYN_WAIT_RX_SYNC_STATEOFSYNCRCVSMDYN                                                    0x00u
#define ETHTSYN_WAIT_RX_FUP_STATEOFSYNCRCVSMDYN                                                     0x01u
#define ETHTSYN_INITIALIZING_STATEOFSYNCSENDSMDYN                                                   0x00u
#define ETHTSYN_WAIT_TX_SYNC_STATEOFSYNCSENDSMDYN                                                   0x01u
#define ETHTSYN_TX_CYCLIC_SYNC_STATEOFSYNCSENDSMDYN                                                 0x02u
#define ETHTSYN_TX_IMMEDIATE_SYNC_STATEOFSYNCSENDSMDYN                                              0x03u
#define ETHTSYN_WAIT_SYNC_EGR_TS_STATEOFSYNCSENDSMDYN                                               0x04u
#define ETHTSYN_TX_FUP_STATEOFSYNCSENDSMDYN                                                         0x05u
#define ETHTSYN_PORTSYNCSENDSM_TXSMOFTXCONFCONTEXT                                                  0x00u
#define ETHTSYN_PDREQSM_TXSMOFTXCONFCONTEXT                                                         0x01u
#define ETHTSYN_PDRESPSM_TXSMOFTXCONFCONTEXT                                                        0x02u
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCIsReducedToDefineDefines  EthTSyn Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFANNOUNCERCVSM                                                 STD_OFF
#define ETHTSYN_ISDEF_MAXSTEPSREMOVEDOFANNOUNCERCVSM                                                STD_OFF
#define ETHTSYN_ISDEF_RXTIMEOUTOFANNOUNCERCVSM                                                      STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAIDXOFANNOUNCERCVSM                                                 STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCELOGMSGINTERVALOFANNOUNCESENDSM                                        STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCETXCYCLEOFANNOUNCESENDSM                                               STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFANNOUNCESENDSM                                                STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFBRIDGETXMASTERPORT                                            STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTINDENDIDXOFCOMCTRLETHIFCTRL                                        STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTINDSTARTIDXOFCOMCTRLETHIFCTRL                                      STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACINDENDIDXOFCOMCTRLETHIFCTRL                                     STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACINDSTARTIDXOFCOMCTRLETHIFCTRL                                   STD_OFF
#define ETHTSYN_ISDEF_ETHIFCTRLIDXOFCOMCTRLETHIFCTRL                                                STD_OFF
#define ETHTSYN_ISDEF_ALWAYSASCAPABLEOFCOMCTRLPHYSPORT                                              STD_OFF
#define ETHTSYN_ISDEF_DEBOUNCETIMERINITOFCOMCTRLPHYSPORT                                            STD_OFF
#define ETHTSYN_ISDEF_INITIALPDELAYNSOFCOMCTRLPHYSPORT                                              STD_OFF
#define ETHTSYN_ISDEF_USESTATICPDELAYOFCOMCTRLPHYSPORT                                              STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCESENDSMIDXOFCOMCTRLPORT                                                STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCESENDSMUSEDOFCOMCTRLPORT                                               STD_OFF
#define ETHTSYN_ISDEF_COMCTRLETHIFCTRLIDXOFCOMCTRLPORT                                              STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPHYSPORTIDXOFCOMCTRLPORT                                               STD_OFF
#define ETHTSYN_ISDEF_COMCTRLTIMEDOMAINIDXOFCOMCTRLPORT                                             STD_OFF
#define ETHTSYN_ISDEF_FRAMEPRIOOFCOMCTRLPORT                                                        STD_OFF
#define ETHTSYN_ISDEF_NUMBEROFCOMCTRLPORT                                                           STD_OFF
#define ETHTSYN_ISDEF_PDREQSMIDXOFCOMCTRLPORT                                                       STD_OFF
#define ETHTSYN_ISDEF_PDREQSMUSEDOFCOMCTRLPORT                                                      STD_OFF
#define ETHTSYN_ISDEF_PDRESPSMIDXOFCOMCTRLPORT                                                      STD_OFF
#define ETHTSYN_ISDEF_PDRESPSMUSEDOFCOMCTRLPORT                                                     STD_OFF
#define ETHTSYN_ISDEF_PORTPARAMSTATSDYNIDXOFCOMCTRLPORT                                             STD_OFF
#define ETHTSYN_ISDEF_PORTPARAMSTATSDYNUSEDOFCOMCTRLPORT                                            STD_OFF
#define ETHTSYN_ISDEF_PORTSYNCSENDSMIDXOFCOMCTRLPORT                                                STD_OFF
#define ETHTSYN_ISDEF_PORTSYNCSENDSMUSEDOFCOMCTRLPORT                                               STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAHANDLERIDXOFCOMCTRLPORT                                            STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAHANDLERUSEDOFCOMCTRLPORT                                           STD_OFF
#define ETHTSYN_ISDEF_SYNCSENDSMIDXOFCOMCTRLPORT                                                    STD_OFF
#define ETHTSYN_ISDEF_SYNCSENDSMUSEDOFCOMCTRLPORT                                                   STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIND                                                                STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTENDIDXOFCOMCTRLTIMEDOMAIN                                          STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTSTARTIDXOFCOMCTRLTIMEDOMAIN                                        STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACIDXOFCOMCTRLTIMEDOMAIN                                          STD_OFF
#define ETHTSYN_ISDEF_IDOFCOMCTRLTIMEDOMAIN                                                         STD_OFF
#define ETHTSYN_ISDEF_OFFSETTIMEDOMAINENDIDXOFCOMCTRLTIMEDOMAIN                                     STD_OFF
#define ETHTSYN_ISDEF_OFFSETTIMEDOMAINSTARTIDXOFCOMCTRLTIMEDOMAIN                                   STD_OFF
#define ETHTSYN_ISDEF_OFFSETTIMEDOMAINUSEDOFCOMCTRLTIMEDOMAIN                                       STD_OFF
#define ETHTSYN_ISDEF_SYNCHRONIZEDTIMEBASEIDOFCOMCTRLTIMEDOMAIN                                     STD_OFF
#define ETHTSYN_ISDEF_FUPDATAIDLISTENDIDXOFCRCHNDL                                                  STD_OFF
#define ETHTSYN_ISDEF_FUPDATAIDLISTSTARTIDXOFCRCHNDL                                                STD_OFF
#define ETHTSYN_ISDEF_BYTE0OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_BYTE1OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_BYTE2OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_BYTE3OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_BYTE4OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_BYTE5OFDESTINATIONMAC                                                         STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACIND                                                             STD_OFF
#define ETHTSYN_ISDEF_FUPDATAIDLIST                                                                 STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTEXTERNALIDXOFFUPRXHANDLER                                          STD_OFF
#define ETHTSYN_ISDEF_CRCFLAGSRXVALIDATEDOFFUPRXHANDLER                                             STD_OFF
#define ETHTSYN_ISDEF_CRCHNDLIDXOFFUPRXHANDLER                                                      STD_OFF
#define ETHTSYN_ISDEF_CRCHNDLUSEDOFFUPRXHANDLER                                                     STD_OFF
#define ETHTSYN_ISDEF_FUPCORRFIELDTHRESHOLDNSOFFUPRXHANDLER                                         STD_OFF
#define ETHTSYN_ISDEF_RXCRCVALIDATEDOFFUPRXHANDLER                                                  STD_OFF
#define ETHTSYN_ISDEF_TIMEVALIDATIONENABLEDOFFUPRXHANDLER                                           STD_OFF
#define ETHTSYN_ISDEF_IDOFOFFSETTIMEDOMAIN                                                          STD_OFF
#define ETHTSYN_ISDEF_SYNCHRONIZEDTIMEBASEIDOFOFFSETTIMEDOMAIN                                      STD_OFF
#define ETHTSYN_ISDEF_AVERAGEWEIGHTOFPDREQSM                                                        STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFPDREQSM                                                       STD_OFF
#define ETHTSYN_ISDEF_LOGMSGINTERVALOFPDREQSM                                                       STD_OFF
#define ETHTSYN_ISDEF_MAXLOSTRESPONSESOFPDREQSM                                                     STD_OFF
#define ETHTSYN_ISDEF_PDREQPERIODOFPDREQSM                                                          STD_OFF
#define ETHTSYN_ISDEF_PDRESPTIMEOUTOFPDREQSM                                                        STD_OFF
#define ETHTSYN_ISDEF_PDTHRESHOLDOFPDREQSM                                                          STD_OFF
#define ETHTSYN_ISDEF_TIMEVALIDATIONENABLEDOFPDREQSM                                                STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTIDXOFPDREQSM                                                     STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFPDRESPSM                                                      STD_OFF
#define ETHTSYN_ISDEF_TIMEVALIDATIONENABLEDOFPDRESPSM                                               STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTIDXOFPDRESPSM                                                    STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFPORTSYNCSENDSM                                                STD_OFF
#define ETHTSYN_ISDEF_FOLLOWUPSENTCBKPTROFPORTSYNCSENDSM                                            STD_OFF
#define ETHTSYN_ISDEF_MSGSENTCBKBUFENDIDXOFPORTSYNCSENDSM                                           STD_OFF
#define ETHTSYN_ISDEF_MSGSENTCBKBUFLENGTHOFPORTSYNCSENDSM                                           STD_OFF
#define ETHTSYN_ISDEF_MSGSENTCBKBUFSTARTIDXOFPORTSYNCSENDSM                                         STD_OFF
#define ETHTSYN_ISDEF_MSGSENTCBKBUFUSEDOFPORTSYNCSENDSM                                             STD_OFF
#define ETHTSYN_ISDEF_SYNCSENTCBKPTROFPORTSYNCSENDSM                                                STD_OFF
#define ETHTSYN_ISDEF_TIMEVALIDATIONENABLEDOFPORTSYNCSENDSM                                         STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTIDXOFPORTSYNCSENDSM                                              STD_OFF
#define ETHTSYN_ISDEF_MAXOUTOFSYNCCNTOFRATEMEAS                                                     STD_OFF
#define ETHTSYN_ISDEF_NRSYNCCYCLESFOROFSCORROFRATEMEAS                                              STD_OFF
#define ETHTSYN_ISDEF_OFSJUMPCORRTHRESHOLDNSOFRATEMEAS                                              STD_OFF
#define ETHTSYN_ISDEF_RATEMEASBUFENDIDXOFRATEMEAS                                                   STD_OFF
#define ETHTSYN_ISDEF_RATEMEASBUFLENGTHOFRATEMEAS                                                   STD_OFF
#define ETHTSYN_ISDEF_RATEMEASBUFSTARTIDXOFRATEMEAS                                                 STD_OFF
#define ETHTSYN_ISDEF_RATERATIOMAXOFRATEMEAS                                                        STD_OFF
#define ETHTSYN_ISDEF_RATERATIOMINOFRATEMEAS                                                        STD_OFF
#define ETHTSYN_ISDEF_SYNCPRECISIONLIMITNSOFRATEMEAS                                                STD_OFF
#define ETHTSYN_ISDEF_USEINITIALOFFSETCORRECTIONOFRATEMEAS                                          STD_OFF
#define ETHTSYN_ISDEF_BRIDGETXMASTERPORTENDIDXOFSITESYNCSYNCTX                                      STD_OFF
#define ETHTSYN_ISDEF_BRIDGETXMASTERPORTSTARTIDXOFSITESYNCSYNCTX                                    STD_OFF
#define ETHTSYN_ISDEF_NUMMSGFWDRETRYOFSITESYNCSYNCTX                                                STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCERCVSMIDXOFSLAVERXDATA                                                 STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCERCVSMUSEDOFSLAVERXDATA                                                STD_OFF
#define ETHTSYN_ISDEF_SLAVERXMASTERCLOCKIDDYNIDXOFSLAVERXDATA                                       STD_OFF
#define ETHTSYN_ISDEF_SLAVERXMASTERCLOCKIDDYNUSEDOFSLAVERXDATA                                      STD_OFF
#define ETHTSYN_ISDEF_SLAVERXSRCPORTIDCHECKCLOCKIDIDXOFSLAVERXDATA                                  STD_OFF
#define ETHTSYN_ISDEF_SLAVERXSRCPORTIDCHECKCLOCKIDUSEDOFSLAVERXDATA                                 STD_OFF
#define ETHTSYN_ISDEF_SYNCRCVSMIDXOFSLAVERXDATA                                                     STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFSLAVERXDATAHANDLER                                            STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAEXTERNALIDXOFSLAVERXDATAHANDLER                                    STD_OFF
#define ETHTSYN_ISDEF_SLAVERXSRCPORTIDCHECKCLOCKID                                                  STD_OFF
#define ETHTSYN_ISDEF_SLAVESWITCHIDXLIST                                                            STD_OFF
#define ETHTSYN_ISDEF_APPLYRATERATIOTOSLAVESWITCHESOFSWTTIMESYNCSM                                  STD_OFF
#define ETHTSYN_ISDEF_ETHIFSWITCHIDXOFSWTTIMESYNCSM                                                 STD_OFF
#define ETHTSYN_ISDEF_RATEMEASIDXOFSWTTIMESYNCSM                                                    STD_OFF
#define ETHTSYN_ISDEF_SLAVESWITCHIDXLISTENDIDXOFSWTTIMESYNCSM                                       STD_OFF
#define ETHTSYN_ISDEF_SLAVESWITCHIDXLISTSTARTIDXOFSWTTIMESYNCSM                                     STD_OFF
#define ETHTSYN_ISDEF_SLAVESWITCHIDXLISTUSEDOFSWTTIMESYNCSM                                         STD_OFF
#define ETHTSYN_ISDEF_SWTSYNCSTATECHGFCTPTROFSWTTIMESYNCSM                                          STD_OFF
#define ETHTSYN_ISDEF_SYNCEVENTTIMEOUTOFSWTTIMESYNCSM                                               STD_OFF
#define ETHTSYN_ISDEF_FOLLOWUPRXTIMEOUTOFSYNCRCVSM                                                  STD_OFF
#define ETHTSYN_ISDEF_FUPRXHANDLERIDXOFSYNCRCVSM                                                    STD_OFF
#define ETHTSYN_ISDEF_PORTPARAMSTATSDYNIDXOFSYNCRCVSM                                               STD_OFF
#define ETHTSYN_ISDEF_PORTPARAMSTATSDYNUSEDOFSYNCRCVSM                                              STD_OFF
#define ETHTSYN_ISDEF_CRCHNDLIDXOFSYNCSENDSM                                                        STD_OFF
#define ETHTSYN_ISDEF_CRCHNDLUSEDOFSYNCSENDSM                                                       STD_OFF
#define ETHTSYN_ISDEF_CRCTIMEFLAGSOFSYNCSENDSM                                                      STD_OFF
#define ETHTSYN_ISDEF_CYCLICMSGRESUMECNTOFSYNCSENDSM                                                STD_OFF
#define ETHTSYN_ISDEF_FUPTXLENOFSYNCSENDSM                                                          STD_OFF
#define ETHTSYN_ISDEF_IMMEDIATETIMESYNCOFSYNCSENDSM                                                 STD_OFF
#define ETHTSYN_ISDEF_PORTSYNCSENDSMIDXOFSYNCSENDSM                                                 STD_OFF
#define ETHTSYN_ISDEF_SYNCLOGMSGINTERVALOFSYNCSENDSM                                                STD_OFF
#define ETHTSYN_ISDEF_SYNCSENDINTERVALOFSYNCSENDSM                                                  STD_OFF
#define ETHTSYN_ISDEF_TIMEBASEUPDATECOUNTERIDXOFSYNCSENDSM                                          STD_OFF
#define ETHTSYN_ISDEF_TIMEBASEUPDATECOUNTERUSEDOFSYNCSENDSM                                         STD_OFF
#define ETHTSYN_ISDEF_TXCRCSECUREDOFSYNCSENDSM                                                      STD_OFF
#define ETHTSYN_ISDEF_SYNCHRONIZEDTIMEBASEIDOFTIMEBASEUPDATECOUNTER                                 STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTIDXOFTXCONFCONTEXT                                                 STD_OFF
#define ETHTSYN_ISDEF_TXSMIDXOFTXCONFCONTEXT                                                        STD_OFF
#define ETHTSYN_ISDEF_TXSMOFTXCONFCONTEXT                                                           STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCERCVSMDYNOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCERCVSMOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCESENDSMDYNOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_ANNOUNCESENDSMOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_BRIDGETXMASTERPORTDYNOFPCCONFIG                                               STD_OFF
#define ETHTSYN_ISDEF_BRIDGETXMASTERPORTOFPCCONFIG                                                  STD_OFF
#define ETHTSYN_ISDEF_COMCTRLETHIFCTRLDYNOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_COMCTRLETHIFCTRLOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPHYSPORTDYNOFPCCONFIG                                                  STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPHYSPORTOFPCCONFIG                                                     STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTINDOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_COMCTRLPORTOFPCCONFIG                                                         STD_OFF
#define ETHTSYN_ISDEF_COMCTRLTIMEDOMAINOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_CRCHNDLOFPCCONFIG                                                             STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACINDOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_DESTINATIONMACOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_FUPDATAIDLISTOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_FUPRXHANDLEROFPCCONFIG                                                        STD_OFF
#define ETHTSYN_ISDEF_MSGSENTCBKBUFOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_OFFSETTIMEDOMAINOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_PDREQSMDYNOFPCCONFIG                                                          STD_OFF
#define ETHTSYN_ISDEF_PDREQSMOFPCCONFIG                                                             STD_OFF
#define ETHTSYN_ISDEF_PDREQTRCVDYNOFPCCONFIG                                                        STD_OFF
#define ETHTSYN_ISDEF_PDRESPSMDYNOFPCCONFIG                                                         STD_OFF
#define ETHTSYN_ISDEF_PDRESPSMOFPCCONFIG                                                            STD_OFF
#define ETHTSYN_ISDEF_PORTPARAMSTATSDYNOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_PORTSYNCSENDSMDYNOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_PORTSYNCSENDSMOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_RATEMEASBUFOFPCCONFIG                                                         STD_OFF
#define ETHTSYN_ISDEF_RATEMEASDYNOFPCCONFIG                                                         STD_OFF
#define ETHTSYN_ISDEF_RATEMEASOFPCCONFIG                                                            STD_OFF
#define ETHTSYN_ISDEF_SITESYNCSYNCTXDYNOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_SITESYNCSYNCTXOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_SIZEOFANNOUNCERCVSMOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_SIZEOFANNOUNCESENDSMOFPCCONFIG                                                STD_OFF
#define ETHTSYN_ISDEF_SIZEOFBRIDGETXMASTERPORTOFPCCONFIG                                            STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCOMCTRLETHIFCTRLOFPCCONFIG                                              STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCOMCTRLPHYSPORTOFPCCONFIG                                               STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCOMCTRLPORTINDOFPCCONFIG                                                STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCOMCTRLPORTOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCOMCTRLTIMEDOMAINOFPCCONFIG                                             STD_OFF
#define ETHTSYN_ISDEF_SIZEOFCRCHNDLOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_SIZEOFDESTINATIONMACINDOFPCCONFIG                                             STD_OFF
#define ETHTSYN_ISDEF_SIZEOFDESTINATIONMACOFPCCONFIG                                                STD_OFF
#define ETHTSYN_ISDEF_SIZEOFFUPDATAIDLISTOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_SIZEOFFUPRXHANDLEROFPCCONFIG                                                  STD_OFF
#define ETHTSYN_ISDEF_SIZEOFMSGSENTCBKBUFOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_SIZEOFOFFSETTIMEDOMAINOFPCCONFIG                                              STD_OFF
#define ETHTSYN_ISDEF_SIZEOFPDREQSMOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_SIZEOFPDRESPSMOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_SIZEOFPORTPARAMSTATSDYNOFPCCONFIG                                             STD_OFF
#define ETHTSYN_ISDEF_SIZEOFPORTSYNCSENDSMOFPCCONFIG                                                STD_OFF
#define ETHTSYN_ISDEF_SIZEOFRATEMEASBUFOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_SIZEOFRATEMEASOFPCCONFIG                                                      STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSITESYNCSYNCTXOFPCCONFIG                                                STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSLAVERXDATAHANDLEROFPCCONFIG                                            STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSLAVERXDATAOFPCCONFIG                                                   STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                       STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                  STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSLAVESWITCHIDXLISTOFPCCONFIG                                            STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSWTTIMESYNCSMOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSYNCRCVSMOFPCCONFIG                                                     STD_OFF
#define ETHTSYN_ISDEF_SIZEOFSYNCSENDSMOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_SIZEOFTIMEBASEUPDATECOUNTEROFPCCONFIG                                         STD_OFF
#define ETHTSYN_ISDEF_SIZEOFTXCONFCONTEXTOFPCCONFIG                                                 STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAHANDLEROFPCCONFIG                                                  STD_OFF
#define ETHTSYN_ISDEF_SLAVERXDATAOFPCCONFIG                                                         STD_OFF
#define ETHTSYN_ISDEF_SLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                             STD_OFF
#define ETHTSYN_ISDEF_SLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                        STD_OFF
#define ETHTSYN_ISDEF_SLAVESWITCHIDXLISTOFPCCONFIG                                                  STD_OFF
#define ETHTSYN_ISDEF_SWTTIMESYNCSMDYNOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_SWTTIMESYNCSMOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_SYNCRCVSMDYNOFPCCONFIG                                                        STD_OFF
#define ETHTSYN_ISDEF_SYNCRCVSMOFPCCONFIG                                                           STD_OFF
#define ETHTSYN_ISDEF_SYNCSENDSMDYNOFPCCONFIG                                                       STD_OFF
#define ETHTSYN_ISDEF_SYNCSENDSMOFPCCONFIG                                                          STD_OFF
#define ETHTSYN_ISDEF_TIMEBASEUPDATECOUNTERDYNOFPCCONFIG                                            STD_OFF
#define ETHTSYN_ISDEF_TIMEBASEUPDATECOUNTEROFPCCONFIG                                               STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTDYNACTIVEFIRSTIDXOFPCCONFIG                                      STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTDYNACTIVELASTIDXOFPCCONFIG                                       STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTDYNOFPCCONFIG                                                    STD_OFF
#define ETHTSYN_ISDEF_TXCONFCONTEXTOFPCCONFIG                                                       STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCEqualsAlwaysToDefines  EthTSyn Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFANNOUNCERCVSM                                                   
#define ETHTSYN_EQ2_MAXSTEPSREMOVEDOFANNOUNCERCVSM                                                  
#define ETHTSYN_EQ2_RXTIMEOUTOFANNOUNCERCVSM                                                        
#define ETHTSYN_EQ2_SLAVERXDATAIDXOFANNOUNCERCVSM                                                   
#define ETHTSYN_EQ2_ANNOUNCELOGMSGINTERVALOFANNOUNCESENDSM                                          
#define ETHTSYN_EQ2_ANNOUNCETXCYCLEOFANNOUNCESENDSM                                                 
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFANNOUNCESENDSM                                                  
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFBRIDGETXMASTERPORT                                              
#define ETHTSYN_EQ2_COMCTRLPORTINDENDIDXOFCOMCTRLETHIFCTRL                                          
#define ETHTSYN_EQ2_COMCTRLPORTINDSTARTIDXOFCOMCTRLETHIFCTRL                                        
#define ETHTSYN_EQ2_DESTINATIONMACINDENDIDXOFCOMCTRLETHIFCTRL                                       
#define ETHTSYN_EQ2_DESTINATIONMACINDSTARTIDXOFCOMCTRLETHIFCTRL                                     
#define ETHTSYN_EQ2_ETHIFCTRLIDXOFCOMCTRLETHIFCTRL                                                  
#define ETHTSYN_EQ2_ALWAYSASCAPABLEOFCOMCTRLPHYSPORT                                                
#define ETHTSYN_EQ2_DEBOUNCETIMERINITOFCOMCTRLPHYSPORT                                              
#define ETHTSYN_EQ2_INITIALPDELAYNSOFCOMCTRLPHYSPORT                                                
#define ETHTSYN_EQ2_USESTATICPDELAYOFCOMCTRLPHYSPORT                                                
#define ETHTSYN_EQ2_ANNOUNCESENDSMIDXOFCOMCTRLPORT                                                  
#define ETHTSYN_EQ2_ANNOUNCESENDSMUSEDOFCOMCTRLPORT                                                 
#define ETHTSYN_EQ2_COMCTRLETHIFCTRLIDXOFCOMCTRLPORT                                                
#define ETHTSYN_EQ2_COMCTRLPHYSPORTIDXOFCOMCTRLPORT                                                 
#define ETHTSYN_EQ2_COMCTRLTIMEDOMAINIDXOFCOMCTRLPORT                                               
#define ETHTSYN_EQ2_FRAMEPRIOOFCOMCTRLPORT                                                          
#define ETHTSYN_EQ2_NUMBEROFCOMCTRLPORT                                                             
#define ETHTSYN_EQ2_PDREQSMIDXOFCOMCTRLPORT                                                         
#define ETHTSYN_EQ2_PDREQSMUSEDOFCOMCTRLPORT                                                        
#define ETHTSYN_EQ2_PDRESPSMIDXOFCOMCTRLPORT                                                        
#define ETHTSYN_EQ2_PDRESPSMUSEDOFCOMCTRLPORT                                                       
#define ETHTSYN_EQ2_PORTPARAMSTATSDYNIDXOFCOMCTRLPORT                                               
#define ETHTSYN_EQ2_PORTPARAMSTATSDYNUSEDOFCOMCTRLPORT                                              
#define ETHTSYN_EQ2_PORTSYNCSENDSMIDXOFCOMCTRLPORT                                                  
#define ETHTSYN_EQ2_PORTSYNCSENDSMUSEDOFCOMCTRLPORT                                                 
#define ETHTSYN_EQ2_SLAVERXDATAHANDLERIDXOFCOMCTRLPORT                                              
#define ETHTSYN_EQ2_SLAVERXDATAHANDLERUSEDOFCOMCTRLPORT                                             
#define ETHTSYN_EQ2_SYNCSENDSMIDXOFCOMCTRLPORT                                                      
#define ETHTSYN_EQ2_SYNCSENDSMUSEDOFCOMCTRLPORT                                                     
#define ETHTSYN_EQ2_COMCTRLPORTIND                                                                  
#define ETHTSYN_EQ2_COMCTRLPORTENDIDXOFCOMCTRLTIMEDOMAIN                                            
#define ETHTSYN_EQ2_COMCTRLPORTSTARTIDXOFCOMCTRLTIMEDOMAIN                                          
#define ETHTSYN_EQ2_DESTINATIONMACIDXOFCOMCTRLTIMEDOMAIN                                            
#define ETHTSYN_EQ2_IDOFCOMCTRLTIMEDOMAIN                                                           
#define ETHTSYN_EQ2_OFFSETTIMEDOMAINENDIDXOFCOMCTRLTIMEDOMAIN                                       
#define ETHTSYN_EQ2_OFFSETTIMEDOMAINSTARTIDXOFCOMCTRLTIMEDOMAIN                                     
#define ETHTSYN_EQ2_OFFSETTIMEDOMAINUSEDOFCOMCTRLTIMEDOMAIN                                         
#define ETHTSYN_EQ2_SYNCHRONIZEDTIMEBASEIDOFCOMCTRLTIMEDOMAIN                                       
#define ETHTSYN_EQ2_FUPDATAIDLISTENDIDXOFCRCHNDL                                                    
#define ETHTSYN_EQ2_FUPDATAIDLISTSTARTIDXOFCRCHNDL                                                  
#define ETHTSYN_EQ2_BYTE0OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_BYTE1OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_BYTE2OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_BYTE3OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_BYTE4OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_BYTE5OFDESTINATIONMAC                                                           
#define ETHTSYN_EQ2_DESTINATIONMACIND                                                               
#define ETHTSYN_EQ2_FUPDATAIDLIST                                                                   
#define ETHTSYN_EQ2_COMCTRLPORTEXTERNALIDXOFFUPRXHANDLER                                            
#define ETHTSYN_EQ2_CRCFLAGSRXVALIDATEDOFFUPRXHANDLER                                               
#define ETHTSYN_EQ2_CRCHNDLIDXOFFUPRXHANDLER                                                        
#define ETHTSYN_EQ2_CRCHNDLUSEDOFFUPRXHANDLER                                                       
#define ETHTSYN_EQ2_FUPCORRFIELDTHRESHOLDNSOFFUPRXHANDLER                                           
#define ETHTSYN_EQ2_RXCRCVALIDATEDOFFUPRXHANDLER                                                    
#define ETHTSYN_EQ2_TIMEVALIDATIONENABLEDOFFUPRXHANDLER                                             
#define ETHTSYN_EQ2_IDOFOFFSETTIMEDOMAIN                                                            
#define ETHTSYN_EQ2_SYNCHRONIZEDTIMEBASEIDOFOFFSETTIMEDOMAIN                                        
#define ETHTSYN_EQ2_AVERAGEWEIGHTOFPDREQSM                                                          
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFPDREQSM                                                         
#define ETHTSYN_EQ2_LOGMSGINTERVALOFPDREQSM                                                         
#define ETHTSYN_EQ2_MAXLOSTRESPONSESOFPDREQSM                                                       
#define ETHTSYN_EQ2_PDREQPERIODOFPDREQSM                                                            
#define ETHTSYN_EQ2_PDRESPTIMEOUTOFPDREQSM                                                          
#define ETHTSYN_EQ2_PDTHRESHOLDOFPDREQSM                                                            
#define ETHTSYN_EQ2_TIMEVALIDATIONENABLEDOFPDREQSM                                                  
#define ETHTSYN_EQ2_TXCONFCONTEXTIDXOFPDREQSM                                                       
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFPDRESPSM                                                        
#define ETHTSYN_EQ2_TIMEVALIDATIONENABLEDOFPDRESPSM                                                 
#define ETHTSYN_EQ2_TXCONFCONTEXTIDXOFPDRESPSM                                                      
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFPORTSYNCSENDSM                                                  
#define ETHTSYN_EQ2_FOLLOWUPSENTCBKPTROFPORTSYNCSENDSM                                              
#define ETHTSYN_EQ2_MSGSENTCBKBUFENDIDXOFPORTSYNCSENDSM                                             
#define ETHTSYN_EQ2_MSGSENTCBKBUFLENGTHOFPORTSYNCSENDSM                                             
#define ETHTSYN_EQ2_MSGSENTCBKBUFSTARTIDXOFPORTSYNCSENDSM                                           
#define ETHTSYN_EQ2_MSGSENTCBKBUFUSEDOFPORTSYNCSENDSM                                               
#define ETHTSYN_EQ2_SYNCSENTCBKPTROFPORTSYNCSENDSM                                                  
#define ETHTSYN_EQ2_TIMEVALIDATIONENABLEDOFPORTSYNCSENDSM                                           
#define ETHTSYN_EQ2_TXCONFCONTEXTIDXOFPORTSYNCSENDSM                                                
#define ETHTSYN_EQ2_MAXOUTOFSYNCCNTOFRATEMEAS                                                       
#define ETHTSYN_EQ2_NRSYNCCYCLESFOROFSCORROFRATEMEAS                                                
#define ETHTSYN_EQ2_OFSJUMPCORRTHRESHOLDNSOFRATEMEAS                                                
#define ETHTSYN_EQ2_RATEMEASBUFENDIDXOFRATEMEAS                                                     
#define ETHTSYN_EQ2_RATEMEASBUFLENGTHOFRATEMEAS                                                     
#define ETHTSYN_EQ2_RATEMEASBUFSTARTIDXOFRATEMEAS                                                   
#define ETHTSYN_EQ2_RATERATIOMAXOFRATEMEAS                                                          
#define ETHTSYN_EQ2_RATERATIOMINOFRATEMEAS                                                          
#define ETHTSYN_EQ2_SYNCPRECISIONLIMITNSOFRATEMEAS                                                  
#define ETHTSYN_EQ2_USEINITIALOFFSETCORRECTIONOFRATEMEAS                                            
#define ETHTSYN_EQ2_BRIDGETXMASTERPORTENDIDXOFSITESYNCSYNCTX                                        
#define ETHTSYN_EQ2_BRIDGETXMASTERPORTSTARTIDXOFSITESYNCSYNCTX                                      
#define ETHTSYN_EQ2_NUMMSGFWDRETRYOFSITESYNCSYNCTX                                                  
#define ETHTSYN_EQ2_ANNOUNCERCVSMIDXOFSLAVERXDATA                                                   
#define ETHTSYN_EQ2_ANNOUNCERCVSMUSEDOFSLAVERXDATA                                                  
#define ETHTSYN_EQ2_SLAVERXMASTERCLOCKIDDYNIDXOFSLAVERXDATA                                         
#define ETHTSYN_EQ2_SLAVERXMASTERCLOCKIDDYNUSEDOFSLAVERXDATA                                        
#define ETHTSYN_EQ2_SLAVERXSRCPORTIDCHECKCLOCKIDIDXOFSLAVERXDATA                                    
#define ETHTSYN_EQ2_SLAVERXSRCPORTIDCHECKCLOCKIDUSEDOFSLAVERXDATA                                   
#define ETHTSYN_EQ2_SYNCRCVSMIDXOFSLAVERXDATA                                                       
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFSLAVERXDATAHANDLER                                              
#define ETHTSYN_EQ2_SLAVERXDATAEXTERNALIDXOFSLAVERXDATAHANDLER                                      
#define ETHTSYN_EQ2_SLAVERXSRCPORTIDCHECKCLOCKID                                                    
#define ETHTSYN_EQ2_SLAVESWITCHIDXLIST                                                              
#define ETHTSYN_EQ2_APPLYRATERATIOTOSLAVESWITCHESOFSWTTIMESYNCSM                                    
#define ETHTSYN_EQ2_ETHIFSWITCHIDXOFSWTTIMESYNCSM                                                   
#define ETHTSYN_EQ2_RATEMEASIDXOFSWTTIMESYNCSM                                                      
#define ETHTSYN_EQ2_SLAVESWITCHIDXLISTENDIDXOFSWTTIMESYNCSM                                         
#define ETHTSYN_EQ2_SLAVESWITCHIDXLISTSTARTIDXOFSWTTIMESYNCSM                                       
#define ETHTSYN_EQ2_SLAVESWITCHIDXLISTUSEDOFSWTTIMESYNCSM                                           
#define ETHTSYN_EQ2_SWTSYNCSTATECHGFCTPTROFSWTTIMESYNCSM                                            
#define ETHTSYN_EQ2_SYNCEVENTTIMEOUTOFSWTTIMESYNCSM                                                 
#define ETHTSYN_EQ2_FOLLOWUPRXTIMEOUTOFSYNCRCVSM                                                    
#define ETHTSYN_EQ2_FUPRXHANDLERIDXOFSYNCRCVSM                                                      
#define ETHTSYN_EQ2_PORTPARAMSTATSDYNIDXOFSYNCRCVSM                                                 
#define ETHTSYN_EQ2_PORTPARAMSTATSDYNUSEDOFSYNCRCVSM                                                
#define ETHTSYN_EQ2_CRCHNDLIDXOFSYNCSENDSM                                                          
#define ETHTSYN_EQ2_CRCHNDLUSEDOFSYNCSENDSM                                                         
#define ETHTSYN_EQ2_CRCTIMEFLAGSOFSYNCSENDSM                                                        
#define ETHTSYN_EQ2_CYCLICMSGRESUMECNTOFSYNCSENDSM                                                  
#define ETHTSYN_EQ2_FUPTXLENOFSYNCSENDSM                                                            
#define ETHTSYN_EQ2_IMMEDIATETIMESYNCOFSYNCSENDSM                                                   
#define ETHTSYN_EQ2_PORTSYNCSENDSMIDXOFSYNCSENDSM                                                   
#define ETHTSYN_EQ2_SYNCLOGMSGINTERVALOFSYNCSENDSM                                                  
#define ETHTSYN_EQ2_SYNCSENDINTERVALOFSYNCSENDSM                                                    
#define ETHTSYN_EQ2_TIMEBASEUPDATECOUNTERIDXOFSYNCSENDSM                                            
#define ETHTSYN_EQ2_TIMEBASEUPDATECOUNTERUSEDOFSYNCSENDSM                                           
#define ETHTSYN_EQ2_TXCRCSECUREDOFSYNCSENDSM                                                        
#define ETHTSYN_EQ2_SYNCHRONIZEDTIMEBASEIDOFTIMEBASEUPDATECOUNTER                                   
#define ETHTSYN_EQ2_COMCTRLPORTIDXOFTXCONFCONTEXT                                                   
#define ETHTSYN_EQ2_TXSMIDXOFTXCONFCONTEXT                                                          
#define ETHTSYN_EQ2_TXSMOFTXCONFCONTEXT                                                             
#define ETHTSYN_EQ2_ANNOUNCERCVSMDYNOFPCCONFIG                                                      
#define ETHTSYN_EQ2_ANNOUNCERCVSMOFPCCONFIG                                                         
#define ETHTSYN_EQ2_ANNOUNCESENDSMDYNOFPCCONFIG                                                     
#define ETHTSYN_EQ2_ANNOUNCESENDSMOFPCCONFIG                                                        
#define ETHTSYN_EQ2_BRIDGETXMASTERPORTDYNOFPCCONFIG                                                 
#define ETHTSYN_EQ2_BRIDGETXMASTERPORTOFPCCONFIG                                                    
#define ETHTSYN_EQ2_COMCTRLETHIFCTRLDYNOFPCCONFIG                                                   
#define ETHTSYN_EQ2_COMCTRLETHIFCTRLOFPCCONFIG                                                      
#define ETHTSYN_EQ2_COMCTRLPHYSPORTDYNOFPCCONFIG                                                    
#define ETHTSYN_EQ2_COMCTRLPHYSPORTOFPCCONFIG                                                       
#define ETHTSYN_EQ2_COMCTRLPORTINDOFPCCONFIG                                                        
#define ETHTSYN_EQ2_COMCTRLPORTOFPCCONFIG                                                           
#define ETHTSYN_EQ2_COMCTRLTIMEDOMAINOFPCCONFIG                                                     
#define ETHTSYN_EQ2_CRCHNDLOFPCCONFIG                                                               
#define ETHTSYN_EQ2_DESTINATIONMACINDOFPCCONFIG                                                     
#define ETHTSYN_EQ2_DESTINATIONMACOFPCCONFIG                                                        
#define ETHTSYN_EQ2_FUPDATAIDLISTOFPCCONFIG                                                         
#define ETHTSYN_EQ2_FUPRXHANDLEROFPCCONFIG                                                          
#define ETHTSYN_EQ2_MSGSENTCBKBUFOFPCCONFIG                                                         
#define ETHTSYN_EQ2_OFFSETTIMEDOMAINOFPCCONFIG                                                      
#define ETHTSYN_EQ2_PDREQSMDYNOFPCCONFIG                                                            
#define ETHTSYN_EQ2_PDREQSMOFPCCONFIG                                                               
#define ETHTSYN_EQ2_PDREQTRCVDYNOFPCCONFIG                                                          
#define ETHTSYN_EQ2_PDRESPSMDYNOFPCCONFIG                                                           
#define ETHTSYN_EQ2_PDRESPSMOFPCCONFIG                                                              
#define ETHTSYN_EQ2_PORTPARAMSTATSDYNOFPCCONFIG                                                     
#define ETHTSYN_EQ2_PORTSYNCSENDSMDYNOFPCCONFIG                                                     
#define ETHTSYN_EQ2_PORTSYNCSENDSMOFPCCONFIG                                                        
#define ETHTSYN_EQ2_RATEMEASBUFOFPCCONFIG                                                           
#define ETHTSYN_EQ2_RATEMEASDYNOFPCCONFIG                                                           
#define ETHTSYN_EQ2_RATEMEASOFPCCONFIG                                                              
#define ETHTSYN_EQ2_SITESYNCSYNCTXDYNOFPCCONFIG                                                     
#define ETHTSYN_EQ2_SITESYNCSYNCTXOFPCCONFIG                                                        
#define ETHTSYN_EQ2_SIZEOFANNOUNCERCVSMOFPCCONFIG                                                   
#define ETHTSYN_EQ2_SIZEOFANNOUNCESENDSMOFPCCONFIG                                                  
#define ETHTSYN_EQ2_SIZEOFBRIDGETXMASTERPORTOFPCCONFIG                                              
#define ETHTSYN_EQ2_SIZEOFCOMCTRLETHIFCTRLOFPCCONFIG                                                
#define ETHTSYN_EQ2_SIZEOFCOMCTRLPHYSPORTOFPCCONFIG                                                 
#define ETHTSYN_EQ2_SIZEOFCOMCTRLPORTINDOFPCCONFIG                                                  
#define ETHTSYN_EQ2_SIZEOFCOMCTRLPORTOFPCCONFIG                                                     
#define ETHTSYN_EQ2_SIZEOFCOMCTRLTIMEDOMAINOFPCCONFIG                                               
#define ETHTSYN_EQ2_SIZEOFCRCHNDLOFPCCONFIG                                                         
#define ETHTSYN_EQ2_SIZEOFDESTINATIONMACINDOFPCCONFIG                                               
#define ETHTSYN_EQ2_SIZEOFDESTINATIONMACOFPCCONFIG                                                  
#define ETHTSYN_EQ2_SIZEOFFUPDATAIDLISTOFPCCONFIG                                                   
#define ETHTSYN_EQ2_SIZEOFFUPRXHANDLEROFPCCONFIG                                                    
#define ETHTSYN_EQ2_SIZEOFMSGSENTCBKBUFOFPCCONFIG                                                   
#define ETHTSYN_EQ2_SIZEOFOFFSETTIMEDOMAINOFPCCONFIG                                                
#define ETHTSYN_EQ2_SIZEOFPDREQSMOFPCCONFIG                                                         
#define ETHTSYN_EQ2_SIZEOFPDRESPSMOFPCCONFIG                                                        
#define ETHTSYN_EQ2_SIZEOFPORTPARAMSTATSDYNOFPCCONFIG                                               
#define ETHTSYN_EQ2_SIZEOFPORTSYNCSENDSMOFPCCONFIG                                                  
#define ETHTSYN_EQ2_SIZEOFRATEMEASBUFOFPCCONFIG                                                     
#define ETHTSYN_EQ2_SIZEOFRATEMEASOFPCCONFIG                                                        
#define ETHTSYN_EQ2_SIZEOFSITESYNCSYNCTXOFPCCONFIG                                                  
#define ETHTSYN_EQ2_SIZEOFSLAVERXDATAHANDLEROFPCCONFIG                                              
#define ETHTSYN_EQ2_SIZEOFSLAVERXDATAOFPCCONFIG                                                     
#define ETHTSYN_EQ2_SIZEOFSLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                         
#define ETHTSYN_EQ2_SIZEOFSLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                    
#define ETHTSYN_EQ2_SIZEOFSLAVESWITCHIDXLISTOFPCCONFIG                                              
#define ETHTSYN_EQ2_SIZEOFSWTTIMESYNCSMOFPCCONFIG                                                   
#define ETHTSYN_EQ2_SIZEOFSYNCRCVSMOFPCCONFIG                                                       
#define ETHTSYN_EQ2_SIZEOFSYNCSENDSMOFPCCONFIG                                                      
#define ETHTSYN_EQ2_SIZEOFTIMEBASEUPDATECOUNTEROFPCCONFIG                                           
#define ETHTSYN_EQ2_SIZEOFTXCONFCONTEXTOFPCCONFIG                                                   
#define ETHTSYN_EQ2_SLAVERXDATAHANDLEROFPCCONFIG                                                    
#define ETHTSYN_EQ2_SLAVERXDATAOFPCCONFIG                                                           
#define ETHTSYN_EQ2_SLAVERXMASTERCLOCKIDDYNOFPCCONFIG                                               
#define ETHTSYN_EQ2_SLAVERXSRCPORTIDCHECKCLOCKIDOFPCCONFIG                                          
#define ETHTSYN_EQ2_SLAVESWITCHIDXLISTOFPCCONFIG                                                    
#define ETHTSYN_EQ2_SWTTIMESYNCSMDYNOFPCCONFIG                                                      
#define ETHTSYN_EQ2_SWTTIMESYNCSMOFPCCONFIG                                                         
#define ETHTSYN_EQ2_SYNCRCVSMDYNOFPCCONFIG                                                          
#define ETHTSYN_EQ2_SYNCRCVSMOFPCCONFIG                                                             
#define ETHTSYN_EQ2_SYNCSENDSMDYNOFPCCONFIG                                                         
#define ETHTSYN_EQ2_SYNCSENDSMOFPCCONFIG                                                            
#define ETHTSYN_EQ2_TIMEBASEUPDATECOUNTERDYNOFPCCONFIG                                              
#define ETHTSYN_EQ2_TIMEBASEUPDATECOUNTEROFPCCONFIG                                                 
#define ETHTSYN_EQ2_TXCONFCONTEXTDYNACTIVEFIRSTIDXOFPCCONFIG                                        
#define ETHTSYN_EQ2_TXCONFCONTEXTDYNACTIVELASTIDXOFPCCONFIG                                         
#define ETHTSYN_EQ2_TXCONFCONTEXTDYNOFPCCONFIG                                                      
#define ETHTSYN_EQ2_TXCONFCONTEXTOFPCCONFIG                                                         
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCSymbolicInitializationPointers  EthTSyn Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define EthTSyn_Config_Ptr                                                                          &(EthTSyn_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'EthTSyn' */
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCInitializationSymbols  EthTSyn Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define EthTSyn_Config                                                                              EthTSyn_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'EthTSyn */
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCGeneral  EthTSyn General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ETHTSYN_CHECK_INIT_POINTER                                                                  STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ETHTSYN_FINAL_MAGIC_NUMBER                                                                  0xA41Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of EthTSyn */
#define ETHTSYN_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'EthTSyn' is not configured to be postbuild capable. */
#define ETHTSYN_INIT_DATA                                                                           ETHTSYN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ETHTSYN_INIT_DATA_HASH_CODE                                                                 -576772822  /**< the precompile constant to validate the initialization structure at initialization time of EthTSyn with a hashcode. The seed value is '0xA41Eu' */
#define ETHTSYN_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ETHTSYN_USE_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer EthTSyn shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - START
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - END
 *********************************************************************************************************************/

#endif /* ETHTSYN_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_Cfg.h
 *********************************************************************************************************************/

