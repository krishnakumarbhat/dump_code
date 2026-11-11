#ifndef DSP_IT_MACROS_TEST_H
   #define DSP_IT_MACROS_TEST_H
/*===========================================================================*/
/**
 * @file dsp_it_macros_test.h
 *
 * Centralized SWE5 Integration Testing Hook Macros for BBE32 DSP Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Consolidates all SWE5 integration test macro hooks used across BBE32
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
 * @defgroup dsp_it_macros DSP Integration Test Macros
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
      #include "dsp_integration_test.h"
   #endif

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - Anglefinding Test Points
    *===========================================================================*/
   #if defined(Integration_Testing) && defined(Anglefinding_IT)
      /**
       * @brief Hook for Angle Finding input data receiver.
       *
       * Validates angle finding input data received from M2D IPC message.
       * Compares actual values against expected stub values set by debugger.
       *
       * @param ptr Pointer to Angle_Finding_Input_T structure
       * @param appl_out_ptr Pointer to AF_Appl_Output_T structure
       */
      #define SIT_AF_INPUT(ptr, appl_out_ptr) SIT_AF_Input_Receiver(ptr, appl_out_ptr)

      /**
       * @brief Hook for D2M message buffer provider.
       *
       * Provides access to D2M message buffer containing detection results.
       * Stubs output values when test interface matches before sending to R52.
       *
       * @param ptr Pointer to D2M message buffer structure
       */
      #define SIT_D2M_MSG_BUFFER(ptr) SIT_D2M_Msg_Buffer_Provider(ptr)

      /**
       * @brief Hook for dwell timestamp provider.
       *
       * Provides access to D2M message buffer for stubbing timestamp/dwell data.
       * Separated from main D2M provider to isolate timestamp-specific test cases.
       *
       * @param ptr Pointer to D2M message buffer structure
       */
      #define SIT_DWELL_TIMESTAMPS(ptr) SIT_Dwell_Timestamps_Provider(ptr)

      /**
       * @brief Hook for Angle Finding USC calibration receiver.
       *
       * Validates USC calibration data (cal matrices, LUTs, search ranges)
       * loaded into the AF module against expected values.
       *
       * @param ptr Pointer to AF_USC_T calibration structure
       */
      #define SIT_AF_USC(ptr) SIT_AF_USC_Receiver(ptr)

      /**
       * @brief Hook for Angle Finding Downselection receiver.
       *
       * Validates downselection initialization parameters including
       * thresholds, target report limits, and scoring configuration.
       *
       * @param ptr Pointer to AF_DownSelection_In_Out_Params_T structure
       */
      #define SIT_AF_DOWNSELECTION(ptr) SIT_AF_Downselection_Receiver(ptr)

      /**
       * @brief Hook for RCS computation receiver.
       *
       * Validates RCS azimuth and elevation rolloff limit arrays
       * computed from SMC calibration data.
       *
       * @param az_ptr Pointer to azimuth rolloff limit array
       * @param el_ptr Pointer to elevation rolloff limit array
       */
      #define SIT_COMPUTE_RCS(az_ptr, el_ptr) SIT_Compute_RCS_Receiver(az_ptr, el_ptr)
   #else
      #define SIT_AF_INPUT(ptr, appl_out_ptr) /* No operation */
      #define SIT_D2M_MSG_BUFFER(ptr)         /* No operation */
      #define SIT_DWELL_TIMESTAMPS(ptr)       /* No operation */
      #define SIT_AF_USC(ptr)                 /* No operation */
      #define SIT_AF_DOWNSELECTION(ptr)       /* No operation */
      #define SIT_COMPUTE_RCS(az_ptr, el_ptr) /* No operation */
   #endif                                     /* Integration_Testing && Anglefinding_IT */

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - IPC Transfer
    *===========================================================================*/
   #if defined(Integration_Testing)
      /**
       * @brief Hook for M2D IPC transfer receive.
       *
       * Receives SWE5 test data (interface number, stub values) from R52 to BBE32
       * via IPC payload. Called after receiving M2D IPC message on DSP side.
       *
       * @param ptr Pointer to M2D IPC payload structure
       */
      #define SIT_IPC_TRANSFER_M2D_RECEIVE(ptr) SIT_IPC_Transfer_M2D_Receive(ptr)

      /**
       * @brief Hook for D2M IPC transfer send.
       *
       * Sends SWE5 test results (validation status) from BBE32 to R52
       * via IPC payload. Called before sending D2M IPC message from DSP.
       *
       * @param ptr Pointer to D2M IPC payload structure
       */
      #define SIT_IPC_TRANSFER_D2M_SEND(ptr) SIT_IPC_Transfer_D2M_Send(ptr)
   #else
      #define SIT_IPC_TRANSFER_M2D_RECEIVE(ptr) /* No operation */
      #define SIT_IPC_TRANSFER_D2M_SEND(ptr)    /* No operation */
   #endif                                       /* Integration_Testing */

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - Radar Capability Test Points
    *===========================================================================*/
   #if defined(Integration_Testing) && defined(Radar_capability_IT)
      /**
       * @brief Hook for providing dynamic alignment data to Radar Capability.
       *
       * Provides access to dynamic alignment data structure used by Radar Capability.
       * Called in RC wrapper after mapping IPC data to RC input structure.
       *
       * @param ptr Pointer to dynamic alignment data structure
       */
      #define SIT_DYNAMIC_ALIGN_DATA(ptr) SIT_DYNAMIC_ALIGN_DATA_Receiver(ptr)
      /**
       * @brief Hook for receiving dynamic alignment data in Radar Capability.
       *
       * Validates dynamic alignment data received from M2D IPC message.
       * Compares actual values against expected stub values set by debugger.
       *
       * @param ptr Pointer to RC_Input_T structure containing dynamic alignment data
       */
      #define SIT_ALIGNMENT_LOG_DATA(ptr) SIT_ALIGNMENT_LOG_DATA_Provider(ptr)
      /**
       * @brief Hook for receiving average MMIC on-chip temperature data in Radar Capability.
       *
       * Validates average MMIC on-chip temperature data received from M2D IPC message.
       * Compares actual value against expected stub value set by debugger.
       *
       * @param ptr Pointer to RC_Input_T structure containing avg MMIC on-chip temp
       */
      #define SIT_AVG_MMIC_ONCHIP_TEMP_DATA(ptr) SIT_AVG_MMIC_ONCHIP_TEMP_DATA_Receiver(ptr)
   #else
      #define SIT_DYNAMIC_ALIGN_DATA(ptr)        /* No operation */
      #define SIT_ALIGNMENT_LOG_DATA(ptr)        /* No operation */
      #define SIT_AVG_MMIC_ONCHIP_TEMP_DATA(ptr) /* No operation */
   #endif                                        /* Integration_Testing && Radar_capability_IT */

   /*===========================================================================*
    * SWE5 Integration Testing Hooks - First Pass Test Points
    *===========================================================================*/
   #if defined(Integration_Testing) && defined(FirstPass_IT)
      /**
       * @brief Hook for First Pass input receiver (WI-365501 Ri).
       *
       * Called from Appl_First_Pass_Execute().
       *
       * @param ptr Pointer to Rdd_First_Pass_Input_T
       */
      #define SIT_FP_RDD_INPUT(ptr) SIT_FP_Input_Receiver(ptr)

      /**
       * @brief Hook for First Pass provider source (WI-365501 Pi).
       *
       * Called in Appl_Doppler_Rdd_Processing() before Appl_First_Pass_Execute().
       *
       * @param ptr Pointer array to rdop_avg_data_ptr
       */
      #define SIT_FP_OUTPUT_DATA(ptr) SIT_FP_Output_Data_Provider(ptr)
   #else
      #define SIT_FP_RDD_INPUT(ptr)   /* No operation */
      #define SIT_FP_OUTPUT_DATA(ptr) /* No operation */
   #endif                             /* Integration_Testing && FirstPass_IT */

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
#endif /* DSP_IT_MACROS_TEST_H */

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
