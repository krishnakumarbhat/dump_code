/*===========================================================================*/
/**
 * @file Ra_fault_injection_unit_test.cc
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 * @section DESC DESCRIPTION:
 * Unit test suite for Ra_fault_injection.c module
 *
 * @section ABBR ABBREVIATIONS:
 *   - ECC: Error Correction Code
 *   - AXI: Advanced eXtensible Interface
 *   - DSP: Digital Signal Processor
 *
 */
/*===========================================================================*/

#include "fff.h"
#include <gtest/gtest.h>

// #include "ra_sfrs.h"
// #include "chandra_sfrs_base.h"

#include "reuse.h"
/*===========================================================================*
 * Unit Test Setup
 *===========================================================================*/
#define ENABLE_SQT_TEST_STUBS
#define UNIT_TEST

extern "C"
{
#include "Ra_fault_injection.h"
}

ra_fault_handler_t ra_fault_handlers[SM_MAX] = {};

extern "C"
{
#include "Ra_fault_injection.c"
#include "Ra_fault_injection_mock.h"
}

/*===========================================================================*
 * Test Fixture
 *===========================================================================*/

class RaFaultInjectionTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RA_MockReset();
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
TEST_F(RaFaultInjectionTest, SM64_Enable_DisablesFusaInterrupts1)
{
   mock_ra_regs.R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG = 0U;

   ra_sm_enable = SM_064_RA_AXI_M_IN_PARITY;

   SM_064_RA_AXI_M_IN_PARITY_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM64_Enable_DisablesFusaInterrupts2)
{
   mock_ra_regs.R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG = 1U;

   ra_sm_enable = SM_064_RA_AXI_M_IN_PARITY;

   SM_064_RA_AXI_M_IN_PARITY_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM65_Enable_DisablesFusaInterrupts1)
{
   mock_ra_regs.R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG = 0U;

   ra_sm_enable = SM_065_RA_AXI_M_OUT_PARITY;

   SM_065_RA_AXI_M_OUT_PARITY_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM65_Enable_DisablesFusaInterrupts2)
{
   mock_ra_regs.R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG = 1U;

   ra_sm_enable = SM_065_RA_AXI_M_OUT_PARITY;

   SM_065_RA_AXI_M_OUT_PARITY_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM82_Enable_DisablesErrorInterrupts1)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;

   ra_sm_enable = SM_082_RA_WWDG_IS;

   SM_082_RA_WWDG_IS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM82_Enable_DisablesErrorInterrupts2)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG = 1U;

   ra_sm_enable = SM_082_RA_WWDG_IS;

   SM_082_RA_WWDG_IS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM83_Enable_ConfiguresWdtInterrupt1)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;

   ra_sm_enable = SM_083_RA_WWDG_OS;

   SM_083_RA_WWDG_OS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM83_Enable_ConfiguresWdtInterrupt2)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG = 1U;

   ra_sm_enable = SM_083_RA_WWDG_OS;

   SM_083_RA_WWDG_OS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM84_Enable_DisablesErrorInterrupts1)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;

   ra_sm_enable = SM_084_RA_WWDG_PS;

   SM_084_RA_WWDG_PS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, SM84_Enable_DisablesErrorInterrupts2)
{
   mock_ra_regs.R52_ERR_IRQ_FLAG_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_FLAG = 1U;

   ra_sm_enable = SM_084_RA_WWDG_PS;

   SM_084_RA_WWDG_PS_Inject();

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, RA_Fault_Injection_Execute1)
{
   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_MAX, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, RA_Fault_Injection_Execute2)
{
   ra_sm_enable                         = SM_084_RA_WWDG_PS;
   ra_fault_handlers[SM_084_RA_WWDG_PS] = SM_084_RA_WWDG_PS_Inject;
   RA_Inj_Type                          = 0U;

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_084_RA_WWDG_PS, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, RA_Fault_Injection_Execute3)
{
   ra_sm_enable                         = SM_084_RA_WWDG_PS;
   ra_fault_handlers[SM_084_RA_WWDG_PS] = SM_084_RA_WWDG_PS_Inject;
   RA_Inj_Type                          = 1U;

   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_084_RA_WWDG_PS, ra_sm_enable);
}

TEST_F(RaFaultInjectionTest, RA_Fault_Injection_Execute4)
{
   ra_sm_enable                         = SM_084_RA_WWDG_PS;
   ra_fault_handlers[SM_084_RA_WWDG_PS] = SM_084_RA_WWDG_PS_Inject;

   RA_Fault_Injection_Execute();
   ra_sm_enable = SM_084_RA_WWDG_PS;

   RA_Fault_Injection_Execute();
   ra_sm_enable = SM_084_RA_WWDG_PS;

   RA_Fault_Injection_Execute();

   ra_sm_enable = SM_084_RA_WWDG_PS;
   RA_Fault_Injection_Execute();

   ra_sm_enable = SM_084_RA_WWDG_PS;
   RA_Fault_Injection_Execute();

   EXPECT_EQ(SM_084_RA_WWDG_PS, ra_sm_enable);
}
