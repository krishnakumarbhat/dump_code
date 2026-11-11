#ifndef IPC_DATA_H
#define IPC_DATA_H
/*===========================================================================*/
/**
 * @file ipc_data.h
 *
 * Provides Structure and APIs for Inter core communication
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2024 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
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
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Dynamic_alignment_stream.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "af_common_data.h"
#include "api/profiling_helpers.h"
#include "debug_stream.h"
#include "detection_debug_stream.h"
#include "header_stream.h" // for Angle_Timing_Data_T
#include "hil_communication_stream.h"
#include "id_stream.h"
#include "ipc_commands.h"
#include "partner_sensor_stream.h"
#include "radar_capability_stream.h"
#include "radar_look_types.h"
#include "radar_sw_config.h"
#include "range_process_xcp_types.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "static_alignment_stream.h"

#ifdef TRACKER_ENABLED
   #include "emb_tracker_stream_interface.h"
#endif

#ifdef FEATURE_ENABLE
   #include "bsis_stream.h"
   #include "mois_stream.h"
   #include "olp_stream.h"
#endif

#include "afbb_cfg.h"                // for AF_FASCIA_COMPENSATION_ENABLE and AF_MULTI_TARGET_DETS
#include "angle_finding_interface.h" // for AF_MAX_NUM_FASCIA_COEF
#include "dra_types.h"
#include "spbb_typedefs.h"
#include "vse_stream.h"

#if (DOWNSELECTION_ENABLE == 1U)
   #include "toi_ds_stream.h"
#else
   #include "toi_stream.h"
#endif

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define IPC_PING_PONG_COUNT        (2U)
#define SIZE_OF_RING_BUFFER        (5)
#define XCP_NO_OF_TARGET_SELECTION (3U)
/* Types for data reception on main sensor for fusion tracker */

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
/* Below macro will enable IPC application CRC checks */
#define ENABLE_IPC_CRC
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   /* Assumed vehicle configuration:
      Rear Left    - position 1
      Rear Right   - position 2
      Front Right  - position 3
      Front Left   - position 4
      Front Center - position 5
   */
   typedef enum Radar_Position_Tag
   {
      RADAR_POSITION_REAR_LEFT    = 1U,
      RADAR_POSITION_REAR_RIGHT   = 2U,
      RADAR_POSITION_FRONT_RIGHT  = 3U,
      RADAR_POSITION_FRONT_LEFT   = 4U,
      RADAR_POSITION_FRONT_CENTER = 5U,
   } Radar_Position_T;

   typedef enum HIL_Component_Output_Update_Source_Tag
   {
      HIL_EXECUTE_EMBEDDED_ALGO,
      HIL_EXECUTE_INJECTION_DATA,
      HIL_EXECUTE_VEHICLE_COM_DATA,
      HIL_EXECUTE_AUTOSAR_CAN_DATA,
   } HIL_Component_Output_Update_Source_T;

   typedef enum Ring_Buffer_RW_Tag
   {
      WRITE_BUFFER = 0,
      READ_BUFFER  = 1,
   } Ring_Buffer_RW_T;
   /*!< CRC module state*/
   typedef enum
   {
      CRC_CH_STATUS_FREE, /**< crc channel is free */
      CRC_CH_STATUS_BUSY  /**< crc channel is busy */
   } CRC_ChannelStatusType;

   /**
    * DSP to R52 IPC structure
    */
   typedef struct XCP_Data_Tag
   {
      uint32_t mprb_abin[MAX_RANGE_BINS];
      uint32_t first_pass_abin[MAX_RANGE_BINS];
      uint32_t cfar_abin[MAX_RANGE_BINS];
      uint32_t cfar_nf_abin[MAX_RANGE_BINS];
      uint32_t second_pass_abin[MAX_RANGE_BINS];

#if ENABLE_ADC_DATA_LOGGING == (1U)
      uint16_t xcp_adc_chirp;
      uint16_t xcp_adc_restore_chirp;
      uint16_t xcp_light_comp_range;
      Range_Proc_XCP_Output_T __attribute__((aligned(32))) range_process_ra_output;
#endif
      uint16_t rdd1_xcp_rdop_amp;
      s10p21_T rdd1_xcp_rbin_est;
      s10p21_T rdd1_xcp_dbin_est;
      s10p21_T rdd1_xcp_abin_est;
      rdop_avg_t rdd1_xcp_rdop_avg;
      rdop_avg_t rdd1_xcp_nf_est;
      uint16_t rdd1_xcp_rdop_avg_dbin[MAX_RANGE_BINS];
      uint16_t rdd1_xcp_rdop_avg_rbin[MAX_DOPPLER_FFT_SIZE];
      uint16_t rdd1_xcp_rdop_avg_abin[ANGLE_BINS_USED];
      uint16_t rdd1_xcp_compressed_bv[NUM_TX_CHANNELS][NUM_RX_ANTENNAS];
      BV_Decomp_Type_T rdd1_xcp_decompressed_bv[NUM_RX_ANTENNAS * NUM_TX_CHANNELS];
      float32_t rdd2_xcp_snr;
      s10p21_T rdd2_xcp_range_rate;
      s10p21_T rdd2_xcp_range;
      uint16_t xcp_max_per_rbin_targets;
      rdop_avg_t xcp_cal_rdopavg_rbin[XCP_NO_OF_TARGET_SELECTION][XCP_CAL_NO_OF_TARGETS];
      rdop_avg_t xcp_cal_rdopavg_dbin[XCP_NO_OF_TARGET_SELECTION][XCP_CAL_NO_OF_TARGETS];
      rdop_avg_t xcp_cal_rdopavg_abin[XCP_NO_OF_TARGET_SELECTION][XCP_CAL_NO_OF_TARGETS];
      uint16_t rdd1_xcp_compressed_bv_3p[XCP_NO_OF_TARGET_SELECTION][NUM_TX_CHANNELS][NUM_RX_ANTENNAS];
      BV_Decomp_Type_T rdd1_xcp_decompressed_bv_3p[XCP_NO_OF_TARGET_SELECTION][NUM_RX_ANTENNAS * NUM_TX_CHANNELS];
   } __attribute__((aligned(32))) XCP_Data_T;

   typedef struct IPC_Header_Tag
   {
      uint32_t crc;
      uint32_t size;
      uint32_t counter;
   } __attribute__((aligned(32))) IPC_Header_T;

   typedef struct Diag_Data_Tag
   {
      uint16_t dfft_rdd_xput_overrun_cnt;
      uint16_t rfft_xput_overrun_cnt;
      uint16_t ipc_m2d_buffer_err_cnt;
      uint16_t dfft_rdd_error_cnt;
      uint32_t bbe_self_test_failure_val;
      uint8_t fusa_bbe32_reg_readback_test_fault_flag;
      uint8_t dsp_self_test_failure_flag;
      uint8_t detection_processing_loop_overrun_fault;
      uint8_t detection_data_integrity_fault;
   } __attribute__((aligned(32))) Diag_Data_T;

   typedef enum DSP_Main_Application_State_Tag
   {
      INIT = 0,
      IDLE,
      RANGE_PROCESSING,
      DOPPLER_AND_RDD_PROCESSING,
      FUSA_BBE_SELF_TEST_PROCESSING,
      ANGLE_FINDING_PROCESSING,
      INTERFERENCE_DETECTION_PROCESSING,
      RADAR_CAPABILITY_PROCESSING,
      TOI_ALIGNMENT_PROCESSING,
      TRACKER_PROCESSING,
      FEATURE_PROCESSING,
      SIGPROC_POST_PROCESSING,
      SIGPROC_POST_PROCESSING_ERROR,
      NUM_PROCESSING_STATES
   } DSP_Main_Application_State_T;

   typedef struct DSP_Timing_Data_Tag
   {
      ProfilingStruct_t state_profiling[NUM_PROCESSING_STATES];
      uint32_t rdd_time;
      Angle_Timing_Data_T af_time;
      ProfilingStruct_t range_process_time;
      uint32_t range_process_idle_time;
      ProfilingStruct_t curr_overall_frame_time;
      BBE_Cache_Info_T instruction_cache_info;
      BBE_Cache_Info_T data_cache_info;
   } DSP_Timing_Data_T;

   typedef struct Angle_Data_XCP_Tag
   {
      int32_t num_af_det;
      float32_t ran;
      float32_t vel;
      float32_t pow[AF_MULTI_TARGET_DETS];
      float32_t snr;
      float32_t theta[AF_MULTI_TARGET_DETS];
      float32_t phi[AF_MULTI_TARGET_DETS];
      float32_t spec_res[AF_MULTI_TARGET_DETS];
      int16_t rdd_idx;
      int8_t az_conf[AF_MULTI_TARGET_DETS];
      int8_t el_conf[AF_MULTI_TARGET_DETS];
      int8_t f_single_target[AF_MULTI_TARGET_DETS];
      int8_t f_superres_target[AF_MULTI_TARGET_DETS];
      int8_t f_1az2el[AF_MULTI_TARGET_DETS];
      int8_t f_bistatic[AF_MULTI_TARGET_DETS];
      int8_t az_af_type[AF_MULTI_TARGET_DETS];
      int8_t el_af_type[AF_MULTI_TARGET_DETS];
      float32_t rcs[AF_MULTI_TARGET_DETS];
   } __attribute__((aligned(32))) Angle_Data_XCP_T;

   /* Enum for the SIT test result */
   typedef enum
   {
      TEST_NOT_PERFORMED = 0,
      TEST_INTERFACE_INVALID,
      TEST_PASSED,
      TEST_FAILED,
      TEST_SKIPPED,
      TEST_STUB_INVALID
   } SIT_Test_Result_T;

   /* Structure to transfer Integration test data over IPC */
   typedef struct SIT_Data_Tag
   {
      double stub_value;                     /* Value to inject into stubbed interface */
      uint32_t test_interface_number;        /* Selects which interface to stub (1-N) */
      uint32_t no_of_elements_in_stub_array; /* Number of array elements to stub */
      SIT_Test_Result_T test_result;         /* Test result */
      bool stub_success;                     /* Flag indicating provider stub validation passed */
   } __attribute__((aligned(32))) SIT_Data_T;
