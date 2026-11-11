#ifndef SWC_PLT_CDD_MCU_SAFETY__H_
#define SWC_PLT_CDD_MCU_SAFETY__H_
/*===========================================================================*\
 * FILE: SWC_PLT_CDD_MCU_Safety.h
 *===========================================================================
 * Copyright 2013 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Functional Safety Configuration.
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
#include "retention_ram_data.h"
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#if (TRUE == XCP_FAULT_INJECTION)
   #define RESET_WITH_SAME_RESET_REASON               (0x01U)
   #define RESET_WITH_DIFF_RESET_REASON               (0x02U)
   #define REPETATIVE_RESET_FAULT_INJECTION_PATTERN_1 (0xAAU)
   #define REPETATIVE_RESET_FAULT_INJECTION_PATTERN_2 (0x55U)
#endif

/* Power-On LBIST register definition and PASS criteria */
#define LBIST_SEQ_STAT0_ADDR (0x89000058U)

/* Bit positions */
#define STS_LBSC_LOADED_POS (0U)
#define STS_LBSC_DONE_POS   (1U)
#define STS_LBSC_GOOD_POS   (2U)

/* Bit masks */
#define STS_LBSC_LOADED_MASK (1U << STS_LBSC_LOADED_POS)
#define STS_LBSC_DONE_MASK   (1U << STS_LBSC_DONE_POS)
#define STS_LBSC_GOOD_MASK   (1U << STS_LBSC_GOOD_POS)

/* Default = PASS. Only FAIL when DONE=1, LOADED=1, GOOD=0 (test ran and failed). */
#define LBIST_TEST_RAN_FAIL_PATTERN (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK)
/* PASS pattern: DONE=1, LOADED=1, GOOD=1 (test ran and passed). */
#define LBIST_PASS_VALUE (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK | STS_LBSC_GOOD_MASK)

/* PMU BOR register addresses */
#ifndef UNIT_TEST
   #define BOR_RST_REASON_CLR (*(volatile uint32 *)(0x89002014U)) /* RST_REASON_CLR Reset Reason Flag Clear Register */
   #define BOR_TRIM_OTP_REG   (*(volatile uint32 *)(0x8B000EE8U)) /* OTP Trim Source Register */
   #define BOR_0P8_TRIM_REG   (*(volatile uint32 *)(BOR_0P8_TRIM))
   #define BOR_1P8_TRIM_REG   (*(volatile uint32 *)(BOR_1P8_TRIM))
#endif

/* Reset Monitor */
#ifndef UNIT_TEST
   #define CTL_RMON (*(volatile uint32 *)(0x89002094U)) /* CTL_RMON Control for software-serviceable resets monitor */
   #define IRQ_RMON (*(volatile uint32 *)(0x89002098U)) /* Interrupt sources for software-serviceable resets monitor */
   #define IRQ_RMON_NOMASK                                                                                                        \
      (*(volatile uint32 *)(0x8900209CU)) /* Interrupt sources for software-serviceable resets monitor without masking */
   #if (ENABLE_SQT_TEST_STUBS == STD_ON)
      #define RMON_CTRL0                                                                                                          \
         (*(volatile uint32 *)(0x890040ACU)) /* RMON_CTRL0 Reset monitor non-software serviceable resets control                  \
                                              */
   #endif
   #define RMON_CLKGEN_CTRL0 (*(volatile uint32 *)(0x8900306CU)) /* CLKGEN_CTRL0 Clock Generator Control Register 0 */
   #define MCU_SAFETY_MISC0_IRQ_MASKED_STAT                                                                                       \
      (*(volatile uint32_t *)0x89003180U) /* MISC0_IRQ_MASKED_STAT Masked interrupt status for MISC0                              \
                                           */
#endif

/* CTL_RMON bit definitions */
#define CTL_RMON_EN_RA   (1U << 0)
#define CTL_RMON_EN_MIPI (1U << 1)
#define CTL_RMON_EN_DSP  (1U << 2)
#define CTL_RMON_EN_REF  (1U << 3)

/* Reset monitor – Serial reset (QSPI + I2C) */
#define CLKGEN_RMON_SER_ENA (1U << 16) /* CTL_RMON_SER_ENA */

/* RMON_CTRL0 bit definitions – non-software-serviceable resets */
#define RMON_CTRL0_SYS_FRC      (1U << 0) /* CTL_RMON_SYS_FRC  – force rst_sys_n monitor trigger */
#define RMON_CTRL0_R52_CORE_FRC (1U << 4) /* CTL_RMON_R52_FRC[0] – force rst_r52_core_n monitor trigger */
#define RMON_CTRL0_R52_TOP_FRC  (1U << 5) /* CTL_RMON_R52_FRC[1] – force rst_r52_top_n monitor trigger */
#define CTL_RMON_FRC_RA         (1U << 16)
#define CTL_RMON_FRC_MIPI       (1U << 17)
#define CTL_RMON_FRC_DSP        (1U << 18)
#define CTL_RMON_FRC_REF        (1U << 19)
#define CLKGEN_RMON_SER_FRC     (1U << 17) /* CTL_RMON_SER_FRC */

/* STS_RMON_SWS field bits */
#define IRQ_RMON_RA_BIT   (1U << 0)
#define IRQ_RMON_MIPI_BIT (1U << 1)
#define IRQ_RMON_DSP_BIT  (1U << 2)
#define IRQ_RMON_REF_BIT  (1U << 3)
#define IRQ_RMON_SER_BIT  (1U << 8) /* QSPI + I2C */

