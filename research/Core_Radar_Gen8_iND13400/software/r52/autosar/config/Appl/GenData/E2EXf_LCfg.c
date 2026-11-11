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
 *             File:  E2EXf_LCfg.c
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR E2EXf Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  MICROSAR E2EXf implementation file for link-time variant
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "E2EXf_LCfg.h"

#if !defined (E2EXF_LOCAL)
# define E2EXF_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_ModuleInitialized;

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08 =
{
  TRUE /* InPlace */ ,
  TRUE /* ExecuteDespiteDataUnavailability */ ,
  TRUE /* ProfileBehavior */ ,
  FALSE /* DisableEndToEndCheck */ ,
  0U /* HeaderLength */ ,
  0U /* UpperHeaderBitsToShift */
};
/* PRQA L:L1 */


#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1181U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  917U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  653U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  389U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  389U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1445U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1725U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1973U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1182U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  918U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  654U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  390U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  390U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1446U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1726U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1974U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1183U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  919U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  655U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  391U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  391U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1447U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1727U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1975U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1176U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  912U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  648U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  384U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  384U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1440U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1720U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1968U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1180U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  916U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  652U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  388U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  388U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1444U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1724U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1972U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1179U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  915U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  651U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  387U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  387U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1443U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1723U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1971U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  389U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  653U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  917U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1181U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1445U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1709U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1973U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  2237U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  390U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  654U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  918U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1182U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1446U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1710U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  1974U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08 =
{
  0U /* Offset */ ,
  328U /* DataLength */ ,
  2238U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  391U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  655U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  919U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1183U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1447U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1711U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  1975U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08 =
{
  0U /* Offset */ ,
  216U /* DataLength */ ,
  2239U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  384U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  648U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  912U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1176U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1440U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1704U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  1968U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08 =
{
  0U /* Offset */ ,
  512U /* DataLength */ ,
  2232U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  387U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  651U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  915U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1179U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1443U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1707U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  1971U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08 =
{
  0U /* Offset */ ,
  504U /* DataLength */ ,
  2235U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  388U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  652U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  916U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1180U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1444U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1708U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  1972U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08 =
{
  0U /* Offset */ ,
  400U /* DataLength */ ,
  2236U /* DataID */ ,
  3U /* MaxDeltaCounter */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08 =
{
  2U /* WindowSizeValid */ ,
  1U /* MinOkStateInit */ ,
  1U /* MaxErrorStateInit */ ,
  1U /* MinOkStateValid */ ,
  1U /* MaxErrorStateValid */ ,
  1U /* MinOkStateInvalid */ ,
  1U /* MaxErrorStateInvalid */ ,
  2U /* WindowSizeInit */ ,
  2U /* WindowSizeInvalid */ ,
  FALSE /* ClearToInvalid */ ,
  FALSE /* TransitToInvalidExtended */
};
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08[2];
/* PRQA L:L1 */

/* PRQA S 1514, 1533 L1 */ /* MD_E2EXf_1514, MD_E2EXf_1533 */
VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08;
/* PRQA L:L1 */

#define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define E2EXF_START_SEC_CODE_ASIL_D
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

E2EXF_LOCAL FUNC(void, E2EXF_CODE) E2EXf_MemClr(P2VAR(void, AUTOMATIC, E2EXF_VAR_CLEARED) ptr, uint32_least num);

/**********************************************************************************************************************
 * E2EXf_InitMemory
 *********************************************************************************************************************/
FUNC(void, E2EXF_CODE) E2EXf_InitMemory(void)
{
  E2EXf_ModuleInitialized = E2EXF_UNINIT;

  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, sizeof(E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, 2);
  E2EXf_MemClr(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, sizeof(E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07));
  E2EXf_MemClr(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08, sizeof(E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08));
}

#ifndef E2EXf_ENABLE_CUSTOM_MEMCLR
E2EXF_LOCAL FUNC(void, E2EXF_CODE) E2EXf_MemClr(P2VAR(void, AUTOMATIC, E2EXF_VAR_CLEARED) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, E2EXF_VAR_CLEARED) dst = (P2VAR(uint8, AUTOMATIC, E2EXF_VAR_CLEARED))ptr; /* PRQA S 0316 */ /* MD_E2EXf_0316 */
  uint32_least i;
  for (i = 0; i < num; i++) /* FETA_RTE_MEMCLR */
  {
    dst[i] = 0;
  }
}
#endif

/***********************************************************************************************************************
 *  E2EXf_Init_Calls()
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(void, E2EXF_CODE) E2EXf_Init_Calls(void)
{
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07);
  (void)E2E_P05CheckInit(&E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08);
  E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08.ProfileStatusWindow = E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08;
  (void)E2E_SMCheckInit(&E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07);
  (void)E2E_P05ProtectInit(&E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08);
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define E2EXF_STOP_SEC_CODE_ASIL_D
#include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_E2EXf_0316:  MISRA rule: Dir1.1
     Reason:       Pointer cast to uint8* because a direct byte access is necessary.
     Risk:         No functional risk. Only a cast to uint8* is performed.
     Prevention:   Not required.

   MD_E2EXf_1514:  MISRA rule: Rule8.9
     Reason:       Because of external definition, misra does not see the call.
     Risk:         No functional risk. There is no side effect.
     Prevention:   Not required.

   MD_E2EXf_1533:  MISRA rule: Rule8.9
     Reason:       Object is referenced by more than one function in different configurations.
     Risk:         No functional risk.
     Prevention:   Not required.

*/

/**********************************************************************************************************************
  Finite Execution Time Analysis justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

  \ID FETA_RTE_MEMCLR
  \DESCRIPTION    Iterations to initialize memory with zero.
  \COUNTERMEASURE \S SMI-322

COV_JUSTIFICATION_END */
