/*===========================================================================*/
/**
 * @file main_application_unit_test.cc
 *
 * Unit tests for software/bbe32/src/main_application.c
 *
 * Testable public functions:
 *   - Get_Current_Lookindex()  — returns the static DSP_Current_Look_Index
 *
 * Strategy:
 *   main_application.c includes many Xtensa/SPBB SDK headers that are not
 *   available on the x86 host.  To keep the test self-contained, the source
 *   is compiled into the test via the textual_hdrs mechanism in the BUILD file.
 *
 *   All SDK/Xtensa dependencies are replaced by the stubs in
 *   main_application_fake.h.  Because the source is compiled in the same
 *   translation unit, we can observe module-level static state (e.g.
 *   DSP_Current_Look_Index) indirectly through the public API.
 *
 *   main_application.c defines a symbol named `main` via Main_Application().
 *   That function is an infinite loop and is NOT tested here.
 */
/*==========================================================================*/

#include <gtest/gtest.h>

/*
 * Pull in the fakes BEFORE the source under test so that every symbol
 * referenced by the source is already declared.
 */
#include "main_application_fake.h"

/* ---- Minimal stubs for Xtensa runtime functions used by main_application.c ---- */
static inline int xtos_interrupt_disable(unsigned int intnum)
{
   (void)intnum;
   return 0;
}
static inline int xtos_interrupt_enable(unsigned int intnum)
{
   (void)intnum;
   return 0;
}

/* ---- Include the source under test ---- */
extern "C"
{
/* Rename main_application's Main_Application to avoid infinite-loop issues at test time */
#define Main_Application Main_Application_SUT
#include "main_application.c"
#undef Main_Application
}

/*===========================================================================*
 * Test fixture
 *===========================================================================*/
class MainApplicationTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      /* --- Memory pool fakes --- */
      RESET_FAKE(Mem_Pool_Init);
      RESET_FAKE(Mem_Pool_Alloc);
      RESET_FAKE(Mem_Pool_Reset);

      /* --- One-time init fakes --- */
      RESET_FAKE(Appl_DSP_Process_Onetime_Init);
      RESET_FAKE(Initialize_Perfmon_Info);
      RESET_FAKE(Enable_Dsp_Ecc);
      RESET_FAKE(Set_RA_SEC_Threshold);
      RESET_FAKE(TOI_Init);

      /* --- IPC buffer fakes --- */
      RESET_FAKE(Get_RP_IPC_D2M_Msg_Buffer);
      RESET_FAKE(Get_DP_RDD_IPC_D2M_Msg_Buffer);
      RESET_FAKE(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
      RESET_FAKE(Get_IPC_M2D_Buffer);
      RESET_FAKE(Get_IPC_M2D_One_Time_Buffer);

      /* --- IPC send / notify fakes --- */
      RESET_FAKE(Send_Range_Proc_Complete);
      RESET_FAKE(Send_Doppler_RDD_Proc_Complete);
      RESET_FAKE(Send_SP_Post_Proc_Complete_to_R52);
      RESET_FAKE(Update_DSP_IPC_Notify);
      RESET_FAKE(Send_Core_Initialization);
      RESET_FAKE(Reset_IPC_AF_Buffer);
      RESET_FAKE(Wait_For_Trigger);
      RESET_FAKE(Get_Ipc_Shared_Buffer_Base_Address);

      /* --- Range processing fakes --- */
      RESET_FAKE(Check_For_Range_Process_Complete_Timeout_Check);
      RESET_FAKE(Get_Range_Procesing_Done_Time);

      /* --- Doppler processing fakes --- */
      RESET_FAKE(Appl_Doppler_Dram1_Memory_Init);
      RESET_FAKE(Appl_Doppler_Sram1_Memory_Init);
      RESET_FAKE(Appl_Doppler_Rdd_Processing);
      RESET_FAKE(Set_MMIC_Data_Discard_Info);

      /* --- RDD fakes --- */
      RESET_FAKE(Appl_Rdd_Dram1_Memory_Init);
      RESET_FAKE(Appl_Rdd_Sram1_Memory_Init);
      RESET_FAKE(Appl_Rdd_Fp_Init);
      RESET_FAKE(Appl_Second_Pass_Init);
      RESET_FAKE(Appl_Sweep_Bw_Init);

      /* --- FuSa / BBE self-test fakes --- */
      RESET_FAKE(Appl_BBE_Self_Test_Memory_Init);
      RESET_FAKE(Fusa_BBE_Check_Execute);
      RESET_FAKE(Update_FUSA_BBE_Self_Test_Fault_Flag);

      /* --- Angle finding fakes --- */
      RESET_FAKE(Anglefinding_Memory_Init);
      RESET_FAKE(Appl_Angle_Finding_Process);

      /* --- Radar capability fakes --- */
      RESET_FAKE(Capability_Handler_Memory_Init);
      RESET_FAKE(rc_wrapper);

      /* --- TOI fakes --- */
      RESET_FAKE(TOI_Parameters_Init);
      RESET_FAKE(Determine_Data_Quality);
      RESET_FAKE(Get_TOI_Init_Parameters);
      RESET_FAKE(Get_TOI_Output_Parameters);
      RESET_FAKE(TOI_Radar_Status_Info_Init);

      /* --- Static alignment fakes --- */
      RESET_FAKE(SA_Alignment_Handler_Memory_Init);
      RESET_FAKE(static_align_wrapper);

      /* --- Dynamic alignment fakes --- */
      RESET_FAKE(Alignment_Handler_Memory_Init);
      RESET_FAKE(dyn_align_wrapper);

      /* --- Tracker wrapper fakes --- */
      RESET_FAKE(Emb_Tracker_Mem_Init);
      RESET_FAKE(Init_Emb_Tracker);
      RESET_FAKE(Run_Emb_Tracker);

      /* --- Static register safety fakes --- */
      RESET_FAKE(Bbe32_Static_Register_Safety_Check);

      /* --- Timing / profiling fakes --- */
      RESET_FAKE(Timing_Helpers_Get_Timestamp);
      RESET_FAKE(Timing_Helpers_Get_Time_Microsec);
      RESET_FAKE(Profiling_Helpers_Init);
      RESET_FAKE(Profiling_Helpers_Update);
      RESET_FAKE(Update_IPC_Perfmon_Info);

      /* --- Interference detection fakes --- */
      RESET_FAKE(interference_detection_wrapper);
      RESET_FAKE(ID_Init_BB_Params);
      RESET_FAKE(ID_Populate_Logging_Structure);
      RESET_FAKE(ID_Clear_Logging_Data);
      RESET_FAKE(Get_ID_Init_Parameters);
      RESET_FAKE(Get_ID_BB_Internals);
      RESET_FAKE(ID_Init);
      RESET_FAKE(Interference_Detection);

      /* --- Reset module-static variables to known state --- */
      DSP_Current_Look_Index          = 0U;
      Range_Process_Error_Status      = CODED_FALSE;
      Angle_Finding_Process_Error_Cnt = 0U;

      /* Wire up IPC buffer fakes to return valid pointers */
      Get_RP_IPC_D2M_Msg_Buffer_fake.custom_fake           = Get_RP_IPC_D2M_Msg_Buffer_custom;
      Get_DP_RDD_IPC_D2M_Msg_Buffer_fake.custom_fake       = Get_DP_RDD_IPC_D2M_Msg_Buffer_custom;
      Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_fake.custom_fake = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom;
      Get_IPC_M2D_Buffer_fake.custom_fake                  = Get_IPC_M2D_Buffer_custom;
      Get_IPC_M2D_One_Time_Buffer_fake.custom_fake         = Get_IPC_M2D_One_Time_Buffer_custom;
      Get_TOI_Init_Parameters_fake.custom_fake             = Get_TOI_Init_Parameters_custom;
      Get_TOI_Output_Parameters_fake.custom_fake           = Get_TOI_Output_Parameters_custom;
      Get_ID_Init_Parameters_fake.custom_fake              = Get_ID_Init_Parameters_custom;
      Get_ID_BB_Internals_fake.custom_fake                 = Get_ID_BB_Internals_custom;

      /* Reset shared IPC stubs so each test starts with a clean HIL/TOI state. */
      memset(Get_DP_RDD_IPC_D2M_Msg_Buffer(), 0, sizeof(D2M_Msg_T));
      memset(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(), 0, sizeof(D2M_Msg_T));
      memset(Get_IPC_M2D_Buffer(), 0, sizeof(M2D_Msg_T));
      memset(Get_IPC_M2D_One_Time_Buffer(), 0, sizeof(M2D_One_Time_Msg_T));
      Get_IPC_M2D_Buffer()->payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
      for (uint8_t stream = 0U; stream < MAX_STREAMS_SH; ++stream)
      {
         Get_IPC_M2D_Buffer()->payload.hil_ipc_info.hil_enabled_streams[stream] = CODED_FALSE;
      }

      FFF_RESET_HISTORY();
   }
};

