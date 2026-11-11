#ifndef Radar_SIL_Output_Data_H
#define Radar_SIL_Output_Data_H
/*===========================================================================*
 * FILE: Radar_SIL_Output_Data.h
 *===========================================================================
 * Copyright 2024 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Input Data Structures for RADAR Software In Loop(SIL) Simulation.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
 *===========================================================================*/
#define OUTPUT_DATA_STRUCTURE_VERSION (9)
#define MAX_CAN_MESSAGES              500
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "RR_ADAS_SYMBOL_Data.h"
#include "fixmac.h"
//#include "RR_ADAS_SYMBOL_Enum.h"
#include "dvl_message.h"

#pragma pack(push, save_pack)
#pragma pack(push, 2)
/*===========================================================================*
 * Typedef's or Structure Declarations
 *===========================================================================*/
/* Header for the Output Data Structure */
typedef struct Output_Data_Hdr
{
   uint32_t Sec_Size;
   uint16_t Sec_Compatibility;
   uint16_t Sec_Checksum;
   uint16_t sym_version; // symbol interface version number
   uint32_t sym_Size;    // size of the SIL_Data_Output structure
} Output_Data_Hdr_T;

// Structure to hold SIL error status from emb library: Sensors &ECU: Enums are defined in the file "apt_sil_error_enum.h"
typedef struct emb_sil_status_tag
{
   unsigned int ver;
   uint8_t silErrStatus[150];
} emb_sil_status_t;

typedef struct silEmbStatus
{
   unsigned char status_flag;
   emb_sil_status_t emb_status;
} silEmbStatus_t;
typedef struct ENET_BUFF_TAG
{
   unsigned char Buf_Bytes[1500];
} ENET_BUFF_T;

typedef struct CAN_OVER_UDP_TAG
{
   unsigned char Buf_Bytes[1500];
} CAN_OVER_UDP_T;

typedef struct SOMEIP_BUFF_TAG
{
   uint64_t PLPTimeStamp_ns; // plp timestamp to given in nano secs
   uint64_t srcMACaddress;   // Source MAC Addr decoded from the field ETH_Frame.Source of input mf4 file
   uint64_t destMACaddress;  // Destination MAC Addr decoded from the field ETH_Frame.Destination of input mf4 file
   uint16_t Ether_Type;      // Currently Ether type is set to Internet Protocol version 4 (IPv4/0x800)
   uint16_t vLAN_ID;         // This field can be filled only when theEthertype is set to VLAN_TAG
   unsigned int data_length; // Total number of Buf_Bytes (IPv4 length field to be given)
   unsigned char Buf_Bytes[1500];
} SOMEIP_BUFF_T;

typedef struct DVL_PAYLOAD
{
   dvlMessageUnion dvl[MAX_CAN_MESSAGES];
   unsigned int msg_count;
} DVL_PAYLOAD_T;

/* Output Data Structure Declaration */
typedef struct SIL_RADAR_Output_Data
{
   Output_Data_Hdr_T Output_Data_Header;
   /* DVSU Payload*/
   ENET_BUFF_T Tx_Buff[250];
   unsigned char Buff_Len;
   bool f_dvsu_buff_valid;
   /*.............*/

   /* SOMEIP Payload*/
   SOMEIP_BUFF_T SOMEIP_Tx_Buff[120];
   unsigned char SOMEIP_Buff_Len;
   unsigned char SOMEIP_f_buff_valid;

   /* DVL Payload */
   DVL_PAYLOAD_T dvl_payload_out;
   /*.............*/

   /* MUDP Record */
   RR_ADAS_SYMBOL_Data_T Symbol_Record;

   /* Embedded sil process status */
   emb_sil_status_t silProcessStatus;
   /*............*/

   /* Can data over UDP*/
   CAN_OVER_UDP_T Can_UDP_Tx_Buff[150]; // need to decide the size of the buffer
   unsigned char Buff_CAN_UDP_Len;
   bool f_CAN_UDP_buff_valid;
   /*............*/
} SIL_RADAR_Output_Data_T;
#pragma pack(pop, save_pack)
#endif
