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
 *              File: SoAd_GenTypes.h
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

#if !defined (SOAD_GEN_TYPES_H)
# define SOAD_GEN_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "TcpIp_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef TcpIp_SocketIdType                        SoAd_SocketIdType; /*!< Socket identifier type. */
# define SOAD_INV_SOCKET_ID                       (TCPIP_INV_SOCKET_ID) /*!< Invalid socket identifier. */

typedef TcpIp_EventType                           SoAd_EventType; /*!< Socket event type. */
# define SOAD_TCP_RESET                           (TCPIP_TCP_RESET) /*!< TCP socket connection reset by remote. */
# define SOAD_TCP_CLOSED                          (TCPIP_TCP_CLOSED) /*!< TCP socket connection closed. */
# define SOAD_TCP_FIN_RECEIVED                    (TCPIP_TCP_FIN_RECEIVED) /*!< TCP socket connection received a FIN. */
# define SOAD_UDP_CLOSED                          (TCPIP_UDP_CLOSED) /*!< UDP socket closed. */
# define SOAD_TLS_HANDSHAKE_SUCCEEDED             (TCPIP_TLS_HANDSHAKE_SUCCEEDED) /*!< TLS handshake successfully established. */
# define SOAD_TLS_EVENT_CLOSENOTIFY_RECEIVED      (TCPIP_TLS_EVENT_CLOSENOTIFY_RECEIVED) /*!< Received a TLS close notify. */

typedef TcpIp_DhcpEventType                       SoAd_DhcpEventType; /*!< DHCP event type. */
# define SOAD_DHCP_EVENT_TX_DISCOVER_SOLICIT      (TCPIP_DHCP_EVENT_TX_DISCOVER_SOLICIT)
# define SOAD_DHCP_EVENT_RX_OFFER_ADVERTISE       (TCPIP_DHCP_EVENT_RX_OFFER_ADVERTISE)
# define SOAD_DHCP_EVENT_TX_REQUEST               (TCPIP_DHCP_EVENT_TX_REQUEST)
# define SOAD_DHCP_EVENT_RX_ACK_REPLY             (TCPIP_DHCP_EVENT_RX_ACK_REPLY)
# define SOAD_DHCP_EVENT_TX_V6_CONFIRM            (TCPIP_DHCP_EVENT_TX_V6_CONFIRM)
# define SOAD_DHCP_EVENT_TX_V6_RENEW              (TCPIP_DHCP_EVENT_TX_V6_RENEW)
# define SOAD_DHCP_EVENT_TX_V6_REBIND             (TCPIP_DHCP_EVENT_TX_V6_REBIND)
# define SOAD_DHCP_EVENT_TX_V6_RELEASE            (TCPIP_DHCP_EVENT_TX_V6_RELEASE)
# define SOAD_DHCP_EVENT_TX_V6_DECLINE            (TCPIP_DHCP_EVENT_TX_V6_DECLINE)
# define SOAD_DHCP_EVENT_INVALID                  (TCPIP_DHCP_EVENT_INVALID)

typedef TcpIp_IpAddrStateType                     SoAd_IpAddrStateType; /*!< IP address state type. */
# define SOAD_IPADDR_STATE_ASSIGNED               (TCPIP_IPADDR_STATE_ASSIGNED) /*!< IP address is assigned. */
# define SOAD_IPADDR_STATE_ONHOLD                 (TCPIP_IPADDR_STATE_ONHOLD) /*!< IP address is not available. */
# define SOAD_IPADDR_STATE_UNASSIGNED             (TCPIP_IPADDR_STATE_UNASSIGNED) /*!< IP address is unassigned. */

typedef TcpIp_DomainType                          SoAd_DomainType; /*!< Socket domain type. */
# define SOAD_AF_INET                             (TCPIP_AF_INET) /*!< Domain type for IPv4. */
# define SOAD_AF_INET6                            (TCPIP_AF_INET6) /*!< Domain type for IPv6. */
# define SOAD_AF_INVALID                          (TCPIP_AF_UNDEFINED) /*!< Invalid domain type. */

