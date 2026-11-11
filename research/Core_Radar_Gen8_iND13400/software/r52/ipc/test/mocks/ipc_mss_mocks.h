/**
 * @file ipc_mss_mocks.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mock declarations of the functions in ipc_mss.c file.
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
#ifndef IPC_MSS_MOCKS_H
#define IPC_MSS_MOCKS_H
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "ipc_mss.h"
/*===========================================================================*
 * Fake void functions - IPC MSS functions
 *===========================================================================*/
DECLARE_FAKE_VOID_FUNC(IPC_M2D_Buffer_Init);
DECLARE_FAKE_VOID_FUNC(IPC_M2D_One_Time_Buffer_Init);
DECLARE_FAKE_VOID_FUNC(Update_R52_IPC_Notify);
DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
DECLARE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_IPC_M2D_Msg_Buffer, uint8_t);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Check_D2M_Crc_Header, D2M_Msg_T *);
DECLARE_FAKE_VALUE_FUNC(bool, Get_DSP_Init_Status);
DECLARE_FAKE_VOID_FUNC(Set_DSP_Init_Status, bool);
DECLARE_FAKE_VALUE_FUNC(bool, Get_Received_Doppler_Done);
DECLARE_FAKE_VOID_FUNC(Set_Received_Doppler_Done, bool);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_M2D_Buffer_Full_Error_Counter);
DECLARE_FAKE_VOID_FUNC(Set_M2D_Buffer_Full_Error_Counter, uint32_t);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_M2D_Crc_Err_Cnt);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_D2M_Crc_Err_Cnt);
DECLARE_FAKE_VALUE_FUNC(volatile DSP_Config_Type_T, Get_DSP_Cfg_Init);
DECLARE_FAKE_VOID_FUNC(Set_DSP_Cfg_Init, DSP_Config_Type_T);
DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_DSP_No_Command_Cnt);
DECLARE_FAKE_VOID_FUNC(Reset_IPC_M2D_Buffer, volatile M2D_Msg_T *);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_R52_D2M_Msg_Header_Cnt);
DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer);
DECLARE_FAKE_VALUE_FUNC(bool, R52_BBE_Trigger);
DECLARE_FAKE_VALUE_FUNC(bool, Get_Is_Doppler_Comp_RDD_Stream_Ready);
DECLARE_FAKE_VOID_FUNC(Set_Is_Doppler_Comp_RDD_Stream_Ready, bool);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Ping_Buf_Addr);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Pong_Buf_Addr);
DECLARE_FAKE_VALUE_FUNC(volatile uint8_t, Get_DSP_Write_IPC_Index);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_R52_Current_PingPong_Index);
DECLARE_FAKE_VOID_FUNC(Update_IPC_M2D_Header, volatile M2D_Msg_T *);
DECLARE_FAKE_VOID_FUNC(Set_XCP_Fault_Inj);

/*===========================================================================*
 * List of fakes used by this unit tester
 *===========================================================================*/
#define FFF_FAKES_IPC_MSS_LIST(FAKE)                                                                                              \
   FAKE(IPC_M2D_Buffer_Init)                                                                                                      \
   FAKE(IPC_M2D_One_Time_Buffer_Init)                                                                                             \
   FAKE(Update_R52_IPC_Notify)                                                                                                    \
   FAKE(Get_IPC_D2M_Sp_Post_Proc_Buffer)                                                                                          \
   FAKE(Get_MSS_IPC_M2D_Msg_Buffer)                                                                                               \
   FAKE(Get_IPC_M2D_Onetime_Msg_Buffer)                                                                                           \
   FAKE(Get_IPC_M2D_Msg_Buffer)                                                                                                   \
   FAKE(Check_D2M_Crc_Header)                                                                                                     \
   FAKE(Get_DSP_Init_Status)                                                                                                      \
   FAKE(Set_DSP_Init_Status)                                                                                                      \
   FAKE(Get_Received_Doppler_Done)                                                                                                \
   FAKE(Set_Received_Doppler_Done)                                                                                                \
   FAKE(Get_M2D_Buffer_Full_Error_Counter)                                                                                        \
   FAKE(Set_M2D_Buffer_Full_Error_Counter)                                                                                        \
   FAKE(Get_IPC_M2D_Crc_Err_Cnt)                                                                                                  \
   FAKE(Get_IPC_D2M_Crc_Err_Cnt)                                                                                                  \
   FAKE(Get_DSP_Cfg_Init)                                                                                                         \
   FAKE(Set_DSP_Cfg_Init)                                                                                                         \
   FAKE(Get_DSP_No_Command_Cnt)                                                                                                   \
   FAKE(Reset_IPC_M2D_Buffer)                                                                                                     \
   FAKE(Get_R52_D2M_Msg_Header_Cnt)                                                                                               \
   FAKE(Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer)                                                                                     \
   FAKE(R52_BBE_Trigger)                                                                                                          \
   FAKE(Get_Is_Doppler_Comp_RDD_Stream_Ready)                                                                                     \
   FAKE(Set_Is_Doppler_Comp_RDD_Stream_Ready)                                                                                     \
   FAKE(Get_D2M_Ping_Buf_Addr)                                                                                                    \
   FAKE(Get_D2M_Pong_Buf_Addr)                                                                                                    \
   FAKE(Get_DSP_Write_IPC_Index)                                                                                                  \
   FAKE(Get_R52_Current_PingPong_Index)                                                                                           \
   FAKE(Update_IPC_M2D_Header)                                                                                                    \
   FAKE(Set_XCP_Fault_Inj)

#endif /* IPC_MSS_MOCKS_H */
