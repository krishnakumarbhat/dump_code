/*===========================================================================*/
/**
 * @file sh_core.c
 *
 * Provides the implementation for stream handling.
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains the stream handler core functionality.
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "sh_core.h"
#include "sh_comm.h"
#include "sh_error.h"
#include "sh_init.h"
#include "sh_module_cfg.h"
#include "sh_tx.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

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

/*CDC total chunks for current radar cycle */
uint8_t CDC_Last_Chunk_Flag = CODED_FALSE; /* Make default True to enable UDP stream Tx while CDC disabled.*/

Stream_Cfg_T Stream_Table[MAX_NUM_STRMS] = {STREAM_LIST(STREAM_CFG)};
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static uint32_t cycle_cnt                   = 0U;
static uint16_t Stream_Count                = 0U;
static uint32_t Stream_Recording_Task_Count = 0U;
/* Stream Transmission Enabled check flag */
static bool Stream_Tx_Enable = false;

static Rec_Hdl_T Streams[NUM_OF_STREAMS];
static volatile bool Stream_Recording_Enable = true;

/* Time taken to execute Periodic_Stream_Handler function*/
static uint32_t Time_Periodic_Stream_Handler_Delta = 0U;
/* Maximum Time taken to execute Periodic_Stream_Handler function*/
static uint32_t Time_Periodic_Stream_Handler_Max = 0U;
/* Time taken to execute Trigger_Stream_Handler function*/
static uint32_t Time_Trigger_Stream_Handler_Delta = 0U;
/* Maximum Time taken to execute Trigger_Stream_Handler function*/
static uint32_t Time_Trigger_Stream_Handler_Max = 0U;

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
Stream_Info_T *Get_Stream_Info_Ptr(uint8_t idx);
static uint8_t *Get_Stream_Last_Fail_Ptr(uint8_t idx);
static uint8_t *Get_Stream_Buf(uint8_t idx, uint8_t sub_id);
static void Periodic_Rec_Handler(void);
static void Clear_StreamHandler_Queue(void);
static uint8_t Rec_Handler_Send_Stream(uint16_t id, uint8_t *buf_ptr);
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 *. Name: Get_Stream_Buf
 *.    returns the address of data ptr
 *.
 *. Parameters: uint8_t idx, uint8_t sub_id
 *. Return Value: uint8_t *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t *Get_Stream_Buf(uint8_t idx, uint8_t sub_id)
{
   return (Stream_Table[idx].stream_info_ptr[sub_id].stream_rec.data_ptr);
}

/******************************************************************************
 *. Name: Get_Stream_Last_Fail_Ptr
 *.    returns the address of last failure stream
 *.
 *. Parameters: uint8_t idx
 *. Return Value: uint8_t *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t *Get_Stream_Last_Fail_Ptr(uint8_t idx)
{
   return (&Stream_Table[idx].last_failure);
}

/******************************************************************************
 *. Name: Clear_StreamHandler_Queue()
 *.    Empty the queue content.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Clear_StreamHandler_Queue(void)
{
   uint16_t stream_idx = 0U;
   uint16_t rec_id     = 0U;

   for (stream_idx = 0; stream_idx < STREAM_QUEUE_SIZE; stream_idx++)
   {
      rec_id = DL_Send_Queue[stream_idx].rec_id;
      if (REC_HANDLER_EMPTY != rec_id)
      {
         DISABLE_ALL_INTERRUPTS();
         Get_Rec_Hdl_Ptr(rec_id)->state     = (uint8_t)STREAM_STATE_IDLE;
         DL_Send_Queue[stream_idx].rec_id   = REC_HANDLER_EMPTY;
         DL_Send_Queue[stream_idx].data_ptr = NULL;
         ENABLE_ALL_INTERRUPTS();
      }
   }
}

/******************************************************************************
 *. Name: Periodic_Rec_Handler
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
static void Periodic_Rec_Handler(void)
{
#if defined(CDC_TOTAL_CHUNKS_CURRENT_CYCLE)
   SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();
#endif
   /* count the cycles before anything else */
   cycle_cnt++;

   if (Stream_Recording_Enable && Stream_Handler_Init_Flag)
   {
      if (CODED_TRUE == CDC_Last_Chunk_Flag)
      {
         Send_Stream_From_Queue();
      }
      else
      {
         /* Do nothing for now */
      }
   }
   else
   {
      /* Clear the queue contents */
      Clear_StreamHandler_Queue();
   }
}

