/*===========================================================================*/
/**
 * @file ipc_data_fake.cc
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
 * Fake function definitions for the ipc_data module.
 * Uses FFF (Fake Function Framework) for function mocking in unit tests.
 *
 * @section ABBR ABBREVIATIONS:
 *   - FFF: Fake Function Framework
 *   - IPC: Inter-Processor Communication
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
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "ipc_data_fake.h"

/*===========================================================================*
 * Fake value functions - IPC Data Functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(volatile Ipc_Notify_Structure_T *, Get_IPC_Notify_Buffer, Core_To_Core_ID_T, Ring_Buffer_RW_T);
DEFINE_FAKE_VOID_FUNC(IPC_Notify_Buffer_Init);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Ipc_Shared_Buffer_Base_Address);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Is_IPC_Notify_Buffer_Empty, Core_To_Core_ID_T);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Is_IPC_Notify_Buffer_Full, Core_To_Core_ID_T);
DEFINE_FAKE_VOID_FUNC(Increment_IPC_Notify_ReadIndx, Core_To_Core_ID_T);
DEFINE_FAKE_VOID_FUNC(Increment_IPC_Notify_WriteIndx, Core_To_Core_ID_T);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Next_Ring_Buffer_Index, uint32_t);
DEFINE_FAKE_VALUE_FUNC(volatile void *, volatile_memset, volatile void *, int, size_t);

/*===========================================================================*
 * Mock the internal data structure (if needed)
 *===========================================================================*/
extern "C"
{
   // Add any internal data structure mocks here if needed for testing
}
