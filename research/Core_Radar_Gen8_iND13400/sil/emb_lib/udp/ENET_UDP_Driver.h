#ifndef ENET_UDP_DRIVER_H_
#define ENET_UDP_DRIVER_H_

/*===========================================================================*\
 * FILE: ENET_UDP_Driver.h
 *===========================================================================
 * Copyright 2024 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * DESCRIPTION:
 *   Header file for Ethernet Driver.
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
 *     TODO: Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   TODO: List of deviations from standards in this file, or
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

#include "fixmac.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#define TYPE_ARP             (0x0806)
#define ARP_Request_Opcode   (1)
#define ARP_Response_Opcode  (2)
#define ORIGIN_MAC_LAST_BYTE (11)
#define PROTOCOL_ID_UDP      (0x11)
#define Extra_HIL_frames     (2)
#define HOST_PC_IP_ADDRESS   (0xC0A80128)

/*
 * Legacy Bit level Buffer Descriptor definitions
 */
#define TX_BD_R     0x8000
#define TX_BD_INUSE 0x4000
#define TX_BD_TO1   0x4000
#define TX_BD_W     0x2000
#define TX_BD_TO2   0x1000
#define TX_BD_L     0x0800
#define TX_BD_TC    0x0400
#define TX_BD_DEF   0x0200
#define TX_BD_HB    0x0100
#define TX_BD_LC    0x0080
#define TX_BD_RL    0x0040
#define TX_BD_UN    0x0002
#define TX_BD_CSL   0x0001

#define RX_BD_E     0x8000
#define RX_BD_INUSE 0x4000
#define RX_BD_R01   0x4000
#define RX_BD_W     0x2000
#define RX_BD_R02   0x1000
#define RX_BD_L     0x0800
#define RX_BD_M     0x0100
#define RX_BD_BC    0x0080
#define RX_BD_MC    0x0040
#define RX_BD_LG    0x0020
#define RX_BD_NO    0x0010
#define RX_BD_SH    0x0008
#define RX_BD_CR    0x0004
#define RX_BD_OV    0x0002
#define RX_BD_TR    0x0001

typedef struct ENET_Frame_data
{
   uint32_t XCP_TX_count;
   uint16_t Logging_TX_error;
   uint16_t CDC_TX_error;
   uint16_t ARP_TX_error;
   uint16_t No_buffer_free;
   uint16_t Next_buffer_occupied;
   uint16_t Wrapping_around_count;
} ENET_Frame_data_T;

typedef struct ENET_Frame_type
{
   uint16_t ARP_frame_received;
   uint16_t Undefined_frame_received;
   uint16_t HIL_frame_received;
   uint16_t XCP_frame_received;
} ENET_Frame_type_T;
/* Enhanced TX Buffer Descriptor Bit Level Definitions - Status0 */
#define TX_BD_S0_R   0x8000
#define TX_BD_S0_TO1 0x4000
#define TX_BD_S0_W   0x2000
#define TX_BD_S0_TO2 0x1000
#define TX_BD_S0_L   0x0800
#define TX_BD_S0_TC  0x0400

/* Enhanced TX Buffer Descriptor Bit Level Definitions - Status8 */
#define TX_BD_S8_INT   0x4000
#define TX_BD_S8_TS    0x2000
#define TX_BD_S8_PINS  0x1000
#define TX_BD_S8_IINS  0x0800
#define TX_BD_S8_FTYPE 0x00F0

/* Enhanced TX Buffer Descriptor Bit Level Definitions - StatusA */
#define TX_BD_SA_TXE 0x8000
#define TX_BD_SA_UE  0x2000
#define TX_BD_SA_EE  0x1000
#define TX_BD_SA_FE  0x0800
#define TX_BD_SA_LCE 0x0400
#define TX_BD_SA_OE  0x0200
#define TX_BD_SA_TSE 0x0100
/* Enhanced TX Buffer Descriptor Bit Level Definitions - Status10 */
#define TX_BD_S10_BDU 0x8000

/* Enhanced RX Buffer Descriptor Bit Level Definitions - Status0 */
#define RX_BD_S0_E   0x8000
#define RX_BD_S0_RO1 0x4000
#define RX_BD_S0_W   0x2000
#define RX_BD_S0_RO2 0x1000
#define RX_BD_S0_L   0x0800
#define RX_BD_S0_M   0x0100
#define RX_BD_S0_BC  0x0080
#define RX_BD_S0_MC  0x0040
#define RX_BD_S0_LG  0x0020
#define RX_BD_S0_NO  0x0010
#define RX_BD_S0_CR  0x0004
#define RX_BD_S0_OV  0x0002
#define RX_BD_S0_TR  0x0001

