/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  udp_sil_wrapper.cpp
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_Logging>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "udp_sil_wrapper.h"
#include "app_chksum.h"
#include "sh_interface.h"
//#include "DRA_internals_stream.h" // need to include before stream_handler_if.h
#include "Dynamic_alignment_stream.h"
#include "debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "emblib_ipc_data.h"
#include "header_stream.h"
#include "ipc_data.h"
#include "profile_timing.h"
#include "radar_sw_config.h"
#include "rdd_stream.h"
#include "reuse.h"
#include "sh_comm.h"
#include "sh_error.h"
#include "sh_module_cfg.h"
#include "sh_types.h"
#include "sil_version.h"
#include "sil_wrapper_common.h"
#include "static_alignment_stream.h"
#include "status_stream.h"
#include "usc_cal.h"
#include "vse_stream.h"
#if (defined(CDC_ENABLE))
   #include "cdc_frame_interface.h"
   #include "cdc_stream.h"
#endif

#include "id_stream.h"

uint8_t Stream_Handler_En_XCP = CODED_TRUE; /*Variable to enable/diable periodic message TX*/
static Stream_Error_T RDD_Stream_Err;
static Stream_Error_T RDD_Debug_Stream_Err;
#ifdef TRACKER_ENABLED
static uint32_t Tracker_Ref_Index = 0U;
#endif
static bool K_Disable_CDC_Logging = false; /*This flag will be enabled in future */
static bool XCP_Connection_Status = false;

GLOB_TS_STRUCT_TYPE cur_timestamp_start;
GLOB_TS_STRUCT_TYPE cur_timestamp_end;
GLOB_TS_STRUCT_TYPE cur_mid_dwell;

#if (defined(CDC_ENABLE))
volatile static uint16_t C0_CDC_Current_Index                = 0U;
volatile static uint16_t C0_CDC_Previous_Index               = 0U;
volatile static uint32_t C0_CDC_Transmit_Success_Cnt         = 0U;
volatile static uint32_t C0_CDC_Transmit_Fail_Cnt            = 0U;
volatile static uint16_t C0_CDC_Transmitted_In_Cycle_Cnt     = 0U;
volatile static uint16_t C0_CDC_Transmitted_In_Cycle_Cnt_Max = 0U;
volatile static uint16_t C0_CDC_Current_Index_Cnt            = 0U;
volatile static uint32_t C0_CDC_Current_Index_Error_Cnt      = 0U;
volatile static uint16_t C0_CDC_Enet_Buffer_Max_Depth        = 0U;
volatile bool C0_CDC_Radar_Frame_Reset                       = false;
volatile bool C0_CDC_Previous_Radar_Frame_Reset              = false;
static uint8_t CDC_LastChunk_Buffer[ETH_DATA_PAYLOAD]        = {0U};
/*#define CDC_FRAME_SYNC_VERIFY*/ /*while enable this macro please enable DSP_CDC_VERIFY macro in CDC_packing.c file( both macro
                                    required)*/
   #ifdef CDC_FRAME_SYNC_VERIFY
volatile static uint16_t C0_CDC_Frame_Sync_Count     = 0U;
volatile static uint16_t C0_CDC_Frame_Sync_Error_Cnt = 0U;
   #endif
#endif

#define LOG_SIGNAL_INVALID_VALUE (0xA5A5U) /* Invalid value for 16 bit signals */
/* Protocol dependent configs*/
#ifndef MULTICAST_LOG_TX_ENABLE
   #define REGULAR_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_LOGGING_TX;
   #define DYNAMIC_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_ETH_XCP_TX;
   #define FAST_STREAM_PDU_ID    SoAdConf_SoAdPduRoute_RDR_LOGGING_TX_FAST;
#else
   #define REGULAR_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_LOGGING_TX;
   #define DYNAMIC_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_ETH_XCP_TX;
   #define FAST_STREAM_PDU_ID    SoAdConf_SoAdPduRoute_RDR_LOGGING_TX_FAST;
#endif

#ifndef US_2_MS
   #define US_2_MS (0.001F)
#endif

/* Test variables for Ethernet Stack verification */
volatile static uint32_t Frame_Tx_Success_Cnt = 0U;
volatile static uint32_t Frame_Tx_Failure_Cnt = 0U;

#if defined(SH_ENABLE_CALIB_STREAM)
static void Config_Calib_Stream(void);
#endif
#ifdef TRACKER_ENABLED
static bool Is_Tracker_Stream_Applicable(void);
static void Config_Tracker_Streams(void);
#endif

void Config_All_Stream(void);
#if (defined(CDC_ENABLE))
static void Config_CDC_Stream(void);
#endif

#ifdef ADC_STREAMING_ENABLE
FUNC(void, SWC_PLT_CDD_UDP_Logging_CODE) RE_ADC_Streaming(void);
#endif
static void Populate_Status_Stream(void);
static void Populate_Header_Stream(void);
static void Populate_Debug_Stream(void);
static void Populate_Vse_Stream(void);
#ifdef TRACKER_ENABLED
static void Populate_Partner_Sensor_Stream(void);
#endif

#ifdef FEATURE_ENABLE
static void Populate_Bsis_Stream(void);
static void Populate_Mois_Stream(void);
static void Populate_Olp_Stream(void);
#endif

#if defined(TRACKER_ENABLED)
static void Set_Tracker_Stream_Ref_Index(uint32_t val);
#endif
static void Unused_Signal_Status_Stream();

uint8_t SoAd_Frame_Transmit(Tx_Frame_Param_T *tx_frame_param_ptr);

#ifdef ADC_STREAMING_DEBUG
   #define NUM_ENET_ADC_TX_BUFFERS (250U)
#else
   #define NUM_ENET_ADC_TX_BUFFERS (1100U)
#endif
#define ADC_CIRC_BUF_ROLLOVER(idx) (((idx) + (NUM_ENET_ADC_TX_BUFFERS)) % (NUM_ENET_ADC_TX_BUFFERS))

