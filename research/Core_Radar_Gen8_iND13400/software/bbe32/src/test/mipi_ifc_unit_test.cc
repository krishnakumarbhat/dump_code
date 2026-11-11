/*===========================================================================*/
/**
 * @file mipi_ifc_unit_test.cc
 *
 * Unit tests for software/bbe32/src/mipi_ifc.c
 *
 * Testable public functions:
 *   - Appl_MIPI_One_Time_Init()        — one-time MIPI initialization
 *   - Get_MIPI_Chirp_End_Timestamp()   — returns chirp end timestamp
 *   - Get_MIPI_Chirp_Count()           — returns chirp callback count
 *   - Appl_IDM_Stat_Init()             — allocates feed forward memory
 *   - Appl_Mipi_Idm_Config()           — configures IDM per look
 *   - Appl_IDM_Stat_Process()          — processes IDM statistics
 *   - Mipi_Chirp_End_IRQ_Handler()     — chirp end interrupt handler
 */
/*==========================================================================*/
#include <gtest/gtest.h>

#include "core_macros_fff.h"
#include "mipi_ifc_fake.h"

extern "C"
{
#include "mipi_ifc.c"
}

/*===========================================================================*
 * Test fixture
 *===========================================================================*/
class MipiIfcTest : public ::testing::Test
{
 protected:
   static constexpr uint32_t kExcisionWcmemIndex = 0x1800U / sizeof(uint32_t);
   D2M_Msg_T m_rp_d2m_buf                        = {};

   static uint32_t PackExcisionRatio(uint32_t ratio)
   {
      return ratio | (ratio << 16U);
   }

   void ResetIrqState()
   {
      memset((void *)&MIPI_IFC_Internal_Data, 0, sizeof(MIPI_IFC_Internal_Data));
      memset(g_ra_reg_space_stub, 0, sizeof(g_ra_reg_space_stub));
      memset(g_mipi_stat_mem_stub, 0, sizeof(g_mipi_stat_mem_stub));
      memset(g_ra_mem_stub, 0, sizeof(g_ra_mem_stub));
      MIPI_IFC_Internal_Data.frame_size             = M_FRAME[RADAR_LOOK_A];
      MIPI_IFC_Internal_Data.fddt_scaled_frame_size = (uint32_t)MIPI_IFC_Internal_Data.frame_size * FDDT_EXCISION_BASE_RATIO;
   }

   void ExpectMappedRatio(uint32_t max_excision, uint32_t expected_ratio)
   {
      ResetIrqState();
      g_mipi_stat_mem_stub[0] = max_excision;
      g_mipi_stat_mem_stub[2] = max_excision > 0U ? (max_excision - 1U) : 0U;
      g_mipi_stat_mem_stub[4] = max_excision > 1U ? (max_excision - 2U) : 0U;
      g_mipi_stat_mem_stub[6] = max_excision > 2U ? (max_excision - 3U) : 0U;

      Mipi_Chirp_End_IRQ_Handler(NULL);

      EXPECT_EQ(g_ra_mem_stub[kExcisionWcmemIndex], PackExcisionRatio(expected_ratio));
   }

   void SetUp() override
   {
      FFF_FAKES_CORE_MACROS(RESET_FAKE);
      RESET_FAKE(Get_RP_IPC_D2M_Msg_Buffer);
      RESET_FAKE(Mipi_Helpers_Idm_Config_Ch0);
      RESET_FAKE(Mipi_Helpers_Idm_Config_Ch1);
      RESET_FAKE(Mipi_Helpers_Idm_Config_Ch2);
      RESET_FAKE(Mipi_Helpers_Idm_Config_Ch3);
      RESET_FAKE(Mipi_Clear_Idm_Stats);
      RESET_FAKE(Mipi_Helpers_Clear_Chirp_End_Flag);
      RESET_FAKE(Mipi_Helpers_Chirp_End_IRQ_Enable);
      RESET_FAKE(Mipi_Read_Idm_Stats);
      RESET_FAKE(Appl_Range_Process_Push_Ra_Commands);
      RESET_FAKE(Timing_Helpers_Get_Timestamp);
      RESET_FAKE(Timing_Helpers_Get_Time_Nanosec);
      RESET_FAKE(xtos_interrupt_clear);
      RESET_FAKE(vector_copy_unaligned);
      FFF_RESET_HISTORY();

      memset(&m_rp_d2m_buf, 0, sizeof(m_rp_d2m_buf));
      Get_RP_IPC_D2M_Msg_Buffer_fake.return_val = reinterpret_cast<volatile D2M_Msg_T *>(&m_rp_d2m_buf);
      Offline_Mode_Flag_DSP                     = 0U;

      /* Reset MIPI internal data */
      ResetIrqState();
   }
};

