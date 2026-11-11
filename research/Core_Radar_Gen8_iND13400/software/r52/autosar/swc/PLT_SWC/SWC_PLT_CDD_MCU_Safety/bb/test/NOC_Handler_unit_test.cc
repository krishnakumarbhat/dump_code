/*===========================================================================*/
/**
 * @file NOC_Handler_unit_test.cc
 *
 * Unit tests for NOC handler register programming and latent-fault ISR paths.
 */
/*===========================================================================*/

#include <gtest/gtest.h>

#include "fff.h"
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test/FailSafe_callout_fake.h"

DEFINE_FFF_GLOBALS;

/* Mock hardware registers used by NOC_Handler.c */
volatile uint32_t mock_sticky_diag_ctrl0 = 0U;
volatile uint32_t mock_sticky_diag_ctrl1 = 0U;
volatile uint32_t mock_sticky_diag_ctrl2 = 0U;

volatile uint32_t mock_chandra_noc_clear = 0U;
volatile uint32_t mock_small_noc_clear   = 0U;
volatile uint32_t mock_artie_noc_clear   = 0U;

volatile uint32_t mock_chandra_noc_bist_control = 0U;
volatile uint32_t mock_small_noc_bist_control   = 0U;
volatile uint32_t mock_artie_noc_bist_control   = 0U;

volatile uint32_t mock_chandra_noc_bist_start = 0U;
volatile uint32_t mock_small_noc_bist_start   = 0U;
volatile uint32_t mock_artie_noc_bist_start   = 0U;

volatile uint32_t mock_chandra_noc_bist_status = 0U;
volatile uint32_t mock_small_noc_bist_status   = 0U;
volatile uint32_t mock_artie_noc_bist_status   = 0U;

volatile uint32_t mock_chandra_noc_latent_fault0 = 0U;
volatile uint32_t mock_chandra_noc_latent_fault1 = 0U;
volatile uint32_t mock_chandra_noc_latent_fault2 = 0U;
volatile uint32_t mock_chandra_noc_latent_fault3 = 0U;

volatile uint32_t mock_small_noc_latent_fault0 = 0U;
volatile uint32_t mock_small_noc_latent_fault1 = 0U;
volatile uint32_t mock_small_noc_latent_fault2 = 0U;
volatile uint32_t mock_small_noc_latent_fault3 = 0U;

volatile uint32_t mock_artie_noc_latent_fault0 = 0U;
volatile uint32_t mock_artie_noc_latent_fault1 = 0U;
volatile uint32_t mock_artie_noc_latent_fault2 = 0U;
volatile uint32_t mock_artie_noc_latent_fault3 = 0U;

extern "C"
{
#include "NOC_Handler.h"
}

/* Rebind address macros to mock registers for host-side unit testing. */
#undef STICKY_DIAG_CTRL0_ADDR
#undef STICKY_DIAG_CTRL1_ADDR
#undef STICKY_DIAG_CTRL2_ADDR
#undef CHANDRA_NOC_CLEAR_ADDR
#undef SMALL_NOC_CLEAR_ADDR
#undef ARTIE_NOC_CLEAR_ADDR
#undef CHANDRA_NOC_BIST_CONTROL_ADDR
#undef SMALL_NOC_BIST_CONTROL_ADDR
#undef ARTIE_NOC_BIST_CONTROL_ADDR
#undef CHANDRA_NOC_BIST_START_ADDR
#undef SMALL_NOC_BIST_START_ADDR
#undef ARTIE_NOC_BIST_START_ADDR
#undef CHANDRA_NOC_BIST_STATUS_ADDR
#undef SMALL_NOC_BIST_STATUS_ADDR
#undef ARTIE_NOC_BIST_STATUS_ADDR
#undef CHANDRA_NOC_LATENT_COM_FAULT_00_ADDR
#undef CHANDRA_NOC_LATENT_COM_FAULT_01_ADDR
#undef CHANDRA_NOC_LATENT_COM_FAULT_02_ADDR
#undef CHANDRA_NOC_LATENT_COM_FAULT_03_ADDR
#undef SMALL_NOC_LATENT_COM_FAULT_00_ADDR
#undef SMALL_NOC_LATENT_COM_FAULT_01_ADDR
#undef SMALL_NOC_LATENT_COM_FAULT_02_ADDR
#undef SMALL_NOC_LATENT_COM_FAULT_03_ADDR
#undef ARTIE_NOC_LATENT_COM_FAULT_00_ADDR
#undef ARTIE_NOC_LATENT_COM_FAULT_01_ADDR
#undef ARTIE_NOC_LATENT_COM_FAULT_02_ADDR
#undef ARTIE_NOC_LATENT_COM_FAULT_03_ADDR

