/**
 * @file main_application.c
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Main DSP application state machine implementation.
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *   - Requirements Document(s):
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 * @section DFS DEVIATIONS FROM STANDARDS:
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/* ========================================================================== */
/*                             Include Filsdes                                  */
/* ========================================================================== */
#include "main_application.h"
#include "api/mipi_helpers.h"
#include "api/profiling_helpers.h"
#include "api/ra_helpers.h"
#include "api/sysmem_helpers.h"
#include "api/timing_helpers.h"
#include "fusa_bbe_self_test.h"

#include <string.h>

#include "Ra_fault_injection.h"
#if defined(FEATURE_ENABLE)
   #include "Rte_SWC_PLT_Appl_Communication.h"
#endif
#include "afbb_cfg.h"
#include "angle_finding_interface.h"
#include "angle_finding_project_interface.h"
#include "bbe32_static_register_validation.h"
#include "chandra_sfrs_base.h"
#include "doppler_process_ifc.h"
#include "dss_ecc_parity.h"
#include "dyn_align_wrapper.h"
#include "interference_detection_algo_interface.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "mem_pool.h"
#include "mipi_ifc.h"
#include "performance_monitor_ifc.h"
#include "radar_data_quality.h"
#include "range_process.h"
#include "range_process_ifc.h"
#include "rc_wrapper.h"
#include "sh_module_cfg.h"
#include "static_align_wrapper.h"
#include "xcp_adc_logging.h"
#include <xtensa/tie/xt_ioports.h>
#include <xtensa/xtruntime.h>

#if DOWNSELECTION_ENABLE
   #include "toi_ds_stream.h"
#else
   #include "toi_stream.h"
#endif

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "dsp_it_macros_test.h"

#ifdef TRACKER_ENABLED
   #include "emb_tracker_wrapper.h"
#endif

#if defined(FEATURE_ENABLE)
   #include "OLP_wrapper.h"
   #include "SFL_Wrapper.h"
#endif

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#if (DOWNSELECTION_ENABLE)
   #define TOI_RADAR_DATA_STATUS_T TOI_Radar_Data_Status_Payload_DS_T
#else
   #define TOI_RADAR_DATA_STATUS_T TOI_Radar_Data_Status_Payload_T
#endif

/**
 * @brief Set the size of the shared memory pool.
 */
#define MEMORY_POOL_DRAM1_ALLOCATION_BYTES (61 * 1024)
#define MEMORY_POOL_SRAM1_ALLOCATION_BYTES (180 * 1024)
/**
 * @brief Set the longest expected frame time, used to reset overall application timer max
 */
#define MAX_OVERALL_FRAME_TIME_US (100000U) /* 100ms */

/**
 * @brief BBE32 poll timeout for HIL Rx complete flag.
 *        = MAX_DOPPLER_PROC_OVERRUN_TIME_US − 5 ms safety margin.
 */
#define MAX_HIL_RX_COMPLETE_WAIT_TIME_US (MAX_DOPPLER_PROC_OVERRUN_TIME_US - 5000U)

   /* ========================================================================== */
   /*                         Type Definitions                                   */
   /* ========================================================================== */
   typedef DSP_Main_Application_State_T (*state_machine_handler)(void);

   typedef struct
   {
      DSP_Main_Application_State_T state;
      state_machine_handler handler;
   } StateMachine_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined(FEATURE_ENABLE)
   L2_MOIS_Feature_Degradation_Flags_T L2_MOIS_Feature_Degradation_Flags;
   L2_BSIS_Feature_Degradation_Flags_T L2_BSIS_Feature_Degradation_Flags;
   uint8_t Final_MOIS_Degrade_Flag = CODED_FALSE;
   uint8_t Final_BSIS_Degrade_Flag = CODED_FALSE;
#endif

#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
   /** These are not defined as static, so that they are not flagged in error as set but unused.
    **/
   typedef struct
   {
      DSP_Main_Application_State_T state;
      ProfilingStruct_t profilingStruct;
      uint32_t count;
   } ProfilingInfo_t;

   ProfilingInfo_t __attribute__((section(".sram1.data"))) MainApplication_ProfilingInfo[NUM_PROCESSING_STATES] = {
      {INIT, {0}, 0},
      {IDLE, {0}, 0},
      {RANGE_PROCESSING, {0}, 0},
      {DOPPLER_AND_RDD_PROCESSING, {0}, 0},
      {FUSA_BBE_SELF_TEST_PROCESSING, {0}, 0},
      {ANGLE_FINDING_PROCESSING, {0}, 0},
      {INTERFERENCE_DETECTION_PROCESSING, {0}, 0},
      {RADAR_CAPABILITY_PROCESSING, {0}, 0},
      {TOI_ALIGNMENT_PROCESSING, {0}, 0},
      {TRACKER_PROCESSING, {0}, 0},
      {FEATURE_PROCESSING, {0}, 0},
      {SIGPROC_POST_PROCESSING, {0}, 0},
      {SIGPROC_POST_PROCESSING_ERROR, {0}, 0},
   };

   ProfilingStruct_t MainApplication_ProfilingInfo_Overall = {0};

   typedef struct
   {
      /* Data latency from RFFT Middle of dwell to Angle finding + Radar Cap end*/
      uint32_t rfft_mod_to_af_latency;

      /* Data latency from RFFT Middle of dwell to DFFT-RDD end*/
      uint32_t rfft_mod_to_dfft_rdd_latency;

      /* Total time of RFFT + DFFT */
      uint32_t rfft_dfft_total_time;

      /* Total time of DFFT + AF + Radar Cap */
      uint32_t dfft_af_total_time;

   } BBE_Timing_Info_T;

   volatile BBE_Timing_Info_T BBE_Instant_Times = {0};
   volatile BBE_Timing_Info_T BBE_Peak_Times    = {0};
