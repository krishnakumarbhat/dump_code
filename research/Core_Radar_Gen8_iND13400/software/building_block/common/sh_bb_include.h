#ifndef SH_BB_INCLUDE_H
#define SH_BB_INCLUDE_H
/*===========================================================================*\
 * FILE: sh_bb_include.h
*===========================================================================
* Copyright (C) 2020 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*   Provides the necessary project header inclusion for SH BB.
*
* ABBREVIATIONS:
*   List of abbreviations used, or reference(s) to external document(s)
*
* TRACEABILITY INFO:
*   Design Document(s):
*
*   Requirements Document(s):
*
*   Applicable Standards (in order of precedence: highest first):
*     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
*
* DEVIATIONS FROM STANDARDS:
*   None.
*
\*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "Dynamic_alignment_stream.h"
#include "afbb_cfg.h"
#include "calib_stream.h"
#include "calibration_cfg.h"
#include "cdc_stream.h"
#include "debug_stream.h"
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "header_stream.h"
#include "id_stream.h"
#include "mmic_stream.h"
#include "partner_sensor_stream.h"
#include "radar_capability_stream.h"
#include "radar_look_types.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "spbb_cfg.h"
#include "static_alignment_stream.h"
#include "status_stream.h"
#include "stream_header.h"
#include "toi_ds_stream.h"
#include "toi_stream.h"
#include "vse_stream.h"
#ifdef FEATURE_ENABLE
   #include "bsis_stream.h"
   #include "mois_stream.h"
   #include "olp_stream.h"
#endif
#ifdef TRACKER_ENABLED
   #include "emb_tracker_stream_interface.h"
#endif
#ifdef STREAM_RX_ENABLE
   #include "vid_stream.h"
#endif
#include "smc_cal.h"
#include "usc_cal.h"

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

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

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
#endif /* SH_BB_INCLUDE_H */
