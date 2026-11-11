#ifndef AF_COMMON_DATA_H
#define AF_COMMON_DATA_H
/*===========================================================================*\
* FILE: af_common_data.h
*===========================================================================
* Copyright 2026 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*       Provide helper layer to define AF Detection structure and include
*       necessary stream header files.
*
* ABBREVIATIONS:
*   List of abbreviations used, or reference(s) to external document(s)
*
* TRACEABILITY INFO:
*   Design Document(s):
*
*   Requirements Document(s):
*
*   Applicable Standards (in order of precedence: highest first):
*     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
*
* DEVIATIONS FROM STANDARDS:
*   None.
*
\*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "detection_stream.h"
#include "down_selection_stream.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*
 * These macros check that both detection and down-selection structures have
 * the same size. Unfortunately, they won't catch every type of problem that
 * can occur -- if a new field is added and it replaces some padding, then the
 * structure size won't change.
 */
#define DET_SIZE_CHECK_ASSERT()                                                                                                   \
   typedef char __DET_SIZE_CHECK_ASSERT__[(sizeof(AF_Detection_T) == sizeof(AF_Str_Detection_T)) ? 1 : -1]
#define DS_DET_SIZE_CHECK_ASSERT()                                                                                                \
   typedef char __DS_DET_SIZE_CHECK_ASSERT__[(sizeof(AF_Detection_T) == sizeof(AF_DS_Str_Detection_T)) ? 1 : -1]
#define DET_LIST_PROPERTY_SIZE_CHECK_ASSERT()                                                                                     \
   typedef char                                                                                                                   \
      __DS_DET_SIZE_CHECK_ASSERT__[(sizeof(AF_Str_Det_List_Property_T) == sizeof(AF_DS_Str_Det_List_Property_T)) ? 1 : -1]
/*
 * These macros check that both detection and down-selection structures have
 * matching offsets for a given field. Unfortunately, they won't catch every
 * type of problem that can occur -- if the type of the last field is changed
 * or if a type is changed and padding results in the next field being
 * unmoved, then this check won't notice the difference.
 */
#define DET_FIELD_CHECK_ASSERT(field)                                                                                             \
   typedef char                                                                                                                   \
      __DET_FIELD_CHECK_ASSERT_##field##__[(offsetof(AF_Detection_T, field) == offsetof(AF_Str_Detection_T, field)) ? 1 : -1]
#define DS_DET_FIELD_CHECK_ASSERT(field)                                                                                          \
   typedef char                                                                                                                   \
      __DET_FIELD_CHECK_ASSERT_##field##__[(offsetof(AF_Detection_T, field) == offsetof(AF_DS_Str_Detection_T, field)) ? 1 : -1]
#define DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(field)                                                                               \
   typedef char __PROPERTY_FIELD_CHECK_ASSERT_##field##__                                                                         \
      [(offsetof(AF_Str_Det_List_Property_T, field) == offsetof(AF_DS_Str_Det_List_Property_T, field)) ? 1 : -1]

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*
 * Structure representing a single AF output detection
 * This structure is used internally in the AFBB and should map onto both the
 * detection stream and down selection stream output structures.
 * If you modify this structure you will need to update detection_stream.h,
 * down_selection_stream.h and the assertion checks below.
 */
typedef struct AF_Detection_Tag
{
   float32_t ran;
   float32_t vel;
   float32_t pow;
   float32_t snr;
   float32_t theta;
   float32_t phi;
   float32_t rcs;
   float32_t spec_res;
   int16_t rdd_idx;
   int8_t az_conf;
   int8_t el_conf;
   int8_t f_single_target;
   int8_t f_superres_target;
   int8_t f_bistatic;
   uint8_t reserved1;
} AF_Detection_T;
/*
 * If you get a compiler error for these macros, then you need to update
 * detection_stream.h to match the AF_Detection_T above
 */
DET_SIZE_CHECK_ASSERT();
DET_FIELD_CHECK_ASSERT(ran);
DET_FIELD_CHECK_ASSERT(vel);
DET_FIELD_CHECK_ASSERT(pow);
DET_FIELD_CHECK_ASSERT(snr);
DET_FIELD_CHECK_ASSERT(theta);
DET_FIELD_CHECK_ASSERT(phi);
DET_FIELD_CHECK_ASSERT(rcs);
DET_FIELD_CHECK_ASSERT(spec_res);
DET_FIELD_CHECK_ASSERT(rdd_idx);
DET_FIELD_CHECK_ASSERT(az_conf);
DET_FIELD_CHECK_ASSERT(el_conf);
DET_FIELD_CHECK_ASSERT(f_single_target);
DET_FIELD_CHECK_ASSERT(f_superres_target);
DET_FIELD_CHECK_ASSERT(f_bistatic);
DET_FIELD_CHECK_ASSERT(reserved1);
/*
 * If you get a compiler error for these macros, then you need to update
 * down_selection_stream.h to match the AF_Detection_T above
 */
DS_DET_SIZE_CHECK_ASSERT();
DS_DET_FIELD_CHECK_ASSERT(ran);
DS_DET_FIELD_CHECK_ASSERT(vel);
DS_DET_FIELD_CHECK_ASSERT(pow);
DS_DET_FIELD_CHECK_ASSERT(snr);
DS_DET_FIELD_CHECK_ASSERT(theta);
DS_DET_FIELD_CHECK_ASSERT(phi);
DS_DET_FIELD_CHECK_ASSERT(rcs);
DS_DET_FIELD_CHECK_ASSERT(spec_res);
DS_DET_FIELD_CHECK_ASSERT(rdd_idx);
DS_DET_FIELD_CHECK_ASSERT(az_conf);
DS_DET_FIELD_CHECK_ASSERT(el_conf);
DS_DET_FIELD_CHECK_ASSERT(f_single_target);
DS_DET_FIELD_CHECK_ASSERT(f_superres_target);
DS_DET_FIELD_CHECK_ASSERT(f_bistatic);
DS_DET_FIELD_CHECK_ASSERT(reserved1);

/*
 * If you get a compiler error for these macros, then you need to update
 * AF_DS_Str_Det_List_Property_T to match AF_Str_Det_List_Property_T
 */
DET_LIST_PROPERTY_SIZE_CHECK_ASSERT();
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(detection_timestamp_ns);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(detection_timestamp_sec);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(lookindex);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(scanindex);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(look_type);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(range_coverage);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(doppler_coverage);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(num_fp_detections);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(num_sp_detections);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(slope_correction_status);
DET_LIST_PROPERTY_FIELD_CHECK_ASSERT(timestamp_status);

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

#endif /* AF_COMMON_DATA_H */
