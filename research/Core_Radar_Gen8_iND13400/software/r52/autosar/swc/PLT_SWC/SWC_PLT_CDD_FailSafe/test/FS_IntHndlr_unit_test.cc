/*===========================================================================*/
/**
 * @file FS_IntHndlr_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 *
 * Unit test suite for the FS_IntHndlr.c file
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "FS_IntHndlr_fake.h"
#include "fff.h"
#include <gtest/gtest.h>
#include <string.h>
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "FS_IntHndlr.c"
}

/*===========================================================================*
 * Test Constants
 *===========================================================================*/

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class FailsafeFusaInterruptHandler_UnitTestSuite : public testing::Test
{
 protected:
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp() override
   {
      FFF_FAKES_FUSA_HANDLER_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();
      /* Reset fake variables */
      MIPI_Err_Fusa_Counter                          = 0;
      MIPI_Chp_Fusa_Counter                          = 0;
      Retention_Ram_Data.Exception_data.reset_number = 0;

      /* Reset UNIT_TEST SYSMEM mock storage */
      (void)memset((void *)&sysmem_sfrs_ut, 0, sizeof(sysmem_sfrs_ut));
      sysmem_port0_sec_ded_stat1_ut = 0U;
      sysmem_port1_sec_ded_stat1_ut = 0U;
      sysmem0_ecc_temp              = 0U;
      sysmem1_ecc_temp              = 0U;
      r52_cee_lim_ctrl0_ut          = 0U;
      r52_cee_lim_ctrl1_ut          = 0U;
      r52_cee_cnt_stat0_ut          = 0U;
      r52_cee_cnt_stat1_ut          = 0U;
      r52_cee_snap_ctrl_ut          = 0U;
      r52_cee_irq_stat_ut           = 0U;
      r52_cee_clear_ctrl_ut         = 0U;
      (void)memset((void *)&ecc_correctable_cnts, 0, sizeof(ecc_correctable_cnts));

      (void)memset((void *)&artie_sfrs_ut, 0, sizeof(artie_sfrs_ut));

      /* Reset Reset Monitor mock registers */
      IRQ_RMON                         = 0;
      IRQ_RMON_NOMASK                  = 0;
      MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0;
      CTL_RMON                         = 0;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @b Test_ID: FailsafeFusaInterruptHandler_T1
 * @b Description:
 *    Test Case for Sanity Check
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, FailsafeFusaInterruptHandler__Config_SANITY_CHECK)
{
   /*Sanity Check*/
   ASSERT_EQ(true, true);
}

/**
 * @b Test_ID: Os_Isr_DSP_Clock_Monitor_Handler_T1
 * @b Description:
 *    Test that DSP Clock Monitor Handler calls FailSafe_Log_ResetReason
 *    with MCU_FAILSAFE_DSP_CLK_FAILURE
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_DSP_Clock_Monitor_Handler_T1)
{
   /* Act */
   Os_Isr_DSP_Clock_Monitor_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_DSP_CLK_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_RA_Clock_Monitor_Handler_T1
 * @b Description:
 *    Test that RA Clock Monitor Handler calls FailSafe_Log_ResetReason
 *    with MCU_FAILSAFE_RA_CLK_FAILURE
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_RA_Clock_Monitor_Handler_T1)
{
   /* Act */
   Os_Isr_RA_Clock_Monitor_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RA_CLK_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_MIPI_Clock_Monitor_Handler_T1
 * @b Description:
 *    Test that MIPI Clock Monitor Handler calls FailSafe_Log_ResetReason
 *    with MCU_FAILSAFE_MIPI_CLK_FAILURE
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_MIPI_Clock_Monitor_Handler_T1)
{
   /* Act */
   Os_Isr_MIPI_Clock_Monitor_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_MIPI_CLK_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Serial_Clock_Monitor_Handler_T1
 * @b Description:
 *    Test that Serial Clock Monitor Handler stores reset reason in retention RAM
 *    and calls FailSafe_Log_ResetReason with MCU_FAILSAFE_SERIAL_CLK_FAILURE
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Serial_Clock_Monitor_Handler_T1)
{
   /* Act */
   Os_Isr_Serial_Clock_Monitor_Handler();

   /* Assert - verify retention RAM is updated */
   ASSERT_EQ(Retention_Ram_Data.Exception_data.reset_number, MCU_FAILSAFE_SERIAL_CLK_FAILURE);
   /* Assert - verify FailSafe_Log_ResetReason is called */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_SERIAL_CLK_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Serial_Clock_Monitor_Handler_T2
 * @b Description:
 *    Test that Serial Clock Monitor Handler overwrites previous reset reason
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Serial_Clock_Monitor_Handler_T2)
{
   /* Arrange - set a previous reset reason */
   Retention_Ram_Data.Exception_data.reset_number = 0xFF;

   /* Act */
   Os_Isr_Serial_Clock_Monitor_Handler();

   /* Assert - verify retention RAM is updated with new value */
   ASSERT_EQ(Retention_Ram_Data.Exception_data.reset_number, MCU_FAILSAFE_SERIAL_CLK_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_BBE_SP_FUSA_IRQ_Handler_T1
 * @b Description:
 *    function coverage
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_BBE_SP_FUSA_IRQ_Handler_T1)
{
   /* Act */
   Os_Isr_BBE_SP_FUSA_IRQ_Handler();
}

/**
 * @b Test_ID: Os_Isr_RA_ERROR_IRQ_Handler_T1
 * @b Description:
 *    function coverage
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_RA_ERROR_IRQ_Handler_T1)
{
   /* Act */
   Os_Isr_RA_ERROR_IRQ_Handler();
}

