/*===========================================================================*/
/**
 * @file hil_interface_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the Interface of Angle Finding Module.
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#ifdef _WIN32
   /* WIN32_LEAN_AND_MEAN excludes COM/OLE headers that conflict with AUTOSAR
    * typedefs (e.g. ApplicationType) already pulled in by the test's C headers. */
   #ifndef WIN32_LEAN_AND_MEAN
      #define WIN32_LEAN_AND_MEAN
   #endif
   #include <windows.h>
#endif
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>
/*===========================================================================*
 *
 * Macros needed for Angle Finding Module
 *===========================================================================*/

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "hil_interface_fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
extern "C"
{
#include "SWC_PLT_Appl_PlatformTime_fake.h"
#include "hil_communication_handler_fake.h"
#include "hil_interface.c"
#include "hil_interface_fff.h"
#include "ipc_data.h"
#include "sh_comm.h"
#include "sh_module_cfg.h"
}

DEFINE_FFF_GLOBALS;

#define VERIFY_POINTER(ptr) ASSERT_NE(ptr, NULL) << #ptr " is null pointer";

static SH_Output_T g_sh_output_data = {0};

static void SetShOutput(Stream_Cfg_T *stream_table_info_addr, Stream_Info_T *stream_list_info_addr)
{
   g_sh_output_data.sh_stream_table_cfg_ptr = stream_table_info_addr;
   g_sh_output_data.sh_stream_info_ptr      = stream_list_info_addr;
   Get_SH_Output_Data_Ptr_fake.return_val   = &g_sh_output_data;
}
/*===========================================================================*
 * Valid Configuration For Tests
 *
 * On Windows x64 the PE+ image base is 0x140000000, so global variables live
 * above 4 GB.  The Get_D2M_*_Buf_Addr fakes return uint32_t; the source casts
 * that value back to D2M_Msg_T *.  With a truncated address the pointer is
 * invalid, and the EUR-2912 code that writes through IPC_D2M_Buff_Ptr causes
 * an access violation.  SetUpTestSuite() allocates the two D2M buffers below
 * the 4 GB boundary via VirtualAlloc so the uint32_t round-trip is lossless.
 *===========================================================================*/
