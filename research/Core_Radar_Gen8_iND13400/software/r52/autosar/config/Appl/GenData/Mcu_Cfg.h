/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/*===========================================================================*/
/**
 * @Mcu Pre-compile configuration parameters for MCU
 *
 * @file 	 Mcu_Cfg.h
 * @Date     Generation Time:   2026-08-26 23:24:01
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2025. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary. 
 * 
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @MCU Pre-compile configuration parameters for MCU
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of MCU Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of MCU Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef MCU_CFG_H_
#define MCU_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{      /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
/** Mcu Driver Configuration Version Info */
#define MCU_CFG_MAJOR_VERSION (0x06u) /**< Mcu Driver Configuration Major Version */
#define MCU_CFG_MINOR_VERSION (0x01u) /**< Mcu Driver Configuration Minor Version */

/*****************************************************************************************
 * McuGeneralConfiguration Container
 * Description: This container contains the configuration (parameters) of the MCU driver.
 * @satisfies: ECUC_Mcu_00118
 *****************************************************************************************/
/**
 * @brief Enable/Disable the Development Error Detection and Notification
 * @satisfies ECUC_Mcu_00166
 */
#define MCU_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Enable/disable Mcu_GetRamState() API
 * @satisfies ECUC_Mcu_00181
 */
#define MCU_GET_RAM_STATE_API (STD_OFF)

/**
 * @brief If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver.
 * This concept applies when there are some write once clock registers and a bootloader is present.
 * If this parameter is set to TRUE, the MCU driver is responsible of the clock initialization.
 * @satisfies ECUC_Mcu_00182
 */
#define MCU_INIT_CLOCK (STD_ON)

/**
 * @brief MCU_NO_PLL shall be set True if the H/W does not have a PLL, or the PLL circuitry is enabled after the power on without sw intervention.
 * In this case MCU_DistributePllClock has to be disabled and MCU_GetPllStatus has to return MCU_PLL_STATUS_UNDEFINED.
 * Otherwise this parameters has to be set FALSE
 * @satisfies ECUC_Mcu_00180
 */
#define MCU_NO_PLL (STD_OFF)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Mcu_PerformReset()
 * @satisfies ECUC_Mcu_00167
 */
#define MCU_PERFORM_RESET_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the API to read out the modules version information.
 * @satisfies ECUC_Mcu_00168
 */
#define MCU_VERSION_INFO_API (STD_ON) 

/**
 * @brief Pre-processor to enable/disable the FCRU sticky register information API.
 */
#define MCU_GET_FCRU_STICKY_REG_API		(STD_OFF)

/**
 * @brief Pre-processor to enable / disable the pre reset callout .
 */
#define MCU_PRE_RESET_CALLOUT   (STD_OFF)    
/**
 * @brief The parameter represents the different type of reset that a Micro supports. This parameter 
 * is referenced by the parameter EcuMResetReason in the ECU State manager module.
 *
 */
#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET  ((uint8)0x00u)

#define McuConf_McuResetReasonConf_MCU_SW_RESET  ((uint8)0x01u)

#define McuConf_McuResetReasonConf_MCU_FCRU_RESET  ((uint8)0x02u)

#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED  ((uint8)0x04u)

#define McuConf_McuResetReasonConf_MCU_RSTN_RESET  ((uint8)0x03u)

	
/**
 * @brief  Create defines with the IDs assigned to Mcu RAM Section configurations.
 * These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
 */
 
 #define McuConf_McuRamSectorSettingConf_SYSMEM0		((Mcu_RamSectionType)0x00u)
 
 #define McuConf_McuRamSectorSettingConf_SYSMEM1		((Mcu_RamSectionType)0x01u)
 
/*****************************************************************************************
 * Parent Container: McuClockSettingConfig
 * Description: This container contains the configuration (parameters) for the Clock settings of the MCU.
 * @satisfies: ECUC_Mcu_00124
 * **************************************************************************************/
#define McuConf_McuClockSettingConfig_McuClockSettingConfig ((Mcu_ClockType)(0x00u)) /**< Requirement ECUC_Mcu_00183: This Id will be used as argument for the API Mcu_InitClock*/
#define MCU_NBR_CLOCKS ((Mcu_ClockType)(0x01u)) /**< Number of clock configurations available for the micro - Used to ensure that the function is executed within the allowed parameters.*/

#define USED_PLL McuConf_McuClockSettingConfig_McuClockSettingConfig /**< Parameter used in the functions Mcu_DistributePllClock() and Mcu_GetPllStatus()*/
/*****************************************************************************************
 * Parent Container: McuModeSettingConf
 * Description: Contains the configuration (parameters) for the Mode setting of the MCU
 * @satisfies: ECUC_Mcu_00123
 * **************************************************************************************/
 /**
 * @brief The parameter represents the MCU Mode in normal operation
 * @satisfies ECUC_Mcu_00176
 */
#define McuConf_McuModeSettingConf_McuModeSettingConf ((Mcu_ModeType)(0x00u))
/**
 * @brief The parameter represents the configured reset setting
 * @satisfies ECUC_Mcu_00173
 */
#define MCU_RESET_SETTING 		MCU_RESET_ALL

/**
 * @satisfies    None
 * @brief        OS Category 1 ISR selector.
 */
#define MCU_OS_ISR_CATEGORY_1                        (1U)

/**
 * @satisfies    None
 * @brief        OS Category 2 ISR selector.
 */
#define MCU_OS_ISR_CATEGORY_2                        (2U)

/**
 * @satisfies    None
 * @brief        Configured OS ISR category for the MCU Clock Monitor interrupts.
 */
#define MCU_OS_ISR_CATEGORY                          (MCU_OS_ISR_CATEGORY_2)

/**
 * @satisfies    None
 * @brief        OS ISR special function name configured for the DSP Clock Monitor interrupt.
 */
#define MCU_DSP_CLKMON_OS_ISR_SPECIAL_FUNCTION_NAME      CRG_CLKMON_DSP_Handler

/**
 * @satisfies    None
 * @brief        OS ISR special function name configured for the RA Clock Monitor interrupt.
 */
#define MCU_RA_CLKMON_OS_ISR_SPECIAL_FUNCTION_NAME       CRG_CLKMON_RA_Handler

/**
 * @satisfies    None
 * @brief        OS ISR special function name configured for the MIPI Clock Monitor interrupt.
 */
#define MCU_MIPI_CLKMON_OS_ISR_SPECIAL_FUNCTION_NAME     CRG_CLKMON_MIPI_Handler

/**
 * @satisfies    None
 * @brief        OS ISR special function name configured for the SERIAL Clock Monitor interrupt.
 */
#define MCU_SERIAL_CLKMON_OS_ISR_SPECIAL_FUNCTION_NAME   CRG_CLKMON_SERIAL_Handler


#define MCU_ACCESSIBLE_APPS_NUM             (0U) /** Specifies the number of authorized OS applications */

/*===========================================================================*
 * Exported Preprocessor functions MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/
/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MCU_CFG_H_*/