/* PMU BOR configuration */
#define BOR_0P8_FLAG_CLR_MSK (1u << 2u)
#define BOR_1P8_FLAG_CLR_MSK (1u << 3u)
#define BOR_FLAGS_CLR_MSK    (BOR_0P8_FLAG_CLR_MSK | BOR_1P8_FLAG_CLR_MSK)

#define BOR_ARM_EN_BIT         (1U << 8U)
#define BOR_TRIM_VALUE         (9U)
#define BOR_TRIM_FIELD_MSK     (0x3Fu)
#define BOR_TRIM_OTP_1P8_SHIFT (6U)

#define BOR_TRIM_OTP_VALID     (1U)
#define BOR_TRIM_OTP_INVALID   (0U)
#define BOR_TRIM_OTP_NO_VALUE  (0U)
#define BOR_DEFAULT_TRIM_VALUE (0x20U) /* Default mid-point trim value if OTP is not valid */

#define DCLSCOMPIN0_POS  (0U)
#define DCLSCOMPIN2_POS  (2U)
#define DCLSCOMPIN4_POS  (4U)
#define DCLSCOMPIN6_POS  (6U)
#define DCLSCOMPIN8_POS  (8U)
#define DCLSCOMPIN10_POS (10U)
#define DCLSCOMPIN12_POS (12U)
#define DCLSCOMPIN84_POS (16U)
#define DCLSCOMPIN86_POS (18U)

#define DCLS_CTRL_ADDR       (*(volatile uint32 *)(0x89003018U))
#define DCLSCOMPIN0_ENABLE   (1U << DCLSCOMPIN0_POS)
#define DCLSCOMPIN2_ENABLE   (1U << DCLSCOMPIN2_POS)
#define DCLSCOMPIN4_ENABLE   (1U << DCLSCOMPIN4_POS)
#define DCLSCOMPIN6_ENABLE   (1U << DCLSCOMPIN6_POS)
#define DCLSCOMPIN8_ENABLE   (1U << DCLSCOMPIN8_POS)
#define DCLSCOMPIN10_ENABLE  (1U << DCLSCOMPIN10_POS)
#define DCLSCOMPIN12_ENABLE  (1U << DCLSCOMPIN12_POS)
#define DCLSCOMPIN84_ENABLE  (1U << DCLSCOMPIN84_POS)
#define DCLSCOMPIN86_ENABLE  (1U << DCLSCOMPIN86_POS)
#define DCLSCOMPIN0_DISABLE  (0U << DCLSCOMPIN0_POS)
#define DCLSCOMPIN2_DISABLE  (0U << DCLSCOMPIN2_POS)
#define DCLSCOMPIN4_DISABLE  (0U << DCLSCOMPIN4_POS)
#define DCLSCOMPIN6_DISABLE  (0U << DCLSCOMPIN6_POS)
#define DCLSCOMPIN8_DISABLE  (0U << DCLSCOMPIN8_POS)
#define DCLSCOMPIN10_DISABLE (0U << DCLSCOMPIN10_POS)
#define DCLSCOMPIN12_DISABLE (0U << DCLSCOMPIN12_POS)
#define DCLSCOMPIN84_DISABLE (0U << DCLSCOMPIN84_POS)
#define DCLSCOMPIN86_DISABLE (0U << DCLSCOMPIN86_POS)

#define DCLS_CTRL_CONFIG                                                                                                          \
   (DCLSCOMPIN0_ENABLE | DCLSCOMPIN2_ENABLE | DCLSCOMPIN4_ENABLE | DCLSCOMPIN6_ENABLE | DCLSCOMPIN8_ENABLE |                      \
    DCLSCOMPIN10_ENABLE | DCLSCOMPIN12_ENABLE | DCLSCOMPIN84_ENABLE | DCLSCOMPIN86_ENABLE)
   /*===========================================================================*\
       * Exported Type Declarations
      \*===========================================================================*/
   typedef enum MCU_InitializationStatus_Tag
   {
      MCUINIT_NOT_COMPLETED,
      MCUINIT_COMPLETED,
      MCUINIT_FAILED
   } MCU_InitializationStatus_T;

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   typedef enum
   {
      RMON_RST_SYS = 1,
      RMON_RST_R52_CORE,
      RMON_RST_R52_TOP,
      RMON_RST_RA,
      RMON_RST_MIPI,
      RMON_RST_DSP,
      RMON_RST_REF,
      RMON_RST_ART_SER
   } Rmon_ResetType;
#endif

   /*===========================================================================*\
    * Exported Object Declarations
   \*===========================================================================*/

   /*===========================================================================*\
    * Exported Function Prototypes
   \*===========================================================================*/
   void MCU_Safety_Init(void);
   void MCU_Safety_50ms(void);
   void Enable_PMU_BOR(void);
   void Enable_RMON(void);
#if (ENABLE_DOUBLE_RESET_FIX == STD_ON)
   void RMON_Enable_RA(void);
   void RMON_Disable_RA(void);
   void RMON_Enable_MIPI(void);
   void RMON_Disable_MIPI(void);
#endif
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   void MCU_Safety_TestManager(void);
#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   void MCU_Safety_Integration_Test(void);
#endif
   /*===========================================================================*\
    * Exported Inline Function Definitions and #define Function-Like Macros
   \*===========================================================================*/
   /*===========================================================================*\
    * File Revision History (top to bottom: first revision to last revision)
    *===========================================================================
    *
    * Date             userid  (Description on following lines: SCR #, etc.)

   \*===========================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* SWC_PLT_CDD_MCU_SAFETY__H_ */