typedef TcpIp_SockAddrType                        SoAd_SockAddrType; /*!< Generic socket address type. */
typedef TcpIp_SockAddrInetType                    SoAd_SockAddrInetType; /*!< IPv4 socket address type. */
typedef TcpIp_SockAddrInet6Type                   SoAd_SockAddrInet6Type; /*!< IPv6 socket address type. */

typedef TcpIp_ProtocolType                        SoAd_ProtocolType; /*!< Socket protocol type. */
# define SOAD_IPPROTO_TCP                         (TCPIP_IPPROTO_TCP) /*!< Protocol type for TCP. */
# define SOAD_IPPROTO_UDP                         (TCPIP_IPPROTO_UDP) /*!< Protocol type for UDP. */

typedef TcpIp_ParamIdType                         SoAd_ParamIdType; /*!< Parameter identifier type to change socket specific parameter. */
# define SOAD_PARAMID_TCP_RXWND_MAX               (TCPIP_PARAMID_TCP_RXWND_MAX) /*!< TCP Rx buffer size. */
# define SOAD_PARAMID_FRAMEPRIO                   (TCPIP_PARAMID_FRAMEPRIO) /*!< Frame priority (VLAN). */
# define SOAD_PARAMID_TCP_NAGLE                   (TCPIP_PARAMID_TCP_NAGLE) /*!< Indicates if nagle algorithm enabled. */
# define SOAD_PARAMID_TCP_KEEPALIVE               (TCPIP_PARAMID_TCP_KEEPALIVE) /*!< Indicates if keep alive enabled. */
# define SOAD_PARAMID_TTL                         (TCPIP_PARAMID_TTL) /*!< Time to live. */
# define SOAD_PARAMID_TCP_KEEPALIVE_TIME          (TCPIP_PARAMID_TCP_KEEPALIVE_TIME) /*!< Keep alive time. */
# define SOAD_PARAMID_TCP_KEEPALIVE_PROBES_MAX    (TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX) /*!< Number of keep alive probes. */
# define SOAD_PARAMID_TCP_KEEPALIVE_INTERVAL      (TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL) /*!< Interval time of keep alive probes. */
# define SOAD_PARAMID_UDP_CHECKSUM                (TCPIP_PARAMID_UDP_CHECKSUM) /*!< Indicates if UDP Checksum is enabled. */
# define SOAD_PARAMID_TLS_CONNECTION_ASSIGNMENT   (TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT) /*!< TLS connection assignment. */
# define SOAD_PARAMID_TCP_MSL                     (TCPIP_PARAMID_TCP_MSL) /*!< Socket specific MSL assignment. */
# define SOAD_PARAMID_TCP_TXWND_MAX               (TCPIP_PARAMID_V_TCP_TXBUFSIZE) /*!< TCP Tx buffer size. */
# define SOAD_PARAMID_UDP_TXREQLISTSIZE           (TCPIP_PARAMID_V_UDP_TXREQLISTSIZE) /*!< UDP Tx request list size to store transmissions if TxConfirmation is required. */
# define SOAD_PARAMID_UDP_TXRETRYLISTSIZE         (TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE) /*!< UDP Tx retry list size to store transmissions if address resolution (e.g. ARP) is not yet finished. */

typedef TcpIp_IpAddrAssignmentType                SoAd_IpAddrAssignmentType; /*!< IP address assignment type. */
# define SOAD_IPADDR_ASSIGNMENT_STATIC            (TCPIP_IPADDR_ASSIGNMENT_STATIC) /*!< Static IP address. */
# define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP    (TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) /*!< Link local IP address with parameters for DoIP use-case. */
# define SOAD_IPADDR_ASSIGNMENT_DHCP              (TCPIP_IPADDR_ASSIGNMENT_DHCP) /*!< DHCP IP address. */
# define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL         (TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL) /*!< Link local IP address. */
# define SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER       (TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER) /*!< Dynamic configured IPv6 address by Router Advertisement. */

typedef TcpIp_LocalAddrIdType                     SoAd_LocalAddrIdType; /*!< Local address identifier type. */

#endif /* SOAD_GEN_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_GenTypes.h
 *********************************************************************************************************************/

