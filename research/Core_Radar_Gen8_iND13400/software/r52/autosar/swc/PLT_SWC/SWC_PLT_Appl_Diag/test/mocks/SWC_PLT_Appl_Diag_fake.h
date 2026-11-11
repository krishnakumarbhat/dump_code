/**
 * @file SWC_PLT_Appl_Diag_fake.h
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
 * Mocks of the functions in SWC_PLT_Appl_Diag.c file.
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
#ifndef SWC_PLT_APPL_DIAG_FAKE_H_
#define SWC_PLT_APPL_DIAG_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(Diag_Init);
   DECLARE_FAKE_VOID_FUNC(Diag_Battery_Fault_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Can_Bus_Off_Fault_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Host_Microcontroller_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Inter_Processor_Communication_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Memory_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Radar_Blockage_Detection_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Radar_Interference_Detection_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Radar_Hardware_Tests_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Radar_Transceiver_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Tracker_Calibration_Checksum_Fault_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Alignment_Diagnostics_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_PlatformTime_Test_50ms);
   DECLARE_FAKE_VOID_FUNC(Diag_Microprocessor_Temp_Tests_50ms);
#ifdef __cplusplus
}
#endif

#define FFF_FAKES_RADAR_STATUS_LIST(FAKE)                                                                                         \
   FAKE(Diag_Battery_Fault_Tests_50ms)                                                                                            \
   FAKE(Diag_Can_Bus_Off_Fault_Test_50ms)                                                                                         \
   FAKE(Diag_Host_Microcontroller_Tests_50ms)                                                                                     \
   FAKE(Diag_Inter_Processor_Communication_Diagnostics_50ms)                                                                      \
   FAKE(Diag_Memory_Diagnostics_50ms)                                                                                             \
   FAKE(Diag_Radar_Blockage_Detection_Test_50ms)                                                                                  \
   FAKE(Diag_Radar_Interference_Detection_Test_50ms)                                                                              \
   FAKE(Diag_Radar_Hardware_Tests_50ms)                                                                                           \
   FAKE(Diag_Radar_Transceiver_Diagnostics_50ms)                                                                                  \
   FAKE(Diag_Tracker_Calibration_Checksum_Fault_Test_50ms)                                                                        \
   FAKE(Diag_Init)
#endif
