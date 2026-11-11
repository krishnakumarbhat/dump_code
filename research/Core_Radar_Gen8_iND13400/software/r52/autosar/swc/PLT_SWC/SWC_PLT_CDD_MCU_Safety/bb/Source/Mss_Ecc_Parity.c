/*===========================================================================*\
 * FILE: Mss_Ecc_Parity.c
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
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "Std_Types.h"
#include <stdint.h>
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Mss_Ecc_Parity.h"
#include "Os.h"
#include "artie_sfrs.h"
#include "chandra_sfrs_base.h"
#ifndef UNIT_TEST
   #include "artie_sfrs.h"
   #include "fusa_ctrl_sfrs.h"
   #include "sysmem_sfrs.h"
   #define SYSMEM ((volatile SYSMEM_SFRS_t *)SYSMEM_base)
   #define FUSA_CTRL                                                                                                              \
      ((volatile FUSA_CTRL_SFRS_t *)FUSA_CTRL_base) /* polyspace MISRA-C-2023:11.4 "Pointer-integer conversions required for      \
                                                       memory-mapped hardware register access" */
   #define ARTIE                                                                                                                  \
      ((volatile ARTIE_SFRS_t *)ARTIE_base) /* polyspace MISRA-C-2023:11.4 "Pointer-integer conversions required for              \
                                               memory-mapped hardware register access" */
#endif
/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

#if (ENABLE_SQT_TEST_STUBS == STD_ON) || defined(UNIT_TEST)
void SYSMEM_ECC_Test_Inject_SEC(void);
void SYSMEM_ECC_Test_Inject_DED(void);
void Fault_Injection_Test_Mss_Tcm_Cache(void);
#endif

#if (defined(ENABLE_SQT_ARTIEMEM_FAULT) && !defined(UNIT_TEST))
void ARTIEMEM_SEC_Fault_Injection(void);
void ARTIEMEM_DED_Fault_Injection(void);
#endif

#define ARTIE_REG_BASE_ADDR ARTIE_base
#ifndef UNIT_TEST
   #define ARTIE_REGS               ((volatile ARTIE_SFRS_t *)ARTIE_REG_BASE_ADDR)
   #define ARTIE_ADDR64             ((volatile uint64_t *)0x91800030ULL)
   #define ARTIE_ADDR64_DED         ((volatile uint64_t *)0x91800030ULL)
   #define ARTIE_DATA64             (0x0080020000000000ULL)
   #define ARTIE_DATA64_DED         (0x0080020000000001ULL)
   #define ARTIE_ECC_ENCODER_BYPASS (1u << 0)
   #define ARTIE_CTL_SNAP_SEC_CNT   (1u << 16)
   #define ARTIE_CLR_ECC_SEC_CNT    (1u << 0)
   #define SET_SEC_THRESHOLD        (0u)
#endif
/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/

#if (ENABLE_SQT_TEST_STUBS == STD_ON) && !defined(UNIT_TEST)
volatile uint8_t sysmem_sec_ecc_port0          = 0;
volatile uint8_t sysmem_sec_ecc_port1          = 0;
volatile uint8_t sysmem_ded_ecc_port0          = 0;
volatile uint8_t sysmem_ded_ecc_port1          = 0;
volatile uint8_t test_tcm                      = 0u;
volatile uint32_t Max_TimeOut_Milliseconds_Dss = 3000;
volatile uint32_t Timeout_Cnt_Dss              = 0U;
volatile uint8_t Result_Dss                    = TRUE;
#endif

static volatile bool Ecc_Enable_Status_Flag = false;