/*===========================================================================*
 * Appl_MIPI_One_Time_Init tests
 *===========================================================================*/

/* Verify one-time init registers interrupt handler */
TEST_F(MipiIfcTest, OneTimeInit_RegistersInterruptHandler)
{
   Appl_MIPI_One_Time_Init();
   EXPECT_EQ(xtos_set_interrupt_handler_fake.call_count, 1U);
}

/*===========================================================================*
 * Get_MIPI_Chirp_End_Timestamp tests
 *===========================================================================*/

/* Verify initial timestamp is zero */
TEST_F(MipiIfcTest, GetChirpEndTimestamp_InitiallyZero)
{
   EXPECT_EQ(Get_MIPI_Chirp_End_Timestamp(0), 0U);
}

/* Verify timestamp is updated after IRQ handler */
TEST_F(MipiIfcTest, GetChirpEndTimestamp_UpdatedAfterIRQ)
{
   Timing_Helpers_Get_Timestamp_fake.return_val = 12345U;
   Mipi_Chirp_End_IRQ_Handler(NULL);
   EXPECT_EQ(Get_MIPI_Chirp_End_Timestamp(0), 12345U);
}

/*===========================================================================*
 * Get_MIPI_Chirp_Count tests
 *===========================================================================*/

/* Verify initial chirp count is zero */
TEST_F(MipiIfcTest, GetChirpCount_InitiallyZero)
{
   EXPECT_EQ(Get_MIPI_Chirp_Count(), 0U);
}

/* Verify chirp count increments on IRQ */
TEST_F(MipiIfcTest, GetChirpCount_IncrementsOnIRQ)
{
   Mipi_Chirp_End_IRQ_Handler(NULL);
   EXPECT_EQ(Get_MIPI_Chirp_Count(), 1U);
   Mipi_Chirp_End_IRQ_Handler(NULL);
   EXPECT_EQ(Get_MIPI_Chirp_Count(), 2U);
}

/*===========================================================================*
 * Appl_Mipi_Idm_Config tests
 *===========================================================================*/

/* Verify IDM config calls all 4 channel config helpers */
TEST_F(MipiIfcTest, IdmConfig_CallsAllChannelHelpers)
{
   Appl_Mipi_Idm_Config(RADAR_LOOK_A);
   EXPECT_EQ(Mipi_Helpers_Idm_Config_Ch0_fake.call_count, 1U);
   EXPECT_EQ(Mipi_Helpers_Idm_Config_Ch1_fake.call_count, 1U);
   EXPECT_EQ(Mipi_Helpers_Idm_Config_Ch2_fake.call_count, 1U);
   EXPECT_EQ(Mipi_Helpers_Idm_Config_Ch3_fake.call_count, 1U);
}

/* Verify IDM config clears stats and enables chirp end IRQ */
TEST_F(MipiIfcTest, IdmConfig_ClearsStatsAndEnablesIRQ)
{
   Appl_Mipi_Idm_Config(RADAR_LOOK_A);
   EXPECT_EQ(Mipi_Clear_Idm_Stats_fake.call_count, 1U);
   EXPECT_EQ(Mipi_Helpers_Chirp_End_IRQ_Enable_fake.call_count, 1U);
   EXPECT_EQ(xtos_interrupt_enable_fake.call_count, 1U);
}