D2M_Msg_T *d2m_msg      = nullptr;
uint32_t ping_buff_addr = 0U;
uint32_t pong_buff_addr = 0U;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class HIL_Interface_Unit_Test_Suite : public testing::Test
{
 public:
   /**
    *  @b Description
    *  @none
    *      Allocate the shared D2M ping/pong buffers once for the whole suite.
    *      On Windows x64 VirtualAlloc with a low-address hint keeps the
    *      allocation below 4 GB so (uint32_t)(uintptr_t)ptr is lossless.
    */
   static void SetUpTestSuite()
   {
#ifdef _WIN32
      for (uintptr_t hint = 0x10000000U; hint < 0xC0000000U; hint += 0x01000000U)
      {
         d2m_msg = (D2M_Msg_T *)VirtualAlloc((LPVOID)hint, sizeof(D2M_Msg_T) * 2U, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
         if (d2m_msg != nullptr)
         {
            break;
         }
      }
#else
      static D2M_Msg_T s_buf[2];
      std::memset(s_buf, 0, sizeof(s_buf));
      d2m_msg = s_buf;
#endif
      ping_buff_addr = (uint32_t)((uintptr_t)d2m_msg);
      pong_buff_addr = (uint32_t)((uintptr_t)(d2m_msg + 1));
   }

   /**
    *  @b Description
    *  @none
    *      Release the D2M buffers after all tests in the suite have run.
    */
   static void TearDownTestSuite()
   {
#ifdef _WIN32
      if (d2m_msg != nullptr)
      {
         (void)VirtualFree(d2m_msg, 0U, MEM_RELEASE);
         d2m_msg = nullptr;
      }
#endif
   }

   /**
    *  @b Description
    *  @none
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_HIL_LIST(RESET_FAKE);
      if (d2m_msg != nullptr)
      {
         std::memset(d2m_msg, 0, sizeof(D2M_Msg_T) * 2U);
      }
   }

   /**
    *  @b Description
    *  @n
    *      Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_Interface__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC1)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 1U;
   Number_Of_Streams_Initialized       = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized, 0u); /*checked as per the streams initialized*/
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC2)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 0U;
   Number_Of_Streams_Initialized       = 0;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   /*hil_ipc_index  = 0U;*/
   hil_input_data.num_hil_enabled_streams = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized, 0U); /*checked as per the streams initialized*/
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC3)
{
   HIL_Input_T hil_input_data                   = {0};
   HIL_Output_T hil_output_data                 = {0};
   M2D_Msg_T mss_to_dss_l3                      = {0};
   Stream_Cfg_T stream_table_info_addr          = {0};
   Stream_Info_T stream_list_info_addr          = {0};
   uint32_t Ping_Pong_Index_dummy               = 1U;
   Number_Of_Streams_Initialized                = 0;
   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = 0x0;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_EQ(IPC_D2M_Buff_Ptr, nullptr);
   ASSERT_EQ(Number_Of_Streams_Initialized, 0U);
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC4)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy =
      0U; /*R52 PingPong(0) != DSP_Write(1); guard uses HIL_Ipc_Index < NUM_IPC_INDEX so streams are still initialized*/
   Number_Of_Streams_Initialized                = 0;
   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized, 0U); /*streams initialized: HIL_Ipc_Index(1) < NUM_IPC_INDEX(2) is always true*/
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC5)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 1U;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   VERIFY_POINTER(hil_input_data.hil_ipc_index);
   VERIFY_POINTER(hil_input_data.num_hil_enabled_streams);
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC6)
{
   HIL_Input_T hil_input_data                   = {0};
   HIL_Output_T hil_output_data                 = {0};
   M2D_Msg_T mss_to_dss_l3                      = {0};
   Stream_Cfg_T stream_table_info_addr          = {0};
   Stream_Info_T stream_list_info_addr          = {0};
   uint32_t Ping_Pong_Index_dummy               = 3U;
   Number_Of_Streams_Initialized                = 0;
   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 3U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   /*Function Under test*/
   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized,
             0U); /*streams initialized: DSP_Write(3) -> HIL_Ipc_Index=1, HIL_Ipc_Index(1) < NUM_IPC_INDEX(2) is true*/
}

TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_interface_TC7)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 0U;
   Number_Of_Streams_Initialized       = 0;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;
   Stream_Memory_Map[0][0].stream_id       = 112U; /*to achive stream number mismatch condition*/
   Stream_Memory_Map[0][1].stream_id       = 113U; /*to achive stream number mismatch condition*/

   /*Function Under test*/
   Update_HIL_Input_Interface(); /*check when stream Memory map is not properly initialized*/
   /*Assertions*/
   ASSERT_EQ(hil_input_data.hil_init_failed, true);
}

TEST_F(HIL_Interface_Unit_Test_Suite, MSS_to_DSS_buffer_NULL_check)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 0U;
   Number_Of_Streams_Initialized       = 0;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = NULL;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;
   Stream_Memory_Map[0][0].stream_id       = 112U; /*to achive stream number mismatch condition*/
   Stream_Memory_Map[0][1].stream_id       = 113U; /*to achive stream number mismatch condition*/

   /*Function Under test*/
   Update_HIL_Input_Interface(); /*check when stream Memory map is not properly initialized*/

   /*Assertions*/
   ASSERT_EQ(Number_Of_Streams_Initialized, 0u);
   ASSERT_EQ(HIL_Mem_Update, 0u);
}

TEST_F(HIL_Interface_Unit_Test_Suite, M7buffer_Null_check)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 1U;
   Number_Of_Streams_Initialized       = 0u;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = 0U;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = 0U;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_EQ(Number_Of_Streams_Initialized, 0u);
   ASSERT_EQ(HIL_Mem_Update, 0u);
}
#if 0
TEST_F(HIL_Interface_Unit_Test_Suite, A53_Null_check)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   uint32_t Ping_Pong_Index_dummy      = 1U;
   Number_Of_Streams_Initialized       = 0u;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val        = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val       = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val    = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val       = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val          = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val          = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams        = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_EQ(Number_Of_Streams_Initialized, 0u);
   ASSERT_EQ(HIL_Mem_Update, 0u);
}
#endif
TEST_F(HIL_Interface_Unit_Test_Suite, MAXhil_ipc_index_check)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   Number_Of_Streams_Initialized       = 0u;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = NUM_IPC_INDEX;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized,
             0u); /*DSP_Write(2) -> HIL_Ipc_Index=1, guard HIL_Ipc_Index < NUM_IPC_INDEX passes -> streams initialized*/
   ASSERT_NE(HIL_Mem_Update, 0u);
}