/* Enhanced RX Buffer Descriptor Bit Level Definitions - Status8 */
#define RX_BD_S8_ME  0x8000
#define RX_BD_S8_PE  0x0400
#define RX_BD_S8_CE  0x0200
#define RX_BD_S8_UC  0x0100
#define RX_BD_S8_INT 0x0080

/* Enhanced RX Buffer Descriptor Bit Level Definitions - StatusA */
#define RX_BD_SA_VPCP 0xE000
#define RX_BD_SA_ICE  0x0020
#define RX_BD_SA_PCR  0x0010
#define RX_BD_SA_VLAN 0x0004
#define RX_BD_SA_IPV6 0x0002
#define RX_BD_SA_FRAG 0x0001

/* Enhanced RX Buffer Descriptor Bit Level Definitions - StatusC */
#define RX_BD_SC_HDR_LEN   0xF800
#define RX_BD_SC_PROT_TYPE 0x00FF

/* Enhanced RX Buffer Descriptor Bit Level Definitions - Status10 */
#define RX_BD_S10_BDU 0x8000

/* Bit definitions and macros for MCF_FEC_RCR */
#define MPC_FEC_RCR_LOOP      (0x00000001)
#define MPC_FEC_RCR_DRT       (0x00000002)
#define MPC_FEC_RCR_MII_MODE  (0x00000004)
#define MPC_FEC_RCR_PROM      (0x00000008)
#define MPC_FEC_RCR_BC_REJ    (0x00000010)
#define MPC_FEC_RCR_FCE       (0x00000020)
#define MPC_FEC_RCR_MAX_FL(x) (((x)&0x000007FF) << 16)

#define FAIL      0
#define OK        1
#define TRUE_REJ  2
#define BROADCAST 2

#define RX_BUFFER_SIZE 1536

#define TX_BUFFER_SIZE 1536

/* UDP Packet format*/

#define PACKET_LEN_BEFORE_UDP_PAYLOAD 42

#define PACKET_LEN_BEFORE_UDP_PAYLOAD_WORD 21

#define UDP_HEADER_SIZE 8

#define IPV4_HEADER_SIZE 20

#define UDP_MAX_PAYLOAD 1468

#define UDP_PAYLOAD 1424

/* IPv4 Length Byte offsets */

#define IPV4_LEN_MSB_BYTE_OFFSET 16

#define IPV4_LEN_LSB_BYTE_OFFSET 17

/* UDP Length Byte offsets */

#define UDP_LEN_MSB_BYTE_OFFSET 38

#define UDP_LEN_LSB_BYTE_OFFSET 39

/* Length for ARP Packet  */

#define ARP_PACKET_LENGTH (44)

#define MAX_XCP_REQ_LENGTH (100)

#define PACKET_LEN_BEFORE_XCP_PAYLOAD 46

#define XCP_RESP_HEADER_LENGTH (4)

/*UDP Standard length*/

#define UDP_PACKET_LENGTH (1514)

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

typedef volatile signed long vint32_t;
typedef volatile unsigned long vuint32_t;

typedef enum Tx_Rx_Buffer_Tag
{
   UDP_LOGGING_BUFFER = 1,
   HIL_LOGGING_BUFFER = 2,
   ENET_INVALID_BUFFER
} Tx_Rx_Buffer_T;

typedef enum
{
   ENET_BUFF_MEMORY_INIT         = 0,
   ENET_BUFF_MEMORY_INIT_SUCCESS = 1,
   ENET_BUFF_MEMORY_INSUFFICIENT
} ENET_BUFF_MEMORY_STATUS_T;

typedef enum ENET_Buffer_Overlap_Tag
{
   UDP_Tx_Buffer_Memory_Over = 1,
   UDP_Rx_Buffer_Memory_Over = 2,
   HIL_Rx_Buffer_Memory_Over = 3,
   MAX_Buffer_Memory
} ENET_Buffer_Overlap_T;

