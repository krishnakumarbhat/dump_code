#ifndef PLATFORMTIME_H
#define PLATFORMTIME_H

/*****************************************************************************
 * Copyright 2013 Delphi Technologies, Inc., All Rights Reserved
 *
 * CM Synergy Header
 * %full_name:
 * %created_by:
 * %date_created:   Wed Feb  20 2018 %
 *
 * File Description:
 *   This file contains the platformtime functionality
 *
 * Deviations from software standards: none
 *
 * Additional information contained in procedure header blocks:
 *
 * Updates to areas outside the scope of procedures:
 *
 ****************************************************************************/

/*************************
 * #includes
 **************************/
#include "SWC_PLT_Appl_PlatformTime_cfg.h"
#include "reuse.h"
/*************************
 * #defines
 **************************/
#define SEC_2_US                   (1000000.0f)
#define PLT_MAX_FAULT_NUMBER       (20U)
#define PLT_FAULT_TYPE_CODED_FALSE (0U)
#define PLT_FAULT_TYPE_CODED_TRUE  (1U)
#define MS_PLTTIME_MUL             (10u)

/*************************
 * Typedefs
 *************************/

/*************************
 * Constants
 *************************/
/*===========================================================================*/
/* Enumeration                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* Structures                                                              */
/*===========================================================================*/

/************************
 * Global variables
 ************************/
#if (TRUE == XCP_FAULT_INJECTION)
   #ifndef UNIT_TEST
extern FHTI_Failure_Time Failure_time[PLT_MAX_FAULT_NUMBER];
extern uint8_t Failure_name;
   #else
FHTI_Failure_Time Failure_time[PLT_MAX_FAULT_NUMBER];
uint8 Failure_name;
   #endif
#endif
#if (TRUE == XCP_FAULT_INJECTION)
   #define REMOVE_FAULT 0x02U
   #define INJECT_FAULT 0x01U
#endif
#ifdef UNIT_TEST
uint32_t Mstime_10ms;
#else
static uint32_t Mstime_10ms;
#endif
static uint64 Plt_Timer_Start_Ustime;
/************************
 * function prototypes
 ***********************/
void Get_PlatformTime_Init(void);
void Get_Platform_ustime(uint64 *inst_us_time);
void Get_Platform_mstime(uint32_t *inst_ms_time);
void Platform_Ustime_Errorcheck(void);
void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time);
void Get_Platform_Elapsed_mstime(uint32_t *inst_ms_time, uint32_t start_time);
uint64_t Get_Timer_Cnt_Value_Ticks(uint8 *overflow_count);
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void PlatformTime_Functionality_Test(void);
#endif
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void PlatformTime_Integration_Test(volatile uint8 *tr_platformtime);
#endif
/*============================================================================*\
 * FILE REVISION HISTORY
 *-----------------------------------------------------------------------------
 *                 SUMMARY OF CHANGES
 *
 *  *  DATE          REV         AID          SCR         TASK
 *  ---------------------------------------------------------------------------
   15-04-22         1.0         Nethaji        EEG-3643     provide platformtime
 *  ---------------------------------------------------------------------------
\*============================================================================*/

#endif /*PLATFORMTIME_H */
