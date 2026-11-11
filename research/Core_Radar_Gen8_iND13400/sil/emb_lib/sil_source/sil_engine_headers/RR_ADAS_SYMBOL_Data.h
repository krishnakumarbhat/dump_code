#ifndef _RR_ADAS_SYMBOL_H_
#define _RR_ADAS_SYMBOL_H_
#include "fixmac.h"
#include <stdio.h>
#define MAX_STRM_COUNT 40
#define MAX_STRM_LEN   12000

#pragma pack(push, 2)
typedef struct UDP_Release_Version_SIL_Tag
{
   uint16_t MajorRevision; /*Modified for weekly releases*/
   uint16_t MinorRevision; /*Modify for customer changes*/
} UDP_Release_Version_SIL_T;
typedef struct UDPRecord_Header__SIL_TAG
{
   /*!
    *  Application Layer Info
    */
   uint16_t versionInfo;   /*  Version of this header specification [set to UDP_RECORD_VERSIONINFO] */
   uint16_t sourceTxCnt;   /*  Incremented on every transmission from this source.  */
   uint32_t sourceTxTime;  /*  Timestamp (ms) when packet queued for transmit. */
   uint8_t Platform;       /*  Constant identifying sending application [0:63], see udp_sources.h.  SRR3 21-24/SRR5+ >40 */
   uint8_t Radar_Position; /*  RL :71 / RR :72 / FR :73 / FL  :74 / RC :75 /  LC :76 */
   uint8_t reservedSrc2;   /*  (Set to zero) */
   uint8_t reservedSrc3;   /*  (Set to zero) */
   /*!
    *  Process Layer Info
    */
   uint32_t streamRefIndex; /*  Stream-specific index used for data retrieval (e.g. Look Index for radar) */
   uint32_t streamDataLen;  /*  Stream data payload size (bytes).  Size for each stream must be constant. */
   uint8_t streamTxCnt;     /*  Increments on each transmission of associated stream number. */
   uint8_t streamNumber;    /*  Stream number [0:31]. One source may transmit multiple, asynchronous streams.  */
   uint8_t streamVersion;   /*  Stream data structure format/version (how to interpret data). */
   uint8_t streamChunks;    /*!< A Stream may be transmitted from the process layer as M equal-size
                                 chunks that can be reconstructed on the receive side.
                                 Set to 0 if transmission is not part of a series of chunks (normal mode).
                                 Set to M (>=2) to indicate stream is sent as a series of M chunks.
                                 NOTE: streamTxCnt must increment for each chunk while streamRefIndex
                                 would be the same for each chunk of a series. */
   uint8_t streamChunkIdx;  /*!< Zero when streamChunks is zero. Otherwise, represents this chunk's
                                 position in the reconstruction queue [0:(streamChunks-1)]. */
   uint8_t customerId;      /*  (Set to zero)    */
} UDPRecord_Header_SIL;
typedef struct UDP_CUST_FRAME_HEADER__SIL_Tag
{
   UDP_Release_Version_SIL_T UDP_Version_info; /* UDP packet number, increments with each single UDP packet */
   u32p0_T utc_time;                           /* Latest UTC time available on Flexray at the middle of the radar dwell */
   u32p0_T timestamp;     /* Time signal based upon an internal clock that is synchronized to the Flexray Signal SC_Masterzeit */
   uint16_t packetnumber; /* UDP packet number, increments with each single UDP packet */
   u8p0_T sensorid;       /* Radar Position */
   u8p0_T sensorstatus;   /* 0 - Sensor working, 1- Sensor blind, 2 - Error */
   u8p0_T detectioncnt;   /* Number of detections in current scan */
   u8p0_T Cal_Running_Cnt;
   u8p0_T Total_Cal_Chunk_Cnt;
   u8p0_T Cal_Source; /* In case of Calib stream this is the Cal Source  */
} UDP_CUST_FRAME_HEADER_SIL_T;
/* Strutcure of the frame that will be part of the payload */
typedef struct CDC_FRAME_STRUCTURE_SIL_Tag
{
   UDPRecord_Header_SIL cdc_frame_header;             /* Header defining the data being transmitted */
   UDP_CUST_FRAME_HEADER_SIL_T cdc_cust_frame_header; /* Customer defined frame header */
} CDC_FRAME_STRUCTURE_SIL_T;
struct UDPRecord_SIL
{
   UDPRecord_Header_SIL header; /*  Record header */
   void *payload;               /*  Data payload */
};
typedef struct RR_ADAS_SYMBOL_Data_Tag
{
   struct UDPRecord_SIL raw_stream[MAX_STRM_COUNT]; // Radar Internal Data
                                                    /*.............*/
} RR_ADAS_SYMBOL_Data_T;
#pragma pack(pop)
#endif
