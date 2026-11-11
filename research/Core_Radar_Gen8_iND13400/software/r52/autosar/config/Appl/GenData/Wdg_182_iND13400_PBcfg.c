/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @addtogroup WDG_Module
 * @{
 *
 * @file     Wdg_182_iND13400_PBcfg.c
 * Wdg post-build configuration source
 * @date     Generation Time:   2026-08-26 19:22:36
 * @Project:   Gen8_iND13400 - Version 1.0
 *
 * @details
 * ### Full description
 * Post-build configuration parameters for the WDG module.
 *
 * ### Traceability info
 * + **Design documents:**
 *     + Specification of WDG Driver AUTOSAR CP Release 4.4.0
 *
 * + **Requirements document:**
 *     + Requirements of WDG Driver AUTOSAR CP Release 4.4.0
 *
 * + **Applicable standards:**
 *     + Autosar Classic Platform 4.4.0
 *
 * + **Deviations from standards:**
 *     + None
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2026. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary.
 *
 *------------------------------------------------------------------------------
 *
 * Maybe Changed By the User: NO
 */
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Wdg_182_iND13400.h"

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
extern void WdgTriggerLocation_WdgGeneral(void);	/* polyspace MISRA-C-2023:8.5 [Not a defect:Low] "it is declared only once here" */

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#define WDG_START_SEC_CONFIG_DATA_POSTBUILD
#include "Wdg_MemMap.h" /* polyspace MISRA-C-2023:20.1 DEFECT:USELESS_INCLUDE [Justified:Low] "Memmap header usage as per Autosar guideline." */ 

STATIC VAR(Wdg_GeneralType, AUTOMATIC)WdgGeneralContainer =
{
     .WdgTriggerLocation = &WdgTriggerLocation_WdgGeneral,
};

STATIC VAR(Wdg_SettingsConfigType, AUTOMATIC)WdgSettingsConfigContainer = 
{
     .WdgModeSettings = 
     {
          {
               .ReactionMode = WDG_REACTIONMODE_MIXED,
               .PreloadValue = WDG_PRELOADVALUE_1678MS,
          },
          {
               .ReactionMode = WDG_REACTIONMODE_MIXED,
               .PreloadValue = WDG_PRELOADVALUE_52MS,
          }
     },
     .WdgDefaultMode = WDGIF_SLOW_MODE
};

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
CONST(Wdg_182_iND13400_ConfigType, WDG_CONST) Wdg_182_iND13400_Config =
{
     .WdgGeneral = &WdgGeneralContainer,
     .WdgSettingsConfig = &WdgSettingsConfigContainer
};

#define WDG_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Wdg_MemMap.h" /* polyspace MISRA-C-2023:20.1 DEFECT:USELESS_INCLUDE [Justified:Low] "Memmap header usage as per Autosar guideline." */ 

/** @} */

