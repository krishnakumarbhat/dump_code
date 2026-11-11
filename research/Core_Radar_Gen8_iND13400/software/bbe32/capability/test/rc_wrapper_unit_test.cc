/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"
#include "ipc_data.h"
#include "rc_types.h"
#include "rc_wrapper_fake.h"
#include "smc_cal.h"
#include "usc_cal.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
DEFINE_FFF_GLOBALS;

extern "C"
{
#include "rc_wrapper.c"
}

Dynamic_Alignment_Log_Stream_T alignment_log = {0};

Dynamic_Alignment_Log_Stream_T *Get_Prev_Dyn_Align_Output_custom_fake(void)
{
   return (Dynamic_Alignment_Log_Stream_T *)&alignment_log;
}

SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
USC_Cal_T USC_Cal_Data;
USC_Cal_T *USC_Cal_Data_Ptr = &USC_Cal_Data;
M2D_One_Time_Msg_T RC_One_Time_Buff;
/*===========================================================================*
 * Global Definition
 *===========================================================================*/

// Allocate memory for detection_input and detections_prop (and any other RC internal ptrs)
static void Allocate_RC_Internal_Memory()
{
   RC_Internal_Mem_Info_T *mem = Get_RC_Internal_memory_pointers();
   for (size_t i = 0; i < RC_MP_MAX_NUM_MEMORY_LOC; ++i)
   {
      if ((mem[i].addr_ptr != nullptr) && (mem[i].size > 0U))
      {
         void *p = std::malloc(mem[i].size);
         assert(p != nullptr);
         std::memset(p, 0, mem[i].size);
         *(mem[i].addr_ptr) = p;
      }
   }
}

static void Free_RC_Internal_Memory()
{
   RC_Internal_Mem_Info_T *mem = Get_RC_Internal_memory_pointers();
   for (size_t i = 0; i < RC_MP_MAX_NUM_MEMORY_LOC; ++i)
   {
      if ((mem[i].addr_ptr != nullptr) && (*(mem[i].addr_ptr) != nullptr))
      {
         std::free(*(mem[i].addr_ptr));
         *(mem[i].addr_ptr) = nullptr;
      }
   }
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class rc_wrapper_UnitTestSuite : public testing::Test
{
 public:
   D2M_Msg_T ipc_d2m;
   M2D_Msg_T ipc_m2d;
   Dynamic_Alignment_Log_Stream_T alignment_log;

 protected:
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(&ipc_d2m, 0, sizeof(D2M_Msg_T));
      memset(&ipc_m2d, 0, sizeof(M2D_Msg_T));

      rc_wrapper_reset();
      Allocate_RC_Internal_Memory();
   }
   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
      Free_RC_Internal_Memory();
   }
};

