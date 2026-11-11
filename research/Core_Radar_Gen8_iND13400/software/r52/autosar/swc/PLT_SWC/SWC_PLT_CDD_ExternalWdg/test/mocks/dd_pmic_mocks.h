#ifndef DD_PMIC_MOCKS_H_
#define DD_PMIC_MOCKS_H_

/*===========================================================================*/
/**
 * @file dd_pmic_mocks.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the dd PMIC module using FFF
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "dd_pmic.h"
   /*===========================================================================*
    * Fake value functions - dd PMIC functions
    *===========================================================================*/

   DECLARE_FAKE_VALUE_FUNC(bool, Pmic_Clk_Sync_Enable);
   DECLARE_FAKE_VALUE_FUNC(bool, Pmic_Spread_Spectrum_Enable);
   DECLARE_FAKE_VALUE_FUNC(bool, Pmic_Spread_Spectrum_Disable);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Pmic_Check_Wdg_Dis_Status);
   DECLARE_FAKE_VOID_FUNC(Pmic_Watchdog_Init);
   DECLARE_FAKE_VOID_FUNC(Pmic_Watchdog_Service);
   DECLARE_FAKE_VOID_FUNC(Pmic_Fault_Injection_XCP, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Write_Data, uint32_t, uint8_t, const uint8_t *, uint32_t, boolean);
   DECLARE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Read_Data, uint32_t, uint8_t, uint8_t *, uint32_t);
/* Reset fake functions */
#define FFF_FAKES_PMIC_LIST(FAKE)                                                                                                 \
   FAKE(Pmic_Clk_Sync_Enable)                                                                                                     \
   FAKE(Pmic_Spread_Spectrum_Enable)                                                                                              \
   FAKE(Pmic_Spread_Spectrum_Disable)                                                                                             \
   FAKE(Pmic_Check_Wdg_Dis_Status)                                                                                                \
   FAKE(Pmic_Watchdog_Init)                                                                                                       \
   FAKE(Pmic_Watchdog_Service)                                                                                                    \
   FAKE(I2c_Write_Data)                                                                                                           \
   FAKE(I2c_Read_Data)                                                                                                            \
   FAKE(Pmic_Fault_Injection_XCP)

#ifdef __cplusplus
}
#endif
#endif
