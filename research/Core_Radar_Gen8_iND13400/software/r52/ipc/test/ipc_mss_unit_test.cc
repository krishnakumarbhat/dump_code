/*===========================================================================*/
/**
 * @file ipc_mss_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for ipc_mss.c – covers DDR-4176 IPC CRC refactor changes:
 *   - New getter/setter API for DSP_Init, Received_Doppler_Done,
 *     M2D_Buffer_Full_Error_Counter, DSP_Cfg_Init
 *   - New counter getters: Get_IPC_M2D_Crc_Err_Cnt, Get_IPC_D2M_Crc_Err_Cnt,
 *     Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx
 *   - Check_BBE32_To_R52_Header / Check_D2M_Crc_Header inverted-return-logic
 *   - Update_IPC_M2D_Header: CRC in local variable (no more global M2D_CRC_Calculated)
 *   - Update_R52_IPC_Notify: simplified CRC error condition
 *     (only R52_TO_BBE32_CRC_ERROR increments IPC_M2D_Crc_Err_Cnt)
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstddef>
#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * Mock headers – included before ipc_mss.c compilation so the source sees
 * the FFF fakes rather than real function bodies.
 *===========================================================================*/
#include "FS_IntHndlr_fake.h"
#include "Rte_SWC_PLT_CDD_Radar_Control_fake.h"
#include "SWC_PLT_Appl_PlatformTime_fake.h"
#include "SWC_PLT_CDD_ECUSync_external_fake.h"
#include "crc_calc_mocks.h"
#include "ipc_data_fake.h"
#include "program_flow_monitor_fff.h"

/*===========================================================================*
 * Additional stub declarations – RTE trigger calls used inside
 * Update_R52_IPC_Notify and not covered by the existing fake libraries.
 * Placed before #include "ipc_mss.c" so they compile into the same TU.
 *===========================================================================*/
extern "C"
{
   static uint32_t g_last_frame_time_look_index     = 0U;
   static uint8_t g_last_frame_time_ping_pong_index = 0U;

   /* dsp_setup.c exports this; stub it so the linker does not need the real impl */
   bool DSP_Done_Processing(void)
   {
      return false;
   }

   void Record_Frame_Start_Time(uint32_t look_index, uint8_t ping_pong_index)
   {
      (void)look_index;
      (void)ping_pong_index;
   }

   void Update_Frame_Time_For_Look(uint32_t look_index, uint8_t ping_pong_index)
   {
      g_last_frame_time_look_index      = look_index;
      g_last_frame_time_ping_pong_index = ping_pong_index;
   }

   uint32_t Get_Frame_Time(uint32_t look_index)
   {
      (void)look_index;
      return 0U;
   }

   /* HIL injection stub – HIL_Injection_Request is called inside
    * Update_R52_IPC_Notify when DSP done processing. */
   void HIL_Injection_Request(void)
   {
   }

   /* IrTrigger stub – plain C stub; no FFF tracking needed for DDR-4176 tests. */
   void Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete(void)
   {
   }

   void Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger(void)
   {
   }

   uint8_t Get_RA_R52_ERROR_Failure_State(void)
   {
      return 0U;
   }

   void Set_RA_R52_ERROR_Failure_State(uint8_t value)
   {
      (void)value;
   }

   uint8_t Get_RA_R52_FUSA_Failure_State(void)
   {
      return 0U;
   }

   void Set_RA_R52_FUSA_Failure_State(uint8_t value)
   {
      (void)value;
   }

   /* dsp_setup.c variable definitions used by ipc_mss.c */
   uint8_t R52_M2D_Buffer_Index    = 0U;
   uint32_t R52_M2D_Msg_Header_Cnt = 0U;

   /* Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger and
    * Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx are already
    * DEFINED by Rte_SWC_PLT_CDD_Radar_Control_fake_lib – do not redefine. */
}

/*===========================================================================*
 * Local fake HW register memory for host unit tests.
 * Same technique as dsp_setup_unit_test.cc: map memory at the real DSP_base
 * address so DSP-> accesses inside ipc_mss.c don't segfault.
 *===========================================================================*/
#ifdef _WIN32
extern "C" void *VirtualAlloc(void *lpAddress, size_t dwSize, unsigned long flAllocationType, unsigned long flProtect);

   #ifndef MEM_COMMIT
      #define MEM_COMMIT 0x1000UL
   #endif
   #ifndef MEM_RESERVE
      #define MEM_RESERVE 0x2000UL
   #endif
   #ifndef PAGE_READWRITE
      #define PAGE_READWRITE 0x04UL
   #endif
#else
   #include <sys/mman.h>
#endif

static void *g_dsp_hw_map = nullptr;

/*===========================================================================*
 * Include unit under test
 *===========================================================================*/
extern "C"
{
/* Enable IPC CRC so Check_BBE32_To_R52_Header exercises the refactored path */
#define ENABLE_IPC_CRC
#define ENABLE_IPC_CRC_PROFILING
#define XCP_FAULT_INJECTION TRUE

/* Strip volatile for host-side unit test (same technique as dsp_setup test) */
#define volatile
#include "ipc_mss.c"
#undef volatile
}

/*===========================================================================*
 * FFF global state
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/* Global definition required by extern declaration in ipc_mss.c */
IPC_MMIC_Radar_Data_Status_T Radar_Data_Status = {0};

/*===========================================================================*
 * Test Suite
 *===========================================================================*/
