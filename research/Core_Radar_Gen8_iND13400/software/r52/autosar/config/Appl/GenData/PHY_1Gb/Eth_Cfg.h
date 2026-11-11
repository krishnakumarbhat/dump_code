/*===========================================================================*//**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


/** 
 * @file Eth_Cfg.h
 * Mcal Eth Cfg source file
 *
 * @date    Date created:   09-01-2026
  * 
 * @details 
 * ### Full description
 * Ethernet post-build configuration header file
 * 
 * ### Traceability info
 * + **Design documents:**
 *     + Specification of Ethernet Driver AUTOSAR CP Release 4.4.0
 * 
 * + **Requirements document:**
 *     + Requirements on Ethernet Support in AUTOSAR CP Release 4.4.0
 *
 * 
 * + **Applicable standards:**
 *     + Autosar 4.4.0
 * 
 * + **Deviations from standards:**
 *     + None
 * 
 * @copyright (c) indie Semiconductor 2023-2024. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary. 
 *
 *  ---- AUTOGENERATED FILE - DO NOT EDIT! ---- 
 *
 */
/*===========================================================================*/
#ifndef ETH_CFG_H_
#define ETH_CFG_H_


/*===========================================================================*
 * Header Files
 *===========================================================================*/


/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
/**< ETH Configuration Version*/
#define ETH_PBCFG_MAJOR_VERSION              (6U)      
#define ETH_PBCFG_MINOR_VERSION              (7U)

#define CATEGORY_1           (1u)
#define CATEGORY_2           (2u)

#define NO_TRAFFIC_SHAPING          (0)
#define STATIC_TRAFFIC_SHAPING      (1)
#define DYNAMIC_TRAFFIC_SHAPING     (2)



#define ETH_TX_BUF_ALIGNMENT    	    64  /* 64 bytes */
#define ETH_RX_BUF_ALIGNMENT            64  /* 64 bytes */
#define ETH_MAX_SUPPORTED               1U  /* Number of supported controllers */
 
 /*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
 typedef enum {
    ETH_QUEUE0 = 0,
    ETH_QUEUE1 = 1,
    ETH_QUEUE2 = 2,
    ETH_NUM_QUEUE = 3
}   ETH_QUEUE_IDX;


/**
 * @brief Queue Size options for MTL ModeOperation register.
 * 
 * These values represent the transmit/receive queue size (in bytes) that
 * can be programmed into the MTL hardware. Each option corresponds
 * to a specific size supported by the MAC hardware.
 */
typedef enum {
  MTL_Q_Size_256  = 0,
  MTL_Q_Size_512  = 1,
  MTL_Q_Size_768  = 2,
  MTL_Q_Size_1024 = 3,
  MTL_Q_Size_1280 = 4,
  MTL_Q_Size_1536 = 5,
  MTL_Q_Size_1792 = 6,
  MTL_Q_Size_2048 = 7,
  MTL_Q_Size_2304 = 8,
  MTL_Q_Size_2560 = 9,
  MTL_Q_Size_2816 = 10,
  MTL_Q_Size_3072 = 11,
  MTL_Q_Size_3328 = 12,
  MTL_Q_Size_3584 = 13,
  MTL_Q_Size_3840 = 14,
  MTL_Q_Size_4096 = 15
} MTL_QueueSize;

#define CATEGORY_1           (1u)
#define CATEGORY_2           (2u)
#define NO_TRAFFIC_SHAPING          (0)
#define STATIC_TRAFFIC_SHAPING      (1)
#define DYNAMIC_TRAFFIC_SHAPING     (2)
#define ETH_TX_BUF_ALIGNMENT            64  /* 64 bytes */
#define ETH_RX_BUF_ALIGNMENT            64  /* 64 bytes */
#define ETH_MAX_SUPPORTED               1U  /* Number of supported controllers */

 /**
 * @def             EthGeneral
 * @requirements    ECUC_Eth_00001
 * @brief           General configuration of Ethernet Driver module
 */
