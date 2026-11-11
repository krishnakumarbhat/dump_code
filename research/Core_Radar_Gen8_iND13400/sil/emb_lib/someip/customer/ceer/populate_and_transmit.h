#ifndef POPULATE_AND_TRANSMIT_H
#define POPULATE_AND_TRANSMIT_H

#include "ENET_decoded_types.h"
#include "ENET_encoded_types.h"
#include "cust_someip_iface.h"
#include "someip_driver.h"

typedef uint8_t Std_ReturnType;
typedef struct Eth_Header_Tag
{
   uint64_t Dest_MAC_ID;
   uint64_t Source_MAC_ID;
   uint16_t vLAN_TPID;
   uint16_t pvLAN_TCI;
   uint16_t IP_type;
} Eth_Header_T;
typedef struct IPV4_Header_Tag
{
   uint8_t IP_Version_Length;
   uint8_t diff_ServiceField;
   uint16_t IP_length;
   uint16_t IP_Identification;
   uint16_t Frag_Offset;
   uint8_t TTL;
   uint8_t IP_protocol;
   uint16_t IP_XSUM;
   uint32_t IP_Source;
   uint32_t IP_Dest;
} IPV4_Header_T;
typedef struct UDP_Header_Tag
{
   uint16_t SourcePort;
   uint16_t Dest_Port;
   uint16_t UDP_Length;
   uint16_t UDP_XSUM;
} UDP_Header_T;
typedef struct Ethernet_Stack_Layer_Tag
{
   Eth_Header_T Eth_HeaderInfo;
   IPV4_Header_T IPV4_HeaderInfo;
   UDP_Header_T UDP_HeaderInfo;
} Ethernet_Stack_Layer_T;
typedef struct SOMIP_RECORD_Tag
{
   Ethernet_Stack_Layer_T Eth_StackHeaderInfo;
   unsigned char SOMIP_payload[1412]; // UDP/IP data packet
} SOMIP_RECORD_T;
typedef struct UDPpseudoHeader_Tag
{
   uint32_t UPH_Source;
   uint32_t UPH_Dest;
   uint16_t UPH_Length;
   uint8_t UPH_protocol;
} UDPpseudoHeader_T;

void clear_someip_buffer();
void populate_object_data();
void encode_someip_messages();
// void fill_someip_data(unsigned long long *timestamp);
void fill_someip_data(unsigned long long *timestamp, SOMEIP_Radar_Struct_T *someip_radar_data);

void fill_encoded_RADAR_STATUS_RECORD_T(unsigned char *bufferdet);
void fill_encoded_RADAR_SW_INFO_RECORD_T(unsigned char *bufferdet);
void fill_Dimension_Header(unsigned char *bufferdet);
void add_encoded_Dimension(ENET_encoded::Dimension_T *e_ptr);
void add_encoded_RADAR_STATUS_RECORD_T(ENET_encoded::RADAR_STATUS_RECORD_T *e_ptr, unsigned char *buffer_temp);
void add_encoded_VEHICLE_STATUS_RECORD_T(ENET_encoded::VEHICLE_STATUS_RECORD_T *e_ptr, unsigned char *buffer_temp);
void add_encoded_RADAR_SW_INFO_RECORD_T(ENET_encoded::RADAR_SW_INFO_RECORD_T *e_ptr, unsigned char *buffer_temp);

void encode_DETECTIONS_RECORD(ENET_Encoded_Types_T *encoded_data, ENET_Decoded_Types_T *decoded_data);
void encode_RADAR_STATUS_RECORD(ENET_Encoded_Types_T *encoded_data, ENET_Decoded_Types_T *decoded_data);
void encode_RADAR_SW_INFO_RECORD(ENET_Encoded_Types_T *encoded_data, ENET_Decoded_Types_T *decoded_data);
void encode_VEHICLE_STATUS_RECORD(ENET_Encoded_Types_T *encoded_data, ENET_Decoded_Types_T *decoded_data);

#endif
