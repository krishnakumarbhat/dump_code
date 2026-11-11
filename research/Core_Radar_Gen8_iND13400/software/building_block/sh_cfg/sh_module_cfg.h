#ifndef SH_MODULE_CFG_H
#define SH_MODULE_CFG_H
/*===========================================================================*\
 * FILE: sh_module_cfg.h
*===========================================================================
* Copyright (C) 2020 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*   Provides the configuration for stream handler module.
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
#include "reuse.h"
#include "sh_bb_include.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
// #include "calibration.h"

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define REC_VER      (0xA5)
#define COMMENTED_SH 0U

#define US_T0_MS (0.0001F)
/*Enable the CDC Total Chunks count update for current Radar cycle from DSP/BBE core update*/
#if (defined(CDC_ENABLE))
   #define CDC_TOTAL_CHUNK_INDICATION_FROM_DSP         /*Enable the CDC total chunks in current Radar cycle logic as per APTIV    \
                                                          Header 6.4                                                              \
                                                          \version*/
   #define LAST_FRAME_INDICATION_CNT              (1U) /* CDC Last Frame Indication count */
   #define ONE_FRAME                              (1U)
#endif

/* Ethernet frame in bytes */
#define ETH_FRAME_LENGTH ((uint16_t)1514U)
#define ETH_PAYLOAD      ((uint16_t)1500U)
#define IP_V4_LEN        ((uint16_t)20U)
#define UDP_HDR_LEN      ((uint16_t)8U)
#define REC_HANDLER_OK   (0U)
#define REC_HANDLER_NOK  (1U)

/* UDP is used now, may be TCP/IP later */
#define PROTOCOL_HDR_LEN (UDP_HDR_LEN)

#define IP_PKT_HDR_LEN ((uint16_t)(IP_V4_LEN + PROTOCOL_HDR_LEN))

/* Data payload is same as udp payload i.e. 1472U */
#define ETH_DATA_PAYLOAD ((uint16_t)(ETH_PAYLOAD - IP_PKT_HDR_LEN))

#define RECORD_VERSION ((uint16_t)REC_VER)

#define RECORD_HEADER ((uint16_t)(sizeof(Rec_Hdr_T)))
#ifdef ENABLE_CUSTHDR
   #define REC_CUSTOM_HEADER (sizeof(UDP_Cust_Frame_Header_T))
#else
   #define REC_CUSTOM_HEADER ((uint16_t)0U)
#endif

#define REC_HDR_LEN ((RECORD_HEADER) + (REC_CUSTOM_HEADER))

#define RECORD_VERSIONINFO (uint16_t)((RECORD_VERSION << 8U) | REC_HDR_LEN)

/* The length of the actual data txed in a packet including customer header */
#define REC_PAYLOAD ((uint16_t)(ETH_DATA_PAYLOAD - REC_HDR_LEN))

#define RADAR_CYCLE_MS_TEMPARARY  (50U) /* It needs to be removed once RADAR_CYCLE_MS is available*/
#define MBPS_TO_BPS               (1000000.0F)
#define BYTE_TO_BITS              (8U)
#define SECOND_TO_MS              (1000.0F)
#define ENABLE_RF_STREAM_TESTCODE 0 /* Enables Skip Detection test Code */
#define STREAM_QUEUE_SIZE         ((uint8_t)128U)

#define CALIB_STREAM_NUMBER  (14U)
#define CALIB_STREAM_VERSION (52U) /* dummy */
#define US_TO_MS             0.0001F

#define DISABLE_OPTIMIZATION
#define ENABLE_OPTIMIZATION

   typedef uint32_t Calib_Stream_T;

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/

#if (0xA5 != REC_VER)
   #error "\nVariant not supported. Please add support for the variant you are compiling\n"
#else
   #define STREAM_SOURCE K_PLATFORM_VARIANT
#endif

#define SH_ENABLE_CALIB_STREAM /*Enable CALIB stream for SH BB build */

#if defined(SH_ENABLE_CALIB_STREAM)
   #define SH_CALIB_STREAM_ENTRY(DCS_X) DCS_X(CALIB, Calib)
#else
   #define SH_CALIB_STREAM_ENTRY(DCS_X)
#endif

#define BASE_STREAM_LIST(DCS_X)                                                                                                   \
   DCS_X(DETECTION, Detection)                                                                                                    \
   DCS_X(VSE, Vse)                                                                                                                \
   DCS_X(RDD, Rdd)                                                                                                                \
   DCS_X(MMIC, MMIC)                                                                                                              \
   SH_CALIB_STREAM_ENTRY(DCS_X)                                                                                                   \
   DCS_X(STATUS, Status)                                                                                                          \
   DCS_X(DEBUG, Debug)                                                                                                            \
   DCS_X(DRA, Dynamic_Alignment_Log)                                                                                              \
   DCS_X(CDC, CDC)                                                                                                                \
   DCS_X(HEADER, Header)                                                                                                          \
   DCS_X(RDD_DEBUG, Rdd_Debug)                                                                                                    \
   DCS_X(RADAR_CAPABILITY, Radar_Capability)                                                                                      \
   DCS_X(ID, ID)                                                                                                                  \
   DCS_X(DETECTION_DEBUG, Detection_Debug)                                                                                        \
   DCS_X(DOWN_SELECTION, Down_selection)                                                                                          \
   DCS_X(TOI, TOI)                                                                                                                \
   DCS_X(TOI_DS, TOI_DS)                                                                                                          \
   DCS_X(SRA, Static_Alignment_Log)                                                                                               \
   DCS_X(PARTNER_SENSOR, Partner_Sensor)

