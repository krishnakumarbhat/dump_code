/*===========================================================================*\
 * FILE: Ra_fault_injection.c
 *===========================================================================
 * Copyright 2025 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the SYSMEM ECC/parity handling and fault injection APIs for Functional Safety Mechanism.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     SW REF 264.15D "APTIV C Coding Standards" [12-Mar-2006]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
#if defined(ENABLE_SQT_TEST_STUBS)
   #pragma clang optimize off
#endif
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "reuse.h"
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Ra_fault_injection.h"
#include "chandra_sfrs_base.h"
#include "ra_mem_sfrs.h"
#include "ra_sfrs.h"

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/

#if defined(ENABLE_SQT_TEST_STUBS)
   /* SM_068_RA_CQ_OVF_MON Test Definitions */
   #define SM_068_NUM_TESTS            (1U)          /* Number of CQ overflow tests */
   #define SM_068_CQ_OVF_ERR_FLAG_MASK (0x00000010U) /* R52_ERR_IRQ_FLAG_1.CQ_OVF_IRQ_R52_ERR_FLAG (bit 4) */
   #define SM_068_RA_CMD_QUEUE_SIZE    (16U)         /* RA CQMEM slots (0-15), but queue depth is 128 per manual */

   #define SM_067_NUM_TESTS                    (21U)         /* Total number of invalid config tests */
   #define SM_067_RA_CMD_SIZE                  (32U)         /* RA command size in 32-bit words */
   #define SM_067_INVALID_CONFIG_ERR_FLAG_MASK (0x00000001U) /* R52_ERR_IRQ_FLAG_1.INVALID_CONFIG_IRQ_R52_ERR_FLAG */
   #define SM_067_TEST_CMD_SLOT                (0U)
   #define SM_067_RA_CMD_SIZE_RUNTIME          (16)
#endif

#define PTR_RA                    ((volatile RA_SFRS_t *)RA_base)
#define PTR_RA_MEM                ((volatile RA_MEM_SFRS_t *)RA_MEM_base)
#define RA_AXI_IN_PARITY_IRQ_BIT  (1u << 24)
#define RA_AXI_OUT_PARITY_IRQ_BIT (1u << 25)
#define SM64_SM65_BUFFER_BYTES    (255U)
#define RA_SM65_WAIT_TIMEOUT      (1000000U)
#define RA_MULTI_INJECT_COUNT     (4U)

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
#if defined(ENABLE_SQT_TEST_STUBS)
volatile ra_sm_test_t ra_sm_enable        = SM_MAX;
volatile ra_ecc_test_t ra_ecc_test_enable = RA_ECC_TEST_SEC;
volatile uint8_t RA_Inj_Type              = 0U;

static volatile uint8_t ra_sm70_event_observed = 0U;
static uint32_t ra_fault_injection_count       = 0U;

/*===========================================================================*\
 * Local Preprocessor Constants
\*===========================================================================*/

/* ========================================================================== *
 * Global Variables
 * ========================================================================== */
volatile uint32_t CQMEM_ErrCnt  = 0; /* Variable to hold CQMEM error count */
volatile uint32_t IDXMEM_ErrCnt = 0; /* Variable to hold IDXMEM error count */
volatile uint32_t PHXMEM_ErrCnt = 0; /* Variable to hold PHXMEM error count */
volatile uint32_t WCMEM_ErrCnt  = 0; /* Variable to hold WCMEM error count */
volatile uint32_t ESTMEM_ErrCnt = 0; /* Variable to hold ESTMEM error count */
volatile uint32_t __attribute__((section(".sram1.bss"))) __attribute__((aligned(32)))
RA_Shared_Input_Buffer[SM64_SM65_BUFFER_BYTES] = {0U};
volatile uint32_t __attribute__((section(".sram1.bss"))) __attribute__((aligned(32)))
RA_Shared_Output_Buffer[SM64_SM65_BUFFER_BYTES] = {0U};
volatile uint32_t *const RA_Shared_Input_Ptr    = &RA_Shared_Input_Buffer[0];
volatile uint32_t *const RA_Shared_Output_Ptr   = &RA_Shared_Output_Buffer[0];

static void RA_Clear_Shared_Buffers(void)
{
   uint32_t i = 0U;

   for (i = 0U; i < SM64_SM65_BUFFER_BYTES; i++)
   {
      RA_Shared_Input_Buffer[i]  = 0U;
      RA_Shared_Output_Buffer[i] = 0U;
   }
}
#endif
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
#ifndef UNIT_TEST
/** Configures the RA ECC single-error thresholds during application initialization. */
void Set_RA_SEC_Threshold(void)
{
   volatile RA_SFRS_t *ra                              = PTR_RA;
   ra->CQMEM_ECC_CONTROL.f.CQMEM_ECC_SEC_CNT_THR       = 0;
   ra->IDXMEM_ECC_CONTROL.f.IDXMEM_ECC_SEC_CNT_THR     = 0;
   ra->PHMEM_ECC_CONTROL.f.PHMEM_ECC_SEC_CNT_THR       = 0;
   ra->WCMEM_ECC_CONTROL.f.WCMEM_ECC_SEC_CNT_THR       = 0;
   ra->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_SEC_CNT_THR = 0;
   ra->ESTMEM_2_ECC_CONTROL.f.ESTMEM_2_ECC_SEC_CNT_THR = 0;
   ra->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_SEC_CNT_THR = 0;
   ra->ESTMEM_4_ECC_CONTROL.f.ESTMEM_4_ECC_SEC_CNT_THR = 0;
}
#endif

