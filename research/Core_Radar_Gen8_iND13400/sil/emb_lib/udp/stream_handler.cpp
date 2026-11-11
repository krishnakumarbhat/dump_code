/*===========================================================================*\
 * FILE: stream_handler.c
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 *    This module contains the DataLogger implementation.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

#include <string.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "sh_comm.h"
#include "sh_core.h"
#include "sh_module_cfg.h"
#include "sh_tx.h"
#include "sh_types.h"
#include "spbb_cfg.h"
#ifdef VID_STREAM_TX
   #include "vid_stream.h"
#endif
#include "ENET_UDP_Driver.h"
#include "dd_gpt.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED_CHECK(X, Y) (((uintptr_t)(X) & ((sizeof(uintptr_t)) - 1)) | ((uintptr_t)(Y) & ((sizeof(uintptr_t)) - 1)))
/* How many bytes are copied each iteration of the 8X unrolled loop.  */
#define BIGBLOCKSIZE (sizeof(uint32_t) << 3)
/* How many bytes are copied each iteration of the word copy loop.  */
#define LITTLEBLOCKSIZE (sizeof(uint32_t))
/* Threshhold for punting to the byte copier.  */
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)
#define MAX_UINT16     (65535U)

/*===========================================================================*
 * Local Preprocessor #define MACROS & ENUM
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Imported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/
Record_Queue_T DL_Send_Queue[STREAM_QUEUE_SIZE];
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static uint16_t Source_Tx_Cnt     = 0U;
static uint32_t Frame_Failure_Cnt = 0U;
/* If it's local, need more 2k of stack, else core-freezes.
However, no improvement seen in timing, on storing it in stack. */
static Rec_Frame_T Frame_Buf;
#if defined(SH_ENABLE_REGULAR_FAST_STREAM)
static Streaming_Radar_Input_T Streaming_Radar_Input = {0};
#endif
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static Rec_Frame_T *Get_Frame_Buffer(void);
static uint16_t Get_RecordID_From_Queue(uint16_t id);
#if (defined(SH_ENABLE_REGULAR_FAST_STREAM) && ENABLE_RF_STREAM_TESTCODE)
static void Update_RF_Stream_Debug_Data(RF_Stream_Debug_T rf_stream_debug);
#endif
static uint8_t *Get_Data_Ptr_From_Queue(uint16_t id);
#if defined(CDC_TOTAL_CHUNKS_CURRENT_CYCLE)
static uint8_t Check_CDC_Last_Chunk_Flag_of_Current_Cycle(Rec_Frame_T *frame_ptr);
#else
static uint16_t Get_CDC_Total_Chunks_Of_Prev_Cycle(Rec_Frame_T *frame_ptr);
#endif
#if defined(SH_ENABLE_CALIB_STREAM)
static inline uint16_t Get_Stream_Index_From_Id(uint16_t stream_id);
#endif
static uint8_t Send_Stream_Chunk(Rec_Hdl_T *rec_hdl_ptr, uint8_t *src_ptr, uint32_t scan_index, uint16_t payload_len,
                                 uint16_t idx);
static bool Check_Stream_Selected_In_Bitfield(uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/******************************************************************************
 *. Name: Get_Frame_Buffer
 *.    returns the address of frame buffer
 *.
 *. Parameters: void
 *. Return Value: Rec_Frame_T*
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static Rec_Frame_T *Get_Frame_Buffer(void)
{
   return (&Frame_Buf);
}

/******************************************************************************
 *. Name: Get_RecordID_From_Queue
 *.    returns the rec id
 *.
 *. Parameters: uint16_t id
 *. Return Value: uint16_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint16_t Get_RecordID_From_Queue(uint16_t id)
{
   return (DL_Send_Queue[id].rec_id);
}

#if defined(SH_ENABLE_CALIB_STREAM)
/******************************************************************************
 *. Name: Get_Stream_Index_From_Id
 *.    returns the stream enum number from the ID
 *.    considering the varying number of Calibration streams
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static inline uint16_t Get_Stream_Index_From_Id(uint16_t stream_id)
{
   uint16_t stream_enum;
   if (stream_id <= CALIB)
   {
      stream_enum = stream_id;
   }
   else if (stream_id <= (CALIB + (MAX_CAL_SOURCE - 1U))) /* Stream_Id > CALIB */
   {
      stream_enum = CALIB;
   }
   else /* Stream_Id > ((CALIB + (MAX_CAL_SOURCE - 1))) */
   {
      stream_enum = (stream_id - ((MAX_CAL_SOURCE)-1U));
   }
   return stream_enum;
}

#endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 *. Name: Get_Source_Tx_Cnt(void)
 *.    Function to get Source_Tx_Cnt value
 *.
 *. Parameters: void
 *. Return Value: uint16_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint16_t Get_Source_Tx_Cnt(void)
{
   return (Source_Tx_Cnt);
}

