/**
 * @file doppler_process_ifc.c
 *
 * Application interface mapping for Doppler Process module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2023 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Doppler Process module
 *
 * @section ABBR ABBREVIATIONS:
 *   - None.
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Doppler Process Module Design Document
 *
 *   - Requirements Document(s):
 *     - Doppler Process Module Requirements Document
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - MISRA C:2012 Guidelines
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "api/bbe_helpers.h"
#include "api/profiling_helpers.h"
#include "api/ra_helpers.h"
#include "api/second_pass.h"
#include "api/timing_helpers.h"

#include "appl_fp_ifc.h"
#include "appl_sp_ifc.h"

#include "appl_cfar_ifc.h"
#include "appl_rdd_prv.h"
#include "appl_sweepbw_ifc.h"
#include "ci_stv_misalignment.h"
#include "doppler_process.h"
#include "doppler_process_ifc.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "mem_pool.h"
#include "range_process_ifc.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "smc_cal.h"
#include "spbb_cfg.h"
#include "spbb_math.h"
#include "sweep_bw.h"
#include "sweep_bw_types.h"
#include "usc_cal.h"

/* ========================================================================== */
/*                     SWE5 Integration Test Hook                             */
/* ========================================================================== */
#include "dsp_it_macros_test.h"
/*===========================================================================*/
/* Compatibility with future USC updates */
/*===========================================================================*/
#if defined(k_calmat1_ctx_usc) && !defined(k_calmat1_ctx_USC)
   #define k_calmat1_ctx_USC k_calmat1_ctx_usc
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
// #define ENABLE_MODULEWISE_TIMING
#define NUM_INITIAL_RANGE_BINS              (3U)
#define SECOND_TO_LAST_RBIN                 ((uint16_t)(MAX_RANGE_BINS - 2U))
#define LAST_RBIN_INDEX                     ((uint16_t)(MAX_RANGE_BINS - 1U))
#define CI2_OFFSET                          (32U)
#define MAX_DOPPLER_PROC_OVERRUN_TIME_TICKS ((uint32_t)(MAX_DOPPLER_PROC_OVERRUN_TIME_US / DSP_CLOCK_PERIOD_US))

#ifdef ENABLE_MODULEWISE_TIMING
   #define PROFILE_MODULE_INIT(x)  Profiling_Helpers_Init(&(x##_Modulewise_Time), true)
   #define PROFILE_MODULE_START(x) Profiling_Helpers_Init(&(x##_Modulewise_Time), false)
   #define PROFILE_MODULE_STOP(x)  Profiling_Helpers_Update(&(x##_Modulewise_Time))
#else
   #define PROFILE_MODULE_INIT(x)
   #define PROFILE_MODULE_START(x)
   #define PROFILE_MODULE_STOP(x)
#endif

#ifdef SPBB_SCM_ENABLE
static void Reset_SCM_Internals(RDD_Internal_Buff_T *p_rdd_int_buffer);
#endif
/* ========================================================================== */
/*                          Local Type Declarations                           */
/* ========================================================================== */

/** Structure to hold Doppler Dram1 memory pool variables for easier allocation and to enforce alignment */
typedef struct Doppler_Dram1_MemPool_Vars_Tag
{
   NCI_Circular_Buffer_Trans_T rdop_avg_data __attribute__((aligned(32)));
   int16_t angle_coefficients[4][32] __attribute__((aligned(32)));
   uint16_t temp_rdop_avg_input[MAP_NUM_ANGLES][MAX_DOPPLER_FFT_SIZE] __attribute__((aligned(32)));
} Doppler_Dram1_MemPool_Vars_T;