class Ipc_Mss_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      /* Map memory at real DSP_base for code inside ipc_mss.c */
      if (g_dsp_hw_map == nullptr)
      {
#ifdef _WIN32
         g_dsp_hw_map = VirtualAlloc((void *)(uintptr_t)DSP_base, sizeof(DSP_SFRS_t), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
#else
         g_dsp_hw_map = mmap((void *)(uintptr_t)DSP_base, sizeof(DSP_SFRS_t), PROT_READ | PROT_WRITE,
                             MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
         if (g_dsp_hw_map == MAP_FAILED)
         {
            g_dsp_hw_map = nullptr;
         }
#endif
      }

      volatile DSP_SFRS_t *const dsp_regs = (volatile DSP_SFRS_t *)DSP_base;
      if (g_dsp_hw_map != nullptr)
      {
         memset((void *)dsp_regs, 0, sizeof(*dsp_regs));
      }

      FFF_FAKES_RTE_SWC_PLT_CDD_RADAR_CONTROL(RESET_FAKE);
      FFF_FAKES_CRC_CALC_LIST(RESET_FAKE);
      RESET_IPC_DATA_MOCKS(RESET_FAKE);
      FFF_FAKE_SWC_PLATFORMTIME(RESET_FAKE);
      FFF_FAKES_PROGRAM_FLOW_MONITOR_LIST(RESET_FAKE);
      FFF_FAKES_FUSA_HANDLER_LIST(RESET_FAKE);
      RESET_FAKE(Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger);
      FFF_RESET_HISTORY();

      /* Reset module-level state */
      DSP_Init                        = false;
      Received_Doppler_Done           = false;
      Received_Doppler_Stream         = false;
      DSP_Cfg_Init                    = DSP_CONFIG_NO_ERROR;
      M2D_Buffer_Full_Error_Counter   = 0U;
      IPC_M2D_Crc_Err_Cnt             = 0U;
      IPC_D2M_Crc_Err_Cnt             = 0U;
      IPC_Dopp_RDD_Comp_Buf_Read_idx  = 0U;
      Ping_Buf_Addr                   = 0U;
      Pong_Buf_Addr                   = 0U;
      R52_M2D_Buffer_Index            = 0U;
      R52_M2D_Msg_Header_Cnt          = 0U;
      R52_D2M_Msg_Header_Cnt          = 0U;
      DSP_No_Command_Cnt              = 0U;
      DSP_Write_IPC_Index             = 0U;
      IPC_Dopp_RDD_Comp_Buf_Read_Addr = NULL;
      IPC_Sp_Post_Proc_Buf_Read_Addr  = NULL;
      IPC_Sp_Post_Buf_Read_Addr_Raw   = NULL;
      IPC_Sp_Post_Buf_Read_Idx_Raw    = 0U;
      Received_Doppler_Stream         = false;
      memset(&DSP_Range_Config_Counts, 0, sizeof(DSP_Range_Config_Counts));
      memset(&DSP_Range_Process_Complete_Counts, 0, sizeof(DSP_Range_Process_Complete_Counts));
      memset(&DSP_Doppler_Process_Complete_Counts, 0, sizeof(DSP_Doppler_Process_Complete_Counts));
      memset(&DSP_Sp_Post_Complete_Counts, 0, sizeof(DSP_Sp_Post_Complete_Counts));
      memset(&Radar_Data_Status, 0, sizeof(Radar_Data_Status));

      IPC_D2M_Start_Time_Us     = 0U;
      IPC_D2M_Delta_Time_Us     = 0U;
      IPC_D2M_Max_Delta_Time_Us = 0U;
      IPC_D2M_Min_Delta_Time_Us = 1000000U;
      FailCnt_IPC_ISR           = 0U;

      /* Reset CRC profiling state */
      M2D_CRC_Compute_Time_us           = 0U;
      D2M_CRC_Compute_Time_us           = 0U;
      M2D_CRC_Compute_Time_Max_us       = 0U;
      M2D_CRC_Compute_Time_Min_us       = UINT32_MAX;
      D2M_CRC_Compute_Time_Max_us       = 0U;
      D2M_CRC_Compute_Time_Min_us       = UINT32_MAX;
      g_last_frame_time_look_index      = 0U;
      g_last_frame_time_ping_pong_index = 0U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * DDR-4176 — A.  Set_DSP_Init_Status  (new setter, DDR-4176)
 *
 * was: callers (dsp_setup.c) wrote DSP_Init directly
 * now: Set_DSP_Init_Status(val) / Get_DSP_Init_Status() encapsulate the var
 *===========================================================================*/

/**
 *  @b set_dsp_init_status_true
 *  @n
 *      Set_DSP_Init_Status(true) must make Get_DSP_Init_Status() return true.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetDspInitStatus_True_GetReturnsTrue)
{
   DSP_Init = false;

   Set_DSP_Init_Status(true);

   EXPECT_TRUE(Get_DSP_Init_Status());
}

/**
 *  @b set_dsp_init_status_false
 *  @n
 *      Set_DSP_Init_Status(false) must make Get_DSP_Init_Status() return false.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetDspInitStatus_False_GetReturnsFalse)
{
   DSP_Init = true;

   Set_DSP_Init_Status(false);

   EXPECT_FALSE(Get_DSP_Init_Status());
}

/*===========================================================================*
 * DDR-4176 — B.  Get/Set_Received_Doppler_Done  (both new, DDR-4176)
 *
 * was: dsp_setup.c read/wrote Received_Doppler_Done directly
 * now: encapsulated via Get/Set_Received_Doppler_Done()
 *===========================================================================*/

/**
 *  @b set_received_doppler_done_true
 *  @n
 *      Set_Received_Doppler_Done(true) → Get_Received_Doppler_Done() == true.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetReceivedDopplerDone_True_GetReturnsTrue)
{
   Received_Doppler_Done = false;

   Set_Received_Doppler_Done(true);

   EXPECT_TRUE(Get_Received_Doppler_Done());
}

/**
 *  @b set_received_doppler_done_false
 *  @n
 *      Set_Received_Doppler_Done(false) → Get_Received_Doppler_Done() == false.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetReceivedDopplerDone_False_GetReturnsFalse)
{
   Received_Doppler_Done = true;

   Set_Received_Doppler_Done(false);

   EXPECT_FALSE(Get_Received_Doppler_Done());
}

/*===========================================================================*
 * DDR-4176 — C.  Get/Set_M2D_Buffer_Full_Error_Counter  (both new, DDR-4176)
 *
 * was: dsp_setup.c incremented M2D_Buffer_Full_Error_Counter directly
 * now: Set_M2D_Buffer_Full_Error_Counter(Get_M2D_Buffer_Full_Error_Counter() + 1U)
 *===========================================================================*/

/**
 *  @b set_m2d_buffer_full_error_counter_round_trip
 *  @n
 *      Set_M2D_Buffer_Full_Error_Counter(n) → Get_M2D_Buffer_Full_Error_Counter() == n.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetM2dBufferFullErrCnt_RoundTrip)
{
   Set_M2D_Buffer_Full_Error_Counter(42U);

   EXPECT_EQ(Get_M2D_Buffer_Full_Error_Counter(), 42U);
}

/**
 *  @b set_m2d_buffer_full_error_counter_to_zero
 *  @n
 *      Set_M2D_Buffer_Full_Error_Counter(0) resets the counter.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetM2dBufferFullErrCnt_Zero_ReturnsZero)
{
   M2D_Buffer_Full_Error_Counter = 99U;

   Set_M2D_Buffer_Full_Error_Counter(0U);

   EXPECT_EQ(Get_M2D_Buffer_Full_Error_Counter(), 0U);
}

/*===========================================================================*
 * DDR-4176 — D.  Get/Set_DSP_Cfg_Init  (both new, DDR-4176)
 *
 * was: dsp_setup.c read/wrote DSP_Cfg_Init directly
 * now: Get_DSP_Cfg_Init() / Set_DSP_Cfg_Init(val)
 *===========================================================================*/

/**
 *  @b set_dsp_cfg_init_waiting
 *  @n
 *      Set_DSP_Cfg_Init(WAITING) → Get_DSP_Cfg_Init() == WAITING.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetDspCfgInit_Waiting_RoundTrip)
{
   Set_DSP_Cfg_Init(DSP_CONFIG_WAITING_FOR_RESPONSE);

   EXPECT_EQ((DSP_Config_Type_T)Get_DSP_Cfg_Init(), DSP_CONFIG_WAITING_FOR_RESPONSE);
}

/**
 *  @b set_dsp_cfg_init_error
 *  @n
 *      Set_DSP_Cfg_Init(DSP_CONFIG_ERROR) → Get_DSP_Cfg_Init() == DSP_CONFIG_ERROR.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetDspCfgInit_Error_RoundTrip)
{
   Set_DSP_Cfg_Init(DSP_CONFIG_ERROR);

   EXPECT_EQ((DSP_Config_Type_T)Get_DSP_Cfg_Init(), DSP_CONFIG_ERROR);
}

/**
 *  @b set_dsp_cfg_init_no_error
 *  @n
 *      Set_DSP_Cfg_Init(DSP_CONFIG_NO_ERROR) clears an error state.
 */
TEST_F(Ipc_Mss_UnitTestSuite, SetDspCfgInit_NoError_ClearsErrorState)
{
   DSP_Cfg_Init = DSP_CONFIG_ERROR;

   Set_DSP_Cfg_Init(DSP_CONFIG_NO_ERROR);

   EXPECT_EQ((DSP_Config_Type_T)Get_DSP_Cfg_Init(), DSP_CONFIG_NO_ERROR);
}

/*===========================================================================*
 * DDR-4176 — E.  Get_IPC_M2D_Crc_Err_Cnt  (new getter, DDR-4176)
 *===========================================================================*/

/**
 *  @b get_ipc_m2d_crc_err_cnt_reflects_counter
 *  @n
 *      Get_IPC_M2D_Crc_Err_Cnt() must reflect the value of IPC_M2D_Crc_Err_Cnt.
 */
TEST_F(Ipc_Mss_UnitTestSuite, GetIpcM2dCrcErrCnt_ReflectsCounter)
{
   IPC_M2D_Crc_Err_Cnt = 7U;

   EXPECT_EQ(Get_IPC_M2D_Crc_Err_Cnt(), 7U);
}

/*===========================================================================*
 * DDR-4176 — F.  Get_IPC_D2M_Crc_Err_Cnt  (new getter, DDR-4176)
 *===========================================================================*/

/**
 *  @b get_ipc_d2m_crc_err_cnt_reflects_counter
 *  @n
 *      Get_IPC_D2M_Crc_Err_Cnt() must reflect the value of IPC_D2M_Crc_Err_Cnt.
 */
TEST_F(Ipc_Mss_UnitTestSuite, GetIpcD2mCrcErrCnt_ReflectsCounter)
{
   IPC_D2M_Crc_Err_Cnt = 3U;

   EXPECT_EQ(Get_IPC_D2M_Crc_Err_Cnt(), 3U);
}

/*===========================================================================*
 * DDR-4176 — G.  Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx  (new getter, DDR-4176)
 *===========================================================================*/

/**
 *  @b get_ipc_dopp_rdd_comp_buf_read_idx
 *  @n
 *      Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx() returns the current ping-pong index.
 */
TEST_F(Ipc_Mss_UnitTestSuite, GetIpcDoppRddCompBufReadIdx_ReturnsPingPongIndex)
{
   IPC_Dopp_RDD_Comp_Buf_Read_idx = 1U;

   EXPECT_EQ(Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx(), 1U);
}

/*===========================================================================*
 * DDR-4176 — H.  Check_BBE32_To_R52_Header / Check_D2M_Crc_Header refactor
 *
 * Old logic (inverted):
 *   - Check_BBE32 default = CODED_TRUE (error)
 *   - If valid → CODED_FALSE (ok)
 *   - Check_D2M_Crc_Header: CODED_FALSE from inner ⇒ propagate ok
 *   - Error counter: Test_IPC_D2M_Crc_Err_Cnt++
 *
 * DDR-4176 new logic (clear):
 *   - Check_BBE32 default = CODED_FALSE
 *   - If valid → CODED_TRUE
 *   - Check_D2M_Crc_Header: CODED_TRUE from inner ⇒ return CODED_TRUE
 *   - Error counter: IPC_D2M_Crc_Err_Cnt++ (not Test_ counter)
 *   - Both branches return CODED_TRUE (TO-DO field until CRC stable)
 *===========================================================================*/

/**
 *  @b check_d2m_crc_header_valid_message_no_err_cnt_increment
 *  @n
 *      Valid D2M message (correct size, counter, CRC):
 *        - Check_D2M_Crc_Header returns CODED_TRUE
 *        - IPC_D2M_Crc_Err_Cnt unchanged
 */
TEST_F(Ipc_Mss_UnitTestSuite, CheckD2mCrcHeader_ValidMsg_ReturnsTrueNoErrCnt)
{
   D2M_Msg_T buf;
   memset(&buf, 0, sizeof(buf));

   /* Size correct; first call increments R52_D2M_Msg_Header_Cnt to 1 */
   buf.header.size    = sizeof(D2M_Msg_T);
   buf.header.counter = 1U;
   buf.header.crc     = 0xABCD1234U;

   /* CRC mock returns matching value → valid CRC */
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0xABCD1234U;
   IPC_D2M_Crc_Err_Cnt                    = 0U;

   uint8_t result = Check_D2M_Crc_Header(&buf);

   EXPECT_EQ(result, (uint8_t)CODED_TRUE);
   EXPECT_EQ(IPC_D2M_Crc_Err_Cnt, 0U); /* no error: counter stays at 0 */
}

/**
 *  @b check_d2m_crc_header_crc_mismatch_increments_ipc_d2m_err_cnt
 *  @n
 *      DDR-4176 changed the error counter from Test_IPC_D2M_Crc_Err_Cnt to
 *      IPC_D2M_Crc_Err_Cnt.  CRC mismatch must increment IPC_D2M_Crc_Err_Cnt.
 */
TEST_F(Ipc_Mss_UnitTestSuite, CheckD2mCrcHeader_CrcMismatch_IncrementsIpcD2mCrcErrCnt)
{
   D2M_Msg_T buf;
   memset(&buf, 0, sizeof(buf));

   /* Sync state: first call with valid CRC advances expected counter to 1. */
   buf.header.size                        = sizeof(D2M_Msg_T);
   buf.header.counter                     = 1U;
   buf.header.crc                         = 0x11111111U;
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0x11111111U;
   Check_D2M_Crc_Header(&buf);

   /* Second call: size ok, counter = 2, CRC MISMATCH */
   IPC_D2M_Crc_Err_Cnt                    = 0U;
   buf.header.counter                     = 2U;
   buf.header.crc                         = 0xDEADBEEFU;
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0x99999999U; /* mismatch */

   uint8_t result = Check_D2M_Crc_Header(&buf);

   /* DDR-4176: IPC_D2M_Crc_Err_Cnt++ replaces Test_IPC_D2M_Crc_Err_Cnt++ */
   EXPECT_EQ(IPC_D2M_Crc_Err_Cnt, 1U);
   /* DDR-5028: TO-DO workaround removed; CRC mismatch now returns CODED_FALSE */
   EXPECT_EQ(result, (uint8_t)CODED_FALSE);
}

/**
 *  @b check_d2m_crc_header_size_mismatch_increments_err_cnt
 *  @n
 *      Wrong header.size triggers counter resync in Check_BBE32_To_R52_Header
 *      (returns CODED_FALSE) → Check_D2M_Crc_Header increments IPC_D2M_Crc_Err_Cnt.
 */
TEST_F(Ipc_Mss_UnitTestSuite, CheckD2mCrcHeader_SizeMismatch_IncrementsErrCnt)
{
   D2M_Msg_T buf;
   memset(&buf, 0, sizeof(buf));

   buf.header.size     = sizeof(D2M_Msg_T) - 1U; /* WRONG */
   buf.header.counter  = 1U;
   IPC_D2M_Crc_Err_Cnt = 0U;

   uint8_t result = Check_D2M_Crc_Header(&buf);

   EXPECT_EQ(IPC_D2M_Crc_Err_Cnt, 1U);
   /* DDR-5028: TO-DO workaround removed; error path now returns CODED_FALSE */
   EXPECT_EQ(result, (uint8_t)CODED_FALSE);
}

/*===========================================================================*
 * DDR-4176 — I.  Update_IPC_M2D_Header:  CRC stored in local var
 *
 * Old: M2D_CRC_Calculated = Calc_M2D_Buf_Crc(...); header.crc = M2D_CRC_Calculated;
 * New: m2d_crc_calculated  = Calc_M2D_Buf_Crc(...); header.crc = m2d_crc_calculated;
 *
 * Observable: header.crc receives the value returned by Calc_M2D_Buf_Crc.
 *             The old global M2D_CRC_Calculated is gone.
 *===========================================================================*/

/**
 *  @b update_ipc_m2d_header_crc_from_local_var
 *  @n
 *      Update_IPC_M2D_Header must write the Calc_M2D_Buf_Crc() return value
 *      into header.crc via a local variable (DDR-4176 removed the global write).
 */
TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_CrcWrittenFromLocalVar)
{
   volatile M2D_Msg_T m2d_msg;
   memset((void *)&m2d_msg, 0, sizeof(m2d_msg));

   const uint32_t expected_crc      = 0xCAFEBABEU;
   Calc_M2D_Buf_Crc_fake.return_val = expected_crc;
   volatile_memset_fake.return_val  = nullptr;

   Update_IPC_M2D_Header(&m2d_msg);

   /* DDR-4176: result from Calc_M2D_Buf_Crc() stored locally and written to header */
   EXPECT_EQ(m2d_msg.header.crc, expected_crc);
   /* Verify Calc_M2D_Buf_Crc was called exactly once */
   EXPECT_EQ(Calc_M2D_Buf_Crc_fake.call_count, 1U);
}

/**
 *  @b update_ipc_m2d_header_size_and_counter
 *  @n
 *      Update_IPC_M2D_Header must set header.size = sizeof(M2D_Msg_T) and
 *      increment the message counter (unchanged by DDR-4176 — regression guard).
 */
TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_SizeAndCounterSetCorrectly)
{
   volatile M2D_Msg_T m2d_msg;
   memset((void *)&m2d_msg, 0, sizeof(m2d_msg));
   Calc_M2D_Buf_Crc_fake.return_val = 0U;
   volatile_memset_fake.return_val  = nullptr;

   Update_IPC_M2D_Header(&m2d_msg);

   EXPECT_EQ(m2d_msg.header.size, sizeof(M2D_Msg_T));
   EXPECT_EQ(m2d_msg.header.counter, 1U); /* first call: counter incremented to 1 */
}

