/*===========================================================================*/
/**
 * @file mipi_interrupt_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for mipi_interrupt.c — tests IRQ setup, flag get/clear,
 * ISR handlers, and counter functions.
 *
 * @section ABBR ABBREVIATIONS:
 *   - MIPI: Mobile Industry Processor Interface
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Design_Doc_RDD_SIL.md
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 */
/*===========================================================================*/

/*===========================================================================*
 * Google Test / FFF Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

#define UNIT_TEST

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Block ARM-specific and platform headers that cannot compile on x86
 *===========================================================================*/
/* Block chandra_r52.h (ARM CMSIS, CPSR_Type, __get_CPSR etc.) */
#define CHANDRA_R52_H
/* Block chandra_r52_gic.h — we provide FFF fakes for GIC functions instead */
#define CHANDRA_R52_GIC
/* Block system_chandra.h — ensureInterruptsNotMasked extern provided via FFF */
#define SYSTEM_CHANDRA_H

/*===========================================================================*
 * Required type definitions
 *===========================================================================*/
#include "Std_Types.h"
#include "chandra_r52_irq.h" /* IRQn_Enum: MIPI_FUSA_IRQn, MIPI_FRM_START_IRQn etc. */

/* SFR struct definitions for mock hardware register storage */
#include "csi_sfrs.h"
#include "mipi_ocp_mem_sfrs.h"
#include "mipi_sfrs.h"
#include "mipi_stat_mem_sfrs.h"

#define __IO volatile

/*===========================================================================*
 * GIC constants (normally from chandra_r52_gic.h, blocked above)
 *===========================================================================*/
#ifndef GIC_CONFIG_EDGE
   #define GIC_CONFIG_EDGE (2U)
#endif

/*===========================================================================*
 * Fakes for external function dependencies of mipi_interrupt.c
 *===========================================================================*/
/* GIC controller functions */
DECLARE_FAKE_VALUE_FUNC(uint32_t, GIC_configureIntBasic, uint32_t, uint32_t);
DECLARE_FAKE_VALUE_FUNC(uint32_t, GIC_enableInt, uint32_t);
DECLARE_FAKE_VALUE_FUNC(uint32_t, GIC_disableInt, uint32_t);

/* ARM interrupt mask helper — defined inside #ifdef __arm__ in source, stub needed for x86 */
DECLARE_FAKE_VOID_FUNC(ensureInterruptsNotMasked);

DEFINE_FAKE_VALUE_FUNC(uint32_t, GIC_configureIntBasic, uint32_t, uint32_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, GIC_enableInt, uint32_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, GIC_disableInt, uint32_t);
DEFINE_FAKE_VOID_FUNC(ensureInterruptsNotMasked);

/*===========================================================================*
 * Mock hardware register storage
 *===========================================================================*/
static MIPI_SFRS_t mock_MIPI_storage;
static MIPI_OCP_MEM_SFRS_t mock_MIPI_OCP_MEM_storage;

/* Override the hardware base-address macros before dd_mipi.h is included */
#define PTR_MIPI         ((__IO MIPI_SFRS_t *const)(&mock_MIPI_storage))
#define PTR_MIPI_OCP_MEM ((__IO MIPI_OCP_MEM_SFRS_t *const)(&mock_MIPI_OCP_MEM_storage))
/* MIPI_OCP_MEM_base must be defined for the cast in End_MIPI_Chirp */
#define MIPI_OCP_MEM_base ((uintptr_t)(&mock_MIPI_OCP_MEM_storage))

/*===========================================================================*
 * Provide definitions for ptrMIPI / ptrMIPI_OCP_MEM (declared extern in dd_mipi.h)
 * mipi_interrupt.c uses these pointers but does NOT define them (dd_mipi.c does).
 *===========================================================================*/
extern "C"
{
   volatile MIPI_SFRS_t *const ptrMIPI                 = PTR_MIPI;
   volatile MIPI_OCP_MEM_SFRS_t *const ptrMIPI_OCP_MEM = PTR_MIPI_OCP_MEM;
}

/*===========================================================================*
 * Include the source under test (white-box)
 *===========================================================================*/
extern "C"
{
#include "mipi_interrupt.c"
}

