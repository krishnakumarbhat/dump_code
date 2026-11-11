#ifndef DYNAMIC_STREAM_HELPER_H
#define DYNAMIC_STREAM_HELPER_H
/*===========================================================================*\
* FILE: dynamic_stream_helper.h
*===========================================================================
* Copyright 2026 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*       Provide shim layer to pull dynamic array sizes from
*       radar_sw_config.h or use a fixed value for PC_RESIM
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

#ifndef PC_RESIM
   /* grab AF_MAX_NUM_DET, MAX_TARGET_REPORTS, MAX_DETS_FIRST_PASS from SMC */
   #include "radar_sw_config.h"
#else
   /* define maximum theoretical sizes for PC_RESIM */
   #define AF_MAX_NUM_DET      (6000U)
   #define MAX_TARGET_REPORTS  (3000U)
   #define MAX_DETS_FIRST_PASS (4000U)
#endif

#endif /* DYNAMIC_STREAM_HELPER_H */