#if defined(ENABLE_SQT_TEST_STUBS)
/** Injects the SM_064 AXI master input parity fault and clears its status flag. */
void SM_064_RA_AXI_M_IN_PARITY_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);
   uint32_t timeout              = RA_SM65_WAIT_TIMEOUT;

   ra->R52_FUSA_IRQ_ENA.r = 0x00000000U; /* Disable all RA error interrupts */

   /* Enable Interrupt bit for SM64 */
   ra->R52_FUSA_IRQ_ENA.r |= RA_AXI_IN_PARITY_IRQ_BIT;

   /* Force CQMEM to use AHB bus for input data */
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Step1: Clear CQMEM command */
   cqmem_cmd0[0]  = 0x0021FF00U;                   /* F8  = IN_SIZE(255)  F16 = IRQ_EN(1) F20 = INPUT_MNGR_MODE(2) */
   cqmem_cmd0[1]  = 0x00000001U;                   /* F32 = IN_OP_SET(1) F33 = IN_FETCH_MODE(0) F36 = IN_DPMEM_BANK_DST(0)  */
   cqmem_cmd0[2]  = (uint32_t)RA_Shared_Input_Ptr; /* F64 = IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;                   /* F96  = IN_ADDR_STEP = 0 */
   cqmem_cmd0[4]  = 0x00000000U;                   /* F128 = PROC_OP_SET = 0 Processing stage disabled */
   cqmem_cmd0[5]  = 0x00000000U;                   /* F160 = OUT_OP_SET = 0 Output stage disabled */
   cqmem_cmd0[6]  = 0x00000000U;                   /* F192..F223 unused */
   cqmem_cmd0[7]  = 0x00000000U;                   /* F224..F255 unused */
   cqmem_cmd0[8]  = 0x00000000U;                   /* F256..F287 unused */
   cqmem_cmd0[9]  = 0x00000000U;                   /* F288..F319 unused */
   cqmem_cmd0[10] = 0x00000000U;                   /* F320..F351 unused */
   cqmem_cmd0[11] = 0x00000000U;                   /* F352..F383 unused */
   cqmem_cmd0[12] = 0x00000000U;                   /* F384..F415 unused */
   cqmem_cmd0[13] = 0x00000000U;                   /* F416..F447 unused */
   cqmem_cmd0[14] = 0x00000000U;                   /* F448..F479 unused */
   cqmem_cmd0[15] = 0x00000000U;                   /* F480..F511 unused */

   /* Step2: Force AXI input parity error */
   ra->FUSA_TESTMODES.f.TM_FORCE_AXI_IN_PARITY_ERR = (1U << 8);
   ra->CONTROL.f.FORCE_CQMEM_AHB                   = 0U;
   (void)ra->CONTROL.r; /* Read back to ensure write has taken effect */

   /* Step3: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step4: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
   #ifndef UNIT_TEST
   while ((ra->R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG == 0U) && (timeout > 0U))
   #endif
   {
      timeout--;
   }

   /* Reset test injection state after flag is observed (or timeout expires). */
   ra->FUSA_TESTMODES.f.TM_FORCE_AXI_IN_PARITY_ERR &= ~(1U << 8);
   if (ra->R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG != 0U)
   {
      ra->R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG = 0U;
   }
}

/** Injects the SM_065 AXI master output parity fault and clears its status flag. */
void SM_065_RA_AXI_M_OUT_PARITY_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);
   uint32_t timeout              = RA_SM65_WAIT_TIMEOUT;

   /* Disable all RA error interrupts */
   ra->R52_FUSA_IRQ_ENA.r = 0x00000000U;

   /* Enable Interrupt bit for SM65 */
   ra->R52_FUSA_IRQ_ENA.r |= RA_AXI_OUT_PARITY_IRQ_BIT;

   /* Force CQMEM to use AHB bus for input data */
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Step1: Clear CQMEM command */
   cqmem_cmd0[0]  = 0x0061FF00U; /* F8=IN_SIZE(255), F16=IRQ_EN(1), F20=INPUT_MNGR_MODE(2), F22=OUTPUT_MNGR_MODE(1) */
   cqmem_cmd0[1]  = 0x00000001U; /* F32=IN_OP_SET(1), F33=IN_FETCH_MODE(0), F36=IN_DPMEM_BANK_DST(0) */
   cqmem_cmd0[2]  = (uint32_t)RA_Shared_Input_Ptr;  /* F64=IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;                    /* F96=IN_ADDR_STEP(0) */
   cqmem_cmd0[4]  = 0x00000000U;                    /* F128=PROC_OP_SET(0) - Processing stage disabled */
   cqmem_cmd0[5]  = 0x00000001U;                    /* F160=OUT_OP_SET(1), F164=OUT_DPMEM_BANK_SRC(0) */
   cqmem_cmd0[6]  = (uint32_t)RA_Shared_Output_Ptr; /* F192=OUT_ADDR_START */
   cqmem_cmd0[7]  = 0x00000000U;                    /* F224=OUT_ADDR_STEP(0) */
   cqmem_cmd0[8]  = 0x00000000U;                    /* F256..F287 unused */
   cqmem_cmd0[9]  = 0x00000000U;                    /* F288..F319 unused */
   cqmem_cmd0[10] = 0x00000000U;                    /* F320..F351 unused */
   cqmem_cmd0[11] = 0x00000000U;                    /* F352..F383 unused */
   cqmem_cmd0[12] = 0x00000000U;                    /* F384..F415 unused */
   cqmem_cmd0[13] = 0x00000000U;                    /* F416..F447 unused */
   cqmem_cmd0[14] = 0x00000000U;                    /* F448..F479 unused */
   cqmem_cmd0[15] = 0x00000000U;                    /* F480..F511 unused */

   /* Step2: Force AXI output parity error */
   ra->FUSA_TESTMODES.f.TM_FORCE_AXI_OUT_PARITY_ERR = (1U << 15);

   /* Force CQMEM to use AHB bus for input data */
   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   /* Step3: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step4: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;

   #ifndef UNIT_TEST
   while ((ra->R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG == 0U) && (timeout > 0U))
   #endif
   {
      timeout--;
   }

   /* Reset test injection state after flag is observed (or timeout expires). */
   ra->FUSA_TESTMODES.f.TM_FORCE_AXI_OUT_PARITY_ERR &= ~(1U << 15);
   if (ra->R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG != 0U)
   {
      ra->R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG = 0U;
   }
}

/** Injects the SM_082 input-stage watchdog timeout fault. */
void SM_082_RA_WWDG_IS_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);
   uint32_t timeout              = RA_SM65_WAIT_TIMEOUT;

   ra->R52_ERR_IRQ_ENA_1.r = 0x00000000U; /* Disable all RA error interrupts */

   /* Enable Interrupt bit for SM82 */
   ra->R52_ERR_IRQ_ENA_1.f.IN_STAGE_WDT_IRQ_R52_ERR_ENA = 1U;

   ra->CONTROL.r |= 0x0FFF0000; /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Step1 */
   cqmem_cmd0[0]  = 0x0021FF00U;                   /* F8=IN_SIZE(255), F16=IRQ_EN(1), F20=INPUT_MNGR_MODE(2) */
   cqmem_cmd0[1]  = 0x00000001U;                   /* F32=IN_OP_SET(1), F33=IN_FETCH_MODE(0) */
   cqmem_cmd0[2]  = (uint32_t)RA_Shared_Input_Ptr; /* F64=IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;                   /* F96=IN_ADDR_STEP(0) */
   cqmem_cmd0[4]  = 0x00000000U;                   /* F128=PROC_OP_SET(0) - Processing stage disabled */
   cqmem_cmd0[5]  = 0x00000000U;                   /* F160=OUT_OP_SET(0) - Output stage disabled */
   cqmem_cmd0[6]  = 0x00000000U;                   /* F192..F223 unused */
   cqmem_cmd0[7]  = 0x00000000U;                   /* F224..F255 unused */
   cqmem_cmd0[8]  = 0x00000000U;                   /* F256..F287 unused */
   cqmem_cmd0[9]  = 0x00000000U;                   /* F288..F319 unused */
   cqmem_cmd0[10] = 0x00000000U;                   /* F320..F351 unused */
   cqmem_cmd0[11] = 0x00000000U;                   /* F352..F383 unused */
   cqmem_cmd0[12] = 0x00000000U;                   /* F384..F415 unused */
   cqmem_cmd0[13] = 0x00000000U;                   /* F416..F447 unused */
   cqmem_cmd0[14] = 0x00000000U;                   /* F448..F479 unused */
   cqmem_cmd0[15] = 0x00000000U;                   /* F480..F511 unused */

   /* Step2: Configure watchdog */
   ra->MON_TIMER_IN_CTRL.f.MON_TMR_IN_TIMEOUT_SEL = 1U;
   ra->MON_TIMER_IN_CTRL.f.MON_TMR_IN_ENA         = 1U;

   ra->CONTROL.r &= ~(0x0FFF0000); /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   /* Step3: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step4: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
   #ifndef UNIT_TEST
   while ((ra->R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG == 0U) && (timeout > 0U))
   #endif
   {
      timeout--;
   }

   if (ra->R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U)
   {
      ra->R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;
   }
   ra->MON_TIMER_IN_CTRL.f.MON_TMR_IN_TIMEOUT_SEL = 500000U; /* Reset to default value */
}