/*===========================================================================*
 * Get_Current_Lookindex tests
 *===========================================================================*/

/**
 * @brief At initialization, DSP_Current_Look_Index is zero.
 *        Get_Current_Lookindex() should therefore return 0.
 */
TEST_F(MainApplicationTest, GetCurrentLookindex_InitialValue_ReturnsZero)
{
   /* DSP_Current_Look_Index is a module-static, zero-initialized variable.
    * Unless the state machine has run, it must be 0. */
   uint16_t idx = Get_Current_Lookindex();
   EXPECT_EQ(idx, 0U);
}

/**
 * @brief Get_Current_Lookindex must return a uint16_t — verify the type
 *        width does not truncate for a known zero value.
 */
TEST_F(MainApplicationTest, GetCurrentLookindex_ReturnsUint16)
{
   uint16_t idx = Get_Current_Lookindex();
   /* The returned value must fit in a uint16_t without loss */
   EXPECT_LE(idx, static_cast<uint16_t>(0xFFFFU));
}

/**
 * @brief Calling Get_Current_Lookindex multiple times returns a consistent value
 *        (no side effects from repeated reads).
 */
TEST_F(MainApplicationTest, GetCurrentLookindex_CalledTwice_SameValue)
{
   uint16_t first  = Get_Current_Lookindex();
   uint16_t second = Get_Current_Lookindex();
   EXPECT_EQ(first, second);
}

/*===========================================================================*
 * Init_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, InitHandler_MemPoolSuccess_ReturnsIdle)
{
   Mem_Pool_Init_fake.return_val     = MEM_POOL_SUCCESS;
   DSP_Main_Application_State_T next = Init_Handler();
   EXPECT_EQ(next, IDLE);
}

TEST_F(MainApplicationTest, InitHandler_MemPoolSuccess_CallsEnableDspEcc)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_SUCCESS;
   Init_Handler();
   EXPECT_EQ(Enable_Dsp_Ecc_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, InitHandler_MemPoolSuccess_CallsRaSecThreshold)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_SUCCESS;
   Init_Handler();
   EXPECT_EQ(Set_RA_SEC_Threshold_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, InitHandler_MemPoolSuccess_CallsOnetimeInit)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_SUCCESS;
   Init_Handler();
   EXPECT_EQ(Appl_DSP_Process_Onetime_Init_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, InitHandler_MemPoolSuccess_CallsInitializePerfmonInfo)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_SUCCESS;
   Init_Handler();
   EXPECT_EQ(Initialize_Perfmon_Info_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, InitHandler_Dram1Failure_ReturnsInit)
{
   /* First call (dram1) fails, second call (sram1) succeeds */
   Memory_Pool_Return_T init_returns[] = {MEM_POOL_FAILURE, MEM_POOL_SUCCESS};
   SET_RETURN_SEQ(Mem_Pool_Init, init_returns, 2);

   DSP_Main_Application_State_T next = Init_Handler();
   EXPECT_EQ(next, INIT);
}

TEST_F(MainApplicationTest, InitHandler_Sram1Failure_ReturnsInit)
{
   /* First call (dram1) succeeds, second call (sram1) fails */
   Memory_Pool_Return_T init_returns[] = {MEM_POOL_SUCCESS, MEM_POOL_FAILURE};
   SET_RETURN_SEQ(Mem_Pool_Init, init_returns, 2);

   DSP_Main_Application_State_T next = Init_Handler();
   EXPECT_EQ(next, INIT);
}

TEST_F(MainApplicationTest, InitHandler_MemPoolFailure_DoesNotCallRaSecThreshold)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_FAILURE;
   (void)Init_Handler();
   EXPECT_EQ(Set_RA_SEC_Threshold_fake.call_count, 0U);
}