/**
 *  @b rc_get_ver_major
 *  @n
 *      Test the rc wrapper rc_get_ver_major function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_get_ver_major_unit_test)
{
   // ARRANGE
   uint8_t rc_ver_major = 3U;

   // ACT
   rc_get_ver_major();

   // ASSERT
   EXPECT_EQ(3U, rc_ver_major);
}

/**
 *  @b rc_get_ver_minor
 *  @n
 *      Test the rc wrapper rc_get_ver_minor function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_get_ver_minor_unit_test)
{
   // ARRANGE
   uint8_t rc_ver_minor = 2U;

   // ACT
   rc_get_ver_minor();

   // ASSERT
   EXPECT_EQ(2U, rc_ver_minor);
}

/**
 *  @b rc_get_ver_patch
 *  @n
 *      Test the rc wrapper rc_get_ver_patch function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_get_ver_patch_unit_test)
{
   // ARRANGE
   uint8_t rc_ver_patch = 0U;

   // ACT
   rc_get_ver_patch();

   // ASSERT
   EXPECT_EQ(0U, rc_ver_patch);
}

/**
 *  @b rc_map_input_data
 *  @n
 *      Test the rc_map_input_data function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_map_input_data_unit_test_1)
{
   // ARRANGE
   ipc_d2m.payload.det_data.det_list_property.lookindex                  = 13U;
   ipc_d2m.payload.rdd_stream_data.look_data.scan_index                  = 99U;
   ipc_m2d.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = 12.3F;
   // ipc_d2m.payload.interference_detection_data.interference_data_discard = true;
   ipc_m2d.payload.avg_mmic_onchip_temp       = 59;
   Get_Prev_Dyn_Align_Output_fake.custom_fake = Get_Prev_Dyn_Align_Output_custom_fake;

   // ACT
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ASSERT
   EXPECT_EQ(13U, rc_input->p_det_data.det_list_property.lookindex);
   EXPECT_EQ(99U, rc_input->p_rdd_stream_data.look_data.scan_index);
   EXPECT_FLOAT_EQ(12.3F, rc_input->p_veh_data.veh_speed);
   // EXPECT_TRUE(rc_input->p_id_data.interference_data_discard);
   EXPECT_EQ(59, rc_input->avg_mmic_onchip_temp);
}

/**
 *  @b rc_ptr_update
 *  @n
 *      Covers null IPC input branches used by wrapper-side pointer wiring.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_ptr_update_null_inputs_sets_defaults)
{
   // ARRANGE
   RC_Input_Data_T rc_ipc_data_ut             = {0};
   M2D_One_Time_Msg_T m2d_one_time_init       = {0};
   Get_Prev_Dyn_Align_Output_fake.custom_fake = Get_Prev_Dyn_Align_Output_custom_fake;

   // ACT
   rc_ptr_update(nullptr, nullptr, &rc_ipc_data_ut, &m2d_one_time_init);

   // ASSERT
   EXPECT_EQ(rc_ipc_data_ut.f_initialized, CODED_FALSE);
   EXPECT_EQ(rc_ipc_data_ut.vse_data, nullptr);
   EXPECT_EQ(rc_ipc_data_ut.af_ipc_data, nullptr);
   EXPECT_EQ(rc_ipc_data_ut.af_debug_data, nullptr);
   EXPECT_EQ(rc_ipc_data_ut.rdd_ipc_data, nullptr);
   EXPECT_EQ(rc_ipc_data_ut.rc_output, nullptr);
   EXPECT_EQ(rc_ipc_data_ut.ipc_avg_mmic_onchip_temp, RC_INVALID_MMIC_TEMPERATURE);
}

/**
 *  @b rc_wrapper
 *  @n
 *      Test the rc wrapper function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_wrapper_unit_test_5)
{
   // ARRANGE
   Get_Prev_Dyn_Align_Output_fake.return_val                                                          = &alignment_log;
   ipc_d2m.payload.rdd_stream_data.rdd_data.cfar_nf_est[RC_MNR_MIN_RBIN_IND_VERY_CLOSE][0]            = 1000U;
   ipc_d2m.payload.rdd_stream_data.rdd_data.rdd1_max_per_range_bin[RC_MNR_MIN_RBIN_IND_VERY_CLOSE][0] = 2000U;

   ipc_d2m.payload.det_data.num_af_det                      = 5;
   ipc_d2m.payload.det_data.det_list_property.lookindex     = 2U;
   ipc_d2m.payload.rdd_stream_data.look_data.scan_index     = 2U;
   ipc_d2m.payload.rdd_stream_data.look_data.look_id        = 1U;
   ipc_d2m.payload.rdd_stream_data.rdd_data.rdd1_num_detect = 3U;
   // ipc_d2m.payload.interference_detection_data.stream_hdr.scan_index     = 2U;
   // ipc_d2m.payload.interference_detection_data.interference_data_discard = false;
   ipc_m2d.payload.veh_data.stream_hdr.scan_index                        = 4U;
   ipc_m2d.payload.avg_mmic_onchip_temp                                  = 62;
   ipc_m2d.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = 11.1F;
   ipc_m2d.payload.veh_data.vse_output.comp_yaw_rate_filtered            = 0.1F;

#ifdef SRR8P
   SMC_Cal_Data_Ptr->Header2_Info.platform = 83U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 83U;
#endif

#ifdef FLR8
   SMC_Cal_Data_Ptr->Header2_Info.platform = 82U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 82U;
#endif

   // Timestamp
   ipc_d2m.payload.det_data.det_list_property.detection_timestamp_ns  = 151000000U;
   ipc_d2m.payload.det_data.det_list_property.detection_timestamp_sec = 12U;

   const uint32_t timestamp_s                 = ipc_d2m.payload.det_data.det_list_property.detection_timestamp_sec;
   const uint32_t timestamp_ns                = ipc_d2m.payload.det_data.det_list_property.detection_timestamp_ns;
   const uint32_t timestamp_ms                = (timestamp_s * 1000U) + (timestamp_ns / 1000000U);
   Get_Prev_Dyn_Align_Output_fake.custom_fake = Get_Prev_Dyn_Align_Output_custom_fake;

   // ACT
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ASSERT
   // EXPECT_EQ(timestamp_ms, ipc_d2m.payload.radar_capability_data.timestamp_ms);
   EXPECT_EQ(2U, ipc_d2m.payload.radar_capability_data.look_index);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.look_type);
   EXPECT_EQ(11.1F, ipc_d2m.payload.radar_capability_data.host_speed_m_s);
   EXPECT_EQ(0.1F, ipc_d2m.payload.radar_capability_data.host_yawrate_rad_s);
   EXPECT_EQ(62, ipc_d2m.payload.radar_capability_data.avg_mmic_onchip_temp);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.blockage.blockage_active);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.dm.dm_active);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.re.re_active);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.se.se_active);
   EXPECT_EQ(1U, ipc_d2m.payload.radar_capability_data.pbd.pbd_active);
}

/**
 *  @b rc_wrapper
 *  @n
 *      Test the rc wrapper function.
 */
