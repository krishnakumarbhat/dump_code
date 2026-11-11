/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Xcp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanXcp_Cfg.h
 *   Generation Time: 2026-05-11 17:41:24
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


#if !defined(CANXCP_CFG_H)
#define CANXCP_CFG_H

/* -----------------------------------------------------------------------------
    &&&~  
 ----------------------------------------------------------------------------- */

#include "CanXcp_Types.h"

#if !defined XcpConfig
#define XcpConfig    CanXcp_Config
#endif

/* CanXcpTxPduId symbolic name defines */



/**
 * \defgroup XcpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpTxPdu_XcpTxPdu                                     0       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpTxPdu_XcpTxPdu_001                                 0       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpTxPdu_XcpTxPdu_002                                 1       /**< [PostBuildInvariantValuesModelView] */
/**\} */

/* CanXcpRxPduId symbolic name defines */



/**
 * \defgroup XcpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpRxPdu_XcpRxPdu                                     0       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpRxPdu_XcpRxPdu_001                                 0       /**< [PostBuildInvariantValuesModelView] */
/**\} */

#ifndef CANXCP_CONFIG_VARIANT
#define CANXCP_CONFIG_VARIANT XCP_CONFIGURATION_VARIANT
#endif

#define CANXCP_DEV_ERROR_DETECT              STD_ON
#define CANXCP_DEV_ERROR_REPORT              STD_ON
#define CANXCP_VERSION_INFO_API              STD_OFF   

/* Transport Layer */
#define CANXCP_MULTI_CONN_PROT               STD_OFF
#define CANXCP_VARIABLE_DLC                  STD_ON
#define CANXCP_TRANSPORT_LAYER_VERSION       0x0100u
#define kXcpSendQueueMinSize                 1u
/* Enable/Disable transport layer activation control API */
#define CANXCP_ENABLE_CONTROL                STD_ON
#define CANXCP_NUMBER_OF_CHANNELS            1u
#define CANXCP_CONF_TIMEOUT                  10u
#define kCanXcpMaxCTO                        64u
#define kCanXcpMaxDTO                        64u

#define CANXCP_PDU_SIZE                      64u /* CAN-FD specific options */
#define CANXCP_ENABLE_PDUMODE                STD_OFF


#endif /* CANXCP_CFG_H */


