/*===========================================================================*\
 * FILE: Driver_PWM.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2024 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Mock header providing ARM_DRIVER_PWM types and PWM control constants
 * for unit testing of power_supply_clock module.
\*===========================================================================*/

#ifndef DRIVER_PWM_H
#define DRIVER_PWM_H

#include <stdint.h>

/*===========================================================================*\
 * ARM PWM Control Position Definitions
\*===========================================================================*/
#define ARM_PWM_CONTROL_POS       (0UL)
#define ARM_PWM_PRESCALER_POS     (8UL)
#define ARM_PWM_DITHER_CTROL_POS  (11UL)
#define ARM_PWM_STAIRCASE_EOC_POS (12UL)

/*===========================================================================*\
 * ARM PWM Control Codes
\*===========================================================================*/
#define ARM_PWM_DISABLE               (0x11UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_ENABLE                (0x10UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_MODE_STAIRCASE        (0x02UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_PRESCALER_DIV_1       (0x00UL << ARM_PWM_PRESCALER_POS)
#define ARM_PWM_DITHER_DISABLE        (0x00UL << ARM_PWM_DITHER_CTROL_POS)
#define ARM_PWM_STAIRCASE_EOC_ENABLE  (0x13UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_STAIRCASE_EOC_COUNT   (0x16UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_DITHER_STEP           (0x12UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_SLOPE_STEP            (0x17UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_SLOPE_STEP_MAX_PERIOD (0x18UL << ARM_PWM_CONTROL_POS)
#define ARM_PWM_SLOPE_STEP_MIN_PERIOD (0x19UL << ARM_PWM_CONTROL_POS)

/*===========================================================================*\
 * ARM_DRIVER_PWM Struct (CMSIS-Driver pattern)
\*===========================================================================*/
typedef struct
{
   int32_t (*Initialize)(void);
   int32_t (*Uninitialize)(void);
   void (*SetDutyCycle)(uint16_t u16_DutyCycle);
   void (*SetPeriodAndDuty)(uint32_t Period, uint16_t u16_DutyCycle);
   void (*SetOutputToIdle)(void);
   int32_t (*GetOutputState)(uint8_t *const value);
   int32_t (*Control)(uint32_t controlOperation, uint32_t arg);
   int32_t (*SetStaircaseExtSource)(uint8_t eocExtSource, uint8_t eocExLim, uint8_t eofExtSource, uint8_t eofExLim);
} ARM_DRIVER_PWM;

#define ARM_PWM_CTRL_NUMBER 2

extern ARM_DRIVER_PWM Driver_PWM[ARM_PWM_CTRL_NUMBER];

#endif /* DRIVER_PWM_H */
