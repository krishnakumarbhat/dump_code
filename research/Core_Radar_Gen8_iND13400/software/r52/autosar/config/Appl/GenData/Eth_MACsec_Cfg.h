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

/*===========================================================================*/
/**
 * @file Eth_MACsec_Cfg.h
 * MACsec Driver configurations
 *
 * @date    Date created:   09-01-2026
 *
 * @copyright (c) indie Semiconductor 2025. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary.
 *
 * @details
 * ### Full description
 * Configurations need by the MACsec driver
 *
 * ### Traceability info
 * + **Design documents:**
 *     + 
 *
 * + **Requirements document:**
 *     + AUTOSAR_FO_RS_MACsec.pdf
 *
 * + **Applicable standards:**
 *     + 
 *
 * + **Deviations from standards:**
 *
 *
 */

/*===========================================================================*/
#if !defined (ETH_MACSEC_CFG_H)
# define ETH_MACSEC_CFG_H
#ifdef __cplusplus
extern "C"{
#endif

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Eth_MACsec_Types.h"

/*===========================================================================*
 * Global Preprocessor defined MACROS
 *===========================================================================*/

#define MACSEC_VLAN_MODE   MACSEC_VLAN_MODE_NOP
#define MACSEC_TX_SAD_MTU                  0x800u
#define MACSEC_TX_SAD_SOFT_TTL             0x0u
#define MACSEC_TX_SAD_HARD_TTL             0x0u

/*  
Enables the call of the MACsec APIs through MKA-->EthIF-->EthTrcv_Generic
Note: This macro shall not be set to STD_ON with the demo app
*/

#define ETH_CFG_MACSEC_ENABLED    STD_OFF

#define ETH_CFG_ENABLE_MACSEC_HW_BYPASS   STD_ON


/* Enables the CLK fix mentioned in http://jira.indiesemi.com:8080/browse/CHAN-786 for MACsec */
#define ETHMACSEC_RX_TEST STD_OFF


/* Enables the MACsec IP to be configured by static configurations without the MKA */ 
#define ETHMACSEC_TEST_WITHOUT_MKA STD_OFF

#ifdef __cplusplus
}
#endif
#endif /* ETH_MACSEC_CFG_H */

/*===========================================================================*
 *  Revision History
 *===========================================================================*/
/**
 *  ---------------------------------------------------------------------------
 *  Version   Date          Author          Description
 *  ---------------------------------------------------------------------------
 *  1.0       4/2/2025      Amr Khaled      Initial Implementation of MACsec drv
**/

/*===========================================================================*
 *  END OF FILE: Eth_MACsec_Cfg.h
 *===========================================================================*/