#if (defined(ENABLE_SQT_ARTIEMEM_FAULT) && !defined(UNIT_TEST))
volatile uint32_t Max_TimeOut_Milliseconds_Dss = 3000;
volatile uint32_t Timeout_Cnt_Dss              = 0U;
volatile uint8_t Result_Dss                    = TRUE;
volatile uint8_t ARTIEMEM_ErrCnt               = 0;
volatile uint8_t SEC_FltNum                    = 0;
volatile uint8_t DED_FltNum                    = 0;
#endif
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/* NOTE: `SYSMEM_base` and `SYSMEM` are provided by `sysmem_sfrs.h` in non-UNIT_TEST builds. */
#if (ENABLE_SQT_TEST_STUBS == STD_ON) && !defined(UNIT_TEST)
   /* Bit field definitions */
   #define STS_P0_ECC_SEC_CNT_MASK         (0xFFFFu)
   #define STS_P1_ECC_SEC_CNT_MASK         (0xFFFFu)
   #define SYSMEM_PORT0_SEC_DED_STAT1_ADDR (*((volatile uint32_t *)(SYSMEM_base + 0x18u)))
   /* Port1 register block starts at 0xF4 offset from port0 block. */
   #define SYSMEM_PORT1_SEC_DED_STAT1_ADDR (*((volatile uint32_t *)(SYSMEM_base + 0x10Cu)))

   /* ECC Parity patterns for error injection */
   #define ECC_PARITY_SINGLE_BIT_ERROR    (0xF8) /* SEC: offset 0x1FFFF8, data 0x3 (Port0) */
   #define ECC_PARITY_SINGLE_BIT_ERROR_P1 (0x01) /* SEC: offset 0x1000, data 0x2 (Port1), discovered by sweep */
   #define ECC_PARITY_DOUBLE_BIT_ERROR    (0xF0) /* DED: offset 0x1FFFF8, data 0x3 (Port0) */
   #define ECC_PARITY_DOUBLE_BIT_ERROR_P1 (0x27) /* DED: offset 0x1000, data 0x2 (Port1) */

#endif
#define SET_SEC_THRESHOLD (0u)
#define ATTEMPT_COUNT     (3U)                  /* Number of attempts to enable ECC */
#define FCRU_SET_KEY      ((uint32)0xCAB005E5U) /* Valid Key Value  */
#define CLR_ARTIE_MEM_IRQ (0x3F)                /* Clear all Artiemem IRQs */
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/******************************************************************************
 * Name:  ECC_Irq_Enable
 *    This function enables ECC monitoring and IRQs for  memories
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Initializes SYSMEM memories, clears SEC counters, and enables ECC IRQs
 *
 *
 ******************************************************************************/
void ECC_Irq_Enable(void)
{
#ifndef UNIT_TEST
   /* Enable DED (bits 10, 26) and SEC threshold (bits 11, 27) IRQs for Port0 and Port1 */
   SYSMEM->IRQ_ENA_CTRL0 = 0x0C000C00;
#else
   /* do nothing */
#endif
}

/******************************************************************************
 * Name:  ECC_Sec_Threshold_Config
 *    This function configures SEC threshold limits for SYSMEM ports
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 ******************************************************************************/
void ECC_Sec_Threshold_Config(void)
{
#ifndef UNIT_TEST
   /* Configure SEC threshold limit for Port0 and Port1 */
   SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_ERR_SEC_LIM = SET_SEC_THRESHOLD;
   SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_ERR_SEC_LIM = SET_SEC_THRESHOLD;

   /* Configure SEC threshold limit for Artiemem */
   ARTIE_REGS->SEC_CNT_CTRL.f.CTL_ERR_SEC_LIM = SET_SEC_THRESHOLD;
   ARTIE_REGS->AMEM_IRQ_CLR.r                 = 0x3F;
#else
   /* do nothing */
#endif
}

/******************************************************************************
 * Name:  Enable_Tcm_Cache_Ecc
 *    This function enables ECC for TCM memory
 *
 * Shared Variables: Ecc_Enable_Status_Flag
 *
 * Parameters: none
 *
 * Return Value: bool
 *
 * Design Information:
 *   Enables ECC TCM memory and updates monitor flag on enable failure
 *
 *
 ******************************************************************************/
bool Enable_Tcm_Cache_Ecc(void)
{
   uint32_t tcm_ecc_en = 0U;

#ifndef UNIT_TEST
   ARTIE->SP_MAIN_CFG.f.CFGRAMPROTEN = 1U;
   /* Read back to confirm ECC enable has latched */
   tcm_ecc_en = ARTIE->SP_MAIN_CFG.f.CFGRAMPROTEN;

   if (tcm_ecc_en != 1U)
   {
      Ecc_Enable_Status_Flag |= true;
   }
#else

#endif
   return Ecc_Enable_Status_Flag;
}
/******************************************************************************
 * Name:  Get_Ecc_Enable_Err_status
 *    This function retrieves the ECC enable error state for TCM memory
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: bool
 *
 * Design Information:
 *   Retrieves the ECC enable error state for TCM memory
 *
 *
 ******************************************************************************/
