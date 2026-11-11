/*===========================================================================*/
/**
 * @file main_application_fake.h
 *
 * Fake declarations for main_application.c unit tests.
 *
 * Strategy: Pre-define every include guard that main_application.c would pull
 *           in, then provide the minimal stub types and FFF fakes so the
 *           source compiles in the x86 unit-test environment.
 */
/*==========================================================================*/
#pragma once

/*===========================================================================*
 * Include guard pre-definitions — block ALL real headers included by
 * main_application.c so their content is never processed.  The BUILD deps
 * ensure the compiler can *find* the files (satisfying the #include search)
 * but the guards cause the preprocessor to skip them.
 *===========================================================================*/
#define MAIN_APPLICATION_H
#define MIPI_HELPERS_H
#define PROFILING_HELPERS_H
#define RA_HELPERS_H
#define SYSMEM_HELPERS_H
#define _TIMING_HELPERS_H_
#define FUSA_BBE_SELF_TEST_H
#define AFBB_CFG_H
#define ANGALE_FINDING_INTERFACE_H /* note: real header has this typo */
#define ANGLE_FINDING_TYPES_H      /* transitive from angle_finding_interface */
#define ANGLE_FINDING_PROJECT_INTERFACE_H
#define DOPPLER_PROCESS_IFC_H
#define DYN_ALIGN_WRAPPER_H
#define IPC_DSP_H
#define IPC_DATA_H
#define IPC_COMMANDS_H
#define MEM_POOL_H
#define MIPI_TPGEN_IFC_H
#define PERFORMANCE_MONITOR_IFC_H
#define RADAR_DATA_QUALITY_H
#define RANGE_PROCESS_H
#define RANGE_PROCESS_IFC_H
#define RC_WRAPPER_H
#define BBE32_STATIC_REGISTER_VALIDATION_H
#define DSS_ECC_PARITY_H
#define STATIC_ALIGN_WRAPPER_H_
#define TOI_STREAM_H
#define TOI_ALGO_INTERFACE_H
#define XCP_ADC_LOGGING_H
#define F360_RADAR_TRACKER_H
#define EMB_TRACKER_WRAPPER_H
#define SH_MODULE_CFG_H
#define INTERFERENCE_DETECTION_ALGO_INTERFACE_H
#define RA_FAULT_INJECTION_H
/* Transitive / SDK headers that may be pulled in */
#define RDD_STREAM_H
#define RADAR_LOOK_TYPES_H
#define SPBB_INCLUDE_H
#define SPBB_TYPEDEFS_H

/*===========================================================================*
 * Standard headers & FFF
 *===========================================================================*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "fff.h"

/*===========================================================================*
 * Primitive type aliases
 *===========================================================================*/
typedef float float32_t;
typedef int32_t s8p23_T;
typedef int32_t s10p21_T;

/*===========================================================================*
 * Common macros
 *===========================================================================*/
#define CODED_TRUE  (0xAAU)
#define CODED_FALSE (0x55U)

/* MAX_DOPPLER_PROC_OVERRUN_TIME_US is normally in doppler_process_ifc.h, which is
 * blocked by its include guard above.  Provide the value here so that
 * main_application.c can build MAX_HIL_RX_COMPLETE_WAIT_TIME_US. */
#define MAX_DOPPLER_PROC_OVERRUN_TIME_US (26000U)

/* Host-side Xtensa cache stub — no-op on x86_64 */
#define xthal_dcache_block_invalidate(addr, size) ((void)(addr))

#ifndef MAX
   #define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef UNUSED_PARAM
   #define UNUSED_PARAM(x) (void)(x)
#endif

#define ENABLE_PROFILE_TIMING_OUTPUTS
#define RADAR_CYCLE_MS_TMP  (26000U)
#define SP2DSP_LVL1_INT     (8U)
#define DEFAULT_TIMEOUT_US  (200000U)
#define IPC_PING_PONG_COUNT (2U)