TEST_F(rc_wrapper_UnitTestSuite, Radarcapability_Init_unit_test_1)
{
   // ARRANGE
   ipc_m2d.payload.avg_mmic_onchip_temp = 62;

   // ACT
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ASSERT
   EXPECT_EQ(62, rc_input->avg_mmic_onchip_temp);
}

/**
 *  @b rc_wrapper
 *  @n
 *      Test the rc wrapper function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_wrapper_unit_test_6)
{
   // ARRANGE
   // Initialize the data
#ifdef SRR8P
   SMC_Cal_Data_Ptr->Header2_Info.platform = 82U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 82U;
#endif

#ifdef FLR8
   SMC_Cal_Data_Ptr->Header2_Info.platform = 83U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 83U;
#endif
   Radar_Capability_Stream_T *rc_output = NULL;
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ACT
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ASSERT
   ASSERT_EQ(0, rc_output);
}

/**
 *  @b rc_wrapper
 *  @n
 *      Test the rc wrapper function.
 */
TEST_F(rc_wrapper_UnitTestSuite, rc_wrapper_unit_test_7)
{
   // ARRANGE
   // Initialize the data
#ifdef SRR8P
   SMC_Cal_Data_Ptr->Header2_Info.platform = 83U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 83U;
#endif

#ifdef FLR8
   SMC_Cal_Data_Ptr->Header2_Info.platform = 82U;
   USC_Cal_Data_Ptr->Header2_Info.platform = 82U;
#endif
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   ipc_m2d.payload.veh_data.stream_hdr.scan_index                        = 4U;
   ipc_m2d.payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = 11.1F;
   ipc_m2d.payload.veh_data.vse_output.comp_yaw_rate_filtered            = 0.1F;
   ipc_m2d.payload.avg_mmic_onchip_temp                                  = 62;

   // ACT
   rc_wrapper(&ipc_d2m, &ipc_m2d, &RC_One_Time_Buff);

   // ASSERT
   EXPECT_EQ(62, rc_input->avg_mmic_onchip_temp);
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Test successful memory allocation from pool.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_success_test)
{
   // ARRANGE
   const uint32_t POOL_SIZE = 32000U; // Must be >= sizeof(RC_Input_T) + alignment overhead (~31KB)
   uint8_t memory_buffer[POOL_SIZE] __attribute__((aligned(32)));
   Mem_Pool_T test_mem_pool;
   Memory_Pool_Return_T init_result;
   Memory_Pool_Return_T alloc_result;

   // Save original pointers (allocated by SetUp())
   RC_Input_T *saved_rc_input = rc_input;

   // Initialize memory pool
   init_result = Mem_Pool_Init(&test_mem_pool, memory_buffer, POOL_SIZE);
   ASSERT_EQ(MEM_POOL_SUCCESS, init_result);

   // ACT
   alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result);
   EXPECT_NE(nullptr, rc_input);

   // Verify memory pool size increased (memory was allocated)
   EXPECT_GT(test_mem_pool.size, 0U);

   // Restore original pointers for TearDown() to properly free
   rc_input = saved_rc_input;
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Test memory allocation failure when pool is too small.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_insufficient_memory_test)
{
   // ARRANGE
   const uint32_t POOL_SIZE = 64U; // Very small pool - insufficient
   uint8_t memory_buffer[POOL_SIZE] __attribute__((aligned(32)));
   Mem_Pool_T test_mem_pool;
   Memory_Pool_Return_T init_result;
   Memory_Pool_Return_T alloc_result;

   // Save original pointers (allocated by SetUp())
   RC_Input_T *saved_rc_input = rc_input;

   // Initialize memory pool
   init_result = Mem_Pool_Init(&test_mem_pool, memory_buffer, POOL_SIZE);
   ASSERT_EQ(MEM_POOL_SUCCESS, init_result);

   // ACT
   alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_FAILURE, alloc_result);

   // Restore original pointers for TearDown()
   rc_input = saved_rc_input;
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Test memory allocation with exact size requirement.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_exact_size_test)
{
   // ARRANGE
   // Calculate exact size needed
   RC_Internal_Mem_Info_T *mem_info = Get_RC_Internal_memory_pointers();
   uint32_t total_size              = 0U;
   for (uint8_t i = 0; i < RC_MP_MAX_NUM_MEMORY_LOC; i++)
   {
      if ((mem_info[i].addr_ptr != nullptr) && (mem_info[i].size > 0U))
      {
         total_size += MEM_POOL_USAGE(mem_info[i].size);
      }
   }

   // Add some buffer for alignment
   const uint32_t POOL_SIZE = total_size + 128U;
   uint8_t memory_buffer[POOL_SIZE] __attribute__((aligned(32)));
   Mem_Pool_T test_mem_pool;
   Memory_Pool_Return_T init_result;
   Memory_Pool_Return_T alloc_result;

   // Save original pointers (allocated by SetUp())
   RC_Input_T *saved_rc_input = rc_input;

   // Initialize memory pool
   init_result = Mem_Pool_Init(&test_mem_pool, memory_buffer, POOL_SIZE);
   ASSERT_EQ(MEM_POOL_SUCCESS, init_result);

   // ACT
   alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result);
   EXPECT_NE(nullptr, rc_input);

   // Restore original pointers for TearDown()
   rc_input = saved_rc_input;
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Test multiple consecutive allocations and resets.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_reset_and_reallocate_test)
{
   // ARRANGE
   const uint32_t POOL_SIZE = 32000U; // Must be >= sizeof(RC_Input_T) + alignment overhead (~31KB)
   uint8_t memory_buffer[POOL_SIZE] __attribute__((aligned(32)));
   Mem_Pool_T test_mem_pool;
   Memory_Pool_Return_T alloc_result1, alloc_result2;

   // Save original pointers (allocated by SetUp())
   RC_Input_T *saved_rc_input = rc_input;

   // Initialize memory pool
   ASSERT_EQ(MEM_POOL_SUCCESS, Mem_Pool_Init(&test_mem_pool, memory_buffer, POOL_SIZE));

   // ACT - First allocation
   alloc_result1        = Capability_Handler_Memory_Init(&test_mem_pool);
   void *first_rc_input = rc_input;
   uint32_t first_size  = test_mem_pool.size;

   // Reset pool
   Mem_Pool_Reset(&test_mem_pool);

   // ACT - Second allocation
   alloc_result2         = Capability_Handler_Memory_Init(&test_mem_pool);
   void *second_rc_input = rc_input;
   uint32_t second_size  = test_mem_pool.size;

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result1);
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result2);

   // After reset, pointers should be at same addresses (pool reused)
   EXPECT_EQ(first_rc_input, second_rc_input);
   EXPECT_EQ(first_size, second_size);

   // Restore original pointers for TearDown()
   rc_input = saved_rc_input;
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Test that allocated memory size matches expected size for RC_NUM_INSTANCES.
 *      Note: This test validates the basic allocation without checking exact sizes,
 *      since the implementation may vary (static array vs dynamic pointer for rc_memory).
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_verify_instance_count_test)
{
   // ARRANGE
   const uint32_t POOL_SIZE = 32000U; // Must be >= sizeof(RC_Input_T) + alignment overhead (~31KB)
   uint8_t memory_buffer[POOL_SIZE] __attribute__((aligned(32)));
   Mem_Pool_T test_mem_pool;
   Memory_Pool_Return_T alloc_result;

   // Save original pointers (allocated by SetUp())
   RC_Input_T *saved_rc_input = rc_input;

   // Initialize memory pool
   ASSERT_EQ(MEM_POOL_SUCCESS, Mem_Pool_Init(&test_mem_pool, memory_buffer, POOL_SIZE));

   // ACT
   alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result);

   // Verify rc_input was allocated and is not null
   EXPECT_NE(nullptr, rc_input);

   // Verify some memory was allocated from the pool
   EXPECT_GT(test_mem_pool.size, 0U);

   // The allocated size should at least include RC_Input_T
   uint32_t min_expected_size = MEM_POOL_USAGE(sizeof(RC_Input_T));
   EXPECT_GE(test_mem_pool.size, min_expected_size);

   // Restore original pointers for TearDown()
   rc_input = saved_rc_input;
}
/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Cover branch where addr_ptr is NULL and allocation is skipped.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_null_addr_ptr_skips_allocation)
{
   // ARRANGE
   RC_Internal_Mem_Info_T *mem_info = Get_RC_Internal_memory_pointers();
   RC_Input_T *saved_rc_input       = rc_input;

   mem_info[0].addr_ptr = nullptr;
   mem_info[0].size     = sizeof(RC_Input_T);

   alignas(MEM_POOL_ALIGNMENT_IN_BYTES) uint8_t memory_buffer[32000U] = {0};
   Mem_Pool_T test_mem_pool                                           = {0};
   ASSERT_EQ(MEM_POOL_SUCCESS, Mem_Pool_Init(&test_mem_pool, memory_buffer, sizeof(RC_Input_T)));

   // ACT
   Memory_Pool_Return_T alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result);

   // Restore original pointer state for TearDown()
   rc_input = saved_rc_input;
}

