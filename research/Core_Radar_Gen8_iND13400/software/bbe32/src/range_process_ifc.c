/*===========================================================================*/
/**
 * @file range_process_ifc.c
 *
 * Application interface mapping for Range Process module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2023 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Range Process module
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
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "mipi_ifc.h"
#include "range_process.h"
#include "range_process_ifc.h"
#include "range_process_types.h"
#include "xcp_adc_logging.h"

#include "api/mipi_helpers.h"
#include "api/profiling_helpers.h"
#include "api/ra_helpers.h"
#include "api/timing_helpers.h"

#include "ipc_dsp.h"
#include "smc_cal.h"
#include "spbb_math.h"
#ifdef __XTENSA__
   #include <xtensa/config/core.h>
   #include <xtensa/hal.h>
   #include <xtensa/tie/xt_bbe32.h>
   #include <xtensa/tie/xt_bben.h>
   #include <xtensa/tie/xt_ioports.h>
   #include <xtensa/xtruntime.h>
#else
   #include "core-macros.h"
#endif

#include "dss_ecc_parity.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
/* Convert the expected chirping time to microseconds */
#define FLOAT_MS_TO_UINT32_US(x) ((uint32_t)((x)*1000.0F))

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
#ifdef ENABLE_CHIRP_PROFILING_INFO
typedef struct Range_Process_Chirp_Cycles_Tag
{
   uint32_t callback_cycles;
   uint32_t initial_chirp_cycles;
   uint32_t other_chirp_cycles_max;
   uint32_t last_chirp_cycles;
   uint32_t other_chirp_timestamp;
   uint32_t ra_processing_cycles; // Number of cycles since MIPI chirp end interrupt - approximate processing time of RA
   uint32_t config_time_cycles;
} Range_Process_Chirp_Cycles_T;

typedef struct Range_Process_Chirp_Timing_Tag
{
   float32_t callback_time_us;
   float32_t initial_chirp_time_us;
   float32_t other_chirps_max_time_us;
   float32_t last_chirp_time_us;
   float32_t ra_processing_time_avg_us;
   float32_t config_time_us;
} Range_Process_Chirp_Timing_T;
#endif

typedef enum Appl_Range_Process_Status_Tag
{
   APPL_RANGE_PROCESS_IDLE = 0,
   APPL_RANGE_PROCESS_RUNNING,
   APPL_RANGE_PROCESS_COMPLETE_ERROR,
   APPL_RANGE_PROCESS_COMPLETE_SUCCESS,
} Appl_Range_Process_Status_T;

typedef struct Range_Process_Info_Tag
{
   uint16_t chirp_callback_cnt;
   uint16_t expected_num_chirps;
   uint32_t error_count;
   Range_Process_Status_T bb_status;
   Range_Process_Status_T bb_status_mipi_chirp_end;
   Appl_Range_Process_Status_T status;

#ifdef ENABLE_CHIRP_PROFILING_INFO
   Range_Process_Chirp_Timing_T chirp_timing;
#endif

   Range_Process_Error_T execute_error_return;
   ProfilingStruct_t profiling_info;
   uint32_t last_chirp_timestamp;
} Range_Process_Info_T;

typedef struct ADC_Offline_Data_Tag
{
   volatile int16_t chirp_data[SPBB_MAX_SAMPLES * NUM_RX_CHANNELS];
   volatile uint32_t data_ready;
   uint32_t debug_counter;
} ADC_Offline_Data_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
uint32_t __attribute__((section(".sram1.bss"))) __attribute__((aligned(64)))
RangeProc_OutputDataCube[COMP_RFFT_CUBE_SIZE_IN_32BIT_WORDS][K_MAX];
// uint16_t __attribute__((section(".sram1.bss"))) RangeProc_NCI_Accum[MAX_RANGE_FFT_SIZE >> 1];
Bexp_Output_T __attribute__((section(".sram1.bss"))) RangeProc_Bexp;

uint32_t __attribute__((section(".sram1.bss"))) __attribute__((aligned(32))) dummy_array[16];

volatile Range_Process_Info_T Appl_Range_Variables = {
   .chirp_callback_cnt       = 0,
   .expected_num_chirps      = 0,
   .bb_status                = RANGE_PROCESS_NUMBER_STATUS,
   .bb_status_mipi_chirp_end = RANGE_PROCESS_NUMBER_STATUS,
   .status                   = APPL_RANGE_PROCESS_IDLE,
   .execute_error_return     = 0,
   .profiling_info           = {0},
   .last_chirp_timestamp     = 0,
};