TEST_F(HIL_Interface_Unit_Test_Suite, different_IPC_index_value)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   Number_Of_Streams_Initialized       = 0u;
   HIL_Mem_Update                      = 0u;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;
   hil_input_data.num_hil_enabled_streams  = 5U;

   Update_HIL_Input_Interface();

   /*Assertions*/
   ASSERT_NE(Number_Of_Streams_Initialized,
             0u); /*DSP_Write(0) -> HIL_Ipc_Index=0, guard HIL_Ipc_Index < NUM_IPC_INDEX passes -> streams initialized*/
   ASSERT_NE(HIL_Mem_Update, 0u);
}

/* =========================================================================
 * New tests — improve coverage for Update_HIL_Input_Interface
 * ========================================================================= */

/* DSP_Write == 0  → ping path: HIL_Ping_Index++, IPC_D2M_Buff_Ptr = ping,
 * HIL_Ipc_Index = 0, hil_input_data.hil_ipc_index = 0               */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_ping_index_increments_correct_buffer_selected)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   HIL_Ping_Index = 0U;
   HIL_Pong_Index = 0U;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U; /* ping path */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   ASSERT_EQ(HIL_Ping_Index, 1U);                                      /* ping incremented */
   ASSERT_EQ(HIL_Pong_Index, 0U);                                      /* pong unchanged */
   ASSERT_EQ(IPC_D2M_Buff_Ptr, (D2M_Msg_T *)((size_t)ping_buff_addr)); /* correct buffer */
   ASSERT_EQ(HIL_Ipc_Index, 0U);                                       /* index == 0 for ping */
   ASSERT_EQ(hil_input_data.hil_ipc_index, 0U);                        /* propagated to input */
}

/* DSP_Write != 0  → pong path: HIL_Pong_Index++, IPC_D2M_Buff_Ptr = pong,
 * HIL_Ipc_Index = 1, hil_input_data.hil_ipc_index = 1               */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_pong_index_increments_correct_buffer_selected)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   HIL_Ping_Index = 0U;
   HIL_Pong_Index = 0U;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U; /* pong path */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   ASSERT_EQ(HIL_Pong_Index, 1U);                                      /* pong incremented */
   ASSERT_EQ(HIL_Ping_Index, 0U);                                      /* ping unchanged */
   ASSERT_EQ(IPC_D2M_Buff_Ptr, (D2M_Msg_T *)((size_t)pong_buff_addr)); /* correct buffer */
   ASSERT_EQ(HIL_Ipc_Index, 1U);                                       /* index == 1 for pong */
   ASSERT_EQ(hil_input_data.hil_ipc_index, 1U);                        /* propagated to input */
}

/* hil_tx_message_fptr, hil_get_source_time_fptr, stream_table_cfg_ptr and
 * stream_info_ptr must all be populated by Update_HIL_Input_Interface     */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_input_data_pointers_correctly_populated)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   ASSERT_NE(hil_input_data.hil_tx_message_fptr, nullptr);      /* &SoAd_IfTransmit */
   ASSERT_NE(hil_input_data.hil_get_source_time_fptr, nullptr); /* &Get_HIL_Timestamp_ms */
   ASSERT_EQ(hil_input_data.stream_table_cfg_ptr, &stream_table_info_addr);
   ASSERT_EQ(hil_input_data.stream_info_ptr, &stream_list_info_addr);
}

