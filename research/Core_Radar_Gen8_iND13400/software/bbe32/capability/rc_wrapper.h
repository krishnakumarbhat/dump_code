#ifndef RC_WRAPPER_H
#define RC_WRAPPER_H
/*===========================================================================*/
/**
 * @file rc_wrapper.h
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
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
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

#include "ipc_data.h"
#include "mem_pool.h"
#include "rcbb_include.h"
#include <stdint.h>
#include <string.h>

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
#define RC_MP_MAX_NUM_MEMORY_LOC 1

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/
/* ========================================================================== *
 *                            Structures
 * ========================================================================== */
typedef struct Rc_Ipc_Data_Tag
{
   Rdd_Stream_T *rdd_ipc_data;
   Detection_Stream_T *af_ipc_data;
   Detection_Debug_Stream_T *af_debug_data;
   RC_GLOB_TS_STRUCT_TYPE p_middle_of_dwell_ts_ipc;
   ID_Stream_T *id_data;
   Dynamic_Alignment_Log_Stream_T *dyn_data;
   Vse_Stream_T *vse_data;
   Radar_Capability_Stream_T *rc_output;
   int16_t ipc_avg_mmic_onchip_temp;
   uint8_t f_initialized;
} RC_Input_Data_T;

typedef struct RC_Internal_Mem_Info_Tag
{
   void **addr_ptr;
   uint32_t size;
} RC_Internal_Mem_Info_T;
/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

   // Radar Capability main function
   uint8_t rc_get_ver_major(void);
   uint8_t rc_get_ver_minor(void);
   uint8_t rc_get_ver_patch(void);

#ifdef PC_RESIM
   bool rc_wrapper_update_memory_instance(const uint8_t rc_new_memory_index);
#endif
   void rc_wrapper_reset(void);
#ifdef RC_FAULT_INJECION_ENABLED
   void rc_wrapper_set_injected_fault_num(const uint8_t fault_num);
#endif
   void rc_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr);
   Memory_Pool_Return_T Capability_Handler_Memory_Init(Mem_Pool_T *mem_pool);
   RC_Internal_Mem_Info_T *Get_RC_Internal_memory_pointers(void);

#ifdef __cplusplus
}
#endif

#endif
