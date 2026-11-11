#ifndef TOI_CONFIG_H
#define TOI_CONFIG_H

/*===========================================================================*\
 * FILE: TOI_Config.h
 *===========================================================================
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitve Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *   This header defines the configuration constants, macros, and type mappings
 *   for the TOI Character Quality Determination module. It provides range-check
 *   thresholds, fixed-point scaling parameters, SNR conversion factors, and
 *   conditional compilation macros that abstract the TOI data types and stream
 *   structures for both downselection-enabled and standard detection paths.
 *
 * @section ABBR ABBREVIATIONS:
 *   - Open below WI in document
 *   - "https://polarionprod1.aptiv.com/polarion/redirect/project/CORE_RADAR_GEN5/workitem?id=WI-280990"
 *
 *   - Requirements Document(s):
 *     -
 *"https://polarionprod1.aptiv.com/polarion/#/project/CORE_RADAR_GEN5/wiki/511-SRS_Radar/CMP_SRS_CoreRadar_Detection_Management"
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *   - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *    - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 *===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "blockage_types.h"
#include "radar_sw_config.h"

#if DOWNSELECTION_ENABLE
   #include "down_selection_stream.h"
   #include "toi_ds_stream.h"
#else
   #include "detection_stream.h"
   #include "toi_stream.h"
#endif

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#undef PI
#define PI                      (3.14159265358979323846F)
#define SNR_LINEAR_FACTOR       (0.16609640475F) // 3.321928095e+00F * 0.05F
#define NO_FRACTIONAL_BITS      (0U)
#define FIXED_POINT_7_FRAC_BITS (7U)
#define SNR_FRAC_BITS           (2U)

/* Keeping large dummy ranges to get range check fault as CODED_FALSE till actual values are available */
#define RANGE_MIN_R         (-1000.5F)
#define RANGE_MAX_R         (1000.000000F)
#define RANGE_MIN_R_DOT     (-1000.200000F)
#define RANGE_MAX_R_DOT     (1000.100000F)
#define RANGE_MIN_ELEVATION ((-1000.100000F * PI) / 180.0F)
#define RANGE_MAX_ELEVATION ((1000.100000F * PI) / 180.0F)
#define RANGE_MIN_ANG       ((-1000.000000F * PI) / 180.0F)
#define RANGE_MAX_ANG       ((1000.000000F * PI) / 180.0F)

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#if (DOWNSELECTION_ENABLE)
   #define TOI_OUTPUT_DATA_T       TOI_DS_Op_Data_T
   #define TOI_STREAM_T            TOI_DS_Stream_T
   #define TOI_RADAR_DATA_STATUS_T TOI_Radar_Data_Status_Payload_DS_T
   #define AF_DET_TYPE             AF_DS_Det_T
#else
   #define TOI_OUTPUT_DATA_T       TOI_Op_Data_T
   #define TOI_STREAM_T            TOI_Stream_T
   #define TOI_RADAR_DATA_STATUS_T TOI_Radar_Data_Status_Payload_T
   #define AF_DET_TYPE             AF_Det_T
#endif

#define AF_DET_GET_FIELD(VAR_PTR, FIELD, INDEX) (VAR_PTR[INDEX].FIELD)

/*===========================================================================*\
 * Exported test object definitions
\*===========================================================================*/
/* Uncomment below DETECTION_TEST_STUB_ON macro for testing detection range check */
/*#define DETECTION_TEST_STUB_ON*/
#ifdef DETECTION_TEST_STUB_ON
extern volatile uint8_t Test_Stub_Detection;
/*Initialize to value within range*/
extern volatile float32_t Detection_R;
extern volatile float32_t Detection_Rdot;
extern volatile float32_t Detection_Elevation;
extern volatile float32_t Detection_Ang;
#endif

#endif /* TOI_CONFIG_H */
