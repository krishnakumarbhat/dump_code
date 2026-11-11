/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @Port Cfg header file
 *
 * @file 	 Port_Cfg.h
 * @Date     Generation Time:   2026-09-11 16:06:48
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 * @section DESCRIPTION:
 *
 * @Port configuration header file
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
 * @PORT Abstraction Layer Post Build Configuration Port header file 
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of PORT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of PORT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/*Define constant value*/
#define PORT_CFG_MAJOR_VERSION              (4U)
#define PORT_CFG_MINOR_VERSION              (3U)


#define PORT_SET_PIN_MODE_API               (STD_OFF)
#define PORT_VERSION_INFO_API               (STD_OFF)
#define PORT_DEV_ERROR_DETECT               (STD_OFF)
#define PORT_SET_PIN_DIRECTION_API          (STD_OFF)

/** @brief OS Category 1 ISR selector. */
#define PORT_OS_ISR_CATEGORY_1              (1U)

/** @brief OS Category 2 ISR selector. */
#define PORT_OS_ISR_CATEGORY_2              (2U)

/** @brief Configured OS ISR category for the IOCTRL FUSA interrupt. */
#define PORT_OS_ISR_CATEGORY                (PORT_OS_ISR_CATEGORY_2)

/** @brief Configured OS ISR special function name for the IOCTRL FUSA interrupt. */
#define PORT_OS_ISR_SPECIAL_FUNCTION_NAME   IOCTRL_ERR_FUSA_Handler


/**
 * @def             PORT_ENABLE_INIT_CHECK
 * @brief           Enables or disables PORT driver initialization check.
 */
#define PORT_ENABLE_INIT_CHECK           	(STD_ON)

/**
 * @def PortNumberOfPortPins
 * @brief Total number of PORT pins available on the target device.
 *
 * This macro expands to the number of physical PORT pins generated
 */
#define PortNumberOfPortPins							   (26U)

#define PortConf_PortPin_MARS_RESET_N                      (0U)
#define PortConf_PortPin_CANWK_EN                          (1U)
#define PortConf_PortPin_ETH_IRQ                           (2U)
#define PortConf_PortPin_MM_FRAME_START                    (3U)
#define PortConf_PortPin_PIN_POSITION                      (4U)
#define PortConf_PortPin_UART_RX                           (5U)
#define PortConf_PortPin_I2CM_SCL                          (6U)
#define PortConf_PortPin_I2CM_SDA                          (7U)
#define PortConf_PortPin_GPIO8_DEBUG_DETECT                (8U)
#define PortConf_PortPin_GPIO9_TOD                         (9U)
#define PortConf_PortPin_GPIO10_ERR_N                      (10U)
#define PortConf_PortPin_GPIO11_FPGA_RST_N                 (11U)
#define PortConf_PortPin_GPIO12_HSD_FAULT                  (12U)
#define PortConf_PortPin_GP_QSPI_D3                        (13U)
#define PortConf_PortPin_ENET_PHYRSTB                      (14U)
#define PortConf_PortPin_PWM_1                             (15U)
#define PortConf_PortPin_GPIO16_ERR_N_HSD_EN               (16U)
#define PortConf_PortPin_POS_GND_EN                        (17U)
#define PortConf_PortPin_CAN0_RXD                          (18U)
#define PortConf_PortPin_CAN0_TXD                          (19U)
#define PortConf_PortPin_CAN0_STDBY                        (20U)
#define PortConf_PortPin_CAN1_RXD                          (21U)
#define PortConf_PortPin_CAN1_TXD                          (22U)
#define PortConf_PortPin_CAN1_STDBY                        (23U)
#define PortConf_PortPin_ETH_MDIO                          (24U)
#define PortConf_PortPin_ETH_MDC                           (25U)
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

#endif /* PORT_CFG_H_*/

