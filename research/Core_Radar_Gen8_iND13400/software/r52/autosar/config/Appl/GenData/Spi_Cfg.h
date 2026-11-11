/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


/** 
 * @Spi Cfg file
 *
 * @file 	 Spi_Cfg.h
 * @Date     Generation Time:   2026-08-26 22:51:47
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
 * @SPI Spi configuration header file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of SPI Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Specification of SPI Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 * @section Maybe Changed By the User: NO
 */
/*===========================================================================*/
#ifndef SPI_CFG_H_
#define SPI_CFG_H_

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

/**
 * @name SPI Handler/Driver Configuration Version Info 
 */

/** @{ */
/**
 * @def             SPI_CFG_MAJOR_VERSION
 * @brief           SPI Handler/Driver Configuration Major Version
 */
#define SPI_CFG_MAJOR_VERSION             (0x04U)
/**
 * @def             SPI_CFG_MINOR_VERSION
 * @brief           SPI Handler/Driver Configuration Minor Version
 */
#define SPI_CFG_MINOR_VERSION             (0x04U)
/** @} */


/**
 * @def             SPI_CANCEL_API
 * @satisfies       ECUC_Spi_00226
 * @brief           Switches the Spi_Cancel function ON or OFF.
 *                  Parent container: SpiGeneral.
 */
#define SPI_CANCEL_API 							(STD_OFF)

/**
 * @def             SPI_ENABLE_INIT_CHECK
 * @brief           Enables or disables SPI driver initialization check.
 */
#define SPI_ENABLE_INIT_CHECK           		(STD_ON)

/**
 * @def             SPI_CHANNEL_BUFFERS_ALLOWED
 * @satisfies       ECUC_Spi_00227
 * @brief           Selects the Channel Buffers allowed: IB = 0, EB = 1 y IB/EB = 2.
 *                  Parent container: SpiGeneral.
 */
#define SPI_CHANNEL_BUFFERS_ALLOWED             (SPI_IB_EB)

/**
 * @def             SPI_MAX_CHANNEL
 * @satisfies    	ECUC_Spi_00197
 * @brief           Number of Channels configured.
 *                  Parent container: SpiDriver.
 */
#define SPI_MAX_CHANNEL             (2)

/**
 * @def             SPI_MAX_JOB
 * @satisfies       ECUC_Spi_00198
 * @brief           Number of Jobs configured.
 *                  Parent container: SpiDriver.
 */
#define SPI_MAX_JOB             (1)

/**
 * @def             SPI_MAX_SEQUENCE
 * @satisfies       ECUC_Spi_00227
 * @brief           Number of Sequences configured.
 *                  Parent container: SpiDriver.
 */
#define SPI_MAX_SEQUENCE             (1)

/**
 * @def             SPI_DEV_ERROR_DETECT
 * @satisfies       ECUC_Spi_00228
 * @brief           Switches the development error detection and notification on or off.
 *                  Parent container: SpiGeneral.
 */
#define SPI_DEV_ERROR_DETECT 					(STD_ON)

/**
 * @def             SPI_HW_STATUS_API
 * @satisfies       ECUC_Spi_00229
 * @brief           Switches the Spi_GetHWUnitStatus function ON or OFF.
 *                  Parent container: SpiGeneral.
 */
#define SPI_HW_STATUS_API                       (STD_OFF)

/**
 * @def             SPI_INTERRUPTIBLE_SEQ_ALLOWED
 * @satisfies       ECUC_Spi_00230
 * @brief           Switches the Interruptible Sequences handling functionality ON or OFF.
 *                  Parent container: SpiGeneral.
 */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED           (STD_OFF)

/**
 * @def             SPI_LEVEL_DELIVERED
 * @satisfies       ECUC_Spi_00231
 * @brief           Selects the level of scalable functionality that is available and delivered.
 *                  Parent container: SpiGeneral.
 */
#define SPI_LEVEL_DELIVERED                     (LEVEL1)

/**
 * @def             SPI_VERSION_INFO_API
 * @satisfies       ECUC_Spi_00232
 * @brief           Switches the Spi_GetVersionInfo function ON or OFF.
 *                  Parent container: SpiGeneral.
 */
#define SPI_VERSION_INFO_API                    (STD_ON)


/**
 * @satisfies    None
 * @brief           OS Category 1 ISR selector.
 */
#define SPI_OS_ISR_CATEGORY_1                  (1U)

/**
 * @satisfies    None
 * @brief           OS Category 2 ISR selector.
 */
#define SPI_OS_ISR_CATEGORY_2                  (2U)

/**
 * @satisfies    None
 * @brief           Configured OS ISR category for the SPI interrupts.
 */
#define SPI_OS_ISR_CATEGORY                    (SPI_OS_ISR_CATEGORY_2)

/**
 * @satisfies    None
 * @brief           OS ISR special function name configured for the MMIC SPI interrupts.
 */
#define SPI_MMIC_OS_ISR_SPECIAL_FUNCTION_NAME       QSPI_MMIC_Handler

/**
 * @satisfies    None
 * @brief           OS ISR special function name configured for the GP SPI interrupts.
 */
#define SPI_GP_OS_ISR_SPECIAL_FUNCTION_NAME       SPIM_SSI_Handler


/* polyspace-begin MISRA-C-2023:2.5 [Not a defect:Low] "Macros are unused by the upper layer " */

/**
 * @satisfies       ECUC_Spi_00242
 * @brief           Defines the cycle time of the function Spi_MainFunction_Handling in seconds (used by upper layer).
 *                  Parent container: SpiGeneral.
 */
#define SPI_MAIN_FUNCTION_PERIOD                (0.01)

/**
 * @satisfies       ECUC_Spi_00237
 * @brief           Specifies whether concurrent Spi_SyncTransmit() calls for different sequences shall be configurable.
 *                  Parent container: SpiGeneral.
 */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT    (STD_OFF)

#define SpiConf_SpiChannel_SpiChannel_2		1U
#define SpiConf_SpiChannel_SpiChannel_1		0U

#define SpiConf_SpiJob_SpiJob_MMIC					0U

#define SpiConf_SpiSequence_SpiSequence_MMIC	0U

/* polyspace-end MISRA-C-2023:2.5 [Not a defect:Low] "Macros are unused by the upper layer " */


#define SPI_ACCESSIBLE_APPS_NUM             (0U) /** Specifies the number of authorized OS applications */

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


#endif /* SPI_CFG_H_*/ 