/*===========================================================================*
 * DDR-4176 — J.  Update_R52_IPC_Notify: simplified CRC error condition
 *
 * Old guard: if (R52_TO_BBE32_CRC_ERROR == ef || ERRORFIELD_RANGE_PROCESS_ERROR == ef)
 * New guard: if (R52_TO_BBE32_CRC_ERROR == ef)
 *
 * ERRORFIELD_RANGE_PROCESS_ERROR alone must no longer increment
 * IPC_M2D_Crc_Err_Cnt.
 *===========================================================================*/

/**
 *  @b update_r52_notify_r52_to_bbe32_crc_error_increments_cnt
 *  @n
 *      R52_TO_BBE32_CRC_ERROR errorField must still increment IPC_M2D_Crc_Err_Cnt
 *      (unchanged from old behaviour — regression guard).
 */
TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_R52ToBbe32CrcErr_IncrementsM2dCrcErrCnt)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.errorField = R52_TO_BBE32_CRC_ERROR;
   notify.command    = NO_COMMAND;
   /* Return false once so the loop body executes, then true to exit the while */
   static uint8_t is_empty_seq_j1[]                   = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq_j1;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;
   IPC_M2D_Crc_Err_Cnt                                = 0U;

   Update_R52_IPC_Notify();

   EXPECT_EQ(IPC_M2D_Crc_Err_Cnt, 1U);
}

