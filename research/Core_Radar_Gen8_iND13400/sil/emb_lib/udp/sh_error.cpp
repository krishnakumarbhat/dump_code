/*===========================================================================*/
/**
 * @file sh_error.c
 *
 * Provides the implementation for stream error handling.
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
 * This file contains the stream handler error information.
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
#include "sh_error.h"
#include "sh_core.h"
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS & ENUM
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

typedef uint32_t Stream_Err_T;

/*===========================================================================*
 * Imported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

static Stream_Err_T Stream_Rec_Sts       = 0U;
static Stream_Err_T Stream_Rec_Sts_Latch = 0U;

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif

   static bool Get_Stream_Err(uint16_t id);
   static bool Get_Latch_Stream_Err(uint16_t id);

   /*===========================================================================*
    * Local Inline Function Definitions and Function-Like Macros
    *===========================================================================*/

   /*===========================================================================*
    * Function Definitions
    *===========================================================================*/

   /******************************************************************************
    *. Name: Set_Stream_Err
    *.    Sets the stream error
    *.
    *. Parameters: uint16_t id
    *. Return Value: void
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   void Set_Stream_Err(uint16_t id)
   {
      Stream_Rec_Sts |= (uint32_t)(1U << (uint8_t)(id));
   }

   /******************************************************************************
    *. Name: Clr_Stream_Err
    *.    Clears the stream error
    *.
    *. Parameters: uint16_t id
    *. Return Value: void
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   void Clr_Stream_Err(uint16_t id)
   {
      Stream_Rec_Sts &= (uint32_t)(~(1U << (uint8_t)(id)));
   }

   /******************************************************************************
    *. Name: Get_Stream_Err
    *.    returns the stream error
    *.
    *. Parameters: uint16_t id
    *. Return Value: bool
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   static bool Get_Stream_Err(uint16_t id)
   {
      return ((bool)((uint8_t)(Stream_Rec_Sts >> (uint8_t)(id)) & 0x01U));
   }

   /******************************************************************************
    *. Name: Get_Latch_Stream_Err
    *.    returns the latch stream error
    *.    considering the varying number of Calibration streams
    *.
    *. Parameters: uint16_t id
    *. Return Value: bool
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   static bool Get_Latch_Stream_Err(uint16_t id)
   {
      return ((bool)((uint8_t)(Stream_Rec_Sts_Latch >> (id)) & 0x01U));
   }

   /******************************************************************************
    *. Name: Latch_Stream_Err
    *.    Update the latch stream error
    *.
    *. Parameters: void
    *. Return Value: void
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   /* latch the stream error status */
   void Latch_Stream_Err(void)
   {
      Stream_Rec_Sts_Latch |= Stream_Rec_Sts;
   }

   /******************************************************************************
    *. Name: Get_Stream_Error
    *.    Provide the error info of the requested stream
    *.
    *. Parameters: uint8_t stream_idx, uint8_t sub_stream_no
    *. Return Value: Stream_Error_T
    *.
    *. Traceability Information:
    *. Place references to requirements and design IDs here.
    *.
    *. JIRA Issues:
    ******************************************************************************/
   Stream_Error_T Get_Stream_Error(Stream_List_T stream_idx, uint8_t sub_stream_no)
   {
      Stream_Error_T stream_err_info = {0};
      Stream_Info_T *stream_info_ptr = Get_Stream_Info_Ptr((uint8_t)stream_idx);
      uint8_t sub_stream_cnt         = Get_Stream_Sub((uint8_t)stream_idx);
      uint8_t info_req_sts           = (uint8_t)REC_HANDLER_NOT_OK;

      if ((stream_idx < MAX_NUM_STRMS) && (sub_stream_no < sub_stream_cnt))
      {
         if ((uint8_t)STREAM_INIT == Get_Stream_Mode((uint8_t)stream_idx))
         {
            stream_err_info.current_error_sts = Get_Stream_Err(stream_info_ptr[sub_stream_no].stream_rec_id);
            stream_err_info.latched_error_sts = Get_Latch_Stream_Err(stream_info_ptr[sub_stream_no].stream_rec_id);
            stream_err_info.stream_overwrite  = (uint16_t)(*Get_Stream_Ow_Ptr((uint8_t)stream_idx));
            stream_err_info.stream_failure    = (uint16_t)(*Get_Stream_Fail_Ptr((uint8_t)stream_idx));
            info_req_sts                      = REC_HANDLER_OK;
         }
         else
         {
            info_req_sts = (uint8_t)REC_HANDLER_STREAM_UNINIT;
         }
      }
      else
      {
         info_req_sts = (uint8_t)REC_HANDLER_INVALID_ID;
      }

      stream_err_info.info_req_sts = info_req_sts;
      return stream_err_info;
   }

#ifdef __cplusplus
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