/** Injects the SM_083 output-stage watchdog timeout fault. */
void SM_083_RA_WWDG_OS_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);
   uint32_t timeout              = RA_SM65_WAIT_TIMEOUT;

   ra->R52_ERR_IRQ_ENA_1.r = 0x00000000U; /* Disable all RA error interrupts */

   /* Enable Interrupt bit for SM83 */
   ra->R52_ERR_IRQ_ENA_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_ENA = 1U;

   ra->CONTROL.r |= 0x0FFF0000; /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Step1: Clear CQMEM command */
   cqmem_cmd0[0]  = 0x0051FF00U;                    /* F8=IN_SIZE(255), F16=IRQ_EN(1), F22=OUTPUT_MNGR_MODE(1) */
   cqmem_cmd0[1]  = 0x00000000U;                    /* F32=IN_OP_SET(0) - Input stage disabled */
   cqmem_cmd0[2]  = 0x00000000U;                    /* F64=IN_ADDR_START unused */
   cqmem_cmd0[3]  = 0x00000000U;                    /* F96=IN_ADDR_STEP unused */
   cqmem_cmd0[4]  = 0x00000000U;                    /* F128=PROC_OP_SET(0) - Processing stage disabled */
   cqmem_cmd0[5]  = 0x00000001U;                    /* F160=OUT_OP_SET(1) - Output stage enabled */
   cqmem_cmd0[6]  = (uint32_t)RA_Shared_Output_Ptr; /* F192=OUT_ADDR_START */
   cqmem_cmd0[7]  = 0x00000000U;                    /* F224=OUT_ADDR_STEP(0) */
   cqmem_cmd0[8]  = 0x00000000U;                    /* F256..F287 unused */
   cqmem_cmd0[9]  = 0x00000000U;                    /* F288..F319 unused */
   cqmem_cmd0[10] = 0x00000000U;                    /* F320..F351 unused */
   cqmem_cmd0[11] = 0x00000000U;                    /* F352..F383 unused */
   cqmem_cmd0[12] = 0x00000000U;                    /* F384..F415 unused */
   cqmem_cmd0[13] = 0x00000000U;                    /* F416..F447 unused */
   cqmem_cmd0[14] = 0x00000000U;                    /* F448..F479 unused */
   cqmem_cmd0[15] = 0x00000000U;                    /* F480..F511 unused */

   /* Step2: Set minimum watchdog timeout */
   ra->MON_TIMER_OUT_CTRL.f.MON_TMR_OUT_TIMEOUT_SEL = 1U;
   ra->MON_TIMER_OUT_CTRL.f.MON_TMR_OUT_ENA         = 1U;

   ra->CONTROL.r &= ~(0x0FFF0000); /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   /* Step3: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step4: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
   #ifndef UNIT_TEST
   while ((ra->R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG == 0U) && (timeout > 0U))
   #endif
   {
      timeout--;
   }

   if (ra->R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U)
   {
      ra->R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;
   }
   ra->MON_TIMER_OUT_CTRL.f.MON_TMR_OUT_TIMEOUT_SEL = 500000U; /* Reset to default value */
}

/** Injects the SM_084 processing-stage watchdog timeout fault. */
void SM_084_RA_WWDG_PS_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   ra->R52_ERR_IRQ_ENA_1.r = 0x00000000U; /* Disable all RA error interrupts */

   /* Enable Interrupt bit for SM84 */
   ra->R52_ERR_IRQ_ENA_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_ENA = 1U;

   ra->CONTROL.r |= 0x0FFF0000; /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   /* Step1: Clear CQMEM command */
   cqmem_cmd0[0] =
      0x0351FF00U; /* F8=IN_SIZE(255), F16=IRQ_EN(1), F20=INPUT_MNGR_MODE(2), F22=OUTPUT_MNGR_MODE(1), F24=FFT_TYPE(3) */
   cqmem_cmd0[1]  = 0x00000000U; /* F32=IN_OP_SET(0) - Input stage disabled */
   cqmem_cmd0[2]  = 0x00000000U; /* F64=IN_ADDR_START unused */
   cqmem_cmd0[3]  = 0x00000000U; /* F96=IN_ADDR_STEP unused */
   cqmem_cmd0[4]  = 0x00000001U; /* F128=PROC_OP_SET(1) - Processing stage enabled */
   cqmem_cmd0[5]  = 0x00000000U; /* F160=OUT_OP_SET(0) - Output stage disabled */
   cqmem_cmd0[6]  = 0x00000000U; /* F192..F223 unused */
   cqmem_cmd0[7]  = 0x00000000U; /* F224..F255 unused */
   cqmem_cmd0[8]  = 0x00000000U; /* F256..F287 unused */
   cqmem_cmd0[9]  = 0x80000000U; /* F279=PREP_BYPASS(1) */
   cqmem_cmd0[10] = 0x00000000U; /* F320..F351 */
   cqmem_cmd0[11] = 0x00000008U; /* F343=POSP_BYPASS(1) */
   cqmem_cmd0[12] = 0x00000000U; /* F384..F415 unused */
   cqmem_cmd0[13] = 0x00000000U; /* F416..F447 unused */
   cqmem_cmd0[14] = 0x00000000U; /* F448..F479 unused */
   cqmem_cmd0[15] = 0x00000000U; /* F480..F511 unused */

   /* Step2: Set minimum watchdog timeout */
   ra->MON_TIMER_PROC_CTRL.f.MON_TMR_PROC_TIMEOUT_SEL = 1U;
   ra->MON_TIMER_PROC_CTRL.f.MON_TMR_PROC_ENA         = 1U;

   ra->CONTROL.r &= ~(0x0FFF0000); /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   /* Step3: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step4: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;

   /* Clear the faults */
   while (ra->R52_ERR_IRQ_FLAG_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U) /* Wait for the interrupt flag to be set */
   {
      ra->R52_ERR_IRQ_FLAG_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_FLAG = 0U;
      ra->MON_TIMER_PROC_CTRL.f.MON_TMR_PROC_TIMEOUT_SEL       = 500000U; /* Reset to default value */
   }
}

   #ifndef UNIT_TEST
