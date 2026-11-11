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
 *            Module: J1939Dcm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: J1939Dcm_Cfg.h
 *   Generation Time: 2026-05-11 17:41:03
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
    
#if !defined(J1939DCM_CFG_H)
#define J1939DCM_CFG_H

/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/

#include "J1939Dcm_Types.h"



/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* --- Component Version Information ------------------------------------------------------------------------------- */
/* AUTOSAR Version (from xsi:schemaLocation) */
#define J1939DCM_CFG_AR_RELEASE_MAJOR_VERSION                             4u
#define J1939DCM_CFG_AR_RELEASE_MINOR_VERSION                             1u
#define J1939DCM_CFG_AR_RELEASE_REVISION_VERSION                          2u

/* AUTOSAR Software Specification Version Information of BSW-IMPLEMENTATION */
#define J1939DCM_CFG_AR_MAJOR_VERSION                                     4u
#define J1939DCM_CFG_AR_MINOR_VERSION                                     1u
#define J1939DCM_CFG_AR_PATCH_VERSION                                     2u

/* SW version number of BSW-IMPLEMENTATION */
#define J1939DCM_CFG_SW_MAJOR_VERSION                                     18u
#define J1939DCM_CFG_SW_MINOR_VERSION                                     4u
#define J1939DCM_CFG_SW_PATCH_VERSION                                     1u

/* Generator Version Information */
#define J1939DCM_CFG_GEN_MAJOR_VERSION                                    18
#define J1939DCM_CFG_GEN_MINOR_VERSION                                    4
#define J1939DCM_CFG_GEN_PATCH_VERSION                                    1


/**********************************************************************************************************************
 * Global defines
**********************************************************************************************************************/

/* Definition of feature switches in the library delivered */
#ifndef J1939DCM_USE_DUMMY_STATEMENT
#define J1939DCM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939DCM_DUMMY_STATEMENT
#define J1939DCM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939DCM_DUMMY_STATEMENT_CONST
#define J1939DCM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define J1939DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef J1939DCM_ATOMIC_VARIABLE_ACCESS
#define J1939DCM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef J1939DCM_PROCESSOR_IND13400
#define J1939DCM_PROCESSOR_IND13400
#endif
#ifndef J1939DCM_COMP_LLVMDIAB
#define J1939DCM_COMP_LLVMDIAB
#endif
#ifndef J1939DCM_GEN_GENERATOR_MSR
#define J1939DCM_GEN_GENERATOR_MSR
#endif
#ifndef J1939DCM_CPUTYPE_BITORDER_LSB2MSB
#define J1939DCM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef J1939DCM_CONFIGURATION_VARIANT_PRECOMPILE
#define J1939DCM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef J1939DCM_CONFIGURATION_VARIANT_LINKTIME
#define J1939DCM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef J1939DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define J1939DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef J1939DCM_CONFIGURATION_VARIANT
#define J1939DCM_CONFIGURATION_VARIANT J1939DCM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef J1939DCM_POSTBUILD_VARIANT_SUPPORT
#define J1939DCM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef J1939DCM_DEV_ERROR_DETECT
#define J1939DCM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef J1939DCM_DEV_ERROR_REPORT
#define J1939DCM_DEV_ERROR_REPORT STD_ON
#endif

/**********************************************************************************************************************
 * General defines
**********************************************************************************************************************/

#define J1939DCM_VERSION_INFO_API               STD_OFF 
#define J1939DCM_DM13_HS_MODIFIED_ENABLED       STD_OFF 
#define J1939DCM_BUFFERSIZE_COMMON              1785u 
#define J1939DCM_BUFFERSIZE_DM1                 1785u 
#define J1939DCM_TASK_CYCLE                     10u 
#define J1939DCM_TXTIMEOUT                      101u 
#define J1939DCM_MAX_DTCS_PER_CYCLE             1u 
#define J1939DCM_DM1_MAX_DTCS                   20u 
#define J1939DCM_MAX_FF_PER_CYCLE               1u 
#define J1939DCM_MAX_FF_SIZE_CONFORM            STD_ON 
#define J1939DCM_MAX_RATIOS_PER_CYCLE           1u 
#define J1939DCM_MAX_SUPPORTED_SPNS_PER_CYCLE   1u 
#define J1939DCM_MAX_CALIBRATION_INFO_PER_CYCLE 1u 
#define J1939DCM_MAX_ACTIVE_TIME_PER_CYCLE      1u 
#define J1939DCM_DM1_ISOBUS_CONFORM             STD_OFF 



/**********************************************************************************************************************
 * Supported DMs
**********************************************************************************************************************/

#define J1939DCM_DM1_SUPPORT  STD_ON 
#define J1939DCM_DM2_SUPPORT  STD_OFF 
#define J1939DCM_DM3_SUPPORT  STD_OFF 
#define J1939DCM_DM4_SUPPORT  STD_OFF 
#define J1939DCM_DM5_SUPPORT  STD_OFF 
#define J1939DCM_DM6_SUPPORT  STD_OFF 
#define J1939DCM_DM7_SUPPORT  STD_OFF 
#define J1939DCM_DM8_SUPPORT  STD_OFF 
#define J1939DCM_DM10_SUPPORT STD_OFF 
#define J1939DCM_DM11_SUPPORT STD_OFF 
#define J1939DCM_DM12_SUPPORT STD_OFF 
#define J1939DCM_DM13_SUPPORT STD_OFF 
#define J1939DCM_DM14_SUPPORT STD_OFF 
#define J1939DCM_DM15_SUPPORT STD_OFF 
#define J1939DCM_DM16_SUPPORT STD_OFF 
#define J1939DCM_DM17_SUPPORT STD_OFF 
#define J1939DCM_DM18_SUPPORT STD_OFF 
#define J1939DCM_DM19_SUPPORT STD_OFF 
#define J1939DCM_DM20_SUPPORT STD_OFF 
#define J1939DCM_DM21_SUPPORT STD_OFF 
#define J1939DCM_DM22_SUPPORT STD_OFF 
#define J1939DCM_DM23_SUPPORT STD_OFF 
#define J1939DCM_DM24_SUPPORT STD_OFF 
#define J1939DCM_DM25_SUPPORT STD_OFF 
#define J1939DCM_DM26_SUPPORT STD_OFF 
#define J1939DCM_DM27_SUPPORT STD_OFF 
#define J1939DCM_DM28_SUPPORT STD_OFF 
#define J1939DCM_DM29_SUPPORT STD_OFF 
#define J1939DCM_DM30_SUPPORT STD_OFF 
#define J1939DCM_DM31_SUPPORT STD_OFF 
#define J1939DCM_DM33_SUPPORT STD_OFF 
#define J1939DCM_DM34_SUPPORT STD_OFF 
#define J1939DCM_DM35_SUPPORT STD_OFF 
#define J1939DCM_DM53_SUPPORT STD_OFF 
#define J1939DCM_DM54_SUPPORT STD_OFF 
#define J1939DCM_DM55_SUPPORT STD_OFF 
#define J1939DCM_DM56_SUPPORT STD_OFF 
#define J1939DCM_DM57_SUPPORT STD_OFF 
#define J1939DCM_DM58_SUPPORT STD_OFF 



