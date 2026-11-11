#ifndef DYN_ALIGN_WRAPPER_H
#define DYN_ALIGN_WRAPPER_H
/*===========================================================================*/
/**
 * @file dyn_align_wrapper.h
 *
 * Application Interface to Dynamic Alignment Module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application Interface to Dynamic Alignment Module
 *
 * @section ABBR ABBREVIATIONS:
 *   -  List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -  Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -  Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     -  Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -  List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#include "dabb_include.h"
#include "dra_signal_short_track_exit.h"
#include "ipc_data.h"
#include "mem_pool.h"
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/
   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
#define DA_MP_MAX_NUM_MEMORY_LOC 2
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/
   float rm_fabsf(float x);
   /* ========================================================================== *
    *                            Structures
    * ========================================================================== */
   typedef struct DYN_ALIGNMENT_INPUT_Tag
   {
      Dynamic_Alignment_Data_T *p_m2d_alignment_config;
      M2D_One_Time_Msg_T *p_da_one_time_init_data;
      HIL_Ipc_Info_T *p_hil_info_in;
      Detection_Stream_T *p_det_stream;
      Rdd_Stream_T *p_rdd_stream;
      Vse_Stream_T *p_vse_stream;
      Radar_Capability_Stream_T *p_rc_stream;
      Dynamic_Alignment_Log_Stream_T *p_da_log_stream;
#if (DOWNSELECTION_ENABLE == 1U)
      TOI_DS_Stream_T *p_toi_ds_stream;
#else
   TOI_Stream_T *p_toi_stream;
#endif
      float vacs_boresight_kf_az;
      float vacs_boresight_kf_el;
      uint32_t n_updates_azimuth_initial;
   } DYN_ALIGN_INPUT_T;

   typedef struct DA_Internal_Mem_Info_Tag
   {
      void **addr_ptr;
      uint32_t size;
   } DA_Internal_Mem_Info_T;
   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void dyn_align_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr);

   /* A-PRISM fast-lock SiL/compare readouts (gain schedule value, lock flag). */
   float Aprism_Da_GetGain(void);
   uint8_t Aprism_Da_IsLocked(void);
#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
   /* A-PRISM ghost-inspection SiL/compare readouts (per-scan counters). */
   uint16_t Aprism_Ghost_Inspected(void);
   uint16_t Aprism_Ghost_Refused(void);
#endif

   Dynamic_Alignment_Log_Stream_T *Get_Prev_Dyn_Align_Output(void);
   DA_Internal_Mem_Info_T *Get_DA_Internal_memory_pointers(void);
   Memory_Pool_Return_T Alignment_Handler_Memory_Init(Mem_Pool_T *mem_pool);
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* _DYN_ALIGN_WRAPPER_ */