/******************************************************************************
 *. Name: Rec_Handler_Add_Stream
 *.    Function to add new stream.
 *.
 *. Parameters: uint32_t address : address for the stream
 *.             uint32_t length  : stream length
 *.             uint16_t* id : id of the assigned stream to be returned to the caller
 *. Return Value: uint8_t ret_val
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Rec_Handler_Add_Stream(Stream_Cfg_T *stream_cfg_ptr)
{
   Stream_Handler_Init_Params_T *sh_ip_ptr = Get_Stream_Handler_Init_Params();
   uint32_t stream_size;
   uint16_t stream_id;
   uint16_t stream_chunks;
   uint8_t ret_val = REC_HANDLER_OK;
   uint8_t i;
   uint8_t sub_stream_cnt;

   Stream_Rec_T *rec_ptr;
   Stream_Info_T *stream_info_ptr;
   Rec_Hdl_T *rec_hdl_ptr;

   sub_stream_cnt = stream_cfg_ptr->sub_stream_cnt;

   stream_info_ptr = stream_cfg_ptr->stream_info_ptr;

   /* Allocate id for each stream or sub stream e.g. USC/SMC  */
   for (i = 0U; i < sub_stream_cnt; i++)
   {
      stream_id = Stream_Count;

      if (stream_id < NUM_OF_STREAMS)
      {
         rec_hdl_ptr = Get_Rec_Hdl_Ptr(stream_id);

         rec_ptr = &stream_info_ptr[i].stream_rec;

         /* update the record header with all the static info */
         rec_ptr->rec_hdr.versionInfo   = RECORD_VERSIONINFO;
         rec_ptr->rec_hdr.sourceInfo    = sh_ip_ptr->source_info;
         rec_ptr->rec_hdr.sourceInfo1   = sh_ip_ptr->source_info1;
         rec_ptr->rec_hdr.sourceInfo2   = sh_ip_ptr->source_info2;
         rec_ptr->rec_hdr.streamNumber  = stream_cfg_ptr->stream_num;
         rec_ptr->rec_hdr.streamVersion = stream_info_ptr[i].stream_ver;
#if (0xA5 == REC_VER)
         rec_ptr->rec_hdr.sensorId = sh_ip_ptr->sensor_id;
#else
         rec_ptr->rec_hdr.customerId     = sh_ip_ptr->sensor_id;
         rec_ptr->rec_hdr.sensorPosition = sh_ip_ptr->sensor_id;
#endif
         rec_ptr->rec_hdr.streamChunkIdx = 0U;

         rec_hdl_ptr->rec_ptr = rec_ptr;
         rec_hdl_ptr->length  = stream_info_ptr[i].stream_len;

         /* get enable flag */
         rec_hdl_ptr->enable = stream_info_ptr[i].stream_ena;

         if (rec_hdl_ptr->enable > 0U)
         {
            rec_hdl_ptr->state = (uint8_t)STREAM_STATE_IDLE;
         }
         else
         {
            rec_hdl_ptr->state = (uint8_t)STREAM_STATE_DISABLE;
         }

         rec_hdl_ptr->id = stream_id;

         /* assign unique id for each stream */
         stream_info_ptr[i].stream_rec_id = stream_id;

         /* get stream_type and chunks per cycle */
         rec_hdl_ptr->stream_type      = stream_info_ptr[i].stream_type;
         rec_hdl_ptr->chunks_per_cycle = stream_info_ptr[i].stream_cpc;

#if (0xA5 == REC_VER)
         /* chunks per cycle; zero for regular stream, non-zero for static streams */
         rec_ptr->rec_hdr.streamChunksPerCycle = stream_info_ptr[i].stream_cpc;
#endif

         /* calculate once and use it */
         stream_size   = stream_info_ptr[i].stream_len;
         stream_chunks = (uint16_t)(stream_size / REC_PAYLOAD);

         if (stream_size > ((uint32_t)stream_chunks * (uint32_t)REC_PAYLOAD))
         {
            stream_chunks += 1U;
         }
         rec_ptr->rec_hdr.streamChunks = stream_chunks;

         Stream_Count++;
         /* If static stream is configured with ALL_CHUNKS (0), send all chunks each cycle */
         if ((rec_hdl_ptr->stream_type == (uint8_t)STREAM_STATIC) && (rec_hdl_ptr->chunks_per_cycle == (uint8_t)ALL_CHUNKS))
         {
            rec_hdl_ptr->chunks_per_cycle = (uint8_t)stream_chunks;
#if (0xA5 == REC_VER)
            rec_ptr->rec_hdr.streamChunksPerCycle = rec_hdl_ptr->chunks_per_cycle;
#endif
         }
      }
      else
      {
         ret_val = (uint8_t)REC_HANDLER_INVALID_ID;
         break;
      }
   }

   return ret_val;
}