/**********************************************************************************************************************
 * RxPdu
**********************************************************************************************************************/




/**********************************************************************************************************************
 * TxPdu
**********************************************************************************************************************/

#define J1939DcmConf_J1939DcmTxPdu_J1939DcmTxPdu 0u 



/**********************************************************************************************************************
 * Misc.
**********************************************************************************************************************/

#define J1939DCM_INVALID_PDU_ID                  65535u 
#define J1939DCM_DM_SUPPORTS_NODE                0u 
#define J1939DCM_SIZE_OF_BITFIELD_SUPPORTED_SPNS 1u 
#define J1939DCM_MAX_NUM_CHANNELS                1u 
#define J1939DCM_MAX_NUM_NODES                   1u 
#define J1939DCM_GENERATOR_COMPATIBILITY_VERSION 0x00036585u /*  Extended error detection capabilities  */  



/**********************************************************************************************************************
 * MEMORY ACCESS FUNCTIONS
**********************************************************************************************************************/

#define J1939Dcm_Cfg_MemRequestIndicationFunc    NULL_PTR 
#define J1939Dcm_Cfg_MemResponseTxConfFunc       NULL_PTR 
#define J1939Dcm_Cfg_MemDataStartOfReceptionFunc NULL_PTR 
#define J1939Dcm_Cfg_MemDataCopyRxFunc           NULL_PTR 
#define J1939Dcm_Cfg_MemDataRxIndicationFunc     NULL_PTR 
#define J1939Dcm_Cfg_MemDataTxConfFunc           NULL_PTR 



