/*===========================================================================*/
/**
 * @file crc_calc_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * B0-variant unit tests for crc_calc.c.
 *
 * Functions under test (compiled when UNIT_TEST is defined):
 *   - Compute_CRC32_SW        (SW table-based CRC32)
 *   - Calc_M2D_Buf_Crc        (M2D IPC buffer CRC via SW CRC)
 *   - Calc_D2M_Buf_Crc_Chn_X  (D2M IPC buffer CRC via HW channel)
 *   - Crc_AreAllEnginesBusy   (B0 inline: per-channel busy check)
 *
 * All HW-engine functions (Reflect32, ARM_CRC_Control, CRC_CalculateCRCX,
 * Crc_CalculateCRC32_HW, Crc_GetChannelRegs, ARM_CRC_CalculateCRC32)
 * live inside #ifndef UNIT_TEST and are NOT compiled for unit tests.
 * Crc_CalculateCRC32_HW is faked via FFF since Calc_D2M_Buf_Crc_Chn_X
 * calls it.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Forward-declare Crc_CalculateCRC32_HW as a FFF fake BEFORE including
 * crc_calc.c.  The real definition is inside #ifndef UNIT_TEST, so we
 * supply the fake that Calc_D2M_Buf_Crc_Chn_X will call.
 *===========================================================================*/
extern "C"
{
   /* Fake for HW CRC – called by Calc_D2M_Buf_Crc_Chn_X */
   static uint32_t Crc_CalculateCRC32_HW(const uint8_t *Crc_DataPtr, uint32_t Crc_Length, uint32_t Crc_StartValue32,
                                         bool Crc_IsFirstCall, uint8_t channel);
}

/*===========================================================================*
 * Textual inclusion of the TU
 *===========================================================================*/
extern "C"
{
   /* Fake for external dependency */
   FAKE_VALUE_FUNC(uint32_t, Get_Ipc_Shared_Buffer_Base_Address);

#include "crc_calc.c"
}

/*===========================================================================*
 * Provide the Crc_CalculateCRC32_HW fake body AFTER crc_calc.c so we
 * have access to the types it defines.
 * Returns a fixed value so tests can verify the D2M path calls it.
 *===========================================================================*/
static uint32_t g_fake_hw_crc_return      = 0xDEADBEEFU;
static uint32_t g_fake_hw_crc_call_count  = 0U;
static uint8_t g_fake_hw_crc_last_channel = 0xFFU;

static uint32_t Crc_CalculateCRC32_HW(const uint8_t *Crc_DataPtr, uint32_t Crc_Length, uint32_t Crc_StartValue32,
                                      bool Crc_IsFirstCall, uint8_t channel)
{
   (void)Crc_DataPtr;
   (void)Crc_Length;
   (void)Crc_StartValue32;
   (void)Crc_IsFirstCall;
   g_fake_hw_crc_call_count++;
   g_fake_hw_crc_last_channel = channel;
   return g_fake_hw_crc_return;
}

/*===========================================================================*
 * Test Fixture
 *===========================================================================*/
class CrcCalcB0Test : public testing::Test
{
 protected:
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Get_Ipc_Shared_Buffer_Base_Address);
      g_fake_hw_crc_return       = 0xDEADBEEFU;
      g_fake_hw_crc_call_count   = 0U;
      g_fake_hw_crc_last_channel = 0xFFU;
      /* Reset static CRC tables to avoid cross-test contamination */
      memset(IPC_M2D_Crc_Cal_Tab, 0, sizeof(IPC_M2D_Crc_Cal_Tab));
      memset(IPC_D2M_Crc_Cal_Tab, 0, sizeof(IPC_D2M_Crc_Cal_Tab));
   }
   void TearDown() override
   {
   }
};

/* ===================================================================== *
 * 1. Compute_CRC32_SW
 * ===================================================================== */

/* firstCall = true  →  seed = 0xFFFFFFFF, standard CRC32 of 10 zero bytes */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_FirstCall_AllZeros)
{
   uint8_t buf[10] = {0};
   uint32_t crc    = Compute_CRC32_SW(buf, 10U, 0U, true);
   /* firstCall ignores start_value and uses 0xFFFFFFFF as init.
    * Verify determinism and non-trivial result. */
   uint32_t crc2 = Compute_CRC32_SW(buf, 10U, 0U, true);
   EXPECT_EQ(crc, crc2);
   EXPECT_NE(crc, 0U);
   /* Standard CRC32 of 10 zero bytes = 0xE38A6876 */
   EXPECT_EQ(crc, 0xE38A6876U);
}

