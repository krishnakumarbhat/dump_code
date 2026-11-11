#ifndef DSP_INTEGRATION_TEST_H
   #define DSP_INTEGRATION_TEST_H
/*===========================================================================*/
/**
 * @file dsp_integration_test.h
 *
 * SWE5 Integration Test Header for BBE32/DSP Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Provides type declarations, function prototypes, and enumeration definitions
 *   for the BBE32/DSP core integration test (SWE5) framework. Includes interface
 *   enumeration (Test_Interface_Name_T) and global pointer structures (G_Pointer_T)
 *   for debugger visibility.
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC  - Inter-Processor Communication
 *   - SWE5 - Software Engineering Level 5 (Integration Testing)
 *   - SIT  - Software Integration Testing
 *   - RDD  - Range Doppler Detection
 *   - AF   - Angle Finding
 *   - USC  - Unit Specific Calibration
 *   - D2M  - DSP to Master
 *   - M2D  - Master to DSP
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWE5 Integration Test Framework Design
 *
 *   - Requirements Document(s):
 *     - Integration test framework for Gen8 radar system
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @defgroup dsp_integration_test DSP Integration Test
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

   #if defined(Integration_Testing)

      /*===========================================================================*
       * Standard Header Files
       *===========================================================================*/
      #include <stdbool.h>
      #include <stdint.h>

      /*===========================================================================*
       * Other Header Files
       *===========================================================================*/
      #include "ipc_data.h"
      #include "usc_cal.h"

      #if defined(Anglefinding_IT) || defined(Radar_capability_IT)
         #include "angle_finding_project_interface.h"
         #include "rdd_stream.h"
         #include "stream_header.h"
      #endif /* Anglefinding_IT || Radar_capability_IT */

      #if defined(FirstPass_IT)
         #include "rdd_first_pass_types.h" /* Provides Rdd_First_Pass_Input_T type */
         #include "spbb_configuration.h"   /* Provides NCI buffer depth macros, MAP_NUM_ANGLES, SPBB_MAX_DOPPLER_FFT_SIZE */
      #endif                               /* FirstPass_IT */

      #if defined(Radar_capability_IT)
         #include "rc_wrapper.h"