/**
 *  @b update_r52_notify_range_process_crc_error_does_not_increment_cnt
 *  @n
 *      DDR-4176 removed ERRORFIELD_RANGE_PROCESS_ERROR from the
 *      IPC_M2D_Crc_Err_Cnt guard.  That error field alone must NOT increment it.
 */
TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_RangeProcCrcErr_DoesNotIncrementM2dCnt)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.errorField = ERRORFIELD_RANGE_PROCESS_ERROR;
   notify.command    = NO_COMMAND;
   /* Return false once so the loop body executes, then true to exit the while */
   static uint8_t is_empty_seq_j2[]                   = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq_j2;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;
   IPC_M2D_Crc_Err_Cnt                                = 0U;

   Update_R52_IPC_Notify();

   /* DDR-4176: ERRORFIELD_RANGE_PROCESS_ERROR no longer triggers
    * IPC_M2D_Crc_Err_Cnt increment */
   EXPECT_EQ(IPC_M2D_Crc_Err_Cnt, 0U);
}
/*===========================================================================*
 * R52_BBE_Trigger tests
 * Note: R52_BBE_Trigger(true path) writes to DSP->SP2DSP_INT hardware register
 * which is not accessible in host unit tests. Only the false path is testable.
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, R52BbeTrigger_DspInitFalse_ReturnsFalse)
{
   DSP_Init = false;

   bool result = R52_BBE_Trigger();

   EXPECT_FALSE(result);
}

/*===========================================================================*
 * Buffer getter/init tests
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcM2dOnetimeMsgBuffer_ReturnsCorrectAddress)
{
   volatile M2D_One_Time_Msg_T *result = Get_IPC_M2D_Onetime_Msg_Buffer();

   EXPECT_EQ(result, (volatile M2D_One_Time_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcM2dMsgBuffer_ReturnsCorrectAddress)
{
   volatile M2D_Msg_T *result0 = Get_IPC_M2D_Msg_Buffer(0U);
   volatile M2D_Msg_T *result1 = Get_IPC_M2D_Msg_Buffer(1U);

   EXPECT_EQ(result0, (volatile M2D_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_Buffer[0]);
   EXPECT_EQ(result1, (volatile M2D_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_Buffer[1]);
}

TEST_F(Ipc_Mss_UnitTestSuite, ResetIpcM2dBuffer_SetsSizeAndZerosCrc)
{
   volatile M2D_Msg_T m2d;
   memset((void *)&m2d, 0xFF, sizeof(m2d));
   volatile_memset_fake.return_val = nullptr;

   Reset_IPC_M2D_Buffer(&m2d);

   EXPECT_EQ(m2d.header.size, sizeof(M2D_Msg_T));
   EXPECT_EQ(m2d.header.crc, 0U);
   EXPECT_EQ(volatile_memset_fake.call_count, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, IpcM2dBufferInit_InitializesAllPingPongBuffers)
{
   volatile_memset_fake.return_val = nullptr;

   IPC_M2D_Buffer_Init();

   /* Should call Reset_IPC_M2D_Buffer for each ping-pong buffer */
   EXPECT_EQ(volatile_memset_fake.call_count, IPC_PING_PONG_COUNT);
   for (uint8_t i = 0; i < IPC_PING_PONG_COUNT; i++)
   {
      EXPECT_EQ(IPC_M2D_Buffers.IPC_M2D_Buffer[i].header.size, sizeof(M2D_Msg_T));
      EXPECT_EQ(IPC_M2D_Buffers.IPC_M2D_Buffer[i].header.crc, 0U);
   }
}

