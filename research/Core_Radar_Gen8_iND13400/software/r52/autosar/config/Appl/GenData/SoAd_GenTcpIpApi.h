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
 *              File: SoAd_GenTcpIpApi.h
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

#if !defined (SOAD_GEN_TCPIP_API_H)
# define SOAD_GEN_TCPIP_API_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "TcpIp.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

# define SoAd_TcpIpApiSoAdGetSocket(DOMAIN, PROTOCOL, SOCKETIDPTR) \
  TcpIp_SoAdGetSocket((DOMAIN), (PROTOCOL), (SOCKETIDPTR))

# define SoAd_TcpIpApiChangeParameter(SOCKETID, PARAMETERID, PARAMETERVALUE) \
  TcpIp_ChangeParameter((SOCKETID), (PARAMETERID), (PARAMETERVALUE))

# define SoAd_TcpIpApiBind(SOCKETID, LOCALADDRID, PORTPTR) \
  TcpIp_Bind((SOCKETID), (LOCALADDRID), (PORTPTR))

# define SoAd_TcpIpApiTcpListen(SOCKETID, MAXCHANNELS) \
  TcpIp_TcpListen((SOCKETID), (MAXCHANNELS))

# define SoAd_TcpIpApiTcpConnect(SOCKETID, REMOTEADDRPTR) \
  TcpIp_TcpConnect((SOCKETID), (REMOTEADDRPTR))

# define SoAd_TcpIpApiTcpTransmit(SOCKETID, DATAPTR, AVAILABLELENGTH, FORCERETRIEVE) \
  TcpIp_TcpTransmit((SOCKETID), (DATAPTR), (AVAILABLELENGTH), (FORCERETRIEVE))

# define SoAd_TcpIpApiUdpTransmit(SOCKETID, DATAPTR, REMOTEADDRPTR, TOTALLENGTH) \
  TcpIp_UdpTransmit((SOCKETID), (DATAPTR), (REMOTEADDRPTR), (TOTALLENGTH))

# define SoAd_TcpIpApiTcpReceived(SOCKETID, LENGTH) \
  TcpIp_TcpReceived((SOCKETID), (LENGTH))

# define SoAd_TcpIpApiClose(SOCKETID, ABORT) \
  TcpIp_Close((SOCKETID), (ABORT))

# define SoAd_TcpIpApiRequestIpAddrAssignment(LOCALADDRID, TYPE, LOCALIPADDRPTR, NETMASK, DEFAULTROUTERPTR) \
  TcpIp_RequestIpAddrAssignment((LOCALADDRID), (TYPE), (LOCALIPADDRPTR), (NETMASK), (DEFAULTROUTERPTR))

# define SoAd_TcpIpApiReleaseIpAddrAssignment(LOCALADDRID) \
  TcpIp_ReleaseIpAddrAssignment((LOCALADDRID))

# define SoAd_TcpIpApiGetIpAddr(LOCALADDRID, IPADDRPTR, NETMASKPTR, DEFAULTROUTERPTR) \
  TcpIp_GetIpAddr((LOCALADDRID), (IPADDRPTR), (NETMASKPTR), (DEFAULTROUTERPTR))

# define SoAd_TcpIpApiGetCtrlIdx(LOCALADDRID, CTRLIDXPTR) \
  TcpIp_GetCtrlIdx((LOCALADDRID), (CTRLIDXPTR))

# define SoAd_TcpIpApiGetRemotePhysAddr(CTRLIDX, IPADDRPTR, PHYSADDRPTR, INITRES) \
  TcpIp_GetRemotePhysAddr((CTRLIDX), (IPADDRPTR), (PHYSADDRPTR), (INITRES))

# define SoAd_TcpIpApiGetPhysAddr(LOCALADDRID, PHYSADDRPTR) \
  TcpIp_GetPhysAddr((LOCALADDRID), (PHYSADDRPTR))

# define SoAd_TcpIpApiDhcpReadOption(LOCALADDRID, OPTION, DATALENGTH, DATAPTR) \
  TcpIp_DhcpReadOption((LOCALADDRID), (OPTION), (DATALENGTH), (DATAPTR))

# define SoAd_TcpIpApiDhcpWriteOption(LOCALADDRID, OPTION, DATALENGTH, DATAPTR) \
  TcpIp_DhcpWriteOption((LOCALADDRID), (OPTION), (DATALENGTH), (DATAPTR))

# define SoAd_TcpIpApiDhcpV6ReadOption(LOCALADDRID, OPTION, DATALENGTH, DATAPTR) \
  TcpIp_DhcpV6ReadOption((LOCALADDRID), (OPTION), (DATALENGTH), (DATAPTR))

# define SoAd_TcpIpApiDhcpV6WriteOption(LOCALADDRID, OPTION, DATALENGTH, DATAPTR) \
  TcpIp_DhcpV6WriteOption((LOCALADDRID), (OPTION), (DATALENGTH), (DATAPTR))

#endif /* SOAD_GEN_TCPIP_API_H */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_GenTcpIpApi.h
 *********************************************************************************************************************/