/* Verify IDM config resets chirp callback count */
TEST_F(MipiIfcTest, IdmConfig_ResetsChirpCallbackCount)
{
   MIPI_IFC_Internal_Data.chirp_callback_cnt = 42U;
   Appl_Mipi_Idm_Config(RADAR_LOOK_A);
   EXPECT_EQ(MIPI_IFC_Internal_Data.chirp_callback_cnt, 0U);
}

/*===========================================================================*
 * Mipi_Chirp_End_IRQ_Handler tests
 *===========================================================================*/

/* Verify IRQ handler pushes RA commands to the command queue */
TEST_F(MipiIfcTest, ChirpEndIRQ_PushesRaCommands)
{
   Mipi_Chirp_End_IRQ_Handler(NULL);
   EXPECT_EQ(Appl_Range_Process_Push_Ra_Commands_fake.call_count, 1U);
}

/* Verify IRQ handler clears the chirp-done interrupt */
TEST_F(MipiIfcTest, ChirpEndIRQ_ClearsInterrupt)
{
   Mipi_Chirp_End_IRQ_Handler(NULL);
   EXPECT_EQ(xtos_interrupt_clear_fake.call_count, 1U);
}

/* Verify IRQ handler maps zero excision to the base ratio */
TEST_F(MipiIfcTest, ChirpEndIRQ_ZeroExcision_UsesBaseRatio)
{
   ExpectMappedRatio(0U, 2048U);
}

/* Verify IRQ handler uses scaled division below half-frame excision */
TEST_F(MipiIfcTest, ChirpEndIRQ_BelowHalfFrame_UsesScaledRatio)
{
   ExpectMappedRatio(64U, 2730U);
}

/* Verify IRQ handler doubles the ratio at half-frame excision */
TEST_F(MipiIfcTest, ChirpEndIRQ_HalfFrame_UsesDoubleRatio)
{
   ExpectMappedRatio(128U, 2048U * 2U);
}

/* Verify IRQ handler increases to 4x when 64 samples remain */
TEST_F(MipiIfcTest, ChirpEndIRQ_QuarterFrameRemaining_UsesQuadRatio)
{
   ExpectMappedRatio(192U, 2048U * 4U);
}

/* Verify IRQ handler returns the saturation fallback at full-frame excision */
TEST_F(MipiIfcTest, ChirpEndIRQ_FullFrameExcision_UsesSaturatedRatio)
{
   ExpectMappedRatio(256U, 0xFFFFU);
}

/* Verify IRQ handler preserves the current wrapped-denominator behavior above frame size */
TEST_F(MipiIfcTest, ChirpEndIRQ_AboveFrameExcision_UsesCurrentRatio)
{
   ExpectMappedRatio(300U, 8U);
}

/* Verify offline injection mode overrides the measured excision count */
TEST_F(MipiIfcTest, ChirpEndIRQ_OfflineInjection_OverridesMeasuredExcision)
{
   ResetIrqState();
   Offline_Mode_Flag_DSP        = ITF_ADC_INJECTION_MODE;
   max_excision_count_injection = 123U;
   g_mipi_stat_mem_stub[0]      = 950U;

   Mipi_Chirp_End_IRQ_Handler(NULL);

   EXPECT_EQ(g_ra_mem_stub[kExcisionWcmemIndex], PackExcisionRatio(3942U));
}

/*===========================================================================*
 * Appl_IDM_Stat_Process tests
 *===========================================================================*/

/* Verify stat process disables chirp done interrupt */
TEST_F(MipiIfcTest, StatProcess_DisablesChirpDoneIRQ)
{
   Appl_IDM_Stat_Process(RADAR_LOOK_A);
   EXPECT_EQ(xtos_interrupt_disable_fake.call_count, 1U);
}

/* Verify stat process reads IDM stats */
TEST_F(MipiIfcTest, StatProcess_ReadsIdmStats)
{
   Appl_IDM_Stat_Process(RADAR_LOOK_A);
   EXPECT_EQ(Mipi_Read_Idm_Stats_fake.call_count, 1U);
}
