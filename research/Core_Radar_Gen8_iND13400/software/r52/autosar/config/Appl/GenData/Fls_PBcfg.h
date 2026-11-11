/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Fls PBcfg header file
 *
 * @file 	 Fls_PBcfg.h
 * @Date     Generation Time:   2026-08-28 16:45:33
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
 * @FLS  PBCfg header file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of Flash Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of Flash Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/

#ifndef FLS_PBCFG_H_
#define FLS_PBCFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "MemIf.h"

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/
#define FLS_PBCFG_MAJOR_VERSION             (3U)
#define FLS_PBCFG_MINOR_VERSION             (5U)

/* Container FlsGeneral */
#define FLS_BASE_ADDRESS                    ((uint32)0x00000000U)	/**< This parameter defines the lower boundary for read / write / erase and compare jobs.*/
#define FLS_BLANK_CHECK_API                 (STD_ON)        		/**< Compile switch to enable/disable the Fls_BlankCheck function.*/
#define FLS_CANCEL_API                      (STD_ON)            	/**< Compile switch to enable and disable the Fls_Cancel function.*/
#define FLS_COMPARE_API                     (STD_ON)           		/**< Compile switch to enable and disable the Fls_Compare function.*/
#define FLS_ENABLE_INIT_CHECK           	(STD_ON) 				/**< Enables or disables FLS driver initialization check.*/
#define FLS_DEV_ERROR_DETECT                (STD_OFF)				/**< Switches the development error detection and notification on or off.*/
#define FLS_ERASE_VERIFICATION_ENABLED      (STD_ON) 				/**< Compile switch to enable erase verification.*/
#define FLS_GET_JOB_RESULT_API              (STD_ON)         		/**< Compile switch to enable and disable the Fls_GetJobResult function.*/
#define FLS_GET_STATUS_API                  (STD_ON)            	/**< Compile switch to enable and disable the Fls_GetStatus function.*/
#define FLS_SET_MODE_API                    (STD_ON)              	/**< Compile switch to enable and disable the Fls_SetMode function.*/
#define FLS_TIMEOUT_SUPERVISION_ENABLED     (STD_OFF) 				/**< Compile switch to enable timeout supervision.*/
#define FLS_TOTAL_SIZE                      ((uint32)0x400000U)		/**< The total amount of flash memory in bytes (see also SWS_Fls_00208 and SWS_Fls_00209).*/
#define FLS_FAST_CLK                        (STD_ON)                /**< Switches between normal and fast clock */
#define FLS_VERSION_INFO_API                (STD_ON)           		/**< Pre-processor switch to enable / disable the API to read out the modules version information.*/
#define FLS_WRITE_VERIFICATION_ENABLED      (STD_OFF)  			    /**< Compile switch to enable write verification.*/

#define FlsConf_FlsGeneral_FlsDriverIndex   ((uint8)0x00U)		    /**< Index of the driver, used by FEE.*/

/* Container FlsPublishInformation  */
#define FLS_ERASED_VALUE                    ((uint32)0xFFFFFFFFU)          /**< The contents of an erased flash memory cel   */
#define FLS_ERASE_TIME                      ((uint32)300U)             	    /**< Maximum time to erase one complete flash sector */

#define FLS_DISABLE_CHIP_ID_VERIFICATION 	(STD_ON) 				        /**< Chip ID verification status: STD_ON = enabled, STD_OFF = disabled */

#define FLS_EXPECTED_HW_ID           	    ("IS25WP032D")				   /**< Unique identifier of the hardware device */
#define FLS_SPECIFIED_ERASE_CYCLES          ((uint32)0x10000U)             /**< Number of erase cycles specified for the flash device                    */
#define FLS_WRITE_TIME                      ((uint32)2000U)                 /**< Maximum time to program one complete flash page (in microseconds)  */