typedef enum ENET_Radar_Position_Tag
{
   ENET_RADAR_POSITION_UNKNOWN = 0, /*DEFAULT     */
   ENET_RADAR_POSITION_RL      = 1, /*REAR_LEFT   */
   ENET_RADAR_POSITION_RR      = 2, /*REAR_RIGHT  */
   ENET_RADAR_POSITION_FR      = 3, /*FRONT_RIGHT */
   ENET_RADAR_POSITION_FL      = 4, /*FRONT_LEFT  */
   ENET_RADAR_POSITION_CF      = 5, /*FRONT_CENTER*/
   ENET_RADAR_POSITION_CR      = 6, /*REAR_CENTER */
   ENET_RADAR_POSITION_RC      = 7, /*RIGHT_CENTER*/
   ENET_RADAR_POSITION_LC      = 8, /*LEFT_CENTER */
   ENET_RADAR_POSITION_INVALID
} ENET_Radar_Position_Tag;

typedef struct XCP_packet
{
   vuint8_t XCP_Length[2];
   vuint8_t XCP_Counter[2];
   vuint8_t data[8];
} XCP_Packet_T;

/* Legacy Buffer Descriptor Format */
typedef struct
{
   uint16_t status; /* control and status */
   uint16_t length; /* transfer length */
   uint8_t *data;   /* buffer address */
} NBUF;

/* Enhanced Buffer Descriptor Format */
typedef union Tx_Rx_eNBUF_Tag
{
   struct
   {
      vuint16_t status0;   /* control and status */
      vuint16_t length;    /* transfer length */
      vuint8_t *data;      /* buffer address */
      vuint16_t status8;   /* control and status */
      vuint16_t statusA;   /* control and status */
      vuint16_t statusC;   /* control and status */
      vuint16_t statusE;   /* control and status */
      vuint16_t status10;  /* control and status */
      vuint16_t dummy12;   /* control and status */
      vuint32_t timestamp; /* control and status */
      vuint16_t dummy18;   /* control and status */
      vuint16_t dummy1A;   /* control and status */
      vuint16_t dumym1C;   /* control and status */
      vuint16_t dummy1E;   /* control and status */
   } eNBUF_Tx;

   struct
   {
      union
      {
         vuint16_t R; /* control and status */
         struct
         { /* PRQA S 0635 ++ */ /* reason for QAC suppression:volatile unsigned short is enough for 16 bits */
            vuint16_t E:1;
            vuint16_t RO1:1;
            vuint16_t W:1;
            vuint16_t RO2:1;
            vuint16_t L:1;
            vuint16_t:2;
            vuint16_t M:1;
            vuint16_t BC:1;
            vuint16_t MC:1;
            vuint16_t LG:1;
            vuint16_t NO:1;
            vuint16_t:1;
            vuint16_t CR:1;
            vuint16_t OV:1;
            vuint16_t TR:1;
         } B;
      } STATUS0;
      vuint16_t length; /* transfer length */
      vuint8_t *data;   /* buffer address */
      union
      {
         vuint16_t R; /* control and status */
         struct
         {
            vuint16_t ME:1;
            vuint16_t:4;
            vuint16_t PE:1;
            vuint16_t CE:1;
            vuint16_t UC:1;
            vuint16_t INT:1;
            vuint16_t:7;
         } B;
      } STATUS8;
      union
      {
         vuint16_t R; /* control and status */
         struct
         {
            vuint16_t VPCP:3;
            vuint16_t:7;
            vuint16_t ICE:1;
            vuint16_t PCR:1;
            vuint16_t:1;
            vuint16_t VLAN:1;
            vuint16_t IPV6:1;
            vuint16_t FRAG:1;
         } B;
      } STATUSA;
      union
      {
         vuint16_t R; /* control and status */
         struct
         {
            vuint16_t HEADER_LEN:5;
            vuint16_t:3;
            vuint16_t PROTOCOL_TYPE:8;
         } B;
      } STATUSC;
      vuint16_t statusE; /* control and status */
      union
      {
         vuint16_t R; /* control and status */
         struct
         {
            vuint16_t BDU:1;
            vuint16_t:15;
         } B;
      } STATUS10;
      vuint16_t dummy12;   /* control and status */
      vuint32_t timestamp; /* control and status */
      vuint16_t dummy18;   /* control and status */
      vuint16_t dummy1A;   /* control and status */
      vuint16_t dumym1C;   /* control and status */
      vuint16_t dummy1E;   /* control and status */
   } eNBUF_Rx;
} Tx_Rx_eNBUF_T;