/* firstCall = false  →  seed = FINAL_XOR ^ start_value, then process */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_NotFirstCall_AllZeros)
{
   uint8_t buf[10] = {0};
   /* When firstCall=false, start_value=0 → internal init = 0xFFFFFFFF ^ 0 = 0xFFFFFFFF
    * Same initial state as firstCall=true, so result should match. */
   uint32_t crc_first    = Compute_CRC32_SW(buf, 10U, 0U, true);
   uint32_t crc_notfirst = Compute_CRC32_SW(buf, 10U, 0U, false);
   /* firstCall=false, start=0 → XOR final = 0xFFFFFFFF → same seed as firstCall=true */
   EXPECT_EQ(crc_notfirst, crc_first);
}

/* Standard CRC32/Ethernet test vector: "123456789" → 0xCBF43926 */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_StandardVector)
{
   uint8_t data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   uint32_t crc   = Compute_CRC32_SW(data, 9U, 0U, true);
   EXPECT_EQ(crc, 0xCBF43926U);
}

/* Empty data (length = 0) → XOR of init with final = 0 */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_ZeroLength)
{
   uint8_t buf[1] = {0};
   uint32_t crc   = Compute_CRC32_SW(buf, 0U, 0U, true);
   /* Loop does not execute; result = init ^ final = 0xFFFFFFFF ^ 0xFFFFFFFF = 0 */
   EXPECT_EQ(crc, 0x00000000U);
}

/* Single byte */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_SingleByte)
{
   uint8_t data = 0xAA;
   uint32_t crc = Compute_CRC32_SW(&data, 1U, 0U, true);
   /* Verify determinism – same input → same output */
   uint32_t crc2 = Compute_CRC32_SW(&data, 1U, 0U, true);
   EXPECT_EQ(crc, crc2);
   /* Non-zero result expected */
   EXPECT_NE(crc, 0U);
}

/* Chained calls: firstCall=true, then continuation */
TEST_F(CrcCalcB0Test, ComputeCRC32SW_ChainedCalls)
{
   uint8_t part1[] = {'1', '2', '3', '4', '5'};
   uint8_t part2[] = {'6', '7', '8', '9'};

   /* CRC of full "123456789" in one shot */
   uint8_t full[]    = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   uint32_t crc_full = Compute_CRC32_SW(full, 9U, 0U, true);

   /* Chained: first part, then continuation */
   uint32_t crc_a = Compute_CRC32_SW(part1, 5U, 0U, true);
   uint32_t crc_b = Compute_CRC32_SW(part2, 4U, crc_a, false);
   EXPECT_EQ(crc_b, crc_full);
}

/* ===================================================================== *
 * 2. Crc_AreAllEnginesBusy  (B0 inline)
 * ===================================================================== */

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_AllBusy_ReturnsTrue)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   state.Crc_EngineBusyCh0 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh1 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh2 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh3 = (uint32_t)CRC_CH_STATUS_BUSY;
   EXPECT_TRUE(Crc_AreAllEnginesBusy(&state));
}

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_Ch0Free_ReturnsFalse)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   state.Crc_EngineBusyCh0 = (uint32_t)CRC_CH_STATUS_FREE;
   state.Crc_EngineBusyCh1 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh2 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh3 = (uint32_t)CRC_CH_STATUS_BUSY;
   EXPECT_FALSE(Crc_AreAllEnginesBusy(&state));
}

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_Ch1Free_ReturnsFalse)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   state.Crc_EngineBusyCh0 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh1 = (uint32_t)CRC_CH_STATUS_FREE;
   state.Crc_EngineBusyCh2 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh3 = (uint32_t)CRC_CH_STATUS_BUSY;
   EXPECT_FALSE(Crc_AreAllEnginesBusy(&state));
}

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_Ch2Free_ReturnsFalse)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   state.Crc_EngineBusyCh0 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh1 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh2 = (uint32_t)CRC_CH_STATUS_FREE;
   state.Crc_EngineBusyCh3 = (uint32_t)CRC_CH_STATUS_BUSY;
   EXPECT_FALSE(Crc_AreAllEnginesBusy(&state));
}

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_Ch3Free_ReturnsFalse)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   state.Crc_EngineBusyCh0 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh1 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh2 = (uint32_t)CRC_CH_STATUS_BUSY;
   state.Crc_EngineBusyCh3 = (uint32_t)CRC_CH_STATUS_FREE;
   EXPECT_FALSE(Crc_AreAllEnginesBusy(&state));
}

