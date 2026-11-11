#ifndef MSS_ECC_PARITY_H
#define MSS_ECC_PARITY_H
/*===========================================================================*\
 * FILE: Mss_Ecc_Parity.h
 *===========================================================================
 * Copyright 2024 APTIV Technologies Inc. All Rights Reserved.
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
#include <stdbool.h>
#include <stdint.h>
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
/*===========================================================================*\
    * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void ECC_Irq_Enable(void);
void ECC_Sec_Threshold_Config(void);
bool Enable_Tcm_Cache_Ecc(void);
void Enable_Mss_Tcm_Cache_Ecc(void);
bool Get_Ecc_Enable_Err_status(void);
void Fault_Injection_Test_Mss_Tcm_Cache(void);
void Ecc_Fault_Injection_Test(void);

#endif /* MSS_ECC_PARITY_H */