/* This is used in ADC offline injection - marked as volatile, since the Lauterbach will interact with this pointer. */
volatile ADC_Offline_Data_T *Offline_Data_Injection_Ptr = NULL;
uint16_t Range_Proc_Overrun_Counter                     = 0U;
static uint32_t Range_Processing_Done_Timestamp         = 0U;
volatile uint32_t Mipi_Stat_Processing_Time             = 0;
#ifdef ENABLE_CHIRP_PROFILING_INFO
volatile Range_Process_Chirp_Cycles_T Appl_Range_Chirp_Cycles;
#endif

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
void ADC_Offline_Injection_Handler(Mem_Pool_T *mem_pool);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
#ifdef ENABLE_CHIRP_PROFILING_INFO
/**
 *  @b Description
 *  @n
 *      Update the chirp cycle counts based on the current chirp number/or completion of the frame.
 *
 *  @retval
 *      Returns void
 */
static inline void Update_Per_Chirp_Cycles(uint32_t chirp_timestamp)
{
   if (Appl_Range_Variables.chirp_callback_cnt == 1) // Initial chirp
   {
      Appl_Range_Chirp_Cycles.initial_chirp_cycles   = chirp_timestamp - Appl_Range_Variables.profiling_info.startTimestamp;
      Appl_Range_Chirp_Cycles.other_chirp_cycles_max = 0;
      Appl_Range_Chirp_Cycles.callback_cycles        = 0;
   }
   else if (Appl_Range_Variables.bb_status == RANGE_PROCESS_COMPLETE)
   {
      Appl_Range_Chirp_Cycles.last_chirp_cycles = chirp_timestamp - Appl_Range_Chirp_Cycles.other_chirp_timestamp;
   }
   else
   {
      uint32_t chirp_cycles = chirp_timestamp - Appl_Range_Chirp_Cycles.other_chirp_timestamp;

      if (chirp_cycles > Appl_Range_Chirp_Cycles.other_chirp_cycles_max)
      {
         Appl_Range_Chirp_Cycles.other_chirp_cycles_max = chirp_cycles;
      }
   }

   Appl_Range_Chirp_Cycles.other_chirp_timestamp = chirp_timestamp;
}

/**
 *  @b Description
 *  @n
 *      Update the chirp timing for readability in microseconds.
 *
 *  @retval
 *      Returns void
 */
static inline void Update_Per_Chirp_Timing(void)
{
   volatile Range_Process_Chirp_Timing_T *chirp_timing = &Appl_Range_Variables.chirp_timing;

   chirp_timing->callback_time_us          = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.callback_cycles);
   chirp_timing->initial_chirp_time_us     = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.initial_chirp_cycles);
   chirp_timing->other_chirps_max_time_us  = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.other_chirp_cycles_max);
   chirp_timing->last_chirp_time_us        = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.last_chirp_cycles);
   chirp_timing->ra_processing_time_avg_us = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.ra_processing_cycles) *
                                             get_recip(Appl_Range_Variables.chirp_callback_cnt);
   chirp_timing->config_time_us = Timing_Helpers_Get_Time_Microsec(Appl_Range_Chirp_Cycles.config_time_cycles);
}
#endif
/**
 *  @b Description
 *  @n
 *      While below rfft designated time, this is expected to be false.
 *
 * @param[in] mem_pool - Pointer to memory pool. Used for ADC offline injection purpose.
 *
 *  @retval
 *      Returns TRUE if either error or timeout, FALSE if running and not errored out.
 */