#define ETH_DEV_ERROR_DETECT                    (STD_OFF)
#define ETH_CFG_GETTXERRORCOUNTERVALUESAPI      (STD_OFF)
#define ETH_CFG_GETTXSTATSAPI                   (STD_OFF)
#define ETH_CFG_GETRXSTATSAPI                   (STD_OFF)
#define ETH_CFG_GETCOUNTERVALUESAPI				(STD_OFF)
#define ETH_CFG_GLOBALTIMESUPPORT               (STD_ON)
#define ETH_CFG_INDEX                           (0u)
#define ETH_CFG_MAINFUNCTIONPERIOD              (0.01)
#define ETH_CFG_VERSIONINFOAPI                  (STD_ON)
#define ETH_CFG_MAXCTRLSSUPPORTED               (1)
#define ETH_CFG_ENABLERXINTERRUPT               (STD_ON)
#define ETH_CFG_ENABLETXINTERRUPT               (STD_ON)
#define ETH_CFG_ENABLEEXPLICITBUFFERMAPPING     (STD_OFF)
#define ETH_CFG_ENABLEMACSECAPI                 (STD_OFF)
#define ETH_CFG_MAX_FILTER_PHY_ADDR             (31)            /* Fixed by hw capabilities, iND specific */ 
#define ETH_CFG_ENABLEM_MAC_AN                  (STD_ON)
#define MAX_PRIORITY_COUNT                       (8)
#define ETH_CHECKSUM_OFFLOAD_SW_COMPENSATION_TCP_Q2     (STD_OFF)
#define ETH_CHECKSUM_OFFLOAD_SW_COMPENSATION_UDP_Q2     (STD_OFF)
#define ETH_CHECKSUM_OFFLOAD_SW_COMPENSATION_IPV4_Q2    (STD_OFF)
#define ETH_CHECKSUM_OFFLOAD_SW_COMPENSATION     		(STD_OFF)
#define ETH_CFG_ENABLEECCINJECTIONTEST                  (STD_OFF)
#define ETH_CFG_ENABLEECC                               (STD_ON)
#define ETH_ACCESSIBLE_APPS_NUM                         (0)

#define MTL_TXQ0_SIZE_FIELD_VAL      MTL_Q_Size_1536
#define MTL_TXQ1_SIZE_FIELD_VAL      MTL_Q_Size_1536
#define MTL_TXQ2_SIZE_FIELD_VAL      MTL_Q_Size_1024

#define MTL_RXQ0_SIZE_FIELD_VAL     MTL_Q_Size_3840
#define MTL_RXQ1_SIZE_FIELD_VAL     MTL_Q_Size_256

/**
 * @def             Supplier specific
 * @brief           General specific supplier configuration of Ethernet Driver module
 */
	

#if ETH_CONFIG_VARIANT == VARIANT_POST_BUILD    /* Only post-build variant can have multiple configurations */
#define ETH_NUM_OF_CONFIGURATIONS   1U        	/* Number of configurations */
#else
#define ETH_NUM_OF_CONFIGURATIONS   1U 			/* Number of configurations */
#endif

#define ETH_DRIVER_INSTANCE             1U   	/* Instance number assigned to the driver */

/**
 *@def              ETH_HARDWARE_A0_VARIANT
 *@requirements     
 *@brief            Specifies the supported hardware varaint for the generated configurations.
 *                  Parent container: EthGeneral. 
 */
#define ETH_HARDWARE_A0_VARIANT 			(0xA0U)

/**
 *@def              ETH_HARDWARE_B0_VARIANT
 *@requirements     
 *@brief            Specifies the supported hardware varaint for the generated configurations.
 *                  Parent container: EthGeneral. 
 */
#define ETH_HARDWARE_B0_VARIANT 			(0xB0U)

