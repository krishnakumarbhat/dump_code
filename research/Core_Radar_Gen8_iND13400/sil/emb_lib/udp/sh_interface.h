
#ifndef SH_INTERFACE_H
#define SH_INTERFACE_H
/*===========================================================================*\
 * FILE: sh_interface.h
*===========================================================================
* Copyright 2020 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*   This file contains the header files for logging data.
*
* ABBREVIATIONS:
*   List of abbreviations used, or reference(s) to external document(s)
*
* TRACEABILITY INFO:
*   Design Document(s):
*
*   Requirements Document(s):
*
*   Applicable Standards (in order of precedence: highest first):
*     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
*
* DEVIATIONS FROM STANDARDS:
*   None.
*
\*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "sh_comm.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/
#define Get_Source_Tx_Time() ((uint64_t)Get_Timestamp_ms())

/*Start Atomic Section by disabling interrupts*/
#define Start_Atomic_Section() // DisableAllInterrupts()
/*End Atomic Section by enabling interrupts*/
#define End_Atomic_Section() // EnableAllInterrupts()
void Update_SH_Input_Interface(void);
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
#endif /* SH_WRAPPER_INTERFACE_H */