volatile uint16_t MAX_TX_PER_CYCLE = 250u;
#define MAX_TEST_TRIGGER_BUF (8U)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dt_AlignAuto_Error: Integer in interval [0...255]
 * Dt_AlignHandler_Error: Integer in interval [0...255]
 * Dt_Align_Mode_T: Integer in interval [0...255]
 * Dt_Align_Status: Integer in interval [0...255]
 * Dt_Align_Veh_Cond: Integer in interval [0...255]
 * Dt_DRA_Detection_Coordinate_System: Integer in interval [0...255]
 * Dt_SystemOperationMode: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Dt_Fault_T: Array with 16 element(s) of type uint8
 * Rte_DT_Dt_Alignment_Config_Data_6: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Alignment_Config_Data_9: Array with 4 element(s) of type float32
 * Rte_DT_Dt_FailSafe_ResetReason_T_0: Array with 5 element(s) of type uint8
 * Rte_DT_Dt_FailSafe_ResetReason_T_7: Array with 5 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_8: Array with 10 element(s) of type uint16
 *
 * Record Types:
 * =============
 * Dt_AlignmentAuto: Record with elements
 *   StartAzimuth of type float32
 *   StartElevation of type float32
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AAAzimuthStd of type float32
 *   AAElevationStd of type float32
 *   AARollStd of type float32
 *   Az_Err_positive of type float32
 *   Az_Err_negative of type float32
 *   El_Err_positive of type float32
 *   El_Err_negative of type float32
 *   RollError_positive of type float32
 *   RollError_negative of type float32
 *   HostScf of type float32
 *   AzimuthNumUpdates of type uint32
 *   ElevationNumUpdates of type uint32
 *   AutoAlignmentFailRootCause of type Dt_AlignAuto_Error
 *   AlignAutoStatus of type Dt_Align_Status
 *   HostScf_QF of type uint8
 *   StartRoll of type float32
 *   AACurrentRoll of type float32
 *   RollUpdates of type uint32
 * Dt_AlignmentService: Record with elements
 *   DistanceAbsolute of type float32
 *   DistanceEffective of type float32
 *   AvgNumOfDet of type uint32
 *   DurationAbsolute of type float32
 *   DurationEffective of type float32
 *   AverageSpeed of type float32
 *   AlignmentServiceSt of type Dt_Align_Status
 *   VehicleCondition of type Dt_Align_Veh_Cond
 * Dt_AlignmentShortTrack: Record with elements
 *   AlignShortTrackSt of type Dt_Align_Status
 * Dt_AlignmentStatic: Record with elements
 *   MeasuredAzimuth of type float32
 *   MeasuredElevation of type float32
 *   Measured_Az_Std of type float32
 *   Measured_El_Std of type float32
 *   MeasuredRange of type float32
 *   MeasuredRangeStd of type float32
 *   MeasuredRangeRate of type float32
 *   MeasuredRangeRateStd of type float32
 *   MeasuredRCS of type float32
 *   MeasuredRCSStd of type float32
 *   AlignmentStaticStatus of type Dt_Align_Status
 *   StatusOfPlate of type uint8
 *   StatusOfAzimuth of type uint8
 *   StatusOfElevation of type uint8
 *   ImpactByInterference of type boolean
 * Dt_Alignment_Config_Data: Record with elements
 *   initial_vacs_boresight_az_estimated of type float32
 *   initial_vacs_boresight_el_estimated of type float32
 *   initial_speed_compensation_factor of type float32
 *   max_abs_misalignment_az of type float32
 *   short_track_target_height of type float32
 *   short_track_target_range_rate of type float32
 *   az_scf_kf_covariance of type Rte_DT_Dt_Alignment_Config_Data_6
 *   initial_vacs_boresight_rl_estimated of type float32
 *   initial_num_updates_rl of type uint32
 *   el_roll_kf_covariance of type Rte_DT_Dt_Alignment_Config_Data_9
 *   iso_sensor_x_posn of type float32
 *   iso_sensor_y_posn of type float32
 *   iso_sensor_z_posn of type float32
 *   iso_sensor_yaw of type float32
 *   iso_sensor_pitch of type float32
 *   iso_sensor_roll of type float32
 *   distance_rear_axle_to_front_bumper of type float32
 *   max_abs_misalignment_el_sky of type float32
 *   max_abs_misalignment_el_ground of type float32
 *   aacurrent_azimuth of type float32
 *   aacurrent_elevation of type float32
 *   initial_num_updates_az of type uint32
 *   initial_num_updates_el of type float32
 *   mount_loc of type uint8
 *   short_track_exit_condition of type uint8
 *   f_data_valid of type uint8
 *   initial_align_quality_factor_el of type uint8
 *   initial_align_quality_factor_az of type uint8
 *   align_cmd of type uint8
 *   auto_align_status of type uint8
 *   Align_RadarOperation_Mode of type uint8
 *   coordinate_system_input of type uint8
 * Dt_Alignment_Handler: Record with elements
 *   InitialAlignmentResultAz of type float32
 *   InitialAlignmentResultEl of type float32
 *   InitialAlignmentResultHostSCF of type float32
 *   InitialAlignmentResultAzUpdates of type uint32
 *   InitialAlignmentResultElUpdates of type uint32
 *   AlignmentAzimuth of type float32
 *   AlignmentElevation of type float32
 *   AzimuthStd of type float32
 *   ElevationStd of type float32
 *   calTime of type float32
 *   CalDisplay of type uint8
 *   ProgressPercent of type uint8
 *   AlignmentError of type Dt_AlignHandler_Error
 *   ElevationQuality of type uint8
 *   AzimuthQuality of type uint8
 *   Alignment_modeIn of type Dt_Align_Mode_T
 *   AlignmentModeOut of type Dt_Align_Mode_T
 *   InitialLastSuccessAlignmentMode of type Dt_Align_Mode_T
 *   Radar_Type_Input of type uint8
 *   CoordinateSystem_Input of type Dt_DRA_Detection_Coordinate_System
 *   InitialAlignmentResultRoll of type float32
 *   InitialAlignmentResultRollUpdates of type uint32
 *   AlignmentRoll of type float32
 * Dt_Alignment_M2D_Data: Record with elements
 *   static_alignment_data of type Dt_Static_Alignment_Data
 *   dynamic_alignment_data of type Dt_Alignment_Config_Data
 * Dt_CPU_Load: Record with elements
 *   CPU_Load of type uint32
 *   CPU_Load_Max of type uint32
 *   CPU_Load_Min of type uint32
 *   CPU_Load_Avg of type uint32
 * Dt_FailSafe_ResetReason_T: Record with elements
 *   reset_reason of type Rte_DT_Dt_FailSafe_ResetReason_T_0
 *   reset_counter of type uint8
 *   last_cycle_reset of type uint8
 *   reset_reason_crnt_indx of type uint8
 *   repetitive_reset_counter of type uint8
 *   RFE_Repetitive_Reset_Counter of type uint8
 *   mem_exception_reason of type Dt_Memory_Exception_Info_T
 *   wdg_failed_SE_info of type Rte_DT_Dt_FailSafe_ResetReason_T_7
 *   FCCU_Faults of type Rte_DT_Dt_FailSafe_ResetReason_T_8
 *   xrdc_violation_info of type Dt_XRDC_Violation_Info_T
 *   R1_NCF_Counter of type uint32
 * Dt_Memory_Exception_Info_T: Record with elements
 *   ExceptionType of type uint32
 *   ExceptionCausingAddress of type uint32
 *   ExceptionStatusRegister of type uint32
 *   IsMemException_Occured of type boolean
 *   MemoryExceptionAddress of type uint32
 *   StackPointer of type uint32
 * Dt_RTM_parameters_T: Record with elements
 *   Runtime_average of type uint32
 *   Runtime_overall of type uint32
 *   Runtime_MAX of type uint32
 *   Runtime_MIN of type uint32
 * Dt_Static_Alignment_Data: Record with elements
 *   yaw of type float32
 *   pitch of type float32
 *   plate_angle_deg_scs of type float32
 *   plate_distance of type float32
 *   polarity of type float32
 *   horz_angle_min of type float32
 *   horz_angle_max of type float32
 *   vert_angle_min of type float32
 *   vert_angle_max of type float32
 *   plate_lat_position of type float32
 *   mount_loc of type uint8
 *   align_cmd of type uint8
 *   f_data_valid of type uint8
 * Dt_XRDC_Violation_Info_T: Record with elements
 *   IsXRDCViolation_Occured of type boolean
 *   XRDC_Instance of type uint8
 *   MRC_Instance of type uint8
 *   PAC_Instance of type uint8
 *   XRDCViolationAddress of type uint32
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_Logging_START_SEC_CODE

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Detection_Populate_Detection_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Detection_Stream> of PortPrototype
 *<PostRadarProcessing_Detection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Detection_Populate_Detection_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Detection_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Detection_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Detection_E_OK
 *   RTE_E_PostRadarProcessing_Detection_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Detection_Populate_Detection_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Detection_Populate_Detection_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Detection_Populate_Detection_Stream (returns application error)
    *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint8_t det_trigger_state;
   uint8_t det_debug_trigger_state;
   uint8_t ds_trigger_state;

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
      if (NULL != p_ipc_d2m_msg)
      {
         Detection_Stream_T *stream_ptr = (Detection_Stream_T *)&(p_ipc_d2m_msg->payload.det_data);

         Detection_Debug_Stream_T *det_debug_stream_ptr = (Detection_Debug_Stream_T *)&(p_ipc_d2m_msg->payload.det_debug_data);

#if (DOWNSELECTION_ENABLE == 1U)
         Down_selection_Stream_T *ds_stream_ptr = &(p_ipc_d2m_msg->payload.downselection_data);
#endif
         /* Send Detection stream */
         det_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(DETECTION, (uint8_t *)stream_ptr);

         // det_debug_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(DETECTION_DEBUG, (uint8_t
         // *)det_debug_stream_ptr);

#if (DOWNSELECTION_ENABLE == 1U)
         /* Send DS stream */
         ds_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(DOWN_SELECTION, (uint8_t *)ds_stream_ptr);
#endif
#ifdef TRACKER_ENABLED
         Populate_Partner_Sensor_Stream();
#endif
      }
   }

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_RDD_Populate_RDD_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Header_Stream> of PortPrototype <PostRadarProcessing_Header>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_RDD_Populate_RDD_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Header_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Header_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Header_E_OK
 *   RTE_E_PostRadarProcessing_Header_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_RDD_Populate_RDD_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_RDD_Populate_RDD_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_RDD_Populate_RDD_Stream (returns application error)
    *********************************************************************************************************************/

   uint8_t rdd_trigger_state       = 0U;
   uint8_t rdd_debug_trigger_state = 0U;
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      /* RDD stream shall be directly triggered by DSS later */
      D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer(); // get_ipc_d2m_buffer();

      if (NULL != p_ipc_d2m_msg)
      {
         Rdd_Stream_T *stream_ptr = (Rdd_Stream_T *)&(p_ipc_d2m_msg->payload.rdd_stream_data);
         // Rdd_Debug_Stream_T *rdd_debug_stream_ptr = (Rdd_Debug_Stream_T *)&(p_ipc_d2m_msg->payload.rdd_debug_data);
         RDD_Stream_Err = Get_Stream_Error(RDD, 0U);
         // RDD_Debug_Stream_Err                     = Get_Stream_Error(RDD_DEBUG, 0U);

         /* Trigger RDD Stream handler */
         rdd_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(RDD, (uint8_t *)stream_ptr);
         /*Trigger RDD Debug stream handler */
         // rdd_debug_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(RDD_DEBUG, (uint8_t
         // *)rdd_debug_stream_ptr);
      }
   }

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Debug_Populate_Debug_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_MMIC_Stream> of PortPrototype <PostRadarProcessing_MMIC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Debug_Populate_Debug_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_MMIC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Debug_Populate_Debug_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Debug_Populate_Debug_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Debug_Populate_Debug_Stream (returns application error)
    *********************************************************************************************************************/

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      Populate_Debug_Stream();
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_RDD_Stream> of PortPrototype <PostRadarProcessing_RDD>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_RDD_E_NOT_OK
 *   RTE_E_PostRadarProcessing_RDD_E_NOT_OK
 *   RTE_E_PostRadarProcessing_RDD_E_OK
 *   RTE_E_PostRadarProcessing_RDD_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream (returns application error)
    *********************************************************************************************************************/

   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();

      if (NULL != p_ipc_d2m_msg)
      {
         Static_Alignment_Log_Stream_T *sa_stream_ptr =
            (Static_Alignment_Log_Stream_T *)&p_ipc_d2m_msg->payload.alignment_stream_data;
         Dynamic_Alignment_Log_Stream_T *dra_stream_ptr =
            (Dynamic_Alignment_Log_Stream_T *)&p_ipc_d2m_msg->payload.dynamic_alignment_log_stream;
         Radar_Capability_Stream_T *rc_stream_ptr = (Radar_Capability_Stream_T *)&p_ipc_d2m_msg->payload.radar_capability_data;
         ID_Stream_T *id_stream_ptr               = (ID_Stream_T *)&(p_ipc_d2m_msg->payload.interference_detection_data);
#if (DOWNSELECTION_ENABLE == 1U)
         TOI_DS_Stream_T *toi_ds_stream_ptr = (TOI_DS_Stream_T *)(&p_ipc_d2m_msg->payload.toi_ds_stream_data);
#else
         TOI_Stream_T *toi_stream_ptr = (TOI_Stream_T *)(&p_ipc_d2m_msg->payload.toi_stream_data);
#endif

         /* Trigger Alignment Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SRA, (uint8_t *)sa_stream_ptr);

         /* Trigger Dynamic Alignment Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(DRA, (uint8_t *)dra_stream_ptr);

         /* Trigger Radar Capability Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(RADAR_CAPABILITY, (uint8_t *)rc_stream_ptr);

         /* Trigger Interference Detection Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(ID, (uint8_t *)id_stream_ptr);

         /* Trigger TOI Stream handler */
#if (DOWNSELECTION_ENABLE == 1U)
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TOI_DS, (uint8_t *)toi_ds_stream_ptr);
#else
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TOI, (uint8_t *)toi_stream_ptr);
#endif

         /* populate VSE stream */
         Populate_Vse_Stream();

