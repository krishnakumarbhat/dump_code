/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  ComXf.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR ComXf Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  MICROSAR ComXf header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef COMXF_H
# define COMXF_H


# include "SchM_ComXf_Type.h"

# define COMXF_SW_MAJOR_VERSION (0x04U)
# define COMXF_SW_MINOR_VERSION (0x28U)
# define COMXF_SW_PATCH_VERSION (0x00U)

# define COMXF_VENDOR_ID (0x1EU)
# define COMXF_MODULE_ID (0xAFU)

# define COMXF_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define COMXF_AR_RELEASE_MINOR_VERSION     (0x02U)
# define COMXF_AR_RELEASE_REVISION_VERSION  (0x02U)

/* Return Codes */
# define COMXF_E_SER_GENERIC_ERROR (0x81U)

# define COMXF_START_SEC_CODE_ASIL_B
# include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * ComXf transformers
 *********************************************************************************************************************/

/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_001_004_oRDR_DETECTION_001_004_oPCAN_RADAR_df4895a5_Tx_I_SG_Detections_001_004_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_005_008_oRDR_DETECTION_005_008_oPCAN_RADAR_ae8ba1f7_Tx_I_SG_Detections_005_008_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_005_008_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_009_012_oRDR_DETECTION_009_012_oPCAN_RADAR_37f1858c_Tx_I_SG_Detections_009_012_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_009_012_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_013_016_oRDR_DETECTION_013_016_oPCAN_RADAR_05faeda4_Tx_I_SG_Detections_013_016_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_013_016_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_017_020_oRDR_DETECTION_017_020_oPCAN_RADAR_e956bb2e_Tx_I_SG_Detections_017_020_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_017_020_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_021_024_oRDR_DETECTION_021_024_oPCAN_RADAR_ea3d35f7_Tx_I_SG_Detections_021_024_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_021_024_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_025_028_oRDR_DETECTION_025_028_oPCAN_RADAR_9bfe01a5_Tx_I_SG_Detections_025_028_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_025_028_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_029_032_oRDR_DETECTION_029_032_oPCAN_RADAR_028425de_Tx_I_SG_Detections_029_032_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_029_032_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_033_036_oRDR_DETECTION_033_036_oPCAN_RADAR_308f4df6_Tx_I_SG_Detections_033_036_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_033_036_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_037_040_oRDR_DETECTION_037_040_oPCAN_RADAR_abdcc2d8_Tx_I_SG_Detections_037_040_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_037_040_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_041_044_oRDR_DETECTION_041_044_oPCAN_RADAR_b5a3d501_Tx_I_SG_Detections_041_044_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_041_044_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_045_048_oRDR_DETECTION_045_048_oPCAN_RADAR_c460e153_Tx_I_SG_Detections_045_048_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_045_048_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_049_052_oRDR_DETECTION_049_052_oPCAN_RADAR_5d1ac528_Tx_I_SG_Detections_049_052_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_049_052_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_053_056_oRDR_DETECTION_053_056_oPCAN_RADAR_6f11ad00_Tx_I_SG_Detections_053_056_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_053_056_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_057_060_oRDR_DETECTION_057_060_oPCAN_RADAR_83bdfb8a_Tx_I_SG_Detections_057_060_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_057_060_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_061_064_oRDR_DETECTION_061_064_oPCAN_RADAR_80d67553_Tx_I_SG_Detections_061_064_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_061_064_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_065_068_oRDR_DETECTION_065_068_oPCAN_RADAR_f1154101_Tx_I_SG_Detections_065_068_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_065_068_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_069_072_oRDR_DETECTION_069_072_oPCAN_RADAR_686f657a_Tx_I_SG_Detections_069_072_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_069_072_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_073_076_oRDR_DETECTION_073_076_oPCAN_RADAR_5a640d52_Tx_I_SG_Detections_073_076_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_073_076_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_077_080_oRDR_DETECTION_077_080_oPCAN_RADAR_2ec83134_Tx_I_SG_Detections_077_080_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_077_080_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_081_084_oRDR_DETECTION_081_084_oPCAN_RADAR_0a9e14ed_Tx_I_SG_Detections_081_084_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_081_084_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_085_088_oRDR_DETECTION_085_088_oPCAN_RADAR_7b5d20bf_Tx_I_SG_Detections_085_088_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_085_088_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_089_092_oRDR_DETECTION_089_092_oPCAN_RADAR_e22704c4_Tx_I_SG_Detections_089_092_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_089_092_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_093_096_oRDR_DETECTION_093_096_oPCAN_RADAR_d02c6cec_Tx_I_SG_Detections_093_096_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_093_096_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_097_100_oRDR_DETECTION_097_100_oPCAN_RADAR_dcf343f6_Tx_I_SG_Detections_097_100_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_097_100_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_101_104_oRDR_DETECTION_101_104_oPCAN_RADAR_9de0b719_Tx_I_SG_Detections_101_104_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_101_104_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_105_108_oRDR_DETECTION_105_108_oPCAN_RADAR_ec23834b_Tx_I_SG_Detections_105_108_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_105_108_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_109_112_oRDR_DETECTION_109_112_oPCAN_RADAR_7559a730_Tx_I_SG_Detections_109_112_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_109_112_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_113_116_oRDR_DETECTION_113_116_oPCAN_RADAR_4752cf18_Tx_I_SG_Detections_113_116_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_113_116_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_117_120_oRDR_DETECTION_117_120_oPCAN_RADAR_abfe9992_Tx_I_SG_Detections_117_120_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_117_120_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_121_124_oRDR_DETECTION_121_124_oPCAN_RADAR_a895174b_Tx_I_SG_Detections_121_124_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_121_124_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_125_128_oRDR_DETECTION_125_128_oPCAN_RADAR_d9562319_Tx_I_SG_Detections_125_128_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_125_128_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_129_132_oRDR_DETECTION_129_132_oPCAN_RADAR_402c0762_Tx_I_SG_Detections_129_132_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_129_132_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_133_136_oRDR_DETECTION_133_136_oPCAN_RADAR_72276f4a_Tx_I_SG_Detections_133_136_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_133_136_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_137_140_oRDR_DETECTION_137_140_oPCAN_RADAR_e974e064_Tx_I_SG_Detections_137_140_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_137_140_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_141_144_oRDR_DETECTION_141_144_oPCAN_RADAR_f70bf7bd_Tx_I_SG_Detections_141_144_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_141_144_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_145_148_oRDR_DETECTION_145_148_oPCAN_RADAR_86c8c3ef_Tx_I_SG_Detections_145_148_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_145_148_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_149_152_oRDR_DETECTION_149_152_oPCAN_RADAR_1fb2e794_Tx_I_SG_Detections_149_152_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_149_152_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_153_156_oRDR_DETECTION_153_156_oPCAN_RADAR_2db98fbc_Tx_I_SG_Detections_153_156_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_153_156_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_157_160_oRDR_DETECTION_157_160_oPCAN_RADAR_c115d936_Tx_I_SG_Detections_157_160_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_157_160_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_161_164_oRDR_DETECTION_161_164_oPCAN_RADAR_c27e57ef_Tx_I_SG_Detections_161_164_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_161_164_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_165_168_oRDR_DETECTION_165_168_oPCAN_RADAR_b3bd63bd_Tx_I_SG_Detections_165_168_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_165_168_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_169_172_oRDR_DETECTION_169_172_oPCAN_RADAR_2ac747c6_Tx_I_SG_Detections_169_172_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_169_172_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_173_176_oRDR_DETECTION_173_176_oPCAN_RADAR_18cc2fee_Tx_I_SG_Detections_173_176_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_173_176_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_177_180_oRDR_DETECTION_177_180_oPCAN_RADAR_6c601388_Tx_I_SG_Detections_177_180_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_177_180_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_181_184_oRDR_DETECTION_181_184_oPCAN_RADAR_48363651_Tx_I_SG_Detections_181_184_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_181_184_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_185_188_oRDR_DETECTION_185_188_oPCAN_RADAR_39f50203_Tx_I_SG_Detections_185_188_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_185_188_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_189_192_oRDR_DETECTION_189_192_oPCAN_RADAR_a08f2678_Tx_I_SG_Detections_189_192_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_189_192_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_193_196_oRDR_DETECTION_193_196_oPCAN_RADAR_92844e50_Tx_I_SG_Detections_193_196_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_193_196_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_197_200_oRDR_DETECTION_197_200_oPCAN_RADAR_f6bd2d5e_Tx_I_SG_Detections_197_200_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_197_200_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_201_204_oRDR_DETECTION_201_204_oPCAN_RADAR_5a18d0dd_Tx_I_SG_Detections_201_204_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_201_204_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_205_208_oRDR_DETECTION_205_208_oPCAN_RADAR_2bdbe48f_Tx_I_SG_Detections_205_208_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_205_208_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_209_212_oRDR_DETECTION_209_212_oPCAN_RADAR_b2a1c0f4_Tx_I_SG_Detections_209_212_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_209_212_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_213_216_oRDR_DETECTION_213_216_oPCAN_RADAR_80aaa8dc_Tx_I_SG_Detections_213_216_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_213_216_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_217_220_oRDR_DETECTION_217_220_oPCAN_RADAR_6c06fe56_Tx_I_SG_Detections_217_220_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_217_220_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_221_224_oRDR_DETECTION_221_224_oPCAN_RADAR_6f6d708f_Tx_I_SG_Detections_221_224_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_221_224_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_225_228_oRDR_DETECTION_225_228_oPCAN_RADAR_1eae44dd_Tx_I_SG_Detections_225_228_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_225_228_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_229_232_oRDR_DETECTION_229_232_oPCAN_RADAR_87d460a6_Tx_I_SG_Detections_229_232_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_229_232_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_233_236_oRDR_DETECTION_233_236_oPCAN_RADAR_b5df088e_Tx_I_SG_Detections_233_236_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_233_236_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_237_240_oRDR_DETECTION_237_240_oPCAN_RADAR_2e8c87a0_Tx_I_SG_Detections_237_240_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_237_240_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_241_244_oRDR_DETECTION_241_244_oPCAN_RADAR_30f39079_Tx_I_SG_Detections_241_244_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_241_244_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_245_248_oRDR_DETECTION_245_248_oPCAN_RADAR_4130a42b_Tx_I_SG_Detections_245_248_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_245_248_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_249_252_oRDR_DETECTION_249_252_oPCAN_RADAR_d84a8050_Tx_I_SG_Detections_249_252_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_249_252_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_253_256_oRDR_DETECTION_253_256_oPCAN_RADAR_ea41e878_Tx_I_SG_Detections_253_256_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_253_256_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_257_260_oRDR_DETECTION_257_260_oPCAN_RADAR_06edbef2_Tx_I_SG_Detections_257_260_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_257_260_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_261_264_oRDR_DETECTION_261_264_oPCAN_RADAR_0586302b_Tx_I_SG_Detections_261_264_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_261_264_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_265_268_oRDR_DETECTION_265_268_oPCAN_RADAR_74450479_Tx_I_SG_Detections_265_268_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_265_268_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_269_272_oRDR_DETECTION_269_272_oPCAN_RADAR_ed3f2002_Tx_I_SG_Detections_269_272_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_269_272_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_273_276_oRDR_DETECTION_273_276_oPCAN_RADAR_df34482a_Tx_I_SG_Detections_273_276_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_273_276_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_277_280_oRDR_DETECTION_277_280_oPCAN_RADAR_ab98744c_Tx_I_SG_Detections_277_280_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_277_280_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_281_284_oRDR_DETECTION_281_284_oPCAN_RADAR_8fce5195_Tx_I_SG_Detections_281_284_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_281_284_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_285_288_oRDR_DETECTION_285_288_oPCAN_RADAR_fe0d65c7_Tx_I_SG_Detections_285_288_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_285_288_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_289_292_oRDR_DETECTION_289_292_oPCAN_RADAR_677741bc_Tx_I_SG_Detections_289_292_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_289_292_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_293_296_oRDR_DETECTION_293_296_oPCAN_RADAR_557c2994_Tx_I_SG_Detections_293_296_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_293_296_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_297_300_oRDR_DETECTION_297_300_oPCAN_RADAR_59a3068e_Tx_I_SG_Detections_297_300_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_297_300_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_301_304_oRDR_DETECTION_301_304_oPCAN_RADAR_18b0f261_Tx_I_SG_Detections_301_304_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_301_304_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_305_308_oRDR_DETECTION_305_308_oPCAN_RADAR_6973c633_Tx_I_SG_Detections_305_308_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_305_308_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_309_312_oRDR_DETECTION_309_312_oPCAN_RADAR_f009e248_Tx_I_SG_Detections_309_312_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_309_312_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_313_316_oRDR_DETECTION_313_316_oPCAN_RADAR_c2028a60_Tx_I_SG_Detections_313_316_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_313_316_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_317_320_oRDR_DETECTION_317_320_oPCAN_RADAR_2eaedcea_Tx_I_SG_Detections_317_320_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_317_320_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_321_324_oRDR_DETECTION_321_324_oPCAN_RADAR_2dc55233_Tx_I_SG_Detections_321_324_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_321_324_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_325_328_oRDR_DETECTION_325_328_oPCAN_RADAR_5c066661_Tx_I_SG_Detections_325_328_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_325_328_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_329_332_oRDR_DETECTION_329_332_oPCAN_RADAR_c57c421a_Tx_I_SG_Detections_329_332_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_329_332_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_333_336_oRDR_DETECTION_333_336_oPCAN_RADAR_f7772a32_Tx_I_SG_Detections_333_336_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_333_336_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_337_340_oRDR_DETECTION_337_340_oPCAN_RADAR_6c24a51c_Tx_I_SG_Detections_337_340_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_337_340_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_341_344_oRDR_DETECTION_341_344_oPCAN_RADAR_725bb2c5_Tx_I_SG_Detections_341_344_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_341_344_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_345_348_oRDR_DETECTION_345_348_oPCAN_RADAR_03988697_Tx_I_SG_Detections_345_348_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_345_348_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_349_352_oRDR_DETECTION_349_352_oPCAN_RADAR_9ae2a2ec_Tx_I_SG_Detections_349_352_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_349_352_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_353_356_oRDR_DETECTION_353_356_oPCAN_RADAR_a8e9cac4_Tx_I_SG_Detections_353_356_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_353_356_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_357_360_oRDR_DETECTION_357_360_oPCAN_RADAR_44459c4e_Tx_I_SG_Detections_357_360_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_357_360_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_361_364_oRDR_DETECTION_361_364_oPCAN_RADAR_472e1297_Tx_I_SG_Detections_361_364_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_361_364_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_365_368_oRDR_DETECTION_365_368_oPCAN_RADAR_36ed26c5_Tx_I_SG_Detections_365_368_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_365_368_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_369_372_oRDR_DETECTION_369_372_oPCAN_RADAR_af9702be_Tx_I_SG_Detections_369_372_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_369_372_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_373_376_oRDR_DETECTION_373_376_oPCAN_RADAR_9d9c6a96_Tx_I_SG_Detections_373_376_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_373_376_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_377_380_oRDR_DETECTION_377_380_oPCAN_RADAR_e93056f0_Tx_I_SG_Detections_377_380_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_377_380_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_381_384_oRDR_DETECTION_381_384_oPCAN_RADAR_cd667329_Tx_I_SG_Detections_381_384_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_381_384_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_385_388_oRDR_DETECTION_385_388_oPCAN_RADAR_bca5477b_Tx_I_SG_Detections_385_388_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_385_388_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_389_392_oRDR_DETECTION_389_392_oPCAN_RADAR_25df6300_Tx_I_SG_Detections_389_392_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_389_392_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_393_396_oRDR_DETECTION_393_396_oPCAN_RADAR_17d40b28_Tx_I_SG_Detections_393_396_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_393_396_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 60;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_Detections_397_400_oRDR_DETECTION_397_400_oPCAN_RADAR_a221f00e_Tx_I_SG_Detections_397_400_AL(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_Detections_397_400_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 1;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_GW_prop_ADAS_BSIS_info_oGW_prop_ADAS_BSIS_info_oPCAN_RADAR_e9da8865_Tx_I_SG_GW_prop_ADAS_BSIS_info_ALPCAN(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_GW_prop_ADAS_BSIS_info_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 1;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_MOIS_oMOIS_oVCAN_RADAR_f9ec408e_Tx_I_SG_MOIS_ALVCAN(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_MOIS_ALVCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 1;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_RDR_BSD1_Tx_oRDR_BSD1_Tx_oPCAN_RADAR_bd131ac1_Tx_I_SG_RDR_BSD1_Tx_ALPCAN(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RDR_BSD1_Tx_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 20;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_TrackerHeader_oRDR_OBJ_HEADER_002_oPCAN_RADAR_563ddea3_Tx_SG_TrackerHeader_impdt(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(SG_TrackerHeader_impdt, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 13;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_TrackerStatus_oRDR_OBJ_STATUS_003_oPCAN_RADAR_3d577421_Tx_SG_TrackerStatus_impdt(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(SG_TrackerStatus_impdt, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 1;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Com_SG_prop_ADAS_MOIS_info_oprop_ADAS_MOIS_info_oVCAN_RADAR_cb191e50_Tx_I_SG_prop_ADAS_MOIS_info_ALVCAN(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_prop_ADAS_MOIS_info_ALVCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 41;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 27;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 64;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 63;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires $lengthOf(buffer) >= 50;
 *    requires bufferLength != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, COMXF_APPL_VAR) bufferLength, P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, COMXF_APPL_DATA) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * ComXf retransformers
 *********************************************************************************************************************/

/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_005_008_oRDR_FUSION_DET_005_008_oPCAN_RADAR_0783a66c_Rx_I_SG_Fusion_Detections_005_008_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_005_008_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_009_012_oRDR_FUSION_DET_009_012_oPCAN_RADAR_85b0e384_Rx_I_SG_Fusion_Detections_009_012_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_009_012_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_013_016_oRDR_FUSION_DET_013_016_oPCAN_RADAR_713b89f4_Rx_I_SG_Fusion_Detections_013_016_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_013_016_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_017_020_oRDR_FUSION_DET_017_020_oPCAN_RADAR_3121649c_Rx_I_SG_Fusion_Detections_017_020_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_017_020_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_021_024_oRDR_FUSION_DET_021_024_oPCAN_RADAR_f7a0d0a9_Rx_I_SG_Fusion_Detections_021_024_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_021_024_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_025_028_oRDR_FUSION_DET_025_028_oPCAN_RADAR_ba5bfb5a_Rx_I_SG_Fusion_Detections_025_028_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_025_028_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_029_032_oRDR_FUSION_DET_029_032_oPCAN_RADAR_3868beb2_Rx_I_SG_Fusion_Detections_029_032_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_029_032_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_033_036_oRDR_FUSION_DET_033_036_oPCAN_RADAR_cce3d4c2_Rx_I_SG_Fusion_Detections_033_036_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_033_036_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_037_040_oRDR_FUSION_DET_037_040_oPCAN_RADAR_cee54bfa_Rx_I_SG_Fusion_Detections_037_040_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_037_040_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_041_044_oRDR_FUSION_DET_041_044_oPCAN_RADAR_eab931b2_Rx_I_SG_Fusion_Detections_041_044_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_041_044_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_045_048_oRDR_FUSION_DET_045_048_oPCAN_RADAR_a7421a41_Rx_I_SG_Fusion_Detections_045_048_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_045_048_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_049_052_oRDR_FUSION_DET_049_052_oPCAN_RADAR_25715fa9_Rx_I_SG_Fusion_Detections_049_052_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_049_052_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_053_056_oRDR_FUSION_DET_053_056_oPCAN_RADAR_d1fa35d9_Rx_I_SG_Fusion_Detections_053_056_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_053_056_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_057_060_oRDR_FUSION_DET_057_060_oPCAN_RADAR_91e0d8b1_Rx_I_SG_Fusion_Detections_057_060_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_057_060_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_061_064_oRDR_FUSION_DET_061_064_oPCAN_RADAR_57616c84_Rx_I_SG_Fusion_Detections_061_064_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_061_064_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_065_068_oRDR_FUSION_DET_065_068_oPCAN_RADAR_1a9a4777_Rx_I_SG_Fusion_Detections_065_068_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_065_068_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_069_072_oRDR_FUSION_DET_069_072_oPCAN_RADAR_98a9029f_Rx_I_SG_Fusion_Detections_069_072_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_069_072_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_073_076_oRDR_FUSION_DET_073_076_oPCAN_RADAR_6c2268ef_Rx_I_SG_Fusion_Detections_073_076_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_073_076_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_077_080_oRDR_FUSION_DET_077_080_oPCAN_RADAR_ea1c1377_Rx_I_SG_Fusion_Detections_077_080_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_077_080_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_081_084_oRDR_FUSION_DET_081_084_oPCAN_RADAR_d08af384_Rx_I_SG_Fusion_Detections_081_084_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_081_084_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_085_088_oRDR_FUSION_DET_085_088_oPCAN_RADAR_9d71d877_Rx_I_SG_Fusion_Detections_085_088_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_085_088_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_089_092_oRDR_FUSION_DET_089_092_oPCAN_RADAR_1f429d9f_Rx_I_SG_Fusion_Detections_089_092_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_089_092_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_093_096_oRDR_FUSION_DET_093_096_oPCAN_RADAR_ebc9f7ef_Rx_I_SG_Fusion_Detections_093_096_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_093_096_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_097_100_oRDR_FUSION_DET_097_100_oPCAN_RADAR_f997174e_Rx_I_SG_Fusion_Detections_097_100_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_097_100_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_101_104_oRDR_FUSION_DET_101_104_oPCAN_RADAR_2dfb2b7d_Rx_I_SG_Fusion_Detections_101_104_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_101_104_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_105_108_oRDR_FUSION_DET_105_108_oPCAN_RADAR_6000008e_Rx_I_SG_Fusion_Detections_105_108_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_105_108_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_109_112_oRDR_FUSION_DET_109_112_oPCAN_RADAR_e2334566_Rx_I_SG_Fusion_Detections_109_112_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_109_112_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_113_116_oRDR_FUSION_DET_113_116_oPCAN_RADAR_16b82f16_Rx_I_SG_Fusion_Detections_113_116_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_113_116_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_117_120_oRDR_FUSION_DET_117_120_oPCAN_RADAR_56a2c27e_Rx_I_SG_Fusion_Detections_117_120_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_117_120_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_121_124_oRDR_FUSION_DET_121_124_oPCAN_RADAR_9023764b_Rx_I_SG_Fusion_Detections_121_124_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_121_124_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_Fusion_Detections_125_128_oRDR_FUSION_DET_125_128_oPCAN_RADAR_ddd85db8_Rx_I_SG_Fusion_Detections_125_128_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_Detections_125_128_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SG_VehicleStatus_oSYS_VEHICLE_STATUS_oPCAN_RADAR_0411a809_Rx_I_SG_VehicleStatus_AL(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_VehicleStatus_AL, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */


# define COMXF_STOP_SEC_CODE_ASIL_B
# include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Defines for ComXf transformer APIs
 *********************************************************************************************************************/

# define ComXf_Com_SG_Detections_001_004_oRDR_DETECTION_001_004_oPCAN_RADAR_df4895a5_Tx ComXf_Com_SG_Detections_001_004_oRDR_DETECTION_001_004_oPCAN_RADAR_df4895a5_Tx_I_SG_Detections_001_004_AL
# define ComXf_Com_SG_Detections_005_008_oRDR_DETECTION_005_008_oPCAN_RADAR_ae8ba1f7_Tx ComXf_Com_SG_Detections_005_008_oRDR_DETECTION_005_008_oPCAN_RADAR_ae8ba1f7_Tx_I_SG_Detections_005_008_AL
# define ComXf_Com_SG_Detections_009_012_oRDR_DETECTION_009_012_oPCAN_RADAR_37f1858c_Tx ComXf_Com_SG_Detections_009_012_oRDR_DETECTION_009_012_oPCAN_RADAR_37f1858c_Tx_I_SG_Detections_009_012_AL
# define ComXf_Com_SG_Detections_013_016_oRDR_DETECTION_013_016_oPCAN_RADAR_05faeda4_Tx ComXf_Com_SG_Detections_013_016_oRDR_DETECTION_013_016_oPCAN_RADAR_05faeda4_Tx_I_SG_Detections_013_016_AL
# define ComXf_Com_SG_Detections_017_020_oRDR_DETECTION_017_020_oPCAN_RADAR_e956bb2e_Tx ComXf_Com_SG_Detections_017_020_oRDR_DETECTION_017_020_oPCAN_RADAR_e956bb2e_Tx_I_SG_Detections_017_020_AL
# define ComXf_Com_SG_Detections_021_024_oRDR_DETECTION_021_024_oPCAN_RADAR_ea3d35f7_Tx ComXf_Com_SG_Detections_021_024_oRDR_DETECTION_021_024_oPCAN_RADAR_ea3d35f7_Tx_I_SG_Detections_021_024_AL
# define ComXf_Com_SG_Detections_025_028_oRDR_DETECTION_025_028_oPCAN_RADAR_9bfe01a5_Tx ComXf_Com_SG_Detections_025_028_oRDR_DETECTION_025_028_oPCAN_RADAR_9bfe01a5_Tx_I_SG_Detections_025_028_AL
# define ComXf_Com_SG_Detections_029_032_oRDR_DETECTION_029_032_oPCAN_RADAR_028425de_Tx ComXf_Com_SG_Detections_029_032_oRDR_DETECTION_029_032_oPCAN_RADAR_028425de_Tx_I_SG_Detections_029_032_AL
# define ComXf_Com_SG_Detections_033_036_oRDR_DETECTION_033_036_oPCAN_RADAR_308f4df6_Tx ComXf_Com_SG_Detections_033_036_oRDR_DETECTION_033_036_oPCAN_RADAR_308f4df6_Tx_I_SG_Detections_033_036_AL
# define ComXf_Com_SG_Detections_037_040_oRDR_DETECTION_037_040_oPCAN_RADAR_abdcc2d8_Tx ComXf_Com_SG_Detections_037_040_oRDR_DETECTION_037_040_oPCAN_RADAR_abdcc2d8_Tx_I_SG_Detections_037_040_AL
# define ComXf_Com_SG_Detections_041_044_oRDR_DETECTION_041_044_oPCAN_RADAR_b5a3d501_Tx ComXf_Com_SG_Detections_041_044_oRDR_DETECTION_041_044_oPCAN_RADAR_b5a3d501_Tx_I_SG_Detections_041_044_AL
# define ComXf_Com_SG_Detections_045_048_oRDR_DETECTION_045_048_oPCAN_RADAR_c460e153_Tx ComXf_Com_SG_Detections_045_048_oRDR_DETECTION_045_048_oPCAN_RADAR_c460e153_Tx_I_SG_Detections_045_048_AL
# define ComXf_Com_SG_Detections_049_052_oRDR_DETECTION_049_052_oPCAN_RADAR_5d1ac528_Tx ComXf_Com_SG_Detections_049_052_oRDR_DETECTION_049_052_oPCAN_RADAR_5d1ac528_Tx_I_SG_Detections_049_052_AL
# define ComXf_Com_SG_Detections_053_056_oRDR_DETECTION_053_056_oPCAN_RADAR_6f11ad00_Tx ComXf_Com_SG_Detections_053_056_oRDR_DETECTION_053_056_oPCAN_RADAR_6f11ad00_Tx_I_SG_Detections_053_056_AL
# define ComXf_Com_SG_Detections_057_060_oRDR_DETECTION_057_060_oPCAN_RADAR_83bdfb8a_Tx ComXf_Com_SG_Detections_057_060_oRDR_DETECTION_057_060_oPCAN_RADAR_83bdfb8a_Tx_I_SG_Detections_057_060_AL
# define ComXf_Com_SG_Detections_061_064_oRDR_DETECTION_061_064_oPCAN_RADAR_80d67553_Tx ComXf_Com_SG_Detections_061_064_oRDR_DETECTION_061_064_oPCAN_RADAR_80d67553_Tx_I_SG_Detections_061_064_AL
# define ComXf_Com_SG_Detections_065_068_oRDR_DETECTION_065_068_oPCAN_RADAR_f1154101_Tx ComXf_Com_SG_Detections_065_068_oRDR_DETECTION_065_068_oPCAN_RADAR_f1154101_Tx_I_SG_Detections_065_068_AL
# define ComXf_Com_SG_Detections_069_072_oRDR_DETECTION_069_072_oPCAN_RADAR_686f657a_Tx ComXf_Com_SG_Detections_069_072_oRDR_DETECTION_069_072_oPCAN_RADAR_686f657a_Tx_I_SG_Detections_069_072_AL
# define ComXf_Com_SG_Detections_073_076_oRDR_DETECTION_073_076_oPCAN_RADAR_5a640d52_Tx ComXf_Com_SG_Detections_073_076_oRDR_DETECTION_073_076_oPCAN_RADAR_5a640d52_Tx_I_SG_Detections_073_076_AL
# define ComXf_Com_SG_Detections_077_080_oRDR_DETECTION_077_080_oPCAN_RADAR_2ec83134_Tx ComXf_Com_SG_Detections_077_080_oRDR_DETECTION_077_080_oPCAN_RADAR_2ec83134_Tx_I_SG_Detections_077_080_AL
# define ComXf_Com_SG_Detections_081_084_oRDR_DETECTION_081_084_oPCAN_RADAR_0a9e14ed_Tx ComXf_Com_SG_Detections_081_084_oRDR_DETECTION_081_084_oPCAN_RADAR_0a9e14ed_Tx_I_SG_Detections_081_084_AL
# define ComXf_Com_SG_Detections_085_088_oRDR_DETECTION_085_088_oPCAN_RADAR_7b5d20bf_Tx ComXf_Com_SG_Detections_085_088_oRDR_DETECTION_085_088_oPCAN_RADAR_7b5d20bf_Tx_I_SG_Detections_085_088_AL
# define ComXf_Com_SG_Detections_089_092_oRDR_DETECTION_089_092_oPCAN_RADAR_e22704c4_Tx ComXf_Com_SG_Detections_089_092_oRDR_DETECTION_089_092_oPCAN_RADAR_e22704c4_Tx_I_SG_Detections_089_092_AL
# define ComXf_Com_SG_Detections_093_096_oRDR_DETECTION_093_096_oPCAN_RADAR_d02c6cec_Tx ComXf_Com_SG_Detections_093_096_oRDR_DETECTION_093_096_oPCAN_RADAR_d02c6cec_Tx_I_SG_Detections_093_096_AL
# define ComXf_Com_SG_Detections_097_100_oRDR_DETECTION_097_100_oPCAN_RADAR_dcf343f6_Tx ComXf_Com_SG_Detections_097_100_oRDR_DETECTION_097_100_oPCAN_RADAR_dcf343f6_Tx_I_SG_Detections_097_100_AL
# define ComXf_Com_SG_Detections_101_104_oRDR_DETECTION_101_104_oPCAN_RADAR_9de0b719_Tx ComXf_Com_SG_Detections_101_104_oRDR_DETECTION_101_104_oPCAN_RADAR_9de0b719_Tx_I_SG_Detections_101_104_AL
# define ComXf_Com_SG_Detections_105_108_oRDR_DETECTION_105_108_oPCAN_RADAR_ec23834b_Tx ComXf_Com_SG_Detections_105_108_oRDR_DETECTION_105_108_oPCAN_RADAR_ec23834b_Tx_I_SG_Detections_105_108_AL
# define ComXf_Com_SG_Detections_109_112_oRDR_DETECTION_109_112_oPCAN_RADAR_7559a730_Tx ComXf_Com_SG_Detections_109_112_oRDR_DETECTION_109_112_oPCAN_RADAR_7559a730_Tx_I_SG_Detections_109_112_AL
# define ComXf_Com_SG_Detections_113_116_oRDR_DETECTION_113_116_oPCAN_RADAR_4752cf18_Tx ComXf_Com_SG_Detections_113_116_oRDR_DETECTION_113_116_oPCAN_RADAR_4752cf18_Tx_I_SG_Detections_113_116_AL
# define ComXf_Com_SG_Detections_117_120_oRDR_DETECTION_117_120_oPCAN_RADAR_abfe9992_Tx ComXf_Com_SG_Detections_117_120_oRDR_DETECTION_117_120_oPCAN_RADAR_abfe9992_Tx_I_SG_Detections_117_120_AL
# define ComXf_Com_SG_Detections_121_124_oRDR_DETECTION_121_124_oPCAN_RADAR_a895174b_Tx ComXf_Com_SG_Detections_121_124_oRDR_DETECTION_121_124_oPCAN_RADAR_a895174b_Tx_I_SG_Detections_121_124_AL
# define ComXf_Com_SG_Detections_125_128_oRDR_DETECTION_125_128_oPCAN_RADAR_d9562319_Tx ComXf_Com_SG_Detections_125_128_oRDR_DETECTION_125_128_oPCAN_RADAR_d9562319_Tx_I_SG_Detections_125_128_AL
# define ComXf_Com_SG_Detections_129_132_oRDR_DETECTION_129_132_oPCAN_RADAR_402c0762_Tx ComXf_Com_SG_Detections_129_132_oRDR_DETECTION_129_132_oPCAN_RADAR_402c0762_Tx_I_SG_Detections_129_132_AL
# define ComXf_Com_SG_Detections_133_136_oRDR_DETECTION_133_136_oPCAN_RADAR_72276f4a_Tx ComXf_Com_SG_Detections_133_136_oRDR_DETECTION_133_136_oPCAN_RADAR_72276f4a_Tx_I_SG_Detections_133_136_AL
# define ComXf_Com_SG_Detections_137_140_oRDR_DETECTION_137_140_oPCAN_RADAR_e974e064_Tx ComXf_Com_SG_Detections_137_140_oRDR_DETECTION_137_140_oPCAN_RADAR_e974e064_Tx_I_SG_Detections_137_140_AL
# define ComXf_Com_SG_Detections_141_144_oRDR_DETECTION_141_144_oPCAN_RADAR_f70bf7bd_Tx ComXf_Com_SG_Detections_141_144_oRDR_DETECTION_141_144_oPCAN_RADAR_f70bf7bd_Tx_I_SG_Detections_141_144_AL
# define ComXf_Com_SG_Detections_145_148_oRDR_DETECTION_145_148_oPCAN_RADAR_86c8c3ef_Tx ComXf_Com_SG_Detections_145_148_oRDR_DETECTION_145_148_oPCAN_RADAR_86c8c3ef_Tx_I_SG_Detections_145_148_AL
# define ComXf_Com_SG_Detections_149_152_oRDR_DETECTION_149_152_oPCAN_RADAR_1fb2e794_Tx ComXf_Com_SG_Detections_149_152_oRDR_DETECTION_149_152_oPCAN_RADAR_1fb2e794_Tx_I_SG_Detections_149_152_AL
# define ComXf_Com_SG_Detections_153_156_oRDR_DETECTION_153_156_oPCAN_RADAR_2db98fbc_Tx ComXf_Com_SG_Detections_153_156_oRDR_DETECTION_153_156_oPCAN_RADAR_2db98fbc_Tx_I_SG_Detections_153_156_AL
# define ComXf_Com_SG_Detections_157_160_oRDR_DETECTION_157_160_oPCAN_RADAR_c115d936_Tx ComXf_Com_SG_Detections_157_160_oRDR_DETECTION_157_160_oPCAN_RADAR_c115d936_Tx_I_SG_Detections_157_160_AL
# define ComXf_Com_SG_Detections_161_164_oRDR_DETECTION_161_164_oPCAN_RADAR_c27e57ef_Tx ComXf_Com_SG_Detections_161_164_oRDR_DETECTION_161_164_oPCAN_RADAR_c27e57ef_Tx_I_SG_Detections_161_164_AL
# define ComXf_Com_SG_Detections_165_168_oRDR_DETECTION_165_168_oPCAN_RADAR_b3bd63bd_Tx ComXf_Com_SG_Detections_165_168_oRDR_DETECTION_165_168_oPCAN_RADAR_b3bd63bd_Tx_I_SG_Detections_165_168_AL
# define ComXf_Com_SG_Detections_169_172_oRDR_DETECTION_169_172_oPCAN_RADAR_2ac747c6_Tx ComXf_Com_SG_Detections_169_172_oRDR_DETECTION_169_172_oPCAN_RADAR_2ac747c6_Tx_I_SG_Detections_169_172_AL
# define ComXf_Com_SG_Detections_173_176_oRDR_DETECTION_173_176_oPCAN_RADAR_18cc2fee_Tx ComXf_Com_SG_Detections_173_176_oRDR_DETECTION_173_176_oPCAN_RADAR_18cc2fee_Tx_I_SG_Detections_173_176_AL
# define ComXf_Com_SG_Detections_177_180_oRDR_DETECTION_177_180_oPCAN_RADAR_6c601388_Tx ComXf_Com_SG_Detections_177_180_oRDR_DETECTION_177_180_oPCAN_RADAR_6c601388_Tx_I_SG_Detections_177_180_AL
# define ComXf_Com_SG_Detections_181_184_oRDR_DETECTION_181_184_oPCAN_RADAR_48363651_Tx ComXf_Com_SG_Detections_181_184_oRDR_DETECTION_181_184_oPCAN_RADAR_48363651_Tx_I_SG_Detections_181_184_AL
# define ComXf_Com_SG_Detections_185_188_oRDR_DETECTION_185_188_oPCAN_RADAR_39f50203_Tx ComXf_Com_SG_Detections_185_188_oRDR_DETECTION_185_188_oPCAN_RADAR_39f50203_Tx_I_SG_Detections_185_188_AL
# define ComXf_Com_SG_Detections_189_192_oRDR_DETECTION_189_192_oPCAN_RADAR_a08f2678_Tx ComXf_Com_SG_Detections_189_192_oRDR_DETECTION_189_192_oPCAN_RADAR_a08f2678_Tx_I_SG_Detections_189_192_AL
# define ComXf_Com_SG_Detections_193_196_oRDR_DETECTION_193_196_oPCAN_RADAR_92844e50_Tx ComXf_Com_SG_Detections_193_196_oRDR_DETECTION_193_196_oPCAN_RADAR_92844e50_Tx_I_SG_Detections_193_196_AL
# define ComXf_Com_SG_Detections_197_200_oRDR_DETECTION_197_200_oPCAN_RADAR_f6bd2d5e_Tx ComXf_Com_SG_Detections_197_200_oRDR_DETECTION_197_200_oPCAN_RADAR_f6bd2d5e_Tx_I_SG_Detections_197_200_AL
# define ComXf_Com_SG_Detections_201_204_oRDR_DETECTION_201_204_oPCAN_RADAR_5a18d0dd_Tx ComXf_Com_SG_Detections_201_204_oRDR_DETECTION_201_204_oPCAN_RADAR_5a18d0dd_Tx_I_SG_Detections_201_204_AL
# define ComXf_Com_SG_Detections_205_208_oRDR_DETECTION_205_208_oPCAN_RADAR_2bdbe48f_Tx ComXf_Com_SG_Detections_205_208_oRDR_DETECTION_205_208_oPCAN_RADAR_2bdbe48f_Tx_I_SG_Detections_205_208_AL
# define ComXf_Com_SG_Detections_209_212_oRDR_DETECTION_209_212_oPCAN_RADAR_b2a1c0f4_Tx ComXf_Com_SG_Detections_209_212_oRDR_DETECTION_209_212_oPCAN_RADAR_b2a1c0f4_Tx_I_SG_Detections_209_212_AL
# define ComXf_Com_SG_Detections_213_216_oRDR_DETECTION_213_216_oPCAN_RADAR_80aaa8dc_Tx ComXf_Com_SG_Detections_213_216_oRDR_DETECTION_213_216_oPCAN_RADAR_80aaa8dc_Tx_I_SG_Detections_213_216_AL
# define ComXf_Com_SG_Detections_217_220_oRDR_DETECTION_217_220_oPCAN_RADAR_6c06fe56_Tx ComXf_Com_SG_Detections_217_220_oRDR_DETECTION_217_220_oPCAN_RADAR_6c06fe56_Tx_I_SG_Detections_217_220_AL
# define ComXf_Com_SG_Detections_221_224_oRDR_DETECTION_221_224_oPCAN_RADAR_6f6d708f_Tx ComXf_Com_SG_Detections_221_224_oRDR_DETECTION_221_224_oPCAN_RADAR_6f6d708f_Tx_I_SG_Detections_221_224_AL
# define ComXf_Com_SG_Detections_225_228_oRDR_DETECTION_225_228_oPCAN_RADAR_1eae44dd_Tx ComXf_Com_SG_Detections_225_228_oRDR_DETECTION_225_228_oPCAN_RADAR_1eae44dd_Tx_I_SG_Detections_225_228_AL
# define ComXf_Com_SG_Detections_229_232_oRDR_DETECTION_229_232_oPCAN_RADAR_87d460a6_Tx ComXf_Com_SG_Detections_229_232_oRDR_DETECTION_229_232_oPCAN_RADAR_87d460a6_Tx_I_SG_Detections_229_232_AL
# define ComXf_Com_SG_Detections_233_236_oRDR_DETECTION_233_236_oPCAN_RADAR_b5df088e_Tx ComXf_Com_SG_Detections_233_236_oRDR_DETECTION_233_236_oPCAN_RADAR_b5df088e_Tx_I_SG_Detections_233_236_AL
# define ComXf_Com_SG_Detections_237_240_oRDR_DETECTION_237_240_oPCAN_RADAR_2e8c87a0_Tx ComXf_Com_SG_Detections_237_240_oRDR_DETECTION_237_240_oPCAN_RADAR_2e8c87a0_Tx_I_SG_Detections_237_240_AL
# define ComXf_Com_SG_Detections_241_244_oRDR_DETECTION_241_244_oPCAN_RADAR_30f39079_Tx ComXf_Com_SG_Detections_241_244_oRDR_DETECTION_241_244_oPCAN_RADAR_30f39079_Tx_I_SG_Detections_241_244_AL
# define ComXf_Com_SG_Detections_245_248_oRDR_DETECTION_245_248_oPCAN_RADAR_4130a42b_Tx ComXf_Com_SG_Detections_245_248_oRDR_DETECTION_245_248_oPCAN_RADAR_4130a42b_Tx_I_SG_Detections_245_248_AL
# define ComXf_Com_SG_Detections_249_252_oRDR_DETECTION_249_252_oPCAN_RADAR_d84a8050_Tx ComXf_Com_SG_Detections_249_252_oRDR_DETECTION_249_252_oPCAN_RADAR_d84a8050_Tx_I_SG_Detections_249_252_AL
# define ComXf_Com_SG_Detections_253_256_oRDR_DETECTION_253_256_oPCAN_RADAR_ea41e878_Tx ComXf_Com_SG_Detections_253_256_oRDR_DETECTION_253_256_oPCAN_RADAR_ea41e878_Tx_I_SG_Detections_253_256_AL
# define ComXf_Com_SG_Detections_257_260_oRDR_DETECTION_257_260_oPCAN_RADAR_06edbef2_Tx ComXf_Com_SG_Detections_257_260_oRDR_DETECTION_257_260_oPCAN_RADAR_06edbef2_Tx_I_SG_Detections_257_260_AL
# define ComXf_Com_SG_Detections_261_264_oRDR_DETECTION_261_264_oPCAN_RADAR_0586302b_Tx ComXf_Com_SG_Detections_261_264_oRDR_DETECTION_261_264_oPCAN_RADAR_0586302b_Tx_I_SG_Detections_261_264_AL
# define ComXf_Com_SG_Detections_265_268_oRDR_DETECTION_265_268_oPCAN_RADAR_74450479_Tx ComXf_Com_SG_Detections_265_268_oRDR_DETECTION_265_268_oPCAN_RADAR_74450479_Tx_I_SG_Detections_265_268_AL
# define ComXf_Com_SG_Detections_269_272_oRDR_DETECTION_269_272_oPCAN_RADAR_ed3f2002_Tx ComXf_Com_SG_Detections_269_272_oRDR_DETECTION_269_272_oPCAN_RADAR_ed3f2002_Tx_I_SG_Detections_269_272_AL
# define ComXf_Com_SG_Detections_273_276_oRDR_DETECTION_273_276_oPCAN_RADAR_df34482a_Tx ComXf_Com_SG_Detections_273_276_oRDR_DETECTION_273_276_oPCAN_RADAR_df34482a_Tx_I_SG_Detections_273_276_AL
# define ComXf_Com_SG_Detections_277_280_oRDR_DETECTION_277_280_oPCAN_RADAR_ab98744c_Tx ComXf_Com_SG_Detections_277_280_oRDR_DETECTION_277_280_oPCAN_RADAR_ab98744c_Tx_I_SG_Detections_277_280_AL
# define ComXf_Com_SG_Detections_281_284_oRDR_DETECTION_281_284_oPCAN_RADAR_8fce5195_Tx ComXf_Com_SG_Detections_281_284_oRDR_DETECTION_281_284_oPCAN_RADAR_8fce5195_Tx_I_SG_Detections_281_284_AL
# define ComXf_Com_SG_Detections_285_288_oRDR_DETECTION_285_288_oPCAN_RADAR_fe0d65c7_Tx ComXf_Com_SG_Detections_285_288_oRDR_DETECTION_285_288_oPCAN_RADAR_fe0d65c7_Tx_I_SG_Detections_285_288_AL
# define ComXf_Com_SG_Detections_289_292_oRDR_DETECTION_289_292_oPCAN_RADAR_677741bc_Tx ComXf_Com_SG_Detections_289_292_oRDR_DETECTION_289_292_oPCAN_RADAR_677741bc_Tx_I_SG_Detections_289_292_AL
# define ComXf_Com_SG_Detections_293_296_oRDR_DETECTION_293_296_oPCAN_RADAR_557c2994_Tx ComXf_Com_SG_Detections_293_296_oRDR_DETECTION_293_296_oPCAN_RADAR_557c2994_Tx_I_SG_Detections_293_296_AL
# define ComXf_Com_SG_Detections_297_300_oRDR_DETECTION_297_300_oPCAN_RADAR_59a3068e_Tx ComXf_Com_SG_Detections_297_300_oRDR_DETECTION_297_300_oPCAN_RADAR_59a3068e_Tx_I_SG_Detections_297_300_AL
# define ComXf_Com_SG_Detections_301_304_oRDR_DETECTION_301_304_oPCAN_RADAR_18b0f261_Tx ComXf_Com_SG_Detections_301_304_oRDR_DETECTION_301_304_oPCAN_RADAR_18b0f261_Tx_I_SG_Detections_301_304_AL
# define ComXf_Com_SG_Detections_305_308_oRDR_DETECTION_305_308_oPCAN_RADAR_6973c633_Tx ComXf_Com_SG_Detections_305_308_oRDR_DETECTION_305_308_oPCAN_RADAR_6973c633_Tx_I_SG_Detections_305_308_AL
# define ComXf_Com_SG_Detections_309_312_oRDR_DETECTION_309_312_oPCAN_RADAR_f009e248_Tx ComXf_Com_SG_Detections_309_312_oRDR_DETECTION_309_312_oPCAN_RADAR_f009e248_Tx_I_SG_Detections_309_312_AL
# define ComXf_Com_SG_Detections_313_316_oRDR_DETECTION_313_316_oPCAN_RADAR_c2028a60_Tx ComXf_Com_SG_Detections_313_316_oRDR_DETECTION_313_316_oPCAN_RADAR_c2028a60_Tx_I_SG_Detections_313_316_AL
# define ComXf_Com_SG_Detections_317_320_oRDR_DETECTION_317_320_oPCAN_RADAR_2eaedcea_Tx ComXf_Com_SG_Detections_317_320_oRDR_DETECTION_317_320_oPCAN_RADAR_2eaedcea_Tx_I_SG_Detections_317_320_AL
# define ComXf_Com_SG_Detections_321_324_oRDR_DETECTION_321_324_oPCAN_RADAR_2dc55233_Tx ComXf_Com_SG_Detections_321_324_oRDR_DETECTION_321_324_oPCAN_RADAR_2dc55233_Tx_I_SG_Detections_321_324_AL
# define ComXf_Com_SG_Detections_325_328_oRDR_DETECTION_325_328_oPCAN_RADAR_5c066661_Tx ComXf_Com_SG_Detections_325_328_oRDR_DETECTION_325_328_oPCAN_RADAR_5c066661_Tx_I_SG_Detections_325_328_AL
# define ComXf_Com_SG_Detections_329_332_oRDR_DETECTION_329_332_oPCAN_RADAR_c57c421a_Tx ComXf_Com_SG_Detections_329_332_oRDR_DETECTION_329_332_oPCAN_RADAR_c57c421a_Tx_I_SG_Detections_329_332_AL
# define ComXf_Com_SG_Detections_333_336_oRDR_DETECTION_333_336_oPCAN_RADAR_f7772a32_Tx ComXf_Com_SG_Detections_333_336_oRDR_DETECTION_333_336_oPCAN_RADAR_f7772a32_Tx_I_SG_Detections_333_336_AL
# define ComXf_Com_SG_Detections_337_340_oRDR_DETECTION_337_340_oPCAN_RADAR_6c24a51c_Tx ComXf_Com_SG_Detections_337_340_oRDR_DETECTION_337_340_oPCAN_RADAR_6c24a51c_Tx_I_SG_Detections_337_340_AL
# define ComXf_Com_SG_Detections_341_344_oRDR_DETECTION_341_344_oPCAN_RADAR_725bb2c5_Tx ComXf_Com_SG_Detections_341_344_oRDR_DETECTION_341_344_oPCAN_RADAR_725bb2c5_Tx_I_SG_Detections_341_344_AL
# define ComXf_Com_SG_Detections_345_348_oRDR_DETECTION_345_348_oPCAN_RADAR_03988697_Tx ComXf_Com_SG_Detections_345_348_oRDR_DETECTION_345_348_oPCAN_RADAR_03988697_Tx_I_SG_Detections_345_348_AL
# define ComXf_Com_SG_Detections_349_352_oRDR_DETECTION_349_352_oPCAN_RADAR_9ae2a2ec_Tx ComXf_Com_SG_Detections_349_352_oRDR_DETECTION_349_352_oPCAN_RADAR_9ae2a2ec_Tx_I_SG_Detections_349_352_AL
# define ComXf_Com_SG_Detections_353_356_oRDR_DETECTION_353_356_oPCAN_RADAR_a8e9cac4_Tx ComXf_Com_SG_Detections_353_356_oRDR_DETECTION_353_356_oPCAN_RADAR_a8e9cac4_Tx_I_SG_Detections_353_356_AL
# define ComXf_Com_SG_Detections_357_360_oRDR_DETECTION_357_360_oPCAN_RADAR_44459c4e_Tx ComXf_Com_SG_Detections_357_360_oRDR_DETECTION_357_360_oPCAN_RADAR_44459c4e_Tx_I_SG_Detections_357_360_AL
# define ComXf_Com_SG_Detections_361_364_oRDR_DETECTION_361_364_oPCAN_RADAR_472e1297_Tx ComXf_Com_SG_Detections_361_364_oRDR_DETECTION_361_364_oPCAN_RADAR_472e1297_Tx_I_SG_Detections_361_364_AL
# define ComXf_Com_SG_Detections_365_368_oRDR_DETECTION_365_368_oPCAN_RADAR_36ed26c5_Tx ComXf_Com_SG_Detections_365_368_oRDR_DETECTION_365_368_oPCAN_RADAR_36ed26c5_Tx_I_SG_Detections_365_368_AL
# define ComXf_Com_SG_Detections_369_372_oRDR_DETECTION_369_372_oPCAN_RADAR_af9702be_Tx ComXf_Com_SG_Detections_369_372_oRDR_DETECTION_369_372_oPCAN_RADAR_af9702be_Tx_I_SG_Detections_369_372_AL
# define ComXf_Com_SG_Detections_373_376_oRDR_DETECTION_373_376_oPCAN_RADAR_9d9c6a96_Tx ComXf_Com_SG_Detections_373_376_oRDR_DETECTION_373_376_oPCAN_RADAR_9d9c6a96_Tx_I_SG_Detections_373_376_AL
# define ComXf_Com_SG_Detections_377_380_oRDR_DETECTION_377_380_oPCAN_RADAR_e93056f0_Tx ComXf_Com_SG_Detections_377_380_oRDR_DETECTION_377_380_oPCAN_RADAR_e93056f0_Tx_I_SG_Detections_377_380_AL
# define ComXf_Com_SG_Detections_381_384_oRDR_DETECTION_381_384_oPCAN_RADAR_cd667329_Tx ComXf_Com_SG_Detections_381_384_oRDR_DETECTION_381_384_oPCAN_RADAR_cd667329_Tx_I_SG_Detections_381_384_AL
# define ComXf_Com_SG_Detections_385_388_oRDR_DETECTION_385_388_oPCAN_RADAR_bca5477b_Tx ComXf_Com_SG_Detections_385_388_oRDR_DETECTION_385_388_oPCAN_RADAR_bca5477b_Tx_I_SG_Detections_385_388_AL
# define ComXf_Com_SG_Detections_389_392_oRDR_DETECTION_389_392_oPCAN_RADAR_25df6300_Tx ComXf_Com_SG_Detections_389_392_oRDR_DETECTION_389_392_oPCAN_RADAR_25df6300_Tx_I_SG_Detections_389_392_AL
# define ComXf_Com_SG_Detections_393_396_oRDR_DETECTION_393_396_oPCAN_RADAR_17d40b28_Tx ComXf_Com_SG_Detections_393_396_oRDR_DETECTION_393_396_oPCAN_RADAR_17d40b28_Tx_I_SG_Detections_393_396_AL
# define ComXf_Com_SG_Detections_397_400_oRDR_DETECTION_397_400_oPCAN_RADAR_a221f00e_Tx ComXf_Com_SG_Detections_397_400_oRDR_DETECTION_397_400_oPCAN_RADAR_a221f00e_Tx_I_SG_Detections_397_400_AL
# define ComXf_Com_SG_GW_prop_ADAS_BSIS_info_oGW_prop_ADAS_BSIS_info_oPCAN_RADAR_e9da8865_Tx ComXf_Com_SG_GW_prop_ADAS_BSIS_info_oGW_prop_ADAS_BSIS_info_oPCAN_RADAR_e9da8865_Tx_I_SG_GW_prop_ADAS_BSIS_info_ALPCAN
# define ComXf_Com_SG_MOIS_oMOIS_oVCAN_RADAR_f9ec408e_Tx ComXf_Com_SG_MOIS_oMOIS_oVCAN_RADAR_f9ec408e_Tx_I_SG_MOIS_ALVCAN
# define ComXf_Com_SG_RDR_BSD1_Tx_oRDR_BSD1_Tx_oPCAN_RADAR_bd131ac1_Tx ComXf_Com_SG_RDR_BSD1_Tx_oRDR_BSD1_Tx_oPCAN_RADAR_bd131ac1_Tx_I_SG_RDR_BSD1_Tx_ALPCAN
# define ComXf_Com_SG_TrackerHeader_oRDR_OBJ_HEADER_002_oPCAN_RADAR_563ddea3_Tx ComXf_Com_SG_TrackerHeader_oRDR_OBJ_HEADER_002_oPCAN_RADAR_563ddea3_Tx_SG_TrackerHeader_impdt
# define ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject002_oRDR_TRACKER_OBJ_002_oPCAN_RADAR_75f2e109_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject003_oRDR_TRACKER_OBJ_003_oPCAN_RADAR_8ce669ba_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject004_oRDR_TRACKER_OBJ_004_oPCAN_RADAR_0e1ad860_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject005_oRDR_TRACKER_OBJ_005_oPCAN_RADAR_f70e50d3_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject006_oRDR_TRACKER_OBJ_006_oPCAN_RADAR_2742cf47_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject007_oRDR_TRACKER_OBJ_007_oPCAN_RADAR_de5647f4_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject008_oRDR_TRACKER_OBJ_008_oPCAN_RADAR_f9caaab2_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject009_oRDR_TRACKER_OBJ_009_oPCAN_RADAR_00de2201_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject010_oRDR_TRACKER_OBJ_010_oPCAN_RADAR_0e3b0090_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject011_oRDR_TRACKER_OBJ_011_oPCAN_RADAR_f72f8823_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject012_oRDR_TRACKER_OBJ_012_oPCAN_RADAR_276317b7_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject013_oRDR_TRACKER_OBJ_013_oPCAN_RADAR_de779f04_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject014_oRDR_TRACKER_OBJ_014_oPCAN_RADAR_5c8b2ede_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject015_oRDR_TRACKER_OBJ_015_oPCAN_RADAR_a59fa66d_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject016_oRDR_TRACKER_OBJ_016_oPCAN_RADAR_75d339f9_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject017_oRDR_TRACKER_OBJ_017_oPCAN_RADAR_8cc7b14a_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject018_oRDR_TRACKER_OBJ_018_oPCAN_RADAR_ab5b5c0c_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject019_oRDR_TRACKER_OBJ_019_oPCAN_RADAR_524fd4bf_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject020_oRDR_TRACKER_OBJ_020_oPCAN_RADAR_f9891b52_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject021_oRDR_TRACKER_OBJ_021_oPCAN_RADAR_009d93e1_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject022_oRDR_TRACKER_OBJ_022_oPCAN_RADAR_d0d10c75_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject023_oRDR_TRACKER_OBJ_023_oPCAN_RADAR_29c584c6_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject024_oRDR_TRACKER_OBJ_024_oPCAN_RADAR_ab39351c_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject025_oRDR_TRACKER_OBJ_025_oPCAN_RADAR_522dbdaf_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject026_oRDR_TRACKER_OBJ_026_oPCAN_RADAR_8261223b_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject027_oRDR_TRACKER_OBJ_027_oPCAN_RADAR_7b75aa88_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject028_oRDR_TRACKER_OBJ_028_oPCAN_RADAR_5ce947ce_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject029_oRDR_TRACKER_OBJ_029_oPCAN_RADAR_a5fdcf7d_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject030_oRDR_TRACKER_OBJ_030_oPCAN_RADAR_ab18edec_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject031_oRDR_TRACKER_OBJ_031_oPCAN_RADAR_520c655f_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject032_oRDR_TRACKER_OBJ_032_oPCAN_RADAR_8240facb_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject033_oRDR_TRACKER_OBJ_033_oPCAN_RADAR_7b547278_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject034_oRDR_TRACKER_OBJ_034_oPCAN_RADAR_f9a8c3a2_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject035_oRDR_TRACKER_OBJ_035_oPCAN_RADAR_00bc4b11_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject036_oRDR_TRACKER_OBJ_036_oPCAN_RADAR_d0f0d485_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject037_oRDR_TRACKER_OBJ_037_oPCAN_RADAR_29e45c36_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject038_oRDR_TRACKER_OBJ_038_oPCAN_RADAR_0e78b170_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject039_oRDR_TRACKER_OBJ_039_oPCAN_RADAR_f76c39c3_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject040_oRDR_TRACKER_OBJ_040_oPCAN_RADAR_cd9c2a97_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject041_oRDR_TRACKER_OBJ_041_oPCAN_RADAR_3488a224_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject042_oRDR_TRACKER_OBJ_042_oPCAN_RADAR_e4c43db0_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject043_oRDR_TRACKER_OBJ_043_oPCAN_RADAR_1dd0b503_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject044_oRDR_TRACKER_OBJ_044_oPCAN_RADAR_9f2c04d9_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject045_oRDR_TRACKER_OBJ_045_oPCAN_RADAR_66388c6a_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject046_oRDR_TRACKER_OBJ_046_oPCAN_RADAR_b67413fe_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject047_oRDR_TRACKER_OBJ_047_oPCAN_RADAR_4f609b4d_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject048_oRDR_TRACKER_OBJ_048_oPCAN_RADAR_68fc760b_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject049_oRDR_TRACKER_OBJ_049_oPCAN_RADAR_91e8feb8_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject050_oRDR_TRACKER_OBJ_050_oPCAN_RADAR_9f0ddc29_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject051_oRDR_TRACKER_OBJ_051_oPCAN_RADAR_6619549a_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject052_oRDR_TRACKER_OBJ_052_oPCAN_RADAR_b655cb0e_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject053_oRDR_TRACKER_OBJ_053_oPCAN_RADAR_4f4143bd_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject054_oRDR_TRACKER_OBJ_054_oPCAN_RADAR_cdbdf267_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject055_oRDR_TRACKER_OBJ_055_oPCAN_RADAR_34a97ad4_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject056_oRDR_TRACKER_OBJ_056_oPCAN_RADAR_e4e5e540_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject057_oRDR_TRACKER_OBJ_057_oPCAN_RADAR_1df16df3_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject058_oRDR_TRACKER_OBJ_058_oPCAN_RADAR_3a6d80b5_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject059_oRDR_TRACKER_OBJ_059_oPCAN_RADAR_c3790806_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject060_oRDR_TRACKER_OBJ_060_oPCAN_RADAR_68bfc7eb_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject061_oRDR_TRACKER_OBJ_061_oPCAN_RADAR_91ab4f58_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject062_oRDR_TRACKER_OBJ_062_oPCAN_RADAR_41e7d0cc_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject063_oRDR_TRACKER_OBJ_063_oPCAN_RADAR_b8f3587f_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerObject064_oRDR_TRACKER_OBJ_064_oPCAN_RADAR_3a0fe9a5_Tx ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx_SG_TrackerObject001_impdt
# define ComXf_Com_SG_TrackerStatus_oRDR_OBJ_STATUS_003_oPCAN_RADAR_3d577421_Tx ComXf_Com_SG_TrackerStatus_oRDR_OBJ_STATUS_003_oPCAN_RADAR_3d577421_Tx_SG_TrackerStatus_impdt
# define ComXf_Com_SG_prop_ADAS_MOIS_info_oprop_ADAS_MOIS_info_oVCAN_RADAR_cb191e50_Tx ComXf_Com_SG_prop_ADAS_MOIS_info_oprop_ADAS_MOIS_info_oVCAN_RADAR_cb191e50_Tx_I_SG_prop_ADAS_MOIS_info_ALVCAN

/**********************************************************************************************************************
 * Defines for ComXf retransformer APIs
 *********************************************************************************************************************/

# define ComXf_Inv_Com_SG_Fusion_Detections_005_008_oRDR_FUSION_DET_005_008_oPCAN_RADAR_0783a66c_Rx ComXf_Inv_Com_SG_Fusion_Detections_005_008_oRDR_FUSION_DET_005_008_oPCAN_RADAR_0783a66c_Rx_I_SG_Fusion_Detections_005_008_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_009_012_oRDR_FUSION_DET_009_012_oPCAN_RADAR_85b0e384_Rx ComXf_Inv_Com_SG_Fusion_Detections_009_012_oRDR_FUSION_DET_009_012_oPCAN_RADAR_85b0e384_Rx_I_SG_Fusion_Detections_009_012_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_013_016_oRDR_FUSION_DET_013_016_oPCAN_RADAR_713b89f4_Rx ComXf_Inv_Com_SG_Fusion_Detections_013_016_oRDR_FUSION_DET_013_016_oPCAN_RADAR_713b89f4_Rx_I_SG_Fusion_Detections_013_016_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_017_020_oRDR_FUSION_DET_017_020_oPCAN_RADAR_3121649c_Rx ComXf_Inv_Com_SG_Fusion_Detections_017_020_oRDR_FUSION_DET_017_020_oPCAN_RADAR_3121649c_Rx_I_SG_Fusion_Detections_017_020_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_021_024_oRDR_FUSION_DET_021_024_oPCAN_RADAR_f7a0d0a9_Rx ComXf_Inv_Com_SG_Fusion_Detections_021_024_oRDR_FUSION_DET_021_024_oPCAN_RADAR_f7a0d0a9_Rx_I_SG_Fusion_Detections_021_024_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_025_028_oRDR_FUSION_DET_025_028_oPCAN_RADAR_ba5bfb5a_Rx ComXf_Inv_Com_SG_Fusion_Detections_025_028_oRDR_FUSION_DET_025_028_oPCAN_RADAR_ba5bfb5a_Rx_I_SG_Fusion_Detections_025_028_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_029_032_oRDR_FUSION_DET_029_032_oPCAN_RADAR_3868beb2_Rx ComXf_Inv_Com_SG_Fusion_Detections_029_032_oRDR_FUSION_DET_029_032_oPCAN_RADAR_3868beb2_Rx_I_SG_Fusion_Detections_029_032_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_033_036_oRDR_FUSION_DET_033_036_oPCAN_RADAR_cce3d4c2_Rx ComXf_Inv_Com_SG_Fusion_Detections_033_036_oRDR_FUSION_DET_033_036_oPCAN_RADAR_cce3d4c2_Rx_I_SG_Fusion_Detections_033_036_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_037_040_oRDR_FUSION_DET_037_040_oPCAN_RADAR_cee54bfa_Rx ComXf_Inv_Com_SG_Fusion_Detections_037_040_oRDR_FUSION_DET_037_040_oPCAN_RADAR_cee54bfa_Rx_I_SG_Fusion_Detections_037_040_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_041_044_oRDR_FUSION_DET_041_044_oPCAN_RADAR_eab931b2_Rx ComXf_Inv_Com_SG_Fusion_Detections_041_044_oRDR_FUSION_DET_041_044_oPCAN_RADAR_eab931b2_Rx_I_SG_Fusion_Detections_041_044_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_045_048_oRDR_FUSION_DET_045_048_oPCAN_RADAR_a7421a41_Rx ComXf_Inv_Com_SG_Fusion_Detections_045_048_oRDR_FUSION_DET_045_048_oPCAN_RADAR_a7421a41_Rx_I_SG_Fusion_Detections_045_048_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_049_052_oRDR_FUSION_DET_049_052_oPCAN_RADAR_25715fa9_Rx ComXf_Inv_Com_SG_Fusion_Detections_049_052_oRDR_FUSION_DET_049_052_oPCAN_RADAR_25715fa9_Rx_I_SG_Fusion_Detections_049_052_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_053_056_oRDR_FUSION_DET_053_056_oPCAN_RADAR_d1fa35d9_Rx ComXf_Inv_Com_SG_Fusion_Detections_053_056_oRDR_FUSION_DET_053_056_oPCAN_RADAR_d1fa35d9_Rx_I_SG_Fusion_Detections_053_056_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_057_060_oRDR_FUSION_DET_057_060_oPCAN_RADAR_91e0d8b1_Rx ComXf_Inv_Com_SG_Fusion_Detections_057_060_oRDR_FUSION_DET_057_060_oPCAN_RADAR_91e0d8b1_Rx_I_SG_Fusion_Detections_057_060_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_061_064_oRDR_FUSION_DET_061_064_oPCAN_RADAR_57616c84_Rx ComXf_Inv_Com_SG_Fusion_Detections_061_064_oRDR_FUSION_DET_061_064_oPCAN_RADAR_57616c84_Rx_I_SG_Fusion_Detections_061_064_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_065_068_oRDR_FUSION_DET_065_068_oPCAN_RADAR_1a9a4777_Rx ComXf_Inv_Com_SG_Fusion_Detections_065_068_oRDR_FUSION_DET_065_068_oPCAN_RADAR_1a9a4777_Rx_I_SG_Fusion_Detections_065_068_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_069_072_oRDR_FUSION_DET_069_072_oPCAN_RADAR_98a9029f_Rx ComXf_Inv_Com_SG_Fusion_Detections_069_072_oRDR_FUSION_DET_069_072_oPCAN_RADAR_98a9029f_Rx_I_SG_Fusion_Detections_069_072_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_073_076_oRDR_FUSION_DET_073_076_oPCAN_RADAR_6c2268ef_Rx ComXf_Inv_Com_SG_Fusion_Detections_073_076_oRDR_FUSION_DET_073_076_oPCAN_RADAR_6c2268ef_Rx_I_SG_Fusion_Detections_073_076_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_077_080_oRDR_FUSION_DET_077_080_oPCAN_RADAR_ea1c1377_Rx ComXf_Inv_Com_SG_Fusion_Detections_077_080_oRDR_FUSION_DET_077_080_oPCAN_RADAR_ea1c1377_Rx_I_SG_Fusion_Detections_077_080_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_081_084_oRDR_FUSION_DET_081_084_oPCAN_RADAR_d08af384_Rx ComXf_Inv_Com_SG_Fusion_Detections_081_084_oRDR_FUSION_DET_081_084_oPCAN_RADAR_d08af384_Rx_I_SG_Fusion_Detections_081_084_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_085_088_oRDR_FUSION_DET_085_088_oPCAN_RADAR_9d71d877_Rx ComXf_Inv_Com_SG_Fusion_Detections_085_088_oRDR_FUSION_DET_085_088_oPCAN_RADAR_9d71d877_Rx_I_SG_Fusion_Detections_085_088_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_089_092_oRDR_FUSION_DET_089_092_oPCAN_RADAR_1f429d9f_Rx ComXf_Inv_Com_SG_Fusion_Detections_089_092_oRDR_FUSION_DET_089_092_oPCAN_RADAR_1f429d9f_Rx_I_SG_Fusion_Detections_089_092_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_093_096_oRDR_FUSION_DET_093_096_oPCAN_RADAR_ebc9f7ef_Rx ComXf_Inv_Com_SG_Fusion_Detections_093_096_oRDR_FUSION_DET_093_096_oPCAN_RADAR_ebc9f7ef_Rx_I_SG_Fusion_Detections_093_096_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_097_100_oRDR_FUSION_DET_097_100_oPCAN_RADAR_f997174e_Rx ComXf_Inv_Com_SG_Fusion_Detections_097_100_oRDR_FUSION_DET_097_100_oPCAN_RADAR_f997174e_Rx_I_SG_Fusion_Detections_097_100_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_101_104_oRDR_FUSION_DET_101_104_oPCAN_RADAR_2dfb2b7d_Rx ComXf_Inv_Com_SG_Fusion_Detections_101_104_oRDR_FUSION_DET_101_104_oPCAN_RADAR_2dfb2b7d_Rx_I_SG_Fusion_Detections_101_104_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_105_108_oRDR_FUSION_DET_105_108_oPCAN_RADAR_6000008e_Rx ComXf_Inv_Com_SG_Fusion_Detections_105_108_oRDR_FUSION_DET_105_108_oPCAN_RADAR_6000008e_Rx_I_SG_Fusion_Detections_105_108_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_109_112_oRDR_FUSION_DET_109_112_oPCAN_RADAR_e2334566_Rx ComXf_Inv_Com_SG_Fusion_Detections_109_112_oRDR_FUSION_DET_109_112_oPCAN_RADAR_e2334566_Rx_I_SG_Fusion_Detections_109_112_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_113_116_oRDR_FUSION_DET_113_116_oPCAN_RADAR_16b82f16_Rx ComXf_Inv_Com_SG_Fusion_Detections_113_116_oRDR_FUSION_DET_113_116_oPCAN_RADAR_16b82f16_Rx_I_SG_Fusion_Detections_113_116_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_117_120_oRDR_FUSION_DET_117_120_oPCAN_RADAR_56a2c27e_Rx ComXf_Inv_Com_SG_Fusion_Detections_117_120_oRDR_FUSION_DET_117_120_oPCAN_RADAR_56a2c27e_Rx_I_SG_Fusion_Detections_117_120_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_121_124_oRDR_FUSION_DET_121_124_oPCAN_RADAR_9023764b_Rx ComXf_Inv_Com_SG_Fusion_Detections_121_124_oRDR_FUSION_DET_121_124_oPCAN_RADAR_9023764b_Rx_I_SG_Fusion_Detections_121_124_AL
# define ComXf_Inv_Com_SG_Fusion_Detections_125_128_oRDR_FUSION_DET_125_128_oPCAN_RADAR_ddd85db8_Rx ComXf_Inv_Com_SG_Fusion_Detections_125_128_oRDR_FUSION_DET_125_128_oPCAN_RADAR_ddd85db8_Rx_I_SG_Fusion_Detections_125_128_AL
# define ComXf_Inv_Com_SG_VehicleStatus_oSYS_VEHICLE_STATUS_oPCAN_RADAR_0411a809_Rx ComXf_Inv_Com_SG_VehicleStatus_oSYS_VEHICLE_STATUS_oPCAN_RADAR_0411a809_Rx_I_SG_VehicleStatus_AL

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

typedef uint8 ComXf_ConfigType;
FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config);
FUNC(void, COMXF_CODE) ComXf_DeInit(void);

#endif /* COMXF_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_0786:  MISRA rule: Rule5.5
     Reason:       Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:         No functional risk.
     Prevention:   Not required.

*/
