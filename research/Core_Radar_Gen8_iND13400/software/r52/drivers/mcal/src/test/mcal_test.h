/*===========================================================================*\
 * FILE: mcal_test.h
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  mcal_init.c
 * %version:  1 %
 * %derived_by:  xjvkxp %
 * %date_modified:  Tue Jun  13 15:55:28 2023 %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains code for the mcal_init funciton
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *   Requirements Document(s):
 *   (Design & Requirements)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None
 *
\*===========================================================================*/

#ifndef MCAL_TEST_H
#define MCAL_TEST_H

#include <stdbool.h>

/* Test result status */
typedef enum
{
   MCAL_STATUS_FAIL    = 0, /* Test executed and failed */
   MCAL_STATUS_PASS    = 1, /* Test executed and passed */
   MCAL_STATUS_NOT_RUN = 2  /* Test not yet executed    */
} Mcal_TestStatus_t;

/* Per-test configuration and result */
typedef struct
{
   bool enable;              /* TRUE = run this test, FALSE = skip */
   Mcal_TestStatus_t status; /* Result (valid only when enable == TRUE) */
} Mcal_TestConfig_t;

/* Top-level test configuration - one member per MCAL module */
typedef struct
{
   Mcal_TestConfig_t Mcu;
   Mcal_TestConfig_t Dio;
   Mcal_TestConfig_t Adc;
   Mcal_TestConfig_t I2c;
   Mcal_TestConfig_t Fls;
   Mcal_TestConfig_t Dma;
   Mcal_TestConfig_t Gpt;
   Mcal_TestConfig_t Pwm;
   Mcal_TestConfig_t Uart;
} Mcal_TestSuite_t;

/* Global test configuration */
extern Mcal_TestSuite_t Mcal_Test_Config;

void Mcal_Test(void);

#endif /* MCAL_TEST_H */