#ifndef TRACKER_DISABLED
         if (Is_Tracker_Stream_Applicable())
         {
            Set_Tracker_Stream_Ref_Index(p_ipc_d2m_msg->payload.emb_tracker_status.scan_index);

            Sync_Info_Stream_T *sync_info_stream_ptr = &p_ipc_d2m_msg->payload.sync_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SYNC_INFO, (uint8_t *)sync_info_stream_ptr);
            Vehicle_Info_Stream_T *vehicle_info_stream_ptr = &p_ipc_d2m_msg->payload.vehicle_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(VEHICLE_INFO, (uint8_t *)vehicle_info_stream_ptr);
            Tracker_Info_Stream_T *tracker_info_stream_ptr = &p_ipc_d2m_msg->payload.tracker_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TRACKER_INFO, (uint8_t *)tracker_info_stream_ptr);
            Timing_Info_Stream_T *timing_info_stream_ptr = &p_ipc_d2m_msg->payload.timing_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TIMING_INFO, (uint8_t *)timing_info_stream_ptr);
            Host_Calibs_Stream_T *host_calibs_stream_ptr = &p_ipc_d2m_msg->payload.host_calibs_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(HOST_CALIBS, (uint8_t *)host_calibs_stream_ptr);
            Host_Props_Stream_T *host_props_stream_ptr = &p_ipc_d2m_msg->payload.host_props_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(HOST_PROPS, (uint8_t *)host_props_stream_ptr);
            Static_Env_Poly_Stream_T *static_env_poly_stream_ptr = &p_ipc_d2m_msg->payload.static_env_poly_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(STATIC_ENV_POLY, (uint8_t *)static_env_poly_stream_ptr);
            Functional_Safety_Faults_Stream_T *functional_safety_faults_stream_ptr =
               &p_ipc_d2m_msg->payload.functional_safety_faults_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(FUNCTIONAL_SAFETY_FAULTS,
                                                                     (uint8_t *)functional_safety_faults_stream_ptr);
            Object_List_Stream_T *object_list_stream_ptr = &p_ipc_d2m_msg->payload.object_list_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(OBJECT_LIST, (uint8_t *)object_list_stream_ptr);
            Processed_Detection_Stream_T *processed_detection_stream_ptr = &p_ipc_d2m_msg->payload.processed_detection_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(PROCESSED_DETECTION,
                                                                     (uint8_t *)processed_detection_stream_ptr);
            Sensor_Calib_Stream_T *sensor_calib_stream_ptr = &p_ipc_d2m_msg->payload.sensor_calib_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SENSOR_CALIB, (uint8_t *)sensor_calib_stream_ptr);
            Trailer_Detector_Stream_T *trailer_detector_stream_ptr = &p_ipc_d2m_msg->payload.trailer_detector_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TRAILER_DETECTOR, (uint8_t *)trailer_detector_stream_ptr);
            Cv_Trailer_Stream_T *cv_trailer_stream_ptr = &p_ipc_d2m_msg->payload.cv_trailer_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(CV_TRAILER, (uint8_t *)cv_trailer_stream_ptr);
         }

   #ifdef FEATURE_ENABLE
         /* populate BSIS stream */
         Populate_Bsis_Stream();
         /* populate MOIS stream */
         Populate_Mois_Stream();
         Populate_Olp_Stream();
   #endif
