#ifndef MCAL_INIT_H
#define MCAL_INIT_H
/*===========================================================================*\
 * FILE: mcal_init.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the APIs and types for mcal_init
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Adc.h"
#include "Dio.h"
#include "Dma.h"
#include "Dma_PBcfg.h"
#include "Eth.h"
#include "Eth_PBcfg.h"
#include "Fls.h"
#include "I2c.h"
#include "I2c_PBcfg.h"
#include "Mcu.h"
#include "Port.h"
#include "Port_PBcfg.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "Pwm_PBcfg.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "Spi.h"
#include "Uart.h"
#include "board_revision.h"
#include "mipi_wrapper.h"
// #include "dd_gpt.h"
#include "dd_pmic.h"
#include "mcal_test.h"
#include "power_supply_clock.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void MCAL_Init(void);

void Eth_RunOnce(void);
// void Eth_Periodic(void);
void Eth_Example_InitExampleUDPPckg(void);
// void Eth_Log(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
#if (UART_TEST_ENABLE == TEST_ENABLED)
void Usart_Periodic(void); /*Uart Rx test code*/
#endif
void Calib_Init_Function(void);
void CAN_Trcv_Init(void);

/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

#endif /* MCAL_INIT_H */
