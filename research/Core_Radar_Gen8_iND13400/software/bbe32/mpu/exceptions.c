/**
 * @file exceptions.c
 * @brief Provide the implementations for the API to enable exception handling.
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
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <xtensa/xtruntime.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "exceptions.h"
#include "ipc_data.h"
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /*==================================================================================================
   *                                      GLOBAL VARIABLES
   ==================================================================================================*/
   // list of exceptions for which we override the default handler
   // (xtos_unhandled_exception) in xtos_exc_handler_table
   static const uint32_t dspDispExcCauses[] = {
      EXCCAUSE_ILLEGAL,
      EXCCAUSE_INSTR_ERROR,
      EXCCAUSE_LOAD_STORE_ERROR, // MPU
      EXCCAUSE_DIVIDE_BY_ZERO,
      EXCCAUSE_PC_ERROR,
      EXCCAUSE_PRIVILEGED, // MPU
      EXCCAUSE_UNALIGNED,
      EXCCAUSE_INSTR_DATA_ERROR,
      EXCCAUSE_LOAD_STORE_DATA_ERROR,
      EXCCAUSE_INSTR_ADDR_ERROR,
      EXCCAUSE_LOAD_STORE_ADDR_ERROR,
      EXCCAUSE_ITLB_MISS,
      EXCCAUSE_ITLB_MULTIHIT, // MPU
      EXCCAUSE_INSTR_RING,
      EXCCAUSE_INSTR_PROHIBITED, // MPU
      EXCCAUSE_DTLB_MISS,
      EXCCAUSE_DTLB_MULTIHIT, // MPU
      EXCCAUSE_LOAD_STORE_RING,
      EXCCAUSE_LOAD_PROHIBITED, // MPU
      EXCCAUSE_STORE_PROHIBITED // MPU
   };

#if XCHAL_HAVE_XEA3
   volatile ExcFrame Global_Exc_Frame = {0};
#else
volatile UserFrame Global_Exc_Frame = {0};
#endif

   /*==================================================================================================
   *                                       LOCAL FUNCTIONS
   ==================================================================================================*/
   volatile uint32_t Exception_Cause  = 0;
   volatile uint32_t Exception_Ccount = 0;
   volatile uint32_t Exception_VADDR  = 0;
   volatile uint32_t Exception_PS     = 0;
   volatile uint32_t Exception_EPC1   = 0;

   static void Exception_Handler(void *arg)
   {
      IPC_Shared_Buffers_T *ipc_buf_add = (IPC_Shared_Buffers_T *)Get_Ipc_Shared_Buffer_Base_Address();
      (void)arg; // Arg is unused, remove the compilation error here.
      Exception_Cause  = XT_RSR_EXCCAUSE();
      Exception_Ccount = XT_RSR_CCOUNT();
      Exception_VADDR  = XT_RSR_EXCVADDR();
      Exception_PS     = XT_RSR_PS();
      Exception_EPC1   = XT_RSR_EPC1();

      UserFrame *test                                   = (UserFrame *)arg;
      Global_Exc_Frame                                  = *test;
      ipc_buf_add->D2M_Debug_Msg.BBE32_Exception_Cause  = Exception_Cause;
      ipc_buf_add->D2M_Debug_Msg.BBE32_Exception_Ccount = Exception_Ccount;
      ipc_buf_add->D2M_Debug_Msg.Exception_VADDR        = Exception_VADDR;
      ipc_buf_add->D2M_Debug_Msg.Exception_PS           = Exception_PS;
      ipc_buf_add->D2M_Debug_Msg.Exception_EPC1         = Exception_EPC1;

      memcpy((void *)&ipc_buf_add->UserFrame, (void *)&Global_Exc_Frame, sizeof(UserFrame));
#ifndef UNIT_TEST
      while (true)
      {
      }; // halt the DSP here
#endif
   }

   /*==================================================================================================
   *                                       GLOBAL FUNCTIONS
   ==================================================================================================*/
   void Register_Exception_Handlers(void)
   {
      uint32_t i;

      for (i = 0; i < (sizeof(dspDispExcCauses) / sizeof(dspDispExcCauses[0])); i++)
      {
         // Sets the entries in xtos_exc_handler_table, which is used by the _UserExceptionVector
         (void)xtos_set_exception_handler(dspDispExcCauses[i], Exception_Handler, NULL);
      }
   }

   /*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
