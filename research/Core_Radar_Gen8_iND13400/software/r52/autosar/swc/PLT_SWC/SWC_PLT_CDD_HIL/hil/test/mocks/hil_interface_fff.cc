/*===========================================================================*/
/**
 * @file hil_interface_fff.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mock functions for stream_handler.c file.
 *
 * @section ABBR ABBREVIATIONS:
 *   -List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     -Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "hil_interface_fff.h"

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for stream_handler.c
 *===========================================================================*/

/*===========================================================================*
 * FAKE VOID FUNCTIONS for SH
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(Header_Stream_T *, Get_Header_Stream_Ptr);
DEFINE_FAKE_VALUE_FUNC(Status_Stream_T *, Get_Status_Stream_Ptr);
DEFINE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);
DEFINE_FAKE_VOID_FUNC(Get_PlatformTime_ms_read, uint32_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_IfTransmit, PduIdType, P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA));
DEFINE_FAKE_VALUE_FUNC(uint8_t, Update_HIL_Internal_Memory_Pointers);

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for dsp_setup dependencies
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buf_Addr, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Ping_Buf_Addr);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Pong_Buf_Addr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t, Get_DSP_Write_IPC_Index);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Fetch_M2D_Buffer_Idx_HIL_Injection);

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for sensor_position / logging / timer dependencies
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
DEFINE_FAKE_VALUE_FUNC(float32, Get_Timestamp_ms);