#define STICKY_DIAG_CTRL0_ADDR               mock_sticky_diag_ctrl0
#define STICKY_DIAG_CTRL1_ADDR               mock_sticky_diag_ctrl1
#define STICKY_DIAG_CTRL2_ADDR               mock_sticky_diag_ctrl2
#define CHANDRA_NOC_CLEAR_ADDR               mock_chandra_noc_clear
#define SMALL_NOC_CLEAR_ADDR                 mock_small_noc_clear
#define ARTIE_NOC_CLEAR_ADDR                 mock_artie_noc_clear
#define CHANDRA_NOC_BIST_CONTROL_ADDR        mock_chandra_noc_bist_control
#define SMALL_NOC_BIST_CONTROL_ADDR          mock_small_noc_bist_control
#define ARTIE_NOC_BIST_CONTROL_ADDR          mock_artie_noc_bist_control
#define CHANDRA_NOC_BIST_START_ADDR          mock_chandra_noc_bist_start
#define SMALL_NOC_BIST_START_ADDR            mock_small_noc_bist_start
#define ARTIE_NOC_BIST_START_ADDR            mock_artie_noc_bist_start
#define CHANDRA_NOC_BIST_STATUS_ADDR         mock_chandra_noc_bist_status
#define SMALL_NOC_BIST_STATUS_ADDR           mock_small_noc_bist_status
#define ARTIE_NOC_BIST_STATUS_ADDR           mock_artie_noc_bist_status
#define CHANDRA_NOC_LATENT_COM_FAULT_00_ADDR mock_chandra_noc_latent_fault0
#define CHANDRA_NOC_LATENT_COM_FAULT_01_ADDR mock_chandra_noc_latent_fault1
#define CHANDRA_NOC_LATENT_COM_FAULT_02_ADDR mock_chandra_noc_latent_fault2
#define CHANDRA_NOC_LATENT_COM_FAULT_03_ADDR mock_chandra_noc_latent_fault3
#define SMALL_NOC_LATENT_COM_FAULT_00_ADDR   mock_small_noc_latent_fault0
#define SMALL_NOC_LATENT_COM_FAULT_01_ADDR   mock_small_noc_latent_fault1
#define SMALL_NOC_LATENT_COM_FAULT_02_ADDR   mock_small_noc_latent_fault2
#define SMALL_NOC_LATENT_COM_FAULT_03_ADDR   mock_small_noc_latent_fault3
#define ARTIE_NOC_LATENT_COM_FAULT_00_ADDR   mock_artie_noc_latent_fault0
#define ARTIE_NOC_LATENT_COM_FAULT_01_ADDR   mock_artie_noc_latent_fault1
#define ARTIE_NOC_LATENT_COM_FAULT_02_ADDR   mock_artie_noc_latent_fault2
#define ARTIE_NOC_LATENT_COM_FAULT_03_ADDR   mock_artie_noc_latent_fault3

static uint32_t g_log_call_count             = 0U;
static uint16 g_last_resnum                  = 0U;
static Dt_NOC_Fault_Info_T g_last_fault_info = {0U};

extern "C"
{
#include "NOC_Handler.c"

   void Log_NOCLatentIntFault_Info(Dt_NOC_Fault_Info_T *NOCFault_Context, uint16 Resnum)
   {
      g_log_call_count++;
      g_last_resnum = Resnum;
      if (NOCFault_Context != NULL_PTR)
      {
         g_last_fault_info = *NOCFault_Context;
      }
   }
}

class NOC_Handler_UnitTestSuite : public testing::Test
{
 protected:
   static constexpr uint32_t kSeedControlValue = 0x00FF00FFU;
   static constexpr uint32_t kNonFailStatus    = 0U;
   static constexpr uint32_t kFailStatus       = NOC_BIST_FAILED_BIT;
   static constexpr uint32_t kFault0Value      = 0x11U;
   static constexpr uint32_t kFault1Value      = 0x22U;
   static constexpr uint32_t kFault2Value      = 0x33U;
   static constexpr uint32_t kFault3Value      = 0x44U;