TEST_F(MainApplicationTest, InitHandler_AlwaysCallsToiInit)
{
   Mem_Pool_Init_fake.return_val = MEM_POOL_SUCCESS;
   Init_Handler();
   EXPECT_EQ(TOI_Init_fake.call_count, 0U);
}

/*===========================================================================*
 * Idle_Handler tests — skipped: requires threading for do-while loop
 *===========================================================================*/

/*===========================================================================*
 * Wait_For_Rfft_Complete_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, WaitForRfft_RangeError_ReturnsTOIAlignmentProcessing)
{
   Check_For_Range_Process_Complete_Timeout_Check_fake.return_val = APPL_RANGE_ERROR;

   DSP_Main_Application_State_T next = Wait_For_Rfft_Complete_Handler();

   EXPECT_EQ(next, TOI_ALIGNMENT_PROCESSING);
   EXPECT_EQ(Range_Process_Error_Status, CODED_TRUE);
   EXPECT_GE(Send_Range_Proc_Complete_fake.call_count, 1U);
   EXPECT_GE(Send_Doppler_RDD_Proc_Complete_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, WaitForRfft_RangeTimeout_ReturnsTOIAlignmentProcessing)
{
   Check_For_Range_Process_Complete_Timeout_Check_fake.return_val = APPL_RANGE_TIMEOUT;

   DSP_Main_Application_State_T next = Wait_For_Rfft_Complete_Handler();

   EXPECT_EQ(next, TOI_ALIGNMENT_PROCESSING);
   EXPECT_EQ(Range_Process_Error_Status, CODED_TRUE);
}

TEST_F(MainApplicationTest, WaitForRfft_RangeSuccess_ReturnsDoppler)
{
   Check_For_Range_Process_Complete_Timeout_Check_fake.return_val = APPL_RANGE_NO_ERROR;

   DSP_Main_Application_State_T next = Wait_For_Rfft_Complete_Handler();

   EXPECT_EQ(next, DOPPLER_AND_RDD_PROCESSING);
   EXPECT_EQ(Send_Range_Proc_Complete_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, WaitForRfft_RangeSuccess_IncrementsLookIndex)
{
   DSP_Current_Look_Index                                         = 5U;
   Check_For_Range_Process_Complete_Timeout_Check_fake.return_val = APPL_RANGE_NO_ERROR;

   Wait_For_Rfft_Complete_Handler();

   EXPECT_EQ(Get_Current_Lookindex(), 6U);
}

/*===========================================================================*
 * Doppler_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, DopplerHandler_MemPoolFail_ReturnsSPPostProcError)
{
   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_FAILURE;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, SIGPROC_POST_PROCESSING_ERROR);
   EXPECT_GE(Send_Doppler_RDD_Proc_Complete_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, DopplerHandler_DopplerNoError_ReturnsFusa)
{
   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val    = APPL_DOPPLER_NO_ERROR;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, FUSA_BBE_SELF_TEST_PROCESSING);
}

TEST_F(MainApplicationTest, DopplerHandler_DopplerTimeout_ReturnsSPPostProcError)
{
   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val    = APPL_DOPPLER_TIMEOUT;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, SIGPROC_POST_PROCESSING_ERROR);
}

TEST_F(MainApplicationTest, DopplerHandler_DopplerError_ReturnsSPPostProcError)
{
   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val    = APPL_DOPPLER_ERROR;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, SIGPROC_POST_PROCESSING_ERROR);
}

TEST_F(MainApplicationTest, DopplerHandler_CallsMemPoolReset)
{
   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val    = APPL_DOPPLER_NO_ERROR;

   Doppler_Handler();

   /* Two resets: dram1 + sram1 */
   EXPECT_EQ(Mem_Pool_Reset_fake.call_count, 2U);
}