/**********************************************************************************************************************
 * MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmPCDataSwitches  J1939Dcm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define J1939DCM_CFG_CHANNELSUPPORTEDARRAY                                                          STD_ON
#define J1939DCM_CFG_CHANNELTABLE                                                                   STD_ON
#define J1939DCM_CFG_BUSTYPEARRAYOFCFG_CHANNELTABLE                                                 STD_ON
#define J1939DCM_CFG_CHANNELIDARRAYOFCFG_CHANNELTABLE                                               STD_ON
#define J1939DCM_CFG_ISOBUSCHANNELOFCFG_CHANNELTABLE                                                STD_ON
#define J1939DCM_CFG_MESSAGETABLEENDIDXOFCFG_CHANNELTABLE                                           STD_ON
#define J1939DCM_CFG_MESSAGETABLESTARTIDXOFCFG_CHANNELTABLE                                         STD_ON
#define J1939DCM_CFG_MESSAGETABLE                                                                   STD_ON
#define J1939DCM_CFG_DMARRAYOFCFG_MESSAGETABLE                                                      STD_ON
#define J1939DCM_CFG_PGNARRAYOFCFG_MESSAGETABLE                                                     STD_ON
#define J1939DCM_CFG_PEERTXPDUARRAYENDIDXOFCFG_MESSAGETABLE                                         STD_ON
#define J1939DCM_CFG_PEERTXPDUARRAYSTARTIDXOFCFG_MESSAGETABLE                                       STD_ON
#define J1939DCM_CFG_METADATATYPEARRAY                                                              STD_ON
#define J1939DCM_METADATAGETTERCAN_ID_32IDXOFCFG_METADATATYPEARRAY                                  STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterCAN_ID_32Idx' Reason: 'the optional indirection is deactivated because MetaDataGetterCAN_ID_32UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERCAN_ID_32USEDOFCFG_METADATATYPEARRAY                                 STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterCAN_ID_32Used' Reason: 'the optional indirection is deactivated because MetaDataGetterCAN_ID_32UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERPRIORITY_8IDXOFCFG_METADATATYPEARRAY                                 STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterPRIORITY_8Idx' Reason: 'the optional indirection is deactivated because MetaDataGetterPRIORITY_8UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERPRIORITY_8USEDOFCFG_METADATATYPEARRAY                                STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterPRIORITY_8Used' Reason: 'the optional indirection is deactivated because MetaDataGetterPRIORITY_8UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERSOURCE_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                          STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterSOURCE_ADDRESS_16Idx' Reason: 'the optional indirection is deactivated because MetaDataGetterSOURCE_ADDRESS_16UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERSOURCE_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                         STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataGetterSOURCE_ADDRESS_16Used' Reason: 'the optional indirection is deactivated because MetaDataGetterSOURCE_ADDRESS_16UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATAGETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                          STD_ON
#define J1939DCM_METADATAGETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                         STD_ON
#define J1939DCM_METADATASETTERCAN_ID_32IDXOFCFG_METADATATYPEARRAY                                  STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterCAN_ID_32Idx' Reason: 'the optional indirection is deactivated because MetaDataSetterCAN_ID_32UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERCAN_ID_32USEDOFCFG_METADATATYPEARRAY                                 STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterCAN_ID_32Used' Reason: 'the optional indirection is deactivated because MetaDataSetterCAN_ID_32UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERPRIORITY_8IDXOFCFG_METADATATYPEARRAY                                 STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterPRIORITY_8Idx' Reason: 'the optional indirection is deactivated because MetaDataSetterPRIORITY_8UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERPRIORITY_8USEDOFCFG_METADATATYPEARRAY                                STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterPRIORITY_8Used' Reason: 'the optional indirection is deactivated because MetaDataSetterPRIORITY_8UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERSOURCE_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                          STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterSOURCE_ADDRESS_16Idx' Reason: 'the optional indirection is deactivated because MetaDataSetterSOURCE_ADDRESS_16UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERSOURCE_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                         STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_MetaDataTypeArray.MetaDataSetterSOURCE_ADDRESS_16Used' Reason: 'the optional indirection is deactivated because MetaDataSetterSOURCE_ADDRESS_16UsedOfCfg_MetaDataTypeArray is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_METADATASETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                          STD_ON
#define J1939DCM_METADATASETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                         STD_ON
#define J1939DCM_CFG_NODETABLE                                                                      STD_ON
#define J1939DCM_CFG_CHANNELSUPPORTEDARRAYENDIDXOFCFG_NODETABLE                                     STD_ON
#define J1939DCM_CFG_CHANNELSUPPORTEDARRAYSTARTIDXOFCFG_NODETABLE                                   STD_ON
#define J1939DCM_CFG_DEMCLIENTIDARRAYOFCFG_NODETABLE                                                STD_ON
#define J1939DCM_CFG_NODEADDRESSARRAYOFCFG_NODETABLE                                                STD_ON
#define J1939DCM_CFG_NODEIDARRAYOFCFG_NODETABLE                                                     STD_ON
#define J1939DCM_CFG_OBDSPECIFICARRAYOFCFG_NODETABLE                                                STD_ON
#define J1939DCM_CFG_SPNARRAYENDIDXOFCFG_NODETABLE                                                  STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_NodeTable.Cfg_SPNArrayEndIdx' Reason: 'the optional indirection is deactivated because Cfg_SPNArrayUsedOfCfg_NodeTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_SPNARRAYSTARTIDXOFCFG_NODETABLE                                                STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_NodeTable.Cfg_SPNArrayStartIdx' Reason: 'the optional indirection is deactivated because Cfg_SPNArrayUsedOfCfg_NodeTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_SPNARRAYUSEDOFCFG_NODETABLE                                                    STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_NodeTable.Cfg_SPNArrayUsed' Reason: 'the optional indirection is deactivated because Cfg_SPNArrayUsedOfCfg_NodeTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_USERIDARRAYOFCFG_NODETABLE                                                     STD_ON
#define J1939DCM_CFG_PEERTXPDUARRAY                                                                 STD_ON
#define J1939DCM_CFG_METADATATYPEARRAYIDXOFCFG_PEERTXPDUARRAY                                       STD_ON
#define J1939DCM_CFG_METADATATYPEARRAYUSEDOFCFG_PEERTXPDUARRAY                                      STD_ON
#define J1939DCM_CFG_PEERTXPDUOFCFG_PEERTXPDUARRAY                                                  STD_ON
#define J1939DCM_CFG_RXPDUTABLE                                                                     STD_ON
#define J1939DCM_CFG_CHANNELTABLEIDXOFCFG_RXPDUTABLE                                                STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_ChannelTableIdx' Reason: 'the optional indirection is deactivated because Cfg_ChannelTableUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_CHANNELTABLEUSEDOFCFG_RXPDUTABLE                                               STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_ChannelTableUsed' Reason: 'the optional indirection is deactivated because Cfg_ChannelTableUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_MESSAGETABLEIDXOFCFG_RXPDUTABLE                                                STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_MessageTableIdx' Reason: 'the optional indirection is deactivated because Cfg_MessageTableUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_MESSAGETABLEUSEDOFCFG_RXPDUTABLE                                               STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_MessageTableUsed' Reason: 'the optional indirection is deactivated because Cfg_MessageTableUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_METADATATYPEARRAYIDXOFCFG_RXPDUTABLE                                           STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_MetaDataTypeArrayIdx' Reason: 'the optional indirection is deactivated because Cfg_MetaDataTypeArrayUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_METADATATYPEARRAYUSEDOFCFG_RXPDUTABLE                                          STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_RxPduTable.Cfg_MetaDataTypeArrayUsed' Reason: 'the optional indirection is deactivated because Cfg_MetaDataTypeArrayUsedOfCfg_RxPduTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define J1939DCM_CFG_RXISBROADCASTOFCFG_RXPDUTABLE                                                  STD_ON
#define J1939DCM_CFG_RXNODEADDRESSOFCFG_RXPDUTABLE                                                  STD_ON
#define J1939DCM_CFG_RXSOURCEADDRESSOFCFG_RXPDUTABLE                                                STD_ON
#define J1939DCM_CFG_SPNARRAY                                                                       STD_OFF  /**< Deactivateable: 'J1939Dcm_Cfg_SPNArray' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_CFG_TXPDUTABLE                                                                     STD_ON
#define J1939DCM_CFG_CHANNELTABLEIDXOFCFG_TXPDUTABLE                                                STD_ON
#define J1939DCM_CFG_CHANNELTABLEUSEDOFCFG_TXPDUTABLE                                               STD_ON
#define J1939DCM_CFG_MESSAGETABLEIDXOFCFG_TXPDUTABLE                                                STD_ON
#define J1939DCM_CFG_MESSAGETABLEUSEDOFCFG_TXPDUTABLE                                               STD_ON
#define J1939DCM_COMPATIBILITYVERSION                                                               STD_ON
#define J1939DCM_FINALMAGICNUMBER                                                                   STD_OFF  /**< Deactivateable: 'J1939Dcm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define J1939DCM_INITBROADCASTSTATUS                                                                STD_ON
#define J1939DCM_INITDATAHASHCODE                                                                   STD_OFF  /**< Deactivateable: 'J1939Dcm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define J1939DCM_METADATAGETTERCAN_ID_32                                                            STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataGetterCAN_ID_32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATAGETTERPRIORITY_8                                                           STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataGetterPRIORITY_8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATAGETTERSOURCE_ADDRESS_16                                                    STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataGetterSOURCE_ADDRESS_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATAGETTERTARGET_ADDRESS_16                                                    STD_ON
#define J1939DCM_METADATASETTERCAN_ID_32                                                            STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataSetterCAN_ID_32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATASETTERPRIORITY_8                                                           STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataSetterPRIORITY_8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATASETTERSOURCE_ADDRESS_16                                                    STD_OFF  /**< Deactivateable: 'J1939Dcm_MetaDataSetterSOURCE_ADDRESS_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define J1939DCM_METADATASETTERTARGET_ADDRESS_16                                                    STD_ON
#define J1939DCM_NUMBEROFEXISTEDRXPDUS                                                              STD_ON
#define J1939DCM_NUMBEROFEXISTEDTXPDUS                                                              STD_ON
#define J1939DCM_SIZEOFCFG_CHANNELSUPPORTEDARRAY                                                    STD_ON
#define J1939DCM_SIZEOFCFG_CHANNELTABLE                                                             STD_ON
#define J1939DCM_SIZEOFCFG_MESSAGETABLE                                                             STD_ON
#define J1939DCM_SIZEOFCFG_METADATATYPEARRAY                                                        STD_ON
#define J1939DCM_SIZEOFCFG_NODETABLE                                                                STD_ON
#define J1939DCM_SIZEOFCFG_PEERTXPDUARRAY                                                           STD_ON
#define J1939DCM_SIZEOFCFG_RXPDUTABLE                                                               STD_ON
#define J1939DCM_SIZEOFCFG_SPNARRAY                                                                 STD_OFF  /**< Deactivateable: 'J1939Dcm_SizeOfCfg_SPNArray' Reason: 'Deactivateable: 'Cfg_SPNArray' Reason: 'Deactivateable: 'J1939Dcm_Cfg_SPNArray' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define J1939DCM_SIZEOFCFG_TXPDUTABLE                                                               STD_ON
#define J1939DCM_PCCONFIG                                                                           STD_ON
#define J1939DCM_CFG_CHANNELSUPPORTEDARRAYOFPCCONFIG                                                STD_ON
#define J1939DCM_CFG_CHANNELTABLEOFPCCONFIG                                                         STD_ON
#define J1939DCM_CFG_MESSAGETABLEOFPCCONFIG                                                         STD_ON
#define J1939DCM_CFG_METADATATYPEARRAYOFPCCONFIG                                                    STD_ON
#define J1939DCM_CFG_NODETABLEOFPCCONFIG                                                            STD_ON
#define J1939DCM_CFG_PEERTXPDUARRAYOFPCCONFIG                                                       STD_ON
#define J1939DCM_CFG_RXPDUTABLEOFPCCONFIG                                                           STD_ON
#define J1939DCM_CFG_TXPDUTABLEOFPCCONFIG                                                           STD_ON
#define J1939DCM_COMPATIBILITYVERSIONOFPCCONFIG                                                     STD_ON
#define J1939DCM_FINALMAGICNUMBEROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'J1939Dcm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define J1939DCM_INITBROADCASTSTATUSOFPCCONFIG                                                      STD_ON
#define J1939DCM_INITDATAHASHCODEOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'J1939Dcm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define J1939DCM_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                          STD_ON
#define J1939DCM_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                          STD_ON
#define J1939DCM_NUMBEROFEXISTEDRXPDUSOFPCCONFIG                                                    STD_ON
#define J1939DCM_NUMBEROFEXISTEDTXPDUSOFPCCONFIG                                                    STD_ON
#define J1939DCM_SIZEOFCFG_CHANNELSUPPORTEDARRAYOFPCCONFIG                                          STD_ON
#define J1939DCM_SIZEOFCFG_CHANNELTABLEOFPCCONFIG                                                   STD_ON
#define J1939DCM_SIZEOFCFG_MESSAGETABLEOFPCCONFIG                                                   STD_ON
#define J1939DCM_SIZEOFCFG_METADATATYPEARRAYOFPCCONFIG                                              STD_ON
#define J1939DCM_SIZEOFCFG_NODETABLEOFPCCONFIG                                                      STD_ON
#define J1939DCM_SIZEOFCFG_PEERTXPDUARRAYOFPCCONFIG                                                 STD_ON
#define J1939DCM_SIZEOFCFG_RXPDUTABLEOFPCCONFIG                                                     STD_ON
#define J1939DCM_SIZEOFCFG_SPNARRAYOFPCCONFIG                                                       STD_OFF  /**< Deactivateable: 'J1939Dcm_PCConfig.SizeOfCfg_SPNArray' Reason: 'Deactivateable: 'Cfg_SPNArray' Reason: 'Deactivateable: 'J1939Dcm_Cfg_SPNArray' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define J1939DCM_SIZEOFCFG_TXPDUTABLEOFPCCONFIG                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCNoReferenceDefines  J1939Dcm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define J1939DCM_NO_METADATAGETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                       255u
#define J1939DCM_NO_METADATASETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                       255u
#define J1939DCM_NO_CFG_METADATATYPEARRAYIDXOFCFG_PEERTXPDUARRAY                                    255u
#define J1939DCM_NO_CFG_CHANNELTABLEIDXOFCFG_TXPDUTABLE                                             255u
#define J1939DCM_NO_CFG_MESSAGETABLEIDXOFCFG_TXPDUTABLE                                             255u
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCIsReducedToDefineDefines  J1939Dcm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define J1939DCM_ISDEF_CFG_CHANNELSUPPORTEDARRAY                                                    STD_ON
#define J1939DCM_ISDEF_CFG_BUSTYPEARRAYOFCFG_CHANNELTABLE                                           STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELIDARRAYOFCFG_CHANNELTABLE                                         STD_ON
#define J1939DCM_ISDEF_CFG_ISOBUSCHANNELOFCFG_CHANNELTABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_MESSAGETABLEENDIDXOFCFG_CHANNELTABLE                                     STD_ON
#define J1939DCM_ISDEF_CFG_MESSAGETABLESTARTIDXOFCFG_CHANNELTABLE                                   STD_ON
#define J1939DCM_ISDEF_CFG_DMARRAYOFCFG_MESSAGETABLE                                                STD_ON
#define J1939DCM_ISDEF_CFG_PGNARRAYOFCFG_MESSAGETABLE                                               STD_ON
#define J1939DCM_ISDEF_CFG_PEERTXPDUARRAYENDIDXOFCFG_MESSAGETABLE                                   STD_ON
#define J1939DCM_ISDEF_CFG_PEERTXPDUARRAYSTARTIDXOFCFG_MESSAGETABLE                                 STD_ON
#define J1939DCM_ISDEF_METADATAGETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                    STD_ON
#define J1939DCM_ISDEF_METADATAGETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                   STD_ON
#define J1939DCM_ISDEF_METADATASETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                    STD_ON
#define J1939DCM_ISDEF_METADATASETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                   STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELSUPPORTEDARRAYENDIDXOFCFG_NODETABLE                               STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELSUPPORTEDARRAYSTARTIDXOFCFG_NODETABLE                             STD_ON
#define J1939DCM_ISDEF_CFG_DEMCLIENTIDARRAYOFCFG_NODETABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_NODEADDRESSARRAYOFCFG_NODETABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_NODEIDARRAYOFCFG_NODETABLE                                               STD_ON
#define J1939DCM_ISDEF_CFG_OBDSPECIFICARRAYOFCFG_NODETABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_USERIDARRAYOFCFG_NODETABLE                                               STD_ON
#define J1939DCM_ISDEF_CFG_METADATATYPEARRAYIDXOFCFG_PEERTXPDUARRAY                                 STD_ON
#define J1939DCM_ISDEF_CFG_METADATATYPEARRAYUSEDOFCFG_PEERTXPDUARRAY                                STD_ON
#define J1939DCM_ISDEF_CFG_PEERTXPDUOFCFG_PEERTXPDUARRAY                                            STD_ON
#define J1939DCM_ISDEF_CFG_RXISBROADCASTOFCFG_RXPDUTABLE                                            STD_ON
#define J1939DCM_ISDEF_CFG_RXNODEADDRESSOFCFG_RXPDUTABLE                                            STD_ON
#define J1939DCM_ISDEF_CFG_RXSOURCEADDRESSOFCFG_RXPDUTABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELTABLEIDXOFCFG_TXPDUTABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELTABLEUSEDOFCFG_TXPDUTABLE                                         STD_ON
#define J1939DCM_ISDEF_CFG_MESSAGETABLEIDXOFCFG_TXPDUTABLE                                          STD_ON
#define J1939DCM_ISDEF_CFG_MESSAGETABLEUSEDOFCFG_TXPDUTABLE                                         STD_ON
#define J1939DCM_ISDEF_METADATAGETTERTARGET_ADDRESS_16                                              STD_OFF
#define J1939DCM_ISDEF_METADATASETTERTARGET_ADDRESS_16                                              STD_OFF
#define J1939DCM_ISDEF_CFG_CHANNELSUPPORTEDARRAYOFPCCONFIG                                          STD_ON
#define J1939DCM_ISDEF_CFG_CHANNELTABLEOFPCCONFIG                                                   STD_ON
#define J1939DCM_ISDEF_CFG_MESSAGETABLEOFPCCONFIG                                                   STD_ON
#define J1939DCM_ISDEF_CFG_METADATATYPEARRAYOFPCCONFIG                                              STD_ON
#define J1939DCM_ISDEF_CFG_NODETABLEOFPCCONFIG                                                      STD_ON
#define J1939DCM_ISDEF_CFG_PEERTXPDUARRAYOFPCCONFIG                                                 STD_ON
#define J1939DCM_ISDEF_CFG_RXPDUTABLEOFPCCONFIG                                                     STD_ON
#define J1939DCM_ISDEF_CFG_TXPDUTABLEOFPCCONFIG                                                     STD_ON
#define J1939DCM_ISDEF_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                    STD_ON
#define J1939DCM_ISDEF_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCEqualsAlwaysToDefines  J1939Dcm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define J1939DCM_EQ2_CFG_CHANNELSUPPORTEDARRAY                                                      TRUE
#define J1939DCM_EQ2_CFG_BUSTYPEARRAYOFCFG_CHANNELTABLE                                             J1939DCM_J1939_NETWORK_1
#define J1939DCM_EQ2_CFG_CHANNELIDARRAYOFCFG_CHANNELTABLE                                           ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6
#define J1939DCM_EQ2_CFG_ISOBUSCHANNELOFCFG_CHANNELTABLE                                            FALSE
#define J1939DCM_EQ2_CFG_MESSAGETABLEENDIDXOFCFG_CHANNELTABLE                                       1u
#define J1939DCM_EQ2_CFG_MESSAGETABLESTARTIDXOFCFG_CHANNELTABLE                                     0u
#define J1939DCM_EQ2_CFG_DMARRAYOFCFG_MESSAGETABLE                                                  J1939DCM_DM1
#define J1939DCM_EQ2_CFG_PGNARRAYOFCFG_MESSAGETABLE                                                 J1939DCM_DM1_PGN
#define J1939DCM_EQ2_CFG_PEERTXPDUARRAYENDIDXOFCFG_MESSAGETABLE                                     1u
#define J1939DCM_EQ2_CFG_PEERTXPDUARRAYSTARTIDXOFCFG_MESSAGETABLE                                   0u
#define J1939DCM_EQ2_METADATAGETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                      0u
#define J1939DCM_EQ2_METADATAGETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                     TRUE
#define J1939DCM_EQ2_METADATASETTERTARGET_ADDRESS_16IDXOFCFG_METADATATYPEARRAY                      0u
#define J1939DCM_EQ2_METADATASETTERTARGET_ADDRESS_16USEDOFCFG_METADATATYPEARRAY                     TRUE
#define J1939DCM_EQ2_CFG_CHANNELSUPPORTEDARRAYENDIDXOFCFG_NODETABLE                                 1u
#define J1939DCM_EQ2_CFG_CHANNELSUPPORTEDARRAYSTARTIDXOFCFG_NODETABLE                               0u
#define J1939DCM_EQ2_CFG_DEMCLIENTIDARRAYOFCFG_NODETABLE                                            DemConf_DemClient_DemClient
#define J1939DCM_EQ2_CFG_NODEADDRESSARRAYOFCFG_NODETABLE                                            208u
#define J1939DCM_EQ2_CFG_NODEIDARRAYOFCFG_NODETABLE                                                 J1939NmConf_J1939NmNode_J1939NmNode
#define J1939DCM_EQ2_CFG_OBDSPECIFICARRAYOFCFG_NODETABLE                                            FALSE
#define J1939DCM_EQ2_CFG_USERIDARRAYOFCFG_NODETABLE                                                 J1939RmConf_J1939RmUser_J1939RmUser
#define J1939DCM_EQ2_CFG_METADATATYPEARRAYIDXOFCFG_PEERTXPDUARRAY                                   0u
#define J1939DCM_EQ2_CFG_METADATATYPEARRAYUSEDOFCFG_PEERTXPDUARRAY                                  TRUE
#define J1939DCM_EQ2_CFG_PEERTXPDUOFCFG_PEERTXPDUARRAY                                              PduRConf_PduRSrcPdu_PduRSrcPdu_beb9bba4
#define J1939DCM_EQ2_CFG_RXISBROADCASTOFCFG_RXPDUTABLE                                              FALSE
#define J1939DCM_EQ2_CFG_RXNODEADDRESSOFCFG_RXPDUTABLE                                              0u
#define J1939DCM_EQ2_CFG_RXSOURCEADDRESSOFCFG_RXPDUTABLE                                            0u
#define J1939DCM_EQ2_CFG_CHANNELTABLEIDXOFCFG_TXPDUTABLE                                            0u
#define J1939DCM_EQ2_CFG_CHANNELTABLEUSEDOFCFG_TXPDUTABLE                                           TRUE
#define J1939DCM_EQ2_CFG_MESSAGETABLEIDXOFCFG_TXPDUTABLE                                            0u
#define J1939DCM_EQ2_CFG_MESSAGETABLEUSEDOFCFG_TXPDUTABLE                                           TRUE
#define J1939DCM_EQ2_METADATAGETTERTARGET_ADDRESS_16                                                
#define J1939DCM_EQ2_METADATASETTERTARGET_ADDRESS_16                                                
#define J1939DCM_EQ2_CFG_CHANNELSUPPORTEDARRAYOFPCCONFIG                                            J1939Dcm_Cfg_ChannelSupportedArray
#define J1939DCM_EQ2_CFG_CHANNELTABLEOFPCCONFIG                                                     J1939Dcm_Cfg_ChannelTable
#define J1939DCM_EQ2_CFG_MESSAGETABLEOFPCCONFIG                                                     J1939Dcm_Cfg_MessageTable
#define J1939DCM_EQ2_CFG_METADATATYPEARRAYOFPCCONFIG                                                J1939Dcm_Cfg_MetaDataTypeArray
#define J1939DCM_EQ2_CFG_NODETABLEOFPCCONFIG                                                        J1939Dcm_Cfg_NodeTable
#define J1939DCM_EQ2_CFG_PEERTXPDUARRAYOFPCCONFIG                                                   J1939Dcm_Cfg_PeerTxPduArray
#define J1939DCM_EQ2_CFG_RXPDUTABLEOFPCCONFIG                                                       J1939Dcm_Cfg_RxPduTable
#define J1939DCM_EQ2_CFG_TXPDUTABLEOFPCCONFIG                                                       J1939Dcm_Cfg_TxPduTable
#define J1939DCM_EQ2_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                      J1939Dcm_MetaDataGetterTARGET_ADDRESS_16
#define J1939DCM_EQ2_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                      J1939Dcm_MetaDataSetterTARGET_ADDRESS_16
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCSymbolicInitializationPointers  J1939Dcm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define J1939Dcm_Config_Ptr                                                                         NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Dcm' */
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCInitializationSymbols  J1939Dcm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define J1939Dcm_Config                                                                             NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Dcm */
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCGeneral  J1939Dcm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define J1939DCM_CHECK_INIT_POINTER                                                                 STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define J1939DCM_FINAL_MAGIC_NUMBER                                                                 0x3A1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of J1939Dcm */
#define J1939DCM_INDIVIDUAL_POSTBUILD                                                               STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'J1939Dcm' is not configured to be postbuild capable. */
#define J1939DCM_INIT_DATA                                                                          J1939DCM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define J1939DCM_INIT_DATA_HASH_CODE                                                                -248463323  /**< the precompile constant to validate the initialization structure at initialization time of J1939Dcm with a hashcode. The seed value is '0x3A1Eu' */
#define J1939DCM_USE_ECUM_BSW_ERROR_HOOK                                                            STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define J1939DCM_USE_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer J1939Dcm shall be used. */
/** 
  \}
*/ 


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmPCGetConstantDuplicatedRootDataMacros  J1939Dcm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define J1939Dcm_GetCfg_ChannelSupportedArrayOfPCConfig()                                           J1939Dcm_Cfg_ChannelSupportedArray  /**< the pointer to J1939Dcm_Cfg_ChannelSupportedArray */
#define J1939Dcm_GetCfg_ChannelTableOfPCConfig()                                                    J1939Dcm_Cfg_ChannelTable  /**< the pointer to J1939Dcm_Cfg_ChannelTable */
#define J1939Dcm_GetCfg_MessageTableOfPCConfig()                                                    J1939Dcm_Cfg_MessageTable  /**< the pointer to J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_GetCfg_MetaDataTypeArrayOfPCConfig()                                               J1939Dcm_Cfg_MetaDataTypeArray  /**< the pointer to J1939Dcm_Cfg_MetaDataTypeArray */
#define J1939Dcm_GetCfg_NodeTableOfPCConfig()                                                       J1939Dcm_Cfg_NodeTable  /**< the pointer to J1939Dcm_Cfg_NodeTable */
#define J1939Dcm_GetCfg_PeerTxPduArrayOfPCConfig()                                                  J1939Dcm_Cfg_PeerTxPduArray  /**< the pointer to J1939Dcm_Cfg_PeerTxPduArray */
#define J1939Dcm_GetCfg_RxPduTableOfPCConfig()                                                      J1939Dcm_Cfg_RxPduTable  /**< the pointer to J1939Dcm_Cfg_RxPduTable */
#define J1939Dcm_GetCfg_TxPduTableOfPCConfig()                                                      J1939Dcm_Cfg_TxPduTable  /**< the pointer to J1939Dcm_Cfg_TxPduTable */
#define J1939Dcm_GetCompatibilityVersionOfPCConfig()                                                222597u
#define J1939Dcm_GetInitBroadcastStatusOfPCConfig()                                                 4u
#define J1939Dcm_GetMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                     J1939Dcm_MetaDataGetterTARGET_ADDRESS_16  /**< the pointer to J1939Dcm_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Dcm_GetMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                     J1939Dcm_MetaDataSetterTARGET_ADDRESS_16  /**< the pointer to J1939Dcm_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Dcm_GetNumberOfExistedRxPdusOfPCConfig()                                               0u
#define J1939Dcm_GetNumberOfExistedTxPdusOfPCConfig()                                               1u
#define J1939Dcm_GetSizeOfCfg_ChannelSupportedArrayOfPCConfig()                                     1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_ChannelSupportedArray */
#define J1939Dcm_GetSizeOfCfg_ChannelTableOfPCConfig()                                              1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_ChannelTable */
#define J1939Dcm_GetSizeOfCfg_MessageTableOfPCConfig()                                              1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_GetSizeOfCfg_MetaDataTypeArrayOfPCConfig()                                         1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_MetaDataTypeArray */
#define J1939Dcm_GetSizeOfCfg_NodeTableOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_NodeTable */
#define J1939Dcm_GetSizeOfCfg_PeerTxPduArrayOfPCConfig()                                            1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_PeerTxPduArray */
#define J1939Dcm_GetSizeOfCfg_RxPduTableOfPCConfig()                                                1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_RxPduTable */
#define J1939Dcm_GetSizeOfCfg_TxPduTableOfPCConfig()                                                1u  /**< the number of accomplishable value elements in J1939Dcm_Cfg_TxPduTable */
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCGetDataMacros  J1939Dcm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define J1939Dcm_GetMetaDataGetterTARGET_ADDRESS_16(Index)                                          (J1939Dcm_GetMetaDataGetterTARGET_ADDRESS_16OfPCConfig()[(Index)])
#define J1939Dcm_GetMetaDataSetterTARGET_ADDRESS_16(Index)                                          (J1939Dcm_GetMetaDataSetterTARGET_ADDRESS_16OfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCGetDeduplicatedDataMacros  J1939Dcm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define J1939Dcm_IsCfg_ChannelSupportedArray(Index)                                                 (((TRUE)) != FALSE)
#define J1939Dcm_GetCfg_BusTypeArrayOfCfg_ChannelTable(Index)                                       J1939DCM_J1939_NETWORK_1
#define J1939Dcm_GetCfg_ChannelIdArrayOfCfg_ChannelTable(Index)                                     ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6
#define J1939Dcm_IsCfg_IsobusChannelOfCfg_ChannelTable(Index)                                       (((FALSE)) != FALSE)
#define J1939Dcm_GetCfg_MessageTableEndIdxOfCfg_ChannelTable(Index)                                 1u  /**< the end index of the 1:n relation pointing to J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_GetCfg_MessageTableStartIdxOfCfg_ChannelTable(Index)                               0u  /**< the start index of the 1:n relation pointing to J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_GetCfg_DMArrayOfCfg_MessageTable(Index)                                            J1939DCM_DM1
#define J1939Dcm_GetCfg_PGNArrayOfCfg_MessageTable(Index)                                           J1939DCM_DM1_PGN
#define J1939Dcm_GetCfg_PeerTxPduArrayEndIdxOfCfg_MessageTable(Index)                               1u  /**< the end index of the 1:n relation pointing to J1939Dcm_Cfg_PeerTxPduArray */
#define J1939Dcm_GetCfg_PeerTxPduArrayStartIdxOfCfg_MessageTable(Index)                             0u  /**< the start index of the 1:n relation pointing to J1939Dcm_Cfg_PeerTxPduArray */
#define J1939Dcm_GetMetaDataGetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray(Index)                0u  /**< the index of the 0:1 relation pointing to J1939Dcm_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Dcm_IsMetaDataGetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray(Index)                (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Dcm_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Dcm_GetMetaDataSetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray(Index)                0u  /**< the index of the 0:1 relation pointing to J1939Dcm_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Dcm_IsMetaDataSetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray(Index)                (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Dcm_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Dcm_GetCfg_ChannelSupportedArrayEndIdxOfCfg_NodeTable(Index)                           1u  /**< the end index of the 1:n relation pointing to J1939Dcm_Cfg_ChannelSupportedArray */
#define J1939Dcm_GetCfg_ChannelSupportedArrayStartIdxOfCfg_NodeTable(Index)                         0u  /**< the start index of the 1:n relation pointing to J1939Dcm_Cfg_ChannelSupportedArray */
#define J1939Dcm_GetCfg_DemClientIdArrayOfCfg_NodeTable(Index)                                      DemConf_DemClient_DemClient
#define J1939Dcm_GetCfg_NodeAddressArrayOfCfg_NodeTable(Index)                                      208u
#define J1939Dcm_GetCfg_NodeIdArrayOfCfg_NodeTable(Index)                                           J1939NmConf_J1939NmNode_J1939NmNode
#define J1939Dcm_IsCfg_ObdSpecificArrayOfCfg_NodeTable(Index)                                       (((FALSE)) != FALSE)
#define J1939Dcm_GetCfg_UserIdArrayOfCfg_NodeTable(Index)                                           J1939RmConf_J1939RmUser_J1939RmUser
#define J1939Dcm_GetCfg_MetaDataTypeArrayIdxOfCfg_PeerTxPduArray(Index)                             0u  /**< the index of the 0:1 relation pointing to J1939Dcm_Cfg_MetaDataTypeArray */
#define J1939Dcm_IsCfg_MetaDataTypeArrayUsedOfCfg_PeerTxPduArray(Index)                             (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Dcm_Cfg_MetaDataTypeArray */
#define J1939Dcm_GetCfg_PeerTxPduOfCfg_PeerTxPduArray(Index)                                        PduRConf_PduRSrcPdu_PduRSrcPdu_beb9bba4  /**< the symbolic name value of the peer tx pdu */
#define J1939Dcm_IsCfg_RxIsBroadcastOfCfg_RxPduTable(Index)                                         (((FALSE)) != FALSE)  /**< the broadcast property for the given RX PDU ID */
#define J1939Dcm_GetCfg_RxNodeAddressOfCfg_RxPduTable(Index)                                        0u  /**< the node address assigned to the RX PDU ID */
#define J1939Dcm_GetCfg_RxSourceAddressOfCfg_RxPduTable(Index)                                      0u  /**< the source address for the given PDU (in case of no meta data) */
#define J1939Dcm_GetCfg_ChannelTableIdxOfCfg_TxPduTable(Index)                                      0u  /**< the index of the 0:1 relation pointing to J1939Dcm_Cfg_ChannelTable */
#define J1939Dcm_IsCfg_ChannelTableUsedOfCfg_TxPduTable(Index)                                      (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Dcm_Cfg_ChannelTable */
#define J1939Dcm_GetCfg_MessageTableIdxOfCfg_TxPduTable(Index)                                      0u  /**< the index of the 0:1 relation pointing to J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_IsCfg_MessageTableUsedOfCfg_TxPduTable(Index)                                      (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Dcm_Cfg_MessageTable */
#define J1939Dcm_GetCompatibilityVersion()                                                          J1939Dcm_GetCompatibilityVersionOfPCConfig()
#define J1939Dcm_GetInitBroadcastStatus()                                                           J1939Dcm_GetInitBroadcastStatusOfPCConfig()
#define J1939Dcm_GetNumberOfExistedRxPdus()                                                         J1939Dcm_GetNumberOfExistedRxPdusOfPCConfig()
#define J1939Dcm_GetNumberOfExistedTxPdus()                                                         J1939Dcm_GetNumberOfExistedTxPdusOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_ChannelSupportedArray()                                               J1939Dcm_GetSizeOfCfg_ChannelSupportedArrayOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_ChannelTable()                                                        J1939Dcm_GetSizeOfCfg_ChannelTableOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_MessageTable()                                                        J1939Dcm_GetSizeOfCfg_MessageTableOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_MetaDataTypeArray()                                                   J1939Dcm_GetSizeOfCfg_MetaDataTypeArrayOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_NodeTable()                                                           J1939Dcm_GetSizeOfCfg_NodeTableOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_PeerTxPduArray()                                                      J1939Dcm_GetSizeOfCfg_PeerTxPduArrayOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_RxPduTable()                                                          J1939Dcm_GetSizeOfCfg_RxPduTableOfPCConfig()
#define J1939Dcm_GetSizeOfCfg_TxPduTable()                                                          J1939Dcm_GetSizeOfCfg_TxPduTableOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCHasMacros  J1939Dcm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define J1939Dcm_HasCfg_ChannelSupportedArray()                                                     (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelTable()                                                              (TRUE != FALSE)
#define J1939Dcm_HasCfg_BusTypeArrayOfCfg_ChannelTable()                                            (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelIdArrayOfCfg_ChannelTable()                                          (TRUE != FALSE)
#define J1939Dcm_HasCfg_IsobusChannelOfCfg_ChannelTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTableEndIdxOfCfg_ChannelTable()                                      (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTableStartIdxOfCfg_ChannelTable()                                    (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTable()                                                              (TRUE != FALSE)
#define J1939Dcm_HasCfg_DMArrayOfCfg_MessageTable()                                                 (TRUE != FALSE)
#define J1939Dcm_HasCfg_PGNArrayOfCfg_MessageTable()                                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_PeerTxPduArrayEndIdxOfCfg_MessageTable()                                    (TRUE != FALSE)
#define J1939Dcm_HasCfg_PeerTxPduArrayStartIdxOfCfg_MessageTable()                                  (TRUE != FALSE)
#define J1939Dcm_HasCfg_MetaDataTypeArray()                                                         (TRUE != FALSE)
#define J1939Dcm_HasMetaDataGetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray()                     (TRUE != FALSE)
#define J1939Dcm_HasMetaDataGetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray()                    (TRUE != FALSE)
#define J1939Dcm_HasMetaDataSetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray()                     (TRUE != FALSE)
#define J1939Dcm_HasMetaDataSetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray()                    (TRUE != FALSE)
#define J1939Dcm_HasCfg_NodeTable()                                                                 (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelSupportedArrayEndIdxOfCfg_NodeTable()                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelSupportedArrayStartIdxOfCfg_NodeTable()                              (TRUE != FALSE)
#define J1939Dcm_HasCfg_DemClientIdArrayOfCfg_NodeTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_NodeAddressArrayOfCfg_NodeTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_NodeIdArrayOfCfg_NodeTable()                                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_ObdSpecificArrayOfCfg_NodeTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_UserIdArrayOfCfg_NodeTable()                                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_PeerTxPduArray()                                                            (TRUE != FALSE)
#define J1939Dcm_HasCfg_MetaDataTypeArrayIdxOfCfg_PeerTxPduArray()                                  (TRUE != FALSE)
#define J1939Dcm_HasCfg_MetaDataTypeArrayUsedOfCfg_PeerTxPduArray()                                 (TRUE != FALSE)
#define J1939Dcm_HasCfg_PeerTxPduOfCfg_PeerTxPduArray()                                             (TRUE != FALSE)
#define J1939Dcm_HasCfg_RxPduTable()                                                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_RxIsBroadcastOfCfg_RxPduTable()                                             (TRUE != FALSE)
#define J1939Dcm_HasCfg_RxNodeAddressOfCfg_RxPduTable()                                             (TRUE != FALSE)
#define J1939Dcm_HasCfg_RxSourceAddressOfCfg_RxPduTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_TxPduTable()                                                                (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelTableIdxOfCfg_TxPduTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelTableUsedOfCfg_TxPduTable()                                          (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTableIdxOfCfg_TxPduTable()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTableUsedOfCfg_TxPduTable()                                          (TRUE != FALSE)
#define J1939Dcm_HasCompatibilityVersion()                                                          (TRUE != FALSE)
#define J1939Dcm_HasInitBroadcastStatus()                                                           (TRUE != FALSE)
#define J1939Dcm_HasMetaDataGetterTARGET_ADDRESS_16()                                               (TRUE != FALSE)
#define J1939Dcm_HasMetaDataSetterTARGET_ADDRESS_16()                                               (TRUE != FALSE)
#define J1939Dcm_HasNumberOfExistedRxPdus()                                                         (TRUE != FALSE)
#define J1939Dcm_HasNumberOfExistedTxPdus()                                                         (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_ChannelSupportedArray()                                               (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_ChannelTable()                                                        (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_MessageTable()                                                        (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_MetaDataTypeArray()                                                   (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_NodeTable()                                                           (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_PeerTxPduArray()                                                      (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_RxPduTable()                                                          (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_TxPduTable()                                                          (TRUE != FALSE)
#define J1939Dcm_HasPCConfig()                                                                      (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelSupportedArrayOfPCConfig()                                           (TRUE != FALSE)
#define J1939Dcm_HasCfg_ChannelTableOfPCConfig()                                                    (TRUE != FALSE)
#define J1939Dcm_HasCfg_MessageTableOfPCConfig()                                                    (TRUE != FALSE)
#define J1939Dcm_HasCfg_MetaDataTypeArrayOfPCConfig()                                               (TRUE != FALSE)
#define J1939Dcm_HasCfg_NodeTableOfPCConfig()                                                       (TRUE != FALSE)
#define J1939Dcm_HasCfg_PeerTxPduArrayOfPCConfig()                                                  (TRUE != FALSE)
#define J1939Dcm_HasCfg_RxPduTableOfPCConfig()                                                      (TRUE != FALSE)
#define J1939Dcm_HasCfg_TxPduTableOfPCConfig()                                                      (TRUE != FALSE)
#define J1939Dcm_HasCompatibilityVersionOfPCConfig()                                                (TRUE != FALSE)
#define J1939Dcm_HasInitBroadcastStatusOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Dcm_HasMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                     (TRUE != FALSE)
#define J1939Dcm_HasMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                     (TRUE != FALSE)
#define J1939Dcm_HasNumberOfExistedRxPdusOfPCConfig()                                               (TRUE != FALSE)
#define J1939Dcm_HasNumberOfExistedTxPdusOfPCConfig()                                               (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_ChannelSupportedArrayOfPCConfig()                                     (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_ChannelTableOfPCConfig()                                              (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_MessageTableOfPCConfig()                                              (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_MetaDataTypeArrayOfPCConfig()                                         (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_NodeTableOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_PeerTxPduArrayOfPCConfig()                                            (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_RxPduTableOfPCConfig()                                                (TRUE != FALSE)
#define J1939Dcm_HasSizeOfCfg_TxPduTableOfPCConfig()                                                (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmLTDataSwitches  J1939Dcm Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define J1939DCM_LTCONFIG                                                                           STD_OFF  /**< Deactivateable: 'J1939Dcm_LTConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmPBDataSwitches  J1939Dcm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define J1939DCM_PBCONFIG                                                                           STD_OFF  /**< Deactivateable: 'J1939Dcm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define J1939DCM_LTCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'J1939Dcm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define J1939DCM_PCCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'J1939Dcm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/



#endif /* J1939DCM_CFG_H */