/* Values for AF_Retval_T */
#define AF_E_OK           ((uint32_t)0 /* standard return value for success */)
#define AF_E_PARAM        ((uint32_t)1 << 0 /* invalid parameter input */)
#define AF_E_CAL_MISMATCH ((uint32_t)1 << 1 /* some problem with one of the calibration inputs */)
#define AF_E_SMC_MISMATCH ((uint32_t)1 << 2 /* specifically a problem with the SMC */)
#define AF_E_USC_MISMATCH ((uint32_t)1 << 3 /* specifically a problem with the USC */)
#define AF_E_SATURATION   ((uint32_t)1 << 4 /* did not finish processing all detections in time */)
#define AF_E_TIMEOUT      ((uint32_t)1 << 5 /* exceeded the time limit entirely */)
// keep last:
#define AF_E_UNKNOWN ((uint32_t)1 << 31 /* unknown error occurred*/)

/*===========================================================================*
 * Interference detection stubs and constants
 *===========================================================================*/
/* Stub interference detection types */
typedef struct
{
   uint8_t *enable_id_ptr;
   uint16_t *nf_est_ptr;
   uint8_t *min_chirp_scaling_ptr;
   uint16_t *id_start_rbin_ptr;
   uint16_t *id_end_rbin_ptr;
   float32_t *low_degradation_thold_ptr;
   float32_t *med_degradation_thold_ptr;
   float32_t *high_degradation_thold_ptr;
   uint8_t *bv_scale_per_rbin_ptr;
   void *id_logging_out_ptr;
   float32_t *ref_mean_nf_ptr;
   float32_t *ref_nf_offset_ptr;
   float32_t *filter_coef_ptr;
   float32_t *data_discard_thold_ptr;
} ID_BB_Input_Params_T;

typedef struct
{
   float32_t nf_mean_db_value[1];
   float32_t nf_max_db_value[1];
   float32_t nf_min_db_value[1];
   uint8_t interference_detected;
   uint8_t id_version_re_release;
   uint8_t id_version_branch_identifier;
   uint8_t id_version_minor;
   uint8_t id_version_major;
   uint32_t interference_level;
   uint8_t range_check_interference;
   float32_t normalised_nf;
   uint8_t interference_health;
   uint8_t interference_data_discard;
} ID_MDF_BB_Internals_T;
/*===========================================================================*
 * Enum stubs
 *===========================================================================*/

/* DSP state machine states (matches ipc_data.h) */
typedef enum
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
   NUM_PROCESSING_STATES,
} DSP_Main_Application_State_T;

/* Memory pool return (matches mem_pool.h) */
typedef enum
{
   MEM_POOL_SUCCESS = 0u,
   MEM_POOL_FAILURE = 1u,
} Memory_Pool_Return_T;

/* Error field (matches ipc_commands.h) */
typedef enum
{
   ERRORFIELD_NO_ERROR = 0,
   ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR,
   ERRORFIELD_RANGE_PROCESS_ERROR,
   ERRORFIELD_RANGE_PROCESS_TIMEOUT,
   ERRORFIELD_DOPPLER_PROCESS_NOT_RUN,
   ERRORFIELD_DOPPLER_PROCESS_TIMEOUT,
   ERRORFIELD_DOPPLER_PROCESS_ERROR,
   ERRORFIELD_DOPPLER_PROCESS_MEMPOOL_FAILED,
   ERRORFIELD_POST_SIG_PROC_ERROR,
} Error_Field_T;

/* Trigger received (matches ipc_dsp.h) */
typedef enum
{
   NO_TRIGGER = 0,
   TRIGGER_RECEIVED
} Trigger_Received_T;

/* Range process return values (matches range_process_ifc.h) */
typedef enum
{
   APPL_RANGE_NO_ERROR = 0,
   APPL_RANGE_TIMEOUT  = 1,
   APPL_RANGE_ERROR    = 2,
} Appl_Range_Return_Values_T;

/* Doppler process return values (matches doppler_process_ifc.h) */
typedef enum
{
   APPL_DOPPLER_NO_ERROR = 0,
   APPL_DOPPLER_TIMEOUT  = 1,
   APPL_DOPPLER_ERROR    = 2,
} Appl_Doppler_Return_Values_T;

/* HIL component output update source (matches ipc_data.h) */
typedef enum
{
   HIL_EXECUTE_EMBEDDED_ALGO,
   HIL_EXECUTE_INJECTION_DATA,
   HIL_EXECUTE_VEHICLE_COM_DATA,
   HIL_EXECUTE_AUTOSAR_CAN_DATA,
} HIL_Component_Output_Update_Source_T;