/******************************************************************************
 *. Name: memcpy_aligned(void *dst_ptr, const void *src_ptr, uint32_t len)
 *.    Same as memcpy but utilises possibility to copy 4 bytes at once.
 *.
 *. Parameters: void *dst_ptr, const void *src_ptr, uint32_t len
 *. Return Value: void *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void *memcpy_aligned(void *__restrict dst0, const void *__restrict src0, size_t len0)
{
   uintptr_t dst = (uintptr_t)dst0;
   uintptr_t src = (uintptr_t)src0;

   uint8_t *b_dst       = (uint8_t *)dst0;
   const uint8_t *b_src = (const uint8_t *)src0;

   uint32_t *aligned_dst;
   const uint32_t *aligned_src;

   /* If the size is small, or either SRC or DST is unaligned,
      then punt into the byte copy loop.  This should be rare.  */
   if (!TOO_SMALL(len0) && !UNALIGNED_CHECK(src, dst))
   {
      aligned_dst = (uint32_t *)dst;
      aligned_src = (uint32_t *)src;

      /* Copy 8X long words at a time if possible.  */
      while (len0 >= BIGBLOCKSIZE)
      {
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;
         *aligned_dst++ = *aligned_src++;

         len0 -= BIGBLOCKSIZE;
      }

      /* Copy one long word at a time if possible.  */
      while (len0 >= LITTLEBLOCKSIZE)
      {
         *aligned_dst++ = *aligned_src++;
         len0 -= LITTLEBLOCKSIZE;
      }

      b_dst = (uint8_t *)aligned_dst;
      b_src = (const uint8_t *)aligned_src;
   }
   /* Pick up any residual with a byte copier.  */

   while (len0--)
      *b_dst++ = *b_src++;

   return dst0;
}

/******************************************************************************
 *. Name: Pop_Stream_From_Queue
 *.    After attempting to send specific stream it is removed from queue by this function
 *.
 *. Parameters:  stream_idx :
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-1626
 ******************************************************************************/
static void Pop_Stream_From_Queue(uint16_t stream_idx)
{
   /* Invoking atomic section to prevent concurrent access */
   DISABLE_ALL_INTERRUPTS();
   DL_Send_Queue[stream_idx].rec_id   = REC_HANDLER_EMPTY;
   DL_Send_Queue[stream_idx].data_ptr = NULL;
   ENABLE_ALL_INTERRUPTS();
}

/******************************************************************************
 *. Name: Overwrite_Stream_On_Queue
 *.    Before attempting to send specific stream it is overwritten on the queue by this function
 *.
 *. Parameters: uint16_t id : id of the stream to modify
                       uint8_t *buf_ptr : pointer to source that is to be logged out
 *. Return Value: uint8_t ret_val
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-1626
 ******************************************************************************/
uint8_t Overwrite_Stream_On_Queue(uint16_t id, uint8_t *buf_ptr)
{
   uint16_t stream_idx = 0U;
   /*stream ID is already checked and is valid but still unable to overwrite on the queue.
   Ideally this shall not occur.*/
   uint8_t ret_val = (uint8_t)REC_HANDLER_NOT_FOUND_IN_Q;

   for (stream_idx = 0; stream_idx < STREAM_QUEUE_SIZE; stream_idx++)
   {
      if (Get_RecordID_From_Queue(stream_idx) == id)
      {
         if (NULL != DL_Send_Queue[stream_idx].data_ptr)
         {
            DISABLE_ALL_INTERRUPTS();
            /*Needs to be overwritten as same id is passed*/
            DL_Send_Queue[stream_idx].rec_id = id;
            /*Assigned actual address*/
            DL_Send_Queue[stream_idx].data_ptr = buf_ptr;
            ENABLE_ALL_INTERRUPTS();
            ret_val = (uint8_t)REC_HANDLER_OVERWRITE;
         }
         else
         {
            /* Give error code */
            ret_val = (uint8_t)REC_HANDLER_Q_CORRUPT;
         }

         break;
      }
   }

   return (ret_val);
}

/******************************************************************************
 *. Name: Push_Stream_On_Queue
 *.    send specific stream.
 *.
 *. Parameters: uint16_t id : id of the stream to modify,
                       uint8_t *buf_ptr : pointer to source that is to be logged out
 *. Return Value: uint8_t ret_val
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-1626
 ******************************************************************************/
uint8_t Push_Stream_On_Queue(uint16_t id, uint8_t *buf_ptr)
{
   uint16_t stream_idx = 0U;
   /*Unable to find an empty slot in the queue*/
   uint8_t ret_val = (uint8_t)REC_HANDLER_Q_FULL;

   for (stream_idx = 0; stream_idx < STREAM_QUEUE_SIZE; stream_idx++)
   {
      if (Get_RecordID_From_Queue(stream_idx) == REC_HANDLER_EMPTY)
      {
         if (NULL == DL_Send_Queue[stream_idx].data_ptr)
         {
            DISABLE_ALL_INTERRUPTS();
            DL_Send_Queue[stream_idx].rec_id   = id;
            DL_Send_Queue[stream_idx].data_ptr = buf_ptr; /*Assigned actual address*/
            ENABLE_ALL_INTERRUPTS();
            ret_val = REC_HANDLER_OK;
         }
         else
         {
            /* Give error code */
            ret_val = (uint8_t)REC_HANDLER_Q_CORRUPT;
         }
         /* Either added successfully or queue is corrupted, so break out of loop */
         break;
      }
   }

   return (ret_val);
}

