#ifndef CUST_SOMEIP_IFACE_H
#define CUST_SOMEIP_IFACE_H

#include "fixmac.h"

typedef struct SOMEIP_Radar_Struct_Tag
{
   uint64_t Vlan_id;
   uint64_t Src_Mac;
   uint64_t Dst_Mac;
   uint64_t Eth_Type;
} SOMEIP_Radar_Struct_T;

void someip_data_write(unsigned long long timestamp);
void populate_someip_data(unsigned long long *timestamp, SOMEIP_Radar_Struct_T *someip_radar_data);

#endif // CUST_SOMEIP_IFACE_H
