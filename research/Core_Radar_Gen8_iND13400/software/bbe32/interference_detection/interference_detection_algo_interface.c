/*===========================================================================*/
/**
 * @file interference_detection_algo_interface.c
 *
 * Interference detection algorithm interface implementation.
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
 * This module initializes interference detection BB inputs, clears logging data,
 * populates output logging structures, and provides the wrapper entry point.
 *
 * @section ABBR ABBREVIATIONS:
 *   - ID: Interference Detection
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Design_Doc_RDD_SIL.md
 *
 *   - Requirements Document(s):
 *     - Refer to project-level requirements baseline.
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - MISRA C:2012
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
#include "interference_detection_algo_interface.h"

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#include "idbb_include.h"
#include "interference_detection.h"
#include "interference_detection_cbk.h"
#include "ipc_dsp.h"
#include "mem_pool.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
/* Speed dependency removed: decisions are now made without vehicle speed.
   Historical macros and speed-based branching were removed to simplify
   the interface. */
/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static float32_t G_Low_Degradation_Thold;
static float32_t G_Med_Degradation_Thold;
static float32_t G_High_Degradation_Thold;

#ifdef ID_TEST
volatile static uint8_t Enable_Id_Test                                                                    = 1;
volatile static uint16_t Detect_Id_Test                                                                   = 14367U;
static uint16_t __attribute__((section(".sram0.data"))) Cfar_Nf_Est_Test[MAX_RANGE_BINS][ANGLE_BINS_USED] = {
   [0] = {14367, 8053, 7606, 14111, 7100, 13897, 13898, 12654}, [1] = {8444, 18258, 18466, 8760, 8144, 8618, 9303, 8792}};
static uint16_t __attribute__((section(".sram0.data")))
Nci_Bexp_Test[MAX_RANGE_BINS][ANGLE_BINS_USED]  = {[0] = {45, 45, 45, 45, 45, 45, 45, 45}, [1] = {45, 45, 45, 45, 45, 45, 45, 45}};
volatile static uint8_t Min_Chirp_Scaling_Test  = 3U;
volatile static uint16_t Start_Bin_Test         = 0U;
volatile static uint16_t End_Bin_Test           = 1U;
volatile static uint16_t Bv_Scale_Per_Rbin_Test = 45U;
#endif

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
static void id_ptr_update(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m, ID_INPUT_T *p_id_ipc_data);
/******************************************************************************
 * Name:  id_ptr_update
 *   Initialization function for ID module
 *
 * Shared Variables: none
 *
 * Parameters: M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m, ID_INPUT_T *p_id_ipc_data
 *
 * Return Value: none
 *
 ******************************************************************************/
void id_ptr_update(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m, ID_INPUT_T *p_id_ipc_data)
{
   p_id_ipc_data->p_rdd_stream = &p_d2m->payload.rdd_stream_data;
   p_id_ipc_data->p_vse_stream = &p_m2d->payload.veh_data;
   p_id_ipc_data->p_id_stream  = &p_d2m->payload.interference_detection_data;
}

/******************************************************************************
 * Name:  ID_Init_BB_Params
 *   Initialization function for ID parameters
 *
 * Shared Variables: ID_INPUT_T *p_id_ipc_data
 *
 * Parameters: none
 *
 * Return Value: none
 *
 ******************************************************************************/
