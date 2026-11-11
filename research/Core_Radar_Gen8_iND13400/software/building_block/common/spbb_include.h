#ifndef SPBB_INCLUDE_H
#define SPBB_INCLUDE_H
/*===========================================================================*/
/**
 * @file
 * @brief File to include application header into SPBB world
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2024 Aptiv, All Rights Reserved.
 * @copyright Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 *
 * @section ABBR ABBREVIATIONS:
 *   - None
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * @addtogroup api
 * @{
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdbool.h>
#include <stdint.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "fixmac.h"
#include "radar_look_types.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "reuse.h"
#include "spbb_memmap.h"
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

#define DSP_CLK_FREQ_HZ (833000000)

   /************************************
    * Use this Define if you want to see all the SFR
    * such as Ra_Ptr, Mipi ,SysMem etc for debugging
    * *********************************/
   //#define ENABLE_HELPERS_SFR_DEBUG

   /*===========================================================================*\
   * Exported Preprocessor #define MACROS
   \*===========================================================================*/

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   typedef struct Module_Version_Tag
   {
      uint8_t module_id;
      uint8_t major;
      uint8_t minor;
      uint8_t patch;
   } Module_Version_T;

   /*===========================================================================*
    * Exported variables
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* SPBB_INCLUDE_H */