typedef struct RC_Input_Tag RC_Input_T;
      #endif /* Radar_capability_IT */

      /*===========================================================================*
       * Preprocessor #define Constants
       *===========================================================================*/
      /* Tolerance for floating point validation - 1e-5 matches Gen7_V2 tolerance */
      #define SWE5_VALIDATION_TOLERANCE (1e-5F)

   /* Note: AF_CAL_SEC_N is defined in afbb_cfg.h, do not redefine here */

   /*===========================================================================*
    * Preprocessor #define MACROS
    *===========================================================================*/

   /**
    * @brief Helper macros for conditional inclusion based on module.
    */
      #if defined(Anglefinding_IT)
         #define IF_ANGLEFINDING(x) x
      #else
         #define IF_ANGLEFINDING(x)
      #endif /* Anglefinding_IT */

      #if defined(Radar_capability_IT)
         #define IF_RADAR_CAPABILITY(x) x
      #else
         #define IF_RADAR_CAPABILITY(x)
      #endif /* Radar_capability_IT */

      #if defined(FirstPass_IT)
         #define IF_FIRSTPASS(x) x
      #else
         #define IF_FIRSTPASS(x)
      #endif /* FirstPass_IT */

      /* Direct expansion for variant macros to avoid double-nesting issues with Diab/Xtensa compilers */
      #if defined(FLR8) && (defined(Anglefinding_IT) || defined(Radar_capability_IT))
         #define IF_FLR8_VARIANT(x) x
      #else
         #define IF_FLR8_VARIANT(x)
      #endif /* FLR8 && (Anglefinding_IT || Radar_capability_IT) */

      #if defined(SRR8P) && (defined(Anglefinding_IT) || defined(Radar_capability_IT))
         #define IF_SRR8P_VARIANT(x) x
      #else
         #define IF_SRR8P_VARIANT(x)
      #endif /* SRR8P && (Anglefinding_IT || Radar_capability_IT) */

   /*===========================================================================*
    * Interface Enumeration List (DCS_X-macro pattern)
    *===========================================================================*/

   /**
    * @brief Master Interface Enumeration List using X-macro pattern.
    *
    * This macro defines all test interface names and their corresponding
    * numeric values (work item IDs). It is expanded using the DCS_X macro to generate:
    * - Enum values for interface identification
    * - Switch case labels for validation in Is_Valid_Interface()
    *
    * Interfaces are grouped by module and guarded by module-specific macros.
    * New interfaces should be added in the appropriate section with unique values.
    */
      #define INTERFACE_ENUM_LIST                                                                                                 \
         /* RDD Stream Interfaces - Angle Finding Input */                                                                        \
         IF_ANGLEFINDING(DCS_X(Ri_beam_vector, 392701U))             /* WI-379775: rdd1_bv[detect][TX][RX] */                     \
         IF_ANGLEFINDING(DCS_X(Ri_rdd_snr, 362404U))                 /* WI-362404: rdd2_snr[detect] */                            \
         IF_ANGLEFINDING(DCS_X(Ri_range_rate, 362403U))              /* WI-362403: rdd2_range_rate[detect] */                     \
         IF_ANGLEFINDING(DCS_X(Ri_range, 362402U))                   /* WI-362402: rdd2_range[detect] */                          \
         IF_ANGLEFINDING(DCS_X(Ri_scan_index, 362399U))              /* WI-362399: look_data.scan_index */                        \
         IF_ANGLEFINDING(DCS_X(Ri_look_type, 362398U))               /* WI-362398: look_data.look_id */                           \
         IF_ANGLEFINDING(DCS_X(Ri_sp_fail_flag, 294068U))            /* WI-294068: rdd2_sp_fail_flag[detect] */                   \
         IF_ANGLEFINDING(DCS_X(Ri_sp_num_detections, 294066U))       /* WI-294066: rdd2_num_detect */                             \
         IF_ANGLEFINDING(DCS_X(Ri_fp_num_detections, 294052U))       /* WI-294052: rdd1_num_detect */                             \
         IF_ANGLEFINDING(DCS_X(Ri_range_doppler_amplitude, 294048U)) /* WI-294048: rdd1_rdop_amp[detect] */                       \
         IF_ANGLEFINDING(DCS_X(Ri_range_bin_index, 294049U))         /* WI-294049: rdd1_rindx[detect] */                          \
         IF_ANGLEFINDING(DCS_X(Ri_CR_response, 294047U))             /* WI-294047: bwdep_cr_resp[rbin] */                         \
         IF_ANGLEFINDING(DCS_X(Ri_nci_bexp, 399434U))                /* WI-399434: nci_bexp[rbin] */                              \
         IF_ANGLEFINDING(DCS_X(Ri_look_index, 399606U))              /* WI-399606: look_data.look_index */                        \
         IF_ANGLEFINDING(DCS_X(Ri_range_coverage, 379779U))          /* WI-379779: look_data.range_coverage */                    \
         IF_ANGLEFINDING(DCS_X(Ri_doppler_coverage, 379778U))        /* WI-379778: look_data.doppler_coverage */                  \
         IF_ANGLEFINDING(DCS_X(Ri_host_vehicle_speed, 362349U))      /* WI-362349: veh_speed */                                   \
         IF_ANGLEFINDING(DCS_X(Ri_radar_position, 362359U))          /* WI-362359: radar_position */                              \
         /* Timestamp/Dwell Interfaces */                                                                                         \
         IF_ANGLEFINDING(DCS_X(Ri_ts_start_dwell_nanosec, 385403U)) /* WI-385403: look_data.start_dwell_nanosec */                \
         IF_ANGLEFINDING(DCS_X(Ri_ts_start_dwell_sec, 385404U))     /* WI-385404: look_data.start_dwell_sec */                    \
         IF_ANGLEFINDING(DCS_X(Ri_ts_start_dwell_status, 385397U))  /* WI-385397: look_data.start_dwell_status */                 \
         IF_ANGLEFINDING(DCS_X(Ri_ts_end_dwell_nanosec, 385408U))   /* WI-385408: look_data.end_dwell_nanosec */                  \
         IF_ANGLEFINDING(DCS_X(Ri_ts_end_dwell_sec, 385406U))       /* WI-385406: look_data.end_dwell_sec */                      \
         IF_ANGLEFINDING(DCS_X(Ri_ts_end_dwell_status, 385405U))    /* WI-385405: look_data.end_dwell_status */                   \
         IF_ANGLEFINDING(DCS_X(Ri_ts_mid_dwell_nanosec, 385409U))   /* WI-385409: look_data.mid_dwell_nanosec */                  \
         IF_ANGLEFINDING(DCS_X(Ri_ts_mid_dwell_sec, 385410U))       /* WI-385410: look_data.mid_dwell_sec */                      \
         IF_ANGLEFINDING(DCS_X(Ri_ts_mid_dwell_status, 385407U))    /* WI-385407: look_data.mid_dwell_status */                   \
         /* USC Calibration Interfaces for Angle Finding */                                                                       \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_tx_cal_matrix, 294040001U))  USC_AF_Cal.k_calmat1_ctx[4][8] as creal32_T*    */       \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_rx_cal_matrix, 294040002U))  USC_AF_Cal.k_calmat1_crx[8][16] as creal32_T*   */       \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_cal_matrix, 294040003U))     USC_AF_Cal.k_calmat1_c1[32][64] as creal32_T*   */       \
         /* SMC Downselection Interfaces */                                                                                       \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_enable_aa_az, 345643001U))            /* WI-345643001: enable_aa_az */                   \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_enable_aa_el, 345643002U))            /* WI-345643002: enable_aa_el */                   \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_enable_az_proj, 345643003U))          /* WI-345643003: enable_az_proj */                 \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_enable_el_proj, 345643004U))          /* WI-345643004: enable_el_proj */                 \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_num_unfolding_intervals, 345643005U)) /* WI-345643005: num_unfolding_intervals */        \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_score_selection, 345643006U))         /* WI-345643006: score_selection */                \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_moving_thold, 345643007U))            /* WI-345643007: moving_thold */                   \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_flag_enable_ds, 345643008U))          /* WI-345643008: flag_enable_ds */                 \
         IF_ANGLEFINDING(DCS_X(Ri_smc_ds_max_target_reports, 345643009U))      /* WI-345643009: max_target_reports */             \
         /* Unambiguous Velocity Interface */                                                                                     \
         IF_ANGLEFINDING(DCS_X(Ri_unambiguous_velocity, 399436U)) /* WI-399436: unambiguous_velocity */                           \
         /* Sensor Mounting Position Interfaces */                                                                                \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_pos_x, 294037001U))      /* WI-294037001: sensor_mount_pos_x */                    \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_pos_y, 294037002U))      /* WI-294037002: sensor_mount_pos_y */                    \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_pos_z, 294037003U))      /* WI-294037003: sensor_mount_pos_z */                    \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_ornt_roll, 294037004U))  /* WI-294037004: sensor_mount_ornt_roll */                \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_ornt_pitch, 294037005U)) /* WI-294037005: sensor_mount_ornt_pitch */               \
         IF_ANGLEFINDING(DCS_X(Ri_sensor_mount_ornt_yaw, 294037006U))   /* WI-294037006: sensor_mount_ornt_yaw */                 \
         /* RCS Rolloff Limit Interfaces */                                                                                       \
         /* IF_ANGLEFINDING(DCS_X(Ri_k_rcs_az_rolloff_limit_str_0, 399439001U)) WI-399439001: k_rcs_az_rolloff_limit[0] */        \
         /* IF_ANGLEFINDING(DCS_X(Ri_k_rcs_az_rolloff_limit_str_1, 399439002U)) WI-399439002: k_rcs_az_rolloff_limit[1] */        \
         /* IF_ANGLEFINDING(DCS_X(Ri_k_rcs_el_rolloff_limit_str_0, 399439003U)) WI-399439003: k_rcs_el_rolloff_limit[0] */        \
         /* IF_ANGLEFINDING(DCS_X(Ri_k_rcs_el_rolloff_limit_str_1, 399439004U)) WI-399439004: k_rcs_el_rolloff_limit[1] */        \
         /* Radar Capability interfaces */                                                                                        \
         IF_RADAR_CAPABILITY(DCS_X(Ri_vacs_boresight_el_estimated, 380006U)) /* WI-380006 : vacs_boresight_el_estimated */        \
         IF_RADAR_CAPABILITY(DCS_X(Ri_vacs_boresight_el_nominal, 370541U))   /* WI-370541 : vacs_boresight_el_nominal */          \
         IF_RADAR_CAPABILITY(DCS_X(Ri_vacs_boresight_az_nominal, 398900U))   /* WI-398900 : vacs_boresight_az_nominal */          \
         IF_RADAR_CAPABILITY(DCS_X(Ri_vacs_boresight_az_estimated, 398901U)) /* WI-398901 : vacs_boresight_az_estimated */        \
         IF_RADAR_CAPABILITY(                                                                                                     \
            DCS_X(Ri_error_status_el_est_out_of_bounds, 380005U)) /* WI-380005 : error_status_el_est_out_of_bounds */             \
         IF_RADAR_CAPABILITY(                                                                                                     \
            DCS_X(Ri_error_status_az_est_out_of_bounds, 398902U))        /* WI-398902 : error_status_az_est_out_of_bounds */      \
         IF_RADAR_CAPABILITY(DCS_X(Ri_elevation_estimation_qf, 370553U)) /* WI-370553 : elevation_estimation_qf */                \
         IF_RADAR_CAPABILITY(DCS_X(Ri_azimuth_estimation_qf, 398903U))   /* WI-398903 : azimuth_estimation_qf */                  \
         IF_RADAR_CAPABILITY(DCS_X(Ri_avg_mmic_onchip_temp, 370545U))    /* WI-370545: avg_mmic_onchip_temp */                    \
         IF_RADAR_CAPABILITY(DCS_X(Ri_host_speed, 370537U))              /* WI-370537 : host_speed */                             \
         IF_RADAR_CAPABILITY(DCS_X(Ri_host_yawrate, 370539U))            /* WI-370539 : host_yawrate */                           \
         IF_RADAR_CAPABILITY(DCS_X(Ri_rdd_max_per_range_bin, 370568U))   /* WI-370568 : rdd_max_per_range_bin */                  \
         IF_RADAR_CAPABILITY(DCS_X(Ri_cfar_nf_est, 370570U))             /* WI-370570 : cfar_nf_est */                            \
         IF_RADAR_CAPABILITY(DCS_X(Ri_min_chirp_scaling, 370573U))       /* WI-370573 : min_chirp_scaling */                      \
         IF_RADAR_CAPABILITY(DCS_X(Ri_look_data_0, 370549001U))          /* WI-370549001 : look_data_0 */                         \
         IF_RADAR_CAPABILITY(DCS_X(Ri_look_data_1, 370549002U))          /* WI-370549002 : look_data_1 */                         \
         /* First Pass interfaces */                                                                                              \
         IF_FIRSTPASS(DCS_X(Ri_NCI_prev_rdop_avg, 365501U)) /* WI-365501: prev_ptr / rdop_avg_data_ptr[NCI_PREV_BUFFER_DEPTH] */  \
         IF_FIRSTPASS(                                                                                                            \
            DCS_X(Ri_NCI_curr_rdop_avg, 365503U)) /* WI-365503: curr_ptr / rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH] */         \
         IF_FIRSTPASS(DCS_X(Ri_NCI_next_rdop_avg, 365505U)) /* WI-365505: next_ptr / rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH] */  \
         /* Other Module Interfaces can be added below with appropriate guards */

