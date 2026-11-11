/*===========================================================================*/
/**
 * @file dss_ecc_parity.c
 *
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "reuse.h"
#include "sysctrl_sfrs.h"

#ifndef UNIT_TEST
   #include <xtensa/tie/xt_core.h>
   #include <xtensa/tie/xt_ioports.h>
   #include <xtensa/tie/xt_memerr.h>
   #include <xtensa/xtruntime.h>
#endif

#include "chandra_sfrs_base.h"
#include "dss_ecc_parity.h"
#include "ra_mem_sfrs.h"
#include "ra_sfrs.h"

/* ========================================================================== *
 * Macros
 * ========================================================================== */

#define SYSCTRL           ((volatile SYSCTRL_SFRS_t *)SYSCTRL_base)
#define AXI_ECC_ADDRESS   (0x00103034)
#define ATTEMP_COUNT      (3U)
#define ESTMEM_WORD_COUNT (2048U)
#define CSRPCTL_ENAB      (1U << 0)

#define DSP_FUSA_IRQ_ENA_ADDR        0x84401014u
#define FUSA_IRQ_PARITH_BIT          (0U)
#define FUSA_IRQ_ERROR_CORRECTED_BIT (1U)
#define FUSA_IRQ_FIV_BIT             (2U)
#define FUSA_IRQ_FINSV_BIT           (3U)
#define FUSA_IRQ_PFATAL_ERROR_BIT    (4U)

#define SHIFT_ERRENAB 8u
#define SHIFT_ERRTEST 9u
#define SHIFT_DATAEXC 10u
#define SHIFT_INSTEXC 11u

#ifndef DSS_ECC_IRQ_ENABLE
   #define DSS_ECC_IRQ_ENABLE()                                                                                                   \
      (*(DSP_FUSA_IRQ_ENA) |= ((1U << FUSA_IRQ_ERROR_CORRECTED_BIT) | (1U << FUSA_IRQ_FIV_BIT) | (1U << FUSA_IRQ_FINSV_BIT)))
#endif
#ifndef DSS_ECC_DRAM_PTR
   #define DSS_ECC_DRAM_PTR ((int32_t *)0x84022000U)
#endif
#ifndef DSS_ECC_IRAM_PTR
   #define DSS_ECC_IRAM_PTR ((int32_t *)0x84040500U)
#endif
#ifndef UNIT_TEST
   #define PTR_RA     ((volatile RA_SFRS_t *)RA_base)
   #define PTR_RA_MEM ((volatile RA_MEM_SFRS_t *)RA_MEM_base)
#endif
#define CSRPCTL_ENABLE            (1U << 0)
#define CSRPCTL_TEST              (1U << 1)
#define CSRPCTL_PARITY            (1U << 8)
#define CSRPCTL_TEST_WRONG_PARITY (CSRPCTL_TEST | CSRPCTL_PARITY)
/*===========================================================================*
 * external Const Object Declarations
 *===========================================================================*/

/* ========================================================================== *
 * Local typedefs
 * ========================================================================== */
/* ========================================================================== *
 * Global Variables
 * ========================================================================== */
volatile uint8_t Axi_Ecc_Mon_Flag    = CODED_FALSE; /* Variable to hold dsp axi status */
volatile uint8_t Csr_Parity_Mon_Flag = CODED_FALSE; /* Variable to hold dsp csr parity status */

/* Register bank pointer for DSP FUSA IRQ enable (forwards ErrorCorrected to R52) */
volatile uint32_t *const DSP_FUSA_IRQ_ENA = (volatile uint32_t *)DSP_FUSA_IRQ_ENA_ADDR;
volatile EccTest_t test_dsp               = ECC_TEST_NONE;
volatile uint8_t dsp_ecc_parity_test_flag = 0;
/* ========================================================================== *
 * Internal Function Declarations
 * ========================================================================== */
bool Enable_Axi_Ecc(void);

#ifndef UNIT_TEST
static void Estmem_Force_Ahb(const bool enable_ahb);
static void Estmem_Init_All(void);
static void Estmem_Reset_Sec_Counters(void);
static void Estmem_Clear_Flags(void);
static void Estmem_Enable_Irqs(void);
#endif
static void Ecc_Interrupt_Init(void);

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/**
 *  @b Description
 *  @n
 *      Handler for Enabling ECC for AXI.
 *
 *  @retval
 *
 */
bool Enable_Axi_Ecc(void)
{
   bool result         = true;
   uint32_t axi_ecc_en = 0U; /* Variable to hold AXI ECC enable status */
   uint32_t axi_val;

   /* Enable AXI_ECC */
   axi_val = 1U;

   /* Synchronize and write updated value */
   XT_ISYNC();
   XT_WER(axi_val, AXI_ECC_ADDRESS);
   XT_ISYNC();

   /* Read the axi ecc address to check the updated value */
   axi_ecc_en = XT_RER(AXI_ECC_ADDRESS);

   if (axi_ecc_en != 1U)
   {
      result = false; // Error handling will be added
   }
   return result;
}

