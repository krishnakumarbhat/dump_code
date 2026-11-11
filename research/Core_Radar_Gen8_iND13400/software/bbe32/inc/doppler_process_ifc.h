#ifndef DOPPLER_PROCESS_IFC_H
#define DOPPLER_PROCESS_IFC_H
/**
 * @file doppler_process_ifc.h
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
 * Doppler processing wrapper definitions.
 *
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
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdbool.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "doppler_process_types.h"
#include "mem_pool.h"
#include "radar_sw_config.h"

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/
#define DOPPLER_RA_MAX_RUN_TIME_US (45U)
/** Max allowed Doppler + RDD processing time in microseconds */
#define MAX_DOPPLER_PROC_OVERRUN_TIME_US (26000U)
   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum Appl_Doppler_Return_Values_Tag
   {
      APPL_DOPPLER_NO_ERROR = 0,
      APPL_DOPPLER_TIMEOUT  = 1,
      APPL_DOPPLER_ERROR    = 2,
   } Appl_Doppler_Return_Values_T;

   /*===========================================================================*
    * Exported Object Declarations
    *===========================================================================*/
   /* Circular NCI, CI DSP internal buffer */
   extern uint16_t *rdop_avg_data_ptr[];

   /* Circular NCI Max, partial CI and BV DSP internal buffer */
   extern NCI_Circular_Buffer_Ptr_T rdop_avg_max;

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   Memory_Pool_Return_T Appl_Doppler_Dram1_Memory_Init(Mem_Pool_T *mem_pool);
   Memory_Pool_Return_T Appl_Doppler_Sram1_Memory_Init(Mem_Pool_T *mem_pool);
   Appl_Doppler_Return_Values_T __attribute__((noinline)) Appl_Doppler_Rdd_Processing(Radar_Look_T look_id);

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* DOPPLER_PROC_H */