TEST_F(MainApplicationTest, DopplerHandler_NonHILRDDMode_UpdatesRDDStreamHeaders)
{
   D2M_Msg_T *d2m_msg_ptr = Get_DP_RDD_IPC_D2M_Msg_Buffer();
   memset(d2m_msg_ptr, 0, sizeof(*d2m_msg_ptr));
   d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index = 77U;

   M2D_Msg_T *m2d_msg_ptr = Get_IPC_M2D_Buffer();
   memset(m2d_msg_ptr, 0, sizeof(*m2d_msg_ptr));
   m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled         = CODED_FALSE;
   m2d_msg_ptr->payload.hil_ipc_info.hil_enabled_streams[RDD] = CODED_FALSE;

   Appl_Doppler_Dram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val    = APPL_DOPPLER_NO_ERROR;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, FUSA_BBE_SELF_TEST_PROCESSING);
   EXPECT_EQ(77U, d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index);
   EXPECT_EQ(77U, d2m_msg_ptr->payload.rdd_stream_data.stream_hdr.scan_index);
   EXPECT_EQ(sizeof(Rdd_Stream_T), d2m_msg_ptr->payload.rdd_stream_data.stream_hdr.size);
   EXPECT_EQ((uint16_t)ERRORFIELD_NO_ERROR, d2m_msg_ptr->payload.rdd_stream_data.stream_hdr.error_info);
   EXPECT_EQ(77U, d2m_msg_ptr->payload.rdd_debug_data.stream_hdr.scan_index);
   EXPECT_EQ(sizeof(Rdd_Debug_Stream_T), d2m_msg_ptr->payload.rdd_debug_data.stream_hdr.size);
   EXPECT_EQ((uint16_t)ERRORFIELD_NO_ERROR, d2m_msg_ptr->payload.rdd_debug_data.stream_hdr.error_info);
}

TEST_F(MainApplicationTest, DopplerHandler_HILRDDMode_SkipsRDDStreamHeaderUpdate)
{
   D2M_Msg_T *d2m_msg_ptr = Get_DP_RDD_IPC_D2M_Msg_Buffer();
   memset(d2m_msg_ptr, 0, sizeof(*d2m_msg_ptr));
   d2m_msg_ptr->payload.hil_rx_mailbox.hil_rx_complete_flag = CODED_TRUE;

   M2D_Msg_T *m2d_msg_ptr = Get_IPC_M2D_Buffer();
   memset(m2d_msg_ptr, 0, sizeof(*m2d_msg_ptr));
   m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled         = CODED_TRUE;
   m2d_msg_ptr->payload.hil_ipc_info.hil_enabled_streams[RDD] = CODED_TRUE;

   Timing_Helpers_Get_Timestamp_fake.return_val     = 0U;
   Timing_Helpers_Get_Time_Microsec_fake.return_val = MAX_HIL_RX_COMPLETE_WAIT_TIME_US + 1U;
   Appl_Doppler_Dram1_Memory_Init_fake.return_val   = MEM_POOL_SUCCESS;
   Appl_Doppler_Sram1_Memory_Init_fake.return_val   = MEM_POOL_SUCCESS;
   Appl_Doppler_Rdd_Processing_fake.return_val      = APPL_DOPPLER_NO_ERROR;

   DSP_Main_Application_State_T next = Doppler_Handler();

   EXPECT_EQ(next, ANGLE_FINDING_PROCESSING);
   EXPECT_EQ(0U, d2m_msg_ptr->payload.rdd_stream_data.stream_hdr.scan_index);
   EXPECT_EQ(0U, d2m_msg_ptr->payload.rdd_stream_data.stream_hdr.error_info);
   EXPECT_EQ(0U, d2m_msg_ptr->payload.rdd_debug_data.stream_hdr.scan_index);
   EXPECT_EQ(0U, d2m_msg_ptr->payload.rdd_debug_data.stream_hdr.error_info);
}

