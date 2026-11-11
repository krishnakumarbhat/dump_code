/**
 * @file SWC_PLT_Appl_FaultMgr_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in SWC_PLT_Appl_FaultMgr.c file.
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
#ifndef SWC_PLT_APPL_FAULT_FAKE_H_
#define SWC_PLT_APPL_FAULT_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "SWC_PLT_Appl_FaultMgr.h"

   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Radar_Blockage_Detection_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Alignment_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Battery_Fault_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_General_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Host_Microcontroller_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Init);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Interprocessor_Comm_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Main_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Memory_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Microprocessor_Temp_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Radar_Hardware_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Fault_Mgr_Radar_Transceiver_Diagnostics_50ms);
   DECLARE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Active_Fault_Table);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_ReadBlock, uint16, void *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_WriteBlock, uint16, const void *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_GetErrorStatus, uint16, uint8 *);
   DECLARE_FAKE_VOID_FUNC(Platform_memory_Copy, void *, void *, uint8);

#ifdef __cplusplus
}
#endif

#endif