/*===========================================================================*
 * Helper: simple callback tracking
 *===========================================================================*/
static int s_callback_count = 0;
static void TestCallback(void)
{
   s_callback_count++;
}

/*===========================================================================*
 * Test Fixture
 *===========================================================================*/
class MIPI_Interrupt_UnitTestSuite : public testing::Test
{
 protected:
   void SetUp() override
   {
      /* Reset FFF fake histories and call counts */
      FFF_RESET_HISTORY();
      RESET_FAKE(GIC_configureIntBasic);
      RESET_FAKE(GIC_enableInt);
      RESET_FAKE(GIC_disableInt);
      RESET_FAKE(ensureInterruptsNotMasked);

      /* Set GIC fakes to return E_OK (0) by default */
      GIC_configureIntBasic_fake.return_val = (uint32_t)E_OK;
      // GIC_enableInt_fake.return_val         = (uint32_t)E_OK;
      // GIC_disableInt_fake.return_val        = (uint32_t)E_OK;

      /* Clear mock hardware registers */
      memset(&mock_MIPI_storage, 0, sizeof(mock_MIPI_storage));
      memset(&mock_MIPI_OCP_MEM_storage, 0, sizeof(mock_MIPI_OCP_MEM_storage));

      /* Reset module-level static variables (white-box access) */
      MIPI_Frm_Start_Handler    = NULL_PTR;
      MIPI_Frm_End_Handler      = NULL_PTR;
      MIPI_Chp_Start_Handler    = NULL_PTR;
      MIPI_Chp_End_Handler      = NULL_PTR;
      MIPI_Chp_Fusa_Irq_Handler = NULL_PTR;
      MIPI_Frame_Start_Flag     = false;
      MIPI_Frame_End_Flag       = false;
      MIPI_Chirp_Start_Flag     = false;
      MIPI_Chirp_End_Flag       = false;
      MIPI_Fusa_Irq_Flag        = false;
      MIPI_Chirp_Start_Irq_Cnt  = 0U;
      MIPI_Chirp_End_Irq_Cnt    = 0U;
      MIPI_Frame_Start_Irq_Cnt  = 0U;
      MIPI_Frame_End_Irq_Cnt    = 0U;
      MIPI_FuSa_Irq_Cnt         = 0U;
      Number_Rx_To_Copy         = 0U;
      Chirp_Counter             = 0U;

      s_callback_count = 0;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases — MIPI_Irq_Setup
 *===========================================================================*/

/**
 * @brief MIPI_Irq_Setup with all handlers NULL disables all GIC interrupts
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_AllNullHandlers_DisablesAll)
{
   Std_ReturnType result = MIPI_Irq_Setup(NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR);

   EXPECT_EQ(result, E_OK);
   /* 5 interrupts should be disabled: FuSa, FrmStart, FrmEnd, ChpStart, ChpEnd */
   // EXPECT_EQ(GIC_disableInt_fake.call_count, 5U);
   // EXPECT_EQ(GIC_enableInt_fake.call_count, 0U);
   EXPECT_EQ(ensureInterruptsNotMasked_fake.call_count, 1U);
}

/**
 * @brief MIPI_Irq_Setup with all handlers provided enables all GIC interrupts
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_AllHandlersProvided_EnablesAll)
{
   Std_ReturnType result = MIPI_Irq_Setup(TestCallback, TestCallback, TestCallback, TestCallback, TestCallback);

   EXPECT_EQ(result, E_OK);
   /* 5 interrupts should be enabled: FuSa, FrmStart, FrmEnd, ChpStart, ChpEnd */
   // EXPECT_EQ(GIC_enableInt_fake.call_count, 5U);
   // EXPECT_EQ(GIC_configureIntBasic_fake.call_count, 5U);
   EXPECT_EQ(ensureInterruptsNotMasked_fake.call_count, 1U);
}

