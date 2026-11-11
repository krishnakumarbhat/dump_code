#include "cust_someip_iface.h"
#include "populate_and_transmit.h"
#include "sil_wrapper_common.h"

void someip_update_radar_data(SOMEIP_Radar_Struct_T *somip_radar_data, int *position)
{
   switch (*position)
   {
      case FRONT_LEFT:
         somip_radar_data->Vlan_id  = 0X0068;
         somip_radar_data->Src_Mac  = 0x4ABB23BD6328;
         somip_radar_data->Dst_Mac  = 0xA90E22A01A00;
         somip_radar_data->Eth_Type = 0X800;
         break;
      case FRONT_RIGHT:
         somip_radar_data->Vlan_id  = 0X0068;
         somip_radar_data->Src_Mac  = 0x49BB23BD6328;
         somip_radar_data->Dst_Mac  = 0xA90E22A01A00;
         somip_radar_data->Eth_Type = 0X800;
         break;
      case REAR_LEFT:
         somip_radar_data->Vlan_id  = 0X0068;
         somip_radar_data->Src_Mac  = 0x47BB23BD6328;
         somip_radar_data->Dst_Mac  = 0xA90E22A01A00;
         somip_radar_data->Eth_Type = 0X800;
         break;
      case REAR_RIGHT:
         somip_radar_data->Vlan_id  = 0X0068;
         somip_radar_data->Src_Mac  = 0x48BB23BD6328;
         somip_radar_data->Dst_Mac  = 0xA90E22A01A00;
         somip_radar_data->Eth_Type = 0X800;
         break;
      case FRONT_CENTER:
         somip_radar_data->Vlan_id  = 0X0068;
         somip_radar_data->Src_Mac  = 0x4BBB23BD6328;
         somip_radar_data->Dst_Mac  = 0xA90E22A01A00;
         somip_radar_data->Eth_Type = 0X800;
         break;
   }
}

void someip_data_write(unsigned long long timestamp)
{
   SOMEIP_Radar_Struct_T someip_radar_data;
   int posn = Get_Radar_Position();
   someip_update_radar_data(&someip_radar_data, &posn);
   switch (posn)
   {
      case FRONT_LEFT:
         populate_someip_data(&timestamp, &someip_radar_data);
         break;
      case FRONT_RIGHT:
         populate_someip_data(&timestamp, &someip_radar_data);
         break;
      case REAR_LEFT:
         populate_someip_data(&timestamp, &someip_radar_data);
         break;
      case REAR_RIGHT:
         populate_someip_data(&timestamp, &someip_radar_data);
         break;
      case FRONT_CENTER:
         populate_someip_data(&timestamp, &someip_radar_data);
         break;
   }
}

void populate_someip_data(unsigned long long *timestamp, SOMEIP_Radar_Struct_T *someip_radar_data)
{
   clear_someip_buffer();
   populate_object_data();
   encode_someip_messages();
   fill_someip_data(timestamp, someip_radar_data);
}