#endif
      }
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_MMIC_Populate_MMIC_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Radar_Capability_Stream> of PortPrototype
 *<PostRadarProcessing_Radar_Capability>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_MMIC_Populate_MMIC_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_MMIC_Populate_MMIC_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_MMIC_Populate_MMIC_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_MMIC_Populate_MMIC_Stream (returns application error)
    *********************************************************************************************************************/

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Status_Populate_Status_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Status_Stream> of PortPrototype <PostRadarProcessing_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Status_Populate_Status_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Status_Populate_Status_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Status_Populate_Status_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Status_Populate_Status_Stream (returns application error)
    *********************************************************************************************************************/
   if (CODED_TRUE == Stream_Handler_En_XCP) /* Enable/Disable stream logging upon XCP request */
   {
      Populate_Status_Stream();
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Header_Populate_Header_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Status_Stream> of PortPrototype <PostRadarProcessing_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Header_Populate_Header_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Header_Populate_Header_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Header_Populate_Header_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Header_Populate_Header_Stream (returns application error)
    *********************************************************************************************************************/

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      Populate_Header_Stream();
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

void Config_All_Stream(void)
{
   uint8_t config_det_result;
   uint8_t config_det_debug_result;
   uint8_t config_hdr_result;
   uint8_t config_status_result;
   uint8_t config_rdd_result;
   uint8_t config_rdd_debug_result;
   uint8_t config_mmic_result;
   uint8_t config_debug_result;
   uint8_t config_align_result;
   uint8_t config_dra_result;
   uint8_t config_radar_cap_result;
   uint8_t config_vse_result;
   uint8_t config_id_result;
#if (DOWNSELECTION_ENABLE == 1U)
   uint8_t config_toi_ds_result;
#else
   uint8_t config_toi_result
#endif

#ifndef TRACKER_DISABLED
   uint8_t config_partner_sensor_result;
   uint8_t config_vehicle_result;
   uint8_t config_process_result;
   uint8_t config_sync_info_result;
   uint8_t config_tracker_result;
   uint8_t config_obj_list_result;
   uint8_t config_timing_info_result;
   uint8_t config_host_calibs_result;
   uint8_t config_host_props_result;
   uint8_t config_static_env_poly_result;
   uint8_t config_fusa_result;
   uint8_t config_trailer_detect_result;
   uint8_t config_cv_trailer_result;
   #ifdef FEATURE_ENABLE
   uint8_t config_bsis_result;
   uint8_t config_mois_result;
   uint8_t config_olp_result;
   #endif
#endif

   uint8_t config_sensor_calib_result;
   uint8_t config_down_sel_result;

   Stream_Init_Cfg_T all_init_cfg = {(uint8_t)ALL_CHUNKS, STREAM_REGULAR_FAST, (uint8_t) true, 0U};

   config_det_result       = Stream_Config_Init(DETECTION, &all_init_cfg);
   config_det_debug_result = Stream_Config_Init(DETECTION_DEBUG, &all_init_cfg);
   config_hdr_result       = Stream_Config_Init(HEADER, &all_init_cfg);
   config_status_result    = Stream_Config_Init(STATUS, &all_init_cfg);
   config_rdd_result       = Stream_Config_Init(RDD, &all_init_cfg);
   config_rdd_debug_result = Stream_Config_Init(RDD_DEBUG, &all_init_cfg);
   config_vse_result       = Stream_Config_Init(VSE, &all_init_cfg);
   config_debug_result     = Stream_Config_Init(DEBUG, &all_init_cfg);
   config_mmic_result      = Stream_Config_Init(MMIC, &all_init_cfg);
   config_align_result     = Stream_Config_Init(SRA, &all_init_cfg);
   config_radar_cap_result = Stream_Config_Init(RADAR_CAPABILITY, &all_init_cfg);
   config_down_sel_result  = Stream_Config_Init(DOWN_SELECTION, &all_init_cfg);
   config_id_result        = Stream_Config_Init(ID, &all_init_cfg);
#if (DOWNSELECTION_ENABLE == 1U)
   config_toi_ds_result = Stream_Config_Init(TOI_DS, &all_init_cfg);
#else
   config_toi_result = Stream_Config_Init(TOI, &all_init_cfg);
#endif
   config_dra_result = Stream_Config_Init(DRA, &all_init_cfg);
#ifndef TRACKER_DISABLED
   config_partner_sensor_result  = Stream_Config_Init(PARTNER_SENSOR, &all_init_cfg);
   config_vehicle_result         = Stream_Config_Init(VEHICLE_INFO, &all_init_cfg);
   config_process_result         = Stream_Config_Init(PROCESSED_DETECTION, &all_init_cfg);
   config_sync_info_result       = Stream_Config_Init(SYNC_INFO, &all_init_cfg);
   config_tracker_result         = Stream_Config_Init(TRACKER_INFO, &all_init_cfg);
   config_timing_info_result     = Stream_Config_Init(TIMING_INFO, &all_init_cfg);
   config_obj_list_result        = Stream_Config_Init(OBJECT_LIST, &all_init_cfg);
   config_sensor_calib_result    = Stream_Config_Init(SENSOR_CALIB, &all_init_cfg);
   config_host_calibs_result     = Stream_Config_Init(HOST_CALIBS, &all_init_cfg);
   config_host_props_result      = Stream_Config_Init(HOST_PROPS, &all_init_cfg);
   config_static_env_poly_result = Stream_Config_Init(STATIC_ENV_POLY, &all_init_cfg);
   config_fusa_result            = Stream_Config_Init(FUNCTIONAL_SAFETY_FAULTS, &all_init_cfg);
   config_trailer_detect_result  = Stream_Config_Init(TRAILER_DETECTOR, &all_init_cfg);
   config_cv_trailer_result      = Stream_Config_Init(CV_TRAILER, &all_init_cfg);
   #ifdef FEATURE_ENABLE
   config_bsis_result = Stream_Config_Init(BSIS, &all_init_cfg);
   config_mois_result = Stream_Config_Init(MOIS, &all_init_cfg);
   config_olp_result  = Stream_Config_Init(OLP, &all_init_cfg);
   #endif
#endif
   /*Use of config_result depends on application requirement*/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_ActiveFaultTable_De_ActiveFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_AlignmentAuto_De_AlignmentAuto(Dt_AlignmentAuto *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentService_De_AlignmentService(Dt_AlignmentService *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentShortTrack_De_AlignmentShortTrack(Dt_AlignmentShortTrack *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentStatic_De_AlignmentStatic(Dt_AlignmentStatic *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_Handler_De_Alignment_Handler(Dt_Alignment_Handler *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(Dt_Alignment_M2D_Data *data)
 *   Std_ReturnType Rte_Read_Rp_CPU_Load_De_CPU_Load(Dt_CPU_Load *data)
 *   Std_ReturnType Rte_Read_Rp_Command_Radiate_Final_RadarRadiateInterface_De_CommandRadiate_Final(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_EcuSync_Offset_ms_De_EcuSync_Offset_ms(float32 *data)
 *   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data)
 *   Std_ReturnType Rte_Read_Rp_Hil_Activation_De_Hil_Activation(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_OperationModeType_De_OperationMode_System(Dt_SystemOperationMode *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Get_Platform_Elapsed_ustime_read(uint32 *inst_us_time, uint64 start_time)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Rp_Get_PlatformTime_ms_read(uint32 *instant_mstime)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Rp_Get_PlatfromTime_us_read(uint64 *instant_ustime)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Rtm_task_measurement_Operation(Dt_RTM_parameters_T *destination)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_50ms_doc
 *********************************************************************************************************************/

/********Created for LVDS Testing********************/
//#define LVDS_TX_NO_16_BIT_SAMPLES 1024 //2 KB
//#define LVDS_TX_NO_OF_FRAMES 10 //1 50ms Cycle --> 2 KB(1 Buffer) x 1(No of Buffers) x 10(No of Frames) --> 20KB
// uint16_t UserBuffer0[CSL_NEXT_MULTIPLE_OF(LVDS_TX_NO_16_BIT_SAMPLES, CSL_CACHE_L1D_LINESIZE)]
// __attribute__((aligned(CSL_CACHE_L1D_LINESIZE)));
////uint16_t UserBuffer1[CSL_NEXT_MULTIPLE_OF(LVDS_TX_NO_16_BIT_SAMPLES, CSL_CACHE_L1D_LINESIZE)]
///__attribute__((aligned(CSL_CACHE_L1D_LINESIZE))); /uint16_t UserBuffer2[CSL_NEXT_MULTIPLE_OF(LVDS_TX_NO_16_BIT_SAMPLES,
/// CSL_CACHE_L1D_LINESIZE)] __attribute__((aligned(CSL_CACHE_L1D_LINESIZE)));
// uint32_t Index       = 0;
// uint32_t Frame_Count = 0;
// LVDSStream_UserData_T LVDSStream_UserData;
// uint32_t idx = 0;
// uint8_t isTxDone = 0;
/***************LVDS Testing END*********************/
// clang-format on

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_50ms
    *********************************************************************************************************************/

   uint8_t calib_trigger_state;
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();

   /* This flag shall be updated from the BSW's input - a flag indicating the communication is established
   Currently made true to indicate communication is enabled directly*/
   static bool enable_tx = true;

   if (enable_tx)
   {
      Set_Stream_Tx_Enable_Status(enable_tx);
   }
   // PostRadarProcessing_Debug_Populate_Debug_Stream();
   PostRadarProcessing_Detection_Populate_Detection_Stream();
   PostRadarProcessing_Header_Populate_Header_Stream();
   PostRadarProcessing_MMIC_Populate_MMIC_Stream();
   PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream();
   PostRadarProcessing_Status_Populate_Status_Stream();
   PostRadarProcessing_RDD_Populate_RDD_Stream();

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      /* This stream can be triggered independently of radar cycle rate */
      calib_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(CALIB, (uint8_t *)NULL);
   }
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Board_Revision_De_Board_Revision(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_Init
    *********************************************************************************************************************/

   /* Initialize stream handler */
   Stream_Handler_Init_Params_T sh_ip;
   sh_ip.sensor_id    = (uint8_t)Get_Radar_Position();
   sh_ip.source_info  = (uint8_t)STREAM_SOURCE; /*sensor type - radar, lidar, camera etc.*/
   sh_ip.source_info1 = (uint8_t)SENSOR_RADAR;
   // sh_ip.source_info2 = (uint8_t)Get_SMC_Cal_Minor(); /* customer ID info from SMC - BMW, CEER etc.*/

   Update_Stream_Handler_Input(&sh_ip);

   Update_SH_Input_Interface();

   Update_SH_Output_Interface();

   Config_Calib_Stream();
#if (defined(CDC_ENABLE))
   Config_CDC_Stream();
#endif
   Config_All_Stream();
   Stream_Handler_Init();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
 *. Name: Populate_Vse_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Vse_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint8_t vse_trigger_state;
   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
   M2D_Msg_T *p_ipc_m2d_msg = Get_IPC_M2D_Buffer();
   Vse_Stream_T *stream_ptr = &p_ipc_m2d_msg->payload.veh_data;

   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr->stream_hdr.scan_index = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.scan_index;
      /* Calculate checksum */
      Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Vse_Stream_T));

      vse_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(VSE, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Populate_Status_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Status_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint8_t sensor_location         = 0U;
   uint8_t status_trigger_state;
   Status_Stream_T *stream_ptr               = Get_Status_Log_Data_Ptr();
   D2M_Msg_T *p_ipc_d2m_msg                  = Get_IPC_D2M_Buffer();
   M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_One_Time_Buffer();

   if (NULL != p_ipc_d2m_msg)
   {
      Look_Data_T *ipc_look_data_ptr = &(p_ipc_d2m_msg->payload.rdd_stream_data.look_data);
      // const Diag_Data_T *p_ipc_dsp_to_cm7 = &(p_ipc_d2m_msg->payload.diag_data);
      stream_ptr->stream_hdr.scan_index = (uint16_t)ipc_look_data_ptr->scan_index;
      stream_ptr->scanindex             = (uint16_t)ipc_look_data_ptr->scan_index;
      stream_ptr->lookindex             = (uint16_t)ipc_look_data_ptr->scan_index;
      stream_ptr->look_type             = (uint16_t)ipc_look_data_ptr->look_id;
   }
   stream_ptr->app_version_Info.appl_variant = K_PLATFORM_VARIANT; /* Platform variant Eg: SRR7P, FLR7V2 ect*/

   stream_ptr->app_version_Info.major_release_revision = SIL_MAJOR_VERSION;        /* SW major revision */
   stream_ptr->app_version_Info.minor_release_revision = SIL_MINOR_VERSION;        /* SW minor revision */
   stream_ptr->app_version_Info.patch_release_revision = SIL_PATCH_VERSION;        /* SW patch revision */
   stream_ptr->app_version_Info.pre_release_revision   = SIL_PRE_RELEASE_REVISION; /* SW pre-release    */
   stream_ptr->customer_info.customer_id               = Get_SMC_Cal_Minor();      /*Customer ID Eg: CEER/BMW ect*/
   stream_ptr->customer_info.customer_my               = LOG_SIG_NOT_IMPLEMENTED;  /*Customer_Model_Year MY25/MY26/SP25/SP26 ect*/
   stream_ptr->customer_info.customer_variant          = LOG_SIG_NOT_IMPLEMENTED;  /*customer_Variant LOW/MID/HIGH*/
   stream_ptr->stream_hdr.version                      = STATUS_STREAM_VERSION;
   stream_ptr->stream_hdr.size                         = sizeof(Status_Stream_T);

   stream_ptr->usc_version_major    = Get_USC_Cal_Major();
   stream_ptr->usc_version_minor    = Get_USC_Cal_Minor();
   stream_ptr->usc_version_patch    = Get_USC_Cal_Patch();
   stream_ptr->usc_version_platform = Get_USC_Cal_Platform();

   stream_ptr->sts_serial_num_julian_day  = k_Julian_Production_Date_USC;
   stream_ptr->sts_serial_num_julian_year = k_Julian_Year_USC;
   stream_ptr->sts_serial_number_sequence = k_Mfg_Sequence_Number_USC;

   stream_ptr->smc_version_major    = Get_SMC_Cal_Major();
   stream_ptr->smc_version_minor    = Get_SMC_Cal_Minor();
   stream_ptr->smc_version_patch    = Get_SMC_Cal_Patch();
   stream_ptr->smc_version_platform = Get_SMC_Cal_Platform();

   stream_ptr->stream1_version = (uint8_t)DETECTION_STREAM_VERSION;
   stream_ptr->stream2_version = (uint8_t)HEADER_STREAM_VERSION;
   stream_ptr->stream3_version = (uint8_t)STATUS_STREAM_VERSION;
   stream_ptr->stream4_version = (uint8_t)RDD_STREAM_VERSION;
   stream_ptr->stream5_version = (uint8_t)VSE_STREAM_VERSION;

   stream_ptr->stream6_version = (uint8_t)MMIC_STREAM_VERSION;
   /* Sensor Position */
   sensor_location                   = (uint8_t)(Get_Radar_Position() - 1u);
   stream_ptr->sensor_mount_location = Get_Radar_Position();
   if (NULL != m2d_one_time_init_ptr)
   {
      stream_ptr->sensor_mount_ornt_yaw =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw;
      stream_ptr->sensor_mount_ornt_pitch =
         m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch;
      stream_ptr->sensor_mount_ornt_roll =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll;
      stream_ptr->sensor_mount_pos_x =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x;
      stream_ptr->sensor_mount_pos_y =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y;
      stream_ptr->sensor_mount_pos_z =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z;
      stream_ptr->sensor_height =
         (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height;

      /*Calculate the polarity based on roll*/
      stream_ptr->sensor_polarity =
         ((int8_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll < 0.1F ?
             (int8_t)(1) :
             (int8_t)(-1));

      stream_ptr->sensor_long_offset =
         (float32_t)m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
   }

   stream_ptr->platform_variant = Get_SMC_Cal_Platform();

#if 0
      stream_ptr->mmic_temp_rx0 = (int16_t)MMIC_Temperature.temperature_data.tmpRxSens;
      stream_ptr->mmic_temp_rx1 = (int16_t)MMIC_Temperature.temperature_data.tmpXOSens;
      stream_ptr->mmic_temp_rx2 = (int16_t)0;
      stream_ptr->mmic_temp_rx3 = (int16_t)0;

      stream_ptr->mmic_temp_tx0   = (int16_t)MMIC_Temperature.temperature_data.tmpTx12Sens;
      stream_ptr->mmic_temp_tx1   = (int16_t)MMIC_Temperature.temperature_data.tmpTx34Sens;
      stream_ptr->mmic_temp_tx2   = (int16_t)0;
      stream_ptr->mmic_temp_tx3   = (int16_t)0;
      stream_ptr->mode_trig_count = 0xFF; /*mode_trig_count*/
#endif

   /* Calculate checksum */
   Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Status_Stream_T));

   status_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(STATUS, (uint8_t *)stream_ptr);
}

FUNC(void, SWC_PLT_CDD_Logging_CODE) transmit_udp_data(void)
{
   /* Start Timer */
   TIMER_START(TRANSMIT_UDP);

   RE_Logging_50ms();

   /* Stop Timer */
   TIMER_STOP(TRANSMIT_UDP);
}

/******************************************************************************
 *. Name: Populate_Debug_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Debug_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint8_t debug_trigger_state;
   Debug_Stream_T *stream_ptr = Get_Debug_Log_Data_Ptr();

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
   if ((NULL != p_ipc_d2m_msg))
   {
      Look_Data_T *ipc_look_data_ptr = &(p_ipc_d2m_msg->payload.rdd_stream_data.look_data);
      // void *dest_ptr                 = (Cdc_Tdc_Support_T *)&stream_ptr->Cdc_Tdc_Support;
#if COMMENTED_SH /*--commented until CDC module up*/
      Cdc_Tdc_Support_T *p_ipc_d2m_cdc_tdc_spprt_data =
         &(p_ipc_d2m_msg->payload.cdc_tdc_support_data); /*To be filled by DSP core*/

      ((Cdc_Tdc_Support_T *)(dest_ptr))->min_chirp_scaling  = p_ipc_d2m_cdc_tdc_spprt_data->min_chirp_scaling;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_time_stamp      = p_ipc_d2m_cdc_tdc_spprt_data->ML_time_stamp;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->invalid_frame      = p_ipc_d2m_cdc_tdc_spprt_data->invalid_frame;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->Num_of_ML_log_bins = p_ipc_d2m_cdc_tdc_spprt_data->Num_of_ML_log_bins;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_ScanIndex       = p_ipc_d2m_cdc_tdc_spprt_data->ML_ScanIndex;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_look_type       = p_ipc_d2m_cdc_tdc_spprt_data->ML_look_type;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_Gear_position   = p_ipc_d2m_cdc_tdc_spprt_data->ML_Gear_position;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_Comp_Abs_speed  = (float)UINT8_MAX;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_Abs_speed       = p_ipc_d2m_cdc_tdc_spprt_data->ML_Abs_speed;
      ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_Yaw_rate        = p_ipc_d2m_cdc_tdc_spprt_data->ML_Yaw_rate;

      for (uint16_t idx = 0; idx < MAX_RANGE_BINS; idx++)
      {
         ((Cdc_Tdc_Support_T *)(dest_ptr))->bv_scale_per_rbin[idx]   = p_ipc_d2m_cdc_tdc_spprt_data->bv_scale_per_rbin[idx];
         ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_NF_est[idx]           = p_ipc_d2m_cdc_tdc_spprt_data->ML_NF_est[idx];
         ((Cdc_Tdc_Support_T *)(dest_ptr))->cr_resp[idx]             = p_ipc_d2m_cdc_tdc_spprt_data->cr_resp[idx];
         ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_CFAR_thr[idx]         = p_ipc_d2m_cdc_tdc_spprt_data->ML_CFAR_thr[idx];
         ((Cdc_Tdc_Support_T *)(dest_ptr))->ML_Stationary_index[idx] = p_ipc_d2m_cdc_tdc_spprt_data->ML_Stationary_index[idx];
      }
#endif

      void *dest_ptr = (Logging_Statistics_T *)&stream_ptr->logging_statistics; /*Data to be provided by packing core - Good to get
                                                                           stats here - No CDC interrupts post RDD task*/

      ((Logging_Statistics_T *)(dest_ptr))->CDC_MAX_LOG_BINS                       = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Range_Bins_Limited_Count           = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_ENET_Partial_Buffer_Mismatch_Count = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_ENET_Buffer_UNAVBL_Count           = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Frames_Max                = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Frames                    = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Bins                      = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Total_Bins_Max                = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Total_Bins                    = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Dbins_Per_Rbin_Max        = 0;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Num_Dbins_Per_Rbin_Max             = 0;
      ((Logging_Statistics_T *)(dest_ptr))->ENET_TxBuffers_Pending_Count           = 0;
      ((Logging_Statistics_T *)(dest_ptr))->ENET_TxBuffers_Pending_Count_MAX       = 0;
      ((Logging_Statistics_T *)(dest_ptr))->ENET_ARP_Tx_Buf_UNAVBL_Count           = 0;
      ((Logging_Statistics_T *)(dest_ptr))->ENET_CDC_Tx_Buf_UNAVBL_Count           = 0;
      ((Logging_Statistics_T *)(dest_ptr))->ENET_Logging_Tx_Buf_UNAVBL_Count       = 0;
#if (defined(CDC_ENABLE))
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Current_Index_Error_Cnt = C0_CDC_Current_Index_Error_Cnt;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Fail_Cnt       = C0_CDC_Transmit_Fail_Cnt;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Success_Cnt    = C0_CDC_Transmit_Success_Cnt;
#else
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Current_Index_Error_Cnt = 0U;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Fail_Cnt = 0U;
      ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Success_Cnt = 0U;
#endif
      ((Logging_Statistics_T *)(dest_ptr))->Frame_Transmit_Success_Cnt = Frame_Tx_Success_Cnt;
      ((Logging_Statistics_T *)(dest_ptr))->Frame_Transmit_Failure_Cnt = Frame_Tx_Failure_Cnt;

#ifndef DISBLE_STACK_MONITOR
   #if COMMENTED_SH /*--Commented until Stack_usage_data update through IPC struct*/
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Bytes =
         p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.stack_utilization_bytes;
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Percentage =
         p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.stack_utilization_percentage;
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_State =
         p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.current_state;
   #endif
#else
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Bytes = 0;
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Percentage = 0;
      ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_State = 0;

#endif
      //   D2M_Diag_Data_T *p_ipc_d2m_diag_data                 = &(p_ipc_d2m_msg->payload.diag_data);
      //   D2M_Diag_Data_Log_T *D2M_local_ptr                   = (D2M_Diag_Data_Log_T *)&stream_ptr->D2M_Diag_Data;
      // D2M_local_ptr->dfft_rdd_xput_overrun_cnt = p_ipc_d2m_diag_data->dfft_rdd_xput_overrun_cnt;
      // D2M_local_ptr->rfft_xput_overrun_cnt     = p_ipc_d2m_diag_data->rfft_xput_overrun_cnt;
      // D2M_local_ptr->ipc_m2d_buffer_err_cnt    = p_ipc_d2m_diag_data->ipc_m2d_buffer_err_cnt;
      // D2M_local_ptr->dfft_rdd_error_cnt        = p_ipc_d2m_diag_data->dfft_rdd_error_cnt;
      //   D2M_local_ptr->bbe_self_test_failure_flag            = p_ipc_d2m_diag_data->bbe_self_test_failure_flag;
      //   D2M_local_ptr->fusa_spt_self_test_fault_flag         = p_ipc_d2m_diag_data->fusa_spt_self_test_fault_flag;
      //   D2M_local_ptr->fusa_spt_reg_readback_test_fault_flag = p_ipc_d2m_diag_data->fusa_spt_reg_readback_test_fault_flag;
      //   D2M_local_ptr->mem_pool_error_cnt                    = p_ipc_d2m_diag_data->mem_pool_error_cnt;
      //   D2M_local_ptr->spt_write_axi_error_counter           = p_ipc_d2m_diag_data->spt_write_axi_error_counter;
      //   D2M_local_ptr->spt_write_lu_error_counter            = p_ipc_d2m_diag_data->spt_write_lu_error_counter;
      // D2M_local_ptr->rsvd4 = p_ipc_d2m_diag_data->rsvd4;
      // for (uint16_t idx = 0; idx < 12; idx++)
      // {
      //    D2M_local_ptr->spt_static_register_readback_mismatch_bitmap[idx] =
      //       p_ipc_d2m_diag_data->spt_static_register_readback_mismatch_bitmap[idx];
      // }

      //   D2M_Diag_Data_T *p_ipc_d2m_diag_data  = &(p_ipc_d2m_msg->payload.diag_data);
      //   D2M_Diag_Data_Log_T *D2M_local_ptr    = (D2M_Diag_Data_Log_T *)&stream_ptr->D2M_Diag_Data;
      //   D2M_local_ptr->psp_xput_overrun_cnt   = p_ipc_d2m_diag_data->psp_xput_overrun_cnt;
      //   D2M_local_ptr->psp_mem_pool_error_cnt = p_ipc_d2m_diag_data->psp_mem_pool_error_cnt;
      // D2M_local_ptr->rsvd3 = p_ipc_d2m_diag_data->rsvd3;
      // D2M_local_ptr->rsvd4 = p_ipc_d2m_diag_data->rsvd4;
      // D2M_local_ptr->rsvd5 = p_ipc_d2m_diag_data->rsvd5;

      stream_ptr->debug_scanindex       = ipc_look_data_ptr->scan_index;
      stream_ptr->stream_hdr.scan_index = ipc_look_data_ptr->scan_index;

      /* Calculate checksum */
      Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Debug_Stream_T));

      debug_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(DEBUG, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Populate_Header_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Header_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint8_t header_trigger_state;
   Header_Stream_T *stream_ptr = Get_Header_Log_Data_Ptr();
#if 0
   Dt_Fault_T Active_fault_table;
   Dt_Fault_T History_fault_table;
   Dt_FailSafe_ResetReason_T FailSafe_ResetReason;
   uint8_t Command_Radiate_Final;
   float32_t m_EcuSync_Offset_ms;
   uint8_t operation_mode;
#endif
   // GLOB_TS_STRUCT_TYPE timestamp_start;
   // GLOB_TS_STRUCT_TYPE timestamp_end;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();

   /*
   Radar_TimeSync_Info_Status_T* p_temp_ts_status = Get_Radar_TimeSync_Info_Status_Ptr();
   TS_Current_Time_T* p_data_acq_time = Get_TS_Current_Time(TS_READ_START_DATA_ACQ);
   TS_Current_Time_T* p_data_dwell_time = Get_TS_Current_Time(TS_READ_DWELL_TIME);
   VCAN_Rx_Signals_T* vcan_rx_signals =  Get_VCAN_Rx_Signals();
   */
   if ((NULL != p_ipc_d2m_msg))
   {
      Rdd_Stream_T *ipc_rdd_log_ptr    = &p_ipc_d2m_msg->payload.rdd_stream_data;
      RDD_Data_T *p_ipc_d2m_rdd_data   = &(ipc_rdd_log_ptr->rdd_data);
      DSP_Timing_Data_T *p_timing_data = &p_ipc_d2m_msg->payload.dsp_timing_data;
#if 0
   Radar_TimeSync_Info_Status_T* p_temp_ts_status = Get_Radar_TimeSync_Info_Status_Ptr();
   TS_Current_Time_T* p_data_acq_time = Get_TS_Current_Time(TS_READ_START_DATA_ACQ);
   TS_Current_Time_T* p_data_dwell_time = Get_TS_Current_Time(TS_READ_DWELL_TIME);
   VCAN_Rx_Signals_T* vcan_rx_signals =  Get_VCAN_Rx_Signals();
#endif

      stream_ptr->xput_info.data_cache_info.cache_hit_count            = p_timing_data->data_cache_info.cache_hit_count;
      stream_ptr->xput_info.data_cache_info.cache_miss_count           = p_timing_data->data_cache_info.cache_miss_count;
      stream_ptr->xput_info.data_cache_info.cache_hit_count_max        = p_timing_data->data_cache_info.cache_hit_count_max;
      stream_ptr->xput_info.data_cache_info.cache_miss_count_max       = p_timing_data->data_cache_info.cache_miss_count_max;
      stream_ptr->xput_info.instruction_cache_info.cache_hit_count     = p_timing_data->instruction_cache_info.cache_hit_count;
      stream_ptr->xput_info.instruction_cache_info.cache_miss_count    = p_timing_data->instruction_cache_info.cache_miss_count;
      stream_ptr->xput_info.instruction_cache_info.cache_hit_count_max = p_timing_data->instruction_cache_info.cache_hit_count_max;
      stream_ptr->xput_info.instruction_cache_info.cache_miss_count_max =
         p_timing_data->instruction_cache_info.cache_miss_count_max;

      stream_ptr->xput_info.idle_xput_inst = (float32_t)p_timing_data->state_profiling[IDLE].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.idle_xput_peak = (float32_t)p_timing_data->state_profiling[IDLE].maxRuntime * (float)US_2_MS;

      /*Some of the below member of RDD Structure should be defined*/
      stream_ptr->xput_info.RDD_xput_inst =
         (float32_t)p_timing_data->state_profiling[DOPPLER_AND_RDD_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.RDD_xput_peak =
         (float32_t)p_timing_data->state_profiling[DOPPLER_AND_RDD_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.bbe_stl_xput_inst =
         (float32_t)p_timing_data->state_profiling[FUSA_BBE_SELF_TEST_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.bbe_stl_xput_peak =
         (float32_t)p_timing_data->state_profiling[FUSA_BBE_SELF_TEST_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.RFFT_xput_inst =
         (float32_t)p_timing_data->state_profiling[RANGE_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.RFFT_xput_peak =
         (float32_t)p_timing_data->state_profiling[RANGE_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.chirping_time_inst =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.range_process_time.lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.chirping_time_peak =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.range_process_time.maxRuntime * (float)US_2_MS;

      // copy anglefinding timing structure to the stream
      // these timestamps are in seconds instead of ms and represent the time taken as computed
      // internally within the angle-finding process, itself
      // memcpy(&stream_ptr->xput_info.af_time, &p_timing_data->af_time, sizeof(stream_ptr->xput_info.af_time));
      // these timestamps come from the state-machine wrapper
      // so they include some additional overhead from initializing the AF inputs
      stream_ptr->xput_info.af_xput_inst =
         (float32_t)p_timing_data->state_profiling[ANGLE_FINDING_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.af_xput_peak =
         (float32_t)p_timing_data->state_profiling[ANGLE_FINDING_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.rc_xput_inst =
         (float32_t)p_timing_data->state_profiling[RADAR_CAPABILITY_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.rc_xput_peak =
         (float32_t)p_timing_data->state_profiling[RADAR_CAPABILITY_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.id_xput_inst =
         (float32_t)p_timing_data->state_profiling[INTERFERENCE_DETECTION_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.id_xput_peak =
         (float32_t)p_timing_data->state_profiling[INTERFERENCE_DETECTION_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.alignment_xput_inst =
         (float32_t)p_timing_data->state_profiling[TOI_ALIGNMENT_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.alignment_xput_peak =
         (float32_t)p_timing_data->state_profiling[TOI_ALIGNMENT_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.tracker_xput_inst =
         (float32_t)p_timing_data->state_profiling[TRACKER_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.tracker_xput_peak =
         (float32_t)p_timing_data->state_profiling[TRACKER_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.feature_xput_inst =
         (float32_t)p_timing_data->state_profiling[FEATURE_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.feature_xput_peak =
         (float32_t)p_timing_data->state_profiling[FEATURE_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.sig_proc_done_inst =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.sig_proc_done_peak =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.sig_proc_done_error_inst =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING_ERROR].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.sig_proc_done_error_peak =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING_ERROR].maxRuntime * (float)US_2_MS;

      /*RDD detection information*/
      stream_ptr->detection_num_1st_pass = p_ipc_d2m_rdd_data->rdd1_num_detect;
      stream_ptr->detection_num_2nd_pass = p_ipc_d2m_rdd_data->rdd2_num_detect;
      stream_ptr->look_type              = ipc_rdd_log_ptr->look_data.look_id;
      stream_ptr->scanindex              = ipc_rdd_log_ptr->look_data.scan_index;
      stream_ptr->stream_hdr.scan_index  = ipc_rdd_log_ptr->look_data.scan_index;
      stream_ptr->lookindex              = ipc_rdd_log_ptr->look_data.scan_index;

      switch (ipc_rdd_log_ptr->look_data.look_id)
      {
         case (uint16_t)RADAR_LOOK_A:
            /*
            stream_ptr->det_range_max = k_detection_range_max_Look_A_SMC;
            stream_ptr->det_range_min = k_detection_range_min_Look_A_SMC;
            stream_ptr->speed_range_max = k_detection_range_rate_max_Look_A_SMC;
            stream_ptr->speed_range_min = k_detection_range_rate_min_Look_A_SMC;
            */
            break;

         case (uint16_t)RADAR_LOOK_B:
            /*
            stream_ptr->det_range_max = k_detection_range_max_Look_B_SMC;
            stream_ptr->det_range_min = k_detection_range_min_Look_B_SMC;
            stream_ptr->speed_range_max = k_detection_range_rate_max_Look_B_SMC;
            stream_ptr->speed_range_min = k_detection_range_rate_min_Look_B_SMC;
            */
            break;

         case (uint16_t)RADAR_LOOK_C:
            /*
            stream_ptr->det_range_max = k_detection_range_max_Look_C_SMC;
            stream_ptr->det_range_min = k_detection_range_min_Look_C_SMC;
            stream_ptr->speed_range_max = k_detection_range_rate_max_Look_C_SMC;
            stream_ptr->speed_range_min = k_detection_range_rate_min_Look_C_SMC;
            */
            break;

         case (uint16_t)RADAR_LOOK_D:
            /*
            stream_ptr->det_range_max = k_detection_range_max_Look_D_SMC;
            stream_ptr->det_range_min = k_detection_range_min_Look_D_SMC;
            stream_ptr->speed_range_max = k_detection_range_rate_max_Look_D_SMC;
            stream_ptr->speed_range_min = k_detection_range_rate_min_Look_D_SMC;
            */
            break;

         default:
            /* Do Nothing */
            break;
      }
   }

   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr->sensor_timestamp_sec      = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.start_dwell_sec;
      stream_ptr->sensor_timestamp_ns       = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.start_dwell_nanosec;
      stream_ptr->sensor_dwell_time_sec     = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_sec;
      stream_ptr->sensor_dwell_time_ns      = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_nanosec;
      stream_ptr->sensor_mid_dwell_time_ns  = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.mid_dwell_nanosec;
      stream_ptr->sensor_mid_dwell_time_sec = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.mid_dwell_sec;

      stream_ptr->time_sync_validity_flag = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_status;

      if (TS_GLOBAL_TIME_BASE == p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_status)
      {
         stream_ptr->time_sync_no_tsyn_error = 1;
      }
      else
      {
         stream_ptr->time_sync_no_tsyn_error = 0;
      }
   }

   /* Calculate checksum */
   Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Header_Stream_T));

   header_trigger_state = sh_output_data_ptr->sh_trigger_stream_handler_fptr(HEADER, (uint8_t *)stream_ptr);
}

/******************************************************************************
 *. Name: Config_Calib_Stream
 *.    Provide params to configure a calibration stream (Static stream)
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Config_Calib_Stream(void)
{
   uint8_t config_result;
   Stream_Init_Cfg_T calib_init_cfg = {(uint8_t)CHUNK_1, STREAM_STATIC, (uint8_t) true, 0U};
   config_result                    = Calib_Stream_Config_Init(&calib_init_cfg);
   /*Use of config_result depends on application requirement*/
}

#if (defined(CDC_ENABLE))
/******************************************************************************
 *. Name: Config_CDC_Stream
 *.    Provide init params to configure CDC stream (Dynamic stream)
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Config_CDC_Stream(void)
{
   uint8_t config_result;
   Stream_Init_Cfg_T cdc_init_cfg = {(uint8_t)ALL_CHUNKS, STREAM_DYNAMIC, (uint8_t) true, 0U};
   config_result                  = Stream_Config_Init(CDC, &cdc_init_cfg);
   /*Use of config_result depends on application requirement*/
}
#endif

#ifdef TRACKER_ENABLED
/******************************************************************************
 *. Name: Populate_Partner_Sensor_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Partner_Sensor_Stream(void)
{
   M2D_Msg_T *p_ipc_m2d_msg        = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
   D2M_Msg_T *p_ipc_d2m_msg        = Get_IPC_D2M_Buffer();
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();

   if ((NULL != p_ipc_m2d_msg) && (NULL != p_ipc_d2m_msg))
   {
      Partner_Sensor_Stream_T *stream_ptr = &p_ipc_m2d_msg->payload.partners_data;

      stream_ptr->stream_hdr.scan_index = p_ipc_d2m_msg->payload.det_data.det_list_property.scanindex;

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(PARTNER_SENSOR, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Set_Tracker_Stream_Ref_Index
 *.    Function to set scan index to use for tracker streams
 *.
 *. Parameters: uint32_t
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Set_Tracker_Stream_Ref_Index(uint32_t val)
{
   Tracker_Ref_Index = val;
}

/******************************************************************************
 *. Name: Get_Tracker_Stream_Ref_Index
 *.    Function to get scan index to use for tracker streams
 *.
 *. Parameters: void
 *. Return Value: uint32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.

 *. JIRA Issues:
 ******************************************************************************/
uint32_t Get_Tracker_Ref_Index(void)
{
   return Tracker_Ref_Index;
}

/******************************************************************************
 *. Name: Is_Tracker_Stream_Applicable
 *.    Check if the tracker stream is enabled for the current radar.
 *.
 *. Parameters: None
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static bool Is_Tracker_Stream_Applicable(void)
{
   #if defined(AL_TRACKER)
   return ((Get_Radar_Position() == FRONT_CENTER) || (Get_Radar_Position() == REAR_LEFT));
   #else
   return true;
   #endif
}
#endif

#ifdef FEATURE_ENABLE
/******************************************************************************
 *. Name: Populate_Bsis_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Bsis_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Bsis_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Bsis_Stream_T *)&(p_ipc_d2m_msg->payload.Bsis_IPC_Output);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Bsis_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(BSIS, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Populate_Mois_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Mois_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Mois_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Mois_Stream_T *)&(p_ipc_d2m_msg->payload.Mois_IPC_Output);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Mois_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(MOIS, (uint8_t *)stream_ptr);
   }
}
/******************************************************************************
 *. Name: Populate_Olp_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Olp_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Olp_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Olp_Stream_T *)&(p_ipc_d2m_msg->payload.Olp_Object_Data);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Olp_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(OLP, (uint8_t *)stream_ptr);
   }
}
#endif

/******************************************************************************
 *. Name: Get_Status_Calibration_Disable_CDC_Logging
 *.    Function to get CDC logging disable status.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_Status_Calibration_Disable_CDC_Logging(void)
{
   return K_Disable_CDC_Logging;
}

/******************************************************************************
 *. Name: Udp_Rx_Callback
 *.    Udp Rx callback when the data is received on ethernet
 *.
 *. Parameters: udp_rx_ptr - received data pointer
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Udp_Rx_Callback(const uint8_t *udp_rx_ptr)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   sh_output_data_ptr->sh_udp_rx_callback_update_fptr((uint8_t *)udp_rx_ptr);
}

/******************************************************************************
 *. Name: Get_XCP_Over_ETH_Status
 *.    Function to get XCP over Ethernet.
 *.
 *. Parameters: void
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_XCP_Over_ETH_Status(void)
{
   return XCP_Connection_Status;
}

/******************************************************************************
 *. Name: Set_XCP_Over_ETH_Status
 *.    Function to set XCP over Ethernet.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Set_XCP_Over_ETH_Status(bool val)
{
   XCP_Connection_Status = val;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