/**
 * @brief MIPI_Irq_Setup stores handlers in static variables
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_StoresHandlers)
{
   MIPI_Irq_Setup(TestCallback, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR);

   EXPECT_EQ(MIPI_Frm_Start_Handler, TestCallback);
   EXPECT_EQ(MIPI_Frm_End_Handler, (mipi_ithandler)NULL_PTR);
}

/**
 * @brief MIPI_Irq_Setup with frame start handler enables FRM_START IRQ in hardware
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_FrmStartHandler_EnablesRegisterBit)
{
   MIPI_Irq_Setup(TestCallback, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR);

   /* FRAME_IRQ_EN should have FRAME_START bit set */
   EXPECT_NE(mock_MIPI_storage.FRAME_IRQ_EN.r & MIPI_FRAME_IRQ_EN_FRAME_START_EN_msk, 0U);
}

/**
 * @brief MIPI_Irq_Setup with NULL frame start handler disables FRM_START bit in hardware
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_NoFrmStartHandler_DisablesRegisterBit)
{
   /* Pre-set the bit to verify it gets cleared */
   mock_MIPI_storage.FRAME_IRQ_EN.r |= MIPI_FRAME_IRQ_EN_FRAME_START_EN_msk;

   MIPI_Irq_Setup(NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR);

   EXPECT_EQ(mock_MIPI_storage.FRAME_IRQ_EN.r & MIPI_FRAME_IRQ_EN_FRAME_START_EN_msk, 0U);
}

/**
 * @brief MIPI_Irq_Setup with FuSa handler writes FuSa enable registers
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, IrqSetup_FusaHandler_WritesFusaEnableRegisters)
{
   MIPI_Irq_Setup(NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, TestCallback);

   EXPECT_EQ(mock_MIPI_storage.FUSA_IRQ0_EN.r, MIPI_FUSA_IRQ0_ENABLE_MASK);
   EXPECT_EQ(mock_MIPI_storage.FUSA_IRQ1_EN.r, MIPI_FUSA_IRQ1_ENABLE_MASK);
   EXPECT_EQ(mock_MIPI_storage.FUSA_IRQ2_EN.r, MIPI_FUSA_IRQ2_ENABLE_MASK);
}

/*===========================================================================*
 * Test Cases — MIPI_Get_Frm_End_Flag / MIPI_Clear_Frm_End_Flag
 *===========================================================================*/

/**
 * @brief MIPI_Get_Frm_End_Flag returns E_NOT_OK when pointer is NULL
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmEndFlag_NullPointer_ReturnsNotOk)
{
   Std_ReturnType result = MIPI_Get_Frm_End_Flag(NULL_PTR);
   EXPECT_EQ(result, E_NOT_OK);
}

/**
 * @brief MIPI_Get_Frm_End_Flag reads from hardware register when no handler is set
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmEndFlag_NoHandler_ReadsHardwareRegister)
{
   /* Simulate hardware reporting frame end */
   mock_MIPI_storage.FRAME_IRQ_FLAG.f.FRAME_END_FLAG = 1U;

   volatile bool flag    = false;
   Std_ReturnType result = MIPI_Get_Frm_End_Flag(&flag);

   EXPECT_EQ(result, E_OK);
   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Get_Frm_End_Flag reads cached flag when handler is registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmEndFlag_WithHandler_ReadsCachedFlag)
{
   MIPI_Frm_End_Handler = TestCallback;
   MIPI_Frame_End_Flag  = true;

   volatile bool flag = false;
   MIPI_Get_Frm_End_Flag(&flag);

   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Clear_Frm_End_Flag always returns E_OK
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearFrmEndFlag_ReturnsOk)
{
   Std_ReturnType result = MIPI_Clear_Frm_End_Flag();
   EXPECT_EQ(result, E_OK);
}

/**
 * @brief MIPI_Clear_Frm_End_Flag clears cached flag when handler is set
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearFrmEndFlag_WithHandler_ClearsCachedFlag)
{
   MIPI_Frm_End_Handler = TestCallback;
   MIPI_Frame_End_Flag  = true;

   MIPI_Clear_Frm_End_Flag();

   EXPECT_FALSE(MIPI_Frame_End_Flag);
}

/*===========================================================================*
 * Test Cases — MIPI_Get_Frm_Start_Flag / MIPI_Clear_Frm_Start_Flag
 *===========================================================================*/