/** Injects an SM_069 CQMEM double-bit ECC error. */
void SM_069_RA_CQMEM_ECC_DED_Inject(void)
{
   volatile RA_SFRS_t *ra = PTR_RA;
   uint32_t read_value    = 0;
   /* Enable RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to CQMEM through the AHB interface. */
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1;

   /* Bypass the ECC encoder so the parity bits remain invalid. */
   ra->CQMEM_ECC_CONTROL.f.CQMEM_ECC_ENC_BYPASS = 1;

   // Write a value to the memory
   ((uint32_t *)PTR_RA_MEM->CQMEM)[16] = 0xFFFFFFFF;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[17] = 0xFFFFFFFF;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[18] = 0xFFFFFFFF;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[19] = 0xFFFFFFFF;

   /* Reading the corrupted location triggers the double-error detect path. */
   read_value = ((uint32_t *)PTR_RA_MEM->CQMEM)[16];

   if (read_value != 0xFFFFFFFF)
   {
      CQMEM_ErrCnt += 1;
   }
}

/** Injects an SM_069 CQMEM single-bit ECC error. */
void SM_069_RA_CQMEM_ECC_SEC_Inject(void)
{
   volatile RA_SFRS_t *ra       = PTR_RA;
   volatile uint32_t read_value = 0U;
   /* Enable the RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to CQMEM through AHB interface */
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1;

   /* Bypass ECC encoder */
   ra->CQMEM_ECC_CONTROL.f.CQMEM_ECC_ENC_BYPASS = 1;

   /* Since CQMEM has a width of 128 bits, 4x32-bits writes have to be done */
   ((uint32_t *)PTR_RA_MEM->CQMEM)[0] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->CQMEM)[3] = 0xFFFFFFFFU;

   /* Read 4 times to force the Single-bit Error 4 times */
   for (uint32_t i = 0U; i < 4U; i++)
   {
      read_value = ((uint32_t *)PTR_RA_MEM->CQMEM)[0];
      (void)read_value;

      if (ra->CQMEM_ECC_STATUS != (uint16_t)(i + 1U))
      {
         CQMEM_ErrCnt += 1U;
      }
   }
}

/** Injects an SM_081 WCMEM double-bit ECC error. */
void SM_081_RA_WCMEM_ECC_DED_Inject(void)
{
   volatile RA_SFRS_t *ra = PTR_RA;
   uint32_t read_value    = 0U;

   /* Enable RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to WCMEM through the AHB interface. */
   ra->CONTROL.f.FORCE_WCMEM_AHB = 1;

   /* Bypass the ECC encoder so the parity bits remain invalid. */
   ra->WCMEM_ECC_CONTROL.f.WCMEM_ECC_ENC_BYPASS = 1;

   /* Corrupt a full ECC line using 4x32-bit writes. */
   ((uint32_t *)PTR_RA_MEM->WCMEM)[4] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[5] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[6] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[7] = 0xFFFFFFFFU;

   /* Reading the corrupted location triggers the double-error detect path. */
   read_value = ((uint32_t *)PTR_RA_MEM->WCMEM)[4];

   if (read_value != 0xFFFFFFFFU)
   {
      WCMEM_ErrCnt += 1U;
   }
}

/** Injects an SM_081 WCMEM single-bit ECC error. */
void SM_081_RA_WCMEM_ECC_SEC_Inject(void)
{
   uint32_t read_value    = 0U;
   volatile RA_SFRS_t *ra = PTR_RA;

   ra->CONTROL.f.ENA                            = 1;
   ra->CONTROL.f.FORCE_WCMEM_AHB                = 1;
   ra->WCMEM_ECC_CONTROL.f.WCMEM_ECC_ENC_BYPASS = 1;

   ((uint32_t *)PTR_RA_MEM->WCMEM)[0] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->WCMEM)[3] = 0xFFFFFFFFU;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      read_value = ((uint32_t *)PTR_RA_MEM->WCMEM)[0];
      (void)read_value;

      if (ra->WCMEM_ECC_STATUS != (uint16_t)(i + 1U))
      {
         WCMEM_ErrCnt += 1U;
      }
   }
}

/** Injects an SM_075 IDXMEM double-bit ECC error. */
void SM_075_RA_IDXMEM_ECC_DED_Inject(void)
{
   uint32_t read_value    = 0U;
   volatile RA_SFRS_t *ra = PTR_RA;

   /* Enable RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to IDXMEM through the AHB interface. */
   ra->CONTROL.f.FORCE_IDXMEM_AHB = 1;

   /* Bypass the ECC encoder so the parity bits remain invalid. */
   ra->IDXMEM_ECC_CONTROL.f.IDXMEM_ECC_ENC_BYPASS = 1;

   /* Corrupt a full aligned ECC line using 4x32-bit writes. */
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[3] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[4] = 0xFFFFFFFFU;

   /* Reading the corrupted location triggers the double-error detect path. */
   read_value = ((uint32_t *)PTR_RA_MEM->IDXMEM)[1];

   if (read_value != 0xFFFFFFFFU)
   {
      IDXMEM_ErrCnt += 1U;
   }
}

/** Injects an SM_075 IDXMEM single-bit ECC error. */
void SM_075_RA_IDXMEM_ECC_SEC_Inject(void)
{
   volatile uint32_t read_value = 0U;
   volatile RA_SFRS_t *ra       = PTR_RA;

   ra->CONTROL.f.ENA                              = 1;
   ra->CONTROL.f.FORCE_IDXMEM_AHB                 = 1;
   ra->IDXMEM_ECC_CONTROL.f.IDXMEM_ECC_ENC_BYPASS = 1;

   ((uint32_t *)PTR_RA_MEM->IDXMEM)[0] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->IDXMEM)[3] = 0xFFFFFFFFU;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      read_value = ((uint32_t *)PTR_RA_MEM->IDXMEM)[0];
      (void)read_value;

      if (ra->IDXMEM_ECC_STATUS != (uint16_t)(i + 1U))
      {
         IDXMEM_ErrCnt += 1U;
      }
   }
}

