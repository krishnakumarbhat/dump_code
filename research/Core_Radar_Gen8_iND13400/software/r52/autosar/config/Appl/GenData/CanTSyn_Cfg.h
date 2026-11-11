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
 *            Module: CanTSyn
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTSyn_Cfg.h
 *   Generation Time: 2026-05-13 15:21:26
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
#if !defined (CANTSYN_CFG_H)
# define CANTSYN_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "CanTSyn_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* General defines */
#ifndef CANTSYN_USE_DUMMY_STATEMENT
#define CANTSYN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_DUMMY_STATEMENT
#define CANTSYN_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_DUMMY_STATEMENT_CONST
#define CANTSYN_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANTSYN_ATOMIC_VARIABLE_ACCESS
#define CANTSYN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANTSYN_PROCESSOR_IND13400
#define CANTSYN_PROCESSOR_IND13400
#endif
#ifndef CANTSYN_COMP_LLVMDIAB
#define CANTSYN_COMP_LLVMDIAB
#endif
#ifndef CANTSYN_GEN_GENERATOR_MSR
#define CANTSYN_GEN_GENERATOR_MSR
#endif
#ifndef CANTSYN_CPUTYPE_BITORDER_LSB2MSB
#define CANTSYN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#define CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_LINKTIME
#define CANTSYN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT
#define CANTSYN_CONFIGURATION_VARIANT CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANTSYN_POSTBUILD_VARIANT_SUPPORT
#define CANTSYN_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


/* Version identification */
# define CANTSYN_CFG_MAJOR_VERSION                         (7u)
# define CANTSYN_CFG_MINOR_VERSION                         (2u)

# define CANTSYN_DEV_ERROR_DETECT                          (STD_ON)
# define CANTSYN_DEV_ERROR_REPORT                          (STD_ON)
# define CANTSYN_VERSION_INFO_API                          (STD_OFF)
# define CANTSYN_MAIN_FUNCTION_CYCLE                       (10u /*  ms  */ )

# define CANTSYN_CRC_USED                                  (STD_ON)
# define CANTSYN_AR_4_3_X
# define CANTSYN_EXISTS_SHARED_PDUS                        (STD_OFF)
# define CANTSYN_EXTENDED_MESSAGE_USED                     (STD_OFF)
# define CANTSYN_STANDARD_MESSAGE_USED                     (STD_ON)

/* If the StbM does not provide the Time Base Type, the offset between Time Domain ID and Message Domain ID is 16; otherwise, it is 0. */
# define CANTSYN_MESSAGE_DOMAIN_ID_OFFSET                  (16u)

/* Master debounce counter configuration */
# define CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER            (STD_OFF)

/* Multi-Core/Multi-Partition configuration */
# define CANTSYN_MULTIPARTITION_USED                       (STD_OFF)