TEST_F(Ipc_Mss_UnitTestSuite, IpcM2dOneTimeBufferInit_ZerosBuffer)
{
   memset((void *)&IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data, 0xFF, sizeof(M2D_One_Time_Msg_T));

   IPC_M2D_One_Time_Buffer_Init();

   /* Verify buffer is zeroed */
   uint8_t *p = (uint8_t *)&IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;
   for (size_t i = 0; i < sizeof(M2D_One_Time_Msg_T); i++)
   {
      EXPECT_EQ(p[i], 0U) << "Byte " << i << " not zeroed";
   }
}

/*===========================================================================*
 * Simple getter tests for remaining uncovered getters
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcD2mSpPostProcBuffer_ReturnsCurrentPointer)
{
   D2M_Msg_T dummy;
   IPC_Sp_Post_Proc_Buf_Read_Addr = &dummy;

   EXPECT_EQ(Get_IPC_D2M_Sp_Post_Proc_Buffer(), &dummy);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcD2mSpPostProcBuffer_ReturnsNullInitially)
{
   IPC_Sp_Post_Proc_Buf_Read_Addr = NULL;

   EXPECT_EQ(Get_IPC_D2M_Sp_Post_Proc_Buffer(), (D2M_Msg_T *)NULL);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetMssIpcM2dMsgBuffer_ReturnsBufferAtCurrentIndex)
{
   R52_M2D_Buffer_Index       = 0U;
   volatile M2D_Msg_T *result = Get_MSS_IPC_M2D_Msg_Buffer();
   EXPECT_EQ(result, (volatile M2D_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_Buffer[0]);

   R52_M2D_Buffer_Index = 1U;
   result               = Get_MSS_IPC_M2D_Msg_Buffer();
   EXPECT_EQ(result, (volatile M2D_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_Buffer[1]);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcD2mDoppRddCompBufBuffer_ReturnsCurrentPointer)
{
   D2M_Msg_T dummy;
   IPC_Dopp_RDD_Comp_Buf_Read_Addr = &dummy;

   EXPECT_EQ(Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer(), &dummy);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetSetIsDopplerCompRddStreamReady_RoundTrip)
{
   Set_Is_Doppler_Comp_RDD_Stream_Ready(true);
   EXPECT_TRUE(Get_Is_Doppler_Comp_RDD_Stream_Ready());

   Set_Is_Doppler_Comp_RDD_Stream_Ready(false);
   EXPECT_FALSE(Get_Is_Doppler_Comp_RDD_Stream_Ready());
}

TEST_F(Ipc_Mss_UnitTestSuite, GetD2mPingPongBufAddr_ReflectsStoredAddresses)
{
   Ping_Buf_Addr = 0x10000000U;
   Pong_Buf_Addr = 0x20000000U;

   EXPECT_EQ(Get_D2M_Ping_Buf_Addr(), 0x10000000U);
   EXPECT_EQ(Get_D2M_Pong_Buf_Addr(), 0x20000000U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetDspWriteIpcIndex_ReflectsValue)
{
   DSP_Write_IPC_Index = 1U;

   EXPECT_EQ(Get_DSP_Write_IPC_Index(), 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetR52CurrentPingPongIndex_ReflectsValue)
{
   R52_M2D_Buffer_Index = 1U;

   EXPECT_EQ(Get_R52_Current_PingPong_Index(), 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetR52D2mMsgHeaderCnt_ReflectsValue)
{
   R52_D2M_Msg_Header_Cnt = 42U;

   EXPECT_EQ(Get_R52_D2M_Msg_Header_Cnt(), 42U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetDspNoCommandCnt_ReflectsValue)
{
   DSP_No_Command_Cnt = 5U;

   EXPECT_EQ(Get_DSP_No_Command_Cnt(), 5U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcSpPostBufReadAddrRaw_ReflectsValue)
{
   D2M_Msg_T dummy;
   IPC_Sp_Post_Buf_Read_Addr_Raw = &dummy;

   EXPECT_EQ(Get_IPC_Sp_Post_Buf_Read_Addr_Raw(), &dummy);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetIpcSpPostBufReadIdxRaw_ReflectsValue)
{
   IPC_Sp_Post_Buf_Read_Idx_Raw = 1U;

   EXPECT_EQ(Get_IPC_Sp_Post_Buf_Read_Idx_Raw(), 1U);
}

/*===========================================================================*
 * Message counter getter tests
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, GetDspRangeConfigCounts_ReflectsValues)
{
   DSP_Range_Config_Counts.rx_count    = 10U;
   DSP_Range_Config_Counts.error_count = 2U;

   IPC_Message_Counter_T result = Get_DSP_Range_Config_Counts();

   EXPECT_EQ(result.rx_count, 10U);
   EXPECT_EQ(result.error_count, 2U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetDspRangeProcessCompleteCounts_ReflectsValues)
{
   DSP_Range_Process_Complete_Counts.rx_count    = 20U;
   DSP_Range_Process_Complete_Counts.error_count = 3U;

   IPC_Message_Counter_T result = Get_DSP_Range_Process_Complete_Counts();

   EXPECT_EQ(result.rx_count, 20U);
   EXPECT_EQ(result.error_count, 3U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetDspDopplerProcessCompleteCounts_ReflectsValues)
{
   DSP_Doppler_Process_Complete_Counts.rx_count    = 30U;
   DSP_Doppler_Process_Complete_Counts.error_count = 4U;

   IPC_Message_Counter_T result = Get_DSP_Doppler_Process_Complete_Counts();

   EXPECT_EQ(result.rx_count, 30U);
   EXPECT_EQ(result.error_count, 4U);
}

TEST_F(Ipc_Mss_UnitTestSuite, GetDspSpPostCompleteCounts_ReflectsValues)
{
   DSP_Sp_Post_Complete_Counts.rx_count    = 40U;
   DSP_Sp_Post_Complete_Counts.error_count = 5U;

   IPC_Message_Counter_T result = Get_DSP_Sp_Post_Complete_Counts();

   EXPECT_EQ(result.rx_count, 40U);
   EXPECT_EQ(result.error_count, 5U);
}

/*===========================================================================*
 * Check_BBE32_To_R52_Header — counter mismatch branch
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, CheckBbe32ToR52Header_CounterMismatch_ResyncsAndReturnsFalse)
{
   D2M_Msg_T buf;
   memset(&buf, 0, sizeof(buf));

   /* Size ok, but counter is 5 while expected is 1 */
   buf.header.size    = sizeof(D2M_Msg_T);
   buf.header.counter = 5U;

   uint8_t result = Check_D2M_Crc_Header(&buf);

   /* Counter resync happens inside Check_BBE32_To_R52_Header, returns CODED_FALSE */
   EXPECT_EQ(result, (uint8_t)CODED_FALSE);
   EXPECT_EQ(IPC_D2M_Crc_Err_Cnt, 1U);
   /* R52_D2M_Msg_Header_Cnt resynced to received counter */
   EXPECT_EQ(R52_D2M_Msg_Header_Cnt, 5U);
}