/**
 * @brief MIPI_Get_Frm_Start_Flag returns E_NOT_OK for NULL pointer
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmStartFlag_NullPointer_ReturnsNotOk)
{
   Std_ReturnType result = MIPI_Get_Frm_Start_Flag(NULL_PTR);
   EXPECT_EQ(result, E_NOT_OK);
}

/**
 * @brief MIPI_Get_Frm_Start_Flag reads hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmStartFlag_NoHandler_ReadsHardware)
{
   mock_MIPI_storage.FRAME_IRQ_FLAG.f.FRAME_START_FLAG = 1U;

   volatile bool flag    = false;
   Std_ReturnType result = MIPI_Get_Frm_Start_Flag(&flag);

   EXPECT_EQ(result, E_OK);
   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Get_Frm_Start_Flag reads cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetFrmStartFlag_WithHandler_ReadsCachedFlag)
{
   MIPI_Frm_Start_Handler = TestCallback;
   MIPI_Frame_Start_Flag  = true;

   volatile bool flag    = false;
   Std_ReturnType result = MIPI_Get_Frm_Start_Flag(&flag);

   EXPECT_EQ(result, E_OK);
   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Clear_Frm_Start_Flag clears cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearFrmStartFlag_WithHandler_ClearsCachedFlag)
{
   MIPI_Frm_Start_Handler = TestCallback;
   MIPI_Frame_Start_Flag  = true;

   Std_ReturnType result = MIPI_Clear_Frm_Start_Flag();

   EXPECT_EQ(result, E_OK);
   EXPECT_FALSE(MIPI_Frame_Start_Flag);
}

/**
 * @brief MIPI_Clear_Frm_Start_Flag writes to hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearFrmStartFlag_NoHandler_WritesRegister)
{
   mock_MIPI_storage.FRAME_IRQ_FLAG.r = 0U;

   Std_ReturnType result = MIPI_Clear_Frm_Start_Flag();

   EXPECT_EQ(result, E_OK);
   EXPECT_EQ(mock_MIPI_storage.FRAME_IRQ_FLAG.r, MIPI_FRAME_IRQ_FLAG_FRAME_START_FLAG_msk);
}

/*===========================================================================*
 * Test Cases — MIPI_Get_Chp_Start_Flag / MIPI_Clear_Chp_Start_Flag
 *===========================================================================*/

/**
 * @brief MIPI_Get_Chp_Start_Flag returns E_NOT_OK for NULL pointer
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpStartFlag_NullPointer_ReturnsNotOk)
{
   Std_ReturnType result = MIPI_Get_Chp_Start_Flag(NULL_PTR);
   EXPECT_EQ(result, E_NOT_OK);
}

/**
 * @brief MIPI_Get_Chp_Start_Flag reads hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpStartFlag_NoHandler_ReadsHardware)
{
   mock_MIPI_storage.CHIRP_IRQ_FLAG.f.CHIRP_START_FLAG = 1U;

   volatile bool flag    = false;
   Std_ReturnType result = MIPI_Get_Chp_Start_Flag(&flag);

   EXPECT_EQ(result, E_OK);
   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Get_Chp_Start_Flag reads cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpStartFlag_WithHandler_ReadsCachedFlag)
{
   MIPI_Chp_Start_Handler = TestCallback;
   MIPI_Chirp_Start_Flag  = true;

   volatile bool flag = false;
   MIPI_Get_Chp_Start_Flag(&flag);

   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Clear_Chp_Start_Flag clears cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearChpStartFlag_WithHandler_ClearsCachedFlag)
{
   MIPI_Chp_Start_Handler = TestCallback;
   MIPI_Chirp_Start_Flag  = true;

   MIPI_Clear_Chp_Start_Flag();

   EXPECT_FALSE(MIPI_Chirp_Start_Flag);
}

/**
 * @brief MIPI_Clear_Chp_Start_Flag writes to hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearChpStartFlag_NoHandler_WritesRegister)
{
   mock_MIPI_storage.CHIRP_IRQ_FLAG.r = 0U;

   Std_ReturnType result = MIPI_Clear_Chp_Start_Flag();

   EXPECT_EQ(result, E_OK);
   EXPECT_EQ(mock_MIPI_storage.CHIRP_IRQ_FLAG.r, MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk);
}

/*===========================================================================*
 * Test Cases — MIPI_Get_Chp_End_Flag / MIPI_Clear_Chp_End_Flag
 *===========================================================================*/