bool Get_Ecc_Enable_Err_status(void)
{
   return Ecc_Enable_Status_Flag;
}
/******************************************************************************
 * Name:  Enable_Mss_Tcm_Cache_Ecc
 *    This function enables ECC for TCM memory
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Enables ECC TCM memory
 *
 *
 ******************************************************************************/

void Enable_Mss_Tcm_Cache_Ecc(void)
{
   for (uint8_t attempt = 0U; attempt < ATTEMPT_COUNT; ++attempt)
   {
      if (Enable_Tcm_Cache_Ecc() == false)
      {
         break; /* ECC enabled successfully */
      }
   }
}
#if (defined(ENABLE_SQT_ARTIEMEM_FAULT) && !defined(UNIT_TEST))
/******************************************************************************
 * Name:  ARTIEMEM_SEC_Fault_Injection
 *    Injects a Single Error Correction (SEC) fault in ARTIE memory
 ******************************************************************************/
void ARTIEMEM_SEC_Fault_Injection(void)
{
   volatile uint64_t read_value;
   volatile uint32_t dummy;

   // Disable ARTIE MEM interrupt (replace with correct source if needed)
   Os_DisableInterruptSource(Artie_Mem_Fusa_Handler);
   ARTIE_REGS->SEC_CNT_CTRL.f.CTL_ERR_SEC_LIM = SET_SEC_THRESHOLD;

   // Step 1: Initialize memory with encoder enabled (valid ECC bits)
   ARTIE_REGS->MEM_CTRL.r &= ~ARTIE_ECC_ENCODER_BYPASS; // Ensure encoder is enabled
   *ARTIE_ADDR64 = 0xA5A5A5A5A5A5A5A5ULL;               // Write known-good value
                                                        // read_value = *ARTIE_ADDR64; // Optional: verify write

   ARTIE_REGS->CLEAR_ERR_CTRL.r |= ARTIE_CLR_ECC_SEC_CNT;
   ARTIE_REGS->CLEAR_ERR_CTRL.r &= ~ARTIE_CLR_ECC_SEC_CNT;
   ARTIE_REGS->AMEM_IRQ_CLR.r = CLR_ARTIE_MEM_IRQ;
   dummy                      = ARTIE_REGS->AMEM_IRQ_CLR.r; // Small delay
   for (volatile int i = 0; i < 1000; ++i)
   {
      __asm__ volatile("nop");
   }
   ARTIE_REGS->MEM_CTRL.r |= ARTIE_ECC_ENCODER_BYPASS;
   dummy = ARTIE_REGS->MEM_CTRL.r; // Small delay
   for (volatile int i = 0; i < 1000; ++i)
   {
      __asm__ volatile("nop");
   }
   *ARTIE_ADDR64 = ARTIE_DATA64;
   // Delay to ensure write completion
   for (volatile int i = 0; i < 5000; ++i)
   {
      __asm__ volatile("nop");
   }
   // dummy = *ARTIE_ADDR64; // Read back to ensure write
   (void)dummy; // Prevent unused variable warning
   ARTIE_REGS->MEM_CTRL.r &= ~ARTIE_ECC_ENCODER_BYPASS;

   ARTIE_REGS->AMEM_IRQ_CLR.r = CLR_ARTIE_MEM_IRQ;
   for (volatile int i = 0; i < 5000; ++i)
   {
      __asm__ volatile("nop");
   }

   read_value = *ARTIE_ADDR64;
   for (volatile int i = 0; i < 5000; ++i)
   {
      __asm__ volatile("nop");
   }

   ARTIE_REGS->SEC_CNT_CTRL.r |= ARTIE_CTL_SNAP_SEC_CNT;
   ARTIE_REGS->SEC_CNT_CTRL.r &= ~ARTIE_CTL_SNAP_SEC_CNT;
   dummy = ARTIE_REGS->MEM_CTRL.r; // Small delay
   for (volatile int i = 0; i < 1000; ++i)

      if (read_value != ARTIE_DATA64)
      {
         ARTIEMEM_ErrCnt += 1u;
      }
   // Re-enable ARTIE MEM interrupt   Os_EnableInterruptSource(Artie_Mem_Fusa_Handler, TRUE);
   Os_EnableInterruptSource(Artie_Mem_Fusa_Handler, TRUE);
}
/******************************************************************************
 * Name:  ARTIEMEM_DED_Fault_Injection
 *    Injects a Double Error Detection (DED) fault in ARTIE memory
 ******************************************************************************/
