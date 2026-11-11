/**
 * @file Fault_Lib_Prj_fake.cc
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
 * Mocks of the functions in Fault_Lib_Prj.c file.
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

#include "Fault_Lib_Prj_fake.h"
// Declare the wrapper function for testing
extern "C"
{
   Customer_fault_T *SWC_Appl_History_Fault_Table;
}

/* Provide minimal fake for platform getter used by Fault_Lib_Prj.c when
 * the platform source isn't linked into the unit test. Forward-declare a
 * compact compatible type to avoid pulling in the real header (which
 * conflicts with test fakes/types).
 */
extern "C"
{
   typedef struct
   {
      uint8_t Platform_byte[PLATFORM_FAULT_TABLE_SIZE];
   } Platform_fault_T;
   Platform_fault_T *Get_Platform_Active_Fault_Latch_Table(void)
   {
      static Platform_fault_T s_fake_platform_table;
      return &s_fake_platform_table;
   }
}

DEFINE_FAKE_VOID_FUNC(Platform_Active_Fault_Table);
DEFINE_FAKE_VOID_FUNC(Platform_Fault_Enable_Table);