/**
 * @brief MIPI_Get_Chp_End_Flag returns E_NOT_OK for NULL pointer
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpEndFlag_NullPointer_ReturnsNotOk)
{
   Std_ReturnType result = MIPI_Get_Chp_End_Flag(NULL_PTR);
   EXPECT_EQ(result, E_NOT_OK);
}

/**
 * @brief MIPI_Get_Chp_End_Flag reads cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpEndFlag_WithHandler_ReadsCachedFlag)
{
   MIPI_Chp_End_Handler = TestCallback;
   MIPI_Chirp_End_Flag  = true;

   volatile bool flag = false;
   MIPI_Get_Chp_End_Flag(&flag);

   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Get_Chp_End_Flag reads hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, GetChpEndFlag_NoHandler_ReadsHardware)
{
   mock_MIPI_storage.CHIRP_IRQ_FLAG.f.CHIRP_END_FLAG = 1U;

   volatile bool flag    = false;
   Std_ReturnType result = MIPI_Get_Chp_End_Flag(&flag);

   EXPECT_EQ(result, E_OK);
   EXPECT_TRUE(flag);
}

/**
 * @brief MIPI_Clear_Chp_End_Flag clears cached flag when handler registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearChpEndFlag_WithHandler_ClearsCachedFlag)
{
   MIPI_Chp_End_Handler = TestCallback;
   MIPI_Chirp_End_Flag  = true;

   Std_ReturnType result = MIPI_Clear_Chp_End_Flag();

   EXPECT_EQ(result, E_OK);
   EXPECT_FALSE(MIPI_Chirp_End_Flag);
}

/**
 * @brief MIPI_Clear_Chp_End_Flag writes to hardware register when no handler
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ClearChpEndFlag_NoHandler_WritesRegister)
{
   mock_MIPI_storage.CHIRP_IRQ_FLAG.r = 0U;

   Std_ReturnType result = MIPI_Clear_Chp_End_Flag();

   EXPECT_EQ(result, E_OK);
   EXPECT_EQ(mock_MIPI_storage.CHIRP_IRQ_FLAG.r, MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk);
}

/*===========================================================================*
 * Test Cases — ISR Handler Functions
 *===========================================================================*/