void ARTIEMEM_DED_Fault_Injection(void)
{
   volatile uint64_t read_value;
   volatile uint32_t dummy;

   // Disable ARTIE MEM interrupt (replace with correct source if needed)
   Os_DisableInterruptSource(Artie_Mem_Fusa_Handler);

   // Step 1: Initialize memory with encoder enabled (valid ECC bits)
   ARTIE_REGS->MEM_CTRL.r &= ~ARTIE_ECC_ENCODER_BYPASS; // Ensure encoder is enabled
   *ARTIE_ADDR64_DED = 0xA5A5A5A5A5A5A5A5ULL;           // Write known-good value

   // Step 2: Clear error/IRQ status
   ARTIE_REGS->CLEAR_ERR_CTRL.r |= ARTIE_CLR_ECC_SEC_CNT;
   ARTIE_REGS->CLEAR_ERR_CTRL.r &= ~ARTIE_CLR_ECC_SEC_CNT;
   ARTIE_REGS->AMEM_IRQ_CLR.r = CLR_ARTIE_MEM_IRQ;
   dummy                      = ARTIE_REGS->AMEM_IRQ_CLR.r; // Small delay
   for (volatile int i = 0; i < 1000; ++i)
   {
      __asm__ volatile("nop");
   }

   // Step 3: Enable encoder bypass and inject DED
   ARTIE_REGS->MEM_CTRL.r |= ARTIE_ECC_ENCODER_BYPASS;
   dummy = ARTIE_REGS->MEM_CTRL.r; // Small delay
   for (volatile int i = 0; i < 1000; ++i)
   {
      __asm__ volatile("nop");
   }

   *ARTIE_ADDR64_DED = ARTIE_DATA64_DED;
   // Delay to ensure write completion
   for (volatile int i = 0; i < 5000; ++i)
   {
      __asm__ volatile("nop");
   }
   dummy = *ARTIE_ADDR64_DED; // Read back to ensure write
   (void)dummy;               // Prevent unused variable warning

   ARTIE_REGS->MEM_CTRL.r &= ~ARTIE_ECC_ENCODER_BYPASS;

   read_value = *ARTIE_ADDR64_DED;

   if (read_value == ARTIE_DATA64_DED)
   {
      ARTIEMEM_ErrCnt += 1u;
   }

   // Re-enable ARTIE MEM interrupt
   Os_EnableInterruptSource(Artie_Mem_Fusa_Handler, TRUE);
}
#endif

#if (ENABLE_SQT_TEST_STUBS == STD_ON) && !defined(UNIT_TEST)

/******************************************************************************
 * Name:  ECC_Inject_Delay
 *    Helper: timeout delay loop used between ECC injection register operations
 ******************************************************************************/
static void ECC_Inject_Delay(void)
{
   do
   {
      Timeout_Cnt_Dss++;
      if (Timeout_Cnt_Dss > Max_TimeOut_Milliseconds_Dss)
      {
         Result_Dss = FALSE;
         break;
      }
   } while (Result_Dss != FALSE);
}

/******************************************************************************
 * Name:  SYSMEM_ECC_Test_Inject_SEC
 *    This function injects Single-bit Error Correctable (SEC) errors into SYSMEM memories
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Injects SEC errors by enabling ECC encoder bypass and setting parity bits to create single-bit error, then reads back to
 *trigger correction and logging. Finally, clears sticky bits and restores normal operation.
 *
 *
 ******************************************************************************/

