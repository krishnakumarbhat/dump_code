#ifndef MIPI_TPGEN_IFC_H
#define MIPI_TPGEN_IFC_H
/**
 * @file mipi_ifc.h
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
 * Mipi wrapper interface definitions.
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
#include "api/mipi_helpers.h"
#include "mem_pool.h"
#include "radar_look_types.h"
#include "spbb_cfg.h"
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
#define MIPI_CHIRP_DONE_ISR (16U)
#define MIPI_FRAME_DONE_ISR (17U)
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void Appl_Mipi_Idm_Config(Radar_Look_T look_type);
   void Appl_IDM_Stat_Process(Radar_Look_T look_type);
   void Appl_MIPI_One_Time_Init(void);
   uint32_t Get_MIPI_Chirp_End_Timestamp(uint32_t chirp_idx);
   uint32_t Get_MIPI_Chirp_Count(void);

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* MIPI_TPGEN_IFC_H */