/**
 *@def              ETH_HARDWARE_VARIANT
 *@requirements     
 *@brief            Specifies the supported hardware varaint for the generated configurations.
 *                  Parent container: EthGeneral. 
 */
 #define ETH_HARDWARE_VARIANT 					   (ETH_HARDWARE_B0_VARIANT)

/**
 * @def             EthCtrlConfig container
 * @requirements    ECUC_Eth_00006
 * @brief           The Ethernet Driver module shall support pre-compile time, link time and post-build time configuration
 *                  Parent container: NA
 */

#define ETH_CFG_ETHCTRLENABLEMII                    (STD_ON)
#define ETH_CFG_CTRLIDX                             (0)
#define ETH_CFG_MACLAYERSUBTYPE                     (SERIAL)
#define ETH_CFG_MACLAYERTYPE                        (ETH_MAC_LAYER_TYPE_XGMII)
#define ETH_CFG_CTRLTXBUFSIZE                       (7688)
#define ETH_CFG_CTRLRXBUFSIZE                       (13776)
#define ETH_CFG_CTRLMIIHWLOOPMAXCYCLES              (1000000U)
#define ETH_CFG_CTRLMACSWRESETTIMEOUT               (0x000F4240u)
#define ETH_CFG_CTRLMACSERDESLOCKTIMEOUT            (0x000F4240u)
#define ETH_CFG_CTRLENABLELOOPBACKMODE              (STD_OFF)
#define ETH_CFG_CTRLMIIINTERFACE                    (ETH_SGMII_MODE)
#define ETH_CFG_CTRLINTERPACKETGAP					(31U)
#define ETH_CFG_TXRX_BUFFER_SIZE					(ETH_CFG_CTRLTXBUFSIZE + ETH_CFG_CTRLRXBUFSIZE)



#define ETH_CFG_TXQ0_BUFLEN                     (1522)
#define ETH_CFG_TXQ0_BUFTOTAL                   (4)
#define ETH_CFG_TXQ0_IDX                        (0)
#define ETH_CFG_TXQ1_BUFLEN                     (200)
#define ETH_CFG_TXQ1_BUFTOTAL                   (4)
#define ETH_CFG_TXQ1_IDX                        (1)
#define ETH_CFG_TXQ2_BUFLEN                     (200)
#define ETH_CFG_TXQ2_BUFTOTAL                   (4)
#define ETH_CFG_TXQ2_IDX                        (2)


#define ETH_CFG_RXQ0_BUFLEN         	 		(1522)
#define ETH_CFG_RXQ0_BUFTOTAL           		(8)
/* TODO: Move to be PB */
#define ETH_CFG_RXQ0_FRAME_PROCESS_LIMIT		(5U)
#define ETH_CFG_RXQ0_IDX           	 		    (0)
#define ETH_CFG_RXQ1_BUFLEN         	 		(200)
#define ETH_CFG_RXQ1_BUFTOTAL           		(8)
/* TODO: Move to be PB */
#define ETH_CFG_RXQ1_FRAME_PROCESS_LIMIT		(5U)
#define ETH_CFG_RXQ1_IDX           	 		    (1)

 /**
 * @def             EthCtrlOffloading container
 * @requirements    ECUC_Eth_00030
 * @brief           The Ethernet Driver module shall support pre-compile time, link time and post-build time configuration
 *                  Parent container: NA
 */
#define ETH_CFG_ENABLE_OFFLOAD_CHECKSUM_ICMP       STD_ON
#define ETH_CFG_ENABLE_OFFLOAD_CHECKSUM_IPV4       STD_ON
#define ETH_CFG_ENABLE_OFFLOAD_CHECKSUM_TCP        STD_ON
#define ETH_CFG_ENABLE_OFFLOAD_CHECKSUM_UDP        STD_ON

#define ETH_CFG_ETHCTRLCONFIGPREDECTOTAL_SCH0                (1)
#define ETH_CFG_ETHCTRLCONFIGSCHEDULERTOTAL                  	  (1)

#endif



