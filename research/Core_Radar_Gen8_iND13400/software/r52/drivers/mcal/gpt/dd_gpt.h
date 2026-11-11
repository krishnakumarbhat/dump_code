#ifndef DD_GPT_H /* { */
#define DD_GPT_H

/*===========================================================================*\
 * FILE: dd_gpt.h
 *===========================================================================
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Confidential – Restricted Aptiv information. Do not disclose.
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *  This file contains functions for GPT driver.
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
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     TODO: Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "Gpt.h"
#include "Gpt_Types.h"
#include "Platform_Types.h"
#include <stdint.h>
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#define SEC_2_MS (1000.0f)
#define SEC_2_US (1000000.0f)
#define MS_2_US  (1000.0f)
#define MS_2_SEC (0.001f)
#define US_2_SEC (0.000001f)

#define TIMERS_SRC_CLK() ((System_Clk_GetSysCurrentClock()) / 5)
#define COUNTS2SEC(c)    (uint32_t)((uint64_t)c * (uint64_t)TIMERS_SRC_CLK())
#define COUNTS2MS(c)     (uint32_t)((uint64_t)c * (uint64_t)TIMERS_SRC_CLK() / 1000UL)

#define TIMERS_SRC_CLK_B0() ((System_Clk_GetSysCurrentClock()) / 2)
#define COUNTS2SEC_B0(c)    (uint32_t)((uint64_t)c * (uint64_t)TIMERS_SRC_CLK_B0())
#define COUNTS2MS_B0(c)     (uint32_t)((uint64_t)c * (uint64_t)TIMERS_SRC_CLK_B0() / 1000UL)

#define MAX_RESOLUTION 0xFFFFFFFFU
/*===========================================================================*\
   * @Struct FHTI_Failure_Time | To store start time and delta time(FHTI) for faults
  \*===========================================================================*/
typedef struct
{
   uint64 StartTime;
   uint32 DeltaTime;
} FHTI_Failure_Time;

typedef enum
{
   GPT_PHY_TMR_0 = 0U,
   GPT_PHY_TMR_1,
   GPT_PHY_TMR_2,

#if (GPT_HARDWARE_VARIANT == GPT_B0_HARDWARE_VARIANT)
   GPT_PHY_TMR_3,
   GPT_PHY_TMR_4,
   GPT_PHY_TMR_5,
   GPT_PHY_TMR_6,
   GPT_PHY_TMR_7,
   GPT_PHY_TMR_8,
   GPT_PHY_TMR_9,
   GPT_PHY_TMR_10,
   GPT_PHY_TMR_11,
   GPT_PHY_TMR_12,
   GPT_PHY_TMR_13,
   GPT_PHY_TMR_14,
   GPT_PHY_TMR_15
#endif
} Gpt_TimerPhysicalChannelType;

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
extern volatile uint32_t Timestamp_Seconds;
extern void Init_GPT_Wrapper(void);
uint32_t Get_Timestamp_Milliseconds(void);
uint32_t Get_Elapsed_Time_Milliseconds(uint32_t starting_timestamp_ms);
extern void Set_Timer_Cnt_Value_ms(Gpt_TimerPhysicalChannelType gpt_phy_dev, float32 timer_val_ms);
uint32_t Set_Trigger_GPT_Time(uint32_t trigger_time);
uint32_t Set_Trigger_HWB0_GPT_Time(uint32_t trigger_time);
extern void Start_EcuSync_Timer(void);

#endif /* } DD_GPT_H */
