/*===========================================================================*/
/**
 * @file ipc_data_fake.h
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
 * Fake/Mock header file for IPC data module unit testing
 * Uses FFF (Fake Function Framework) for function mocking
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef IPC_DATA_FAKE_H
#define IPC_DATA_FAKE_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*===========================================================================*
 * Includes
 *===========================================================================*/
#include "ipc_data.h"

   /*===========================================================================*
    * FFF Function Declarations - IPC Data Functions
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(volatile Ipc_Notify_Structure_T *, Get_IPC_Notify_Buffer, Core_To_Core_ID_T, Ring_Buffer_RW_T);
   DECLARE_FAKE_VOID_FUNC(IPC_Notify_Buffer_Init);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_Ipc_Shared_Buffer_Base_Address);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Is_IPC_Notify_Buffer_Empty, Core_To_Core_ID_T);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Is_IPC_Notify_Buffer_Full, Core_To_Core_ID_T);
   DECLARE_FAKE_VOID_FUNC(Increment_IPC_Notify_ReadIndx, Core_To_Core_ID_T);
   DECLARE_FAKE_VOID_FUNC(Increment_IPC_Notify_WriteIndx, Core_To_Core_ID_T);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Next_Ring_Buffer_Index, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(volatile void *, volatile_memset, volatile void *, int, size_t);

/*===========================================================================*
 * Helper Macros for Test Setup
 *===========================================================================*/

/**
 * @brief Reset all IPC data mocks
 * Call this in SetUp() or at the beginning of each test
 */
#define RESET_IPC_DATA_MOCKS(FAKE)                                                                                                \
   RESET_FAKE(Get_IPC_Notify_Buffer);                                                                                             \
   RESET_FAKE(IPC_Notify_Buffer_Init);                                                                                            \
   RESET_FAKE(Get_Ipc_Shared_Buffer_Base_Address);                                                                                \
   RESET_FAKE(Is_IPC_Notify_Buffer_Empty);                                                                                        \
   RESET_FAKE(Is_IPC_Notify_Buffer_Full);                                                                                         \
   RESET_FAKE(Increment_IPC_Notify_ReadIndx);                                                                                     \
   RESET_FAKE(Increment_IPC_Notify_WriteIndx);                                                                                    \
   RESET_FAKE(Next_Ring_Buffer_Index);                                                                                            \
   RESET_FAKE(volatile_memset)

#ifdef __cplusplus
}
#endif

#endif /* IPC_DATA_FAKE_H */
