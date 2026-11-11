/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Dio cfg header
 *
 * @file     Dio_Cfg.h
 * @Date     Generation Time:   2026-09-03 02:11:05
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *------------------------------------------------------------------------------
 * Copyright (c) indie Semiconductor 2025.
 *------------------------------------------------------------------------------
 * @desc  DIO MCAL configuration header (PB/SW-fixed)
 */
#ifndef DIO_CFG_H_
#define DIO_CFG_H_


/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================*
* Global Macro Definitions
*===========================================================================*/
/**
 * @def             DIO_CFG_MAJOR_VERSION
 * @brief           Dio Driver Configuration Major Version
 */
#define DIO_CFG_MAJOR_VERSION              (3U)
/**
 * @def             DIO_CFG_MINOR_VERSION
 * @brief           Dio Driver Configuration Minor Version
 */
#define DIO_CFG_MINOR_VERSION              (8U)

/*                          Container: DioGeneral                            */

/**
 * @def             DIO_ACCESSIBLE_APPS_NUM
 * @brief           Specifies the number of authorized OS applications
*/
#define DIO_ACCESSIBLE_APPS_NUM             (0U)

/**
 * @def             DIO_DEV_ERROR_DETECT
 * @requirements    ECUC_Dio_00142
 * @brief           Switches the development error detection and notification on or off.
 */
#define DIO_DEV_ERROR_DETECT               (STD_OFF)

/**
 * @def             DIO_VERSION_INFO_API
 * @requirements	ECUC_Dio_00143
 * @brief           Pre-Compiler switch to include the API Dio_GetVersionInfo()
*/
#define DIO_VERSION_INFO_API               (STD_OFF)

/**
 * @def             DIO_FLIP_CHANNEL_API
 * @requirements    ECUC_Dio_00153
 * @brief           Adds / removes the service Dio_FlipChannel() from the code
 */
#define DIO_FLIP_CHANNEL_API               (STD_ON)

/**
 * @def             DIO_MASKED_WRITE_PORT_API
 * @requirements    ECUC_Dio_00155
 * @brief           Adds / removes the service Dio_MaskedWritePort() from the code.
 */
#define DIO_MASKED_WRITE_PORT_API          (STD_OFF)

/**
 * @def             DIO_INSTANCE_ID
 * @brief           Specifies the Instance ID
*/
#define DIO_INSTANCE_ID                    ((uint8)0x00u)

/*                            END: DioGeneral                               */


/* =========================================================
 * User Defined Symbolic Names for the Dio Port
 * ========================================================= */
#define DioConf_DioPort_DioPort   (0x0000u)
#define DioConf_DioPort_DioPort_001   (0x0001u)
#define DioConf_DioPort_DioPort_002   (0x0002u)

/* =========================================================
 * Canonical symbolic channel IDs
 * ========================================================= */
/* -------- Port 0 -------- */
#define DIO_CHANNEL_0_0  ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_0_1  ((Dio_ChannelType)0x001)
#define DIO_CHANNEL_0_3  ((Dio_ChannelType)0x002)
/* -------- End of Port 0 -------- */

/* -------- Port 1 -------- */
#define DIO_CHANNEL_1_8  ((Dio_ChannelType)0x003)
#define DIO_CHANNEL_1_9  ((Dio_ChannelType)0x004)
#define DIO_CHANNEL_1_10  ((Dio_ChannelType)0x005)
#define DIO_CHANNEL_1_11  ((Dio_ChannelType)0x006)
#define DIO_CHANNEL_1_12  ((Dio_ChannelType)0x007)
/* -------- End of Port 1 -------- */

/* -------- Port 2 -------- */
#define DIO_CHANNEL_2_16  ((Dio_ChannelType)0x008)
#define DIO_CHANNEL_2_17  ((Dio_ChannelType)0x009)
/* -------- End of Port 2 -------- */


/* =========================================================
 * User Defined Symbolic Names for the Dio Channels
 * ========================================================= */
/* -------- Port 0 -------- */
#define DioConf_DioChannel_A2_A3_MARS_RESET_N  DIO_CHANNEL_0_0
#define DioConf_DioChannel_A2_A3_CANWK_EN  DIO_CHANNEL_0_1
#define DioConf_DioChannel_A2_A3_MM_FRAME_START  DIO_CHANNEL_0_3
/* -------- End of Port 0 -------- */

/* -------- Port 1 -------- */
#define DioConf_DioChannel_A3_DEBUG_DETECT  DIO_CHANNEL_1_8
#define DioConf_DioChannel_A3_TOD  DIO_CHANNEL_1_9
#define DioConf_DioChannel_A3_ERR_N  DIO_CHANNEL_1_10
#define DioConf_DioChannel_A3_FPGA_RST_N  DIO_CHANNEL_1_11
#define DioConf_DioChannel_A3_HSD_FAULT  DIO_CHANNEL_1_12
/* -------- End of Port 1 -------- */

/* -------- Port 2 -------- */
#define DioConf_DioChannel_A2_A3_ERRN_HSDEN  DIO_CHANNEL_2_16
#define DioConf_DioChannel_A2_A3_POS_GND_EN  DIO_CHANNEL_2_17
/* -------- End of Port 2 -------- */


/* =================== Aggregates =================== */
#define DIO_NUM_OF_PORTS                        (3u)
#define DIO_NUM_OF_CHANNELS                     (10u)
#define DIO_CHANNELS_PER_PORT                   (8u)
#define DIO_MAX_CHANNEL_ID                      ((Dio_ChannelType)0x009)

/* =========================================================
 * User Defined Symbolic Names for the DIO Channel Groups
 * ========================================================= */

/* Total number of configured DIO channel groups */
#define DIO_CHANNELGROUPCOUNT                   (3u)

/* ======= Symbolic links to each configured Channel Group ======= */
/* Port 0, ChannelGroup: 0 */
#define DioConf_DioChannelGroup_DioChannelGroup   (&Dio_Config.ChannelGroupConfigPtr[0])
/* Port 1, ChannelGroup: 0 */
#define DioConf_DioChannelGroup_DioChannelGroup_1   (&Dio_Config.ChannelGroupConfigPtr[1])
/* Port 2, ChannelGroup: 0 */
#define DioConf_DioChannelGroup_DioChannelGroup_2   (&Dio_Config.ChannelGroupConfigPtr[2])

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/

/* Dio Channel Group */
extern const Dio_ChannelGroupType Dio_ChannelGroupConfig[DIO_CHANNELGROUPCOUNT];

/* Maps compact generated DIO channel IDs to physical GPIO pin IDs */
extern const Dio_ChannelType Dio_ChannelPhysicalIdMap[DIO_NUM_OF_CHANNELS];

/* Dio Configuration */
extern const Dio_ConfigType Dio_Config;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DIO_CFG_H_ */