/** Injects an SM_079 PHMEM double-bit ECC error. */
void SM_079_RA_PHMEM_ECC_DED_Inject(void)
{
   uint32_t read_value    = 0U;
   volatile RA_SFRS_t *ra = PTR_RA;

   /* Enable RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to PHMEM through the AHB interface. */
   ra->CONTROL.f.FORCE_PHMEM_AHB = 1;

   /* Bypass the ECC encoder so the parity bits remain invalid. */
   ra->PHMEM_ECC_CONTROL.f.PHMEM_ECC_ENC_BYPASS = 1;

   /* Corrupt a full aligned ECC line using 4x32-bit writes. */
   ((uint32_t *)PTR_RA_MEM->PHMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[3] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[4] = 0xFFFFFFFFU;

   /* Reading the corrupted location triggers the double-error detect path. */
   read_value = ((uint32_t *)PTR_RA_MEM->PHMEM)[1];

   if (read_value != 0xFFFFFFFFU)
   {
      PHXMEM_ErrCnt += 1U;
   }
}

/** Injects an SM_079 PHMEM single-bit ECC error. */
void SM_079_RA_PHMEM_ECC_SEC_Inject(void)
{
   uint32_t read_value    = 0U;
   volatile RA_SFRS_t *ra = PTR_RA;

   ra->CONTROL.f.ENA                            = 1;
   ra->CONTROL.f.FORCE_PHMEM_AHB                = 1;
   ra->PHMEM_ECC_CONTROL.f.PHMEM_ECC_ENC_BYPASS = 1;

   ((uint32_t *)PTR_RA_MEM->PHMEM)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[3] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->PHMEM)[4] = 0xFFFFFFFFU;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      read_value = ((uint32_t *)PTR_RA_MEM->PHMEM)[1];
      (void)read_value;

      if (ra->PHMEM_ECC_STATUS != (uint16_t)(i + 1U))
      {
         PHXMEM_ErrCnt += 1U;
      }
   }
}

void SM_073_RA_ESTMEM_ECC_DED_Inject(void)
{
   uint32_t read_value    = 0U;
   volatile RA_SFRS_t *ra = PTR_RA;

   /* Enable RA */
   ra->CONTROL.f.ENA = 1;

   /* Force access to PHMEM through the AHB interface. */
   ra->CONTROL.f.FORCE_ESTMEM_3_AHB = 1;

   /* Bypass the ECC encoder so the parity bits remain invalid. */
   ra->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_ENC_BYPASS = 1;

   /* Corrupt a full aligned ECC line using 4x32-bit writes. */
   ((uint32_t *)PTR_RA_MEM->ESTMEM_3)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_3)[3] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_3)[4] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_3)[5] = 0xFFFFFFFFU;

   /* Reading the corrupted location triggers the double-error detect path. */
   read_value = ((uint32_t *)PTR_RA_MEM->ESTMEM_3)[2];
   if (read_value != 0xFFFFFFFFU)
   {
      ESTMEM_ErrCnt += 1U;
   }
}

void SM_073_RA_ESTMEM_ECC_SEC_Inject(void)
{
   volatile uint32_t read_value                       = 0U;
   volatile RA_SFRS_t *ra                             = PTR_RA;
   ra->CONTROL.f.ENA                                  = 1;
   ra->CONTROL.f.FORCE_ESTMEM_1_AHB                   = 1;
   ra->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_ENC_BYPASS = 1;

   ((uint32_t *)PTR_RA_MEM->ESTMEM_1)[0] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_1)[1] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_1)[2] = 0xFFFFFFFFU;
   ((uint32_t *)PTR_RA_MEM->ESTMEM_1)[3] = 0xFFFFFFFFU;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      read_value = ((uint32_t *)PTR_RA_MEM->ESTMEM_1)[0];
      (void)read_value;

      if (ra->ESTMEM_1_ECC_STATUS != (uint16_t)(i + 1U))
      {
         ESTMEM_ErrCnt += 1U;
      }
   }
}
/******************************************************************************
 * Name:  SM_067_Run_Single_Test
 *        Run a single SM_067 test with the provided invalid command.
 *        Writes command to RA CQMEM and checks if INVALID_CONFIG error is detected.
 *
 * Shared Variables: none
 *
 * Parameters:
 *    test_index - Index of the test (0-20)
 *    command    - Pointer to the invalid command array (32 words)
 *
 * Return Value: true if test passed (error was detected), false otherwise
 *
 * Design Information:
 *   Run a single SM_067 test with the provided invalid command.
 *   Writes command to RA CQMEM and checks if INVALID_CONFIG error is detected.
 ******************************************************************************/
/** Injects the SM_067 command-queue invalid-configuration fault. */
void SM_067_RA_CMD_MON_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);
   volatile uint32_t timeout     = RA_SM65_WAIT_TIMEOUT;

   ra->R52_ERR_IRQ_ENA_1.r                                = 0x00000000U; /* Disable all RA error interrupts */
   ra->R52_ERR_IRQ_ENA_1.f.INVALID_CONFIG_IRQ_R52_ERR_ENA = 1U;
   ra->R52_ERR_IRQ_FLAG_1.r                               = 0xFFFFFFFFU;

   /* Ensure the command queue is empty before loading the invalid command. */
   ra->CONTROL.f.ENA         = 0U;
   ra->CONTROL.f.QUEUE_RESET = 1U;
   ra->CONTROL.f.QUEUE_RESET = 0U;
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;
   (void)ra->CONTROL.r;
   for (uint8_t i = 0U; i < SM_067_RA_CMD_SIZE_RUNTIME; i++)
   {
      cqmem_cmd0[i] = 0x00000000U;
   }

   /* Manual 16.67.4.1.2: IN_MNGR_MODE_3_ERR. */
   cqmem_cmd0[0]  = 0x00311F00U; /* IN_SIZE=31, IRQ_EN=1, INPUT_MNGR_MODE=3 */
   cqmem_cmd0[1]  = 0x00000001U; /* IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2]  = 0x80000000U; /* IN_ADDR_START: valid Sysmem 0 address */
   cqmem_cmd0[3]  = 0x00000000U; /* IN_ADDR_STEP */
   cqmem_cmd0[4]  = 0x00000000U; /* PROC_OP_SET=0 */
   cqmem_cmd0[5]  = 0x00000000U; /* OUT_OP_SET=0 */
   cqmem_cmd0[6]  = 0x00000000U;
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00000000U;
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00000000U;
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   ra->CONTROL.f.ENA = 1U;

   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;

   /* Capture whether hardware raised SM67 even if the R52 IRQ is not delivered. */
   while ((ra->R52_ERR_IRQ_FLAG_1.f.INVALID_CONFIG_IRQ_R52_ERR_FLAG == 0U) && (timeout > 0U))
   {
      timeout--;
   }
}