/* Stream enum values used to index hil_enabled_streams[] (matches streams_cfg.h) */
enum
{
   DETECTION = 0,
   VSE,
   RDD,
   MMIC,
   CALIB,
   STATUS,
   ALIGNMENT,
   DEBUG,
   DRA,
   CDC,
   HEADER,
   RDD_DEBUG,
   RADAR_CAPABILITY,
   DETECTION_DEBUG,
   DOWN_SELECTION,
};

#define MAX_STREAMS_SH (40U)

/* AF return type */
typedef uint32_t AF_Retval_T;

/* Radar position (matches ipc_data.h) */
typedef enum
{
   RADAR_POSITION_REAR_LEFT    = 1U,
   RADAR_POSITION_REAR_RIGHT   = 2U,
   RADAR_POSITION_FRONT_RIGHT  = 3U,
   RADAR_POSITION_FRONT_LEFT   = 4U,
   RADAR_POSITION_FRONT_CENTER = 5U,
} Radar_Position_T;

/* Radar look type */
typedef uint32_t Radar_Look_T;

/* Radar mode type */
typedef uint8_t Radar_Mode_T;

/* Offline mode */
typedef uint32_t Offline_Mode_T;
#define ITF_ADC_INJECTION_MODE       (1U)
#define ITF_DATA_CUBE_INJECTION_MODE (2U)
#define ITF_TEST_COLLECTION_MODE     (3U)

/*===========================================================================*
 * Struct stubs — only the members actually accessed by main_application.c
 *===========================================================================*/

/* ProfilingStruct_t (matches profiling_helpers.h) */
typedef struct
{
   uint32_t lastRuntime;
   uint32_t maxRuntime;
   uint32_t averageRuntime;
   uint32_t samplesAveraged;
   uint32_t totalRuntime;
   uint32_t startTimestamp;
} ProfilingStruct_t;

/* Mem_Pool_T (matches mem_pool.h) */
typedef struct
{
   uint8_t *base_addr;
   uint32_t size;
   uint32_t max_size;
} Mem_Pool_T;

/* Look_Data_T (matches rdd_stream.h) */
typedef struct
{
   uint32_t start_dwell_nanosec;
   uint32_t start_dwell_sec;
   uint32_t end_dwell_nanosec;
   uint32_t end_dwell_sec;
   uint32_t mid_dwell_nanosec;
   uint32_t mid_dwell_sec;
   uint16_t look_id;
   uint16_t scan_type;
   uint16_t look_index;
   uint16_t scan_index;
   uint8_t start_dwell_status;
   uint8_t end_dwell_status;
   uint8_t mid_dwell_status;
   uint8_t mode;
} Look_Data_T;

/* Minimal stream / IPC stubs — match the real header layout used by the code under test */
typedef struct
{
   uint32_t size;           /* stream size */
   uint16_t version;        /* stream version */
   uint16_t checksum;       /* checksum of stream */
   uint16_t scan_index;     /* scan index */
   uint16_t error_info;     /* error information */
   uint32_t module_time_ms; /* module time in ms */
} Stream_Hdr_T;
typedef struct
{
   uint16_t cfar_nf_est[16][64]; /* Stub for interference detection access */
   uint8_t min_chirp_scaling;    /* Stub for interference detection access */
   uint8_t nci_bexp[16][64];     /* Stub for RBIN_SCALING_ENABLED access */
   uint8_t pad[3];               /* Padding for alignment */
} RDD_Data_T;

typedef struct
{
   Stream_Hdr_T stream_hdr;
   Look_Data_T look_data;
   RDD_Data_T rdd_data;
} Rdd_Stream_T;

typedef struct
{
   uint8_t d[4];
} XCP_Data_T;
typedef struct
{
   Stream_Hdr_T stream_hdr;
   uint8_t d[4];
} Rdd_Debug_Stream_T;
typedef struct
{
   uint8_t af_saturation_flag;
   uint8_t af_timeout_flag;
} AF_Diagnostics_Info_T;

typedef struct
{
   uint16_t look_type;
   uint16_t lookindex;
} AF_Str_Det_List_Property_T;

