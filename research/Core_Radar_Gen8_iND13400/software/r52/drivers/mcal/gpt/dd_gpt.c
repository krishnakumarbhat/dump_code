/*===========================================================================*\
 * FILE: dd_gpt.c
 *===========================================================================
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Confidential – Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 *  This file a wrapper for the GPT MCAL module to help abstract the HW
 *  away from the SW. It provides APIs to users which are in the time
 *  domain instead of in ticks, so that the users do not need to know what
 *  frequencies are used in the timers.
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
#include "dd_gpt.h"
#include "Gpt.h"
#include "chandra_sfrs_base.h"
#include "system_clk.h"
#include "timers_sfrs.h"
#if (TRUE == XCP_FAULT_INJECTION)
   #include "boot_interface.h"
   #include "platformtime.h"
   #include "retention_ram_data.h"
   #define MCU_STARTUP_FAULT (13U)
#endif
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/
#define US_TIMESTAMP_MAX_VALUE_S  3600u /* The us timestamp rolls over every hour and can be used to time up to one hour */
#define US_TIMESTAMP_MAX_VALUE_MS (US_TIMESTAMP_MAX_VALUE_S * 1000u)
#define US_TIMESTAMP_MAX_VALUE_US (US_TIMESTAMP_MAX_VALUE_S * 1000000u)

#define GPT_TRIGGER_SET_TIME_MS    1
#define GPT_TRIGGER_SET_TIME_10_MS 10
#define GPT_TRIGGER_SET_TIME_50_MS 50
#define GPT_TRIGGER_SET_TIME_US    1

#define GPT_NUM_OF_CHNS_MAX 16
#define GPT_FIRST_SET       3
#define GPT_SECOND_SET      16

#define TIMERS_CONTROL_REG 0x91923044
#define TIMERS_LOAD_COUNT  0x9192303C
#define TIMERS_4_CTRL      ((__IO uint32_t *)TIMERS_CONTROL_REG)
#define TIMERS_4_LOAD      ((__IO uint32_t *)TIMERS_LOAD_COUNT)
/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * External Object Definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
volatile uint32_t Timestamp_Seconds                 = 0u;
volatile uint32_t Timestamp_Milliseconds            = 0u;
uint32_t cnt_ms                                     = 0u;
volatile float32 GPT_Period[GPT_NUM_OF_CHNS_MAX]    = {0.0f};
volatile float32 GPT_Frequency[GPT_NUM_OF_CHNS_MAX] = {0.0f};

/*===========================================================================*\
 * Local Function Prototypes
 *
\*===========================================================================*/

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/**
 * FUNCTION:Init_GPT_Wrapper
 *  This function initializes the GPT Wrapper. It must be called before any fucnctions
 *  to read or write to the timers in physical units.
 *
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return         none
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Init_GPT_Wrapper}
 */
void Init_GPT_Wrapper(void)
{
   uint32_t trigger_ms_timer;
   uint32_t i = 0;
   float32 clk_freq;
   float32 clk_period;

   clk_freq   = (float32)TIMERS_SRC_CLK();
   clk_period = (1.0f / clk_freq);

   Gpt_Init(&Gpt_Config);

   for (i = 0; i < GPT_FIRST_SET; i++)
   {
      GPT_Frequency[i] = clk_freq;
      GPT_Period[i]    = clk_period;
   }

   clk_freq   = (float32)TIMERS_SRC_CLK_B0();
   clk_period = (1.0f / clk_freq);

   for (i = GPT_FIRST_SET; i < GPT_SECOND_SET; i++)
   {
      GPT_Frequency[i] = clk_freq;
      GPT_Period[i]    = clk_period;
   }

   trigger_ms_timer = Set_Trigger_GPT_Time(GPT_TRIGGER_SET_TIME_MS); // Timestamp at 1ms
   Gpt_StartTimer(GPT_PHY_TMR_2, trigger_ms_timer);
   Gpt_EnableNotification(GPT_PHY_TMR_2);

#if (GPT_HARDWARE_VARIANT == GPT_B0_HARDWARE_VARIANT)
   trigger_ms_timer = Set_Trigger_HWB0_GPT_Time(GPT_TRIGGER_SET_TIME_10_MS);
   Gpt_StartTimer(GPT_PHY_TMR_3, trigger_ms_timer);
   #ifndef UNITTEST
   *TIMERS_4_LOAD = 0xFFFFFFFF; /* Load desired value to timer 4 */
   *TIMERS_4_CTRL = 1U;         /* Enable timer 4 in free running mode */
   #endif
   Gpt_EnableNotification(GPT_PHY_TMR_3);

   Gpt_StartTimer(GPT_PHY_TMR_4, (uint32_t)MAX_RESOLUTION - 1u);
#endif
#if (TRUE == XCP_FAULT_INJECTION)

   if (Retention_Ram_Data.fhti_test_data.failure_name == MCU_STARTUP_FAULT)
   {
      /* Update Failure Name */
      Failure_name = MCU_STARTUP_FAULT;

      /* Update Start Time */
      // if (Failure_time[Failure_name].StartTime == 0)
      // {
      // Failure_time[Failure_name].StartTime = Get_Timestamp_us();
      // }
      /* Fault Injection - Not starting the platform timer to set mcu startup fault */
      Gpt_StopTimer(GPT_PHY_TMR_3);
   }
   else
   {
      /*Do Nothing*/
   }

#endif
}

