#include "someip_driver.h"
#include "sil_wrapper_common.h"
#include <string.h>

void Transmit_SOMEIP_Signals(SOMEIP_ID_Struct_T *SOMEIP_Enable, uint16_t *total_someip_buff_Len, unsigned long long *timestamp)
{
   // time=time +1;
   SIL_RADAR_Output_Data_T *Output_Ptr = Get_Sil_Radar_Output_Data_Ptr();
   for (int i = 0; i < *total_someip_buff_Len && i < MAX_SOMEIP_MESSAGES; i++)
   {
      if (SOMEIP_Enable[i].SOMEIP_Flag == 1)
      {
         Output_Ptr->SOMEIP_Tx_Buff[i].PLPTimeStamp_ns = SOMEIP_Enable[i].SOMEIP_PLPTimeStamp; // timestamp;
         Output_Ptr->SOMEIP_Tx_Buff[i].srcMACaddress   = SOMEIP_Enable[i].SOMEIP_src_MACaddr;
         Output_Ptr->SOMEIP_Tx_Buff[i].destMACaddress  = SOMEIP_Enable[i].SOMEIP_Dest_MACaddr;
         Output_Ptr->SOMEIP_Tx_Buff[i].Ether_Type      = SOMEIP_Enable[i].SOMEIP_Ether_type;
         Output_Ptr->SOMEIP_Tx_Buff[i].vLAN_ID         = SOMEIP_Enable[i].SOMEIP_VLAN_ID;
         Output_Ptr->SOMEIP_Tx_Buff[i].data_length     = SOMEIP_Enable[i].SOMEIP_Data_Len;
         memcpy(Output_Ptr->SOMEIP_Tx_Buff[i].Buf_Bytes, SOMEIP_Enable[i].SOMEIP_Buff,
                sizeof(Output_Ptr->SOMEIP_Tx_Buff[i].Buf_Bytes));
      }
   }

   Output_Ptr->SOMEIP_Buff_Len     = *total_someip_buff_Len;
   Output_Ptr->SOMEIP_f_buff_valid = 1;
}
