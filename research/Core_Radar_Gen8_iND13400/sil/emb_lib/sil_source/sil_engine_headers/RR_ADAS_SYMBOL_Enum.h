#ifndef _RR_ADAS_SYMBOL_ENUM_H_
#define _RR_ADAS_SYMBOL_ENUM_H_
#define MAX_RADAR_LOGGING_SOURCE (40)
// Use this enum while generating Symbol Data
// Update the enum for the new data
#pragma pack(push, 2)

enum class SiL_Logging_Data_Source_T : int
{
   DETECTION_STREAM                  = 0,
   HEADER_STREAM                     = 1,
   STATUS_STREAM                     = 2,
   RDD_STREAM                        = 3,
   VSE_STREAM                        = 4,
   DEBUG_STREAM                      = 5,
   CDC_GEN8_STREAM                   = 6,
   MMIC_STREAM                       = 7,
   ALIGNMENT_STREAM                  = 8,
   RFFT_STREAM                       = 9,
   BLOCKAGE_STREAM                   = 10,
   ADC_STREAM                        = 11,
   BSIS_STREAM                       = 9,
   MOIS_STREAM                       = 10,
   OLP_STREAM                        = 11,
   RADAR_CAPABILITY_STREAM           = 12,
   DOWN_SELECTION_STREAM             = 13,
   ID_STREAM                         = 14,
   TOI_STREAM                        = 15,
   DYNAMIC_ALIGNMENT_STREAM          = 16,
   ALIGNMENT_INTERNALS_STREAM        = 17,
   ROT_INTERNALS_STREAM              = 18,
   CALIB_STREAM                      = 19,
   ROT_SAFETY_FAULTS_STREAM          = 20,
   ROT_TRACKER_INFO_STREAM           = 21,
   ROT_VEHICLE_INFO_STREAM           = 22,
   ROT_OBJECT_STREAM                 = 23,
   ROT_ISO_OBJECT_STREAM             = 24,
   ROT_PROCESSED_DETECTION_STREAM    = 25,
   LCDA_CUST_OUTPUT_STREAM           = 26,
   TRAILER_DETECTOR_STREAM           = 17,
   INTERNAL_TRAILER_DETECTOR_STREAM  = 18,
   SENSOR_CALIB_STREAM               = 33,
   SYNC_INFO_STREAM                  = 20,
   VEHICLE_INFO_STREAM               = 21,
   TRACKER_INFO_STREAM               = 22,
   TIMING_INFO_STREAM                = 23,
   HOST_CALIBS_STREAM                = 24,
   HOST_PROPS_STREAM                 = 25,
   STATIC_ENV_POLY_STREAM            = 26,
   VID_STREAM                        = 27,
   CED_CUST_OUTPUT_STREAM            = 28,
   CTA_CUST_OUTPUT_STREAM            = 29,
   CUST_ALGO_STREAM                  = 30,
   FUNCTIONAL_SAFETY_FAULTS_STREAM   = 28,
   OBJECT_LIST_STREAM                = 29,
   PROCESSED_DETECTION_STREAM        = 30,
   TOI_DS_STREAM                     = 31,
   PARTNER_SENSOR_STREAM             = 32,
   OLP_OBJECT_STREAM                 = 34,
   PMO_OBJECT_STREAM                 = 35,
   CV_TRAILER_STREAM                 = 34,
   INTERNAL_OBJECT_STREAM            = 35,
   INTERNAL_CLUSTER_STREAM           = 36,
   INTERNAL_DETECTION_HIST_STREAM    = 37,
   INTERNAL_REFLECTION_BUFFER_STREAM = 38,
   INTERNAL_CWD_STREAM               = 39
};

enum class Cal_Source_T : int
{
   USC_FLASH           = 0U,
   SMC_FLASH           = 1U,
   PSC_FLASH           = 2U,
   TRACKER_INTERNALS   = 4U,
   ALIGNMENT_INTERNALS = 5U,
   USC_RAM             = 13U,
   SMC_RAM             = 48U,
};

typedef enum RR_ADAS_SYMBOL_Enum_Tag
{
   DATA_INVALID    = 0,
   SYM_INPUT_DATA  = 1,
   SYM_TRACKER_OUT = 2,
   SYM_RADAR_OUT   = 3,
   MAX_SYM_DATA
} RR_ADAS_SYMBOL_Enum_T;

#pragma pack(pop)
#endif
