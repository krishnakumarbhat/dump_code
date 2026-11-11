#ifndef SOMEIP_SIL_DRIVER_H
#define SOMEIP_SIL_DRIVER_H

#include "fixmac.h"

#define MAX_SOMEIP_MESSAGES (120)

typedef struct SOMEIP_ID_Struct_Tag
{
   uint8_t SOMEIP_Flag;
   uint64_t SOMEIP_PLPTimeStamp;
   uint64_t SOMEIP_src_MACaddr;
   uint64_t SOMEIP_Dest_MACaddr;
   uint64_t SOMEIP_Ether_type;
   uint64_t SOMEIP_VLAN_ID;
   unsigned int SOMEIP_Data_Len;
   unsigned char SOMEIP_Buff[1500];
} SOMEIP_ID_Struct_T;

static long long time = 0;
void Fill_SOMEIP_buffer(unsigned int Data_Len, unsigned char Buff[1500]);
void Transmit_SOMEIP_Signals(SOMEIP_ID_Struct_T *SOMEIP_Enable, uint16_t *total_someip_buff_Len, unsigned long long *timestamp);

#endif // SOMEIP_SIL_DRIVER_H