/*===========================================================================*
 * Update_R52_IPC_Notify — switch case branches
 *===========================================================================*/

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspRangeConfigComplete_NoError_SetsDspCfgNoError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = DSP_RANGE_CONFIGURATION_COMPLETE;
   notify.errorField = ERRORFIELD_NO_ERROR;
   notify.pfm_index  = 7U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ((DSP_Config_Type_T)DSP_Cfg_Init, DSP_CONFIG_NO_ERROR);
   EXPECT_EQ(DSP_Range_Config_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Range_Config_Counts.error_count, 0U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspRangeConfigComplete_ConfigError_SetsDspCfgError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = DSP_RANGE_CONFIGURATION_COMPLETE;
   notify.errorField = ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR;
   notify.pfm_index  = 1U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ((DSP_Config_Type_T)DSP_Cfg_Init, DSP_CONFIG_ERROR);
   EXPECT_EQ(DSP_Range_Config_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Range_Config_Counts.error_count, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspRangeProcessingComplete_NoError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = DSP_RANGE_PROCESSING_COMPLETE;
   notify.errorField = ERRORFIELD_NO_ERROR;
   notify.pfm_index  = 2U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ(DSP_Range_Process_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Range_Process_Complete_Counts.error_count, 0U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspRangeProcessingComplete_WithError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = DSP_RANGE_PROCESSING_COMPLETE;
   notify.errorField = ERRORFIELD_RANGE_PROCESS_ERROR;
   notify.pfm_index  = 3U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ(DSP_Range_Process_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Range_Process_Complete_Counts.error_count, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspDopplerComplete_NoError_PingBuffer)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   D2M_Msg_T dummy_buf;
   notify.command       = DSP_DOPPLER_PROCESSING_COMPLETE;
   notify.errorField    = ERRORFIELD_NO_ERROR;
   notify.curIpcAddr    = (uint32_t)(uintptr_t)&dummy_buf;
   notify.pingPongIndex = 0U;
   notify.pfm_index     = 4U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_TRUE(Received_Doppler_Done);
   EXPECT_TRUE(Received_Doppler_Stream);
   EXPECT_EQ(DSP_Doppler_Process_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Doppler_Process_Complete_Counts.error_count, 0U);
   EXPECT_EQ(IPC_Dopp_RDD_Comp_Buf_Read_idx, 0U);
   EXPECT_EQ(Ping_Buf_Addr, (uint32_t)(uintptr_t)&dummy_buf);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspDopplerComplete_WithError_PongBuffer)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   D2M_Msg_T dummy_buf;
   notify.command       = DSP_DOPPLER_PROCESSING_COMPLETE;
   notify.errorField    = ERRORFIELD_DOPPLER_PROCESS_ERROR;
   notify.curIpcAddr    = (uint32_t)(uintptr_t)&dummy_buf;
   notify.pingPongIndex = 1U;
   notify.pfm_index     = 5U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_TRUE(Received_Doppler_Done);
   EXPECT_EQ(DSP_Doppler_Process_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Doppler_Process_Complete_Counts.error_count, 1U);
   EXPECT_EQ(IPC_Dopp_RDD_Comp_Buf_Read_idx, 1U);
   EXPECT_EQ(Pong_Buf_Addr, (uint32_t)(uintptr_t)&dummy_buf);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspSpPostComplete_TimingBranch_CoversAvailabilityAndFailureCounters)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   D2M_Msg_T dummy_buf;
   notify.command       = DSP_SP_POST_PROCESSING_COMPLETE;
   notify.errorField    = ERRORFIELD_NO_ERROR;
   notify.curIpcAddr    = (uint32_t)(uintptr_t)&dummy_buf;
   notify.lookIndex     = 21U;
   notify.pingPongIndex = 1U;
   notify.pfm_index     = 9U;

   Get_IPC_Notify_Buffer_fake.return_val = (Ipc_Notify_Structure_T *)&notify;

   static uint8_t is_empty_seq[]                      = {false, true, false, true, false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 6;

   Get_Platform_ustime_fake.custom_fake = [](uint64_t *time_us)
   {
      static uint64_t seq[] = {1000ULL, 2000ULL, 3000ULL};
      static size_t idx     = 0U;
      *time_us              = seq[idx % (sizeof(seq) / sizeof(seq[0]))];
      idx++;
   };

   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed_us, uint64_t start_time)
   {
      static uint32_t seq[] = {50000U, 60000U};
      static size_t idx     = 0U;
      (void)start_time;
      *elapsed_us = seq[idx % (sizeof(seq) / sizeof(seq[0]))];
      idx++;
   };

   IPC_D2M_Start_Time_Us     = 0U;
   IPC_D2M_Delta_Time_Us     = 0U;
   IPC_D2M_Max_Delta_Time_Us = 0U;
   IPC_D2M_Min_Delta_Time_Us = 1000000U;
   FailCnt_IPC_ISR           = 0U;

   Update_R52_IPC_Notify();
   EXPECT_EQ(IPC_D2M_Max_Delta_Time_Us, 0U);
   EXPECT_EQ(IPC_D2M_Min_Delta_Time_Us, 1000000U);
   EXPECT_EQ(FailCnt_IPC_ISR, 0U);

   Update_R52_IPC_Notify();
   EXPECT_EQ(IPC_D2M_Max_Delta_Time_Us, 50000U);
   EXPECT_EQ(IPC_D2M_Min_Delta_Time_Us, 50000U);
   EXPECT_EQ(FailCnt_IPC_ISR, 0U);

   Update_R52_IPC_Notify();
   EXPECT_EQ(IPC_D2M_Max_Delta_Time_Us, 60000U);
   EXPECT_EQ(IPC_D2M_Min_Delta_Time_Us, 50000U);
   EXPECT_EQ(FailCnt_IPC_ISR, 1U);
   EXPECT_EQ(g_last_frame_time_look_index, 21U);
   EXPECT_EQ(g_last_frame_time_ping_pong_index, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspSpPostComplete_NoError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   D2M_Msg_T dummy_buf;
   notify.command       = DSP_SP_POST_PROCESSING_COMPLETE;
   notify.errorField    = ERRORFIELD_NO_ERROR;
   notify.curIpcAddr    = (uint32_t)(uintptr_t)&dummy_buf;
   notify.lookIndex     = 23U;
   notify.pingPongIndex = 0U;
   notify.pfm_index     = 6U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ(DSP_Sp_Post_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Sp_Post_Complete_Counts.error_count, 0U);
   EXPECT_EQ(g_last_frame_time_look_index, 23U);
   EXPECT_EQ(g_last_frame_time_ping_pong_index, 0U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DspSpPostComplete_WithError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = DSP_SP_POST_PROCESSING_COMPLETE;
   notify.errorField = ERRORFIELD_POST_SIG_PROC_ERROR;
   notify.pfm_index  = 7U;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;

   Update_R52_IPC_Notify();

   EXPECT_EQ(DSP_Sp_Post_Complete_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Sp_Post_Complete_Counts.error_count, 1U);
}

/* CORE_INITIALIZED buffer-not-full path calls R52_BBE_Trigger which writes
 * to DSP hardware registers — not testable on host. Only the buffer-full
 * error path is tested. */

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_CoreInitialized_BufferFull_IncrementsError)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command = CORE_INITIALIZED;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;
   Is_IPC_Notify_Buffer_Full_fake.return_val          = true;
   M2D_Buffer_Full_Error_Counter                      = 0U;

   Update_R52_IPC_Notify();

   EXPECT_FALSE(DSP_Init);
   EXPECT_EQ(M2D_Buffer_Full_Error_Counter, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_DefaultCommand_IncrementsDspNoCommandCnt)
{
   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));

   notify.command    = 0xFFU; /* Unknown command */
   notify.errorField = ERRORFIELD_NO_ERROR;

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Get_IPC_Notify_Buffer_fake.return_val              = (Ipc_Notify_Structure_T *)&notify;
   DSP_No_Command_Cnt                                 = 0U;

   Update_R52_IPC_Notify();

   EXPECT_EQ(DSP_No_Command_Cnt, 1U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_EmptyBuffer_DoesNothing)
{
   Is_IPC_Notify_Buffer_Empty_fake.return_val = true;

   Update_R52_IPC_Notify();

   EXPECT_EQ(Get_IPC_Notify_Buffer_fake.call_count, 0U);
   EXPECT_EQ(Increment_IPC_Notify_ReadIndx_fake.call_count, 0U);
}