/**
 * @brief Enumeration of test interface names generated from INTERFACE_ENUM_LIST.
 *
 * Each interface is assigned a unique value for identification during testing.
 */
typedef enum Test_Interface_Name_Tag
{
   Test_Interface_None = 0U, /**< Default/invalid interface */
      #define DCS_X(name, value) name = value,
   INTERFACE_ENUM_LIST
      #undef DCS_X
} Test_Interface_Name_T;

/*===========================================================================*
 * Type Declarations
 *===========================================================================*/

/**
 * @brief Enumeration defining data types for stubbing/validation operations.
 *
 * Used to specify the type of data being stubbed or validated,
 * enabling type-safe operations across different variable types.
 */
typedef enum DataType_Tag
{
   DATATYPE_UINT8 = 0U, /**< Unsigned 8-bit integer */
   DATATYPE_UINT16,     /**< Unsigned 16-bit integer */
   DATATYPE_UINT32,     /**< Unsigned 32-bit integer */
   DATATYPE_INT16,      /**< Signed 16-bit integer */
   DATATYPE_INT32,      /**< Signed 32-bit integer */
   DATATYPE_FLOAT32,    /**< 32-bit floating point */
   DATATYPE_ENUM        /**< Enumeration type (treated as uint8_t) */
} DataType_T;

