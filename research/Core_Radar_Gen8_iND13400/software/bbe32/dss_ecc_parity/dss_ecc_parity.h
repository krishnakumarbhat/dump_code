#ifndef DSS_ECC_PARITY_H
#define DSS_ECC_PARITY_H
/*===========================================================================*/
/**
 * @file dss_ecc_parity.h
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

/*===========================================================================*\
 * Standard Header Files
 *===========================================================================*/
#include <stdbool.h>
#include <stdint.h>
/*===========================================================================*\
 * Other Header Files
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
 *===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
 *===========================================================================*/
void Enable_Dsp_Ecc(void);
void Enable_Dsp_Parity(void);
uint8_t Get_Axi_Ecc_Enable_Err_state(void);
uint8_t Get_Csr_Parity_Enable_Err_state(void);
typedef enum
{
   ECC_TEST_NONE = 0,
   ECC_TEST_DRAM_SEC,
   ECC_TEST_DRAM_DED,
   ECC_TEST_IRAM_SEC,
   ECC_TEST_IRAM_DED,
   ECC_TEST_CSR_PARITY
} EccTest_t;
/*
 * Host-based unit tests (x86_64) may include this header via transitive deps
 * (e.g. SPBB UTs) but cannot link the real hardware implementation.
 */
#if defined(__XTENSA__) || defined(UNIT_TEST)
void RA_ESTMEM_ECC_Enable(void);
void Inject_Correctable_Error(int32_t *addr);
void Test_Dsp_Ecc_Parity_Error(void);
uint32_t Get_Ecc_Mesr_Status(void);
#else /*UT*/
static inline void RA_ESTMEM_ECC_Enable(void)
{
}
static inline void Inject_Correctable_Error(int32_t *addr)
{
   (void)addr;
}
static inline void Inject_Uncorrectable_Error(int32_t *addr)
{
   (void)addr;
}
static inline uint32_t Get_Ecc_Mesr_Status(void)
{
   return 0;
}
#endif
/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- ------
 *===========================================================================*/

#endif // DSS_ECC_PARITY_H
