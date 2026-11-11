#ifndef MASTER_INTEGRATION_TEST_H
   #define MASTER_INTEGRATION_TEST_H
/*===========================================================================*/
/**
 * @file master_integration_test.h
 *
 * SWE5 Integration Test Header for R52/Master Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Declares stubbing and validation APIs for R52/Master core integration test
 *   (SWE5) hooks. Includes interface enumeration (Test_Interface_Name_T) and
 *   global pointer structures (G_Pointer_T) for debugger visibility.
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC  - Inter-Processor Communication
 *   - SWE5 - Software Engineering Level 5 (Integration Testing)
 *   - SIT  - Software Integration Testing
 *   - D2M  - DSP to Master
 *   - M2D  - Master to DSP
 *   - USC  - Unit Specific Calibration
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
 * @defgroup master_integration_test Master Integration Test
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

   #ifdef __cplusplus
extern "C"
{         /* ! Inclusion of header files should NOT be inside the extern "C" block */
   #endif /* __cplusplus */

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

      #if defined(Anglefinding_IT)
         #include "smc_cal.h"
         #include "usc_cal.h"
      #endif /* Anglefinding_IT */

      /*===========================================================================*
       * Local Preprocessor #define Constants
       *===========================================================================*/
      #define SWE5_VALIDATION_TOLERANCE (1e-5F)

      /*===========================================================================*
       * Local Preprocessor #define MACROS
       *===========================================================================*/

      /* Helper macros for conditional inclusion based on module */
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

      /* Direct expansion for variant macros to avoid double-nesting issues with Diab compiler */
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

      /* Test interface enumeration - requirement interface names mapped to work items */
      #define INTERFACE_ENUM_LIST                                                                                                 \
         /* Angle Finding Interfaces */                                                                                           \
         IF_ANGLEFINDING(DCS_X(Ri_radar_position, 362359U))     /* WI-362359: radar_position */                                   \
         IF_ANGLEFINDING(DCS_X(Ri_host_vehicle_speed, 362349U)) /* WI-362349: veh_speed */                                        \
         /* USC Calibration Interfaces */                                                                                         \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_tx_cal_matrix, 294040001U))  USC_AF_Cal.k_calmat1_ctx[4][8] as creal32_T* */          \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_rx_cal_matrix, 294040002U))  USC_AF_Cal.k_calmat1_crx[8][16] as creal32_T* */         \
         /* IF_ANGLEFINDING(DCS_X(Ri_usc_af_cal_matrix, 294040003U))     USC_AF_Cal.k_calmat1_c1[32][64] as creal32_T* */         \
         /* AF Downselection Calibration Interfaces (only fields present in SMC Downselection_Cal_T) */                           \
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
         /*IF_ANGLEFINDING(DCS_X(Ri_k_rcs_az_rolloff_limit_str_0, 399439001U))  WI-399439001: k_rcs_az_rolloff_limit[0] */        \
         /*IF_ANGLEFINDING(DCS_X(Ri_k_rcs_az_rolloff_limit_str_1, 399439002U))  WI-399439002: k_rcs_az_rolloff_limit[1] */        \
         /*IF_ANGLEFINDING(DCS_X(Ri_k_rcs_el_rolloff_limit_str_0, 399439003U))  WI-399439003: k_rcs_el_rolloff_limit[0] */        \
         /*IF_ANGLEFINDING(DCS_X(Ri_k_rcs_el_rolloff_limit_str_1, 399439004U))  WI-399439004: k_rcs_el_rolloff_limit[1] */        \
         /* Radar Capability interfaces */                                                                                        \
         IF_RADAR_CAPABILITY(DCS_X(Ri_avg_mmic_onchip_temp, 370545U)) /* WI-370545: avg_mmic_onchip_temp */                       \
         IF_RADAR_CAPABILITY(DCS_X(Ri_host_speed, 370537U))           /* WI-370537 : host_speed */                                \
         IF_RADAR_CAPABILITY(DCS_X(Ri_host_yawrate, 370539U))         /* WI-370539 : host_yawrate */                              \
         IF_RADAR_CAPABILITY(DCS_X(Ri_look_data_0, 370549001U))       /* WI-370549001 : look_data_0 */                            \
         IF_RADAR_CAPABILITY(DCS_X(Ri_look_data_1, 370549002U))       /* WI-370549002 : look_data_1 */

   /* Test interface enumeration using DCS_X-macro expansion */
   typedef enum Test_Interface_Name_Tag
   {
      Test_Interface_None = 0U, /* Default/invalid interface */
      #define DCS_X(name, value) name = value,
      INTERFACE_ENUM_LIST
      #undef DCS_X
   } Test_Interface_Name_T;

   /*===========================================================================*
    * Local Type Declarations
    *===========================================================================*/
   /**
    * @brief Data type enumeration for generic stubbing and validation
    */
   typedef enum DataType_Tag
   {
      DATATYPE_UINT8 = 0U, /* Unsigned 8-bit integer */
      DATATYPE_UINT16,     /* Unsigned 16-bit integer */
      DATATYPE_UINT32,     /* Unsigned 32-bit integer */
      DATATYPE_INT16,      /* Signed 16-bit integer */
      DATATYPE_INT32,      /* Signed 32-bit integer */
      DATATYPE_FLOAT32,    /* 32-bit floating point */
      DATATYPE_ENUM        /* Enumeration type */
   } DataType_T;

   /* Data pointer union for type-safe pointer casting */
   typedef union Data_Ptr_Tag
   {
      void *ptr;     /* Generic pointer */
      uint8_t *u8;   /* Pointer to uint8_t data */
      uint16_t *u16; /* Pointer to uint16_t data */
      uint32_t *u32; /* Pointer to uint32_t data */
      int16_t *i16;  /* Pointer to int16_t data */
      int32_t *i32;  /* Pointer to int32_t data */
      float *f32;    /* Pointer to float data */
   } Data_Ptr_T;

   /* Common global pointer structure for debugger visibility */
   typedef struct G_Pointer_Tag
   {
      Data_Ptr_T data;            /* Data pointer union */
      size_t elem_size;           /* Size of each element */
      size_t no_of_elements;      /* Number of elements */
      Test_Interface_Name_T name; /* Enum identifying variable for debugger */
      DataType_T data_type;
   } G_Pointer_T;

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

   /******************************************************************************
    * Name:  SIT_IPC_Transfer_M2D_Send
    *   Send test inputs from R52 to BBE32 via M2D IPC buffer.
    *
    * Shared Variables: Test_Iface_Num, Stub_Val, Stub_Len, Master_Res
    *
    * Parameters: m2d_payload_ptr - Pointer to M2D payload structure
    *
    * Return Value: none
    *
    * Design Information:
    *  - Called from dsp_setup.c before M2D header update
    *
    *  Change References:
    *  - Initial implementation
    *
    ******************************************************************************/
   void SIT_IPC_Transfer_M2D_Send(M2D_Payload_T *m2d_payload_ptr);

   /******************************************************************************
    * Name:  SIT_IPC_Transfer_D2M_Receive
    *   Receive BBE32 result from D2M IPC buffer.
    *
    * Shared Variables: DSP_Final_Res
    *
    * Parameters: d2m_payload_ptr - Pointer to D2M payload structure
    *
    * Return Value: none
    *
    * Design Information:
    *  - Called from dsp_setup.c when DSP_RANGE_PROCESSING_COMPLETE received
    *
    *  Change References:
    *  - Initial implementation
    *
    ******************************************************************************/
   void SIT_IPC_Transfer_D2M_Receive(const D2M_Payload_T *d2m_payload_ptr);

      #if defined(Anglefinding_IT)
   /******************************************************************************
    * Name:  SIT_M2D_Onetime_Provider
    *   Provider stub function - injects test values into M2D onetime message.
    *
    * Shared Variables: Master_Stub_Len, Master_Stub_Val, Master_Test_Iface_Num
    *
    * Parameters: msg_ptr - Pointer to M2D_One_Time_Msg_T buffer
    *
    * Return Value: none
    *
    * Design Information:
    *  - Called at end of DSP_Processing_Onetime_Init() in dsp_setup.c
    *
    *  Change References:
    *  - Initial implementation
    *
    ******************************************************************************/
   void SIT_M2D_Onetime_Provider(M2D_One_Time_Msg_T *msg_ptr);

   /******************************************************************************
    * Name:  SIT_M2D_Perlook_Provider
    *   Provider for M2D per-look message.
    *
    * Shared Variables: Master_Stub_Len, Master_Stub_Val, Master_Test_Iface_Num
    *
    * Parameters: m2d_payload_ptr - Pointer to M2D payload buffer
    *
    * Return Value: none
    *
    * Design Information:
    *  - Called at each look during runtime processing
    *
    *  Change References:
    *  - Initial implementation
    *
    ******************************************************************************/
   void SIT_M2D_Perlook_Provider(M2D_Payload_T *m2d_payload_ptr);
      #endif /* Anglefinding_IT */
   /******************************************************************************
    * Name:  SIT_Calibration_Data_Provider
    *   Provider for SMC/calibration data stub injection.
    *   Stubs SMC AF calibration (FLR8/SRR8P), downselection params,
    *   RCS rolloff limits, sensor mounting, and unambiguous velocity
    *   into calibration structures during Validate_Load_All_Calib_Data().
    *
    * Shared Variables: Master_Stub_Len, Master_Stub_Val, Master_Test_Iface_Num
    *
    * Parameters: none (operates on global calibration data pointers)
    *
    * Return Value: none
    *
    * Design Information:
    *  - Called from Validate_Load_All_Calib_Data() in CalibHandler via
    *    SIT_Calibration_Data() macro hook
    *
    *  Change References:
    *  - Initial implementation
    *
    ******************************************************************************/
   void SIT_Calibration_Data_Provider(void);

      #if defined(Radar_capability_IT)
   /******************************************************************************
    * Name:  SIT_MMIC_ONCHIP_DATA_Provider
    *   Provider for MMIC on-chip data stub injection.
    *  Stubs avg_mmic_onchip_temp into M2D message during DSP processing.
    *  Used for validating MMIC on-chip data flow through IPC and processing chain.
    *  - Called from DSP_Processing_Onetime_Init() in dsp_setup.c
    * - Initial implementation
    *
    ******************************************************************************/
   void SIT_MMIC_ONCHIP_DATA_Provider(M2D_Msg_T *m2d_msg_ptr);

      #endif /* Radar_capability_IT */
      /*===========================================================================*
       * Exported Inline Function Definitions and #define Function-Like Macros
       *===========================================================================*/

   /** @} doxygen end group */
   #endif /* Integration_Testing */

   #ifdef __cplusplus
} /* extern "C" */
   #endif /* __cplusplus */

#endif /* MASTER_INTEGRATION_TEST_H */

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
