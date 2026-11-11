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
 *            Module: SomeIpTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SomeIpTp_Cfg.h
 *   Generation Time: 2026-08-27 14:12:14
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
#if !defined(SOMEIPTP_CFG_H)
# define SOMEIPTP_CFG_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "ComStack_Types.h"
 
 /**********************************************************************************************************************
 * MACROS
**********************************************************************************************************************/
/* Definition of feature switches in the library delivered */
#ifndef SOMEIPTP_USE_DUMMY_STATEMENT
#define SOMEIPTP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOMEIPTP_DUMMY_STATEMENT
#define SOMEIPTP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOMEIPTP_DUMMY_STATEMENT_CONST
#define SOMEIPTP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SOMEIPTP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SOMEIPTP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SOMEIPTP_ATOMIC_VARIABLE_ACCESS
#define SOMEIPTP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SOMEIPTP_PROCESSOR_IND13400
#define SOMEIPTP_PROCESSOR_IND13400
#endif
#ifndef SOMEIPTP_COMP_LLVMDIAB
#define SOMEIPTP_COMP_LLVMDIAB
#endif
#ifndef SOMEIPTP_GEN_GENERATOR_MSR
#define SOMEIPTP_GEN_GENERATOR_MSR
#endif
#ifndef SOMEIPTP_CPUTYPE_BITORDER_LSB2MSB
#define SOMEIPTP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SOMEIPTP_CONFIGURATION_VARIANT_PRECOMPILE
#define SOMEIPTP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SOMEIPTP_CONFIGURATION_VARIANT_LINKTIME
#define SOMEIPTP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SOMEIPTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SOMEIPTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SOMEIPTP_CONFIGURATION_VARIANT
#define SOMEIPTP_CONFIGURATION_VARIANT SOMEIPTP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SOMEIPTP_POSTBUILD_VARIANT_SUPPORT
#define SOMEIPTP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define SOMEIPTP_DEV_ERROR_DETECT                   STD_ON
#define SOMEIPTP_DEV_ERROR_REPORT                   STD_ON
#define SOMEIPTP_VERSION_INFO_API                   STD_OFF
#define SOMEIPTP_RUNTIME_ERROR_REPORT               STD_ON

#define SOMEIPTP_CFG_GEN_MAJOR_VERSION              6u
#define SOMEIPTP_CFG_GEN_MINOR_VERSION              1u
#define SOMEIPTP_CFG_GEN_PATCH_VERSION              1u

/* LL Rx N-Pdu IDs */




/* UL Tx N-Sdu IDs and LL Tx N-Pdu IDs */



/**
 * \defgroup SomeIpTpHandleIdsTxPdusPDUIDs Handle IDs of handle space TxPdus PDU IDs.
 * \brief Symbolic Name Values (SNVs) for TxPdus PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SomeIpTpConf_SomeIpTpTxNPdu_PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced 0u /**< [PostBuildInvariantValuesModelView] */