__attribute__((optnone)) void SYSMEM_ECC_Test_Inject_SEC(void)
{
   if (sysmem_sec_ecc_port0 == 1)
   {
      volatile uint64_t *const p    = (volatile uint64_t *)0x801FFFF8;
      const uint64_t pattern        = 0x0000000000000003;
      const uint32_t irq_ena_backup = SYSMEM->IRQ_ENA_CTRL0;

      /* Clear previous sticky bits and latched IRQ status (if any) */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 0;
      ECC_Inject_Delay();
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 0;
      ECC_Inject_Delay();
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 0;
      ECC_Inject_Delay();
      SYSMEM->IRQ_STAT0 = 0x00000C00u;

      /* During SEC test: force SEC IRQ enabled and DED IRQ masked for deterministic ISR routing. */
      SYSMEM->IRQ_ENA_CTRL0 = ((irq_ena_backup | 0x00000800u) & (~0x00000400u));

      /* Enable encoder bypass and set single-bit parity */
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_BYP    = 1;
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_PARITY = ECC_PARITY_SINGLE_BIT_ERROR;

      /* Write same data with forced-bad ECC */
      *p = pattern;
      ECC_Inject_Delay();
      /* Restore normal ECC */
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_BYP = 0;
      ECC_Inject_Delay();
      /* Read to trigger correction and event logging */
      {
         volatile uint64_t readback = *p;
         (void)readback;
      }

      /* Snapshot SEC counter to ensure threshold/counter state is latched. */
      SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 1;
      SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 0;

      /* Read sticky and SEC counter AFTER injection */
      uint32_t sts0 = SYSMEM->PORT0_SEC_DED_STAT0.f.STS_P0_ECC_SEC_STICKY; /* contains STS_P0_ECC_SEC_STICKY/DED_STICKY */
      (void)sts0;
      ECC_Inject_Delay();
      SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 1;
      SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 0;
      ECC_Inject_Delay();
      uint16_t sec_cnt_after = (uint16_t)(SYSMEM_PORT0_SEC_DED_STAT1_ADDR & STS_P0_ECC_SEC_CNT_MASK);
      (void)sec_cnt_after;
      ECC_Inject_Delay();
      /* Write valid data back to clear corrupted ECC */
      *p = pattern;
      ECC_Inject_Delay();
      /* Restore IRQ enable configuration, but keep Port0 SEC/DED IRQs enabled. */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup | 0x00000C00u);
      ECC_Inject_Delay();
      /* Wait briefly for ISR handling (IRQ bit11 should clear once handled), timeout-protected. */
      {
         volatile uint32_t wait_isr = 0u;
         while (wait_isr < 100000u)
         {
            if ((SYSMEM->IRQ_STAT0 & 0x00000800u) == 0u)
            {
               break;
            }
            wait_isr++;
         }
      }

      sysmem_sec_ecc_port0 = 0;
   }
   else
   {
      /* do nothing */
   }
   if (sysmem_sec_ecc_port1 == 1)
   {
      volatile uint64_t *const p    = (volatile uint64_t *)0x82001000;
      const uint64_t pattern        = 0x0000000000000002;
      const uint32_t irq_ena_backup = SYSMEM->IRQ_ENA_CTRL0;

      /* Clear previous sticky bits (if set) */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 0;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 0;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT    = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT    = 0;
      SYSMEM->IRQ_STAT0                                     = 0x0C000000u;

      /* During SEC test: force SEC IRQ enabled and DED IRQ masked for deterministic ISR routing. */
      SYSMEM->IRQ_ENA_CTRL0 = ((irq_ena_backup | 0x08000000u) & (~0x04000000u));

      /*
       * Retry a few SEC injections in the same call.
       * This helps when SEC IRQ assertion is delayed in free-run timing.
       */
      for (uint32_t attempt = 0u; attempt < 8u; attempt++)
      {
         SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_BYP    = 1;
         SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_PARITY = ECC_PARITY_SINGLE_BIT_ERROR_P1;

         /* Write same data with forced-bad ECC */
         *p = pattern;

         /* Restore normal ECC */
         SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_BYP = 0;

         /* Read to trigger correction and event logging */
         {
            volatile uint64_t readback = *p;
            (void)readback;
         }

         /* Snapshot SEC counter to ensure threshold/counter state is latched. */
         SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 1;
         SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 0;

         /* Wait until SEC indication is latched (IRQ bit27 or SEC sticky), with timeout. */
         {
            volatile uint32_t wait = 0u;
            while (wait < 50000u)
            {
               uint32_t irq_status_now = SYSMEM->IRQ_STAT0;
               uint32_t sec_sticky_now = SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_SEC_STICKY;
               if (((irq_status_now & 0x08000000u) != 0u) || (sec_sticky_now != 0u))
               {
                  attempt = 8u; /* break outer loop */
                  break;
               }
               wait++;
            }
         }
      }

      /* Read sticky and SEC counter AFTER injection */
      uint32_t sts0 = SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_SEC_STICKY; /* contains STS_P1_ECC_SEC_STICKY/DED_STICKY */
      (void)sts0;
      SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 1;
      SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 0;
      uint16_t sec_cnt_after                            = (uint16_t)(SYSMEM_PORT1_SEC_DED_STAT1_ADDR & STS_P1_ECC_SEC_CNT_MASK);
      (void)sec_cnt_after;

      /* Write valid data back to clear corrupted ECC */
      *p = pattern;

      /* Restore IRQ enable configuration, but keep Port1 SEC/DED IRQs enabled. */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup | 0x0C000000u);

      sysmem_sec_ecc_port1 = 0;
   }
   else
   {
      /* do nothing */
   }
}