/**
 * @brief Union for type-safe pointer casting during stub/validate operations.
 *
 * Provides a clean way to cast void pointers to specific types
 * without violating strict aliasing rules.
 */
typedef union Data_Ptr_Tag
{
   void *ptr;     /**< Generic pointer */
   uint8_t *u8;   /**< Pointer to uint8_t */
   uint16_t *u16; /**< Pointer to uint16_t */
   uint32_t *u32; /**< Pointer to uint32_t */
   int16_t *i16;  /**< Pointer to int16_t */
   int32_t *i32;  /**< Pointer to int32_t */
   float *f32;    /**< Pointer to float */
} Data_Ptr_T;

/**
 * @brief Global pointer structure for debugger visibility.
 *
 * Allows debugger to inspect test data with metadata about
 * element size, count, name and type.
 */
typedef struct G_Pointer_Tag
{
   Data_Ptr_T data;            /**< Pointer to the actual data */
   size_t elem_size;           /**< Size of each element in bytes */
   size_t no_of_elements;      /**< Number of elements in array */
   Test_Interface_Name_T name; /**< Enum identifying variable for debugger */
   DataType_T data_type;       /**< Data type for proper interpretation */
} G_Pointer_T;

/*===========================================================================*
 * Global Variable Declarations (external linkage)
 *===========================================================================*/
