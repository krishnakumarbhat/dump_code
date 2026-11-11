/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_project_parameters.h
 * Purpose: Embedded tracker project/variant parameters with compile time validation.
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */

/*==========================================================================*/
#ifndef EMB_TRACKER_PROJECT_PARAMETERS_H
#define EMB_TRACKER_PROJECT_PARAMETERS_H

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#if defined(PLATFORM_FLR8_STANDALONE)
   /* Stream array size parameters */
   #define NUMBER_OF_OBJECTS_EMB    64U
   #define NUMBER_OF_DETECTIONS_EMB 128U
   #define NUMBER_OF_SENSORS_EMB    1U
   #define NUMBER_OF_CLUSTERS_EMB   200U
   #define NUMBER_OF_HIST_DETS_EMB  200U

   /* The number of detections to receive from main sensor */
   #define NUMBER_OF_MAIN_DETECTIONS_EMB NUMBER_OF_DETECTIONS_EMB
   /* The number of detections to receive from helper sensors, if there are any */
   #define NUMBER_OF_PARTNER_DETECTIONS_EMB 0U

   /* The host vehicle type */
   #define HOST_TYPE F360_HOST_TYPE_PASSENGER_VEHICLE

   /* The number of cycles to buffer the host data to account for latency of detection processing */
   #define HOST_BUFFER_DELAY_CYCLES 0U

   /* The number of cycles to buffer main sensor variable data and detections to account for latency of partner sensor data */
   #define MAIN_SENSOR_BUFFER_DELAY_CYCLES 0U

   /* For enabling tracker internals streams */
   /* Caution: These will use a lot of memory on IPC! */
   #define ENABLE_INTERNAL_TRACKER_STREAMS 0U

#elif defined(PLATFORM_SRR8P_STANDALONE)
   #define NUMBER_OF_OBJECTS_EMB    64U
   #define NUMBER_OF_DETECTIONS_EMB 128U
   #define NUMBER_OF_SENSORS_EMB    1U
   #define NUMBER_OF_CLUSTERS_EMB   128U
   #define NUMBER_OF_HIST_DETS_EMB  128U

   #define NUMBER_OF_MAIN_DETECTIONS_EMB    NUMBER_OF_DETECTIONS_EMB
   #define NUMBER_OF_PARTNER_DETECTIONS_EMB 0U

   #define HOST_TYPE F360_HOST_TYPE_PASSENGER_VEHICLE

   #define HOST_BUFFER_DELAY_CYCLES 0U

   #define MAIN_SENSOR_BUFFER_DELAY_CYCLES 0U

   #define ENABLE_INTERNAL_TRACKER_STREAMS 0U

#elif defined(PLATFORM_SRR8P_2_SENSOR_FUSION)
   #define NUMBER_OF_OBJECTS_EMB    64U
   #define NUMBER_OF_DETECTIONS_EMB 128U
   #define NUMBER_OF_SENSORS_EMB    2U
   #define NUMBER_OF_CLUSTERS_EMB   200U
   #define NUMBER_OF_HIST_DETS_EMB  200U

   #define NUMBER_OF_MAIN_DETECTIONS_EMB    64U
   #define NUMBER_OF_PARTNER_DETECTIONS_EMB 64U

   #define HOST_TYPE F360_HOST_TYPE_PASSENGER_VEHICLE
   #ifndef HOST_BUFFER_DELAY_CYCLES
      #define HOST_BUFFER_DELAY_CYCLES 2U
   #endif
   #ifndef MAIN_SENSOR_BUFFER_DELAY_CYCLES
      #define MAIN_SENSOR_BUFFER_DELAY_CYCLES 2U
   #endif

   #define ENABLE_INTERNAL_TRACKER_STREAMS 0U

#elif defined(AL_TRACKER)
   #define NUMBER_OF_OBJECTS_EMB    64U
   #define NUMBER_OF_DETECTIONS_EMB 256U
   #define NUMBER_OF_SENSORS_EMB    2U
   #define NUMBER_OF_CLUSTERS_EMB   200U
   #define NUMBER_OF_HIST_DETS_EMB  200U

   #define NUMBER_OF_MAIN_DETECTIONS_EMB    128U
   #define NUMBER_OF_PARTNER_DETECTIONS_EMB 128U

   #define HOST_TYPE F360_HOST_TYPE_COMMERCIAL_VEHICLE

   /* May already be defined via build defines (e.g. stubbed test target) */
   #ifndef HOST_BUFFER_DELAY_CYCLES
      #define HOST_BUFFER_DELAY_CYCLES 2U
   #endif

   #ifndef MAIN_SENSOR_BUFFER_DELAY_CYCLES
      #define MAIN_SENSOR_BUFFER_DELAY_CYCLES 2U
   #endif

   #define ENABLE_INTERNAL_TRACKER_STREAMS 0U

#else
   /* These need to be defined to allow streamdef generation */
   #define NUMBER_OF_OBJECTS_EMB    1U
   #define NUMBER_OF_DETECTIONS_EMB 1U
   #define NUMBER_OF_SENSORS_EMB    1U
   #define NUMBER_OF_CLUSTERS_EMB   1U
   #define NUMBER_OF_HIST_DETS_EMB  1U

   /* But throw error if embedded code compilation reaches this case */
   #error "Project/variant parameters need defined!"
#endif

/* ========================================================================== */
/*                      Compile Time Validation                               */
/* ========================================================================== */
/* C++ static asserts to verify parameters match with chosen f360_variant_definition */
#ifdef __cplusplus
   #include "T360_Types.h"
   #include "f360_constants.h"
   #include "f360_variant_definition.h"
using namespace f360_variant_A;

/* Tracker parameter checks */
static_assert(NUMBER_OF_OBJECTS_EMB == NUMBER_OF_OBJECT_TRACKS, "Number of objects mismatch!");
static_assert(NUMBER_OF_DETECTIONS_EMB == MAX_NUMBER_OF_DETECTIONS, "Number of detections mismatch!");
static_assert(NUMBER_OF_SENSORS_EMB == MAX_NUMBER_OF_SENSORS, "Number of sensor calibs mismatch!");
static_assert(NUMBER_OF_CLUSTERS_EMB == NUMBER_OF_CLUSTERS, "Number of clusters mismatch!");
static_assert(NUMBER_OF_HIST_DETS_EMB == MAX_NUMBER_OF_HISTORIC_DETECTIONS, "Number of historic detections mismatch!");

/* Sensor detection count sanity check */
static_assert(NUMBER_OF_DETECTIONS_EMB ==
                 (NUMBER_OF_MAIN_DETECTIONS_EMB + (NUMBER_OF_PARTNER_DETECTIONS_EMB * (NUMBER_OF_SENSORS_EMB - 1U))),
              "Detection count macros don't match!");
#endif

#endif /* EMB_TRACKER_PROJECT_PARAMETERS_H */
