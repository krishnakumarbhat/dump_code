#ifndef HIL_INTERFACE_H
#define HIL_INTERFACE_H
/*===========================================================================*\
 * FILE: hil_interface.h
*===========================================================================
* Copyright 2026 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*   This header file declares the interfaces, types, and macros required for
*   Hardware-in-the-Loop (HIL) integration and communication within the radar
*   software system.
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
void Update_HIL_Input_Interface(void);
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid   (Description on following lines: SCR #, etc.)
 * --------    -----    ------------------------------------------------------
 *29-Aug-2024   jjyb9k   DNP-4996: Initial Version of hil interface.

\*===========================================================================*/
#endif /* HIL_INTERFACE_H */
