/**
 * @file SWC_PLT_CDD_HIL_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
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

#ifndef SWC_PLT_CDD_HIL_FAKE_H_
#define SWC_PLT_CDD_HIL_FAKE_H_
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "fff.h"
#include "header_stream.h"
#include "ipc_data.h"
#include "status_stream.h"
#include <stdint.h>

   /*===========================================================================*
    * Fake value functions - symbols needed by SWC_PLT_CDD_HIL.c
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Header_Stream_T *, Get_Header_Stream_Ptr);
   DECLARE_FAKE_VALUE_FUNC(Status_Stream_T *, Get_Status_Stream_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
   DECLARE_FAKE_VOID_FUNC(HIL_Injection_Request);
   DECLARE_FAKE_VOID_FUNC(Update_HIL_Input_Interface);

   /*===========================================================================*
    * Fake value functions - sensor position
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);

   /*===========================================================================*
    * Fake value functions - IPC mocks
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);

#define FFF_FAKES_HIL_SWC_PLT_CDD_LIST(FAKE)                                                                                      \
   FAKE(Get_Header_Stream_Ptr)                                                                                                    \
   FAKE(Get_Status_Stream_Ptr)                                                                                                    \
   FAKE(Get_Req_En_Dis_CDC_Stream)                                                                                                \
   FAKE(HIL_Injection_Request)                                                                                                    \
   FAKE(Update_HIL_Input_Interface)                                                                                               \
   FAKE(Get_Radar_Position)                                                                                                       \
   FAKE(Get_MSS_IPC_M2D_Msg_Buffer)                                                                                               \
   FAKE(Get_IPC_M2D_Onetime_Msg_Buffer)

#ifdef __cplusplus
}

#endif

#endif /* SWC_PLT_CDD_HIL_FAKE_H*/