/**
 * @b Test_ID: Os_Isr_RA_FUSA_IRQ_Handler_T1
 * @b Description:
 *    function coverage
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_RA_FUSA_IRQ_Handler_T1)
{
   /* Act */
   Os_Isr_RA_FUSA_IRQ_Handler();
}

/**
 * @b Test_ID: Os_Isr_Sysmem0_Fusa_Handler_T1
 * @b Description:
 *    DED sticky set: must log FAILSAFE_SM_090_SYSMEM0 and clear DED IRQ bit.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Sysmem0_Fusa_Handler_T1)
{
   /* Arrange */
   SYSMEM->IRQ_STAT0                                   = 0x00000400U; /* Port0 DED IRQ */
   SYSMEM->PORT0_SEC_DED_STAT0.f.STS_P0_ECC_DED_STICKY = 1U;
   sysmem_port0_sec_ded_stat1_ut                       = 0U;

   /* Act */
   Os_Isr_Sysmem0_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(sysmem0_ecc_temp, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, FAILSAFE_SM_090_SYSMEM0);
   ASSERT_EQ(SYSMEM->IRQ_STAT0, 0x00000400U);
}

/**
 * @b Test_ID: Os_Isr_Sysmem0_Fusa_Handler_T2
 * @b Description:
 *    SEC threshold: must clear SEC/DED IRQ bits; must not log reset reason.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Sysmem0_Fusa_Handler_T2)
{
   /* Arrange */
   SYSMEM->IRQ_STAT0                                   = 0x00000800U; /* Port0 SEC threshold IRQ */
   SYSMEM->PORT0_SEC_DED_STAT0.f.STS_P0_ECC_DED_STICKY = 0U;
   sysmem_port0_sec_ded_stat1_ut                       = 5U; /* sec_count=5 */

   /* Act */
   Os_Isr_Sysmem0_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(sysmem0_ecc_temp, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);
   ASSERT_EQ(SYSMEM->IRQ_STAT0, 0x00000C00U);
}

/**
 * @b Test_ID: Os_Isr_Sysmem1_Fusa_Handler_T1
 * @b Description:
 *    DED sticky set: must log FAILSAFE_SM_090_SYSMEM1 and clear DED IRQ bit.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Sysmem1_Fusa_Handler_T1)
{
   /* Arrange */
   SYSMEM->IRQ_STAT0                                   = 0x04000000U; /* Port1 DED IRQ */
   SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_DED_STICKY = 1U;
   sysmem_port1_sec_ded_stat1_ut                       = 0U;

   /* Act */
   Os_Isr_Sysmem1_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(sysmem1_ecc_temp, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, FAILSAFE_SM_090_SYSMEM1);
   ASSERT_EQ(SYSMEM->IRQ_STAT0, 0x04000000U);
}