#ifdef XCP_FAULT_INJECTION
   typedef enum XCP_Fault_Injn_Tag
   {
      R52_To_BBE_Fault = 1,
      BBE_To_R52_Fault = 2,
      NO_Fault         = 3,
   } XCP_Fault_Injn_T;
#endif
   typedef struct Tracker_Host_Output_Tag
   {
      uint32_t timestamp_secs;
      uint32_t timestamp_nanosecs;
      uint32_t veh_index;
      float signed_filt_veh_speed_over_ground;
      float vcs_long_velocity;
      float vcs_lat_velocity;
      float vcs_lat_accel;
      float vcs_long_accel;
      float comp_yaw_rate_filtered;
      float vcs_sideslip;
      float sideslip_rear_axle;
      float curvature_rear_axle;
      float speed_compensation_factor;
      float comp_steering_angle_deg;
      uint16_t K_Unused16_1;
      uint8_t filt_veh_speed_over_ground_qf;
      uint8_t comp_yaw_rate_qf;
      uint8_t vcs_lat_accel_qf;
      uint8_t vcs_long_accel_qf;
      uint8_t reverse_status;
      uint8_t vse_major_version;
      uint8_t vse_minor_version;
      uint8_t vse_field_version;
      uint8_t vse_calibration_version;
   } Tracker_Host_Output_T;

   /**
    * @brief HIL Rx mailbox � BBE32 polls this to know when M7 has finished
    *        receiving the current HIL cycle's UDP frames.
    *
    * Isolated on its own 32-byte cache line so BBE32 can call
    * xthal_dcache_block_invalidate() safely without evicting adjacent data.
    */
   typedef struct HIL_Rx_Mailbox_Tag
   {
      uint8_t hil_rx_complete_flag; /**< Set by M7 when HIL frame reception is complete */
      uint8_t reserved[31];         /**< Pad to a full 32-byte cache line */
   } __attribute__((aligned(32))) HIL_Rx_Mailbox_T;

   typedef struct D2M_Payload_Tag
   {
      DSP_Timing_Data_T dsp_timing_data;
      XCP_Data_T xcp_data;
      Rdd_Debug_Stream_T rdd_debug_data;
      // M2D_Payload_T ipc_m2d_payload;
      Rdd_Stream_T rdd_stream_data;
      Diag_Data_T diag_data;
      Angle_Data_XCP_T xcp_af_data;
      Detection_Stream_T det_data;
      Detection_Debug_Stream_T det_debug_data;
      Static_Alignment_Log_Stream_T alignment_stream_data;
      ID_Stream_T interference_detection_data;
      Dynamic_Alignment_Log_Stream_T dynamic_alignment_log_stream;
      Radar_Capability_Stream_T radar_capability_data;
#ifdef TRACKER_ENABLED
      Emb_Tracker_Status_T emb_tracker_status;
      Sync_Info_Stream_T sync_info_stream;
      Vehicle_Info_Stream_T vehicle_info_stream;
      Tracker_Info_Stream_T tracker_info_stream;
      Timing_Info_Stream_T timing_info_stream;
      Host_Calibs_Stream_T host_calibs_stream;
      Host_Props_Stream_T host_props_stream;
      Static_Env_Poly_Stream_T static_env_poly_stream;
      Functional_Safety_Faults_Stream_T functional_safety_faults_stream;
      Object_List_Stream_T object_list_stream;
      Processed_Detection_Stream_T processed_detection_stream;
      Sensor_Calib_Stream_T sensor_calib_stream;
      Trailer_Detector_Stream_T trailer_detector_stream;
      Cv_Trailer_Stream_T cv_trailer_stream;

   #if ENABLE_INTERNAL_TRACKER_STREAMS
      Internal_Trailer_Detector_Stream_T internal_trailer_detector_stream;
      Internal_Object_Stream_T internal_object_stream;
      Internal_Cluster_Stream_T internal_cluster_stream;
      Internal_Detection_Hist_Stream_T internal_detection_hist_stream;
      Internal_Reflection_Buffer_Stream_T internal_reflection_buffer_stream;
      Internal_CWD_Stream_T internal_cwd_stream;
   #endif
#endif
#if (DOWNSELECTION_ENABLE == 1U)
      Down_selection_Stream_T downselection_data;
      TOI_DS_Stream_T toi_ds_stream_data;
#else
   TOI_Stream_T toi_stream_data;
#endif
#if defined(Integration_Testing)
      SIT_Data_T sit_data; /* Structure to transfer Integration test data over IPC */
#endif
#if defined(FEATURE_ENABLE)
      Olp_Stream_T Olp_Object_Data;
      Bsis_Stream_T Bsis_IPC_Output;
      Mois_Stream_T Mois_IPC_Output;
#endif
      HIL_Rx_Mailbox_T hil_rx_mailbox; /* HIL Rx handshake mailbox (written by M7, polled by BBE32) */
   } __attribute__((aligned(32))) D2M_Payload_T;

   typedef struct D2M_Msg_Tag
   {
      IPC_Header_T header;
      D2M_Payload_T payload;
   } __attribute__((aligned(32))) D2M_Msg_T;

   typedef struct D2M_Debug_Msg_Tag
   {
      uint32_t DSP_Main_Application_Idle_Counter;
      uint32_t DSP_Main_Application_Retry_Core_Init;
      uint32_t BBE32_Exception_Cause;
      uint32_t BBE32_Exception_Ccount;
      uint32_t Exception_VADDR;
      uint32_t Exception_PS;
      uint32_t Exception_EPC1;
   } D2M_Debug_Msg_T;

   typedef struct UserFrame_Tag
   {
      uint32_t pc;
      uint32_t ps;
      uint32_t sar;
      uint32_t vpri;
      uint32_t a2;
      uint32_t a3;
      uint32_t a4;
      uint32_t a5;
      uint32_t exccause;
      uint32_t lcount;
      uint32_t lbeg;
      uint32_t lend;
      uint32_t acclo;
      uint32_t acchi;
      uint32_t mr[4];
      uint32_t pad[2];
   } UserFrame_T;

   typedef struct IPC_Crc_ModuleStateType_Tag
   {
      uint8_t Crc_EngineBusy;    /**< A0 compat: single engine mutex */
      uint8_t Crc_EngineBusyCh0; /**< CRC engine Ch0 state */
      uint8_t Crc_EngineBusyCh1; /**< CRC engine Ch1 state */
      uint8_t Crc_EngineBusyCh2; /**< CRC engine Ch2 state */
      uint8_t Crc_EngineBusyCh3; /**< CRC engine Ch3 state */
   } IPC_Crc_ModuleStateType_T;

   typedef struct IPC_Shared_Buffers_Tag
   {
      Ipc_Notify_Structure_T Ipc_Notify_Buffers[CORE_TO_CORE_MAX][SIZE_OF_RING_BUFFER];
      uint32_t ReadIndx[CORE_TO_CORE_MAX];
      uint32_t WriteIndx[CORE_TO_CORE_MAX];
      D2M_Debug_Msg_T D2M_Debug_Msg;
      UserFrame_T UserFrame;
      IPC_Crc_ModuleStateType_T Crc_ModuleState;
   } __attribute__((aligned(32))) IPC_Shared_Buffers_T;

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
   typedef enum FC_Enable_Flag_Tag
   {
      NO_SLOPE_CORRECTION  = 0,
      FC_ALL_DIRECTIONS    = 1,
      FC_AZIMUTH           = 2,
      FC_ELEVATION         = 3,
      FC_ROLL              = 4,
      FC_AZIMUTH_ELEVATION = 5,
      FC_AZIMUTH_ROLL      = 6,
      FC_ELEVATION_ROLL    = 7,

      FC_MAX_NUM_MODES /* keep last */
   } FC_Enable_Flag_T;

   typedef struct Fascia_Comp_Data_Tag
   {
      FC_Enable_Flag_T axis_enable;
      /* algorithm uses fixed size set of coefficients */
      /* if any coefficients are unused, set them to 0 */
      /* coefficients[0] is the most significant term (x^5 term) */
      /* coefficients[5] is the least significant term (constant term)*/
      float32_t az_coefficients[AF_MAX_NUM_FASCIA_COEF];
      float32_t el_coefficients[AF_MAX_NUM_FASCIA_COEF];
   } Fascia_Comp_Data_T;