/* Container FlsSector  */
#define FLS_NUMBER_OF_SECTORS_VALUE         ((uint16)1024U)                /**< Number of continuous sectors with identical values for FLS_SECTOR_SIZE and FLS_PAGE_SIZE.*/
#define FLS_PAGE_SIZE_VALUE                 ((Fls_LengthType)256U)           /**< A flash page is the smallest amount of flash memory that can be programmed in one pass. */
#define FLS_SECTOR_SIZE_VALUE               ((Fls_LengthType)4096U)        /**< A flash sector is the smallest amount of flash memory that can be erased in one pass. */
#define FLS_SECTOR_START_ADDRESS_VALUE      ((uint32)0x00000000U)		   /**< Sector start address*/

#define FLS_INSTANCE_ID                     ((uint8)(0x00u))

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

typedef VAR(uint32, TYPEDEF)   Fls_AddressType;
typedef VAR(uint32, TYPEDEF)   Fls_LengthType;              /**< @req SWS_Fls_00370 Shall be the same type as Fls_AddressType because of arithmetic operations */
typedef P2FUNC(void, FLS_APPL_CODE, Fls_NotifyType) (void);

/**
 * @struct Fls_SectorType
 * @requirements    ECUC_Fls_00202
 * @brief           Configuration description of a flashable sector.
 */
typedef struct 
{
    VAR(Fls_LengthType, TYPEDEF)		FlsPageSize;                /**< A flash page is the smallest amount of flash memory that can be programmed in one pass. */
    VAR(Fls_LengthType, TYPEDEF)		FlsSectorSize;              /**< A flash sector is the smallest amount of flash memory that can be erased in one pass. */
    VAR(Fls_AddressType, TYPEDEF)		FlsSectorStartaddress;      /**< Sector start address*/
    VAR(uint16, TYPEDEF)	            FlsNumberOfSectors;         /**< Number of continuous sectors with identical values for FlsSectorSize and FlsPageSize.*/
}Fls_SectorType;

/**
 * @struct Fls_ConfigType
 * @requirements    ECUC_Fls_00270
 * @brief           Container for runtime configuration parameters of the flash driver.
 */
typedef struct 
{  
    VAR(uint32, TYPEDEF)	            FlsAcErase;                 /**< Address offset in RAM to which the erase flash access code shall be loaded.*/
    VAR(uint32, TYPEDEF)	            FlsAcWrite;                 /**< Address offset in RAM to which the write flash access code shall be loaded.*/
    VAR(uint32, TYPEDEF)	            FlsMaxReadFastMode;         /**< The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in fast mode.*/
    VAR(uint32, TYPEDEF)	            FlsMaxReadNormalMode;       /**< The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in normal mode. */
    VAR(uint32, TYPEDEF)	            FlsMaxWriteFastMode;        /**< The maximum number of bytes to write in one cycle of the flash driver's job processing function in fast mode.*/
    VAR(uint32, TYPEDEF)	            FlsMaxWriteNormalMode;      /**< The maximum number of bytes to write in one cycle of the flash driver's job processing function in normal mode.*/
    VAR(uint32, TYPEDEF)	            FlsProtection;              /**< Erase/write protection settings. Only relevant if supported by hardware.*/
    VAR(uint32, TYPEDEF)	            FlsCallCycle;               /**< Cycle time of calls of the flash driver's main function (in seconds) */
    VAR(MemIf_ModeType, TYPEDEF)	    FlsDefaultMode;             /**< This parameter is the default FLS device mode after initialization. */
    VAR(Fls_NotifyType, TYPEDEF)	    FlsJobEndNotification;      /**< Mapped to the job end notification routine provided by some upper layer module */
    VAR(Fls_NotifyType, TYPEDEF)	    FlsJobErrorNotification;    /**< Mapped to the job error notification routine provided by some upper layer module  */
    P2CONST(Fls_SectorType,  TYPEDEF, FLS_APPL_CONST) FlsSector;    /**< Configuration description of a flashable sector */
    VAR(uint16, TYPEDEF)	            FlsDriverStrength;          /**< Flash Chip Driver Strength */
    VAR(uint8, TYPEDEF)	            	FlsReceiveSampleDelay;      /**< QSPI Flash Receive Sample Delay.*/
} Fls_ConfigType;

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/
extern const Fls_ConfigType Fls_Config;

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/
/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* FLS_PBCFG_H_*/