/**
 * @b Test_ID: Os_Isr_Sysmem1_Fusa_Handler_T2
 * @b Description:
 *    SEC threshold: must clear SEC/DED IRQ bits; must not log reset reason.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Sysmem1_Fusa_Handler_T2)
{
   /* Arrange */
   SYSMEM->IRQ_STAT0                                   = 0x08000000U; /* Port1 SEC threshold IRQ */
   SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_DED_STICKY = 0U;
   sysmem_port1_sec_ded_stat1_ut                       = 2U; /* sec_count=2 */

   /* Act */
   Os_Isr_Sysmem1_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(sysmem1_ecc_temp, 1U);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);
   ASSERT_EQ(SYSMEM->IRQ_STAT0, 0x0C000000U);
}

/**
 * @b Test_ID: Initalize_CEE_Limit_T1
 * @b Description:
 *    Verify CEE limit init writes lower 16-bit fields to zero.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Initalize_CEE_Limit_SW_UNIT_01)
{
   /* Arrange */
   r52_cee_lim_ctrl0_ut = 0xA5A55A5AU;
   r52_cee_lim_ctrl1_ut = 0x12345678U;

   /* Act */
   Initalize_CEE_Limit();

   /* Assert */
   ASSERT_EQ(r52_cee_lim_ctrl0_ut, 0xA5A50000U);
   ASSERT_EQ(r52_cee_lim_ctrl1_ut, 0x12340000U);
}

/**
 * @b Test_ID: Monitor_AXI_S_Correctable_Errors_T1
 * @b Description:
 *    IRQ not fired: no counters/RTE updates.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Monitor_AXI_S_Correctable_Errors_SW_UNIT_01)
{
   /* Arrange */
   r52_cee_irq_stat_ut                = 0U;
   r52_cee_snap_ctrl_ut               = 0xFFFFFFFFU;
   r52_cee_clear_ctrl_ut              = 0x12340000U;
   ecc_correctable_cnts.sp_axi_s_corr = 7U;

   /* Act */
   Monitor_AXI_S_Correctable_Errors();

   /* Assert */
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_s_corr, 7U);
   ASSERT_EQ(r52_cee_snap_ctrl_ut, 0xFFFFFFFFU);
   ASSERT_EQ(r52_cee_clear_ctrl_ut, 0x12340000U);
   ASSERT_EQ(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault_fake.call_count, 0);
}

/**
 * @b Test_ID: Monitor_AXI_S_Correctable_Errors_T2
 * @b Description:
 *    IRQ fired: snapshot/read/clear path updates AXI-S counters and triggers NVM write.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Monitor_AXI_S_Correctable_Errors_SW_UNIT_02)
{
   /* Arrange */
   r52_cee_irq_stat_ut  = ERREVT_0_CEE_IRQ_FIRED;
   r52_cee_cnt_stat0_ut = 5U;

   /* Act */
   Monitor_AXI_S_Correctable_Errors();

   /* Assert */
   ASSERT_EQ((r52_cee_snap_ctrl_ut & (1U << ERREVT_0_CEE_SNAP_CTRL_BIT)), 0U);
   ASSERT_EQ(r52_cee_clear_ctrl_ut, (1U << ERREVT_0_CEE_CLEAR_CTRL_IRQ_CLR_BIT) | (1U << ERREVT_0_CEE_CLEAR_CTRL_CNT_CLR_BIT) |
                                       (1U << ERREVT_0_CEE_CLEAR_CTRL_CLR_BIT));
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_s_corr, 5U);
   ASSERT_EQ(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault_fake.call_count, 1);
}

/**
 * @b Test_ID: Monitor_AXI_M_Correctable_Errors_T1
 * @b Description:
 *    IRQ not fired: no counters/RTE updates.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Monitor_AXI_M_Correctable_Errors_SW_UNIT_01)
{
   /* Arrange */
   r52_cee_irq_stat_ut                = 0U;
   r52_cee_snap_ctrl_ut               = 0xAAAAAAAAU;
   r52_cee_clear_ctrl_ut              = 0x55550000U;
   ecc_correctable_cnts.sp_axi_m_corr = 9U;

   /* Act */
   Monitor_AXI_M_Correctable_Errors();

   /* Assert */
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_m_corr, 9U);
   ASSERT_EQ(r52_cee_snap_ctrl_ut, 0xAAAAAAAAU);
   ASSERT_EQ(r52_cee_clear_ctrl_ut, 0x55550000U);
   ASSERT_EQ(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault_fake.call_count, 0);
}