Appl_Range_Return_Values_T Check_For_Range_Process_Complete_Timeout_Check(Mem_Pool_T *mem_pool)
{
   volatile RDD_Data_T *p_rdd_data  = &Get_RP_IPC_D2M_Msg_Buffer()->payload.rdd_stream_data.rdd_data;
   uint16_t look_type               = Get_RP_IPC_D2M_Msg_Buffer()->payload.rdd_stream_data.look_data.look_id;
   DSP_Timing_Data_T *p_timing_data = (DSP_Timing_Data_T *)&Get_RP_IPC_D2M_Msg_Buffer()->payload.dsp_timing_data;
   ProfilingStruct_t *p_chirp_time  = (ProfilingStruct_t *)(uintptr_t)&p_timing_data->range_process_time;
   uint32_t start_timestamp         = Appl_Range_Variables.profiling_info.startTimestamp;
   uint32_t range_process_run_time_us =
      (uint32_t)Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - start_timestamp);
   volatile Range_Process_Timing_Debug_T *rdd_debug_data_ptr =
      &Get_RP_IPC_D2M_Msg_Buffer()->payload.rdd_debug_data.rdd_data.appl_range_process_debug;
   volatile Diag_Data_T *diag_data_ptr  = &Get_RP_IPC_D2M_Msg_Buffer()->payload.diag_data;
   Appl_Range_Return_Values_T ret_value = APPL_RANGE_ERROR;
   uint32_t timeout_in_us               = RANGE_PROCESSING_TIMEOUT_US;
   uint32_t range_process_idle_time_us  = 0U;
   uint32_t num_bins_done               = 0;

   if (look_type < NUM_LOOKS)
   {
      timeout_in_us = FLOAT_MS_TO_UINT32_US(k_frame_dwell_ms_smc[look_type]);
      timeout_in_us += MAX_ALLOWED_CHIRP_TIME_INCREASE_US;
   }
   else
   {
      /* Leave as default timeout */
      timeout_in_us = RANGE_PROCESSING_TIMEOUT_US;

      /* Set look_type to a valid look */
      look_type = RADAR_LOOK_A;
   }

   if (ITF_ADC_INJECTION_MODE == Offline_Mode_Flag_DSP)
   {
      ADC_Offline_Injection_Handler(mem_pool);

      while (Appl_Range_Variables.bb_status != RANGE_PROCESS_COMPLETE)
      {
         /* Waiting for the final interrupt to trigger
            This wait prevents the timeout from being triggered. */
      }

      num_bins_done = Appl_Range_Variables.chirp_callback_cnt; // No idle time in ADC injection mode.
   }
   else
   {
      uint32_t idle_start_timestamp = Timing_Helpers_Get_Timestamp();
      uint32_t interrupt_status     = 0U;

      /* Disable Interrupts*/
      interrupt_status = xthal_disable_interrupts();

      /* Read the number of chirps processed to this point */
      num_bins_done = Appl_Range_Variables.chirp_callback_cnt;

      /* Restore interrupts */
      xthal_restore_interrupts(interrupt_status);

      while (range_process_run_time_us < timeout_in_us && Appl_Range_Variables.bb_status != RANGE_PROCESS_COMPLETE)
      {
         range_process_run_time_us = (uint32_t)Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - start_timestamp);
      }

      range_process_idle_time_us =
         (uint32_t)Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - idle_start_timestamp);
   }

   /* Set the range processing done time before proceeding. */
   Range_Processing_Done_Timestamp = Timing_Helpers_Get_Timestamp();

   xtos_interrupt_disable(RA_CMD_DONE_ISR);
   xtos_interrupt_clear(RA_CMD_DONE_ISR);
   Ra_Enable_Cmd_Done_Interrupt(false);
   Ra_Clear_Cmd_Done_Irq_Bbe32_Func_Flag();

   Range_Process_Done();

   p_rdd_data->min_chirp_scaling = (uint8_t)Ra_Get_Min_Chirp_Scale_Value();

#ifdef ENABLE_CHIRP_PROFILING_INFO
   Update_Per_Chirp_Timing();

   // Subtract the total time spent handling the callbacks from the idle time to get the actual idle time.
   range_process_idle_time_us -=
      (Appl_Range_Variables.chirp_timing.callback_time_us) * (Appl_Range_Variables.chirp_callback_cnt - num_bins_done);
#else
   // If chirp profiling is not enabled, approximate the total time spent handling callbacks and subtract from the idle time to get
   // an approximate idle time.
   range_process_idle_time_us -= 1000U * (Appl_Range_Variables.chirp_callback_cnt - num_bins_done);
#endif

   if (Appl_Range_Variables.bb_status == RANGE_PROCESS_COMPLETE)
   {
      uint32_t time_start         = Timing_Helpers_Get_Timestamp();
      Appl_Range_Variables.status = APPL_RANGE_PROCESS_COMPLETE_SUCCESS;
      Appl_IDM_Stat_Process((Radar_Look_T)look_type);
      Mipi_Stat_Processing_Time = (uint32_t)Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - time_start);

#if ENABLE_ADC_DATA_LOGGING == (1U)
      Post_Process_ADC_Data_Buffer();
