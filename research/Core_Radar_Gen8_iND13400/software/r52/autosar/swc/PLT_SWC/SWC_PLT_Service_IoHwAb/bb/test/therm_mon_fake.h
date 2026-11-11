/*===========================================================================*/
/**
 * @file therm_mon_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock definitions for thermal monitor unit tests
 * Provides mocked hardware register access and external function dependencies
 *
 * @section ABBR ABBREVIATIONS:
 *   - TMU - Thermal Monitoring Unit
 *   - PVT - Process, Voltage, Temperature
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
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef THERM_MON_FAKE_H
#define THERM_MON_FAKE_H

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_Appl_IoHwAb_Type.h"
#include "fff.h"
#include "reuse.h"
#include <cstring>
#include <string.h>

/*===========================================================================*
 * Mock for FailSafe_Log_ResetReason - Define before including source
 * Wrap in extern "C" to match C linkage from SWC_PLT_CDD_FailSafe.h
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, uint16);
#ifdef __cplusplus
}
#endif

/*===========================================================================*
 * Include thermal_monitor.h FIRST to get original definitions.
 * The include guard will prevent it from being processed again when
 * thermal_monitor.c includes it.
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
#include "thermal_monitor.h"
#ifdef __cplusplus
}
#endif
/*===========================================================================*
 * Undefine the hardware register macros from thermal_monitor.h
 * so we can redefine them to use mock variables.
 *===========================================================================*/
/* PVT0 registers */
#undef PVT0_CTRL0_ADDR
#undef PVT0_CTRL1_ADDR
#undef PVT0_CTRL3_ADDR
#undef PVT0_CTRL4_ADDR
#undef PVT0_IRQ_CTRL_ADDR
#undef PVT0_STAT0_ADDR
#undef PVT0_STAT1_ADDR

/* PVT1 registers */
#undef PVT1_CTRL0_ADDR
#undef PVT1_CTRL1_ADDR
#undef PVT1_CTRL3_ADDR
#undef PVT1_CTRL4_ADDR
#undef PVT1_IRQ_CTRL_ADDR
#undef PVT1_STAT0_ADDR
#undef PVT1_STAT1_ADDR

/* SYS CTRL registers */
#undef OTP_PVT_TRIM_ADDR

/*===========================================================================*
 * Mock Hardware Registers - Global variables for test access
 *===========================================================================*/

/* PVT0 Mock Registers */
extern uint32_t mock_PVT0_CTRL0;
extern uint32_t mock_PVT0_CTRL1;
extern uint32_t mock_PVT0_CTRL3;
extern uint32_t mock_PVT0_CTRL4;
extern uint32_t mock_PVT0_IRQ_CTRL;
extern uint32_t mock_PVT0_STAT0;
extern uint32_t mock_PVT0_STAT1;

/* PVT1 Mock Registers */
extern uint32_t mock_PVT1_CTRL0;
extern uint32_t mock_PVT1_CTRL1;
extern uint32_t mock_PVT1_CTRL3;
extern uint32_t mock_PVT1_CTRL4;
extern uint32_t mock_PVT1_IRQ_CTRL;
extern uint32_t mock_PVT1_STAT0;
extern uint32_t mock_PVT1_STAT1;

/* SYS CTRL Mock Registers */
extern uint32_t mock_SYS_CTRL_PVT_TRIM;

/*===========================================================================*
 * Redefine hardware register macros to use mock variables
 *===========================================================================*/

/* PVT0 Register overrides */
#define PVT0_CTRL0_ADDR    mock_PVT0_CTRL0
#define PVT0_CTRL1_ADDR    mock_PVT0_CTRL1
#define PVT0_CTRL3_ADDR    mock_PVT0_CTRL3
#define PVT0_CTRL4_ADDR    mock_PVT0_CTRL4
#define PVT0_IRQ_CTRL_ADDR mock_PVT0_IRQ_CTRL
#define PVT0_STAT0_ADDR    mock_PVT0_STAT0
#define PVT0_STAT1_ADDR    mock_PVT0_STAT1

/* PVT1 Register overrides */
#define PVT1_CTRL0_ADDR    mock_PVT1_CTRL0
#define PVT1_CTRL1_ADDR    mock_PVT1_CTRL1
#define PVT1_CTRL3_ADDR    mock_PVT1_CTRL3
#define PVT1_CTRL4_ADDR    mock_PVT1_CTRL4
#define PVT1_IRQ_CTRL_ADDR mock_PVT1_IRQ_CTRL
#define PVT1_STAT0_ADDR    mock_PVT1_STAT0
#define PVT1_STAT1_ADDR    mock_PVT1_STAT1

/* SYS CTRL Register overrides */
#define OTP_PVT_TRIM_ADDR mock_SYS_CTRL_PVT_TRIM

/*===========================================================================*
 * Reset function for test setup
 *===========================================================================*/
void Reset_Mock_PVT_Registers(void);

#endif /* THERM_MON_FAKE_H */