/******************************************************************************
 * Name:  Enable_Dsp_Ecc
 *    This function enables ECC for DSP
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Enables ECC for DSP memory
 *
 *
 ******************************************************************************/
void Enable_Dsp_Ecc(void)
{
   bool dsp_ecc_status = false;
   for (uint8_t attempt = 0; (attempt < ATTEMP_COUNT && !dsp_ecc_status); ++attempt)
   {
      dsp_ecc_status = Enable_Axi_Ecc();
   }

   if (!dsp_ecc_status)
   {
      Axi_Ecc_Mon_Flag = CODED_TRUE;
   }
}

/******************************************************************************
 * Name:  Enable_Csrpctl_Parity
 *    This function enables Parity for CSR.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Enables Parity for CSR.
 *
 *
 ******************************************************************************/
bool Enable_Csrpctl_Parity(void)
{
   bool result            = true;
   uint32_t csr_parity_en = 0U; /* Variable to hold CSR parity enable status */
   uint32_t csr_val;

   /* Read current CSR parity control register value */
   csr_val = XT_RSR_CSRPCTL();

   /* Set bit 0 'Enable' without altering other bits */
   csr_val |= CSRPCTL_ENAB;

   /* Synchronize and write updated value */
   XT_ISYNC();
   XT_WSR_CSRPCTL(csr_val);
   XT_ISYNC();

   /* Read the csr parity control register to check the updated value */
   csr_parity_en = XT_RSR_CSRPCTL();

   if ((csr_parity_en & CSRPCTL_ENAB) == 0U)
   {
      result = false;
   }
   return result;
}

/******************************************************************************
 * Name:  Enable_Dsp_Parity
 *    This function enables Parity for DSP.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Enables Parity for DSP.
 *
 *
 ******************************************************************************/
void Enable_Dsp_Parity(void)
{
   bool csr_parity_enabled = false; /* Is CSR parity successfully enabled? */

   csr_parity_enabled = Enable_Csrpctl_Parity();

   if (!csr_parity_enabled)
   {
      Csr_Parity_Mon_Flag = CODED_TRUE;
   }
}

/******************************************************************************
 * Name:  Get_Axi_Ecc_Enable_Err_state
 *    This function gets the AXI ECC Enable error state.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Gets the AXI ECC Enable error state.
 *
 *
 ******************************************************************************/
uint8_t Get_Axi_Ecc_Enable_Err_state(void)
{
   return Axi_Ecc_Mon_Flag;
}

/******************************************************************************
 * Name:  Get_Csr_Parity_Enable_Err_state
 *    This function gets the CSR Parity Enable error state.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: uint8_t
 *
 * Design Information:
 *   Enables Parity for CSR.
 *
 *
 ******************************************************************************/
uint8_t Get_Csr_Parity_Enable_Err_state(void)
{
   return Csr_Parity_Mon_Flag;
}

#ifndef UNIT_TEST
static void Estmem_Force_Ahb(const bool enable_ahb)
{
   const uint8_t force_val = enable_ahb ? 1U : 0U;

   PTR_RA->CONTROL.f.FORCE_ESTMEM_1_AHB = force_val;
   PTR_RA->CONTROL.f.FORCE_ESTMEM_2_AHB = force_val;
   PTR_RA->CONTROL.f.FORCE_ESTMEM_3_AHB = force_val;
   PTR_RA->CONTROL.f.FORCE_ESTMEM_4_AHB = force_val;
}

static void Estmem_Init_All(void)
{
   for (uint32_t i = 0U; i < ESTMEM_WORD_COUNT; i++)
   {
      PTR_RA_MEM->ESTMEM_1[i] = 0x00000000U;
      PTR_RA_MEM->ESTMEM_2[i] = 0x00000000U;
      PTR_RA_MEM->ESTMEM_3[i] = 0x00000000U;
      PTR_RA_MEM->ESTMEM_4[i] = 0x00000000U;
   }
}

static void Estmem_Reset_Sec_Counters(void)
{
   PTR_RA->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_SEC_CNT_CLR = 1;
   PTR_RA->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_SEC_CNT_CLR = 0;
   PTR_RA->ESTMEM_2_ECC_CONTROL.f.ESTMEM_2_ECC_SEC_CNT_CLR = 1;
   PTR_RA->ESTMEM_2_ECC_CONTROL.f.ESTMEM_2_ECC_SEC_CNT_CLR = 0;
   PTR_RA->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_SEC_CNT_CLR = 1;
   PTR_RA->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_SEC_CNT_CLR = 0;
   PTR_RA->ESTMEM_4_ECC_CONTROL.f.ESTMEM_4_ECC_SEC_CNT_CLR = 1;
   PTR_RA->ESTMEM_4_ECC_CONTROL.f.ESTMEM_4_ECC_SEC_CNT_CLR = 0;
}

