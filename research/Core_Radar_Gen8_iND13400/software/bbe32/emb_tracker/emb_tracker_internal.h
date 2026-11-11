/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_internal.h
 * Purpose: Definitions of internal variables shared between emb_tracker_wrapper.cpp and emb_tracker_stubs.cpp
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */

/*==========================================================================*/
#ifndef EMB_TRACKER_INTERNAL_H
#define EMB_TRACKER_INTERNAL_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "f360_core_info.h"
#include "f360_detection_list.h"
#include "f360_host.h"
#include "f360_host_raw.h"
#include "f360_radar_sensor.h"

using namespace f360_variant_A;

/* ========================================================================== */
/*                  Exported Object Declarations                              */
/* ========================================================================== */
/* These variables shared between emb_tracker_wrapper.cpp and emb_tracker_stubs.cpp */
extern F360_Core_Info_T core_info;
extern F360_Radar_Sensor_T sensors[MAX_NUMBER_OF_SENSORS];
extern F360_Detection_List_T *f360_det_list;
extern F360_Host_Raw_T host_raw;
extern F360_Host_T *host_buffer_read_ptr;

#endif /* EMB_TRACKER_INTERNAL_H */
