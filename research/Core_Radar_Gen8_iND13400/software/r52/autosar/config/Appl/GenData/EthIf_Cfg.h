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
 *              File: EthIf_Cfg.h
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

#if !defined (ETHIF_CFG_H)
# define ETHIF_CFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETHIF_USE_DUMMY_STATEMENT
#define ETHIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHIF_DUMMY_STATEMENT
#define ETHIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHIF_DUMMY_STATEMENT_CONST
#define ETHIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETHIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETHIF_ATOMIC_VARIABLE_ACCESS
#define ETHIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETHIF_PROCESSOR_IND13400
#define ETHIF_PROCESSOR_IND13400
#endif
#ifndef ETHIF_COMP_LLVMDIAB
#define ETHIF_COMP_LLVMDIAB
#endif
#ifndef ETHIF_GEN_GENERATOR_MSR
#define ETHIF_GEN_GENERATOR_MSR
#endif
#ifndef ETHIF_CPUTYPE_BITORDER_LSB2MSB
#define ETHIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETHIF_CONFIGURATION_VARIANT_PRECOMPILE
#define ETHIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETHIF_CONFIGURATION_VARIANT_LINKTIME
#define ETHIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETHIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETHIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETHIF_CONFIGURATION_VARIANT
#define ETHIF_CONFIGURATION_VARIANT ETHIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETHIF_POSTBUILD_VARIANT_SUPPORT
#define ETHIF_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfControllers
 *********************************************************************************************************************/
#define EthIfConf_EthIfController_cnctr_RDR_RdrNet_5172a59b (0u)

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfPhysControllers
 *********************************************************************************************************************/
#define EthIfConf_EthIfPhysController_EthIf_RADAR_EthConnector1_Controller_bbe781c0 (0u)

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfClkUnits
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfSwitchs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfSwitchPortGroups
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfFrameOwnerConfigs
 *********************************************************************************************************************/
#define EthIfConf_EthIfFrameOwnerConfig_TcpIp_IPv4 (0u)
#define EthIfConf_EthIfFrameOwnerConfig_TcpIp_ARP (1u)
#define EthIfConf_EthIfFrameOwnerConfig_EthTSyn_PTP (2u)

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfFrameRxPdus
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfFrameTxPdus
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfTxQueueProcMainFunction
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of EthIfRxQueueProcMainFunction
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES of Autosar Version Information
 *********************************************************************************************************************/
# define ETHIF_AR_4_1_1                            (0u)
# define ETHIF_AR_4_3_0                            (1u)
# define ETHIF_AR_23_11                            (2u)

