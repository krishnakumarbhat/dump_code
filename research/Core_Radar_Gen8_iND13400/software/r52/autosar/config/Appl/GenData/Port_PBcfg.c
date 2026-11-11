/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Port PBCfg source
 *
 * @file 	 Port_PBCfg.c
 * @Date     Generation Time:   2026-09-11 16:06:48
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
 * @Microcontroller Microcontroller Abstraction Layer Port Post Build configuration source file 
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Port.h"

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define PORT_START_SEC_CONFIG_DATA_POSTBUILD
#include "Port_MemMap.h"



/* ================= Single Variant Configuration ================= */
CONST(Port_ConfigType, PORT_PBCFG) Port_Config[] =
{
    /* ---- Port PortContainer ---- */
    {
        .PortPinId = (uint16)1u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)2u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)3u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_ETH,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)4u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)5u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)6u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_UART,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)7u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_I2C,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 15,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)8u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_I2C,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 15,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)9u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_DOWN,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)10u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)11u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)12u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)13u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)14u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_SPI,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)15u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 15,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = FALSE
    },
    {
        .PortPinId = (uint16)16u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_PWM,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 15,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = FALSE
    },
    {
        .PortPinId = (uint16)17u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)18u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_DIO,
        .PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)19u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 7,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)20u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 7,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)21u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)22u,
        .PortPinDirection = PORT_PIN_IN,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 7,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)23u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 7,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)24u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_CAN,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)25u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = TRUE,
        .PortPinInitialMode = PORT_PIN_MODE_ETH,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    },
    {
        .PortPinId = (uint16)26u,
        .PortPinDirection = PORT_PIN_OUT,
        .PortPinModeChangeable = FALSE,
        .PortPinDirectionChangeable = FALSE,
        .PortPinInitialMode = PORT_PIN_MODE_ETH,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinPullMode = PORT_PIN_PULL_NONE,
        .PortPinDriveStrength = 0,
        .PortPinSchmittTrigger = FALSE,
        .PortPinReadBack = TRUE
    }
};

#define PORT_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Port_MemMap.h"

