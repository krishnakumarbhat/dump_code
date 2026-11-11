/**
 * @file exceptions.h
 * @brief Provide the API to enable exception handling.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Main application definitions.
 * @note This file should only contain constant definitions and NO INCLUDE files.
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

   /*==================================================================================================
   *                                          CONSTANTS
   ==================================================================================================*/

   /*==================================================================================================
   *                                      DEFINES AND MACROS
   ==================================================================================================*/

   /*==================================================================================================
   *                                             ENUMS
   ==================================================================================================*/

   /*==================================================================================================
   *                                STRUCTURES AND OTHER TYPEDEFS
   ==================================================================================================*/

   /*==================================================================================================
   *                                GLOBAL VARIABLE DECLARATIONS
   ==================================================================================================*/

   /*==================================================================================================
   *                                    FUNCTION PROTOTYPES
   ==================================================================================================*/
   void Register_Exception_Handlers(void);

#ifdef __cplusplus
}
#endif

#endif /* EXCEPTIONS_H */
