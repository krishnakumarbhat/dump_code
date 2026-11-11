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
 *            Module: PduR
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2026-08-05 12:38:42
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
#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_IND13400
#define PDUR_PROCESSOR_IND13400
#endif
#ifndef PDUR_COMP_LLVMDIAB
#define PDUR_COMP_LLVMDIAB
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PDUR_BSWM_CALLBACKS STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRPduCallback] */

#define PduR_PBConfigIdType uint32

 /*  DET Error define list  */ 
#define PDUR_FCT_COMTX 0x89u 
#define PDUR_FCT_SOADIFRXIND 0x61u 
#define PDUR_FCT_SOADIFTX 0x69u 
#define PDUR_FCT_SOADIFTXCFM 0x62u 
#define PDUR_FCT_SOADIFTT 0x63u 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_LDCOMTX 0xE9u 
#define PDUR_FCT_SOMEIPTPRXIND 0xE1u 
#define PDUR_FCT_SOMEIPTPTPRXIND 0xE5u 
#define PDUR_FCT_SOMEIPTPTX 0xE9u 
#define PDUR_FCT_SOMEIPTPTPTXCFM 0xE8u 
#define PDUR_FCT_SOMEIPTPTXCFM 0xE2u 
#define PDUR_FCT_SOMEIPTPTPSOR 0xE6u 
#define PDUR_FCT_SOMEIPTPTPCPYRX 0xE4u 
#define PDUR_FCT_SOMEIPTPTPCPYTX 0xE7u 
#define PDUR_FCT_SOMEIPTPTT 0xE3u 
#define PDUR_FCT_J1939DCMTX 0x29u 
#define PDUR_FCT_J1939TPRXIND 0x25u 
#define PDUR_FCT_J1939TPTX 0x29u 
#define PDUR_FCT_J1939TPTXCFM 0x28u 
#define PDUR_FCT_J1939TPSOR 0x26u 
#define PDUR_FCT_J1939TPCPYRX 0x24u 
#define PDUR_FCT_J1939TPCPYTX 0x27u 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_DCMCTX 0x9Au 
 /*   PduR_ComTransmit  PduR_SoAdIfIfRxIndication  PduR_SoAdIfTransmit  PduR_SoAdIfTxConfirmation  PduR_SoAdIfTriggerTransmit  PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_LdComTransmit  PduR_SomeIpTpIfRxIndication  PduR_SomeIpTpTpTpRxIndication  PduR_SomeIpTpTransmit  PduR_SomeIpTpTpTxConfirmation  PduR_SomeIpTpTxConfirmation  PduR_SomeIpTpTpStartOfReception  PduR_SomeIpTpTpCopyRxData  PduR_SomeIpTpTpCopyTxData  PduR_SomeIpTpTriggerTransmit  PduR_J1939DcmTransmit  PduR_J1939TpTpRxIndication  PduR_J1939TpTransmit  PduR_J1939TpTxConfirmation  PduR_J1939TpStartOfReception  PduR_J1939TpCopyRxData  PduR_J1939TpCopyTxData  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_DcmTransmit  PduR_DcmCancelTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_3f57de57_Rx_afaa1f7b_Rx 0u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_CCVS1_oVCAN_RADAR_e4df8c5f_Rx_1d08c8b3_Rx 1u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_CLS_Tx_4_oVCAN_RADAR_e4fced07_Rx_d09977e2_Rx 2u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_CLS_Tx_16_oVCAN_RADAR_afa2b499_Rx_314b6b6e_Rx 3u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_ETC2_00_oVCAN_RADAR_fd8cfcd0_Rx_55c59867_Rx 4u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_ETC2_03_oVCAN_RADAR_a69b4dc5_Rx_03929d1b_Rx 5u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_781ac753_Rx_b0c6f800_Rx 6u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CCVS1_oPCAN_RADAR_d10adaab_Rx_783b4bee_Rx 7u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CLS_Tx_4_oPCAN_RADAR_deff6d37_Rx_b617520e_Rx 8u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CLS_Tx_16_oPCAN_RADAR_c3f80567_Rx_ddfca0b8_Rx 9u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ETC2_03_oPCAN_RADAR_766d20c0_Rx_05f07e44_Rx 10u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ETC2_oPCAN_RADAR_57f17119_Rx_e03fcab1_Rx 11u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_OEL_oPCAN_RADAR_4c06edea_Rx_43222444_Rx 12u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_SAS_oPCAN_RADAR_e6d96f6c_Rx_b4918efe_Rx 13u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_TD_oPCAN_RADAR_a04f08f1_Rx_eb5fedc8_Rx 14u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VDC2_oPCAN_RADAR_9daa2cf0_Rx_2af15c9a_Rx 15u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VD_oPCAN_RADAR_e94baa9d_Rx_de20eca3_Rx 16u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VI_oPCAN_RADAR_6896f87b_Rx_f6dde99d_Rx 17u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_OEL_oVCAN_RADAR_45092dcb_Rx_e7745bc0_Rx  18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_e2456918_Rx_81e001a4_Rx 19u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_b952d80d_Rx_bbc5f648_Rx 20u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_CAPABILITY_oPCAN_RADAR_2f1662f1_Rx_40343c24_Rx 21u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_001_004_oPCAN_RADAR_d9a9ebb4_Rx_2d45ad19_Rx 22u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_005_008_oPCAN_RADAR_00d57f1e_Rx_a70ea4bc_Rx 23u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_009_012_oPCAN_RADAR_97a275d6_Rx_7f5ee3b6_Rx 24u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_013_016_oPCAN_RADAR_c7d74ef9_Rx_57f3a278_Rx 25u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_017_020_oPCAN_RADAR_722d8936_Rx_79c21ad9_Rx 26u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_021_024_oPCAN_RADAR_50cdb45d_Rx_bb700ec4_Rx 27u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_025_028_oPCAN_RADAR_89b120f7_Rx_18db8483_Rx 28u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_029_032_oPCAN_RADAR_1ec62a3f_Rx_3b5286ba_Rx 29u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_033_036_oPCAN_RADAR_4eb31110_Rx_1350ffb2_Rx 30u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_037_040_oPCAN_RADAR_69409207_Rx_9669473b_Rx 31u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_041_044_oPCAN_RADAR_10105227_Rx_6b4e3673_Rx 32u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_045_048_oPCAN_RADAR_c96cc68d_Rx_c0057d5b_Rx 33u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_049_052_oPCAN_RADAR_5e1bcc45_Rx_132dc921_Rx 34u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_053_056_oPCAN_RADAR_0e6ef76a_Rx_58587179_Rx 35u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_057_060_oPCAN_RADAR_bb9430a5_Rx_b035ac65_Rx 36u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_061_064_oPCAN_RADAR_99740dce_Rx_5bdbe3ec_Rx 37u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_065_068_oPCAN_RADAR_40089964_Rx_798630bc_Rx 38u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_069_072_oPCAN_RADAR_d77f93ac_Rx_1899c974_Rx 39u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_073_076_oPCAN_RADAR_870aa883_Rx_2f64c955_Rx 40u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_077_080_oPCAN_RADAR_5f9aa465_Rx_4243a654_Rx 41u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_081_084_oPCAN_RADAR_91ab9ed3_Rx_034cdf81_Rx 42u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_085_088_oPCAN_RADAR_48d70a79_Rx_fd43e886_Rx 43u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_089_092_oPCAN_RADAR_dfa000b1_Rx_3225c807_Rx 44u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_093_096_oPCAN_RADAR_8fd53b9e_Rx_96fac798_Rx 45u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_097_100_oPCAN_RADAR_43d6c604_Rx_6734284d_Rx 46u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_101_104_oPCAN_RADAR_58bef7d5_Rx_7a8ffc03_Rx 47u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_105_108_oPCAN_RADAR_81c2637f_Rx_9b017139_Rx 48u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_109_112_oPCAN_RADAR_16b569b7_Rx_9f35f68b_Rx 49u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_113_116_oPCAN_RADAR_46c05298_Rx_52789a25_Rx 50u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_117_120_oPCAN_RADAR_f33a9557_Rx_f689c3be_Rx 51u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_121_124_oPCAN_RADAR_d1daa83c_Rx_f5d5e0dc_Rx 52u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_DET_125_128_oPCAN_RADAR_08a63c96_Rx_306b8626_Rx 53u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_HEADER_001_oPCAN_RADAR_204bf532_Rx_a89b9b48_Rx 54u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_STATUS_001_oPCAN_RADAR_b6cfc045_Rx_c7bfd0ac_Rx 55u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_FUSION_STATUS_002_oPCAN_RADAR_edd87150_Rx_543d6eb7_Rx 56u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SAS_oVCAN_RADAR_efd6af4d_Rx_673bb0aa_Rx  57u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SYS_VEHICLE_STATUS_oPCAN_RADAR_9bbcdf4b_Rx_fe2e3497_Rx 58u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_TD_oVCAN_RADAR_7fe49199_Rx_b2c5ee3f_Rx   59u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_VDC2_oVCAN_RADAR_9b73b1bc_Rx_8bed2445_Rx 60u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_VD_oVCAN_RADAR_36e033f5_Rx_33254787_Rx   61u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_VI_oVCAN_RADAR_b73d6113_Rx_77666074_Rx   62u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_signalPdu_ADAS_Vehicle_Status_71b7c213_Rx_18053073_Rx 63u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0e6d82c3                       21u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1d08c8b3                       1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1ea56287_001                   71u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1fb17dd9                       65u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2af15c9a                       17u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2d45ad19                       29u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2e732dfd_001                   5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2f64c955                       47u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3a10829e_001                   77u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3b5286ba                       36u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4ed399d8                       73u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5bdbe3ec                       44u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5e07bf6a_001                   69u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6b4e3673                       39u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7a8ffc03                       54u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7f5ee3b6                       31u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8bed2445                       83u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9b017139                       55u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9f35f68b                       56u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_03e5ee26_001                   86u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_05f07e44                       12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_18db8483                       35u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_55c59867                       6u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_57f3a278                       32u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_79c21ad9                       33u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_81e001a4                       26u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_96fac798                       52u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_034cdf81                       49u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_132dc921                       41u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_148ccc54_001                   78u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_306b8626                       60u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_314b6b6e                       3u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_464f39b2                       23u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_543d6eb7                       63u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_673bb0aa                       64u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_783b4bee                       9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1350ffb2                       37u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1899c974                       46u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3225c807                       51u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4243a654                       48u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_03929d1b                       7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_40343c24                       28u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_52789a25                       57u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_798630bc                       45u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6734284d                       53u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9669473b                       38u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_18053073                       87u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_33254787                       84u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_43222444                       14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_58587179                       42u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_77666074                       85u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a70ea4bc                       30u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a89b9b48                       61u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_aa962039                       76u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_afaa1f7b                       0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b0c6f800                       8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b2c5ee3f                       82u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b035ac65                       43u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b0883b81_001                   79u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b4918efe                       15u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b617520e                       10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7632270_001                   4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_baa10f81                       68u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bae2d263                       22u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bb700ec4                       34u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bbc5f648                       27u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_be0e46e0_001                   80u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c7bfd0ac                       62u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c9ecf8b2                       75u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c0057d5b                       40u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ce426d3c_001                   72u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d09977e2                       2u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dd8809d0_001                   70u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ddfca0b8                       11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_de20eca3                       18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e03fcab1                       13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e7745bc0                       20u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_eb5fedc8                       16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ee16d246                       67u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ee753382                       66u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f2d237b5                       74u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f5d5e0dc                       59u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f6dde99d                       19u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f23c0b68                       24u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f689c3be                       58u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f60795ea                       25u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fd43e886                       50u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fe2e3497                       81u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0a0c7e54                       84u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0bea2fee                       120u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0cacdbaf                       4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0eb6c97d                       180u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0ef3b535                       155u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1ae5d784                       119u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1f03f8dd                       160u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2a870fac                       140u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3bc63c33                       85u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3bf88f81                       18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3eda2bea                       67u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3f8a85b4                       54u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4b04cdb6                       116u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4edeb339                       83u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4f1bc526                       42u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4f323af5                       97u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4fce08d8                       123u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5a1b40fb                       167u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5a38c029                       7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5b4521ce                       14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5d7416fe                       122u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5e070d98                       5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6a10def5                       163u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6ae4d5be                       159u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6bf36202                       187u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7a87facd                       153u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d97b0c9                       189u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d228420                       130u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8b837188                       35u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8c7ce5f5                       63u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8d15d405                       31u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8f6d8fc5                       17u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9fc8c3de                       104u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_09eaf938                       41u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_10ed6f75                       81u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_11f019fd                       69u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_13ead5b9                       29u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_16c46b0e                       19u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_16d666a1                       138u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_18c490d9                       164u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_19ae22b0                       147u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_19dbfe02                       154u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_21b8b528                       186u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_21e7c134                       92u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_24a407b4                       25u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_30d6958d                       88u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_33bf485e                       181u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_33e0b055                       131u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_35c65891                       66u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_35ccba72                       117u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_45dc00ac                       139u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_46f2847a                       148u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_49a2be73                       152u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_51be0ad3                       151u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_65b951fc                       129u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_69bb1772                       191u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_72f07d0c                       95u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_77e03a49                       111u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_86f019cb                       175u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_89ae4017                       142u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_92f3afa0                       103u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_96ae5532                       72u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_97d8b342                       48u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_98c6f402                       32u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_020b0f9a                       55u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_048c6441                       108u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_097e15ef                       126u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_111ddca3                       57u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_290a2834                       102u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_298d5cfa                       121u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_335b1c89                       93u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_412acf80                       90u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_518f8e48                       65u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_559eb387                       114u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_657fa4c9                       13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_666cd3cd                       157u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_688fe9f8                       53u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_695ce72f                       73u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_721dbc05                       39u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_776bf50a                       47u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_788bbdb4                       179u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_788dc9d6                       96u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_853c95a7                       27u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_862a0990                       169u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_908f46f4                       75u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_916fab35                       50u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_928f6819                       76u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_994ef650                       100u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1012f080                       71u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2495f9d4                       166u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3986e7d5                       30u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4500db53                       162u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4883c0e3                       150u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5388ea8c                       59u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5471a133                       149u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5830ecbc                       137u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6149f4ac                       8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6601beb6                       82u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8499b820                       168u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8656e65c                       16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8888be57                       28u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9098fc9e                       33u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_06822de6                       101u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_12988cee                       135u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_20954a70                       80u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_24146c63                       20u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_27420dcf                       177u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_36891f02                       89u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_37235e8d                       24u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_39695c5b                       1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_81196a7c                       78u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_345001f2                       184u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_491196aa                       107u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_787545ab                       99u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_861339c8                       109u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_921805df                       60u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_968025e3                       145u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0501344c                       61u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0565674b                       182u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3227631e                       87u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3327516f                       185u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4371474b                       158u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7059221e                       36u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_00300665                       49u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_37177174                       128u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_91229167                       6u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_98538545                       105u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a3cd0b40                       22u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_aecd6860                       62u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_af55dfb3                       21u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b5fe123c                       146u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b6c27c0e                       77u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7e0bf39                       12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b8d5302b                       118u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b83eb6bf                       40u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b88d3c0a                       112u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b114bae6                       178u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b88278da                       3u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b9876897                       68u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_baa27a48                       106u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bb4876e0                       98u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bbb1f985                       141u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bcb3cc16                       74u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bd12da3a                       91u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_beb9bba4                       0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c0e2a6b5                       134u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c2fc0504                       192u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c5bcf08d                       144u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c5c61ffe                       124u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c6e52a15                       133u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c9a412e4                       46u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c01c948e                       113u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c06d99da                       11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c74f761f                       52u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ca318370                       15u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cb35f6b9                       115u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cbd20d2e                       70u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cbea582e                       56u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cfa1c4bc                       43u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cfcd6f6f                       86u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d1ac5560                       136u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d2d7e2a4                       44u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d4a08e46                       161u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d27995e8                       45u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d30572be                       9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d87193f4                       170u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_da3b0c2b                       188u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dc70d43f                       23u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dd0274df                       156u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dee3be1f                       172u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_df2f5c14                       127u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dffb8b0e                       2u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e2a4874e                       94u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e31a11d2                       38u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e71c1eed                       176u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e7232cc0                       51u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e27318ae                       173u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e58688dc                       183u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_eb36a6cb                       10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ef0735fa                       64u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f0a0a000                       165u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f3b727a2                       37u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f3c9ccf6                       110u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f4b7358b                       190u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f6af31bc                       171u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f8b1a6fe                       58u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f66c45ff                       125u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f497a076                       143u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f947f6e7                       79u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f16341fe                       132u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f46075d1                       174u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f070380c                       34u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fd1f7138                       26u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_BSD1_oVCAN_RADAR_aa49a410_Tx             0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_DM1_B0_oVCAN_RADAR_15753e9e_Tx           1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_DM1_B1_oVCAN_RADAR_2387ae6d_Tx           2u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ADAS_FN_Enable_disable_sts_Tx_oPCAN_RADAR_27a639a3_Tx 3u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CCVS1_Tx_oPCAN_RADAR_7eaa671a_Tx      4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CLS_Tx_4_Tx_oPCAN_RADAR_ecf0186d_Tx   5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_CLS_Tx_16_Tx_oPCAN_RADAR_b30c42cc_Tx  6u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ETC2_03_Tx_oPCAN_RADAR_07adbeb0_Tx    7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_ETC2_Tx_oPCAN_RADAR_dfec0354_Tx       8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_OEL_Tx_oPCAN_RADAR_96436c6f_Tx        9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_SAS_Tx_oPCAN_RADAR_6c223e7b_Tx        10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_TD_Tx_oPCAN_RADAR_aa39de8f_Tx         11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VDC2_Tx_oPCAN_RADAR_8a7343d4_Tx       12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VD_Tx_oPCAN_RADAR_70a8f6f0_Tx         13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_VI_Tx_oPCAN_RADAR_ad28cbdc_Tx         14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_GW_prop_ADAS_BSIS_info_oPCAN_RADAR_2b91b919_Tx 15u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_MOIS_oVCAN_RADAR_1658382d_Tx             16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_4f94d655_Tx 17u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_14836740_Tx 18u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_BSD1_Tx_oPCAN_RADAR_3cea6970_Tx      19u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_CAPABILITY_oPCAN_RADAR_476dda7e_Tx   20u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_001_004_oPCAN_RADAR_db6da1bd_Tx 21u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_005_008_oPCAN_RADAR_02113517_Tx 22u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_009_012_oPCAN_RADAR_95663fdf_Tx 23u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_013_016_oPCAN_RADAR_c51304f0_Tx 24u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_017_020_oPCAN_RADAR_70e9c33f_Tx 25u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_021_024_oPCAN_RADAR_5209fe54_Tx 26u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_025_028_oPCAN_RADAR_8b756afe_Tx 27u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_029_032_oPCAN_RADAR_1c026036_Tx 28u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_033_036_oPCAN_RADAR_4c775b19_Tx 29u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_037_040_oPCAN_RADAR_6b84d80e_Tx 30u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_041_044_oPCAN_RADAR_12d4182e_Tx 31u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_045_048_oPCAN_RADAR_cba88c84_Tx 32u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_049_052_oPCAN_RADAR_5cdf864c_Tx 33u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_053_056_oPCAN_RADAR_0caabd63_Tx 34u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_057_060_oPCAN_RADAR_b9507aac_Tx 35u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_061_064_oPCAN_RADAR_9bb047c7_Tx 36u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_065_068_oPCAN_RADAR_42ccd36d_Tx 37u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_069_072_oPCAN_RADAR_d5bbd9a5_Tx 38u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_073_076_oPCAN_RADAR_85cee28a_Tx 39u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_077_080_oPCAN_RADAR_5d5eee6c_Tx 40u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_081_084_oPCAN_RADAR_936fd4da_Tx 41u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_085_088_oPCAN_RADAR_4a134070_Tx 42u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_089_092_oPCAN_RADAR_dd644ab8_Tx 43u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_093_096_oPCAN_RADAR_8d117197_Tx 44u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_097_100_oPCAN_RADAR_41128c0d_Tx 45u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_101_104_oPCAN_RADAR_5a7abddc_Tx 46u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_105_108_oPCAN_RADAR_83062976_Tx 47u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_109_112_oPCAN_RADAR_147123be_Tx 48u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_113_116_oPCAN_RADAR_44041891_Tx 49u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_117_120_oPCAN_RADAR_f1fedf5e_Tx 50u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_121_124_oPCAN_RADAR_d31ee235_Tx 51u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_125_128_oPCAN_RADAR_0a62769f_Tx 52u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_129_132_oPCAN_RADAR_9d157c57_Tx 53u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_133_136_oPCAN_RADAR_cd604778_Tx 54u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_137_140_oPCAN_RADAR_ea93c46f_Tx 55u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_141_144_oPCAN_RADAR_93c3044f_Tx 56u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_145_148_oPCAN_RADAR_4abf90e5_Tx 57u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_149_152_oPCAN_RADAR_ddc89a2d_Tx 58u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_153_156_oPCAN_RADAR_8dbda102_Tx 59u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_157_160_oPCAN_RADAR_384766cd_Tx 60u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_161_164_oPCAN_RADAR_1aa75ba6_Tx 61u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_165_168_oPCAN_RADAR_c3dbcf0c_Tx 62u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_169_172_oPCAN_RADAR_54acc5c4_Tx 63u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_173_176_oPCAN_RADAR_04d9feeb_Tx 64u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_177_180_oPCAN_RADAR_dc49f20d_Tx 65u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_181_184_oPCAN_RADAR_1278c8bb_Tx 66u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_185_188_oPCAN_RADAR_cb045c11_Tx 67u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_189_192_oPCAN_RADAR_5c7356d9_Tx 68u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_193_196_oPCAN_RADAR_0c066df6_Tx 69u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_197_200_oPCAN_RADAR_8448b9bd_Tx 70u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_201_204_oPCAN_RADAR_02329f3e_Tx 71u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_205_208_oPCAN_RADAR_db4e0b94_Tx 72u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_209_212_oPCAN_RADAR_4c39015c_Tx 73u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_213_216_oPCAN_RADAR_1c4c3a73_Tx 74u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_217_220_oPCAN_RADAR_a9b6fdbc_Tx 75u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_221_224_oPCAN_RADAR_8b56c0d7_Tx 76u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_225_228_oPCAN_RADAR_522a547d_Tx 77u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_229_232_oPCAN_RADAR_c55d5eb5_Tx 78u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_233_236_oPCAN_RADAR_9528659a_Tx 79u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_237_240_oPCAN_RADAR_b2dbe68d_Tx 80u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_241_244_oPCAN_RADAR_cb8b26ad_Tx 81u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_245_248_oPCAN_RADAR_12f7b207_Tx 82u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_249_252_oPCAN_RADAR_8580b8cf_Tx 83u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_253_256_oPCAN_RADAR_d5f583e0_Tx 84u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_257_260_oPCAN_RADAR_600f442f_Tx 85u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_261_264_oPCAN_RADAR_42ef7944_Tx 86u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_265_268_oPCAN_RADAR_9b93edee_Tx 87u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_269_272_oPCAN_RADAR_0ce4e726_Tx 88u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_273_276_oPCAN_RADAR_5c91dc09_Tx 89u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_277_280_oPCAN_RADAR_8401d0ef_Tx 90u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_281_284_oPCAN_RADAR_4a30ea59_Tx 91u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_285_288_oPCAN_RADAR_934c7ef3_Tx 92u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_289_292_oPCAN_RADAR_043b743b_Tx 93u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_293_296_oPCAN_RADAR_544e4f14_Tx 94u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_297_300_oPCAN_RADAR_984db28e_Tx 95u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_301_304_oPCAN_RADAR_8325835f_Tx 96u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_305_308_oPCAN_RADAR_5a5917f5_Tx 97u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_309_312_oPCAN_RADAR_cd2e1d3d_Tx 98u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_313_316_oPCAN_RADAR_9d5b2612_Tx 99u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_317_320_oPCAN_RADAR_28a1e1dd_Tx 100u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_321_324_oPCAN_RADAR_0a41dcb6_Tx 101u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_325_328_oPCAN_RADAR_d33d481c_Tx 102u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_329_332_oPCAN_RADAR_444a42d4_Tx 103u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_333_336_oPCAN_RADAR_143f79fb_Tx 104u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_337_340_oPCAN_RADAR_33ccfaec_Tx 105u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_341_344_oPCAN_RADAR_4a9c3acc_Tx 106u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_345_348_oPCAN_RADAR_93e0ae66_Tx 107u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_349_352_oPCAN_RADAR_0497a4ae_Tx 108u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_353_356_oPCAN_RADAR_54e29f81_Tx 109u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_357_360_oPCAN_RADAR_e118584e_Tx 110u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_361_364_oPCAN_RADAR_c3f86525_Tx 111u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_365_368_oPCAN_RADAR_1a84f18f_Tx 112u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_369_372_oPCAN_RADAR_8df3fb47_Tx 113u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_373_376_oPCAN_RADAR_dd86c068_Tx 114u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_377_380_oPCAN_RADAR_0516cc8e_Tx 115u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_381_384_oPCAN_RADAR_cb27f638_Tx 116u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_385_388_oPCAN_RADAR_125b6292_Tx 117u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_389_392_oPCAN_RADAR_852c685a_Tx 118u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_393_396_oPCAN_RADAR_d5595375_Tx 119u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_DETECTION_397_400_oPCAN_RADAR_d58dd49c_Tx 120u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_HEADER_001_oPCAN_RADAR_48304dbd_Tx   121u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_OBJ_HEADER_002_oPCAN_RADAR_018ea437_Tx 122u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_OBJ_STATUS_003_oPCAN_RADAR_a1f801b3_Tx 123u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_STATUS_001_oPCAN_RADAR_deb478ca_Tx   124u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_STATUS_002_oPCAN_RADAR_85a3c9df_Tx   125u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_001_oPCAN_RADAR_eb452802_Tx 126u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_002_oPCAN_RADAR_b0529917_Tx 127u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_003_oPCAN_RADAR_86a009e4_Tx 128u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_004_oPCAN_RADAR_067dfb3d_Tx 129u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_005_oPCAN_RADAR_308f6bce_Tx 130u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_006_oPCAN_RADAR_6b98dadb_Tx 131u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_007_oPCAN_RADAR_5d6a4a28_Tx 132u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_008_oPCAN_RADAR_b1523928_Tx 133u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_009_oPCAN_RADAR_87a0a9db_Tx 134u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_010_oPCAN_RADAR_f935e9c7_Tx 135u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_011_oPCAN_RADAR_cfc77934_Tx 136u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_012_oPCAN_RADAR_94d0c821_Tx 137u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_013_oPCAN_RADAR_a22258d2_Tx 138u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_014_oPCAN_RADAR_22ffaa0b_Tx 139u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_015_oPCAN_RADAR_140d3af8_Tx 140u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_016_oPCAN_RADAR_4f1a8bed_Tx 141u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_017_oPCAN_RADAR_79e81b1e_Tx 142u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_018_oPCAN_RADAR_95d0681e_Tx 143u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_019_oPCAN_RADAR_a322f8ed_Tx 144u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_020_oPCAN_RADAR_94b31a9d_Tx 145u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_021_oPCAN_RADAR_a2418a6e_Tx 146u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_022_oPCAN_RADAR_f9563b7b_Tx 147u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_023_oPCAN_RADAR_cfa4ab88_Tx 148u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_024_oPCAN_RADAR_4f795951_Tx 149u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_025_oPCAN_RADAR_798bc9a2_Tx 150u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_026_oPCAN_RADAR_229c78b7_Tx 151u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_027_oPCAN_RADAR_146ee844_Tx 152u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_028_oPCAN_RADAR_f8569b44_Tx 153u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_029_oPCAN_RADAR_cea40bb7_Tx 154u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_030_oPCAN_RADAR_b0314bab_Tx 155u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_031_oPCAN_RADAR_86c3db58_Tx 156u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_032_oPCAN_RADAR_ddd46a4d_Tx 157u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_033_oPCAN_RADAR_eb26fabe_Tx 158u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_034_oPCAN_RADAR_6bfb0867_Tx 159u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_035_oPCAN_RADAR_5d099894_Tx 160u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_036_oPCAN_RADAR_061e2981_Tx 161u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_037_oPCAN_RADAR_30ecb972_Tx 162u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_038_oPCAN_RADAR_dcd4ca72_Tx 163u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_039_oPCAN_RADAR_ea265a81_Tx 164u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_040_oPCAN_RADAR_4fbefc29_Tx 165u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_041_oPCAN_RADAR_794c6cda_Tx 166u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_042_oPCAN_RADAR_225bddcf_Tx 167u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_043_oPCAN_RADAR_14a94d3c_Tx 168u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_044_oPCAN_RADAR_9474bfe5_Tx 169u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_045_oPCAN_RADAR_a2862f16_Tx 170u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_046_oPCAN_RADAR_f9919e03_Tx 171u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_047_oPCAN_RADAR_cf630ef0_Tx 172u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_048_oPCAN_RADAR_235b7df0_Tx 173u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_049_oPCAN_RADAR_15a9ed03_Tx 174u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_050_oPCAN_RADAR_6b3cad1f_Tx 175u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_051_oPCAN_RADAR_5dce3dec_Tx 176u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_052_oPCAN_RADAR_06d98cf9_Tx 177u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_053_oPCAN_RADAR_302b1c0a_Tx 178u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_054_oPCAN_RADAR_b0f6eed3_Tx 179u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_055_oPCAN_RADAR_86047e20_Tx 180u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_056_oPCAN_RADAR_dd13cf35_Tx 181u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_057_oPCAN_RADAR_ebe15fc6_Tx 182u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_058_oPCAN_RADAR_07d92cc6_Tx 183u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_059_oPCAN_RADAR_312bbc35_Tx 184u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_060_oPCAN_RADAR_06ba5e45_Tx 185u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_061_oPCAN_RADAR_3048ceb6_Tx 186u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_062_oPCAN_RADAR_6b5f7fa3_Tx 187u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_063_oPCAN_RADAR_5dadef50_Tx 188u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_RDR_TRACKER_OBJ_064_oPCAN_RADAR_dd701d89_Tx 189u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_6638d82d_Tx 190u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3d2f6938_Tx 191u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_349e32f6_Tx 192u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_9afe60a3_Tx 193u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_e30acad9_Tx 194u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_b81d7bcc_Tx 195u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_63bc1ea4_Tx 196u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_20ab64b4_Tx 197u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx 198u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx 199u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx 200u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx 201u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx 202u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx 203u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx 204u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx 205u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_TPCM_SR1_oVCAN_RADAR_42f3de03_Tx         206u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_TPCM_SR2_oVCAN_RADAR_19e46f16_Tx         207u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_TPDT_B0_oVCAN_RADAR_bde39209_Tx          208u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_TPDT_B1_oVCAN_RADAR_8b1102fa_Tx          209u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_prop_ADAS_BSIS_info_oVCAN_RADAR_a7fddec0_Tx 210u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_prop_ADAS_MOIS_info_oVCAN_RADAR_21657ab6_Tx 211u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_signalPdu_RDR_1_Detections_Transport_d322aa23_Tx_f4b7358b_Tx 212u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_signalPdu_RDR_1_SW_Info_14232baa_Tx      213u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_signalPdu_RDR_1_Status_67c6fd21_Tx       214u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DIAG_REQ_FNC_OBD1_oVCAN_RADAR_7e5c8685_Rx_e4e4d778_Rx 0u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_DIAG_REQ_FNC_OBD2_oVCAN_RADAR_254b3790_Rx_017e0121_Rx 1u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_DIAG_REQ_FNC_OTA_oVCAN_RADAR_e787ed21_Rx_dbaad71c_Rx 2u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_DIAG_REQ_FNC_PLANT_oVCAN_RADAR_42eb2f27_Rx_55bb6522_Rx 3u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_5445ad08_Rx_7bb4cf60_Rx 4u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_0f521c1d_Rx_1d3adefb_Rx 5u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_REQ_PHY_OTA_oVCAN_RADAR_9187f4da_Rx_4399556e_Rx 6u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_d1c8c991_Rx_199df235_Rx 7u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OBD1_oPCAN_RADAR_20_25c43a7c_Rx_12ce5aa9_Rx 8u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OBD1_oPCAN_RADAR_b9aa9d1d_Rx_ec57064f_Rx 9u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OBD2_oPCAN_RADAR_20_41244182_Rx_acafabed_Rx 10u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OBD2_oPCAN_RADAR_e2bd2c08_Rx_dab59121_Rx 11u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OTA_oPCAN_RADAR_20_e1100275_Rx_09f61e64_Rx 12u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_OTA_oPCAN_RADAR_a013523e_Rx_6f3aa62d_Rx 13u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_PLANT_oPCAN_RADAR_20_c17463fa_Rx_d6a59fd3_Rx 15u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_FUNC_PLANT_oPCAN_RADAR_f6414098_Rx_61d1e2e6_Rx 14u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OBD1_oPCAN_RADAR_20_f19508d6_Rx_88550f3d_Rx 16u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OBD1_oPCAN_RADAR_bb22f7fc_Rx_d26a3583_Rx 17u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OBD2_oPCAN_RADAR_20_95757328_Rx_5808d905_Rx 18u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OBD2_oPCAN_RADAR_e03546e9_Rx_f2e56351_Rx 19u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OTA_oPCAN_RADAR_20_0b124a16_Rx_58857336_Rx 21u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_OTA_oPCAN_RADAR_45eab9fd_Rx_c794190e_Rx 20u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_PLANT_oPCAN_RADAR_20_f7a3783e_Rx_917a13f6_Rx 22u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_REQ_PHYS_PLANT_oPCAN_RADAR_214e1a1c_Rx_ce8fc2bd_Rx 23u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb                       5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d                       13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60                       4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64                       12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9                       8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522                       3u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6                       15u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121                       1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_199df235                       7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6                       22u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905                       18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d                       16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e                       6u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_58857336                       20u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed                       10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e                       21u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd                       23u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3                       14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583                       17u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121                       11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c                       2u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778                       0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f                       9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351                       19u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DM1_D0_oVCAN_RADAR_ce78d82a_Tx           0u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx 1u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx 2u  /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx 3u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx 4u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx 5u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx 6u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx 7u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx 8u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx 9u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx 10u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx 11u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx 12u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define PduRConf_PduRDestPdu_signalPdu_RDR_1_Detections_52b391ee_Tx   13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