/******************************************************************************
 * Name:  SYSMEM_ECC_Test_Inject_DED
 *    This function injects Double-bit Error Detectable (DED) errors into SYSMEM memories
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *   Injects DED errors by enabling ECC encoder bypass and setting parity bits to create double-bit error, then reads back to
 *trigger detection and logging. Finally, clears sticky bits and restores normal operation.
 *
 *
 ******************************************************************************/
__attribute__((optnone)) void SYSMEM_ECC_Test_Inject_DED(void)
{
   if (sysmem_ded_ecc_port0 == 1)
   {
      volatile uint64_t *const p    = (volatile uint64_t *)0x801FFFF8;
      const uint64_t pattern        = 0x0000000000000003;
      const uint32_t irq_ena_backup = SYSMEM->IRQ_ENA_CTRL0;

      /* Clear previous DED sticky (if set) */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 0;
      ECC_Inject_Delay();
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 0;

      SYSMEM->IRQ_STAT0 = 0x00000C00u;

      /* Mask Port0 SEC threshold IRQ during DED test so ISR sees DED-only event. */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup & (~0x00000800u));

      /* Enable encoder bypass and set double-bit parity */
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_BYP    = 1;
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_PARITY = ECC_PARITY_DOUBLE_BIT_ERROR;

      /* Write same data with forced-bad ECC (double-bit parity) */
      *p = pattern;
      ECC_Inject_Delay();
      /* Restore normal ECC */
      SYSMEM->PORT0_ECC_CTRL0.f.CTL_P0_ECC_ENC_BYP = 0;
      ECC_Inject_Delay();
      /* Read to trigger detection and event logging */
      volatile uint64_t readback = *p;
      (void)readback;
      ECC_Inject_Delay();
      /* Read DED sticky AFTER injection */
      uint32_t ded_sticky = SYSMEM->PORT0_SEC_DED_STAT0.f.STS_P0_ECC_DED_STICKY;
      ECC_Inject_Delay();
      (void)ded_sticky;

      /* Write valid data back to clear corrupted ECC */
      *p = pattern;

      /* Restore IRQ enable configuration, but keep Port0 SEC/DED IRQs enabled. */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup | 0x00000C00u);

      sysmem_ded_ecc_port0 = 0;
   }
   else
   {
      /* do nothing */
   }
   if (sysmem_ded_ecc_port1 == 1)
   {
      volatile uint64_t *const p    = (volatile uint64_t *)0x82001000;
      const uint64_t pattern        = 0x0000000000000002;
      const uint32_t irq_ena_backup = SYSMEM->IRQ_ENA_CTRL0;

      /* Clear previous DED sticky (if set) */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 0;
      ECC_Inject_Delay();
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 0;
      SYSMEM->IRQ_STAT0                                  = 0x0C000000u;

      /* Mask Port1 SEC threshold IRQ during DED test so ISR sees DED-only event */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup & (~0x08000000u));

      /* Enable encoder bypass and set double-bit parity */
      SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_BYP    = 1;
      SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_PARITY = ECC_PARITY_DOUBLE_BIT_ERROR_P1;

      /* Write same data with forced-bad ECC (double-bit parity) */
      *p = pattern;
      ECC_Inject_Delay();
      /* Restore normal ECC */
      SYSMEM->PORT1_ECC_CTRL0.f.CTL_P1_ECC_ENC_BYP = 0;

      /* Read to trigger detection and event logging */
      volatile uint64_t readback = *p;
      (void)readback;
      ECC_Inject_Delay();
      /* Read DED sticky AFTER injection */
      uint32_t ded_sticky = SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_DED_STICKY;

      (void)ded_sticky;
      ECC_Inject_Delay();
      /* Write valid data back to clear corrupted ECC */
      *p = pattern;

      /* Restore IRQ enable configuration, but keep Port1 SEC/DED IRQs enabled. */
      SYSMEM->IRQ_ENA_CTRL0 = (irq_ena_backup | 0x0C000000u);

      /* Wait briefly for ISR handling (IRQ bit26 should clear once handled), timeout-protected. */
      {
         volatile uint32_t wait_isr = 0u;
         while (wait_isr < 100000u)
         {
            if ((SYSMEM->IRQ_STAT0 & 0x04000000u) == 0u)
            {
               break;
            }
            wait_isr++;
         }
      }

      sysmem_ded_ecc_port1 = 0;
   }
   else
   {
      /* do nothing */
   }
}

