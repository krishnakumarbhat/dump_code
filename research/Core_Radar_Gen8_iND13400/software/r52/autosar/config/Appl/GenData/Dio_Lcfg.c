/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Dio PBcfg source
 *
 * @file 	 Dio_Lcfg.c
 * @Date     Generation Time:   2026-09-03 02:11:05
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
 * @DIO Mcal Dio PBcfg source file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of DIO Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of DIO Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Dio.h"
#include "Dio_Cfg.h"

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define DIO_START_SEC_CONFIG_DATA_POSTBUILD
#include "Dio_MemMap.h"



const Dio_ChannelType Dio_ChannelPhysicalIdMap[DIO_NUM_OF_CHANNELS] =
{
    (0x00U), /* DIO_CHANNEL_0_0 */
    (0x01U), /* DIO_CHANNEL_0_1 */
    (0x03U), /* DIO_CHANNEL_0_3 */
    (0x08U), /* DIO_CHANNEL_1_8 */
    (0x09U), /* DIO_CHANNEL_1_9 */
    (0x0aU), /* DIO_CHANNEL_1_10 */
    (0x0bU), /* DIO_CHANNEL_1_11 */
    (0x0cU), /* DIO_CHANNEL_1_12 */
    (0x10U), /* DIO_CHANNEL_2_16 */
    (0x11U) /* DIO_CHANNEL_2_17 */
};

const Dio_ChannelGroupType Dio_ChannelGroupConfig[DIO_CHANNELGROUPCOUNT] =
{
  {/* DioPort_0, DioChannelGroupId_0 */
    .port = (Dio_PortType)0,          /* Port Id */
    .mask = (Dio_PortLevelType)0xFF,    /* Mask    */
    .offset = (uint8)0                /* Offset  */
  },
  {/* DioPort_1, DioChannelGroupId_0 */
    .port = (Dio_PortType)1,          /* Port Id */
    .mask = (Dio_PortLevelType)0xFF,    /* Mask    */
    .offset = (uint8)0                /* Offset  */
  },
  {/* DioPort_2, DioChannelGroupId_0 */
    .port = (Dio_PortType)2,          /* Port Id */
    .mask = (Dio_PortLevelType)0xFF,    /* Mask    */
    .offset = (uint8)0                /* Offset  */
  }
};

const Dio_ConfigType Dio_Config =
{
    .NumberOfPorts = DIO_NUM_OF_PORTS,
    .NumberOfGroup = DIO_CHANNELGROUPCOUNT,
    .ChannelGroupConfigPtr = &Dio_ChannelGroupConfig[0],
};


#define DIO_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Dio_MemMap.h" /* polyspace MISRA-C-2023:20.1 [Justified:Low] "Memmap header usage as per Autosar guideline." */ /* polyspace DEFECT:USELESS_INCLUDE [Justified:Low] "Memmap header usage as per Autosar guideline." */

/*===========================================================================*
 * Local Object Definitions
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