#endif

      p_timing_data->range_process_idle_time = range_process_idle_time_us;

      ret_value = APPL_RANGE_NO_ERROR;

      Profiling_Helpers_Update_Manual((ProfilingStruct_t *)(uintptr_t)&Appl_Range_Variables.profiling_info,
                                      Appl_Range_Variables.last_chirp_timestamp);
      if ((ITF_ADC_INJECTION_MODE != Offline_Mode_Flag_DSP) && (Appl_Range_Variables.profiling_info.lastRuntime >= timeout_in_us))
      {
         /* If the timeout for range processing is exceeded, set the timeout error. */
         ret_value = APPL_RANGE_TIMEOUT;
         Range_Proc_Overrun_Counter++;
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      Profiling_Helpers_Update((ProfilingStruct_t *)(uintptr_t)&Appl_Range_Variables.profiling_info);
      /* If the bb_status is not complete, set the generic error. */
      ret_value = APPL_RANGE_ERROR;

      Range_Proc_Overrun_Counter++;
   }

   p_chirp_time->lastRuntime    = Appl_Range_Variables.profiling_info.lastRuntime;
   p_chirp_time->averageRuntime = Appl_Range_Variables.profiling_info.averageRuntime;
   p_chirp_time->maxRuntime     = Appl_Range_Variables.profiling_info.maxRuntime;

   if (ret_value != APPL_RANGE_NO_ERROR)
   {
      Ra_Reset_Req();

      /* Enable ESTMEM ECC interrupt */
      RA_ESTMEM_ECC_Enable();

      Appl_Range_Variables.status = APPL_RANGE_PROCESS_COMPLETE_ERROR;
   }
   else
   {
      /* Do Nothing */
   }

   // If an error occurred, clear the max time.
   if (APPL_RANGE_PROCESS_COMPLETE_ERROR == Appl_Range_Variables.status)
   {
      Appl_Range_Variables.profiling_info.maxRuntime = 0;
   }
   else
   {
      /* Do nothing */
   }

   /* TODO: These are additional debug information that can be removed. */
   rdd_debug_data_ptr->appl_range_variables_chirp_callback_cnt   = Appl_Range_Variables.chirp_callback_cnt;
   rdd_debug_data_ptr->appl_range_variables_error_count          = Appl_Range_Variables.error_count;
   rdd_debug_data_ptr->appl_range_variables_bb_status            = Appl_Range_Variables.bb_status;
   rdd_debug_data_ptr->appl_range_variables_status               = Appl_Range_Variables.status;
   rdd_debug_data_ptr->appl_range_variables_execute_error_return = Appl_Range_Variables.execute_error_return;
   rdd_debug_data_ptr->appl_range_variables_last_runtime         = Appl_Range_Variables.profiling_info.lastRuntime;
   rdd_debug_data_ptr->idm_timing_last_runtime                   = Mipi_Stat_Processing_Time;
   rdd_debug_data_ptr->mipi_chirp_count                          = Get_MIPI_Chirp_Count();
#ifdef ENABLE_CHIRP_PROFILING_INFO
   rdd_debug_data_ptr->initial_chirp_time_us     = Appl_Range_Variables.chirp_timing.initial_chirp_time_us;
   rdd_debug_data_ptr->other_chirps_max_time_us  = Appl_Range_Variables.chirp_timing.other_chirps_max_time_us;
   rdd_debug_data_ptr->last_chirp_time_us        = Appl_Range_Variables.chirp_timing.last_chirp_time_us;
   rdd_debug_data_ptr->ra_processing_time_avg_us = Appl_Range_Variables.chirp_timing.ra_processing_time_avg_us;
   rdd_debug_data_ptr->config_time_us            = Appl_Range_Variables.chirp_timing.config_time_us;
#else
   rdd_debug_data_ptr->initial_chirp_time_us     = 0.0F;
   rdd_debug_data_ptr->other_chirps_max_time_us  = 0.0F;
   rdd_debug_data_ptr->last_chirp_time_us        = 0.0F;
   rdd_debug_data_ptr->ra_processing_time_avg_us = 0.0F;
   rdd_debug_data_ptr->config_time_us            = 0.0F;
#endif

   diag_data_ptr->rfft_xput_overrun_cnt = Range_Proc_Overrun_Counter;

   return ret_value;
}

/**
 *  @b Description
 *  @n
 *      Handler for command done interrupt callback. Clears the command done flag to bbe, Pushes command for next chirp in the
 * queue,
 *
 *  @retval
 *      Returns void
 */
