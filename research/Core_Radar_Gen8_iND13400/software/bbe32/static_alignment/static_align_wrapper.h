
#ifndef STATIC_ALIGN_WRAPPER_H_
#define STATIC_ALIGN_WRAPPER_H_

/*===========================================================================*/
/**
 * @file static_align_wrapper.h
 *
 * Application Interface to Static Alignment module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application Interface to Static Alignment module
 *
 * @section File : static_align_wrapper.h
 *
 * @section purpose PURPOSE: Static alignment wrapper header
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
#include <stdint.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
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
#define SA_MP_MAX_NUM_MEMORY_LOC 1
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /* ========================================================================== *
    *                            Structures
    * ========================================================================== */
   typedef struct SA_Ipc_Data_Tag
   {
      Static_Alignment_Data_T *p_sa_data;
      Dynamic_Alignment_Data_T *p_da_data;
      Calib_Data_T *p_sa_calib_data;
      Detection_Stream_T *p_af_det_data;
      Vse_Stream_T *p_vehicle_data;
      Static_Alignment_Log_Stream_T *p_stat_align_stream_data;
      ID_Stream_T *p_ID_data;
      Rdd_Stream_T *p_rdd_stream_data;
      M2D_One_Time_Msg_T *p_da_one_time_init_data;
#if (DOWNSELECTION_ENABLE == 1U)
      TOI_DS_Stream_T *p_toi_ds_stream;
#else
   TOI_Stream_T *p_toi_stream;
#endif
   } SA_Input_Data_T;

   typedef struct SA_Internal_Mem_Info_Tag
   {
      void **addr_ptr;
      uint32_t size;
   } SA_Internal_Mem_Info_T;
   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void static_align_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr);
   Memory_Pool_Return_T SA_Alignment_Handler_Memory_Init(Mem_Pool_T *mem_pool);
   void sa_ptr_update(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m, M2D_One_Time_Msg_T *m2d_one_time_init_ptr, SA_Input_Data_T *sa_ipc_data);

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* STATIC_ALIGN_DOPPLER_WRAPPER_H_ */