/******************************************************************************
 * Name:  SM_068_Test_Command_Queue_Overflow
 * Description:
 *    Test SM_068_RA_CQ_OVF_MON by following EXACT testability procedure from
 *    Chandra Reference Manual section 16.68.4 Testability.
 *
 *    Steps per manual:
 *    1. Write command from Table 16.58 to CQMEM
 *    2. Reset Command Queue to empty it
 *    3. Disable input stage watchdog (IN_STAGE_WDT_IRQ_R52_ERR_ENA = 0)
 *    4. Enable RA
 *    5. Push same command >129 times (CQ depth 128 + 1)
 *    6. Verify CQ_OVF IRQ is triggered
 *
 * Return Value: None (results stored in SM_068_Test_Results array and globals)
 *
 * Design Information:
 *   This function tests the command queue overflow detection by pushing more commands than the queue can hold
 *****************************************************************************/
/** Injects the SM_068 command-queue overflow fault. */
void SM_068_RA_CQ_OVF_MON_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   cqmem_cmd0[0]  = 0x0021FF00U; /* word 0: IN_SIZE=255, IRQ_EN=1, INPUT_MNGR_MODE=2 */
   cqmem_cmd0[1]  = 0x00000003U; /* word 1: IN_OP_SET=1, IN_FETCH_MODE=1 */
   cqmem_cmd0[2]  = 0x80000000U; /* word 2: IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;
   cqmem_cmd0[4]  = 0x00000000U; /* word 4: PROC_OP_SET=0 */
   cqmem_cmd0[5]  = 0x00000000U; /* word 5: OUT_OP_SET=0 */
   cqmem_cmd0[6]  = 0x00000000U;
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00000000U;
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00000000U;
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;

   /* Step 2: Reset the Command Queue to empty it */
   ra->CONTROL.f.ENA = 0U; /* Disable RA to reset/flush command queue */

   /* Step 3: Disable the input stage watchdog */
   /* R52_ERR_IRQ_ENA_1.IN_STAGE_WDT_IRQ_R52_ERR_ENA = 0 (bit 1) */
   ra->R52_ERR_IRQ_ENA_1.r &= ~(0x00000002U); /* Clear bit 1 to disable IN_STAGE_WDT */

   /* Enable CQ_OVF error detection (bit 4) */
   ra->R52_ERR_IRQ_ENA_1.r |= SM_068_CQ_OVF_ERR_FLAG_MASK; /* Enable CQ_OVF_IRQ */

   /* Step 4: Enable the RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step 5: Push the command defined in '1' to the CQ a number of times greater than 129 */
   /* (CQ depth is 128, so push 130 times to trigger overflow) */
   /* Push the SAME command (slot 0) 130 times */
   for (uint16_t push_count = 0; push_count < 130U; push_count++)
   {
      ra->CMD_PUSH.f.CMD_IDX  = 0U; /* Always push slot 0 (same command) */
      ra->CMD_PUSH.f.CMD_PUSH = 1U;
      /* NO delay - push as fast as possible */
   }
}

/******************************************************************************
 * Name:  SM_070_Test_DECOMP_OVF
 * Description:
 *
 *
 * Return Value: true if error flag is set, false otherwise
 *
 * Design Information:
 *
 ******************************************************************************/
/** Injects the SM_070 datapath preprocessing overflow fault. */
void SM_070_RA_DATAPATH_MON_Inject(void)
{
   volatile RA_SFRS_t *ra         = PTR_RA;
   volatile uint32_t *cqmem_cmd0  = (volatile uint32_t *)(RA_MEM_base);
   volatile uint32_t *const input = RA_Shared_Input_Ptr;

   ra->CONTROL.f.ENA         = 0U;
   ra->R52_ERR_IRQ_FLAG_1.r  = 0xFFFFFFFFU;
   ra->R52_ERR_IRQ_ENA_1.r   = 0x00000000U;
   ra->CONTROL.f.QUEUE_RESET = 1U;
   ra->CONTROL.f.QUEUE_RESET = 0U;
   (void)ra->CONTROL.r;

   ra->CONTROL.r &= ~(0x0FFF0000); /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Step 1: Load 128 complex samples (I,Q pairs) as 24-bit values in 32-bit words.
    * IN_SIZE=31 → (31+1)*4=128 sample words; each word holds one 24-bit sample in bits[23:0]. */
   for (uint32_t i = 0U; i < 64U; i++)
   {
      input[(i * 2U) + 0U] = 0x007FFFFFU; /* I: max positive 24-bit = 2^23-1 */
      input[(i * 2U) + 1U] = 0x007FFFFFU; /* Q: max positive 24-bit = 2^23-1 */
   }

   ra->CONTROL.f.ENA = 0U;
   (void)ra->CONTROL.r;

   ra->R52_ERR_IRQ_ENA_1.r |= RA_R52_ERR_IRQ_ENA_1_PREPROC_OVF_IRQ_R52_ERR_ENA_msk;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   cqmem_cmd0[0] = 0x03611F00U; /* word 0: IN_SIZE=31, IRQ_EN=1, INPUT_MNGR_MODE=2, OUTPUT_MNGR_MODE=1, FFT_TYPE=3 */
   cqmem_cmd0[1] = 0x00000001U; /* word 1: IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2] = (uint32_t)&RA_Shared_Input_Buffer[0]; /* word 2: IN_ADDR_START */
   cqmem_cmd0[3] = 0x00000000U;
   cqmem_cmd0[4] = 0x10000041U; /* word 4: PROC_OP_SET=1, PROC_DPMEM_BANK_SRC=0, PROC_DPMEM_BANK_DST=1, PREP_FINAL_SCALING_MSB=1 */
   cqmem_cmd0[5] = 0x00000000U;
   cqmem_cmd0[6] = 0x00000000U;
   cqmem_cmd0[7] = 0x00000000U;
   cqmem_cmd0[8] = 0x0902001FU;  /* word 8: PREP_BLOCK_SIZE=31, PREP_WIND_BYPASS=1, PREP_SUM_BYPASS=1, PREP_CMP_BYPASS=1 */
   cqmem_cmd0[9] = 0x10001000U;  /* word 9: PREP_PHASE_BYPASS=1, PREP_INDEX_BYPASS=1 */
   cqmem_cmd0[10] = 0x00800000U; /* word 10: POSP_BYPASS=1 */
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.r &= ~(0x0FFF0000); /* Force CQMEM to use AHB bus for input data */
   (void)ra->CONTROL.r;

   ra->CONTROL.f.ENA       = 1U;
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;

   /* Wait until the PREPROC_OVF event is generated before allowing another injection. */
   volatile uint32_t timeout = 1000000U;
   while ((ra->R52_ERR_IRQ_FLAG_1.f.PREPROC_OVF_IRQ_R52_ERR_FLAG == 0U) && (timeout > 0U))
   {
      timeout--;
   }

   ra_sm70_event_observed = (uint8_t)(timeout > 0U);

   /* Do not start the next injection until the RA error ISR has cleared this flag. */
   while ((ra->R52_ERR_IRQ_FLAG_1.f.PREPROC_OVF_IRQ_R52_ERR_FLAG != 0U) && (timeout > 0U))
   {
      timeout--;
   }
}

