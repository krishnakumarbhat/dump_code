/*===========================================================================*/
/**
 * @file static_align_wrapper_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *-----------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the static alignment wrapper
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
 */
/*==========================================================================*/

#include "fff.h"
#include <cmath>
#include <cstring>
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS;

/* Provide math helper and calibration stubs before including the UUT */
extern "C"
{
#define UNIT_TEST_SA
#include "smc_cal.h"

   /* SMC calibration data required by k_sensor_mount_location_smc macro */
   SMC_Cal_T SMC_Cal_Data      = {0};
   SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;

   /* rm_fabsf: declared in static_align_wrapper.h, not provided by sabb */
   float rm_fabsf(float x)
   {
      return fabsf(x);
   }

/* Include the Unit Under Test for coverage instrumentation */
#include "static_align_wrapper.c"
}

/* IPC buffers used across tests */
static D2M_Msg_T IPC_D2M_Buffer                   = {0};
static M2D_Msg_T IPC_M2D_Buffer                   = {0};
static M2D_One_Time_Msg_T IPC_M2D_One_Time_Buffer = {0};
static SA_Input_Data_T sa_ipc_data                = {0};

/* Memory pool backing buffer (aligned to MEM_POOL_ALIGNMENT_IN_BYTES = 32) */
static uint8_t mem_pool_buf[4096U] __attribute__((aligned(32))) = {0};

/* Test suite */
class StaticAlignmentWrapperTest : public testing::Test
{
 protected:
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      memset(&IPC_D2M_Buffer, 0, sizeof(IPC_D2M_Buffer));
      memset(&IPC_M2D_Buffer, 0, sizeof(IPC_M2D_Buffer));
      memset(&IPC_M2D_One_Time_Buffer, 0, sizeof(IPC_M2D_One_Time_Buffer));
      memset(&sa_ipc_data, 0, sizeof(sa_ipc_data));
      memset(mem_pool_buf, 0, sizeof(mem_pool_buf));
   }
   void TearDown() override
   {
   }
};

/* ---- Helper: build an initialised memory pool ---- */
static Mem_Pool_T make_pool(void)
{
   Mem_Pool_T pool = {0};
   (void)Mem_Pool_Init(&pool, mem_pool_buf, sizeof(mem_pool_buf));
   return pool;
}

/* ---- Tests ---- */

TEST_F(StaticAlignmentWrapperTest, GetMemoryPointers_ReturnsNonNull)
{
   SA_Internal_Mem_Info_T *mem_info = Get_SA_Internal_memory_pointers();
   ASSERT_NE(nullptr, mem_info);
   EXPECT_GT(mem_info[0].size, 0u);
   EXPECT_NE(nullptr, mem_info[0].addr_ptr);
}

TEST_F(StaticAlignmentWrapperTest, MemoryInit_Success)
{
   Mem_Pool_T pool          = make_pool();
   Memory_Pool_Return_T ret = SA_Alignment_Handler_Memory_Init(&pool);
   EXPECT_EQ(MEM_POOL_SUCCESS, ret);
   /* sra_det_input should now point into the pool */
   SA_Internal_Mem_Info_T *info = Get_SA_Internal_memory_pointers();
   EXPECT_NE(nullptr, *info[0].addr_ptr);
}

TEST_F(StaticAlignmentWrapperTest, MemoryInit_InsufficientPool_Fails)
{
   /* Pool too small to hold SRA_Detection_Input_T */
   static uint8_t small_buf[4U] __attribute__((aligned(32)));
   Mem_Pool_T pool = {0};
   (void)Mem_Pool_Init(&pool, small_buf, sizeof(small_buf));
   Memory_Pool_Return_T ret = SA_Alignment_Handler_Memory_Init(&pool);
   EXPECT_EQ(MEM_POOL_FAILURE, ret);
}

TEST_F(StaticAlignmentWrapperTest, SaPtrUpdate_AssignsPointers)
{
   sa_ptr_update(&IPC_M2D_Buffer, &IPC_D2M_Buffer, &IPC_M2D_One_Time_Buffer, &sa_ipc_data);

   EXPECT_EQ(sa_ipc_data.p_sa_data, &IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data);
   EXPECT_EQ(sa_ipc_data.p_da_data, &IPC_M2D_Buffer.payload.alignment_Info.dynamic_alignment_data);
   EXPECT_EQ(sa_ipc_data.p_sa_calib_data, &IPC_M2D_One_Time_Buffer.calib_data);
   EXPECT_EQ(sa_ipc_data.p_af_det_data, &IPC_D2M_Buffer.payload.det_data);
   EXPECT_EQ(sa_ipc_data.p_vehicle_data, &IPC_M2D_Buffer.payload.veh_data);
   EXPECT_EQ(sa_ipc_data.p_stat_align_stream_data, &IPC_D2M_Buffer.payload.alignment_stream_data);
   EXPECT_EQ(sa_ipc_data.p_ID_data, &IPC_D2M_Buffer.payload.interference_detection_data);
   EXPECT_EQ(sa_ipc_data.p_rdd_stream_data, &IPC_D2M_Buffer.payload.rdd_stream_data);
}