/*===========================================================================*
 * R52_BBE_Trigger with DSP_Init = true
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, R52BbeTrigger_DspInitTrue_ReturnsTrue)
{
   ASSERT_NE(g_dsp_hw_map, nullptr) << "DSP hw map allocation failed";
   DSP_Init = true;

   bool result = R52_BBE_Trigger();

   EXPECT_TRUE(result);
}

/*===========================================================================*
 * CORE_INITIALIZED — buffer not full path (triggers R52_BBE_Trigger)
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_CoreInitialized_BufferNotFull_SetsDspInit)
{
   ASSERT_NE(g_dsp_hw_map, nullptr) << "DSP hw map allocation failed";

   static volatile Ipc_Notify_Structure_T notify;
   memset((void *)&notify, 0, sizeof(notify));
   notify.command    = CORE_INITIALIZED;
   notify.curIpcAddr = 0x12345678U;

   static volatile Ipc_Notify_Structure_T r52_write_buf;
   memset((void *)&r52_write_buf, 0, sizeof(r52_write_buf));

   static uint8_t is_empty_seq[]                      = {false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 2;
   Is_IPC_Notify_Buffer_Full_fake.return_val          = false;

   /* First call returns read notify, second call returns write buffer */
   static volatile Ipc_Notify_Structure_T *notify_seq[] = {&notify, &r52_write_buf};
   Get_IPC_Notify_Buffer_fake.return_val_seq            = (volatile Ipc_Notify_Structure_T **)notify_seq;
   Get_IPC_Notify_Buffer_fake.return_val_seq_len        = 2;

   Update_R52_IPC_Notify();

   EXPECT_TRUE(DSP_Init);
   EXPECT_EQ(Increment_IPC_Notify_WriteIndx_fake.call_count, 1U);
   EXPECT_EQ(r52_write_buf.command, (uint8_t)CORE_INITIALIZED);
}

/*===========================================================================*
 * Update_IPC_M2D_Header — XCP fault injection path
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_XcpFault_R52ToBbeFault_SetsSizeZero)
{
   static M2D_Msg_T m2d;
   memset(&m2d, 0, sizeof(m2d));
   m2d.payload.xcp_fault_type = R52_To_BBE_Fault;

   Calc_M2D_Buf_Crc_fake.return_val = 0xDEADBEEFU;

   Update_IPC_M2D_Header((volatile M2D_Msg_T *)&m2d);

   EXPECT_EQ(m2d.header.size, 0U);
   EXPECT_EQ(m2d.header.crc, 0xDEADBEEFU);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_XcpFault_NotR52ToBbe_KeepsSize)
{
   static M2D_Msg_T m2d;
   memset(&m2d, 0, sizeof(m2d));
   m2d.payload.xcp_fault_type = 0U; /* Not R52_To_BBE_Fault */

   Calc_M2D_Buf_Crc_fake.return_val = 0xAABBCCDDU;

   Update_IPC_M2D_Header((volatile M2D_Msg_T *)&m2d);

   EXPECT_EQ(m2d.header.size, sizeof(M2D_Msg_T));
   EXPECT_EQ(m2d.header.crc, 0xAABBCCDDU);
}

/*===========================================================================*
 * Update_IPC_M2D_Header — CRC profiling min/max tracking
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_CrcProfiling_UpdatesMax)
{
   static M2D_Msg_T m2d;
   memset(&m2d, 0, sizeof(m2d));
   Calc_M2D_Buf_Crc_fake.return_val = 0U;

   /* Simulate elapsed time returning a large value */
   M2D_CRC_Compute_Time_Max_us = 0U;
   M2D_CRC_Compute_Time_Min_us = UINT32_MAX;

   /* Get_Platform_Elapsed_ustime writes to its first arg — use custom fake */
   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed, uint64_t start) { *elapsed = 500U; };

   Update_IPC_M2D_Header((volatile M2D_Msg_T *)&m2d);

   EXPECT_EQ(M2D_CRC_Compute_Time_Max_us, 500U);
   EXPECT_EQ(M2D_CRC_Compute_Time_Min_us, 500U);
}

TEST_F(Ipc_Mss_UnitTestSuite, UpdateIpcM2dHeader_CrcProfiling_OnlyUpdatesMinWhenSmaller)
{
   static M2D_Msg_T m2d;
   memset(&m2d, 0, sizeof(m2d));
   Calc_M2D_Buf_Crc_fake.return_val = 0U;

   M2D_CRC_Compute_Time_Max_us = 1000U;
   M2D_CRC_Compute_Time_Min_us = 100U;

   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed, uint64_t start)
   {
      *elapsed = 200U; /* Not smaller than 100 min, not larger than 1000 max */
   };

   Update_IPC_M2D_Header((volatile M2D_Msg_T *)&m2d);

   EXPECT_EQ(M2D_CRC_Compute_Time_Max_us, 1000U); /* unchanged */
   EXPECT_EQ(M2D_CRC_Compute_Time_Min_us, 100U);  /* unchanged */
}

