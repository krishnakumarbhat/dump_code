/**
 * @file get_r52_time_from_bbe32.c
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * BBE32-side helper API to estimate current R52 global time.
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
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "get_r52_time_from_bbe32.h"
#include "chandra_sfrs_base.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "timers_sfrs.h"
#include <stdint.h>

/* ========================================================================== */
/*                           Macro Definitions                                */
/* ========================================================================== */
#ifndef __IO
   #define __IO volatile
#endif

#define TIMERS ((__IO TIMERS_SFRS_t *)TIMERS_base)

/* Macro for timestamp workaround when middle dwell time is 0 */
#define TIMESTAMP_WORKAROUND_HIL (30000U) /* 30 ms */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *      Estimate current R52 global time.
 *
 *  @retval
 *      Estimated current R52 time in microseconds.
 */
uint64_t Get_R52_Time_From_BBE32(void)
{
   /* Get the R52 sync time and ticks to be used for estimating current R52 time */
   volatile M2D_Msg_T *p_m2d_msg_ptr     = Get_IPC_M2D_Buffer();
   GLOB_TS_STRUCT_TYPE r52_time_for_sync = p_m2d_msg_ptr->payload.r52_time_for_sync;
   uint32_t r52_sync_ticks               = p_m2d_msg_ptr->payload.r52_ticks_for_sync;

   /* Get the current R52 ticks */
   uint32_t current_ticks = TIMERS->TIMER1CURRENTVAL;

   /* Calculate the difference between sync and current ticks, handling rollover */
   /* TIMERS->TIMER1CURRENTVAL ticks count down, not up */
   uint32_t delta_ticks;
   if (r52_sync_ticks >= current_ticks)
   {
      delta_ticks = r52_sync_ticks - current_ticks;
   }
   else
   {
      delta_ticks = (UINT32_MAX - current_ticks) + r52_sync_ticks + 1U;
   }

   /* Calculate the estimated current R52 time in microseconds */
   uint64_t delta_time_us    = ((uint64_t)delta_ticks * NS_PER_TICK) / NS_PER_US;
   uint64_t r52_sync_time_us = (r52_time_for_sync.ts_secs * US_PER_S) + (r52_time_for_sync.ts_nanosecs / NS_PER_US);
   return delta_time_us + r52_sync_time_us;
}

/**
 *  @b Description
 *  @n
 *      Estimate current R52 global time for HIL, using only the downselection detection timestamp so that the estimate does
 *      not depend on R52/BBE32 tick synchronization.
 *
 *  @param[in] p_ipc_d2m Pointer to the IPC D2M message.
 *
 *  @retval
 *      Estimated current R52 time in microseconds.
 */
uint64_t Get_HIL_R52_Time_From_BBE32(D2M_Msg_T *p_ipc_d2m)
{
   /* Down-selection stream detection timestamp */
   static uint64_t timestamp_us = 0;
   timestamp_us = ((uint64_t)p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec * US_PER_S) +
                  (p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns / NS_PER_US) +
                  TIMESTAMP_WORKAROUND_HIL;

   return timestamp_us;
}
