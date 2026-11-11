#ifndef DD_MIPI_FFF_H
#define DD_MIPI_FFF_H
/*===========================================================================*/
/**
 * @file dd_mipi_fff.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for dd_mipi using FFF.
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
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "Std_Types.h"

/* Forward declarations to avoid pulling dd_mipi.h into non-MMIC unit tests,
   which conflicts with other MIPI test-pattern enums. */
typedef struct MIPI_Config_Tag MIPI_Config_T;
typedef struct MIPI_CSI2_Rx_Settings_Tag MIPI_CSI2_Rx_Settings_T;
/*===========================================================================*
 * Fake value functions - dd_mipi functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Disable);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Enable);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Disable);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_CSI2_Config, const volatile MIPI_CSI2_Rx_Settings_T *);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Write_Chirp, const volatile int16_t *, uint16_t, uint16_t, uint8_t);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Init, const volatile MIPI_Config_T *);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Disable);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Enable, uint8_t);
DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Test_Pattern_Config, uint8_t);
DECLARE_FAKE_VOID_FUNC(Initialize_Frame_Start_Output_Gpio);
DECLARE_FAKE_VOID_FUNC(Trigger_Frame_Start_To_Resi);

/* List of fakes used by this unit tester */
#define FFF_FAKES_DD_MIPI_LIST(FAKE)                                                                                              \
   FAKE(MIPI_Enable)                                                                                                              \
   FAKE(MIPI_Disable)                                                                                                             \
   FAKE(MIPI_Debugmode_Enable)                                                                                                    \
   FAKE(MIPI_Debugmode_Disable)                                                                                                   \
   FAKE(MIPI_CSI2_Config)                                                                                                         \
   FAKE(MIPI_Init)                                                                                                                \
   FAKE(MIPI_Debugmode_Write_Chirp)                                                                                               \
   FAKE(MIPI_Test_Pattern_Disable)                                                                                                \
   FAKE(MIPI_Test_Pattern_Enable)                                                                                                 \
   FAKE(MIPI_Test_Pattern_Config)                                                                                                 \
   FAKE(Initialize_Frame_Start_Output_Gpio)                                                                                       \
   FAKE(Trigger_Frame_Start_To_Resi)

#endif /* DD_MIPI_FFF_H */
