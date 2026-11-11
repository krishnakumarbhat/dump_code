/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/



/*===========================================================================*/
/**
 * @Mcu Post-build Cfg source
 *
 * @file 	 Mcu_PBcfg.c
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
 * @Microcontroller MCAL MCU Post-build configuration source file
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Mcu.h"
#include "Mcu_UserCallouts.h" /* polyspace DEFECT:USELESS_INCLUDE [Justified:Low] " Used by the module " */
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
 
#define NUM_CLOCK_SETTINGS              27U
#define NUM_MEM_SECTIONS                2U

/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/


/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
 /*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

#define MCU_START_SEC_CONFIG_DATA_POSTBUILD
#include "Mcu_MemMap.h"

STATIC VAR(Mcu_ClockSettingConfigType, MCU_CODE) McuClockSettingConfig[NUM_CLOCK_SETTINGS] =
{
	{
		.McuClockReferencePointFrequency = 500u
	},
	{
		.McuClockReferencePointFrequency = 2500000000u
	},
	{
		.McuClockReferencePointFrequency = 40000000u
	},
	{
		.McuClockReferencePointFrequency = 40000000u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 833000000u
	},
	{
		.McuClockReferencePointFrequency = 500000000u
	},
	{
		.McuClockReferencePointFrequency = 500000000u
	},
	{
		.McuClockReferencePointFrequency = 250000000u
	},
	{
		.McuClockReferencePointFrequency = 250000000u
	},
	{
		.McuClockReferencePointFrequency = 100000000u
	},
	{
		.McuClockReferencePointFrequency = 100000000u
	},
	{
		.McuClockReferencePointFrequency = 500000000u
	},
	{
		.McuClockReferencePointFrequency = 500000000u
	},
	{
		.McuClockReferencePointFrequency = 40000000u
	},
	{
		.McuClockReferencePointFrequency = 40000000u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 625000000u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 625000000u
	},
	{
		.McuClockReferencePointFrequency = 625000000u
	},
	{
		.McuClockReferencePointFrequency = 0u
	},
	{
		.McuClockReferencePointFrequency = 625000000u
	},
	{
		.McuClockReferencePointFrequency = 625000000u
	},
	{
		.McuClockReferencePointFrequency = 50000000u
	},
}; /* Configuration of clock settings available for the MCU. */


STATIC VAR(Mcu_RamSectorSettingConfType, MCU_CODE) McuRamSectorSettingConf[NUM_MEM_SECTIONS] =
{
    [0x00u]=   		/* SYSMEM0 */
    {
    	.McuRamDefaultValue = 0x00u,
        .McuRamSectionBaseAddress = (uint32 *)0x80000000u,
        .McuRamSectionSize = 0x02000000u,
        .McuRamSectionWriteSize = 0x08u,
    },
    [0x01u]=   		/* SYSMEM1 */
    {
    	.McuRamDefaultValue = 0x00u,
        .McuRamSectionBaseAddress = (uint32 *)0x82000000u,
        .McuRamSectionSize = 0x02000000u,
        .McuRamSectionWriteSize = 0x08u,
    },

}; /* Configuration of RAM sections available for the MCU. */




CONST(Mcu_ConfigType, MCU_CODE) Mcu_Config =
{
        .McuNumberOfMcuModes = 0x01u,            /* Mcu has one power mode setting (ACTIVE)*/
        .McuRamSectors = 0x00000002u,                  /* Number of RAM sections*/
        .McuClockSrcFailureNotification = MCU_CLOCK_FAIL_DETECTION_DISABLED,	/* Clock failure notification enabled */
        .McuPreResetCallout = NULL_PTR,
        .McuRamSectorSettingConf = McuRamSectorSettingConf,
        .McuClockSettingConfig = McuClockSettingConfig,
};





#define MCU_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Mcu_MemMap.h"  /* polyspace MISRA-C-2023:20.1 "AUTOSAR Memory Mapping " */ /* polyspace DEFECT:USELESS_INCLUDE [Justified:Low] "AUTOSAR Memory Mapping" */
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*
 *  Local Function Definitions
 *===========================================================================*/

