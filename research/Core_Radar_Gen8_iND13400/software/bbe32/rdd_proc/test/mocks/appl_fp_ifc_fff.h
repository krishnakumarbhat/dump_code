/**
 * @file appl_fp_ifc_fff.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mock the functions of file rdd_process_ifc.c
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
#ifndef APPPL_FP_IFC_FFF_H
#define APPPL_FP_IFC_FFF_H
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_fp_ifc.h"

/*===========================================================================*
 * Type definitions for complex fake function parameters
 *===========================================================================*/
typedef BV_Comp_Type_T (*BvCompTypePtr)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE];

/*===========================================================================*
 * Fake value functions - appl_fp_ifc
 *===========================================================================*/

DECLARE_FAKE_VALUE_FUNC(uint16_t *, Get_Cdc_Dbin_Array_Buffer_Ptr);
DECLARE_FAKE_VALUE_FUNC(bool *, Get_Ci_Flag_Array_Buffer_Ptr);

DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Dram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Sram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(bool, Appl_First_Pass_Execute, uint16_t, D2M_Msg_T *, BvCompTypePtr);
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Rdd_Fp_Init, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Update_Rdd_Instrumentation_Variables);
/* List of fakes used by this unit tester */
#define FFF_FAKES_APPL_FP_IFC_LIST(FAKE)                                                                                          \
   FAKE(Get_Cdc_Dbin_Array_Buffer_Ptr)                                                                                            \
   FAKE(Get_Ci_Flag_Array_Buffer_Ptr)                                                                                             \
   FAKE(Appl_Rdd_Dram1_Memory_Init)                                                                                               \
   FAKE(Appl_Rdd_Sram1_Memory_Init)                                                                                               \
   FAKE(Appl_First_Pass_Execute)                                                                                                  \
   FAKE(Appl_Rdd_Fp_Init)                                                                                                         \
   FAKE(Update_Rdd_Instrumentation_Variables)
#endif /* APPPL_FP_IFC_FFF_H */