void ID_Init_BB_Params(ID_INPUT_T *p_id_ipc_data)
{
   ID_BB_Input_Params_T *const l_id_bb_input_params_ptr = Get_ID_Init_Parameters();
#ifdef ID_TEST
   Radar_Look_T l_look_type = (Radar_Look_T)1;
#else
   Radar_Look_T l_look_type                        = (Radar_Look_T)p_id_ipc_data->p_rdd_stream->look_data.look_id;
#endif
   /* Unused variable removed - look_type not needed for current implementation */
   RADAR_FLOAT(((int32_t)k_nf_degradation_thold_smc[l_look_type][0]), 8, G_Low_Degradation_Thold);
   RADAR_FLOAT(((int32_t)k_nf_degradation_thold_smc[l_look_type][1]), 8, G_Med_Degradation_Thold);
   RADAR_FLOAT(((int32_t)k_nf_degradation_thold_smc[l_look_type][2]), 8, G_High_Degradation_Thold);
   static float32_t l_ref_mean_nf_temp        = 0.0F;
   static float32_t l_ref_nf_offset_temp      = 0.0F;
   static float32_t l_filter_coef_temp        = 0.0F;
   static float32_t l_data_discard_thold_temp = 0.0F;

#ifdef ID_TEST
   Cfar_Nf_Est_Test[0][0]                          = Detect_Id_Test;
   Nci_Bexp_Test[0][0]                             = Bv_Scale_Per_Rbin_Test;
   l_id_bb_input_params_ptr->enable_id_ptr         = (uint8_t *)(&Enable_Id_Test);
   l_id_bb_input_params_ptr->nf_est_ptr            = (uint16_t *)(&(Cfar_Nf_Est_Test));
   l_id_bb_input_params_ptr->min_chirp_scaling_ptr = (&Min_Chirp_Scaling_Test);
   l_id_bb_input_params_ptr->id_start_rbin_ptr     = (uint16_t *)&Start_Bin_Test;
   l_id_bb_input_params_ptr->id_end_rbin_ptr       = (uint16_t *)&End_Bin_Test;
#else
   l_id_bb_input_params_ptr->enable_id_ptr         = (uint8_t *)(&k_enable_interference_det_smc[l_look_type]);
   l_id_bb_input_params_ptr->nf_est_ptr            = (uint16_t *)(p_id_ipc_data->p_rdd_stream->rdd_data.cfar_nf_est);
   l_id_bb_input_params_ptr->min_chirp_scaling_ptr = (&p_id_ipc_data->p_rdd_stream->rdd_data.min_chirp_scaling);
   l_id_bb_input_params_ptr->id_start_rbin_ptr     = (uint16_t *)(&k_interference_det_rbin_range_smc[l_look_type][0]);
   l_id_bb_input_params_ptr->id_end_rbin_ptr       = (uint16_t *)(&k_interference_det_rbin_range_smc[l_look_type][1]);
#endif
   l_id_bb_input_params_ptr->low_degradation_thold_ptr  = &G_Low_Degradation_Thold;
   l_id_bb_input_params_ptr->med_degradation_thold_ptr  = &G_Med_Degradation_Thold;
   l_id_bb_input_params_ptr->high_degradation_thold_ptr = &G_High_Degradation_Thold;

#ifdef RBIN_SCALING_ENABLED
   #ifdef ID_TEST
   l_id_bb_input_params_ptr->bv_scale_per_rbin_ptr = (uint16_t *)&Nci_Bexp_Test;
   #else
   l_id_bb_input_params_ptr->bv_scale_per_rbin_ptr = (uint16_t *)(p_id_ipc_data->p_rdd_stream->rdd_data.nci_bexp);
   #endif
#endif

   l_id_bb_input_params_ptr->id_logging_out_ptr = p_id_ipc_data->p_id_stream;

   RADAR_UFLOAT(((uint32_t)k_interference_ref_mean_nf_smc[l_look_type]), 2, l_ref_mean_nf_temp);
   RADAR_UFLOAT(((uint32_t)k_interference_ref_nf_offset_smc[l_look_type]), 2, l_ref_nf_offset_temp);
   RADAR_UFLOAT(((uint32_t)k_interference_filter_coef_smc[l_look_type]), 8, l_filter_coef_temp);
   RADAR_UFLOAT(((uint32_t)k_interference_data_discard_thold_smc[l_look_type]), 1, l_data_discard_thold_temp);
   l_id_bb_input_params_ptr->ref_mean_nf_ptr        = &l_ref_mean_nf_temp;
   l_id_bb_input_params_ptr->ref_nf_offset_ptr      = (&l_ref_nf_offset_temp);
   l_id_bb_input_params_ptr->filter_coef_ptr        = (&l_filter_coef_temp);
   l_id_bb_input_params_ptr->data_discard_thold_ptr = (&l_data_discard_thold_temp);
}