/*===========================================================================*
 * Check_BBE32_To_R52_Header — CRC profiling min/max tracking
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, CheckBbe32ToR52Header_CrcMatch_WithProfiling_UpdatesMinMax)
{
   static D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));
   d2m.header.size    = sizeof(D2M_Msg_T);
   d2m.header.counter = 1U; /* R52_D2M_Msg_Header_Cnt starts at 0, incremented to 1 */
   d2m.header.crc     = 0x12345678U;

   R52_D2M_Msg_Header_Cnt                 = 0U;
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0x12345678U;

   D2M_CRC_Compute_Time_Max_us = 0U;
   D2M_CRC_Compute_Time_Min_us = UINT32_MAX;

   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed, uint64_t start) { *elapsed = 300U; };

   uint8_t result = Check_D2M_Crc_Header(&d2m);

   EXPECT_EQ(result, CODED_TRUE);
   EXPECT_EQ(D2M_CRC_Compute_Time_Max_us, 300U);
   EXPECT_EQ(D2M_CRC_Compute_Time_Min_us, 300U);
}

TEST_F(Ipc_Mss_UnitTestSuite, CheckBbe32ToR52Header_CrcMatch_ProfilingNoMinUpdate)
{
   static D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));
   d2m.header.size    = sizeof(D2M_Msg_T);
   d2m.header.counter = 1U;
   d2m.header.crc     = 0xABCDU;

   R52_D2M_Msg_Header_Cnt                 = 0U;
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0xABCDU;

   D2M_CRC_Compute_Time_Max_us = 1000U;
   D2M_CRC_Compute_Time_Min_us = 50U;

   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed, uint64_t start)
   {
      *elapsed = 200U; /* Between min(50) and max(1000), no update */
   };

   uint8_t result = Check_D2M_Crc_Header(&d2m);

   EXPECT_EQ(result, CODED_TRUE);
   EXPECT_EQ(D2M_CRC_Compute_Time_Max_us, 1000U);
   EXPECT_EQ(D2M_CRC_Compute_Time_Min_us, 50U);
}

TEST_F(Ipc_Mss_UnitTestSuite, CheckBbe32ToR52Header_CrcMismatch_WithProfiling)
{
   static D2M_Msg_T d2m;
   memset(&d2m, 0, sizeof(d2m));
   d2m.header.size    = sizeof(D2M_Msg_T);
   d2m.header.counter = 1U;
   d2m.header.crc     = 0x1111U;

   R52_D2M_Msg_Header_Cnt                 = 0U;
   Calc_D2M_Buf_Crc_Chn_X_fake.return_val = 0x2222U; /* Mismatch */

   Get_Platform_Elapsed_ustime_fake.custom_fake = [](uint32_t *elapsed, uint64_t start) { *elapsed = 100U; };

   uint8_t result = Check_D2M_Crc_Header(&d2m);

   EXPECT_EQ(result, CODED_FALSE); /* CRC failed */
   EXPECT_EQ(IPC_D2M_Crc_Err_Cnt, 1U);
}

/*===========================================================================*
 * Set_XCP_Fault_Inj tests
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, SetXcpFaultInj_R52ToBbeFault_SetsPayload)
{
   Ipc_Xcp_Fault_Injn_Var = R52_To_BBE_Fault;
   R52_M2D_Buffer_Index   = 0U;

   Set_XCP_Fault_Inj();

   volatile M2D_Msg_T *m2d = Get_MSS_IPC_M2D_Msg_Buffer();
   EXPECT_EQ(m2d->payload.xcp_fault_type, R52_To_BBE_Fault);
}

TEST_F(Ipc_Mss_UnitTestSuite, SetXcpFaultInj_BbeToR52Fault_SetsPayload)
{
   Ipc_Xcp_Fault_Injn_Var = BBE_To_R52_Fault;
   R52_M2D_Buffer_Index   = 0U;

   Set_XCP_Fault_Inj();

   volatile M2D_Msg_T *m2d = Get_MSS_IPC_M2D_Msg_Buffer();
   EXPECT_EQ(m2d->payload.xcp_fault_type, BBE_To_R52_Fault);
}

TEST_F(Ipc_Mss_UnitTestSuite, SetXcpFaultInj_NoFault_SetsPayload)
{
   Ipc_Xcp_Fault_Injn_Var = NO_Fault;
   R52_M2D_Buffer_Index   = 0U;

   /* Pre-set to something else to verify it changes */
   volatile M2D_Msg_T *m2d     = Get_MSS_IPC_M2D_Msg_Buffer();
   m2d->payload.xcp_fault_type = R52_To_BBE_Fault;

   Set_XCP_Fault_Inj();

   EXPECT_EQ(m2d->payload.xcp_fault_type, NO_Fault);
}

TEST_F(Ipc_Mss_UnitTestSuite, SetXcpFaultInj_UnknownValue_DoesNothing)
{
   Ipc_Xcp_Fault_Injn_Var = 0xFFU; /* Unknown */
   R52_M2D_Buffer_Index   = 0U;

   volatile M2D_Msg_T *m2d     = Get_MSS_IPC_M2D_Msg_Buffer();
   m2d->payload.xcp_fault_type = NO_Fault;

   Set_XCP_Fault_Inj();

   EXPECT_EQ(m2d->payload.xcp_fault_type, NO_Fault); /* Unchanged */
}

/*===========================================================================*
 * Multiple loop iterations in Update_R52_IPC_Notify
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, UpdateR52IpcNotify_MultipleMessages_ProcessesAll)
{
   static volatile Ipc_Notify_Structure_T notify1;
   static volatile Ipc_Notify_Structure_T notify2;
   memset((void *)&notify1, 0, sizeof(notify1));
   memset((void *)&notify2, 0, sizeof(notify2));

   notify1.command    = DSP_RANGE_CONFIGURATION_COMPLETE;
   notify1.errorField = ERRORFIELD_NO_ERROR;
   notify2.command    = DSP_RANGE_PROCESSING_COMPLETE;
   notify2.errorField = ERRORFIELD_NO_ERROR;

   /* Buffer returns not-empty twice, then empty */
   static uint8_t is_empty_seq[]                      = {false, false, true};
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq     = is_empty_seq;
   Is_IPC_Notify_Buffer_Empty_fake.return_val_seq_len = 3;

   /* Return different notifications each call */
   static volatile Ipc_Notify_Structure_T *notify_seq[] = {(volatile Ipc_Notify_Structure_T *)&notify1,
                                                           (volatile Ipc_Notify_Structure_T *)&notify2};
   Get_IPC_Notify_Buffer_fake.return_val_seq            = notify_seq;
   Get_IPC_Notify_Buffer_fake.return_val_seq_len        = 2;

   Update_R52_IPC_Notify();

   EXPECT_EQ(Increment_IPC_Notify_ReadIndx_fake.call_count, 2U);
   EXPECT_EQ(DSP_Range_Config_Counts.rx_count, 1U);
   EXPECT_EQ(DSP_Range_Process_Complete_Counts.rx_count, 1U);
}

/*===========================================================================*
 * Set_IPC_XCP_Fault_Injn_Var test
 *===========================================================================*/
TEST_F(Ipc_Mss_UnitTestSuite, SetIpcXcpFaultInjnVar_SetsValue)
{
   Set_IPC_XCP_Fault_Injn_Var(R52_To_BBE_Fault);

   EXPECT_EQ(Ipc_Xcp_Fault_Injn_Var, R52_To_BBE_Fault);
}