#if defined(CDC_TOTAL_CHUNKS_CURRENT_CYCLE)
/******************************************************************************
 *. Name: Set_CDC_Last_Chunk_Flag_Of_Current_Cycle
 *.    set the CDC last chunk flag to indicate the last chunk of CDC stream.
 *.
 *. Parameters:  void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DNP-5599
 ******************************************************************************/
void Set_CDC_Last_Chunk_Flag_Of_Current_Cycle(void)
{
   CDC_Last_Chunk_Flag = CODED_TRUE;
}

/******************************************************************************
 *. Name: Check_CDC_Last_Chunk_Flag_of_Current_Cycle
 *.    check the CDC last chunk flag is enabled or disabled.
 *.
 *. Parameters:  Rec_Frame_T * : pointer to the source
 *. Return Value: uint8_t CDC_Last_Chunk_Flag
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DNP-5599
 ******************************************************************************/
static uint8_t Check_CDC_Last_Chunk_Flag_of_Current_Cycle(Rec_Frame_T *frame_ptr)
{
   static uint32_t prev_scanindex = 0U;

   /* check the radar cycle change through scanindex */
   if (prev_scanindex == frame_ptr->rec_hdr.streamRefIndex)
   {
      /*do nothing*/
   }
   else
   {
      prev_scanindex      = frame_ptr->rec_hdr.streamRefIndex; /* Update scanindex*/
      CDC_Last_Chunk_Flag = CODED_FALSE;                       /* reset the flag if scanindex changed*/
   }

   return (CDC_Last_Chunk_Flag); /*return CDC last chunk flag value*/
}
#else
/******************************************************************************
 *. Name: Get_CDC_Total_Chunks_Of_Prev_Cycle
 *.    Count the chunks of CDC stream for Previous Radar cycle and send counts to current Radar cycle.
 *.
 *. Parameters:  Rec_Frame_T * : pointer to the source
 *. Return Value: uint16_t l_cdc_total_chunks
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DNP-4883
 ******************************************************************************/
static uint16_t Get_CDC_Total_Chunks_Of_Prev_Cycle(Rec_Frame_T *frame_ptr)
{
   static uint16_t prev_scanindex   = 0U;
   static uint16_t cdc_chunk_count  = 0U;
   static uint16_t cdc_total_chunks = 0U;

   /* check the radar cycle change through scanindex */
   if (prev_scanindex == frame_ptr->rec_hdr.streamRefIndex)
   {
      cdc_chunk_count++; /* Increment chunk counter */
   }
   else
   {
      prev_scanindex   = frame_ptr->rec_hdr.streamRefIndex; /* Update scanindex*/
      cdc_total_chunks = cdc_chunk_count;                   /* Update prev cycle CDC total chunks*/
      cdc_chunk_count  = 1U;                                /* Update chunk counter with default one chunk*/
   }

   return cdc_total_chunks;
}
#endif

/******************************************************************************
 *. Name: Get_Data_Ptr_From_Queue
 *.    returns the address of data-ptr from queue
 *.
 *. Parameters: uint16_t id
 *. Return Value: uint8_t *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t *Get_Data_Ptr_From_Queue(uint16_t id)
{
   return (DL_Send_Queue[id].data_ptr);
}

/******************************************************************************
 *. Name: Check_Stream_Selected_In_Bitfield
 *.    Check if a stream is enabled in the bitfield.
 *.
 *. Parameters: uint8_t stream_num, uint32_t *stream_num_bitfield_ptr
 *. Return Value: bool
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static bool Check_Stream_Selected_In_Bitfield(uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr)
{
   bool ret_val         = false;
   uint8_t bitfield_idx = stream_num / STREAM_NUM_BITFIELD_WORD_BITS;

   if (NULL == stream_num_bitfield_ptr)
   {
      /* invalid pointer, treat as not selected */
      ret_val = false;
   }
   else if (stream_num_bitfield_ptr[0] & ALL_STREAMS_BITMASK)
   {
      /* bit0 of word0 indicates "ALL streams" */
      ret_val = true;
   }
   else
   {
      /* Stream_Table bounds stream_num, so bitfield_idx is already handled; check the bit corresponding to stream_num. */
      ret_val = ((stream_num_bitfield_ptr[bitfield_idx] & (1U << (stream_num % STREAM_NUM_BITFIELD_WORD_BITS))) != 0U);
   }

   return ret_val;
}