/* Values written to hil_output_data must be forwarded verbatim to
 * ipc_m2d_buff_ptr->payload.hil_ipc_info.*                         */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_m2d_output_fields_written_from_hil_output)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   /* Distinctive sentinel values */
   hil_output_data.hil_mode_enabled               = 0xAAU;
   hil_output_data.hil_scanindex                  = 42U;
   hil_output_data.hil_enabled_streams[DETECTION] = 0x55U;
   hil_output_data.hil_enabled_streams[STATUS]    = 0xAAU;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   ASSERT_EQ(mss_to_dss_l3.payload.hil_ipc_info.hil_mode_enabled, 0xAAU);
   ASSERT_EQ(mss_to_dss_l3.payload.hil_ipc_info.hil_scanindex, 42U);
   ASSERT_EQ(mss_to_dss_l3.payload.hil_ipc_info.hil_enabled_streams[DETECTION], 0x55U);
   ASSERT_EQ(mss_to_dss_l3.payload.hil_ipc_info.hil_enabled_streams[STATUS], 0xAAU);
}

/* ipc_m2d_buff_ptr->payload.look_Info.scan_index must be forwarded to
 * hil_input_data.current_radar_scan_index                           */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_scan_index_forwarded_to_input)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   mss_to_dss_l3.payload.look_Info.scan_index = 77U;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   ASSERT_EQ(hil_input_data.current_radar_scan_index, 77U);
}

/* When hil_req_stream_num does not match any entry in Stream_Memory_Map the
 * false branch of the stream-id comparison in Update_HIL_App_Buf_Addr must
 * be taken.  All map entries have stream_id=0 (zero-init struct); requesting
 * stream_id=99 guarantees no match → hil_req_stream_buff_ptr stays NULL and
 * hil_memory_init_failed remains false (match body never entered).          */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_App_Buf_Addr_no_stream_id_match)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   Header_Stream_T header_stream_ut    = {0};
   Status_Stream_T status_stream_ut    = {0};

   /* Request a stream ID that will never appear in the map (map stream IDs are
    * all 0 because stream_table_info_addr is zero-initialised).              */
   hil_input_data.num_hil_enabled_streams              = 1U;
   hil_input_data.hil_init_table[0].hil_req_stream_num = 99U;

   Get_Header_Stream_Ptr_fake.return_val        = &header_stream_ut;
   Get_Status_Stream_Ptr_fake.return_val        = &status_stream_ut;
   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U; /* ping → map rebuilt at IPC index 0 */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   /* Stream ID 99 is not in the map → buff_ptr stays NULL */
   ASSERT_EQ(hil_input_data.hil_init_table[0].hil_req_stream_buff_ptr, nullptr);
   /* hil_memory_init_failed stays false: the match body (NULL check) was never entered */
   ASSERT_EQ(hil_input_data.hil_init_failed, false);
}

/* When hil_req_stream_num MATCHES an entry whose stream_addr is NULL the
 * hil_stream_memory_init_failed flag and hil_init_failed must be CODED_TRUE. */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_App_Buf_Addr_matched_but_null_addr)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   /* stream_id=0 in map will match hil_req_stream_num=0 (default), but leave
    * stream_addr=NULL (Get_Header/Status return NULL by default).
    * Force Number_Of_Streams_Initialized so the inner loop executes.        */
   Number_Of_Streams_Initialized       = 1U;
   Stream_Memory_Map[0][0].stream_id   = 0U;   /* matches hil_req_stream_num=0 */
   Stream_Memory_Map[0][0].stream_addr = NULL; /* NULL → failure path */

   hil_input_data.num_hil_enabled_streams              = 1U;
   hil_input_data.hil_init_table[0].hil_req_stream_num = 0U; /* will match */

   /* Use ping path so HIL_Ipc_Index=0 matches the slot we set above */
   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U;
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   /* Match found but addr is NULL → per-stream failure flag set */
   ASSERT_EQ(hil_input_data.hil_init_table[0].hil_stream_memory_init_failed, CODED_TRUE);
   /* Accumulated failure must also be set */
   ASSERT_EQ(hil_input_data.hil_init_failed, true);
}