/**
 * FUNCTION: Get_Timestamp_Milliseconds
 *  This function provides an timestamp in milliseconds
 *
 * \param[in]     none
 *
 * \return         uint32_t timestamp_ms - A timestamp in milliseconds
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Get_Elapsed_Time_Milliseconds}
 */
uint32_t Get_Timestamp_Milliseconds(void)
{
   return Timestamp_Milliseconds;
}

/**
 * FUNCTION: Get_Elapsed_Time_Milliseconds
 *  This function provides an elapsed time when provided a starting timestamp,
 *    which should be obtained via Get_Timestamp_Milliseconds()
 *
 * \param[in]     starting_timestamp_ms - A starting timestamp obtained
 *                from the function Get_Timestamp_Milliseconds()
 *
 * \return         uint32_t elapsed_time_ms - The elapsed time in milliseconds
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 */
uint32_t Get_Elapsed_Time_Milliseconds(uint32_t starting_timestamp_ms)
{
   return Timestamp_Milliseconds - starting_timestamp_ms;
}

/**
 * FUNCTION:Set_Timer_Cnt_Value_ms
 *  This function sets a given timer counts to the number of milliseconds
 *  provided as an input argument
 *
 * \param[in]     Gpt_TimerPhysicalChannelType gpt_phy_dev
 *                float32 timer_val_ms
 *
 * \return         none
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Set_Timer_Cnt_Value_ms}
 */
void Set_Timer_Cnt_Value_ms(Gpt_TimerPhysicalChannelType gpt_phy_dev, float32 timer_val_ms)
{
   uint32_t ticks;
   float32 temp_float;
   if (gpt_phy_dev < GPT_NUM_OF_CHNS_MAX)
   {
      /* desired timer / 1,000 ms/s * timer frequency */
      temp_float = (timer_val_ms * MS_2_SEC * GPT_Frequency[gpt_phy_dev]);
      ticks      = (uint32_t)temp_float;

      Gpt_StopTimer(gpt_phy_dev);

      Gpt_StartTimer(gpt_phy_dev, ticks);
   }
}

/**
 * @fn            Set_Trigger_GPT_Time
 * @ID
 * @requirements  Requirement IDs here
 * @design        Design reference here
 * @brief         Set Trigger time value in ms for timers.
 * @param [in]    Timer value
 * @param [in]    None
 * @param [out]   None
 * @return        Timer value in milliseconds
 */
uint32_t Set_Trigger_GPT_Time(uint32_t trigger_time)
{
   uint32_t timer_val;

   timer_val = COUNTS2MS(trigger_time);
   return (timer_val);
}

/**
 * @fn            Set_Trigger_HWB0_GPT_Time
 * @ID
 * @requirements  Requirement IDs here
 * @design        Design reference here
 * @brief         Set Trigger time value in ms for timers for B0 board.
 * @param [in]    Timer value
 * @param [in]    None
 * @param [out]   None
 * @return        Timer value in milliseconds
 */
uint32_t Set_Trigger_HWB0_GPT_Time(uint32_t trigger_time)
{
   uint32_t timer_val;

   timer_val = COUNTS2MS_B0(trigger_time);
   return (timer_val);
}

/**
 * @fn            Gpt_Notification_Channel2
 * @ID
 * @requirements  Requirement IDs here
 * @design        Design reference here
 * @brief         Notification for the timeout period.
 * @param [in]    None
 * @param [in]    None
 * @param [out]   None
 * @return        None
 */
void Free_Running_Timer_Notification(void)
{
   Timestamp_Milliseconds++;
   cnt_ms++;
   if (cnt_ms >= 1000)
   {
      cnt_ms = 0;
      Timestamp_Seconds++;
   }
}

/**
 * FUNCTION:Start_EcuSync_Timer
 *  This function initializes the radar trigger timer. It must be called only after StbM is initialized
 *
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return         none
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Start_EcuSync_Timer}
 */
void Start_EcuSync_Timer(void)
{
   uint32_t trigger_ms_timer;

   trigger_ms_timer = Set_Trigger_GPT_Time(GPT_TRIGGER_SET_TIME_50_MS);
   Gpt_StartTimer(GPT_PHY_TMR_1, trigger_ms_timer);
   Gpt_EnableNotification(GPT_PHY_TMR_1);
}
