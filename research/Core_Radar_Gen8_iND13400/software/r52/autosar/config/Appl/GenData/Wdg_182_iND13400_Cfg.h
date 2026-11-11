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
 * @file     Wdg_182_iND13400_Cfg.h
 * Wdg configuration header
 * @date     Generation Time:   2026-08-26 19:22:36
 * @Project:   Gen8_iND13400 - Version 1.0
 *
 * @details
 * ### Full description
 * Pre-compile configuration parameters for the WDG module.
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
#ifndef WDG_182_iND13400_CFG_H_
#define WDG_182_iND13400_CFG_H_
#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/**< Wdg Driver Configuration Major Version */
#define WDG_182_iND13400_CFG_MAJOR_VERSION        (0x08U)

/**< Wdg Driver Configuration Minor Version */
#define WDG_182_iND13400_CFG_MINOR_VERSION        (0x03U)


/**
 * @def             WDG_DEV_ERROR_DETECT
 * @requirements    ECUC_Wdg_00114, ECUC_Wdg_00115
 * @brief           Switches the development error detection and notification on or off.
 *                      - TRUE: detection and notification is enabled.
 *                      - FALSE: detection and notification is disabled
 *                  Parent container: WdgGeneral.
 */
#define WDG_DEV_ERROR_DETECT                   (STD_ON)

/**
 * @def             WDG_DISABLE_ALLOWED
 * @requirements    ECUC_Wdg_00114, ECUC_Wdg_00116
 * @brief           Compile switch to allow / forbid disabling the watchdog driver during runtime.
 *                      - TRUE: Disabling the watchdog driver at runtime is allowed.
 *                      - FALSE: Disabling the watchdog driver at runtime is not allowed.
 *                  Parent container: WdgGeneral.
 */
#define WDG_DISABLE_ALLOWED                   (STD_ON)

/**
 * @def             WDG_MAX_TIMEOUT
 * @requirements    ECUC_Wdg_00114, ECUC_Wdg_00131
 * @brief           The maximum timeout (sec) to which the watchdog trigger condition can
 *                  be initialized.
 */
#define WDG_MAX_TIMEOUT                       (const uint32)65535

/**
 * @def             WDG_VERSION_INFO_API
 * @requirements    ECUC_Wdg_00114, ECUC_Wdg_00119
 * @brief           Enable Wdg version check service.
 */
#define WDG_VERSION_INFO_API                   (STD_OFF)

/**
 * @def             WDG_ENABLE_INIT_CHECK
 * @requirements    CHDA-SWARCH-9225
 * @brief           Enable Wdg initialization status check service.
 */
#define WDG_ENABLE_INIT_CHECK                  (STD_OFF)

/**
 * @def             WdgIndex
 * @requirements    ECUC_Wdg_00114, ECUC_Wdg_00117
 * @brief           Specifies the InstanceId of this module instance. If only one instance is
 *                  present it shall have the Id 0.
 */
#define WdgConf_WdgGeneral_WdgIndex          (0U)    

/**
 * @def   			Watchdog channel index usage
 * @brief 			Watchdog channel index.
 * @requirements 	ECUC_Wdg_00117
 */               
#define	WDG_CHANNEL_ZERO					 (0U)

/**
 * @def   WDG_CONFIGURED_CHANNEL
 * @brief Selected watchdog channel.
 * @requirements ECUC_Wdg_00117
 */
#define WDG_CONFIGURED_CHANNEL				WDG_CHANNEL_ZERO
/**
 * @def             WDG_ENABLE_TIMEOUT_MAPPING
 * @requirements    None 
 * @brief           Maps the requested timeout to the nearest HW TOP
 */    
#define WDG_ENABLE_TIMEOUT_MAPPING				(STD_OFF)

/** Watchdog interrupt handling is generated when a mode uses interrupt or mixed reaction. */
#define WDG_INTERRUPT_ENABLED                  (STD_ON)

/**
 * @def             WDG_OS_ISR_CATEGORY_1
 * @requirements    None
 * @brief           OS Category 1 ISR selector.
 */
#define WDG_OS_ISR_CATEGORY_1                  (1U)

/**
 * @def             WDG_OS_ISR_CATEGORY_2
 * @requirements    None
 * @brief           OS Category 2 ISR selector.
 */
#define WDG_OS_ISR_CATEGORY_2                  (2U)

/**
 * @def             WDG_OS_ISR_CATEGORY
 * @requirements    None
 * @brief           Configured OS ISR category for the Wdg interrupt.
 */
#define WDG_OS_ISR_CATEGORY                    (WDG_OS_ISR_CATEGORY_2)

/**
 * @def             WDG_OS_ISR_SPECIAL_FUNCTION_NAME
 * @requirements    None
 * @brief           OS ISR special function name configured for the Wdg interrupt.
 */
#define WDG_OS_ISR_SPECIAL_FUNCTION_NAME       WATCHDOG_FUSA_Handler

/**
 * @enum            Wdg_PreloadValueType
 * @requirements    None
 * @brief           Preload values (in miliseconds)
 */
#define WDG_PRELOADVALUE_52MS					(5U)
#define WDG_PRELOADVALUE_1678MS				(10U)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* WDG_182_iND13400_CFG_H_*/

/** @} */

