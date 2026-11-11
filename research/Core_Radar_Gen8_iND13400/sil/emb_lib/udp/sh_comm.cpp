/*===========================================================================*/
/**
 * @file sh_comm.c
 *
 * Add a one line description of the implementation.
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
 * This file contains the SH communication.
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
#include "sh_comm.h"
#include "sh_core.h"
#if defined(STREAM_RX_ENABLE)
   #include "sh_init_rx.h"
#endif
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

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

SH_Input_T SH_Inputs   = {NULL};
SH_Output_T SH_Outputs = {NULL};

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/
SH_Input_T *Get_SH_Input_Data_Ptr(void);
SH_Output_T *Get_SH_Output_Data_Ptr(void);
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 *. Name: Get_SH_Input_Data_Ptr
 *.    Function to Get_SH_Input_Data_Ptr.
 *.
 *. Parameters:
 *. Return Value: HIL_Input_T
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
SH_Input_T *Get_SH_Input_Data_Ptr(void)
{
   return &(SH_Inputs);
}

/******************************************************************************
 *. Name: Get_SH_Output_Data_Ptr
 *.    Function to Get_SH_Output_Data_Ptr.
 *.
 *. Parameters:
 *. Return Value: HIL_Input_T
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
SH_Output_T *Get_SH_Output_Data_Ptr(void)
{
   return &(SH_Outputs);
}

/******************************************************************************
 *. Name: Update_SH_Output_Interface
 *.    Function to update the SH output interface.
 *.
 *. Parameters:
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Update_SH_Output_Interface(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();

   sh_output_data_ptr->sh_stream_info_ptr         = Get_Stream_Info();
   sh_output_data_ptr->sh_stream_table_cfg_ptr    = Get_Stream_Table();
   sh_output_data_ptr->sh_source_tx_cnt           = Get_Source_Tx_Cnt();
   sh_output_data_ptr->sh_stream_error            = Get_Stream_Error;
   sh_output_data_ptr->sh_stream_recording_enable = Get_Stream_Recording_Status();
#if defined(STREAM_RX_ENABLE)
   sh_output_data_ptr->sh_udp_rx_callback_update_fptr  = Udp_Rx_Callback_Update;
   sh_output_data_ptr->sh_get_stream_rx_info_data_fptr = Get_Stream_Rx_Info_Data_Ptr;
#endif
   sh_output_data_ptr->sh_trigger_stream_handler_fptr = Trigger_Stream_Handler;
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