#if defined(FEATURE_ENABLE)
   #define FEATURE_STREAM_LIST(DCS_X)                                                                                             \
      DCS_X(BSIS, Bsis)                                                                                                           \
      DCS_X(MOIS, Mois)                                                                                                           \
      DCS_X(OLP, Olp)
#else
   #define FEATURE_STREAM_LIST(DCS_X)
#endif

#if defined(TRACKER_ENABLED)
   #define TRACKER_STREAM_LIST(DCS_X)                                                                                             \
      DCS_X(SYNC_INFO, Sync_Info)                                                                                                 \
      DCS_X(VEHICLE_INFO, Vehicle_Info)                                                                                           \
      DCS_X(TRACKER_INFO, Tracker_Info)                                                                                           \
      DCS_X(TIMING_INFO, Timing_Info)                                                                                             \
      DCS_X(HOST_CALIBS, Host_Calibs)                                                                                             \
      DCS_X(HOST_PROPS, Host_Props)                                                                                               \
      DCS_X(STATIC_ENV_POLY, Static_Env_Poly)                                                                                     \
      DCS_X(FUNCTIONAL_SAFETY_FAULTS, Functional_Safety_Faults)                                                                   \
      DCS_X(OBJECT_LIST, Object_List)                                                                                             \
      DCS_X(PROCESSED_DETECTION, Processed_Detection)                                                                             \
      DCS_X(SENSOR_CALIB, Sensor_Calib)                                                                                           \
      DCS_X(TRAILER_DETECTOR, Trailer_Detector)                                                                                   \
      DCS_X(CV_TRAILER, Cv_Trailer)
#else
   #define TRACKER_STREAM_LIST(DCS_X)
#endif

#if defined(TRACKER_ENABLED) && ENABLE_INTERNAL_TRACKER_STREAMS
   #define TRACKER_INTERNAL_STREAM_LIST(DCS_X)                                                                                    \
      DCS_X(INTERNAL_TRAILER_DETECTOR, Internal_Trailer_Detector)                                                                 \
      DCS_X(INTERNAL_OBJECT, Internal_Object)                                                                                     \
      DCS_X(INTERNAL_CLUSTER, Internal_Cluster)                                                                                   \
      DCS_X(INTERNAL_DETECTION_HIST, Internal_Detection_Hist)                                                                     \
      DCS_X(INTERNAL_REFLECTION_BUFFER, Internal_Reflection_Buffer)                                                               \
      DCS_X(INTERNAL_CWD, Internal_CWD)
#else
   #define TRACKER_INTERNAL_STREAM_LIST(DCS_X)
#endif

/* SH TX Stream List */
#define STREAM_LIST(DCS_X)                                                                                                        \
   BASE_STREAM_LIST(DCS_X)                                                                                                        \
   TRACKER_STREAM_LIST(DCS_X)                                                                                                     \
   TRACKER_INTERNAL_STREAM_LIST(DCS_X)                                                                                            \
   FEATURE_STREAM_LIST(DCS_X)

/* SH RX Stream List */
#if defined(STREAM_RX_ENABLE)
   #define STREAM_RX_LIST(DCS_X) DCS_X(VID, Vid)
#else
   #define STREAM_RX_LIST(DCS_X)
#endif

#define STREAM_ENUM(stream_name, pfx)    stream_name,
#define STREAM_RX_ENUM(stream_name, pfx) stream_name,
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum Stream_List_Tag
   {
      STREAM_LIST(STREAM_ENUM) MAX_NUM_STRMS /* Max number of streams */
   } Stream_List_T;

#if defined(STREAM_RX_ENABLE)
   typedef enum Stream_Rx_List_Tag
   {
      STREAM_RX_LIST(STREAM_RX_ENUM) MAX_NUM_STRMS_RX /* Max number of rx streams */
   } Stream_Rx_List_T;
#endif

   typedef enum Sensor_Type_Tag
   {
      SENSOR_UNKNOWN = 0x00,
      SENSOR_RADAR,
      SENSOR_CAMERA,
      SENSOR_LIDAR,
      SENSOR_ULTRA_SONIC,
   } Sensor_Type_T;
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * -------   --------  ------    ------------   -----------------------------
 * Date      Revision  User ID    Jira Ticket   Description
 * -------   --------  ------    ------------   ------------------------------
 *
\*===========================================================================*/
#endif /* SH_MODULE_CFG_H */