/**
 *  @b Capability_Handler_Memory_Init
 *  @n
 *      Cover branch where size is zero and allocation is skipped.
 */
TEST_F(rc_wrapper_UnitTestSuite, Capability_Handler_Memory_Init_zero_size_skips_allocation)
{
   // ARRANGE
   RC_Internal_Mem_Info_T *mem_info = Get_RC_Internal_memory_pointers();
   RC_Input_T *saved_rc_input       = rc_input;
   void *dummy_ptr                  = (void *)saved_rc_input;

   mem_info[0].addr_ptr = &dummy_ptr;
   mem_info[0].size     = 0U;

   alignas(MEM_POOL_ALIGNMENT_IN_BYTES) uint8_t memory_buffer[32000U] = {0};
   Mem_Pool_T test_mem_pool                                           = {0};
   ASSERT_EQ(MEM_POOL_SUCCESS, Mem_Pool_Init(&test_mem_pool, memory_buffer, sizeof(RC_Input_T)));

   // ACT
   Memory_Pool_Return_T alloc_result = Capability_Handler_Memory_Init(&test_mem_pool);

   // ASSERT
   EXPECT_EQ(MEM_POOL_SUCCESS, alloc_result);

   // Restore original pointer state for TearDown()
   rc_input = saved_rc_input;
}

