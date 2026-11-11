/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_Communication_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock implementation file for SWC_PLT_Appl_Communication unit testing
 *
 * @section ABBR ABBREVIATIONS:
 *   - FFF: Fake Function Framework
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWC_PLT_Appl_Communication Unit Test Design
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/
#include "can_tx_msgs_fakes.h"

/* Define fake functions for CAN */
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, CanSM_RequestComMode, ComM_UserHandleType, ComM_ModeType);
DEFINE_FAKE_VOID_FUNC(Com_MainFunctionTx_ComMainFunctionTx_Event);

/* Define fake functions for SOME/IP */
DEFINE_FAKE_VOID_FUNC(Init_Provided_Services);
DEFINE_FAKE_VOID_FUNC(Init_Consumed_Services);
DEFINE_FAKE_VOID_FUNC(Process_Provided_Services);
DEFINE_FAKE_VOID_FUNC(Process_Consumed_Services);

/* Define fake functions for CAN Processing */
DEFINE_FAKE_VOID_FUNC(Process_Received_CAN_Msgs);
DEFINE_FAKE_VOID_FUNC(Send_Radar_Status_001_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Radar_Status_002_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Alignment_Status_001_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Radar_Capability_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Tracker_Status_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Radar_Header_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Alignment_Status_002_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Radar_Detection_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Tracker_Header_Messages);
DEFINE_FAKE_VOID_FUNC(Send_Tracker_Objects_On_CAN);
DEFINE_FAKE_VOID_FUNC(Com_IpduGroupStop, Com_IpduGroupIdType);
DEFINE_FAKE_VOID_FUNC(Com_IpduGroupStart, Com_IpduGroupIdType, boolean);
DEFINE_FAKE_VALUE_FUNC(Dt_AlignmentStatic *, Get_AlignmentStatic);
DEFINE_FAKE_VALUE_FUNC(Dt_AlignmentService *, Get_AlignmentService);
DEFINE_FAKE_VALUE_FUNC(Dt_AlignmentShortTrack *, Get_AlignmentShortTrack);
