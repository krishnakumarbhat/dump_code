/**
 * @file hil_interface_fff.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mock the functions of the wrappers in anglefinding_project_interface.c
 *
 * @section ABBR ABBREVIATIONS:
 *   -List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
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

#ifndef HIL_INTERFACE_FFF_H
#define HIL_INTERFACE_FFF_H
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif

#include "SoAd.h"
#include "dd_gpt.h"
#include "fff.h"
#include "header_stream.h"
#include "hil_interface.h"
#include "ipc_data.h"
#include "sh_interface.h"
#include "status_stream.h"

   /*===========================================================================*
    * C Header Files
    *===========================================================================*/

   /*===========================================================================*
    * Fake value functions - HIL project interface
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Header_Stream_T *, Get_Header_Stream_Ptr);
   DECLARE_FAKE_VALUE_FUNC(Status_Stream_T *, Get_Status_Stream_Ptr);
   DECLARE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);
   DECLARE_FAKE_VOID_FUNC(Get_PlatformTime_ms_read, uint32_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Update_HIL_Internal_Memory_Pointers);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_IfTransmit, PduIdType, P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA));

   /*===========================================================================*
    * Fake value functions - dsp_setup dependencies
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buf_Addr, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Ping_Buf_Addr);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_D2M_Pong_Buf_Addr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t, Get_DSP_Write_IPC_Index);
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Fetch_M2D_Buffer_Idx_HIL_Injection);

   /*===========================================================================*
    * Fake value functions - sensor_position / logging / timer dependencies
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
   DECLARE_FAKE_VALUE_FUNC(float32, Get_Timestamp_ms);

   /*===========================================================================*
    * Extern RTE variable stub
    *===========================================================================*/
   extern uint8_t Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation;

#define FFF_FAKES_HIL_LIST(FAKE)                                                                                                  \
   FAKE(Get_Header_Stream_Ptr)                                                                                                    \
   FAKE(Get_SH_Output_Data_Ptr)                                                                                                   \
   FAKE(SoAd_IfTransmit)                                                                                                          \
   FAKE(Get_PlatformTime_ms_read)                                                                                                 \
   FAKE(Get_Status_Stream_Ptr)                                                                                                    \
   FAKE(Update_HIL_Internal_Memory_Pointers)                                                                                      \
   FAKE(Get_MSS_IPC_M2D_Msg_Buf_Addr)                                                                                             \
   FAKE(Get_D2M_Ping_Buf_Addr)                                                                                                    \
   FAKE(Get_D2M_Pong_Buf_Addr)                                                                                                    \
   FAKE(Get_DSP_Write_IPC_Index)                                                                                                  \
   FAKE(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer)                                                                                      \
   FAKE(Get_Fetch_M2D_Buffer_Idx_HIL_Injection)                                                                                   \
   FAKE(Get_Radar_Position)                                                                                                       \
   FAKE(Get_Req_En_Dis_CDC_Stream)                                                                                                \
   FAKE(Get_Timestamp_ms)

#ifdef __cplusplus
}
#endif

#endif /* HIL_INTERFACE_FFF_H*/