/**
 * @b Test_ID: Monitor_AXI_M_Correctable_Errors_T2
 * @b Description:
 *    IRQ fired: snapshot/read/clear path updates AXI-M counters and triggers NVM write.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Monitor_AXI_M_Correctable_Errors_SW_UNIT_02)
{
   /* Arrange */
   r52_cee_irq_stat_ut  = ERREVT0_2_CEE_IRQ_FIRED;
   r52_cee_cnt_stat1_ut = 11U;

   /* Act */
   Monitor_AXI_M_Correctable_Errors();

   /* Assert */
   ASSERT_EQ((r52_cee_snap_ctrl_ut & (1U << ERREVT0_2_CEE_SNAP_CTRL_BIT)), 0U);
   ASSERT_EQ(r52_cee_clear_ctrl_ut, (1U << ERREVT0_2_CEE_CLEAR_CTRL_IRQ_CLR_BIT) | (1U << ERREVT0_2_CEE_CLEAR_CTRL_CNT_CLR_BIT) |
                                       (1U << ERREVT0_2_CEE_CLEAR_CTRL_CLR_BIT));
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_m_corr, 11U);
   ASSERT_EQ(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault_fake.call_count, 1);
}

/**
 * @b Test_ID: Monitor_Correctable_Errors_T1
 * @b Description:
 *    Wrapper services both AXI-S and AXI-M paths.
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Monitor_Correctable_Errors_SW_UNIT_01)
{
   /* Arrange */
   r52_cee_irq_stat_ut  = ERREVT_0_CEE_IRQ_FIRED | ERREVT0_2_CEE_IRQ_FIRED;
   r52_cee_cnt_stat0_ut = 3U;
   r52_cee_cnt_stat1_ut = 4U;

   /* Act */
   Monitor_Correctable_Errors();

   /* Assert */
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_s_corr, 3U);
   ASSERT_EQ(ecc_correctable_cnts.sp_axi_m_corr, 4U);
   ASSERT_EQ(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault_fake.call_count, 2);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_RA_Fault
 * @b Description:
 *    Test that Reset Monitor Handler correctly handles RA fault (bit 0 set)
 *    Verifies IRQ_RMON is cleared via W1C and correct reset reason is logged
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_RA_Fault)
{
   /* Arrange - Set RA fault bit */
   IRQ_RMON                         = 0x00000001U; /* RA bit set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify RA fault detected and logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_RA_FAILURE);

   /* Verify IRQ_RMON W1C write used the software-serviceable mask bits [3:0]. */
   ASSERT_EQ(IRQ_RMON, 0x0000000FU);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_MIPI_Fault
 * @b Description:
 *    Test that Reset Monitor Handler correctly handles MIPI fault (bit 1 set)
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_MIPI_Fault)
{
   /* Arrange - Set MIPI fault bit */
   IRQ_RMON                         = 0x00000002U; /* MIPI bit set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify MIPI fault detected and logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_MIPI_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_DSP_Fault
 * @b Description:
 *    Test that Reset Monitor Handler correctly handles DSP fault (bit 2 set)
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_DSP_Fault)
{
   /* Arrange - Set DSP fault bit */
   IRQ_RMON                         = 0x00000004U; /* DSP bit set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify DSP fault detected and logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_DSP_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_REF_Fault
 * @b Description:
 *    Test that Reset Monitor Handler correctly handles REF fault (bit 3 set)
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_REF_Fault)
{
   /* Arrange - Set REF fault bit */
   IRQ_RMON                         = 0x00000008U; /* REF bit set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify REF fault detected and logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_REF_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_SER_Fault
 * @b Description:
 *    Test that Reset Monitor Handler correctly handles Serial fault (bit 8 of MISC0)
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_SER_Fault)
{
   /* Arrange - Set Serial fault bit */
   IRQ_RMON                         = 0x00000000U;
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000100U; /* SER bit (bit 8) set */

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify Serial fault detected and logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_SER_FAILURE);

   /* Verify MCU_SAFETY_MISC0_IRQ_MASKED_STAT was cleared (W1C) */
   ASSERT_EQ(MCU_SAFETY_MISC0_IRQ_MASKED_STAT, 0x00000100U); /* W1C: write 1 to clear */
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_Priority_RA_Over_MIPI
 * @b Description:
 *    Test that RA has priority over MIPI when both faults are active
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_Priority_RA_Over_MIPI)
{
   /* Arrange - Set both RA and MIPI fault bits */
   IRQ_RMON                         = 0x00000003U; /* RA (bit 0) + MIPI (bit 1) set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify RA fault is logged (higher priority) */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_RA_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_Priority_DSP_Over_REF
 * @b Description:
 *    Test that DSP has priority over REF when both faults are active
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_Priority_DSP_Over_REF)
{
   /* Arrange - Set both DSP and REF fault bits */
   IRQ_RMON                         = 0x0000000CU; /* DSP (bit 2) + REF (bit 3) set */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify DSP fault is logged (higher priority) */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_DSP_FAILURE);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_Spurious_No_Fault
 * @b Description:
 *    Test that spurious interrupt (no recognized fault) does not trigger reset
 *    This tests the else branch where no valid fault is detected
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_Spurious_No_Fault)
{
   /* Arrange - No fault bits set */
   IRQ_RMON                         = 0x00000000U;
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify no reset reason was logged (spurious IRQ) */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);
}