   void SetUp() override
   {
      RESET_FAKE(FailSafe_Log_ResetReason);
      FFF_RESET_HISTORY();

      mock_sticky_diag_ctrl0 = 0U;
      mock_sticky_diag_ctrl1 = 0U;
      mock_sticky_diag_ctrl2 = 0U;

      mock_chandra_noc_clear = 0U;
      mock_small_noc_clear   = 0U;
      mock_artie_noc_clear   = 0U;

      mock_chandra_noc_bist_control = kSeedControlValue;
      mock_small_noc_bist_control   = kSeedControlValue;
      mock_artie_noc_bist_control   = kSeedControlValue;

      mock_chandra_noc_bist_start = 0U;
      mock_small_noc_bist_start   = 0U;
      mock_artie_noc_bist_start   = 0U;

      mock_chandra_noc_bist_status = kNonFailStatus;
      mock_small_noc_bist_status   = kNonFailStatus;
      mock_artie_noc_bist_status   = kNonFailStatus;

      mock_chandra_noc_latent_fault0 = 0U;
      mock_chandra_noc_latent_fault1 = 0U;
      mock_chandra_noc_latent_fault2 = 0U;
      mock_chandra_noc_latent_fault3 = 0U;

      mock_small_noc_latent_fault0 = 0U;
      mock_small_noc_latent_fault1 = 0U;
      mock_small_noc_latent_fault2 = 0U;
      mock_small_noc_latent_fault3 = 0U;

      mock_artie_noc_latent_fault0 = 0U;
      mock_artie_noc_latent_fault1 = 0U;
      mock_artie_noc_latent_fault2 = 0U;
      mock_artie_noc_latent_fault3 = 0U;

      g_log_call_count  = 0U;
      g_last_resnum     = 0U;
      g_last_fault_info = {0U};
   }
};

