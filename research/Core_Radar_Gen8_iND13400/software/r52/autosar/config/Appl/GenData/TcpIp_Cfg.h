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
 *            Module: TcpIp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: TcpIp_Cfg.h
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
#if !defined(TCPIP_CFG_H)
#define TCPIP_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TCPIP SWITCH DEFINES
 *********************************************************************************************************************/
#define TCPIP_VERSION_INFO_API                     STD_OFF
#define TCPIP_DEV_ERROR_DETECT                     STD_ON
#define TCPIP_DEV_ERROR_REPORT                     STD_ON

#define TCPIP_SUPPORT_DHCPV4                       STD_OFF

#define TCPIP_SUPPORT_DHCPV6                       STD_OFF
#define TCPIP_SUPPORT_DHCPV6_OPTIONS               STD_OFF

#define TCPIP_SUPPORT_TCP                          STD_OFF
#define TCPIP_SUPPORT_DNS                          STD_OFF
#define TCPIP_SUPPORT_DEM                          STD_OFF
#define TCPIP_SUPPORT_IPV4                         STD_ON
#define TCPIP_SUPPORT_IPV6                         STD_OFF
#define TCPIP_SUPPORT_SOAD                         STD_ON
#define TCPIP_SUPPORT_ICMPV4                       STD_OFF
#define TCPIP_SUPPORT_DHCPV4SERVER                 STD_OFF
#define TCPIP_SUPPORT_DIAG_ACCESS_EXTENSIONS       STD_OFF
#define TCPIP_SUPPORT_MEASUREMENT_DATA             STD_OFF
#define TCPIP_SUPPORT_SECURITY_EVENT_REPORTING     STD_OFF
#define TCPIP_SUPPORT_IPSEC                        STD_OFF

#define TCPIP_SUPPORT_ASRTLS                       STD_OFF
#define TCPIP_SUPPORT_ASRTLS_VERSION_1_2           STD_OFF
#define TCPIP_SUPPORT_ASRTLS_VERSION_1_3           STD_OFF
#define TCPIP_SUPPORT_ASRTLSSERVER                 STD_OFF
#define TCPIP_SUPPORT_ASRTLSSERVER_PSK             STD_OFF
#define TCPIP_SUPPORT_ASRTLSCLIENT                 STD_OFF
#define TCPIP_SUPPORT_ASRTLSCLIENT_PSK             STD_OFF
#define TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS  STD_OFF
#define TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS         STD_OFF
#define TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME     STD_OFF
#define TCPIP_SUPPORT_ASRTLS_ECC                   STD_OFF
#define TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION      STD_OFF /* Specifies if the TLS connection should trigger the Error Indication callout function. */

#define TCPIP_SINGLE_MAIN_FUNCTION_ENABLED         STD_ON

#define TCPIP_MULTICORE_SUPPORT_ENABLED            STD_OFF


#define TCPIP_SUPPORT_IP_ETHIF_ADDR_FILTER_API     STD_ON
#define TCPIP_SUPPORT_IP_ADDR_NVM_STORAGE          STD_OFF

#define TCPIP_SUPPORT_ICMPV4_DST_UNREACHABLE_MSG   STD_OFF
#define TCPIP_SUPPORT_ICMPV4_ECHO_REPLY            STD_OFF

#define TCPIP_SUPPORT_ARP_DISCARDED_ENTRY_HANDLING STD_OFF



#define TCPIP_TCP_DIAG_READ_ACK_SEQ_NUM_ENABLED    STD_OFF


#define TCPIP_TLS_CONNECTION_COUNT                 0u

#define TCPIP_MAIN_FCT_PERIOD_MSEC                 5u




/**********************************************************************************************************************
  GLOBAL DATA TYPES - SIMPLE
**********************************************************************************************************************/
/* Dynamic datatype, can be UInt8 or Uint16, based on the total amount  of UDP and TCP sockets. For internal usages, 4 sockets are reserved. */
typedef uint8  TcpIp_SocketIdType; /* UInt8, total number of UDP and TCP sockets is less than 250.*/
# define TCPIP_SOCKETID_INVALID     0xFFU
# define TCPIP_INV_SOCK_HND         (TCPIP_SOCKETID_INVALID) /* For legacy usage */
# define TCPIP_INV_SOCKET_ID        (TCPIP_SOCKETID_INVALID) /* For legacy usage */
typedef TcpIp_SocketIdType TcpIp_SockHndType;

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (SNV)
 *********************************************************************************************************************/



/**
 * \defgroup TcpIpHandleIdsLocalAddr Handle IDs of handle space LocalAddr.
 * \brief Parameter: TcpIpAddrId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define TcpIpConf_TcpIpLocalAddr_NEP_ADAS_RdrNet_CtrlRxMulticast_91909614 1u  /**< [PostBuildInvariantValuesModelView] */
#define TcpIpConf_TcpIpLocalAddr_NEP_ANY_IP_c7cdbb5a                  2u      /**< [PostBuildInvariantValuesModelView] */
#define TcpIpConf_TcpIpLocalAddr_NEP_SRR_1_RdrNet_Unicast_48476027    0u      /**< [PostBuildInvariantValuesModelView] */
#define TcpIpConf_TcpIpLocalAddr_TcpIpV4LocalAddr_RDR_EthConnector1_fbdc15b4_Broadcast 3u /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup TcpIpHandleIdsSocketOwner Handle IDs of handle space SocketOwner.
 * \brief Parameter: TcpIpSocketOwnerId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define TcpIpConf_TcpIpSocketOwner_SoAd                               0u      /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**********************************************************************************************************************
 *  MODULE SPECIFIC DEFINES
 *********************************************************************************************************************/
#ifndef TCPIP_USE_DUMMY_STATEMENT
#define TCPIP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_DUMMY_STATEMENT
#define TCPIP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_DUMMY_STATEMENT_CONST
#define TCPIP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define TCPIP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef TCPIP_ATOMIC_VARIABLE_ACCESS
#define TCPIP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef TCPIP_PROCESSOR_IND13400
#define TCPIP_PROCESSOR_IND13400
#endif
#ifndef TCPIP_COMP_LLVMDIAB
#define TCPIP_COMP_LLVMDIAB
#endif
#ifndef TCPIP_GEN_GENERATOR_MSR
#define TCPIP_GEN_GENERATOR_MSR
#endif
#ifndef TCPIP_CPUTYPE_BITORDER_LSB2MSB
#define TCPIP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_PRECOMPILE
#define TCPIP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_LINKTIME
#define TCPIP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define TCPIP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT
#define TCPIP_CONFIGURATION_VARIANT TCPIP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef TCPIP_POSTBUILD_VARIANT_SUPPORT
#define TCPIP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* User Config File Start */

/* User Config File End */


#endif /* TCPIP_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Cfg.h
 *********************************************************************************************************************/