/** Structure to hold Doppler Sram1 memory pool variables for easier allocation and to enforce alignment */
typedef struct Doppler_Sram1_MemPool_Vars_Tag
{
   int32_t dp_dfft_bv_output_buffer[BV_CIRCULAR_BUFF_DEPTH][NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE] __attribute__((aligned(64)));
   uint16_t dp_rdop_avg_nci_data[NCI_CIRCULAR_BUFF_DEPTH][MAP_NUM_ANGLES][MAX_DOPPLER_FFT_SIZE] __attribute__((aligned(32)));

   /*
    * Align to 256 bytes, so that these buffers occupy complete cache lines.
    * Bexp_Output_T is 16 bytes, so total size of a set of MAP_NUM_ANGLES is 128 bytes or half a cache line.
    * If NCI_CIRCULAR_BUFF_DEPTH is not an even number, need to pad this structure with dummy data.
    */
   Bexp_Output_T dp_nci_bexp[NCI_CIRCULAR_BUFF_DEPTH][MAP_NUM_ANGLES] __attribute__((aligned(256)));

#if NCI_CIRCULAR_BUFF_DEPTH % 2 != 0
   /* Pad with dummy data */
   uint8_t padding[256 - (sizeof(dp_nci_bexp) % 256)];
#endif
} Doppler_Sram1_MemPool_Vars_T;

/* ========================================================================== */
/*                         Local Object Definitions                           */
/* ========================================================================== */

/* ========================================================================== */
/*                           External variables                               */
/* ========================================================================== */

/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* Pointers to Doppler variables */
uint16_t *rdop_avg_data_ptr[NCI_CIRCULAR_BUFF_DEPTH];
int16_t (*Angle_Coefficients_Ptr)[32];
uint16_t (*rdop_avg_temp_ptr)[MAP_NUM_ANGLES][MAX_DOPPLER_FFT_SIZE];

/** Pointers to all Doppler variables allocated to the shareable Dram1 Memory Pool */
NCI_Circular_Buffer_Trans_Ptr_T rdop_avg_data;
/* NCI_Circular_Buffer_Ptr_T rdop_avg_max; */
int16_t *ci_stv_vec;

/** Pointers to all Doppler variables allocated to the shareable Sram1 Memory Pool */
int32_t (*dp_dfft_bv_output_buffer)[BV_CIRCULAR_BUFF_DEPTH][NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE];
uint16_t (*dp_rdop_avg_nci_data)[NCI_CIRCULAR_BUFF_DEPTH][MAP_NUM_ANGLES][MAX_DOPPLER_FFT_SIZE];
Bexp_Output_T (*dp_nci_bexp)[NCI_CIRCULAR_BUFF_DEPTH][MAP_NUM_ANGLES];

Ra_Cmd_Map_Index_List_T *p_ra_cmd_list_mem = NULL;

/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */
/* Variables specific to Dopp/RDD TimeOut Limit */
static volatile uint32_t Doppler_Proc_Initialization_Fail_Count = 0U;
static volatile uint32_t Doppler_Proc_Active_Time_Max           = 0U;
static volatile uint32_t Doppler_Proc_Active_Ticks_Max          = 0U;
static volatile uint16_t Doppler_Proc_Overrun_Counter           = 0U;
uint32_t doppler_proc_start_timestamp                           = 0U;
uint32_t doppler_proc_max_runtime                               = 0U;

#ifdef ENABLE_MODULEWISE_TIMING
ProfilingStruct_t Doppler_Modulewise_Time          = {0};
ProfilingStruct_t Extract_NCI_Bexp_Modulewise_Time = {0};
ProfilingStruct_t SweepBW_Modulewise_Time          = {0};
ProfilingStruct_t FP_Modulewise_Time               = {0};
ProfilingStruct_t SP_Modulewise_Time               = {0};
ProfilingStruct_t CFAR_Modulewise_Time             = {0};
#endif

static volatile uint32_t Doppler_Proc_RA_Error_Count                         = 0U;
uint8_t __attribute__((section(".sram0.bss"))) rest_bin_flag[MAX_RANGE_BINS] = {0};

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static bool Appl_Doppler_Process_Init(Radar_Look_T look_id);
Memory_Pool_Return_T __attribute__((noinline)) Appl_Ra_Cmd_Memory_Init(Mem_Pool_T *mem_pool);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *   Allocate temporary objects to the dram1 memory pool
 *
 * @param[in]  mem_pool - Pointer to the memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T Appl_Doppler_Dram1_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T ret_val = MEM_POOL_FAILURE;

   Doppler_Dram1_MemPool_Vars_T *doppler_mempool_vars = NULL;
   ret_val = Mem_Pool_Alloc(mem_pool, sizeof(*doppler_mempool_vars), (void **)&doppler_mempool_vars);

   if (MEM_POOL_SUCCESS == ret_val)
   {
      /* Assign pointers to all struct members */
      rdop_avg_data          = &doppler_mempool_vars->rdop_avg_data;
      Angle_Coefficients_Ptr = &doppler_mempool_vars->angle_coefficients[0];
      rdop_avg_temp_ptr      = &doppler_mempool_vars->temp_rdop_avg_input;
      /* rdop_avg_max  = &doppler_mempool_vars->rdop_avg_max; */
      /* ci_stv_vec    = (void *)&doppler_mempool_vars->ci_stv_vec; */

      ret_val = Appl_Rdd_Dram1_Memory_Init(mem_pool);
      if (MEM_POOL_SUCCESS == ret_val)
      {
         ret_val = Appl_Ra_Cmd_Memory_Init(mem_pool);
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Do Nothing */
   }

   return ret_val;
}