typedef struct
{
   AF_Str_Det_List_Property_T det_list_property;
   AF_Diagnostics_Info_T af_diagnostics_info;
} Detection_Stream_T;
typedef struct
{
   uint8_t d[4];
} Detection_Debug_Stream_T;
typedef struct
{
   uint8_t d[4];
} Angle_Data_XCP_T;
typedef struct
{
   uint8_t d[4];
} Static_Alignment_Log_Stream_T;
typedef struct
{
   uint8_t d[4];
} Dynamic_Alignment_Log_Stream_T;
typedef struct
{
   uint8_t d[4];
} Radar_Capability_Stream_T;
typedef struct
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
   uint8_t radar_data_discard;
   uint8_t radar_MMIC_config_error;
   uint8_t MMIC_reinit_request;
   uint8_t MMIC_error_id;
   uint8_t radar_ctl_state_idle;
   uint8_t radar_ctl_state_degraded;
   uint8_t radar_radiation_off;
   uint8_t K_radar_status_Unused8_1;
   uint8_t K_radar_status_Unused8_2;
} Radar_Data_Status_T;
typedef struct
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
   uint8_t radar_data_discard;
   uint8_t radar_MMIC_config_error;
   uint8_t MMIC_reinit_request;
   uint8_t MMIC_error_id;
   uint8_t radar_ctl_state_idle;
   uint8_t radar_ctl_state_degraded;
   uint8_t radar_radiation_off;
   uint8_t radar_ctl_pure_cw_mode;
   uint8_t K_radar_status_Unused8_2;
} TOI_Radar_Data_Status_Payload_T;
typedef struct TOI_Input_Params_Tag
{
   uint8_t det_proc_loop_overrun_flag_ip;
   uint8_t rdd1_saturation_occured_flag_ip;
   uint8_t interference_detected_ip;
   uint8_t range_check_interference_ip;
   uint8_t range_check_blockage_ip;
   uint8_t blockage_val_ip;
   uint8_t blockage_status_ip;
   uint8_t dsp_self_test_failure_flag_ip;
   uint16_t scan_index_ip;
   uint16_t look_id;
   int32_t det_ip_count;
   float32_t *snr_ip_ptr;
   int8_t *az_conf_ip_ptr;
   int8_t *el_conf_ip_ptr;
   int8_t *f_bistatic_ip_ptr;
   int8_t *f_single_target_ip_ptr;
   int8_t *f_ci_det_ip_ptr;
   float32_t *pow_ip_ptr;
   uintptr_t radar_ip_sts_ptr;
   void *af_ip_det_data;
   void *toi_data_status_dst_ptr;
} TOI_Input_Params_T;
typedef struct TOI_Output_Params_Tag
{
   void *toi_op_data_ptr;
   void *toi_op_stream_ptr;
} TOI_Output_Params_T;
typedef struct
{
   uint8_t d[4];
} TOI_Stream_T;

typedef struct
{
   uint8_t d[4];
} BBE_Cache_Info_T;
typedef struct
{
   uint8_t d[4];
} Angle_Timing_Data_T;
typedef struct
{
   uint8_t d[4];
} XCP_Info_T;

typedef struct
{
   uint32_t crc;
   uint32_t size;
   uint32_t counter;
} IPC_Header_T;

typedef struct
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
   uint8_t af_timeout_fault_flag;
} Diag_Data_T;

typedef struct
{
   ProfilingStruct_t state_profiling[NUM_PROCESSING_STATES];
   uint32_t rdd_time;
   Angle_Timing_Data_T af_time;
   ProfilingStruct_t range_process_time;
   ProfilingStruct_t curr_overall_frame_time;
   BBE_Cache_Info_T instruction_cache_info;
   BBE_Cache_Info_T data_cache_info;
} DSP_Timing_Data_T;

typedef struct
{
   Stream_Hdr_T stream_hdr;
   float32_t nf_mean_db_value[1];
   float32_t nf_max_db_value[1];
   float32_t nf_min_db_value[1];
   uint8_t interference_detected;
   uint8_t id_version_re_release;
   uint8_t id_version_branch_identifier;
   uint8_t id_version_minor;
   uint8_t id_version_major;
   uint8_t interference_level;
   uint8_t range_check_interference;
   float32_t normalised_nf;
   uint8_t interference_health;
   uint8_t interference_data_discard;
} ID_Stream_T;