static void Estmem_Clear_Flags(void)
{
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_1_IRQ_R52_FUSA_FLAG = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_1_IRQ_R52_FUSA_FLAG     = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_2_IRQ_R52_FUSA_FLAG = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_2_IRQ_R52_FUSA_FLAG     = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_3_IRQ_R52_FUSA_FLAG = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_3_IRQ_R52_FUSA_FLAG     = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_4_IRQ_R52_FUSA_FLAG = 1;
   PTR_RA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_4_IRQ_R52_FUSA_FLAG     = 1;
}

static void Estmem_Enable_Irqs(void)
{
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_SEC_CNT_ESTMEM_1_IRQ_R52_FUSA_ENA = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_DED_ESTMEM_1_IRQ_R52_FUSA_ENA     = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_SEC_CNT_ESTMEM_2_IRQ_R52_FUSA_ENA = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_DED_ESTMEM_2_IRQ_R52_FUSA_ENA     = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_SEC_CNT_ESTMEM_3_IRQ_R52_FUSA_ENA = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_DED_ESTMEM_3_IRQ_R52_FUSA_ENA     = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_SEC_CNT_ESTMEM_4_IRQ_R52_FUSA_ENA = 1;
   PTR_RA->R52_FUSA_IRQ_ENA.f.ECC_DED_ESTMEM_4_IRQ_R52_FUSA_ENA     = 1;
}

void RA_ESTMEM_ECC_Enable(void)
{
   static bool estmem_initialized = false;

   if (!estmem_initialized)
   {
      /* Force access to ESTMEM through the AHB interface for initialization. */
      Estmem_Force_Ahb(true);
      Estmem_Init_All();

      /* Ensure all memory writes are committed before releasing AHB control. */
      XT_MEMW();
      XT_ISYNC();

      Estmem_Force_Ahb(false);

      /* Ensure pipeline sees updated configuration after releasing AHB force. */
      XT_ISYNC();

      estmem_initialized = true;
   }

   Estmem_Reset_Sec_Counters();
   Estmem_Clear_Flags();

   /* Ensure all register writes are committed before enabling interrupts. */
   XT_MEMW();
   Estmem_Enable_Irqs();
}
#endif
/******************************************************************************
 * Name:  Ecc_Interrupt_Init
 *    This function enables ECC interrupt handling for DSP.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Enables Ecc interrupt.
 *
 *
 ******************************************************************************/
static void Ecc_Interrupt_Init(void)
{
   /* Enable forwarding ErrorCorrected signal to R52 (IRQ #72) */
   DSS_ECC_IRQ_ENABLE();
}

/******************************************************************************
 * Name:  Inject_Csr_Parity_Error
 *    This function injects a Parity error for CSR.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Injects a Parity error for CSR.
 *
 *
 ******************************************************************************/
void Inject_Csr_Parity_Error(void)
{
   uint32_t value;
   /* Enable Test mode + Wrong Parity */
   XT_ISYNC();
   XT_WSR_CSRPCTL(CSRPCTL_TEST_WRONG_PARITY);
   XT_ISYNC();

   /* Read protected register */
   value = XT_RSR_MEMCTL();
   /* Re-enable wrong parity injection */
   XT_ISYNC();
   XT_WSR_CSRPCTL(CSRPCTL_TEST_WRONG_PARITY);
   XT_ISYNC();
   /* Write protected register using bad parity */
   XT_WSR_MEMCTL(value);
   XT_ESYNC();
   /* Enable CSR parity checking */
   XT_ISYNC();
   XT_WSR_CSRPCTL(CSRPCTL_ENABLE);
   XT_ISYNC();

   value = XT_RSR_MEMCTL();

   (void)value;
}
/******************************************************************************
 * Name:  Inject_Correctable_Error
 *    This function injects a correctable ECC error into DRAM.
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Injects a correctable ECC error into DRAM.
 *
 *
 ******************************************************************************/