/**********************************************************************************************************************
 *  BASIC CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_AUTOSAR_CALLBACK_SIGNATURE_VERSION     ETHIF_AR_4_3_0
# define ETHIF_DEV_ERROR_DETECT                       (STD_ON)
# define ETHIF_DEV_ERROR_REPORT                       (STD_ON)
# define ETHIF_VERSION_INFO_API                       (STD_OFF)

/**********************************************************************************************************************
 *  API FEATURE CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ENABLE_HEADER_ACCESS_API               (STD_OFF)
# define ETHIF_ENABLE_MACSEC_API                      (STD_OFF)
# define ETHIF_ENABLE_MAIN_FUNCTION_STATE             (STD_OFF)
# define ETHIF_ENABLE_SIGNAL_QUALITY_API              (STD_OFF)
# define ETHIF_ENABLE_UPDATE_PHYS_ADDR_FILTER         (STD_ON)
# define ETHIF_MEASUREMENT_DATA_SUPPORT               (STD_OFF)
# define ETHIF_SIGNAL_QUALITY_CHECK_PERIOD            (STD_OFF)

/**********************************************************************************************************************
 *  ETHERNET SWITCH CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ENABLE_GET_PORT_MAC_ADDR_VLAN_API      (STD_OFF)
# define ETHIF_ETHSWT_FRAME_MANAGEMENT_SUPPORT        (STD_OFF)
# define ETHIF_ETHSWT_TIME_STAMP_SUPPORT              (STD_OFF)
# define ETHIF_ETHSWT_USED                            (STD_OFF)
# define ETHIF_GET_ARL_TABLE_API                      (STD_OFF)
# define ETHIF_GET_BUFFER_LEVEL_API                   (STD_OFF)
# define ETHIF_GET_DROP_COUNT_API                     (STD_OFF)
# define ETHIF_GET_PORT_MAC_ADDR_API                  (STD_OFF)
# define ETHIF_RESET_CONFIG_API                       (STD_OFF)
# define ETHIF_STORE_CONFIG_API                       (STD_OFF)
# define ETHIF_SWITCH_ENABLE_VLAN_API                 (STD_OFF)
# define ETHIF_SWITCH_UPDATE_MCAST_PORT_ASSIGN_API    (STD_OFF)
# define ETHIF_SWT_PORT_GROUP_MODE_REQ_SUPPORT        (STD_OFF)

/**********************************************************************************************************************
 *  ETHERNET TRANSCEIVER CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ETHTRANSCEIVER_CONFIGURED              (STD_ON)
# define ETHIF_ETHTRCV_USED                           (STD_ON)

/**********************************************************************************************************************
 *  FIREWALL SUPPORT CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_FIREWALL_SUPPORT                       (STD_OFF)

/**********************************************************************************************************************
 *  INTERRUPT AND COMMUNICATION CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ENABLE_RX_INTERRUPT                    (STD_ON)
# define ETHIF_ENABLE_TX_INTERRUPT                    (STD_ON)
# define ETHIF_RXPDU_HANDLING_SUPPORT                 (STD_OFF)
# define ETHIF_TXPDU_HANDLING_SUPPORT                 (STD_OFF)
# define ETHIF_TXPDU_INDIRECT_DATA_PROVISION_SUPPORT  (STD_OFF)

/**********************************************************************************************************************
 *  LEGACY WAKEUP CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_LEGACY_WAKEUP_SUPPORT                  (STD_OFF)

/**********************************************************************************************************************
 *  MODE HANDLING CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ASYNC_MODE_HANDLING_SUPPORT            (STD_OFF)

/**********************************************************************************************************************
 *  MULTI-CORE AND BSW SPLIT CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_BSWSPLIT_RX_POLLING_SUPPORT            (STD_OFF)
# define ETHIF_BSWSPLIT_TX_POLLING_SUPPORT            (STD_OFF)
# define ETHIF_MULTI_CORE_SUPPORT                     (STD_OFF)
# define ETHIF_MULTI_PARTITION_SUPPORT                (STD_OFF)

/**********************************************************************************************************************
 *  SECURITY EVENT REPORTING CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ENABLE_SECURITY_EVENT_REPORTING        (STD_OFF)
# define ETHIF_SEV_INVALID                            (0xFFFFu)
# define ETHIF_SEV_DROPPED_INVALID_CTRLIDX_DATAGRAM   ETHIF_SEV_INVALID
# define ETHIF_SEV_DROPPED_UNKNOWN_ETHERTYPE_DATAGRAM ETHIF_SEV_INVALID
# define ETHIF_SEV_DROPPED_VLAN_DOUBLE_TAG_DATAGRAM   ETHIF_SEV_INVALID
# define ETHIF_SEV_ETH_MAC_COLLISION                  ETHIF_SEV_INVALID

/**********************************************************************************************************************
 *  TIME STAMPING CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_GLOBAL_TIME_SUPPORT                    (STD_ON)
# define ETHIF_PHC_SUPPORT                            (STD_OFF)

/**********************************************************************************************************************
 *  TRAFFIC HANDLING CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_DYNAMIC_TRAFFIC_SHAPING_SUPPORT        (STD_OFF)
# define ETHIF_EXTENDED_TRAFFIC_HANDLING_TYPE         ETHIF_NO_EXTENDED_TRAFFIC_HANDLING

/**********************************************************************************************************************
 *  WAKEUP ON DATA LINE CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ETHSM_SLEEPINDICATION_SUPPORT          (STD_OFF)
# define ETHIF_ETHTRCV_GET_PHY_WAKEUP_REASON_API      (STD_OFF)
# define ETHIF_ETHTRCV_GET_SWT_PORT_WAKEUP_REASON_API (STD_OFF)
# define ETHIF_ETHTRCV_SLAVE_PASSIVE                  (STD_OFF)
# define ETHIF_WAKEUP_SOURCES_MASK                    ((0u))
# define ETHIF_WAKEUP_SUPPORT                         (STD_OFF)

/**********************************************************************************************************************
 *  ZERO COPY CONFIGURATION
 *********************************************************************************************************************/
# define ETHIF_ENABLE_ZERO_COPY_EXTENSIONS            (STD_OFF)


#endif /* ETHIF_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_Cfg.h
 *********************************************************************************************************************/