/* Global pointer structures for debugger visibility */
extern volatile G_Pointer_T DSP_Shared_Pi; /**< DSP Provider pointer */
extern volatile G_Pointer_T DSP_Shared_Ri; /**< DSP Receiver pointer */

/*===========================================================================*
 * Function Prototypes
 *===========================================================================*/

/**
 * @brief Receive SIT test data from M2D IPC buffer.
 *
 * Called from ipc_dsp.c when M2D data is received.
 * Extracts test parameters (interface number, stub value, stub length)
 * from M2D payload for use in DSP stubbing/validation.
 *
 * @param[in] m2d_payload_ptr Pointer to M2D payload structure
 */
void SIT_IPC_Transfer_M2D_Receive(const M2D_Payload_T *m2d_payload_ptr);

/**
 * @brief Send SIT test result back to R52 via D2M IPC buffer.
 *
 * Called from ipc_dsp.c before D2M header update.
 * Populates D2M payload with DSP test result for R52 to receive.
 *
 * @param[in,out] d2m_payload_ptr Pointer to D2M payload structure
 */
void SIT_IPC_Transfer_D2M_Send(D2M_Payload_T *d2m_payload_ptr);

   /* Anglefinding-specific receiver functions */
      #if defined(Anglefinding_IT) || defined(Radar_capability_IT)
/**
 * @brief Provider function to inject test values into RDD data.
 *
 * Called at end of Appl_Doppler_Rdd_Processing() in doppler_process_ifc.c.
 * Stubs RDD data values that will be consumed by Angle Finding module
 * to enable data flow validation through the processing chain.
 *
 * @param[in,out] d2m_msg_ptr Pointer to D2M message structure containing RDD data
 */
void SIT_D2M_Msg_Buffer_Provider(D2M_Msg_T *d2m_msg_ptr);

/**
 * @brief Provider function to inject test values into dwell timestamp data.
 *
 * Called in Doppler_Handler after dwell timestamp calculation.
 * Stubs timestamp/dwell fields in Look_Data_T structure for validation.
 * Separated from main D2M provider to isolate timestamp-specific test cases.
 *
 * @param[in,out] d2m_msg_ptr Pointer to D2M message structure containing Look_Data_T
 */
void SIT_Dwell_Timestamps_Provider(D2M_Msg_T *d2m_msg_ptr);

/**
 * @brief Receiver function for Anglefinding input data validation.
 *
 * Called after Anglefinding input copy. Validates that stubbed values
 * from R52 provider were correctly received through IPC and
 * processing chain.
 *
 * @param[in] af_input_ptr Pointer to Anglefinding input structure
 * @param[in] appl_out_ptr Pointer to AF_Appl_Output_T structure
 */