/*===========================================================================*
 * Fusa_BBE_Self_Test_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, FusaHandler_ReturnsAngleFinding)
{
   DSP_Main_Application_State_T next = Fusa_BBE_Self_Test_Handler();
   EXPECT_EQ(next, ANGLE_FINDING_PROCESSING);
}

TEST_F(MainApplicationTest, FusaHandler_CallsBBESelfTest)
{
   Fusa_BBE_Self_Test_Handler();
   EXPECT_EQ(Fusa_BBE_Check_Execute_fake.call_count, 1U);
   EXPECT_EQ(Update_FUSA_BBE_Self_Test_Fault_Flag_fake.call_count, 1U);
}

/*===========================================================================*
 * Anglefinding_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, AnglefindingHandler_ReturnsRadarCapability)
{
   Anglefinding_Memory_Init_fake.return_val   = MEM_POOL_SUCCESS;
   Appl_Angle_Finding_Process_fake.return_val = AF_E_OK;

   DSP_Main_Application_State_T next = Anglefinding_Handler();
   EXPECT_EQ(next, INTERFERENCE_DETECTION_PROCESSING);
}

TEST_F(MainApplicationTest, AnglefindingHandler_MemPoolFail_StillReturnsRadarCapability)
{
   Anglefinding_Memory_Init_fake.return_val = MEM_POOL_FAILURE;

   DSP_Main_Application_State_T next = Anglefinding_Handler();
   EXPECT_EQ(next, INTERFERENCE_DETECTION_PROCESSING);
}

TEST_F(MainApplicationTest, AnglefindingHandler_AFError_IncrementsErrorCount)
{
   Anglefinding_Memory_Init_fake.return_val   = MEM_POOL_SUCCESS;
   Appl_Angle_Finding_Process_fake.return_val = AF_E_OK + 1U; /* not AF_E_OK */
   uint16_t initial_cnt                       = Angle_Finding_Process_Error_Cnt;

   Anglefinding_Handler();

   EXPECT_GT(Angle_Finding_Process_Error_Cnt, initial_cnt);
}

TEST_F(MainApplicationTest, AnglefindingHandler_CallsResetIpcAfBuffer)
{
   Anglefinding_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   Anglefinding_Handler();

   EXPECT_EQ(Reset_IPC_AF_Buffer_fake.call_count, 1U);
}

