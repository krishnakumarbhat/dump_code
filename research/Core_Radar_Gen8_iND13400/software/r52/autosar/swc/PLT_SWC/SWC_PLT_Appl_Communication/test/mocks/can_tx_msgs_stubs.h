#ifndef CAN_TX_MSGS_STUBS_H_
#define CAN_TX_MSGS_STUBS_H_

/*===========================================================================*/
/**
 * @file can_tx_msgs_stubs.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the can_tx_msgs.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
// #include "Dio.h"
#include "Fault_Lib_Plt.h"
#include "Rte_Type.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "StbM.h"
#include "calibration_cfg.h"
#include "fff.h"
#include "ipc_mss.h"
#include "reuse.h"
#include "versions.h"

   /*===========================================================================*
    * FAKE VALUE FUNCTIONS for can_tx_msgs.c
    *===========================================================================*/

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064,
                           P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));

   /* Radar header, status, alignment, capability, tracker header/status */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_AL_Vdp_SG_RadarHeader_AL,
                           P2CONST(I_SG_RadarHeader_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_AL_Vdp_SG_RadarStatus1_AL,
                           P2CONST(I_SG_RadarStatus1_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL,
                           P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL,
                           P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL,
                           P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL,
                           P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader,
                           P2CONST(SG_TrackerHeader_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus,
                           P2CONST(SG_TrackerStatus_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));

   /* Detections 001-400 (100 frames x 4 detections each) */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL,
                           P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL,
                           P2CONST(I_SG_Detections_005_008_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL,
                           P2CONST(I_SG_Detections_009_012_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL,
                           P2CONST(I_SG_Detections_013_016_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL,
                           P2CONST(I_SG_Detections_017_020_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL,
                           P2CONST(I_SG_Detections_021_024_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL,
                           P2CONST(I_SG_Detections_025_028_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL,
                           P2CONST(I_SG_Detections_029_032_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL,
                           P2CONST(I_SG_Detections_033_036_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL,
                           P2CONST(I_SG_Detections_037_040_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL,
                           P2CONST(I_SG_Detections_041_044_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL,
                           P2CONST(I_SG_Detections_045_048_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL,
                           P2CONST(I_SG_Detections_049_052_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL,
                           P2CONST(I_SG_Detections_053_056_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL,
                           P2CONST(I_SG_Detections_057_060_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL,
                           P2CONST(I_SG_Detections_061_064_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL,
                           P2CONST(I_SG_Detections_065_068_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL,
                           P2CONST(I_SG_Detections_069_072_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL,
                           P2CONST(I_SG_Detections_073_076_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL,
                           P2CONST(I_SG_Detections_077_080_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL,
                           P2CONST(I_SG_Detections_081_084_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL,
                           P2CONST(I_SG_Detections_085_088_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL,
                           P2CONST(I_SG_Detections_089_092_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL,
                           P2CONST(I_SG_Detections_093_096_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL,
                           P2CONST(I_SG_Detections_097_100_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL,
                           P2CONST(I_SG_Detections_101_104_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL,
                           P2CONST(I_SG_Detections_105_108_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL,
                           P2CONST(I_SG_Detections_109_112_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL,
                           P2CONST(I_SG_Detections_113_116_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL,
                           P2CONST(I_SG_Detections_117_120_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL,
                           P2CONST(I_SG_Detections_121_124_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL,
                           P2CONST(I_SG_Detections_125_128_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL,
                           P2CONST(I_SG_Detections_129_132_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL,
                           P2CONST(I_SG_Detections_133_136_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL,
                           P2CONST(I_SG_Detections_137_140_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL,
                           P2CONST(I_SG_Detections_141_144_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL,
                           P2CONST(I_SG_Detections_145_148_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL,
                           P2CONST(I_SG_Detections_149_152_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL,
                           P2CONST(I_SG_Detections_153_156_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL,
                           P2CONST(I_SG_Detections_157_160_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL,
                           P2CONST(I_SG_Detections_161_164_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL,
                           P2CONST(I_SG_Detections_165_168_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL,
                           P2CONST(I_SG_Detections_169_172_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL,
                           P2CONST(I_SG_Detections_173_176_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL,
                           P2CONST(I_SG_Detections_177_180_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL,
                           P2CONST(I_SG_Detections_181_184_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL,
                           P2CONST(I_SG_Detections_185_188_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL,
                           P2CONST(I_SG_Detections_189_192_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL,
                           P2CONST(I_SG_Detections_193_196_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL,
                           P2CONST(I_SG_Detections_197_200_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL,
                           P2CONST(I_SG_Detections_201_204_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL,
                           P2CONST(I_SG_Detections_205_208_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL,
                           P2CONST(I_SG_Detections_209_212_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL,
                           P2CONST(I_SG_Detections_213_216_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL,
                           P2CONST(I_SG_Detections_217_220_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL,
                           P2CONST(I_SG_Detections_221_224_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL,
                           P2CONST(I_SG_Detections_225_228_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL,
                           P2CONST(I_SG_Detections_229_232_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL,
                           P2CONST(I_SG_Detections_233_236_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL,
                           P2CONST(I_SG_Detections_237_240_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL,
                           P2CONST(I_SG_Detections_241_244_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL,
                           P2CONST(I_SG_Detections_245_248_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL,
                           P2CONST(I_SG_Detections_249_252_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL,
                           P2CONST(I_SG_Detections_253_256_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL,
                           P2CONST(I_SG_Detections_257_260_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL,
                           P2CONST(I_SG_Detections_261_264_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL,
                           P2CONST(I_SG_Detections_265_268_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL,
                           P2CONST(I_SG_Detections_269_272_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL,
                           P2CONST(I_SG_Detections_273_276_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL,
                           P2CONST(I_SG_Detections_277_280_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL,
                           P2CONST(I_SG_Detections_281_284_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL,
                           P2CONST(I_SG_Detections_285_288_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL,
                           P2CONST(I_SG_Detections_289_292_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL,
                           P2CONST(I_SG_Detections_293_296_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL,
                           P2CONST(I_SG_Detections_297_300_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL,
                           P2CONST(I_SG_Detections_301_304_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL,
                           P2CONST(I_SG_Detections_305_308_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL,
                           P2CONST(I_SG_Detections_309_312_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL,
                           P2CONST(I_SG_Detections_313_316_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL,
                           P2CONST(I_SG_Detections_317_320_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL,
                           P2CONST(I_SG_Detections_321_324_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL,
                           P2CONST(I_SG_Detections_325_328_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL,
                           P2CONST(I_SG_Detections_329_332_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL,
                           P2CONST(I_SG_Detections_333_336_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL,
                           P2CONST(I_SG_Detections_337_340_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL,
                           P2CONST(I_SG_Detections_341_344_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL,
                           P2CONST(I_SG_Detections_345_348_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL,
                           P2CONST(I_SG_Detections_349_352_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL,
                           P2CONST(I_SG_Detections_353_356_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL,
                           P2CONST(I_SG_Detections_357_360_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL,
                           P2CONST(I_SG_Detections_361_364_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL,
                           P2CONST(I_SG_Detections_365_368_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL,
                           P2CONST(I_SG_Detections_369_372_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL,
                           P2CONST(I_SG_Detections_373_376_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL,
                           P2CONST(I_SG_Detections_377_380_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL,
                           P2CONST(I_SG_Detections_381_384_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL,
                           P2CONST(I_SG_Detections_385_388_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL,
                           P2CONST(I_SG_Detections_389_392_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL,
                           P2CONST(I_SG_Detections_393_396_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL,
                           P2CONST(I_SG_Detections_397_400_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN,
                           P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN,
                           P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA));

   /* Rte_Read */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_Logging_Rp_CPU_Load_De_CPU_Load,
                           P2VAR(Dt_CPU_Load, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR));

   /* IPC buffer getters */
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);

   /* Miscellaneous getters */
   DECLARE_FAKE_VALUE_FUNC(float32_t, FXP2FLP_Fnc, int32_t, int32_t, bool);
   DECLARE_FAKE_VALUE_FUNC(const Application_Version_T *, Get_Application_Version);
   DECLARE_FAKE_VALUE_FUNC(const Bootloader_Version_T *, Get_Bootloader_Version);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
   DECLARE_FAKE_VALUE_FUNC(volatile float32_t *, Get_XCP_MCU_Temperature_Data);
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_MMIC_Error_Reinit_Count);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_XCP_Over_ETH_Status);
   DECLARE_FAKE_VALUE_FUNC(Dt_Alignment_Handler *, Get_AlignmentHandler);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentAuto *, Get_AlignmentAuto);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentStatic *, Get_AlignmentStatic);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentService *, Get_AlignmentService);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentShortTrack *, Get_AlignmentShortTrack);

   Platform_fault_T *Get_Platform_Active_Fault_Table(void);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */

#endif /* CAN_TX_MSGS_STUBS_H_ */
