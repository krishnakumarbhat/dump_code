/****************************************************************************
 * Copyright 2022 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 * Version Tracking Header
 * %file_name: EthIf_User_Cbk.c
 * %version: 1 %
 * %last_modified_by:Mounir Karmada%
 * %date_modified: 31-Oct-2022 %
 *
 ******************************************************************************
 *
 * Module Name:
 *    EthIf_User_Cbk.c
 *
 * Description:
 *    This module contains the extended configuration of Ethernet MAC and IP.
 *
 * Traces to Software Architecture/Design Document:
 *    SAD_...
 *
 * Implements following software requirements:
 *    WI-xxxxx,...
 *
 * Deviations/Justifications from software standards:
 *    None
 *
 *****************************************************************************/
/*===========================================================================*\
 * Includes
\*===========================================================================*/
#include "EthIf_User_Cbk.h"
#include "EthSM.h"
#include "SoAd.h"
#include "SoAd_Cfg.h"
#include "TcpIp_IpV4.h"
#include "TcpIp_Types.h"
#include "calibration_if.h"
#include "sensor_position.h"
#include "smc_cal.h"

#define DEFAULT_REMOTE_IP_LSB (40U)

static uint8 Base_MAC_Address[MAC_ADDR_BYTES] = {0x28u, 0x63u, 0xBDu, 0x23u, 0xBBu, 0x00u};
static uint32 Base_Ip_Address                 = 0x0001A8C0u;

static uint8 Default_Addr_Lsb[14] = {71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u};

/************************************************************************************************/
/* Link State Change callback - Called once per change,
 *which guarantees resetting of IP and MAC once Link is lost and reestablished
 */
volatile static uint8 logging_socket_open = 0;
TcpIp_SockAddrBaseType localAddress;
TcpIp_SockAddrBaseType remoteAddress;
void CDD_Cbk_TrcvLinkStateChg(uint8 EthIfCtrlIdx, EthTrcv_LinkStateType TrcvLinkState)
{
   /* Only read position for IP/MAC assignment on Link Up notification*/
   if (TrcvLinkState != ETHTRCV_LINK_STATE_DOWN)
   {
      uint8 ecu_position;
      Std_ReturnType returnVal;
      uint8 net_mask = 0u; /* Netmask in CIDR notation */

      ecu_position = Get_Radar_Position();

      localAddress.sa_family           = TCPIP_AF_INET;
      localAddress.SockAddrIn.sin_addr = Get_Sensor_IP_Address(ecu_position);

      remoteAddress.sa_family           = TCPIP_AF_INET;
      remoteAddress.SockAddrIn.sin_addr = Get_Remote_IP_Address();
      remoteAddress.DomainAndPort.port  = Get_Remote_Port();

      /* Update Eth State Once */
      EthSM_MainFunction();

      /* Set Source MAC Address */
      EthIf_SetPhysAddr(EthIfCtrlIdx, Get_Sensor_Mac_Address(ecu_position));

      /* Call IpV4_MainFunction to enable IpV4CtrlDyn */
      IpV4_MainFunction(TCPIP_SINGLECORE_APPLID);

      /* Set Source IP Address */
      returnVal =
         TcpIp_RequestIpAddrAssignment(TcpIpConf_TcpIpLocalAddr_NEP_SRR_1_RdrNet_Unicast_48476027, TCPIP_IPADDR_ASSIGNMENT_STATIC,
                                       (TCPIP_P2V(TcpIp_SockAddrType)) & localAddress, net_mask, 0U);

      /* Set destination address for logging bundle */
      if (returnVal == E_OK)
      {
         returnVal = SoAd_SetRemoteAddr(SoAdConf_SoAdSocketConnection_ConnectionBundle_RDR_1_94fef815_001,
                                        (TCPIP_P2V(TcpIp_SockAddrType)) & remoteAddress);
      }
      logging_socket_open = SoAd_OpenSoCon(SoAdConf_SoAdSocketConnection_ConnectionBundle_RDR_1_94fef815_001);
#if 0
      /* Set destination address for CDC bundle */
      if (returnVal == E_OK)
      {
         remoteAddress.DomainAndPort.port = Get_Remote_Port() + CDC_PORT_OFFSET;
         returnVal                        = SoAd_SetRemoteAddr(SoAdConf_SoAdSocketConnection_SoAdSocketConnection_CDC,
                                                               (TCPIP_P2V(TcpIp_SockAddrType)) & remoteAddress);
      }
      cdc_socket_open = SoAd_OpenSoCon(SoAdConf_SoAdSocketConnection_SoAdSocketConnection_CDC);
#endif
   }
   else
   {
      /* Do Nothing */
   }
}

/* Construct the MAC address with the LSB defined in SMC */
static uint8 *Get_Sensor_Mac_Address(uint8 position)
{
   if (true == (boolean)Get_Cal_Load_Status((Log_Cal_Src_T)SMC))
   {
      Base_MAC_Address[MAC_ADDR_BYTES - 1u] = Default_Addr_Lsb[position - 1u];
   }
   else
   {
      Base_MAC_Address[MAC_ADDR_BYTES - 1u] =
         SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_sensor_ethernet_lsb_list[position - 1u];
   }

   return (uint8 *)Base_MAC_Address;
}

/* Construct the IP address with the LSB defined in SMC */
static uint32 Get_Sensor_IP_Address(uint8 position)
{
   uint8 ip_lsb;
   uint32 l_sensor_address = 0;

   if (true == (boolean)Get_Cal_Load_Status((Log_Cal_Src_T)SMC))
   {
      l_sensor_address = Base_Ip_Address;
      l_sensor_address = l_sensor_address | (Default_Addr_Lsb[position - 1u] << IP_ADD_POS_3);
   }
   else
   {
      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_sensor_ethernet_lsb_list[position - 1u];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_3);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[0];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_0);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[1];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_1);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[2];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_2);
   }

   return l_sensor_address;
}

/* Construct the IP address with the LSB defined in SMC */
uint32 Get_Remote_IP_Address(void)
{
   uint8 ip_lsb;
   uint32 l_sensor_address = 0;
   if (true == (boolean)Get_Cal_Load_Status((Log_Cal_Src_T)SMC))
   {
      l_sensor_address = Base_Ip_Address;
      l_sensor_address = l_sensor_address | (DEFAULT_REMOTE_IP_LSB << IP_ADD_POS_3);
   }
   else
   {
      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[0];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_0);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[1];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_1);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[2];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_2);

      ip_lsb           = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[3];
      l_sensor_address = l_sensor_address | (ip_lsb << IP_ADD_POS_3);
   }

   return l_sensor_address;
}

uint16 Get_Remote_Port(void)
{
   // TO DO: read port from SMC when available
   return REMOTE_PORT;
}

uint16 Get_Local_Port(void)
{
   // TO DO: read port from SMC when available
   return LOCAL_PORT;
}

/**************************************************************************************************************
 *                               Revision History
 **************************************************************************************************************
 *
 *    Date        By             Description
 * ----------  ---------   -----------------------
 * 11-02-2022  Mounir          - Initial Version to set IP and MAC per sensor position.
\*===========================================================================================================*/