/******************************************************************************
 *. Name: Rec_Handler_Send_Stream
 *.    send specific stream.
 *.
 *. Parameters: uint16_t id : id of the stream to modify
                        uint8_t *buf_ptr : pointer to source that is to be logged out
 *. Return Value: uint8_t ret_val
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t Rec_Handler_Send_Stream(uint16_t id, uint8_t *buf_ptr)
{
   uint8_t ret_val        = REC_HANDLER_OK;
   uint8_t ret_val_queue  = REC_HANDLER_OK;
   bool send_stream_flag  = false;
   Rec_Hdl_T *rec_hdl_ptr = NULL;
   // SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();

   if (id < NUM_OF_STREAMS)
   {
      rec_hdl_ptr = Get_Rec_Hdl_Ptr(id);

      if ((uint8_t)STREAM_STATE_READY == rec_hdl_ptr->state)
      {
         if (REC_HANDLER_OVERWRITE == (Rec_Handler_Error_T)(ret_val = Overwrite_Stream_On_Queue(id, buf_ptr)))
         {
            /*Do not push stream to queue as it's overwritten*/
            send_stream_flag = false;
         }
         else if (REC_HANDLER_NOT_FOUND_IN_Q == (Rec_Handler_Error_T)ret_val)
         {
            /* Not found in queue */
            send_stream_flag = true;
         }
         else
         {
            /* Need to define behavior */
         }
      }
      else if ((uint8_t)STREAM_STATE_SENDING == rec_hdl_ptr->state)
      {
         ret_val          = (uint8_t)REC_HANDLER_BUSY;
         send_stream_flag = false;
      }
      else if ((uint8_t)STREAM_STATE_IDLE == rec_hdl_ptr->state)
      {
         ret_val          = REC_HANDLER_OK;
         send_stream_flag = true;
      }
      else if ((uint8_t)STREAM_STATE_DISABLE == rec_hdl_ptr->state)
      {
         ret_val          = REC_HANDLER_OK;
         send_stream_flag = false;
      }
      else
      {
         ret_val          = (uint8_t)REC_HANDLER_INCORRECT_STATE;
         send_stream_flag = false;
      }

      if (send_stream_flag)
      {
         rec_hdl_ptr->rec_ptr->data_ptr = buf_ptr;

         ret_val_queue = Push_Stream_On_Queue(id, buf_ptr);

         if (REC_HANDLER_OK == ret_val_queue)
         {
            DISABLE_ALL_INTERRUPTS();
            rec_hdl_ptr->state = (uint8_t)STREAM_STATE_READY;
            ENABLE_ALL_INTERRUPTS();
            /* As the queue addition is successful, just Return the stream state's ret_val as it is*/
         }
         else
         {
            /* Failed to put on to queue */
            ret_val = ret_val_queue;
         }
      }
      else
      {
         /* do nothing */
      }
   }
   else /* id >= NUM_OF_STREAMS */
   {
      ret_val = (uint8_t)REC_HANDLER_INVALID_ID;
   }

   return ret_val;
}

/******************************************************************************
 *. Name: Periodic_Stream_Handler
 *.    Periodic task to process and send UDP logging data
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Periodic_Stream_Handler(void)
{
   SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();

   uint64_t time_periodic_str_hdl_start;
   sh_input_data_ptr->ustime_logging_fptr(&time_periodic_str_hdl_start);
   /* Trigger the periodic stream handler */
   Periodic_Rec_Handler();

   Stream_Recording_Task_Count++;

   sh_input_data_ptr->elapsed_ustime_logging_fptr(&Time_Periodic_Stream_Handler_Delta, time_periodic_str_hdl_start);
   /*Maximum execution time calculation for Periodic_Stream_Handler function */
   if (Time_Periodic_Stream_Handler_Max < Time_Periodic_Stream_Handler_Delta)
   {
      Time_Periodic_Stream_Handler_Max = Time_Periodic_Stream_Handler_Delta;
   }
}