/**
 *  @b Description
 *  @n
 *   Allocate temporary objects to the sram1 memory pool
 *
 * @param[in]  mem_pool - Pointer to the memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T Appl_Doppler_Sram1_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T ret_val = MEM_POOL_FAILURE;

   Doppler_Sram1_MemPool_Vars_T *doppler_mempool_vars = NULL;
   ret_val = Mem_Pool_Alloc(mem_pool, sizeof(*doppler_mempool_vars), (void **)&doppler_mempool_vars);

   if ((MEM_POOL_SUCCESS == ret_val) && (NULL != doppler_mempool_vars))
   {
      /* Assign pointers to all struct members */
      dp_dfft_bv_output_buffer = &doppler_mempool_vars->dp_dfft_bv_output_buffer;
      dp_rdop_avg_nci_data     = &doppler_mempool_vars->dp_rdop_avg_nci_data;
      dp_nci_bexp              = &doppler_mempool_vars->dp_nci_bexp;

      /* Zero any vars that need it */
      vector_clear(dp_nci_bexp, sizeof(*dp_nci_bexp));
      xthal_dcache_block_writeback_inv(dp_nci_bexp, sizeof(*dp_nci_bexp));

      ret_val = Appl_CFAR_Memory_Init(mem_pool);
   }
   else
   {
      /* Do Nothing */
   }

   return ret_val;
}

/**
 *  @b Description
 *  @n
 *   Allocate the RA command map index list buffer on the memory pool.
 *
 * @param[in]  mem_pool - Pointer to the memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T __attribute__((noinline)) Appl_Ra_Cmd_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T ret_val = MEM_POOL_FAILURE;

   ret_val = Mem_Pool_Alloc(mem_pool, sizeof(Ra_Cmd_Map_Index_List_T), (void **)&p_ra_cmd_list_mem);
   return ret_val;
}

static void Circular_Buffer_Init(void)
{
   uint16_t k;

   /*need to initialize prev, curr and next NCI data*/
   for (k = 0U; k < NCI_CIRCULAR_BUFF_DEPTH; k++)
   {
      rdop_avg_data_ptr[k] = &(*rdop_avg_data)[k][0][0];
   }
}

#ifdef SPBB_SCM_ENABLE
/**
 *  @b Description
 *  @n
 *      Reset the Saturation Counter measure's internal flags.
 *
 *  @param[in]  *p_rdd_int_buffer
 *             pointer to RDD_Internal_Buff_T
 *  @param[out]  None
 *
 */
static void Reset_SCM_Internals(RDD_Internal_Buff_T *p_rdd_int_buffer)
{
   p_rdd_int_buffer->scm_targets_saturation_flag = CODED_FALSE;
   p_rdd_int_buffer->scm_prioritization_flag     = CODED_FALSE;
   p_rdd_int_buffer->scm_run_per_rbin            = CODED_FALSE;
   p_rdd_int_buffer->scm_max_rbin_processed      = 0U;
   p_rdd_int_buffer->scm_max_detectable_range    = 0.0F;
   vector_clear(&p_rdd_int_buffer->saturation_cm_dbin_diff[0], sizeof(p_rdd_int_buffer->saturation_cm_dbin_diff));
}
#endif

