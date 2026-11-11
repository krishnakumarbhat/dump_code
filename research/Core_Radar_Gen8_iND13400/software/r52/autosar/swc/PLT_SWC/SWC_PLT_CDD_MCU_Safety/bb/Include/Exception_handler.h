#ifndef EXCEPTION_HANDLER_H_
#define EXCEPTION_HANDLER_H_
/*===========================================================================*\
 * FILE: Excpetion_handler.h
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
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "Std_Types.h"
#include "stdbool.h"
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
// #ifndef UNIT_TEST
// extern uint32 __USER_EXCEPTION_STACK_END;
// #endif

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/
/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void ExceptionHandler_Illegal_Instruction(void);
void ExceptionHandler_Abort_Prefetch(void);
void ExceptionHandler_Abort_Data(void);
void PreftechAbortExceptionTest(void);
void IllegalInstructionExceptionTest(void);
void DataAbortExceptionTest(void);
void GetExceptionInfo(uint8 Error);
void Set_Exception_Mode(uint8 Error);
void Restore_Exception_Mode(void);
void Set_Fault_Address(void);
extern void Log_ExceptionReason_Info(Dt_Memory_Exception_Info_T *Exception_Context, uint16 Resnum);
/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================

\*===========================================================================*/

#endif /*EXCEPTION_HANDLER_H_*/
