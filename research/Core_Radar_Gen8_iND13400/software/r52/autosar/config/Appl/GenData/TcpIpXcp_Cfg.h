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
 *              File: TcpIpXcp_Cfg.h
 *   Generation Time: 2026-08-11 12:42:54
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


#if !defined(TCPIPXCP_CFG_H)
#define TCPIPXCP_CFG_H

/* -----------------------------------------------------------------------------
    &&&~  
 ----------------------------------------------------------------------------- */

/* TcpIpXcpTxPduId symbolic name defines */



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

/* TcpIpXcpRxPduId symbolic name defines */



/**
 * \defgroup XcpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpRxPdu_XcpRxPdu                                     0       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpRxPdu_XcpRxPdu_001                                 0       /**< [PostBuildInvariantValuesModelView] */
/**\} */

#ifndef XCP_USE_DUMMY_STATEMENT
#define XCP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT_CONST
#define XCP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XCP_ATOMIC_VARIABLE_ACCESS
#define XCP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XCP_PROCESSOR_IND13400
#define XCP_PROCESSOR_IND13400
#endif
#ifndef XCP_COMP_LLVMDIAB
#define XCP_COMP_LLVMDIAB
#endif
#ifndef XCP_GEN_GENERATOR_MSR
#define XCP_GEN_GENERATOR_MSR
#endif
#ifndef XCP_CPUTYPE_BITORDER_LSB2MSB
#define XCP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef XCP_CONFIGURATION_VARIANT_PRECOMPILE
#define XCP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XCP_CONFIGURATION_VARIANT_LINKTIME
#define XCP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XCP_CONFIGURATION_VARIANT
#define XCP_CONFIGURATION_VARIANT XCP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XCP_POSTBUILD_VARIANT_SUPPORT
#define XCP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifndef TCPIPXCP_CONFIG_VARIANT
#define TCPIPXCP_CONFIG_VARIANT XCP_CONFIGURATION_VARIANT
#endif

#define TCPIPXCP_TRANSPORT_LAYER_VERSION     0x0100u
#define TCPIPXCP_CONFIGURATOR                5u
/* Development error detecting and reporting */
#define TCPIPXCP_DEV_ERROR_DETECT            STD_ON
#define TCPIPXCP_DEV_ERROR_REPORT            STD_ON
/* Pre-processor switch for enabling version info support. ON/OFF */ 
#define TCPIPXCP_VERSION_INFO_API            STD_OFF
/* Enable/Disable transport layer activation control API */ 
#define TCPIPXCP_ENABLE_CONTROL              STD_ON
#define TCPIPXCP_MODE_CHG_API                STD_ON
#define TCPIPXCP_PROTOCOL_FORMAT             TCPIPXCP_PROTOCOL_UDP
#define TCPIPXCP_ENABLE_PDUMODE              STD_OFF
#define TCPIPXCP_NUMBER_OF_CHANNELS          1u
#define TCPIPXCP_CONF_TIMEOUT                10u
#define TCPIPXCP_MULTI_CONN_PROT             STD_OFF
#define TCPIPXCP_CONCATENATION_MODE          STD_ON
#define TCPIPXCP_BURST_MODE                  STD_ON
#define TCPIPXCP_BURST_MODE_SIZE             10u
#define TCPIPXCP_USE_PDUR                    STD_OFF
/*  - Synchronous Data Acquisition (DAQ) commands */
#if !defined XCP_ENABLE_DAQ
# define XCP_ENABLE_DAQ                       STD_ON
#endif                       

#define TCPIPXCP_PDU_SIZE                    1448u
/* Pre-processor values for Max CTO and Max DTO parameters */ 
#define kTcpIpXcpMaxCTO                      255u
#define kTcpIpXcpMaxDTO                      1444u

#define TCPIPXCP_AUTOSARVERSION              411u

#include "TcpIpXcp_Types.h" 


#endif /* TCPIPXCP_CFG_H */


