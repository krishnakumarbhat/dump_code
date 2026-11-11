#ifndef RANGE_PROCESS_IFC_H
#define RANGE_PROCESS_IFC_H
/**
 * @file range_process_ifc.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2021 Aptiv. All rights reserved.
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
#include "mem_pool.h"
#include "radar_look_types.h"
#include "range_process_types.h"
#include "spbb_cfg.h"
#include "xcp_adc_logging.h"
#include <stdbool.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
#define RANGE_PROCESSING_TIMEOUT_US (30000)
#define RA_CMD_DONE_ISR             (13U)

/* The maximum amount of time expected for MMIC triggering to take */
#define MAX_ALLOWED_CHIRP_TIME_INCREASE_US (2000U)
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum Appl_Range_Return_Values_Tag
   {
      APPL_RANGE_NO_ERROR = 0,
      APPL_RANGE_TIMEOUT  = 1,
      APPL_RANGE_ERROR    = 2,
   } Appl_Range_Return_Values_T;

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/
   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   extern uint32_t RangeProc_OutputDataCube[COMP_RFFT_CUBE_SIZE_IN_32BIT_WORDS][K_MAX];

   bool Appl_Range_Process_Init(Radar_Look_T look_type);

   Appl_Range_Return_Values_T __attribute__((section(".sram0.text")))
   Check_For_Range_Process_Complete_Timeout_Check(Mem_Pool_T *mem_pool);

   void Appl_Range_Process_Chirp_Callback(void *arg);
   void Appl_Range_Process_Push_Ra_Commands(void);
   uint32_t Get_Range_Procesing_Done_Time(void);
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* RANGE_PROC_H */