/* When HEADER and STATUS fakes return non-NULL pointers every stream address
 * in the map is valid → hil_init_failed must be false (success path of
 * Update_HIL_App_Buf_Addr / hil_memory_init_failed=false)           */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_memory_init_success_all_addrs_non_null)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};
   Header_Stream_T header_stream_ut    = {0};
   Status_Stream_T status_stream_ut    = {0};

   /* Provide non-NULL Header and Status pointers to make all stream addrs valid */
   Get_Header_Stream_Ptr_fake.return_val  = &header_stream_ut;
   Get_Status_Stream_Ptr_fake.return_val  = &status_stream_ut;
   hil_input_data.num_hil_enabled_streams = 5U;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 0U; /* ping → IPC_D2M_Buff_Ptr = d2m_msg[0] (non-NULL) */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   /* All stream addresses non-NULL → memory init must succeed */
   ASSERT_EQ(hil_input_data.hil_init_failed, false);
}

/* EUR-2799: When IPC_D2M_Buff_Ptr is non-NULL, hil_rx_mailbox is resolved
 * from the D2M payload, hil_rx_complete_flag is reset to CODED_FALSE, and
 * hil_input_data.hil_rx_complete_flag is set to point to the mailbox flag. */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_rx_mailbox_valid_buffer_resets_rx_complete_flag)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   /* Pre-set the flag to a non-CODED_FALSE sentinel to confirm it is overwritten */
   d2m_msg[1].payload.hil_rx_mailbox.hil_rx_complete_flag = 0xFFU;

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U; /* pong path → IPC_D2M_Buff_Ptr = d2m_msg[1] */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = pong_buff_addr;

   Update_HIL_Input_Interface();

   /* hil_rx_complete_flag in the D2M mailbox must be cleared to CODED_FALSE */
   ASSERT_EQ(d2m_msg[1].payload.hil_rx_mailbox.hil_rx_complete_flag, CODED_FALSE);
   /* hil_input_data.hil_rx_complete_flag must point into the D2M pong buffer mailbox */
   ASSERT_EQ(hil_input_data.hil_rx_complete_flag, &d2m_msg[1].payload.hil_rx_mailbox.hil_rx_complete_flag);
}

/* EUR-2799: When IPC_D2M_Buff_Ptr is NULL (D2M buffer addr returns zero),
 * hil_rx_mailbox stays NULL and the flag-reset block is skipped entirely —
 * hil_input_data.hil_rx_complete_flag must remain nullptr. */
TEST_F(HIL_Interface_Unit_Test_Suite, HIL_rx_mailbox_null_buffer_skips_rx_complete_flag)
{
   HIL_Input_T hil_input_data          = {0};
   HIL_Output_T hil_output_data        = {0};
   M2D_Msg_T mss_to_dss_l3             = {0};
   Stream_Cfg_T stream_table_info_addr = {0};
   Stream_Info_T stream_list_info_addr = {0};

   Get_HIL_Input_Data_Ptr_fake.return_val       = &hil_input_data;
   Get_HIL_Output_Data_Ptr_fake.return_val      = &hil_output_data;
   Get_MSS_IPC_M2D_Msg_Buf_Addr_fake.return_val = &mss_to_dss_l3;
   SetShOutput(&stream_table_info_addr, &stream_list_info_addr);
   Get_DSP_Write_IPC_Index_fake.return_val = 1U; /* pong path */
   Get_D2M_Ping_Buf_Addr_fake.return_val   = ping_buff_addr;
   Get_D2M_Pong_Buf_Addr_fake.return_val   = 0x0; /* NULL → IPC_D2M_Buff_Ptr = NULL */

   Update_HIL_Input_Interface();

   /* hil_rx_mailbox stayed NULL → flag pointer must not be written */
   ASSERT_EQ(hil_input_data.hil_rx_complete_flag, nullptr);
}

void Get_Platform_mstime_SetValue(uint32_t *out_ms)
{
   if (out_ms != nullptr)
   {
      *out_ms = 1234u;
   }
}

TEST(SWC_PLT_CDD_HIL_UnitTest, Get_HIL_Timestamp_ms_ReturnsPlatformTime)
{
   RESET_FAKE(Get_Platform_mstime);
   FFF_RESET_HISTORY();

   Get_Platform_mstime_fake.custom_fake = Get_Platform_mstime_SetValue;

   const uint32_t ts_ms = Get_HIL_Timestamp_ms();

   EXPECT_EQ(1u, Get_Platform_mstime_fake.call_count);
   EXPECT_NE(nullptr, Get_Platform_mstime_fake.arg0_val);
   EXPECT_EQ(1234u, ts_ms);
}