/* HIL Rx mailbox (matches ipc_data.h — 32-byte cache-line aligned struct polled by BBE32) */
typedef struct
{
   uint8_t hil_rx_complete_flag;
   uint8_t reserved[31];
} HIL_Rx_Mailbox_T;

typedef struct
{
   DSP_Timing_Data_T dsp_timing_data;
   XCP_Data_T xcp_data;
   Rdd_Debug_Stream_T rdd_debug_data;
   Rdd_Stream_T rdd_stream_data;
   Diag_Data_T diag_data;
   Angle_Data_XCP_T xcp_af_data;
   Detection_Stream_T det_data;
   Detection_Debug_Stream_T det_debug_data;
   Static_Alignment_Log_Stream_T alignment_stream_data;
   Dynamic_Alignment_Log_Stream_T dynamic_alignment_log_stream;
   Radar_Capability_Stream_T radar_capability_data;
   TOI_Stream_T toi_stream_data;
   ID_Stream_T interference_detection_data;
   HIL_Rx_Mailbox_T hil_rx_mailbox;
} D2M_Payload_T;

typedef struct
{
   IPC_Header_T header;
   D2M_Payload_T payload;
} D2M_Msg_T;

void Update_RDD_Stream_Header(volatile D2M_Msg_T *d2m_msg_ptr, int error);

typedef struct
{
   uint32_t DSP_Main_Application_Idle_Counter;
   uint32_t DSP_Main_Application_Retry_Core_Init;
   uint32_t BBE32_Exception_Cause;
} D2M_Debug_Msg_T;

typedef struct
{
   D2M_Debug_Msg_T D2M_Debug_Msg;
} IPC_Shared_Buffers_T;

/* HIL IPC info (matches ipc_data.h — only members accessed by main_application.c) */
typedef struct
{
   uint32_t hil_scanindex;
   uint8_t hil_enabled_streams[MAX_STREAMS_SH];
   uint8_t hil_mode_enabled;
   uint8_t hil_entry_point;
   uint8_t hil_request_reinit_module;
   uint8_t hil_data_src_af;
   uint8_t hil_data_src_alignment;
   uint8_t hil_data_src_id;
   uint8_t hil_data_src_radar_capability;
   uint8_t hil_src_radar_mounting_data;
   uint8_t hil_src_vehicle_data;
   uint8_t hil_src_timestamp;
} HIL_Ipc_Info_T;

/* Vehicle data sub-structs for M2D path */
typedef struct
{
   float32_t veh_speed;
   uint8_t pad[60];
} Veh_Params_Stub_T;

typedef struct
{
   float32_t signed_filt_veh_speed_over_ground;
} Vse_Output_T;

typedef struct
{
   Veh_Params_Stub_T veh_params;
   Vse_Output_T vse_output;
   uint8_t vse_output_valid;
} Vse_Stream_T;

typedef struct
{
   XCP_Info_T xcp_info;
   uint8_t look_info_pad[64];
   Vse_Stream_T veh_data;
   uint32_t offline_mode_flag;
   int16_t avg_mmic_onchip_temp;
   HIL_Ipc_Info_T hil_ipc_info;
} M2D_Payload_T;

typedef struct
{
   IPC_Header_T header;
   M2D_Payload_T payload;
} M2D_Msg_T;

/* Calib_Data_T stub (matches ipc_data.h — only members accessed) */
typedef struct
{
   uint8_t data_availability_status;
} Calib_Data_T;

typedef struct
{
   uint32_t usc_sram_address;
   uint32_t smc_sram_address;
   Calib_Data_T calib_data;
   uint8_t radar_position;
} M2D_One_Time_Msg_T;

/* Dynamic alignment / capability / static alignment I/O types */
typedef struct
{
   uint8_t data[64];
} DYN_ALIGN_INPUT_T;
typedef struct
{
   uint8_t data[64];
} RC_Input_Data_T;
typedef struct
{
   uint8_t data[64];
} SA_Input_Data_T;