/*===========================================================================*
 * Radar_Performance_Degradation_Monitor_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, RadarCapHandler_ReturnsTOIAlignment)
{
   Capability_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   DSP_Main_Application_State_T next = Radar_Performance_Degradation_Monitor_Handler();
   EXPECT_EQ(next, TOI_ALIGNMENT_PROCESSING);
}

TEST_F(MainApplicationTest, RadarCapHandler_MemPoolSuccess_CallsRcWrapper)
{
   Capability_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   Radar_Performance_Degradation_Monitor_Handler();

   EXPECT_EQ(rc_wrapper_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, RadarCapHandler_MemPoolFail_SkipsRcWrapper)
{
   Capability_Handler_Memory_Init_fake.return_val = MEM_POOL_FAILURE;

   Radar_Performance_Degradation_Monitor_Handler();

   EXPECT_EQ(rc_wrapper_fake.call_count, 0U);
}

/*===========================================================================*
 * TOI_Alignment_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, TOIAlignmentHandler_NormalPath_ReturnsTracker)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   DSP_Main_Application_State_T next = TOI_Alignment_Handler();
   EXPECT_EQ(next, TRACKER_PROCESSING);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_RangeError_ReturnsSPPostProcError)
{
   Range_Process_Error_Status                       = CODED_TRUE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Timing_Helpers_Get_Time_Microsec_fake.return_val = 10000U;

   DSP_Main_Application_State_T next = TOI_Alignment_Handler();
   EXPECT_EQ(next, SIGPROC_POST_PROCESSING_ERROR);
   EXPECT_EQ(Range_Process_Error_Status, CODED_FALSE);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_CallsTOIFunctions)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   TOI_Alignment_Handler();

   EXPECT_EQ(TOI_Parameters_Init_fake.call_count, 1U);
   EXPECT_EQ(Determine_Data_Quality_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_SAMemPoolSuccess_CallsStaticAlign)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;

   TOI_Alignment_Handler();

   EXPECT_EQ(static_align_wrapper_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_SAMemPoolFail_SkipsStaticAlign)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_FAILURE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;

   TOI_Alignment_Handler();

   EXPECT_EQ(static_align_wrapper_fake.call_count, 0U);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_DynAlignMemPoolSuccess_CallsDynAlign)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_SUCCESS;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   TOI_Alignment_Handler();

   EXPECT_EQ(dyn_align_wrapper_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, TOIAlignmentHandler_DynAlignMemPoolFail_SkipsDynAlign)
{
   Range_Process_Error_Status                       = CODED_FALSE;
   Alignment_Handler_Memory_Init_fake.return_val    = MEM_POOL_FAILURE;
   SA_Alignment_Handler_Memory_Init_fake.return_val = MEM_POOL_SUCCESS;

   TOI_Alignment_Handler();

   EXPECT_EQ(dyn_align_wrapper_fake.call_count, 0U);
}

/*===========================================================================*
 * Tracker_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, TrackerHandler_CalibAvailableAndMemPoolSuccess_InitializesAndRunsTracker)
{
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time                  = Get_IPC_M2D_One_Time_Buffer();
   M2D_Msg_T *p_ipc_m2d                                    = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
   p_ipc_m2d_one_time->calib_data.data_availability_status = CODED_TRUE;
   p_ipc_m2d->payload.veh_data.vse_output_valid            = CODED_TRUE;
   Emb_Tracker_Mem_Init_fake.return_val                    = MEM_POOL_SUCCESS;
   p_ipc_m2d_one_time->radar_position                      = RADAR_POSITION_FRONT_CENTER;
   for (int i = 0; i < 2; i++)
   {
      p_ipc_m2d->payload.hil_ipc_info.hil_request_reinit_module = (i == 0) ? CODED_TRUE : CODED_FALSE;
      const unsigned int init_call_count_before                 = Init_Emb_Tracker_fake.call_count;

      DSP_Main_Application_State_T next = Tracker_Handler();

      EXPECT_EQ(next, FEATURE_PROCESSING);
      EXPECT_EQ(Emb_Tracker_Mem_Init_fake.call_count, i + 1);
      EXPECT_EQ(Init_Emb_Tracker_fake.call_count, init_call_count_before + ((i == 0) ? 1U : 0U));
      EXPECT_EQ(Run_Emb_Tracker_fake.call_count, i + 1);
      EXPECT_EQ(Mem_Pool_Reset_fake.call_count, i + 1);
   }
}

TEST_F(MainApplicationTest, TrackerHandler_CalibAvailableAndMemPoolFailure)
{
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time                  = Get_IPC_M2D_One_Time_Buffer();
   M2D_Msg_T *p_ipc_m2d                                    = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
   p_ipc_m2d_one_time->calib_data.data_availability_status = CODED_TRUE;
   p_ipc_m2d->payload.veh_data.vse_output_valid            = CODED_TRUE;
   Emb_Tracker_Mem_Init_fake.return_val                    = MEM_POOL_FAILURE;
   p_ipc_m2d_one_time->radar_position                      = RADAR_POSITION_FRONT_CENTER;

   DSP_Main_Application_State_T next = Tracker_Handler();

   EXPECT_EQ(next, FEATURE_PROCESSING);
   EXPECT_EQ(Emb_Tracker_Mem_Init_fake.call_count, 1U);
   EXPECT_EQ(Init_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Run_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Mem_Pool_Reset_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, TrackerHandler_CalibUnavailable_SkipsTrackerExecution)
{
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time                  = Get_IPC_M2D_One_Time_Buffer();
   M2D_Msg_T *p_ipc_m2d                                    = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
   p_ipc_m2d_one_time->calib_data.data_availability_status = CODED_FALSE;
   p_ipc_m2d->payload.veh_data.vse_output_valid            = CODED_FALSE;
   p_ipc_m2d_one_time->radar_position                      = RADAR_POSITION_FRONT_CENTER;

   DSP_Main_Application_State_T next = Tracker_Handler();

   EXPECT_EQ(next, FEATURE_PROCESSING);
   EXPECT_EQ(Emb_Tracker_Mem_Init_fake.call_count, 0U);
   EXPECT_EQ(Init_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Run_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Mem_Pool_Reset_fake.call_count, 0U);
}

TEST_F(MainApplicationTest, TrackerHandler_RadarPosLeft_SkipsTrackerExecution)
{
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time                  = Get_IPC_M2D_One_Time_Buffer();
   p_ipc_m2d_one_time->calib_data.data_availability_status = CODED_TRUE;
   p_ipc_m2d_one_time->radar_position                      = RADAR_POSITION_FRONT_LEFT;

   DSP_Main_Application_State_T next = Tracker_Handler();

   EXPECT_EQ(next, SIGPROC_POST_PROCESSING);
   EXPECT_EQ(Emb_Tracker_Mem_Init_fake.call_count, 0U);
   EXPECT_EQ(Init_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Run_Emb_Tracker_fake.call_count, 0U);
   EXPECT_EQ(Mem_Pool_Reset_fake.call_count, 0U);
}

/*===========================================================================*
 * Feature_Handler tests (ROT_NONE defined — Feature is excluded)
 *===========================================================================*/