/**
 * @b Test_ID: Os_Isr_Reset_Monitor_Handler_Bit_Masking_Clears_Only_Valid_Bits
 * @b Description:
 *    Test that W1C operation only clears the valid fault bits [3:0] in IRQ_RMON
 *    and preserves other bits if accidentally set
 */
TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Reset_Monitor_Handler_Bit_Masking_Clears_Only_Valid_Bits)
{
   /* Arrange - Set RA fault + some invalid high bits */
   IRQ_RMON                         = 0xFFFF0001U; /* RA bit + high bits */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0x00000000U;

   /* Act */
   Os_Isr_Reset_Monitor_Handler();

   /* Assert - Verify RA fault was logged */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, MCU_FAILSAFE_RMON_RA_FAILURE);

   /* Verify only bits [3:0] were written for W1C, high bits not touched. */
   ASSERT_EQ(IRQ_RMON, 0x0000000FU);
}

TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Artie_Mem_Fusa_Handler_DED)
{
   /* Arrange */
   ARTIE_REGS->AMEM_IRQ_STATUS.f.AMEM_DED_IRQ_FIRED = 1U;
   ARTIE_REGS->SEC_DED_STAT.f.STS_ECC_SEC_CNT       = 0U;

   /* Act */
   Os_Isr_Artie_Mem_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, FAILSAFE_SM_05_ARTIEMEM_ECC);
}

TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Artie_Mem_Fusa_Handler_SEC)
{
   /* Arrange */
   ARTIE_REGS->AMEM_IRQ_STATUS.f.AMEM_SEC_IRQ_FIRED = 1U;
   ARTIE_REGS->SEC_DED_STAT.f.STS_ECC_SEC_CNT       = 3U;

   /* Act */
   Os_Isr_Artie_Mem_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);

   /* IRQ clear expected */
   ASSERT_EQ(ARTIE_REGS->AMEM_IRQ_CLR.r, 0x3F);
}

TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, Os_Isr_Artie_Mem_Fusa_Handler_No_Event)
{
   /* Arrange */
   ARTIE_REGS->AMEM_IRQ_STATUS.r = 0U;

   /* Act */
   Os_Isr_Artie_Mem_Fusa_Handler();

   /* Assert */
   ASSERT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);
}

TEST_F(FailsafeFusaInterruptHandler_UnitTestSuite, RA_R52_Failure_State_Get_Set)
{
   Get_RA_R52_ERROR_Failure_State();
   Get_RA_R52_FUSA_Failure_State();
   Set_RA_R52_ERROR_Failure_State(0);
   Set_RA_R52_FUSA_Failure_State(0);
}

/*===========================================================================*
 * End of test suite
 *===========================================================================*/