/* AF application I/O stubs (matches angle_finding_project_interface.h) */
typedef struct
{
   void *appl_rdd_data_ptr;
   void *appl_xcp_data_ptr;
   void *appl_xcp_info_data_ptr;
   void *appl_look_data_ptr;
   float32_t *appl_veh_speed_ptr;
   uint8_t *appl_radar_position_ptr;
   uint32_t appl_doppler_start_time;
   Calib_Data_T *calib_data_ptr;
} AF_Appl_Input_T;

typedef struct
{
   Detection_Stream_T *appl_detection_stream_data_ptr;
   Detection_Debug_Stream_T *appl_detection_debug_data_ptr;
   Angle_Data_XCP_T *appl_af_xcp_data_ptr;
   Angle_Timing_Data_T *appl_af_timing_data_ptr;
} AF_Appl_Output_T;

/* Interference detection I/O stubs */
typedef struct
{
   Rdd_Stream_T *p_rdd_stream;
   Vse_Stream_T *p_vse_stream;
   ID_Stream_T *p_id_stream;
} ID_INPUT_T;

/*===========================================================================*
 * Extern variable declarations
 *===========================================================================*/
extern volatile Trigger_Received_T IPC_R52_To_BBE_Trigger_Received;
extern Offline_Mode_T Offline_Mode_Flag_DSP;

/*===========================================================================*
 * FFF fake declarations — every external function called by
 * main_application.c
 *===========================================================================*/

/* Memory pool */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Init, Mem_Pool_T *, void *, uint32_t);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
DECLARE_FAKE_VOID_FUNC(Mem_Pool_Reset, Mem_Pool_T *);

/* IPC communication */
DECLARE_FAKE_VOID_FUNC(Appl_DSP_Process_Onetime_Init);
DECLARE_FAKE_VOID_FUNC(Reset_IPC_AF_Buffer, bool, bool);
DECLARE_FAKE_VOID_FUNC(Send_Range_Proc_Complete, uint32_t);
DECLARE_FAKE_VOID_FUNC(Send_Doppler_RDD_Proc_Complete, uint32_t);
DECLARE_FAKE_VOID_FUNC(Send_SP_Post_Proc_Complete_to_R52, uint32_t);
DECLARE_FAKE_VOID_FUNC(Update_DSP_IPC_Notify);
DECLARE_FAKE_VOID_FUNC(Send_Core_Initialization);
DECLARE_FAKE_VALUE_FUNC(bool, Wait_For_Trigger, volatile uint32_t *);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_Ipc_Shared_Buffer_Base_Address);

/* IPC buffer getters */
DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_RP_IPC_D2M_Msg_Buffer);
DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_DP_RDD_IPC_D2M_Msg_Buffer);
DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
DECLARE_FAKE_VALUE_FUNC(M2D_Msg_T *, Get_IPC_M2D_Buffer);
DECLARE_FAKE_VALUE_FUNC(M2D_One_Time_Msg_T *, Get_IPC_M2D_One_Time_Buffer);

/* Custom fake functions for IPC buffer getters (defined in fake.cc) */
D2M_Msg_T *Get_RP_IPC_D2M_Msg_Buffer_custom(void);
D2M_Msg_T *Get_DP_RDD_IPC_D2M_Msg_Buffer_custom(void);
D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom(void);
M2D_Msg_T *Get_IPC_M2D_Buffer_custom(void);
M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer_custom(void);
TOI_Input_Params_T *Get_TOI_Init_Parameters_custom(void);
TOI_Output_Params_T *Get_TOI_Output_Parameters_custom(void);
ID_BB_Input_Params_T *Get_ID_Init_Parameters_custom(void);
ID_MDF_BB_Internals_T *Get_ID_BB_Internals_custom(void);

/* Range processing */
DECLARE_FAKE_VALUE_FUNC(Appl_Range_Return_Values_T, Check_For_Range_Process_Complete_Timeout_Check, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_Range_Procesing_Done_Time);

/* Doppler processing */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Doppler_Dram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Doppler_Sram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(Appl_Doppler_Return_Values_T, Appl_Doppler_Rdd_Processing, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Set_MMIC_Data_Discard_Info);