/******************************************************************************
 *. Name: Get_Rec_Hdl_Ptr
 *.    returns the address of particular stream
 *.
 *. Parameters: uint16_t id
 *. Return Value: Rec_Hdl_T *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Rec_Hdl_T *Get_Rec_Hdl_Ptr(uint16_t id)
{
   return ((Rec_Hdl_T *)&Streams[id]);
}

/******************************************************************************
 *. Name: Get_Stream_Mode
 *.    returns the stream mode
 *.
 *. Parameters: uint8_t idx
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Get_Stream_Mode(uint8_t idx)
{
   return (Stream_Table[idx].stream_mode);
}

/******************************************************************************
 *. Name: Get_Stream_Info_Ptr
 *.    returns the address of  stream info
 *.
 *. Parameters: uint8_t idx
 *. Return Value: Stream_Info_T *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Stream_Info_T *Get_Stream_Info_Ptr(uint8_t idx)
{
   return (Stream_Table[idx].stream_info_ptr);
}
/******************************************************************************
 *. Name: Get_Stream_Sub
 *.    returns the sub stream count
 *.
 *. Parameters: uint8_t idx
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Get_Stream_Sub(uint8_t idx)
{
   return (Stream_Table[idx].sub_stream_cnt);
}

/******************************************************************************
 *. Name: Get_Stream_Ow_Ptr
 *.    returns the address of stream overwrite
 *.    considering the varying number of Calibration streams
 *.
 *. Parameters: uint8_t idx
 *. Return Value: uint16_t *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint16_t *Get_Stream_Ow_Ptr(uint8_t idx)
{
   return (&Stream_Table[idx].stream_overwrite);
}

/******************************************************************************
 *. Name: Get_Stream_Fail_Ptr
 *.    returns the address of stream failure
 *.
 *. Parameters: uint8_t idx
 *. Return Value: uint16_t *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint16_t *Get_Stream_Fail_Ptr(uint8_t idx)
{
   return (&Stream_Table[idx].stream_failure);
}

/******************************************************************************
 *. Name: Set_Stream_Tx_Enable_Status(bool val)
 *.    Function to set status of Stream_Tx_Enable
 *.
 *. Parameters: bool
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Set_Stream_Tx_Enable_Status(bool val)
{
   Stream_Tx_Enable = val;
}

/******************************************************************************
 *. Name: Get_Stream_Tx_Enable_Status(void)
 *.    Function to get status of Stream_Tx_Enable
 *.
 *. Parameters: void
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_Stream_Tx_Enable_Status(void)
{
   return Stream_Tx_Enable;
}

/******************************************************************************
 *. Name: Trigger_Stream_Handler(Stream_List_T stream_idx, uint8_t *buf_ptr)
 *.    Triggers the stream handler.
 *.
 *. Parameters: uint8_t stream_idx, uint8_t *buf_ptr
 *. Return Value: uint8_t stream_idx, uint8_t *buf_ptr
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Trigger_Stream_Handler(Stream_List_T stream_idx, uint8_t *buf_ptr)
{
   uint16_t stream_rec_id         = 0U;
   uint8_t stream_state           = 0U;
   uint8_t sub_stream_cnt         = 0U;
   uint8_t i                      = 0U;
   uint8_t *data_ptr              = NULL;
   Stream_Info_T *stream_info_ptr = NULL;
   Rec_Hdl_T *rec_hdl_ptr         = NULL;
   uint16_t chunk_start           = 0U;
   uint16_t chunk_end             = 0U;
   SH_Input_T *sh_input_data_ptr  = Get_SH_Input_Data_Ptr();

   uint64_t time_trigger_str_hdl_start = 0U;
   sh_input_data_ptr->ustime_logging_fptr(&time_trigger_str_hdl_start);

   uint16_t *stream_overwrite_ptr = Get_Stream_Ow_Ptr((uint8_t)stream_idx);
   uint16_t *stream_failures_ptr  = Get_Stream_Fail_Ptr((uint8_t)stream_idx);
   uint8_t *last_fail             = Get_Stream_Last_Fail_Ptr((uint8_t)stream_idx);

   if (stream_idx < MAX_NUM_STRMS)
   {
      if ((uint8_t)STREAM_INIT == Get_Stream_Mode((uint8_t)stream_idx))
      {
         if (Stream_Tx_Enable)
         {
            /* stream already initialized */
            sub_stream_cnt  = Get_Stream_Sub((uint8_t)stream_idx);
            stream_info_ptr = Get_Stream_Info_Ptr((uint8_t)stream_idx);

            data_ptr = buf_ptr;

            for (i = 0U; i < sub_stream_cnt; i++)
            {
               if ((uint8_t)CALIB == stream_idx)
               {
                  /* sub-stream for CALIB, viz, smc, usc etc */
                  data_ptr = Get_Stream_Buf((uint8_t)CALIB, i);
               }
               if (NULL != data_ptr)
               {
                  stream_rec_id = stream_info_ptr[i].stream_rec_id;
                  rec_hdl_ptr   = Get_Rec_Hdl_Ptr(stream_rec_id);

                  if (((uint8_t)0U == rec_hdl_ptr->enable) || ((uint8_t)STREAM_STATE_DISABLE == rec_hdl_ptr->state))
                  {
                     /* stream disabled at runtime; treat as no-operation */
                     stream_state = REC_HANDLER_OK;
                  }
                  else if (((uint8_t)STREAM_DYNAMIC == rec_hdl_ptr->stream_type) ||
                           ((uint8_t)STREAM_REGULAR_FAST == rec_hdl_ptr->stream_type))
                  {
                     /* send out stream immediately - bypass the queue */

                     DISABLE_ALL_INTERRUPTS();
                     rec_hdl_ptr->state = (uint8_t)STREAM_STATE_READY;
                     ENABLE_ALL_INTERRUPTS();
                     stream_state = Send_Stream(stream_rec_id, data_ptr, chunk_start, chunk_end);
                     if (REC_HANDLER_OK != stream_state)
                     {
                        stream_state = (uint8_t)REC_HANDLER_TX_FAILED;
                     }
                  }
                  else
                  {
                     /* send out stream through queue */
                     stream_state = Rec_Handler_Send_Stream(stream_rec_id, data_ptr);
                  }
               }
               else
               {
                  stream_state = (uint8_t)REC_HANDLER_INVALID_STREAM_ADDR;
               }

               if (REC_HANDLER_OK != stream_state)
               {
                  if ((uint8_t)REC_HANDLER_OVERWRITE == stream_state)
                  {
                     /* increment the overwrite counter */
                     (*stream_overwrite_ptr)++;
                  }
                  else
                  {
                     /* failed to add stream to sending queue */
                     (*stream_failures_ptr)++;
                     *last_fail = stream_state;
                  }
               }
            } /* for loop */
         }
         else
         {
            stream_state = (uint8_t)REC_HANDLER_TX_FAILED;
         }
      }
      else
      {
         stream_state = (uint8_t)REC_HANDLER_STREAM_UNINIT;
      }
   }
   else
   {
      stream_state = (uint8_t)REC_HANDLER_INVALID_ID;
   }
   sh_input_data_ptr->elapsed_ustime_logging_fptr(&Time_Trigger_Stream_Handler_Delta, time_trigger_str_hdl_start);
   /*Maximum execution time calculation for Trigger_Stream_Handler function */
   if (Time_Trigger_Stream_Handler_Max < Time_Trigger_Stream_Handler_Delta)
   {
      Time_Trigger_Stream_Handler_Max = Time_Trigger_Stream_Handler_Delta;
   }

   return stream_state;
}

