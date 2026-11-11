/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @Uart Uart Configuration header file
 *
 * @file 	 Uart_Cfg.h
 * @Date     Generation Time:   2026-08-26 23:24:01
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 * @section DESCRIPTION:
 *
 * @ Mcal Configuration Uart header file 
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
 * @UART Abstraction Layer Configuration Uart header file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Design document name
 *
 *   - Requirements Document(s):
 *     - @Requirements document name
 *
 *   - Applicable Standards:
 *     - @Standards name here
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef UART_CFG_H_
#define UART_CFG_H_

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

/**< Uart Driver Configuration Version Info */
#define UART_CFG_MAJOR_VERSION        	(5U) /**< Uart  Configuration Major Version */
#define UART_CFG_MINOR_VERSION        	(2U) /**< Uart  Configuration Minor Version */

#define UART_INSTANCE_ID                ((uint8)(0x00u))

/**< Uart Configuration Number of channels  */   
#define UART_NUMBER_OF_CHANNELS         (1U)  

/** @brief OS Category 1 ISR selector. */
#define UART_OS_ISR_CATEGORY_1           (1U)

/** @brief OS Category 2 ISR selector. */
#define UART_OS_ISR_CATEGORY_2           (2U)

/** @brief Configured OS ISR category for the UART interrupt. */
#define UART_OS_ISR_CATEGORY             (UART_OS_ISR_CATEGORY_2)

/** @brief Configured OS ISR special function name for the UART interrupt. */
#define UART_OS_ISR_SPECIAL_FUNCTION_NAME UART_Handler

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/**< Build version info API */
#define UART_VERSION_INFO_API               (STD_ON)

/**< Enable Development Error Trace */
#define UART_DEV_ERROR_DETECT               (STD_ON)
 
/**< Uart GetStatus API */
#define UART_GET_STATUS_API               	(STD_ON)

/**< Uart DeInit API */
#define UART_DE_INIT_API               	    (STD_ON)

/**< Uart GetTxCount API */
#define UART_GET_TX_COUNT_API               (STD_ON)

/**< Uart GetRxCount API */
#define UART_GET_RX_COUNT_API               (STD_ON)

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


#endif /* UART_CFG_H_*/