/* RDD sub-module init fakes */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Dram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Sram1_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Rdd_Fp_Init, uint32_t);
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Second_Pass_Init, uint32_t);
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Sweep_Bw_Init, uint32_t);

/* FuSa BBE self-test */
DECLARE_FAKE_VOID_FUNC(Enable_Dsp_Ecc);
DECLARE_FAKE_VOID_FUNC(Enable_Dsp_Parity);
DECLARE_FAKE_VOID_FUNC(RA_ESTMEM_ECC_Enable);
#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(Set_RA_SEC_Threshold);
   DECLARE_FAKE_VOID_FUNC(RA_Fault_Injection_Execute);
#ifdef __cplusplus
}
#endif
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_BBE_Self_Test_Memory_Init, Mem_Pool_T *, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Fusa_BBE_Check_Execute);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Update_FUSA_BBE_Self_Test_Fault_Flag, uint32_t);

/* Angle finding */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Anglefinding_Memory_Init, Mem_Pool_T *, Mem_Pool_T *);
DECLARE_FAKE_VALUE_FUNC(AF_Retval_T, Appl_Angle_Finding_Process, AF_Appl_Input_T *, AF_Appl_Output_T *);

/* Radar capability */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Capability_Handler_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VOID_FUNC(rc_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* TOI / radar data quality */
DECLARE_FAKE_VOID_FUNC(TOI_Init);
DECLARE_FAKE_VOID_FUNC(TOI_Parameters_Init);
DECLARE_FAKE_VOID_FUNC(Determine_Data_Quality, TOI_Input_Params_T *, TOI_Output_Params_T *);
DECLARE_FAKE_VALUE_FUNC(TOI_Input_Params_T *, Get_TOI_Init_Parameters);
DECLARE_FAKE_VALUE_FUNC(TOI_Output_Params_T *, Get_TOI_Output_Parameters);
DECLARE_FAKE_VOID_FUNC(TOI_Radar_Status_Info_Init, TOI_Input_Params_T *);

/* Static alignment */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, SA_Alignment_Handler_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VOID_FUNC(static_align_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* Dynamic alignment */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Alignment_Handler_Memory_Init, Mem_Pool_T *);
DECLARE_FAKE_VOID_FUNC(dyn_align_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* Tracker wrapper */
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Emb_Tracker_Mem_Init, Mem_Pool_T *, D2M_Msg_T *);
DECLARE_FAKE_VOID_FUNC(Init_Emb_Tracker, volatile M2D_One_Time_Msg_T *, M2D_Msg_T *);
DECLARE_FAKE_VOID_FUNC(Run_Emb_Tracker, D2M_Msg_T *, M2D_Msg_T *, volatile M2D_One_Time_Msg_T *);

/* BBE32 static register validation */
DECLARE_FAKE_VOID_FUNC(Bbe32_Static_Register_Safety_Check);

/* Profiling / timing helpers */
DECLARE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Time_Microsec, uint32_t);
DECLARE_FAKE_VOID_FUNC(Profiling_Helpers_Init, void *, bool);
DECLARE_FAKE_VOID_FUNC(Profiling_Helpers_Update, ProfilingStruct_t *);

/* Performance monitor */
DECLARE_FAKE_VOID_FUNC(Initialize_Perfmon_Info);
DECLARE_FAKE_VOID_FUNC(Update_IPC_Perfmon_Info, BBE_Cache_Info_T *, BBE_Cache_Info_T *);
/* Interference detection */
DECLARE_FAKE_VOID_FUNC(interference_detection_wrapper, M2D_Msg_T *, D2M_Msg_T *);
DECLARE_FAKE_VOID_FUNC(ID_Init_BB_Params, ID_INPUT_T *);
DECLARE_FAKE_VOID_FUNC(ID_Populate_Logging_Structure, ID_INPUT_T *);
DECLARE_FAKE_VOID_FUNC(ID_Clear_Logging_Data);
DECLARE_FAKE_VALUE_FUNC(ID_BB_Input_Params_T *, Get_ID_Init_Parameters);
DECLARE_FAKE_VALUE_FUNC(ID_MDF_BB_Internals_T *, Get_ID_BB_Internals);
DECLARE_FAKE_VOID_FUNC(ID_Init);
DECLARE_FAKE_VOID_FUNC(Interference_Detection);
