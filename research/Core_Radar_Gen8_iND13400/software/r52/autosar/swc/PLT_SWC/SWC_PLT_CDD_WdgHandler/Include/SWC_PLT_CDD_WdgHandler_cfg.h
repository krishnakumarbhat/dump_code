/**************************************************************************
 * Copyright 2025 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        Application WdgHandler \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:g1oq86  %derived_by: g10q86 % \n
 * \b Classification:     CONFIDENTIAL \n
 *
 *
 *
 ***************************************************************************
 *
 *  Module Name:  SWC_PLT_CDD_WdgHandler_cfg.h
 *
 *  Description:
 *    Header file for SWC_PLT_CDD_WdgHandler
 *
 *
 **************************************************************************/
/*=====================================================================================================================*
 * PREPROCESSOR DIRECTIVES
 *=====================================================================================================================*/
#include "Wdg_182_iND13400.h"

#ifndef SWC_PLT_CDD_WDGHANDLER_CFG_H
   #define SWC_PLT_CDD_WDGHANDLER_CFG_H

   #if (STD_ON == ENABLE_SIT_TEST_STUBS)
void Wdghandler_Integration_Test(void);
   #endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

   #define INT_WDG_FAIL_THRESHOLD_FOR_EXT_WDG (40U)
   #define MCU_FAILSAFE_WDG_RESET_REASON      (28U)
   #ifndef UNIT_TEST
      #define WDG_SETTRIGGER_CONDITION_FUNC Wdg_182_iND13400_SetTriggerCondition
      #define WDG_SETMODE_FUNC              Wdg_182_iND13400_SetMode
   #endif

   #if (TRUE == XCP_FAULT_INJECTION)
      #define FT_SWT_FAILURE          (0x00U)
      #define IC_INTERNAL_SWT_FAILURE (0x00U)
      #define IC_EXTERNAL_SWT_FAILURE (0x01U)
      #define IC_INT_EXT_SWT_FAILURE  (0x02U)
      #define IC_REMOVE_SWT_FAILURE   (0x03U)
   #endif
FUNC(void, WDG_CODE) Internal_Wdg_Instance_SetTriggerCondition(uint16 u16Timeout);
FUNC(Std_ReturnType, WDG_CODE) Internal_Wdg_Instance_SetMode(WdgIf_ModeType Mode);

#endif /* SWC_PLT_CDD_WDGHANDLER_CFG_H */
