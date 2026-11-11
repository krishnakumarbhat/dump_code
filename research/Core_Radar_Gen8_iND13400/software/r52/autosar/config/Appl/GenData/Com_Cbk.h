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
 *            Module: Com
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cbk.h
 *   Generation Time: 2026-08-05 12:38:46
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

#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_dbe1c88d_Rx 0u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_CCVS1_oVCAN_RADAR_7fab2fed_Rx                 1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_CLS_Tx_4_oVCAN_RADAR_1adbb350_Rx              2u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_CLS_Tx_16_oVCAN_RADAR_4a01c26f_Rx             3u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_ETC2_00_oVCAN_RADAR_322c725a_Rx               4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_ETC2_03_oVCAN_RADAR_8fe61e94_Rx               5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_a2ffe33c_Rx 6u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_CCVS1_oPCAN_RADAR_379fc270_Rx              7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_CLS_Tx_4_oPCAN_RADAR_888f4e35_Rx           8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_CLS_Tx_16_oPCAN_RADAR_92e0b941_Rx          9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_ETC2_03_oPCAN_RADAR_7791e995_Rx            10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_ETC2_oPCAN_RADAR_2970e6e5_Rx               11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_OEL_oPCAN_RADAR_b67c14d5_Rx                12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_SAS_oPCAN_RADAR_3d30de8a_Rx                13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_TD_oPCAN_RADAR_87cf7844_Rx                 14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_VDC2_oPCAN_RADAR_a2fdf3c6_Rx               15u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_VD_oPCAN_RADAR_66a1bce9_Rx                 16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_GW_VI_oPCAN_RADAR_218ddc97_Rx                 17u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_OEL_oVCAN_RADAR_75091ec5_Rx                   18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_5cbb3751_Rx 19u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_e1715b9f_Rx 20u /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_CAPABILITY_oPCAN_RADAR_d81ad430_Rx 21u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_001_004_oPCAN_RADAR_d39eadb5_Rx 22u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_005_008_oPCAN_RADAR_3a2c3381_Rx 23u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_009_012_oPCAN_RADAR_0864dc80_Rx 24u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_013_016_oPCAN_RADAR_15a3dfae_Rx 25u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_017_020_oPCAN_RADAR_ba2f0267_Rx 26u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_021_024_oPCAN_RADAR_3724029b_Rx 27u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_025_028_oPCAN_RADAR_de969caf_Rx 28u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_029_032_oPCAN_RADAR_ecde73ae_Rx 29u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_033_036_oPCAN_RADAR_f1197080_Rx 30u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_037_040_oPCAN_RADAR_47392252_Rx 31u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_041_044_oPCAN_RADAR_c19af5a8_Rx 32u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_045_048_oPCAN_RADAR_28286b9c_Rx 33u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_049_052_oPCAN_RADAR_1a60849d_Rx 34u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_053_056_oPCAN_RADAR_07a787b3_Rx 35u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_057_060_oPCAN_RADAR_a82b5a7a_Rx 36u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_061_064_oPCAN_RADAR_25205a86_Rx 37u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_065_068_oPCAN_RADAR_cc92c4b2_Rx 38u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_069_072_oPCAN_RADAR_feda2bb3_Rx 39u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_073_076_oPCAN_RADAR_e31d289d_Rx 40u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_077_080_oPCAN_RADAR_66646479_Rx 41u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_081_084_oPCAN_RADAR_f7961d8f_Rx 42u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_085_088_oPCAN_RADAR_1e2483bb_Rx 43u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_089_092_oPCAN_RADAR_2c6c6cba_Rx 44u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_093_096_oPCAN_RADAR_31ab6f94_Rx 45u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_097_100_oPCAN_RADAR_f5ebb32e_Rx 46u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_101_104_oPCAN_RADAR_bd87f605_Rx 47u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_105_108_oPCAN_RADAR_54356831_Rx 48u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_109_112_oPCAN_RADAR_667d8730_Rx 49u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_113_116_oPCAN_RADAR_7bba841e_Rx 50u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_117_120_oPCAN_RADAR_d43659d7_Rx 51u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_121_124_oPCAN_RADAR_593d592b_Rx 52u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_DET_125_128_oPCAN_RADAR_b08fc71f_Rx 53u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_HEADER_001_oPCAN_RADAR_cc468fbf_Rx 54u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_STATUS_001_oPCAN_RADAR_8bf3739d_Rx 55u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_FUSION_STATUS_002_oPCAN_RADAR_36391f53_Rx 56u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_SAS_oVCAN_RADAR_fe45d49a_Rx                   57u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_SYS_VEHICLE_STATUS_oPCAN_RADAR_43e5dd0e_Rx    58u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_TD_oVCAN_RADAR_804fc074_Rx                    59u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_VDC2_oVCAN_RADAR_5a222cac_Rx                  60u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_VD_oVCAN_RADAR_612104d9_Rx                    61u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_VI_oVCAN_RADAR_260d64a7_Rx                    62u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_GW_prop_ADAS_BSIS_info_oPCAN_RADAR_f2d61fec_Tx 0u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_MOIS_oVCAN_RADAR_39784631_Tx                  1u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_dd819ed8_Tx 2u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_604bf216_Tx 3u   /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_BSD1_Tx_oPCAN_RADAR_170995fb_Tx           4u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_CAPABILITY_oPCAN_RADAR_18844568_Tx        5u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_001_004_oPCAN_RADAR_b0420040_Tx 6u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_005_008_oPCAN_RADAR_59f09e74_Tx 7u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_009_012_oPCAN_RADAR_6bb87175_Tx 8u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_013_016_oPCAN_RADAR_767f725b_Tx 9u      /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_017_020_oPCAN_RADAR_d9f3af92_Tx 10u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_021_024_oPCAN_RADAR_54f8af6e_Tx 11u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_025_028_oPCAN_RADAR_bd4a315a_Tx 12u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_029_032_oPCAN_RADAR_8f02de5b_Tx 13u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_033_036_oPCAN_RADAR_92c5dd75_Tx 14u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_037_040_oPCAN_RADAR_24e58fa7_Tx 15u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_041_044_oPCAN_RADAR_a246585d_Tx 16u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_045_048_oPCAN_RADAR_4bf4c669_Tx 17u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_049_052_oPCAN_RADAR_79bc2968_Tx 18u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_053_056_oPCAN_RADAR_647b2a46_Tx 19u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_057_060_oPCAN_RADAR_cbf7f78f_Tx 20u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_061_064_oPCAN_RADAR_46fcf773_Tx 21u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_065_068_oPCAN_RADAR_af4e6947_Tx 22u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_069_072_oPCAN_RADAR_9d068646_Tx 23u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_073_076_oPCAN_RADAR_80c18568_Tx 24u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_077_080_oPCAN_RADAR_05b8c98c_Tx 25u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_081_084_oPCAN_RADAR_944ab07a_Tx 26u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_085_088_oPCAN_RADAR_7df82e4e_Tx 27u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_089_092_oPCAN_RADAR_4fb0c14f_Tx 28u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_093_096_oPCAN_RADAR_5277c261_Tx 29u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_097_100_oPCAN_RADAR_96371edb_Tx 30u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_101_104_oPCAN_RADAR_de5b5bf0_Tx 31u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_105_108_oPCAN_RADAR_37e9c5c4_Tx 32u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_109_112_oPCAN_RADAR_05a12ac5_Tx 33u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_113_116_oPCAN_RADAR_186629eb_Tx 34u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_117_120_oPCAN_RADAR_b7eaf422_Tx 35u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_121_124_oPCAN_RADAR_3ae1f4de_Tx 36u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_125_128_oPCAN_RADAR_d3536aea_Tx 37u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_129_132_oPCAN_RADAR_e11b85eb_Tx 38u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_133_136_oPCAN_RADAR_fcdc86c5_Tx 39u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_137_140_oPCAN_RADAR_4afcd417_Tx 40u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_141_144_oPCAN_RADAR_cc5f03ed_Tx 41u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_145_148_oPCAN_RADAR_25ed9dd9_Tx 42u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_149_152_oPCAN_RADAR_17a572d8_Tx 43u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_153_156_oPCAN_RADAR_0a6271f6_Tx 44u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_157_160_oPCAN_RADAR_a5eeac3f_Tx 45u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_161_164_oPCAN_RADAR_28e5acc3_Tx 46u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_165_168_oPCAN_RADAR_c15732f7_Tx 47u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_169_172_oPCAN_RADAR_f31fddf6_Tx 48u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_173_176_oPCAN_RADAR_eed8ded8_Tx 49u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_177_180_oPCAN_RADAR_6ba1923c_Tx 50u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_181_184_oPCAN_RADAR_fa53ebca_Tx 51u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_185_188_oPCAN_RADAR_13e175fe_Tx 52u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_189_192_oPCAN_RADAR_21a99aff_Tx 53u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_193_196_oPCAN_RADAR_3c6e99d1_Tx 54u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_197_200_oPCAN_RADAR_50a8f4fa_Tx 55u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_201_204_oPCAN_RADAR_6c70b720_Tx 56u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_205_208_oPCAN_RADAR_85c22914_Tx 57u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_209_212_oPCAN_RADAR_b78ac615_Tx 58u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_213_216_oPCAN_RADAR_aa4dc53b_Tx 59u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_217_220_oPCAN_RADAR_05c118f2_Tx 60u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_221_224_oPCAN_RADAR_88ca180e_Tx 61u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_225_228_oPCAN_RADAR_6178863a_Tx 62u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_229_232_oPCAN_RADAR_5330693b_Tx 63u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_233_236_oPCAN_RADAR_4ef76a15_Tx 64u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_237_240_oPCAN_RADAR_f8d738c7_Tx 65u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_241_244_oPCAN_RADAR_7e74ef3d_Tx 66u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_245_248_oPCAN_RADAR_97c67109_Tx 67u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_249_252_oPCAN_RADAR_a58e9e08_Tx 68u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_253_256_oPCAN_RADAR_b8499d26_Tx 69u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_257_260_oPCAN_RADAR_17c540ef_Tx 70u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_261_264_oPCAN_RADAR_9ace4013_Tx 71u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_265_268_oPCAN_RADAR_737cde27_Tx 72u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_269_272_oPCAN_RADAR_41343126_Tx 73u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_273_276_oPCAN_RADAR_5cf33208_Tx 74u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_277_280_oPCAN_RADAR_d98a7eec_Tx 75u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_281_284_oPCAN_RADAR_4878071a_Tx 76u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_285_288_oPCAN_RADAR_a1ca992e_Tx 77u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_289_292_oPCAN_RADAR_9382762f_Tx 78u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_293_296_oPCAN_RADAR_8e457501_Tx 79u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_297_300_oPCAN_RADAR_4a05a9bb_Tx 80u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_301_304_oPCAN_RADAR_0269ec90_Tx 81u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_305_308_oPCAN_RADAR_ebdb72a4_Tx 82u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_309_312_oPCAN_RADAR_d9939da5_Tx 83u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_313_316_oPCAN_RADAR_c4549e8b_Tx 84u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_317_320_oPCAN_RADAR_6bd84342_Tx 85u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_321_324_oPCAN_RADAR_e6d343be_Tx 86u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_325_328_oPCAN_RADAR_0f61dd8a_Tx 87u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_329_332_oPCAN_RADAR_3d29328b_Tx 88u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_333_336_oPCAN_RADAR_20ee31a5_Tx 89u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_337_340_oPCAN_RADAR_96ce6377_Tx 90u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_341_344_oPCAN_RADAR_106db48d_Tx 91u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_345_348_oPCAN_RADAR_f9df2ab9_Tx 92u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_349_352_oPCAN_RADAR_cb97c5b8_Tx 93u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_353_356_oPCAN_RADAR_d650c696_Tx 94u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_357_360_oPCAN_RADAR_79dc1b5f_Tx 95u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_361_364_oPCAN_RADAR_f4d71ba3_Tx 96u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_365_368_oPCAN_RADAR_1d658597_Tx 97u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_369_372_oPCAN_RADAR_2f2d6a96_Tx 98u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_373_376_oPCAN_RADAR_32ea69b8_Tx 99u     /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_377_380_oPCAN_RADAR_b793255c_Tx 100u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_381_384_oPCAN_RADAR_26615caa_Tx 101u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_385_388_oPCAN_RADAR_cfd3c29e_Tx 102u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_389_392_oPCAN_RADAR_fd9b2d9f_Tx 103u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_393_396_oPCAN_RADAR_e05c2eb1_Tx 104u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_DETECTION_397_400_oPCAN_RADAR_06e626f9_Tx 105u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_HEADER_001_oPCAN_RADAR_0cd81ee7_Tx        106u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_OBJ_HEADER_002_oPCAN_RADAR_1ea433e3_Tx    107u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_OBJ_STATUS_003_oPCAN_RADAR_84871644_Tx    108u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_STATUS_001_oPCAN_RADAR_4b6de2c5_Tx        109u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_STATUS_002_oPCAN_RADAR_f6a78e0b_Tx        110u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_001_oPCAN_RADAR_2e87fb56_Tx   111u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_002_oPCAN_RADAR_934d9798_Tx   112u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_003_oPCAN_RADAR_4edb4e1d_Tx   113u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_004_oPCAN_RADAR_33a84845_Tx   114u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_005_oPCAN_RADAR_ee3e91c0_Tx   115u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_006_oPCAN_RADAR_53f4fd0e_Tx   116u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_007_oPCAN_RADAR_8e62248b_Tx   117u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_008_oPCAN_RADAR_a912f1be_Tx   118u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_009_oPCAN_RADAR_7484283b_Tx   119u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_010_oPCAN_RADAR_6e1ec3a5_Tx   120u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_011_oPCAN_RADAR_b3881a20_Tx   121u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_012_oPCAN_RADAR_0e4276ee_Tx   122u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_013_oPCAN_RADAR_d3d4af6b_Tx   123u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_014_oPCAN_RADAR_aea7a933_Tx   124u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_015_oPCAN_RADAR_733170b6_Tx   125u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_016_oPCAN_RADAR_cefb1c78_Tx   126u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_017_oPCAN_RADAR_136dc5fd_Tx   127u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_018_oPCAN_RADAR_341d10c8_Tx   128u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_019_oPCAN_RADAR_e98bc94d_Tx   129u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_020_oPCAN_RADAR_127fe67e_Tx   130u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_021_oPCAN_RADAR_cfe93ffb_Tx   131u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_022_oPCAN_RADAR_72235335_Tx   132u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_023_oPCAN_RADAR_afb58ab0_Tx   133u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_024_oPCAN_RADAR_d2c68ce8_Tx   134u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_025_oPCAN_RADAR_0f50556d_Tx   135u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_026_oPCAN_RADAR_b29a39a3_Tx   136u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_027_oPCAN_RADAR_6f0ce026_Tx   137u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_028_oPCAN_RADAR_487c3513_Tx   138u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_029_oPCAN_RADAR_95eaec96_Tx   139u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_030_oPCAN_RADAR_8f700708_Tx   140u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_031_oPCAN_RADAR_52e6de8d_Tx   141u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_032_oPCAN_RADAR_ef2cb243_Tx   142u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_033_oPCAN_RADAR_32ba6bc6_Tx   143u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_034_oPCAN_RADAR_4fc96d9e_Tx   144u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_035_oPCAN_RADAR_925fb41b_Tx   145u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_036_oPCAN_RADAR_2f95d8d5_Tx   146u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_037_oPCAN_RADAR_f2030150_Tx   147u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_038_oPCAN_RADAR_d573d465_Tx   148u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_039_oPCAN_RADAR_08e50de0_Tx   149u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_040_oPCAN_RADAR_eabdadc8_Tx   150u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_041_oPCAN_RADAR_372b744d_Tx   151u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_042_oPCAN_RADAR_8ae11883_Tx   152u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_043_oPCAN_RADAR_5777c106_Tx   153u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_044_oPCAN_RADAR_2a04c75e_Tx   154u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_045_oPCAN_RADAR_f7921edb_Tx   155u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_046_oPCAN_RADAR_4a587215_Tx   156u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_047_oPCAN_RADAR_97ceab90_Tx   157u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_048_oPCAN_RADAR_b0be7ea5_Tx   158u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_049_oPCAN_RADAR_6d28a720_Tx   159u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_050_oPCAN_RADAR_77b24cbe_Tx   160u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_051_oPCAN_RADAR_aa24953b_Tx   161u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_052_oPCAN_RADAR_17eef9f5_Tx   162u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_053_oPCAN_RADAR_ca782070_Tx   163u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_054_oPCAN_RADAR_b70b2628_Tx   164u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_055_oPCAN_RADAR_6a9dffad_Tx   165u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_056_oPCAN_RADAR_d7579363_Tx   166u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_057_oPCAN_RADAR_0ac14ae6_Tx   167u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_058_oPCAN_RADAR_2db19fd3_Tx   168u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_059_oPCAN_RADAR_f0274656_Tx   169u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_060_oPCAN_RADAR_0bd36965_Tx   170u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_061_oPCAN_RADAR_d645b0e0_Tx   171u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_062_oPCAN_RADAR_6b8fdc2e_Tx   172u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_063_oPCAN_RADAR_b61905ab_Tx   173u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_RDR_TRACKER_OBJ_064_oPCAN_RADAR_cb6a03f3_Tx   174u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
#define ComConf_ComIPdu_prop_ADAS_MOIS_info_oVCAN_RADAR_f03aed28_Tx   175u    /**< [RDR_01, RDR_02, RDR_03, RDR_04, RDR_05, RDR_06, RDR_07, RDR_08] */
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
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */

/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after an I-PDU has been received.
    \param[in]    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                               Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    PduInfoPtr   Pointer to an instance of PduInfoType.
                                 - PduInfoPtr->MetaDataPtr may contain metadata or NULL_PTR.
                                 - PduInfoPtr->SduDataPtr contains the contents of the Pdu. 
                                 - PduInfoPtr->SduLength indicates the length of the Pdu.
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737026
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after the PDU has been transmitted on the network.
                  A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param[in]    TxPduId   ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737028
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief          This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
                    Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
                    to the L-PDU buffer given by SduPtr.
                    Use case:
                    This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
                    can be initiated by the Master schedule table itself or a received LIN header.
                    This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
                    (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
                    (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param[in]      TxPduId       ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param[in,out]  PduInfoPtr    Pointer to an instance of PduInfoType.
                                  Contains a pointer to a buffer to which the destination module copies the data:
                                    - PduInfoPtr->MetaDataPtr Is ignored. No meta data is copied in the TriggerTransmit API. The meta data has to be provided in the Transmit API.
                                    - PduInfoPtr->SduDataPtr Contains a pointer to the buffer.
                                    - PduInfoPtr->SduLength In: Contains the length of the provided buffer. Out: Contains the amount of bytes which were actually copied.
    \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
    \return         E_NOT_OK      No data has been copied, because
                                  Com is not initialized
                                  or TxPduId is not valid
                                  or PduInfoPtr is NULL_PTR
                                  or SduDataPtr is NULL_PTR
                                  or SduLength is too small.
    \context        TASK|ISR2
    \synchronous    TRUE
    \reentrant      TRUE, for different Handles
    \trace          SPEC-2737022, SPEC-2737023, SPEC-2737024
    \note           The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr);

/**********************************************************************************************************************
  Com_TpTxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the PduR after a large I-PDU has been transmitted via the transport protocol on its network.
    \param[in]    PduId    ID of the I-PDU that has been transmitted.
    \param[in]    Result   Result of the transmission of the I-PDU
    \context      TASK|ISR2
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737029
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TpTxConfirmation( PduIdType PduId, Std_ReturnType Result );

/**********************************************************************************************************************
  Com_CopyTxData
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer to copy Data from the Com TP buffer to the lower layer TP buffer.
    \param[in]    PduId               ID of Com TP I-PDU to be transmitted.
    \param[in]    PduInfoPtr          Pointer to an instance of PduInfoType. 
                                      Contains a pointer to a buffer to which the destination module copies the data:
                                        - PduInfoPtr->MetaDataPtr Is ignored. No meta data is copied in the CopyTxData API. The meta data has to be provided in the Transmit API.
                                        - PduInfoPtr->SduDataPtr Contains a pointer to the buffer.
                                        - PduInfoPtr->SduLength Contains the length of the provided buffer. A SduLength of 0 is possible in order to poll the available transmit data count.
    \param[in]    RetryInfoPtr        If the TpDataState of the RetryInfoPtr is TP_DATARETRY no data will be copied. Otherwise, the COM module
                                      will ignore the value of this pointer, since it always keeps the complete buffer until the transmission of a large I-PDU is either confirmed or aborted.
    \param[out]   TxDataCntPtr        Out parameter: Remaining Tx data after completion of this call.
    \return       BufReq_ReturnType   BUFREQ_OK:       Data has been copied to the transmit buffer completely as requested.
                                      BUFREQ_E_BUSY:   The transmission buffer is actually not available (implementation specific).
                                      BUFREQ_E_NOT_OK: Data has not been copied. Request failed, in case the corresponding I-PDU was stopped.
    \context      TASK|ISR2
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2736849, SPEC-2737039, SPEC-2737040
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr, P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_VAR) RetryInfoPtr, P2VAR(PduLengthType, AUTOMATIC, COM_APPL_VAR) TxDataCntPtr);

/**********************************************************************************************************************
  Com_TpRxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after a TP I-PDU has been received.
    \param[in]    PduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                             Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    Result     Indicates whether the Message was received successfully.
    \context      TASK|ISR2
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737027, SPEC-2737063
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TpRxIndication( PduIdType PduId, Std_ReturnType Result );

/**********************************************************************************************************************
  Com_StartOfReception
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer to indicate the start of a incoming TP connection.
    \param[in]    ComRxPduId         ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
    \param[in]    PduInfoPtr         Pointer to an instance of PduInfoType.
                                      - PduInfoPtr->MetaDataPtr may contain metadata or NULL_PTR.
                                      - PduInfoPtr->SduDataPtr may contain contents of the first frame of the Tp Pdu or NULL_PTR. FF and SF data will be ignored.
                                      - PduInfoPtr->SduLength may indicate the length of the first frame or zero. FF and SF data will be ignored.
                                      - PduInfoPtr may be NULL_PTR if None of the above parameters are used.
    \param[in]    TpSduLength        complete length of the TP I-PDU to be received.
    \param[out]   RxBufferSizePtr    The Com returns in this value the remaining TP buffer size to the lower layer.
    \return       BufReq_ReturnType  BUFREQ_OK:       Connection has been accepted.
                                                      RxBufferSizePtr indicates the available receive buffer.
                                     BUFREQ_E_NOT_OK: Connection has been rejected.
                                                      RxBufferSizePtr remains unchanged.
                                     BUFREQ_E_OVFL:   In case the configured buffer size as specified via ComPduIdRef.PduLength is smaller than TpSduLength.
    \context      TASK|ISR2
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2736846, SPEC-2737030, SPEC-2737031, SPEC-2737032, SPEC-2737033, SPEC-2737034, SPEC-2737035, SPEC-2737036
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception(PduIdType ComRxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, COM_APPL_VAR) RxBufferSizePtr);

/**********************************************************************************************************************
  Com_CopyRxData
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer to hand a received TP segment to Com.
                  The Com copies the received segment in his internal tp buffer.
    \param[in]    PduId             ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
    \param[in]    PduInfoPtr        Pointer to an instance of PduInfoType. 
                                    Contains a pointer to a buffer from which the destination module copies the received data:
                                      - PduInfoPtr->MetaDataPtr Is ignored. No meta data is copied in the CopyRxData API. The meta data has to be provided in the StartOfReception API.
                                      - PduInfoPtr->SduDataPtr Contains a pointer to the data.
                                      - PduInfoPtr->SduLength Contains the length of the provided data.
    \param[out]   RxBufferSizePtr    The Com returns in this value the remaining TP buffer size to the lower layer.
    \return       BufReq_ReturnType  BUFREQ_OK:       Connection has been accepted.
                                                      RxBufferSizePtr indicates the available receive buffer.
                                     BUFREQ_E_NOT_OK: Connection has been rejected.
                                                      RxBufferSizePtr remains unchanged.
    \context      TASK|ISR2
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2736846, SPEC-2737037, SPEC-2737038
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData(PduIdType PduId, CONSTP2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr, P2VAR(PduLengthType, AUTOMATIC, COM_APPL_VAR) RxBufferSizePtr);

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

