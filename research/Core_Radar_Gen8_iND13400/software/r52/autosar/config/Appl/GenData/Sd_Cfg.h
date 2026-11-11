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
 *            Module: Sd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Sd_Cfg.h
 *   Generation Time: 2026-08-27 14:12:20
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
#if !defined (SD_CFG_H)
# define SD_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Appl_Rand.h"

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#define SD_VERSION_INFO_API                                STD_OFF
#define SD_DEV_ERROR_REPORT                                STD_ON
#define SD_DEV_ERROR_DETECT                                STD_ON
#define SD_RUNTIME_ERROR_REPORT                            STD_ON
#define SD_MAIN_FCT_CYCLE_TIME_MS                          5u
#define SD_DEM_EVENTS_CONFIGURED                           STD_OFF
#define SD_SET_REM_ADDR_OF_CLIENT_RX_MULTICAST_SOCON       STD_ON
#define SD_GET_RESET_MEASUREMENT_DATA_API                  STD_OFF
#define SD_RUNTIME_MEASUREMENT_SUPPORT                     STD_ON
#define SD_MULTI_PARTITION                                 STD_OFF
#define SD_FAST_SUBSCRIPTION_RECOVERY                      STD_OFF
#define SD_ACL_POLICY_CHECK                                FALSE
#define SD_SECURITY_EVENT_REPORTING                        STD_OFF

/* Random Number Function */
#define Sd_ExternalRandomNumberFct Appl_Crypto_GetRandNo



/**
 * \defgroup SdHandleIdsUnicastRxPdu Handle IDs of handle space UnicastRxPdu.
 * \brief Parameter: SdInstanceUnicastRxPdu
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdInstanceUnicastRxPdu_SdInstanceUnicastRxPdu          1u      /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup SdHandleIdsMulticastRxPdu Handle IDs of handle space MulticastRxPdu.
 * \brief Parameter: SdInstanceMulticastRxPdu
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdInstanceMulticastRxPdu_SdInstanceMulticastRxPdu      0u      /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup SdHandleIdsClient Handle IDs of handle space Client.
 * \brief Parameter: SdClientServiceHandleId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdClientService_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b 0u /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup SdHandleIdsServer Handle IDs of handle space Server.
 * \brief Parameter: SdServerServiceHandleId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdServerService_provService_RDR_1_Detections_89f78c9f  0u      /**< [PostBuildInvariantValuesModelView] */
#define SdConf_SdServerService_provService_RDR_1_SW_Info_c2745ec9     1u      /**< [PostBuildInvariantValuesModelView] */
#define SdConf_SdServerService_provService_RDR_1_Status_d2069d01      2u      /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup SdHandleIdsConsumedEventGroup Handle IDs of handle space ConsumedEventGroup.
 * \brief Parameter: SdConsumedEventGroupHandleId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdConsumedEventGroup_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85 0u /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**
 * \defgroup SdHandleIdsEventHandler Handle IDs of handle space EventHandler.
 * \brief Parameter: SdEventHandlerHandleId
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SdConf_SdEventHandler_EventGroup_RDR_1_653e2581               1u      /**< [PostBuildInvariantValuesModelView] */
#define SdConf_SdEventHandler_EventGroup_RDR_1_ca62382d               0u      /**< [PostBuildInvariantValuesModelView] */
#define SdConf_SdEventHandler_EventGroup_RDR_1_f7c73cae               2u      /**< [PostBuildInvariantValuesModelView] */
/**\} */



/**********************************************************************************************************************
 *  MODULE SPECIFIC DEFINES
 *********************************************************************************************************************/
#ifndef SD_USE_DUMMY_STATEMENT
#define SD_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SD_DUMMY_STATEMENT
#define SD_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SD_DUMMY_STATEMENT_CONST
#define SD_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SD_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SD_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SD_ATOMIC_VARIABLE_ACCESS
#define SD_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SD_PROCESSOR_IND13400
#define SD_PROCESSOR_IND13400
#endif
#ifndef SD_COMP_LLVMDIAB
#define SD_COMP_LLVMDIAB
#endif
#ifndef SD_GEN_GENERATOR_MSR
#define SD_GEN_GENERATOR_MSR
#endif
#ifndef SD_CPUTYPE_BITORDER_LSB2MSB
#define SD_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SD_CONFIGURATION_VARIANT_PRECOMPILE
#define SD_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SD_CONFIGURATION_VARIANT_LINKTIME
#define SD_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SD_CONFIGURATION_VARIANT
#define SD_CONFIGURATION_VARIANT SD_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SD_POSTBUILD_VARIANT_SUPPORT
#define SD_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif




#endif /* SD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Sd_Cfg.h
 *********************************************************************************************************************/

