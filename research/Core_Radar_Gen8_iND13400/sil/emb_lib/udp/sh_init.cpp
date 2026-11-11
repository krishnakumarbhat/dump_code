/*===========================================================================*/
/**
 * @file sh_init.c
 *
 * Provides the implementation for stream initialization.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains the stream handler initialization.
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
#include "sh_init.h"
#include "sh_comm.h"
#include "sh_core.h"
#include "sh_error.h"
#include "sh_module_cfg.h"
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS & ENUM
 *===========================================================================*/
#define CAL_STREAM_INFO(cal, pfx)                                                                                                 \
   {                                                                                                                              \
      sizeof(cal##_Cal_T),         /* stream_len */                                                                               \
      (uint16_t)0U,                /* stream_rec_id */                                                                            \
      (uint16_t)0U,                /* rsvd1 */                                                                                    \
      (uint8_t)CHUNK_1,            /* stream_chunks_per_cycle */                                                                  \
      (uint8_t)STREAM_STATIC,      /* stream_type */                                                                              \
      (uint8_t) true,              /* stream_enable */                                                                            \
      (uint8_t)cal,                /* cal_src */                                                                                  \
      {{0},                        /* rec_hdr */                                                                                  \
       (uint8_t *)&cal##_Cal_Data} /* stream_data */                                                                              \
   },

#define STREAM_INFO(str, pfx)                                                                                                     \
   {                                                                                                                              \
      sizeof(pfx##_Stream_T),        /* stream_len */                                                                             \
      (uint16_t)0U,                  /* stream_rec_id */                                                                          \
      (uint16_t)0U,                  /* rsvd1 */                                                                                  \
      (uint8_t)ALL_CHUNKS,           /* stream_chunks_per_cycle */                                                                \
      (uint8_t)STREAM_REGULAR,       /* stream_type */                                                                            \
      (uint8_t) true,                /* stream_enable */                                                                          \
      (uint8_t)str##_STREAM_VERSION, /* stream_ver */                                                                             \
      {{0},                          /* rec_hdr */                                                                                \
       (uint8_t *)NULL}              /* stream_data */                                                                            \
   },

#define STREAM_CFG(str, pfx)                                                                                                      \
   {                                                                                                                              \
      (Stream_Info_T *)&Stream_Info_List[(uint8_t)str],                                                                           \
      (uint16_t)0U,                 /* stream_overwrite */                                                                        \
      (uint16_t)0U,                 /* stream_failure */                                                                          \
      (uint8_t)str,                 /* stream_idx */                                                                              \
      (uint8_t)str##_STREAM_NUMBER, /* stream_num */                                                                              \
      (uint8_t)STREAM_UNINIT,       /* stream_mode */                                                                             \
      (uint8_t)1U,                  /* sub_stream_cnt */                                                                          \
      (uint8_t)0U                   /* last stream failure mode */                                                                \
   },

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

#if defined(SH_ENABLE_CALIB_STREAM)
static Stream_Info_T Cal_Stream_Info[] = {CAL_TABLE(CAL_STREAM_INFO)};
#endif
Stream_Info_T Stream_Info_List[]                               = {STREAM_LIST(STREAM_INFO)};
bool Stream_Handler_Init_Flag                                  = FALSE;
static Stream_Handler_Init_Params_T Stream_Handler_Init_Params = {0};

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static void Init_Streams(void);
static void Rec_Handler_Init(void);
static void Set_Logging_Stream_Mode(uint8_t idx, uint8_t smode);

/*===========================================================================*
 * Imported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declaration
 *===========================================================================*/

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 *. Name: Set_Logging_Stream_Mode
 *.    Sets the stream mode as smode
 *.
 *. Parameters: uint8_t idx, uint8_t smode
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Set_Logging_Stream_Mode(uint8_t idx, uint8_t smode)
{
   Stream_Table[idx].stream_mode = (uint8_t)smode;
}

/******************************************************************************
 *. Name: Init_Streams
 *.    Init function to initialize UDP Logging.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Init_Streams(void)
{
   uint8_t i;
   uint8_t stream_state;

   for (i = 0U; i < (uint8_t)MAX_NUM_STRMS; i++)
   {
      /* Assign the stream an ID */
      if ((uint8_t)STREAM_UNINIT == Get_Stream_Mode(i)
#ifdef ADC_STREAMING_ENABLE
          && ((uint8_t)ADC == Stream_Table[i].stream_idx)
#endif
      )
      {
         stream_state = Rec_Handler_Add_Stream(&Stream_Table[i]);
         if (REC_HANDLER_OK == stream_state)
         {
            /* adding stream successful */
            Set_Logging_Stream_Mode(i, (uint8_t)STREAM_INIT);
         }
         else
         {
            /* adding stream failed */
         }
      }
   }
}

/******************************************************************************
 *. Name: Rec_Handler_Init
 *.    Init function to initialize Handler internal vars.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Rec_Handler_Init(void)
{
   uint16_t stream_idx = 0U;

   for (stream_idx = 0; stream_idx < STREAM_QUEUE_SIZE; stream_idx++)
   {
      DL_Send_Queue[stream_idx].rec_id   = REC_HANDLER_EMPTY;
      DL_Send_Queue[stream_idx].data_ptr = NULL;
   }
}

/******************************************************************************
 *. Name: Stream_Config_Init
 *.    Configure the user specific params of stream at init.
 *.
 *. Parameters: uint8_t stream_idx, Stream_Init_Cfg_T* stream_cfg_data
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Stream_Config_Init(Stream_List_T stream_idx, Stream_Init_Cfg_T *stream_cfg_data)
{
   uint8_t ret_val = (uint8_t)REC_HANDLER_INVALID_ID;
   uint8_t i;

   for (i = 0U; i < (uint8_t)MAX_NUM_STRMS; i++)
   {
      if (stream_idx == (Stream_List_T)Stream_Table[i].stream_idx)
      {
         Stream_Table[i].stream_info_ptr->stream_ena  = stream_cfg_data->stream_ena;
         Stream_Table[i].stream_info_ptr->stream_type = stream_cfg_data->stream_type;
         Stream_Table[i].stream_info_ptr->stream_cpc  = stream_cfg_data->stream_cpc;

         ret_val = REC_HANDLER_OK;
         break;
      }
   }

   return ret_val;
}

/******************************************************************************
 *. Name: Calib_Stream_Config_Init
 *.    Configure the calib specific params at init.
 *.
 *. Parameters: Stream_Init_Cfg_T* stream_cfg_data
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
DISABLE_OPTIMIZATION
uint8_t Calib_Stream_Config_Init(Stream_Init_Cfg_T *stream_cfg_data)
{
   uint8_t ret_val = (uint8_t)REC_HANDLER_INVALID_ID;
   uint8_t i;

   for (i = 0U; i < (uint8_t)MAX_NUM_STRMS; i++)
   {
      if ((uint8_t)CALIB == Stream_Table[i].stream_idx)
      {
         /* special stream - configure explicitly
            Number of sub streams e.g. USC/SMC etc. */
         Stream_Table[i].sub_stream_cnt  = (uint8_t)MAX_CAL_SOURCE;
         Stream_Table[i].stream_info_ptr = &Cal_Stream_Info[0];

         Stream_Table[i].stream_info_ptr->stream_ena = stream_cfg_data->stream_ena;
         /*Calib stream is always static*/
         Stream_Table[i].stream_info_ptr->stream_type = (uint8_t)STREAM_STATIC;
         Stream_Table[i].stream_info_ptr->stream_cpc  = stream_cfg_data->stream_cpc;

         ret_val = REC_HANDLER_OK;
         break;
      }
   }

   return ret_val;
}
ENABLE_OPTIMIZATION
/******************************************************************************
 *. Name: Stream_Handler_Init
 *.    Task to init streams
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Stream_Handler_Init(void)
{
   /* Update streams if necessary */
   Init_Streams();

   /* Initialise the queue */
   Rec_Handler_Init();

   Stream_Handler_Init_Flag = true;
}

/******************************************************************************
 *. Name: Update_Stream_Handler_Input(Stream_Handler_Init_Params_T *sh_ip)
 *.    Update the inputs for Stream Handler
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Update_Stream_Handler_Input(Stream_Handler_Init_Params_T *sh_ip)
{
   Stream_Handler_Init_Params.sensor_id     = sh_ip->sensor_id;
   Stream_Handler_Init_Params.tx_frame_fptr = sh_ip->tx_frame_fptr;
   Stream_Handler_Init_Params.source_info   = sh_ip->source_info;
   Stream_Handler_Init_Params.source_info1  = sh_ip->source_info1;
   Stream_Handler_Init_Params.source_info2  = sh_ip->source_info2;
}

/******************************************************************************
 *. Name: Get_Stream_Handler_Init_Params(void)
 *.    Get the inputs for Stream Handler
 *.
 *. Parameters: void
 *. Return Value: Stream_Handler_Init_Params_T *
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Stream_Handler_Init_Params_T *Get_Stream_Handler_Init_Params(void)
{
   return &Stream_Handler_Init_Params;
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
