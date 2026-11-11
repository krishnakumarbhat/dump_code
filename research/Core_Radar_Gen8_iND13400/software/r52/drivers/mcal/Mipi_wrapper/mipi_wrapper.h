#ifndef MIPI_WRAPPER_H /* { */
#define MIPI_WRAPPER_H
/*===========================================================================*\
 * FILE: mipi_wrapper.h
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Mipi Wrapper functions.
 *
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
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "I2c.h"
#include "reuse.h"
/*===========================================================================*\
 * Local Preprocessor defined Constants
\*===========================================================================*/

#define DEBUG_VARIABLES_ENABLED (1U) /* Set to ENABLED to enable debug variables for I2C operations */

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/
#if (DEBUG_VARIABLES_ENABLED == (1U))
   #define COUNT_MIPI_I2C_WRITE_ATTEMPT() (Mipi_Debug_Counters.write_attempts++)
   #define COUNT_MIPI_I2C_WRITE_SUCCESS() (Mipi_Debug_Counters.write_success++)
   #define COUNT_MIPI_I2C_READ_ATTEMPT()  (Mipi_Debug_Counters.read_attempts++)
   #define COUNT_MIPI_I2C_READ_SUCCESS()  (Mipi_Debug_Counters.read_success++)
   #define COUNT_MIPI_RESET_VERIFIED()    (Mipi_Debug_Counters.reset_verified++)
   #define COUNT_MIPI_RESET_FAILED()      (Mipi_Debug_Counters.reset_failed++)

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/
typedef struct Mipi_I2c_Debug_Counters_Tag
{
   uint32_t write_attempts; /* Number of I2C write attempts to MIPI */
   uint32_t write_success;  /* Number of successful I2C write operations */
   uint32_t read_attempts;  /* Number of I2C read attempts from MIPI */
   uint32_t read_success;   /* Number of successful I2C read operations */
   uint32_t reset_verified; /* Number of times reset was successfully verified */
   uint32_t reset_failed;   /* Number of times reset verification failed */
} Mipi_I2c_Debug_Counters_T;

#endif /* DEBUG_VARIABLES_ENABLED == 1U */

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
bool Deassert_Reset_Mipi(void);
bool Assert_Reset_Mipi(void);
#endif /* } MIPI_WRAPPER_H */