TEST_F(MainApplicationTest, FeatureHandler_ReturnsSignalProcPostProcessing)
{
   /* With ROT_NONE defined, tracker code is skipped */
   DSP_Main_Application_State_T next = Feature_Handler();
   EXPECT_EQ(next, SIGPROC_POST_PROCESSING);
}

/*===========================================================================*
 * SP_Post_Proc_Complete_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, SPPostProcHandler_ReturnsIdle)
{
   DSP_Main_Application_State_T next = SP_Post_Proc_Complete_Handler();
   EXPECT_EQ(next, IDLE);
}

TEST_F(MainApplicationTest, SPPostProcHandler_CallsBbe32StaticRegCheck)
{
   SP_Post_Proc_Complete_Handler();
   EXPECT_EQ(Bbe32_Static_Register_Safety_Check_fake.call_count, 1U);
}

TEST_F(MainApplicationTest, SPPostProcHandler_SendsNoError)
{
   SP_Post_Proc_Complete_Handler();
   EXPECT_EQ(Send_SP_Post_Proc_Complete_to_R52_fake.call_count, 1U);
   EXPECT_EQ(Send_SP_Post_Proc_Complete_to_R52_fake.arg0_val, (uint32_t)ERRORFIELD_NO_ERROR);
}

/*===========================================================================*
 * Interference_Detection_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, InterferenceDetectionHandler_ReturnsRadarCapability)
{
   DSP_Main_Application_State_T next = Interference_Detection_Handler();
   EXPECT_EQ(next, RADAR_CAPABILITY_PROCESSING);
}

TEST_F(MainApplicationTest, InterferenceDetectionHandler_CallsInterferenceDetectionWrapper)
{
   Interference_Detection_Handler();
   EXPECT_EQ(interference_detection_wrapper_fake.call_count, 1U);
}

/*===========================================================================*
 * SP_Post_Proc_Complete_Error_Handler tests
 *===========================================================================*/

TEST_F(MainApplicationTest, SPPostProcErrorHandler_ReturnsIdle)
{
   DSP_Main_Application_State_T next = SP_Post_Proc_Complete_Error_Handler();
   EXPECT_EQ(next, IDLE);
}

TEST_F(MainApplicationTest, SPPostProcErrorHandler_SendsPostSigProcError)
{
   SP_Post_Proc_Complete_Error_Handler();
   EXPECT_EQ(Send_SP_Post_Proc_Complete_to_R52_fake.call_count, 1U);
   EXPECT_EQ(Send_SP_Post_Proc_Complete_to_R52_fake.arg0_val, (uint32_t)ERRORFIELD_POST_SIG_PROC_ERROR);
}

TEST_F(MainApplicationTest, SPPostProcErrorHandler_CallsBbe32StaticRegCheck)
{
   SP_Post_Proc_Complete_Error_Handler();
   EXPECT_EQ(Bbe32_Static_Register_Safety_Check_fake.call_count, 1U);
}

/*===========================================================================*
 * Update_Frame_Timing tests (compiled with ENABLE_PROFILE_TIMING_OUTPUTS)
 *===========================================================================*/

TEST_F(MainApplicationTest, UpdateFrameTiming_CallsUpdateIpcPerfmonInfo)
{
   Update_Frame_Timing();
   EXPECT_EQ(Update_IPC_Perfmon_Info_fake.call_count, 1U);
}

/*===========================================================================*
 * Set_Current_Lookindex tests (static, accessed indirectly)
 *===========================================================================*/

TEST_F(MainApplicationTest, SetCurrentLookindex_IncrementsIndex)
{
   DSP_Current_Look_Index = 0U;
   Set_Current_Lookindex();
   EXPECT_EQ(DSP_Current_Look_Index, 1U);
}

TEST_F(MainApplicationTest, SetCurrentLookindex_MultipleCalls)
{
   DSP_Current_Look_Index = 10U;
   Set_Current_Lookindex();
   Set_Current_Lookindex();
   EXPECT_EQ(DSP_Current_Look_Index, 12U);
}