#define SomeIpTpConf_SomeIpTpTxNSdu_PDUTriggering14_Detections_RDR1_to_ADAS_de104d9b 0u /**< [PostBuildInvariantValuesModelView] */
/**\} */


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONSTANTS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SomeIpTpPCDataSwitches  SomeIpTp Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SOMEIPTP_CHANNEL                                                                            STD_ON
#define SOMEIPTP_NPDUSEPARATIONTIMEOFCHANNEL                                                        STD_ON
#define SOMEIPTP_NUMOFRXNSDUSOFCHANNEL                                                              STD_ON
#define SOMEIPTP_NUMOFTXNSDUSOFCHANNEL                                                              STD_ON
#define SOMEIPTP_RXTIMEOUTTIMEOFCHANNEL                                                             STD_ON
#define SOMEIPTP_TXCONFTIMEOUTTIMEOFCHANNEL                                                         STD_ON
#define SOMEIPTP_FINALMAGICNUMBER                                                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SOMEIPTP_INITDATAHASHCODE                                                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SOMEIPTP_METADATAGETTERSOCKET_CONNECTION_ID_16                                              STD_OFF  /**< Deactivateable: 'SomeIpTp_MetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATASETTERSOCKET_CONNECTION_ID_16                                              STD_OFF  /**< Deactivateable: 'SomeIpTp_MetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXNSDU                                                                             STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOMEIPTP_CHANNELIDXOFRXNSDU                                                                 STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.ChannelIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_INVALIDHNDOFRXNSDU                                                                 STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATAGETTERSOCKET_CONNECTION_ID_16IDXOFRXNSDU                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.MetaDataGetterSOCKET_CONNECTION_ID_16Idx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATAGETTERSOCKET_CONNECTION_ID_16USEDOFRXNSDU                                  STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.MetaDataGetterSOCKET_CONNECTION_ID_16Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATASETTERSOCKET_CONNECTION_ID_16IDXOFRXNSDU                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.MetaDataSetterSOCKET_CONNECTION_ID_16Idx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATASETTERSOCKET_CONNECTION_ID_16USEDOFRXNSDU                                  STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.MetaDataSetterSOCKET_CONNECTION_ID_16Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXSHORTHEADERSENDIDXOFRXNSDU                                                       STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.RxShortHeadersEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXSHORTHEADERSSTARTIDXOFRXNSDU                                                     STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.RxShortHeadersStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXSTATEIDXOFRXNSDU                                                                 STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.RxStateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_UPPERLAYERIDOFRXNSDU                                                               STD_OFF  /**< Deactivateable: 'SomeIpTp_RXNSdu.UpperLayerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXSHORTHEADERS                                                                     STD_OFF  /**< Deactivateable: 'SomeIpTp_RxShortHeaders' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_RXSTATE                                                                            STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define SOMEIPTP_AVAILBUFSIZEOFRXSTATE                                                              STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.AvailBufSize' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_DATAINDEXOFRXSTATE                                                                 STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.DataIndex' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_METADATAOFRXSTATE                                                                  STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.Metadata' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_OFFSETOFRXSTATE                                                                    STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.Offset' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_STATUSOFRXSTATE                                                                    STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.Status' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_TIMEROFRXSTATE                                                                     STD_OFF  /**< Deactivateable: 'SomeIpTp_RxState.Timer' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define SOMEIPTP_SIZEOFCHANNEL                                                                      STD_ON
#define SOMEIPTP_SIZEOFMETADATAGETTERSOCKET_CONNECTION_ID_16                                        STD_OFF  /**< Deactivateable: 'SomeIpTp_SizeOfMetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'MetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'SomeIpTp_MetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFMETADATASETTERSOCKET_CONNECTION_ID_16                                        STD_OFF  /**< Deactivateable: 'SomeIpTp_SizeOfMetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'MetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'SomeIpTp_MetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFRXNSDU                                                                       STD_OFF  /**< Deactivateable: 'SomeIpTp_SizeOfRXNSdu' Reason: 'Deactivateable: 'RXNSdu' Reason: 'Deactivateable: 'SomeIpTp_RXNSdu' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOMEIPTP_SIZEOFRXSHORTHEADERS                                                               STD_OFF  /**< Deactivateable: 'SomeIpTp_SizeOfRxShortHeaders' Reason: 'Deactivateable: 'RxShortHeaders' Reason: 'Deactivateable: 'SomeIpTp_RxShortHeaders' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFRXSTATE                                                                      STD_OFF  /**< Deactivateable: 'SomeIpTp_SizeOfRxState' Reason: 'Deactivateable: 'RxState' Reason: 'Deactivateable: 'SomeIpTp_RxState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.''' */
#define SOMEIPTP_SIZEOFTXNSDU                                                                       STD_ON
#define SOMEIPTP_SIZEOFTXQUEUEELEMENT                                                               STD_ON
#define SOMEIPTP_SIZEOFTXSHORTHEADERS                                                               STD_ON
#define SOMEIPTP_SIZEOFTXSTATE                                                                      STD_ON
#define SOMEIPTP_TXNSDU                                                                             STD_ON
#define SOMEIPTP_CHANNELIDXOFTXNSDU                                                                 STD_ON
#define SOMEIPTP_INVALIDHNDOFTXNSDU                                                                 STD_OFF  /**< Deactivateable: 'SomeIpTp_TXNSdu.InvalidHnd' Reason: 'the value of SomeIpTp_InvalidHndOfTXNSdu is always 'false' due to this, the array is deactivated.' */
#define SOMEIPTP_LOWERLAYERIDOFTXNSDU                                                               STD_ON
#define SOMEIPTP_MAXTXSFPAYLOADOFTXNSDU                                                             STD_ON
#define SOMEIPTP_METADATAGETTERSOCKET_CONNECTION_ID_16IDXOFTXNSDU                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_TXNSdu.MetaDataGetterSOCKET_CONNECTION_ID_16Idx' Reason: 'the optional indirection is deactivated because MetaDataGetterSOCKET_CONNECTION_ID_16UsedOfTXNSdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SOMEIPTP_METADATAGETTERSOCKET_CONNECTION_ID_16USEDOFTXNSDU                                  STD_OFF  /**< Deactivateable: 'SomeIpTp_TXNSdu.MetaDataGetterSOCKET_CONNECTION_ID_16Used' Reason: 'the optional indirection is deactivated because MetaDataGetterSOCKET_CONNECTION_ID_16UsedOfTXNSdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SOMEIPTP_METADATASETTERSOCKET_CONNECTION_ID_16IDXOFTXNSDU                                   STD_OFF  /**< Deactivateable: 'SomeIpTp_TXNSdu.MetaDataSetterSOCKET_CONNECTION_ID_16Idx' Reason: 'the optional indirection is deactivated because MetaDataSetterSOCKET_CONNECTION_ID_16UsedOfTXNSdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SOMEIPTP_METADATASETTERSOCKET_CONNECTION_ID_16USEDOFTXNSDU                                  STD_OFF  /**< Deactivateable: 'SomeIpTp_TXNSdu.MetaDataSetterSOCKET_CONNECTION_ID_16Used' Reason: 'the optional indirection is deactivated because MetaDataSetterSOCKET_CONNECTION_ID_16UsedOfTXNSdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SOMEIPTP_TXBURSTSIZEOFTXNSDU                                                                STD_ON
#define SOMEIPTP_TXNPDUHANDLEIDOFTXNSDU                                                             STD_ON
#define SOMEIPTP_TXNPDULENGTHOFTXNSDU                                                               STD_ON
#define SOMEIPTP_TXNSDUHANDLEIDOFTXNSDU                                                             STD_ON
#define SOMEIPTP_TXSHORTHEADERSENDIDXOFTXNSDU                                                       STD_ON
#define SOMEIPTP_TXSHORTHEADERSSTARTIDXOFTXNSDU                                                     STD_ON
#define SOMEIPTP_TXSTATEIDXOFTXNSDU                                                                 STD_ON
#define SOMEIPTP_UPPERLAYERIDOFTXNSDU                                                               STD_ON
#define SOMEIPTP_TXQUEUEELEMENT                                                                     STD_ON
#define SOMEIPTP_TXSHORTHEADERS                                                                     STD_ON
#define SOMEIPTP_TXSTATE                                                                            STD_ON
#define SOMEIPTP_DATAINDEXOFTXSTATE                                                                 STD_ON
#define SOMEIPTP_DATALENGTHOFTXSTATE                                                                STD_ON
#define SOMEIPTP_METADATAOFTXSTATE                                                                  STD_ON
#define SOMEIPTP_NEXTSEGMENTDLOFTXSTATE                                                             STD_ON
#define SOMEIPTP_OFFSETOFTXSTATE                                                                    STD_ON
#define SOMEIPTP_SEGMENTEDOFTXSTATE                                                                 STD_ON
#define SOMEIPTP_STATUSOFTXSTATE                                                                    STD_ON
#define SOMEIPTP_TIMEROFTXSTATE                                                                     STD_ON
#define SOMEIPTP_PCCONFIG                                                                           STD_ON
#define SOMEIPTP_CHANNELOFPCCONFIG                                                                  STD_ON
#define SOMEIPTP_FINALMAGICNUMBEROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SOMEIPTP_INITDATAHASHCODEOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SOMEIPTP_SIZEOFCHANNELOFPCCONFIG                                                            STD_ON
#define SOMEIPTP_SIZEOFMETADATAGETTERSOCKET_CONNECTION_ID_16OFPCCONFIG                              STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.SizeOfMetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'MetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'SomeIpTp_MetaDataGetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFMETADATASETTERSOCKET_CONNECTION_ID_16OFPCCONFIG                              STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.SizeOfMetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'MetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'Deactivateable: 'SomeIpTp_MetaDataSetterSOCKET_CONNECTION_ID_16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFRXNSDUOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.SizeOfRXNSdu' Reason: 'Deactivateable: 'RXNSdu' Reason: 'Deactivateable: 'SomeIpTp_RXNSdu' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOMEIPTP_SIZEOFRXSHORTHEADERSOFPCCONFIG                                                     STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.SizeOfRxShortHeaders' Reason: 'Deactivateable: 'RxShortHeaders' Reason: 'Deactivateable: 'SomeIpTp_RxShortHeaders' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define SOMEIPTP_SIZEOFRXSTATEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'SomeIpTp_PCConfig.SizeOfRxState' Reason: 'Deactivateable: 'RxState' Reason: 'Deactivateable: 'SomeIpTp_RxState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.''' */
#define SOMEIPTP_SIZEOFTXNSDUOFPCCONFIG                                                             STD_ON
#define SOMEIPTP_SIZEOFTXQUEUEELEMENTOFPCCONFIG                                                     STD_ON
#define SOMEIPTP_SIZEOFTXSHORTHEADERSOFPCCONFIG                                                     STD_ON
#define SOMEIPTP_SIZEOFTXSTATEOFPCCONFIG                                                            STD_ON
#define SOMEIPTP_TXNSDUOFPCCONFIG                                                                   STD_ON
#define SOMEIPTP_TXQUEUEELEMENTOFPCCONFIG                                                           STD_ON
#define SOMEIPTP_TXSHORTHEADERSOFPCCONFIG                                                           STD_ON
#define SOMEIPTP_TXSTATEOFPCCONFIG                                                                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCMinNumericValueDefines  SomeIpTp Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SOMEIPTP_MIN_TXQUEUEELEMENT                                                                 0u
#define SOMEIPTP_MIN_TXSHORTHEADERS                                                                 0u
#define SOMEIPTP_MIN_DATAINDEXOFTXSTATE                                                             0u
#define SOMEIPTP_MIN_DATALENGTHOFTXSTATE                                                            0u
#define SOMEIPTP_MIN_METADATAOFTXSTATE                                                              0u
#define SOMEIPTP_MIN_NEXTSEGMENTDLOFTXSTATE                                                         0u
#define SOMEIPTP_MIN_OFFSETOFTXSTATE                                                                0u
#define SOMEIPTP_MIN_TIMEROFTXSTATE                                                                 0u
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCMaxNumericValueDefines  SomeIpTp Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SOMEIPTP_MAX_TXQUEUEELEMENT                                                                 65535u
#define SOMEIPTP_MAX_TXSHORTHEADERS                                                                 255u
#define SOMEIPTP_MAX_DATAINDEXOFTXSTATE                                                             65535u
#define SOMEIPTP_MAX_DATALENGTHOFTXSTATE                                                            65535u
#define SOMEIPTP_MAX_METADATAOFTXSTATE                                                              65535u
#define SOMEIPTP_MAX_NEXTSEGMENTDLOFTXSTATE                                                         65535u
#define SOMEIPTP_MAX_OFFSETOFTXSTATE                                                                4294967295u
#define SOMEIPTP_MAX_TIMEROFTXSTATE                                                                 65535u
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCIsReducedToDefineDefines  SomeIpTp Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SOMEIPTP_ISDEF_NPDUSEPARATIONTIMEOFCHANNEL                                                  STD_OFF
#define SOMEIPTP_ISDEF_NUMOFRXNSDUSOFCHANNEL                                                        STD_OFF
#define SOMEIPTP_ISDEF_NUMOFTXNSDUSOFCHANNEL                                                        STD_OFF
#define SOMEIPTP_ISDEF_RXTIMEOUTTIMEOFCHANNEL                                                       STD_OFF
#define SOMEIPTP_ISDEF_TXCONFTIMEOUTTIMEOFCHANNEL                                                   STD_OFF
#define SOMEIPTP_ISDEF_CHANNELIDXOFTXNSDU                                                           STD_OFF
#define SOMEIPTP_ISDEF_LOWERLAYERIDOFTXNSDU                                                         STD_OFF
#define SOMEIPTP_ISDEF_MAXTXSFPAYLOADOFTXNSDU                                                       STD_OFF
#define SOMEIPTP_ISDEF_TXBURSTSIZEOFTXNSDU                                                          STD_OFF
#define SOMEIPTP_ISDEF_TXNPDUHANDLEIDOFTXNSDU                                                       STD_OFF
#define SOMEIPTP_ISDEF_TXNPDULENGTHOFTXNSDU                                                         STD_OFF
#define SOMEIPTP_ISDEF_TXNSDUHANDLEIDOFTXNSDU                                                       STD_OFF
#define SOMEIPTP_ISDEF_TXSHORTHEADERSENDIDXOFTXNSDU                                                 STD_OFF
#define SOMEIPTP_ISDEF_TXSHORTHEADERSSTARTIDXOFTXNSDU                                               STD_OFF
#define SOMEIPTP_ISDEF_TXSTATEIDXOFTXNSDU                                                           STD_OFF
#define SOMEIPTP_ISDEF_UPPERLAYERIDOFTXNSDU                                                         STD_OFF
#define SOMEIPTP_ISDEF_CHANNELOFPCCONFIG                                                            STD_ON
#define SOMEIPTP_ISDEF_TXNSDUOFPCCONFIG                                                             STD_ON
#define SOMEIPTP_ISDEF_TXQUEUEELEMENTOFPCCONFIG                                                     STD_ON
#define SOMEIPTP_ISDEF_TXSHORTHEADERSOFPCCONFIG                                                     STD_ON
#define SOMEIPTP_ISDEF_TXSTATEOFPCCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCEqualsAlwaysToDefines  SomeIpTp Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SOMEIPTP_EQ2_NPDUSEPARATIONTIMEOFCHANNEL                                                    
#define SOMEIPTP_EQ2_NUMOFRXNSDUSOFCHANNEL                                                          
#define SOMEIPTP_EQ2_NUMOFTXNSDUSOFCHANNEL                                                          
#define SOMEIPTP_EQ2_RXTIMEOUTTIMEOFCHANNEL                                                         
#define SOMEIPTP_EQ2_TXCONFTIMEOUTTIMEOFCHANNEL                                                     
#define SOMEIPTP_EQ2_CHANNELIDXOFTXNSDU                                                             
#define SOMEIPTP_EQ2_LOWERLAYERIDOFTXNSDU                                                           
#define SOMEIPTP_EQ2_MAXTXSFPAYLOADOFTXNSDU                                                         
#define SOMEIPTP_EQ2_TXBURSTSIZEOFTXNSDU                                                            
#define SOMEIPTP_EQ2_TXNPDUHANDLEIDOFTXNSDU                                                         
#define SOMEIPTP_EQ2_TXNPDULENGTHOFTXNSDU                                                           
#define SOMEIPTP_EQ2_TXNSDUHANDLEIDOFTXNSDU                                                         
#define SOMEIPTP_EQ2_TXSHORTHEADERSENDIDXOFTXNSDU                                                   
#define SOMEIPTP_EQ2_TXSHORTHEADERSSTARTIDXOFTXNSDU                                                 
#define SOMEIPTP_EQ2_TXSTATEIDXOFTXNSDU                                                             
#define SOMEIPTP_EQ2_UPPERLAYERIDOFTXNSDU                                                           
#define SOMEIPTP_EQ2_CHANNELOFPCCONFIG                                                              SomeIpTp_Channel
#define SOMEIPTP_EQ2_TXNSDUOFPCCONFIG                                                               SomeIpTp_TXNSdu
#define SOMEIPTP_EQ2_TXQUEUEELEMENTOFPCCONFIG                                                       SomeIpTp_TxQueueElement
#define SOMEIPTP_EQ2_TXSHORTHEADERSOFPCCONFIG                                                       SomeIpTp_TxShortHeaders.raw
#define SOMEIPTP_EQ2_TXSTATEOFPCCONFIG                                                              SomeIpTp_TxState.raw
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCSymbolicInitializationPointers  SomeIpTp Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define SomeIpTp_Config_Ptr                                                                         NULL_PTR  /**< symbolic identifier which shall be used to initialize 'SomeIpTp' */
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCInitializationSymbols  SomeIpTp Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define SomeIpTp_Config                                                                             NULL_PTR  /**< symbolic identifier which could be used to initialize 'SomeIpTp */
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCGeneral  SomeIpTp General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SOMEIPTP_CHECK_INIT_POINTER                                                                 STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SOMEIPTP_FINAL_MAGIC_NUMBER                                                                 0x001Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of SomeIpTp */
#define SOMEIPTP_INDIVIDUAL_POSTBUILD                                                               STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'SomeIpTp' is not configured to be postbuild capable. */
#define SOMEIPTP_INIT_DATA                                                                          SOMEIPTP_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SOMEIPTP_INIT_DATA_HASH_CODE                                                                -716236264  /**< the precompile constant to validate the initialization structure at initialization time of SomeIpTp with a hashcode. The seed value is '0x001Eu' */
#define SOMEIPTP_USE_ECUM_BSW_ERROR_HOOK                                                            STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SOMEIPTP_USE_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer SomeIpTp shall be used. */
/** 
  \}
*/ 




#endif /* SOMEIPTP_CFG_H */
/**********************************************************************************************************************
  END OF FILE: SomeIpTp_Cfg.h
**********************************************************************************************************************/