static void __attribute__((noinline)) Circular_Buffer_Update(void)
{
   rdop_avg_t **pp_rdop_avg_data;
   rdop_avg_t *p_rdop_avg_data;

   uint16_t k;

   /* Rotate rdop avg  history */
   pp_rdop_avg_data = &rdop_avg_data_ptr[0];
   p_rdop_avg_data  = pp_rdop_avg_data[0];

   /* Rotate NCI rdop avg and history */
   for (k = 0U; k < (NCI_CIRCULAR_BUFF_DEPTH - 1U); k++)
   {
      pp_rdop_avg_data[k] = pp_rdop_avg_data[(k + 1U)];
   }
   pp_rdop_avg_data[(NCI_CIRCULAR_BUFF_DEPTH - 1U)] = p_rdop_avg_data;
}

static void Extract_Nci_Bexp_Output(DopplerProc_Output_T *p_doppler_process_out, RDD_Data_T *p_rdd_data, uint16_t rbin_idx_circ,
                                    uint16_t rbin_idx)
{
   uint16_t aidx;

   /* Invalidate cache for the NCI output and Bexp output before reading the data to ensure data coherency as Doppler Process
    * writes to these buffers using non-cacheable writes */
   xthal_dcache_block_invalidate(&(*p_doppler_process_out->p_nci_output)[rbin_idx_circ],
                                 sizeof((*p_doppler_process_out->p_nci_output)[rbin_idx_circ]));
   xthal_dcache_block_invalidate(&((*p_doppler_process_out->nci_bexp)[rbin_idx_circ]),
                                 sizeof((*p_doppler_process_out->nci_bexp)[rbin_idx_circ]));

   for (aidx = 0; aidx < MAP_NUM_ANGLES; aidx++)
   {
      p_rdd_data->nci_bexp[rbin_idx][aidx] = (*p_doppler_process_out->nci_bexp)[rbin_idx_circ][aidx].bexp;
   }

   /* Copy the current rdop_avg data to the internal memory of the BBE, so that the transpose can be done efficiently. */
   vector_copy_aligned(rdop_avg_temp_ptr, &(*p_doppler_process_out->p_nci_output)[rbin_idx_circ], sizeof(*rdop_avg_temp_ptr));
   Transpose_8xN_U16(&(*rdop_avg_data)[rbin_idx_circ][0][0], rdop_avg_temp_ptr, MAX_DOPPLER_FFT_SIZE);
}

/**
 *  @b Description
 *  @n
 *      bool(Radar_Look_T look_id) placeholder for initializing the doppler processing configuration based on the look_id.
 *
 *      (Radar_Look_T look_id, Doppler_Process_Input_T *doppler_process_input, Doppler_Process_Output_T* doppler_process_output)
 *
 */
static bool Appl_Doppler_Process_Init(Radar_Look_T look_id)
{
   bool ret_val                             = false;
   DopplerProc_Config_T doppler_process_cfg = {0};
   int16_t *p_smc_real_in                   = &k_uncal_tx_stv_real_look_1_smc[0][0];
   int16_t *p_smc_imag_in                   = &k_uncal_tx_stv_imag_look_1_smc[0][0];

   doppler_process_cfg.look_id                 = look_id;
   doppler_process_cfg.num_chirps              = K_FRAME[look_id];
   doppler_process_cfg.num_adc_samples         = M_FRAME[look_id];
   doppler_process_cfg.doppler_fft_size        = MAX_DOPPLER_FFT_SIZE;
   doppler_process_cfg.used_rfft_bins          = MAX_RANGE_BINS;
   doppler_process_cfg.p_doppler_window_data   = k_doppler_window_smc[look_id];
   doppler_process_cfg.p_doppler_bpm_data      = k_bpm_codes_adc_varying_smc[look_id];
   doppler_process_cfg.p_angle_filter_coeffs_1 = &Angle_Coefficients_Ptr[0];
   doppler_process_cfg.p_angle_filter_coeffs_2 = &Angle_Coefficients_Ptr[1];
   doppler_process_cfg.p_angle_filter_coeffs_3 = &Angle_Coefficients_Ptr[2];
   doppler_process_cfg.p_angle_filter_coeffs_4 = &Angle_Coefficients_Ptr[3];
   doppler_process_cfg.p_ddm_offset_table      = k_ddma_bin_shifts_smc[look_id];
   doppler_process_cfg.k_rest_threshold_factor = (uint16_t)k_rest_threshold_factor_smc[look_id];
   doppler_process_cfg.posp_gain               = 0;
   doppler_process_cfg.p_ra_cmd_list           = p_ra_cmd_list_mem;

   if (RADAR_LOOK_B == look_id)
   {
      p_smc_real_in = &k_uncal_tx_stv_real_look_2_smc[0][0];
      p_smc_imag_in = &k_uncal_tx_stv_imag_look_2_smc[0][0];
   }
   else if (RADAR_LOOK_C == look_id)
   {
      p_smc_real_in = &k_uncal_tx_stv_real_look_3_smc[0][0];
      p_smc_imag_in = &k_uncal_tx_stv_imag_look_3_smc[0][0];
   }
   else if (RADAR_LOOK_D == look_id)
   {
      p_smc_real_in = &k_uncal_tx_stv_real_look_4_smc[0][0];
      p_smc_imag_in = &k_uncal_tx_stv_imag_look_4_smc[0][0];
   }
   else
   {
      /* Do Nothing - Default to look 1 stv values */
   }

   Do_Matrix_Multiply(p_smc_real_in, p_smc_imag_in, &k_calmat1_ctx_USC, &k_mmic_to_af_tx_order_smc[0],
                      &k_af_to_mmic_tx_order_smc[0], Angle_Coefficients_Ptr);

   ret_val = (DOPPLER_PROCESS_NO_ERROR == Doppler_Process_Init(&doppler_process_cfg));

   return ret_val;
}

