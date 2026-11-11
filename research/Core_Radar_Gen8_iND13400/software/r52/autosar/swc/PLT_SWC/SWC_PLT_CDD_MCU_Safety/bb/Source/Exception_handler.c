/*===========================================================================*/
/**
 * @file Excpetion_handler.c
 *
 * @todo This file is to handle exceptions
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "Exception_handler.h"
#include "retention_ram_data.h"
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
Dt_Memory_Exception_Info_T Exception_Context;

uint32 gException_Stack;
uint32 gException_R13Value  = 0;
uint32 gException_SPSRValue = 0;
uint32 gException_R14Value  = 0;
uint32 gException_IFARValue = 0;
uint32 gException_DFARValue = 0;
uint32 gLastCPSRvalue       = 0;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
void exception_asm_load(uint32 *value_regiter);
void Mcu_Reset(void);
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  ExceptionHandler_Illegal_Instruction
 *   This function is used to handle Illegal Instruction Exceptions
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#pragma clang optimize off
void ExceptionHandler_Illegal_Instruction(void)
{
#ifndef UNIT_TEST
   __asm(" mov R5, R14 ");
   exception_asm_load(&gException_R14Value); // load and store store the value of R14 in R5
   __asm(" mov R5, R13 ");                   // move the value of Link register to R5
   exception_asm_load(&gException_R13Value); // load and store store the value of R13 in R5
#endif
   GetExceptionInfo(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION);
   /*update this in failsafe */
   Log_ExceptionReason_Info(&Exception_Context, MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION);
   /*Reset through failsafe and log reset reason*/
   Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION);
}
#pragma clang optimize on
/******************************************************************************
 * Name:  ExceptionHandler_Abort_Prefetch
 *   This function is used to Abort Prefetch Exception handler
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#pragma clang optimize off
void ExceptionHandler_Abort_Prefetch(void)
{
#ifndef UNIT_TEST
   __asm(" mov R5, R14 ");
   exception_asm_load(&gException_R14Value); // load and store store the value of R14 in R5
   __asm(" mov R5, R13 ");                   // move the value of Link register to R5
   exception_asm_load(&gException_R13Value); // load and store store the value of R13 in R5
#endif
   GetExceptionInfo(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION);
   /*update this in failsafe */
   Log_ExceptionReason_Info(&Exception_Context, MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION);
   /*Reset through failsafe and log reset reason*/
   Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION);
   /* to log an trigger a reset*/
}
#pragma clang optimize on
/******************************************************************************
 * Name:  ExceptionHandler_Abort_Data
 *   This function is used to data abort Exception handler
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#pragma clang optimize off
void ExceptionHandler_Abort_Data(void)
{
   GetExceptionInfo(MCU_FAILSAFE_ABORT_DATA_EXCEPTION);
   /*update this in failsafe */
   Log_ExceptionReason_Info(&Exception_Context, MCU_FAILSAFE_ABORT_DATA_EXCEPTION);
   /*Reset through failsafe and log reset reason*/
   Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FAILSAFE_ABORT_DATA_EXCEPTION);
   /* to log an trigger a reset*/
}
#pragma clang optimize on
/******************************************************************************
 * Name:  GetExceptionInfo_ASM
 *   This function is used to get exception info
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#pragma clang optimize off
void GetExceptionInfo_ASM(uint8 Error)
{
#ifndef UNIT_TEST
   __asm(" mrs R5, cpsr ");             // move CPSR value to R5
   exception_asm_load(&gLastCPSRvalue); // load and store store the value of CPSR in R5

   if (Error == MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION)
   {
      __asm("cps  #0x1B");
      __asm(" mov R10, r5 ");
   }
   else if ((Error == MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION) || (Error == MCU_FAILSAFE_ABORT_DATA_EXCEPTION) ||
            (Error == OS_PROTECTION_MEMORY) || (Error == OS_PROTECTION_EXCEPTION))
   {
      __asm("cps  #0x17");
      __asm(" mov R10, r5 ");
      __asm(" mov R5, R14 ");
      exception_asm_load(&gException_R14Value); // load and store store the value of R14 in R5
      __asm(" mov R5, R13 ");                   // move the value of Link register to R5
      exception_asm_load(&gException_R13Value); // load and store store the value of R13 in R5
   }
   else
   {
      // Do nothing
   }

   __asm(" MRS R5, SPSR ");                   // move SPSR value to R5
   exception_asm_load(&gException_SPSRValue); // load and store store the value of SPSR in R5
   __asm(" MRC P15, #0, R5, C6, C0, #2 ");    // Move IFAR value in R5
   exception_asm_load(&gException_IFARValue);
   __asm(" MRC P15, #0, R5, C6, C0, #0 "); // move DFAR value in R5
   exception_asm_load(&gException_DFARValue);

   __asm(" mov R5, r10 ");              // move old CPSR value to R5
   exception_asm_load(&gLastCPSRvalue); // load and store store the value of CPSR in R5
   if ((gLastCPSRvalue & 0x1F) == 0x1F) // checking the prveious CPSR value and moving back to same mode
   {
      __asm("cps  #0x1F");
   }
   else if ((gLastCPSRvalue & 0x1F) == 0x1B)
   {
      __asm("cps  #0x1B");
   }
   else if ((gLastCPSRvalue & 0x1F) == 0x17)
   {
      __asm("cps  #0x17");
   }
   else if ((gLastCPSRvalue & 0x1F) == 0x10)
   {
      __asm("cps  #0x10");
   }
   else if ((gLastCPSRvalue & 0x1F) == 0x13)
   {
      __asm("cps  #0x13");
   }
   else
   {
      // do nothing
   }

#endif
}
#pragma clang optimize on
/******************************************************************************
 * Name:  Set_Fault_Address
 *   This function updates fault address fields based on IFAR/DFAR capture.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 ******************************************************************************/
#pragma clang optimize off
void Set_Fault_Address(void)
{
   if (gException_IFARValue != 0U)
   {
      Exception_Context.ExceptionCausingAddress = gException_R14Value - 4U; // Subtract to get the actual address of the exception
      Exception_Context.MemoryExceptionAddress  = gException_IFARValue;
   }
   else if (gException_DFARValue != 0U)
   {
      Exception_Context.ExceptionCausingAddress = gException_R14Value - 8U; // Subtract to get the actual address of the exception
      Exception_Context.MemoryExceptionAddress  = gException_DFARValue;
   }
   else
   {
      // Do nothing
   }
}
#pragma clang optimize on
/******************************************************************************
 * Name:  GetExceptionInfo
 *   This function is used to get exception info
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#pragma clang optimize off
void GetExceptionInfo(uint8 Error)
{
   if (Error == MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION)
   {
      GetExceptionInfo_ASM(Error);
      Exception_Context.IsMemException_Occured  = FALSE;
      Exception_Context.ExceptionCausingAddress = gException_R14Value - 2U; // Subtract to get the actual address of the exception
      Exception_Context.MemoryExceptionAddress  = gException_IFARValue;
   }
   else
   {
      GetExceptionInfo_ASM(Error);
      Exception_Context.IsMemException_Occured = TRUE;
      Set_Fault_Address();
   }
   Exception_Context.ExceptionType           = Error;
   Exception_Context.StackPointer            = gException_R13Value;
   Exception_Context.ExceptionStatusRegister = gException_SPSRValue;
}
