/*===========================================================================*/
/**
 * @file sh_interface.c
 *
 * @todo Add a one line description of the implementation.
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
 *  This fle contains the stream_handler related cfg, Error codes etc
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
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
#include "sh_interface.h"
#include "Os.h"
#include "Os_Lcfg.h"
#include "SWC_PLT_CDD_Logging.h"
#include "dd_gpt.h"
#include "platformtime.h"
#include "sh_tx.h"
#include "sh_types.h"
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor code
 *===========================================================================*/

/*===========================================================================*
 * Import function prototypes
 *===========================================================================*/

/*===========================================================================*
 * extern Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local function Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
// static Stream_Error_T Sh_Stream_Error = {0U, 0U, 0, 0, 0U, 0U};

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
void Update_SH_Input_Interface(void)
{
   SH_Input_T *sh_input_data_ptr = (SH_Input_T *)Get_SH_Input_Data_Ptr();

   sh_input_data_ptr->calibration_disable_cdc_logging_fptr = Get_Status_Calibration_Disable_CDC_Logging;
   sh_input_data_ptr->xcp_over_eth_status_fptr             = Get_XCP_Over_ETH_Status;
   sh_input_data_ptr->disable_allinterrupts_fptr           = DisableAllInterrupts;
   sh_input_data_ptr->enable_allinterrupts_fptr            = EnableAllInterrupts;
   sh_input_data_ptr->ustime_logging_fptr                  = Get_Platform_ustime;
   sh_input_data_ptr->elapsed_ustime_logging_fptr          = Get_Platform_Elapsed_ustime;
   sh_input_data_ptr->send_stream_internal_fptr            = Send_Stream_Internal; /*Check Below*/
   /* Trusted func call would be once available.This changes is added temporarily*/
   sh_input_data_ptr->req_en_dis_cdc_stream_fptr = Get_Req_En_Dis_CDC_Stream;
#ifdef TRACKER_ENABLED
   sh_input_data_ptr->tracker_ref_index_fptr = Get_Tracker_Ref_Index;
#endif
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