/**
 *  @b Description
 *  @n
 *   Call initialization functions for Sweep BW, First Pass, and Second Pass
 *
 * @param[in]  look_id - Current frame Look ID
 *
 * @return true for success, false for failure
 **/
static bool Appl_Rdd_Process_Init(Radar_Look_T look_id)
{
   bool ret_val;

   Update_Rdd_Instrumentation_Variables();

   /* Call the initializations for the BBs here. */
   ret_val = Appl_Sweep_Bw_Init(look_id);
   ret_val = ret_val && Appl_Cfar_Init(look_id);
   ret_val = ret_val && Appl_Rdd_Fp_Init(look_id);
   ret_val = ret_val && Appl_Second_Pass_Init(look_id);
#ifdef CDC_ENABLE
   ret_val = ret_val && Appl_Cdc_Init(look_id);
#endif

   return ret_val;
}

/**
 *  @b Description
 *  @n
 *      Perform doppler and RDD pipelined processing.
 *
 *
 *  @retval retVal
 *      true for success, false for an error
 */

Appl_Doppler_Return_Values_T __attribute__((noinline)) Appl_Doppler_Rdd_Processing(Radar_Look_T look_id)
{
   Appl_Doppler_Return_Values_T appl_doppler_ret_val = APPL_DOPPLER_ERROR;

   bool doppler_proc_retval = true;
   bool firstpass_ret_val   = true;

   uint16_t rbin_idx                        = 0U;
   uint16_t rbin_idx_circ                   = rbin_idx % NCI_CIRCULAR_BUFF_DEPTH;
   DopplerProc_Input_T doppler_process_in   = {0};
   DopplerProc_Output_T doppler_process_out = {0};

   Ra_Helper_Error_T bbe32_irq_flag           = RA_HELPER_FAIL_ERROR;
   Doppler_Process_Error_T doppler_error_code = DOPPLER_PROCESS_NO_ERROR;
   Doppler_Process_Status_T doppler_status    = DOPPLER_PROCESS_ERROR;
   D2M_Msg_T *d2m_msg_ptr                     = Get_DP_RDD_IPC_D2M_Msg_Buffer();
   RDD_Data_T *p_rdd_data                     = &d2m_msg_ptr->payload.rdd_stream_data.rdd_data;
   DSP_Timing_Data_T *p_timing_data           = &d2m_msg_ptr->payload.dsp_timing_data;

   Stream_Hdr_T *p_stream_hdr       = &d2m_msg_ptr->payload.rdd_stream_data.stream_hdr;
   Stream_Hdr_T *p_debug_stream_hdr = &d2m_msg_ptr->payload.rdd_debug_data.stream_hdr;

   uint16_t rbin_idx_m1;
   uint16_t fp_detections_range_idx;

   uint32_t i;
   uint32_t doppler_rdd_runtime = 0U;

   //@TODO Keep this under the ITF only, i.e. bring back this if loop.
   // Currently we are commenting the If check , to resolve the Bexp oscillation issue
   // if (ITF_DATA_CUBE_INJECTION_MODE == Offline_Mode_Flag_DSP)
   //{
   Doppler_Min_Shift_Set(p_rdd_data->min_chirp_scaling);
   //}

   /* Initialize profiling for each module */
   PROFILE_MODULE_INIT(Doppler);
   PROFILE_MODULE_INIT(SweepBW);
   PROFILE_MODULE_INIT(FP);
   PROFILE_MODULE_INIT(Extract_NCI_Bexp);
   PROFILE_MODULE_INIT(CFAR);

   doppler_proc_start_timestamp = Timing_Helpers_Get_Timestamp();

   Circular_Buffer_Init();

#ifdef SPBB_SCM_ENABLE
   Reset_SCM_Internals(p_rdd_int_buff);
#endif

   doppler_proc_retval = Appl_Doppler_Process_Init(look_id) && Appl_Rdd_Process_Init(look_id);

   /* enable the RA and command queue*/
   if (doppler_proc_retval)
   {
      rbin_idx = RBIN0;

      doppler_process_in.rbin_idx               = rbin_idx;
      doppler_process_in.p_compressed_rfft_cube = &RangeProc_OutputDataCube;
      doppler_process_out.p_comp_bv_output      = dp_dfft_bv_output_buffer;
      doppler_process_out.p_nci_output          = dp_rdop_avg_nci_data;
      doppler_process_out.nci_bexp              = dp_nci_bexp;
      doppler_process_out.p_rest_bin_flag       = &rest_bin_flag;

      if (K_ENABLE_REST_PROC)
      {
         /*enable REST for all rbin*/
         (void)memset((uint8_t *)&rest_bin_flag[doppler_process_in.rbin_idx], 1U, sizeof(uint8_t) * (MAX_RANGE_BINS));
      }
      else
      {
         /*Do Nothing*/
      }
      PROFILE_MODULE_START(Doppler);
      /* Push the Command to execute in command queue.*/
      doppler_error_code =
         (Doppler_Process_Execute_RangeBin_Zero(&doppler_process_in, &doppler_process_out)); /* for zeroth rbin */

      /* Calculate first set of LUT for Sweep Bandwidth*/
      PROFILE_MODULE_START(SweepBW);
      Appl_Sweep_Bw_Execute(p_rdd_data);
      PROFILE_MODULE_STOP(SweepBW);

#pragma unroll
      for (i = 0U; i < NUM_INITIAL_RANGE_BINS; i++)
      {
         bbe32_irq_flag = Ra_Wait_Until_Done(DOPPLER_RA_MAX_RUN_TIME_US);
         PROFILE_MODULE_STOP(Doppler);
         Circular_Buffer_Update();

         if (bbe32_irq_flag != RA_HELPER_NO_ERROR)
         {
            rbin_idx = (uint16_t)(MAX_RANGE_BINS + 1U);
            Doppler_Proc_RA_Error_Count++;
            /* Set the doppler return flag false for an error in the RA */
            doppler_proc_retval = false;
            break;
         }
         else /* RA completed without error.*/
         {
            /* Do Nothing */
         }

         ++rbin_idx; /* range_idx = 1/ 2/ 3 */
         doppler_process_in.rbin_idx = rbin_idx;

         rbin_idx_m1 = (uint16_t)(rbin_idx - 1U);

         if (DOPPLER_PROCESS_NO_ERROR == doppler_error_code)
         {
            PROFILE_MODULE_START(Doppler);
            doppler_status = Doppler_Process_Execute(&doppler_process_in, &doppler_process_out);
         }

         rbin_idx_circ = rbin_idx_m1 % NCI_CIRCULAR_BUFF_DEPTH;

         PROFILE_MODULE_START(Extract_NCI_Bexp);
         Extract_Nci_Bexp_Output(&doppler_process_out, p_rdd_data, rbin_idx_circ, rbin_idx_m1);
         PROFILE_MODULE_STOP(Extract_NCI_Bexp);

         PROFILE_MODULE_START(CFAR);
         Appl_Cfar_Execute(rbin_idx_m1, p_rdd_data);
         PROFILE_MODULE_STOP(CFAR);
      }

      PROFILE_MODULE_START(FP);
      firstpass_ret_val = Appl_First_Pass_Execute(RBIN1,       /* Processing RDD FP for RBIN1 */
                                                  d2m_msg_ptr, /* D2M IPC pointer */
                                                  (BV_Comp_Type_T(*)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE]) &
                                                     (*dp_dfft_bv_output_buffer)[RBIN1 % BV_CIRCULAR_BUFF_DEPTH]);
      PROFILE_MODULE_STOP(FP);

      ++rbin_idx; /* range_idx = 4 */

      for (; rbin_idx <= LAST_RBIN_INDEX; ++rbin_idx)
      {
         bbe32_irq_flag = Ra_Wait_Until_Done(DOPPLER_RA_MAX_RUN_TIME_US);
         PROFILE_MODULE_STOP(Doppler);

         Circular_Buffer_Update();

         if (bbe32_irq_flag != RA_HELPER_NO_ERROR)
         {
            rbin_idx = (uint16_t)(MAX_RANGE_BINS + 1U);
            Doppler_Proc_RA_Error_Count++;
            /* Set the doppler return flag false for an error in the RA */
            doppler_proc_retval = false;
            break;
         }
         else /* RA completed without error.*/
         {
            /* Do Nothing */
         }

         fp_detections_range_idx = (uint16_t)(rbin_idx - 2U); /* Detections work 2 bins behind the doppler processing */
         rbin_idx_m1             = (uint16_t)(rbin_idx - 1U); /* cfar, transpose ops works 1 bin behind the doppler processing */
         rbin_idx_circ           = rbin_idx_m1 % NCI_CIRCULAR_BUFF_DEPTH;

         doppler_process_in.rbin_idx = rbin_idx;

         doppler_status = Doppler_Process_Execute(&doppler_process_in, &doppler_process_out); /* for all rbin */
         PROFILE_MODULE_STOP(Doppler);

         PROFILE_MODULE_START(Extract_NCI_Bexp);
         Extract_Nci_Bexp_Output(&doppler_process_out, p_rdd_data, rbin_idx_circ, rbin_idx_m1);
         PROFILE_MODULE_STOP(Extract_NCI_Bexp);

         PROFILE_MODULE_START(CFAR);
         Appl_Cfar_Execute(rbin_idx_m1, p_rdd_data);
         PROFILE_MODULE_STOP(CFAR);

         PROFILE_MODULE_START(FP);
         /* Provides rdop_avg_data_ptr parameter details to verify Integration Testing.
          * This section executes only when the Integration_Testing macro is enabled.
          */
         SIT_FP_OUTPUT_DATA(rdop_avg_data_ptr);

         firstpass_ret_val =
            Appl_First_Pass_Execute(fp_detections_range_idx, /* Processing RDD FP for fp_detections_range_idx */
                                    d2m_msg_ptr,             /* D2M IPC pointer */
                                    (BV_Comp_Type_T(*)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE]) &
                                       (*dp_dfft_bv_output_buffer)[fp_detections_range_idx % BV_CIRCULAR_BUFF_DEPTH]);

#ifdef SPBB_SCM_ENABLE
         p_rdd_data->rdd1_target_saturation_data.rdd1_targets_saturation_flag = p_rdd_int_buff->scm_targets_saturation_flag;
         p_rdd_data->rdd1_target_saturation_data.rdd1_max_rbin_processed      = p_rdd_int_buff->scm_max_rbin_processed;
         p_rdd_data->rdd1_target_saturation_data.rdd1_max_detectable_range    = p_rdd_int_buff->scm_max_detectable_range;
         p_rdd_data->rdd1_target_saturation_data.rdd1_scm_prioritization_flag = p_rdd_int_buff->scm_prioritization_flag;
#endif
         PROFILE_MODULE_STOP(FP);

         if ((Timing_Helpers_Get_Timestamp() - doppler_proc_start_timestamp) >= MAX_DOPPLER_PROC_OVERRUN_TIME_TICKS)
         {
            rbin_idx = (uint16_t)(MAX_RANGE_BINS + 1U);
            break;
         }
         else
         {
            /*Do Nothing*/
         }
      }

      if (MAX_RANGE_BINS == rbin_idx)
      {
         rbin_idx_circ = ((uint16_t)(MAX_RANGE_BINS - 1U)) % NCI_CIRCULAR_BUFF_DEPTH;

         bbe32_irq_flag = Ra_Wait_Until_Done(DOPPLER_RA_MAX_RUN_TIME_US);
         PROFILE_MODULE_STOP(Doppler);

         Circular_Buffer_Update();

         if (bbe32_irq_flag != RA_HELPER_NO_ERROR)
         {
            rbin_idx = (uint16_t)(MAX_RANGE_BINS + 1U);
            Doppler_Proc_RA_Error_Count++;
            /* Set the doppler return flag false for an error in the RA */
            doppler_proc_retval = false;
         }
         else /* RA completed without error.*/
         {
            /* continue with processing last bin */
            PROFILE_MODULE_START(Extract_NCI_Bexp);
            Extract_Nci_Bexp_Output(&doppler_process_out, p_rdd_data, rbin_idx_circ, (uint16_t)(MAX_RANGE_BINS - 1U));
            PROFILE_MODULE_STOP(Extract_NCI_Bexp);

            PROFILE_MODULE_START(CFAR);
            Appl_Cfar_Execute((uint16_t)(MAX_RANGE_BINS - 1U), p_rdd_data);
            PROFILE_MODULE_STOP(CFAR);

            PROFILE_MODULE_START(FP);
            firstpass_ret_val =
               Appl_First_Pass_Execute(SECOND_TO_LAST_RBIN, /* Processing RDD FP for SECOND_TO_LAST_RBIN */
                                       d2m_msg_ptr,         /* D2M IPC pointer */
                                       (BV_Comp_Type_T(*)[NUM_CDM_CHANNELS][MAX_DOPPLER_FFT_SIZE]) &
                                          (*dp_dfft_bv_output_buffer)[SECOND_TO_LAST_RBIN % BV_CIRCULAR_BUFF_DEPTH]);
            PROFILE_MODULE_STOP(FP);

            Circular_Buffer_Update();
         }
      }
      else
      {
         doppler_proc_retval = false;
      }

      PROFILE_MODULE_START(SP);
      Appl_Second_Pass_Execute(p_rdd_data);
      PROFILE_MODULE_STOP(SP);

      Doppler_Process_Done();
   }
   else
   {
      /* Mechanism to count errors in the initialization of doppler/RDD processing initialization */
      Doppler_Proc_Initialization_Fail_Count++;
   }

   /* Update the maximum execution time of the doppler/rdd processing. */
   doppler_rdd_runtime = Timing_Helpers_Get_Timestamp() - doppler_proc_start_timestamp;
   if (doppler_rdd_runtime > Doppler_Proc_Active_Ticks_Max)
   {
      Doppler_Proc_Active_Time_Max  = (uint32_t)Timing_Helpers_Get_Time_Microsec(doppler_rdd_runtime);
      Doppler_Proc_Active_Ticks_Max = doppler_rdd_runtime;
      p_timing_data->rdd_time       = Doppler_Proc_Active_Time_Max;
   }
   else
   {
      p_timing_data->rdd_time = (uint32_t)Timing_Helpers_Get_Time_Microsec(doppler_rdd_runtime);
   }

   if (doppler_rdd_runtime > MAX_DOPPLER_PROC_OVERRUN_TIME_TICKS)
   {
      Doppler_Proc_Overrun_Counter++;
      appl_doppler_ret_val = APPL_DOPPLER_TIMEOUT;
   }
   else if (!doppler_proc_retval)
   {
      appl_doppler_ret_val = APPL_DOPPLER_ERROR;
   }
   else
   {
      appl_doppler_ret_val = APPL_DOPPLER_NO_ERROR;
   }

   /** Update Diag information*/
   d2m_msg_ptr->payload.diag_data.ipc_m2d_buffer_err_cnt    = IPC_M2D_Buffer_Err_Cnt;
   d2m_msg_ptr->payload.diag_data.dfft_rdd_xput_overrun_cnt = Doppler_Proc_Overrun_Counter;

   /** Update RDD Stream header at the end.*/
   p_stream_hdr->module_time_ms       = p_timing_data->rdd_time;
   p_debug_stream_hdr->module_time_ms = p_timing_data->rdd_time;

   /* Providing d2m_msg_ptr info, for Integration Testing */
   SIT_D2M_MSG_BUFFER(d2m_msg_ptr);

   return appl_doppler_ret_val;
}