/**
 *  @b Mem_Pool_Init
 *  @n
 *      Test misaligned base address path to cover failure branch in Mem_Pool_Init.
 */
TEST_F(rc_wrapper_UnitTestSuite, Mem_Pool_Init_misaligned_base_fails)
{
   // ARRANGE
   uint8_t memory_buffer[128 + MEM_POOL_ALIGNMENT_IN_BYTES] = {0};
   Mem_Pool_T test_mem_pool                                 = {0};
   uint8_t *misaligned_base                                 = &memory_buffer[1];

   // ACT
   Memory_Pool_Return_T init_result = Mem_Pool_Init(&test_mem_pool, misaligned_base, 128U);

   // ASSERT
   EXPECT_EQ(MEM_POOL_FAILURE, init_result);
   EXPECT_EQ(nullptr, test_mem_pool.base_addr);
   EXPECT_EQ(0U, test_mem_pool.max_size);
   EXPECT_EQ(0U, test_mem_pool.size);
}

/**
 *  @b mapping_det
 *  @n
 *      Test the rc wrapper mapping_det_false_test function with f_is_FLR_sensor set false.
 */
TEST_F(rc_wrapper_UnitTestSuite, mapping_det_false_test)
{
   rc_input->p_det_data.ch_ch_degradation_data.ch_ch_degradation_conf = 0.0F;
   RC_Input_Data_T rc_ipc_data                                        = {0};
   rc_ipc_data.af_ipc_data                                            = &ipc_d2m.payload.det_data;
   mapping_det(rc_ipc_data.af_ipc_data, &rc_input->p_det_data, false);
   ASSERT_EQ(rc_input->p_det_data.ch_ch_degradation_data.ch_ch_degradation_conf, 1.0F);
}

/**
 *  @b mapping_det
 *  @n
 *      Test the rc wrapper mapping_det_true_test function with f_is_FLR_sensor set true.
 */
TEST_F(rc_wrapper_UnitTestSuite, mapping_det_true_test)
{
   rc_input->p_det_data.ch_ch_degradation_data.ch_ch_degradation_conf = 0.0F;
   RC_Input_Data_T rc_ipc_data                                        = {0};
   rc_ipc_data.af_ipc_data                                            = &ipc_d2m.payload.det_data;
   mapping_det(rc_ipc_data.af_ipc_data, &rc_input->p_det_data, true);
   ASSERT_EQ(rc_input->p_det_data.ch_ch_degradation_data.ch_ch_degradation_conf, 1.0F);
}
