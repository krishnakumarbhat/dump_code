/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_wrapper.h
 * Purpose: Embedded tracker wrapper function declarations
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */
/*==========================================================================*/
#ifndef EMB_TRACKER_WRAPPER_H
#define EMB_TRACKER_WRAPPER_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ipc_data.h"
#include "mem_pool.h"

/* ========================================================================== */
/*                           Helper Structs                                   */
/* ========================================================================== */
typedef struct Len_Wid_Segments_Tag
{
   float32_t len1;
   float32_t len2;
   float32_t wid1;
   float32_t wid2;
} Len_Wid_Segments;

/* ========================================================================== */
/*                      Function Declarations                                 */
/* ========================================================================== */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

   /* Tracker wrapper functions called from main_application.c */
   Memory_Pool_Return_T Emb_Tracker_Mem_Init(Mem_Pool_T *mem_pool, D2M_Msg_T *p_ipc_d2m);
   void Init_Emb_Tracker(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d);
   void Run_Emb_Tracker(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d, volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time);
   void Map_Ref_Point_To_Len_Wid_Segments(uint8_t reference_point, float32_t length, float32_t width, Len_Wid_Segments *segments);
#if defined(PC_RESIM_TRACKER) && defined(_DEBUG)
   void Close_F360_Tracker_Xtrk_File();
   void Open_F360_Tracker_Xtrk_File(const char *xtrk_filename);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* EMB_TRACKER_WRAPPER_H */