#endif

   typedef struct Vehicle_Calib_Data_Tag
   {
      float32_t k_distance_front_bumper_to_rear_axle;
      float32_t k_rear_cornering_compliance;
      float32_t k_steering_gear_ratio;
      float32_t k_wheelbase;
      float32_t k_vehicle_width;
      float32_t k_vehicle_length;
   } Vehicle_Calib_Data_T;

   typedef struct Sensor_Mount_Data_Tag
   {
      float32_t k_sensor_mount_pos_x;
      float32_t k_sensor_mount_pos_y;
      float32_t k_sensor_mount_pos_z;
      float32_t k_sensor_mount_height;
      float32_t k_sensor_mount_ornt_yaw;
      float32_t k_sensor_mount_ornt_pitch;
      float32_t k_sensor_mount_ornt_roll;
   } Sensor_Mount_Data_T;

   typedef struct Sensor_Calib_Data_Tag
   {
      Sensor_Mount_Data_T sensor_mount_data;
      float32_t k_rdotmin;
      float32_t k_fov_hor_begin;
      float32_t k_fov_hor_end;
      float32_t k_fov_ver_begin;
      float32_t k_fov_ver_end;
      float32_t k_vwrapping[4];
      float32_t k_rwrapping[4];
      float32_t k_detection_range_max[4];
      float32_t k_sensor_mount_polarity;
   } Sensor_Calib_Data_T;

   typedef struct Calib_Data_Tag
   {
      Vehicle_Calib_Data_T vehicle_calib_data;
      Sensor_Calib_Data_T sensor_calib_data;
      uint8_t data_availability_status;
   } Calib_Data_T;

   typedef struct M2D_Onetime_Msg_Tag
   {
      uint32_t usc_sram_address;
      uint32_t smc_sram_address;
      Calib_Data_T calib_data;
      uint8_t radar_position;
#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
      Fascia_Comp_Data_T fascia_compensation_params;
#endif
   } __attribute__((aligned(32))) M2D_One_Time_Msg_T;

   typedef struct XCP_Info_Tag
   {
      uint16_t xcp_adc_chirp_num;
      uint16_t xcp_adc_restore_chirp_num;
      uint16_t xcp_light_comp_range_num;
      Radar_Look_T xcp_look_select;
      uint16_t xcp_cmd;
      uint16_t xcp_data;
      uint16_t xcp_range_idx;
      uint16_t xcp_doppler_idx;
      uint16_t xcp_angle_idx;
      uint16_t xcp_range_idx_bv_variance;
      uint16_t xcp_target_range_idx[NUM_LOOKS][XCP_NO_OF_TARGET_SELECTION];
      uint16_t xcp_target_doppler_idx[NUM_LOOKS][XCP_NO_OF_TARGET_SELECTION];
      uint16_t xcp_target_angle_idx[NUM_LOOKS][XCP_NO_OF_TARGET_SELECTION];
      uint8_t xcp_target_select_cmd;
      uint8_t xcp_cfar_out_select_ci;
      uint8_t xcp_rdd_vary_xput_flag;
      uint8_t xcp_spe_gain_vary_enable_flag;
      uint8_t xcp_max_static_target_case_enable;
      uint16_t xcp_max_fp_tgt_cnt;
      uint16_t xcp_rngidx_target_start;
      float32_t xcp_spe_gain;
      float32_t xcp_spe_gain_min;
      float32_t xcp_spe_gain_max;
      uint16_t xcp_max_fp_per_rbin_target_cnt;
      float32_t xcp_rdd_vary_xput_cfar_cal;
   } __attribute__((aligned(32))) XCP_Info_T;

   typedef struct Look_Info_Tag
   {
      uint16_t scan_index;
      Radar_Look_T look_type;
      Radar_Mode_T mode;
   } __attribute__((aligned(32))) Look_Info_T;

   typedef struct Static_Alignment_Data_Tag
   {
      float32_t yaw;
      float32_t pitch;
      float32_t plate_angle_deg_scs;
      float32_t plate_distance;
      float32_t polarity;
      float32_t horz_angle_min;
      float32_t horz_angle_max;
      float32_t vert_angle_min;
      float32_t vert_angle_max;
      float32_t plate_lat_position;
      float32_t max_abs_misalignment_az;
      float32_t max_abs_misalignment_el_sky;
      float32_t max_abs_misalignment_el_ground;
      float32_t target_height_over_ground;
      uint16_t k_num_valid_scan_needed;
      uint16_t k_max_number_of_scans_allowed;
      uint8_t mount_loc;
      uint8_t align_cmd; /* 0: off, 1: auto, 2: short_track, 3: service */
      uint8_t f_data_valid;
      uint8_t target_type_select; /* 0: SRA_FLAT_PLATE, 1: SRA_DOPPLER_GENERATOR, 2: SRA_CORNER_REFLECTOR, 3: SRA_RESERVED */
   } __attribute__((aligned(32))) Static_Alignment_Data_T;

   typedef struct Alignment_Handler_Output_Tag
   {
      uint8_t auto_align_status;
      float32_t aacurrent_azimuth;
      float32_t aacurrent_elevation;
   } Alignment_Handler_Output_T;

   typedef struct Dynamic_Alignment_Data_Tag
   {
      /* Initialization data */
      float32_t initial_vacs_boresight_az_estimated; /* [rad] */
      float32_t initial_vacs_boresight_el_estimated; /* [rad] */
      float32_t initial_vacs_boresight_rl_estimated; /* [rad] */
      float32_t initial_speed_compensation_factor;
      float32_t max_abs_misalignment_az;        /* [rad] */
      float32_t max_abs_misalignment_el_sky;    /* [rad] */
      float32_t max_abs_misalignment_el_ground; /* [rad] */
      uint32_t initial_num_updates_az;
      uint32_t initial_num_updates_el;
      uint32_t initial_num_updates_rl;
      uint8_t initial_align_quality_factor_az;
      uint8_t initial_align_quality_factor_el;
      uint8_t align_cmd; /* 0: off, 1: auto, 2: short_track, 3: service */

      float32_t short_track_target_height;
      float32_t short_track_target_range_rate;
      float32_t az_scf_kf_covariance[4];
      float32_t el_roll_kf_covariance[4];
      uint8_t short_track_exit_condition;

      /* Mounting position (iso, origin at center rear axle) */
      float32_t iso_sensor_x_posn;                  /* [m] */
      float32_t iso_sensor_y_posn;                  /* [m] */
      float32_t iso_sensor_z_posn;                  /* [m] */
      float32_t iso_sensor_yaw;                     /* [rad] */
      float32_t iso_sensor_pitch;                   /* [rad] */
      float32_t iso_sensor_roll;                    /* [rad] */
      float32_t distance_rear_axle_to_front_bumper; /* [m] */
      uint8_t mount_loc;
      DRA_Detection_Coordinate_System_T coordinate_system_input;
      uint8_t f_data_valid;
      uint8_t operation_mode_status;
      Alignment_Handler_Output_T alignment_handler_out;
      uint8_t azimuth_estimation_qf;
      uint8_t elevation_estimation_qf;
      uint8_t scf_estimation_qf;
   } __attribute__((aligned(32))) Dynamic_Alignment_Data_T;
   typedef struct M2D_Cust_EOL_FPSA_Data_Tag
   {
      uint8_t EOL_routine_trigger;
      uint8_t SSA_routine_trigger;
   } __attribute__((aligned(32))) M2D_Cust_EOL_FPSA_Data_T;

   typedef struct Alignment_Info_Tag
   {
      Static_Alignment_Data_T static_alignment_data;
      Dynamic_Alignment_Data_T dynamic_alignment_data;
   } __attribute__((aligned(32))) Alignment_Info_T;

