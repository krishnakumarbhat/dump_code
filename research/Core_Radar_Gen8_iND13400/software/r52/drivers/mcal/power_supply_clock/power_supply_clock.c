/*===========================================================================*\
 * FILE: power_supply_clock.c
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *    This file contains functions to initilize 2Mhz & 8Mhz power supply clock with dithering enabled .
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

#include "Std_Types.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#include "chandra_sfrs_base.h"

#include "power_supply_clock.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#ifdef DEVELOPMENT_ONLY /* These PWM outputs are not needed with PMIC used in Gen8 */
   /* PS_CLK_4MHz / PWM_1 and HSD_EN / PWM_0 are not needed in Gen8 */
   /* PS_CLK_4MHz is not needed in as PMIC creates its own clock    */
   /* HSD_EN is not used for this application */
   #define PS_2MHZ_CLK_DITHER_ENABLE CLOCK_ENABLED
   #define PS_8MHZ_CLK_DITHER_ENABLE CLOCK_ENABLED
   #if (PS_2MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
      #define PS_2MHZ_CLK_DITHER() PS_2MHz_Clk_Dithering()
   #else
      #define PS_2MHZ_CLK_DITHER() ((Std_ReturnType)0)
   #endif /* End of PS_2MHZ_CLK_DITHER_ENABLE */
   #if (PS_8MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
      #define PS_8MHZ_CLK_DITHER() PS_8MHz_Clk_Dithering()
   #else
      #define PS_8MHZ_CLK_DITHER() ((Std_ReturnType)0)
   #endif /* End of PS_8MHZ_CLK_DITHER_ENABLE */
#endif

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

#if (PS_2MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
extern ARM_DRIVER_PWM Driver_Pwm[2];
static ARM_DRIVER_PWM *PwmDvr0 = &Driver_Pwm0;
#endif /*End of PS_2MHZ_CLK_DITHER_ENABLE*/
#if (PS_8MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
extern ARM_DRIVER_PWM Driver_Pwm1;
static ARM_DRIVER_PWM *PwmDvr1 = &Driver_Pwm1;
#endif /*End of PS_8MHZ_CLK_DITHER_ENABLE*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (PS_2MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
static Std_ReturnType PS_2MHz_Clk_Dithering(void);
#endif /*End of PS_2MHZ_CLK_DITHER_ENABLE*/

#if (PS_8MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
static Std_ReturnType PS_8MHz_Clk_Dithering(void);
#endif /*End of PS_8MHZ_CLK_DITHER_ENABLE*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

#if (PS_2MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
/*****************************************************************************
 *. Name: PS_2MHz_Clk_Dithering
 *.    This function enables the pwm Channel0 and generate a frequency in range between 1.7Mhz to 2.6Mhz
 *.
 *. Parameters: void
 *.
 *. Return Value:Std_ReturnType
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static Std_ReturnType PS_2MHz_Clk_Dithering(void)
{
   static Std_ReturnType return_value;
   return_value |= Driver_PWM[0].Initialize();
   return_value |= Driver_PWM[0].Control(ARM_PWM_DISABLE, 1);
   return_value |= Driver_PWM[0].Control(ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE, 0);
   return_value |= Driver_PWM[0].Control(ARM_PWM_STAIRCASE_EOC_ENABLE, 0x1);
   return_value |= Driver_PWM[0].Control(ARM_PWM_STAIRCASE_EOC_COUNT, 0xFF);
   return_value |= Driver_PWM[0].Control(ARM_PWM_DITHER_STEP, 0x1);
   return_value |= Driver_PWM[0].Control(ARM_PWM_SLOPE_STEP, 0x2);
   return_value |= Driver_PWM[0].Control(ARM_PWM_SLOPE_STEP_MAX_PERIOD, 0x93);
   return_value |= Driver_PWM[0].Control(ARM_PWM_SLOPE_STEP_MIN_PERIOD, 0x61);
   return_value |= Driver_PWM[0].Control(ARM_PWM_ENABLE, 1);
   return return_value;
}
#endif /*end of PS_2MHZ_CLK_DITHER_ENABLE*/

#if (PS_8MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
/*****************************************************************************
 *. Name: PS_8MHz_Clk_Dithering
 *.    This function enables the pwm Channel1 and generate a frequency in range between 7.2Mhz to 8.6Mhz
 *.
 *. Parameters: void
 *.
 *. Return Value:Std_ReturnType
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static Std_ReturnType PS_8MHz_Clk_Dithering(void)
{
   static Std_ReturnType return_value;
   return_value |= Driver_PWM[1].Initialize();
   return_value |= Driver_PWM[1].Control(ARM_PWM_DISABLE, 1);
   return_value |= Driver_PWM[1].Control(ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE, 0);
   return_value |= Driver_PWM[1].Control(ARM_PWM_STAIRCASE_EOC_ENABLE, 0x1);
   return_value |= Driver_PWM[1].Control(ARM_PWM_STAIRCASE_EOC_COUNT, 0xFF);
   return_value |= Driver_PWM[1].Control(ARM_PWM_DITHER_STEP, 0x1);
   return_value |= Driver_PWM[1].Control(ARM_PWM_SLOPE_STEP, 0x1);
   return_value |= Driver_PWM[1].Control(ARM_PWM_SLOPE_STEP_MAX_PERIOD, 0x22);
   return_value |= Driver_PWM[1].Control(ARM_PWM_SLOPE_STEP_MIN_PERIOD, 0x1D);
   return_value |= Driver_PWM[1].Control(ARM_PWM_ENABLE, 1);
   return return_value;
}
#endif /*end of PS_8MHZ_CLK_DITHER_ENABLE*/

#ifdef DEVELOPMENT_ONLY
   #if (PS_CLOCK_INIT_ENABLE == CLOCK_ENABLED)
/*****************************************************************************
 *. Name: PS_Clock_Init
 *.    This function will initilize and run both 2Mhz and 8Mhz dithering.
 *.
 *. Parameters: void
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void PS_Clock_Init(void)
{
   PS_2MHZ_CLK_DITHER();

   PS_8MHZ_CLK_DITHER();
}
   #endif /*end of PS_CLOCK_INIT_ENABLE*/
#endif    /*end of DEVELOPMENT_ONLY*/
