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
 *            Module: J1939Tp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: J1939Tp_Cfg.h
 *   Generation Time: 2026-08-05 12:38:44
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

#if !(defined J1939TP_CFG_H)
# define J1939TP_CFG_H

/**********************************************************************************************************************
  MISRA JUSTIFICATION
**********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

# include "J1939Tp_Types.h"


/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef J1939TP_USE_DUMMY_STATEMENT
#define J1939TP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939TP_DUMMY_STATEMENT
#define J1939TP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939TP_DUMMY_STATEMENT_CONST
#define J1939TP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef J1939TP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define J1939TP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef J1939TP_ATOMIC_VARIABLE_ACCESS
#define J1939TP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef J1939TP_PROCESSOR_IND13400
#define J1939TP_PROCESSOR_IND13400
#endif
#ifndef J1939TP_COMP_LLVMDIAB
#define J1939TP_COMP_LLVMDIAB
#endif
#ifndef J1939TP_GEN_GENERATOR_MSR
#define J1939TP_GEN_GENERATOR_MSR
#endif
#ifndef J1939TP_CPUTYPE_BITORDER_LSB2MSB
#define J1939TP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef J1939TP_CONFIGURATION_VARIANT_PRECOMPILE
#define J1939TP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef J1939TP_CONFIGURATION_VARIANT_LINKTIME
#define J1939TP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef J1939TP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define J1939TP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef J1939TP_CONFIGURATION_VARIANT
#define J1939TP_CONFIGURATION_VARIANT J1939TP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef J1939TP_POSTBUILD_VARIANT_SUPPORT
#define J1939TP_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


#define J1939TP_CFG_MAJOR_VERSION (2u)
#define J1939TP_CFG_MINOR_VERSION (3u)
#define J1939TP_CFG_PATCH_VERSION (0u)

#define J1939TP_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/J1939Tp/J1939TpGeneral[0:J1939TpSafeBswChecks] || /ActiveEcuC/J1939Tp/J1939TpGeneral[0:J1939TpDevErrorDetect] */

#define J1939TP_DEV_ERROR_REPORT STD_ON
#define J1939TP_RUNTIME_ERROR_REPORT STD_ON
#define J1939TP_VERSION_INFO_API STD_OFF

#define J1939TP_CANCELLATION_SUPPORT STD_OFF

#define J1939TP_CANIF_DLCCHECK STD_OFF

#define J1939TP_ENABLED STD_ON
#define J1939TP_TX_ENABLED STD_ON
#define J1939TP_RX_ENABLED STD_OFF

#define J1939TP_DIRECT_ENABLED STD_ON
#define J1939TP_DIRECT_TX_ENABLED STD_ON
#define J1939TP_DIRECT_RX_ENABLED STD_OFF

#define J1939TP_BAM_ENABLED STD_ON
#define J1939TP_BAM_TX_ENABLED STD_ON
#define J1939TP_BAM_RX_ENABLED STD_OFF

#define J1939TP_CMDT_ENABLED STD_ON
#define J1939TP_CMDT_TX_ENABLED STD_ON
#define J1939TP_CMDT_RX_ENABLED STD_OFF

#define J1939TP_ETP_ENABLED STD_OFF
#define J1939TP_ETP_TX_ENABLED STD_OFF
#define J1939TP_ETP_RX_ENABLED STD_OFF

#define J1939TP_FPP_ENABLED STD_OFF
#define J1939TP_FPP_TX_ENABLED STD_OFF
#define J1939TP_FPP_RX_ENABLED STD_OFF

#define J1939TP_FDBAM_ENABLED STD_OFF
#define J1939TP_FDBAM_TX_ENABLED STD_OFF
#define J1939TP_FDBAM_RX_ENABLED STD_OFF

#define J1939TP_FDCMDT_ENABLED STD_OFF
#define J1939TP_FDCMDT_TX_ENABLED STD_OFF
#define J1939TP_FDCMDT_RX_ENABLED STD_OFF

#define J1939TP_FDDIRECT_ENABLED STD_OFF
#define J1939TP_FDDIRECT_TX_ENABLED STD_OFF
#define J1939TP_FDDIRECT_RX_ENABLED STD_OFF




/**
 * \defgroup J1939TpHandleIdsTxN-SDUIDs Handle IDs of handle space Tx N-SDU IDs.
 * \brief Symbolic Name Values (SNVs) for Tx N-SDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define J1939TpConf_J1939TpTxNSdu_DM1_D0_oVCAN_RADAR_ce78d82a_Tx      0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */





/**
 * \defgroup J1939TpHandleIdsTxN-PDUIDs Handle IDs of handle space Tx N-PDU IDs.
 * \brief Symbolic Name Values (SNVs) for Tx N-PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define J1939TpConf_J1939TpTxCmNPdu_J1939TpTxCmNPdu_2210d016          0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define J1939TpConf_J1939TpTxDirectNPdu_DirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_3cea4416 2u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define J1939TpConf_J1939TpTxDtNPdu_J1939TpTxDtNPdu_2210d016          1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPCDataSwitches  J1939Tp Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define J1939TP_FINALMAGICNUMBER                                                                    STD_OFF  /**< the module configuration does not support flashing of data. */