/******************************************************************************
 * Name:  SM_072_Check_RA_EST_MUX_MON
 * Description:
 *    Helper function to check if EST_MUX error flag is set in RA for Estimator 1.
 *    Concurrent write/read access to estimator triggers this error.
 *
 * Return Value: true if error flag is set, false otherwise
 *
 * Design Information:
 *   Per Chandra Reference Manual 16.72.3, EST_MUX errors are reported in
 *   R52_ERR_IRQ_FLAG_2 register (EST_MUX_1_IRQ_R52_ERR_FLAG at bit 0).
 ******************************************************************************/
void SM_072_RA_EST_MUX_MON_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   RA_Clear_Shared_Buffers();

   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   (void)ra->CONTROL.r;

   cqmem_cmd0[0]  = 0x0371FF00U; /* word 0: IN_SIZE=255, IRQ_EN=1, INPUT_MNGR_MODE=3, OUTPUT_MNGR_MODE=1, FFT_TYPE=3 */
   cqmem_cmd0[1]  = 0x00000001U; /* word 1: IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2]  = (uint32_t)RA_Shared_Input_Ptr; /* word 2: IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;
   cqmem_cmd0[4]  = 0x00000001U; /* word 4: PROC_OP_SET=1 */
   cqmem_cmd0[5]  = 0x00000000U; /* word 5: OUT_OP_SET=0 */
   cqmem_cmd0[6]  = 0x00000000U;
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00800000U; /* word 8: PREP_BYPASS=1 */
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00800000U; /* word 10: POSP_BYPASS=1 */
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00080087U; /* word 12: EST_1_INIT=1, VECTOR=1, COHERENT=1, WR_ENA=1, RD_ENA=1 */
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   /* Enable the RA */
   ra->CONTROL.f.ENA = 1U;
   (void)ra->CONTROL.r;

   /* Push the command to trigger execution and concurrent access */
   ra->CMD_PUSH.f.CMD_IDX  = 0U; /* Push slot 0 (our configured command) */
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
}

/******************************************************************************
 * Name:  SM_076_Test_DPMEM_MUX_ERR
 * Description:
 *
 *
 * Return Value: true if error flag is set, false otherwise
 *
 * Design Information:
 *
 ******************************************************************************/
void SM_076_RA_MEM_ACCESS_MON_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   ra->R52_ERR_IRQ_FLAG_1.r = 0xFFFFFFFFU;
   ra->R52_ERR_IRQ_ENA_1.r  = 0x00000000U;
   ra->CONTROL.f.ENA        = 0U;
   (void)ra->CONTROL.r;

   RA_Clear_Shared_Buffers();

   /* Reset queue */
   ra->CONTROL.f.QUEUE_RESET = 1U;
   ra->CONTROL.f.QUEUE_RESET = 0U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   cqmem_cmd0[0]  = 0x0321FF00U;                   /* IN_SIZE=255, IRQ_EN=1, INPUT_MNGR_MODE=2, FFT_TYPE=3 */
   cqmem_cmd0[1]  = 0x00000001U;                   /* IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2]  = (uint32_t)RA_Shared_Input_Ptr; /* IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;
   cqmem_cmd0[4]  = 0x00000051U; /* PROC_OP_SET=1, PROC_DPMEM_BANK_SRC=DST=1 */
   cqmem_cmd0[5]  = 0x00000000U; /* OUT_OP_SET=0 */
   cqmem_cmd0[6]  = 0x00000000U;
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00000000U;
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00000000U;
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   ra->R52_ERR_IRQ_ENA_1.f.DPMEM_MUX_ERR_IRQ_R52_ERR_ENA = 1U;
   ra->CONTROL.f.ENA                                     = 1U;

   /* Push command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;

   /* Wait for error */
   volatile uint32_t timeout = 1000000U;

   while (timeout--)
   {
      if (ra->R52_ERR_IRQ_FLAG_1.f.DPMEM_MUX_ERR_IRQ_R52_ERR_FLAG)
      {
         break;
      }
   }
}
/******************************************************************************
 * Name:  SM_077_Test_RA_OUT_ADDR_MONITOR
 * Description:
 *
 *
 * Return Value: true if error flag is set, false otherwise
 *
 * Design Information:
 *   Per Chandra Reference Manual 16.72.3, EST_MUX errors are reported in
 *   R52_ERR_IRQ_FLAG_2 register (EST_MUX_1_IRQ_R52_ERR_FLAG at bit 0).
 ******************************************************************************/
void SM_077_RA_OUT_ADDR_MONITOR_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   /*Step1: Enable the configured region by setting OUT_ADDR_RANGE_CONTROL.OUT_ADDR_ACTIVE_REGIONS to 1.*/
   ra->OUT_ADDR_RANGE_CONTROL = 1U;
   (void)ra->OUT_ADDR_RANGE_CONTROL;

   /* Step 2: Enable Interrupt bit for SM77 */
   ra->R52_ERR_IRQ_ENA_2.r |= RA_R52_ERR_IRQ_ENA_2_OUT_ADDR_RANGE_IRQ_R52_ERR_ENA_msk;

   /*Step 3 : Write the command*/
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   cqmem_cmd0[0]  = 0x0061FF00U; /* word 0: IN_SIZE=255, IRQ_EN=1, INPUT_MNGR_MODE=2, OUTPUT_MNGR_MODE=1 */
   cqmem_cmd0[1]  = 0x00000001U; /* word 1: IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2]  = 0x80000000U; /* word 2: IN_ADDR_START */
   cqmem_cmd0[3]  = 0x00000000U;
   cqmem_cmd0[4]  = 0x00000000U; /* word 4: PROC_OP_SET=0 */
   cqmem_cmd0[5]  = 0x00000001U; /* word 5: OUT_OP_SET=1 */
   cqmem_cmd0[6]  = 0x82002000U; /* word 6: OUT_ADDR_START, outside configured valid range */
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00000000U;
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00000000U;
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   /* Step4: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step5: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
}

/******************************************************************************
 * Name:  SM_080_Test_SM_080_RA_SLV_ERR_MON
 * Description:
 *
 *
 * Return Value: true if error flag is set, false otherwise
 *
 * Design Information:
 *   Per Chandra Reference Manual 16.72.3, EST_MUX errors are reported in
 *   R52_ERR_IRQ_FLAG_2 register (EST_MUX_1_IRQ_R52_ERR_FLAG at bit 0).
 ******************************************************************************/
