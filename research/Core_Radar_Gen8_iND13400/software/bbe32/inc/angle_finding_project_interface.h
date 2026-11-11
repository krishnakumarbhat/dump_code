#ifndef ANGLE_FINDING_PROJECT_INTERFACE_H
#define ANGLE_FINDING_PROJECT_INTERFACE_H
/*===========================================================================*/
/**
 * @file angle_finding_project_interface.h
 *
 * Contains the definitions of user-defined datatypes related to anglefinding
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
 *===========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "afbb_cfg.h"
#include "angle_finding_interface.h"
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "ipc_data.h"
#include "mem_pool.h"
#include "rdd_stream.h"
#include "reuse.h"

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
   #include "down_selection_stream.h"
#endif

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

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   /* type for slope_correction_status in detection and downselection streams */
   typedef enum FS_Executed_Flag_Tag
   {
      FS_NO_SLOPE_CORRECTION = (0),
      FS_AZ_EXECUTED         = (1),
      FS_EL_EXECUTED         = (2),
      FS_AZ_EL_EXECUTED      = (3)
   } FS_Executed_Flag_T;

   /*===========================================================================*\
    * Exported Object Declarations
   \*===========================================================================*/
   typedef struct AF_Appl_Input_Tag
   {
      RDD_Data_T *appl_rdd_data_ptr;
      Look_Data_T *appl_look_data_ptr;
      XCP_Data_T *appl_xcp_data_ptr;
      XCP_Info_T *appl_xcp_info_data_ptr;
      float32_t *appl_veh_speed_ptr;
      uint8_t *appl_radar_position_ptr;
      uint32_t appl_doppler_start_time;
      Calib_Data_T *calib_data_ptr; // Includes the sensor mount information for down-selection
                                    // Need to be populated from the M2D one time buffer
   } AF_Appl_Input_T;

   typedef struct AF_Appl_Output_Tag
   {
      Detection_Stream_T *appl_detection_stream_data_ptr;
      Detection_Debug_Stream_T *appl_detection_debug_data_ptr;
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      Down_selection_Stream_T *appl_down_selection_stream_data_ptr;
#endif
      Angle_Data_XCP_T *appl_af_xcp_data_ptr;
      Angle_Timing_Data_T *appl_af_timing_data_ptr;
   } AF_Appl_Output_T;

   /*===========================================================================*\
    * Exported Function Prototypes
   \*===========================================================================*/

   /*
    * NOTE: function headers can be found alongside the function definitions in
    * anglefinding_project_interface.c
    */
   Memory_Pool_Return_T Anglefinding_Memory_Init(Mem_Pool_T *dram_mem_pool, Mem_Pool_T *sram_mem_pool);
   AF_Retval_T Appl_Angle_Finding_Process(AF_Appl_Input_T *, AF_Appl_Output_T *);

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
   Memory_Pool_Return_T DownSelection_Memory_Init(Mem_Pool_T *mem_pool);
   AF_Retval_T Appl_Down_Selection_Process(AF_Appl_Input_T *appl_in, AF_Appl_Output_T *appl_out);
#endif

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
   Memory_Pool_Return_T Fascia_Compensation_Memory_Init(Mem_Pool_T *dram_mem_pool);
   void Appl_Execute_Fascia_Compensation(volatile Fascia_Comp_Data_T *fascia_compensation_params, AF_Appl_Output_T *af_appl_data);
#endif

   void Angle_Finding_Update_Metrics(AF_Appl_Output_T *appl_out, AF_Retval_T af_status);

   /*===========================================================================*\
    * Exported Inline Function Definitions and #define Function-Like Macros
   \*===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