#if defined(VEH_AL_CAN_STANDALONE)
   #if defined(FEATURE_ENABLE)
   typedef struct Feature_Input_Tag
   {
      uint8_t mois_fn_enable_disable_sts;
      uint8_t bsis_fn_enable_disable_sts;
      uint8_t ignition_sts;
      uint8_t mois_feat_degrade_flag;
      uint8_t bsis_feat_degrade_flag;
      uint8_t temp_init_align_no_calib_flag;
   } Feature_Input_T;
   #endif
#endif
   typedef struct HIL_Ipc_Info_Tag
   {
      uint32_t hil_scanindex;
      uint8_t hil_enabled_streams[MAX_STREAMS_SH];
      uint8_t hil_mode_enabled;
      uint8_t hil_entry_point;
      uint8_t hil_request_reinit_module;  /* Reinit request from HIL due to change in mount parameters */
      uint8_t hil_request_disable_fusion; /* Request from HIL user to disable fusion */
      uint8_t hil_data_src_af;
      uint8_t hil_data_src_alignment;
      uint8_t hil_data_src_id;
      uint8_t hil_data_src_radar_capability;
      uint8_t hil_src_radar_mounting_data;
      uint8_t hil_src_vehicle_data;
      uint8_t hil_src_timestamp;
      uint8_t hil_src_fusion_data;
   } __attribute__((aligned(32))) HIL_Ipc_Info_T;

   typedef struct Radar_Data_Status_Payload_Tag /*Offset Start byte of the Structure Radar_Data_Status_Payload is 28 bytes*/
   {
      uint32_t start_dwell_nanosec;
      uint32_t start_dwell_sec;
      uint32_t end_dwell_nanosec;
      uint32_t end_dwell_sec;
      uint32_t mid_dwell_nanosec;
      uint32_t mid_dwell_sec;
      uint8_t start_dwell_status;
      uint8_t end_dwell_status;
      uint8_t mid_dwell_status;
      uint8_t Radar_Data_Discard;
      uint8_t Radar_MMIC_Config_Error;
      uint8_t MMIC_Reinit_Request;
      uint8_t MMIC_Error_Id;
      uint8_t Radar_Ctl_State_Idle;
      uint8_t Radar_Ctl_State_Degraded;
      uint8_t Radar_Radiation_Off;
      uint8_t Radar_Ctl_Pure_CW_Mode;
      uint8_t Radar_Data_Satus_Unused_1;
   } Radar_Data_Status_Payload_T;

   typedef struct Radar_Data_Status_Hdr_Tag
   {
      uint32_t radar_data_status_crc;
      uint16_t alive_counter;
      uint16_t scan_index;
      uint8_t crc_mismatch_flag;
      uint8_t K_Unused8_1;
   } Radar_Data_Status_Hdr_T;

   typedef struct IPC_MMIC_Radar_Data_Status_Tag /*Offset Start byte of the Structure Radar_Data_Status is 36 bytes*/
   {
      Radar_Data_Status_Hdr_T radar_data_status_header;
      Radar_Data_Status_Payload_T radar_data_status_payload;
   } IPC_MMIC_Radar_Data_Status_T;

   typedef struct M2D_Payload_Tag
   {
      XCP_Info_T xcp_info;
      Look_Info_T look_Info;
      Vse_Stream_T veh_data;
      uint32_t offline_mode_flag;
      int16_t avg_mmic_onchip_temp;
      // Radar_Ctl_Init_Status_T radar_status;
      Alignment_Info_T alignment_Info;
#if defined(VEH_AL_CAN_STANDALONE)
   #if defined(FEATURE_ENABLE)
      Feature_Input_T feature_input;
   #endif
#endif
      uintptr_t Radar_Sts_Ptr;
      HIL_Ipc_Info_T hil_ipc_info;
      GLOB_TS_STRUCT_TYPE r52_time_for_sync;
      uint32_t r52_ticks_for_sync;
#if defined(Integration_Testing)
      SIT_Data_T sit_data; /* Structure to transfer Integration test data over IPC */
#endif
#ifdef TRACKER_ENABLED
      Partner_Sensor_Stream_T partners_data;
#endif
#ifdef XCP_FAULT_INJECTION
      XCP_Fault_Injn_T xcp_fault_type;
#endif
   } __attribute__((aligned(32))) M2D_Payload_T;

   typedef struct M2D_Msg_Tag
   {
      IPC_Header_T header;
      M2D_Payload_T payload;
   } __attribute__((aligned(32))) M2D_Msg_T;
   typedef struct IPC_M2D_Buffers_Tag
   {
      M2D_One_Time_Msg_T IPC_M2D_One_Time_Init_Data;
      M2D_Msg_T IPC_M2D_Buffer[IPC_PING_PONG_COUNT];
   } __attribute__((aligned(32))) IPC_M2D_Buffers_T;

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void IPC_Notify_Buffer_Init(void);
   volatile Ipc_Notify_Structure_T *Get_IPC_Notify_Buffer(Core_To_Core_ID_T core_to_core_id, Ring_Buffer_RW_T readWrite);
   uint32_t Get_Ipc_Shared_Buffer_Base_Address(void);

   uint8_t Is_IPC_Notify_Buffer_Empty(Core_To_Core_ID_T coreid);
   uint8_t Is_IPC_Notify_Buffer_Full(Core_To_Core_ID_T coreid);
   void Increment_IPC_Notify_ReadIndx(Core_To_Core_ID_T coreid);
   void Increment_IPC_Notify_WriteIndx(Core_To_Core_ID_T coreid);
   volatile void *volatile_memset(volatile void *s, int c, size_t n);
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* IPC_DATA_H */
