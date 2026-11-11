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
 *            Module: LdCom
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LdCom_Cfg.h
 *   Generation Time: 2026-04-02 15:09:55
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

#if !defined (LDCOM_CFG_H)
# define LDCOM_CFG_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* General defines */
#ifndef LDCOM_USE_DUMMY_STATEMENT
#define LDCOM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LDCOM_DUMMY_STATEMENT
#define LDCOM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LDCOM_DUMMY_STATEMENT_CONST
#define LDCOM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LDCOM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define LDCOM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef LDCOM_ATOMIC_VARIABLE_ACCESS
#define LDCOM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef LDCOM_PROCESSOR_IND13400
#define LDCOM_PROCESSOR_IND13400
#endif
#ifndef LDCOM_COMP_LLVMDIAB
#define LDCOM_COMP_LLVMDIAB
#endif
#ifndef LDCOM_GEN_GENERATOR_MSR
#define LDCOM_GEN_GENERATOR_MSR
#endif
#ifndef LDCOM_CPUTYPE_BITORDER_LSB2MSB
#define LDCOM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef LDCOM_CONFIGURATION_VARIANT_PRECOMPILE
#define LDCOM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LDCOM_CONFIGURATION_VARIANT_LINKTIME
#define LDCOM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LDCOM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LDCOM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef LDCOM_CONFIGURATION_VARIANT
#define LDCOM_CONFIGURATION_VARIANT LDCOM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef LDCOM_POSTBUILD_VARIANT_SUPPORT
#define LDCOM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* General API */
#define LDCOM_COMMUNICATION_INTERFACE  STD_ON  /**< /ActiveEcuC/PduR/LdCom[0:PduRCommunicationInterface] */
#define LDCOM_TRANSPORT_PROTOCOL       STD_ON  /**< /ActiveEcuC/PduR/LdCom[0:PduRTransportProtocol] */
#define LDCOM_TRIGGER_TRANSMIT_API     STD_OFF  /**< /ActiveEcuC/PduR/LdCom[0:PduRTriggertransmit] */
#define LDCOM_TX_CONFIRMATION_API      STD_OFF  /**< /ActiveEcuC/PduR/LdCom[0:PduRTxConfirmation] */

#define LDCOM_DEV_ERROR_DETECT         STD_ON  /**< /ActiveEcuC/LdCom/LdComGeneral[0:LdComSafeBswChecks] || /ActiveEcuC/LdCom/LdComGeneral[0:LdComDevErrorDetect] */
#define LDCOM_DEV_ERROR_REPORT         STD_ON  /**< /ActiveEcuC/LdCom/LdComGeneral[0:LdComDevErrorDetect] */
#define LDCOM_VERSION_INFO_API         STD_OFF  /**< /ActiveEcuC/LdCom/LdComGeneral[0:LdComVersionInfoApi] */

/* Symbolic name values (SNV) */



/**
 * \defgroup LdComHandleIdsLdComPdu Handle IDs of handle space LdComPdu.
 * \brief LdComPdu
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define LdComConf_LdComIPdu_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx 0u      /**< [PostBuildInvariantValuesModelView] */
#define LdComConf_LdComIPdu_signalPdu_RDR_1_Detections_52b391ee_Tx    1u      /**< [PostBuildInvariantValuesModelView] */
#define LdComConf_LdComIPdu_signalPdu_RDR_1_SW_Info_b4e751e3_Tx       2u      /**< [PostBuildInvariantValuesModelView] */
#define LdComConf_LdComIPdu_signalPdu_RDR_1_Status_9d482741_Tx        3u      /**< [PostBuildInvariantValuesModelView] */
/**\} */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USER CONFIGURATION FILE
 *********************************************************************************************************************/
/* User Config File Start */

/* User Config File End */

#endif  /* LDCOM_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: LdCom_Cfg.h
 *********************************************************************************************************************/
