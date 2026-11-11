#ifndef CAN_SIL_DRIVER_H
#define CAN_SIL_DRIVER_H

#define CAN_Signals_per_UDP_frame      18
#define CANOVERUDP_IDENTIFICATION_WORD ((uint16_t)0x5A28U)

#include "fixmac.h"

void Fill_CAN_buffer(uint32_t Handle, uint32_t CanID, uint8_t DLC, const uint8_t *Data);
void Transmit_CAN_Signals(unsigned long long timestamp);
void Transmit_CAN_over_UDP(void);

typedef struct Can_ID_Struct_Tag
{
   uint32_t Can_Id;
   uint8_t Can_Data[8];
} Can_ID_Struct_T;

typedef struct CAN_FD_ID_UDP_Tag
{
   uint64_t Cycle_Timestamp_us;
   uint32_t Can_Id;
   uint32_t reserved;
   uint8_t Can_Data[64]; //(76 Bytes size for CAN_FD_ID_UDP_T)

} CAN_FD_ID_UDP_T;

typedef struct CAN_FD_UDP_HEADER_Tag
{
   uint16_t Identification; // 0x5A28: 0x5A is a mgic number and 0x28 = 40 the size of the CAN_FD_UDP_HEADER_T
   uint8_t CANOVERUDP_Implentation_version_Major;
   uint8_t CANOVERUDP_Implentation_version_Minor;
   uint8_t SW_APPlication_Version_Major;
   uint8_t SW_APPlication_Version_Minor;
   uint8_t SW_APPlication_Version_Patch;
   uint8_t CAN_DBC_Version_Major;
   uint8_t CAN_DBC_Version_Minor;
   uint8_t reserved1[7];
   uint16_t Scan_Index;
   uint8_t Total_CANOVERUDP_Frames;
   uint8_t Current_CANOVERUDP_Frames;
   uint16_t Frame_Data_Size; // payload bytes in this frame (header size excluded)
   uint8_t Radar_posn;       //->each emblib packs this
   uint8_t Customer;
   uint8_t reserved2[16]; //  (Total size of CAN_FD_UDP_HEADER_T = 40 bytes)

} CAN_FD_UDP_HEADER_T;

typedef struct CAN_UDP_DATA_Tag
{
   CAN_FD_UDP_HEADER_T header;
   CAN_FD_ID_UDP_T data[CAN_Signals_per_UDP_frame];
} CAN_UDP_DATA_T;

union CAN_OVER_UDP
{
   CAN_UDP_DATA_T can_frame_data;    // size 1484
   unsigned char can_rawframe[1500]; // size 1500
};

#endif // CAN_SIL_DRIVER_H
