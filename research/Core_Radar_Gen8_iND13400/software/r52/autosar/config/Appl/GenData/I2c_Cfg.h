/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @file 	 I2c_Cfg.h
 * @Date     Generation Time:   2026-08-24 09:53:27
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
 * @I2C Provides Pre-compile configuration parameters for I2c module
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - 
 *
 *   - Requirements Document(s):
 *     -
 *
 *   - Applicable Standards:
 *     -
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef I2C_CFG_H_
#define I2C_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

#define I2C_CFG_MAJOR_VERSION 			(0x05u) /**< I2C Driver Configuration Major Version */
#define I2C_CFG_MINOR_VERSION 			(0x00u) /**< I2C Driver Configuration Minor Version */

/** I2C transfer handling modes */
#define I2C_INTERRUPT_MODE              (0x00U) /**< Interrupt-driven transfer mode */
#define I2C_POLLING_MODE                (0x01U) /**< Polling-driven transfer mode */

/** I2C device operating modes */
#define I2C_DEVICE_MASTER_MODE          (0x00U) /**< I2C operates in master mode */
#define I2C_DEVICE_SLAVE_MODE           (0x01U) /**< I2C operates in slave mode */

/**
 * @def             I2C_VERSION_INFO_API
 * @brief           Enables the version information API.
 */
#define I2C_VERSION_INFO_API               STD_OFF

/**
 * @def             I2C_DEV_ERROR_DETECT
 * @brief           Enable Development Error Trace
 */
#define I2C_DEV_ERROR_DETECT               STD_OFF

/**
 * @def             I2C_CONFIGURED_MODE
 * @brief           Indicates the configured I2C device mode (Master/Slave) selected by user configuration.
 */
#define I2C_CONFIGURED_MODE     		   I2C_DEVICE_MASTER_MODE

/**
 * @def             I2C_TRANSFER_MODE
 * @brief           Indicates the selected I2C transfer handling mode (Polling or Interrupt).
 */
#define I2C_TRANSFER_MODE				   I2C_INTERRUPT_MODE

/**
 * @def             I2C_OS_ISR_CATEGORY_1
 * @requirements    None
 * @brief           OS Category 1 ISR selector.
 */
#define I2C_OS_ISR_CATEGORY_1                  (1U)

/**
 * @def             I2C_OS_ISR_CATEGORY_2
 * @requirements    None
 * @brief           OS Category 2 ISR selector.
 */
#define I2C_OS_ISR_CATEGORY_2                  (2U)

/**
 * @def             I2C_OS_ISR_CATEGORY
 * @requirements    None
 * @brief           Configured OS ISR category for the I2c interrupt.
 */
#define I2C_OS_ISR_CATEGORY                    (I2C_OS_ISR_CATEGORY_2)

/**
 * @def             I2C_OS_ISR_SPECIAL_FUNCTION_NAME
 * @requirements    None
 * @brief           OS ISR special function name configured for the I2C interrupt.
 */
#define I2C_OS_ISR_SPECIAL_FUNCTION_NAME       I2CM_Handler
/**
 * @def             I2C_BUS_FAULT_DETECTION_ENABLE
 * @brief           Enables I2C bus fault detection and recovery handling.
 */
#define I2C_BUS_FAULT_DETECTION_ENABLE     	  STD_ON


/**
 * @def             I2C_BUS_FAULT_DETECTION_TIMEOUT
 * @brief           Timeout for detecting SDA or SCL being held low.
 */
#define I2C_BUS_FAULT_DETECTION_TIMEOUT             (uint32)(50U)

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


#endif /* I2C_CFG_H_*/