#endif

   /* Memory Pool structures for managing shared memory across the states. */
   static Mem_Pool_T Memory_Pool_Dram1 = {0};
   static Mem_Pool_T Memory_Pool_Sram1 = {0};

   /** Shared memory buffers for use across states.
    *  Allows for memory reuse in components that run in mutually
    *  exclusive times, e.g. RDD and AF.
    *
    *  @note Range processing and AF cannot both use these memory sections!
    *        These memory sections should be aligned to 128 bytes for FuSa BBE Self Test.
    *
    *        SRAM buffer is aligned to 256 bytes to align with cache line size. The buffers allocated
    *        in this memory pool must not overlap with other buffers that might cause cache coherency issues.
    **/
   static __attribute__((aligned(128))) __attribute__((section(".dram1.bss")))
   int8_t Memory_Pool_Allocation_dram1[MEMORY_POOL_DRAM1_ALLOCATION_BYTES];
   static __attribute__((aligned(256))) __attribute__((section(".sram1.bss")))
   int8_t Memory_Pool_Allocation_sram1[MEMORY_POOL_SRAM1_ALLOCATION_BYTES];
   uint16_t Doppler_Process_Error_Cnt     = 0U;
   uint16_t Range_Process_Error_Cnt       = 0U;
   static uint16_t DSP_Current_Look_Index = 0U;

   static uint8_t Range_Process_Error_Status         = CODED_FALSE;
   static uint8_t Doppler_Process_Timeout_Error_Flag = CODED_FALSE;

   ID_INPUT_T Id_Input_Data;

   /* AF Error Flags for lauterbach debugging */
   static __attribute__((used)) uint16_t Angle_Finding_Process_Error_Cnt     = 0U;
   static __attribute__((used)) AF_Retval_T Angle_Finding_Process_Last_Error = AF_E_OK;

   /* Bypass flags are added for lauterbach debugging*/
   static __attribute__((used)) bool HIL_Alignment_Algo_Bypass        = false;
   static __attribute__((used)) bool HIL_TOI_Algo_Bypass              = false;
   static __attribute__((used)) bool HIL_RC_Algo_Bypass               = false;
   static __attribute__((used)) bool HIL_Scan_Index_Updated_To_RDD    = false;
   static __attribute__((used)) uint8_t HIL_Bypass_Doppler_Processing = CODED_FALSE;
   static __attribute__((used)) uint16_t HIL_Rx_Complete_Timeout_Cnt  = 0U;

   /*===========================================================================*
    * Local Function Prototypes
    *===========================================================================*/
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Init_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Idle_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Wait_For_Rfft_Complete_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Doppler_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Fusa_BBE_Self_Test_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Anglefinding_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Interference_Detection_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Radar_Performance_Degradation_Monitor_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) TOI_Alignment_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Tracker_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) Feature_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) SP_Post_Proc_Complete_Handler(void);
   static DSP_Main_Application_State_T __attribute__((section(".sram0.text"))) SP_Post_Proc_Complete_Error_Handler(void);
   static void __attribute__((section(".sram0.text"))) Update_Frame_Timing(void);
   static void Set_Current_Lookindex(void);
   static void Update_Timestamp_Data(void);
   static uint8_t Wait_For_HIL_Rx_Complete(void);
   static void Delay_Millisec(uint32_t delay_ms);
   /*===========================================================================*
    * Function Definitions
    *===========================================================================*/
   /**
    *  @b Description
    *  @n
    *      Get the Current Look Index.
    *
    *  @param[in]
    *
    *  @retval
    *      uint16_t.
    */
   uint16_t Get_Current_Lookindex(void)
   {
      return DSP_Current_Look_Index;
   }

   /**
    *  @b Description
    *  @n
    *      Increments the Current Look Index for every successful range acquisition.
    *
    *  @param[in]
    *
    *  @retval
    *      void
    */
   static void Set_Current_Lookindex(void)
   {
      DSP_Current_Look_Index++;
   }

   /**
    *  @b Description
    *  @n
    *      Initialization state handler. Called only one time.
    *
    *  @retval
    *      Returns IDLE state as the next state to transition to.
    */
   static DSP_Main_Application_State_T Init_Handler(void)
   {
      DSP_Main_Application_State_T new_state = IDLE;
      Memory_Pool_Return_T dram1_pool_result;
      Memory_Pool_Return_T sram1_pool_result;

      /* If the Mem_Pool_Init fails, stay in the INIT state. */
      dram1_pool_result = Mem_Pool_Init(&Memory_Pool_Dram1, Memory_Pool_Allocation_dram1, MEMORY_POOL_DRAM1_ALLOCATION_BYTES);
      sram1_pool_result = Mem_Pool_Init(&Memory_Pool_Sram1, Memory_Pool_Allocation_sram1, MEMORY_POOL_SRAM1_ALLOCATION_BYTES);
      if ((MEM_POOL_SUCCESS == dram1_pool_result) && (MEM_POOL_SUCCESS == sram1_pool_result))
      {
         new_state = IDLE;
         /** DSP Ecc enabling Handler **/
         Enable_Dsp_Ecc();
         /** DSP Parity enabling Handler **/
         Enable_Dsp_Parity();
         /* Enable ESTMEM ECC interrupt */
         RA_ESTMEM_ECC_Enable();
         /** Set RA SEC Threshold **/
         Set_RA_SEC_Threshold();
         /** Application one time Init*/
         Appl_DSP_Process_Onetime_Init();
#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
         Initialize_Perfmon_Info();
#endif
      }
      else
      {
         new_state = INIT;
      }

      return new_state;
   }

   /**
    *  @b Description
    *  @n
    *      IDLE state handler. Waits for the RFFT processing to be started.
    *
    *  @retval
    *      Returns RANGE_PROCESSING.
    */
   static DSP_Main_Application_State_T Idle_Handler(void)
   {
      /** This case will be preceded by angle finding.
       *  Once the RFFT is started, jump to the state to wait
       *  for range processing to complete.
       **/

      DSP_Main_Application_State_T next_state = IDLE;
      bool trigger_received                   = false;
      IPC_Shared_Buffers_T *ipc_buf_add       = (IPC_Shared_Buffers_T *)Get_Ipc_Shared_Buffer_Base_Address();

      do
      {
         trigger_received = Wait_For_Trigger((volatile uint32_t *)&IPC_R52_To_BBE_Trigger_Received);
         ipc_buf_add->D2M_Debug_Msg.DSP_Main_Application_Idle_Counter++;
      } while (!trigger_received);

      IPC_R52_To_BBE_Trigger_Received = NO_TRIGGER;

      next_state = RANGE_PROCESSING;

      return next_state;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for waiting for the RFFT to complete.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(DOPPLER_AND_RDD_PROCESSING, SIGPROC_POST_PROCESSING).
    */
   static DSP_Main_Application_State_T Wait_For_Rfft_Complete_Handler(void)
   {
      DSP_Main_Application_State_T next_state          = IDLE;
      Appl_Range_Return_Values_T range_process_success = APPL_RANGE_ERROR;
      volatile D2M_Msg_T *p_ipc_d2m_msg                = Get_RP_IPC_D2M_Msg_Buffer();

      /* Reset RP-context overrun flag every cycle; set to CODED_TRUE only on
       * current-cycle range timeout/error paths below. */
      Range_Process_Error_Status = CODED_FALSE;

      range_process_success = Check_For_Range_Process_Complete_Timeout_Check(&Memory_Pool_Dram1);
      if (APPL_RANGE_ERROR == range_process_success)
      {
         Send_Range_Proc_Complete(ERRORFIELD_RANGE_PROCESS_ERROR);
         Send_Doppler_RDD_Proc_Complete(ERRORFIELD_DOPPLER_PROCESS_NOT_RUN);
         Range_Process_Error_Status = CODED_TRUE;
         next_state                 = TOI_ALIGNMENT_PROCESSING;
         Range_Process_Error_Cnt++;
      }
      else if (APPL_RANGE_TIMEOUT == range_process_success)
      {
         Send_Range_Proc_Complete(ERRORFIELD_RANGE_PROCESS_TIMEOUT);
         Send_Doppler_RDD_Proc_Complete(ERRORFIELD_DOPPLER_PROCESS_NOT_RUN);
         Range_Process_Error_Status = CODED_TRUE;
         next_state                 = TOI_ALIGNMENT_PROCESSING;
         Range_Process_Error_Cnt++;
      }
      else
      {
         Send_Range_Proc_Complete(ERRORFIELD_NO_ERROR);
         Set_Current_Lookindex();
         next_state = DOPPLER_AND_RDD_PROCESSING;
      }
      p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_index = Get_Current_Lookindex();

      Mem_Pool_Reset(&Memory_Pool_Dram1);
      return next_state;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for running doppler and RDD processing.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(FUSA_BBE_SELF_TEST_PROCESSING, SIGPROC_POST_PROCESSING).
    */
   static DSP_Main_Application_State_T Doppler_Handler(void)
   {
      DSP_Main_Application_State_T next_state = SIGPROC_POST_PROCESSING_ERROR;
      Error_Field_T error_field               = ERRORFIELD_DOPPLER_PROCESS_NOT_RUN;
      volatile D2M_Msg_T *d2m_msg_ptr         = Get_DP_RDD_IPC_D2M_Msg_Buffer();
      M2D_Msg_T *p_ipc_m2d                    = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      Radar_Look_T lookid;

      /* Reset DP-context overrun flag every cycle; set to CODED_TRUE only on
       * current-cycle doppler timeout path below. */
      Doppler_Process_Timeout_Error_Flag = CODED_FALSE;
      Memory_Pool_Return_T dram1_pool_result;
      Memory_Pool_Return_T sram1_pool_result;
      /* HIL data */
      uint8_t hil_mode_enabled = p_ipc_m2d->payload.hil_ipc_info.hil_mode_enabled;
      bool hil_rdd_mode        = (CODED_TRUE == p_ipc_m2d->payload.hil_ipc_info.hil_enabled_streams[RDD]) ? true : false;

      lookid            = d2m_msg_ptr->payload.rdd_stream_data.look_data.look_id;
      dram1_pool_result = Appl_Doppler_Dram1_Memory_Init(&Memory_Pool_Dram1);
      sram1_pool_result = Appl_Doppler_Sram1_Memory_Init(&Memory_Pool_Sram1);

      if ((MEM_POOL_SUCCESS == dram1_pool_result) && (MEM_POOL_SUCCESS == sram1_pool_result) && (CODED_TRUE != hil_mode_enabled))
      {
         Appl_Doppler_Return_Values_T doppler_proc_retval = Appl_Doppler_Rdd_Processing(lookid);
         if (APPL_DOPPLER_TIMEOUT == doppler_proc_retval)
         {
            /* Set DSP loop overrun fault - doppler processing timeout, data discarded */
            error_field = ERRORFIELD_DOPPLER_PROCESS_TIMEOUT;
            Doppler_Process_Error_Cnt++;
            Doppler_Process_Timeout_Error_Flag = CODED_TRUE;
            next_state                         = SIGPROC_POST_PROCESSING_ERROR;
         }
         else if (APPL_DOPPLER_ERROR == doppler_proc_retval)
         {
            error_field = ERRORFIELD_DOPPLER_PROCESS_ERROR;
            Doppler_Process_Error_Cnt++;
         }
         else
         {
            error_field = ERRORFIELD_NO_ERROR;
            next_state  = FUSA_BBE_SELF_TEST_PROCESSING;
         }

         Set_MMIC_Data_Discard_Info();
         /* Update the dwell timestamp in rdd stream*/
         Update_Timestamp_Data();
      }
      else if (CODED_TRUE == hil_mode_enabled)
      {
         /* Simulate Doppler timing during HIL bypass, then wait for M7 Rx complete */
         if (CODED_FALSE == Wait_For_HIL_Rx_Complete())
         {
            /* HIL frames did not arrive within the timeout — count and discard */
            HIL_Rx_Complete_Timeout_Cnt++;
         }

         error_field = ERRORFIELD_NO_ERROR;
         next_state  = ANGLE_FINDING_PROCESSING;
         /* Update the dwell timestamp in rdd stream*/
      }
      else
      {
         error_field = ERRORFIELD_DOPPLER_PROCESS_MEMPOOL_FAILED;
         Doppler_Process_Error_Cnt++;
      }

      if (false == hil_rdd_mode)
      {
         /*This function should called before Send_Doppler_RDD_Proc_Complete()*/
         Update_RDD_Stream_Header(d2m_msg_ptr, error_field); /* Update RDD and Debug stream header */
      }

      Send_Doppler_RDD_Proc_Complete(error_field);
      /* Enable ESTMEM ECC interrupt */
      RA_ESTMEM_ECC_Enable();

      /** Set RA SEC Threshold **/
      Set_RA_SEC_Threshold();

      Mem_Pool_Reset(&Memory_Pool_Dram1);
      Mem_Pool_Reset(&Memory_Pool_Sram1);

      /* Providing d2m_msg_ptr info, for Integration Testing */
      SIT_DWELL_TIMESTAMPS((D2M_Msg_T *)d2m_msg_ptr);

#if defined(ENABLE_SQT_TEST_STUBS)
      RA_Fault_Injection_Execute();
#endif
#if defined(ENABLE_SQT_TEST_STUBS)
      Test_Dsp_Ecc_Parity_Error(); /*SM-18,SM-20,SM-22*/
#endif
      return next_state;
   }

   /**
    *  @b Description
    *  @n
    *      Updates the dwell time stamp data on rdd stream
    *
    *  @retval
    *      None
    */
   static void Update_Timestamp_Data(void)
   {
      TOI_Input_Params_T *const toi_input_params_ptr = Get_TOI_Init_Parameters();
      TOI_RADAR_DATA_STATUS_T *p_toi_ts_data         = (TOI_RADAR_DATA_STATUS_T *)toi_input_params_ptr->toi_data_status_dst_ptr;
      D2M_Msg_T *p_d2m_data                          = Get_DP_RDD_IPC_D2M_Msg_Buffer();
      Look_Data_T *look_data_ptr                     = &p_d2m_data->payload.rdd_stream_data.look_data;
      look_data_ptr->start_dwell_sec                 = p_toi_ts_data->start_dwell_sec;
      look_data_ptr->start_dwell_nanosec             = p_toi_ts_data->start_dwell_nanosec;
      look_data_ptr->start_dwell_status              = p_toi_ts_data->start_dwell_status;
      look_data_ptr->mid_dwell_sec                   = p_toi_ts_data->mid_dwell_sec;
      look_data_ptr->mid_dwell_nanosec               = p_toi_ts_data->mid_dwell_nanosec;
      look_data_ptr->mid_dwell_status                = p_toi_ts_data->mid_dwell_status;
      look_data_ptr->end_dwell_sec                   = p_toi_ts_data->end_dwell_sec;
      look_data_ptr->end_dwell_nanosec               = p_toi_ts_data->end_dwell_nanosec;
      look_data_ptr->end_dwell_status                = p_toi_ts_data->end_dwell_status;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for running Fusa BBE Self Test.
    *
    * Must disable interrupts to run the Fusa BBE self-test.
    *
    * This might result in missing interrupts related to chirps, if doppler/RDD takes
    * up to the start of the next frame to complete.
    *
    * If this happens, frame skips will be observed.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(ANGLE_FINDING_PROCESSING).
    */
   static DSP_Main_Application_State_T Fusa_BBE_Self_Test_Handler(void)
   {
      uint32_t fusa_bbe_self_test_error       = 0U;
      uint8_t fusa_bbe_self_test_failure_flag = CODED_TRUE;

      // Disable the interrupt for running STL.
      (void)xtos_interrupt_disable(SP2DSP_LVL1_INT);

      Appl_BBE_Self_Test_Memory_Init(&Memory_Pool_Dram1, &Memory_Pool_Sram1);

      /*Integrate BBE Self Test*/
      fusa_bbe_self_test_error        = Fusa_BBE_Check_Execute();
      fusa_bbe_self_test_failure_flag = Update_FUSA_BBE_Self_Test_Fault_Flag(fusa_bbe_self_test_error);

      /* Update the diagnostic data in the IPC buffer with the self-test result */
      Get_SP_Post_Proc_IPC_D2M_Msg_Buffer()->payload.diag_data.bbe_self_test_failure_val  = fusa_bbe_self_test_error;
      Get_SP_Post_Proc_IPC_D2M_Msg_Buffer()->payload.diag_data.dsp_self_test_failure_flag = fusa_bbe_self_test_failure_flag;

      Mem_Pool_Reset(&Memory_Pool_Dram1);
      Mem_Pool_Reset(&Memory_Pool_Sram1);

      (void)xtos_interrupt_enable(SP2DSP_LVL1_INT);

      return ANGLE_FINDING_PROCESSING;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for Angle Finding processing.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(RADAR_CAPABILITY_PROCESSING).
    */
   static DSP_Main_Application_State_T Anglefinding_Handler(void)
   {
      Memory_Pool_Return_T mem_pool_result = MEM_POOL_FAILURE;
      AF_Retval_T af_proc_return           = AF_E_UNKNOWN;
      /* These return conditions outside of this mask set will signal a fatal error and we will not continue processing */
      const AF_Retval_T fatal_error_mask = ~(AF_E_SATURATION | AF_E_TIMEOUT | AF_E_OK);

      AF_Appl_Input_T af_appl_input   = {0};
      AF_Appl_Output_T af_appl_output = {0};

      M2D_Msg_T *p_ipc_m2d                  = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      D2M_Msg_T *p_ipc_d2m_msg              = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      af_appl_input.appl_rdd_data_ptr       = &p_ipc_d2m_msg->payload.rdd_stream_data.rdd_data;
      af_appl_input.appl_xcp_data_ptr       = &p_ipc_d2m_msg->payload.xcp_data;
      af_appl_input.appl_xcp_info_data_ptr  = &p_ipc_m2d->payload.xcp_info;
      af_appl_input.appl_look_data_ptr      = &p_ipc_d2m_msg->payload.rdd_stream_data.look_data;
      af_appl_input.appl_veh_speed_ptr      = &(p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);
      af_appl_input.appl_radar_position_ptr = (uint8_t *)&(Get_IPC_M2D_One_Time_Buffer()->radar_position);
      af_appl_input.calib_data_ptr          = (Calib_Data_T *)&(Get_IPC_M2D_One_Time_Buffer()->calib_data);
      af_appl_input.appl_doppler_start_time = Get_Range_Procesing_Done_Time();

      af_appl_output.appl_detection_stream_data_ptr = &p_ipc_d2m_msg->payload.det_data;
      af_appl_output.appl_detection_debug_data_ptr  = &p_ipc_d2m_msg->payload.det_debug_data;
      af_appl_output.appl_af_xcp_data_ptr           = &p_ipc_d2m_msg->payload.xcp_af_data;
      af_appl_output.appl_af_timing_data_ptr        = &p_ipc_d2m_msg->payload.dsp_timing_data.af_time;
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      af_appl_output.appl_down_selection_stream_data_ptr = &p_ipc_d2m_msg->payload.downselection_data;
#endif

      /* determine hil mode configuration */
      uint8_t hil_mode_enabled     = p_ipc_m2d->payload.hil_ipc_info.hil_mode_enabled;
      uint8_t *hil_enabled_streams = p_ipc_m2d->payload.hil_ipc_info.hil_enabled_streams;
      bool hil_detection_stream_injection_mode =
         ((CODED_TRUE == hil_mode_enabled) && (CODED_TRUE == hil_enabled_streams[DETECTION]));
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      bool hil_downselection_stream_injection_mode =
         ((CODED_TRUE == hil_mode_enabled) && (CODED_TRUE == hil_enabled_streams[DOWN_SELECTION]));
#else
   bool hil_downselection_stream_injection_mode = false;
#endif

      /* Reset AF IPC buffer */
      Reset_IPC_AF_Buffer(hil_detection_stream_injection_mode, hil_downselection_stream_injection_mode);

      if (hil_detection_stream_injection_mode | hil_downselection_stream_injection_mode)
      {
         HIL_Scan_Index_Updated_To_RDD = true;
         /*Update the RDD scan index with HIL injected scan index. Other modules gets updated with this scan index*/
         p_ipc_d2m_msg->payload.rdd_stream_data.look_data.scan_index = p_ipc_m2d->payload.hil_ipc_info.hil_scanindex;
         p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_index = p_ipc_d2m_msg->payload.det_data.det_list_property.lookindex;
         p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_id    = p_ipc_d2m_msg->payload.det_data.det_list_property.look_type;
         /* Simulate AF Execution Success */
         af_proc_return = AF_E_OK;
      }
      else
      {
         /* Run Streamline Anglefinding */
         mem_pool_result = Anglefinding_Memory_Init(&Memory_Pool_Dram1, &Memory_Pool_Sram1);
         if (mem_pool_result == MEM_POOL_SUCCESS)
         {
            af_proc_return = Appl_Angle_Finding_Process(&af_appl_input, &af_appl_output);
         }
         else
         {
            af_proc_return = AF_E_UNKNOWN; /* TODO: lets add an out of memory failure code to our enum */
         }
         Mem_Pool_Reset(&Memory_Pool_Dram1);
         Mem_Pool_Reset(&Memory_Pool_Sram1);
      }

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
      if ((0 == (af_proc_return & fatal_error_mask)) && (!hil_downselection_stream_injection_mode))
      {
         /* Execute Fascia Compensation */
         mem_pool_result = Fascia_Compensation_Memory_Init(&Memory_Pool_Dram1);
         if (MEM_POOL_SUCCESS == mem_pool_result)
         {
            Appl_Execute_Fascia_Compensation(&(Get_IPC_M2D_One_Time_Buffer()->fascia_compensation_params), &af_appl_output);
         }
         else
         {
            af_proc_return = AF_E_UNKNOWN; /* TODO: lets add an out of memory failure code to our enum */
         }
         Mem_Pool_Reset(&Memory_Pool_Dram1);
         Mem_Pool_Reset(&Memory_Pool_Sram1);
      }
#endif

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
      if ((0 == (af_proc_return & fatal_error_mask)) && (!hil_downselection_stream_injection_mode))
      {
         /* Run Stage 2 Downselection */
         mem_pool_result = DownSelection_Memory_Init(&Memory_Pool_Dram1);
         if (MEM_POOL_SUCCESS == mem_pool_result)
         {
            Appl_Down_Selection_Process(&af_appl_input, &af_appl_output);
         }
         else
         {
            af_proc_return = AF_E_UNKNOWN; /* TODO: lets add an out of memory failure code to our enum */
         }
         Mem_Pool_Reset(&Memory_Pool_Dram1);
         Mem_Pool_Reset(&Memory_Pool_Sram1);
      }
#endif

      /* report timeout */
      if (af_appl_output.appl_detection_stream_data_ptr->af_diagnostics_info.af_timeout_flag)
      {
         p_ipc_d2m_msg->payload.diag_data.detection_processing_loop_overrun_fault = CODED_TRUE;
      }

      if (AF_E_OK != af_proc_return)
      {
         Angle_Finding_Process_Error_Cnt++;
         Angle_Finding_Process_Last_Error = af_proc_return;
      }

      /* RFC: if (af_proc_return & fatal_error_mask)), should we return a different next_state? */

      return INTERFERENCE_DETECTION_PROCESSING;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for Interference detection process.
    *
    *  @retval
    *      Returns PSPC_State_T(PSPC_STATE_RCAP).
    */
   static DSP_Main_Application_State_T Interference_Detection_Handler(void)
   {
      M2D_Msg_T *p_ipc_m2d     = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      D2M_Msg_T *p_ipc_d2m_msg = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();

      interference_detection_wrapper(p_ipc_m2d, p_ipc_d2m_msg);

      return RADAR_CAPABILITY_PROCESSING;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for Radar Capability processing.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(TOI_ALIGNMENT_PROCESSING).
    */
   static DSP_Main_Application_State_T Radar_Performance_Degradation_Monitor_Handler(void)
   {
      Memory_Pool_Return_T mem_pool_result = MEM_POOL_FAILURE;
      mem_pool_result                      = Capability_Handler_Memory_Init(&Memory_Pool_Dram1);
      M2D_Msg_T *p_ipc_m2d                 = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      uint8_t hil_mode_enabled             = p_ipc_m2d->payload.hil_ipc_info.hil_mode_enabled;
      uint8_t hil_data_src_for_rc_module   = p_ipc_m2d->payload.hil_ipc_info.hil_data_src_radar_capability;

      if ((MEM_POOL_SUCCESS == mem_pool_result) &&
          ((CODED_TRUE != hil_mode_enabled) ||
           ((CODED_TRUE == hil_mode_enabled) && (HIL_EXECUTE_EMBEDDED_ALGO == hil_data_src_for_rc_module))))
      {
         /* Radar Capability */
         rc_wrapper((D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(), (M2D_Msg_T *)Get_IPC_M2D_Buffer(),
                    (M2D_One_Time_Msg_T *)Get_IPC_M2D_One_Time_Buffer());
      }
      else if ((HIL_EXECUTE_INJECTION_DATA == hil_data_src_for_rc_module) && (CODED_TRUE == hil_mode_enabled))
      {
         /*By pass the RC algo during HIL*/
         HIL_RC_Algo_Bypass = true;
      }
      else
      {
         /*Do Nothing*/
      }
      Mem_Pool_Reset(&Memory_Pool_Dram1);

      return TOI_ALIGNMENT_PROCESSING; // next state Alignment processing
   }

   /**
    *  @b Description
    *  @n
    *       Handler for Alignment processing.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(TRACKER_PROCESSING).
    */
   static DSP_Main_Application_State_T TOI_Alignment_Handler(void)
   {
      D2M_Msg_T *p_d2m_data              = Get_DP_RDD_IPC_D2M_Msg_Buffer();
      M2D_Msg_T *p_ipc_m2d               = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      uint8_t hil_mode_enabled           = p_ipc_m2d->payload.hil_ipc_info.hil_mode_enabled;
      uint8_t hil_data_src_for_alignment = p_ipc_m2d->payload.hil_ipc_info.hil_data_src_alignment;

      DSP_Main_Application_State_T next_state = TRACKER_PROCESSING;

      Memory_Pool_Return_T mem_pool_result = MEM_POOL_FAILURE;
      mem_pool_result                      = Alignment_Handler_Memory_Init(&Memory_Pool_Dram1);

      Memory_Pool_Return_T sa_mem_pool_result = MEM_POOL_FAILURE;
      sa_mem_pool_result                      = SA_Alignment_Handler_Memory_Init(&Memory_Pool_Dram1);

      if ((CODED_TRUE == Range_Process_Error_Status) || (CODED_TRUE == Doppler_Process_Timeout_Error_Flag))
      {
         p_d2m_data->payload.diag_data.detection_data_integrity_fault = CODED_TRUE;
         if (CODED_TRUE == Range_Process_Error_Status)
         {
            /** @note Add 10ms delay so that Radar Control Module can update timestamp in the Look Complete stage */
            Delay_Millisec(10U);

            /* Read the radar data status buffer from IPC*/
            Set_MMIC_Data_Discard_Info();

            /* Update the dwell timestamp in rdd stream*/
            Update_Timestamp_Data();

            Range_Process_Error_Status = CODED_FALSE;
            next_state                 = SIGPROC_POST_PROCESSING_ERROR;
         }
         if (CODED_TRUE == Doppler_Process_Timeout_Error_Flag)
         {
            next_state                         = SIGPROC_POST_PROCESSING_ERROR;
            Doppler_Process_Timeout_Error_Flag = CODED_FALSE;
         }
      }
      else
      {
         p_d2m_data->payload.diag_data.detection_data_integrity_fault = CODED_FALSE;
      }

      /* Bypass TOI stream updates during HIL */ /*TOI is currenlty not available in SH table*/
      if (CODED_TRUE == hil_mode_enabled)        /*&& (CODED_TRUE == hil_enabled_streams[TOI]))*/
      {
         HIL_TOI_Algo_Bypass = true;
      }
      else
      {
         /*Initialize TOI input parameters and Get the status of data qualifier*/
         TOI_Parameters_Init();

         /*Get status of Data Qualifier*/
         Determine_Data_Quality(Get_TOI_Init_Parameters(), Get_TOI_Output_Parameters());
      }

      /*Run Alignment Algo during normal SW run and during HIL*/
      if ((CODED_TRUE != hil_mode_enabled) ||
          ((CODED_TRUE == hil_mode_enabled) && (HIL_EXECUTE_EMBEDDED_ALGO == hil_data_src_for_alignment)))
      {
         if (MEM_POOL_SUCCESS == sa_mem_pool_result)
         {
            /* Static Alignment */
            static_align_wrapper((D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(), (M2D_Msg_T *)Get_IPC_M2D_Buffer(),
                                 (M2D_One_Time_Msg_T *)Get_IPC_M2D_One_Time_Buffer());
         }

         if (MEM_POOL_SUCCESS == mem_pool_result)
         {
            dyn_align_wrapper((D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(), (M2D_Msg_T *)Get_IPC_M2D_Buffer(),
                              (M2D_One_Time_Msg_T *)Get_IPC_M2D_One_Time_Buffer());
         }
      }
      else if ((HIL_EXECUTE_INJECTION_DATA == hil_data_src_for_alignment) && (CODED_TRUE == hil_mode_enabled))
      {
         /*By pass the alignment algo during HIL*/
         HIL_Alignment_Algo_Bypass = true;
      }
      else
      {
         /*Do Nothing*/
      }
      /*Resetting mempool memory, this frees the memory for use by other applications*/
      Mem_Pool_Reset(&Memory_Pool_Dram1);

      return next_state;
   }

   /**
    *  @b Description
    *  @n
    *      Handler for Tracker processing.
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(SIGPROC_POST_PROCESSING).
    */
   static DSP_Main_Application_State_T Tracker_Handler(void)
   {
/* Don't run if tracker is not enabled by build flag */
#ifdef TRACKER_ENABLED

      static bool tracker_initialized = false;

      /* Get IPC pointers to pass to tracker wrapper */
      D2M_Msg_T *p_ipc_d2m                            = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      M2D_Msg_T *p_ipc_m2d                            = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();
      uint8_t hil_req_tracker_reinit                  = p_ipc_m2d->payload.hil_ipc_info.hil_request_reinit_module;

      if (CODED_TRUE == hil_req_tracker_reinit)
      {
         tracker_initialized = false;
      }

      /* Skip tracker and feature execution if this is the AL partner sensor (1 SW) */
   #if defined(AL_TRACKER)
      if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_LEFT)
      {
         return SIGPROC_POST_PROCESSING;
      }
   #endif

      /* Don't run tracker until calibration data is available on IPC */
      if (p_ipc_m2d_one_time->calib_data.data_availability_status == CODED_TRUE &&
          (tracker_initialized || p_ipc_m2d->payload.veh_data.vse_output_valid))
      {
         /* Initialize tracker memory and allocate mempool usage */
         Memory_Pool_Return_T mem_pool_result = Emb_Tracker_Mem_Init(&Memory_Pool_Dram1, p_ipc_d2m);

         /* Don't run the tracker if mempool allocation failed */
         if (mem_pool_result == MEM_POOL_SUCCESS)
         {
            /* Don't re-initialize tracker unless necessary */
            if (!tracker_initialized)
            {
               /* Initialize tracker, related modules, and necessary variables */
               Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);
               tracker_initialized = true;
            }

            /* Run the embedded tracker */
            Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
         }

         /* Return used mempool memory */
         Mem_Pool_Reset(&Memory_Pool_Dram1);
      }
#endif

      /* Go to next state */
      return FEATURE_PROCESSING; // next state Signal processing
   }

#if defined(FEATURE_ENABLE)
   /**
    *  @b Description
    *  @n
    *      Feature degradation checks for blockage value & status.
    *
    *  @retval
    *      Returns CODED_TRUE if the feature is degraded, CODED_FALSE otherwise.
    * PRS requirements to be considered for testing :
    * 1) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106845
    * 2) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106848
    */
   uint8_t Self_FC_Align_Blockage_Feat_Degrade_Check(uint8_t align_auto_sts)
   {
      uint8_t mois_feature_degradation_flag = CODED_FALSE;
      D2M_Msg_T *p_ipc_d2m                  = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      uint8_t blockage_sts                  = p_ipc_d2m->payload.radar_capability_data.blockage.blockage_status;
      uint8_t blockage_val                  = p_ipc_d2m->payload.radar_capability_data.blockage.blockage.value;
      M2D_Msg_T *p_ipc_m2d                  = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      uint8_t init_align_calib_flg          = p_ipc_m2d->payload.feature_input.temp_init_align_no_calib_flag;

      uint8_t mois_blockage_cond1 =
         (DRA_BLOCKAGE_STATUS_OK == blockage_sts) &&
         ((DRA_BLOCKAGE_VALUE_NOT_BLOCKED != blockage_val) && (DRA_BLOCKAGE_VALUE_SLIGHTLY_BLOCKED != blockage_val));
      uint8_t mois_blockage_cond2 = (DRA_BLOCKAGE_STATUS_FAULTY == blockage_sts) ||
                                    (0x4 == blockage_sts); // in software invalid is 255(DRA_BLOCKAGE_STATUS_INVALID)
      uint8_t mois_sensor_blocked = mois_blockage_cond1 || mois_blockage_cond2;

      uint8_t mois_no_blockage =
         ((DRA_BLOCKAGE_STATUS_OK == blockage_sts) &&
          ((DRA_BLOCKAGE_VALUE_NOT_BLOCKED == blockage_val) || (DRA_BLOCKAGE_VALUE_SLIGHTLY_BLOCKED == blockage_val)));

      volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_One_Time_Buffer();
      uint8_t sensor_pos                                 = m2d_one_time_init_ptr->radar_position;
      if (5U == sensor_pos)
      {
         if (mois_no_blockage)
         {
            L2_MOIS_Feature_Degradation_Flags.mois_self_blockage_flag = CODED_FALSE;
         }
         else if (mois_sensor_blocked)
         {
            L2_MOIS_Feature_Degradation_Flags.mois_self_blockage_flag = CODED_TRUE;
         }

         if ((0U == init_align_calib_flg) || (Cx1_AAstatus_Active == align_auto_sts) || (Cx2_AAstatus_Paused == align_auto_sts))
         {
            L2_MOIS_Feature_Degradation_Flags.mois_self_align_init_calib_degrade_flag = CODED_FALSE;
         }
         else if ((1U == init_align_calib_flg) || (Cx0_AAstatus_Off == align_auto_sts) || (Cx3_AAstatus_Failed == align_auto_sts))
         {
            L2_MOIS_Feature_Degradation_Flags.mois_self_align_init_calib_degrade_flag = CODED_TRUE;
         }
      }
      mois_feature_degradation_flag =
         ((CODED_TRUE == L2_MOIS_Feature_Degradation_Flags.mois_self_blockage_flag ||
           (CODED_TRUE == L2_MOIS_Feature_Degradation_Flags.mois_self_align_init_calib_degrade_flag)) ?
             CODED_TRUE :
             CODED_FALSE);

      return (mois_feature_degradation_flag);
   }

   /**
    *  @b Description
    *  @n
    *      Feature degradation checks for blockage value & status.
    *
    *  @retval
    *      Returns CODED_TRUE if the feature is degraded, CODED_FALSE otherwise.
    * PRS requirements to be considered for testing :
    * 1) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106846
    * 2) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106849
    */
   uint8_t Self_L2_Align_Blockage_Feat_Degrade_Check(uint8_t align_auto_sts)
   {
      uint8_t l2_bsis_feature_degradation_flag = CODED_FALSE;
      D2M_Msg_T *p_ipc_d2m                     = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      uint8_t blockage_sts                     = p_ipc_d2m->payload.radar_capability_data.blockage.blockage_status;
      uint8_t blockage_val                     = p_ipc_d2m->payload.radar_capability_data.blockage.blockage.value;
      M2D_Msg_T *p_ipc_m2d                     = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      uint8_t init_align_calib_flg             = p_ipc_m2d->payload.feature_input.temp_init_align_no_calib_flag;

      uint8_t bsis_blockage_cond1 = (0x1 == blockage_sts) && ((0x0 != blockage_val) && (0x1 != blockage_val));
      uint8_t bsis_blockage_cond2 = (0x0 == blockage_sts) || (0x4 == blockage_sts);
      uint8_t bsis_sensor_blocked = bsis_blockage_cond1 || bsis_blockage_cond2;

      uint8_t bsis_no_blockage = ((0x1 == blockage_sts) && ((0x0 == blockage_val) || (0x1 == blockage_val)));

      volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_One_Time_Buffer();
      uint8_t sensor_pos                                 = m2d_one_time_init_ptr->radar_position;
      if (1U == sensor_pos)
      {
         if (bsis_no_blockage)
         {
            L2_BSIS_Feature_Degradation_Flags.bsis_self_blockage_flag = CODED_FALSE;
         }
         else if (bsis_sensor_blocked)
         {
            L2_BSIS_Feature_Degradation_Flags.bsis_self_blockage_flag = CODED_TRUE;
         }

         if ((0U == init_align_calib_flg) || (Cx1_AAstatus_Active == align_auto_sts) || (Cx2_AAstatus_Paused == align_auto_sts))
         {
            L2_BSIS_Feature_Degradation_Flags.bsis_self_align_init_calib_degrade_flag = CODED_FALSE;
         }
         else if ((1U == init_align_calib_flg) || (Cx0_AAstatus_Off == align_auto_sts) || (Cx3_AAstatus_Failed == align_auto_sts))
         {
            L2_BSIS_Feature_Degradation_Flags.bsis_self_align_init_calib_degrade_flag = CODED_TRUE;
         }
      }
      l2_bsis_feature_degradation_flag =
         ((CODED_TRUE == L2_BSIS_Feature_Degradation_Flags.bsis_self_blockage_flag ||
           CODED_TRUE == L2_BSIS_Feature_Degradation_Flags.bsis_self_align_init_calib_degrade_flag) ?
             CODED_TRUE :
             CODED_FALSE);

      return l2_bsis_feature_degradation_flag;
   }

   /**
    *  @b Description
    *  @n
    *      Feature function handler
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(SIGPROC_POST_PROCESSING).
    */
   void Feature_Degrade_Checks(void)
   {
      M2D_Msg_T *p_ipc_m2d   = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
      uint8_t align_auto_sts = p_ipc_m2d->payload.alignment_Info.dynamic_alignment_data.alignment_handler_out.auto_align_status;

      /* Check alignment and blockage flags for feature degradation */
      Final_MOIS_Degrade_Flag = (CODED_TRUE == p_ipc_m2d->payload.feature_input.mois_feat_degrade_flag) ?
                                   CODED_TRUE :
                                   Self_FC_Align_Blockage_Feat_Degrade_Check(align_auto_sts);
      Final_BSIS_Degrade_Flag = (CODED_TRUE == p_ipc_m2d->payload.feature_input.bsis_feat_degrade_flag) ?
                                   CODED_TRUE :
                                   Self_L2_Align_Blockage_Feat_Degrade_Check(align_auto_sts);
   }

   /**
    *  @b Description
    *  @n
    *      Gets the current BSIS feature degradation status.
    *
    *  @retval
    *      Returns the current BSIS feature degradation status.
    */
   uint8_t Get_BSIS_Degrade_Status(void)
   {
      return Final_BSIS_Degrade_Flag;
   }

   /**
    *  @b Description
    *  @n
    *      Gets the current MOIS feature degradation status.
    *
    *  @retval
    *      Returns the current MOIS feature degradation status.
    */
   uint8_t Get_MOIS_Degrade_Status(void)
   {
      return Final_MOIS_Degrade_Flag;
   }
#endif

   /**
    *  @b Description
    *  @n
    *      Feature function handler
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(SIGPROC_POST_PROCESSING).
    */
   static DSP_Main_Application_State_T Feature_Handler()
   {
#ifdef VEH_AL_CAN_STANDALONE
   #if defined(FEATURE_ENABLE)

      static bool feature_initialized = false;

      Feature_Degrade_Checks();

      /* Those calls retrieve the current feature degradation status */
      /* Get_BSIS_Degrade_Status();
         Get_MOIS_Degrade_Status(); */

      if (!feature_initialized)
      {
         /* Start of Customer specific modules initialization*/
         Olp_Init();
         Feature_Function_Init();
         /* End of Customer specific modules initialization*/

         feature_initialized = true;
      }

      /* Start of Customer specific modules periodic execution*/
      Olp_Main();
      Feature_Function_Run_50ms();
         /* End of Customer specific modules periodic execution*/
   #endif
#endif

      return SIGPROC_POST_PROCESSING;
   }

   /**
    *  @b Description
    *  @n
    *      Signal Proc Post Processing Complete Handler
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(IDLE).
    */
   static DSP_Main_Application_State_T SP_Post_Proc_Complete_Handler(void)
   {
      Update_Frame_Timing();
      Bbe32_Static_Register_Safety_Check();
      Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);
      return IDLE;
   }

   /**
    *  @b Description
    *  @n
    *      Signal Proc Post Processing Complete Handler - Failure condition
    *
    *  @retval
    *      Returns DSP_Main_Application_State_T(IDLE).
    */
   static DSP_Main_Application_State_T SP_Post_Proc_Complete_Error_Handler(void)
   {
      Update_Frame_Timing();
      Bbe32_Static_Register_Safety_Check();
      Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_POST_SIG_PROC_ERROR);
      return IDLE;
   }

   /**
    *  @b Description
    *  @n
    *      Polls the HIL Rx complete flag written by M7 into the D2M IPC mailbox.
    *      Returns CODED_TRUE when M7 signals that all HIL frames for the current
    *      cycle have been received, or CODED_FALSE if the poll times out after
    *      MAX_HIL_RX_COMPLETE_WAIT_TIME_US microseconds.
    *
    *      The mailbox field is on its own 32-byte cache line; each iteration
    *      invalidates that line so BBE32 sees the latest value written by M7.
    *
    *  @retval  CODED_TRUE   HIL Rx complete flag set by M7 within timeout.
    *  @retval  CODED_FALSE  Timeout expired without the flag being set.
    */
   static uint8_t Wait_For_HIL_Rx_Complete(void)
   {
      volatile D2M_Msg_T *p_d2m_msg        = Get_DP_RDD_IPC_D2M_Msg_Buffer();
      volatile HIL_Rx_Mailbox_T *p_mailbox = &p_d2m_msg->payload.hil_rx_mailbox;
      uint32_t start_ts                    = Timing_Helpers_Get_Timestamp();
      uint32_t elapsed_us                  = 0U;
      uint8_t ret_val                      = CODED_FALSE;

      do
      {
         xthal_dcache_block_invalidate((void *)(uintptr_t)p_mailbox, sizeof(HIL_Rx_Mailbox_T));
         if (CODED_TRUE == p_mailbox->hil_rx_complete_flag)
         {
            ret_val = CODED_TRUE;
         }
         uint32_t current_ts = Timing_Helpers_Get_Timestamp();
         uint32_t delta_ts   = (current_ts >= start_ts) ? (current_ts - start_ts) : ((0xFFFFFFFFU - start_ts) + current_ts);
         elapsed_us          = Timing_Helpers_Get_Time_Microsec(delta_ts);
      } while (elapsed_us < MAX_HIL_RX_COMPLETE_WAIT_TIME_US);

      return ret_val;
   }

   /**
    *  @b Description
    *  @n
    *      Busy-wait delay for the specified number of milliseconds.
    *      Uses Timing_Helpers_Get_Timestamp() and Timing_Helpers_Get_Time_Microsec()
    *      to poll elapsed time, with timestamp wrap-around handling.
    *
    *  @param[in]  delay_ms  Number of milliseconds to wait (e.g. 10U for 10 ms).
    *
    *  @retval  void
    */
   static void Delay_Millisec(uint32_t delay_ms)
   {
      uint32_t delay_us   = delay_ms * 1000U;
      uint32_t start_ts   = Timing_Helpers_Get_Timestamp();
      uint32_t elapsed_us = 0U;
      do
      {
         uint32_t current_ts = Timing_Helpers_Get_Timestamp();
         uint32_t delta_ts   = (current_ts >= start_ts) ? (current_ts - start_ts) : ((0xFFFFFFFFU - start_ts) + current_ts);
         elapsed_us          = Timing_Helpers_Get_Time_Microsec(delta_ts);
      } while (elapsed_us < delay_us);
   }

   /**
    *  @b Description
    *  @n
    *      Function to update the timing information in the IPC buffer.
    *      Updates internally kept profiling structures for DSP monitoring.
    *
    *  @retval
    *      N/A
    */
   void Update_Frame_Timing(void)
   {
#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
      uint8_t i;
      D2M_Msg_T *p_d2m_data               = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      DSP_Timing_Data_T *p_timing_data    = &p_d2m_data->payload.dsp_timing_data;
      ProfilingStruct_t *p_overall_timing = &p_d2m_data->payload.dsp_timing_data.curr_overall_frame_time;

      p_overall_timing->lastRuntime    = MainApplication_ProfilingInfo_Overall.lastRuntime;
      p_overall_timing->maxRuntime     = MainApplication_ProfilingInfo_Overall.maxRuntime;
      p_overall_timing->averageRuntime = MainApplication_ProfilingInfo_Overall.averageRuntime;

      for (i = 0; (i < NUM_PROCESSING_STATES); i++)
      {
         /* populate MainApplication_ProfilingInfo timing info into IPC */
         memcpy(&p_timing_data->state_profiling[i], &MainApplication_ProfilingInfo[i].profilingStruct,
                sizeof(p_timing_data->state_profiling[i]));
      }

      BBE_Instant_Times.rfft_mod_to_af_latency =
         (MainApplication_ProfilingInfo[RANGE_PROCESSING].profilingStruct.lastRuntime >> 1) +
         MainApplication_ProfilingInfo[DOPPLER_AND_RDD_PROCESSING].profilingStruct.lastRuntime +
         MainApplication_ProfilingInfo[ANGLE_FINDING_PROCESSING].profilingStruct.lastRuntime;

      BBE_Instant_Times.rfft_mod_to_dfft_rdd_latency =
         (MainApplication_ProfilingInfo[RANGE_PROCESSING].profilingStruct.lastRuntime >> 1) +
         MainApplication_ProfilingInfo[DOPPLER_AND_RDD_PROCESSING].profilingStruct.lastRuntime;

      BBE_Instant_Times.rfft_dfft_total_time =
         MainApplication_ProfilingInfo[RANGE_PROCESSING].profilingStruct.lastRuntime +
         MainApplication_ProfilingInfo[DOPPLER_AND_RDD_PROCESSING].profilingStruct.lastRuntime;

      BBE_Instant_Times.dfft_af_total_time =
         MainApplication_ProfilingInfo[DOPPLER_AND_RDD_PROCESSING].profilingStruct.lastRuntime +
         MainApplication_ProfilingInfo[ANGLE_FINDING_PROCESSING].profilingStruct.lastRuntime;

      BBE_Instant_Times.rfft_mod_to_af_latency =
         MAX(BBE_Instant_Times.rfft_mod_to_af_latency, BBE_Instant_Times.rfft_mod_to_af_latency);
      BBE_Instant_Times.rfft_mod_to_dfft_rdd_latency =
         MAX(BBE_Instant_Times.rfft_mod_to_dfft_rdd_latency, BBE_Instant_Times.rfft_mod_to_dfft_rdd_latency);
      BBE_Instant_Times.rfft_dfft_total_time = MAX(BBE_Instant_Times.rfft_dfft_total_time, BBE_Instant_Times.rfft_dfft_total_time);
      BBE_Instant_Times.dfft_af_total_time   = MAX(BBE_Instant_Times.dfft_af_total_time, BBE_Instant_Times.dfft_af_total_time);

      Update_IPC_Perfmon_Info(&p_timing_data->data_cache_info, &p_timing_data->instruction_cache_info);
#endif
   }

   /**
    *  @b Description
    *  @n
    *      Run the application state machine forever. This method should never return.
    */
   void Main_Application(void)
   {
      /***********************************************************************/
      /* SERIOUSLY, if you update this table, add the new state in the stack */
      /* analysis configuration:                                             */
      /* tools/python/stackAnalysis/bbe32App_config.ini                      */
      /***********************************************************************/
      static StateMachine_t MainApplication_states[] = {
         {INIT, Init_Handler},
         {IDLE, Idle_Handler},
         {RANGE_PROCESSING, Wait_For_Rfft_Complete_Handler},
         {DOPPLER_AND_RDD_PROCESSING, Doppler_Handler},
         {FUSA_BBE_SELF_TEST_PROCESSING, Fusa_BBE_Self_Test_Handler},
         {ANGLE_FINDING_PROCESSING, Anglefinding_Handler},
         {INTERFERENCE_DETECTION_PROCESSING, Interference_Detection_Handler},
         {RADAR_CAPABILITY_PROCESSING, Radar_Performance_Degradation_Monitor_Handler},
         {TOI_ALIGNMENT_PROCESSING, TOI_Alignment_Handler},
         {TRACKER_PROCESSING, Tracker_Handler},
         {FEATURE_PROCESSING, Feature_Handler},
         {SIGPROC_POST_PROCESSING, SP_Post_Proc_Complete_Handler},
         {SIGPROC_POST_PROCESSING_ERROR, SP_Post_Proc_Complete_Error_Handler}};
      /***********************************************************************/
      /* SERIOUSLY, if you update this table, add the new state in the stack */
      /* analysis configuration:                                             */
      /* tools/python/stackAnalysis/bbe32App_config.ini                      */
      /***********************************************************************/

      static DSP_Main_Application_State_T MainApplication_currentState = INIT;

#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
      DSP_Main_Application_State_T MainApplication_profileState = INIT;

      for (uint8_t i = 0; i < NUM_PROCESSING_STATES; i++)
      {
         Profiling_Helpers_Init(&MainApplication_ProfilingInfo[i].profilingStruct, true);
         MainApplication_ProfilingInfo[i].count = 0;
      }
#endif

      while (1)
      {
#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
         MainApplication_profileState = MainApplication_currentState;
         Profiling_Helpers_Init(&MainApplication_ProfilingInfo[MainApplication_profileState].profilingStruct, false);

         if ((MainApplication_profileState == SIGPROC_POST_PROCESSING) ||
             (MainApplication_profileState == SIGPROC_POST_PROCESSING_ERROR))
         {
            bool reset_profiling_info = MainApplication_ProfilingInfo_Overall.maxRuntime > MAX_OVERALL_FRAME_TIME_US;

            if (reset_profiling_info)
            {
               MainApplication_ProfilingInfo_Overall.maxRuntime = MainApplication_ProfilingInfo_Overall.lastRuntime;
            }

            Profiling_Helpers_Update(&MainApplication_ProfilingInfo_Overall);
         }
#endif

         MainApplication_currentState = (*MainApplication_states[MainApplication_currentState].handler)();

#ifdef ENABLE_PROFILE_TIMING_OUTPUTS
         Profiling_Helpers_Update(&MainApplication_ProfilingInfo[MainApplication_profileState].profilingStruct);
         MainApplication_ProfilingInfo[MainApplication_profileState].count++;
#endif
      }
   }

#ifdef __cplusplus
}
#endif /* __cplusplus */