/******************************************************************************
 *. Name: Set_Stream_Recording_Status(bool)
 *.    Function to enable or disable Stream Recording
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Set_Stream_Recording_Status(bool val)
{
   Stream_Recording_Enable = val;
}

/******************************************************************************
 *. Name: Enable_Stream_Recording(void)
 *.    Function to enable UDP Logging.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Enable_Stream_Recording(void)
{
   SH_Input_T *sh_input_data_ptr = Get_SH_Input_Data_Ptr();
   if (sh_input_data_ptr->xcp_over_eth_status_fptr() /*&& sh_input_data_ptr->calibration_disable_cdc_logging_fptr()*/)
   {
      /* Disable UDP logging when XCP Connection is active */
      Set_Stream_Recording_Status(false);
   }
   else
   {
      Set_Stream_Recording_Status(true);
   }
}

/******************************************************************************
 *. Name: Get_Stream_Table(void)
 *.    Function to get stream table address
 *.
 *. Parameters: void
 *. Return Value: Stream_Cfg_T
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Stream_Cfg_T *Get_Stream_Table(void)
{
   return &Stream_Table[0];
}

/******************************************************************************
 *. Name: Get_Stream_Info(void)
 *.    Function to get stream list Info address
 *.
 *. Parameters: void
 *. Return Value: Stream_Info_List
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Stream_Info_T *Get_Stream_Info(void)
{
   return &Stream_Info_List[0];
}

/******************************************************************************
 *. Name: Get_Stream_Recording_Status(void)
 *.    Function to staus of stream recording
 *.
 *. Parameters: void
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_Stream_Recording_Status(void)
{
   return Stream_Recording_Enable;
}

/******************************************************************************
 *. Name: Get_Total_Streams
 *.    returns the total stream count
 *.    considering the varying number of Calibration streams
 *.
 *. Parameters: void
 *. Return Value: uint16_t
 *.
 *. Traceability Information:
 *.  Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint16_t Get_Total_Streams(void)
{
   return (Stream_Count);
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