void Appl_Range_Process_Chirp_Callback(void *arg)
{
   (void)arg;
   uint32_t start_time = Timing_Helpers_Get_Timestamp();

#ifdef ENABLE_CHIRP_PROFILING_INFO
   uint32_t cycles = 0;
   Appl_Range_Chirp_Cycles.ra_processing_cycles +=
      (start_time - Get_MIPI_Chirp_End_Timestamp(Appl_Range_Variables.chirp_callback_cnt));
#endif

   Ra_Clear_Cmd_Done_Irq_Bbe32_Func_Flag();
   xtos_interrupt_clear(RA_CMD_DONE_ISR);

   Appl_Range_Variables.chirp_callback_cnt++;

   if (Appl_Range_Variables.chirp_callback_cnt == Appl_Range_Variables.expected_num_chirps)
   {
      Appl_Range_Variables.bb_status = Appl_Range_Variables.bb_status_mipi_chirp_end;
   }

   if (Appl_Range_Variables.bb_status == RANGE_PROCESS_COMPLETE)
   {
#if ENABLE_ADC_DATA_LOGGING == (1U)
      Invalidate_ADC_XCP_Cache(); /* CM10 wrote via DMA after Call 1 cached this slot — must invalidate */
#endif
      XCP_Logging_Handler();
      Appl_Range_Variables.last_chirp_timestamp = start_time;
   }

#ifdef ENABLE_CHIRP_PROFILING_INFO
   Update_Per_Chirp_Cycles(Timing_Helpers_Get_Timestamp());
   cycles = Timing_Helpers_Get_Timestamp() - start_time;

   if (cycles > Appl_Range_Chirp_Cycles.callback_cycles)
   {
      Appl_Range_Chirp_Cycles.callback_cycles = cycles;
   }
   else
   {
      /* Do Nothing */
   }
#endif
}

/**
 *  @b Description
 *  @n
 *      Handler for RA Queue population callback. Pushes command for next chirp in the
 * queue,
 *
 *  @retval
 *      Returns void
 */
void Appl_Range_Process_Push_Ra_Commands(void)
{
   /* Added so that BBE does not read back stale data, every chirp */
#if ENABLE_ADC_DATA_LOGGING == (1U)
   Invalidate_ADC_XCP_Cache();
#endif
   Appl_Range_Variables.bb_status_mipi_chirp_end = Process_Chirp_Callback();
}
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/**
 *  @b Description
 *  @n Perform Range Processing Init and Execute
 *
 * @param[in] look_type - look id to configure for processing
 *
 * @retval
 * bool ret_val -> true for success, False for failure
 *
 */
