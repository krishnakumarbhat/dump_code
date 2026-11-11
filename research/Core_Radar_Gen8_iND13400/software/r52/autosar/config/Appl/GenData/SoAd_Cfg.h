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
 *            Module: SoAd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SoAd_Cfg.h
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] SOAD01500 - BSW Module configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Xcp only supports /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) set to true. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) (DefRef: /MICROSAR/SoAd/SoAdBswModules/SoAdIfTxConfirmation)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#if !defined(SOAD_CFG_H)
#define SOAD_CFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (EXTERNAL USE): SOCKET CONNECTION
 *********************************************************************************************************************/



/**
 * \defgroup SoAdHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SoAdConf_SoAdSocketConnection_ConnectionBundle2_14f4c9c7      0u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_ConnectionBundle4_81a0ef65      1u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_ConnectionBundle_ADAS_53ce198e  2u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_ConnectionBundle_RDR_1_94fef815 3u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_ConnectionBundle_RDR_1_94fef815_001 4u  /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_SoAdSocketConnection_HIL_Rx     7u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_SoAdSocketConnection_HIL_Tx     6u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_SoAdSocketConnection_Veh_Rx_001 5u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketConnection_SoAdSocketConnection_XCP        8u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (EXTERNAL USE): PDU ROUTE PDU
 *********************************************************************************************************************/



/**
 * \defgroup SoAdHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SoAdConf_SoAdPduRoute_GenerelPurposePDU3_a3a5c5ac_Tx          0u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_RDR_ETH_XCP_TX                          1u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_RDR_HIL_TX                              4u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_RDR_LOGGING_TX                          2u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_RDR_LOGGING_TX_FAST                     3u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_signalPdu_RDR_1_Detections_Transport_d322aa23_Tx 5u /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_signalPdu_RDR_1_SW_Info_14232baa_Tx     6u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdPduRoute_signalPdu_RDR_1_Status_67c6fd21_Tx      7u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (EXTERNAL USE): SOCKET ROUTE PDU
 *********************************************************************************************************************/



/**
 * \defgroup SoAdHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SoAdConf_SoAdSocketRouteDest_ConnectionBundle2_5528fe66       0u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketRouteDest_ConnectionBundle4_f5688455       1u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketRouteDest_ConnectionBundle_ADAS_f656ca1d   2u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketRouteDest_SoAdSocketRouteDest_HIL          3u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketRouteDest_SoAdSocketRouteDest_Veh_UDP_Rx   4u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdSocketRouteDest_SoAdSocketRouteDest_XCP_RX_Eth   5u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (EXTERNAL USE): ROUTING GROUP
 *********************************************************************************************************************/



/**
 * \defgroup SoAdHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup                    0u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup1_27560e95          1u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup2_be5f5f2f          2u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup3_c9586fb9          3u      /**< [PostBuildInvariantValuesModelView] */
#define SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup4_573cfa1a          4u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#define SOAD_VERSION_INFO_API                   STD_OFF
#define SOAD_DEV_ERROR_REPORT                   STD_ON
#define SOAD_DEV_ERROR_DETECT                   STD_ON
#define SOAD_RUNTIME_ERROR_REPORT               STD_ON
#define SOAD_MAIN_FCT_CYCLE_TIME_MS             5u
#define SOAD_GET_RESET_MEASUREMENT_DATA_API     STD_OFF
#define SOAD_SECURITY_EVENT_REPORTING           STD_OFF
#define SOAD_BMC_USAGE_ENABLED                  STD_OFF
#define SOAD_MAX_PDU_LENGTH                     SOAD_UINT8OR16
#define SOAD_MODE_CHG_QUEUE_ENABLED             STD_OFF
#define SOAD_RST_FOR_FORCE_RELEASE_ENABLED      STD_ON

/**********************************************************************************************************************
 *  MODULE SPECIFIC DEFINES
 *********************************************************************************************************************/
#ifndef SOAD_USE_DUMMY_STATEMENT
#define SOAD_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOAD_DUMMY_STATEMENT
#define SOAD_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOAD_DUMMY_STATEMENT_CONST
#define SOAD_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOAD_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SOAD_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SOAD_ATOMIC_VARIABLE_ACCESS
#define SOAD_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SOAD_PROCESSOR_IND13400
#define SOAD_PROCESSOR_IND13400
#endif
#ifndef SOAD_COMP_LLVMDIAB
#define SOAD_COMP_LLVMDIAB
#endif
#ifndef SOAD_GEN_GENERATOR_MSR
#define SOAD_GEN_GENERATOR_MSR
#endif
#ifndef SOAD_CPUTYPE_BITORDER_LSB2MSB
#define SOAD_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SOAD_CONFIGURATION_VARIANT_PRECOMPILE
#define SOAD_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SOAD_CONFIGURATION_VARIANT_LINKTIME
#define SOAD_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SOAD_CONFIGURATION_VARIANT
#define SOAD_CONFIGURATION_VARIANT SOAD_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SOAD_POSTBUILD_VARIANT_SUPPORT
#define SOAD_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define SOAD_SINGLE_MAIN_FUNCTION               STD_ON
#define SOAD_TX_DYN_LEN                         STD_OFF
#define SOAD_IPV6                               STD_OFF
#define SOAD_TCP                                STD_OFF
#define SOAD_DHCPV4_CLIENT_ENABLED              STD_OFF
#define SOAD_DHCPV6_CLIENT_ENABLED              STD_OFF
#define SOAD_MULTI_INSTANCE                     STD_OFF
#define SOAD_MULTI_PARTITION                    STD_OFF
#define SOAD_SD_UL_ENABLED                      STD_ON

#define SOAD_SHUTDOWN_FINISHED_WAIT             400u
#define SOAD_N_PDU_UDP_TX_QUEUE_RETRY_CNT_MAIN  300u
#define SOAD_MAX_PDU_LEN                        0x0000FFFFu
#define SOAD_MAX_UDP_PDU_LEN                    0xFFFFu

/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - START
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - END
 *********************************************************************************************************************/

#endif /* SOAD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Cfg.h
 *********************************************************************************************************************/

