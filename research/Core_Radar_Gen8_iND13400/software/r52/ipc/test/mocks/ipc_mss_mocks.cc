/**
 * @file ipc_mss_mocks.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in ipc_mss.c file.
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

#include "ipc_mss_mocks.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/

/*===========================================================================*
 * Fake value functions - IPC functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(IPC_M2D_Buffer_Init);
DEFINE_FAKE_VOID_FUNC(IPC_M2D_One_Time_Buffer_Init);
DEFINE_FAKE_VOID_FUNC(Update_R52_IPC_Notify);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_IPC_M2D_Msg_Buffer, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Check_D2M_Crc_Header, D2M_Msg_T *);
DEFINE_FAKE_VALUE_FUNC(bool, Get_DSP_Init_Status);
DEFINE_FAKE_VOID_FUNC(Set_DSP_Init_Status, bool);
DEFINE_FAKE_VALUE_FUNC(bool, Get_Received_Doppler_Done);
DEFINE_FAKE_VOID_FUNC(Set_Received_Doppler_Done, bool);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_M2D_Buffer_Full_Error_Counter);
DEFINE_FAKE_VOID_FUNC(Set_M2D_Buffer_Full_Error_Counter, uint32_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_M2D_Crc_Err_Cnt);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_D2M_Crc_Err_Cnt);
DEFINE_FAKE_VALUE_FUNC(volatile DSP_Config_Type_T, Get_DSP_Cfg_Init);
DEFINE_FAKE_VOID_FUNC(Set_DSP_Cfg_Init, DSP_Config_Type_T);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_DSP_No_Command_Cnt);
DEFINE_FAKE_VOID_FUNC(Reset_IPC_M2D_Buffer, volatile M2D_Msg_T *);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_R52_D2M_Msg_Header_Cnt);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer);
DEFINE_FAKE_VALUE_FUNC(bool, R52_BBE_Trigger);
DEFINE_FAKE_VALUE_FUNC(bool, Get_Is_Doppler_Comp_RDD_Stream_Ready);
DEFINE_FAKE_VOID_FUNC(Set_Is_Doppler_Comp_RDD_Stream_Ready, bool);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Ping_Buf_Addr);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Pong_Buf_Addr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t, Get_DSP_Write_IPC_Index);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_R52_Current_PingPong_Index);
DEFINE_FAKE_VOID_FUNC(Update_IPC_M2D_Header, volatile M2D_Msg_T *);
DEFINE_FAKE_VOID_FUNC(Set_XCP_Fault_Inj);

/*===========================================================================*
 * Mock the internal data structure
 *===========================================================================*/
extern "C"
{
}