void Inject_Correctable_Error(int32_t *addr)
{
   uint32_t val, data;
   volatile int32_t aux;
   volatile int32_t *ptr;
   volatile int32_t bit;
   ptr = addr;

   /* Read current value at address */
   data = *ptr;

   /* Select a random bit to flip (0-31) */
   bit = (int32_t)(XT_RSR_CCOUNT() % 32);

   /* Toggle the selected bit */
   data ^= (1 << bit);

   /* Disable memory error checking (MemErrEnab = 0) */
   val = XT_RSR_MESR();
   val &= ~(1 << 8);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();

   /* Enable error test mode (ErrTest = 1) */
   val = XT_RSR_MESR();
   val |= (1 << 9);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();

   XT_MEMW();
   XT_EXTW();

   /* Read to ensure cache coherency */
   aux = ptr[0];

   /* Write the corrupted data (with flipped bit) */
   *ptr = data;

   XT_MEMW();
   XT_EXTW();

   /* Disable error test mode (ErrTest = 0) */
   val = XT_RSR_MESR();
   val &= ~(1 << 9);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();

   /* Re-enable memory error checking (MemErrEnab = 1) */
   val = XT_RSR_MESR();
   val |= (1 << 8);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();

   XT_MEMW();

   /* Read back to trigger error detection and correction */
   aux = ptr[0];

   /* Prevent compiler optimization of unused variable */
   (void)aux;
}

/******************************************************************************
 * Name:  Inject_Uncorrectable_Error
 *    This function injects an uncorrectable ECC error into DRAM.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Injects an uncorrectable ECC error into DRAM.
 *
 *
 ******************************************************************************/
void Inject_Uncorrectable_Error(int32_t *addr)
{
   uint32_t val, data;
   volatile int32_t aux;
   volatile int32_t *ptr;
   uint32_t bit1;
   uint32_t bit2;
   ptr = addr;
   /* Read current value */
   data = *ptr;
   /* Select two different bits */
   bit1 = (XT_RSR_CCOUNT() % 32U);
   bit2 = ((bit1 + 7U) % 32U);
   /* Create double-bit corruption */
   data ^= (1UL << bit1);
   data ^= (1UL << bit2);
   /* Disable ECC checking */
   val = XT_RSR_MESR();
   val &= ~(1U << SHIFT_ERRENAB);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();
   XT_ISYNC();
   /* Enable ErrTest mode */
   val = XT_RSR_MESR();
   val |= (1U << SHIFT_ERRTEST);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();
   XT_MEMW();
   XT_EXTW();
   aux = ptr[0];
   /* Write corrupted data */
   *ptr = data;
   XT_MEMW();
   XT_EXTW();
   /* Disable ErrTest */
   val = XT_RSR_MESR();
   val &= ~(1U << SHIFT_ERRTEST);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();
   /* Re-enable ECC checking */
   val = XT_RSR_MESR();
   val |= (1U << SHIFT_ERRENAB);
   XT_ISYNC();
   XT_WSR_MESR(val);
   XT_ISYNC();
   XT_MEMW();
   /* Trigger ECC evaluation */
   aux = ptr[0];
   (void)aux;
}

/******************************************************************************
 * Name:  Test_Dsp_Ecc_Parity_Error
 *    This function tests ECC error injection for DRAM, IRAM, and CSR parity.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Tests ECC error injection for DRAM, IRAM, and CSR parity.
 *
 *
 ******************************************************************************/
void Test_Dsp_Ecc_Parity_Error(void)
{
   if (dsp_ecc_parity_test_flag == 1U)
   {
      int32_t *ptr = NULL;
      /* Initialize ECC infrastructure */
      Ecc_Interrupt_Init();
      switch (test_dsp)
      {
         case ECC_TEST_DRAM_SEC:
            test_dsp = ECC_TEST_NONE;
            ptr      = DSS_ECC_DRAM_PTR;
            *ptr     = 0xCAFEBEEFU;
            Inject_Correctable_Error(ptr);
            break;
         case ECC_TEST_DRAM_DED:
            test_dsp = ECC_TEST_NONE;
            ptr      = DSS_ECC_DRAM_PTR;
            *ptr     = 0xCAFEBEEFU;
            Inject_Uncorrectable_Error(ptr);
            break;
         case ECC_TEST_IRAM_SEC:
            test_dsp = ECC_TEST_NONE;
            ptr      = DSS_ECC_IRAM_PTR;
            *ptr     = 0xCAFEBEEFU;
            Inject_Correctable_Error(ptr);
            break;
         case ECC_TEST_IRAM_DED:
            test_dsp = ECC_TEST_NONE;
            ptr      = DSS_ECC_IRAM_PTR;
            *ptr     = 0xCAFEBEEFU;
            Inject_Uncorrectable_Error(ptr);
            break;
         case ECC_TEST_CSR_PARITY:
            test_dsp = ECC_TEST_NONE;
            Inject_Csr_Parity_Error();
            break;
         default:
            break;
      }
      dsp_ecc_parity_test_flag = 0U;
   }
}

/*===========================================================================*
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- ------
\*===========================================================================*/
