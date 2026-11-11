/**
 * @file EthIf_User_Cbk_wrapper.c
 * @brief Wrapper for EthIf_User_Cbk.c with testable implementations
 */

#include "EthIf_User_Cbk_fakes.h"

// Mock SMC Calibration Data
static SMC_Cal_Data_T mock_smc_data = {
   .Vehicle_Configuration_Cal = {.k_sensor_ethernet_lsb_list = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08},
                                 .k_destination_ip           = {192, 168, 1, 100}}};

SMC_Cal_Data_T *SMC_Cal_Data_Ptr = &mock_smc_data;

#line 1 "software/r52/autosar/config/Appl/Source/EthIf_User_Cbk.c"
#define IP_ADD_POS_0 0u
#define IP_ADD_POS_1 8u
#define IP_ADD_POS_2 16u
#define IP_ADD_POS_3 24u
#define REMOTE_PORT  5050u
#define LOCAL_PORT   5000u
#define BASE_IP_ADDR 0x0001A8C0u

static uint8_t default_addr_lsb[14] = {71u, 72u, 73u, 74u, 75u, 76u, 77u, 78u, 79u, 80u, 81u, 82u, 83u, 84u};

void User_EthIf_ArpTableAddEntry(uint8_t CtrlIdx, const uint8_t *MacPtr, const uint8_t *IpV4AddrPtr)
{
   // Empty implementation
}

void User_EthIf_CtrlModeIndication(uint8_t CtrlIdx, uint8_t CtrlMode)
{
   // Empty implementation
}

void User_EthIf_TrcvModeIndication(uint8_t TrcvIdx, uint8_t TrcvMode)
{
   static uint8_t mac_address[MAC_ADDR_BYTES];
   static uint32_t ip_address;

   if (Get_Cal_Load_Status((Log_Cal_Src_T)SMC))
   {
      mac_address[0] = 0x28u;
      mac_address[1] = 0x63u;
      mac_address[2] = 0xBDu;
      mac_address[3] = 0x23u;
      mac_address[4] = 0xBBu;
      mac_address[5] = default_addr_lsb[TrcvIdx];

      ip_address = BASE_IP_ADDR | ((uint32_t)default_addr_lsb[TrcvIdx] << IP_ADD_POS_3);
   }
   else
   {
      for (uint8_t i = 0; i < MAC_ADDR_BYTES; i++)
      {
         mac_address[i] = SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_sensor_ethernet_lsb_list[i];
      }

      ip_address = ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[0] << IP_ADD_POS_0) |
                   ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[1] << IP_ADD_POS_1) |
                   ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[2] << IP_ADD_POS_2) |
                   ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[3] << IP_ADD_POS_3);
   }

   EthIf_SetPhysAddr(0, mac_address);

   SoAd_SetUniqueRemoteAddr(0, (uint8_t *)&ip_address, REMOTE_PORT);
}

void User_EthIf_SwitchPortModeIndication(EthIf_SwitchPortIdxType PortIdx, uint8_t PortMode)
{
   // Empty implementation
}
