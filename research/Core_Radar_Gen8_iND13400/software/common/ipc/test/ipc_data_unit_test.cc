/*===========================================================================*/
/**
 * @file ipc_data_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for ipc_data.c
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC: Inter-Processor Communication
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - ipc_data Unit Test Design
 *
 *   - Requirements Document(s):
 *     - APO-266: Functional safety requirement
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files - Include source after mocks
 *===========================================================================*/
extern "C"
{
#include "ipc_data.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class IPC_Data_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      IPC_Notify_Buffer_Init();
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief IPC_Notify_Buffer_Init: After init, shared buffer should be zero-initialized.
 */
TEST_F(IPC_Data_UnitTestSuite, IPC_Notify_Buffer_Init_ClearsBuffer)
{
   IPC_Notify_Buffer_Init();
   EXPECT_EQ(Ipc_Shared_Buffer.ReadIndx[R52_TO_BBE_CORE], 0U) << "ReadIndx should be 0 after init";
   EXPECT_EQ(Ipc_Shared_Buffer.WriteIndx[R52_TO_BBE_CORE], 0U) << "WriteIndx should be 0 after init";
}

/**
 * @brief IPC_Notify_Buffer_Init: CRC engine should be set to FREE after init.
 */
TEST_F(IPC_Data_UnitTestSuite, IPC_Notify_Buffer_Init_CrcStatusFree)
{
   IPC_Notify_Buffer_Init();
   uint32_t crcBusy = Ipc_Shared_Buffer.Crc_ModuleState.Crc_EngineBusy;
   EXPECT_EQ(crcBusy, static_cast<uint8_t>(CRC_CH_STATUS_FREE)) << "CRC engine should be FREE after init";
}

/**
 * @brief Is_IPC_Notify_Buffer_Empty: Fresh buffer should be empty.
 */
TEST_F(IPC_Data_UnitTestSuite, IsIpcNotifyBufferEmpty_FreshBuffer_IsEmpty)
{
   uint8_t result = Is_IPC_Notify_Buffer_Empty(R52_TO_BBE_CORE);
   EXPECT_NE(result, 0U) << "Fresh buffer should be empty (ReadIndx == WriteIndx)";
}

/**
 * @brief Is_IPC_Notify_Buffer_Full: Fresh buffer should NOT be full.
 */
TEST_F(IPC_Data_UnitTestSuite, IsIpcNotifyBufferFull_FreshBuffer_IsNotFull)
{
   uint8_t result = Is_IPC_Notify_Buffer_Full(R52_TO_BBE_CORE);
   EXPECT_EQ(result, 0U) << "Fresh buffer should not be full";
}

/**
 * @brief Increment_IPC_Notify_WriteIndx: After one increment, buffer should not be empty.
 */
TEST_F(IPC_Data_UnitTestSuite, IncrementWriteIndx_Once_BufferNotEmpty)
{
   Increment_IPC_Notify_WriteIndx(R52_TO_BBE_CORE);
   uint8_t empty = Is_IPC_Notify_Buffer_Empty(R52_TO_BBE_CORE);
   EXPECT_EQ(empty, 0U) << "Buffer should not be empty after incrementing write index";
}

/**
 * @brief Increment_IPC_Notify_ReadIndx: Incrementing read after write makes buffer empty.
 */
TEST_F(IPC_Data_UnitTestSuite, IncrementReadIndx_AfterWrite_BufferBecomesEmpty)
{
   Increment_IPC_Notify_WriteIndx(R52_TO_BBE_CORE);
   Increment_IPC_Notify_ReadIndx(R52_TO_BBE_CORE);
   uint8_t empty = Is_IPC_Notify_Buffer_Empty(R52_TO_BBE_CORE);
   EXPECT_NE(empty, 0U) << "Buffer should be empty after incrementing read to match write";
}

/**
 * @brief Next_Ring_Buffer_Index: At max index, next wraps to 0.
 */
TEST_F(IPC_Data_UnitTestSuite, NextRingBufferIndex_MaxIndex_WrapsToZero)
{
   uint32_t next = Next_Ring_Buffer_Index(SIZE_OF_RING_BUFFER - 1U);
   EXPECT_EQ(next, 0U) << "Next index at max should wrap to 0";
}

/**
 * @brief Next_Ring_Buffer_Index: At non-max index, increments by 1.
 */
TEST_F(IPC_Data_UnitTestSuite, NextRingBufferIndex_NonMaxIndex_IncrementsBy1)
{
   uint32_t next = Next_Ring_Buffer_Index(1U);
   EXPECT_EQ(next, 2U) << "Next index should be current + 1 when not at max";
}

/**
 * @brief Next_Ring_Buffer_Index: Index 0 returns 1.
 */
TEST_F(IPC_Data_UnitTestSuite, NextRingBufferIndex_Zero_ReturnsOne)
{
   uint32_t next = Next_Ring_Buffer_Index(0U);
   EXPECT_EQ(next, 1U) << "Next of 0 should be 1";
}

/**
 * @brief Get_IPC_Notify_Buffer: Returns read buffer when readWrite = READ_BUFFER.
 */
TEST_F(IPC_Data_UnitTestSuite, GetIpcNotifyBuffer_ReadMode_ReturnsReadBuffer)
{
   volatile Ipc_Notify_Structure_T *buf = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, READ_BUFFER);
   ASSERT_NE(buf, nullptr) << "Should return a valid buffer pointer";
   /* Verify it points to the correct array element */
   EXPECT_EQ(buf, &Ipc_Shared_Buffer.Ipc_Notify_Buffers[R52_TO_BBE_CORE][0U]);
}