#define J1939TP_FPPRXSDUSEQUENCECOUNTER                                                             STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_FPPTXSDUSEQUENCECOUNTER                                                             STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_INITDATAHASHCODE                                                                    STD_OFF  /**< the module configuration does not support flashing of data. */
#define J1939TP_MAINPERIOD                                                                          STD_ON
#define J1939TP_METADATAGETTERCAN_ID_32                                                             STD_ON
#define J1939TP_METADATAGETTERPRIORITY_8                                                            STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16                                                     STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16                                                     STD_ON
#define J1939TP_METADATASETTERCAN_ID_32                                                             STD_ON
#define J1939TP_METADATASETTERPRIORITY_8                                                            STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16                                                     STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERTARGET_ADDRESS_16                                                     STD_ON
#define J1939TP_RXCHANNEL                                                                           STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_COMMCHANNELOFRXCHANNEL                                                              STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXCANFDCHANNELOFRXCHANNEL                                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXCANCELLATIONSUPPORTOFRXCHANNEL                                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXCHANNELRXNSDURXNSDUTABLEINDENDIDXOFRXCHANNEL                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXCHANNELRXNSDURXNSDUTABLEINDSTARTIDXOFRXCHANNEL                                    STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXCHANNELRXNSDURXNSDUTABLEINDUSEDOFRXCHANNEL                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXCHANNELUSESMULTIPGOFRXCHANNEL                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXDAOFRXCHANNEL                                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXDYNAMICBLOCKCALCULATIONOFRXCHANNEL                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXDYNAMICBUFFERRATIOOFRXCHANNEL                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXISOBUSCHANNELOFRXCHANNEL                                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPACKETSPERBLOCKOFRXCHANNEL                                                        STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPROTOCOLTYPEOFRXCHANNEL                                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXRETRYSUPPORTOFRXCHANNEL                                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXSAOFRXCHANNEL                                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDUFDRXFCNPDUIDXOFRXCHANNEL                                                       STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDUFDRXFCNPDUUSEDOFRXCHANNEL                                                      STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDURXETPFCNPDUIDXOFRXCHANNEL                                                      STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDURXETPFCNPDUUSEDOFRXCHANNEL                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDURXFCNPDUIDXOFRXCHANNEL                                                         STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_TXPDURXFCNPDUUSEDOFRXCHANNEL                                                        STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXCHANNELRXNSDU                                                                     STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_RXSDURXNSDUIDXOFRXCHANNELRXNSDU                                                     STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXCHANNELRXNSDURXNSDUTABLEIND                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDU                                                                               STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_HASMETADATAOFRXPDU                                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_INVALIDHNDOFRXPDU                                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERCAN_ID_32IDXOFRXPDU                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERCAN_ID_32USEDOFRXPDU                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERCAN_ID_32IDXOFRXPDU                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERCAN_ID_32USEDOFRXPDU                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_ONISOBUSOFRXPDU                                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_PDUFORMATOFRXPDU                                                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_PDUTYPEOFRXPDU                                                                      STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPDUDAPRIOIDXOFRXPDU                                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUDAPRIOUSEDOFRXPDU                                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFRXPDU                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFRXPDU                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELRXCHANNELTABLEINDUSEDOFRXPDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXSDURXSDUTABLEINDENDIDXOFRXPDU                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXSDURXSDUTABLEINDSTARTIDXOFRXPDU                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXSDURXSDUTABLEINDUSEDOFRXPDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUSAIDXOFRXPDU                                                                   STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUSAUSEDOFRXPDU                                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFRXPDU                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFRXPDU                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFRXPDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUDAPRIO                                                                         STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_RXPDUDAOFRXPDUDAPRIO                                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPDUPRIOOFRXPDUDAPRIO                                                              STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPDURXCHANNEL                                                                      STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_RXCHANNELRXCHANNELIDXOFRXPDURXCHANNEL                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELRXCHANNELTABLEIND                                                     STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXSDU                                                                          STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_RXSDURXSDUIDXOFRXPDURXSDU                                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDURXSDURXSDUTABLEIND                                                             STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXPDUSA                                                                             STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPDUTXCHANNEL                                                                      STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_TXCHANNELTXCHANNELIDXOFRXPDUTXCHANNEL                                               STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXPDUTXCHANNELTXCHANNELTABLEIND                                                     STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXSDU                                                                               STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_FPPRXSDUSEQUENCECOUNTERIDXOFRXSDU                                                   STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_FPPRXSDUSEQUENCECOUNTERUSEDOFRXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_HASMETADATADAOFRXSDU                                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_HASMETADATAOFRXSDU                                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_HASMETADATAPRIOOFRXSDU                                                              STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_HASMETADATASAOFRXSDU                                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_INVALIDHNDOFRXSDU                                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_ISVARIABLEOFRXSDU                                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERPRIORITY_8IDXOFRXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERPRIORITY_8USEDOFRXSDU                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16IDXOFRXSDU                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16USEDOFRXSDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16IDXOFRXSDU                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16USEDOFRXSDU                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERPRIORITY_8IDXOFRXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERPRIORITY_8USEDOFRXSDU                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16IDXOFRXSDU                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16USEDOFRXSDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERTARGET_ADDRESS_16IDXOFRXSDU                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_METADATASETTERTARGET_ADDRESS_16USEDOFRXSDU                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_PGNOFRXSDU                                                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_PDULENGTHOFRXSDU                                                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXCHANNELCHANNELIDXOFRXSDU                                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXCHANNELCHANNELUSEDOFRXSDU                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_RXSDUSTATEIDXOFRXSDU                                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_SDUIDOFRXSDU                                                                        STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_RXSDUSTATE                                                                          STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define J1939TP_SIZEOFFPPRXSDUSEQUENCECOUNTER                                                       STD_ON
#define J1939TP_SIZEOFFPPTXSDUSEQUENCECOUNTER                                                       STD_ON
#define J1939TP_SIZEOFMETADATAGETTERCAN_ID_32                                                       STD_ON
#define J1939TP_SIZEOFMETADATAGETTERPRIORITY_8                                                      STD_ON
#define J1939TP_SIZEOFMETADATAGETTERSOURCE_ADDRESS_16                                               STD_ON
#define J1939TP_SIZEOFMETADATAGETTERTARGET_ADDRESS_16                                               STD_ON
#define J1939TP_SIZEOFMETADATASETTERCAN_ID_32                                                       STD_ON
#define J1939TP_SIZEOFMETADATASETTERPRIORITY_8                                                      STD_ON
#define J1939TP_SIZEOFMETADATASETTERSOURCE_ADDRESS_16                                               STD_ON
#define J1939TP_SIZEOFMETADATASETTERTARGET_ADDRESS_16                                               STD_ON
#define J1939TP_SIZEOFRXCHANNEL                                                                     STD_ON
#define J1939TP_SIZEOFRXCHANNELRXNSDU                                                               STD_ON
#define J1939TP_SIZEOFRXCHANNELRXNSDURXNSDUTABLEIND                                                 STD_ON
#define J1939TP_SIZEOFRXPDU                                                                         STD_ON
#define J1939TP_SIZEOFRXPDUDAPRIO                                                                   STD_ON
#define J1939TP_SIZEOFRXPDURXCHANNEL                                                                STD_ON
#define J1939TP_SIZEOFRXPDURXCHANNELRXCHANNELTABLEIND                                               STD_ON
#define J1939TP_SIZEOFRXPDURXSDU                                                                    STD_ON
#define J1939TP_SIZEOFRXPDURXSDURXSDUTABLEIND                                                       STD_ON
#define J1939TP_SIZEOFRXPDUSA                                                                       STD_ON
#define J1939TP_SIZEOFRXPDUTXCHANNEL                                                                STD_ON
#define J1939TP_SIZEOFRXPDUTXCHANNELTXCHANNELTABLEIND                                               STD_ON
#define J1939TP_SIZEOFRXSDU                                                                         STD_ON
#define J1939TP_SIZEOFRXSDUSTATE                                                                    STD_ON
#define J1939TP_SIZEOFTXCHANNEL                                                                     STD_ON
#define J1939TP_SIZEOFTXCHANNELTXNSDU                                                               STD_ON
#define J1939TP_SIZEOFTXCHANNELTXNSDUTXNSDUTABLEIND                                                 STD_ON
#define J1939TP_SIZEOFTXPDU                                                                         STD_ON
#define J1939TP_SIZEOFTXPDURXCHANNEL                                                                STD_ON
#define J1939TP_SIZEOFTXPDURXCHANNELRXCHANNELTABLEIND                                               STD_ON
#define J1939TP_SIZEOFTXPDUSTATE                                                                    STD_ON
#define J1939TP_SIZEOFTXPDUTXCHANNEL                                                                STD_ON
#define J1939TP_SIZEOFTXPDUTXCHANNELTXCHANNELTABLEIND                                               STD_ON
#define J1939TP_SIZEOFTXSDU                                                                         STD_ON
#define J1939TP_SIZEOFTXSDUSTATE                                                                    STD_ON
#define J1939TP_TIME_FP                                                                             STD_ON
#define J1939TP_TIME_T1                                                                             STD_ON
#define J1939TP_TIME_T2                                                                             STD_ON
#define J1939TP_TIME_T3                                                                             STD_ON
#define J1939TP_TIME_T4                                                                             STD_ON
#define J1939TP_TIME_T5                                                                             STD_ON
#define J1939TP_TIME_TH                                                                             STD_ON
#define J1939TP_TIME_TR                                                                             STD_ON
#define J1939TP_TXCHANNEL                                                                           STD_ON
#define J1939TP_COMMCHANNELOFTXCHANNEL                                                              STD_ON
#define J1939TP_TXBAMINTERFRAMETIMEOFTXCHANNEL                                                      STD_ON
#define J1939TP_TXCANFDCHANNELOFTXCHANNEL                                                           STD_OFF  /**< the value of J1939Tp_TxCanFdChannelOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXCANCELLATIONSUPPORTOFTXCHANNEL                                                    STD_OFF  /**< the value of J1939Tp_TxCancellationSupportOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXCHANNELTXNSDUTXNSDUTABLEINDENDIDXOFTXCHANNEL                                      STD_ON
#define J1939TP_TXCHANNELTXNSDUTXNSDUTABLEINDSTARTIDXOFTXCHANNEL                                    STD_ON
#define J1939TP_TXCHANNELTXNSDUTXNSDUTABLEINDUSEDOFTXCHANNEL                                        STD_ON
#define J1939TP_TXCHANNELUSESMULTIPGOFTXCHANNEL                                                     STD_OFF  /**< the value of J1939Tp_TxChannelUsesMultiPGOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXDAOFTXCHANNEL                                                                     STD_ON
#define J1939TP_TXDYNAMICBLOCKCALCULATIONOFTXCHANNEL                                                STD_OFF  /**< the value of J1939Tp_TxDynamicBlockCalculationOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXISOBUSCHANNELOFTXCHANNEL                                                          STD_OFF  /**< the value of J1939Tp_TxIsobusChannelOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXMAXPACKETSPERBLOCKOFTXCHANNEL                                                     STD_ON
#define J1939TP_TXPDUFDTXCMNPDUIDXOFTXCHANNEL                                                       STD_OFF  /**< the value of J1939Tp_TxPduFdTxCmNPduIdxOfTxChannel is always 'J1939TP_NO_TXPDUFDTXCMNPDUIDXOFTXCHANNEL' due to this, the array is deactivated. */
#define J1939TP_TXPDUFDTXCMNPDUUSEDOFTXCHANNEL                                                      STD_OFF  /**< the value of J1939Tp_TxPduFdTxCmNPduUsedOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPDUFDTXDTNPDUIDXOFTXCHANNEL                                                       STD_OFF  /**< the value of J1939Tp_TxPduFdTxDtNPduIdxOfTxChannel is always 'J1939TP_NO_TXPDUFDTXDTNPDUIDXOFTXCHANNEL' due to this, the array is deactivated. */
#define J1939TP_TXPDUFDTXDTNPDUUSEDOFTXCHANNEL                                                      STD_OFF  /**< the value of J1939Tp_TxPduFdTxDtNPduUsedOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPDUTXCMNPDUIDXOFTXCHANNEL                                                         STD_ON
#define J1939TP_TXPDUTXCMNPDUUSEDOFTXCHANNEL                                                        STD_ON
#define J1939TP_TXPDUTXDTNPDUIDXOFTXCHANNEL                                                         STD_ON
#define J1939TP_TXPDUTXDTNPDUUSEDOFTXCHANNEL                                                        STD_ON
#define J1939TP_TXPDUTXETPCMNPDUIDXOFTXCHANNEL                                                      STD_OFF  /**< the value of J1939Tp_TxPduTxEtpCmNPduIdxOfTxChannel is always 'J1939TP_NO_TXPDUTXETPCMNPDUIDXOFTXCHANNEL' due to this, the array is deactivated. */
#define J1939TP_TXPDUTXETPCMNPDUUSEDOFTXCHANNEL                                                     STD_OFF  /**< the value of J1939Tp_TxPduTxEtpCmNPduUsedOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPDUTXETPDTNPDUIDXOFTXCHANNEL                                                      STD_OFF  /**< the value of J1939Tp_TxPduTxEtpDtNPduIdxOfTxChannel is always 'J1939TP_NO_TXPDUTXETPDTNPDUIDXOFTXCHANNEL' due to this, the array is deactivated. */
#define J1939TP_TXPDUTXETPDTNPDUUSEDOFTXCHANNEL                                                     STD_OFF  /**< the value of J1939Tp_TxPduTxEtpDtNPduUsedOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPENDINGSUPPORTOFTXCHANNEL                                                         STD_OFF  /**< the value of J1939Tp_TxPendingSupportOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPRIOFTXCHANNEL                                                                    STD_ON
#define J1939TP_TXPROTOCOLTYPEOFTXCHANNEL                                                           STD_ON
#define J1939TP_TXRETRYSUPPORTOFTXCHANNEL                                                           STD_OFF  /**< the value of J1939Tp_TxRetrySupportOfTxChannel is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXSAOFTXCHANNEL                                                                     STD_ON
#define J1939TP_TXVARPRIOFTXCHANNEL                                                                 STD_ON
#define J1939TP_TXCHANNELTXNSDU                                                                     STD_ON
#define J1939TP_TXSDUTXNSDUIDXOFTXCHANNELTXNSDU                                                     STD_ON
#define J1939TP_TXCHANNELTXNSDUTXNSDUTABLEIND                                                       STD_ON
#define J1939TP_TXCONFTIMEOUT                                                                       STD_ON
#define J1939TP_TXPDU                                                                               STD_ON
#define J1939TP_HASMETADATAOFTXPDU                                                                  STD_ON
#define J1939TP_INVALIDHNDOFTXPDU                                                                   STD_OFF  /**< the value of J1939Tp_InvalidHndOfTxPdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_METADATAGETTERCAN_ID_32IDXOFTXPDU                                                   STD_ON
#define J1939TP_METADATAGETTERCAN_ID_32USEDOFTXPDU                                                  STD_ON
#define J1939TP_METADATASETTERCAN_ID_32IDXOFTXPDU                                                   STD_ON
#define J1939TP_METADATASETTERCAN_ID_32USEDOFTXPDU                                                  STD_ON
#define J1939TP_ONISOBUSOFTXPDU                                                                     STD_OFF  /**< the value of J1939Tp_OnIsobusOfTxPdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_PDUIDOFTXPDU                                                                        STD_ON
#define J1939TP_PDUTYPEOFTXPDU                                                                      STD_ON
#define J1939TP_TXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFTXPDU                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_TXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFTXPDU                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_TXPDURXCHANNELRXCHANNELTABLEINDUSEDOFTXPDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_TXPDUSTATEIDXOFTXPDU                                                                STD_ON
#define J1939TP_TXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFTXPDU                                        STD_ON
#define J1939TP_TXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFTXPDU                                      STD_ON
#define J1939TP_TXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFTXPDU                                          STD_ON
#define J1939TP_TXPDURXCHANNEL                                                                      STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define J1939TP_RXCHANNELRXCHANNELIDXOFTXPDURXCHANNEL                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_TXPDURXCHANNELRXCHANNELTABLEIND                                                     STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_TXPDUSTATE                                                                          STD_ON
#define J1939TP_TXPDUTXCHANNEL                                                                      STD_ON
#define J1939TP_TXCHANNELTXCHANNELIDXOFTXPDUTXCHANNEL                                               STD_ON
#define J1939TP_TXPDUTXCHANNELTXCHANNELTABLEIND                                                     STD_ON
#define J1939TP_TXSDU                                                                               STD_ON
#define J1939TP_DIRECTPRIORITYOFTXSDU                                                               STD_ON
#define J1939TP_FPPTXSDUSEQUENCECOUNTERIDXOFTXSDU                                                   STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_FPPTXSDUSEQUENCECOUNTERUSEDOFTXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_HASMETADATADAOFTXSDU                                                                STD_ON
#define J1939TP_HASMETADATAOFTXSDU                                                                  STD_ON
#define J1939TP_HASMETADATAPRIOOFTXSDU                                                              STD_OFF  /**< the value of J1939Tp_HasMetaDataPrioOfTxSdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_HASMETADATASAOFTXSDU                                                                STD_OFF  /**< the value of J1939Tp_HasMetaDataSaOfTxSdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_INVALIDHNDOFTXSDU                                                                   STD_OFF  /**< the value of J1939Tp_InvalidHndOfTxSdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_ISDIRECTPRIOCONFIGUREDOFTXSDU                                                       STD_ON
#define J1939TP_ISVARIABLEOFTXSDU                                                                   STD_ON
#define J1939TP_METADATAGETTERPRIORITY_8IDXOFTXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERPRIORITY_8USEDOFTXSDU                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16IDXOFTXSDU                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16USEDOFTXSDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16IDXOFTXSDU                                           STD_ON
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16USEDOFTXSDU                                          STD_ON
#define J1939TP_METADATASETTERPRIORITY_8IDXOFTXSDU                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERPRIORITY_8USEDOFTXSDU                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16IDXOFTXSDU                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16USEDOFTXSDU                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_METADATASETTERTARGET_ADDRESS_16IDXOFTXSDU                                           STD_ON
#define J1939TP_METADATASETTERTARGET_ADDRESS_16USEDOFTXSDU                                          STD_ON
#define J1939TP_PGNOFTXSDU                                                                          STD_ON
#define J1939TP_PDUFORMATOFTXSDU                                                                    STD_ON
#define J1939TP_PDULENGTHOFTXSDU                                                                    STD_ON
#define J1939TP_SDUIDOFTXSDU                                                                        STD_ON
#define J1939TP_TXCHANNELCHANNELIDXOFTXSDU                                                          STD_ON
#define J1939TP_TXCHANNELCHANNELUSEDOFTXSDU                                                         STD_ON
#define J1939TP_TXPDUDIRECTFDBCNPDUIDXOFTXSDU                                                       STD_OFF  /**< the value of J1939Tp_TxPduDirectFdBcNPduIdxOfTxSdu is always 'J1939TP_NO_TXPDUDIRECTFDBCNPDUIDXOFTXSDU' due to this, the array is deactivated. */
#define J1939TP_TXPDUDIRECTFDBCNPDUUSEDOFTXSDU                                                      STD_OFF  /**< the value of J1939Tp_TxPduDirectFdBcNPduUsedOfTxSdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPDUDIRECTFDNPDUIDXOFTXSDU                                                         STD_OFF  /**< the value of J1939Tp_TxPduDirectFdNPduIdxOfTxSdu is always 'J1939TP_NO_TXPDUDIRECTFDNPDUIDXOFTXSDU' due to this, the array is deactivated. */
#define J1939TP_TXPDUDIRECTFDNPDUUSEDOFTXSDU                                                        STD_OFF  /**< the value of J1939Tp_TxPduDirectFdNPduUsedOfTxSdu is always 'false' due to this, the array is deactivated. */
#define J1939TP_TXPDUDIRECTNPDUIDXOFTXSDU                                                           STD_ON
#define J1939TP_TXPDUDIRECTNPDUUSEDOFTXSDU                                                          STD_ON
#define J1939TP_TXSDUSTATEIDXOFTXSDU                                                                STD_ON
#define J1939TP_TXSDUSTATE                                                                          STD_ON
#define J1939TP_PCCONFIG                                                                            STD_ON
#define J1939TP_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< the module configuration does not support flashing of data. */
#define J1939TP_FPPRXSDUSEQUENCECOUNTEROFPCCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_FPPTXSDUSEQUENCECOUNTEROFPCCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< the module configuration does not support flashing of data. */
#define J1939TP_MAINPERIODOFPCCONFIG                                                                STD_ON
#define J1939TP_METADATAGETTERCAN_ID_32OFPCCONFIG                                                   STD_ON
#define J1939TP_METADATAGETTERPRIORITY_8OFPCCONFIG                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_METADATAGETTERSOURCE_ADDRESS_16OFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                           STD_ON
#define J1939TP_METADATASETTERCAN_ID_32OFPCCONFIG                                                   STD_ON
#define J1939TP_METADATASETTERPRIORITY_8OFPCCONFIG                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_METADATASETTERSOURCE_ADDRESS_16OFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                           STD_ON
#define J1939TP_RXCHANNELOFPCCONFIG                                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXCHANNELRXNSDUOFPCCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXCHANNELRXNSDURXNSDUTABLEINDOFPCCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDUDAPRIOOFPCCONFIG                                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDUOFPCCONFIG                                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELOFPCCONFIG                                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDURXSDUOFPCCONFIG                                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDURXSDURXSDUTABLEINDOFPCCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDUSAOFPCCONFIG                                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDUTXCHANNELOFPCCONFIG                                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXSDUOFPCCONFIG                                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_RXSDUSTATEOFPCCONFIG                                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_SIZEOFFPPRXSDUSEQUENCECOUNTEROFPCCONFIG                                             STD_ON
#define J1939TP_SIZEOFFPPTXSDUSEQUENCECOUNTEROFPCCONFIG                                             STD_ON
#define J1939TP_SIZEOFMETADATAGETTERCAN_ID_32OFPCCONFIG                                             STD_ON
#define J1939TP_SIZEOFMETADATAGETTERPRIORITY_8OFPCCONFIG                                            STD_ON
#define J1939TP_SIZEOFMETADATAGETTERSOURCE_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFMETADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFMETADATASETTERCAN_ID_32OFPCCONFIG                                             STD_ON
#define J1939TP_SIZEOFMETADATASETTERPRIORITY_8OFPCCONFIG                                            STD_ON
#define J1939TP_SIZEOFMETADATASETTERSOURCE_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFMETADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFRXCHANNELOFPCCONFIG                                                           STD_ON
#define J1939TP_SIZEOFRXCHANNELRXNSDUOFPCCONFIG                                                     STD_ON
#define J1939TP_SIZEOFRXCHANNELRXNSDURXNSDUTABLEINDOFPCCONFIG                                       STD_ON
#define J1939TP_SIZEOFRXPDUDAPRIOOFPCCONFIG                                                         STD_ON
#define J1939TP_SIZEOFRXPDUOFPCCONFIG                                                               STD_ON
#define J1939TP_SIZEOFRXPDURXCHANNELOFPCCONFIG                                                      STD_ON
#define J1939TP_SIZEOFRXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFRXPDURXSDUOFPCCONFIG                                                          STD_ON
#define J1939TP_SIZEOFRXPDURXSDURXSDUTABLEINDOFPCCONFIG                                             STD_ON
#define J1939TP_SIZEOFRXPDUSAOFPCCONFIG                                                             STD_ON
#define J1939TP_SIZEOFRXPDUTXCHANNELOFPCCONFIG                                                      STD_ON
#define J1939TP_SIZEOFRXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFRXSDUOFPCCONFIG                                                               STD_ON
#define J1939TP_SIZEOFRXSDUSTATEOFPCCONFIG                                                          STD_ON
#define J1939TP_SIZEOFTXCHANNELOFPCCONFIG                                                           STD_ON
#define J1939TP_SIZEOFTXCHANNELTXNSDUOFPCCONFIG                                                     STD_ON
#define J1939TP_SIZEOFTXCHANNELTXNSDUTXNSDUTABLEINDOFPCCONFIG                                       STD_ON
#define J1939TP_SIZEOFTXPDUOFPCCONFIG                                                               STD_ON
#define J1939TP_SIZEOFTXPDURXCHANNELOFPCCONFIG                                                      STD_ON
#define J1939TP_SIZEOFTXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFTXPDUSTATEOFPCCONFIG                                                          STD_ON
#define J1939TP_SIZEOFTXPDUTXCHANNELOFPCCONFIG                                                      STD_ON
#define J1939TP_SIZEOFTXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                     STD_ON
#define J1939TP_SIZEOFTXSDUOFPCCONFIG                                                               STD_ON
#define J1939TP_SIZEOFTXSDUSTATEOFPCCONFIG                                                          STD_ON
#define J1939TP_TIME_FPOFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_T1OFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_T2OFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_T3OFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_T4OFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_T5OFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_THOFPCCONFIG                                                                   STD_ON
#define J1939TP_TIME_TROFPCCONFIG                                                                   STD_ON
#define J1939TP_TXCHANNELOFPCCONFIG                                                                 STD_ON
#define J1939TP_TXCHANNELTXNSDUOFPCCONFIG                                                           STD_ON
#define J1939TP_TXCHANNELTXNSDUTXNSDUTABLEINDOFPCCONFIG                                             STD_ON
#define J1939TP_TXCONFTIMEOUTOFPCCONFIG                                                             STD_ON
#define J1939TP_TXPDUOFPCCONFIG                                                                     STD_ON
#define J1939TP_TXPDURXCHANNELOFPCCONFIG                                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_TXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define J1939TP_TXPDUSTATEOFPCCONFIG                                                                STD_ON
#define J1939TP_TXPDUTXCHANNELOFPCCONFIG                                                            STD_ON
#define J1939TP_TXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                           STD_ON
#define J1939TP_TXSDUOFPCCONFIG                                                                     STD_ON
#define J1939TP_TXSDUSTATEOFPCCONFIG                                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCMinNumericValueDefines  J1939Tp Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define J1939TP_MIN_FPPRXSDUSEQUENCECOUNTER                                                         0u
#define J1939TP_MIN_FPPTXSDUSEQUENCECOUNTER                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCMaxNumericValueDefines  J1939Tp Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define J1939TP_MAX_FPPRXSDUSEQUENCECOUNTER                                                         255u
#define J1939TP_MAX_FPPTXSDUSEQUENCECOUNTER                                                         255u
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCNoReferenceDefines  J1939Tp No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define J1939TP_NO_RXCHANNELRXNSDURXNSDUTABLEINDENDIDXOFRXCHANNEL                                   255u
#define J1939TP_NO_RXCHANNELRXNSDURXNSDUTABLEINDSTARTIDXOFRXCHANNEL                                 255u
#define J1939TP_NO_TXPDUFDRXFCNPDUIDXOFRXCHANNEL                                                    255u
#define J1939TP_NO_TXPDURXETPFCNPDUIDXOFRXCHANNEL                                                   255u
#define J1939TP_NO_TXPDURXFCNPDUIDXOFRXCHANNEL                                                      255u
#define J1939TP_NO_METADATAGETTERCAN_ID_32IDXOFRXPDU                                                255u
#define J1939TP_NO_METADATASETTERCAN_ID_32IDXOFRXPDU                                                255u
#define J1939TP_NO_RXPDUDAPRIOIDXOFRXPDU                                                            255u
#define J1939TP_NO_RXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFRXPDU                                     255u
#define J1939TP_NO_RXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFRXPDU                                   255u
#define J1939TP_NO_RXPDURXSDURXSDUTABLEINDENDIDXOFRXPDU                                             255u
#define J1939TP_NO_RXPDURXSDURXSDUTABLEINDSTARTIDXOFRXPDU                                           255u
#define J1939TP_NO_RXPDUSAIDXOFRXPDU                                                                255u
#define J1939TP_NO_RXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFRXPDU                                     255u
#define J1939TP_NO_RXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFRXPDU                                   255u
#define J1939TP_NO_RXPDUDAOFRXPDUDAPRIO                                                             255u
#define J1939TP_NO_RXPDUPRIOOFRXPDUDAPRIO                                                           255u
#define J1939TP_NO_RXPDUSA                                                                          255u
#define J1939TP_NO_FPPRXSDUSEQUENCECOUNTERIDXOFRXSDU                                                255u
#define J1939TP_NO_METADATAGETTERPRIORITY_8IDXOFRXSDU                                               255u
#define J1939TP_NO_METADATAGETTERSOURCE_ADDRESS_16IDXOFRXSDU                                        255u
#define J1939TP_NO_METADATAGETTERTARGET_ADDRESS_16IDXOFRXSDU                                        255u
#define J1939TP_NO_METADATASETTERPRIORITY_8IDXOFRXSDU                                               255u
#define J1939TP_NO_METADATASETTERSOURCE_ADDRESS_16IDXOFRXSDU                                        255u
#define J1939TP_NO_METADATASETTERTARGET_ADDRESS_16IDXOFRXSDU                                        255u
#define J1939TP_NO_RXCHANNELCHANNELIDXOFRXSDU                                                       255u
#define J1939TP_NO_SDUIDOFRXSDU                                                                     255u
#define J1939TP_NO_TXCHANNELTXNSDUTXNSDUTABLEINDENDIDXOFTXCHANNEL                                   255u
#define J1939TP_NO_TXCHANNELTXNSDUTXNSDUTABLEINDSTARTIDXOFTXCHANNEL                                 255u
#define J1939TP_NO_TXPDUFDTXCMNPDUIDXOFTXCHANNEL                                                    255u
#define J1939TP_NO_TXPDUFDTXDTNPDUIDXOFTXCHANNEL                                                    255u
#define J1939TP_NO_TXPDUTXCMNPDUIDXOFTXCHANNEL                                                      255u
#define J1939TP_NO_TXPDUTXDTNPDUIDXOFTXCHANNEL                                                      255u
#define J1939TP_NO_TXPDUTXETPCMNPDUIDXOFTXCHANNEL                                                   255u
#define J1939TP_NO_TXPDUTXETPDTNPDUIDXOFTXCHANNEL                                                   255u
#define J1939TP_NO_METADATAGETTERCAN_ID_32IDXOFTXPDU                                                255u
#define J1939TP_NO_METADATASETTERCAN_ID_32IDXOFTXPDU                                                255u
#define J1939TP_NO_PDUIDOFTXPDU                                                                     255u
#define J1939TP_NO_TXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFTXPDU                                     255u
#define J1939TP_NO_TXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFTXPDU                                   255u
#define J1939TP_NO_TXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFTXPDU                                     255u
#define J1939TP_NO_TXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFTXPDU                                   255u
#define J1939TP_NO_FPPTXSDUSEQUENCECOUNTERIDXOFTXSDU                                                255u
#define J1939TP_NO_METADATAGETTERPRIORITY_8IDXOFTXSDU                                               255u
#define J1939TP_NO_METADATAGETTERSOURCE_ADDRESS_16IDXOFTXSDU                                        255u
#define J1939TP_NO_METADATAGETTERTARGET_ADDRESS_16IDXOFTXSDU                                        255u
#define J1939TP_NO_METADATASETTERPRIORITY_8IDXOFTXSDU                                               255u
#define J1939TP_NO_METADATASETTERSOURCE_ADDRESS_16IDXOFTXSDU                                        255u
#define J1939TP_NO_METADATASETTERTARGET_ADDRESS_16IDXOFTXSDU                                        255u
#define J1939TP_NO_SDUIDOFTXSDU                                                                     255u
#define J1939TP_NO_TXCHANNELCHANNELIDXOFTXSDU                                                       255u
#define J1939TP_NO_TXPDUDIRECTFDBCNPDUIDXOFTXSDU                                                    255u
#define J1939TP_NO_TXPDUDIRECTFDNPDUIDXOFTXSDU                                                      255u
#define J1939TP_NO_TXPDUDIRECTNPDUIDXOFTXSDU                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCEnumExistsDefines  J1939Tp Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define J1939TP_EXISTS_PROTOCOL_UNUSED_RXPROTOCOLTYPEOFRXCHANNEL                                    STD_OFF
#define J1939TP_EXISTS_PROTOCOL_BAM_RXPROTOCOLTYPEOFRXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_PROTOCOL_CMDT_RXPROTOCOLTYPEOFRXCHANNEL                                      STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FD_BAM_RXPROTOCOLTYPEOFRXCHANNEL                                    STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FD_CMDT_RXPROTOCOLTYPEOFRXCHANNEL                                   STD_OFF
#define J1939TP_EXISTS_PROTOCOL_ETP_RXPROTOCOLTYPEOFRXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FPP_RXPROTOCOLTYPEOFRXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_UNDEFINED_PDUFORMATOFRXPDU                                                   STD_OFF
#define J1939TP_EXISTS_PDU1_PDUFORMATOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_PDU2_PDUFORMATOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_UNUSED_PDUTYPEOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_DIRECT_PDUTYPEOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_FDDIRECT_PDUTYPEOFRXPDU                                                      STD_OFF
#define J1939TP_EXISTS_FDDIRECTBC_PDUTYPEOFRXPDU                                                    STD_OFF
#define J1939TP_EXISTS_TPCM_PDUTYPEOFRXPDU                                                          STD_OFF
#define J1939TP_EXISTS_TPDT_PDUTYPEOFRXPDU                                                          STD_OFF
#define J1939TP_EXISTS_FDTPCM_PDUTYPEOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_FDTPDT_PDUTYPEOFRXPDU                                                        STD_OFF
#define J1939TP_EXISTS_ETPCM_PDUTYPEOFRXPDU                                                         STD_OFF
#define J1939TP_EXISTS_ETPDT_PDUTYPEOFRXPDU                                                         STD_OFF
#define J1939TP_EXISTS_FPP_PDUTYPEOFRXPDU                                                           STD_OFF
#define J1939TP_EXISTS_PROTOCOL_UNUSED_TXPROTOCOLTYPEOFTXCHANNEL                                    STD_ON
#define J1939TP_EXISTS_PROTOCOL_BAM_TXPROTOCOLTYPEOFTXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_PROTOCOL_CMDT_TXPROTOCOLTYPEOFTXCHANNEL                                      STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FD_BAM_TXPROTOCOLTYPEOFTXCHANNEL                                    STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FD_CMDT_TXPROTOCOLTYPEOFTXCHANNEL                                   STD_OFF
#define J1939TP_EXISTS_PROTOCOL_ETP_TXPROTOCOLTYPEOFTXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_PROTOCOL_FPP_TXPROTOCOLTYPEOFTXCHANNEL                                       STD_OFF
#define J1939TP_EXISTS_UNUSED_PDUTYPEOFTXPDU                                                        STD_OFF
#define J1939TP_EXISTS_DIRECT_PDUTYPEOFTXPDU                                                        STD_ON
#define J1939TP_EXISTS_FDDIRECT_PDUTYPEOFTXPDU                                                      STD_OFF
#define J1939TP_EXISTS_FDDIRECTBC_PDUTYPEOFTXPDU                                                    STD_OFF
#define J1939TP_EXISTS_TPCM_PDUTYPEOFTXPDU                                                          STD_ON
#define J1939TP_EXISTS_TPDT_PDUTYPEOFTXPDU                                                          STD_ON
#define J1939TP_EXISTS_FDTPCM_PDUTYPEOFTXPDU                                                        STD_OFF
#define J1939TP_EXISTS_FDTPDT_PDUTYPEOFTXPDU                                                        STD_OFF
#define J1939TP_EXISTS_ETPCM_PDUTYPEOFTXPDU                                                         STD_OFF
#define J1939TP_EXISTS_ETPDT_PDUTYPEOFTXPDU                                                         STD_OFF
#define J1939TP_EXISTS_FPP_PDUTYPEOFTXPDU                                                           STD_OFF
#define J1939TP_EXISTS_UNDEFINED_PDUFORMATOFTXSDU                                                   STD_OFF
#define J1939TP_EXISTS_PDU1_PDUFORMATOFTXSDU                                                        STD_OFF
#define J1939TP_EXISTS_PDU2_PDUFORMATOFTXSDU                                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCEnumDefines  J1939Tp Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define J1939TP_PROTOCOL_UNUSED_RXPROTOCOLTYPEOFRXCHANNEL                                           0x00u
#define J1939TP_PROTOCOL_BAM_RXPROTOCOLTYPEOFRXCHANNEL                                              0x01u
#define J1939TP_PROTOCOL_CMDT_RXPROTOCOLTYPEOFRXCHANNEL                                             0x02u
#define J1939TP_PROTOCOL_FD_BAM_RXPROTOCOLTYPEOFRXCHANNEL                                           0x03u
#define J1939TP_PROTOCOL_FD_CMDT_RXPROTOCOLTYPEOFRXCHANNEL                                          0x04u
#define J1939TP_PROTOCOL_ETP_RXPROTOCOLTYPEOFRXCHANNEL                                              0x05u
#define J1939TP_PROTOCOL_FPP_RXPROTOCOLTYPEOFRXCHANNEL                                              0x06u
#define J1939TP_UNDEFINED_PDUFORMATOFRXPDU                                                          0x00u
#define J1939TP_PDU1_PDUFORMATOFRXPDU                                                               0x01u
#define J1939TP_PDU2_PDUFORMATOFRXPDU                                                               0x02u
#define J1939TP_UNUSED_PDUTYPEOFRXPDU                                                               0x00u
#define J1939TP_DIRECT_PDUTYPEOFRXPDU                                                               0x01u
#define J1939TP_FDDIRECT_PDUTYPEOFRXPDU                                                             0x02u
#define J1939TP_FDDIRECTBC_PDUTYPEOFRXPDU                                                           0x03u
#define J1939TP_TPCM_PDUTYPEOFRXPDU                                                                 0x04u
#define J1939TP_TPDT_PDUTYPEOFRXPDU                                                                 0x05u
#define J1939TP_FDTPCM_PDUTYPEOFRXPDU                                                               0x06u
#define J1939TP_FDTPDT_PDUTYPEOFRXPDU                                                               0x07u
#define J1939TP_ETPCM_PDUTYPEOFRXPDU                                                                0x08u
#define J1939TP_ETPDT_PDUTYPEOFRXPDU                                                                0x09u
#define J1939TP_FPP_PDUTYPEOFRXPDU                                                                  0x0Au
#define J1939TP_PROTOCOL_UNUSED_TXPROTOCOLTYPEOFTXCHANNEL                                           0x00u
#define J1939TP_PROTOCOL_BAM_TXPROTOCOLTYPEOFTXCHANNEL                                              0x01u
#define J1939TP_PROTOCOL_CMDT_TXPROTOCOLTYPEOFTXCHANNEL                                             0x02u
#define J1939TP_PROTOCOL_FD_BAM_TXPROTOCOLTYPEOFTXCHANNEL                                           0x03u
#define J1939TP_PROTOCOL_FD_CMDT_TXPROTOCOLTYPEOFTXCHANNEL                                          0x04u
#define J1939TP_PROTOCOL_ETP_TXPROTOCOLTYPEOFTXCHANNEL                                              0x05u
#define J1939TP_PROTOCOL_FPP_TXPROTOCOLTYPEOFTXCHANNEL                                              0x06u
#define J1939TP_UNUSED_PDUTYPEOFTXPDU                                                               0x00u
#define J1939TP_DIRECT_PDUTYPEOFTXPDU                                                               0x01u
#define J1939TP_FDDIRECT_PDUTYPEOFTXPDU                                                             0x02u
#define J1939TP_FDDIRECTBC_PDUTYPEOFTXPDU                                                           0x03u
#define J1939TP_TPCM_PDUTYPEOFTXPDU                                                                 0x04u
#define J1939TP_TPDT_PDUTYPEOFTXPDU                                                                 0x05u
#define J1939TP_FDTPCM_PDUTYPEOFTXPDU                                                               0x06u
#define J1939TP_FDTPDT_PDUTYPEOFTXPDU                                                               0x07u
#define J1939TP_ETPCM_PDUTYPEOFTXPDU                                                                0x08u
#define J1939TP_ETPDT_PDUTYPEOFTXPDU                                                                0x09u
#define J1939TP_FPP_PDUTYPEOFTXPDU                                                                  0x0Au
#define J1939TP_UNDEFINED_PDUFORMATOFTXSDU                                                          0x00u
#define J1939TP_PDU1_PDUFORMATOFTXSDU                                                               0x01u
#define J1939TP_PDU2_PDUFORMATOFTXSDU                                                               0x02u
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCIsReducedToDefineDefines  J1939Tp Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32                                                       STD_OFF
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8                                                      STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16                                               STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16                                               STD_OFF
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32                                                       STD_OFF
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8                                                      STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16                                               STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16                                               STD_OFF
#define J1939TP_ISDEF_COMMCHANNELOFRXCHANNEL                                                        STD_OFF
#define J1939TP_ISDEF_RXCANFDCHANNELOFRXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_RXCANCELLATIONSUPPORTOFRXCHANNEL                                              STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDURXNSDUTABLEINDENDIDXOFRXCHANNEL                                STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDURXNSDUTABLEINDSTARTIDXOFRXCHANNEL                              STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDURXNSDUTABLEINDUSEDOFRXCHANNEL                                  STD_OFF
#define J1939TP_ISDEF_RXCHANNELUSESMULTIPGOFRXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_RXDAOFRXCHANNEL                                                               STD_OFF
#define J1939TP_ISDEF_RXDYNAMICBLOCKCALCULATIONOFRXCHANNEL                                          STD_OFF
#define J1939TP_ISDEF_RXDYNAMICBUFFERRATIOOFRXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_RXISOBUSCHANNELOFRXCHANNEL                                                    STD_OFF
#define J1939TP_ISDEF_RXPACKETSPERBLOCKOFRXCHANNEL                                                  STD_OFF
#define J1939TP_ISDEF_RXPROTOCOLTYPEOFRXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_RXRETRYSUPPORTOFRXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_RXSAOFRXCHANNEL                                                               STD_OFF
#define J1939TP_ISDEF_TXPDUFDRXFCNPDUIDXOFRXCHANNEL                                                 STD_OFF
#define J1939TP_ISDEF_TXPDUFDRXFCNPDUUSEDOFRXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDURXETPFCNPDUIDXOFRXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDURXETPFCNPDUUSEDOFRXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_TXPDURXFCNPDUIDXOFRXCHANNEL                                                   STD_OFF
#define J1939TP_ISDEF_TXPDURXFCNPDUUSEDOFRXCHANNEL                                                  STD_OFF
#define J1939TP_ISDEF_RXSDURXNSDUIDXOFRXCHANNELRXNSDU                                               STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDURXNSDUTABLEIND                                                 STD_OFF
#define J1939TP_ISDEF_HASMETADATAOFRXPDU                                                            STD_OFF
#define J1939TP_ISDEF_INVALIDHNDOFRXPDU                                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32IDXOFRXPDU                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32USEDOFRXPDU                                            STD_OFF
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32IDXOFRXPDU                                             STD_OFF
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32USEDOFRXPDU                                            STD_OFF
#define J1939TP_ISDEF_ONISOBUSOFRXPDU                                                               STD_OFF
#define J1939TP_ISDEF_PDUFORMATOFRXPDU                                                              STD_OFF
#define J1939TP_ISDEF_PDUTYPEOFRXPDU                                                                STD_OFF
#define J1939TP_ISDEF_RXPDUDAPRIOIDXOFRXPDU                                                         STD_OFF
#define J1939TP_ISDEF_RXPDUDAPRIOUSEDOFRXPDU                                                        STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFRXPDU                                  STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFRXPDU                                STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELRXCHANNELTABLEINDUSEDOFRXPDU                                    STD_OFF
#define J1939TP_ISDEF_RXPDURXSDURXSDUTABLEINDENDIDXOFRXPDU                                          STD_OFF
#define J1939TP_ISDEF_RXPDURXSDURXSDUTABLEINDSTARTIDXOFRXPDU                                        STD_OFF
#define J1939TP_ISDEF_RXPDURXSDURXSDUTABLEINDUSEDOFRXPDU                                            STD_OFF
#define J1939TP_ISDEF_RXPDUSAIDXOFRXPDU                                                             STD_OFF
#define J1939TP_ISDEF_RXPDUSAUSEDOFRXPDU                                                            STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFRXPDU                                  STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFRXPDU                                STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFRXPDU                                    STD_OFF
#define J1939TP_ISDEF_RXPDUDAOFRXPDUDAPRIO                                                          STD_OFF
#define J1939TP_ISDEF_RXPDUPRIOOFRXPDUDAPRIO                                                        STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXCHANNELIDXOFRXPDURXCHANNEL                                         STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELRXCHANNELTABLEIND                                               STD_OFF
#define J1939TP_ISDEF_RXSDURXSDUIDXOFRXPDURXSDU                                                     STD_OFF
#define J1939TP_ISDEF_RXPDURXSDURXSDUTABLEIND                                                       STD_OFF
#define J1939TP_ISDEF_RXPDUSA                                                                       STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXCHANNELIDXOFRXPDUTXCHANNEL                                         STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELTXCHANNELTABLEIND                                               STD_OFF
#define J1939TP_ISDEF_FPPRXSDUSEQUENCECOUNTERIDXOFRXSDU                                             STD_OFF
#define J1939TP_ISDEF_FPPRXSDUSEQUENCECOUNTERUSEDOFRXSDU                                            STD_OFF
#define J1939TP_ISDEF_HASMETADATADAOFRXSDU                                                          STD_OFF
#define J1939TP_ISDEF_HASMETADATAOFRXSDU                                                            STD_OFF
#define J1939TP_ISDEF_HASMETADATAPRIOOFRXSDU                                                        STD_OFF
#define J1939TP_ISDEF_HASMETADATASAOFRXSDU                                                          STD_OFF
#define J1939TP_ISDEF_INVALIDHNDOFRXSDU                                                             STD_OFF
#define J1939TP_ISDEF_ISVARIABLEOFRXSDU                                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8IDXOFRXSDU                                            STD_OFF
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8USEDOFRXSDU                                           STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16IDXOFRXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16USEDOFRXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16IDXOFRXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16USEDOFRXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8IDXOFRXSDU                                            STD_OFF
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8USEDOFRXSDU                                           STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16IDXOFRXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16USEDOFRXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16IDXOFRXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16USEDOFRXSDU                                    STD_OFF
#define J1939TP_ISDEF_PGNOFRXSDU                                                                    STD_OFF
#define J1939TP_ISDEF_PDULENGTHOFRXSDU                                                              STD_OFF
#define J1939TP_ISDEF_RXCHANNELCHANNELIDXOFRXSDU                                                    STD_OFF
#define J1939TP_ISDEF_RXCHANNELCHANNELUSEDOFRXSDU                                                   STD_OFF
#define J1939TP_ISDEF_RXSDUSTATEIDXOFRXSDU                                                          STD_OFF
#define J1939TP_ISDEF_SDUIDOFRXSDU                                                                  STD_OFF
#define J1939TP_ISDEF_COMMCHANNELOFTXCHANNEL                                                        STD_OFF
#define J1939TP_ISDEF_TXBAMINTERFRAMETIMEOFTXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXCANFDCHANNELOFTXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_TXCANCELLATIONSUPPORTOFTXCHANNEL                                              STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXNSDUTXNSDUTABLEINDENDIDXOFTXCHANNEL                                STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXNSDUTXNSDUTABLEINDSTARTIDXOFTXCHANNEL                              STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXNSDUTXNSDUTABLEINDUSEDOFTXCHANNEL                                  STD_OFF
#define J1939TP_ISDEF_TXCHANNELUSESMULTIPGOFTXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_TXDAOFTXCHANNEL                                                               STD_OFF
#define J1939TP_ISDEF_TXDYNAMICBLOCKCALCULATIONOFTXCHANNEL                                          STD_OFF
#define J1939TP_ISDEF_TXISOBUSCHANNELOFTXCHANNEL                                                    STD_OFF
#define J1939TP_ISDEF_TXMAXPACKETSPERBLOCKOFTXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_TXPDUFDTXCMNPDUIDXOFTXCHANNEL                                                 STD_OFF
#define J1939TP_ISDEF_TXPDUFDTXCMNPDUUSEDOFTXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDUFDTXDTNPDUIDXOFTXCHANNEL                                                 STD_OFF
#define J1939TP_ISDEF_TXPDUFDTXDTNPDUUSEDOFTXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDUTXCMNPDUIDXOFTXCHANNEL                                                   STD_OFF
#define J1939TP_ISDEF_TXPDUTXCMNPDUUSEDOFTXCHANNEL                                                  STD_OFF
#define J1939TP_ISDEF_TXPDUTXDTNPDUIDXOFTXCHANNEL                                                   STD_OFF
#define J1939TP_ISDEF_TXPDUTXDTNPDUUSEDOFTXCHANNEL                                                  STD_OFF
#define J1939TP_ISDEF_TXPDUTXETPCMNPDUIDXOFTXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDUTXETPCMNPDUUSEDOFTXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_TXPDUTXETPDTNPDUIDXOFTXCHANNEL                                                STD_OFF
#define J1939TP_ISDEF_TXPDUTXETPDTNPDUUSEDOFTXCHANNEL                                               STD_OFF
#define J1939TP_ISDEF_TXPENDINGSUPPORTOFTXCHANNEL                                                   STD_OFF
#define J1939TP_ISDEF_TXPRIOFTXCHANNEL                                                              STD_OFF
#define J1939TP_ISDEF_TXPROTOCOLTYPEOFTXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_TXRETRYSUPPORTOFTXCHANNEL                                                     STD_OFF
#define J1939TP_ISDEF_TXSAOFTXCHANNEL                                                               STD_OFF
#define J1939TP_ISDEF_TXVARPRIOFTXCHANNEL                                                           STD_OFF
#define J1939TP_ISDEF_TXSDUTXNSDUIDXOFTXCHANNELTXNSDU                                               STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXNSDUTXNSDUTABLEIND                                                 STD_OFF
#define J1939TP_ISDEF_HASMETADATAOFTXPDU                                                            STD_OFF
#define J1939TP_ISDEF_INVALIDHNDOFTXPDU                                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32IDXOFTXPDU                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32USEDOFTXPDU                                            STD_OFF
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32IDXOFTXPDU                                             STD_OFF
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32USEDOFTXPDU                                            STD_OFF
#define J1939TP_ISDEF_ONISOBUSOFTXPDU                                                               STD_OFF
#define J1939TP_ISDEF_PDUIDOFTXPDU                                                                  STD_OFF
#define J1939TP_ISDEF_PDUTYPEOFTXPDU                                                                STD_OFF
#define J1939TP_ISDEF_TXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFTXPDU                                  STD_OFF
#define J1939TP_ISDEF_TXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFTXPDU                                STD_OFF
#define J1939TP_ISDEF_TXPDURXCHANNELRXCHANNELTABLEINDUSEDOFTXPDU                                    STD_OFF
#define J1939TP_ISDEF_TXPDUSTATEIDXOFTXPDU                                                          STD_OFF
#define J1939TP_ISDEF_TXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFTXPDU                                  STD_OFF
#define J1939TP_ISDEF_TXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFTXPDU                                STD_OFF
#define J1939TP_ISDEF_TXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFTXPDU                                    STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXCHANNELIDXOFTXPDURXCHANNEL                                         STD_OFF
#define J1939TP_ISDEF_TXPDURXCHANNELRXCHANNELTABLEIND                                               STD_OFF
#define J1939TP_ISDEF_TXCHANNELTXCHANNELIDXOFTXPDUTXCHANNEL                                         STD_OFF
#define J1939TP_ISDEF_TXPDUTXCHANNELTXCHANNELTABLEIND                                               STD_OFF
#define J1939TP_ISDEF_DIRECTPRIORITYOFTXSDU                                                         STD_OFF
#define J1939TP_ISDEF_FPPTXSDUSEQUENCECOUNTERIDXOFTXSDU                                             STD_OFF
#define J1939TP_ISDEF_FPPTXSDUSEQUENCECOUNTERUSEDOFTXSDU                                            STD_OFF
#define J1939TP_ISDEF_HASMETADATADAOFTXSDU                                                          STD_OFF
#define J1939TP_ISDEF_HASMETADATAOFTXSDU                                                            STD_OFF
#define J1939TP_ISDEF_HASMETADATAPRIOOFTXSDU                                                        STD_OFF
#define J1939TP_ISDEF_HASMETADATASAOFTXSDU                                                          STD_OFF
#define J1939TP_ISDEF_INVALIDHNDOFTXSDU                                                             STD_OFF
#define J1939TP_ISDEF_ISDIRECTPRIOCONFIGUREDOFTXSDU                                                 STD_OFF
#define J1939TP_ISDEF_ISVARIABLEOFTXSDU                                                             STD_OFF
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8IDXOFTXSDU                                            STD_OFF
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8USEDOFTXSDU                                           STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16IDXOFTXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16USEDOFTXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16IDXOFTXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16USEDOFTXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8IDXOFTXSDU                                            STD_OFF
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8USEDOFTXSDU                                           STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16IDXOFTXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16USEDOFTXSDU                                    STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16IDXOFTXSDU                                     STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16USEDOFTXSDU                                    STD_OFF
#define J1939TP_ISDEF_PGNOFTXSDU                                                                    STD_OFF
#define J1939TP_ISDEF_PDUFORMATOFTXSDU                                                              STD_OFF
#define J1939TP_ISDEF_PDULENGTHOFTXSDU                                                              STD_OFF
#define J1939TP_ISDEF_SDUIDOFTXSDU                                                                  STD_OFF
#define J1939TP_ISDEF_TXCHANNELCHANNELIDXOFTXSDU                                                    STD_OFF
#define J1939TP_ISDEF_TXCHANNELCHANNELUSEDOFTXSDU                                                   STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTFDBCNPDUIDXOFTXSDU                                                 STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTFDBCNPDUUSEDOFTXSDU                                                STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTFDNPDUIDXOFTXSDU                                                   STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTFDNPDUUSEDOFTXSDU                                                  STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTNPDUIDXOFTXSDU                                                     STD_OFF
#define J1939TP_ISDEF_TXPDUDIRECTNPDUUSEDOFTXSDU                                                    STD_OFF
#define J1939TP_ISDEF_TXSDUSTATEIDXOFTXSDU                                                          STD_OFF
#define J1939TP_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                    STD_OFF
#define J1939TP_ISDEF_FPPRXSDUSEQUENCECOUNTEROFPCCONFIG                                             STD_OFF
#define J1939TP_ISDEF_FPPTXSDUSEQUENCECOUNTEROFPCCONFIG                                             STD_OFF
#define J1939TP_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                    STD_OFF
#define J1939TP_ISDEF_METADATAGETTERCAN_ID_32OFPCCONFIG                                             STD_ON
#define J1939TP_ISDEF_METADATAGETTERPRIORITY_8OFPCCONFIG                                            STD_OFF
#define J1939TP_ISDEF_METADATAGETTERSOURCE_ADDRESS_16OFPCCONFIG                                     STD_OFF
#define J1939TP_ISDEF_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_ISDEF_METADATASETTERCAN_ID_32OFPCCONFIG                                             STD_ON
#define J1939TP_ISDEF_METADATASETTERPRIORITY_8OFPCCONFIG                                            STD_OFF
#define J1939TP_ISDEF_METADATASETTERSOURCE_ADDRESS_16OFPCCONFIG                                     STD_OFF
#define J1939TP_ISDEF_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                     STD_ON
#define J1939TP_ISDEF_RXCHANNELOFPCCONFIG                                                           STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDUOFPCCONFIG                                                     STD_OFF
#define J1939TP_ISDEF_RXCHANNELRXNSDURXNSDUTABLEINDOFPCCONFIG                                       STD_OFF
#define J1939TP_ISDEF_RXPDUDAPRIOOFPCCONFIG                                                         STD_OFF
#define J1939TP_ISDEF_RXPDUOFPCCONFIG                                                               STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELOFPCCONFIG                                                      STD_OFF
#define J1939TP_ISDEF_RXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                     STD_OFF
#define J1939TP_ISDEF_RXPDURXSDUOFPCCONFIG                                                          STD_OFF
#define J1939TP_ISDEF_RXPDURXSDURXSDUTABLEINDOFPCCONFIG                                             STD_OFF
#define J1939TP_ISDEF_RXPDUSAOFPCCONFIG                                                             STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELOFPCCONFIG                                                      STD_OFF
#define J1939TP_ISDEF_RXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                     STD_OFF
#define J1939TP_ISDEF_RXSDUOFPCCONFIG                                                               STD_OFF
#define J1939TP_ISDEF_RXSDUSTATEOFPCCONFIG                                                          STD_OFF
#define J1939TP_ISDEF_TXCHANNELOFPCCONFIG                                                           STD_ON
#define J1939TP_ISDEF_TXCHANNELTXNSDUOFPCCONFIG                                                     STD_ON
#define J1939TP_ISDEF_TXCHANNELTXNSDUTXNSDUTABLEINDOFPCCONFIG                                       STD_ON
#define J1939TP_ISDEF_TXPDUOFPCCONFIG                                                               STD_ON
#define J1939TP_ISDEF_TXPDURXCHANNELOFPCCONFIG                                                      STD_OFF
#define J1939TP_ISDEF_TXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                     STD_OFF
#define J1939TP_ISDEF_TXPDUSTATEOFPCCONFIG                                                          STD_ON
#define J1939TP_ISDEF_TXPDUTXCHANNELOFPCCONFIG                                                      STD_ON
#define J1939TP_ISDEF_TXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                     STD_ON
#define J1939TP_ISDEF_TXSDUOFPCCONFIG                                                               STD_ON
#define J1939TP_ISDEF_TXSDUSTATEOFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCEqualsAlwaysToDefines  J1939Tp Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32                                                         
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8                                                        
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16                                                 
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16                                                 
#define J1939TP_EQ2_METADATASETTERCAN_ID_32                                                         
#define J1939TP_EQ2_METADATASETTERPRIORITY_8                                                        
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16                                                 
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16                                                 
#define J1939TP_EQ2_COMMCHANNELOFRXCHANNEL                                                          
#define J1939TP_EQ2_RXCANFDCHANNELOFRXCHANNEL                                                       
#define J1939TP_EQ2_RXCANCELLATIONSUPPORTOFRXCHANNEL                                                
#define J1939TP_EQ2_RXCHANNELRXNSDURXNSDUTABLEINDENDIDXOFRXCHANNEL                                  
#define J1939TP_EQ2_RXCHANNELRXNSDURXNSDUTABLEINDSTARTIDXOFRXCHANNEL                                
#define J1939TP_EQ2_RXCHANNELRXNSDURXNSDUTABLEINDUSEDOFRXCHANNEL                                    
#define J1939TP_EQ2_RXCHANNELUSESMULTIPGOFRXCHANNEL                                                 
#define J1939TP_EQ2_RXDAOFRXCHANNEL                                                                 
#define J1939TP_EQ2_RXDYNAMICBLOCKCALCULATIONOFRXCHANNEL                                            
#define J1939TP_EQ2_RXDYNAMICBUFFERRATIOOFRXCHANNEL                                                 
#define J1939TP_EQ2_RXISOBUSCHANNELOFRXCHANNEL                                                      
#define J1939TP_EQ2_RXPACKETSPERBLOCKOFRXCHANNEL                                                    
#define J1939TP_EQ2_RXPROTOCOLTYPEOFRXCHANNEL                                                       
#define J1939TP_EQ2_RXRETRYSUPPORTOFRXCHANNEL                                                       
#define J1939TP_EQ2_RXSAOFRXCHANNEL                                                                 
#define J1939TP_EQ2_TXPDUFDRXFCNPDUIDXOFRXCHANNEL                                                   
#define J1939TP_EQ2_TXPDUFDRXFCNPDUUSEDOFRXCHANNEL                                                  
#define J1939TP_EQ2_TXPDURXETPFCNPDUIDXOFRXCHANNEL                                                  
#define J1939TP_EQ2_TXPDURXETPFCNPDUUSEDOFRXCHANNEL                                                 
#define J1939TP_EQ2_TXPDURXFCNPDUIDXOFRXCHANNEL                                                     
#define J1939TP_EQ2_TXPDURXFCNPDUUSEDOFRXCHANNEL                                                    
#define J1939TP_EQ2_RXSDURXNSDUIDXOFRXCHANNELRXNSDU                                                 
#define J1939TP_EQ2_RXCHANNELRXNSDURXNSDUTABLEIND                                                   
#define J1939TP_EQ2_HASMETADATAOFRXPDU                                                              
#define J1939TP_EQ2_INVALIDHNDOFRXPDU                                                               
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32IDXOFRXPDU                                               
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32USEDOFRXPDU                                              
#define J1939TP_EQ2_METADATASETTERCAN_ID_32IDXOFRXPDU                                               
#define J1939TP_EQ2_METADATASETTERCAN_ID_32USEDOFRXPDU                                              
#define J1939TP_EQ2_ONISOBUSOFRXPDU                                                                 
#define J1939TP_EQ2_PDUFORMATOFRXPDU                                                                
#define J1939TP_EQ2_PDUTYPEOFRXPDU                                                                  
#define J1939TP_EQ2_RXPDUDAPRIOIDXOFRXPDU                                                           
#define J1939TP_EQ2_RXPDUDAPRIOUSEDOFRXPDU                                                          
#define J1939TP_EQ2_RXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFRXPDU                                    
#define J1939TP_EQ2_RXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFRXPDU                                  
#define J1939TP_EQ2_RXPDURXCHANNELRXCHANNELTABLEINDUSEDOFRXPDU                                      
#define J1939TP_EQ2_RXPDURXSDURXSDUTABLEINDENDIDXOFRXPDU                                            
#define J1939TP_EQ2_RXPDURXSDURXSDUTABLEINDSTARTIDXOFRXPDU                                          
#define J1939TP_EQ2_RXPDURXSDURXSDUTABLEINDUSEDOFRXPDU                                              
#define J1939TP_EQ2_RXPDUSAIDXOFRXPDU                                                               
#define J1939TP_EQ2_RXPDUSAUSEDOFRXPDU                                                              
#define J1939TP_EQ2_RXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFRXPDU                                    
#define J1939TP_EQ2_RXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFRXPDU                                  
#define J1939TP_EQ2_RXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFRXPDU                                      
#define J1939TP_EQ2_RXPDUDAOFRXPDUDAPRIO                                                            
#define J1939TP_EQ2_RXPDUPRIOOFRXPDUDAPRIO                                                          
#define J1939TP_EQ2_RXCHANNELRXCHANNELIDXOFRXPDURXCHANNEL                                           
#define J1939TP_EQ2_RXPDURXCHANNELRXCHANNELTABLEIND                                                 
#define J1939TP_EQ2_RXSDURXSDUIDXOFRXPDURXSDU                                                       
#define J1939TP_EQ2_RXPDURXSDURXSDUTABLEIND                                                         
#define J1939TP_EQ2_RXPDUSA                                                                         
#define J1939TP_EQ2_TXCHANNELTXCHANNELIDXOFRXPDUTXCHANNEL                                           
#define J1939TP_EQ2_RXPDUTXCHANNELTXCHANNELTABLEIND                                                 
#define J1939TP_EQ2_FPPRXSDUSEQUENCECOUNTERIDXOFRXSDU                                               
#define J1939TP_EQ2_FPPRXSDUSEQUENCECOUNTERUSEDOFRXSDU                                              
#define J1939TP_EQ2_HASMETADATADAOFRXSDU                                                            
#define J1939TP_EQ2_HASMETADATAOFRXSDU                                                              
#define J1939TP_EQ2_HASMETADATAPRIOOFRXSDU                                                          
#define J1939TP_EQ2_HASMETADATASAOFRXSDU                                                            
#define J1939TP_EQ2_INVALIDHNDOFRXSDU                                                               
#define J1939TP_EQ2_ISVARIABLEOFRXSDU                                                               
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8IDXOFRXSDU                                              
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8USEDOFRXSDU                                             
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16IDXOFRXSDU                                       
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16USEDOFRXSDU                                      
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16IDXOFRXSDU                                       
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16USEDOFRXSDU                                      
#define J1939TP_EQ2_METADATASETTERPRIORITY_8IDXOFRXSDU                                              
#define J1939TP_EQ2_METADATASETTERPRIORITY_8USEDOFRXSDU                                             
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16IDXOFRXSDU                                       
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16USEDOFRXSDU                                      
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16IDXOFRXSDU                                       
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16USEDOFRXSDU                                      
#define J1939TP_EQ2_PGNOFRXSDU                                                                      
#define J1939TP_EQ2_PDULENGTHOFRXSDU                                                                
#define J1939TP_EQ2_RXCHANNELCHANNELIDXOFRXSDU                                                      
#define J1939TP_EQ2_RXCHANNELCHANNELUSEDOFRXSDU                                                     
#define J1939TP_EQ2_RXSDUSTATEIDXOFRXSDU                                                            
#define J1939TP_EQ2_SDUIDOFRXSDU                                                                    
#define J1939TP_EQ2_COMMCHANNELOFTXCHANNEL                                                          
#define J1939TP_EQ2_TXBAMINTERFRAMETIMEOFTXCHANNEL                                                  
#define J1939TP_EQ2_TXCANFDCHANNELOFTXCHANNEL                                                       
#define J1939TP_EQ2_TXCANCELLATIONSUPPORTOFTXCHANNEL                                                
#define J1939TP_EQ2_TXCHANNELTXNSDUTXNSDUTABLEINDENDIDXOFTXCHANNEL                                  
#define J1939TP_EQ2_TXCHANNELTXNSDUTXNSDUTABLEINDSTARTIDXOFTXCHANNEL                                
#define J1939TP_EQ2_TXCHANNELTXNSDUTXNSDUTABLEINDUSEDOFTXCHANNEL                                    
#define J1939TP_EQ2_TXCHANNELUSESMULTIPGOFTXCHANNEL                                                 
#define J1939TP_EQ2_TXDAOFTXCHANNEL                                                                 
#define J1939TP_EQ2_TXDYNAMICBLOCKCALCULATIONOFTXCHANNEL                                            
#define J1939TP_EQ2_TXISOBUSCHANNELOFTXCHANNEL                                                      
#define J1939TP_EQ2_TXMAXPACKETSPERBLOCKOFTXCHANNEL                                                 
#define J1939TP_EQ2_TXPDUFDTXCMNPDUIDXOFTXCHANNEL                                                   
#define J1939TP_EQ2_TXPDUFDTXCMNPDUUSEDOFTXCHANNEL                                                  
#define J1939TP_EQ2_TXPDUFDTXDTNPDUIDXOFTXCHANNEL                                                   
#define J1939TP_EQ2_TXPDUFDTXDTNPDUUSEDOFTXCHANNEL                                                  
#define J1939TP_EQ2_TXPDUTXCMNPDUIDXOFTXCHANNEL                                                     
#define J1939TP_EQ2_TXPDUTXCMNPDUUSEDOFTXCHANNEL                                                    
#define J1939TP_EQ2_TXPDUTXDTNPDUIDXOFTXCHANNEL                                                     
#define J1939TP_EQ2_TXPDUTXDTNPDUUSEDOFTXCHANNEL                                                    
#define J1939TP_EQ2_TXPDUTXETPCMNPDUIDXOFTXCHANNEL                                                  
#define J1939TP_EQ2_TXPDUTXETPCMNPDUUSEDOFTXCHANNEL                                                 
#define J1939TP_EQ2_TXPDUTXETPDTNPDUIDXOFTXCHANNEL                                                  
#define J1939TP_EQ2_TXPDUTXETPDTNPDUUSEDOFTXCHANNEL                                                 
#define J1939TP_EQ2_TXPENDINGSUPPORTOFTXCHANNEL                                                     
#define J1939TP_EQ2_TXPRIOFTXCHANNEL                                                                
#define J1939TP_EQ2_TXPROTOCOLTYPEOFTXCHANNEL                                                       
#define J1939TP_EQ2_TXRETRYSUPPORTOFTXCHANNEL                                                       
#define J1939TP_EQ2_TXSAOFTXCHANNEL                                                                 
#define J1939TP_EQ2_TXVARPRIOFTXCHANNEL                                                             
#define J1939TP_EQ2_TXSDUTXNSDUIDXOFTXCHANNELTXNSDU                                                 
#define J1939TP_EQ2_TXCHANNELTXNSDUTXNSDUTABLEIND                                                   
#define J1939TP_EQ2_HASMETADATAOFTXPDU                                                              
#define J1939TP_EQ2_INVALIDHNDOFTXPDU                                                               
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32IDXOFTXPDU                                               
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32USEDOFTXPDU                                              
#define J1939TP_EQ2_METADATASETTERCAN_ID_32IDXOFTXPDU                                               
#define J1939TP_EQ2_METADATASETTERCAN_ID_32USEDOFTXPDU                                              
#define J1939TP_EQ2_ONISOBUSOFTXPDU                                                                 
#define J1939TP_EQ2_PDUIDOFTXPDU                                                                    
#define J1939TP_EQ2_PDUTYPEOFTXPDU                                                                  
#define J1939TP_EQ2_TXPDURXCHANNELRXCHANNELTABLEINDENDIDXOFTXPDU                                    
#define J1939TP_EQ2_TXPDURXCHANNELRXCHANNELTABLEINDSTARTIDXOFTXPDU                                  
#define J1939TP_EQ2_TXPDURXCHANNELRXCHANNELTABLEINDUSEDOFTXPDU                                      
#define J1939TP_EQ2_TXPDUSTATEIDXOFTXPDU                                                            
#define J1939TP_EQ2_TXPDUTXCHANNELTXCHANNELTABLEINDENDIDXOFTXPDU                                    
#define J1939TP_EQ2_TXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFTXPDU                                  
#define J1939TP_EQ2_TXPDUTXCHANNELTXCHANNELTABLEINDUSEDOFTXPDU                                      
#define J1939TP_EQ2_RXCHANNELRXCHANNELIDXOFTXPDURXCHANNEL                                           
#define J1939TP_EQ2_TXPDURXCHANNELRXCHANNELTABLEIND                                                 
#define J1939TP_EQ2_TXCHANNELTXCHANNELIDXOFTXPDUTXCHANNEL                                           
#define J1939TP_EQ2_TXPDUTXCHANNELTXCHANNELTABLEIND                                                 
#define J1939TP_EQ2_DIRECTPRIORITYOFTXSDU                                                           
#define J1939TP_EQ2_FPPTXSDUSEQUENCECOUNTERIDXOFTXSDU                                               
#define J1939TP_EQ2_FPPTXSDUSEQUENCECOUNTERUSEDOFTXSDU                                              
#define J1939TP_EQ2_HASMETADATADAOFTXSDU                                                            
#define J1939TP_EQ2_HASMETADATAOFTXSDU                                                              
#define J1939TP_EQ2_HASMETADATAPRIOOFTXSDU                                                          
#define J1939TP_EQ2_HASMETADATASAOFTXSDU                                                            
#define J1939TP_EQ2_INVALIDHNDOFTXSDU                                                               
#define J1939TP_EQ2_ISDIRECTPRIOCONFIGUREDOFTXSDU                                                   
#define J1939TP_EQ2_ISVARIABLEOFTXSDU                                                               
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8IDXOFTXSDU                                              
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8USEDOFTXSDU                                             
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16IDXOFTXSDU                                       
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16USEDOFTXSDU                                      
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16IDXOFTXSDU                                       
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16USEDOFTXSDU                                      
#define J1939TP_EQ2_METADATASETTERPRIORITY_8IDXOFTXSDU                                              
#define J1939TP_EQ2_METADATASETTERPRIORITY_8USEDOFTXSDU                                             
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16IDXOFTXSDU                                       
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16USEDOFTXSDU                                      
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16IDXOFTXSDU                                       
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16USEDOFTXSDU                                      
#define J1939TP_EQ2_PGNOFTXSDU                                                                      
#define J1939TP_EQ2_PDUFORMATOFTXSDU                                                                
#define J1939TP_EQ2_PDULENGTHOFTXSDU                                                                
#define J1939TP_EQ2_SDUIDOFTXSDU                                                                    
#define J1939TP_EQ2_TXCHANNELCHANNELIDXOFTXSDU                                                      
#define J1939TP_EQ2_TXCHANNELCHANNELUSEDOFTXSDU                                                     
#define J1939TP_EQ2_TXPDUDIRECTFDBCNPDUIDXOFTXSDU                                                   
#define J1939TP_EQ2_TXPDUDIRECTFDBCNPDUUSEDOFTXSDU                                                  
#define J1939TP_EQ2_TXPDUDIRECTFDNPDUIDXOFTXSDU                                                     
#define J1939TP_EQ2_TXPDUDIRECTFDNPDUUSEDOFTXSDU                                                    
#define J1939TP_EQ2_TXPDUDIRECTNPDUIDXOFTXSDU                                                       
#define J1939TP_EQ2_TXPDUDIRECTNPDUUSEDOFTXSDU                                                      
#define J1939TP_EQ2_TXSDUSTATEIDXOFTXSDU                                                            
#define J1939TP_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                      
#define J1939TP_EQ2_FPPRXSDUSEQUENCECOUNTEROFPCCONFIG                                               
#define J1939TP_EQ2_FPPTXSDUSEQUENCECOUNTEROFPCCONFIG                                               
#define J1939TP_EQ2_INITDATAHASHCODEOFPCCONFIG                                                      
#define J1939TP_EQ2_METADATAGETTERCAN_ID_32OFPCCONFIG                                               J1939Tp_MetaDataGetterCAN_ID_32
#define J1939TP_EQ2_METADATAGETTERPRIORITY_8OFPCCONFIG                                              
#define J1939TP_EQ2_METADATAGETTERSOURCE_ADDRESS_16OFPCCONFIG                                       
#define J1939TP_EQ2_METADATAGETTERTARGET_ADDRESS_16OFPCCONFIG                                       J1939Tp_MetaDataGetterTARGET_ADDRESS_16
#define J1939TP_EQ2_METADATASETTERCAN_ID_32OFPCCONFIG                                               J1939Tp_MetaDataSetterCAN_ID_32
#define J1939TP_EQ2_METADATASETTERPRIORITY_8OFPCCONFIG                                              
#define J1939TP_EQ2_METADATASETTERSOURCE_ADDRESS_16OFPCCONFIG                                       
#define J1939TP_EQ2_METADATASETTERTARGET_ADDRESS_16OFPCCONFIG                                       J1939Tp_MetaDataSetterTARGET_ADDRESS_16
#define J1939TP_EQ2_RXCHANNELOFPCCONFIG                                                             
#define J1939TP_EQ2_RXCHANNELRXNSDUOFPCCONFIG                                                       
#define J1939TP_EQ2_RXCHANNELRXNSDURXNSDUTABLEINDOFPCCONFIG                                         
#define J1939TP_EQ2_RXPDUDAPRIOOFPCCONFIG                                                           
#define J1939TP_EQ2_RXPDUOFPCCONFIG                                                                 
#define J1939TP_EQ2_RXPDURXCHANNELOFPCCONFIG                                                        
#define J1939TP_EQ2_RXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                       
#define J1939TP_EQ2_RXPDURXSDUOFPCCONFIG                                                            
#define J1939TP_EQ2_RXPDURXSDURXSDUTABLEINDOFPCCONFIG                                               
#define J1939TP_EQ2_RXPDUSAOFPCCONFIG                                                               
#define J1939TP_EQ2_RXPDUTXCHANNELOFPCCONFIG                                                        
#define J1939TP_EQ2_RXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                       
#define J1939TP_EQ2_RXSDUOFPCCONFIG                                                                 
#define J1939TP_EQ2_RXSDUSTATEOFPCCONFIG                                                            
#define J1939TP_EQ2_TXCHANNELOFPCCONFIG                                                             J1939Tp_TxChannel
#define J1939TP_EQ2_TXCHANNELTXNSDUOFPCCONFIG                                                       J1939Tp_TxChannelTxNSdu
#define J1939TP_EQ2_TXCHANNELTXNSDUTXNSDUTABLEINDOFPCCONFIG                                         J1939Tp_TxChannelTxNSduTxNSduTableInd
#define J1939TP_EQ2_TXPDUOFPCCONFIG                                                                 J1939Tp_TxPdu
#define J1939TP_EQ2_TXPDURXCHANNELOFPCCONFIG                                                        
#define J1939TP_EQ2_TXPDURXCHANNELRXCHANNELTABLEINDOFPCCONFIG                                       
#define J1939TP_EQ2_TXPDUSTATEOFPCCONFIG                                                            J1939Tp_TxPduState.raw
#define J1939TP_EQ2_TXPDUTXCHANNELOFPCCONFIG                                                        J1939Tp_TxPduTxChannel
#define J1939TP_EQ2_TXPDUTXCHANNELTXCHANNELTABLEINDOFPCCONFIG                                       J1939Tp_TxPduTxChannelTxChannelTableInd
#define J1939TP_EQ2_TXSDUOFPCCONFIG                                                                 J1939Tp_TxSdu
#define J1939TP_EQ2_TXSDUSTATEOFPCCONFIG                                                            J1939Tp_TxSduState.raw
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCSymbolicNonDereferenciateablePointers  J1939Tp Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define J1939Tp_FppRxSduSequenceCounter                                                             ((J1939Tp_FppRxSduSequenceCounterPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_FppTxSduSequenceCounter                                                             ((J1939Tp_FppTxSduSequenceCounterPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_MetaDataGetterPRIORITY_8                                                            ((J1939Tp_MetaDataGetterPRIORITY_8PtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_MetaDataGetterSOURCE_ADDRESS_16                                                     ((J1939Tp_MetaDataGetterSOURCE_ADDRESS_16PtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_MetaDataSetterPRIORITY_8                                                            ((J1939Tp_MetaDataSetterPRIORITY_8PtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_MetaDataSetterSOURCE_ADDRESS_16                                                     ((J1939Tp_MetaDataSetterSOURCE_ADDRESS_16PtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxChannel                                                                           ((J1939Tp_RxChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxChannelRxNSdu                                                                     ((J1939Tp_RxChannelRxNSduPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxChannelRxNSduRxNSduTableInd                                                       ((J1939Tp_RxChannelRxNSduRxNSduTableIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPdu                                                                               ((J1939Tp_RxPduPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduDaPrio                                                                         ((J1939Tp_RxPduDaPrioPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduRxChannel                                                                      ((J1939Tp_RxPduRxChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduRxChannelRxChannelTableInd                                                     ((J1939Tp_RxPduRxChannelRxChannelTableIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduRxSdu                                                                          ((J1939Tp_RxPduRxSduPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduRxSduRxSduTableInd                                                             ((J1939Tp_RxPduRxSduRxSduTableIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduSa                                                                             ((J1939Tp_RxPduSaPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduTxChannel                                                                      ((J1939Tp_RxPduTxChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxPduTxChannelTxChannelTableInd                                                     ((J1939Tp_RxPduTxChannelTxChannelTableIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxSdu                                                                               ((J1939Tp_RxSduPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_RxSduState                                                                          ((J1939Tp_RxSduStatePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_TxPduRxChannel                                                                      ((J1939Tp_TxPduRxChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define J1939Tp_TxPduRxChannelRxChannelTableInd                                                     ((J1939Tp_TxPduRxChannelRxChannelTableIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCSymbolicInitializationPointers  J1939Tp Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define J1939Tp_Config_RDR_01_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_02_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_03_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_04_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_05_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_06_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_07_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
#define J1939Tp_Config_RDR_08_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'J1939Tp' */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCInitializationSymbols  J1939Tp Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define J1939Tp_Config_RDR_01                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_02                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_03                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_04                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_05                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_06                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_07                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
#define J1939Tp_Config_RDR_08                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'J1939Tp */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCGeneral  J1939Tp General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define J1939TP_CHECK_INIT_POINTER                                                                  STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define J1939TP_FINAL_MAGIC_NUMBER                                                                  0x251Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of J1939Tp */
#define J1939TP_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'J1939Tp' is not configured to be postbuild capable. */
#define J1939TP_INIT_DATA                                                                           J1939TP_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define J1939TP_INIT_DATA_HASH_CODE                                                                 -652557570  /**< the precompile constant to validate the initialization structure at initialization time of J1939Tp with a hashcode. The seed value is '0x251Eu' */
#define J1939TP_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define J1939TP_USE_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer J1939Tp shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

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
  \defgroup  J1939TpPCGetRootDataMacros  J1939Tp Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define J1939Tp_GetFinalMagicNumberOfPCConfig()                                                     0x0000u
#define J1939Tp_GetFppRxSduSequenceCounterOfPCConfig()                                              NULL_PTR
#define J1939Tp_GetFppTxSduSequenceCounterOfPCConfig()                                              NULL_PTR
#define J1939Tp_GetInitDataHashCodeOfPCConfig()                                                     0
#define J1939Tp_GetMetaDataGetterPRIORITY_8OfPCConfig()                                             NULL_PTR
#define J1939Tp_GetMetaDataGetterSOURCE_ADDRESS_16OfPCConfig()                                      NULL_PTR
#define J1939Tp_GetMetaDataSetterPRIORITY_8OfPCConfig()                                             NULL_PTR
#define J1939Tp_GetMetaDataSetterSOURCE_ADDRESS_16OfPCConfig()                                      NULL_PTR
#define J1939Tp_GetRxChannelOfPCConfig()                                                            NULL_PTR
#define J1939Tp_GetRxChannelRxNSduOfPCConfig()                                                      NULL_PTR
#define J1939Tp_GetRxChannelRxNSduRxNSduTableIndOfPCConfig()                                        NULL_PTR
#define J1939Tp_GetRxPduDaPrioOfPCConfig()                                                          NULL_PTR
#define J1939Tp_GetRxPduOfPCConfig()                                                                NULL_PTR
#define J1939Tp_GetRxPduRxChannelOfPCConfig()                                                       NULL_PTR
#define J1939Tp_GetRxPduRxChannelRxChannelTableIndOfPCConfig()                                      NULL_PTR
#define J1939Tp_GetRxPduRxSduOfPCConfig()                                                           NULL_PTR
#define J1939Tp_GetRxPduRxSduRxSduTableIndOfPCConfig()                                              NULL_PTR
#define J1939Tp_GetRxPduSaOfPCConfig()                                                              NULL_PTR
#define J1939Tp_GetRxPduTxChannelOfPCConfig()                                                       NULL_PTR
#define J1939Tp_GetRxPduTxChannelTxChannelTableIndOfPCConfig()                                      NULL_PTR
#define J1939Tp_GetRxSduOfPCConfig()                                                                NULL_PTR
#define J1939Tp_GetRxSduStateOfPCConfig()                                                           NULL_PTR
#define J1939Tp_GetTxPduRxChannelOfPCConfig()                                                       NULL_PTR
#define J1939Tp_GetTxPduRxChannelRxChannelTableIndOfPCConfig()                                      NULL_PTR
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCGetConstantDuplicatedRootDataMacros  J1939Tp Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define J1939Tp_GetMainPeriodOfPCConfig()                                                           10u
#define J1939Tp_GetMetaDataGetterCAN_ID_32OfPCConfig()                                              J1939Tp_MetaDataGetterCAN_ID_32  /**< the pointer to J1939Tp_MetaDataGetterCAN_ID_32 */
#define J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                      J1939Tp_MetaDataGetterTARGET_ADDRESS_16  /**< the pointer to J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Tp_GetMetaDataSetterCAN_ID_32OfPCConfig()                                              J1939Tp_MetaDataSetterCAN_ID_32  /**< the pointer to J1939Tp_MetaDataSetterCAN_ID_32 */
#define J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                      J1939Tp_MetaDataSetterTARGET_ADDRESS_16  /**< the pointer to J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Tp_GetSizeOfFppRxSduSequenceCounterOfPCConfig()                                        0u  /**< the number of accomplishable value elements in J1939Tp_FppRxSduSequenceCounter */
#define J1939Tp_GetSizeOfFppTxSduSequenceCounterOfPCConfig()                                        0u  /**< the number of accomplishable value elements in J1939Tp_FppTxSduSequenceCounter */
#define J1939Tp_GetSizeOfMetaDataGetterCAN_ID_32OfPCConfig()                                        1u  /**< the number of accomplishable value elements in J1939Tp_MetaDataGetterCAN_ID_32 */
#define J1939Tp_GetSizeOfMetaDataGetterPRIORITY_8OfPCConfig()                                       0u  /**< the number of accomplishable value elements in J1939Tp_MetaDataGetterPRIORITY_8 */
#define J1939Tp_GetSizeOfMetaDataGetterSOURCE_ADDRESS_16OfPCConfig()                                0u  /**< the number of accomplishable value elements in J1939Tp_MetaDataGetterSOURCE_ADDRESS_16 */
#define J1939Tp_GetSizeOfMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                1u  /**< the number of accomplishable value elements in J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Tp_GetSizeOfMetaDataSetterCAN_ID_32OfPCConfig()                                        1u  /**< the number of accomplishable value elements in J1939Tp_MetaDataSetterCAN_ID_32 */
#define J1939Tp_GetSizeOfMetaDataSetterPRIORITY_8OfPCConfig()                                       0u  /**< the number of accomplishable value elements in J1939Tp_MetaDataSetterPRIORITY_8 */
#define J1939Tp_GetSizeOfMetaDataSetterSOURCE_ADDRESS_16OfPCConfig()                                0u  /**< the number of accomplishable value elements in J1939Tp_MetaDataSetterSOURCE_ADDRESS_16 */
#define J1939Tp_GetSizeOfMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                1u  /**< the number of accomplishable value elements in J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Tp_GetSizeOfRxChannelOfPCConfig()                                                      0u  /**< the number of accomplishable value elements in J1939Tp_RxChannel */
#define J1939Tp_GetSizeOfRxChannelRxNSduOfPCConfig()                                                0u  /**< the number of accomplishable value elements in J1939Tp_RxChannelRxNSdu */
#define J1939Tp_GetSizeOfRxChannelRxNSduRxNSduTableIndOfPCConfig()                                  0u  /**< the number of accomplishable value elements in J1939Tp_RxChannelRxNSduRxNSduTableInd */
#define J1939Tp_GetSizeOfRxPduDaPrioOfPCConfig()                                                    0u  /**< the number of accomplishable value elements in J1939Tp_RxPduDaPrio */
#define J1939Tp_GetSizeOfRxPduOfPCConfig()                                                          0u  /**< the number of accomplishable value elements in J1939Tp_RxPdu */
#define J1939Tp_GetSizeOfRxPduRxChannelOfPCConfig()                                                 0u  /**< the number of accomplishable value elements in J1939Tp_RxPduRxChannel */
#define J1939Tp_GetSizeOfRxPduRxChannelRxChannelTableIndOfPCConfig()                                0u  /**< the number of accomplishable value elements in J1939Tp_RxPduRxChannelRxChannelTableInd */
#define J1939Tp_GetSizeOfRxPduRxSduOfPCConfig()                                                     0u  /**< the number of accomplishable value elements in J1939Tp_RxPduRxSdu */
#define J1939Tp_GetSizeOfRxPduRxSduRxSduTableIndOfPCConfig()                                        0u  /**< the number of accomplishable value elements in J1939Tp_RxPduRxSduRxSduTableInd */
#define J1939Tp_GetSizeOfRxPduSaOfPCConfig()                                                        0u  /**< the number of accomplishable value elements in J1939Tp_RxPduSa */
#define J1939Tp_GetSizeOfRxPduTxChannelOfPCConfig()                                                 0u  /**< the number of accomplishable value elements in J1939Tp_RxPduTxChannel */
#define J1939Tp_GetSizeOfRxPduTxChannelTxChannelTableIndOfPCConfig()                                0u  /**< the number of accomplishable value elements in J1939Tp_RxPduTxChannelTxChannelTableInd */
#define J1939Tp_GetSizeOfRxSduOfPCConfig()                                                          0u  /**< the number of accomplishable value elements in J1939Tp_RxSdu */
#define J1939Tp_GetSizeOfRxSduStateOfPCConfig()                                                     0u  /**< the number of accomplishable value elements in J1939Tp_RxSduState */
#define J1939Tp_GetSizeOfTxChannelOfPCConfig()                                                      1u  /**< the number of accomplishable value elements in J1939Tp_TxChannel */
#define J1939Tp_GetSizeOfTxChannelTxNSduOfPCConfig()                                                1u  /**< the number of accomplishable value elements in J1939Tp_TxChannelTxNSdu */
#define J1939Tp_GetSizeOfTxChannelTxNSduTxNSduTableIndOfPCConfig()                                  1u  /**< the number of accomplishable value elements in J1939Tp_TxChannelTxNSduTxNSduTableInd */
#define J1939Tp_GetSizeOfTxPduOfPCConfig()                                                          3u  /**< the number of accomplishable value elements in J1939Tp_TxPdu */
#define J1939Tp_GetSizeOfTxPduRxChannelOfPCConfig()                                                 0u  /**< the number of accomplishable value elements in J1939Tp_TxPduRxChannel */
#define J1939Tp_GetSizeOfTxPduRxChannelRxChannelTableIndOfPCConfig()                                0u  /**< the number of accomplishable value elements in J1939Tp_TxPduRxChannelRxChannelTableInd */
#define J1939Tp_GetSizeOfTxPduStateOfPCConfig()                                                     3u  /**< the number of accomplishable value elements in J1939Tp_TxPduState */
#define J1939Tp_GetSizeOfTxPduTxChannelOfPCConfig()                                                 3u  /**< the number of accomplishable value elements in J1939Tp_TxPduTxChannel */
#define J1939Tp_GetSizeOfTxPduTxChannelTxChannelTableIndOfPCConfig()                                3u  /**< the number of accomplishable value elements in J1939Tp_TxPduTxChannelTxChannelTableInd */
#define J1939Tp_GetSizeOfTxSduOfPCConfig()                                                          1u  /**< the number of accomplishable value elements in J1939Tp_TxSdu */
#define J1939Tp_GetSizeOfTxSduStateOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in J1939Tp_TxSduState */
#define J1939Tp_GetTime_FpOfPCConfig()                                                              10u
#define J1939Tp_GetTime_T1OfPCConfig()                                                              75u
#define J1939Tp_GetTime_T2OfPCConfig()                                                              125u
#define J1939Tp_GetTime_T3OfPCConfig()                                                              125u
#define J1939Tp_GetTime_T4OfPCConfig()                                                              105u
#define J1939Tp_GetTime_T5OfPCConfig()                                                              300u
#define J1939Tp_GetTime_ThOfPCConfig()                                                              50u
#define J1939Tp_GetTime_TrOfPCConfig()                                                              20u
#define J1939Tp_GetTxChannelOfPCConfig()                                                            J1939Tp_TxChannel  /**< the pointer to J1939Tp_TxChannel */
#define J1939Tp_GetTxChannelTxNSduOfPCConfig()                                                      J1939Tp_TxChannelTxNSdu  /**< the pointer to J1939Tp_TxChannelTxNSdu */
#define J1939Tp_GetTxChannelTxNSduTxNSduTableIndOfPCConfig()                                        J1939Tp_TxChannelTxNSduTxNSduTableInd  /**< the pointer to J1939Tp_TxChannelTxNSduTxNSduTableInd */
#define J1939Tp_GetTxConfTimeoutOfPCConfig()                                                        150u
#define J1939Tp_GetTxPduOfPCConfig()                                                                J1939Tp_TxPdu  /**< the pointer to J1939Tp_TxPdu */
#define J1939Tp_GetTxPduStateOfPCConfig()                                                           J1939Tp_TxPduState.raw  /**< the pointer to J1939Tp_TxPduState */
#define J1939Tp_GetTxPduTxChannelOfPCConfig()                                                       J1939Tp_TxPduTxChannel  /**< the pointer to J1939Tp_TxPduTxChannel */
#define J1939Tp_GetTxPduTxChannelTxChannelTableIndOfPCConfig()                                      J1939Tp_TxPduTxChannelTxChannelTableInd  /**< the pointer to J1939Tp_TxPduTxChannelTxChannelTableInd */
#define J1939Tp_GetTxSduOfPCConfig()                                                                J1939Tp_TxSdu  /**< the pointer to J1939Tp_TxSdu */
#define J1939Tp_GetTxSduStateOfPCConfig()                                                           J1939Tp_TxSduState.raw  /**< the pointer to J1939Tp_TxSduState */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCGetDataMacros  J1939Tp Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define J1939Tp_GetFppRxSduSequenceCounter(Index)                                                   (0u)
#define J1939Tp_GetFppTxSduSequenceCounter(Index)                                                   (0u)
#define J1939Tp_GetMetaDataGetterCAN_ID_32(Index)                                                   (J1939Tp_GetMetaDataGetterCAN_ID_32OfPCConfig()[(Index)])
#define J1939Tp_GetMetaDataGetterPRIORITY_8(Index)                                                  (NULL_PTR)
#define J1939Tp_GetMetaDataGetterSOURCE_ADDRESS_16(Index)                                           (NULL_PTR)
#define J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16(Index)                                           (J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16OfPCConfig()[(Index)])
#define J1939Tp_GetMetaDataSetterCAN_ID_32(Index)                                                   (J1939Tp_GetMetaDataSetterCAN_ID_32OfPCConfig()[(Index)])
#define J1939Tp_GetMetaDataSetterPRIORITY_8(Index)                                                  (NULL_PTR)
#define J1939Tp_GetMetaDataSetterSOURCE_ADDRESS_16(Index)                                           (NULL_PTR)
#define J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16(Index)                                           (J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16OfPCConfig()[(Index)])
#define J1939Tp_GetComMChannelOfRxChannel(Index)                                                    (0u)
#define J1939Tp_IsRxCanFdChannelOfRxChannel(Index)                                                  ((FALSE) != FALSE)
#define J1939Tp_IsRxCancellationSupportOfRxChannel(Index)                                           ((FALSE) != FALSE)
#define J1939Tp_GetRxChannelRxNSduRxNSduTableIndEndIdxOfRxChannel(Index)                            (0u)
#define J1939Tp_GetRxChannelRxNSduRxNSduTableIndStartIdxOfRxChannel(Index)                          (0u)
#define J1939Tp_IsRxChannelRxNSduRxNSduTableIndUsedOfRxChannel(Index)                               ((FALSE) != FALSE)
#define J1939Tp_IsRxChannelUsesMultiPGOfRxChannel(Index)                                            ((FALSE) != FALSE)
#define J1939Tp_GetRxDaOfRxChannel(Index)                                                           (0x00u)
#define J1939Tp_IsRxDynamicBlockCalculationOfRxChannel(Index)                                       ((FALSE) != FALSE)
#define J1939Tp_GetRxDynamicBufferRatioOfRxChannel(Index)                                           (0u)
#define J1939Tp_IsRxIsobusChannelOfRxChannel(Index)                                                 ((FALSE) != FALSE)
#define J1939Tp_GetRxPacketsPerBlockOfRxChannel(Index)                                              (0u)
#define J1939Tp_GetRxProtocolTypeOfRxChannel(Index)                                                 (0x00u)
#define J1939Tp_IsRxRetrySupportOfRxChannel(Index)                                                  ((FALSE) != FALSE)
#define J1939Tp_GetRxSaOfRxChannel(Index)                                                           (0x00u)
#define J1939Tp_GetTxPduFdRxFcNPduIdxOfRxChannel(Index)                                             (0u)
#define J1939Tp_IsTxPduFdRxFcNPduUsedOfRxChannel(Index)                                             ((FALSE) != FALSE)
#define J1939Tp_GetTxPduRxEtpFcNPduIdxOfRxChannel(Index)                                            (0u)
#define J1939Tp_IsTxPduRxEtpFcNPduUsedOfRxChannel(Index)                                            ((FALSE) != FALSE)
#define J1939Tp_GetTxPduRxFcNPduIdxOfRxChannel(Index)                                               (0u)
#define J1939Tp_IsTxPduRxFcNPduUsedOfRxChannel(Index)                                               ((FALSE) != FALSE)
#define J1939Tp_GetRxSduRxNSduIdxOfRxChannelRxNSdu(Index)                                           (0u)
#define J1939Tp_GetRxChannelRxNSduRxNSduTableInd(Index)                                             (0u)
#define J1939Tp_IsHasMetaDataOfRxPdu(Index)                                                         ((FALSE) != FALSE)
#define J1939Tp_IsInvalidHndOfRxPdu(Index)                                                          ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterCAN_ID_32IdxOfRxPdu(Index)                                         (0u)
#define J1939Tp_IsMetaDataGetterCAN_ID_32UsedOfRxPdu(Index)                                         ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterCAN_ID_32IdxOfRxPdu(Index)                                         (0u)
#define J1939Tp_IsMetaDataSetterCAN_ID_32UsedOfRxPdu(Index)                                         ((FALSE) != FALSE)
#define J1939Tp_IsOnIsobusOfRxPdu(Index)                                                            ((FALSE) != FALSE)
#define J1939Tp_GetPduFormatOfRxPdu(Index)                                                          (0x00u)
#define J1939Tp_GetPduTypeOfRxPdu(Index)                                                            (0x00u)
#define J1939Tp_GetRxPduDaPrioIdxOfRxPdu(Index)                                                     (0u)
#define J1939Tp_IsRxPduDaPrioUsedOfRxPdu(Index)                                                     ((FALSE) != FALSE)
#define J1939Tp_GetRxPduRxChannelRxChannelTableIndEndIdxOfRxPdu(Index)                              (0u)
#define J1939Tp_GetRxPduRxChannelRxChannelTableIndStartIdxOfRxPdu(Index)                            (0u)
#define J1939Tp_IsRxPduRxChannelRxChannelTableIndUsedOfRxPdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetRxPduRxSduRxSduTableIndEndIdxOfRxPdu(Index)                                      (0u)
#define J1939Tp_GetRxPduRxSduRxSduTableIndStartIdxOfRxPdu(Index)                                    (0u)
#define J1939Tp_IsRxPduRxSduRxSduTableIndUsedOfRxPdu(Index)                                         ((FALSE) != FALSE)
#define J1939Tp_GetRxPduSaIdxOfRxPdu(Index)                                                         (0u)
#define J1939Tp_IsRxPduSaUsedOfRxPdu(Index)                                                         ((FALSE) != FALSE)
#define J1939Tp_GetRxPduTxChannelTxChannelTableIndEndIdxOfRxPdu(Index)                              (0u)
#define J1939Tp_GetRxPduTxChannelTxChannelTableIndStartIdxOfRxPdu(Index)                            (0u)
#define J1939Tp_IsRxPduTxChannelTxChannelTableIndUsedOfRxPdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetRxPduDaOfRxPduDaPrio(Index)                                                      (0x00u)
#define J1939Tp_GetRxPduPrioOfRxPduDaPrio(Index)                                                    (0u)
#define J1939Tp_GetRxChannelRxChannelIdxOfRxPduRxChannel(Index)                                     (0u)
#define J1939Tp_GetRxPduRxChannelRxChannelTableInd(Index)                                           (0u)
#define J1939Tp_GetRxSduRxSduIdxOfRxPduRxSdu(Index)                                                 (0u)
#define J1939Tp_GetRxPduRxSduRxSduTableInd(Index)                                                   (0u)
#define J1939Tp_GetRxPduSa(Index)                                                                   (0x00u)
#define J1939Tp_GetTxChannelTxChannelIdxOfRxPduTxChannel(Index)                                     (0u)
#define J1939Tp_GetRxPduTxChannelTxChannelTableInd(Index)                                           (0u)
#define J1939Tp_GetFppRxSduSequenceCounterIdxOfRxSdu(Index)                                         (0u)
#define J1939Tp_IsFppRxSduSequenceCounterUsedOfRxSdu(Index)                                         ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataDaOfRxSdu(Index)                                                       ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataOfRxSdu(Index)                                                         ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataPrioOfRxSdu(Index)                                                     ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataSaOfRxSdu(Index)                                                       ((FALSE) != FALSE)
#define J1939Tp_IsInvalidHndOfRxSdu(Index)                                                          ((FALSE) != FALSE)
#define J1939Tp_IsIsVariableOfRxSdu(Index)                                                          ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterPRIORITY_8IdxOfRxSdu(Index)                                        (0u)
#define J1939Tp_IsMetaDataGetterPRIORITY_8UsedOfRxSdu(Index)                                        ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterSOURCE_ADDRESS_16IdxOfRxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataGetterSOURCE_ADDRESS_16UsedOfRxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16IdxOfRxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataGetterTARGET_ADDRESS_16UsedOfRxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterPRIORITY_8IdxOfRxSdu(Index)                                        (0u)
#define J1939Tp_IsMetaDataSetterPRIORITY_8UsedOfRxSdu(Index)                                        ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterSOURCE_ADDRESS_16IdxOfRxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataSetterSOURCE_ADDRESS_16UsedOfRxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16IdxOfRxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataSetterTARGET_ADDRESS_16UsedOfRxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetPGNOfRxSdu(Index)                                                                (0x00u)
#define J1939Tp_GetPduLengthOfRxSdu(Index)                                                          (0u)
#define J1939Tp_GetRxChannelChannelIdxOfRxSdu(Index)                                                (0u)
#define J1939Tp_IsRxChannelChannelUsedOfRxSdu(Index)                                                ((FALSE) != FALSE)
#define J1939Tp_GetRxSduStateIdxOfRxSdu(Index)                                                      (0u)
#define J1939Tp_GetSduIdOfRxSdu(Index)                                                              (0u)
#define J1939Tp_GetRxSduState(Index)                                                                ()
#define J1939Tp_GetComMChannelOfTxChannel(Index)                                                    (J1939Tp_GetTxChannelOfPCConfig()[(Index)].ComMChannelOfTxChannel)
#define J1939Tp_GetTxBamInterframeTimeOfTxChannel(Index)                                            (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxBamInterframeTimeOfTxChannel)
#define J1939Tp_IsTxCanFdChannelOfTxChannel(Index)                                                  ((FALSE) != FALSE)
#define J1939Tp_IsTxCancellationSupportOfTxChannel(Index)                                           ((FALSE) != FALSE)
#define J1939Tp_GetTxChannelTxNSduTxNSduTableIndEndIdxOfTxChannel(Index)                            (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxChannelTxNSduTxNSduTableIndEndIdxOfTxChannel)
#define J1939Tp_GetTxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel(Index)                          (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel)
#define J1939Tp_IsTxChannelUsesMultiPGOfTxChannel(Index)                                            ((FALSE) != FALSE)
#define J1939Tp_GetTxDaOfTxChannel(Index)                                                           (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxDaOfTxChannel)
#define J1939Tp_IsTxDynamicBlockCalculationOfTxChannel(Index)                                       ((FALSE) != FALSE)
#define J1939Tp_IsTxIsobusChannelOfTxChannel(Index)                                                 ((FALSE) != FALSE)
#define J1939Tp_GetTxMaxPacketsPerBlockOfTxChannel(Index)                                           (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxMaxPacketsPerBlockOfTxChannel)
#define J1939Tp_GetTxPduFdTxCmNPduIdxOfTxChannel(Index)                                             (0u)
#define J1939Tp_IsTxPduFdTxCmNPduUsedOfTxChannel(Index)                                             ((FALSE) != FALSE)
#define J1939Tp_GetTxPduFdTxDtNPduIdxOfTxChannel(Index)                                             (0u)
#define J1939Tp_IsTxPduFdTxDtNPduUsedOfTxChannel(Index)                                             ((FALSE) != FALSE)
#define J1939Tp_GetTxPduTxCmNPduIdxOfTxChannel(Index)                                               (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxPduTxCmNPduIdxOfTxChannel)
#define J1939Tp_GetTxPduTxDtNPduIdxOfTxChannel(Index)                                               (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxPduTxDtNPduIdxOfTxChannel)
#define J1939Tp_GetTxPduTxEtpCmNPduIdxOfTxChannel(Index)                                            (0u)
#define J1939Tp_IsTxPduTxEtpCmNPduUsedOfTxChannel(Index)                                            ((FALSE) != FALSE)
#define J1939Tp_GetTxPduTxEtpDtNPduIdxOfTxChannel(Index)                                            (0u)
#define J1939Tp_IsTxPduTxEtpDtNPduUsedOfTxChannel(Index)                                            ((FALSE) != FALSE)
#define J1939Tp_IsTxPendingSupportOfTxChannel(Index)                                                ((FALSE) != FALSE)
#define J1939Tp_GetTxPriOfTxChannel(Index)                                                          (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxPriOfTxChannel)
#define J1939Tp_GetTxProtocolTypeOfTxChannel(Index)                                                 (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxProtocolTypeOfTxChannel)
#define J1939Tp_IsTxRetrySupportOfTxChannel(Index)                                                  ((FALSE) != FALSE)
#define J1939Tp_GetTxSaOfTxChannel(Index)                                                           (J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxSaOfTxChannel)
#define J1939Tp_IsTxVarPriOfTxChannel(Index)                                                        ((J1939Tp_GetTxChannelOfPCConfig()[(Index)].TxVarPriOfTxChannel) != FALSE)
#define J1939Tp_GetTxSduTxNSduIdxOfTxChannelTxNSdu(Index)                                           (J1939Tp_GetTxChannelTxNSduOfPCConfig()[(Index)].TxSduTxNSduIdxOfTxChannelTxNSdu)
#define J1939Tp_GetTxChannelTxNSduTxNSduTableInd(Index)                                             (J1939Tp_GetTxChannelTxNSduTxNSduTableIndOfPCConfig()[(Index)])
#define J1939Tp_IsHasMetaDataOfTxPdu(Index)                                                         ((J1939Tp_GetTxPduOfPCConfig()[(Index)].HasMetaDataOfTxPdu) != FALSE)
#define J1939Tp_IsInvalidHndOfTxPdu(Index)                                                          ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterCAN_ID_32IdxOfTxPdu(Index)                                         (J1939Tp_GetTxPduOfPCConfig()[(Index)].MetaDataGetterCAN_ID_32IdxOfTxPdu)
#define J1939Tp_GetMetaDataSetterCAN_ID_32IdxOfTxPdu(Index)                                         (J1939Tp_GetTxPduOfPCConfig()[(Index)].MetaDataSetterCAN_ID_32IdxOfTxPdu)
#define J1939Tp_IsOnIsobusOfTxPdu(Index)                                                            ((FALSE) != FALSE)
#define J1939Tp_GetPduIdOfTxPdu(Index)                                                              (J1939Tp_GetTxPduOfPCConfig()[(Index)].PduIdOfTxPdu)
#define J1939Tp_GetPduTypeOfTxPdu(Index)                                                            (J1939Tp_GetTxPduOfPCConfig()[(Index)].PduTypeOfTxPdu)
#define J1939Tp_GetTxPduRxChannelRxChannelTableIndEndIdxOfTxPdu(Index)                              (0u)
#define J1939Tp_GetTxPduRxChannelRxChannelTableIndStartIdxOfTxPdu(Index)                            (0u)
#define J1939Tp_IsTxPduRxChannelRxChannelTableIndUsedOfTxPdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetTxPduStateIdxOfTxPdu(Index)                                                      (J1939Tp_GetTxPduOfPCConfig()[(Index)].TxPduStateIdxOfTxPdu)
#define J1939Tp_GetTxPduTxChannelTxChannelTableIndEndIdxOfTxPdu(Index)                              (J1939Tp_GetTxPduOfPCConfig()[(Index)].TxPduTxChannelTxChannelTableIndEndIdxOfTxPdu)
#define J1939Tp_GetTxPduTxChannelTxChannelTableIndStartIdxOfTxPdu(Index)                            (J1939Tp_GetTxPduOfPCConfig()[(Index)].TxPduTxChannelTxChannelTableIndStartIdxOfTxPdu)
#define J1939Tp_GetRxChannelRxChannelIdxOfTxPduRxChannel(Index)                                     (0u)
#define J1939Tp_GetTxPduRxChannelRxChannelTableInd(Index)                                           (0u)
#define J1939Tp_GetTxPduState(Index)                                                                (J1939Tp_GetTxPduStateOfPCConfig()[(Index)])
#define J1939Tp_GetTxChannelTxChannelIdxOfTxPduTxChannel(Index)                                     (J1939Tp_GetTxPduTxChannelOfPCConfig()[(Index)].TxChannelTxChannelIdxOfTxPduTxChannel)
#define J1939Tp_GetTxPduTxChannelTxChannelTableInd(Index)                                           (J1939Tp_GetTxPduTxChannelTxChannelTableIndOfPCConfig()[(Index)])
#define J1939Tp_GetDirectPriorityOfTxSdu(Index)                                                     (J1939Tp_GetTxSduOfPCConfig()[(Index)].DirectPriorityOfTxSdu)
#define J1939Tp_GetFppTxSduSequenceCounterIdxOfTxSdu(Index)                                         (0u)
#define J1939Tp_IsFppTxSduSequenceCounterUsedOfTxSdu(Index)                                         ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataDaOfTxSdu(Index)                                                       ((J1939Tp_GetTxSduOfPCConfig()[(Index)].HasMetaDataDaOfTxSdu) != FALSE)
#define J1939Tp_IsHasMetaDataOfTxSdu(Index)                                                         ((J1939Tp_GetTxSduOfPCConfig()[(Index)].HasMetaDataOfTxSdu) != FALSE)
#define J1939Tp_IsHasMetaDataPrioOfTxSdu(Index)                                                     ((FALSE) != FALSE)
#define J1939Tp_IsHasMetaDataSaOfTxSdu(Index)                                                       ((FALSE) != FALSE)
#define J1939Tp_IsInvalidHndOfTxSdu(Index)                                                          ((FALSE) != FALSE)
#define J1939Tp_IsIsDirectPrioConfiguredOfTxSdu(Index)                                              ((J1939Tp_GetTxSduOfPCConfig()[(Index)].IsDirectPrioConfiguredOfTxSdu) != FALSE)
#define J1939Tp_IsIsVariableOfTxSdu(Index)                                                          ((J1939Tp_GetTxSduOfPCConfig()[(Index)].IsVariableOfTxSdu) != FALSE)
#define J1939Tp_GetMetaDataGetterPRIORITY_8IdxOfTxSdu(Index)                                        (0u)
#define J1939Tp_IsMetaDataGetterPRIORITY_8UsedOfTxSdu(Index)                                        ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterSOURCE_ADDRESS_16IdxOfTxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataGetterSOURCE_ADDRESS_16UsedOfTxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu(Index)                                 (J1939Tp_GetTxSduOfPCConfig()[(Index)].MetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu)
#define J1939Tp_GetMetaDataSetterPRIORITY_8IdxOfTxSdu(Index)                                        (0u)
#define J1939Tp_IsMetaDataSetterPRIORITY_8UsedOfTxSdu(Index)                                        ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterSOURCE_ADDRESS_16IdxOfTxSdu(Index)                                 (0u)
#define J1939Tp_IsMetaDataSetterSOURCE_ADDRESS_16UsedOfTxSdu(Index)                                 ((FALSE) != FALSE)
#define J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu(Index)                                 (J1939Tp_GetTxSduOfPCConfig()[(Index)].MetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu)
#define J1939Tp_GetPGNOfTxSdu(Index)                                                                (J1939Tp_GetTxSduOfPCConfig()[(Index)].PGNOfTxSdu)
#define J1939Tp_GetPduFormatOfTxSdu(Index)                                                          (J1939Tp_GetTxSduOfPCConfig()[(Index)].PduFormatOfTxSdu)
#define J1939Tp_GetPduLengthOfTxSdu(Index)                                                          (J1939Tp_GetTxSduOfPCConfig()[(Index)].PduLengthOfTxSdu)
#define J1939Tp_GetSduIdOfTxSdu(Index)                                                              (J1939Tp_GetTxSduOfPCConfig()[(Index)].SduIdOfTxSdu)
#define J1939Tp_GetTxChannelChannelIdxOfTxSdu(Index)                                                (J1939Tp_GetTxSduOfPCConfig()[(Index)].TxChannelChannelIdxOfTxSdu)
#define J1939Tp_GetTxPduDirectFdBcNPduIdxOfTxSdu(Index)                                             (0u)
#define J1939Tp_IsTxPduDirectFdBcNPduUsedOfTxSdu(Index)                                             ((FALSE) != FALSE)
#define J1939Tp_GetTxPduDirectFdNPduIdxOfTxSdu(Index)                                               (0u)
#define J1939Tp_IsTxPduDirectFdNPduUsedOfTxSdu(Index)                                               ((FALSE) != FALSE)
#define J1939Tp_GetTxPduDirectNPduIdxOfTxSdu(Index)                                                 (J1939Tp_GetTxSduOfPCConfig()[(Index)].TxPduDirectNPduIdxOfTxSdu)
#define J1939Tp_GetTxSduStateIdxOfTxSdu(Index)                                                      (J1939Tp_GetTxSduOfPCConfig()[(Index)].TxSduStateIdxOfTxSdu)
#define J1939Tp_GetTxSduState(Index)                                                                (J1939Tp_GetTxSduStateOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCGetDeduplicatedDataMacros  J1939Tp Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define J1939Tp_GetFinalMagicNumber()                                                               J1939Tp_GetFinalMagicNumberOfPCConfig()
#define J1939Tp_GetInitDataHashCode()                                                               J1939Tp_GetInitDataHashCodeOfPCConfig()
#define J1939Tp_GetMainPeriod()                                                                     J1939Tp_GetMainPeriodOfPCConfig()
#define J1939Tp_GetSizeOfFppRxSduSequenceCounter()                                                  J1939Tp_GetSizeOfFppRxSduSequenceCounterOfPCConfig()
#define J1939Tp_GetSizeOfFppTxSduSequenceCounter()                                                  J1939Tp_GetSizeOfFppTxSduSequenceCounterOfPCConfig()
#define J1939Tp_GetSizeOfMetaDataGetterCAN_ID_32()                                                  J1939Tp_GetSizeOfMetaDataGetterCAN_ID_32OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataGetterPRIORITY_8()                                                 J1939Tp_GetSizeOfMetaDataGetterPRIORITY_8OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataGetterSOURCE_ADDRESS_16()                                          J1939Tp_GetSizeOfMetaDataGetterSOURCE_ADDRESS_16OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataGetterTARGET_ADDRESS_16()                                          J1939Tp_GetSizeOfMetaDataGetterTARGET_ADDRESS_16OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataSetterCAN_ID_32()                                                  J1939Tp_GetSizeOfMetaDataSetterCAN_ID_32OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataSetterPRIORITY_8()                                                 J1939Tp_GetSizeOfMetaDataSetterPRIORITY_8OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataSetterSOURCE_ADDRESS_16()                                          J1939Tp_GetSizeOfMetaDataSetterSOURCE_ADDRESS_16OfPCConfig()
#define J1939Tp_GetSizeOfMetaDataSetterTARGET_ADDRESS_16()                                          J1939Tp_GetSizeOfMetaDataSetterTARGET_ADDRESS_16OfPCConfig()
#define J1939Tp_GetSizeOfRxChannel()                                                                J1939Tp_GetSizeOfRxChannelOfPCConfig()
#define J1939Tp_GetSizeOfRxChannelRxNSdu()                                                          J1939Tp_GetSizeOfRxChannelRxNSduOfPCConfig()
#define J1939Tp_GetSizeOfRxChannelRxNSduRxNSduTableInd()                                            J1939Tp_GetSizeOfRxChannelRxNSduRxNSduTableIndOfPCConfig()
#define J1939Tp_GetSizeOfRxPdu()                                                                    J1939Tp_GetSizeOfRxPduOfPCConfig()
#define J1939Tp_GetSizeOfRxPduDaPrio()                                                              J1939Tp_GetSizeOfRxPduDaPrioOfPCConfig()
#define J1939Tp_GetSizeOfRxPduRxChannel()                                                           J1939Tp_GetSizeOfRxPduRxChannelOfPCConfig()
#define J1939Tp_GetSizeOfRxPduRxChannelRxChannelTableInd()                                          J1939Tp_GetSizeOfRxPduRxChannelRxChannelTableIndOfPCConfig()
#define J1939Tp_GetSizeOfRxPduRxSdu()                                                               J1939Tp_GetSizeOfRxPduRxSduOfPCConfig()
#define J1939Tp_GetSizeOfRxPduRxSduRxSduTableInd()                                                  J1939Tp_GetSizeOfRxPduRxSduRxSduTableIndOfPCConfig()
#define J1939Tp_GetSizeOfRxPduSa()                                                                  J1939Tp_GetSizeOfRxPduSaOfPCConfig()
#define J1939Tp_GetSizeOfRxPduTxChannel()                                                           J1939Tp_GetSizeOfRxPduTxChannelOfPCConfig()
#define J1939Tp_GetSizeOfRxPduTxChannelTxChannelTableInd()                                          J1939Tp_GetSizeOfRxPduTxChannelTxChannelTableIndOfPCConfig()
#define J1939Tp_GetSizeOfRxSdu()                                                                    J1939Tp_GetSizeOfRxSduOfPCConfig()
#define J1939Tp_GetSizeOfRxSduState()                                                               J1939Tp_GetSizeOfRxSduStateOfPCConfig()
#define J1939Tp_GetSizeOfTxChannel()                                                                J1939Tp_GetSizeOfTxChannelOfPCConfig()
#define J1939Tp_GetSizeOfTxChannelTxNSdu()                                                          J1939Tp_GetSizeOfTxChannelTxNSduOfPCConfig()
#define J1939Tp_GetSizeOfTxChannelTxNSduTxNSduTableInd()                                            J1939Tp_GetSizeOfTxChannelTxNSduTxNSduTableIndOfPCConfig()
#define J1939Tp_GetSizeOfTxPdu()                                                                    J1939Tp_GetSizeOfTxPduOfPCConfig()
#define J1939Tp_GetSizeOfTxPduRxChannel()                                                           J1939Tp_GetSizeOfTxPduRxChannelOfPCConfig()
#define J1939Tp_GetSizeOfTxPduRxChannelRxChannelTableInd()                                          J1939Tp_GetSizeOfTxPduRxChannelRxChannelTableIndOfPCConfig()
#define J1939Tp_GetSizeOfTxPduState()                                                               J1939Tp_GetSizeOfTxPduStateOfPCConfig()
#define J1939Tp_GetSizeOfTxPduTxChannel()                                                           J1939Tp_GetSizeOfTxPduTxChannelOfPCConfig()
#define J1939Tp_GetSizeOfTxPduTxChannelTxChannelTableInd()                                          J1939Tp_GetSizeOfTxPduTxChannelTxChannelTableIndOfPCConfig()
#define J1939Tp_GetSizeOfTxSdu()                                                                    J1939Tp_GetSizeOfTxSduOfPCConfig()
#define J1939Tp_GetSizeOfTxSduState()                                                               J1939Tp_GetSizeOfTxSduStateOfPCConfig()
#define J1939Tp_GetTime_Fp()                                                                        J1939Tp_GetTime_FpOfPCConfig()
#define J1939Tp_GetTime_T1()                                                                        J1939Tp_GetTime_T1OfPCConfig()
#define J1939Tp_GetTime_T2()                                                                        J1939Tp_GetTime_T2OfPCConfig()
#define J1939Tp_GetTime_T3()                                                                        J1939Tp_GetTime_T3OfPCConfig()
#define J1939Tp_GetTime_T4()                                                                        J1939Tp_GetTime_T4OfPCConfig()
#define J1939Tp_GetTime_T5()                                                                        J1939Tp_GetTime_T5OfPCConfig()
#define J1939Tp_GetTime_Th()                                                                        J1939Tp_GetTime_ThOfPCConfig()
#define J1939Tp_GetTime_Tr()                                                                        J1939Tp_GetTime_TrOfPCConfig()
#define J1939Tp_IsTxChannelTxNSduTxNSduTableIndUsedOfTxChannel(Index)                               (((boolean)(J1939Tp_GetTxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel(Index) != J1939TP_NO_TXCHANNELTXNSDUTXNSDUTABLEINDSTARTIDXOFTXCHANNEL)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd */
#define J1939Tp_IsTxPduTxCmNPduUsedOfTxChannel(Index)                                               (((boolean)(J1939Tp_GetTxPduTxCmNPduIdxOfTxChannel(Index) != J1939TP_NO_TXPDUTXCMNPDUIDXOFTXCHANNEL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_TxPdu */
#define J1939Tp_IsTxPduTxDtNPduUsedOfTxChannel(Index)                                               (((boolean)(J1939Tp_GetTxPduTxDtNPduIdxOfTxChannel(Index) != J1939TP_NO_TXPDUTXDTNPDUIDXOFTXCHANNEL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_TxPdu */
#define J1939Tp_GetTxConfTimeout()                                                                  J1939Tp_GetTxConfTimeoutOfPCConfig()
#define J1939Tp_IsMetaDataGetterCAN_ID_32UsedOfTxPdu(Index)                                         (((boolean)(J1939Tp_GetMetaDataGetterCAN_ID_32IdxOfTxPdu(Index) != J1939TP_NO_METADATAGETTERCAN_ID_32IDXOFTXPDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_MetaDataGetterCAN_ID_32 */
#define J1939Tp_IsMetaDataSetterCAN_ID_32UsedOfTxPdu(Index)                                         (((boolean)(J1939Tp_GetMetaDataSetterCAN_ID_32IdxOfTxPdu(Index) != J1939TP_NO_METADATASETTERCAN_ID_32IDXOFTXPDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_MetaDataSetterCAN_ID_32 */
#define J1939Tp_IsTxPduTxChannelTxChannelTableIndUsedOfTxPdu(Index)                                 (((boolean)(J1939Tp_GetTxPduTxChannelTxChannelTableIndStartIdxOfTxPdu(Index) != J1939TP_NO_TXPDUTXCHANNELTXCHANNELTABLEINDSTARTIDXOFTXPDU)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd */
#define J1939Tp_IsMetaDataGetterTARGET_ADDRESS_16UsedOfTxSdu(Index)                                 (((boolean)(J1939Tp_GetMetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu(Index) != J1939TP_NO_METADATAGETTERTARGET_ADDRESS_16IDXOFTXSDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
#define J1939Tp_IsMetaDataSetterTARGET_ADDRESS_16UsedOfTxSdu(Index)                                 (((boolean)(J1939Tp_GetMetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu(Index) != J1939TP_NO_METADATASETTERTARGET_ADDRESS_16IDXOFTXSDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
#define J1939Tp_IsTxChannelChannelUsedOfTxSdu(Index)                                                (((boolean)(J1939Tp_GetTxChannelChannelIdxOfTxSdu(Index) != J1939TP_NO_TXCHANNELCHANNELIDXOFTXSDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_TxChannel */
#define J1939Tp_IsTxPduDirectNPduUsedOfTxSdu(Index)                                                 (((boolean)(J1939Tp_GetTxPduDirectNPduIdxOfTxSdu(Index) != J1939TP_NO_TXPDUDIRECTNPDUIDXOFTXSDU)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to J1939Tp_TxPdu */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCSetDataMacros  J1939Tp Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define J1939Tp_SetFppRxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_SetFppTxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_SetRxSduState(Index, Value)                                                         
#define J1939Tp_SetTxPduState(Index, Value)                                                         J1939Tp_GetTxPduStateOfPCConfig()[(Index)] = (Value)
#define J1939Tp_SetTxSduState(Index, Value)                                                         J1939Tp_GetTxSduStateOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCGetAddressOfDataMacros  J1939Tp Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define J1939Tp_GetAddrRxSduState(Index)                                                            ((J1939Tp_RxSduStatePtrType)(NULL_PTR))
#define J1939Tp_GetAddrTxPduState(Index)                                                            (&J1939Tp_GetTxPduState(Index))
#define J1939Tp_GetAddrTxSduState(Index)                                                            (&J1939Tp_GetTxSduState(Index))
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCHasMacros  J1939Tp Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define J1939Tp_HasFinalMagicNumber()                                                               (FALSE != FALSE)
#define J1939Tp_HasFppRxSduSequenceCounter()                                                        (FALSE != FALSE)
#define J1939Tp_HasFppTxSduSequenceCounter()                                                        (FALSE != FALSE)
#define J1939Tp_HasInitDataHashCode()                                                               (FALSE != FALSE)
#define J1939Tp_HasMainPeriod()                                                                     (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32()                                                        (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8()                                                       (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16()                                                (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16()                                                (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32()                                                        (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8()                                                       (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16()                                                (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16()                                                (TRUE != FALSE)
#define J1939Tp_HasRxChannel()                                                                      (FALSE != FALSE)
#define J1939Tp_HasComMChannelOfRxChannel()                                                         (FALSE != FALSE)
#define J1939Tp_HasRxCanFdChannelOfRxChannel()                                                      (FALSE != FALSE)
#define J1939Tp_HasRxCancellationSupportOfRxChannel()                                               (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduRxNSduTableIndEndIdxOfRxChannel()                                 (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduRxNSduTableIndStartIdxOfRxChannel()                               (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduRxNSduTableIndUsedOfRxChannel()                                   (FALSE != FALSE)
#define J1939Tp_HasRxChannelUsesMultiPGOfRxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasRxDaOfRxChannel()                                                                (FALSE != FALSE)
#define J1939Tp_HasRxDynamicBlockCalculationOfRxChannel()                                           (FALSE != FALSE)
#define J1939Tp_HasRxDynamicBufferRatioOfRxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasRxIsobusChannelOfRxChannel()                                                     (FALSE != FALSE)
#define J1939Tp_HasRxPacketsPerBlockOfRxChannel()                                                   (FALSE != FALSE)
#define J1939Tp_HasRxProtocolTypeOfRxChannel()                                                      (FALSE != FALSE)
#define J1939Tp_HasRxRetrySupportOfRxChannel()                                                      (FALSE != FALSE)
#define J1939Tp_HasRxSaOfRxChannel()                                                                (FALSE != FALSE)
#define J1939Tp_HasTxPduFdRxFcNPduIdxOfRxChannel()                                                  (FALSE != FALSE)
#define J1939Tp_HasTxPduFdRxFcNPduUsedOfRxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduRxEtpFcNPduIdxOfRxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduRxEtpFcNPduUsedOfRxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasTxPduRxFcNPduIdxOfRxChannel()                                                    (FALSE != FALSE)
#define J1939Tp_HasTxPduRxFcNPduUsedOfRxChannel()                                                   (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSdu()                                                                (FALSE != FALSE)
#define J1939Tp_HasRxSduRxNSduIdxOfRxChannelRxNSdu()                                                (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduRxNSduTableInd()                                                  (FALSE != FALSE)
#define J1939Tp_HasRxPdu()                                                                          (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataOfRxPdu()                                                             (FALSE != FALSE)
#define J1939Tp_HasInvalidHndOfRxPdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32IdxOfRxPdu()                                              (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32UsedOfRxPdu()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32IdxOfRxPdu()                                              (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32UsedOfRxPdu()                                             (FALSE != FALSE)
#define J1939Tp_HasOnIsobusOfRxPdu()                                                                (FALSE != FALSE)
#define J1939Tp_HasPduFormatOfRxPdu()                                                               (FALSE != FALSE)
#define J1939Tp_HasPduTypeOfRxPdu()                                                                 (FALSE != FALSE)
#define J1939Tp_HasRxPduDaPrioIdxOfRxPdu()                                                          (FALSE != FALSE)
#define J1939Tp_HasRxPduDaPrioUsedOfRxPdu()                                                         (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelRxChannelTableIndEndIdxOfRxPdu()                                   (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelRxChannelTableIndStartIdxOfRxPdu()                                 (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelRxChannelTableIndUsedOfRxPdu()                                     (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduRxSduTableIndEndIdxOfRxPdu()                                           (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduRxSduTableIndStartIdxOfRxPdu()                                         (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduRxSduTableIndUsedOfRxPdu()                                             (FALSE != FALSE)
#define J1939Tp_HasRxPduSaIdxOfRxPdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasRxPduSaUsedOfRxPdu()                                                             (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelTxChannelTableIndEndIdxOfRxPdu()                                   (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelTxChannelTableIndStartIdxOfRxPdu()                                 (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelTxChannelTableIndUsedOfRxPdu()                                     (FALSE != FALSE)
#define J1939Tp_HasRxPduDaPrio()                                                                    (FALSE != FALSE)
#define J1939Tp_HasRxPduDaOfRxPduDaPrio()                                                           (FALSE != FALSE)
#define J1939Tp_HasRxPduPrioOfRxPduDaPrio()                                                         (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannel()                                                                 (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxChannelIdxOfRxPduRxChannel()                                          (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelRxChannelTableInd()                                                (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSdu()                                                                     (FALSE != FALSE)
#define J1939Tp_HasRxSduRxSduIdxOfRxPduRxSdu()                                                      (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduRxSduTableInd()                                                        (FALSE != FALSE)
#define J1939Tp_HasRxPduSa()                                                                        (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannel()                                                                 (FALSE != FALSE)
#define J1939Tp_HasTxChannelTxChannelIdxOfRxPduTxChannel()                                          (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelTxChannelTableInd()                                                (FALSE != FALSE)
#define J1939Tp_HasRxSdu()                                                                          (FALSE != FALSE)
#define J1939Tp_HasFppRxSduSequenceCounterIdxOfRxSdu()                                              (FALSE != FALSE)
#define J1939Tp_HasFppRxSduSequenceCounterUsedOfRxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataDaOfRxSdu()                                                           (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataOfRxSdu()                                                             (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataPrioOfRxSdu()                                                         (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataSaOfRxSdu()                                                           (FALSE != FALSE)
#define J1939Tp_HasInvalidHndOfRxSdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasIsVariableOfRxSdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8IdxOfRxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8UsedOfRxSdu()                                            (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16IdxOfRxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16UsedOfRxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16IdxOfRxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16UsedOfRxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8IdxOfRxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8UsedOfRxSdu()                                            (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16IdxOfRxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16UsedOfRxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16IdxOfRxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16UsedOfRxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasPGNOfRxSdu()                                                                     (FALSE != FALSE)
#define J1939Tp_HasPduLengthOfRxSdu()                                                               (FALSE != FALSE)
#define J1939Tp_HasRxChannelChannelIdxOfRxSdu()                                                     (FALSE != FALSE)
#define J1939Tp_HasRxChannelChannelUsedOfRxSdu()                                                    (FALSE != FALSE)
#define J1939Tp_HasRxSduStateIdxOfRxSdu()                                                           (FALSE != FALSE)
#define J1939Tp_HasSduIdOfRxSdu()                                                                   (FALSE != FALSE)
#define J1939Tp_HasRxSduState()                                                                     (FALSE != FALSE)
#define J1939Tp_HasSizeOfFppRxSduSequenceCounter()                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfFppTxSduSequenceCounter()                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterCAN_ID_32()                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterPRIORITY_8()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterSOURCE_ADDRESS_16()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterTARGET_ADDRESS_16()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterCAN_ID_32()                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterPRIORITY_8()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterSOURCE_ADDRESS_16()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterTARGET_ADDRESS_16()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannel()                                                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannelRxNSdu()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannelRxNSduRxNSduTableInd()                                            (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPdu()                                                                    (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduDaPrio()                                                              (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxChannel()                                                           (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxChannelRxChannelTableInd()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxSdu()                                                               (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxSduRxSduTableInd()                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduSa()                                                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduTxChannel()                                                           (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduTxChannelTxChannelTableInd()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxSdu()                                                                    (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxSduState()                                                               (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannel()                                                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannelTxNSdu()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannelTxNSduTxNSduTableInd()                                            (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPdu()                                                                    (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduRxChannel()                                                           (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduRxChannelRxChannelTableInd()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduState()                                                               (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduTxChannel()                                                           (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduTxChannelTxChannelTableInd()                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxSdu()                                                                    (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxSduState()                                                               (TRUE != FALSE)
#define J1939Tp_HasTime_Fp()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_T1()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_T2()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_T3()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_T4()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_T5()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_Th()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTime_Tr()                                                                        (TRUE != FALSE)
#define J1939Tp_HasTxChannel()                                                                      (TRUE != FALSE)
#define J1939Tp_HasComMChannelOfTxChannel()                                                         (TRUE != FALSE)
#define J1939Tp_HasTxBamInterframeTimeOfTxChannel()                                                 (TRUE != FALSE)
#define J1939Tp_HasTxCanFdChannelOfTxChannel()                                                      (FALSE != FALSE)
#define J1939Tp_HasTxCancellationSupportOfTxChannel()                                               (FALSE != FALSE)
#define J1939Tp_HasTxChannelTxNSduTxNSduTableIndEndIdxOfTxChannel()                                 (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel()                               (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSduTxNSduTableIndUsedOfTxChannel()                                   (TRUE != FALSE)
#define J1939Tp_HasTxChannelUsesMultiPGOfTxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasTxDaOfTxChannel()                                                                (TRUE != FALSE)
#define J1939Tp_HasTxDynamicBlockCalculationOfTxChannel()                                           (FALSE != FALSE)
#define J1939Tp_HasTxIsobusChannelOfTxChannel()                                                     (FALSE != FALSE)
#define J1939Tp_HasTxMaxPacketsPerBlockOfTxChannel()                                                (TRUE != FALSE)
#define J1939Tp_HasTxPduFdTxCmNPduIdxOfTxChannel()                                                  (FALSE != FALSE)
#define J1939Tp_HasTxPduFdTxCmNPduUsedOfTxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduFdTxDtNPduIdxOfTxChannel()                                                  (FALSE != FALSE)
#define J1939Tp_HasTxPduFdTxDtNPduUsedOfTxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduTxCmNPduIdxOfTxChannel()                                                    (TRUE != FALSE)
#define J1939Tp_HasTxPduTxCmNPduUsedOfTxChannel()                                                   (TRUE != FALSE)
#define J1939Tp_HasTxPduTxDtNPduIdxOfTxChannel()                                                    (TRUE != FALSE)
#define J1939Tp_HasTxPduTxDtNPduUsedOfTxChannel()                                                   (TRUE != FALSE)
#define J1939Tp_HasTxPduTxEtpCmNPduIdxOfTxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduTxEtpCmNPduUsedOfTxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasTxPduTxEtpDtNPduIdxOfTxChannel()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduTxEtpDtNPduUsedOfTxChannel()                                                (FALSE != FALSE)
#define J1939Tp_HasTxPendingSupportOfTxChannel()                                                    (FALSE != FALSE)
#define J1939Tp_HasTxPriOfTxChannel()                                                               (TRUE != FALSE)
#define J1939Tp_HasTxProtocolTypeOfTxChannel()                                                      (TRUE != FALSE)
#define J1939Tp_HasTxRetrySupportOfTxChannel()                                                      (FALSE != FALSE)
#define J1939Tp_HasTxSaOfTxChannel()                                                                (TRUE != FALSE)
#define J1939Tp_HasTxVarPriOfTxChannel()                                                            (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSdu()                                                                (TRUE != FALSE)
#define J1939Tp_HasTxSduTxNSduIdxOfTxChannelTxNSdu()                                                (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSduTxNSduTableInd()                                                  (TRUE != FALSE)
#define J1939Tp_HasTxConfTimeout()                                                                  (TRUE != FALSE)
#define J1939Tp_HasTxPdu()                                                                          (TRUE != FALSE)
#define J1939Tp_HasHasMetaDataOfTxPdu()                                                             (TRUE != FALSE)
#define J1939Tp_HasInvalidHndOfTxPdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32IdxOfTxPdu()                                              (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32UsedOfTxPdu()                                             (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32IdxOfTxPdu()                                              (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32UsedOfTxPdu()                                             (TRUE != FALSE)
#define J1939Tp_HasOnIsobusOfTxPdu()                                                                (FALSE != FALSE)
#define J1939Tp_HasPduIdOfTxPdu()                                                                   (TRUE != FALSE)
#define J1939Tp_HasPduTypeOfTxPdu()                                                                 (TRUE != FALSE)
#define J1939Tp_HasTxPduRxChannelRxChannelTableIndEndIdxOfTxPdu()                                   (FALSE != FALSE)
#define J1939Tp_HasTxPduRxChannelRxChannelTableIndStartIdxOfTxPdu()                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduRxChannelRxChannelTableIndUsedOfTxPdu()                                     (FALSE != FALSE)
#define J1939Tp_HasTxPduStateIdxOfTxPdu()                                                           (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelTxChannelTableIndEndIdxOfTxPdu()                                   (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelTxChannelTableIndStartIdxOfTxPdu()                                 (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelTxChannelTableIndUsedOfTxPdu()                                     (TRUE != FALSE)
#define J1939Tp_HasTxPduRxChannel()                                                                 (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxChannelIdxOfTxPduRxChannel()                                          (FALSE != FALSE)
#define J1939Tp_HasTxPduRxChannelRxChannelTableInd()                                                (FALSE != FALSE)
#define J1939Tp_HasTxPduState()                                                                     (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannel()                                                                 (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxChannelIdxOfTxPduTxChannel()                                          (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelTxChannelTableInd()                                                (TRUE != FALSE)
#define J1939Tp_HasTxSdu()                                                                          (TRUE != FALSE)
#define J1939Tp_HasDirectPriorityOfTxSdu()                                                          (TRUE != FALSE)
#define J1939Tp_HasFppTxSduSequenceCounterIdxOfTxSdu()                                              (FALSE != FALSE)
#define J1939Tp_HasFppTxSduSequenceCounterUsedOfTxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataDaOfTxSdu()                                                           (TRUE != FALSE)
#define J1939Tp_HasHasMetaDataOfTxSdu()                                                             (TRUE != FALSE)
#define J1939Tp_HasHasMetaDataPrioOfTxSdu()                                                         (FALSE != FALSE)
#define J1939Tp_HasHasMetaDataSaOfTxSdu()                                                           (FALSE != FALSE)
#define J1939Tp_HasInvalidHndOfTxSdu()                                                              (FALSE != FALSE)
#define J1939Tp_HasIsDirectPrioConfiguredOfTxSdu()                                                  (TRUE != FALSE)
#define J1939Tp_HasIsVariableOfTxSdu()                                                              (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8IdxOfTxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8UsedOfTxSdu()                                            (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16IdxOfTxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16UsedOfTxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu()                                      (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16UsedOfTxSdu()                                     (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8IdxOfTxSdu()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8UsedOfTxSdu()                                            (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16IdxOfTxSdu()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16UsedOfTxSdu()                                     (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu()                                      (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16UsedOfTxSdu()                                     (TRUE != FALSE)
#define J1939Tp_HasPGNOfTxSdu()                                                                     (TRUE != FALSE)
#define J1939Tp_HasPduFormatOfTxSdu()                                                               (TRUE != FALSE)
#define J1939Tp_HasPduLengthOfTxSdu()                                                               (TRUE != FALSE)
#define J1939Tp_HasSduIdOfTxSdu()                                                                   (TRUE != FALSE)
#define J1939Tp_HasTxChannelChannelIdxOfTxSdu()                                                     (TRUE != FALSE)
#define J1939Tp_HasTxChannelChannelUsedOfTxSdu()                                                    (TRUE != FALSE)
#define J1939Tp_HasTxPduDirectFdBcNPduIdxOfTxSdu()                                                  (FALSE != FALSE)
#define J1939Tp_HasTxPduDirectFdBcNPduUsedOfTxSdu()                                                 (FALSE != FALSE)
#define J1939Tp_HasTxPduDirectFdNPduIdxOfTxSdu()                                                    (FALSE != FALSE)
#define J1939Tp_HasTxPduDirectFdNPduUsedOfTxSdu()                                                   (FALSE != FALSE)
#define J1939Tp_HasTxPduDirectNPduIdxOfTxSdu()                                                      (TRUE != FALSE)
#define J1939Tp_HasTxPduDirectNPduUsedOfTxSdu()                                                     (TRUE != FALSE)
#define J1939Tp_HasTxSduStateIdxOfTxSdu()                                                           (TRUE != FALSE)
#define J1939Tp_HasTxSduState()                                                                     (TRUE != FALSE)
#define J1939Tp_HasPCConfig()                                                                       (TRUE != FALSE)
#define J1939Tp_HasFinalMagicNumberOfPCConfig()                                                     (FALSE != FALSE)
#define J1939Tp_HasFppRxSduSequenceCounterOfPCConfig()                                              (FALSE != FALSE)
#define J1939Tp_HasFppTxSduSequenceCounterOfPCConfig()                                              (FALSE != FALSE)
#define J1939Tp_HasInitDataHashCodeOfPCConfig()                                                     (FALSE != FALSE)
#define J1939Tp_HasMainPeriodOfPCConfig()                                                           (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterCAN_ID_32OfPCConfig()                                              (TRUE != FALSE)
#define J1939Tp_HasMetaDataGetterPRIORITY_8OfPCConfig()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterSOURCE_ADDRESS_16OfPCConfig()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                      (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterCAN_ID_32OfPCConfig()                                              (TRUE != FALSE)
#define J1939Tp_HasMetaDataSetterPRIORITY_8OfPCConfig()                                             (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterSOURCE_ADDRESS_16OfPCConfig()                                      (FALSE != FALSE)
#define J1939Tp_HasMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                      (TRUE != FALSE)
#define J1939Tp_HasRxChannelOfPCConfig()                                                            (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduOfPCConfig()                                                      (FALSE != FALSE)
#define J1939Tp_HasRxChannelRxNSduRxNSduTableIndOfPCConfig()                                        (FALSE != FALSE)
#define J1939Tp_HasRxPduDaPrioOfPCConfig()                                                          (FALSE != FALSE)
#define J1939Tp_HasRxPduOfPCConfig()                                                                (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelOfPCConfig()                                                       (FALSE != FALSE)
#define J1939Tp_HasRxPduRxChannelRxChannelTableIndOfPCConfig()                                      (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduOfPCConfig()                                                           (FALSE != FALSE)
#define J1939Tp_HasRxPduRxSduRxSduTableIndOfPCConfig()                                              (FALSE != FALSE)
#define J1939Tp_HasRxPduSaOfPCConfig()                                                              (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelOfPCConfig()                                                       (FALSE != FALSE)
#define J1939Tp_HasRxPduTxChannelTxChannelTableIndOfPCConfig()                                      (FALSE != FALSE)
#define J1939Tp_HasRxSduOfPCConfig()                                                                (FALSE != FALSE)
#define J1939Tp_HasRxSduStateOfPCConfig()                                                           (FALSE != FALSE)
#define J1939Tp_HasSizeOfFppRxSduSequenceCounterOfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfFppTxSduSequenceCounterOfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterCAN_ID_32OfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterPRIORITY_8OfPCConfig()                                       (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterSOURCE_ADDRESS_16OfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataGetterTARGET_ADDRESS_16OfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterCAN_ID_32OfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterPRIORITY_8OfPCConfig()                                       (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterSOURCE_ADDRESS_16OfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfMetaDataSetterTARGET_ADDRESS_16OfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannelOfPCConfig()                                                      (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannelRxNSduOfPCConfig()                                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxChannelRxNSduRxNSduTableIndOfPCConfig()                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduDaPrioOfPCConfig()                                                    (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduOfPCConfig()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxChannelOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxChannelRxChannelTableIndOfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxSduOfPCConfig()                                                     (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduRxSduRxSduTableIndOfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduSaOfPCConfig()                                                        (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduTxChannelOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxPduTxChannelTxChannelTableIndOfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxSduOfPCConfig()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfRxSduStateOfPCConfig()                                                     (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannelOfPCConfig()                                                      (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannelTxNSduOfPCConfig()                                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxChannelTxNSduTxNSduTableIndOfPCConfig()                                  (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduOfPCConfig()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduRxChannelOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduRxChannelRxChannelTableIndOfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduStateOfPCConfig()                                                     (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduTxChannelOfPCConfig()                                                 (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxPduTxChannelTxChannelTableIndOfPCConfig()                                (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxSduOfPCConfig()                                                          (TRUE != FALSE)
#define J1939Tp_HasSizeOfTxSduStateOfPCConfig()                                                     (TRUE != FALSE)
#define J1939Tp_HasTime_FpOfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_T1OfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_T2OfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_T3OfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_T4OfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_T5OfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_ThOfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTime_TrOfPCConfig()                                                              (TRUE != FALSE)
#define J1939Tp_HasTxChannelOfPCConfig()                                                            (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSduOfPCConfig()                                                      (TRUE != FALSE)
#define J1939Tp_HasTxChannelTxNSduTxNSduTableIndOfPCConfig()                                        (TRUE != FALSE)
#define J1939Tp_HasTxConfTimeoutOfPCConfig()                                                        (TRUE != FALSE)
#define J1939Tp_HasTxPduOfPCConfig()                                                                (TRUE != FALSE)
#define J1939Tp_HasTxPduRxChannelOfPCConfig()                                                       (FALSE != FALSE)
#define J1939Tp_HasTxPduRxChannelRxChannelTableIndOfPCConfig()                                      (FALSE != FALSE)
#define J1939Tp_HasTxPduStateOfPCConfig()                                                           (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelOfPCConfig()                                                       (TRUE != FALSE)
#define J1939Tp_HasTxPduTxChannelTxChannelTableIndOfPCConfig()                                      (TRUE != FALSE)
#define J1939Tp_HasTxSduOfPCConfig()                                                                (TRUE != FALSE)
#define J1939Tp_HasTxSduStateOfPCConfig()                                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCExistsEnumMacros  J1939Tp Exists Enum Macros (PRE_COMPILE)
  \brief  These macros can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define J1939Tp_ExistsPROTOCOL_UNUSEDRxProtocolTypeOfRxChannel()                                    (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_BAMRxProtocolTypeOfRxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_CMDTRxProtocolTypeOfRxChannel()                                      (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FD_BAMRxProtocolTypeOfRxChannel()                                    (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FD_CMDTRxProtocolTypeOfRxChannel()                                   (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_ETPRxProtocolTypeOfRxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FPPRxProtocolTypeOfRxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsUNDEFINEDPduFormatOfRxPdu()                                                   (FALSE != FALSE)
#define J1939Tp_ExistsPDU1PduFormatOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsPDU2PduFormatOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsUNUSEDPduTypeOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsDIRECTPduTypeOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsFDDIRECTPduTypeOfRxPdu()                                                      (FALSE != FALSE)
#define J1939Tp_ExistsFDDIRECTBCPduTypeOfRxPdu()                                                    (FALSE != FALSE)
#define J1939Tp_ExistsTPCMPduTypeOfRxPdu()                                                          (FALSE != FALSE)
#define J1939Tp_ExistsTPDTPduTypeOfRxPdu()                                                          (FALSE != FALSE)
#define J1939Tp_ExistsFDTPCMPduTypeOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsFDTPDTPduTypeOfRxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsETPCMPduTypeOfRxPdu()                                                         (FALSE != FALSE)
#define J1939Tp_ExistsETPDTPduTypeOfRxPdu()                                                         (FALSE != FALSE)
#define J1939Tp_ExistsFPPPduTypeOfRxPdu()                                                           (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_UNUSEDTxProtocolTypeOfTxChannel()                                    (TRUE != FALSE)
#define J1939Tp_ExistsPROTOCOL_BAMTxProtocolTypeOfTxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_CMDTTxProtocolTypeOfTxChannel()                                      (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FD_BAMTxProtocolTypeOfTxChannel()                                    (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FD_CMDTTxProtocolTypeOfTxChannel()                                   (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_ETPTxProtocolTypeOfTxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsPROTOCOL_FPPTxProtocolTypeOfTxChannel()                                       (FALSE != FALSE)
#define J1939Tp_ExistsUNUSEDPduTypeOfTxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsDIRECTPduTypeOfTxPdu()                                                        (TRUE != FALSE)
#define J1939Tp_ExistsFDDIRECTPduTypeOfTxPdu()                                                      (FALSE != FALSE)
#define J1939Tp_ExistsFDDIRECTBCPduTypeOfTxPdu()                                                    (FALSE != FALSE)
#define J1939Tp_ExistsTPCMPduTypeOfTxPdu()                                                          (TRUE != FALSE)
#define J1939Tp_ExistsTPDTPduTypeOfTxPdu()                                                          (TRUE != FALSE)
#define J1939Tp_ExistsFDTPCMPduTypeOfTxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsFDTPDTPduTypeOfTxPdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsETPCMPduTypeOfTxPdu()                                                         (FALSE != FALSE)
#define J1939Tp_ExistsETPDTPduTypeOfTxPdu()                                                         (FALSE != FALSE)
#define J1939Tp_ExistsFPPPduTypeOfTxPdu()                                                           (FALSE != FALSE)
#define J1939Tp_ExistsUNDEFINEDPduFormatOfTxSdu()                                                   (FALSE != FALSE)
#define J1939Tp_ExistsPDU1PduFormatOfTxSdu()                                                        (FALSE != FALSE)
#define J1939Tp_ExistsPDU2PduFormatOfTxSdu()                                                        (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCIncrementDataMacros  J1939Tp Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define J1939Tp_IncFppRxSduSequenceCounter(Index)                                                   
#define J1939Tp_IncFppTxSduSequenceCounter(Index)                                                   
#define J1939Tp_IncRxSduState(Index)                                                                
#define J1939Tp_IncTxPduState(Index)                                                                J1939Tp_GetTxPduState(Index)++
#define J1939Tp_IncTxSduState(Index)                                                                J1939Tp_GetTxSduState(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCDecrementDataMacros  J1939Tp Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define J1939Tp_DecFppRxSduSequenceCounter(Index)                                                   
#define J1939Tp_DecFppTxSduSequenceCounter(Index)                                                   
#define J1939Tp_DecRxSduState(Index)                                                                
#define J1939Tp_DecTxPduState(Index)                                                                J1939Tp_GetTxPduState(Index)--
#define J1939Tp_DecTxSduState(Index)                                                                J1939Tp_GetTxSduState(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCAddDataMacros  J1939Tp Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define J1939Tp_AddFppRxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_AddFppTxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_AddRxSduState(Index, Value)                                                         
#define J1939Tp_AddTxPduState(Index, Value)                                                         J1939Tp_SetTxPduState(Index, (J1939Tp_GetTxPduState(Index) + Value))
#define J1939Tp_AddTxSduState(Index, Value)                                                         J1939Tp_SetTxSduState(Index, (J1939Tp_GetTxSduState(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCSubstractDataMacros  J1939Tp Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define J1939Tp_SubFppRxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_SubFppTxSduSequenceCounter(Index, Value)                                            
#define J1939Tp_SubRxSduState(Index, Value)                                                         
#define J1939Tp_SubTxPduState(Index, Value)                                                         J1939Tp_SetTxPduState(Index, (J1939Tp_GetTxPduState(Index) - Value))
#define J1939Tp_SubTxSduState(Index, Value)                                                         J1939Tp_SetTxSduState(Index, (J1939Tp_GetTxSduState(Index) - Value))
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
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPCSizeOfTypes  J1939Tp SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for J1939Tp_SizeOfFppRxSduSequenceCounter */
typedef uint8 J1939Tp_SizeOfFppRxSduSequenceCounterType;

/**   \brief  value based type definition for J1939Tp_SizeOfFppTxSduSequenceCounter */
typedef uint8 J1939Tp_SizeOfFppTxSduSequenceCounterType;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataGetterCAN_ID_32 */
typedef uint8 J1939Tp_SizeOfMetaDataGetterCAN_ID_32Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataGetterPRIORITY_8 */
typedef uint8 J1939Tp_SizeOfMetaDataGetterPRIORITY_8Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataGetterSOURCE_ADDRESS_16 */
typedef uint8 J1939Tp_SizeOfMetaDataGetterSOURCE_ADDRESS_16Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataGetterTARGET_ADDRESS_16 */
typedef uint8 J1939Tp_SizeOfMetaDataGetterTARGET_ADDRESS_16Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataSetterCAN_ID_32 */
typedef uint8 J1939Tp_SizeOfMetaDataSetterCAN_ID_32Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataSetterPRIORITY_8 */
typedef uint8 J1939Tp_SizeOfMetaDataSetterPRIORITY_8Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataSetterSOURCE_ADDRESS_16 */
typedef uint8 J1939Tp_SizeOfMetaDataSetterSOURCE_ADDRESS_16Type;

/**   \brief  value based type definition for J1939Tp_SizeOfMetaDataSetterTARGET_ADDRESS_16 */
typedef uint8 J1939Tp_SizeOfMetaDataSetterTARGET_ADDRESS_16Type;

/**   \brief  value based type definition for J1939Tp_SizeOfRxChannel */
typedef uint8 J1939Tp_SizeOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxChannelRxNSdu */
typedef uint8 J1939Tp_SizeOfRxChannelRxNSduType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxChannelRxNSduRxNSduTableInd */
typedef uint8 J1939Tp_SizeOfRxChannelRxNSduRxNSduTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPdu */
typedef uint8 J1939Tp_SizeOfRxPduType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduDaPrio */
typedef uint8 J1939Tp_SizeOfRxPduDaPrioType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduRxChannel */
typedef uint8 J1939Tp_SizeOfRxPduRxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduRxChannelRxChannelTableInd */
typedef uint8 J1939Tp_SizeOfRxPduRxChannelRxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduRxSdu */
typedef uint8 J1939Tp_SizeOfRxPduRxSduType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduRxSduRxSduTableInd */
typedef uint8 J1939Tp_SizeOfRxPduRxSduRxSduTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduSa */
typedef uint8 J1939Tp_SizeOfRxPduSaType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduTxChannel */
typedef uint8 J1939Tp_SizeOfRxPduTxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxPduTxChannelTxChannelTableInd */
typedef uint8 J1939Tp_SizeOfRxPduTxChannelTxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxSdu */
typedef uint8 J1939Tp_SizeOfRxSduType;

/**   \brief  value based type definition for J1939Tp_SizeOfRxSduState */
typedef uint8 J1939Tp_SizeOfRxSduStateType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxChannel */
typedef uint8 J1939Tp_SizeOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxChannelTxNSdu */
typedef uint8 J1939Tp_SizeOfTxChannelTxNSduType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxChannelTxNSduTxNSduTableInd */
typedef uint8 J1939Tp_SizeOfTxChannelTxNSduTxNSduTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPdu */
typedef uint8 J1939Tp_SizeOfTxPduType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPduRxChannel */
typedef uint8 J1939Tp_SizeOfTxPduRxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPduRxChannelRxChannelTableInd */
typedef uint8 J1939Tp_SizeOfTxPduRxChannelRxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPduState */
typedef uint8 J1939Tp_SizeOfTxPduStateType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPduTxChannel */
typedef uint8 J1939Tp_SizeOfTxPduTxChannelType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxPduTxChannelTxChannelTableInd */
typedef uint8 J1939Tp_SizeOfTxPduTxChannelTxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxSdu */
typedef uint8 J1939Tp_SizeOfTxSduType;

/**   \brief  value based type definition for J1939Tp_SizeOfTxSduState */
typedef uint8 J1939Tp_SizeOfTxSduStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPCIterableTypes  J1939Tp Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate J1939Tp_FppRxSduSequenceCounter */
typedef uint8_least J1939Tp_FppRxSduSequenceCounterIterType;

/**   \brief  type used to iterate J1939Tp_FppTxSduSequenceCounter */
typedef uint8_least J1939Tp_FppTxSduSequenceCounterIterType;

/**   \brief  type used to iterate J1939Tp_MetaDataGetterCAN_ID_32 */
typedef uint8_least J1939Tp_MetaDataGetterCAN_ID_32IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataGetterPRIORITY_8 */
typedef uint8_least J1939Tp_MetaDataGetterPRIORITY_8IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataGetterSOURCE_ADDRESS_16 */
typedef uint8_least J1939Tp_MetaDataGetterSOURCE_ADDRESS_16IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
typedef uint8_least J1939Tp_MetaDataGetterTARGET_ADDRESS_16IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataSetterCAN_ID_32 */
typedef uint8_least J1939Tp_MetaDataSetterCAN_ID_32IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataSetterPRIORITY_8 */
typedef uint8_least J1939Tp_MetaDataSetterPRIORITY_8IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataSetterSOURCE_ADDRESS_16 */
typedef uint8_least J1939Tp_MetaDataSetterSOURCE_ADDRESS_16IterType;

/**   \brief  type used to iterate J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
typedef uint8_least J1939Tp_MetaDataSetterTARGET_ADDRESS_16IterType;

/**   \brief  type used to iterate J1939Tp_RxChannel */
typedef uint8_least J1939Tp_RxChannelIterType;

/**   \brief  type used to iterate J1939Tp_RxChannelRxNSdu */
typedef uint8_least J1939Tp_RxChannelRxNSduIterType;

/**   \brief  type used to iterate J1939Tp_RxChannelRxNSduRxNSduTableInd */
typedef uint8_least J1939Tp_RxChannelRxNSduRxNSduTableIndIterType;

/**   \brief  type used to iterate J1939Tp_RxPdu */
typedef uint8_least J1939Tp_RxPduIterType;

/**   \brief  type used to iterate J1939Tp_RxPduDaPrio */
typedef uint8_least J1939Tp_RxPduDaPrioIterType;

/**   \brief  type used to iterate J1939Tp_RxPduRxChannel */
typedef uint8_least J1939Tp_RxPduRxChannelIterType;

/**   \brief  type used to iterate J1939Tp_RxPduRxChannelRxChannelTableInd */
typedef uint8_least J1939Tp_RxPduRxChannelRxChannelTableIndIterType;

/**   \brief  type used to iterate J1939Tp_RxPduRxSdu */
typedef uint8_least J1939Tp_RxPduRxSduIterType;

/**   \brief  type used to iterate J1939Tp_RxPduRxSduRxSduTableInd */
typedef uint8_least J1939Tp_RxPduRxSduRxSduTableIndIterType;

/**   \brief  type used to iterate J1939Tp_RxPduSa */
typedef uint8_least J1939Tp_RxPduSaIterType;

/**   \brief  type used to iterate J1939Tp_RxPduTxChannel */
typedef uint8_least J1939Tp_RxPduTxChannelIterType;

/**   \brief  type used to iterate J1939Tp_RxPduTxChannelTxChannelTableInd */
typedef uint8_least J1939Tp_RxPduTxChannelTxChannelTableIndIterType;

/**   \brief  type used to iterate J1939Tp_RxSdu */
typedef uint8_least J1939Tp_RxSduIterType;

/**   \brief  type used to iterate J1939Tp_RxSduState */
typedef uint8_least J1939Tp_RxSduStateIterType;

/**   \brief  type used to iterate J1939Tp_TxChannel */
typedef uint8_least J1939Tp_TxChannelIterType;

/**   \brief  type used to iterate J1939Tp_TxChannelTxNSdu */
typedef uint8_least J1939Tp_TxChannelTxNSduIterType;

/**   \brief  type used to iterate J1939Tp_TxChannelTxNSduTxNSduTableInd */
typedef uint8_least J1939Tp_TxChannelTxNSduTxNSduTableIndIterType;

/**   \brief  type used to iterate J1939Tp_TxPdu */
typedef uint8_least J1939Tp_TxPduIterType;

/**   \brief  type used to iterate J1939Tp_TxPduRxChannel */
typedef uint8_least J1939Tp_TxPduRxChannelIterType;

/**   \brief  type used to iterate J1939Tp_TxPduRxChannelRxChannelTableInd */
typedef uint8_least J1939Tp_TxPduRxChannelRxChannelTableIndIterType;

/**   \brief  type used to iterate J1939Tp_TxPduState */
typedef uint8_least J1939Tp_TxPduStateIterType;

/**   \brief  type used to iterate J1939Tp_TxPduTxChannel */
typedef uint8_least J1939Tp_TxPduTxChannelIterType;

/**   \brief  type used to iterate J1939Tp_TxPduTxChannelTxChannelTableInd */
typedef uint8_least J1939Tp_TxPduTxChannelTxChannelTableIndIterType;

/**   \brief  type used to iterate J1939Tp_TxSdu */
typedef uint8_least J1939Tp_TxSduIterType;

/**   \brief  type used to iterate J1939Tp_TxSduState */
typedef uint8_least J1939Tp_TxSduStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCValueTypes  J1939Tp Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for J1939Tp_FinalMagicNumber */
typedef uint16 J1939Tp_FinalMagicNumberType;

/**   \brief  value based type definition for J1939Tp_FppRxSduSequenceCounter */
typedef uint8 J1939Tp_FppRxSduSequenceCounterType;

/**   \brief  value based type definition for J1939Tp_FppTxSduSequenceCounter */
typedef uint8 J1939Tp_FppTxSduSequenceCounterType;

/**   \brief  value based type definition for J1939Tp_InitDataHashCode */
typedef sint32 J1939Tp_InitDataHashCodeType;

/**   \brief  value based type definition for J1939Tp_MainPeriod */
typedef uint8 J1939Tp_MainPeriodType;

/**   \brief  value based type definition for J1939Tp_ComMChannelOfRxChannel */
typedef NetworkHandleType J1939Tp_ComMChannelOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxCanFdChannelOfRxChannel */
typedef boolean J1939Tp_RxCanFdChannelOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxCancellationSupportOfRxChannel */
typedef boolean J1939Tp_RxCancellationSupportOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxNSduRxNSduTableIndEndIdxOfRxChannel */
typedef uint8 J1939Tp_RxChannelRxNSduRxNSduTableIndEndIdxOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxNSduRxNSduTableIndStartIdxOfRxChannel */
typedef uint8 J1939Tp_RxChannelRxNSduRxNSduTableIndStartIdxOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxNSduRxNSduTableIndUsedOfRxChannel */
typedef boolean J1939Tp_RxChannelRxNSduRxNSduTableIndUsedOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxChannelUsesMultiPGOfRxChannel */
typedef boolean J1939Tp_RxChannelUsesMultiPGOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxDaOfRxChannel */
typedef uint8 J1939Tp_RxDaOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxDynamicBlockCalculationOfRxChannel */
typedef boolean J1939Tp_RxDynamicBlockCalculationOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxDynamicBufferRatioOfRxChannel */
typedef uint8 J1939Tp_RxDynamicBufferRatioOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxIsobusChannelOfRxChannel */
typedef boolean J1939Tp_RxIsobusChannelOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxPacketsPerBlockOfRxChannel */
typedef uint8 J1939Tp_RxPacketsPerBlockOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxProtocolTypeOfRxChannel */
typedef uint8 J1939Tp_RxProtocolTypeOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxRetrySupportOfRxChannel */
typedef boolean J1939Tp_RxRetrySupportOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxSaOfRxChannel */
typedef uint8 J1939Tp_RxSaOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdRxFcNPduIdxOfRxChannel */
typedef uint8 J1939Tp_TxPduFdRxFcNPduIdxOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdRxFcNPduUsedOfRxChannel */
typedef boolean J1939Tp_TxPduFdRxFcNPduUsedOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduRxEtpFcNPduIdxOfRxChannel */
typedef uint8 J1939Tp_TxPduRxEtpFcNPduIdxOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduRxEtpFcNPduUsedOfRxChannel */
typedef boolean J1939Tp_TxPduRxEtpFcNPduUsedOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduRxFcNPduIdxOfRxChannel */
typedef uint8 J1939Tp_TxPduRxFcNPduIdxOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduRxFcNPduUsedOfRxChannel */
typedef boolean J1939Tp_TxPduRxFcNPduUsedOfRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxSduRxNSduIdxOfRxChannelRxNSdu */
typedef uint8 J1939Tp_RxSduRxNSduIdxOfRxChannelRxNSduType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxNSduRxNSduTableInd */
typedef uint8 J1939Tp_RxChannelRxNSduRxNSduTableIndType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataOfRxPdu */
typedef boolean J1939Tp_HasMetaDataOfRxPduType;

/**   \brief  value based type definition for J1939Tp_InvalidHndOfRxPdu */
typedef boolean J1939Tp_InvalidHndOfRxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterCAN_ID_32IdxOfRxPdu */
typedef uint8 J1939Tp_MetaDataGetterCAN_ID_32IdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterCAN_ID_32UsedOfRxPdu */
typedef boolean J1939Tp_MetaDataGetterCAN_ID_32UsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterCAN_ID_32IdxOfRxPdu */
typedef uint8 J1939Tp_MetaDataSetterCAN_ID_32IdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterCAN_ID_32UsedOfRxPdu */
typedef boolean J1939Tp_MetaDataSetterCAN_ID_32UsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_OnIsobusOfRxPdu */
typedef boolean J1939Tp_OnIsobusOfRxPduType;

/**   \brief  value based type definition for J1939Tp_PduFormatOfRxPdu */
typedef uint8 J1939Tp_PduFormatOfRxPduType;

/**   \brief  value based type definition for J1939Tp_PduTypeOfRxPdu */
typedef uint8 J1939Tp_PduTypeOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduDaPrioIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduDaPrioIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduDaPrioUsedOfRxPdu */
typedef boolean J1939Tp_RxPduDaPrioUsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxChannelRxChannelTableIndEndIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduRxChannelRxChannelTableIndEndIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxChannelRxChannelTableIndStartIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduRxChannelRxChannelTableIndStartIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxChannelRxChannelTableIndUsedOfRxPdu */
typedef boolean J1939Tp_RxPduRxChannelRxChannelTableIndUsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxSduRxSduTableIndEndIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduRxSduRxSduTableIndEndIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxSduRxSduTableIndStartIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduRxSduRxSduTableIndStartIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxSduRxSduTableIndUsedOfRxPdu */
typedef boolean J1939Tp_RxPduRxSduRxSduTableIndUsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduSaIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduSaIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduSaUsedOfRxPdu */
typedef boolean J1939Tp_RxPduSaUsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduTxChannelTxChannelTableIndEndIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduTxChannelTxChannelTableIndEndIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduTxChannelTxChannelTableIndStartIdxOfRxPdu */
typedef uint8 J1939Tp_RxPduTxChannelTxChannelTableIndStartIdxOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduTxChannelTxChannelTableIndUsedOfRxPdu */
typedef boolean J1939Tp_RxPduTxChannelTxChannelTableIndUsedOfRxPduType;

/**   \brief  value based type definition for J1939Tp_RxPduDaOfRxPduDaPrio */
typedef uint8 J1939Tp_RxPduDaOfRxPduDaPrioType;

/**   \brief  value based type definition for J1939Tp_RxPduPrioOfRxPduDaPrio */
typedef uint8 J1939Tp_RxPduPrioOfRxPduDaPrioType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxChannelIdxOfRxPduRxChannel */
typedef uint8 J1939Tp_RxChannelRxChannelIdxOfRxPduRxChannelType;

/**   \brief  value based type definition for J1939Tp_RxPduRxChannelRxChannelTableInd */
typedef uint8 J1939Tp_RxPduRxChannelRxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_RxSduRxSduIdxOfRxPduRxSdu */
typedef uint8 J1939Tp_RxSduRxSduIdxOfRxPduRxSduType;

/**   \brief  value based type definition for J1939Tp_RxPduRxSduRxSduTableInd */
typedef uint8 J1939Tp_RxPduRxSduRxSduTableIndType;

/**   \brief  value based type definition for J1939Tp_RxPduSa */
typedef uint8 J1939Tp_RxPduSaType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxChannelIdxOfRxPduTxChannel */
typedef uint8 J1939Tp_TxChannelTxChannelIdxOfRxPduTxChannelType;

/**   \brief  value based type definition for J1939Tp_RxPduTxChannelTxChannelTableInd */
typedef uint8 J1939Tp_RxPduTxChannelTxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_FppRxSduSequenceCounterIdxOfRxSdu */
typedef uint8 J1939Tp_FppRxSduSequenceCounterIdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_FppRxSduSequenceCounterUsedOfRxSdu */
typedef boolean J1939Tp_FppRxSduSequenceCounterUsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataDaOfRxSdu */
typedef boolean J1939Tp_HasMetaDataDaOfRxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataOfRxSdu */
typedef boolean J1939Tp_HasMetaDataOfRxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataPrioOfRxSdu */
typedef boolean J1939Tp_HasMetaDataPrioOfRxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataSaOfRxSdu */
typedef boolean J1939Tp_HasMetaDataSaOfRxSduType;

/**   \brief  value based type definition for J1939Tp_InvalidHndOfRxSdu */
typedef boolean J1939Tp_InvalidHndOfRxSduType;

/**   \brief  value based type definition for J1939Tp_IsVariableOfRxSdu */
typedef boolean J1939Tp_IsVariableOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterPRIORITY_8IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataGetterPRIORITY_8IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterPRIORITY_8UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataGetterPRIORITY_8UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterSOURCE_ADDRESS_16IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataGetterSOURCE_ADDRESS_16IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterSOURCE_ADDRESS_16UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataGetterSOURCE_ADDRESS_16UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterTARGET_ADDRESS_16IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataGetterTARGET_ADDRESS_16IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterTARGET_ADDRESS_16UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataGetterTARGET_ADDRESS_16UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterPRIORITY_8IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataSetterPRIORITY_8IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterPRIORITY_8UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataSetterPRIORITY_8UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterSOURCE_ADDRESS_16IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataSetterSOURCE_ADDRESS_16IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterSOURCE_ADDRESS_16UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataSetterSOURCE_ADDRESS_16UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterTARGET_ADDRESS_16IdxOfRxSdu */
typedef uint8 J1939Tp_MetaDataSetterTARGET_ADDRESS_16IdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterTARGET_ADDRESS_16UsedOfRxSdu */
typedef boolean J1939Tp_MetaDataSetterTARGET_ADDRESS_16UsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_PGNOfRxSdu */
typedef uint8 J1939Tp_PGNOfRxSduType;

/**   \brief  value based type definition for J1939Tp_PduLengthOfRxSdu */
typedef uint8 J1939Tp_PduLengthOfRxSduType;

/**   \brief  value based type definition for J1939Tp_RxChannelChannelIdxOfRxSdu */
typedef uint8 J1939Tp_RxChannelChannelIdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_RxChannelChannelUsedOfRxSdu */
typedef boolean J1939Tp_RxChannelChannelUsedOfRxSduType;

/**   \brief  value based type definition for J1939Tp_RxSduStateIdxOfRxSdu */
typedef uint8 J1939Tp_RxSduStateIdxOfRxSduType;

/**   \brief  value based type definition for J1939Tp_SduIdOfRxSdu */
typedef uint8 J1939Tp_SduIdOfRxSduType;

/**   \brief  value based type definition for J1939Tp_Time_Fp */
typedef uint8 J1939Tp_Time_FpType;

/**   \brief  value based type definition for J1939Tp_Time_T1 */
typedef uint8 J1939Tp_Time_T1Type;

/**   \brief  value based type definition for J1939Tp_Time_T2 */
typedef uint8 J1939Tp_Time_T2Type;

/**   \brief  value based type definition for J1939Tp_Time_T3 */
typedef uint8 J1939Tp_Time_T3Type;

/**   \brief  value based type definition for J1939Tp_Time_T4 */
typedef uint8 J1939Tp_Time_T4Type;

/**   \brief  value based type definition for J1939Tp_Time_T5 */
typedef uint16 J1939Tp_Time_T5Type;

/**   \brief  value based type definition for J1939Tp_Time_Th */
typedef uint8 J1939Tp_Time_ThType;

/**   \brief  value based type definition for J1939Tp_Time_Tr */
typedef uint8 J1939Tp_Time_TrType;

/**   \brief  value based type definition for J1939Tp_ComMChannelOfTxChannel */
typedef NetworkHandleType J1939Tp_ComMChannelOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxBamInterframeTimeOfTxChannel */
typedef uint8 J1939Tp_TxBamInterframeTimeOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxCanFdChannelOfTxChannel */
typedef boolean J1939Tp_TxCanFdChannelOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxCancellationSupportOfTxChannel */
typedef boolean J1939Tp_TxCancellationSupportOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxNSduTxNSduTableIndEndIdxOfTxChannel */
typedef uint8 J1939Tp_TxChannelTxNSduTxNSduTableIndEndIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel */
typedef uint8 J1939Tp_TxChannelTxNSduTxNSduTableIndStartIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxNSduTxNSduTableIndUsedOfTxChannel */
typedef boolean J1939Tp_TxChannelTxNSduTxNSduTableIndUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxChannelUsesMultiPGOfTxChannel */
typedef boolean J1939Tp_TxChannelUsesMultiPGOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxDaOfTxChannel */
typedef uint8 J1939Tp_TxDaOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxDynamicBlockCalculationOfTxChannel */
typedef boolean J1939Tp_TxDynamicBlockCalculationOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxIsobusChannelOfTxChannel */
typedef boolean J1939Tp_TxIsobusChannelOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxMaxPacketsPerBlockOfTxChannel */
typedef uint8 J1939Tp_TxMaxPacketsPerBlockOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdTxCmNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduFdTxCmNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdTxCmNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduFdTxCmNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdTxDtNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduFdTxDtNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduFdTxDtNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduFdTxDtNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxCmNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduTxCmNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxCmNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduTxCmNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxDtNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduTxDtNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxDtNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduTxDtNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxEtpCmNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduTxEtpCmNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxEtpCmNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduTxEtpCmNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxEtpDtNPduIdxOfTxChannel */
typedef uint8 J1939Tp_TxPduTxEtpDtNPduIdxOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxEtpDtNPduUsedOfTxChannel */
typedef boolean J1939Tp_TxPduTxEtpDtNPduUsedOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPendingSupportOfTxChannel */
typedef boolean J1939Tp_TxPendingSupportOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPriOfTxChannel */
typedef uint8 J1939Tp_TxPriOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxProtocolTypeOfTxChannel */
typedef uint8 J1939Tp_TxProtocolTypeOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxRetrySupportOfTxChannel */
typedef boolean J1939Tp_TxRetrySupportOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxSaOfTxChannel */
typedef uint8 J1939Tp_TxSaOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxVarPriOfTxChannel */
typedef boolean J1939Tp_TxVarPriOfTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxSduTxNSduIdxOfTxChannelTxNSdu */
typedef uint8 J1939Tp_TxSduTxNSduIdxOfTxChannelTxNSduType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxNSduTxNSduTableInd */
typedef uint8 J1939Tp_TxChannelTxNSduTxNSduTableIndType;

/**   \brief  value based type definition for J1939Tp_TxConfTimeout */
typedef uint8 J1939Tp_TxConfTimeoutType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataOfTxPdu */
typedef boolean J1939Tp_HasMetaDataOfTxPduType;

/**   \brief  value based type definition for J1939Tp_InvalidHndOfTxPdu */
typedef boolean J1939Tp_InvalidHndOfTxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterCAN_ID_32IdxOfTxPdu */
typedef uint8 J1939Tp_MetaDataGetterCAN_ID_32IdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterCAN_ID_32UsedOfTxPdu */
typedef boolean J1939Tp_MetaDataGetterCAN_ID_32UsedOfTxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterCAN_ID_32IdxOfTxPdu */
typedef uint8 J1939Tp_MetaDataSetterCAN_ID_32IdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterCAN_ID_32UsedOfTxPdu */
typedef boolean J1939Tp_MetaDataSetterCAN_ID_32UsedOfTxPduType;

/**   \brief  value based type definition for J1939Tp_OnIsobusOfTxPdu */
typedef boolean J1939Tp_OnIsobusOfTxPduType;

/**   \brief  value based type definition for J1939Tp_PduIdOfTxPdu */
typedef uint8 J1939Tp_PduIdOfTxPduType;

/**   \brief  value based type definition for J1939Tp_PduTypeOfTxPdu */
typedef uint8 J1939Tp_PduTypeOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduRxChannelRxChannelTableIndEndIdxOfTxPdu */
typedef uint8 J1939Tp_TxPduRxChannelRxChannelTableIndEndIdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduRxChannelRxChannelTableIndStartIdxOfTxPdu */
typedef uint8 J1939Tp_TxPduRxChannelRxChannelTableIndStartIdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduRxChannelRxChannelTableIndUsedOfTxPdu */
typedef boolean J1939Tp_TxPduRxChannelRxChannelTableIndUsedOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduStateIdxOfTxPdu */
typedef uint8 J1939Tp_TxPduStateIdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduTxChannelTxChannelTableIndEndIdxOfTxPdu */
typedef uint8 J1939Tp_TxPduTxChannelTxChannelTableIndEndIdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduTxChannelTxChannelTableIndStartIdxOfTxPdu */
typedef uint8 J1939Tp_TxPduTxChannelTxChannelTableIndStartIdxOfTxPduType;

/**   \brief  value based type definition for J1939Tp_TxPduTxChannelTxChannelTableIndUsedOfTxPdu */
typedef boolean J1939Tp_TxPduTxChannelTxChannelTableIndUsedOfTxPduType;

/**   \brief  value based type definition for J1939Tp_RxChannelRxChannelIdxOfTxPduRxChannel */
typedef uint8 J1939Tp_RxChannelRxChannelIdxOfTxPduRxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduRxChannelRxChannelTableInd */
typedef uint8 J1939Tp_TxPduRxChannelRxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_TxChannelTxChannelIdxOfTxPduTxChannel */
typedef uint8 J1939Tp_TxChannelTxChannelIdxOfTxPduTxChannelType;

/**   \brief  value based type definition for J1939Tp_TxPduTxChannelTxChannelTableInd */
typedef uint8 J1939Tp_TxPduTxChannelTxChannelTableIndType;

/**   \brief  value based type definition for J1939Tp_DirectPriorityOfTxSdu */
typedef uint8 J1939Tp_DirectPriorityOfTxSduType;

/**   \brief  value based type definition for J1939Tp_FppTxSduSequenceCounterIdxOfTxSdu */
typedef uint8 J1939Tp_FppTxSduSequenceCounterIdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_FppTxSduSequenceCounterUsedOfTxSdu */
typedef boolean J1939Tp_FppTxSduSequenceCounterUsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataDaOfTxSdu */
typedef boolean J1939Tp_HasMetaDataDaOfTxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataOfTxSdu */
typedef boolean J1939Tp_HasMetaDataOfTxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataPrioOfTxSdu */
typedef boolean J1939Tp_HasMetaDataPrioOfTxSduType;

/**   \brief  value based type definition for J1939Tp_HasMetaDataSaOfTxSdu */
typedef boolean J1939Tp_HasMetaDataSaOfTxSduType;

/**   \brief  value based type definition for J1939Tp_InvalidHndOfTxSdu */
typedef boolean J1939Tp_InvalidHndOfTxSduType;

/**   \brief  value based type definition for J1939Tp_IsDirectPrioConfiguredOfTxSdu */
typedef boolean J1939Tp_IsDirectPrioConfiguredOfTxSduType;

/**   \brief  value based type definition for J1939Tp_IsVariableOfTxSdu */
typedef boolean J1939Tp_IsVariableOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterPRIORITY_8IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataGetterPRIORITY_8IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterPRIORITY_8UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataGetterPRIORITY_8UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterSOURCE_ADDRESS_16IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataGetterSOURCE_ADDRESS_16IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterSOURCE_ADDRESS_16UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataGetterSOURCE_ADDRESS_16UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataGetterTARGET_ADDRESS_16IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataGetterTARGET_ADDRESS_16UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataGetterTARGET_ADDRESS_16UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterPRIORITY_8IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataSetterPRIORITY_8IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterPRIORITY_8UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataSetterPRIORITY_8UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterSOURCE_ADDRESS_16IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataSetterSOURCE_ADDRESS_16IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterSOURCE_ADDRESS_16UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataSetterSOURCE_ADDRESS_16UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu */
typedef uint8 J1939Tp_MetaDataSetterTARGET_ADDRESS_16IdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_MetaDataSetterTARGET_ADDRESS_16UsedOfTxSdu */
typedef boolean J1939Tp_MetaDataSetterTARGET_ADDRESS_16UsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_PGNOfTxSdu */
typedef uint16 J1939Tp_PGNOfTxSduType;

/**   \brief  value based type definition for J1939Tp_PduFormatOfTxSdu */
typedef uint8 J1939Tp_PduFormatOfTxSduType;

/**   \brief  value based type definition for J1939Tp_PduLengthOfTxSdu */
typedef uint8 J1939Tp_PduLengthOfTxSduType;

/**   \brief  value based type definition for J1939Tp_SduIdOfTxSdu */
typedef uint8 J1939Tp_SduIdOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxChannelChannelIdxOfTxSdu */
typedef uint8 J1939Tp_TxChannelChannelIdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxChannelChannelUsedOfTxSdu */
typedef boolean J1939Tp_TxChannelChannelUsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectFdBcNPduIdxOfTxSdu */
typedef uint8 J1939Tp_TxPduDirectFdBcNPduIdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectFdBcNPduUsedOfTxSdu */
typedef boolean J1939Tp_TxPduDirectFdBcNPduUsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectFdNPduIdxOfTxSdu */
typedef uint8 J1939Tp_TxPduDirectFdNPduIdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectFdNPduUsedOfTxSdu */
typedef boolean J1939Tp_TxPduDirectFdNPduUsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectNPduIdxOfTxSdu */
typedef uint8 J1939Tp_TxPduDirectNPduIdxOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxPduDirectNPduUsedOfTxSdu */
typedef boolean J1939Tp_TxPduDirectNPduUsedOfTxSduType;

/**   \brief  value based type definition for J1939Tp_TxSduStateIdxOfTxSdu */
typedef uint8 J1939Tp_TxSduStateIdxOfTxSduType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPCStructTypes  J1939Tp Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in J1939Tp_RxChannel */
typedef struct sJ1939Tp_RxChannelType
{
  uint8 J1939Tp_RxChannelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxChannelType;

/**   \brief  type used in J1939Tp_RxChannelRxNSdu */
typedef struct sJ1939Tp_RxChannelRxNSduType
{
  uint8 J1939Tp_RxChannelRxNSduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxChannelRxNSduType;

/**   \brief  type used in J1939Tp_RxPdu */
typedef struct sJ1939Tp_RxPduType
{
  uint8 J1939Tp_RxPduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxPduType;

/**   \brief  type used in J1939Tp_RxPduDaPrio */
typedef struct sJ1939Tp_RxPduDaPrioType
{
  uint8 J1939Tp_RxPduDaPrioNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxPduDaPrioType;

/**   \brief  type used in J1939Tp_RxPduRxChannel */
typedef struct sJ1939Tp_RxPduRxChannelType
{
  uint8 J1939Tp_RxPduRxChannelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxPduRxChannelType;

/**   \brief  type used in J1939Tp_RxPduRxSdu */
typedef struct sJ1939Tp_RxPduRxSduType
{
  uint8 J1939Tp_RxPduRxSduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxPduRxSduType;

/**   \brief  type used in J1939Tp_RxPduTxChannel */
typedef struct sJ1939Tp_RxPduTxChannelType
{
  uint8 J1939Tp_RxPduTxChannelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxPduTxChannelType;

/**   \brief  type used in J1939Tp_RxSdu */
typedef struct sJ1939Tp_RxSduType
{
  uint8 J1939Tp_RxSduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_RxSduType;

/**   \brief  type used in J1939Tp_TxChannel */
typedef struct sJ1939Tp_TxChannelType
{
  J1939Tp_ComMChannelOfTxChannelType ComMChannelOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxChannelComMNetworkHandleRef */
  J1939Tp_TxVarPriOfTxChannelType TxVarPriOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxUseNonDefaultTpPriority */
  J1939Tp_TxBamInterframeTimeOfTxChannelType TxBamInterframeTimeOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxBamInterframeTime */
  J1939Tp_TxChannelTxNSduTxNSduTableIndEndIdxOfTxChannelType TxChannelTxNSduTxNSduTableIndEndIdxOfTxChannel;  /**< the end index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd */
  J1939Tp_TxChannelTxNSduTxNSduTableIndStartIdxOfTxChannelType TxChannelTxNSduTxNSduTableIndStartIdxOfTxChannel;  /**< the start index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd */
  J1939Tp_TxDaOfTxChannelType TxDaOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxDa */
  J1939Tp_TxMaxPacketsPerBlockOfTxChannelType TxMaxPacketsPerBlockOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxMaxPacketsPerBlock */
  J1939Tp_TxPduTxCmNPduIdxOfTxChannelType TxPduTxCmNPduIdxOfTxChannel;  /**< the index of the 0:1 relation pointing to J1939Tp_TxPdu */
  J1939Tp_TxPduTxDtNPduIdxOfTxChannelType TxPduTxDtNPduIdxOfTxChannel;  /**< the index of the 0:1 relation pointing to J1939Tp_TxPdu */
  J1939Tp_TxPriOfTxChannelType TxPriOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxPriority */
  J1939Tp_TxProtocolTypeOfTxChannelType TxProtocolTypeOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxProtocolType */
  J1939Tp_TxSaOfTxChannelType TxSaOfTxChannel;  /**< DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxSa */
} J1939Tp_TxChannelType;

/**   \brief  type used in J1939Tp_TxChannelTxNSdu */
typedef struct sJ1939Tp_TxChannelTxNSduType
{
  J1939Tp_TxSduTxNSduIdxOfTxChannelTxNSduType TxSduTxNSduIdxOfTxChannelTxNSdu;  /**< the index of the 1:1 relation pointing to J1939Tp_TxSdu */
} J1939Tp_TxChannelTxNSduType;

/**   \brief  type used in J1939Tp_TxPdu */
typedef struct sJ1939Tp_TxPduType
{
  J1939Tp_HasMetaDataOfTxPduType HasMetaDataOfTxPdu;  /**< MetaData */
  J1939Tp_MetaDataGetterCAN_ID_32IdxOfTxPduType MetaDataGetterCAN_ID_32IdxOfTxPdu;  /**< the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterCAN_ID_32 */
  J1939Tp_MetaDataSetterCAN_ID_32IdxOfTxPduType MetaDataSetterCAN_ID_32IdxOfTxPdu;  /**< the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterCAN_ID_32 */
  J1939Tp_PduIdOfTxPduType PduIdOfTxPdu;  /**< PDU ID */
  J1939Tp_PduTypeOfTxPduType PduTypeOfTxPdu;  /**< PDU Type */
  J1939Tp_TxPduStateIdxOfTxPduType TxPduStateIdxOfTxPdu;  /**< the index of the 1:1 relation pointing to J1939Tp_TxPduState */
  J1939Tp_TxPduTxChannelTxChannelTableIndEndIdxOfTxPduType TxPduTxChannelTxChannelTableIndEndIdxOfTxPdu;  /**< the end index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd */
  J1939Tp_TxPduTxChannelTxChannelTableIndStartIdxOfTxPduType TxPduTxChannelTxChannelTableIndStartIdxOfTxPdu;  /**< the start index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd */
} J1939Tp_TxPduType;

/**   \brief  type used in J1939Tp_TxPduRxChannel */
typedef struct sJ1939Tp_TxPduRxChannelType
{
  uint8 J1939Tp_TxPduRxChannelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_TxPduRxChannelType;

/**   \brief  type used in J1939Tp_TxPduTxChannel */
typedef struct sJ1939Tp_TxPduTxChannelType
{
  J1939Tp_TxChannelTxChannelIdxOfTxPduTxChannelType TxChannelTxChannelIdxOfTxPduTxChannel;  /**< the index of the 1:1 relation pointing to J1939Tp_TxChannel */
} J1939Tp_TxPduTxChannelType;

/**   \brief  type used in J1939Tp_TxSdu */
typedef struct sJ1939Tp_TxSduType
{
  J1939Tp_PGNOfTxSduType PGNOfTxSdu;  /**< PGN */
  J1939Tp_HasMetaDataOfTxSduType HasMetaDataOfTxSdu;  /**< MetaData */
  J1939Tp_HasMetaDataDaOfTxSduType HasMetaDataDaOfTxSdu;  /**< MetaData DA */
  J1939Tp_IsDirectPrioConfiguredOfTxSduType IsDirectPrioConfiguredOfTxSdu;  /**< Is DirectPriority configured */
  J1939Tp_IsVariableOfTxSduType IsVariableOfTxSdu;  /**< Variable Length */
  J1939Tp_DirectPriorityOfTxSduType DirectPriorityOfTxSdu;  /**< Priority of a direct frame. */
  J1939Tp_MetaDataGetterTARGET_ADDRESS_16IdxOfTxSduType MetaDataGetterTARGET_ADDRESS_16IdxOfTxSdu;  /**< the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
  J1939Tp_MetaDataSetterTARGET_ADDRESS_16IdxOfTxSduType MetaDataSetterTARGET_ADDRESS_16IdxOfTxSdu;  /**< the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
  J1939Tp_PduFormatOfTxSduType PduFormatOfTxSdu;  /**< PDU format */
  J1939Tp_PduLengthOfTxSduType PduLengthOfTxSdu;  /**< PDU Length */
  J1939Tp_SduIdOfTxSduType SduIdOfTxSdu;  /**< SDU ID */
  J1939Tp_TxChannelChannelIdxOfTxSduType TxChannelChannelIdxOfTxSdu;  /**< the index of the 0:1 relation pointing to J1939Tp_TxChannel */
  J1939Tp_TxPduDirectNPduIdxOfTxSduType TxPduDirectNPduIdxOfTxSdu;  /**< the index of the 0:1 relation pointing to J1939Tp_TxPdu */
  J1939Tp_TxSduStateIdxOfTxSduType TxSduStateIdxOfTxSdu;  /**< the index of the 1:1 relation pointing to J1939Tp_TxSduState */
} J1939Tp_TxSduType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCSymbolicStructTypes  J1939Tp Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_01 */
typedef struct J1939Tp_TxPduStateRDR_01StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_02 */
typedef struct J1939Tp_TxPduStateRDR_02StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_03 */
typedef struct J1939Tp_TxPduStateRDR_03StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_04 */
typedef struct J1939Tp_TxPduStateRDR_04StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_05 */
typedef struct J1939Tp_TxPduStateRDR_05StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_06 */
typedef struct J1939Tp_TxPduStateRDR_06StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_07 */
typedef struct J1939Tp_TxPduStateRDR_07StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxPduState for debugging purposes in the predefined variant RDR_08 */
typedef struct J1939Tp_TxPduStateRDR_08StructSTag
{
  J1939Tp_TxNPduStateType TPCM_Tp_oVCAN_RADAR_a235016c_Tx;
  J1939Tp_TxNPduStateType TPDT_Tp_oVCAN_RADAR_92966f54_Tx;
  J1939Tp_TxNPduStateType TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx;
} J1939Tp_TxPduStateRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_01 */
typedef struct J1939Tp_TxSduStateRDR_01StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_02 */
typedef struct J1939Tp_TxSduStateRDR_02StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_03 */
typedef struct J1939Tp_TxSduStateRDR_03StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_04 */
typedef struct J1939Tp_TxSduStateRDR_04StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_05 */
typedef struct J1939Tp_TxSduStateRDR_05StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_06 */
typedef struct J1939Tp_TxSduStateRDR_06StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_07 */
typedef struct J1939Tp_TxSduStateRDR_07StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to J1939Tp_TxSduState for debugging purposes in the predefined variant RDR_08 */
typedef struct J1939Tp_TxSduStateRDR_08StructSTag
{
  J1939Tp_TxNSduStateType DM1_D0_oVCAN_RADAR_ce78d82a_Tx;
} J1939Tp_TxSduStateRDR_08StructSType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCUnionIndexAndSymbolTypes  J1939Tp Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access J1939Tp_TxPduState in an index and symbol based style for debugging purposes */
typedef union J1939Tp_TxPduStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  J1939Tp_TxNPduStateType raw[3];
  J1939Tp_TxPduStateRDR_01StructSType strRDR_01;
  J1939Tp_TxPduStateRDR_02StructSType strRDR_02;
  J1939Tp_TxPduStateRDR_03StructSType strRDR_03;
  J1939Tp_TxPduStateRDR_04StructSType strRDR_04;
  J1939Tp_TxPduStateRDR_05StructSType strRDR_05;
  J1939Tp_TxPduStateRDR_06StructSType strRDR_06;
  J1939Tp_TxPduStateRDR_07StructSType strRDR_07;
  J1939Tp_TxPduStateRDR_08StructSType strRDR_08;
} J1939Tp_TxPduStateUType;

/**   \brief  type to access J1939Tp_TxSduState in an index and symbol based style for debugging purposes */
typedef union J1939Tp_TxSduStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  J1939Tp_TxNSduStateType raw[1];
  J1939Tp_TxSduStateRDR_01StructSType strRDR_01;
  J1939Tp_TxSduStateRDR_02StructSType strRDR_02;
  J1939Tp_TxSduStateRDR_03StructSType strRDR_03;
  J1939Tp_TxSduStateRDR_04StructSType strRDR_04;
  J1939Tp_TxSduStateRDR_05StructSType strRDR_05;
  J1939Tp_TxSduStateRDR_06StructSType strRDR_06;
  J1939Tp_TxSduStateRDR_07StructSType strRDR_07;
  J1939Tp_TxSduStateRDR_08StructSType strRDR_08;
} J1939Tp_TxSduStateUType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCFunctionPointerTypes  J1939Tp Function Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point to the MetaData Getter and Setter Functions.
  \{
*/ 
/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataGetterCAN_ID_32 */
typedef P2FUNC(uint32, J1939TP_CODE, J1939Tp_MetaDataGetterCAN_ID_32FctPtrType) (P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataGetterPRIORITY_8 */
typedef P2FUNC(uint8, J1939TP_CODE, J1939Tp_MetaDataGetterPRIORITY_8FctPtrType) (P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataGetterSOURCE_ADDRESS_16 */
typedef P2FUNC(uint16, J1939TP_CODE, J1939Tp_MetaDataGetterSOURCE_ADDRESS_16FctPtrType) (P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataGetterTARGET_ADDRESS_16 */
typedef P2FUNC(uint16, J1939TP_CODE, J1939Tp_MetaDataGetterTARGET_ADDRESS_16FctPtrType) (P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataSetterCAN_ID_32 */
typedef P2FUNC(void, J1939TP_CODE, J1939Tp_MetaDataSetterCAN_ID_32FctPtrType) (P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint32 item);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataSetterPRIORITY_8 */
typedef P2FUNC(void, J1939TP_CODE, J1939Tp_MetaDataSetterPRIORITY_8FctPtrType) (P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint8 item);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataSetterSOURCE_ADDRESS_16 */
typedef P2FUNC(void, J1939TP_CODE, J1939Tp_MetaDataSetterSOURCE_ADDRESS_16FctPtrType) (P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint16 item);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataSetterTARGET_ADDRESS_16 */
typedef P2FUNC(void, J1939TP_CODE, J1939Tp_MetaDataSetterTARGET_ADDRESS_16FctPtrType) (P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint16 item);

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCRootPointerTypes  J1939Tp Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to J1939Tp_FppRxSduSequenceCounter */
typedef P2VAR(J1939Tp_FppRxSduSequenceCounterType, TYPEDEF, J1939TP_VAR_NO_INIT) J1939Tp_FppRxSduSequenceCounterPtrType;

/**   \brief  type used to point to J1939Tp_FppTxSduSequenceCounter */
typedef P2VAR(J1939Tp_FppTxSduSequenceCounterType, TYPEDEF, J1939TP_VAR_NO_INIT) J1939Tp_FppTxSduSequenceCounterPtrType;

/**   \brief  type used to point to J1939Tp_MetaDataGetterCAN_ID_32 */
typedef P2CONST(J1939Tp_MetaDataGetterCAN_ID_32FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataGetterCAN_ID_32PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataGetterPRIORITY_8 */
typedef P2CONST(J1939Tp_MetaDataGetterPRIORITY_8FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataGetterPRIORITY_8PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataGetterSOURCE_ADDRESS_16 */
typedef P2CONST(J1939Tp_MetaDataGetterSOURCE_ADDRESS_16FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataGetterSOURCE_ADDRESS_16PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataGetterTARGET_ADDRESS_16 */
typedef P2CONST(J1939Tp_MetaDataGetterTARGET_ADDRESS_16FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataGetterTARGET_ADDRESS_16PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataSetterCAN_ID_32 */
typedef P2CONST(J1939Tp_MetaDataSetterCAN_ID_32FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataSetterCAN_ID_32PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataSetterPRIORITY_8 */
typedef P2CONST(J1939Tp_MetaDataSetterPRIORITY_8FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataSetterPRIORITY_8PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataSetterSOURCE_ADDRESS_16 */
typedef P2CONST(J1939Tp_MetaDataSetterSOURCE_ADDRESS_16FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataSetterSOURCE_ADDRESS_16PtrType;

/**   \brief  type used to point to J1939Tp_MetaDataSetterTARGET_ADDRESS_16 */
typedef P2CONST(J1939Tp_MetaDataSetterTARGET_ADDRESS_16FctPtrType, TYPEDEF, J1939TP_CONST) J1939Tp_MetaDataSetterTARGET_ADDRESS_16PtrType;

/**   \brief  type used to point to J1939Tp_RxChannel */
typedef P2CONST(J1939Tp_RxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_RxChannelPtrType;

/**   \brief  type used to point to J1939Tp_RxChannelRxNSdu */
typedef P2CONST(J1939Tp_RxChannelRxNSduType, TYPEDEF, J1939TP_CONST) J1939Tp_RxChannelRxNSduPtrType;

/**   \brief  type used to point to J1939Tp_RxChannelRxNSduRxNSduTableInd */
typedef P2CONST(J1939Tp_RxChannelRxNSduRxNSduTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_RxChannelRxNSduRxNSduTableIndPtrType;

/**   \brief  type used to point to J1939Tp_RxPdu */
typedef P2CONST(J1939Tp_RxPduType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduPtrType;

/**   \brief  type used to point to J1939Tp_RxPduDaPrio */
typedef P2CONST(J1939Tp_RxPduDaPrioType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduDaPrioPtrType;

/**   \brief  type used to point to J1939Tp_RxPduRxChannel */
typedef P2CONST(J1939Tp_RxPduRxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduRxChannelPtrType;

/**   \brief  type used to point to J1939Tp_RxPduRxChannelRxChannelTableInd */
typedef P2CONST(J1939Tp_RxPduRxChannelRxChannelTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduRxChannelRxChannelTableIndPtrType;

/**   \brief  type used to point to J1939Tp_RxPduRxSdu */
typedef P2CONST(J1939Tp_RxPduRxSduType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduRxSduPtrType;

/**   \brief  type used to point to J1939Tp_RxPduRxSduRxSduTableInd */
typedef P2CONST(J1939Tp_RxPduRxSduRxSduTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduRxSduRxSduTableIndPtrType;

/**   \brief  type used to point to J1939Tp_RxPduSa */
typedef P2CONST(J1939Tp_RxPduSaType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduSaPtrType;

/**   \brief  type used to point to J1939Tp_RxPduTxChannel */
typedef P2CONST(J1939Tp_RxPduTxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduTxChannelPtrType;

/**   \brief  type used to point to J1939Tp_RxPduTxChannelTxChannelTableInd */
typedef P2CONST(J1939Tp_RxPduTxChannelTxChannelTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_RxPduTxChannelTxChannelTableIndPtrType;

/**   \brief  type used to point to J1939Tp_RxSdu */
typedef P2CONST(J1939Tp_RxSduType, TYPEDEF, J1939TP_CONST) J1939Tp_RxSduPtrType;

/**   \brief  type used to point to J1939Tp_RxSduState */
typedef P2VAR(J1939Tp_RxNSduStateType, TYPEDEF, J1939TP_VAR_NO_INIT) J1939Tp_RxSduStatePtrType;

/**   \brief  type used to point to J1939Tp_TxChannel */
typedef P2CONST(J1939Tp_TxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_TxChannelPtrType;

/**   \brief  type used to point to J1939Tp_TxChannelTxNSdu */
typedef P2CONST(J1939Tp_TxChannelTxNSduType, TYPEDEF, J1939TP_CONST) J1939Tp_TxChannelTxNSduPtrType;

/**   \brief  type used to point to J1939Tp_TxChannelTxNSduTxNSduTableInd */
typedef P2CONST(J1939Tp_TxChannelTxNSduTxNSduTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_TxChannelTxNSduTxNSduTableIndPtrType;

/**   \brief  type used to point to J1939Tp_TxPdu */
typedef P2CONST(J1939Tp_TxPduType, TYPEDEF, J1939TP_CONST) J1939Tp_TxPduPtrType;

/**   \brief  type used to point to J1939Tp_TxPduRxChannel */
typedef P2CONST(J1939Tp_TxPduRxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_TxPduRxChannelPtrType;

/**   \brief  type used to point to J1939Tp_TxPduRxChannelRxChannelTableInd */
typedef P2CONST(J1939Tp_TxPduRxChannelRxChannelTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_TxPduRxChannelRxChannelTableIndPtrType;

/**   \brief  type used to point to J1939Tp_TxPduState */
typedef P2VAR(J1939Tp_TxNPduStateType, TYPEDEF, J1939TP_VAR_NO_INIT) J1939Tp_TxPduStatePtrType;

/**   \brief  type used to point to J1939Tp_TxPduTxChannel */
typedef P2CONST(J1939Tp_TxPduTxChannelType, TYPEDEF, J1939TP_CONST) J1939Tp_TxPduTxChannelPtrType;

/**   \brief  type used to point to J1939Tp_TxPduTxChannelTxChannelTableInd */
typedef P2CONST(J1939Tp_TxPduTxChannelTxChannelTableIndType, TYPEDEF, J1939TP_CONST) J1939Tp_TxPduTxChannelTxChannelTableIndPtrType;

/**   \brief  type used to point to J1939Tp_TxSdu */
typedef P2CONST(J1939Tp_TxSduType, TYPEDEF, J1939TP_CONST) J1939Tp_TxSduPtrType;

/**   \brief  type used to point to J1939Tp_TxSduState */
typedef P2VAR(J1939Tp_TxNSduStateType, TYPEDEF, J1939TP_VAR_NO_INIT) J1939Tp_TxSduStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPCRootValueTypes  J1939Tp Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in J1939Tp_PCConfig */
typedef struct sJ1939Tp_PCConfigType
{
  uint8 J1939Tp_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_PCConfigType;

typedef J1939Tp_PCConfigType J1939Tp_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPBValueTypes  J1939Tp Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for J1939Tp_LTConfigIdxOfPBConfig */
typedef uint8 J1939Tp_LTConfigIdxOfPBConfigType;

/**   \brief  value based type definition for J1939Tp_PCConfigIdxOfPBConfig */
typedef uint8 J1939Tp_PCConfigIdxOfPBConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPBRootValueTypes  J1939Tp Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in J1939Tp_PBConfig */
typedef struct sJ1939Tp_PBConfigType
{
  uint8 J1939Tp_PBConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Tp_PBConfigType;

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  J1939Tp_MetaDataGetterCAN_ID_32
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_MetaDataGetterCAN_ID_32FctPtrType, J1939TP_CONST) J1939Tp_MetaDataGetterCAN_ID_32[1];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataGetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_MetaDataGetterTARGET_ADDRESS_16FctPtrType, J1939TP_CONST) J1939Tp_MetaDataGetterTARGET_ADDRESS_16[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataSetterCAN_ID_32
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_MetaDataSetterCAN_ID_32FctPtrType, J1939TP_CONST) J1939Tp_MetaDataSetterCAN_ID_32[1];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataSetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_MetaDataSetterTARGET_ADDRESS_16FctPtrType, J1939TP_CONST) J1939Tp_MetaDataSetterTARGET_ADDRESS_16[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannel
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannel
  \brief  DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel
  \details
  Element                                  Description
  ComMChannel                              DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxChannelComMNetworkHandleRef
  TxVarPri                                 DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxUseNonDefaultTpPriority
  TxBamInterframeTime                      DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxBamInterframeTime
  TxChannelTxNSduTxNSduTableIndEndIdx      the end index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd
  TxChannelTxNSduTxNSduTableIndStartIdx    the start index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd
  TxDa                                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxDa
  TxMaxPacketsPerBlock                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxMaxPacketsPerBlock
  TxPduTxCmNPduIdx                         the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxPduTxDtNPduIdx                         the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxPri                                    DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxPriority
  TxProtocolType                           DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxProtocolType
  TxSa                                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxSa
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxChannelType, J1939TP_CONST) J1939Tp_TxChannel[1];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannelTxNSdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannelTxNSdu
  \details
  Element           Description
  TxSduTxNSduIdx    the index of the 1:1 relation pointing to J1939Tp_TxSdu
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxChannelTxNSduType, J1939TP_CONST) J1939Tp_TxChannelTxNSdu[1];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannelTxNSduTxNSduTableInd
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannelTxNSduTxNSduTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to J1939Tp_TxChannelTxNSdu
*/ 
#define J1939TP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxChannelTxNSduTxNSduTableIndType, J1939TP_CONST) J1939Tp_TxChannelTxNSduTxNSduTableInd[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939TP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPdu
  \brief  List of transmitted PDUs
  \details
  Element                                    Description
  HasMetaData                                MetaData
  MetaDataGetterCAN_ID_32Idx                 the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterCAN_ID_32
  MetaDataSetterCAN_ID_32Idx                 the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterCAN_ID_32
  PduId                                      PDU ID
  PduType                                    PDU Type
  TxPduStateIdx                              the index of the 1:1 relation pointing to J1939Tp_TxPduState
  TxPduTxChannelTxChannelTableIndEndIdx      the end index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd
  TxPduTxChannelTxChannelTableIndStartIdx    the start index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxPduType, J1939TP_CONST) J1939Tp_TxPdu[3];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduTxChannel
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduTxChannel
  \details
  Element                  Description
  TxChannelTxChannelIdx    the index of the 1:1 relation pointing to J1939Tp_TxChannel
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxPduTxChannelType, J1939TP_CONST) J1939Tp_TxPduTxChannel[3];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduTxChannelTxChannelTableInd
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduTxChannelTxChannelTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to J1939Tp_TxPduTxChannel
*/ 
#define J1939TP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxPduTxChannelTxChannelTableIndType, J1939TP_CONST) J1939Tp_TxPduTxChannelTxChannelTableInd[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939TP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxSdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxSdu
  \brief  List of transmitted SDUs
  \details
  Element                               Description
  PGN                                   PGN
  HasMetaData                           MetaData
  HasMetaDataDa                         MetaData DA
  IsDirectPrioConfigured                Is DirectPriority configured
  IsVariable                            Variable Length
  DirectPriority                        Priority of a direct frame.
  MetaDataGetterTARGET_ADDRESS_16Idx    the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterTARGET_ADDRESS_16
  MetaDataSetterTARGET_ADDRESS_16Idx    the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterTARGET_ADDRESS_16
  PduFormat                             PDU format
  PduLength                             PDU Length
  SduId                                 SDU ID
  TxChannelChannelIdx                   the index of the 0:1 relation pointing to J1939Tp_TxChannel
  TxPduDirectNPduIdx                    the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxSduStateIdx                         the index of the 1:1 relation pointing to J1939Tp_TxSduState
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Tp_TxSduType, J1939TP_CONST) J1939Tp_TxSdu[1];
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduState
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduState
  \brief  State of J1939Tp Tx PDU
*/ 
#define J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(J1939Tp_TxPduStateUType, J1939TP_VAR_NO_INIT) J1939Tp_TxPduState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxSduState
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxSduState
  \brief  State of J1939Tp Tx SDU
*/ 
#define J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(J1939Tp_TxSduStateUType, J1939TP_VAR_NO_INIT) J1939Tp_TxSduState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define J1939TP_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern FUNC(uint32, J1939TP_CODE) J1939Tp_Mdt_Get_CAN_ID_32_CAN_ID_32( P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr );
extern FUNC(uint16, J1939TP_CODE) J1939Tp_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr );
extern FUNC(void, J1939TP_CODE) J1939Tp_Mdt_Set_CAN_ID_32_CAN_ID_32( P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint32 item );
extern FUNC(void, J1939TP_CODE) J1939Tp_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint16 item );
#define J1939TP_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* User Config File Start */

/* User Config File End */


#endif  /* J1939TP_CFG_H */

/**********************************************************************************************************************
  END OF FILE: J1939Tp_Cfg.h
**********************************************************************************************************************/