typedef union CDC_UDP_Payload_Buffer_Tag
{
   vuint8_t UDP_Payload[UDP_MAX_PAYLOAD];
   //   struct
   //   {
   //      vuint8_t  CDC_Header_Bytes[CDC_HEADER_NUM_BYTES];
   // #ifndef CUSTOMER_GWM_SRR5
   //      DL_CDC_RECORD_STRUT_T CDC_BV_Records[CDC_NUM_RECORDS_PER_FRAME];
   // #endif
   //   }
   //   Buf_CDC_UDP_Payload_Struct;
} CDC_UDP_Payload_Buffer_T;

typedef union IPV4_UDP_Tx_Rx_Buffer_Tag
{
   vuint8_t Buf_Bytes[TX_BUFFER_SIZE];
   vuint16_t Buf_Words[TX_BUFFER_SIZE / 2];
   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP1:8;
      vuint16_t IPv4_Src_IP2:8;
      vuint16_t IPv4_Src_IP3:8;
      vuint16_t IPv4_Src_IP4:8;
      vuint16_t IPv4_Dest_IP1:8;
      vuint16_t IPv4_Dest_IP2:8;
      vuint16_t IPv4_Dest_IP3:8;
      vuint16_t IPv4_Dest_IP4:8;
      vuint16_t UDP_Src_Port;
      vuint16_t UDP_Dest_Port;
      vuint16_t UDP_Length;
      vuint16_t UDP_Xsum;
      vuint8_t UDP_Payload[TX_BUFFER_SIZE - PACKET_LEN_BEFORE_UDP_PAYLOAD]; /* IPv4 UDP Frame, 42 bytes before payload */
   } Buf_Struct;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP_UA;
      vuint16_t IPv4_Src_IP_LA;
      vuint16_t IPv4_Dest_IP_UA;
      vuint16_t IPv4_Dest_IP_LA;
      vuint16_t UDP_Src_Port;
      vuint16_t UDP_Dest_Port;
      vuint16_t UDP_Length;
      vuint16_t UDP_Xsum;
      vuint8_t UDP_Payload[RX_BUFFER_SIZE - PACKET_LEN_BEFORE_UDP_PAYLOAD]; /* IPv4 UDP Frame, 42 bytes before payload */
   } Rx_Buf_Struct;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP1:8;
      vuint16_t IPv4_Src_IP2:8;
      vuint16_t IPv4_Src_IP3:8;
      vuint16_t IPv4_Src_IP4:8;
      vuint16_t IPv4_Dest_IP1:8;
      vuint16_t IPv4_Dest_IP2:8;
      vuint16_t IPv4_Dest_IP3:8;
      vuint16_t IPv4_Dest_IP4:8;
      vuint16_t UDP_Src_Port;
      vuint16_t UDP_Dest_Port;
      vuint16_t UDP_Length;
      vuint16_t UDP_Xsum;
      //      vuint8_t  CDC_Header_Bytes[CDC_HEADER_NUM_BYTES];
      // #ifndef CUSTOMER_GWM_SRR5
      //      DL_CDC_RECORD_STRUT_T CDC_BV_Records[CDC_NUM_RECORDS_PER_FRAME];
      // #endif
   } Buf_CDC_Struct;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t Hardware_Type;
      vuint16_t Protocol_Type;
      vuint8_t Hardware_Address_Length; /* 6 for Ethernet */
      vuint8_t Protocol_Address_Length; /* 4 for IPv4 */
      vuint16_t Op_code;
      vuint8_t Sender_Hardware_Address[6];
      vuint32_t Sender_Protocol_Address;
      vuint8_t Target_Hardware_Address[6];
      vuint16_t Target_Protocol_Address_1;
      vuint16_t Target_Protocol_Address_2;
      vuint8_t Unused_1[2];
      vuint8_t Unused_2[TX_BUFFER_SIZE - ARP_PACKET_LENGTH];
   } ARP_Struct;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_type;
      vuint16_t Hardware_Type;
      vuint16_t Protocol_Type;
      vuint8_t Hardware_Address_Length; /*6 for Ethernet */
      vuint8_t Protocol_Address_Length; /* 4 for IPv4 */
      vuint16_t Op_code;
      vuint8_t Sender_Hardware_Address[6];
      vuint32_t Sender_Protocol_Address;
      vuint8_t Target_Hardware_Address[6];
      vuint16_t Target_Protocol_Address_1;
      vuint16_t Target_Protocol_Address_2;
      vuint8_t Unused_1[2];
      vuint8_t Unused_2[RX_BUFFER_SIZE - ARP_PACKET_LENGTH];
   } ARP_format;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP1:8;
      vuint16_t IPv4_Src_IP2:8;
      vuint16_t IPv4_Src_IP3:8;
      vuint16_t IPv4_Src_IP4:8;
      vuint16_t IPv4_Dest_IP1:8;
      vuint16_t IPv4_Dest_IP2:8;
      vuint16_t IPv4_Dest_IP3:8;
      vuint16_t IPv4_Dest_IP4:8;
      vuint16_t UDP_Src_Port;
      vuint16_t UDP_Dest_Port;
      vuint16_t UDP_Length;
      vuint16_t UDP_Xsum;
      vuint8_t XCP_Length[2];
      vuint8_t XCP_Counter[2];
      vuint8_t XCP_Payload[TX_BUFFER_SIZE - PACKET_LEN_BEFORE_XCP_PAYLOAD]; /* 46 bytes before payload */
   } XCP_Struct;
   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP1:8;
      vuint16_t IPv4_Src_IP2:8;
      vuint16_t IPv4_Src_IP3:8;
      vuint16_t IPv4_Src_IP4:8;
      vuint16_t IPv4_Dest_IP1:8;
      vuint16_t IPv4_Dest_IP2:8;
      vuint16_t IPv4_Dest_IP3:8;
      vuint16_t IPv4_Dest_IP4:8;
      vuint16_t UDP_Src_Port;
      vuint16_t UDP_Dest_Port;
      vuint16_t UDP_Length;
      vuint16_t UDP_Xsum;
      XCP_Packet_T xcp_datagroup[122];
      vuint8_t empty[30];
   } XCP_DAQ_Message;

   struct
   {
      vuint8_t Dest_MAC[6];
      vuint8_t Src_MAC[6];
      vuint16_t Ethernet_Type;
      vuint16_t IPv4_Version:4;
      vuint16_t IPv4_IHL:4;
      vuint16_t IPv4_TOS:8;
      vuint16_t IPv4_Length;
      vuint16_t IPv4_FragID;
      vuint16_t IPv4_Flags:3;
      vuint16_t IPv4_FragOffst:13;
      vuint16_t IPv4_TTL:8;
      vuint16_t IPv4_Protocol:8;
      vuint16_t IPv4_HeaderXsum;
      vuint16_t IPv4_Src_IP_UA;
      vuint16_t IPv4_Src_IP_LA;
      vuint16_t IPv4_Dest_IP_UA;
      vuint16_t IPv4_Dest_IP_LA;
      vuint16_t HIL_Src_Port;
      vuint16_t HIL_Dest_Port;
      vuint16_t HIL_Length;
      vuint16_t HIL_Xsum;
      vuint8_t HIL_Payload[TX_BUFFER_SIZE - PACKET_LEN_BEFORE_UDP_PAYLOAD]; /* IPv4 UDP Frame, 42 bytes before payload */
   } HIL_format;

   struct
   {
      vuint8_t HIL_Payload[RX_BUFFER_SIZE];
   } HIL_Data_buffer;

} IPV4_UDP_Tx_Rx_Buffer_T;

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/
extern uint16_t ENET_Logging_Tx_Buf_UNAVBL_Count;
extern uint16_t ENET_CDC_Tx_Buf_UNAVBL_Count;
extern uint16_t ENET_ARP_Tx_Buf_UNAVBL_Count;
extern uint16_t ENET_TxBuffers_Pending_Count;
extern uint16_t ENET_TxBuffers_Pending_Count_MAX;

extern uint8_t UNICAST_MODE_ON;
extern uint8_t BROADCAST_MODE_ON;
extern volatile uint8_t UDP_LAST_STREAM;
extern volatile uint8_t UDP_FIRST_STREAM;
extern uint8_t Prv_Cycle_UDP_BW_USAGE;
extern uint8_t Prv_Cycle_CDC_BW_USAGE;

// extern UDP_Timing_Info_T udp_timing_info[MAX_NO_OF_UDP_TASK];

#define CDC_FIRST_MESSAGE_ID (0x1000)

/*===========================================================================*\
 * Exposed Function Prototypes
\*===========================================================================*/

uint8_t ENET_UDP_Driver_FrameTX(uint8_t *dataBuffer, uint16_t len);

void Initialize_Tx_Rx_Buffer_Size(Tx_Rx_Buffer_T);

#endif /* ENET_UDP_DRIVER_H_ */
