#ifndef IDBB_INCLUDE_H
#define IDBB_INCLUDE_H
/*===========================================================================*/
/**
 * @file
 * @brief File to include application header into IDBB world
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2022 Aptiv, All Rights Reserved.
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
#include "id_stream.h"
#include "ipc_data.h"
#include "radar_look_types.h"
#include "radar_math.h"
#include "rdd_stream.h"
#include "smc_cal.h"
#include "vse_stream.h"
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*\
   * Exported Preprocessor #define MACROS
   \*===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Variables
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* IDBB_INCLUDE_H */