TEST_F(NOC_Handler_UnitTestSuite, Clear_StickyDiag_MissionFault_registers_Testcase1)
{
   Clear_StickyDiag_MissionFault_registers();

   ASSERT_EQ(mock_sticky_diag_ctrl0, STICKY_DIAG_CLEAR_ALL_BITS);
   ASSERT_EQ(mock_sticky_diag_ctrl1, STICKY_DIAG_CLEAR_ALL_BITS);
   ASSERT_EQ(mock_sticky_diag_ctrl2, STICKY_DIAG_CLEAR_ALL_BITS);
   ASSERT_EQ(mock_chandra_noc_clear, NOC_MISSION_CLEAR_BIT);
   ASSERT_EQ(mock_small_noc_clear, NOC_MISSION_CLEAR_BIT);
   ASSERT_EQ(mock_artie_noc_clear, NOC_MISSION_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Run_Bist_Chandra_Testcase1)
{
   Os_Isr_CNOC_Latent_Fusa_Handler();

   NOC_Run_Bist_Chandra();

   ASSERT_EQ(mock_chandra_noc_bist_control, (kSeedControlValue | NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_chandra_noc_bist_start, BIST_START_VALUE);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Run_Bist_Small_Testcase1)
{
   NOC_Run_Bist_Small();

   ASSERT_EQ(mock_small_noc_bist_control, (kSeedControlValue | NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_small_noc_bist_start, BIST_START_VALUE);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Run_Bist_Artie_Testcase1)
{
   NOC_Run_Bist_Artie();

   ASSERT_EQ(mock_artie_noc_bist_control, (kSeedControlValue | NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_artie_noc_bist_start, BIST_START_VALUE);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_CNOC_Latent_Fusa_Handler_Testcase1)
{
   NOC_Run_Bist_Chandra();
   mock_chandra_noc_bist_status = kNonFailStatus;

   Os_Isr_CNOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
   ASSERT_EQ(mock_chandra_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_chandra_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_CNOC_Latent_Fusa_Handler_Testcase2)
{
   NOC_Run_Bist_Chandra();
   mock_chandra_noc_bist_status   = kFailStatus;
   mock_chandra_noc_latent_fault0 = kFault0Value;
   mock_chandra_noc_latent_fault1 = kFault1Value;
   mock_chandra_noc_latent_fault2 = kFault2Value;
   mock_chandra_noc_latent_fault3 = kFault3Value;

   Os_Isr_CNOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
   ASSERT_EQ(mock_chandra_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_chandra_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_ANOC_Latent_Fusa_Handler_Testcase1)
{
   NOC_Run_Bist_Artie();
   mock_artie_noc_bist_status = kNonFailStatus;

   Os_Isr_ANOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
   ASSERT_EQ(mock_artie_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_artie_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_ANOC_Latent_Fusa_Handler_Testcase2)
{
   NOC_Run_Bist_Artie();
   mock_artie_noc_bist_status   = kFailStatus;
   mock_artie_noc_latent_fault0 = kFault0Value;
   mock_artie_noc_latent_fault1 = kFault1Value;
   mock_artie_noc_latent_fault2 = kFault2Value;
   mock_artie_noc_latent_fault3 = kFault3Value;

   Os_Isr_ANOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
   ASSERT_EQ(mock_artie_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_artie_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_SNOC_Latent_Fusa_Handler_Testcase1)
{
   NOC_Run_Bist_Small();
   mock_small_noc_bist_status = kNonFailStatus;

   Os_Isr_SNOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
   ASSERT_EQ(mock_small_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_small_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_SNOC_Latent_Fusa_Handler_Testcase2)
{
   NOC_Run_Bist_Small();
   mock_small_noc_bist_status   = kFailStatus;
   mock_small_noc_latent_fault0 = kFault0Value;
   mock_small_noc_latent_fault1 = kFault1Value;
   mock_small_noc_latent_fault2 = kFault2Value;
   mock_small_noc_latent_fault3 = kFault3Value;

   Os_Isr_SNOC_Latent_Fusa_Handler();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
   ASSERT_EQ(mock_small_noc_bist_control, (kSeedControlValue & ~NOC_BIST_AUTOMISSION_BIT));
   ASSERT_EQ(mock_small_noc_clear, NOC_BIST_CLEAR_BIT);
}

TEST_F(NOC_Handler_UnitTestSuite, Os_Isr_ANOC_Latent_Fusa_Handler_Testcase3)
{
   NOC_Run_Bist_Chandra();
   NOC_Run_Bist_Artie();
   NOC_Run_Bist_Small();

   Os_Isr_ANOC_Latent_Fusa_Handler();
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Chandra_LatentIsr_Execution_Testcase1)
{
   NOC_Run_Bist_Chandra();

   mock_chandra_noc_latent_fault0 = kFault0Value;
   mock_chandra_noc_latent_fault1 = kFault1Value;
   mock_chandra_noc_latent_fault2 = kFault2Value;
   mock_chandra_noc_latent_fault3 = kFault3Value;

   NOC_Verify_Chandra_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Chandra_LatentIsr_Execution_Testcase2)
{
   NOC_Run_Bist_Chandra();
   Os_Isr_CNOC_Latent_Fusa_Handler();

   g_log_call_count = 0U;
   RESET_FAKE(FailSafe_Log_ResetReason);

   NOC_Verify_Chandra_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Artie_LatentIsr_Execution_Testcase1)
{
   NOC_Run_Bist_Artie();

   mock_artie_noc_latent_fault0 = kFault0Value;
   mock_artie_noc_latent_fault1 = kFault1Value;
   mock_artie_noc_latent_fault2 = kFault2Value;
   mock_artie_noc_latent_fault3 = kFault3Value;

   NOC_Verify_Artie_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Artie_LatentIsr_Execution_Testcase2)
{
   NOC_Run_Bist_Artie();
   Os_Isr_ANOC_Latent_Fusa_Handler();

   g_log_call_count = 0U;
   RESET_FAKE(FailSafe_Log_ResetReason);

   NOC_Verify_Artie_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Small_LatentIsr_Execution_Testcase1)
{
   NOC_Run_Bist_Small();

   mock_small_noc_latent_fault0 = kFault0Value;
   mock_small_noc_latent_fault1 = kFault1Value;
   mock_small_noc_latent_fault2 = kFault2Value;
   mock_small_noc_latent_fault3 = kFault3Value;

   NOC_Verify_Small_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 1U);
   ASSERT_EQ(g_last_resnum, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
   ASSERT_EQ(g_last_fault_info.LatentFault0, kFault0Value);
   ASSERT_EQ(g_last_fault_info.LatentFault1, kFault1Value);
   ASSERT_EQ(g_last_fault_info.LatentFault2, kFault2Value);
   ASSERT_EQ(g_last_fault_info.LatentFault3, kFault3Value);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
}

TEST_F(NOC_Handler_UnitTestSuite, NOC_Verify_Small_LatentIsr_Execution_Testcase2)
{
   NOC_Run_Bist_Small();
   Os_Isr_SNOC_Latent_Fusa_Handler();

   g_log_call_count = 0U;
   RESET_FAKE(FailSafe_Log_ResetReason);

   NOC_Verify_Small_LatentIsr_Execution();

   ASSERT_EQ(g_log_call_count, 0U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0U);
}
