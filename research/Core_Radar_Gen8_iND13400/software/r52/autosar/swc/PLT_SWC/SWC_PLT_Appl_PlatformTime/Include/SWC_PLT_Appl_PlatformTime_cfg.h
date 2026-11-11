#ifndef SWC_PLT_APPL_PLATFORMTIME_CFG_H
#define SWC_PLT_APPL_PLATFORMTIME_CFG_H

/*===========================================================================*\
 * FILE: SWC_PLT_Appl_PlatformTime_Cfg.h
 *===========================================================================
 * Copyright (C) 2024 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   Header file for SWC_PLT_Appl_PlatformTime.c
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "dd_gpt.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define STM_PERIOD       (0.000000004f)
#define PLATFORMTIME_MAX (343597383u)
#define PLT_TIMER_CH     ((Gpt_TimerPhysicalChannelType)3U)
/*
GPT_clk_Freq = 250Mhz
Max value for 32 bit counter = 2^32
Time at which the counter will overflow each time = (1/GPT_clk_Freq) * 2^32 = 17.179869184 secs
                                                  = (1/250e6) * 2^32 = 17179869.184 us
*/
#define OVER_FLOW_TIME_VALUE ((uint64_t)17179869)

#define GET_TIMER_CNT_VALUE_TICKS Get_Timer_Cnt_Value_Ticks
/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void Get_Platform_ustime(uint64 *inst_us_time);
void Get_Platform_mstime(uint32_t *inst_ms_time);
void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time);
void Platform_Ms_FromUstime_Update(void);
void Platform_Get_Ms_Total_FromUstime(uint32_t *total_ms);
void Platform_Get_Ms_Delta_FromUstime(uint32_t *delta_ms);
void Platform_Ms_FromUstime_Init(void);
void Platform_Ustime_Errorcheck(void);

#endif /*} SWC_PLT_APPL_PLATFORMTIME_CFG_H */