/**
 * @brief Get_IPC_Notify_Buffer: Returns write buffer when readWrite = WRITE_BUFFER.
 */
TEST_F(IPC_Data_UnitTestSuite, GetIpcNotifyBuffer_WriteMode_ReturnsWriteBuffer)
{
   volatile Ipc_Notify_Structure_T *buf = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, WRITE_BUFFER);
   ASSERT_NE(buf, nullptr) << "Should return a valid buffer pointer";
   EXPECT_EQ(buf, &Ipc_Shared_Buffer.Ipc_Notify_Buffers[R52_TO_BBE_CORE][0U]);
}

/**
 * @brief Get_Ipc_Shared_Buffer_Base_Address: Returns non-zero address.
 */
TEST_F(IPC_Data_UnitTestSuite, GetIpcSharedBufferBaseAddress_ReturnsNonZero)
{
   uint32_t addr = Get_Ipc_Shared_Buffer_Base_Address();
   EXPECT_NE(addr, 0U) << "Shared buffer base address should be non-zero";
}

/**
 * @brief volatile_memset: Sets all bytes in a region to the given value.
 */
TEST_F(IPC_Data_UnitTestSuite, VolatileMemset_SetsAllBytes)
{
   uint8_t buf[16];
   volatile void *result = volatile_memset((volatile void *)buf, 0xAB, sizeof(buf));
   ASSERT_NE(result, nullptr);
   for (size_t i = 0; i < sizeof(buf); i++)
   {
      EXPECT_EQ(buf[i], 0xABU) << "Byte " << i << " should be 0xAB";
   }
}

/**
 * @brief volatile_memset: Setting to zero clears all bytes.
 */
TEST_F(IPC_Data_UnitTestSuite, VolatileMemset_ClearsBuffer)
{
   uint8_t buf[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   volatile_memset((volatile void *)buf, 0, sizeof(buf));
   for (size_t i = 0; i < sizeof(buf); i++)
   {
      EXPECT_EQ(buf[i], 0U) << "Byte " << i << " should be cleared to 0";
   }
}

/**
 * @brief Is_IPC_Notify_Buffer_Full: Buffer becomes full when write fills all slots.
 */
TEST_F(IPC_Data_UnitTestSuite, IsIpcNotifyBufferFull_FullBuffer_ReturnsTrue)
{
   /* Fill the ring buffer by incrementing write SIZE_OF_RING_BUFFER-1 times */
   for (uint32_t i = 0U; i < (SIZE_OF_RING_BUFFER - 1U); i++)
   {
      Increment_IPC_Notify_WriteIndx(R52_TO_BBE_CORE);
   }
   uint8_t full = Is_IPC_Notify_Buffer_Full(R52_TO_BBE_CORE);
   EXPECT_NE(full, 0U) << "Buffer should be full after filling all slots";
}