/******************************************************************************
 * Name:  ID_Populate_Logging_Structure
 *   Output Logging function for ID
 *
 * Shared Variables: none
 *
 * Parameters: ID_INPUT_T *p_id_ipc_data
 *
 * Return Value: none
 *
 ******************************************************************************/
void ID_Populate_Logging_Structure(ID_INPUT_T *p_id_ipc_data)
{
   ID_BB_Input_Params_T *const l_id_bb_input_params_ptr = Get_ID_Init_Parameters();
   ID_Stream_T *const l_id_logging_out_ptr              = (ID_Stream_T *)(l_id_bb_input_params_ptr->id_logging_out_ptr);
   uint16_t id_scan_index                               = p_id_ipc_data->p_rdd_stream->look_data.scan_index;

   if (NULL != l_id_logging_out_ptr)
   {
      l_id_logging_out_ptr->stream_hdr.scan_index = id_scan_index;

      l_id_logging_out_ptr->nf_mean_db_value[0]          = Get_ID_BB_Internals()->nf_mean_db_value[0];
      l_id_logging_out_ptr->nf_max_db_value[0]           = Get_ID_BB_Internals()->nf_max_db_value[0];
      l_id_logging_out_ptr->nf_min_db_value[0]           = Get_ID_BB_Internals()->nf_min_db_value[0];
      l_id_logging_out_ptr->interference_detected        = Get_ID_BB_Internals()->interference_detected;
      l_id_logging_out_ptr->id_version_re_release        = Get_ID_BB_Internals()->id_version_re_release;
      l_id_logging_out_ptr->id_version_branch_identifier = Get_ID_BB_Internals()->id_version_branch_identifier;
      l_id_logging_out_ptr->id_version_minor             = Get_ID_BB_Internals()->id_version_minor;
      l_id_logging_out_ptr->id_version_major             = Get_ID_BB_Internals()->id_version_major;
      l_id_logging_out_ptr->interference_level           = Get_ID_BB_Internals()->interference_level;
      l_id_logging_out_ptr->range_check_interference     = Get_ID_BB_Internals()->range_check_interference;
      l_id_logging_out_ptr->normalised_nf                = Get_ID_BB_Internals()->normalised_nf;
      l_id_logging_out_ptr->interference_health          = Get_ID_BB_Internals()->interference_health;
      l_id_logging_out_ptr->interference_data_discard    = Get_ID_BB_Internals()->interference_data_discard;
   }
   else
   {
      /* Null pointer diagnostics are handled by the caller path. */
   }
}

/******************************************************************************
 * Name:  ID_Clear_Logging_Data
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 ******************************************************************************/
void ID_Clear_Logging_Data(void)
{
   ID_BB_Input_Params_T *const l_id_bb_input_params_ptr = Get_ID_Init_Parameters();

   if (NULL != l_id_bb_input_params_ptr->id_logging_out_ptr)
   {
      memset((ID_Stream_T *)(l_id_bb_input_params_ptr->id_logging_out_ptr), 0x00, sizeof(ID_Stream_T));
   }
   else
   {
      /* Null pointer diagnostics are handled by the caller path. */
   }
}

/******************************************************************************
 * Name:  interference_detection_wrapper
 *
 * Shared Variables: none
 *
 * Parameters: ID_INPUT_T *p_id_ipc_data
 *
 * Return Value: none
 *
 ******************************************************************************/
void interference_detection_wrapper(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m)
{
   ID_INPUT_T id_ipc_data;

   id_ptr_update(p_m2d, p_d2m, &id_ipc_data);
   /*Interference Detection*/
   ID_Init_BB_Params(&id_ipc_data); /* Initialize the BB inputs/outputs for Interference Detection BB*/
   ID_Clear_Logging_Data();
   ID_Init();                /*Interference detection Init function call*/
   Interference_Detection(); /* Interference Detection main API call*/
   ID_Populate_Logging_Structure(&id_ipc_data);
}