TEST_F(StaticAlignmentWrapperTest, StaticAlignWrapper_NoInit_DataNotValid)
{
   /* f_data_valid == 0 → no init, no execution */
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.f_data_valid = 0U;
   static_align_wrapper(&IPC_D2M_Buffer, &IPC_M2D_Buffer, &IPC_M2D_One_Time_Buffer);
   SUCCEED();
}

TEST_F(StaticAlignmentWrapperTest, StaticAlignWrapper_InitPath_DataValid)
{
   /* Allocate sra_det_input so Execute_Static_Alignment can dereference it */
   Mem_Pool_T pool = make_pool();
   (void)SA_Alignment_Handler_Memory_Init(&pool);

   /* Trigger init path: f_data_valid > 0 */
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.f_data_valid = 1U;
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.align_cmd    = (uint8_t)SRA_ALGO_MODE_ACTIVE;

   static_align_wrapper(&IPC_D2M_Buffer, &IPC_M2D_Buffer, &IPC_M2D_One_Time_Buffer);
   SUCCEED();
}

TEST_F(StaticAlignmentWrapperTest, StaticAlignWrapper_AlignCmdChange)
{
   Mem_Pool_T pool = make_pool();
   (void)SA_Alignment_Handler_Memory_Init(&pool);

   /* First call to set prev_align_cmd */
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.f_data_valid = 1U;
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.align_cmd    = (uint8_t)SRA_ALGO_MODE_ACTIVE;
   static_align_wrapper(&IPC_D2M_Buffer, &IPC_M2D_Buffer, &IPC_M2D_One_Time_Buffer);

   /* Second call with different align_cmd → re-init path */
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.align_cmd = (uint8_t)SRA_ALGO_MODE_OFF;
   static_align_wrapper(&IPC_D2M_Buffer, &IPC_M2D_Buffer, &IPC_M2D_One_Time_Buffer);
   SUCCEED();
}

TEST_F(StaticAlignmentWrapperTest, StaticAlignWrapper_InterferenceLevelHigh)
{
   Mem_Pool_T pool = make_pool();
   (void)SA_Alignment_Handler_Memory_Init(&pool);

   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.f_data_valid = 1U;
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.align_cmd    = (uint8_t)SRA_ALGO_MODE_ACTIVE;
   /* Set interference level == 4 to exercise the SRA_DEGRADATION_HIGH branch */
   IPC_D2M_Buffer.payload.interference_detection_data.interference_level = 4U;

   static_align_wrapper(&IPC_D2M_Buffer, &IPC_M2D_Buffer, &IPC_M2D_One_Time_Buffer);
   SUCCEED();
}

TEST_F(StaticAlignmentWrapperTest, StaticAlignWrapper_radar_pos)
{
   // Start with init status set
   // Setup different align_cmd to trigger re-init path
   IPC_M2D_Buffer.payload.alignment_Info.static_alignment_data.align_cmd = 5;
   /* Ensure internal sra_det_input is allocated to avoid NULL deref in convert_detections */
   SA_Internal_Mem_Info_T *mem_info                  = Get_SA_Internal_memory_pointers();
   static SRA_Detection_Input_T local_sra_det_input2 = {};
   if ((NULL != mem_info) && (NULL != mem_info[0].addr_ptr))
   {
      (*(SRA_Detection_Input_T **)mem_info[0].addr_ptr) = &local_sra_det_input2;
   }

   sa_ptr_update(&IPC_M2D_Buffer, &IPC_D2M_Buffer, &IPC_M2D_One_Time_Buffer, &sa_ipc_data);

   IPC_M2D_One_Time_Buffer.radar_position = RADAR_POSITION_FRONT_CENTER;
   sa_ipc_data.p_da_one_time_init_data    = &IPC_M2D_One_Time_Buffer;

   Static_align_Init(&sa_ipc_data);

   ASSERT_EQ(sra_radar_params.radar_type, DRA_RADAR_TYPE_FLR8);
   SUCCEED();
}
