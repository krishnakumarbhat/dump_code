#ifndef SWC_PLT_CDD_ECUSYNC_EXTERNAL_H
#define SWC_PLT_CDD_ECUSYNC_EXTERNAL_H
/*===========================================================================*\
 * FILE: SWC_PLT_CDD_ECUSync_external.h
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This file conatins ECUSync/TimeSync realted functions.
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

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/
#include <stdint.h>
/*===========================================================================*\
 *  preprocessor #define CONSTANTS
\*===========================================================================*/
#ifndef NS_2_US
   #define NS_2_US 0.001f
#endif
#ifndef S_2_MS
   #define S_2_MS 1000u
#endif
#define US_2_NS                                (1000U)
#define S_2_US                                 (1000000UL)
#define S_2_NS                                 (1000000000UL)
#define NS_2_MS                                (0.000001f)
#define INT16_MAX_F                            (32767.0f)
#define INT16_MIN_F                            (-32768.0f)
#define POINT_OF_TRIGGER_SCALER                (10U) /* divide factor to adjust POINT_OF_TRIGGER signal, ms to .1ms */
#define TS_ERROR                               ((uint32_t)(-1))
#define STBM_EV_TIMEOUT_OCCURRED_MASK          (0x02U)
#define Radar_triggering_threshold_MAX         (51250U)
#define Radar_triggering_threshold_MIN         (48750U)
#define Radar_triggering_outside_threshold_MAX (55000U)
#define Radar_triggering_outside_threshold_MIN (45000U)

/* Uncomment the below macro to enable CAN Time Synchronization.
 * Comment it to disable CAN TimeSync and use Ethernet TimeSync instead. */
/* #define CANTSYNC_ENABLE */

/* Below are different values of STBM Status
8- Synchronized
24- Leap into Past
40- Leap into Future
9- Stopped PTP RX and last state was SYNCH
25- Stopped PTP RX and last state was Leap into Past
41- Stopped PTP RX and last state was Leap into Future

ts_status	time_sync_source_master
0	         0 (Local)
8	         1 (global)
9	         0 (Local)
24	         1 (global)
40	         1 (global)
25	         0 (Local)
41	         0 (Local)
*/

#define TS_GLOBAL_TIME_BASE (0x08u) /* Radar are synchronized */
#define TS_POWER_ON_STATUS  (0u)
#define TS_SOURCE_LOCAL     (0u)
#define TS_SOURCE_GLOBAL    (1u)
#define TS_STBM_LSB         (0x01)

typedef enum
{
   TS_NO_BUFF,
   TS_START_ACQ,
   TS_LOOK_COMP,
   TS_MAX_MEAS_PTS,
} GLOB_TS_MEAS_PTS;

typedef struct
{
   uint8_t ts_status;
   uint32_t ts_nanosecs;
   uint32_t ts_secs;
} GLOB_TS_STRUCT_TYPE;

/*===========================================================================*\
 * Function declarations
\*===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

   uint8_t CaptureGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point, GLOB_TS_STRUCT_TYPE *ret_ts);
   GLOB_TS_STRUCT_TYPE *GetGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
   GLOB_TS_STRUCT_TYPE *PeekGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
   uint8_t GetTimeStampDiff_Ns(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result);
   uint8_t GetMidTimeStamps(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, GLOB_TS_STRUCT_TYPE *result, uint32_t *diff);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SWC_PLT_CDD_ECUSYNC_EXTERNAL_H */