bool Appl_Range_Process_Init(Radar_Look_T look_type)
{
   bool app_init_retval = false;

   RangeProc_Config_T range_process_cfg = {0};
   RangeProc_Input_T range_process_in   = {0};
   RangeProc_Output_T range_process_out = {0};

#ifdef ENABLE_CHIRP_PROFILING_INFO
   uint32_t start_time                          = Timing_Helpers_Get_Timestamp();
   Appl_Range_Chirp_Cycles.ra_processing_cycles = 0;
#endif

   Appl_Mipi_Idm_Config(look_type);

   Appl_Range_Variables.chirp_callback_cnt  = 0;
   Appl_Range_Variables.expected_num_chirps = K_FRAME[look_type];

   Profiling_Helpers_Init((ProfilingStruct_t *)(uintptr_t)&Appl_Range_Variables.profiling_info, false);

   range_process_cfg.num_adc_samples = M_FRAME[look_type];
   range_process_cfg.fft_size        = MAX_RANGE_FFT_SIZE;
   range_process_cfg.used_fft_bins   = MAX_RANGE_BINS;
   range_process_cfg.num_chirps      = K_FRAME[look_type];
   // need configur with smc data
   range_process_cfg.range_window_data = &(k_range_window_smc[look_type][0]);

   // preprocessor's comparator scaling is used to obtain the FDDT threshold
   // i.e. fddt_threshold_multiplier*RIDM threshold
   range_process_cfg.prep_gain =
      (uint16_t)(k_fddt_threshold_multiplier_smc[look_type] * k_ridm_frequency_domain_multiplier_smc[look_type]);
   range_process_cfg.prep_div          = M_FRAME[look_type];
   range_process_cfg.posp_gain         = k_ridm_frequency_domain_multiplier_smc[look_type];
   range_process_cfg.posp_div          = M_FRAME[look_type];
   range_process_cfg.num_segments_ridm = k_ridm_frequency_domain_segments_smc[look_type];
   range_process_cfg.enable_fddt       = k_fddt_enable_smc;

   Range_Process_Init(&range_process_cfg);

#if ENABLE_ADC_DATA_LOGGING == (1U)
   Configure_ADC_XCP_Output();
#endif

   Ra_Clear_Cmd_Done_Irq_Bbe32_Func_Flag();
   Ra_Enable_Cmd_Done_Interrupt(true);
   xtos_interrupt_clear(RA_CMD_DONE_ISR);
   xtos_interrupt_enable(RA_CMD_DONE_ISR);

   Appl_Range_Variables.bb_status = RANGE_PROCESS_NOT_COMPLETE;

   range_process_in.rfft_adc_inp_ptr = (int16_t *)MIPI_OCP_MEM_base;
   range_process_in.chirp_idx        = 0U;

   range_process_out.rfft_output_ptr = &RangeProc_OutputDataCube[0][0];
   // range_process_out.nci_accumulation = (int16_t *)&RangeProc_NCI_Accum[0];
   range_process_out.bexp_value       = &RangeProc_Bexp;
   range_process_out.dummy_output_ptr = (uint32_t(*)[16]) & dummy_array[0];

   Appl_Range_Variables.execute_error_return = Range_Process_Execute(&range_process_in, &range_process_out);

   app_init_retval = (RANGE_PROCESS_NO_ERROR == Appl_Range_Variables.execute_error_return);

   if (app_init_retval)
   {
      Appl_Range_Variables.status = APPL_RANGE_PROCESS_RUNNING;
   }
   else
   {
      /* Do Nothing */
   }

#ifdef ENABLE_CHIRP_PROFILING_INFO
   Appl_Range_Chirp_Cycles.config_time_cycles = Timing_Helpers_Get_Timestamp() - start_time;
#endif

   return app_init_retval;
}

/**
 *  @b Description
 *  @n
 *
 * @param[in] mem_pool - Pointer to memory pool for use as communicating with Trace32
 *
 * @retval N/A
 *
 */
void __attribute__((section(".sram0.text"))) __attribute__((noinline)) ADC_Offline_Injection_Handler(Mem_Pool_T *mem_pool)
{
   uint32_t chirp_idx;
   Radar_Look_T look_id = Get_DP_RDD_IPC_D2M_Msg_Buffer()->payload.rdd_stream_data.look_data.look_id;
   uint32_t num_chirps  = K_FRAME[look_id];
   uint32_t num_samples = M_FRAME[look_id];

   Mem_Pool_Alloc(mem_pool, sizeof(*Offline_Data_Injection_Ptr), (void **)(uintptr_t)&Offline_Data_Injection_Ptr);

   Offline_Data_Injection_Ptr->data_ready = 0x55AA;

   for (chirp_idx = 0; chirp_idx < num_chirps; chirp_idx++)
   {
      while (XT_L32AI(&Offline_Data_Injection_Ptr->data_ready, 0) != 0xAA55)
      {
         /* Waiting for the Lauterbach to write the data and set data valid. */
         Offline_Data_Injection_Ptr->debug_counter++;
      }

      Mipi_Debugmode_Write_Chirp(&Offline_Data_Injection_Ptr->chirp_data[0],
                                 (uint16_t)(num_samples * NUM_RX_CHANNELS * sizeof(uint16_t)), (uint16_t)num_samples,
                                 NUM_RX_CHANNELS);

      Offline_Data_Injection_Ptr->data_ready    = 0x55AA;
      Offline_Data_Injection_Ptr->debug_counter = 0;
   }

   while (XT_L32AI(&Offline_Data_Injection_Ptr->data_ready, 0) != 0xAA55)
   {
      /* Waiting for the Lauterbach to write the data and set data valid. */
      Offline_Data_Injection_Ptr->debug_counter++;
   }

   Mem_Pool_Reset(mem_pool);
}

/**
 *  @b Description
 *  @n
 *      Get the timestamp for when range processing completed chirps.
 *      This is immediately after the chirping is done, before any
 *      significant processing is done.
 *
 *  @retval
 *      N/A
 */
uint32_t Get_Range_Procesing_Done_Time(void)
{
   return Range_Processing_Done_Timestamp;
}
