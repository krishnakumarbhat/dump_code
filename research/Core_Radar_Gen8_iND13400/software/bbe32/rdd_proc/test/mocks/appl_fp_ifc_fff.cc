/**
 * @file appl_fp_ifc_fff.cc
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
 * Mocks for the rdd_process_ifc.c files.
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
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include "appl_fp_ifc_fff.h"
#include "fff.h"
/* DEFINE_FFF_GLOBALS MUST be called in the unit test file */

/*===========================================================================*
 * Fake value functions - rdd_process_ifc
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(uint16_t *, Get_Cdc_Dbin_Array_Buffer_Ptr);
DEFINE_FAKE_VALUE_FUNC(bool *, Get_Ci_Flag_Array_Buffer_Ptr);

DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Dram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Sram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(bool, Appl_First_Pass_Execute, uint16_t, D2M_Msg_T *, BvCompTypePtr);
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Rdd_Fp_Init, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Update_Rdd_Instrumentation_Variables);
/*===========================================================================*
 * Mock the internal data structure
 *===========================================================================*/
extern "C"
{
}