/** Injects the SM_080 AXI slave response error fault. */
void SM_080_RA_SLV_ERR_MON_Inject(void)
{
   volatile RA_SFRS_t *ra        = PTR_RA;
   volatile uint32_t *cqmem_cmd0 = (volatile uint32_t *)(RA_MEM_base);

   /* Isolate SM80 from the input-stage watchdog while the slave error is injected. */
   ra->R52_ERR_IRQ_ENA_1.r                                 = 0x00000000U;
   ra->R52_ERR_IRQ_ENA_1.f.AXI_IN_RESP_ERR_IRQ_R52_ERR_ENA = 1U;
   ra->R52_ERR_IRQ_FLAG_1.r                                = 0xFFFFFFFFU;

   /* The previous injection may have left the command queue stalled. */
   ra->CONTROL.f.ENA         = 0U;
   ra->CONTROL.f.QUEUE_RESET = 1U;
   ra->CONTROL.f.QUEUE_RESET = 0U;
   (void)ra->CONTROL.r;

   /*Step 1 : Write the command*/
   ra->CONTROL.f.FORCE_CQMEM_AHB = 1U;

   cqmem_cmd0[0]  = 0x00210300U; /* word 0: IN_SIZE=3, IRQ_EN=1, INPUT_MNGR_MODE=2 */
   cqmem_cmd0[1]  = 0x00000001U; /* word 1: IN_OP_SET=1, IN_FETCH_MODE=0 */
   cqmem_cmd0[2]  = 0x00000000U; /* word 2: invalid/unmapped IN_ADDR_START to trigger AXI IN response error */
   cqmem_cmd0[3]  = 0x00000000U;
   cqmem_cmd0[4]  = 0x00000000U; /* word 4: PROC_OP_SET=0 */
   cqmem_cmd0[5]  = 0x00000000U; /* word 5: OUT_OP_SET=0 */
   cqmem_cmd0[6]  = 0x00000000U;
   cqmem_cmd0[7]  = 0x00000000U;
   cqmem_cmd0[8]  = 0x00000000U;
   cqmem_cmd0[9]  = 0x00000000U;
   cqmem_cmd0[10] = 0x00000000U;
   cqmem_cmd0[11] = 0x00000000U;
   cqmem_cmd0[12] = 0x00000000U;
   cqmem_cmd0[13] = 0x00000000U;
   cqmem_cmd0[14] = 0x00000000U;
   cqmem_cmd0[15] = 0x00000000U;

   ra->CONTROL.f.FORCE_CQMEM_AHB = 0U;
   (void)ra->CONTROL.r;

   /* Step2: Enable RA */
   ra->CONTROL.f.ENA = 1U;

   /* Step3: Push Command */
   ra->CMD_PUSH.f.CMD_IDX  = 0U;
   ra->CMD_PUSH.f.CMD_PUSH = 1U;
}

/** Selects the requested SEC or DED injection for SM_069 CQMEM ECC. */
void SM_069_RA_CQMEM_ECC_Inject(void)
{
   if (ra_ecc_test_enable == RA_ECC_TEST_DED)
   {
      SM_069_RA_CQMEM_ECC_DED_Inject();
   }
   else
   {
      SM_069_RA_CQMEM_ECC_SEC_Inject();
   }
}

/** Selects the requested SEC or DED injection for SM_075 IDXMEM ECC. */
void SM_075_RA_IDXMEM_ECC_Inject(void)
{
   if (ra_ecc_test_enable == RA_ECC_TEST_DED)
   {
      SM_075_RA_IDXMEM_ECC_DED_Inject();
   }
   else
   {
      SM_075_RA_IDXMEM_ECC_SEC_Inject();
   }
}

/** Selects the requested SEC or DED injection for SM_079 PHMEM ECC. */
void SM_079_RA_PHMEM_ECC_Inject(void)
{
   if (ra_ecc_test_enable == RA_ECC_TEST_DED)
   {
      SM_079_RA_PHMEM_ECC_DED_Inject();
   }
   else
   {
      SM_079_RA_PHMEM_ECC_SEC_Inject();
   }
}

/** Selects the requested SEC or DED injection for SM_081 WCMEM ECC. */
void SM_081_RA_WCMEM_ECC_Inject(void)
{
   if (ra_ecc_test_enable == RA_ECC_TEST_DED)
   {
      SM_081_RA_WCMEM_ECC_DED_Inject();
   }
   else
   {
      SM_081_RA_WCMEM_ECC_SEC_Inject();
   }
}

/** Selects the requested SEC or DED injection for SM_073 ESMEM ECC. */
void SM_073_RA_ESTMEM_ECC_Inject(void)
{
   if (ra_ecc_test_enable == RA_ECC_TEST_DED)
   {
      SM_073_RA_ESTMEM_ECC_DED_Inject();
   }
   else
   {
      SM_073_RA_ESTMEM_ECC_SEC_Inject();
   }
}

   #endif /* UNIT_TEST */
/** Executes the selected SQT RA fault injection up to the configured repeat count. */
void RA_Fault_Injection_Execute(void)
{
   ra_fault_handler_t selected_handler = NULL;
   static uint8_t loop_cntr            = 0U;

   if (ra_sm_enable >= SM_MAX)
   {
      return;
   }

   selected_handler = ra_fault_handlers[ra_sm_enable];
   if ((selected_handler != NULL) && (ra_fault_injection_count < RA_MULTI_INJECT_COUNT))
   {
      if (RA_Inj_Type == 1U && (loop_cntr % 5 == 0U))
      {
         selected_handler();
   #ifndef UNIT_TEST
         if ((ra_sm_enable != SM_070_RA_DATAPATH_MON) || (ra_sm70_event_observed != 0U))
   #endif
         {
            ra_fault_injection_count++;
         }
      }
      else if (RA_Inj_Type == 0U)
      {
         selected_handler();

   #ifndef UNIT_TEST
         if ((ra_sm_enable != SM_070_RA_DATAPATH_MON) || (ra_sm70_event_observed != 0U))
   #endif
         {
            ra_fault_injection_count++;
         }
      }

      loop_cntr++;
   }
   else
   {
      ra_sm_enable             = SM_MAX;
      ra_fault_injection_count = 0U;
      RA_Inj_Type              = 0U;
      loop_cntr                = 0U;
   }
}

   #pragma clang optimize on
#endif
