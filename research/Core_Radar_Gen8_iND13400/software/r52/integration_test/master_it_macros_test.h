#ifndef MASTER_IT_MACROS_TEST_H
   #define MASTER_IT_MACROS_TEST_H
/*===========================================================================*/
/**
 * @file master_it_macros_test.h
 *
 * Centralized SWE5 Integration Testing Hook Macros for R52 Master Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Consolidates all SWE5 integration test macro hooks used across R52
 *   core source files. Instead of duplicating macro definitions in each
 *   .c file, include this single header to access all SWE5 hooks.
 *   When testing flags are disabled, all macros expand to no-ops to
 *   avoid dead code and TiCS impacts.
 *
 * @section ABBR ABBREVIATIONS:
 *   - SIT  - Software Integration Testing
 *   - SWE5 - Software Engineering Level 5 (Integration Testing)
 *   - IPC  - Inter-Processor Communication
 *   - AF   - Angle Finding
 *   - D2M  - DSP to Master
 *   - M2D  - Master to DSP
 *   - USC  - Unit Specific Calibration
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWE5 Integration Test Framework Design
 *
 *   - Requirements Document(s):
 *     - Integration test framework for Gen8 radar system
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @defgroup master_it_macros Master Integration Test Macros
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

   #ifdef __cplusplus
extern "C"
{         /* ! Inclusion of header files should NOT be inside the extern "C" block */
   #endif /* __cplusplus */

   /*===========================================================================*
    * Header Includes (Conditional)
    *===========================================================================*/
   #if defined(Integration_Testing)
      #include "master_integration_test.h"
   #endif

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - Debug Control
    *===========================================================================*/
   #if defined(Integration_Testing)
   /**
    * @brief Global flag to control test execution from debugger.
    *
    * When Integration_Testing is enabled, the SIT_WAIT_FOR_DEBUGGER() macro
    * will spin until this flag is set to true by the debugger. This allows
    * test setup (setting stub values, interface numbers) before execution.
    */
   extern volatile bool SIT_Run;

      /**
       * @brief Macro to wait for debugger to attach and set SIT_Run = true.
       *
       * When Integration_Testing is enabled, execution halts at this point
       * until a debugger sets SIT_Run to true. This allows test setup before
       * execution continues.
       */
      #define SIT_WAIT_FOR_DEBUGGER()                                                                                             \
         do                                                                                                                       \
         {                                                                                                                        \
            while (!SIT_Run)                                                                                                      \
            {                                                                                                                     \
               /* Wait for debugger to set SIT_Run = true */                                                                      \
            }                                                                                                                     \
         } while (0)
   #else
      #define SIT_WAIT_FOR_DEBUGGER() /* No-op when Integration_Testing not enabled */
   #endif                             /* Integration_Testing */

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - Anglefinding Test Points
    *===========================================================================*/
   #if defined(Integration_Testing) && defined(Anglefinding_IT)
      /**
       * @brief Hook for M2D (Master-to-DSP) one-time provider.
       *
       * Provides one-time initialization data (e.g., radar position) to DSP.
       * Stubs values when test interface matches.
       *
       * @param ptr Pointer to one-time data structure
       */
      #define SIT_M2D_ONETIME(ptr) SIT_M2D_Onetime_Provider(ptr)

      /**
       * @brief Hook for M2D per-look provider.
       *
       * Provides per-look data (e.g., vehicle speed) to DSP for each radar look.
       * Stubs values when test interface matches.
       *
       * @param ptr Pointer to per-look data structure
       */
      #define SIT_M2D_PERLOOK(ptr) SIT_M2D_Perlook_Provider(ptr)
   #else
      #define SIT_M2D_ONETIME(ptr) /* No operation */
      #define SIT_M2D_PERLOOK(ptr) /* No operation */
   #endif                          /* Integration_Testing && Anglefinding_IT */

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - IPC Transfer
    *===========================================================================*/
   #if defined(Integration_Testing)
      /**
       * @brief Hook for M2D IPC transfer send.
       *
       * Sends SWE5 test data (interface number, stub values) from R52 to BBE32
       * via IPC payload. Called after preparing M2D IPC message.
       *
       * @param ptr Pointer to M2D IPC payload structure
       */
      #define SIT_IPC_TRANSFER_M2D_SEND(ptr) SIT_IPC_Transfer_M2D_Send(ptr)

      /**
       * @brief Hook for D2M IPC transfer receive.
       *
       * Receives SWE5 test results (validation status) from BBE32 to R52
       * via IPC payload. Called after receiving D2M IPC message.
       *
       * @param ptr Pointer to D2M IPC payload structure
       */
      #define SIT_IPC_TRANSFER_D2M_RECEIVE(ptr) SIT_IPC_Transfer_D2M_Receive(ptr)

      /**
       * @brief Hook for calibration data provider.
       *
       * Stubs USC and SMC calibration data for integration testing.
       * Called from Validate_Load_All_Calib_Data() in calibration handler.
       * Covers USC AF calibration, SMC angle finding params, downselection,
       * RCS rolloff limits, sensor mounting, and unambiguous velocity.
       */
      #define SIT_Calibration_Data() SIT_Calibration_Data_Provider()
   #else
      #define SIT_IPC_TRANSFER_M2D_SEND(ptr)    /* No operation */
      #define SIT_IPC_TRANSFER_D2M_RECEIVE(ptr) /* No operation */
      #define SIT_Calibration_Data()            /* No operation */
   #endif                                       /* Integration_Testing */

   #if defined(Integration_Testing) && defined(Radar_capability_IT)
      /**
       * @brief Hook for MMIC on-chip data provider.
       *
       * Stubs MMIC on-chip data (e.g., temperature) for integration testing.
       * Called during DSP processing when preparing M2D message.
       */
      #define SIT_MMIC_ONCHIP_DATA(ptr) SIT_MMIC_ONCHIP_DATA_Provider(ptr)
   #else
      #define SIT_MMIC_ONCHIP_DATA(ptr) /* No operation */
   #endif                               /* Integration_Testing && Radar_capability_IT */
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

   #ifdef __cplusplus
} /* extern "C" */
   #endif /* __cplusplus */

/** @} doxygen end group */
#endif /* MASTER_IT_MACROS_TEST_H */

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  DC          Dinesh ch
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  26-02-10      1.0              DC           EAH-7658
 *      Created initial SWE5 automation framework
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