/******************************************************************************
 *. Name: Send_Stream_Chunk
 *.    Updates the record header and calls out ethernet driver
 *.
 *. Parameters: Rec_Hdl_T *rec_hdl_ptr
 *.             uint8_t *src_ptr
.*.             uint32_t scan_index
 *.             uint16_t payload_len
 *.             uint16_t idx
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
DISABLE_OPTIMIZATION
static uint8_t Send_Stream_Chunk(Rec_Hdl_T *rec_hdl_ptr, uint8_t *src_ptr, uint32_t scan_index, uint16_t payload_len, uint16_t idx)
{
   SH_Input_T *sh_input_data_ptr           = Get_SH_Input_Data_Ptr();
   Stream_Handler_Init_Params_T *sh_ip_ptr = Get_Stream_Handler_Init_Params();
   Rec_Frame_T *frame_ptr                  = Get_Frame_Buffer();
   Stream_Rec_T *rec_ptr;
   Stream_Type_T stream_type;
   uint8_t stream_number;
   uint8_t ret_val;
   Tx_Frame_Param_T tx_frame_param;
   uint64_t source_tx_time_us = 0U;

   if (payload_len > 0U)
   {
      rec_ptr       = rec_hdl_ptr->rec_ptr;
      stream_number = rec_ptr->rec_hdr.streamNumber;
      stream_type   = (Stream_Type_T)rec_hdl_ptr->stream_type;

      if (payload_len < REC_PAYLOAD)
      {
         /* Clear the unused space in Buffer before populating any data */
         (void)memset(&frame_ptr->payload[payload_len], 0, (REC_PAYLOAD - payload_len));
      }

      /* Copy data into the frame */
      (void)memcpy_aligned(&frame_ptr->payload[0], src_ptr, payload_len);

      /* static header info */
      frame_ptr->rec_hdr.versionInfo   = rec_ptr->rec_hdr.versionInfo;
      frame_ptr->rec_hdr.streamNumber  = rec_ptr->rec_hdr.streamNumber;
      frame_ptr->rec_hdr.streamVersion = rec_ptr->rec_hdr.streamVersion;
      frame_ptr->rec_hdr.sourceInfo    = rec_ptr->rec_hdr.sourceInfo;
      frame_ptr->rec_hdr.sourceInfo1   = rec_ptr->rec_hdr.sourceInfo1;
      frame_ptr->rec_hdr.sourceInfo2   = rec_ptr->rec_hdr.sourceInfo2;
      frame_ptr->rec_hdr.streamChunks  = rec_ptr->rec_hdr.streamChunks;

#if (0xA5 == REC_VER)
      frame_ptr->rec_hdr.sensorId             = rec_ptr->rec_hdr.sensorId;
      frame_ptr->rec_hdr.streamChunksPerCycle = rec_ptr->rec_hdr.streamChunksPerCycle;
#else
      frame_ptr->rec_hdr.customerId     = rec_ptr->rec_hdr.customerId;
      frame_ptr->rec_hdr.sensorPosition = rec_ptr->rec_hdr.sensorPosition;
      frame_ptr->rec_hdr.reservedSrc2   = rec_ptr->rec_hdr.reservedSrc2;
      frame_ptr->rec_hdr.reservedSrc3   = rec_ptr->rec_hdr.reservedSrc3;
#endif

      /* dynamic header info */
      frame_ptr->rec_hdr.streamRefIndex = scan_index;
      frame_ptr->rec_hdr.streamDataLen  = payload_len;
      frame_ptr->rec_hdr.streamTxCnt    = (uint8_t)rec_hdl_ptr->txcount;
      frame_ptr->rec_hdr.sourceTxCnt    = Source_Tx_Cnt;
      frame_ptr->rec_hdr.streamChunkIdx = idx;

      if (STREAM_DYNAMIC == stream_type)
      {
#if defined(CDC_TOTAL_CHUNKS_CURRENT_CYCLE)
         if (CODED_TRUE == Check_CDC_Last_Chunk_Flag_of_Current_Cycle(frame_ptr))
         {
            frame_ptr->rec_hdr.streamDataLen = 0U; /*assigned zero as per APTIV Header 6.4 version*/
         }
         frame_ptr->rec_hdr.streamChunks =
            (uint16_t)((SPBB_MAX_CDC_DBIN_COUNT_PER_FRAME / TOTAL_CDC_RECORDS_PER_FRAME) + ONE_FRAME +
                       LAST_FRAME_INDICATION_CNT); /*assigned MAX CDC chunks as per APTIV Header 6.4 version*/
#else
         frame_ptr->rec_hdr.streamChunks = Get_CDC_Total_Chunks_Of_Prev_Cycle(frame_ptr);
#endif
      }
      sh_input_data_ptr->ustime_logging_fptr(&source_tx_time_us);
      frame_ptr->rec_hdr.sourceTxTime = (uint32_t)(source_tx_time_us * US_T0_MS); // Get_Source_Tx_Time();

      /* increment the stream tx counter */
      rec_hdl_ptr->txcount++;