/******************************************************************************
 * Name:  Fault_Injection_Test_Mss_Tcm_Cache
 *    Boot1/Boot2 retained-reset test path for TCM fatal channel validation.
 *
 * Note:
 *   Boot1 configures FCRU and triggers TCM fatal stimulus (BTCM/CTCM read).
 *   Boot2 validates DIAG latches, clears status and resets retain marker.
 ******************************************************************************/
__attribute__((optnone, used)) void Fault_Injection_Test_Mss_Tcm_Cache(void)
{
   #ifndef UNIT_TEST
   if (test_tcm != 0u)
   {
      /* Verify fault pins aren't already asserted before forcing fault */
      if ((FUSA_CTRL->FCRU_DIAG0 != 0x00000000u) || (FUSA_CTRL->FCRU_DIAG1 != 0x00000000u))
      {
         /* Fault already active - do not proceed with test */
         return;
      }

      /* FCRU_KEY must be set to 0xCAB005E5 in order to force faults */
      FUSA_CTRL->FCRU_KEY = FCRU_SET_KEY;

      switch (test_tcm)
      {
         case 1u:
            /* Pin 32 - R52 fatal memory error from TCMs (bit 0 of CTRL12) */
            FUSA_CTRL->FCRU_CTRL11 = 0x00000000u;
            FUSA_CTRL->FCRU_CTRL12 = 0x00000001u;
            break;

         case 2u:
            /* Pin 41 - R52 fatal TCM error (bit 9 of CTRL12) */
            FUSA_CTRL->FCRU_CTRL11 = 0x00000000u;
            FUSA_CTRL->FCRU_CTRL12 = 0x00000200u;
            break;

         case 3u:
            /* Pin 44 - R52 fatal L1 or TCM error (bit 12 of CTRL12) */
            FUSA_CTRL->FCRU_CTRL11 = 0x00000000u;
            FUSA_CTRL->FCRU_CTRL12 = 0x00001000u;
            break;

         default:
            break;
      }
   }
   #else
      /* do nothing */
   #endif
}
#endif /* ENABLE_SQT_TEST_STUBS */
#ifdef UNIT_TEST

uint32_t sysmem_ecc_inject_sec_call_count = 0u;
uint32_t sysmem_ecc_inject_ded_call_count = 0u;
uint32_t fault_injection_tcm_call_count   = 0u;

void SYSMEM_ECC_Test_Inject_SEC(void)
{
   ++sysmem_ecc_inject_sec_call_count;
}

void SYSMEM_ECC_Test_Inject_DED(void)
{
   ++sysmem_ecc_inject_ded_call_count;
}

void Fault_Injection_Test_Mss_Tcm_Cache(void)
{
   ++fault_injection_tcm_call_count;
}

#endif

/******************************************************************************
 * Name: Ecc_Fault_Injection_Test
 * Description: Execute SYSMEM ECC test sequence per SM_090_SYSMEM_ECC spec
 *****************************************************************************/
__attribute__((optnone, used)) void Ecc_Fault_Injection_Test(void)
{
#if (ENABLE_SQT_TEST_STUBS == STD_ON) || defined(UNIT_TEST)
   SYSMEM_ECC_Test_Inject_SEC();
   SYSMEM_ECC_Test_Inject_DED();
   Fault_Injection_Test_Mss_Tcm_Cache();
#else
   /* do nothing */
#endif

#if (defined(ENABLE_SQT_ARTIEMEM_FAULT) && !defined(UNIT_TEST))
   /* Inject SEC faults with SM number */
   switch (SEC_FltNum)
   {
      case 5:
         SEC_FltNum = 0;
         ARTIEMEM_SEC_Fault_Injection();
         break;
      default:
         break;
   }

   /* Inject DED faults with SM number */
   switch (DED_FltNum)
   {
      case 5:
         DED_FltNum = 0;
         ARTIEMEM_DED_Fault_Injection();
         break;
      default:
         break;
   }
#else
   /* do nothing */
#endif
}
