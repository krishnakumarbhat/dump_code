#ifndef SWC_PLT_APPL_MODEMANAGER_CFG_H
#define SWC_PLT_APPL_MODEMANAGER_CFG_H
/*===========================================================================*\
 * FILE: SWC_PLT_Appl_ModeManager_Cfg.h
 *===========================================================================
 * Copyright (C) 2024 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   Header file for SWC_PLT_Appl_ModeManager.c
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
#include "Dio.h"
#include "retention_ram_data.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
/* Macros for testing */
#if ((TRUE == ENABLE_SQT_TEST_STUBS) || (TRUE == XCP_FAULT_INJECTION)) /* For XCP Fault Injection to check Cust Force Radiation*/
   #define K_FORCE_RADIATE_ENABLE   STD_ON
   #define CUSTFORCE_RADIATE_ENABLE STD_ON

#else
   #define K_FORCE_RADIATE_ENABLE   STD_OFF
   #define CUSTFORCE_RADIATE_ENABLE STD_OFF
#endif

#ifdef UNIT_TEST
   #define K_FORCE_RADIATE_ENABLE   STD_OFF
   #define CUSTFORCE_RADIATE_ENABLE STD_OFF
#endif

#define DIO_PIN_TOD_ENABLE STD_OFF

#define MODEMANAGER_VALUE_ZERO    (0x00U)
#define MODEMANAGER_VALUE_ONE     (0x01U)
#define MODEMANAGER_VALUE_TWO     (0x02U)
#define MODEMANAGER_VALUE_THREE   (0x03U)
#define MODEMANAGER_VALUE_FOUR    (0x04U)
#define MODEMANAGER_VALUE_FIVE    (0x05U)
#define MODEMANAGER_VALUE_SIX     (0x06U)
#define MODEMANAGER_VALUE_DEFAULT (0x07U)
#define MODEMANAGER_PRJ_RESET     (0x01U) /*To store reset reason in Retention_Ram_Data.fhti_test_data.failure_name */
#define MCU_INIT_INVALID_VALUE    (0xFF)
#define Boot_Shared_Data          Retention_Ram_Data

/* As Modemanager is Buildingblock component,Modifying Boot_Shared_Data to Retention_Ram_Data*/
/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/
extern volatile uint8 Mode_Manager_Fault_Injection;
extern volatile uint8 Mode_Manager_State_Transition;
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
void Modemanager_Integration_Test(void);
#endif

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Modemanager_Functionality_Test(void);
#endif

void Evaluate_FHTI_Time(void);
/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

#endif /* SWC_PLT_APPL_MODEMANAGER_CFG_H */
