/**
 * @file get_r52_time_from_bbe32.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * BBE32-side helper API to estimate current R52 global time function declaration.
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
 *     - @todo Update list of applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 */
/*==========================================================================*/
#ifndef GET_R52_TIME_FROM_BBE32_H
#define GET_R52_TIME_FROM_BBE32_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ipc_data.h"
#include <stdint.h>

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#define US_PER_S    (1000000ULL)
#define NS_PER_US   (1000ULL)
#define NS_PER_TICK (10ULL)

/* ========================================================================== */
/*                      Function Declarations                                 */
/* ========================================================================== */
#ifdef __cplusplus
extern "C"
{
#endif

   uint64_t Get_R52_Time_From_BBE32(void);
   uint64_t Get_HIL_R52_Time_From_BBE32(D2M_Msg_T *p_ipc_d2m);

#ifdef __cplusplus
}
#endif

#endif /* GET_R52_TIME_FROM_BBE32_H */