#if (defined(SH_ENABLE_REGULAR_FAST_STREAM) && ENABLE_RF_STREAM_TESTCODE)
      /* Update debug information only when ENABLE_RF_STREAM_TESTCODE is enabled */
      Update_RF_Stream_Debug_Data(frame_ptr->rec_hdr);
#endif

      /* increment the source tx counter */
      Source_Tx_Cnt++;

      /* Call the driver to transmit frame */
      tx_frame_param.frame_ptr     = frame_ptr;
      tx_frame_param.stream_type   = stream_type;
      tx_frame_param.stream_number = stream_number;
      ret_val                      = ENET_UDP_Driver_FrameTX((uint8_t *)frame_ptr, sizeof(Rec_Frame_T));
   }
   else
   {
      /* payload_len is zero */
      ret_val = (uint8_t)REC_HANDLER_WRONG_PAYLOAD_LEN;
   }
   return (ret_val);
}
ENABLE_OPTIMIZATION
/******************************************************************************
 *. Name: Send_Stream_From_Queue
 *.    Function to send logging streams via queue.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Send_Stream_From_Queue(void)
{
   uint16_t *stream_failures_ptr;
   uint16_t stream_id;
   uint16_t stream_enum;
   uint16_t stream_idx;
   uint8_t frame_failure = REC_HANDLER_OK;
   uint8_t *base_ptr;
   uint16_t chunk_start = 0U;
   uint16_t chunk_end   = 0U;

   for (stream_idx = 0; stream_idx < STREAM_QUEUE_SIZE; stream_idx++)
   {
      stream_id = Get_RecordID_From_Queue(stream_idx);

      if (REC_HANDLER_EMPTY != stream_id)
      {
         /* Placeholder in queue for getting multiple frame data for single stream */
         base_ptr = Get_Data_Ptr_From_Queue(stream_idx);
         if (NULL == base_ptr)
         {
            frame_failure = (uint8_t)REC_HANDLER_Q_CORRUPT;
         }
         else
         {
            /* send out the stream */
            frame_failure = Send_Stream(stream_id, base_ptr, chunk_start, chunk_end);
         }

         if (REC_HANDLER_OK != frame_failure)
         {
#if defined(SH_ENABLE_CALIB_STREAM)
            stream_enum = Get_Stream_Index_From_Id(stream_id);
#else
            stream_enum = stream_id;
#endif
            stream_failures_ptr = Get_Stream_Fail_Ptr((uint8_t)stream_enum);
            (*stream_failures_ptr)++;
         }

         /*The queue has to be updated -> if all chunks are transmitted or there's an error.*/
         Pop_Stream_From_Queue(stream_idx);
      }
   }
}

#if defined(SH_ENABLE_REGULAR_FAST_STREAM)
/******************************************************************************
 *. Name: Update_Streaming_Radar_Input(Streaming_Radar_Input_T *sh_ip)
 *.    Update the inputs for Regular Fast streams
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Update_Streaming_Radar_Input(Streaming_Radar_Input_T *rf_stream_ip)
{
   memcpy_aligned(Streaming_Radar_Input.stream_chunks, rf_stream_ip->stream_chunks, sizeof(Streaming_Radar_Input_T));
   Streaming_Radar_Input.chunk_size_factor  = rf_stream_ip->chunk_size_factor;
   Streaming_Radar_Input.header_size_offset = rf_stream_ip->header_size_offset;
}

/******************************************************************************
 *. Name: Get_Streaming_Radar_Input(void)
 *.    Get the inputs for Stream Handler
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Streaming_Radar_Input_T *Get_Streaming_Radar_Input(void)
{
   return &Streaming_Radar_Input;
}
   #if ENABLE_RF_STREAM_TESTCODE
/******************************************************************************
 *. Name: Get_RF_Stream_Debug_Data(void)
 *.    Share test variable for debugging RF stream
 *.
 *. Parameters: void
 *. Return Value: RF_Stream_Debug_T *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
volatile RF_Stream_Debug_T *Get_RF_Stream_Debug_Data(void)
{
   return &test_rf_stream_debug;
}

/******************************************************************************
 *. Name: Update_RF_Stream_Debug_Data(void)
 *.    Copy data into the test variable for debugging RF stream
 *.
 *. Parameters: void
 *. Return Value: RF_Stream_Debug_T *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Update_RF_Stream_Debug_Data(RF_Stream_Debug_T rf_stream_debug)
{
   memcpy_aligned((void *)&test_rf_stream_debug, &rf_stream_debug, sizeof(RF_Stream_Debug_T));
}
   #endif
#endif

/******************************************************************************
 *. Name: Send_Stream
 *.    Function to send logging streams.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
DISABLE_OPTIMIZATION
uint8_t Send_Stream(uint16_t rec_id, uint8_t *base_ptr, uint16_t chunk_start, uint16_t chunk_end)
{
   uint8_t frame_sent_status_int = REC_HANDLER_OK;
   SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();
   frame_sent_status_int         = sh_input_data_ptr->send_stream_internal_fptr(rec_id, base_ptr, chunk_start, chunk_end);
   return frame_sent_status_int;
}

/******************************************************************************
 *. Name: Send_Stream_Internal
 *.   Trusted call function to send logging streams.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Send_Stream_Internal(uint16_t rec_id, uint8_t *base_ptr, uint16_t chunk_start, uint16_t chunk_end)
{
#if defined(SH_ENABLE_REGULAR_FAST_STREAM)
   Streaming_Radar_Input_T *sr_ip_ptr = Get_Streaming_Radar_Input();
   uint8_t look_id                    = 0U;
#endif
   uint32_t radar_scan_index = 0U;
   uint16_t payload_len;
   uint16_t idx;
   uint16_t rem_bytes;
   /* max_chunks - indicates the no of chunks sent together in this function call*/
   uint16_t max_chunks;
   uint16_t complete_chunks;
