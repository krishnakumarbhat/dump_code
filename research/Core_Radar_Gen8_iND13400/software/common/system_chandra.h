/**************************************************************************/ /**
                                                                              * @file     system_chandra.h
                                                                              * @brief    CMSIS Cortex-R52 Device Peripheral Access
                                                                              *Layer Header File
                                                                              * @version  V5.00
                                                                              * @date     02. March 2016
                                                                              ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_CHANDRA_H
#define SYSTEM_CHANDRA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define REF_CLK_FREQ_HZ          40000000UL
#define PLL_CLK_FPGA_FREQ_HZ     (500000000UL / 20UL)
#define PLL_CLK_REDUCED_FREQ_HZ  416666666UL
#define PLL_CLK_FULL_FREQ_HZ     500000000UL
#define CRG_PLL_CTRL_CLK_SEL_PLL 1

   /**
     \brief Setup the microcontroller system.

      Initialize the System and update the SystemCoreClock variable.
    */
   extern void SystemInit(void);

   /**
     \brief  Get SystemCoreClock.

      Return the SystemCoreClock based on the current core Clock retrieved from cpu registers.s
    */
   extern uint32_t GetSystemClock(void);

   /**
     \brief  PLL initialisation sequence.

     Setup the PLL and perform a calibration of the PLL
    */
   extern void PllInit(void);

   /**
     \brief  Switch System clock to PLL clock

     Switch the System clock to the PLL generated clock
    */
   extern void SysClockSwitchToPllClock(void);

   /**
     \brief  Switch System clock to REF clock

     Switch the System clock to the output of the 'reference oscillator' (40MHz)
    */
   extern void SysClockSwitchToRefClock(void);

#ifdef __arm__
   extern void ensureInterruptsNotMasked(void); // TODO: o this might need a home somewhere more r52-generic?
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_CHANDRA_H__ */