TEST_F(CrcCalcB0Test, AreAllEnginesBusy_AllFree_ReturnsFalse)
{
   IPC_Crc_ModuleStateType_T state;
   memset(&state, 0, sizeof(state));
   EXPECT_FALSE(Crc_AreAllEnginesBusy(&state));
}

/* ===================================================================== *
 * 3. Calc_M2D_Buf_Crc
 * ===================================================================== */

TEST_F(CrcCalcB0Test, CalcM2DBufCrc_ReturnsNonZero)
{
   /* Allocate and zero-init an M2D message */
   M2D_Msg_T msg;
   memset(&msg, 0, sizeof(msg));

   uint32_t crc = Calc_M2D_Buf_Crc(&msg);
   /* SW CRC of zeroed signals → deterministic non-trivial value */
   EXPECT_NE(crc, 0U);
}

TEST_F(CrcCalcB0Test, CalcM2DBufCrc_DifferentPayloadGivesDifferentCrc)
{
   M2D_Msg_T msg1;
   memset(&msg1, 0, sizeof(msg1));

   M2D_Msg_T msg2;
   memset(&msg2, 0xAA, sizeof(msg2));

   uint32_t crc1 = Calc_M2D_Buf_Crc(&msg1);
   uint32_t crc2 = Calc_M2D_Buf_Crc(&msg2);
   EXPECT_NE(crc1, crc2);
}

TEST_F(CrcCalcB0Test, CalcM2DBufCrc_Deterministic)
{
   M2D_Msg_T msg;
   memset(&msg, 0x55, sizeof(msg));

   /* Reset the static CRC table so both calls start from same state */
   memset(IPC_M2D_Crc_Cal_Tab, 0, sizeof(IPC_M2D_Crc_Cal_Tab));
   uint32_t crc1 = Calc_M2D_Buf_Crc(&msg);
   /* Reset again before second call — the static table carries state */
   memset(IPC_M2D_Crc_Cal_Tab, 0, sizeof(IPC_M2D_Crc_Cal_Tab));
   uint32_t crc2 = Calc_M2D_Buf_Crc(&msg);
   EXPECT_EQ(crc1, crc2);
}

/* NULL buffer_ptr → signal table entries not populated, only CRC tab entry
 * is built.  Exercises the false branch of (NULL != buffer_ptr). */
TEST_F(CrcCalcB0Test, CalcM2DBufCrc_NullPtr)
{
   /* Clear signal table so startAddr entries are NULL */
   memset(M2D_Crc_Calc_Sig, 0, sizeof(M2D_Crc_Calc_Sig));
   uint32_t crc = Calc_M2D_Buf_Crc(NULL);
   /* With NULL buffer, only CRC tab entry is processed → still returns a value */
   (void)crc; /* result depends on IPC_M2D_Crc_Cal_Tab state, just ensure no crash */
}

/* Force a NULL startAddr inside the M2D loop to cover the false branch
 * of (NULL != M2D_Crc_Calc_Sig[idx].startAddr). */
TEST_F(CrcCalcB0Test, CalcM2DBufCrc_NullStartAddr_Skipped)
{
   M2D_Msg_T msg;
   memset(&msg, 0, sizeof(msg));

   /* First call populates the signal table normally */
   (void)Calc_M2D_Buf_Crc(&msg);

   /* Now NULL-out one of the signal entries and call again.
    * The loop re-populates from buffer_ptr, so we NULL the buffer_ptr
    * path to leave entries empty, but the CRC tab entry always exists. */
   memset(M2D_Crc_Calc_Sig, 0, sizeof(M2D_Crc_Calc_Sig));
   /* Call with NULL so only CRC tab entry is built; other entries stay NULL */
   uint32_t crc = Calc_M2D_Buf_Crc(NULL);
   (void)crc;
}