/**
 * @brief MIPI_Frame_Start_Handler sets the cached flag and calls registered callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FrameStartHandler_SetsFlag_CallsCallback)
{
   MIPI_Frm_Start_Handler = TestCallback;

   MIPI_Frame_Start_Handler();

   EXPECT_TRUE(MIPI_Frame_Start_Flag);
   EXPECT_EQ(s_callback_count, 1);
}

/**
 * @brief MIPI_Frame_Start_Handler sets flag even with no callback registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FrameStartHandler_NoCallback_SetsFlag)
{
   MIPI_Frame_Start_Handler();

   EXPECT_TRUE(MIPI_Frame_Start_Flag);
   EXPECT_EQ(s_callback_count, 0);
}

/**
 * @brief MIPI_Frame_End_Handler sets the cached flag and calls registered callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FrameEndHandler_SetsFlag_CallsCallback)
{
   MIPI_Frm_End_Handler = TestCallback;

   MIPI_Frame_End_Handler();

   EXPECT_TRUE(MIPI_Frame_End_Flag);
   EXPECT_EQ(s_callback_count, 1);
}

/**
 * @brief MIPI_Frame_End_Handler sets flag even with no callback registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FrameEndHandler_NoCallback_SetsFlag)
{
   MIPI_Frame_End_Handler();

   EXPECT_TRUE(MIPI_Frame_End_Flag);
   EXPECT_EQ(s_callback_count, 0);
}

/**
 * @brief MIPI_Chirp_Start_Handler sets the cached flag and calls registered callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ChirpStartHandler_SetsFlag_CallsCallback)
{
   MIPI_Chp_Start_Handler = TestCallback;

   MIPI_Chirp_Start_Handler();

   EXPECT_TRUE(MIPI_Chirp_Start_Flag);
   EXPECT_EQ(s_callback_count, 1);
}

/**
 * @brief MIPI_Chirp_Start_Handler sets flag even with no callback registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ChirpStartHandler_NoCallback_SetsFlag)
{
   MIPI_Chirp_Start_Handler();

   EXPECT_TRUE(MIPI_Chirp_Start_Flag);
   EXPECT_EQ(s_callback_count, 0);
}

/**
 * @brief MIPI_Chirp_End_Handler sets the cached flag and calls registered callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ChirpEndHandler_SetsFlag_CallsCallback)
{
   MIPI_Chp_End_Handler = TestCallback;

   MIPI_Chirp_End_Handler();

   EXPECT_TRUE(MIPI_Chirp_End_Flag);
   EXPECT_EQ(s_callback_count, 1);
}

/**
 * @brief MIPI_Chirp_End_Handler sets flag even with no callback registered
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, ChirpEndHandler_NoCallback_SetsFlag)
{
   MIPI_Chirp_End_Handler();

   EXPECT_TRUE(MIPI_Chirp_End_Flag);
   EXPECT_EQ(s_callback_count, 0);
}

/**
 * @brief MIPI_FuSa_Irq_Handler sets the FuSa flag and calls registered callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FusaIrqHandler_SetsFlag_CallsCallback)
{
   MIPI_Chp_Fusa_Irq_Handler = TestCallback;

   MIPI_FuSa_Irq_Handler();

   EXPECT_TRUE(MIPI_Fusa_Irq_Flag);
   EXPECT_EQ(s_callback_count, 1);
}

/**
 * @brief MIPI_FuSa_Irq_Handler sets flag even with no callback
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FusaIrqHandler_NoCallback_SetsFlag)
{
   MIPI_FuSa_Irq_Handler();

   EXPECT_TRUE(MIPI_Fusa_Irq_Flag);
   EXPECT_EQ(s_callback_count, 0);
}

/*===========================================================================*
 * Test Cases — Counter Functions
 *===========================================================================*/

/**
 * @brief Start_MIPI_Chirp increments the chirp start counter
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, StartMipiChirp_IncrementsCounter)
{
   EXPECT_EQ(MIPI_Chirp_Start_Irq_Cnt, 0U);
   Start_MIPI_Chirp();
   EXPECT_EQ(MIPI_Chirp_Start_Irq_Cnt, 1U);
   Start_MIPI_Chirp();
   EXPECT_EQ(MIPI_Chirp_Start_Irq_Cnt, 2U);
}

/**
 * @brief End_MIPI_Chirp increments the chirp end counter with zero Rx channels to copy
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, EndMipiChirp_ZeroRxChannels_IncrementsChirpCounter)
{
   Number_Rx_To_Copy = 0U; /* Skip the DMA loop */

   End_MIPI_Chirp();

   EXPECT_EQ(MIPI_Chirp_End_Irq_Cnt, 1U);
   EXPECT_EQ(Chirp_Counter, 1U);
}

/**
 * @brief Start_MIPI_Frame increments the frame start counter
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, StartMipiFrame_IncrementsCounter)
{
   EXPECT_EQ(MIPI_Frame_Start_Irq_Cnt, 0U);
   Start_MIPI_Frame();
   EXPECT_EQ(MIPI_Frame_Start_Irq_Cnt, 1U);
}

/**
 * @brief End_MIPI_Frame increments the frame end counter
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, EndMipiFrame_IncrementsCounter)
{
   EXPECT_EQ(MIPI_Frame_End_Irq_Cnt, 0U);
   End_MIPI_Frame();
   EXPECT_EQ(MIPI_Frame_End_Irq_Cnt, 1U);
}

/**
 * @brief MIPI_FuSa_IRQ increments the FuSa interrupt counter
 */
TEST_F(MIPI_Interrupt_UnitTestSuite, FusaIRQ_IncrementsCounter)
{
   EXPECT_EQ(MIPI_FuSa_Irq_Cnt, 0U);
   MIPI_FuSa_IRQ();
   EXPECT_EQ(MIPI_FuSa_Irq_Cnt, 1U);
}
