#ifndef BBE32_STATIC_REGISTER_VALIDATION_H
#define BBE32_STATIC_REGISTER_VALIDATION_H
/*===========================================================================*\
 * FILE: bbe32_static_register_safety.h
 *===========================================================================
 * Copyright 2025 APTIV Technologies Inc. All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Functional Safety Configuration.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used or reference(s) to external document(s)
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
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
/*===========================================================================*\
    * Exported Preprocessor #define Constants
\*===========================================================================*//*AUX ACC */
#define AUX_ACC_MISC_CTRL0 (0x84402050)
#define AUX_ACC_ECC_CTRL0  (0x84402178)
#define AUX_ACC_ECC_CTRL1  (0x8440217C)
#define AUX_ACC_ECC_CTRL2  (0x84402180)
#define AUX_ACC_RAM_CTRL0  (0x84402190)
#define IRQ_ERR_ENA_CTRL0  (0x84402194)
#define IRQ_INFO_ENA_CTRL0 (0x8440219C)

/* RX ACC*/
#define R52_ERR_IRQ_ENA_1   (0x844C0024)
#define R52_ERR_IRQ_ENA_2   (0x844C0028)
#define R52_FUNC_IRQ_ENA    (0x844C002C)
#define COMP_PRBS_1         (0x844C003C)
#define COMP_PRBS_2         (0x844C0040)
#define DECOMP_PRBS_1       (0x844C0044)
#define DECOMP_PRBS_2       (0x844C0048)
#define MON_TIMER_IN_CTRL   (0x844C006C)
#define MON_TIMER_PROC_CTRL (0x844C0074)
#define MON_TIMER_OUT_CTRL  (0x844C007C)
#define IDMA_TRIGGER_ENA    (0x844C0090)

// /* BBE32*/
#define DSP_FUSA_IRQ_ENA (0x84401014)
#define DSP_IRQ_ENA      (0x84401024)
#define DSP_CTRL         (0x84401000)

void Bbe32_Static_Register_Safety_Check(void);

#endif /*BBE32_STATIC_REGISTER_VALIDATION_H*/