/*streamChunks indicates total chunks in that stream*/
/*prev_chunk_idx needed specifically for dynamic streams to keep tab on previously ended streamChunkIdx value */
#if (0xA5 == REC_VER)
   uint16_t streamChunks;
   uint16_t prev_chunk_idx;
#else
   uint8_t streamChunks;
   uint8_t prev_chunk_idx;
#endif
   uint8_t frame_sent_status = REC_HANDLER_OK;
   uint8_t stream_type       = (uint8_t)MAX_STREAM_TYPES;
   bool is_static_stream     = false;

   uint8_t *running_ptr;
   Stream_Rec_T *rec_ptr;
   Rec_Hdl_T *rec_hdl_ptr;

#ifdef TRACKER_ENABLED
   bool is_tracker_static_stream = false;
#endif
   rec_hdl_ptr = Get_Rec_Hdl_Ptr(rec_id);

   if ((uint8_t)STREAM_STATE_READY == rec_hdl_ptr->state)
   {
      rec_ptr = rec_hdl_ptr->rec_ptr;
#ifdef TRACKER_ENABLED
      is_tracker_static_stream = ((rec_ptr->rec_hdr.streamNumber >= SYNC_INFO_STREAM_NUMBER) &&
                                  (rec_ptr->rec_hdr.streamNumber <= INTERNAL_CWD_STREAM_NUMBER));
#endif
      DISABLE_ALL_INTERRUPTS();
      rec_hdl_ptr->state = (uint8_t)STREAM_STATE_SENDING;
      ENABLE_ALL_INTERRUPTS();
      /*Number of frames/chunks required for the logging structure*/
      rem_bytes    = (uint16_t)(rec_hdl_ptr->length % REC_PAYLOAD);
      streamChunks = rec_ptr->rec_hdr.streamChunks;

      if (rec_ptr->rec_hdr.streamChunks > 0U)
      {
         payload_len = REC_PAYLOAD;

         stream_type = rec_hdl_ptr->stream_type;
         switch (stream_type)
         {
            case (uint8_t)STREAM_DYNAMIC:
            {
               /*The initial structure in payload is Stream_Hdr_T.*/
               radar_scan_index = ((Dyn_Hdr_T *)base_ptr)->scan_index;

               if (rec_hdl_ptr->ref_idx != radar_scan_index)
               {
                  rec_hdl_ptr->ref_idx            = radar_scan_index;
                  rec_ptr->rec_hdr.streamChunkIdx = 0U;
               }
               is_static_stream = false;
               /* send all chunks in a cycle */
               max_chunks     = streamChunks;
               idx            = 0;
               prev_chunk_idx = rec_ptr->rec_hdr.streamChunkIdx;
               break;
            }

            case (uint8_t)STREAM_REGULAR:
            case (uint8_t)STREAM_REGULAR_FAST:
            {
               /*The initial structure in payload is Stream_Hdr_T.*/
               radar_scan_index = ((Stream_Hdr_T *)base_ptr)->scan_index;
               is_static_stream = false;
#ifdef TRACKER_ENABLED
               if (is_tracker_static_stream)
               {
                  SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();

                  if ((NULL != sh_input_data_ptr) && (NULL != sh_input_data_ptr->tracker_ref_index_fptr))
                  {
                     radar_scan_index = sh_input_data_ptr->tracker_ref_index_fptr();
                  }
               }
#endif
               /* send all chunks in a cycle */
               max_chunks     = streamChunks;
               idx            = rec_ptr->rec_hdr.streamChunkIdx;
               prev_chunk_idx = 0U;
               break;
            }

               // case STREAM_REGULAR_FAST:
               //{
               //   /*The initial structure in payload is Stream_Hdr_T.*/
               //   radar_scan_index = ((Rf_Dyn_Hdr_T *)base_ptr)->scan_index;
               //   /*rem_bytes =
               //      (((Rf_Dyn_Hdr_T *)base_ptr)->records_cnt * sr_ip_ptr->chunk_size_factor) + sr_ip_ptr->header_size_offset;*/
               //   is_static_stream = false;

               //   look_id                       = ((Rf_Dyn_Hdr_T *)base_ptr)->look_id;
               //   rec_ptr->rec_hdr.streamChunks = sr_ip_ptr->stream_chunks[look_id];

               //   if (rec_hdl_ptr->ref_idx != radar_scan_index)
               //   {
               //      rec_hdl_ptr->ref_idx            = radar_scan_index;
               //      rec_ptr->rec_hdr.streamChunkIdx = 0U;
               //   }

               //   /* send 1 chunk per function call */
               //   streamChunks   = 1U;
               //   max_chunks     = streamChunks;
               //   idx            = 0U;
               //   prev_chunk_idx = rec_ptr->rec_hdr.streamChunkIdx;
               //   break;
               //}

            case (uint8_t)STREAM_STATIC:
            {
               radar_scan_index = rec_hdl_ptr->ref_idx;
               is_static_stream = true;

               /* send only certain no. of chunks in a cycle */
               max_chunks     = (uint16_t)(rec_ptr->rec_hdr.streamChunkIdx + rec_hdl_ptr->chunks_per_cycle);
               idx            = rec_ptr->rec_hdr.streamChunkIdx;
               prev_chunk_idx = 0U;
               break;
            }

            default:
            {
               radar_scan_index = 0xFFU;
               is_static_stream = false;

               max_chunks        = 1U;
               frame_sent_status = (uint8_t)REC_HANDLER_NOT_OK;
               idx               = 0xFFU;
               prev_chunk_idx    = 0U;
               break;
            }
         }

         /*Complete chunks indicate the no of ethernet frames with full payload.
         Out of total 'n' chunks in a stream, (n-1) will have full payload and is sent directly via the for loop below*/
         complete_chunks = (uint16_t)(max_chunks - 1U);

         for (; idx < complete_chunks; idx++)
         {
            /* offset as per the frame/payload len */
            running_ptr = (uint8_t *)(&base_ptr[idx * payload_len]);

            /* send frames */
            frame_sent_status = Send_Stream_Chunk(rec_hdl_ptr, running_ptr, radar_scan_index, payload_len, (idx + prev_chunk_idx));
            if (REC_HANDLER_OK != frame_sent_status)
            {
               /* Stop sending sub frames, break the loop and retry in next cycle *
                  Should this be captured for debugging purpose? */
               break;
            }
         }

         /*Use the idx value as assigned by the for-loop OR finally incremented value when exited out of it successfully*/
         if ((REC_HANDLER_OK == frame_sent_status))
         {
            /* offset as per the frame/payload len */
            running_ptr = (uint8_t *)(&base_ptr[idx * payload_len]);

            if (idx == streamChunks - 1U)
            {
               /* Last chunk of the multi chunk stream OR single chunk stream */
               payload_len = (rem_bytes > 0U) ? rem_bytes : REC_PAYLOAD;
            }

            /* send last frame */
            frame_sent_status = Send_Stream_Chunk(rec_hdl_ptr, running_ptr, radar_scan_index, payload_len, (idx + prev_chunk_idx));
            /*Increment idx for further comparisons below*/
            idx++;
         }

         if ((idx == streamChunks) && (REC_HANDLER_OK == frame_sent_status))
         {
            /* successfully sent all chunks */
            Frame_Failure_Cnt = 0U;

            if ((STREAM_DYNAMIC == (Stream_Type_T)stream_type) /* || (STREAM_REGULAR_FAST == stream_type)*/)
            {
               rec_ptr->rec_hdr.streamChunkIdx += idx;
            }
            else
            {
               rec_ptr->rec_hdr.streamChunkIdx = 0U;
            }

            if (is_static_stream)
            {
               if ((MAX_UINT16 > rec_hdl_ptr->ref_idx) /*due to radar scanindex will be uint16_t so maintaining the limit for
                                                          Static stream.*/
#ifdef TRACKER_ENABLED
                   && (!is_tracker_static_stream)
#endif
               )
               {
                  rec_hdl_ptr->ref_idx++;
               }
               else
               {
                  rec_hdl_ptr->ref_idx = 0;
               }
            }

            Clr_Stream_Err(rec_hdl_ptr->id);
         }
         else
         {
            if ((idx != max_chunks) || (REC_HANDLER_OK != frame_sent_status))
            {
               /* stream sending failed */
               Frame_Failure_Cnt++;

               /* capture the failure */
               Set_Stream_Err(rec_hdl_ptr->id);

               /* reset the chunk index for next cycle*/
               rec_ptr->rec_hdr.streamChunkIdx = 0U;
               if (is_static_stream)
               {
                  if ((MAX_UINT16 > rec_hdl_ptr->ref_idx) /*due to radar scanindex will be uint16_t so maintaining the limit for
                                                             Static stream.*/
#ifdef TRACKER_ENABLED
                      && (!is_tracker_static_stream)
#endif
                  )
                  {
                     rec_hdl_ptr->ref_idx++;
                  }
                  else
                  {
                     rec_hdl_ptr->ref_idx = 0;
                  }
               }
            }
            else
            {
               /* successfully sent configured number of chunks */
               Frame_Failure_Cnt = 0U;
               Clr_Stream_Err(rec_hdl_ptr->id);

               rec_ptr->rec_hdr.streamChunkIdx = idx;
            }
            Latch_Stream_Err();
         }
      } /* rec_ptr->rec_hdr.streamChunks */

      rec_hdl_ptr->state = (uint8_t)STREAM_STATE_IDLE;
   }
   else
   {
      frame_sent_status = (uint8_t)REC_HANDLER_INCORRECT_STATE;
   }
   return (frame_sent_status);
}
ENABLE_OPTIMIZATION