/* Force a NULL startAddr inside the D2M loop by passing NULL buffer_ptr. */
TEST_F(CrcCalcB0Test, CalcD2MBufCrc_NullPtr_NullStartAddrSkipped)
{
   IPC_Shared_Buffers_T ipc_buf;
   memset(&ipc_buf, 0, sizeof(ipc_buf));
   Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uint32_t)(uintptr_t)&ipc_buf;

   /* Clear signal table so all startAddr entries are NULL */
   memset(D2M_Crc_Calc_Sig, 0, sizeof(D2M_Crc_Calc_Sig));
   g_fake_hw_crc_return = 0x42U;
   uint32_t crc         = Calc_D2M_Buf_Crc_Chn_X(NULL, ARM_CRC_CHANNEL0);
   /* With NULL buffer_ptr, only CRC tab entry has non-NULL startAddr.
    * Other entries stay NULL → exercises the false branch. */
   EXPECT_GE(g_fake_hw_crc_call_count, 1U);
}

/* ===================================================================== *
 * 4. Calc_D2M_Buf_Crc_Chn_X
 * ===================================================================== */

TEST_F(CrcCalcB0Test, CalcD2MBufCrc_NullPtr_ReturnsHwCrc)
{
   /* NULL buffer_ptr → skips signal table build, still iterates
    * over the IPC_D2M_Crc_Cal_Tab entry calling HW CRC */
   IPC_Shared_Buffers_T ipc_buf;
   memset(&ipc_buf, 0, sizeof(ipc_buf));
   Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uint32_t)(uintptr_t)&ipc_buf;

   g_fake_hw_crc_return = 0x12345678U;
   uint32_t crc         = Calc_D2M_Buf_Crc_Chn_X(NULL, ARM_CRC_CHANNEL0);
   /* With NULL, only the CRC-tab entry is populated → 1 call to HW CRC */
   EXPECT_GE(g_fake_hw_crc_call_count, 1U);
   EXPECT_EQ(crc, 0x12345678U);
}

TEST_F(CrcCalcB0Test, CalcD2MBufCrc_Channel0_CallsHwWithCh0)
{
   D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));

   IPC_Shared_Buffers_T ipc_buf;
   memset(&ipc_buf, 0, sizeof(ipc_buf));
   Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uint32_t)(uintptr_t)&ipc_buf;

   g_fake_hw_crc_return = 0xAABBCCDDU;
   uint32_t crc         = Calc_D2M_Buf_Crc_Chn_X(&d2m, ARM_CRC_CHANNEL0);
   EXPECT_EQ(g_fake_hw_crc_last_channel, ARM_CRC_CHANNEL0);
   EXPECT_EQ(crc, 0xAABBCCDDU);
   /* With DOWNSELECTION_ENABLE=0, there are 7 entries: diag, fault_table,
    * det_data.af_data, toi_stream_data (ip+op combined), alignment_stream_data,
    * dynamic_alignment_log_stream, CRC tab = 7 calls */
   EXPECT_EQ(g_fake_hw_crc_call_count, 7U);
}

TEST_F(CrcCalcB0Test, CalcD2MBufCrc_Channel1_CallsHwWithCh1)
{
   D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));

   IPC_Shared_Buffers_T ipc_buf;
   memset(&ipc_buf, 0, sizeof(ipc_buf));
   Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uint32_t)(uintptr_t)&ipc_buf;

   g_fake_hw_crc_return = 0x11223344U;
   uint32_t crc         = Calc_D2M_Buf_Crc_Chn_X(&d2m, ARM_CRC_CHANNEL1);
   EXPECT_EQ(g_fake_hw_crc_last_channel, ARM_CRC_CHANNEL1);
   EXPECT_EQ(crc, 0x11223344U);
   EXPECT_EQ(g_fake_hw_crc_call_count, 7U);
}

TEST_F(CrcCalcB0Test, CalcD2MBufCrc_InvalidChannel_NoHwCall)
{
   D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));

   IPC_Shared_Buffers_T ipc_buf;
   memset(&ipc_buf, 0, sizeof(ipc_buf));
   Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uint32_t)(uintptr_t)&ipc_buf;

   /* Channel 5 is neither CHANNEL0 nor CHANNEL1 → neither if/else-if taken */
   uint32_t crc = Calc_D2M_Buf_Crc_Chn_X(&d2m, 5U);
   EXPECT_EQ(g_fake_hw_crc_call_count, 0U);
   EXPECT_EQ(crc, 0U);
}