void SIT_AF_Input_Receiver(const Angle_Finding_Input_T *af_input_ptr, const AF_Appl_Output_T *appl_out_ptr);

         #if 0  /* Disabled - AF_USC_T_Temp not yet available in Gen8 */
/**
 * @brief USC calibration validation function for Angle Finding.
 *
 * Called to validate USC calibration parameters received by BBE32.
 * Validates lookup tables, calibration matrices, and angle ranges.
 *
 * @param[in] af_usc_ptr Pointer to AF_USC_T calibration structure
 */
void SIT_AF_USC_Receiver(void *af_usc_void_ptr);
         #endif /* #if 0 */

/**
 * @brief Downselection calibration receiver - validates downselection params.
 *
 * Called from af_downselection.c to validate that downselection calibration
 * parameters were correctly received.
 *
 * @param[in] p_af_ds_inout_param Pointer to AF downselection params structure
 */
void SIT_AF_Downselection_Receiver(AF_DownSelection_In_Out_Params_T *af_ds_init_params);

/**
 * @brief RCS rolloff limit receiver - validates RCS calibration parameters.
 *
 * Called from compute_rcs.c to validate that RCS rolloff limit
 * calibration parameters were correctly received.
 *
 * @param[in] k_rcs_az_rolloff Pointer to azimuth RCS rolloff limit array
 * @param[in] k_rcs_el_rolloff Pointer to elevation RCS rolloff limit array
 */
void SIT_Compute_RCS_Receiver(float32_t *k_rcs_az_rolloff, float32_t *k_rcs_el_rolloff);
      #endif /* Anglefinding_IT || Radar_capability_IT */

      #if defined(Radar_capability_IT)
/**
 * @brief Provider function for Dynamic Alignment log data.
 *
 * Called before Dynamic Alignment log data is sent back. Stubs log data
 * for validation by R52 receiver.
 *
 */
void SIT_ALIGNMENT_LOG_DATA_Provider(Dynamic_Alignment_Log_Stream_T *alignment_log_ptr);
/**
 * @brief Receiver function for Dynamic Alignment data.
 *
 * Called after Dynamic Alignment data is received. Validates that stubbed values
 * from R52 provider were correctly received through IPC and processing chain.
 *
 */
void SIT_DYNAMIC_ALIGN_DATA_Receiver(RC_Input_T *rc_input);
/**
 * @brief Receiver function for average MMIC on-chip temperature data.
 *
 * Called after average MMIC on-chip temperature data is received. Validates that stubbed value
 * from R52 provider was correctly received through IPC and processing chain.
 * @param[in] rc_input_ptr Pointer to RC_Input_T structure containing avg MMIC on-chip temp
 *
 */
void SIT_AVG_MMIC_ONCHIP_TEMP_DATA_Receiver(RC_Input_T *rc_input);

      #endif /* Radar_capability_IT */
             /* First Pass-specific functions */
      #if defined(FirstPass_IT)
/**
 * @brief Provider function for First Pass input data source.
 *
 * Called in Appl_Doppler_Rdd_Processing() at the Circular_Buffer_Update point.
 * Stubs rdop_avg_data_ptr[NCI_PREV_BUFFER_DEPTH],
 * rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH], and
 * rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH] for
 * WI-365501/WI-365503/WI-365505 Pi flows.
 *
 * @param[in,out] rdop_data_ptr Pointer array to NCI circular buffers
 */
void SIT_FP_Output_Data_Provider(uint16_t **rdop_data_ptr);

/**
 * @brief Receiver function for First Pass input validation.
 *
 * Called from Appl_First_Pass_Execute().
 * Validates rdd_fp_input->prev_ptr, rdd_fp_input->curr_ptr, and
 * rdd_fp_input->next_ptr for WI-365501/WI-365503/WI-365505 Ri flows.
 *
 * @param[in] rdd_fp_input Pointer to First Pass input structure
 */
void SIT_FP_Input_Receiver(const Rdd_First_Pass_Input_T *rdd_fp_input);

      #endif /* FirstPass_IT */
   #endif    /* Integration_Testing */

/** @} doxygen end group */
#endif /* DSP_INTEGRATION_TEST_H */

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  DC          Dinesh ch
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  26-02-10      1.0              DC           EAH-7658
 *      Created initial SWE5 automation framework
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
