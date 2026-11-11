/*===========================================================================*/
/**
 * @file dd_pmic_mocks.cc
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
 * Fake function declarations for the dd PMIC module methods.
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

#ifdef __cplusplus
extern "C"
{
#endif
   /*===========================================================================*
    * C Header Files
    *===========================================================================*/

#include "dd_pmic_mocks.h"

   /*===========================================================================*
    * Fake value functions - dd PMIC functions
    *===========================================================================*/

   DEFINE_FAKE_VALUE_FUNC(bool, Pmic_Clk_Sync_Enable);
   DEFINE_FAKE_VALUE_FUNC(bool, Pmic_Spread_Spectrum_Enable);
   DEFINE_FAKE_VALUE_FUNC(bool, Pmic_Spread_Spectrum_Disable);
   DEFINE_FAKE_VALUE_FUNC(uint8_t, Pmic_Check_Wdg_Dis_Status);
   DEFINE_FAKE_VOID_FUNC(Pmic_Watchdog_Init);
   DEFINE_FAKE_VOID_FUNC(Pmic_Watchdog_Service);
   DEFINE_FAKE_VOID_FUNC(Pmic_Fault_Injection_XCP, uint8_t);
   DEFINE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Write_Data, uint32_t, uint8_t, const uint8_t *, uint32_t, boolean);
   DEFINE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Read_Data, uint32_t, uint8_t, uint8_t *, uint32_t);

   /* Global variable used by XCP fault injection */
   volatile uint8_t PMIC_MCU_Comm_Fault = 0U;

#ifdef __cplusplus
}
#endif