/******************************************************************************
 *. Name: Apply_Stream_Enable_Config
 *.    Enable/Disable a stream at runtime by updating both the configuration
 *.    (`stream_ena`) and the live handler state (`Rec_Hdl_T`).
 *.
 *. Parameters: uint32_t *stream_num_bitfield_ptr, uint8_t stream_ena
 *. Return Value: uint8_t
 *.
 *. Notes:
 *.   - If disabling, any queued entries for the stream are removed.
 *.   - If a stream is currently sending, it is not force-aborted; the enable
 *.     flag prevents future triggers.
 ******************************************************************************/
uint8_t Apply_Stream_Enable_Config(volatile uint32_t *stream_num_bitfield_ptr, uint8_t stream_ena)
{
   uint8_t ret_val = REC_HANDLER_INVALID_ID;
   uint8_t table_idx;
   uint8_t sub_idx;
   uint8_t sub_stream_cnt;
   Stream_Info_T *stream_info_ptr;

   for (table_idx = 0U; table_idx < (uint8_t)MAX_NUM_STRMS; table_idx++)
   {
      if (Check_Stream_Selected_In_Bitfield(Stream_Table[table_idx].stream_num, stream_num_bitfield_ptr))
      {
         sub_stream_cnt  = Stream_Table[table_idx].sub_stream_cnt;
         stream_info_ptr = Stream_Table[table_idx].stream_info_ptr;

         for (sub_idx = 0U; sub_idx < sub_stream_cnt; sub_idx++)
         {
            uint16_t stream_rec_id;

            stream_info_ptr[sub_idx].stream_ena = stream_ena;

            if ((uint8_t)STREAM_INIT == Stream_Table[table_idx].stream_mode)
            {
               stream_rec_id = stream_info_ptr[sub_idx].stream_rec_id;
               if (stream_rec_id < NUM_OF_STREAMS)
               {
                  Rec_Hdl_T *rec_hdl_ptr = Get_Rec_Hdl_Ptr(stream_rec_id);

                  if ((uint8_t)0U == stream_ena)
                  {
                     DISABLE_ALL_INTERRUPTS();
                     rec_hdl_ptr->enable = 0U;
                     if (STREAM_STATE_SENDING != rec_hdl_ptr->state)
                     {
                        rec_hdl_ptr->state = STREAM_STATE_DISABLE;
                     }
                     else
                     {
                        /* do nothing*/
                     }
                     ENABLE_ALL_INTERRUPTS();

                     Pop_Stream_From_Queue(Stream_Table[table_idx].stream_idx); /* remove any queued entries for the stream */
                  }
                  else
                  {
                     DISABLE_ALL_INTERRUPTS();
                     rec_hdl_ptr->enable = 1U;
                     if (STREAM_STATE_DISABLE == rec_hdl_ptr->state)
                     {
                        rec_hdl_ptr->state = STREAM_STATE_IDLE;
                     }
                     ENABLE_ALL_INTERRUPTS();
                  }
               }
               else
               {
                  /*do nothing*/
               }
            }
            else
            {
               /*do nothing*/
            }
         }

         ret_val = REC_HANDLER_OK;
      }
      else
      {
         /* do nothing */
      }
   }

   return ret_val;
}

#if defined(UNIT_TEST)
bool Check_Stream_Selected_In_Bitfield_For_UT(uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr)
{
   return Check_Stream_Selected_In_Bitfield(stream_num, stream_num_bitfield_ptr);
}

uint8_t Send_Stream_Chunk_For_UT(Rec_Hdl_T *rec_hdl_ptr, uint8_t *src_ptr, uint32_t scan_index, uint16_t payload_len, uint16_t idx)
{
   return Send_Stream_Chunk(rec_hdl_ptr, src_ptr, scan_index, payload_len, idx);
}
#endif

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