/* Message types */
#define CANTSYN_TIME_SYNC_MESSAGE_DLC                       (8u)
#define CANTSYN_TIME_SYNC_EXTENDED_MESSAGE_DLC              (16u)
#define CANTSYN_TIME_SYNC_MAX_MESSAGE_DLC                   (CANTSYN_TIME_SYNC_MESSAGE_DLC)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC         (0x10u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC             (0x20u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC          (0x18u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC              (0x28u)
#ifdef CANTSYN_AR_4_3_X
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC         (0x34u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC             (0x44u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC        (0x3Cu)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC            (0x4Cu)
#endif
#ifdef CANTSYN_AR_4_2_X
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC         (0x30u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC             (0x40u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC        (0x38u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC            (0x48u)
#endif




/**
 * \defgroup CanTSynHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanTSynConf_CanTSynGlobalTimeMasterPdu_CanTSynGlobalTimeMasterPdu 0u  /**< [RDR_05] */
/**\} */




/**
 * \defgroup CanTSynHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in multiple predefined variants */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanTSynConf_CanTSynGlobalTimeSlavePdu_CanTSynGlobalTimeSlavePdu 0u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_06, RDR_07, RDR_08] */
/**\} */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCDataSwitches  CanTSyn Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTSYN_CONTROLLERINFO                                                                      STD_ON
#define CANTSYN_SNVOFCONTROLLERINFO                                                                 STD_ON
#define CANTSYN_CONTROLLERPDUPARTITIONMAPPING                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_CONTROLLERIDOFCONTROLLERPDUPARTITIONMAPPING                                         STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PARTITIONCONFIGIDXOFCONTROLLERPDUPARTITIONMAPPING                                   STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_DOMAINCONFIG                                                                        STD_ON
#define CANTSYN_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                      STD_ON
#define CANTSYN_DOMAINIDOFDOMAINCONFIG                                                              STD_ON
#define CANTSYN_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                                   STD_ON
#define CANTSYN_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                                 STD_ON
#define CANTSYN_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                                     STD_ON
#define CANTSYN_MASTERCONFIGENDIDXOFDOMAINCONFIG                                                    STD_ON
#define CANTSYN_MASTERCONFIGLENGTHOFDOMAINCONFIG                                                    STD_ON
#define CANTSYN_MASTERCONFIGSTARTIDXOFDOMAINCONFIG                                                  STD_ON
#define CANTSYN_MASTERCONFIGUSEDOFDOMAINCONFIG                                                      STD_ON
#define CANTSYN_MESSAGEDLCOFDOMAINCONFIG                                                            STD_ON
#define CANTSYN_OFFSETDOMAINOFDOMAINCONFIG                                                          STD_ON
#define CANTSYN_SLAVECONFIGIDXOFDOMAINCONFIG                                                        STD_ON
#define CANTSYN_SLAVECONFIGUSEDOFDOMAINCONFIG                                                       STD_ON
#define CANTSYN_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                                  STD_ON
#define CANTSYN_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                                STD_ON
#define CANTSYN_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                                    STD_ON
#define CANTSYN_TIMEBASEIDOFDOMAINCONFIG                                                            STD_ON
#define CANTSYN_FINALMAGICNUMBER                                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_FUPDATAIDLIST                                                                       STD_ON
#define CANTSYN_INITDATAHASHCODE                                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_INITIALIZED                                                                         STD_ON
#define CANTSYN_MASTERCONFIG                                                                        STD_ON
#define CANTSYN_CONTROLLERINFOIDXOFMASTERCONFIG                                                     STD_ON
#define CANTSYN_CYCLICMSGRESUMETIMEOFMASTERCONFIG                                                   STD_ON
#define CANTSYN_DEBOUNCETIMEOFMASTERCONFIG                                                          STD_ON
#define CANTSYN_DOMAINCONFIGIDXOFMASTERCONFIG                                                       STD_ON
#define CANTSYN_FUPMESSAGETYPEOFMASTERCONFIG                                                        STD_ON
#define CANTSYN_IMMEDIATETIMESYNCOFMASTERCONFIG                                                     STD_ON
#define CANTSYN_MASTERCONFHANDLEIDOFMASTERCONFIG                                                    STD_ON
#define CANTSYN_MASTERCONFTIMEOUTOFMASTERCONFIG                                                     STD_ON
#define CANTSYN_MESSAGEDOMAINIDOFMASTERCONFIG                                                       STD_ON
#define CANTSYN_PARTITIONCONFIGIDXOFMASTERCONFIG                                                    STD_ON
#define CANTSYN_PDUIDSTATESIDXOFMASTERCONFIG                                                        STD_ON
#define CANTSYN_SYNCMESSAGETYPEOFMASTERCONFIG                                                       STD_ON
#define CANTSYN_TXCRCSECUREDOFMASTERCONFIG                                                          STD_ON
#define CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG                                                  STD_ON
#define CANTSYN_TXDEBOUNCECOUNTERUSEDOFMASTERCONFIG                                                 STD_ON
#define CANTSYN_TXPDUIDOFMASTERCONFIG                                                               STD_ON
#define CANTSYN_TXPERIODOFMASTERCONFIG                                                              STD_ON
#define CANTSYN_MASTERPDUPARTITIONMAPPING                                                           STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PARTITIONCONFIGIDXOFMASTERPDUPARTITIONMAPPING                                       STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PDUIDOFMASTERPDUPARTITIONMAPPING                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MASTERSTATE                                                                         STD_ON
#define CANTSYN_CYCLICMSGRESUMECOUNTEROFMASTERSTATE                                                 STD_ON
#define CANTSYN_FUPTIMESTAMPOFMASTERSTATE                                                           STD_ON
#define CANTSYN_LASTUPDATECOUNTEROFMASTERSTATE                                                      STD_ON
#define CANTSYN_STATEOFMASTERSTATE                                                                  STD_ON
#define CANTSYN_SYNCTIMESTAMPOFMASTERSTATE                                                          STD_ON
#define CANTSYN_TIMEBASESTATUSOFMASTERSTATE                                                         STD_ON
#define CANTSYN_TRANSMITIMMEDIATESYNCOFMASTERSTATE                                                  STD_ON
#define CANTSYN_TXCONFIRMATIONTIMEOUTCOUNTEROFMASTERSTATE                                           STD_ON
#define CANTSYN_TXPERIODCOUNTEROFMASTERSTATE                                                        STD_ON
#define CANTSYN_TXSEQUENCECOUNTEROFMASTERSTATE                                                      STD_ON
#define CANTSYN_USERDATAOFMASTERSTATE                                                               STD_ON
#define CANTSYN_VIRTUALLOCALTIMEOFMASTERSTATE                                                       STD_ON
#define CANTSYN_PARTITIONIDENTIFIERS                                                                STD_ON
#define CANTSYN_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                          STD_ON
#define CANTSYN_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                  STD_ON
#define CANTSYN_PDUIDSTATES                                                                         STD_ON
#define CANTSYN_SIZEOFCONTROLLERINFO                                                                STD_ON
#define CANTSYN_SIZEOFCONTROLLERPDUPARTITIONMAPPING                                                 STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFDOMAINCONFIG                                                                  STD_ON
#define CANTSYN_SIZEOFFUPDATAIDLIST                                                                 STD_ON
#define CANTSYN_SIZEOFMASTERCONFIG                                                                  STD_ON
#define CANTSYN_SIZEOFMASTERPDUPARTITIONMAPPING                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFMASTERSTATE                                                                   STD_ON
#define CANTSYN_SIZEOFPARTITIONIDENTIFIERS                                                          STD_ON
#define CANTSYN_SIZEOFPDUIDSTATES                                                                   STD_ON
#define CANTSYN_SIZEOFSLAVECONFIG                                                                   STD_ON
#define CANTSYN_SIZEOFSLAVEPDUPARTITIONMAPPING                                                      STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFSLAVESTATE                                                                    STD_ON
#define CANTSYN_SIZEOFSYNCDATAIDLIST                                                                STD_ON
#define CANTSYN_SIZEOFTRANSMISSIONCONTROLLERSTATE                                                   STD_ON
#define CANTSYN_SIZEOFTXDEBOUNCECOUNTER                                                             STD_ON
#define CANTSYN_SLAVECONFIG                                                                         STD_ON
#define CANTSYN_DOMAINCONFIGIDXOFSLAVECONFIG                                                        STD_ON
#define CANTSYN_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                        STD_ON
#define CANTSYN_PARTITIONCONFIGIDXOFSLAVECONFIG                                                     STD_ON
#define CANTSYN_RXCRCVALIDATEDOFSLAVECONFIG                                                         STD_ON
#define CANTSYN_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                               STD_ON
#define CANTSYN_SLAVEHANDLEIDOFSLAVECONFIG                                                          STD_ON
#define CANTSYN_SLAVEPDUPARTITIONMAPPING                                                            STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PARTITIONCONFIGIDXOFSLAVEPDUPARTITIONMAPPING                                        STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionConfigIdx' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PDUIDOFSLAVEPDUPARTITIONMAPPING                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_SLAVESTATE                                                                          STD_ON
#define CANTSYN_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                                  STD_ON
#define CANTSYN_RXSEQUENCECOUNTEROFSLAVESTATE                                                       STD_ON
#define CANTSYN_STATEOFSLAVESTATE                                                                   STD_ON
#define CANTSYN_SYNCMSGOFSLAVESTATE                                                                 STD_ON
#define CANTSYN_VIRTUALLOCALTIMEOFSLAVESTATE                                                        STD_ON
#define CANTSYN_SYNCDATAIDLIST                                                                      STD_ON
#define CANTSYN_TRANSMISSIONCONTROLLERSTATE                                                         STD_ON
#define CANTSYN_TXDEBOUNCECOUNTER                                                                   STD_ON
#define CANTSYN_PCCONFIG                                                                            STD_ON
#define CANTSYN_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_PCPARTITIONCONFIGOFPCCONFIG                                                         STD_ON
#define CANTSYN_PARTITIONIDENTIFIERSOFPCCONFIG                                                      STD_ON
#define CANTSYN_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                STD_ON
#define CANTSYN_PCPARTITIONCONFIG                                                                   STD_ON
#define CANTSYN_CONTROLLERINFOOFPCPARTITIONCONFIG                                                   STD_ON
#define CANTSYN_DOMAINCONFIGOFPCPARTITIONCONFIG                                                     STD_ON
#define CANTSYN_FUPDATAIDLISTOFPCPARTITIONCONFIG                                                    STD_ON
#define CANTSYN_INITIALIZEDOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_MASTERCONFIGOFPCPARTITIONCONFIG                                                     STD_ON
#define CANTSYN_MASTERSTATEOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_PDUIDSTATESOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_SIZEOFCONTROLLERINFOOFPCPARTITIONCONFIG                                             STD_ON
#define CANTSYN_SIZEOFCONTROLLERPDUPARTITIONMAPPINGOFPCPARTITIONCONFIG                              STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfigRDR_01.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_02.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_03.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_04.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_05.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_06.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_07.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_08.SizeOfControllerPduPartitionMapping' Reason: 'Deactivateable: 'ControllerPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFDOMAINCONFIGOFPCPARTITIONCONFIG                                               STD_ON
#define CANTSYN_SIZEOFFUPDATAIDLISTOFPCPARTITIONCONFIG                                              STD_ON
#define CANTSYN_SIZEOFMASTERCONFIGOFPCPARTITIONCONFIG                                               STD_ON
#define CANTSYN_SIZEOFMASTERPDUPARTITIONMAPPINGOFPCPARTITIONCONFIG                                  STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfigRDR_01.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_02.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_03.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_04.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_05.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_06.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_07.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_08.SizeOfMasterPduPartitionMapping' Reason: 'Deactivateable: 'MasterPduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFMASTERSTATEOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_SIZEOFPDUIDSTATESOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_SIZEOFSLAVECONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_SIZEOFSLAVEPDUPARTITIONMAPPINGOFPCPARTITIONCONFIG                                   STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfigRDR_01.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_02.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_03.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_04.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_05.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_06.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_07.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' and Deactivateable: 'CanTSyn_PCPartitionConfigRDR_08.SizeOfSlavePduPartitionMapping' Reason: 'Deactivateable: 'SlavePduPartitionMapping' Reason: 'Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define CANTSYN_SIZEOFSLAVESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define CANTSYN_SIZEOFSYNCDATAIDLISTOFPCPARTITIONCONFIG                                             STD_ON
#define CANTSYN_SIZEOFTRANSMISSIONCONTROLLERSTATEOFPCPARTITIONCONFIG                                STD_ON
#define CANTSYN_SIZEOFTXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                          STD_ON
#define CANTSYN_SLAVECONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_SLAVESTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define CANTSYN_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                                   STD_ON
#define CANTSYN_TRANSMISSIONCONTROLLERSTATEOFPCPARTITIONCONFIG                                      STD_ON
#define CANTSYN_TXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCMinNumericValueDefines  CanTSyn Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANTSYN_MIN_CYCLICMSGRESUMECOUNTEROFMASTERSTATE                                             0u
#define CANTSYN_MIN_LASTUPDATECOUNTEROFMASTERSTATE                                                  0u
#define CANTSYN_MIN_TXCONFIRMATIONTIMEOUTCOUNTEROFMASTERSTATE                                       0u
#define CANTSYN_MIN_TXPERIODCOUNTEROFMASTERSTATE                                                    0u
#define CANTSYN_MIN_TXSEQUENCECOUNTEROFMASTERSTATE                                                  0u
#define CANTSYN_MIN_PDUIDSTATES                                                                     0u
#define CANTSYN_MIN_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                              0u
#define CANTSYN_MIN_RXSEQUENCECOUNTEROFSLAVESTATE                                                   0u
#define CANTSYN_MIN_TXDEBOUNCECOUNTER                                                               0u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCMaxNumericValueDefines  CanTSyn Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANTSYN_MAX_CYCLICMSGRESUMECOUNTEROFMASTERSTATE                                             4294967295u
#define CANTSYN_MAX_LASTUPDATECOUNTEROFMASTERSTATE                                                  255u
#define CANTSYN_MAX_TXCONFIRMATIONTIMEOUTCOUNTEROFMASTERSTATE                                       4294967295u
#define CANTSYN_MAX_TXPERIODCOUNTEROFMASTERSTATE                                                    4294967295u
#define CANTSYN_MAX_TXSEQUENCECOUNTEROFMASTERSTATE                                                  255u
#define CANTSYN_MAX_PDUIDSTATES                                                                     255u
#define CANTSYN_MAX_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                              4294967295u
#define CANTSYN_MAX_RXSEQUENCECOUNTEROFSLAVESTATE                                                   255u
#define CANTSYN_MAX_TXDEBOUNCECOUNTER                                                               255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCNoReferenceDefines  CanTSyn No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANTSYN_NO_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                                255u
#define CANTSYN_NO_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                              255u
#define CANTSYN_NO_MASTERCONFIGENDIDXOFDOMAINCONFIG                                                 255u
#define CANTSYN_NO_MASTERCONFIGSTARTIDXOFDOMAINCONFIG                                               255u
#define CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG                                                     255u
#define CANTSYN_NO_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                               255u
#define CANTSYN_NO_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                             255u
#define CANTSYN_NO_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG                                               255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEnumExistsDefines  CanTSyn Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANTSYN_EXISTS_CRC_OFFSET_CRCANDDOMAINTYPEOFDOMAINCONFIG                                    STD_OFF
#define CANTSYN_EXISTS_NOT_CRC_OFFSET_CRCANDDOMAINTYPEOFDOMAINCONFIG                                STD_OFF
#define CANTSYN_EXISTS_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                      STD_ON
#define CANTSYN_EXISTS_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                  STD_ON
#define CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                            STD_OFF
#define CANTSYN_EXISTS_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                        STD_ON
#define CANTSYN_EXISTS_NOT_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG                                STD_ON
#define CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG                                    STD_OFF
#define CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG                                              STD_OFF
#define CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG                                          STD_ON
#define CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG                                               STD_OFF
#define CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG                                           STD_OFF
#define CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG                                          STD_OFF
#define CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                    STD_OFF
#define CANTSYN_EXISTS_OPTIONAL_RXCRCVALIDATEDOFSLAVECONFIG                                         STD_OFF
#define CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEnumDefines  CanTSyn Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANTSYN_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                             0x02u
#define CANTSYN_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                         0x03u
#define CANTSYN_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                               0x01u
#define CANTSYN_NOT_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG                                       0x00u
#define CANTSYN_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG                                                 0x01u
#define CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                               0x03u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIsReducedToDefineDefines  CanTSyn Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANTSYN_ISDEF_SNVOFCONTROLLERINFO                                                           STD_OFF
#define CANTSYN_ISDEF_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                STD_OFF
#define CANTSYN_ISDEF_DOMAINIDOFDOMAINCONFIG                                                        STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                             STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                           STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_MASTERCONFIGENDIDXOFDOMAINCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_MASTERCONFIGLENGTHOFDOMAINCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_MASTERCONFIGSTARTIDXOFDOMAINCONFIG                                            STD_OFF
#define CANTSYN_ISDEF_MASTERCONFIGUSEDOFDOMAINCONFIG                                                STD_OFF
#define CANTSYN_ISDEF_MESSAGEDLCOFDOMAINCONFIG                                                      STD_OFF
#define CANTSYN_ISDEF_OFFSETDOMAINOFDOMAINCONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_SLAVECONFIGIDXOFDOMAINCONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_SLAVECONFIGUSEDOFDOMAINCONFIG                                                 STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                            STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                          STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_TIMEBASEIDOFDOMAINCONFIG                                                      STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLIST                                                                 STD_OFF
#define CANTSYN_ISDEF_CONTROLLERINFOIDXOFMASTERCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_CYCLICMSGRESUMETIMEOFMASTERCONFIG                                             STD_OFF
#define CANTSYN_ISDEF_DEBOUNCETIMEOFMASTERCONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_DOMAINCONFIGIDXOFMASTERCONFIG                                                 STD_OFF
#define CANTSYN_ISDEF_FUPMESSAGETYPEOFMASTERCONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_IMMEDIATETIMESYNCOFMASTERCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_MASTERCONFHANDLEIDOFMASTERCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_MASTERCONFTIMEOUTOFMASTERCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_MESSAGEDOMAINIDOFMASTERCONFIG                                                 STD_OFF
#define CANTSYN_ISDEF_PARTITIONCONFIGIDXOFMASTERCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_PDUIDSTATESIDXOFMASTERCONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_SYNCMESSAGETYPEOFMASTERCONFIG                                                 STD_OFF
#define CANTSYN_ISDEF_TXCRCSECUREDOFMASTERCONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG                                            STD_OFF
#define CANTSYN_ISDEF_TXDEBOUNCECOUNTERUSEDOFMASTERCONFIG                                           STD_OFF
#define CANTSYN_ISDEF_TXPDUIDOFMASTERCONFIG                                                         STD_OFF
#define CANTSYN_ISDEF_TXPERIODOFMASTERCONFIG                                                        STD_OFF
#define CANTSYN_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                    STD_OFF
#define CANTSYN_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                            STD_OFF
#define CANTSYN_ISDEF_DOMAINCONFIGIDXOFSLAVECONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_PARTITIONCONFIGIDXOFSLAVECONFIG                                               STD_OFF
#define CANTSYN_ISDEF_RXCRCVALIDATEDOFSLAVECONFIG                                                   STD_OFF
#define CANTSYN_ISDEF_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                         STD_OFF
#define CANTSYN_ISDEF_SLAVEHANDLEIDOFSLAVECONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLIST                                                                STD_OFF
#define CANTSYN_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                   STD_OFF
#define CANTSYN_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                STD_ON
#define CANTSYN_ISDEF_CONTROLLERINFOOFPCPARTITIONCONFIG                                             STD_OFF
#define CANTSYN_ISDEF_DOMAINCONFIGOFPCPARTITIONCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTOFPCPARTITIONCONFIG                                              STD_ON
#define CANTSYN_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_ISDEF_MASTERCONFIGOFPCPARTITIONCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_MASTERSTATEOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_ISDEF_PDUIDSTATESOFPCPARTITIONCONFIG                                                STD_OFF
#define CANTSYN_ISDEF_SIZEOFCONTROLLERINFOOFPCPARTITIONCONFIG                                       STD_OFF
#define CANTSYN_ISDEF_SIZEOFMASTERCONFIGOFPCPARTITIONCONFIG                                         STD_OFF
#define CANTSYN_ISDEF_SIZEOFPDUIDSTATESOFPCPARTITIONCONFIG                                          STD_OFF
#define CANTSYN_ISDEF_SIZEOFSLAVECONFIGOFPCPARTITIONCONFIG                                          STD_OFF
#define CANTSYN_ISDEF_SIZEOFTXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                    STD_OFF
#define CANTSYN_ISDEF_SLAVECONFIGOFPCPARTITIONCONFIG                                                STD_OFF
#define CANTSYN_ISDEF_SLAVESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define CANTSYN_ISDEF_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                             STD_ON
#define CANTSYN_ISDEF_TRANSMISSIONCONTROLLERSTATEOFPCPARTITIONCONFIG                                STD_OFF
#define CANTSYN_ISDEF_TXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                          STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEqualsAlwaysToDefines  CanTSyn Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANTSYN_EQ2_SNVOFCONTROLLERINFO                                                             
#define CANTSYN_EQ2_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                  
#define CANTSYN_EQ2_DOMAINIDOFDOMAINCONFIG                                                          
#define CANTSYN_EQ2_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                               
#define CANTSYN_EQ2_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                             
#define CANTSYN_EQ2_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                                 
#define CANTSYN_EQ2_MASTERCONFIGENDIDXOFDOMAINCONFIG                                                
#define CANTSYN_EQ2_MASTERCONFIGLENGTHOFDOMAINCONFIG                                                
#define CANTSYN_EQ2_MASTERCONFIGSTARTIDXOFDOMAINCONFIG                                              
#define CANTSYN_EQ2_MASTERCONFIGUSEDOFDOMAINCONFIG                                                  
#define CANTSYN_EQ2_MESSAGEDLCOFDOMAINCONFIG                                                        
#define CANTSYN_EQ2_OFFSETDOMAINOFDOMAINCONFIG                                                      
#define CANTSYN_EQ2_SLAVECONFIGIDXOFDOMAINCONFIG                                                    
#define CANTSYN_EQ2_SLAVECONFIGUSEDOFDOMAINCONFIG                                                   
#define CANTSYN_EQ2_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                              
#define CANTSYN_EQ2_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                            
#define CANTSYN_EQ2_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                                
#define CANTSYN_EQ2_TIMEBASEIDOFDOMAINCONFIG                                                        
#define CANTSYN_EQ2_FUPDATAIDLIST                                                                   
#define CANTSYN_EQ2_CONTROLLERINFOIDXOFMASTERCONFIG                                                 
#define CANTSYN_EQ2_CYCLICMSGRESUMETIMEOFMASTERCONFIG                                               
#define CANTSYN_EQ2_DEBOUNCETIMEOFMASTERCONFIG                                                      
#define CANTSYN_EQ2_DOMAINCONFIGIDXOFMASTERCONFIG                                                   
#define CANTSYN_EQ2_FUPMESSAGETYPEOFMASTERCONFIG                                                    
#define CANTSYN_EQ2_IMMEDIATETIMESYNCOFMASTERCONFIG                                                 
#define CANTSYN_EQ2_MASTERCONFHANDLEIDOFMASTERCONFIG                                                
#define CANTSYN_EQ2_MASTERCONFTIMEOUTOFMASTERCONFIG                                                 
#define CANTSYN_EQ2_MESSAGEDOMAINIDOFMASTERCONFIG                                                   
#define CANTSYN_EQ2_PARTITIONCONFIGIDXOFMASTERCONFIG                                                
#define CANTSYN_EQ2_PDUIDSTATESIDXOFMASTERCONFIG                                                    
#define CANTSYN_EQ2_SYNCMESSAGETYPEOFMASTERCONFIG                                                   
#define CANTSYN_EQ2_TXCRCSECUREDOFMASTERCONFIG                                                      
#define CANTSYN_EQ2_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG                                              
#define CANTSYN_EQ2_TXDEBOUNCECOUNTERUSEDOFMASTERCONFIG                                             
#define CANTSYN_EQ2_TXPDUIDOFMASTERCONFIG                                                           
#define CANTSYN_EQ2_TXPERIODOFMASTERCONFIG                                                          
#define CANTSYN_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                      
#define CANTSYN_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                              
#define CANTSYN_EQ2_DOMAINCONFIGIDXOFSLAVECONFIG                                                    
#define CANTSYN_EQ2_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                    
#define CANTSYN_EQ2_PARTITIONCONFIGIDXOFSLAVECONFIG                                                 
#define CANTSYN_EQ2_RXCRCVALIDATEDOFSLAVECONFIG                                                     
#define CANTSYN_EQ2_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                           
#define CANTSYN_EQ2_SLAVEHANDLEIDOFSLAVECONFIG                                                      
#define CANTSYN_EQ2_SYNCDATAIDLIST                                                                  
#define CANTSYN_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                     
#define CANTSYN_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                  CanTSyn_PartitionIdentifiers
#define CANTSYN_EQ2_CONTROLLERINFOOFPCPARTITIONCONFIG                                               
#define CANTSYN_EQ2_DOMAINCONFIGOFPCPARTITIONCONFIG                                                 
#define CANTSYN_EQ2_FUPDATAIDLISTOFPCPARTITIONCONFIG                                                CanTSyn_FupDataIDList
#define CANTSYN_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                  (&(CanTSyn_Initialized))
#define CANTSYN_EQ2_MASTERCONFIGOFPCPARTITIONCONFIG                                                 
#define CANTSYN_EQ2_MASTERSTATEOFPCPARTITIONCONFIG                                                  CanTSyn_MasterState
#define CANTSYN_EQ2_PDUIDSTATESOFPCPARTITIONCONFIG                                                  
#define CANTSYN_EQ2_SIZEOFCONTROLLERINFOOFPCPARTITIONCONFIG                                         
#define CANTSYN_EQ2_SIZEOFMASTERCONFIGOFPCPARTITIONCONFIG                                           
#define CANTSYN_EQ2_SIZEOFPDUIDSTATESOFPCPARTITIONCONFIG                                            
#define CANTSYN_EQ2_SIZEOFSLAVECONFIGOFPCPARTITIONCONFIG                                            
#define CANTSYN_EQ2_SIZEOFTXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                      
#define CANTSYN_EQ2_SLAVECONFIGOFPCPARTITIONCONFIG                                                  
#define CANTSYN_EQ2_SLAVESTATEOFPCPARTITIONCONFIG                                                   CanTSyn_SlaveState
#define CANTSYN_EQ2_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                               CanTSyn_SyncDataIDList
#define CANTSYN_EQ2_TRANSMISSIONCONTROLLERSTATEOFPCPARTITIONCONFIG                                  
#define CANTSYN_EQ2_TXDEBOUNCECOUNTEROFPCPARTITIONCONFIG                                            
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSymbolicInitializationPointers  CanTSyn Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanTSyn_Config_RDR_01_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_01)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_02_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_03_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_03)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_04_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_04)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_05_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_05)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_06_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_06)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_07_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_07)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
#define CanTSyn_Config_RDR_08_Ptr                                                                   &(CanTSyn_PCConfig.Config_RDR_08)  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCInitializationSymbols  CanTSyn Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanTSyn_Config_RDR_01                                                                       CanTSyn_PCConfig.Config_RDR_01  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_02                                                                       CanTSyn_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_03                                                                       CanTSyn_PCConfig.Config_RDR_03  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_04                                                                       CanTSyn_PCConfig.Config_RDR_04  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_05                                                                       CanTSyn_PCConfig.Config_RDR_05  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_06                                                                       CanTSyn_PCConfig.Config_RDR_06  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_07                                                                       CanTSyn_PCConfig.Config_RDR_07  /**< symbolic identifier which could be used to initialize 'CanTSyn */
#define CanTSyn_Config_RDR_08                                                                       CanTSyn_PCConfig.Config_RDR_08  /**< symbolic identifier which could be used to initialize 'CanTSyn */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGeneral  CanTSyn General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANTSYN_CHECK_INIT_POINTER                                                                  STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANTSYN_FINAL_MAGIC_NUMBER                                                                  0xA11Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanTSyn */
#define CANTSYN_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanTSyn' is not configured to be postbuild capable. */
#define CANTSYN_INIT_DATA                                                                           CANTSYN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANTSYN_INIT_DATA_HASH_CODE                                                                 -1159238718  /**< the precompile constant to validate the initialization structure at initialization time of CanTSyn with a hashcode. The seed value is '0xA11Eu' */
#define CANTSYN_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANTSYN_USE_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer CanTSyn shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCGetRootDataMacros  CanTSyn Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanTSyn_GetPCPartitionConfigOfPCConfig()                                                    CanTSyn_ConfigDataPtr->PCPartitionConfigOfPCConfig
#define CanTSyn_GetControllerInfoOfPCPartitionConfig(partitionIndex)                                CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ControllerInfoOfPCPartitionConfig
#define CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)                                  CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].DomainConfigOfPCPartitionConfig
#define CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)                                  CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MasterConfigOfPCPartitionConfig
#define CanTSyn_GetPduIdStatesOfPCPartitionConfig(partitionIndex)                                   CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduIdStatesOfPCPartitionConfig
#define CanTSyn_GetSizeOfControllerInfoOfPCPartitionConfig(partitionIndex)                          CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfControllerInfoOfPCPartitionConfig
#define CanTSyn_GetSizeOfMasterConfigOfPCPartitionConfig(partitionIndex)                            CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMasterConfigOfPCPartitionConfig
#define CanTSyn_GetSizeOfPduIdStatesOfPCPartitionConfig(partitionIndex)                             CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPduIdStatesOfPCPartitionConfig
#define CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)                             CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSlaveConfigOfPCPartitionConfig
#define CanTSyn_GetSizeOfTxDebounceCounterOfPCPartitionConfig(partitionIndex)                       CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTxDebounceCounterOfPCPartitionConfig
#define CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)                                   CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SlaveConfigOfPCPartitionConfig
#define CanTSyn_GetTransmissionControllerStateOfPCPartitionConfig(partitionIndex)                   CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TransmissionControllerStateOfPCPartitionConfig
#define CanTSyn_GetTxDebounceCounterOfPCPartitionConfig(partitionIndex)                             CanTSyn_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TxDebounceCounterOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetConstantDuplicatedRootDataMacros  CanTSyn Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanTSyn_GetPartitionIdentifiersOfPCConfig()                                                 CanTSyn_PartitionIdentifiers  /**< the pointer to CanTSyn_PartitionIdentifiers */
#define CanTSyn_GetSizeOfPartitionIdentifiersOfPCConfig()                                           1u  /**< the number of accomplishable value elements in CanTSyn_PartitionIdentifiers */
#define CanTSyn_GetFupDataIDListOfPCPartitionConfig(partitionIndex)                                 CanTSyn_FupDataIDList  /**< the pointer to CanTSyn_FupDataIDList */
#define CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex)                                   (&(CanTSyn_Initialized))  /**< the pointer to CanTSyn_Initialized */
#define CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)                                   CanTSyn_MasterState  /**< the pointer to CanTSyn_MasterState */
#define CanTSyn_GetSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in CanTSyn_DomainConfig */
#define CanTSyn_GetSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)                           16u  /**< the number of accomplishable value elements in CanTSyn_FupDataIDList */
#define CanTSyn_GetSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)                          16u  /**< the number of accomplishable value elements in CanTSyn_SyncDataIDList */
#define CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)                                    CanTSyn_SlaveState  /**< the pointer to CanTSyn_SlaveState */
#define CanTSyn_GetSyncDataIDListOfPCPartitionConfig(partitionIndex)                                CanTSyn_SyncDataIDList  /**< the pointer to CanTSyn_SyncDataIDList */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDuplicatedRootDataMacros  CanTSyn Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define CanTSyn_GetSizeOfMasterStateOfPCPartitionConfig(partitionIndex)                             CanTSyn_GetSizeOfMasterConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in CanTSyn_MasterState */
#define CanTSyn_GetSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)                              CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in CanTSyn_SlaveState */
#define CanTSyn_GetSizeOfTransmissionControllerStateOfPCPartitionConfig(partitionIndex)             CanTSyn_GetSizeOfControllerInfoOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in CanTSyn_TransmissionControllerState */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDataMacros  CanTSyn Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanTSyn_GetSnvOfControllerInfo(Index, partitionIndex)                                       (CanTSyn_GetControllerInfoOfPCPartitionConfig(partitionIndex)[(Index)].SnvOfControllerInfo)
#define CanTSyn_GetCrcAndDomainTypeOfDomainConfig(Index, partitionIndex)                            (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].CrcAndDomainTypeOfDomainConfig)
#define CanTSyn_GetDomainIdOfDomainConfig(Index, partitionIndex)                                    (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].DomainIdOfDomainConfig)
#define CanTSyn_GetFupDataIDListEndIdxOfDomainConfig(Index, partitionIndex)                         (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].FupDataIDListEndIdxOfDomainConfig)
#define CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(Index, partitionIndex)                       (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].FupDataIDListStartIdxOfDomainConfig)
#define CanTSyn_GetMasterConfigEndIdxOfDomainConfig(Index, partitionIndex)                          (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].MasterConfigEndIdxOfDomainConfig)
#define CanTSyn_GetMasterConfigLengthOfDomainConfig(Index, partitionIndex)                          (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].MasterConfigLengthOfDomainConfig)
#define CanTSyn_GetMasterConfigStartIdxOfDomainConfig(Index, partitionIndex)                        (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].MasterConfigStartIdxOfDomainConfig)
#define CanTSyn_GetMessageDlcOfDomainConfig(Index, partitionIndex)                                  (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].MessageDlcOfDomainConfig)
#define CanTSyn_GetOffsetDomainOfDomainConfig(Index, partitionIndex)                                (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].OffsetDomainOfDomainConfig)
#define CanTSyn_GetSlaveConfigIdxOfDomainConfig(Index, partitionIndex)                              (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SlaveConfigIdxOfDomainConfig)
#define CanTSyn_GetSyncDataIDListEndIdxOfDomainConfig(Index, partitionIndex)                        (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncDataIDListEndIdxOfDomainConfig)
#define CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(Index, partitionIndex)                      (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncDataIDListStartIdxOfDomainConfig)
#define CanTSyn_GetTimeBaseIdOfDomainConfig(Index, partitionIndex)                                  (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseIdOfDomainConfig)
#define CanTSyn_GetFupDataIDList(Index, partitionIndex)                                             (CanTSyn_GetFupDataIDListOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanTSyn_IsInitialized(partitionIndex)                                                       (((*(CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define CanTSyn_GetControllerInfoIdxOfMasterConfig(Index, partitionIndex)                           (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].ControllerInfoIdxOfMasterConfig)
#define CanTSyn_GetCyclicMsgResumeTimeOfMasterConfig(Index, partitionIndex)                         (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].CyclicMsgResumeTimeOfMasterConfig)
#define CanTSyn_GetDebounceTimeOfMasterConfig(Index, partitionIndex)                                (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].DebounceTimeOfMasterConfig)
#define CanTSyn_GetDomainConfigIdxOfMasterConfig(Index, partitionIndex)                             (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].DomainConfigIdxOfMasterConfig)
#define CanTSyn_GetFupMessageTypeOfMasterConfig(Index, partitionIndex)                              (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].FupMessageTypeOfMasterConfig)
#define CanTSyn_GetImmediateTimeSyncOfMasterConfig(Index, partitionIndex)                           (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateTimeSyncOfMasterConfig)
#define CanTSyn_GetMasterConfHandleIdOfMasterConfig(Index, partitionIndex)                          (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].MasterConfHandleIdOfMasterConfig)
#define CanTSyn_GetMasterConfTimeoutOfMasterConfig(Index, partitionIndex)                           (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].MasterConfTimeoutOfMasterConfig)
#define CanTSyn_GetMessageDomainIdOfMasterConfig(Index, partitionIndex)                             (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].MessageDomainIdOfMasterConfig)
#define CanTSyn_GetPartitionConfigIdxOfMasterConfig(Index, partitionIndex)                          (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].PartitionConfigIdxOfMasterConfig)
#define CanTSyn_GetPduIdStatesIdxOfMasterConfig(Index, partitionIndex)                              (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].PduIdStatesIdxOfMasterConfig)
#define CanTSyn_GetSyncMessageTypeOfMasterConfig(Index, partitionIndex)                             (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncMessageTypeOfMasterConfig)
#define CanTSyn_GetTxCrcSecuredOfMasterConfig(Index, partitionIndex)                                (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].TxCrcSecuredOfMasterConfig)
#define CanTSyn_GetTxDebounceCounterIdxOfMasterConfig(Index, partitionIndex)                        (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].TxDebounceCounterIdxOfMasterConfig)
#define CanTSyn_GetTxPduIdOfMasterConfig(Index, partitionIndex)                                     (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].TxPduIdOfMasterConfig)
#define CanTSyn_GetTxPeriodOfMasterConfig(Index, partitionIndex)                                    (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex)[(Index)].TxPeriodOfMasterConfig)
#define CanTSyn_GetCyclicMsgResumeCounterOfMasterState(Index, partitionIndex)                       (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].CyclicMsgResumeCounterOfMasterState)
#define CanTSyn_GetFupTimeStampOfMasterState(Index, partitionIndex)                                 (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].FupTimeStampOfMasterState)
#define CanTSyn_GetLastUpdateCounterOfMasterState(Index, partitionIndex)                            (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].LastUpdateCounterOfMasterState)
#define CanTSyn_GetStateOfMasterState(Index, partitionIndex)                                        (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfMasterState)
#define CanTSyn_GetSyncTimestampOfMasterState(Index, partitionIndex)                                (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncTimestampOfMasterState)
#define CanTSyn_GetTimeBaseStatusOfMasterState(Index, partitionIndex)                               (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseStatusOfMasterState)
#define CanTSyn_IsTransmitImmediateSyncOfMasterState(Index, partitionIndex)                         ((CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TransmitImmediateSyncOfMasterState) != FALSE)
#define CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(Index, partitionIndex)                 (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxConfirmationTimeoutCounterOfMasterState)
#define CanTSyn_GetTxPeriodCounterOfMasterState(Index, partitionIndex)                              (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxPeriodCounterOfMasterState)
#define CanTSyn_GetTxSequenceCounterOfMasterState(Index, partitionIndex)                            (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxSequenceCounterOfMasterState)
#define CanTSyn_GetUserDataOfMasterState(Index, partitionIndex)                                     (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].UserDataOfMasterState)
#define CanTSyn_GetVirtualLocalTimeOfMasterState(Index, partitionIndex)                             (CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfMasterState)
#define CanTSyn_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                (CanTSyn_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define CanTSyn_GetPartitionSNVOfPartitionIdentifiers(Index)                                        (CanTSyn_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define CanTSyn_GetPduIdStates(Index, partitionIndex)                                               (CanTSyn_GetPduIdStatesOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanTSyn_GetDomainConfigIdxOfSlaveConfig(Index, partitionIndex)                              (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].DomainConfigIdxOfSlaveConfig)
#define CanTSyn_GetFollowUpTimeoutOfSlaveConfig(Index, partitionIndex)                              (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].FollowUpTimeoutOfSlaveConfig)
#define CanTSyn_GetPartitionConfigIdxOfSlaveConfig(Index, partitionIndex)                           (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].PartitionConfigIdxOfSlaveConfig)
#define CanTSyn_GetRxCrcValidatedOfSlaveConfig(Index, partitionIndex)                               (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].RxCrcValidatedOfSlaveConfig)
#define CanTSyn_GetSequenceCounterJumpWidthOfSlaveConfig(Index, partitionIndex)                     (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].SequenceCounterJumpWidthOfSlaveConfig)
#define CanTSyn_GetSlaveHandleIdOfSlaveConfig(Index, partitionIndex)                                (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].SlaveHandleIdOfSlaveConfig)
#define CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxFollowUpTimeoutCountOfSlaveState)
#define CanTSyn_GetRxSequenceCounterOfSlaveState(Index, partitionIndex)                             (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxSequenceCounterOfSlaveState)
#define CanTSyn_GetStateOfSlaveState(Index, partitionIndex)                                         (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSlaveState)
#define CanTSyn_GetVirtualLocalTimeOfSlaveState(Index, partitionIndex)                              (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfSlaveState)
#define CanTSyn_GetSyncDataIDList(Index, partitionIndex)                                            (CanTSyn_GetSyncDataIDListOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanTSyn_GetTransmissionControllerState(Index, partitionIndex)                               (CanTSyn_GetTransmissionControllerStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanTSyn_GetTxDebounceCounter(Index, partitionIndex)                                         (CanTSyn_GetTxDebounceCounterOfPCPartitionConfig(partitionIndex)[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDeduplicatedDataMacros  CanTSyn Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanTSyn_IsFupDataIDListUsedOfDomainConfig(Index, partitionIndex)                            (((boolean)(CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTSyn_FupDataIDList */
#define CanTSyn_IsMasterConfigUsedOfDomainConfig(Index, partitionIndex)                             (((boolean)(CanTSyn_GetMasterConfigLengthOfDomainConfig(((Index)), (partitionIndex)) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTSyn_MasterConfig */
#define CanTSyn_IsSlaveConfigUsedOfDomainConfig(Index, partitionIndex)                              (((boolean)(CanTSyn_GetSlaveConfigIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTSyn_SlaveConfig */
#define CanTSyn_IsSyncDataIDListUsedOfDomainConfig(Index, partitionIndex)                           (((boolean)(CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTSyn_SyncDataIDList */
#define CanTSyn_IsTxDebounceCounterUsedOfMasterConfig(Index, partitionIndex)                        (((boolean)(CanTSyn_GetTxDebounceCounterIdxOfMasterConfig(((Index)), (partitionIndex)) != CANTSYN_NO_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTSyn_TxDebounceCounter */
#define CanTSyn_GetSizeOfControllerInfo(partitionIndex)                                             CanTSyn_GetSizeOfControllerInfoOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfDomainConfig(partitionIndex)                                               CanTSyn_GetSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfFupDataIDList(partitionIndex)                                              CanTSyn_GetSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfMasterConfig(partitionIndex)                                               CanTSyn_GetSizeOfMasterConfigOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfMasterState(partitionIndex)                                                CanTSyn_GetSizeOfMasterStateOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfPartitionIdentifiers()                                                     CanTSyn_GetSizeOfPartitionIdentifiersOfPCConfig()
#define CanTSyn_GetSizeOfPduIdStates(partitionIndex)                                                CanTSyn_GetSizeOfPduIdStatesOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfSlaveConfig(partitionIndex)                                                CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfSlaveState(partitionIndex)                                                 CanTSyn_GetSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfSyncDataIDList(partitionIndex)                                             CanTSyn_GetSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfTransmissionControllerState(partitionIndex)                                CanTSyn_GetSizeOfTransmissionControllerStateOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfTxDebounceCounter(partitionIndex)                                          CanTSyn_GetSizeOfTxDebounceCounterOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSetDataMacros  CanTSyn Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanTSyn_SetInitialized(Value, partitionIndex)                                               (*(CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define CanTSyn_SetCyclicMsgResumeCounterOfMasterState(Index, Value, partitionIndex)                CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].CyclicMsgResumeCounterOfMasterState = (Value)
#define CanTSyn_SetFupTimeStampOfMasterState(Index, Value, partitionIndex)                          CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].FupTimeStampOfMasterState = (Value)
#define CanTSyn_SetLastUpdateCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].LastUpdateCounterOfMasterState = (Value)
#define CanTSyn_SetStateOfMasterState(Index, Value, partitionIndex)                                 CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfMasterState = (Value)
#define CanTSyn_SetSyncTimestampOfMasterState(Index, Value, partitionIndex)                         CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncTimestampOfMasterState = (Value)
#define CanTSyn_SetTimeBaseStatusOfMasterState(Index, Value, partitionIndex)                        CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseStatusOfMasterState = (Value)
#define CanTSyn_SetTransmitImmediateSyncOfMasterState(Index, Value, partitionIndex)                 CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TransmitImmediateSyncOfMasterState = (Value)
#define CanTSyn_SetTxConfirmationTimeoutCounterOfMasterState(Index, Value, partitionIndex)          CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxConfirmationTimeoutCounterOfMasterState = (Value)
#define CanTSyn_SetTxPeriodCounterOfMasterState(Index, Value, partitionIndex)                       CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxPeriodCounterOfMasterState = (Value)
#define CanTSyn_SetTxSequenceCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].TxSequenceCounterOfMasterState = (Value)
#define CanTSyn_SetUserDataOfMasterState(Index, Value, partitionIndex)                              CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].UserDataOfMasterState = (Value)
#define CanTSyn_SetVirtualLocalTimeOfMasterState(Index, Value, partitionIndex)                      CanTSyn_GetMasterStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfMasterState = (Value)
#define CanTSyn_SetPduIdStates(Index, Value, partitionIndex)                                        CanTSyn_GetPduIdStatesOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxFollowUpTimeoutCountOfSlaveState = (Value)
#define CanTSyn_SetRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxSequenceCounterOfSlaveState = (Value)
#define CanTSyn_SetStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSlaveState = (Value)
#define CanTSyn_SetVirtualLocalTimeOfSlaveState(Index, Value, partitionIndex)                       CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfSlaveState = (Value)
#define CanTSyn_SetTransmissionControllerState(Index, Value, partitionIndex)                        CanTSyn_GetTransmissionControllerStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define CanTSyn_SetTxDebounceCounter(Index, Value, partitionIndex)                                  CanTSyn_GetTxDebounceCounterOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetAddressOfDataMacros  CanTSyn Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanTSyn_GetAddrSyncTimestampOfMasterState(Index, partitionIndex)                            (&CanTSyn_GetSyncTimestampOfMasterState(((Index)), (partitionIndex)))
#define CanTSyn_GetAddrSyncMsgOfSlaveState(Index, partitionIndex)                                   (&(CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncMsgOfSlaveState))
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCHasMacros  CanTSyn Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanTSyn_HasControllerInfo(partitionIndex)                                                   (CanTSyn_GetControllerInfoOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasSnvOfControllerInfo(partitionIndex)                                              (TRUE != FALSE)
#define CanTSyn_HasDomainConfig(partitionIndex)                                                     (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasCrcAndDomainTypeOfDomainConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasDomainIdOfDomainConfig(partitionIndex)                                           (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListEndIdxOfDomainConfig(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListStartIdxOfDomainConfig(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListUsedOfDomainConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasMasterConfigEndIdxOfDomainConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasMasterConfigLengthOfDomainConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasMasterConfigStartIdxOfDomainConfig(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasMasterConfigUsedOfDomainConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasMessageDlcOfDomainConfig(partitionIndex)                                         (TRUE != FALSE)
#define CanTSyn_HasOffsetDomainOfDomainConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigIdxOfDomainConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigUsedOfDomainConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListEndIdxOfDomainConfig(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListStartIdxOfDomainConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListUsedOfDomainConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasTimeBaseIdOfDomainConfig(partitionIndex)                                         (TRUE != FALSE)
#define CanTSyn_HasFupDataIDList(partitionIndex)                                                    (TRUE != FALSE)
#define CanTSyn_HasInitialized(partitionIndex)                                                      (TRUE != FALSE)
#define CanTSyn_HasMasterConfig(partitionIndex)                                                     (CanTSyn_GetMasterConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasControllerInfoIdxOfMasterConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasCyclicMsgResumeTimeOfMasterConfig(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasDebounceTimeOfMasterConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasDomainConfigIdxOfMasterConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasFupMessageTypeOfMasterConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasImmediateTimeSyncOfMasterConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasMasterConfHandleIdOfMasterConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasMasterConfTimeoutOfMasterConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasMessageDomainIdOfMasterConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasPartitionConfigIdxOfMasterConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasPduIdStatesIdxOfMasterConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasSyncMessageTypeOfMasterConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasTxCrcSecuredOfMasterConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasTxDebounceCounterIdxOfMasterConfig(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasTxDebounceCounterUsedOfMasterConfig(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasTxPduIdOfMasterConfig(partitionIndex)                                            (TRUE != FALSE)
#define CanTSyn_HasTxPeriodOfMasterConfig(partitionIndex)                                           (TRUE != FALSE)
#define CanTSyn_HasMasterState(partitionIndex)                                                      (TRUE != FALSE)
#define CanTSyn_HasCyclicMsgResumeCounterOfMasterState(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasFupTimeStampOfMasterState(partitionIndex)                                        (TRUE != FALSE)
#define CanTSyn_HasLastUpdateCounterOfMasterState(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasStateOfMasterState(partitionIndex)                                               (TRUE != FALSE)
#define CanTSyn_HasSyncTimestampOfMasterState(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasTimeBaseStatusOfMasterState(partitionIndex)                                      (TRUE != FALSE)
#define CanTSyn_HasTransmitImmediateSyncOfMasterState(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasTxConfirmationTimeoutCounterOfMasterState(partitionIndex)                        (TRUE != FALSE)
#define CanTSyn_HasTxPeriodCounterOfMasterState(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasTxSequenceCounterOfMasterState(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasUserDataOfMasterState(partitionIndex)                                            (TRUE != FALSE)
#define CanTSyn_HasVirtualLocalTimeOfMasterState(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasPartitionIdentifiers()                                                           (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                     (TRUE != FALSE)
#define CanTSyn_HasPartitionSNVOfPartitionIdentifiers()                                             (TRUE != FALSE)
#define CanTSyn_HasPduIdStates(partitionIndex)                                                      (CanTSyn_GetPduIdStatesOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasSizeOfControllerInfo(partitionIndex)                                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfDomainConfig(partitionIndex)                                               (TRUE != FALSE)
#define CanTSyn_HasSizeOfFupDataIDList(partitionIndex)                                              (TRUE != FALSE)
#define CanTSyn_HasSizeOfMasterConfig(partitionIndex)                                               (TRUE != FALSE)
#define CanTSyn_HasSizeOfMasterState(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSizeOfPartitionIdentifiers()                                                     (TRUE != FALSE)
#define CanTSyn_HasSizeOfPduIdStates(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveConfig(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveState(partitionIndex)                                                 (TRUE != FALSE)
#define CanTSyn_HasSizeOfSyncDataIDList(partitionIndex)                                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfTransmissionControllerState(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasSizeOfTxDebounceCounter(partitionIndex)                                          (TRUE != FALSE)
#define CanTSyn_HasSlaveConfig(partitionIndex)                                                      (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasDomainConfigIdxOfSlaveConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasFollowUpTimeoutOfSlaveConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasPartitionConfigIdxOfSlaveConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasRxCrcValidatedOfSlaveConfig(partitionIndex)                                      (TRUE != FALSE)
#define CanTSyn_HasSequenceCounterJumpWidthOfSlaveConfig(partitionIndex)                            (TRUE != FALSE)
#define CanTSyn_HasSlaveHandleIdOfSlaveConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasSlaveState(partitionIndex)                                                       (TRUE != FALSE)
#define CanTSyn_HasRxFollowUpTimeoutCountOfSlaveState(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasRxSequenceCounterOfSlaveState(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasStateOfSlaveState(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSyncMsgOfSlaveState(partitionIndex)                                              (TRUE != FALSE)
#define CanTSyn_HasVirtualLocalTimeOfSlaveState(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDList(partitionIndex)                                                   (TRUE != FALSE)
#define CanTSyn_HasTransmissionControllerState(partitionIndex)                                      (CanTSyn_GetTransmissionControllerStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasTxDebounceCounter(partitionIndex)                                                (CanTSyn_GetTxDebounceCounterOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define CanTSyn_HasPCConfig()                                                                       (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanTSyn_HasPartitionIdentifiersOfPCConfig()                                                 (TRUE != FALSE)
#define CanTSyn_HasSizeOfPartitionIdentifiersOfPCConfig()                                           (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfig()                                                              (CanTSyn_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define CanTSyn_HasControllerInfoOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasDomainConfigOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasInitializedOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasMasterConfigOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasMasterStateOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasPduIdStatesOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasSizeOfControllerInfoOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define CanTSyn_HasSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define CanTSyn_HasSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define CanTSyn_HasSizeOfMasterConfigOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define CanTSyn_HasSizeOfMasterStateOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfPduIdStatesOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define CanTSyn_HasSizeOfTransmissionControllerStateOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define CanTSyn_HasSizeOfTxDebounceCounterOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasSlaveStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasTransmissionControllerStateOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define CanTSyn_HasTxDebounceCounterOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIncrementDataMacros  CanTSyn Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_IncCyclicMsgResumeCounterOfMasterState(Index, partitionIndex)                       CanTSyn_GetCyclicMsgResumeCounterOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncLastUpdateCounterOfMasterState(Index, partitionIndex)                            CanTSyn_GetLastUpdateCounterOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncStateOfMasterState(Index, partitionIndex)                                        CanTSyn_GetStateOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncTxConfirmationTimeoutCounterOfMasterState(Index, partitionIndex)                 CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncTxPeriodCounterOfMasterState(Index, partitionIndex)                              CanTSyn_GetTxPeriodCounterOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncTxSequenceCounterOfMasterState(Index, partitionIndex)                            CanTSyn_GetTxSequenceCounterOfMasterState(((Index)), (partitionIndex))++
#define CanTSyn_IncPduIdStates(Index, partitionIndex)                                               CanTSyn_GetPduIdStates(((Index)), (partitionIndex))++
#define CanTSyn_IncRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex))++
#define CanTSyn_IncRxSequenceCounterOfSlaveState(Index, partitionIndex)                             CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex))++
#define CanTSyn_IncStateOfSlaveState(Index, partitionIndex)                                         CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex))++
#define CanTSyn_IncTransmissionControllerState(Index, partitionIndex)                               CanTSyn_GetTransmissionControllerState(((Index)), (partitionIndex))++
#define CanTSyn_IncTxDebounceCounter(Index, partitionIndex)                                         CanTSyn_GetTxDebounceCounter(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCDecrementDataMacros  CanTSyn Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_DecCyclicMsgResumeCounterOfMasterState(Index, partitionIndex)                       CanTSyn_GetCyclicMsgResumeCounterOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecLastUpdateCounterOfMasterState(Index, partitionIndex)                            CanTSyn_GetLastUpdateCounterOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecStateOfMasterState(Index, partitionIndex)                                        CanTSyn_GetStateOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecTxConfirmationTimeoutCounterOfMasterState(Index, partitionIndex)                 CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecTxPeriodCounterOfMasterState(Index, partitionIndex)                              CanTSyn_GetTxPeriodCounterOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecTxSequenceCounterOfMasterState(Index, partitionIndex)                            CanTSyn_GetTxSequenceCounterOfMasterState(((Index)), (partitionIndex))--
#define CanTSyn_DecPduIdStates(Index, partitionIndex)                                               CanTSyn_GetPduIdStates(((Index)), (partitionIndex))--
#define CanTSyn_DecRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex))--
#define CanTSyn_DecRxSequenceCounterOfSlaveState(Index, partitionIndex)                             CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex))--
#define CanTSyn_DecStateOfSlaveState(Index, partitionIndex)                                         CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex))--
#define CanTSyn_DecTransmissionControllerState(Index, partitionIndex)                               CanTSyn_GetTransmissionControllerState(((Index)), (partitionIndex))--
#define CanTSyn_DecTxDebounceCounter(Index, partitionIndex)                                         CanTSyn_GetTxDebounceCounter(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCAddDataMacros  CanTSyn Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_AddCyclicMsgResumeCounterOfMasterState(Index, Value, partitionIndex)                CanTSyn_SetCyclicMsgResumeCounterOfMasterState(Index, (CanTSyn_GetCyclicMsgResumeCounterOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddLastUpdateCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_SetLastUpdateCounterOfMasterState(Index, (CanTSyn_GetLastUpdateCounterOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddStateOfMasterState(Index, Value, partitionIndex)                                 CanTSyn_SetStateOfMasterState(Index, (CanTSyn_GetStateOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddTxConfirmationTimeoutCounterOfMasterState(Index, Value, partitionIndex)          CanTSyn_SetTxConfirmationTimeoutCounterOfMasterState(Index, (CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddTxPeriodCounterOfMasterState(Index, Value, partitionIndex)                       CanTSyn_SetTxPeriodCounterOfMasterState(Index, (CanTSyn_GetTxPeriodCounterOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddTxSequenceCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_SetTxSequenceCounterOfMasterState(Index, (CanTSyn_GetTxSequenceCounterOfMasterState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddPduIdStates(Index, Value, partitionIndex)                                        CanTSyn_SetPduIdStates(Index, (CanTSyn_GetPduIdStates(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_SetRxSequenceCounterOfSlaveState(Index, (CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_SetStateOfSlaveState(Index, (CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddTransmissionControllerState(Index, Value, partitionIndex)                        CanTSyn_SetTransmissionControllerState(Index, (CanTSyn_GetTransmissionControllerState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddTxDebounceCounter(Index, Value, partitionIndex)                                  CanTSyn_SetTxDebounceCounter(Index, (CanTSyn_GetTxDebounceCounter(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSubstractDataMacros  CanTSyn Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_SubCyclicMsgResumeCounterOfMasterState(Index, Value, partitionIndex)                CanTSyn_SetCyclicMsgResumeCounterOfMasterState(Index, (CanTSyn_GetCyclicMsgResumeCounterOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubLastUpdateCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_SetLastUpdateCounterOfMasterState(Index, (CanTSyn_GetLastUpdateCounterOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubStateOfMasterState(Index, Value, partitionIndex)                                 CanTSyn_SetStateOfMasterState(Index, (CanTSyn_GetStateOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubTxConfirmationTimeoutCounterOfMasterState(Index, Value, partitionIndex)          CanTSyn_SetTxConfirmationTimeoutCounterOfMasterState(Index, (CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubTxPeriodCounterOfMasterState(Index, Value, partitionIndex)                       CanTSyn_SetTxPeriodCounterOfMasterState(Index, (CanTSyn_GetTxPeriodCounterOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubTxSequenceCounterOfMasterState(Index, Value, partitionIndex)                     CanTSyn_SetTxSequenceCounterOfMasterState(Index, (CanTSyn_GetTxSequenceCounterOfMasterState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubPduIdStates(Index, Value, partitionIndex)                                        CanTSyn_SetPduIdStates(Index, (CanTSyn_GetPduIdStates(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_SetRxSequenceCounterOfSlaveState(Index, (CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_SetStateOfSlaveState(Index, (CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubTransmissionControllerState(Index, Value, partitionIndex)                        CanTSyn_SetTransmissionControllerState(Index, (CanTSyn_GetTransmissionControllerState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubTxDebounceCounter(Index, Value, partitionIndex)                                  CanTSyn_SetTxDebounceCounter(Index, (CanTSyn_GetTxDebounceCounter(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 


/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 CanTSyn_CanMsgType[CANTSYN_TIME_SYNC_MAX_MESSAGE_DLC];
typedef uint8 CanTSyn_CanStdMsgType[CANTSYN_TIME_SYNC_MESSAGE_DLC];

/* CANTSYN State-Machine State Definitions */
typedef uint8 CanTSyn_StateMachineStateType;
# define CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC                    (0u)
# define CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP               (1u)

# define CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND                  (2u)
# define CANTSYN_STATE_SEND_WAITING_FOR_SYNC_TX_CONFIRMATION       (3u)
# define CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND             (4u)
# define CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_TX_CONFIRMATION  (5u)


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCSizeOfTypes  CanTSyn SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for CanTSyn_SizeOfControllerInfo */
typedef uint8 CanTSyn_SizeOfControllerInfoType;

/**   \brief  value based type definition for CanTSyn_SizeOfDomainConfig */
typedef uint8 CanTSyn_SizeOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SizeOfFupDataIDList */
typedef uint8 CanTSyn_SizeOfFupDataIDListType;

/**   \brief  value based type definition for CanTSyn_SizeOfMasterConfig */
typedef uint8 CanTSyn_SizeOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_SizeOfMasterState */
typedef uint8 CanTSyn_SizeOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_SizeOfPartitionIdentifiers */
typedef uint8 CanTSyn_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_SizeOfPduIdStates */
typedef uint8 CanTSyn_SizeOfPduIdStatesType;

/**   \brief  value based type definition for CanTSyn_SizeOfSlaveConfig */
typedef uint8 CanTSyn_SizeOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SizeOfSlaveState */
typedef uint8 CanTSyn_SizeOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_SizeOfSyncDataIDList */
typedef uint8 CanTSyn_SizeOfSyncDataIDListType;

/**   \brief  value based type definition for CanTSyn_SizeOfTransmissionControllerState */
typedef uint8 CanTSyn_SizeOfTransmissionControllerStateType;

/**   \brief  value based type definition for CanTSyn_SizeOfTxDebounceCounter */
typedef uint8 CanTSyn_SizeOfTxDebounceCounterType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCIterableTypes  CanTSyn Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanTSyn_ControllerInfo */
typedef uint8_least CanTSyn_ControllerInfoIterType;

/**   \brief  type used to iterate CanTSyn_DomainConfig */
typedef uint8_least CanTSyn_DomainConfigIterType;

/**   \brief  type used to iterate CanTSyn_FupDataIDList */
typedef uint8_least CanTSyn_FupDataIDListIterType;

/**   \brief  type used to iterate CanTSyn_MasterConfig */
typedef uint8_least CanTSyn_MasterConfigIterType;

/**   \brief  type used to iterate CanTSyn_PartitionIdentifiers */
typedef uint8_least CanTSyn_PartitionIdentifiersIterType;

/**   \brief  type used to iterate CanTSyn_PduIdStates */
typedef uint8_least CanTSyn_PduIdStatesIterType;

/**   \brief  type used to iterate CanTSyn_SlaveConfig */
typedef uint8_least CanTSyn_SlaveConfigIterType;

/**   \brief  type used to iterate CanTSyn_SyncDataIDList */
typedef uint8_least CanTSyn_SyncDataIDListIterType;

/**   \brief  type used to iterate CanTSyn_TxDebounceCounter */
typedef uint8_least CanTSyn_TxDebounceCounterIterType;

/**   \brief  type used to iterate CanTSyn_PCPartitionConfig */
typedef uint8_least CanTSyn_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIterableTypesWithSizeRelations  CanTSyn Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate CanTSyn_MasterState */
typedef CanTSyn_MasterConfigIterType CanTSyn_MasterStateIterType;

/**   \brief  type used to iterate CanTSyn_SlaveState */
typedef CanTSyn_SlaveConfigIterType CanTSyn_SlaveStateIterType;

/**   \brief  type used to iterate CanTSyn_TransmissionControllerState */
typedef CanTSyn_ControllerInfoIterType CanTSyn_TransmissionControllerStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCValueTypes  CanTSyn Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanTSyn_SnvOfControllerInfo */
typedef uint8 CanTSyn_SnvOfControllerInfoType;

/**   \brief  value based type definition for CanTSyn_CrcAndDomainTypeOfDomainConfig */
typedef uint8 CanTSyn_CrcAndDomainTypeOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_DomainIdOfDomainConfig */
typedef uint8 CanTSyn_DomainIdOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListEndIdxOfDomainConfig */
typedef uint8 CanTSyn_FupDataIDListEndIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListStartIdxOfDomainConfig */
typedef uint8 CanTSyn_FupDataIDListStartIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListUsedOfDomainConfig */
typedef boolean CanTSyn_FupDataIDListUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfigEndIdxOfDomainConfig */
typedef uint8 CanTSyn_MasterConfigEndIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfigLengthOfDomainConfig */
typedef uint8 CanTSyn_MasterConfigLengthOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfigStartIdxOfDomainConfig */
typedef uint8 CanTSyn_MasterConfigStartIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfigUsedOfDomainConfig */
typedef boolean CanTSyn_MasterConfigUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MessageDlcOfDomainConfig */
typedef uint8 CanTSyn_MessageDlcOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_OffsetDomainOfDomainConfig */
typedef uint8 CanTSyn_OffsetDomainOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveConfigIdxOfDomainConfig */
typedef uint8 CanTSyn_SlaveConfigIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveConfigUsedOfDomainConfig */
typedef boolean CanTSyn_SlaveConfigUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListEndIdxOfDomainConfig */
typedef uint8 CanTSyn_SyncDataIDListEndIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListStartIdxOfDomainConfig */
typedef uint8 CanTSyn_SyncDataIDListStartIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListUsedOfDomainConfig */
typedef boolean CanTSyn_SyncDataIDListUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDList */
typedef uint8 CanTSyn_FupDataIDListType;

/**   \brief  value based type definition for CanTSyn_Initialized */
typedef boolean CanTSyn_InitializedType;

/**   \brief  value based type definition for CanTSyn_ControllerInfoIdxOfMasterConfig */
typedef uint8 CanTSyn_ControllerInfoIdxOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_CyclicMsgResumeTimeOfMasterConfig */
typedef uint8 CanTSyn_CyclicMsgResumeTimeOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_DebounceTimeOfMasterConfig */
typedef uint8 CanTSyn_DebounceTimeOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_DomainConfigIdxOfMasterConfig */
typedef uint8 CanTSyn_DomainConfigIdxOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_FupMessageTypeOfMasterConfig */
typedef uint8 CanTSyn_FupMessageTypeOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_ImmediateTimeSyncOfMasterConfig */
typedef uint8 CanTSyn_ImmediateTimeSyncOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfHandleIdOfMasterConfig */
typedef uint8 CanTSyn_MasterConfHandleIdOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_MasterConfTimeoutOfMasterConfig */
typedef uint8 CanTSyn_MasterConfTimeoutOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_MessageDomainIdOfMasterConfig */
typedef uint8 CanTSyn_MessageDomainIdOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_PartitionConfigIdxOfMasterConfig */
typedef uint8 CanTSyn_PartitionConfigIdxOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_PduIdStatesIdxOfMasterConfig */
typedef uint8 CanTSyn_PduIdStatesIdxOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_SyncMessageTypeOfMasterConfig */
typedef uint8 CanTSyn_SyncMessageTypeOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_TxCrcSecuredOfMasterConfig */
typedef uint8 CanTSyn_TxCrcSecuredOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_TxDebounceCounterIdxOfMasterConfig */
typedef uint8 CanTSyn_TxDebounceCounterIdxOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_TxDebounceCounterUsedOfMasterConfig */
typedef boolean CanTSyn_TxDebounceCounterUsedOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_TxPduIdOfMasterConfig */
typedef uint8 CanTSyn_TxPduIdOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_TxPeriodOfMasterConfig */
typedef uint8 CanTSyn_TxPeriodOfMasterConfigType;

/**   \brief  value based type definition for CanTSyn_CyclicMsgResumeCounterOfMasterState */
typedef uint32 CanTSyn_CyclicMsgResumeCounterOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_LastUpdateCounterOfMasterState */
typedef uint8 CanTSyn_LastUpdateCounterOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_TransmitImmediateSyncOfMasterState */
typedef boolean CanTSyn_TransmitImmediateSyncOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_TxConfirmationTimeoutCounterOfMasterState */
typedef uint32 CanTSyn_TxConfirmationTimeoutCounterOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_TxPeriodCounterOfMasterState */
typedef uint32 CanTSyn_TxPeriodCounterOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_TxSequenceCounterOfMasterState */
typedef uint8 CanTSyn_TxSequenceCounterOfMasterStateType;

/**   \brief  value based type definition for CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_PartitionSNVOfPartitionIdentifiers */
typedef uint32 CanTSyn_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_PduIdStates */
typedef uint8 CanTSyn_PduIdStatesType;

/**   \brief  value based type definition for CanTSyn_DomainConfigIdxOfSlaveConfig */
typedef uint8 CanTSyn_DomainConfigIdxOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_FollowUpTimeoutOfSlaveConfig */
typedef uint8 CanTSyn_FollowUpTimeoutOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_PartitionConfigIdxOfSlaveConfig */
typedef uint8 CanTSyn_PartitionConfigIdxOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_RxCrcValidatedOfSlaveConfig */
typedef uint8 CanTSyn_RxCrcValidatedOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SequenceCounterJumpWidthOfSlaveConfig */
typedef uint8 CanTSyn_SequenceCounterJumpWidthOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveHandleIdOfSlaveConfig */
typedef uint8 CanTSyn_SlaveHandleIdOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_RxFollowUpTimeoutCountOfSlaveState */
typedef uint32 CanTSyn_RxFollowUpTimeoutCountOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_RxSequenceCounterOfSlaveState */
typedef uint8 CanTSyn_RxSequenceCounterOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDList */
typedef uint8 CanTSyn_SyncDataIDListType;

/**   \brief  value based type definition for CanTSyn_TxDebounceCounter */
typedef uint8 CanTSyn_TxDebounceCounterType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCStructTypes  CanTSyn Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanTSyn_ControllerInfo */
typedef struct sCanTSyn_ControllerInfoType
{
  CanTSyn_SnvOfControllerInfoType SnvOfControllerInfo;  /**< Symbolic Name Value of the referenced controller */
} CanTSyn_ControllerInfoType;

/**   \brief  type used in CanTSyn_DomainConfig */
typedef struct sCanTSyn_DomainConfigType
{
  CanTSyn_CrcAndDomainTypeOfDomainConfigType CrcAndDomainTypeOfDomainConfig;  /**< Indicates if this domain supports crc if it contains a master that supports txCrc. */
  CanTSyn_DomainIdOfDomainConfigType DomainIdOfDomainConfig;  /**< Domain Id */
  CanTSyn_FupDataIDListEndIdxOfDomainConfigType FupDataIDListEndIdxOfDomainConfig;  /**< the end index of the 0:n relation pointing to CanTSyn_FupDataIDList */
  CanTSyn_FupDataIDListStartIdxOfDomainConfigType FupDataIDListStartIdxOfDomainConfig;  /**< the start index of the 0:n relation pointing to CanTSyn_FupDataIDList */
  CanTSyn_MasterConfigEndIdxOfDomainConfigType MasterConfigEndIdxOfDomainConfig;  /**< the end index of the 0:n relation pointing to CanTSyn_MasterConfig */
  CanTSyn_MasterConfigLengthOfDomainConfigType MasterConfigLengthOfDomainConfig;  /**< the number of relations pointing to CanTSyn_MasterConfig */
  CanTSyn_MasterConfigStartIdxOfDomainConfigType MasterConfigStartIdxOfDomainConfig;  /**< the start index of the 0:n relation pointing to CanTSyn_MasterConfig */
  CanTSyn_MessageDlcOfDomainConfigType MessageDlcOfDomainConfig;  /**< Indicates if the Extended Message Format for CAN-FD is used. */
  CanTSyn_OffsetDomainOfDomainConfigType OffsetDomainOfDomainConfig;  /**< Indicates if this domain sends offset messages. */
  CanTSyn_SlaveConfigIdxOfDomainConfigType SlaveConfigIdxOfDomainConfig;  /**< the index of the 0:1 relation pointing to CanTSyn_SlaveConfig */
  CanTSyn_SyncDataIDListEndIdxOfDomainConfigType SyncDataIDListEndIdxOfDomainConfig;  /**< the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList */
  CanTSyn_SyncDataIDListStartIdxOfDomainConfigType SyncDataIDListStartIdxOfDomainConfig;  /**< the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList */
  StbM_SynchronizedTimeBaseType TimeBaseIdOfDomainConfig;  /**< Mandatory reference to the required synchronized time-base. */
} CanTSyn_DomainConfigType;

/**   \brief  type used in CanTSyn_MasterConfig */
typedef struct sCanTSyn_MasterConfigType
{
  CanTSyn_ControllerInfoIdxOfMasterConfigType ControllerInfoIdxOfMasterConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_ControllerInfo */
  CanTSyn_CyclicMsgResumeTimeOfMasterConfigType CyclicMsgResumeTimeOfMasterConfig;  /**< Defines the time where the 1st regular cycle time based message transmission takes place, after an immediate transmission before. */
  CanTSyn_DebounceTimeOfMasterConfigType DebounceTimeOfMasterConfig;  /**< This represents the configuration of a Tx debounce time for SYNC, FUP, OFS and OFNS messages compared to a message before with the same PDU. */
  CanTSyn_DomainConfigIdxOfMasterConfigType DomainConfigIdxOfMasterConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_DomainConfig */
  CanTSyn_FupMessageTypeOfMasterConfigType FupMessageTypeOfMasterConfig;  /**< This provides information about whether or not the FUP/OFNS message is CRC secured. */
  CanTSyn_ImmediateTimeSyncOfMasterConfigType ImmediateTimeSyncOfMasterConfig;  /**< Enables/Disables the cyclic polling of StbM_GetTimeBaseUpdateCounter() within CanTSyn_MainFunction(). */
  CanTSyn_MasterConfHandleIdOfMasterConfigType MasterConfHandleIdOfMasterConfig;  /**< This represents the handle ID of the PDU that contains the global time information. */
  CanTSyn_MasterConfTimeoutOfMasterConfigType MasterConfTimeoutOfMasterConfig;  /**< This represents the confirmation timeout after transmission of a message. */
  CanTSyn_MessageDomainIdOfMasterConfigType MessageDomainIdOfMasterConfig;  /**< This contains the domain ID to which the message belongs. */
  CanTSyn_PartitionConfigIdxOfMasterConfigType PartitionConfigIdxOfMasterConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig */
  CanTSyn_PduIdStatesIdxOfMasterConfigType PduIdStatesIdxOfMasterConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_PduIdStates */
  CanTSyn_SyncMessageTypeOfMasterConfigType SyncMessageTypeOfMasterConfig;  /**< This provides information about whether or not the SYNC/OFS message is CRC secured. */
  CanTSyn_TxCrcSecuredOfMasterConfigType TxCrcSecuredOfMasterConfig;  /**< CRC is supported or not. */
  CanTSyn_TxDebounceCounterIdxOfMasterConfigType TxDebounceCounterIdxOfMasterConfig;  /**< the index of the 0:1 relation pointing to CanTSyn_TxDebounceCounter */
  CanTSyn_TxPduIdOfMasterConfigType TxPduIdOfMasterConfig;  /**< This represents the ID of the Pdu taken to transmit the global time information. */
  CanTSyn_TxPeriodOfMasterConfigType TxPeriodOfMasterConfig;  /**< This represents configuration of the Tx period. */
} CanTSyn_MasterConfigType;

/**   \brief  type used in CanTSyn_MasterState */
typedef struct sCanTSyn_MasterStateType
{
  CanTSyn_CyclicMsgResumeCounterOfMasterStateType CyclicMsgResumeCounterOfMasterState;  /**< Count of number of cyclic time bases transmissions. */
  CanTSyn_TxConfirmationTimeoutCounterOfMasterStateType TxConfirmationTimeoutCounterOfMasterState;  /**< Count of confirmation timeout after each transmission. */
  CanTSyn_TxPeriodCounterOfMasterStateType TxPeriodCounterOfMasterState;  /**< Counter for TxPeriod. */
  CanTSyn_LastUpdateCounterOfMasterStateType LastUpdateCounterOfMasterState;  /**< The value of the time base update counter that is retrieved from StbM can be stored in here in order to compare it to the next current update counter. */
  CanTSyn_TransmitImmediateSyncOfMasterStateType TransmitImmediateSyncOfMasterState;  /**< True if next Sync message is sent in immediate mode. */
  CanTSyn_TxSequenceCounterOfMasterStateType TxSequenceCounterOfMasterState;  /**< Sequence counter for Tx messages. */
  StbM_TimeStampType FupTimeStampOfMasterState;  /**< This represents the time stamp of follow up message from StbM. */
  CanTSyn_StateMachineStateType StateOfMasterState;  /**< State of the master. */
  StbM_TimeStampType SyncTimestampOfMasterState;  /**< This represents the synchronized time stamp from StbM. */
  StbM_TimeBaseStatusType TimeBaseStatusOfMasterState;  /**< This represents the time base status value from StbM. */
  StbM_UserDataType UserDataOfMasterState;  /**< This represents the user data retrieved from StbM. */
  StbM_VirtualLocalTimeType VirtualLocalTimeOfMasterState;  /**< This represents Virtual Local Time value from StbM. */
} CanTSyn_MasterStateType;

/**   \brief  type used in CanTSyn_PartitionIdentifiers */
typedef struct sCanTSyn_PartitionIdentifiersType
{
  CanTSyn_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig */
} CanTSyn_PartitionIdentifiersType;

/**   \brief  type used in CanTSyn_SlaveConfig */
typedef struct sCanTSyn_SlaveConfigType
{
  CanTSyn_DomainConfigIdxOfSlaveConfigType DomainConfigIdxOfSlaveConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_DomainConfig */
  CanTSyn_FollowUpTimeoutOfSlaveConfigType FollowUpTimeoutOfSlaveConfig;  /**< Rx timeout for the follow-up message. This is only relevant for selected bus systems. */
  CanTSyn_PartitionConfigIdxOfSlaveConfigType PartitionConfigIdxOfSlaveConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig */
  CanTSyn_RxCrcValidatedOfSlaveConfigType RxCrcValidatedOfSlaveConfig;  /**< Validation of the CRC is supported or not */
  CanTSyn_SequenceCounterJumpWidthOfSlaveConfigType SequenceCounterJumpWidthOfSlaveConfig;  /**< The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages. */
  CanTSyn_SlaveHandleIdOfSlaveConfigType SlaveHandleIdOfSlaveConfig;  /**< This represents the handle ID of the PDU that contains the global time information. */
} CanTSyn_SlaveConfigType;

/**   \brief  type used in CanTSyn_SlaveState */
typedef struct sCanTSyn_SlaveStateType
{
  CanTSyn_RxFollowUpTimeoutCountOfSlaveStateType RxFollowUpTimeoutCountOfSlaveState;  /**< Count of number of Rx timeouts for follow-up messages. */
  CanTSyn_RxSequenceCounterOfSlaveStateType RxSequenceCounterOfSlaveState;  /**< Sequence counter for Rx messages. */
  CanTSyn_StateMachineStateType StateOfSlaveState;  /**< State of the slave */
  CanTSyn_CanStdMsgType SyncMsgOfSlaveState;  /**< This represents the synchronized message type. */
  StbM_VirtualLocalTimeType VirtualLocalTimeOfSlaveState;  /**< This represents Virtual Local Time value from StbM. */
} CanTSyn_SlaveStateType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCRootPointerTypes  CanTSyn Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanTSyn_ControllerInfo */
typedef P2CONST(CanTSyn_ControllerInfoType, TYPEDEF, CANTSYN_CONST) CanTSyn_ControllerInfoPtrType;

/**   \brief  type used to point to CanTSyn_DomainConfig */
typedef P2CONST(CanTSyn_DomainConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_DomainConfigPtrType;

/**   \brief  type used to point to CanTSyn_FupDataIDList */
typedef P2CONST(CanTSyn_FupDataIDListType, TYPEDEF, CANTSYN_CONST) CanTSyn_FupDataIDListPtrType;

/**   \brief  type used to point to CanTSyn_Initialized */
typedef P2VAR(CanTSyn_InitializedType, TYPEDEF, CANTSYN_VAR_CLEARED) CanTSyn_InitializedPtrType;

/**   \brief  type used to point to CanTSyn_MasterConfig */
typedef P2CONST(CanTSyn_MasterConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_MasterConfigPtrType;

/**   \brief  type used to point to CanTSyn_MasterState */
typedef P2VAR(CanTSyn_MasterStateType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_MasterStatePtrType;

/**   \brief  type used to point to CanTSyn_SyncTimestampOfMasterState */
typedef P2VAR(StbM_TimeStampType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_SyncTimestampOfMasterStatePtrType;

/**   \brief  type used to point to CanTSyn_PartitionIdentifiers */
typedef P2CONST(CanTSyn_PartitionIdentifiersType, TYPEDEF, CANTSYN_CONST) CanTSyn_PartitionIdentifiersPtrType;

/**   \brief  type used to point to CanTSyn_PduIdStates */
typedef P2VAR(CanTSyn_PduIdStatesType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_PduIdStatesPtrType;

/**   \brief  type used to point to CanTSyn_SlaveConfig */
typedef P2CONST(CanTSyn_SlaveConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_SlaveConfigPtrType;

/**   \brief  type used to point to CanTSyn_SlaveState */
typedef P2VAR(CanTSyn_SlaveStateType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveStatePtrType;

/**   \brief  type used to point to CanTSyn_SyncMsgOfSlaveState */
typedef P2VAR(CanTSyn_CanStdMsgType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_SyncMsgOfSlaveStatePtrType;

/**   \brief  type used to point to CanTSyn_SyncDataIDList */
typedef P2CONST(CanTSyn_SyncDataIDListType, TYPEDEF, CANTSYN_CONST) CanTSyn_SyncDataIDListPtrType;

/**   \brief  type used to point to CanTSyn_TransmissionControllerState */
typedef P2VAR(CanTSyn_TransmissionModeType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_TransmissionControllerStatePtrType;

/**   \brief  type used to point to CanTSyn_TxDebounceCounter */
typedef P2VAR(CanTSyn_TxDebounceCounterType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_TxDebounceCounterPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCPartitionRootPointer  CanTSyn Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in CanTSyn_PCPartitionConfig */
typedef struct sCanTSyn_PCPartitionConfigType
{
  CanTSyn_ControllerInfoPtrType ControllerInfoOfPCPartitionConfig;  /**< the pointer to CanTSyn_ControllerInfo */
  CanTSyn_DomainConfigPtrType DomainConfigOfPCPartitionConfig;  /**< the pointer to CanTSyn_DomainConfig */
  CanTSyn_MasterConfigPtrType MasterConfigOfPCPartitionConfig;  /**< the pointer to CanTSyn_MasterConfig */
  CanTSyn_PduIdStatesPtrType PduIdStatesOfPCPartitionConfig;  /**< the pointer to CanTSyn_PduIdStates */
  CanTSyn_SlaveConfigPtrType SlaveConfigOfPCPartitionConfig;  /**< the pointer to CanTSyn_SlaveConfig */
  CanTSyn_TransmissionControllerStatePtrType TransmissionControllerStateOfPCPartitionConfig;  /**< the pointer to CanTSyn_TransmissionControllerState */
  CanTSyn_TxDebounceCounterPtrType TxDebounceCounterOfPCPartitionConfig;  /**< the pointer to CanTSyn_TxDebounceCounter */
  CanTSyn_SizeOfControllerInfoType SizeOfControllerInfoOfPCPartitionConfig;  /**< the number of accomplishable value elements in CanTSyn_ControllerInfo */
  CanTSyn_SizeOfMasterConfigType SizeOfMasterConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in CanTSyn_MasterConfig */
  CanTSyn_SizeOfPduIdStatesType SizeOfPduIdStatesOfPCPartitionConfig;  /**< the number of accomplishable value elements in CanTSyn_PduIdStates */
  CanTSyn_SizeOfSlaveConfigType SizeOfSlaveConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in CanTSyn_SlaveConfig */
  CanTSyn_SizeOfTxDebounceCounterType SizeOfTxDebounceCounterOfPCPartitionConfig;  /**< the number of accomplishable value elements in CanTSyn_TxDebounceCounter */
} CanTSyn_PCPartitionConfigType;

/**   \brief  type used to point to CanTSyn_PCPartitionConfig */
typedef P2CONST(CanTSyn_PCPartitionConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCRootValueTypes  CanTSyn Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanTSyn_PCConfig */
typedef struct sCanTSyn_PCConfigType
{
  CanTSyn_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to CanTSyn_PCPartitionConfig */
} CanTSyn_PCConfigType;

typedef CanTSyn_PCConfigType CanTSyn_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanTSyn_PCConfig in a symbol based style. */
typedef struct sCanTSyn_PCConfigsType
{
  CanTSyn_PCConfigType Config_RDR_01;  /**< [Config_RDR_01] */
  CanTSyn_PCConfigType Config_RDR_02;  /**< [Config_RDR_02] */
  CanTSyn_PCConfigType Config_RDR_03;  /**< [Config_RDR_03] */
  CanTSyn_PCConfigType Config_RDR_04;  /**< [Config_RDR_04] */
  CanTSyn_PCConfigType Config_RDR_05;  /**< [Config_RDR_05] */
  CanTSyn_PCConfigType Config_RDR_06;  /**< [Config_RDR_06] */
  CanTSyn_PCConfigType Config_RDR_07;  /**< [Config_RDR_07] */
  CanTSyn_PCConfigType Config_RDR_08;  /**< [Config_RDR_08] */
} CanTSyn_PCConfigsType;

/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, CANTSYN_VAR_NO_INIT) CanTSyn_PreInitialized;

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTSyn_ControllerInfo
**********************************************************************************************************************/
/** 
  \var    CanTSyn_ControllerInfo
  \brief  Referenced controller info.
  \details
  Element    Description
  Snv        Symbolic Name Value of the referenced controller
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_ControllerInfoType, CANTSYN_CONST) CanTSyn_ControllerInfo[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_DomainConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfigRDR_01
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Indicates if this domain supports crc if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MasterConfigEndIdx        the end index of the 0:n relation pointing to CanTSyn_MasterConfig
  MasterConfigLength        the number of relations pointing to CanTSyn_MasterConfig
  MasterConfigStartIdx      the start index of the 0:n relation pointing to CanTSyn_MasterConfig
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Indicates if this domain sends offset messages.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfigRDR_01[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_DomainConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfigRDR_05
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Indicates if this domain supports crc if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MasterConfigEndIdx        the end index of the 0:n relation pointing to CanTSyn_MasterConfig
  MasterConfigLength        the number of relations pointing to CanTSyn_MasterConfig
  MasterConfigStartIdx      the start index of the 0:n relation pointing to CanTSyn_MasterConfig
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Indicates if this domain sends offset messages.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfigRDR_05[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_FupDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_FupDataIDList
  \brief  Element of the DataIDList for FUP/OFNS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_FupDataIDListType, CANTSYN_CONST) CanTSyn_FupDataIDList[16];
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_MasterConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_MasterConfig
  \brief  Contains configuration parameters of masters.
  \details
  Element                 Description
  ControllerInfoIdx       the index of the 1:1 relation pointing to CanTSyn_ControllerInfo
  CyclicMsgResumeTime     Defines the time where the 1st regular cycle time based message transmission takes place, after an immediate transmission before.
  DebounceTime            This represents the configuration of a Tx debounce time for SYNC, FUP, OFS and OFNS messages compared to a message before with the same PDU.
  DomainConfigIdx         the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FupMessageType          This provides information about whether or not the FUP/OFNS message is CRC secured.
  ImmediateTimeSync       Enables/Disables the cyclic polling of StbM_GetTimeBaseUpdateCounter() within CanTSyn_MainFunction().
  MasterConfHandleId      This represents the handle ID of the PDU that contains the global time information.
  MasterConfTimeout       This represents the confirmation timeout after transmission of a message.
  MessageDomainId         This contains the domain ID to which the message belongs.
  PartitionConfigIdx      the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  PduIdStatesIdx          the index of the 1:1 relation pointing to CanTSyn_PduIdStates
  SyncMessageType         This provides information about whether or not the SYNC/OFS message is CRC secured.
  TxCrcSecured            CRC is supported or not.
  TxDebounceCounterIdx    the index of the 0:1 relation pointing to CanTSyn_TxDebounceCounter
  TxPduId                 This represents the ID of the Pdu taken to transmit the global time information.
  TxPeriod                This represents configuration of the Tx period.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_MasterConfigType, CANTSYN_CONST) CanTSyn_MasterConfig[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_PartitionIdentifiersType, CANTSYN_CONST) CanTSyn_PartitionIdentifiers[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveConfig
  \brief  Contains configuration parameters of slave.
  \details
  Element                     Description
  DomainConfigIdx             the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FollowUpTimeout             Rx timeout for the follow-up message. This is only relevant for selected bus systems.
  PartitionConfigIdx          the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  RxCrcValidated              Validation of the CRC is supported or not
  SequenceCounterJumpWidth    The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages.
  SlaveHandleId               This represents the handle ID of the PDU that contains the global time information.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_SlaveConfigType, CANTSYN_CONST) CanTSyn_SlaveConfig[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SyncDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SyncDataIDList
  \brief  Element of the DataIDList for SYNC/OFS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_SyncDataIDListType, CANTSYN_CONST) CanTSyn_SyncDataIDList[16];
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_Initialized
**********************************************************************************************************************/
/** 
  \var    CanTSyn_Initialized
  \brief  Initialization state of the CanTSyn. TRUE, if CanTSyn_Init() has been called, else FALSE.
*/ 
#define CANTSYN_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_InitializedType, CANTSYN_VAR_CLEARED) CanTSyn_Initialized;
#define CANTSYN_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_MasterState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_MasterState
  \brief  Contains variables of masters.
  \details
  Element                         Description
  CyclicMsgResumeCounter          Count of number of cyclic time bases transmissions.
  TxConfirmationTimeoutCounter    Count of confirmation timeout after each transmission.
  TxPeriodCounter                 Counter for TxPeriod.
  LastUpdateCounter               The value of the time base update counter that is retrieved from StbM can be stored in here in order to compare it to the next current update counter.
  TransmitImmediateSync           True if next Sync message is sent in immediate mode.
  TxSequenceCounter               Sequence counter for Tx messages.
  FupTimeStamp                    This represents the time stamp of follow up message from StbM.
  State                           State of the master.
  SyncTimestamp                   This represents the synchronized time stamp from StbM.
  TimeBaseStatus                  This represents the time base status value from StbM.
  UserData                        This represents the user data retrieved from StbM.
  VirtualLocalTime                This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_MasterStateType, CANTSYN_VAR_NO_INIT) CanTSyn_MasterState[1];
#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PduIdStates
**********************************************************************************************************************/
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_PduIdStatesType, CANTSYN_VAR_NO_INIT) CanTSyn_PduIdStates[1];
#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveState
  \details
  Element                   Description
  RxFollowUpTimeoutCount    Count of number of Rx timeouts for follow-up messages.
  RxSequenceCounter         Sequence counter for Rx messages.
  State                     State of the slave
  SyncMsg                   This represents the synchronized message type.
  VirtualLocalTime          This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_SlaveStateType, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveState[1];
#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_TransmissionControllerState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_TransmissionControllerState
  \brief  State of the transmission. 1u = CANTSYN_TX_ON, 0u = CANTSYN_TX_OFF.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_TransmissionModeType, CANTSYN_VAR_NO_INIT) CanTSyn_TransmissionControllerState[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_TxDebounceCounter
**********************************************************************************************************************/
/** 
  \var    CanTSyn_TxDebounceCounter
  \brief  Current counter value for debouncing.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_TxDebounceCounterType, CANTSYN_VAR_NO_INIT) CanTSyn_TxDebounceCounter[1];
#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_PCConfigsType, CANTSYN_CONST) CanTSyn_PCConfig;
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCPartitionConfigRDR_01
  \details
  Element                        Description
  ControllerInfo                 the pointer to CanTSyn_ControllerInfo
  DomainConfig                   the pointer to CanTSyn_DomainConfig
  MasterConfig                   the pointer to CanTSyn_MasterConfig
  PduIdStates                    the pointer to CanTSyn_PduIdStates
  SlaveConfig                    the pointer to CanTSyn_SlaveConfig
  TransmissionControllerState    the pointer to CanTSyn_TransmissionControllerState
  TxDebounceCounter              the pointer to CanTSyn_TxDebounceCounter
  SizeOfControllerInfo           the number of accomplishable value elements in CanTSyn_ControllerInfo
  SizeOfMasterConfig             the number of accomplishable value elements in CanTSyn_MasterConfig
  SizeOfPduIdStates              the number of accomplishable value elements in CanTSyn_PduIdStates
  SizeOfSlaveConfig              the number of accomplishable value elements in CanTSyn_SlaveConfig
  SizeOfTxDebounceCounter        the number of accomplishable value elements in CanTSyn_TxDebounceCounter
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_PCPartitionConfigType, CANTSYN_CONST) CanTSyn_PCPartitionConfigRDR_01[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCPartitionConfigRDR_05
  \details
  Element                        Description
  ControllerInfo                 the pointer to CanTSyn_ControllerInfo
  DomainConfig                   the pointer to CanTSyn_DomainConfig
  MasterConfig                   the pointer to CanTSyn_MasterConfig
  PduIdStates                    the pointer to CanTSyn_PduIdStates
  SlaveConfig                    the pointer to CanTSyn_SlaveConfig
  TransmissionControllerState    the pointer to CanTSyn_TransmissionControllerState
  TxDebounceCounter              the pointer to CanTSyn_TxDebounceCounter
  SizeOfControllerInfo           the number of accomplishable value elements in CanTSyn_ControllerInfo
  SizeOfMasterConfig             the number of accomplishable value elements in CanTSyn_MasterConfig
  SizeOfPduIdStates              the number of accomplishable value elements in CanTSyn_PduIdStates
  SizeOfSlaveConfig              the number of accomplishable value elements in CanTSyn_SlaveConfig
  SizeOfTxDebounceCounter        the number of accomplishable value elements in CanTSyn_TxDebounceCounter
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_PCPartitionConfigType, CANTSYN_CONST) CanTSyn_PCPartitionConfigRDR_05[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#endif  /* CANTSYN_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: CanTSyn_Cfg.h
 *********************************************************************************************************************/
