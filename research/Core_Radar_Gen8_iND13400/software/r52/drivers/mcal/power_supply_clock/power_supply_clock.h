#ifndef POWER_SUPPLY_CLOCK_H_
#define POWER_SUPPLY_CLOCK_H_

/*===========================================================================*/
/**
 * @file power_supply_clock.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 * DESCRIPTION:
 *   This file contains the header files for power supply clock functions.
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*
 *  Header Files
 *===========================================================================*/
#include "dd_pmic.h"

/*===========================================================================*
 * Exported Preprocessor defined Constants
 *===========================================================================*/
#define CLOCK_ENABLED  (1U)
#define CLOCK_DISABLED (0U)

/* Allow override from test environment */
#ifndef PS_CLOCK_INIT_ENABLE
   #define PS_CLOCK_INIT_ENABLE CLOCK_DISABLED
#endif

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

#if (PS_CLOCK_INIT_ENABLE == CLOCK_ENABLED)
void PS_Clock_Init(void);
#endif /*End of PS_CLOCK_INIT_ENABLE*/

#endif /* POWER_SUPPLY_CLOCK_H_ */
